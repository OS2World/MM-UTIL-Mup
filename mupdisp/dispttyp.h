
/* Copyright (c) 1995, 1996, 1998 by Arkkra Enterprises */
/* All rights reserved */

/* to compile Mup/Ghostscript display program
 * to allow working on AT386 terminal type, make sure AT386 is
 * defined. To compile to work on X-windows, make sure XWINDOW is defined.
 * To work with either, define both.
 * Support for other terminal types could be added in the future. */

#ifdef i386
#if !defined(linux) && !defined(__EMX__)
#define AT386	1
#endif
#endif

#ifdef unix
#define XWINDOW	1
#endif

