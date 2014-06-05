#line 1 "graphviz-2.38.0\\lib\\sfio\\sfvprintf.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
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











/*	Internal definitions for sfio.
**	Written by Kiem-Phong Vo
*/

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio_t.h" 1
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








/*	This header file is for library writers who need to know certain
**	internal info concerning the full Sfio_t structure. Including this
**	file means that you agree to track closely with sfio development
**	in case its internal architecture is changed.
**
**	Written by Kiem-Phong Vo
*/

/* the parts of Sfio_t private to sfio functions */
















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

	 _ast_intmax_t extent; _ast_intmax_t here; unsigned char getr; unsigned char tiny[1]; unsigned short bits; unsigned int mode; struct _sfdisc_s* disc; struct _sfpool_s* pool; struct _sfrsrv_s* rsrv; struct _sfproc_s* proc; Void_t* mutex; Void_t* stdio; _ast_intmax_t lpos; size_t iosz;

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




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 44 "graphviz-2.38.0\\lib\\sfio\\sfio_t.h" 2

/* mode bit to indicate that the structure hasn't been initialized */


/* short-hand for common stream types */





/* for static initialization of an Sfio_t structure */



























/* function to clear an Sfio_t structure */
































#line 25 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 2

/* note that the macro vt_threaded has effect on vthread.h */
#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1
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










/*	Header for the Vthread library.
**	Note that the macro vt_threaded may be defined
**	outside of vthread.h to suppress threading.
**
**	Written by Kiem-Phong Vo
*/

#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1

/* ast doesn't do threads yet */
















    
    
    
    
    










    
    
    
    
    






/* common attributes for various structures */







/* directives for vtset() */


    typedef struct _vtmutex_s Vtmutex_t;
    typedef struct _vtonce_s Vtonce_t;
    typedef struct _vthread_s Vthread_t;














     1 extern Vthread_t *vtopen _ARG_((Vthread_t *, int));
    extern int vtclose _ARG_((Vthread_t *));
    extern int vtset _ARG_((Vthread_t *, int, Void_t *));
    extern int vtrun _ARG_((Vthread_t *, void *(*)(void *), void *));
    extern int vtkill _ARG_((Vthread_t *));
    extern int vtwait _ARG_((Vthread_t *));

/*    extern int vtonce _ARG_((Vtonce_t *, void (*)())); */

    extern Vtmutex_t *vtmtxopen _ARG_((Vtmutex_t *, int));
    extern int vtmtxclose _ARG_((Vtmutex_t *));
    extern int vtmtxlock _ARG_((Vtmutex_t *));
    extern int vtmtxtrylock _ARG_((Vtmutex_t *));
    extern int vtmtxunlock _ARG_((Vtmutex_t *));
    extern int vtmtxclrlock _ARG_((Vtmutex_t *));

    extern Void_t *vtstatus _ARG_((Vthread_t *));
    extern int vterror _ARG_((Vthread_t *));
    extern int vtmtxerror _ARG_((Vtmutex_t *));
    extern int vtonceerror _ARG_((Vtonce_t *));

     _END_EXTERNS_


	
	
	
	
	
	
    


    
	
	
	
	
	
	
	
    


    
	
	
	
    














/* fake structures and functions */

    struct _vtmutex_s {
	int error;
    };
    struct _vtattr_s {
	int error;
    };
    struct _vthread_s {
	int error;
    };
    struct _vtonce_s {
	int error;
    };































#line 28 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 2

/* file system info */





























/* when building the binary compatibility package, a number of header files
   are not needed and they may get in the way so we remove them here.
*/





























































#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1



















#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1






































/* functions for polling readiness of streams */


























/* to test for executable access mode of a file */




/* alternative process forking */























































































/* 64-bit vs 32-bit file stuff */


    





    



/* to get rid of pesky compiler warnings */






/* Private flags in the "bits" field */







/* this bit signals sfmutex() not to create a mutex for a private stream */


/* on closing, don't be a hero about reread/rewrite on interrupts */


/* private flags that must be cleared in sfclrlock */







/* bits for the mode field, SF_INIT defined in sfio_t.h */



















/* short-hands */

















/* macros do determine stream types from Stat_t data */








































/* set close-on-exec */












/* a couple of error number that we use, default values are like Linux */


















/* see if we can use memory mapping for io */

















/* function to get the decimal point for local environment */





























/* stream pool structure. */
    typedef struct _sfpool_s Sfpool_t;
    struct _sfpool_s {
	Sfpool_t *next;
	int mode;		/* type of pool                 */
	int s_sf;		/* size of pool array           */
	int n_sf;		/* number currently in pool     */
	Sfio_t **sf;		/* array of streams             */
	Sfio_t *array[3];	/* start with 3                 */
	Vtmutex_t mutex;	/* mutex lock object            */
    };

/* reserve buffer structure */
    typedef struct _sfrsrv_s Sfrsrv_t;
    struct _sfrsrv_s {
	ssize_t slen;		/* last string length           */
	ssize_t size;		/* buffer size                  */
	unsigned char data[1];		/* data buffer                  */
    };

/* co-process structure */
    typedef struct _sfproc_s Sfproc_t;
    struct _sfproc_s {
	int pid;		/* process id                   */
	unsigned char *rdata;		/* read data being cached       */
	int ndata;		/* size of cached data          */
	int size;		/* buffer size                  */
	int file;		/* saved file descriptor        */
	int sigp;		/* sigpipe protection needed    */
    };

/* extensions to sfvprintf/sfvscanf */








    typedef struct _fmt_s Fmt_t;
    typedef struct _fmtpos_s Fmtpos_t;
    typedef union {
	int i, *ip;
	long l, *lp;
	short h, *hp;
	unsigned int ui;
	unsigned long ul;
	unsigned short uh;
	_ast_intmax_t ll, *llp;
	unsigned _ast_intmax_t lu;
	_ast_fltmax_t ld;
	double d;
	float f;
	char c, *s, **sp;
	Void_t *vp;
	Sffmt_t *ft;
    } Argv_t;

    struct _fmt_s {
	char *form;		/* format string                */
	va_list args;		/* corresponding arglist        */

	char *oform;		/* original format string       */
	va_list oargs;		/* original arg list            */
	int argn;		/* number of args already used  */
	Fmtpos_t *fp;		/* position list                */

	Sffmt_t *ft;		/* formatting environment       */
	Sffmtevent_f eventf;	/* event function               */
	Fmt_t *next;		/* stack frame pointer          */
    };

    struct _fmtpos_s {
	Sffmt_t ft;		/* environment                  */
	Argv_t argv;		/* argument value               */
	int fmt;		/* original format              */
	int need[5];	/* positions depending on       */
    };























/* format flags&types, must coexist with those in sfio.h */








/* type of elements to be converted */







/* local variables used across sf-functions */













    typedef struct _sfextern_s {
	ssize_t sf_page;
	struct _sfpool_s sf_pool;
	int (*sf_pmove) _ARG_((Sfio_t *, int));
	Sfio_t *(*sf_stack) _ARG_((Sfio_t *, Sfio_t *));
	void (*sf_notify) _ARG_((Sfio_t *, int, int));
	int (*sf_stdsync) _ARG_((Sfio_t *));
	struct _sfdisc_s sf_udisc;
	void (*sf_cleanup) _ARG_((void));
	int sf_exiting;
	int sf_done;
	Vtonce_t *sf_once;
	void (*sf_oncef) _ARG_((void));
	Vtmutex_t *sf_mutex;
    } Sfextern_t;

/* get the real value of a byte in a coded long or ulong */




/* amount of precision to get in each iteration during coding of doubles */


/* grain size for buffer increment */



/* when the buffer is empty, certain io requests may be better done directly
   on the given application buffers. The below condition determines when.
*/



/* number of pages to memory map at a time */


/* set/unset sequential states for mmap */



















/* the bottomless bit bucket */







/* exception types */

























/* lock/open a stream */










/* check to see if the stream can be accessed */




/* set discipline code */
























/* fast peek of a stream */






/* more than this for a line buffer, we might as well flush */


/* safe closing function */


/* string stream extent */





/* control flags for open() */










































/* floating point to ascii conversion */











/* tables for numerical translation */











    typedef struct _sftab_ {
	_ast_fltmax_t sf_pos10[6];	/* positive powers of 10        */
	_ast_fltmax_t sf_neg10[6];	/* negative powers of 10        */
	unsigned char sf_dec[200];	/* ascii reps of values < 100   */
	char *sf_digits;	/* digits for general bases     */
	int (*sf_cvinitf) (void);	/* initialization function      */
	int sf_cvinit;		/* initialization state         */
	Fmtpos_t *(*sf_fmtposf)
	    _ARG_((Sfio_t *, const char *, va_list, int));
	char *(*sf_fmtintf) _ARG_((const char *, int *));
	unsigned char sf_cv36[((unsigned char)(~0)) + 1];	/* conversion for base [2-36]   */
	unsigned char sf_cv64[((unsigned char)(~0)) + 1];	/* conversion for base [37-64]  */
	unsigned char sf_type[((unsigned char)(~0)) + 1];	/* conversion formats&types     */
    } Sftab_t;

/* thread-safe macro/function to initialize _Sfcv* conversion tables */


/* sfucvt() converts decimal integers to ASCII */













































/* handy functions */





/* fast functions for memory copy and memory clear */













/* note that MEMCPY advances the associated pointers */























     1 extern Sfextern_t _Sfextern;
    extern Sftab_t _Sftable;

    extern int _sfpopen _ARG_((Sfio_t *, int, int, int));
    extern int _sfpclose _ARG_((Sfio_t *));
    extern int _sfmode _ARG_((Sfio_t *, int, int));
    extern int _sftype _ARG_((const char *, int *, int *));
    extern int _sfexcept _ARG_((Sfio_t *, int, ssize_t, Sfdisc_t *));
    extern Sfrsrv_t *_sfrsrv _ARG_((Sfio_t *, ssize_t));
    extern int _sfsetpool _ARG_((Sfio_t *));
    extern char *_sfcvt _ARG_((Void_t *, int, int *, int *, int));
    extern char **_sfgetpath _ARG_((char *));
    extern _ast_fltmax_t _sfstrtod _ARG_((const char *, char **));






    _astimport int errno;


/* for portable encoding of double values */


    extern double frexp _ARG_((double, int *));
    extern double ldexp _ARG_((double, int));




    extern Void_t *mmap _ARG_((Void_t *, size_t, int, int, int, off_t));
    extern int munmap _ARG_((Void_t *, size_t));





    extern void abort _ARG_((void));
    extern int atexit _ARG_((void (*)(void)));
    extern char *getenv _ARG_((const char *));
    extern void *malloc _ARG_((size_t));
    extern void *realloc _ARG_((void *, size_t));
    extern void free _ARG_((void *));
    extern size_t strlen _ARG_((const char *));
    extern char *strcpy _ARG_((char *, const char *));

    extern Void_t *memset _ARG_((void *, int, size_t));
    extern Void_t *memchr _ARG_((const void *, int, size_t));
    extern Void_t *memccpy _ARG_((void *, const void *, int, size_t));

    extern Void_t *memcpy _ARG_((void *, const void *, size_t));


    


    extern int remove _ARG_((const char *));









    extern int close _ARG_((int));
    extern ssize_t read _ARG_((int, void *, size_t));
    extern ssize_t write _ARG_((int, const void *, size_t));
    extern off_t lseek _ARG_((int, off_t, int));
    extern int dup _ARG_((int));
    extern int isatty _ARG_((int));
    extern int wait _ARG_((int *));
    extern int pipe _ARG_((int *));
    extern int access _ARG_((const char *, int));
    extern unsigned int sleep _ARG_((unsigned int));
    extern int execl _ARG_((const char *, const char *, ...));
    extern int execv _ARG_((const char *, char **));

    extern int fork _ARG_((void));


    






    


    


    extern time_t time _ARG_((time_t *));
    extern int waitpid _ARG_((int, int *, int));

    extern void _exit _ARG_((int));

    typedef int (*Onexit_f) _ARG_((void));
    extern Onexit_f onexit _ARG_((Onexit_f));


    



    




    

    




    




     _END_EXTERNS_




#line 16 "graphviz-2.38.0\\lib\\sfio\\sfvprintf.c" 2

/*	The engine for formatting data
**
**	Written by Kiem-Phong Vo.
*/










int sfvprintf(Sfio_t * f, const char *form, va_list args)






{
    register int v = 0, n_s, base, fmt, flags;
    _ast_intmax_t lv;
    register char *sp, *ssp, *endsp, *ep, *endep;
    int dot, width, precis, n, n_output;
    int sign, decpt;
    ssize_t size;
    double dval;

    _ast_fltmax_t ldval;

    char *tls[2], **ls;		/* for %..[separ]s              */
    char *t_str;		/* stuff between ()             */
    ssize_t n_str;		/* its length                   */

    Argv_t argv;		/* for extf to return value     */
    Sffmt_t *ft;		/* format environment           */
    Fmt_t *fm, *fmstk;		/* stack contexts               */

    char *oform;		/* original format string       */
    va_list oargs;		/* original arg list            */
    Fmtpos_t *fp;		/* arg position list            */
    int argp, argn;		/* arg position and number      */


    char buf[(((1024+(8*1024))/sizeof(int) + 1)*sizeof(int)) + 1024], data[1024];
    int decimal = 0, thousand = 0;

    /* fast io system */
    register unsigned char *d, *endd;
    register int w;

























    ((_Sftable.sf_cvinit) ? 1 : ((_Sftable.sf_cvinit) = (*(_Sftable.sf_cvinitf))()) );			/* initialize conversion tables */

    { if(!f) return(-1); };

    if (!form)
	{ return(-1); };

    /* make sure stream is in write mode and buffer is not NULL */
    if (f->mode != 0000002 && _sfmode(f, 0000002, 0) < 0)
	{ return(-1); };

    (void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);

    if (!f->data && !(f->flags & 0000004)) {
	f->data = f->next = (unsigned char *) data;
	f->endb = f->data + sizeof(data);
    }
    ((d = f->next, endd = f->endb), n_output = 0);

    tls[1] = ((char *)0);

    fmstk = ((Fmt_t *)0);
    ft = ((Sffmt_t *)0);

    oform = (char *) form;
    va_copy(oargs, args);
    fp = ((Fmtpos_t *)0);
    argn = -1;

  loop_fmt:
    while ((n = *form)) {
	if (n != '%') {		/* collect the non-pattern chars */
	    sp = (char *) form++;
	    while (*form && *form != '%')
		form += 1;
	    n = form - sp;
	    { if((endd-d) >= n) { switch(n) { default : memcpy((Void_t*)d,(Void_t*)sp,n); d += n; sp += n; break; case 7 : *d++ = *sp++; case 6 : *d++ = *sp++; case 5 : *d++ = *sp++; case 4 : *d++ = *sp++; case 3 : *d++ = *sp++; case 2 : *d++ = *sp++; case 1 : *d++ = *sp++; }; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfwrite(f,(Void_t*)sp,n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; } };
	    continue;
	} else
	    form += 1;

	flags = 0;
	size = width = precis = base = n_s = argp = -1;
	ssp = (_Sftable.sf_digits);
	endep = ep = ((char *)0);
	endsp = sp = buf + (sizeof(buf) - 1);
	t_str = ((char *)0);
	n_str = dot = 0;

      loop_flags:		/* LOOP FOR \0, %, FLAGS, WIDTH, PRECISION, BASE, TYPE */
	switch ((fmt = *form++)) {
	case '\0':
	    { if(d < endd) { *d++ = (unsigned char)'%'; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),_sfflsbuf(f,'%'))) >= 0 ? 1 : 0; (d = f->next, endd = f->endb); if(w < 0) goto done; } };
	    goto pop_fmt;
	case '%':
	    { if(d < endd) { *d++ = (unsigned char)'%'; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),_sfflsbuf(f,'%'))) >= 0 ? 1 : 0; (d = f->next, endd = f->endb); if(w < 0) goto done; } };
	    continue;

	case '(':		/* get the type enclosed in balanced parens */
	    t_str = (char *) form;
	    for (v = 1;;) {
		switch (*form++) {
		case 0:	/* not balancable, retract */
		    form = t_str;
		    t_str = ((char *)0);
		    n_str = 0;
		    goto loop_flags;
		case '(':	/* increasing nested level */
		    v += 1;
		    continue;
		case ')':	/* decreasing nested level */
		    if ((v -= 1) != 0)
			continue;
		    if (*t_str != '*')
			n_str = (form - 1) - t_str;
		    else {
			t_str = (*(_Sftable.sf_fmtintf)) (t_str + 1, &n);
			if (*t_str == '$') {
			    if (!fp && !(fp = (*(_Sftable.sf_fmtposf))
					 (f, oform, oargs, 0)))
				goto pop_fmt;
			    n = (n < 0 ? (argn += 1) : (argn = n) );
			} else
			    n = (-1 < 0 ? (argn += 1) : (argn = -1) );

			if (fp) {
			    t_str = fp[n].argv.s;
			    n_str = fp[n].ft.size;
			} else if (ft && ft->extf) {
			    ((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = 
 '('), (ft->size = 0), (ft->flags = (0&07777770)), (ft->width = 0), (ft->precis = 0), (ft->base = 0), (ft->t_str = ((char *)0)), (ft->n_str = 0) );
			    n = (*ft->extf)
				(f, (Void_t *) & argv, ft);
			    if (n < 0)
				goto pop_fmt;
			    if (!(ft->flags & 00400000))
				goto t_arg;
			    if ((t_str = argv.s) &&
				(n_str = (int) ft->size) < 0)
				n_str = strlen(t_str);
			} else {
			  t_arg:
			    if ((t_str = va_arg(args, char *)))
				 n_str = strlen(t_str);
			}
		    }
		    goto loop_flags;
		}
	    }

	case '-':
	    flags = (flags & ~00001000) | 00000100;
	    goto loop_flags;
	case '0':
	    if (!(flags & 00000100))
		flags |= 00001000;
	    goto loop_flags;
	case ' ':
	    if (!(flags & 00000200))
		flags |= 00000400;
	    goto loop_flags;
	case '+':
	    flags = (flags & ~00000400) | 00000200;
	    goto loop_flags;
	case '#':
	    flags |= 00002000;
	    goto loop_flags;
	case '\'':
	    ;
	    if (thousand)
		flags |= 00004000;
	    goto loop_flags;

	case '.':
	    dot += 1;
	    if (dot == 1) {	/* so base can be defined without setting precis */
		if (*form != '.')
		    precis = 0;
	    } else if (dot == 2) {
		base = 0;	/* for %s,%c */
		if (*form == 'c' || *form == 's')
		    goto loop_flags;
		if (*form && !isalnum(*form) &&
		    (form[1] == 'c' || form[1] == 's')) {
		    if (*form == '*')
			goto do_star;
		    else {
			base = *form++;
			goto loop_flags;
		    }
		}
	    }

	    if (isdigit(*form)) {
		fmt = *form++;
		goto dot_size;
	    } else if (*form != '*')
		goto loop_flags;
	  do_star:
	    form += 1;		/* fall thru for '*' */
	case '*':
	    form = (*(_Sftable.sf_fmtintf)) (form, &n);
	    if (*form == '$') {
		form += 1;
		if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 0)))
		    goto pop_fmt;
		n = (n < 0 ? (argn += 1) : (argn = n) );
	    } else
		n = (-1 < 0 ? (argn += 1) : (argn = -1) );

	    if (fp)
		v = fp[n].argv.i;
	    else if (ft && ft->extf) {
		((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = '.'), (ft->size = dot), (ft->flags = (0&07777770)), (ft->width = 0), (ft->precis = 0), (ft->base = 0), (ft->t_str = ((char *)0)), (ft->n_str = 
 0) );
		if ((*ft->extf) (f, (Void_t *) (&argv), ft) < 0)
		    goto pop_fmt;
		if (ft->flags & 00400000)
		    v = argv.i;
		else
		    v = (dot <= 2) ? va_arg(args, int) : 0;
	    } else
		v = dot <= 2 ? va_arg(args, int) : 0;
	    goto dot_set;

	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	  dot_size:
	    for (v = fmt - '0'; isdigit(*form); ++form)
		v = v * 10 + (*form - '0');
	    if (*form == '$') {
		form += 1;
		if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 0)))
		    goto pop_fmt;
		argp = v - 1;
		goto loop_flags;
	    }
	  dot_set:
	    if (dot == 0) {
		if ((width = v) < 0) {
		    width = -width;
		    flags = (flags & ~00001000) | 00000100;
		}
	    } else if (dot == 1)
		precis = v;
	    else if (dot == 2)
		base = v;
	    goto loop_flags;

	case 'I':		/* object length */
	    size = 0;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 02000000;
	    if (isdigit(*form)) {
		for (n = *form; isdigit(n); n = *++form)
		    size = size * 10 + (n - '0');
	    } else if (*form == '*') {
		form = (*(_Sftable.sf_fmtintf)) (form + 1, &n);
		if (*form == '$') {
		    form += 1;
		    if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 0)))
			goto pop_fmt;
		    n = (n < 0 ? (argn += 1) : (argn = n) );
		} else
		    n = (-1 < 0 ? (argn += 1) : (argn = -1) );

		if (fp)		/* use position list */
		    size = fp[n].argv.i;
		else if (ft && ft->extf) {
		    ((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = 'I'), (ft->size = sizeof(int)), (ft->flags = (0&07777770)), (ft->width = 0), (ft->precis = 0), (ft->base = 0), (ft->t_str = 
 ((char *)0)), (ft->n_str = 0) );
		    if ((*ft->extf) (f, (Void_t *) (&argv), ft) < 0)
			goto pop_fmt;
		    if (ft->flags & 00400000)
			size = argv.i;
		    else
			size = va_arg(args, int);
		} else
		    size = va_arg(args, int);
	    }
	    goto loop_flags;

	case 'l':
	    size = -1;
	    flags &= ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 );
	    if (*form == 'l') {
		form += 1;
		flags |= 00100000;
	    } else
		flags |= 00040000;
	    goto loop_flags;
	case 'h':
	    size = -1;
	    flags &= ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 );
	    if (*form == 'h') {
		form += 1;
		flags |= 00000010;
	    } else
		flags |= 00020000;
	    goto loop_flags;
	case 'L':
	    size = -1;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 00200000;
	    goto loop_flags;

	case 'j':
	    size = -1;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 04000000;
	    goto loop_flags;
	case 'z':
	    size = -1;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 00000040;
	    goto loop_flags;
	case 't':
	    size = -1;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 00000020;
	    goto loop_flags;
	}

	/* set the correct size */
	if (flags & ((00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 ) & ~02000000)) {
	    if (((_Sftable.sf_type)[fmt] & (001 | 002)) || fmt == 'n') {
		size = (flags & 00100000) ? sizeof(_ast_intmax_t) :
		    (flags & 00040000) ? sizeof(long) :
		    (flags & 00020000) ? sizeof(short) :
		    (flags & 00000010) ? sizeof(char) :
		    (flags & 04000000) ? sizeof(_ast_intmax_t) :
		    (flags & 00000020) ? sizeof(ptrdiff_t) :
		    (flags & 00000040) ? sizeof(size_t) : -1;
	    } else if ((_Sftable.sf_type)[fmt] & 004) {
		size = (flags & 00200000) ? sizeof(_ast_fltmax_t) :
		    (flags & (00040000 | 00100000)) ?
		    sizeof(double) : -1;
	    }
	}

	argp = (argp < 0 ? (argn += 1) : (argn = argp) );
	if (fp) {
	    if (ft && ft->extf && fp[argp].ft.fmt != fp[argp].fmt)
		fmt = fp[argp].ft.fmt;
	    argv = fp[argp].argv;
	    size = fp[argp].ft.size;
	} else if (ft && ft->extf) {	/* extended processing */
	    ((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = fmt), (ft->size = size), (ft->flags = (flags&07777770)), (ft->width = width), (ft->precis = precis), (ft->base = base), (ft->t_str = 
 t_str), (ft->n_str = n_str) );
	    ((n_output += d - f->next), (f->next = d));
	    (void)((0) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );
	    v = (*ft->extf) (f, (Void_t *) (&argv), ft);
	    (void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);
	    (d = f->next, endd = f->endb);

	    if (v < 0)
		goto pop_fmt;
	    else if (v == 0) {	/* extf did not output */
		((form = ft->form), va_copy(args,ft->args), (fmt = ft->fmt), (size = ft->size), (flags = (flags&~(07777770))|(ft->flags&07777770)), (width = ft->width), (precis = ft->precis), (
 base = ft->base) );
		if (!(ft->flags & 00400000))
		    goto get_val;
	    } else if (v > 0) {	/* extf output v bytes */
		n_output += v;
		continue;
	    }
	} else {
	  get_val:
	    switch ((_Sftable.sf_type)[fmt]) {
	    case 001:
	    case 002:

		if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) ))
		    argv.ll = va_arg(args, _ast_intmax_t);
		else

		if ((size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) ))
		     argv.l = va_arg(args, long);
		else
		    argv.i = va_arg(args, int);
		break;
	    case 004:

		if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
		    argv.ld = va_arg(args, _ast_fltmax_t);
		else

		    argv.d = va_arg(args, double);
		break;
	    case 020:
		argv.vp = va_arg(args, Void_t *);
		break;
	    case 010:
		if (base >= 0)
		    argv.s = va_arg(args, char *);
		else
		    argv.c = (char) va_arg(args, int);
		break;
	    default:		/* unknown pattern */
		break;
	    }
	}

	switch (fmt) {		/* PRINTF DIRECTIVES */
	default:		/* unknown directive */
	    form -= 1;
	    argn -= 1;
	    continue;

	case '!':		/* stacking a new environment */
	    if (!fp)
		fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 0);
	    else
		goto pop_fmt;

	    if (!argv.ft)
		goto pop_fmt;
	    if (!argv.ft->form && ft) {	/* change extension functions */
		if (ft->eventf &&
		    (*ft->eventf) (f, 6, (Void_t *) form, ft) < 0)
		    continue;
		fmstk->ft = ft = argv.ft;
	    } else {		/* stack a new environment */
		if (!(fm = (Fmt_t *) malloc(sizeof(Fmt_t))))
		    goto done;

		if (argv.ft->form) {
		    fm->form = (char *) form;
		    va_copy(fm->args, args);

		    fm->oform = oform;
		    va_copy(fm->oargs, oargs);
		    fm->argn = argn;
		    fm->fp = fp;

		    form = argv.ft->form;
		    va_copy(args, argv.ft->args);
		    argn = -1;
		    fp = ((Fmtpos_t *)0);
		} else
		    fm->form = ((char *)0);

		fm->eventf = argv.ft->eventf;
		fm->ft = ft;
		fm->next = fmstk;
		fmstk = fm;
		ft = argv.ft;
	    }
	    continue;

	case 's':
	    if (base >= 0) {	/* list of strings */
		if (!(ls = argv.sp) || !ls[0])
		    continue;
	    } else {
		if (!(sp = argv.s))
		    sp = "(null)";
		ls = tls;
		tls[0] = sp;
	    }
	    for (sp = *ls;;) {
		if ((v = size) >= 0) {
		    if (precis >= 0 && v > precis)
			v = precis;
		} else if (precis < 0)
		    v = strlen(sp);
		else {		/* precis >= 0 means min(strlen,precis) */
		    for (v = 0; v < precis; ++v)
			if (sp[v] == 0)
			    break;
		}
		if ((n = width - v) > 0) {
		    if (flags & 00001000) {
			{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)'0'; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,'0',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
		    } else if (!(flags & 00000100)) {
			{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)' '; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,' ',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
		    }
		}
		{ if((endd-d) >= v) { switch(v) { default : memcpy((Void_t*)d,(Void_t*)sp,v); d += v; sp += v; break; case 7 : *d++ = *sp++; case 6 : *d++ = *sp++; case 5 : *d++ = *sp++; case 4 : *d++ = *sp++; case 3 : *d++ = *sp++; case 2 : *d++ = *sp++; case 1 : *d++ = *sp++; }; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfwrite(f,(Void_t*)sp,v))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(v != w) goto done; } };
		if (n > 0) {
		    { if((endd-d) >= n) { while(n--) *d++ = (unsigned char)' '; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,' ',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
		}
		if (!(sp = *++ls))
		    break;
		else if (base > 0) {
		    { if(d < endd) { *d++ = (unsigned char)base; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),_sfflsbuf(f,base))) >= 0 ? 1 : 0; (d = f->next, endd = f->endb); if(w < 0) goto done; } };
		}
	    }
	    continue;

	case 'c':		/* an array of characters */
	    if (base >= 0) {
		if (!(sp = argv.s) || !sp[0])
		    continue;
	    } else {
		fmt = (int) argv.c;
		sp = buf;
		buf[0] = fmt;
		buf[1] = 0;
	    }
	    if (precis <= 0)
		precis = 1;
	    for (fmt = *sp;;) {
		if ((n = width - precis) > 0 && !(flags & 00000100)) {
		{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)' '; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,' ',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } }};
		v = precis;
		{ if((endd-d) >= v) { while(v--) *d++ = (unsigned char)fmt; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,fmt,v))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(v != w) goto done; v = 0; } };
		if (n > 0) {
		{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)' '; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,' ',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } }};
		if (!(fmt = *++sp))
		    break;
		else if (base > 0) {
		    { if(d < endd) { *d++ = (unsigned char)base; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),_sfflsbuf(f,base))) >= 0 ? 1 : 0; (d = f->next, endd = f->endb); if(w < 0) goto done; } };
		}
	    }
	    continue;

	case 'n':		/* return current output length */
	    ((n_output += d - f->next), (f->next = d));

	    if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) ))
		*((_ast_intmax_t *) argv.vp) = (_ast_intmax_t) n_output;
	    else

	    if ((size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) ))
		*((long *) argv.vp) = (long) n_output;
	    else if (sizeof(short) < sizeof(int) &&
		     (size == sizeof(short) || (size == 0 && sizeof(short) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(short)*8) ))
		*((short *) argv.vp) = (short) n_output;
	    else if (size == sizeof(char))
		*((char *) argv.vp) = (char) n_output;
	    else
		*((int *) argv.vp) = (int) n_output;

	    continue;

	case 'p':		/* pointer value */
	    fmt = 'x';
	    base = 16;
	    n_s = 15;
	    n = 4;
	    flags =
		(flags & ~(00000200 | 00000400 | 00001000)) |
		00002000;

	    
	    

	    v = (int) ((unsigned int) argv.vp);
	    goto int_cvt;

	case 'o':
	    base = 8;
	    n_s = 7;
	    n = 3;
	    flags &= ~(00000200 | 00000400);
	    goto int_arg;
	case 'X':
	    ssp = "0123456789ABCDEF";
	case 'x':
	    base = 16;
	    n_s = 15;
	    n = 4;
	    flags &= ~(00000200 | 00000400);
	    goto int_arg;
	case 'i':
	    fmt = 'd';
	    goto d_format;
	case 'u':
	    flags &= ~(00000200 | 00000400);
	case 'd':
	  d_format:
	    if (base < 2 || base > 64)
		base = 10;
	    if ((base & (n_s = base - 1)) == 0) {
		if (base < 8)
		    n = base < 4 ? 1 : 2;
		else if (base < 32)
		    n = base < 16 ? 3 : 4;
		else
		    n = base < 64 ? 5 : 6;
	    } else
		n_s = base == 10 ? -1 : 0;

	  int_arg:

	    if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) )) {
		lv = argv.ll;
		goto long_cvt;
	    } else if ((size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) )) {
		if (fmt == 'd')
		    lv = (_ast_intmax_t) argv.l;
		else
		    lv = (_ast_intmax_t) ((unsigned long) argv.l);
	      long_cvt:
		if (lv == 0 && precis == 0)
		    break;
		if (lv < 0 && fmt == 'd') {
		    flags |= 02000000000;
		    if (lv == (~((~((unsigned _ast_intmax_t)0)) >> 1))) {	/* avoid overflow */
			lv = (_ast_intmax_t) ((~((~((unsigned _ast_intmax_t)0)) >> 1)) / base);
			*--sp = (_Sftable.sf_digits)[(~((~((unsigned _ast_intmax_t)0)) >> 1)) -
					  ((unsigned _ast_intmax_t) lv) * base];
		    } else
			lv = -lv;
		}
		if (n_s < 0) {	/* base 10 */
		    register _ast_intmax_t nv;
		    { while((unsigned _ast_intmax_t)lv >= 10000) { nv = lv; lv = (_ast_intmax_t)(((unsigned _ast_intmax_t)lv)/10000); nv = (_ast_intmax_t)((unsigned _ast_intmax_t)nv - ((unsigned _ast_intmax_t)lv)*10000); sp -= 4; { if(nv < 5*1000) if(nv < 2*1000) if(nv < 1*1000) { sp[0] = '0'; } else { sp[0] = '1'; nv -= 1*1000; } else if(nv < 3*1000) { sp[0] = '2'; nv -= 2*1000; } else if(nv < 4*1000) { sp[0] = '3'; nv -= 3*1000; } else { sp[0] = '4'; nv -= 4*1000; } else if(nv < 7*1000) if(nv < 6*1000) { sp[0] = '5'; nv -= 5*1000; } else { sp[0] = '6'; nv -= 6*1000; } else if(nv < 8*1000) { sp[0] = '7'; nv -= 7*1000; } else if(nv < 9*1000) { sp[0] = '8'; nv -= 8*1000; } else { sp[0] = '9'; nv -= 9*1000; } }; { if(nv < 5*100) if(nv < 2*100) if(nv < 1*100) { sp[1] = '0'; } else { sp[1] = '1'; nv -= 1*100; } else if(nv < 3*100) { sp[1] = '2'; nv -= 2*100; } else if(nv < 4*100) { sp[1] = '3'; nv -= 3*100; } else { sp[1] = '4'; nv -= 4*100; } else if(nv < 7*100) if(nv < 6*100) { sp[1] = '5'; nv -= 5*100; } else { sp[1] = '6'; nv -= 6*100; } else if(nv < 8*100) { sp[1] = '7'; nv -= 7*100; } else if(nv < 9*100) { sp[1] = '8'; nv -= 8*100; } else { sp[1] = '9'; nv -= 9*100; } }; sp[2] = *(ssp = (char*)(_Sftable.sf_dec) + (nv <<= 1)); sp[3] = *(ssp+1); } if(lv < 100) { if(lv < 10) { sp -= 1; sp[0] = (char)('0'+lv); } else { sp -= 2; sp[0] = *(ssp = (char*)(_Sftable.sf_dec) + (lv <<= 1)); sp[1] = *(ssp+1); } } else { if(lv < 1000) { sp -= 3; { if(lv < 5*100) if(lv < 2*100) if(lv < 1*100) { sp[0] = '0'; } else { sp[0] = '1'; lv -= 1*100; } else if(lv < 3*100) { sp[0] = '2'; lv -= 2*100; } else if(lv < 4*100) { sp[0] = '3'; lv -= 3*100; } else { sp[0] = '4'; lv -= 4*100; } else if(lv < 7*100) if(lv < 6*100) { sp[0] = '5'; lv -= 5*100; } else { sp[0] = '6'; lv -= 6*100; } else if(lv < 8*100) { sp[0] = '7'; lv -= 7*100; } else if(lv < 9*100) { sp[0] = '8'; lv -= 8*100; } else { sp[0] = '9'; lv -= 9*100; } }; sp[1] = *(ssp = (char*)(_Sftable.sf_dec) + (lv <<= 1)); sp[2] = *(ssp+1); } else { sp -= 4; { if(lv < 5*1000) if(lv < 2*1000) if(lv < 1*1000) { sp[0] = '0'; } else { sp[0] = '1'; lv -= 1*1000; } else if(lv < 3*1000) { sp[0] = '2'; lv -= 2*1000; } else if(lv < 4*1000) { sp[0] = '3'; lv -= 3*1000; } else { sp[0] = '4'; lv -= 4*1000; } else if(lv < 7*1000) if(lv < 6*1000) { sp[0] = '5'; lv -= 5*1000; } else { sp[0] = '6'; lv -= 6*1000; } else if(lv < 8*1000) { sp[0] = '7'; lv -= 7*1000; } else if(lv < 9*1000) { sp[0] = '8'; lv -= 8*1000; } else { sp[0] = '9'; lv -= 9*1000; } }; { if(lv < 5*100) if(lv < 2*100) if(lv < 1*100) { sp[1] = '0'; } else { sp[1] = '1'; lv -= 1*100; } else if(lv < 3*100) { sp[1] = '2'; lv -= 2*100; } else if(lv < 4*100) { sp[1] = '3'; lv -= 3*100; } else { sp[1] = '4'; lv -= 4*100; } else if(lv < 7*100) if(lv < 6*100) { sp[1] = '5'; lv -= 5*100; } else { sp[1] = '6'; lv -= 6*100; } else if(lv < 8*100) { sp[1] = '7'; lv -= 7*100; } else if(lv < 9*100) { sp[1] = '8'; lv -= 8*100; } else { sp[1] = '9'; lv -= 9*100; } }; sp[2] = *(ssp = (char*)(_Sftable.sf_dec) + (lv <<= 1)); sp[3] = *(ssp+1); } } };
		} else if (n_s > 0) {	/* base power-of-2 */
		    do {
			*--sp = ssp[lv & n_s];
		    } while ((lv = ((unsigned _ast_intmax_t) lv) >> n));
		} else {	/* general base */
		    do {
			*--sp = ssp[((unsigned _ast_intmax_t) lv) % base];
		    } while ((lv = ((unsigned _ast_intmax_t) lv) / base));
		}
	    } else

	    if (sizeof(short) < sizeof(int)
		    && (size == sizeof(short) || (size == 0 && sizeof(short) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(short)*8) )) {
		if (ft && ft->extf && (ft->flags & 00400000)) {
		    if (fmt == 'd')
			v = (int) ((short) argv.h);
		    else
			v = (int) ((unsigned short) argv.h);
		} else {
		    if (fmt == 'd')
			v = (int) ((short) argv.i);
		    else
			v = (int) ((unsigned short) argv.i);
		}
		goto int_cvt;
	    } else if (size == sizeof(char)) {
		if (ft && ft->extf && (ft->flags & 00400000)) {
		    if (fmt == 'd')
			v = (int) ((char) argv.c);
		    else
			v = (int) ((unsigned char) argv.c);
		} else {
		    if (fmt == 'd')
			v = (int) ((char) argv.i);
		    else
			v = (int) ((unsigned char) argv.i);
		}
		goto int_cvt;
	    } else {
		v = argv.i;
	      int_cvt:
		if (v == 0 && precis == 0)
		    break;
		if (v < 0 && fmt == 'd') {
		    flags |= 02000000000;
		    if (v == (~((~((unsigned int)0)) >> 1))) {	/* avoid overflow */
			v = (int) ((~((~((unsigned int)0)) >> 1)) / base);
			*--sp = (_Sftable.sf_digits)[(~((~((unsigned int)0)) >> 1)) - ((unsigned int) v) * base];
		    } else
			v = -v;
		}
		if (n_s < 0) {	/* base 10 */
		    { while((unsigned int)v >= 10000) { n = v; v = (int)(((unsigned int)v)/10000); n = (int)((unsigned int)n - ((unsigned int)v)*10000); sp -= 4; { if(n < 5*1000) if(n < 2*1000) if(n < 1*1000) { sp[0] = '0'; } else { sp[0] = '1'; n -= 1*1000; } else if(n < 3*1000) { sp[0] = '2'; n -= 2*1000; } else if(n < 4*1000) { sp[0] = '3'; n -= 3*1000; } else { sp[0] = '4'; n -= 4*1000; } else if(n < 7*1000) if(n < 6*1000) { sp[0] = '5'; n -= 5*1000; } else { sp[0] = '6'; n -= 6*1000; } else if(n < 8*1000) { sp[0] = '7'; n -= 7*1000; } else if(n < 9*1000) { sp[0] = '8'; n -= 8*1000; } else { sp[0] = '9'; n -= 9*1000; } }; { if(n < 5*100) if(n < 2*100) if(n < 1*100) { sp[1] = '0'; } else { sp[1] = '1'; n -= 1*100; } else if(n < 3*100) { sp[1] = '2'; n -= 2*100; } else if(n < 4*100) { sp[1] = '3'; n -= 3*100; } else { sp[1] = '4'; n -= 4*100; } else if(n < 7*100) if(n < 6*100) { sp[1] = '5'; n -= 5*100; } else { sp[1] = '6'; n -= 6*100; } else if(n < 8*100) { sp[1] = '7'; n -= 7*100; } else if(n < 9*100) { sp[1] = '8'; n -= 8*100; } else { sp[1] = '9'; n -= 9*100; } }; sp[2] = *(ssp = (char*)(_Sftable.sf_dec) + (n <<= 1)); sp[3] = *(ssp+1); } if(v < 100) { if(v < 10) { sp -= 1; sp[0] = (char)('0'+v); } else { sp -= 2; sp[0] = *(ssp = (char*)(_Sftable.sf_dec) + (v <<= 1)); sp[1] = *(ssp+1); } } else { if(v < 1000) { sp -= 3; { if(v < 5*100) if(v < 2*100) if(v < 1*100) { sp[0] = '0'; } else { sp[0] = '1'; v -= 1*100; } else if(v < 3*100) { sp[0] = '2'; v -= 2*100; } else if(v < 4*100) { sp[0] = '3'; v -= 3*100; } else { sp[0] = '4'; v -= 4*100; } else if(v < 7*100) if(v < 6*100) { sp[0] = '5'; v -= 5*100; } else { sp[0] = '6'; v -= 6*100; } else if(v < 8*100) { sp[0] = '7'; v -= 7*100; } else if(v < 9*100) { sp[0] = '8'; v -= 8*100; } else { sp[0] = '9'; v -= 9*100; } }; sp[1] = *(ssp = (char*)(_Sftable.sf_dec) + (v <<= 1)); sp[2] = *(ssp+1); } else { sp -= 4; { if(v < 5*1000) if(v < 2*1000) if(v < 1*1000) { sp[0] = '0'; } else { sp[0] = '1'; v -= 1*1000; } else if(v < 3*1000) { sp[0] = '2'; v -= 2*1000; } else if(v < 4*1000) { sp[0] = '3'; v -= 3*1000; } else { sp[0] = '4'; v -= 4*1000; } else if(v < 7*1000) if(v < 6*1000) { sp[0] = '5'; v -= 5*1000; } else { sp[0] = '6'; v -= 6*1000; } else if(v < 8*1000) { sp[0] = '7'; v -= 7*1000; } else if(v < 9*1000) { sp[0] = '8'; v -= 8*1000; } else { sp[0] = '9'; v -= 9*1000; } }; { if(v < 5*100) if(v < 2*100) if(v < 1*100) { sp[1] = '0'; } else { sp[1] = '1'; v -= 1*100; } else if(v < 3*100) { sp[1] = '2'; v -= 2*100; } else if(v < 4*100) { sp[1] = '3'; v -= 3*100; } else { sp[1] = '4'; v -= 4*100; } else if(v < 7*100) if(v < 6*100) { sp[1] = '5'; v -= 5*100; } else { sp[1] = '6'; v -= 6*100; } else if(v < 8*100) { sp[1] = '7'; v -= 7*100; } else if(v < 9*100) { sp[1] = '8'; v -= 8*100; } else { sp[1] = '9'; v -= 9*100; } }; sp[2] = *(ssp = (char*)(_Sftable.sf_dec) + (v <<= 1)); sp[3] = *(ssp+1); } } };
		} else if (n_s > 0) {	/* base power-of-2 */
		    do {
			*--sp = ssp[v & n_s];
		    } while ((v = ((unsigned int) v) >> n));
		} else {	/* n_s == 0, general base */
		    do {
			*--sp = ssp[((unsigned int) v) % base];
		    } while ((v = ((unsigned int) v) / base));
		}
	    }

	    if (n_s < 0 && (flags & 00004000)
		&& (n = endsp - sp) > 3) {
		if ((n %= 3) == 0)
		    n = 3;
		for (ep = buf + 1024, endep = ep + n;;) {
		    while (ep < endep)
			*ep++ = *sp++;
		    if (sp == endsp)
			break;
		    if (sp <= endsp - 3)
			*ep++ = thousand;
		    endep = ep + 3;
		}
		sp = buf + 1024;
		endsp = ep;
	    }

	    /* zero padding for precision if have room in buffer */
	    if (precis > 0 && (precis -= (endsp - sp)) < (sp - buf) - 64)
		while (precis-- > 0)
		    *--sp = '0';

	    if (flags & 00002000) {	/* prefix */
		if (fmt == 'o') {
		    if (*sp != '0')
			*--sp = '0';
		} else {
		    if (width > 0 && (flags & 00001000)) {	/* do 0 padding first */
			if (fmt == 'x' || fmt == 'X')
			    n = 0;
			else if (dot < 2)
			    n = width;
			else
			    n = base < 10 ? 2 : 3;
			n += (flags & (02000000000 | 00000200)) ? 1 : 0;
			n = width - (n + (endsp - sp));
			while (n-- > 0)
			    *--sp = '0';
		    }
		    if (fmt == 'x' || fmt == 'X') {
			*--sp = (char) fmt;
			*--sp = '0';
		    } else if (dot >= 2) {	/* base#value notation */
			*--sp = '#';
			if (base < 10)
			    *--sp = (char) ('0' + base);
			else {
			    *--sp = (_Sftable.sf_dec)[(base <<= 1) + 1];
			    *--sp = (_Sftable.sf_dec)[base];
			}
		    }
		}
	    }

	    break;

	case 'g':
	case 'G':		/* these ultimately become %e or %f */
	case 'e':
	case 'E':
	case 'f':

	    if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
		ldval = argv.ld;
	    else

	    if (!(ft && ft->extf && (ft->flags & 00400000)) ||
		    (size == sizeof(double) || (size == 0 && sizeof(double) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(double)*8) ))
		 dval = argv.d;
	    else
		dval = (double) argv.f;

	    if (fmt == 'e' || fmt == 'E') {
		n = (precis = precis < 0 ? 6 : precis) + 1;

		if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) )) {
		    ep = _sfcvt(&ldval, ((n) < (1024) ? (n) : (1024)),
				&decpt, &sign,
				01000000000 | 00200000);
		} else

		{
		    ep = _sfcvt(&dval, ((n) < (1024) ? (n) : (1024)),
				&decpt, &sign, 01000000000);
		}
		goto e_format;
	    } else if (fmt == 'f' || fmt == 'F') {
		precis = precis < 0 ? 6 : precis;

		if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) )) {
		    ep = _sfcvt(&ldval, ((precis) < (1024) ? (precis) : (1024)),
				&decpt, &sign, 00200000);
		} else

		{
		    ep = _sfcvt(&dval, ((precis) < (1024) ? (precis) : (1024)),
				&decpt, &sign, 0);
		}
		goto f_format;
	    }

	    /* 'g' or 'G' format */
	    precis = precis < 0 ? 6 : precis == 0 ? 1 : precis;

	    if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) )) {
		ep = _sfcvt(&ldval, ((precis) < (1024) ? (precis) : (1024)),
			    &decpt, &sign, 01000000000 | 00200000);
		if (ldval == 0.)
		    decpt = 1;
		else if (*ep == 'I')
		    goto infinite;
	    } else

	    {
		ep = _sfcvt(&dval, ((precis) < (1024) ? (precis) : (1024)),
			    &decpt, &sign, 01000000000);
		if (dval == 0.)
		    decpt = 1;
		else if (*ep == 'I')
		    goto infinite;
	    }

	    if (!(flags & 00002000)) {	/* zap trailing 0s */
		if ((n = ( (_Sfi) )) > precis)
		    n = precis;
		while ((n -= 1) >= 1 && ep[n] == '0');
		n += 1;
	    } else
		n = precis;

	    if (decpt < -3 || decpt > precis) {
		precis = n - 1;
		goto e_format;
	    } else {
		precis = n - decpt;
		goto f_format;
	    }

	  e_format:		/* build the x.yyyy string */
	    if (isalpha(*ep))
		goto infinite;
	    sp = endsp = buf + 1;	/* reserve space for sign */
	    *endsp++ = *ep ? *ep++ : '0';

	    ;
	    if (precis > 0 || (flags & 00002000))
		*endsp++ = decimal;
	    ssp = endsp;
	    endep = ep + precis;
	    while ((*endsp++ = *ep++) && ep <= endep);
	    precis -= (endsp -= 1) - ssp;

	    /* build the exponent */
	    ep = endep = buf + (sizeof(buf) - 1);

	    if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
		dval = ldval ? 1. : 0.;	/* so the below test works */

	    if (dval != 0.) {
		if ((n = decpt - 1) < 0)
		    n = -n;
		while (n > 9) {
		    v = n;
		    n /= 10;
		    *--ep = (char) ('0' + (v - n * 10));
		}
	    } else
		n = 0;
	    *--ep = (char) ('0' + n);
	    if (endep - ep <= 1)	/* at least 2 digits */
		*--ep = '0';

	    /* the e/Exponent separator and sign */
	    *--ep = (decpt > 0 || dval == 0.) ? '+' : '-';
	    *--ep = isupper(fmt) ? 'E' : 'e';

	    goto end_efg;

	  f_format:		/* data before the decimal point */
	    if (isalpha(*ep)) {
	      infinite:
		endsp = (sp = ep) + ( (_Sfi) );
		ep = endep;
		precis = 0;
		goto end_efg;
	    }

	    ;
	    endsp = sp = buf + 1;	/* save a space for sign */
	    endep = ep + decpt;
	    if (decpt > 3 && (flags & 00004000)) {
		if ((n = decpt % 3) == 0)
		    n = 3;
		while (ep < endep && (*endsp++ = *ep++)) {
		    if (--n == 0 && (ep <= endep - 3)) {
			*endsp++ = thousand;
			n = 3;
		    }
		}
	    } else {
		while (ep < endep && (*endsp++ = *ep++));
	    }
	    if (endsp == sp)
		*endsp++ = '0';

	    if (precis > 0 || (flags & 00002000))
		*endsp++ = decimal;

	    if ((n = -decpt) > 0) {	/* output zeros for negative exponent */
		ssp = endsp + ((n) < (precis) ? (n) : (precis));
		precis -= n;
		while (endsp < ssp)
		    *endsp++ = '0';
	    }

	    ssp = endsp;
	    endep = ep + precis;
	    while ((*endsp++ = *ep++) && ep <= endep);
	    precis -= (endsp -= 1) - ssp;
	    ep = endep;
	  end_efg:
	    flags |= 004;
	    if (sign)
		flags |= 02000000000;
	    break;
	}

	if (flags == 0 && width <= 0)
	    goto do_output;

	if (flags & (02000000000|00000200|00000400))
	    fmt =
		(flags & 02000000000) ? '-' : (flags & 00000200) ? '+' :
		' ';

	n = (endsp - sp) + (endep - ep) + (precis <= 0 ? 0 : precis) +
	    ((flags & (02000000000|00000200|00000400)) ? 1 : 0);
	if ((v = width - n) <= 0)
	    v = 0;
	else if (!(flags & 00001000)) {	/* right padding */
	    if (flags & 00000100)
		v = -v;
	    else if (flags & (02000000000|00000200|00000400)) {	/* blank padding, output prefix now */
		*--sp = fmt;
		flags &= ~(02000000000|00000200|00000400);
	    }
	}

	if (flags & (02000000000|00000200|00000400)) {	/* put out the prefix */
	    { if(d < endd) { *d++ = (unsigned char)fmt; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),_sfflsbuf(f,fmt))) >= 0 ? 1 : 0; (d = f->next, endd = f->endb); if(w < 0) goto done; } };
	    if (fmt != ' ')
		flags |= 00001000;
	}

	if ((n = v) > 0) {	/* left padding */
	    v = (flags & 00001000) ? '0' : ' ';
	    { if((endd-d) >= n) { while(n--) *d++ = (unsigned char)v; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,v,n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
	}

	if ((n = precis) > 0 && !(flags & 004)) {	/* padding for integer precision */
	    { if((endd-d) >= n) { while(n--) *d++ = (unsigned char)'0'; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,'0',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
	    precis = 0;
	}

      do_output:
	if ((n = endsp - sp) > 0)
	    { if((endd-d) >= n) { switch(n) { default : memcpy((Void_t*)d,(Void_t*)sp,n); d += n; sp += n; break; case 7 : *d++ = *sp++; case 6 : *d++ = *sp++; case 5 : *d++ = *sp++; case 4 : *d++ = *sp++; case 3 : *d++ = *sp++; case 2 : *d++ = *sp++; case 1 : *d++ = *sp++; }; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfwrite(f,(Void_t*)sp,n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; } };

	if (flags & (004 | 00000100)) {	/* SFFMT_FLOAT: right padding for float precision */
	    if ((n = precis) > 0)
		{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)'0'; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,'0',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };

	    /* SFFMT_FLOAT: the exponent of %eE */
	    if ((n = endep - (sp = ep)) > 0)
		{ if((endd-d) >= n) { switch(n) { default : memcpy((Void_t*)d,(Void_t*)sp,n); d += n; sp += n; break; case 7 : *d++ = *sp++; case 6 : *d++ = *sp++; case 5 : *d++ = *sp++; case 4 : *d++ = *sp++; case 3 : *d++ = *sp++; case 2 : *d++ = *sp++; case 1 : *d++ = *sp++; }; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfwrite(f,(Void_t*)sp,n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; } };

	    /* SFFMT_LEFT: right padding */
	    if ((n = -v) > 0)
		{ if((endd-d) >= n) { while(n--) *d++ = (unsigned char)' '; } else { ((n_output += d - f->next), (f->next = d)); n_output += (w = (((f)->mode |= 00100000),sfnputc(f,' ',n))) > 0 ? w : 0; (d = f->next, endd = f->endb); if(n != w) goto done; n = 0; } };
	}
    }

  pop_fmt:
    if (fp) {
	free(fp);
	fp = ((Fmtpos_t *)0);
    }
    while ((fm = fmstk)) {	/* pop the format stack and continue */
	if (fm->eventf) {
	    if (!form || !form[0])
		(*fm->eventf) (f, 11, ((Void_t *)0), ft);
	    else if ((*fm->eventf) (f, 6, (Void_t *) form, ft) < 0)
		goto loop_fmt;
	}

	fmstk = fm->next;
	if ((form = fm->form)) {
	    va_copy(args, fm->args);
	    oform = fm->oform;
	    va_copy(oargs, fm->oargs);
	    argn = fm->argn;
	    fp = fm->fp;
	}
	ft = fm->ft;
	free(fm);
	if (form && form[0])
	    goto loop_fmt;
    }

  done:
    if (fp)
	free(fp);
    while ((fm = fmstk)) {
	if (fm->eventf)
	    (*fm->eventf) (f, 11, ((Void_t *)0), fm->ft);
	fmstk = fm->next;
	free(fm);
    }

    ((n_output += d - f->next), (f->next = d));

    n = f->next - f->data;
    if ((d = f->data) == (unsigned char *) data)
	f->endw = f->endr = f->endb = f->data = ((unsigned char *)0);
    f->next = f->data;

    if ((((flags = f->flags) & 0000100) && !(flags & 0004000)) ||
	(n > 0 && (d == (unsigned char *) data || (flags & 0000040))))
	(void) (((f)->mode |= 00100000),sfwrite(f,(Void_t *) d,n));
    else
	f->next += n;

    (void)((0) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );
    { return(n_output); };
}
