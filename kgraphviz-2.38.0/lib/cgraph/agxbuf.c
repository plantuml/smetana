#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.c" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/


#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/








/* Extensible buffer:
 *  Malloc'ed memory is never released until agxbfree is called.
 */
    typedef struct {
	unsigned char *buf;	/* start of buffer */
	unsigned char *ptr;	/* next place to write */
	unsigned char *eptr;	/* end of buffer */
	int dyna;		/* true if buffer is malloc'ed */
    } agxbuf;

/* agxbinit:
 * Initializes new agxbuf; caller provides memory.
 * Assume if init is non-null, hint = sizeof(init[])
 */
    extern void agxbinit(agxbuf * xb, unsigned int hint,
			 unsigned char *init);

/* agxbput_n:
 * Append string s of length n into xb
 */
    extern int agxbput_n(agxbuf * xb, const char *s, unsigned int n);

/* agxbput:
 * Append string s into xb
 */
    extern int agxbput(agxbuf * xb, const char *s);

/* agxbfree:
 * Free any malloced resources.
 */
    extern void agxbfree(agxbuf * xb);

/* agxbpop:
 * Removes last character added, if any.
 */
    extern int agxbpop(agxbuf * xb);

/* agxbmore:
 * Expand buffer to hold at least ssz more bytes.
 */
    extern int agxbmore(agxbuf * xb, int unsigned ssz);

/* agxbputc:
 * Add character to buffer.
 *  int agxbputc(agxbuf*, char)
 */



/* agxbuse:
 * Null-terminates buffer; resets and returns pointer to data;
 *  char* agxbuse(agxbuf* xb)
 */


/* agxbstart:
 * Return pointer to beginning of buffer.
 *  char* agxbstart(agxbuf* xb)
 */


/* agxblen:
 * Return number of characters currently stored.
 *  int agxblen(agxbuf* xb)
 */


/* agxbclear:
 * Resets pointer to data;
 *  void agxbclear(agxbuf* xb)
 */


/* agxbnext:
 * Next position for writing.
 *  char* agxbnext(agxbuf* xb)
 */







#line 20 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.c" 2



/* agxbinit:
 * Assume if init is non-null, hint = sizeof(init[])
 */
void agxbinit(agxbuf * xb, unsigned int hint, unsigned char *init)
{
    if (init) {
	xb->buf = init;
	xb->dyna = 0;
    } else {
	if (hint == 0)
	    hint = BUFSIZ;
	xb->dyna = 1;
	xb->buf = (unsigned char*)malloc((hint)*sizeof(unsigned char));
    }
    xb->eptr = xb->buf + hint;
    xb->ptr = xb->buf;
    *xb->ptr = '\0';
}

/* agxbmore;
 * Expand buffer to hold at least ssz more bytes.
 */
int agxbmore(agxbuf * xb, unsigned int ssz)
{
    int cnt;			/* current no. of characters in buffer */
    int size;			/* current buffer size */
    int nsize;			/* new buffer size */
    unsigned char *nbuf;	/* new buffer */

    size = xb->eptr - xb->buf;
    nsize = 2 * size;
    if (size + (int)ssz > nsize)
	nsize = size + ssz;
    cnt = xb->ptr - xb->buf;
    if (xb->dyna) {
	nbuf = realloc(xb->buf, nsize);
    } else {
	nbuf = (unsigned char*)malloc((nsize)*sizeof(unsigned char));
	memcpy(nbuf, xb->buf, cnt);
	xb->dyna = 1;
    }
    xb->buf = nbuf;
    xb->ptr = xb->buf + cnt;
    xb->eptr = xb->buf + nsize;
    return 0;
}

/* agxbput_n:
 * Append string s of length n onto xb
 */
int agxbput_n(agxbuf * xb, const char *s, unsigned int ssz)
{
    if (xb->ptr + ssz > xb->eptr)
	agxbmore(xb, ssz);
    memcpy(xb->ptr, s, ssz);
    xb->ptr += ssz;
    return ssz;
}

/* agxbput:
 * Append string s into xb
 */
int agxbput(agxbuf * xb, const char *s)
{
    unsigned int ssz = strlen(s);

    return agxbput_n(xb, s, ssz);
}

/* agxbfree:
 * Free any malloced resources.
 */
void agxbfree(agxbuf * xb)
{
    if (xb->dyna)
	free(xb->buf);
}

/* agxbpop:
 * Removes last character added, if any.
 */
int agxbpop(agxbuf * xb)
{
    int c;
    if (xb->ptr > xb->buf) {
	c = *xb->ptr--;
	return c;
    } else
	return -1;

}
