/* Copyright (c) 2006, 2007, 2010 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _UTILS_H_
#define _UTILS_H_

// This file defines miscellaneous things that don't seem to really
// belong with any particular menu.

#include <FL/Fl.H>
#include <FL/Fl_Int_Input.H>

#ifdef OS_LIKE_WIN32
// For some reason mingw doesn't seem to properly define va_list anywhere.
// I guess it needs a compiler-specific header file.
// We don't actually use any functions that use va_list,
// so just need to try to keep the compiler happy.
#ifndef va_list
#define va_list __VALIST
#endif
#endif

// The FLTK Fl_Int_Input is almost what we want, but it allows
// octal and hex input via leading 0 and 0x respectively.
// So the Int_Input derived class intercepts the input and throws away
// characters from the set [xX] and leading zeros.
// Sometimes we also want to restrict to positive numbers,
// so the Positive_Int_Input class discards the - character as well.

class Int_Input : public Fl_Int_Input {
public:
	Int_Input(int x, int y, int w, int h, const char * label);
	int handle(int event);
protected:
	bool allow_negative;
};

class Positive_Int_Input : public Int_Input {
public:
	Positive_Int_Input(int x, int y, int w, int h, const char * label);
};


// Return the native OS's directory separator character
char dir_separator(void);
// Return the native OS's path separator character
char path_separator(void);

// Set the $MUPPATH value
extern void set_muppath(const char * new_muppath);

// Get value of PATH from third argument to main(), or failing that,
// from getenv(), and save it.
extern void get_path(const char ** const env_p);

// Return true if given path is an absoluate path
extern bool is_absolute(const char * const path);

// Find full path to an executable.
// If found, true is returned and full path is filled into location,
// which must be at least FL_PATH_MAX bytes long.
// If executable is not found, false is returned, and the contents of
// location is not defined.
extern bool find_executable(const char * const pgm_name, char * location);

// Returns path to magic file saying user agrees to license
extern const char * magic_file(const char * pname = 0);

// wrapper for fl_filename_expand that corrects directory separators
extern void filename_expand(char *expanded_path, const char *given_path);

#ifdef OS_LIKE_WIN32
// On Windows, we read the registry to try to determine the proper
// program to use for a given file type, like .mid or .ps files.
// This function will return the path to the appropriate file,
// if found, in a static area that may get overwritten on next call,
// so caller needs to make its own copy. If program is not found,
// returns null.
extern char * lookup_pgm_for_file_suffix(const char * file_suffix);

// Look for likely default directory for Mup files.
// Use the current user's "My Music" place if there is one,
// otherwise try their "My Documents" folder.
// Returns path in static area or null on failure.
extern char * find_music_folder(void);

#endif

#endif
