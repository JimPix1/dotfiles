void
nrowgrid(Monitor *m)
{
    unsigned int n = 0, i = 0, ri = 0, ci = 0;  /* counters */
    unsigned int cx, cy, cw, ch;                /* client geometry */
    unsigned int uw = 0, uh = 0, uc = 0;        /* utilization trackers */
    unsigned int cols, rows = m->nmaster + 1;
    Client *c;

    /* count clients */
    for (c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);

    /* nothing to do here */
    if (n == 0)
        return;

    /* force 2 clients to always split vertically */
    if (FORCE_VSPLIT && n == 2)
        rows = 1;

    /* never allow empty rows */
    if (n < rows)
        rows = n;

    /* define first row */
    cols = n / rows;
    uc = cols;
    cy = m->wy;
    ch = m->wh / rows;
    uh = ch;

    for (c = nexttiled(m->clients); c; c = nexttiled(c->next), i++, ci++) {
        if (ci == cols) {
            uw = 0;
            ci = 0;
            ri++;

            /* next row */
            cols = (n - uc) / (rows - ri);
            uc += cols;
            cy = m->wy + uh;
            ch = (m->wh - uh) / (rows - ri);
            uh += ch;
        }

        cx = m->wx + uw;
        cw = (m->ww - uw) / (cols - ci);
        uw += cw;

        resize(c, cx, cy, cw - 2 * c->bw, ch - 2 * c->bw, 0);
    }
}
