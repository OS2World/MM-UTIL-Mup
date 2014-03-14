/* Copyright (c) 2006 by Arkkra Enterprises */
/* All rights reserved */

/* We build the template into Mupmate so we do not have to depend on the
 * template file existing at run time. */
extern const char * const template_text =
"//!Mup-Arkkra\n\
// This is a Mup input file template.\n\
// Lines starting with // are \"comments\" that are here for your benefit.\n\
// You can remove them without affecting the output.\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		things to go on the top of the first page\n\
top\n\
\n\
	//		 centered title.\n\
	// The number in parentheses is the text point size.\n\
	// Make it bigger if you want a bigger title or smaller if you\n\
	// want a smaller title\n\
	title (18) \"Replace this with the title of your song\"\n\
\n\
	//		subtitle\n\
	// If you want a subtitle, remove the // from the beginning\n\
	// of the next line and fill in the appropriate subtitle text\n\
	// title (14) \"Replace this with the subtitle\"\n\
\n\
	//		composer info\n\
	// The first pair of double quotes enclose what to left justify,\n\
	// the second encloses what to right justify.\n\
	// If you want more than one line, add similar lines of input\n\
	title   \"\"   \"Replace this with composer info\"\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		things to go on the bottom on the first page\n\
bottom\n\
	// If you want a copyright notice, remove the //\n\
	// from the next line and edit in the appropriate information\n\
	// title \"\\(copyright) Copyright  Replace this with year and name\"\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		things to go on the top of pages other than the first\n\
top2\n\
	// This example will give a centered page number between dashes.\n\
	// You can customize as you wish.\n\
	title \"- \\% -\"\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		things to go at the bottom of pages other than the first\n\
bottom2\n\
	// if you want things printed at the bottom of pages of than\n\
	// the first page, place them here\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		score-wide parameters\n\
//\n\
// You may or may not need to change some items in this section\n\
//\n\
// The values given as examples are the default values that Mup uses\n\
// if you don't specify anything for them\n\
score\n\
	//	time signature. Can be cut, com,\n\
	//	or two numbers with a /	between them\n\
	time = 4/4\n\
\n\
	//	key signature. Value is a number from 0 to 7\n\
	//	followed by # or & for number of sharps or flats.\n\
	key = 0#\n\
\n\
	//	how many staffs. Can be a number from 1 to 40\n\
	staffs = 1\n\
\n\
	//	clef. Can be treble, treble8, 8treble, frenchviolin,\n\
	//	soprano, mezzosoprano, alto, tenor, baritone, or bass\n\
	clef = treble\n\
\n\
	// Note: there are many more parameters that can be set,\n\
	// but they are not included in this simple template.\n\
	// There are parameters to set margins, control how things\n\
	// are laid out on the page, transpositions value, font and size\n\
	// for text and lyrics, etc\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//	You can set some parameters for specific staffs,\n\
//	to override the score-wide parameters. For example,\n\
//	if you specify staffs = 2 in the score-wide parameters above,\n\
//	and want to use bass clef on staff 2, even though the score-wide\n\
//	clef parameter is set to treble, you can do\n\
//		staff 2\n\
//			clef = bass\n\
\n\
\n\
/////////////////////////////////////////////////////////////////////////\n\
//		music input starts here\n\
music\n\
\n\
\n\
// For each measure, you enter one line of input for each staff,\n\
// then indicate what kind of barline to print.\n\
// The following specifies that staff 1 contains a measure of rest\n\
// and that an ordinary bar line is to be used at the end of the measure.\n\
\n\
1: mr;\n\
bar\n\
\n\
// Usually, a measure of input for one staff consists of one or more chords\n\
// Each chord is specified by\n\
//	time_value notes ;\n\
// where time_value is something like\n\
//	4	for a quarter note\n\
//	8	for an eighth note\n\
//	4.	for a dotted-quarter note\n\
// etc and notes is a list of one or more notes, specified as a pitch from\n\
// a to g, optionally followed by an accidental (#, &, x, &&, or n for sharp,\n\
// flat, double sharp, double flat, or natural respectively).\n\
// Examples:\n\
//	4c;\n\
//	2. ceg;\n\
//	16 f#;\n\
//	1 d b&;\n\
// (Spaces are optional, you can put them in if you want, but don't have to)\n\
//\n\
// So a complete measure might look something like:\n\
//	1: 4e; 4d; 2c;\n\
//	bar\n\
//\n\
// If you want a note in a different octave than the default octave\n\
// (the octave from middle-C up for treble clef,\n\
// or the octave below middle-C for bass clef),\n\
// you can add a + for each octave to go up or - for each octave to go down.\n\
// For example:\n\
//	1: c+; gc+e+; a&-; f#---;\n\
//\n\
// There are many other things you can specify, such as ties, slurs, grace\n\
// notes, etc, and there are also many shortcuts you can use to save typing.\n\
// Consult the Mup documentation for more details.\n\
\n\
// Other bar types you may want to use are\n\
//	repeatstart\n\
//	repeatend\n\
//	repeatboth\n\
//	dblbar\n\
//	endbar\n\
//	invisbar";
