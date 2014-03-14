
/* Copyright (c) 1995, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2006,
 * 2007, 2009 by Arkkra Enterprises */
/* All rights reserved */

/* functions for printing endings, pedal marks, phrase marks, etc */

#include "defines.h"
#include "structs.h"
#include "globals.h"

/* width of tapered curve at endpoint relative to maximum width */
#define TAPERWID	(0.4)


/*
 * Define a structure for storing points of a curve, whether generated (like
 * for phrase marks) or user-specified.  It also stores information used in
 * calculating Bezier curves that will be drawn between each pair of
 * neighboring points.  The "control points" are points 1 and 2 for the
 * Bezier curve going from this point to the next point.  These structures
 * get their x and y filled in from CURVE or CRVLIST structures.
 */
struct CURVEINFO {
	float x, y;	/* point's coords */
	float len;	/* length of line segment from here to next point */
	float ang;	/* angle between the 2 segments at this point */
	int bend;	/* bend direction at point: 1=clockwise, -1=counter */
	float slopetan;	/* slope of line "tangent" to this point if axes are */
			/* rotated such that segment starting here is horiz. */
	float x1, y1;	/* control point 1 for segment starting at this point */
	float x2, y2;	/* control point 2 for segment starting at this point */
};

/* static functions */
static void do_endings P((struct MAINLL *first_p, struct MAINLL *last_p,
		char *endlabel, int carryout));
static void draw_ending P((int staffno, double ry, struct MAINLL *first_p,
		struct MAINLL *last_p, char *endlabel, int carryout));
static void pr_endlabel P((double x, double y, char *label));
static void pr_end_line P((double begin_x, double end_x, double y,
		int carryout));
static int is_top_visible_in_range P((int staffno, int top));
static void calccurve P((struct CURVEINFO v[], int num));
static void findcontrol P((struct CURVEINFO v[], int num));
static void font_bbox P((int mfont, struct USERFONT *ufont_p, int *llx_p,
		int *lly_p, int *urx_p, int *ury_p));
static void pr_usym_ps P((struct USERFONT *ufont_p, int mfont, int code));
static void pr_bbox P((char *name, int mfont, struct USERFONT *ufont_p,
		int code));
static char *sym_prefix P((int mfont));



/* whenever we hit a FEED, draw any endings associated with the score */

void
pr_endings(main_feed_p)

struct MAINLL *main_feed_p;	/* FEED */

{
	static char *endlabel = (char *) 0;/* ending label if had to carry over
					 * to next score */
	struct MAINLL *curr_p;		/* where we are in main list */
	struct MAINLL *first_p;		/* where an ending begins */
	struct MAINLL *last_bar_p = 0;	/* points to last bar on score so far */


	debug(512, "pr_endings");

	first_p = (struct MAINLL *) 0;

	/* go through the entire score line. For every set of measures that have
	 * endings, draw them. */
	for (curr_p = main_feed_p->next; curr_p != (struct MAINLL *) 0;
					curr_p = curr_p->next) {

		/* go just to end of current score */
		if (curr_p->str == S_FEED) {
			break;
		}

		/* if there is a pseudo bar, see if it is in an ending */
		if (curr_p->str == S_CLEFSIG) {
			if (curr_p->u.clefsig_p->bar_p != (struct BAR *) 0 &&
					curr_p->u.clefsig_p->bar_p->endingloc
					!= NOITEM) {
				first_p = curr_p;
				endlabel = curr_p->u.clefsig_p->bar_p->endinglabel;
			}
			continue;
		}

		/* for each bar, check its endingloc and act accordingly */
		else if (curr_p->str == S_BAR) {

			switch(curr_p->u.bar_p->endingloc) {

			case ENDITEM:
				if (first_p == (struct MAINLL *) 0) {
					pfatal("ending without beginning");
				}
				/*FALLTHRU*/
			case NOITEM:
				/* if we were doing an ending, we reached the
				 * end of it, so handle it */
				if (first_p != (struct MAINLL *) 0) {
					/* it doesn't seem like it should be
					 * possible to get inside this IF for
					 * the NOITEM case, but it doesn't
					 * hurt anything to have to code as it
					 * is, and I don't want to change it for
					 * fear it would break some obscure
					 * circumstance I've forgotten about */
					do_endings(first_p, curr_p, endlabel, NO);
					endlabel = (char *) 0;
					first_p = (struct MAINLL *) 0;
				}
				break;

			case STARTITEM:
				/* if we are also implictly ending a previous
				 * ending, do that first. In any case, keep
				 * track of where this ending begins. */
				if (first_p != (struct MAINLL *) 0) {
					do_endings(first_p, curr_p,
								endlabel, NO);
				}

				first_p = curr_p;
				endlabel = curr_p->u.bar_p->endinglabel;

				break;

			case INITEM:
				break;

			default:
				pfatal("bad endingloc value");
				/*NOTREACHED*/
				break;
			}
			last_bar_p = curr_p;
		}
	}

	/* we must be at the end of the score. If we are in the middle
	 * of an ending, draw this score's portion of it now */
	if ( (first_p != (struct MAINLL *) 0)
				&& (last_bar_p != (struct MAINLL *) 0)) {
		do_endings(first_p, last_bar_p, endlabel,
				last_bar_p->u.bar_p->endingloc
				== INITEM ? YES : NO);
	}
}


/* now that we have identified an ending, print it above each
 * staff that is supposed to get endings */

static void
do_endings(first_p, last_p, endlabel, carryout)

struct MAINLL *first_p;	/* where to begin drawing endings */
struct MAINLL *last_p;	/* where to end the endings */
char *endlabel;		/* if ending has a label, this will be
			 * that label, otherwise NULL */
int carryout;		/* YES if will carry over to next staff */

{
	struct MARKCOORD *markc_p;	/* info about where to draw ending */


	/* for each staff that is supposed to have endings,
	 * draw the ending */
	if (first_p->str == S_CLEFSIG) {
		/* pseudo-bar */
		markc_p = first_p->u.clefsig_p->bar_p->ending_p;
	}
	else {
		/* normal bar */
		markc_p = first_p->u.bar_p->ending_p;
	}

	/* if this is an endending and the bar line at the end is an ordinary
	 * bar or an invisbar, then set the carryout flag so that the final
	 * vertical line doesn't get drawn. */
	if (last_p->u.bar_p->endingloc == ENDITEM
				&& (last_p->u.bar_p->bartype == SINGLEBAR ||
				last_p->u.bar_p->bartype == INVISBAR)) {
		/* But if this is the very end of the piece,
		 * then we *do* want to draw the final vertical */
		struct MAINLL* mll_p;
		for (mll_p = last_p->next; mll_p != 0; mll_p = mll_p->next) {
			if (mll_p->str == S_STAFF) {
				break;
			}
		}
		if (mll_p != 0) {
			carryout = YES;
		}
	}

	/* draw an ending for each item in MARKCOORD list */
	for (   ; markc_p != (struct MARKCOORD *) 0; markc_p = markc_p->next) {
		draw_ending(markc_p->staffno, (double) markc_p->ry,
					first_p, last_p, endlabel, carryout);
	}
}


/* draw ending marks over specified staff */

static void
draw_ending(staffno, ry, first_p, last_p, endlabel, carryout)

int staffno;		/* which staff to draw over */
double ry;		/* relative y */
struct MAINLL *first_p;	/* draw ending starting from here */
struct MAINLL *last_p;	/* ending end here */
char *endlabel;		/* if has label, this is the label, else is NULL */
int carryout;		/* if YES, will carry over to next score */

{
	float begin_x;		/* x coord of beginning and end of ending */
	float y;		/* vertical location of ending */


	/* first_p can point to either a CLEFSIG (if carrying over an
	 * ending) or to a BAR. Find appropriate x coordinate */
	switch (first_p->str) {

	case S_CLEFSIG:
		begin_x = first_p->u.clefsig_p->bar_p->c[AX];
		break;

	case S_BAR:
		begin_x = first_p->u.bar_p->c[AX];
		break;

	default:
		/* shut up compilers that erroneously thinks begin_x
		 * could get used without being set. */
		begin_x = 0.0;
		pfatal("bad struct type passed to draw_ending");
		/*NOTREACHED*/
		break;
	}

	/* get vertical position */
	y = Staffs_y[staffno] + ry;

	/* now we know where to put it, so draw it */
	do_linetype(L_NORMAL);

	/* print the beginning vertical and label now if appropriate */
	if (endlabel != (char *) 0) {
		pr_endlabel( (double) begin_x, (double) y, endlabel);
	}

	pr_end_line ( (double) begin_x, (double) last_p->u.bar_p->c[AX],
						(double) y, carryout);
}


/* print label at the beginning of an ending, along with the vertical line
 * to the left of the label */

static void
pr_endlabel(x, y, label)

double x;	/* coordinate of beginning of ending */
double y;
char *label;	/* the ending label or NULL */

{
	/* if there is a label, this is the beginning of an ending, so
	 * print a vertical line followed by the label */
	if (label != (char *) 0) {
		x += (2.0 * STDPAD);
		draw_line(x, y + STDPAD, x, y + ENDINGHEIGHT - STDPAD);
		pr_string(x + (3.0 * STDPAD), y + (2.0 * STDPAD), label, J_LEFT,
					(char *) 0, -1);
	}
}


/* print horizontal line above ending, possibly with ending vertical line */

static void
pr_end_line(begin_x, end_x, y, carryout)

double begin_x;	/* horizontal coordinates of ending line */
double end_x;
double y;	/* vertical position */
int carryout;	/* if YES, continued on next score, so no end vertical */

{
	/* adjust to allow a little padding */
	begin_x += (2.0 * STDPAD);
	end_x -= (2.0 * STDPAD);
	y += ENDINGHEIGHT - STDPAD;

	/* draw the horizontal line above the ending */
	draw_line(begin_x, y, end_x, y);

	/* if the ending ends here, draw vertical line at end */
	if (carryout == NO) {
		draw_line(end_x, y, end_x, y - ENDINGHEIGHT + (2.0 * STDPAD));
	}
}


/* function to tell whether a given staff should have ending put on it. Returns
 * YES if it does, NO if it doesn't */

int
has_ending(staffno)

int staffno;		/* which staff to check */

{
	register int s;		/* index through barstlist */


	/* if staff is invisible, ending doesn't count */
	if ( svpath(staffno, VISIBLE)->visible == NO) {
		return(NO);
	}
 
	switch ( Score.endingstyle ) {

	case ENDING_TOP:
		/* if there is an earlier staff that is visible, then no
		 * ending on this one. Otherwise there is */
		return( is_top_visible_in_range(staffno, 1) );

	case ENDING_BARRED:
		/* go through barstlist. If this
		 * staff is within a range and any staffs above it are
		 * invisible at the moment, it gets an ending. */
		for (s = 0; s < Score.nbarst;  s++) {

			if ((staffno >= Score.barstlist[s].top) && (staffno
						<= Score.barstlist[s].bottom)) {

				return( is_top_visible_in_range(staffno,
						Score.barstlist[s].top));
			}
		}

		/* if wasn't in any of the ranges, then it must be barred
		 * by itself */
		return(YES);

	case ENDING_GROUPED:
		/* go through brace and bracket list. If the top visible
		 * of any of them match the given score, it gets an ending */
		for (s = 0; s < Score.nbrace; s++) {

			if ((staffno >= Score.bracelist[s].topstaff)
					&& (staffno
					<= Score.bracelist[s].botstaff)) {

				return( is_top_visible_in_range(staffno,
					Score.bracelist[s].topstaff));
			}
		}

		for (s = 0; s < Score.nbrack; s++) {

			if ((staffno >= Score.bracklist[s].topstaff)
					&& (staffno
					<= Score.bracklist[s].botstaff)) {

				return( is_top_visible_in_range(staffno,
					Score.bracklist[s].topstaff));
			}
		}

		/* wasn't in either list, so it probably shouldn't have an
		 * ending. However, if it happens to be the top staff, we
		 * better put one on anyway, because the top staff should
		 * always get an ending. */
		return( is_top_visible_in_range(staffno, 1) );

	default:
		pfatal("unknown endingstyle");
	}
	/*NOTREACHED*/
	return(NO);
}


/* given a staff number and the top of a range of staffs, return YES if the
 * given staff is the top visible staff in the range, otherwise return NO.
 * Assume that staffno itself is for a visible staff */

int
is_top_visible_in_range(staffno, top)

int staffno;	/* which staff to check */
int top;	/* top of range to check */

{
	for (staffno--; staffno >= top; staffno--) {
		if ( svpath(staffno, VISIBLE)->visible == YES) {
			/* something above it is visible */
			return(NO);
		}
	}
	return(YES);
}


/* functions for printing piano pedals marks */

/* keep track of where last coordinate of pedal mark was for each staff.
 * If no pedal currently on a staff, set to 0.0 */
static float Last_ped_x[MAXSTAFFS + 1];
static float Last_ped_y[MAXSTAFFS + 1];


/* return the distance to offset the 'P' of "Ped." from the group X to
 * center it on the group. The first time called, calculate the width,
 * after that, just return it */

double
ped_offset()

{
	static double width = 0.0;
	char pstr[4];

	if (width == 0.0) {
		/* first time, make string with just P and get width of that */
		(void) strncpy(pstr, Ped_start, 3);
		pstr[3] = '\0';
		width = strwidth(pstr) / 2.0;
	}
	return(width);
}


/* when we encounter a ST_PEDAL, print the pedal character and save the
 * east boundary as the last pedal x value, for later use. If is endped,
 * set this last pedal x value to 0.0 */

void
pr_ped_char(stuff_p, staffno)

struct STUFF *stuff_p;		/* pedal info */
int staffno;			/* which staff */

{
	int font;
	int size;
	char *string;
	int pedstyle;	/* P_PEDSTAR or P_ALTPEDSTAR or P_LINE */
	int pedchar;	/* pedal music character code */
	double overlap;	/* to avoid tiny gaps in pedal line due to roundoff */
	char *adj_pstart;	/* Ped_start adjusted for Staffscale */
	char *adj_pstop;	/* Ped_stop adjusted for Staffscale */


	if (stuff_p->string == (char *) 0) {
		/* must be a pedal mark carried over from a previous
		 * score. Just need to save away the coordinate. */
		Last_ped_x[staffno] = stuff_p->c[AX];
		Last_ped_y[staffno] = stuff_p->c[AY];
		return;
	}

	pedstyle = svpath(staffno, PEDSTYLE)->pedstyle;

	/* extract the pedal character to be printed */
	font = stuff_p->string[0];
	size = stuff_p->string[1];
	string = stuff_p->string + 2;
	pedchar = next_str_char(&string, &font, &size) & 0xff;

	/* overlap lines just slightly with pedal characters, to compensate
	 * for any rounding of the bounding box which might cause a tiny
	 * gap to appear between the line and the pedal character */
	overlap = Stdpad / 3.0;

	/* draw line from previous pedal character, if any, to this one */
	if (pedstyle == P_LINE && Last_ped_x[staffno] != 0.0) {
		if (stuff_p->c[AW] + overlap - Last_ped_x[staffno] > 0) {
			do_linetype(L_NORMAL);
			draw_line(Last_ped_x[staffno], stuff_p->c[AY],
				stuff_p->c[AW] + overlap, stuff_p->c[AY]);
		}
	}

	Last_ped_y[staffno] = stuff_p->c[AY];

	switch (pedchar) {

	case C_BEGPED:
		if (Last_ped_x[staffno] != 0.0) {
			/* This used to be a pfatal, because it should
			 * never happen. But it can happen
			 * due to user error: if user does something like
			 *	pedal ....
			 *	repeatend
			 *	....
			 *	pedal ...
			 * 	repeatend
			 * Having two repeatends without an intervening
			 * repeatstart is illegal.
			 * It has never shown up as a true pfatal in millions
			 * of test runs, so if it is ever hit,
			 * it's probably the user error case.
			 */
			ufatal("got begin pedal when already doing pedal, staff %d", staffno);
		}
		Last_ped_x[staffno] = stuff_p->c[AE] - overlap;
		break;
		
	case C_PEDAL:
		if (Last_ped_x[staffno] == 0.0) {
			pfatal("got pedal without begped, staff %d", staffno);
		}
		Last_ped_x[staffno] = stuff_p->c[AE] - overlap;
		break;

	case C_ENDPED:
		if (Last_ped_x[staffno] == 0.0) {
			pfatal("got endped without begped, staff %d", staffno);
		}
		Last_ped_x[staffno] = 0.0;
		break;
		
	default:
		pfatal("bad character 0x%x in pedal string", pedchar);
		/*NOTREACHED*/
		break;
	}

	/* now print the appropriate pedal character */
	if (pedstyle == P_LINE) {
		/* We used to print the pedal characters from FONT_MUSIC,
		 * but Ghostscript sometimes misaligned them with the
		 * pedal lines, so now we draw the characters "manually."
		 */
		do_linetype(L_NORMAL);
		switch (pedchar) {
		case C_BEGPED:
			draw_line(stuff_p->c[AX], stuff_p->c[AN],
				stuff_p->c[AX], stuff_p->c[AY]);
			draw_line(stuff_p->c[AX], stuff_p->c[AY],
				stuff_p->c[AE] + overlap, stuff_p->c[AY]);
			break;
		case C_PEDAL:
			draw_line(stuff_p->c[AW], stuff_p->c[AY],
				stuff_p->c[AX], stuff_p->c[AN]);
			draw_line(stuff_p->c[AX], stuff_p->c[AN],
				stuff_p->c[AE], stuff_p->c[AY]);
			break;
		case C_ENDPED:
			draw_line(stuff_p->c[AW] - overlap, stuff_p->c[AY],
				stuff_p->c[AX], stuff_p->c[AY]);
			draw_line(stuff_p->c[AX], stuff_p->c[AN],
				stuff_p->c[AX], stuff_p->c[AY]);
			break;

		}
			
	}
	else {
		/* If we need to adjust for Staffscale, make a temp copy */
		if (Staffscale != 1.0) {
			adj_pstart = copy_string(Ped_start + 2,
				(int) Ped_start[0],
				adj_size( (int) Ped_start[1], Staffscale,
				(char *) 0, -1));
			adj_pstop = copy_string(Ped_stop + 2,
				(int) Ped_stop[0],
				adj_size( (int) Ped_stop[1], Staffscale,
				(char *) 0, -1));
		}
		else {
			adj_pstart = Ped_start;
			adj_pstop = Ped_stop;
		}

		/* In alt pedstar style, a PEDAL is treated exactly like
		 * a BEGPED, so pretend that's what we got. */
		if (pedstyle == P_ALTPEDSTAR && pedchar == C_PEDAL) {
			pedchar = C_BEGPED;
		}

		switch (pedchar) {

		case C_BEGPED:
			pr_string(stuff_p->c[AX] - (strwidth(adj_pstart) / 2.0),
					stuff_p->c[AY], adj_pstart,
					J_CENTER, stuff_p->inputfile,
					stuff_p->inputlineno);
			break;

		case C_PEDAL:
			pr_string(stuff_p->c[AX] - strwidth(adj_pstop)
					- ped_offset() * Staffscale,
					stuff_p->c[AY], adj_pstop,
					J_RIGHT, stuff_p->inputfile,
					stuff_p->inputlineno);
			pr_string(stuff_p->c[AX] - ped_offset() * Staffscale,
					stuff_p->c[AY], adj_pstart,
					J_LEFT, stuff_p->inputfile,
					stuff_p->inputlineno);
			break;

		case C_ENDPED:
			pr_string(stuff_p->c[AX] - (strwidth(adj_pstop) / 2.0),
					stuff_p->c[AY], adj_pstop,
					J_CENTER, stuff_p->inputfile,
					stuff_p->inputlineno);
			break;

		default:
			pfatal("bad character 0x%x in pedal string", pedchar);
			/*NOTREACHED*/
			break;
		}

		/* If we had to make a temp copy to account for Staffscale,
		 * free the temp copy. */
		if (Staffscale != 1.0) {
			FREE(adj_pstart);
			FREE(adj_pstop);
		}
	}
}


/* when we hit a bar line, extend any pedal marks to the bar line. Since things
 * are stored in units of bars, easier to do this than keep track of the
 * entire length and have to worry about page feeds, etc. This is just for
 * normal bars, not pseudo-bars. They are handled separately. */

void
pr_ped_bar(mll_p, bar_p)

struct MAINLL *mll_p;	/* print pedal mark up to bar hangs off of here */
struct BAR *bar_p;	/* print pedal marks up to this bar */

{
	register int s;
	float endadj;		/* adjustment for endings */


	/* for each staff that has pedal marks pending, draw an extension
	 * line to where this bar line is and reset Last_ped_x */
	for (s = 1; s <= Score.staffs; s++) {

		if (Last_ped_x[s] != 0.0) {

			if (Last_ped_y[s] <= 0.0) {
				pfatal("don't have y coordinate for drawing pedal mark");
			}

			endadj = 0.0;
			if (svpath(s, PEDSTYLE)->pedstyle == P_LINE) {
				do_linetype(L_NORMAL);
				if (Ped_snapshot[0] == YES &&
						bar_p->endingloc == STARTITEM) {

					/* going into 2nd ending, so shorten
					 * this pedal to not reach bar */
					endadj = (2.0 * STEPSIZE);
					/* if line length is positive,	
					 * draw it */
					if (bar_p->c[AX] - endadj
							> Last_ped_x[s]) {

						draw_line(Last_ped_x[s],
							Last_ped_y[s],
							bar_p->c[AX] - endadj,
							Last_ped_y[s]);
					}
				}
				else {
					if (bar_p->c[AX] - STDPAD >
							Last_ped_x[s]) {
						draw_line(Last_ped_x[s],
								Last_ped_y[s],
								bar_p->c[AX]
								- STDPAD,
								Last_ped_y[s]);
						endadj = -STDPAD;
					}
					else {
						endadj = -(bar_p->c[AX]
							- Last_ped_x[s]);
					}
				}
			}

			Last_ped_x[s] = bar_p->c[AX] + endadj;
		}
	}
	saveped(mll_p, bar_p);
}


/* handle pedal going into endings. When we hit a first ending, save the
 * state of the pedal for all staffs. On subsequent endings in the set,
 * reset the pedal state to what it was at the beginning of the first ending.
 * At the endending, go back to normal operation. */

void
saveped(mll_p, bar_p)

struct MAINLL *mll_p;	/* bar is connected here */
struct BAR *bar_p;

{
	register int s;		/* staff index */


	if (mll_p == (struct MAINLL *) 0) {
		pfatal("null pointer in saveped");
	}

	if (bar_p->endingloc == STARTITEM) {

		if (Ped_snapshot[0] == YES) {

			/* starting 2nd ending: restore pedal state as it was
			 * at beginning of first ending */
			for (s = 1; s <= Score.staffs; s++) {
				if (Ped_snapshot[s] == YES) {
					Last_ped_x[s] = bar_p->c[AX]
							+ (2.0 * STEPSIZE);
				}
				else {
					Last_ped_x[s] = 0.0;
				}
			}
		}

		else {
			/* starting a set of endings,
			 * need to save pedal state at this
			 * point so we can carry it into subsequent endings */
			for (s = 1; s <= Score.staffs; s++) {
				/* set to YES if pedal is on */
				Ped_snapshot[s] = (Last_ped_x[s] == 0.0 ? NO : YES);
			}
			/* make sure any remaining staffs are set to pedal off,
			 * in case user increases the number of staffs
			 * during the endings... */
			for (   ; s <= MAXSTAFFS; s++) {
				Ped_snapshot[s] = NO;
			}

			/* mark that we now have a snapshot */
			Ped_snapshot[0] = YES;
		}
	}

	else if (bar_p->endingloc == ENDITEM) {
		/* at end of endings, discard snapshot of pedal states.
		 * However, we have to make sure this is really the end of
		 * endings, and not just a bar that was marked as end
		 * because the start of the next was moved from here to
		 * the pseudo bar. So we search forward, if we find a
		 * clefsig with pseudo-bar before finding a chhead,
		 * and that pseudo bar endingloc is STARTITEM, then this
		 * isn't really the end of endings, and should be ignored. */
		for (   ; mll_p != (struct MAINLL *) 0; mll_p = mll_p->next) {
			if (mll_p->str == S_CHHEAD) {
				/* is end of endings */
				break;
			}
			else if (mll_p->str == S_CLEFSIG &&
					mll_p->u.clefsig_p->bar_p !=
					(struct BAR *) 0 &&
					mll_p->u.clefsig_p->bar_p->endingloc
					== STARTITEM) {
				/* not really end of endings */
				return;
			}
		}
		Ped_snapshot[0] = NO;
	}
}


/* given a list of phrase mark curve coordinates, print the curve */
/* output each x,y, coordinate pair, then the number of coordinates and
 * finally the "curve" function name */

void
pr_phrase(crvlist_p, linetype, tapered, staffno)

struct CRVLIST *crvlist_p;	/* the curve to print */
int linetype;			/* if not tapered, may be L_DOTTED or L_DASHED*/
int tapered;			/* YES or NO */
int staffno;			/* which staff, to get staffscale */

{
	int n;
	struct CRVLIST *c_p;
	float *xlist,* ylist;

	/* count up number of coordinates */
	for (n = 0, c_p = crvlist_p; c_p != (struct CRVLIST *) 0;
					c_p = c_p->next) {
		n++;
	}

	MALLOCA(float, xlist, n);
	MALLOCA(float, ylist, n);
	for (n = 0, c_p = crvlist_p; c_p != (struct CRVLIST *) 0;
					c_p = c_p->next, n++) {
		xlist[n] = c_p->x;
		ylist[n] = c_p->y;
	}
	if (tapered == NO) {
		do_linetype(linetype);
	}
	pr_allcurve(xlist, ylist, n,
		svpath(staffno, STAFFSCALE)->staffscale * W_MEDIUM / PPI,
		tapered);
	FREE(xlist);
	FREE(ylist);
}

/*
 * Name:        pr_allcurve()
 *
 * Abstract:    Print a curve, either generated (e.g., tie) or user-defined.
 *
 * Returns:     void
 *
 * Description: This function is given an array of CURVEINFOs, one for each
 *		point of a curve, where x and y have been filled in.  It fills
 *		the rest of the items in the structures, and prints PostScript
 *		commands for drawing the curve.  If the curve is to be dashed
 *		or dotted, the calling function must put out the PostScript
 *		commands for that.  It does not handle "wavy".
 */


void
pr_allcurve(x, y, num, cwid, tapered)

float x[], y[];		/* coordinates of the curve's points */
int num;		/* number of elements (points) in the array */
double cwid;		/* (max) width of the curve, in inches */
int tapered;		/* YES or NO */

{
	struct CURVEINFO *v;	/* malloc structs for holding point info */
	float *slen;		/* malloc length of each segment */
	float *xoff;		/* malloc x offset of curve boundary from mid*/
	float *yoff;		/* malloc y offset of curve boundary from mid*/
	float *off;		/* malloc total offset of curve boundary */
	float totlen;		/* len of curve, along segments */
	float maxplace;		/* distance from end where a tapered curve */
				/* reaches its maximum thickness */
	float cumlen, remlen, fromend;	/* used in tapering curve */
	float dx, dy;		/* for finding x and y offsets */
	float temp;		/* temp variable */
	int n;			/* loop through points */


	/*
	 * If the curve is not to be tapered, calculate Bezier curves joining
	 * these points, and stroke the resulting path.
	 */
	if (tapered == NO) {
		/* load coords into structures, and calculate control points */
		MALLOC(CURVEINFO, v, num);
		for (n = 0; n < num; n++) {
			v[n].x = x[n];
			v[n].y = y[n];
		}
		calccurve(v, num);

		/* output results in PostScript */
		do_moveto(v[0].x, v[0].y);

		for (n = 0; n < num - 1; n++) {
			do_curveto( v[n].x1, v[n].y1, v[n].x2, v[n].y2,
					v[n+1].x, v[n+1].y);
		}
		do_stroke();

		FREE(v);
		return;
	}

	/*
	 * The curve is to be tapered.  We're going to draw two series of
	 * Bezier curves, forming the boundaries of the whole curve, and then
	 * fill.  Note that this will always result in a solid curve,
	 * regardless of any earlier request for dashes or dots.
	 */
	/* first allocate the arrays we're going to need */
	MALLOC(CURVEINFO, v, num);
	MALLOCA(float, slen, num);
	MALLOCA(float, xoff, num);
	MALLOCA(float, yoff, num);
	MALLOCA(float, off, num);

	/* find and save len of each segment, and accumulate total len */
	totlen = 0;
	for (n = 0; n < num - 1; n++) {
		slen[n] = sqrt( (double) (SQUARED(x[n+1] - x[n]) +
				SQUARED(y[n+1] - y[n]) ) );
		totlen += slen[n];
	}

	/*
	 * Tapering occurs up to a max of 1/3 inches from the end of a curve.
	 * maxplace is set up such that it is normally the distance from the
	 * end where the max thickness is attained.  However, if a curve is
	 * shorter than 2/3 inches, it will never attain this max thickness.
	 */
	if (totlen > 0.5) {
		maxplace = 1.0/3.0;
	} else {
		maxplace = totlen * (2.0/3.0);
	}

	cumlen = 0.0;		/* none accumulated so far */
	remlen = totlen;	/* all of it remains */
	for (n = 0; n < num; n++) {
		/* whichever end this point is closer to, note distance */
		if (cumlen < remlen) {
			fromend = cumlen;
		}
		else {
			fromend = remlen;
		}

		/* set the offset for this point for achieving tapering */
		if (fromend > maxplace) {
			off[n] = cwid / 2.0;
		} else {
			float taperwid;
			/*
			 * For curves longer than 2/3, taperwid should be only
			 * half of TAPERWID; for zero length curves, it should
			 * be full TAPERWID; in between, adjust linearly.  Then,
			 * at the ends, the width is taperwid times the full
			 * standard thickness (the middle of a long curve); and
			 * ramp up linearly towards 1/3 inches from the end.
			 */
			taperwid = totlen > 2.0/3.0 ? TAPERWID / 2.0 :
					TAPERWID * (1.0 - 0.75 * totlen);
			off[n] = (cwid / 2.0) *
			((1.0 - taperwid) * fromend / maxplace + taperwid);
		}

		/*
		 * Break offset into x and y components, based on the slope
		 * between the two surrounding points.  For the endpoints,
		 * there are not two surrounding points, so use the slope of
		 * the neighboring segment.
		 */
		/*
		 * First get deltas; x and y are switched and sign reversed
		 * on one, because we're concerned with the line perpendicular
		 * to the line joining the two points.  (Its slope is the
		 * negative inverse.)  Only the ratio dx/dy matters, not the
		 * values.
		 */
		if (n == 0) {
			dx = y[1] - y[0];
			dy = x[0] - x[1];
		} else if (n == num - 1) {
			dx = y[num-1] - y[num-2];
			dy = x[num-2] - x[num-1];
		} else {
			dx = y[n+1] - y[n-1];
			dy = x[n-1] - x[n+1];
		}

		/* get hypotenuse of something */
		temp = off[n] / sqrt( (double) (SQUARED(dx) + SQUARED(dy)) );

		/* get x and y offsets; may need to switch signs */
		xoff[n] = fabs(temp * dx);
		yoff[n] = fabs(temp * dy);
		if (dx > 0)
			xoff[n] *= -1;
		if (dy > 0)
			yoff[n] *= -1;

		/* update cumulative and remaining length if not at end */
		if (n < num - 1) {
			cumlen += slen[n];
			remlen -= slen[n];
		}
	}

	/*
	 * Load coords into structures, and calculate control points, for one
	 * boundary of the curve.
	 */
	for (n = 0; n < num; n++) {
		v[n].x = x[n] + xoff[n];
		v[n].y = y[n] + yoff[n];
	}
	calccurve(v, num);

	/*
 	 * Move to the center of the curve's thickness at the beginning point.
	 * Draw a perpendicular line to the curve's boundary.  Then generate
	 * the curves that form this side's boundary.
	 */
	do_moveto(x[0], y[0]);
	do_line(v[0].x, v[0].y);
	for (n = 0; n < num - 1; n++) {
		do_curveto( v[n].x1, v[n].y1, v[n].x2, v[n].y2,
				v[n+1].x, v[n+1].y);
	}

	/*
	 * Load coords into structures, and calculate control points, for the
	 * other boundary of the curve.  We're going to do this side in
	 * reverse, back to the beginning.
	 */
	for (n = 0; n < num; n++) {
		v[n].x = x[num - 1 - n] - xoff[num - 1 - n];
		v[n].y = y[num - 1 - n] - yoff[num - 1 - n];
	}
	calccurve(v, num);

	/*
	 * Draw a line across the curve's thickness at this end.  Then
	 * generate the curves that form this side's boundary.
	 */
	do_line( v[0].x, v[0].y);
	for (n = 0; n < num - 1; n++) {
		do_curveto( v[n].x1, v[n].y1, v[n].x2, v[n].y2,
				v[n+1].x, v[n+1].y);
	}

	/* fill to form the full, solid curve */
	do_fill();

	FREE(slen);
	FREE(xoff);
	FREE(yoff);
	FREE(off);
	FREE(v);
}

/*
 * Name:        calccurve()
 *
 * Abstract:    Calculate info for drawing cubic arcs through a curve's points.
 *
 * Returns:     void
 *
 * Description: This function is given an array of CURVEINFOs, one for each
 *		point of a curve, where x and y have been filled in.  It fills
 *		in the rest of the items in the structures.  Specifically, in
 *		each structure, (x1, y1) and (x2, y2) are the control points
 *		for drawing a Bezier curve (using curveto) from this point to
 *		the next one.  These points are chosen in such a way that the
 *		slopes at the end of one curve and the start of the next are
 *		equal, to avoid a sharp corner.  Also, the angles this slope
 *		forms with straight line segments connecting the points are
 *		equal.  The angle at the start of the first curve is set equal
 *		to the angle at the end of it, and the angle at the end of the
 *		last curve is set equal to the angle at the beginning of it.
 *		The other fields in the CURVEINFOs are set but aren't useful to
 *		the caller.  In the last point's CURVEINFO, some of the fields
 *		are not used (including x1, y1, x2, y2).
 */


static void
calccurve(v, num)

struct CURVEINFO v[];	/* array of curve points, x and y must be filled in */
int num;		/* number of elements (points) in the array */

{
	int n;				/* loop through the points */
	float temp, delx, dely;		/* temp variables */
	float slope, intercept;		/* for equation of a segment */


	/* find the length of each segment connecting neighboring points */
	for (n = 0; n < num - 1; n++) {
		/* use Pythagorean theorem; put result in 1st point's "len" */
		delx = v[n+1].x - v[n].x;
		dely = v[n+1].y - v[n].y;
		v[n].len = sqrt( (double) (SQUARED(delx) + SQUARED(dely)) );
		if (v[n].len == 0)
			ufatal("two curve points are equal");
	}

	/* find the angle at each point other than the endpoints */
	for (n = 1; n < num - 1; n++) {
		/*
		 * Use the law of cosines on the triangle formed by this point
		 * and the preceding and following points.  First get the delta
		 * from the preceding point to the following point.
		 */
		delx = v[n+1].x - v[n-1].x;
		dely = v[n+1].y - v[n-1].y;

		/*
		 * The law of cosines:  c^2  =  a^2  +  b^2  -  2 a b cos(C).
		 * Solve this for the cosine of our point's angle (angle "C").
		 */
		temp = ( SQUARED(v[n-1].len) + SQUARED(v[n].len) -
			(SQUARED(delx) + SQUARED(dely)) ) /
			( 2.0 * v[n-1].len * v[n].len );

		/* if angle is 180, should be -1, but guard against roundoff */
		if (temp < -1)
			temp = -1;	/* should have been exactly -1 */

		/* if angle is 0, this is not allowed in our curve */
		if (temp >= 1)
			ufatal("curve bends all the way back on itself");

		v[n].ang = acos(temp);
	}

	/* set the bend direction at each point other than the endpoints */
	for (n = 1; n < num - 1; n++) {
		/* handle special case where previous segment is vertical */
		if (v[n-1].x == v[n].x) {
			if (v[n-1].y < v[n].y) {
				if (v[n+1].x >= v[n].x)
					v[n].bend = 1;
				else
					v[n].bend = -1;
			} else {
				if (v[n+1].x >= v[n].x)
					v[n].bend = -1;
				else
					v[n].bend = 1;
			}
			continue;	/* go to next loop iteration */
		}

		/*
		 * Find the equation of the previous segment.  Plug the
		 * following point's x into that equation to get where its y
		 * would have been if the angle were 180.  Comparing that y to
		 * the actual y, we can determine the bend direction.
		 */
		slope = (v[n].y - v[n-1].y) / (v[n].x - v[n-1].x);
		intercept = v[n-1].y - slope * v[n-1].x;
		temp = slope * v[n+1].x + intercept;

		if (v[n].x > v[n-1].x) {
			if (v[n+1].y < temp)
				v[n].bend = 1;
			else
				v[n].bend = -1;
		} else {
			if (v[n+1].y < temp)
				v[n].bend = -1;
			else
				v[n].bend = 1;
		}
	}

	/*
	 * At the endpoints, there is only one segment, so no angle or bend
	 * direction is defined.  But we need to have something.  So we semi-
	 * arbitrarily set these to the same value as their neighboring points.
	 */
	v[0].ang = v[1].ang;
	v[0].bend = v[1].bend;
	v[num-1].ang = v[num-2].ang;
	v[num-1].bend = v[num-2].bend;

	/*
	 * For all points, set the slope of the line tangent to the curves
	 * we're going to draw, in the coordinate system where the segment
	 * starting at this point is horizontal.  (This is the coordinate
	 * system that findcontrol() uses.)  Since the angle between segments
	 * is not allowed to be 0, this slope is never vertical (infinity).
	 */
	for (n = 0; n < num; n++)
		v[n].slopetan = -v[n].bend * tan( v[n].ang / 2 + PI / 2);

	/*
	 * For each segment, calculate control points to define a Bezier curve
	 * connecting the endpoints, according to the specifications.
	 */
	for (n = 0; n < num - 1; n++)
		findcontrol(v, n);
}

/*
 * Name:        findcontrol()
 *
 * Abstract:    Find Bezier control points for one segment of the curve.
 *
 * Returns:     void
 *
 * Description: This function is given an array of CURVEINFOs, one for each
 *		point, with everything filled in except the control points.  It
 *		calculates them and fills them in.
 */


static void
findcontrol(v, n)

struct CURVEINFO v[];
int n;

{
	float costheta, sintheta;	/* for rotating axes by theta */

	/*
	 * All of the following variables refer to the rotated/translated
	 * position of the segment (see comment below).  Point 0 is the
	 * starting point, point 3 is the ending point, and points 1 and 2
	 * are the Bezier control points.
	 */
	float x1, x2, y1, y2;	/* control points */
	float x3;		/* end point (y3 is always 0) */
	float slope0, slope3;	/* slope of tangent lines at endpoints */
	float b, c;		/* some coefficients of cubic y = f(x) */
	float cx, by, cy;	/* Bezier coefficients */


	/*
	 * Rotate and translate the axes so that the starting point (point 0)
	 * is at the origin, and the ending point (3) is on the positive
	 * x axis.  Their coords are (0, 0) and (v[n].len, 0).  We are going
	 * to find a cubic equation that intersects the endpoints, and has the
	 * necessary slope at those points such that the tangent line's slope
	 * is halfway between horizontal (this segment) and the slope of the
	 * neighboring segment.  The equation is
	 *	y  =  a x^3  +  b x^2  +  c x  +  d
	 * so the slope is
	 *	y' =  3 a x^2  +  2 b x  +  c
	 * By plugging the two points into these, you get 4 equations in the 4
	 * unknowns a, b, c, d.
	 */
	x3 = v[n].len;

	/* find the slope of the tangent lines at the first & second points */
	slope0 = v[n].slopetan;
	slope3 = -v[n+1].slopetan;

	/* set values of a, b, c (d turns out to be always 0) */
	/* a = (slope0 + slope3) / SQUARED(x3);	don't really need this one */
	b = (-2 * slope0 - slope3) / x3;
	c = slope0;

	/*
	 * For Bezier version of this, let x = t / x3, and for y, plug this
	 * into the cubic we have found.  This gives us the Bezier coeff.:
	 *	x = ax t^3  +  bx t^2  +  cx t  +  x0
	 *	y = ay t^3  +  by t^2  +  cy t  +  y0
	 */
	/* ax and bx are always 0 */
	cx = x3;
	/* ay = a * CUBED(x3);		this one is not needed */
	by = b * SQUARED(x3);
	cy = c * x3;

	/* get control points 1 and 2 from Bezier coefficients & endpoints */
	x1 = cx / 3;
	y1 = cy / 3;
	x2 = x1 + cx / 3;
	y2 = y1 + (by + cy) / 3;

	/*
	 * Rotate and translate the axes back to where they really were.  Store
	 * these real positions of the control points.
	 */
	costheta = (v[n+1].x - v[n].x) / v[n].len;
	sintheta = (v[n+1].y - v[n].y) / v[n].len;

	v[n].x1 = v[n].x + x1 * costheta - y1 * sintheta;
	v[n].x2 = v[n].x + x2 * costheta - y2 * sintheta;
	v[n].y1 = v[n].y + y1 * costheta + x1 * sintheta;
	v[n].y2 = v[n].y + y2 * costheta + x2 * sintheta;
}


/* draw a V-shaped bend indicator by drawing two line segments */

void
pr_bend(crvlist_p)

struct CRVLIST *crvlist_p;

{
	if (crvlist_p == (struct CRVLIST *) 0
			|| crvlist_p->next == (struct CRVLIST *) 0
			|| crvlist_p->next->next == (struct CRVLIST *) 0) {
		pfatal("invalid bend crvlist");
	}

	do_linetype(L_NORMAL);
	draw_line(crvlist_p->x, crvlist_p->y, crvlist_p->next->x, crvlist_p->next->y);
	draw_line(crvlist_p->next->x, crvlist_p->next->y,
			crvlist_p->next->next->x, crvlist_p->next->next->y);
}


/* draw a slide for a tab or tabnote staff. Slides are stored internally
 * like slurs. Here we just draw a line between the appropriate coordinates */

void
pr_tabslur(crvlist_p, ts_style)

struct CRVLIST *crvlist_p;
int ts_style;

{
	if (crvlist_p == (struct CRVLIST *) 0
				|| crvlist_p->next == (struct CRVLIST *) 0) {
		pfatal("invalid tabslur crvlist");
	}

	do_linetype(ts_style);
	draw_line(crvlist_p->x, crvlist_p->y, crvlist_p->next->x, crvlist_p->next->y);
}


/* print a small curve to indicate a 1/4 step bend on a tabnote */

void
pr_sm_bend(x, y)

double x, y;	/* where to start the curve. This is the bottom left end */

{
	float xlist[4], ylist[4];	/* coordinates of the curve */


	/* fill in the relative horizontal and vertical offsets. These
	 * are hand picked to give a nice looking curve */
	xlist[0] = x;
	ylist[0] = y;
	xlist[1] = x + 0.5 * STEPSIZE;
	ylist[1] = y + 0.2 * STEPSIZE;
	xlist[2] = x + 1.2 * STEPSIZE;
	ylist[2] = y + 1.2 * STEPSIZE;
	xlist[3] = x + 1.3 * STEPSIZE;
	ylist[3] = y + 1.75 * STEPSIZE;

	/* now print the curve */
	pr_allcurve(xlist, ylist, 4, W_NORMAL, NO);
}


/* Print 'atend' grids */

void
pr_atend()

{
	float x;		/* of first grid of row */
	float y;		/* of row; top line of grid */
	float gridx;		/* x of grid being printed */
	float north;		/* of the grid */
	float space;		/* distance between grid lines */
	struct GRID *grid_p;
	int g;			/* index through grid_p array */
	int staff = -1;		/* always -1 to indicate atend. Using a
				 * variable rather than hard-coding where
				 * used just on general principles. */
	int column;		/* how many columns printed so far in row */
	int rows_to_print;	/* how many rows to print per page. */
	struct MAINLL *main_feed_p;	/* for getting top/bottom blocks */
	struct FEED *feed_p;	/* for getting top/bottom blocks */


	x = Atend_info.firstgrid_x;
	y = Atend_info.firstgrid_y;
	rows_to_print = Atend_info.rows_per_page;
	space = gridspace(staff);
	column = 0;

	/* Find the last FEED. We use that to get top/bottom blocks */
	for (main_feed_p = Mainlltc_p; main_feed_p->str != S_FEED;
					main_feed_p= main_feed_p->prev) {
		;
	}
	feed_p = main_feed_p->u.feed_p;
	for (g = 0; g < Atend_info.grids_used; g++) {
		grid_p = Atend_info.grid_p[g];
		gridsize(grid_p, staff, &north, (float *) 0, (float *) 0, (float *) 0);
		/* calculate horizontal position of this grid */
		gridx = x + column * Atend_info.horz_sep;

		/* print the name of the grid */
		pr_string(gridx - strwidth(grid_p->name) / 2.0,
				y + north + strdescent(grid_p->name),
				grid_p->name, J_LEFT, (char *) 0, -1);

		/* print the grid itself */
		do_grid(gridx - space * (grid_p->numstr - 1) / 2.0,
					y, space, grid_p, staff, DEFHORZSCALE);

		if (++column >= Atend_info.grids_per_row &&
				g < Atend_info.grids_used - 1) {
			/* move to next row */
			column = 0;
			y -= Atend_info.vert_sep;
			rows_to_print--;
			if (Atend_info.separate_page == YES &&
						rows_to_print <= 0) {
				rows_to_print = Atend_info.rows_per_page;
				y = Atend_info.firstgrid_y;
				/* print top/bottom blocks, if any */
				/* use *2 blocks for any subsequent pages */
				feed_p->top_p = feed_p->top2_p;
				feed_p->bot_p = feed_p->bot2_p;
				pr_feed(main_feed_p);
			}
		}
	}
}


/* After outputting standard part of prolog, if the user defined any
 * symbols, we need to output the PostScript for them.
 * User-defined symbol fonts are defined
 * in a fairly similar manner to the native Mup music fonts.
 */

void
user_symbols(mfont, ufont_p)

int mfont;			/* Which font to write PostScript about,
				 * relative to FONT_MUSIC */
struct USERFONT *ufont_p;	/* The information describing the font */

{
	int i;		/* index through symbols */
	int llx, lly;	/* font-wide bounding box, lower left */
	int urx, ury;	/* font-wide bounding box, upper right */


	if (ufont_p->num_symbols == 0) {
		/* User did not define any symbols in this font */
		return;
	}

	/* Calculate the font-wide bounding box. */
	font_bbox(mfont, ufont_p, &llx, &lly, &urx, &ury);

	/* Output PostScript code for setting up the font as a whole. */
	/* Create font dictionary and fill in required entries */
	printf("\n%% Create font of user defined symbols\n\n");

	/* Declare a procedure for each user defined symbol, to print it.
	 * In the native Mup fonts, we do this last, after defining the
	 * PostScript for them, but here we do them first.
	 * Overriding the Mup native fonts requires this order, because
	 * we have to generate PostScript code to look the Encoding
	 * at runtime, because we don't know the mapping.
	 * We do happen to know the mapping here, but by using the same
	 * order, we can use a common function.
	 */
	for (i = 0; i < ufont_p->num_symbols; i++) {
	 	/*  Figuring out what to backslash can get a little messy,
		 * so just use the octal version, which will always work. */
		printf("/UDS_%s { (\\%03o) printuchar%d } def\n",
			ufont_p->symbols[i].name, i + FIRST_CHAR, mfont);
	}

	/* Now define the font */
	printf("/mfont%d 100 dict def\nmfont%d begin\n", mfont, mfont);
	printf("\t/FontType 3 def\n\t/FontMatrix [ .001 0 0 0.001 0 0 ] def\n");
        printf("\t/FontBBox [ %d %d %d %d ] def\n", llx, lly, urx, ury);
        printf("\t/FontName (Mfont%d) def\n", mfont);

	/* Set Encoding array */
	printf("\t/Encoding StandardEncoding length array def\n\tStandardEncoding Encoding copy\n\tpop\n");

	/* populate CharStrings dictionary with sym drawing code */
	printf("\t/CharStrings StandardEncoding length dict def\n");
	/* temporarily redefine printing procedure to get the Encoding value */
	printf("\t5 dict begin\n\t/printuchar%d { {} forall } def\n", mfont);
	printf("\tCharStrings begin\n\t\t/.notdef {} def\n");

	/* For each symbol the user defined, output their PostScript code */
	for (i = 0; i < ufont_p->num_symbols; i++) {
		pr_usym_ps(ufont_p, mfont, i);
	}
	/* End  the temporary print dictionary and the CharStrings dictionary */
	printf("\tend\nend\n");

	/* Define the procedure for drawing symbols */
	printf("\t/BuildChar {\n\t\texch begin\n\t\tEncoding exch get\n\t\tdup\n");
	printf("\t\tUfbbox%d exch get\n\t\taload pop setcachedevice\n", mfont);
	printf("\t\tCharStrings exch get\n\t\texec\n\t\tend\n\t} def\nend\n\n");

	/* Define generic procedure for drawing a symbol */
	printf("/printuchar%d {\n", mfont);
	printf("\tgsave\n\t/userchar exch def\n");
	printf("\t/Mfont%d findfont exch 10 mul scalefont setfont moveto\n", mfont);
        printf("\tuserchar show\n\tgrestore\n} def\n");

	/* Make bounding box dictionary */
	printf("mfont%d begin\n\tmfont%d /Ufbbox%d Encoding length dict put\n",
					mfont, mfont, mfont);
	printf("\t5 dict begin\n\t/printuchar%d { {} forall } def\n", mfont);
	for (i = 0; i < ufont_p->num_symbols; i++) {
		pr_bbox("Ufbbox", mfont, ufont_p, i);
	}
	/* end bounding box dictionary and font dictionary */
	printf("\tend\nend\n");
	printf("/Mfont%d mfont%d definefont\n", mfont, mfont);
}


/* If user overrode any builtin music symbols, generate PostScript to
 * override the dictionary entries */

void
user_overrides(mfont, ufont_p)

int mfont;			/* Which font to write PostScript about,
				 * relative to FONT_MUSIC */
struct USERFONT *ufont_p;	/* The information describing the font */

{
	int i;		/* index through font */
	int llx, lly;	/* lower left bounding box */
	int urx, ury;	/* upper right bounding box */
	int findex;	/* into Fontinfo array */

	if (ufont_p->num_symbols == 0) {
		/* User did not override any symbols in this font */
		return;
	}

	/* open font dictionary */
	printf("mfont%d begin\n", mfont);

	/* Generate code to update font-wide bounding box if necessary */
	font_bbox(mfont, ufont_p, &llx, &lly, &urx, &ury);
	printf("%d FontBBox 0 get lt { FontBBox 0 %d put } if\n", llx, llx);
	printf("%d FontBBox 1 get lt { FontBBox 1 %d put } if\n", lly, lly);
	printf("%d FontBBox 2 get gt { FontBBox 2 %d put } if\n", urx, urx);
	printf("%d FontBBox 3 get gt { FontBBox 3 %d put } if\n", ury, ury);

	/*  temporarily override print routine to get encoding value */
	printf("5 dict begin\n\t/printmchar%d { {} forall } def\n", mfont);

	/* replace symbol drawing routines for the overrides */
	printf("CharStrings begin\n");
	findex = font_index(mfont + FONT_MUSIC);
	for (i = 0; i < Fontinfo[findex].numchars; i++) {
		if (ufont_p->symbols[i].postscript != 0) {
			pr_usym_ps(ufont_p, mfont, i);
		}
	}
	printf("end\n");

	/* replace per-symbol bounding box info */
	for (i = 0; i < Fontinfo[findex].numchars; i++) {
		if (ufont_p->symbols[i].postscript != 0) {
			pr_bbox("Mcbbox", mfont, ufont_p, i);
		}
	}
	printf("end\n");
	printf("end\n");
}


/* Calculate the font-wide bounding box. First assume the
 * bbox corners are way off in the opposite direction of where
 * they should be, then find the actual values.
 */

static void
font_bbox(mfont, ufont_p, llx_p, lly_p, urx_p, ury_p)

int mfont;			/* relative to FONT_MUSIC */
struct USERFONT *ufont_p;	/* Calculate for this font */
int *llx_p, *lly_p;		/* return lower left here */
int *urx_p, *ury_p;		/* return upper right here */

{
	int i;		/* index through the font */
	int findex;	/* into Fontinfo */

	*llx_p = *lly_p = MAX_USYM_UNITS;
	*urx_p = *ury_p = -MAX_USYM_UNITS;
	findex = font_index(mfont + FONT_MUSIC);
	for (i = 0; i < Fontinfo[findex].numchars; i++) {
		if (ufont_p->symbols[i].name == 0) {
			continue;
		}
		if (ufont_p->symbols[i].llx < *llx_p) {
			*llx_p = ufont_p->symbols[i].llx;
		}
		if (ufont_p->symbols[i].lly < *lly_p) {
			*lly_p = ufont_p->symbols[i].lly;
		}
		if (ufont_p->symbols[i].urx > *urx_p) {
			*urx_p = ufont_p->symbols[i].urx;
		}
		if (ufont_p->symbols[i].ury > *ury_p) {
			*ury_p = ufont_p->symbols[i].ury;
		}
	}
}


/* Output the user's PostScript definition of a user-defined symbol */

static void
pr_usym_ps(ufont_p, mfont, code)

struct USERFONT	*ufont_p;	/* do symbol from this font */
int mfont;			/* font number offset from FONT_MUSIC */
int code;			/* do this code in the font */

{
	printf("\t\t%% %s\n", ufont_p->symbols[code].name);
	if (mfont < NUM_MFONTS) {
		/* We don't know the mapping between the muschar.h values
		 * and what is used in the prolog,
		 * so we generate PostScript code to
		 * look up the mapping in Encoding at PostScript runtime. */
		printf("\t\tEncoding %s%s get cvlit {\n",
			sym_prefix(mfont), ufont_p->symbols[code].name);
	}
	else {
		/* Put the symbol name in the proper slot of Encoding vector */
		printf("\t\tEncoding %d /%s%s put\n", code + FIRST_CHAR,
			sym_prefix(mfont), ufont_p->symbols[code].name);
		/* Output the PostScript definition of the character */
		printf("\t\t/%s%s {\n", sym_prefix(mfont),
						ufont_p->symbols[code].name);
	}
	/* Note that user has to supply proper PostScript escapes.
	 * The +2 is to skip the font/size we prepend on strings. */
	printf("\t\t%s\n\t\t} def\n", ufont_p->symbols[code].postscript + 2);
}


/* Output the bounding box dictionary entry for a user-defined symbol */

static void
pr_bbox(name, mfont, ufont_p, code)

char *name;			/* name of bounding box dictionary to update */
int mfont;			/* font number relative to FONT_MUSIC */
struct USERFONT *ufont_p;	/* do symbol from this font */
int code;			/* which symbol in the font */

{
	printf("\t%s%d Encoding %s%s get [ %d 0 %d %d %d %d ] put\n",
		name, mfont, sym_prefix(mfont),
		ufont_p->symbols[code].name,
		ufont_p->symbols[code].urx - ufont_p->symbols[code].llx,
		ufont_p->symbols[code].llx, ufont_p->symbols[code].lly,
		ufont_p->symbols[code].urx, ufont_p->symbols[code].ury);
}


/* To avoid possibility of user symbol name colliding with something,
 * return a prefix to use when naming user defined symbol;
 * no prefix for other.
 */

static char *
sym_prefix(mfont)

int mfont;		/* offset relative to FONT_MUSIC */

{
	if (mfont >= FONT_USERDEF1 - FONT_MUSIC) {
		return("UDS_");
	}
	else {
		return("");
	}
}
