#line 1 "graphviz-2.38.0\\lib\\expr\\exeval.c" 1
/* vim:set shiftwidth=4 ts=4: */

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
 * expression library evaluator
 */


#line 1 "graphviz-2.38.0\\lib\\expr\\exeval.c" 1






#line 1 "graphviz-2.38.0\\lib\\expr\\exlib.h" 1
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
 * expression library private definitions
 */




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
































#line 26 "graphviz-2.38.0\\lib\\expr\\exlib.h" 2
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






#line 27 "graphviz-2.38.0\\lib\\expr\\exlib.h" 2








typedef struct Exinput_s		/* input stack			*/
{
	struct Exinput_s*next;		/* next in stack		*/
	int		close;		/* close fp on pop		*/
	char*		file;		/* previous file		*/
	Sfio_t*		fp;		/* expression file pointer	*/
	int		line;		/* previous line		*/
	int		nesting;	/* expression nesting level	*/
	int		peek;		/* 1 char peek			*/
	int		unit;		/* first frame in parse unit	*/
	char*		pushback;	/* pushback buffer		*/
	char*		bp;		/* expression string base	*/
	char*		pp;		/* pushback pointer		*/
	char*		sp;		/* expression string pointer	*/
} Exinput_t;

typedef struct Print_s			/* compiled printf arg node	*/
{
	struct Print_s*	next;		/* next arg			*/
	char*		format;		/* printf format for arg	*/
	struct Exnode_s*param[3];	/* 0:width 1:precision 2:base	*/
	struct Exnode_s*arg;		/* arg to format		*/
} Print_t;






































































#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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
 * expression library definitions
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
































































    
    
			  
    
			    
    
    
			 
    
    

    
    
    
    
    
    
			  

    

    
    
    
    
    






#line 26 "graphviz-2.38.0\\lib\\expr\\expr.h" 2










/*
 * bison -pPREFIX misses YYSTYPE
 */




#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1


/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */



/* Enabling traces.  */




extern int exdebug;


/* Tokens.  */


   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum extokentype {
     MINTOKEN = 258,
     INTEGER = 259,
     UNSIGNED = 260,
     CHARACTER = 261,
     FLOATING = 262,
     STRING = 263,
     VOIDTYPE = 264,
     STATIC = 265,
     ADDRESS = 266,
     ARRAY = 267,
     BREAK = 268,
     CALL = 269,
     CASE = 270,
     CONSTANT = 271,
     CONTINUE = 272,
     DECLARE = 273,
     DEFAULT = 274,
     DYNAMIC = 275,
     ELSE = 276,
     EXIT = 277,
     FOR = 278,
     FUNCTION = 279,
     GSUB = 280,
     ITERATE = 281,
     ITERATER = 282,
     ID = 283,
     IF = 284,
     LABEL = 285,
     MEMBER = 286,
     NAME = 287,
     POS = 288,
     PRAGMA = 289,
     PRE = 290,
     PRINT = 291,
     PRINTF = 292,
     PROCEDURE = 293,
     QUERY = 294,
     RAND = 295,
     RETURN = 296,
     SCANF = 297,
     SPLIT = 298,
     SPRINTF = 299,
     SRAND = 300,
     SSCANF = 301,
     SUB = 302,
     SUBSTR = 303,
     SWITCH = 304,
     TOKENS = 305,
     UNSET = 306,
     WHILE = 307,
     F2I = 308,
     F2S = 309,
     I2F = 310,
     I2S = 311,
     S2B = 312,
     S2F = 313,
     S2I = 314,
     F2X = 315,
     I2X = 316,
     S2X = 317,
     X2F = 318,
     X2I = 319,
     X2S = 320,
     X2X = 321,
     XPRINT = 322,
     OR = 323,
     AND = 324,
     NE = 325,
     EQ = 326,
     GE = 327,
     LE = 328,
     RS = 329,
     LS = 330,
     IN_OP = 331,
     UNARY = 332,
     DEC = 333,
     INC = 334,
     CAST = 335,
     MAXTOKEN = 336
   };

/* Tokens.  */



















































































typedef union EXSTYPE
{
/* Line 2049 of yacc.c  */


	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	_ast_intmax_t	integer;
	int		op;
	char*		string;
	void*		user;
	struct Exbuf_s*	buffer;


/* Line 2049 of yacc.c  */

} EXSTYPE;





extern EXSTYPE exlval;











int exparse ();





#line 38 "graphviz-2.38.0\\lib\\expr\\expr.h" 2





#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1















































   

   
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   


























































































	
	
	
	
	
	
	
	
	




























#line 41 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1



/*	Public interface for the dictionary library
**
**      Written by Kiem-Phong Vo
*/











#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1






















typedef struct _dtlink_s	Dtlink_t;
typedef struct _dthold_s	Dthold_t;
typedef struct _dtdisc_s	Dtdisc_t;
typedef struct _dtmethod_s	Dtmethod_t;
typedef struct _dtdata_s	Dtdata_t;
typedef struct _dt_s		Dt_t;
typedef struct _dt_s		Dict_t;	/* for libdict compatibility */
typedef struct _dtstat_s	Dtstat_t;
typedef void*			(*Dtmemory_f)(Dt_t*,void*,size_t,Dtdisc_t*);
typedef void*			(*Dtsearch_f)(Dt_t*,void*,int);
typedef void* 		(*Dtmake_f)(Dt_t*,void*,Dtdisc_t*);
typedef void 			(*Dtfree_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtcompar_f)(Dt_t*,void*,void*,Dtdisc_t*);
typedef unsigned int		(*Dthash_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtevent_f)(Dt_t*,int,void*,Dtdisc_t*);

struct _dtlink_s
{	Dtlink_t*	right;	/* right child		*/
	union
	{ unsigned int	_hash;	/* hash value		*/
	  Dtlink_t*	_left;	/* left child		*/
	} hl;
};

/* private structure to hold an object */
struct _dthold_s
{	Dtlink_t	hdr;	/* header		*/
	void*		obj;	/* user object		*/
};

/* method to manipulate dictionary structure */
struct _dtmethod_s 
{	Dtsearch_f	searchf; /* search function	*/
	int		type;	/* type of operation	*/
};

/* stuff that may be in shared memory */
struct _dtdata_s
{	int		type;	/* type of dictionary			*/
	Dtlink_t*	here;	/* finger to last search element	*/
	union
	{ Dtlink_t**	_htab;	/* hash table				*/
	  Dtlink_t*	_head;	/* linked list				*/
	} hh;
	int		ntab;	/* number of hash slots			*/
	int		size;	/* number of objects			*/
	int		loop;	/* number of nested loops		*/
	int		minp;	/* min path before splay, always even	*/
				/* for hash dt, > 0: fixed table size 	*/
};

/* structure to hold methods that manipulate an object */
struct _dtdisc_s
{	int		key;	/* where the key begins in an object	*/
	int		size;	/* key size and type			*/
	int		link;	/* offset to Dtlink_t field		*/
	Dtmake_f	makef;	/* object constructor			*/
	Dtfree_f	freef;	/* object destructor			*/
	Dtcompar_f	comparf;/* to compare two objects		*/
	Dthash_f	hashf;	/* to compute hash value of an object	*/
	Dtmemory_f	memoryf;/* to allocate/free memory		*/
	Dtevent_f	eventf;	/* to process events			*/
};













/* the dictionary structure itself */
struct _dt_s
{	Dtsearch_f	searchf;/* search function			*/
	Dtdisc_t*	disc;	/* method to manipulate objs		*/
	Dtdata_t*	data;	/* sharable data			*/
	Dtmemory_f	memoryf;/* function to alloc/free memory	*/
	Dtmethod_t*	meth;	/* dictionary method			*/
	int		type;	/* type information			*/
	int		nview;	/* number of parent view dictionaries	*/
	Dt_t*		view;	/* next on viewpath			*/
	Dt_t*		walk;	/* dictionary being walked		*/
	void*		user;	/* for user's usage			*/
};

/* structure to get status of a dictionary */
struct _dtstat_s
{	int	dt_meth;	/* method type				*/
	int	dt_size;	/* number of elements			*/
	int	dt_n;		/* number of chains or levels		*/
	int	dt_max;		/* max size of a chain or a level	*/
	int*	dt_count;	/* counts of chains or levels by size	*/
};

/* flag set if the last search operation actually found the object */


/* supported storage methods */










/* asserts to dtdisc() */



/* types of search */















/* events */








1	/* public data */







extern Dtmethod_t* 	Dtset;
extern Dtmethod_t* 	Dtbag;
extern Dtmethod_t* 	Dtoset;
extern Dtmethod_t* 	Dtobag;
extern Dtmethod_t*	Dtlist;
extern Dtmethod_t*	Dtstack;
extern Dtmethod_t*	Dtqueue;
extern Dtmethod_t*	Dtdeque;

/* compatibility stuff; will go away */

extern Dtmethod_t*	Dtorder;
extern Dtmethod_t*	Dttree;
extern Dtmethod_t*	Dthash;
extern Dtmethod_t	_Dttree;
extern Dtmethod_t	_Dthash;
extern Dtmethod_t	_Dtlist;
extern Dtmethod_t	_Dtqueue;
extern Dtmethod_t	_Dtstack;





1	/* public functions */




extern Dt_t*		dtopen (Dtdisc_t*, Dtmethod_t*);
extern int		dtclose (Dt_t*);
extern Dt_t*		dtview (Dt_t*, Dt_t*);
extern Dtdisc_t*	dtdisc (Dt_t* dt, Dtdisc_t*, int);
extern Dtmethod_t*	dtmethod (Dt_t*, Dtmethod_t*);

extern Dtlink_t*	dtflatten (Dt_t*);
extern Dtlink_t*	dtextract (Dt_t*);
extern int		dtrestore (Dt_t*, Dtlink_t*);

extern int		dttreeset (Dt_t*, int, int);

extern int		dtwalk (Dt_t*, int(*)(Dt_t*,void*,void*), void*);

extern void*		dtrenew (Dt_t*, void*);

extern int		dtsize (Dt_t*);
extern int		dtstat (Dt_t*, Dtstat_t*, int);
extern unsigned int	dtstrhash (unsigned int, void*, int);











/* internal functions for translating among holder, object and key */












/* special search function for tree structure only */

























































#line 44 "graphviz-2.38.0\\lib\\expr\\expr.h" 2
#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmalloc.h" 1
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








/*	Public header file for the virtual malloc package.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/






#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmalloc.h" 1


    typedef struct _vmalloc_s Vmalloc_t;
    typedef struct _vmstat_s Vmstat_t;
    typedef struct _vmdisc_s Vmdisc_t;
    typedef struct _vmethod_s Vmethod_t;
    typedef void *(*Vmemory_f)
	(Vmalloc_t *, void *, size_t, size_t, Vmdisc_t *);
    typedef int (*Vmexcept_f)
	(Vmalloc_t *, int, void *, Vmdisc_t *);

    struct _vmstat_s {
	int n_busy;		/* number of busy blocks        */
	int n_free;		/* number of free blocks        */
	size_t s_busy;		/* total amount of busy space   */
	size_t s_free;		/* total amount of free space   */
	size_t m_busy;		/* largest busy piece           */
	size_t m_free;		/* largest free piece           */
	int n_seg;		/* number of segments           */
	size_t extent;		/* total size of region         */
    };

    struct _vmdisc_s {
	Vmemory_f memoryf;	/* memory manipulator           */
	Vmexcept_f exceptf;	/* exception handler            */
	size_t round;		/* rounding requirement         */
    };

    struct _vmethod_s {
	void *(*allocf) (Vmalloc_t *, size_t);
	void *(*resizef) (Vmalloc_t *, void *, size_t, int);
	int (*freef) (Vmalloc_t *, void *);
	long (*addrf) (Vmalloc_t *, void *);
	long (*sizef) (Vmalloc_t *, void *);
	int (*compactf) (Vmalloc_t *);
	void *(*alignf) (Vmalloc_t *, size_t, size_t);
	unsigned short meth;
    };

    struct _vmalloc_s {
	Vmethod_t meth;		/* method for allocation        */
	char *file;		/* file name                    */
	int line;		/* line number                  */

	 

    };


















/* exception types */






     1		/* public data */







/*visual studio*/







/*end visual studio*/		 
		 extern Vmethod_t *Vmbest;	/* best allocation              */
    extern Vmethod_t *Vmlast;	/* last-block allocation        */
    extern Vmethod_t *Vmpool;	/* pool allocation              */
    extern Vmethod_t *Vmdebug;	/* allocation with debugging    */
    extern Vmethod_t *Vmprofile;	/* profiling memory usage       */

    extern Vmdisc_t *Vmdcheap;	/* heap discipline              */
    extern Vmdisc_t *Vmdcsbrk;	/* sbrk discipline              */

    extern Vmalloc_t *Vmheap;	/* heap region                  */
    extern Vmalloc_t *Vmregion;	/* malloc region                */

      1	/* public functions */



     extern Vmalloc_t *vmopen (Vmdisc_t *, Vmethod_t *, int);
    extern int vmclose (Vmalloc_t *);
    extern int vmclear (Vmalloc_t *);
    extern int vmcompact (Vmalloc_t *);

    extern Vmdisc_t *vmdisc (Vmalloc_t *, Vmdisc_t *);

    extern void *vmalloc (Vmalloc_t *, size_t);
    extern void *vmalign (Vmalloc_t *, size_t, size_t);
    extern void *vmresize (Vmalloc_t *, void *, size_t, int);
    extern int vmfree (Vmalloc_t *, void *);

    extern long vmaddr (Vmalloc_t *, void *);
    extern long vmsize (Vmalloc_t *, void *);

    extern Vmalloc_t *vmregion (void *);
    extern void *vmsegment (Vmalloc_t *, void *);
    extern int vmset (Vmalloc_t *, int, int);

    extern void *vmdbwatch (void *);
    extern int vmdbcheck (Vmalloc_t *);

    extern int vmprofile (Vmalloc_t *, int);

    extern int vmtrace (int);
    extern int vmtrbusy (Vmalloc_t *);

    extern int vmstat (Vmalloc_t *, Vmstat_t *);

    extern int vmwalk (Vmalloc_t *,
 int(*)(Vmalloc_t *, void *, size_t,
 Vmdisc_t *));
    extern char *vmstrdup (Vmalloc_t *, const char *);




    extern void *malloc (size_t);
    extern void *realloc (void *, size_t);
    extern void free (void *);
    extern void cfree (void *);
    extern void *calloc (size_t, size_t);
    extern void *memalign (size_t, size_t);
    extern void *valloc (size_t);



     
/* to coerce any value to a Vmalloc_t*, make ANSI happy */

/* enable recording of where a call originates from */


































/* non-debugging/profiling allocation calls */
























#line 45 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



/*
 * flags
 */




















/* previously known as EXID, but EXID is also defined by bison in y.tab.h */







/* function type mechanism
 * types are encoded in TBITS
 * Thus, maximum # of parameters, including return type,
 * is sizeof(Exid_t.type)/TBITS. Also see T in exgram.h
 */

/*
 * arg 0 is the return value type
 */


















typedef short Exshort_t;


typedef EXSTYPE Extype_t;

union Exdata_u; typedef union Exdata_u Exdata_t;
struct Exdisc_s; typedef struct Exdisc_s Exdisc_t;
struct Exnode_s; typedef struct Exnode_s Exnode_t;
struct Expr_s; typedef struct Expr_s Expr_t;
struct Exref_s; typedef struct Exref_s Exref_t;

typedef int (*Exerror_f) (Expr_t *, Exdisc_t *, int, const char *, ...);
typedef void (*Exexit_f) (Expr_t *, Exdisc_t *, int);

typedef struct Exlocal_s		/* user defined member type	*/
{
	_ast_intmax_t	number;
	char*		pointer;
} Exlocal_t;

typedef struct Exid_s			/* id symbol table info		*/
{
	Dtlink_t	link;		/* symbol table link		*/
	long		lex;		/* lex class			*/
	long		index;		/* user defined index		*/
	long		type;		/* symbol and arg types		*/
	long		index_type;	/* index type for arrays        */
	long		flags;		/* user defined flags		*/
	Exnode_t*	value;		/* value			*/
	Exlocal_t	local;		/* user defined local stuff	*/
	long		isstatic;	/* static			*/
	char		name[32];/* symbol name			*/
} Exid_t;

struct Exref_s				/* . reference list		*/
{
	Exref_t*	next;		/* next in list			*/
	Exid_t*		symbol;		/* reference id symbol		*/
	Exnode_t*	index;		/* optional reference index	*/
};

typedef struct Exbuf_s			/* sized buffer			*/
{
	unsigned long	size;		/* buffer size			*/
	char*		data;		/* buffer data			*/
} Exbuf_t;

union Exdata_u
{

	struct
	{
	Extype_t	value;		/* constant value		*/
	Exid_t*		reference;	/* conversion reference symbol	*/
	}		constant;	/* variable reference		*/

	struct
	{
	Exnode_t*	left;		/* left operand			*/
	Exnode_t*	right;		/* right operand		*/
	Exnode_t*	last;		/* for cons			*/
	}		operand;	/* operands			*/

	struct
	{
	Exnode_t*	statement;	/* case label statement(s)	*/
	Exnode_t*	next;		/* next case item		*/
	Extype_t**	constant;	/* case label constant array	*/
	}		select;		/* case item			*/

	struct
	{
	Exid_t*		symbol;		/* id symbol table entry	*/
	Exref_t*	reference;	/* . reference list		*/
	Exnode_t*	index;		/* array index expression	*/
	Exnode_t*	dyna;		/* dynamic expression		*/
	}		variable;	/* variable reference		*/


	Exnode_t* next; Extype_t value; struct { Exid_t* procedure; Exnode_t* args; } call; struct { Exnode_t* array; Exid_t* index; Exnode_t* statement; } generate; struct { Exid_t* array; Exnode_t* string; Exnode_t* seps; } split; struct { Exnode_t* descriptor; Print_t* args; } print; struct { Exnode_t* base; Exnode_t* pat; Exnode_t* repl; } string; struct { Exnode_t* args; Exnode_t* body; Dt_t* frame; int arity; } procedure; struct { Exnode_t* descriptor; Exnode_t* format; Exnode_t* args; } scan;


};

struct Exnode_s				/* expression tree node		*/
{
	Exshort_t	type;		/* value type			*/
	Exshort_t	op;		/* operator			*/
	Exshort_t	binary;		/* data.operand.{left,right} ok	*/
	Exshort_t	pad_1;		/* padding to help cc		*/
	Exlocal_t	local;		/* user defined local stuff	*/
	union
	{
	double	(*floating)(char**);	/* FLOATING return value	*/
	_ast_intmax_t(*integer)(char**);	/* INTEGER|UNSIGNED return value*/
	char*	(*string)(char**);	/* STRING return value		*/
	}		compiled;	/* compiled function pointer	*/
	Exdata_t	data;		/* node data			*/


	Exshort_t subop; Exshort_t pad_2;


};

struct Exdisc_s				/* discipline			*/
{
	unsigned long	version;	/* EX_VERSION			*/
	unsigned long	flags;		/* EX_* flags			*/
	Exid_t*		symbols;	/* static symbols		*/
	char**		data;		/* compiled function arg data	*/
	char*		lib;		/* pathfind() lib		*/
	char*		type;		/* pathfind() type		*/
	int		(*castf)(Expr_t*, Exnode_t*, const char*, int, Exid_t*, int, Exdisc_t*);
					/* unknown cast function	*/
	int		(*convertf)(Expr_t*, Exnode_t*, int, Exid_t*, int, Exdisc_t*);
					/* type conversion function	*/
	int		(*binaryf) (Expr_t *, Exnode_t *, Exnode_t *, Exnode_t *, int, Exdisc_t *);
					/* binary operator function     */
	char*		(*typename) (Expr_t *, int);
					/* application type names       */
	int		(*stringof) (Expr_t *, Exnode_t *, int, Exdisc_t *);
					/* value to string conversion   */
	Extype_t	(*keyf) (Expr_t *, Extype_t, int, Exdisc_t *);
					/* dictionary key for external type objects     */
	Exerror_f	errorf;		/* error function		*/
	Extype_t	(*getf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Exdisc_t*);
					/* get value function		*/
	Extype_t	(*reff)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, char*, int, Exdisc_t*);
					/* reference value function	*/
	int		(*setf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Extype_t, Exdisc_t*);
					/* set value function		*/
	int		(*matchf)(Expr_t*, Exnode_t*, const char*, Exnode_t*, const char*, void*, Exdisc_t*);
	/* exit function           */
	Exexit_f	exitf;
	int*		types;
	void*		user;
};

struct Expr_s				/* ex program state		*/
{
	const char*	id;		/* library id			*/
	Dt_t*		symbols;	/* symbol table			*/
	const char*	more;		/* more after %% (sp or != 0)	*/
	Sfio_t*		file[10];	/* io streams			*/
	Vmalloc_t*	vm;		/* program store		*/


	Vmalloc_t* ve; Dt_t* frame; Dtdisc_t symdisc; Exdisc_t* disc; Exinput_t* input; Expr_t* program; Sfio_t* tmp; Extype_t loopret; Exid_t main; char line[512]; char* linep; int eof; int errors; int formals; int linewrap; int loopcount; int loopop; int nesting;


};

struct Excc_s; typedef struct Excc_s Excc_t;
struct Exccdisc_s; typedef struct Exccdisc_s Exccdisc_t;

struct Exccdisc_s			/* excc() discipline		*/
{
	Sfio_t*		text;		/* text output stream		*/
	char*		id;		/* symbol prefix		*/
	unsigned long	flags;		/* EXCC_* flags			*/
	int		(*ccf)(Excc_t*, Exnode_t*, Exid_t*, Exref_t*, Exnode_t*, Exccdisc_t*);
					/* program generator function	*/
};

struct Excc_s				/* excc() state			*/
{
	Expr_t*		expr;		/* exopen() state		*/
	Exdisc_t*	disc;		/* exopen() discipline		*/


	


};





extern Exnode_t*	excast(Expr_t*, Exnode_t*, int, Exnode_t*, int);
extern Exnode_t*	exnoncast(Exnode_t *);
extern int		excc(Excc_t*, const char*, Exid_t*, int);
extern int		exccclose(Excc_t*);
extern Excc_t*		exccopen(Expr_t*, Exccdisc_t*);
extern void		exclose(Expr_t*, int);
extern int		excomp(Expr_t*, const char*, int, const char*, Sfio_t*);
extern char*		excontext(Expr_t*, char*, int);
extern int		exdump(Expr_t*, Exnode_t*, Sfio_t*);
extern void		exerror(const char*, ...);
extern void		exwarn(const char *, ...);
extern Extype_t		exeval(Expr_t*, Exnode_t*, void*);
extern Exnode_t*	exexpr(Expr_t*, const char*, Exid_t*, int);
extern void		exfreenode(Expr_t*, Exnode_t*);
extern Exnode_t*	exnewnode(Expr_t*, int, int, int, Exnode_t*, Exnode_t*);
extern char*		exnospace(void);
extern Expr_t*		exopen(Exdisc_t*);
extern int		expop(Expr_t*);
extern int		expush(Expr_t*, const char*, int, const char*, Sfio_t*);
extern int		exrewind(Expr_t*);
extern char*		exstash(Sfio_t*, Vmalloc_t*);
extern void		exstatement(Expr_t*);
extern int		extoken_fn(Expr_t*);
extern char*		exstring(Expr_t *, char *);
extern void*		exstralloc(Expr_t *, void *, size_t);
extern int		exstrfree(Expr_t *, void *);
extern char*		extype(int);
extern Extype_t		exzero(int);
extern char*	exopname(int);
extern void		exinit(void);
extern char*	extypename(Expr_t * p, int);
extern int		exisAssign(Exnode_t *);








#line 129 "graphviz-2.38.0\\lib\\expr\\exlib.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\exlib.h" 1
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






#line 131 "graphviz-2.38.0\\lib\\expr\\exlib.h" 2
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








#line 132 "graphviz-2.38.0\\lib\\expr\\exlib.h" 2








typedef struct Switch_s			/* switch parse state		*/
{
	struct Switch_s*prev;		/* previous switch state	*/
	Exnode_t*	firstcase;	/* first case block		*/
	Exnode_t*	lastcase;	/* last case block		*/
	Exnode_t*	defcase;	/* default case block		*/
	Extype_t**	base;		/* label base pointer		*/
	Extype_t**	cur;		/* current label pointer	*/
	Extype_t**	last;		/* last label pointer		*/
	int		def;		/* default label hit		*/
	int		type;		/* switch test type		*/
} Switch_t;

typedef struct Exassoc_s		/* associative array bucket	*/
{
	Dtlink_t	link;		/* table link			*/
	Extype_t	key;		/* key				*/
	Extype_t	value;		/* value			*/
	char		name[1];	/* index name			*/
} Exassoc_t;

typedef struct Exstate_s		/* ex global state		*/
{
	Exid_t*		id;		/* current declaration id	*/
	int		declare;	/* current declaration type	*/
	Exref_t*	lastref;	/* last in . reference list	*/
	int		nolabel;	/* <id>':' not a label		*/
	Exinput_t	null;		/* null input			*/
	Expr_t*		program;	/* current program		*/
	Exnode_t*	procedure;	/* current procedure		*/
	Exref_t*	refs;		/* . reference list		*/
	int		assigned;	/* declaration assignment	*/
	int		instatic;	/* static declaration		*/
	int		statics;	/* static used			*/
	Switch_t*	swstate;	/* switch parse state		*/
	char		nullstring[1];	/* ""				*/
} Exstate_t;

extern Exid_t		exbuiltin[];
extern const char*	exversion;
extern Exstate_t	expr;

extern int		exparse(void);	/* yacc should do this		*/




extern _ast_intmax_t		strToL(char *, char **);






#line 25 "graphviz-2.38.0\\lib\\expr\\exeval.c" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\exop.h" 1
static const char* exop[] = {
	"MINTOKEN",
	"INTEGER",
	"UNSIGNED",
	"CHARACTER",
	"FLOATING",
	"STRING",
	"VOIDTYPE",
	"STATIC",
	"ADDRESS",
	"ARRAY",
	"BREAK",
	"CALL",
	"CASE",
	"CONSTANT",
	"CONTINUE",
	"DECLARE",
	"DEFAULT",
	"DYNAMIC",
	"ELSE",
	"EXIT",
	"FOR",
	"FUNCTION",
	"GSUB",
	"ITERATE",
	"ITERATER",
	"ID",
	"IF",
	"LABEL",
	"MEMBER",
	"NAME",
	"POS",
	"PRAGMA",
	"PRE",
	"PRINT",
	"PRINTF",
	"PROCEDURE",
	"QUERY",
	"RAND",
	"RETURN",
	"SCANF",
	"SPLIT",
	"SPRINTF",
	"SRAND",
	"SSCANF",
	"SUB",
	"SUBSTR",
	"SWITCH",
	"TOKENS",
	"UNSET",
	"WHILE",
	"F2I",
	"F2S",
	"I2F",
	"I2S",
	"S2B",
	"S2F",
	"S2I",
	"F2X",
	"I2X",
	"S2X",
	"X2F",
	"X2I",
	"X2S",
	"X2X",
	"XPRINT",
	"OR",
	"AND",
	"NE",
	"EQ",
	"GE",
	"LE",
	"RS",
	"LS",
	"IN_OP",
	"UNARY",
	"DEC",
	"INC",
	"CAST",
};
#line 26 "graphviz-2.38.0\\lib\\expr\\exeval.c" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\exeval.c" 1
#line 1 "graphviz-2.38.0\\lib\\expr\\exeval.c" 1
#line 1 "graphviz-2.38.0\\lib\\expr\\exeval.c" 1












static Extype_t	eval(Expr_t*, Exnode_t*, void*);





static char*
lexname(int op, int subop)
{
	register char*	b;

	static int	n;
	static char	buf[4][16];

	if (op > 258 && op < 336)
		return (char*)exop[op - 258];
	if (++n >= 4)
		n = 0;
	b = buf[n];
	if (op == '=')
	{
		if (subop > 258 && subop < 336)
			sfsprintf(b, 16, "%s=", exop[subop - 258]);
		else if (subop > ' ' && subop <= '~')
			sfsprintf(b, 16, "%c=", subop);
		else
			sfsprintf(b, 16, "(%d)=", subop);
	}
	else if (subop < 0)
		sfsprintf(b, 16, "(EXTERNAL:%d)", op);
	else if (op > ' ' && op <= '~')
		sfsprintf(b, 16, "%c", op);
	else
		sfsprintf(b, 16, "(%d)", op);
	return b;
}

/* evaldyn:
 * Evaluate item from array given key.
 * Returns 1 if item existed, zero otherwise
 * 
 */
static int
evaldyn (Expr_t * ex, register Exnode_t * expr, void *env, int delete)
{
	Exassoc_t *b;
	Extype_t v;
	char buf[32];
	Extype_t key;
	char *keyname;

	v = eval(ex, expr->data.variable.index, env);
	if (expr->data.variable.symbol->index_type == 259) {
		if (!(b = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t *) expr->data.variable.symbol->local.pointer),(void*)(&v),0001000))) {
			return 0;
		}
	} 
	else {
		int type = expr->data.variable.index->type;
		if (type != 263) {
			if (!((type) > 258)) {
				key = (*ex->disc->keyf) (ex, v, type, ex->disc);
			} else
				key.integer = v.integer;
			sfsprintf(buf, sizeof(buf), "0x%I*x", sizeof(v.integer), key.integer);
			keyname = buf;
		} else
			keyname = v.string;
		if (!(b = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.variable.
 symbol->local.pointer))->searchf))(((Dt_t *) expr->data.variable.
 symbol->local.pointer),(void*)(keyname),0001000))) {
			return 0;
		}
	}
	if (delete) {
		(*(((Dt_t*)((Dt_t*)expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t*)expr->data.variable.symbol->local.pointer),(void*)(b),0000002);
		free (b);
	}
	return 1;
}

/*
 * return dynamic (associative array) variable value
 * assoc will point to the associative array bucket
 */

static Extype_t
getdyn(Expr_t* ex, register Exnode_t* expr, void* env, Exassoc_t** assoc)
{
	Exassoc_t*	b;
	Extype_t	v;

	if (expr->data.variable.index)
	{
		Extype_t key;
		char	buf[2*(sizeof(key.integer))+1];  /* no. of hex chars needed plus null byte */
		char *keyname;

		v = eval(ex, expr->data.variable.index, env);
		if (expr->data.variable.symbol->index_type == 259) {
			if (!(b = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t *) expr->data.variable.symbol->local.pointer),(void*)(&v),0001000))) 
			{
				if (!(b = ((0)?(Exassoc_t*)realloc((char*)(0),sizeof(Exassoc_t)*(1)+(0)):(Exassoc_t*)calloc(1,sizeof(Exassoc_t)*(1)+(0)))))
					exnospace();
				b->key = v;
				(*(((Dt_t*)((Dt_t *) expr->data.variable.symbol->local. pointer))->searchf))(((Dt_t *) expr->data.variable.symbol->local. pointer),(void*)(b),0000001);
			}
		} else {
			int type = expr->data.variable.index->type;
			if (type != 263) {
				if (!((type) > 258)) {
					key = (*ex->disc->keyf) (ex, v, type, ex->disc);
				} else
					key.integer = v.integer;
				sfsprintf(buf, sizeof(buf), "%I*x", sizeof(key.integer), key.integer);
				keyname = buf;
			} else
				keyname = v.string;
			if (!(b = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t *) expr->data.variable.symbol->local.pointer),(void*)(keyname),0001000))) 
			{
				if (!(b = ((0)?(Exassoc_t*)realloc((char*)(0),sizeof(Exassoc_t)*(1)+(strlen(keyname))):(Exassoc_t*)calloc(1,sizeof(Exassoc_t)*(1)+(strlen(keyname))))))
					exnospace();
				strcpy(b->name, keyname);
				b->key = v;
				(*(((Dt_t*)((Dt_t *) expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t *) expr->data.variable.symbol->local.pointer),(void*)(b),0000001);
			}
		}
		*assoc = b;
		if (b)
		{
			if (expr->data.variable.symbol->type == 263 && !b->value.string)
				b->value = exzero(expr->data.variable.symbol->type);
			return b->value;
		}
		v = exzero(expr->data.variable.symbol->type);
		return v;
	}
	*assoc = 0;
	return expr->data.variable.symbol->value->data.constant.value;
}

typedef struct
{
	Sffmt_t		fmt;
	Expr_t*		expr;
	void*		env;
	Print_t*	args;
	Extype_t	value;
	Exnode_t*	actuals;
	Sfio_t*		tmp;
} Fmt_t;

/*
 * printf %! extension function
 */

static int
prformat(Sfio_t* sp, void* vp, Sffmt_t* dp)
{
	register Fmt_t*		fmt = (Fmt_t*)dp;
	register Exnode_t*	node;
	register char*		s;
	register char*		txt;
	int			n;
	int			from;
	int			to = 0;
	time_t			tm;

    struct tm *stm;



	dp->flags |= 00400000;
	if (fmt->args)
	{
		if ((node = (dp->fmt == '*') ? fmt->args->param[dp->size] : fmt->args->arg))
			fmt->value = exeval(fmt->expr, node, fmt->env);
		else
			fmt->value.integer = 0;
		to = fmt->args->arg->type;
	}
	else if (!(fmt->actuals = fmt->actuals->data.operand.right))
		exerror("printf: not enough arguments");
	else
	{
		node = fmt->actuals->data.operand.left;
		from = node->type;
		switch (dp->fmt)
		{
		case 'f':
		case 'g':
			to = 262;
			break;
		case 's':
			to = 263;
			break;
		default:
			switch (from)
			{
			case 259:
			case 260:
				to = from;
				break;
			default:
				to = 259;
				break;
			}
			break;
		}
		if (to == from)
			fmt->value = exeval(fmt->expr, node, fmt->env);
		else
		{
			node = excast(fmt->expr, node, to, 0, 0);
			fmt->value = exeval(fmt->expr, node, fmt->env);
			node->data.operand.left = 0;
			(*(((Vmalloc_t*)((fmt->expr)->vm))->meth.freef))(((fmt->expr)->vm),(void*)(node));
			if (to == 263)
			{
				if (fmt->value.string)
				{
					n = strlen(fmt->value.string);
					if ((s = fmtbuf(n + 1)))
						memcpy(s, fmt->value.string, n + 1);
					(*(((Vmalloc_t*)(fmt->expr->vm))->meth.freef))((fmt->expr->vm),(void*)(fmt->value.string));
					fmt->value.string = s;
				}
				if (!fmt->value.string)
					fmt->value.string = "";
			}
		}
	}
	switch (to)
	{
	case 263:
		*((char**)vp) = fmt->value.string;
		fmt->fmt.size = -1;
		break;
	case 262:
		*((double*)vp) = fmt->value.floating;
		fmt->fmt.size = sizeof(double);
		break;
	default:
		*((_ast_intmax_t*)vp) = fmt->value.integer;
		dp->size = sizeof(_ast_intmax_t);
		break;
	}
	if (dp->n_str > 0)
	{
		if (!fmt->tmp && !(fmt->tmp = sfnew((Sfio_t*)0,(char*)0,-1,-1,0000002|0000004)))
			txt = exnospace();
		else
		{
			sfprintf(fmt->tmp, "%.*s", dp->n_str, dp->t_str);
			txt = exstash(fmt->tmp, 0);
		}
	}
	else
		txt = 0;
	switch (dp->fmt)
	{
	case 'q':
	case 'Q':
		s = *((char**)vp);
		*((char**)vp) = fmtquote(s, "$'", "'", strlen(s), 0);
		dp->fmt = 's';
		dp->size = -1;
		break;
	case 'S':
		dp->flags &= ~00040000;
		s = *((char**)vp);
		if (txt)
		{
			if ((*(txt)==*("identifier")&&!strcmp(txt,"identifier")))
			{
				if (*s && !isalpha(*s))
					*s++ = '_';
				for (; *s; s++)
					if (!isalnum(*s))
						*s = '_';
			}
			else if ((*(txt)==*("invert")&&!strcmp(txt,"invert")))
			{
				for (; *s; s++)
					if (isupper(*s))
						*s = tolower(*s);
					else if (islower(*s))
						*s = toupper(*s);
			}
			else if ((*(txt)==*("lower")&&!strcmp(txt,"lower")))
			{
				for (; *s; s++)
					if (isupper(*s))
						*s = tolower(*s);
			}
			else if ((*(txt)==*("upper")&&!strcmp(txt,"upper")))
			{
				for (; *s; s++)
					if (islower(*s))
						*s = toupper(*s);
			}
			else if ((*(txt)==*("variable")&&!strcmp(txt,"variable")))
			{
				for (; *s; s++)
					if (!isalnum(*s) && *s != '_')
						*s = '.';
			}
		}
		dp->fmt = 's';
		dp->size = -1;
		break;
	case 't':
	case 'T':
		if ((tm = *((_ast_intmax_t*)vp)) == -1)
			tm = time(0);

        if (!txt)
            txt = "%?%K";
        s = fmtbuf(80);
        stm = localtime(&tm);
        strftime(s, 80, txt, stm);
        *((char **) vp) = s;

		

		dp->fmt = 's';
		dp->size = -1;
		break;
	}
	return 0;
}

/*
 * print a list of strings
 */

static int
prints(Expr_t * ex, register Exnode_t * expr, void *env, Sfio_t * sp)
{
    Extype_t v;
    Exnode_t *args;

    args = expr->data.operand.left;
    while (args) {
	v = eval(ex, args->data.operand.left, env);
	sfputr(sp, v.string, -1);
	args = args->data.operand.right;
    }
    ( (((Sfio_t*)((sp)))->next >= ((Sfio_t*)((sp)))->endw ? _sfflsbuf(((Sfio_t*)((sp))),(int)((unsigned char)(('\n')))) : (int)(*((Sfio_t*)((sp)))->next++ = (unsigned char)(('\n'))) ) );
    return 0;
}

/*
 * do printf
 */

static int
print(Expr_t* ex, Exnode_t* expr, void* env, Sfio_t* sp)
{
	register Print_t*	x;
	Extype_t		v;
	Fmt_t			fmt;

	if (!sp)
	{
		v = eval(ex, expr->data.print.descriptor, env);
		if (v.integer < 0 || v.integer >= (sizeof(ex->file)/sizeof(ex->file[0])) || (!(sp = ex->file[v.integer]) && !(sp = ex->file[v.integer] = sfnew(0, 0, (-1), v.integer, 0000001|0000002))))
		{
			exerror("printf: %d: invalid descriptor", v.integer);
			return -1;
		}
	}
	memset(&fmt, 0, sizeof(fmt));
	fmt.fmt.version = 20010201L;
	fmt.fmt.extf = prformat;
	fmt.expr = ex;
	fmt.env = env;
	x = expr->data.print.args;
	if (x->format)
		do
		{
			if (x->arg)
			{
				fmt.fmt.form = x->format;
				fmt.args = x;
				sfprintf(sp, "%!", &fmt);
			}
			else
				sfputr(sp, x->format, -1);
		} while ((x = x->next));
	else
	{
		v = eval(ex, x->arg->data.operand.left, env);
		fmt.fmt.form = v.string;
		fmt.actuals = x->arg;
		sfprintf(sp, "%!", &fmt);
		if (fmt.actuals->data.operand.right)
			exerror("(s)printf: \"%s\": too many arguments", fmt.fmt.form);
	}
	if (fmt.tmp)
		sfclose(fmt.tmp);
	return 0;
}

/*
 * scanf %! extension function
 */

static int
scformat(Sfio_t* sp, void* vp, Sffmt_t* dp)
{
	register Fmt_t*		fmt = (Fmt_t*)dp;
	register Exnode_t*	node;

	if (!fmt->actuals)
	{
		exerror("scanf: not enough arguments");
		return -1;
	}
	node = fmt->actuals->data.operand.left;
	switch (dp->fmt)
	{
	case 'f':
	case 'g':
		if (node->type != 262)
		{
			exerror("scanf: %s: floating variable address argument expected", node->data.variable.symbol->name);
			return -1;
		}
		fmt->fmt.size = sizeof(double);
		*((void**)vp) = &node->data.variable.symbol->value->data.constant.value;
		break;
	case 's':
	case '[':
		if (node->type != 263)
		{
			exerror("scanf: %s: string variable address argument expected", node->data.variable.symbol->name);
			return -1;
		}
		if (node->data.variable.symbol->value->data.constant.value.string == expr.nullstring)
			node->data.variable.symbol->value->data.constant.value.string = 0;
		fmt->fmt.size = 1024;
		*((void**)vp) = node->data.variable.symbol->value->data.constant.value.string = (char*)(*(((Vmalloc_t*)((fmt->expr->vm)))->meth.resizef)) (((fmt->expr->vm)),(void*)((node->data.variable.symbol->value->data.constant.value.string)),(sizeof(char)*(fmt->fmt.size)+(0)),((0000002|0000001|0000004)));
		break;
	case 'c':
		if (node->type != 261) {
			exerror("scanf: %s: char variable address argument expected", node->data.variable.symbol->name);
			return -1;
		}
		fmt->fmt.size = sizeof(_ast_intmax_t);
		*((void **) vp) = &node->data.variable.symbol->value->data.constant.value;
		break;
	default:
		if (node->type != 259 && node->type != 260)
		{
			exerror("scanf: %s: integer variable address argument expected", node->data.variable.symbol->name);
			return -1;
		}
		dp->size = sizeof(_ast_intmax_t);
		*((void**)vp) = &node->data.variable.symbol->value->data.constant.value;
		break;
	}
	fmt->actuals = fmt->actuals->data.operand.right;
	dp->flags |= 00400000;
	return 0;
}

/*
 * do scanf
 */

static int
scan(Expr_t* ex, Exnode_t* expr, void* env, Sfio_t* sp)
{
	Extype_t		v;
	Extype_t		u;
	Fmt_t			fmt;
	int			n;

	if (!sp)
	{
		if (expr->data.scan.descriptor)
		{
			v = eval(ex, expr->data.scan.descriptor, env);
			if (expr->data.scan.descriptor->type == 263)
				goto get;
		}
		else
			v.integer = 0;
		if ((v.integer < 0) || (v.integer >= (sizeof(ex->file)/sizeof(ex->file[0]))) || (!(sp = ex->file[v.integer]) && !(sp = ex->file[v.integer] = sfnew(0, 0, (-1), v.integer, 0000001|0000002))))
		{
			exerror("scanf: %d: invalid descriptor", v.integer);
			return 0;
		}
	}
 get:
	memset(&fmt, 0, sizeof(fmt));
	fmt.fmt.version = 20010201L;
	fmt.fmt.extf = scformat;
	fmt.expr = ex;
	fmt.env = env;
	u = eval(ex, expr->data.scan.format, env);
	fmt.fmt.form = u.string;
	fmt.actuals = expr->data.scan.args;
	n = sp ? sfscanf(sp, "%!", &fmt) : sfsscanf(v.string, "%!", &fmt);
	if (fmt.tmp) sfclose(fmt.tmp);
	if (fmt.actuals && !*fmt.fmt.form)
		exerror("scanf: %s: too many arguments", fmt.actuals->data.operand.left->data.variable.symbol->name);
	return n;
}

/*
 * string add
 */

static char*
str_add(Expr_t* ex, register char* l, register char* r)
{
	sfprintf(ex->tmp, "%s%s", l, r);
	return exstash(ex->tmp, ex->ve);
}

/*
 * string ior
 */

static char*
str_ior(Expr_t* ex, register char* l, register char* r)
{
	register int	c;
	register char*	s = l;

	while ((c = *s++))
		if (!strchr(s, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	while ((c = *r++))
		if (!strchr(l, c) && !strchr(r, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	return exstash(ex->tmp, ex->ve);
}

/*
 * string and
 */

static char*
str_and(Expr_t* ex, register char* l, register char* r)
{
	register int	c;

	while ((c = *l++))
		if (strchr(r, c) && !strchr(l, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	return exstash(ex->tmp, ex->ve);
}

/*
 * string xor
 */

static char*
str_xor(Expr_t* ex, register char* l, register char* r)
{
	register int	c;
	register char*	s = l;

	while ((c = *s++))
		if (!strchr(r, c) && !strchr(s, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	while ((c = *r++))
		if (!strchr(l, c) && !strchr(r, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	return exstash(ex->tmp, ex->ve);
}

/*
 * string mod
 */

static char*
str_mod(Expr_t* ex, register char* l, register char* r)
{
	register int	c;

	while ((c = *l++))
		if (!strchr(r, c) && !strchr(l, c))
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
	return exstash(ex->tmp, ex->ve);
}

/*
 * string mpy
 */

static char*
str_mpy(Expr_t* ex, register char* l, register char* r)
{
	register int	lc;
	register int	rc;

	while ((lc = *l++) && (rc = *r++))
		( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((lc == rc ? lc : ' ')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((lc == rc ? lc : ' '))) ) );
	return exstash(ex->tmp, ex->ve);
}

/* replace:
 * Add replacement string.
 * \digit is replaced with a subgroup match, if any.
 */
static void
replace(Sfio_t * s, char *base, register char *repl, int ng, int *sub)
{
	char c;
	int idx, offset;

	while ((c = *repl++)) {
	if (c == '\\') {
	    if ((c = *repl) && isdigit(c)) {
			idx = c - '0';
			if (idx < ng) {
		    	offset = sub[2 * idx];
		    	sfwrite(s, base + offset, sub[2 * idx + 1] - offset);
			}
			repl++;
	    } else
			( (((Sfio_t*)((s)))->next >= ((Sfio_t*)((s)))->endw ? _sfflsbuf(((Sfio_t*)((s))),(int)((unsigned char)(('\\')))) : (int)(*((Sfio_t*)((s)))->next++ = (unsigned char)(('\\'))) ) );
	} else
	    ( (((Sfio_t*)((s)))->next >= ((Sfio_t*)((s)))->endw ? _sfflsbuf(((Sfio_t*)((s))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((s)))->next++ = (unsigned char)((c))) ) );
	}
}



static void
addItem (Dt_t* arr, Extype_t v, char* tok)
{
	Exassoc_t* b;

	if (!(b = (Exassoc_t *) (*(((Dt_t*)(arr))->searchf))((arr),(void*)(&v),0001000))) {
		if (!(b = ((0)?(Exassoc_t*)realloc((char*)(0),sizeof(Exassoc_t)*(1)+(0)):(Exassoc_t*)calloc(1,sizeof(Exassoc_t)*(1)+(0)))))
	    	exerror("out of space [assoc]");
		b->key = v;
		(*(((Dt_t*)(arr))->searchf))((arr),(void*)(b),0000001);
	}
	b->value.string = tok;
}

/* exsplit:
 * break string into possibly empty fields and store in array
 * return number of fields
 */
Extype_t
exsplit(Expr_t * ex, register Exnode_t * expr, void *env)
{
	Extype_t v;
	char *str;
	char *seps;
	char *tok;
	size_t sz;
	Sfio_t* fp = ex->tmp;
	Dt_t* arr = (Dt_t*)expr->data.split.array->local.pointer;
	int i;

	str = (eval(ex, expr->data.split.string, env)).string;
	if (expr->data.split.seps)
		seps = (eval(ex, expr->data.split.seps, env)).string;
	else
		seps = " \t\n";

	v.integer = 0;
	while (*str) {
		sz = strspn (str, seps);
	    if (sz) {
			if (v.integer == 0) {  /* initial separator => empty field */
	    		addItem (arr, v, "");
	    		v.integer++;
			}
			for (i = 1; i < sz; i++) {
	    		addItem (arr, v, "");
	    		v.integer++;
			}
		}
		str += sz;
		if (*str == '\0') { /* terminal separator => empty field */
			addItem (arr, v, "");
			v.integer++;
	    	break;
		}
		sz = strcspn (str, seps);
		sfwrite (fp, str, sz);
		tok = vmstrdup((ex)->vm,(( (((Sfio_t*)((fp)))->next >= ((Sfio_t*)((fp)))->endw ? _sfflsbuf(((Sfio_t*)((fp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((fp)))->next++ = (unsigned char)((0))) ) ), (char*)((fp)->next = (fp)->data) ));
		addItem (arr, v, tok);
		v.integer++;
		str += sz;
	}

	return v;
}

/* extoken:
 * tokenize string and store in array
 * return number of tokens
 */
Extype_t
extokens(Expr_t * ex, register Exnode_t * expr, void *env)
{
	Extype_t v;
	char *str;
	char *seps;
	char *tok;
	size_t sz;
	Sfio_t* fp = ex->tmp;
	Dt_t* arr = (Dt_t*)expr->data.split.array->local.pointer;

	str = (eval(ex, expr->data.split.string, env)).string;
	if (expr->data.split.seps)
		seps = (eval(ex, expr->data.split.seps, env)).string;
	else
		seps = " \t\n";

	v.integer = 0;
	while (*str) {
		sz = strspn (str, seps);
		str += sz;
		if (*str == '\0')
	    	break;

		sz = strcspn (str, seps);
		assert (sz);
		sfwrite (fp, str, sz);
		tok = vmstrdup((ex)->vm,(( (((Sfio_t*)((fp)))->next >= ((Sfio_t*)((fp)))->endw ? _sfflsbuf(((Sfio_t*)((fp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((fp)))->next++ = (unsigned char)((0))) ) ), (char*)((fp)->next = (fp)->data) ));
		addItem (arr, v, tok);
		v.integer++;
		str += sz;
	}

	return v;
}

/* exsub:
 * return string after pattern substitution
 */
Extype_t
exsub(Expr_t * ex, register Exnode_t * expr, void *env, int global)
{
	char *str;
	char *pat;
	char *repl;
	char *p;
	char *s;
	Extype_t v;
	int sub[20];
	int flags = 01;
	int ng;

	str = (eval(ex, expr->data.string.base, env)).string;
	pat = (eval(ex, expr->data.string.pat, env)).string;
	if (expr->data.string.repl)
		repl = (eval(ex, expr->data.string.repl, env)).string;
	else
		repl = 0;

	if (!global) {
		if (*pat == '^') {
		    pat++;
		    flags |= 02;
		}
		p = pat;
		while (*p)
		    p++;
		if (p > pat)
		    p--;
		if (*p == '$') {
		    if ((p > pat) && (*(p - 1) == '\\')) {
				*p-- = '\0';
				*p = '$';
	    	} else {
				flags |= 04;
				*p = '\0';
	    	}
		}
	}
	if (*pat == '\0') {
		v.string = vmstrdup(ex->ve, str);
		return v;
	}

	ng = strgrpmatch(str, pat, sub, (sizeof(sub)/(2*sizeof(int))), flags);
	if (ng == 0) {
		v.string = vmstrdup(ex->ve, str);
		return v;
	}
    if (sub[0] == sub[1]) {
		exwarn("pattern match of empty string - ill-specified pattern \"%s\"?", pat);
		v.string = vmstrdup(ex->ve, str);
		return v;
    } 
	sfwrite(ex->tmp, str, sub[0]);
	if (repl)
		replace(ex->tmp, str, repl, ng, sub);

	s = str + sub[1];
	if (global) {
		while ((ng = strgrpmatch(s, pat, sub, (sizeof(sub)/(2*sizeof(int))), flags))) {
	   	 sfwrite(ex->tmp, s, sub[0]);
	   	 if (repl)
			replace(ex->tmp, s, repl, ng, sub);
	   	 s = s + sub[1];
		}
	}

	sfputr(ex->tmp, s, -1);
	v.string = exstash(ex->tmp,ex->ve);
	return v;
}

/* exsubstr:
 * return substring.
 */
static Extype_t exsubstr(Expr_t * ex, register Exnode_t * expr, void *env)
{
	Extype_t s;
	Extype_t i;
	Extype_t l;
	Extype_t v;
	int len;

	s = eval(ex, expr->data.string.base, env);
	len = strlen(s.string);
	i = eval(ex, expr->data.string.pat, env);
	if ((i.integer < 0) || (len < i.integer))
		exerror("illegal start index in substr(%s,%d)", s.string, i.integer);
	if (expr->data.string.repl) {
		l = eval(ex, expr->data.string.repl, env);
		if ((l.integer < 0) || (len - i.integer < l.integer))
	    exerror("illegal length in substr(%s,%d,%d)", s.string, i.integer, l.integer);
	} else
		l.integer = len - i.integer;

	v.string = (*(((Vmalloc_t*)(ex->ve))->meth.allocf))((ex->ve),(l.integer + 1));
	if (expr->data.string.repl) {
		strncpy(v.string, s.string + i.integer, l.integer);
		v.string[l.integer] = '\0';
	} else
		strcpy(v.string, s.string + i.integer);
	return v;
}

/* xConvert:
 * Convert from external type.
 */
static void
xConvert(Expr_t * ex, Exnode_t * expr, int type, Extype_t v,
	 Exnode_t * tmp)
{
	*tmp = *expr->data.operand.left;
	tmp->data.constant.value = v;
	if ((*ex->disc->convertf) (ex, tmp, type, expr->data.operand.right ? expr->data.
		operand.right->data.variable.symbol : (Exid_t *) 0, 0, ex->disc)) {
		exerror("%s: cannot convert %s value to %s",
			expr->data.operand.left->data.variable.symbol->name,
			extypename(ex, expr->data.operand.left->type), extypename(ex, type));
	}
	tmp->type = type;
}

/* xPrint:
 * Generate string representation from value of external type.
 */
static void
xPrint(Expr_t * ex, Exnode_t * expr, Extype_t v, Exnode_t * tmp)
{
	*tmp = *expr->data.operand.left;
	tmp->data.constant.value = v;
	if ((*ex->disc->stringof) (ex, tmp, 0, ex->disc))
	exerror("%s: no string representation of %s value",
		expr->data.operand.left->data.variable.symbol->name,
		extypename(ex, expr->data.operand.left->type));
	tmp->type = 263;
}

/*
 * internal exeval
 */
static long seed;

static Extype_t
eval(Expr_t* ex, register Exnode_t* expr, void* env)
{
	register Exnode_t*	x;
	register Exnode_t*	a;
	register Extype_t**	t;
	register int		n;
	Extype_t		v;
	Extype_t		r;
	Extype_t		i;
	char*			e;
	Exnode_t		tmp;
	Exnode_t		rtmp;
	Exnode_t*		rp;
	Exassoc_t*		assoc;
	Extype_t		args[64+1];
	Extype_t		save[64];

	if (!expr || ex->loopcount)
	{
		v.integer = 1;
		return v;
	}
	x = expr->data.operand.left;
	switch (expr->op)
	{
	case 268:
	case 272:
		v = eval(ex, x, env);
		ex->loopcount = v.integer;
		ex->loopop = expr->op;
		return v;
	case 271:
		return expr->data.constant.value;
	case 333:
		n = -1;
	add:
		if (x->op == 275)
			r = getdyn(ex, x, env, &assoc);
		else
		{
			if (x->data.variable.index)
				i = eval(ex, x->data.variable.index, env);
			else
				i.integer = (-1);

			if (x->data.variable.dyna) {
				Extype_t locv;
				locv = getdyn(ex, x->data.variable.dyna, env, &assoc);
				x->data.variable.dyna->data.variable.dyna->data.constant.value = locv;
			}

			r = (*ex->disc->getf)(ex, x, x->data.variable.symbol, x->data.variable.reference, env, (int)i.integer, ex->disc);
		}
		v = r;
		switch (x->type)
		{
		case 262:
			v.floating += n;
			break;
		case 259:
		case 260:
			v.integer += n;
			break;
		default:
			goto huh;
		}
	set:
		if (x->op == 275)
		{
			if (x->type == 263)
			{
				v.string = vmstrdup(ex->vm, v.string);
				if ((e = assoc ? assoc->value.string : x->data.variable.symbol->value->data.constant.value.string))
					(*(((Vmalloc_t*)(ex->vm))->meth.freef))((ex->vm),(void*)(e));
			}
			if (assoc)
				assoc->value = v;
			else
				x->data.variable.symbol->value->data.constant.value = v;
		}
		else
		{
			if (x->data.variable.index)
				i = eval(ex, x->data.variable.index, env);
			else
				i.integer = (-1);

			if (x->data.variable.dyna) {
				Extype_t locv;
				locv = getdyn(ex, x->data.variable.dyna, env, &assoc);
				x->data.variable.dyna->data.variable.dyna->data.constant.value = locv;
			}

			if ((*ex->disc->setf)(ex, x, x->data.variable.symbol, x->data.variable.reference, env, (int)i.integer, v, ex->disc) < 0)
				exerror("%s: cannot set value", x->data.variable.symbol->name);
		}
		if (expr->subop == 290)
			r = v;
		return r;
	case 275:
		return getdyn(ex, expr, env, &assoc);
	case 298:
		return exsplit(ex, expr, env);
	case 305:
		return extokens(ex, expr, env);
	case 280:
		return exsub(ex, expr, env, 1);
	case 302:
		return exsub(ex, expr, env, 0);
	case 303:
		return exsubstr(ex, expr, env);
	case 300:
		v.integer = seed;
		if (expr->binary) {
			seed = eval(ex, x, env).integer;
		} else
			seed = time(0);
		srand48(seed);
		return v;
	case 295:
		v.floating = drand48();
		return v;
	case 277:
		v = eval(ex, x, env);
		if (ex->disc->exitf)
			(*ex->disc->exitf) (ex, env, (int)v.integer);
		else
			exit((int)v.integer);
		/*NOTREACHED*/
		v.integer = -1;
		return v;
	case 284:
		v = eval(ex, x, env);
		if (v.integer)
			eval(ex, expr->data.operand.right->data.operand.left, env);
		else
			eval(ex, expr->data.operand.right->data.operand.right, env);
		v.integer = 1;
		return v;
	case 278:
	case 307:
		expr = expr->data.operand.right;
		for (;;)
		{
			r = eval(ex, x, env);
			if (!r.integer)
			{
				v.integer = 1;
				return v;
			}
			if (expr->data.operand.right)
			{
				eval(ex, expr->data.operand.right, env);
				if (ex->loopcount > 0 && (--ex->loopcount > 0 || ex->loopop != 272))
				{
					v.integer = 0;
					return v;
				}
			}
			if (expr->data.operand.left)
				eval(ex, expr->data.operand.left, env);
		}
		/*NOTREACHED*/
	case 304:
		v = eval(ex, x, env);
		i.integer = x->type;
		r.integer = 0;
		x = expr->data.operand.right;
		a = x->data.select.statement;
		n = 0;
		while ((x = x->data.select.next))
		{
			if (!(t = x->data.select.constant))
				n = 1;
			else
				for (; *t; t++)
				{
					switch ((int)i.integer)
					{
					case 259:
					case 260:
						if ((*t)->integer == v.integer)
							break;
						continue;
					case 263:
						if ((ex->disc->version >= 19981111L && ex->disc->matchf) ? (*ex->disc->matchf)(ex, x, (*t)->string, expr->data.operand.left, v.string, env, ex->disc) : strmatch((*t)->string, v.string))
							break;
						continue;
					case 262:
						if ((*t)->floating == v.floating)
							break;
						continue;
					}
					n = 1;
					break;
				}
			if (n)
			{
				if (!x->data.select.statement)
				{
					r.integer = 1;
					break;
				}
				r = eval(ex, x->data.select.statement, env);
				if (ex->loopcount > 0)
				{
					ex->loopcount--;
					break;
				}
			}
		}
		if (!n && a)
		{
			r = eval(ex, a, env);
			if (ex->loopcount > 0)
				ex->loopcount--;
		}
		return r;
	case 281:
		v.integer = 0;
		if (expr->data.generate.array->op == 275)
		{
			n = expr->data.generate.index->type == 263;
			for (assoc = (Exassoc_t*)(*(((Dt_t*)((Dt_t*)expr->data.generate.array->data.variable.symbol->local.pointer))->searchf))(((Dt_t*)expr->data.generate.array->data.variable.symbol->local.pointer),(void*)(0),0000200); assoc; assoc = (Exassoc_t*)(*(((Dt_t*)((Dt_t*)expr->data.generate.array->data.variable.symbol->local.pointer))->searchf))(((Dt_t*)expr->data.generate.array->data.variable.symbol->local.pointer),(void*)(assoc),0000010))
			{
				v.integer++;
				if (n)
					expr->data.generate.index->value->data.constant.value.string = assoc->name;
				else
					expr->data.generate.index->value->data.constant.value = assoc->key;
				eval(ex, expr->data.generate.statement, env);
				if (ex->loopcount > 0 && (--ex->loopcount > 0 || ex->loopop != 272))
				{
					v.integer = 0;
					break;
				}
			}
		}
		else
		{
			r = (*ex->disc->getf)(ex, expr, expr->data.generate.array->data.variable.symbol, expr->data.generate.array->data.variable.reference, env, 0, ex->disc);
			for (v.integer = 0; v.integer < r.integer; v.integer++)
			{
				expr->data.generate.index->value->data.constant.value.integer = v.integer;
				eval(ex, expr->data.generate.statement, env);
				if (ex->loopcount > 0 && (--ex->loopcount > 0 || ex->loopop != 272))
				{
					v.integer = 0;
					break;
				}
			}
		}
		return v;
    case 282:
		v.integer = 0;
		if (expr->data.generate.array->op == 275) {
			n = expr->data.generate.index->type == 263;
			for (assoc = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.generate.array->
 data.variable.symbol->local.
 pointer))->searchf))(((Dt_t *) expr->data.generate.array->
 data.variable.symbol->local.
 pointer),(void*)(0),0000400); assoc;
		 		assoc = (Exassoc_t *) (*(((Dt_t*)((Dt_t *) expr->data.generate.array->
 data.variable.symbol->local.pointer))->searchf))(((Dt_t *) expr->data.generate.array->
 data.variable.symbol->local.pointer),(void*)(
 assoc),0000020)) {
				v.integer++;
				if (n)
					expr->data.generate.index->value->data.constant.value.string = assoc->name;
				else
					expr->data.generate.index->value->data.constant.value = assoc->key;
				eval(ex, expr->data.generate.statement, env);
				if (ex->loopcount > 0 && (--ex->loopcount > 0 || ex->loopop != 272)) {
					v.integer = 0;
					break;
				}
			}
		} else {
			r = (*ex->disc->getf) (ex, expr, expr->data.generate.array->data.
				   variable.symbol, expr->data.generate.array->data.  variable.reference, env, 0, ex->disc);
			for (v.integer = r.integer-1; 0 <= v.integer; v.integer--) {
				expr->data.generate.index->value->data.constant.value.integer = v.integer;
				eval(ex, expr->data.generate.statement, env);
				if (ex->loopcount > 0 && (--ex->loopcount > 0 || ex->loopop != 272)) {
					v.integer = 0;
					break;
				}
			}
		}
		return v;
	case '#':
		v.integer = dtsize ((Dt_t*)expr->data.variable.symbol->local.pointer);
		return v;
	case 331:
		v.integer = evaldyn (ex, expr, env, 0);
		return v;
	case 306:
		if (expr->data.variable.index) {
			v.integer = evaldyn (ex, expr, env, 1);
		}
		else {
			(*(((Dt_t*)((Dt_t*)expr->data.variable.symbol->local.pointer))->searchf))(((Dt_t*)expr->data.variable.symbol->local.pointer),(void*)(0),0000100);
			v.integer = 0;
		}
		return v;
	case 269:
		x = expr->data.call.args;
		for (n = 0, a = expr->data.call.procedure->value->data.procedure.args; a && x; a = a->data.operand.right)
		{
			if (n < (sizeof(args)/sizeof(args[0])))
			{
				save[n] = a->data.operand.left->data.variable.symbol->value->data.constant.value;
				args[n++] = eval(ex, x->data.operand.left, env);
			}
			else
				a->data.operand.left->data.variable.symbol->value->data.constant.value = eval(ex, x->data.operand.left, env);
			x = x->data.operand.right;
		}
		for (n = 0, a = expr->data.call.procedure->value->data.procedure.args; a && n < (sizeof(save)/sizeof(save[0])); a = a->data.operand.right)
			a->data.operand.left->data.variable.symbol->value->data.constant.value = args[n++];
		if (x)
			exerror("too many actual args");
		else if (a)
			exerror("not enough actual args");
		v = exeval(ex, expr->data.call.procedure->value->data.procedure.body, env);
		for (n = 0, a = expr->data.call.procedure->value->data.procedure.args; a && n < (sizeof(save)/sizeof(save[0])); a = a->data.operand.right)
			a->data.operand.left->data.variable.symbol->value->data.constant.value = save[n++];
		return v;
	case 267:
		n = 0;
		for (x = expr->data.operand.right; x && n < (sizeof(args)/sizeof(args[0])); x = x->data.operand.right)
			args[n++] = eval(ex, x->data.operand.left, env);
		return (*ex->disc->getf) (ex, expr->data.operand.left, expr->data.operand.left->data.variable.symbol,
			expr->data.operand.left->data.variable.reference, args, (-3), ex->disc);
	case 279:
		n = 0;
		args[n++].string = (char*)env;
		for (x = expr->data.operand.right; x && n < (sizeof(args)/sizeof(args[0])); x = x->data.operand.right)
			args[n++] = eval(ex, x->data.operand.left, env);
		return (*ex->disc->getf)(ex, expr->data.operand.left, expr->data.operand.left->data.variable.symbol, expr->data.operand.left->data.variable.reference, args+1, (-2), ex->disc);
	case 283:
		if (expr->data.variable.index)
			i = eval(ex, expr->data.variable.index, env);
		else
			i.integer = (-1);

		if (expr->data.variable.dyna) {
			Extype_t locv;
			locv = getdyn(ex, expr->data.variable.dyna, env, &assoc);
			expr->data.variable.dyna->data.variable.dyna->data.constant.  value = locv;
		}

		return (*ex->disc->getf)(ex, expr, expr->data.variable.symbol, expr->data.variable.reference, env, (int)i.integer, ex->disc);
	case 334:
		n = 1;
		goto add;
	case 291:
		v.integer = prints(ex, expr, env, sfstdout);
		return v;
	case 292:
		v.integer = print(ex, expr, env, 0);
		return v;

	
		
		
		

	case 296:
		ex->loopret = eval(ex, x, env);
		ex->loopcount = 32767;
		ex->loopop = expr->op;
		return ex->loopret;
	case 297:
	case 301:
		v.integer = scan(ex, expr, env, 0);
		return v;
	case 299:
		print(ex, expr, env, ex->tmp);
		v.string = exstash(ex->tmp, ex->ve);
		return v;
	case '=':
		v = eval(ex, expr->data.operand.right, env);
		if (expr->subop != '=')
		{
			r = v;
			if (x->op == 275)
				v = getdyn(ex, x, env, &assoc);
			else
			{
				if (x->data.variable.index)
					v = eval(ex, x->data.variable.index, env);
				else
					v.integer = (-1);

				if (x->data.variable.dyna) {
					Extype_t locv;
					locv = getdyn(ex, x->data.variable.dyna, env, &assoc);
					x->data.variable.dyna->data.variable.dyna->data.  constant.value = locv;
				}

				v = (*ex->disc->getf)(ex, x, x->data.variable.symbol, x->data.variable.reference, env, (int)v.integer, ex->disc);
			}
			switch (x->type)
			{
			case 262:
				switch (expr->subop)
				{
				case '+':
					v.floating += r.floating;
					break;
				case '-':
					v.floating -= r.floating;
					break;
				case '*':
					v.floating *= r.floating;
					break;
				case '/':
					if (r.floating == 0.0)
						exerror("floating divide by 0");
					else
						v.floating /= r.floating;
					break;
				case '%':
					if ((r.integer = r.floating) == 0)
						exerror("floating 0 modulus");
					else
						v.floating = ((_ast_intmax_t)v.floating) % r.integer;
					break;
				case '&':
					v.floating = ((_ast_intmax_t)v.floating) & ((_ast_intmax_t)r.floating);
					break;
				case '|':
					v.floating = ((_ast_intmax_t)v.floating) | ((_ast_intmax_t)r.floating);
					break;
				case '^':
					v.floating = ((_ast_intmax_t)v.floating) ^ ((_ast_intmax_t)r.floating);
					break;
				case 330:
					v.floating = ((_ast_intmax_t)v.floating) << ((_ast_intmax_t)r.floating);
					break;
				case 329:

					

					v.floating = ((unsigned _ast_intmax_t)v.floating) >> ((_ast_intmax_t)r.floating);

					break;
				default:
					goto huh;
				}
				break;
			case 259:
			case 260:
				switch (expr->subop)
				{
				case '+':
					v.integer += r.integer;
					break;
				case '-':
					v.integer -= r.integer;
					break;
				case '*':
					v.integer *= r.integer;
					break;
				case '/':
					if (r.integer == 0)
						exerror("integer divide by 0");
					else
						v.integer /= r.integer;
					break;
				case '%':
					if (r.integer == 0)
						exerror("integer 0 modulus");
					else
						v.integer %= r.integer;
					break;
				case '&':
					v.integer &= r.integer;
					break;
				case '|':
					v.integer |= r.integer;
					break;
				case '^':
					v.integer ^= r.integer;
					break;
				case 330:
					v.integer <<= r.integer;
					break;
				case 329:
					v.integer = (unsigned _ast_intmax_t)v.integer >> r.integer;
					break;
				default:
					goto huh;
				}
				break;
			case 263:
				switch (expr->subop)
				{
				case '+':
					v.string = str_add(ex, v.string, r.string);
					break;
				case '|':
					v.string = str_ior(ex, v.string, r.string);
					break;
				case '&':
					v.string = str_and(ex, v.string, r.string);
					break;
				case '^':
					v.string = str_xor(ex, v.string, r.string);
					break;
				case '%':
					v.string = str_mod(ex, v.string, r.string);
					break;
				case '*':
					v.string = str_mpy(ex, v.string, r.string);
					break;
				default:
					goto huh;
				}
				break;
			default:
				goto huh;
			}
		}
		else if (x->op == 275)
			getdyn(ex, x, env, &assoc);
		else
			assoc = 0;
		r = v;
		goto set;
	case ';':
	case ',':
		v = eval(ex, x, env);
		while ((expr = expr->data.operand.right) && (expr->op == ';' || expr->op == ','))
		{
			v = eval(ex, expr->data.operand.left, env);
			if (ex->loopcount)
				return v;
		}
		return expr ? eval(ex, expr, env) : v;
	case '?':
		v = eval(ex, x, env);
		return v.integer ? eval(ex, expr->data.operand.right->data.operand.left, env) : eval(ex, expr->data.operand.right->data.operand.right, env);
	case 324:
		v = eval(ex, x, env);
		return v.integer ? eval(ex, expr->data.operand.right, env) : v;
	case 323:
		v = eval(ex, x, env);
		return v.integer ? v : eval(ex, expr->data.operand.right, env);
	}
	v = eval(ex, x, env);
	if ((x = expr->data.operand.right)) {
		r = eval(ex, x, env);
		if (!((x->type) > 258) && expr->binary) {
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			rtmp = *x;
			rtmp.data.constant.value = r;
			if (!(*ex->disc->binaryf) (ex, &tmp, expr, &rtmp, 0, ex->disc)) return tmp.data.constant.value;
		}
	}
	switch (expr->data.operand.left->type)
	{
	case 262:
		switch (expr->op)
		{
		case 308:
			v.integer = v.floating;
			return v;
		case 309:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if (expr->data.operand.left->op != 275 && expr->data.operand.left->op != 283)
			{
				sfprintf(ex->tmp, "%g", v.floating);
				tmp.data.constant.value.string = exstash(ex->tmp, ex->ve);
			}
			else if ((*ex->disc->convertf)(ex, &tmp, 263, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc)) {
				sfprintf(ex->tmp, "%g", v.floating);
				tmp.data.constant.value.string = exstash(ex->tmp, ex->ve);
			}
			tmp.type = 263;
			return tmp.data.constant.value;
		case 315:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if ((*ex->disc->convertf)(ex, &tmp, expr->type, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc))
				exerror("%s: cannot convert floating value to external", tmp.data.variable.symbol->name);
			tmp.type = expr->type;
			return tmp.data.constant.value;
		case '!':
			v.floating = !((_ast_intmax_t)v.floating);
			return v;
		case '~':
			v.floating = ~((_ast_intmax_t)v.floating);
			return v;
		case '-':
			if (x)
				v.floating -= r.floating;
			else
				v.floating = -v.floating;
			return v;
		case '+':
			v.floating += r.floating;
			return v;
		case '&':
			v.floating = (_ast_intmax_t)v.floating & (_ast_intmax_t)r.floating;
			return v;
		case '|':
			v.floating = (_ast_intmax_t)v.floating | (_ast_intmax_t)r.floating;
			return v;
		case '^':
			v.floating = (_ast_intmax_t)v.floating ^ (_ast_intmax_t)r.floating;
			return v;
		case '*':
			v.floating *= r.floating;
			return v;
		case '/':
			if (r.floating == 0.0)
				exerror("floating divide by 0");
			else
				v.floating /= r.floating;
			return v;
		case '%':
			if ((r.integer = r.floating) == 0)
				exerror("floating 0 modulus");
			else
				v.floating = (_ast_intmax_t)v.floating % r.integer;
			return v;
		case '<':
			v.integer = v.floating < r.floating;
			return v;
		case 328:
			v.integer = v.floating <= r.floating;
			return v;
		case 326:
			v.integer = v.floating == r.floating;
			return v;
		case 325:
			v.integer = v.floating != r.floating;
			return v;
		case 327:
			v.integer = v.floating >= r.floating;
			return v;
		case '>':
			v.integer = v.floating > r.floating;
			return v;
		case 330:
/* IBM compilers can't deal with these shift operators on long long.
 *                                      v.floating = ((Sflong_t)v.floating) << ((Sflong_t)r.floating);
 */
			{
				_ast_intmax_t op1, op2;
				op1 = ((_ast_intmax_t) v.floating);
				op2 = ((_ast_intmax_t) r.floating);
				v.floating = (double) (op1 << op2);
			}
			return v;
		case 329:

			

/* IBM compilers can't deal with these shift operators on long long.
 *                                      v.floating = ((Sfulong_t)v.floating) >> ((Sflong_t)r.floating);
 */
			{
				_ast_intmax_t op1, op2;
				op1 = ((unsigned _ast_intmax_t) v.floating);
				op2 = ((_ast_intmax_t) r.floating);
				v.floating = (double) (op1 >> op2);
			}


			return v;
		}
		break;
	default:
		switch (expr->op)
		{
		case 318:
			xConvert(ex, expr, 262, v, &tmp);
			return tmp.data.constant.value;
		case 319:
			xConvert(ex, expr, 259, v, &tmp);
			return tmp.data.constant.value;
		case 320:
			xConvert(ex, expr, 263, v, &tmp);
			return tmp.data.constant.value;
		case 321:
			xConvert(ex, expr, expr->type, v, &tmp);
			return tmp.data.constant.value;
		case 322:
			xPrint(ex, expr, v, &tmp);
			return tmp.data.constant.value;
		default:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if (x) {
				rtmp = *x;
				rtmp.data.constant.value = r;
				rp = &rtmp;
			} else
				rp = 0;
			if (!(*ex->disc->binaryf) (ex, &tmp, expr, rp, 0, ex->disc))
				return tmp.data.constant.value;
		}
		goto integer;
	case 260:
		switch (expr->op)
		{
		case '<':
			v.integer = (unsigned _ast_intmax_t)v.integer < (unsigned _ast_intmax_t)r.integer;
			return v;
		case 328:
			v.integer = (unsigned _ast_intmax_t)v.integer <= (unsigned _ast_intmax_t)r.integer;
			return v;
		case 327:
			v.integer = (unsigned _ast_intmax_t)v.integer >= (unsigned _ast_intmax_t)r.integer;
			return v;
		case '>':
			v.integer = (unsigned _ast_intmax_t)v.integer > (unsigned _ast_intmax_t)r.integer;
			return v;
		}
		/*FALLTHROUGH*/
	case 259:
	integer:
		switch (expr->op)
		{
		case 310:

			

			if (expr->type == 260)
				v.floating = (unsigned _ast_intmax_t)v.integer;
			else
				v.floating = v.integer;

			return v;
		case 311:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if (expr->data.operand.left->op != 275 && expr->data.operand.left->op != 283)
			{
				if (expr->data.operand.left->type == 260)
					sfprintf(ex->tmp, "%I*u", sizeof(v.integer), v.integer);
				else
					sfprintf(ex->tmp, "%I*d", sizeof(v.integer), v.integer);
				tmp.data.constant.value.string = exstash(ex->tmp, ex->ve);
			}
			else if ((*ex->disc->convertf)(ex, &tmp, 263, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc)) {
				if (expr->data.operand.left->type == 260)
					sfprintf(ex->tmp, "%I*u", sizeof(v.integer), v.integer);
				else
					sfprintf(ex->tmp, "%I*d", sizeof(v.integer), v.integer);
				tmp.data.constant.value.string =  exstash(ex->tmp, ex->ve);
			}
			tmp.type = 263;
			return tmp.data.constant.value;
		case 316:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if ((*ex->disc->convertf)(ex, &tmp, expr->type, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc))
				exerror("%s: cannot convert integer value to external", tmp.data.variable.symbol->name);
			tmp.type = expr->type;
			return tmp.data.constant.value;
		case '!':
			v.integer = !v.integer;
			return v;
		case '~':
			v.integer = ~v.integer;
			return v;
		case '-':
			if (x)
				v.integer -= r.integer;
			else
				v.integer = -v.integer;
			return v;
		case '+':
			v.integer += r.integer;
			return v;
		case '&':
			v.integer &= r.integer;
			return v;
		case '|':
			v.integer |= r.integer;
			return v;
		case '^':
			v.integer ^= r.integer;
			return v;
		case '*':
			v.integer *= r.integer;
			return v;
		case '/':
			if (r.integer == 0)
				exerror("integer divide by 0");
			else
				v.integer /= r.integer;
			return v;
		case '%':
			if (r.integer == 0)
				exerror("integer 0 modulus");
			else
				v.integer %= r.integer;
			return v;
		case 326:
			v.integer = v.integer == r.integer;
			return v;
		case 325:
			v.integer = v.integer != r.integer;
			return v;
		case 330:
/* IBM compilers can't deal with these shift operators on long long.
 *                      v.floating = (Sflong_t)v.floating << (Sflong_t)r.floating;
 */
			{
				_ast_intmax_t op1, op2;
				op1 = ((_ast_intmax_t) v.floating);
				op2 = ((_ast_intmax_t) r.floating);
				v.floating = (double) (op1 << op2);
			}
			return v;
		case 329:
/* IBM compilers can't deal with these shift operators on long long.
 *                      v.integer = ((Sfulong_t)v.floating) >> (Sflong_t)r.floating;
 */
			{
				unsigned _ast_intmax_t op1;
				_ast_intmax_t op2;
				op1 = ((unsigned _ast_intmax_t) v.floating);
				op2 = ((_ast_intmax_t) r.floating);
				v.integer = (op1 >> op2);
			}
			return v;
		case '<':
			v.integer = v.integer < r.integer;
			return v;
		case 328:
			v.integer = v.integer <= r.integer;
			return v;
		case 327:
			v.integer = v.integer >= r.integer;
			return v;
		case '>':
			v.integer = v.integer > r.integer;
			return v;
		}
		break;
	case 263:
		switch (expr->op)
		{
		case 312:
			v.integer = *v.string != 0;
			return v;
		case 313:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if ((*ex->disc->convertf)(ex, &tmp, 262, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc))
			{
				tmp.data.constant.value.floating = strtod(v.string, &e);
				if (*e)
					tmp.data.constant.value.floating = *v.string != 0;
			}
			tmp.type = 262;
			return tmp.data.constant.value;
		case 314:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if ((*ex->disc->convertf)(ex, &tmp, 259, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc))
			{
				if (v.string) {
					tmp.data.constant.value.integer = strtoll(v.string, &e, 0);
                    if (*e)
                        tmp.data.constant.value.integer = *v.string != 0;
				}
				else
					tmp.data.constant.value.integer = 0;
			}
			tmp.type = 259;
			return tmp.data.constant.value;
		case 317:
			tmp = *expr->data.operand.left;
			tmp.data.constant.value = v;
			if ((*ex->disc->convertf)(ex, &tmp, expr->type, expr->data.operand.right ? expr->data.operand.right->data.variable.symbol : (Exid_t*)0, 0, ex->disc))
				exerror("%s: cannot convert string value to external", tmp.data.variable.symbol->name);
			tmp.type = expr->type;
			return tmp.data.constant.value;
		case 326:
		case 325:
			v.integer = ((v.string && r.string) ? ((ex->disc->version >= 19981111L && ex->disc->matchf) ? (*ex->disc->matchf)(ex, expr->data.operand.left, v.string, expr->data.operand.right, r.string, env, ex->disc) : strmatch(v.string, r.string)) : (v.string == r.string)) == (expr->op == 326);
			return v;
		case '+':
			v.string = str_add(ex, v.string, r.string);
			return v;
		case '|':
			v.string = str_ior(ex, v.string, r.string);
			return v;
		case '&':
			v.string = str_and(ex, v.string, r.string);
			return v;
		case '^':
			v.string = str_xor(ex, v.string, r.string);
			return v;
		case '%':
			v.string = str_mod(ex, v.string, r.string);
			return v;
		case '*':
			v.string = str_mpy(ex, v.string, r.string);
			return v;
		}
		v.integer = strcoll(v.string, r.string);
		switch (expr->op)
		{
		case '<':
			v.integer = v.integer < 0;
			return v;
		case 328:
			v.integer = v.integer <= 0;
			return v;
		case 327:
			v.integer = v.integer >= 0;
			return v;
		case '>':
			v.integer = v.integer > 0;
			return v;
		}
		goto huh;
	}
 huh:
	if (expr->binary)
		exerror("operator %s %s %s not implemented", lexname(expr->data.operand.left->type, -1), lexname(expr->op, expr->subop), expr->data.operand.right ? lexname(expr->data.operand.right->type, -1) : "UNARY");
	else
		exerror("operator %s %s not implemented", lexname(expr->op, expr->subop), lexname(expr->data.operand.left->type, -1));
	return exzero(expr->type);
}

/*
 * evaluate expression expr
 */

Extype_t
exeval(Expr_t* ex, Exnode_t* expr, void* env)
{
	Extype_t	v;

	vmclear(ex->ve);
	if (expr->compiled.integer)
	{
		switch (expr->type)
		{
		case 262:
			v.floating = (*expr->compiled.floating)(ex->disc->data);
			break;
		case 263:
			v.string = (*expr->compiled.string)(ex->disc->data);
			break;
		default:
			v.integer = (*expr->compiled.integer)(ex->disc->data);
			break;
		}
	}
	else
	{
		v = eval(ex, expr, env);
		if (ex->loopcount > 0)
		{
			ex->loopcount = 0;
			if (ex->loopop == 296)
				return ex->loopret;
		}
	}
	return v;
}












    
    
    

    
    
	
	
	    
	
	    
    
	
    



/* exstring:
 * Generate copy of input string using
 * string memory.
 */
char *exstring(Expr_t * ex, char *s)
{
    return vmstrdup(ex->ve, s);
}

/* exstralloc:
 * If p = NULL, allocate sz bytes in expression
 * memory; otherwise, realloc.
 */
void *exstralloc(Expr_t * ex, void *p, size_t sz)
{
    return (*(((Vmalloc_t*)(ex->ve))->meth.resizef)) ((ex->ve),(void*)(p),(sz),(0000001 | 0000002));
}

/* exstrfree:
 * Free memory obtained from exstralloc.
 */
int exstrfree(Expr_t * ex, void *p)
{
    return (*(((Vmalloc_t*)(ex->ve))->meth.freef))((ex->ve),(void*)(p));
}

