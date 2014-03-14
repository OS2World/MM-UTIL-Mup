/* Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2003, 2004, 2005, 2006,
 * 2008, 2010 by Arkkra Enterprises */
/* All rights reserved */
/*
 *	globals.c
 *
 *	This files defines all the global variables used in more than one
 *	file, except for ones that are used only by yacc and lex.
 */

#include "structs.h"
#include "rational.h"
#include "globals.h"

/*
 * Define the fixed SSV structures, which accumulate attributes of the
 * score, staffs, and voices.
 */
struct SSV Score;
struct SSV Staff[MAXSTAFFS];
struct SSV Voice[MAXSTAFFS][MAXVOICES];

/*
 * Define command line requested staff and voice visibilities.  Each value is
 * YES or NO.
 */
short Staff_vis[MAXSTAFFS + 1];
short Voice_vis[MAXSTAFFS + 1][MAXVOICES + 1];

/*
 * Define head and tail cells of the main linked list set up by the parser.
 */
struct MAINLL *Mainllhc_p;
struct MAINLL *Mainlltc_p;

int Optch = OPTION_MARKER;	/* character for command line options */
int Mupmate = NO;		/* was Mup called from Mupmate? */
int Errorcount;		/* number of errors found so far */
int Maxverses;		/* maximum number of verse numbers used in the song */
short Meas_num = 1;	/* count measure numbers */
int Preproc = NO;	/* was -E specified on command line? */
int Ppcomments = NO;	/* was -C specified on command line? */

int Context = C_MUSIC;
int Curr_family = BASE_TIMES;
int Curr_font = FONT_TR;
int Curr_size = DFLT_SIZE;
struct USERFONT *Userfonts;
int Got_some_data = NO;
int Doing_tab_staff;	/* YES while parsing a line for a tab staff, else NO */
int Doing_MIDI = NO;
char *Curr_filename;
char *Outfilename = "";
int Vflag = NO;
int Vcombused = NO;	/* was the voicecombine parameter ever used? */
int CSBused = NO;	/* was cross staff beaming used in this song? */
int CSSused = NO;	/* was cross staff stemming used in this song? */
int CSSpass = NO;	/* YES while doing a special pass for cross staff stem*/

/*
 * Because of look-ahead, an error message could often have the line number
 * one too high if we increment yylineno at the moment the newline is seen,
 * so we keep track of whether the previous byte read was a newline, and
 * only increment yylineno when the next character after that is read.
 */
int Lineno_increment = 0;

/*
 * The following table lets you conveniently find the character name of any
 * note head type of form GF_NORMAL.  It is to be indexed like this:
 *	headchar = Hctab [ basictime > 2 ? 3 : basictime ];
 */
unsigned char Hctab [] = {
	C_DBLWHOLE,	C_1N,	C_2N,	C_4N
};

/*
 * This table is like Hctab, but for X notes.  Note that for half notes and
 * longer, we actually draw the note as a diamond instead of an X.
 */
unsigned char Xhctab[] = {
	C_DWHDIAMOND,	C_DIAMOND,	C_DIAMOND,	 C_XNOTE
};

/*
 * This table is like Hctab, but for diamond shaped notes.
 */
unsigned char Dhctab[] = {
	C_DWHDIAMOND,	C_DIAMOND,	C_DIAMOND,	 C_FILLDIAMOND
};

/*
 * The following table lets you conveniently find the character name of any
 * rest type, whole or shorter.  It is to be indexed by log2(basictime).
 */
unsigned char Resttab[] = {
	C_LL1REST, C_LL2REST, C_4REST, C_8REST, C_16REST, C_32REST, C_64REST,
	C_128REST, C_256REST,
};

/*
 * The following table tells how many letters up from C each note is.  It is
 * to be indexed by (noteletter - 'a').
 */
int Letshift[] = { 5, 6, 0, 1, 2, 3, 4, };
	        /* a  b  c  d  e  f  g */

/* the note letters in the order of the circle of fifths */
char Circle[] = "fcgdaeb";

/* internal accidental letters */
char Acclets[] = "B&n#x";

/* external accidental symbols */
char *Acctostr[] = { "&&", "&", "", "#", "x" };

/*
 * Define strings for pedstyle = pedstar ("Ped." and the star).
 */
char Ped_start[] = { FONT_ZI, 18, 'P', 'e', 'd', '.', '\0' };
char Ped_stop[] =  { FONT_ZD1, 14, 'i', '\0' };

/*
 * Define the string info for standard guitar tuning.  Note that the octaves
 * are for how it should be printed; the actual sound is an octave lower.
 * When outputting MIDI, we check whether the tablature staff is using this
 * default array, and if so, automatically transpose down by 12 halfsteps.
 */
struct STRINGINFO Guitar[DEFTABLINES] = {
	{ 'e', '\0', 0, 5 },
	{ 'b', '\0', 0, 4 },
	{ 'g', '\0', 0, 4 },
	{ 'd', '\0', 0, 4 },
	{ 'a', '\0', 0, 3 },
	{ 'e', '\0', 1, 3 },
};

/*
 * These arrays are used to keep track of things while adjusting the pitches
 * of notes to account for octave marks. They are indexed by staff number,
 * so element 0 of each array is unused. Octave mark related transposition
 * is done both in MIDI code and trantab code.
 */
int Octave_adjust[MAXSTAFFS+1];	/* how many octaves to adjust due to
				 * user-specified octave marks */
int Octave_bars[MAXSTAFFS+1];	/* how many bar lines to cross with
				 * current Octave_adjust (if Octave_adjust is
				 * zero, this variable is meaningless) */
float Octave_count[MAXSTAFFS+1];/* number of counts into measure that
				 * Octave_adjust applies in measure after
				 * Octave_bars have gone by. (if Octave_adjust
				 * is zero, this variable is meaningless */
/*
 * Define fixed location variables.  For all of these, only the absolute
 * coordinates are used.
 */
float _Page	[NUMCTYPE];	/* whole page */
float _Win	[NUMCTYPE];	/* middle (music) window */
float _Cur	[NUMCTYPE];	/* current position */

/*
 * Define the structures for headers and footers.
 */
struct BLOCKHEAD Header;	/* first page header */
struct BLOCKHEAD Footer;	/* first page footer */
struct BLOCKHEAD Header2;	/* later page header */
struct BLOCKHEAD Footer2;	/* later page footer */

/*
 * used by print phase to keep track of current staff locations
 */
float *Score_location_p;	/* score coord from FEED struct */
float Staffs_y[MAXSTAFFS + 1];	/* absolute Y of the staffs of a score */

/*
 * While constructing a GRPSYL list of groups or lyrics, or a list of STUFF,
 * any of which could be being defining for multiple staffs at once and/or more
 * than one vno, keep a pointer to the list of staffs and vnos being defined.
 * Once we gather an entire line of input, the GRPSYL list or STUFF list is
 * cloned for each staff being defined, and the information is moved to be
 * associated with the appropriate STAFF structs.
 */
struct RANGELIST *Staffrange_p;
struct RANGELIST *Vnorange_p;

/*
 * During parse phase, this keeps track of the place (PL_ABOVE, PL_BELOW,
 * or PL_BETWEEN) of the current thing being collected (groups, lyrics,
 * or stuff).
 */
short Place;

/*
 * Snapshot of the state of pedals at the beginning of endings.
 * The zeroth element of the array is used as a flag. If it is YES,
 * the rest of the array contains the pedal state for each staff,
 * YES for pedal on, NO for off. If the zeroth element is NO,
 * the rest of the array is meaningless.
 */
short Ped_snapshot[MAXSTAFFS + 1];

/* table to give a quick mapping from staff number to STAFF struct */
struct MAINLL *Staffmap_p[MAXSTAFFS + 1];

/* pointer to beginning of all the STAFF structs in current measure */
struct MAINLL *List_of_staffs_p;

struct SVRANGELIST *Svrangelist_p;

/* beginning of the list of GRPSYL structs currently being built */
struct GRPSYL *Curr_gs_list_p;

/* If 0, no multirest in current measure yet.
 * If 1, got a multirest.
 * If 2, got both a multirest and music data */
short Got_multirest;

/* YES if input contained at least one group in the current measure */
short Got_group;

short Pagenum;			/* which page we are currently printing */
int Last_pagenum;		/* page number of the final page */

/* items used when chord grids are to be printed at the end of the song */
struct ATEND_INFO Atend_info;

/*
 * Rectab is a malloc'ed array of structures representing rectangles, each of
 * which encloses some object to be drawn.  There are routines that stack
 * objects, and they use Rectab to keep track of objects that have been
 * stacked, so that the next object can be stacked as close as possible without
 * overlapping them.  The function init_rectab() should be called before using
 * Rectab, and free_rectab() should be called when done with it.  Reclim tells
 * how many rectangles are currently in Rectab.  It should be incremented by
 * calling inc_reclim(), which knows when to realloc.  After stacking some
 * rectangles, you can set Reclim back to 0 to start on another batch.
 */
struct RECTAB *Rectab;
int Reclim;

/*
 * From the beginning of the placement phase (considered to be transgroups(),
 * although you could argue that real placement doesn't begin until setnotes()),
 * until placement starts needing to consider multiple staffs at a time (in
 * restsyl.c after apply_staffscale()), it is convenient to pretend that the
 * staffscale parameter doesn't exist.  The code there ignores it.  However,
 * that code calls some utility functions that use staffscale; so we need to
 * make it look like staffscale is 1.   initstructs() sets it to 1, but during
 * this part of the placement phase we need to avoid changing it when assigning
 * SSVs.  This global flag will be set to YES during that period of time,
 * causing asgnssv() to ignore any attempted changes to staffscale.
 */
int Ignore_staffscale;

/*
 * Define a variable for a staff's staffscale, and other variables which are
 * staffscale times the corresponding macro symbol in all caps.  This is to
 * avoid recalculating these all the time.  These variables are for use in
 * files where a main function loops over staffs, and calls a tree of
 * subroutines for each staff.  The main function should set these variables
 * for the current staff, and from there on the code can use them.  At the
 * start of the placement phase they are initialized to their default values by
 * doing initstructs() and set_staffscale(0).
 */
float Staffscale;	/* for this staff */
float Stdpad;		/* STDPAD on this staff */
float Stepsize;		/* STEPSIZE on this staff */
float Flagsep;		/* FLAGSEP on this staff */
float Smflagsep;	/* SMFLAGSEP on this staff */
float Tupheight;	/* TUPHEIGHT on this staff */

/* define rational number constants that may be useful in multiple files */
RATIONAL Zero = {0,1};
RATIONAL One_fourth = {1,4};
RATIONAL One_third = {1,3};
RATIONAL One_half = {1,2};
RATIONAL Two_thirds = {2,3};
RATIONAL Three_fourths = {3,4};
RATIONAL One = {1,1};
RATIONAL Two = {2,1};
RATIONAL Three = {3,1};
RATIONAL Four = {4,1};

/*
 * Define something longer than the longest possible measure.  See the comment
 * by the #define for MAXTSLEN.
 */
RATIONAL Maxtime = {(MAXTSLEN - 3) * 99 + 1, 1};

int Debuglevel;			/* bitmap of what message classes to print */

/*
 * Define a set of coordinate arrays to be used in debugging, 2 of them for
 * now.  If you put in debugging code to set AN,AS,AE,AW, the MUP_BB code in
 * print.c will draw a box at those coordinates on each page.  That code loops
 * through this array, drawing boxes, stopped when finds these coords are zero.
 */
float Debug_coords[2][NUMCTYPE];
