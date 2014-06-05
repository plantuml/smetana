#line 1 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 1
/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */


/* Bison version.  */


/* Skeleton name.  */


/* Pure parsers.  */


/* Push parsers.  */


/* Pull parsers.  */





/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */



/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library grammar and compiler
 */









#line 1 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 1
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






#line 75 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 2




/* Line 336 of yacc.c  */










/* Enabling verbose error messages.  */







/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */


/* Enabling traces.  */




extern int yydebug;


/* Tokens.  */


   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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



















































































typedef union YYSTYPE
{
/* Line 350 of yacc.c  */


	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	_ast_intmax_t	integer;
	int		op;
	char*		string;
	void*		user;
	struct Exbuf_s*	buffer;


/* Line 350 of yacc.c  */

} YYSTYPE;





extern YYSTYPE yylval;











int yyparse ();





/* Copy the second part of user declarations.  */
/* Line 353 of yacc.c  */



#line 1 "graphviz-2.38.0\\lib\\expr\\exgram.h" 1
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
 * grammar support routines
 * stuffed in a header so exparse.y can work
 * with both yacc and bison
 * sometimes free stuff can cost a lot
 */








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















































   

   
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   


























































































	
	
	
	
	
	
	
	
	




























#line 40 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



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

























































#line 43 "graphviz-2.38.0\\lib\\expr\\expr.h" 2
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
























#line 44 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



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


typedef YYSTYPE Extype_t;

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






#line 30 "graphviz-2.38.0\\lib\\expr\\exgram.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\exgram.h" 1






static int		a2t[] = { 0, 262, 259, 263 };
static Switch_t		swstate;

Exstate_t		expr;

static int T(int t) 
{
	if (expr.program->disc->types)
	    return expr.program->disc->types[t & ((1<<4)-1)];
	else
	    return a2t[t & ((1<<4)-1)];
}

/*
 * allocate and initialize a new expression node in the current program
 */

Exnode_t*
exnewnode(Expr_t* p, int op, int binary, int type, Exnode_t* left, Exnode_t* right)
{
	register Exnode_t*	x;

	x = (Exnode_t*)(char*)(*(((Vmalloc_t*)(((p)->vm)))->meth.resizef)) ((((p)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Exnode_t))+(0)),((0000002|0000001|0000004)));
	x->op = op;
	x->type = type;
	x->binary = binary;
	x->local.number = 0;
	x->local.pointer = 0;
	x->data.operand.left = left;
	x->data.operand.right = right;
	return x;
}

/*
 * free node x and its children
 */

void
exfreenode(Expr_t* p, register Exnode_t* x)
{
	register Print_t*	pr;
	register Exref_t*	r;
	Print_t*		pn;
	Exref_t*		rn;
	int			i;

	switch (x->op)
	{
	case 269:
		if (x->data.call.args)
			exfreenode(p, x->data.call.args);
		break;
	case 271:
		break;
	case 274:
		if (x->data.select.next)
			exfreenode(p, x->data.select.next);
		break;
	case 275:
		if (x->data.variable.index)
			exfreenode(p, x->data.variable.index);
		if (x->data.variable.symbol->local.pointer)
		{
			dtclose((Dt_t*)x->data.variable.symbol->local.pointer);
			x->data.variable.symbol->local.pointer = 0;
		}
		break;
	case '#':
		if (x->data.variable.symbol->local.pointer) {
			dtclose((Dt_t *) x->data.variable.symbol->local.pointer);
			x->data.variable.symbol->local.pointer = 0;
		}
		break;
//	case IN_OP:
	case 306:
		if (x->data.variable.index)
			exfreenode(p, x->data.variable.index);
		if (x->data.variable.symbol->local.pointer) {
			dtclose((Dt_t *) x->data.variable.symbol->local.pointer);
			x->data.variable.symbol->local.pointer = 0;
		}
		break;
	case 281:
	case 282:
		if (x->data.generate.statement)
			exfreenode(p, x->data.generate.statement);
		break;
	case 283:
		rn = x->data.variable.reference;
		while ((r = rn))
		{
			rn = r->next;
			(*(((Vmalloc_t*)(p->vm))->meth.freef))((p->vm),(void*)(r));
		}
		if (x->data.variable.index)
			exfreenode(p, x->data.variable.index);
		break;
	case 280:
	case 302:
	case 303:
		exfreenode(p, x->data.string.base);
		exfreenode(p, x->data.string.pat);
		if (x->data.string.repl)
			exfreenode(p, x->data.string.repl);
		break;
	case 305:
	case 298:
		if (x->data.split.seps)
			exfreenode(p, x->data.split.seps);
		exfreenode(p, x->data.split.string);
		if (x->data.split.array->local.pointer) {
			dtclose((Dt_t *) x->data.split.array->local.pointer);
			x->data.split.array->local.pointer = 0;
		}
		break;
	case 291:
		exfreenode(p, x->data.operand.left);
		break;
	case 292:
	case 299:
		if (x->data.print.descriptor)
			exfreenode(p, x->data.print.descriptor);
		pn = x->data.print.args;
		while ((pr = pn))
		{
			for (i = 0; i < (sizeof(pr->param)/sizeof(pr->param[0])) && pr->param[i]; i++)
				exfreenode(p, pr->param[i]);
			if (pr->arg)
				exfreenode(p, pr->arg);
			pn = pr->next;
			(*(((Vmalloc_t*)(p->vm))->meth.freef))((p->vm),(void*)(pr));
		}
		break;
	default:
		if (x->data.operand.left)
			exfreenode(p, x->data.operand.left);
		if (x->data.operand.right)
			exfreenode(p, x->data.operand.right);
		break;
	}
	(*(((Vmalloc_t*)(p->vm))->meth.freef))((p->vm),(void*)(x));
}

/* extract:
 * Given an argument list, extract first argument,
 * check its type, reset argument list, and 
 * return first argument.
 * Return 0 on failure.
 */
static Exnode_t *extract(Expr_t * p, Exnode_t ** argp, int type) {
	Exnode_t *args = *argp;
	Exnode_t *left;

	if (!args || (type != args->data.operand.left->type))
	    return 0;
	*argp = args->data.operand.right;
	left = args->data.operand.left;
	args->data.operand.left = args->data.operand.right = 0;
	exfreenode(p, args);
	return left;
}

/* exnewsplit:
 * Generate split/tokens node.
 * Fifth argument is optional.
 */
static Exnode_t *exnewsplit(Expr_t * p, int op, Exid_t* dyn, Exnode_t * s, Exnode_t* seps) {
	Exnode_t *ss = 0;

	if (dyn->local.pointer == 0)
              	exerror("cannot use non-array %s in %s", dyn->name, exopname(op));
	if ((dyn->index_type > 0) && (dyn->index_type != 259))
            exerror("in %s, array %s must have integer index type, not %s", 
		exopname(op), dyn->name, extypename(p, s->type));
	if (dyn->type != 263)
            exerror("in %s, array %s entries must have string type, not %s", 
		exopname(op), dyn->name, extypename(p, s->type));
	if (s->type != 263)
            exerror("first argument to %s must have string type, not %s", 
		exopname(op), extypename(p, s->type));
	if (seps && (seps->type != 263))
            exerror("third argument to %s must have string type, not %s", 
		exopname(op), extypename(p, seps->type));
	ss = exnewnode(p, op, 0, 259, 0, 0);
	ss->data.split.array = dyn;
	ss->data.split.string = s;
	ss->data.split.seps = seps;
	return ss;
}

/* exnewsub:
 * Generate sub node.
 * Third argument is optional.
 */
static Exnode_t *exnewsub(Expr_t * p, Exnode_t * args, int op) {
	Exnode_t *base;
	Exnode_t *pat;
	Exnode_t *repl;
	Exnode_t *ss = 0;

	base = extract(p, &args, 263);
	if (!base)
	    exerror("invalid first argument to sub operator");
	pat = extract(p, &args, 263);
	if (!pat)
	    exerror("invalid second argument to sub operator");
	if (args) {
	    repl = extract(p, &args, 263);
	    if (!repl)
		exerror("invalid third argument to sub operator");
	} else
	    repl = 0;
	if (args)
	    exerror("too many arguments to sub operator");
	ss = exnewnode(p, op, 0, 263, 0, 0);
	ss->data.string.base = base;
	ss->data.string.pat = pat;
	ss->data.string.repl = repl;
	return ss;
}

/* exnewsubstr:
 * Generate substr node.
 */
static Exnode_t *exnewsubstr(Expr_t * p, Exnode_t * args) {
	Exnode_t *base;
	Exnode_t *pat;
	Exnode_t *repl;
	Exnode_t *ss = 0;

	base = extract(p, &args, 263);
	if (!base)
	    exerror("invalid first argument to substr operator");
	pat = extract(p, &args, 259);
	if (!pat)
	    exerror("invalid second argument to substr operator");
	if (args) {
	    repl = extract(p, &args, 259);
	    if (!repl)
		exerror("invalid third argument to substr operator");
	} else
	    repl = 0;
	if (args)
	    exerror("too many arguments to substr operator");
	ss = exnewnode(p, 303, 0, 263, 0, 0);
	ss->data.string.base = base;
	ss->data.string.pat = pat;
	ss->data.string.repl = repl;
	return ss;
}

/* exstringOf:
 * Cast x to type STRING
 * Assume x->type != STRING
 */
static Exnode_t *exstringOf(Expr_t * p, register Exnode_t * x) {
	int type = x->type;
	int cvt = 0;

	if (!type) {
	    x->type = 263;
	    return x;
	}
	if (!((type) > 258) && !p->disc->stringof)
	    exerror("cannot convert %s to STRING", extypename(p, type));
	if (x->op != 271) {
	    if (!((type) > 258)) {
		if ((*p->disc->stringof) (p, x, 1, p->disc) < 0) {
		    exerror("cannot convert %s to STRING",
			    extypename(p, type));
		}
		cvt = 322;
	    } else
		switch (type) {
		case 262:
		    cvt = 309;
		    break;
		case 259:
		    cvt = 311;
		    break;
		}
	    x = exnewnode(p, cvt, 0, 263, x, 0);
	} else if (!((type) > 258)) {
	    if ((*p->disc->stringof) (p, x, 0, p->disc) < 0)
		exerror("cannot convert constant %s to STRING",
			extypename(p, x->type));
	} else
	    switch (type) {
	    case 262:
		sfprintf(p->tmp, "%g", x->data.constant.value.floating);
		x->data.constant.value.string =
		    vmstrdup(p->vm, (( (((Sfio_t*)((p->tmp)))->next >= ((Sfio_t*)((p->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((p->tmp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((p->tmp)))->next++ = (unsigned char)((0))) ) ), (char*)((p->tmp)->next = (p->tmp)->data) ));
		break;
	    case 259:
		sfprintf(p->tmp, "%I*d",
			 sizeof(x->data.constant.value.integer),
			 x->data.constant.value.integer);
		x->data.constant.value.string =
		    vmstrdup(p->vm, (( (((Sfio_t*)((p->tmp)))->next >= ((Sfio_t*)((p->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((p->tmp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((p->tmp)))->next++ = (unsigned char)((0))) ) ), (char*)((p->tmp)->next = (p->tmp)->data) ));
		break;
	    default:
		exerror("internal error: %d: unknown type", type);
		break;
	    }
	x->type = 263;
	return x;
}

/* exprint:
 * Generate argument list of strings.
 */
static Exnode_t *exprint(Expr_t * p, Exid_t * ex, Exnode_t * args) {
	Exnode_t *arg = args;
	Exnode_t *pr;

	while (arg) {
	    if (arg->data.operand.left->type != 263)
		arg->data.operand.left =
		    exstringOf(p, arg->data.operand.left);
	    arg = arg->data.operand.right;
	}
	pr = exnewnode(p, ex->index, 1, ex->type, args, 0);
	return pr;
}

/* makeVar:
 *
 * Create variable from s[idx].refs 
 * If s is DYNAMIC, refs is non-empty and dyna represents s[idx].
 * The rightmost element in s[idx].refs becomes the dominant symbol,
 * and the prefix gets stored in refs. (This format is used to simplify
 * the yacc parser.)
 */
static Exnode_t *makeVar(Expr_t * prog, Exid_t * s, Exnode_t * idx,
			     Exnode_t * dyna, Exref_t * refs) {
	Exnode_t *nn;
	int kind;
	Exid_t *sym;

	/* parse components */
	if (refs) {
	    if (refs->next) {
		sym = refs->next->symbol;
		refs->next->symbol = refs->symbol;
	    } else
		sym = refs->symbol;
	    refs->symbol = s;
	    refs->index = idx;
	} else
	    sym = s;

	if (sym->type)
	    kind = sym->type;
	else
	    kind = 263;

	nn = exnewnode(prog, 283, 0, kind, 0, 0);
	nn->data.variable.symbol = sym;
	nn->data.variable.reference = refs;
	nn->data.variable.index = 0;
	nn->data.variable.dyna = dyna;
	if (!prog->disc->getf)
	    exerror("%s: identifier references not supported", sym->name);
	else if (expr.program->disc->reff)
	    (*expr.program->disc->reff) (prog, nn,
					 nn->data.variable.symbol, refs,
					 0, (-1), prog->disc);

	return nn;
}

/*
 * cast x to type
 */

static char*	typename[] =
{
	"external", "integer", "unsigned", "char", "float", "string"
};

static int	typecast[6][6] =
{
	{321,	319,	319,	319,	318,	320},
	{316,	0,	0,	0,	310,	311},
	{316,	0,	0,	0,	310,	311},
	{316,	0,	0,	0,	310,	311},
	{315,	308,	308,	308,	0,	309},
	{317,	314,	314,	314,	313,	0},
};







char *extypename(Expr_t * p, int type) {
	if (((type) > 258))
	    return typename[(((type)>=259&&(type)<=263)?((type)-259+1):0)];
	return (p->disc->typename) (p, type);
}

/* exnoncast:
 * Return first non-cast node.
 */
Exnode_t *exnoncast(register Exnode_t * x) {
	while (x && (x->op >= 308) && (x->op <= 321))
	    x = x->data.operand.left;
	return x;
}

Exnode_t*
excast(Expr_t* p, register Exnode_t* x, register int type, register Exnode_t* xref, int arg)
{
	register int	t2t;
	char*		s;
	char*		e;

	if (x && x->type != type && type && type != 264)
	{
		if (!x->type)
		{
			x->type = type;
			return x;
		}
		if (!(t2t = typecast[(((x->type)>=259&&(x->type)<=263)?((x->type)-259+1):0)][(((type)>=259&&(type)<=263)?((type)-259+1):0)]))
			return x;
		if (((t2t)>=315) && !p->disc->convertf)
			exerror("cannot convert %s to %s", extypename(p, x->type), extypename(p, type));
		if (x->op != 271) {
			Exid_t *sym = (xref ? xref->data.variable.symbol : 0);
			if (((t2t)>=315)) {
				int a = (arg ? arg : 1);
		    	if ((*p->disc->convertf) (p, x, type, sym, a, p->disc) < 0) {
					if (xref) {
						if ((sym->lex == 279) && arg)
							exerror ("%s: cannot use value of type %s as argument %d in function %s",
				     			sym->name, extypename(p, x->type),
				     			arg, sym->name);
						else
							exerror("%s: cannot convert %s to %s",
							xref->data.variable.symbol->name,
							extypename(p, x->type),
							extypename(p, type));
					} else {
			    		exerror("cannot convert %s to %s",
							extypename(p, x->type), extypename(p, type));
					}
				}
			}
			x = exnewnode(p, t2t, 0, type, x, xref);
		}
		else switch (t2t)
		{
		case 315:
		case 316:
		case 317:
		case 318:
		case 319:
		case 320:
		case 321:
			if (xref && xref->op == 283)
			{
				if ((*p->disc->convertf)(p, x, type, xref->data.variable.symbol, arg, p->disc) < 0)
					exerror("%s: cannot cast constant %s to %s", xref->data.variable.symbol->name, extypename(p, x->type), extypename(p, type));
			}
			else if ((*p->disc->convertf)(p, x, type, 0, arg, p->disc) < 0)
				exerror("cannot cast constant %s to %s", extypename(p, x->type), extypename(p, type));
			break;
		case 308:
			x->data.constant.value.integer = x->data.constant.value.floating;
			break;
		case 309:
			sfprintf(p->tmp, "%g", x->data.constant.value.floating);
			x->data.constant.value.string = exstash(p->tmp, p->vm);
			break;
		case 310:
			x->data.constant.value.floating = x->data.constant.value.integer;
			break;
		case 311:
			sfprintf(p->tmp, "%I*d", sizeof(x->data.constant.value.integer), x->data.constant.value.integer);
			x->data.constant.value.string = exstash(p->tmp, p->vm);
			break;
		case 313:
			s =  x->data.constant.value.string;
			x->data.constant.value.integer = strtod(s, &e);
			if (*e)
				x->data.constant.value.floating = (*s != 0);
			break;
		case 314:
			s = x->data.constant.value.string;
			x->data.constant.value.integer = strtoll(s, &e, 0);
			if (*e)
				x->data.constant.value.integer = (*s != 0);
			break;
		default:
			exerror("internal error: %d: unknown cast op", t2t);
			break;
		}
		x->type = type;
	}
	return x;
}











	
	
	

	
	
		
			
		
		
		
		
		
		
		
		
			
			
			
			
				
			
			
				
				
					
				
				
				
				
			
			
		
			
			
		
			
			
			
		
			
			
		
			
			
			
		
			
			
		
			
			
		
			
			
		
	
	




/*
 * force ref . sym qualification
 */

static Exid_t*
qualify(register Exref_t* ref, register Exid_t* sym)
{
	register Exid_t*	x;
	char*			s;

	while (ref->next)
		ref = ref->next;
	sfprintf(expr.program->tmp, "%s.%s", ref->symbol->name, sym->name);
	s = exstash(expr.program->tmp, 0);
	if (!(x = (Exid_t*)(*(((Dt_t*)(expr.program->symbols))->searchf))((expr.program->symbols),(void*)(s),0001000)))
	{
		if ((x = ((0)?(Exid_t*)realloc((char*)(0),sizeof(Exid_t)*(1)+(strlen(s) - 32 + 1)):(Exid_t*)calloc(1,sizeof(Exid_t)*(1)+(strlen(s) - 32 + 1)))))
		{
			memcpy(x, sym, sizeof(Exid_t) - 32);
			strcpy(x->name, s);
			(*(((Dt_t*)(expr.program->symbols))->searchf))((expr.program->symbols),(void*)(x),0000001);
		}
		else
		{
			exnospace();
			x = sym;
		}
	}
	return x;
}

/*
 * check function call arg types and count
 * return function identifier node
 */

static Exnode_t*
call(Exref_t* ref, register Exid_t* fun, register Exnode_t* args)
{
	register int	t;
	register int	type;
	Exnode_t*	x;
	int		num;

	x = exnewnode(expr.program, 283, 0, 0, 0, 0);
	t = fun->type;
	x->data.variable.symbol = fun = ((ref)&&(expr.program->disc->flags&(1<<5))?qualify(ref,fun):(fun));
	x->data.variable.reference = ref;
	num = 0;
	((t)>>=4);
	while ((type = T(t)))
	{
		if (!args)
		{
			exerror("%s: not enough args", fun->name);
			return args;
		}
		num++;
		if (type != args->data.operand.left->type)
			args->data.operand.left = excast(expr.program, args->data.operand.left, type, 0, num);
		args = args->data.operand.right;
		((t)>>=4);
	}
	if (args)
		exerror("%s: too many args", fun->name);
	return x;
}

/*
 * precompile a printf/scanf call
 */

static Print_t*
preprint(register Exnode_t* args)
{
	register Print_t*	x;
	register char*		s;
	register int		c;
	int			t;
	int			i;
	int			n;
	char*			e;
	char*			f;
	Print_t*		p = 0;
	Print_t*		q;

	if (!args || args->data.operand.left->type != 263)
		exerror("format string argument expected");
	if (args->data.operand.left->op != 271)
	{
		x = (Print_t*)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Print_t))+(0)),((0000002|0000001|0000004)));
		memset(x,0,sizeof(*x));
		x->arg = args;
		return x;
	}
	f = args->data.operand.left->data.constant.value.string;
	args = args->data.operand.right;
	for (s = f; *s; s++)
	{
		( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)((*s)))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)((*s))) ) );
		if (*s == '%')
		{
			if (!*++s)
				exerror("%s: trailing %% in format", f);
			if (*s != '%')
				break;
			if (args)
				( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)(('%')))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)(('%'))) ) );
		}
	}
	x = 0;
	for (;;)
	{
		q = (Print_t*)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Print_t))+(0)),((0000002|0000001|0000004)));
		if (x)
			x->next = q;
		else
			p = q;
		x = q;
		memset(x,0,sizeof(*x));
		if (*s)
		{
			i = 0;
			t = 259;
			for (;;)
			{
				switch (c = *s++)
				{
				case 0:
					exerror("unterminated %%... in format");
					goto done;
				case '*':
					if (i >= (sizeof(x->param)/sizeof(x->param[0])))
					{
						*s = 0;
						exerror("format %s has too many * arguments", f);
						goto done;
					}
					if (!args)
					{
						*s = 0;
						exerror("format %s * argument expected", f);
						goto done;
					}
					x->param[i++] = args->data.operand.left;
					args = args->data.operand.right;
					break;
				case '(':
					n = 1;
					for (;;)
					{
						( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)((c))) ) );
						switch (c = *s++)
						{
						case 0:
							s--;
							break;
						case '(':
							n++;
							continue;
						case ')':
							if (--n <= 0)
								break;
							continue;
						default:
							continue;
						}
						break;
					}
					break;
				case 'c':
				case 'd':
					goto specified;
				case 'e':
				case 'f':
				case 'g':
					t = 262;
					goto specified;
				case 'h':
					exerror("short formats not supported");
					goto done;
				case 'l':
					t = 259;
					break;
				case 'o':
				case 'u':
				case 'x':
				case 'T':
					t = 260;
					goto specified;
				case 's':
				case 'S':
					t = 263;
					goto specified;
				default:
					if (isalpha(c))
						goto specified;
					break;
				}
				( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)((c))) ) );
			}
		specified:
			( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)((c))) ) );
			for (e = s; *s; s++)
			{
				if (*s == '%')
				{
					if (!*++s)
					{
						*e = 0;
						exerror("%s: trailing %% in format", f);
						goto done;
					}
					if (*s != '%')
					{
						s--;
						break;
					}
				}
				( (((Sfio_t*)((expr.program->tmp)))->next >= ((Sfio_t*)((expr.program->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((expr.program->tmp))),(int)((unsigned char)((*s)))) : (int)(*((Sfio_t*)((expr.program->tmp)))->next++ = (unsigned char)((*s))) ) );
			}
			if (!args)
			{
				*e = 0;
				exerror("%s format argument expected", f);
				goto done;
			}
			x->arg = args->data.operand.left;
			switch (t)
			{
			case 262:
				if (x->arg->type != 262)
					x->arg = exnewnode(expr.program, x->arg->type == 263 ? 313 : ((x->arg->type)>=259&&(x->arg->type)<=261) ? 310 : 318, 0, 262, x->arg, x->arg->op == 283 ? x->arg : (Exnode_t*)0);
				break;
			case 259:
			case 260:
				if (!((x->arg->type)>=259&&(x->arg->type)<=261))
					x->arg = exnewnode(expr.program, x->arg->type == 263 ? 314 : x->arg->type == 262 ? 308 : 319, 0, 259, x->arg, x->arg->op == 283 ? x->arg : (Exnode_t*)0);
				x->arg->type = t;
				break;
			case 263:
				if (x->arg->type != 263)
				{
					if (x->arg->op == 271 && x->arg->data.constant.reference && expr.program->disc->convertf)
					{
						if ((*expr.program->disc->convertf)(expr.program, x->arg, 263, x->arg->data.constant.reference, 0, expr.program->disc) < 0)
							exerror("cannot convert string format argument");
						else x->arg->data.constant.value.string = vmstrdup(expr.program->vm, x->arg->data.constant.value.string);
					}
					else if (!expr.program->disc->convertf || (x->arg->op != 283 && x->arg->op != 275 && x->arg->op != 315 && x->arg->op != 316 && x->arg->op != 317))
						exerror("string format argument expected");
					else
						x->arg = exnewnode(expr.program, x->arg->type == 262 ? 309 : ((x->arg->type)>=259&&(x->arg->type)<=261) ? 311 : 320, 0, 263, x->arg, x->arg->op == 283 ? x->arg : (Exnode_t*)0);
				}
				break;
			}
			args = args->data.operand.right;
		}
		x->format = exstash(expr.program->tmp, expr.program->vm);
		if (!*s)
			break;
		f = s;
	}
	if (args)
		exerror("too many format arguments");
 done:
	( (((0) < 0 || (0) > (expr.program->tmp)->size) ? (char*)0 : (char*)((expr.program->tmp)->next = (expr.program->tmp)->data+(0)) ) );
	return p;
}

/*
 * push a new input stream and program
 */

int
expush(Expr_t* p, const char* name, int line, const char* sp, Sfio_t* fp)
{
	register Exinput_t*	in;
	register char*		s;
	char			buf[1024];

	if (!(in = ((0)?(Exinput_t*)realloc((char*)(0),sizeof(Exinput_t)*(1)+(0)):(Exinput_t*)calloc(1,sizeof(Exinput_t)*(1)+(0)))))
	{
		exnospace();
		return -1;
	}
	if (!p->input)
		p->input = &expr.null;
	if (!(in->bp = in->sp = (char*)sp))
	{
		if ((in->fp = fp))
			in->close = 0;
		else if (name)
		{
			if (!(s = pathfind(name, p->disc->lib, p->disc->type, buf, sizeof(buf))) || !(in->fp = sfopen(0, s, "r")))
			{
				exerror("%s: file not found", name);
				in->bp = in->sp = "";
			}
			else
			{
				name = (const char*)vmstrdup(p->vm, s);
				in->close = 1;
			}
		}
	}
	else in->fp = 0;
	if (!(in->next = p->input)->next)
	{
		p->errors = 0;
		if (!(p->disc->flags & (1<<3)))
		{
			if (line >= 0)
				_err_info.line = line;
		}
		else if (!_err_info.line)
			_err_info.line = 1;
	}
	else if (line >= 0)
		_err_info.line = line;
	((p)->linep=(p)->line,(p)->linewrap=0);
	p->eof = 0;
	p->input = in;
	in->file = _err_info.file;
	if (line >= 0)
		_err_info.file = (char*)name;
	in->line = _err_info.line;
	in->nesting = 0;
	in->unit = !name && !line;
	p->program = expr.program;
	expr.program = p;
	return 0;
}

/*
 * pop the current input stream
 */

int
expop(register Expr_t* p)
{
	register int		c;
	register Exinput_t*	in;

	if (!(in = p->input) || !in->next || in->unit)
		return -1;
	if (in->nesting)
		exerror("unbalanced quote or nesting construct");
	_err_info.file = in->file;
	if (in->next->next)
		_err_info.line = in->line;
	else
	{
		if (p->errors && in->fp && p->linep != p->line)
			while ((c = ( (((Sfio_t*)(in->fp))->next >= ((Sfio_t*)(in->fp))->endr ? _sffilbuf(((Sfio_t*)(in->fp)),0) : (int)(*((Sfio_t*)(in->fp))->next++) ) )) != (-1))
				if (c == '\n')
				{
					_err_info.line++;
					break;
				}
		if (!(p->disc->flags & (1<<3)))
			_err_info.line = in->line;
	}
	if (in->fp && in->close)
		sfclose(in->fp);
	if (in->pushback)
		free(in->pushback);
	p->input = in->next;
	free(in);
	((p)->linep=(p)->line,(p)->linewrap=0);
	if (p->program)
		expr.program = p->program;
	return 0;
}

/*
 * clear global state of stale pointers
 */

void exinit(void) {
	memset (&expr, 0, sizeof(Exstate_t));
}

/*
 * compile the expression in [sf]p
 */

int
excomp(register Expr_t* p, const char* name, int line, const char* sp, Sfio_t* fp)
{
	Exid_t*	v;
	int	eof;

	p->more = 0;
	eof = p->eof;
	if (!sp && !fp)
	{
		if (!p->input)
			return -1;
	}
	else if (expush(p, name, line, sp, fp))
		return -1;
	else
		p->input->unit = line >= 0;
	exparse();
	p->input->unit = 0;
	expop(p);
	p->eof = eof;
	if (expr.statics)
	{
		for (v = (Exid_t*)(*(((Dt_t*)(p->symbols))->searchf))((p->symbols),(void*)(0),0000200); v; v = (Exid_t*)(*(((Dt_t*)(p->symbols))->searchf))((p->symbols),(void*)(v),0000010))
			if (v->isstatic)
			{
				(*(((Dt_t*)(p->symbols))->searchf))((p->symbols),(void*)(v),0000002);
				if (!--expr.statics)
					break;
			}
		expr.statics = 0;
	}
	return 0;
}

/*
 * free the program p
 */

void
exclose(register Expr_t* p, int all)
{
	register int		i;
	register Exinput_t*	in;

	if (p)
	{
		if (all)
		{
			for (i = 3; i < (sizeof(p->file)/sizeof(p->file[0])); i++)
				if (p->file[i])
					sfclose(p->file[i]);
			if (p->vm)
				vmclose(p->vm);
			if (p->ve)
				vmclose(p->ve);
			if (p->symbols)
				dtclose(p->symbols);
			if (p->tmp)
				sfclose(p->tmp);
			while ((in = p->input))
			{
				if (in->pushback)
					free(in->pushback);
				if (in->fp && in->close)
					sfclose(in->fp);
				if ((p->input = in->next))
					free(in);
			}
			free(p);
		}
		else
		{
			vmclear(p->ve);
			p->main.value = 0;
		}
	}
}

/* checkBinary:
 * See if application wants to allow the given expression
 * combination. l and r give the operands; the operator
 * is given by ex. r may be NULL.
 */
static void
checkBinary(Expr_t * p, Exnode_t * l, Exnode_t * ex, Exnode_t * r) 
{
	if ((*p->disc->binaryf) (p, l, ex, r, 1, p->disc) < 0) {
	    if (r)
		exerror
		    ("cannot apply operator %s to expressions of types %s and %s",
		     exopname(ex->op), extypename(p, l->type),
		     extypename(p, r->type));
	    else
		exerror
		    ("cannot apply operator %s to expression of type %s",
		     exopname(ex->op), extypename(p, l->type));
	}
}

/* checkName:
 * We allow parser to accept any name in a declaration, in
 * order to check that the name is undeclared and give a better
 * error message if it isn't.
 */
static void checkName(Exid_t * id) 
{
	switch (id->lex) {
	case 275:
	    exerror("Variable \"%s\" already declared", id->name);
	    break;
	case 279:
	    exerror("Name \"%s\" already used as a function", id->name);
	    break;
	case 283:
	    exerror("Name \"%s\" already used as a keyword", id->name);
	    break;
	case 287:
	    break;
	default:
	    _err_msg(0x00ff,
		  "Unexpected token \"%s\" as name in dcl_item", id->name);
	    break;
	}
}

static int
cmpKey(Dt_t * d, Extype_t * key1, Extype_t * key2, Dtdisc_t * disc) 
{
	if (key1->integer < key2->integer)
	    return -1;
	else if (key1->integer > key2->integer)
	    return 1;
	else
	    return 0;
}

int
exisAssign(Exnode_t * n) 
{
	return ((n->op == '=') && (n->subop == '='));
}






#line 212 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 2


/* Line 353 of yacc.c  */









typedef unsigned char yytype_uint8;








typedef short int yytype_int8;





typedef unsigned short int yytype_uint16;





typedef short int yytype_int16;






























/* Suppress unused-variable warnings by "using" E.  */






/* Identity function, used to suppress warnings about constant conditions.  */










    


  





/* The parser invokes alloca or malloc; define the necessary symbols.  */

















      









   


    









































/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */


/* The size of an array large to enough to hold all stacks, each with
   N elements.  */






/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */














/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */

















/* YYFINAL -- State number of the termination state.  */

/* YYLAST -- Last index in YYTABLE.  */


/* YYNTOKENS -- Number of terminals.  */

/* YYNNTS -- Number of nonterminals.  */

/* YYNRULES -- Number of rules.  */

/* YYNRULES -- Number of states.  */


/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */






/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,    93,     2,    90,    76,     2,
      98,   103,    88,    85,    68,    86,   106,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,   102,
      79,    69,    80,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    74,   101,    92,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    72,    73,    77,    78,    81,    82,    83,
      84,    87,    94,    95,    96,    97,    99
};


/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    16,    17,    20,
      24,    27,    28,    29,    36,    43,    49,    59,    65,    70,
      77,    83,    84,    93,    97,   101,   105,   106,   109,   112,
     114,   117,   121,   124,   125,   127,   129,   133,   134,   139,
     141,   143,   145,   147,   149,   151,   152,   155,   156,   158,
     162,   167,   171,   175,   179,   183,   187,   191,   195,   199,
     203,   207,   211,   215,   219,   223,   227,   231,   235,   239,
     243,   244,   245,   253,   256,   259,   262,   265,   268,   271,
     276,   281,   286,   291,   296,   303,   312,   317,   321,   325,
     330,   335,   340,   345,   350,   353,   356,   359,   363,   366,
     369,   371,   373,   375,   377,   379,   381,   383,   385,   387,
     389,   391,   393,   395,   398,   402,   404,   405,   408,   412,
     413,   417,   418,   420,   422,   426,   427,   429,   431,   433,
     437,   438,   442,   443,   445,   449,   452,   455,   456,   459,
     461,   462,   463
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     108,     0,    -1,   112,   109,    -1,    -1,   109,   110,    -1,
      -1,    30,    71,   111,   112,    -1,    -1,   112,   113,    -1,
     100,   112,   101,    -1,   128,   102,    -1,    -1,    -1,   121,
     114,    18,   115,   122,   102,    -1,    29,    98,   129,   103,
     113,   127,    -1,    23,    98,   136,   103,   113,    -1,    23,
      98,   128,   102,   128,   102,   128,   103,   113,    -1,    27,
      98,   136,   103,   113,    -1,    51,    98,    20,   103,    -1,
      51,    98,    20,    68,   129,   103,    -1,    52,    98,   129,
     103,   113,    -1,    -1,    49,    98,   129,   116,   103,   100,
     117,   101,    -1,    13,   128,   102,    -1,    17,   128,   102,
      -1,    41,   128,   102,    -1,    -1,   117,   118,    -1,   119,
     112,    -1,   120,    -1,   119,   120,    -1,    15,   133,    71,
      -1,    19,    71,    -1,    -1,    10,    -1,   123,    -1,   122,
      68,   123,    -1,    -1,   125,   124,   137,   148,    -1,    32,
      -1,    20,    -1,    28,    -1,    24,    -1,    32,    -1,    20,
      -1,    -1,    21,   113,    -1,    -1,   129,    -1,    98,   129,
     103,    -1,    98,    18,   103,   129,    -1,   129,    79,   129,
      -1,   129,    86,   129,    -1,   129,    88,   129,    -1,   129,
      89,   129,    -1,   129,    90,   129,    -1,   129,    84,   129,
      -1,   129,    83,   129,    -1,   129,    80,   129,    -1,   129,
      82,   129,    -1,   129,    81,   129,    -1,   129,    78,   129,
      -1,   129,    77,   129,    -1,   129,    76,   129,    -1,   129,
      74,   129,    -1,   129,    75,   129,    -1,   129,    85,   129,
      -1,   129,    73,   129,    -1,   129,    72,   129,    -1,   129,
      68,   129,    -1,    -1,    -1,   129,    70,   130,   129,    71,
     131,   129,    -1,    91,   129,    -1,    93,    20,    -1,    92,
     129,    -1,    86,   129,    -1,    85,   129,    -1,    76,   136,
      -1,    12,   104,   139,   105,    -1,    24,    98,   139,   103,
      -1,    25,    98,   139,   103,    -1,    47,    98,   139,   103,
      -1,    48,    98,   139,   103,    -1,   132,    98,   129,    68,
      20,   103,    -1,   132,    98,   129,    68,    20,    68,   129,
     103,    -1,    22,    98,   129,   103,    -1,    40,    98,   103,
      -1,    45,    98,   103,    -1,    45,    98,   129,   103,    -1,
      38,    98,   139,   103,    -1,    36,    98,   139,   103,    -1,
     134,    98,   139,   103,    -1,   135,    98,   139,   103,    -1,
     136,   147,    -1,    96,   136,    -1,   136,    96,    -1,   129,
      87,    20,    -1,    95,   136,    -1,   136,    95,    -1,   133,
      -1,    43,    -1,    50,    -1,    16,    -1,     7,    -1,     4,
      -1,     8,    -1,     5,    -1,    37,    -1,    39,    -1,    44,
      -1,    42,    -1,    46,    -1,    28,   145,    -1,    20,   138,
     145,    -1,    32,    -1,    -1,   104,   105,    -1,   104,    18,
     105,    -1,    -1,   104,   129,   105,    -1,    -1,   140,    -1,
     129,    -1,   140,    68,   129,    -1,    -1,    18,    -1,   142,
      -1,   143,    -1,   142,    68,   143,    -1,    -1,    18,   144,
     126,    -1,    -1,   146,    -1,   106,    28,   146,    -1,   106,
      28,    -1,   106,    32,    -1,    -1,    69,   129,    -1,   147,
      -1,    -1,    -1,    98,   149,   141,   150,   103,   100,   112,
     101,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   195,   196,   199,   199,   239,   242,   269,
     273,   277,   277,   277,   282,   292,   305,   320,   333,   341,
     352,   362,   362,   374,   386,   390,   403,   433,   436,   468,
     469,   472,   493,   500,   503,   509,   510,   517,   517,   573,
     574,   575,   576,   579,   580,   584,   587,   594,   597,   600,
     604,   608,   653,   657,   661,   665,   669,   673,   677,   681,
     685,   689,   693,   697,   701,   705,   709,   713,   726,   730,
     740,   740,   740,   781,   801,   808,   812,   816,   820,   824,
     828,   838,   842,   846,   850,   854,   858,   864,   868,   872,
     878,   883,   887,   912,   948,   972,   980,   988,   999,  1003,
    1007,  1010,  1011,  1013,  1021,  1026,  1031,  1036,  1043,  1044,
    1045,  1048,  1049,  1052,  1056,  1076,  1089,  1092,  1096,  1110,
    1113,  1120,  1123,  1131,  1136,  1143,  1146,  1152,  1155,  1159,
    1170,  1170,  1183,  1186,  1198,  1217,  1221,  1227,  1230,  1237,
    1238,  1255,  1238
};



/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINTOKEN", "INTEGER", "UNSIGNED",
  "CHARACTER", "FLOATING", "STRING", "VOIDTYPE", "STATIC", "ADDRESS",
  "ARRAY", "BREAK", "CALL", "CASE", "CONSTANT", "CONTINUE", "DECLARE",
  "DEFAULT", "DYNAMIC", "ELSE", "EXIT", "FOR", "FUNCTION", "GSUB",
  "ITERATE", "ITERATER", "ID", "IF", "LABEL", "MEMBER", "NAME", "POS",
  "PRAGMA", "PRE", "PRINT", "PRINTF", "PROCEDURE", "QUERY", "RAND",
  "RETURN", "SCANF", "SPLIT", "SPRINTF", "SRAND", "SSCANF", "SUB",
  "SUBSTR", "SWITCH", "TOKENS", "UNSET", "WHILE", "F2I", "F2S", "I2F",
  "I2S", "S2B", "S2F", "S2I", "F2X", "I2X", "S2X", "X2F", "X2I", "X2S",
  "X2X", "XPRINT", "','", "'='", "'?'", "':'", "OR", "AND", "'|'", "'^'",
  "'&'", "NE", "EQ", "'<'", "'>'", "GE", "LE", "RS", "LS", "'+'", "'-'",
  "IN_OP", "'*'", "'/'", "'%'", "'!'", "'~'", "'#'", "UNARY", "DEC", "INC",
  "CAST", "'('", "MAXTOKEN", "'{'", "'}'", "';'", "')'", "'['", "']'",
  "'.'", "$accept", "program", "action_list", "action", "$@1",
  "statement_list", "statement", "$@2", "$@3", "$@4", "switch_list",
  "switch_item", "case_list", "case_item", "static", "dcl_list",
  "dcl_item", "$@5", "dcl_name", "name", "else_opt", "expr_opt", "expr",
  "$@6", "$@7", "splitop", "constant", "print", "scan", "variable",
  "array", "index", "args", "arg_list", "formals", "formal_list",
  "formal_item", "$@8", "members", "member", "assign", "initialize", "$@9",
  "$@10", 0
};







       
     
     
     
     
     
     
      
      
      
     



/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   111,   110,   112,   112,   113,
     113,   114,   115,   113,   113,   113,   113,   113,   113,   113,
     113,   116,   113,   113,   113,   113,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   124,   123,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   131,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   132,   132,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   136,   136,   136,   137,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   142,   142,
     144,   143,   145,   145,   145,   146,   146,   147,   147,   148,
     149,   150,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     4,     0,     2,     3,
       2,     0,     0,     6,     6,     5,     9,     5,     4,     6,
       5,     0,     8,     3,     3,     3,     0,     2,     2,     1,
       2,     3,     2,     0,     1,     1,     3,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     0,     7,     2,     2,     2,     2,     2,     2,     4,
       4,     4,     4,     4,     6,     8,     4,     3,     3,     4,
       4,     4,     4,     4,     2,     2,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     0,     2,     3,     0,
       3,     0,     1,     1,     3,     0,     1,     1,     1,     3,
       0,     3,     0,     1,     3,     2,     2,     0,     2,     1,
       0,     0,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     3,     1,   105,   107,   104,   106,    34,     0,
      47,   103,    47,   119,     0,     0,     0,     0,     0,   132,
       0,   115,     0,   108,     0,   109,     0,    47,   111,   101,
     110,     0,   112,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     2,
       8,    11,     0,    48,     0,   100,     0,     0,   137,   121,
       0,     0,     0,   132,     0,    47,   121,   121,     0,     0,
     113,   133,     0,   121,   121,     0,     0,     0,   121,   121,
       0,     0,     0,    78,    77,    76,    73,    75,    74,    98,
      95,     0,     0,    33,     0,     4,     0,    10,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   121,     0,    99,    96,    94,   123,     0,   122,    23,
      24,     0,   114,     0,     0,   137,     0,     0,     0,   135,
     136,     0,     0,     0,    87,    25,    88,     0,     0,     0,
      21,     0,     0,     0,    49,     9,     5,    12,    69,     0,
      68,    67,    64,    65,    63,    62,    61,    51,    58,    60,
      59,    57,    56,    66,    52,    97,    53,    54,    55,     0,
       0,     0,   138,    79,     0,   120,    86,    47,    33,    80,
      81,    33,     0,   134,    33,    91,    90,    89,    82,    83,
       0,     0,    18,    33,    50,     7,     0,     0,     0,    92,
      93,   124,     0,    15,    17,   135,    45,     0,     0,    20,
       6,    40,    42,    41,    39,     0,    35,    37,    71,   119,
      47,    33,    14,    26,    19,     0,    13,   116,     0,     0,
      84,     0,    46,     0,    36,     0,   137,    72,     0,    33,
       0,     0,    22,    27,     7,    29,     0,   117,   140,   139,
      38,    85,    16,     0,    32,    28,    30,   118,   125,    31,
     130,   141,   127,   128,     0,     0,     0,    44,    43,   131,
       0,   130,   129,     7,    33,   142
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    49,    95,   205,     2,    50,    96,   206,   200,
     243,   253,   254,   255,    51,   225,   226,   237,   227,   279,
     232,    52,    53,   159,   238,    54,    55,    56,    57,    58,
     246,    63,   127,   128,   271,   272,   273,   274,    70,    71,
     125,   260,   268,   275
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */

static const yytype_int16 yypact[] =
{
    -144,     9,   200,  -144,  -144,  -144,  -144,  -144,  -144,   -89,
     691,  -144,   691,   -80,   -71,   -64,   -63,   -43,   -35,   -27,
     -11,  -144,    11,  -144,    16,  -144,    20,   691,  -144,  -144,
    -144,    23,  -144,    31,    39,    41,  -144,    56,    57,     1,
     691,   691,   691,   691,    79,     1,     1,   596,  -144,    92,
    -144,  -144,    49,   872,    58,  -144,    60,    61,   -37,   691,
      65,    66,   691,   -27,   691,   691,   691,   691,     1,   -12,
    -144,  -144,   691,   691,   691,    59,    68,    88,   691,   691,
     691,   140,   691,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,    72,   284,   299,   100,  -144,   158,  -144,   691,  -144,
     691,   691,   691,   691,   691,   691,   691,   691,   691,   691,
     691,   691,   691,   691,   691,   143,   691,   691,   691,   691,
     691,   691,   691,  -144,  -144,  -144,   916,    77,   109,  -144,
    -144,   185,  -144,   383,    83,   -56,    84,    85,    95,    93,
    -144,   482,    97,    98,  -144,  -144,  -144,   577,   106,   108,
     872,   -51,   672,   691,  -144,  -144,  -144,  -144,   916,   691,
     934,   951,   967,   982,   996,  1010,  1010,  1022,  1022,  1022,
    1022,   107,   107,    53,    53,  -144,  -144,  -144,  -144,   895,
     111,   112,   916,  -144,   691,  -144,  -144,   691,   497,  -144,
    -144,   497,    29,  -144,   497,  -144,  -144,  -144,  -144,  -144,
     116,   691,  -144,   497,  -144,  -144,    87,   849,   786,  -144,
    -144,   916,   124,  -144,  -144,  -144,   168,    90,   767,  -144,
     200,  -144,  -144,  -144,  -144,   -49,  -144,  -144,  -144,   -54,
     691,   497,  -144,  -144,  -144,    87,  -144,   126,   691,   691,
    -144,   128,  -144,    -7,  -144,   -16,   -44,   916,   815,   497,
     145,   162,  -144,  -144,    86,  -144,   129,  -144,  -144,  -144,
    -144,  -144,  -144,   183,  -144,   200,  -144,  -144,   238,  -144,
     174,  -144,   210,  -144,   -10,   176,   262,  -144,  -144,  -144,
     181,  -144,  -144,  -144,   398,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,   -48,  -143,  -144,  -144,  -144,
    -144,  -144,  -144,    28,  -144,  -144,    48,  -144,  -144,  -144,
    -144,    -9,   -36,  -144,  -144,  -144,    34,  -144,  -144,   101,
    -144,  -144,    24,  -144,  -144,  -144,    12,  -144,   224,   150,
      51,  -144,  -144,  -144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */

static const yytype_int16 yytable[] =
{
      93,    60,   256,    61,    84,    85,    86,    87,   250,     3,
     277,    92,   251,   122,   239,    59,   139,   201,    76,   235,
     140,    13,   278,   126,    62,   122,   131,    64,   133,    19,
     126,   126,   122,    21,    65,    66,   141,   126,   126,   123,
     124,   147,   126,   126,   150,   213,   152,   188,   214,   240,
      62,   216,   202,   236,   258,    67,   134,   215,   123,   124,
     219,   140,   158,    68,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    69,
     176,   177,   178,   179,   126,   126,   182,    72,   242,   257,
     136,   137,     4,     5,   252,     6,     7,   142,   143,    88,
       9,   250,   148,   149,    11,   251,   262,   221,    13,    73,
      14,   222,    16,    17,    74,   223,    19,   204,    75,   224,
      21,    77,    94,   207,    22,    23,    24,    25,    26,    78,
      28,    29,    30,    31,    32,    33,    34,    79,    36,    80,
      83,   116,   117,   118,   180,   181,    89,    90,   211,     4,
       5,    97,     6,     7,    81,    82,   119,   220,   120,   121,
     151,    11,   144,   175,    39,   218,   135,   129,   130,   138,
     145,   156,   158,    40,    41,   153,   157,   184,   212,    42,
      43,    44,   183,    45,    46,   187,    47,   189,   190,   231,
     233,   146,   113,   114,   115,   116,   117,   118,   191,   192,
     195,   196,   247,   248,     4,     5,   265,     6,     7,   198,
       8,   199,     9,    10,   209,   210,    11,    12,   -33,   217,
      13,   241,    14,    15,    16,    17,   230,    18,    19,    20,
     245,   249,    21,   264,   267,   284,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    98,   269,    99,   270,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    39,  -126,   276,   280,
     281,   283,   266,   244,   263,    40,    41,   132,   282,   193,
     185,    42,    43,    44,     0,    45,    46,   259,    47,     0,
      48,     0,   -47,     4,     5,     0,     6,     7,     0,     8,
       0,     9,    10,     0,     0,    11,    12,     0,     0,    13,
       0,    14,    15,    16,    17,     0,    18,    19,    20,     0,
       0,    21,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    98,     0,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,   154,     0,     0,
      42,    43,    44,     0,    45,    46,     0,    47,     0,    48,
     155,   -47,     4,     5,     0,     6,     7,     0,     8,     0,
       9,    10,     0,     0,    11,    12,     0,     0,    13,     0,
      14,    15,    16,    17,     0,    18,    19,    20,     0,     0,
      21,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    98,     0,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    39,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,   186,     0,     0,    42,
      43,    44,     0,    45,    46,     0,    47,     0,    48,   285,
     -47,     4,     5,     0,     6,     7,     0,     8,     0,     9,
      10,     0,     0,    11,    12,     0,     0,    13,     0,    14,
      15,    16,    17,     0,    18,    19,    20,     0,     0,    21,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      98,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,   194,     0,     0,    42,    43,
      44,     0,    45,    46,     0,    47,     0,    48,     0,   -47,
       4,     5,     0,     6,     7,     0,     0,     0,     9,     0,
       0,     0,    11,     0,    91,     0,    13,     0,    14,     0,
      16,    17,     0,     0,    19,     0,     0,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,     0,    28,    29,
      30,    31,    32,    33,    34,    98,    36,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     197,    40,    41,     0,     0,     0,     0,    42,    43,    44,
       0,    45,    46,     0,    47,     4,     5,     0,     6,     7,
       0,     0,     0,     9,     0,     0,     0,    11,     0,     0,
       0,    13,     0,    14,     0,    16,    17,     0,     0,    19,
       0,     0,     0,    21,     0,     0,     0,    22,    23,    24,
      25,    26,     0,    28,    29,    30,    31,    32,    33,    34,
      98,    36,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,   203,    40,    41,     0,     0,
       0,     0,    42,    43,    44,     0,    45,    46,     0,    47,
       4,     5,     0,     6,     7,     0,     0,     0,     9,     0,
       0,     0,    11,     0,     0,     0,   229,     0,    14,     0,
      16,    17,     0,     0,    19,     0,     0,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,     0,    28,    29,
      30,    31,    32,    33,    34,    98,    36,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     234,    40,    41,     0,     0,     0,     0,    42,    43,    44,
       0,    45,    46,    98,    47,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,   261,    99,
     228,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      98,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   208,     0,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,  -127,  -127,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,  -127,  -127,  -127,  -127,   111,   112,   113,   114,   115,
     116,   117,   118
};







static const yytype_int16 yycheck[] =
{
      48,    10,    18,    12,    40,    41,    42,    43,    15,     0,
      20,    47,    19,    69,    68,   104,    28,    68,    27,    68,
      32,    20,    32,    59,   104,    69,    62,    98,    64,    28,
      66,    67,    69,    32,    98,    98,    72,    73,    74,    95,
      96,    77,    78,    79,    80,   188,    82,   103,   191,   103,
     104,   194,   103,   102,    98,    98,    65,    28,    95,    96,
     203,    32,    98,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   106,
     116,   117,   118,   119,   120,   121,   122,    98,   231,   105,
      66,    67,     4,     5,   101,     7,     8,    73,    74,    20,
      12,    15,    78,    79,    16,    19,   249,    20,    20,    98,
      22,    24,    24,    25,    98,    28,    28,   153,    98,    32,
      32,    98,    30,   159,    36,    37,    38,    39,    40,    98,
      42,    43,    44,    45,    46,    47,    48,    98,    50,    98,
      39,    88,    89,    90,   120,   121,    45,    46,   184,     4,
       5,   102,     7,     8,    98,    98,    98,   205,    98,    98,
      20,    16,   103,    20,    76,   201,    65,   102,   102,    68,
     102,    71,   208,    85,    86,   103,    18,    68,   187,    91,
      92,    93,   105,    95,    96,   102,    98,   103,   103,    21,
     100,   103,    85,    86,    87,    88,    89,    90,   103,   106,
     103,   103,   238,   239,     4,     5,   254,     7,     8,   103,
      10,   103,    12,    13,   103,   103,    16,    17,    18,   103,
      20,   230,    22,    23,    24,    25,   102,    27,    28,    29,
     104,   103,    32,    71,   105,   283,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    68,    71,    70,    18,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    76,   103,    68,   103,
      18,   100,   254,   235,   250,    85,    86,    63,   276,   139,
     105,    91,    92,    93,    -1,    95,    96,   246,    98,    -1,
     100,    -1,   102,     4,     5,    -1,     7,     8,    -1,    10,
      -1,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    68,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,   103,    -1,    -1,
      91,    92,    93,    -1,    95,    96,    -1,    98,    -1,   100,
     101,   102,     4,     5,    -1,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    68,    -1,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,   103,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    -1,    98,    -1,   100,   101,
     102,     4,     5,    -1,     7,     8,    -1,    10,    -1,    12,
      13,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      68,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,   103,    -1,    -1,    91,    92,
      93,    -1,    95,    96,    -1,    98,    -1,   100,    -1,   102,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    16,    -1,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    68,    50,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    -1,    98,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      68,    50,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    93,    -1,    95,    96,    -1,    98,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    68,    50,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    68,    98,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,   103,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      68,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    68,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   108,   112,     0,     4,     5,     7,     8,    10,    12,
      13,    16,    17,    20,    22,    23,    24,    25,    27,    28,
      29,    32,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    76,
      85,    86,    91,    92,    93,    95,    96,    98,   100,   109,
     113,   121,   128,   129,   132,   133,   134,   135,   136,   104,
     128,   128,   104,   138,    98,    98,    98,    98,    98,   106,
     145,   146,    98,    98,    98,    98,   128,    98,    98,    98,
      98,    98,    98,   136,   129,   129,   129,   129,    20,   136,
     136,    18,   129,   112,    30,   110,   114,   102,    68,    70,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    98,
      98,    98,    69,    95,    96,   147,   129,   139,   140,   102,
     102,   129,   145,   129,   128,   136,   139,   139,   136,    28,
      32,   129,   139,   139,   103,   102,   103,   129,   139,   139,
     129,    20,   129,   103,   103,   101,    71,    18,   129,   130,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,    20,   129,   129,   129,   129,
     139,   139,   129,   105,    68,   105,   103,   102,   103,   103,
     103,   103,   106,   146,   103,   103,   103,   103,   103,   103,
     116,    68,   103,   103,   129,   111,   115,   129,    68,   103,
     103,   129,   128,   113,   113,    28,   113,   103,   129,   113,
     112,    20,    24,    28,    32,   122,   123,   125,    71,    20,
     102,    21,   127,   100,   103,    68,   102,   124,   131,    68,
     103,   128,   113,   117,   123,   104,   137,   129,   129,   103,
      15,    19,   101,   118,   119,   120,    18,   105,    98,   147,
     148,   103,   113,   133,    71,   112,   120,   105,   149,    71,
      18,   141,   142,   143,   144,   150,    68,    20,    32,   126,
     103,    18,   143,   100,   112,   101
};











/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */



  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */

























/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

























/* This macro is provided for backward compatibility. */






/* YYLEX -- calling `yylex' with the right arguments.  */







/* Enable debugging if requested.  */



#line 1 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 1





















/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/





static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;

{
  FILE *yyo = yyoutput;
  ((void) (yyo));
  if (!yyvaluep)
    return;

  
    

  ((void) (yyoutput));

  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/






static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;

{
  if (yytype < 107)
    fprintf (yyoutput, "token %s (", yytname[yytype]);
  else
    fprintf (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  fprintf (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/






static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;

{
  fprintf (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      fprintf (stderr, " %d", yybot);
    }
  fprintf (stderr, "\n");
}








/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/






static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;

{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  fprintf (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}







/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;








/* YYINITDEPTH -- initial size of the parser's stacks.  */




/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */




















    


  
  
    
  

















    
    


  
  

  
    

  















  
    
      
      

      
	
	  
	  
	  
	    

	  
	    
	      
	    
	  
	    
	      
	    
	    

	  
	    
	      
	    
	  
    
    

  
    

  













                

  
  
  
  
  
  
  
  
  

  

  


























  
    
      
      
      
        
          


          
          
          
          
          

          
            
                
              
                
                  
                    
                    
                    
                  
                
                
                
                       
                  
                
              
        
    

  
    




      
      
      
      
      
      

    

  
  
    
  

  
    
      
      
             
        
      
    

  


  
    
    
    
      
        
          
          
        
      
        
          
          
        
  
  



/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/





static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;

{
  ((void) (yyvaluep));

  if (!yymsg)
    yymsg = "Deleting";
  do { if (yydebug) { fprintf (stderr, "%s ", yymsg); yy_symbol_print (stderr, yytype, yyvaluep); fprintf (stderr, "\n"); } } while ((0));

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/









    







int
yyparse ()



{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[200];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[200];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    unsigned int yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  
  
  
  




  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = 200;

  do { if (yydebug) fprintf (stderr, "Starting parse\n"); } while ((0));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = (-2); /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      unsigned int yysize = yyssp - yyss + 1;


      
	


	
	

	



	
		    
		    
		    

	
	
      


      

      /* Extend the stack our own way.  */
      if (10000 <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (10000 < yystacksize)
	yystacksize = 10000;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) malloc (((yystacksize) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) + (sizeof (union yyalloc) - 1)));
	if (! yyptr)
	  goto yyexhaustedlab;
	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyss_alloc)[yyi] = (yyss)[yyi]; } while ((0)); yyss = &yyptr->yyss_alloc; yynewbytes = yystacksize * sizeof (*yyss) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));
	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyvs_alloc)[yyi] = (yyvs)[yyi]; } while ((0)); yyvs = &yyptr->yyvs_alloc; yynewbytes = yystacksize * sizeof (*yyvs) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));

	if (yyss1 != yyssa)
	  free (yyss1);
      }



      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      do { if (yydebug) fprintf (stderr, "Stack size increased to %lu\n",
(unsigned long int) yystacksize); } while ((0));

      if (yyss + yystacksize - 1 <= yyssp)
	goto yyabortlab;
    }

  do { if (yydebug) fprintf (stderr, "Entering state %d\n", yystate); } while ((0));

  if (yystate == 3)
    goto yyacceptlab;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (((yyn) == (-144)))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == (-2))
    {
      do { if (yydebug) fprintf (stderr, "Reading a token: "); } while ((0));
      yychar = yylex ();
    }

  if (yychar <= 0)
    {
      yychar = yytoken = 0;
      do { if (yydebug) fprintf (stderr, "Now at end of input.\n"); } while ((0));
    }
  else
    {
      yytoken = ((unsigned int) (yychar) <= 336 ? yytranslate[yychar] : 2);
      do { if (yydebug) { fprintf (stderr, "%s ", "Next token is"); yy_symbol_print (stderr, yytoken, &yylval); fprintf (stderr, "\n"); } } while ((0));
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || 1112 < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (((yyn) == (-127)))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  do { if (yydebug) { fprintf (stderr, "%s ", "Shifting"); yy_symbol_print (stderr, yytoken, &yylval); fprintf (stderr, "\n"); } } while ((0));

  /* Discard the shifted token.  */
  yychar = (-2);

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  do { if (yydebug) yy_reduce_print (yyvsp, yyn); } while ((0));
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(1) - (2)].expr) && !(expr.program->disc->flags & (1<<8)))
			{
				if (expr.program->main.value && !(expr.program->disc->flags & (1<<6)))
					exfreenode(expr.program, expr.program->main.value);
				if ((yyvsp[(1) - (2)].expr)->op == 312)
				{
					Exnode_t*	x;

					x = (yyvsp[(1) - (2)].expr);
					(yyvsp[(1) - (2)].expr) = x->data.operand.left;
					x->data.operand.left = 0;
					exfreenode(expr.program, x);
				}
				expr.program->main.lex = 293;
				expr.program->main.value = exnewnode(expr.program, 293, 1, (yyvsp[(1) - (2)].expr)->type, 0, (yyvsp[(1) - (2)].expr));
			}
		}
    break;

  case 5:
/* Line 1787 of yacc.c  */

    {
				register Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("no nested function definitions");
				(yyvsp[(1) - (2)].id)->lex = 293;
				expr.procedure = (yyvsp[(1) - (2)].id)->value = exnewnode(expr.program, 293, 1, (yyvsp[(1) - (2)].id)->type, 0, 0);
				expr.procedure->type = 259;
				if (!(disc = ((0)?(Dtdisc_t*)realloc((char*)(0),sizeof(Dtdisc_t)*(1)+(0)):(Dtdisc_t*)calloc(1,sizeof(Dtdisc_t)*(1)+(0)))))
					exnospace();
				disc->key = offsetof(Exid_t, name);
				if (expr.assigned && !(*((yyvsp[(1) -(2)].id)->name)==*("begin")&&!strcmp((yyvsp[(1) -(2)].id)->name,"begin")))
				{
					if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
						exnospace();
					expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
				}
			}
    break;

  case 6:
/* Line 1787 of yacc.c  */

    {
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, 0);
				expr.program->frame = 0;
			}
			if ((yyvsp[(4) - (4)].expr) && (yyvsp[(4) - (4)].expr)->op == 312)
			{
				Exnode_t*	x;

				x = (yyvsp[(4) - (4)].expr);
				(yyvsp[(4) - (4)].expr) = x->data.operand.left;
				x->data.operand.left = 0;
				exfreenode(expr.program, x);
			}
			(yyvsp[(1) - (4)].id)->value->data.operand.right = excast(expr.program, (yyvsp[(4) - (4)].expr), (yyvsp[(1) - (4)].id)->type, 0, 0);
		}
    break;

  case 7:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 8:
/* Line 1787 of yacc.c  */

    {
			if (!(yyvsp[(1) - (2)].expr))
				(yyval.expr) = (yyvsp[(2) - (2)].expr);
			else if (!(yyvsp[(2) - (2)].expr))
				(yyval.expr) = (yyvsp[(1) - (2)].expr);
			else if ((yyvsp[(1) - (2)].expr)->op == 271)
			{
				exfreenode(expr.program, (yyvsp[(1) - (2)].expr));
				(yyval.expr) = (yyvsp[(2) - (2)].expr);
			}

			
			
				
				
			
			
			
				
				
			

			else (yyval.expr) = exnewnode(expr.program, ';', 1, (yyvsp[(2) - (2)].expr)->type, (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr));
		}
    break;

  case 9:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(2) - (3)].expr);
		}
    break;

  case 10:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = ((yyvsp[(1) - (2)].expr) && (yyvsp[(1) - (2)].expr)->type == 263) ? exnewnode(expr.program, 312, 1, 259, (yyvsp[(1) - (2)].expr), 0) : (yyvsp[(1) - (2)].expr);
		}
    break;

  case 11:
/* Line 1787 of yacc.c  */

    {expr.instatic=(yyvsp[(1) - (1)].integer);}
    break;

  case 12:
/* Line 1787 of yacc.c  */

    {expr.declare=(yyvsp[(3) - (3)].id)->type;}
    break;

  case 13:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(5) - (6)].expr);
			expr.declare = 0;
		}
    break;

  case 14:
/* Line 1787 of yacc.c  */

    {
			if (exisAssign ((yyvsp[(3) - (6)].expr)))
				exwarn ("assignment used as boolean in if statement");
			if ((yyvsp[(3) - (6)].expr)->type == 263)
				(yyvsp[(3) - (6)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(3) - (6)].expr), 0);
			else if (!(((yyvsp[(3) -(6)].expr)->type)>=259&&((yyvsp[(3) -(6)].expr)->type)<=261))
				(yyvsp[(3) - (6)].expr) = excast(expr.program, (yyvsp[(3) - (6)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (6)].id)->index, 1, 259, (yyvsp[(3) - (6)].expr), exnewnode(expr.program, ':', 1, (yyvsp[(5) - (6)].expr) ? (yyvsp[(5) - (6)].expr)->type : 0, (yyvsp[(5) - (6)].expr), (yyvsp[(6) - (6)].expr)));
		}
    break;

  case 15:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 281, 0, 259, 0, 0);
			(yyval.expr)->data.generate.array = (yyvsp[(3) - (5)].expr);
			if (!(yyvsp[(3) - (5)].expr)->data.variable.index || (yyvsp[(3) - (5)].expr)->data.variable.index->op != 275)
				exerror("simple index variable expected");
			(yyval.expr)->data.generate.index = (yyvsp[(3) - (5)].expr)->data.variable.index->data.variable.symbol;
			if ((yyvsp[(3) - (5)].expr)->op == 283 && (yyval.expr)->data.generate.index->type != 259)
				exerror("integer index variable expected");
			exfreenode(expr.program, (yyvsp[(3) - (5)].expr)->data.variable.index);
			(yyvsp[(3) - (5)].expr)->data.variable.index = 0;
			(yyval.expr)->data.generate.statement = (yyvsp[(5) - (5)].expr);
		}
    break;

  case 16:
/* Line 1787 of yacc.c  */

    {
			if (!(yyvsp[(5) - (9)].expr))
			{
				(yyvsp[(5) - (9)].expr) = exnewnode(expr.program, 271, 0, 259, 0, 0);
				(yyvsp[(5) - (9)].expr)->data.constant.value.integer = 1;
			}
			else if ((yyvsp[(5) - (9)].expr)->type == 263)
				(yyvsp[(5) - (9)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(5) - (9)].expr), 0);
			else if (!(((yyvsp[(5) -(9)].expr)->type)>=259&&((yyvsp[(5) -(9)].expr)->type)<=261))
				(yyvsp[(5) - (9)].expr) = excast(expr.program, (yyvsp[(5) - (9)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (9)].id)->index, 1, 259, (yyvsp[(5) - (9)].expr), exnewnode(expr.program, ';', 1, 0, (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].expr)));
			if ((yyvsp[(3) - (9)].expr))
				(yyval.expr) = exnewnode(expr.program, ';', 1, 259, (yyvsp[(3) - (9)].expr), (yyval.expr));
		}
    break;

  case 17:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 282, 0, 259, 0, 0);
			(yyval.expr)->data.generate.array = (yyvsp[(3) - (5)].expr);
			if (!(yyvsp[(3) - (5)].expr)->data.variable.index || (yyvsp[(3) - (5)].expr)->data.variable.index->op != 275)
				exerror("simple index variable expected");
			(yyval.expr)->data.generate.index = (yyvsp[(3) - (5)].expr)->data.variable.index->data.variable.symbol;
			if ((yyvsp[(3) - (5)].expr)->op == 283 && (yyval.expr)->data.generate.index->type != 259)
				exerror("integer index variable expected");
			exfreenode(expr.program, (yyvsp[(3) - (5)].expr)->data.variable.index);
			(yyvsp[(3) - (5)].expr)->data.variable.index = 0;
			(yyval.expr)->data.generate.statement = (yyvsp[(5) - (5)].expr);
		}
    break;

  case 18:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(3) - (4)].id)->local.pointer == 0)
              			exerror("cannot apply unset to non-array %s", (yyvsp[(3) - (4)].id)->name);
			(yyval.expr) = exnewnode(expr.program, 306, 0, 259, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(3) - (4)].id);
			(yyval.expr)->data.variable.index = 0;
		}
    break;

  case 19:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(3) - (6)].id)->local.pointer == 0)
              			exerror("cannot apply unset to non-array %s", (yyvsp[(3) - (6)].id)->name);
			if (((yyvsp[(3) - (6)].id)->index_type > 0) && ((yyvsp[(5) - (6)].expr)->type != (yyvsp[(3) - (6)].id)->index_type))
            		    exerror("%s indices must have type %s, not %s", 
				(yyvsp[(3) - (6)].id)->name, extypename(expr.program, (yyvsp[(3) - (6)].id)->index_type),extypename(expr.program, (yyvsp[(5) - (6)].expr)->type));
			(yyval.expr) = exnewnode(expr.program, 306, 0, 259, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(3) - (6)].id);
			(yyval.expr)->data.variable.index = (yyvsp[(5) - (6)].expr);
		}
    break;

  case 20:
/* Line 1787 of yacc.c  */

    {
			if (exisAssign ((yyvsp[(3) - (5)].expr)))
				exwarn ("assignment used as boolean in while statement");
			if ((yyvsp[(3) - (5)].expr)->type == 263)
				(yyvsp[(3) - (5)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(3) - (5)].expr), 0);
			else if (!(((yyvsp[(3) -(5)].expr)->type)>=259&&((yyvsp[(3) -(5)].expr)->type)<=261))
				(yyvsp[(3) - (5)].expr) = excast(expr.program, (yyvsp[(3) - (5)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (5)].id)->index, 1, 259, (yyvsp[(3) - (5)].expr), exnewnode(expr.program, ';', 1, 0, 0, (yyvsp[(5) - (5)].expr)));
		}
    break;

  case 21:
/* Line 1787 of yacc.c  */

    {expr.declare=(yyvsp[(3) - (3)].expr)->type;}
    break;

  case 22:
/* Line 1787 of yacc.c  */

    {
			register Switch_t*	sw = expr.swstate;

			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (8)].id)->index, 1, 259, (yyvsp[(3) - (8)].expr), exnewnode(expr.program, 274, 1, 0, sw->defcase, sw->firstcase));
			expr.swstate = expr.swstate->prev;
			if (sw->base)
				free(sw->base);
			if (sw != &swstate)
				free(sw);
			expr.declare = 0;
		}
    break;

  case 23:
/* Line 1787 of yacc.c  */

    {
		loopop:
			if (!(yyvsp[(2) - (3)].expr))
			{
				(yyvsp[(2) - (3)].expr) = exnewnode(expr.program, 271, 0, 259, 0, 0);
				(yyvsp[(2) - (3)].expr)->data.constant.value.integer = 1;
			}
			else if (!(((yyvsp[(2) -(3)].expr)->type)>=259&&((yyvsp[(2) -(3)].expr)->type)<=261))
				(yyvsp[(2) - (3)].expr) = excast(expr.program, (yyvsp[(2) - (3)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (3)].id)->index, 1, 259, (yyvsp[(2) - (3)].expr), 0);
		}
    break;

  case 24:
/* Line 1787 of yacc.c  */

    {
			goto loopop;
		}
    break;

  case 25:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(2) - (3)].expr))
			{
				if (expr.procedure && !expr.procedure->type)
					exerror("return in void function");
				(yyvsp[(2) - (3)].expr) = excast(expr.program, (yyvsp[(2) - (3)].expr), expr.procedure ? expr.procedure->type : 259, 0, 0);
			}
			(yyval.expr) = exnewnode(expr.program, 296, 1, (yyvsp[(2) - (3)].expr) ? (yyvsp[(2) - (3)].expr)->type : 0, (yyvsp[(2) - (3)].expr), 0);
		}
    break;

  case 26:
/* Line 1787 of yacc.c  */

    {
			register Switch_t*		sw;
			int				n;

			if (expr.swstate)
			{
				if (!(sw = ((0)?(Switch_t*)realloc((char*)(0),sizeof(Switch_t)*(1)+(0)):(Switch_t*)calloc(1,sizeof(Switch_t)*(1)+(0)))))
				{
					exnospace();
					sw = &swstate;
				}
				sw->prev = expr.swstate;
			}
			else
				sw = &swstate;
			expr.swstate = sw;
			sw->type = expr.declare;
			sw->firstcase = 0;
			sw->lastcase = 0;
			sw->defcase = 0;
			sw->def = 0;
			n = 8;
			if (!(sw->base = ((0)?(Extype_t**)realloc((char*)(0),sizeof(Extype_t*)*(n)+(0)):(Extype_t**)calloc(1,sizeof(Extype_t*)*(n)+(0)))))
			{
				exnospace();
				n = 0;
			}
			sw->cur = sw->base;
			sw->last = sw->base + n;
		}
    break;

  case 28:
/* Line 1787 of yacc.c  */

    {
			register Switch_t*	sw = expr.swstate;
			int			n;

			(yyval.expr) = exnewnode(expr.program, 270, 1, 0, (yyvsp[(2) - (2)].expr), 0);
			if (sw->cur > sw->base)
			{
				if (sw->lastcase)
					sw->lastcase->data.select.next = (yyval.expr);
				else
					sw->firstcase = (yyval.expr);
				sw->lastcase = (yyval.expr);
				n = sw->cur - sw->base;
				sw->cur = sw->base;
				(yyval.expr)->data.select.constant = (Extype_t**)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*((n + 1) * sizeof(Extype_t*))+(0)),((0000002|0000001|0000004)));
				memcpy((yyval.expr)->data.select.constant, sw->base, n * sizeof(Extype_t*));
				(yyval.expr)->data.select.constant[n] = 0;
			}
			else
				(yyval.expr)->data.select.constant = 0;
			if (sw->def)
			{
				sw->def = 0;
				if (sw->defcase)
					exerror("duplicate default in switch");
				else
					sw->defcase = (yyvsp[(2) - (2)].expr);
			}
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */

    {
			int	n;

			if (expr.swstate->cur >= expr.swstate->last)
			{
				n = expr.swstate->cur - expr.swstate->base;
				if (!(expr.swstate->base = ((expr.swstate->base)?(Extype_t**)realloc((char*)(expr.swstate->base),sizeof(Extype_t*)*(2 * n)+(0)):(Extype_t**)calloc(1,sizeof(Extype_t*)*(2 * n)+(0)))))
				{
					exerror("too many case labels for switch");
					n = 0;
				}
				expr.swstate->cur = expr.swstate->base + n;
				expr.swstate->last = expr.swstate->base + 2 * n;
			}
			if (expr.swstate->cur)
			{
				(yyvsp[(2) - (3)].expr) = excast(expr.program, (yyvsp[(2) - (3)].expr), expr.swstate->type, 0, 0);
				*expr.swstate->cur++ = &((yyvsp[(2) - (3)].expr)->data.constant.value);
			}
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */

    {
			expr.swstate->def = 1;
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */

    {
			(yyval.integer) = 0;
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */

    {
			(yyval.integer) = 1;
		}
    break;

  case 36:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(3) - (3)].expr))
				(yyval.expr) = (yyvsp[(1) - (3)].expr) ? exnewnode(expr.program, ',', 1, (yyvsp[(3) - (3)].expr)->type, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)) : (yyvsp[(3) - (3)].expr);
		}
    break;

  case 37:
/* Line 1787 of yacc.c  */

    {checkName ((yyvsp[(1) - (1)].id)); expr.id=(yyvsp[(1) - (1)].id);}
    break;

  case 38:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
			if (!(yyvsp[(1) - (4)].id)->type || expr.declare)
				(yyvsp[(1) - (4)].id)->type = expr.declare;
			if ((yyvsp[(4) - (4)].expr) && (yyvsp[(4) - (4)].expr)->op == 293)
			{
				(yyvsp[(1) - (4)].id)->lex = 293;
				(yyvsp[(1) - (4)].id)->type = (yyvsp[(4) - (4)].expr)->type;
				(yyvsp[(1) - (4)].id)->value = (yyvsp[(4) - (4)].expr);
			}
			else
			{
				(yyvsp[(1) - (4)].id)->lex = 275;
				(yyvsp[(1) - (4)].id)->value = exnewnode(expr.program, 0, 0, 0, 0, 0);
				if ((yyvsp[(3) - (4)].integer) && !(yyvsp[(1) - (4)].id)->local.pointer)
				{
					Dtdisc_t*	disc;

					if (!(disc = ((0)?(Dtdisc_t*)realloc((char*)(0),sizeof(Dtdisc_t)*(1)+(0)):(Dtdisc_t*)calloc(1,sizeof(Dtdisc_t)*(1)+(0)))))
						exnospace();
					if ((yyvsp[(3) - (4)].integer) == 259) {
						disc->key = offsetof(Exassoc_t, key);
						disc->size = sizeof(Extype_t);
						disc->comparf = (Dtcompar_f)cmpKey;
					}
					else
						disc->key = offsetof(Exassoc_t, name);
					if (!((yyvsp[(1) - (4)].id)->local.pointer = (char*)dtopen(disc, Dtoset)))
						exerror("%s: cannot initialize associative array", (yyvsp[(1) - (4)].id)->name);
					(yyvsp[(1) - (4)].id)->index_type = (yyvsp[(3) - (4)].integer); /* -1 indicates no typechecking */
				}
				if ((yyvsp[(4) - (4)].expr))
				{
					if ((yyvsp[(4) - (4)].expr)->type != (yyvsp[(1) - (4)].id)->type)
					{
						(yyvsp[(4) - (4)].expr)->type = (yyvsp[(1) - (4)].id)->type;
						(yyvsp[(4) - (4)].expr)->data.operand.right = excast(expr.program, (yyvsp[(4) - (4)].expr)->data.operand.right, (yyvsp[(1) - (4)].id)->type, 0, 0);
					}
					(yyvsp[(4) - (4)].expr)->data.operand.left = exnewnode(expr.program, 275, 0, (yyvsp[(1) - (4)].id)->type, 0, 0);
					(yyvsp[(4) - (4)].expr)->data.operand.left->data.variable.symbol = (yyvsp[(1) - (4)].id);
					(yyval.expr) = (yyvsp[(4) - (4)].expr);

					
					
						
						
					

				}
				else if (!(yyvsp[(3) - (4)].integer))
					(yyvsp[(1) - (4)].id)->value->data.value = exzero((yyvsp[(1) - (4)].id)->type);
			}
		}
    break;

  case 45:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 46:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(2) - (2)].expr);
		}
    break;

  case 47:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 49:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(2) - (3)].expr);
		}
    break;

  case 50:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = ((yyvsp[(4) - (4)].expr)->type == (yyvsp[(2) - (4)].id)->type) ? (yyvsp[(4) - (4)].expr) : excast(expr.program, (yyvsp[(4) - (4)].expr), (yyvsp[(2) - (4)].id)->type, 0, 0);
		}
    break;

  case 51:
/* Line 1787 of yacc.c  */

    {
			int	rel;

		relational:
			rel = 259;
			goto coerce;
		binary:
			rel = 0;
		coerce:
			if (!(yyvsp[(1) - (3)].expr)->type)
			{
				if (!(yyvsp[(3) - (3)].expr)->type)
					(yyvsp[(1) - (3)].expr)->type = (yyvsp[(3) - (3)].expr)->type = rel ? 263 : 259;
				else
					(yyvsp[(1) - (3)].expr)->type = (yyvsp[(3) - (3)].expr)->type;
			}
			else if (!(yyvsp[(3) - (3)].expr)->type)
				(yyvsp[(3) - (3)].expr)->type = (yyvsp[(1) - (3)].expr)->type;
			if ((yyvsp[(1) - (3)].expr)->type != (yyvsp[(3) - (3)].expr)->type)
			{
				if ((yyvsp[(1) - (3)].expr)->type == 263)
					(yyvsp[(1) - (3)].expr) = excast(expr.program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)->type, (yyvsp[(3) - (3)].expr), 0);
				else if ((yyvsp[(3) - (3)].expr)->type == 263)
					(yyvsp[(3) - (3)].expr) = excast(expr.program, (yyvsp[(3) - (3)].expr), (yyvsp[(1) - (3)].expr)->type, (yyvsp[(1) - (3)].expr), 0);
				else if ((yyvsp[(1) - (3)].expr)->type == 262)
					(yyvsp[(3) - (3)].expr) = excast(expr.program, (yyvsp[(3) - (3)].expr), 262, (yyvsp[(1) - (3)].expr), 0);
				else if ((yyvsp[(3) - (3)].expr)->type == 262)
					(yyvsp[(1) - (3)].expr) = excast(expr.program, (yyvsp[(1) - (3)].expr), 262, (yyvsp[(3) - (3)].expr), 0);
			}
			if (!rel)
				rel = ((yyvsp[(1) - (3)].expr)->type == 263) ? 263 : (((yyvsp[(1) - (3)].expr)->type == 260) ? 260 : (yyvsp[(3) - (3)].expr)->type);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(2) - (3)].op), 1, rel, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));
			if (!expr.program->errors && (yyvsp[(1) - (3)].expr)->op == 271 && (yyvsp[(3) - (3)].expr)->op == 271)
			{
				(yyval.expr)->data.constant.value = exeval(expr.program, (yyval.expr), 0);
				(yyval.expr)->binary = 0;
				(yyval.expr)->op = 271;
				exfreenode(expr.program, (yyvsp[(1) - (3)].expr));
				exfreenode(expr.program, (yyvsp[(3) - (3)].expr));
			}
			else if (!(((yyvsp[(1) -(3)].expr)->type) > 258) || !(((yyvsp[(3) -(3)].expr)->type) > 258)) {
				checkBinary(expr.program, (yyvsp[(1) - (3)].expr), (yyval.expr), (yyvsp[(3) - (3)].expr));
			}
		}
    break;

  case 52:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 53:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 54:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 55:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 56:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 57:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 58:
/* Line 1787 of yacc.c  */

    {
			goto relational;
		}
    break;

  case 59:
/* Line 1787 of yacc.c  */

    {
			goto relational;
		}
    break;

  case 60:
/* Line 1787 of yacc.c  */

    {
			goto relational;
		}
    break;

  case 61:
/* Line 1787 of yacc.c  */

    {
			goto relational;
		}
    break;

  case 62:
/* Line 1787 of yacc.c  */

    {
			goto relational;
		}
    break;

  case 63:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 64:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 65:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 66:
/* Line 1787 of yacc.c  */

    {
			goto binary;
		}
    break;

  case 67:
/* Line 1787 of yacc.c  */

    {
		logical:
			if ((yyvsp[(1) - (3)].expr)->type == 263)
				(yyvsp[(1) - (3)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(1) - (3)].expr), 0);
			else if (!(((yyvsp[(1) -(3)].expr)->type) > 258))
				(yyvsp[(1) - (3)].expr) = excast(expr.program, (yyvsp[(1) - (3)].expr), 259, 0, 0);
			if ((yyvsp[(3) - (3)].expr)->type == 263)
				(yyvsp[(3) - (3)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(3) - (3)].expr), 0);
			else if (!(((yyvsp[(3) -(3)].expr)->type) > 258))
				(yyvsp[(3) - (3)].expr) = excast(expr.program, (yyvsp[(3) - (3)].expr), 259, 0, 0);
			goto binary;
		}
    break;

  case 68:
/* Line 1787 of yacc.c  */

    {
			goto logical;
		}
    break;

  case 69:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(1) - (3)].expr)->op == 271)
			{
				exfreenode(expr.program, (yyvsp[(1) - (3)].expr));
				(yyval.expr) = (yyvsp[(3) - (3)].expr);
			}
			else
				(yyval.expr) = exnewnode(expr.program, ',', 1, (yyvsp[(3) - (3)].expr)->type, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));
		}
    break;

  case 70:
/* Line 1787 of yacc.c  */

    {expr.nolabel=1;}
    break;

  case 71:
/* Line 1787 of yacc.c  */

    {expr.nolabel=0;}
    break;

  case 72:
/* Line 1787 of yacc.c  */

    {
			if (!(yyvsp[(4) - (7)].expr)->type)
			{
				if (!(yyvsp[(7) - (7)].expr)->type)
					(yyvsp[(4) - (7)].expr)->type = (yyvsp[(7) - (7)].expr)->type = 259;
				else
					(yyvsp[(4) - (7)].expr)->type = (yyvsp[(7) - (7)].expr)->type;
			}
			else if (!(yyvsp[(7) - (7)].expr)->type)
				(yyvsp[(7) - (7)].expr)->type = (yyvsp[(4) - (7)].expr)->type;
			if ((yyvsp[(1) - (7)].expr)->type == 263)
				(yyvsp[(1) - (7)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(1) - (7)].expr), 0);
			else if (!(((yyvsp[(1) -(7)].expr)->type)>=259&&((yyvsp[(1) -(7)].expr)->type)<=261))
				(yyvsp[(1) - (7)].expr) = excast(expr.program, (yyvsp[(1) - (7)].expr), 259, 0, 0);
			if ((yyvsp[(4) - (7)].expr)->type != (yyvsp[(7) - (7)].expr)->type)
			{
				if ((yyvsp[(4) - (7)].expr)->type == 263 || (yyvsp[(7) - (7)].expr)->type == 263)
					exerror("if statement string type mismatch");
				else if ((yyvsp[(4) - (7)].expr)->type == 262)
					(yyvsp[(7) - (7)].expr) = excast(expr.program, (yyvsp[(7) - (7)].expr), 262, 0, 0);
				else if ((yyvsp[(7) - (7)].expr)->type == 262)
					(yyvsp[(4) - (7)].expr) = excast(expr.program, (yyvsp[(4) - (7)].expr), 262, 0, 0);
			}
			if ((yyvsp[(1) - (7)].expr)->op == 271)
			{
				if ((yyvsp[(1) - (7)].expr)->data.constant.value.integer)
				{
					(yyval.expr) = (yyvsp[(4) - (7)].expr);
					exfreenode(expr.program, (yyvsp[(7) - (7)].expr));
				}
				else
				{
					(yyval.expr) = (yyvsp[(7) - (7)].expr);
					exfreenode(expr.program, (yyvsp[(4) - (7)].expr));
				}
				exfreenode(expr.program, (yyvsp[(1) - (7)].expr));
			}
			else
				(yyval.expr) = exnewnode(expr.program, '?', 1, (yyvsp[(4) - (7)].expr)->type, (yyvsp[(1) - (7)].expr), exnewnode(expr.program, ':', 1, (yyvsp[(4) - (7)].expr)->type, (yyvsp[(4) - (7)].expr), (yyvsp[(7) - (7)].expr)));
		}
    break;

  case 73:
/* Line 1787 of yacc.c  */

    {
		iunary:
			if ((yyvsp[(2) - (2)].expr)->type == 263)
				(yyvsp[(2) - (2)].expr) = exnewnode(expr.program, 312, 1, 259, (yyvsp[(2) - (2)].expr), 0);
			else if (!(((yyvsp[(2) -(2)].expr)->type)>=259&&((yyvsp[(2) -(2)].expr)->type)<=261))
				(yyvsp[(2) - (2)].expr) = excast(expr.program, (yyvsp[(2) - (2)].expr), 259, 0, 0);
		unary:
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (2)].op), 1, (yyvsp[(2) - (2)].expr)->type == 260 ? 259 : (yyvsp[(2) - (2)].expr)->type, (yyvsp[(2) - (2)].expr), 0);
			if ((yyvsp[(2) - (2)].expr)->op == 271)
			{
				(yyval.expr)->data.constant.value = exeval(expr.program, (yyval.expr), 0);
				(yyval.expr)->binary = 0;
				(yyval.expr)->op = 271;
				exfreenode(expr.program, (yyvsp[(2) - (2)].expr));
			}
			else if (!(((yyvsp[(2) -(2)].expr)->type) > 258)) {
				checkBinary(expr.program, (yyvsp[(2) - (2)].expr), (yyval.expr), 0);
			}
		}
    break;

  case 74:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(2) - (2)].id)->local.pointer == 0)
              			exerror("cannot apply '#' operator to non-array %s", (yyvsp[(2) - (2)].id)->name);
			(yyval.expr) = exnewnode(expr.program, '#', 0, 259, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(2) - (2)].id);
		}
    break;

  case 75:
/* Line 1787 of yacc.c  */

    {
			goto iunary;
		}
    break;

  case 76:
/* Line 1787 of yacc.c  */

    {
			goto unary;
		}
    break;

  case 77:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(2) - (2)].expr);
		}
    break;

  case 78:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 266, 0, T((yyvsp[(2) - (2)].expr)->type), (yyvsp[(2) - (2)].expr), 0);
		}
    break;

  case 79:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 267, 1, T((yyvsp[(1) - (4)].id)->type), call(0, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr)), (yyvsp[(3) - (4)].expr));
		}
    break;

  case 80:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 279, 1, T((yyvsp[(1) - (4)].id)->type), call(0, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr)), (yyvsp[(3) - (4)].expr));

			
				
			
				

		}
    break;

  case 81:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewsub (expr.program, (yyvsp[(3) - (4)].expr), 280);
		}
    break;

  case 82:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewsub (expr.program, (yyvsp[(3) - (4)].expr), 302);
		}
    break;

  case 83:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewsubstr (expr.program, (yyvsp[(3) - (4)].expr));
		}
    break;

  case 84:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewsplit (expr.program, (yyvsp[(1) - (6)].id)->index, (yyvsp[(5) - (6)].id), (yyvsp[(3) - (6)].expr), 0);
		}
    break;

  case 85:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewsplit (expr.program, (yyvsp[(1) - (8)].id)->index, (yyvsp[(5) - (8)].id), (yyvsp[(3) - (8)].expr), (yyvsp[(7) - (8)].expr));
		}
    break;

  case 86:
/* Line 1787 of yacc.c  */

    {
			if (!(((yyvsp[(3) -(4)].expr)->type)>=259&&((yyvsp[(3) -(4)].expr)->type)<=261))
				(yyvsp[(3) - (4)].expr) = excast(expr.program, (yyvsp[(3) - (4)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, 277, 1, 259, (yyvsp[(3) - (4)].expr), 0);
		}
    break;

  case 87:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 295, 0, 262, 0, 0);
		}
    break;

  case 88:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 300, 0, 259, 0, 0);
		}
    break;

  case 89:
/* Line 1787 of yacc.c  */

    {
			if (!(((yyvsp[(3) -(4)].expr)->type)>=259&&((yyvsp[(3) -(4)].expr)->type)<=261))
				(yyvsp[(3) - (4)].expr) = excast(expr.program, (yyvsp[(3) - (4)].expr), 259, 0, 0);
			(yyval.expr) = exnewnode(expr.program, 300, 1, 259, (yyvsp[(3) - (4)].expr), 0);
		}
    break;

  case 90:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 269, 1, (yyvsp[(1) - (4)].id)->type, 0, (yyvsp[(3) - (4)].expr));
			(yyval.expr)->data.call.procedure = (yyvsp[(1) - (4)].id);
		}
    break;

  case 91:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exprint(expr.program, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr));
		}
    break;

  case 92:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (4)].id)->index, 0, (yyvsp[(1) - (4)].id)->type, 0, 0);
			if ((yyvsp[(3) - (4)].expr) && (yyvsp[(3) - (4)].expr)->data.operand.left->type == 259)
			{
				(yyval.expr)->data.print.descriptor = (yyvsp[(3) - (4)].expr)->data.operand.left;
				(yyvsp[(3) - (4)].expr) = (yyvsp[(3) - (4)].expr)->data.operand.right;
			}
			else 
				switch ((yyvsp[(1) - (4)].id)->index)
				{
				case 294:
					(yyval.expr)->data.print.descriptor = exnewnode(expr.program, 271, 0, 259, 0, 0);
					(yyval.expr)->data.print.descriptor->data.constant.value.integer = 2;
					break;
				case 292:
					(yyval.expr)->data.print.descriptor = exnewnode(expr.program, 271, 0, 259, 0, 0);
					(yyval.expr)->data.print.descriptor->data.constant.value.integer = 1;
					break;
				case 299:
					(yyval.expr)->data.print.descriptor = 0;
					break;
				}
			(yyval.expr)->data.print.args = preprint((yyvsp[(3) - (4)].expr));
		}
    break;

  case 93:
/* Line 1787 of yacc.c  */

    {
			register Exnode_t*	x;

			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (4)].id)->index, 0, (yyvsp[(1) - (4)].id)->type, 0, 0);
			if ((yyvsp[(3) - (4)].expr) && (yyvsp[(3) - (4)].expr)->data.operand.left->type == 259)
			{
				(yyval.expr)->data.scan.descriptor = (yyvsp[(3) - (4)].expr)->data.operand.left;
				(yyvsp[(3) - (4)].expr) = (yyvsp[(3) - (4)].expr)->data.operand.right;
			}
			else 
				switch ((yyvsp[(1) - (4)].id)->index)
				{
				case 297:
					(yyval.expr)->data.scan.descriptor = 0;
					break;
				case 301:
					if ((yyvsp[(3) - (4)].expr) && (yyvsp[(3) - (4)].expr)->data.operand.left->type == 263)
					{
						(yyval.expr)->data.scan.descriptor = (yyvsp[(3) - (4)].expr)->data.operand.left;
						(yyvsp[(3) - (4)].expr) = (yyvsp[(3) - (4)].expr)->data.operand.right;
					}
					else
						exerror("%s: string argument expected", (yyvsp[(1) - (4)].id)->name);
					break;
				}
			if (!(yyvsp[(3) - (4)].expr) || !(yyvsp[(3) - (4)].expr)->data.operand.left || (yyvsp[(3) - (4)].expr)->data.operand.left->type != 263)
				exerror("%s: format argument expected", (yyvsp[(1) - (4)].id)->name);
			(yyval.expr)->data.scan.format = (yyvsp[(3) - (4)].expr)->data.operand.left;
			for (x = (yyval.expr)->data.scan.args = (yyvsp[(3) - (4)].expr)->data.operand.right; x; x = x->data.operand.right)
			{
				if (x->data.operand.left->op != 266)
					exerror("%s: address argument expected", (yyvsp[(1) - (4)].id)->name);
				x->data.operand.left = x->data.operand.left->data.operand.left;
			}
		}
    break;

  case 94:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(2) - (2)].expr))
			{
				if ((yyvsp[(1) - (2)].expr)->op == 283 && !expr.program->disc->setf)
					exerror("%s: variable assignment not supported", (yyvsp[(1) - (2)].expr)->data.variable.symbol->name);
				else
				{
					if (!(yyvsp[(1) - (2)].expr)->type)
						(yyvsp[(1) - (2)].expr)->type = (yyvsp[(2) - (2)].expr)->type;

					

					else if ((yyvsp[(2) - (2)].expr)->type != (yyvsp[(1) - (2)].expr)->type)

					{
						(yyvsp[(2) - (2)].expr)->type = (yyvsp[(1) - (2)].expr)->type;
						(yyvsp[(2) - (2)].expr)->data.operand.right = excast(expr.program, (yyvsp[(2) - (2)].expr)->data.operand.right, (yyvsp[(1) - (2)].expr)->type, 0, 0);
					}
					(yyvsp[(2) - (2)].expr)->data.operand.left = (yyvsp[(1) - (2)].expr);
					(yyval.expr) = (yyvsp[(2) - (2)].expr);
				}
			}
		}
    break;

  case 95:
/* Line 1787 of yacc.c  */

    {
		pre:
			if ((yyvsp[(2) - (2)].expr)->type == 263)
				exerror("++ and -- invalid for string variables");
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(1) - (2)].op), 0, (yyvsp[(2) - (2)].expr)->type, (yyvsp[(2) - (2)].expr), 0);
			(yyval.expr)->subop = 290;
		}
    break;

  case 96:
/* Line 1787 of yacc.c  */

    {
		pos:
			if ((yyvsp[(1) - (2)].expr)->type == 263)
				exerror("++ and -- invalid for string variables");
			(yyval.expr) = exnewnode(expr.program, (yyvsp[(2) - (2)].op), 0, (yyvsp[(1) - (2)].expr)->type, (yyvsp[(1) - (2)].expr), 0);
			(yyval.expr)->subop = 288;
		}
    break;

  case 97:
/* Line 1787 of yacc.c  */

    {
			if ((yyvsp[(3) - (3)].id)->local.pointer == 0)
              			exerror("cannot apply IN to non-array %s", (yyvsp[(3) - (3)].id)->name);
			if (((yyvsp[(3) - (3)].id)->index_type > 0) && ((yyvsp[(1) - (3)].expr)->type != (yyvsp[(3) - (3)].id)->index_type))
            		    exerror("%s indices must have type %s, not %s", 
				(yyvsp[(3) - (3)].id)->name, extypename(expr.program, (yyvsp[(3) - (3)].id)->index_type),extypename(expr.program, (yyvsp[(1) - (3)].expr)->type));
			(yyval.expr) = exnewnode(expr.program, 331, 0, 259, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(3) - (3)].id);
			(yyval.expr)->data.variable.index = (yyvsp[(1) - (3)].expr);
		}
    break;

  case 98:
/* Line 1787 of yacc.c  */

    {
			goto pre;
		}
    break;

  case 99:
/* Line 1787 of yacc.c  */

    {
			goto pos;
		}
    break;

  case 103:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 271, 0, (yyvsp[(1) - (1)].id)->type, 0, 0);
			if (!expr.program->disc->reff)
				exerror("%s: identifier references not supported", (yyvsp[(1) - (1)].id)->name);
			else
				(yyval.expr)->data.constant.value = (*expr.program->disc->reff)(expr.program, (yyval.expr), (yyvsp[(1) - (1)].id), 0, 0, (-1), expr.program->disc);
		}
    break;

  case 104:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 271, 0, 262, 0, 0);
			(yyval.expr)->data.constant.value.floating = (yyvsp[(1) - (1)].floating);
		}
    break;

  case 105:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 271, 0, 259, 0, 0);
			(yyval.expr)->data.constant.value.integer = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 106:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 271, 0, 263, 0, 0);
			(yyval.expr)->data.constant.value.string = (yyvsp[(1) - (1)].string);
		}
    break;

  case 107:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 271, 0, 260, 0, 0);
			(yyval.expr)->data.constant.value.integer = (yyvsp[(1) - (1)].integer);
		}
    break;

  case 113:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = makeVar(expr.program, (yyvsp[(1) - (2)].id), 0, 0, (yyvsp[(2) - (2)].reference));
		}
    break;

  case 114:
/* Line 1787 of yacc.c  */

    {
			Exnode_t*   n;

			n = exnewnode(expr.program, 275, 0, (yyvsp[(1) - (3)].id)->type, 0, 0);
			n->data.variable.symbol = (yyvsp[(1) - (3)].id);
			n->data.variable.reference = 0;
			if (((n->data.variable.index = (yyvsp[(2) - (3)].expr)) == 0) != ((yyvsp[(1) - (3)].id)->local.pointer == 0))
				exerror("%s: is%s an array", (yyvsp[(1) - (3)].id)->name, (yyvsp[(1) - (3)].id)->local.pointer ? "" : " not");
			if ((yyvsp[(1) - (3)].id)->local.pointer && ((yyvsp[(1) - (3)].id)->index_type > 0)) {
				if ((yyvsp[(2) - (3)].expr)->type != (yyvsp[(1) - (3)].id)->index_type)
					exerror("%s: indices must have type %s, not %s", 
						(yyvsp[(1) - (3)].id)->name, extypename(expr.program, (yyvsp[(1) - (3)].id)->index_type),extypename(expr.program, (yyvsp[(2) - (3)].expr)->type));
			}
			if ((yyvsp[(3) - (3)].reference)) {
				n->data.variable.dyna =exnewnode(expr.program, 0, 0, 0, 0, 0);
				(yyval.expr) = makeVar(expr.program, (yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].expr), n, (yyvsp[(3) - (3)].reference));
			}
			else (yyval.expr) = n;
		}
    break;

  case 115:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 283, 0, 263, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(1) - (1)].id);
			(yyval.expr)->data.variable.reference = 0;
			(yyval.expr)->data.variable.index = 0;
			(yyval.expr)->data.variable.dyna = 0;
			if (!(expr.program->disc->flags & (1<<9)))
				exerror("unknown identifier");
		}
    break;

  case 116:
/* Line 1787 of yacc.c  */

    {
			(yyval.integer) = 0;
		}
    break;

  case 117:
/* Line 1787 of yacc.c  */

    {
			(yyval.integer) = -1;
		}
    break;

  case 118:
/* Line 1787 of yacc.c  */

    {
			/* If DECLARE is VOID, its type is 0, so this acts like
			 * the empty case.
			 */
			if ((((yyvsp[(2) -(3)].id)->type)>=259&&((yyvsp[(2) -(3)].id)->type)<=261))
				(yyval.integer) = 259;
			else
				(yyval.integer) = (yyvsp[(2) - (3)].id)->type;
				
		}
    break;

  case 119:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 120:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(2) - (3)].expr);
		}
    break;

  case 121:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 122:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = (yyvsp[(1) - (1)].expr)->data.operand.left;
			(yyvsp[(1) - (1)].expr)->data.operand.left = (yyvsp[(1) - (1)].expr)->data.operand.right = 0;
			exfreenode(expr.program, (yyvsp[(1) - (1)].expr));
		}
    break;

  case 123:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, ',', 1, 0, exnewnode(expr.program, ',', 1, (yyvsp[(1) - (1)].expr)->type, (yyvsp[(1) - (1)].expr), 0), 0);
			(yyval.expr)->data.operand.right = (yyval.expr)->data.operand.left;
		}
    break;

  case 124:
/* Line 1787 of yacc.c  */

    {
			(yyvsp[(1) - (3)].expr)->data.operand.right = (yyvsp[(1) - (3)].expr)->data.operand.right->data.operand.right = exnewnode(expr.program, ',', 1, (yyvsp[(1) - (3)].expr)->type, (yyvsp[(3) - (3)].expr), 0);
		}
    break;

  case 125:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 126:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
			if ((yyvsp[(1) - (1)].id)->type)
				exerror("(void) expected");
		}
    break;

  case 128:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, ',', 1, (yyvsp[(1) - (1)].expr)->type, (yyvsp[(1) - (1)].expr), 0);
		}
    break;

  case 129:
/* Line 1787 of yacc.c  */

    {
			register Exnode_t*	x;
			register Exnode_t*	y;

			(yyval.expr) = (yyvsp[(1) - (3)].expr);
			for (x = (yyvsp[(1) - (3)].expr); (y = x->data.operand.right); x = y);
			x->data.operand.right = exnewnode(expr.program, ',', 1, (yyvsp[(3) - (3)].expr)->type, (yyvsp[(3) - (3)].expr), 0);
		}
    break;

  case 130:
/* Line 1787 of yacc.c  */

    {expr.declare=(yyvsp[(1) - (1)].id)->type;}
    break;

  case 131:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, 283, 0, (yyvsp[(1) - (3)].id)->type, 0, 0);
			(yyval.expr)->data.variable.symbol = (yyvsp[(3) - (3)].id);
			(yyvsp[(3) - (3)].id)->lex = 275;
			(yyvsp[(3) - (3)].id)->type = (yyvsp[(1) - (3)].id)->type;
			(yyvsp[(3) - (3)].id)->value = exnewnode(expr.program, 0, 0, 0, 0, 0);
			expr.procedure->data.procedure.arity++;
			expr.declare = 0;
		}
    break;

  case 132:
/* Line 1787 of yacc.c  */

    {
			(yyval.reference) = expr.refs = expr.lastref = 0;
		}
    break;

  case 133:
/* Line 1787 of yacc.c  */

    {
			Exref_t*	r;

			r = (Exref_t*)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Exref_t))+(0)),((0000002|0000001|0000004)));
			r->symbol = (yyvsp[(1) - (1)].id);
			expr.refs = r;
			expr.lastref = r;
			r->next = 0;
			r->index = 0;
			(yyval.reference) = expr.refs;
		}
    break;

  case 134:
/* Line 1787 of yacc.c  */

    {
			Exref_t*	r;
			Exref_t*	l;

			r = (Exref_t*)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Exref_t))+(0)),((0000002|0000001|0000004)));
			r->symbol = (yyvsp[(3) - (3)].id);
			r->index = 0;
			r->next = 0;
			l = (Exref_t*)(char*)(*(((Vmalloc_t*)(((expr.program)->vm)))->meth.resizef)) ((((expr.program)->vm)),(void*)((0)),(sizeof(char)*(sizeof(Exref_t))+(0)),((0000002|0000001|0000004)));
			l->symbol = (yyvsp[(2) - (3)].id);
			l->index = 0;
			l->next = r;
			expr.refs = l;
			expr.lastref = r;
			(yyval.reference) = expr.refs;
		}
    break;

  case 135:
/* Line 1787 of yacc.c  */

    {
			(yyval.id) = (yyvsp[(2) - (2)].id);
		}
    break;

  case 136:
/* Line 1787 of yacc.c  */

    {
			(yyval.id) = (yyvsp[(2) - (2)].id);
		}
    break;

  case 137:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = 0;
		}
    break;

  case 138:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = exnewnode(expr.program, '=', 1, (yyvsp[(2) - (2)].expr)->type, 0, (yyvsp[(2) - (2)].expr));
			(yyval.expr)->subop = (yyvsp[(1) - (2)].op);
		}
    break;

  case 140:
/* Line 1787 of yacc.c  */

    {
				register Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("%s: nested function definitions not supported", expr.id->name);
				expr.procedure = exnewnode(expr.program, 293, 1, expr.declare, 0, 0);
				if (!(disc = ((0)?(Dtdisc_t*)realloc((char*)(0),sizeof(Dtdisc_t)*(1)+(0)):(Dtdisc_t*)calloc(1,sizeof(Dtdisc_t)*(1)+(0)))))
					exnospace();
				disc->key = offsetof(Exid_t, name);
				if (!(*(expr.id->name)==*("begin")&&!strcmp(expr.id->name,"begin")))
				{
					if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
						exnospace();
					expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
					expr.program->formals = 1;
				}
				expr.declare = 0;
			}
    break;

  case 141:
/* Line 1787 of yacc.c  */

    {
				expr.id->lex = 293;
				expr.id->type = expr.procedure->type;
				expr.program->formals = 0;
				expr.declare = 0;
			}
    break;

  case 142:
/* Line 1787 of yacc.c  */

    {
			(yyval.expr) = expr.procedure;
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, 0);
				expr.program->frame = 0;
			}
			(yyval.expr)->data.operand.left = (yyvsp[(3) - (8)].expr);
			(yyval.expr)->data.operand.right = excast(expr.program, (yyvsp[(7) - (8)].expr), (yyval.expr)->type, 0, 0);

			/*
			 * NOTE: procedure definition was slipped into the
			 *	 declaration initializer statement production,
			 *	 therefore requiring the statement terminator
			 */

			((expr.program)->linep--,(expr.program)->input->peek=(';'));
		}
    break;


/* Line 1787 of yacc.c  */

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  do { if (yydebug) { fprintf (stderr, "%s ", "-> $$ ="); yy_symbol_print (stderr, yyr1[yyn], &yyval); fprintf (stderr, "\n"); } } while ((0));

  (yyvsp -= (yylen), yyssp -= (yylen));
  yylen = 0;
  do { if (yydebug) yy_stack_print ((yyss), (yyssp)); } while ((0));

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - 107] + *yyssp;
  if (0 <= yystate && yystate <= 1112 && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - 107];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == (-2) ? (-2) : ((unsigned int) (yychar) <= 336 ? yytranslate[yychar] : 2);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

      yyerror ("syntax error");



      
        
        
        
        
          
        
          
            
              
            
            
              
                
                
                
              
            
              
                
                
              
          
        
        
          
      


    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= 0)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == 0)
	    goto yyabortlab;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = (-2);
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  (yyvsp -= (yylen), yyssp -= (yylen));
  yylen = 0;
  do { if (yydebug) yy_stack_print ((yyss), (yyssp)); } while ((0));
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!((yyn) == (-144)))
	{
	  yyn += 1;
	  if (0 <= yyn && yyn <= 1112 && yycheck[yyn] == 1)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	goto yyabortlab;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      (yyvsp -= (1), yyssp -= (1));
      yystate = *yyssp;
      do { if (yydebug) yy_stack_print ((yyss), (yyssp)); } while ((0));
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  do { if (yydebug) { fprintf (stderr, "%s ", "Shifting"); yy_symbol_print (stderr, yystos[yyn], yyvsp); fprintf (stderr, "\n"); } } while ((0));

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror ("memory exhausted");
  yyresult = 2;
  /* Fall through.  */


yyreturn:
  if (yychar != (-2))
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = ((unsigned int) (yychar) <= 336 ? yytranslate[yychar] : 2);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  (yyvsp -= (yylen), yyssp -= (yylen));
  do { if (yydebug) yy_stack_print ((yyss), (yyssp)); } while ((0));
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      (yyvsp -= (1), yyssp -= (1));
    }

  if (yyss != yyssa)
    free (yyss);


  
    

  /* Make sure YYID is used.  */
  return (yyresult);
}


/* Line 2048 of yacc.c  */



#line 1 "graphviz-2.38.0\\lib\\expr\\exgram.h" 1
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
 * grammar support routines
 * stuffed in a header so exparse.y can work
 * with both yacc and bison
 * sometimes free stuff can cost a lot
 */























	
	    
	
	    









	

	
	
	
	
	
	
	
	
	









	
	
	
	
	

	
	
	
		
			
		
	
		
	
		
			
		
	
		
			
		
		
			
			
		
		
	
		
			
			
		
		

	
		
			
		
			
			
		
		
	
	
		
			
		
	
		
		
		
			
			
		
		
			
		
	
	
	
		
		
		
			
		
	
	
		
			
		
		
			
			
		
		
	
		
		
	
	
		
			
		
		
		
			
				
			
				
			
			
		
		
	
		
			
		
			
		
	
	









	
	

	
	    
	
	
	
	
	







	

	
              	
	
            
		
	
            
		
	
            
		
	
            
		
	
	
	
	
	







	
	
	
	

	
	
	    
	
	
	    
	
	    
	    
		
	
	    
	
	    
	
	
	
	
	






	
	
	
	

	
	
	    
	
	
	    
	
	    
	    
		
	
	    
	
	    
	
	
	
	
	







	
	

	
	    
	    
	
	
	    
	
	    
		
		    
			    
		
		
	    
		
		
		    
		    
		
		    
		    
		
	    
	
	    
		
			
	
	    
	    
		
		
		    
		
	    
		
			 
			 
		
		    
		
	    
		
		
	    
	
	






	
	

	
	    
		
		    
	    
	
	
	











			     
	
	
	

	
	
	    
		
		
	    
		
	    
	    
	
	    

	
	    
	
	    

	
	
	
	
	
	
	    
	
	    
					 
					 

	








	




	
	
	
	
	
	









	
	    
	






	
	    
	





	
	
	

	
	
		
		
			
			
		
		
			
		
			
		
			
			
				
		    	
					
						
							
				     			
				     			
						
							
							
							
							
					
			    		
							
					
				
			
			
		
		
		
		
		
		
		
		
		
		
			
			
				
					
			
			
				
			
		
			
			
		
			
			
			
		
			
			
		
			
			
			
		
			
			
			
				
			
		
			
			
			
				
			
		
			
			
		
		
	
	












	
	
	

	
	
		
			
		
		
		
		
		
		
		
		
			
			
			
			
				
			
			
				
				
					
				
				
				
				
			
			
		
			
			
		
			
			
			
		
			
			
		
			
			
			
		
			
			
		
			
			
		
			
			
		
	
	











	
	

	
		
	
	
	
	
		
		
			
			
			
		
		
		
			
			
		
	
	










	
	
	
	

	
	
	
	
	
	
	
	
		
		
			
			
		
		
		
			
		
		
	
	
		
	









	
	
	
	
	
	
	
	
	
	

	
		
	
	
		
		
		
		
	
	
	
	
	
		
		
		
			
				
			
				
			
				
		
	
	
	
	
		
		
			
		
			
		
		
		
		
			
			
			
			
				
				
				
					
					
				
					
					
						
						
						
					
					
					
						
						
						
					
					
					
					
				
					
					
					
						
						
						
						
							
							
						
							
							
						
							
								
							
						
							
						
						
					
					
				
				
					
				
				
				
					
					
				
					
					
				
					
					
				
				
				
				
					
					
				
				
					
					
				
					
						
					
				
				
			
		
			
			
			
				
				
					
					
						
						
						
					
					
					
						
						
					
				
				
			
			
			
				
				
				
			
			
			
			
			
				
					
				
			
			
				
					
				
				
			
				
				
					
					
						
							
						
					
					
						
					
						
				
				
			
			
		
		
		
			
		
	
	
		
 
	
	









	
	
	

	
	
		
		
	
	
		
	
	
		
			
		
		
			
			
				
				
			
			
			
				
				
			
		
	
	
	
	
		
		
		
			
				
		
		
			
	
	
		
	
	
	
	
	
		
	
	
	
	
	
	









	
	

	
		
	
		
	
	
		
	
	
		
			
				
				
					
					
				
		
			
	
	
		
	
		
	
	
	
	
		
	







	









	
	

	
	
	
	
		
			
	
	
		
	
		
	
	
	
	
	
	
		
			
			
				
				
					
			
		
	
	









	
	

	
	
		
		
			
				
					
			
				
			
				
			
				
			
				
			
			
				
					
				
					
				
					
			
			
		
		
		
			
			
		
	










	
	    
		
		    
		     
		     
	    
		
		    
		     
	









	
	
	    
	    
	
	    
	    
	
	    
	    
	
	    
	
	    
		  
	    
	





	
	    
	
	    
	
	    





	







#line 3175 "graphviz-2.38.0\\lib\\expr\\y.tab.c" 2

