/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_1ARG_FUNC = 258,
     T_2ARG_FUNC = 259,
     T_2FNUMVAR = 260,
     T_ADDSUB_OP = 261,
     T_ALIGN = 262,
     T_ALL = 263,
     T_ALT = 264,
     T_AMPERSAND = 265,
     T_AUTO = 266,
     T_BARSTLISTVAR = 267,
     T_BARTYPE = 268,
     T_BBOX = 269,
     T_BLOCKHEAD = 270,
     T_BM = 271,
     T_BULGE = 272,
     T_CLEF = 273,
     T_CLEFVAR = 274,
     T_COLON = 275,
     T_COMMA = 276,
     T_COMMON = 277,
     T_CUE = 278,
     T_CURVE = 279,
     T_CUT = 280,
     T_DASH = 281,
     T_DBLFLAT = 282,
     T_DIAM = 283,
     T_DOT = 284,
     T_DOWN = 285,
     T_DRUM = 286,
     T_EBM = 287,
     T_EM_BEGIN = 288,
     T_EM_END = 289,
     T_ENDENDING = 290,
     T_ENDING = 291,
     T_ENDSTYLE = 292,
     T_ENDTYPE = 293,
     T_EPH = 294,
     T_EQUAL = 295,
     T_ESBM = 296,
     T_EVERY = 297,
     T_EXCLAM = 298,
     T_FAMILY = 299,
     T_FFAMILY = 300,
     T_FNUMVAR = 301,
     T_FONT = 302,
     T_FONTVAR = 303,
     T_GRACE = 304,
     T_GRIDS = 305,
     T_HAT = 306,
     T_HEADSHAPES = 307,
     T_HIDECHANGES = 308,
     T_HO = 309,
     T_HS = 310,
     T_KEY = 311,
     T_LBRACE = 312,
     T_LBRACKET = 313,
     T_LEN = 314,
     T_LET = 315,
     T_LETTER = 316,
     T_LET_M = 317,
     T_LET_N = 318,
     T_LET_R = 319,
     T_LET_S = 320,
     T_LET_U = 321,
     T_LET_X = 322,
     T_LINE = 323,
     T_LINETYPE = 324,
     T_LPAREN = 325,
     T_LVAR = 326,
     T_LYRICS = 327,
     T_L_ANGLE = 328,
     T_L_DBLANGLE = 329,
     T_MEASNUM = 330,
     T_MIDI = 331,
     T_MNUM = 332,
     T_MODIFIER = 333,
     T_MULDIV_OP = 334,
     T_MULTIREST = 335,
     T_MULTIWHOLE = 336,
     T_MUSIC = 337,
     T_MUSSYM = 338,
     T_NEWLINE = 339,
     T_NL = 340,
     T_NONE = 341,
     T_NONNAT = 342,
     T_NOWHERE_SLIDE = 343,
     T_NUM = 344,
     T_NUMBER = 345,
     T_NUMVAR = 346,
     T_OCTAVE = 347,
     T_ORDER = 348,
     T_ORIENTATION = 349,
     T_OTHERTEXT = 350,
     T_PAD = 351,
     T_PAGESIZE = 352,
     T_PARAGRAPH = 353,
     T_PARATYPE = 354,
     T_PEDAL = 355,
     T_PEDSTAR = 356,
     T_PEDSTYLE = 357,
     T_PH = 358,
     T_PHRASE = 359,
     T_PITCH = 360,
     T_PLACE = 361,
     T_PLUS = 362,
     T_POSTSCRIPT = 363,
     T_PRINTTYPE = 364,
     T_PSVAR = 365,
     T_QUESTION = 366,
     T_RANGELISTVAR = 367,
     T_RATNUMLISTVAR = 368,
     T_RBRACE = 369,
     T_RBRACKET = 370,
     T_REHEARSAL = 371,
     T_REHTYPE = 372,
     T_REH_STYLE = 373,
     T_REPEATDOTS = 374,
     T_ROLL = 375,
     T_RPAREN = 376,
     T_RPT = 377,
     T_R_ANGLE = 378,
     T_R_DBLANGLE = 379,
     T_SCORE = 380,
     T_SCOREFEED = 381,
     T_SCOREPAD = 382,
     T_SCORESEP = 383,
     T_SEMICOLON = 384,
     T_SHARP = 385,
     T_SHORTEN = 386,
     T_SLASH = 387,
     T_SLASHMARK = 388,
     T_SLOPE = 389,
     T_SLUR = 390,
     T_STAFF = 391,
     T_STAFFLINES = 392,
     T_STANDARD = 393,
     T_STAR = 394,
     T_STEMOFFSET = 395,
     T_STRING = 396,
     T_STRVAR = 397,
     T_SWINGUNIT = 398,
     T_SYMBOL = 399,
     T_TAB = 400,
     T_TICKS = 401,
     T_TIE = 402,
     T_TIL = 403,
     T_TILDE = 404,
     T_TIME = 405,
     T_TIMEUNIT = 406,
     T_TITLE = 407,
     T_TO = 408,
     T_TRANSPOSE = 409,
     T_UNITS = 410,
     T_UNITTYPE = 411,
     T_UNSET = 412,
     T_UP = 413,
     T_USEACCS = 414,
     T_VCOMBINE = 415,
     T_VCOMBVAL = 416,
     T_VISVAR = 417,
     T_VOICE = 418,
     T_VVAR = 419,
     T_WHEREUSED = 420,
     T_WITH = 421,
     T_XNOTE = 422,
     T_XPOS_INT = 423,
     T_YESNOVAR = 424
   };
#endif
/* Tokens.  */
#define T_1ARG_FUNC 258
#define T_2ARG_FUNC 259
#define T_2FNUMVAR 260
#define T_ADDSUB_OP 261
#define T_ALIGN 262
#define T_ALL 263
#define T_ALT 264
#define T_AMPERSAND 265
#define T_AUTO 266
#define T_BARSTLISTVAR 267
#define T_BARTYPE 268
#define T_BBOX 269
#define T_BLOCKHEAD 270
#define T_BM 271
#define T_BULGE 272
#define T_CLEF 273
#define T_CLEFVAR 274
#define T_COLON 275
#define T_COMMA 276
#define T_COMMON 277
#define T_CUE 278
#define T_CURVE 279
#define T_CUT 280
#define T_DASH 281
#define T_DBLFLAT 282
#define T_DIAM 283
#define T_DOT 284
#define T_DOWN 285
#define T_DRUM 286
#define T_EBM 287
#define T_EM_BEGIN 288
#define T_EM_END 289
#define T_ENDENDING 290
#define T_ENDING 291
#define T_ENDSTYLE 292
#define T_ENDTYPE 293
#define T_EPH 294
#define T_EQUAL 295
#define T_ESBM 296
#define T_EVERY 297
#define T_EXCLAM 298
#define T_FAMILY 299
#define T_FFAMILY 300
#define T_FNUMVAR 301
#define T_FONT 302
#define T_FONTVAR 303
#define T_GRACE 304
#define T_GRIDS 305
#define T_HAT 306
#define T_HEADSHAPES 307
#define T_HIDECHANGES 308
#define T_HO 309
#define T_HS 310
#define T_KEY 311
#define T_LBRACE 312
#define T_LBRACKET 313
#define T_LEN 314
#define T_LET 315
#define T_LETTER 316
#define T_LET_M 317
#define T_LET_N 318
#define T_LET_R 319
#define T_LET_S 320
#define T_LET_U 321
#define T_LET_X 322
#define T_LINE 323
#define T_LINETYPE 324
#define T_LPAREN 325
#define T_LVAR 326
#define T_LYRICS 327
#define T_L_ANGLE 328
#define T_L_DBLANGLE 329
#define T_MEASNUM 330
#define T_MIDI 331
#define T_MNUM 332
#define T_MODIFIER 333
#define T_MULDIV_OP 334
#define T_MULTIREST 335
#define T_MULTIWHOLE 336
#define T_MUSIC 337
#define T_MUSSYM 338
#define T_NEWLINE 339
#define T_NL 340
#define T_NONE 341
#define T_NONNAT 342
#define T_NOWHERE_SLIDE 343
#define T_NUM 344
#define T_NUMBER 345
#define T_NUMVAR 346
#define T_OCTAVE 347
#define T_ORDER 348
#define T_ORIENTATION 349
#define T_OTHERTEXT 350
#define T_PAD 351
#define T_PAGESIZE 352
#define T_PARAGRAPH 353
#define T_PARATYPE 354
#define T_PEDAL 355
#define T_PEDSTAR 356
#define T_PEDSTYLE 357
#define T_PH 358
#define T_PHRASE 359
#define T_PITCH 360
#define T_PLACE 361
#define T_PLUS 362
#define T_POSTSCRIPT 363
#define T_PRINTTYPE 364
#define T_PSVAR 365
#define T_QUESTION 366
#define T_RANGELISTVAR 367
#define T_RATNUMLISTVAR 368
#define T_RBRACE 369
#define T_RBRACKET 370
#define T_REHEARSAL 371
#define T_REHTYPE 372
#define T_REH_STYLE 373
#define T_REPEATDOTS 374
#define T_ROLL 375
#define T_RPAREN 376
#define T_RPT 377
#define T_R_ANGLE 378
#define T_R_DBLANGLE 379
#define T_SCORE 380
#define T_SCOREFEED 381
#define T_SCOREPAD 382
#define T_SCORESEP 383
#define T_SEMICOLON 384
#define T_SHARP 385
#define T_SHORTEN 386
#define T_SLASH 387
#define T_SLASHMARK 388
#define T_SLOPE 389
#define T_SLUR 390
#define T_STAFF 391
#define T_STAFFLINES 392
#define T_STANDARD 393
#define T_STAR 394
#define T_STEMOFFSET 395
#define T_STRING 396
#define T_STRVAR 397
#define T_SWINGUNIT 398
#define T_SYMBOL 399
#define T_TAB 400
#define T_TICKS 401
#define T_TIE 402
#define T_TIL 403
#define T_TILDE 404
#define T_TIME 405
#define T_TIMEUNIT 406
#define T_TITLE 407
#define T_TO 408
#define T_TRANSPOSE 409
#define T_UNITS 410
#define T_UNITTYPE 411
#define T_UNSET 412
#define T_UP 413
#define T_USEACCS 414
#define T_VCOMBINE 415
#define T_VCOMBVAL 416
#define T_VISVAR 417
#define T_VOICE 418
#define T_VVAR 419
#define T_WHEREUSED 420
#define T_WITH 421
#define T_XNOTE 422
#define T_XPOS_INT 423
#define T_YESNOVAR 424




/* Copy the first part of user declarations.  */
#line 2 "gram.y"


/* Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
 * 2005, 2006, 2007, 2008, 2009, 2010, 2011 by Arkkra Enterprises */
/* All rights reserved */

/* parser for music publication program. Uses lex to get tokens. */


#include "rational.h"
#include "globals.h"
#include "defines.h"
#include "structs.h"

#define YYDEBUG 1


/* how many items to allocate at a time for
 * "with" list, and location lists, etc */
#define ITEMS	(4)


static struct MAINLL *Currstruct_p;	/* main list struct being filled in */
static struct BLOCKHEAD *Currblock_p;	/* current block, if non-zero */

static struct INPCOORD *Curr_loc_info_p; /* location info being collected */
static struct USER_SYMBOL *Curr_usym_p;	/* user-defined symbol being defined */


static short Gotheader, Gotfooter;	/* boolean: to make sure each is defined only once */
static short Gothead2, Gotfoot2;
static short Getting_tup_dur;		/* YES if currently collection tuplet
					 * duration rather than GRPSYL dur */

static struct GRPSYL *Curr_grpsyl_p;	/* current GRPSYL struct being filled in */
static struct GRPSYL *Last_grpsyl_p;	/* previous GRPSYL struct filled in (contains
					 * defaults for the current one */
static struct TIMELIST *Extra_time_p;	/* If user enters times to be added
					 * together, like 2.+16 this points to
					 * a linked list of the extra times */
static struct TIMELIST *Curr_timelist_p;/* current additive time, used to know
					 * where to link items to the list */
static struct TIMELIST *Last_alloced_timelist_p; /* Most recently allocated
					 * list. Keeping track of this lets us
					 * avoid trying to free the list
					 * when Extra_time_p is pointing
					 * to a list from an SSV. */
static struct GRPSYL *Prev_grpsyl_p;	/* Like Last_grpsyl_p except in the
					 * case of additive times,
					 * in which case it points to the
					 * first group. This is needed in case
					 * the following group is to get its
					 * time value by defaulting to that
					 * of its previous group. */
static int Extra_basictime;		/* for saving basictime, when doing
					 * additive times */
static int Doing_timeunit = NO;		/* YES if gathering timeunit param */
static struct GRPSYL *Lyrics_p;		/* pointer to current list of lyrics */
static char **Curr_marklist;		/* current "with" list */
static struct PRINTDATA **Next_print_link_p_p;	/* points to where to attach next
						 * print command that we get */
static int Item_count;			/* items in current list */
static int Max_items;			/* current amount of space in lists
					 * "with" list, curve locations, etc) */

static int Plus_minus;			/* if 1 add, if -1 subtract offset */
static int Defining_multiple = NO;	/* if defining multiple voices at once */
static int Chord_at_a_time = NO;	/* YES for chord-at-a-time,
					 * NO for voice-at-a-time */
static int EM_staff;			/* Staff number of most recent
					 * emptymeas parameter usage */
static short Endingloc;			/* if current bar starts or ends an
					 * ending, etc (STARTITEM, ENDITEM, etc) */
static short Got_ending;		/* YES if got ending on this bar */

static int Til_bars;			/* number of bars in "til" clause */
static double Dist;			/* dist for a specific STUFF */
static int Dist_usage;			/* meaning of Dist field */
static int Aligntag = NOALIGNTAG;	/* align tag number for STUFF */
static short User_meas_time;		/* YES if user specified a time for
					 * an 'm' item. Only valid on mr */
static int Order_place;			/* PL_* for markorder in SSV */
static int Order_prio;			/* value in markorder in SSV */
static int Start_gracebackup;		/* how many grace notes to back up
					 * before starting a "stuff" */
static int End_gracebackup;		/* how many grace notes to back up
					 * before ending a "stuff" */
static float Til_offset;		/* beat count in "til" clause */
static float Til_steps;			/* stepsize offset of "til" clause */
static int Linetype;			/* L_DOTTED, L_DASHED, or L_NORMAL */

static char *String1, *String2;		/* to temporarily keep track
					 * of labels and other temporary
					 * strings */
static char Tmpbuff[20];		/* temporary buffer for converting
					 * float numbers */
static char Stringbuff[100];		/* temporary string storage */
static int Titlefont, Titlesize;	/* font/size for title command */
static double Extra;			/* extra vertical space for prints */
static short Good_till_canceled = NO;	/* if [] things should be continued
					 * until turned off */
static short Curr_paratype = J_JUSTPARA; /* current paragraph type */
static struct TIMEDSSV *Curr_tssv_p;	/* current mid-measure param change */
static char Timerep[MAXTSLEN];		/* Internal representation of time
					 * signature being collected */
static int Tsig_offset;			/* Current place in Timerep while
					 * collecting a time signature */
static char *Alt_timesig_list;		/* If user specified alternating
					 * time signatures, this points to
					 * the beginning of the list, for
					 * when we need to wrap around */
static char *Next_alt_timesig;		/* If user specified alternating
					 * time signatures, this points to
					 * the one for the next measure */
static short Tsig_visibility;		/* If EACHMEAS, alternating
					 * time signatures will be done
					 * by explicitly printing
					 * the appropriate time signature at
					 * the beginning of every measure,
					 * rather than printing them all just
					 * once at the beginning of the run
					 * of measures that alternate. */
static struct TAG_REF *Curr_timeref_tag_p; /* Time offsets are relative
					 * to the most recent horizontal tag.
					 * This points to that tag,
					 * or is zero if no such tag yet */

/* Row index values must match the PS_* value definitions in defines.h.
 * Column [0] is height in portrait mode, and column [1] is height. */
double pagesztbl[7][2] = {
	{ 8.5, 11.0 },		/* PS_LETTER */
	{ 8.5, 14.0 },		/* PS_LEGAL */
	{ 8.5, 13.0 },		/* PS_FLSA */
	{ 5.5, 8.5 },		/* PS_HALFLETTER */
	{ 8.26, 11.69 },	/* PS_A4 */
	{ 5.84, 8.26 },		/* PS_A5 */
	{ 4.12, 5.84 }		/* PS_A6 */
};



/* static functions */
static char *stripquotes P((char *string));	/* rmv double quotes
						 * from string */
static void chkdup_headfoot P((int flag, char *which));
static void end_prev_context P((void));
static void clone_staff_ssvs P((struct MAINLL *insert_p));
static void clone_voice_ssvs P((struct MAINLL *insert_p));
static void clone1ssv P((struct SSV *clone_src_p, struct MAINLL *insert_p,
		int staffno, int voiceno));
static void chk_ssv_ranges P((int context));
static void var_valid P((void));	 /* check if okay to set location var */
static void proc_printcmd P((int justifytype, struct INPCOORD *inpc_p,
		char *str, int font, int size, int got_nl,
		int isPostScript, double extra));
static double extra_needed P((int font, int size, char *string));
static void keyword_notes P((char *str));
static void free_extra_time P((void));
static void tsig_item P((int item));
static struct EXPR_NODE *newnode P((int op));




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 169 "gram.y"
{
int	intval;		/* for tokens/nonterminals that return int values */
char	*stringval;	/* for tokens/nonterminals that return strings */
float	floatval;	/* for nonterminals that return floats */
RATIONAL ratval;	/* for nonterminals that return rational numbers */
struct INPCOORD *inpcoord_p;	/* for nonterminals that return coord info */
struct EXPR_NODE *expr_p;/* for nonterminals that return coord expression */
struct TAG_REF *tag_p;	/* for nonterminals that return a tag reference */
}
/* Line 187 of yacc.c.  */
#line 608 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 621 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  186
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  288
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1018

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   424

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    13,    15,    17,    19,
      22,    24,    28,    30,    33,    35,    37,    39,    41,    43,
      46,    50,    51,    57,    58,    64,    66,    70,    72,    74,
      78,    81,    82,    83,    85,    87,    89,    93,    95,    98,
     100,   102,   104,   107,   110,   112,   114,   119,   122,   126,
     132,   137,   142,   143,   148,   153,   158,   164,   169,   174,
     178,   182,   186,   190,   194,   198,   202,   206,   210,   214,
     218,   222,   225,   226,   231,   235,   240,   245,   249,   253,
     257,   263,   267,   271,   275,   285,   291,   293,   295,   297,
     299,   301,   304,   305,   307,   309,   310,   311,   313,   315,
     317,   321,   325,   326,   331,   336,   338,   339,   341,   342,
     345,   348,   350,   352,   353,   354,   356,   360,   364,   365,
     368,   369,   374,   375,   378,   380,   381,   382,   384,   388,
     391,   393,   395,   397,   399,   403,   407,   409,   411,   413,
     415,   417,   419,   421,   423,   425,   428,   430,   431,   435,
     437,   438,   443,   445,   447,   451,   455,   457,   459,   463,
     465,   466,   468,   469,   471,   475,   479,   482,   483,   485,
     487,   489,   492,   495,   497,   502,   504,   507,   512,   513,
     515,   516,   518,   520,   522,   524,   525,   528,   531,   532,
     536,   537,   541,   542,   547,   549,   552,   553,   555,   556,
     559,   560,   562,   564,   566,   568,   570,   571,   573,   575,
     578,   580,   582,   589,   592,   593,   595,   596,   598,   599,
     603,   605,   608,   612,   620,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   645,   647,   649,
     651,   653,   655,   657,   659,   661,   663,   665,   667,   669,
     671,   673,   675,   677,   679,   681,   683,   685,   687,   689,
     693,   696,   701,   705,   707,   708,   710,   712,   714,   717,
     721,   723,   725,   727,   731,   733,   737,   739,   741,   744,
     746,   748,   752,   755,   756,   759,   762,   767,   768,   771,
     773,   776,   778,   784,   785,   787,   789,   792,   797,   799,
     801,   803,   805,   809,   813,   817,   821,   824,   826,   831,
     838,   839,   843,   844,   849,   850,   851,   853,   855,   859,
     863,   865,   867,   869,   871,   875,   878,   881,   884,   887,
     889,   891,   894,   895,   897,   898,   900,   902,   906,   908,
     912,   915,   918,   920,   924,   928,   929,   930,   932,   933,
     937,   939,   943,   945,   947,   949,   951,   953,   955,   957,
     959,   961,   963,   965,   967,   969,   972,   974,   976,   977,
     979,   980,   984,   986,   988,   989,   992,   997,   998,   999,
    1001,  1002,  1005,  1007,  1011,  1012,  1014,  1016,  1018,  1021,
    1024,  1025,  1027,  1031,  1034,  1038,  1041,  1044,  1046,  1047,
    1050,  1053,  1054,  1058,  1060,  1061,  1065,  1067,  1069,  1071,
    1074,  1076,  1078,  1080,  1082,  1084,  1086,  1088,  1090,  1094,
    1097,  1103,  1109,  1113,  1119,  1127,  1133,  1138,  1145,  1150,
    1156,  1161,  1162,  1164,  1166,  1167,  1169,  1170,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1193,  1195,
    1198,  1204,  1206,  1207,  1209,  1211,  1213,  1216,  1219,  1222,
    1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,  1240,  1249,
    1250,  1252,  1254,  1256,  1258,  1260,  1261,  1263,  1264,  1267,
    1272,  1276,  1278,  1279,  1281,  1282,  1284,  1286,  1288,  1292,
    1295,  1296,  1299,  1302,  1303,  1304,  1310,  1312,  1314,  1316,
    1320,  1323,  1324,  1327,  1328,  1331,  1332,  1334,  1336,  1339,
    1342,  1346,  1348,  1354,  1355,  1357,  1359,  1362,  1365,  1371,
    1374,  1376,  1378,  1379,  1383,  1385,  1386,  1389,  1393,  1395,
    1397,  1398,  1400,  1401,  1403,  1405,  1407,  1411,  1412,  1417,
    1420,  1422,  1423,  1428,  1429,  1432,  1434,  1437,  1439,  1441,
    1445,  1449,  1453,  1461,  1464,  1466,  1467,  1469,  1471,  1473,
    1475,  1482,  1483,  1485,  1487,  1490,  1492,  1493,  1497,  1501,
    1505,  1510,  1517,  1519,  1523,  1526,  1528,  1530,  1532,  1534,
    1536,  1538,  1542,  1545,  1546,  1548,  1550,  1552,  1560,  1561,
    1562,  1564,  1565,  1570,  1578,  1579,  1582,  1585,  1587,  1591,
    1593,  1597,  1600,  1602,  1606,  1614,  1621,  1624,  1626,  1628,
    1630,  1632,  1635,  1637,  1639,  1641,  1643,  1645,  1646,  1650,
    1651,  1653,  1654,  1657,  1660,  1664,  1665,  1667,  1668,  1671,
    1673,  1676,  1682,  1685,  1686,  1691,  1692,  1697,  1698,  1700,
    1702,  1703,  1706,  1709,  1712,  1715,  1718,  1723,  1729,  1730,
    1732,  1734,  1737,  1739,  1742,  1743,  1746,  1750,  1753,  1757,
    1761,  1765,  1767,  1769,  1770,  1772
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     171,     0,    -1,   172,    -1,   171,   172,    -1,   173,   391,
      -1,   193,    -1,   258,    -1,   264,    -1,   268,    -1,   392,
      84,    -1,   186,    -1,   385,   391,    84,    -1,    84,    -1,
       1,    84,    -1,   174,    -1,   183,    -1,   185,    -1,   187,
      -1,   188,    -1,   184,   182,    -1,   125,   182,   181,    -1,
      -1,   136,   182,   175,   177,   181,    -1,    -1,   163,   182,
     176,   179,   181,    -1,   178,    -1,   177,   278,   178,    -1,
     281,    -1,   180,    -1,   179,   278,   180,    -1,   281,   284,
      -1,    -1,    -1,    15,    -1,    82,    -1,    50,    -1,   267,
     267,    84,    -1,    52,    -1,   144,   267,    -1,   191,    -1,
     191,    -1,    90,    -1,   327,   191,    -1,   195,   194,    -1,
     129,    -1,    84,    -1,    91,    40,   327,   191,    -1,    91,
      40,    -1,    46,    40,   411,    -1,     5,    40,   411,    21,
     411,    -1,   131,    40,   411,   247,    -1,   110,    40,   249,
     250,    -1,    -1,   160,    40,   196,   251,    -1,    96,    40,
     327,   411,    -1,   164,    40,   191,   200,    -1,   113,    40,
     201,   202,   208,    -1,   112,    40,   209,   210,    -1,    12,
      40,   216,   217,    -1,   119,    40,   219,    -1,   220,    40,
     221,    -1,    56,    40,   234,    -1,   159,    40,   235,    -1,
     150,    40,   224,    -1,   137,    40,   237,    -1,    48,    40,
      47,    -1,    44,    40,    45,    -1,    19,    40,    18,    -1,
     169,    40,   242,    -1,   162,    40,   198,    -1,    75,    40,
     199,    -1,   157,   266,    -1,    -1,   151,    40,   197,   206,
      -1,   143,    40,   207,    -1,   128,    40,   243,   244,    -1,
     127,    40,   245,   246,    -1,    37,    40,   253,    -1,   118,
      40,   117,    -1,   102,    40,   256,    -1,   154,    40,   254,
     257,   191,    -1,   155,    40,   156,    -1,   142,    40,   267,
      -1,   108,    40,   267,    -1,    14,    40,   192,    21,   192,
      21,   192,    21,   192,    -1,   140,    40,   192,    21,   192,
      -1,   165,    -1,    61,    -1,    63,    -1,    61,    -1,    63,
      -1,    42,   191,    -1,    -1,   105,    -1,    61,    -1,    -1,
      -1,   203,    -1,   206,    -1,   204,    -1,   203,    21,   206,
      -1,   203,    21,   204,    -1,    -1,    70,   205,   203,   121,
      -1,   319,   324,   320,   323,    -1,    62,    -1,    -1,   206,
      -1,    -1,    64,    65,    -1,    65,    64,    -1,    65,    -1,
      64,    -1,    -1,    -1,   211,    -1,   210,    21,   211,    -1,
     191,   212,   213,    -1,    -1,    26,   191,    -1,    -1,    70,
     215,   214,   121,    -1,    -1,    21,   215,    -1,   267,    -1,
      -1,    -1,   218,    -1,   217,    21,   218,    -1,   191,   212,
      -1,     8,    -1,   138,    -1,    93,    -1,   222,    -1,   221,
      21,   222,    -1,   221,    10,   222,    -1,   223,    -1,    83,
      -1,    92,    -1,    95,    -1,    78,    -1,    72,    -1,    36,
      -1,   116,    -1,   100,    -1,   225,   232,    -1,   227,    -1,
      -1,   225,   226,   227,    -1,   229,    -1,    -1,   227,   107,
     228,   229,    -1,    25,    -1,    22,    -1,   230,   132,   191,
      -1,   230,   107,    81,    -1,    81,    -1,   231,    -1,   230,
     107,   231,    -1,   191,    -1,    -1,   242,    -1,    -1,    63,
      -1,   191,   344,   255,    -1,   341,   342,   255,    -1,   242,
     236,    -1,    -1,    86,    -1,     8,    -1,    87,    -1,   191,
     233,    -1,   191,    31,    -1,   145,    -1,   145,    70,   238,
     121,    -1,   239,    -1,   238,   239,    -1,   341,   240,   241,
     343,    -1,    -1,   344,    -1,    -1,   146,    -1,    61,    -1,
      63,    -1,   191,    -1,    -1,    21,   191,    -1,   327,   191,
      -1,    -1,    21,   327,   191,    -1,    -1,    21,   411,   248,
      -1,    -1,    21,   192,    21,   192,    -1,    97,    -1,   341,
     191,    -1,    -1,    94,    -1,    -1,   284,   252,    -1,    -1,
     161,    -1,    38,    -1,    15,    -1,   158,    -1,    30,    -1,
      -1,   168,    -1,    68,    -1,     9,   101,    -1,   101,    -1,
     168,    -1,   152,   259,   262,   263,   391,    84,    -1,   261,
     260,    -1,    -1,    47,    -1,    -1,    45,    -1,    -1,    70,
     191,   121,    -1,   267,    -1,   267,   267,    -1,   267,   267,
     267,    -1,   265,    98,   259,   262,   267,   391,    84,    -1,
      -1,    99,    -1,    91,    -1,   169,    -1,   128,    -1,   137,
      -1,   151,    -1,   143,    -1,    96,    -1,    12,    -1,    46,
      -1,     5,    -1,   131,    -1,   119,    -1,   155,    -1,    37,
      -1,   118,    -1,    75,    -1,   102,    -1,   164,    -1,   160,
      -1,   127,    -1,   112,    -1,    93,    -1,   159,    -1,    56,
      -1,   150,    -1,   154,    -1,   113,    -1,   162,    -1,   142,
      -1,    48,    -1,    44,    -1,    19,    -1,   141,    -1,   267,
     107,   141,    -1,   269,    84,    -1,   270,   271,   280,   286,
      -1,    80,   191,   391,    -1,   361,    -1,    -1,   277,    -1,
     272,    -1,   273,    -1,   272,   273,    -1,   274,   276,   275,
      -1,    58,    -1,   115,    -1,   277,    -1,   276,   129,   277,
      -1,   279,    -1,   277,   278,   279,    -1,    10,    -1,   281,
      -1,   281,   284,    -1,    20,    -1,   282,    -1,   281,    21,
     282,    -1,   189,   283,    -1,    -1,    26,   189,    -1,   190,
     285,    -1,   190,    26,   190,   285,    -1,    -1,    21,   284,
      -1,   287,    -1,   286,   287,    -1,   355,    -1,   288,   294,
     328,   304,   129,    -1,    -1,   289,    -1,   290,    -1,   289,
     290,    -1,    74,   291,   292,   124,    -1,   125,    -1,   136,
      -1,   163,    -1,   293,    -1,   292,   129,   293,    -1,    19,
      40,    18,    -1,    91,    40,   191,    -1,   169,    40,   242,
      -1,   295,   317,    -1,   298,    -1,    58,    26,   115,   298,
      -1,    58,   298,   299,   115,   296,   297,    -1,    -1,    29,
      29,    29,    -1,    -1,   297,    58,   299,   115,    -1,    -1,
      -1,   300,    -1,   301,    -1,   300,   129,   301,    -1,   166,
     307,   310,    -1,   353,    -1,   314,    -1,   325,    -1,   315,
      -1,    46,   327,   191,    -1,    54,   302,    -1,    55,   267,
      -1,    59,   411,    -1,   133,   191,    -1,   107,    -1,    26,
      -1,   303,   411,    -1,    -1,   405,    -1,    -1,   305,    -1,
     306,    -1,   305,    21,   306,    -1,   316,    -1,   134,   327,
     411,    -1,     9,   191,    -1,   103,   365,    -1,    39,    -1,
     135,   308,   309,    -1,   147,   308,   309,    -1,    -1,    -1,
     315,    -1,    -1,   153,   163,   191,    -1,   311,    -1,   310,
      21,   311,    -1,   312,    -1,   313,    -1,   267,    -1,    29,
      -1,    26,    -1,   123,    -1,    51,    -1,    23,    -1,    49,
      -1,    28,    -1,   167,    -1,   158,    -1,    30,    -1,    16,
     318,    -1,    41,    -1,    32,    -1,    -1,   206,    -1,    -1,
     166,   136,   106,    -1,    81,    -1,   191,    -1,    -1,   320,
     321,    -1,   405,   322,   319,   324,    -1,    -1,    -1,    62,
      -1,    -1,   324,    29,    -1,   326,    -1,    96,   327,   411,
      -1,    -1,    26,    -1,   334,    -1,   329,    -1,   330,   333,
      -1,   331,   332,    -1,    -1,   111,    -1,   149,   308,   309,
      -1,    40,   354,    -1,    51,   341,   343,    -1,    51,   132,
      -1,    55,   267,    -1,   348,    -1,    -1,   333,   332,    -1,
     337,   335,    -1,    -1,   336,   337,   106,    -1,   166,    -1,
      -1,   337,   338,   333,    -1,   339,    -1,    64,    -1,    65,
      -1,    66,    65,    -1,   122,    -1,    13,    -1,    49,    -1,
      38,    -1,    99,    -1,   112,    -1,    18,    -1,   159,    -1,
      70,   339,   121,    -1,   341,   340,    -1,   341,    70,   344,
     121,   343,    -1,   341,    70,   345,   121,   340,    -1,   341,
      70,   341,    -1,   341,   344,   241,   343,   340,    -1,   341,
     344,   241,    70,   345,   121,   340,    -1,   341,   344,   241,
      70,   341,    -1,   341,   146,   343,   340,    -1,   341,   146,
      70,   345,   121,   340,    -1,   341,   345,   342,   340,    -1,
     341,   345,    70,   344,   121,    -1,   341,   345,    70,   341,
      -1,    -1,   267,    -1,   105,    -1,    -1,   344,    -1,    -1,
     345,    -1,   130,    -1,    10,    -1,    63,    -1,    67,    -1,
      27,    -1,   191,    -1,   346,    -1,   347,    -1,    26,    -1,
     346,    26,    -1,   107,    -1,   347,   107,    -1,   349,   350,
     123,   308,   309,    -1,    73,    -1,    -1,    88,    -1,   351,
      -1,   352,    -1,   351,   352,    -1,   341,   343,    -1,    40,
     354,    -1,    61,    -1,   105,    -1,    62,    -1,    64,    -1,
      65,    -1,    66,    -1,    63,    -1,    67,    -1,    71,    -1,
     357,   286,   358,   359,   191,   356,   360,   129,    -1,    -1,
      63,    -1,    89,    -1,    61,    -1,    57,    -1,   114,    -1,
      -1,   106,    -1,    -1,    21,   206,    -1,    72,   362,    20,
     376,    -1,   363,   366,   369,    -1,   364,    -1,    -1,   106,
      -1,    -1,   106,    -1,   367,    -1,     8,    -1,   366,    21,
     367,    -1,   191,   368,    -1,    -1,    26,   191,    -1,    10,
     191,    -1,    -1,    -1,   369,   129,   106,   370,   366,    -1,
     372,    -1,   105,    -1,   373,    -1,   372,    21,   373,    -1,
     191,   374,    -1,    -1,    26,   191,    -1,    -1,   377,   383,
      -1,    -1,   378,    -1,   379,    -1,   378,   379,    -1,   380,
     129,    -1,   375,   317,   382,    -1,   381,    -1,   357,   378,
     358,   191,   360,    -1,    -1,    65,    -1,   384,    -1,   383,
     384,    -1,   267,   129,    -1,    58,   371,   115,   267,   129,
      -1,   393,   398,    -1,   415,    -1,   419,    -1,    -1,   126,
     386,   387,    -1,   454,    -1,    -1,   387,   388,    -1,    46,
     390,   389,    -1,   411,    -1,    11,    -1,    -1,    40,    -1,
      -1,   129,    -1,   426,    -1,   448,    -1,   417,   394,   395,
      -1,    -1,    70,   417,    13,   121,    -1,   396,   397,    -1,
      13,    -1,    -1,   397,    33,   268,    34,    -1,    -1,   398,
     399,    -1,   326,    -1,    40,   354,    -1,   400,    -1,    53,
      -1,    77,    40,   191,    -1,    60,    40,   267,    -1,    89,
      40,   191,    -1,   116,   401,   261,   260,   432,   402,   434,
      -1,    36,   267,    -1,    35,    -1,    -1,   267,    -1,    77,
      -1,    89,    -1,    60,    -1,    70,   404,   406,    21,   407,
     121,    -1,    -1,   107,    -1,    26,    -1,   408,   409,    -1,
     409,    -1,    -1,    70,   409,   121,    -1,   409,     6,   409,
      -1,   409,    79,   409,    -1,     3,    70,   409,   121,    -1,
       4,    70,   409,    21,   409,   121,    -1,   411,    -1,   414,
      29,   410,    -1,   150,   411,    -1,    61,    -1,    67,    -1,
     105,    -1,    63,    -1,    65,    -1,   191,    -1,   191,    29,
     412,    -1,    29,   413,    -1,    -1,   413,    -1,    90,    -1,
     354,    -1,   417,    68,   416,   403,   153,   403,   418,    -1,
      -1,    -1,    69,    -1,    -1,   166,   259,   262,   267,    -1,
     417,    24,   420,   425,   153,   425,   421,    -1,    -1,   153,
     422,    -1,    17,   423,    -1,   425,    -1,   422,   153,   425,
      -1,   424,    -1,   423,    21,   424,    -1,   327,   411,    -1,
     403,    -1,   427,    20,   438,    -1,   430,   432,   433,   364,
     366,   434,   437,    -1,   417,   104,   432,   364,   366,   434,
      -1,   428,   429,    -1,    76,    -1,   277,    -1,     8,    -1,
     431,    -1,   261,    47,    -1,    73,    -1,   123,    -1,   100,
      -1,    83,    -1,    92,    -1,    -1,    70,   191,   121,    -1,
      -1,    78,    -1,    -1,    46,   435,    -1,   411,   436,    -1,
      26,   411,   436,    -1,    -1,    43,    -1,    -1,     7,   191,
      -1,   439,    -1,   438,   439,    -1,   440,   442,   443,   444,
     129,    -1,   411,   441,    -1,    -1,    70,    26,   191,   121,
      -1,    -1,    58,   405,   411,   115,    -1,    -1,   139,    -1,
     267,    -1,    -1,   148,   445,    -1,   411,   446,    -1,   441,
     442,    -1,    62,   447,    -1,   441,   442,    -1,   107,   411,
     441,   442,    -1,   120,   449,   450,    20,   453,    -1,    -1,
     158,    -1,    30,    -1,   451,   452,    -1,   189,    -1,   189,
     190,    -1,    -1,   153,   189,    -1,   153,   189,   190,    -1,
     411,   129,    -1,   453,   411,   129,    -1,   456,   457,   267,
      -1,   455,   457,   267,    -1,   108,    -1,   109,    -1,    -1,
      85,    -1,   403,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   461,   461,   464,   467,   470,   473,   476,   479,   482,
     485,   488,   491,   497,   508,   515,   521,   525,   530,   534,
     549,   555,   555,   575,   575,   593,   595,   599,   604,   606,
     609,   615,   621,   627,   786,   791,   799,   815,   824,   834,
     837,   843,   848,   854,   857,   860,   863,   882,   897,   903,
     909,   915,   924,   924,   928,   935,   941,   951,   957,   963,
     972,   980,   983,   989,   995,  1000,  1006,  1012,  1040,  1046,
    1049,  1055,  1084,  1084,  1097,  1107,  1112,  1117,  1127,  1147,
    1174,  1201,  1207,  1213,  1232,  1253,  1273,  1285,  1301,  1312,
    1325,  1331,  1351,  1357,  1370,  1383,  1388,  1392,  1396,  1402,
    1405,  1411,  1415,  1415,  1420,  1478,  1496,  1501,  1506,  1511,
    1517,  1523,  1529,  1535,  1541,  1545,  1548,  1551,  1560,  1566,
    1578,  1584,  1591,  1597,  1603,  1607,  1612,  1616,  1619,  1623,
    1631,  1637,  1642,  1662,  1670,  1678,  1685,  1697,  1703,  1709,
    1715,  1734,  1740,  1746,  1752,  1758,  1780,  1783,  1783,  1789,
    1794,  1794,  1800,  1806,  1812,  1835,  1847,  1855,  1858,  1861,
    1880,  1885,  1891,  1896,  1904,  1915,  1954,  1973,  1981,  1987,
    1993,  2000,  2006,  2012,  2022,  2029,  2035,  2041,  2050,  2055,
    2063,  2069,  2080,  2090,  2095,  2109,  2127,  2137,  2152,  2170,
    2182,  2186,  2192,  2196,  2208,  2211,  2237,  2242,  2250,  2255,
    2264,  2269,  2276,  2282,  2291,  2297,  2303,  2308,  2324,  2330,
    2336,  2341,  2344,  2348,  2368,  2373,  2379,  2384,  2389,  2394,
    2400,  2408,  2428,  2446,  2538,  2545,  2552,  2555,  2558,  2561,
    2564,  2567,  2570,  2573,  2576,  2579,  2582,  2585,  2588,  2591,
    2594,  2597,  2600,  2603,  2606,  2609,  2612,  2615,  2618,  2621,
    2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,  2648,  2659,
    2672,  2684,  2703,  2738,  2744,  2748,  2754,  2760,  2763,  2766,
    2769,  2774,  2779,  2785,  2791,  2798,  2801,  2808,  2816,  2825,
    2832,  2835,  2841,  2850,  2856,  2866,  2879,  2900,  2904,  2909,
    2912,  2916,  2919,  2962,  2966,  2970,  2973,  2977,  2986,  2992,
    2998,  3005,  3008,  3012,  3022,  3039,  3055,  3059,  3075,  3081,
    3086,  3091,  3097,  3101,  3109,  3116,  3123,  3126,  3129,  3132,
    3139,  3142,  3145,  3148,  3165,  3182,  3193,  3220,  3232,  3257,
    3263,  3269,  3284,  3289,  3294,  3297,  3301,  3304,  3308,  3311,
    3324,  3352,  3364,  3375,  3390,  3404,  3414,  3419,  3426,  3431,
    3448,  3451,  3454,  3468,  3477,  3481,  3488,  3495,  3502,  3508,
    3519,  3532,  3542,  3553,  3559,  3565,  3593,  3599,  3630,  3639,
    3650,  3655,  3671,  3698,  3746,  3751,  3755,  3770,  3791,  3796,
    3809,  3814,  3820,  3840,  3846,  3852,  3858,  3871,  3876,  3880,
    3884,  3903,  3919,  3938,  3979,  3997,  4010,  4029,  4032,  4035,
    4039,  4046,  4051,  4091,  4098,  4106,  4112,  4115,  4122,  4135,
    4148,  4164,  4184,  4191,  4203,  4214,  4226,  4238,  4246,  4251,
    4262,  4272,  4282,  4298,  4304,  4314,  4330,  4336,  4342,  4351,
    4357,  4371,  4376,  4393,  4400,  4406,  4411,  4417,  4422,  4428,
    4434,  4441,  4448,  4454,  4460,  4472,  4482,  4488,  4494,  4500,
    4507,  4514,  4521,  4530,  4537,  4541,  4544,  4548,  4560,  4569,
    4575,  4583,  4590,  4597,  4604,  4611,  4618,  4624,  4630,  4637,
    4643,  4650,  4657,  4669,  4674,  4680,  4685,  4694,  4701,  4706,
    4710,  4715,  4725,  4732,  4738,  4743,  4751,  4754,  4764,  4767,
    4775,  4782,  4792,  4798,  4802,  4802,  4806,  4811,  4822,  4827,
    4832,  4840,  4846,  4852,  4861,  4873,  4879,  4885,  4888,  4891,
    4894,  4916,  4920,  4927,  4933,  4939,  4942,  4946,  4957,  4962,
    5071,  5074,  5078,  5077,  5158,  5161,  5165,  5168,  5203,  5217,
    5222,  5225,  5228,  5231,  5235,  5238,  5241,  5293,  5299,  5321,
    5329,  5352,  5356,  5362,  5365,  5369,  5377,  5388,  5420,  5434,
    5441,  5447,  5452,  5469,  5477,  5490,  5500,  5508,  5517,  5526,
    5534,  5542,  5551,  5557,  5564,  5572,  5582,  5599,  5605,  5613,
    5621,  5629,  5637,  5644,  5690,  5712,  5729,  5735,  5745,  5751,
    5757,  5762,  5768,  5775,  5781,  5784,  5789,  5792,  5814,  5821,
    5826,  5831,  5836,  5841,  5854,  5867,  5870,  5873,  5876,  5880,
    5883,  5887,  5903,  5940,  5948,  5955,  5970,  5980,  5987,  5990,
    5997,  6006,  6030,  6042,  6048,  6054,  6060,  6067,  6073,  6079,
    6084,  6090,  6096,  6109,  6115,  6128,  6133,  6139,  6144,  6155,
    6158,  6162,  6170,  6180,  6185,  6191,  6196,  6202,  6207,  6219,
    6225,  6230,  6235,  6253,  6261,  6267,  6275,  6282,  6286,  6291,
    6298,  6305,  6309,  6316,  6322,  6325,  6332,  6339,  6345,  6350,
    6361,  6372,  6377,  6381,  6388,  6395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_1ARG_FUNC", "T_2ARG_FUNC",
  "T_2FNUMVAR", "T_ADDSUB_OP", "T_ALIGN", "T_ALL", "T_ALT", "T_AMPERSAND",
  "T_AUTO", "T_BARSTLISTVAR", "T_BARTYPE", "T_BBOX", "T_BLOCKHEAD", "T_BM",
  "T_BULGE", "T_CLEF", "T_CLEFVAR", "T_COLON", "T_COMMA", "T_COMMON",
  "T_CUE", "T_CURVE", "T_CUT", "T_DASH", "T_DBLFLAT", "T_DIAM", "T_DOT",
  "T_DOWN", "T_DRUM", "T_EBM", "T_EM_BEGIN", "T_EM_END", "T_ENDENDING",
  "T_ENDING", "T_ENDSTYLE", "T_ENDTYPE", "T_EPH", "T_EQUAL", "T_ESBM",
  "T_EVERY", "T_EXCLAM", "T_FAMILY", "T_FFAMILY", "T_FNUMVAR", "T_FONT",
  "T_FONTVAR", "T_GRACE", "T_GRIDS", "T_HAT", "T_HEADSHAPES",
  "T_HIDECHANGES", "T_HO", "T_HS", "T_KEY", "T_LBRACE", "T_LBRACKET",
  "T_LEN", "T_LET", "T_LETTER", "T_LET_M", "T_LET_N", "T_LET_R", "T_LET_S",
  "T_LET_U", "T_LET_X", "T_LINE", "T_LINETYPE", "T_LPAREN", "T_LVAR",
  "T_LYRICS", "T_L_ANGLE", "T_L_DBLANGLE", "T_MEASNUM", "T_MIDI", "T_MNUM",
  "T_MODIFIER", "T_MULDIV_OP", "T_MULTIREST", "T_MULTIWHOLE", "T_MUSIC",
  "T_MUSSYM", "T_NEWLINE", "T_NL", "T_NONE", "T_NONNAT", "T_NOWHERE_SLIDE",
  "T_NUM", "T_NUMBER", "T_NUMVAR", "T_OCTAVE", "T_ORDER", "T_ORIENTATION",
  "T_OTHERTEXT", "T_PAD", "T_PAGESIZE", "T_PARAGRAPH", "T_PARATYPE",
  "T_PEDAL", "T_PEDSTAR", "T_PEDSTYLE", "T_PH", "T_PHRASE", "T_PITCH",
  "T_PLACE", "T_PLUS", "T_POSTSCRIPT", "T_PRINTTYPE", "T_PSVAR",
  "T_QUESTION", "T_RANGELISTVAR", "T_RATNUMLISTVAR", "T_RBRACE",
  "T_RBRACKET", "T_REHEARSAL", "T_REHTYPE", "T_REH_STYLE", "T_REPEATDOTS",
  "T_ROLL", "T_RPAREN", "T_RPT", "T_R_ANGLE", "T_R_DBLANGLE", "T_SCORE",
  "T_SCOREFEED", "T_SCOREPAD", "T_SCORESEP", "T_SEMICOLON", "T_SHARP",
  "T_SHORTEN", "T_SLASH", "T_SLASHMARK", "T_SLOPE", "T_SLUR", "T_STAFF",
  "T_STAFFLINES", "T_STANDARD", "T_STAR", "T_STEMOFFSET", "T_STRING",
  "T_STRVAR", "T_SWINGUNIT", "T_SYMBOL", "T_TAB", "T_TICKS", "T_TIE",
  "T_TIL", "T_TILDE", "T_TIME", "T_TIMEUNIT", "T_TITLE", "T_TO",
  "T_TRANSPOSE", "T_UNITS", "T_UNITTYPE", "T_UNSET", "T_UP", "T_USEACCS",
  "T_VCOMBINE", "T_VCOMBVAL", "T_VISVAR", "T_VOICE", "T_VVAR",
  "T_WHEREUSED", "T_WITH", "T_XNOTE", "T_XPOS_INT", "T_YESNOVAR",
  "$accept", "song", "item", "context", "ssv_context", "@1", "@2",
  "ssv_stafflist", "ssv_staff_item", "ssv_sv_list", "ssv_sv_item",
  "alloc_ssv", "new_context", "blockhead_context", "music_context",
  "grid_context", "stringpair", "headshape_context", "symbol_context",
  "staffnum", "voicenum", "num", "value", "assignment", "terminator",
  "assign", "@3", "@4", "visval", "measnumval", "vschemetype",
  "allocbeamlist", "ratnumlist", "nonempty_ratnumlist", "subbeam", "@5",
  "time_item", "swing_time", "opt_rs", "alloc_rangelist", "rangelist",
  "rangeitem", "rangetail", "grplabel", "optlabel2", "glabel",
  "alloc_barstlist", "barstlist", "barst_item", "repeatdots_value",
  "mark_order", "orderlist", "orderitem", "marktype", "timesig",
  "tsiglist", "@6", "meas_tsig", "@7", "fraction", "numerator",
  "numerator_value", "opt_ts_visibility", "opt_n", "keyspec",
  "useaccs_value", "useaccs_qual", "stafflinedef", "tab_string_list",
  "tab_item", "opt_str_acc", "opt_ticks", "flagval", "minscsep",
  "maxscsep", "minscpad", "maxscpad", "shorten_opts", "shorten_range",
  "pagesize", "orientation", "vcombine_value", "opt_vcombine_qualifier",
  "end_type", "updown", "majmin", "pedstyle", "transpose_interval",
  "title", "tfont", "title_font", "font_family", "title_size", "titleA",
  "paragraph", "opt_paratype", "paramname", "string", "music_input",
  "noteinfo", "init_staff", "sv_spec", "sv_map_list", "sv_map_entry",
  "map_start", "map_finish", "sv_map_item_list", "voice_id", "sv_and",
  "sv_item", "notecolon", "grp_stafflist", "grp_staff_item",
  "grp_staff_range", "voice_spec", "voice_tail", "groupinfo", "groupdata",
  "mid_meas_param", "mid_meas_list", "mid_meas_item", "mm_context",
  "mm_params", "mm_param_item", "grp_attributes", "styleinfo", "gtc",
  "extra_styleinfo", "alloc_grpsyl", "marklist", "marklistA", "markitem",
  "hor_offset", "opt_plus_or_minus", "other_attr", "attr_list",
  "attr_item", "alloc_marklist", "opt_dir", "opt_to_voice", "marks",
  "mark", "mark_item", "shorthand_mark", "notetype", "dir", "beammark",
  "time_val", "crossbeam", "basic_time_val", "opt_more_time",
  "more_time_item", "alloc_timelist", "opt_m", "dots", "padding",
  "padspec", "opt_minus", "group", "special_group", "extra_attr",
  "spec_grp_alloc", "extra_item", "note_opts", "notelist",
  "opt_other_staff", "css_with", "some_notes", "notedata", "notedata1",
  "opt_bend", "pitch", "opt_accidental", "opt_octave", "acc_symbol",
  "octave", "minuslist", "pluslist", "slur_item", "start_slur", "slurlist",
  "fullslurlist", "slurnote", "grp_locsave", "loc_variable", "ntuplet",
  "printtup", "start_tuplet", "rbrace", "opt_side", "opt_time",
  "lyricinfo", "lyric_id", "lyr_opt_place", "opt_place", "ph_opt_place",
  "staff_list", "staff_item", "staff_range", "more_lyric_ids", "@8",
  "verse_spec", "verselist", "verse_item", "verse_range",
  "alloc_lyr_grpsyl", "lyricdata", "lyr_tlist", "lyrics_timelist",
  "lyr_time_item", "lyr_tm", "lyrtuplet", "opt_space", "lyr_verse",
  "verse_string", "os_directive", "@9", "opt_temp_margin", "temp_margin",
  "margin_override", "opt_equals", "opt_semi", "directive", "barinfo",
  "precbartype", "barline", "bartype", "emptymeas_input", "bar_items",
  "bar_opt", "ending_info", "chk_dup_reh", "rehearsal_mark", "location",
  "alloc_loc", "plus_or_minus", "xcoord", "ycoord", "coord_setup",
  "expression", "direction", "floatnum", "opt_decimal_part", "numstr",
  "variable", "line", "line_alloc", "linetype", "opt_line_str", "curve",
  "curve_alloc", "curve_tail", "loc_list", "bulgelist", "bulge_value",
  "curve_loc", "stuff_info", "stuff_header", "midi", "midi_staff",
  "stuff_id", "stuff_type", "opt_size", "opt_modifier", "opt_dist",
  "stuff_dist", "opt_exclam", "opt_align", "stufflist", "stuff_item",
  "beat_offset", "gracebackup", "steps_offset", "opt_string", "til_clause",
  "til_val", "til_suffix", "til_offset", "roll_cmd", "opt_roll_dir",
  "roll_extent", "roll_start", "roll_end", "roll_offsetlist", "printcmd",
  "postscript", "printtype", "opt_loc", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   170,   171,   171,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   173,   173,   173,   173,   173,   173,
     174,   175,   174,   176,   174,   177,   177,   178,   179,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   194,   195,   195,   195,   195,
     195,   195,   196,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   197,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   198,   198,   198,   199,
     199,   199,   200,   200,   200,   201,   202,   202,   203,   203,
     203,   203,   205,   204,   206,   206,   207,   207,   208,   208,
     208,   208,   208,   209,   210,   210,   210,   211,   212,   212,
     213,   213,   214,   214,   215,   216,   217,   217,   217,   218,
     219,   219,   220,   221,   221,   221,   222,   223,   223,   223,
     223,   223,   223,   223,   223,   224,   225,   226,   225,   227,
     228,   227,   229,   229,   229,   229,   229,   230,   230,   231,
     232,   232,   233,   233,   234,   234,   235,   236,   236,   236,
     236,   237,   237,   237,   237,   238,   238,   239,   240,   240,
     241,   241,   242,   242,   243,   244,   244,   245,   246,   246,
     247,   247,   248,   248,   249,   249,   250,   250,   251,   251,
     252,   252,   253,   253,   254,   254,   255,   255,   256,   256,
     256,   257,   258,   259,   260,   260,   261,   261,   262,   262,
     263,   263,   263,   264,   265,   265,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   267,   267,
     268,   269,   269,   269,   270,   271,   271,   272,   272,   273,
     274,   275,   276,   276,   277,   277,   278,   279,   279,   280,
     281,   281,   282,   283,   283,   284,   284,   285,   285,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   291,   291,
     291,   292,   292,   293,   293,   293,   294,   295,   295,   295,
     296,   296,   297,   297,   298,   299,   299,   300,   300,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   302,
     302,   302,   303,   303,   304,   304,   305,   305,   306,   306,
     306,   306,   306,   306,   306,   307,   308,   308,   309,   309,
     310,   310,   311,   312,   312,   313,   313,   313,   313,   314,
     314,   314,   314,   315,   315,   316,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   320,   321,   322,   323,   323,
     324,   324,   325,   326,   327,   327,   328,   328,   329,   330,
     331,   332,   332,   332,   332,   332,   332,   332,   333,   333,
     334,   335,   335,   336,   337,   337,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   340,   340,   341,   342,   342,   343,   343,   344,   344,
     344,   344,   344,   345,   345,   345,   346,   346,   347,   347,
     348,   349,   350,   350,   350,   351,   351,   352,   353,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   355,   356,
     356,   356,   356,   357,   358,   359,   359,   360,   360,   361,
     362,   363,   364,   364,   365,   365,   366,   366,   366,   367,
     368,   368,   368,   369,   370,   369,   371,   371,   372,   372,
     373,   374,   374,   375,   376,   377,   377,   378,   378,   379,
     380,   380,   381,   382,   382,   383,   383,   384,   384,   385,
     385,   385,   386,   385,   385,   387,   387,   388,   389,   389,
     390,   390,   391,   391,   392,   392,   393,   394,   394,   395,
     396,   397,   397,   398,   398,   399,   399,   399,   399,   399,
     399,   399,   399,   400,   400,   401,   402,   402,   402,   402,
     403,   404,   405,   405,   406,   407,   408,   409,   409,   409,
     409,   409,   409,   409,   409,   410,   410,   410,   410,   410,
     411,   411,   411,   412,   412,   413,   414,   415,   416,   417,
     417,   418,   418,   419,   420,   421,   421,   422,   422,   423,
     423,   424,   425,   426,   427,   427,   427,   428,   429,   429,
     430,   431,   431,   431,   431,   431,   431,   432,   432,   433,
     433,   434,   434,   435,   435,   436,   436,   437,   437,   438,
     438,   439,   440,   441,   441,   442,   442,   443,   443,   443,
     444,   444,   445,   446,   446,   447,   447,   448,   449,   449,
     449,   450,   451,   451,   452,   452,   452,   453,   453,   454,
     454,   455,   456,   457,   457,   457
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     2,
       3,     0,     5,     0,     5,     1,     3,     1,     1,     3,
       2,     0,     0,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     1,     1,     4,     2,     3,     5,
       4,     4,     0,     4,     4,     4,     5,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     0,     4,     3,     4,     4,     3,     3,     3,
       5,     3,     3,     3,     9,     5,     1,     1,     1,     1,
       1,     2,     0,     1,     1,     0,     0,     1,     1,     1,
       3,     3,     0,     4,     4,     1,     0,     1,     0,     2,
       2,     1,     1,     0,     0,     1,     3,     3,     0,     2,
       0,     4,     0,     2,     1,     0,     0,     1,     3,     2,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       0,     4,     1,     1,     3,     3,     1,     1,     3,     1,
       0,     1,     0,     1,     3,     3,     2,     0,     1,     1,
       1,     2,     2,     1,     4,     1,     2,     4,     0,     1,
       0,     1,     1,     1,     1,     0,     2,     2,     0,     3,
       0,     3,     0,     4,     1,     2,     0,     1,     0,     2,
       0,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     1,     6,     2,     0,     1,     0,     1,     0,     3,
       1,     2,     3,     7,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     3,     1,     0,     1,     1,     1,     2,     3,
       1,     1,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     3,     2,     0,     2,     2,     4,     0,     2,     1,
       2,     1,     5,     0,     1,     1,     2,     4,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     4,     6,
       0,     3,     0,     4,     0,     0,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     2,     2,     2,     2,     1,
       1,     2,     0,     1,     0,     1,     1,     3,     1,     3,
       2,     2,     1,     3,     3,     0,     0,     1,     0,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     0,     1,
       0,     3,     1,     1,     0,     2,     4,     0,     0,     1,
       0,     2,     1,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     3,     2,     3,     2,     2,     1,     0,     2,
       2,     0,     3,     1,     0,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       5,     5,     3,     5,     7,     5,     4,     6,     4,     5,
       4,     0,     1,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       5,     1,     0,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     8,     0,
       1,     1,     1,     1,     1,     0,     1,     0,     2,     4,
       3,     1,     0,     1,     0,     1,     1,     1,     3,     2,
       0,     2,     2,     0,     0,     5,     1,     1,     1,     3,
       2,     0,     2,     0,     2,     0,     1,     1,     2,     2,
       3,     1,     5,     0,     1,     1,     2,     2,     5,     2,
       1,     1,     0,     3,     1,     0,     2,     3,     1,     1,
       0,     1,     0,     1,     1,     1,     3,     0,     4,     2,
       1,     0,     4,     0,     2,     1,     2,     1,     1,     3,
       3,     3,     7,     2,     1,     0,     1,     1,     1,     1,
       6,     0,     1,     1,     2,     1,     0,     3,     3,     3,
       4,     6,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     1,     1,     1,     7,     0,     0,
       1,     0,     4,     7,     0,     2,     2,     1,     3,     1,
       3,     2,     1,     3,     7,     6,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     0,     3,     0,
       1,     0,     2,     2,     3,     0,     1,     0,     2,     1,
       2,     5,     2,     0,     4,     0,     4,     0,     1,     1,
       0,     2,     2,     2,     2,     2,     4,     5,     0,     1,
       1,     2,     1,     2,     0,     2,     3,     2,     3,     3,
       3,     1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,    33,     0,     0,     0,   217,
       0,     0,    35,    37,     0,   590,   482,   612,     0,   607,
       0,    34,   615,    12,     0,   616,   132,     0,   225,   614,
       0,   661,   662,     0,     0,     0,     0,     0,   648,   613,
      32,   522,     0,     0,     0,    32,     0,     0,   258,     0,
       0,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     2,   532,    14,    15,    32,
      16,    10,    17,    18,     5,     0,     0,     6,     0,     7,
       0,     0,     8,     0,     0,   263,   532,     0,   543,   520,
     537,   521,   534,     0,     0,   617,   610,   535,   524,   663,
     663,    13,     0,   125,   384,     0,     0,     0,     0,     0,
       0,   483,     0,     0,   481,     0,    41,   532,    47,   384,
       0,     0,     0,   113,    95,     0,     0,   650,   649,     0,
      31,   525,   384,     0,     0,    21,     0,   384,     0,   106,
      38,     0,    72,   218,   214,     0,     0,   235,   233,   257,
     239,   256,   234,   255,   249,   241,   226,   247,   232,   242,
     246,   252,   240,   237,   245,   228,   236,   229,   254,   231,
     250,   230,   251,   238,   248,   244,   253,   243,   227,    71,
       0,    52,     0,    23,     0,     0,     1,     3,   533,     4,
      19,    45,    44,    43,     0,   611,   216,     0,     0,   260,
     270,   283,    39,     0,   266,   267,     0,   265,   274,   277,
     280,     0,     9,   519,   594,   588,   589,   617,     0,     0,
     609,   608,   606,     0,   619,   561,   664,   665,     0,     0,
       0,   580,     0,   126,   385,     0,     0,    67,   203,   202,
      77,    66,    48,    65,   433,     0,    61,   434,   503,   487,
     490,   493,   486,     0,    89,    90,    70,   262,     0,     0,
       0,   208,   210,    79,    83,   194,   196,     0,   114,    96,
      78,   130,   131,    59,   652,     0,   654,    20,   523,   188,
       0,   184,   185,   190,     0,   173,   162,    64,     0,    82,
     105,   372,   373,   107,    74,   380,   153,   152,   156,   159,
      63,   147,   146,   149,     0,   157,     0,     0,     0,   215,
     213,   205,   204,     0,    81,   182,   183,    62,   167,   198,
      87,    88,    86,    69,     0,    92,    68,   142,   141,   140,
     137,   138,   139,   144,   143,    60,   133,   136,   218,   259,
      36,     0,   282,   279,   293,   268,     0,   272,   276,     0,
       0,   287,    40,   278,    11,   554,     0,     0,   548,     0,
       0,     0,   384,   555,   545,   544,   547,     0,     0,     0,
     482,   540,   536,   541,   633,   603,   629,   635,     0,   620,
     482,   566,   660,   659,   585,   582,   583,     0,   118,    58,
     127,   384,    42,   439,   442,   440,   441,   438,   206,   206,
     435,   473,   503,   368,   479,     0,   503,   507,     0,   511,
       0,     0,   489,     0,   480,    91,    46,    54,   209,   197,
      51,   195,   118,    57,   115,   102,   108,    97,    99,    98,
     653,     0,     0,   651,   530,   526,   384,    76,   187,     0,
      75,     0,    50,    31,    25,    27,     0,   172,   163,   171,
     384,   374,     0,   145,   161,   150,     0,     0,    73,     0,
     532,   220,   211,     0,   169,   168,   170,   166,    53,   200,
      31,    28,     0,    94,    93,    55,     0,     0,     0,   284,
       0,   293,   289,   314,   294,   295,   291,   293,   271,     0,
     269,   275,   281,     0,     0,   285,   553,   459,   461,   465,
     462,   463,   464,   466,   467,   460,   546,     0,     0,     0,
       0,   216,   602,     0,     0,     0,     0,   539,     0,   632,
     630,     0,   637,   618,     0,     0,     0,   581,   584,    49,
       0,   129,     0,     0,   207,   164,   165,   503,   369,   513,
       0,     0,   504,   515,   508,   509,   492,   491,   488,     0,
     120,     0,     0,   112,   111,    56,     0,     0,   647,   655,
     531,     0,     0,   186,   192,    22,     0,     0,   175,   178,
      85,   381,   378,   148,     0,   155,   158,   154,   219,     0,
     221,    80,   201,   199,    24,     0,    30,   135,   134,   532,
     298,   299,   300,     0,   290,   314,   404,   368,   307,   296,
     293,   273,   288,   287,   550,   549,   551,   383,   214,     0,
       0,   538,   621,   264,     0,   563,   562,     0,   638,   639,
     640,   621,     0,     0,     0,     0,     0,   586,   564,   572,
       0,   119,   128,   384,   474,     0,   514,   510,   497,   501,
       0,   496,   498,   517,   516,   494,     0,   117,   116,     0,
     109,   110,   101,   100,   657,     0,   656,   529,   527,   528,
     189,   384,   191,    26,   174,   176,   180,   179,   379,   375,
     104,   377,   151,   212,   222,    29,     0,     0,     0,     0,
       0,   301,     0,   315,   334,   387,   398,     0,   386,   401,
     306,   475,   286,   617,     0,   591,     0,   605,     0,     0,
       0,     0,     0,   627,     0,   565,     0,     0,     0,   574,
       0,     0,     0,     0,   477,     0,   500,     0,     0,     0,
     122,   124,   103,   658,     0,   181,   436,     0,   223,     0,
       0,     0,   297,     0,   314,   359,   361,   364,     0,   384,
     360,   332,     0,     0,     0,   363,   345,   362,     0,   316,
     317,   321,   323,   322,   382,   320,     0,   370,   367,   342,
     366,   484,   384,   346,   346,     0,   335,   336,   338,   388,
       0,     0,     0,   451,   391,   346,   389,   397,   452,   411,
     416,   413,   412,   407,   408,     0,     0,   414,   415,   410,
     417,   403,   400,   404,   398,   406,   431,   476,     0,     0,
     384,     0,   593,   216,   587,     0,   625,   622,   542,   634,
     636,   633,   641,   631,     0,   604,   560,     0,     0,   567,
     568,   569,   575,   578,   579,   576,   577,   573,   384,     0,
     512,   502,     0,   499,   495,     0,     0,   384,   446,   448,
     443,   177,   437,   444,   445,   380,   303,   304,   305,   302,
     308,   458,     0,   330,   329,   325,     0,   333,   326,   327,
     328,     0,   310,     0,   340,     0,   365,   485,   341,     0,
     348,   347,   348,   292,     0,   399,   393,   395,   436,   396,
     348,   453,   436,     0,   454,   455,   409,     0,     0,   405,
       0,   436,   432,   419,   180,   434,   469,   559,   557,   558,
     556,   621,     0,   596,   599,   595,   597,   218,   625,   626,
     623,   633,   635,   642,   628,   570,     0,    84,   478,   518,
     123,   121,   193,   447,   449,   376,   324,   331,   356,   355,
     358,   357,   354,   319,   350,   352,   353,     0,   312,   318,
       0,   339,     0,   343,   344,   337,   394,   392,   457,   346,
     456,   418,   402,   422,     0,     0,     0,   431,   436,     0,
     431,   472,   470,   471,   477,   552,   601,   384,     0,     0,
     624,     0,   635,   644,   643,     0,     0,     0,   309,   371,
       0,   348,   436,   431,     0,   426,     0,   431,   430,     0,
     428,     0,   600,   598,   592,   633,   645,   571,   351,   311,
     315,   349,   450,   420,   421,   431,   425,     0,   423,   429,
     468,   635,     0,   427,   431,   646,   313,   424
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    65,    66,    67,   284,   324,   443,   444,   470,
     471,   277,   130,    68,    69,    70,    71,    72,    73,   201,
     351,   231,   235,    74,   193,    75,   319,   306,   323,   256,
     475,   269,   426,   427,   428,   552,   429,   294,   555,   268,
     423,   424,   531,   647,   836,   720,   233,   389,   390,   273,
      76,   335,   336,   337,   300,   301,   452,   302,   574,   303,
     304,   305,   453,   449,   246,   317,   467,   287,   567,   568,
     666,   726,   318,   282,   440,   279,   437,   442,   662,   266,
     420,   468,   583,   240,   313,   535,   263,   463,    77,   143,
     310,   144,   308,   460,    79,    80,   179,   892,    82,    83,
      84,   203,   204,   205,   206,   490,   346,   207,   349,   208,
     344,   209,   210,   342,   353,   495,   481,   482,   483,   484,
     485,   593,   680,   681,   596,   597,   938,   978,   598,   748,
     749,   750,   855,   856,   765,   766,   767,   861,   870,   943,
     933,   934,   935,   936,   751,   871,   768,   539,   866,   295,
     572,   669,   727,   670,   451,   753,   754,   236,   684,   685,
     686,   687,   875,   769,   688,   792,   793,   689,   794,   795,
     893,   796,   399,   841,   400,   842,   843,   844,   777,   778,
     883,   884,   885,   755,   627,   486,   964,   402,   635,   798,
     830,    85,   112,   113,   114,   868,   251,   252,   412,   414,
     719,   640,   641,   642,   716,   403,   404,   405,   406,   407,
     408,   409,   637,   542,   543,    86,   131,   278,   435,   658,
     561,   189,    87,    88,   218,   372,   373,   517,   213,   365,
     366,   511,   901,   512,   381,   617,   525,   704,   526,   628,
     827,   629,   527,   385,   630,    89,   368,    90,   804,    91,
     367,   802,   905,   903,   904,   513,    92,    93,    94,   222,
      95,    96,   224,   380,   697,   807,   910,   815,   375,   376,
     377,   519,   522,   620,   702,   812,   913,   973,    97,   129,
     275,   276,   433,   558,    98,    99,   100,   228
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -823
static const yytype_int16 yypact[] =
{
    1016,    22,   236,   297,   315,  -823,   357,   424,   455,  -823,
     466,   472,  -823,  -823,   476,  -823,   103,  -823,   491,  -823,
     214,  -823,  -823,  -823,   495,  -823,  -823,   521,  -823,  -823,
     528,   531,  -823,   532,   533,   534,   535,   536,    15,  -823,
    -823,  -823,   539,   548,   549,  -823,   552,   553,  -823,   554,
     556,   335,   557,   558,   555,   559,   561,  1150,   562,   563,
     564,  -823,   565,   566,   882,  -823,   478,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   266,   568,  -823,   570,  -823,
     511,   -33,  -823,   526,   213,  -823,   478,   527,  -823,  -823,
     338,  -823,  -823,   592,    55,   543,  -823,  -823,  -823,   416,
     416,  -823,   163,  -823,   589,   601,   385,   575,   163,   574,
     403,  -823,   602,    70,  -823,   483,  -823,   478,    44,   589,
     165,   335,    83,  -823,  -823,   509,    30,  -823,  -823,   214,
    -823,  -823,   589,   214,   163,  -823,   169,   589,   335,   368,
     522,   346,  -823,   560,   580,    24,   475,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     499,  -823,    87,  -823,   214,   499,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   324,  -823,   555,   492,   397,  -823,
    -823,   606,  -823,   608,   576,  -823,   214,   625,  -823,    74,
    -823,   567,  -823,   474,  -823,  -823,   569,   543,   623,   163,
    -823,   625,  -823,   214,   571,  -823,  -823,  -823,   335,   335,
     547,   610,   619,   214,  -823,   620,   214,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,    80,  -823,    80,     3,  -823,
     198,   621,  -823,   214,  -823,  -823,  -823,  -823,   214,   163,
     542,  -823,  -823,  -823,   522,  -823,   550,   214,   214,   401,
    -823,  -823,  -823,  -823,   214,   628,   500,  -823,   599,   631,
     214,  -823,   633,   634,   214,   586,   310,  -823,   636,   522,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   327,   551,  -823,   245,  -823,   368,   214,   335,  -823,
    -823,  -823,  -823,   493,  -823,  -823,  -823,  -823,   110,   214,
    -823,  -823,  -823,  -823,   214,   -13,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   463,  -823,  -823,   560,  -823,
    -823,   214,  -823,  -823,   336,  -823,   388,   625,  -823,   214,
     214,   524,  -823,  -823,  -823,  -823,   335,   520,  -823,   622,
     624,   626,   589,  -823,  -823,  -823,  -823,   590,   590,   646,
     103,  -823,  -823,  -823,   597,   163,  -823,   611,   572,  -823,
     103,  -823,   522,   522,  -823,  -823,   547,   163,   642,   650,
    -823,   589,  -823,  -823,  -823,  -823,  -823,  -823,   504,   504,
    -823,  -823,   616,   368,  -823,    -5,    10,  -823,   545,  -823,
     214,   214,  -823,   214,   546,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,   642,   655,  -823,  -823,   488,   656,  -823,  -823,
    -823,   163,   214,  -823,   638,  -823,   589,  -823,  -823,   214,
    -823,   163,  -823,   625,  -823,   658,   577,  -823,  -823,  -823,
     589,   651,   346,  -823,  -823,  -823,   353,   214,  -823,   573,
     478,   -33,  -823,   214,  -823,  -823,  -823,  -823,  -823,   523,
     625,  -823,    74,  -823,  -823,  -823,   324,   324,   335,  -823,
     -23,   393,  -823,   629,   607,  -823,  -823,   336,  -823,   214,
    -823,  -823,  -823,   214,   214,  -823,   522,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   335,   214,   214,
     163,   555,  -823,   530,   537,   581,    70,   653,   662,  -823,
    -823,    17,   428,  -823,    70,   668,   228,  -823,  -823,  -823,
     214,  -823,   214,   670,  -823,  -823,  -823,   260,  -823,   627,
     436,   -41,    -5,  -823,  -823,  -823,  -823,  -823,  -823,   598,
     635,   214,   401,   630,   639,  -823,   401,   583,   163,   214,
    -823,   325,   214,  -823,   677,  -823,   214,   237,  -823,    80,
    -823,  -823,   218,   551,   346,  -823,  -823,  -823,  -823,   632,
     -33,  -823,  -823,  -823,  -823,   214,  -823,  -823,  -823,   -20,
    -823,  -823,  -823,    36,  -823,   683,    42,   368,  -823,  -823,
     312,   625,  -823,   689,   522,  -823,  -823,  -823,   580,   590,
     590,  -823,   426,   456,   214,  -823,  -823,   163,  -823,   522,
     578,   426,   228,   643,   644,   228,   163,  -823,    79,  -823,
     686,  -823,  -823,   589,  -823,   214,  -823,  -823,  -823,   692,
     605,   700,  -823,  -823,  -823,  -823,   335,  -823,  -823,    28,
    -823,  -823,  -823,  -823,  -823,   593,  -823,  -823,  -823,  -823,
    -823,   589,  -823,  -823,  -823,  -823,   582,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   522,  -823,   640,   690,   691,   693,
     430,  -823,   614,   321,    64,  -823,  -823,   185,  -823,    34,
    -823,   617,  -823,   543,    19,   579,   375,  -823,   698,   613,
     637,   163,   609,   728,   615,    79,   228,   228,    56,  -823,
     228,   228,   433,   718,   719,   214,  -823,   335,   214,    70,
     720,   522,  -823,  -823,   722,  -823,   238,   365,  -823,   726,
     214,   499,  -823,    36,  -823,  -823,  -823,  -823,   520,   589,
    -823,   131,   335,   163,   214,  -823,  -823,  -823,   641,   618,
    -823,  -823,  -823,  -823,  -823,  -823,   214,   584,  -823,  -823,
    -823,   645,   589,    27,    27,   652,   725,  -823,  -823,   185,
     520,   316,   335,  -823,  -823,    27,  -823,  -823,    -4,  -823,
    -823,  -823,  -823,  -823,  -823,   684,   577,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   257,  -823,   214,    77,
     589,   590,  -823,   555,  -823,   163,   705,  -823,  -823,  -823,
    -823,   487,  -823,  -823,   214,  -823,  -823,    63,   264,  -823,
     674,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   589,   368,
    -823,  -823,   322,  -823,   621,   335,   647,   589,  -823,  -823,
    -823,  -823,  -823,   729,   654,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,   214,   217,   222,  -823,   163,  -823,   522,  -823,
    -823,    60,   730,   321,  -823,   648,  -823,  -823,  -823,   163,
     604,  -823,   604,  -823,    64,  -823,  -823,  -823,   238,   522,
     604,  -823,   238,   657,   577,  -823,  -823,   649,   157,   185,
     355,   216,   522,  -823,   582,    49,   296,  -823,  -823,  -823,
     522,   708,   163,   737,  -823,   612,  -823,   560,   705,  -823,
    -823,   204,   611,  -823,  -823,  -823,   228,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   651,  -823,  -823,  -823,  -823,
    -823,  -823,   522,   739,  -823,  -823,  -823,   733,  -823,  -823,
     660,  -823,   600,  -823,  -823,  -823,  -823,  -823,  -823,    27,
    -823,  -823,  -823,  -823,   664,   665,   238,   335,   276,   210,
     335,  -823,  -823,  -823,   719,  -823,  -823,   589,   590,   335,
    -823,   163,   611,  -823,  -823,    73,    60,   735,   709,  -823,
     214,   604,   238,   335,   666,  -823,   136,   335,  -823,   667,
    -823,   661,  -823,  -823,   522,   597,  -823,  -823,  -823,  -823,
     321,  -823,  -823,  -823,  -823,   335,  -823,   671,  -823,  -823,
    -823,   611,   659,  -823,   335,  -823,  -823,  -823
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -823,  -823,   707,  -823,  -823,  -823,  -823,  -823,   203,  -823,
     188,   -18,   454,  -823,  -823,  -823,  -823,  -823,  -823,  -106,
    -249,   -19,  -131,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,   223,   227,  -823,  -128,  -823,  -823,  -823,
    -823,   242,   367,  -823,  -823,   -39,  -823,  -823,   262,  -823,
    -823,  -823,    88,  -823,  -823,  -823,  -823,   345,  -823,   224,
    -823,   344,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   234,
    -823,   -92,  -173,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   404,  -823,  -823,  -823,  -189,
     196,    13,  -330,  -823,  -823,  -823,  -823,     0,   192,  -823,
    -823,  -823,  -823,   603,  -823,  -823,  -823,   -75,    -2,   457,
    -823,  -253,   458,  -823,  -286,   206,   326,  -439,  -823,  -823,
     328,  -823,  -823,    78,  -823,  -823,  -823,  -823,  -558,  -186,
    -823,   -48,  -823,  -823,  -823,  -823,   -58,  -823,  -736,  -822,
    -823,  -159,  -823,  -823,  -823,  -661,  -823,   221,  -823,    92,
    -823,  -823,  -823,  -823,   -25,  -823,   663,  -115,  -823,  -823,
    -823,  -823,   134,    29,  -823,  -823,  -823,    32,  -823,    40,
    -548,  -108,   -73,  -610,  -240,  -767,  -823,  -823,  -823,  -823,
    -823,  -823,   -57,  -823,  -339,  -823,  -823,  -318,   229,  -823,
    -136,  -823,  -823,  -823,   149,  -823,  -489,   417,  -823,  -823,
    -823,  -823,  -823,   113,  -823,  -823,  -823,  -823,   432,  -366,
    -823,  -823,  -823,  -823,   290,  -823,  -823,  -823,  -823,  -823,
    -823,   -71,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,   -90,  -823,  -538,  -823,  -823,  -823,  -581,
    -823,   -78,  -823,   450,  -823,  -823,  -823,   669,  -823,  -823,
    -823,  -823,  -823,  -823,  -130,  -589,  -823,  -823,  -823,  -823,
    -823,  -823,  -201,  -823,  -600,  -823,   -70,  -823,  -823,   464,
    -823,  -779,  -757,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   740
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -590
static const yytype_int16 yytable[] =
{
      81,   117,   247,   258,   259,   398,   288,   338,   478,   227,
     227,   293,   326,    78,   267,   211,   370,   280,   506,   221,
     694,   703,   752,   274,   232,   430,   487,   612,   872,   895,
     242,   445,   912,   469,   671,   621,   800,   683,   271,   880,
     544,   705,   594,   615,   708,   127,   257,   779,   473,   556,
     944,   140,   780,   540,   311,   677,   283,   737,   947,   393,
     401,  -505,   710,   220,    81,   202,   197,   401,  -506,   710,
     234,   472,   781,   756,   197,   202,   394,    78,   249,   710,
     757,   198,  -390,   782,   881,   710,   928,   197,   643,   929,
     393,   245,   474,  -390,   250,   350,   758,  -390,   783,   784,
     785,   244,   590,   759,   786,   760,   101,   394,    48,   188,
     202,   930,   395,   591,   281,  -390,   396,   286,   464,   959,
     292,   264,   299,   955,   616,   817,   818,   678,   454,   820,
     821,   347,   972,   787,  -384,   711,    48,   897,   289,   244,
     592,   374,   711,   395,  -505,   116,   788,   396,   320,   722,
     321,  -506,   711,  -390,   898,   974,   789,   853,   711,  1002,
     116,   594,   838,   487,   116,   325,   899,   761,   272,   487,
     779,   544,   801,   128,   260,   780,   850,   819,   458,   397,
     265,   417,   312,   931,   915,   745,   586,   202,   244,   984,
     352,  -390,   230,   790,   997,   781,   465,   466,   762,   763,
     791,    48,   752,   857,   378,   679,   782,   602,   410,   111,
     397,   764,   906,   981,   388,   996,  1011,   392,    48,  1007,
     393,   783,   784,   785,   411,   770,   116,   786,   382,   383,
     834,   623,   624,   261,   415,   479,   771,   394,   854,   416,
     772,   244,   838,   839,   615,   603,  -563,   510,   421,   422,
     292,  -562,   322,   116,  1015,   352,   787,   230,   773,   116,
     533,   438,   244,   952,   838,   202,   262,   393,   946,   788,
     710,   200,   948,   395,   518,   538,   102,   396,   514,   789,
     668,   957,   487,   838,   394,   916,   956,   292,   459,   497,
     498,   499,   500,   501,   502,   503,   774,   374,   625,   504,
     352,   965,   838,   116,   116,   202,   116,  -563,   461,   529,
     656,   971,  -562,   445,   285,   244,   790,   401,   116,   570,
     395,   562,   202,   839,   396,   616,   559,   890,   116,   667,
     202,   202,   472,   505,   775,   975,   657,   103,   569,   752,
     397,   447,   244,   711,   735,   839,   986,   116,   987,   736,
     191,   737,   456,   557,   230,   104,   496,   961,   664,   962,
     327,   738,   214,   564,   839,   393,   116,   739,   296,   401,
     740,   297,  1003,   448,   634,   741,   742,   457,   626,   993,
     743,   838,   394,   839,   292,   963,   480,   397,   315,   579,
     316,   546,   547,   401,   250,   192,   328,   105,    48,   851,
     238,   805,   329,   891,   230,   541,   215,   330,   216,   985,
     480,  -160,   990,   202,   601,   116,   331,   362,   395,   332,
     563,   244,   396,   239,   333,   565,   634,   298,   653,   197,
     290,   876,   607,   299,   575,  1004,   116,   299,   577,  1008,
     334,   566,   217,   116,   581,   116,   291,   413,   877,   291,
     401,   919,   584,   352,   744,   116,  -160,  1013,   116,   569,
     244,   580,   839,   290,   106,   116,  1017,   480,   585,   538,
     202,   425,   696,   476,   352,   352,    48,  -261,   589,   745,
     655,   340,   291,   659,   477,   397,   225,   746,   747,   605,
     606,   116,   799,   116,   822,   107,   823,   250,   824,   135,
     825,   226,   713,   488,   197,   250,   108,   604,   244,   355,
     356,   631,   109,   388,   357,   183,   110,   489,   676,   516,
     695,   639,   619,   190,   608,   253,   116,   358,    16,   524,
     724,   115,   422,   292,   359,   118,    20,   292,   826,   700,
     352,   638,   541,   660,   254,   493,   255,   202,   709,   911,
     494,   360,   553,   554,   732,   299,   894,   518,   848,   733,
     315,   119,   316,   361,   587,   588,   202,   618,   120,    48,
     362,   121,   122,   123,   124,   125,   126,   969,   292,   132,
     674,   497,   498,   499,   500,   501,   502,   503,   133,   134,
     363,   504,   136,   137,   138,   699,   139,   141,   142,   145,
       9,   146,   180,   181,   182,   184,   185,   188,   194,   196,
     199,   212,   219,   223,   907,   234,   714,   195,   806,   237,
     241,   243,   248,   811,   852,   505,   270,   309,   343,   197,
     307,   314,   341,   339,   200,   348,   371,   384,    15,   386,
     387,   391,   413,   418,   419,   434,   721,   869,   431,   379,
     954,   354,   436,   432,   439,   441,   446,   450,   455,   515,
     225,   462,   507,   878,   508,   859,   509,   518,   530,   521,
     882,   532,   534,   401,   545,   549,   551,   556,   560,   350,
     571,   480,   244,   609,   582,   902,   613,   595,   614,   622,
     610,   633,   636,   523,   578,   650,   831,   917,   661,   639,
     250,   918,   611,   651,   645,   646,   922,   840,   292,   682,
     493,   847,   654,   706,   707,   712,   673,   832,   715,   989,
     717,   718,   723,   797,   728,   860,   701,   908,   725,   734,
     729,   730,   808,   731,   809,   814,   816,   864,   813,   828,
     829,   835,   858,   837,   846,   803,   874,   863,   909,   886,
     865,   867,   810,   711,   696,   923,   862,   942,   967,   937,
     976,   924,   977,   980,   999,   968,   979,  1000,   921,   663,
     951,   187,   879,   675,  1016,   649,   882,   840,   927,   896,
     949,   873,   953,   652,   940,   982,   983,  1005,  1009,   550,
    1010,   941,  1014,   648,   632,   914,   920,   573,   672,   900,
     576,   665,   958,   536,   693,   698,   491,   345,   492,   692,
     292,   849,   599,   600,  1012,   939,   945,   998,   690,   845,
     925,   776,   960,   889,   966,   888,   887,   950,   991,   691,
     548,   833,   644,   926,   537,   721,   528,   992,   970,   520,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   988,   902,     0,     0,     0,     0,     0,     0,   840,
       0,   932,     0,   840,     0,     0,     0,     0,     0,     0,
       0,   840,   840,     0,     0,     0,   364,     0,  1006,     0,
       0,     0,   186,     1,     0,   369,     0,     2,     0,     0,
       0,     0,     0,   995,     3,  -589,     4,     5,     0,     0,
       0,     6,     0,     0,     0,     0,  -589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     8,     9,    10,  -216,
      11,     0,    12,     0,    13,     0,     0,   840,    14,   840,
    -264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -589,    15,  -589,     0,    16,    17,     0,    18,    19,     0,
       0,  1001,    20,   840,    21,    22,    23,   840,     0,   994,
       0,     0,  -264,    24,    25,    26,   932,     0,    27,     0,
    -224,    28,    29,     0,    30,     0,  -589,     0,     0,     0,
      31,    32,    33,     0,    34,    35,     0,     0,     0,     0,
      36,    37,    38,     0,     0,    39,     0,    40,    41,    42,
      43,     0,     0,    44,     0,     0,     0,     1,    45,    46,
       0,     2,    47,    48,    49,    50,    51,     0,     3,  -589,
       4,     5,    52,    53,    54,     6,    55,    56,     0,    57,
    -589,    58,    59,     0,    60,    61,    62,     0,     0,     0,
       0,    63,     0,     7,     0,     0,     0,     0,     0,     0,
       8,     9,    10,  -216,    11,     0,    12,     0,    13,     0,
       0,     0,    14,     0,  -264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -589,    15,  -589,     0,    16,    17,
       0,    18,    19,     0,     0,     0,    20,     0,    21,    22,
      23,     0,     0,     0,     0,     0,  -264,    24,    25,    26,
       0,     0,    27,     0,  -224,    28,    29,     0,    30,     0,
    -589,     0,     0,     0,    31,    32,    33,     0,    34,    35,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    39,
       0,    40,    41,    42,    43,     0,     0,    44,     0,     0,
       0,     0,    45,    46,     0,   147,    47,    48,    49,    50,
      51,     0,   148,     0,     0,     0,    52,    53,    54,   149,
      55,    56,     0,    57,     0,    58,    59,     0,    60,    61,
      62,     0,     0,     0,     0,    63,     0,   150,     0,     0,
       0,     0,     0,     0,   151,     0,   152,     0,   153,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,   157,     0,     0,   158,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,   162,   163,
       0,     0,     0,     0,     0,     0,     0,   164,   165,     0,
       0,   166,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,   168,   169,     0,     0,     0,     0,     0,     0,
     170,   171,     0,     0,   172,   173,     0,     0,     0,   174,
     175,     0,   176,     0,   177,     0,     0,     0,     0,   178
};

static const yytype_int16 yycheck[] =
{
       0,    20,   110,   118,   119,   245,   137,   196,   338,    99,
     100,   139,   185,     0,   122,    86,   217,   132,   357,    94,
     609,   621,   683,   129,   102,   274,   344,   516,   764,   796,
     108,   284,   811,   319,   572,   524,    17,   595,     8,   775,
     406,   622,   481,    26,   625,    30,   117,    13,    61,    21,
     872,    51,    18,    58,    30,    19,   134,    30,   880,    10,
      57,    58,     6,     8,    64,    84,   107,    57,    58,     6,
      26,   324,    38,     9,   107,    94,    27,    64,     8,     6,
      16,    81,    40,    49,    88,     6,    26,   107,   129,    29,
      10,   110,   105,    51,   113,    21,    32,    55,    64,    65,
      66,   105,   125,    39,    70,    41,    84,    27,   141,   129,
     129,    51,    63,   136,   133,    73,    67,   136,     8,    70,
     139,   121,   141,   890,   107,   706,   707,    91,   301,   710,
     711,   206,   911,    99,    90,    79,   141,    60,   138,   105,
     163,   219,    79,    63,   141,    90,   112,    67,    61,   121,
      63,   141,    79,   111,    77,   912,   122,    26,    79,   981,
      90,   600,    26,   481,    90,   184,    89,   103,   138,   487,
      13,   537,   153,   158,     9,    18,   734,   121,   306,   130,
      97,   259,   158,   123,   121,   158,   472,   206,   105,   956,
     209,   149,    29,   159,   121,    38,    86,    87,   134,   135,
     166,   141,   863,   741,   223,   169,    49,   493,    10,   106,
     130,   147,   801,   949,   233,   972,   995,   236,   141,   986,
      10,    64,    65,    66,    26,    40,    90,    70,   228,   229,
     719,     3,     4,    68,   253,   341,    51,    27,   107,   258,
      55,   105,    26,   107,    26,   494,    29,   362,   267,   268,
     269,    29,   165,    90,  1011,   274,    99,    29,    73,    90,
     391,   280,   105,   106,    26,   284,   101,    10,   878,   112,
       6,    58,   882,    63,    70,   403,    40,    67,   368,   122,
      62,   891,   600,    26,    27,    21,    70,   306,   307,    61,
      62,    63,    64,    65,    66,    67,   111,   375,    70,    71,
     319,   901,    26,    90,    90,   324,    90,    90,   308,   387,
     559,   107,    90,   566,   145,   105,   159,    57,    90,   450,
      63,   436,   341,   107,    67,   107,   432,    70,    90,   569,
     349,   350,   585,   105,   149,   916,    11,    40,   446,  1000,
     130,    31,   105,    79,    23,   107,    70,    90,   958,    28,
      84,    30,   107,   431,    29,    40,   356,    61,   121,    63,
      36,    40,    24,   441,   107,    10,    90,    46,    22,    57,
      49,    25,   982,    63,   114,    54,    55,   132,   150,   968,
      59,    26,    27,   107,   403,    89,    74,   130,    61,   460,
      63,   410,   411,    57,   413,   129,    72,    40,   141,   738,
      15,    26,    78,   146,    29,   405,    68,    83,    70,   957,
      74,    84,   960,   432,   489,    90,    92,    96,    63,    95,
     439,   105,    67,    38,   100,   443,   114,    81,   556,   107,
      62,   770,   510,   452,    81,   983,    90,   456,   457,   987,
     116,   443,   104,    90,   463,    90,    81,    21,   132,    81,
      57,   129,   470,   472,   133,    90,   129,  1005,    90,   567,
     105,   461,   107,    62,    40,    90,  1014,    74,   470,   597,
     489,    70,    46,    10,   493,   494,   141,    84,   478,   158,
     558,    84,    81,   561,    21,   130,    70,   166,   167,   508,
     509,    90,   693,    90,    61,    40,    63,   516,    65,    45,
      67,    85,   633,   115,   107,   524,    40,   507,   105,    35,
      36,   530,    40,   532,    40,    61,    40,   129,   589,   370,
     610,   540,   522,    69,   511,    42,    90,    53,    72,   380,
     661,    40,   551,   552,    60,    40,    80,   556,   105,   617,
     559,   105,   542,   562,    61,    21,    63,   566,   626,    62,
      26,    77,    64,    65,   124,   574,   796,    70,   731,   129,
      61,    40,    63,    89,   476,   477,   585,   139,    40,   141,
      96,    40,    40,    40,    40,    40,    40,   907,   597,    40,
     580,    61,    62,    63,    64,    65,    66,    67,    40,    40,
     116,    71,    40,    40,    40,   614,    40,    40,    40,    40,
      45,    40,    40,    40,    40,    40,    40,   129,    40,    98,
      84,    84,    20,    70,   803,    26,   635,    47,   696,    18,
      45,    47,    20,   701,   739,   105,   117,    47,    20,   107,
      70,   156,    26,   141,    58,    10,    13,    90,    69,    29,
      21,    21,    21,   101,    94,    46,   646,   762,    20,    78,
     890,    84,    21,   153,    21,    21,    70,    21,   107,    13,
      70,   168,    40,   771,    40,   743,    40,    70,    26,    58,
     778,    21,   168,    57,   129,   129,    21,    21,    40,    21,
      29,    74,   105,   153,   161,   800,    33,    58,    26,    21,
     153,    21,    65,   121,   121,    65,   715,   828,    21,   718,
     719,   829,   121,    64,   106,    70,   837,   726,   727,    26,
      21,   730,   129,    70,    70,    29,    84,   717,    26,   959,
     115,    21,   129,   106,    84,   744,   148,   805,   146,   115,
      40,    40,    34,    40,   121,     7,   121,   756,   129,    21,
      21,    21,   742,    21,    18,   166,    21,   129,    43,    65,
     166,   106,   115,    79,    46,    26,   115,   153,    21,    29,
      21,   107,    29,   163,    29,   153,   106,    58,   121,   566,
     121,    64,   772,   585,   115,   552,   884,   796,   856,   798,
     123,   129,   890,   556,   136,   121,   121,   121,   121,   422,
     129,   869,   121,   551,   532,   814,   835,   452,   574,   799,
     456,   567,   894,   399,   608,   613,   349,   204,   350,   603,
     829,   733,   484,   487,  1000,   863,   874,   976,   597,   727,
     845,   687,   895,   794,   902,   793,   786,   884,   964,   600,
     413,   718,   542,   852,   402,   835,   386,   967,   908,   375,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   959,   967,    -1,    -1,    -1,    -1,    -1,    -1,   878,
      -1,   861,    -1,   882,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   890,   891,    -1,    -1,    -1,   213,    -1,   986,    -1,
      -1,    -1,     0,     1,    -1,   216,    -1,     5,    -1,    -1,
      -1,    -1,    -1,   971,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    -1,    50,    -1,    52,    -1,    -1,   956,    56,   958,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    72,    73,    -1,    75,    76,    -1,
      -1,   980,    80,   982,    82,    83,    84,   986,    -1,   969,
      -1,    -1,    90,    91,    92,    93,   976,    -1,    96,    -1,
      98,    99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
     108,   109,   110,    -1,   112,   113,    -1,    -1,    -1,    -1,
     118,   119,   120,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,    -1,   131,    -1,    -1,    -1,     1,   136,   137,
      -1,     5,   140,   141,   142,   143,   144,    -1,    12,    13,
      14,    15,   150,   151,   152,    19,   154,   155,    -1,   157,
      24,   159,   160,    -1,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    72,    73,
      -1,    75,    76,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    -1,    96,    -1,    98,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,    -1,   131,    -1,    -1,
      -1,    -1,   136,   137,    -1,     5,   140,   141,   142,   143,
     144,    -1,    12,    -1,    -1,    -1,   150,   151,   152,    19,
     154,   155,    -1,   157,    -1,   159,   160,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,    -1,    -1,   154,   155,    -1,    -1,    -1,   159,
     160,    -1,   162,    -1,   164,    -1,    -1,    -1,    -1,   169
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,     5,    12,    14,    15,    19,    37,    44,    45,
      46,    48,    50,    52,    56,    69,    72,    73,    75,    76,
      80,    82,    83,    84,    91,    92,    93,    96,    99,   100,
     102,   108,   109,   110,   112,   113,   118,   119,   120,   123,
     125,   126,   127,   128,   131,   136,   137,   140,   141,   142,
     143,   144,   150,   151,   152,   154,   155,   157,   159,   160,
     162,   163,   164,   169,   171,   172,   173,   174,   183,   184,
     185,   186,   187,   188,   193,   195,   220,   258,   261,   264,
     265,   267,   268,   269,   270,   361,   385,   392,   393,   415,
     417,   419,   426,   427,   428,   430,   431,   448,   454,   455,
     456,    84,    40,    40,    40,    40,    40,    40,    40,    40,
      40,   106,   362,   363,   364,    40,    90,   191,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    30,   158,   449,
     182,   386,    40,    40,    40,   182,    40,    40,    40,    40,
     267,    40,    40,   259,   261,    40,    40,     5,    12,    19,
      37,    44,    46,    48,    56,    75,    91,    93,    96,   102,
     112,   113,   118,   119,   127,   128,   131,   137,   142,   143,
     150,   151,   154,   155,   159,   160,   162,   164,   169,   266,
      40,    40,    40,   182,    40,    40,     0,   172,   129,   391,
     182,    84,   129,   194,    40,    47,    98,   107,   267,    84,
      58,   189,   191,   271,   272,   273,   274,   277,   279,   281,
     282,   391,    84,   398,    24,    68,    70,   104,   394,    20,
       8,   277,   429,    70,   432,    70,    85,   403,   457,   457,
      29,   191,   411,   216,    26,   192,   327,    18,    15,    38,
     253,    45,   411,    47,   105,   191,   234,   341,    20,     8,
     191,   366,   367,    42,    61,    63,   199,   391,   327,   327,
       9,    68,   101,   256,   267,    97,   249,   341,   209,   201,
     117,     8,   138,   219,   189,   450,   451,   181,   387,   245,
     327,   191,   243,   411,   175,   145,   191,   237,   192,   267,
      62,    81,   191,   206,   207,   319,    22,    25,    81,   191,
     224,   225,   227,   229,   230,   231,   197,    70,   262,    47,
     260,    30,   158,   254,   156,    61,    63,   235,   242,   196,
      61,    63,   165,   198,   176,   191,   242,    36,    72,    78,
      83,    92,    95,   100,   116,   221,   222,   223,   259,   141,
      84,    26,   283,    20,   280,   273,   276,   277,    10,   278,
      21,   190,   191,   284,    84,    35,    36,    40,    53,    60,
      77,    89,    96,   116,   326,   399,   400,   420,   416,   417,
     432,    13,   395,   396,   411,   438,   439,   440,   191,    78,
     433,   404,   267,   267,    90,   413,    29,    21,   191,   217,
     218,    21,   191,    10,    27,    63,    67,   130,   344,   342,
     344,    57,   357,   375,   376,   377,   378,   379,   380,   381,
      10,    26,   368,    21,   369,   191,   191,   411,   101,    94,
     250,   191,   191,   210,   211,    70,   202,   203,   204,   206,
     190,    20,   153,   452,    46,   388,    21,   246,   191,    21,
     244,    21,   247,   177,   178,   281,    70,    31,    63,   233,
      21,   324,   226,   232,   242,   107,   107,   132,   206,   191,
     263,   267,   168,   257,     8,    86,    87,   236,   251,   284,
     179,   180,   281,    61,   105,   200,    10,    21,   262,   189,
      74,   286,   287,   288,   289,   290,   355,   357,   115,   129,
     275,   279,   282,    21,    26,   285,   267,    61,    62,    63,
      64,    65,    66,    67,    71,   105,   354,    40,    40,    40,
     327,   401,   403,   425,   403,    13,   364,   397,    70,   441,
     439,    58,   442,   121,   364,   406,   408,   412,   413,   411,
      26,   212,    21,   192,   168,   255,   255,   378,   206,   317,
      58,   267,   383,   384,   379,   129,   191,   191,   367,   129,
     212,    21,   205,    64,    65,   208,    21,   411,   453,   189,
      40,   390,   327,   191,   411,   181,   278,   238,   239,   341,
     192,    29,   320,   227,   228,    81,   231,   191,   121,   391,
     267,   191,   161,   252,   181,   278,   284,   222,   222,   267,
     125,   136,   163,   291,   287,    58,   294,   295,   298,   290,
     286,   277,   284,   190,   267,   191,   191,   411,   261,   153,
     153,   121,   366,    33,    26,    26,   107,   405,   139,   267,
     443,   366,    21,     3,     4,    70,   150,   354,   409,   411,
     414,   191,   218,    21,   114,   358,    65,   382,   105,   191,
     371,   372,   373,   129,   384,   106,    70,   213,   211,   203,
      65,    64,   204,   206,   129,   411,   190,    11,   389,   411,
     191,    21,   248,   178,   121,   239,   240,   344,    62,   321,
     323,   405,   229,    84,   267,   180,   391,    19,    91,   169,
     292,   293,    26,   298,   328,   329,   330,   331,   334,   337,
     317,   358,   285,   260,   425,   403,    46,   434,   268,   191,
     411,   148,   444,   434,   407,   409,    70,    70,   409,   411,
       6,    79,    29,   192,   191,    26,   374,   115,    21,   370,
     215,   267,   121,   129,   192,   146,   241,   322,    84,    40,
      40,    40,   124,   129,   115,    23,    28,    30,    40,    46,
      49,    54,    55,    59,   133,   158,   166,   167,   299,   300,
     301,   314,   315,   325,   326,   353,     9,    16,    32,    39,
      41,   103,   134,   135,   147,   304,   305,   306,   316,   333,
      40,    51,    55,    73,   111,   149,   332,   348,   349,    13,
      18,    38,    49,    64,    65,    66,    70,    99,   112,   122,
     159,   166,   335,   336,   338,   339,   341,   106,   359,   432,
      17,   153,   421,   166,   418,    26,   411,   435,    34,   121,
     115,   411,   445,   129,     7,   437,   121,   409,   409,   121,
     409,   409,    61,    63,    65,    67,   105,   410,    21,    21,
     360,   191,   267,   373,   366,    21,   214,    21,    26,   107,
     191,   343,   345,   346,   347,   319,    18,   191,   242,   293,
     298,   354,   327,    26,   107,   302,   303,   405,   267,   411,
     191,   307,   115,   129,   191,   166,   318,   106,   365,   327,
     308,   315,   308,   129,    21,   332,   354,   132,   341,   267,
     308,    88,   341,   350,   351,   352,    65,   339,   337,   333,
      70,   146,   267,   340,   344,   345,   191,    60,    77,    89,
     267,   402,   327,   423,   424,   422,   425,   259,   411,    43,
     436,    62,   441,   446,   191,   121,    21,   192,   206,   129,
     215,   121,   192,    26,   107,   324,   191,   411,    26,    29,
      51,   123,   267,   310,   311,   312,   313,    29,   296,   301,
     136,   411,   153,   309,   309,   306,   343,   309,   343,   123,
     352,   121,   106,   341,   344,   345,    70,   343,   241,    70,
     342,    61,    63,    89,   356,   434,   411,    21,   153,   262,
     436,   107,   441,   447,   442,   409,    21,    29,   297,   106,
     163,   308,   121,   121,   345,   340,    70,   343,   341,   344,
     340,   360,   424,   425,   267,   411,   442,   121,   311,    29,
      58,   191,   309,   343,   340,   121,   341,   345,   340,   121,
     129,   441,   299,   340,   121,   442,   115,   340
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:
#line 492 "gram.y"
    {
		/* for blank lines -- nothing to do */
	;}
    break;

  case 13:
#line 498 "gram.y"
    {
		/* to keep going after stumbling on an input error */
		Getting_tup_dur = NO;
		Good_till_canceled = NO;
		Defining_multiple = NO;
		Curr_grpsyl_p = (struct GRPSYL *) 0;
		Last_grpsyl_p = (struct GRPSYL *) 0;
		Prev_grpsyl_p = (struct GRPSYL *) 0;
	;}
    break;

  case 14:
#line 509 "gram.y"
    {
		/* fill in context field of the SSV struct */
		Currstruct_p->u.ssv_p->context = (short) Context;
	;}
    break;

  case 15:
#line 516 "gram.y"
    {
		Curr_family = Score.fontfamily;
	;}
    break;

  case 16:
#line 522 "gram.y"
    {;}
    break;

  case 17:
#line 526 "gram.y"
    {;}
    break;

  case 18:
#line 531 "gram.y"
    {;}
    break;

  case 19:
#line 535 "gram.y"
    {
		/* have lots of separate structs in music context, so
		 * mark that we have no current struct */
		Currstruct_p = (struct MAINLL *) 0;

		/* make sure at least 1 staff is visible. Not good to
		 * check when user sets visible, because it would be
		 * nice to first set everything invisible and later
		 * turn one on. So if we wait till now to check,
		 * user doesn't have to switch back and forth from
		 * score to staff to get 1 voice visible. */
		check_at_least1visible();
	;}
    break;

  case 20:
#line 550 "gram.y"
    {
		Context = C_SCORE;
	;}
    break;

  case 21:
#line 555 "gram.y"
    { begin_range(PL_UNKNOWN); ;}
    break;

  case 22:
#line 556 "gram.y"
    {
		/* Make sure all the staffs are in range */
		chk_ssv_ranges(C_STAFF);

		/* Set current SSV's staff to the first one on the list.
		 * If there is more than one, we will clone the SSV later.
		 * Note that it is possible that the staff number the user
		 * specified is actually illegal, but we will use it anyway,
		 * because it keeps the code simpler to pretend all is well,
		 * and ssv.c code will ignore such illegal SSVs anyway.
		 */
		if (Svrangelist_p != 0 && Svrangelist_p->stafflist_p != 0) {
			Currstruct_p->u.ssv_p->staffno
					= Svrangelist_p->stafflist_p->begin;
		}
		Context = C_STAFF;
	;}
    break;

  case 23:
#line 575 "gram.y"
    { begin_range(PL_UNKNOWN); ;}
    break;

  case 24:
#line 576 "gram.y"
    {
		/* Make sure all the staffs and voices are in range */
		chk_ssv_ranges(C_VOICE);

		/* Set current SSV's staff/voice to the first one on the list.
		 * If there are more than, we will clone the SSV later */
		if (Svrangelist_p != 0 && Svrangelist_p->stafflist_p != 0) {
			Currstruct_p->u.ssv_p->staffno
					= Svrangelist_p->stafflist_p->begin;
		}
		if (Svrangelist_p != 0 && Svrangelist_p->vnolist_p != 0) {
			Currstruct_p->u.ssv_p->voiceno
					= Svrangelist_p->vnolist_p->begin;
		}
		Context = C_VOICE;
	;}
    break;

  case 27:
#line 600 "gram.y"
    {
		add_to_sv_list();
	;}
    break;

  case 30:
#line 610 "gram.y"
    {
		add_to_sv_list();
	;}
    break;

  case 31:
#line 615 "gram.y"
    {
		/* allocate an SSV struct */
		Currstruct_p = newMAINLLstruct(S_SSV, yylineno);
	;}
    break;

  case 32:
#line 621 "gram.y"
    {
		/* entering new context, if we have a current struct,
		 * we were in a different context, so add its info to the list */
		end_prev_context();
	;}
    break;

  case 33:
#line 628 "gram.y"
    {
		struct FEED *feed_p;		/* where to attach blocks */
		int calloced;			/* YES if dynamically alloced */

		end_prev_context();
		Currstruct_p = (struct MAINLL *) 0;
		Context = (yyvsp[(1) - (1)].intval);
		calloced = NO;

		switch ((yyvsp[(1) - (1)].intval)) {
		case C_HEADER:
			/* We only allow one of these */
			chkdup_headfoot(Gotheader++, "header");
			Currblock_p = &Header;
			break;
		case C_HEAD2:
			chkdup_headfoot(Gothead2++, "header2");
			Currblock_p = &Header2;
			break;
		case C_FOOTER:
			chkdup_headfoot(Gotfooter++, "footer");
			Currblock_p = &Footer;
			break;
		case C_FOOT2:
			chkdup_headfoot(Gotfoot2++, "foot2");
			Currblock_p = &Footer2;
			break;
			break;
		case C_TOP:
		case C_TOP2:
		case C_BOT:
		case C_BOT2:
		case C_BLOCK:
			CALLOC(BLOCKHEAD, Currblock_p, 1);
			calloced = YES;
			break;
		default:
			pfatal("Unknown block-type context");
			/*NOTREACHED*/
			break;
		}
		set_win_coord(Currblock_p->c);
		/* Remember where to start attaching "print" commands */
		Next_print_link_p_p = &(Currblock_p->printdata_p);

		/* The dynamically allocated blocks
		 * (not the static head/foot blocks)
		 * need extra processing to populate
		 * the main list properly with FEEDs.
		 */
		if (calloced == YES) {
			if (Mainlltc_p == 0 || Mainlltc_p->str != S_FEED) {
				/* User had not specified a feed
				 * right before this block, so we need
				 * to add one for them implicitly.
				 * Create a new FEED and add it
				 * to the end of the main list.
				 */
				insertMAINLL(newMAINLLstruct(S_FEED, yylineno),
							Mainlltc_p);
			}
			feed_p = Mainlltc_p->u.feed_p;

			/* Normally, top/top2/bot/bot2 result in a pagefeed.
			 * But we have a special case for backward
			 * compatibility and for flexibility.
			 * User can get a separate
			 * "title" page if they really want to,
			 * by using an explicit newpage at the beginning.
			 * But in the normal case, they'd want to declare
			 * top/bot that will go on the first page without
			 * that causing a newpage. So if there hasn't been
			 * any music or block yet, we won't set newpage=YES
			 * for top/top2/bot/bot2, but otherwise we will.
			 */
			if (Context & (C_TOP|C_TOP2|C_BOT|C_BOT2)) {
				struct MAINLL *m_p;
				for (m_p = Mainlltc_p->prev; m_p != 0;
							m_p = m_p->prev) {
					if (m_p->str == S_BAR ||
							m_p->str == S_BLOCKHEAD) {
						/* There was music or block,
						 * so this is not
						 * at very beginning,
						 * so no special case:
						 * there will be new page.
						 */
						feed_p->pagefeed = YES;
						break;
					}
				}
			}

			/* Now check for redefined blocks and
			 * attach the BLOCKHEAD onto the FEED or the
			 * main list, as appropriate.
			 */
			switch (Context) {
			case C_TOP:
				if (feed_p->top_p != 0) {
					warning("top redefined before being used");
				}
				feed_p->top_p = Currblock_p;
				break;
			case C_TOP2:
				if (feed_p->top2_p != 0) {
					warning("top2 redefined before being used");
				}
				feed_p->top2_p = Currblock_p;
				break;
			case C_BOT:
				if (feed_p->bot_p != 0) {
					warning("bot redefined before being used");
				}
				feed_p->bot_p = Currblock_p;
				break;
			case C_BOT2:
				if (feed_p->bot2_p != 0) {
					warning("bot2 redefined before being used");
				}
				feed_p->bot2_p = Currblock_p;
				break;
			case C_BLOCK:
				insertMAINLL(newMAINLLstruct(S_BLOCKHEAD, yylineno),
						Mainlltc_p);
				Mainlltc_p->u.blockhead_p = Currblock_p;
				/* These blocks count like "music" for purposes
				 * of things that can only be set
				 * before any "music"
				 */
				Got_some_data = YES;
				break;
			case C_HEADER:
			case C_HEAD2:
			case C_FOOTER:
			case C_FOOT2:
				/* These are static, not in main list,
				 * so nothing needs to be done with them.
				 */
				break;
			default:
				pfatal("unexpected context (0x%x) for block", Context);
				/*NOTREACHED*/
				break;
			}

			/* We need a feed after a block.
			 * Use -1 as lineno to mark it as internally generated.
			 * That way if user puts their own explicit feed
			 * next in the input, we can know we can
			 * discard this internally generated one.
			 */
			if (Context & C_BLOCK) {
				insertMAINLL(newMAINLLstruct(S_FEED, -1), Mainlltc_p);
			}
		}
	;}
    break;

  case 34:
#line 787 "gram.y"
    {
		Context = C_MUSIC;
	;}
    break;

  case 35:
#line 792 "gram.y"
    {
		end_prev_context();
		Currstruct_p = (struct MAINLL *) 0;
		Context = C_GRIDS;
	;}
    break;

  case 36:
#line 800 "gram.y"
    {
		if (Context == C_GRIDS) {
			add_grid((yyvsp[(1) - (3)].stringval), (yyvsp[(2) - (3)].stringval));
		}
		else if (Context == C_HEADSHAPES) {
			/* skip past the font/size bytes */
			add_shape((yyvsp[(1) - (3)].stringval) + 2, (yyvsp[(2) - (3)].stringval) + 2);
		}
		else {
			l_warning(Curr_filename, yylineno - 1,
				"unexpected text strings (possibly intended to be in grids or headshapes context, or missing + for concatenation?)");
		}
	;}
    break;

  case 37:
#line 816 "gram.y"
    {
		end_prev_context();
		Currstruct_p = (struct MAINLL *) 0;
		Context = C_HEADSHAPES;
	;}
    break;

  case 38:
#line 825 "gram.y"
    {
		end_prev_context();
		Currstruct_p = (struct MAINLL *) 0;
		Context = C_SYMBOL;
		/* The +2 to skip font/size */
		Curr_usym_p = alloc_usym((yyvsp[(2) - (2)].stringval) + 2);
	;}
    break;

  case 40:
#line 838 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
		/* later on we check for being within current range */
	;}
    break;

  case 41:
#line 844 "gram.y"
    {
		(yyval.intval) = atoi(yytext);
	;}
    break;

  case 42:
#line 849 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (2)].intval) * (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 46:
#line 864 "gram.y"
    {
		/* Only a few things are allowed to have a negative number.
		 * Other code assumes that that restriction is enforced here,
		 * so we only honor the minus if it is legal. */
		if ((yyvsp[(3) - (4)].intval) == -1) {
			if ((yyvsp[(1) - (4)].intval) != STAFFPAD && (yyvsp[(1) - (4)].intval) != SYLPOSITION) {
				yyerror("negative value not allowed");
			}
			else {
				assign_int((yyvsp[(1) - (4)].intval), -((yyvsp[(4) - (4)].intval)), Currstruct_p);
			}
		}
		else {
			assign_int((yyvsp[(1) - (4)].intval), (yyvsp[(4) - (4)].intval), Currstruct_p);
		}
	;}
    break;

  case 47:
#line 883 "gram.y"
    {
		/* only restcombine and gridfret can be set to empty */
		if ((yyvsp[(1) - (2)].intval) == RESTCOMBINE) {
			assign_int((yyvsp[(1) - (2)].intval), NORESTCOMBINE, Currstruct_p);
		}
		else if ((yyvsp[(1) - (2)].intval) == GRIDFRET) {
			assign_int((yyvsp[(1) - (2)].intval), NOGRIDFRET, Currstruct_p);
		}
		else {
			yyerror("parameter value required");
		}
	;}
    break;

  case 48:
#line 898 "gram.y"
    {
		assign_float((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].floatval), Currstruct_p);
	;}
    break;

  case 49:
#line 904 "gram.y"
    {
		assign_2floats((yyvsp[(1) - (5)].intval), (yyvsp[(3) - (5)].floatval), (yyvsp[(5) - (5)].floatval), Currstruct_p);
	;}
    break;

  case 50:
#line 910 "gram.y"
    {
		assign_float((yyvsp[(1) - (4)].intval), (yyvsp[(3) - (4)].floatval), Currstruct_p);
	;}
    break;

  case 51:
#line 916 "gram.y"
    {
		double multiplier;
		multiplier = (Score.units == INCHES ? 1.0 : CMPERINCH);
		assign_float(PAGEWIDTH, pagesztbl[(yyvsp[(3) - (4)].intval)][(yyvsp[(4) - (4)].intval)] * multiplier, Currstruct_p);
		assign_float(PAGEHEIGHT, pagesztbl[(yyvsp[(3) - (4)].intval)][(yyvsp[(4) - (4)].intval) ^ 1] * multiplier, Currstruct_p);
	;}
    break;

  case 52:
#line 924 "gram.y"
    { begin_range(PL_UNKNOWN);  ;}
    break;

  case 53:
#line 925 "gram.y"
    { ;}
    break;

  case 54:
#line 929 "gram.y"
    {
		/* specified in stepsizes, stored in inches */
		assign_float(PAD, (yyvsp[(3) - (4)].intval) * (yyvsp[(4) - (4)].floatval) * STEPSIZE, Currstruct_p);
	;}
    break;

  case 55:
#line 936 "gram.y"
    {
		assign_vscheme ((yyvsp[(3) - (4)].intval), (yyvsp[(4) - (4)].intval), Currstruct_p);
	;}
    break;

  case 56:
#line 942 "gram.y"
    {
		set_beamlist(Currstruct_p);
		if (Currstruct_p != 0 && Currstruct_p->u.ssv_p != 0) {
			Currstruct_p->u.ssv_p->beamrests = ((yyvsp[(5) - (5)].intval) & 0x1);
			Currstruct_p->u.ssv_p->beamspaces = (((yyvsp[(5) - (5)].intval) >> 1) & 0x1);
		}
	;}
    break;

  case 57:
#line 952 "gram.y"
    {
		set_staffset((yyvsp[(1) - (4)].intval), Currstruct_p);
	;}
    break;

  case 58:
#line 958 "gram.y"
    {
		set_barstlist(Currstruct_p);
	;}
    break;

  case 59:
#line 964 "gram.y"
    {
		if (contextcheck(C_SCORE|C_STAFF, "repeatdots") == YES) {
			Currstruct_p->u.ssv_p->repeatdots = (yyvsp[(3) - (3)].intval);
			Currstruct_p->u.ssv_p->used[REPEATDOTS] = YES;
		}
	;}
    break;

  case 60:
#line 973 "gram.y"
    {
		if (Currstruct_p != 0) {
			chk_order(Currstruct_p->u.ssv_p, Order_place);
		}
	;}
    break;

  case 62:
#line 984 "gram.y"
    {
		assign_int((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 63:
#line 990 "gram.y"
    {
		/* all the work for this is done in timesig */
	;}
    break;

  case 64:
#line 996 "gram.y"
    {
	;}
    break;

  case 65:
#line 1001 "gram.y"
    {
		set_font((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 66:
#line 1007 "gram.y"
    {
		set_font((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 67:
#line 1013 "gram.y"
    {
		if (contextcheck(C_SCORE|C_STAFF,"clef parameter") == YES) {
			used_check(Currstruct_p, CLEF, "clef");
			if (Context == C_STAFF && has_tab_staff()) {
				/* We used to be able to make this just a
				 * warning, but now that is hard, because
				 * we'd want to let it assign for any
				 * non-tab, but it is hard to know at this
				 * point which SSVs will be tab and which					 * non-tab, because we may not have created
				 * them all yet. We cannot let the tab ones
				 * get assigned, because later code would
				 * get confused by clef not being TABCLEF.
				 * While we could figure this all out with
				 * enough code, it really is a user error,
				 * so not worth bending over backwards
				 * to try to keep it just a warning.
				 */
				l_yyerror(Curr_filename, yylineno,
					"can't set clef on tab staff");
			}
			Currstruct_p->u.ssv_p->clef = (yyvsp[(3) - (3)].intval);
			Currstruct_p->u.ssv_p->used[CLEF] = YES;
			asgnssv(Currstruct_p->u.ssv_p);
		}
	;}
    break;

  case 68:
#line 1041 "gram.y"
    {
		assign_int((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 70:
#line 1050 "gram.y"
    {
		assign_int((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 71:
#line 1056 "gram.y"
    {
		if (contextcheck(C_STAFF|C_VOICE, "unset") == YES) {
			if ((yyvsp[(2) - (2)].intval) < 0 || (yyvsp[(2) - (2)].intval) >= NUMFLDS) {
				pfatal("invalid parameter index %d", (yyvsp[(2) - (2)].intval));
			}
			if (Currstruct_p->u.ssv_p->used[(yyvsp[(2) - (2)].intval)] == YES) {
				warning("unsetting parameter overrides previous setting");
			}
			/* Note that if user tries to unset something that
			 * can't be set in the current context, we silently
			 * ignore that. We figure that since it's already unset,
			 * it doesn't hurt anything to unset it again,
			 * and it's easier to not bother to check.
			 */

			Currstruct_p->u.ssv_p->used[(yyvsp[(2) - (2)].intval)] = UNSET;

			/* special case: scoresep controls two fields */
			if ((yyvsp[(2) - (2)].intval) == MINSCSEP) {
				Currstruct_p->u.ssv_p->used[MAXSCSEP] = UNSET;
			}

			/* Assign, just in case there are new interactions */
			asgnssv(Currstruct_p->u.ssv_p);
		}
	;}
    break;

  case 72:
#line 1084 "gram.y"
    { Doing_timeunit = YES; ;}
    break;

  case 73:
#line 1085 "gram.y"
    {
		if ( contextcheck(C_SSV, "timeunit parameter") == YES ) {
			used_check(Currstruct_p, TIMEUNIT, "timeunit");
			Currstruct_p->u.ssv_p->timeunit = (yyvsp[(4) - (4)].ratval);
			Currstruct_p->u.ssv_p->timelist_p = Extra_time_p;
			Extra_time_p = 0;
			Doing_timeunit = NO;
			Currstruct_p->u.ssv_p->used[TIMEUNIT] = YES;
		}
	;}
    break;

  case 74:
#line 1098 "gram.y"
    {
		if ( contextcheck(C_SSV, "swingunit parameter") == YES ) {
			used_check(Currstruct_p, SWINGUNIT, "swingunit");
			Currstruct_p->u.ssv_p->swingunit = (yyvsp[(3) - (3)].ratval);
			Currstruct_p->u.ssv_p->used[SWINGUNIT] = YES;
		}
	;}
    break;

  case 75:
#line 1108 "gram.y"
    {
	;}
    break;

  case 76:
#line 1113 "gram.y"
    {
	;}
    break;

  case 77:
#line 1118 "gram.y"
    {
		if ( contextcheck(C_SCORE, "endingstyle parameter") == YES ) {
			used_check(Currstruct_p, ENDINGSTYLE, "endingstyle");
			Currstruct_p->u.ssv_p->endingstyle = (yyvsp[(3) - (3)].intval);
			Currstruct_p->u.ssv_p->used[ENDINGSTYLE] = YES;
		}
	;}
    break;

  case 78:
#line 1128 "gram.y"
    {
		if ((yyvsp[(1) - (3)].intval) == REHSTYLE) {
			if (contextcheck(C_SCORE | C_STAFF, "rehstyle parameter") == YES ) {
				used_check(Currstruct_p, REHSTYLE, "rehstyle");
				Currstruct_p->u.ssv_p->rehstyle = (yyvsp[(3) - (3)].intval);
				Currstruct_p->u.ssv_p->used[REHSTYLE] = YES;
			}
		}
		else if ((yyvsp[(1) - (3)].intval) == MEASNUMSTYLE) {
			if (contextcheck(C_SCORE, "measnumstyle parameter") == YES) {
				used_check(Currstruct_p, MEASNUMSTYLE, "measnumstyle");
				Currstruct_p->u.ssv_p->measnumstyle = (yyvsp[(3) - (3)].intval);
				Currstruct_p->u.ssv_p->used[MEASNUMSTYLE] = YES;
			}
		}
		
	;}
    break;

  case 79:
#line 1148 "gram.y"
    {
		if ( contextcheck(C_SCORE | C_STAFF, "pedstyle parameter") == YES ) {
			used_check(Currstruct_p, PEDSTYLE, "pedstyle");
			Currstruct_p->u.ssv_p->pedstyle = (yyvsp[(3) - (3)].intval);
			Currstruct_p->u.ssv_p->used[PEDSTYLE] = YES;
			/* Since Ped_stop is a predefined string that
			 * doesn't go through fix_string(), we wouldn't
			 * realize that font ZD1 was used until printing
			 * phase after we ought to have emitted the
			 * encoding vector code, which is too late,
			 * so mark it here. If the user sets the
			 * parameter to pedstar but then never actually uses
			 * a star, this will just cause a few extraenous
			 * but otherwise harmless lines of output. It is
			 * less important the ZI gets marked as used,
			 * since we don't change its encodiong vector,
			 * so don't need to emit special code, but might as
			 * well mark that here as well. */
			if ((yyvsp[(3) - (3)].intval) != P_LINE) {
				Fontinfo[font_index(FONT_ZD1)].was_used = YES;
				Fontinfo[font_index(FONT_ZI)].was_used = YES;
			}
		}
	;}
    break;

  case 80:
#line 1175 "gram.y"
    {
		char *trans_name;
		trans_name = ((yyvsp[(1) - (5)].intval) == TRANSPOSITION ?
			"transpose" : "addtranspose");
		if (contextcheck(C_SCORE|C_STAFF, trans_name) == YES) {
			if (Context == C_STAFF && has_tab_staff() == YES) {
				l_warning(Curr_filename, yylineno,
					"%s not allowed on tablature staff; ignoring",
					trans_name);
			}
			used_check(Currstruct_p, (yyvsp[(1) - (5)].intval), trans_name);
			chk_interval((yyvsp[(4) - (5)].intval), (yyvsp[(5) - (5)].intval));
			if ((yyvsp[(1) - (5)].intval) == TRANSPOSITION) {
				Currstruct_p->u.ssv_p->inttype = (yyvsp[(4) - (5)].intval);
				Currstruct_p->u.ssv_p->intnum = (yyvsp[(3) - (5)].intval) * (yyvsp[(5) - (5)].intval);
			}
			else {
				Currstruct_p->u.ssv_p->addinttype = (yyvsp[(4) - (5)].intval);
				Currstruct_p->u.ssv_p->addintnum = (yyvsp[(3) - (5)].intval) * (yyvsp[(5) - (5)].intval);
			}
			Currstruct_p->u.ssv_p->used[(yyvsp[(1) - (5)].intval)] = YES;
			asgnssv(Currstruct_p->u.ssv_p);
		}
	;}
    break;

  case 81:
#line 1202 "gram.y"
    {
		assign_unit((yyvsp[(3) - (3)].intval), Currstruct_p);
	;}
    break;

  case 82:
#line 1208 "gram.y"
    {
		assign_string((yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].stringval), Currstruct_p);
	;}
    break;

  case 83:
#line 1214 "gram.y"
    {
		if (Curr_usym_p == 0) {
			l_yyerror(Curr_filename, yylineno,
				"postscript= only valid in symbol context; maybe you meant without '=' ?");
		}
		else {
			if (Curr_usym_p->flags & US_POSTSCRIPT) {
				l_warning(Curr_filename, yylineno,
					"Multiple postscript definitions given for symbol '%s'; using last",
					Curr_usym_p->name);
				FREE(Curr_usym_p->postscript);
			}
			Curr_usym_p->postscript = (yyvsp[(3) - (3)].stringval);
			Curr_usym_p->flags |= US_POSTSCRIPT;
		}
	;}
    break;

  case 84:
#line 1233 "gram.y"
    {
		if (Curr_usym_p == 0) {
			l_yyerror(Curr_filename, yylineno,
				"bbox= only valid in symbol context");
		}
		else {
			if (Curr_usym_p->flags & US_BBOX) {
				l_warning(Curr_filename, yylineno,
					"Multiple bbox definitions given for symbol %s; using last",
					Curr_usym_p->name);
			}
			Curr_usym_p->llx = (yyvsp[(3) - (9)].intval);
			Curr_usym_p->lly = (yyvsp[(5) - (9)].intval);
			Curr_usym_p->urx = (yyvsp[(7) - (9)].intval);
			Curr_usym_p->ury = (yyvsp[(9) - (9)].intval);
			Curr_usym_p->flags |= US_BBOX;
		}
	;}
    break;

  case 85:
#line 1254 "gram.y"
    {
		if (Curr_usym_p == 0) {
			l_yyerror(Curr_filename, yylineno,
				"stemoffset= only valid in symbol context");
		}
		else {
			if (Curr_usym_p->flags & US_STEMOFFSET) {
				l_warning(Curr_filename, yylineno,
					"Multiple stemoffset definitions given for %s; last used",
					Curr_usym_p->name);
			}
			Curr_usym_p->upstem_y = (yyvsp[(3) - (5)].intval);
			Curr_usym_p->downstem_y = (yyvsp[(5) - (5)].intval);
			Curr_usym_p->flags |= US_STEMOFFSET;
		}
	;}
    break;

  case 86:
#line 1274 "gram.y"
    {
		/* whereused is not allowed on voice, just score and staff */
		if (contextcheck(C_SCORE|C_STAFF, "visible=whereused") == YES) {
			assign_int(VISIBLE, YES, Currstruct_p);
			if (Currstruct_p != 0 && Currstruct_p->u.ssv_p != 0) {
				Currstruct_p->u.ssv_p->hidesilent = YES;
			}
		}
	;}
    break;

  case 87:
#line 1286 "gram.y"
    {
		/* only valid letter is y */
		if (*yytext != 'y') {
			yyerror("visible value must be y, n, or whereused");
		}
		else if (contextcheck(C_SSV, "visible parameter")
								== YES) {
			assign_int(VISIBLE, YES, Currstruct_p);
			if (Currstruct_p != 0 && Currstruct_p->u.ssv_p != 0) {
				Currstruct_p->u.ssv_p->hidesilent = NO;
			}
		}
	;}
    break;

  case 88:
#line 1302 "gram.y"
    {
		if (contextcheck(C_SSV, "visible parameter") == YES) {
			assign_int(VISIBLE, NO, Currstruct_p);
			if (Currstruct_p != 0 && Currstruct_p->u.ssv_p != 0) {
				Currstruct_p->u.ssv_p->hidesilent = NO;
			}
		}
	;}
    break;

  case 89:
#line 1313 "gram.y"
    {
		/* only valid letter is y */
		if (*yytext != 'y') {
			yyerror("measnum value must be y, n, or every N");
			(yyval.intval) = MN_NONE;
		}
		else {
			(yyval.intval) = MN_SCORE;
		}
	;}
    break;

  case 90:
#line 1326 "gram.y"
    {
		(yyval.intval) = MN_NONE;
	;}
    break;

  case 91:
#line 1332 "gram.y"
    {
		if ((yyvsp[(2) - (2)].intval) < MINEVERYMEASNUM || (yyvsp[(2) - (2)].intval) > MAXEVERYMEASNUM) {
			/* We have to do range check here rather than let
			 * assign_int() do it, because internally we use
			 * additional values, and it would be confusing to
			 * the user to include those internal values in the
			 * valid range. */
			l_yyerror(Curr_filename, yylineno,
				"for measnum=every N, N must be between %d and %d",
				MINEVERYMEASNUM, MAXEVERYMEASNUM);
			(yyval.intval) = MN_NONE;
		}
		else {
			(yyval.intval) = (yyvsp[(2) - (2)].intval);
		}
	;}
    break;

  case 92:
#line 1351 "gram.y"
    {
		/* none specified */
		(yyval.intval) = V_1;
	;}
    break;

  case 93:
#line 1358 "gram.y"
    {
		/* only valid value here is 'f'  */
		if (*yytext == 'f') {
			(yyval.intval) = V_2FREESTEM;
		}
		else {
			yyerror("invalid voice qualifier: must be f or o");
			(yyval.intval) = V_1;
		}
	;}
    break;

  case 94:
#line 1371 "gram.y"
    {
		/* only valid value here is 'o' */
		if (*yytext == 'o') {
			(yyval.intval) = V_2OPSTEM;
		}
		else {
			yyerror("invalid voice qualifier: must be f or o");
			(yyval.intval) = (int) V_1;
		}
	;}
    break;

  case 95:
#line 1383 "gram.y"
    {
		/* NULL token for allocating a new beamlist */
		new_beamlist();
	;}
    break;

  case 98:
#line 1397 "gram.y"
    {
		add_beamlist((yyvsp[(1) - (1)].ratval));
	;}
    break;

  case 100:
#line 1406 "gram.y"
    {
		add_beamlist((yyvsp[(3) - (3)].ratval));
	;}
    break;

  case 102:
#line 1415 "gram.y"
    { begin_subbeam(); ;}
    break;

  case 103:
#line 1416 "gram.y"
    {
		end_subbeam();
	;}
    break;

  case 104:
#line 1421 "gram.y"
    {
		(yyval.ratval) = calcfulltime((yyvsp[(1) - (4)].ratval), (yyvsp[(2) - (4)].intval));

		/* If filling in a GRPSYL struct,
		 * need to fill in dots and basictime.
		 * Could also be here due to beamstyle
		 * or timeunit or location time offset,
		 * in which case the Curr_grpsyl_p will be NULL,
		 * or while getting tuplet duration. */
		if (Curr_grpsyl_p != (struct GRPSYL *) 0
						&& Getting_tup_dur == NO) {
			Curr_grpsyl_p->dots = (yyvsp[(2) - (4)].intval);
			Curr_grpsyl_p->basictime = reconstruct_basictime((yyval.ratval));
		}
		else {
			struct TIMELIST *timelist_p;	/* walk thru list */
			struct TIMELIST *next_p;/* save next to delete curr */
			RATIONAL totaltime;	/* sum of extra times */

			/* Start with first time value (which was calculated
			 * above and is now in $$), then add on the added
			 * times, if any. */
			totaltime = (yyval.ratval);
			for (timelist_p = Extra_time_p; timelist_p != 0;
						timelist_p = next_p) {
				next_p = timelist_p->next;
				totaltime = radd(totaltime, timelist_p->fulltime);
				if (Doing_timeunit == NO) {
					/* For things like swingunit
					 * or tuplet time, we just need the
					 * resulting time, not the individual
					 * time units and arithmetic. */
					FREE(timelist_p);
				}
			}
			if (Extra_time_p != 0 && LE(totaltime, Zero)) {
				yyerror("Time values must add up to more than zero");
			}
			/* Current timelist is finished; can't append any
			 * more items to it. */
			Curr_timelist_p = 0;
			if (Doing_timeunit == YES) {
				/* For timeunit, we return the initial
				 * timeunit, but also preserve
				 * Extra_time_p for putting in SSV.
				 */
				(yyval.ratval) = calcfulltime((yyvsp[(1) - (4)].ratval), (yyvsp[(2) - (4)].intval));
			}
			else {
				/* the list has been freed above */
				Extra_time_p = 0;
				(yyval.ratval) = totaltime;
			}
		}
	;}
    break;

  case 105:
#line 1479 "gram.y"
    {
		(yyval.ratval).n = (svpath(1, TIME))->time.n;
		(yyval.ratval).d = (svpath(1, TIME))->time.d;
		if (Curr_grpsyl_p != (struct GRPSYL *) 0
					&& Getting_tup_dur == NO) {
			/* use whole note symbol as default */
			Curr_grpsyl_p->basictime = 1;
			Curr_grpsyl_p->is_meas = YES;
			User_meas_time = NO;
		}
		else {
			yyerror("'m' is not valid here");
		}
	;}
    break;

  case 106:
#line 1496 "gram.y"
    {
		(yyval.ratval) = Zero;
	;}
    break;

  case 108:
#line 1506 "gram.y"
    {
		(yyval.intval) = NO;
	;}
    break;

  case 109:
#line 1512 "gram.y"
    {
		(yyval.intval) = (YES | (YES << 1));
	;}
    break;

  case 110:
#line 1518 "gram.y"
    {
		(yyval.intval) = ((YES << 1) | YES);
	;}
    break;

  case 111:
#line 1524 "gram.y"
    {
		(yyval.intval) = (YES << 1);
	;}
    break;

  case 112:
#line 1530 "gram.y"
    {
		(yyval.intval) = YES;
	;}
    break;

  case 113:
#line 1535 "gram.y"
    {
		/* null token for the purpose of allocating a new rangelist
		 * to be filled in with user data */
		new_staffset();
	;}
    break;

  case 117:
#line 1552 "gram.y"
    {
		/* save information about this range in the list */
		/* if only a single number, not a range, rangetail will be
		 * 0, so use num as both beginning and end of range */
		add_staffset( (yyvsp[(1) - (3)].intval), ((yyvsp[(2) - (3)].intval) > 0 ? (yyvsp[(2) - (3)].intval) : (yyvsp[(1) - (3)].intval)), String1, String2);
	;}
    break;

  case 118:
#line 1560 "gram.y"
    {
		/* no end of range, so return 0 as flag that there was only 1 number */
		(yyval.intval) = 0;
	;}
    break;

  case 119:
#line 1567 "gram.y"
    {
		/* make sure isn't 0, because that it illegal and would be used
		 * later as though there were no range. Other error checking
		 * on this number will be done later. */
		if ((yyvsp[(2) - (2)].intval) == 0) {
			yyerror("second number of range may not be zero");
		}
		(yyval.intval) = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 120:
#line 1578 "gram.y"
    {
		/* no labels */
		String1 = String2 = (char *) 0;
	;}
    break;

  case 121:
#line 1585 "gram.y"
    {
		/* save label */
		String1 = (yyvsp[(2) - (4)].stringval);
	;}
    break;

  case 122:
#line 1591 "gram.y"
    {
		/* no second label */
		String2 = (char *) 0;
	;}
    break;

  case 123:
#line 1598 "gram.y"
    {
		/* save label2 for later use */
		String2 = (yyvsp[(2) - (2)].stringval);
	;}
    break;

  case 125:
#line 1607 "gram.y"
    {
		/* NULL token for allocating space for a bar style list */
		new_barstlist();
	;}
    break;

  case 129:
#line 1624 "gram.y"
    {
		/* if only 1 number, not range, rangetail will be 0, so use
		 * same number for beginning and end */
		add_barst((yyvsp[(1) - (2)].intval), ((yyvsp[(2) - (2)].intval) == 0 ? (yyvsp[(1) - (2)].intval) : (yyvsp[(2) - (2)].intval)) );
	;}
    break;

  case 130:
#line 1632 "gram.y"
    {
		(yyval.intval) = RD_ALL;
	;}
    break;

  case 131:
#line 1638 "gram.y"
    {
		(yyval.intval) = RD_STANDARD;
	;}
    break;

  case 132:
#line 1643 "gram.y"
    {
		Order_place = (yyvsp[(1) - (1)].intval);
		Order_prio = 1;
		if (Currstruct_p != 0) {
			switch ((yyvsp[(1) - (1)].intval)) {
			case PL_ABOVE:
				Currstruct_p->u.ssv_p->used[ABOVEORDER] = YES;
				break;
			case PL_BELOW:
				Currstruct_p->u.ssv_p->used[BELOWORDER] = YES;
				break;
			case PL_BETWEEN:
				Currstruct_p->u.ssv_p->used[BETWEENORDER] = YES;
				break;
			}
		}
	;}
    break;

  case 133:
#line 1663 "gram.y"
    {
		if (Currstruct_p != 0) {
			Currstruct_p->u.ssv_p->markorder[Order_place][(yyvsp[(1) - (1)].intval)] = Order_prio;
		}
	;}
    break;

  case 134:
#line 1671 "gram.y"
    {
		if (Currstruct_p != 0) {
			Currstruct_p->u.ssv_p->markorder[Order_place][(yyvsp[(3) - (3)].intval)] = ++Order_prio;
		}
	;}
    break;

  case 135:
#line 1679 "gram.y"
    {
		if (Currstruct_p != 0) {
			Currstruct_p->u.ssv_p->markorder[Order_place][(yyvsp[(3) - (3)].intval)] = Order_prio;
		}
	;}
    break;

  case 136:
#line 1686 "gram.y"
    {
		if (Currstruct_p != 0) {
			if (Currstruct_p->u.ssv_p->markorder[Order_place][(yyvsp[(1) - (1)].intval)] != 0) {
				l_yyerror(Curr_filename, yylineno,
					"order item %s specified more than once", (yyvsp[(1) - (1)].intval));
			}
		}
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 137:
#line 1698 "gram.y"
    {
		(yyval.intval) = MK_MUSSYM;
	;}
    break;

  case 138:
#line 1704 "gram.y"
    {
		(yyval.intval) = MK_OCTAVE;
	;}
    break;

  case 139:
#line 1710 "gram.y"
    {
		(yyval.intval) = MK_OTHERTEXT;
	;}
    break;

  case 140:
#line 1716 "gram.y"
    {
		switch ((yyvsp[(1) - (1)].intval)) {
		case TM_CHORD:
			(yyval.intval) = MK_CHORD;
			break;
		case TM_DYN:
			(yyval.intval) = MK_DYN;
			break;
		default:
			yyerror("invalid text modifier in order list");
			/* set to something valid, since $$ will be used
			 * as an array subscript. */
			(yyval.intval) = MK_CHORD;
			break;
		}
	;}
    break;

  case 141:
#line 1735 "gram.y"
    {
		(yyval.intval) = MK_LYRICS;
	;}
    break;

  case 142:
#line 1741 "gram.y"
    {
		(yyval.intval) = MK_ENDING;
	;}
    break;

  case 143:
#line 1747 "gram.y"
    {
		(yyval.intval) = MK_REHEARSAL;
	;}
    break;

  case 144:
#line 1753 "gram.y"
    {
		(yyval.intval) = MK_PEDAL;
	;}
    break;

  case 145:
#line 1759 "gram.y"
    {
		tsig_item(TSR_END);
		if (Currstruct_p != 0 && Currstruct_p->u.ssv_p != 0) {
			MALLOCA(char, Currstruct_p->u.ssv_p->timerep, Tsig_offset);
			strcpy(Currstruct_p->u.ssv_p->timerep, Timerep);
			assign_timesig(Currstruct_p, (yyvsp[(2) - (2)].intval), &Next_alt_timesig);
			Tsig_visibility = (yyvsp[(2) - (2)].intval);
			/* If there are alternating time signatures,
			 * need to save pointer to this list */
			if (Next_alt_timesig != 0) {
				Alt_timesig_list = Timerep;
			}
			else {
				Alt_timesig_list = 0;
			}
		}
		/* Reset for next time signature usage, if any */
		Tsig_offset = 0;
	;}
    break;

  case 147:
#line 1783 "gram.y"
    { tsig_item(TSR_ALTERNATING); ;}
    break;

  case 148:
#line 1784 "gram.y"
    {
		/* this is for alternating time signature */
	;}
    break;

  case 149:
#line 1790 "gram.y"
    {
	;}
    break;

  case 150:
#line 1794 "gram.y"
    { tsig_item(TSR_ADD); ;}
    break;

  case 151:
#line 1795 "gram.y"
    {
		/* This would be for things like 2/4 + 3/8 */
	;}
    break;

  case 152:
#line 1801 "gram.y"
    {
		tsig_item(TSR_CUT);
	;}
    break;

  case 153:
#line 1807 "gram.y"
    {
		tsig_item(TSR_COMMON);
	;}
    break;

  case 154:
#line 1813 "gram.y"
    {
		tsig_item(TSR_SLASH);
		if ((yyvsp[(3) - (3)].intval) < MINDENOMINATOR) {
			l_yyerror(Curr_filename, yylineno,
				"time signature denominator cannot be less than %d",
				MINDENOMINATOR);
			(yyvsp[(3) - (3)].intval) = MINDENOMINATOR;
		}
		else if ((yyvsp[(3) - (3)].intval) > MAXDENOMINATOR) {
			l_yyerror(Curr_filename, yylineno,
				"time signature denominator cannot be greater than %d",
				MAXDENOMINATOR);
			(yyvsp[(3) - (3)].intval) = MAXDENOMINATOR;
		}
		else if (power_of2check((yyvsp[(3) - (3)].intval), "time signature denominator") == NO) {
			(yyvsp[(3) - (3)].intval) = 1 << drmo((yyvsp[(3) - (3)].intval));
		}

		tsig_item((yyvsp[(3) - (3)].intval));
	;}
    break;

  case 155:
#line 1836 "gram.y"
    {
		/* this is something like 3+1/4 where the 1/4 get interpreted
		 * by lexer as quadwhole, but it's really 1 for numerator
		 * and 4 for denominator. 
		 */
		tsig_item(1);
		tsig_item(TSR_SLASH);
		tsig_item((yyvsp[(3) - (3)].intval));
	;}
    break;

  case 156:
#line 1848 "gram.y"
    {
		tsig_item(1);
		tsig_item(TSR_SLASH);
		tsig_item((yyvsp[(1) - (1)].intval));
	;}
    break;

  case 159:
#line 1862 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) < MINNUMERATOR) {
			l_yyerror(Curr_filename, yylineno,
				"time signature numerator cannot be less than %d",
				MINNUMERATOR);
			(yyvsp[(1) - (1)].intval) = MINNUMERATOR;
		}
		else if ((yyvsp[(1) - (1)].intval) > MAXNUMERATOR) {
			l_yyerror(Curr_filename, yylineno,
				"time signature numerator cannot be greater than %d",
				MAXNUMERATOR);
			(yyvsp[(1) - (1)].intval) = MAXNUMERATOR;
		}
		tsig_item((yyvsp[(1) - (1)].intval));
	;}
    break;

  case 160:
#line 1880 "gram.y"
    {
		(yyval.intval) = PTS_ONCE;
	;}
    break;

  case 161:
#line 1886 "gram.y"
    {
		(yyval.intval) = ((yyvsp[(1) - (1)].intval) == YES ? PTS_ALWAYS : PTS_NEVER);
	;}
    break;

  case 162:
#line 1891 "gram.y"
    {
		(yyval.intval) = NO;
	;}
    break;

  case 163:
#line 1897 "gram.y"
    {
		/* 'n' is used in various places to mean do NOT
		 * print something that would normally be printed,
		 * so YES means we do want to inhibit the normal printing. */
		(yyval.intval) = YES;
	;}
    break;

  case 164:
#line 1905 "gram.y"
    {
		if ( ((yyvsp[(2) - (3)].intval) != '#') && ((yyvsp[(2) - (3)].intval) != '&') ) {
			yyerror("key signature must include # or &");
		}
		else {
			assign_key((yyvsp[(1) - (3)].intval), (yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval), Currstruct_p);
		}
	;}
    break;

  case 165:
#line 1916 "gram.y"
    {
		int sharps;

		/* Get number of sharps for the pitch letter */
		sharps = strchr(Circle, (yyvsp[(1) - (3)].intval)) - Circle - 1;

		/* adjust for sharp/flat */
		if ((yyvsp[(2) - (3)].intval) == '#') {
			sharps += 7;
		}
		else if ((yyvsp[(2) - (3)].intval) == '&') {
			sharps -= 7;
		}
		else if ((yyvsp[(2) - (3)].intval) != 0) {
			yyerror("key letter can only be followed by # or &");
			/* set to some ridiculous value, so will fail below */
			sharps = 999;
		}

		/* Adjust if needed for minor */
		if ((yyvsp[(3) - (3)].intval) == YES) {
			sharps -= 3;
		}

		/* disallow illegal keys, like f& */
		if (abs(sharps) > 7) {
			/* print error unless already printed one above */
			if (sharps < 100) {
				yyerror("invalid key--too many sharps or flats");
			}
		}
		else {
			assign_key(abs(sharps), (sharps >= 0 ? '#' : '&'),
							(yyvsp[(3) - (3)].intval), Currstruct_p);
		}
	;}
    break;

  case 166:
#line 1955 "gram.y"
    {
		if ((yyvsp[(1) - (2)].intval) == NO) {
			if ((yyvsp[(2) - (2)].intval) != -1) {
				l_warning(Curr_filename, yylineno,
					"can't use useaccs qualifier with n; ignoring the qualifier");
			}
			(yyval.intval) = UA_N;
		}
		else {
			if ((yyvsp[(2) - (2)].intval) == -1) {
				(yyvsp[(2) - (2)].intval) = UA_Y_NONE;
			}
			(yyval.intval) = (yyvsp[(2) - (2)].intval);
		}
	;}
    break;

  case 167:
#line 1973 "gram.y"
    {
		/* Empty means UA_Y_NONE when used with 'y', but we need
		 * to distinguish temporarily, in case user erroneously
		 * tries to use std with 'n' */
		(yyval.intval) = -1;
	;}
    break;

  case 168:
#line 1982 "gram.y"
    {
		(yyval.intval) = UA_Y_NONE;
	;}
    break;

  case 169:
#line 1988 "gram.y"
    {
		(yyval.intval) = UA_Y_ALL;
	;}
    break;

  case 170:
#line 1994 "gram.y"
    {
		(yyval.intval) = UA_Y_NONNAT;
	;}
    break;

  case 171:
#line 2001 "gram.y"
    {
		asgn_stafflines((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].intval) == YES ? SS_NOTHING : SS_NORMAL, Currstruct_p);
	;}
    break;

  case 172:
#line 2007 "gram.y"
    {
		asgn_stafflines((yyvsp[(1) - (2)].intval), SS_DRUM, Currstruct_p);
	;}
    break;

  case 173:
#line 2013 "gram.y"
    {
		/* use default tablature */
		if (Currstruct_p != 0) {
			Currstruct_p->u.ssv_p->strinfo = Guitar;
			asgn_stafflines(DEFTABLINES, NO, Currstruct_p);
		}
	;}
    break;

  case 174:
#line 2023 "gram.y"
    {
		/* user-specified tablature */
		asgn_stafflines((yyvsp[(3) - (4)].intval), NO, Currstruct_p);
	;}
    break;

  case 175:
#line 2030 "gram.y"
    {
		(yyval.intval) = 1;
	;}
    break;

  case 176:
#line 2036 "gram.y"
    {
		/* count up the number of strings */
		(yyval.intval) = (yyvsp[(1) - (2)].intval) + 1;
	;}
    break;

  case 177:
#line 2042 "gram.y"
    {
		/* save info about this tablature string */
		if (Currstruct_p != 0) {
			add_tab_string_info((yyvsp[(1) - (4)].intval), (yyvsp[(2) - (4)].intval), (yyvsp[(3) - (4)].intval), (yyvsp[(4) - (4)].intval), Currstruct_p->u.ssv_p);
		}
	;}
    break;

  case 178:
#line 2050 "gram.y"
    {
		(yyval.intval) = 0;
	;}
    break;

  case 179:
#line 2056 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) != '&' && (yyvsp[(1) - (1)].intval) != '#') {
			yyerror("accidental on string can only be & or #");
		}
	;}
    break;

  case 180:
#line 2063 "gram.y"
    {
		/* no ticks */
		(yyval.intval) = 0;
	;}
    break;

  case 181:
#line 2070 "gram.y"
    {
		/* limit number of ticks. Has to match the number of bits
		 * used by TMP_NTICKS in grpsyl.c */
		if ((yyvsp[(1) - (1)].intval) > MAXTICKS) {
			l_yyerror(Curr_filename, yylineno,
				"too many ' marks (%d max)", MAXTICKS);
			(yyvsp[(1) - (1)].intval) = MAXTICKS;
		}
	;}
    break;

  case 182:
#line 2081 "gram.y"
    {
		/* only valid letter is y */
		if (*yytext != 'y') {
			yyerror("flag value must be y or n");
		}
		(yyval.intval) = YES;
	;}
    break;

  case 183:
#line 2091 "gram.y"
    {
		(yyval.intval) = NO;
	;}
    break;

  case 184:
#line 2096 "gram.y"
    {
		if (Currstruct_p == 0) {
			l_warning(Curr_filename, yylineno,
				"wrong context for setting scoresep; ignoring");
		}
		else {
			/* Assign the value of minimum vertical space
			 * between scores. */
			assign_int(MINSCSEP, (yyvsp[(1) - (1)].intval), Currstruct_p);
		}
	;}
    break;

  case 185:
#line 2109 "gram.y"
    {
		if (Currstruct_p != 0) {
			/* if user set minimum greater than default maximum,
			 * adjust maximum to equal the minimum
			 * they specified. */
			if (Currstruct_p->u.ssv_p->minscsep
					> Currstruct_p->u.ssv_p->maxscsep) {
				Currstruct_p->u.ssv_p->maxscsep
					= Currstruct_p->u.ssv_p->minscsep;
			}
			else {
				/* fill in default */
				assign_int(MAXSCSEP, DEFMAXSCSEP, Currstruct_p);
			}
		}
	;}
    break;

  case 186:
#line 2128 "gram.y"
    {
		if (Currstruct_p != 0) {
			if (Currstruct_p->u.ssv_p->minscsep > (yyvsp[(2) - (2)].intval)) {
				yyerror("scoresep maximum smaller than minimum");
			}
			assign_int(MAXSCSEP, (yyvsp[(2) - (2)].intval), Currstruct_p);
		}
	;}
    break;

  case 187:
#line 2138 "gram.y"
    {
		if (Currstruct_p == 0) {
			l_warning(Curr_filename, yylineno,
				"wrong context for setting scorepad; ignoring");
		}
		else {
			/* Assign the value of minimum vertical space
			 * between scores. */
			assign_int(MINSCPAD, (yyvsp[(1) - (2)].intval) * (yyvsp[(2) - (2)].intval), Currstruct_p);
		}
	;}
    break;

  case 188:
#line 2152 "gram.y"
    {
		if (Currstruct_p != 0) {
			/* If user set minimum greater than default maximum,
			 * adjust maximum to equal the minimum
			 * they specified. */
			if (Currstruct_p->u.ssv_p->minscpad
					> Currstruct_p->u.ssv_p->maxscpad) {
				Currstruct_p->u.ssv_p->maxscpad
					= Currstruct_p->u.ssv_p->minscpad;
			}
			else {
				/* fill in default */
				assign_int(MAXSCPAD, DEFMAXSCPAD, Currstruct_p);
			}
		}
	;}
    break;

  case 189:
#line 2171 "gram.y"
    {
		if (Currstruct_p != 0) {
			if (Currstruct_p->u.ssv_p->minscpad > (yyvsp[(2) - (3)].intval) * (yyvsp[(3) - (3)].intval)) {
				yyerror("scorepad maximum smaller than minimum");
			}
			assign_int(MAXSCPAD, (yyvsp[(2) - (3)].intval) * (yyvsp[(3) - (3)].intval), Currstruct_p);
		}
	;}
    break;

  case 190:
#line 2182 "gram.y"
    {
	;}
    break;

  case 191:
#line 2187 "gram.y"
    {
		assign_float(MAXPROSHORT, (yyvsp[(2) - (3)].floatval), Currstruct_p);
	;}
    break;

  case 192:
#line 2192 "gram.y"
    {
	;}
    break;

  case 193:
#line 2197 "gram.y"
    {
		if ((yyvsp[(2) - (4)].intval) > (yyvsp[(4) - (4)].intval)) {
			l_warning(Curr_filename, yylineno,
				"distance to begin shortening protruding stems cannot be greater than ending distance; making them equal");
			(yyvsp[(4) - (4)].intval) = (yyvsp[(2) - (4)].intval);
		}
		assign_int(BEGPROSHORT, (yyvsp[(2) - (4)].intval), Currstruct_p);
		assign_int(ENDPROSHORT, (yyvsp[(4) - (4)].intval), Currstruct_p);
	;}
    break;

  case 195:
#line 2212 "gram.y"
    {
		if ((yyvsp[(1) - (2)].intval) == (int) 'a' && (yyvsp[(2) - (2)].intval) >= 4 && (yyvsp[(2) - (2)].intval) <= 6) {
			switch ((yyvsp[(2) - (2)].intval)) {
			case 4:
				(yyval.intval) = PS_A4;
				break;
			case 5:
				(yyval.intval) = PS_A5;
				break;
			case 6:
				(yyval.intval) = PS_A6;
				break;
			default:
				pfatal("impossible pagesize");
				break;
			}
		}
		else {
			yyerror("unsupported pagesize");
		}
	;}
    break;

  case 196:
#line 2237 "gram.y"
    {
		(yyval.intval) = 0;
	;}
    break;

  case 197:
#line 2243 "gram.y"
    {
		(yyval.intval) = ((yyvsp[(1) - (1)].intval) == O_PORTRAIT ? 0 : 1);
	;}
    break;

  case 198:
#line 2250 "gram.y"
    {
		assign_vcombine(VC_NOOVERLAP, Currstruct_p);
	;}
    break;

  case 199:
#line 2256 "gram.y"
    {
		assign_vcombine((yyvsp[(2) - (2)].intval), Currstruct_p);
		Defining_multiple = NO;
	;}
    break;

  case 200:
#line 2264 "gram.y"
    {
		(yyval.intval) = VC_NOOVERLAP;
	;}
    break;

  case 201:
#line 2270 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 202:
#line 2277 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 203:
#line 2283 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) != C_TOP) {
			l_yyerror(Curr_filename, yylineno,
					"%s not valid here", yytext);
		}
		(yyval.intval) = ENDING_TOP;
	;}
    break;

  case 204:
#line 2292 "gram.y"
    {
		(yyval.intval) = 1;
	;}
    break;

  case 205:
#line 2298 "gram.y"
    {
		(yyval.intval) = -1;
	;}
    break;

  case 206:
#line 2303 "gram.y"
    {
		(yyval.intval) = NO;
	;}
    break;

  case 207:
#line 2309 "gram.y"
    {
		switch ((yyvsp[(1) - (1)].intval)) {
		case MINOR:
			(yyval.intval) = YES;
			break;
		case MAJOR:
			(yyval.intval) = NO;
			break;
		default:
			(yyval.intval) = NO;
			yyerror("must be major or minor");
			break;
		}
	;}
    break;

  case 208:
#line 2325 "gram.y"
    {
		(yyval.intval) = P_LINE;
	;}
    break;

  case 209:
#line 2331 "gram.y"
    {
		(yyval.intval) = P_ALTPEDSTAR;
	;}
    break;

  case 210:
#line 2337 "gram.y"
    {
		(yyval.intval) = P_PEDSTAR;
	;}
    break;

  case 212:
#line 2345 "gram.y"
    {
	;}
    break;

  case 213:
#line 2349 "gram.y"
    {
		if ((yyvsp[(2) - (2)].intval) == FONT_UNKNOWN) {
			(yyvsp[(2) - (2)].intval) = Curr_font;
		}
		if ((yyvsp[(1) - (2)].intval) == FAMILY_DFLT) {
			/* user didn't specify a family. Use the current
			 * family, unless we don't have one yet, in which
			 * case look it up */
			if (Curr_family == FAMILY_DFLT) {
				Curr_family = Score.fontfamily;
			}
			Titlefont =  Curr_family + (yyvsp[(2) - (2)].intval);
		}
		else {
			Titlefont = (yyvsp[(1) - (2)].intval) + (yyvsp[(2) - (2)].intval);
		}
	;}
    break;

  case 214:
#line 2368 "gram.y"
    {
		(yyval.intval) = FONT_UNKNOWN;
	;}
    break;

  case 215:
#line 2374 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 216:
#line 2379 "gram.y"
    {
		(yyval.intval) = FAMILY_DFLT;
	;}
    break;

  case 217:
#line 2384 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 218:
#line 2389 "gram.y"
    {
		Titlesize = Curr_size;
	;}
    break;

  case 219:
#line 2395 "gram.y"
    {
		Titlesize = (yyvsp[(2) - (3)].intval);
	;}
    break;

  case 220:
#line 2401 "gram.y"
    {
		Extra = extra_needed(Titlefont, Titlesize, (yyvsp[(1) - (1)].stringval));
		proc_printcmd(J_CENTER, (struct INPCOORD *) 0, (yyvsp[(1) - (1)].stringval),
				Titlefont, Titlesize, YES, NO, Extra);
	;}
    break;

  case 221:
#line 2409 "gram.y"
    {
		double tmp_extra;

		/* if one is taller than the default for the font/size,
		 * figure out how much more to add on */
		/* can't use MAX passing extra_needed() as arguments because
		 * it would get executed multiple times, which is a problem */
		Extra = extra_needed(Titlefont, Titlesize, (yyvsp[(1) - (2)].stringval));
		tmp_extra = extra_needed(Titlefont, Titlesize, (yyvsp[(2) - (2)].stringval));
		Extra = MAX(Extra, tmp_extra);


		proc_printcmd(J_LEFT, (struct INPCOORD *) 0, (yyvsp[(1) - (2)].stringval),
				Titlefont, Titlesize, YES, NO, Extra);
		proc_printcmd(J_RIGHT, (struct INPCOORD *) 0, (yyvsp[(2) - (2)].stringval),
				Titlefont, Titlesize, NO, NO, (double) 0.0);
	;}
    break;

  case 222:
#line 2429 "gram.y"
    {
		double tmp_extra;

		Extra = extra_needed(Titlefont, Titlesize, (yyvsp[(1) - (3)].stringval));
		tmp_extra = extra_needed(Titlefont, Titlesize, (yyvsp[(2) - (3)].stringval));
		Extra = MAX(Extra, tmp_extra);
		tmp_extra = extra_needed(Titlefont, Titlesize, (yyvsp[(3) - (3)].stringval));
		Extra = MAX(Extra, tmp_extra);

		proc_printcmd(J_LEFT, (struct INPCOORD *) 0, (yyvsp[(1) - (3)].stringval),
				Titlefont, Titlesize, YES, NO, Extra);
		proc_printcmd(J_CENTER, (struct INPCOORD *) 0, (yyvsp[(2) - (3)].stringval),
				Titlefont, Titlesize, NO, NO, (double) 0.0);
		proc_printcmd(J_RIGHT, (struct INPCOORD *) 0, (yyvsp[(3) - (3)].stringval),
				Titlefont, Titlesize, NO, NO, (double) 0.0);
	;}
    break;

  case 223:
#line 2447 "gram.y"
    {
		char *p;		/* pointer through the string */
		int backslash_count;	/* how many backslashes in a row */
		int font, size;		/* at end of \n-delimited segment */
		char *string_start;	/* where current segment begins */

		/* Convert unescaped input newlines to spaces.
		 * The +2 in the 'for' initialization is to skip font/size.
		 */
		backslash_count = 0;
		string_start = (yyvsp[(5) - (7)].stringval);
		/* If we are running on a file using \r or \r\n for
		 * line separator, normalize to \n instead */
		for (p = string_start + 2; *p != 0; p++) {
			if (*p == '\r') {
				if ( *(p+1) != '\n') {
					/* \r by itself. Use \n instead */
					*p = '\n';
				}
				else {
					/* delete the \r */
					char *src, *dest;
					for (src = p + 1, dest = p;  ; src++, dest++) { 
						*dest = *src;
						if (*src == '\0') {
							break;
						}
					}
				}
			}
		}

		font = Titlefont;
		size = Titlesize;
		for (p = string_start + 2; *p != 0; p++) {
			/* Real newlines not preceeded by an odd number
			 * of backslashes are converted to spaces. */
			if (*p == '\n' && (backslash_count & 0x1) == 0) {
				*p = ' ';
			}

			/* Count up number of consecutive backslashes.
			 * Also, if user explicitly uses \n, split into
			 * a new paragraph
			 */
			if (*p == '\\') {
				backslash_count++;
				if (((backslash_count & 0x1) == 1)
						&& ( *(p+1) == 'n') ) {
					/* Need to split.
					 * Terminate the current string
					 * where we are in it, and process it,
					 * then arrange to continue processing
					 * on the rest of the string.
					 */
					*p = '\0';
					(void) fix_string(string_start,
						font, size,
						Curr_filename, yylineno);
					proc_printcmd((yyvsp[(1) - (7)].intval), (struct INPCOORD*) 0,
						string_start, font, size,
						YES, NO, 0.0);

					/* The user could change font/size
					 * in mid-string with \f() and/or \s().
					 * so we have to determine what they
					 * are at the end of the current segment
					 * and use that for making the copy
					 * of the remainder of the string.
					 * The original copy of the remainder
					 * of the string gets "memory leaked,"
					 * but this is a rare case, so not
					 * worth worrying about.
					 */
					end_fontsize(string_start, &font, &size);
					string_start = copy_string(p+2, font, size);
					p = string_start + 2;
				}
			}
			else {
				backslash_count = 0;
			}
		}
		(void) fix_string(string_start, font, size,
					Curr_filename, yylineno);
		proc_printcmd((yyvsp[(1) - (7)].intval), (struct INPCOORD*) 0, string_start,
					font, size, YES, NO, 0.0);
	;}
    break;

  case 224:
#line 2538 "gram.y"
    {
		/* Use same paragraph time as last time (or default if
		 * this is the first paragraph ever in this song.) */
		(yyval.intval) = Curr_paratype;
	;}
    break;

  case 225:
#line 2546 "gram.y"
    {
		Curr_paratype = (yyvsp[(1) - (1)].intval);
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 258:
#line 2649 "gram.y"
    {
		/* strip the quotes from the string and make a copy for later use */
		if (Curr_family == FAMILY_DFLT) {
			Curr_family = Score.fontfamily;
		}
		(yyval.stringval) = copy_string(stripquotes(yytext), Curr_family + Curr_font,
								Curr_size);
	;}
    break;

  case 259:
#line 2660 "gram.y"
    {
		char *old_string;

		/* append new string part to existing part */
		old_string = (yyvsp[(1) - (3)].stringval);
		/* new string part has quotes, so subtract 2 from needed length,
		 * but need space for null, so overall need 1 less. */
		MALLOCA(char, (yyval.stringval), strlen(old_string) + strlen(yytext) - 1);
		sprintf((yyval.stringval), "%s%s", old_string, stripquotes(yytext));
		FREE(old_string);
	;}
    break;

  case 260:
#line 2673 "gram.y"
    {
		(void) contextcheck(C_MUSIC, "music information");
		tssv_line();
		/* reset flags for next voice */
		Defining_multiple = NO;
		Curr_grpsyl_p = (struct GRPSYL *) 0;
		Good_till_canceled = NO;
		free_extra_time();
		Prev_grpsyl_p = 0;
	;}
    break;

  case 261:
#line 2685 "gram.y"
    {
		/* Here's the deal: the staff/voice specification
		 * could be lists of staff ranges and/or voices.
		 * We need a separate copy of the groupinfo
		 * for each staff/voice. So as we parse the sv_spec,
		 * we remember which staffs and voices are specified,
		 * and keep a pointer to the first STAFF in the measure.
		 * Then after collecting the groupinfo,
		 * we make copies of the group info for each staff/voice given.
		 * It has to be copies rather than just a pointer to the
		 * same stuff, because the coordinates will be different
		 * for each staff/voice. */

		/* attach the groupinfo to each of the STAFF structs */
		link_groups();
	;}
    break;

  case 262:
#line 2704 "gram.y"
    {
		add_multirest((yyvsp[(2) - (3)].intval));
		/* If there are alternating time signatures, figure out
		 * which one should be in effect at the end of the multirest */
		if (Alt_timesig_list != 0) {
			int m;

			/* The Next_alt_timesig is already pointing to
			 * the value for after the first measure in the
			 * multirest, so have to subtract 1 here */
			for (m = 0; m < (yyvsp[(2) - (3)].intval) - 1; m++) {
				if (Next_alt_timesig == 0) {
					/* Shouldn't really ever get here,
					 * since other code should do the
					 * wrap-around, but just in case... */
					Next_alt_timesig = Alt_timesig_list;
					continue;
				}
				do {
					Next_alt_timesig++;
					if (*Next_alt_timesig == TSR_END) {
						Next_alt_timesig = Alt_timesig_list;
						break;
					}
				} while (*Next_alt_timesig != TSR_ALTERNATING);
			}
			if (*Next_alt_timesig == TSR_ALTERNATING) {
				Next_alt_timesig++;
			}
		}
		Currstruct_p = (struct MAINLL *) 0;
	;}
    break;

  case 263:
#line 2739 "gram.y"
    {
		free_staffrange();
	;}
    break;

  case 264:
#line 2744 "gram.y"
    {
		begin_range(PL_UNKNOWN);
	;}
    break;

  case 265:
#line 2749 "gram.y"
    {
		Chord_at_a_time = NO;
	;}
    break;

  case 266:
#line 2755 "gram.y"
    {
		Chord_at_a_time = YES;
	;}
    break;

  case 270:
#line 2770 "gram.y"
    {
		begin_map();
	;}
    break;

  case 271:
#line 2775 "gram.y"
    {
		end_map();
	;}
    break;

  case 272:
#line 2780 "gram.y"
    {
		map_item();
	;}
    break;

  case 273:
#line 2786 "gram.y"
    {
		map_item();
		Defining_multiple = YES;
	;}
    break;

  case 274:
#line 2792 "gram.y"
    {
		/* initialize grpsyl info */
		Curr_grpsyl_p = Last_grpsyl_p = (struct GRPSYL *) 0;
	;}
    break;

  case 276:
#line 2802 "gram.y"
    {
		/* prepare for a new set of ranges */
		begin_range(Place);
		Defining_multiple = YES;
	;}
    break;

  case 277:
#line 2809 "gram.y"
    {
		/* data is for staff with only one voice */
		save_vno_range(1, 1);
		add_to_sv_list();
	;}
    break;

  case 278:
#line 2817 "gram.y"
    {
		if ((yyvsp[(2) - (2)].intval) == YES) {
			add_to_sv_list();
		}
	;}
    break;

  case 279:
#line 2826 "gram.y"
    {
		/* set flag as to whether we are processing tab staff
		 * information or normal staff info */
		Doing_tab_staff = is_tab_range();
	;}
    break;

  case 281:
#line 2836 "gram.y"
    {
		/* several staffs have the same note data */
		Defining_multiple = YES;
	;}
    break;

  case 282:
#line 2842 "gram.y"
    {
		/* remember which staffs we are currently getting data for */
		/* if only a single number, not a range, staff_range will be
		 * 0, so use staffnum as high and low of range */
		save_staff_range((yyvsp[(1) - (2)].intval), ((yyvsp[(2) - (2)].intval) == 0 ? (yyvsp[(1) - (2)].intval) : (yyvsp[(2) - (2)].intval)));
	;}
    break;

  case 283:
#line 2850 "gram.y"
    {
		/* empty - no range, just a single number */
		(yyval.intval) = 0;
	;}
    break;

  case 284:
#line 2857 "gram.y"
    {
		Defining_multiple = YES;
		(yyval.intval) = (yyvsp[(2) - (2)].intval);
		if ((yyvsp[(2) - (2)].intval) == 0) {
			yyerror("staff of 0 is illegal");
		}
	;}
    break;

  case 285:
#line 2867 "gram.y"
    {
		/* note data applies to a single voice */
		if (rangecheck((yyvsp[(1) - (2)].intval), MINVOICES, MAXVOICES, "voice") == YES) {
			save_vno_range((yyvsp[(1) - (2)].intval), (yyvsp[(1) - (2)].intval));
			(yyval.intval) = YES;
		}
		else {
			(yyval.intval) = NO;
		}
	;}
    break;

  case 286:
#line 2880 "gram.y"
    {
		/* note data applies to range of voices */
		if (rangecheck((yyvsp[(1) - (4)].intval), MINVOICES, MAXVOICES, "voice") == YES &&
				rangecheck((yyvsp[(3) - (4)].intval), MINVOICES, MAXVOICES, "voice") == YES) {
			if ((yyvsp[(3) - (4)].intval) < (yyvsp[(1) - (4)].intval)) {
				l_yyerror(Curr_filename, yylineno,
					"end of voice range is smaller than beginning");
				(yyval.intval) = NO;
			}
			else {
				save_vno_range((yyvsp[(1) - (4)].intval), (yyvsp[(3) - (4)].intval));
				Defining_multiple = YES;
				(yyval.intval) = YES;
			}
		}
		else {
			(yyval.intval) = NO;
		}
	;}
    break;

  case 288:
#line 2905 "gram.y"
    {
		Defining_multiple = YES;
	;}
    break;

  case 292:
#line 2920 "gram.y"
    {
		/* Associate any TIMEDSSVs with this group */
		if (Curr_tssv_p != 0) {
			tssv_setgrpsyl(Curr_grpsyl_p);
			Curr_tssv_p = 0;
		}

		/* if no custom beaming indicated, fill in based on previous. */
		if ( Curr_grpsyl_p->beamloc == NOITEM) {
			setbeamloc(Curr_grpsyl_p, Last_grpsyl_p);
		}

		/* later we check that if there is an 'm', it is
		 * the only thing in the measure */

		link_notegroup(Curr_grpsyl_p, Last_grpsyl_p);
		Curr_marklist = 0;
		/* Save pointer to this group, in case there are additive
		 * times, and the next group gets its time value from this
		 * group. In that case, we need this group, not the last one
		 * of the added groups. */
		Prev_grpsyl_p = Curr_grpsyl_p;
		/* Add groups if there were additive time values. */
		if (Extra_time_p != 0) {
			Curr_grpsyl_p = expandgrp(Curr_grpsyl_p, Extra_time_p);
			/* If there was a custom beam ebm on something with
			 * additive time, we need make sure ENDITEM is on only
			 * the last of the expanded groups. */
			if (Curr_grpsyl_p != Prev_grpsyl_p
					&& Prev_grpsyl_p->beamloc == ENDITEM) {
				struct GRPSYL *g_p;
				for (g_p = Prev_grpsyl_p; g_p != Curr_grpsyl_p;
							g_p = g_p->next) {
					g_p->beamloc = INITEM;
				}
				Curr_grpsyl_p->beamloc = ENDITEM;
			}
			Last_grpsyl_p = Curr_grpsyl_p->prev;
		}
		Curr_timelist_p = 0;
	;}
    break;

  case 297:
#line 2978 "gram.y"
    {
		if (Chord_at_a_time == YES) {
			yyerror("mid-measure changes not allowed on chord-at-a-time input");
		}
	;}
    break;

  case 298:
#line 2987 "gram.y"
    {
		Curr_tssv_p = tssv_create(C_SCORE);
	;}
    break;

  case 299:
#line 2993 "gram.y"
    {
		Curr_tssv_p = tssv_create(C_STAFF);
	;}
    break;

  case 300:
#line 2999 "gram.y"
    {
		Curr_tssv_p = tssv_create(C_VOICE);
	;}
    break;

  case 303:
#line 3013 "gram.y"
    {
		if (Curr_grpsyl_p != 0 && Curr_grpsyl_p->grpsyl == GS_GROUP
				&& Curr_grpsyl_p->grpvalue == GV_ZERO) {
			yyerror("mid-measure clef change not allowed after grace note\n");
		}
		tssv_update(Curr_tssv_p, (yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval));
	;}
    break;

  case 304:
#line 3023 "gram.y"
    {
		switch ((yyvsp[(1) - (3)].intval)) {

		case DEFOCT:
		case RELEASE:
			tssv_update(Curr_tssv_p, (yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval));
			break;

		default:
			l_warning(Curr_filename, yylineno,
				"parameter type cannot be changed mid-measure; ignoring");
			break;
		}
	;}
    break;

  case 305:
#line 3040 "gram.y"
    {
		switch ((yyvsp[(1) - (3)].intval)) {

		case ALIGNRESTS:
			tssv_update(Curr_tssv_p, (yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].intval));
			break;

		default:
			l_warning(Curr_filename, yylineno,
				"parameter type cannot be changed mid-measure; ignoring");
			break;
		}
	;}
    break;

  case 307:
#line 3060 "gram.y"
    {
		if (Good_till_canceled == NO) {
			/* use default attributes */
			Curr_grpsyl_p->grpvalue = GV_NORMAL;
			Curr_grpsyl_p->grpsize = GS_NORMAL;
			Curr_grpsyl_p->headshape = HS_UNKNOWN;
		}
		else {
			/* re-use previous style */
			copy_attributes(Curr_grpsyl_p, Last_grpsyl_p);
			Curr_grpsyl_p->with_was_gtc = YES;
		}
	;}
    break;

  case 308:
#line 3076 "gram.y"
    {
		Good_till_canceled = NO;
	;}
    break;

  case 309:
#line 3082 "gram.y"
    {
	;}
    break;

  case 310:
#line 3086 "gram.y"
    {
		Good_till_canceled = NO;
	;}
    break;

  case 311:
#line 3092 "gram.y"
    {
		Good_till_canceled = YES;
	;}
    break;

  case 312:
#line 3097 "gram.y"
    {
	;}
    break;

  case 313:
#line 3102 "gram.y"
    {
		if (Good_till_canceled == YES) {
			yyerror("can't use ... and more than one [] on same chord");
		}
	;}
    break;

  case 314:
#line 3109 "gram.y"
    {
		/* NULL token to cause allocation of a GRPSYL struct */
		Last_grpsyl_p = Curr_grpsyl_p;
		Curr_grpsyl_p = newGRPSYL(GS_GROUP);
	;}
    break;

  case 315:
#line 3116 "gram.y"
    {
		/* an empty marklist means we should use
		 * the same attributes as the last time */
		copy_attributes(Curr_grpsyl_p, Last_grpsyl_p);
	;}
    break;

  case 319:
#line 3133 "gram.y"
    {
		Curr_grpsyl_p->nwith = (short) Item_count;
		Curr_grpsyl_p->withlist = Curr_marklist;
	;}
    break;

  case 323:
#line 3149 "gram.y"
    {
		if (Curr_grpsyl_p->stemdir != UNKNOWN &&
					Curr_grpsyl_p->stemdir != (yyvsp[(1) - (1)].intval)) {
			l_warning(Curr_filename, yylineno,
				"both stem directions specified; using last instance");
		}
		if (Doing_tab_staff == YES) {
			l_warning(Curr_filename, yylineno,
				"stem direction specification is pointless on tab staff; ignoring");
		}
		else {
			Curr_grpsyl_p->stemdir = (yyvsp[(1) - (1)].intval);
		}
	;}
    break;

  case 324:
#line 3166 "gram.y"
    {
		if ((yyvsp[(1) - (3)].intval) != DIST) {
			l_warning(Curr_filename, yylineno,
				"unexpected parameter name; ignoring");
		}
		else {
			if (Curr_grpsyl_p->restdist != NORESTDIST &&
					Curr_grpsyl_p->restdist != (yyvsp[(2) - (3)].intval) * (yyvsp[(3) - (3)].intval)) {
				l_warning(Curr_filename, yylineno,
						"more than one dist value specified; using last instance");
			}
			Curr_grpsyl_p->restdist = (yyvsp[(2) - (3)].intval) * (yyvsp[(3) - (3)].intval);
		}
	;}
    break;

  case 325:
#line 3183 "gram.y"
    {
		if (Curr_grpsyl_p->ho_usage != HO_NONE &&
				Curr_grpsyl_p->ho_usage != (yyvsp[(2) - (2)].intval)) {
			l_warning(Curr_filename, yylineno,
				"More than one ho type specified; last instance used");
		}
		Curr_grpsyl_p->ho_usage = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 326:
#line 3194 "gram.y"
    {
		if (Curr_grpsyl_p != 0) {
			if (Curr_grpsyl_p->headshape != HS_UNKNOWN) {
				l_warning(Curr_filename, yylineno,
					"multiple head shapes specified, using last");
			}
			/* +2 to skip past extraneous font/size */
			if (Doing_tab_staff == YES && strcmp((yyvsp[(2) - (2)].stringval) + 2, "allx") != 0) {
				yyerror("allx is the only headshape allowed on tab staffs");
			}
			if ((Curr_grpsyl_p->headshape = get_shape_num((yyvsp[(2) - (2)].stringval) + 2))
					== HS_UNKNOWN) {
				l_yyerror(Curr_filename, yylineno,
					"'%s' is not a valid head shape name",
					ascii_str((yyvsp[(2) - (2)].stringval), YES, NO, TM_NONE));
			}
		}
		else {
			pfatal("Curr_grpsyl_p was null for setting hs");
		}
		/* We don't need the name anymore; we have its corresponding
		 * number that we use internally. */
		FREE((yyvsp[(2) - (2)].stringval));
	;}
    break;

  case 327:
#line 3221 "gram.y"
    {
		if (Curr_grpsyl_p->stemlen != STEMLEN_UNKNOWN &&
				fabs(Curr_grpsyl_p->stemlen - (yyvsp[(2) - (2)].floatval) * STEPSIZE) > 0.0001) {
			l_warning(Curr_filename, yylineno,
				"more than one len specified; using last instance");
		}
		Curr_grpsyl_p->stemlen = (yyvsp[(2) - (2)].floatval) * STEPSIZE;
		Curr_grpsyl_p->stemlen_forced = YES;
	;}
    break;

  case 328:
#line 3233 "gram.y"
    {
		if ((yyvsp[(2) - (2)].intval) <= 0) {
			yyerror("slash number must be > 0");
		}
		else if ((yyvsp[(2) - (2)].intval) > 8) {
			/* we decided 8 slashes would be at least 256th note
			 * or shorter, and 256th is the shortest note we
			 * support, 8 slashes is plenty */
			l_warning(Curr_filename, yylineno,
				"number of slashes only allowed to be <= 8; limiting to 8");
			(yyvsp[(2) - (2)].intval) = 8;
		}
		if (Curr_grpsyl_p->slash_alt > 0 &&
					Curr_grpsyl_p->slash_alt != (yyvsp[(2) - (2)].intval)) {
			l_warning(Curr_filename, yylineno,
				"more than one slash value specified; using last instance");
		}
		if (Curr_grpsyl_p->slash_alt < 0) {
			yyerror("only one slash/alt allowed per group");
		}
		Curr_grpsyl_p->slash_alt = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 329:
#line 3258 "gram.y"
    {
		(yyval.intval) = HO_RIGHT;
	;}
    break;

  case 330:
#line 3264 "gram.y"
    {
		(yyval.intval) = HO_LEFT;
	;}
    break;

  case 331:
#line 3270 "gram.y"
    {
		/* We want to silently accept identical values specified
		 * more than once, so use fuzzy compare to deal with roundoff */
		if (Curr_grpsyl_p->ho_usage == HO_VALUE &&
				fabs(Curr_grpsyl_p->ho_value - (yyvsp[(1) - (2)].intval) * (yyvsp[(2) - (2)].floatval)) > 0.0001) {
			l_warning(Curr_filename, yylineno,
				"More than one ho value specified; last instance used");
		}
		Curr_grpsyl_p->ho_value = (yyvsp[(1) - (2)].intval) * (yyvsp[(2) - (2)].floatval);
		(yyval.intval) = HO_VALUE;
	;}
    break;

  case 332:
#line 3284 "gram.y"
    {
		(yyval.intval) = 1;
	;}
    break;

  case 333:
#line 3290 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 339:
#line 3312 "gram.y"
    {
		(yyvsp[(3) - (3)].floatval) *= (yyvsp[(2) - (3)].intval);
		if (fabs(Curr_grpsyl_p->beamslope - NOBEAMANGLE) > 0.01) {
			l_warning(Curr_filename, yylineno,
				"multiple slope values specified; using last one");
		}
		if (frangecheck((yyvsp[(3) - (3)].floatval), MINBEAMANGLE, MAXBEAMANGLE, "slope") == YES) {
			Curr_grpsyl_p->beamslope = (yyvsp[(3) - (3)].floatval);
		}
	;}
    break;

  case 340:
#line 3325 "gram.y"
    {
		if ((yyvsp[(2) - (2)].intval) <= 0) {
			yyerror("alt number must be > 0");
		}
		if (Curr_grpsyl_p->slash_alt != 0) {
			yyerror("only one slash/alt allowed per group");
		}
		if (Doing_tab_staff == YES) {
			l_warning(Curr_filename, yylineno,
				"alt not allowed on tablature staff; ignoring");
		}
		else {
			/* Should at least keep small enough
			 * that 1 shifted left by this still fits
			 * in a 16-bit int. For a while we limited to 15,
			 * but for slashes, we limit to 8, and
			 * that seems like more than enough for here too. */
			if ((yyvsp[(2) - (2)].intval) > 8) {
				l_warning(Curr_filename, yylineno,
					"alt value too large; limiting to 8");
				(yyvsp[(2) - (2)].intval) = 8;
			}
			Curr_grpsyl_p->slash_alt = -(yyvsp[(2) - (2)].intval);
		}
	;}
    break;

  case 341:
#line 3353 "gram.y"
    {
		if (Curr_grpsyl_p->phcount < PH_COUNT) {
			Curr_grpsyl_p->phplace[Curr_grpsyl_p->phcount++] = (yyvsp[(2) - (2)].intval);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
				"too many ph marks on the same chord; limiting to %d", PH_COUNT);
		}
	;}
    break;

  case 342:
#line 3365 "gram.y"
    {
		if (Curr_grpsyl_p->ephcount < PH_COUNT) {
			Curr_grpsyl_p->ephcount++;
		}
		else {
			l_yyerror(Curr_filename, yylineno,
				"too many eph marks on the same chord; limiting to %d", PH_COUNT);
		}
	;}
    break;

  case 343:
#line 3376 "gram.y"
    {
		int n;

		/* add a slur to each note in the chord. Don't know
		 * which pitch to slur to yet, just that it will be to
		 * the "matching" note in the next chord, so use
		 * special magic pitch of 'M' to convey this */
		for (n = 0; n < Curr_grpsyl_p->nnotes; n++) {
			add_slurto(Curr_grpsyl_p, 'M', USE_DFLT_OCTAVE, n, (yyvsp[(1) - (3)].intval));
			set_slurdir(Curr_grpsyl_p, -1, (yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval));
		}
	;}
    break;

  case 344:
#line 3391 "gram.y"
    {
		int n;

		Curr_grpsyl_p->tie = YES;
		for (n = 0; n < Curr_grpsyl_p->nnotes; n++) {
			Curr_grpsyl_p->notelist[n].tie = YES;
			Curr_grpsyl_p->notelist[n].tiestyle = (yyvsp[(1) - (3)].intval);
			Curr_grpsyl_p->notelist[n].tiedir = (yyvsp[(2) - (3)].intval);
			Curr_grpsyl_p->notelist[n].tied_to_voice = (yyvsp[(3) - (3)].intval);
		}
	;}
    break;

  case 345:
#line 3404 "gram.y"
    {
		if (Curr_marklist == 0) {
			/* allocate space for a list of marks */
			MALLOCA(char *, Curr_marklist, ITEMS);
			Item_count = 0;
			Max_items = ITEMS;
		}
	;}
    break;

  case 346:
#line 3414 "gram.y"
    {
		(yyval.intval) = UNKNOWN;
	;}
    break;

  case 347:
#line 3420 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 348:
#line 3426 "gram.y"
    {
		(yyval.intval) = NO_TO_VOICE;
	;}
    break;

  case 349:
#line 3432 "gram.y"
    {
		if ((yyvsp[(3) - (3)].intval) >= MINVOICES && (yyvsp[(3) - (3)].intval) <= MAXVOICES) {
			/* Note that if the current staff doesn't have this
			 * to voice, that error will be caught later,
			 * by find_to_group() in tie.c */
			(yyval.intval) = (yyvsp[(3) - (3)].intval);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
					"to voice must be between %d and %d",
					MINVOICES, MAXVOICES);
			(yyval.intval) = NO_TO_VOICE;
		}
	;}
    break;

  case 352:
#line 3455 "gram.y"
    {
		/* if too many items, get some more space */
		if (Item_count >= Max_items) {
			Max_items += ITEMS;
			if ((Curr_marklist = (char **) realloc(Curr_marklist,
						Max_items * sizeof(char **)))
						== (char **) 0) {
				l_no_mem(__FILE__, __LINE__);
			}
		}
		Curr_marklist[Item_count++] = (yyvsp[(1) - (1)].stringval);
	;}
    break;

  case 353:
#line 3469 "gram.y"
    {
		MALLOCA(char, (yyval.stringval), strlen((yyvsp[(1) - (1)].stringval)) + 3);
		(yyval.stringval)[0] = FONT_TR;
		(yyval.stringval)[1] = DFLT_SIZE;
		sprintf((yyval.stringval) + 2, (yyvsp[(1) - (1)].stringval));
	;}
    break;

  case 355:
#line 3482 "gram.y"
    {
		(yyval.stringval) = (Curr_grpsyl_p->grpsize == GS_NORMAL
					? "\\(dot)" : "\\(smdot)");
	;}
    break;

  case 356:
#line 3489 "gram.y"
    {
		(yyval.stringval) = (Curr_grpsyl_p->grpsize == GS_NORMAL
					? "\\(leg)" : "\\(smleg)");
	;}
    break;

  case 357:
#line 3496 "gram.y"
    {
		(yyval.stringval) = (Curr_grpsyl_p->grpsize == GS_NORMAL
					? "\\(acc_gt)" : "\\(smacc_gt)");
	;}
    break;

  case 358:
#line 3503 "gram.y"
    {
		(yyval.stringval) = (Curr_grpsyl_p->grpsize == GS_NORMAL
					? "\\(acc_hat)" : "\\(smacc_hat)");
	;}
    break;

  case 359:
#line 3509 "gram.y"
    {
		if (Curr_grpsyl_p->grpvalue == GV_ZERO) {
			l_warning(Curr_filename, yylineno,
				"both grace and cue specified; using last instance");
		}
		Curr_grpsyl_p->grpvalue = GV_NORMAL;
		Curr_grpsyl_p->grpsize = GS_SMALL;
	;}
    break;

  case 360:
#line 3520 "gram.y"
    {
		if (Curr_grpsyl_p->grpsize == GS_SMALL
					&& Curr_grpsyl_p->grpvalue != GV_ZERO) {
			l_warning(Curr_filename, yylineno,
				"both cue and grace specified; using last instance");
		}

		Curr_grpsyl_p->grpsize = GS_SMALL;
		Curr_grpsyl_p->grpvalue = GV_ZERO;
	;}
    break;

  case 361:
#line 3533 "gram.y"
    {
		if (Curr_grpsyl_p->headshape != HS_UNKNOWN) {
			l_warning(Curr_filename, yylineno,
				"diam is overriding previous headshapes specification");
		}
		Curr_grpsyl_p->headshape = get_shape_num("diam");
	;}
    break;

  case 362:
#line 3543 "gram.y"
    {
		if (Curr_grpsyl_p->headshape != HS_UNKNOWN) {
			l_warning(Curr_filename, yylineno,
				"xnote is overriding previous headshapes specification");
		}
		Curr_grpsyl_p->headshape = get_shape_num(
					Doing_tab_staff == YES ? "allx" : "x");
	;}
    break;

  case 363:
#line 3554 "gram.y"
    {
		(yyval.intval) = UP;
	;}
    break;

  case 364:
#line 3560 "gram.y"
    {
		(yyval.intval) = DOWN;
	;}
    break;

  case 365:
#line 3566 "gram.y"
    {
		/* custom beaming cannot be nested */
		struct GRPSYL *prev_like_gs_p;
		/* Find previous group with same grace-ness. Can't use
		 * prevsimilar() here, since it looks at grpcont too. */
		for (prev_like_gs_p = Last_grpsyl_p; prev_like_gs_p != 0 &&
			prev_like_gs_p->grpvalue != Curr_grpsyl_p->grpvalue;
			prev_like_gs_p = prev_like_gs_p->prev) {
			;
		}
		if (prev_like_gs_p != 0 &&
				((prev_like_gs_p->beamloc == STARTITEM)
				|| (prev_like_gs_p->beamloc == INITEM)) ) {
			yyerror("custom beaming may not be nested");
		}
		/* Non-custom beaming, if any, is done later, in do_bar() */
		else {
			/* begin custom beaming */
			Curr_grpsyl_p->beamloc = STARTITEM;
			if (Curr_grpsyl_p->basictime < 8 && (yyvsp[(2) - (2)].intval) == CS_SAME) {
				yyerror("beamed notes must be 8th or shorter");
			}
		}
		Curr_grpsyl_p->beamto = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 366:
#line 3594 "gram.y"
    {
		Curr_grpsyl_p->breakbeam = YES;
	;}
    break;

  case 367:
#line 3600 "gram.y"
    {
		struct GRPSYL *last_nongrace_p;

		/* find the previous group, skipping grace groups */
		for (last_nongrace_p = Last_grpsyl_p;
				last_nongrace_p != (struct GRPSYL *) 0
				&& last_nongrace_p->grpvalue == GV_ZERO;
				last_nongrace_p = last_nongrace_p->prev) {
			;
		}

		/* check that a custom beam is in progress */
		if ((last_nongrace_p == (struct GRPSYL *) 0)
				|| ((last_nongrace_p != (struct GRPSYL *) 0)
				&& (last_nongrace_p->beamloc != STARTITEM)
				&& (last_nongrace_p->beamloc != INITEM) )) {
			l_warning(Curr_filename, yylineno,
				"'ebm' unexpected: no custom beaming in progress; ignoring");
		}
		else {
			Curr_grpsyl_p->beamloc = ENDITEM;
			Curr_grpsyl_p->beamto = last_nongrace_p->beamto;
			if (Curr_grpsyl_p->basictime < 8
					&& Last_grpsyl_p->beamto == CS_SAME) {
				yyerror("beamed notes must be 8th or shorter");
			}
		}
	;}
    break;

  case 368:
#line 3630 "gram.y"
    {
		/* Use the same as last time or default timeunit.
		 * If that involves additive time values,
		 * save pointer to that info in Extra_time_p for later use. */
		Extra_time_p = copy_timeunit(Curr_grpsyl_p, Prev_grpsyl_p,
						Extra_time_p);
	;}
    break;

  case 369:
#line 3640 "gram.y"
    {
		if (Curr_grpsyl_p->is_meas == YES) {
			Curr_grpsyl_p->fulltime = Score.time;
		}
		else {
			Curr_grpsyl_p->fulltime = (yyvsp[(1) - (1)].ratval);
		}
	;}
    break;

  case 370:
#line 3650 "gram.y"
    {
		(yyval.intval) = CS_SAME;
	;}
    break;

  case 371:
#line 3656 "gram.y"
    {
		CSBused = YES;
		switch ((yyvsp[(3) - (3)].intval)) {
		case PL_ABOVE:
			(yyval.intval) = CS_ABOVE;
			break;
		case PL_BELOW:
			(yyval.intval) = CS_BELOW;
			break;
		default:
			yyerror("bm with staff must be 'above' or 'below'");
			(yyval.intval) = CS_SAME;
		}
	;}
    break;

  case 372:
#line 3672 "gram.y"
    {
		(yyval.ratval).n = (yyvsp[(1) - (1)].intval);
		(yyval.ratval).d = 1;

		/* if filling in a GRPSYL struct, need to fill in basic time,
		 * could also be here due to beamstyle, in which case the
		 * Curr_grpsyl_p will be NULL, or when getting tuplet duration,
		 * in which case flag will be set */
		if (Curr_grpsyl_p != (struct GRPSYL *) 0
					&& Getting_tup_dur == NO) {
			/* If we are gathering basictime as part of a list
			 * of additive times, we will save the value a few
			 * lines down from here. But in the normal case,
			 * we set basictime in the current GRPSYL. */
			if (Extra_time_p == 0) {
				/* 1/2 is 0 internally. 1/4 is -1 internally */
				 Curr_grpsyl_p->basictime = ((yyvsp[(1) - (1)].intval) == 2 ? 0 : -1);
			}
		}
		/* If doing additive times, need to save value. */
		if (Extra_time_p != 0) {
			Extra_basictime = ((yyvsp[(1) - (1)].intval) == 2 ? 0 : -1);
		}
	;}
    break;

  case 373:
#line 3699 "gram.y"
    {
		/* check that a power of two from 1 to MAXBASICTIME */
		if (power_of2check((yyvsp[(1) - (1)].intval), "note basic time value") == NO) {
			/* force to a power to two, so that other code
			 * (like in expandgrp) that expect a sane value
			 * will not blow up. This may lead to a somewhat
			 * misleading "time does not add up to time
			 * signature" message, but we don't know what
			 * time they really meant, and this is better
			 * than pfataling. */
			(yyvsp[(1) - (1)].intval) = 2;
		}
		/* can't use rangecheck here because the error message would
		 * say 0 and -1 are valid times, which is only true internally--
		 * the user has to use 1/2, 1/4 or m. */
		if ((yyvsp[(1) - (1)].intval) < MINBASICTIME || (yyvsp[(1) - (1)].intval) > MAXBASICTIME) {
			l_yyerror(Curr_filename, yylineno,
				"time value must be between 1 and %d, or 1/2 or 1/4 or m",
				MAXBASICTIME);
			/* If user entered outrageous value, clamp to
			 * something semi-reasonable, else we could get
			 * rational overflow, and pfatal, even though it
			 * it is really a user error. */
			if ((yyvsp[(1) - (1)].intval) > MAXBASICTIME * 4) {
				(yyvsp[(1) - (1)].intval) = MAXBASICTIME * 4;
			}
		}
		(yyval.ratval).n = 1;
		/* avoid division by zero */
		if ((yyvsp[(1) - (1)].intval) == 0) {
			(yyvsp[(1) - (1)].intval) = 1;
		}
		(yyval.ratval).d = (yyvsp[(1) - (1)].intval);
		if (Curr_grpsyl_p != (struct GRPSYL *) 0
					&& Getting_tup_dur == NO) {
			if (Curr_timelist_p == 0) {
				Curr_grpsyl_p->basictime = (yyvsp[(1) - (1)].intval);
			}
		}
		/* If doing additive times, need to save value */
		if (Extra_time_p != 0) {
			Extra_basictime = (yyvsp[(1) - (1)].intval);
		}
	;}
    break;

  case 374:
#line 3746 "gram.y"
    {
		free_extra_time();
	;}
    break;

  case 376:
#line 3756 "gram.y"
    {
		/* Set basictime to what we saved in basic_time_val rule,
		 * then calculate fulltime from that and number of dots. */
		Curr_timelist_p->basictime = Extra_basictime;
		Curr_timelist_p->fulltime = calcfulltime((yyvsp[(3) - (4)].ratval), (yyvsp[(4) - (4)].intval));
		/* handle subtracted times by negating the fulltime */
		if ((yyvsp[(1) - (4)].intval) == -1) {
			Curr_timelist_p->fulltime = rneg(Curr_timelist_p->fulltime);
		}
	;}
    break;

  case 377:
#line 3770 "gram.y"
    {
		struct TIMELIST *timelist_p;

		MALLOC(TIMELIST, timelist_p, 1);
		/* Add to end of linked list */
		timelist_p->next = 0;
		/* Init fulltime to something to avoid garbage if there
		 * in a user input error */
		timelist_p->fulltime = Zero;
		if (Extra_time_p == 0) {
			Last_alloced_timelist_p = Extra_time_p = timelist_p;
		}
		else {
			Curr_timelist_p->next = timelist_p;
		}
		/* Keep track of where to append next item to list, if any */
		Curr_timelist_p = timelist_p;
	;}
    break;

  case 378:
#line 3791 "gram.y"
    {
		User_meas_time = NO;
	;}
    break;

  case 379:
#line 3797 "gram.y"
    {
		if (Curr_grpsyl_p != (struct GRPSYL *) 0
					&& Getting_tup_dur == NO) {
			Curr_grpsyl_p->is_meas = YES;
			User_meas_time = YES;
		}
		else {
			yyerror("'m' is not valid here");
		}
	;}
    break;

  case 380:
#line 3809 "gram.y"
    {
		(yyval.intval) = 0;
	;}
    break;

  case 381:
#line 3815 "gram.y"
    {
		/* count up the number of dots */
		(yyval.intval) = (yyvsp[(1) - (2)].intval) + 1;
	;}
    break;

  case 382:
#line 3821 "gram.y"
    {
		/* We can't distinguish between the default 0.0 and
		 * if user explicitly sets to 0.0, so if they set to 0.0
		 * then to something else, we won't catch that as setting
		 * twice, but that shouldn't be common. Besides, if they
		 * expect them to be additive, adding to zero will work
		 * as they expect... Because of roundoff, we can't do
		 * exact compare for specifying the same value more than once,
		 * so treat as identical if pretty close. */
		if (Curr_grpsyl_p->padding != 0.0 && 
				fabs(Curr_grpsyl_p->padding - ((yyvsp[(1) - (1)].floatval) * STEPSIZE))
				> 0.0001) {
			l_warning(Curr_filename, yylineno,
				"padding specified more than once; using last instance");
		}
		Curr_grpsyl_p->padding = (yyvsp[(1) - (1)].floatval) * STEPSIZE;
	;}
    break;

  case 383:
#line 3841 "gram.y"
    {
		(yyval.floatval) = (float) (yyvsp[(2) - (3)].intval) * (yyvsp[(3) - (3)].floatval);
	;}
    break;

  case 384:
#line 3846 "gram.y"
    {
		/* no sign--must be a positive number */
		(yyval.intval) = 1;
	;}
    break;

  case 385:
#line 3853 "gram.y"
    {
		/* user wants a negative number */
		(yyval.intval) = -1;
	;}
    break;

  case 386:
#line 3859 "gram.y"
    {
		Curr_grpsyl_p->grpcont = GC_NOTES;
		if ((yyvsp[(1) - (1)].intval) == 0) {
			/* no notes listed, use same as previous group */
			copy_notes(Curr_grpsyl_p, Last_grpsyl_p);
		}
		else {
			resize_notelist(Curr_grpsyl_p);
		}
	;}
    break;

  case 390:
#line 3884 "gram.y"
    {
		/* allocate GRPSYL for the case where everything is defaulted
		 * from the previous group, with just an extra attribute
		 * like ? or ~ specified. */
		if (Curr_grpsyl_p == (struct GRPSYL *) 0) {
			/* shouldn't ever happen, but just in case... */
			Curr_grpsyl_p = newGRPSYL(GS_GROUP);
		}
		if (Last_grpsyl_p != (struct GRPSYL *) 0 &&
					Last_grpsyl_p->nnotes >= 1) {
			copy_notes(Curr_grpsyl_p, Last_grpsyl_p);
		}
		else if (Last_grpsyl_p != (struct GRPSYL *) 0 && 
				Last_grpsyl_p->grpcont == GC_REST) {
			Curr_grpsyl_p->grpcont = GC_REST;
		}
	;}
    break;

  case 391:
#line 3904 "gram.y"
    {
		if (Curr_grpsyl_p->grpcont == GC_NOTES &&
					Curr_grpsyl_p->nnotes > 0) {
			Curr_grpsyl_p->notelist[Curr_grpsyl_p->nnotes - 1]
						.notesize = GS_SMALL;
		}
		else if (Curr_grpsyl_p->grpcont == GC_REST) {
			Curr_grpsyl_p->grpsize  = GS_SMALL;
		}
		else {
			yyerror("no note specified for '?'");
		}
	;}
    break;

  case 392:
#line 3920 "gram.y"
    {
		if (Curr_grpsyl_p->grpcont != GC_NOTES) {
			yyerror("can't tie a rest or space");
		}
		else if (Curr_grpsyl_p->nnotes > 0) {
			struct NOTE *n_p;
			n_p = &(Curr_grpsyl_p->notelist[Curr_grpsyl_p->nnotes - 1]);
			n_p->tie = YES;
			n_p->tiestyle = (yyvsp[(1) - (3)].intval);
			n_p->tiedir = (yyvsp[(2) - (3)].intval);
			n_p->tied_to_voice = (yyvsp[(3) - (3)].intval);
		}
		else {
			yyerror("no note specified for '~'");
		}
	;}
    break;

  case 393:
#line 3939 "gram.y"
    {
		if (Curr_grpsyl_p->nnotes > 0) {
			switch (Curr_grpsyl_p->notelist
                                        [Curr_grpsyl_p->nnotes - 1].letter) {
			case PP_REST:
				/* If we haven't already allocated space for
				 * the restc array, so that now. It could
				 * already be allocated if user specified
				 * more than one tag. */
				if (Curr_grpsyl_p->restc == 0) {
					MALLOCA(float, Curr_grpsyl_p->restc, NUMCTYPE);
				}
				addsym((yyvsp[(2) - (2)].stringval), Curr_grpsyl_p->restc, CT_NOTE);
				break;
			case PP_SPACE:
			case PP_RPT:
			case PP_NO_PITCH:  /* this one not really possible */
				addsym((yyvsp[(2) - (2)].stringval), Curr_grpsyl_p->c, CT_GRPSYL);
				break;
			default:
				addsym((yyvsp[(2) - (2)].stringval), Curr_grpsyl_p->notelist
					[Curr_grpsyl_p->nnotes - 1].c, CT_NOTE);
				break;
			}
			var_valid();
		}
		else if (Curr_grpsyl_p->grpcont == GC_REST) {
			/* This should really never be hit anymore since
			 * chord-at-a-time code was added, but shouldn't
			 * hurt to leave it, just in case. */
			addsym((yyvsp[(2) - (2)].stringval), Curr_grpsyl_p->c, CT_GRPSYL);
			var_valid();
		}
		else {
			l_yyerror(Curr_filename, yylineno,
				"no note specified for location tag '%s'", (yyvsp[(2) - (2)].stringval));
		}
	;}
    break;

  case 394:
#line 3980 "gram.y"
    {
		/* this is for bend on a non-tablature staff */
		if (Doing_tab_staff == YES) {
			yyerror("^ bend not allowed on tablature staff; use quoted bend string");
		}
		else {
			add_slurto(Curr_grpsyl_p, (yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval),
					Curr_grpsyl_p->nnotes - 1, L_NORMAL);
			if (Curr_grpsyl_p->nnotes > 0) {
				Curr_grpsyl_p->notelist
						[Curr_grpsyl_p->nnotes - 1]
						.is_bend = YES;
			}
		}
	;}
    break;

  case 395:
#line 3998 "gram.y"
    {
		/* this is for a small bend (1/4 step) on a non-tab staff */
		if (Doing_tab_staff == YES) {
			yyerror("^/ not allowed on tablature staff; use quoted bend string");
		}
		else if (Curr_grpsyl_p != 0 && Curr_grpsyl_p->nnotes > 0) {
			Curr_grpsyl_p->notelist[Curr_grpsyl_p->nnotes - 1]
					.smallbend = YES;
		}
	;}
    break;

  case 396:
#line 4011 "gram.y"
    {
		if (Curr_grpsyl_p->grpcont == GC_NOTES &&
					Curr_grpsyl_p->nnotes > 0) {
			if ((Curr_grpsyl_p->notelist[Curr_grpsyl_p->nnotes - 1]
					.headshape = get_shape_num((yyvsp[(2) - (2)].stringval) + 2))
					== HS_UNKNOWN) {
				l_yyerror(Curr_filename, yylineno,
					"'%s' is not a valid head shape name",
					ascii_str((yyvsp[(2) - (2)].stringval), YES, NO, TM_NONE));
			}
		}
		else {
			yyerror("no note specified for headshape");
		}
		FREE((yyvsp[(2) - (2)].stringval));
	;}
    break;

  case 400:
#line 4040 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (2)].intval) + (yyvsp[(2) - (2)].intval);	/* total number of notes */
	;}
    break;

  case 401:
#line 4046 "gram.y"
    {
		(yyval.intval) = 0;
	;}
    break;

  case 402:
#line 4052 "gram.y"
    {
		switch ((yyvsp[(3) - (3)].intval)) {
		case PL_ABOVE:
			Curr_grpsyl_p->stemto = CS_ABOVE;
			break;
		case PL_BELOW:
			Curr_grpsyl_p->stemto = CS_BELOW;
			break;
		default:
			yyerror("cross staff stem must be with 'above' or 'below'");
			Curr_grpsyl_p->stemto = CS_SAME;
		}
		if ((yyvsp[(2) - (3)].intval) == 0) {
			/* Maybe this wouldn't really hurt to allow,
			 * but it's rather silly--why would user bother to go
			 * to the trouble of saying there are cross staff stem
			 * notes, but then not list any?
			 */
			yyerror("cross-staff stem note list is empty");
		}

		/* It doesn't make sense to do "with r below" or "with s below"
		 * since we don't allow mixing rests and notes, and the only
		 * reason for CSS is for something that has a stem. */
		else if ((yyvsp[(2) - (3)].intval) > 0) {
			int idx;
			int pitch;

			for (idx = FCNI(Curr_grpsyl_p);
					idx <= LCNI(Curr_grpsyl_p); idx++) {
				pitch = Curr_grpsyl_p->notelist[idx].letter;
				if (pitch == PP_REST || pitch == PP_SPACE) {
					yyerror("can't use with above/below on rest or space");
				}
			}
		}
		(yyval.intval) = (yyvsp[(2) - (3)].intval);
	;}
    break;

  case 403:
#line 4092 "gram.y"
    {
		CSSused = YES;
		Curr_grpsyl_p->stemto_idx = Curr_grpsyl_p->nnotes;
	;}
    break;

  case 404:
#line 4098 "gram.y"
    {
		/* No notes.  If this is for the list of "normal" staff notes,
		 * and there are no "other" staff notes (for cross-staff stems),
		 * this means use the same notes as the last group. */
		(yyval.intval) = 0;
	;}
    break;

  case 405:
#line 4107 "gram.y"
    {
		/* return number of notes in notelist */
		(yyval.intval) = (yyvsp[(1) - (3)].intval) + 1;
	;}
    break;

  case 407:
#line 4116 "gram.y"
    {
		add_note(Curr_grpsyl_p, (int) PP_REST, 0, USE_DFLT_OCTAVE,
							0, NO, (char *) 0);
	;}
    break;

  case 408:
#line 4123 "gram.y"
    {
		/* temporarily stash uncompressibility (NO in this case)
		 * in the octave field */
		add_note(Curr_grpsyl_p, (int) PP_SPACE, 0, NO,
							0, NO, (char *) 0);
		if (Curr_grpsyl_p->is_meas == YES && User_meas_time == YES) {
			l_warning(Curr_filename, yylineno,
				"specifying time value on measure space is pointless; ignoring");
		}
	;}
    break;

  case 409:
#line 4136 "gram.y"
    {
		/* temporarily stash uncompressibility (YES in this case)
		 * in the octave field */
		add_note(Curr_grpsyl_p, (int) PP_SPACE, 0, YES,
							0, NO, (char *) 0);
		if (Curr_grpsyl_p->is_meas == YES && User_meas_time == YES) {
			l_warning(Curr_filename, yylineno,
				"specifying time value on measure uncollapseable space is pointless; ignoring");
		}
	;}
    break;

  case 410:
#line 4149 "gram.y"
    {
		if (Curr_grpsyl_p->is_meas == YES) {
			if (User_meas_time == YES) {
				l_warning(Curr_filename, yylineno,
					"specifying time value on measure repeat is pointless; ignoring");
			}
		}
		else {
			yyerror("rpt can only be used with m");
		}
		add_note(Curr_grpsyl_p, (int) PP_RPT, 0, USE_DFLT_OCTAVE,
							0, NO, (char *) 0);
	;}
    break;

  case 411:
#line 4165 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == SINGLEBAR) {
			/* lexer thinks this is 'bar'
			 * but is really 'b' 'a' 'r' */
			keyword_notes(yytext);
		}
		else if ((yyvsp[(1) - (1)].intval) == ENDBAR) {
			/* lexer thinks this is 'endbar'
			 * but is really 'en' 'd' 'b' 'a' 'r' */
			add_note(Curr_grpsyl_p, (int) 'e', 'n',
				USE_DFLT_OCTAVE, 0, NO, (char *) 0);
			keyword_notes(yytext + 2);
		}
		else {
			yyerror("bar type not valid here");
		}
	;}
    break;

  case 412:
#line 4185 "gram.y"
    {
		/* lexer thinks this is 'grace' but really 'g' 'r' 'a' 'c' 'e' */
		keyword_notes(yytext);
	;}
    break;

  case 413:
#line 4192 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == ENDING_BARRED) {
			keyword_notes(yytext);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
					"%s not valid here", yytext);
		}
	;}
    break;

  case 414:
#line 4203 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == J_RAGPARA) {
			keyword_notes(yytext);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
					"%s not valid here", yytext);
		}
	;}
    break;

  case 415:
#line 4215 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == BRACELIST) {
			keyword_notes(yytext);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
					"%s not valid here", yytext);
		}
	;}
    break;

  case 416:
#line 4227 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == BASS) {
			keyword_notes(yytext);
		}
		else {
			l_yyerror(Curr_filename, yylineno,
					"%s not valid here", yytext);
		}
	;}
    break;

  case 417:
#line 4239 "gram.y"
    {
		/* in chord-at-time mode, lex could mistake useaccs
		 * for a 6-note chord: us e a c c s  */
		keyword_notes(yytext);
	;}
    break;

  case 418:
#line 4247 "gram.y"
    {
		Curr_grpsyl_p->notelist[Curr_grpsyl_p->nnotes - 1].note_has_paren = YES;
	;}
    break;

  case 419:
#line 4252 "gram.y"
    {
		if (Doing_tab_staff == YES) {
			add_note(Curr_grpsyl_p, (yyvsp[(1) - (2)].intval), 0, NOFRET, 0, NO, (yyvsp[(2) - (2)].stringval));
		}
		else {
			add_note(Curr_grpsyl_p, (yyvsp[(1) - (2)].intval), 0, USE_DFLT_OCTAVE, 0, NO, (yyvsp[(2) - (2)].stringval));
		}
	;}
    break;

  case 420:
#line 4263 "gram.y"
    {
		if (Doing_tab_staff == YES) {
			l_warning(Curr_filename, yylineno,
				"parentheses around accidentals are extraneous on tab staffs; ignoring");
		}
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (5)].intval), (yyvsp[(3) - (5)].intval), (yyvsp[(5) - (5)].intval), 0, YES, (char *) 0);
	;}
    break;

  case 421:
#line 4273 "gram.y"
    {
		if (Doing_tab_staff == NO) {
			l_warning(Curr_filename, yylineno,
				"parentheses around octave are extraneous; ignoring");
		}
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (5)].intval), 0, (yyvsp[(3) - (5)].intval), 0, YES, (yyvsp[(5) - (5)].stringval));
	;}
    break;

  case 422:
#line 4283 "gram.y"
    {
		/* Whoops! The left paren was really for a new note,
		 * which happens to be parenthesized. But beause yacc only
		 * looks ahead one token, it finds out too late. So we
		 * catch it here, push the parenthesis and pitch back into
		 * the input and return back to the parent grammar rule,
		 * since we now have complete note. */
		pushback(yytext[0]);
		pushback('(');
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (3)].intval), 0,
			(Doing_tab_staff ? NOFRET : USE_DFLT_OCTAVE),
			0, NO, (char *) 0);
	;}
    break;

  case 423:
#line 4299 "gram.y"
    {
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (5)].intval), (yyvsp[(2) - (5)].intval), (yyvsp[(4) - (5)].intval), (yyvsp[(3) - (5)].intval), NO, (yyvsp[(5) - (5)].stringval));
	;}
    break;

  case 424:
#line 4305 "gram.y"
    {
		if (Doing_tab_staff == NO) {
			l_warning(Curr_filename, yylineno,
				"extraneous parentheses around octave; ignoring");
		}
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (7)].intval), (yyvsp[(2) - (7)].intval), (yyvsp[(5) - (7)].intval), (yyvsp[(3) - (7)].intval), YES, (yyvsp[(7) - (7)].stringval));
	;}
    break;

  case 425:
#line 4315 "gram.y"
    {
		/* Whoops! The left paren was really for a new note,
		 * which happens to be parenthesized. But beause yacc only
		 * looks ahead one token, it finds out too late. So we
		 * catch it here, push the parenthesis and pitch back into
		 * the input and return back to the parent grammar rule,
		 * since we now have complete note. */
		pushback(yytext[0]);
		pushback('(');
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (5)].intval), (yyvsp[(2) - (5)].intval),
			(Doing_tab_staff ? NOFRET : USE_DFLT_OCTAVE),
			(yyvsp[(3) - (5)].intval), NO, (char *) 0);
	;}
    break;

  case 426:
#line 4331 "gram.y"
    {
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (4)].intval), 0, (yyvsp[(3) - (4)].intval), (yyvsp[(2) - (4)].intval), NO, (yyvsp[(4) - (4)].stringval));
	;}
    break;

  case 427:
#line 4337 "gram.y"
    {
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (6)].intval), 0, (yyvsp[(4) - (6)].intval), (yyvsp[(2) - (6)].intval), YES, (yyvsp[(6) - (6)].stringval));
	;}
    break;

  case 428:
#line 4343 "gram.y"
    {
		if (Doing_tab_staff == YES && (yyvsp[(3) - (4)].intval) != '\0') {
			yyerror("accidental must be before fret number");
		}
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (4)].intval), (yyvsp[(3) - (4)].intval), (yyvsp[(2) - (4)].intval), 0, NO, (yyvsp[(4) - (4)].stringval));
	;}
    break;

  case 429:
#line 4352 "gram.y"
    {
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (5)].intval), (yyvsp[(4) - (5)].intval), (yyvsp[(2) - (5)].intval), 0, YES, (char *) 0);
	;}
    break;

  case 430:
#line 4358 "gram.y"
    {
		/* Whoops! The left paren was really for a new note,
		 * which happens to be parenthesized. But beause yacc only
		 * looks ahead one token, it finds out too late. So we
		 * catch it here, push the parenthesis and pitch back into
		 * the input and return back to the parent grammar rule,
		 * since we now have complete note. */
		pushback(yytext[0]);
		pushback('(');
		add_note(Curr_grpsyl_p, (yyvsp[(1) - (4)].intval), 0, (yyvsp[(2) - (4)].intval), 0, NO, (char *) 0);
	;}
    break;

  case 431:
#line 4371 "gram.y"
    {
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 432:
#line 4377 "gram.y"
    {
		if (Doing_tab_staff == NO) {
			/* try to give helpful error message */
			if (get_shape_num((yyvsp[(1) - (1)].stringval) + 2) != HS_UNKNOWN) {
				yyerror("missing 'hs' before headshape string");
			}
			else if (strcmp((yyvsp[(1) - (1)].stringval) + 2, "full") == 0 || isdigit((yyvsp[(1) - (1)].stringval)[2])) {
				yyerror("bend string not allowed on non-tablature staff; use ^");
			}
			else {
				yyerror("unexpected string");
			}
			(yyval.stringval) = (char *) 0;
		}
	;}
    break;

  case 433:
#line 4394 "gram.y"
    {
		/* return 'a' to 'g' value */
		(yyval.intval) = (int) *yytext;
	;}
    break;

  case 434:
#line 4400 "gram.y"
    {
		/* no accidental */
		(yyval.intval) = 0;
	;}
    break;

  case 435:
#line 4407 "gram.y"
    {
	;}
    break;

  case 436:
#line 4411 "gram.y"
    {
		/* no octave or fret designation */
		(yyval.intval) = (Doing_tab_staff ? NOFRET : USE_DFLT_OCTAVE);
	;}
    break;

  case 437:
#line 4418 "gram.y"
    {
	;}
    break;

  case 438:
#line 4423 "gram.y"
    {
		(yyval.intval) = '#';
	;}
    break;

  case 439:
#line 4429 "gram.y"
    {
		(yyval.intval) = '&';
	;}
    break;

  case 440:
#line 4435 "gram.y"
    {
		/* natural */
		(yyval.intval) = 'n';
	;}
    break;

  case 441:
#line 4442 "gram.y"
    {
		/* double sharp */
		(yyval.intval) = 'x';
	;}
    break;

  case 442:
#line 4449 "gram.y"
    {
		(yyval.intval) = 'B';
	;}
    break;

  case 443:
#line 4455 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 444:
#line 4461 "gram.y"
    {
		/* we can't really fill in the actual octave yet, because
		 * it may be different on different staffs or voices, so
		 * we store the relative octave and fill in actual value
		 * later.
		 */
		/* this will be a negative number */
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 445:
#line 4473 "gram.y"
    {
		/* we can't really fill in the actual octave yet, because
		 * it may be different on different staffs or voices, so
		 * we store the relative octave and fill in actual value
		 * later.
		 */
		(yyval.intval) = USE_DFLT_OCTAVE + (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 446:
#line 4483 "gram.y"
    {
		(yyval.intval) = -1;
	;}
    break;

  case 447:
#line 4489 "gram.y"
    {
		/* count up the number of minus signs */
		(yyval.intval) = (yyvsp[(1) - (2)].intval) - 1;
	;}
    break;

  case 448:
#line 4495 "gram.y"
    {
		(yyval.intval) = 1;
	;}
    break;

  case 449:
#line 4501 "gram.y"
    {
		/* count up the number of plus signs */
		(yyval.intval) = (yyvsp[(1) - (2)].intval) + 1;
	;}
    break;

  case 450:
#line 4508 "gram.y"
    {
		set_slurdir(Curr_grpsyl_p, Curr_grpsyl_p->nnotes - 1, (yyvsp[(4) - (5)].intval), (yyvsp[(5) - (5)].intval));
	;}
    break;

  case 451:
#line 4515 "gram.y"
    {
		Linetype = (yyvsp[(1) - (1)].intval);
		begin_slur(Curr_grpsyl_p, Curr_grpsyl_p->nnotes - 1);
	;}
    break;

  case 452:
#line 4521 "gram.y"
    {
		/* empty list. Only allowed if only one note in following
		 * group. However, we don't know that yet, so marked pitch
		 * as 'U' for unknown */
		add_slurto(Curr_grpsyl_p, 'U', USE_DFLT_OCTAVE,
				Curr_grpsyl_p->nnotes - 1, Linetype);
	;}
    break;

  case 453:
#line 4531 "gram.y"
    {
		add_slurto(Curr_grpsyl_p, 0, (yyvsp[(1) - (1)].intval), Curr_grpsyl_p->nnotes - 1,
						Linetype);
	;}
    break;

  case 457:
#line 4549 "gram.y"
    {
		if (Doing_tab_staff == YES) {
			yyerror("cannot specify string inside <> on tab staffs");
		}
		else {
			add_slurto(Curr_grpsyl_p, (yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].intval),
					Curr_grpsyl_p->nnotes - 1, Linetype);
		}
	;}
    break;

  case 458:
#line 4561 "gram.y"
    {
		/* save address associated with entire group */
		if ( (yyvsp[(2) - (2)].stringval) != (char *) 0) {
			addsym((yyvsp[(2) - (2)].stringval), Curr_grpsyl_p->c, CT_GRPSYL);
			var_valid();
		}
	;}
    break;

  case 459:
#line 4570 "gram.y"
    {
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 460:
#line 4576 "gram.y"
    {
		/* a-g are usually pitches, but in this context, they
		 * are 1-character variable names. */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 461:
#line 4584 "gram.y"
    {
		/* usually m means measure, but here it is the variable m */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 462:
#line 4591 "gram.y"
    {
		/* usually rest, here variable r */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 463:
#line 4598 "gram.y"
    {
		/* usually space, here variable s */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 464:
#line 4605 "gram.y"
    {
		/* usually uncompressible, here variable u */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 465:
#line 4612 "gram.y"
    {
		/* usually natural, here variable n */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 466:
#line 4619 "gram.y"
    {
		/* usually double sharp, here variable x */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 467:
#line 4625 "gram.y"
    {
		/* longer variable -- one with more than one character name */
		(yyval.stringval) = strcpy(Stringbuff, yytext);
	;}
    break;

  case 468:
#line 4631 "gram.y"
    {
		end_tuplet((yyvsp[(5) - (8)].intval), (yyvsp[(7) - (8)].ratval), (yyvsp[(6) - (8)].intval), (yyvsp[(4) - (8)].intval));
		Getting_tup_dur = NO;
	;}
    break;

  case 469:
#line 4637 "gram.y"
    {
		/* nothing -- use default of when to print tuplet number/bracket */
		(yyval.intval) = PT_DEFAULT;
	;}
    break;

  case 470:
#line 4644 "gram.y"
    {
		/* don't print tuplet or bracket */
		(yyval.intval) = PT_NEITHER;
	;}
    break;

  case 471:
#line 4651 "gram.y"
    {
		/* print number only */
		(yyval.intval) = PT_NUMBER;
	;}
    break;

  case 472:
#line 4658 "gram.y"
    {
		if (*yytext == 'y') {
			(yyval.intval) = PT_BOTH;
		}
		else {
			yyerror("tuplet number/bracket qualifier must be y or n or num");
		}
	;}
    break;

  case 473:
#line 4670 "gram.y"
    {
		begin_tuplet();
	;}
    break;

  case 474:
#line 4675 "gram.y"
    {
		Getting_tup_dur = YES;
	;}
    break;

  case 475:
#line 4680 "gram.y"
    {
		(yyval.intval) = PL_UNKNOWN;
	;}
    break;

  case 476:
#line 4686 "gram.y"
    {
		if (yylval.intval == PL_BETWEEN) {
			yyerror("between not allowed for tuplet side");
			(yyval.intval) = PL_UNKNOWN;
		}
	;}
    break;

  case 477:
#line 4694 "gram.y"
    {
		/* optional time value is missing */
		(yyval.ratval).n = 0;
		(yyval.ratval).d = 1;
	;}
    break;

  case 478:
#line 4702 "gram.y"
    {
		(yyval.ratval) = (yyvsp[(2) - (2)].ratval);
	;}
    break;

  case 479:
#line 4707 "gram.y"
    {
	;}
    break;

  case 480:
#line 4711 "gram.y"
    {
		Last_grpsyl_p = Curr_grpsyl_p = (struct GRPSYL *) 0;
	;}
    break;

  case 481:
#line 4716 "gram.y"
    {
		/* If user does "all" without specifying a place,
		 * all() will call dflt_place() which was really intended
		 * to only handle STUFF. So we have to tell it we have lyrics,
		 * not a true STUFF. */
		set_stuff_type(-1);
	;}
    break;

  case 482:
#line 4725 "gram.y"
    {
		/* empty, use default */
		begin_range(PL_UNKNOWN);
		(yyval.intval) = PL_UNKNOWN;
	;}
    break;

  case 483:
#line 4733 "gram.y"
    {
		begin_range((yyvsp[(1) - (1)].intval));
	;}
    break;

  case 484:
#line 4738 "gram.y"
    {
		(yyval.intval)= PL_UNKNOWN;
	;}
    break;

  case 485:
#line 4744 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) == PL_BETWEEN) {
			yyerror("place for ph, if specified, must be above or below, not between");
		}
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 487:
#line 4755 "gram.y"
    {
		/* means goes above or below all the staffs, regardless if
		 * some happen to be invisible at the moment, so find top
		 * or bottom visible staff as appropriate,and save that
		 * away as the staff range */
		all();
	;}
    break;

  case 489:
#line 4768 "gram.y"
    {
		/* if staff_range == 0, then only one staff specified, so
		 * use first staff number for both beginning and end of range */
		save_staff_range((yyvsp[(1) - (2)].intval), ((yyvsp[(2) - (2)].intval) == 0 ? (yyvsp[(1) - (2)].intval) : (yyvsp[(2) - (2)].intval)) );
	;}
    break;

  case 490:
#line 4775 "gram.y"
    {
		/* empty */
		chk_range_type(NO);
		(yyval.intval) = 0;
	;}
    break;

  case 491:
#line 4783 "gram.y"
    {
		chk_range_type(NO);
		(yyval.intval) = (yyvsp[(2) - (2)].intval);
		if ((yyvsp[(2) - (2)].intval) == 0) {
			yyerror("staff of 0 is illegal");
		}
	;}
    break;

  case 492:
#line 4793 "gram.y"
    {
		chk_range_type(YES);
		(yyval.intval) = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 494:
#line 4802 "gram.y"
    { Place = (yyvsp[(3) - (3)].intval); ;}
    break;

  case 496:
#line 4807 "gram.y"
    {
	;}
    break;

  case 497:
#line 4812 "gram.y"
    {
		if (*yytext != 'c') {
			yyerror("verse must be 'c' or number(s)");
		}
		else {
			save_vno_range(0, 0);
		}
	;}
    break;

  case 498:
#line 4823 "gram.y"
    {
	;}
    break;

  case 499:
#line 4828 "gram.y"
    {
	;}
    break;

  case 500:
#line 4833 "gram.y"
    {
		/* if end of range is 0, not really a range, use first number
		 * for both beginning and end */
		lyr_verse((yyvsp[(1) - (2)].intval), ((yyvsp[(2) - (2)].intval) == 0 ? (yyvsp[(1) - (2)].intval) : (yyvsp[(2) - (2)].intval)));
	;}
    break;

  case 501:
#line 4840 "gram.y"
    {
		/* empty */
		(yyval.intval) = 0;
	;}
    break;

  case 502:
#line 4847 "gram.y"
    {
		(yyval.intval) = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 503:
#line 4852 "gram.y"
    {
		/* null token to allocate a GRPSYL for a lyric */
		Last_grpsyl_p = Curr_grpsyl_p;
		Curr_grpsyl_p = newGRPSYL(GS_SYLLABLE);
		if (Last_grpsyl_p == (struct GRPSYL *) 0) {
			Lyrics_p = Curr_grpsyl_p;
		}
	;}
    break;

  case 504:
#line 4862 "gram.y"
    {
		/* If user didn't specify a place, fix that. */
		if (Place == PL_UNKNOWN) {
			Place = PL_BELOW;
		}
		/* copies of the lyrics info has been made for all staffs/verses
		 * at this point, so get rid of master copy */
		free_grpsyls(Lyrics_p);
	;}
    break;

  case 505:
#line 4873 "gram.y"
    {
		/* empty -- need to derive times from music */
		Lyrics_p = derive_lyrtime();
	;}
    break;

  case 506:
#line 4880 "gram.y"
    {
		not_derived();
	;}
    break;

  case 510:
#line 4895 "gram.y"
    {
		link_notegroup(Curr_grpsyl_p, Last_grpsyl_p);
		/* Save pointer to current GRPSYL in case the next
		 * group gets its time value based on this one,
		 * and there are additive times on this one. */
		Prev_grpsyl_p = Curr_grpsyl_p;
		/* If there are additive times, add those in.
		 * We don't need to make extra groups for lyrics, because we
		 * don't need to tie groups together--the lyrics time
		 * can hold any legal RATIONAL, even those that aren't
		 * specifiable with a single time value. */
		if (Extra_time_p != 0) {
			struct TIMELIST *timelist_p;
			for (timelist_p = Extra_time_p; timelist_p != 0;
						timelist_p = timelist_p->next) {
				Curr_grpsyl_p->fulltime = radd(Curr_grpsyl_p->fulltime, timelist_p->fulltime);
			}
		}
	;}
    break;

  case 511:
#line 4917 "gram.y"
    {
	;}
    break;

  case 512:
#line 4921 "gram.y"
    {
		end_tuplet((yyvsp[(4) - (5)].intval), (yyvsp[(5) - (5)].ratval), NO, PL_UNKNOWN);
		Getting_tup_dur = NO;
	;}
    break;

  case 513:
#line 4927 "gram.y"
    {
		/* empty, will fill in an actual syllable later */
		Curr_grpsyl_p->syl = (char *) 0;
	;}
    break;

  case 514:
#line 4934 "gram.y"
    {
		/* space, not a lyric, so mark for later use */
		Curr_grpsyl_p->grpcont = GC_SPACE;
	;}
    break;

  case 517:
#line 4947 "gram.y"
    {
		/* If no [verseno] is specified, use -1 as special flag
		 * to be resolved later to "one more than previous",
		 * or if there wasn't a previous, to verse 1.
		 */
		lyr_verse(-1, -1);
		proc_lyrics(Lyrics_p, (yyvsp[(1) - (2)].stringval));
	;}
    break;

  case 518:
#line 4958 "gram.y"
    {
		proc_lyrics(Lyrics_p, (yyvsp[(4) - (5)].stringval));
	;}
    break;

  case 519:
#line 4963 "gram.y"
    {
		/* If user set measnum=every N and did not already put some
		 * kind of reh mark on this bar, and this measure is a
		 * multiple of N, we add a mnum mark,
		 * but using measnumstyle */
		if (Currstruct_p != 0 && IS_EVERY(Score.measnum) &&
				Currstruct_p->u.bar_p->reh_type == REH_NONE &&
				Meas_num % Score.measnum == 0) {
			Currstruct_p->u.bar_p->reh_type = REH_BAR_MNUM;
			/* Do like the code in set_reh_string() except use the
			 * measnum* parameters for family, font, and size. */
			Currstruct_p->u.bar_p->reh_string =
					copy_string(num2str(Meas_num) + 2,
                        		Score.measnumfamily + Score.measnumfont,
                        		Score.measnumsize);
		}

		Currstruct_p = (struct MAINLL *) 0;
		/* If there are alternating time signature,
		 * add an implicit time signature SSV for the
		 * next time signature in the list.
		 */
		if (Alt_timesig_list != 0) {
			end_prev_context();
			Context = C_SCORE;
			Currstruct_p = newMAINLLstruct(S_SSV, -1);
			Currstruct_p->u.ssv_p->context = Context;
			if (Tsig_visibility == PTS_ALWAYS &&
					Next_alt_timesig != Alt_timesig_list) {
				/* If user wants alternating time signatures
				 * printed on every measure, if there is
				 * a multirest, we will print multiple
				 * time signatures there, and might have to
				 * wrap around to the beginning of the list.
				 * So make a copy of the entire list,
				 * starting from wherever we are now,
				 * wrapping around to the beginning,
				 * and ending just before where we are now.
				 * Most of the time,
				 * there probably won't be a multirest,
				 * so this will be a waste, but unfortunately,
				 * we don't know yet whether there will be
				 * one or not, so need to do the whole list
				 * just in case.
				 *
				 * Calculate length of the two pieces:
				 * from where we are to end, and from
				 * beginning to where we are.
				 */
				int remlength;
				int wraplength;
				remlength = strlen(Next_alt_timesig);
				wraplength = strlen(Alt_timesig_list)
						- remlength;
				/* need one more for terminator. */
				MALLOCA(char, Currstruct_p->u.ssv_p->timerep,
						remlength + wraplength + 1);

				/* copy remainder into beginning */
				strcpy(Currstruct_p->u.ssv_p->timerep,
						Next_alt_timesig);
				/* copy the wrap-around part of list,
				 * but move the TSR_ALTERNATING from the
				 * end of that part to between the two parts */
				Currstruct_p->u.ssv_p->timerep[remlength]
						= TSR_ALTERNATING;
				strncpy(Currstruct_p->u.ssv_p->timerep +
						remlength + 1, Alt_timesig_list,
						wraplength - 1);
				/* Add the terminator */
				Currstruct_p->u.ssv_p->timerep
						[remlength + wraplength]
						= TSR_END;

				assign_timesig(Currstruct_p, PTS_ALWAYS,
							&Next_alt_timesig);


				/* Make this new copy the new
				 * head of the list */
				Alt_timesig_list =
						Currstruct_p->u.ssv_p->timerep;
			}
			else {
				/* make a copy of the remaining alternating
				 * signatures and assign that */
				MALLOCA(char, Currstruct_p->u.ssv_p->timerep,
					strlen(Next_alt_timesig) + 1);
				strcpy(Currstruct_p->u.ssv_p->timerep,
							Next_alt_timesig);
				assign_timesig(Currstruct_p,
					(Tsig_visibility == PTS_ALWAYS ?
					PTS_ALWAYS : PTS_NEVER),
					&Next_alt_timesig);

				/* If we reached end of list, start over */
				if (Next_alt_timesig == 0) {
					Next_alt_timesig = Alt_timesig_list;
				}
			}

			asgnssv(Currstruct_p->u.ssv_p);
			end_prev_context();
			Context = C_MUSIC;
		}
	;}
    break;

  case 522:
#line 5078 "gram.y"
    {
		struct MAINLL * mll_p;
		char *name;


		name = (yylval.intval == YES ? "newpage" : "newscore");

		(void) contextcheck(C_MUSIC | C_BLOCK, name);
		Currstruct_p = newMAINLLstruct(S_FEED, yylineno);
		Currstruct_p->u.feed_p->pagefeed = (yyvsp[(1) - (1)].intval);

		/* make sure we're not in the middle of a measure. Go
		 * backwards in main list. If we hit STAFF before a BAR,
		 * then there is a problem.
		 */
		for (mll_p = Mainlltc_p; mll_p != (struct MAINLL *) 0;
					mll_p = mll_p->prev) {

			if (mll_p->str == S_BAR) {
				break;
			}
			else if (mll_p->str == S_STAFF) {
				l_yyerror(Curr_filename, yylineno,
					"%s not allowed in middle of measure",
					name);
				break;
			}
			else if (mll_p->str == S_FEED) {
				struct MAINLL *m_p;
				/* Need to look backwards for blocks, but need
				 * to ignore any SSVs that are in between */
				for (m_p = mll_p->prev;
						m_p != 0 && m_p->str == S_SSV;
						m_p = m_p->prev) {
					;
				}
				if (m_p != 0 && m_p->str == S_BLOCKHEAD) {
					/* This is a feed following a block.
					 * If it was an implicit feed,
					 * we can get rid of it, because
					 * user now put an explicit one.
					 */
					if (mll_p->inputlineno == -1) {
						unlinkMAINLL(mll_p);
						FREE(mll_p);
					}
					/* We must be in block context,
					 * so no need to check farther back.
					 */
					break;
				}
				else {
					l_yyerror(Curr_filename, yylineno,
						"consecutive newscore/newpage not allowed");
				}
				break;
			}
		}
		insertMAINLL(Currstruct_p, Mainlltc_p);

		/* If this is inside a block, we need to create a new block
		 * and feed after it.
		 */
		if (Context == C_BLOCK) {
			CALLOC(BLOCKHEAD, Currblock_p, 1);
			set_win_coord(Currblock_p->c);
			Next_print_link_p_p = &(Currblock_p->printdata_p);
			insertMAINLL(newMAINLLstruct(S_BLOCKHEAD, yylineno),
						Mainlltc_p);
			Mainlltc_p->u.blockhead_p = Currblock_p;
			insertMAINLL(newMAINLLstruct(S_FEED, -1), Mainlltc_p);
		}

	;}
    break;

  case 523:
#line 5153 "gram.y"
    {
		Currstruct_p = (struct MAINLL *) 0;
	;}
    break;

  case 527:
#line 5169 "gram.y"
    {
		if ((yyvsp[(3) - (3)].floatval) > 0.0) {
			(yyvsp[(3) - (3)].floatval) = adjust2inches((yyvsp[(3) - (3)].floatval));	/* in case we are in centimeter mode */
		}
		if ((yyvsp[(1) - (3)].intval) == RIGHTMARGIN) {
			if (Currstruct_p->u.feed_p->rightmargin >= 0) {
				l_warning(Curr_filename, yylineno,
					"rightmargin specified more than once, using last instance");
				/* fall through to override the previous */
			}
			Currstruct_p->u.feed_p->rightmargin = (yyvsp[(3) - (3)].floatval);
		}
		else if ((yyvsp[(1) - (3)].intval) == LEFTMARGIN) {
			if (Currstruct_p->u.feed_p->leftmargin >= 0) {
				l_warning(Curr_filename, yylineno,
					"leftmargin specified more than once, using last instance");
				/* fall through to override the previous */
			}
			if ((yyvsp[(3) - (3)].floatval) == MG_AUTO) {
				l_warning(Curr_filename, yylineno,
					"auto can only be used with rightmargin, not leftmargin; ignoring");
				(yyvsp[(3) - (3)].floatval) = MG_DEFAULT;
			}
			Currstruct_p->u.feed_p->leftmargin = (yyvsp[(3) - (3)].floatval);
		}
		else {
			yyerror("unexpected parameter; only 'leftmargin' or 'rightmargin' allowed here");
		}
		chkmargin(Score.topmargin, Score.botmargin,
				Currstruct_p->u.feed_p->leftmargin,
				Currstruct_p->u.feed_p->rightmargin);
	;}
    break;

  case 528:
#line 5204 "gram.y"
    {
		if ((yyvsp[(1) - (1)].floatval) < 0.0) {
			/* Actually, the floatnum lexing is such that this
			 * should be impossible... */
			yyerror("margin override cannot be negative; ignoring");
			(yyval.floatval) = MG_DEFAULT;
		}
		else {
			(yyval.floatval) = (yyvsp[(1) - (1)].floatval);
		}
	;}
    break;

  case 529:
#line 5218 "gram.y"
    {
		(yyval.floatval) = MG_AUTO;
	;}
    break;

  case 536:
#line 5242 "gram.y"
    {

		/* build a BAR struct and add it to the main list */
		if (contextcheck(C_MUSIC, "bar") == YES) {

			Currstruct_p = add_bar((yyvsp[(3) - (3)].intval), (yyvsp[(1) - (3)].intval), Endingloc, Mainlltc_p);
			Got_ending = NO;
		}
		if ((yyvsp[(3) - (3)].intval) == RESTART && Endingloc != NOITEM) {
			yyerror("restart cannot be used inside an ending");
		}

		/* User can specify bar type to use on preceeding staff when
		 * a repeatstart gets moved to the next scores's pseudo-bar */
		if ((yyvsp[(2) - (3)].intval) != -1) {
			if ((yyvsp[(3) - (3)].intval) != REPEATSTART) {
				l_warning(Curr_filename, yylineno,
					"bar type for preceeding score only allowed on repeatstart; ignoring");
			}
			else if (Currstruct_p != 0 && Currstruct_p->u.bar_p != 0) {
				Currstruct_p->u.bar_p->precbartype = (yyvsp[(2) - (3)].intval);
				if ((yyvsp[(2) - (3)].intval) != SINGLEBAR && (yyvsp[(2) - (3)].intval) != DOUBLEBAR &&
						(Linetype == L_DASHED ||
						Linetype == L_DOTTED)) {
					l_warning(Curr_filename, yylineno,
						"dashed/dotted only allowed on bar or dblbar; ignoring");
					Linetype = L_NORMAL;
				}
				Currstruct_p->u.bar_p->linetype = Linetype;
			}
		}
		else {
			/* Default is single bar. It could be argued that in
			 * the case of a key change on this bar, it really
		 	 * should be a dblbar, but user can force that
			 * if they want it. */
			if (Currstruct_p != 0 && Currstruct_p->u.bar_p != 0) {
				Currstruct_p->u.bar_p->precbartype = SINGLEBAR;
			}
		}
		/* Placement phase indirectly uses Doing_tab_staff when it
		 * calls notecomp, so clear it in case we don't get a
		 * non-tab staff input before the end of file.
		 * We could probably get by just doing after parsing is done,
		 * but this seems cleaner, and cheap enough.
		 */
		Doing_tab_staff = NO;
	;}
    break;

  case 537:
#line 5293 "gram.y"
    {
		(yyval.intval) = -1;	/* special value to mean "none specified" */
		Linetype = L_NORMAL;
	;}
    break;

  case 538:
#line 5300 "gram.y"
    {
		/* Parens wouldn't be strictly necessary to be able to parse,
		 * but seem useful semantically to make it clear this is
		 * optional, only applying when repeatstart is moved to
		 * next score's pseudo bar. */
		(yyval.intval) = (yyvsp[(3) - (4)].intval);
		if ((yyvsp[(2) - (4)].intval) == L_DOTTED || (yyvsp[(2) - (4)].intval) == L_DASHED) {
			if ((yyvsp[(3) - (4)].intval) != SINGLEBAR && (yyvsp[(3) - (4)].intval) != DOUBLEBAR) {
				l_warning(Curr_filename, yylineno,
					"Only bar or dblbar can be dashed or dotted; ignoring");
			}
			else {
				Linetype = (yyvsp[(2) - (4)].intval);
			}
		}
		else if ((yyvsp[(2) - (4)].intval) != L_NORMAL) {
			l_warning(Curr_filename, yylineno,
					"Bar line type modifier can only can be dashed or dotted; ignoring");
		}
	;}
    break;

  case 539:
#line 5322 "gram.y"
    {
		/* Call proc_emptymeas() to free up the last buffer, if any,
		 * and return back to normal input stream. */
		proc_emptymeas(MAXSTAFFS+1);
		(yyval.intval) = (yyvsp[(1) - (2)].intval);
	;}
    break;

  case 540:
#line 5330 "gram.y"
    {
		/* If there was any empty voices in the input for this
		 * measure which have emptymeas parameter set,
		 * proc_emptymeas() will arrange to create just-in-time
		 * virtual input for it that will get parsed via
		 * the emptymeas_input rule.
		 * We pass arg of 1 to tell it to start looking from
		 * staff 1. Subsequent calls to proc_emptymeas(), if any,
		 * will generate input for additional voices, until
		 * no more are needed for this measure.
		 */
		if ((yyvsp[(1) - (1)].intval) != RESTART) {
			EM_staff = proc_emptymeas(1);
		}
		else {
			/* don't create any music before a restart */
			EM_staff = MAXSTAFFS + 1;
		}
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 541:
#line 5352 "gram.y"
    {
	;}
    break;

  case 542:
#line 5357 "gram.y"
    {
		/* See if there is any more virtual input needed */
		EM_staff = proc_emptymeas(EM_staff);
	;}
    break;

  case 545:
#line 5370 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			Currstruct_p->u.bar_p->padding += (yyvsp[(1) - (1)].floatval) * STEPSIZE;
		}
	;}
    break;

  case 546:
#line 5378 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			/* fill in location info */
			if ((yyvsp[(2) - (2)].stringval) != (char *) 0) {
				addsym((yyvsp[(2) - (2)].stringval), Currstruct_p->u.bar_p->c, CT_BAR);
			}
		}
	;}
    break;

  case 547:
#line 5389 "gram.y"
    {
		if (Got_ending == YES) {
			yyerror("Only one ending allowed per bar");
		}
		Got_ending = YES;

		if (Currstruct_p != (struct MAINLL *) 0) {
			if (Currstruct_p->u.bar_p->bartype == RESTART) {
				yyerror("ending not allowed on restart");
			}
			/* fill in ending label if any */
			Currstruct_p->u.bar_p->endinglabel = (yyvsp[(1) - (1)].stringval);
			Currstruct_p->u.bar_p->endingloc = Endingloc;
			ped_endings(Endingloc);

			/* for next time around, figure out what endingloc will
			 * be if user doesn't specify something different */
			switch (Endingloc) {
			case STARTITEM:
				Endingloc = INITEM;
				break;
			case ENDITEM:
				Endingloc = NOITEM;
				break;
			default:
				break;
			}
		}
	;}
    break;

  case 548:
#line 5421 "gram.y"
    {
		if (Currstruct_p != 0) {
			if (Currstruct_p->u.bar_p->bartype == RESTART) {
				l_warning(Curr_filename, yylineno,
					"hidechanges not allowed on restart; ignoring");
			}
			else {
				Currstruct_p->u.bar_p->hidechanges = YES;
			}
		}
	;}
    break;

  case 549:
#line 5434 "gram.y"
    {
		if (Currstruct_p != 0) {
			set_mnum(Currstruct_p->u.bar_p, (yyvsp[(3) - (3)].intval));
		}
	;}
    break;

  case 550:
#line 5441 "gram.y"
    {
		/* +2 to skip font/size */
		init_reh(-1, (yyvsp[(3) - (3)].stringval) + 2, Currstruct_p);
	;}
    break;

  case 551:
#line 5447 "gram.y"
    {
		init_reh((yyvsp[(3) - (3)].intval), (char *)0, Currstruct_p);
	;}
    break;

  case 552:
#line 5453 "gram.y"
    {
		if (Currstruct_p != 0 && Currstruct_p->str == S_BAR) {
			if (Currstruct_p->u.bar_p->reh_string != 0) {
				/* This indicates user specified multiple
				 * rehearsal strings. We would have already
				 * given a warning message. */
				FREE(Currstruct_p->u.bar_p->reh_string);
				Currstruct_p->u.bar_p->reh_string = 0;
			}
			set_reh_string(Currstruct_p->u.bar_p, (yyvsp[(3) - (7)].intval), (yyvsp[(4) - (7)].intval), (yyvsp[(5) - (7)].intval), (yyvsp[(6) - (7)].stringval));
			Currstruct_p->u.bar_p->dist = Dist;
			Currstruct_p->u.bar_p->dist_usage = Dist_usage;
		}
	;}
    break;

  case 553:
#line 5470 "gram.y"
    {
		(yyval.stringval) = (yyvsp[(2) - (2)].stringval);
		(void) fix_string((yyvsp[(2) - (2)].stringval), FONT_TR, DFLT_SIZE, Curr_filename, yylineno);
		Endingloc = STARTITEM;
	;}
    break;

  case 554:
#line 5478 "gram.y"
    {
		if (Endingloc == NOITEM) {
			l_warning(Curr_filename, yylineno,
				"no ending in progress; extraneous 'endending' ignored");
		}
		else {
			Endingloc = ENDITEM;
		}
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 555:
#line 5490 "gram.y"
    {
		/* null token to check for more than one rehearsal mark
		 * on one BAR */
		if (Currstruct_p != (struct MAINLL *) 0 &&
				Currstruct_p->u.bar_p->reh_type != REH_NONE) {
			l_warning(Curr_filename, yylineno,
				"only one rehearsal mark allowed per bar; using last");
		}
	;}
    break;

  case 556:
#line 5501 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			Currstruct_p->u.bar_p->reh_type = REH_STRING;
		}
	;}
    break;

  case 557:
#line 5509 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			Currstruct_p->u.bar_p->reh_type = REH_MNUM;
		}
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 558:
#line 5518 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			Currstruct_p->u.bar_p->reh_type = REH_NUM;
		}
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 559:
#line 5527 "gram.y"
    {
		if (Currstruct_p != (struct MAINLL *) 0) {
			Currstruct_p->u.bar_p->reh_type = REH_LET;
		}
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 560:
#line 5535 "gram.y"
    {
		(yyval.inpcoord_p) = (yyvsp[(2) - (6)].inpcoord_p);
		(yyvsp[(2) - (6)].inpcoord_p)->hexpr_p = (yyvsp[(3) - (6)].expr_p);
		(yyvsp[(2) - (6)].inpcoord_p)->vexpr_p = (yyvsp[(5) - (6)].expr_p);
	;}
    break;

  case 561:
#line 5542 "gram.y"
    {
		/* null token to allocate an INPCOORD */
		CALLOC(INPCOORD, Curr_loc_info_p, 1);
		(yyval.inpcoord_p) = Curr_loc_info_p;
		/* set to positive in case input starts with an absolute
		 * x coordinate */
		Plus_minus = 1;
	;}
    break;

  case 562:
#line 5552 "gram.y"
    {
		(yyval.intval) = Plus_minus = 1;
	;}
    break;

  case 563:
#line 5558 "gram.y"
    {
		(yyval.intval) = Plus_minus = -1;
	;}
    break;

  case 564:
#line 5565 "gram.y"
    {
		(yyval.expr_p) = (yyvsp[(2) - (2)].expr_p);
		Curr_timeref_tag_p = 0;
	;}
    break;

  case 565:
#line 5573 "gram.y"
    {
		(yyval.expr_p) = (yyvsp[(1) - (1)].expr_p);

		/* Put lex back into normal (not coord arithemetic) mode */
		set_lex_mode(NO);
	;}
    break;

  case 566:
#line 5582 "gram.y"
    {
		/* Put lex into special mode to return different tokens
		 * for arithmetic operators. This is just in case the
		 * precedence rules might mess up other rules if we used
		 * the same tokens. The + - * / symbols are used for very
		 * different things elsewhere in the grammer, where
		 * precedence doesn't make sense. It probably wouldn't hurt,
		 * but it seems better to be safe, and only do the precedence
		 * when really needed.
		 */
		set_lex_mode(YES);
		Curr_timeref_tag_p = 0;
	;}
    break;

  case 567:
#line 5600 "gram.y"
    {
		(yyval.expr_p) = (yyvsp[(2) - (3)].expr_p);
	;}
    break;

  case 568:
#line 5606 "gram.y"
    {
		(yyval.expr_p) = newnode((yyvsp[(2) - (3)].intval));
		(yyval.expr_p)->left.lchild_p = (yyvsp[(1) - (3)].expr_p);
		(yyval.expr_p)->right.rchild_p = (yyvsp[(3) - (3)].expr_p);
	;}
    break;

  case 569:
#line 5614 "gram.y"
    {
		(yyval.expr_p) = newnode((yyvsp[(2) - (3)].intval));
		(yyval.expr_p)->left.lchild_p = (yyvsp[(1) - (3)].expr_p);
		(yyval.expr_p)->right.rchild_p = (yyvsp[(3) - (3)].expr_p);
	;}
    break;

  case 570:
#line 5622 "gram.y"
    {
		(yyval.expr_p) = newnode((yyvsp[(1) - (4)].intval));
		(yyval.expr_p)->left.lchild_p = (yyvsp[(3) - (4)].expr_p);
	;}
    break;

  case 571:
#line 5630 "gram.y"
    {
		(yyval.expr_p) = newnode((yyvsp[(1) - (6)].intval));
		(yyval.expr_p)->left.lchild_p = (yyvsp[(3) - (6)].expr_p);
		(yyval.expr_p)->right.rchild_p = (yyvsp[(5) - (6)].expr_p);
	;}
    break;

  case 572:
#line 5638 "gram.y"
    {
		(yyval.expr_p) = newnode(OP_FLOAT_LITERAL);
		(yyval.expr_p)->left.value = (yyvsp[(1) - (1)].floatval);
	;}
    break;

  case 573:
#line 5645 "gram.y"
    {
		(yyval.expr_p) = newnode(OP_TAG_REF);

		/* Get space to save info about this tag reference */
		MALLOC(TAG_REF, (yyval.expr_p)->left.ltag_p, 1);

		/* Get the address of the c[] associated with this tag.
		 * We also save which index into the c[]
		 */
		if (((yyval.expr_p)->left.ltag_p->c = symval((yyvsp[(1) - (3)].stringval), &((yyval.expr_p)->left.ltag_p->c))) == 0) {
			l_yyerror(Curr_filename, yylineno,
				"unable to find tag %s\n", (yyvsp[(1) - (3)].stringval));
		}
		else {
			(yyval.expr_p)->left.ltag_p->c_index = (yyvsp[(3) - (3)].intval);
			save_tag_ref((yyval.expr_p)->left.ltag_p->c, &((yyval.expr_p)->left.ltag_p->c));
		}

		if (index_type((yyvsp[(3) - (3)].intval)) == AX) {
			/* Remember this tag, in case user
			 * wants to do a time offset relative to it.
			 * We always take time offsets relative
			 * to the most recent horizontal tag
			 * in the current expression.
			 * Since there may be expressions as arguments
			 * to functions, we keep a stack of these. */
			Curr_timeref_tag_p = (yyval.expr_p)->left.ltag_p;
		}

		/* If this is the first tag of the proper direction in the
		 * expression, that's the base tag used to determine
		 * which staff/score the tag is associated with, if any */
		if (index_type((yyvsp[(3) - (3)].intval)) == AX && Curr_loc_info_p->hor_p == 0) {
			Curr_loc_info_p->hor_p = (yyval.expr_p)->left.ltag_p->c;
			save_tag_ref(Curr_loc_info_p->hor_p,
						&(Curr_loc_info_p->hor_p));
		}
		else if (index_type((yyvsp[(3) - (3)].intval)) == AY && Curr_loc_info_p->vert_p == 0) {
			Curr_loc_info_p->vert_p = (yyval.expr_p)->left.ltag_p->c;
			save_tag_ref(Curr_loc_info_p->vert_p,
						&(Curr_loc_info_p->vert_p));
		}
	;}
    break;

  case 574:
#line 5691 "gram.y"
    {
		if (Curr_timeref_tag_p == 0) {
			yyerror("time offset require a prior horizontal tag reference");
			(yyval.expr_p) = 0;
		}
		else if (is_builtin_tag(Curr_timeref_tag_p->c)) {
			yyerror("cannot have a time offset relative to a builtin tag like _win or _page");
			(yyval.expr_p) = 0;
		}
		else {
			(yyval.expr_p) = newnode(OP_TIME_OFFSET);
			(yyval.expr_p)->left.value = (yyvsp[(2) - (2)].floatval);
			MALLOC(TAG_REF, (yyval.expr_p)->right.rtag_p, 1);
			(yyval.expr_p)->right.rtag_p = Curr_timeref_tag_p;
			save_tag_ref((yyval.expr_p)->right.rtag_p->c,
						&((yyval.expr_p)->right.rtag_p->c));
		}
	;}
    break;

  case 575:
#line 5713 "gram.y"
    {
		/* only valid letters are w and y */
		if (*yytext == 'w') {
			(yyval.intval) = AW;
		}
		else if (*yytext == 'y') {
			(yyval.intval) = AY;
		}
		else {
			yyerror("invalid direction: must be x, y, e, w, n or s");
			/* Return something valid, so if any code tries
			 * to use it later, it won't core dump */
			(yyval.intval) = AX;
		}
	;}
    break;

  case 576:
#line 5730 "gram.y"
    {
		(yyval.intval) = AX;
	;}
    break;

  case 577:
#line 5736 "gram.y"
    {
		/* only valid value is e */
		if (*yytext != 'e') {
			yyerror("invalid direction: must be x, y, e, w, n or s");
		}
		(yyval.intval) = AE;
	;}
    break;

  case 578:
#line 5746 "gram.y"
    {
		(yyval.intval) = AN;
	;}
    break;

  case 579:
#line 5752 "gram.y"
    {
		(yyval.intval) = AS;
	;}
    break;

  case 580:
#line 5758 "gram.y"
    {
		(yyval.floatval) = (float) (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 581:
#line 5763 "gram.y"
    {
		sprintf(Tmpbuff,"%d.%s", (yyvsp[(1) - (3)].intval), (yyvsp[(3) - (3)].stringval));
		(yyval.floatval) = (float) atof(Tmpbuff);
	;}
    break;

  case 582:
#line 5769 "gram.y"
    {
		sprintf(Tmpbuff,"0.%s", (yyvsp[(2) - (2)].stringval));
		(yyval.floatval) = (float) atof(Tmpbuff);
	;}
    break;

  case 583:
#line 5775 "gram.y"
    {
		/* no decimal fraction part of float number */
		(yyval.stringval) = "";
	;}
    break;

  case 585:
#line 5785 "gram.y"
    {
		(yyval.stringval) = yytext;
	;}
    break;

  case 587:
#line 5793 "gram.y"
    {
		Currstruct_p->u.line_p->linetype = (yyvsp[(1) - (7)].intval);
		Currstruct_p->u.line_p->start = *((yyvsp[(4) - (7)].inpcoord_p));
		Currstruct_p->u.line_p->end = *((yyvsp[(6) - (7)].inpcoord_p));
		rep_inpcoord((yyvsp[(4) - (7)].inpcoord_p), &(Currstruct_p->u.line_p->start));
		rep_inpcoord((yyvsp[(6) - (7)].inpcoord_p), &(Currstruct_p->u.line_p->end));
		Currstruct_p->u.line_p->string = (yyvsp[(7) - (7)].stringval);

		/* copies of the location info went into the LINE struct,
		 * so we can free the original copy of the information */
		if ((yyvsp[(4) - (7)].inpcoord_p)) {
			FREE((yyvsp[(4) - (7)].inpcoord_p));
		}
		if ((yyvsp[(6) - (7)].inpcoord_p)) {
			FREE((yyvsp[(6) - (7)].inpcoord_p));
		}
		insertMAINLL(Currstruct_p, Mainlltc_p);
		Currstruct_p = (struct MAINLL *) 0;
	;}
    break;

  case 588:
#line 5814 "gram.y"
    {
		/* null token to cause allocation of LINE struct */
		(void) contextcheck(C_MUSIC, "line");
		Currstruct_p = newMAINLLstruct(S_LINE, yylineno);
	;}
    break;

  case 589:
#line 5821 "gram.y"
    {
		(yyval.intval) = L_NORMAL;
	;}
    break;

  case 591:
#line 5831 "gram.y"
    {
		(yyval.stringval) = 0;
	;}
    break;

  case 592:
#line 5836 "gram.y"
    {
		(yyval.stringval) = fix_string((yyvsp[(4) - (4)].stringval), Titlefont, Titlesize, Curr_filename, yylineno);
	;}
    break;

  case 593:
#line 5842 "gram.y"
    {
		if ((yyvsp[(1) - (7)].intval) == L_WAVY) {
			l_warning(Curr_filename, yylineno,
						"wavy curve not allowed; using normal curve");
			(yyvsp[(1) - (7)].intval) = L_NORMAL;
		}
		Currstruct_p->u.curve_p->curvetype = (yyvsp[(1) - (7)].intval);
		insertMAINLL(Currstruct_p, Mainlltc_p);
		Currstruct_p = (struct MAINLL *) 0;
	;}
    break;

  case 594:
#line 5854 "gram.y"
    {
		(void) contextcheck(C_MUSIC, "curve");
		Currstruct_p = newMAINLLstruct(S_CURVE, yylineno);

		/* get space for a list of locations and mark it as empty */
		Item_count = 0;
		Currstruct_p->u.curve_p->ncoord = (short) Item_count;
		Currstruct_p->u.curve_p->nbulge = (short) Item_count;
		MALLOC(INPCOORD, Currstruct_p->u.curve_p->coordlist, ITEMS);
		Max_items = ITEMS;
	;}
    break;

  case 601:
#line 5888 "gram.y"
    {
		/* get enough space to store some values if don't have enough */
		if (Currstruct_p->u.curve_p->nbulge == 0) {
			MALLOCA(float, Currstruct_p->u.curve_p->bulgelist, ITEMS);
		}
		else if ( (Currstruct_p->u.curve_p->nbulge % ITEMS) == 0) {
			REALLOCA(float, Currstruct_p->u.curve_p->bulgelist,
				Currstruct_p->u.curve_p->nbulge + ITEMS);
		}

		/* fill in the value and increment the count of how many */
		Currstruct_p->u.curve_p->bulgelist[Currstruct_p->u.curve_p->nbulge] = (yyvsp[(1) - (2)].intval) * (yyvsp[(2) - (2)].floatval);
		(Currstruct_p->u.curve_p->nbulge)++;
	;}
    break;

  case 602:
#line 5904 "gram.y"
    {
		struct INPCOORD *curve_inpcoord_p;

		/* If ran off end of list, make list bigger.
		 * We cannot use REALLOC here, since we need to update
		 * the tag reference information on each individual array
		 * element, so we alloc all new space, copy the existing data,
		 * and update the tag references, then free the old space,
		 * and redirect the pointer to the new space. */
		if (Currstruct_p->u.curve_p->ncoord >= Max_items) {
			struct INPCOORD *newlist_p;
			int n;
			Max_items += ITEMS;
			MALLOC(INPCOORD, newlist_p, Max_items);
			for (n = 0; n < Currstruct_p->u.curve_p->ncoord; n++) {
				newlist_p[n] = Currstruct_p->u.curve_p->coordlist[n];
				rep_inpcoord(
				    &(Currstruct_p->u.curve_p->coordlist[n]),
				    &(newlist_p[n]));
			}
			FREE(Currstruct_p->u.curve_p->coordlist);
			Currstruct_p->u.curve_p->coordlist = newlist_p;
		}

		/* Add this entry to the end of the list, update the
		 * tag reference to point to this permanent copy rather
		 * the temporary one we will be deleting, and update the
		 * count of how many elements in the list. */
		curve_inpcoord_p = &(Currstruct_p->u.curve_p->coordlist
					[Currstruct_p->u.curve_p->ncoord]);
		*curve_inpcoord_p = *((yyvsp[(1) - (1)].inpcoord_p));
		rep_inpcoord((yyvsp[(1) - (1)].inpcoord_p), curve_inpcoord_p);
		(Currstruct_p->u.curve_p->ncoord)++;
		FREE((yyvsp[(1) - (1)].inpcoord_p));
	;}
    break;

  case 603:
#line 5941 "gram.y"
    {
		attach_stuff();
		/* so reset flag */
		Defining_multiple = NO;
	;}
    break;

  case 604:
#line 5949 "gram.y"
    {
		chk_stuff_header((yyvsp[(2) - (7)].intval), (yyvsp[(3) - (7)].intval), (yyvsp[(4) - (7)].intval), Dist_usage);
		add_to_sv_list();
	;}
    break;

  case 605:
#line 5956 "gram.y"
    {
		/* Separate rule for phrase because it has the linetype
		 * modifier in front, unlike any other STUFF. The size,
		 * and dist are not really allowed, but we match them
		 * if they are there in order to give more clear error
		 * message than just "syntax error," since there was
		 * already code elsewhere to check for these errors.
		 */
		set_stuff_type(ST_PHRASE);
		chk_stuff_header((yyvsp[(3) - (6)].intval), (yyvsp[(1) - (6)].intval), (yyvsp[(4) - (6)].intval), Dist_usage);
		add_to_sv_list();
		Aligntag = NOALIGNTAG;
	;}
    break;

  case 606:
#line 5971 "gram.y"
    {
		/* need a separate rule for midi, because it can include
		 * a voice as well as staff. It also cannot have the chord,
		 * size or place, although those are checked elsewhere anyway */
		chk_stuff_header(-1, NO, PL_UNKNOWN, SD_NONE);
		Aligntag = NOALIGNTAG;
	;}
    break;

  case 607:
#line 5981 "gram.y"
    {
		set_stuff_type(ST_MIDI);
		begin_range(PL_UNKNOWN);
	;}
    break;

  case 609:
#line 5991 "gram.y"
    {
		all();
		add_to_sv_list();
	;}
    break;

  case 610:
#line 5998 "gram.y"
    {
		/* dummy token for sole purpose of saving away current
		 * stuff type. We have to do this in order to have it in
		 * time to figure out the default place for "all" */
		set_stuff_type((yyvsp[(1) - (1)].intval));
	;}
    break;

  case 611:
#line 6007 "gram.y"
    {
		Curr_family = (yyvsp[(1) - (2)].intval);

		switch ((yyvsp[(2) - (2)].intval)) {
		case FONT_TR:
			(yyval.intval) = ST_ROM;
			break;
		case FONT_TI:
			(yyval.intval) = ST_ITAL;
			break;
		case FONT_TB:
			(yyval.intval) = ST_BOLD;
			break;
		case FONT_TX:
			(yyval.intval) = ST_BOLDITAL;
			break;
		default:
			pfatal("unknown font");
			break;
		}
	;}
    break;

  case 612:
#line 6031 "gram.y"
    {
		if ((yyvsp[(1) - (1)].intval) != L_NORMAL) {
			/* user used 'dotted' or 'dashed' which applies only
			 * to use of T_L_ANGLE for slurs. Use generic error
			 * message so looks like any other similar error. */
			yyerror("syntax error");
		}
		(yyval.intval) = ST_CRESC;
	;}
    break;

  case 613:
#line 6043 "gram.y"
    {
		(yyval.intval) = ST_DECRESC;
	;}
    break;

  case 614:
#line 6049 "gram.y"
    {
		(yyval.intval) = ST_PEDAL;
	;}
    break;

  case 615:
#line 6055 "gram.y"
    {
		(yyval.intval) = ST_MUSSYM;
	;}
    break;

  case 616:
#line 6061 "gram.y"
    {
		(yyval.intval) = ST_OCTAVE;
	;}
    break;

  case 617:
#line 6067 "gram.y"
    {
		/* use -1 to indicate user didn't specify so must use default */
		(yyval.intval) = -1;
	;}
    break;

  case 618:
#line 6074 "gram.y"
    {
		(yyval.intval) = (yyvsp[(2) - (3)].intval);
	;}
    break;

  case 619:
#line 6079 "gram.y"
    {
		(yyval.intval) = TM_NONE;
	;}
    break;

  case 620:
#line 6085 "gram.y"
    {
		(yyval.intval) = (yyvsp[(1) - (1)].intval);
	;}
    break;

  case 621:
#line 6090 "gram.y"
    {
		Dist = 0.0;
		Dist_usage = SD_NONE;
	;}
    break;

  case 622:
#line 6097 "gram.y"
    {
		if ((yyvsp[(1) - (2)].intval) != DIST) {
			yyerror("unexpected parameter name instead of 'dist'");
		}
		else {
			if (frangecheck((yyvsp[(2) - (2)].floatval), -MAXDIST, MAXDIST, "dist") == YES) {
				Dist = (yyvsp[(2) - (2)].floatval);
			}
		}
	;}
    break;

  case 623:
#line 6110 "gram.y"
    {
		(yyval.floatval) = (yyvsp[(1) - (2)].floatval);
	;}
    break;

  case 624:
#line 6116 "gram.y"
    {
		if (Dist_usage != SD_FORCE) {
			l_warning(Curr_filename, yylineno,
				"negative dist requires !, setting to 0");
			(yyval.floatval) = 0.0;
		}
		else {
			(yyval.floatval) = - (yyvsp[(2) - (3)].floatval);
		}
	;}
    break;

  case 625:
#line 6128 "gram.y"
    {
		Dist_usage = SD_MIN;
	;}
    break;

  case 626:
#line 6134 "gram.y"
    {
		Dist_usage = SD_FORCE;
	;}
    break;

  case 627:
#line 6139 "gram.y"
    {
		Aligntag = NOALIGNTAG;
	;}
    break;

  case 628:
#line 6145 "gram.y"
    {
		if (rangecheck((yyvsp[(2) - (2)].intval), MINALIGNTAG, MAXALIGNTAG, "align tag number") == YES) {
			Aligntag = (yyvsp[(2) - (2)].intval);
		}
		else {
			Aligntag = NOALIGNTAG;
		}
	;}
    break;

  case 631:
#line 6163 "gram.y"
    {
		add_stuff_item((yyvsp[(1) - (5)].floatval), (yyvsp[(2) - (5)].floatval), Start_gracebackup, (yyvsp[(3) - (5)].stringval),
			Til_bars, Til_offset, Til_steps, End_gracebackup,
			Dist, Dist_usage, Aligntag);
	;}
    break;

  case 632:
#line 6171 "gram.y"
    {
		Til_bars = 0;
		Til_offset = 0.0;
		Til_steps = 0.0;
		(yyval.floatval) = (yyvsp[(1) - (2)].floatval);
		Start_gracebackup = (yyvsp[(2) - (2)].intval);
	;}
    break;

  case 633:
#line 6180 "gram.y"
    {
		(yyval.intval) = 0;
	;}
    break;

  case 634:
#line 6186 "gram.y"
    {
		(yyval.intval) = (yyvsp[(3) - (4)].intval);
	;}
    break;

  case 635:
#line 6191 "gram.y"
    {
		(yyval.floatval) = 0.0;
	;}
    break;

  case 636:
#line 6197 "gram.y"
    {
		(yyval.floatval) = (yyvsp[(3) - (4)].floatval) * (float) (yyvsp[(2) - (4)].intval);
	;}
    break;

  case 637:
#line 6202 "gram.y"
    {
		(yyval.stringval) = (char *) 0;
	;}
    break;

  case 638:
#line 6208 "gram.y"
    {
		if (get_stuff_type() != ST_PEDAL) {
			yyerror("'*' only valid with pedal");
		}
		MALLOCA(char, (yyval.stringval), 12);
		(yyval.stringval)[0] = FONT_MUSIC;
		(yyval.stringval)[1] = DFLT_SIZE;
		sprintf((yyval.stringval) + 2, "\\(endped)");
	;}
    break;

  case 639:
#line 6220 "gram.y"
    {
		(yyval.stringval) = (yyvsp[(1) - (1)].stringval);
	;}
    break;

  case 640:
#line 6225 "gram.y"
    {
		End_gracebackup = 0;
	;}
    break;

  case 641:
#line 6231 "gram.y"
    {
	;}
    break;

  case 642:
#line 6236 "gram.y"
    {
		/** if there is a non-empty til_suffix, the floatnum better
		 ** have been an integer, and is really the number
		 * of bars. **/
		if ((yyvsp[(2) - (2)].intval) == YES) {
			Til_bars = (int) (yyvsp[(1) - (2)].floatval);
			if ((yyvsp[(1) - (2)].floatval) - Til_bars != 0.0) {
				yyerror("number of measures in til clause must be a whole number");
			}
		}
		else {
			/* only a number, that means it was really a beat offset */
			Til_offset = (yyvsp[(1) - (2)].floatval);
		}
	;}
    break;

  case 643:
#line 6254 "gram.y"
    {
		(yyval.intval) = NO;
		End_gracebackup = (yyvsp[(1) - (2)].intval);
		Til_steps = (yyvsp[(2) - (2)].floatval);
	;}
    break;

  case 644:
#line 6262 "gram.y"
    {
		(yyval.intval) = YES;
	;}
    break;

  case 645:
#line 6268 "gram.y"
    {
		Til_offset = 0.0;
		Til_steps = (yyvsp[(2) - (2)].floatval);
		End_gracebackup = (yyvsp[(1) - (2)].intval);
	;}
    break;

  case 646:
#line 6276 "gram.y"
    {
		Til_offset = (yyvsp[(2) - (4)].floatval);
		Til_steps = (yyvsp[(4) - (4)].floatval);
		End_gracebackup = (yyvsp[(3) - (4)].intval);
	;}
    break;

  case 648:
#line 6286 "gram.y"
    {
		newROLLINFO();
	;}
    break;

  case 649:
#line 6292 "gram.y"
    {
		newROLLINFO();
		setrolldir(UP);
	;}
    break;

  case 650:
#line 6299 "gram.y"
    {
		newROLLINFO();
		setrolldir(DOWN);
	;}
    break;

  case 652:
#line 6310 "gram.y"
    {
		/* save staffnum and voice 1 for start of roll */
		rollparam((yyvsp[(1) - (1)].intval), 1, -1, -1);
	;}
    break;

  case 653:
#line 6317 "gram.y"
    {
		/* save staff and voice for start of roll */
		rollparam((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].intval), -1, -1);
	;}
    break;

  case 655:
#line 6326 "gram.y"
    {
		/* save staffnum, voice 1 for end of roll */
		rollparam(-1, -1, (yyvsp[(2) - (2)].intval), 1);
	;}
    break;

  case 656:
#line 6333 "gram.y"
    {
		/* save staffnum and voice for end of roll */
		rollparam(-1, -1, (yyvsp[(2) - (3)].intval), (yyvsp[(3) - (3)].intval));
	;}
    break;

  case 657:
#line 6340 "gram.y"
    {
		rolloffset( (double) (yyvsp[(1) - (2)].floatval));
	;}
    break;

  case 658:
#line 6346 "gram.y"
    {	
		rolloffset( (double) (yyvsp[(2) - (3)].floatval));
	;}
    break;

  case 659:
#line 6351 "gram.y"
    {
		if (Curr_family == FAMILY_DFLT) {
			Curr_family = Score.fontfamily;
		}
		Extra = extra_needed(Curr_family + Curr_font, Curr_size, (yyvsp[(3) - (3)].stringval));
		proc_printcmd((yyvsp[(1) - (3)].intval), Curr_loc_info_p, (yyvsp[(3) - (3)].stringval), Curr_family + Curr_font,
			Curr_size, (yyvsp[(2) - (3)].intval), NO, ((yyvsp[(2) - (3)].intval) == YES ? Extra : (double) 0.0));
	;}
    break;

  case 660:
#line 6362 "gram.y"
    {
		if ((yyvsp[(2) - (3)].intval) == YES) {
			warning("nl ignored for postscript");
		}
		proc_printcmd(J_NONE, Curr_loc_info_p, (yyvsp[(3) - (3)].stringval), FONT_UNKNOWN,
			DFLT_SIZE, NO, YES, (double) 0.0);
		end_raw();
	;}
    break;

  case 661:
#line 6373 "gram.y"
    {
		begin_raw();
	;}
    break;

  case 663:
#line 6381 "gram.y"
    {
		/* this means print at default location */
		Curr_loc_info_p = (struct INPCOORD *) 0;
		(yyval.intval) = NO;
	;}
    break;

  case 664:
#line 6389 "gram.y"
    {
		Curr_loc_info_p = (struct INPCOORD *) 0;
		(yyval.intval) = YES;
	;}
    break;

  case 665:
#line 6396 "gram.y"
    {
		(yyval.intval) = NO;
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 9120 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 6401 "gram.y"


#include <stdio.h>


/* print error message along with current filename and line number */

int
yyerror(msg)

char *msg;

{
	if (strncmp(msg, "syntax error", 12) == 0 ||
			strncmp(msg, "parse error", 11) == 0) {
		/* beef up yacc's default syntax error message */
		if (*yytext == '\n') {
			l_yyerror(Curr_filename, yylineno,
				"error detected at end of line (maybe missing semicolon or other required element?)");
		}
		else if (is_internal_token(yytext) == YES) { 
			/* We add some funny tokens for our internal use
			 * when doing emptymeas parameter expansion.
			 * It is conceivable that there could be
			 * some (rare) scenarios where a user error
			 * in their value for that parameter would cause the
			 * parser to detect the error when it got to our
			 * funny token, and it would be very confusing to the
			 * user if we printed that out as the offending token,
			 * since they didn't input it, and it is chosen
			 * specifically to be strange looking.
			 */
			l_yyerror(Curr_filename, yylineno,
				"error detected during internal emptymeas parameter processing");
		}
		else {
			l_yyerror(Curr_filename, yylineno,
				"error detected at '%s'", yytext);
		}
	}
	else {
		l_yyerror(Curr_filename, yylineno, "%s", msg);
	}

	/* return something to keep lint happy */
	return(0);
}


/* if argument is surrounded by double quotes, remove them and return the
 * unquoted string. Actually just NULL out the end quote and return a
 * pointer to beyond the leading quote */

static char *
stripquotes(string)

char *string;

{
	char *p;

	p = string + strlen(string) - 1;
	if (*p == '"') {
		*p = '\0';
	}
	return( *string == '"' ? string + 1 : string);
}


/* make sure each header/footer type specified only once */

static void
chkdup_headfoot(flag, which)

int flag;	/* if non-zero, had gotten this head/foot before */
char *which;	/* header, footer, header2 or footer2 */

{
	if (flag != 0) {
		l_yyerror(Curr_filename, yylineno,
				"%s context specified more than once", which);
	}
}


/* when entering new context, need to save away everything about current one */

static void
end_prev_context()

{
	struct MAINLL *place_p;		/* where to insert SSV in main list */


	/* assume we will place at the end of main list. Later we'll set
	 * the right value if that assumption is wrong */
	place_p = Mainlltc_p;

	/* If current main list item hasn't been added to list yet,
	 * do that now. */
	if (Currstruct_p != (struct MAINLL *) 0 && Currstruct_p != place_p) {

		if (Currstruct_p->str == S_SSV) {

			if (List_of_staffs_p != (struct MAINLL *) 0) {
				yyerror("can't change context inside a measure");
				Currstruct_p = (struct MAINLL *) 0;
				return;
			}

			/* if is an SSV struct, we also need to set the
			 * correct values at this point, because the
			 * parser needs to know current values of some
			 * things (like font and point size) */
			asgnssv(Currstruct_p->u.ssv_p);

			/* if this SSV is after a FEED, we have to move it
			 * before the FEED in order to follow the rules of
			 * what comes when on the main list */
			for (   ; place_p != (struct MAINLL *) 0 &&
					place_p->str == S_FEED;
					place_p = place_p->prev) {
			}
		}

		insertMAINLL(Currstruct_p, place_p);
	}

	if (Currstruct_p != 0 && Currstruct_p->str == S_SSV) {
		/* memorize or recall beamstyle and timeunit if appropriate */
		remember_tsig_params(Currstruct_p);

		/* If user specified multiple staffs/voices, clone the
		 * necessary SSV nows */
		if (Currstruct_p->u.ssv_p->context == C_STAFF) {
			clone_staff_ssvs(place_p);
			free_rlists();
		}
		else if (Currstruct_p->u.ssv_p->context == C_VOICE) {
			clone_voice_ssvs(place_p);
			free_rlists();
		}
		Defining_multiple = NO;
	}

	if (Curr_usym_p != 0) {
		define_usym();
		Curr_usym_p = 0;
	}

	Curr_grpsyl_p = (struct GRPSYL *) 0;
	Currblock_p = (struct BLOCKHEAD *) 0;
	set_win_coord(0);
}


/* If user gave a list of staffs for a "staff" context, clone copies of
 * the SSV that we made for the first on the list for the rest of the list. */

static void
clone_staff_ssvs(insert_p)

struct MAINLL *insert_p;
{
	struct SVRANGELIST *svr_p;
	struct RANGELIST *sr_p;		/* list of staff ranges */
	struct SSV *clone_src_p;	/* the SSV to clone */
	int s;				/* staff number */

	clone_src_p = Currstruct_p->u.ssv_p;
	for (svr_p = Svrangelist_p; svr_p != 0; svr_p = svr_p->next) {
		for (sr_p = svr_p->stafflist_p; sr_p != 0; sr_p = sr_p->next) { 
			for (s = sr_p->begin; s <= sr_p->end && s <= Score.staffs; s++) {
				if (clone_src_p->staffno == s) {
					/* skip past the clone source */
					continue;
				}
				clone1ssv(clone_src_p, insert_p, s, clone_src_p->voiceno);
			}
		}
	}
}


/* If user gave a list of staffs and/or voices  for a "voice" context,
 * clone copies of the SSV that we made for the first on the list
 * for the rest of the list. */

static void
clone_voice_ssvs(insert_p)

struct MAINLL *insert_p;

{
	struct SVRANGELIST *svr_p;
	struct RANGELIST *sr_p;		/* list of staff ranges */
	struct RANGELIST *vr_p;		/* list of voice ranges */
	struct SSV *clone_src_p;	/* the SSV to clone */
	int s;				/* staff number */
	int v;				/* voice number */
	int numvoices;			/* how many voices on current staff */
	int have_non_v3 = NO;		/* If any voice other than voice 3 */


	clone_src_p = Currstruct_p->u.ssv_p;
	for (svr_p = Svrangelist_p; svr_p != 0; svr_p = svr_p->next) {
	    for (sr_p = svr_p->stafflist_p; sr_p != 0; sr_p = sr_p->next) { 
		for (s = sr_p->begin; s <= sr_p->end && s <= Score.staffs; s++) {
		    numvoices = vscheme_voices(svpath(s, VSCHEME)->vscheme);
		    for (vr_p = svr_p->vnolist_p; vr_p != 0; vr_p = vr_p->next) {
			for (v = vr_p->begin; v <= vr_p->end && v <= numvoices; v++) {
				if (v != 3) {
					have_non_v3 = YES;
				}
				if (clone_src_p->staffno == s
						&& clone_src_p->voiceno == v) {
					/* skip past the clone source */
					continue;
				}
				clone1ssv(clone_src_p, insert_p, s, v);
			}
		    }
		}
	    }
	}

	if (clone_src_p->used[ALIGNRESTS] == YES && have_non_v3 == NO) {
		l_warning(Curr_filename, yylineno,
				"alignrests not used for voice 3; ignoring");
	}
}

/* Clone the given SSV and insert it in the specified place in the main list.
 * Change the copied versions staffno/voiceno to the specified values,
 * and do any additional error checks and processsing as needed.
 */

static void
clone1ssv(clone_src_p, insert_p, staffno, voiceno)

struct SSV *clone_src_p;
struct MAINLL *insert_p;
int staffno;
int voiceno;

{
	struct MAINLL *newmllssv_p;	/* the cloned SSV */

	newmllssv_p = newMAINLLstruct(S_SSV, Currstruct_p->inputlineno);
	memcpy(newmllssv_p->u.ssv_p, clone_src_p, sizeof(struct SSV));
	newmllssv_p->u.ssv_p->staffno = staffno;
	newmllssv_p->u.ssv_p->voiceno = voiceno;
	/* Fix beamstyle/timeunit. It could be different for each clone */
	remember_tsig_params(newmllssv_p);
	insertMAINLL(newmllssv_p, insert_p);

	/* Make sure any tab staffs have non-tabs above them.
	 * One disadvantage of waiting till making the clone to check this is
	 * that if there is a user error, the line number will be the end
	 * of the context rather than the one with "stafflines" on it.
	 * But the error message will tell them which staff is the problem,
	 * and this should be pretty rare--they have to be setting stafflines
	 * in a staff context for multiple staffs where the combination of
	 * staffs is illegal--so it doesn't seem worth the extra work it would
	 * be to be more precise. */
	if (newmllssv_p->u.ssv_p->context == C_STAFF &&
				newmllssv_p->u.ssv_p->used[STAFFLINES] == YES) {
		chk_tab(newmllssv_p);
	}
	asgnssv(newmllssv_p->u.ssv_p);
}


/* Check that the staffs/voices specified for an SSV are valid.
 * We only give a warning if all values specified are out of range.
 * If at least one is valid, we assume user did something like
 * 	voice 1-40 3
 * to set something for voice 3 on all staffs without having to worry
 * about which staffs actually have a voice 3.
 */

static void
chk_ssv_ranges(context)

int context;	/* expected to only be either C_STAFF or C_VOICE */

{
	struct SVRANGELIST *svr_p;	/* list of staff/voice ranges */
	struct RANGELIST *sr_p;		/* list of staff ranges */
	struct RANGELIST *vr_p;		/* list of voice ranges */
	int s;				/* staff number */
	int v;				/* voice number */
	int numvoices;			/* how many voices on current staff */


	for (svr_p = Svrangelist_p; svr_p != 0; svr_p = svr_p->next) {
	    for (sr_p = svr_p->stafflist_p; sr_p != 0; sr_p = sr_p->next) { 
		for (s = sr_p->begin; s <= sr_p->end; s++) {
		    if (context == C_STAFF) {
			if (s >= MINSTAFFS && s <= Score.staffs) {
				/* Found a valid one. One is all we need. */
				return;
			}
			continue;
		    }

		    /* a voice context */
		    numvoices = vscheme_voices(svpath(s, VSCHEME)->vscheme);
		    for (vr_p = svr_p->vnolist_p; vr_p != 0; vr_p = vr_p->next) { 
			for (v = vr_p->begin; v <= vr_p->end; v++) {
			    if (s >= MINSTAFFS && s <= Score.staffs &&
					v >= MINVOICES && v <= numvoices) {
				/* Found a valid one. One is all we need. */
				return;
			    }
			}
		    }
		}
	    }
	}
	/* Fell through all the loops without finding a single valid case */
	if (context == C_STAFF) {
		l_warning(Curr_filename, yylineno,
			"staff out of range; must be between %d and %d",
			MINSTAFFS, Score.staffs);
	}
	else {
		l_warning(Curr_filename, yylineno,
			"staff/voice combination out of range; staff must be between %d and %d, voice between %d and %d and within vscheme limit for the staff",
			MINSTAFFS, MAXSTAFFS, MINVOICES, MAXVOICES);
	}
}


/* if defining more than one voice at the moment, not valid to set
 * a location variable. Print message and reset flag so we don't
 * give any more of the same message this measure */

static void
var_valid()

{
	if (Defining_multiple == YES) {
		yyerror("location tag is only allowed when defining a single voice");
		Defining_multiple = NO;
	}
	else if (Chord_at_a_time == YES) {
		yyerror("location tag not allowed with chord-at-a-time input");
	}
}


/* do a print command like left, right, or center. Allocate a PRINTDATA
 * struct and fill in all the information about what to print and where
 * to print it. */

static void
proc_printcmd(justifytype, inpc_p, str, font, size, got_nl, isPostScript, extra)

int justifytype;	/* J_LEFT, etc */
struct INPCOORD *inpc_p;	/* where to print */
char *str;		/* the string to print */
int font;
int size;
int got_nl;	/* YES if should go to next line before printing */
int isPostScript;	/* YES if is raw PostScript rather than normal print */
double extra;	/* how much extra vertical padding to add */

{
	struct PRINTDATA *curr_print_p;
	struct EXPR_NODE *node_p;
	int htype;


	(void) contextcheck(C_MUSIC | C_BLOCKHEAD, "print");

	/* save all the info in a PRINTDATA struct */
	MALLOC(PRINTDATA, curr_print_p, 1);

	if (inpc_p == (struct INPCOORD *) 0) {

		/* print at default location */
		curr_print_p->location.vert_p = symval("_cur", (float **) 0);
		/* Create an expression that is _cur - extra */
		node_p = newnode(OP_SUB);
		curr_print_p->location.vexpr_p = node_p;

		node_p->left.lchild_p = newnode(OP_TAG_REF);
		MALLOC(TAG_REF, node_p->left.lchild_p->left.ltag_p, 1);
		node_p->left.lchild_p->left.ltag_p->c = curr_print_p->location.vert_p;
		node_p->left.lchild_p->left.ltag_p->c_index = AY;
		save_tag_ref(node_p->left.lchild_p->left.ltag_p->c,
					&(node_p->left.lchild_p->left.ltag_p->c));

		node_p->right.rchild_p = newnode(OP_FLOAT_LITERAL);
		node_p->right.rchild_p->left.value = extra;

		switch (justifytype) {
		case J_LEFT:
		case J_RAGPARA:
		case J_JUSTPARA:
			/* default x is relative to _win.w */
			curr_print_p->location.hor_p = symval("_win", (float **) 0);
			htype = AW;
			break;
		case J_RIGHT:
			/* default x is relative to _win.e */
			curr_print_p->location.hor_p = symval("_win", (float **) 0);
			htype = AE;
			break;
		case J_CENTER:
			/* default x is relative to _win.x */
			curr_print_p->location.hor_p = symval("_win", (float **) 0);
			htype = AX;
			break;
		case J_NONE:
		default:
			/* default is at current location */
			curr_print_p->location.hor_p = symval("_cur", (float **) 0);
			htype = AX;
			break;
		}

		curr_print_p->location.hexpr_p = newnode(OP_TAG_REF);
		MALLOC(TAG_REF, curr_print_p->location.hexpr_p->left.ltag_p, 1);
		curr_print_p->location.hexpr_p->left.ltag_p->c = curr_print_p->location.hor_p;
		curr_print_p->location.hexpr_p->left.ltag_p->c_index = htype;
		save_tag_ref(curr_print_p->location.hexpr_p->left.ltag_p->c,
			&(curr_print_p->location.hexpr_p->left.ltag_p->c));

		/* If this is the first print command in a block,
		 * we implicitly go down by the font ascent. */
		if (isPostScript == NO && Currblock_p != 0
					&& Next_print_link_p_p
					== &(Currblock_p->printdata_p) ) {
			/* Alter expression, to subtract the fontascent */
			node_p = newnode(OP_SUB);
			node_p->left.lchild_p = curr_print_p->location.vexpr_p;
			curr_print_p->location.vexpr_p = node_p;
			node_p->right.rchild_p = newnode(OP_FLOAT_LITERAL);
			node_p->right.rchild_p->left.value = fontascent(font, size) / STEPSIZE;

			got_nl = NO;
		}

	}
	else {
		curr_print_p->location = *(inpc_p);
		rep_inpcoord(inpc_p, &(curr_print_p->location) );
		FREE(inpc_p);
	}

	curr_print_p->isPostScript = isPostScript;
	if (isPostScript == YES) {
		curr_print_p->width = 0.0;
	}
	else {
		curr_print_p->width = strwidth(str);
	}
	curr_print_p->justifytype = (short) justifytype;
	curr_print_p->string = str;
	curr_print_p->inputfile = Curr_filename;
	curr_print_p->inputlineno = (short) yylineno;

	/* special case of user asking that this be printed
	 * on the next line. In this case we go down by the
	 * current point size */
	if (got_nl) {
		node_p = newnode(OP_SUB);
		node_p->left.lchild_p = curr_print_p->location.vexpr_p;
		curr_print_p->location.vexpr_p = node_p;
		node_p->right.rchild_p = newnode(OP_FLOAT_LITERAL);
		node_p->right.rchild_p->left.value = fontheight(font, size) / STEPSIZE;
	}

	/* Now link onto proper list -- could be in BLOCKHEAD
	 * context or doing a PRHEAD. If we are in BLOCKHEAD context, we
	 * definitely have something in the main list to attach to.
	 * If in C_MUSIC, we may or may not depending on whether
	 * this is the first in a series of print commands. */
	if ( ((Context & C_BLOCKHEAD) != 0)
		|| ((Currstruct_p != (struct MAINLL *) 0) &&
		(Currstruct_p->str == S_PRHEAD) ) ) {
			if (Next_print_link_p_p == (struct PRINTDATA **) 0) {
				pfatal("Next_print_link_p_p is null");
			}
			/* this means the value of Next_print_link_p_p
			 * is valid and will tell us where to link */
			*Next_print_link_p_p = curr_print_p;
	}
	else {
		/* We must be in music context, but the last
		 * thing we saw wasn't a print command, so
		 * we have to allocate a PRHEAD and put it
		 * in the main list and attach to that. */
		/* allocate a new struct, put on main list and attach
		 * the print command to it */
		Currstruct_p = newMAINLLstruct(S_PRHEAD, yylineno);
		insertMAINLL(Currstruct_p, Mainlltc_p);
		Currstruct_p->u.prhead_p->printdata_p = curr_print_p;
		Currstruct_p = (struct MAINLL *) 0;
	}

	/* in any case, if we get another print command right away, it
	 * should be linked onto this one, so remember where we are */
	Next_print_link_p_p = &(curr_print_p->next);
	curr_print_p->next = (struct PRINTDATA *) 0;
}


/* if the given string has a higher ascent than the given font/size, return
 * the amount is it higher, in stepsizes */

static double
extra_needed(font, size, string)

int font;	/* default font for this string */
int size;	/* default size for this string */
char *string;	/* string, which might contain \s(xx) to make it bigger
		 * than normal */

{
	double usual_ascent;
	double this_string_ascent;


	/* get expected ascent for this font/size and actual for string */
	usual_ascent = fontascent(font, size);
	(void) fix_string(string, font, size, Curr_filename, yylineno);
	this_string_ascent = strascent(string);

	/* if this string is too tall, return by how much it is too tall */
	if (this_string_ascent > usual_ascent) {
		return (this_string_ascent - usual_ascent) / STEPSIZE;
	}
	else {
		return(0.0);
	}
}


/* Sometimes lexer will recognize something as a keyword, but it's
 * really a bunch of note letters, due to context. This function turns
 * the mistaken keyword into notes. It handles a through g and r and s, and
 * us, but not n, which would also be troublesome, but which we don't (yet)
 * need to handle.
 */

static void
keyword_notes(str)

char *str;

{
	for (  ; *str != '\0'; str++) {
		if (*str == 'u' && *(str+1) == 's') {
			str++;
			continue;
		}

		/* On the last letter, if it's a true pitch, have to
		 * push it back into input, because it could be followed
		 * by an accidental or octave mark or tick or something. */
		if (*(str+1) == '\0' && *str >= 'a' && *str <= 'g') {
			pushback(*str);
		}
		else {
			add_note(Curr_grpsyl_p, (int) *str, 0, USE_DFLT_OCTAVE,
							0, NO, (char *) 0);
		}
	}
}


/* Free up the current additive time list, if any */

static void
free_extra_time()
{
	struct TIMELIST *tl_p;

	/* If this was the most recently allocated list, we can free it.
	 * We can't free otherwise, since Extra_time_p might be
	 * pointing to one from an SSV, which must be kept around. */
	if (Extra_time_p == Last_alloced_timelist_p) {
		while (Extra_time_p != 0) {
			tl_p = Extra_time_p->next;
			FREE(Extra_time_p);
			Extra_time_p = tl_p;
		}
	}
	Extra_time_p = 0;
	Last_alloced_timelist_p = 0;
	Curr_timelist_p = 0;
}


/* Add an item to the internal representation of the time signature
 * currently being collected */

static void
tsig_item(item)

int item;	/* the byte to add to timerep */

{
	if (Tsig_offset >= MAXTSLEN  - 1) {
		l_ufatal(Curr_filename, yylineno,
				"time signature is too complicated");
	}
	Timerep[Tsig_offset++] = (char) item;
}


/* Allocate a new expression node, fill in its opearator field, and return it. */

static struct EXPR_NODE *
newnode(op)

int op;		/* OP_* value for the new node */

{
	struct EXPR_NODE * node_p;

	CALLOC(EXPR_NODE, node_p, 1);
	node_p->op = op;
	return(node_p);
}

