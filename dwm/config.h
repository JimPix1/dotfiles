/* JimPix's build of dwm! */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* Appearance */
static unsigned int borderpx  = 3;    /* border pixel of windows */
static unsigned int snap      = 17;   /* snap pixel */
static unsigned int gappih    = 7;    /* horiz inner gap between windows */
static unsigned int gappiv    = 6;    /* vert inner gap between windows */
static unsigned int gappoh    = 7;    /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 8;    /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;    /* 1 means swallow floating windows by default */
static int smartgaps          = 0;    /* 1 means no outer gap when there is only one window */
static int showbar            = 1;    /* 0 means no bar */
static int topbar             = 1;    /* 0 means bottom bar */
static const int user_bh      = 20;   /* 0 means dwm will calculate bar height, >= 1 means dwm uses user_bh as bar height */
static const int toptab       = False;		/* False means bottom tab bar */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab      = showtab_auto;	/* Default tab bar show mode */

static char *fonts[]          = { "monospace:size=10", "JoyPixels:pixelsize=11:antialias=true:autohint=true" };
static char normbgcolor[]     = "#13141d";
static char normbordercolor[] = "#222222";
static char normfgcolor[]     = "#bbbbbb";
static char selfgcolor[]      = "#15141d";
static char selbordercolor[]  = "#84a0c6";
static char selbgcolor[]      = "#84a0c6";
static char *colors[][3] = {
       /*               fg           bg           border          */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* Scratchpads */
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
/* 	    sp cmd	program	  instance    name            geometry	     command	             */
const char *spcmd1[] = {TERMINAL, "-n",     "spnvim",      "-g", "90x40",  "-e", "nvim",        NULL };
const char *spcmd2[] = {TERMINAL, "-n",     "spcmus",      "-g", "110x35", "-e", "cmus",        NULL };
const char *spcmd3[] = {TERMINAL, "-n",     "spterm",      "-g", "135x35",                      NULL };
const char *spcmd4[] = {TERMINAL, "-n",     "spfloaterm",  "-g", "85x34",                       NULL };
const char *spcmd5[] = {TERMINAL, "-n",     "spcalc",      "-g", "75x30",  "-e", "bc", "-ql",   NULL };
const char *spcmd6[] = {TERMINAL, "-n",     "sptrans-ga",  "-T", "Trans-Ga", "-g", "90x30",  "-e", "trans", ":ga", "-I", NULL };
const char *spcmd7[] = {TERMINAL, "-n",     "sptrans-de",  "-T", "Trans-De", "-g", "90x30",  "-e", "trans", ":de", "-I", NULL };
const char *spcmd8[] = {TERMINAL, "-n",     "sptrans-en",  "-T", "Trans-En", "-g", "90x30",  "-e", "trans", ":en", "-I", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spnvim",      spcmd1},
	{"spcmus",      spcmd2},
	{"spterm",      spcmd3},
	{"spfloaterm",  spcmd4},
	{"spcalc",      spcmd5},
	{"sptrans-ga",  spcmd6},
	{"sptrans-ga",  spcmd7},
	{"sptrans-en",  spcmd8},
};

/* Tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* Assigns */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    	               instance      title          	      tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     	               NULL,         NULL,       	      0,           0,           0,          0,         0 },
        /* General */
	{ "firefox",		       NULL,         NULL,     		      1 << 8,      0,           0,          0,         0 },
	{ "qBittorrent",               NULL,         NULL,      	      1 << 3,      0,           0,          0,         0 },
	{ "Yad",                       NULL,         NULL,      	      0,           1,           0,          0,         0 },
	{ "scrcpy",		       NULL,         NULL,      	      0,           1,           0,          0,         0 },
	{ "Steam",                     NULL,         NULL,     		      1 << 6,      0,           0,          0,         0 },
	{ TERMINAL,                    NULL,         NULL,       	      0,           0,           1,          0,         0 },
	/* Title Assigns */
	{ NULL,                        NULL,         "Event Tester",  	      0,           0,           0,          1,         0 },
	{ NULL,                        NULL,         "Picture-in-Picture",    0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Weather Report",        0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Current Moon Phase",    0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Network Manager",       0,           1,           0,          0,         0 },
	{ NULL,                        NULL,         "Steam", 	 	      1 << 6,      0,           0,          0,         0 },
	/* Games */
	{ NULL,                        NULL,         "Mindustry",             1 << 5,      0,           0,          0,         0 },
	{ "voxygen",                   NULL,         NULL,           	      1 << 5,      0,           0,          0,         0 },
	{ "openspades",                NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "BetterSpades v0.1.5",       NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "ShovelKnight",              NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Wine",                      NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Hollow Knight",	       NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Kingdom Rush",              NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "Kingdom Rush Frontiers",    NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "KingdomsAndCastles.x86_64", NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "btd5-win.exe",              NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "factorio",		       NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 },
	{ "Kingdom Rush",              NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "supertuxkart",              NULL,         NULL,     		      1 << 5,      0,           0,          0,         0 },
	{ "supertux2",                 NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "TotallyAccurateBattleSimulator", NULL,    NULL,      	      1 << 5,      0,           0,          0,         0 },
 	  // Minecraft
	{ "Minecraft* 1.18.1",         NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "minecraft-launcher",        NULL,         NULL,                    1 << 5,      1,           0,          0,         0 },
	{ "Minecraft Launcher",        NULL,         NULL,                    1 << 5,      1,           0,          0,         0 },
	  // Steam Games
	{ "steam_proton", 	       NULL,         NULL,                    1 << 5,      0,           0,          0,         0 },
	{ "hl2_linux",        	       NULL,         NULL,      	      1 << 5,      0,           0,          0,         0 }, // tf2 + hl
	{ "steam_app_7670", 	       NULL,         NULL,                    1 << 5,      0,           0,          0,         0 }, // bioshock
	{ "steam_app_409710", 	       NULL,         NULL,                    1 << 5,      0,           0,          0,         0 }, // bioshock remastered
	{ "steam_app_291550",          NULL,         NULL,                    1 << 5,      0,           0,          0,         0 }, // brawlhalla
	{ "steam_app_960090",          NULL,         NULL,                    1 << 5,      0,           0,          0,         0 }, // bloons td 6
	{ "steam_app_674940",          NULL,         NULL,                    1 << 5,      0,           0,          0,         0 }, // stick fight
	/* Scratchpads */
	{ TERMINAL,                    "spnvim",     NULL,                    SPTAG(0),    1,           1,          0,         0 },
	{ TERMINAL,                    "spcmus",     NULL,                    SPTAG(1),    1,           1,          0,         0 },
	{ TERMINAL,                    "spterm",     NULL,                    SPTAG(2),    1,           1,          0,         0 },
	{ TERMINAL,                    "spfloaterm", NULL,                    SPTAG(3),    1,           1,          0,         0 },
	{ TERMINAL,                    "spcalc",     NULL,                    SPTAG(4),    1,           1,          0,         0 },
	{ TERMINAL,                    "sptrans-ga", NULL,                    SPTAG(5),    1,           1,          0,         0 },
	{ TERMINAL,                    "sptrans-de", NULL,                    SPTAG(6),    1,           1,          0,         0 },
	{ TERMINAL,                    "sptrans-en", NULL,                    SPTAG(7),    1,           1,          0,         0 },
};

/* Layouts */
static float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;   /* number of clients in master area */
static int resizehints = 0;   /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1        /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol       arrange function */
 	{ "[]=",	tile },			   /* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		   /* Master on top, slaves on bottom */

 	{ "[M]",	monocle },		   /* All windows on top of eachother */
	{ "[D]",	deck },		   	   /* Master on left, slaves in monocle-like mode on right */

	{ "###",        nrowgrid },                /* better gaplessgrid */
	{ "><>",	NULL },			   /* no layout function means floating behavior */

	{ "[\\]",	dwindle },	           /* Decreasing in size right and leftward */
	{ "[@]",	spiral },		   /* Fibonacci spiral */

	{ "|M|",	centeredmaster },	   /* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },  /* Same but master floats */

	{ NULL,		NULL },
};

/* Key definitions */
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

/* Helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Commands */
static const char *termcmd[]   = { TERMINAL, NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"

/* Keybindings */
static Key keys[] = {
	/* modifier                     key             function         argument */
	STACKKEYS(MODKEY,                    	        focus)
	STACKKEYS(MODKEY|ShiftMask,          	        push)
	TAGKEYS(			XK_1,	        0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,    	7)
	TAGKEYS(			XK_9,	  	8)
	{ MODKEY,			XK_0,	        view,	         {.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,	        tag,             {.ui = ~0 } },

	{ MODKEY|ControlMask,           XK_q,           quit,            {1} }, // renew dwm
	{ MODKEY,			XK_Tab,		view,		 {0} },
	{ MODKEY,			XK_q,		killclient,	 {0} },
	{ MODKEY,			XK_r,		setlayout, 	 {.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_r,		setlayout,	 {.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_t,		setlayout,	 {.v = &layouts[2]} }, /* monocle */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	 {.v = &layouts[3]} }, /* deck */
	{ MODKEY,		        XK_y,		setlayout,	 {.v = &layouts[4]} }, /* nrowgrid */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	 {.v = &layouts[5]} }, /* float */
	{ MODKEY,			XK_u,		setlayout,	 {.v = &layouts[6]} }, /* dwindle */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	 {.v = &layouts[7]} }, /* spiral */
	{ MODKEY,                       XK_i,           setlayout,       {.v = &layouts[8]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	 {.v = &layouts[9]} }, /* centeredfloatingmaster */
	{ MODKEY,			XK_o,		incnmaster,      {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,      {.i = -1 } },
	{ MODKEY,			XK_backslash,	view,		 {0} },

	{ MODKEY,			XK_a,		togglegaps, 	 {0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	 {0} },
 	{ MODKEY|ControlMask,		XK_a,		togglesmartgaps, {0} },
	{ MODKEY,			XK_s,		togglesticky,	 {0} },
	{ MODKEY,			XK_f,		togglefullscr,	 {0} },
	{ MODKEY,			XK_Return,	spawn,		 {.v = termcmd } },
	{ MODKEY,			XK_g,		shiftview,	 { .i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	 { .i = -1 } },
	{ MODKEY,			XK_h,		setmfact,	 {.f = -0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,      	 {.f = +0.05} },
	{ MODKEY,			XK_semicolon,	shiftview,	 { .i = 1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	 { .i = 1 } },

        { MODKEY|ShiftMask,	        XK_p,           togglescratch,	 {.ui = 0} },
        { MODKEY,			XK_comma,       togglescratch,	 {.ui = 1} },
        { MODKEY,		        XK_BackSpace,   togglescratch, 	 {.ui = 2} },
        { MODKEY|ShiftMask,		XK_BackSpace,   togglescratch,	 {.ui = 3} },
        { MODKEY,		        XK_c,           togglescratch,	 {.ui = 4} },
        { MODKEY,		        XK_minus,       togglescratch,	 {.ui = 5} },
        { MODKEY|ShiftMask,		XK_minus,       togglescratch,	 {.ui = 6} },
        { MODKEY|ControlMask,		XK_minus,       togglescratch,	 {.ui = 7} },

	{ MODKEY,			XK_z,		incrgaps,	 {.i = +3 } },
	{ MODKEY,			XK_x,		incrgaps,	 {.i = -3 } },
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_e,		togglebar,	 {0} },
	{ MODKEY|ShiftMask,             XK_e,           tabmode,         {-1} },
	{ MODKEY,			XK_Left,	focusmon,	 {.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		 {.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	 {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		 {.i = +1 } },

	{ MODKEY,			XK_Page_Up,	shiftview,	 { .i = -1 } },
	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	 { .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	 { .i = +1 } },
	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	 { .i = +1 } },

	{ MODKEY,			XK_space,	zoom,		 {0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	 {0} },
	{ MODKEY,                       XK_Down,        moveresize,      {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,          moveresize,      {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,       moveresize,      {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   	moveresize,      {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,  	moveresize,      {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,    	moveresize,      {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right, 	moveresize,      {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,  	moveresize,      {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,    	moveresizeedge,  {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   	moveresizeedge,  {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left, 	moveresizeedge,  {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,	moveresizeedge,  {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     	moveresizeedge,  {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   	moveresizeedge,  {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   	moveresizeedge,  {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  	moveresizeedge,  {.v = "R"} },

	{ 0,			        XF86XK_AudioMute,    	   spawn,	SHCMD("pamixer -t; pkill -RTMIN+6 dwmblocks") }, // mute
	{ 0,			        XF86XK_AudioRaiseVolume,   spawn,	SHCMD("pamixer --allow-boost -i 5; pkill -RTMIN+6 dwmblocks") }, // vol up
	{ 0,			        XF86XK_AudioLowerVolume,   spawn,	SHCMD("pamixer --allow-boost -d 5; pkill -RTMIN+6 dwmblocks") }, // vol down
	{ MODKEY,			XK_p,   		   spawn,	SHCMD("playerctl pause") }, // player pause
	{ 0,				XF86XK_AudioPlay,   	   spawn,	SHCMD("playerctl play") },  // player play
	{ 0,				XF86XK_AudioNext,   	   spawn,	SHCMD("playerctl next") },  // player next
	{ 0,				XF86XK_AudioPrev,   	   spawn,	SHCMD("playerctl previous") },  // player previous
	{ 0,				XF86XK_MonBrightnessDown,  spawn,	SHCMD("xbacklight -dec 10") },  // brightness down
	{ 0,				XF86XK_MonBrightnessUp,    spawn,	SHCMD("xbacklight -inc 10") },  // brightness up
	{ ControlMask,			XK_F2,   	 	   spawn,	SHCMD("xbacklight -set 0") },   // brightness min
	{ ControlMask,			XK_F3,   	 	   spawn,	SHCMD("xbacklight -set 100") }, // brightness reset

	{ MODKEY,			XK_d,			   spawn,	SHCMD("dmenu_run -c -bw 2 -g 2 -l 13 -fn mono-10") }, // dmenu_run
	{ MODKEY|ShiftMask,		XK_d,	           	   spawn,	SHCMD("dmkill") },   // dmenu script to kill programs etc.
	{ MODKEY|ShiftMask,		XK_q,	           	   spawn,	SHCMD("dmlogout") }, // sys actions
	{ MODKEY,			XK_numbersign,	           spawn,	SHCMD("dmnote") },   // dmenu script for notes
	{ MODKEY|ShiftMask,		XK_numbersign,	           spawn,	SHCMD("$TERMINAL -e $EDITOR ~/dox/notes/notes.md") }, // notes.md
	{ MODKEY|ControlMask,		XK_numbersign,	           spawn,	SHCMD("$TERMINAL -e $EDITOR ~/dox/notes/mcnotes.md") }, // minecraft notes
	{ MODKEY,			XK_n,			   spawn,	SHCMD(TERMINAL " -e lfrun") }, // lf file manager
};

/* Button definitions */
/* Click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask          button        function         argument */
	{ ClkStatusText,        0,                  Button1,      sigdwmblocks,    {.i = 1} },
	{ ClkStatusText,        0,                  Button2,      sigdwmblocks,    {.i = 2} },
	{ ClkStatusText,        0,                  Button3,      sigdwmblocks,    {.i = 3} },
	{ ClkStatusText,        0,                  Button4,      sigdwmblocks,    {.i = 4} },
	{ ClkStatusText,        0,                  Button5,      sigdwmblocks,    {.i = 5} },
	{ ClkStatusText,        ShiftMask,          Button1,      sigdwmblocks,    {.i = 6} },
	{ ClkStatusText,        ShiftMask,   	    Button3,      sigdwmblocks,    {.i = 7} },
	{ ClkStatusText,        ControlMask,   	    Button1,      sigdwmblocks,    {.i = 8} },

	{ ClkStatusText,        ShiftMask,          Button2,      spawn,           SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,             Button1,      movemouse,       {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button1,      togglefloating,  {0} },
	{ ClkClientWin,         MODKEY,             Button2,      defaultgaps,     {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button2,   	  zoom,            {0} },
	{ ClkClientWin,         MODKEY,             Button3,  	  resizemouse,     {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button3,      togglefullscr,   {0} },
	{ ClkClientWin,		MODKEY,	  	    Button4,  	  incrgaps,	   {.i = -1} },
	{ ClkClientWin,		MODKEY,		    Button5,      incrgaps,	   {.i = +1} },
	{ ClkTagBar,            0, 		    Button2,      tag,             {0} },
        { ClkTagBar,            MODKEY,             Button1,	  toggletag,       {0} },
	{ ClkTagBar,            0, 	            Button1,  	  view,            {0} },
	{ ClkTagBar,            0, 	            Button3,  	  toggleview,      {0} },
        { ClkTagBar,		0,		    Button4,      shiftview,       {.i = -1} },
	{ ClkTagBar,		0,		    Button5,      shiftview,       {.i = 1} },
	{ ClkWinTitle,          0,                  Button1,      focuswin,        {1} },
	{ ClkWinTitle,          0,                  Button3,      zoom,            {0} },
	{ ClkTabBar,            0,                  Button1,      focuswin,        {0} },
	{ ClkRootWin,		0,		    Button2,      togglebar,       {0} },
};

