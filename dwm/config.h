 //		      dwm config.h			//
/////////////////////////////////////////////////////////
/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMINAL2 "kitty"
#define TERMCLASS "st"

/* appearance */
static unsigned int borderpx = 3;     /* border pixel of windows */
static unsigned int snap     = 14;    /* snap pixel */
static unsigned int gappih   = 6;     /* horiz inner gap between windows */
static unsigned int gappiv   = 6;     /* vert inner gap between windows */
static unsigned int gappoh   = 5;     /* horiz outer gap between windows and screen edge */
static unsigned int gappov   = 5;     /* vert outer gap between windows and screen edge */
static int swallowfloating   = 1;     /* 1 means swallow floating windows by default */
static int smartgaps         = 1;     /* 1 means no outer gap when there is only one window */
static int showbar           = 1;     /* 0 means no bar */
static int topbar            = 1;     /* 0 means bottom bar */
static const int user_bh     = 20;    /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
/*  Display modes of the tab bar: never shown, always shown, shown only in
    monocle mode in the presence of several windows.
    Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab     = showtab_auto;     /* Default tab bar show mode */
static const int toptab      = False;            /* False means bottom tab bar */

static char *fonts[]            = { "monospace:size=10", "JoyPixels:pixelsize=11:antialias=true:autohint=true" };
static const char col_gray1[]   = "#222222";
static char normbgcolor[]       = "#13141d";
static char normbordercolor[]   = "#222222";
static char normftbordercolor[] = "#222222";
static char normfgcolor[]       = "#bbbbbb";
static char selfgcolor[]        = "#15141d";
static char selbordercolor[]    = "#84a0c6";
static char selftbordercolor[]  = "#6088be";
static char selbgcolor[]        = "#84a0c6";
static char *colors[][4] = {
       /*               fg           bg           border           float */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor, normftbordercolor},
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor,  selftbordercolor},
};

static const char *const autostart[] = {
       "xfce4-power-manager", NULL,
       "xbindkeys", NULL,
       "dwmblocks", NULL,
       "bgchanger-feh", NULL,
       "picom", NULL,
       "dunst", NULL,
       "redshiftday", NULL,
//       "/lib/mate-polkit/polkit-mate-authentication-agent-1", NULL,
       NULL /* terminate */
};

/* scratchpads */
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
/* 	    sp cmd	program	  instance name          geometry	command	         */
const char *spcmd1[] = {TERMINAL, "-n", "spnvim",     "-g", "90x40",  "-e", "nvim", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcmus",     "-g", "95x35",  "-e", "cmus", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spterm",     "-g", "135x35",               NULL };
const char *spcmd4[] = {TERMINAL, "-n", "spterm2",    "-g", "134x35",               NULL };
const char *spcmd5[] = {TERMINAL, "-n", "spfloaterm", "-g", "85x34",                NULL };
const char *spcmd6[] = {TERMINAL, "-n", "spcalc",     "-g", "80x30",  "-e", "bc",   NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spnvim",      spcmd1},
	{"spcmus",      spcmd2},
	{"spterm",      spcmd3},
	{"spterm",      spcmd4},
	{"spfloaterm",  spcmd5},
	{"spcalc",      spcmd6},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    	             instance      title          	      tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     	               NULL,         NULL,       	      0,           0,           0,          0,         0 },
        /* General */
	{ "Thunderbird",               NULL,         NULL,      	      1 << 4,      0,           0,          0,         0 },
	{ "Audacious",                 NULL,         NULL,      	      0,           1,           0,          0,         0 },
	{ "Steam",                     NULL,         NULL,     		      1 << 6,      0,           0,          0,         0 },
	{ "Rum",                       NULL,         NULL,     		      1 << 6,      0,           0,          0,         0 },
	{ "qBittorrent",               NULL,         NULL,      	      1 << 3,      0,           0,          0,         0 },
	{ "zoom",                      NULL,         NULL,       	      1 << 0,      0,           0,          0,         0 },
	/* Tag 9 Assigns */
	{ "Brave-browser-beta",        NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	{ "firefox-nightly",           NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	{ "Chromium",                  NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	{ "discord",                   NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	{ "Element-Nightly",           NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	/* Terminal Assigns */
	{ "kitty",                     NULL,         NULL,       	      0,           0,           1,          0,         0 },
	{ "st",                        NULL,         NULL,       	      0,           0,           1,          0,         0 },
	{ "URxvt",                     NULL,         NULL,       	      1 << 7,      0,           1,          0,         0 },
	/* Title Assigns */
	{ NULL,                        NULL,         "Event Tester",  	      0,           0,           0,          1,         0 },
	{ NULL,                        NULL,         "Picture-in-picture",    0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Picture-in-Picture",    0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Page Unresponsive",     0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "weatherreport",         0,           1,           0,          0,         0 },
	/* Games */
	{ "voxygen",                   NULL,         NULL,           	      1 << 5,      0,           0,          0,         0 },
	{ NULL,                        NULL,         "Mindustry",             1 << 5,      0,           0,          0,         0 },
	{ "lunarclient",               NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "apricots",                  NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "openspades",                NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "hl2_linux",        	       NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "ShovelKnight",              NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Wine",                      NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "hollow_knight.x86_64",      NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Kingdom Rush",              NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "Kingdom Rush Frontiers",    NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "KingdomsAndCastles.x86_64", NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "astromenace",               NULL,         NULL,     		      1 << 5,      0,           0,          0,         0 },
	{ "supertuxkart",              NULL,         NULL,     		      1 << 5,      0,           0,          0,         0 },
	{ "supertux2",                 NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "Minecraft* 1.18.1",         NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "steam_app_291550",          NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "steam_app_960090",          NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	/* Scratchpads */
	{ NULL,                        "spnvim",     NULL,                    SPTAG(0),    1,           1,          0,         0 },
	{ NULL,                        "spcmus",     NULL,                    SPTAG(1),    1,           1,          0,         0 },
	{ NULL,                        "spterm",     NULL,                    SPTAG(2),    1,           1,          0,         0 },
	{ NULL,                        "spterm2",    NULL,                    SPTAG(3),    1,           1,          0,         0 },
	{ NULL,                        "spfloaterm", NULL,                    SPTAG(4),    1,           1,          0,         0 },
	{ NULL,                        "spcalc",     NULL,                    SPTAG(5),    1,           1,          0,         0 },
};


/* layouts */
static float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;   /* number of clients in master area */
static int resizehints = 0;   /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1        /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "nrowgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

 	{ "[M]",	monocle },		/* All windows on top of eachother */
	{ "[D]",	deck },			/* Master on left, slaves in monocle-like mode on right */

	{ "###",        nrowgrid },             /* better gaplessgrid */
	{ "><>",	NULL },			/* no layout function means floating behavior */

	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */
	{ "[@]",	spiral },		/* Fibonacci spiral */

	{ "|M|",	centeredmaster },	     /* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },    /* Same but master floats */

	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */

static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",		STRING,	&normbordercolor },
		{ "color8",		STRING,	&selbordercolor },
		{ "color0",		STRING,	&normbgcolor },
		{ "color4",		STRING,	&normfgcolor },
		{ "color0",		STRING,	&selfgcolor },
		{ "color4",		STRING,	&selbgcolor },
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	 &mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

/* keybindings */
static Key keys[] = {
	/* modifier                     key        function      argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(			XK_1,	   0)
	TAGKEYS(			XK_2,	   1)
	TAGKEYS(			XK_3,	   2)
	TAGKEYS(			XK_4,	   3)
	TAGKEYS(			XK_5,	   4)
	TAGKEYS(			XK_6,	   5)
	TAGKEYS(			XK_7,	   6)
	TAGKEYS(			XK_8,      7)
	TAGKEYS(			XK_9,	   8)
	{ MODKEY,			XK_0,	   view,	 {.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,	   tag,          {.ui = ~0 } },

	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY,			XK_q,		killclient,	{0} },
	{ MODKEY,			XK_r,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_r,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[2]} }, /* monocle */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[3]} }, /* deck */
	{ MODKEY,		        XK_y,		setlayout,	{.v = &layouts[4]} }, /* nrowgrid */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[5]} }, /* float */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,                       XK_i,           setlayout,      {.v = &layouts[8]} }, /* dwindle */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[9]} }, /* spiral */
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_backslash,	view,		{0} },

	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.05} },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	{ .i = 1 } },


        { MODKEY|ShiftMask,	        XK_p,           togglescratch,	{.ui = 0} },
        { MODKEY|ShiftMask,		XK_comma,       togglescratch,	{.ui = 1} },
        { MODKEY,		        XK_BackSpace,   togglescratch,	{.ui = 2} },
        { MODKEY|ControlMask,		XK_BackSpace,   togglescratch,	{.ui = 3} },
        { MODKEY|ShiftMask,		XK_BackSpace,   togglescratch,	{.ui = 4} },
        { MODKEY,		        XK_c,           togglescratch,	{.ui = 5} },

	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_e,		togglebar,	{0} },
	{ MODKEY|ShiftMask,             XK_e,           tabmode,        {-1} },
	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },

	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask          button            function         argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,                  Button3,          zoom,            {0} },
	{ ClkStatusText,        0,                  Button1,          sigdwmblocks,    {.i = 1} },
	{ ClkStatusText,        0,                  Button2,          sigdwmblocks,    {.i = 2} },
	{ ClkStatusText,        0,                  Button3,          sigdwmblocks,    {.i = 3} },
	{ ClkStatusText,        0,                  Button4,          sigdwmblocks,    {.i = 4} },
	{ ClkStatusText,        0,                  Button5,          sigdwmblocks,    {.i = 5} },
	{ ClkStatusText,        ShiftMask,          Button1,          sigdwmblocks,    {.i = 6} },
#endif
	{ ClkClientWin,         MODKEY,             Button1,          movemouse,       {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button1,          togglefloating,  {0} },
	{ ClkClientWin,         MODKEY,             Button2,          defaultgaps,     {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button2,   	      zoom,            {0} },
	{ ClkClientWin,         MODKEY,             Button3,  	      resizemouse,     {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button3,  	      togglefullscr,   {0} },
	{ ClkClientWin,		MODKEY,	  	    Button4,   	      incrgaps,	       {.i = +1} },
	{ ClkClientWin,		MODKEY,		    Button5,          incrgaps,	       {.i = -1} },
	{ ClkTagBar,            MODKEY|ShiftMask,   Button1,          tag,             {0} },
        { ClkTagBar,            MODKEY,             Button3,  	      toggletag,       {0} },
	{ ClkTagBar,            MODKEY,             Button1,  	      view,            {0} },
	{ ClkTagBar,            MODKEY,             Button3,  	      toggleview,      {0} },
        { ClkTagBar,		MODKEY,		    Button4,          shiftview,       {.i = -1} },
	{ ClkTagBar,		MODKEY,		    Button5,          shiftview,       {.i = 1} },
	{ ClkTabBar,            0,                  Button1,          focuswin,        {0} },
	{ ClkRootWin,		0,		    Button2,          togglebar,       {0} },
};

 //////////////////////////////////////////////////////////
//			End of file			//

