
/* Copyright (c) 1995, 1998, 1999, 2000, 2001 by Arkkra Enterprises */
/* All rights reserved */

/* functions to generate the bitmap output file from the Mup input.
 * Includes functions for running Mup to produce PostScript, and to run
 * Ghostscript on the output of Mup */


#ifdef __WATCOMC__
#include <process.h>
#include <errno.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include "mupdisp.h"

#ifdef unix
#include <sys/wait.h>
#endif

/* bitmap for message to tell user to wait while we do our thing... */
#include "waitmsg.bm"

char Small_adjust[200]; /* PostScript instructions to add to get small
			 * version of output (small enough for a whole page
			 * to fit on the screen) */
char Large_adjust[200]; /* PostScript instructions to add for the large,
			 * scroll-able version of the output */
double Reduction_factor;/* how to adjust for small version */
char Papersize[32];	/* -sPAPERSIZE argument to Ghostscript */

static void do_genfile P((int fd, int do_full));
static void copyfile P((int srcfile, long start, long end, int destfile));
static void genfile P((char *outfile, int do_full));


/* generate one of the bitmap files if not already generated,
 * either full or partial page based on value of fullpgmode.
 * Return file descriptor of appropriate bitmap */

int
gen1file(fullpgmode)

int fullpgmode;		/* if YES, generate full-page version */

{
	if (fullpgmode == YES) {
		/* if bitmap file not already created, make it now */
		if (Fullbitmaps <= 0) {
			Fullbitmaps = create_tmpfile(Fullfile);

			/* generate Postscript to scale and translate
			 * output appropriately */
			sprintf(Small_adjust, "%f %f translate\n%f %f scale\n",
					BITS_PER_LINE
					* ((1.0 - Reduction_factor) / 2.0),
					LINES_PER_PAGE - (LINES_PER_PAGE
					* Reduction_factor
					* Conf_info_p->adjust) - 4,
					Reduction_factor,
					Reduction_factor * Conf_info_p->adjust);

			/* tell user to wait */
			( *(Conf_info_p->bitmap) ) (Waitmsg_bitmap,
					Waitmsg_width, Waitmsg_height);
			/* generate the bitmap */
			genfile(Fullfile, YES);
		}
		close (Fullbitmaps);
#ifdef O_BINARY
		Fullbitmaps = open(Fullfile, O_RDONLY | O_BINARY, 0);
#else
		Fullbitmaps = open(Fullfile, O_RDONLY, 0);
#endif
		return(Fullbitmaps);
	}
	else {
		/* if bitmap file not already created, make it now */
		if (Partbitmaps <= 0) {
			Partbitmaps = create_tmpfile(Partfile);

			sprintf(Large_adjust, "%f %f translate\n%f %f scale\n",
					0.0, (1.0 - Conf_info_p->adjust)
					* LINES_PER_PAGE,
					1.0, Conf_info_p->adjust);

			/* tell user to wait */
			( *(Conf_info_p->bitmap) ) (Waitmsg_bitmap,
					Waitmsg_width, Waitmsg_height);
			/* generate the bitmap */
			genfile(Partfile, NO);
		}
		close (Partbitmaps);
#ifdef O_BINARY
		Partbitmaps = open(Partfile, O_RDONLY | O_BINARY, 0);
#else
		Partbitmaps = open(Partfile, O_RDONLY, 0);
#endif
		return(Partbitmaps);
	}
}


/* generate a file containing bitmap representations of pages */

static void
genfile(outfile, do_full)

char *outfile;          /* put bitmaps in this file */
int do_full;            /* YES if to do full version of page */

{
	char outfileopt[L_tmpnam+14];   /* space for -sOutputFile=outfile */
	int ret;                /* return value from Ghostscript */
	struct stat statinfo;
#ifdef unix
	int pip[2];     /* for pipe to gs */
	int child;      /* Ghostscript's process ID */
	

	/* create a pipe to Ghostscript */
	if (pipe(pip) != 0) {
		Exit_errmsg = "can't set up pipe\n";
		(*Conf_info_p->cleanup) (1);
	}

	/* execute Ghostscript */
	switch (child = fork()) {
	case 0:
		/* connect its input to the pipe. Discard stdout and stderr */
		close(0);
		dup(pip[0]);
		close(1);
		dup(Nulldev);
		close(2);
		dup(Nulldev);
		sprintf(outfileopt, "-sOutputFile=%s", outfile);
		execlp("gs", "gs", "-sDEVICE=bit", Papersize, "-dQUIET",
					 outfileopt, "-", (char *) 0);
		/*FALLTHRU*/
	case -1:
		Exit_errmsg = "can't exec Ghostscript";
		(*Conf_info_p->cleanup) (1);
		break;
	default:
		close(pip[0]);

		/* generate the file */
		do_genfile(pip[1], do_full);
		close(pip[1]);

		/* wait for Ghostscript to complete */
		while ( wait(&ret) != child )
			;
		if (ret != 0 || stat(Gs_errfile, &statinfo) == 0) {
			Exit_errmsg = "Ghostscript failed\n";
			(*Conf_info_p->cleanup) (1);
		}
	}
#else
#ifdef __WATCOMC__
	/* DOS can't do pipes, so use a temp file instead. */
	int tmpf;
	char pstmpfile[L_tmpnam];
	static char message[128]; /* buffer for error message */


	/* make a temp file for the modified PostScript */
	tmpf = create_tmpfile(pstmpfile);
	do_genfile(tmpf, do_full);
	close(tmpf);

	/* execute Ghostscript on the temp file */
	sprintf(outfileopt, "-sOutputFile=%s", outfile);
	ret = spawnlp(P_WAIT, "gs", "gs", "-sDEVICE=bit", Papersize,
		"-dQUIET", "-dNOPAUSE", outfileopt, pstmpfile, (char *) 0);

	if (ret != 0) {
		/* try executing gs386 instead */
		/**** probably should check for a specific return code ****/
		ret = spawnlp(P_WAIT, "gs386", "gs386", "-sDEVICE=bit",
	  			Papersize, "-dQUIET", "-dNOPAUSE",
				outfileopt, pstmpfile, (char *) 0);
	}

	/* remove the temp file */
        unlink(pstmpfile);
	if (ret != 0 || stat(Gs_errfile, &statinfo) == 0) {
		unlink(outfile);
		if (ret == -1) {
			sprintf(message, "Ghostscript error %d (gs386 may be missing from your PATH?)\n", ret);
		}
		else {
			sprintf(message, "Ghostscript error %d\n", ret);
		}
		Exit_errmsg = message;
		(*Conf_info_p->cleanup) (1);
	}
#else
	Exit_errmsg = "unsupported platform\n";
	(*Conf_info_p->cleanup) (1);
#endif
#endif
}


/* determine proper PAPERSIZE, and set parameter appropriately for that
 * page size */

/* table to translate width and height to PAPERSIZE name */
struct PaperSizeInfo {
	int x;		/* width, must be <= MAX_BITS_PER_LINE */
	int y;		/* height, must be <= MAX_LINES_PER_PAGE */
	char *sizename;	/* name of paper size */
	double reduction;	/* how much to multiply by in small mode */
} Size_table[] = {
	{ 612, 792, "letter", 0.48 },	/* default has to be first */
	{ 540, 720, "note", 0.525 },
	{ 612, 1008, "legal", 0.375 },
	{ 595, 842, "a4", 0.46 },
	{ 421, 595, "a5", 0.65 },
	{ 297, 421, "a6", 0.8 },
	{ 612, 936, "flsa", 0.41 },
	{ 396, 612, "halfletter", 0.63 },
	{ 0, 0, (char *) 0 }
};

/* How many points away from a standard paper size we allow to
 * account for roundoffs, since user was specifying in inches or cm
 * rather than points, so they may be off somewhat */
#define FUZZ	24

void
get_paper_size(x, y)

int x, y;

{
	int i;

	/* if we've already been called once, we're already done */
	if (Papersize[0] == '-') {
		return;
	}

	/* go through table till we find a standard size that matches */
	for (i = 0; Size_table[i].x != 0; i++) {
		if ( (x > Size_table[i].x - FUZZ)
				&& (x < Size_table[i].x + FUZZ)
				&& (y > Size_table[i].y - FUZZ)
				&& (y < Size_table[i].y + FUZZ) ) {

			/* close enough to a standard size,
			 * so we'll go with it */
			break;
		}
	}

	if (Size_table[i].x == 0) {
		/* if not found in table, use the default (letter) */
		i = 0;
	}

	/* set appropriate parameters */
	Bits_per_line = Size_table[i].x;
	Lines_per_page = Size_table[i].y;
	Bytes_per_line = (Bits_per_line >> 3) + ((Bits_per_line & 0x7) ? 1 : 0);
	Reduction_factor = Size_table[i].reduction;
	sprintf(Papersize, "-sPAPERSIZE=%s", Size_table[i].sizename);
}


/* generate bitmap from PostScript by calling Ghostscript */

static void
do_genfile(fd, do_full)

int fd;		/* file descriptor to write to */
int do_full;	/* if YES, do full page mode */

{
	struct Pginfo *pg_p;    /* for info about each page */
	char errhandler[200];   /* PostScript error handler redefinition */


	/* arrange to quit Ghostscript on errors (shouldn't get errors
	 * from Mup output, but could run out of memory, causing VMerror) */
	sprintf(errhandler, "/handleerror { $error begin (%s) (w) file dup errorname 100 string cvs writestring (\\n) writestring end quit } def\n", Gs_errfile);
	write(fd, errhandler, strlen(errhandler));

	/* copy the prolog */
	copyfile(Psfile, Beginprolog, Endprolog, fd);
	
	/* for each page add proper scaling, etc information */
	for (pg_p = Pagehead; pg_p != (struct Pginfo *) 0;
							pg_p = pg_p->next) {
		write(fd, "save\n", 5);
		if (do_full == YES) {
			char tmpbuff[100];

			write(fd, "0.2 setgray\n", 12);
			sprintf(tmpbuff, "0 0 moveto 0 %d lineto %d %d lineto %d 0 lineto closepath fill\n",
					Lines_per_page,
					Bits_per_line,
					Lines_per_page,
					Bits_per_line);
			write(fd, tmpbuff, strlen(tmpbuff));

			write(fd, Small_adjust, strlen(Small_adjust));
			write(fd, "1 setgray\n", 10);
			write(fd, tmpbuff, strlen(tmpbuff));
			write(fd, "0 setgray\n", 10);
		}
		else {
			write(fd, Large_adjust, strlen(Large_adjust));
		}

		/* copy a page worth of PostScript */
		copyfile(Psfile, pg_p->begin, pg_p->end, fd);
		write(fd, "restore\n", 8);
	}

	/* finish up the Ghostscript input */
	write(fd, "quit\n", 5);
}


/* copy a portion of one file descriptor to another file description */

static void
copyfile(srcfile, start, end, destfile)

int srcfile;    /* read from this file */
long start;     /* start at this offset in srcfile */
long end;       /* go this far in srcfile */
int destfile;   /* write to current position in this file */

{
	char buff[BUFSIZ];	/* buffer for copying */
	int size;		/* how much to copy at once */
	long remaining;		/* how much still to be copied */

 
	/* go to specified spot in source file */
	lseek(srcfile, start, SEEK_SET);

	/* copy a block at a time, last piece will be whatever is left */
	for (remaining = end - start; remaining > 0L; remaining -= BUFSIZ) {
		size = (remaining >= BUFSIZ ? BUFSIZ : remaining);
		
		if (read(srcfile, buff, size) == size) {
			if (write(destfile, buff, size) != size) {
				Exit_errmsg = "File write failed (probably out of disk space)\n";
				( *(Conf_info_p)->cleanup) (1);
			}
		}
		else {
			Exit_errmsg = "Read failed\n";
			( *(Conf_info_p)->cleanup) (1);
		}
	}
}


/* execute Mup, putting output in Psfile */

void
run_mup(argv)

char **argv;    /* arguments to pass to Mup */

{
	int ret;
	int child;


#ifdef unix
	switch(child = fork()) {
	case 0:
		/* arrange to put output in Psfile */
		close(1);
		dup(Psfile);

		/* execute Mup */
		execvp("mup", argv);
		fprintf(stderr, "failed to execute Mup\n");
		exit(1);
	case -1:
		fprintf(stderr, "failed to fork Mup\n");
		generalcleanup(1);
		/*NOTREACHED*/
		break;
	default:
		/* wait for Mup to complete */
		while (wait(&ret) != child)
			;
		if (ret != 0) {
			unlink(Mupfile);
			generalcleanup(ret);
		}
		break;
	}
#else
#ifdef __WATCOMC__
	/* arrange to put output in Psfile */
	close(1);
	dup(Psfile);

	/* execute Mup */
	if ((ret = spawnvp(P_WAIT, "mup", argv)) != 0) {
		if (errno != 0) {
			perror("Mup failed");
		}
		unlink(Mupfile);
		exit(ret);
	} 
#else
	fprintf(stderr, "unsupported platform\n");
#endif
#endif
}
