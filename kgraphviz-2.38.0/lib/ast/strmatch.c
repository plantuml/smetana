#line 1 "graphviz-2.38.0\\lib\\ast\\strmatch.c" 1
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
 * D. G. Korn
 * G. S. Fowler
 * AT&T Research
 *
 * match shell file patterns -- derived from Bourne and Korn shell gmatch()
 *
 *	sh pattern	egrep RE	description
 *	----------	--------	-----------
 *	*		.*		0 or more chars
 *	?		.		any single char
 *	[.]		[.]		char class
 *	[!.]		[^.]		negated char class
 *	[[:.:]]		[[:.:]]		ctype class
 *	[[=.=]]		[[=.=]]		equivalence class
 *	[[...]]		[[...]]		collation element
 *	*(.)		(.)*		0 or more of
 *	+(.)		(.)+		1 or more of
 *	?(.)		(.)?		0 or 1 of
 *	(.)		(.)		1 of
 *	@(.)		(.)		1 of
 *	a|b		a|b		a or b
 *	\#				() subgroup back reference [1-9]
 *	a&b				a and b
 *	!(.)				none of
 *
 * \ used to escape metacharacters
 *
 *	*, ?, (, |, &, ), [, \ must be \'d outside of [...]
 *	only ] must be \'d inside [...]
 *
 * BUG: unbalanced ) terminates top level pattern
 *
 * BOTCH: collating element sort order and character class ranges apparently
 *	  do not have strcoll() in common so we resort to fnmatch(), calling
 *	  it up to COLL_MAX times to determine the matched collating
 *	  element size
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






#line 56 "graphviz-2.38.0\\lib\\ast\\strmatch.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\strmatch.c" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\hashkey.h" 1
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
 * Glenn Fowler
 * AT&T Research
 *
 * 1-6 char lower-case keyword -> long hash
 * digit args passed as HASHKEYN('2')
 */




























    extern long strkey(const char *);








#line 58 "graphviz-2.38.0\\lib\\ast\\strmatch.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\strmatch.c" 1






































    
    

    
	
	
    
    
























typedef struct {
    char *beg[10];
    char *end[10];
    char *next_s;
    short groups;
} Group_t;

typedef struct {
    Group_t current;
    Group_t best;
    char *last_s;
    char *next_p;
} Match_t;























/*
 * gobble chars up to <sub> or ) keeping track of (...) and [...]
 * sub must be one of { '|', '&', 0 }
 * 0 returned if s runs out
 */

static char *gobble(Match_t * mp, register char *s, register int sub,
		    int *g, int clear)
{
    register int p = 0;
    register char *b = 0;
    int c = 0;
    int n;

    for (;;)
	switch ((*s++)) {
	case '\\':
	    if ((*s++))
		break;
	 /*FALLTHROUGH*/ case 0:
	    return 0;
	case '[':
	    if (!b) {
		if (*s == '!')
		    (void)(*s++);
		b = s;
	    } else if (*s == '.' || *s == '=' || *s == ':')
		c = *s;
	    break;
	case ']':
	    if (b) {
		if (*(s - 2) == c)
		    c = 0;
		else if (b != (s - 1))
		    b = 0;
	    }
	    break;
	case '(':
	    if (!b) {
		p++;
		n = (*g)++;
		if (clear) {
		    if (!sub)
			n++;
		    if (n < 10)
			mp->current.beg[n] = mp->current.end[n] = 0;
		}
	    }
	    break;
	case ')':
	    if (!b && p-- <= 0)
		return sub ? 0 : s;
	    break;
	case '|':
	    if (!b && !p && sub == '|')
		return s;
	    break;
	}
}

static int grpmatch(Match_t *, int, char *, register char *, char *, int);







/*
 * match a single pattern
 * e is the end (0) of the substring in s
 * r marks the start of a repeated subgroup pattern
 */

static int
onematch(Match_t * mp, int g, char *s, char *p, char *e, char *r,
	 int flags)
{
    register int pc;
    register int sc;
    register int n;
    register int icase;
    char *olds;
    char *oldp;


    
    
	  

    icase = flags & 010;
    do {
	olds = s;
	sc = (((s)>=(e))?0:(*s++));
	if (icase && isupper(sc))
	    sc = tolower(sc);
	oldp = p;
	switch (pc = (*p++)) {
	case '(':
	case '*':
	case '?':
	case '+':
	case '@':
	case '!':
	    if (pc == '(' || *p == '(') {
		char *subp;
		int oldg;

		s = olds;
		subp = p + (pc != '(');
		oldg = g;
		n = ++g;
		if (g < 10 && (!r || g > mp->current.groups))
		    mp->current.beg[g] = mp->current.end[g] = 0;
		if (!(p = gobble(mp, subp, 0, &g, !r)))
		    {return (0);};
		if (pc == '*' || pc == '?' || (pc == '+' && oldp == r)) {
		    if (onematch(mp, g, s, p, e, 0, flags))
			{return (1);};
		    if (!sc || !(((s)>=(e))?0:(*s++))) {
			mp->current.groups = oldg;
			{return (0);};
		    }
		}
		if (pc == '*' || pc == '+') {
		    p = oldp;
		    sc = n - 1;
		} else
		    sc = g;
		pc = (pc != '!');
		do {
		    if (grpmatch(mp, n, olds, subp, s, flags) == pc) {
			if (n < 10) {
			    if (!mp->current.beg[n]
				|| mp->current.beg[n] > olds)
				mp->current.beg[n] = olds;
			    if (s > mp->current.end[n])
				mp->current.end[n] = s;

			    
				  
				  
				  
				  

			}
			if (onematch(mp, sc, s, p, e, oldp, flags)) {
			    if (p == oldp && n < 10) {
				if (!mp->current.beg[n]
				    || mp->current.beg[n] > olds)
				    mp->current.beg[n] = olds;
				if (s > mp->current.end[n])
				    mp->current.end[n] = s;

				
				      
				      
				      
				      
				      

			    }
			    {return (1);};
			}
		    }
		} while (s < e && (*s++));
		mp->current.groups = oldg;
		{return (0);};
	    } else if (pc == '*') {
		/*
		 * several stars are the same as one
		 */

		while (*p == '*' && *(p + 1) != '(')
		    p++;
		oldp = p;
		switch (pc = (*p++)) {
		case '@':
		case '!':
		case '+':
		    n = *p == '(';
		    break;
		case '(':
		case '[':
		case '?':
		case '*':
		    n = 1;
		    break;
		case 0:
		case '|':
		case '&':
		case ')':
		    mp->current.next_s = (flags & 01) ? e : olds;
		    mp->next_p = oldp;
		    mp->current.groups = g;
		    if (!pc
			&& (!mp->best.next_s
			    || ((flags & 01)
				&& mp->current.next_s > mp->best.next_s)
			    || (!(flags & 01)
				&& mp->current.next_s <
				mp->best.next_s))) {
			mp->best = mp->current;

			
			      

		    }
		    {return (1);};
		case '\\':
		    if (!(pc = (*p++)))
			{return (0);};
		    if (pc >= '0' && pc <= '9') {
			n = pc - '0';

			
			      
			      
			      
			      

			if (n <= g && mp->current.beg[n])
			    pc = *mp->current.beg[n];
		    }
		/*FALLTHROUGH*/ default:
		    if (icase && isupper(pc))
			pc = tolower(pc);
		    n = 0;
		    break;
		}
		p = oldp;
		for (;;) {
		    if ((n || pc == sc)
			&& onematch(mp, g, olds, p, e, 0, flags))
			{return (1);};
		    if (!sc)
			{return (0);};
		    olds = s;
		    sc = (((s)>=(e))?0:(*s++));
		    if ((flags & 010) && isupper(sc))
			sc = tolower(sc);
		}
	    } else if (pc != '?' && pc != sc)
		{return (0);};
	    break;
	case 0:
	    if (!(flags & 01))
		sc = 0;
	 /*FALLTHROUGH*/ case '|':
	case '&':
	case ')':
	    if (!sc) {
		mp->current.next_s = olds;
		mp->next_p = oldp;
		mp->current.groups = g;
	    }
	    if (!pc
		&& (!mp->best.next_s
		    || ((flags & 01) && olds > mp->best.next_s)
		    || (!(flags & 01)
			&& olds < mp->best.next_s))) {
		mp->best = mp->current;
		mp->best.next_s = olds;
		mp->best.groups = g;

		
		      

	    }
	    {return (!sc);};
	case '[':
	    {
		/*UNDENT... */

		int invert;
		int x;
		int ok = 0;
		char *range;

		if (!sc)
		    {return (0);};

		
		    
		

		    range = 0;
		n = 0;
		if ((invert = (*p == '!')))
		    p++;
		for (;;) {
		    oldp = p;
		    if (!(pc = (*p++))) {
			{return (0);};
		    } else if (pc == '['
			       && (*p == ':' || *p == '=' || *p == '.')) {
			x = 0;
			n = (*p++);
			oldp = p;
			for (;;) {
			    if (!(pc = (*p++)))
				{return (0);};
			    if (pc == n && *p == ']')
				break;
			    x++;
			}
			(void)(*p++);
			if (ok)
			    /*NOP*/;
			else if (n == ':') {
			    switch (((((((((((((((((((x)+'a')-('a'-1)))<<5)+((oldp[0])-('a'-1))))<<5)+((oldp[1])-('a'-1))))<<5)+((oldp[2])-('a'-1))))<<5)+((oldp[3])-('a'-1))))<<5)+((
 oldp[4])-('a'-1)))) {
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('a')-('a'-1))))<<5)+(('l')-('a'-1))))<<5)+(('n')-('a'-1))))<<5)+(('u')-('a'-1))))<<5)+(('m')-('a'-1))):
				if (isalnum(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('a')-('a'-1))))<<5)+(('l')-('a'-1))))<<5)+(('p')-('a'-1))))<<5)+(('h')-('a'-1))))<<5)+(('a')-('a'-1))):
				if (isalpha(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('b')-('a'-1))))<<5)+(('l')-('a'-1))))<<5)+(('a')-('a'-1))))<<5)+(('n')-('a'-1))))<<5)+(('k')-('a'-1))):
				if (((sc)==' '||(sc)=='\t'))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('c')-('a'-1))))<<5)+(('n')-('a'-1))))<<5)+(('t')-('a'-1))))<<5)+(('r')-('a'-1))))<<5)+(('l')-('a'-1))):
				if (iscntrl(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('d')-('a'-1))))<<5)+(('i')-('a'-1))))<<5)+(('g')-('a'-1))))<<5)+(('i')-('a'-1))))<<5)+(('t')-('a'-1))):
				if (isdigit(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('g')-('a'-1))))<<5)+(('r')-('a'-1))))<<5)+(('a')-('a'-1))))<<5)+(('p')-('a'-1))))<<5)+(('h')-('a'-1))):
				if ((isprint(sc)&&!((sc)==' '||(sc)=='\t')))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('l')-('a'-1))))<<5)+(('o')-('a'-1))))<<5)+(('w')-('a'-1))))<<5)+(('e')-('a'-1))))<<5)+(('r')-('a'-1))):
				if (islower(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('p')-('a'-1))))<<5)+(('r')-('a'-1))))<<5)+(('i')-('a'-1))))<<5)+(('n')-('a'-1))))<<5)+(('t')-('a'-1))):
				if (isprint(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('p')-('a'-1))))<<5)+(('u')-('a'-1))))<<5)+(('n')-('a'-1))))<<5)+(('c')-('a'-1))))<<5)+(('t')-('a'-1))):
				if (ispunct(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('s')-('a'-1))))<<5)+(('p')-('a'-1))))<<5)+(('a')-('a'-1))))<<5)+(('c')-('a'-1))))<<5)+(('e')-('a'-1))):
				if (isspace(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((5)+'a')-('a'-1)))<<5)+(('u')-('a'-1))))<<5)+(('p')-('a'-1))))<<5)+(('p')-('a'-1))))<<5)+(('e')-('a'-1))))<<5)+(('r')-('a'-1))):
				if (icase ? islower(sc) : isupper(sc))
				    ok = 1;
				break;
			    case ((((((((((((((((((6)+'a')-('a'-1)))<<5)+(('x')-('a'-1))))<<5)+(('d')-('a'-1))))<<5)+(('i')-('a'-1))))<<5)+(('g')-('a'-1))))<<5)+(('i')-('a'-1))):
				if (oldp[5] == 't' && (((sc)>='0'&&(sc)<='9')||((sc)>='a'&&(sc)<='f')||((sc)>='A'&&(sc)<='F')))
				    ok = 1;
				break;

			    
				
				    

				    
					
				    
				    
				    
					
				
				

			    }
			}

			
			    

			else if (range)
			    goto getrange;
			else if (*p == '-' && *(p + 1) != ']') {
			    (void)(*p++);
			    range = oldp;
			} else
			    if ((isalpha(*oldp) && isalpha(*olds)
				 && tolower(*oldp) == tolower(*olds))
				|| sc == (*oldp++))
			    ok = 1;
			n = 1;
		    } else if (pc == ']' && n) {

			
			    
			    

			    
				
			    
			    
			    
			    
				
			    
			    
			    
				 
				
				
				
				    
				
				    
			    
			    
			    
			

			if (ok != invert)
			    break;
			{return (0);};
		    } else if (pc == '\\'
			       && (oldp = p, !(pc = (*p++)))) {
			{return (0);};
		    } else if (ok)
			/*NOP*/;

		    
			     

		    else if (range)

		    {
		      getrange:

			
			    
			    
			    
			    
			    
			    

			    
			    
			    
			    
				
			    
				
				    
				    
				
				    
			    
			
			

			    if (icase && isupper(pc))
				pc = tolower(pc);
			x = (*range++);
			if (icase && isupper(x))
			    x = tolower(x);
			if (sc == x || sc == pc || (sc > x && sc < pc))
			    ok = 1;
			if (*p == '-' && *(p + 1) != ']') {
			    (void)(*p++);
			    range = oldp;
			} else
			    range = 0;
			n = 1;
		    } else if (*p == '-' && *(p + 1) != ']') {
			(void)(*p++);

			
			    
			

			    range = oldp;
			n = 1;
		    } else {
			if (icase && isupper(pc))
			    pc = tolower(pc);
			if (sc == pc)
			    ok = 1;
			n = pc;
		    }
		}

		/*...INDENT */
	    }
	    break;
	case '\\':
	    if (!(pc = (*p++)))
		{return (0);};
	    if (pc >= '0' && pc <= '9') {
		n = pc - '0';

		
		      
		      
		      

		if (n <= g && (oldp = mp->current.beg[n])) {
		    while (oldp < mp->current.end[n])
			if (!*olds || *olds++ != *oldp++)
			    {return (0);};
		    s = olds;
		    break;
		}
	    }
	/*FALLTHROUGH*/ default:
	    if (icase && isupper(pc))
		pc = tolower(pc);
	    if (pc != sc)
		{return (0);};
	    break;
	}
    } while (sc);
    {return (0);};
}

/*
 * match any pattern in a group
 * | and & subgroups are parsed here
 */

static int
grpmatch(Match_t * mp, int g, char *s, register char *p, char *e,
	 int flags)
{
    register char *a;


    
    
	  

    do {
	for (a = p; onematch(mp, g, s, a, e, 0, flags); a++)
	    if (*(a = mp->next_p) != '&')
		{return (1);};
    } while ((p = gobble(mp, p, '|', &g, 1)));
    {return (0);};
}

/*
 * subgroup match
 * 0 returned if no match
 * otherwise number of subgroups matched returned
 * match group begin offsets are even elements of sub
 * match group end offsets are odd elements of sub
 * the matched string is from s+sub[0] up to but not
 * including s+sub[1]
 */

int strgrpmatch(const char *b, const char *p, int *sub, int n, int flags)
{
    register int i;
    register char *s;
    char *e;
    Match_t match;

    s = (char *) b;
    match.last_s = e = s + strlen(s);
    for (;;) {
	match.best.next_s = 0;
	match.current.groups = 0;
	match.current.beg[0] = 0;
	if ((i = grpmatch(&match, 0, s, (char *) p, e, flags))
	    || match.best.next_s) {
	    if (!(flags & 04) || (match.current.next_s == e)) {
		if (!i)
		    match.current = match.best;
		match.current.groups++;
		match.current.end[0] = match.current.next_s;

		
		      
		      
		      

		break;
	    }
	}
	if ((flags & 02) || s >= e)
	    return 0;
	s++;
    }
    if ((flags & 04) && match.current.next_s != e)
	return 0;
    if (!sub)
	return 1;
    match.current.beg[0] = s;
    s = (char *) b;
    if (n > match.current.groups)
	n = match.current.groups;
    for (i = 0; i < n; i++) {
	sub[i * 2] = match.current.end[i] ? match.current.beg[i] - s : 0;
	sub[i * 2 + 1] =
	    match.current.end[i] ? match.current.end[i] - s : 0;
    }
    return n;
}

/*
 * compare the string s with the shell pattern p
 * returns 1 for match 0 otherwise
 */

int strmatch(const char *s, const char *p)
{
    return strgrpmatch(s, p, 0, 0, 01 | 02 | 04);
}

/*
 * leading substring match
 * first char after end of substring returned
 * 0 returned if no match
 *
 * OBSOLETE: use strgrpmatch()
 */

char *strsubmatch(const char *s, const char *p, int flags)
{
    int match[2];

    return strgrpmatch(s, p, match, 1,
		       (flags ? 01 : 0) | 02) ? (char *) s +
	match[1] : (char *) 0;
}
