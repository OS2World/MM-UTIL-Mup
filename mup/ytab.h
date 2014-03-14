/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */
#line 397 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

