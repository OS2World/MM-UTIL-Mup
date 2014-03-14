static char Copyright[] =
	"Copyright (c) 1995-2011 by Arkkra Enterprises.\nAll rights reserved.\n";

/* main for "Mup" music publication program */

/*
 *		Command line arguments 
 * -cN	Combine strings of N measures of rest into multirests (N > 1)
 * -C		Include comments in macro-processed output (with -E)
 * -dn   turns on debug level n
 *		1 = yydebug
 *		2 = parse phase high level trace
 *		4 = parse phase low level trace
 *		8 = reserved
 *		16 = placement phase high level trace
 *		32 = placement phase low level trace
 *		64 = reserved
 *		128 = print contents of main linked list
 *		256 = print phase high level trace
 *		512 = print phase low level trace
 *	This is a bitmap, so multiple levels can be on at once
 * -DMACRO[=def] define a macro
 * -e errfile	write error output into errfile instead of stderr
 * -E		just do macro expansion
 * -f file	write output to file instead of stdout
 * -F		write output to file, deriving the name
 * -m midifile  generate MIDI output into specified file instead of the
 *		usual PostScript output to stdout.
 * -M		create MIDI file, deriving the file name
 * -olist	print only pages given in list
 * -pN		start numbering pages at N instead of from 1
 * -r    	print registration form
 * -slist	print only the staffs in list
 * -v    	print verion number and exit
 * -xN,M	extract just measures N through M.
 *	Negative values are relative to the end of the song.
 *	The comma and second number are optional.
 *
 * Expects zero or more input files. If no file specified, reads stdin
 *
 * Exit code is 0 on success, or the number of errors found, up to 254,
 * or 255 for internal error.
 */


#ifdef __WATCOMC__
#include <io.h>
#endif
#ifdef Mac_BBEdit
#include <Files.h>
#include <Folders.h>
#include <MupInterface.h>
#define main _mup	/* rename entry point to _mup */
#endif
#include <errno.h>
#include <fcntl.h>
#include "defines.h"
#include "globals.h"


/* List of valid command line options and their explanations */
struct Options {
	char	option_letter;
	char	*argument;	/* describes the arg if any, or "" if none */
	char	*explanation;
} Option_list[] = {
	{ 'c', " N",		"combine N or more measures of rests into multirests" },
	{ 'C',	"",		"include comments in macro preprocessor output" },
	{ 'd', " N",		"turn on debug level N" },
	{ 'D', " MACRO[=macro_def]", "define macro" },
	{ 'e', " errfile",	"write error messages to errfile" },
	{ 'E', "",		"run macro preprocessor only" },
	{ 'f', " outfile",	"write output to outfile" },
	{ 'F', "",		"write output to file with derived name" },
	{ 'm', " midifile",	"generate MIDI output file" },
	{ 'M', "",		"generate MIDI output file, derive file name" },
	{ 'o', " pagelist",	"only print pages in pagelist" },
	{ 'p', " N",		"start numbering pages at N" },
	{ 'r', "",		"print shareware REGISTRATION form" },
	{ 's', " stafflist",	"print only staffs in stafflist" },
	{ 'v', "",		"print version number" },
	{ 'x', " N[,M]",	"extract measures N through M" }
};


#ifndef _UNISTD_H
/* to process command line args */
extern int getopt P((int argc, char * const *argv, const char *optstr));
extern int optind;	/* set by getopt to point to current cmd line argument */
extern char *optarg;	/* set by getopt */
extern char *getenv();
#endif
extern FILE *yyout;	/* lex could try to write error output here */

static char **Arglist;		/* global pointer to argv */
static int Num_args;		/* global copy of argc */
static char Version[] = "5.8";	/* Mup version number */
static int Got_e_option = NO;	/* was there a -e option on the command line? */

/* The different kinds of things that can be argument to -o option.
 * If no -o option, then it will be PG_ALL, "odd" and "even" will
 * map to PG_ODD and PG_EVEN, and a list of page numbers or ranges to PG_LIST.
 */
static int Pglist_type;
#define PG_LIST		0
#define PG_ODD		1
#define PG_EVEN		2
#define PG_ALL		3

#ifdef O_BINARY
static char * Read_mode = "rb";
#else
static char * Read_mode = "r";
#endif

/* If there is a list of pages to print using -o, the values are stored
 * in a list of RANGELIST structs. This points to that list. The "all" field
 * of the struct is unused.
 */
static struct RANGELIST *Page_range;

static void usage P((char **argv));	/* print usage message and exit */
static int ignore_option P((int opt));
static void notice P((void));
static void first_msg P((char *pname));
static void setvflag P((char *fname));
static void registration P((void));
static char *derive_file_name P((char *suffix));
static int get_first_page P((int pagenum));
static void set_pagelist P((char *pagelist, int startpage));
static void prune_page_range P((int start_page));
static void vis_staffs P((char *stafflist));




int
main(argc, argv)

int argc;
char **argv;

{
	int a;			/* for command line args */
	char *midifilename = (char *) 0;
	int combine = NORESTCOMBINE;	/* number of measures to combine into
				 * multirests with -c option */
	int derive_out_name = NO;	/* YES is -F option is specified */
	char *vis_stafflist = (char *) 0;	/* -s list of visible staffs */
	int pagenum;
	char *pagelist = 0;
	int start = 1, end = -1;	/* Arguments to -x option */
	int has_x_arg = NO;
	int outfile_args = 0;	/* we only allow one instance of [fFmM] options */
	int n, i;
	int num_options;
	char *getopt_string;



	notice();
	first_msg(argv[0]);

	/* Initialize all the font metrics.
	 * This must happen before init_symtbl() */
	init_psfont_metrics();
	init_musfont_metrics();
	init_charinfo_table();

	/* must init head shapes table before first call to initstructs */
	init_symtbl();

	/* set initial page number to "not set" */
	pagenum = MINFIRSTPAGE - 1;
	initstructs();

	/* If run via mupmate, user may not understand error messages	
	 * about things like -c or -p, so we give different messages. */
	Mupmate = (getenv("MUPMATE") == 0 ? NO : YES);

	/* process command line arguments */
	/* create getopt string */
	num_options = NUMELEM(Option_list);
	/* allow for worst case of all requiring colon */
	MALLOCA(char, getopt_string, 2 * num_options + 1);
	for (n = i = 0; n < num_options; n++) {
		if (ignore_option( (int) Option_list[n].option_letter) == YES) {
			continue;
		}
		getopt_string[i] = Option_list[n].option_letter;
		if (Option_list[n].argument[0] != '\0') {
			getopt_string[++i] = ':';
		}
		i++;
	}
	getopt_string[i] = '\0';

	while ((a = getopt(argc, argv, getopt_string)) != EOF) {

		switch (a) {

		case 'c':
			combine = atoi(optarg);
			if (combine < MINRESTCOMBINE || combine > MAXRESTCOMBINE) {
				if (Mupmate == YES) {
					/* Should be impossible to get here,
					 * since mupmate refuses to accept
					 * out of range values. */
					l_yyerror(0, -1, "Run > Set Options > Min measures to combine: value must be between %d and %d.",
						MINRESTCOMBINE, MAXRESTCOMBINE);
				}
				else {
					l_yyerror(0, -1, "argument for %cc (number of measures to combine) must be between %d and %d",
						Optch, MINRESTCOMBINE, MAXRESTCOMBINE);
				}
			}
			break;

		case 'C':
			Ppcomments = YES;
			break;

		case 'd':
			Debuglevel = (int) strtol(optarg, (char **) 0, 0);
			break;

		case 'e':
			if (freopen(optarg, "w", stderr) == (FILE *) 0) {
				cant_open(optarg);
			}
			Got_e_option = YES;
			break;

		case 'E':
			Preproc = YES;
			break;

		case 'f':
			Outfilename = optarg;
			outfile_args++;
			break;

		case 'F':
			derive_out_name = YES;
			outfile_args++;
			break;

		case 'D':
			cmdline_macro(optarg);
			break;

		case 'm':
			midifilename = optarg;
			/* FALLTHRU */
		case 'M':
			Doing_MIDI = YES;
			/* define "built-in" MIDI macro */
			cmdline_macro("MIDI");
			outfile_args++;
			break;

		case 'o':
			pagelist = optarg;
			break;

		case 'p':
			pagenum = atoi(optarg);
			if (pagenum < MINFIRSTPAGE || pagenum > MAXFIRSTPAGE) {
				if (Mupmate == YES) {
					/* Should be impossible to get here,
					 * since mupmate refuses to accept
					 * out of range values. */
					l_yyerror(0, -1, "Run > Set Options > First Page: value must be between %d and %d.",
						MINFIRSTPAGE, MAXFIRSTPAGE);
				}
				else {
					l_yyerror(0, -1, "argument for %cp (first page) must be between %d and %d",
						Optch, MINFIRSTPAGE, MAXFIRSTPAGE);
				}
			}
			break;

		case 'r':
			registration();
			exit(0);
			/*NOTREACHED*/
			break;

		case 's':
			vis_stafflist = optarg;
			break;

		case 'v':
			/* if got "-e errfile -v" then we want to put the
			 * opening notice into the errfile. This can allow
			 * another program to execute "mup -e errfile -v"
			 * and then use the contents of errfile as the
			 * text for an "About Mup" informational block.
			 */
			if (Got_e_option == YES) {
				notice();
			}

			(void) fprintf(stderr,"Version %s\n", Version);
			exit(0);
			/*NOTREACHED*/
			break;

		case 'x':
			chk_x_arg(optarg, &start, &end);
			has_x_arg = YES;
			break;

		default:
			usage(argv);
			break;
		}
	}

	if (Ppcomments == YES && Preproc == NO) {
		warning("-C only valid with -E; ignored");
	}

	if (Preproc == YES && vis_stafflist != 0) {
		warning("-s not valid with -E; ignored");
	}

	if (outfile_args > 1) {
		(void) fprintf(stderr, "Only one output file option (-f, -F, -m, -M) can be specified\n");
		exit(1);
	}

	/* turn on yacc debug flag if appropriate */
	if (Debuglevel & 1) {
		yydebug = 1;
		ifdebug = 1;
	}

	/* save info about arguments so yywrap can open additional input files
	 * if necessary */
	Arglist = argv;
	Num_args = argc;
	yyin = stdin;
	yyout = stderr;

	/* if file argument, open that, else use stdin */
	if (optind <= argc - 1) {
		(void) yywrap();
	}
	else {
#ifdef Mac_BBEdit
		Curr_filename  = _mup_input_filename;
#else
		Curr_filename = "stdin";
#if defined(unix) || defined(__WATCOM__)
		/* Sometimes people forget to give a file name,
		 * then wonder why Mup is "hanging," so let user
		 * know it isn't hanging... it's waiting for them
		 * to type something. But only if input is a terminal,
		 * and stderr is a terminal--if stdin is a pipe,
		 * user probably doesn't need a reminder. */
		if (isatty(0) && isatty(2)) {
			fprintf(stderr, "No input file specified; reading standard input.\n\n");
		}
#endif
#endif
	}

	/* initialize for parser */
	raterrfuncp = doraterr;
	initstructs();
	vis_staffs(vis_stafflist);
	reset_ped_state();

	/* parse the input */
	if (Preproc == YES) {
		preproc();
	}
	else {
		(void) yyparse();
	}
#ifndef UNIX_LIKE_FILES
	mac_cleanup();
#endif


	/* do final checks and cleanup of input data */
	/* check for missing endif */
	chk_ifdefs();	
	if (Preproc == YES) {
		error_exit();
	}

	/* find height of headers and footers */
	/* Note: this has to be called when we are at the *end* of the main
	 * list with all SSVs applied, so that we know the margin settings */
	calc_block_heights();
	/* make sure there is a final barline */
	check4barline_at_end();
	/* make sure we go to new score if visibility changes */
	chk_vis_feed();

	/* derive tabnote staff data for tablature staffs. But if there
	 * have been errors found, don't bother, because we may have
	 * some incomplete/inconsistent data that tab2tabnote doesn't
	 * know how to deal with cleanly. */
	if (Errorcount == 0) {
		tab2tabnote();
	}

	/* Convert ph-eph pairs into pharse STUFFs */
	conv_ph_eph();

	/* do -c option or restcombine parameter */
	combine_rests(combine);

	/* make sure there aren't til clauses past end of song */
	chk4dangling_til_clauses("the end of the song");

	/* count how many verses */
	set_maxverses();

	/* process ties */
	tie();

	/* Verify that -o argument (and maybe -p or firstpage parameter)
	 * is valid. If not, this will ufatal. */
	pagenum = get_first_page(pagenum);
	set_pagelist(pagelist, pagenum);

	/* Do -x (extract) option if needed. But if there were errors before,
	 * skip this, because there could be empty measures and such,
	 * that could confuse it, and we're going to give up soon anyway. */
	if (has_x_arg == YES && Errorcount == 0) {
		extract(start, end);
	}

	debug(2, "finished with parsing, Errorcount is %d", Errorcount);

	if (Errorcount > 0) {
		(void) fprintf(stderr, "\nstopping due to previous error%s\n",
						Errorcount ? "s" : "");
		error_exit();
	}

	/* do the placement phase */

	/* initialize the Staffscale and related variables to default values */
	initstructs();
	set_staffscale(0);
	Ignore_staffscale = YES;

	/* transpose */
	transgroups();

	/* set up ties that carry into next measure */
	tie_carry();

	/* line up chords */
	makechords();

	/* place notes relative to staff and set stem direction */
	setnotes();	
	/* find relative horizontal position of notes */
	setgrps();
	/* set coordinates of rests and syllables */
	restsyl();

	/* generate MIDI file if appropriate. We wait until here to
	 * do MIDI, so that chord widths have been established, so midi
	 * code can more easily figure out how to crunch all-space chords */
	if (Doing_MIDI == YES) {
		if (midifilename == (char *) 0) {
			/* -M option, so we have to derive the name */
			midifilename = derive_file_name(".mid");
		}
		gen_midi(midifilename);
		exit(0);
	}

	/* figure out absolute horizontal locations */
	abshorz();
	/* find lengths of beams, angles of beams, etc */
	beamstem();
	/* set up mussym, octave, rom, bold, pedal, etc */
	stuff();

	/* find vertical coordinates relative to staff */
	relvert();
	/* set absolute vertical coordinates */
	absvert();

	/* split lines and curves */
	fix_locvars();	

	print_mainll();

	if (derive_out_name == YES) {
		Outfilename = derive_file_name(".ps");
	}
	if (*Outfilename != '\0') {
		if (freopen(Outfilename, "w", stdout) == (FILE *) 0) {
			cant_open(Outfilename);
			exit(1);
		}
	}

	/* output PostScript for printing */
	prune_page_range(pagenum);
	do {
		Pagenum = (short) pagenum;
		print_music();
	} while (Page_range != (struct RANGELIST *) 0);
	trailer();

	/* if we get to here, all is okay. If there was a problem,
	 * we would have exited where the problem occurred */
	return(0);
}


/* print copyright notice */

static void
notice()

{
	if (getenv("MUPQUIET") == (char *) 0 || Got_e_option == YES) {
		fprintf(stderr, "Mup - Music Publisher   Version %s\n", Version);
		fprintf(stderr, Copyright);
	}
}


/* print registration form */

static void
registration()
{
	printf("Mup is SHAREWARE.  You can try out a copy for free, but if you decide\n");
	printf("to keep and use it, you must register by filling out the form below\n");
	printf("and sending the form and cash, check, or money order to:\n");
	printf("                Arkkra Enterprises\n");
	printf("                P. O. Box 315\n");
	printf("                Warrenville, IL  60555    USA\n");
	printf("\nName______________________________________________________________\n\n");
	printf("Address___________________________________________________________\n\n");
	printf("City_____________________________ State/Province__________________\n\n");
	printf("Zip code/Postal code_____________________ Country_________________\n\n");
	printf("Email address (please print clearly)______________________________\n\n");
	printf("How did you find out about Mup?___________________________________\n\n");
	printf("__________________________________________________________________\n\n");
	printf("___Linux  ___ Windows/MS-DOS  ___Mac  ___Other____________________\n\n");
	printf("Would you like to join the Mup users mailing list? ___ Yes  ___ No\n\n");
	printf("___ Mup Version %s Registrations.........................$29 each\n", Version);
	printf("\t\t\t(Illinois residents, add $2.32 sales tax)\n");
	printf("(For credit card payment, see http://www.arkkra.com/doc/credtcrd.html)\n");
}


/* print usage message and exit */

static void
usage(argv)

char **argv;

{
	int num_options;	/* how many options */
	int n;
	char *whitespace;	/* for lining things up */
	int white_length;	/* strlen(whitespace) */
	int length;		/* of an argument item */
	char *extra_options;	/* parent process can ask us to print more */


	/* print the usage summary */
	fprintf(stderr, "usage: %s ", argv[0]);
	num_options = NUMELEM(Option_list);
	for (n = 0; n < num_options; n++) {
		if (ignore_option( (int) Option_list[n].option_letter) == YES) {
			/* ignore this option */
			continue;
		}
		fprintf(stderr, "[%c%c%s] ", Optch,
			Option_list[n].option_letter, Option_list[n].argument);
	}
	fprintf(stderr, "[file...]\n");

	/* We'll add as much of this whitespace string to each argument
	 * item as needed to line the explanations up nicely. */
	whitespace = "                  ";
	white_length = strlen(whitespace);

	/* print the explanations of each option */
	for (n = 0; n < num_options; n++) {

		if (ignore_option( (int) Option_list[n].option_letter) == YES) {
			continue;
		}

		fprintf(stderr, "   %c%c%s", Optch,
			Option_list[n].option_letter, Option_list[n].argument);

		/* add enough white space to line things up */
		if ((length = strlen(Option_list[n].argument)) < white_length) {
			fprintf(stderr, whitespace + length);
		}

		fprintf(stderr, " %s\n", Option_list[n].explanation);
	}
	/* If calling program tells us to add some options to the list,
	 * print those out too. */
	if ((extra_options = getenv("MUPADDOP")) != (char *) 0) {
		fprintf(stderr, "%s", extra_options);
	}

	exit(1);
}


/* If Mup is being called by some other program, like mupdisp,
 * such that some of Mup's options should be disallowed, it
 * should set $MUPDELOP to the list of options to be deleted
 * from the list of valid options. This function will say, for the
 * given option, whether it should be disallowed. */

static int
ignore_option(opt)

int opt;	/* an option letter */

{
	static char *del_options = 0;	/* which options to delete from list */

	/* the first time we are called, get the list, if any */
	if (del_options == (char *) 0) {
		if ((del_options = getenv("MUPDELOP")) == (char *) 0) {
			del_options = "";
		}
	}

	return ((strchr(del_options, opt) != (char *) 0) ? YES : NO);
}


/* print message to display first time program is executed if appropriate.
 * If a particular magic file exists, we know
 * (or at least assume) the user has already seen the
 * message about Mup being shareware. If not, we print the message and
 * exit.  For unix, the magic file is called .mup and must be either in the
 * current directory or in $HOME. For DOS, it is called mup.ok and must be
 * either in the current directory or in the directory where mup.exe was
 * executed, as indicated by argv[0]. */

#ifndef MAGIC_FILE_NAME
#define MAGIC_FILE_NAME (char *) 0
#endif

int check = 100, *Check_p = &check;

static void
first_msg(pname)

char *pname;		/* argv[0] */

{
	char *fname;		/* name of magic file */
	char *home;		/* $HOME (unix) or where mup is located (DOS) */
#ifdef __DOS__
	char *last_slash, * last_backslash;
#endif
	char *path = (char *) 0;/*  home/fname */
	int saw_file = NO;	/* YES if so magic file, but without a valid
				 * registration key */


	fname = MAGIC_FILE_NAME;
	
	if (fname == (char *) 0) {
		fprintf(stderr, "\tMup is shareware.  You may try it out for free, but if you\n");
		fprintf(stderr, "\tdecide to keep it, you must pay a registration fee of $29.\n");
		fprintf(stderr, "\tThis copy of Mup was compiled for an unrecognized Operating System\n");
		fprintf(stderr, "\tor compiler. If you have a UNIX-like operating system,\n");
		fprintf(stderr, "\tyou can try compiling with -Dunix, or if you have as MS-DOS-like\n");
		fprintf(stderr, "\tOperating system, you can try compiling with -D__DOS__\n");
		fprintf(stderr, "\tIf that still doesn't work, to suppress this message,\n");
		fprintf(stderr, "\tand start using Mup, modify defines.h to define MAGIC_FILE_NAME\n");
		fprintf(stderr, "\tto a name that is appropriate for your operating system.\n");
		fprintf(stderr, "\tBy doing so, you acknowledge that you have read\n");
		fprintf(stderr, "\tthe Mup license and agree to its terms,\n");
		fprintf(stderr, "\tand agree that if you decide to continue to use Mup\n");
		fprintf(stderr, "\tafter trying it out, you will pay the registration fee.\n");
		fprintf(stderr, "\tAfter changing MAGIC_FILE_NAME or any other related #defines\n");
		fprintf(stderr, "\tthat you might need, and recompiling, execute\n");
		fprintf(stderr, "\t\tmup -r\n\tto get a registration form. If you let us know about any changes\n");
		fprintf(stderr, "\tyou need to make to support your OS, we will consider\n");
		fprintf(stderr, "\tincorporating those changes in a future Mup release.\n");
		exit(1);
	}

	/* if magic file exists in current directory,
	 * indicating user has already seen the message, return */
#ifndef Mac_BBEdit
	if (access(fname, 0) == 0) {
		setvflag(fname);
		if (Vflag == YES) {
			return;
		}
		else {
			check = 100;
			saw_file = YES;
		}
	}
#endif

#ifdef MAGIC_FILE_HOME
	/* construct pathname to magic file if it is in $HOME */
	if ((home = getenv("HOME")) != (char *) 0) {
		MALLOCA(char, path, strlen(home)+ strlen(fname) + 2);
#ifdef VMS
		(void) sprintf(path, "%s%s", home, fname);
#else
		(void) sprintf(path, "%s/%s", home, fname);
#endif
	}
#else
#ifdef __DOS__
	/* construct pathname to magic file if it is in the directory where
	 * mup.exe came from */
	last_slash = strrchr(pname, '/');
	last_backslash = strrchr(pname, '\\');
	if (last_slash != 0 && last_backslash != 0) {
		/* mixture of foward and backward; use the last */
		home = MAX(last_slash, last_backslash);
	}
	else if (last_slash != 0) {
		home = last_slash;
	}
	else if (last_backslash != 0) {
		home = last_backslash;
	}
	else {
		home = 0;
	}
	if (home != 0) {
		int baselength;		/* strlen up through last \  */

		baselength = home - pname + 1;
		MALLOCA(char, path, baselength + strlen(fname) + 1);
		/* copy pname up to last backslash */
		strncpy(path, pname, baselength);
		/* add magic file name */
		strcpy(path + baselength, fname);
	}
#endif
#endif
#ifdef Mac_BBEdit
#pragma unused(pname)
	/* check for file in Preferences folder inside System folder */
	path = 0;
	home = 0;
	{
		short vRefNum;
		long dirID;
		FSSpec fsSpec;
		
		if (FindFolder(kOnSystemDisk, kPreferencesFolderType, false, &vRefNum, &dirID) == noErr)
			/* preferences folder exists */
			if (FSMakeFSSpec(vRefNum, dirID, (StringPtr) MupRegFileName, &fsSpec) == noErr) {	/* file exists */
				short old_vRefNum;
				long old_dirID;
				if (HGetVol((StringPtr) 0, &old_vRefNum, &old_dirID) != noErr) return;
				if (HSetVol((StringPtr) 0, vRefNum, dirID) != noErr) return;
				setvflag(fname);
				HSetVol((StringPtr) 0, old_vRefNum, old_dirID);
				return;
			}
	}
#else
	/* check for file in $HOME or where mup.exe came from */
	if (path != (char *) 0 && access(path, 0) == 0) {
		setvflag(path);
		return;
	}
#endif

	if (saw_file == YES) {
		/* User had agreed to license, so should not print the
		 * message below, but they haven't registered */
		return;
	}

	/* print shareware message and exit */
	fprintf(stderr, "\n\tMup is shareware.  You may try it out for free, but if you\n");
	fprintf(stderr, "\tdecide to keep it, you must pay a registration fee of $29.\n");
	fprintf(stderr, "\n\tTo use Mup, first create a file called %s\n", fname);
#ifdef Mac_BBEdit
	fprintf(stderr, "\tin the Preferences folder inside the system folder");
#else
	fprintf(stderr, "\tin the current directory");
#endif
	if (path == (char *) 0) {
		fprintf(stderr, ".\n");
	}
	else {
		fprintf(stderr, " or at %s\n", path);
	}
	fprintf(stderr, "\t(It can be zero length.  It just has to exist.)\n");
	fprintf(stderr, "\tBy creating this file, you acknowledge that you have read\n");
	fprintf(stderr, "\tthe Mup license and agree to its terms, and agree that\n");
	fprintf(stderr, "\tif you decide to continue to use Mup after trying it out,\n\tyou will pay the registration fee.\n");
#ifdef Mac_BBEdit
	fprintf(stderr, "\n\tAfter creating this file, select\n\t'Registration' from the Mup dialog box\n\tto get a registration form.\n\n");
#else
	fprintf(stderr, "\n\tAfter creating this file, execute\n\t\tmup %cr\n\tto get a registration form.\n\n", Optch);
#endif
	exit(1);
}


static void
setvflag(fname)
char *fname;
{
	int f;
	char buff[48];
	int sum = 0;
	int hash = 0x45;
	int n = 16;
	int i;

	if ((f = open(fname, O_RDONLY, 0)) > 0) {
		if (read(f, buff, n) == n) {
			for (i = 0; i < n; i++) {
				sum += buff[i];
				hash ^= (buff[i] ^ sum);
				check ^= (buff[i] << (1 + (i & 3)));
			}
			Vflag = (((sum == 02703) && (hash == 02146)) ? YES : NO);
		}
	}
	(void) close(f);
}


/* make our own yywrap rather than use the one in the lex library.
 * In case user specifies more than one file, open
 * each in turn, and return control to lex */

int
yywrap()

{
	int leng = 0;	/* Length of file name. Initialization done solely
			 * to avoid bogus "used before set" warning. */

	/* return from any macros or includes */
	if (popfile() == 1) {
		return(0);
	}

	/* if user specified more files, open the next one */
	for (  ; optind < Num_args; optind++) {
		if (yyin != NULL) {
			(void) fclose(yyin);
		}
		errno = 0;
		if ((yyin = fopen(Arglist[optind], Read_mode)) != NULL) {
			Curr_filename = Arglist[optind++];
			yylineno = 1;
			return(0);
		}
		/* If name doesn't already end with .mup or .MUP and the open
		 * failed because the file didn't exist, try the name with
		 * .mup appended. */
		else if (
#ifdef ENOENT
				errno == ENOENT &&
#endif
				( ((leng = strlen(Arglist[optind])) < 5) ||
				(strcmp(Arglist[optind] + leng - 4, ".mup") != 0 &&
				strcmp(Arglist[optind] + leng - 4, ".MUP") != 0
				)) ) {
			MALLOCA(char, Curr_filename, leng + 5);
			sprintf(Curr_filename, "%s.mup", Arglist[optind]);
			if ((yyin = fopen(Curr_filename, Read_mode)) != NULL) {
				yylineno = 1;
				optind++;
				return(0);
			}
			/* try upper case suffix before giving up */
			sprintf(Curr_filename, "%s.MUP", Arglist[optind]);
			if ((yyin = fopen(Curr_filename, Read_mode)) != NULL) {
				yylineno = 1;
				optind++;
				return(0);
			}
			FREE(Curr_filename);
		}
		cant_open(Arglist[optind]);
	}

	return(1);
}


/* If user used -M or -F option, we need to derive the output file name.
 * Use the last input file name, strip off the trailing .mup if it is there,
 * add the suffix, and return the derived name.
 */

static char *
derive_file_name(suffix)

char *suffix;		/* ".mid" or ".ps" */

{
	int length;		/* of Curr_filename */
	char *file_name;	/* the name we derive */
	char *suffix_location;	/* where the suffix will go */


	length = strlen(Curr_filename);
	MALLOCA(char, file_name, length + strlen(suffix) + 1);

	/* start with the original Mup input file name */
	strcpy(file_name, Curr_filename);

	/* see if we need to strip off a .mup */
	if (length > 3) {
		/* find where the .mup would start if it is there */
		suffix_location = file_name + length - 4;

		/* If user used upper case, so will we */
		if (strcmp(suffix_location, ".MUP") == 0) {
			if (strcmp(suffix, ".mid") == 0) {
				suffix = ".MID";
			}
			else if (strcmp(suffix, ".ps") == 0) {
				suffix = ".PS";
			}
			else {
				pfatal("derive_file_name() called with unknown suffix '%s'", suffix);
			}
		}
		else if (strcmp(suffix_location, ".mup") != 0) {
			/* no .mup to strip off; just add to the end */
			suffix_location = file_name + length;
		}
	}
	else {
		suffix_location = file_name + length;
	}

	/* append the suffix and return the derived name */
	strcpy(suffix_location, suffix);
	return(file_name);
}


/* Determine the first page number. If user used -p option, use that,
 * otherwise get from first_page parameter, else use 1. */

static int
get_first_page(pagenum)

int pagenum;		/* from -p option */

{
	struct MAINLL *m_p;

	/* if there wasn't a -p value, figure out what to use for first page */
	if (pagenum < MINFIRSTPAGE) {
		/* default to page 1 */
		pagenum = 1;

		/* look for last setting of firstpage parameter before
		 * any STAFFs */
		initstructs();
		for (m_p = Mainllhc_p; m_p != 0; m_p = m_p->next) {
			if (m_p->str == S_SSV) {
				if (m_p->u.ssv_p->used[FIRSTPAGE] == YES) {
					pagenum = m_p->u.ssv_p->firstpage;
				}
			}
			else if (m_p->str == S_STAFF) {
				break;
			}
		}
	}
	return(pagenum);
}


/* Parse the argument to -o, if there is a -o option specified, and
 * save the info away for later use. Gives error if argument is invalid.
 */

static void
set_pagelist(pagelist, startpage)

char *pagelist;
int startpage;	/* from -p option */

{
	if (pagelist == (char *) 0) {
		/* no -o option, print all pages */
		Pglist_type = PG_ALL;
	}

	else if (strcmp(pagelist, "odd") == 0) {
		Pglist_type = PG_ODD;
	}

	else if (strcmp(pagelist, "even") == 0) {
		Pglist_type = PG_EVEN;
	}

	else {
		struct RANGELIST *new_range;
		struct RANGELIST **linkpoint_p_p;/* tail of Page_range list,
						 * for linking to the end
						 * of the list */
		char *p, *beyondnum;		/* for parsing the numbers */
		short lower, upper;		/* page number range */


		Pglist_type = PG_LIST;

		/* Parse the argument to -o and save the ranges */
		/* first set up where to link onto tail of list */
		linkpoint_p_p = &Page_range;

		/* walk through the -o argument */
		for (p = pagelist; *p != '\0';   ) {

			/* skip any leading white space */
			while (isspace(*p)) {
				p++;
			}

			/* get page number (which may or may not be the
			 * start of a range of numbers) */
			lower = (short) strtol(p, &beyondnum, 10);
			if (beyondnum == p || lower <= 0 || lower < startpage) {
				/* bad number from user, jump to error out */
				break;
			}

			p = beyondnum;
			/* skip any white space */
			while (isspace(*p)) {
				p++;
			}

			if (*p == '-') {
				/* there is a range of page numbers. Get the
				 * upper limit of the range */
				upper = (short) strtol(++p, &beyondnum, 10);
				if (beyondnum == p || upper <= 0
							|| upper < lower) {
					/* bad value from user */
					break;
				}
				p = beyondnum;
				while (isspace(*p)) {
					p++;
				}
				if (*p == ',') {
					p++;
				}
				else if (*p != '\0') {
					break;
				}
			}
			else if (*p == ',') {
				/* not a range, so treat like range of n-n */
				upper = lower;
				p++;
			}
			else if (*p == '\0') {
				upper = lower;
			}
			else {
				/* something other than dash, comma, or end of
				 * string, which is a user error */
				break;
			}

			/* save info about this page range */
			MALLOC(RANGELIST, new_range, 1);
			new_range->begin = lower;
			new_range->end = upper;
			new_range->next = (struct RANGELIST *) 0;

			/* link onto tail of list */
			*linkpoint_p_p = new_range;
			linkpoint_p_p = &(new_range->next);
		}

		/* if jumped out of loop without finishing parsing, user
		 * gave us something we didn't understand */
		if (*p != '\0') {
			if (Mupmate == YES) {
				l_yyerror(0, -1, "Run > Set Options > Pages to display: value is invalid.");
			}
			else {
				l_yyerror(0, -1, "argument for -o (list of pages to display) is invalid");
			}
		}
	}
}


/* Calculate the page number for the final page and put it in Last_pagenum.
 * If there is a -o list, make sure all the
 * pages listed on the -o list are less than that. If they aren't remove them
 * from the list. Without this step, Mup could go into a loop trying to print
 * a page that doesn't exist. */

static void
prune_page_range(start_page)

int start_page;		/* number given to the first page via the -p option
			 * or via the firstpage parameter */

{
	struct MAINLL *mll_p;	/* to count page feeds */
	struct RANGELIST **range_p_p;
	int pruned;		/* if we removed anything from list */

	/* find the largest page number */
	Last_pagenum = start_page;
	for (mll_p = Mainllhc_p; mll_p != (struct MAINLL *) 0; mll_p = mll_p->next) {
		if (mll_p->str == S_FEED && mll_p->u.feed_p->pagefeed == YES) {
			Last_pagenum++;
		}
	}

	/* If there are extra pages for gridsatend, add those on */
	if (Atend_info.separate_page == YES) {
		int grids_per_page;

		grids_per_page = Atend_info.grids_per_row *
				Atend_info.rows_per_page;
		/* round up */
		Last_pagenum += (Atend_info.grids_used + grids_per_page - 1)
						/ grids_per_page;
	}


	if (Pglist_type != PG_LIST) {
		return;
	}

	/* see if any items in Page_range are bigger
	 * than the biggest page number */
	pruned = NO;
	for (range_p_p = &Page_range; *range_p_p != (struct RANGELIST *) 0;
					range_p_p = &((*range_p_p)->next) ) {
		if ((*range_p_p)->begin > Last_pagenum) {
			/* need to get rid of this entire entry, because none
			 * of the pages listed actually exist */
			pruned = YES;
			if ((*range_p_p = (*range_p_p)->next)
						== (struct RANGELIST *) 0) {
				/* last one on the list */
				break;
			}
		}
		else if ((*range_p_p)->end > Last_pagenum) {
			/* just need to shorten this range */
			(*range_p_p)->end = Last_pagenum;
			pruned = YES;
		}
	}

	if (pruned == YES) {
		l_warning( (char *) 0, -1, "-o list included one or more pages that don't exist");
	}
}


/* given a page number, return YES if that page should be printed now, NO
 * if not. If user gave a list of pages to print using -o, we print the page
 * only if it is the very first thing on the list. If there is a smaller
 * number further on in the list, we'll do that page later on another pass.
 * The print phase has to keep making multiple passes until the list is
 * empty. This allows user to print things out in random order, which may
 * be useful especially for 2-on-1 printing, where for example, you may
 * want a 4-page "booklet", printing page 4 then page 1 on one side and
 * pages 2 and 3 on the other side.
 */

int
onpagelist(pagenum)

int pagenum;

{
	struct RANGELIST *old_range;	/* to keep track of item to free */

	switch (Pglist_type) {

	case PG_ALL:
		return(YES);

	case PG_ODD:
		return (pagenum & 1) == 1 ? YES : NO;

	case PG_EVEN:
		return (pagenum & 1) == 0 ? YES : NO;

	default:
		if (Page_range == (struct RANGELIST *) 0) {
			/* ran off the end of list, so no more to print */
			return(NO);
		}

		if (Page_range->begin == pagenum) {
			/* is first on list so we will print it.
			 * But first, fix up the list. If we've used up all of
			 * the current range, free it and point to the next. */
			(Page_range->begin)++;
			if (Page_range->begin > Page_range->end) {
				old_range = Page_range;
				Page_range = Page_range->next;
				FREE(old_range);
			}
			return(YES);
		}
		break;
	}
	return(NO);
}


/* return YES if we were doing a page list (-o option) but have now handled
 * all of the pages */

int
last_page()
{
	if (Pglist_type == PG_LIST) {
		return ((Page_range == 0) ? YES : NO);
	}
	else {
		return ((Pagenum == Last_pagenum) ? YES : NO);
	}
}


/* handle the argument to -s (list of staffs to make visible). For each
 * visible staff, make an SSV marking it visible */

static void
vis_staffs(stafflist)

char *stafflist;
{
	int s;				/* staff index */
	int v;				/* voice index */
	long start, end;		/* staff range */


	if (stafflist == (char *) 0) {
		/* user didn't use -s, so set to all visible */
		for (s = 1; s <= MAXSTAFFS; s++) {
			Staff_vis[s] = YES;
			for (v = 1; v <= MAXVOICES; v++) {
				Voice_vis[s][v] = YES;
			}
		}
		return;
	}

	/* init to all invisible */
	for (s = 1; s <= MAXSTAFFS; s++) {
		Staff_vis[s] = NO;
		for (v = 1; v <= MAXVOICES; v++) {
			Voice_vis[s][v] = NO;
		}
	}

	for (  ; *stafflist != '\0';   ) {
		/* get first staff number in list. Will error check below */
		start = strtol(stafflist, &stafflist, 10);

		if (*stafflist == '-') {
			/* we have a range. Get end of range */
			end = strtol(stafflist + 1, &stafflist, 10);
		}
		else {
			/* single number, use end same as start */
			end = start;
		}

		/* error check */
		if (start < 1 || start > MAXSTAFFS || end < 1 ||
					end > MAXSTAFFS || end < start) {
			if (Mupmate == YES) {
				l_yyerror(0, -1, "Run > Set Options > Staffs to display/play: value is invalid.");
			}
			else {
				l_yyerror(0, -1, "invalid argument for %cs option (staffs to make visible)", Optch);
			}
			return;
		}

		/* see if there is a voice qualifier */
		if (*stafflist == 'v') {
			stafflist++;
			switch (*stafflist) {
			case '1':
				v = 1;
				break;
			case '2':
				v = 2;
				break;
			case '3':
				v = 3;
				break;
			default:
				if (Mupmate == YES) {
					l_yyerror(0, -1, "Run > Set Options > Staffs to display/play: voice qualifier must be 1, 2, or 3.");
				}
				else {
					l_yyerror(0, -1, "voice qualifier for -s option must be 1, 2, or 3");
				}
				return;
			}
			stafflist++;
			if (*stafflist != '\0' && *stafflist != ',') {
				if (Mupmate == YES) {
					l_yyerror(0, -1, "Run > Set Options > Staffs to display/play: invalid voice qualifier. (Maybe missing comma?)");
				}
				else {
					l_yyerror(0, -1, "invalid voice qualifier for -s option (missing comma?)");
				}
				return;
			}
		}
		else {
			/* no voice qualifier */
			v = 0;
		}

		/* mark all staffs in range as visible */
		for (  ; start <= end; start++) {
			Staff_vis[start] = YES;
			if (v != 0) {
				Voice_vis[start][v] = YES;
			}
			else {
				/* no voice qualifier, so all voices are visible */
				int vn;
				for (vn = 1; vn <= MAXVOICES; vn++) {
					Voice_vis[start][vn] = YES;
				}
			}
		}

		/* if comma for another range, skip past it */
		if (*stafflist == ',') {
			stafflist++;
		}
	}
}


#ifdef NEED_GETOPT
/* for non-unix or other systems that don't have a getopt() function,
 * define one here. This is NOT a general purpose implementation of getopt(),
 * but something good enough to work with Mup */

int optind = 1;
char *optarg;
static int argoffset;
int opttype P((int option, char *optstring));

#define NOARG 1
#define WITHARG	2
#define BADOPT  3

int
getopt(argc, argv, optstring)

#ifdef __STDC__
int argc;
char * const *argv;
const char *optstring;
#else
int argc;
char **argv;
char *optstring;
#endif

{
	int option;


	if (optind >= argc) {
		return(EOF);
	}

	if (argoffset == 0) {
#ifdef __DOS__
		if (argv[optind][argoffset] == '-'
					|| argv[optind][argoffset] == '/') {
#else
		if (argv[optind][argoffset] == '-') {
#endif
			argoffset = 1;
		}
		else {
			return(EOF);
		}
	}

	/* determine if option is valid and if should have an argument */
	option = argv[optind][argoffset] & 0x7f;
	switch (opttype(option, (char *) optstring)) {
	case NOARG:
		/* valid option without argument. Keep track of where
		 * to look for next option */
		if (argv[optind][++argoffset] == '\0') {
			optind++;
			argoffset = 0;
		}
		break;

	case WITHARG:
		/* valid option with argument. */
		if (argv[optind][++argoffset] != '\0') {
			/* argument immediately follows in same argv */
			optarg = &(argv[optind][argoffset]);
			optind++;
		}
		else {
			/* white space. argument must be in next argv */
			optind++;
			if (optind >= argc) {
				fprintf(stderr, "missing argument to %c%c option\n", Optch, option);
				return('?');
			}
			optarg = &(argv[optind][0]);
			optind++;
		}
		argoffset = 0;
		break;

	default:
		fprintf(stderr, "invalid option %c%c\n", Optch, option);
		option = '?';
	}
	return(option);
}


/* look up option in optstring and return type of option */

int
opttype(option, optstring)

int option;
char *optstring;

{
	char *p;

	for (p = optstring; *p != '\0'; ) {
		if (*p++ == option) {
			return(*p == ':' ? WITHARG : NOARG);
		}
		if (*p == ':') {
			p++;
		}
	}
	return(BADOPT);
}

#endif
