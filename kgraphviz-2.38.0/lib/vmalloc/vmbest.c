#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmbest.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\vmalloc\\vmbest.c" 2

/* for VirtualAlloc and friends */




/*	Best-fit allocation method. This is based on a best-fit strategy
**	using a splay tree for storage of lists of free blocks of the same
**	size. Recent free blocks may be cached for fast reuse.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/



























    

    
	
	    
    
	
    
	
    











    
    

    
	
    
	
	    
		
    
	

    










    

      

    
	 
	  
    
    
	 
	
    
    
	 
	
    
    










    
	
	    
    











    
    
    

    
	

      
      

    
    
    
	
	
	
	    
	    

	    
		 
		  
		  
		  
		  
		  
		  
			     
		
		
		
		    

		
		    
			
			    
		
		
		     
		    
		
		
		    

		  
	    
		 
		  
		
		
		
		    

		
		    
		
		    
			
			    
		
		
		    
			
		  
	    
		 
		  
		  
		
		
		    
		
	    
	  
	    
	
    

    



/* Tree rotation functions */




/* Find and delete a suitable element in the free tree. */

static Block_t *bestsearch(Vmdata_t * vd, register size_t size,
			   Block_t * wanted)






{
    register size_t s;
    register Block_t *t, *root, *l, *r;
    Block_t link;

    /* extracting a tiniest block from its list */
    if ((root = wanted) && size == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) {
	register Seg_t *seg;

	l = ((root)->head.head.seg.link);
	if ((r = ((root)->body.body.link)))
	    ((r)->head.head.seg.link) = l;
	if (l)
	    ((l)->body.body.link) = r;
	else
	    ((vd)->tiny)[0] = r;

	seg = vd->seg;
	if (!seg->next)
	    ((root)->head.head.seg.seg) = seg;
	else
	    for (;; seg = seg->next) {
		if ((Vmuchar_t *) root > (Vmuchar_t *) seg->addr &&
		    (Vmuchar_t *) root < seg->baddr) {
		    ((root)->head.head.seg.seg) = seg;
		    break;
		}
	    }

	return root;
    }

    /**/ ;

    /* find the right one to delete */
    l = r = &link;
    if ((root = vd->root))
	do {
	    /**/ ;
	    if (size == (s = ((root)->head.head.size.size)))
		break;
	    if (size < s) {
		if ((t = ((root)->body.body.left))) {
		    if (size <= (s = ((t)->head.head.size.size))) {
			(((root)->body.body.left) = ((t)->body.body.right), ((t)->body.body.right) = (root), (root) = (t));
			if (size == s)
			    break;
			t = ((root)->body.body.left);
		    } else {
			((l) = ((l)->body.body.right) = (t));
			t = ((t)->body.body.right);
		    }
		}
		((r) = ((r)->body.body.left) = (root));
	    } else {
		if ((t = ((root)->body.body.right))) {
		    if (size >= (s = ((t)->head.head.size.size))) {
			(((root)->body.body.right) = ((t)->body.body.left), ((t)->body.body.left) = (root), (root) = (t));
			if (size == s)
			    break;
			t = ((root)->body.body.right);
		    } else {
			((r) = ((r)->body.body.left) = (t));
			t = ((t)->body.body.left);
		    }
		}
		((l) = ((l)->body.body.right) = (root));
	    }
	     /**/ ;
	} while ((root = t));

    if (root) {			/* found it, now isolate it */
	((l)->body.body.right) = ((root)->body.body.left);
	((r)->body.body.left) = ((root)->body.body.right);
    } else {			/* nothing exactly fit    */
	((r)->body.body.left) = ((Block_t *)0);
	((l)->body.body.right) = ((Block_t *)0);

	/* grab the least one from the right tree */
	if ((root = ((&link)->body.body.left))) {
	    while ((t = ((root)->body.body.left)))
		(((root)->body.body.left) = ((t)->body.body.right), ((t)->body.body.right) = (root), (root) = (t));
	    ((&link)->body.body.left) = ((root)->body.body.right);
	}
    }

    if (root && (r = ((root)->body.body.link))) {	/* head of a link list, use next one for root */
	((r)->body.body.left) = ((&link)->body.body.right);
	((r)->body.body.right) = ((&link)->body.body.left);
    } else if (!(r = ((&link)->body.body.left)))
	r = ((&link)->body.body.right);
    else {			/* graft left tree to right tree */
	while ((t = ((r)->body.body.left)))
	    (((r)->body.body.left) = ((t)->body.body.right), ((t)->body.body.right) = (r), (r) = (t));
	((r)->body.body.left) = ((&link)->body.body.right);
    }
    vd->root = r;
    /**/ ;

     /**/ ;
    return root;
}

/* Reclaim all delayed free blocks into the free tree */

static int bestreclaim(register Vmdata_t * vd, Block_t * wanted, int c)






{
    register size_t size, s;
    register Block_t *fp, *np, *t, *list, **cache;
    register int n, count;
    register Seg_t *seg;
    Block_t tree;

     /**/ ;

    if ((fp = vd->free)) {
	((fp)->body.body.link) = *(cache = ((vd)->cache) + 7);
	*cache = fp;
	vd->free = ((Block_t *)0);
    }

    ((&tree)->body.body.link) = ((Block_t *)0);
    count = 0;
    for (n = 7; n >= c; --n) {
	list = *(cache = ((vd)->cache) + n);
	*cache = ((Block_t *)0);
	while ((fp = list)) {	/* Note that below here we allow ISJUNK blocks to be
				 ** forward-merged even though they are not removed from
				 ** the list immediately. In this way, the list is
				 ** scanned only once. It works because the LINK and SIZE
				 ** fields are not destroyed during the merging. This can
				 ** be seen by observing that a tiniest block has a 2-word
				 ** header and a 2-word body. Merging a tiniest block
				 ** (1seg) and the next block (2seg) looks like this:
				 **     1seg  size  link  left  2seg size link left ....
				 **     1seg  size  link  left  rite xxxx xxxx .... self
				 ** After the merge, the 2seg word is replaced by the RIGHT
				 ** pointer of the new block and somewhere beyond the
				 ** two xxxx fields, the SELF pointer will replace some
				 ** other word. The important part is that the two xxxx
				 ** fields are kept intact.
				 */
	    count += 1;
	    list = ((list)->body.body.link);
	    /**/ ;

	    size = ((fp)->head.head.size.size);
	    if (!((size) & (04)))	/* already done */
		continue;

	    /* see if this address is from region */
	    for (seg = vd->seg; seg; seg = seg->next)
		if (fp >= ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))) && fp < (Block_t *) seg->baddr)
		    break;
	    if (!seg) {		/* must be a bug in application code! */
		/**/ ;
		continue;
	    }

	    if (((size) & (02))) {	/* backward merge */
		fp = (*((Block_t**)(((char*)(fp)) - sizeof(Block_t*)) ) );
		s = ((fp)->head.head.size.size);
		((!(((fp)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((fp)->body.body.right) == (fp) )) ? (((((t)) = (((fp))->body.body.link)) ? ((((t))->body.body.left) = (((fp))->body.body.left)) : ((Block_t*)0) ), ((((t)) = (((fp))->body.body.left)) ? ((((t))->body.body.link) = (((fp))->body.body.link)) : ((((vd))->tiny)[(((sizeof(struct _align_s)) == 8 ?(((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))>>3) :((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))/(sizeof(struct _align_s))))] = (((fp))->body.body.link)) ) ) : bestsearch((vd),((fp)->head.head.size.size),(fp)) );
		size = (size & ~(07)) + s + sizeof(Head_t);
	    } else
		size &= ~(07);

	    for (;;) {		/* forward merge */
		np = (Block_t *) ((Vmuchar_t *) fp + size +
				  sizeof(Head_t));
		s = ((np)->head.head.size.size);
		/**/ ;
		if (!((s) & (01))) {
		    if (np == vd->wild)
			vd->wild = ((Block_t *)0);
		    else
			((!(((np)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((np)->body.body.right) == (np) )) ? (((((t)) = (((np))->body.body.link)) ? ((((t))->body.body.left) = (((np))->body.body.left)) : ((Block_t*)0) ), ((((t)) = (((np))->body.body.left)) ? ((((t))->body.body.link) = (((np))->body.body.link)) : ((((vd))->tiny)[(((sizeof(struct _align_s)) == 8 ?(((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))>>3) :((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))/(sizeof(struct _align_s))))] = (((np))->body.body.link)) ) ) : bestsearch((vd),((np)->head.head.size.size),(np)) );
		} else if (((s) & (04))) {
		    if ((int) (s < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7) < c)
			c = (s < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7);
		    ((np)->head.head.size.size) = 0;
		    ((s) &= ~(07));
		} else
		    break;
		size += s + sizeof(Head_t);
	    }
	    ((fp)->head.head.size.size) = size;

	    if (fp == wanted)	/* about to be consumed by bestresize */
		continue;

	    /* tell next block that this one is free */
	    ((((np)->head.head.size.size)) |= (02));
	    /**/ ;
	    *(((Block_t**)((fp)->body.data + ((fp)->head.head.size.size) - sizeof(Block_t*)) )) = fp;

	    if (np->body.data >= vd->seg->baddr) {
		vd->wild = fp;
		continue;
	    }

	    /* tiny block goes to tiny list */
	    if (size < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))) {
		s = ((sizeof(struct _align_s)) == 8 ? (((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) );
		np = ((fp)->body.body.link) = ((vd)->tiny)[s];
		if (s == 0) {	/* TINIEST block */
		    if (np)
			((np)->head.head.seg.link) = fp;
		    ((fp)->head.head.seg.link) = ((Block_t *)0);
		} else {
		    if (np)
			((np)->body.body.left) = fp;
		    ((fp)->body.body.left) = ((Block_t *)0);
		    (((fp)->body.body.right) = (fp) );
		}
		((vd)->tiny)[s] = fp;
		continue;
	    }

	    /* don't put in free tree yet because they may be merged soon */
	    np = &tree;
	    if ((((fp)->body.body.link) = ((np)->body.body.link)))
		((((fp)->body.body.link))->body.body.left) = fp;
	    ((np)->body.body.link) = fp;
	    ((fp)->body.body.left) = np;
	    (((fp)->body.body.right) = (fp) );
	}
    }

    /* insert all free blocks into the free tree */
    for (list = ((&tree)->body.body.link); list;) {
	fp = list;
	list = ((list)->body.body.link);

	 /**/ ;
	 /**/ ;
	 /**/ ;
	((fp)->body.body.left) = ((fp)->body.body.right) = ((fp)->body.body.link) = ((Block_t *)0);
	if (!(np = vd->root)) {	/* inserting into an empty tree   */
	    vd->root = fp;
	    continue;
	}

	size = ((fp)->head.head.size.size);
	while (1) {		/* leaf insertion */
	    /**/ ;
	    if ((s = ((np)->head.head.size.size)) > size) {
		if ((t = ((np)->body.body.left))) {
		    /**/ ;
		    np = t;
		} else {
		    ((np)->body.body.left) = fp;
		    break;
		}
	    } else if (s < size) {
		if ((t = ((np)->body.body.right))) {
		    /**/ ;
		    np = t;
		} else {
		    ((np)->body.body.right) = fp;
		    break;
		}
	    } else {		/* s == size */
		if ((t = ((np)->body.body.link))) {
		    ((fp)->body.body.link) = t;
		    ((t)->body.body.left) = fp;
		}
		((np)->body.body.link) = fp;
		((fp)->body.body.left) = np;
		(((fp)->body.body.right) = (fp) );
		break;
	    }
	}
    }

     /**/ ;
    return count;
}


static Void_t *bestalloc(Vmalloc_t * vm, register size_t size)





{
    register Vmdata_t *vd = vm->data;
    register size_t s;
    register Block_t *tp, *np, **cache;
    register int local;
    size_t orgsize = 0;

     /**/ ;

    if (!(local = vd->mode & 0000001)) {
	(((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
	if (((local) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	((local) ? 0 : ((vd)->mode |= 0020000) );
	orgsize = size;
    }

    /**/ ;
     /**/ ;
     /**/ ;
     /**/ ;
     /**/ ;
     /**/ ;
     /**/ ;

    /* for ANSI requirement that malloc(0) returns non-NULL pointer */
    size = size <= (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) ? (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );

    if (size < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (tp = *(cache = ((vd)->cache) + ((sizeof(struct _align_s)) == 8 ? (((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) )))) {
	*cache = ((tp)->body.body.link);
	((((tp)->head.head.size.size)) &= ~(04));
	 /**/ ;
	goto done;
    }

    if ((tp = vd->free)) {	/* allocate from last free piece */
	/**/ ;
	 /**/ ;
	 /**/ ;

	vd->free = ((Block_t *)0);
	if ((s = ((tp)->head.head.size.size)) < size) {
	    ((tp)->body.body.link) = *(cache = ((vd)->cache) + 7);
	    *cache = tp;
	} else {
	    if (s >= size + (sizeof(Head_t) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))) {
		((tp)->head.head.size.size) = size;
		np = ((Block_t*)((tp)->body.data + ((tp)->head.head.size.size)) );
		((np)->head.head.seg.seg) = ((tp)->head.head.seg.seg);
		((np)->head.head.size.size) =
		    ((s & ~(07)) - (size + sizeof(Head_t))) | (04) | (01);
		vd->free = np;
		((tp)->head.head.size.size) |= s & (07);
	    }
	    ((((tp)->head.head.size.size)) &= ~(04));
	    goto done;
	}
    }

    for (;;) {
	for (;;) {		/* best-fit - more or less */
	    for (s = ((sizeof(struct _align_s)) == 8 ? (((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ); s < 7; ++s) {
		if ((tp = ((vd)->tiny)[s])) {
		    ((!(((tp)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((tp)->body.body.right) == (tp) )) ? (((((np)) = (((tp))->body.body.link)) ? ((((np))->body.body.left) = (((tp))->body.body.left)) : ((Block_t*)0) ), ((((np)) = (((tp))->body.body.left)) ? ((((np))->body.body.link) = (((tp))->body.body.link)) : ((((vd))->tiny)[(s)] = (((tp))->body.body.link)) ) ) : bestsearch((vd),((tp)->head.head.size.size),(tp)) );
		    ((((((Block_t*)((tp)->body.data + ((tp)->head.head.size.size)) ))->head.head.size.size)) &= ~(02));
		    goto got_block;
		}
	    }

	    if (((vd)->cache)[7])	/* reclaim big pieces */
		bestreclaim(vd, ((Block_t *)0), 7);
	    if (vd->root && (tp = bestsearch(vd, size, ((Block_t *)0))))
		goto got_block;
	    if (bestreclaim(vd, ((Block_t *)0), 0) == 0)
		break;
	}

	 /**/ ;
	if ((tp = vd->wild) && ((tp)->head.head.size.size) >= size) {
	    /**/ ;
	     /**/ ;
	    vd->wild = ((Block_t *)0);
	    goto got_block;
	}

	/**/ ;
	if ((tp = (*(_Vmextern.vm_extend)) (vm, size, bestsearch)))
	    goto got_block;
	else if (vd->mode & 0010000)
	    vd->mode &= ~0010000;
	else {
	    ((local) ? 0 : ((vd)->mode &= ~0020000) );
	    return ((Void_t *)0);
	}
    }

  got_block:
     /**/ ;
     /**/ ;
     /**/ ;
     /**/ ;

    /* tell next block that we are no longer a free block */
    ((((((Block_t*)((tp)->body.data + ((tp)->head.head.size.size)) ))->head.head.size.size)) &= ~(02));
    /**/ ;

    if ((s = ((tp)->head.head.size.size) - size) >= (sizeof(Head_t) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))) {
	((tp)->head.head.size.size) = size;

	np = ((Block_t*)((tp)->body.data + ((tp)->head.head.size.size)) );
	((np)->head.head.seg.seg) = ((tp)->head.head.seg.seg);
	((np)->head.head.size.size) = (s - sizeof(Head_t)) | (01) | (04);

	if (!vd->root || !(((np)->body.data+((np)->head.head.size.size)+sizeof(Head_t)) >= vd->seg->baddr))
	    vd->free = np;
	else {
	    ((np)->head.head.size.size) &= ~(07);
	    *((Block_t**)((np)->body.data + ((np)->head.head.size.size) - sizeof(Block_t*)) ) = np;
	    ((((((Block_t*)((np)->body.data + ((np)->head.head.size.size)) ))->head.head.size.size)) |= (02));
	    vd->wild = np;
	}
    }

    ((((tp)->head.head.size.size)) |= (01));

  done:
    if (!local && (vd->mode & 0000002) && (_Vmextern.vm_trace)
	&& ((vd)->mode&0003700) == 0000100)
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), (Vmuchar_t *) ((Void_t*)((tp)->body.data) ), orgsize,
		     0);

     /**/ ;

    ((local) ? 0 : ((vd)->mode &= ~0020000) );
    return ((Void_t*)((tp)->body.data) );
}


static long bestaddr(Vmalloc_t * vm, Void_t * addr)





{
    register Seg_t *seg;
    register Block_t *b, *endb;
    register long offset;
    register Vmdata_t *vd = vm->data;
    register int local;
    b = 0;
    endb = 0;

    if (!(local = vd->mode & 0000001)) {
	(((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
	if (((local) ? 0 : ((vd)->mode & 0020000) ))
	    return -1L;
	((local) ? 0 : ((vd)->mode |= 0020000) );
    }

    offset = -1L;
    for (seg = vd->seg; seg; seg = seg->next) {
	b = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	endb = (Block_t *) (seg->baddr - sizeof(Head_t));
	if ((Vmuchar_t *) addr > (Vmuchar_t *) b &&
	    (Vmuchar_t *) addr < (Vmuchar_t *) endb)
	    break;
    }

    if (local && !(vd->mode & 0000001)) {	/* from bestfree or bestresize */
	b = ((Block_t*)((char*)(addr) - sizeof(Head_t)) );
	if (seg && ((b)->head.head.seg.seg) == seg && ((((b)->head.head.size.size)) & (01)) && !((((b)->head.head.size.size)) & (04)))
	    offset = 0;
	if (offset != 0 && vm->disc->exceptf)
	    (void) (*vm->disc->exceptf) (vm, 3, addr, vm->disc);
    } else if (seg) {
	while (b < endb) {
	    register Vmuchar_t *data = (Vmuchar_t *) ((Void_t*)((b)->body.data) );
	    register size_t size = ((b)->head.head.size.size) & ~(07);

	    if ((Vmuchar_t *) addr >= data
		&& (Vmuchar_t *) addr < data + size) {
		if (((((b)->head.head.size.size)) & (04)) || !((((b)->head.head.size.size)) & (01)))
		    offset = -1L;
		else
		    offset = (Vmuchar_t *) addr - data;
		goto done;
	    }

	    b = (Block_t *) ((Vmuchar_t *) ((Void_t*)((b)->body.data) ) + size);
	}
    }

  done:
    ((local) ? 0 : ((vd)->mode &= ~0020000) );
    return offset;
}


static int bestfree(Vmalloc_t * vm, Void_t * data)





{
    register Vmdata_t *vd = vm->data;
    register Block_t *bp, **cache;
    register size_t s;
    register int local;

     /**/ ;

    if (!data)			/* ANSI-ism */
	return 0;

    if (!(local = vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1;
	if (((((vm)->data)->mode |= 0040000), bestaddr((vm),(data)) ) != 0)
	    return -1;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    bp = ((Block_t*)((char*)(data) - sizeof(Head_t)) );
    /**/ ;
    ((((bp)->head.head.size.size)) |= (04));
    if ((s = ((bp)->head.head.size.size)) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))) {
	/**/ ;
	((bp)->body.body.link) = *(cache = ((vd)->cache) + ((sizeof(struct _align_s)) == 8 ? (((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ));
	*cache = bp;
    } else if (!vd->free)
	vd->free = bp;
    else {
	/**/ ;
	((bp)->body.body.link) = *(cache = ((vd)->cache) + 7);
	*cache = bp;
    }

    /* coalesce large free blocks to avoid fragmentation */
    if (s >= (_Vmextern.vm_pagesize) && ((s) & (02)))
	bestreclaim(vd, ((Block_t *)0), 0);

    if (!local && (_Vmextern.vm_trace) && (vd->mode & 0000002)
	&& ((vd)->mode&0003700) == 0000100)
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) data, ((Vmuchar_t *)0), (s & ~(07)),
		     0);

     /**/ ;

    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return 0;
}


static Void_t *bestresize(Vmalloc_t * vm, Void_t * data, register size_t size,
			  int type)







{
    register Vmdata_t *vd = vm->data;
    register Block_t *rp, *np, *t, **cache;
    register size_t s, bs;
    register int local, *d, *ed;
    size_t oldsize = 0, orgsize = 0;
    Void_t *orgdata;
    orgdata = 0;

     /**/ ;

    if (!data) {
	if ((data = bestalloc(vm, size))) {
	    oldsize = 0;
	    size = size <= (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) ? (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );
	}
	goto done;
    }
    if (size == 0) {
	(void) bestfree(vm, data);
	return ((Void_t *)0);
    }

    if (!(local = vd->mode & 0000001)) {
	(((local) = (vd)->mode&0040000), ((vd)->mode &= ~0040000) );
	if (((local) ? 0 : ((vd)->mode & 0020000) ))
	    return ((Void_t *)0);
	if (!local && ((((vm)->data)->mode |= 0040000), bestaddr((vm),(data)) ) != 0)
	    return ((Void_t *)0);
	((local) ? 0 : ((vd)->mode |= 0020000) );

	orgdata = data;		/* for tracing */
	orgsize = size;
    }

    /**/ ;

    size = size <= (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) ? (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) : (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((size)) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((size)) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) );
    rp = ((Block_t*)((char*)(data) - sizeof(Head_t)) );
    /**/ ;
    if ((bs = oldsize = ((rp)->head.head.size.size)) < size) {
	((((rp)->head.head.size.size)) &= ~(07));
	np = ((Block_t*)((rp)->body.data + ((rp)->head.head.size.size)) );
	do {			/* forward merge as much as possible */
	    s = ((np)->head.head.size.size);
	    if (np == vd->free) {
		vd->free = ((Block_t *)0);
		((s) &= ~(07));
	    } else if (((s) & (04))) {
		((((rp)->head.head.size.size)) |= ((bs)&(07)) );
		bestreclaim(vd, np, (s < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7));
		s = ((np)->head.head.size.size);
		bs = ((rp)->head.head.size.size);
		((((rp)->head.head.size.size)) &= ~(07));
	    } else if (!((s) & (01))) {
		if (np == vd->wild)
		    vd->wild = ((Block_t *)0);
		else
		    ((!(((np)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((np)->body.body.right) == (np) )) ? (((((t)) = (((np))->body.body.link)) ? ((((t))->body.body.left) = (((np))->body.body.left)) : ((Block_t*)0) ), ((((t)) = (((np))->body.body.left)) ? ((((t))->body.body.link) = (((np))->body.body.link)) : ((((vd))->tiny)[(((sizeof(struct _align_s)) == 8 ?(((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))>>3) :((s)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))/(sizeof(struct _align_s))))] = (((np))->body.body.link)) ) ) : bestsearch((vd),((np)->head.head.size.size),(np)) );
	    } else
		break;

	    ((rp)->head.head.size.size) += (s += sizeof(Head_t));
	    np = (Block_t *) ((Vmuchar_t *) np + s);
	    ((((np)->head.head.size.size)) &= ~(02));
	} while (((rp)->head.head.size.size) < size);

	if (((rp)->head.head.size.size) < size && size > vd->incr && (((rp)->body.data+((rp)->head.head.size.size)+sizeof(Head_t)) >= ((rp)->head.head.seg.seg)->baddr)) {
	    register Seg_t *seg;

	    s = (size - ((rp)->head.head.size.size)) + sizeof(Head_t);
	    s = (((vd->incr)&((vd->incr)-1)) ? (((((s)) + (((vd->incr))-1)) / ((vd->incr))) * ((vd->incr))) : ((((s)) + (((vd->incr))-1)) & ~(((vd->incr))-1)) );
	    seg = ((rp)->head.head.seg.seg);
	    if ((*vm->disc->memoryf) (vm, seg->addr, seg->extent,
				      seg->extent + s,
				      vm->disc) == seg->addr) {
		((rp)->head.head.size.size) += s;
		seg->extent += s;
		seg->size += s;
		seg->baddr += s;
		((((Block_t*)((rp)->body.data + ((rp)->head.head.size.size)) ))->head.head.seg.seg) = seg;
		((((Block_t*)((rp)->body.data + ((rp)->head.head.size.size)) ))->head.head.size.size) = (01);
	    }
	}

	((((rp)->head.head.size.size)) |= ((bs)&(07)) );
    }

    /* If a buffer is resized, it is likely to be resized again.
       So we increase a bit more to reduce future work */
    bs = size < ((((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _body_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _body_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) << 1) ? size : size < 1024 ? (size >> 1) : 1024;
    if ((s = ((rp)->head.head.size.size)) >= (size + bs + ((((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ) + sizeof(Head_t)))) {
	((rp)->head.head.size.size) = size;
	np = ((Block_t*)((rp)->body.data + ((rp)->head.head.size.size)) );
	((np)->head.head.seg.seg) = ((rp)->head.head.seg.seg);
	((np)->head.head.size.size) = (((s & ~(07)) - size) - sizeof(Head_t)) | (01) | (04);
	((((rp)->head.head.size.size)) |= ((s)&(07)) );
	rp = np;
	goto do_free;
    } else if (s < size) {
	if (!(type & (0000002 | 0000001)))	/* see if old data is moveable */
	    data = ((Void_t *)0);
	else {
	    ed = (int *) data;
	    if (size < ((s & ~(07)) + bs))
		size = (s & ~(07)) + bs;
	    if ((data = ((((vm)->data)->mode |= 0040000), bestalloc((vm),(size)) ))) {
		if (type & 0000001) {	/* old data must be copied */
		    d = (int *) data;
		    switch(s/sizeof(int)) { default: memcpy((Void_t*)d,(Void_t*)ed,s); break; case 7: *d++ = *ed++; case 6: *d++ = *ed++; case 5: *d++ = *ed++; case 4: *d++ = *ed++; case 3: *d++ = *ed++; case 2: *d++ = *ed++; case 1: *d++ = *ed++; };
		}
	      do_free:		/* delay reusing these blocks as long as possible */
		((((rp)->head.head.size.size)) |= (04));
		((rp)->body.body.link) = *(cache = ((vd)->cache) + 7);
		*cache = rp;
		if ((rp = vd->free)) {
		    vd->free = ((Block_t *)0);
		    ((rp)->body.body.link) = *cache;
		    *cache = rp;
		}
	    }
	}
    }

    if (!local && (_Vmextern.vm_trace) && data && (vd->mode & 0000002)
	&& ((vd)->mode&0003700) == 0000100)
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) orgdata, (Vmuchar_t *) data,
		     orgsize, 0);
    ((local) ? 0 : ((vd)->mode &= ~0020000) );

  done:if (data && (type & 0000004) && size > ((oldsize) &= ~(07))) {
	d = (int *) ((char *) data + oldsize);
	size -= oldsize;
	switch(size/sizeof(int)) { default: memset((Void_t*)d,0,size); break; case 7: *d++ = 0; case 6: *d++ = 0; case 5: *d++ = 0; case 4: *d++ = 0; case 3: *d++ = 0; case 2: *d++ = 0; case 1: *d++ = 0; };
    }

    /**/ ;

    return data;
}


static long bestsize(Vmalloc_t * vm, Void_t * addr)





{
    register Seg_t *seg;
    register Block_t *b, *endb;
    register long size;
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1L;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    size = -1L;
    for (seg = vd->seg; seg; seg = seg->next) {
	b = ((Block_t*)(((Vmuchar_t*)(seg)) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(Seg_t))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )));
	endb = (Block_t *) (seg->baddr - sizeof(Head_t));
	if ((Vmuchar_t *) addr <= (Vmuchar_t *) b ||
	    (Vmuchar_t *) addr >= (Vmuchar_t *) endb)
	    continue;
	while (b < endb) {
	    if (addr == ((Void_t*)((b)->body.data) )) {
		if (!((((b)->head.head.size.size)) & (01)) || ((((b)->head.head.size.size)) & (04)))
		    size = -1L;
		else
		    size = (long) ((b)->head.head.size.size) & ~(07);
		goto done;
	    } else if ((Vmuchar_t *) addr <= (Vmuchar_t *) b)
		break;

	    b = (Block_t *) ((Vmuchar_t *) ((Void_t*)((b)->body.data) ) + (((b)->head.head.size.size) & ~(07)));
	}
    }

  done:
    ((0) ? 0 : ((vd)->mode &= ~0020000) );
    return size;
}


static int bestcompact(Vmalloc_t * vm)




{
    register Seg_t *seg, *next;
    register Block_t *bp, *t;
    register size_t size, segsize;
    register Vmdata_t *vd = vm->data;

    if (!(vd->mode & 0000001)) {
	if (((0) ? 0 : ((vd)->mode & 0020000) ))
	    return -1;
	((0) ? 0 : ((vd)->mode |= 0020000) );
    }

    bestreclaim(vd, ((Block_t *)0), 0);
    /**/ ;

    for (seg = vd->seg; seg; seg = next) {
	next = seg->next;

	bp = ((Block_t*)((char*)(seg->baddr) - sizeof(Head_t)) );
	if (!((((bp)->head.head.size.size)) & (02)))
	    continue;

	bp = (*((Block_t**)(((char*)(bp)) - sizeof(Block_t*)) ) );
	/**/ ;
	size = ((bp)->head.head.size.size);
	if (bp == vd->wild)
	    vd->wild = ((Block_t *)0);
	else
	    ((!(((bp)->head.head.size.size) == (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) && (((bp)->body.body.right) == (bp) )) ? (((((t)) = (((bp))->body.body.link)) ? ((((t))->body.body.left) = (((bp))->body.body.left)) : ((Block_t*)0) ), ((((t)) = (((bp))->body.body.left)) ? ((((t))->body.body.link) = (((bp))->body.body.link)) : ((((vd))->tiny)[(((sizeof(struct _align_s)) == 8 ?(((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))>>3) :((size)-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ?(((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) /((sizeof(struct _align_s)))) *((sizeof(struct _align_s)))) :((((sizeof(struct _tiny_s))) +(((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1))))/(sizeof(struct _align_s))))] = (((bp))->body.body.link)) ) ) : bestsearch((vd),((bp)->head.head.size.size),(bp)) );
	((((((Block_t*)((bp)->body.data + ((bp)->head.head.size.size)) ))->head.head.size.size)) &= ~(02));

	if (size < (segsize = seg->size))
	    size += sizeof(Head_t);

	if ((*(_Vmextern.vm_truncate)) (vm, seg, size, 1) >= 0) {
	    if (size >= segsize)	/* entire segment deleted */
		continue;

	    if ((size =
		 (seg->baddr - ((Vmuchar_t *) bp) - sizeof(Head_t))) > 0)
		((bp)->head.head.size.size) = size - sizeof(Head_t);
	    else
		bp = ((Block_t *)0);
	}
	/**/ ;

	if (bp) {
	    /**/ ;
	     /**/ ;
	     /**/ ;
	    ((bp)->head.head.size.size) |= (01) | (04);
	    ((bp)->body.body.link) = ((vd)->cache)[(((bp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)];
	    ((vd)->cache)[(((bp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((bp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)] = bp;
	}
	/**/ ;
    }
    /**/ ;

    if ((_Vmextern.vm_trace) && (vd->mode & 0000002) && ((vd)->mode&0003700) == 0000100)
	(*(_Vmextern.vm_trace)) (vm, (Vmuchar_t *) 0, (Vmuchar_t *) 0, 0, 0);

    ((0) ? 0 : ((vd)->mode &= ~0020000) );

    return 0;
}


static Void_t *bestalign(Vmalloc_t * vm, size_t size, size_t align)






{
    register Vmuchar_t *data;
    register Block_t *tp, *np;
    register Seg_t *seg;
    register size_t s, orgsize = 0, orgalign = 0, extra;
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

    /* hack so that dbalign() can store header data */
    if (((vd)->mode&0003700) != 0001000)
	extra = 0;
    else {
	extra = (2*sizeof(Head_t));
	while (align < extra || (align - extra) < sizeof(Block_t))
	    align *= 2;
    }

    /* reclaim all free blocks now to avoid fragmentation */
    bestreclaim(vd, ((Block_t *)0), 0);

    s = size + 2 * (align + sizeof(Head_t) + extra);
    if (!(data = (Vmuchar_t *) ((((vm)->data)->mode |= 0040000), bestalloc((vm),(s)) )))
	goto done;

    tp = ((Block_t*)((char*)(data) - sizeof(Head_t)) );
    seg = ((tp)->head.head.seg.seg);

    /* get an aligned address that we can live with */
    if ((s = (size_t) ((((Vmulong_t)((char*)(data) - (char*)0) ) + extra) % align)) != 0)
	data += align - s;
    /**/ ;

    if ((np = ((Block_t*)((char*)(data) - sizeof(Head_t)) )) != tp) {	/* need to free left part */
	if (((Vmuchar_t *) np - (Vmuchar_t *) tp) <
	    (ssize_t) (sizeof(Block_t) + extra)) {
	    data += align;
	    np = ((Block_t*)((char*)(data) - sizeof(Head_t)) );
	}
	/**/ ;

	s = (Vmuchar_t *) np - (Vmuchar_t *) tp;
	((np)->head.head.size.size) = ((((tp)->head.head.size.size) & ~(07)) - s) | (01);
	((np)->head.head.seg.seg) = seg;

	((tp)->head.head.size.size) = (s - sizeof(Head_t)) | (((tp)->head.head.size.size) & (07)) | (04);
	 /**/ ;
	((tp)->body.body.link) = ((vd)->cache)[(((tp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)];
	((vd)->cache)[(((tp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)] = tp;
    }

    /* free left-over if too big */
    if ((s = ((np)->head.head.size.size) - size) >= sizeof(Block_t)) {
	((np)->head.head.size.size) = size;

	tp = ((Block_t*)((np)->body.data + ((np)->head.head.size.size)) );
	((tp)->head.head.size.size) = ((s & ~(07)) - sizeof(Head_t)) | (01) | (04);
	((tp)->head.head.seg.seg) = seg;
	((tp)->body.body.link) = ((vd)->cache)[(((tp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)];
	((vd)->cache)[(((tp)->head.head.size.size) < (7*sizeof(struct _align_s) + (((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) )) ? ((sizeof(struct _align_s)) == 8 ? (((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))>>3) : ((((tp)->head.head.size.size))-(((sizeof(struct _align_s))&((sizeof(struct _align_s))-1)) ? (((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) / ((sizeof(struct _align_s)))) * ((sizeof(struct _align_s)))) : ((((sizeof(struct _tiny_s))) + (((sizeof(struct _align_s)))-1)) & ~(((sizeof(struct _align_s)))-1)) ))/(sizeof(struct _align_s)) ) : 7)] = tp;

	((np)->head.head.size.size) |= s & (07);
    }

    bestreclaim(vd, ((Block_t *)0), 0);	/* coalesce all free blocks */

    if (!local && !(vd->mode & 0000001) && (_Vmextern.vm_trace)
	&& (vd->mode & 0000002))
	(*(_Vmextern.vm_trace)) (vm, ((Vmuchar_t *)0), data, orgsize, orgalign);

  done:
    ((local) ? 0 : ((vd)->mode &= ~0020000) );

     /**/ ;

    return (Void_t *) data;
}

/*	A discipline to get memory using sbrk() or VirtualAlloc on win32 */

static Void_t *sbrkmem(Vmalloc_t * vm, Void_t * caddr,
		       size_t csize, size_t nsize, Vmdisc_t * disc)








{

    
    

    
	
    
	
    


    
    

    
	
				       
    
	
			   
    
	

    register Vmuchar_t *addr;
    register ssize_t size;
    (void)(vm);
    (void)(disc);

    /* sbrk, see if still own current address */
    if (csize > 0 && sbrk(0) != (Vmuchar_t *) caddr + csize)
	return ((Void_t *)0);

    /* do this because sbrk() uses 'ssize_t' argument */
    size =
	nsize >
	csize ? (ssize_t) (nsize - csize) : -(ssize_t) (csize - nsize);

    if ((addr = sbrk(size)) == (Vmuchar_t *) (-1))
	return ((Void_t *)0);
    else
	return csize == 0 ? (Void_t *) addr : caddr;


}

static Vmdisc_t _Vmdcsbrk = { sbrkmem, ((Vmexcept_f)0), 0 };

static Vmethod_t _Vmbest = {
    bestalloc,
    bestresize,
    bestfree,
    bestaddr,
    bestsize,
    bestcompact,
    bestalign,
    0000100
};

/* The heap region */
static Vmdata_t _Vmdata = {
    0000100 | 0000001,	/* mode         */
    0,				/* incr         */
    0,				/* pool         */
    ((Seg_t *)0),		/* seg          */
    ((Block_t *)0),		/* free         */
    ((Block_t *)0),		/* wild         */
    ((Block_t *)0),		/* root         */
};
static Vmalloc_t _Vmheap = {
    {bestalloc,
     bestresize,
     bestfree,
     bestaddr,
     bestsize,
     bestcompact,
     bestalign,
     0000100},
    ((char *)0),		/* file         */
    0,				/* line         */
    &_Vmdcsbrk,			/* disc         */
    &_Vmdata,			/* data         */
    ((Vmalloc_t *)0)		/* next             */
};

__DEFINE__(Vmalloc_t *, Vmheap, &_Vmheap);
__DEFINE__(Vmalloc_t *, Vmregion, &_Vmheap);
__DEFINE__(Vmethod_t *, Vmbest, &_Vmbest);
__DEFINE__(Vmdisc_t *, Vmdcsbrk, &_Vmdcsbrk);
