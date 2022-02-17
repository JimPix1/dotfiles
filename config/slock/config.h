/* user and group to drop privileges to */
static const char *user  = "matt";
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",    /* after initialization */
	[INPUT] =  "#84a0c6",  /* during input */
	[FAILED] = "#e8a2af",  /* wrong password */

	/* defaults */
//	[INIT] =   "black",    /* after initialization */
//	[INPUT] =  "#005577",  /* during input */
//	[FAILED] = "#CC3333",  /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

