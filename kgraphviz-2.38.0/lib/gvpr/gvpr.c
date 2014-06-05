#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1
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


/*
 * gpr: graph pattern recognizer
 *
 * Written by Emden Gansner
 */



#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1




#line 1 "graphviz-2.38.0\\lib\\ast\\compat_unistd.h" 1
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




























extern int access (const char*, int);
extern char* getcwd (char*, int);






#line 25 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2

#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 1
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




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1



/*	Public interface for the dictionary library
**
**      Written by Kiem-Phong Vo
*/











#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1






















typedef struct _dtlink_s	Dtlink_t;
typedef struct _dthold_s	Dthold_t;
typedef struct _dtdisc_s	Dtdisc_t;
typedef struct _dtmethod_s	Dtmethod_t;
typedef struct _dtdata_s	Dtdata_t;
typedef struct _dt_s		Dt_t;
typedef struct _dt_s		Dict_t;	/* for libdict compatibility */
typedef struct _dtstat_s	Dtstat_t;
typedef void*			(*Dtmemory_f)(Dt_t*,void*,size_t,Dtdisc_t*);
typedef void*			(*Dtsearch_f)(Dt_t*,void*,int);
typedef void* 		(*Dtmake_f)(Dt_t*,void*,Dtdisc_t*);
typedef void 			(*Dtfree_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtcompar_f)(Dt_t*,void*,void*,Dtdisc_t*);
typedef unsigned int		(*Dthash_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtevent_f)(Dt_t*,int,void*,Dtdisc_t*);

struct _dtlink_s
{	Dtlink_t*	right;	/* right child		*/
	union
	{ unsigned int	_hash;	/* hash value		*/
	  Dtlink_t*	_left;	/* left child		*/
	} hl;
};

/* private structure to hold an object */
struct _dthold_s
{	Dtlink_t	hdr;	/* header		*/
	void*		obj;	/* user object		*/
};

/* method to manipulate dictionary structure */
struct _dtmethod_s 
{	Dtsearch_f	searchf; /* search function	*/
	int		type;	/* type of operation	*/
};

/* stuff that may be in shared memory */
struct _dtdata_s
{	int		type;	/* type of dictionary			*/
	Dtlink_t*	here;	/* finger to last search element	*/
	union
	{ Dtlink_t**	_htab;	/* hash table				*/
	  Dtlink_t*	_head;	/* linked list				*/
	} hh;
	int		ntab;	/* number of hash slots			*/
	int		size;	/* number of objects			*/
	int		loop;	/* number of nested loops		*/
	int		minp;	/* min path before splay, always even	*/
				/* for hash dt, > 0: fixed table size 	*/
};

/* structure to hold methods that manipulate an object */
struct _dtdisc_s
{	int		key;	/* where the key begins in an object	*/
	int		size;	/* key size and type			*/
	int		link;	/* offset to Dtlink_t field		*/
	Dtmake_f	makef;	/* object constructor			*/
	Dtfree_f	freef;	/* object destructor			*/
	Dtcompar_f	comparf;/* to compare two objects		*/
	Dthash_f	hashf;	/* to compute hash value of an object	*/
	Dtmemory_f	memoryf;/* to allocate/free memory		*/
	Dtevent_f	eventf;	/* to process events			*/
};













/* the dictionary structure itself */
struct _dt_s
{	Dtsearch_f	searchf;/* search function			*/
	Dtdisc_t*	disc;	/* method to manipulate objs		*/
	Dtdata_t*	data;	/* sharable data			*/
	Dtmemory_f	memoryf;/* function to alloc/free memory	*/
	Dtmethod_t*	meth;	/* dictionary method			*/
	int		type;	/* type information			*/
	int		nview;	/* number of parent view dictionaries	*/
	Dt_t*		view;	/* next on viewpath			*/
	Dt_t*		walk;	/* dictionary being walked		*/
	void*		user;	/* for user's usage			*/
};

/* structure to get status of a dictionary */
struct _dtstat_s
{	int	dt_meth;	/* method type				*/
	int	dt_size;	/* number of elements			*/
	int	dt_n;		/* number of chains or levels		*/
	int	dt_max;		/* max size of a chain or a level	*/
	int*	dt_count;	/* counts of chains or levels by size	*/
};

/* flag set if the last search operation actually found the object */


/* supported storage methods */










/* asserts to dtdisc() */



/* types of search */















/* events */








1	/* public data */







extern Dtmethod_t* 	Dtset;
extern Dtmethod_t* 	Dtbag;
extern Dtmethod_t* 	Dtoset;
extern Dtmethod_t* 	Dtobag;
extern Dtmethod_t*	Dtlist;
extern Dtmethod_t*	Dtstack;
extern Dtmethod_t*	Dtqueue;
extern Dtmethod_t*	Dtdeque;

/* compatibility stuff; will go away */

extern Dtmethod_t*	Dtorder;
extern Dtmethod_t*	Dttree;
extern Dtmethod_t*	Dthash;
extern Dtmethod_t	_Dttree;
extern Dtmethod_t	_Dthash;
extern Dtmethod_t	_Dtlist;
extern Dtmethod_t	_Dtqueue;
extern Dtmethod_t	_Dtstack;





1	/* public functions */




extern Dt_t*		dtopen (Dtdisc_t*, Dtmethod_t*);
extern int		dtclose (Dt_t*);
extern Dt_t*		dtview (Dt_t*, Dt_t*);
extern Dtdisc_t*	dtdisc (Dt_t* dt, Dtdisc_t*, int);
extern Dtmethod_t*	dtmethod (Dt_t*, Dtmethod_t*);

extern Dtlink_t*	dtflatten (Dt_t*);
extern Dtlink_t*	dtextract (Dt_t*);
extern int		dtrestore (Dt_t*, Dtlink_t*);

extern int		dttreeset (Dt_t*, int, int);

extern int		dtwalk (Dt_t*, int(*)(Dt_t*,void*,void*), void*);

extern void*		dtrenew (Dt_t*, void*);

extern int		dtsize (Dt_t*);
extern int		dtstat (Dt_t*, Dtstat_t*, int);
extern unsigned int	dtstrhash (unsigned int, void*, int);











/* internal functions for translating among holder, object and key */












/* special search function for tree structure only */

























































#line 17 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 2






















/* forward struct type declarations */
typedef struct Agtag_s Agtag_t;
typedef struct Agobj_s Agobj_t;	/* generic object header */
typedef struct Agraph_s Agraph_t;	/* graph, subgraph (or hyperedge) */
typedef struct Agnode_s Agnode_t;	/* node (atom) */
typedef struct Agedge_s Agedge_t;	/* node pair */
typedef struct Agdesc_s Agdesc_t;	/* graph descriptor */
typedef struct Agmemdisc_s Agmemdisc_t;	/* memory allocator */
typedef struct Agiddisc_s Agiddisc_t;	/* object ID allocator */
typedef struct Agiodisc_s Agiodisc_t;	/* IO services */
typedef struct Agdisc_s Agdisc_t;	/* union of client discipline methods */
typedef struct Agdstate_s Agdstate_t;	/* client state (closures) */
typedef struct Agsym_s Agsym_t;	/* string attribute descriptors */
typedef struct Agattr_s Agattr_t;	/* string attribute container */
typedef struct Agcbdisc_s Agcbdisc_t;	/* client event callbacks */
typedef struct Agcbstack_s Agcbstack_t;	/* enclosing state for cbdisc */
typedef struct Agclos_s Agclos_t;	/* common fields for graph/subgs */
typedef struct Agrec_s Agrec_t;	/* generic runtime record */
typedef struct Agdatadict_s Agdatadict_t;	/* set of dictionaries per graph */
typedef struct Agedgepair_s Agedgepair_t;	/* the edge object */
typedef struct Agsubnode_s Agsubnode_t;

/* Header of a user record.  These records are attached by client programs
dynamically at runtime.  A unique string ID must be given to each record
attached to the same object.  Cgraph has functions to create, search for,
and delete these records.   The records are maintained in a circular list,
with obj->data pointing somewhere in the list.  The search function has
an option to lock this pointer on a given record.  The application must
be written so only one such lock is outstanding at a time. */

struct Agrec_s {
    char *name;
    Agrec_t *next;
    /* following this would be any programmer-defined data */
};

/* Object tag for graphs, nodes, and edges.  While there may be several structs
for a given node or edges, there is only one unique ID (per main graph).  */
struct Agtag_s {
    unsigned objtype:2;		/* see literal tags below */
    unsigned mtflock:1;		/* move-to-front lock, see above */
    unsigned attrwf:1;		/* attrs written (parity, write.c) */
    unsigned seq:(sizeof(unsigned) * 8 - 4);	/* sequence no. */
    unsigned long id;		/* client  ID */
};

	/* object tags */






	/* a generic graph/node/edge header */
struct Agobj_s {
    Agtag_t tag;
    Agrec_t *data;
};








/* This is the node struct allocated per graph (or subgraph).  It resides
in the n_dict of the graph.  The node set is maintained by libdict, but
transparently to libgraph callers.  Every node may be given an optional
string name at its time of creation, or it is permissible to pass NIL(char*)
for the name. */

struct Agsubnode_s {		/* the node-per-graph-or-subgraph record */
    Dtlink_t seq_link;		/* must be first */
    Dtlink_t id_link;
    Agnode_t *node;		/* the object */
    Dtlink_t *in_id, *out_id;	/* by node/ID for random access */
    Dtlink_t *in_seq, *out_seq;	/* by node/sequence for serial access */
};

struct Agnode_s {
    Agobj_t base;
    Agraph_t *root;
    Agsubnode_t mainsub;	/* embedded for main graph */
};

struct Agedge_s {
    Agobj_t base;
    Dtlink_t id_link;		/* main graph only */
    Dtlink_t seq_link;
    Agnode_t *node;		/* the endpoint node */
};

struct Agedgepair_s {
    Agedge_t out, in;
};

struct Agdesc_s {		/* graph descriptor */
    unsigned directed:1;	/* if edges are asymmetric */
    unsigned strict:1;		/* if multi-edges forbidden */
    unsigned no_loop:1;		/* if no loops */
    unsigned maingraph:1;	/* if this is the top level graph */
    unsigned flatlock:1;	/* if sets are flattened into lists in cdt */
    unsigned no_write:1;	/* if a temporary subgraph */
    unsigned has_attrs:1;	/* if string attr tables should be initialized */
    unsigned has_cmpnd:1;	/* if may contain collapsed nodes */
};

/* disciplines for external resources needed by libgraph */

struct Agmemdisc_s {		/* memory allocator */
    void *(*open) (Agdisc_t*);	/* independent of other resources */
    void *(*alloc) (void *state, size_t req);
    void *(*resize) (void *state, void *ptr, size_t old, size_t req);
    void (*free) (void *state, void *ptr);
    void (*close) (void *state);
};

struct Agiddisc_s {		/* object ID allocator */
    void *(*open) (Agraph_t * g, Agdisc_t*);	/* associated with a graph */
    long (*map) (void *state, int objtype, char *str, unsigned long *id,
		 int createflag);
    long (*alloc) (void *state, int objtype, unsigned long id);
    void (*free) (void *state, int objtype, unsigned long id);
    char *(*print) (void *state, int objtype, unsigned long id);
    void (*close) (void *state);
    void (*idregister) (void *state, int objtype, void *obj);
};

struct Agiodisc_s {
    int (*afread) (void *chan, char *buf, int bufsize);
    int (*putstr) (void *chan, const char *str);
    int (*flush) (void *chan);	/* sync */
    /* error messages? */
};

struct Agdisc_s {		/* user's discipline */
    Agmemdisc_t *mem;
    Agiddisc_t *id;
    Agiodisc_t *io;
};

	/* default resource disciplines */

/*visual studio*/



/*end visual studio*/

extern Agmemdisc_t AgMemDisc;
extern Agiddisc_t AgIdDisc;
extern Agiodisc_t AgIoDisc;

extern Agdisc_t AgDefaultDisc;


struct Agdstate_s {
    void *mem;
    void *id;
    /* IO must be initialized and finalized outside Cgraph,
     * and channels (FILES) are passed as void* arguments. */
};

typedef void (*agobjfn_t) (Agraph_t * g, Agobj_t * obj, void *arg);
typedef void (*agobjupdfn_t) (Agraph_t * g, Agobj_t * obj, void *arg,
			      Agsym_t * sym);

struct Agcbdisc_s {
    struct {
	agobjfn_t ins;
	agobjupdfn_t mod;
	agobjfn_t del;
    } graph, node, edge;
};

struct Agcbstack_s {		/* object event callbacks */
    Agcbdisc_t *f;		/* methods */
    void *state;		/* closure */
    Agcbstack_t *prev;		/* kept in a stack, unlike other disciplines */
};

struct Agclos_s {
    Agdisc_t disc;		/* resource discipline functions */
    Agdstate_t state;		/* resource closures */
    Dict_t *strdict;		/* shared string dict */
    unsigned long seq[3];	/* local object sequence number counter */
    Agcbstack_t *cb;		/* user and system callback function stacks */
    unsigned char callbacks_enabled;	/* issue user callbacks or hold them? */
    Dict_t *lookup_by_name[3];
    Dict_t *lookup_by_id[3];
};

struct Agraph_s {
    Agobj_t base;
    Agdesc_t desc;
    Dtlink_t link;
    Dict_t *n_seq;		/* the node set in sequence */
    Dict_t *n_id;		/* the node set indexed by ID */
    Dict_t *e_seq, *e_id;	/* holders for edge sets */
    Dict_t *g_dict;		/* subgraphs - descendants */
    Agraph_t *parent, *root;	/* subgraphs - ancestors */
    Agclos_t *clos;		/* shared resources */
};












extern void agpushdisc(Agraph_t * g, Agcbdisc_t * disc, void *state);
extern int agpopdisc(Agraph_t * g, Agcbdisc_t * disc);
extern int agcallbacks(Agraph_t * g, int flag);	/* return prev value */

/* graphs */
extern Agraph_t *agopen(char *name, Agdesc_t desc, Agdisc_t * disc);
extern int agclose(Agraph_t * g);
extern Agraph_t *agread(void *chan, Agdisc_t * disc);
extern Agraph_t *agmemread(const char *cp);
extern void agreadline(int);
extern void agsetfile(char *);
extern Agraph_t *agconcat(Agraph_t * g, void *chan, Agdisc_t * disc);
extern int agwrite(Agraph_t * g, void *chan);
extern int agisdirected(Agraph_t * g);
extern int agisundirected(Agraph_t * g);
extern int agisstrict(Agraph_t * g);
extern int agissimple(Agraph_t * g);

/* nodes */
extern Agnode_t *agnode(Agraph_t * g, char *name, int createflag);
extern Agnode_t *agidnode(Agraph_t * g, unsigned long id, int createflag);
extern Agnode_t *agsubnode(Agraph_t * g, Agnode_t * n, int createflag);
extern Agnode_t *agfstnode(Agraph_t * g);
extern Agnode_t *agnxtnode(Agraph_t * g, Agnode_t * n);
extern Agnode_t *aglstnode(Agraph_t * g);
extern Agnode_t *agprvnode(Agraph_t * g, Agnode_t * n);

extern Agsubnode_t *agsubrep(Agraph_t * g, Agnode_t * n);

/* edges */
extern Agedge_t *agedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			char *name, int createflag);
extern Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			  unsigned long id, int createflag);
extern Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int createflag);
extern Agedge_t *agfstin(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstout(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtout(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n);

/* generic */
extern Agraph_t *agraphof(void* obj);
extern Agraph_t *agroot(void* obj);
extern int agcontains(Agraph_t *, void *);
extern char *agnameof(void *);
extern int agrelabel(void *obj, char *name);	/* scary */
extern int agrelabel_node(Agnode_t * n, char *newname);
extern int agdelete(Agraph_t * g, void *obj);
extern long agdelsubg(Agraph_t * g, Agraph_t * sub);	/* could be agclose */
extern int agdelnode(Agraph_t * g, Agnode_t * arg_n);
extern int agdeledge(Agraph_t * g, Agedge_t * arg_e);
extern int agobjkind(void *);

/* strings */
extern char *agstrdup(Agraph_t *, char *);
extern char *agstrdup_html(Agraph_t *, char *);
extern int aghtmlstr(char *);
extern char *agstrbind(Agraph_t * g, char *);
extern int agstrfree(Agraph_t *, char *);
extern char *agcanon(char *, int);
extern char *agstrcanon(char *, char *);
extern char *agcanonStr(char *str);  /* manages its own buf */

/* definitions for dynamic string attributes */
struct Agattr_s {		/* dynamic string attributes */
    Agrec_t h;			/* common data header */
    Dict_t *dict;		/* shared dict to interpret attr field */
    char **str;			/* the attribute string values */
};

struct Agsym_s {		/* symbol in one of the above dictionaries */
    Dtlink_t link;
    char *name;			/* attribute's name */
    char *defval;		/* its default value for initialization */
    int id;			/* its index in attr[] */
    unsigned char kind;		/* referent object type */
    unsigned char fixed;	/* immutable value */
    unsigned char print;	/* always print */
};

struct Agdatadict_s {		/* set of dictionaries per graph */
    Agrec_t h;			/* installed in list of graph recs */
    struct {
	Dict_t *n, *e, *g;
    } dict;
};

extern Agsym_t *agattr(Agraph_t * g, int kind, char *name, char *value);
extern Agsym_t *agattrsym(void *obj, char *name);
extern Agsym_t *agnxtattr(Agraph_t * g, int kind, Agsym_t * attr);
extern int      agcopyattr(void *oldobj, void *newobj);

extern void *agbindrec(void *obj, char *name, unsigned int size,
		       int move_to_front);
extern Agrec_t *aggetrec(void *obj, char *name, int move_to_front);
extern int agdelrec(void *obj, char *name);
extern void aginit(Agraph_t * g, int kind, char *rec_name, int rec_size,
		   int move_to_front);
extern void agclean(Agraph_t * g, int kind, char *rec_name);

extern char *agget(void *obj, char *name);
extern char *agxget(void *obj, Agsym_t * sym);
extern int agset(void *obj, char *name, char *value);
extern int agxset(void *obj, Agsym_t * sym, char *value);
extern int agsafeset(void* obj, char* name, char* value, char* def);

/* defintions for subgraphs */
extern Agraph_t *agsubg(Agraph_t * g, char *name, int cflag);	/* constructor */
extern Agraph_t *agidsubg(Agraph_t * g, unsigned long id, int cflag);	/* constructor */
extern Agraph_t *agfstsubg(Agraph_t * g), *agnxtsubg(Agraph_t * subg);
extern Agraph_t *agparent(Agraph_t * g);

/* set cardinality */
extern int agnnodes(Agraph_t * g), agnedges(Agraph_t * g), agnsubg(Agraph_t * g);
extern int agdegree(Agraph_t * g, Agnode_t * n, int in, int out);
extern int agcountuniqedges(Agraph_t * g, Agnode_t * n, int in, int out);

/* memory */
extern void *agalloc(Agraph_t * g, size_t size);
extern void *agrealloc(Agraph_t * g, void *ptr, size_t oldsize,
		       size_t size);
extern void agfree(Agraph_t * g, void *ptr);
extern struct _vmalloc_s *agheap(Agraph_t * g);

/* an engineering compromise is a joy forever */
extern void aginternalmapclearlocalnames(Agraph_t * g);




/* error handling */
typedef enum { AGWARN, AGERR, AGMAX, AGPREV } agerrlevel_t;
typedef int (*agusererrf) (char*);
extern agerrlevel_t agseterr(agerrlevel_t);
extern char *aglasterr(void);
extern int agerr(agerrlevel_t level, const char *fmt, ...);
extern void agerrorf(const char *fmt, ...);
extern void agwarningf(const char *fmt, ...);
extern int agerrors(void);
extern int agreseterrors(void);
extern agusererrf agseterrf(agusererrf);

/* data access macros */
/* this assumes that e[0] is out and e[1] is inedge, see edgepair in edge.c  */
























extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,
    Agstrictundirected;



/* fast graphs */
void agflatten(Agraph_t * g, int flag);
typedef Agsubnode_t	Agnoderef_t;
typedef Dtlink_t	Agedgeref_t;



















/* this is expedient but a bit slimey because it "knows" that dict entries of both nodes
and edges are embedded in main graph objects but allocated separately in subgraphs */











#line 20 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\ast\\ast.h" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\align.h" 1
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





/* : : generated from features/align.c by iffe version 1999-08-11 : : */


    typedef unsigned long ALIGN_INTEGRAL;
































#line 22 "graphviz-2.38.0\\lib\\ast\\ast.h" 2























/*
 * strgrpmatch() flags
 */






/*
 * fmtquote() flags
 */

















    extern char *pathpath(char *, const char *, const char *, int);
    extern char *pathfind(const char *, const char *, const char *, char *,
			  size_t);
    extern char *pathaccess(char *, const char *, const char *,
			    const char *, int);
    extern char *pathbin(void);
    extern char *pathcat(char *, const char *, int, const char *,
			 const char *);
    extern int pathgetlink(const char *, char *, int);
    extern int pathexists(char *, int);

    extern int chresc(const char *, char **);
    extern int chrtoi(const char *);
    extern char *fmtesq(const char *, const char *);
    extern char *fmtesc(const char *as);
    extern char *fmtbuf(size_t n);
    extern char *fmtquote(const char *, const char *, const char *, size_t,
			  int);

    extern int astquery(int, const char *, ...);

    extern int strmatch(const char *, const char *);
    extern int strgrpmatch(const char *, const char *, int *, int, int);
    extern int stresc(char *);
    extern long strton(const char *, char **, char *, int);
    extern char *strcopy(char *s, const char *t);






#line 21 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
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
    typedef void *(*Vmemory_f)
	(Vmalloc_t *, void *, size_t, size_t, Vmdisc_t *);
    typedef int (*Vmexcept_f)
	(Vmalloc_t *, int, void *, Vmdisc_t *);

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
	void *(*allocf) (Vmalloc_t *, size_t);
	void *(*resizef) (Vmalloc_t *, void *, size_t, int);
	int (*freef) (Vmalloc_t *, void *);
	long (*addrf) (Vmalloc_t *, void *);
	long (*sizef) (Vmalloc_t *, void *);
	int (*compactf) (Vmalloc_t *);
	void *(*alignf) (Vmalloc_t *, size_t, size_t);
	unsigned short meth;
    };

    struct _vmalloc_s {
	Vmethod_t meth;		/* method for allocation        */
	char *file;		/* file name                    */
	int line;		/* line number                  */

	 

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

      1	/* public functions */



     extern Vmalloc_t *vmopen (Vmdisc_t *, Vmethod_t *, int);
    extern int vmclose (Vmalloc_t *);
    extern int vmclear (Vmalloc_t *);
    extern int vmcompact (Vmalloc_t *);

    extern Vmdisc_t *vmdisc (Vmalloc_t *, Vmdisc_t *);

    extern void *vmalloc (Vmalloc_t *, size_t);
    extern void *vmalign (Vmalloc_t *, size_t, size_t);
    extern void *vmresize (Vmalloc_t *, void *, size_t, int);
    extern int vmfree (Vmalloc_t *, void *);

    extern long vmaddr (Vmalloc_t *, void *);
    extern long vmsize (Vmalloc_t *, void *);

    extern Vmalloc_t *vmregion (void *);
    extern void *vmsegment (Vmalloc_t *, void *);
    extern int vmset (Vmalloc_t *, int, int);

    extern void *vmdbwatch (void *);
    extern int vmdbcheck (Vmalloc_t *);

    extern int vmprofile (Vmalloc_t *, int);

    extern int vmtrace (int);
    extern int vmtrbusy (Vmalloc_t *);

    extern int vmstat (Vmalloc_t *, Vmstat_t *);

    extern int vmwalk (Vmalloc_t *,
 int(*)(Vmalloc_t *, void *, size_t,
 Vmdisc_t *));
    extern char *vmstrdup (Vmalloc_t *, const char *);




    extern void *malloc (size_t);
    extern void *realloc (void *, size_t);
    extern void free (void *);
    extern void cfree (void *);
    extern void *calloc (size_t, size_t);
    extern void *memalign (size_t, size_t);
    extern void *valloc (size_t);



     
/* to coerce any value to a Vmalloc_t*, make ANSI happy */

/* enable recording of where a call originates from */


































/* non-debugging/profiling allocation calls */
























#line 22 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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





/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library definitions
 */




#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
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
































































    
    
			  
    
			    
    
    
			 
    
    

    
    
    
    
    
    
			  

    

    
    
    
    
    






#line 26 "graphviz-2.38.0\\lib\\expr\\expr.h" 2










/*
 * bison -pPREFIX misses YYSTYPE
 */




#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1


/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */



/* Enabling traces.  */




extern int exdebug;


/* Tokens.  */


   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum extokentype {
     MINTOKEN = 258,
     INTEGER = 259,
     UNSIGNED = 260,
     CHARACTER = 261,
     FLOATING = 262,
     STRING = 263,
     VOIDTYPE = 264,
     STATIC = 265,
     ADDRESS = 266,
     ARRAY = 267,
     BREAK = 268,
     CALL = 269,
     CASE = 270,
     CONSTANT = 271,
     CONTINUE = 272,
     DECLARE = 273,
     DEFAULT = 274,
     DYNAMIC = 275,
     ELSE = 276,
     EXIT = 277,
     FOR = 278,
     FUNCTION = 279,
     GSUB = 280,
     ITERATE = 281,
     ITERATER = 282,
     ID = 283,
     IF = 284,
     LABEL = 285,
     MEMBER = 286,
     NAME = 287,
     POS = 288,
     PRAGMA = 289,
     PRE = 290,
     PRINT = 291,
     PRINTF = 292,
     PROCEDURE = 293,
     QUERY = 294,
     RAND = 295,
     RETURN = 296,
     SCANF = 297,
     SPLIT = 298,
     SPRINTF = 299,
     SRAND = 300,
     SSCANF = 301,
     SUB = 302,
     SUBSTR = 303,
     SWITCH = 304,
     TOKENS = 305,
     UNSET = 306,
     WHILE = 307,
     F2I = 308,
     F2S = 309,
     I2F = 310,
     I2S = 311,
     S2B = 312,
     S2F = 313,
     S2I = 314,
     F2X = 315,
     I2X = 316,
     S2X = 317,
     X2F = 318,
     X2I = 319,
     X2S = 320,
     X2X = 321,
     XPRINT = 322,
     OR = 323,
     AND = 324,
     NE = 325,
     EQ = 326,
     GE = 327,
     LE = 328,
     RS = 329,
     LS = 330,
     IN_OP = 331,
     UNARY = 332,
     DEC = 333,
     INC = 334,
     CAST = 335,
     MAXTOKEN = 336
   };

/* Tokens.  */



















































































typedef union EXSTYPE
{
/* Line 2049 of yacc.c  */


	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	_ast_intmax_t	integer;
	int		op;
	char*		string;
	void*		user;
	struct Exbuf_s*	buffer;


/* Line 2049 of yacc.c  */

} EXSTYPE;





extern EXSTYPE exlval;











int exparse ();





#line 38 "graphviz-2.38.0\\lib\\expr\\expr.h" 2





#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1















































   

   
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   


























































































	
	
	
	
	
	
	
	
	




























#line 41 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 44 "graphviz-2.38.0\\lib\\expr\\expr.h" 2
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





















    
    
    
    
    
	
    
	

    
	
	
	
	
	
	
	
	
    

    
	
	
	
    

    
	
	
	
	
	
	
	
	
    

    
	
	
	

	 

    

























     















		 
		 
    
    
    
    

    
    

    
    

     



     
    
    
    

    

    
    
    
    

    
    

    
    
    

    
    

    

    
    

    

    
			     
				     
    




    
    
    
    
    
    
    



     






























































#line 45 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



/*
 * flags
 */




















/* previously known as EXID, but EXID is also defined by bison in y.tab.h */







/* function type mechanism
 * types are encoded in TBITS
 * Thus, maximum # of parameters, including return type,
 * is sizeof(Exid_t.type)/TBITS. Also see T in exgram.h
 */

/*
 * arg 0 is the return value type
 */


















typedef short Exshort_t;


typedef EXSTYPE Extype_t;

union Exdata_u; typedef union Exdata_u Exdata_t;
struct Exdisc_s; typedef struct Exdisc_s Exdisc_t;
struct Exnode_s; typedef struct Exnode_s Exnode_t;
struct Expr_s; typedef struct Expr_s Expr_t;
struct Exref_s; typedef struct Exref_s Exref_t;

typedef int (*Exerror_f) (Expr_t *, Exdisc_t *, int, const char *, ...);
typedef void (*Exexit_f) (Expr_t *, Exdisc_t *, int);

typedef struct Exlocal_s		/* user defined member type	*/
{
	_ast_intmax_t	number;
	char*		pointer;
} Exlocal_t;

typedef struct Exid_s			/* id symbol table info		*/
{
	Dtlink_t	link;		/* symbol table link		*/
	long		lex;		/* lex class			*/
	long		index;		/* user defined index		*/
	long		type;		/* symbol and arg types		*/
	long		index_type;	/* index type for arrays        */
	long		flags;		/* user defined flags		*/
	Exnode_t*	value;		/* value			*/
	Exlocal_t	local;		/* user defined local stuff	*/
	long		isstatic;	/* static			*/
	char		name[32];/* symbol name			*/
} Exid_t;

struct Exref_s				/* . reference list		*/
{
	Exref_t*	next;		/* next in list			*/
	Exid_t*		symbol;		/* reference id symbol		*/
	Exnode_t*	index;		/* optional reference index	*/
};

typedef struct Exbuf_s			/* sized buffer			*/
{
	unsigned long	size;		/* buffer size			*/
	char*		data;		/* buffer data			*/
} Exbuf_t;

union Exdata_u
{

	struct
	{
	Extype_t	value;		/* constant value		*/
	Exid_t*		reference;	/* conversion reference symbol	*/
	}		constant;	/* variable reference		*/

	struct
	{
	Exnode_t*	left;		/* left operand			*/
	Exnode_t*	right;		/* right operand		*/
	Exnode_t*	last;		/* for cons			*/
	}		operand;	/* operands			*/

	struct
	{
	Exnode_t*	statement;	/* case label statement(s)	*/
	Exnode_t*	next;		/* next case item		*/
	Extype_t**	constant;	/* case label constant array	*/
	}		select;		/* case item			*/

	struct
	{
	Exid_t*		symbol;		/* id symbol table entry	*/
	Exref_t*	reference;	/* . reference list		*/
	Exnode_t*	index;		/* array index expression	*/
	Exnode_t*	dyna;		/* dynamic expression		*/
	}		variable;	/* variable reference		*/


	


};

struct Exnode_s				/* expression tree node		*/
{
	Exshort_t	type;		/* value type			*/
	Exshort_t	op;		/* operator			*/
	Exshort_t	binary;		/* data.operand.{left,right} ok	*/
	Exshort_t	pad_1;		/* padding to help cc		*/
	Exlocal_t	local;		/* user defined local stuff	*/
	union
	{
	double	(*floating)(char**);	/* FLOATING return value	*/
	_ast_intmax_t(*integer)(char**);	/* INTEGER|UNSIGNED return value*/
	char*	(*string)(char**);	/* STRING return value		*/
	}		compiled;	/* compiled function pointer	*/
	Exdata_t	data;		/* node data			*/


	


};

struct Exdisc_s				/* discipline			*/
{
	unsigned long	version;	/* EX_VERSION			*/
	unsigned long	flags;		/* EX_* flags			*/
	Exid_t*		symbols;	/* static symbols		*/
	char**		data;		/* compiled function arg data	*/
	char*		lib;		/* pathfind() lib		*/
	char*		type;		/* pathfind() type		*/
	int		(*castf)(Expr_t*, Exnode_t*, const char*, int, Exid_t*, int, Exdisc_t*);
					/* unknown cast function	*/
	int		(*convertf)(Expr_t*, Exnode_t*, int, Exid_t*, int, Exdisc_t*);
					/* type conversion function	*/
	int		(*binaryf) (Expr_t *, Exnode_t *, Exnode_t *, Exnode_t *, int, Exdisc_t *);
					/* binary operator function     */
	char*		(*typename) (Expr_t *, int);
					/* application type names       */
	int		(*stringof) (Expr_t *, Exnode_t *, int, Exdisc_t *);
					/* value to string conversion   */
	Extype_t	(*keyf) (Expr_t *, Extype_t, int, Exdisc_t *);
					/* dictionary key for external type objects     */
	Exerror_f	errorf;		/* error function		*/
	Extype_t	(*getf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Exdisc_t*);
					/* get value function		*/
	Extype_t	(*reff)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, char*, int, Exdisc_t*);
					/* reference value function	*/
	int		(*setf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Extype_t, Exdisc_t*);
					/* set value function		*/
	int		(*matchf)(Expr_t*, Exnode_t*, const char*, Exnode_t*, const char*, void*, Exdisc_t*);
	/* exit function           */
	Exexit_f	exitf;
	int*		types;
	void*		user;
};

struct Expr_s				/* ex program state		*/
{
	const char*	id;		/* library id			*/
	Dt_t*		symbols;	/* symbol table			*/
	const char*	more;		/* more after %% (sp or != 0)	*/
	Sfio_t*		file[10];	/* io streams			*/
	Vmalloc_t*	vm;		/* program store		*/


	


};

struct Excc_s; typedef struct Excc_s Excc_t;
struct Exccdisc_s; typedef struct Exccdisc_s Exccdisc_t;

struct Exccdisc_s			/* excc() discipline		*/
{
	Sfio_t*		text;		/* text output stream		*/
	char*		id;		/* symbol prefix		*/
	unsigned long	flags;		/* EXCC_* flags			*/
	int		(*ccf)(Excc_t*, Exnode_t*, Exid_t*, Exref_t*, Exnode_t*, Exccdisc_t*);
					/* program generator function	*/
};

struct Excc_s				/* excc() state			*/
{
	Expr_t*		expr;		/* exopen() state		*/
	Exdisc_t*	disc;		/* exopen() discipline		*/


	


};





extern Exnode_t*	excast(Expr_t*, Exnode_t*, int, Exnode_t*, int);
extern Exnode_t*	exnoncast(Exnode_t *);
extern int		excc(Excc_t*, const char*, Exid_t*, int);
extern int		exccclose(Excc_t*);
extern Excc_t*		exccopen(Expr_t*, Exccdisc_t*);
extern void		exclose(Expr_t*, int);
extern int		excomp(Expr_t*, const char*, int, const char*, Sfio_t*);
extern char*		excontext(Expr_t*, char*, int);
extern int		exdump(Expr_t*, Exnode_t*, Sfio_t*);
extern void		exerror(const char*, ...);
extern void		exwarn(const char *, ...);
extern Extype_t		exeval(Expr_t*, Exnode_t*, void*);
extern Exnode_t*	exexpr(Expr_t*, const char*, Exid_t*, int);
extern void		exfreenode(Expr_t*, Exnode_t*);
extern Exnode_t*	exnewnode(Expr_t*, int, int, int, Exnode_t*, Exnode_t*);
extern char*		exnospace(void);
extern Expr_t*		exopen(Exdisc_t*);
extern int		expop(Expr_t*);
extern int		expush(Expr_t*, const char*, int, const char*, Sfio_t*);
extern int		exrewind(Expr_t*);
extern char*		exstash(Sfio_t*, Vmalloc_t*);
extern void		exstatement(Expr_t*);
extern int		extoken_fn(Expr_t*);
extern char*		exstring(Expr_t *, char *);
extern void*		exstralloc(Expr_t *, void *, size_t);
extern int		exstrfree(Expr_t *, void *);
extern char*		extype(int);
extern Extype_t		exzero(int);
extern char*	exopname(int);
extern void		exinit(void);
extern char*	extypename(Expr_t * p, int);
extern int		exisAssign(Exnode_t *);








#line 23 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.h" 1
/* $Id$Revision: */
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








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 19 "graphviz-2.38.0\\lib\\gvpr\\gvpr.h" 2




/* Bits for flags variable in gvprstate_t.
 * Included here so that calling programs can use the first
 * two in gvpropts.flags
 */
  /* If set, gvpr calls exit() on errors */

  /* If set, gvpr stores output graphs in gvpropts */

  /* Use longjmp to return to top-level call in gvpr */

  /* $tvnext has been set but not used */



typedef ssize_t (*gvprwr) (void*, const char *buf, size_t nbyte, void*);
typedef int (*gvpruserfn) (char *);
typedef struct {
    char* name;
    gvpruserfn fn;
} gvprbinding;

typedef struct {
    Agraph_t** ingraphs;      /* NULL-terminated array of input graphs */
    int n_outgraphs;          /* if GV_USE_OUTGRAPH set, output graphs */
    Agraph_t** outgraphs;
    gvprwr out;               /* write function for stdout */
    gvprwr err;               /* write function for stderr */
    int flags;
    gvprbinding* bindings;    /* array of bindings, terminated with {NULL,NULL} */
} gvpropts;

    extern int gvpr (int argc, char *argv[], gvpropts* opts);






#line 24 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2

    typedef enum { TV_flat, TV_ne, TV_en, 
                   TV_bfs, 
                   TV_dfs, TV_fwd, TV_rev,
                   TV_postdfs, TV_postfwd, TV_postrev,
                   TV_prepostdfs, TV_prepostfwd, TV_prepostrev,
    } trav_type;

/* Bits for flags variable. 
 */
  /* If set, gvpr calls exit() on errors */

  /* If set, gvpr stores output graphs in gvpropts */



    typedef struct {
	Agraph_t *curgraph;
	Agraph_t *nextgraph;
	Agraph_t *target;
	Agraph_t *outgraph;
	Agobj_t *curobj;
	Sfio_t *tmp;
	Exdisc_t *dp;
	Exerror_f errf;
	Exexit_f exitf;
	char *tgtname;
	char *infname;
	Sfio_t *outFile;
	Agiodisc_t* dfltIO;
	trav_type tvt;
	Agnode_t *tvroot;
	Agnode_t *tvnext;
	Agedge_t *tvedge;
	int name_used;
	int argc;
	char **argv;
	int flags;
	gvprbinding* bindings;
	int n_bindings;
    } Gpr_t;

    typedef struct {
	Sfio_t *outFile;
	int argc;
	char **argv;
	Exerror_f errf;
	Exexit_f exitf;
	int flags;
    } gpr_info;

    extern Gpr_t *openGPRState(gpr_info*);
    extern void addBindings(Gpr_t* state, gvprbinding*);
    extern gvprbinding* findBinding(Gpr_t* state, char*);
    extern void closeGPRState(Gpr_t* state);
    extern void initGPRState(Gpr_t *, Vmalloc_t *);
    extern int validTVT(int);


    







#line 27 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 28 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\globals.h" 1
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

/* this is to get the following win32 DLL junk to work.
 * if ever tempted to remove this, first please read:
 * http://joel.editthispage.com/stories/storyReader$47
 */



























/*visual studio*/





/*end visual studio*/












    extern char *Version;
    extern char **Files;	/* from command line */
    extern const char **Lib;		/* from command line */
    extern char *CmdName;
    extern char *specificFlags;
    extern char *specificItems;
    extern char *Gvfilepath;  /* Per-process path of files allowed in image attributes (also ps libs) */
    extern char *Gvimagepath; /* Per-graph path of files allowed in image attributes  (also ps libs) */

    extern unsigned char Verbose;
    extern unsigned char Reduce;
    extern int MemTest;
    extern char *HTTPServerEnVar;
    extern char *Output_file_name;
    extern int graphviz_errors;
    extern int Nop;
    extern double PSinputscale;
    extern int Syntax_errors;
    extern int Show_cnt;
    extern char** Show_boxes;	/* emit code for correct box coordinates */
    extern int CL_type;		/* NONE, LOCAL, GLOBAL */
    extern unsigned char Concentrate;	/* if parallel edges should be merged */
    extern double Epsilon;	/* defined in input_graph */
    extern int MaxIter;
    extern int Ndim;
    extern int State;		/* last finished phase */
    extern int EdgeLabelsDone;	/* true if edge labels have been positioned */
    extern double Initial_dist;
    extern double Damping;
    extern int Y_invert;	/* invert y in dot & plain output */
    extern int GvExitOnUsage;   /* gvParseArgs() should exit on usage or error */

    extern Agsym_t
	*G_activepencolor, *G_activefillcolor,
	*G_selectedpencolor, *G_selectedfillcolor,
	*G_visitedpencolor, *G_visitedfillcolor,
	*G_deletedpencolor, *G_deletedfillcolor,
	*G_ordering, *G_peripheries, *G_penwidth,
	*G_gradientangle, *G_margin;
    extern Agsym_t
	*N_height, *N_width, *N_shape, *N_color, *N_fillcolor,
	*N_activepencolor, *N_activefillcolor,
	*N_selectedpencolor, *N_selectedfillcolor,
	*N_visitedpencolor, *N_visitedfillcolor,
	*N_deletedpencolor, *N_deletedfillcolor,
	*N_fontsize, *N_fontname, *N_fontcolor, *N_margin,
	*N_label, *N_xlabel, *N_nojustify, *N_style, *N_showboxes,
	*N_sides, *N_peripheries, *N_ordering, *N_orientation,
	*N_skew, *N_distortion, *N_fixed, *N_imagescale, *N_layer,
	*N_group, *N_comment, *N_vertices, *N_z,
	*N_penwidth, *N_gradientangle;
    extern Agsym_t
	*E_weight, *E_minlen, *E_color, *E_fillcolor,
	*E_activepencolor, *E_activefillcolor,
	*E_selectedpencolor, *E_selectedfillcolor,
	*E_visitedpencolor, *E_visitedfillcolor,
	*E_deletedpencolor, *E_deletedfillcolor,
	*E_fontsize, *E_fontname, *E_fontcolor,
	*E_label, *E_xlabel, *E_dir, *E_style, *E_decorate,
	*E_showboxes, *E_arrowsz, *E_constr, *E_layer,
	*E_comment, *E_label_float,
	*E_samehead, *E_sametail,
	*E_arrowhead, *E_arrowtail,
	*E_headlabel, *E_taillabel,
	*E_labelfontsize, *E_labelfontname, *E_labelfontcolor,
	*E_labeldistance, *E_labelangle,
	*E_tailclip, *E_headclip,
	*E_penwidth;

    extern struct fdpParms_s* fdp_parms;











#line 29 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\ingraphs\\ingraphs.h" 1
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




/* The ingraphs library works with both libagraph and with 
 * libgraph, with all user-supplied data. For this to work,
 * the include file relies upon its context to supply a
 * definition of Agraph_t.
 */

#line 1 "graphviz-2.38.0\\lib\\ingraphs\\ingraphs.h" 1





    typedef Agraph_t *(*opengfn) (FILE *);

    typedef struct {
	void *(*openf) (char *);
	Agraph_t *(*readf) (void *);
	int (*closef) (void *);
	void *dflt;
    } ingdisc;

    typedef struct {
	union {
	    char**     Files;
	    Agraph_t** Graphs;
	} u;
	int ctr;
	int ingraphs;
	void *fp;
	ingdisc *fns;
	char heap;
	int errors;
    } ingraph_state;

    extern ingraph_state *newIngraph(ingraph_state *, char **, opengfn);
    extern ingraph_state *newIng(ingraph_state *, char **, ingdisc *);
    extern ingraph_state *newIngGraphs(ingraph_state *, Agraph_t**, ingdisc *);
    extern void closeIngraph(ingraph_state * sp);
    extern Agraph_t *nextGraph(ingraph_state *);
    extern char *fileName(ingraph_state *);





#line 30 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.h" 1
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








    typedef enum { Begin =
	    0, End, BeginG, EndG, Node, Edge, Eof, Error } case_t;

    typedef struct _case_info {
	int gstart;
	char *guard;
	int astart;
	char *action;
	struct _case_info *next;
    } case_info;

    typedef struct _parse_block {
	int l_beging;
	char *begg_stmt;
	int n_nstmts;
	int n_estmts;
	case_info *node_stmts;
	case_info *edge_stmts;
	struct _parse_block *next;
    } parse_block; 

    typedef struct {
	char *source;
	int l_begin, l_end, l_endg;
	char *begin_stmt;
	int n_blocks;
	parse_block *blocks;
	char *endg_stmt;
	char *end_stmt;
    } parse_prog;

    extern parse_prog *parseProg(char *, int);
    extern void freeParseProg (parse_prog *);






#line 20 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 1
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















    
                   
                   
                   
                   
    



  

  



    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
    

    
    
    
    
    
    


    







#line 21 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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





/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library definitions
 */















































































































	
	




	
	
	
	
	
	
	
	
	
	




	
	
	




	
	





	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
					
	
					
	
					
	
					
	
					
	
					
	
	
					
	
					
	
					
	
	
	
	
	




	
	
	
	
	


	









	
	
	
	
					




	
	


	
















































#line 22 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2

    typedef struct {
	Exnode_t *guard;
	Exnode_t *action;
    } case_stmt;



    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
	Extype_t iu;
	Agedge_t* ine;
    } nval_t;

    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
	/* Extype_t iu; */
	char lock;
    } gval_t;

    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
    } uval_t;



    typedef nval_t ndata;
    typedef uval_t edata;
    typedef gval_t gdata;












    typedef struct {
	Exnode_t *begg_stmt;
	int walks;
	int n_nstmts;
	int n_estmts;
	case_stmt *node_stmts;
	case_stmt *edge_stmts;
    } comp_block; 

    typedef struct {
	int flags;
	Expr_t *prog;
	Exnode_t *begin_stmt;
	int n_blocks;
	comp_block  *blocks;
	Exnode_t *endg_stmt;
	Exnode_t *end_stmt;
    } comp_prog;

    extern comp_prog *compileProg(parse_prog *, Gpr_t *, int);
    extern void freeCompileProg (comp_prog *p);
    extern int usesGraph(comp_prog *);
    extern int walksGraph(comp_block *);
    extern Agraph_t *readG(Sfio_t * fp);
    extern Agraph_t *openG(char *name, Agdesc_t);
    extern Agraph_t *openSubg(Agraph_t * g, char *name);
    extern Agnode_t *openNode(Agraph_t * g, char *name);
    extern Agedge_t *openEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key);






#line 31 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\queue.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 19 "graphviz-2.38.0\\lib\\gvpr\\queue.h" 2

    typedef Dt_t queue;

    extern queue *mkQ(Dtmethod_t *);
    extern void push(queue *, void *);
    extern void *pop(queue *, int remove);
    extern void freeQ(queue *);

/* pseudo-functions:
extern queue* mkStack();
extern queue* mkQueue();
extern void* pull(queue*);
extern void* head(queue*);
 */











#line 32 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.h" 1
/* $Id$Revision: */
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

















  

  

  

  






    
    



    
    
    
    
    
    
    


    






#line 33 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 19 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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





/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library definitions
 */















































































































	
	




	
	
	
	
	
	
	
	
	
	




	
	
	




	
	





	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
					
	
					
	
					
	
					
	
					
	
					
	
	
					
	
					
	
					
	
	
	
	
	




	
	
	
	
	


	









	
	
	
	
					




	
	


	
















































#line 20 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 2

    extern void nodeInduce(Agraph_t * selected);
    extern Agobj_t *clone(Agraph_t * g, Agobj_t * obj);
    extern Agraph_t *cloneG(Agraph_t * g, char* name);
    extern Agobj_t *copy(Agraph_t * g, Agobj_t * obj);
    extern int copyAttr(Agobj_t * obj, Agobj_t * obj1);
    extern int indexOf(char *s1, char *s2);
    extern int rindexOf(char *s1, char *s2);
    extern int match(char *str, char *pat);
    extern int lockGraph(Agraph_t * g, int);
    extern Agraph_t *compOf(Agraph_t * g, Agnode_t * n);
    extern Agedge_t *isEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key);
    extern Agnode_t *addNode(Agraph_t * g, Agnode_t * n, int doAdd);
    extern Agedge_t *addEdge(Agraph_t * g, Agedge_t * e, int doAdd);
    extern Agraph_t *sameG(void *p1, void *p2, char *fn, char *msg);
    extern int compare(Agobj_t *, Agobj_t *);
    extern int sfioWrite(Agraph_t *, Sfio_t*, Agiodisc_t*);
    extern int writeFile(Agraph_t *, char *, Agiodisc_t*);
    extern int fwriteFile(Expr_t *, Agraph_t *, int, Agiodisc_t*);
    extern Agraph_t *readFile(char *);
    extern Agraph_t *freadFile(Expr_t *, int);
    extern int openFile(Expr_t *, char *, char *);
    extern int closeFile(Expr_t *, int);
    extern char *readLine(Expr_t *, int);
    extern char *canon(Expr_t * pgm, char *);
    extern char *toHtml(Agraph_t*, char *);
    extern char *toLower(Expr_t * pgm, char *, Sfio_t*);
    extern char *toUpper(Expr_t * pgm, char *, Sfio_t*);
    extern int deleteObj(Agraph_t * g, Agobj_t * obj);
    extern char *colorx (Expr_t* ex, char* incolor, char* fmt, Sfio_t* fp);
    extern void gvstart_timer(void);
    extern double gvelapsed_sec(void);






#line 34 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 1
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





/*
 * macro interface for sfio write strings
 *
 * NOTE: see <stak.h> for an alternative interface
 *	 read operations require sfseek()
 */




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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 26 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 2

























    extern int sfstrtmp(Sfio_t *, int, void *, size_t);








#line 35 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
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





/*
 * standalone mini error interface
 */




#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1

    typedef struct Error_info_s {
	int errors;
	int indent;
	int line;
	int warnings;
	int trace;
	char *file;
	char *id;
    } Error_info_t;



















    extern Error_info_t _err_info;

    extern void setTraceLevel (int);
    extern void setErrorLine (int);
    extern void setErrorFileLine (char*, int);
    extern void setErrorId (char*);
    extern void setErrorErrors (int);
    extern int  getErrorErrors (void);

    extern void _err_msg(int, ...);
    extern void errorf(void *, void *, int, ...);
    extern void _err_msgv(const char *, int, va_list);






#line 36 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.c" 1








static char *Info[] = {
    "gvpr",                     /* Program */
    PACKAGE_VERSION,            /* Version */
    BUILDDATE                   /* Build Date */
};

static const char *usage =
    " [-o <ofile>] [-a <args>] ([-f <prog>] | 'prog') [files]\n   -c         - use source graph for output\n   -f <pfile> - find program in file <pfile>\n   -i         - create node induced subgraph\n   -a <args>  - string arguments available as ARGV[0..]\n   -o <ofile> - write output to <ofile>; stdout by default\n   -n         - no read-ahead of input graphs\n   -q         - turn off warning messages\n   -V         - print version info\n   -?         - print usage info\nIf no files are specified, stdin is used\n";











typedef struct {
    char *cmdName;              /* command name */
    Sfio_t *outFile;		/* output stream; stdout default */
    char *program;              /* program source */
    int useFile;		/* true if program comes from a file */
    int compflags;
    int readAhead;
    char **inFiles;
    int argc;
    char **argv;
    int state;                  /* > 0 : continue; <= 0 finish */
    int verbose;
} options;

static Sfio_t *openOut(char *name)
{
    Sfio_t *outs;

    outs = sfopen(0, name, "w");
    if (outs == 0) {
	_err_msg(2, "could not open %s for writing", name);
    }
    return outs;
}

/* gettok:
 * Tokenize a string. Tokens consist of either a non-empty string
 * of non-space characters, or all characters between a pair of
 * single or double quotes. As usual, we map 
 *   \c -> c
 * for all c
 * Return next argument token, returning NULL if none.
 * sp is updated to point to next character to be processed.
 * NB. There must be white space between tokens. Otherwise, they
 * are concatenated.
 */
static char *gettok(char **sp)
{
    char *s = *sp;
    char *ws = s;
    char *rs = s;
    char c;
    char q = '\0';		/* if non-0, in quote mode with quote char q */

    while (isspace(*rs))
	rs++;
    if ((c = *rs) == '\0')
	return 0;
    while ((c = *rs)) {
	if (q && (q == c)) {	/* end quote */
	    q = '\0';
	} else if (!q && ((c == '"') || (c == '\''))) {
	    q = c;
	} else if (c == '\\') {
	    rs++;
	    c = *rs;
	    if (c)
		*ws++ = c;
	    else {
		_err_msg(1,
		      "backslash in argument followed by no character - ignored");
		rs--;
	    }
	} else if (q || !isspace(c))
	    *ws++ = c;
	else
	    break;
	rs++;
    }
    if (*rs)
	rs++;
    else if (q)
	_err_msg(1, "no closing quote for argument %s", s);
    *sp = rs;
    *ws = '\0';
    return s;
}



/* parseArgs:
 * Split s into whitespace separated tokens, allowing quotes.
 * Append tokens to argument list and return new number of arguments.
 * argc is the current number of arguments, with the arguments
 * stored in *argv.
 */
static int parseArgs(char *s, int argc, char ***argv)
{
    int i, cnt = 0;
    char *args[100];
    char *t;
    char **av;

    while ((t = gettok(&s))) {
	if (cnt == 100) {
	    _err_msg(1,
		  "at most %d arguments allowed per -a flag - ignoring rest",
		  100);
	    break;
	}
	args[cnt++] = t;
    }

    if (cnt) {
	int oldcnt = argc;
	argc = oldcnt + cnt;
	av = ((*argv)?(char **)realloc((char*)(*argv),sizeof(char *)*(argc)+(0)):(char **)malloc(sizeof(char *)*(argc)+(0)));
	for (i = 0; i < cnt; i++)
	    av[oldcnt + i] = strdup(args[i]);
	*argv = av;
    }
    return argc;
}










static Sfio_t*
concat (char* pfx, char* sfx, char** sp)
{
    Sfio_t *pathp;
    if (!(pathp = sfnew((Sfio_t*)0,(char*)0,-1,-1,0000002|0000004))) {
	_err_msg(2, "Could not open buffer");
	return 0;
    }
    sfprintf(pathp, "%s%s", pfx, sfx);
    *sp = (( (((Sfio_t*)((pathp)))->next >= ((Sfio_t*)((pathp)))->endw ? _sfflsbuf(((Sfio_t*)((pathp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((pathp)))->next++ = (unsigned char)((0))) ) ), (char*)((pathp)->next = (pathp)->data) );
    return pathp;
}

/* resolve:
 * Translate -f arg parameter into a pathname.
 * If arg contains '/', return arg.
 * Else search directories in GVPRPATH for arg.
 * Return NULL on error.
 * 
 * FIX - use pathinclude/pathfind
 */
static char *resolve(char *arg, int Verbose)
{
    char *path;
    char *s;
    char *cp;
    char c;
    char *fname = 0;
    Sfio_t *fp;
    Sfio_t *pathp = 0;
    size_t sz;


    

    if (strchr(arg, '/'))

	return strdup(arg);

    path = getenv("GVPRPATH");
    if (!path)
	path = getenv("GPRPATH");  // deprecated
    if (path && (c = *path)) {
	if (c == ':') {
	    pathp = concat(".", path, &path); 
	}
	else if ((c = path[strlen(path)-1]) == ':') {
	    pathp = concat(path, ".", &path); 
	}
    }
    else
	path = ".";
    if (Verbose)
	fprintf (stderr, "PATH: %s\n", path);
    if (!(fp = sfnew((Sfio_t*)0,(char*)0,-1,-1,0000002|0000004))) {
	_err_msg(2, "Could not open buffer");
	return 0;
    }

    while (*path && !fname) {
	if (*path == ':') {	/* skip colons */
	    path++;
	    continue;
	}
	cp = strchr(path, ':');
	if (cp) {
	    sz = (size_t) (cp - path);
	    sfwrite(fp, path, sz);
	    path = cp + 1;	/* skip past current colon */
	} else {
	    sz = sfprintf(fp, path);
	    path += sz;
	}
	( (((Sfio_t*)((fp)))->next >= ((Sfio_t*)((fp)))->endw ? _sfflsbuf(((Sfio_t*)((fp))),(int)((unsigned char)(('/')))) : (int)(*((Sfio_t*)((fp)))->next++ = (unsigned char)(('/'))) ) );
	sfprintf(fp, arg);
	s = (( (((Sfio_t*)((fp)))->next >= ((Sfio_t*)((fp)))->endw ? _sfflsbuf(((Sfio_t*)((fp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((fp)))->next++ = (unsigned char)((0))) ) ), (char*)((fp)->next = (fp)->data) );

	if (access(s, 4) == 0) {
	    fname = strdup(s);
	}
    }

    if (!fname)
	_err_msg(2, "Could not find file \"%s\" in GVPRPATH", arg);

    sfclose(fp);
    if (pathp)
	sfclose(pathp);
    if (Verbose)
	fprintf (stderr, "file %s resolved to %s\n", arg, fname);
    return fname;
}

static char*
getOptarg (int c, char** argp, int* argip, int argc, char** argv)
{
    char* rv; 
    char* arg = *argp;
    int argi = *argip;

    if (*arg) {
	rv = arg;
	while (*arg) arg++; 
	*argp = arg;
    }
    else if (argi < argc) {
	rv = argv[argi++];
	*argip = argi;
    } 
    else {
	rv = 0;
	_err_msg(1, "missing argument for option -%c", c);
    }
    return rv;
}

/* doFlags:
 * Process a command-line argument starting with a '-'.
 * argi is the index of the next available item in argv[].
 * argc has its usual meaning.
 *
 * return > 0 given next argi value
 *        = 0 for exit with 0
 *        < 0 for error
 */
static int
doFlags(char* arg, int argi, int argc, char** argv, options* opts)
{
    int c;

    while ((c = *arg++)) {
	switch (c) {
	case 'c':
	    opts->compflags |= 0x1;
	    break;
	case 'C':
	    opts->compflags |= (0x1|0x4);
	    break;
	case 'f':
	    if ((optarg = getOptarg(c, &arg, &argi, argc, argv)) && (opts->program = resolve(optarg, opts->verbose))) {
		opts->useFile = 1;
	    }
	    else return -1;
	    break;
	case 'i':
	    opts->compflags |= 0x2;
	    break;
	case 'n':
	    opts->readAhead = 0;
	    break;
	case 'a':
	    if ((optarg = getOptarg(c, &arg, &argi, argc, argv))) {
		opts->argc = parseArgs(optarg, opts->argc, &(opts->argv));
	    }
	    else return -1;
	    break;
	case 'o':
	    if (!(optarg = getOptarg(c, &arg, &argi, argc, argv)) || !(opts->outFile = openOut(optarg)))
		return -1;
	    break;
	case 'q':
	    setTraceLevel (2);  /* Don't emit warning messages */
	    break;
	case 'v':
	    opts->verbose = 1;
	    break;
	case 'V':
	    sfprintf(sfstderr, "%s version %s (%s)\n",
		    Info[0], Info[1], Info[2]);
	    return 0;
	    break;
	case '?':
	    _err_msg(0x0800|1, "%s", usage);
	    return 0;
	    break;
	default :
	    _err_msg(1, "option -%c unrecognized", c);
	    break;
	}
    }
    return argi;
}

static void
freeOpts (options* opts)
{
    int i;
    if (!opts) return;
    if (opts->outFile != sfstdout)
	sfclose (opts->outFile);
    free (opts->inFiles);
    if (opts->useFile)
	free (opts->program);
    if (opts->argc) {
	for (i = 0; i < opts->argc; i++)
	    free (opts->argv[i]);
	free (opts->argv);
    }
    free (opts);
}

/* scanArgs:
 * Parse command line options.
 */
static options* scanArgs(int argc, char **argv, gvpropts* uopts)
{
    int i, nfiles;
    char** input_filenames;
    char* arg;
    options* opts = ((0)?(options*)realloc((char*)(0),sizeof(options)*(1)+(0)):(options*)calloc(1,sizeof(options)*(1)+(0)));

    opts->cmdName = argv[0];
    opts->state = 1;
    opts->readAhead = 1;
    setErrorId (opts->cmdName);
    opts->verbose = 0;

    /* estimate number of file names */
    nfiles = 0;
    for (i = 1; i < argc; i++)
	if (argv[i] && argv[i][0] != '-')
	    nfiles++;
    input_filenames = ((0)?(char**)realloc((char*)(0),sizeof(char*)*(nfiles + 1)+(0)):(char**)calloc(1,sizeof(char*)*(nfiles + 1)+(0)));

    /* loop over arguments */
    nfiles = 0;
    for (i = 1; i < argc; ) {
	arg = argv[i++];
	if (*arg == '-') {
	    i = doFlags (arg+1, i, argc, argv, opts);
	    if (i <= 0) {
		opts->state = i;
		goto opts_done;
	    }
	} else if (arg)
	    input_filenames[nfiles++] = arg;
    }

    /* Handle additional semantics */
    if (opts->useFile == 0) {
	if (nfiles == 0) {
	    _err_msg(2,
		  "No program supplied via argument or -f option");
	    opts->state = -1;
	} else {
	    opts->program = input_filenames[0];
	    for (i = 1; i <= nfiles; i++)
		input_filenames[i-1] = input_filenames[i];
	    nfiles--;
	}
    }
    if (nfiles == 0) {
	opts->inFiles = 0;
	free (input_filenames);
	input_filenames = 0;
    }
    else
	opts->inFiles = input_filenames;

    if (!(opts->outFile))
	opts->outFile = sfstdout;

  opts_done:
    if (opts->state <= 0) {
	if (opts->state < 0)
	    _err_msg(0x0800|2, "%s", usage);
	free (input_filenames);
    }

    return opts;
}

static Agobj_t* evalEdge(Gpr_t * state, Expr_t* prog, comp_block * xprog, Agedge_t * e)
{
    int i;
    case_stmt *cs;
    int okay;

    state->curobj = (Agobj_t *) e;
    for (i = 0; i < xprog->n_estmts; i++) {
	cs = xprog->edge_stmts + i;
	if (cs->guard)
	    okay = (exeval(prog, cs->guard, state)).integer;
	else
	    okay = 1;
	if (okay) {
	    if (cs->action)
		exeval(prog, cs->action, state);
	    else
		agsubedge(state->target, e, (!(0)));
	}
    }
    return state->curobj;
}

static Agobj_t* evalNode(Gpr_t * state, Expr_t* prog, comp_block * xprog, Agnode_t * n)
{
    int i;
    case_stmt *cs;
    int okay;

    state->curobj = (Agobj_t *) n;
    for (i = 0; i < xprog->n_nstmts; i++) {
	cs = xprog->node_stmts + i;
	if (cs->guard)
	    okay = (exeval(prog, cs->guard, state)).integer;
	else
	    okay = 1;
	if (okay) {
	    if (cs->action)
		exeval(prog, cs->action, state);
	    else
		agsubnode(state->target, n, (!(0)));
	}
    }
    return (state->curobj);
}

typedef struct {
    Agnode_t *oldroot;
    Agnode_t *prev;
} nodestream;

static Agnode_t *nextNode(Gpr_t * state, nodestream * nodes)
{
    Agnode_t *np;

    if (state->tvroot != nodes->oldroot) {
	np = nodes->oldroot = state->tvroot;
    } else if (state->flags & 8) {
	np = nodes->oldroot = state->tvroot = state->tvnext;
	state->flags &= ~8;
    } else if (nodes->prev) {
	np = nodes->prev = agnxtnode(state->curgraph, nodes->prev);
    } else {
	np = nodes->prev = agfstnode(state->curgraph);
    }
    return np;
}







typedef Agedge_t *(*fstedgefn_t) (Agraph_t *, Agnode_t *);
typedef Agedge_t *(*nxttedgefn_t) (Agraph_t *, Agedge_t *, Agnode_t *);




typedef struct {
    fstedgefn_t fstedge;
    nxttedgefn_t nxtedge;
    unsigned char undirected;
    unsigned char visit;
} trav_fns;

static trav_fns DFSfns = { agfstedge, agnxtedge, 1, 0 };
static trav_fns FWDfns = { agfstout, (nxttedgefn_t) agnxtout, 0, 0 };
static trav_fns REVfns = { agfstin, (nxttedgefn_t) agnxtin, 0, 0 };

static void travBFS(Gpr_t * state, Expr_t* prog, comp_block * xprog)
{
    nodestream nodes;
    queue *q;
    ndata *nd;
    Agnode_t *n;
    Agedge_t *cure;
    Agedge_t *nxte;
    Agraph_t *g = state->curgraph;

    q = mkQ(Dtqueue);
    nodes.oldroot = 0;
    nodes.prev = 0;
    while ((n = nextNode(state, &nodes))) {
	nd = ((ndata*)(aggetrec(n,"userval",0)));
	if ((((nd)->iu.integer)&1))
	    continue;
	(((nd)->iu.integer)|=2,(nd)->ine=(0));
	push(q, n);
	while ((n = (pop(q,1)))) {
	    nd = ((ndata*)(aggetrec(n,"userval",0)));
	    (((nd)->iu.integer) = 1);
	    (((nd)->iu.integer)&=(~2));
	    state->tvedge = nd->ine;
	    if (!evalNode(state, prog, xprog, n)) continue;
	    for (cure = agfstedge(g, n); cure; cure = nxte) {
		nxte = agnxtedge(g, cure, n);
		nd = ((ndata*)(aggetrec(cure->node,"userval",0)));
		if ((((nd)->iu.integer)&1))
		    continue;
		if (!evalEdge(state, prog, xprog, cure)) continue;
		if (!(((nd)->iu.integer)&2)) {
		    push(q, cure->node);
		    (((nd)->iu.integer)|=2,(nd)->ine=(cure));
		}
	    }
	}
    }
    state->tvedge = 0;
    freeQ(q);
}

static void travDFS(Gpr_t * state, Expr_t* prog, comp_block * xprog, trav_fns * fns)
{
    Agnode_t *n;
    queue *stk;
    Agnode_t *curn;
    Agedge_t *cure;
    Agedge_t *entry;
    int more;
    ndata *nd;
    nodestream nodes;
    Agedgepair_t seed;

    stk = mkQ(Dtstack);
    nodes.oldroot = 0;
    nodes.prev = 0;
    while ((n = nextNode(state, &nodes))) {
	nd = ((ndata*)(aggetrec(n,"userval",0)));
	if ((((nd)->iu.integer)&1))
	    continue;
	seed.out.node = n;
	seed.in.node = 0;
	curn = n;
	entry = &(seed.out);
	state->tvedge = cure = 0;
	(((nd)->iu.integer) = 1);
	(((nd)->iu.integer)|=2,(nd)->ine=(0));
	if (fns->visit & 1)
	    evalNode(state, prog, xprog, n);
	more = 1;
	while (more) {
	    if (cure)
		cure = fns->nxtedge(state->curgraph, cure, curn);
	    else
		cure = fns->fstedge(state->curgraph, curn);
	    if (cure) {
		if (entry == ((((((Agobj_t*)(cure))->tag).objtype)==3)?((cure)-1):((cure)+1)))	/* skip edge used to get here */
		    continue;
		nd = ((ndata*)(aggetrec(cure->node,"userval",0)));
		if ((((nd)->iu.integer)&1)) {
		    /* For undirected DFS, visit an edge only if its head
		     * is on the stack, to avoid visiting it twice.
		     * This is no problem in directed DFS.
		     */
		    if (fns->undirected) {
			if ((((nd)->iu.integer)&2))
			    evalEdge(state, prog, xprog, cure);
		    } else
			evalEdge(state, prog, xprog, cure);
		} else {
		    evalEdge(state, prog, xprog, cure);
		    push(stk, entry);
		    state->tvedge = entry = cure;
		    curn = cure->node;
		    cure = 0;
		    if (fns->visit & 1)
			evalNode(state, prog, xprog, curn);
		    (((nd)->iu.integer) = 1);
		    (((nd)->iu.integer)|=2,(nd)->ine=(entry));
		}
	    } else {
		if (fns->visit & 2)
		    evalNode(state, prog, xprog, curn);
		nd = ((ndata*)(aggetrec(curn,"userval",0)));
		(((nd)->iu.integer)&=(~2));
		cure = entry;
		entry = (Agedge_t *) (pop(stk,1));
		if (entry == &(seed.out))
		    state->tvedge = 0;
		else
		    state->tvedge = entry;
		if (entry)
		    curn = entry->node;
		else
		    more = 0;
	    }
	}
    }
    state->tvedge = 0;
    freeQ(stk);
}

static void travNodes(Gpr_t * state, Expr_t* prog, comp_block * xprog)
{
    Agnode_t *n;
    Agnode_t *next;
    Agraph_t *g = state->curgraph;
    for (n = agfstnode(g); n; n = next) {
	next =  agnxtnode(g, n);
	evalNode(state, prog, xprog, n);
    }
}

static void travEdges(Gpr_t * state, Expr_t* prog, comp_block * xprog)
{
    Agnode_t *n;
    Agnode_t *next;
    Agedge_t *e;
    Agedge_t *nexte;
    Agraph_t *g = state->curgraph;
    for (n = agfstnode(g); n; n = next) {
	next = agnxtnode(g, n);
	for (e = agfstout(g, n); e; e = nexte) {
	    nexte = agnxtout(g, e);
	    evalEdge(state, prog, xprog, e);
	}
    }
}

static void travFlat(Gpr_t * state, Expr_t* prog, comp_block * xprog)
{
    Agnode_t *n;
    Agnode_t *next;
    Agedge_t *e;
    Agedge_t *nexte;
    Agraph_t *g = state->curgraph;
    for (n = agfstnode(g); n; n = next) {
	next =  agnxtnode(g, n);
	if (!evalNode(state, prog, xprog, n)) continue;
	if (xprog->n_estmts > 0) {
	    for (e = agfstout(g, n); e; e = nexte) {
		nexte = agnxtout(g, e);
		evalEdge(state, prog, xprog, e);
	    }
	}
    }
}

/* doCleanup:
 * Reset node traversal data
 */
static void doCleanup (Agraph_t* g)
{
    Agnode_t *n;
    ndata *nd;

    for (n = agfstnode(g); n; n =  agnxtnode(g, n)) {
	nd = ((ndata*)(aggetrec(n,"userval",0)));
	nd->ine = 0;
	nd->iu.integer = 0;
    }
}

/* traverse:
 * return 1 if traversal requires cleanup
 */
static int traverse(Gpr_t * state, Expr_t* prog, comp_block * bp, int cleanup)
{
    char *target;

    if (!state->target) {
	if (state->name_used) {
	    sfprintf(state->tmp, "%s%d", state->tgtname, state->name_used);
	    target = (( (((Sfio_t*)((state->tmp)))->next >= ((Sfio_t*)((state->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((state->tmp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((state->tmp)))->next++ = (unsigned char)((0))) ) ), (char*)((state->tmp)->next = (state->tmp)->data) );
	} else
	    target = state->tgtname;
	state->name_used++;
	/* make sure target subgraph does not exist */
	while (agsubg (state->curgraph, target, 0)) {
	    state->name_used++;
	    sfprintf(state->tmp, "%s%d", state->tgtname, state->name_used);
	    target = (( (((Sfio_t*)((state->tmp)))->next >= ((Sfio_t*)((state->tmp)))->endw ? _sfflsbuf(((Sfio_t*)((state->tmp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((state->tmp)))->next++ = (unsigned char)((0))) ) ), (char*)((state->tmp)->next = (state->tmp)->data) );
	}
	state->target = openSubg(state->curgraph, target);
    }
    if (!state->outgraph)
	state->outgraph = state->target;

    switch (state->tvt) {
    case TV_flat:
	travFlat(state, prog, bp);
	break;
    case TV_bfs:
	if (cleanup) doCleanup (state->curgraph);
	travBFS(state, prog, bp);
	cleanup = 1;
	break;
    case TV_dfs:
	if (cleanup) doCleanup (state->curgraph);
	DFSfns.visit = 1;
	travDFS(state, prog, bp, &DFSfns);
	cleanup = 1;
	break;
    case TV_fwd:
	if (cleanup) doCleanup (state->curgraph);
	FWDfns.visit = 1;
	travDFS(state, prog, bp, &FWDfns);
	cleanup = 1;
	break;
    case TV_rev:
	if (cleanup) doCleanup (state->curgraph);
	REVfns.visit = 1;
	travDFS(state, prog, bp, &REVfns);
	cleanup = 1;
	break;
    case TV_postdfs:
	if (cleanup) doCleanup (state->curgraph);
	DFSfns.visit = 2;
	travDFS(state, prog, bp, &DFSfns);
	cleanup = 1;
	break;
    case TV_postfwd:
	if (cleanup) doCleanup (state->curgraph);
	FWDfns.visit = 2;
	travDFS(state, prog, bp, &FWDfns);
	cleanup = 1;
	break;
    case TV_postrev:
	if (cleanup) doCleanup (state->curgraph);
	REVfns.visit = 2 | 1;
	travDFS(state, prog, bp, &REVfns);
	cleanup = 1;
	break;
    case TV_prepostdfs:
	if (cleanup) doCleanup (state->curgraph);
	DFSfns.visit = 2 | 1;
	travDFS(state, prog, bp, &DFSfns);
	cleanup = 1;
	break;
    case TV_prepostfwd:
	if (cleanup) doCleanup (state->curgraph);
	FWDfns.visit = 2 | 1;
	travDFS(state, prog, bp, &FWDfns);
	cleanup = 1;
	break;
    case TV_prepostrev:
	if (cleanup) doCleanup (state->curgraph);
	REVfns.visit = 2;
	travDFS(state, prog, bp, &REVfns);
	cleanup = 1;
	break;
    case TV_ne:
	travNodes(state, prog, bp);
	travEdges(state, prog, bp);
	break;
    case TV_en:
	travEdges(state, prog, bp);
	travNodes(state, prog, bp);
	break;
    }
    return cleanup;
}

/* addOutputGraph:
 * Append output graph to option struct.
 * We know uopts and state->outgraph are non-NULL.
 */
static void
addOutputGraph (Gpr_t* state, gvpropts* uopts)
{
    Agraph_t* g = state->outgraph;

    if ((agroot(g) == state->curgraph) && !uopts->ingraphs)
	g = (Agraph_t*)clone (0, (Agobj_t *)g);

    uopts->n_outgraphs++;
    uopts->outgraphs = ((uopts->outgraphs)?(Agraph_t**)realloc((char*)(uopts->outgraphs),sizeof(Agraph_t*)*(uopts->n_outgraphs)+(0)):(Agraph_t**)malloc(sizeof(Agraph_t*)*(uopts->n_outgraphs)+(0)));
    uopts->outgraphs[uopts->n_outgraphs-1] = g;
}

static void chkClose(Agraph_t * g)
{
    gdata *data;

    data = ((gdata*)(aggetrec(g,"userval",0)));
    if (data->lock & 1)
	data->lock |= 2;
    else
	agclose(g);
}

static void *ing_open(char *f)
{
    return sfopen(0, f, "r");
}

static Agraph_t *ing_read(void *fp)
{
    return readG((Sfio_t *) fp);
}

static int ing_close(void *fp)
{
    return sfclose((Sfio_t *) fp);
}

static ingdisc ingDisc = { ing_open, ing_read, ing_close, 0 };

static void
setDisc (Sfio_t* sp, Sfdisc_t* dp, gvprwr fn)
{
    dp->readf = 0;
    dp->writef = (Sfwrite_f)fn;
    dp->seekf = 0;
    dp->exceptf = 0;
    dp->disc = 0;
    dp = sfdisc (sp, dp);
}

static jmp_buf jbuf;

/* gvexitf:
 * Only used if GV_USE_EXIT not set during exeval.
 * This implies setjmp/longjmp set up.
 */
static void 
gvexitf (Expr_t *handle, Exdisc_t *discipline, int v)
{
    longjmp (jbuf, v);
}

static int 
gverrorf (Expr_t *handle, Exdisc_t *discipline, int level, ...)
{
    va_list ap;

    va_start(ap, level);
    _err_msgv((discipline
	    && handle) ? *((char **) handle) : (char *) handle, level, ap);
    va_end(ap);

    if (level >= 2) {
	Gpr_t *state = (Gpr_t*)(discipline->user);
	if (state->flags & 1)
            exit(1);
	else if (state->flags & 4)
	    longjmp (jbuf, 1);
    }

    return 0;
}

/* gvpr:
 * main loop for gvpr.
 * Return 0 on success; non-zero on error.
 *
 * FIX/TODO:
 *  - close non-source/non-output graphs
 *  - flag to clone target graph?
 *  - remove assignment in boolean warning if wrapped in ()
 *  - do automatic cast for array indices if type is known
 *  - array initialization
 */
int gvpr (int argc, char *argv[], gvpropts * uopts)
{
    Sfdisc_t errdisc;
    Sfdisc_t outdisc;
    parse_prog *prog = 0;
    ingraph_state *ing = 0;
    comp_prog *xprog = 0;
    Gpr_t *state = 0;
    gpr_info info;
    int rv = 0;
    options* opts = 0;
    int cleanup, i, incoreGraphs;
    Agraph_t* nextg = 0;

    setErrorErrors (0);
    ingDisc.dflt = sfstdin;
    if (uopts) {
	if (uopts->out) setDisc (sfstdout, &outdisc, uopts->out);
	if (uopts->err) setDisc (sfstderr, &errdisc, uopts->err);
    }

    opts = scanArgs(argc, argv, uopts);
    if (opts->state <= 0) {
	rv = opts->state;
	goto finish;
    }

    if (opts->verbose)
	gvstart_timer ();
    prog = parseProg(opts->program, opts->useFile);
    if (!prog) {
	rv = 1;
	goto finish;
    }
    info.outFile = opts->outFile;
    info.argc = opts->argc;
    info.argv = opts->argv;
    info.errf = (Exerror_f)gverrorf;
    if (uopts) 
	info.flags = uopts->flags; 
    else
	info.flags = 0;
    if ((uopts->flags & 1))
	info.exitf = 0;
    else
	info.exitf = gvexitf;
    state = openGPRState(&info);
    if (!state) {
	rv = 1;
	goto finish;
    }
    if (uopts->bindings)
	addBindings (state, uopts->bindings);
    xprog = compileProg(prog, state, opts->compflags);
    if (!xprog) {
	rv = 1;
	goto finish;
    }

    initGPRState(state, xprog->prog->vm);
    
    if ((uopts->flags & 2)) {
	uopts->outgraphs = 0;
	uopts->n_outgraphs = 0;
    }

    if (!(uopts->flags & 1)) {
	state->flags |= 4;
	if ((rv = setjmp (jbuf))) {
	    goto finish;
	}
    }

    if (uopts && uopts->ingraphs)
	incoreGraphs = 1;
    else
	incoreGraphs = 0;

    if (opts->verbose)
	sfprintf (sfstderr, "Parse/compile/init: %.2f secs.\n", gvelapsed_sec());
    /* do begin */
    if (xprog->begin_stmt)
	exeval(xprog->prog, xprog->begin_stmt, state);

    /* if program is not null */
    if (usesGraph(xprog)) {
	if (uopts && uopts->ingraphs)
	    ing = newIngGraphs(0, uopts->ingraphs, &ingDisc);
	else
	    ing = newIng(0, opts->inFiles, &ingDisc);
	
	if (opts->verbose) gvstart_timer ();
	for (state->curgraph = nextGraph(ing); state->curgraph; state->curgraph = nextg) {
	    if (opts->verbose) sfprintf (sfstderr, "Read graph: %.2f secs.\n", gvelapsed_sec());
	    state->infname = fileName(ing);
	    if (opts->readAhead)
		nextg = state->nextgraph = nextGraph(ing);
	    cleanup = 0;

	    for (i = 0; i < xprog->n_blocks; i++) {
		comp_block* bp = xprog->blocks + i;

		/* begin graph */
		if (incoreGraphs && (opts->compflags & 0x4))
		    state->curgraph = (Agraph_t*)clone (0, (Agobj_t*)(state->curgraph));
		state->curobj = (Agobj_t *) state->curgraph;
		state->tvroot = 0;
		state->tvt = TV_flat;
		if (bp->begg_stmt)
		    exeval(xprog->prog, bp->begg_stmt, state);

		/* walk graph */
		if (walksGraph(bp)) {
		    cleanup = traverse(state, xprog->prog, bp, cleanup);
		}
	    }

	    /* end graph */
	    state->curobj = (Agobj_t *) state->curgraph;
	    if (xprog->endg_stmt)
		exeval(xprog->prog, xprog->endg_stmt, state);
	    if (opts->verbose) sfprintf (sfstderr, "Finish graph: %.2f secs.\n", gvelapsed_sec());

	    /* if $O == $G and $T is empty, delete $T */
	    if ((state->outgraph == state->curgraph) &&
		(state->target) && !agnnodes(state->target))
		agdelete(state->curgraph, state->target);

	    /* output graph, if necessary
	     * For this, the outgraph must be defined, and either
	     * be non-empty or the -c option was used.
	     */
	    if (state->outgraph && (agnnodes(state->outgraph)
				    || (opts->compflags & 0x1))) {
		if (uopts && (uopts->flags & 2))
		    addOutputGraph (state, uopts);
		else
		    sfioWrite (state->outgraph, opts->outFile, state->dfltIO);
	    }

	    if (!incoreGraphs)
		chkClose(state->curgraph);
	    state->target = 0;
	    state->outgraph = 0;
	
	    if (opts->verbose) gvstart_timer ();
	    if (!opts->readAhead)
		nextg = nextGraph(ing);
	    if (opts->verbose && nextg) sfprintf (sfstderr, "Read graph: %.2f secs.\n", gvelapsed_sec());
	}
    }

	/* do end */
    state->curgraph = 0;
    state->curobj = 0;
    if (xprog->end_stmt)
	exeval(xprog->prog, xprog->end_stmt, state);

  finish:
    /* free all allocated resources */
    freeParseProg (prog);
    freeCompileProg (xprog);
    closeGPRState(state);
    if (ing) closeIngraph (ing);
    freeOpts (opts);

    if (uopts) {
	if (uopts->out) sfdisc (sfstdout, 0);
	if (uopts->err) sfdisc (sfstderr, 0);
    }

    return rv;
}

