#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmlast.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\vmalloc\\vmlast.c" 2

/*	Allocation with freeing and reallocing of last allocated block only.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/


static Void_t *lastalloc(Vmalloc_t * vm, size_t size)





{
    register Block_t *tp, *next;
    register Seg_t *seg, *last;
    register size_t s;
    register Vmdata_t *vd = vm->data;
    register int local;
    size_t orgsize = 0;

    if (!(local = vd->mode & 0000001)) {
	(((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
	if (((local) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((local) ? 0 : ((vd)->mode |= 0020000) );
	orgsize = size;
    }

    size = size < sizeof(struct _align_s) ? sizeof(struct _align_s) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );
    for (;;) {
	for (last = ((Seg_t *)0), seg = vd->seg; seg;
	     last = seg, seg = seg->next) {
	    if (!(tp = seg->free) || (((tp)->head.head.size.size) + sizeof(Head_t)) < size)
		continue;
	    if (last) {
		last->next = seg->next;
		seg->next = vd->seg;
		vd->seg = seg;
	    }
	    goto got_block;
	}

	/* there is no usable free space in region, try extending */
	if ((tp = (*(_Vmextern.vm_extend)) (vm, size, ((Vmsearch_f)0)))) {
	    seg = ((tp)->head.head.seg.seg);
	    goto got_block;
	} else if (vd->mode & 0010000)
	    vd->mode &= ~0010000;
	else
	    goto done;
    }

  got_block:
    if ((s = ((tp)->head.head.size.size)) >= size) {
	next = (Block_t *) ((Vmuchar_t *) tp + size);
	((next)->head.head.size.size) = s - size;
	((next)->head.head.seg.seg) = seg;
	seg->free = next;
    } else
	seg->free = ((Block_t *)0);

    vd->free = seg->last = tp;

    if (!local && (vd->mode & 0000002) && (_Vmextern.vm_trace))
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), (Vmuchar_t *) tp, orgsize, 0);

  done:
    ((local) ? 0 : ((vd)->mode &= ~0020000) );
    return (Void_t *) tp;
}


static int lastfree(Vmalloc_t * vm, register Void_t * data)





{
    register Seg_t *seg;
    register Block_t *fp;
    register size_t s;
    register Vmdata_t *vd = vm->data;
    register int local;

    if (!data)
	return 0;
    if (!(local = vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }
    if (data != (Void_t *) vd->free) {
	if (!local && vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, data, vm->disc);
	((0) ? 0 : ((vd)->mode &= ~0020000) );
	return -1;
    }

    seg = vd->seg;
    if (!local && (vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	if (seg->free)
	    s = (Vmuchar_t *) (seg->free) - (Vmuchar_t *) data;
	else
	    s = (Vmuchar_t *) ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ) - (Vmuchar_t *) data;
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) data, ((Vmuchar_t *)0), s, 0);
    }

    vd->free = ((Block_t *)0);
    fp = (Block_t *) data;
    ((fp)->head.head.seg.seg) = seg;
    ((fp)->head.head.size.size) =
	((Vmuchar_t *) ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ) - (Vmuchar_t *) data) -
	sizeof(Head_t);
    seg->free = fp;
    seg->last = ((Block_t *)0);

    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return 0;
}


static Void_t *lastresize(Vmalloc_t * vm, register Void_t * data, size_t size,
			  int type)







{
    register Block_t *tp;
    register Seg_t *seg;
    register int *d, *ed;
    register size_t oldsize;
    register ssize_t s, ds;
    register Vmdata_t *vd = vm->data;
    register int local;
    register Void_t *addr;
    Void_t *orgdata = 0;
    size_t orgsize = 0;

    if (!data) {
	oldsize = 0;
	data = lastalloc(vm, size);
	goto done;
    }
    if (size <= 0) {
	(void) lastfree(vm, data);
	return ((Void_t *)0);
    }

    if (!(local = vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((0) ? 0 : ((vd)->mode |= 0020000) );
	orgdata = data;
	orgsize = size;
    }

    if (data == (Void_t *) vd->free)
	seg = vd->seg;
    else {			/* see if it was one of ours */
	for (seg = vd->seg; seg; seg = seg->next)
	    if (data >= seg->addr && data < (Void_t *) seg->baddr)
		break;
	if (!seg || (((Vmulong_t)((char*)(data) - (char*)0) ) % sizeof(struct _align_s)) != 0 ||
	    (seg->last && (Vmuchar_t *) data > (Vmuchar_t *) seg->last)) {
	    ((0) ? 0 : ((vd)->mode &= ~0020000) );
	    return ((Void_t *)0);
	}
    }

    /* set 's' to be the current available space */
    if (data != seg->last) {
	if (seg->last && (Vmuchar_t *) data < (Vmuchar_t *) seg->last)
	    oldsize = (Vmuchar_t *) seg->last - (Vmuchar_t *) data;
	else
	    oldsize = (Vmuchar_t *) ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ) - (Vmuchar_t *) data;
	s = -1;
    } else {
	s = (Vmuchar_t *) ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ) - (Vmuchar_t *) data;
	if (!(tp = seg->free))
	    oldsize = s;
	else {
	    oldsize = (Vmuchar_t *) tp - (Vmuchar_t *) data;
	    seg->free = ((Block_t *)0);
	}
    }

    size = size < sizeof(struct _align_s) ? sizeof(struct _align_s) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );
    if (s < 0 || (ssize_t) size > s) {
	if (s >= 0) {		/* amount to extend */
	    ds = size - s;
	    ds = (((vd->incr)&((vd->incr)-1)) ? (((((ds)) + (((vd->incr))-1)) / ((vd->incr))) * ((vd->incr))) : ((((ds)) + (((vd->incr))-1)) & ~(((vd->incr))-1)) );
	    addr = (*vm->disc->memoryf) (vm, seg->addr, seg->extent,
					 seg->extent + ds, vm->disc);
	    if (addr == seg->addr) {
		s += ds;
		seg->size += ds;
		seg->extent += ds;
		seg->baddr += ds;
		((((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ))->head.head.size.size) = (01);
	    } else
		goto do_alloc;
	} else {
	  do_alloc:
	    if (!(type & (0000002 | 0000001)))
		data = ((Void_t *)0);
	    else {
		tp = vd->free;
		if (!(addr = ((((vm)->data)->mode |= 0040000), lastalloc((vm),(size)) ))) {
		    vd->free = tp;
		    data = ((Void_t *)0);
		} else {
		    if (type & 0000001) {
			ed = (int *) data;
			d = (int *) addr;
			ds = oldsize < size ? oldsize : size;
			switch(ds/sizeof(int)) { default: memcpy((Void_t*)d,(Void_t*)ed,ds); break; case 7: *d++ = *ed++; case 6: *d++ = *ed++; case 5: *d++ = *ed++; case 4: *d++ = *ed++; case 3: *d++ = *ed++; case 2: *d++ = *ed++; case 1: *d++ = *ed++; };
		    }

		    if (s >= 0 && seg != vd->seg) {
			tp = (Block_t *) data;
			((tp)->head.head.seg.seg) = seg;
			((tp)->head.head.size.size) = s - sizeof(Head_t);
			seg->free = tp;
		    }

		    /* new block and size */
		    data = addr;
		    seg = vd->seg;
		    s = (Vmuchar_t *) ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) ) -
			(Vmuchar_t *) data;
		    seg->free = ((Block_t *)0);
		}
	    }
	}
    }

    if (data) {
	if (s >= (ssize_t) (size + sizeof(Head_t))) {
	    tp = (Block_t *) ((Vmuchar_t *) data + size);
	    ((tp)->head.head.seg.seg) = seg;
	    ((tp)->head.head.size.size) = (s - size) - sizeof(Head_t);
	    seg->free = tp;
	}

	vd->free = seg->last = (Block_t *) data;

	if (!local && (vd->mode & 0000002) && (_Vmextern.vm_trace))
	    (*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) orgdata, (Vmuchar_t *) data,
			 orgsize, 0);
    }

    ((0) ? 0 : ((vd)->mode &= ~0020000) );

  done:if (data && (type & 0000004) && size > oldsize) {
	d = (int *) ((char *) data + oldsize);
	size -= oldsize;
	switch(size/sizeof(int)) { default: memset((Void_t*)d,0,size); break; case 7: *d++ = 0; case 6: *d++ = 0; case 5: *d++ = 0; case 4: *d++ = 0; case 3: *d++ = 0; case 2: *d++ = 0; case 1: *d++ = 0; };
    }

    return data;
}



static long lastaddr(Vmalloc_t * vm, Void_t * addr)





{
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0000001) && ((0) ? 0 : ((vd)->mode & 0020000) ))
	return -1L;
    if (!vd->free || addr < (Void_t *) vd->free
	|| addr >= (Void_t *) vd->seg->baddr)
	return -1L;
    else
	return (Vmuchar_t *) addr - (Vmuchar_t *) vd->free;
}


static long lastsize(Vmalloc_t * vm, Void_t * addr)





{
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0000001) && ((0) ? 0 : ((vd)->mode & 0020000) ))
	return -1L;
    if (!vd->free || addr != (Void_t *) vd->free)
	return -1L;
    else if (vd->seg->free)
	return (Vmuchar_t *) vd->seg->free - (Vmuchar_t *) addr;
    else
	return (Vmuchar_t *) vd->seg->baddr - (Vmuchar_t *) addr -
	    sizeof(Head_t);
}


static int lastcompact(Vmalloc_t * vm)




{
    register Block_t *fp;
    register Seg_t *seg, *next;
    register size_t s;
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    for (seg = vd->seg; seg; seg = next) {
	next = seg->next;

	if (!(fp = seg->free))
	    continue;

	seg->free = ((Block_t *)0);
	if (seg->size == (s = ((fp)->head.head.size.size) & ~(07)))
	    s = seg->extent;
	else
	    s += sizeof(Head_t);

	if ((*(_Vmextern.vm_truncate)) (vm, seg, s, 1) < 0)
	    seg->free = fp;
    }

    if ((vd->mode & 0000002) && (_Vmextern.vm_trace))
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) 0, (Vmuchar_t *) 0, 0, 0);

    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return 0;
}


static Void_t *lastalign(Vmalloc_t * vm, size_t size, size_t align)






{
    register Vmuchar_t *data;
    register size_t s, orgsize = 0, orgalign = 0;
    register Seg_t *seg;
    register Block_t *next;
    register int local;
    register Vmdata_t *vd = vm->data;

    if (size <= 0 || align <= 0)
	return ((Void_t *)0);

    if (!(local = vd->mode & 0000001)) {
	(((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
	if (((local) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((local) ? 0 : ((vd)->mode |= 0020000) );
	orgsize = size;
	orgalign = align;
    }

    size = size <= (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) ? (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );
    align = ((align)%(sizeof(struct _align_s)) == 0 ? (align) : (sizeof(struct _align_s))%(align) == 0 ? (sizeof(struct _align_s)) : (sizeof(struct _align_s))*(align));

    s = size + align;
    if (!(data = (Vmuchar_t *) ((((vm)->data)->mode |= 0040000), lastalloc((vm),(s)) )))
	goto done;

    /* find the segment containing this block */
    for (seg = vd->seg; seg; seg = seg->next)
	if (seg->last == (Block_t *) data)
	    break;
     /**/ ;

    /* get a suitably aligned address */
    if ((s = (size_t) (((Vmulong_t)((char*)(data) - (char*)0) ) % align)) != 0)
	data += align - s;
    /**/ ;

    /* free the unused tail */
    next = (Block_t *) (data + size);
    if ((s = (seg->baddr - (Vmuchar_t *) next)) >= sizeof(Block_t)) {
	((next)->head.head.seg.seg) = seg;
	((next)->head.head.size.size) = s - sizeof(Head_t);
	seg->free = next;
    }

    vd->free = seg->last = (Block_t *) data;

    if (!local && !(vd->mode & 0000001) && (_Vmextern.vm_trace)
	&& (vd->mode & 0000002))
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), data, orgsize, orgalign);

  done:
    ((local) ? 0 : ((vd)->mode &= ~0020000) );

    return (Void_t *) data;
}

/* Public method for free-1 allocation */
static Vmethod_t _Vmlast = {
    lastalloc,
    lastresize,
    lastfree,
    lastaddr,
    lastsize,
    lastcompact,
    lastalign,
    0000400
};

__DEFINE__(Vmethod_t *, Vmlast, &_Vmlast);
