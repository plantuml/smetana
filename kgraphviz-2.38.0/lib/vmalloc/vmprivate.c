#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmprivate.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\vmalloc\\vmprivate.c" 2






/*	Private code used in the vmalloc library
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/

/* Get more memory for a region */

static Block_t *vmextend(register Vmalloc_t * vm, size_t size,
			 Vmsearch_f searchf)






{
    register size_t s;
    register Seg_t *seg;
    register Block_t *bp, *t;
    register Vmuchar_t *addr;
    register Vmdata_t *vd = vm->data;
    register Vmemory_f memoryf = vm->disc->memoryf;
    register Vmexcept_f exceptf = vm->disc->exceptf;

    (((_Vmextern.vm_pagesize)) = 8192);

    if (vd->incr <= 0)		/* this is just _Vmheap on the first call */
	vd->incr = 4 * (_Vmextern.vm_pagesize);

    /* Get slightly more for administrative data */
    s = size + sizeof(Seg_t) + sizeof(Block_t) + sizeof(Head_t) +
	2 * sizeof(struct _align_s);
    if (s <= size)		/* size was too large and we have wrapped around */
	return ((Block_t *)0);
    if ((size = (((vd->incr)&((vd->incr)-1)) ? (((((s)) + (((vd->incr))-1)) / ((vd->incr))) * ((vd->incr))) : ((((s)) + (((vd->incr))-1)) & ~(((vd->incr))-1)) )) < s)
	return ((Block_t *)0);

    /* see if we can extend the current segment */
    if (!(seg = vd->seg))
	addr = ((Vmuchar_t *)0);
    else {
	if (!vd->wild || ((vd->wild)->head.head.seg.seg) != seg)
	    s = 0;
	else {
	    s = ((vd->wild)->head.head.size.size) + sizeof(Head_t);
	    if ((s = (s / vd->incr) * vd->incr) == size)
		size += vd->incr;
	}
	addr = (Vmuchar_t *) (*memoryf) (vm, seg->addr, seg->extent,
					 seg->extent + size - s, vm->disc);
	if (!addr)
	    seg = ((Seg_t *)0);
	else {
	    /**/ ;
	    addr += seg->extent;
	    size -= s;
	}
    }

    while (!addr) {		/* try to get space */
	if ((addr =
	     (Vmuchar_t *) (*memoryf) (vm, ((Void_t *)0), 0, size,
				       vm->disc)))
	    break;

	/* check with exception handler to see if we should continue */
	if (!exceptf)
	    return ((Block_t *)0);
	else {
	    int rv, lock;
	    lock = vd->mode & 0020000;
	    vd->mode &= ~0020000;
	    rv = (*exceptf) (vm, 2, (Void_t *) size, vm->disc);
	    vd->mode |= lock;
	    if (rv <= 0) {
		if (rv == 0)
		    vd->mode |= 0010000;
		return ((Block_t *)0);
	    }
	}
    }

    if (seg) {			/* extending current segment */
	bp = ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) );
	/**/ ;
	 /**/ ;

	if (vd->mode & (0000100 | 0001000 | 0002000)) {
	    if (!((((bp)->head.head.size.size)) & (02)))
		((bp)->head.head.size.size) = size - sizeof(Head_t);
	    else {
		/**/ ;
		bp = (*((Block_t**)(((char*)(bp)) - sizeof(Block_t*)) ) );
		if (bp == vd->wild)
		    vd->wild = ((Block_t *)0);
		else
		    ((!(((bp)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((bp)->body.body.right) == (bp) )) ? (((((t)) = (((bp))->body.body.link)) ? ((((t))->body.body.left) = (((bp))->body.body.left)) : ((Block_t*)0) ), ((((t)) = (((bp))->body.body.left)) ? ((((t))->body.body.link) = (((bp))->body.body.link)) : ((((vd))->tiny)[(((sizeof(struct _align_s)) == 8 ?(((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))>>3) :((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))/(sizeof(struct _align_s))))] = (((bp))->body.body.link)) ) ) : (*searchf)((vd),((bp)->head.head.size.size),(bp)) );
		((bp)->head.head.size.size) += size;
	    }
	} else {
	    if (seg->free) {
		bp = seg->free;
		seg->free = ((Block_t *)0);
		((bp)->head.head.size.size) += size;
	    } else
		((bp)->head.head.size.size) = size - sizeof(Head_t);
	}

	seg->size += size;
	seg->extent += size;
	seg->baddr += size;
    } else {			/* creating a new segment */
	register Seg_t *sp, *lastsp;

	if ((s = (size_t) (((Vmulong_t)((char*)(addr) - (char*)0) ) % sizeof(struct _align_s))) != 0)
	    addr += sizeof(struct _align_s) - s;

	seg = (Seg_t *) addr;
	seg->vm = vm;
	seg->addr = (Void_t *) (addr - (s ? sizeof(struct _align_s) - s : 0));
	seg->extent = size;
	seg->baddr = addr + size - (s ? 2 * sizeof(struct _align_s) : 0);
	seg->free = ((Block_t *)0);
	bp = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	((bp)->head.head.seg.seg) = seg;
	((bp)->head.head.size.size) = seg->baddr - (Vmuchar_t *) bp - 2 * sizeof(Head_t);

	/* NOTE: for Vmbest, Vmdebug and Vmprofile the region's segment list
	   is reversely ordered by addresses. This is so that we can easily
	   check for the wild block.
	 */
	lastsp = ((Seg_t *)0);
	sp = vd->seg;
	if (vd->mode & (0000100 | 0001000 | 0002000))
	    for (; sp; lastsp = sp, sp = sp->next)
		if (seg->addr > sp->addr)
		    break;
	seg->next = sp;
	if (lastsp)
	    lastsp->next = seg;
	else
	    vd->seg = seg;

	seg->size = ((bp)->head.head.size.size);
    }

    /* make a fake header for possible segmented memory */
    t = ((Block_t*)((bp)->body.data + ((bp)->head.head.size.size)) );
    ((t)->head.head.seg.seg) = seg;
    ((t)->head.head.size.size) = (01);

    /* see if the wild block is still wild */
    if ((t = vd->wild) && (seg = ((t)->head.head.seg.seg)) != vd->seg) {
	((((((Block_t*)((t)->body.data + ((t)->head.head.size.size)) ))->head.head.size.size)) &= ~(02));
	if (vd->mode & (0000100 | 0001000 | 0002000)) {
	    ((t)->head.head.size.size) |= (01) | (04);
	    ((t)->body.body.link) = ((vd)->cache)[(((t)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((t)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((t)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)];
	    ((vd)->cache)[(((t)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((t)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((t)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)] = t;
	} else
	    seg->free = t;

	vd->wild = ((Block_t *)0);
    }

    return bp;
}

/* Truncate a segment if possible */

static int vmtruncate(Vmalloc_t * vm, Seg_t * seg, size_t size, int exact)







{
    register Void_t *caddr;
    register Seg_t *last;
    register Vmdata_t *vd = vm->data;
    register Vmemory_f memoryf = vm->disc->memoryf;

    caddr = seg->addr;

    if (size < seg->size) {
	register size_t less;

	/* the truncated amount must satisfy the discipline requirement */
	if ((less = vm->disc->round) <= 0)
	    less = (_Vmextern.vm_pagesize);
	less = (size / less) * less;
	less = (less / sizeof(struct _align_s)) * sizeof(struct _align_s);

	if (!exact)		/* only truncate multiples of incr */
	    less = (less / vd->incr) * vd->incr;

	if (less > 0 && size > less && (size - less) < sizeof(Block_t))
	    less -= vd->incr;

	if (less <= 0 ||
	    (*memoryf) (vm, caddr, seg->extent, seg->extent - less,
			vm->disc) != caddr)
	    return -1;

	seg->extent -= less;
	seg->size -= less;
	seg->baddr -= less;
	((((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ))->head.head.size.size) = (01);
	return 0;
    }

    /* unlink segment from region */
    if (seg == vd->seg) {
	vd->seg = seg->next;
	last = ((Seg_t *)0);
    } else {
	for (last = vd->seg; last->next != seg; last = last->next);
	last->next = seg->next;
    }

    /* now delete it */
    if ((*memoryf) (vm, caddr, seg->extent, 0, vm->disc) == caddr)
	return 0;

    /* space reduction failed, reinsert segment */
    if (last) {
	seg->next = last->next;
	last->next = seg;
    } else {
	seg->next = vd->seg;
	vd->seg = seg;
    }
    return -1;
}

/* Externally visible names but local to library */
Vmextern_t _Vmextern = { vmextend,	/* _Vmextend    */
    vmtruncate,			/* _Vmtruncate  */
    0,				/* _Vmpagesize  */
    ((char *(*)_ARG_((char *, char *, int)))0),	/* _Vmstrcpy    */
    ((char *(*)_ARG_((Vmulong_t, int)))0),	/* _Vmitoa      */
    ((void(*)_ARG_((Vmalloc_t *,
 Vmuchar_t *, Vmuchar_t *, size_t, size_t)))0),	/* _Vmtrace   */
    ((void(*)_ARG_((Vmalloc_t *)))0)	/* _Vmpfclose       */
};
