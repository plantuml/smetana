#line 1 "graphviz-2.38.0\\lib\\vmalloc\\malloc.c" 1
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




#line 16 "graphviz-2.38.0\\lib\\vmalloc\\malloc.c" 2





/*	malloc compatibility functions.
**	These are aware of debugging/profiling and driven by the environment variables:
**	VMETHOD: select an allocation method by name.
**
**	VMPROFILE: if is a file name, write profile data to it.
**	VMTRACE: if is a file name, write trace data to it.
**	The pattern %p in a file name will be replaced by the process ID.
**
**	VMDEBUG:
**		a:			abort on any warning
**		[decimal]:		period to check arena.
**		0x[hexadecimal]:	address to watch.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/
























static Vmulong_t atou(char **sp)




{
    char *s = *sp;
    Vmulong_t v = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
	for (s += 2; *s; ++s) {
	    if (*s >= '0' && *s <= '9')
		v = (v << 4) + (*s - '0');
	    else if (*s >= 'a' && *s <= 'f')
		v = (v << 4) + (*s - 'a') + 10;
	    else if (*s >= 'A' && *s <= 'F')
		v = (v << 4) + (*s - 'A') + 10;
	    else
		break;
	}
    } else {
	for (; *s; ++s) {
	    if (*s >= '0' && *s <= '9')
		v = v * 10 + (*s - '0');
	    else
		break;
	}
    }

    *sp = s;
    return v;
}

static int _Vmflinit = 0;
static Vmulong_t _Vmdbcheck = 0;
static Vmulong_t _Vmdbtime = 0;
static int _Vmpffd = -1;








static char *insertpid(char *begs, char *ends)





{
    int pid;
    char *s;

    if ((pid = getpid()) < 0)
	return ((char *)0);

    s = ends;
    do {
	if (s == begs)
	    return ((char *)0);
	*--s = '0' + pid % 10;
    } while ((pid /= 10) > 0);
    while (s < ends)
	*begs++ = *s++;

    return begs;
}


static int createfile(char *file)




{
    char buf[1024];
    char *next, *endb;

    next = buf;
    endb = buf + sizeof(buf);
    while (*file) {
	if (*file == '%') {
	    switch (file[1]) {
	    case 'p':
		if (!(next = insertpid(next, endb)))
		    return -1;
		file += 2;
		break;
	    default:
		goto copy;
	    }
	} else {
	  copy:
	    *next++ = *file++;
	}

	if (next >= endb)
	    return -1;
    }

    *next = '\0';

    

    return creat(buf, 0644);

}


static void pfprint(void)



{
    if (Vmregion->meth.meth == 0002000)
	vmprofile(Vmregion, _Vmpffd);
}


static int vmflinit(void)



{
    char *env;
    Vmalloc_t *vm;
    int fd;
    Vmulong_t addr;
    char *file;
    int line;

    /* this must be done now to avoid any inadvertent recursion (more below) */
    _Vmflinit = 1;
    ((file) = (Vmregion)->file, (Vmregion)->file = ((char*)0), (line) = (Vmregion)->line, (Vmregion)->line = 0 );

    /* if getenv() calls malloc(), this may not be caught by the eventual region */
    vm = ((Vmalloc_t *)0);
    if ((env = getenv("VMETHOD"))) {
	if (strcmp(env, "Vmdebug") == 0 || strcmp(env, "vmdebug") == 0)
	    vm = vmopen(Vmdcsbrk, Vmdebug, 0);
	else if (strcmp(env, "Vmprofile") == 0
		 || strcmp(env, "vmprofile") == 0)
	    vm = vmopen(Vmdcsbrk, Vmprofile, 0);
	else if (strcmp(env, "Vmlast") == 0 || strcmp(env, "vmlast") == 0)
	    vm = vmopen(Vmdcsbrk, Vmlast, 0);
	else if (strcmp(env, "Vmpool") == 0 || strcmp(env, "vmpool") == 0)
	    vm = vmopen(Vmdcsbrk, Vmpool, 0);
	else if (strcmp(env, "Vmbest") == 0 || strcmp(env, "vmbest") == 0)
	    vm = Vmheap;
    }

    if ((!vm || vm->meth.meth == 0001000) &&
	(env = getenv("VMDEBUG")) && env[0]) {
	if (vm || (vm = vmopen(Vmdcsbrk, Vmdebug, 0))) {
	    register int setcheck = 0;

	    while (*env) {
		if (*env == 'a')
		    vmset(vm, 0000010, 1);

		if (*env < '0' || *env > '9')
		    env += 1;
		else if (env[0] == '0' && (env[1] == 'x' || env[1] == 'X')) {
		    if ((addr = atou(&env)) != 0)
			vmdbwatch((Void_t *) addr);
		} else {
		    _Vmdbcheck = atou(&env);
		    setcheck = 1;
		}
	    }
	    if (!setcheck)
		_Vmdbcheck = 1;
	}
    }

    if ((!vm || vm->meth.meth == 0002000) &&
	(env = getenv("VMPROFILE")) && env[0]) {
	_Vmpffd = createfile(env);
	if (!vm)
	    vm = vmopen(Vmdcsbrk, Vmprofile, 0);
    }

    /* slip in the new region now so that malloc() will work fine */
    if (vm)
	Vmregion = vm;

    /* turn on tracing if requested */
    if ((env = getenv("VMTRACE")) && env[0] && (fd = createfile(env)) >= 0) {
	vmset(Vmregion, 0000002, 1);
	vmtrace(fd);
    }

    /* make sure that profile data is output upon exiting */
    if (vm && vm->meth.meth == 0002000) {
	if (_Vmpffd < 0)
	    _Vmpffd = 2;
	/* this may wind up calling malloc(), but region is ok now */
	atexit(pfprint);
    } else if (_Vmpffd >= 0) {
	close(_Vmpffd);
	_Vmpffd = -1;
    }

    /* reset file and line number to correct values for the call */
    Vmregion->file = file;
    Vmregion->line = line;

    return 0;
}


Void_t *malloc(register size_t size)




{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    return (*Vmregion->meth.allocf) (Vmregion, size);
}


Void_t *realloc(register Void_t * data, register size_t size)





{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    return (*Vmregion->meth.resizef) (Vmregion, data, size,
				      0000001 | 0000002);
}


void free(register Void_t * data)




{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    (void) (*Vmregion->meth.freef) (Vmregion, data);
}


Void_t *calloc(register size_t n_obj, register size_t s_obj)





{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    return (*Vmregion->meth.resizef) (Vmregion, ((Void_t *)0),
				      n_obj * s_obj, 0000004);
}


void cfree(register Void_t * data)




{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    (void) (*Vmregion->meth.freef) (Vmregion, data);
}


Void_t *memalign(register size_t align, register size_t size)





{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    return (*Vmregion->meth.alignf) (Vmregion, size, align);
}


Void_t *valloc(register size_t size)




{
    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    (((_Vmextern.vm_pagesize)) = 8192);
    return (*Vmregion->meth.alignf) (Vmregion, size, (_Vmextern.vm_pagesize));
}






















    
    










    
    

    
    
    
	
	
	
	
    
    










    
    

    
    
    
	
	
	
	
	
    
    









typedef struct _alloca_s Alloca_t;
union _alloca_u {
    struct {
	char *addr;
	Alloca_t *next;
    } head;
    char array[sizeof(struct _align_s)];
};
struct _alloca_s {
    union _alloca_u head;
    Vmuchar_t data[1];
};


Void_t *alloca(size_t size)




{
    char array[sizeof(struct _align_s)];
    char *file;
    int line;
    register Alloca_t *f;
    static Alloca_t *Frame;

    { if(!_Vmflinit) vmflinit(); if(_Vmdbcheck && (++_Vmdbtime % _Vmdbcheck) == 0 && Vmregion->meth.meth == 0001000) vmdbcheck(Vmregion); };
    ((file) = (Vmregion)->file, (Vmregion)->file = ((char*)0), (line) = (Vmregion)->line, (Vmregion)->line = 0 );
    while (Frame) {
	if ((0 && &array[0] > Frame->head.head.addr) ||
	    (!0 && &array[0] < Frame->head.head.addr)) {
	    f = Frame;
	    Frame = f->head.head.next;
	    (void) (*Vmregion->meth.freef) (Vmregion, f);
	} else
	    break;
    }

    Vmregion->file = file;
    Vmregion->line = line;
    f = (Alloca_t *) (*Vmregion->meth.allocf) (Vmregion,
					       size + sizeof(Alloca_t) -
					       1);

    f->head.head.addr = &array[0];
    f->head.head.next = Frame;
    Frame = f;

    return (Void_t *) f->data;
}



