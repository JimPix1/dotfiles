#define TLINE(y) ((y) < term.scr ? term.hist[((y) + term.histi - \
                     term.scr + HISTSIZE + 1) % HISTSIZE] : \
                     term.line[(y) - term.scr])

void kscrolldown(const Arg *);
void kscrollup(const Arg *);

