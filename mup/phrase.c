
/* Copyright (c) 1995, 1996, 1997, 1998, 1999, 2001, 2002, 2005, 2006, 2008,
 * 2009, 2010, 2011 by Arkkra Enterprises */
/* All rights reserved */

/* functions to determine the curves that make up phrase marks,
 * ties and slurs. */

#include "defines.h"
#include "structs.h"
#include "globals.h"

/* distance to the top/bottom of a V-shape (indicating a bend) relative to
 * the line connecting the endpoints of the V */
#define V_HEIGHT (2.7 * Stepsize)

/* How much bulge to allow in curves. There are three slightly different
 * approaches that are tried, each succeeding approach allows more bulge
 * in a more desperate attempt to get a reasonable curve. */
#define MINBULGE	(1.3)
#define MAXBULGE	(2.4)
#define MIN2BULGE	(2.4)
#define MAX2INITIALBULGE (3.2)
#define MAX2FINALBULGE	(5.4)

/* We'd normally want curves to begin and end (in the x direction) exactly in
 * the middle of their note. But if one curve ends and another begins on
 * the same note, the curve endpoints would collide, which could look bad.
 * So we always offset the endpoints by a tiny amount (ends end a little
 * west of center, and beginnings begin a little east) so they don't touch.
 * This is the amount they are shifted from center.
 */
#define XOFFSET4CURVE	(0.75 * Stdpad)

/* Curves must be at least this far away from notes */
#define CLEARANCE	(3.0 * Stdpad)

/* try_bulge() is called lots of times in a row with mostly the same values,
 * and it needs lots of values, so it is convenient to put them in a struct,
 * and just pass a pointer to it */
struct TRYBULGE {
	struct MAINLL *mll_p;		/* STUFF hangs off here */
	struct GRPSYL *begin_gs_p;	/* group at left end of curve */
	struct GRPSYL *end_gs_p;	/* group at right end of curve */
	int place;			/* PL_*  */
	struct CRVLIST *curvelist_p;	/* points to beginning of curve */
	struct CRVLIST *endlist_p;	/* points to end of curve */
	double xlen;			/* distance to midpoint */
	double ylen;			/* how much bulge to add */
	double sintheta;		/* for rotation from horizontal */
	double costheta;
	double minbulge;		/* first bulge factor to try */
	double maxbulge;		/* last bulge to try before giving up */
};

static int nowhere_slide P((struct STUFF *stuff_p));
static void do_nowhere P((struct STUFF *stuff_p, double x1, double y1,
		double x2, double y2));
static void curve_points P((struct MAINLL *mll_p, struct STUFF *stuff_p,
		int is_phrase));
static double inner_adj P((struct GRPSYL *gs_p, struct NOTE *note_p,
		double y_adj, int place));
static double stick_out P((struct TRYBULGE *info_p));
static double try_bulge P((struct TRYBULGE *info_p));
static double tieslurx P((struct GRPSYL *gs_p, struct NOTE *note_p, int place));
static struct MAINLL *next_staff P((int staff, struct MAINLL *mll_p));
static void redo_steep P((struct CRVLIST *first_p, struct CRVLIST *last_p,
		int place));
static void final_touches P((struct MAINLL *mll_p, struct GRPSYL *begin_gs_p,
		struct GRPSYL *end_gs_p, struct CRVLIST *crvlist_p, int place));
static double eff_tupext P((struct GRPSYL * gs_p, struct STAFF *staff_p, int side));
static int bulge_direction P((struct MAINLL *mll_p, struct GRPSYL *gs1_p,
		int note_index, int curveno));


/* figure out what points are needed for a phrase mark */
/* attach a linked list of x,y coordinates that show where to draw the curve.
 * The curve will be out of the way of any groups within the phrase. */

void
phrase_points(mll_p, stuff_p)

struct MAINLL *mll_p;		/* MAINLL that stuff_p hangs off of */
struct STUFF *stuff_p;		/* info about the phrase mark */

{
	curve_points(mll_p, stuff_p, YES);
}


/* figure out what points are needed for a tie or slur mark */

void
tieslur_points(mll_p, stuff_p)

struct MAINLL *mll_p;		/* MAINLL that stuff_p hangs off of */
struct STUFF *stuff_p;		/* info about the phrase mark */

{
	/* if slide to/from nowhere in particular, do that */
	if (nowhere_slide(stuff_p) == YES) {
		return;
	}

	curve_points(mll_p, stuff_p, NO);
}


/* determine the 3 points that define a V_shaped bend indicator on the tabnote
 * staff associated with a tab staff, and put them in the stuff crvlist */

void
bend_points(mll_p, stuff_p)

struct MAINLL *mll_p;
struct STUFF *stuff_p;

{
	struct CRVLIST *first_point_p, *last_point_p;	/* the beginning
				 * and end points of the curve */
	struct CRVLIST *mid_point_p;		/* middle of the V-shape */
	struct CRVLIST *one2discard_p;		/* a point to discard */
	double midx, midy;			/* midpoint between the ends */
	double v_height;			/* V_HEIGHT, or less than
						 * that for narrow V's */
	double xlen;				/* to help find v_height */
	double slope;				/* of perpendicular line from
						 * (midx, midy) to the point
						 * of the V, v_height away. */


	/* first figure everything out as if it were a normal slur */
	curve_points(mll_p, stuff_p, NO);

	/* Now make into V-shaped curve.
	 * First throw away the inner points that we had found.
	 * It's a bit unfortunate to do all that work, then throw it
	 * away, but the curve_point() function that finds all the points
	 * also does lots of other good things that we want, so rather than
	 * make it more complicated than it already is by having it know
	 * about bends, we just save the things it did that help us here.
	 */
	first_point_p = stuff_p->crvlist_p;
	for (last_point_p = first_point_p->next;
			last_point_p->next != (struct CRVLIST *) 0;  ) {
		one2discard_p = last_point_p;
		last_point_p = last_point_p->next;
		FREE(one2discard_p);
	}

	/* get a midpoint struct and stitch it into the list */
	MALLOC(CRVLIST, mid_point_p, 1);
	first_point_p->next = mid_point_p;
	last_point_p->prev = mid_point_p;
	mid_point_p->prev = first_point_p;
	mid_point_p->next = last_point_p;

	/* find the midpoint of the line between the endpoints */
	midx = (last_point_p->x + first_point_p->x) / 2.0;
	midy = (last_point_p->y + first_point_p->y) / 2.0;

	/* get height. Use V_HEIGHT, except adjust for narrow V's */
	xlen = fabs(last_point_p->x - first_point_p->x);
	if (xlen < 2.0 * V_HEIGHT) {
		v_height = 0.35 * V_HEIGHT;
	}
	else if (xlen < 3.5 * V_HEIGHT) {
		v_height = 0.65 * V_HEIGHT;
	}
	else {
		v_height = V_HEIGHT;
	}

	/* if the y's of the endpoints are equal or nearly so, finding the
	 * midpoint of the V is easy: the x is midx, and the y is midy offset
	 * by v_height in the appropriate direction */
	if (fabs(last_point_p->y - first_point_p->y) < 0.001) {
		mid_point_p->x = midx;
		mid_point_p->y = midy + v_height *
				(stuff_p->place == PL_ABOVE ? 1.0 : -1.0);
		return;
	}

	/* find the slope of the perpendicular */
	slope = (first_point_p->x - last_point_p->x) /
				(last_point_p->y - first_point_p->y);

	/* we want the length of the perpendicular line from (midx, midy)
	 * to the point at the top (or bottom) of the V to be v_height.
	 * Using that line as the hypotenuse of a triangle, we know that
	 * we can find the x and y relative to (midx, midy) by using
	 * Pythagorean   x^2 + y^2 = v_height^2. Furthermore, we calculated 
	 * the slope of the line earlier, and knowing that slope = y/x,
	 * we now solve 2 equations in 2 unknowns:
	 *	x^2 + y^2 = v_height^2
	 *	slope = y / x
	 * Rearranging the first equation and substituting (slope * x) for y:
	 *	x^2 + (slope * x)^2 = v_height^2
	 * solve for x:
	 * 	(1 + slope^2) * x^2 = v_height^2
	 *	x = sqrt( v_height^2 / (1 + slope^2))
	 * Then having found x, solve the second equation for y.
	 *	y = x * slope
	 * Adjust for being relative to (midx, midy) and for bend direction
	 * and slope direction, and we are done.
	 */
	mid_point_p->x = (sqrt((v_height * v_height) / (1.0 + (slope * slope))))
			* (first_point_p->y > last_point_p->y ? 1.0 : -1.0)
			* (stuff_p->place == PL_ABOVE ? 1.0 : -1.0);
	mid_point_p->y = (slope * mid_point_p->x) + midy;
	mid_point_p->x += midx;
}


/* determine the 2 points that define a line indicating a slide for a
 * tab or tabnote staff, and put the points in the stuff crvlist */

void
tabslur_points(mll_p, stuff_p)

struct MAINLL *mll_p;
struct STUFF *stuff_p;

{
	struct CRVLIST *curvelist_p;
	struct GRPSYL *beggrp_p;
	struct GRPSYL *endgrp_p;
	struct NOTE *begnote_p;
	struct NOTE *endnote_p;
	float slant;		/* 0, 1 or -1 to show slant direction */
	int acc1, acc2;		/* effective accidentals on the 2 groups,
				 * -2 to +2 */
	int n, st;		/* index through notelist and slurtolist */


	/* if slide to/from nowhere in particular, do that */
	if (nowhere_slide(stuff_p) == YES) {
		return;
	}

	/* find the end note */
	if (stuff_p->carryin == YES) {
		/* on carryin, beggrp_p is really the ending group,
		 * and the previous group is the real beggrp_p */
		endgrp_p = stuff_p->beggrp_p;
		endnote_p = stuff_p->begnote_p;
		beggrp_p = prevgrpsyl(stuff_p->beggrp_p, &mll_p);

		/* go through all the notes in the previous group,
		 * to find the one that has a slide to the note being
		 * carried into. If there is more than one, use the first
		 * one we find. */
		for (n = 0; n < beggrp_p->nnotes; n++) {
			for (st = 0; st < beggrp_p->notelist[n].nslurto; st++) {
				if (endnote_p->letter ==
				  beggrp_p->notelist[n].slurtolist[st].letter
				  && (is_tab_staff(endgrp_p->staffno) == YES
				  || endnote_p->octave ==
				  beggrp_p->notelist[n].slurtolist[st].octave)) {
					/* found the one sliding to us */
					break;
				}
			}
			if (st < beggrp_p->notelist[n].nslurto) {
				/* found it, so need to jump out */
				break;
			}
		}
		if (n == beggrp_p->nnotes) {
			pfatal("can't find note being slid from");
		}
		begnote_p = &(beggrp_p->notelist[n]);
	}
	else {
		beggrp_p = stuff_p->beggrp_p;
		begnote_p = stuff_p->begnote_p;
		if ((endgrp_p = nextgrpsyl(stuff_p->beggrp_p, &mll_p))
						== (struct GRPSYL *) 0) {
			pfatal("failed to find next group in tabslur_points");
		}
		endnote_p = find_matching_note (endgrp_p, mll_p,
				stuff_p->begnote_p->slurtolist
				[stuff_p->curveno].letter,
				-1,
				stuff_p->begnote_p->slurtolist
				[stuff_p->curveno].octave, "slide");

		if (endnote_p == (struct NOTE *) 0) {
			pfatal("failed to find endnote in tabslur_points");
		}
	}

	if (is_tab_staff(mll_p->u.staff_p->staffno) == YES) {
		/* figure out whether to slant up or down based on whether
		 * first or second fret is higher */
		if (begnote_p->FRETNO > endnote_p->FRETNO) {
			slant = 1;
		}
		else {
			slant = -1;
		}
	}
	else {
		/* on non-tab staff, usually the line goes to the midpoint of
		 * the note head, so no need to adjust, so set slant to 0 */
		slant = 0;

		/* there are two exceptions: first, if both notes have the same
		 * letter/octave, but different accidentals, then we have to
		 * determine the slant based on the accidental. */
		if (begnote_p->letter == endnote_p->letter
				&& begnote_p->octave == endnote_p->octave) {

			/* if the accidental on the begin note is higher than
			 * the accidental on the end note, then it slants
			 * down from left to right, and vice versa. Get the
			 * effective accidental on each group,
			 * accounting for key signature, accidentals earlier
			 * in the measure, etc. */
			acc1 = eff_acc(beggrp_p, begnote_p, mll_p);
			acc2 = eff_acc(endgrp_p, endnote_p, mll_p);

			/* error if the slide is between identical notes */
			if (acc1 == acc2) {
				l_ufatal(endgrp_p->inputfile,
						endgrp_p->inputlineno,
						"can't slide to the same note");
			}
			else if (acc1 > acc2) {
				slant = 1;
			}
			else {
				slant = -1;
			}
		}

		/* second exception: if the slide is carried in, then it needs
		 * to be slanted, so figure out which way */
		if (stuff_p->carryin == YES) {
#ifdef __STDC__
			switch(notecomp( (const void *) begnote_p,
						(const void *) endnote_p)) {
#else
			switch(notecomp( (char *) begnote_p, (char *) endnote_p)) {
#endif
			case 1:
				slant = 0.5;
				break;
			case -1:
				slant = -0.5;
				break;
			default:
				/* same note, so have to use accidental as
				 * the deciding factor */
				acc1 = eff_acc(beggrp_p, begnote_p, mll_p);
				acc2 = eff_acc(endgrp_p, endnote_p, mll_p);

				/* error if the slide is
				 * between identical notes */
				if (acc1 == acc2) {
					l_ufatal(endgrp_p->inputfile,
						endgrp_p->inputlineno,
						"can't slide to the same note");
				}
				else if (acc1 > acc2) {
					slant = 0.5;
				}
				else {
					slant = -0.5;
				}
				break;
			}
		}
	}

	/* find beginning point of line */
	MALLOC(CRVLIST, curvelist_p, 1);
	curvelist_p->prev = (struct CRVLIST *) 0;
	if (stuff_p->carryin == YES) {
		/* start a bit west of the end note */
		curvelist_p->x = stuff_p->beggrp_p->c[AX] +
			notehorz(stuff_p->beggrp_p, stuff_p->begnote_p, RW)
			- 3.0 * Stepsize;
		curvelist_p->y = endnote_p->c[RY] + (slant * Stepsize);
	}
	else {
		/* start just beyond east of begin note */
		curvelist_p->x = begnote_p->c[AE] + Stdpad;
		curvelist_p->y = stuff_p->begnote_p->c[RY] + (slant * Stepsize);
	}

	/* end point of line */
	MALLOC(CRVLIST, curvelist_p->next, 1);
	curvelist_p->next->prev = curvelist_p;
	curvelist_p->next->next = (struct CRVLIST *) 0;
	if (stuff_p->carryout == YES) {
		/* extend to near end of score */
		curvelist_p->next->x = PGWIDTH - eff_rightmargin(mll_p) - Stepsize;
	}
	else  {
		/* go to just before west of end note */
		curvelist_p->next->x = endgrp_p->c[AX] +
				notehorz(endgrp_p, endnote_p, RW) - Stdpad;
	}
	curvelist_p->next->y = endnote_p->c[RY] - (slant * Stepsize);

	/* attach to stuff */
	stuff_p->crvlist_p = curvelist_p;

	/* place doesn't really make sense, so set arbitrarily */
	stuff_p->place = PL_ABOVE;
}


/* if the slide for given tabslur stuff is to/from nowhere in particular,
 * then handle that here and return YES. Otherwise return NO. */

static int
nowhere_slide(stuff_p)

struct STUFF *stuff_p;

{
	double boundary;	/* east or west boundary of note, with
				 * the slide included */
	double adjust = 0.0;	/* to move the slanted line slightly when
				 * there is a note on the other side of
				 * the stem that is in the way. */
	struct GRPSYL *gs_p;
	struct NOTE *note_p;
	int n;
	float slidexlen;	/* SLIDEXLEN * Staffscale */


	if (stuff_p->curveno < 0) {
		return(NO);
	}

	if (stuff_p->begnote_p->nslurto == 0) {
		return(NO);
	}

	/* find which note it is in the chord, so check later for possible
	 * collisions between the slide and a neighboring note */
	gs_p = stuff_p->beggrp_p;
	note_p = stuff_p->begnote_p;
	for (n = 0; n < gs_p->nnotes; n++) {
		if ( &(gs_p->notelist[n]) == note_p) {
			break;
		}
	}
	if (n == gs_p->nnotes) {
		pfatal("couldn't find note in chord for slide");
	}

	slidexlen = SLIDEXLEN * Staffscale;

	/* for each type, find the outer boundary of the note with the
	 * nowhere slide included and draw a line from there towards the
	 * note, slanted the appropriate direction */
	switch (stuff_p->begnote_p->slurtolist[stuff_p->curveno].octave) {

	case IN_UPWARD:
		boundary = stuff_p->beggrp_p->c[AX] +
			notehorz(stuff_p->beggrp_p, stuff_p->begnote_p, RW);
		/* If there is a note one stepsize below this note, and it's
		 * to the left of the stem while the target note is on the
		 * right side, move the slide up a
		 * tiny bit so it doesn't get swallowed up in that other note
		 * and/or a slide coming into it.
		 * If we're sliding into the middle of a cluster with
		 * wrong-side notes both above and below the target note, it
		 * will still get somewhat swallowed, but that's unlikely to
		 * happen very often, and if it does, this is still about the
		 * best we can manage in that case. */
		n++;
		if (n < gs_p->nnotes && gs_p->notelist[n].stepsup
				== note_p->stepsup - 1 &&
				gs_p->notelist[n].c[AX] < note_p->c[AX]) {
			adjust = Stdpad;
		}
		do_nowhere(stuff_p,
			boundary, stuff_p->begnote_p->c[RY] - Stepsize + adjust,
			boundary + slidexlen, stuff_p->begnote_p->c[RY] + adjust);
		return(YES);

	case IN_DOWNWARD:
		boundary = stuff_p->beggrp_p->c[AX] +
			notehorz(stuff_p->beggrp_p, stuff_p->begnote_p, RW);
		/* if there is a note just above that we might
		 * collide with, adjust to dodge it. */
		n--;
		if (n >= 0 && gs_p->notelist[n].stepsup
				== note_p->stepsup + 1 &&
				gs_p->notelist[n].c[AX] < note_p->c[AX]) {
			adjust = Stdpad;
		}
		do_nowhere(stuff_p,
			boundary, stuff_p->begnote_p->c[RY] + Stepsize - adjust,
			boundary + slidexlen, stuff_p->begnote_p->c[RY] - adjust);
		return(YES);

	case OUT_UPWARD:
		boundary = stuff_p->beggrp_p->c[AX] +
			notehorz(stuff_p->beggrp_p, stuff_p->begnote_p, RE);
		/* If note just above this one that we might collide with,
		 * dodge it */
		n--;
		if (n >= 0 && gs_p->notelist[n].stepsup
				== note_p->stepsup + 1 &&
				gs_p->notelist[n].c[AX] > note_p->c[AX]) {
			adjust = Stdpad;
		}
		do_nowhere(stuff_p,
			boundary - slidexlen, stuff_p->begnote_p->c[RY] - adjust,
			boundary, stuff_p->begnote_p->c[RY] + Stepsize - adjust);
		return(YES);

	case OUT_DOWNWARD:
		boundary = stuff_p->beggrp_p->c[AX] +
			notehorz(stuff_p->beggrp_p, stuff_p->begnote_p, RE);
		/* If note below we might collide with, dodge it */
		n++;
		if (n < gs_p->nnotes && gs_p->notelist[n].stepsup
				== note_p->stepsup - 1 &&
				gs_p->notelist[n].c[AX] > note_p->c[AX]) {
			adjust = Stdpad;
		}
		do_nowhere(stuff_p,
			boundary - slidexlen, stuff_p->begnote_p->c[RY] + adjust,
			boundary, stuff_p->begnote_p->c[RY] - Stepsize + adjust);
		return(YES);

	default:
		return(NO);
	}
}


/* make a CRVLIST with the 2 given points and put it in the given stuff */

static void
do_nowhere(stuff_p, x1, y1, x2, y2)

struct STUFF *stuff_p;
double x1, y1, x2, y2;

{
	MALLOC(CRVLIST, stuff_p->crvlist_p, 1);
	stuff_p->crvlist_p->x = x1;
	stuff_p->crvlist_p->y = y1;
	MALLOC(CRVLIST, stuff_p->crvlist_p->next, 1);
	stuff_p->crvlist_p->next->x = x2;
	stuff_p->crvlist_p->next->y = y2;

	stuff_p->crvlist_p->prev = stuff_p->crvlist_p->next->next
							= (struct CRVLIST *) 0;
	stuff_p->crvlist_p->next->prev = stuff_p->crvlist_p;

	/* place is not really relevant, but put something in it */
	stuff_p->place = PL_ABOVE;
}


/* Figure out what points are needed for a curve, either a phrase mark
 * or a tie/slur, or a bend.
 * First it figures out where the endpoints should be,
 * then finds a curve that will be beyond all the groups that it covers.
 */

static void
curve_points(mll_p, stuff_p, is_phrase)

struct MAINLL *mll_p;		/* MAINLL that stuff_p hangs off of */
struct STUFF *stuff_p;		/* info about the phrase mark or tie/slur */
int is_phrase;			/* YES if phrase, NO if tie or slur */

{
	struct GRPSYL *begin_gs_p;	/* curve starts on this group */
	struct GRPSYL *end_gs_p;	/* curve ends on this group */
	struct NOTE *begnote_p;		/* first note for tie/slur */
	struct NOTE *endnote_p = 0;	/* last note of tie/slur */
	int place;			/* bend PL_ABOVE or PL_BELOW */
	int side;			/* RN or RS */
	int side_adj;			/* AN or AS. This field is used to
					 * adjust for nested phrase marks */
	double bulgeval;		/* bulge factor of curve */
	int try;			/* count of tries to get a good curve */
	int found_good;			/* YES if found a good-looking curve */
	struct TRYBULGE tb;		/* Info for try_bulge() */
	struct TRYBULGE *try_p;		/*  = &tb */
	float sign;			/* based on if curve is up or down */
	struct CRVLIST *curvelist_p;	/* beginning of curve */
	struct CRVLIST *endlist_p;	/* last point of curve */
	struct CRVLIST *new_p;		/* point to add to list of points */
	struct MAINLL *bar_mll_p = 0;	/* to find bar or pseudo bar */
	float length;			/* length of curve */
	float ylen;		/* length of segment in y direction before
				 * rotation */
	float y_adj = 0.0, y2_adj = 0.0;/* if moved because was an end note */
	char *name;		/* "phrase" or "tie/slur" */
	float sintheta, costheta;/* for rotating */


	debug(32, "curve_points lineno %d", stuff_p->inputlineno );

	/* get short names to groups and notes we'll use a lot */
	begin_gs_p = stuff_p->beggrp_p;
	end_gs_p = stuff_p->endgrp_p;
	begnote_p = stuff_p->begnote_p;
	
	/* figure out what string ("phrase" or "tie/slur") to use for error
	 * messages and make sure begin group is not null */
	if (is_phrase == YES) {
		name = "phrase";
		if ( (begin_gs_p == (struct GRPSYL *) 0)
				|| (end_gs_p == (struct GRPSYL *) 0) ) {
			pfatal("no group associated with phrase");
		}
	}
	else {
		int indx;

		name = "tie/slur";
		if (begin_gs_p == (struct GRPSYL *) 0) {
			pfatal("no group associated with tie/slur");
		}
		/* figure out which direction to bend the tie/slur */
		if (stuff_p->carryin == YES) {
			struct MAINLL *m_p;
			struct GRPSYL *g_p;
			struct STUFF *st_p;

			/* Need to base bend direction on the
			 * group/note/curve that was the carryout,
			 * otherwise the carryin and carryout could have
			 * different bend directions.
			 * We also need the costuff_p to get
			 * any user override of bend direction.
			 *
			 * Find the MAINLL pointing to the STAFF that
			 * should contain the costuff. Use prevgrpsyl,
			 * since it knows how to deal with endings,
			 * but we're really interested in the MAINLL
			 * pointing to the GRPSYL
			 * rather than the GRPSYL itself.
			 */

			/* First make sure we have the first group
			 * in the measure. */
			for (g_p = begin_gs_p; g_p->prev != 0; g_p = g_p->prev) {
				;
			}

			/* Now find the MAINLL pointing to the prev meas */
			m_p = mll_p;
			(void) prevgrpsyl(g_p, &m_p);
			if (m_p == 0 || m_p->str != S_STAFF) {
				pfatal("failed to find costaff_p's mainll");
			}

			/* Locate the costuff. We could just use
			 * stuff_p->costuff_p, but by searching for it here,
			 * we double check that we really found the right
			 * MAINLL, and can pfatal if not. */
			for (st_p = m_p->u.staff_p->stuff_p; st_p != 0;
							st_p = st_p->next) {
				if (st_p == stuff_p->costuff_p) {
					break;
				}
			}
			if (st_p == 0) {
				pfatal("failed to find costaff_p from mainll");
			}

			indx = st_p->begnote_p - &(st_p->beggrp_p->notelist[0]);
			stuff_p->place = (bulge_direction(m_p, st_p->beggrp_p,
				indx, st_p->curveno) == UP
				? PL_ABOVE : PL_BELOW);
		}
		else {
			indx = begnote_p - &(begin_gs_p->notelist[0]);
			stuff_p->place = (bulge_direction(mll_p, begin_gs_p,
				indx, stuff_p->curveno) == UP
				? PL_ABOVE : PL_BELOW);
		}
	}

	place = stuff_p->place;

	/* determine whether to use north or south of groups, and what sign to
	 * use to get the bends in the correct direction */
	if (place == PL_ABOVE) {
		side = RN;
		side_adj = AN;
		sign = 1.0;
	}
	else {
		side = RS;
		side_adj = AS;
		sign = -1.0;
	}

	/* set up the beginning coord */
	MALLOC(CRVLIST, curvelist_p, 1);
	curvelist_p->prev = (struct CRVLIST *) 0;
	if (is_phrase == YES) {
		/* Start slightly to east of center, so that if another
		 * curves ends on this group, they won't quite touch */
		curvelist_p->x = begin_gs_p->c[AX] + XOFFSET4CURVE;
		if (begin_gs_p->grpcont != GC_SPACE) {
			curvelist_p->y = begin_gs_p->c[side]
				+ eff_tupext(begin_gs_p, mll_p->u.staff_p, place)
				+ (sign * 2.0 * Stdpad);
			/* If there is something in [side_adj] there
			 * was another phrase on this group. But if that phrase
			 * ended on this group, it can be ignored. */
			if (begin_gs_p->c[side_adj] != 0.0 &&
					(begin_gs_p->phraseside & EAST_SIDE)) {
				curvelist_p->y += begin_gs_p->c[side_adj];
			}
		}
		else {
			/* Bizarre case. First group is a space. Use 3 steps
			 * from top or bottom of staff for y coord */
			curvelist_p->y = sign * (3.0 * Stepsize
					+ halfstaffhi(begin_gs_p->staffno));
		}
	}

	else { /* is tie or slur */

		curvelist_p->y = begnote_p->c[RY];
		y_adj = 0.0;

		/* if on the "end" note of a group,
		 * the curve can probably be moved
		 * to the x of the note instead of the edge of the group.
		 * We assume it can if the curve bends away
		 * from the stem and there are no "with"
		 * list items on the group. If there is a with list, move
		 * a little bit, but not enough to hit with items */
		if (begin_gs_p->stemdir == UP && place == PL_BELOW
				&& begnote_p == &(begin_gs_p->notelist
				[begin_gs_p->nnotes - 1])) {
			if (begin_gs_p->nwith == 0 || begin_gs_p->normwith == NO) {
				curvelist_p->x = begnote_p->c[AX]
							+ (2.0 * Stdpad);
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				curvelist_p->y -= y_adj;
			}
			else {
				curvelist_p->x = begnote_p->c[AE];
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
				curvelist_p->y -= y_adj;
			}
		}
		else if (begin_gs_p->stemdir == DOWN && place == PL_ABOVE
				&& begnote_p == &(begin_gs_p->notelist[0])) {
			if (begin_gs_p->nwith == 0
						|| begin_gs_p->normwith == NO) {
				curvelist_p->x = begnote_p->c[AX]
					+ (2.0 * Stdpad);
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				curvelist_p->y += y_adj;
			}
			else {
				curvelist_p->x = begnote_p->c[AE];
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
				curvelist_p->y += y_adj;
			}
		}

		/* whole notes and longer don't really have a stem, so top
		 * note of "stem up" can be moved. Stemless grace notes also
		 * don't have a stem, so the same logic applies. */
		else if ( (begin_gs_p->basictime < 2
				|| (begin_gs_p->grpvalue == GV_ZERO
				&& begin_gs_p->basictime < 8))
				&& begin_gs_p->stemdir == UP
				&& place == PL_ABOVE &&
				begnote_p == &(begin_gs_p->notelist[0])) {
			if (begin_gs_p->nwith == 0
					|| begin_gs_p->normwith == YES) {
				curvelist_p->x = begnote_p->c[AX] + Stdpad;
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				curvelist_p->y += y_adj;
			}
			else {
				curvelist_p->x = begnote_p->c[AE];
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
				curvelist_p->y += y_adj;
			}
		}

		/* can also be moved if bottom note of stem-down group */
		else if (begin_gs_p->stemdir == DOWN && place == PL_BELOW
				&& begnote_p == &(begin_gs_p->notelist
				[begin_gs_p->nnotes - 1])  &&
				stuff_p->carryin == NO) {
			if (begin_gs_p->basictime < 2 && begin_gs_p->nwith > 0
					&& begin_gs_p->normwith == NO) {
				curvelist_p->x = begin_gs_p->c[AE];
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
				curvelist_p->y -= y_adj;
			}
			else {
				curvelist_p->x = begin_gs_p->c[AX];
				y_adj = (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				curvelist_p->y -= y_adj;
			}
		}
		else {
			curvelist_p->x = begin_gs_p->c[AX] +
					notehorz(begin_gs_p, begnote_p, RE) +
					Stdpad;
		}

		/* If two notes are a stepsize apart and the curve from the
		 * west note is bending towards the east note,
		 * then the x should be moved east a little.
		 * First case: this isn't the top note, but the note just
		 * above is 1 stepsize away and on the east side, and the
		 * curve is going up and it's not a carryin. */
		if (begnote_p != &(begin_gs_p->notelist[0]) &&
				begnote_p->stepsup ==
				begnote_p[-1].stepsup - 1 &&
				begnote_p->c[RX] < begnote_p[-1].c[RX] &&
				place == PL_ABOVE &&
				stuff_p->carryin == NO) {
			curvelist_p->x += 1.5 * Stepsize;
		}
		/* Second case: not bottom note, note just
		 * below is one step away and on the east side, the curve
		 * is going down, and it's not a carryin. */
		else if (begnote_p != &(begin_gs_p->notelist[begin_gs_p->nnotes-1]) &&
				begnote_p->stepsup ==
				begnote_p[1].stepsup + 1 &&
				begnote_p->c[RX] < begnote_p[1].c[RX] &&
				place == PL_BELOW &&
				stuff_p->carryin == NO) {
			curvelist_p->x += 1.5 * Stepsize;
		}
				
	}

	/* if carried over from previous score, start a bit farther left */
	if (stuff_p->carryin == YES) {

		/* find the pseudo bar and set x to that */
		for (bar_mll_p = mll_p->prev;
					bar_mll_p != (struct MAINLL *) 0;
					bar_mll_p = bar_mll_p->prev) {
			if (bar_mll_p->str == S_CLEFSIG) {
				if (bar_mll_p->u.clefsig_p->bar_p
							== (struct BAR *) 0) {
					/* carryin to an ending */
					continue;
				}
				curvelist_p->x =
					bar_mll_p->u.clefsig_p->bar_p->c[AE]
					- (TIESLURPAD * Staffscale);

				/* Long notes (wholes, etc) generally get
				 * more space on their left than short notes,
				 * so a curve carried in to a long note
				 * may look overly long, especially if other
				 * scores on the same page have carryins
				 * to short notes. So limit carryin curve
				 * length to 5 stepsizes.
				 */
				if (begin_gs_p->c[AW] - curvelist_p->x > 5.0 * Stepsize) {
					curvelist_p->x = begin_gs_p->c[AW]
							- 5.0 * Stepsize;
				}
				break;
			}
			else if (bar_mll_p->str == S_BAR) {
				/* carryin to an ending */
				curvelist_p->x = begin_gs_p->c[AW];
				break;
			}
		}

		if (bar_mll_p == (struct MAINLL *) 0) {
			pfatal("missing CELFSIG when carrying over %s mark",
								name);
		}
	}

	/* set up ending coord */
	MALLOC(CRVLIST, endlist_p, 1);
	if (is_phrase == YES) {
		/* End slightly to west of group center, so that another
		 * curve can start on this group (if needed) with
		 * touching this curve. */
		endlist_p->x = end_gs_p->c[AX] - XOFFSET4CURVE;
		if (end_gs_p->grpcont != GC_SPACE) {
			endlist_p->y = end_gs_p->c[side]
				+ eff_tupext(end_gs_p, mll_p->u.staff_p, place)
				+ (sign * 2.0 * Stdpad);
			/* Add in space for any relevant nested phrases */
			if (end_gs_p->c[side_adj] != 0.0 &&
					(end_gs_p->phraseside & WEST_SIDE)) {
				endlist_p->y += end_gs_p->c[side_adj];
			}
		}
		else {
			/* Bizarre case. Last group is a space.  Use 3 steps
			 * from top or bottom of staff for y coord */
			endlist_p->y = sign * (3.0 * Stepsize
					+ halfstaffhi(begin_gs_p->staffno));
		}
	}
	else {
		if (stuff_p->carryin == YES) {
			/* in case of carryin, the "begin" group is actually
			 * the ending group, so set the end group, and
			 * adjust the beginning y */
			endlist_p->x = begin_gs_p->c[AW];

			/* adjust things carried into endings to account for
			 * the padding that was added */
			if (bar_mll_p->str == S_BAR) {
				endlist_p->x += TIESLURPAD * Staffscale;
			}

			endlist_p->y = curvelist_p->y;
			end_gs_p = begin_gs_p;

			/* if end note, adjust */
			if (place == PL_ABOVE && begnote_p
						== &(begin_gs_p->notelist[0])) {
				endlist_p->x = begnote_p->c[AX];
				if ((begin_gs_p->basictime > 1) &&
						(begin_gs_p->stemdir == UP)) {
					endlist_p->y += Stepsize;
					curvelist_p->y += Stepsize;
				}
			}
			else if (place == PL_BELOW && begnote_p ==
						&(begin_gs_p->notelist
						[begin_gs_p->nnotes - 1])
						&& (begin_gs_p->stemdir == UP
						|| begin_gs_p->basictime < 2)) {
				endlist_p->x = begnote_p->c[AX];
				if ((begin_gs_p->basictime < 2) &&
						(begin_gs_p->stemdir == DOWN)) {
					endlist_p->y -= Stepsize;
					curvelist_p->y -= Stepsize;
				}
			}
		}
		else {
			/* not carryin */
			if (end_gs_p == 0) {
				/* This is the most usual case. But end_gs_p
				 * will have already been set from the STUFF if
				 * this is a tie/slur to a different voice. */
				end_gs_p = find_next_group (mll_p, begin_gs_p,
						(stuff_p->curveno == -1
						? "tie" : "slur"));
			}
			if (stuff_p->curveno == -1) {
				/* this is a tie */
				endnote_p = find_matching_note (end_gs_p,
						mll_p, begnote_p->letter,
						begnote_p->FRETNO,
						begnote_p->octave, "tie");
			}
			else {
				if (IS_NOWHERE(begnote_p->slurtolist
						[stuff_p->curveno].octave)) {
					pfatal("curve_points called on slide to nowhere");
				}

				endnote_p = find_matching_note (end_gs_p, 0,
						begnote_p->slurtolist
						[stuff_p->curveno].letter,
						-1,
						begnote_p->slurtolist
						[stuff_p->curveno].octave,
						"slur/slide");
			}

			if (endnote_p == 0) {
				pfatal("curve_points: unable to find matching note that had been found earlier");
			}

			endlist_p->y = endnote_p->c[RY];

			y2_adj = 0.0;

			/* move if below curve and bottom note with stem up */
			if (end_gs_p->stemdir == UP && place == PL_BELOW
					&& endnote_p == &(end_gs_p->notelist
					[end_gs_p->nnotes - 1])) {
				if (end_gs_p->nwith == 0
						|| end_gs_p->normwith == NO) {
					endlist_p->x = endnote_p->c[AX]
						- (2.0 * Stdpad);
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
					endlist_p->y -= y2_adj;
				}
				else {
					endlist_p->x = endnote_p->c[AW];
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
					endlist_p->y -= y2_adj;
				}
			}

			/* move if above and top note with stem down */
			else if (end_gs_p->stemdir == DOWN && place == PL_ABOVE
				     && endnote_p == &(end_gs_p->notelist[0])) {
				if (end_gs_p->nwith == 0
						|| end_gs_p->normwith == NO) {
					endlist_p->x = endnote_p->c[AX]
							- (2.0 * Stdpad);
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
					endlist_p->y += y2_adj;
				}
				else {
					endlist_p->x = endnote_p->c[AW];
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
					endlist_p->y += y2_adj;
				}
			}

			/* whole and longer don't have stem, so end note where
			 * a stem would be (if there were one) can be moved */
			else if (end_gs_p->basictime < 2 &&
					end_gs_p->stemdir == DOWN
					&& place == PL_BELOW
					&& endnote_p == &(end_gs_p->notelist
					[end_gs_p->nnotes - 1])) {
				if (end_gs_p->nwith == 0
						|| end_gs_p->normwith == YES) {
					endlist_p->x = endnote_p->c[AX]
								- Stdpad;
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
					endlist_p->y -= y2_adj;
				}
				else {
					endlist_p->x = endnote_p->c[AW];
					y2_adj = (Stepsize *
						(endnote_p->notesize
						== GS_NORMAL ? 1.2 : 0.9));
					endlist_p->y -= y2_adj;
				}
			}

			/* move if above and top note of stem up */
			else if (end_gs_p->stemdir == UP && place == PL_ABOVE
					&& endnote_p ==
					&(end_gs_p->notelist[0]) ) {
				endlist_p->x = end_gs_p->c[AX];
				y2_adj = (Stepsize * (endnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				endlist_p->y += y2_adj;

				/* if tied from note is also the top of its
				 * group, level the tie/slur */
				if (begin_gs_p->stemdir == UP &&
						begnote_p ==
						&(begin_gs_p->notelist[0])  &&
						begin_gs_p->basictime > 1 ) {
					curvelist_p->y += (Stepsize *
						(begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
				}
			}
			else if (begin_gs_p->grpvalue == GV_ZERO) {
				/* grace note to main note, can't use the west
				 * of the end group because that would include
				 * the grace note. */
				endlist_p->x = endnote_p->c[AX] +
					notehorz(end_gs_p, endnote_p, RW);
			}
			else {
				endlist_p->x = tieslurx(end_gs_p, endnote_p,
					stuff_p->place) - (2.0 * Stdpad);
			}

			/* if note tied from is bottom of group with stem down,
			 * level the tie/slur */
			if (end_gs_p->stemdir == DOWN && place == PL_BELOW
					&& endnote_p == &(end_gs_p->notelist
					[end_gs_p->nnotes - 1]) &&
					begin_gs_p->stemdir == DOWN &&
					begnote_p == &(begin_gs_p->notelist
					[begin_gs_p->nnotes - 1]) &&
					end_gs_p->basictime > 1 ) {
				endlist_p->y -= (Stepsize *
						(begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
			}

			/* if beginning of curve was adjusted and this is
			 * an inner note, but there is room on the relevant
			 * side, and this is a tie, then adjust this end's y
			 * to level the curve */
			else if (y_adj != 0.0 && stuff_p->curveno == -1) {
				endlist_p->y += inner_adj(end_gs_p, endnote_p,
							y_adj, place);
			}

			/* level beginning if the note in the previous
			 * chord was the same note but wasn't the top,
			 * but the next note is more than a stepsize
			 * away. */
			if (y2_adj != 0.0 && stuff_p->curveno == -1) {
				curvelist_p->y += inner_adj(begin_gs_p,
					begnote_p, y2_adj, place);
			}
		}
	}

	/* one final adjustment. If the stem of first group is up and stem
	 * of second group is down, and the notes being tied/slurred are both
	 * the tops notes if the place is above or both bottom notes if the
	 * place is below, then move the y coord on the side that wasn't
	 * already moved, to level the curve. Do only if the note is shorter
	 * than a whole note, because longer notes were already moved because
	 * they had no stem. */
	if (is_phrase == NO && begin_gs_p->stemdir == UP
					&& end_gs_p != (struct GRPSYL *) 0
					&& end_gs_p->stemdir == DOWN) {
		if (place == PL_ABOVE && begnote_p ==
				&(begin_gs_p->notelist[0])
				&& endnote_p == &(end_gs_p->notelist[0])
				&& begin_gs_p->basictime > 1) {
			curvelist_p->y += (Stepsize * (begnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
		}
		else if (place == PL_BELOW && begnote_p ==
				&(begin_gs_p->notelist[begin_gs_p->nnotes - 1])
				&& endnote_p ==
				&(end_gs_p->notelist[end_gs_p->nnotes - 1])
				&& end_gs_p->basictime > 1) {
			endlist_p->y -= (Stepsize * (endnote_p->notesize
						== GS_NORMAL ? 1.7 : 1.2));
		}
	}

	endlist_p->next = (struct CRVLIST *) 0;
	/* no need to set other links now because we will be added other nodes
	 * in between in a moment anyway */
	
	/* if carrying over, extend x to margin */
	if (stuff_p->carryout) {
		endlist_p->x = PGWIDTH - eff_rightmargin(mll_p);
	}

	/* find length of curve by Pythagorean */
	length = sqrt(SQUARED(endlist_p->x - curvelist_p->x)
				+ SQUARED(endlist_p->y - curvelist_p->y));

	/* Find y length for creating bulge in the curve.
	 * Make bigger bend if longer curve, but not too big or too small.
	 */
	ylen = length / 16;
	if (ylen > 2.2 * Stepsize) {
		ylen = 2.2 * Stepsize;
	}
	else if (ylen < (Stepsize * 0.75)) {
		ylen = Stepsize * 0.75;
	}
	ylen = ylen * sign;

	/* we figure out curve as if endpoints were on the x axis, then adjust
	 * with the proper sin and cos factors to get them where they really
	 * belong */
	sintheta = (endlist_p->y - curvelist_p->y) / length;
	costheta = (endlist_p->x - curvelist_p->x) / length;

	/* set up node for another point on curve */
	MALLOC(CRVLIST, new_p, 1);
	new_p->prev = curvelist_p;
	new_p->next = endlist_p;
	curvelist_p->next = new_p;
	endlist_p->prev = new_p;

	if (stuff_p->carryout == YES) {
		if (is_phrase == YES) {
			endlist_p->y += ylen / 2.0;
		}
		else {
			end_gs_p = begin_gs_p;
		}
	}

	/* First try a single point in the middle. Try bigger bulge
	 * value if some groups stick out, up to a maximum. */
	tb.mll_p = mll_p;
	tb.begin_gs_p = begin_gs_p;
	tb.end_gs_p = end_gs_p;
	tb.place = place;
	tb.curvelist_p = curvelist_p;
	tb.endlist_p = endlist_p;
	tb.xlen = length / 2.0;
	tb.ylen = ylen;
	tb.sintheta = sintheta;
	tb.costheta = costheta;
	tb.minbulge = MINBULGE;
	tb.maxbulge = MAXBULGE;
	if (sintheta > 0.3) {
		/* steep curve may likely look better with more bulge */
		tb.minbulge *= (0.7 + sintheta);
		tb.maxbulge *= (0.7 + sintheta);
	}
	try_p = &tb;
	if ((bulgeval = try_bulge(try_p)) < MAXBULGE) {
		/* This curve works. Go with it */
		if (bulgeval == MINBULGE) {
			/* The very first try worked with nothing in the way,
			 * so may be safe to try to
			 * beautify any really steep curves.
			 * So try to redo and see if still okay.
			 * If not, put back the original.
			 */
			double save_x, save_y;
			save_x = curvelist_p->next->x;
			save_y = curvelist_p->next->y;
			redo_steep(curvelist_p, endlist_p, place);
			if (stick_out(try_p) > 0.0) {
				curvelist_p->next->x = save_x;
		 		curvelist_p->next->y = save_y;
			}
		}
		/* adjust group boundaries to include the curve */
		final_touches(mll_p, begin_gs_p, end_gs_p, curvelist_p, place);

		/* attach the curve to the stuff */
		stuff_p->crvlist_p = curvelist_p;
		return;
	}

	/* Just adjusting bulge didn't work,
	 * so we try repeatedly moving the ends slightly
	 * and trying again until something works.
	 * Worst case should be something like an above curve encompassing c0
	 * to b9 back to c0, with a stem up on the b9. That would be about 80
	 * stepsizes. But if an end is a cross-staff stem group completely
	 * on the other staff, and if that other staff is ridiculously
	 * far away because of very tall STUFF, even 100 iterations
	 * of moving by a Stepsize sometimes isn't enough.
	 * So we'll try 200 times before giving up with a pfatal.
	 */
	tb.minbulge = MIN2BULGE;
	tb.maxbulge = MAX2INITIALBULGE;
	if (sintheta > 0.3) {
		/* steep curve may likely look better with more bulge */
		tb.minbulge *= (0.7 + sintheta);
		tb.maxbulge *= (0.7 + sintheta);
	}
	found_good = NO;
	for (try = 0; try < 200; try++) {
		double mvbegin, mvend, mvboth;
		/* Getting more and more desperate,
		 * so gradually allow more and more bulge */
		if (tb.maxbulge < MAX2FINALBULGE) {
			tb.maxbulge += 0.15;
		}

		/* Try moving each end individually and both together,
		 * then try to  go with whatever gave the best results
		 * with the least movement.
		 */

		/* try with just begin point moved */
		curvelist_p->y += Stepsize * sign;
		mvbegin = try_bulge(try_p);

		/* try with both endpoints moved */
		endlist_p->y += Stepsize * sign;
		mvboth = try_bulge(try_p);

		/* try with just end point moved */
		curvelist_p->y -= Stepsize * sign;
		mvend = try_bulge(try_p);

		/* See which of the three attempts seemed best */
		if( mvend < mvbegin && mvend < mvboth) {
			/* moving just the end was best */
			if (mvend < tb.maxbulge) {
				found_good = YES;
				break;
			}
		}
		else if (mvbegin < mvend && mvbegin < mvboth) {
			/* moving just the beginning was best */
			curvelist_p->y += Stepsize * sign;
			endlist_p->y -=  Stepsize * sign;
			if (mvbegin < tb.maxbulge) {
				found_good = YES;
				break;
			}
		}
		else {
			/* move both ends */
			curvelist_p->y += Stepsize * sign;
			if (mvboth < tb.maxbulge) {
				found_good = YES;
				break;
			}
		}
	}

	if (found_good == YES) {
		/* Call try_bulge again to set the inner points (the one
		 * we chose might not be the last one we tried. */
		(void) try_bulge(try_p);
		final_touches(mll_p, begin_gs_p, end_gs_p, curvelist_p, place);

		/* attach the curve to the stuff */
		stuff_p->crvlist_p = curvelist_p;
		return;
	}

	pfatal("unable to find a usable curve");
}


/* 
 * Returns the smallest bulge factor that worked, or a value >= maxbulge if
 * nothing worked. The more the return value exceeds maxbulge, the worse
 * the amount of "stick out." The curvelist_p should point to a curve with
 * 3 or 4 points.
 */

static double
try_bulge(info_p)

struct TRYBULGE *info_p;	/* points to all the info this func needs */

{
	struct CRVLIST *mid_p;		/* interior point of curve */
	struct CRVLIST *mid2_p;		/* second inner point, if any */
	double bulge_factor;		/* how much to bulge */
	double amount = 0.0;		/* amount of stick out */


	/* Get pointer to the midpoint(s) */
	mid_p = info_p->curvelist_p->next;
	if (mid_p->next != info_p->endlist_p) {
		mid2_p = mid_p->next;
	}
	else {
		mid2_p = 0;
	}

	/* Keep trying bigger bulge until we find one that clears all the
	 * groups or until the specified maximum is reached. */
	for (bulge_factor = info_p->minbulge; bulge_factor < info_p->maxbulge;
						bulge_factor += 0.25) {

		/* find (x,y) values for midpoint(s) taking the rotation
		 * from horizontal into account. */
		mid_p->x = info_p->curvelist_p->x
			+ (info_p->xlen * info_p->costheta)
			- (bulge_factor * info_p->ylen * info_p->sintheta);
		mid_p->y = info_p->curvelist_p->y
			+ (bulge_factor * info_p->ylen * info_p->costheta)
			+ (info_p->xlen * info_p->sintheta);

		if (mid2_p != 0) {
			mid2_p->x = info_p->curvelist_p->x
				+ (2.0 * info_p->xlen * info_p->costheta)
				- (bulge_factor * info_p->ylen * info_p->sintheta);
			mid2_p->y = info_p->curvelist_p->y
				+ (bulge_factor * info_p->ylen * info_p->costheta)
				+ (2.0 * info_p->xlen * info_p->sintheta);
		}

		if ((amount = stick_out(info_p)) <= 0.0) {
			/* This curve works. Go with it */
			break;
		}
	}

	/* Even max allowed bulge value was not enough. Returning the max bulge
	 * allowed tells caller we failed, and adding on how much
	 * "stick-out" gives an indication of how badly we failed.
	 */
	return(bulge_factor + amount);
}


/* adjust the endpoint of an inner note if the opposite end was adjusted,
 * and there is room to adjust this end. */

static double
inner_adj(gs_p, note_p, y_adj, place)

struct GRPSYL *gs_p;	/* not is in this group */
struct NOTE *note_p;	/* this is the note being tied to */
double y_adj;		/* how much other end of tie was adjusted */
int place;		/* PL_ABOVE or PL_BELOW */

{
	int i;


	if (gs_p->nnotes <= 2) {
		/* can't possibly be an inner note, so no adjust */
		return(0.0);
	}

	/* find index of note */
	for (i = 0; i < gs_p->nnotes; i++) {
		if (note_p == &(gs_p->notelist[i])) {
			break;
		}
	}

	if (i == gs_p->nnotes) {
		pfatal("couldn't find note in chord");
	}

	if (i == 0 || i == gs_p->nnotes - 1) {
		/* not an inner note. no adjust */
		return(0.0);
	}

	/* check if next note in chord is within STEPSIZE away. If not,
	 * we can adjust this end */
	if (place == PL_ABOVE && gs_p->notelist[i-1].stepsup
					> gs_p->notelist[i].stepsup + 1) {
		return(y_adj);
	}
	else if (place == PL_BELOW && gs_p->notelist[i+1].stepsup
					< gs_p->notelist[i].stepsup - 1) {
		/* y_adj will always come in as a positive number and will be
		 * added on return, so return negative value for below curves */
		return(-y_adj);
	}
	return(0.0);
}


/* Returns the sum of the "stick out" of groups in the given curve.
 * If all groups are inside, this will be 0.0
 */

static double
stick_out(info_p)

struct TRYBULGE *info_p;

{
	struct GRPSYL *gs_p;	/* to walk through list */
	struct GRPSYL *begin_gs_p, *end_gs_p;
	double yleft, yright;	/* y value of point on the line that is
				 * at the x position of the left and right
				 * sides of the current GRPSYL, */
	double yg;		/* y of group accounting for other phrases */
	struct MAINLL *mll_p;	/* the curve's STUFF hangs off of here */
	int place;		/* PL_* */
	struct CRVLIST *curvelist_p;	/* beginning of curve to check */
	struct CRVLIST *endlist_p;	/* end of curve to check */
	int staff;
	int voice;
	double stickout;	/* return value */
	double len;		/* length that is deemed "near the end" of the
				 * curve, for setting left/right counts */
	double tupext;
	double clearance;
	double leftsteps;
	double rightsteps;


	begin_gs_p = info_p->begin_gs_p;
	end_gs_p = info_p->end_gs_p;
	if (begin_gs_p == 0 || end_gs_p == 0) {
		pfatal("got null pointer when checking phrase marks");
	}

	if (begin_gs_p->vno != end_gs_p->vno) {
		/* Must be a tie/slue to another voice. We don't attempt
		 * to try to avoid anything that is in the way. */
		return(0.0);
	}

	/* If starting phrase on last note of score or ending one on first
	 * note of a score, begin and end will be the same. We know that
	 * note has already been accounted for, so nothing to do. */
	if (begin_gs_p == end_gs_p) {
		return(0.0);
	}

	staff = begin_gs_p->staffno;
	voice = begin_gs_p->vno;
	curvelist_p = info_p->curvelist_p;
	endlist_p = info_p->endlist_p;
	mll_p = info_p->mll_p;
	place = info_p->place;
	stickout = 0.0;
	/* We will be counting up how many groups stick out near each end,
	 * to potentially help decide which endpoint to move to avoid
	 * collisions. For that purpose, we'll define "near the end"
	 * as being within 1/4 of the total x distance from an endpoint.
	 */
	len = (endlist_p->x - curvelist_p->x) / 4.0;

	/* Go through each group between the beginning and end. We've
	 * already set the curve endings to clear the group boundaries */
	for (gs_p = begin_gs_p->next; gs_p != end_gs_p; gs_p = gs_p->next) {

		/* If hit end of measure go to next measure.
		 * If the vscheme changes to 1 and then back to 2 in the
		 * middle of the phrase, there will be missing measures,
		 * so skip by all of them. */
		while (gs_p == (struct GRPSYL *) 0) {
			mll_p = next_staff(staff, mll_p->next);
			if (info_p->mll_p == (struct MAINLL *) 0) {
				pfatal("fell off end of list while doing phrase marks");
			}
			gs_p = mll_p->u.staff_p->groups_p[voice - 1];
		}

		if (gs_p == end_gs_p) {
			break;
		}

		/* Find out where the y of the curve is at this group.
		 * We actually check two points, one each slightly
		 * to the east and west of the group's x.
		 * We start by guessing 1.5 Stepsizes. Then we
		 * look at what is at the end. If it is
		 * a stem and there is no "with list,"
		 * we can probably get closer,
		 * especially if no flag/beam. Note that the flag/beam
		 * always affects the right side equally, but the stem
		 * effect depends on stem direction. */
		leftsteps = rightsteps = 1.5;
		if (info_p->place == PL_ABOVE && gs_p->stemdir == UP
					&& gs_p->stemlen > 3.0 * Stepsize
					&& (gs_p->nwith == 0 ||
					gs_p->normwith == YES)) {
			leftsteps = 0.5;
			if (gs_p->basictime < 8) {
				rightsteps = 0.5;
			}
		}
		else if (info_p->place == PL_BELOW && gs_p->stemdir == DOWN
					&& gs_p->stemlen > 3.0 * Stepsize
					&& gs_p->basictime < 8
					&& (gs_p->nwith == 0 ||
					gs_p->normwith == YES)) {
			rightsteps = 0.5;
		}
		yleft = curve_y_at_x(curvelist_p, gs_p->c[AX]
					- leftsteps * Stepsize);
		yright = curve_y_at_x(curvelist_p, gs_p->c[AX]
					+ rightsteps * Stepsize);

		/* See if this group is within the curve */
		if (info_p->place == PL_ABOVE) {
			/* Consider the group (RN) plus any relevant
			 * nested phrase marks (their space is stored in AN).
			 * It is relevant unless it's for the begin group
			 * and that group's east is not relevent, or it's the
			 * end group and that group's west is not relevant */
			tupext = eff_tupext(gs_p, mll_p->u.staff_p, place);
			if (tupext > 0.001) {
				/* We can afford to go a little closer to
				 * tuplets than to notes. */
				clearance = CLEARANCE / 3.0;
			}
			else {
				clearance = CLEARANCE;
			}
			yg = gs_p->c[RN] + clearance + tupext;
			if ( (gs_p != begin_gs_p ||
					((gs_p->phraseside & EAST_SIDE) == 0))
					&& (gs_p != end_gs_p ||
					((gs_p->phraseside & WEST_SIDE) == 0)) ) {
				yg += gs_p->c[AN];
			}
			if (yleft > yg && yright > yg) {
				/* Good. It's inside */
				continue;
			}
			else {
				/* Bad. It stuck over */
				stickout += yg - MIN(yleft, yright);
				/* If we are getting desperate, and
				 * one of the corners of the "bounding box"
				 * was cleared, and the other one only got
				 * clipped down into the area of clearance
				 * clearance, we can declare that as good
				 * enough to live with, because at worse
				 * it should just barely brush one corner. */
				if (info_p->maxbulge >= MAX2INITIALBULGE &&
						(yleft > yg || yright > yg ) &&
						stickout < clearance) {
					continue;
				}
			}
		}
		else {
			/* Do the same for curve going down */
			tupext = eff_tupext(gs_p, mll_p->u.staff_p, place);
			if (tupext < -0.001) {
				/* We can afford to go a little closer to
				 * tuplets than to notes. */
				clearance = CLEARANCE / 3.0;
			}
			else {
				clearance = CLEARANCE;
			}
			yg = gs_p->c[RS] - clearance + tupext;
			if ( (gs_p != begin_gs_p ||
					((gs_p->phraseside & EAST_SIDE) == 0))
					&& (gs_p != end_gs_p ||
					((gs_p->phraseside & WEST_SIDE) == 0)) ) {
				yg += gs_p->c[AS];
			}
			if (yleft < yg && yright < yg) {
				continue;
			}
			else {
				stickout += MAX(yleft, yright) - yg;
				if (info_p->maxbulge >= MAX2INITIALBULGE &&
						(yleft < yg || yright < yg ) &&
						stickout < clearance) {
					continue;
				}
			}
		}
	}
	return(stickout);
}


/* find the x of the end of a tie/slur. Usually we could just used the west of
 * the group, but if there are lots of accidentals on notes that are far
 * away from the note in question, the end of the tie can come out rather
 * far away from its note. So try to see if we can move it closer, by
 * checking to see if there are any accidentals on notes nearby. This
 * function is not foolproof, sometimes leaving space when the tie/slur
 * could actually get threaded through a tiny opening, and sometimes
 * overwriting the edge of an accidental somewhat, but tries to do a better
 * job than the original single line of code for figuring this out had done. */

static double
tieslurx(gs_p, note_p, place)

struct GRPSYL *gs_p;	/* check notes in this group */
struct NOTE *note_p;	/* check for accidentals near this note */
int place;		/* PL_ABOVE or PL_BELOW to tell which side to look on */

{
	int n;		/* index through notelist */
	int acc;	/* accidental */


	/* if "wrong" side of a stem up group, better use group boundary */
	if (note_p->c[AX] > gs_p->c[AX] && gs_p->stemdir == UP) {
		return(gs_p->c[AW] + gs_p->padding +
				vvpath(gs_p->staffno, gs_p->vno, PAD)->pad);
	}

	/* if there is another note nearby,
	 * and that note has an accidental, better use
	 * the west of the group to be safe, otherwise
	 * use the west of the note. */
	for (n = 0; n < gs_p->nnotes; n++) {

		acc = gs_p->notelist[n].accidental;
		switch (gs_p->notelist[n].stepsup - note_p->stepsup) {
		case 1:
		case 2:
			/* close enough that sharp, flat, and dblflat may
			 * interfere, if coming in from above */
			if (place == PL_ABOVE && (acc == '#' || acc == '&'
							|| acc == 'B')) {
				return(gs_p->c[AW] + gs_p->padding +
					vvpath(gs_p->staffno, gs_p->vno, PAD)->pad);
			}
			break;
		case 3:
			/* close enough that sharp may interfere, if coming
			 * in from above */
			if (place == PL_ABOVE && acc == '#') {
				return(gs_p->c[AW] + gs_p->padding
					+ vvpath(gs_p->staffno, gs_p->vno, PAD)->pad);
			}
			break;
		case 0:
			/* the note itself */
			break;
		case -1:
			/* sharp, flat, and dblflat may interfere from
			 * either direction */
			if (acc == '#' || acc == '&' || acc == 'B') {
				return(gs_p->c[AW] + gs_p->padding
					+ vvpath(gs_p->staffno, gs_p->vno, PAD)->pad);
			}
			break;

		case -2:
		case -3:
		case -4:
			/* close enough that things may interfere */
			if (place == PL_BELOW && (acc == '#' || acc == '&'
							|| acc == 'B')) {
				return(gs_p->c[AW] + gs_p->padding
					+ vvpath(gs_p->staffno, gs_p->vno, PAD)->pad);
			}
			break;

		default:
			/* this note is too far away to matter */
			break;
		}
	}

	/* it seems there are no accidentals in the way, so use the note
	 * boundary, rather than group boundary */
	return(gs_p->c[AX] + notehorz(gs_p, note_p, AW));
}


/* given a main list struct, search forward from there for the STAFF matching
 * the given staff. If fall off end of main list, return NULL */

static struct MAINLL *
next_staff(staff, mll_p)

int staff;		/* find this staff number */
struct MAINLL *mll_p;	/* where to start */

{
	/* walk through main list looking for desired staff */
	for (  ; mll_p != (struct MAINLL *) 0; mll_p = mll_p->next) {
		if (mll_p->str == S_STAFF) {
			if (mll_p->u.staff_p->staffno == staff) {
				return(mll_p);
			}
		}
	}

	/* didn't find it */
	return( (struct MAINLL *) 0);
}

/*
 * Name:	redo_steep()
 *
 * Abstract:	Redo curves that are very steep.
 *
 * Returns:	void
 *
 * Description:	If the curve is "too steep", it redoes it
 *		so that it's horizontal at the outer end, rather than already
 *		sloping in towards the inner end.
 *		Caller needs to verify the redone curve doesn't collide
 *		with any groups. Assumes the curve contains 3 points.
 */

static void
redo_steep (first_p, last_p, place)

struct CRVLIST *first_p;	/* left endpoint of curve */
struct CRVLIST *last_p;		/* right endpoint of curve */
int place;			/* above or below */

{
	struct CRVLIST *mid_p;		/* new midpoint of curve */
	float delx;			/* distance from the end to test */
	float a, b;			/* some distances, see below */
	float midoff;			/* vert offset of midpoint */


	/*
	 * We need to test whether either end of the curve is sloping in.  So
	 * we really should find the derivative at the endpoints.  But we can
	 * approximate it close enough by finding the y value at a point "near"
	 * the end and comparing it to the end's y value.  "delx" tells how
	 * near.  We'd like to set it to a millionth of an inch, but due to
	 * apparent roundoff errors in curve_y_at_x(), we make it bigger than
	 * that: 1/4 the curve length, but never more than 2 stepsizes.
	 */
	if (last_p->x - first_p->x > 8 * Stepsize) {
		delx = 2 * Stepsize;
	} else {
		delx = (last_p->x - first_p->x) / 4.0;
	}
	if (place == PL_ABOVE) {
		/* if both near points are higher than end points, return */
		if (curve_y_at_x(first_p, first_p->x + delx) >= first_p->y &&
		    curve_y_at_x(first_p, last_p->x  - delx) >= last_p->y) {
			return;
		}
	} else {
		/* if both near points are lower than end points, return */
		if (curve_y_at_x(first_p, first_p->x + delx) <= first_p->y &&
		    curve_y_at_x(first_p, last_p->x  - delx) <= last_p->y) {
			return;
		}
	}

	/*
	 * The curve is steep.  First, we choose a new point,
	 * horizontally in the middle.  We are
	 * going to choose its vertical position so that the outer end of the
	 * curve starts out horizontal.
	 *
	 * Imagine the case of PL_BELOW where the left end is the outer (lower)
	 * end.  (The other 3 cases are symmetrical to this, and we can use the
	 * analogous result.)  Set the axes so that the left end is at the
	 * origin, and the right end is at (2*a, b).  The new point will be at
	 * (a, y), and we have to find y.  We know that y will be between 0 and
	 * b/2.  (Draw a picture.)
	 *
	 * Draw segments from (0, 0) to (a, y), and (a, y) to (2*a, b).  Then
	 * draw a line through (a, y) such that it forms the same angle theta
	 * with each of these segments.  The way calccurve() works, it will
	 * form two cubic arcs (in rotated coordinate systems) through the
	 * three points, such that the slope of each arc at each point forms
	 * the same angle theta with the segment next to it.  The last line we
	 * drew hits the X axis at a point which, with (0, 0) and (a, y) forms
	 * an isoceles triangle, where the angles at (0, 0) and (a, y) are
	 * both theta (because we're saying the arc at (0, 0) is horizontal).
	 * So the other angle is 180 degrees minus 2*theta.  That means the
	 * other angle the line forms with the X axis is 2*theta.  And that
	 * means the angle between the horizontal line through (a, y) and the
	 * second segment (a, y) to (2*a, b) is 3*theta.
	 *
	 * Looking at triangle (0, 0) to (a, 0) to (a, y), we see that
	 *	tan(theta) = y/a
	 * Looking at triangle (a, y) to (2*a, y) to (2*a, b), we see that
	 *	tan(3*theta) = (b-y)/a
	 * There is a trig identity
	 * 			3*tan(theta) - (tan(theta))^3
	 *	tan(3*theta) =	------------------------------
	 *				1 - 3*(tan(theta))^2
	 * Plug into this our values for tan(theta) and tan(3*theta), and you
	 * end up with
	 *	4 y^3 - 3 b y^2 - 4 a^2 y + a^2 b = 0
	 * To solve this cubic, we could do a whole routine for solving cubics,
	 * but it's easier to approximate as follows.
	 *
	 # Define
	 *	F(x) = 4 x^3 - 3 b x^2 - 4 a^2 x + a^2 b
	 * a and b are positive.  So at x = 0, F(x) > 0.  At x=b/2, F(x) < 0.
	 * Thus, as we expect, F(x) = 0 somewhere in between.  For the
	 * following algorithm to work, we need to know that F(x) is strictly
	 * decreasing (the slope is always negative).  The slope is
	 *	F'(x) = 12 x^2 - 6 b x - 4 a^2
	 * (the derivative).  It is a parabola opening upward and going through
	 * (0, -4a^2) and (b/2, -4a^2).  So it is always negative in this
	 * interval.
	 *
	 * The algorithm starts with lo = 0 and hi = b/2.  It draws a straight
	 * line between (lo, F(lo)) and (hi, F(hi)).  The point where this
	 * crosses the X axis we call "mid".  Based on whether F(mid) is
	 * positive or negative, we reset lo or hi to mid, and repeat the
	 * process until F(mid) is within b/1000 of the axis.  Then we will use
	 * mid as our y value in the picture.
	 */
	a = ABSDIFF(first_p->x, last_p->x) / 2.0;
	b = ABSDIFF(first_p->y, last_p->y);

	midoff= solvecubic(4.0, -3.0*b, -4.0*a*a, a*a*b, 0.0, b/2.0, POINT/2.0);

	mid_p = first_p->next;
	mid_p->x = first_p->x + a;	/* horizontally halfway between */

	/* handle the 4 cases, using the "mid" value for y in the diagram */
	if (place == PL_ABOVE) {
		if (first_p->y < last_p->y) {
			mid_p->y = last_p->y - midoff;
		} else {
			mid_p->y = first_p->y - midoff;
		}
	} else {
		if (first_p->y < last_p->y) {
			mid_p->y = first_p->y + midoff;
		} else {
			mid_p->y = last_p->y + midoff;
		}
	}
}


/* do final refinements of curve.
 * Remove any really tiny line segments.
 * Then reset the group north or south boundaries to reflect
 * the inclusion of the phrase mark.
 */

static void
final_touches(mll_p, begin_gs_p, end_gs_p, curvelist_p, place)

struct MAINLL *mll_p;			/* points to first group in curve */
struct GRPSYL *begin_gs_p;		/* first group in curve */
struct GRPSYL *end_gs_p;		/* last group in curve */
struct CRVLIST *curvelist_p;		/* the curve */
int place;				/* PL_ABOVE or PL_BELOW */

{
	int voice;	
	int staff;
	int index;	/* in coord array: RN or RS */
	int adj_index;	/* in coord array: AN or AS. Used to store how much
			 * to adjust for this phrase, in case there are
			 * nested phrases. */
	float y_c;	/* y of curve */
	float x1, y1;	/* lengths of segments in each dimension */
	float length;	/* of line segment */
	struct CRVLIST *crvlist_p;
	struct CRVLIST *extra_p;	/* pointer to point to be freed */
	struct GRPSYL *gs_p;	/* index through groups */


	if ( (mll_p == (struct MAINLL *) 0)
			|| (begin_gs_p == (struct GRPSYL *) 0)
			|| (end_gs_p == (struct GRPSYL *) 0)
			|| (curvelist_p == (struct CRVLIST *) 0) ) {
		pfatal("null pointer in final_touches()");
	}

	if (begin_gs_p->vno != end_gs_p->vno) {
		/* Must be a tie/slue to another voice. We don't attempt
		 * to try to avoid anything that is in the way. */
		return;
	}

	/* If there are really tiny line segments in a curve, the code for
	 * tapering the curve has problems because if the width of the curve
	 * is more than the length of the line and the angles work out just
	 * wrong, various warts, sometimes huge ones, appear on the curves.
	 * So go through the curve and if there are any really tiny lines,
	 * throw away one of the points and make the remaining point the
	 * average of what it was and what the discarded one was.
	 * With the new way of calculating curves, this is probably now
	 * unnecessary, but it seems safer to leave it in, just in case.
	 */
	for (crvlist_p = curvelist_p; crvlist_p->next != (struct CRVLIST *) 0;
						crvlist_p = crvlist_p->next) {
		x1 = crvlist_p->next->x - crvlist_p->x;
		y1 = crvlist_p->next->y - crvlist_p->y;
		length = sqrt(SQUARED(x1) + SQUARED(y1));
		if (length < 0.01) {
			/* replace with average */
			crvlist_p->x = (crvlist_p->x + crvlist_p->next->x)
								/ 2.0;
			crvlist_p->y = (crvlist_p->y + crvlist_p->next->y)
								/ 2.0;
			/* take the extra out of the list */
			extra_p = crvlist_p->next;
			if (crvlist_p->next->next != (struct CRVLIST *) 0) {
				crvlist_p->next->next->prev = crvlist_p;
			}
			crvlist_p->next = crvlist_p->next->next;
			if (crvlist_p->next == (struct CRVLIST *) 0) {
				/* avoid trying to take ->next of null ptr */
				break;
			}
			FREE(extra_p);
		}
	}

	/* adjust north or south of each group within the curve to account for
	 * the space needed for the curve */
	voice = begin_gs_p->vno;
	staff = begin_gs_p->staffno;
	if (place == PL_ABOVE) {
		index = RN;
		adj_index = AN;
	}
	else {
		index = RS;
		adj_index = AS;
	}

	for (gs_p = begin_gs_p;     ; gs_p = gs_p->next) {

		/* if hit end of measure go to next measure, skipping over
		 * any empty measure (which could happen if vscheme changed
		 * from 2 to 1 and back in the middle of the phrase) */
		while (gs_p == (struct GRPSYL *) 0) {
			mll_p = next_staff(staff, mll_p->next);
			if (mll_p == (struct MAINLL *) 0) {
				pfatal("fell off end of list while doing phrase marks");
			}
			gs_p = mll_p->u.staff_p->groups_p[voice - 1];
		}

		/* find where the curve y is at the x of the group, and
		 * adjust the north or south of the group appropriately,
		 * to be used later by any nesting phrase marks */
		y_c = curve_y_at_x(curvelist_p, gs_p->c[AX]);

		/* check for an inner tie. They don't affect the boundary */
		if ( ((index == RN) && (y_c < gs_p->c[index])) ||
				((index == RS) && (y_c > gs_p->c[index]))) {
			gs_p->c[adj_index] = 0.0;
		}
		else {
			if (place == PL_ABOVE) {
				gs_p->c[adj_index] = (y_c - gs_p->c[index]
								+ Stepsize);
			}
			else {
				gs_p->c[adj_index] =  - (gs_p->c[index] - y_c
								+ Stepsize);
			}
		}

		if (gs_p == end_gs_p) {
			/* On the last group on the phrase, this phrase
			 * only affects the west side--another phrase can
			 * start on this same group with considering this one */
			gs_p->phraseside |= WEST_SIDE;
			/* We are done with this curve */
			break;
		}
		else if (gs_p == begin_gs_p){
			/* Only affects east side of first group */
			gs_p->phraseside |= EAST_SIDE;
		}
		else {
			/* not of the end, so both side are relevant */
			gs_p->phraseside |= (EAST_SIDE | WEST_SIDE);
		}
	}
}


/* Determine effective tuplet extension value. Normally, the tupext tells
 * us how much room to leave to allow for the tuplet bracket. However,
 * if the tuplet doesn't get a bracket, this can cause us to leave extra
 * space. We do still need to leave room for the tuplet number
 * even if the bracket isn't there. And the bracket is not quite as tall
 * as the number, so away from the number we can get a little bit closer.
 * We only adjust the tupext value if the group
 * is west or east of the number. This is only done approximately.
 * We find the east and west of the number and add 2 Stepsizes on each side,
 * and if any part of the group would fall inside there, we use the full
 * tupextend if there is no bracket, or 75% of tupextend if there is a bracket.
 * In theory, when we are close to the number,
 * we could calculate a value between zero and tupext that would allow just
 * enough room to clear the number, if we knew exactly what angle the phrase
 * was going to have. But at this point we're still trying to determine that.
 * And usually the approximation will be good enough.
 * Worst case we should either bulge a little too much or slightly clip the
 * number with the phrase mark, so if we're off once in a while,
 * it shouldn't be too bad.
 * But if this isn't a tuplet, or its bracket is on the opposite side
 * as where we're trying to put a curve, then it doesn't count as all.
 */

static double
eff_tupext(gs_p, staff_p, side)

struct GRPSYL *gs_p;
struct STAFF *staff_p;
int side;		/* where the curve will be */

{
	struct GRPSYL *firstgs_p;	/* first group of tuplet */
	float west, east, height;	/* boundary of tuplet number */

	/* if not a tuplet, return tupextend as is */
	if (gs_p->tuploc == NOITEM) {
		return(gs_p->tupextend);
	}

	/* if curve is on opposite side as tuplet bracket, ignore tupextend */
	if (side != tupdir(gs_p, staff_p)) {
		return(0.0);
	}
	for (firstgs_p = gs_p; firstgs_p->tuploc != STARTITEM &&
					firstgs_p->tuploc != LONEITEM;
					firstgs_p = firstgs_p->prev) {
		;
	}
	(void) tupnumsize(firstgs_p, &west, &east, &height, staff_p);
	if (gs_p->c[AE] < west - 2.0 * Stepsize
				|| gs_p->c[AW] > east + 2.0 * Stepsize) {
		if (tupgetsbrack(firstgs_p) == YES) {
			return(0.75 * gs_p->tupextend);
		}
		else {
			return(0.0);
		}
	}


	/* if no special case applies, just return tupextend as is */
	return(gs_p->tupextend);
}


/* determine correct bend direction for curve, return UP or DOWN */

static int
bulge_direction(mll_p, gs1_p, note_index, curveno)

struct MAINLL *mll_p;	/* main list struct pointing to gs1_p */
struct GRPSYL *gs1_p;	/* curve will be from note in gs1_p to note in gs2_p */
int note_index;		/* which note in first group to tie */
int curveno;		/* index into slurto, or -1 for a tie */

{
	struct GRPSYL *gs_p;
	RATIONAL vtime1, vtime2;	/* beginning and ending time of group */
	int othervoice;			/* array index of other voice */


	/* If user explicitly set a bend direction, use that */
	if (curveno == -1 && gs1_p->notelist[note_index].tiedir != UNKNOWN) {
		return(gs1_p->notelist[note_index].tiedir);
	}
	else if (curveno >= 0 && gs1_p->notelist[note_index]
				.slurtolist[curveno].slurdir != UNKNOWN) {
		return(gs1_p->notelist[note_index].slurtolist[curveno].slurdir);
	}

	/* If there are 2 voices on the staff, bend is toward the stem */
	/* However, if the other voice is all spaces, pretend there is only
	 * one voice */
	if ( (mll_p->u.staff_p->groups_p[0] != (struct GRPSYL *) 0)
				&& (mll_p->u.staff_p->groups_p[1]
				!= (struct GRPSYL *) 0) ) {

		/* there are 2 voices */

		/* calculate begin and end time of tied group */
		vtime1 = Zero;
		for (gs_p = mll_p->u.staff_p->groups_p[gs1_p->vno - 1];
					gs_p != gs1_p; gs_p = gs_p->next) {
			vtime1 = radd(vtime1, gs_p->fulltime);
		}

		/* ending time is vtime1 plus the length of group 1. If group
		 * 1 is a grace note, use a very short time */
		if (EQ(gs1_p->fulltime, Zero)) {
			RATIONAL tiny;

			tiny.n = 1;
			tiny.d = 4 * MAXBASICTIME;
			vtime2 = radd(vtime1, tiny);
		}
		else {
			vtime2 = radd(vtime1, gs1_p->fulltime);
		}

		/* get array index of other voice to check it */
		othervoice = (gs1_p->vno == 1 ? 1 : 0);

		if (hasspace(mll_p->u.staff_p->groups_p[othervoice],
					vtime1, vtime2) == NO) {
			/* there IS another voice, so stem goes opposite */
			return(gs1_p->stemdir);
		}
	}

	/* if only one voice (either because there is actually only one
	 * or because there is effectively only one since the other is space)
	 * and there is only one note in group, then bend is opposite stem */
	if (gs1_p->nnotes < 2) {
		/* quarter note grace groups are a special case, since they
		 * don't have a stem (they are for showing prebends). So we
		 * put the bend opposite the stem of the following group. */
		if (gs1_p->grpvalue == GV_ZERO && gs1_p->basictime == 4 &&
				gs1_p->next != (struct GRPSYL *) 0) {
			return(gs1_p->next->stemdir == UP ? DOWN : UP);
		}
		return(gs1_p->stemdir == UP ? DOWN : UP);
	}
	
	/* if one voice on staff with more than one note in the group, all
	 * bend opposite the stem except the top if the stem is up or the
	 * bottom if the stem is down */
	if ( ((gs1_p->stemdir == DOWN) && (note_index == gs1_p->nnotes - 1))
			|| ((gs1_p->stemdir == UP) && (note_index == 0)) ) {
		return(gs1_p->stemdir);
	}
	else {
		return(gs1_p->stemdir == UP ? DOWN : UP);
	}
}
