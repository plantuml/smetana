#line 1 "graphviz-2.38.0\\lib\\expr\\extoken.c" 1
/* $Id$ $Revision$ */
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
 * expression library default lexical analyzer
 */


#line 1 "graphviz-2.38.0\\lib\\expr\\extoken.c" 1


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






#line 25 "graphviz-2.38.0\\lib\\expr\\extoken.c" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\extoken.c" 1














	
	
	
	

	
	
	
	
		
		
	
		
		
		
			
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
	
		
		
			
			
			
			
			
		
		
	
	
		

	
		











	



	
	
	








/*
 * get the next expression char
 */

static int
lex(register Expr_t* ex)
{
	register int	c;

	for (;;)
	{
		if ((c = ex->input->peek))
			ex->input->peek = 0;
		else if (ex->input->pp)
		{
			if (!(c = *ex->input->pp++))
			{
				ex->input->pp = 0;
				continue;
			}
		}
		else if (ex->input->sp)
		{
			if (!(c = *ex->input->sp++))
			{
				if (!expop(ex))
					continue;
				else ;
				ex->input->sp--;
			}
		}
		else if (ex->input->fp)
		{
			if ((c = ( (((Sfio_t*)(ex->input->fp))->next >= ((Sfio_t*)(ex->input->fp))->endr ? _sffilbuf(((Sfio_t*)(ex->input->fp)),0) : (int)(*((Sfio_t*)(ex->input->fp))->next++) ) )) == (-1))
			{
				if (!expop(ex))
					continue;
				else ;
				c = 0;
			}
			else if ((ex->disc->flags & (1<<3)) && c == '\n' && ex->input->next && !ex->input->next->next && ex->input->nesting <= 0)
			{
				_err_info.line++;
				expop(ex);
				;
				c = 0;
			}
		}
		else c = 0;
		if (c == '\n')
			((ex)->linep=(ex)->line,(ex)->linewrap=0);
		else if (c)
			(((ex)->linep>=&(ex)->line[sizeof((ex)->line)]?(ex)->linep=(ex)->line,(ex)->linewrap=1:0),*(ex)->linep++=(c));
		;
		return c;
	}
}

/*
 * get the next expression token
 */

int
extoken_fn(register Expr_t* ex)
{
	register int	c;
	register char*	s;
	register int	q;
	int		b;
	char*		e;
	Dt_t*		v;

	if (ex->eof || ex->errors)
		return 0;
 again:
	for (;;)
		switch (c = lex(ex))
		{
		case 0:
			goto eof;
		case '/':
			switch (q = lex(ex))
			{
			case '*':
				for (;;) switch (lex(ex))
				{
				case '\n':
					if (_err_info.line)
						_err_info.line++;
					else _err_info.line = 2;
					continue;
				case '*':
					switch (lex(ex))
					{
					case 0:
						goto eof;
					case '\n':
						if (_err_info.line)
							_err_info.line++;
						else _err_info.line = 2;
						break;
					case '*':
						((ex)->linep--,(ex)->input->peek=('*'));
						break;
					case '/':
						goto again;
					}
					break;
				}
				break;
			case '/':
				while ((c = lex(ex)) != '\n')
					if (!c)
						goto eof;
				break;
			default:
				goto opeq;
			}
			/*FALLTHROUGH*/
		case '\n':
			if (_err_info.line)
				_err_info.line++;
			else _err_info.line = 2;
			/*FALLTHROUGH*/
		case ' ':
		case '\t':
			break;
		case '(':
		case '{':
		case '[':
			ex->input->nesting++;
			return exlval.op = c;
		case ')':
		case '}':
		case ']':
			ex->input->nesting--;
			return exlval.op = c;
		case '+':
		case '-':
			if ((q = lex(ex)) == c)
				return exlval.op = c == '+' ? 334 : 333;
			goto opeq;
		case '*':
		case '%':
		case '^':
			q = lex(ex);
		opeq:
			exlval.op = c;
			if (q == '=')
				c = '=';
			else if (q == '%' && c == '%')
			{
				if (ex->input->fp)
					ex->more = (const char*)ex->input->fp;
				else ex->more = ex->input->sp;
				goto eof;
			}
			else ((ex)->linep--,(ex)->input->peek=(q));
			return c;
		case '&':
		case '|':
			if ((q = lex(ex)) == '=')
			{
				exlval.op = c;
				return '=';
			}
			if (q == c)
				c = c == '&' ? 324 : 323;
			else ((ex)->linep--,(ex)->input->peek=(q));
			return exlval.op = c;
		case '<':
		case '>':
			if ((q = lex(ex)) == c)
			{
				exlval.op = c = c == '<' ? 330 : 329;
				if ((q = lex(ex)) == '=')
					c = '=';
				else ((ex)->linep--,(ex)->input->peek=(q));
				return c;
			}
			goto relational;
		case '=':
		case '!':
			q = lex(ex);
		relational:
			if (q == '=') switch (c)
			{
			case '<':
				c = 328;
				break;
			case '>':
				c = 327;
				break;
			case '=':
				c = 326;
				break;
			case '!':
				c = 325;
				break;
			}
			else ((ex)->linep--,(ex)->input->peek=(q));
			return exlval.op = c;
		case '#':
			if (!ex->linewrap && !(ex->disc->flags & (1<<4)))
			{
				s = ex->linep - 1;
				while (s > ex->line && isspace(*(s - 1)))
					s--;
				if (s == ex->line)
				{
					switch (extoken_fn(ex))
					{
					case 275:
					case 283:
					case 287:
						s = exlval.id->name;
						break;
					default:
						s = "";
						break;
					}
					if ((*(s)==*("include")&&!strcmp(s,"include")))
					{
						if (extoken_fn(ex) != 263)
							exerror("#%s: string argument expected", s);
						else if (!expush(ex, exlval.string, 1, 0, 0))
						{
							((ex)->linep=(ex)->line,(ex)->linewrap=0);
							goto again;
						}
					}
					else exerror("unknown directive");
				}
			}
			return exlval.op = c;
		case '\'':
		case '"':
			q = c;
			( (((0) < 0 || (0) > (ex->tmp)->size) ? (char*)0 : (char*)((ex->tmp)->next = (ex->tmp)->data+(0)) ) );
			ex->input->nesting++;
			while ((c = lex(ex)) != q)
			{
				if (c == '\\')
				{
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					c = lex(ex);
				}
				if (!c)
				{
					exerror("unterminated %c string", q);
					goto eof;
				}
				if (c == '\n')
				{
					if (_err_info.line)
						_err_info.line++;
					else _err_info.line = 2;
				}
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
			}
			ex->input->nesting--;
			s = exstash(ex->tmp, 0);
			if (q == '"' || (ex->disc->flags & (1<<0)))
			{
				if (!(exlval.string = vmstrdup(ex->vm, s)))
					goto eof;
				stresc(exlval.string);
				return 263;
			}
			exlval.integer = chrtoi(s);
			return 259;
		case '.':
			if (isdigit(c = lex(ex)))
			{
				( (((0) < 0 || (0) > (ex->tmp)->size) ? (char*)0 : (char*)((ex->tmp)->next = (ex->tmp)->data+(0)) ) );
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)(('0')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)(('0'))) ) );
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)(('.')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)(('.'))) ) );
				goto floating;
			}
			((ex)->linep--,(ex)->input->peek=(c));
			return exlval.op = '.';
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			( (((0) < 0 || (0) > (ex->tmp)->size) ? (char*)0 : (char*)((ex->tmp)->next = (ex->tmp)->data+(0)) ) );
			( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
			q = 259;
			b = 0;
			if ((c = lex(ex)) == 'x' || c == 'X')
			{
				b = 16;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				for (;;)
				{
					switch (c = lex(ex))
					{
					case '0': case '1': case '2': case '3': case '4':
					case '5': case '6': case '7': case '8': case '9':
					case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': 
					case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
						continue;
					}
					break;
				}
			}
			else
			{
				while (isdigit(c))
				{
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					c = lex(ex);
				}
				if (c == '#')
				{
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					/* s = exstash(ex->tmp, NiL); */
					/* b = strtol(s, NiL, 10); */
					do
					{
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					} while (isalnum(c = lex(ex)));
				}
				else
				{
					if (c == '.')
					{
					floating:
						q = 262;
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
						while (isdigit(c = lex(ex)))
							( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					}
					if (c == 'e' || c == 'E')
					{
						q = 262;
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
						if ((c = lex(ex)) == '-' || c == '+')
						{
							( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
							c = lex(ex);
						}
						while (isdigit(c))
						{
							( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
							c = lex(ex);
						}
					}
				}
			}
			s = exstash(ex->tmp, 0);
			if (q == 262)
				exlval.floating = strtod(s, &e);
			else
			{
				if (c == 'u' || c == 'U')
				{
					q = 260;
					c = lex(ex);
					exlval.integer = strtoull(s, &e, b);
				}
				else
					exlval.integer = strtoll(s, &e, b);
				if (*e)
				{
					*--e = 1;
					exlval.integer *= strton(e, &e, 0, 0);
				}
			}
			((ex)->linep--,(ex)->input->peek=(c));
			if (*e || isalpha(c) || c == '_' || c == '$')
			{
				exerror("%s: invalid numeric constant", s);
				goto eof;
			}
			return q;
		default:
			if (isalpha(c) || c == '_' || c == '$')
			{
				( (((0) < 0 || (0) > (ex->tmp)->size) ? (char*)0 : (char*)((ex->tmp)->next = (ex->tmp)->data+(0)) ) );
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				while (isalnum(c = lex(ex)) || c == '_' || c == '$')
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				((ex)->linep--,(ex)->input->peek=(c));
				s = exstash(ex->tmp, 0);
				/* v = expr.declare ? dtview(ex->symbols, NiL) : (Dt_t*)0; FIX */
				v = (Dt_t*)0;
				exlval.id = (Exid_t*)(*(((Dt_t*)(ex->symbols))->searchf))((ex->symbols),(void*)(s),0001000);
				if (v)
					dtview(ex->symbols, v);
				if (!exlval.id)
				{
					if (!(exlval.id = ((0)?(Exid_t*)realloc((char*)(0),sizeof(Exid_t)*(1)+(strlen(s) - 32 + 1)):(Exid_t*)calloc(1,sizeof(Exid_t)*(1)+(strlen(s) - 32 + 1)))))
					{
						exnospace();
						goto eof;
					}
					strcpy(exlval.id->name, s);
					exlval.id->lex = 287;
					expr.statics += exlval.id->isstatic = expr.instatic;

					/*
					 * LABELs are in the parent scope!
					 */

					if (c == ':' && !expr.nolabel && ex->frame && ex->frame->view)
						(*(((Dt_t*)(ex->frame->view))->searchf))((ex->frame->view),(void*)(exlval.id),0000001);
					else
						(*(((Dt_t*)(ex->symbols))->searchf))((ex->symbols),(void*)(exlval.id),0000001);
				}

				/*
				 * lexical analyzer state controlled by the grammar
				 */

				switch (exlval.id->lex)
				{
				case 273:
					if (exlval.id->index == 261)
					{
						/*
						 * `char*' === `string'
						 * the * must immediately follow char
						 */

						if (c == '*')
						{
							lex(ex);
							exlval.id = (&exbuiltin[0]);
						}
					}
					break;
				case 287:
					/*
					 * action labels are disambiguated from ?:
					 * through the expr.nolabel grammar hook
					 * the : must immediately follow labels
					 */

					if (c == ':' && !expr.nolabel)
						return 285;
					break;
				case 289:
					/*
					 * user specific statement stripped and
					 * passed as string
					 */

					{
						int	b;
						int	n;
						int	pc;
						int	po;
						int	t;

						/*UNDENT...*/
		( (((0) < 0 || (0) > (ex->tmp)->size) ? (char*)0 : (char*)((ex->tmp)->next = (ex->tmp)->data+(0)) ) );
		b = 1;
		n = 0;
		po = 0;
		t = 0;
		for (c = t = lex(ex);; c = lex(ex))
		{
			switch (c)
			{
			case 0:
				goto eof;
			case '/':
				switch (q = lex(ex))
				{
				case '*':
					for (;;)
					{
						switch (lex(ex))
						{
						case '\n':
							if (_err_info.line)
								_err_info.line++;
							else _err_info.line = 2;
							continue;
						case '*':
							switch (lex(ex))
							{
							case 0:
								goto eof;
							case '\n':
								if (_err_info.line)
									_err_info.line++;
								else _err_info.line = 2;
								continue;
							case '*':
								((ex)->linep--,(ex)->input->peek=('*'));
								continue;
							case '/':
								break;
							default:
								continue;
							}
							break;
						}
						if (!b++)
							goto eof;
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((' ')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((' '))) ) );
						break;
					}
					break;
				case '/':
					while ((c = lex(ex)) != '\n')
						if (!c)
							goto eof;
					if (_err_info.line)
						_err_info.line++;
					else _err_info.line = 2;
					b = 1;
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)(('\n')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)(('\n'))) ) );
					break;
				default:
					b = 0;
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((q)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((q))) ) );
					break;
				}
				continue;
			case '\n':
				if (_err_info.line)
					_err_info.line++;
				else _err_info.line = 2;
				b = 1;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)(('\n')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)(('\n'))) ) );
				continue;
			case ' ':
			case '\t':
				if (!b++)
					goto eof;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((' ')))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((' '))) ) );
				continue;
			case '(':
			case '{':
			case '[':
				b = 0;
				if (!po)
				{
					switch (po = c)
					{
					case '(':
						pc = ')';
						break;
					case '{':
						pc = '}';
						break;
					case '[':
						pc = ']';
						break;
					}
					n++;
				}
				else if (c == po)
					n++;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				continue;
			case ')':
			case '}':
			case ']':
				b = 0;
				if (!po)
				{
					((ex)->linep--,(ex)->input->peek=(c));
					break;
				}
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				if (c == pc && --n <= 0)
				{
					if (t == po)
						break;
					po = 0;
				}
				continue;
			case ';':
				b = 0;
				if (!n)
					break;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				continue;
			case '\'':
			case '"':
				b = 0;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				ex->input->nesting++;
				q = c;
				while ((c = lex(ex)) != q)
				{
					if (c == '\\')
					{
						( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
						c = lex(ex);
					}
					if (!c)
					{
						exerror("unterminated %c string", q);
						goto eof;
					}
					if (c == '\n')
					{
						if (_err_info.line)
							_err_info.line++;
						else _err_info.line = 2;
					}
					( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				}
				ex->input->nesting--;
				continue;
			default:
				b = 0;
				( (((Sfio_t*)((ex->tmp)))->next >= ((Sfio_t*)((ex->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((ex->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((ex->tmp)))->next++ = (unsigned char)((c))) ) );
				continue;
			}
			break;
		}
		(*ex->disc->reff)(ex, 0, exlval.id, 0, exstash(ex->tmp, 0), 0, ex->disc);

						/*..INDENT*/
					}
					goto again;
				}
				return exlval.id->lex;
			}
			return exlval.op = c;
		}
 eof:
	ex->eof = 1;
	return exlval.op = ';';
}
