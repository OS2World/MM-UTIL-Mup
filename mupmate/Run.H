/* Copyright (c) 2006, 2008, 2009 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _RUN_H_
#define _RUN_H_

// Classes for Run menu off of main toolbar

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include "globals.H"
#include "File.H"
#include "Config.H"
#include <stdio.h>
#include <sys/types.h>
#ifdef OS_LIKE_UNIX
#include <signal.h>
#endif
#ifdef OS_LIKE_WIN32
#include <windef.h>
#include <winbase.h>
#include <winnt.h>
#include <process.h>
#endif

// Information about a non-waited-for process
#ifdef OS_LIKE_WIN32
typedef PROCESS_INFORMATION Proc_Info;
#else
typedef pid_t Proc_Info;
#endif

// We limit the number of macros user can define,
// to fit in a reasonably small dialog window.
#define MAX_MACROS	5


// Class for asking user what arguments to pass to Mup when running it

class Run_parameters_dialog : Fl_Double_Window {

friend class Run;

public:
	Run_parameters_dialog(void);
	~Run_parameters_dialog(void);

	// Callbacks
	static void combine_cb(Fl_Widget *, void * data);
	static void extract_cb(Fl_Widget *, void * data);
	static void selected_pages_cb(Fl_Widget *, void * data);
	static void clear_form_cb(Fl_Widget *, void * data);
	static void Macros_cb(Fl_Widget *, void * data);
	static void Apply_and_close_cb(Fl_Widget *, void * data);
	static void Apply_cb(Fl_Widget *, void * data);
	static void Cancel_cb(Fl_Widget *, void * data);

	// Returns true if macro definition is invalid.
	static bool macro_error(const char * macro);

private:
	// Callbacks
	void combine(void);
	void extract(void);
	void selected_pages(void);
	void clear_form(void);
	void Macros(void);
	void Apply_and_close(void);
	void Apply(void);
	void Cancel(void);

	// Common code for Apply and Apply_and_close
	void do_apply(bool ok_to_hide);

	// Widgets
	Fl_Check_Button * enable_combine_p;
	Positive_Int_Input * rest_combine_p;
	Positive_Int_Input * first_page_p;
	Fl_Group * pages_p;
	  Fl_Check_Button * all_p;
	  Fl_Check_Button * odd_p;
	  Fl_Check_Button * even_p;
	  Fl_Check_Button * selected_p;
	  Fl_Input * page_list_p;
	Fl_Input * staff_list_p;
	Int_Input * extract_begin_p;
	Int_Input * extract_end_p;
	Fl_Group * macros_group_p;
	  Fl_Input * macro_definitions_p[MAX_MACROS];
	Fl_Return_Button * apply_and_close_p;
	Fl_Button * apply_p;
	Fl_Button * clear_form_p;
	Fl_Button * cancel_p;

	// Saved values for run parameters
	bool saved_enable_combine;
	char saved_combine_measures[8];
	char saved_first_page[8];
	enum { ALL_PAGES, ODD_PAGES, EVEN_PAGES, SELECTED_PAGES } saved_pages;
	char * saved_page_list;
	char * saved_staff_list;
	char saved_extract_begin[8];
	char saved_extract_end[8];
	char * saved_macro_definitions[MAX_MACROS];
};


// Class for displaying stderr output from Mup to user

class Error_report : public Fl_Double_Window
{
public:
	Error_report(void);
	~Error_report(void);

	// Reads the file where stderr was saved
	int loadfile(const char * filename);

	// Callbacks
	static void OK_cb(Fl_Widget *, void *);
	static void font_change_cb(void * data, Fl_Font font, unsigned char size);

private:
	// Callbacks
	void font_change(Fl_Font font, unsigned char size);
	void OK(void);

	// Widgets
	Fl_Text_Display * text_p;
	Font_change_registration * font_change_reg_p;
	Fl_Return_Button * ok_p;
};



// Class for the Run menu on the main menu bar

class Run {

friend class File;	// For auto-display

public:
	Run(void);
	~Run(void);

	// To know which file to run Mup on
	void set_file(File * file);
	// Kill off child processes
	void clean_up(void);

	// Callbacks
	static void Display_cb(Fl_Widget *, void * data);
	static void Play_cb(Fl_Widget *, void * data);
	static void WritePostScript_cb(Fl_Widget *, void * data);
	static void WriteMIDI_cb(Fl_Widget *, void * data);
	static void Options_cb(Fl_Widget *, void * data);

private:
	// Callbacks
	void Display(void);
	void Play(void);
	void WritePostScript(void);
	void WriteMIDI(void);
	void Options(void);

	// This runs Mup and maybe viewer/player
	void Run_Mup(bool midi, bool show_or_play);

	// Execute the command with given argv.
	// If proc_info_p is zero, wait for the process to complete,
	// otherwise fill it in with information about the spawned process,
	// so that the caller can keep track of it while it runs independently.
	// The hide_window parameter is only used for Windows and causes the
	// spawned process to be created with flags to not create a window,
	// This lets us use a console mode version of Mup, so traditional users
	// can continue to run Mup in a console without mupmate, but we can
	// run the same .exe without the annoyance of a console popping up.
	// Returns 0 on success, -1 on failure to create process,
	// or what the process returned if it had non-zero exit code
	// and was waited for. If a not-waited-for process returns 0,
	// proc_info_p will contain handle or pid information.
	int execute_command(const char **argv, Proc_Info * proc_info_p,
						bool hide_window = false);

	// kill off a previously spawned child process
	void kill_process(const Proc_Info * const proc_info_p,
					const char * const description);

	// Highlight error in the input
	enum Severity { No_error, Warning, Error };
	void show_errors(const char *errfile, const int base_length);
	void mark_line(const int line, const Severity severity);
	
	// Report if we have running helper programs
	bool has_MIDI_child(void);
	bool has_display_child(void);

#ifdef OS_LIKE_WIN32
	// To check if using displayer/player we know how to handle specially
	static bool is_gsview(const char * command);
	static bool is_mplayer(const char * command);
#endif

	// Widgets
	Run_parameters_dialog * parameters_p;
	Error_report * report_p;
	File * file_p;

	// Handles for child processes
	Proc_Info display_child;
	Proc_Info MIDI_child;
};

#endif
