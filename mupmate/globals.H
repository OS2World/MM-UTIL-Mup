#ifndef _GLOBALS_H
#define _GLOBALS_H

// Try to consolidate OS-specific ifdef complicated clauses to this
// header file, so code can use descriptive ifdefs
#if defined(__WIN32) && ! defined(__CYGWIN__)
#define OS_LIKE_WIN32
#endif

#if defined(__linux) || defined(unix)
#define OS_LIKE_UNIX
#endif

#if defined(__APPLE__)
// Mac OS X is a special flavor of UNIX
// so simply treat it like UNIX at most places
#define OS_LIKE_UNIX
#define OS_LIKE_MACOSX
#endif

// We use a class static method for callbacks which cast their "void * data"
// argument to an instance of the class, and call the class method.
// So we use these macros to enforce consistent usage of that technique. 
// Most places will use CALL_BACK. The CALL_BACK_A is only needed in code
// when the object method takes an argument.
// Can't use CALLBACK as single word since under mingw that is already
// defined as something completely different.
#define CALL_BACK_A(classname, cb_name, arg) \
	void \
	classname::cb_name##_cb(Fl_Widget *, void * data) \
	{ \
		((classname *)data)->cb_name(); \
	} \
	void \
	classname::cb_name(arg)
#define CALL_BACK(classname, cb_name) CALL_BACK_A(classname, cb_name, void)

#endif
