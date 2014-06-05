#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmprofile.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\vmalloc\\vmprofile.c" 2

/*	Method to profile space usage.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 03/23/94.
*/













typedef struct _pfdata_s Pfdata_t;
struct _pfdata_s {
    Vmulong_t hash;		/* hash value                   */
    union {
	char *file;		/* file name                    */
	Vmulong_t max;		/* max busy space for region    */
    } fm;
    Vmalloc_t *vm;		/* region alloc from            */
    Pfobj_t *region;		/* pointer to region record     */
    Vmulong_t nalloc;		/* number of alloc calls        */
    Vmulong_t alloc;		/* amount allocated             */
    Vmulong_t nfree;		/* number of free calls         */
    Vmulong_t free;		/* amount freed                 */
};
struct _pfobj_s {
    Pfobj_t *next;		/* next in linked list  */
    int line;			/* line #, 0 for name holder    */
    union {
	Pfdata_t data;
	char f[1];		/* actual file name             */
    } data;
};

static Pfobj_t **Pftable;	/* hash table           */

static Vmalloc_t *Vmpf;		/* heap for our own use */


static Pfobj_t *pfsearch(Vmalloc_t * vm, char *file, int line)






{
    register Pfobj_t *pf, *last;
    register Vmulong_t h;
    register int n;
    register char *cp;

    if (!Vmpf && !(Vmpf = vmopen(Vmdcheap, Vmpool, 0)))
	return ((Pfobj_t *)0);

    /* make hash table; PFTABLE'th slot hold regions' records */
    if (!Pftable) {
	if (!
	    (Pftable =
	     (Pfobj_t **) (*(((Vmalloc_t*)(Vmheap))->meth.allocf))((Vmheap),(
(1019 + 1) * sizeof(Pfobj_t *)))))
	    return ((Pfobj_t *)0);
	for (n = 1019; n >= 0; --n)
	    Pftable[n] = ((Pfobj_t *)0);
    }

    /* see if it's there with a combined hash value of vm,file,line */
    h = line + (((Vmulong_t) vm) >> 4);
    for (cp = file; *cp; ++cp)
	h += (h << 7) + ((*cp) & 0377) + 987654321L;
    n = (int) (h % 1019);
    for (last = ((Pfobj_t *)0), pf = Pftable[n]; pf;
	 last = pf, pf = pf->next)
	if (((pf)->line) == line && ((pf)->data.data.vm) == vm
	    && strcmp(((pf)->data.data.fm.file), file) == 0)
	    break;

    /* insert if not there yet */
    if (!pf) {
	register Pfobj_t *fn;
	register Pfobj_t *pfvm;
	register Vmulong_t hn;

	/* first get/construct the file name slot */
	hn = 0;
	for (cp = file; *cp; ++cp)
	    hn += (hn << 7) + ((*cp) & 0377) + 987654321L;
	n = (int) (hn % 1019);
	for (fn = Pftable[n]; fn; fn = fn->next)
	    if (((fn)->line) < 0 && strcmp(((fn)->data.f), file) == 0)
		break;
	if (!fn) {
	    register size_t s;
	    s = sizeof(Pfobj_t) - sizeof(Pfdata_t) + strlen(file) + 1;
	    if (!(fn = (Pfobj_t *) (*(((Vmalloc_t*)(Vmheap))->meth.allocf))((Vmheap),(s))))
		return ((Pfobj_t *)0);
	    fn->next = Pftable[n];
	    Pftable[n] = fn;
	    ((fn)->line) = -1;
	    strcpy(((fn)->data.f), file);
	}

	/* get region record; note that these are ordered by vm */
	last = ((Pfobj_t *)0);
	for (pfvm = Pftable[1019]; pfvm; last = pfvm, pfvm = pfvm->next)
	    if (vm >= ((pfvm)->data.data.vm))
		break;
	if (!pfvm || ((pfvm)->data.data.vm) > vm) {
	    if (!(pfvm = (Pfobj_t *) (*(((Vmalloc_t*)(Vmpf))->meth.allocf))((Vmpf),(sizeof(Pfobj_t)))))
		return ((Pfobj_t *)0);
	    if (last) {
		pfvm->next = last->next;
		last->next = pfvm;
	    } else {
		pfvm->next = Pftable[1019];
		Pftable[1019] = pfvm;
	    }
	    ((pfvm)->data.data.nalloc) = ((pfvm)->data.data.alloc) = 0;
	    ((pfvm)->data.data.nfree) = ((pfvm)->data.data.free) = 0;
	    ((pfvm)->data.data.fm.max) = 0;
	    ((pfvm)->data.data.vm) = vm;
	    ((pfvm)->line) = 0;
	}

	if (!(pf = (Pfobj_t *) (*(((Vmalloc_t*)(Vmpf))->meth.allocf))((Vmpf),(sizeof(Pfobj_t)))))
	    return ((Pfobj_t *)0);
	n = (int) (h % 1019);
	pf->next = Pftable[n];
	Pftable[n] = pf;
	((pf)->line) = line;
	((pf)->data.data.fm.file) = ((fn)->data.f);
	((pf)->data.data.region) = pfvm;
	((pf)->data.data.vm) = vm;
	((pf)->data.data.nalloc) = 0;
	((pf)->data.data.alloc) = 0;
	((pf)->data.data.nfree) = 0;
	((pf)->data.data.free) = 0;
	((pf)->data.data.hash) = h;
    } else if (last) {		/* do a move-to-front */
	last->next = pf->next;
	pf->next = Pftable[n];
	Pftable[n] = pf;
    }

    return pf;
}


static void pfclose(Vmalloc_t * vm)




{
    register int n;
    register Pfobj_t *pf, *next, *last;

    /* free all records related to region vm */
    for (n = 1019; n >= 0; --n) {
	for (last = ((Pfobj_t *)0), pf = Pftable[n]; pf;) {
	    next = pf->next;

	    if (((pf)->line) >= 0 && ((pf)->data.data.vm) == vm) {
		if (last)
		    last->next = next;
		else
		    Pftable[n] = next;
		(*(((Vmalloc_t*)(Vmpf))->meth.freef))((Vmpf),(Void_t*)(pf));
	    } else
		last = pf;

	    pf = next;
	}
    }
}


static void pfsetinfo(Vmalloc_t * vm, Vmuchar_t * data, size_t size,
		      char *file, int line)








{
    register Pfobj_t *pf;
    register Vmulong_t s;

    /* let vmclose knows that there are records for region vm */
    (_Vmextern.vm_pfclose) = pfclose;

    if (!file || line <= 0) {
	file = "";
	line = 0;
    }

    if ((pf = pfsearch(vm, file, line))) {
	((pf)->data.data.alloc) += size;
	((pf)->data.data.nalloc) += 1;
    }
    (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.seg.pf) = pf;
    (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.size.size) = size;

    if (pf) {			/* update region statistics */
	pf = ((pf)->data.data.region);
	((pf)->data.data.alloc) += size;
	((pf)->data.data.nalloc) += 1;
	if ((s = ((pf)->data.data.alloc) - ((pf)->data.data.free)) > ((pf)->data.data.fm.max))
	    ((pf)->data.data.fm.max) = s;
    }
}

/* sort by file names and line numbers */

static Pfobj_t *pfsort(Pfobj_t * pf)




{
    register Pfobj_t *one, *two, *next;
    register int cmp;

    if (!pf->next)
	return pf;

    /* partition to two equal size lists */
    one = two = ((Pfobj_t *)0);
    while (pf) {
	next = pf->next;
	pf->next = one;
	one = pf;

	if ((pf = next)) {
	    next = pf->next;
	    pf->next = two;
	    two = pf;
	    pf = next;
	}
    }

    /* sort and merge the lists */
    one = pfsort(one);
    two = pfsort(two);
    for (pf = next = ((Pfobj_t *)0);;) {	/* make sure that the "<>" file comes first */
	if (((one)->line) == 0 && ((two)->line) == 0)
	    cmp = ((one)->data.data.vm) > ((two)->data.data.vm) ? 1 : -1;
	else if (((one)->line) == 0)
	    cmp = -1;
	else if (((two)->line) == 0)
	    cmp = 1;
	else if ((cmp = strcmp(((one)->data.data.fm.file), ((two)->data.data.fm.file))) == 0) {
	    cmp = ((one)->line) - ((two)->line);
	    if (cmp == 0)
		cmp = ((one)->data.data.vm) > ((two)->data.data.vm) ? 1 : -1;
	}

	if (cmp < 0) {
	    if (!pf)
		pf = one;
	    else
		next->next = one;
	    next = one;
	    if (!(one = one->next)) {
		if (two)
		    next->next = two;
		return pf;
	    }
	} else {
	    if (!pf)
		pf = two;
	    else
		next->next = two;
	    next = two;
	    if (!(two = two->next)) {
		if (one)
		    next->next = one;
		return pf;
	    }
	}
    }
}


static char *pfsummary(char *buf, Vmulong_t na, Vmulong_t sa,
		       Vmulong_t nf, Vmulong_t sf, Vmulong_t max,
		       Vmulong_t size)










{
    buf = (*(_Vmextern.vm_strcpy)) (buf, "n_alloc", '=');
    buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (na, -1), ':');
    buf = (*(_Vmextern.vm_strcpy)) (buf, "n_free", '=');
    buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (nf, -1), ':');
    buf = (*(_Vmextern.vm_strcpy)) (buf, "s_alloc", '=');
    buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (sa, -1), ':');
    buf = (*(_Vmextern.vm_strcpy)) (buf, "s_free", '=');
    buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (sf, -1), ':');
    if (max > 0) {
	buf = (*(_Vmextern.vm_strcpy)) (buf, "max_busy", '=');
	buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (max, -1), ':');
	buf = (*(_Vmextern.vm_strcpy)) (buf, "extent", '=');
	buf = (*(_Vmextern.vm_strcpy)) (buf, (*(_Vmextern.vm_itoa)) (size, -1), ':');
    }
    *buf++ = '\n';

    return buf;
}

/* print profile data */

int vmprofile(Vmalloc_t * vm, int fd)





{
    register Pfobj_t *pf, *list, *next, *last;
    register int n;
    register Vmulong_t nalloc, alloc, nfree, free;
    register Seg_t *seg;
    char buf[1024], *bufp, *endbuf;




    if (fd < 0)
	return -1;

    /* initialize functions from vmtrace.c that we use below */
    if ((n = vmtrace(-1)) >= 0)
	vmtrace(n);

    alloc = free = nalloc = nfree = 0;
    list = ((Pfobj_t *)0);
    for (n = 1019 - 1; n >= 0; --n) {
	for (pf = Pftable[n], last = ((Pfobj_t *)0); pf;) {
	    next = pf->next;

	    if (((pf)->line) < 0 || (vm && vm != ((pf)->data.data.vm))) {
		last = pf;
		goto next_pf;
	    }

	    /* remove from hash table */
	    if (last)
		last->next = next;
	    else
		Pftable[n] = next;

	    /* put on output list */
	    pf->next = list;
	    list = pf;
	    nalloc += ((pf)->data.data.nalloc);
	    alloc += ((pf)->data.data.alloc);
	    nfree += ((pf)->data.data.nfree);
	    free += ((pf)->data.data.free);

	  next_pf:
	    pf = next;
	}
    }

    (bufp = buf, endbuf = buf+sizeof(buf)-128);
    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "ALLOCATION USAGE SUMMARY", ':');
    bufp = pfsummary(bufp, nalloc, alloc, nfree, free, 0, 0);

    /* print regions' summary data */
    for (pf = Pftable[1019]; pf; pf = pf->next) {
	if (vm && ((pf)->data.data.vm) != vm)
	    continue;
	alloc = 0;
	for (seg = ((pf)->data.data.vm)->data->seg; seg; seg = seg->next)
	    alloc += seg->extent;
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "region", '=');
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(((pf)->data.data.vm)) - (char*)0) ), 0), ':');
	bufp = pfsummary(bufp, ((pf)->data.data.nalloc), ((pf)->data.data.alloc),
			 ((pf)->data.data.nfree), ((pf)->data.data.free), ((pf)->data.data.fm.max), alloc);
    }

    /* sort then output detailed profile */
    list = pfsort(list);
    for (pf = list; pf;) {	/* compute summary for file */
	alloc = free = nalloc = nfree = 0;
	for (last = pf; last; last = last->next) {
	    if (strcmp(((last)->data.data.fm.file), ((pf)->data.data.fm.file)) != 0)
		break;
	    nalloc += ((pf)->data.data.nalloc);
	    alloc += ((last)->data.data.alloc);
	    nfree += ((last)->data.data.nfree);
	    free += ((last)->data.data.free);
	}
	(bufp >= endbuf ? (write(fd,buf,bufp-buf), bufp=buf) : bufp);
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, "file", '=');
	bufp = (*(_Vmextern.vm_strcpy)) (bufp, ((pf)->data.data.fm.file)[0] ? ((pf)->data.data.fm.file) : "<>", ':');
	bufp = pfsummary(bufp, nalloc, alloc, nfree, free, 0, 0);

	while (pf != last) {	/* detailed data */
	    (bufp >= endbuf ? (write(fd,buf,bufp-buf), bufp=buf) : bufp);
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "\tline", '=');
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) (((pf)->line), -1), ':');
	    bufp = (*(_Vmextern.vm_strcpy)) (bufp, "region", '=');
	    bufp =
		(*(_Vmextern.vm_strcpy)) (bufp, (*(_Vmextern.vm_itoa)) (((Vmulong_t)((char*)(((pf)->data.data.vm)) - (char*)0) ), 0), ':');
	    bufp =
		pfsummary(bufp, ((pf)->data.data.nalloc), ((pf)->data.data.alloc), ((pf)->data.data.nfree),
			  ((pf)->data.data.free), 0, 0);

	    /* reinsert into hash table */
	    next = pf->next;
	    n = (int) (((pf)->data.data.hash) % 1019);
	    pf->next = Pftable[n];
	    Pftable[n] = pf;
	    pf = next;
	}
    }

    (bufp > buf ? write(fd,buf,bufp-buf) : 0);
    return 0;
}


static Void_t *pfalloc(Vmalloc_t * vm, size_t size)





{
    register size_t s;
    register Void_t *data;
    register char *file;
    register int line;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );
    if (!(vd->mode & 0000001) && ((0) ? 0 : ((vd)->mode & 0020000) ))
	return ((Void_t *)0);
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    s = (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + sizeof(Head_t);
    if (!(data = ((((vm)->data)->mode |= 0040000), (*(Vmbest->allocf))((vm),(s)) )))
	goto done;

    pfsetinfo(vm, (Vmuchar_t *) data, size, file, line);

    if (!(vd->mode & 0000001) && (vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), (Vmuchar_t *) data, size, 0);
    }
  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return data;
}


static int pffree(Vmalloc_t * vm, Void_t * data)





{
    register Pfobj_t *pf;
    register size_t s;
    register char *file;
    register int line;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (!data)
	return 0;

    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    if (((((vm)->data)->mode |= 0040000), Vmbest->addrf((vm),(data)) ) != 0) {
	if (vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, data, vm->disc);
	((0) ? 0 : ((vd)->mode &= ~0020000) );
	return -1;
    }

    pf = (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.seg.pf);
    s = (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.size.size);
    if (pf) {
	((pf)->data.data.nfree) += 1;
	((pf)->data.data.free) += s;
	pf = ((pf)->data.data.region);
	((pf)->data.data.nfree) += 1;
	((pf)->data.data.free) += s;
    }

    if (!(vd->mode & 0000001) && (vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) data, ((Vmuchar_t *)0), s, 0);
    }

    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return (*(Vmbest->freef)) (vm, data);
}


static Void_t *pfresize(Vmalloc_t * vm, Void_t * data, size_t size,
			int type)







{
    register Pfobj_t *pf;
    register size_t s, news;
    register Void_t *addr;
    register char *file;
    register int line;
    register size_t oldsize;
    register Vmdata_t *vd = vm->data;

    if (!data) {
	oldsize = 0;
	addr = pfalloc(vm, size);
	goto done;
    }
    if (size == 0) {
	(void) pffree(vm, data);
	return ((Void_t *)0);
    }

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );
    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    if (((((vm)->data)->mode |= 0040000), Vmbest->addrf((vm),(data)) ) != 0) {
	if (vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, data, vm->disc);
	((0) ? 0 : ((vd)->mode &= ~0020000) );
	return ((Void_t *)0);
    }

    pf = (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.seg.pf);
    s = oldsize = (((Head_t*)((Vmuchar_t*)(data)+(((((Block_t*)((char*)(data) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.size.size);

    news = (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + sizeof(Head_t);
    if ((addr =
	 ((((vm)->data)->mode |= 0040000), 
 Vmbest->resizef((vm),(data),(news),((type & ~0000004))) ))) {
	if (pf) {
	    ((pf)->data.data.free) += s;
	    ((pf)->data.data.nfree) += 1;
	    pf = ((pf)->data.data.region);
	    ((pf)->data.data.free) += s;
	    ((pf)->data.data.nfree) += 1;
	    pfsetinfo(vm, (Vmuchar_t *) addr, size, file, line);
	}

	if (!(vd->mode & 0000001) && (vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	    vm->file = file;
	    vm->line = line;
	    (*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) data, (Vmuchar_t *) addr, size,
			 0);
	}
    } else if (pf) {		/* reset old info */
	((pf)->data.data.alloc) -= s;
	((pf)->data.data.nalloc) -= 1;
	pf = ((pf)->data.data.region);
	((pf)->data.data.alloc) -= s;
	((pf)->data.data.nalloc) -= 1;
	file = ((pf)->data.data.fm.file);
	line = ((pf)->line);
	pfsetinfo(vm, (Vmuchar_t *) data, s, file, line);
    }

    ((0) ? 0 : ((vd)->mode &= ~0020000) );

  done:if (addr && (type & 0000004) && oldsize < size) {
	register Vmuchar_t *d = (Vmuchar_t *) addr + oldsize, *ed =
	    (Vmuchar_t *) addr + size;
	do {
	    *d++ = 0;
	} while (d < ed);
    }

    return addr;
}


static long pfsize(Vmalloc_t * vm, Void_t * addr)





{
    return (*Vmbest->addrf) (vm, addr) != 0 ? -1L : (long) (((Head_t*)((Vmuchar_t*)(addr)+(((((Block_t*)((char*)(addr) - sizeof(Head_t)) ))->head.head.size.size)&~(07))-sizeof(Head_t)) )->head.size.size);
}


static long pfaddr(Vmalloc_t * vm, Void_t * addr)





{
    return (*Vmbest->addrf) (vm, addr);
}


static int pfcompact(Vmalloc_t * vm)




{
    return (*Vmbest->compactf) (vm);
}


static Void_t *pfalign(Vmalloc_t * vm, size_t size, size_t align)






{
    register size_t s;
    register Void_t *data;
    register char *file;
    register int line;
    register Vmdata_t *vd = vm->data;

    ((file) = (vm)->file, (vm)->file = ((char*)0), (line) = (vm)->line, (vm)->line = 0 );

    if (!(vd->mode & 0000001) && ((0) ? 0 : ((vd)->mode & 0020000) ))
	return ((Void_t *)0);
    ((0) ? 0 : ((vd)->mode |= 0020000) );

    s = (size <= (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) ? (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) + sizeof(Head_t);
    if (!(data = ((((vm)->data)->mode |= 0040000), Vmbest->alignf((vm),(s),(align)) )))
	goto done;

    pfsetinfo(vm, (Vmuchar_t *) data, size, file, line);

    if (!(vd->mode & 0000001) && (vd->mode & 0000002) && (_Vmextern.vm_trace)) {
	vm->file = file;
	vm->line = line;
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), (Vmuchar_t *) data, size,
		     align);
    }
  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return data;
}

static Vmethod_t _Vmprofile = {
    pfalloc,
    pfresize,
    pffree,
    pfaddr,
    pfsize,
    pfcompact,
    pfalign,
    0002000
};

__DEFINE__(Vmethod_t *, Vmprofile, &_Vmprofile);
