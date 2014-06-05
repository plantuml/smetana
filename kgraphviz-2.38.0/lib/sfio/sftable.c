#line 1 "graphviz-2.38.0\\lib\\sfio\\sftable.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\sfio\\sftable.c" 2

/*	Dealing with $ argument addressing stuffs.
**
**	Written by Kiem-Phong Vo.
*/


static char *sffmtint(const char *str, int *v)





{
    for (*v = 0; isdigit(*str); ++str)
	*v = *v * 10 + (*str - '0');
    *v -= 1;
    return (char *) str;
}


static Fmtpos_t *sffmtpos(Sfio_t * f, const char *form, va_list args,
			  int type)







{
    int base, fmt, flags, dot, width, precis;
    ssize_t n_str, size = 0;
    char *t_str, *sp;
    int v, n, skip, dollar, decimal, thousand;
    Sffmt_t *ft, savft;
    Fmtpos_t *fp;		/* position array of arguments  */
    int argp, argn, maxp, need[5];

    if (type < 0)
	fp = ((Fmtpos_t *)0);
    else if (!(fp = sffmtpos(f, form, args, -1)))
	return ((Fmtpos_t *)0);

    dollar = decimal = thousand = 0;
    argn = maxp = -1;
    while ((n = *form)) {
	if (n != '%') {		/* collect the non-pattern chars */
	    sp = (char *) form++;
	    while (*form && *form != '%')
		form += 1;
	    continue;
	} else
	    form += 1;
	if (*form == 0)
	    break;
	else if (*form == '%') {
	    form += 1;
	    continue;
	}

	if (*form == '*' && type > 0) {	/* skip in scanning */
	    skip = 1;
	    form += 1;
	    argp = -1;
	} else {		/* get the position of this argument */
	    skip = 0;
	    sp = sffmtint(form, &argp);
	    if (*sp == '$') {
		dollar = 1;
		form = sp + 1;
	    } else
		argp = -1;
	}

	flags = dot = 0;
	t_str = ((char *)0);
	n_str = 0;
	size = width = precis = base = -1;
	for (n = 0; n < 5; ++n)
	    need[n] = -1;

      loop_flags:		/* LOOP FOR \0, %, FLAGS, WIDTH, PRECISION, BASE, TYPE */
	switch ((fmt = *form++)) {
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
		    n_str = form - t_str;
		    if (*t_str == '*') {
			t_str = sffmtint(t_str + 1, &n);
			if (*t_str == '$')
			    dollar = 1;
			else
			    n = -1;
			if ((n = (n < 0 ? (argn += 1) : (argn = n) )) > maxp)
			    maxp = n;
			if (fp && fp[n].ft.fmt == 0) {
			    fp[n].ft.fmt = '(';
			    fp[n].ft.form = (char *) form;
			}
			need[3] = n;
		    }
		    goto loop_flags;
		}
	    }

	case '-':
	    flags |= 00000100;
	    flags &= ~00001000;
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
	    flags |= 00000200;
	    flags &= ~00000400;
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
	    if ((dot += 1) == 2)
		base = 0;	/* for %s,%c */
	    if (isdigit(*form)) {
		fmt = *form++;
		goto dot_size;
	    } else if (*form != '*')
		goto loop_flags;
	    else
		form += 1;	/* drop thru below */

	case '*':
	    form = sffmtint(form, &n);
	    if (*form == '$') {
		dollar = 1;
		form += 1;
	    } else
		n = -1;
	    if ((n = (n < 0 ? (argn += 1) : (argn = n) )) > maxp)
		maxp = n;
	    if (fp && fp[n].ft.fmt == 0) {
		fp[n].ft.fmt = '.';
		fp[n].ft.size = dot;
		fp[n].ft.form = (char *) form;
	    }
	    if (dot <= 2)
		need[dot] = n;
	    goto loop_flags;

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
	    for (v = fmt - '0', fmt = *form; isdigit(fmt); fmt = *++form)
		v = v * 10 + (fmt - '0');
	    if (dot == 0)
		width = v;
	    else if (dot == 1)
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
		form = sffmtint(form + 1, &n);
		if (*form == '$') {
		    dollar = 1;
		    form += 1;
		} else
		    n = -1;
		if ((n = (n < 0 ? (argn += 1) : (argn = n) )) > maxp)
		    maxp = n;
		if (fp && fp[n].ft.fmt == 0) {
		    fp[n].ft.fmt = 'I';
		    fp[n].ft.size = sizeof(int);
		    fp[n].ft.form = (char *) form;
		}
		need[4] = n;
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
	}

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

	if (skip)
	    continue;

	if ((argp = (argp < 0 ? (argn += 1) : (argn = argp) )) > maxp)
	    maxp = argp;

	if (dollar && fmt == '!')
	    return ((Fmtpos_t *)0);

	if (fp && fp[argp].ft.fmt == 0) {
	    fp[argp].ft.form = (char *) form;
	    fp[argp].ft.fmt = fp[argp].fmt = fmt;
	    fp[argp].ft.size = size;
	    fp[argp].ft.flags = flags;
	    fp[argp].ft.width = width;
	    fp[argp].ft.precis = precis;
	    fp[argp].ft.base = base;
	    fp[argp].ft.t_str = t_str;
	    fp[argp].ft.n_str = n_str;
	    for (n = 0; n < 5; ++n)
		fp[argp].need[n] = need[n];
	}
    }

    if (!fp) {			/* constructing position array only */
	if (!dollar
	    || !(fp = (Fmtpos_t *) malloc((maxp + 1) * sizeof(Fmtpos_t))))
	    return ((Fmtpos_t *)0);
	for (n = 0; n <= maxp; ++n)
	    fp[n].ft.fmt = 0;
	return fp;
    }

    /* get value for positions */
    for (n = 0, ft = ((Sffmt_t *)0); n <= maxp; ++n) {
	if (fp[n].ft.fmt == 0) {	/* gap: pretend it's a 'd' pattern */
	    fp[n].ft.fmt = 'd';
	    fp[n].ft.width = 0;
	    fp[n].ft.precis = 0;
	    fp[n].ft.base = 0;
	    fp[n].ft.size = 0;
	    fp[n].ft.t_str = 0;
	    fp[n].ft.n_str = 0;
	    fp[n].ft.flags = 0;
	    for (v = 0; v < 5; ++v)
		fp[n].need[v] = -1;
	}

	if (ft && ft->extf) {
	    fp[n].ft.version = ft->version;
	    fp[n].ft.extf = ft->extf;
	    fp[n].ft.eventf = ft->eventf;
	    if ((v = fp[n].need[0]) >= 0 && v < n)
		fp[n].ft.width = fp[v].argv.i;
	    if ((v = fp[n].need[1]) >= 0 && v < n)
		fp[n].ft.precis = fp[v].argv.i;
	    if ((v = fp[n].need[2]) >= 0 && v < n)
		fp[n].ft.base = fp[v].argv.i;
	    if ((v = fp[n].need[3]) >= 0 && v < n)
		fp[n].ft.t_str = fp[v].argv.s;
	    if ((v = fp[n].need[4]) >= 0 && v < n)
		fp[n].ft.size = fp[v].argv.i;

	    memcpy(ft, &fp[n].ft, sizeof(Sffmt_t));
	    va_copy(ft->args, args);
	    ft->flags |= 01000000;
	    v = (*ft->extf) (f, (Void_t *) (&fp[n].argv), ft);
	    va_copy(args, ft->args);
	    memcpy(&fp[n].ft, ft, sizeof(Sffmt_t));
	    if (v < 0) {
		memcpy(ft, &savft, sizeof(Sffmt_t));
		ft = ((Sffmt_t *)0);
	    }

	    if (!(fp[n].ft.flags & 00400000))
		goto arg_list;
	} else {
	  arg_list:
	    if (fp[n].ft.fmt == '(') {
		fp[n].argv.s = va_arg(args, char *);
		fp[n].ft.size = strlen(fp[n].argv.s);
	    } else if (fp[n].ft.fmt == '.' || fp[n].ft.fmt == 'I')
		fp[n].argv.i = va_arg(args, int);
	    else if (fp[n].ft.fmt == '!') {
		if (ft)
		    memcpy(ft, &savft, sizeof(Sffmt_t));
		fp[n].argv.ft = ft = va_arg(args, Sffmt_t *);
		if (ft->form)
		    ft = ((Sffmt_t *)0);
		if (ft)
		    memcpy(&savft, ft, sizeof(Sffmt_t));
	    } else if (type > 0)	/* from sfvscanf */
		fp[n].argv.vp = va_arg(args, Void_t *);
	    else
		switch ((_Sftable.sf_type)[fp[n].ft.fmt]) {
		case 001:
		case 002:

		    if ((size == sizeof(_ast_intmax_t) || (size == 0 && sizeof(_ast_intmax_t) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(_ast_intmax_t)*8) ))
			fp[n].argv.ll = va_arg(args, _ast_intmax_t);
		    else

		    if ((size == sizeof(long) || (size == 0 && sizeof(long) == sizeof(_ast_intmax_t)) || (size == 64 && size == sizeof(long)*8) ))
			 fp[n].argv.l = va_arg(args, long);
		    else
			fp[n].argv.i = va_arg(args, int);
		    break;
		case 004:

		    if ((size == sizeof(_ast_fltmax_t) || (size == 0 && sizeof(_ast_fltmax_t) == sizeof(_ast_fltmax_t)) || (size == 64 && size == sizeof(_ast_fltmax_t)*8) ))
			fp[n].argv.ld = va_arg(args, _ast_fltmax_t);
		    else

			fp[n].argv.d = va_arg(args, double);
		    break;
		case 020:
		    fp[n].argv.vp = va_arg(args, Void_t *);
		    break;
		case 010:
		    if (fp[n].ft.base >= 0)
			fp[n].argv.s = va_arg(args, char *);
		    else
			fp[n].argv.c = (char) va_arg(args, int);
		    break;
		default:	/* unknown pattern */
		    break;
		}
	}
    }

    if (ft)
	memcpy(ft, &savft, sizeof(Sffmt_t));
    return fp;
}


/* function to initialize conversion tables */
static int sfcvinit(void)
{
    register int d, l;

    for (d = 0; d <= ((unsigned char)(~0)); ++d) {
	(_Sftable.sf_cv36)[d] = 64;
	(_Sftable.sf_cv64)[d] = 64;
    }

    /* [0-9] */
    for (d = 0; d < 10; ++d) {
	(_Sftable.sf_cv36)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
	(_Sftable.sf_cv64)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
    }

    /* [a-z] */
    for (; d < 36; ++d) {
	(_Sftable.sf_cv36)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
	(_Sftable.sf_cv64)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
    }

    /* [A-Z] */
    for (l = 10; d < 62; ++l, ++d) {
	(_Sftable.sf_cv36)[(unsigned char) (_Sftable.sf_digits)[d]] = l;
	(_Sftable.sf_cv64)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
    }

    /* remaining digits */
    for (; d < 64; ++d) {
	(_Sftable.sf_cv36)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
	(_Sftable.sf_cv64)[(unsigned char) (_Sftable.sf_digits)[d]] = d;
    }

    (_Sftable.sf_type)['d'] = (_Sftable.sf_type)['i'] = 001;
    (_Sftable.sf_type)['u'] = (_Sftable.sf_type)['o'] = (_Sftable.sf_type)['x'] = (_Sftable.sf_type)['X'] = 002;
    (_Sftable.sf_type)['e'] = (_Sftable.sf_type)['E'] =
	(_Sftable.sf_type)['g'] = (_Sftable.sf_type)['G'] = (_Sftable.sf_type)['f'] = 004;
    (_Sftable.sf_type)['s'] = (_Sftable.sf_type)['n'] = (_Sftable.sf_type)['p'] = (_Sftable.sf_type)['!'] =
	020;
    (_Sftable.sf_type)['c'] = 010;
    (_Sftable.sf_type)['['] = 040;

    return 1;
}

/* table for floating point and integer conversions */
Sftab_t _Sftable = {
    {1e1, 1e2, 1e4, 1e8, 1e16, 1e32}
    ,				/* _Sfpos10     */

    {1e-1, 1e-2, 1e-4, 1e-8, 1e-16, 1e-32}
    ,				/* _Sfneg10     */

    {'0', '0', '0', '1', '0', '2', '0', '3', '0', '4',	/* _Sfdec       */
     '0', '5', '0', '6', '0', '7', '0', '8', '0', '9',
     '1', '0', '1', '1', '1', '2', '1', '3', '1', '4',
     '1', '5', '1', '6', '1', '7', '1', '8', '1', '9',
     '2', '0', '2', '1', '2', '2', '2', '3', '2', '4',
     '2', '5', '2', '6', '2', '7', '2', '8', '2', '9',
     '3', '0', '3', '1', '3', '2', '3', '3', '3', '4',
     '3', '5', '3', '6', '3', '7', '3', '8', '3', '9',
     '4', '0', '4', '1', '4', '2', '4', '3', '4', '4',
     '4', '5', '4', '6', '4', '7', '4', '8', '4', '9',
     '5', '0', '5', '1', '5', '2', '5', '3', '5', '4',
     '5', '5', '5', '6', '5', '7', '5', '8', '5', '9',
     '6', '0', '6', '1', '6', '2', '6', '3', '6', '4',
     '6', '5', '6', '6', '6', '7', '6', '8', '6', '9',
     '7', '0', '7', '1', '7', '2', '7', '3', '7', '4',
     '7', '5', '7', '6', '7', '7', '7', '8', '7', '9',
     '8', '0', '8', '1', '8', '2', '8', '3', '8', '4',
     '8', '5', '8', '6', '8', '7', '8', '8', '8', '9',
     '9', '0', '9', '1', '9', '2', '9', '3', '9', '4',
     '9', '5', '9', '6', '9', '7', '9', '8', '9', '9',
     }
    ,

    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@_",

    sfcvinit, 0,
    sffmtpos,
    sffmtint
};
