/* Copyright (c) 2006, 2009 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _CONFIG_H_
#define _CONFIG_H_

// Classes for Config menu item off of main toolbar

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include "utils.H"


// Class for window that asks user for file locations

class FileLocations_dialog : Fl_Double_Window {

friend class Config;

public:
	FileLocations_dialog(void);
	~FileLocations_dialog();

	// Callbacks
	static void Save_cb(Fl_Widget *, void *);
	static void Cancel_cb(Fl_Widget *, void *);

private:
	// Callbacks
	void Save(void);
	void Cancel(void);

	// Populuate fields with current values
	void set_current_values(void);

	// Widgets
	Fl_Input * mup_program_p;
	Fl_Input * mup_documentation_p;
	Fl_Input * music_files_p;
	Fl_Input * muppath_p;
	Fl_Input * viewer_p;
	Fl_Input * player_p;
	Fl_Return_Button * apply_p;
	Fl_Button * cancel_p;
};


// Class for window that asks user for preferences, like editor font, size, etc.

class Preferences_dialog : Fl_Double_Window {

friend class Config;

public:
	Preferences_dialog(void);
	~Preferences_dialog();

	// Callbacks
	static void Save_cb(Fl_Widget *, void * data);
	static void Cancel_cb(Fl_Widget *, void * data);
	static void fontchg_cb(Fl_Widget *, void * data);

private:
	// Callbacks
	void fontchg(void);
	void Save(void);
	void Cancel(void);

	// Populate fields with current values
	void set_current_values(void);

	// Populate size menu as appropriate for the given font
	void set_size_list(Fl_Font font, uchar curr_size);

	// Widgets
	Fl_Choice * font_p;
	Fl_Choice * size_p;
	Fl_Check_Button * auto_display_p;
	Fl_Check_Button * auto_save_p;
	Fl_Value_Input * tooltips_delay_p;
	Fl_Return_Button * apply_p;
	Fl_Button * cancel_p;
};


// Class for user to fill out registration form

class RegistrationForm_dialog : public Fl_Double_Window
{
public:
	RegistrationForm_dialog(void);
	~RegistrationForm_dialog(void);

	// Callbacks
	static void SaveForm_cb(Fl_Widget *, void * data);
	static void Cancel_cb(Fl_Widget *, void * data);

private:
	// Callbacks
	void SaveForm(void);
	void Cancel(void);

	// Fill in the form and write it out for user to mail with payment.
	void generate_form(void);
	// Fill in the value in the blank before or after the given place.
	// If can't fit entire value, returns pointer to how far it got,
	// otherwise returns zero.
	const char * fill_in(bool before, char *place, const char * const value);
	// Calculate sales tax due.
	double sales_tax(void);

	// Widgets
	Fl_Input * name_p;
	Fl_Input * address_p;
	Fl_Input * city_p;
	Fl_Input * state_p;
	Fl_Input * postal_code_p;
	Fl_Input * country_p;
	Fl_Input * email_p;
	Fl_Input * how_heard_p;
	Fl_Check_Button * Windows_p;
	Fl_Check_Button * Mac_p;
	Fl_Check_Button * Linux_p;
	Fl_Check_Button * other_p;
	Fl_Input * other_OS_p;
	Fl_Check_Button * mailing_list_p;
	Positive_Int_Input  * num_regs_p;

	Fl_Return_Button * save_form_p;
	Fl_Button * cancel_p;
};


// Class for user to enter registration key after paying.

class RegistrationKey_dialog : public Fl_Double_Window {
public:
	RegistrationKey_dialog(void);
	~RegistrationKey_dialog();

	// Callbacks
	static void OK_cb(Fl_Widget *, void *);
	static void Cancel_cb(Fl_Widget *, void *);

private:
	// Callbacks
	void OK(void);
	void Cancel(void);

	// Widgets
	Fl_Secret_Input * key_p;
	Fl_Return_Button * OK_p;
	Fl_Button * cancel_p;
};

// Class for the Config menu item on main toolbar

class Config {
public:
	Config();
	~Config();

	// Callbacks
	static void FileLocations_cb(Fl_Widget *, void *);
	static void Preferences_cb(Fl_Widget *, void *);
	static void RegistrationForm_cb(Fl_Widget *, void *);
	static void RegistrationKey_cb(Fl_Widget *, void *);

	// Convert font name to Fl_Font value
	static Fl_Font fontvalue(const char *);

private:
	// Callbacks
	void FileLocations(void);
	void Preferences(void);
	void RegistrationForm(void);
	void RegistrationKey(void);

	// Widgets
	FileLocations_dialog * locations_p;
	Preferences_dialog * preferences_p;
	RegistrationForm_dialog * registrationform_p;
	RegistrationKey_dialog * registrationkey_p;
};


// Any class that wants to be notified of changes in user preference
// for font and size should register a callback function of this type
// using the Font_change_registration class. The first arg will be user
// data the registrant wants to have passed to it. The second argument
// is the new font, and the third argument is the new size.
typedef void (*Font_change_callback)(void *, Fl_Font, unsigned char);

// Any class that wants to be notified of changes in user preference
// in font/size should instantiate an instance of this class.
class Font_change_registration {
public:
	Font_change_registration(Font_change_callback func, void * arg);
	~Font_change_registration(void);

	// This runs all the registered callbacks
	static void run_callbacks(Fl_Font font, unsigned char size);

private:
	// Linked list of callbacks
	static Font_change_registration * list_p;
	Font_change_registration * next;

	// What function to call back, and what to pass it.
	Font_change_callback callback;
	void * callback_arg;
};

#endif
