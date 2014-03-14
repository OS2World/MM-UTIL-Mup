
/* Copyright (c) 1995, 1999, 2000, 2004 by Arkkra Enterprises */
/* All rights reserved */

/*
 * Define the list of all the special music symbols.
 */

/* The following set of symbols is in font FONT_MUSIC.
 * Mapping between name and number is done via Sym2code_table[0][].
 */
#define C_GCLEF 	(32)	 /* G clef (treble clef) */
#define C_FCLEF 	(33)	 /* F clef (bass clef) */
#define C_CCLEF 	(34)	 /* C clef (alto, tenor, etc. clef) */
#define C_DBLWHOLE 	(35)	 /* double whole note */
#define C_1N 		(36)	 /* whole note */
#define C_2N 		(37)	 /* half note head */
#define C_4N 		(38)	 /* quarter (and shorter) note head */
#define C_UPFLAG 	(39)	 /* upward flag */
#define C_DNFLAG 	(40)	 /* downward flag */
#define C_QWHREST 	(41)	 /* quad rest */
#define C_DWHREST 	(42)	 /* double whole rest */
#define C_1REST 	(43)	 /* whole rest */
#define C_2REST 	(44)	 /* half rest */
#define C_4REST 	(45)	 /* quarter rest */
#define C_8REST 	(46)	 /* eighth rest */
#define C_16REST 	(47)	 /* sixteenth rest */
#define C_32REST 	(48)	 /* thirty-second rest */
#define C_64REST 	(49)	 /* sixty-fourth rest */
#define C_128REST 	(50)	 /* 128th rest */
#define C_256REST 	(51)	 /* 256th rest */
#define C_LL1REST 	(52)	 /* legerline-less version of whole rest */
#define C_LL2REST 	(53)	 /* legerline-less version of half rest */
#define C_DOT 		(54)	 /* dot, as for after a note */
#define C_NAT 		(55)	 /* natural sign (n) */
#define C_SHARP 	(56)	 /* sharp sign (#) */
#define C_FLAT 		(57)	 /* flat sign (&) */
#define C_DBLSHARP 	(58)	 /* double sharp */
#define C_DBLFLAT 	(59)	 /* double flat */
#define C_XNOTE 	(60)	 /* X-shaped note head */
#define C_DWHDIAMOND 	(61)	 /* double-whole diamond shaped note */
#define C_DIAMOND 	(62)	 /* diamond-shaped note head */
#define C_FILLDIAMOND 	(63)	 /* filled diamond note head */
#define C_UP2N 		(64)	 /* half note with stem up */
#define C_DN2N 		(65)	 /* half note with stem down */
#define C_UP4N 		(66)	 /* quarter note with stem up */
#define C_DN4N 		(67)	 /* quarter note with stem down */
#define C_COM 		(68)	 /* common time */
#define C_CUT 		(69)	 /* cut time */
#define C_BEGPED 	(70)	 /* begin pedal */
#define C_PEDAL 	(71)	 /* pedal up/down */
#define C_ENDPED 	(72)	 /* end pedal */
#define C_DNBOW 	(73)	 /* down bow */
#define C_UPBOW 	(74)	 /* up bow */
#define C_WEDGE 	(75)	 /* wedge mark */
#define C_UWEDGE 	(76)	 /* upside-down wedge */
#define C_FERM 		(77)	 /* fermata */
#define C_UFERM 	(78)	 /* upside-down fermata */
#define C_SIGN 		(79)	 /* for D.S. */
#define C_CODA 		(80)	 /* the + over circle for jumping to coda */
#define C_MOR 		(81)	 /* mordent */
#define C_INVMOR 	(82)	 /* inverted mordent */
#define C_TURN 		(83)	 /* "turn" ornament */
#define C_INVTURN 	(84)	 /* inverted turn */
#define C_ACC_GT 	(85)	 /* accent that looks like > */
#define C_ACC_HAT 	(86)	 /* accent that looks like ^ */
#define C_ACC_UHAT 	(87)	 /* upside down hat accent */
#define C_TR 		(88)	 /* trill */
#define C_LEG 		(89)	 /* legato mark */
#define C_RR 		(90)	 /* railroad tracks */
#define C_DIM 		(91)	 /* diminished (small circle) */
#define C_HALFDIM 	(92)	 /* half diminished (small circle with slash) */
#define C_TRIANGLE 	(93)	 /* triangle, as for a major 7th chord */
#define C_MEASRPT 	(94)	 /* measure repeat */
#define C_COPYRIGHT 	(95)	 /* c in circle */
#define C_UP8N 		(96)	 /* 1/8 note with stem up */
#define C_DN8N 		(97)	 /* 1/8 note with stem down */
#define C_UP16N 	(98)	 /* 1/16 note with stem up */
#define C_DN16N 	(99)	 /* 1/16 note with stem down */
#define C_UP32N 	(100)	 /* 1/32 note with stem up */
#define C_DN32N 	(101)	 /* 1/32 note with stem down */
#define C_UP64N 	(102)	 /* 1/64 note with stem up */
#define C_DN64N 	(103)	 /* 1/64 note with stem down */
#define C_UP128N 	(104)	 /* 1/128 note with stem up */
#define C_DN128N 	(105)	 /* 1/128 note with stem down */
#define C_UP256N 	(106)	 /* 1/256 note with stem up */
#define C_DN256N 	(107)	 /* 1/256 note with stem down */

/* The following set of symbols is in font FONT_MUSIC2.
 * Mapping between name and number is done via Sym2code_table[1][].
 */
#define C_DWHRIGHTTRIANGLE 	(32)	 /* double whole right triangle */
#define C_RIGHTTRIANGLE 	(33)	 /* hollow right triangle */
#define C_FILLRIGHTTRIANGLE 	(34)	 /* filled right triangle */
#define C_UDWHRIGHTTRIANGLE 	(35)	 /* upside down double whole right tri*/
#define C_URIGHTTRIANGLE 	(36)	 /* upside down hollow right triangle */
#define C_UFILLRIGHTTRIANGLE 	(37)	 /* upside down filled right triangle */
#define C_DWHRECTANGLE 	(38)	 /* double whole rectangle */
#define C_RECTANGLE 	(39)	 /* hollow rectangle */
#define C_FILLRECTANGLE 	(40)	 /* filled rectangle */
#define C_DWHISOSTRIANGLE 	(41)	 /* double whole isosceles triangle */
#define C_ISOSTRIANGLE 	(42)	 /* hollow isosceles triangle */
#define C_FILLISOSTRIANGLE 	(43)	 /* filled isosceles triangle */
#define C_DWHPIEWEDGE 	(44)	 /* double whole pie wedge */
#define C_PIEWEDGE 	(45)	 /* hollow pie wedge */
#define C_FILLPIEWEDGE 	(46)	 /* filled pie wedge */
#define C_DWHSEMICIRCLE 	(47)	 /* double whole semicircle */
#define C_SEMICIRCLE 	(48)	 /* hollow semicircle */
#define C_FILLSEMICIRCLE 	(49)	 /* filled semicircle */
#define C_DWHSLASHHEAD 	(50)	 /* double whole slash note head */
#define C_SLASHHEAD 	(51)	 /* hollow slash note head */
#define C_FILLSLASHHEAD 	(52)	 /* filled slash note head */
#define C_BLANKHEAD 	(53)	 /* blank note head */
