#line 1 "graphviz-2.38.0\\lib\\sfio\\sfvscanf.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\sfio\\sfvscanf.c" 2

/*	The main engine for reading formatted data
**
**	Written by Kiem-Phong Vo.
*/




static char *setclass(register char *form, register char *accept)





{
    register int fmt, c, yes;

    if ((fmt = *form++) == '^') {	/* we want the complement of this set */
	yes = 0;
	fmt = *form++;
    } else
	yes = 1;

    for (c = 0; c <= ((unsigned char)(~0)); ++c)
	accept[c] = !yes;

    if (fmt == ']' || fmt == '-') {	/* special first char */
	accept[fmt] = yes;
	fmt = *form++;
    }

    for (; fmt != ']'; fmt = *form++) {	/* done */
	if (!fmt)
	    return (form - 1);

	/* interval */
	if (fmt != '-' || form[0] == ']' || form[-2] > form[0])
	    accept[fmt] = yes;
	else
	    for (c = form[-2] + 1; c < form[0]; ++c)
		accept[c] = yes;
    }

    return form;
}


static void _sfbuf(Sfio_t * f, int *rs)





{
    if (f->next >= f->endb) {
	if (*rs > 0) {		/* try peeking for a share stream if possible */
	    f->mode |= 00000020;
	    if ((((f)->mode |= 00100000),_sffilbuf(f,-1)) > 0) {
		f->mode |= 00000400;
		return;
	    }
	    *rs = -1;		/* can't peek, back to normal reads */
	}
	(void) (((f)->mode |= 00100000),_sffilbuf(f,-1));
    }
}


int sfvscanf(Sfio_t * f, register const char *form, va_list args)






{
    register unsigned char *d, *endd, *data;
    register int inp, shift, base, width;
    ssize_t size;
    int fmt, flags, dot, n_assign, v, n, n_input;
    char *sp;
    char accept[(((1024+(8*1024))/sizeof(int) + 1)*sizeof(int))];

    Argv_t argv;
    Sffmt_t *ft;
    Fmt_t *fm, *fmstk;

    Fmtpos_t *fp;
    char *oform;
    va_list oargs;
    int argp, argn;

    Void_t *value;		/* location to assign scanned value */
    char *t_str;
    ssize_t n_str;
    int rs;









    { if(!f) return(-1); };

    if (!form)
	{ return(-1); };

    if (f->mode != 0000001 && _sfmode(f, 0000001, 0) < 0)
	{ return(-1); };
    (void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);

    rs = (f->extent < 0 && (f->flags & 0000100)) ? 1 : 0;

    ((_Sftable.sf_cvinit) ? 1 : ((_Sftable.sf_cvinit) = (*(_Sftable.sf_cvinitf))()) );			/* initialize conversion tables */

    (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) );
    n_assign = n_input = 0;

    inp = -1;

    fmstk = ((Fmt_t *)0);
    ft = ((Sffmt_t *)0);

    fp = ((Fmtpos_t *)0);
    argn = -1;
    oform = (char *) form;
    va_copy(oargs, args);

  loop_fmt:
    while ((fmt = *form++)) {
	if (fmt != '%') {
	    if (isspace(fmt)) {
		if (fmt != '\n' || !(f->flags & 0000040))
		    fmt = -1;
		for (;;) {
		    if (((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) < 0 || inp == fmt)
			goto loop_fmt;
		    else if (!isspace(inp)) {
			(--d);
			goto loop_fmt;
		    }
		}
	    } else {
	      match_1:
		if (((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) != fmt) {
		    if (inp >= 0)
			(--d);
		    goto pop_fmt;
		}
	    }
	    continue;
	}

	if (*form == '%') {
	    form += 1;
	    goto match_1;
	}

	if (*form == '\0')
	    goto pop_fmt;

	if (*form == '*') {
	    flags = 00010000;
	    form += 1;
	} else
	    flags = 0;

	/* matching some pattern */
	base = 10;
	size = -1;
	width = dot = 0;
	t_str = ((char *)0);
	n_str = 0;
	value = ((Void_t *)0);
	argp = -1;

      loop_flags:		/* LOOP FOR FLAGS, WIDTH, BASE, TYPE */
	switch ((fmt = *form++)) {
	case '(':		/* get the type which is enclosed in balanced () */
	    t_str = (char *) form;
	    for (v = 1;;) {
		switch (*form++) {
		case 0:	/* not balanceable, retract */
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
					 (f, oform, oargs, 1)))
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

	case '#':		/* alternative format */
	    flags |= 00002000;
	    goto loop_flags;

	case '.':		/* width & base */
	    dot += 1;
	    if (isdigit(*form)) {
		fmt = *form++;
		goto dot_size;
	    } else if (*form == '*') {
		form = (*(_Sftable.sf_fmtintf)) (form + 1, &n);
		if (*form == '$') {
		    form += 1;
		    if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 1)))
			goto pop_fmt;
		    n = (n < 0 ? (argn += 1) : (argn = n) );
		} else
		    n = (-1 < 0 ? (argn += 1) : (argn = -1) );

		if (fp)
		    v = fp[n].argv.i;
		else if (ft && ft->extf) {
		    ((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = '.'), (ft->size = dot), (ft->flags = (0&07777770)), (ft->width = 0), (ft->precis = 0), (ft->base = 0), (ft->t_str = 
 ((char *)0)), (ft->n_str = 0) );
		    if ((*ft->extf) (f, (Void_t *) (&argv), ft) < 0)
			goto pop_fmt;
		    if (ft->flags & 00400000)
			v = argv.i;
		    else
			v = (dot <= 2) ? va_arg(args, int) : 0;
		} else
		    v = (dot <= 2) ? va_arg(args, int) : 0;
		if (v < 0)
		    v = 0;
		goto dot_set;
	    } else
		goto loop_flags;

	case '0':
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
		if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 1)))
		    goto pop_fmt;
		argp = v - 1;
		goto loop_flags;
	    }

	  dot_set:
	    if (dot == 0 || dot == 1)
		width = v;
	    else if (dot == 2)
		base = v;
	    goto loop_flags;

	case 'I':		/* object size */
	    size = 0;
	    flags = (flags & ~(00020000|00000010 | 00040000|00100000| 00200000 | 02000000|04000000| 00000020 | 00000040 )) | 02000000;
	    if (isdigit(*form)) {
		for (n = *form; isdigit(n); n = *++form)
		    size = size * 10 + (n - '0');
	    } else if (*form == '*') {
		form = (*(_Sftable.sf_fmtintf)) (form + 1, &n);
		if (*form == '$') {
		    form += 1;
		    if (!fp && !(fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 1)))
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

	/* set object size */
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
	    if (!(fp[argp].ft.flags & 00010000)) {
		n_assign += 1;
		value = fp[argp].argv.vp;
		size = fp[argp].ft.size;
		if (ft && ft->extf && fp[argp].ft.fmt != fp[argp].fmt)
		    fmt = fp[argp].ft.fmt;
	    } else
		flags |= 00010000;
	} else if (ft && ft->extf) {
	    ((ft->form = (char*)form), va_copy(ft->args,args), (ft->fmt = fmt), (ft->size = size), (ft->flags = (flags&07777770)), (ft->width = width), (ft->precis = 0), (ft->base = base), (ft->t_str = t_str), (ft->n_str = 
 n_str) );
	    ((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) );
	    (void)((0) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );
	    v = (*ft->extf) (f, (Void_t *) & argv, ft);
	    (void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);
	    (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) );

	    if (v < 0)
		goto pop_fmt;
	    else if (v == 0) {	/* extf did not use input stream */
		((form = ft->form), va_copy(args,ft->args), (fmt = ft->fmt), (size = ft->size), (flags = (flags&~(07777770))|(ft->flags&07777770)), (width = ft->width), (n = ft->precis), (base = ft->base) );
		if ((ft->flags & 00400000) && !(ft->flags & 00010000))
		    value = argv.vp;
	    } else {		/* v > 0: number of input bytes consumed */
		n_input += v;
		if (!(ft->flags & 00010000))
		    n_assign += 1;
		continue;
	    }
	}

	if ((_Sftable.sf_type)[fmt] == 0)	/* unknown pattern */
	    continue;

	if (fmt == '!') {
	    if (!fp)
		fp = (*(_Sftable.sf_fmtposf)) (f, oform, oargs, 1);
	    else
		goto pop_fmt;

	    if (!(argv.ft = va_arg(args, Sffmt_t *)))
		continue;
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
	}

	/* get the address to assign value */
	if (!value && !(flags & 00010000))
	    value = va_arg(args, Void_t *);

	if (fmt == 'n') {	/* return length of consumed input */

	    if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) ))
		*((_ast_intmax_t *) value) = (_ast_intmax_t) (n_input + (d-data));
	    else

	    if (sizeof(long) > sizeof(int) && (size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) ))
		*((long *) value) = (long) (n_input + (d-data));
	    else if (sizeof(short) < sizeof(int) &&
		     (size == sizeof(short) || (size == 0 && sizeof(short) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(short)*8) ))
		*((short *) value) = (short) (n_input + (d-data));
	    else if (size == sizeof(char))
		*((char *) value) = (char) (n_input + (d-data));
	    else
		*((int *) value) = (int) (n_input + (d-data));
	    continue;
	}

	/* if get here, start scanning input */
	if (width == 0)
	    width = fmt == 'c' ? 1 : (int)(((unsigned int)~0)>>1);

	/* define the first input character */
	if (fmt == 'c' || fmt == '[')
	    ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 );
	else {
	    do {
		((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 );
	    }
	    while (isspace(inp))	/* skip starting blanks */
	    ;
	}
	if (inp < 0)
	    goto done;

	if ((_Sftable.sf_type)[fmt] == 004) {
	    register char *val;
	    register int dot, exponent;

	    val = accept;
	    if (width >= (((1024+(8*1024))/sizeof(int) + 1)*sizeof(int)))
		width = (((1024+(8*1024))/sizeof(int) + 1)*sizeof(int)) - 1;
	    dot = exponent = 0;
	    do {
		if (isdigit(inp))
		    *val++ = inp;
		else if (inp == '.') {	/* too many dots */
		    if (dot++ > 0)
			break;
		    *val++ = '.';
		} else if (inp == 'e' || inp == 'E') {	/* too many e,E */
		    if (exponent++ > 0)
			break;
		    *val++ = inp;
		    if (--width <= 0 || ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) < 0 ||
			(inp != '-' && inp != '+' && !isdigit(inp)))
			break;
		    *val++ = inp;
		} else if (inp == '-' || inp == '+') {	/* too many signs */
		    if (val > accept)
			break;
		    *val++ = inp;
		} else
		    break;

	    } while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0);

	    if (value) {
		*val = '\0';

		if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
		    argv.ld = _sfstrtod(accept, ((char **)0));
		else

		    argv.d = (double) _sfstrtod(accept, ((char **)0));
	    }

	    if (value) {
		n_assign += 1;

		if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
		    *((_ast_fltmax_t *) value) = argv.ld;
		else

		if ((size == sizeof(double) || (size == 0 && sizeof(double) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(double)*8) ))
		    *((double *) value) = argv.d;
		else
		    *((float *) value) = (float) argv.d;
	    }
	} else if ((_Sftable.sf_type)[fmt] == 002 || fmt == 'p') {
	    if (inp == '-') {
		(--d);
		goto pop_fmt;
	    } else
		goto int_cvt;
	} else if ((_Sftable.sf_type)[fmt] == 001) {
	  int_cvt:
	    if (inp == '-' || inp == '+') {
		if (inp == '-')
		    flags |= 02000000000;
		while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0)
		    if (!isspace(inp))
			break;
	    }
	    if (inp < 0)
		goto done;

	    if (fmt == 'o')
		base = 8;
	    else if (fmt == 'x' || fmt == 'p')
		base = 16;
	    else if (fmt == 'i' && inp == '0') {	/* self-described data */
		base = 8;
		if (width > 1) {	/* peek to see if it's a base-16 */
		    if (((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0) {
			if (inp == 'x' || inp == 'X')
			    base = 16;
			(--d);
		    }
		    inp = '0';
		}
	    }

	    /* now convert */
	    argv.lu = 0;
	    if (base == 16) {
		sp = (char *) (_Sftable.sf_cv36);
		shift = 4;
		if (sp[inp] >= 16) {
		    (--d);
		    goto pop_fmt;
		}
		if (inp == '0' && --width > 0) {	/* skip leading 0x or 0X */
		    if (((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0 &&
			(inp == 'x' || inp == 'X') && --width > 0)
			((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 );
		}
		if (inp >= 0 && sp[inp] < 16)
		    goto base_shift;
	    } else if (base == 10) {	/* fast base 10 conversion */
		if (inp < '0' || inp > '9') {
		    (--d);
		    goto pop_fmt;
		}

		do {
		    argv.lu =
			(argv.lu << 3) + (argv.lu << 1) + (inp - '0');
		} while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= '0'
			 && inp <= '9');

		if (fmt == 'i' && inp == '#' && !(flags & 00002000)) {
		    base = (int) argv.lu;
		    if (base < 2 || base > 64)
			goto pop_fmt;
		    argv.lu = 0;
		    sp = base <= 36 ? (char *) (_Sftable.sf_cv36) : (char *) (_Sftable.sf_cv64);
		    if (--width > 0 &&
			((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0 && sp[inp] < base)
			goto base_conv;
		}
	    } else {		/* other bases */
		sp = base <= 36 ? (char *) (_Sftable.sf_cv36) : (char *) (_Sftable.sf_cv64);
		if (base < 2 || base > 64 || sp[inp] >= base) {
		    (--d);
		    goto pop_fmt;
		}

	      base_conv:	/* check for power of 2 conversions */
		if ((base & ~(base - 1)) == base) {
		    if (base < 8)
			shift = base < 4 ? 1 : 2;
		    else if (base < 32)
			shift = base < 16 ? 3 : 4;
		    else
			shift = base < 64 ? 5 : 6;

		  base_shift:do {
			argv.lu = (argv.lu << shift) + sp[inp];
		    } while (--width > 0 &&
			     ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0 && sp[inp] < base);
		} else {
		    do {
			argv.lu = (argv.lu * base) + sp[inp];
		    } while (--width > 0 &&
			     ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0 && sp[inp] < base);
		}
	    }

	    if (flags & 02000000000)
		argv.ll = -argv.ll;

	    if (value) {
		n_assign += 1;

		if (fmt == 'p')

		    

		    *((Void_t **) value) = (Void_t *) ((unsigned int) argv.lu);


		else if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) ))
		    *((_ast_intmax_t *) value) = argv.ll;

		else if (sizeof(long) > sizeof(int) &&
			 (size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) )) {
		    if (fmt == 'd' || fmt == 'i')
			*((long *) value) = (long) argv.ll;
		    else
			*((unsigned long *) value) = (unsigned long) argv.lu;
		} else if (sizeof(short) < sizeof(int) &&
			   (size == sizeof(short) || (size == 0 && sizeof(short) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(short)*8) )) {
		    if (fmt == 'd' || fmt == 'i')
			*((short *) value) = (short) argv.ll;
		    else
			*((unsigned short *) value) = (unsigned short) argv.lu;
		} else if (size == sizeof(char)) {
		    if (fmt == 'd' || fmt == 'i')
			*((char *) value) = (char) argv.ll;
		    else
			*((unsigned char *) value) = (unsigned char) argv.lu;
		} else {
		    if (fmt == 'd' || fmt == 'i')
			*((int *) value) = (int) argv.ll;
		    else
			*((unsigned int *) value) = (unsigned int) argv.lu;
		}
	    }
	} else if (fmt == 's' || fmt == 'c' || fmt == '[') {
	    if (size < 0)
		size = (int)(((unsigned int)~0)>>1);
	    if (value) {
		argv.s = (char *) value;
		if (fmt != 'c')
		    size -= 1;
	    } else
		size = 0;

	    n = 0;
	    if (fmt == 's') {
		do {
		    if (isspace(inp))
			break;
		    if ((n += 1) <= size)
			*argv.s++ = inp;
		} while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0);
	    } else if (fmt == 'c') {
		do {
		    if ((n += 1) <= size)
			*argv.s++ = inp;
		} while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0);
	    } else {		/* if(fmt == '[') */
		form = setclass((char *) form, accept);
		do {
		    if (!accept[inp]) {
			if (n > 0 || (flags & 00002000))
			    break;
			else {
			    (--d);
			    goto pop_fmt;
			}
		    }
		    if ((n += 1) <= size)
			*argv.s++ = inp;
		} while (--width > 0 && ((inp) = (d < endd || (((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) ), (_sfbuf(f,&rs), (data = d = f->next), (endd = f->endb) ), d < endd)) ? (int)(*d++) : -1 ) >= 0);
	    }

	    if (value && (n > 0 || fmt == '[')) {
		n_assign += 1;
		if (fmt != 'c' && size >= 0)
		    *argv.s = '\0';
	    }
	}

	if (width > 0 && inp >= 0)
	    (--d);
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

    ((n_input += d-data), (rs > 0 ? (((f)->mode |= 00100000),sfread(f,(Void_t*)data,d-data)) : ((f->next = d), 0)) );
    (void)((0) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );

    if (n_assign == 0 && inp < 0)
	n_assign = -1;

    { return(n_assign); };
}
