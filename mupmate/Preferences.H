/* Copyright (c) 2006, 2007 by Arkkra Enterprises */
/* All rights reserved */

#ifndef _PREFERENCES_H_
#define _PREFERENCES_H_

// This file contains things related to user configuration options
// and preferences.

#include <FL/Fl_Preferences.H>

// When preferences have been migrated from previous release, but user
// has not yet been given migration status hints, Migration_status is
// set to Data_migrated. Once the hints are shown, it is changed to
// Migration_complete. If there was nothing to migrate from,
// it gets set to Migration_complete immediately.
const int Not_migrated = 0;
const int Data_migrated = 1;
const int Migration_complete = 2;

// Names and default values for things stored in preferences file
extern const char * const Mup_program_location;
extern const char * const Mup_documentation_location;
extern const char * const Music_files_location;
extern const char * const MUPPATH_location;
extern const char * const Viewer_location;
extern const char * const MIDI_player_location;
extern const char * const Editor_font_preference;
extern const char * const Editor_size_preference;
extern const char * const Auto_display_preference;
extern const char * const Auto_save_preference;
extern const char * const Tooltips_delay_preference;
extern const char * const Showed_startup_hints;
extern const char * const Migration_status;

extern const char * const Default_Mup_program_location;
extern const char * const Default_Mup_documentation_location;
extern const char * const Default_music_files_location;
extern const char * const Default_MUPPATH_location;
extern const char * const Default_viewer_location;
extern const char * const Default_MIDI_player_location;
extern const char * const Default_editor_font;
extern const char * const Default_editor_size;
extern const int Default_auto_display;
extern const int Default_auto_save;
extern const double Default_tooltips_delay;
extern const int Default_startup_hints_flag;
extern const int Default_migration_status;

// This lets us access user preferences that persist across sessions
extern Fl_Preferences * Preferences_p;

// Minimum and maximum font size we use
extern const unsigned char Min_size;
extern const unsigned char Max_size;

// Default and minimum sizes of Main and Help browser windows
extern const int Min_width;
extern const int Default_width;
extern const int Min_height;
extern const int Default_height;

// The directory containing User's Guide, relative to top of
// documentation tree
extern const char * uguide_directory;

// Given a path to Mup's documentation directory,
// add on the name of the User's Guide index file.
// Return that in a static area.
extern const char * users_guide_index_file(const char * const doc_dir);

// This tries to find reasonable default applications for viewing and playing
extern void deduce_helper_locations(void);

// Migrate preferences from previous version, if necessary
extern void migrate_preferences(void);

#endif
