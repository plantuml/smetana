#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmdebug.c" 1
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


#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmdebug.c" 1













#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmhdr.h" 1
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














/*	Common types, and macros for vmalloc functions.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/





    







    






#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmhdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmhdr.h" 1








    typedef unsigned char Vmuchar_t;
    typedef unsigned long Vmulong_t;

    typedef union _head_u Head_t;
    typedef union _body_u Body_t;
    typedef struct _block_s Block_t;
    typedef struct _seg_s Seg_t;
    typedef struct _pfobj_s Pfobj_t;









/* convert an address to an integral value */


/* Round x up to a multiple of y. ROUND2 does powers-of-2 and ROUNDX does others */




/* compute a value that is a common multiple of x and y */






    















/* Blocks are allocated such that their sizes are 0%(BITS+1)
** This frees up enough low order bits to store state information
*/


















/* these bits share the "mode" field with the public bits */





/* test/set/clear lock state */





/* local calls */





/* ALIGN is chosen so that a block can store all primitive types.
** It should also be a multiple of ALIGNB==(BITS+1) so the size field
** of Block_t will always be 0%(BITS+1) as noted above.
** Of paramount importance is the ALIGNA macro below. If the local compile
** environment is strange enough that the below method does not calculate
** ALIGNA right, then the code below should be commented out and ALIGNA
** redefined to the appropriate requirement.
*/
	union _align_u {
	char c, *cp;
	int i, *ip;
	long l, *lp;
	double d, *dp, ***dppp[8];
	size_t s, *sp;
	void (*fn) (void);
	union _align_u *align;
	Head_t *head;
	Body_t *body;
	Block_t *block;
	Vmuchar_t a[(8)];

	

    };
    struct _a_s {
	char c;
	union _align_u a;
    };

    struct _align_s {
	char data[(((sizeof(struct _a_s) - sizeof(union _align_u)))%((8)) == 0 ? ((sizeof(struct _a_s) - sizeof(union _align_u))) : ((8))%((sizeof(struct _a_s) - sizeof(union _align_u))) == 0 ? ((8)) : ((8))*((sizeof(struct _a_s) - sizeof(union _align_u))))];
    };


/* make sure that the head of a block is a multiple of ALIGN */
    struct _head_s {
	union {
	    Seg_t *seg;		/* the containing segment       */
	    Block_t *link;	/* possible link list usage     */
	    Pfobj_t *pf;	/* profile structure pointer    */
	    char *file;		/* for file name in Vmdebug     */
	} seg;
	union {
	    size_t size;	/* size of data area in bytes   */
	    Block_t *link;	/* possible link list usage     */
	    int line;		/* for line number in Vmdebug   */
	} size;
    };

    union _head_u {
	Vmuchar_t data[(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _head_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _head_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )];	/* to standardize size          */
	struct _head_s head;
    };

/* now make sure that the body of a block is a multiple of ALIGN */
    struct _body_s {
	Block_t *link;		/* next in link list            */
	Block_t *left;		/* left child in free tree      */
	Block_t *right;		/* right child in free tree     */
	Block_t **self;		/* self pointer when free       */
    };

    union _body_u {
	Vmuchar_t data[(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _body_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _body_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )];	/* to standardize size          */
	struct _body_s body;
    };

/* After all the songs and dances, we should now have:
**	sizeof(Head_t)%ALIGN == 0
**	sizeof(Body_t)%ALIGN == 0
** and	sizeof(Block_t) = sizeof(Head_t)+sizeof(Body_t)
*/
    struct _block_s {
	Head_t head;
	Body_t body;
    };

/* requirements for smallest block type */
    struct _tiny_s {
	Block_t *link;
	Block_t *self;
    };









/* number of small block types that can be cached after free */







    typedef struct _vmdata_s {
	int mode;		/* current mode for region              */
	size_t incr;		/* allocate in multiple of this         */
	size_t pool;		/* size of an elt in a Vmpool region    */
	Seg_t *seg;		/* list of segments                     */
	Block_t *free;		/* most recent free block               */
	Block_t *wild;		/* wilderness block                     */
	Block_t *root;		/* root of free tree                    */
	Block_t *tiny[7];	/* small blocks                         */
	Block_t *cache[7 + 1];	/* delayed free blocks                */
    } Vmdata_t;

/* private parts of Vmalloc_t */





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
    typedef Void_t *(*Vmemory_f)
	_ARG_((Vmalloc_t *, Void_t *, size_t, size_t, Vmdisc_t *));
    typedef int (*Vmexcept_f)
	_ARG_((Vmalloc_t *, int, Void_t *, Vmdisc_t *));

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
	Void_t *(*allocf) _ARG_((Vmalloc_t *, size_t));
	Void_t *(*resizef) _ARG_((Vmalloc_t *, Void_t *, size_t, int));
	int (*freef) _ARG_((Vmalloc_t *, Void_t *));
	long (*addrf) _ARG_((Vmalloc_t *, Void_t *));
	long (*sizef) _ARG_((Vmalloc_t *, Void_t *));
	int (*compactf) _ARG_((Vmalloc_t *));
	Void_t *(*alignf) _ARG_((Vmalloc_t *, size_t, size_t));
	unsigned short meth;
    };

    struct _vmalloc_s {
	Vmethod_t meth;		/* method for allocation        */
	char *file;		/* file name                    */
	int line;		/* line number                  */

	 Vmdisc_t* disc; Vmdata_t* data; Vmalloc_t* next;

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

     _END_EXTERNS_ 1	/* public functions */



     extern Vmalloc_t *vmopen _ARG_((Vmdisc_t *, Vmethod_t *, int));
    extern int vmclose _ARG_((Vmalloc_t *));
    extern int vmclear _ARG_((Vmalloc_t *));
    extern int vmcompact _ARG_((Vmalloc_t *));

    extern Vmdisc_t *vmdisc _ARG_((Vmalloc_t *, Vmdisc_t *));

    extern Void_t *vmalloc _ARG_((Vmalloc_t *, size_t));
    extern Void_t *vmalign _ARG_((Vmalloc_t *, size_t, size_t));
    extern Void_t *vmresize _ARG_((Vmalloc_t *, Void_t *, size_t, int));
    extern int vmfree _ARG_((Vmalloc_t *, Void_t *));

    extern long vmaddr _ARG_((Vmalloc_t *, Void_t *));
    extern long vmsize _ARG_((Vmalloc_t *, Void_t *));

    extern Vmalloc_t *vmregion _ARG_((Void_t *));
    extern Void_t *vmsegment _ARG_((Vmalloc_t *, Void_t *));
    extern int vmset _ARG_((Vmalloc_t *, int, int));

    extern Void_t *vmdbwatch _ARG_((Void_t *));
    extern int vmdbcheck _ARG_((Vmalloc_t *));

    extern int vmprofile _ARG_((Vmalloc_t *, int));

    extern int vmtrace _ARG_((int));
    extern int vmtrbusy _ARG_((Vmalloc_t *));

    extern int vmstat _ARG_((Vmalloc_t *, Vmstat_t *));

    extern int vmwalk _ARG_((Vmalloc_t *,
			     int (*)(Vmalloc_t *, Void_t *, size_t,
				     Vmdisc_t *)));
    extern char *vmstrdup _ARG_((Vmalloc_t *, const char *));




    extern Void_t *malloc _ARG_((size_t));
    extern Void_t *realloc _ARG_((Void_t *, size_t));
    extern void free _ARG_((Void_t *));
    extern void cfree _ARG_((Void_t *));
    extern Void_t *calloc _ARG_((size_t, size_t));
    extern Void_t *memalign _ARG_((size_t, size_t));
    extern Void_t *valloc _ARG_((size_t));



     _END_EXTERNS_
/* to coerce any value to a Vmalloc_t*, make ANSI happy */

/* enable recording of where a call originates from */


































/* non-debugging/profiling allocation calls */
























#line 224 "graphviz-2.38.0\\lib\\vmalloc\\vmhdr.h" 2

/* we don't use these here and they interfere with some local names */




/* segment structure */
    struct _seg_s {
	Vmalloc_t *vm;		/* the region that holds this   */
	Seg_t *next;		/* next segment                 */
	Void_t *addr;		/* starting segment address     */
	size_t extent;		/* extent of segment            */
	Vmuchar_t *baddr;	/* bottom of usable memory      */
	size_t size;		/* allocable size               */
	Block_t *free;		/* recent free blocks           */
	Block_t *last;		/* Vmlast last-allocated block  */
    };

/* starting block of a segment */


/* short-hands for block data */















/* functions to manipulate link lists of elts of the same size */






/* delete a block from a link list or the free tree.
** The test in the below macro is worth scratching your head a bit.
** Even though tiny blocks (size < BODYSIZE) are kept in separate lists,
** only the TINIEST ones require TLEFT(b) for the back link. Since this
** destroys the SEG(b) pointer, it must be carefully restored in bestsearch().
** Other tiny blocks have enough space to use the usual LEFT(b).
** In this case, I have also carefully arranged so that RIGHT(b) and
** SELF(b) can be overlapped and the test ISLINK() will go through.
*/




/* see if a block is the wilderness block */






/* The lay-out of a Vmprofile block is this:
**	seg_ size ----data---- _pf_ size
**	_________ ____________ _________
**	seg_, size: header required by Vmbest.
**	data:	actual data block.
**	_pf_:	pointer to the corresponding Pfobj_t struct
**	size:	the true size of the block.
** So each block requires an extra Head_t.
*/





/* The lay-out of a block allocated by Vmdebug is this:
**	seg_ size file size seg_ magi ----data---- --magi-- magi line
**	--------- --------- --------- ------------ -------- ---------
**	seg_,size: header required by Vmbest management.
**	file:	the file where it was created.
**	size:	the true byte count of the block
**	seg_:	should be the same as the previous seg_.
**		This allows the function vmregion() to work.
**	magi:	magic bytes to detect overwrites.
**	data:	the actual data block.
**	magi:	more magic bytes.
**	line:	the line number in the file where it was created.
** So for each allocated block, we'll need 3 extra Head_t.
*/

/* convenient macros for accessing the above fields */











/* forward/backward translation for addresses between Vmbest and Vmdebug */



/* set file and line number, note that DBLN > 0 so that DBISBAD will work  */


/* set and test the state of known to be corrupted */





/* compute the bounds of the magic areas */





/* clear and copy functions */























/* external symbols for internal use by vmalloc */
    typedef Block_t *(*Vmsearch_f) _ARG_((Vmdata_t *, size_t, Block_t *));
    typedef struct _vmextern_ {
	Block_t *(*vm_extend) _ARG_((Vmalloc_t *, size_t, Vmsearch_f));
	int (*vm_truncate) _ARG_((Vmalloc_t *, Seg_t *, size_t, int));
	size_t vm_pagesize;
	char *(*vm_strcpy) _ARG_((char *, char *, int));
	char *(*vm_itoa) _ARG_((Vmulong_t, int));
	void (*vm_trace) _ARG_((Vmalloc_t *,
				Vmuchar_t *, Vmuchar_t *, size_t, size_t));
	void (*vm_pfclose) _ARG_((Vmalloc_t *));
    } Vmextern_t;









     1 extern Vmextern_t _Vmextern;




    extern size_t getpagesize _ARG_((void));


    extern void abort _ARG_((void));
    extern ssize_t write _ARG_((int, const void *, size_t));



    extern size_t strlen _ARG_((const char *));
    extern char *strcpy _ARG_((char *, const char *));
    extern int strcmp _ARG_((const char *, const char *));
    extern int atexit _ARG_((void (*)(void)));
    extern char *getenv _ARG_((const char *));
    extern Void_t *memcpy _ARG_((Void_t *, const Void_t *, size_t));
    extern Void_t *memset _ARG_((Void_t *, int, size_t));









/* for malloc.c */

    extern int creat _ARG_((const char *, int));
    extern int close _ARG_((int));

    extern int getpid _ARG_((void));

/* for vmexit.c */

    extern int onexit _ARG_((void (*)(void)));
    extern void _exit _ARG_((int));

    extern void _cleanup _ARG_((void));



/* for vmdcsbrk.c */

    typedef int ssize_t;


    extern Vmuchar_t *sbrk _ARG_((ssize_t));


     _END_EXTERNS_




#line 20 "graphviz-2.38.0\\lib\\vmalloc\\vmdebug.c" 2

/*	Method to help with debugging. This does rigorous checks on
**	addresses and arena integrity.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/

/* structure to keep track of file names */
typedef struct _dbfile_s Dbfile_t;
struct _dbfile_s {
    Dbfile_t *next;
    char file[1];
};
static Dbfile_t *Dbfile;

/* global watch list */

static int Dbnwatch;
static Void_t *Dbwatch[32];

/* types of warnings reported by dbwarn() */







static int Dbinit = 0;

static void dbinit(void)
{
    int fd;
    if ((fd = vmtrace(-1)) >= 0)
	vmtrace(fd);
}

/* just an entry point to make it easy to set break point */

static void vmdbwarn(Vmalloc_t * vm, char *mesg, int n)






{
    register Vmdata_t *vd = vm->data;

    write(2, mesg, n);
    if (vd->mode & 0000010)
	abort();
}

/* issue a warning of some type */

static void dbwarn(Vmalloc_t * vm, Void_t * data, int where, char *file,
		   int line, int type)









{
    char buf[1024], *bufp, *endbuf, *s;


    (Dbinit ? 0 : (dbinit(), Dbinit=1) );

    bufp = buf;
    endbuf = buf + sizeof(buf);

    if (type == 1)
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "alloc error", ':');
    else if (type == 2)
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "free error", ':');
    else if (type == 3)
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "resize error", ':');
    else if (type == 0)
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "corrupted data", ':');
    else if (type == 4)
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "alert", ':');

    /* region info */
    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "region", '=');
    bufp = (*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(vm) - (char*)0) ), 0), ':');

    if (data) {
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "block", '=');
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(data) - (char*)0) ), 0), ':');
    }

    if (!data) {
	if (where == 1)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "can't get memory", ':');
	else
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "region is locked", ':');
    } else if (type == 2 || type == 3) {
	if (where == 0)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "unallocated block", ':');
	else
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "already freed", ':');
    } else if (type == 4) {
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "size", '=');
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) ((((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size ), -1), ':');
	if (where == 1)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "just allocated", ':');
	else if (where == 2)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "being freed", ':');
	else if (where == 3)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "being resized", ':');
	else if (where == 5)
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "just resized", ':');
    } else if (type == 0) {
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "bad byte at", '=');
	bufp =
	    (*(_Vmextern.vm_strcpy)) (bufp,
			  (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(((char *)(where))) - (char*)0) ), -1),
			  ':');
	if ((s = (((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.seg.file )) && (bufp + strlen(s) + 64) < endbuf) {
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "allocated at", '=');
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, s, ',');
	    bufp =
		(*(_Vmextern.vm_strcpy)) (bufp,
			      (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(((char *)(((((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) < 0 ? -(((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) : (((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ))))) - (char*)0) ),
					  -1), ':');
	}
    }

    /* location where offending call originates from */
    if (file && file[0] && line > 0
	&& (bufp + strlen(file) + 64) < endbuf) {
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "detected at", '=');
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, file, ',');
	bufp =
	    (*(_Vmextern.vm_strcpy)) (bufp,
			  (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(((char *)(where))) - (char*)0) ), -1),
			  ':');
    }

    *bufp++ = '\n';
    *bufp = '\0';

    vmdbwarn(vm, buf, (bufp - buf));
}

/* check for watched address and issue warnings */

static void dbwatch(Vmalloc_t * vm, Void_t * data, char *file, int line,
		    int type)








{
    register int n;

    for (n = Dbnwatch; n >= 0; --n) {
	if (Dbwatch[n] == data) {
	    dbwarn(vm, data, type, file, line, 4);
	    return;
	}
    }
}

/* record information about the block */

static void dbsetinfo(Vmuchar_t * data, size_t size, char *file, int line)







{
    register Vmuchar_t *begp, *endp;
    register Dbfile_t *last, *db;

    (Dbinit ? 0 : (dbinit(), Dbinit=1) );

    /* find the file structure */
    if (!file || !file[0])
	db = ((Dbfile_t *)0);
    else {
	for (last = ((Dbfile_t *)0), db = Dbfile; db;
	     last = db, db = db->next)
	    if (strcmp(db->file, file) == 0)
		break;
	if (!db) {
	    db = (Dbfile_t *) (*(((Vmalloc_t*)(Vmheap))->meth.allocf))((Vmheap),(
 sizeof(Dbfile_t) + strlen(file)));
	    if (db) {
		(*(_Vmextern.vm_strcpy)) (db->file, file, 0);
		db->next = Dbfile;
		Dbfile = db->next;
	    }
	} else if (last) {	/* move-to-front heuristic */
	    last->next = db->next;
	    db->next = Dbfile;
	    Dbfile = db->next;
	}
    }

    ((((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.seg.file ) = ((db ? db->file : ((char *)0))), (((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) = ((db ? db->file : ((char *)0))) ? (line) : 1);
    (((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size ) = size;
    (((Head_t*)((Vmuchar_t*)(data) - sizeof(Head_t)))->head.seg.seg ) = ((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.seg.seg);

    (((begp) = (Vmuchar_t*)(&(((Head_t*)((Vmuchar_t*)(data) - sizeof(Head_t)))->head.seg.seg )) + sizeof(Seg_t*)), ((endp) = (data)) );
    while (begp < endp)
	*begp++ = 0255;
    (((begp) = (Vmuchar_t*)(data)+(((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size )), ((endp) = (Vmuchar_t*)(&(((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ))) );
    while (begp < endp)
	*begp++ = 0255;
}

/* Check to see if an address is in some data block of a region.
** This returns -(offset+1) if block is already freed, +(offset+1)
** if block is live, 0 if no match.
*/

static long dbaddr(Vmalloc_t * vm, Void_t * addr)





{
    register Block_t *b = NULL, *endb = NULL;
    register Seg_t *seg;
    register Vmuchar_t *data;
    register long offset = -1L;
    register Vmdata_t *vd = vm->data;
    register int local;

    (((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
    if (((local) ? 0 : ((vd)->mode & 0020000) ) || !addr)
	return -1L;
    ((local) ? 0 : ((vd)->mode |= 0020000) );

    for (seg = vd->seg; seg; seg = seg->next) {
	b = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	endb = (Block_t *) (seg->baddr - sizeof(Head_t));
	if ((Vmuchar_t *) addr > (Vmuchar_t *) b &&
	    (Vmuchar_t *) addr < (Vmuchar_t *) endb)
	    break;
    }
    if (!seg)
	goto done;

    if (local) {		/* must be vmfree or vmresize checking address */
	if ((((Head_t*)((Vmuchar_t*)(addr) - sizeof(Head_t)))->head.seg.seg ) == seg) {
	    b = ((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) );
	    if (((((b)->head.head.size.size)) & (01)) && !((((b)->head.head.size.size)) & (04)))
		offset = 0;
	    else
		offset = -2L;
	}
	goto done;
    }

    while (b < endb) {
	data = (Vmuchar_t *) ((Void_t*)((b)->body.data) );
	if ((Vmuchar_t *) addr >= data
	    && (Vmuchar_t *) addr < data + ((b)->head.head.size.size)) {
	    if (((((b)->head.head.size.size)) & (01)) && !((((b)->head.head.size.size)) & (04))) {
		data = ((Vmuchar_t*)(data) + 2*sizeof(Head_t));
		if ((Vmuchar_t *) addr >= data &&
		    (Vmuchar_t *) addr < data + (((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size ))
		    offset = (Vmuchar_t *) addr - data;
	    }
	    goto done;
	}

	b = (Block_t *) ((Vmuchar_t *) ((Void_t*)((b)->body.data) ) + (((b)->head.head.size.size) & ~(07)));
    }

  done:
    ((local) ? 0 : ((vd)->mode &= ~0020000) );
    return offset;
}



static long dbsize(Vmalloc_t * vm, Void_t * addr)





{
    register Block_t *b, *endb;
    register Seg_t *seg;
    register long size;
    register Vmdata_t *vd = vm->data;

    if (((0) ? 0 : ((vd)->mode & 0020000) ))
	return -1L;
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    size = -1L;
    for (seg = vd->seg; seg; seg = seg->next) {
	b = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	endb = (Block_t *) (seg->baddr - sizeof(Head_t));
	if ((Vmuchar_t *) addr <= (Vmuchar_t *) b ||
	    (Vmuchar_t *) addr >= (Vmuchar_t *) endb)
	    continue;
	while (b < endb) {
	    if (addr == (Void_t *) ((Vmuchar_t*)(((Void_t*)((b)->body.data) )) + 2*sizeof(Head_t))) {
		if (((((b)->head.head.size.size)) & (01)) && !((((b)->head.head.size.size)) & (04)))
		    size = (long) (((Head_t*)((Vmuchar_t*)(addr) - 2*sizeof(Head_t)))->head.size.size );
		goto done;
	    }

	    b = (Block_t *) ((Vmuchar_t *) ((Void_t*)((b)->body.data) ) + (((b)->head.head.size.size) & ~(07)));
	}
    }
  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return size;
}


static Void_t *dballoc(Vmalloc_t * vm, size_t size)





{
    register size_t s;
    register Vmuchar_t *data;
    register char *file;
    register int line;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (((0) ? 0 : ((vd)->mode & 0020000) )) {
	dbwarn(vm, ((Vmuchar_t *)0), 0, file, line, 1);
	return ((Void_t *)0);
    }
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    if (vd->mode & 0000004)
	vmdbcheck(vm);

    s = (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + ((2*sizeof(Head_t))+(2*sizeof(Head_t)));
    if (s < sizeof(Body_t))	/* no tiny blocks during Vmdebug */
	s = sizeof(Body_t);

    if (!(data = (Vmuchar_t *) ((((vm)->data)->mode |= 0040000), (*(Vmbest->allocf))((vm),(s)) ))) {
	dbwarn(vm, ((Vmuchar_t *)0), 1, file, line, 1);
	goto done;
    }

    data = ((Vmuchar_t*)(data) + 2*sizeof(Head_t));
    dbsetinfo(data, size, file, line);

    if ((vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), data, size, 0);
    }

    if (Dbnwatch > 0)
	dbwatch(vm, data, file, line, 1);

  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return (Void_t *) data;
}



static int dbfree(Vmalloc_t * vm, Void_t * data)





{
    char *file;
    int line;
    register long offset;
    register int *ip, *endip;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (!data)
	return 0;

    if (((0) ? 0 : ((vd)->mode & 0020000) )) {
	dbwarn(vm, ((Vmuchar_t *)0), 0, file, line, 2);
	return -1;
    }
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    if (vd->mode & 0000004)
	vmdbcheck(vm);

    if ((offset = ((((vm)->data)->mode |= 0040000), dbaddr((vm),(data)) )) != 0) {
	if (vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, data, vm->disc);
	dbwarn(vm, (Vmuchar_t *) data, offset == -1L ? 0 : 1, file, line,
	       2);
	((0) ? 0 : ((vd)->mode &= ~0020000) );
	return -1;
    }

    if (Dbnwatch > 0)
	dbwatch(vm, data, file, line, 2);

    if ((vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) data, ((Vmuchar_t *)0),
		     (((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size ), 0);
    }

    /* clear free space */
    ip = (int *) data;
    endip = ip + ((((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size ) + sizeof(int) - 1) / sizeof(int);
    while (ip < endip)
	*ip++ = 0;

    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return (*(Vmbest->freef)) (vm, (Void_t *) ((Vmuchar_t*)(data) - 2*sizeof(Head_t)));
}

/*	Resizing an existing block */

static Void_t *dbresize(Vmalloc_t * vm, Void_t * addr, register size_t size,
			int type)







{
    register Vmuchar_t *data;
    register size_t s, oldsize;
    register long offset;
    char *file, *oldfile;
    int line, oldline;
    register Vmdata_t *vd = vm->data;

    if (!addr) {
	oldsize = 0;
	data = (Vmuchar_t *) dballoc(vm, size);
	goto done;
    }
    if (size == 0) {
	(void) dbfree(vm, addr);
	return ((Void_t *)0);
    }

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (((0) ? 0 : ((vd)->mode & 0020000) )) {
	dbwarn(vm, ((Vmuchar_t *)0), 0, file, line, 3);
	return ((Void_t *)0);
    }
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    if (vd->mode & 0000004)
	vmdbcheck(vm);

    if ((offset = ((((vm)->data)->mode |= 0040000), dbaddr((vm),(addr)) )) != 0) {
	if (vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, addr, vm->disc);
	dbwarn(vm, (Vmuchar_t *) addr, offset == -1L ? 0 : 1, file, line,
	       3);
	((0) ? 0 : ((vd)->mode &= ~0020000) );
	return ((Void_t *)0);
    }

    if (Dbnwatch > 0)
	dbwatch(vm, addr, file, line, 3);

    /* Vmbest data block */
    data = ((Vmuchar_t*)(addr) - 2*sizeof(Head_t));
    oldsize = (((Head_t*)((Vmuchar_t*)(addr) - 2*sizeof(Head_t)))->head.size.size );
    oldfile = (((Head_t*)((Vmuchar_t*)(addr) - 2*sizeof(Head_t)))->head.seg.file );
    oldline = ((((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) < 0 ? -(((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) : (((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(addr) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ));

    /* do the resize */
    s = (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + ((2*sizeof(Head_t))+(2*sizeof(Head_t)));
    if (s < sizeof(Body_t))
	s = sizeof(Body_t);
    data = (Vmuchar_t *) ((((vm)->data)->mode |= 0040000), 
(*(Vmbest->resizef))((vm),((Void_t *) data),(s),(
(type & ~0000004))) );
    if (!data) {		/* failed, reset data for old block */
	dbwarn(vm, ((Vmuchar_t *)0), 1, file, line, 3);
	dbsetinfo((Vmuchar_t *) addr, oldsize, oldfile, oldline);
    } else {
	data = ((Vmuchar_t*)(data) + 2*sizeof(Head_t));
	dbsetinfo(data, size, file, line);

	if ((vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	    vm->file = file;
	    vm->line = line;
	    (*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) addr, data, size, 0);
	}
	if (Dbnwatch > 0)
	    dbwatch(vm, data, file, line, 5);
    }

    ((0) ? 0 : ((vd)->mode &= ~0020000) );

  done:if (data && (type & 0000004) && size > oldsize) {
	register Vmuchar_t *d = data + oldsize, *ed = data + size;
	do {
	    *d++ = 0;
	} while (d < ed);
    }
    return (Void_t *) data;
}

/* compact any residual free space */

static int dbcompact(Vmalloc_t * vm)




{
    return (*(Vmbest->compactf)) (vm);
}

/* check for memory overwrites over all live blocks */

int vmdbcheck(Vmalloc_t * vm)




{
    register Block_t *b, *endb;
    register Seg_t *seg;
    int rv;
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0001000))
	return -1;

    rv = 0;
    for (seg = vd->seg; seg; seg = seg->next) {
	b = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	endb = (Block_t *) (seg->baddr - sizeof(Head_t));
	while (b < endb) {
	    register Vmuchar_t *data, *begp, *endp;

	    if (((((b)->head.head.size.size)) & (04)) || !((((b)->head.head.size.size)) & (01)))
		goto next;

	    data = ((Vmuchar_t*)(((Void_t*)((b)->body.data) )) + 2*sizeof(Head_t));
	    if (((((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) <= 0)) {	/* seen this before */
		rv += 1;
		goto next;
	    }

	    (((begp) = (Vmuchar_t*)(&(((Head_t*)((Vmuchar_t*)(data) - sizeof(Head_t)))->head.seg.seg )) + sizeof(Seg_t*)), ((endp) = (data)) );
	    for (; begp < endp; ++begp)
		if (*begp != 0255)
		    goto set_bad;

	    (((begp) = (Vmuchar_t*)(data)+(((Head_t*)((Vmuchar_t*)(data) - 2*sizeof(Head_t)))->head.size.size )), ((endp) = (Vmuchar_t*)(&(((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ))) );
	    for (; begp < endp; ++begp) {
		if (*begp == 0255)
		    continue;
	      set_bad:
		dbwarn(vm, data, begp - data, ((char *)0), 0, 0);
		((((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) > 0 ? ((((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line ) = -(((Head_t*)((Vmuchar_t*)((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) )+(((((Block_t*)((Vmuchar_t*)(data) - 3*sizeof(Head_t)) ))->head.head.size.size) & ~(07))))->head.size.line )) : -1);
		rv += 1;
		goto next;
	    }

	  next:b = (Block_t *) ((Vmuchar_t *) ((Void_t*)((b)->body.data) ) +
			     (((b)->head.head.size.size) & ~(07)));
	}
    }

    return rv;
}

/* set/delete an address to watch */

Void_t *vmdbwatch(Void_t * addr)




{
    register int n;
    register Void_t *out;

    out = ((Void_t *)0);
    if (!addr)
	Dbnwatch = 0;
    else {
	for (n = Dbnwatch - 1; n >= 0; --n)
	    if (Dbwatch[n] == addr)
		break;
	if (n < 0) {		/* insert */
	    if (Dbnwatch == 32) {	/* delete left-most */
		out = Dbwatch[0];
		Dbnwatch -= 1;
		for (n = 0; n < Dbnwatch; ++n)
		    Dbwatch[n] = Dbwatch[n + 1];
	    }
	    Dbwatch[Dbnwatch] = addr;
	    Dbnwatch += 1;
	}
    }
    return out;
}


static Void_t *dbalign(Vmalloc_t * vm, size_t size, size_t align)






{
    register Vmuchar_t *data;
    register size_t s;
    register char *file;
    register int line;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (size <= 0 || align <= 0)
	return ((Void_t *)0);

    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    if ((s = (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + ((2*sizeof(Head_t))+(2*sizeof(Head_t)))) < sizeof(Body_t))
	s = sizeof(Body_t);

    if (!
	(data = (Vmuchar_t *) ((((vm)->data)->mode |= 0040000), (*(Vmbest->alignf))((vm),(s),(align)) )))
	goto done;

    data += (2*sizeof(Head_t));
    dbsetinfo(data, size, file, line);

    if ((vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), data, size, align);
    }

  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return (Void_t *) data;
}

static Vmethod_t _Vmdebug = {
    dballoc,
    dbresize,
    dbfree,
    dbaddr,
    dbsize,
    dbcompact,
    dbalign,
    0001000
};

__DEFINE__(Vmethod_t *, Vmdebug, &_Vmdebug);
