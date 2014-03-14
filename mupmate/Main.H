/* Copyright (c) 2006, 2008 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _MAIN_H_
#define _MAIN_H_

// Header file for the main Mupmate window, containing toolbar and editor.

#include <FL/Fl_Widget.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Editor.H>

#include "File.H"
#include "Edit.H"
#include "Run.H"
#include "Config.H"
#include "Help.H"

class Main;

//---------- class to show Mup license and get user's agreement

class License : public Fl_Double_Window {
public:
	License(Main * m_p, const char * magic);
	~License(void);

	// Callbacks
	static void IAgree_cb(Fl_Widget *, void * data);
	static void Cancel_cb(Fl_Widget *, void * data);
	static void Continue_cb(Fl_Widget *, void * data);

private:
	// Callbacks
	void IAgree(void);
	void Cancel(void);
	void Continue(void);

	// Widgets
	Fl_Text_Display * text_p;	// The text of the license
	Fl_Return_Button * i_agree_p;
	Fl_Button * cancel_p;

	// Name of file that tells us if user has agreed to license
	const char * magic_file_name;

	// The main window
	Main * main_p;
};



// Class for main window, with editor and toolbar

class Main : public Fl_Double_Window {

friend class License;

public:
	Main(const char * title);
	~Main();

	// Callbacks
	static void modify_cb(int, int, int, int, const char *, void * data);
	static void font_change_cb(void * data, Fl_Font font, unsigned char size);
	static void atclose_cb(Fl_Widget *, void * data);
	static void apple_open_cb(const char *c);
	// For highlighting error lines
	static void style_unfinished_cb(int, void *);
	static void style_update_cb(int pos, int inserted, int deleted, int,
			const char *, void * data);


	// We don't want Escape to cause main window to close,
	// and need to handle Paste ungraying specially.
	// This event handler takes care of those things.
	static int handle_events(int);

	// Highlight the specified line in red
	void highlight_error_line(const int linenum, const char index);
	// Unhighlight everything
	void unhighlight_all(void);

	// Show user hints the first time they bring up Mupmate
	void hints(void);

	// Reset state information when user opens a new file.
	void begin_new_file();

	// Pointers to the classes for each toolbar menu item widgets
	File * filemenu_p;
	Edit * editmenu_p;
	Config * configmenu_p;
	Help * helpmenu_p;
	Run * runmenu_p;

	// Clean up all windows 
	static void clean_exit(int exitval = 0);

private:
	// called when input text is modified
	void modify(void);

	// Sets font/size of editor
	void font_change(Fl_Font font, unsigned char size);

	// Make window manager close like Exit
	void atclose(void);

	// Cursor blinker
	static void blinker(void *);

	// Ponters to the top level widgets
	Fl_Menu_Bar * toolbar_p;
	Fl_Text_Editor * editor_p;
	Fl_Text_Buffer * style_buff_p;

	// For highlighting error lines
	Fl_Text_Display::Style_Table_Entry style_table[3];


	// For font/size change notification
	Font_change_registration * font_change_reg_p;

	// True if there is a selected area in editor window
	bool have_selection;

	// True if something in clipboard
	bool can_paste;

	// For knowing when to gray out Undo menu item
	bool undo_active;
	bool undo_active_on_next_change;
	int prev_bufflength;

	// Current cursor on/off state, for blinker
	int cursor_state;

	// We currently only have one main window, but code is
	// general to allow multiple windows. We keep a linked list
	// of all the windows.
	static Main * list_p;
	Main * next;
};

#endif
