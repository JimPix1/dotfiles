//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/     /*Command*/         /*Update Interval*/	/*Update Signal*/
	{"[📦",      "sb-pacpackages",   0,	                1},
	{"[",	     "sb-forecast",      18000,                 2},
//	{"[⛅",	     "weather.py",	 350,                   2},   /* When wttr.in is not functional use weather.py */
	{"[🖥",      "sb-cpu",          3, 	                3},
	{"[🌡",       "sb-temp",          3, 	               4},
	{"[🧠",      "sb-memory",        3,	                5},
	{"[",	     "sb-volume", 	 0,	                6},
	{"[",	     "sb-battery", 	 5,	                7},
	{"[🗓️",      "sb-clock",         1,	               8},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "] ";



// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }

