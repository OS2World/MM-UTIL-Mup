/* Copyright (c) 2009 by Arkkra Enterprises */
/* All rights reserved */

/* Machine generated metrics information about the music symbol fonts */

#include "defines.h"
#include "structs.h"
#include "globals.h"

char *FI_mus1_names[] = {
 "gclef", "fclef", "cclef", "dblwhole",
 "1n", "2n", "4n", "upflag",
 "dnflag", "qwhrest", "dwhrest", "1rest",
 "2rest", "4rest", "8rest", "16rest",
 "32rest", "64rest", "128rest", "256rest",
 "ll1rest", "ll2rest", "dot", "nat",
 "sharp", "flat", "dblsharp", "dblflat",
 "xnote", "dwhdiamond", "diamond", "filldiamond",
 "up2n", "dn2n", "up4n", "dn4n",
 "com", "cut", "begped", "pedal",
 "endped", "dnbow", "upbow", "wedge",
 "uwedge", "ferm", "uferm", "sign",
 "coda", "mor", "invmor", "turn",
 "invturn", "acc_gt", "acc_hat", "acc_uhat",
 "tr", "leg", "rr", "dim",
 "halfdim", "triangle", "measrpt", "copyright",
 "up8n", "dn8n", "up16n", "dn16n",
 "up32n", "dn32n", "up64n", "dn64n",
 "up128n", "dn128n", "up256n", "dn256n"};
short FI_M1_widths[] = {
 272, 279, 237, 147,
 145, 118, 112, 84,
 84, 70, 70, 237,
 237, 113, 127, 138,
 154, 168, 181, 197,
 140, 140, 62, 95,
 120, 104, 123, 184,
 118, 155, 118, 118,
 145, 145, 141, 140,
 176, 176, 61, 140,
 62, 136, 123, 70,
 70, 251, 251, 209,
 251, 206, 206, 204,
 204, 186, 131, 131,
 223, 140, 154, 98,
 129, 134, 204, 151,
 216, 140, 216, 140,
 216, 140, 216, 140,
 216, 140, 216, 140};
short FI_M1_heights[] = {
 666, 352, 372, 166,
 91, 94, 91, 236,
 236, 194, 111, 116,
 75, 286, 177, 261,
 344, 386, 469, 552,
 113, 72, 61, 263,
 286, 236, 122, 236,
 100, 194, 83, 83,
 366, 366, 365, 365,
 205, 277, 116, 97,
 116, 152, 169, 95,
 95, 166, 166, 255,
 263, 105, 152, 119,
 119, 122, 147, 147,
 166, 41, 172, 152,
 168, 140, 213, 150,
 365, 365, 365, 365,
 431, 431, 498, 498,
 565, 565, 623, 623};
short FI_M1_ascents[] = {
 430, 102, 186, 83,
 45, 47, 45, 236,
 0, 97, 97, 101,
 55, 150, 79, 79,
 162, 162, 245, 245,
 98, 56, 30, 131,
 143, 166, 61, 166,
 50, 97, 41, 41,
 305, 61, 305, 59,
 102, 138, 97, 91,
 97, 138, 140, 83,
 81, 152, 152, 127,
 131, 52, 76, 59,
 59, 61, 133, 133,
 152, 20, 155, 137,
 152, 120, 106, 130,
 305, 59, 305, 59,
 372, 59, 438, 59,
 505, 59, 563, 59};
int FI_mus1_numchars = 76;
char *FI_mus2_names[] = {
 "dwhrighttriangle", "righttriangle", "fillrighttriangle", "udwhrighttriangle",
 "urighttriangle", "ufillrighttriangle", "dwhrectangle", "rectangle",
 "fillrectangle", "dwhisostriangle", "isostriangle", "fillisostriangle",
 "dwhpiewedge", "piewedge", "fillpiewedge", "dwhsemicircle",
 "semicircle", "fillsemicircle", "dwhslashhead", "slashhead",
 "fillslashhead", "blankhead"};
short FI_M2_widths[] = {
 127, 118, 118, 127,
 118, 118, 127, 118,
 118, 127, 118, 118,
 127, 118, 118, 127,
 118, 118, 191, 187,
 176, 118};
short FI_M2_heights[] = {
 166, 79, 79, 166,
 79, 79, 166, 75,
 75, 166, 79, 79,
 166, 79, 79, 166,
 79, 79, 200, 200,
 186, 75};
short FI_M2_ascents[] = {
 83, 37, 37, 83,
 41, 41, 83, 37,
 37, 83, 41, 41,
 83, 37, 37, 83,
 37, 37, 100, 100,
 93, 37};
int FI_mus2_numchars = 22;


void
init_musfont_metrics()
{
	int index;

	index = FONT_MUSIC - 1;
	Fontinfo[index].ps_name = "mfont1";
	Fontinfo[index].numchars = FI_mus1_numchars;
	Fontinfo[index].charnames = FI_mus1_names;
	Fontinfo[index].ch_width = FI_M1_widths;
	Fontinfo[index].ch_height = FI_M1_heights;
	Fontinfo[index].ch_ascent = FI_M1_ascents;
	Fontinfo[index].is_ital = NO;
	index = FONT_MUSIC2 - 1;
	Fontinfo[index].ps_name = "mfont2";
	Fontinfo[index].numchars = FI_mus2_numchars;
	Fontinfo[index].charnames = FI_mus2_names;
	Fontinfo[index].ch_width = FI_M2_widths;
	Fontinfo[index].ch_height = FI_M2_heights;
	Fontinfo[index].ch_ascent = FI_M2_ascents;
	Fontinfo[index].is_ital = NO;
}
