//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/     /*Command*/         /*Update Interval*/	/*Update Signal*/
	{"",	     "sb-capslock", 	 0,			11},
	{"",         "sb-record",	 0,			10},
	{"",         "sb-pacpackages",   0, 			1},
	{"",	     "sb-moonphase",     18000,			12},
	{"",	     "sb-forecast",      18000,			2},
//	{"💽",       "sb-disk",          7200, 	        	14},
	{"🖥️",        "sb-cpu",           3, 	                 3},
	{"🌡",        "sb-temp",          3, 	                 4},
	{"🧠",       "sb-memory",        3, 			5},
//	{"🔃",       "sb-swap",          3, 			15},
//	{"",	     "sb-nettraf",	 1,			13},
	{"",	     "sb-volume", 	 0,			6},
	{"",	     "sb-battery", 	 5,			7},
	{"🗓️",        "sb-clock",	  1,		 	 8},
	{"",	     "sb-internet",      5,			9},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "  ";

