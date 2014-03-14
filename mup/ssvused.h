/* Copyright (c) 2001, 2003, 2004, 2006, 2007, 2008, 2009
 * by Arkkra Enterprises */
/* All rights reserved */

#ifndef _SSVUSED_H
#define _SSVUSED_H

/*
 * This file contains the array subscript definitions for the used[] array
 * of an SSV struct. An SSV contains parameters associated with a
 * Score, Staff, or Voice.  The used[] array is a set of flags which say
 * whether a given parameter is actually populated in the SSV instance.
 * In the "score" SSV, all used flags are always set true.  In SSVs for
 * a staff or voice, a "used" flag is only set to true if the user
 * specified a value for the parameter in that staff or voice context.
 *
 * The actual values are machine-generated so they get automatically
 * renumbered if parameters are added or deleted or rearranged.
 *
 * We try to put things that are logically similar close together in
 * this list, but they could be in any order, other than that NUMFLDS
 * _must_ be last.
 */

#define	SCALE_FACTOR		(0)
#define	UNITS			(1)
#define	PAGEHEIGHT		(2)
#define	PAGEWIDTH		(3)
#define	PANELSPERPAGE		(4)
#define	MAXSCORES		(5)
#define	MAXMEASURES		(6)
#define	SLASHESBETWEEN		(7)
#define	TOPMARGIN		(8)
#define	BOTMARGIN		(9)
#define	LEFTMARGIN		(10)
#define	RIGHTMARGIN		(11)
#define	RESTCOMBINE		(12)
#define	FIRSTPAGE		(13)
#define	NUMSTAFF		(14)
#define	MINSCSEP		(15)
#define	MAXSCSEP		(16)
#define	MINSCPAD		(17)
#define	MAXSCPAD		(18)
#define	BRACELIST		(19)
#define	BRACKLIST		(20)
#define	BARSTLIST		(21)
#define	TIME			(22)
#define	DIVISION		(23)
#define	ENDINGSTYLE		(24)
#define	GRIDSATEND		(25)
#define	MEASNUM			(26)
#define	MEASNUMFAMILY		(27)
#define	MEASNUMFONT		(28)
#define	MEASNUMSIZE		(29)
#define	MEASNUMSTYLE		(30)
#define	BRACKETREPEATS		(31)
#define	PACKFACT		(32)
#define	PACKEXP			(33)
#define	WARN			(34)
#define	STAFFSCALE		(35)
#define	VISIBLE			(36)
#define	STAFFLINES		(37)
#define	GRIDSWHEREUSED		(38)
#define	GRIDSCALE		(39)
#define	GRIDFRET		(40)
#define	MINGRIDHEIGHT		(41)
#define	NUMBERMRPT		(42)
#define	PRINTMULTNUM		(43)
#define	RESTSYMMULT		(44)
#define	VSCHEME			(45)
#define	VCOMBINE		(46)
#define	SHARPS			(47)
#define	CANCELKEY		(48)
#define	TRANSPOSITION		(49)
#define	ADDTRANSPOSITION	(50)
#define	USEACCS			(51)
#define	CARRYACCS		(52)
#define	CLEF			(53)
#define	REHSTYLE		(54)
#define	REPEATDOTS		(55)
#define	FONTFAMILY		(56)
#define	FONT			(57)
#define	SIZE			(58)
#define	REHFAMILY		(59)
#define	REHFONT			(60)
#define	REHSIZE			(61)
#define	LYRICSFAMILY		(62)
#define	LYRICSFONT		(63)
#define	LYRICSSIZE		(64)
#define	LYRICSALIGN		(65)
#define	SYLPOSITION		(66)
#define	MINSTSEP		(67)
#define	STAFFPAD		(68)
#define	ABOVEORDER		(69)
#define	BELOWORDER		(70)
#define	BETWEENORDER		(71)
#define	PEDSTYLE		(72)
#define	CHORDDIST		(73)
#define	DIST			(74)
#define	DYNDIST			(75)
#define	LYRICSDIST		(76)
#define	LABEL			(77)
#define	LABEL2			(78)
#define	BEAMSTLIST		(79)
#define	BEAMSLOPE		(80)
#define	PAD			(81)
#define	STEMLEN			(82)
#define	BEAMSHORT		(83)
#define	MAXPROSHORT		(84)
#define	BEGPROSHORT		(85)
#define	ENDPROSHORT		(86)
#define	DEFOCT			(87)
#define	TIMEUNIT		(88)
#define	SWINGUNIT		(89)
#define	WITHFAMILY		(90)
#define	WITHFONT		(91)
#define	WITHSIZE		(92)
#define	ALIGNRESTS		(93)
#define	RELEASE			(94)
#define	ONTHELINE		(95)
#define	TABWHITEBOX		(96)
#define	NOTEHEADS		(97)
#define	EMPTYMEAS		(98)
#define	NUMFLDS			(99)

#endif
