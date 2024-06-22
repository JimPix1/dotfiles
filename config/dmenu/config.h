// JimPix's Dmenu Config

static int topbar    = 1;              /* -b  option; if 0, dmenu appears at bottom */
static int opacity   = 0;              /* -o  option; if 0, then alpha is disabled */
static int fuzzy     = 1;              /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int center    = 0;              /* -c  option; if 0, dmenu won't be centered on the screen */
static int min_width = 450;            /* minimum width when centered */
static int restrict_return = 0;        /* -1 option; if 1, disables shift-return and ctrl-return */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:pixelsize=12:antialias=true:autohint=true",
	"JoyPixels:pixelsize=11:antialias=true:autohint=true"
};

static const char *prompt = NULL;      /* -p  option; prompt to the left of input field */

static const unsigned int baralpha = 0xe0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               	  fg      bg        border     */
	[SchemeNorm] 	      = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  	      = { OPAQUE, baralpha, borderalpha },
	[SchemeBorder] 	      = { OPAQUE, OPAQUE, OPAQUE },
	[SchemeMid] 	      = { OPAQUE, baralpha, borderalpha },
	[SchemeSelHighlight]  = { OPAQUE, baralpha, borderalpha },
	[SchemeNormHighlight] = { OPAQUE, baralpha, borderalpha },
};

static const char *colors[][2] = {
	/*                          fg         bg       */
	[SchemeNorm]          =  { "#cccccc", "#13141d" },
	[SchemeSel]           =  { "#000000", "#84a0c6" },
	[SchemeSelHighlight]  =  { "#d7d7d7", "#000000" },
	[SchemeNormHighlight] =  { "#d7d7d7", "#000000" },
	[SchemeOut]           =  { "#13141d", "#13141d" },
	[SchemeMid]           =  { "#d7d7d7", "#1f202c" },
	[SchemeBorder] 	      =  { "#000000", "#84a0c6" },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;
/* -g option; if nonzero, dmenu uses a grid comprised of columns and lines */
static unsigned int columns        = 0;
static unsigned int lineheight     = 18;  /* -h option; minimum height of a menu line */
static unsigned int min_lineheight = 8;   /* Minimum height of a line */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 0;

