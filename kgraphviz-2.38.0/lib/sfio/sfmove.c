#line 1 "graphviz-2.38.0\\lib\\sfio\\sfmove.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\sfio\\sfmove.c" 2

/*	Move data from one stream to another.
**	This code is written so that it'll work even in the presence
**	of stacking streams, pool, and discipline.
**	If you must change it, be gentle.
**
**	Written by Kiem-Phong Vo.
*/



_ast_intmax_t sfmove(Sfio_t * fr, Sfio_t * fw, _ast_intmax_t n, register int rc)







{
    register unsigned char *cp, *next;
    register ssize_t r, w;
    register unsigned char *endb;
    register int direct;
    _ast_intmax_t n_move;
    unsigned char *rbuf = ((unsigned char *)0);
    ssize_t rsize = 0;

    { if(!fr) return((_ast_intmax_t) 0); };
    if (fw)
	(void)(0);

    for (n_move = 0; n != 0;) {	/* get the streams into the right mode */
	if (fr->mode != 0000001 && _sfmode(fr, 0000001, 0) < 0)
	    goto done;

	(void)((fr)->mode |= 00000040, (fr)->endr = (fr)->endw = (fr)->data);

	/* flush the write buffer as necessary to make room */
	if (fw) {
	    if (fw->mode != 0000002 && _sfmode(fw, 0000002, 0) < 0)
		break;
	    (void)((fw)->mode |= 00000040, (fw)->endr = (fw)->endw = (fw)->data);
	    if (fw->next >= fw->endb ||
		(fw->next > fw->data && fr->extent < 0 &&
		 (fw->extent < 0 || (fw->flags & 0000100))))
		if ((((fw)->mode |= 00100000),_sfflsbuf(fw,-1)) < 0)
		    break;
	}

	/* about to move all, set map to a large amount */
	if (n < 0 && (fr->bits & 00000001) && !(fr->bits & 00002000)) {
	    (((fr)->size *= 8), ((fr)->bits |= 00002000) );

	    if (rc < 0)		/* data will be accessed sequentially */
		fr->bits |= 00000020;
	}

	/* try reading a block of data */
	direct = 0;
	if ((r = fr->endb - (next = fr->next)) <= 0) {	/* amount of data remained to be read */
	    if ((w = n > ((ssize_t)((~((size_t)0)) >> 1)) ? ((ssize_t)((~((size_t)0)) >> 1)) : (ssize_t) n) < 0) {
		if (fr->extent < 0)
		    w = fr->data == fr->tiny ? 1024 : fr->size;
		else if ((fr->extent - fr->here) > 8 * ((ssize_t)(1024*sizeof(int)*2)))
		    w = 8 * ((ssize_t)(1024*sizeof(int)*2));
		else
		    w = (ssize_t) (fr->extent - fr->here);
	    }

	    /* use a decent buffer for data transfer but make sure
	       that if we overread, the left over can be retrieved
	     */
	    if (!(fr->flags & 0000004) && !(fr->bits & 00000001) &&
		(n < 0 || fr->extent >= 0)) {
		register ssize_t maxw = 4 * ((_Sfextern.sf_page) > 0 ? (_Sfextern.sf_page) : ((ssize_t)(1024*sizeof(int)*2)));

		/* direct transfer to a seekable write stream */
		if (fw && fw->extent >= 0 && w <= (fw->endb - fw->next)) {
		    w = fw->endb - (next = fw->next);
		    direct = 0000002;
		} else if (w > fr->size && maxw > fr->size) {	/* making our own buffer */
		    if (w >= maxw)
			w = maxw;
		    else
			w = ((w + fr->size - 1) / fr->size) * fr->size;
		    if (rsize <= 0 && (rbuf = (unsigned char *) malloc(w)))
			rsize = w;
		    if (rbuf) {
			next = rbuf;
			w = rsize;
			direct = 0000004;
		    }
		}
	    }

	    if (!direct) {	/* make sure we don't read too far ahead */
		if (n > 0 && fr->extent < 0 && (fr->flags & 0000100)) {
		    if (rc >= 0) {	/* try peeking a large buffer */
			fr->mode |= 00000020;
			if ((r = (((fr)->mode |= 00100000),_sffilbuf(fr,-1))) > 0)
			    goto done_filbuf;
			else if (n > 1 && !fr->disc) {
			    r = sfpkrd(fr->file,
				       (Void_t *) fr->data,
				       fr->size, rc, -1, (int) (-n));
			    if (r <= 0)
				goto one_r;
			    fr->next = fr->data;
			    fr->endb = fr->endr = fr->next + r;
			    goto done_filbuf;
			} else {	/* get a single record */
			  one_r:fr->getr = rc;
			    fr->mode |= 00000010;
			    r = -1;
			}
		    } else if ((_ast_intmax_t) (r = fr->size) > n)
			r = (ssize_t) n;
		} else
		    r = -1;
		if ((r = (((fr)->mode |= 00100000),_sffilbuf(fr,r))) <= 0)
		    break;
	      done_filbuf:
		next = fr->next;
	    } else {		/* actual amount to be read */
		if (rc < 0 && n > 0 && n < w)
		    w = (ssize_t) n;

		if ((r = (((fr)->mode |= 00100000),sfrd(fr,(Void_t*)next,w,fr->disc))) > 0)
		    fr->next = fr->endb = fr->endr = fr->data;
		else if (r == 0)
		    break;	/* eof */
		else
		    goto again;	/* popped stack */
	    }
	}

	/* compute the extent of data to be moved */
	endb = next + r;
	if (rc < 0) {
	    if (n > 0) {
		if (r > n)
		    r = (ssize_t) n;
		n -= r;
	    }
	    n_move += r;
	    cp = next + r;
	} else {		/* count records */
	    register int rdwr = (fr->flags & 0000020) ||
		(fr->bits & (00000002 | 00000001));
	    if (rdwr) {
		w = endb[-1];
		endb[-1] = rc;
	    } else
		w = 0;
	    for (cp = next; cp < endb;) {	/* find the line extent */
		if (rdwr)
		    while (*cp++ != rc);
		else
		    while (r-- && *cp++ != rc);
		if (cp < endb || w == rc) {
		    n_move += 1;
		    if (n > 0 && (n -= 1) == 0)
			break;
		}
	    }
	    if (rdwr)
		endb[-1] = w;
	    r = cp - next;
	    if (fr->mode & 00001000) {	/* advance the read point by proper amount */
		fr->mode &= ~00001000;
		(void) read(fr->file, (Void_t *) next, r);
		fr->here += r;
		if (!direct)
		    fr->endb = cp;
		else
		    endb = cp;
	    }
	}

	if (!direct)
	    fr->next += r;
	else if ((w = endb - cp) > 0) {	/* move left-over to read stream */
	    if (w > fr->size)
		w = fr->size;
	    memcpy((Void_t *) fr->data, (Void_t *) cp, w);
	    fr->endb = fr->data + w;
	    if ((w = endb - (cp + w)) > 0)
		(void) (((fr)->mode |= 00100000),sfsk(fr,(_ast_intmax_t)(_ast_intmax_t)(-w),1,fr->disc));
	}

	if (fw) {
	    if (direct == 0000002)
		fw->next += r;
	    else if (r <= (fw->endb - fw->next)) {
		memcpy((Void_t *) fw->next, (Void_t *) next, r);
		fw->next += r;
	    } else if ((w = (((fw)->mode |= 00100000),sfwrite(fw,(Void_t *) next,r))) != r) {	/* a write error happened */
		if (w > 0) {
		    r -= w;
		    if (rc < 0)
			n_move -= r;
		}
		if (fr->extent >= 0)
		    (void) (((fr)->mode |= 00100000),sfseek(fr,(_ast_intmax_t)(-r),1));
		break;
	    }
	}

      again:
	(void)((0) ? 0 : ((fr)->mode &= ~(00000040|00000010|00000020), ((fr)->mode == 0000001 ? ((fr)->endr = ((fr)->flags&0) ? (fr)->data : (fr)->endb) : (fr)->mode == 0000002 ? ((fr)->endw = ((fr)->flags&(0|0000040)) ? (fr)->data : (fr)->endb) : ((fr)->endw = (fr)->endr = (fr)->data) ), 0) );
	if (fw)
	    (void)((0) ? 0 : ((fw)->mode &= ~(00000040|00000010|00000020), ((fw)->mode == 0000001 ? ((fw)->endr = ((fw)->flags&0) ? (fw)->data : (fw)->endb) : (fw)->mode == 0000002 ? ((fw)->endw = ((fw)->flags&(0|0000040)) ? (fw)->data : (fw)->endb) : ((fw)->endw = (fw)->endr = (fw)->data) ), 0) );
    }

  done:
    if (n < 0 && (fr->bits & 00000001) && (fr->bits & 00002000)) {	/* back to normal access mode */
	(!((fr)->bits&00002000) ? 0 : (((fr)->bits &= ~00002000), ((fr)->size /= 8)) );
	if ((fr->bits & 00000020) && (fr->data))
	    ;
	fr->bits &= ~00000020;
    }

    if (rbuf)
	free(rbuf);

    (void)((0) ? 0 : ((fr)->mode &= ~(00000040|00000010|00000020), ((fr)->mode == 0000001 ? ((fr)->endr = ((fr)->flags&0) ? (fr)->data : (fr)->endb) : (fr)->mode == 0000002 ? ((fr)->endw = ((fr)->flags&(0|0000040)) ? (fr)->data : (fr)->endb) : ((fr)->endw = (fr)->endr = (fr)->data) ), 0) );
    if (fw) {
	(void)((0) ? 0 : ((fw)->mode &= ~(00000040|00000010|00000020), ((fw)->mode == 0000001 ? ((fw)->endr = ((fw)->flags&0) ? (fw)->data : (fw)->endb) : (fw)->mode == 0000002 ? ((fw)->endw = ((fw)->flags&(0|0000040)) ? (fw)->data : (fw)->endb) : ((fw)->endw = (fw)->endr = (fw)->data) ), 0) );
	(void)(0);
    }

    { return(n_move); };
}
