#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 1
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


/*
 * Top-level parsing of gpr code into blocks
 *
 */

#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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










/*	Public header file for the sfio library
**
**	Written by Kiem-Phong Vo
*/




#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
































































/* Sfoff_t should be large enough for largest file address */







	typedef struct _sfio_s Sfio_t;

    typedef struct _sfdisc_s Sfdisc_t;
    typedef ssize_t(*Sfread_f)
	_ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    typedef ssize_t(*Sfwrite_f)
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    typedef _ast_intmax_t(*Sfseek_f) _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    typedef int (*Sfexcept_f) _ARG_((Sfio_t *, int, Void_t *, Sfdisc_t *));

/* discipline structure */
    struct _sfdisc_s {
	Sfread_f readf;		/* read function                */
	Sfwrite_f writef;	/* write function               */
	Sfseek_f seekf;		/* seek function                */
	Sfexcept_f exceptf;	/* to handle exceptions         */
	Sfdisc_t *disc;		/* the continuing discipline    */
    };

/* a file structure */
    struct _sfio_s {
	unsigned char *next;	/* next position to read/write from     */
	unsigned char *endw;	/* end of write buffer                  */
	unsigned char *endr;	/* end of read buffer                   */
	unsigned char *endb;	/* end of buffer                        */
	Sfio_t *push;		/* the stream that was pushed on        */
	unsigned short flags;	/* type of stream                       */
	short file;		/* file descriptor                      */
	unsigned char *data;	/* base of data buffer                  */
	ssize_t size;		/* buffer size                          */
	ssize_t val;		/* values or string lengths             */

	 

    };

/* formatting environment */
    typedef struct _sffmt_s Sffmt_t;
    typedef int (*Sffmtext_f) _ARG_((Sfio_t *, Void_t *, Sffmt_t *));
    typedef int (*Sffmtevent_f)
	_ARG_((Sfio_t *, int, Void_t *, Sffmt_t *));
    struct _sffmt_s {
	long version;		/* version of this structure            */
	Sffmtext_f extf;	/* function to process arguments        */
	Sffmtevent_f eventf;	/* process events                       */

	char *form;		/* format string to stack               */
	va_list args;		/* corresponding arg list               */

	int fmt;		/* format character                     */
	ssize_t size;		/* object size                          */
	int flags;		/* formatting flags                     */
	int width;		/* width of field                       */
	int precis;		/* precision required                   */
	int base;		/* conversion base                      */

	char *t_str;		/* type string                          */
	ssize_t n_str;		/* length of t_str                      */

	Void_t *noop;		/* as yet unused                        */
    };
























/* for sfmutex() call */





/* various constants */













/* bits for various types of files */







    /* but BSDI stat.h now uses this symbol. */
    /* So we leave it out in such cases.    */




















/* for sfgetr/sfreserve to hold a record */



/* exception events: SF_NEW(0), SF_READ(1), SF_WRITE(2) and the below 	*/





    /* but AIX now uses this symbol. So we  */
    /* avoid defining it in such cases.     */














/* for stack and disciplines */



/* for the notify function and discipline exception */






     1 extern ssize_t _Sfi;




/* standard in/out/err streams */
    extern Sfio_t *sfstdin;
    extern Sfio_t *sfstdout;
    extern Sfio_t *sfstderr;
    extern Sfio_t _Sfstdin;
    extern Sfio_t _Sfstdout;
    extern Sfio_t _Sfstderr;















    extern Sfio_t *sfnew _ARG_((Sfio_t *, Void_t *, size_t, int, int));
    extern Sfio_t *sfopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfpopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfstack _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sfswap _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sftmp _ARG_((size_t));
    extern int sfpurge _ARG_((Sfio_t *));
    extern int sfpoll _ARG_((Sfio_t **, int, int));
    extern Void_t *sfreserve _ARG_((Sfio_t *, ssize_t, int));
    extern int sfsync _ARG_((Sfio_t *));
    extern int sfclrlock _ARG_((Sfio_t *));
    extern Void_t *sfsetbuf _ARG_((Sfio_t *, Void_t *, size_t));
    extern Sfdisc_t *sfdisc _ARG_((Sfio_t *, Sfdisc_t *));
    extern int sfraise _ARG_((Sfio_t *, int, Void_t *));
    extern int sfnotify _ARG_((void (*)(Sfio_t *, int, int)));
    extern int sfset _ARG_((Sfio_t *, int, int));
    extern int sfsetfd _ARG_((Sfio_t *, int));
    extern Sfio_t *sfpool _ARG_((Sfio_t *, Sfio_t *, int));
    extern ssize_t sfread _ARG_((Sfio_t *, Void_t *, size_t));
    extern ssize_t sfwrite _ARG_((Sfio_t *, const Void_t *, size_t));
    extern _ast_intmax_t sfmove _ARG_((Sfio_t *, Sfio_t *, _ast_intmax_t, int));
    extern int sfclose _ARG_((Sfio_t *));
    extern _ast_intmax_t sftell _ARG_((Sfio_t *));
    extern _ast_intmax_t sfseek _ARG_((Sfio_t *, _ast_intmax_t, int));
    extern ssize_t sfputr _ARG_((Sfio_t *, const char *, int));
    extern char *sfgetr _ARG_((Sfio_t *, int, int));
    extern ssize_t sfnputc _ARG_((Sfio_t *, int, size_t));
    extern int sfungetc _ARG_((Sfio_t *, int));
    extern int sfprintf _ARG_((Sfio_t *, const char *, ...));
    extern char *sfprints _ARG_((const char *, ...));
    extern int sfsprintf _ARG_((char *, int, const char *, ...));
    extern int sfvsprintf _ARG_((char *, int, const char *, va_list));
    extern int sfvprintf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfscanf _ARG_((Sfio_t *, const char *, ...));
    extern int sfsscanf _ARG_((const char *, const char *, ...));
    extern int sfvsscanf _ARG_((const char *, const char *, va_list));
    extern int sfvscanf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfresize _ARG_((Sfio_t *, _ast_intmax_t));

/* mutex locking for thread-safety */
    extern int sfmutex _ARG_((Sfio_t *, int));

/* io functions with discipline continuation */
    extern ssize_t sfrd _ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    extern ssize_t sfwr
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    extern _ast_intmax_t sfsk _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    extern ssize_t sfpkrd _ARG_((int, Void_t *, size_t, int, long, int));

/* portable handling of primitive types */
    extern int sfdlen _ARG_((_ast_fltmax_t));
    extern int sfllen _ARG_((_ast_intmax_t));
    extern int sfulen _ARG_((unsigned _ast_intmax_t));

    extern int sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int sfputc _ARG_((Sfio_t *, int));

    extern _ast_fltmax_t sfgetd _ARG_((Sfio_t *));
    extern _ast_intmax_t sfgetl _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetu _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetm _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfgetc _ARG_((Sfio_t *));

    extern int _sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int _sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int _sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int _sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int _sfflsbuf _ARG_((Sfio_t *, int));

    extern int _sffilbuf _ARG_((Sfio_t *, int));

    extern int _sfdlen _ARG_((_ast_fltmax_t));
    extern int _sfllen _ARG_((_ast_intmax_t));
    extern int _sfulen _ARG_((unsigned _ast_intmax_t));

/* miscellaneous function analogues of fast in-line functions */
    extern _ast_intmax_t sfsize _ARG_((Sfio_t *));
    extern int sfclrerr _ARG_((Sfio_t *));
    extern int sfeof _ARG_((Sfio_t *));
    extern int sferror _ARG_((Sfio_t *));
    extern int sffileno _ARG_((Sfio_t *));
    extern int sfstacked _ARG_((Sfio_t *));
    extern ssize_t sfvalue _ARG_((Sfio_t *));
    extern ssize_t sfslen _ARG_((void));


     _END_EXTERNS_
/* coding long integers in a portable and compact fashion */




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\ast\\ast.h" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\align.h" 1
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





/* : : generated from features/align.c by iffe version 1999-08-11 : : */


    typedef unsigned long ALIGN_INTEGRAL;
































#line 22 "graphviz-2.38.0\\lib\\ast\\ast.h" 2























/*
 * strgrpmatch() flags
 */






/*
 * fmtquote() flags
 */

















    extern char *pathpath(char *, const char *, const char *, int);
    extern char *pathfind(const char *, const char *, const char *, char *,
			  size_t);
    extern char *pathaccess(char *, const char *, const char *,
			    const char *, int);
    extern char *pathbin(void);
    extern char *pathcat(char *, const char *, int, const char *,
			 const char *);
    extern int pathgetlink(const char *, char *, int);
    extern int pathexists(char *, int);

    extern int chresc(const char *, char **);
    extern int chrtoi(const char *);
    extern char *fmtesq(const char *, const char *);
    extern char *fmtesc(const char *as);
    extern char *fmtbuf(size_t n);
    extern char *fmtquote(const char *, const char *, const char *, size_t,
			  int);

    extern int astquery(int, const char *, ...);

    extern int strmatch(const char *, const char *);
    extern int strgrpmatch(const char *, const char *, int *, int, int);
    extern int stresc(char *);
    extern long strton(const char *, char **, char *, int);
    extern char *strcopy(char *s, const char *t);






#line 22 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 1
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





/*
 * macro interface for sfio write strings
 *
 * NOTE: see <stak.h> for an alternative interface
 *	 read operations require sfseek()
 */




#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 26 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 2

























    extern int sfstrtmp(Sfio_t *, int, void *, size_t);








#line 23 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
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





/*
 * standalone mini error interface
 */




#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1

    typedef struct Error_info_s {
	int errors;
	int indent;
	int line;
	int warnings;
	int trace;
	char *file;
	char *id;
    } Error_info_t;



















    extern Error_info_t _err_info;

    extern void setTraceLevel (int);
    extern void setErrorLine (int);
    extern void setErrorFileLine (char*, int);
    extern void setErrorId (char*);
    extern void setErrorErrors (int);
    extern int  getErrorErrors (void);

    extern void _err_msg(int, ...);
    extern void errorf(void *, void *, int, ...);
    extern void _err_msgv(const char *, int, va_list);






#line 24 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.h" 1
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








    typedef enum { Begin =
	    0, End, BeginG, EndG, Node, Edge, Eof, Error } case_t;

    typedef struct _case_info {
	int gstart;
	char *guard;
	int astart;
	char *action;
	struct _case_info *next;
    } case_info;

    typedef struct _parse_block {
	int l_beging;
	char *begg_stmt;
	int n_nstmts;
	int n_estmts;
	case_info *node_stmts;
	case_info *edge_stmts;
	struct _parse_block *next;
    } parse_block; 

    typedef struct {
	char *source;
	int l_begin, l_end, l_endg;
	char *begin_stmt;
	int n_blocks;
	parse_block *blocks;
	char *endg_stmt;
	char *end_stmt;
    } parse_prog;

    extern parse_prog *parseProg(char *, int);
    extern void freeParseProg (parse_prog *);






#line 25 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.c" 1

static int lineno = 1;		/* current line number */
static int col0 = 1;		/* true if char ptr is at column 0 */
static int startLine = 1;	/* set to start line of bracketd content */
static int kwLine = 1;		/* set to line of keyword */

static char *case_str[] = {
    "BEGIN",
    "END",
    "BEG_G",
    "END_G",
    "N",
    "E",
    "EOF",
    "ERROR",
};

/* caseStr:
 * Convert case_t to string.
 */
static char *caseStr(case_t cs)
{
    return case_str[(int) cs];
}

/* eol:
 * Eat characters until eol.
 */
static int eol (Sfio_t * str, Sfio_t * ostr)
{
    int c;
    while ((c = ( (((Sfio_t*)(str))->next >= ((Sfio_t*)(str))->endr ? _sffilbuf(((Sfio_t*)(str)),0) : (int)(*((Sfio_t*)(str))->next++) ) )) != '\n') {
	if (c < 0)
	    return c;
    }
    lineno++;
    col0 = 1;
    if (ostr)
	( (((Sfio_t*)((ostr)))->next >= ((Sfio_t*)((ostr)))->endw ? _sfflsbuf(((Sfio_t*)((ostr))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ostr)))->next++ = (unsigned char)((c))) ) );
    return c;
}

/* readc:
 * return character from input stream
 * while keeping track of line number.
 * Strip out comments, and return space or newline.
 * If a newline is seen in comment and ostr
 * is non-null, add newline to ostr.
 */
static int readc(Sfio_t * str, Sfio_t * ostr)
{
    int c;
    int cc;

    switch (c = ( (((Sfio_t*)(str))->next >= ((Sfio_t*)(str))->endr ? _sffilbuf(((Sfio_t*)(str)),0) : (int)(*((Sfio_t*)(str))->next++) ) )) {
    case '\n':
	lineno++;
        col0 = 1;
	break;
    case '#':
	if (col0) { /* shell comment */
	    c = eol (str, ostr);
	}
	else col0 = 0;
	break;
    case '/':
	cc = ( (((Sfio_t*)(str))->next >= ((Sfio_t*)(str))->endr ? _sffilbuf(((Sfio_t*)(str)),0) : (int)(*((Sfio_t*)(str))->next++) ) );
	switch (cc) {
	case '*':		/* in C comment   */
	    while (1) {
		switch (c = ( (((Sfio_t*)(str))->next >= ((Sfio_t*)(str))->endr ? _sffilbuf(((Sfio_t*)(str)),0) : (int)(*((Sfio_t*)(str))->next++) ) )) {
		case '\n':
		    lineno++;
		    if (ostr)
			( (((Sfio_t*)((ostr)))->next >= ((Sfio_t*)((ostr)))->endw ? _sfflsbuf(((Sfio_t*)((ostr))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ostr)))->next++ = (unsigned char)((c))) ) );
		    break;
		case '*':
		    switch (cc = ( (((Sfio_t*)(str))->next >= ((Sfio_t*)(str))->endr ? _sffilbuf(((Sfio_t*)(str)),0) : (int)(*((Sfio_t*)(str))->next++) ) )) {
		    case -1:
			return cc;
			break;
		    case '\n':
			lineno++;
			if (ostr)
			    ( (((Sfio_t*)((ostr)))->next >= ((Sfio_t*)((ostr)))->endw ? _sfflsbuf(((Sfio_t*)((ostr))),(int)((unsigned char)((cc)))) : (int)(*((Sfio_t*)((ostr)))->next++ = (unsigned char)((cc))) ) );
			break;
		    case '*':
			sfungetc(str, cc);
			break;
		    case '/':
			col0 = 0;
			return ' ';
			break;
		    }
		}
	    }
	    break;
	case '/':		/* in C++ comment */
	    c = eol (str, ostr);
	    break;
	default:		/* not a comment  */
	    if (cc >= '\0')
		sfungetc(str, cc);
	    break;
	}
	break;
    default:
        col0 = 0;
	break;
    }
    return c;
}

/* unreadc;
 * push character back onto stream;
 * if newline, reduce lineno.
 */
void unreadc(Sfio_t * str, int c)
{
    sfungetc(str, c);
    if (c == '\n')
	lineno--;
}

/* skipWS:
 */
static int skipWS(Sfio_t * str)
{
    int c;

    while (1) {
	c = readc(str, 0);
	if (!isspace(c)) {
	    return c;
	}
    }
}

/* parseID:
 * Put initial alpha in buffer;
 * add additional alphas, up to buffer size.
 */
static void parseID(Sfio_t * str, int c, char *buf, size_t bsize)
{
    int more = 1;
    char *ptr = buf;
    char *eptr = buf + (bsize - 1);

    *ptr++ = c;
    while (more) {
	c = readc(str, 0);
	if (c < 0)
	    more = 0;
	if (isalpha(c) || (c == '_')) {
	    if (ptr == eptr)
		more = 0;
	    else
		*ptr++ = c;
	} else {
	    more = 0;
	    unreadc(str, c);
	}
    }
    *ptr = '\0';

}



/* parseKind:
 * Look for keywords: BEGIN, END, BEG_G, END_G, N, E
 * As side-effect, sets kwLine to line of keyword.
 */
static case_t parseKind(Sfio_t * str)
{
    int c;
    char buf[8];
    case_t cs = Error;

    c = skipWS(str);
    if (c < 0)
	return Eof;
    if (!isalpha(c)) {
	_err_msg(2,
	      "expected keyword BEGIN/END/N/E...; found '%c', line %d", c,
	      lineno);
	return Error;
    }

    kwLine = lineno;
    parseID(str, c, buf, 8);
    switch (c) {
    case 'B':
	if (strcmp(buf, "BEGIN") == 0)
	    cs = Begin;
	if (strcmp(buf, "BEG_G") == 0)
	    cs = BeginG;
	break;
    case 'E':
	if (buf[1] == '\0')
	    cs = Edge;
	if (strcmp(buf, "END") == 0)
	    cs = End;
	if (strcmp(buf, "END_G") == 0)
	    cs = EndG;
	break;
    case 'N':
	if (buf[1] == '\0')
	    cs = Node;
	break;
    }
    if (cs == Error)
	_err_msg(2, "unexpected keyword \"%s\", line %d", buf,
	      kwLine);
    return cs;
}

/* endString:
 * eat characters from ins, putting them into outs,
 * up to and including a terminating character ec
 * that is not escaped with a back quote.
 */
static int endString(Sfio_t * ins, Sfio_t * outs, char ec)
{
    int sline = lineno;
    int c;

    while ((c = ( (((Sfio_t*)(ins))->next >= ((Sfio_t*)(ins))->endr ? _sffilbuf(((Sfio_t*)(ins)),0) : (int)(*((Sfio_t*)(ins))->next++) ) )) != ec) {
	if (c == '\\') {
	    ( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)((c))) ) );
	    c = ( (((Sfio_t*)(ins))->next >= ((Sfio_t*)(ins))->endr ? _sffilbuf(((Sfio_t*)(ins)),0) : (int)(*((Sfio_t*)(ins))->next++) ) );
	}
	if (c < 0) {
	    _err_msg(2, "unclosed string, start line %d", sline);
	    return c;
	}
	if (c == '\n')
	    lineno++;
	( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)(((char) c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)(((char) c))) ) );
    }
    ( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)((c))) ) );
    return 0;
}

/* endBracket:
 * eat characters from ins, putting them into outs,
 * up to a terminating character ec.
 * Strings are treated as atomic units: any ec in them
 * is ignored. Since matching bc-ec pairs might nest,
 * the function is called recursively.
 */
static int endBracket(Sfio_t * ins, Sfio_t * outs, char bc, char ec)
{
    int c;

    while (1) {
	c = readc(ins, outs);
	if ((c < 0) || (c == ec))
	    return c;
	else if (c == bc) {
	    ( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)(((char) c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)(((char) c))) ) );
	    c = endBracket(ins, outs, bc, ec);
	    if (c < 0)
		return c;
	    else
		( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)(((char) c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)(((char) c))) ) );
	} else if ((c == '\'') || (c == '"')) {
	    ( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)(((char) c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)(((char) c))) ) );
	    if (endString(ins, outs, c)) return -1;
	} else
	    ( (((Sfio_t*)((outs)))->next >= ((Sfio_t*)((outs)))->endw ? _sfflsbuf(((Sfio_t*)((outs))),(int)((unsigned char)(((char) c)))) : (int)(*((Sfio_t*)((outs)))->next++ = (unsigned char)(((char) c))) ) );
    }
}

/* parseBracket:
 *  parse paired expression : bc <string> ec
 *  returning <string>
 * As a side-effect, set startLine to beginning of content.
 */
static char *parseBracket(Sfio_t * str, Sfio_t * buf, int bc, int ec)
{
    int c;

    c = skipWS(str);
    if (c < 0)
	return 0;
    if (c != bc) {
	unreadc(str, c);
	return 0;
    }
    startLine = lineno;
    c = endBracket(str, buf, bc, ec);
    if (c < 0) {
	if (!getErrorErrors())
	    _err_msg(2,
	      "unclosed bracket %c%c expression, start line %d", bc, ec,
	      startLine);
	return 0;
    }
    else
	return strdup((( (((Sfio_t*)((buf)))->next >= ((Sfio_t*)((buf)))->endw ? _sfflsbuf(((Sfio_t*)((buf))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((buf)))->next++ = (unsigned char)((0))) ) ), (char*)((buf)->next = (buf)->data) ));
}

/* parseAction:
 */
static char *parseAction(Sfio_t * str, Sfio_t * buf)
{
    return parseBracket(str, buf, '{', '}');
}

/* parseGuard:
 */
static char *parseGuard(Sfio_t * str, Sfio_t * buf)
{
    return parseBracket(str, buf, '[', ']');
}

/* parseCase:
 * Recognize
 *   BEGIN <optional action>
 *   END <optional action>
 *   BEG_G <optional action>
 *   END_G <optional action>
 *   N <optional guard> <optional action>
 *   E <optional guard> <optional action>
 * where
 *   guard = '[' <expr> ']'
 *   action = '{' <expr> '}'
 */
static case_t
parseCase(Sfio_t * str, char **guard, int *gline, char **action,
	  int *aline)
{
    case_t kind;

    Sfio_t *buf = sfnew((Sfio_t*)0,(char*)0,-1,-1,0000002|0000004);

    kind = parseKind(str);
    switch (kind) {
    case Begin:
    case BeginG:
    case End:
    case EndG:
	*action = parseAction(str, buf);
	*aline = startLine;
	if (getErrorErrors ())
	    kind = Error;
	break;
    case Edge:
    case Node:
	*guard = parseGuard(str, buf);
	*gline = startLine;
	if (!getErrorErrors ()) {
	    *action = parseAction(str, buf);
	    *aline = startLine;
	}
	if (getErrorErrors ())
	    kind = Error;
	break;
    case Eof:
    case Error:		/* to silence warnings */
	break;
    }

    sfclose(buf);
    return kind;
}

/* addBlock:
 * create new block and append to list;
 * return new item as tail
 */
static parse_block *addBlock (parse_block * last, char *stmt, int line,
	int n_nstmts, case_info *nodelist, int n_estmts, case_info *edgelist)
{
    parse_block* item = ((0)?(parse_block*)realloc((char*)(0),sizeof(parse_block)*(1)+(0)):(parse_block*)calloc(1,sizeof(parse_block)*(1)+(0)));

    item->l_beging = line;
    item->begg_stmt = stmt;
    item->n_nstmts = n_nstmts;
    item->n_estmts = n_estmts;
    item->node_stmts = nodelist;
    item->edge_stmts = edgelist;
    if (last)
	last->next = item;

    return item;
}

/* addCase:
 * create new case_info and append to list;
 * return new item as tail
 */
static case_info *addCase(case_info * last, char *guard, int gline,
			  char *action, int line, int *cnt)
{
    case_info *item;

    if (!guard && !action) {
	_err_msg(1,
	      "Case with neither guard nor action, line %d - ignored",
	      kwLine);
	return last;
    }

    *cnt = (*cnt) + 1;
    item = ((0)?(case_info*)realloc((char*)(0),sizeof(case_info)*(1)+(0)):(case_info*)calloc(1,sizeof(case_info)*(1)+(0)));
    item->guard = guard;
    item->action = action;
    item->next = 0;
    if (guard)
	item->gstart = gline;
    if (action)
	item->astart = line;

    if (last)
	last->next = item;

    return item;
}

/* bindAction:
 *
 */
static void
bindAction(case_t cs, char *action, int aline, char **ap, int *lp)
{
    if (!action)
	_err_msg(1, "%s with no action, line %d - ignored",
	      caseStr(cs), kwLine);
    else if (*ap)
	_err_msg(2, "additional %s section, line %d", caseStr(cs),
	      kwLine);
    else {
	*ap = action;
	*lp = aline;
    }
}

/* parseProg:
 * Parses input into gpr sections.
 */
parse_prog *parseProg(char *input, int isFile)
{
    parse_prog *prog;
    Sfio_t *str;
    char *mode;
    char *guard = 0;
    char *action = 0;
    int more;
    parse_block *blocklist = 0;
    case_info *edgelist = 0;
    case_info *nodelist = 0;
    parse_block *blockl = 0;
    case_info *edgel = 0;
    case_info *nodel = 0;
    int n_blocks = 0;
    int n_nstmts = 0;
    int n_estmts = 0;
    int line = 0, gline = 0;
    int l_beging = 0;
    char *begg_stmt;

    
    lineno = col0 = startLine = kwLine = 1;
    prog = ((0)?(parse_prog*)realloc((char*)(0),sizeof(parse_prog)*(1)+(0)):(parse_prog*)calloc(1,sizeof(parse_prog)*(1)+(0)));
    if (!prog) {
	_err_msg(2, "parseProg: out of memory");
	return 0;
    }

    if (isFile) {
	mode = "r";
	prog->source = input;
	
    } else {
	mode = "rs";
	prog->source = 0;	/* command line */
    }

    str = sfopen(0, input, mode);
    if (!str) {
	if (isFile)
	    _err_msg(2, "could not open %s for reading", input);
	else
	    _err_msg(2, "parseProg : unable to create sfio stream");
	free (prog);
	return 0;
    }
    
    begg_stmt = 0;
    more = 1;
    while (more) {
	switch (parseCase(str, &guard, &gline, &action, &line)) {
	case Begin:
	    bindAction(Begin, action, line, &(prog->begin_stmt),
		       &(prog->l_begin));
	    break;
	case BeginG:
	    if (action && (begg_stmt || nodelist || edgelist)) { /* non-empty block */
		blockl = addBlock(blockl, begg_stmt, l_beging, 
		    n_nstmts, nodelist, n_estmts, edgelist);
	 	if (!blocklist)
		    blocklist = blockl;
		n_blocks++;

		/* reset values */
		n_nstmts = n_estmts = 0;
		edgel = nodel = edgelist = nodelist = 0;
		begg_stmt = 0;
	    }
	    bindAction(BeginG, action, line, &begg_stmt, &l_beging);
	    break;
	case End:
	    bindAction(End, action, line, &(prog->end_stmt),
		       &(prog->l_end));
	    break;
	case EndG:
	    bindAction(EndG, action, line, &(prog->endg_stmt),
		       &(prog->l_endg));
	    break;
	case Eof:
	    more = 0;
	    break;
	case Node:
	    nodel = addCase(nodel, guard, gline, action, line, &n_nstmts);
	    if (!nodelist)
		nodelist = nodel;
	    break;
	case Edge:
	    edgel = addCase(edgel, guard, gline, action, line, &n_estmts);
	    if (!edgelist)
		edgelist = edgel;
	    break;
	case Error:		/* to silence warnings */
	    more = 0;
	    break;
	}
    }

    if (begg_stmt || nodelist || edgelist) { /* non-empty block */
	blockl = addBlock(blockl, begg_stmt, l_beging, 
	    n_nstmts, nodelist, n_estmts, edgelist);
	if (!blocklist)
	    blocklist = blockl;
	n_blocks++;
    }

    prog->n_blocks = n_blocks;
    prog->blocks = blocklist;

    sfclose(str);

    if (getErrorErrors ()) {
	freeParseProg (prog);
	prog = 0;
    }

    return prog;
}

static void
freeCaseList (case_info* ip)
{
    case_info* nxt;
    while (ip) {
	nxt = ip->next;
	free (ip->guard);
	free (ip->action);
	free (ip);
	ip = nxt;
    }
}

static void
freeBlocks (parse_block* ip)
{
    parse_block* nxt;
    while (ip) {
	nxt = ip->next;
	free (ip->begg_stmt);
	freeCaseList (ip->node_stmts);
	freeCaseList (ip->edge_stmts);
	ip = nxt;
    }
}

void 
freeParseProg (parse_prog * prog)
{
    if (!prog) return;
    free (prog->begin_stmt);
    freeBlocks (prog->blocks);
    free (prog->endg_stmt);
    free (prog->end_stmt);
    free (prog);
}

