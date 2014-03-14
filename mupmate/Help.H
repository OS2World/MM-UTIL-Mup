/* Copyright (c) 2006 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _HELP_H_
#define _HELP_H_

// Classes for Help menu item off of main toolbar

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/filename.H>
#include "Config.H"


// Class for window to let user browse the HTML version of Mup User's Guide

class Uguide_browser : Fl_Double_Window {

friend class Help;

public:
	Uguide_browser(void);
	~Uguide_browser(void);

	// User can change font/size preference. This callback notifies
	// of such changes, so we can adjust the output accordingly 
	static void font_change_cb(void * data, Fl_Font font, unsigned char size);

	// Load the User's Guide top level index.html file
	void load_uguide(void);

private:
	void font_change(Fl_Font font, unsigned char size);

	// On Windows, Fl_Help_View doesn't seem to properly follow relative
	// URLs, so we use the link() callback to prepend the proper directory.
	static const char * resolve_link(Fl_Widget *, const char * uri);

	Fl_Help_View *browser_p;
	Font_change_registration * font_change_reg_p;
	bool loaded;
};


// Class to give first time user some hints.

class StartupHints : Fl_Double_Window {

friend class Help;

public:
	StartupHints(void);
	~StartupHints(void);

	static void OK_cb(Fl_Widget *, void * data);
	// User can change font/size preference. This callback notifies
	// of such changes, so we can adjust the output accordingly 
	static void font_change_cb(void * data, Fl_Font font, unsigned char size);
private:
	void OK(void);
	void font_change(Fl_Font font, unsigned char size);

	Font_change_registration * font_change_reg_p;
	Fl_Text_Display * text_p;	// The text of the hints
	Fl_Return_Button * OK_p;
};


// Class for "About" window

class About_dialog : Fl_Double_Window {

friend class Help;

public:
	About_dialog(void);
	~About_dialog(void);

	static void OK_cb(Fl_Widget *, void * data);

private:
	void OK(void);

	Fl_Multiline_Output * message_p;
	Fl_Return_Button * ok_p;
};


// Class for Help menu item from main toolbar

class Help {
public:
	Help(void);
	~Help(void);

	static void Uguide_cb(Fl_Widget *, void * data);
	static void Startup_Hints_cb(Fl_Widget *, void * data);
	static void About_cb(Fl_Widget *, void * data);

private:
	void Uguide(void);
	void Startup_Hints(void);
	void About(void);

	About_dialog * about_p;
	StartupHints * startup_hints_p;
	Uguide_browser * uguide_p;
};

#endif
