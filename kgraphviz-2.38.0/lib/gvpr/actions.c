#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
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
 *  Code for main functions in gpr
 */

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
	(Sfio_t *, void *, size_t, Sfdisc_t *);
    typedef ssize_t(*Sfwrite_f)
	(Sfio_t *, const void *, size_t, Sfdisc_t *);
    typedef _ast_intmax_t(*Sfseek_f) (Sfio_t *, _ast_intmax_t, int, Sfdisc_t *);
    typedef int (*Sfexcept_f) (Sfio_t *, int, void *, Sfdisc_t *);

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
    typedef int (*Sffmtext_f) (Sfio_t *, void *, Sffmt_t *);
    typedef int (*Sffmtevent_f)
	(Sfio_t *, int, void *, Sffmt_t *);
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

	void *noop;		/* as yet unused                        */
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















    extern Sfio_t *sfnew (Sfio_t *, void *, size_t, int, int);
    extern Sfio_t *sfopen (Sfio_t *, const char *, const char *);
    extern Sfio_t *sfpopen (Sfio_t *, const char *, const char *);
    extern Sfio_t *sfstack (Sfio_t *, Sfio_t *);
    extern Sfio_t *sfswap (Sfio_t *, Sfio_t *);
    extern Sfio_t *sftmp (size_t);
    extern int sfpurge (Sfio_t *);
    extern int sfpoll (Sfio_t **, int, int);
    extern void *sfreserve (Sfio_t *, ssize_t, int);
    extern int sfsync (Sfio_t *);
    extern int sfclrlock (Sfio_t *);
    extern void *sfsetbuf (Sfio_t *, void *, size_t);
    extern Sfdisc_t *sfdisc (Sfio_t *, Sfdisc_t *);
    extern int sfraise (Sfio_t *, int, void *);
    extern int sfnotify (void(*)(Sfio_t *, int, int));
    extern int sfset (Sfio_t *, int, int);
    extern int sfsetfd (Sfio_t *, int);
    extern Sfio_t *sfpool (Sfio_t *, Sfio_t *, int);
    extern ssize_t sfread (Sfio_t *, void *, size_t);
    extern ssize_t sfwrite (Sfio_t *, const void *, size_t);
    extern _ast_intmax_t sfmove (Sfio_t *, Sfio_t *, _ast_intmax_t, int);
    extern int sfclose (Sfio_t *);
    extern _ast_intmax_t sftell (Sfio_t *);
    extern _ast_intmax_t sfseek (Sfio_t *, _ast_intmax_t, int);
    extern ssize_t sfputr (Sfio_t *, const char *, int);
    extern char *sfgetr (Sfio_t *, int, int);
    extern ssize_t sfnputc (Sfio_t *, int, size_t);
    extern int sfungetc (Sfio_t *, int);
    extern int sfprintf (Sfio_t *, const char *, ...);
    extern char *sfprints (const char *, ...);
    extern int sfsprintf (char *, int, const char *, ...);
    extern int sfvsprintf (char *, int, const char *, va_list);
    extern int sfvprintf (Sfio_t *, const char *, va_list);
    extern int sfscanf (Sfio_t *, const char *, ...);
    extern int sfsscanf (const char *, const char *, ...);
    extern int sfvsscanf (const char *, const char *, va_list);
    extern int sfvscanf (Sfio_t *, const char *, va_list);
    extern int sfresize (Sfio_t *, _ast_intmax_t);

/* mutex locking for thread-safety */
    extern int sfmutex (Sfio_t *, int);

/* io functions with discipline continuation */
    extern ssize_t sfrd (Sfio_t *, void *, size_t, Sfdisc_t *);
    extern ssize_t sfwr
	(Sfio_t *, const void *, size_t, Sfdisc_t *);
    extern _ast_intmax_t sfsk (Sfio_t *, _ast_intmax_t, int, Sfdisc_t *);
    extern ssize_t sfpkrd (int, void *, size_t, int, long, int);

/* portable handling of primitive types */
    extern int sfdlen (_ast_fltmax_t);
    extern int sfllen (_ast_intmax_t);
    extern int sfulen (unsigned _ast_intmax_t);

    extern int sfputd (Sfio_t *, _ast_fltmax_t);
    extern int sfputl (Sfio_t *, _ast_intmax_t);
    extern int sfputu (Sfio_t *, unsigned _ast_intmax_t);
    extern int sfputm (Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t);
    extern int sfputc (Sfio_t *, int);

    extern _ast_fltmax_t sfgetd (Sfio_t *);
    extern _ast_intmax_t sfgetl (Sfio_t *);
    extern unsigned _ast_intmax_t sfgetu (Sfio_t *);
    extern unsigned _ast_intmax_t sfgetm (Sfio_t *, unsigned _ast_intmax_t);
    extern int sfgetc (Sfio_t *);

    extern int _sfputd (Sfio_t *, _ast_fltmax_t);
    extern int _sfputl (Sfio_t *, _ast_intmax_t);
    extern int _sfputu (Sfio_t *, unsigned _ast_intmax_t);
    extern int _sfputm (Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t);
    extern int _sfflsbuf (Sfio_t *, int);

    extern int _sffilbuf (Sfio_t *, int);

    extern int _sfdlen (_ast_fltmax_t);
    extern int _sfllen (_ast_intmax_t);
    extern int _sfulen (unsigned _ast_intmax_t);

/* miscellaneous function analogues of fast in-line functions */
    extern _ast_intmax_t sfsize (Sfio_t *);
    extern int sfclrerr (Sfio_t *);
    extern int sfeof (Sfio_t *);
    extern int sferror (Sfio_t *);
    extern int sffileno (Sfio_t *);
    extern int sfstacked (Sfio_t *);
    extern ssize_t sfvalue (Sfio_t *);
    extern ssize_t sfslen (void);


     
/* coding long integers in a portable and compact fashion */




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















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






#line 21 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
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






#line 22 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
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
































































    
    
			  
    
			    
    
    
			 
    
    

    
    
    
    
    
    
			  

    

    
    
    
    
    






#line 23 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
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






#line 24 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
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








#line 25 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1



/* sameG:
 * Return common root if objects belong to same root graph.
 * NULL otherwise
 */
Agraph_t *sameG(void *p1, void *p2, char *fn, char *msg)
{
    Agobj_t *obj1 = ((Agobj_t*)p1);
    Agobj_t *obj2 = ((Agobj_t*)p2);
    Agraph_t *root;

    root = agroot(agraphof(obj1));
    if (root != agroot(agraphof(obj2))) {
	if (msg)
	    _err_msg(1, "%s in %s() belong to different graphs",
		  msg, fn);
	else
	    _err_msg(1,
		  "%s and %s in %s() belong to different graphs",
		  ((((((Agobj_t*)(obj1))->tag).objtype) == 0) ? "graph" : (((((Agobj_t*)(obj1))->tag).objtype) == 1) ? "node" : "edge"), ((((((Agobj_t*)(obj2))->tag).objtype) == 0) ? "graph" : (((((Agobj_t*)(obj2))->tag).objtype) == 1) ? "node" : "edge"), fn);
	return 0;
    } else
	return root;
}

/* indexOf:
 * Return index of leftmost string s2 in string s1, or -1
 */
int indexOf(char *s1, char *s2)
{
    char c1 = *s2;
    char c;
    char *p;
    int len2;

    if (c1 == '\0')
	return 0;
    p = s1;
    len2 = strlen(s2) - 1;
    while ((c = *p++)) {
	if (c != c1)
	    continue;
	if (strncmp(p, s2 + 1, len2) == 0)
	    return ((p - s1) - 1);
    }
    return -1;
}

/* rindexOf:
 * Return index of rightmost string s2 in string s1, or -1
 */
int rindexOf(char *s1, char *s2)
{
    char c1 = *s2;
    char c;
    char *p;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (c1 == '\0')
	return (len1);
    p = s1 + (len1 - len2);
    while (p >= s1) {
	c = *p;
	if ((c == c1) && (strncmp(p+1, s2+1, len2-1) == 0))
	    return (p - s1);
	else
	    p--;
    }
    return -1;
}

/* match:
 * Return index of pattern pat in string str, or -1
 */
int match(char *str, char *pat)
{
    int sub[2];

    if (strgrpmatch(str, pat, sub, 1, 01)) {
	return (sub[0]);
    } else
	return -1;
}

/* nodeInduce:
 * Add all edges in root graph connecting two nodes in 
 * selected to selected.
 */
void nodeInduce(Agraph_t * selected)
{
    Agnode_t *n;
    Agedge_t *e;
    Agraph_t *base;

    if (!selected)
	return;
    base = agroot(selected);
    if (base == selected)
	return;
    for (n = agfstnode(selected); n; n = agnxtnode(selected, n)) {
	for (e = agfstout(base, n); e; e = agnxtout(base, e)) {
	    if (agsubnode(selected, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), (0)))
		agsubedge(selected, e, (!(0)));
	}
    }
}

/* copyAttr:
 * Copy attributes from src to tgt. Overrides currently
 * defined values.
 * FIX: we should probably use the default value of the source
 * graph when initializing the attribute, rather than "".
 * NOTE: We do not assume src and tgt have the same kind.
 */
int copyAttr(Agobj_t * src, Agobj_t * tgt)
{
    Agraph_t *srcg;
    Agraph_t *tgtg;
    Agsym_t *sym = 0;
    Agsym_t *tsym = 0;
    int skind = ((((Agobj_t*)(src))->tag).objtype);
    int tkind = ((((Agobj_t*)(tgt))->tag).objtype);
    char* val;

    srcg = agraphof(src);
    tgtg = agraphof(tgt);
    while ((sym = agnxtattr(srcg, skind, sym))) {
	tsym = agattrsym(tgt, sym->name);
	if (!tsym)
	    tsym = agattr(tgtg, tkind, sym->name, sym->defval);
	val = agxget(src, sym);
	if (aghtmlstr (val)) {
	    val = agstrdup_html (tgtg, val);
	    agxset(tgt, tsym, val);
	    agstrfree (tgtg, val);
	}
	else
	    agxset(tgt, tsym, val);
    }
    return 0;
}

/* copy:
 * Create new object of type AGTYPE(obj) with all of its
 * attributes.
 * If obj is an edge, only create end nodes if necessary.
 * If obj is a graph, if g is null, create a top-level
 * graph. Otherwise, create a subgraph of g.
 * Assume obj != NULL.
 */
Agobj_t *copy(Agraph_t * g, Agobj_t * obj)
{
    Agobj_t *nobj = 0;
    Agedge_t *e;
    Agnode_t *h;
    Agnode_t *t;
    int kind = ((((Agobj_t*)(obj))->tag).objtype);
    char *name;

    if ((kind != 0) && !g) {
	exerror("NULL graph with non-graph object in copy()");
	return 0;
    }

    switch (kind) {
    case 1:
	name = agnameof(obj);
	nobj = (Agobj_t *) openNode(g, name);
	break;
    case 0:
	name = agnameof(obj);
	if (g)
	    nobj = (Agobj_t *) openSubg(g, name);
	else
	    nobj = (Agobj_t *) openG(name, ((Agraph_t *) obj)->desc);
	break;
    case 3:
    case 2:
	e = (Agedge_t *) obj;
	t = openNode(g, agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)));
	h = openNode(g, agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	name = agnameof ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)));
	nobj = (Agobj_t *) openEdge(g, t, h, name);
	break;
    }
    if (nobj)
	copyAttr(obj, nobj);

    return nobj;
}

typedef struct {
    Dtlink_t link;
    Agedge_t *key;
    Agedge_t *val;
} edgepair_t;

static Agedge_t*
mapEdge (Dt_t* emap, Agedge_t* e)
{
     edgepair_t* ep = (*(((Dt_t*)(emap))->searchf))((emap),(void*)(&e),0001000);     
     if (ep) return ep->val;
     else return 0;
}

/* cloneSubg:
 * Clone subgraph sg in tgt.
 */
static Agraph_t *cloneSubg(Agraph_t * tgt, Agraph_t * g, Dt_t* emap)
{
    Agraph_t *ng;
    Agraph_t *sg;
    Agnode_t *t;
    Agnode_t *newt;
    Agedge_t *e;
    Agedge_t *newe;
    char* name;

    ng = (Agraph_t *) (copy(tgt, ((Agobj_t*)g)));
    if (!ng)
	return 0;
    for (t = agfstnode(g); t; t = agnxtnode(g, t)) {
	newt = agnode(tgt, agnameof(t), 0);
	if (!newt) {
	    exerror("node %s not found in cloned graph %s",
		  agnameof(t), agnameof(tgt));
	    return 0;
	}
	else
	    agsubnode(ng, newt, 1);
    }
    for (t = agfstnode(g); t; t = agnxtnode(g, t)) {
	for (e = agfstout(g, t); e; e = agnxtout(g, e)) {
	    newe = mapEdge (emap, e);
	    if (!newe) {
		name = agnameof((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)));
		if (name)
		    exerror("edge (%s,%s)[%s] not found in cloned graph %s",
		      agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)),
		      name, agnameof(tgt));
		else
		    exerror("edge (%s,%s) not found in cloned graph %s",
		      agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)),
		      agnameof(tgt));
		return 0;
	    }
	    else
		agsubedge(ng, newe, 1);
	}
    }
    for (sg = agfstsubg(g); sg; sg = agnxtsubg(sg)) {
	if (!cloneSubg(ng, sg, emap)) {
	    exerror("error cloning subgraph %s from graph %s",
		  agnameof(sg), agnameof(g));
	    return 0;
	}
    }
    return ng;
}

static int cmppair(Dt_t * d, Agedge_t** key1, Agedge_t** key2, Dtdisc_t * disc)
{
    if (*key1 > *key2) return 1;
    else if (*key1 < *key2) return -1;
    else return 0;
}

static Dtdisc_t edgepair = {
    offsetof(edgepair_t, key),
    sizeof(Agedge_t*),
    offsetof(edgepair_t, link),
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    (Dtcompar_f) cmppair,
    ((Dthash_f)0),
    ((Dtmemory_f)0),
    ((Dtevent_f)0)
};

/* cloneGraph:
 * Clone node, edge and subgraph structure from src to tgt.
 */
static void cloneGraph(Agraph_t * tgt, Agraph_t * src)
{
    Agedge_t *e;
    Agedge_t *ne;
    Agnode_t *t;
    Agraph_t *sg;
    char* name;
    Dt_t* emap = dtopen (&edgepair, Dtoset);
    edgepair_t* data = (edgepair_t*)malloc(sizeof(edgepair_t)*agnedges(src));
    edgepair_t* ep = data;

    for (t = agfstnode(src); t; t = agnxtnode(src, t)) {
	if (!copy(tgt, ((Agobj_t*)t))) {
	    exerror("error cloning node %s from graph %s",
		  agnameof(t), agnameof(src));
	}
    }
    for (t = agfstnode(src); t; t = agnxtnode(src, t)) {
	for (e = agfstout(src, t); e; e = agnxtout(src, e)) {
	    if (!(ne = (Agedge_t*)copy(tgt, ((Agobj_t*)e)))) {
		name = agnameof((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)));
		if (name)
		    exerror("error cloning edge (%s,%s)[%s] from graph %s",
		      agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)),
		      name, agnameof(src));
		else
		    exerror("error cloning edge (%s,%s) from graph %s",
		      agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)),
		      agnameof(src));
		return;
	    }
	    ep->key = e;
	    ep->val = ne;
	    (*(((Dt_t*)(emap))->searchf))((emap),(void*)(ep++),0000001);
	}
    }
    for (sg = agfstsubg(src); sg; sg = agnxtsubg(sg)) {
	if (!cloneSubg(tgt, sg, emap)) {
	    exerror("error cloning subgraph %s from graph %s",
		  agnameof(sg), agnameof(src));
	}
    }

    dtclose (emap);
    free (data);
}

/* cloneG:
 */
Agraph_t *cloneG(Agraph_t * g, char* name)
{
    Agraph_t* ng;

    if (!name || (*name == '\0'))
	name = agnameof (g);
    ng = openG(name, g->desc);
    if (ng) {
	copyAttr((Agobj_t*)g, (Agobj_t*)ng);
	cloneGraph(ng, g);
    }
    return ng;
}

/* clone:
 * Create new object of type AGTYPE(obj) with all of its
 * attributes and substructure.
 * If obj is an edge, end nodes are cloned if necessary.
 * If obj is a graph, if g is null, create a clone top-level
 * graph. Otherwise, create a clone subgraph of g.
 * Assume obj != NULL.
 */
Agobj_t *clone(Agraph_t * g, Agobj_t * obj)
{
    Agobj_t *nobj = 0;
    Agedge_t *e;
    Agnode_t *h;
    Agnode_t *t;
    int kind = ((((Agobj_t*)(obj))->tag).objtype);
    char *name;

    if ((kind != 0) && !g) {
	exerror("NULL graph with non-graph object in clone()");
	return 0;
    }

    switch (kind) {
    case 1:		/* same as copy node */
	name = agnameof(obj);
	nobj = (Agobj_t *) openNode(g, name);
	if (nobj)
	    copyAttr(obj, nobj);
	break;
    case 0:
	name = agnameof(obj);
	if (g)
	    nobj = (Agobj_t *) openSubg(g, name);
	else
	    nobj = (Agobj_t *) openG(name, ((Agraph_t *) obj)->desc);
	if (nobj) {
	    copyAttr(obj, nobj);
	    cloneGraph((Agraph_t *) nobj, (Agraph_t *) obj);
	}
	break;
    case 3:
    case 2:
	e = (Agedge_t *) obj;
	t = (Agnode_t *) clone(g, ((Agobj_t*)((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)));
	h = (Agnode_t *) clone(g, ((Agobj_t*)((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	name = agnameof ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)));
	nobj = (Agobj_t *) openEdge(g, t, h, name);
	if (nobj)
	    copyAttr(obj, nobj);
	break;
    }

    return nobj;
}





static void cc_dfs(Agraph_t* g, Agraph_t * comp, Agnode_t * n)
{
    Agedge_t *e;
    Agnode_t *other;

    (((((ndata*)(aggetrec(n,"userval",0))))->iu.integer) |= 2);
    agidnode(comp, ((((Agobj_t*)(n))->tag).id), 1);
    for (e = agfstedge(g, n); e; e = agnxtedge(g, e, n)) {
	if (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) == n)
	    other = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	else
	    other = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	if (!(((((ndata*)(aggetrec(other,"userval",0))))->iu.integer)&2))
	    cc_dfs(g, comp, other);
    }
}

/* compOf:
 * Return connected component of node.
 */
Agraph_t *compOf(Agraph_t * g, Agnode_t * n)
{
    Agraph_t *cg;
    Agnode_t *np;
    static int id;
    char name[64];

    if (!(n = agidnode(g, ((((Agobj_t*)(n))->tag).id), 0)))
	return 0;		/* n not in g */
    for (np = agfstnode(g); np; np = agnxtnode(g, np))
	(((((ndata*)(aggetrec(np,"userval",0))))->iu.integer) &= ~2);

    sprintf(name, "_cc_%d", id++);
    cg = openSubg(g, name);
    cc_dfs(g, cg, n);

    return cg;
}

/* isEdge:
 * Return edge, if any, between t and h with given key.
 * Edge is in g.
 */
Agedge_t *isEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key)
{
    Agraph_t *root;

    root = sameG(t, h, "isEdge", "tail and head node");
    if (!root)
	return 0;
    if (g) {
	if (root != agroot(g)) return 0;
    }
    else
	g = root;

    return agedge(g, t, h, key, 0);
}

/* addNode:
 * Insert node n into subgraph g.
 * Return image of n
 */
Agnode_t *addNode(Agraph_t * gp, Agnode_t * np, int doAdd)
{
    if (!sameG(gp, np, "addNode", 0))
	return 0;
    return agsubnode(gp, np, doAdd);
}

/* addEdge:
 * Insert edge e into subgraph g.
 * Return image of e
 */
Agedge_t *addEdge(Agraph_t * gp, Agedge_t * ep, int doAdd)
{
    if (!sameG(gp, ep, "addEdge", 0))
	return 0;
    return agsubedge(gp, ep, doAdd);
}

/* lockGraph:
 * Set lock so that graph g will not be deleted.
 * g must be a root graph.
 * If v > 0, set lock
 * If v = 0, unset lock and delete graph is necessary.
 * If v < 0, no op
 * Always return previous lock state.
 * Return -1 on error.
 */
int lockGraph(Agraph_t * g, int v)
{
    gdata *data;
    int oldv;

    if (g != agroot(g)) {
	_err_msg(1,
	      "Graph argument to lock() is not a root graph");
	return -1;
    }
    data = ((gdata*)(aggetrec(g,"userval",0)));
    oldv = data->lock & 1;
    if (v > 0)
	data->lock |= 1;
    else if ((v == 0) && oldv) {
	if (data->lock & 2)
	    agclose(g);
	else
	    data->lock = 0;
    }
    return oldv;
}

/* deleteObj:
 * Remove obj from g.
 * obj may belong to a subgraph of g, so we first must map
 * obj to its version in g.
 * If g is null, remove object from root graph.
 * If obj is a (sub)graph, close it. The g parameter is unused.
 * Return 0 on success, non-zero on failure.
 */
int deleteObj(Agraph_t * g, Agobj_t * obj)
{
    gdata *data;
    if (((((Agobj_t*)(obj))->tag).objtype) == 0) {
	g = (Agraph_t *) obj;
	if (g != agroot(g))
	    return agclose(g);
	data = ((gdata*)(aggetrec(g,"userval",0)));
	if (data->lock & 1) {
	    _err_msg(1, "Cannot delete locked graph %s",
		  agnameof(g));
	    data->lock |= 2;
	    return -1;
	} else
	    return agclose(g);
    }

    /* node or edge */
    if (!g)
	g = agroot(agraphof(obj));
    if (obj)
	return agdelete(g, obj);
    else
	return -1;
}

/* sfioWrite:
 * If the graph is passed in from a library, its output discipline
 * might not use sfio. In this case, we push an sfio discipline on
 * the graph, write it, and then pop it off.
 */
int sfioWrite(Agraph_t * g, Sfio_t* fp, Agiodisc_t* dfltDisc)
{
    Agiodisc_t* saveio;
    int rv;

    if (g->clos->disc.io != dfltDisc) {
	saveio = g->clos->disc.io;
	g->clos->disc.io = dfltDisc;
    }
    rv = agwrite (g, fp);
    if (g->clos->disc.io != dfltDisc) {
	g->clos->disc.io = saveio;
    }
    return rv;
}

/* writeFile:
 * Write graph into file f.
 * Return 0 on success
 */
int writeFile(Agraph_t * g, char *f, Agiodisc_t* io)
{
    int rv;
    Sfio_t *fp;

    if (!f) {
	exerror("NULL string passed to writeG");
	return 1;
    }
    fp = sfopen(0, f, "w");
    if (!fp) {
	exwarn("Could not open %s for writing in writeG", f);
	return 1;
    }
    rv = sfioWrite(g, fp, io);
    sfclose(fp);
    return rv;
}

/* readFile:
 * Read graph from file f.
 * Return 0 on failure
 */
Agraph_t *readFile(char *f)
{
    Agraph_t *gp;
    Sfio_t *fp;

    if (!f) {
	exerror("NULL string passed to readG");
	return 0;
    }
    fp = sfopen(0, f, "r");
    if (!fp) {
	exwarn("Could not open %s for reading in readG", f);
	return 0;
    }
    gp = readG(fp);
    sfclose(fp);

    return gp;
}

int fwriteFile(Expr_t * ex, Agraph_t * g, int fd, Agiodisc_t* io)
{
    Sfio_t *sp;

    if (fd < 0 || fd >= (sizeof(ex->file)/sizeof(ex->file[0]))
	|| !((sp = ex->file[fd]))) {
	exerror("fwriteG: %d: invalid descriptor", fd);
	return 0;
    }
    return sfioWrite(g, sp, io);
}

Agraph_t *freadFile(Expr_t * ex, int fd)
{
    Sfio_t *sp;

    if (fd < 0 || fd >= (sizeof(ex->file)/sizeof(ex->file[0]))
	|| !((sp = ex->file[fd]))) {
	exerror("freadG: %d: invalid descriptor", fd);
	return 0;
    }
    return readG(sp);
}

int openFile(Expr_t * ex, char *fname, char *mode)
{
    int idx;

    /* find open index */
    for (idx = 3; idx < (sizeof(ex->file)/sizeof(ex->file[0])); idx++)
	if (!ex->file[idx])
	    break;
    if (idx == (sizeof(ex->file)/sizeof(ex->file[0]))) {
	exerror("openF: no available descriptors");
	return -1;
    }
    ex->file[idx] = sfopen(0, fname, mode);
    if (ex->file[idx])
	return idx;
    else
	return -1;
}

int closeFile(Expr_t * ex, int fd)
{
    int rv;

    if ((0 <= fd) && (fd <= 2)) {
	exerror("closeF: cannot close standard stream %d", fd);
	return -1;
    }
    if (!ex->file[fd]) {
	exerror("closeF: stream %d not open", fd);
	return -1;
    }
    rv = sfclose(ex->file[fd]);
    if (!rv)
	ex->file[fd] = 0;
    return rv;
}

/*
 * Read single line from stream.
 * Return "" on EOF.
 */
char *readLine(Expr_t * ex, int fd)
{
    Sfio_t *sp;
    int c;
    Sfio_t *tmps;
    char *line;

    if (fd < 0 || fd >= (sizeof(ex->file)/sizeof(ex->file[0])) || !((sp = ex->file[fd]))) {
	exerror("readL: %d: invalid descriptor", fd);
	return "";
    }
    tmps = sfnew((Sfio_t*)0,(char*)0,-1,-1,0000002|0000004);
    while (((c = ( (((Sfio_t*)(sp))->next >= ((Sfio_t*)(sp))->endr ? _sffilbuf(((Sfio_t*)(sp)),0) : (int)(*((Sfio_t*)(sp))->next++) ) )) > 0) && (c != '\n'))
	( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((c))) ) );
    if (c == '\n')
	( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((c)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((c))) ) );
    line = exstring(ex, (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ));
    sfclose(tmps);
    return line;
}

/* compare:
 * Lexicographic ordering of objects.
 */
int compare(Agobj_t * l, Agobj_t * r)
{
    char lkind, rkind;
    if (l == 0) {
	if (r == 0)
	    return 0;
	else
	    return -1;
    } else if (r == 0) {
	return 1;
    }
    if (((((Agobj_t*)(l))->tag).id) < ((((Agobj_t*)(r))->tag).id))
	return -1;
    else if (((((Agobj_t*)(l))->tag).id) > ((((Agobj_t*)(r))->tag).id))
	return 1;
    lkind = ((((Agobj_t*)(l))->tag).objtype);
    rkind = ((((Agobj_t*)(r))->tag).objtype);
    if (lkind == 3)
	lkind = 2;
    if (rkind == 3)
	rkind = 2;
    if (lkind == rkind)
	return 0;
    else if (lkind < rkind)
	return -1;
    else
	return 1;
}

/* toLower:
 * Convert characters to lowercase
 */
char *toLower(Expr_t * pgm, char *s, Sfio_t* tmps)
{
    int c;

    while ((c = *s++))
	( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((tolower(c))))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((tolower(c)))) ) );

    return exstring(pgm, (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ));
}

/* toUpper:
 * Convert characters to uppercase
 */
char *toUpper(Expr_t * pgm, char *s, Sfio_t* tmps)
{
    int c;

    while ((c = *s++))
	( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((toupper(c))))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((toupper(c)))) ) );

    return exstring(pgm, (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ));
}

/* toHtml:
 * Create a string marked as HTML
 */
char *toHtml(Agraph_t* g, char *arg)
{
    return agstrdup_html (g, arg);
}

/* canon:
 * Canonicalize a string for printing.
 */
char *canon(Expr_t * pgm, char *arg)
{
    char *p;

    p = agcanonStr(arg);
    if (p != arg)
	p = exstring(pgm, p);

    return p;
}

#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
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

/* geometric functions (e.g. on points and boxes) with application to, but
 * no specific dependance on graphs */




/* for sincos */




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1



#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
































































    









#line 792 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\color.h" 1
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




/* #include "arith.h" */





typedef struct hsvrgbacolor_t {
    char *name;
    unsigned char h, s, v;
    unsigned char r, g, b, a;
} hsvrgbacolor_t;

/* possible representations of color in gvcolor_t */
typedef enum { HSVA_DOUBLE, RGBA_BYTE, RGBA_WORD, CMYK_BYTE,
		RGBA_DOUBLE, COLOR_STRING, COLOR_INDEX } color_type_t;

/* gvcolor_t can hold a color spec in a choice or representations */
typedef struct color_s {
    union {
	double RGBA[4];
	double HSVA[4];
	unsigned char rgba[4];
	unsigned char cmyk[4];
	int rrggbbaa[4];
	char *string;
	int index;
    } u;
    color_type_t type;
} gvcolor_t;









#line 793 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\colortbl.h" 1
static hsvrgbacolor_t color_lib[] = {
{"/accent3/1",85,93,201,127,201,127,255},
{"/accent3/2",187,45,212,190,174,212,255},
{"/accent3/3",20,119,253,253,192,134,255},
{"/accent4/1",85,93,201,127,201,127,255},
{"/accent4/2",187,45,212,190,174,212,255},
{"/accent4/3",20,119,253,253,192,134,255},
{"/accent4/4",42,102,255,255,255,153,255},
{"/accent5/1",85,93,201,127,201,127,255},
{"/accent5/2",187,45,212,190,174,212,255},
{"/accent5/3",20,119,253,253,192,134,255},
{"/accent5/4",42,102,255,255,255,153,255},
{"/accent5/5",151,173,176,56,108,176,255},
{"/accent6/1",85,93,201,127,201,127,255},
{"/accent6/2",187,45,212,190,174,212,255},
{"/accent6/3",20,119,253,253,192,134,255},
{"/accent6/4",42,102,255,255,255,153,255},
{"/accent6/5",151,173,176,56,108,176,255},
{"/accent6/6",232,252,240,240,2,127,255},
{"/accent7/1",85,93,201,127,201,127,255},
{"/accent7/2",187,45,212,190,174,212,255},
{"/accent7/3",20,119,253,253,192,134,255},
{"/accent7/4",42,102,255,255,255,153,255},
{"/accent7/5",151,173,176,56,108,176,255},
{"/accent7/6",232,252,240,240,2,127,255},
{"/accent7/7",17,224,191,191,91,23,255},
{"/accent8/1",85,93,201,127,201,127,255},
{"/accent8/2",187,45,212,190,174,212,255},
{"/accent8/3",20,119,253,253,192,134,255},
{"/accent8/4",42,102,255,255,255,153,255},
{"/accent8/5",151,173,176,56,108,176,255},
{"/accent8/6",232,252,240,240,2,127,255},
{"/accent8/7",17,224,191,191,91,23,255},
{"/accent8/8",0,0,102,102,102,102,255},
{"/blues3/1",147,25,247,222,235,247,255},
{"/blues3/2",142,75,225,158,202,225,255},
{"/blues3/3",145,188,189,49,130,189,255},
{"/blues4/1",159,16,255,239,243,255,255},
{"/blues4/2",143,46,231,189,215,231,255},
{"/blues4/3",143,127,214,107,174,214,255},
{"/blues4/4",147,208,181,33,113,181,255},
{"/blues5/1",159,16,255,239,243,255,255},
{"/blues5/2",143,46,231,189,215,231,255},
{"/blues5/3",143,127,214,107,174,214,255},
{"/blues5/4",145,188,189,49,130,189,255},
{"/blues5/5",149,241,156,8,81,156,255},
{"/blues6/1",159,16,255,239,243,255,255},
{"/blues6/2",148,43,239,198,219,239,255},
{"/blues6/3",142,75,225,158,202,225,255},
{"/blues6/4",143,127,214,107,174,214,255},
{"/blues6/5",145,188,189,49,130,189,255},
{"/blues6/6",149,241,156,8,81,156,255},
{"/blues7/1",159,16,255,239,243,255,255},
{"/blues7/2",148,43,239,198,219,239,255},
{"/blues7/3",142,75,225,158,202,225,255},
{"/blues7/4",143,127,214,107,174,214,255},
{"/blues7/5",144,169,198,66,146,198,255},
{"/blues7/6",147,208,181,33,113,181,255},
{"/blues7/7",151,241,148,8,69,148,255},
{"/blues8/1",148,8,255,247,251,255,255},
{"/blues8/2",147,25,247,222,235,247,255},
{"/blues8/3",148,43,239,198,219,239,255},
{"/blues8/4",142,75,225,158,202,225,255},
{"/blues8/5",143,127,214,107,174,214,255},
{"/blues8/6",144,169,198,66,146,198,255},
{"/blues8/7",147,208,181,33,113,181,255},
{"/blues8/8",151,241,148,8,69,148,255},
{"/blues9/1",148,8,255,247,251,255,255},
{"/blues9/2",147,25,247,222,235,247,255},
{"/blues9/3",148,43,239,198,219,239,255},
{"/blues9/4",142,75,225,158,202,225,255},
{"/blues9/5",143,127,214,107,174,214,255},
{"/blues9/6",144,169,198,66,146,198,255},
{"/blues9/7",147,208,181,33,113,181,255},
{"/blues9/8",149,241,156,8,81,156,255},
{"/blues9/9",152,235,107,8,48,107,255},
{"/brbg10/1",23,239,84,84,48,5,255},
{"/brbg10/10",119,255,60,0,60,48,255},
{"/brbg10/2",23,236,140,140,81,10,255},
{"/brbg10/3",24,194,191,191,129,45,255},
{"/brbg10/4",29,112,223,223,194,125,255},
{"/brbg10/5",30,52,246,246,232,195,255},
{"/brbg10/6",121,38,234,199,234,229,255},
{"/brbg10/7",120,95,205,128,205,193,255},
{"/brbg10/8",124,165,151,53,151,143,255},
{"/brbg10/9",124,252,102,1,102,94,255},
{"/brbg11/1",23,239,84,84,48,5,255},
{"/brbg11/10",124,252,102,1,102,94,255},
{"/brbg11/11",119,255,60,0,60,48,255},
{"/brbg11/2",23,236,140,140,81,10,255},
{"/brbg11/3",24,194,191,191,129,45,255},
{"/brbg11/4",29,112,223,223,194,125,255},
{"/brbg11/5",30,52,246,246,232,195,255},
{"/brbg11/6",0,0,245,245,245,245,255},
{"/brbg11/7",121,38,234,199,234,229,255},
{"/brbg11/8",120,95,205,128,205,193,255},
{"/brbg11/9",124,165,151,53,151,143,255},
{"/brbg3/1",28,135,216,216,179,101,255},
{"/brbg3/2",0,0,245,245,245,245,255},
{"/brbg3/3",123,127,180,90,180,172,255},
{"/brbg4/1",21,215,166,166,97,26,255},
{"/brbg4/2",29,112,223,223,194,125,255},
{"/brbg4/3",120,95,205,128,205,193,255},
{"/brbg4/4",121,253,133,1,133,113,255},
{"/brbg5/1",21,215,166,166,97,26,255},
{"/brbg5/2",29,112,223,223,194,125,255},
{"/brbg5/3",0,0,245,245,245,245,255},
{"/brbg5/4",120,95,205,128,205,193,255},
{"/brbg5/5",121,253,133,1,133,113,255},
{"/brbg6/1",23,236,140,140,81,10,255},
{"/brbg6/2",28,135,216,216,179,101,255},
{"/brbg6/3",30,52,246,246,232,195,255},
{"/brbg6/4",121,38,234,199,234,229,255},
{"/brbg6/5",123,127,180,90,180,172,255},
{"/brbg6/6",124,252,102,1,102,94,255},
{"/brbg7/1",23,236,140,140,81,10,255},
{"/brbg7/2",28,135,216,216,179,101,255},
{"/brbg7/3",30,52,246,246,232,195,255},
{"/brbg7/4",0,0,245,245,245,245,255},
{"/brbg7/5",121,38,234,199,234,229,255},
{"/brbg7/6",123,127,180,90,180,172,255},
{"/brbg7/7",124,252,102,1,102,94,255},
{"/brbg8/1",23,236,140,140,81,10,255},
{"/brbg8/2",24,194,191,191,129,45,255},
{"/brbg8/3",29,112,223,223,194,125,255},
{"/brbg8/4",30,52,246,246,232,195,255},
{"/brbg8/5",121,38,234,199,234,229,255},
{"/brbg8/6",120,95,205,128,205,193,255},
{"/brbg8/7",124,165,151,53,151,143,255},
{"/brbg8/8",124,252,102,1,102,94,255},
{"/brbg9/1",23,236,140,140,81,10,255},
{"/brbg9/2",24,194,191,191,129,45,255},
{"/brbg9/3",29,112,223,223,194,125,255},
{"/brbg9/4",30,52,246,246,232,195,255},
{"/brbg9/5",0,0,245,245,245,245,255},
{"/brbg9/6",121,38,234,199,234,229,255},
{"/brbg9/7",120,95,205,128,205,193,255},
{"/brbg9/8",124,165,151,53,151,143,255},
{"/brbg9/9",124,252,102,1,102,94,255},
{"/bugn3/1",135,20,249,229,245,249,255},
{"/bugn3/2",117,74,216,153,216,201,255},
{"/bugn3/3",103,185,162,44,162,95,255},
{"/bugn4/1",136,14,251,237,248,251,255},
{"/bugn4/2",127,54,226,178,226,226,255},
{"/bugn4/3",113,120,194,102,194,164,255},
{"/bugn4/4",98,190,139,35,139,69,255},
{"/bugn5/1",136,14,251,237,248,251,255},
{"/bugn5/2",127,54,226,178,226,226,255},
{"/bugn5/3",113,120,194,102,194,164,255},
{"/bugn5/4",103,185,162,44,162,95,255},
{"/bugn5/5",102,255,109,0,109,44,255},
{"/bugn6/1",136,14,251,237,248,251,255},
{"/bugn6/2",119,34,236,204,236,230,255},
{"/bugn6/3",117,74,216,153,216,201,255},
{"/bugn6/4",113,120,194,102,194,164,255},
{"/bugn6/5",103,185,162,44,162,95,255},
{"/bugn6/6",102,255,109,0,109,44,255},
{"/bugn7/1",136,14,251,237,248,251,255},
{"/bugn7/2",119,34,236,204,236,230,255},
{"/bugn7/3",117,74,216,153,216,201,255},
{"/bugn7/4",113,120,194,102,194,164,255},
{"/bugn7/5",105,159,174,65,174,118,255},
{"/bugn7/6",98,190,139,35,139,69,255},
{"/bugn7/7",102,255,88,0,88,36,255},
{"/bugn8/1",134,6,253,247,252,253,255},
{"/bugn8/2",135,20,249,229,245,249,255},
{"/bugn8/3",119,34,236,204,236,230,255},
{"/bugn8/4",117,74,216,153,216,201,255},
{"/bugn8/5",113,120,194,102,194,164,255},
{"/bugn8/6",105,159,174,65,174,118,255},
{"/bugn8/7",98,190,139,35,139,69,255},
{"/bugn8/8",102,255,88,0,88,36,255},
{"/bugn9/1",134,6,253,247,252,253,255},
{"/bugn9/2",135,20,249,229,245,249,255},
{"/bugn9/3",119,34,236,204,236,230,255},
{"/bugn9/4",117,74,216,153,216,201,255},
{"/bugn9/5",113,120,194,102,194,164,255},
{"/bugn9/6",105,159,174,65,174,118,255},
{"/bugn9/7",98,190,139,35,139,69,255},
{"/bugn9/8",102,255,109,0,109,44,255},
{"/bugn9/9",101,255,68,0,68,27,255},
{"/bupu3/1",144,20,244,224,236,244,255},
{"/bupu3/2",148,70,218,158,188,218,255},
{"/bupu3/3",196,123,167,136,86,167,255},
{"/bupu4/1",136,14,251,237,248,251,255},
{"/bupu4/2",146,53,227,179,205,227,255},
{"/bupu4/3",162,74,198,140,150,198,255},
{"/bupu4/4",202,149,157,136,65,157,255},
{"/bupu5/1",136,14,251,237,248,251,255},
{"/bupu5/2",146,53,227,179,205,227,255},
{"/bupu5/3",162,74,198,140,150,198,255},
{"/bupu5/4",196,123,167,136,86,167,255},
{"/bupu5/5",214,225,129,129,15,124,255},
{"/bupu6/1",136,14,251,237,248,251,255},
{"/bupu6/2",148,43,230,191,211,230,255},
{"/bupu6/3",148,70,218,158,188,218,255},
{"/bupu6/4",162,74,198,140,150,198,255},
{"/bupu6/5",196,123,167,136,86,167,255},
{"/bupu6/6",214,225,129,129,15,124,255},
{"/bupu7/1",136,14,251,237,248,251,255},
{"/bupu7/2",148,43,230,191,211,230,255},
{"/bupu7/3",148,70,218,158,188,218,255},
{"/bupu7/4",162,74,198,140,150,198,255},
{"/bupu7/5",190,100,177,140,107,177,255},
{"/bupu7/6",202,149,157,136,65,157,255},
{"/bupu7/7",213,252,110,110,1,107,255},
{"/bupu8/1",134,6,253,247,252,253,255},
{"/bupu8/2",144,20,244,224,236,244,255},
{"/bupu8/3",148,43,230,191,211,230,255},
{"/bupu8/4",148,70,218,158,188,218,255},
{"/bupu8/5",162,74,198,140,150,198,255},
{"/bupu8/6",190,100,177,140,107,177,255},
{"/bupu8/7",202,149,157,136,65,157,255},
{"/bupu8/8",213,252,110,110,1,107,255},
{"/bupu9/1",134,6,253,247,252,253,255},
{"/bupu9/2",144,20,244,224,236,244,255},
{"/bupu9/3",148,43,230,191,211,230,255},
{"/bupu9/4",148,70,218,158,188,218,255},
{"/bupu9/5",162,74,198,140,150,198,255},
{"/bupu9/6",190,100,177,140,107,177,255},
{"/bupu9/7",202,149,157,136,65,157,255},
{"/bupu9/8",214,225,129,129,15,124,255},
{"/bupu9/9",213,255,77,77,0,75,255},
{"/dark23/1",114,211,158,27,158,119,255},
{"/dark23/2",18,252,217,217,95,2,255},
{"/dark23/3",173,95,179,117,112,179,255},
{"/dark24/1",114,211,158,27,158,119,255},
{"/dark24/2",18,252,217,217,95,2,255},
{"/dark24/3",173,95,179,117,112,179,255},
{"/dark24/4",233,209,231,231,41,138,255},
{"/dark25/1",114,211,158,27,158,119,255},
{"/dark25/2",18,252,217,217,95,2,255},
{"/dark25/3",173,95,179,117,112,179,255},
{"/dark25/4",233,209,231,231,41,138,255},
{"/dark25/5",62,208,166,102,166,30,255},
{"/dark26/1",114,211,158,27,158,119,255},
{"/dark26/2",18,252,217,217,95,2,255},
{"/dark26/3",173,95,179,117,112,179,255},
{"/dark26/4",233,209,231,231,41,138,255},
{"/dark26/5",62,208,166,102,166,30,255},
{"/dark26/6",31,252,230,230,171,2,255},
{"/dark27/1",114,211,158,27,158,119,255},
{"/dark27/2",18,252,217,217,95,2,255},
{"/dark27/3",173,95,179,117,112,179,255},
{"/dark27/4",233,209,231,231,41,138,255},
{"/dark27/5",62,208,166,102,166,30,255},
{"/dark27/6",31,252,230,230,171,2,255},
{"/dark27/7",27,210,166,166,118,29,255},
{"/dark28/1",114,211,158,27,158,119,255},
{"/dark28/2",18,252,217,217,95,2,255},
{"/dark28/3",173,95,179,117,112,179,255},
{"/dark28/4",233,209,231,231,41,138,255},
{"/dark28/5",62,208,166,102,166,30,255},
{"/dark28/6",31,252,230,230,171,2,255},
{"/dark28/7",27,210,166,166,118,29,255},
{"/dark28/8",0,0,102,102,102,102,255},
{"/gnbu3/1",76,25,243,224,243,219,255},
{"/gnbu3/2",95,61,221,168,221,181,255},
{"/gnbu3/3",140,170,202,67,162,202,255},
{"/gnbu4/1",65,17,249,240,249,232,255},
{"/gnbu4/2",87,46,228,186,228,188,255},
{"/gnbu4/3",123,101,204,123,204,196,255},
{"/gnbu4/4",141,197,190,43,140,190,255},
{"/gnbu5/1",65,17,249,240,249,232,255},
{"/gnbu5/2",87,46,228,186,228,188,255},
{"/gnbu5/3",123,101,204,123,204,196,255},
{"/gnbu5/4",140,170,202,67,162,202,255},
{"/gnbu5/5",145,243,172,8,104,172,255},
{"/gnbu6/1",65,17,249,240,249,232,255},
{"/gnbu6/2",77,41,235,204,235,197,255},
{"/gnbu6/3",95,61,221,168,221,181,255},
{"/gnbu6/4",123,101,204,123,204,196,255},
{"/gnbu6/5",140,170,202,67,162,202,255},
{"/gnbu6/6",145,243,172,8,104,172,255},
{"/gnbu7/1",65,17,249,240,249,232,255},
{"/gnbu7/2",77,41,235,204,235,197,255},
{"/gnbu7/3",95,61,221,168,221,181,255},
{"/gnbu7/4",123,101,204,123,204,196,255},
{"/gnbu7/5",137,160,211,78,179,211,255},
{"/gnbu7/6",141,197,190,43,140,190,255},
{"/gnbu7/7",147,242,158,8,88,158,255},
{"/gnbu8/1",60,12,252,247,252,240,255},
{"/gnbu8/2",76,25,243,224,243,219,255},
{"/gnbu8/3",77,41,235,204,235,197,255},
{"/gnbu8/4",95,61,221,168,221,181,255},
{"/gnbu8/5",123,101,204,123,204,196,255},
{"/gnbu8/6",137,160,211,78,179,211,255},
{"/gnbu8/7",141,197,190,43,140,190,255},
{"/gnbu8/8",147,242,158,8,88,158,255},
{"/gnbu9/1",60,12,252,247,252,240,255},
{"/gnbu9/2",76,25,243,224,243,219,255},
{"/gnbu9/3",77,41,235,204,235,197,255},
{"/gnbu9/4",95,61,221,168,221,181,255},
{"/gnbu9/5",123,101,204,123,204,196,255},
{"/gnbu9/6",137,160,211,78,179,211,255},
{"/gnbu9/7",141,197,190,43,140,190,255},
{"/gnbu9/8",145,243,172,8,104,172,255},
{"/gnbu9/9",150,239,129,8,64,129,255},
{"/greens3/1",74,21,245,229,245,224,255},
{"/greens3/2",80,72,217,161,217,155,255},
{"/greens3/3",98,178,163,49,163,84,255},
{"/greens4/1",73,15,248,237,248,233,255},
{"/greens4/2",78,54,228,186,228,179,255},
{"/greens4/3",86,104,196,116,196,118,255},
{"/greens4/4",98,190,139,35,139,69,255},
{"/greens5/1",73,15,248,237,248,233,255},
{"/greens5/2",78,54,228,186,228,179,255},
{"/greens5/3",86,104,196,116,196,118,255},
{"/greens5/4",98,178,163,49,163,84,255},
{"/greens5/5",102,255,109,0,109,44,255},
{"/greens6/1",73,15,248,237,248,233,255},
{"/greens6/2",77,44,233,199,233,192,255},
{"/greens6/3",80,72,217,161,217,155,255},
{"/greens6/4",86,104,196,116,196,118,255},
{"/greens6/5",98,178,163,49,163,84,255},
{"/greens6/6",102,255,109,0,109,44,255},
{"/greens7/1",73,15,248,237,248,233,255},
{"/greens7/2",77,44,233,199,233,192,255},
{"/greens7/3",80,72,217,161,217,155,255},
{"/greens7/4",86,104,196,116,196,118,255},
{"/greens7/5",96,158,171,65,171,93,255},
{"/greens7/6",98,190,139,35,139,69,255},
{"/greens7/7",108,255,90,0,90,50,255},
{"/greens8/1",72,7,252,247,252,245,255},
{"/greens8/2",74,21,245,229,245,224,255},
{"/greens8/3",77,44,233,199,233,192,255},
{"/greens8/4",80,72,217,161,217,155,255},
{"/greens8/5",86,104,196,116,196,118,255},
{"/greens8/6",96,158,171,65,171,93,255},
{"/greens8/7",98,190,139,35,139,69,255},
{"/greens8/8",108,255,90,0,90,50,255},
{"/greens9/1",72,7,252,247,252,245,255},
{"/greens9/2",74,21,245,229,245,224,255},
{"/greens9/3",77,44,233,199,233,192,255},
{"/greens9/4",80,72,217,161,217,155,255},
{"/greens9/5",86,104,196,116,196,118,255},
{"/greens9/6",96,158,171,65,171,93,255},
{"/greens9/7",98,190,139,35,139,69,255},
{"/greens9/8",102,255,109,0,109,44,255},
{"/greens9/9",101,255,68,0,68,27,255},
{"/greys3/1",0,0,240,240,240,240,255},
{"/greys3/2",0,0,189,189,189,189,255},
{"/greys3/3",0,0,99,99,99,99,255},
{"/greys4/1",0,0,247,247,247,247,255},
{"/greys4/2",0,0,204,204,204,204,255},
{"/greys4/3",0,0,150,150,150,150,255},
{"/greys4/4",0,0,82,82,82,82,255},
{"/greys5/1",0,0,247,247,247,247,255},
{"/greys5/2",0,0,204,204,204,204,255},
{"/greys5/3",0,0,150,150,150,150,255},
{"/greys5/4",0,0,99,99,99,99,255},
{"/greys5/5",0,0,37,37,37,37,255},
{"/greys6/1",0,0,247,247,247,247,255},
{"/greys6/2",0,0,217,217,217,217,255},
{"/greys6/3",0,0,189,189,189,189,255},
{"/greys6/4",0,0,150,150,150,150,255},
{"/greys6/5",0,0,99,99,99,99,255},
{"/greys6/6",0,0,37,37,37,37,255},
{"/greys7/1",0,0,247,247,247,247,255},
{"/greys7/2",0,0,217,217,217,217,255},
{"/greys7/3",0,0,189,189,189,189,255},
{"/greys7/4",0,0,150,150,150,150,255},
{"/greys7/5",0,0,115,115,115,115,255},
{"/greys7/6",0,0,82,82,82,82,255},
{"/greys7/7",0,0,37,37,37,37,255},
{"/greys8/1",0,0,255,255,255,255,255},
{"/greys8/2",0,0,240,240,240,240,255},
{"/greys8/3",0,0,217,217,217,217,255},
{"/greys8/4",0,0,189,189,189,189,255},
{"/greys8/5",0,0,150,150,150,150,255},
{"/greys8/6",0,0,115,115,115,115,255},
{"/greys8/7",0,0,82,82,82,82,255},
{"/greys8/8",0,0,37,37,37,37,255},
{"/greys9/1",0,0,255,255,255,255,255},
{"/greys9/2",0,0,240,240,240,240,255},
{"/greys9/3",0,0,217,217,217,217,255},
{"/greys9/4",0,0,189,189,189,189,255},
{"/greys9/5",0,0,150,150,150,150,255},
{"/greys9/6",0,0,115,115,115,115,255},
{"/greys9/7",0,0,82,82,82,82,255},
{"/greys9/8",0,0,37,37,37,37,255},
{"/greys9/9",0,0,0,0,0,0,255},
{"/oranges3/1",21,48,254,254,230,206,255},
{"/oranges3/2",19,147,253,253,174,107,255},
{"/oranges3/3",14,240,230,230,85,13,255},
{"/oranges4/1",19,32,254,254,237,222,255},
{"/oranges4/2",20,120,253,253,190,133,255},
{"/oranges4/3",17,194,253,253,141,60,255},
{"/oranges4/4",13,253,217,217,71,1,255},
{"/oranges5/1",19,32,254,254,237,222,255},
{"/oranges5/2",20,120,253,253,190,133,255},
{"/oranges5/3",17,194,253,253,141,60,255},
{"/oranges5/4",14,240,230,230,85,13,255},
{"/oranges5/5",13,250,166,166,54,3,255},
{"/oranges6/1",19,32,254,254,237,222,255},
{"/oranges6/2",21,91,253,253,208,162,255},
{"/oranges6/3",19,147,253,253,174,107,255},
{"/oranges6/4",17,194,253,253,141,60,255},
{"/oranges6/5",14,240,230,230,85,13,255},
{"/oranges6/6",13,250,166,166,54,3,255},
{"/oranges7/1",19,32,254,254,237,222,255},
{"/oranges7/2",21,91,253,253,208,162,255},
{"/oranges7/3",19,147,253,253,174,107,255},
{"/oranges7/4",17,194,253,253,141,60,255},
{"/oranges7/5",16,234,241,241,105,19,255},
{"/oranges7/6",13,253,217,217,72,1,255},
{"/oranges7/7",12,247,140,140,45,4,255},
{"/oranges8/1",21,20,255,255,245,235,255},
{"/oranges8/2",21,48,254,254,230,206,255},
{"/oranges8/3",21,91,253,253,208,162,255},
{"/oranges8/4",19,147,253,253,174,107,255},
{"/oranges8/5",17,194,253,253,141,60,255},
{"/oranges8/6",16,234,241,241,105,19,255},
{"/oranges8/7",13,253,217,217,72,1,255},
{"/oranges8/8",12,247,140,140,45,4,255},
{"/oranges9/1",21,20,255,255,245,235,255},
{"/oranges9/2",21,48,254,254,230,206,255},
{"/oranges9/3",21,91,253,253,208,162,255},
{"/oranges9/4",19,147,253,253,174,107,255},
{"/oranges9/5",17,194,253,253,141,60,255},
{"/oranges9/6",16,234,241,241,105,19,255},
{"/oranges9/7",13,253,217,217,72,1,255},
{"/oranges9/8",13,250,166,166,54,3,255},
{"/oranges9/9",12,246,127,127,39,4,255},
{"/orrd3/1",25,54,254,254,232,200,255},
{"/orrd3/2",19,121,253,253,187,132,255},
{"/orrd3/3",5,197,227,227,74,51,255},
{"/orrd4/1",26,37,254,254,240,217,255},
{"/orrd4/2",24,115,253,253,204,138,255},
{"/orrd4/3",13,164,252,252,141,89,255},
{"/orrd4/4",3,218,215,215,48,31,255},
{"/orrd5/1",26,37,254,254,240,217,255},
{"/orrd5/2",24,115,253,253,204,138,255},
{"/orrd5/3",13,164,252,252,141,89,255},
{"/orrd5/4",5,197,227,227,74,51,255},
{"/orrd5/5",0,255,179,179,0,0,255},
{"/orrd6/1",26,37,254,254,240,217,255},
{"/orrd6/2",24,95,253,253,212,158,255},
{"/orrd6/3",19,121,253,253,187,132,255},
{"/orrd6/4",13,164,252,252,141,89,255},
{"/orrd6/5",5,197,227,227,74,51,255},
{"/orrd6/6",0,255,179,179,0,0,255},
{"/orrd7/1",26,37,254,254,240,217,255},
{"/orrd7/2",24,95,253,253,212,158,255},
{"/orrd7/3",19,121,253,253,187,132,255},
{"/orrd7/4",13,164,252,252,141,89,255},
{"/orrd7/5",7,178,239,239,101,72,255},
{"/orrd7/6",3,218,215,215,48,31,255},
{"/orrd7/7",0,255,153,153,0,0,255},
{"/orrd8/1",24,18,255,255,247,236,255},
{"/orrd8/2",25,54,254,254,232,200,255},
{"/orrd8/3",24,95,253,253,212,158,255},
{"/orrd8/4",19,121,253,253,187,132,255},
{"/orrd8/5",13,164,252,252,141,89,255},
{"/orrd8/6",7,178,239,239,101,72,255},
{"/orrd8/7",3,218,215,215,48,31,255},
{"/orrd8/8",0,255,153,153,0,0,255},
{"/orrd9/1",24,18,255,255,247,236,255},
{"/orrd9/2",25,54,254,254,232,200,255},
{"/orrd9/3",24,95,253,253,212,158,255},
{"/orrd9/4",19,121,253,253,187,132,255},
{"/orrd9/5",13,164,252,252,141,89,255},
{"/orrd9/6",7,178,239,239,101,72,255},
{"/orrd9/7",3,218,215,215,48,31,255},
{"/orrd9/8",0,255,179,179,0,0,255},
{"/orrd9/9",0,255,127,127,0,0,255},
{"/paired10/1",142,68,227,166,206,227,255},
{"/paired10/10",190,153,154,106,61,154,255},
{"/paired10/2",144,211,180,31,120,180,255},
{"/paired10/3",65,97,223,178,223,138,255},
{"/paired10/4",82,184,160,51,160,44,255},
{"/paired10/5",0,99,251,251,154,153,255},
{"/paired10/6",254,225,227,227,26,28,255},
{"/paired10/7",23,143,253,253,191,111,255},
{"/paired10/8",21,255,255,255,127,0,255},
{"/paired10/9",198,42,214,202,178,214,255},
{"/paired11/1",142,68,227,166,206,227,255},
{"/paired11/10",190,153,154,106,61,154,255},
{"/paired11/11",42,102,255,255,255,153,255},
{"/paired11/2",144,211,180,31,120,180,255},
{"/paired11/3",65,97,223,178,223,138,255},
{"/paired11/4",82,184,160,51,160,44,255},
{"/paired11/5",0,99,251,251,154,153,255},
{"/paired11/6",254,225,227,227,26,28,255},
{"/paired11/7",23,143,253,253,191,111,255},
{"/paired11/8",21,255,255,255,127,0,255},
{"/paired11/9",198,42,214,202,178,214,255},
{"/paired12/1",142,68,227,166,206,227,255},
{"/paired12/10",190,153,154,106,61,154,255},
{"/paired12/11",42,102,255,255,255,153,255},
{"/paired12/12",15,197,177,177,89,40,255},
{"/paired12/2",144,211,180,31,120,180,255},
{"/paired12/3",65,97,223,178,223,138,255},
{"/paired12/4",82,184,160,51,160,44,255},
{"/paired12/5",0,99,251,251,154,153,255},
{"/paired12/6",254,225,227,227,26,28,255},
{"/paired12/7",23,143,253,253,191,111,255},
{"/paired12/8",21,255,255,255,127,0,255},
{"/paired12/9",198,42,214,202,178,214,255},
{"/paired3/1",142,68,227,166,206,227,255},
{"/paired3/2",144,211,180,31,120,180,255},
{"/paired3/3",65,97,223,178,223,138,255},
{"/paired4/1",142,68,227,166,206,227,255},
{"/paired4/2",144,211,180,31,120,180,255},
{"/paired4/3",65,97,223,178,223,138,255},
{"/paired4/4",82,184,160,51,160,44,255},
{"/paired5/1",142,68,227,166,206,227,255},
{"/paired5/2",144,211,180,31,120,180,255},
{"/paired5/3",65,97,223,178,223,138,255},
{"/paired5/4",82,184,160,51,160,44,255},
{"/paired5/5",0,99,251,251,154,153,255},
{"/paired6/1",142,68,227,166,206,227,255},
{"/paired6/2",144,211,180,31,120,180,255},
{"/paired6/3",65,97,223,178,223,138,255},
{"/paired6/4",82,184,160,51,160,44,255},
{"/paired6/5",0,99,251,251,154,153,255},
{"/paired6/6",254,225,227,227,26,28,255},
{"/paired7/1",142,68,227,166,206,227,255},
{"/paired7/2",144,211,180,31,120,180,255},
{"/paired7/3",65,97,223,178,223,138,255},
{"/paired7/4",82,184,160,51,160,44,255},
{"/paired7/5",0,99,251,251,154,153,255},
{"/paired7/6",254,225,227,227,26,28,255},
{"/paired7/7",23,143,253,253,191,111,255},
{"/paired8/1",142,68,227,166,206,227,255},
{"/paired8/2",144,211,180,31,120,180,255},
{"/paired8/3",65,97,223,178,223,138,255},
{"/paired8/4",82,184,160,51,160,44,255},
{"/paired8/5",0,99,251,251,154,153,255},
{"/paired8/6",254,225,227,227,26,28,255},
{"/paired8/7",23,143,253,253,191,111,255},
{"/paired8/8",21,255,255,255,127,0,255},
{"/paired9/1",142,68,227,166,206,227,255},
{"/paired9/2",144,211,180,31,120,180,255},
{"/paired9/3",65,97,223,178,223,138,255},
{"/paired9/4",82,184,160,51,160,44,255},
{"/paired9/5",0,99,251,251,154,153,255},
{"/paired9/6",254,225,227,227,26,28,255},
{"/paired9/7",23,143,253,253,191,111,255},
{"/paired9/8",21,255,255,255,127,0,255},
{"/paired9/9",198,42,214,202,178,214,255},
{"/pastel13/1",3,78,251,251,180,174,255},
{"/pastel13/2",146,53,227,179,205,227,255},
{"/pastel13/3",77,41,235,204,235,197,255},
{"/pastel14/1",3,78,251,251,180,174,255},
{"/pastel14/2",146,53,227,179,205,227,255},
{"/pastel14/3",77,41,235,204,235,197,255},
{"/pastel14/4",202,27,228,222,203,228,255},
{"/pastel15/1",3,78,251,251,180,174,255},
{"/pastel15/2",146,53,227,179,205,227,255},
{"/pastel15/3",77,41,235,204,235,197,255},
{"/pastel15/4",202,27,228,222,203,228,255},
{"/pastel15/5",24,88,254,254,217,166,255},
{"/pastel16/1",3,78,251,251,180,174,255},
{"/pastel16/2",146,53,227,179,205,227,255},
{"/pastel16/3",77,41,235,204,235,197,255},
{"/pastel16/4",202,27,228,222,203,228,255},
{"/pastel16/5",24,88,254,254,217,166,255},
{"/pastel16/6",42,50,255,255,255,204,255},
{"/pastel17/1",3,78,251,251,180,174,255},
{"/pastel17/2",146,53,227,179,205,227,255},
{"/pastel17/3",77,41,235,204,235,197,255},
{"/pastel17/4",202,27,228,222,203,228,255},
{"/pastel17/5",24,88,254,254,217,166,255},
{"/pastel17/6",42,50,255,255,255,204,255},
{"/pastel17/7",28,44,229,229,216,189,255},
{"/pastel18/1",3,78,251,251,180,174,255},
{"/pastel18/2",146,53,227,179,205,227,255},
{"/pastel18/3",77,41,235,204,235,197,255},
{"/pastel18/4",202,27,228,222,203,228,255},
{"/pastel18/5",24,88,254,254,217,166,255},
{"/pastel18/6",42,50,255,255,255,204,255},
{"/pastel18/7",28,44,229,229,216,189,255},
{"/pastel18/8",233,35,253,253,218,236,255},
{"/pastel19/1",3,78,251,251,180,174,255},
{"/pastel19/2",146,53,227,179,205,227,255},
{"/pastel19/3",77,41,235,204,235,197,255},
{"/pastel19/4",202,27,228,222,203,228,255},
{"/pastel19/5",24,88,254,254,217,166,255},
{"/pastel19/6",42,50,255,255,255,204,255},
{"/pastel19/7",28,44,229,229,216,189,255},
{"/pastel19/8",233,35,253,253,218,236,255},
{"/pastel19/9",0,0,242,242,242,242,255},
{"/pastel23/1",108,53,226,179,226,205,255},
{"/pastel23/2",17,81,253,253,205,172,255},
{"/pastel23/3",155,31,232,203,213,232,255},
{"/pastel24/1",108,53,226,179,226,205,255},
{"/pastel24/2",17,81,253,253,205,172,255},
{"/pastel24/3",155,31,232,203,213,232,255},
{"/pastel24/4",228,43,244,244,202,228,255},
{"/pastel25/1",108,53,226,179,226,205,255},
{"/pastel25/2",17,81,253,253,205,172,255},
{"/pastel25/3",155,31,232,203,213,232,255},
{"/pastel25/4",228,43,244,244,202,228,255},
{"/pastel25/5",56,45,245,230,245,201,255},
{"/pastel26/1",108,53,226,179,226,205,255},
{"/pastel26/2",17,81,253,253,205,172,255},
{"/pastel26/3",155,31,232,203,213,232,255},
{"/pastel26/4",228,43,244,244,202,228,255},
{"/pastel26/5",56,45,245,230,245,201,255},
{"/pastel26/6",35,81,255,255,242,174,255},
{"/pastel27/1",108,53,226,179,226,205,255},
{"/pastel27/2",17,81,253,253,205,172,255},
{"/pastel27/3",155,31,232,203,213,232,255},
{"/pastel27/4",228,43,244,244,202,228,255},
{"/pastel27/5",56,45,245,230,245,201,255},
{"/pastel27/6",35,81,255,255,242,174,255},
{"/pastel27/7",25,39,241,241,226,204,255},
{"/pastel28/1",108,53,226,179,226,205,255},
{"/pastel28/2",17,81,253,253,205,172,255},
{"/pastel28/3",155,31,232,203,213,232,255},
{"/pastel28/4",228,43,244,244,202,228,255},
{"/pastel28/5",56,45,245,230,245,201,255},
{"/pastel28/6",35,81,255,255,242,174,255},
{"/pastel28/7",25,39,241,241,226,204,255},
{"/pastel28/8",0,0,204,204,204,204,255},
{"/piyg10/1",230,253,142,142,1,82,255},
{"/piyg10/10",77,191,100,39,100,25,255},
{"/piyg10/2",230,220,197,197,27,125,255},
{"/piyg10/3",232,118,222,222,119,174,255},
{"/piyg10/4",229,62,241,241,182,218,255},
{"/piyg10/5",233,29,253,253,224,239,255},
{"/piyg10/6",59,38,245,230,245,208,255},
{"/piyg10/7",61,103,225,184,225,134,255},
{"/piyg10/8",63,166,188,127,188,65,255},
{"/piyg10/9",68,197,146,77,146,33,255},
{"/piyg11/1",230,253,142,142,1,82,255},
{"/piyg11/10",68,197,146,77,146,33,255},
{"/piyg11/11",77,191,100,39,100,25,255},
{"/piyg11/2",230,220,197,197,27,125,255},
{"/piyg11/3",232,118,222,222,119,174,255},
{"/piyg11/4",229,62,241,241,182,218,255},
{"/piyg11/5",233,29,253,253,224,239,255},
{"/piyg11/6",0,0,247,247,247,247,255},
{"/piyg11/7",59,38,245,230,245,208,255},
{"/piyg11/8",61,103,225,184,225,134,255},
{"/piyg11/9",63,166,188,127,188,65,255},
{"/piyg3/1",231,76,233,233,163,201,255},
{"/piyg3/2",0,0,247,247,247,247,255},
{"/piyg3/3",63,129,215,161,215,106,255},
{"/piyg4/1",228,220,208,208,28,139,255},
{"/piyg4/2",229,62,241,241,182,218,255},
{"/piyg4/3",61,103,225,184,225,134,255},
{"/piyg4/4",72,198,172,77,172,38,255},
{"/piyg5/1",228,220,208,208,28,139,255},
{"/piyg5/2",229,62,241,241,182,218,255},
{"/piyg5/3",0,0,247,247,247,247,255},
{"/piyg5/4",61,103,225,184,225,134,255},
{"/piyg5/5",72,198,172,77,172,38,255},
{"/piyg6/1",230,220,197,197,27,125,255},
{"/piyg6/2",231,76,233,233,163,201,255},
{"/piyg6/3",233,29,253,253,224,239,255},
{"/piyg6/4",59,38,245,230,245,208,255},
{"/piyg6/5",63,129,215,161,215,106,255},
{"/piyg6/6",68,197,146,77,146,33,255},
{"/piyg7/1",230,220,197,197,27,125,255},
{"/piyg7/2",231,76,233,233,163,201,255},
{"/piyg7/3",233,29,253,253,224,239,255},
{"/piyg7/4",0,0,247,247,247,247,255},
{"/piyg7/5",59,38,245,230,245,208,255},
{"/piyg7/6",63,129,215,161,215,106,255},
{"/piyg7/7",68,197,146,77,146,33,255},
{"/piyg8/1",230,220,197,197,27,125,255},
{"/piyg8/2",232,118,222,222,119,174,255},
{"/piyg8/3",229,62,241,241,182,218,255},
{"/piyg8/4",233,29,253,253,224,239,255},
{"/piyg8/5",59,38,245,230,245,208,255},
{"/piyg8/6",61,103,225,184,225,134,255},
{"/piyg8/7",63,166,188,127,188,65,255},
{"/piyg8/8",68,197,146,77,146,33,255},
{"/piyg9/1",230,220,197,197,27,125,255},
{"/piyg9/2",232,118,222,222,119,174,255},
{"/piyg9/3",229,62,241,241,182,218,255},
{"/piyg9/4",233,29,253,253,224,239,255},
{"/piyg9/5",0,0,247,247,247,247,255},
{"/piyg9/6",59,38,245,230,245,208,255},
{"/piyg9/7",61,103,225,184,225,134,255},
{"/piyg9/8",63,166,188,127,188,65,255},
{"/piyg9/9",68,197,146,77,146,33,255},
{"/prgn10/1",206,255,75,64,0,75,255},
{"/prgn10/10",101,255,68,0,68,27,255},
{"/prgn10/2",206,173,131,118,42,131,255},
{"/prgn10/3",199,87,171,153,112,171,255},
{"/prgn10/4",199,51,207,194,165,207,255},
{"/prgn10/5",210,21,232,231,212,232,255},
{"/prgn10/6",76,30,240,217,240,211,255},
{"/prgn10/7",80,68,219,166,219,160,255},
{"/prgn10/8",88,123,174,90,174,97,255},
{"/prgn10/9",97,197,120,27,120,55,255},
{"/prgn11/1",206,255,75,64,0,75,255},
{"/prgn11/10",97,197,120,27,120,55,255},
{"/prgn11/11",101,255,68,0,68,27,255},
{"/prgn11/2",206,173,131,118,42,131,255},
{"/prgn11/3",199,87,171,153,112,171,255},
{"/prgn11/4",199,51,207,194,165,207,255},
{"/prgn11/5",210,21,232,231,212,232,255},
{"/prgn11/6",0,0,247,247,247,247,255},
{"/prgn11/7",76,30,240,217,240,211,255},
{"/prgn11/8",80,68,219,166,219,160,255},
{"/prgn11/9",88,123,174,90,174,97,255},
{"/prgn3/1",196,70,195,175,141,195,255},
{"/prgn3/2",0,0,247,247,247,247,255},
{"/prgn3/3",82,90,191,127,191,123,255},
{"/prgn4/1",201,168,148,123,50,148,255},
{"/prgn4/2",199,51,207,194,165,207,255},
{"/prgn4/3",80,68,219,166,219,160,255},
{"/prgn4/4",102,255,136,0,136,55,255},
{"/prgn5/1",201,168,148,123,50,148,255},
{"/prgn5/2",199,51,207,194,165,207,255},
{"/prgn5/3",0,0,247,247,247,247,255},
{"/prgn5/4",80,68,219,166,219,160,255},
{"/prgn5/5",102,255,136,0,136,55,255},
{"/prgn6/1",206,173,131,118,42,131,255},
{"/prgn6/2",196,70,195,175,141,195,255},
{"/prgn6/3",210,21,232,231,212,232,255},
{"/prgn6/4",76,30,240,217,240,211,255},
{"/prgn6/5",82,90,191,127,191,123,255},
{"/prgn6/6",97,197,120,27,120,55,255},
{"/prgn7/1",206,173,131,118,42,131,255},
{"/prgn7/2",196,70,195,175,141,195,255},
{"/prgn7/3",210,21,232,231,212,232,255},
{"/prgn7/4",0,0,247,247,247,247,255},
{"/prgn7/5",76,30,240,217,240,211,255},
{"/prgn7/6",82,90,191,127,191,123,255},
{"/prgn7/7",97,197,120,27,120,55,255},
{"/prgn8/1",206,173,131,118,42,131,255},
{"/prgn8/2",199,87,171,153,112,171,255},
{"/prgn8/3",199,51,207,194,165,207,255},
{"/prgn8/4",210,21,232,231,212,232,255},
{"/prgn8/5",76,30,240,217,240,211,255},
{"/prgn8/6",80,68,219,166,219,160,255},
{"/prgn8/7",88,123,174,90,174,97,255},
{"/prgn8/8",97,197,120,27,120,55,255},
{"/prgn9/1",206,173,131,118,42,131,255},
{"/prgn9/2",199,87,171,153,112,171,255},
{"/prgn9/3",199,51,207,194,165,207,255},
{"/prgn9/4",210,21,232,231,212,232,255},
{"/prgn9/5",0,0,247,247,247,247,255},
{"/prgn9/6",76,30,240,217,240,211,255},
{"/prgn9/7",80,68,219,166,219,160,255},
{"/prgn9/8",88,123,174,90,174,97,255},
{"/prgn9/9",97,197,120,27,120,55,255},
{"/pubu3/1",189,11,242,236,231,242,255},
{"/pubu3/2",151,61,219,166,189,219,255},
{"/pubu3/3",141,197,190,43,140,190,255},
{"/pubu4/1",185,8,246,241,238,246,255},
{"/pubu4/2",155,40,225,189,201,225,255},
{"/pubu4/3",145,112,207,116,169,207,255},
{"/pubu4/4",143,247,176,5,112,176,255},
{"/pubu5/1",185,8,246,241,238,246,255},
{"/pubu5/2",155,40,225,189,201,225,255},
{"/pubu5/3",145,112,207,116,169,207,255},
{"/pubu5/4",141,197,190,43,140,190,255},
{"/pubu5/5",143,247,141,4,90,141,255},
{"/pubu6/1",185,8,246,241,238,246,255},
{"/pubu6/2",168,24,230,208,209,230,255},
{"/pubu6/3",151,61,219,166,189,219,255},
{"/pubu6/4",145,112,207,116,169,207,255},
{"/pubu6/5",141,197,190,43,140,190,255},
{"/pubu6/6",143,247,141,4,90,141,255},
{"/pubu7/1",185,8,246,241,238,246,255},
{"/pubu7/2",168,24,230,208,209,230,255},
{"/pubu7/3",151,61,219,166,189,219,255},
{"/pubu7/4",145,112,207,116,169,207,255},
{"/pubu7/5",142,183,192,54,144,192,255},
{"/pubu7/6",143,247,176,5,112,176,255},
{"/pubu7/7",143,248,123,3,78,123,255},
{"/pubu8/1",233,8,255,255,247,251,255},
{"/pubu8/2",189,11,242,236,231,242,255},
{"/pubu8/3",168,24,230,208,209,230,255},
{"/pubu8/4",151,61,219,166,189,219,255},
{"/pubu8/5",145,112,207,116,169,207,255},
{"/pubu8/6",142,183,192,54,144,192,255},
{"/pubu8/7",143,247,176,5,112,176,255},
{"/pubu8/8",143,248,123,3,78,123,255},
{"/pubu9/1",233,8,255,255,247,251,255},
{"/pubu9/2",189,11,242,236,231,242,255},
{"/pubu9/3",168,24,230,208,209,230,255},
{"/pubu9/4",151,61,219,166,189,219,255},
{"/pubu9/5",145,112,207,116,169,207,255},
{"/pubu9/6",142,183,192,54,144,192,255},
{"/pubu9/7",143,247,176,5,112,176,255},
{"/pubu9/8",143,247,141,4,90,141,255},
{"/pubu9/9",143,249,88,2,56,88,255},
{"/pubugn3/1",200,14,240,236,226,240,255},
{"/pubugn3/2",151,61,219,166,189,219,255},
{"/pubugn3/3",130,208,153,28,144,153,255},
{"/pubugn4/1",207,8,247,246,239,247,255},
{"/pubugn4/2",155,40,225,189,201,225,255},
{"/pubugn4/3",143,128,207,103,169,207,255},
{"/pubugn4/4",130,251,138,2,129,138,255},
{"/pubugn5/1",207,8,247,246,239,247,255},
{"/pubugn5/2",155,40,225,189,201,225,255},
{"/pubugn5/3",143,128,207,103,169,207,255},
{"/pubugn5/4",130,208,153,28,144,153,255},
{"/pubugn5/5",119,252,108,1,108,89,255},
{"/pubugn6/1",207,8,247,246,239,247,255},
{"/pubugn6/2",168,24,230,208,209,230,255},
{"/pubugn6/3",151,61,219,166,189,219,255},
{"/pubugn6/4",143,128,207,103,169,207,255},
{"/pubugn6/5",130,208,153,28,144,153,255},
{"/pubugn6/6",119,252,108,1,108,89,255},
{"/pubugn7/1",207,8,247,246,239,247,255},
{"/pubugn7/2",168,24,230,208,209,230,255},
{"/pubugn7/3",151,61,219,166,189,219,255},
{"/pubugn7/4",143,128,207,103,169,207,255},
{"/pubugn7/5",142,183,192,54,144,192,255},
{"/pubugn7/6",130,251,138,2,129,138,255},
{"/pubugn7/7",118,252,100,1,100,80,255},
{"/pubugn8/1",233,8,255,255,247,251,255},
{"/pubugn8/2",200,14,240,236,226,240,255},
{"/pubugn8/3",168,24,230,208,209,230,255},
{"/pubugn8/4",151,61,219,166,189,219,255},
{"/pubugn8/5",143,128,207,103,169,207,255},
{"/pubugn8/6",142,183,192,54,144,192,255},
{"/pubugn8/7",130,251,138,2,129,138,255},
{"/pubugn8/8",118,252,100,1,100,80,255},
{"/pubugn9/1",233,8,255,255,247,251,255},
{"/pubugn9/2",200,14,240,236,226,240,255},
{"/pubugn9/3",168,24,230,208,209,230,255},
{"/pubugn9/4",151,61,219,166,189,219,255},
{"/pubugn9/5",143,128,207,103,169,207,255},
{"/pubugn9/6",142,183,192,54,144,192,255},
{"/pubugn9/7",130,251,138,2,129,138,255},
{"/pubugn9/8",119,252,108,1,108,89,255},
{"/pubugn9/9",117,251,70,1,70,54,255},
{"/puor10/1",18,238,127,127,59,8,255},
{"/puor10/10",195,255,75,45,0,75,255},
{"/puor10/2",20,246,179,179,88,6,255},
{"/puor10/3",22,232,224,224,130,20,255},
{"/puor10/4",23,155,253,253,184,99,255},
{"/puor10/5",24,72,254,254,224,182,255},
{"/puor10/6",165,20,235,216,218,235,255},
{"/puor10/7",177,47,210,178,171,210,255},
{"/puor10/8",179,84,172,128,115,172,255},
{"/puor10/9",189,181,136,84,39,136,255},
{"/puor11/1",18,238,127,127,59,8,255},
{"/puor11/10",189,181,136,84,39,136,255},
{"/puor11/11",195,255,75,45,0,75,255},
{"/puor11/2",20,246,179,179,88,6,255},
{"/puor11/3",22,232,224,224,130,20,255},
{"/puor11/4",23,155,253,253,184,99,255},
{"/puor11/5",24,72,254,254,224,182,255},
{"/puor11/6",0,0,247,247,247,247,255},
{"/puor11/7",165,20,235,216,218,235,255},
{"/puor11/8",177,47,210,178,171,210,255},
{"/puor11/9",179,84,172,128,115,172,255},
{"/puor3/1",23,187,241,241,163,64,255},
{"/puor3/2",0,0,247,247,247,247,255},
{"/puor3/3",178,69,195,153,142,195,255},
{"/puor4/1",17,253,230,230,97,1,255},
{"/puor4/2",23,155,253,253,184,99,255},
{"/puor4/3",177,47,210,178,171,210,255},
{"/puor4/4",185,155,153,94,60,153,255},
{"/puor5/1",17,253,230,230,97,1,255},
{"/puor5/2",23,155,253,253,184,99,255},
{"/puor5/3",0,0,247,247,247,247,255},
{"/puor5/4",177,47,210,178,171,210,255},
{"/puor5/5",185,155,153,94,60,153,255},
{"/puor6/1",20,246,179,179,88,6,255},
{"/puor6/2",23,187,241,241,163,64,255},
{"/puor6/3",24,72,254,254,224,182,255},
{"/puor6/4",165,20,235,216,218,235,255},
{"/puor6/5",178,69,195,153,142,195,255},
{"/puor6/6",189,181,136,84,39,136,255},
{"/puor7/1",20,246,179,179,88,6,255},
{"/puor7/2",23,187,241,241,163,64,255},
{"/puor7/3",24,72,254,254,224,182,255},
{"/puor7/4",0,0,247,247,247,247,255},
{"/puor7/5",165,20,235,216,218,235,255},
{"/puor7/6",178,69,195,153,142,195,255},
{"/puor7/7",189,181,136,84,39,136,255},
{"/puor8/1",20,246,179,179,88,6,255},
{"/puor8/2",22,232,224,224,130,20,255},
{"/puor8/3",23,155,253,253,184,99,255},
{"/puor8/4",24,72,254,254,224,182,255},
{"/puor8/5",165,20,235,216,218,235,255},
{"/puor8/6",177,47,210,178,171,210,255},
{"/puor8/7",179,84,172,128,115,172,255},
{"/puor8/8",189,181,136,84,39,136,255},
{"/puor9/1",20,246,179,179,88,6,255},
{"/puor9/2",22,232,224,224,130,20,255},
{"/puor9/3",23,155,253,253,184,99,255},
{"/puor9/4",24,72,254,254,224,182,255},
{"/puor9/5",0,0,247,247,247,247,255},
{"/puor9/6",165,20,235,216,218,235,255},
{"/puor9/7",177,47,210,178,171,210,255},
{"/puor9/8",179,84,172,128,115,172,255},
{"/puor9/9",189,181,136,84,39,136,255},
{"/purd3/1",188,14,239,231,225,239,255},
{"/purd3/2",214,67,201,201,148,199,255},
{"/purd3/3",234,222,221,221,28,119,255},
{"/purd4/1",185,8,246,241,238,246,255},
{"/purd4/2",211,41,216,215,181,216,255},
{"/purd4/3",228,139,223,223,101,176,255},
{"/purd4/4",239,232,206,206,18,86,255},
{"/purd5/1",185,8,246,241,238,246,255},
{"/purd5/2",211,41,216,215,181,216,255},
{"/purd5/3",228,139,223,223,101,176,255},
{"/purd5/4",234,222,221,221,28,119,255},
{"/purd5/5",236,255,152,152,0,67,255},
{"/purd6/1",185,8,246,241,238,246,255},
{"/purd6/2",204,38,218,212,185,218,255},
{"/purd6/3",214,67,201,201,148,199,255},
{"/purd6/4",228,139,223,223,101,176,255},
{"/purd6/5",234,222,221,221,28,119,255},
{"/purd6/6",236,255,152,152,0,67,255},
{"/purd7/1",185,8,246,241,238,246,255},
{"/purd7/2",204,38,218,212,185,218,255},
{"/purd7/3",214,67,201,201,148,199,255},
{"/purd7/4",228,139,223,223,101,176,255},
{"/purd7/5",233,209,231,231,41,138,255},
{"/purd7/6",239,232,206,206,18,86,255},
{"/purd7/7",236,255,145,145,0,63,255},
{"/purd8/1",195,5,249,247,244,249,255},
{"/purd8/2",188,14,239,231,225,239,255},
{"/purd8/3",204,38,218,212,185,218,255},
{"/purd8/4",214,67,201,201,148,199,255},
{"/purd8/5",228,139,223,223,101,176,255},
{"/purd8/6",233,209,231,231,41,138,255},
{"/purd8/7",239,232,206,206,18,86,255},
{"/purd8/8",236,255,145,145,0,63,255},
{"/purd9/1",195,5,249,247,244,249,255},
{"/purd9/2",188,14,239,231,225,239,255},
{"/purd9/3",204,38,218,212,185,218,255},
{"/purd9/4",214,67,201,201,148,199,255},
{"/purd9/5",228,139,223,223,101,176,255},
{"/purd9/6",233,209,231,231,41,138,255},
{"/purd9/7",239,232,206,206,18,86,255},
{"/purd9/8",236,255,152,152,0,67,255},
{"/purd9/9",242,255,103,103,0,31,255},
{"/purples3/1",180,8,245,239,237,245,255},
{"/purples3/2",168,37,220,188,189,220,255},
{"/purples3/3",176,100,177,117,107,177,255},
{"/purples4/1",182,7,247,242,240,247,255},
{"/purples4/2",173,28,226,203,201,226,255},
{"/purples4/3",173,58,200,158,154,200,255},
{"/purples4/4",182,128,163,106,81,163,255},
{"/purples5/1",182,7,247,242,240,247,255},
{"/purples5/2",173,28,226,203,201,226,255},
{"/purples5/3",173,58,200,158,154,200,255},
{"/purples5/4",176,100,177,117,107,177,255},
{"/purples5/5",188,185,143,84,39,143,255},
{"/purples6/1",182,7,247,242,240,247,255},
{"/purples6/2",170,18,235,218,218,235,255},
{"/purples6/3",168,37,220,188,189,220,255},
{"/purples6/4",173,58,200,158,154,200,255},
{"/purples6/5",176,100,177,117,107,177,255},
{"/purples6/6",188,185,143,84,39,143,255},
{"/purples7/1",182,7,247,242,240,247,255},
{"/purples7/2",170,18,235,218,218,235,255},
{"/purples7/3",168,37,220,188,189,220,255},
{"/purples7/4",173,58,200,158,154,200,255},
{"/purples7/5",172,83,186,128,125,186,255},
{"/purples7/6",182,128,163,106,81,163,255},
{"/purples7/7",190,216,134,74,20,134,255},
{"/purples8/1",191,2,253,252,251,253,255},
{"/purples8/2",180,8,245,239,237,245,255},
{"/purples8/3",170,18,235,218,218,235,255},
{"/purples8/4",168,37,220,188,189,220,255},
{"/purples8/5",173,58,200,158,154,200,255},
{"/purples8/6",172,83,186,128,125,186,255},
{"/purples8/7",182,128,163,106,81,163,255},
{"/purples8/8",190,216,134,74,20,134,255},
{"/purples9/1",191,2,253,252,251,253,255},
{"/purples9/2",180,8,245,239,237,245,255},
{"/purples9/3",170,18,235,218,218,235,255},
{"/purples9/4",168,37,220,188,189,220,255},
{"/purples9/5",173,58,200,158,154,200,255},
{"/purples9/6",172,83,186,128,125,186,255},
{"/purples9/7",182,128,163,106,81,163,255},
{"/purples9/8",188,185,143,84,39,143,255},
{"/purples9/9",191,255,125,63,0,125,255},
{"/rdbu10/1",242,255,103,103,0,31,255},
{"/rdbu10/10",150,241,97,5,48,97,255},
{"/rdbu10/2",249,220,178,178,24,43,255},
{"/rdbu10/3",5,163,214,214,96,77,255},
{"/rdbu10/4",13,119,244,244,165,130,255},
{"/rdbu10/5",15,54,253,253,219,199,255},
{"/rdbu10/6",142,32,240,209,229,240,255},
{"/rdbu10/7",141,87,222,146,197,222,255},
{"/rdbu10/8",143,167,195,67,147,195,255},
{"/rdbu10/9",148,206,172,33,102,172,255},
{"/rdbu11/1",242,255,103,103,0,31,255},
{"/rdbu11/10",148,206,172,33,102,172,255},
{"/rdbu11/11",150,241,97,5,48,97,255},
{"/rdbu11/2",249,220,178,178,24,43,255},
{"/rdbu11/3",5,163,214,214,96,77,255},
{"/rdbu11/4",13,119,244,244,165,130,255},
{"/rdbu11/5",15,54,253,253,219,199,255},
{"/rdbu11/6",0,0,247,247,247,247,255},
{"/rdbu11/7",142,32,240,209,229,240,255},
{"/rdbu11/8",141,87,222,146,197,222,255},
{"/rdbu11/9",143,167,195,67,147,195,255},
{"/rdbu3/1",12,150,239,239,138,98,255},
{"/rdbu3/2",0,0,247,247,247,247,255},
{"/rdbu3/3",143,128,207,103,169,207,255},
{"/rdbu4/1",248,255,202,202,0,32,255},
{"/rdbu4/2",13,119,244,244,165,130,255},
{"/rdbu4/3",141,87,222,146,197,222,255},
{"/rdbu4/4",143,247,176,5,113,176,255},
{"/rdbu5/1",248,255,202,202,0,32,255},
{"/rdbu5/2",13,119,244,244,165,130,255},
{"/rdbu5/3",0,0,247,247,247,247,255},
{"/rdbu5/4",141,87,222,146,197,222,255},
{"/rdbu5/5",143,247,176,5,113,176,255},
{"/rdbu6/1",249,220,178,178,24,43,255},
{"/rdbu6/2",12,150,239,239,138,98,255},
{"/rdbu6/3",15,54,253,253,219,199,255},
{"/rdbu6/4",142,32,240,209,229,240,255},
{"/rdbu6/5",143,128,207,103,169,207,255},
{"/rdbu6/6",148,206,172,33,102,172,255},
{"/rdbu7/1",249,220,178,178,24,43,255},
{"/rdbu7/2",12,150,239,239,138,98,255},
{"/rdbu7/3",15,54,253,253,219,199,255},
{"/rdbu7/4",0,0,247,247,247,247,255},
{"/rdbu7/5",142,32,240,209,229,240,255},
{"/rdbu7/6",143,128,207,103,169,207,255},
{"/rdbu7/7",148,206,172,33,102,172,255},
{"/rdbu8/1",249,220,178,178,24,43,255},
{"/rdbu8/2",5,163,214,214,96,77,255},
{"/rdbu8/3",13,119,244,244,165,130,255},
{"/rdbu8/4",15,54,253,253,219,199,255},
{"/rdbu8/5",142,32,240,209,229,240,255},
{"/rdbu8/6",141,87,222,146,197,222,255},
{"/rdbu8/7",143,167,195,67,147,195,255},
{"/rdbu8/8",148,206,172,33,102,172,255},
{"/rdbu9/1",249,220,178,178,24,43,255},
{"/rdbu9/2",5,163,214,214,96,77,255},
{"/rdbu9/3",13,119,244,244,165,130,255},
{"/rdbu9/4",15,54,253,253,219,199,255},
{"/rdbu9/5",0,0,247,247,247,247,255},
{"/rdbu9/6",142,32,240,209,229,240,255},
{"/rdbu9/7",141,87,222,146,197,222,255},
{"/rdbu9/8",143,167,195,67,147,195,255},
{"/rdbu9/9",148,206,172,33,102,172,255},
{"/rdgy10/1",242,255,103,103,0,31,255},
{"/rdgy10/10",0,0,26,26,26,26,255},
{"/rdgy10/2",249,220,178,178,24,43,255},
{"/rdgy10/3",5,163,214,214,96,77,255},
{"/rdgy10/4",13,119,244,244,165,130,255},
{"/rdgy10/5",15,54,253,253,219,199,255},
{"/rdgy10/6",0,0,224,224,224,224,255},
{"/rdgy10/7",0,0,186,186,186,186,255},
{"/rdgy10/8",0,0,135,135,135,135,255},
{"/rdgy10/9",0,0,77,77,77,77,255},
{"/rdgy11/1",242,255,103,103,0,31,255},
{"/rdgy11/10",0,0,77,77,77,77,255},
{"/rdgy11/11",0,0,26,26,26,26,255},
{"/rdgy11/2",249,220,178,178,24,43,255},
{"/rdgy11/3",5,163,214,214,96,77,255},
{"/rdgy11/4",13,119,244,244,165,130,255},
{"/rdgy11/5",15,54,253,253,219,199,255},
{"/rdgy11/6",0,0,255,255,255,255,255},
{"/rdgy11/7",0,0,224,224,224,224,255},
{"/rdgy11/8",0,0,186,186,186,186,255},
{"/rdgy11/9",0,0,135,135,135,135,255},
{"/rdgy3/1",12,150,239,239,138,98,255},
{"/rdgy3/2",0,0,255,255,255,255,255},
{"/rdgy3/3",0,0,153,153,153,153,255},
{"/rdgy4/1",248,255,202,202,0,32,255},
{"/rdgy4/2",13,119,244,244,165,130,255},
{"/rdgy4/3",0,0,186,186,186,186,255},
{"/rdgy4/4",0,0,64,64,64,64,255},
{"/rdgy5/1",248,255,202,202,0,32,255},
{"/rdgy5/2",13,119,244,244,165,130,255},
{"/rdgy5/3",0,0,255,255,255,255,255},
{"/rdgy5/4",0,0,186,186,186,186,255},
{"/rdgy5/5",0,0,64,64,64,64,255},
{"/rdgy6/1",249,220,178,178,24,43,255},
{"/rdgy6/2",12,150,239,239,138,98,255},
{"/rdgy6/3",15,54,253,253,219,199,255},
{"/rdgy6/4",0,0,224,224,224,224,255},
{"/rdgy6/5",0,0,153,153,153,153,255},
{"/rdgy6/6",0,0,77,77,77,77,255},
{"/rdgy7/1",249,220,178,178,24,43,255},
{"/rdgy7/2",12,150,239,239,138,98,255},
{"/rdgy7/3",15,54,253,253,219,199,255},
{"/rdgy7/4",0,0,255,255,255,255,255},
{"/rdgy7/5",0,0,224,224,224,224,255},
{"/rdgy7/6",0,0,153,153,153,153,255},
{"/rdgy7/7",0,0,77,77,77,77,255},
{"/rdgy8/1",249,220,178,178,24,43,255},
{"/rdgy8/2",5,163,214,214,96,77,255},
{"/rdgy8/3",13,119,244,244,165,130,255},
{"/rdgy8/4",15,54,253,253,219,199,255},
{"/rdgy8/5",0,0,224,224,224,224,255},
{"/rdgy8/6",0,0,186,186,186,186,255},
{"/rdgy8/7",0,0,135,135,135,135,255},
{"/rdgy8/8",0,0,77,77,77,77,255},
{"/rdgy9/1",249,220,178,178,24,43,255},
{"/rdgy9/2",5,163,214,214,96,77,255},
{"/rdgy9/3",13,119,244,244,165,130,255},
{"/rdgy9/4",15,54,253,253,219,199,255},
{"/rdgy9/5",0,0,255,255,255,255,255},
{"/rdgy9/6",0,0,224,224,224,224,255},
{"/rdgy9/7",0,0,186,186,186,186,255},
{"/rdgy9/8",0,0,135,135,135,135,255},
{"/rdgy9/9",0,0,77,77,77,77,255},
{"/rdpu3/1",3,32,253,253,224,221,255},
{"/rdpu3/2",244,92,250,250,159,181,255},
{"/rdpu3/3",227,220,197,197,27,138,255},
{"/rdpu4/1",13,28,254,254,235,226,255},
{"/rdpu4/2",252,72,251,251,180,185,255},
{"/rdpu4/3",238,147,247,247,104,161,255},
{"/rdpu4/4",224,253,174,174,1,126,255},
{"/rdpu5/1",13,28,254,254,235,226,255},
{"/rdpu5/2",252,72,251,251,180,185,255},
{"/rdpu5/3",238,147,247,247,104,161,255},
{"/rdpu5/4",227,220,197,197,27,138,255},
{"/rdpu5/5",213,252,122,122,1,119,255},
{"/rdpu6/1",13,28,254,254,235,226,255},
{"/rdpu6/2",3,60,252,252,197,192,255},
{"/rdpu6/3",244,92,250,250,159,181,255},
{"/rdpu6/4",238,147,247,247,104,161,255},
{"/rdpu6/5",227,220,197,197,27,138,255},
{"/rdpu6/6",213,252,122,122,1,119,255},
{"/rdpu7/1",13,28,254,254,235,226,255},
{"/rdpu7/2",3,60,252,252,197,192,255},
{"/rdpu7/3",244,92,250,250,159,181,255},
{"/rdpu7/4",238,147,247,247,104,161,255},
{"/rdpu7/5",230,195,221,221,52,151,255},
{"/rdpu7/6",224,253,174,174,1,126,255},
{"/rdpu7/7",213,252,122,122,1,119,255},
{"/rdpu8/1",14,12,255,255,247,243,255},
{"/rdpu8/2",3,32,253,253,224,221,255},
{"/rdpu8/3",3,60,252,252,197,192,255},
{"/rdpu8/4",244,92,250,250,159,181,255},
{"/rdpu8/5",238,147,247,247,104,161,255},
{"/rdpu8/6",230,195,221,221,52,151,255},
{"/rdpu8/7",224,253,174,174,1,126,255},
{"/rdpu8/8",213,252,122,122,1,119,255},
{"/rdpu9/1",14,12,255,255,247,243,255},
{"/rdpu9/2",3,32,253,253,224,221,255},
{"/rdpu9/3",3,60,252,252,197,192,255},
{"/rdpu9/4",244,92,250,250,159,181,255},
{"/rdpu9/5",238,147,247,247,104,161,255},
{"/rdpu9/6",230,195,221,221,52,151,255},
{"/rdpu9/7",224,253,174,174,1,126,255},
{"/rdpu9/8",213,252,122,122,1,119,255},
{"/rdpu9/9",199,255,106,73,0,106,255},
{"/rdylbu10/1",245,255,165,165,0,38,255},
{"/rdylbu10/10",167,171,149,49,54,149,255},
{"/rdylbu10/2",2,208,215,215,48,39,255},
{"/rdylbu10/3",10,184,244,244,109,67,255},
{"/rdylbu10/4",20,157,253,253,174,97,255},
{"/rdylbu10/5",30,110,254,254,224,144,255},
{"/rdylbu10/6",136,24,248,224,243,248,255},
{"/rdylbu10/7",138,67,233,171,217,233,255},
{"/rdylbu10/8",143,113,209,116,173,209,255},
{"/rdylbu10/9",151,157,180,69,117,180,255},
{"/rdylbu11/1",245,255,165,165,0,38,255},
{"/rdylbu11/10",151,157,180,69,117,180,255},
{"/rdylbu11/11",167,171,149,49,54,149,255},
{"/rdylbu11/2",2,208,215,215,48,39,255},
{"/rdylbu11/3",10,184,244,244,109,67,255},
{"/rdylbu11/4",20,157,253,253,174,97,255},
{"/rdylbu11/5",30,110,254,254,224,144,255},
{"/rdylbu11/6",42,64,255,255,255,191,255},
{"/rdylbu11/7",136,24,248,224,243,248,255},
{"/rdylbu11/8",138,67,233,171,217,233,255},
{"/rdylbu11/9",143,113,209,116,173,209,255},
{"/rdylbu3/1",13,164,252,252,141,89,255},
{"/rdylbu3/2",42,64,255,255,255,191,255},
{"/rdylbu3/3",143,86,219,145,191,219,255},
{"/rdylbu4/1",254,225,215,215,25,28,255},
{"/rdylbu4/2",20,157,253,253,174,97,255},
{"/rdylbu4/3",138,67,233,171,217,233,255},
{"/rdylbu4/4",145,193,182,44,123,182,255},
{"/rdylbu5/1",254,225,215,215,25,28,255},
{"/rdylbu5/2",20,157,253,253,174,97,255},
{"/rdylbu5/3",42,64,255,255,255,191,255},
{"/rdylbu5/4",138,67,233,171,217,233,255},
{"/rdylbu5/5",145,193,182,44,123,182,255},
{"/rdylbu6/1",2,208,215,215,48,39,255},
{"/rdylbu6/2",13,164,252,252,141,89,255},
{"/rdylbu6/3",30,110,254,254,224,144,255},
{"/rdylbu6/4",136,24,248,224,243,248,255},
{"/rdylbu6/5",143,86,219,145,191,219,255},
{"/rdylbu6/6",151,157,180,69,117,180,255},
{"/rdylbu7/1",2,208,215,215,48,39,255},
{"/rdylbu7/2",13,164,252,252,141,89,255},
{"/rdylbu7/3",30,110,254,254,224,144,255},
{"/rdylbu7/4",42,64,255,255,255,191,255},
{"/rdylbu7/5",136,24,248,224,243,248,255},
{"/rdylbu7/6",143,86,219,145,191,219,255},
{"/rdylbu7/7",151,157,180,69,117,180,255},
{"/rdylbu8/1",2,208,215,215,48,39,255},
{"/rdylbu8/2",10,184,244,244,109,67,255},
{"/rdylbu8/3",20,157,253,253,174,97,255},
{"/rdylbu8/4",30,110,254,254,224,144,255},
{"/rdylbu8/5",136,24,248,224,243,248,255},
{"/rdylbu8/6",138,67,233,171,217,233,255},
{"/rdylbu8/7",143,113,209,116,173,209,255},
{"/rdylbu8/8",151,157,180,69,117,180,255},
{"/rdylbu9/1",2,208,215,215,48,39,255},
{"/rdylbu9/2",10,184,244,244,109,67,255},
{"/rdylbu9/3",20,157,253,253,174,97,255},
{"/rdylbu9/4",30,110,254,254,224,144,255},
{"/rdylbu9/5",42,64,255,255,255,191,255},
{"/rdylbu9/6",136,24,248,224,243,248,255},
{"/rdylbu9/7",138,67,233,171,217,233,255},
{"/rdylbu9/8",143,113,209,116,173,209,255},
{"/rdylbu9/9",151,157,180,69,117,180,255},
{"/rdylgn10/1",245,255,165,165,0,38,255},
{"/rdylgn10/10",107,255,104,0,104,55,255},
{"/rdylgn10/2",2,208,215,215,48,39,255},
{"/rdylgn10/3",10,184,244,244,109,67,255},
{"/rdylgn10/4",20,157,253,253,174,97,255},
{"/rdylgn10/5",31,115,254,254,224,139,255},
{"/rdylgn10/6",51,106,239,217,239,139,255},
{"/rdylgn10/7",62,130,217,166,217,106,255},
{"/rdylgn10/8",83,121,189,102,189,99,255},
{"/rdylgn10/9",103,211,152,26,152,80,255},
{"/rdylgn11/1",245,255,165,165,0,38,255},
{"/rdylgn11/10",103,211,152,26,152,80,255},
{"/rdylgn11/11",107,255,104,0,104,55,255},
{"/rdylgn11/2",2,208,215,215,48,39,255},
{"/rdylgn11/3",10,184,244,244,109,67,255},
{"/rdylgn11/4",20,157,253,253,174,97,255},
{"/rdylgn11/5",31,115,254,254,224,139,255},
{"/rdylgn11/6",42,64,255,255,255,191,255},
{"/rdylgn11/7",51,106,239,217,239,139,255},
{"/rdylgn11/8",62,130,217,166,217,106,255},
{"/rdylgn11/9",83,121,189,102,189,99,255},
{"/rdylgn3/1",13,164,252,252,141,89,255},
{"/rdylgn3/2",42,64,255,255,255,191,255},
{"/rdylgn3/3",66,136,207,145,207,96,255},
{"/rdylgn4/1",254,225,215,215,25,28,255},
{"/rdylgn4/2",20,157,253,253,174,97,255},
{"/rdylgn4/3",62,130,217,166,217,106,255},
{"/rdylgn4/4",98,210,150,26,150,65,255},
{"/rdylgn5/1",254,225,215,215,25,28,255},
{"/rdylgn5/2",20,157,253,253,174,97,255},
{"/rdylgn5/3",42,64,255,255,255,191,255},
{"/rdylgn5/4",62,130,217,166,217,106,255},
{"/rdylgn5/5",98,210,150,26,150,65,255},
{"/rdylgn6/1",2,208,215,215,48,39,255},
{"/rdylgn6/2",13,164,252,252,141,89,255},
{"/rdylgn6/3",31,115,254,254,224,139,255},
{"/rdylgn6/4",51,106,239,217,239,139,255},
{"/rdylgn6/5",66,136,207,145,207,96,255},
{"/rdylgn6/6",103,211,152,26,152,80,255},
{"/rdylgn7/1",2,208,215,215,48,39,255},
{"/rdylgn7/2",13,164,252,252,141,89,255},
{"/rdylgn7/3",31,115,254,254,224,139,255},
{"/rdylgn7/4",42,64,255,255,255,191,255},
{"/rdylgn7/5",51,106,239,217,239,139,255},
{"/rdylgn7/6",66,136,207,145,207,96,255},
{"/rdylgn7/7",103,211,152,26,152,80,255},
{"/rdylgn8/1",2,208,215,215,48,39,255},
{"/rdylgn8/2",10,184,244,244,109,67,255},
{"/rdylgn8/3",20,157,253,253,174,97,255},
{"/rdylgn8/4",31,115,254,254,224,139,255},
{"/rdylgn8/5",51,106,239,217,239,139,255},
{"/rdylgn8/6",62,130,217,166,217,106,255},
{"/rdylgn8/7",83,121,189,102,189,99,255},
{"/rdylgn8/8",103,211,152,26,152,80,255},
{"/rdylgn9/1",2,208,215,215,48,39,255},
{"/rdylgn9/2",10,184,244,244,109,67,255},
{"/rdylgn9/3",20,157,253,253,174,97,255},
{"/rdylgn9/4",31,115,254,254,224,139,255},
{"/rdylgn9/5",42,64,255,255,255,191,255},
{"/rdylgn9/6",51,106,239,217,239,139,255},
{"/rdylgn9/7",62,130,217,166,217,106,255},
{"/rdylgn9/8",83,121,189,102,189,99,255},
{"/rdylgn9/9",103,211,152,26,152,80,255},
{"/reds3/1",13,44,254,254,224,210,255},
{"/reds3/2",9,139,252,252,146,114,255},
{"/reds3/3",1,211,222,222,45,38,255},
{"/reds4/1",13,37,254,254,229,217,255},
{"/reds4/2",11,108,252,252,174,145,255},
{"/reds4/3",7,179,251,251,106,74,255},
{"/reds4/4",253,224,203,203,24,29,255},
{"/reds5/1",13,37,254,254,229,217,255},
{"/reds5/2",11,108,252,252,174,145,255},
{"/reds5/3",7,179,251,251,106,74,255},
{"/reds5/4",1,211,222,222,45,38,255},
{"/reds5/5",253,231,165,165,15,21,255},
{"/reds6/1",13,37,254,254,229,217,255},
{"/reds6/2",12,92,252,252,187,161,255},
{"/reds6/3",9,139,252,252,146,114,255},
{"/reds6/4",7,179,251,251,106,74,255},
{"/reds6/5",1,211,222,222,45,38,255},
{"/reds6/6",253,231,165,165,15,21,255},
{"/reds7/1",13,37,254,254,229,217,255},
{"/reds7/2",12,92,252,252,187,161,255},
{"/reds7/3",9,139,252,252,146,114,255},
{"/reds7/4",7,179,251,251,106,74,255},
{"/reds7/5",3,208,239,239,59,44,255},
{"/reds7/6",253,224,203,203,24,29,255},
{"/reds7/7",251,255,153,153,0,13,255},
{"/reds8/1",14,15,255,255,245,240,255},
{"/reds8/2",13,44,254,254,224,210,255},
{"/reds8/3",12,92,252,252,187,161,255},
{"/reds8/4",9,139,252,252,146,114,255},
{"/reds8/5",7,179,251,251,106,74,255},
{"/reds8/6",3,208,239,239,59,44,255},
{"/reds8/7",253,224,203,203,24,29,255},
{"/reds8/8",251,255,153,153,0,13,255},
{"/reds9/1",14,15,255,255,245,240,255},
{"/reds9/2",13,44,254,254,224,210,255},
{"/reds9/3",12,92,252,252,187,161,255},
{"/reds9/4",9,139,252,252,146,114,255},
{"/reds9/5",7,179,251,251,106,74,255},
{"/reds9/6",3,208,239,239,59,44,255},
{"/reds9/7",253,224,203,203,24,29,255},
{"/reds9/8",253,231,165,165,15,21,255},
{"/reds9/9",249,255,103,103,0,13,255},
{"/set13/1",254,225,228,228,26,28,255},
{"/set13/2",146,178,184,55,126,184,255},
{"/set13/3",83,147,175,77,175,74,255},
{"/set14/1",254,225,228,228,26,28,255},
{"/set14/2",146,178,184,55,126,184,255},
{"/set14/3",83,147,175,77,175,74,255},
{"/set14/4",207,132,163,152,78,163,255},
{"/set15/1",254,225,228,228,26,28,255},
{"/set15/2",146,178,184,55,126,184,255},
{"/set15/3",83,147,175,77,175,74,255},
{"/set15/4",207,132,163,152,78,163,255},
{"/set15/5",21,255,255,255,127,0,255},
{"/set16/1",254,225,228,228,26,28,255},
{"/set16/2",146,178,184,55,126,184,255},
{"/set16/3",83,147,175,77,175,74,255},
{"/set16/4",207,132,163,152,78,163,255},
{"/set16/5",21,255,255,255,127,0,255},
{"/set16/6",42,204,255,255,255,51,255},
{"/set17/1",254,225,228,228,26,28,255},
{"/set17/2",146,178,184,55,126,184,255},
{"/set17/3",83,147,175,77,175,74,255},
{"/set17/4",207,132,163,152,78,163,255},
{"/set17/5",21,255,255,255,127,0,255},
{"/set17/6",42,204,255,255,255,51,255},
{"/set17/7",15,193,166,166,86,40,255},
{"/set18/1",254,225,228,228,26,28,255},
{"/set18/2",146,178,184,55,126,184,255},
{"/set18/3",83,147,175,77,175,74,255},
{"/set18/4",207,132,163,152,78,163,255},
{"/set18/5",21,255,255,255,127,0,255},
{"/set18/6",42,204,255,255,255,51,255},
{"/set18/7",15,193,166,166,86,40,255},
{"/set18/8",232,121,247,247,129,191,255},
{"/set19/1",254,225,228,228,26,28,255},
{"/set19/2",146,178,184,55,126,184,255},
{"/set19/3",83,147,175,77,175,74,255},
{"/set19/4",207,132,163,152,78,163,255},
{"/set19/5",21,255,255,255,127,0,255},
{"/set19/6",42,204,255,255,255,51,255},
{"/set19/7",15,193,166,166,86,40,255},
{"/set19/8",232,121,247,247,129,191,255},
{"/set19/9",0,0,153,153,153,153,255},
{"/set23/1",114,120,194,102,194,165,255},
{"/set23/2",11,155,252,252,141,98,255},
{"/set23/3",156,77,203,141,160,203,255},
{"/set24/1",114,120,194,102,194,165,255},
{"/set24/2",11,155,252,252,141,98,255},
{"/set24/3",156,77,203,141,160,203,255},
{"/set24/4",228,102,231,231,138,195,255},
{"/set25/1",114,120,194,102,194,165,255},
{"/set25/2",11,155,252,252,141,98,255},
{"/set25/3",156,77,203,141,160,203,255},
{"/set25/4",228,102,231,231,138,195,255},
{"/set25/5",58,155,216,166,216,84,255},
{"/set26/1",114,120,194,102,194,165,255},
{"/set26/2",11,155,252,252,141,98,255},
{"/set26/3",156,77,203,141,160,203,255},
{"/set26/4",228,102,231,231,138,195,255},
{"/set26/5",58,155,216,166,216,84,255},
{"/set26/6",34,208,255,255,217,47,255},
{"/set27/1",114,120,194,102,194,165,255},
{"/set27/2",11,155,252,252,141,98,255},
{"/set27/3",156,77,203,141,160,203,255},
{"/set27/4",228,102,231,231,138,195,255},
{"/set27/5",58,155,216,166,216,84,255},
{"/set27/6",34,208,255,255,217,47,255},
{"/set27/7",25,90,229,229,196,148,255},
{"/set28/1",114,120,194,102,194,165,255},
{"/set28/2",11,155,252,252,141,98,255},
{"/set28/3",156,77,203,141,160,203,255},
{"/set28/4",228,102,231,231,138,195,255},
{"/set28/5",58,155,216,166,216,84,255},
{"/set28/6",34,208,255,255,217,47,255},
{"/set28/7",25,90,229,229,196,148,255},
{"/set28/8",0,0,179,179,179,179,255},
{"/set310/1",120,84,211,141,211,199,255},
{"/set310/10",211,82,189,188,128,189,255},
{"/set310/2",42,76,255,255,255,179,255},
{"/set310/3",175,37,218,190,186,218,255},
{"/set310/4",4,139,251,251,128,114,255},
{"/set310/5",144,100,211,128,177,211,255},
{"/set310/6",22,156,253,253,180,98,255},
{"/set310/7",58,134,222,179,222,105,255},
{"/set310/8",233,47,252,252,205,229,255},
{"/set310/9",0,0,217,217,217,217,255},
{"/set311/1",120,84,211,141,211,199,255},
{"/set311/10",211,82,189,188,128,189,255},
{"/set311/11",77,41,235,204,235,197,255},
{"/set311/2",42,76,255,255,255,179,255},
{"/set311/3",175,37,218,190,186,218,255},
{"/set311/4",4,139,251,251,128,114,255},
{"/set311/5",144,100,211,128,177,211,255},
{"/set311/6",22,156,253,253,180,98,255},
{"/set311/7",58,134,222,179,222,105,255},
{"/set311/8",233,47,252,252,205,229,255},
{"/set311/9",0,0,217,217,217,217,255},
{"/set312/1",120,84,211,141,211,199,255},
{"/set312/10",211,82,189,188,128,189,255},
{"/set312/11",77,41,235,204,235,197,255},
{"/set312/12",37,144,255,255,237,111,255},
{"/set312/2",42,76,255,255,255,179,255},
{"/set312/3",175,37,218,190,186,218,255},
{"/set312/4",4,139,251,251,128,114,255},
{"/set312/5",144,100,211,128,177,211,255},
{"/set312/6",22,156,253,253,180,98,255},
{"/set312/7",58,134,222,179,222,105,255},
{"/set312/8",233,47,252,252,205,229,255},
{"/set312/9",0,0,217,217,217,217,255},
{"/set33/1",120,84,211,141,211,199,255},
{"/set33/2",42,76,255,255,255,179,255},
{"/set33/3",175,37,218,190,186,218,255},
{"/set34/1",120,84,211,141,211,199,255},
{"/set34/2",42,76,255,255,255,179,255},
{"/set34/3",175,37,218,190,186,218,255},
{"/set34/4",4,139,251,251,128,114,255},
{"/set35/1",120,84,211,141,211,199,255},
{"/set35/2",42,76,255,255,255,179,255},
{"/set35/3",175,37,218,190,186,218,255},
{"/set35/4",4,139,251,251,128,114,255},
{"/set35/5",144,100,211,128,177,211,255},
{"/set36/1",120,84,211,141,211,199,255},
{"/set36/2",42,76,255,255,255,179,255},
{"/set36/3",175,37,218,190,186,218,255},
{"/set36/4",4,139,251,251,128,114,255},
{"/set36/5",144,100,211,128,177,211,255},
{"/set36/6",22,156,253,253,180,98,255},
{"/set37/1",120,84,211,141,211,199,255},
{"/set37/2",42,76,255,255,255,179,255},
{"/set37/3",175,37,218,190,186,218,255},
{"/set37/4",4,139,251,251,128,114,255},
{"/set37/5",144,100,211,128,177,211,255},
{"/set37/6",22,156,253,253,180,98,255},
{"/set37/7",58,134,222,179,222,105,255},
{"/set38/1",120,84,211,141,211,199,255},
{"/set38/2",42,76,255,255,255,179,255},
{"/set38/3",175,37,218,190,186,218,255},
{"/set38/4",4,139,251,251,128,114,255},
{"/set38/5",144,100,211,128,177,211,255},
{"/set38/6",22,156,253,253,180,98,255},
{"/set38/7",58,134,222,179,222,105,255},
{"/set38/8",233,47,252,252,205,229,255},
{"/set39/1",120,84,211,141,211,199,255},
{"/set39/2",42,76,255,255,255,179,255},
{"/set39/3",175,37,218,190,186,218,255},
{"/set39/4",4,139,251,251,128,114,255},
{"/set39/5",144,100,211,128,177,211,255},
{"/set39/6",22,156,253,253,180,98,255},
{"/set39/7",58,134,222,179,222,105,255},
{"/set39/8",233,47,252,252,205,229,255},
{"/set39/9",0,0,217,217,217,217,255},
{"/spectral10/1",237,253,158,158,1,66,255},
{"/spectral10/10",177,130,162,94,79,162,255},
{"/spectral10/2",250,180,213,213,62,79,255},
{"/spectral10/3",10,184,244,244,109,67,255},
{"/spectral10/4",20,157,253,253,174,97,255},
{"/spectral10/5",31,115,254,254,224,139,255},
{"/spectral10/6",49,96,245,230,245,152,255},
{"/spectral10/7",79,65,221,171,221,164,255},
{"/spectral10/8",114,120,194,102,194,165,255},
{"/spectral10/9",143,187,189,50,136,189,255},
{"/spectral11/1",237,253,158,158,1,66,255},
{"/spectral11/10",143,187,189,50,136,189,255},
{"/spectral11/11",177,130,162,94,79,162,255},
{"/spectral11/2",250,180,213,213,62,79,255},
{"/spectral11/3",10,184,244,244,109,67,255},
{"/spectral11/4",20,157,253,253,174,97,255},
{"/spectral11/5",31,115,254,254,224,139,255},
{"/spectral11/6",42,64,255,255,255,191,255},
{"/spectral11/7",49,96,245,230,245,152,255},
{"/spectral11/8",79,65,221,171,221,164,255},
{"/spectral11/9",114,120,194,102,194,165,255},
{"/spectral3/1",13,164,252,252,141,89,255},
{"/spectral3/2",42,64,255,255,255,191,255},
{"/spectral3/3",81,77,213,153,213,148,255},
{"/spectral4/1",254,225,215,215,25,28,255},
{"/spectral4/2",20,157,253,253,174,97,255},
{"/spectral4/3",79,65,221,171,221,164,255},
{"/spectral4/4",143,196,186,43,131,186,255},
{"/spectral5/1",254,225,215,215,25,28,255},
{"/spectral5/2",20,157,253,253,174,97,255},
{"/spectral5/3",42,64,255,255,255,191,255},
{"/spectral5/4",79,65,221,171,221,164,255},
{"/spectral5/5",143,196,186,43,131,186,255},
{"/spectral6/1",250,180,213,213,62,79,255},
{"/spectral6/2",13,164,252,252,141,89,255},
{"/spectral6/3",31,115,254,254,224,139,255},
{"/spectral6/4",49,96,245,230,245,152,255},
{"/spectral6/5",81,77,213,153,213,148,255},
{"/spectral6/6",143,187,189,50,136,189,255},
{"/spectral7/1",250,180,213,213,62,79,255},
{"/spectral7/2",13,164,252,252,141,89,255},
{"/spectral7/3",31,115,254,254,224,139,255},
{"/spectral7/4",42,64,255,255,255,191,255},
{"/spectral7/5",49,96,245,230,245,152,255},
{"/spectral7/6",81,77,213,153,213,148,255},
{"/spectral7/7",143,187,189,50,136,189,255},
{"/spectral8/1",250,180,213,213,62,79,255},
{"/spectral8/2",10,184,244,244,109,67,255},
{"/spectral8/3",20,157,253,253,174,97,255},
{"/spectral8/4",31,115,254,254,224,139,255},
{"/spectral8/5",49,96,245,230,245,152,255},
{"/spectral8/6",79,65,221,171,221,164,255},
{"/spectral8/7",114,120,194,102,194,165,255},
{"/spectral8/8",143,187,189,50,136,189,255},
{"/spectral9/1",250,180,213,213,62,79,255},
{"/spectral9/2",10,184,244,244,109,67,255},
{"/spectral9/3",20,157,253,253,174,97,255},
{"/spectral9/4",31,115,254,254,224,139,255},
{"/spectral9/5",42,64,255,255,255,191,255},
{"/spectral9/6",49,96,245,230,245,152,255},
{"/spectral9/7",79,65,221,171,221,164,255},
{"/spectral9/8",114,120,194,102,194,165,255},
{"/spectral9/9",143,187,189,50,136,189,255},
{"/svg/aliceblue",147,15,255,240,248,255,255},
{"/svg/antiquewhite",24,35,250,250,235,215,255},
{"/svg/aqua",127,255,255,0,255,255,255},
{"/svg/aquamarine",113,128,255,127,255,212,255},
{"/svg/azure",127,15,255,240,255,255,255},
{"/svg/beige",42,26,245,245,245,220,255},
{"/svg/bisque",23,58,255,255,228,196,255},
{"/svg/black",0,0,0,0,0,0,255},
{"/svg/blanchedalmond",25,49,255,255,235,205,255},
{"/svg/blue",170,255,255,0,0,255,255},
{"/svg/blueviolet",192,206,226,138,43,226,255},
{"/svg/brown",0,190,165,165,42,42,255},
{"/svg/burlywood",23,99,222,222,184,135,255},
{"/svg/cadetblue",128,103,160,95,158,160,255},
{"/svg/chartreuse",63,255,255,127,255,0,255},
{"/svg/chocolate",17,218,210,210,105,30,255},
{"/svg/coral",11,175,255,255,127,80,255},
{"/svg/cornflowerblue",154,147,237,100,149,237,255},
{"/svg/cornsilk",33,34,255,255,248,220,255},
{"/svg/crimson",246,231,220,220,20,60,255},
{"/svg/cyan",127,255,255,0,255,255,255},
{"/svg/darkblue",170,255,139,0,0,139,255},
{"/svg/darkcyan",127,255,139,0,139,139,255},
{"/svg/darkgoldenrod",30,239,184,184,134,11,255},
{"/svg/darkgray",0,0,169,169,169,169,255},
{"/svg/darkgreen",85,255,100,0,100,0,255},
{"/svg/darkgrey",0,0,169,169,169,169,255},
{"/svg/darkkhaki",39,110,189,189,183,107,255},
{"/svg/darkmagenta",212,255,139,139,0,139,255},
{"/svg/darkolivegreen",58,142,107,85,107,47,255},
{"/svg/darkorange",23,255,255,255,140,0,255},
{"/svg/darkorchid",198,192,204,153,50,204,255},
{"/svg/darkred",0,255,139,139,0,0,255},
{"/svg/darksalmon",10,121,233,233,150,122,255},
{"/svg/darkseagreen",85,61,188,143,188,143,255},
{"/svg/darkslateblue",175,143,139,72,61,139,255},
{"/svg/darkslategray",127,103,79,47,79,79,255},
{"/svg/darkslategrey",127,103,79,47,79,79,255},
{"/svg/darkturquoise",128,255,209,0,206,209,255},
{"/svg/darkviolet",199,255,211,148,0,211,255},
{"/svg/deeppink",232,235,255,255,20,147,255},
{"/svg/deepskyblue",138,255,255,0,191,255,255},
{"/svg/dimgray",0,0,105,105,105,105,255},
{"/svg/dimgrey",0,0,105,105,105,105,255},
{"/svg/dodgerblue",148,225,255,30,144,255,255},
{"/svg/firebrick",0,206,178,178,34,34,255},
{"/svg/floralwhite",28,15,255,255,250,240,255},
{"/svg/forestgreen",85,192,139,34,139,34,255},
{"/svg/fuchsia",212,255,255,255,0,255,255},
{"/svg/gainsboro",0,0,220,220,220,220,255},
{"/svg/ghostwhite",170,7,255,248,248,255,255},
{"/svg/gold",35,255,255,255,215,0,255},
{"/svg/goldenrod",30,217,218,218,165,32,255},
{"/svg/gray",0,0,128,128,128,128,255},
{"/svg/green",85,255,128,0,128,0,255},
{"/svg/greenyellow",59,208,255,173,255,47,255},
{"/svg/grey",0,0,128,128,128,128,255},
{"/svg/honeydew",85,15,255,240,255,240,255},
{"/svg/hotpink",233,150,255,255,105,180,255},
{"/svg/indianred",0,140,205,205,92,92,255},
{"/svg/indigo",194,255,130,75,0,130,255},
{"/svg/ivory",42,15,255,255,255,240,255},
{"/svg/khaki",38,106,240,240,230,140,255},
{"/svg/lavender",170,20,250,230,230,250,255},
{"/svg/lavenderblush",240,15,255,255,240,245,255},
{"/svg/lawngreen",64,255,252,124,252,0,255},
{"/svg/lemonchiffon",38,49,255,255,250,205,255},
{"/svg/lightblue",137,63,230,173,216,230,255},
{"/svg/lightcoral",0,119,240,240,128,128,255},
{"/svg/lightcyan",127,31,255,224,255,255,255},
{"/svg/lightgoldenrodyellow",42,40,250,250,250,210,255},
{"/svg/lightgray",0,0,211,211,211,211,255},
{"/svg/lightgreen",85,100,238,144,238,144,255},
{"/svg/lightgrey",0,0,211,211,211,211,255},
{"/svg/lightpink",248,73,255,255,182,193,255},
{"/svg/lightsalmon",12,132,255,255,160,122,255},
{"/svg/lightseagreen",125,209,178,32,178,170,255},
{"/svg/lightskyblue",143,117,250,135,206,250,255},
{"/svg/lightslategray",148,56,153,119,136,153,255},
{"/svg/lightslategrey",148,56,153,119,136,153,255},
{"/svg/lightsteelblue",151,52,222,176,196,222,255},
{"/svg/lightyellow",42,31,255,255,255,224,255},
{"/svg/lime",85,255,255,0,255,0,255},
{"/svg/limegreen",85,192,205,50,205,50,255},
{"/svg/linen",21,20,250,250,240,230,255},
{"/svg/magenta",212,255,255,255,0,255,255},
{"/svg/maroon",0,255,128,128,0,0,255},
{"/svg/mediumaquamarine",113,128,205,102,205,170,255},
{"/svg/mediumblue",170,255,205,0,0,205,255},
{"/svg/mediumorchid",204,152,211,186,85,211,255},
{"/svg/mediumpurple",183,124,219,147,112,219,255},
{"/svg/mediumseagreen",103,169,179,60,179,113,255},
{"/svg/mediumslateblue",176,143,238,123,104,238,255},
{"/svg/mediumspringgreen",111,255,250,0,250,154,255},
{"/svg/mediumturquoise",125,167,209,72,209,204,255},
{"/svg/mediumvioletred",228,228,199,199,21,133,255},
{"/svg/midnightblue",170,198,112,25,25,112,255},
{"/svg/mintcream",106,9,255,245,255,250,255},
{"/svg/mistyrose",4,30,255,255,228,225,255},
{"/svg/moccasin",26,73,255,255,228,181,255},
{"/svg/navajowhite",25,81,255,255,222,173,255},
{"/svg/navy",170,255,128,0,0,128,255},
{"/svg/oldlace",27,23,253,253,245,230,255},
{"/svg/olive",42,255,128,128,128,0,255},
{"/svg/olivedrab",56,192,142,107,142,35,255},
{"/svg/orange",27,255,255,255,165,0,255},
{"/svg/orangered",11,255,255,255,69,0,255},
{"/svg/orchid",214,123,218,218,112,214,255},
{"/svg/palegoldenrod",38,72,238,238,232,170,255},
{"/svg/palegreen",85,100,251,152,251,152,255},
{"/svg/paleturquoise",127,67,238,175,238,238,255},
{"/svg/palevioletred",241,124,219,219,112,147,255},
{"/svg/papayawhip",26,41,255,255,239,213,255},
{"/svg/peachpuff",20,70,255,255,218,185,255},
{"/svg/peru",20,176,205,205,133,63,255},
{"/svg/pink",247,63,255,255,192,203,255},
{"/svg/plum",212,70,221,221,160,221,255},
{"/svg/powderblue",132,59,230,176,224,230,255},
{"/svg/purple",212,255,128,128,0,128,255},
{"/svg/red",0,255,255,255,0,0,255},
{"/svg/rosybrown",0,61,188,188,143,143,255},
{"/svg/royalblue",159,181,225,65,105,225,255},
{"/svg/saddlebrown",17,220,139,139,69,19,255},
{"/svg/salmon",4,138,250,250,128,114,255},
{"/svg/sandybrown",19,154,244,244,164,96,255},
{"/svg/seagreen",103,170,139,46,139,87,255},
{"/svg/seashell",17,16,255,255,245,238,255},
{"/svg/sienna",13,183,160,160,82,45,255},
{"/svg/silver",0,0,192,192,192,192,255},
{"/svg/skyblue",139,108,235,135,206,235,255},
{"/svg/slateblue",175,143,205,106,90,205,255},
{"/svg/slategray",148,56,144,112,128,144,255},
{"/svg/slategrey",148,56,144,112,128,144,255},
{"/svg/snow",0,5,255,255,250,250,255},
{"/svg/springgreen",106,255,255,0,255,127,255},
{"/svg/steelblue",146,155,180,70,130,180,255},
{"/svg/tan",24,84,210,210,180,140,255},
{"/svg/teal",127,255,128,0,128,128,255},
{"/svg/thistle",212,29,216,216,191,216,255},
{"/svg/tomato",6,184,255,255,99,71,255},
{"/svg/turquoise",123,182,224,64,224,208,255},
{"/svg/violet",212,115,238,238,130,238,255},
{"/svg/wheat",27,68,245,245,222,179,255},
{"/svg/white",0,0,255,255,255,255,255},
{"/svg/whitesmoke",0,0,245,245,245,245,255},
{"/svg/yellow",42,255,255,255,255,0,255},
{"/svg/yellowgreen",56,192,205,154,205,50,255},
{"/ylgn3/1",45,67,252,247,252,185,255},
{"/ylgn3/2",68,91,221,173,221,142,255},
{"/ylgn3/3",98,178,163,49,163,84,255},
{"/ylgn4/1",42,50,255,255,255,204,255},
{"/ylgn4/2",62,85,230,194,230,153,255},
{"/ylgn4/3",85,100,198,120,198,121,255},
{"/ylgn4/4",99,187,132,35,132,67,255},
{"/ylgn5/1",42,50,255,255,255,204,255},
{"/ylgn5/2",62,85,230,194,230,153,255},
{"/ylgn5/3",85,100,198,120,198,121,255},
{"/ylgn5/4",98,178,163,49,163,84,255},
{"/ylgn5/5",107,255,104,0,104,55,255},
{"/ylgn6/1",42,50,255,255,255,204,255},
{"/ylgn6/2",55,81,240,217,240,163,255},
{"/ylgn6/3",68,91,221,173,221,142,255},
{"/ylgn6/4",85,100,198,120,198,121,255},
{"/ylgn6/5",98,178,163,49,163,84,255},
{"/ylgn6/6",107,255,104,0,104,55,255},
{"/ylgn7/1",42,50,255,255,255,204,255},
{"/ylgn7/2",55,81,240,217,240,163,255},
{"/ylgn7/3",68,91,221,173,221,142,255},
{"/ylgn7/4",85,100,198,120,198,121,255},
{"/ylgn7/5",96,158,171,65,171,93,255},
{"/ylgn7/6",99,187,132,35,132,67,255},
{"/ylgn7/7",108,255,90,0,90,50,255},
{"/ylgn8/1",42,25,255,255,255,229,255},
{"/ylgn8/2",45,67,252,247,252,185,255},
{"/ylgn8/3",55,81,240,217,240,163,255},
{"/ylgn8/4",68,91,221,173,221,142,255},
{"/ylgn8/5",85,100,198,120,198,121,255},
{"/ylgn8/6",96,158,171,65,171,93,255},
{"/ylgn8/7",99,187,132,35,132,67,255},
{"/ylgn8/8",108,255,90,0,90,50,255},
{"/ylgn9/1",42,25,255,255,255,229,255},
{"/ylgn9/2",45,67,252,247,252,185,255},
{"/ylgn9/3",55,81,240,217,240,163,255},
{"/ylgn9/4",68,91,221,173,221,142,255},
{"/ylgn9/5",85,100,198,120,198,121,255},
{"/ylgn9/6",96,158,171,65,171,93,255},
{"/ylgn9/7",99,187,132,35,132,67,255},
{"/ylgn9/8",107,255,104,0,104,55,255},
{"/ylgn9/9",110,255,69,0,69,41,255},
{"/ylgnbu3/1",49,73,248,237,248,177,255},
{"/ylgnbu3/2",117,97,205,127,205,187,255},
{"/ylgnbu3/3",144,194,184,44,127,184,255},
{"/ylgnbu4/1",42,50,255,255,255,204,255},
{"/ylgnbu4/2",99,66,218,161,218,180,255},
{"/ylgnbu4/3",132,170,196,65,182,196,255},
{"/ylgnbu4/4",150,203,168,34,94,168,255},
{"/ylgnbu5/1",42,50,255,255,255,204,255},
{"/ylgnbu5/2",99,66,218,161,218,180,255},
{"/ylgnbu5/3",132,170,196,65,182,196,255},
{"/ylgnbu5/4",144,194,184,44,127,184,255},
{"/ylgnbu5/5",164,191,148,37,52,148,255},
{"/ylgnbu6/1",42,50,255,255,255,204,255},
{"/ylgnbu6/2",69,58,233,199,233,180,255},
{"/ylgnbu6/3",117,97,205,127,205,187,255},
{"/ylgnbu6/4",132,170,196,65,182,196,255},
{"/ylgnbu6/5",144,194,184,44,127,184,255},
{"/ylgnbu6/6",164,191,148,37,52,148,255},
{"/ylgnbu7/1",42,50,255,255,255,204,255},
{"/ylgnbu7/2",69,58,233,199,233,180,255},
{"/ylgnbu7/3",117,97,205,127,205,187,255},
{"/ylgnbu7/4",132,170,196,65,182,196,255},
{"/ylgnbu7/5",139,216,192,29,145,192,255},
{"/ylgnbu7/6",150,203,168,34,94,168,255},
{"/ylgnbu7/7",158,231,132,12,44,132,255},
{"/ylgnbu8/1",42,38,255,255,255,217,255},
{"/ylgnbu8/2",49,73,248,237,248,177,255},
{"/ylgnbu8/3",69,58,233,199,233,180,255},
{"/ylgnbu8/4",117,97,205,127,205,187,255},
{"/ylgnbu8/5",132,170,196,65,182,196,255},
{"/ylgnbu8/6",139,216,192,29,145,192,255},
{"/ylgnbu8/7",150,203,168,34,94,168,255},
{"/ylgnbu8/8",158,231,132,12,44,132,255},
{"/ylgnbu9/1",42,38,255,255,255,217,255},
{"/ylgnbu9/2",49,73,248,237,248,177,255},
{"/ylgnbu9/3",69,58,233,199,233,180,255},
{"/ylgnbu9/4",117,97,205,127,205,187,255},
{"/ylgnbu9/5",132,170,196,65,182,196,255},
{"/ylgnbu9/6",139,216,192,29,145,192,255},
{"/ylgnbu9/7",150,203,168,34,94,168,255},
{"/ylgnbu9/8",164,191,148,37,52,148,255},
{"/ylgnbu9/9",158,231,88,8,29,88,255},
{"/ylorbr3/1",37,66,255,255,247,188,255},
{"/ylorbr3/2",28,175,254,254,196,79,255},
{"/ylorbr3/3",16,238,217,217,95,14,255},
{"/ylorbr4/1",42,42,255,255,255,212,255},
{"/ylorbr4/2",28,112,254,254,217,142,255},
{"/ylorbr4/3",22,213,254,254,153,41,255},
{"/ylorbr4/4",15,252,204,204,76,2,255},
{"/ylorbr5/1",42,42,255,255,255,212,255},
{"/ylorbr5/2",28,112,254,254,217,142,255},
{"/ylorbr5/3",22,213,254,254,153,41,255},
{"/ylorbr5/4",16,238,217,217,95,14,255},
{"/ylorbr5/5",13,248,153,153,52,4,255},
{"/ylorbr6/1",42,42,255,255,255,212,255},
{"/ylorbr6/2",31,109,254,254,227,145,255},
{"/ylorbr6/3",28,175,254,254,196,79,255},
{"/ylorbr6/4",22,213,254,254,153,41,255},
{"/ylorbr6/5",16,238,217,217,95,14,255},
{"/ylorbr6/6",13,248,153,153,52,4,255},
{"/ylorbr7/1",42,42,255,255,255,212,255},
{"/ylorbr7/2",31,109,254,254,227,145,255},
{"/ylorbr7/3",28,175,254,254,196,79,255},
{"/ylorbr7/4",22,213,254,254,153,41,255},
{"/ylorbr7/5",18,233,236,236,112,20,255},
{"/ylorbr7/6",15,252,204,204,76,2,255},
{"/ylorbr7/7",12,247,140,140,45,4,255},
{"/ylorbr8/1",42,25,255,255,255,229,255},
{"/ylorbr8/2",37,66,255,255,247,188,255},
{"/ylorbr8/3",31,109,254,254,227,145,255},
{"/ylorbr8/4",28,175,254,254,196,79,255},
{"/ylorbr8/5",22,213,254,254,153,41,255},
{"/ylorbr8/6",18,233,236,236,112,20,255},
{"/ylorbr8/7",15,252,204,204,76,2,255},
{"/ylorbr8/8",12,247,140,140,45,4,255},
{"/ylorbr9/1",42,25,255,255,255,229,255},
{"/ylorbr9/2",37,66,255,255,247,188,255},
{"/ylorbr9/3",31,109,254,254,227,145,255},
{"/ylorbr9/4",28,175,254,254,196,79,255},
{"/ylorbr9/5",22,213,254,254,153,41,255},
{"/ylorbr9/6",18,233,236,236,112,20,255},
{"/ylorbr9/7",15,252,204,204,76,2,255},
{"/ylorbr9/8",13,248,153,153,52,4,255},
{"/ylorbr9/9",13,240,102,102,37,6,255},
{"/ylorrd3/1",34,95,255,255,237,160,255},
{"/ylorrd3/2",24,178,254,254,178,76,255},
{"/ylorrd3/3",5,221,240,240,59,32,255},
{"/ylorrd4/1",42,77,255,255,255,178,255},
{"/ylorrd4/2",29,162,254,254,204,92,255},
{"/ylorrd4/3",17,194,253,253,141,60,255},
{"/ylorrd4/4",254,225,227,227,26,28,255},
{"/ylorrd5/1",42,77,255,255,255,178,255},
{"/ylorrd5/2",29,162,254,254,204,92,255},
{"/ylorrd5/3",17,194,253,253,141,60,255},
{"/ylorrd5/4",5,221,240,240,59,32,255},
{"/ylorrd5/5",246,255,189,189,0,38,255},
{"/ylorrd6/1",42,77,255,255,255,178,255},
{"/ylorrd6/2",30,136,254,254,217,118,255},
{"/ylorrd6/3",24,178,254,254,178,76,255},
{"/ylorrd6/4",17,194,253,253,141,60,255},
{"/ylorrd6/5",5,221,240,240,59,32,255},
{"/ylorrd6/6",246,255,189,189,0,38,255},
{"/ylorrd7/1",42,77,255,255,255,178,255},
{"/ylorrd7/2",30,136,254,254,217,118,255},
{"/ylorrd7/3",24,178,254,254,178,76,255},
{"/ylorrd7/4",17,194,253,253,141,60,255},
{"/ylorrd7/5",7,212,252,252,78,42,255},
{"/ylorrd7/6",254,225,227,227,26,28,255},
{"/ylorrd7/7",245,255,177,177,0,38,255},
{"/ylorrd8/1",42,50,255,255,255,204,255},
{"/ylorrd8/2",34,95,255,255,237,160,255},
{"/ylorrd8/3",30,136,254,254,217,118,255},
{"/ylorrd8/4",24,178,254,254,178,76,255},
{"/ylorrd8/5",17,194,253,253,141,60,255},
{"/ylorrd8/6",7,212,252,252,78,42,255},
{"/ylorrd8/7",254,225,227,227,26,28,255},
{"/ylorrd8/8",245,255,177,177,0,38,255},
{"/ylorrd9/1",42,50,255,255,255,204,255},
{"/ylorrd9/2",34,95,255,255,237,160,255},
{"/ylorrd9/3",30,136,254,254,217,118,255},
{"/ylorrd9/4",24,178,254,254,178,76,255},
{"/ylorrd9/5",17,194,253,253,141,60,255},
{"/ylorrd9/6",7,212,252,252,78,42,255},
{"/ylorrd9/7",254,225,227,227,26,28,255},
{"/ylorrd9/8",246,255,189,189,0,38,255},
{"/ylorrd9/9",242,255,128,128,0,38,255},
{"aliceblue",147,15,255,240,248,255,255},
{"antiquewhite",24,35,250,250,235,215,255},
{"antiquewhite1",23,36,255,255,239,219,255},
{"antiquewhite2",23,36,238,238,223,204,255},
{"antiquewhite3",23,36,205,205,192,176,255},
{"antiquewhite4",24,34,139,139,131,120,255},
{"aquamarine",113,128,255,127,255,212,255},
{"aquamarine1",113,128,255,127,255,212,255},
{"aquamarine2",113,128,238,118,238,198,255},
{"aquamarine3",113,128,205,102,205,170,255},
{"aquamarine4",113,128,139,69,139,116,255},
{"azure",127,15,255,240,255,255,255},
{"azure1",127,15,255,240,255,255,255},
{"azure2",127,15,238,224,238,238,255},
{"azure3",127,14,205,193,205,205,255},
{"azure4",127,14,139,131,139,139,255},
{"beige",42,26,245,245,245,220,255},
{"bisque",23,58,255,255,228,196,255},
{"bisque1",23,58,255,255,228,196,255},
{"bisque2",23,58,238,238,213,183,255},
{"bisque3",22,58,205,205,183,158,255},
{"bisque4",23,58,139,139,125,107,255},
{"black",0,0,0,0,0,0,255},
{"blanchedalmond",25,49,255,255,235,205,255},
{"blue",170,255,255,0,0,255,255},
{"blue1",170,255,255,0,0,255,255},
{"blue2",170,255,238,0,0,238,255},
{"blue3",170,255,205,0,0,205,255},
{"blue4",170,255,139,0,0,139,255},
{"blueviolet",192,206,226,138,43,226,255},
{"brown",0,190,165,165,42,42,255},
{"brown1",0,191,255,255,64,64,255},
{"brown2",0,191,238,238,59,59,255},
{"brown3",0,191,205,205,51,51,255},
{"brown4",0,190,139,139,35,35,255},
{"burlywood",23,99,222,222,184,135,255},
{"burlywood1",23,100,255,255,211,155,255},
{"burlywood2",23,99,238,238,197,145,255},
{"burlywood3",23,99,205,205,170,125,255},
{"burlywood4",23,99,139,139,115,85,255},
{"cadetblue",128,103,160,95,158,160,255},
{"cadetblue1",131,103,255,152,245,255,255},
{"cadetblue2",131,102,238,142,229,238,255},
{"cadetblue3",131,103,205,122,197,205,255},
{"cadetblue4",131,102,139,83,134,139,255},
{"chartreuse",63,255,255,127,255,0,255},
{"chartreuse1",63,255,255,127,255,0,255},
{"chartreuse2",63,255,238,118,238,0,255},
{"chartreuse3",63,255,205,102,205,0,255},
{"chartreuse4",63,255,139,69,139,0,255},
{"chocolate",17,218,210,210,105,30,255},
{"chocolate1",17,219,255,255,127,36,255},
{"chocolate2",17,219,238,238,118,33,255},
{"chocolate3",17,218,205,205,102,29,255},
{"chocolate4",17,220,139,139,69,19,255},
{"coral",11,175,255,255,127,80,255},
{"coral1",7,169,255,255,114,86,255},
{"coral2",6,169,238,238,106,80,255},
{"coral3",6,169,205,205,91,69,255},
{"coral4",6,168,139,139,62,47,255},
{"cornflowerblue",154,147,237,100,149,237,255},
{"cornsilk",33,34,255,255,248,220,255},
{"cornsilk1",33,34,255,255,248,220,255},
{"cornsilk2",34,35,238,238,232,205,255},
{"cornsilk3",34,34,205,205,200,177,255},
{"cornsilk4",35,34,139,139,136,120,255},
{"crimson",246,231,220,220,20,60,255},
{"cyan",127,255,255,0,255,255,255},
{"cyan1",127,255,255,0,255,255,255},
{"cyan2",127,255,238,0,238,238,255},
{"cyan3",127,255,205,0,205,205,255},
{"cyan4",127,255,139,0,139,139,255},
{"darkgoldenrod",30,239,184,184,134,11,255},
{"darkgoldenrod1",30,240,255,255,185,15,255},
{"darkgoldenrod2",30,240,238,238,173,14,255},
{"darkgoldenrod3",30,240,205,205,149,12,255},
{"darkgoldenrod4",30,240,139,139,101,8,255},
{"darkgreen",85,255,100,0,100,0,255},
{"darkkhaki",39,110,189,189,183,107,255},
{"darkolivegreen",58,142,107,85,107,47,255},
{"darkolivegreen1",58,143,255,202,255,112,255},
{"darkolivegreen2",58,143,238,188,238,104,255},
{"darkolivegreen3",58,143,205,162,205,90,255},
{"darkolivegreen4",58,143,139,110,139,61,255},
{"darkorange",23,255,255,255,140,0,255},
{"darkorange1",21,255,255,255,127,0,255},
{"darkorange2",21,255,238,238,118,0,255},
{"darkorange3",21,255,205,205,102,0,255},
{"darkorange4",21,255,139,139,69,0,255},
{"darkorchid",198,192,204,153,50,204,255},
{"darkorchid1",198,193,255,191,62,255,255},
{"darkorchid2",198,192,238,178,58,238,255},
{"darkorchid3",198,192,205,154,50,205,255},
{"darkorchid4",198,192,139,104,34,139,255},
{"darksalmon",10,121,233,233,150,122,255},
{"darkseagreen",85,61,188,143,188,143,255},
{"darkseagreen1",85,62,255,193,255,193,255},
{"darkseagreen2",85,62,238,180,238,180,255},
{"darkseagreen3",85,62,205,155,205,155,255},
{"darkseagreen4",85,62,139,105,139,105,255},
{"darkslateblue",175,143,139,72,61,139,255},
{"darkslategray",127,103,79,47,79,79,255},
{"darkslategray1",127,104,255,151,255,255,255},
{"darkslategray2",127,103,238,141,238,238,255},
{"darkslategray3",127,104,205,121,205,205,255},
{"darkslategray4",127,104,139,82,139,139,255},
{"darkslategrey",127,103,79,47,79,79,255},
{"darkturquoise",128,255,209,0,206,209,255},
{"darkviolet",199,255,211,148,0,211,255},
{"deeppink",232,235,255,255,20,147,255},
{"deeppink1",232,235,255,255,20,147,255},
{"deeppink2",232,235,238,238,18,137,255},
{"deeppink3",232,235,205,205,16,118,255},
{"deeppink4",231,236,139,139,10,80,255},
{"deepskyblue",138,255,255,0,191,255,255},
{"deepskyblue1",138,255,255,0,191,255,255},
{"deepskyblue2",138,255,238,0,178,238,255},
{"deepskyblue3",138,255,205,0,154,205,255},
{"deepskyblue4",138,255,139,0,104,139,255},
{"dimgray",0,0,105,105,105,105,255},
{"dimgrey",0,0,105,105,105,105,255},
{"dodgerblue",148,225,255,30,144,255,255},
{"dodgerblue1",148,225,255,30,144,255,255},
{"dodgerblue2",148,225,238,28,134,238,255},
{"dodgerblue3",148,225,205,24,116,205,255},
{"dodgerblue4",148,225,139,16,78,139,255},
{"firebrick",0,206,178,178,34,34,255},
{"firebrick1",0,207,255,255,48,48,255},
{"firebrick2",0,207,238,238,44,44,255},
{"firebrick3",0,207,205,205,38,38,255},
{"firebrick4",0,207,139,139,26,26,255},
{"floralwhite",28,15,255,255,250,240,255},
{"forestgreen",85,192,139,34,139,34,255},
{"gainsboro",0,0,220,220,220,220,255},
{"ghostwhite",170,7,255,248,248,255,255},
{"gold",35,255,255,255,215,0,255},
{"gold1",35,255,255,255,215,0,255},
{"gold2",35,255,238,238,201,0,255},
{"gold3",35,255,205,205,173,0,255},
{"gold4",35,255,139,139,117,0,255},
{"goldenrod",30,217,218,218,165,32,255},
{"goldenrod1",30,218,255,255,193,37,255},
{"goldenrod2",30,218,238,238,180,34,255},
{"goldenrod3",30,218,205,205,155,29,255},
{"goldenrod4",30,218,139,139,105,20,255},
{"gray",0,0,192,192,192,192,255},
{"gray0",0,0,0,0,0,0,255},
{"gray1",0,0,3,3,3,3,255},
{"gray10",0,0,26,26,26,26,255},
{"gray100",0,0,255,255,255,255,255},
{"gray11",0,0,28,28,28,28,255},
{"gray12",0,0,31,31,31,31,255},
{"gray13",0,0,33,33,33,33,255},
{"gray14",0,0,36,36,36,36,255},
{"gray15",0,0,38,38,38,38,255},
{"gray16",0,0,41,41,41,41,255},
{"gray17",0,0,43,43,43,43,255},
{"gray18",0,0,46,46,46,46,255},
{"gray19",0,0,48,48,48,48,255},
{"gray2",0,0,5,5,5,5,255},
{"gray20",0,0,51,51,51,51,255},
{"gray21",0,0,54,54,54,54,255},
{"gray22",0,0,56,56,56,56,255},
{"gray23",0,0,59,59,59,59,255},
{"gray24",0,0,61,61,61,61,255},
{"gray25",0,0,64,64,64,64,255},
{"gray26",0,0,66,66,66,66,255},
{"gray27",0,0,69,69,69,69,255},
{"gray28",0,0,71,71,71,71,255},
{"gray29",0,0,74,74,74,74,255},
{"gray3",0,0,8,8,8,8,255},
{"gray30",0,0,77,77,77,77,255},
{"gray31",0,0,79,79,79,79,255},
{"gray32",0,0,82,82,82,82,255},
{"gray33",0,0,84,84,84,84,255},
{"gray34",0,0,87,87,87,87,255},
{"gray35",0,0,89,89,89,89,255},
{"gray36",0,0,92,92,92,92,255},
{"gray37",0,0,94,94,94,94,255},
{"gray38",0,0,97,97,97,97,255},
{"gray39",0,0,99,99,99,99,255},
{"gray4",0,0,10,10,10,10,255},
{"gray40",0,0,102,102,102,102,255},
{"gray41",0,0,105,105,105,105,255},
{"gray42",0,0,107,107,107,107,255},
{"gray43",0,0,110,110,110,110,255},
{"gray44",0,0,112,112,112,112,255},
{"gray45",0,0,115,115,115,115,255},
{"gray46",0,0,117,117,117,117,255},
{"gray47",0,0,120,120,120,120,255},
{"gray48",0,0,122,122,122,122,255},
{"gray49",0,0,125,125,125,125,255},
{"gray5",0,0,13,13,13,13,255},
{"gray50",0,0,127,127,127,127,255},
{"gray51",0,0,130,130,130,130,255},
{"gray52",0,0,133,133,133,133,255},
{"gray53",0,0,135,135,135,135,255},
{"gray54",0,0,138,138,138,138,255},
{"gray55",0,0,140,140,140,140,255},
{"gray56",0,0,143,143,143,143,255},
{"gray57",0,0,145,145,145,145,255},
{"gray58",0,0,148,148,148,148,255},
{"gray59",0,0,150,150,150,150,255},
{"gray6",0,0,15,15,15,15,255},
{"gray60",0,0,153,153,153,153,255},
{"gray61",0,0,156,156,156,156,255},
{"gray62",0,0,158,158,158,158,255},
{"gray63",0,0,161,161,161,161,255},
{"gray64",0,0,163,163,163,163,255},
{"gray65",0,0,166,166,166,166,255},
{"gray66",0,0,168,168,168,168,255},
{"gray67",0,0,171,171,171,171,255},
{"gray68",0,0,173,173,173,173,255},
{"gray69",0,0,176,176,176,176,255},
{"gray7",0,0,18,18,18,18,255},
{"gray70",0,0,179,179,179,179,255},
{"gray71",0,0,181,181,181,181,255},
{"gray72",0,0,184,184,184,184,255},
{"gray73",0,0,186,186,186,186,255},
{"gray74",0,0,189,189,189,189,255},
{"gray75",0,0,191,191,191,191,255},
{"gray76",0,0,194,194,194,194,255},
{"gray77",0,0,196,196,196,196,255},
{"gray78",0,0,199,199,199,199,255},
{"gray79",0,0,201,201,201,201,255},
{"gray8",0,0,20,20,20,20,255},
{"gray80",0,0,204,204,204,204,255},
{"gray81",0,0,207,207,207,207,255},
{"gray82",0,0,209,209,209,209,255},
{"gray83",0,0,212,212,212,212,255},
{"gray84",0,0,214,214,214,214,255},
{"gray85",0,0,217,217,217,217,255},
{"gray86",0,0,219,219,219,219,255},
{"gray87",0,0,222,222,222,222,255},
{"gray88",0,0,224,224,224,224,255},
{"gray89",0,0,227,227,227,227,255},
{"gray9",0,0,23,23,23,23,255},
{"gray90",0,0,229,229,229,229,255},
{"gray91",0,0,232,232,232,232,255},
{"gray92",0,0,235,235,235,235,255},
{"gray93",0,0,237,237,237,237,255},
{"gray94",0,0,240,240,240,240,255},
{"gray95",0,0,242,242,242,242,255},
{"gray96",0,0,245,245,245,245,255},
{"gray97",0,0,247,247,247,247,255},
{"gray98",0,0,250,250,250,250,255},
{"gray99",0,0,252,252,252,252,255},
{"green",85,255,255,0,255,0,255},
{"green1",85,255,255,0,255,0,255},
{"green2",85,255,238,0,238,0,255},
{"green3",85,255,205,0,205,0,255},
{"green4",85,255,139,0,139,0,255},
{"greenyellow",59,208,255,173,255,47,255},
{"grey",0,0,192,192,192,192,255},
{"grey0",0,0,0,0,0,0,255},
{"grey1",0,0,3,3,3,3,255},
{"grey10",0,0,26,26,26,26,255},
{"grey100",0,0,255,255,255,255,255},
{"grey11",0,0,28,28,28,28,255},
{"grey12",0,0,31,31,31,31,255},
{"grey13",0,0,33,33,33,33,255},
{"grey14",0,0,36,36,36,36,255},
{"grey15",0,0,38,38,38,38,255},
{"grey16",0,0,41,41,41,41,255},
{"grey17",0,0,43,43,43,43,255},
{"grey18",0,0,46,46,46,46,255},
{"grey19",0,0,48,48,48,48,255},
{"grey2",0,0,5,5,5,5,255},
{"grey20",0,0,51,51,51,51,255},
{"grey21",0,0,54,54,54,54,255},
{"grey22",0,0,56,56,56,56,255},
{"grey23",0,0,59,59,59,59,255},
{"grey24",0,0,61,61,61,61,255},
{"grey25",0,0,64,64,64,64,255},
{"grey26",0,0,66,66,66,66,255},
{"grey27",0,0,69,69,69,69,255},
{"grey28",0,0,71,71,71,71,255},
{"grey29",0,0,74,74,74,74,255},
{"grey3",0,0,8,8,8,8,255},
{"grey30",0,0,77,77,77,77,255},
{"grey31",0,0,79,79,79,79,255},
{"grey32",0,0,82,82,82,82,255},
{"grey33",0,0,84,84,84,84,255},
{"grey34",0,0,87,87,87,87,255},
{"grey35",0,0,89,89,89,89,255},
{"grey36",0,0,92,92,92,92,255},
{"grey37",0,0,94,94,94,94,255},
{"grey38",0,0,97,97,97,97,255},
{"grey39",0,0,99,99,99,99,255},
{"grey4",0,0,10,10,10,10,255},
{"grey40",0,0,102,102,102,102,255},
{"grey41",0,0,105,105,105,105,255},
{"grey42",0,0,107,107,107,107,255},
{"grey43",0,0,110,110,110,110,255},
{"grey44",0,0,112,112,112,112,255},
{"grey45",0,0,115,115,115,115,255},
{"grey46",0,0,117,117,117,117,255},
{"grey47",0,0,120,120,120,120,255},
{"grey48",0,0,122,122,122,122,255},
{"grey49",0,0,125,125,125,125,255},
{"grey5",0,0,13,13,13,13,255},
{"grey50",0,0,127,127,127,127,255},
{"grey51",0,0,130,130,130,130,255},
{"grey52",0,0,133,133,133,133,255},
{"grey53",0,0,135,135,135,135,255},
{"grey54",0,0,138,138,138,138,255},
{"grey55",0,0,140,140,140,140,255},
{"grey56",0,0,143,143,143,143,255},
{"grey57",0,0,145,145,145,145,255},
{"grey58",0,0,148,148,148,148,255},
{"grey59",0,0,150,150,150,150,255},
{"grey6",0,0,15,15,15,15,255},
{"grey60",0,0,153,153,153,153,255},
{"grey61",0,0,156,156,156,156,255},
{"grey62",0,0,158,158,158,158,255},
{"grey63",0,0,161,161,161,161,255},
{"grey64",0,0,163,163,163,163,255},
{"grey65",0,0,166,166,166,166,255},
{"grey66",0,0,168,168,168,168,255},
{"grey67",0,0,171,171,171,171,255},
{"grey68",0,0,173,173,173,173,255},
{"grey69",0,0,176,176,176,176,255},
{"grey7",0,0,18,18,18,18,255},
{"grey70",0,0,179,179,179,179,255},
{"grey71",0,0,181,181,181,181,255},
{"grey72",0,0,184,184,184,184,255},
{"grey73",0,0,186,186,186,186,255},
{"grey74",0,0,189,189,189,189,255},
{"grey75",0,0,191,191,191,191,255},
{"grey76",0,0,194,194,194,194,255},
{"grey77",0,0,196,196,196,196,255},
{"grey78",0,0,199,199,199,199,255},
{"grey79",0,0,201,201,201,201,255},
{"grey8",0,0,20,20,20,20,255},
{"grey80",0,0,204,204,204,204,255},
{"grey81",0,0,207,207,207,207,255},
{"grey82",0,0,209,209,209,209,255},
{"grey83",0,0,212,212,212,212,255},
{"grey84",0,0,214,214,214,214,255},
{"grey85",0,0,217,217,217,217,255},
{"grey86",0,0,219,219,219,219,255},
{"grey87",0,0,222,222,222,222,255},
{"grey88",0,0,224,224,224,224,255},
{"grey89",0,0,227,227,227,227,255},
{"grey9",0,0,23,23,23,23,255},
{"grey90",0,0,229,229,229,229,255},
{"grey91",0,0,232,232,232,232,255},
{"grey92",0,0,235,235,235,235,255},
{"grey93",0,0,237,237,237,237,255},
{"grey94",0,0,240,240,240,240,255},
{"grey95",0,0,242,242,242,242,255},
{"grey96",0,0,245,245,245,245,255},
{"grey97",0,0,247,247,247,247,255},
{"grey98",0,0,250,250,250,250,255},
{"grey99",0,0,252,252,252,252,255},
{"honeydew",85,15,255,240,255,240,255},
{"honeydew1",85,15,255,240,255,240,255},
{"honeydew2",85,15,238,224,238,224,255},
{"honeydew3",85,14,205,193,205,193,255},
{"honeydew4",85,14,139,131,139,131,255},
{"hotpink",233,150,255,255,105,180,255},
{"hotpink1",234,145,255,255,110,180,255},
{"hotpink2",235,141,238,238,106,167,255},
{"hotpink3",236,135,205,205,96,144,255},
{"hotpink4",234,148,139,139,58,98,255},
{"indianred",0,140,205,205,92,92,255},
{"indianred1",0,148,255,255,106,106,255},
{"indianred2",0,148,238,238,99,99,255},
{"indianred3",0,149,205,205,85,85,255},
{"indianred4",0,148,139,139,58,58,255},
{"indigo",194,255,130,75,0,130,255},
{"invis",42,0,255,255,255,254,0},
{"ivory",42,15,255,255,255,240,255},
{"ivory1",42,15,255,255,255,240,255},
{"ivory2",42,15,238,238,238,224,255},
{"ivory3",42,14,205,205,205,193,255},
{"ivory4",42,14,139,139,139,131,255},
{"khaki",38,106,240,240,230,140,255},
{"khaki1",39,112,255,255,246,143,255},
{"khaki2",39,112,238,238,230,133,255},
{"khaki3",39,111,205,205,198,115,255},
{"khaki4",39,111,139,139,134,78,255},
{"lavender",170,20,250,230,230,250,255},
{"lavenderblush",240,15,255,255,240,245,255},
{"lavenderblush1",240,15,255,255,240,245,255},
{"lavenderblush2",239,15,238,238,224,229,255},
{"lavenderblush3",240,14,205,205,193,197,255},
{"lavenderblush4",239,14,139,139,131,134,255},
{"lawngreen",64,255,252,124,252,0,255},
{"lemonchiffon",38,49,255,255,250,205,255},
{"lemonchiffon1",38,49,255,255,250,205,255},
{"lemonchiffon2",37,50,238,238,233,191,255},
{"lemonchiffon3",38,49,205,205,201,165,255},
{"lemonchiffon4",39,49,139,139,137,112,255},
{"lightblue",137,63,230,173,216,230,255},
{"lightblue1",138,64,255,191,239,255,255},
{"lightblue2",138,64,238,178,223,238,255},
{"lightblue3",138,63,205,154,192,205,255},
{"lightblue4",137,64,139,104,131,139,255},
{"lightcoral",0,119,240,240,128,128,255},
{"lightcyan",127,31,255,224,255,255,255},
{"lightcyan1",127,31,255,224,255,255,255},
{"lightcyan2",127,31,238,209,238,238,255},
{"lightcyan3",127,31,205,180,205,205,255},
{"lightcyan4",127,31,139,122,139,139,255},
{"lightgoldenrod",35,115,238,238,221,130,255},
{"lightgoldenrod1",35,116,255,255,236,139,255},
{"lightgoldenrod2",35,115,238,238,220,130,255},
{"lightgoldenrod3",35,115,205,205,190,112,255},
{"lightgoldenrod4",35,115,139,139,129,76,255},
{"lightgoldenrodyellow",42,40,250,250,250,210,255},
{"lightgray",0,0,211,211,211,211,255},
{"lightgrey",0,0,211,211,211,211,255},
{"lightpink",248,73,255,255,182,193,255},
{"lightpink1",249,81,255,255,174,185,255},
{"lightpink2",248,81,238,238,162,173,255},
{"lightpink3",249,80,205,205,140,149,255},
{"lightpink4",249,80,139,139,95,101,255},
{"lightsalmon",12,132,255,255,160,122,255},
{"lightsalmon1",12,132,255,255,160,122,255},
{"lightsalmon2",11,132,238,238,149,114,255},
{"lightsalmon3",12,133,205,205,129,98,255},
{"lightsalmon4",12,133,139,139,87,66,255},
{"lightseagreen",125,209,178,32,178,170,255},
{"lightskyblue",143,117,250,135,206,250,255},
{"lightskyblue1",143,79,255,176,226,255,255},
{"lightskyblue2",143,79,238,164,211,238,255},
{"lightskyblue3",142,79,205,141,182,205,255},
{"lightskyblue4",143,78,139,96,123,139,255},
{"lightslateblue",175,143,255,132,112,255,255},
{"lightslategray",148,56,153,119,136,153,255},
{"lightslategrey",148,56,153,119,136,153,255},
{"lightsteelblue",151,52,222,176,196,222,255},
{"lightsteelblue1",151,53,255,202,225,255,255},
{"lightsteelblue2",151,53,238,188,210,238,255},
{"lightsteelblue3",151,53,205,162,181,205,255},
{"lightsteelblue4",150,53,139,110,123,139,255},
{"lightyellow",42,31,255,255,255,224,255},
{"lightyellow1",42,31,255,255,255,224,255},
{"lightyellow2",42,31,238,238,238,209,255},
{"lightyellow3",42,31,205,205,205,180,255},
{"lightyellow4",42,31,139,139,139,122,255},
{"limegreen",85,192,205,50,205,50,255},
{"linen",21,20,250,250,240,230,255},
{"magenta",212,255,255,255,0,255,255},
{"magenta1",212,255,255,255,0,255,255},
{"magenta2",212,255,238,238,0,238,255},
{"magenta3",212,255,205,205,0,205,255},
{"magenta4",212,255,139,139,0,139,255},
{"maroon",239,185,176,176,48,96,255},
{"maroon1",228,203,255,255,52,179,255},
{"maroon2",228,203,238,238,48,167,255},
{"maroon3",228,204,205,205,41,144,255},
{"maroon4",228,203,139,139,28,98,255},
{"mediumaquamarine",113,128,205,102,205,170,255},
{"mediumblue",170,255,205,0,0,205,255},
{"mediumorchid",204,152,211,186,85,211,255},
{"mediumorchid1",203,153,255,224,102,255,255},
{"mediumorchid2",203,153,238,209,95,238,255},
{"mediumorchid3",203,153,205,180,82,205,255},
{"mediumorchid4",203,154,139,122,55,139,255},
{"mediumpurple",183,124,219,147,112,219,255},
{"mediumpurple1",183,125,255,171,130,255,255},
{"mediumpurple2",183,125,238,159,121,238,255},
{"mediumpurple3",183,125,205,137,104,205,255},
{"mediumpurple4",183,124,139,93,71,139,255},
{"mediumseagreen",103,169,179,60,179,113,255},
{"mediumslateblue",176,143,238,123,104,238,255},
{"mediumspringgreen",111,255,250,0,250,154,255},
{"mediumturquoise",125,167,209,72,209,204,255},
{"mediumvioletred",228,228,199,199,21,133,255},
{"midnightblue",170,198,112,25,25,112,255},
{"mintcream",106,9,255,245,255,250,255},
{"mistyrose",4,30,255,255,228,225,255},
{"mistyrose1",4,30,255,255,228,225,255},
{"mistyrose2",4,30,238,238,213,210,255},
{"mistyrose3",3,29,205,205,183,181,255},
{"mistyrose4",5,29,139,139,125,123,255},
{"moccasin",26,73,255,255,228,181,255},
{"navajowhite",25,81,255,255,222,173,255},
{"navajowhite1",25,81,255,255,222,173,255},
{"navajowhite2",25,82,238,238,207,161,255},
{"navajowhite3",25,82,205,205,179,139,255},
{"navajowhite4",25,82,139,139,121,94,255},
{"navy",170,255,128,0,0,128,255},
{"navyblue",170,255,128,0,0,128,255},
{"none",42,0,255,255,255,254,0},
{"oldlace",27,23,253,253,245,230,255},
{"olivedrab",56,192,142,107,142,35,255},
{"olivedrab1",56,193,255,192,255,62,255},
{"olivedrab2",56,192,238,179,238,58,255},
{"olivedrab3",56,192,205,154,205,50,255},
{"olivedrab4",56,192,139,105,139,34,255},
{"orange",27,255,255,255,165,0,255},
{"orange1",27,255,255,255,165,0,255},
{"orange2",27,255,238,238,154,0,255},
{"orange3",27,255,205,205,133,0,255},
{"orange4",27,255,139,139,90,0,255},
{"orangered",11,255,255,255,69,0,255},
{"orangered1",11,255,255,255,69,0,255},
{"orangered2",11,255,238,238,64,0,255},
{"orangered3",11,255,205,205,55,0,255},
{"orangered4",11,255,139,139,37,0,255},
{"orchid",214,123,218,218,112,214,255},
{"orchid1",214,124,255,255,131,250,255},
{"orchid2",214,124,238,238,122,233,255},
{"orchid3",214,124,205,205,105,201,255},
{"orchid4",213,124,139,139,71,137,255},
{"palegoldenrod",38,72,238,238,232,170,255},
{"palegreen",85,100,251,152,251,152,255},
{"palegreen1",85,101,255,154,255,154,255},
{"palegreen2",85,100,238,144,238,144,255},
{"palegreen3",85,100,205,124,205,124,255},
{"palegreen4",85,100,139,84,139,84,255},
{"paleturquoise",127,67,238,175,238,238,255},
{"paleturquoise1",127,68,255,187,255,255,255},
{"paleturquoise2",127,68,238,174,238,238,255},
{"paleturquoise3",127,68,205,150,205,205,255},
{"paleturquoise4",127,67,139,102,139,139,255},
{"palevioletred",241,124,219,219,112,147,255},
{"palevioletred1",241,125,255,255,130,171,255},
{"palevioletred2",241,125,238,238,121,159,255},
{"palevioletred3",241,125,205,205,104,137,255},
{"palevioletred4",241,124,139,139,71,93,255},
{"papayawhip",26,41,255,255,239,213,255},
{"peachpuff",20,70,255,255,218,185,255},
{"peachpuff1",20,70,255,255,218,185,255},
{"peachpuff2",19,69,238,238,203,173,255},
{"peachpuff3",19,69,205,205,175,149,255},
{"peachpuff4",20,69,139,139,119,101,255},
{"peru",20,176,205,205,133,63,255},
{"pink",247,63,255,255,192,203,255},
{"pink1",245,73,255,255,181,197,255},
{"pink2",245,73,238,238,169,184,255},
{"pink3",245,74,205,205,145,158,255},
{"pink4",245,73,139,139,99,108,255},
{"plum",212,70,221,221,160,221,255},
{"plum1",212,68,255,255,187,255,255},
{"plum2",212,68,238,238,174,238,255},
{"plum3",212,68,205,205,150,205,255},
{"plum4",212,67,139,139,102,139,255},
{"powderblue",132,59,230,176,224,230,255},
{"purple",196,221,240,160,32,240,255},
{"purple1",191,207,255,155,48,255,255},
{"purple2",192,207,238,145,44,238,255},
{"purple3",192,207,205,125,38,205,255},
{"purple4",192,207,139,85,26,139,255},
{"red",0,255,255,255,0,0,255},
{"red1",0,255,255,255,0,0,255},
{"red2",0,255,238,238,0,0,255},
{"red3",0,255,205,205,0,0,255},
{"red4",0,255,139,139,0,0,255},
{"rosybrown",0,61,188,188,143,143,255},
{"rosybrown1",0,62,255,255,193,193,255},
{"rosybrown2",0,62,238,238,180,180,255},
{"rosybrown3",0,62,205,205,155,155,255},
{"rosybrown4",0,62,139,139,105,105,255},
{"royalblue",159,181,225,65,105,225,255},
{"royalblue1",159,183,255,72,118,255,255},
{"royalblue2",159,183,238,67,110,238,255},
{"royalblue3",159,182,205,58,95,205,255},
{"royalblue4",159,183,139,39,64,139,255},
{"saddlebrown",17,220,139,139,69,19,255},
{"salmon",4,138,250,250,128,114,255},
{"salmon1",9,150,255,255,140,105,255},
{"salmon2",9,150,238,238,130,98,255},
{"salmon3",9,150,205,205,112,84,255},
{"salmon4",9,150,139,139,76,57,255},
{"sandybrown",19,154,244,244,164,96,255},
{"seagreen",103,170,139,46,139,87,255},
{"seagreen1",103,171,255,84,255,159,255},
{"seagreen2",103,171,238,78,238,148,255},
{"seagreen3",103,171,205,67,205,128,255},
{"seagreen4",103,170,139,46,139,87,255},
{"seashell",17,16,255,255,245,238,255},
{"seashell1",17,16,255,255,245,238,255},
{"seashell2",18,17,238,238,229,222,255},
{"seashell3",18,17,205,205,197,191,255},
{"seashell4",18,16,139,139,134,130,255},
{"sienna",13,183,160,160,82,45,255},
{"sienna1",13,184,255,255,130,71,255},
{"sienna2",13,184,238,238,121,66,255},
{"sienna3",13,184,205,205,104,57,255},
{"sienna4",13,185,139,139,71,38,255},
{"skyblue",139,108,235,135,206,235,255},
{"skyblue1",144,120,255,135,206,255,255},
{"skyblue2",144,120,238,126,192,238,255},
{"skyblue3",144,120,205,108,166,205,255},
{"skyblue4",145,119,139,74,112,139,255},
{"slateblue",175,143,205,106,90,205,255},
{"slateblue1",175,144,255,131,111,255,255},
{"slateblue2",175,144,238,122,103,238,255},
{"slateblue3",175,144,205,105,89,205,255},
{"slateblue4",175,144,139,71,60,139,255},
{"slategray",148,56,144,112,128,144,255},
{"slategray1",149,56,255,198,226,255,255},
{"slategray2",149,56,238,185,211,238,255},
{"slategray3",148,57,205,159,182,205,255},
{"slategray4",149,56,139,108,123,139,255},
{"slategrey",148,56,144,112,128,144,255},
{"snow",0,5,255,255,250,250,255},
{"snow1",0,5,255,255,250,250,255},
{"snow2",0,5,238,238,233,233,255},
{"snow3",0,4,205,205,201,201,255},
{"snow4",0,3,139,139,137,137,255},
{"springgreen",106,255,255,0,255,127,255},
{"springgreen1",106,255,255,0,255,127,255},
{"springgreen2",106,255,238,0,238,118,255},
{"springgreen3",106,255,205,0,205,102,255},
{"springgreen4",106,255,139,0,139,69,255},
{"steelblue",146,155,180,70,130,180,255},
{"steelblue1",146,156,255,99,184,255,255},
{"steelblue2",146,156,238,92,172,238,255},
{"steelblue3",146,156,205,79,148,205,255},
{"steelblue4",147,155,139,54,100,139,255},
{"tan",24,84,210,210,180,140,255},
{"tan1",20,176,255,255,165,79,255},
{"tan2",20,176,238,238,154,73,255},
{"tan3",20,176,205,205,133,63,255},
{"tan4",20,176,139,139,90,43,255},
{"thistle",212,29,216,216,191,216,255},
{"thistle1",212,30,255,255,225,255,255},
{"thistle2",212,30,238,238,210,238,255},
{"thistle3",212,29,205,205,181,205,255},
{"thistle4",212,29,139,139,123,139,255},
{"tomato",6,184,255,255,99,71,255},
{"tomato1",6,184,255,255,99,71,255},
{"tomato2",6,184,238,238,92,66,255},
{"tomato3",6,184,205,205,79,57,255},
{"tomato4",6,185,139,139,54,38,255},
{"transparent",42,0,255,255,255,254,0},
{"turquoise",123,182,224,64,224,208,255},
{"turquoise1",129,255,255,0,245,255,255},
{"turquoise2",129,255,238,0,229,238,255},
{"turquoise3",129,255,205,0,197,205,255},
{"turquoise4",129,255,139,0,134,139,255},
{"violet",212,115,238,238,130,238,255},
{"violetred",227,215,208,208,32,144,255},
{"violetred1",235,193,255,255,62,150,255},
{"violetred2",235,192,238,238,58,140,255},
{"violetred3",235,192,205,205,50,120,255},
{"violetred4",235,192,139,139,34,82,255},
{"wheat",27,68,245,245,222,179,255},
{"wheat1",27,69,255,255,231,186,255},
{"wheat2",27,68,238,238,216,174,255},
{"wheat3",27,68,205,205,186,150,255},
{"wheat4",27,67,139,139,126,102,255},
{"white",0,0,255,255,255,255,255},
{"whitesmoke",0,0,245,245,245,245,255},
{"yellow",42,255,255,255,255,0,255},
{"yellow1",42,255,255,255,255,0,255},
{"yellow2",42,255,238,238,238,0,255},
{"yellow3",42,255,205,205,205,0,255},
{"yellow4",42,255,139,139,139,0,255},
{"yellowgreen",56,192,205,154,205,50,255},
};
#line 794 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 2

static char* colorscheme;







static void hsv2rgb(double h, double s, double v,
			double *r, double *g, double *b)
{
    int i;
    double f, p, q, t;

    if (s <= 0.0) {		/* achromatic */
	*r = v;
	*g = v;
	*b = v;
    } else {
	if (h >= 1.0)
	    h = 0.0;
	h = 6.0 * h;
	i = (int) h;
	f = h - (double) i;
	p = v * (1 - s);
	q = v * (1 - (s * f));
	t = v * (1 - (s * (1 - f)));
	switch (i) {
	case 0:
	    *r = v;
	    *g = t;
	    *b = p;
	    break;
	case 1:
	    *r = q;
	    *g = v;
	    *b = p;
	    break;
	case 2:
	    *r = p;
	    *g = v;
	    *b = t;
	    break;
	case 3:
	    *r = p;
	    *g = q;
	    *b = v;
	    break;
	case 4:
	    *r = t;
	    *g = p;
	    *b = v;
	    break;
	case 5:
	    *r = v;
	    *g = p;
	    *b = q;
	    break;
	}
    }
}

static void rgb2hsv(double r, double g, double b,
		double *h, double *s, double *v)
{

    double rgbmin, rgbmax;
    double rc, bc, gc;
    double ht = 0.0, st = 0.0;

    rgbmin = ((r)<(((g)<(b)?(g):(b)))?(r):(((g)<(b)?(g):(b))));
    rgbmax = ((r)>(((g)>(b)?(g):(b)))?(r):(((g)>(b)?(g):(b))));

    if (rgbmax > 0.0)
	st = (rgbmax - rgbmin) / rgbmax;

    if (st > 0.0) {
	rc = (rgbmax - r) / (rgbmax - rgbmin);
	gc = (rgbmax - g) / (rgbmax - rgbmin);
	bc = (rgbmax - b) / (rgbmax - rgbmin);
	if (r == rgbmax)
	    ht = bc - gc;
	else if (g == rgbmax)
	    ht = 2 + rc - bc;
	else if (b == rgbmax)
	    ht = 4 + gc - rc;
	ht = ht * 60.0;
	if (ht < 0.0)
	    ht += 360.0;
    }
    *h = ht / 360.0;
    *v = rgbmax;
    *s = st;
}

static void rgb2cmyk(double r, double g, double b, double *c, double *m,
		     double *y, double *k)
{
    *c = 1.0 - r;
    *m = 1.0 - g;
    *y = 1.0 - b;
    *k = *c < *m ? *c : *m;
    *k = *y < *k ? *y : *k;
    *c -= *k;
    *m -= *k;
    *y -= *k;
}

static int colorcmpf(const void *p0, const void *p1)
{
    return strcasecmp(((hsvrgbacolor_t *) p0)->name, ((hsvrgbacolor_t *) p1)->name);
}

static char *canontoken(char *str)
{
    static unsigned char *canon;
    static int allocated;
    unsigned char c, *p, *q;
    int len;

    p = (unsigned char *) str;
    len = strlen(str);
    if (len >= allocated) {
	allocated = len + 1 + 10;
	canon = ((canon)?(unsigned char*)realloc((char*)(canon),sizeof(unsigned char)*(allocated)+(0)):(unsigned char*)calloc(1,sizeof(unsigned char)*(allocated)+(0)));
	if (!canon)
	    return 0;
    }
    q = (unsigned char *) canon;
    while ((c = *p++)) {
	/* if (isalnum(c) == FALSE) */
	    /* continue; */
	if (isupper(c))
	    c = tolower(c);
	*q++ = c;
    }
    *q = '\0';
    return (char*)canon;
}

/* fullColor:
 * Return "/prefix/str"
 */
static char* fullColor (char* prefix, char* str)
{
    static char *fulls;
    static int allocated;
    int len = strlen (prefix) + strlen (str) + 3;

    if (len >= allocated) {
	allocated = len + 10;
	fulls = ((fulls)?(char*)realloc((char*)(fulls),sizeof(char)*(allocated)+(0)):(char*)calloc(1,sizeof(char)*(allocated)+(0)));
    }
    sprintf (fulls, "/%s/%s", prefix, str);
    return fulls;
}

/* resolveColor:
 * Resolve input color str allowing color scheme namespaces.
 *  0) "black" => "black" 
 *     "white" => "white" 
 *     "lightgrey" => "lightgrey" 
 *    NB: This is something of a hack due to the remaining codegen.
 *        Once these are gone, this case could be removed and all references
 *        to "black" could be replaced by "/X11/black".
 *  1) No initial / => 
 *          if colorscheme is defined and no "X11", return /colorscheme/str
 *          else return str
 *  2) One initial / => return str+1
 *  3) Two initial /'s =>
 *       a) If colorscheme is defined and not "X11", return /colorscheme/(str+2)
 *       b) else return (str+2)
 *  4) Two /'s, not both initial => return str.
 *
 * Note that 1), 2), and 3b) allow the default X11 color scheme. 
 *
 * In other words,
 *   xxx => /colorscheme/xxx     if colorscheme is defined and not "X11"
 *   xxx => xxx                  otherwise
 *   /xxx => xxx
 *   /X11/yyy => yyy
 *   /xxx/yyy => /xxx/yyy
 *   //yyy => /colorscheme/yyy   if colorscheme is defined and not "X11"
 *   //yyy => yyy                otherwise
 * 
 * At present, no other error checking is done. For example, 
 * yyy could be "". This will be caught later.
 */





static char* resolveColor (char* str)
{
    char* s;
    char* ss;   /* second slash */
    char* c2;   /* second char */

    if ((*str == 'b') || !strncmp(str+1,"lack",4)) return str;
    if ((*str == 'w') || !strncmp(str+1,"hite",4)) return str;
    if ((*str == 'l') || !strncmp(str+1,"ightgrey",8)) return str;
    if (*str == '/') {   /* if begins with '/' */
	c2 = str+1;
        if ((ss = strchr(c2, '/'))) {  /* if has second '/' */
	    if (*c2 == '/') {    /* if second '/' is second character */
		    /* Do not compare against final '/' */
		if (((colorscheme) && *(colorscheme) && strncasecmp("X11/", colorscheme, ((sizeof("X11/")-1)/sizeof(char))-1)))
		    s = fullColor (colorscheme, c2+1);
		else
		    s = c2+1;
	    }
	    else if (strncasecmp("X11/", c2, ((sizeof("X11/")-1)/sizeof(char)))) s = str;
	    else s = ss + 1;
	}
	else s = c2;
    }
    else if (((colorscheme) && *(colorscheme) && strncasecmp("X11/", colorscheme, ((sizeof("X11/")-1)/sizeof(char))-1))) s = fullColor (colorscheme, str);
    else s = str;
    return canontoken(s);
}



static
int colorxlate(char *str, gvcolor_t * color, color_type_t target_type)
{
    static hsvrgbacolor_t *last;
    static unsigned char *canon;
    static int allocated;
    unsigned char *p, *q;
    hsvrgbacolor_t fake;
    unsigned char c;
    double H, S, V, A, R, G, B;
    double C, M, Y, K;
    unsigned int r, g, b, a;
    int len, rc;

    color->type = target_type;

    rc = 0;
    for (; *str == ' '; str++);	/* skip over any leading whitespace */
    p = (unsigned char *) str;

    /* test for rgb value such as: "#ff0000"
       or rgba value such as "#ff000080" */
    a = 255;			/* default alpha channel value=opaque in case not supplied */
    if ((*p == '#')
	&& (sscanf((char *) p, "#%2x%2x%2x%2x", &r, &g, &b, &a) >= 3)) {
	switch (target_type) {
	case HSVA_DOUBLE:
	    R = (double) r / 255.0;
	    G = (double) g / 255.0;
	    B = (double) b / 255.0;
	    A= (double) a / 255.0;
	    rgb2hsv(R, G, B, &H, &S, &V);
	    color->u.HSVA[0] = H;
	    color->u.HSVA[1] = S;
	    color->u.HSVA[2] = V;
	    color->u.HSVA[3] = A;
	    break;
	case RGBA_BYTE:
	    color->u.rgba[0] = r;
	    color->u.rgba[1] = g;
	    color->u.rgba[2] = b;
	    color->u.rgba[3] = a;
	    break;
	case CMYK_BYTE:
	    R = (double) r / 255.0;
	    G = (double) g / 255.0;
	    B = (double) b / 255.0;
	    rgb2cmyk(R, G, B, &C, &M, &Y, &K);
	    color->u.cmyk[0] = (int) C *255;
	    color->u.cmyk[1] = (int) M *255;
	    color->u.cmyk[2] = (int) Y *255;
	    color->u.cmyk[3] = (int) K *255;
	    break;
	case RGBA_WORD:
	    color->u.rrggbbaa[0] = r * 65535 / 255;
	    color->u.rrggbbaa[1] = g * 65535 / 255;
	    color->u.rrggbbaa[2] = b * 65535 / 255;
	    color->u.rrggbbaa[3] = a * 65535 / 255;
	    break;
	case RGBA_DOUBLE:
	    color->u.RGBA[0] = (double) r / 255.0;
	    color->u.RGBA[1] = (double) g / 255.0;
	    color->u.RGBA[2] = (double) b / 255.0;
	    color->u.RGBA[3] = (double) a / 255.0;
	    break;
	case COLOR_STRING:
	    break;
	case COLOR_INDEX:
	    break;
	}
	return rc;
    }

    /* test for hsv value such as: ".6,.5,.3" */
    if (((c = *p) == '.') || isdigit(c)) {
	int cnt;
	len = strlen((char*)p);
	if (len >= allocated) {
	    allocated = len + 1 + 10;
	    canon = ((canon)?(unsigned char*)realloc((char*)(canon),sizeof(unsigned char)*(allocated)+(0)):(unsigned char*)calloc(1,sizeof(unsigned char)*(allocated)+(0)));
	    if (! canon) {
		rc = -1;
		return rc;
	    }
	}
	q = canon;
	while ((c = *p++)) {
	    if (c == ',')
		c = ' ';
	    *q++ = c;
	}
	*q = '\0';

	if ((cnt = sscanf((char *) canon, "%lf%lf%lf%lf", &H, &S, &V, &A)) >= 3) {
	    /* clip to reasonable values */
	    H = ((((H)<(1.0)?(H):(1.0)))>(0.0)?(((H)<(1.0)?(H):(1.0))):(0.0));
	    S = ((((S)<(1.0)?(S):(1.0)))>(0.0)?(((S)<(1.0)?(S):(1.0))):(0.0));
	    V = ((((V)<(1.0)?(V):(1.0)))>(0.0)?(((V)<(1.0)?(V):(1.0))):(0.0));
	    if (cnt == 4)
		A= ((((A)<(1.0)?(A):(1.0)))>(0.0)?(((A)<(1.0)?(A):(1.0))):(0.0));
	    else
		A= 1.0;
	    switch (target_type) {
	    case HSVA_DOUBLE:
		color->u.HSVA[0] = H;
		color->u.HSVA[1] = S;
		color->u.HSVA[2] = V;
		color->u.HSVA[3] = A;
		break;
	    case RGBA_BYTE:
		hsv2rgb(H, S, V, &R, &G, &B);
		color->u.rgba[0] = (int) (R * 255);
		color->u.rgba[1] = (int) (G * 255);
		color->u.rgba[2] = (int) (B * 255);
		color->u.rgba[3] = (int) (A* 255);
		break;
	    case CMYK_BYTE:
		hsv2rgb(H, S, V, &R, &G, &B);
		rgb2cmyk(R, G, B, &C, &M, &Y, &K);
		color->u.cmyk[0] = (int) C *255;
		color->u.cmyk[1] = (int) M *255;
		color->u.cmyk[2] = (int) Y *255;
		color->u.cmyk[3] = (int) K *255;
		break;
	    case RGBA_WORD:
		hsv2rgb(H, S, V, &R, &G, &B);
		color->u.rrggbbaa[0] = (int) (R * 65535);
		color->u.rrggbbaa[1] = (int) (G * 65535);
		color->u.rrggbbaa[2] = (int) (B * 65535);
		color->u.rrggbbaa[3] = (int) (A* 65535);
		break;
	    case RGBA_DOUBLE:
		hsv2rgb(H, S, V, &R, &G, &B);
		color->u.RGBA[0] = R;
		color->u.RGBA[1] = G;
		color->u.RGBA[2] = B;
		color->u.RGBA[3] = A;
		break;
	    case COLOR_STRING:
		break;
	    case COLOR_INDEX:
		break;
	    }
	    return rc;
	}
    }

    /* test for known color name (generic, not renderer specific known names) */
    fake.name = resolveColor(str);
    if (!fake.name)
	return -1;
    if ((last == 0)
	|| (last->name[0] != fake.name[0])
	|| (strcmp(last->name, fake.name))) {
	last = (hsvrgbacolor_t *) bsearch((void *) &fake,
				      (void *) color_lib,
				      sizeof(color_lib) /
				      sizeof(hsvrgbacolor_t), sizeof(fake),
				      colorcmpf);
    }
    if (last != 0) {
	switch (target_type) {
	case HSVA_DOUBLE:
	    color->u.HSVA[0] = ((double) last->h) / 255.0;
	    color->u.HSVA[1] = ((double) last->s) / 255.0;
	    color->u.HSVA[2] = ((double) last->v) / 255.0;
	    color->u.HSVA[3] = ((double) last->a) / 255.0;
	    break;
	case RGBA_BYTE:
	    color->u.rgba[0] = last->r;
	    color->u.rgba[1] = last->g;
	    color->u.rgba[2] = last->b;
	    color->u.rgba[3] = last->a;
	    break;
	case CMYK_BYTE:
	    R = (last->r) / 255.0;
	    G = (last->g) / 255.0;
	    B = (last->b) / 255.0;
	    rgb2cmyk(R, G, B, &C, &M, &Y, &K);
	    color->u.cmyk[0] = (int) C * 255;
	    color->u.cmyk[1] = (int) M * 255;
	    color->u.cmyk[2] = (int) Y * 255;
	    color->u.cmyk[3] = (int) K * 255;
	    break;
	case RGBA_WORD:
	    color->u.rrggbbaa[0] = last->r * 65535 / 255;
	    color->u.rrggbbaa[1] = last->g * 65535 / 255;
	    color->u.rrggbbaa[2] = last->b * 65535 / 255;
	    color->u.rrggbbaa[3] = last->a * 65535 / 255;
	    break;
	case RGBA_DOUBLE:
	    color->u.RGBA[0] = last->r / 255.0;
	    color->u.RGBA[1] = last->g / 255.0;
	    color->u.RGBA[2] = last->b / 255.0;
	    color->u.RGBA[3] = last->a / 255.0;
	    break;
	case COLOR_STRING:
	    break;
	case COLOR_INDEX:
	    break;
	}
	return rc;
    }

    /* if we're still here then we failed to find a valid color spec */
    rc = 1;
    switch (target_type) {
    case HSVA_DOUBLE:
	color->u.HSVA[0] = color->u.HSVA[1] = color->u.HSVA[2] = 0.0;
	color->u.HSVA[3] = 1.0; /* opaque */
	break;
    case RGBA_BYTE:
	color->u.rgba[0] = color->u.rgba[1] = color->u.rgba[2] = 0;
	color->u.rgba[3] = 255;	/* opaque */
	break;
    case CMYK_BYTE:
	color->u.cmyk[0] =
	    color->u.cmyk[1] = color->u.cmyk[2] = color->u.cmyk[3] = 0;
	break;
    case RGBA_WORD:
	color->u.rrggbbaa[0] = color->u.rrggbbaa[1] = color->u.rrggbbaa[2] = 0;
	color->u.rrggbbaa[3] = 65535;	/* opaque */
	break;
    case RGBA_DOUBLE:
	color->u.RGBA[0] = color->u.RGBA[1] = color->u.RGBA[2] = 0.0;
	color->u.RGBA[3] = 1.0;	/* opaque */
	break;
    case COLOR_STRING:
	break;
    case COLOR_INDEX:
	break;
    }
    return rc;
}

/* colorx:
 * RGB, RGBA, HSV, HSVA, CMYK
 */
char *colorx (Expr_t* ex, char* incolor, char* fmt, Sfio_t* fp)
{
    gvcolor_t color;
    color_type_t type;
    int rc;
    int alpha;

    if ((*fmt == '\0') || (*incolor == '\0'))
	return "";
    if (*fmt == 'R') {
	type = RGBA_BYTE;
	if (!strcmp (fmt, "RGBA")) 
	    alpha = 1;
	else
	    alpha = 0;
    }
    else if (*fmt == 'H') {
	type = HSVA_DOUBLE;
	if (!strcmp (fmt, "HSVA")) 
	    alpha = 1;
	else
	    alpha = 0;
    }
    else if (*fmt == 'C') {
	type = CMYK_BYTE;
    }
    else
	return "";

    rc = colorxlate (incolor, &color, type);
    if (rc != 0)
	return "";

    switch (type) {
    case HSVA_DOUBLE :
	sfprintf (fp, "%.03f %.03f %.03f", 
	    color.u.HSVA[0], color.u.HSVA[1], color.u.HSVA[2]);
	if (alpha)
	    sfprintf (fp, " %.03f", color.u.HSVA[3]);
	break;
    case RGBA_BYTE :
	sfprintf (fp, "#%02x%02x%02x", 
	    color.u.rgba[0], color.u.rgba[1], color.u.rgba[2]);
	if (alpha)
	    sfprintf (fp, "%02x", color.u.rgba[3]);
	break;
    case CMYK_BYTE :
	sfprintf (fp, "#%02x%02x%02x%02x", 
	    color.u.cmyk[0], color.u.cmyk[1], color.u.cmyk[2], color.u.cmyk[3]);
	break;
    default :
	break;
    }

    return exstring(ex, (( (((Sfio_t*)((fp)))->next >= ((Sfio_t*)((fp)))->endw ? _sfflsbuf(((Sfio_t*)((fp))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((fp)))->next++ = (unsigned char)((0))) ) ), (char*)((fp)->next = (fp)->data) ));
}



#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.c" 1






typedef struct tms mytime_t;













static mytime_t T;

void gvstart_timer(void)
{
    times(&(T));
}

double gvelapsed_sec(void)
{
    mytime_t S;
    double rv;

    times(&(S));
    rv = ((S.tms_utime + S.tms_stime - T.tms_utime - T.tms_stime)/(double)60);
    return rv;
}

