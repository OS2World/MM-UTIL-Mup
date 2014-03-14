/* Copyright (c) 2006, 2007, 2009, 2010 by Arkkra Enterprises */
/* All rights reserved */

// Code for Help menu item from main toolbar

#include "globals.H"
#include "Preferences.H"
#include "Config.H"
#include "Help.H"
#include <FL/fl_ask.H>
#include <string.h>
#include <stdlib.h>


// Window for browsing Mup User's Guide

Uguide_browser::Uguide_browser(void)
	: Fl_Double_Window(0, 0, Default_width, Default_height, "Mup User's Guide")
{
	browser_p = new Fl_Help_View(x(), y(), w(), h(), "");
	// Set font/size and arrange to get notified of changes in them
	font_change_reg_p = new Font_change_registration(font_change_cb, (void *) this);

	// Haven't loaded the User's Guide yet
	loaded = false;

	// Allow browser window to be made as big as the user wants
	size_range(Min_width, Min_height, 0, 0);
	resizable((Fl_Widget *)browser_p);

	// Fix problem with following relative links properly.
	browser_p->link(resolve_link);

	// Arrange for destructor to clean up new-ed widgets
	end();
}


Uguide_browser::~Uguide_browser(void)
{
	delete font_change_reg_p;
	font_change_reg_p = 0;
}


// Load Mup User's Guide into browser, if haven't already done so.

void
Uguide_browser::load_uguide(void)
{
	if (!loaded) {
		// Entry under File Locations tells the base directory
		// for Mup documentation. We concatenate the uguide/index.file
		// to that directory to get top level file for User's Guide.
		char * base_url;
		(void) Preferences_p->get(Mup_documentation_location, base_url,
				Default_Mup_documentation_location);
		const char * url = users_guide_index_file(base_url);

		// Fltk has a bug (at least in some versions):
		// the documentation claims load()
		// returns -1 on failure, but in fact it always returns 0.
		// So the strncmp attempts to deduce if it failed.
		if (browser_p->load(url) != 0 ||
				strstr(browser_p->value(), "Mup User's Guide")
				== 0) {
			fl_alert("Unable to load User's Guide.\n  %s\n"
				"Check settings in Config > File Locations", url);
		}
		else {
			loaded = true;
		}
	}
}


// Callback for when user changes font/size

void
Uguide_browser::font_change_cb(void * data, Fl_Font font, unsigned char size)
{
	((Uguide_browser *)data)->font_change(font, size);
}

void
Uguide_browser::font_change(Fl_Font font, unsigned char size)
{
	browser_p->textfont(font);
	browser_p->textsize(size);
}

// On Windows, Fl_Help_View doesn't seem to properly follow relative
// URLs (it goes relative to current working directory rather than
// relative to the file containing the link),
// so we use the link() callback to prepend the proper directory.
// On Linux, things work fine without this kludge, but things also
// work with it, so to keep code common, we do it always.

const char *
Uguide_browser::resolve_link(Fl_Widget * help_browser_p, const char * uri)
{
	static char link_path[FL_PATH_MAX];

	if (strncmp(uri, "http:", 5) == 0) {
		// Uguide has a few links to arkkra.com.
		// They won't actually work, because we don't handle
		// http, but it's better to let them through than to
		// change the path and really confuse the user.
		return(uri);
	}

	char * base_url;
	(void) Preferences_p->get(Mup_documentation_location, base_url,
				Default_Mup_documentation_location);
	char expanded_url[FL_PATH_MAX];
	filename_expand(expanded_url, base_url);
	(void) sprintf(link_path, "%s%c%s%c%s", expanded_url, dir_separator(),
				uguide_directory, dir_separator(),
				fl_filename_name(uri));
	return((const char *) link_path);
}

//---- Hints for user when they use Mupmate for the first time
// (or they can ask to see it later too)

const char * Welcome_message =
	"Welcome to Mupmate. Mupmate provides an interface to the\n"
	"Mup music publication program from Arkkra Enterprises,\n"
	"making it easy to edit, display, and print musical scores.\n"
	"\n"
	"If you have not used Mup before, you should begin by selecting\n"
	"   Help > Mup User's Guide\n"
	"for information on how to use Mup.\n"
	"\n"
	"You may also want to verify that the settings under\n"
	"   Config > File Locations   and    Config > Preferences\n"
	"are what you want, and adjust them if you wish.\n"
	"\n"
	"You are welcome to try out Mup for free to decide whether\n"
	"it meets your needs. If you decide to keep it, select\n"
	"   Config > Registration Form\n";

const char * Migration_message =
	"Thank you for upgrading Mupmate. Mupmate provides an interface\n"
	"to the Mup music publication program from Arkkra Enterprises,\n"
	"making it easy to edit, display, and print musical scores.\n"
	"\n"
	"Your preferences from the previous version have been migrated,\n"
	"but you should check all the settings under\n"
	"   Config > File Locations   and    Config > Preferences\n"
	"to make sure they are correct, and adjust them if you wish.\n";

StartupHints::StartupHints(void)
	: Fl_Double_Window(Default_width - 100, Default_height - 100,
	"Mup Startup Hints")
{
	text_p = new Fl_Text_Display(20, 20, w() - 40, h() - 90);
	resizable((Fl_Widget *) text_p);
	text_p->buffer( new Fl_Text_Buffer () );
	font_change_reg_p = new Font_change_registration(font_change_cb, (void *) this);
	int migration_status;
	(void) Preferences_p->get(Migration_status, migration_status,
						Default_migration_status);
	if (migration_status == Data_migrated) {
		text_p->buffer()->text(Migration_message);
		Preferences_p->set(Migration_status, Migration_complete);
	}
	else {
		text_p->buffer()->text(Welcome_message);
	}
	char * doc_dir;
	(void) Preferences_p->get(Mup_documentation_location, doc_dir,
			Default_Mup_documentation_location);
	text_p->buffer()->append("\nAdditional documentation is available in the folder:\n  ");
	text_p->buffer()->append(doc_dir);

	OK_p = new Fl_Return_Button(w() / 2 - 50, h() - 50, 100, 30,
								"OK");
	OK_p->callback(OK_cb, this);
	show();
	end();

	Preferences_p->set(Showed_startup_hints, 1);
	Preferences_p->flush();
}

StartupHints::~StartupHints()
{
	delete font_change_reg_p;
	font_change_reg_p = 0;
}

// Callback for user clicking OK when done reading startup hints

CALL_BACK(StartupHints, OK)
{
	hide();
}


// Callback for when user changes font/size

void
StartupHints::font_change_cb(void * data, Fl_Font font, unsigned char size)
{
	((StartupHints *)data)->font_change(font, size);
}

void
StartupHints::font_change(Fl_Font font, unsigned char size)
{
	text_p->textfont(font);
	text_p->textsize(size);
	text_p->redisplay_range(0, text_p->buffer()->length());
}

//-----the "About" window-----------------------------------------------

About_dialog::About_dialog(void)
	: Fl_Double_Window(270, 200, "About Mupmate")
{
	message_p = new Fl_Multiline_Output(20, 20, w() - 40, 120, "");
	message_p->value("\n   Mupmate is a user interface\n"
			"   for the Mup music publisher\n"
			"   program from www.arkkra.com\n"
			"\n"
			"     This is Version 5.8");
	// Hide the cursor by making same color as background
	message_p->cursor_color(message_p->color());

	ok_p = new Fl_Return_Button((w() - 100) / 2, 155, 100, 30, "OK");
	ok_p->callback(OK_cb, this);

	// Arrange for destructor to clean up new-ed widgets
	end();
}

About_dialog::~About_dialog(void)
{
}


CALL_BACK(About_dialog, OK)
{
	hide();
}

//------the Help menu item from main toolbar-----------------------------

Help::Help(void)
{
	uguide_p = 0;
	startup_hints_p = 0;
	about_p = 0;
}

Help::~Help(void)
{
	if (about_p != 0) {
		delete about_p;
		about_p = 0;
	}
	if (startup_hints_p != 0) {
		delete startup_hints_p;
		startup_hints_p = 0;
	}
	if (uguide_p != 0) {
		delete uguide_p;
		uguide_p = 0;
	}
}


// Callback for when user requests viewing the Mup User's Guide

CALL_BACK(Help, Uguide)
{
	if (uguide_p == 0) {
		// first time, create widget
		uguide_p = new Uguide_browser();
	}
	// Always attempt to load in case URL was bad last time but okay now.
	// If already loaded, this will be a no-op.
	uguide_p->load_uguide();
	uguide_p->show();
}


// Callback for when user clicks "Startup Hints" button

CALL_BACK(Help, Startup_Hints)
{
	// We delete any existing instance and start over,
	// just in case the path to the documentation has changed.
	if (startup_hints_p != 0) {
		delete startup_hints_p;
	}
	startup_hints_p = new StartupHints();
	startup_hints_p->show();
}


// Callback for when user clicks "About" button

CALL_BACK(Help, About)
{
	if (about_p == 0) {
		// first time, create widget
		about_p = new About_dialog();
	}
	about_p->show();
}
