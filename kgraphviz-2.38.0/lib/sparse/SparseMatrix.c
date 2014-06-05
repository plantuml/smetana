#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\logic.h" 1
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


















































#line 20 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1






































    extern void *zmalloc(size_t);
    extern void *zrealloc(void *, size_t, size_t, size_t);
    extern void *gmalloc(size_t);
	extern void *grealloc(void *, size_t);







#line 21 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 2
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
































































    









#line 22 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 1
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



#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
/* Applications that do not use the common library can define STANDALONE
 * to get definitions/definitions that are normally provided there.
 * In particular, note that Verbose is declared but undefined.
 */

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











#line 26 "graphviz-2.38.0\\lib\\sparse\\general.h" 2
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











#line 27 "graphviz-2.38.0\\lib\\sparse\\general.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\logic.h" 1
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


















































#line 28 "graphviz-2.38.0\\lib\\sparse\\general.h" 2
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














































































    









#line 29 "graphviz-2.38.0\\lib\\sparse\\general.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1
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











































    
    
    
	







#line 30 "graphviz-2.38.0\\lib\\sparse\\general.h" 2























































extern int irand(int n);
extern double drand(void);
extern int *random_permutation(int n);/* random permutation of 0 to n-1 */


double* vector_subtract_to(int n, double *x, double *y);/* y = x-y */
double* vector_subtract_from(int n, double *x, double *y);/* y = y-x */
double* vector_add_to(int n, double *x, double *y);

double vector_product(int n, double *x, double *y);

double* vector_saxpy(int n, double *x, double *y, double beta); /* y = x+beta*y */


double* vector_saxpy2(int n, double *x, double *y, double beta);/* x = x+beta*y */

/* take m elements v[p[i]]],i=1,...,m and oput in u. u will be assigned if *u = NULL */
void vector_take(int n, double *v, int m, int *p, double **u);
void vector_float_take(int n, float *v, int m, int *p, float **u);

/* give the position of the lagest, second largest etc in vector v if ascending = TRUE
   or
   give the position of the smallest, second smallest etc  in vector v if ascending = TRUE.
   results in p. If *p == NULL, p is asigned.
*/
void vector_ordering(int n, double *v, int **p, int ascending);
void vector_sort_real(int n, double *v, int ascending);
void vector_sort_int(int n, int *v, int ascending);
double vector_median(int n, double *x);
double vector_percentile(int n, double *x, double y);/* find the value such that y% of element of vector x is <= that value.*/

void vector_print(char *s, int n, double *x);





int excute_system_command3(char *s1, char *s2, char *s3);
int excute_system_command(char *s1, char *s2);



enum {UNMATCHED = -1};


double distance(double *x, int dim, int i, int j);
double distance_cropped(double *x, int dim, int i, int j);

double point_distance(double *p1, double *p2, int dim);

char *strip_dir(char *s);

void scale_to_box(double xmin, double ymin, double xmax, double ymax, int n, int dim, double *x);

/* check to see if this is a string is integer (that can be casted into an integer variable hence very long list of digits are not valid, like 123456789012345. Return 1 if true, 0 if false. */
int validQ_int_string(char *to_convert, int *v);

/* check to see if this is a string of digits consists of 0-9 */
int digitsQ(char *to_convert);





#line 16 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 1


enum {FORMAT_CSC, FORMAT_CSR, FORMAT_COORD};
enum {UNMASKED = -10, MASKED = 1};
enum {MATRIX_PATTERN_SYMMETRIC = 1<<0, MATRIX_SYMMETRIC = 1<<1, MATRIX_SKEW = 1<<2, MATRIX_HERMITIAN = 1<<3, MATRIX_UNDIRECTED = 1<<4};
enum {BIPARTITE_RECT = 0, BIPARTITE_PATTERN_UNSYM, BIPARTITE_UNSYM, BIPARTITE_ALWAYS};


struct SparseMatrix_struct {
  int m; /* row dimension */
  int n; /* column dimension */
  int nz;/* The actual length used is nz, for CSR/CSC matrix this is the same as ia[n] */
  int nzmax; /* the current length of ja and a (if exists) allocated.*/
  int type; /* whether it is real/complex matrix, or pattern only */
  int *ia; /* row pointer for CSR format, or row indices for coordinate format. 0-based */
  int *ja; /* column indices. 0-based */
  void *a; /* entry values. If NULL, pattern matrix */
  int format;/* whether it is CSR, CSC, COORD. By default it is in CSR format */
  int property; /* pattern_symmetric/symmetric/skew/hermitian*/
  int size;/* size of each entry. This allows for general matrix where each entry is, say, a matrix itself */
};

typedef struct SparseMatrix_struct* SparseMatrix;

enum {MATRIX_TYPE_REAL = 1<<0, MATRIX_TYPE_COMPLEX = 1<<1, MATRIX_TYPE_INTEGER = 1<<2, MATRIX_TYPE_PATTERN = 1<<3, MATRIX_TYPE_UNKNOWN = 1<<4};

/* SparseMatrix_general is more general and allow elements to be 
   any data structure, not just real/int/complex etc */
SparseMatrix SparseMatrix_new(int m, int n, int nz, int type, int format);
SparseMatrix SparseMatrix_general_new(int m, int n, int nz, int type, size_t sz, int format);

/* this version sum repeated entries */
SparseMatrix SparseMatrix_from_coordinate_format(SparseMatrix A);
/* what_to_sum is SUM_REPEATED_NONE, SUM_REPEATED_ALL, SUM_REPEATED_REAL_PART, SUM_REPEATED_IMAGINARY_PART, SUM_IMGINARY_KEEP_LAST_REAL*/
SparseMatrix SparseMatrix_from_coordinate_format_not_compacted(SparseMatrix A, int what_to_sum);

SparseMatrix SparseMatrix_from_coordinate_arrays(int nz, int m, int n, int *irn, int *jcn, void *val, int type, size_t sz);
SparseMatrix SparseMatrix_from_coordinate_arrays_not_compacted(int nz, int m, int n, int *irn, int *jcn, void *val, int type, size_t sz, int what_to_sum);


void SparseMatrix_print(char *, SparseMatrix A);/*print to stdout in Mathematica format*/

void SparseMatrix_export(FILE *f, SparseMatrix A);/* export into MM format except the header */

SparseMatrix SparseMatrix_import_binary(char *name);
SparseMatrix SparseMatrix_import_binary_fp(FILE *f);/* import into a preopenned file */

void SparseMatrix_export_binary(char *name, SparseMatrix A, int *flag);
void SparseMatrix_export_binary_fp(FILE *f, SparseMatrix A);/* export binary into a file preopened */

void SparseMatrix_delete(SparseMatrix A);

SparseMatrix SparseMatrix_add(SparseMatrix A, SparseMatrix B);
SparseMatrix SparseMatrix_multiply(SparseMatrix A, SparseMatrix B);
SparseMatrix SparseMatrix_multiply3(SparseMatrix A, SparseMatrix B, SparseMatrix C);

/* For complex matrix:
   if what_to_sum = SUM_REPEATED_REAL_PART, we find entries {i,j,x + i y} and sum the x's if {i,j,Round(y)} are the same
   if what_to_sum = SUM_REPEATED_IMAGINARY_PART, we find entries {i,j,x + i y} and sum the y's if {i,j,Round(x)} are the same
   For other matrix, what_to_sum = SUM_REPEATED_REAL_PART is the same as what_to_sum = SUM_REPEATED_IMAGINARY_PART
   or what_to_sum = SUM_REPEATED_ALL
   if what_to_sum = SUM_IMGINARY_KEEP_LAST_REAL, we merge {i,j,R1,I1} and {i,j,R2,I2} into {i,j,R1+R2,I2}. Useful if I1 and I2 are time stamps, 
   .   and we use this to indicate that a user watched R1+R2 seconds, last watch is I2.
*/
enum {SUM_REPEATED_NONE = 0, SUM_REPEATED_ALL, SUM_REPEATED_REAL_PART, SUM_REPEATED_IMAGINARY_PART, SUM_IMGINARY_KEEP_LAST_REAL};
SparseMatrix SparseMatrix_sum_repeat_entries(SparseMatrix A, int what_to_sum);
SparseMatrix SparseMatrix_coordinate_form_add_entries(SparseMatrix A, int nentries, int *irn, int *jcn, void *val);
int SparseMatrix_is_symmetric(SparseMatrix A, int test_pattern_symmetry_only);
SparseMatrix SparseMatrix_transpose(SparseMatrix A);
SparseMatrix SparseMatrix_symmetrize(SparseMatrix A, int pattern_symmetric_only);
SparseMatrix SparseMatrix_symmetrize_nodiag(SparseMatrix A, int pattern_symmetric_only);
void SparseMatrix_multiply_vector(SparseMatrix A, double *v, double **res, int transposed);/* if v = NULL, v is assumed to be {1,1,...,1}*/
SparseMatrix SparseMatrix_remove_diagonal(SparseMatrix A);
SparseMatrix SparseMatrix_remove_upper(SparseMatrix A);/* remove diag and upper diag */
SparseMatrix SparseMatrix_divide_row_by_degree(SparseMatrix A);
SparseMatrix SparseMatrix_get_real_adjacency_matrix_symmetrized(SparseMatrix A);  /* symmetric, all entries to 1, diaginal removed */
SparseMatrix SparseMatrix_normalize_to_rowsum1(SparseMatrix A);/* for real only! */
void SparseMatrix_multiply_dense(SparseMatrix A, int ATranspose, double *v, int vTransposed, double **res, int res_transpose, int dim);
SparseMatrix SparseMatrix_apply_fun(SparseMatrix A, double (*fun)(double x));/* for real only! */
SparseMatrix SparseMatrix_apply_fun_general(SparseMatrix A, void (*fun)(int i, int j, int n, double *x));/* for real and complex (n=2) */
SparseMatrix SparseMatrix_copy(SparseMatrix A);
int SparseMatrix_has_diagonal(SparseMatrix A);
SparseMatrix SparseMatrix_normalize_by_row(SparseMatrix A);/* divide by max of each row */
SparseMatrix SparseMatrix_crop(SparseMatrix A, double epsilon);/*remove any entry <= epsilon*/
SparseMatrix SparseMatrix_scaled_by_vector(SparseMatrix A, double *v, int apply_to_row);
SparseMatrix SparseMatrix_multiply_by_scaler(SparseMatrix A, double s);
SparseMatrix SparseMatrix_make_undirected(SparseMatrix A);/* make it strictly low diag only, and set flag to undirected */
int SparseMatrix_connectedQ(SparseMatrix A);
double SparseMatrix_pseudo_diameter_only(SparseMatrix A);
double SparseMatrix_pseudo_diameter_weighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ); /* assume real distances, unsymmetric matrix ill be symmetrized */
double SparseMatrix_pseudo_diameter_unweighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ); /* assume unit edge length, unsymmetric matrix ill be symmetrized */
void SparseMatrix_level_sets(SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reintialize_mask);
void SparseMatrix_level_sets_khops(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reintialize_mask);
void SparseMatrix_weakly_connected_components(SparseMatrix A0, int *ncomp, int **comps, int **comps_ptr);
void SparseMatrix_decompose_to_supervariables(SparseMatrix A, int *ncluster, int **cluster, int **clusterp);
SparseMatrix SparseMatrix_get_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices);
SparseMatrix SparseMatrix_exclude_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices);

SparseMatrix SparseMatrix_get_augmented(SparseMatrix A);

/* bipartite_options:
   BIPARTITE_RECT -- turn rectangular matrix into square), 
   BIPARTITE_PATTERN_UNSYM -- pattern unsummetric as bipartite
   BIPARTITE_UNSYM -- unsymmetric as square
   BIPARTITE_ALWAYS -- always as square
*/
SparseMatrix SparseMatrix_to_square_matrix(SparseMatrix A, int bipartite_options);

SparseMatrix SparseMatrix_largest_component(SparseMatrix A);

/* columns with <= threhold entries are deleted */
SparseMatrix SparseMatrix_delete_empty_columns(SparseMatrix A, int **new2old, int *nnew, int inplace);
SparseMatrix SparseMatrix_delete_sparse_columns(SparseMatrix A, int threshold, int **new2old, int *nnew, int inplace);

SparseMatrix SparseMatrix_sort(SparseMatrix A);

SparseMatrix SparseMatrix_set_entries_to_real_one(SparseMatrix A);

SparseMatrix SparseMatrix_complement(SparseMatrix A, int undirected);

int SparseMatrix_k_centers(SparseMatrix D, int weighted, int K, int root, 
			  int **centers, int centering, double **dist);

int SparseMatrix_k_centers_user(SparseMatrix D, int weighted, int K, 
				int *centers_user, int centering, double **dist);

SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted);

int SparseMatrix_distance_matrix(SparseMatrix A, int weighted,  double **dist_matrix);
SparseMatrix SparseMatrix_distance_matrix_khops(int khops, SparseMatrix A, int weighted);
SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted);

void SparseMatrix_kcoreness(SparseMatrix A, int **coreness);/* assign coreness to each node */
void SparseMatrix_kcore_decomposition(SparseMatrix A, int *coreness_max0, int **coreness_ptr0, int **coreness_list0);/* return the decomposition */

void SparseMatrix_khairness(SparseMatrix A, int **hairness);/* assign hairness to each node */
void SparseMatrix_khair_decomposition(SparseMatrix A, int *hairness_max0, int **hairness_ptr0, int **hairness_list0);/* return the decomposition */

SparseMatrix SparseMatrix_from_dense(int m, int n, double *x);

void SparseMatrix_page_rank(SparseMatrix A, double teleport_probablity, int weighted, double epsilon, double **page_rank);


























#line 23 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\BinaryHeap.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
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










































































































































#line 17 "graphviz-2.38.0\\lib\\sparse\\BinaryHeap.h" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\IntStack.h" 1
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




/* last in first out integer stack */
struct IntStack_struct{
  int last;/* position of the last element, If empty, last = -1 */
  int max_len;
  int *stack;
};

typedef struct IntStack_struct* IntStack;

IntStack IntStack_new(void);

void IntStack_delete(IntStack s);



int IntStack_push(IntStack s, int i);/* add an item and return the pos (>=0).
					Return negative value of malloc failed */

int IntStack_pop(IntStack s, int *flag);/* remove the last item. If none exist, flag = -1, and return -1. */

void IntStack_print(IntStack s);


#line 18 "graphviz-2.38.0\\lib\\sparse\\BinaryHeap.h" 2

/* binary heap code. 
   Caution: items inserted should be kept untouched, e.g., the value of the item should be kepted unchanged while the heap is still in use! 
   To change the valud of am item, use BinaryHeap_reset
*/

struct BinaryHeap_struct {
  int max_len;/* storage allocated for the heap */
  int len;/*number of elements in the heap so far. <= maxlen */
  void **heap;
  int *id_to_pos;/* this array store the position of an item with ID. For ID that was not in use,
		    i.e., no in pos_to_id[1:len],
		    id_to_pos[id] = -1
		  */
  int *pos_to_id;/* this array stores the ID of item at position pos. 
		    pos_to_id[id_to_pos[i]] = i, for i not in the id_stack & i < length(id_stack)+len
		    id_to_pos[pos_to_id[i]] = i, 0 <= i < len
		 */
  IntStack id_stack;/* a stack that store IDs that is no longer used, to
		       be assigned to newly inserted elements.
		       For sanity check, the union of items in
		       the id_stack, and that is pos_to_id[1:len],
		       should form a set of contiguous numbers 
		       {1, 2, ..., len, ...}
		    */
  int (*cmp)(void*item1, void*item2);/* comparison function. Return 1,0,-1
				      if item1 >, =, < item2 */
};

enum {BinaryHeap_error_malloc = -10};

typedef struct BinaryHeap_struct* BinaryHeap;

BinaryHeap BinaryHeap_new(int (*cmp)(void*item1, void*item2));


void BinaryHeap_delete(BinaryHeap h, void (*del)(void* item));/* delete not just the heap data structure, but also the data items
								       through a user supplied del function. */

int BinaryHeap_insert(BinaryHeap h, void *item);/* insert an item, and return its ID. 
						   This ID can be used later to extract the item. ID
						   are always nonnegative. If the return value is 
						   negative, it is an error message */

void* BinaryHeap_get_min(BinaryHeap h);/* return the min item */

void* BinaryHeap_extract_min(BinaryHeap h);/* return and remove the min item */

void* BinaryHeap_extract_item(BinaryHeap h, int id);/* extract an item with ID out and delete it */

void* BinaryHeap_get_item(BinaryHeap h, int id);/* get an item with ID out, without deleting */

int BinaryHeap_reset(BinaryHeap h, int id, void *item);/* reset value of an item with specified id. Return new pos. If ID is invalue, return -1 */

void BinaryHeap_print(BinaryHeap h, void (*pnt)(void*));

void BinaryHeap_sanity_check(BinaryHeap h);


#line 24 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.c" 2





static size_t size_of_matrix_type(int type){
  int size = 0;
  switch (type){
  case MATRIX_TYPE_REAL:
    size = sizeof(double);
    break;
  case MATRIX_TYPE_COMPLEX:
    size = 2*sizeof(double);
    break;
  case MATRIX_TYPE_INTEGER:
    size = sizeof(int);
    break;
  case MATRIX_TYPE_PATTERN:
    size = 0;
    break;
  case MATRIX_TYPE_UNKNOWN:
    size = 0;
    break;
  default:
    size = 0;
    break;
  }

  return size;
}

SparseMatrix SparseMatrix_sort(SparseMatrix A){
  SparseMatrix B;
  B = SparseMatrix_transpose(A);
  SparseMatrix_delete(A);
  A = SparseMatrix_transpose(B);
  SparseMatrix_delete(B);
  return A;
}
SparseMatrix SparseMatrix_make_undirected(SparseMatrix A){
  /* make it strictly low diag only, and set flag to undirected */
  SparseMatrix B;
  B = SparseMatrix_symmetrize(A, (0));
  (((B)->property)=(((B)->property)|(MATRIX_UNDIRECTED)));
  return SparseMatrix_remove_upper(B);
}
SparseMatrix SparseMatrix_transpose(SparseMatrix A){
  int *ia = A->ia, *ja = A->ja, *ib, *jb, nz = A->nz, m = A->m, n = A->n, type = A->type, format = A->format;
  SparseMatrix B;
  int i, j;

  if (!A) return (void *)0;
  assert(A->format == FORMAT_CSR);/* only implemented for CSR right now */

  B = SparseMatrix_new(n, m, nz, type, format);
  B->nz = nz;
  ib = B->ia;
  jb = B->ja;

  for (i = 0; i <= n; i++) ib[i] = 0;
  for (i = 0; i < m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      ib[ja[j]+1]++;
    }
  }

  for (i = 0; i < n; i++) ib[i+1] += ib[i];

  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jb[ib[ja[j]]] = i;
	b[ib[ja[j]]++] = a[j];
      }
    }
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jb[ib[ja[j]]] = i;
	b[2*ib[ja[j]]] = a[2*j];
	b[2*ib[ja[j]]+1] = a[2*j+1];
	ib[ja[j]]++;
      }
    }
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *ai = (int*) A->a;
    int *bi = (int*) B->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jb[ib[ja[j]]] = i;
	bi[ib[ja[j]]++] = ai[j];
      }
    }
    break;
  }
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jb[ib[ja[j]]++] = i;
      }
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
    SparseMatrix_delete(B);
    return (void *)0;
  default:
    SparseMatrix_delete(B);
    return (void *)0;
  }


  for (i = n-1; i >= 0; i--) ib[i+1] = ib[i];
  ib[0] = 0;
  

  return B;
}

SparseMatrix SparseMatrix_symmetrize(SparseMatrix A, int pattern_symmetric_only){
  SparseMatrix B;
  if (SparseMatrix_is_symmetric(A, pattern_symmetric_only)) return SparseMatrix_copy(A);
  B = SparseMatrix_transpose(A);
  if (!B) return (void *)0;
  A = SparseMatrix_add(A, B);
  SparseMatrix_delete(B);
  (((A)->property)=(((A)->property)|(MATRIX_SYMMETRIC)));
  (((A)->property)=(((A)->property)|(MATRIX_PATTERN_SYMMETRIC)));
  return A;
}

SparseMatrix SparseMatrix_symmetrize_nodiag(SparseMatrix A, int pattern_symmetric_only){
  SparseMatrix B;
  if (SparseMatrix_is_symmetric(A, pattern_symmetric_only)) {
    B = SparseMatrix_copy(A);
    return SparseMatrix_remove_diagonal(B);
  }
  B = SparseMatrix_transpose(A);
  if (!B) return (void *)0;
  A = SparseMatrix_add(A, B);
  SparseMatrix_delete(B);
  (((A)->property)=(((A)->property)|(MATRIX_SYMMETRIC)));
  (((A)->property)=(((A)->property)|(MATRIX_PATTERN_SYMMETRIC)));
  return SparseMatrix_remove_diagonal(A);
}

int SparseMatrix_is_symmetric(SparseMatrix A, int test_pattern_symmetry_only){
  /* assume no repeated entries! */
  SparseMatrix B;
  int *ia, *ja, *ib, *jb, type, m;
  int *mask;
  int res = (0);
  int i, j;
  assert(A->format == FORMAT_CSR);/* only implemented for CSR right now */

  if (!A) return (0);

  if ((((A)->property)&(MATRIX_SYMMETRIC))) return (!(0));
  if (test_pattern_symmetry_only && (((A)->property)&(MATRIX_PATTERN_SYMMETRIC))) return (!(0));

  if (A->m != A->n) return (0);

  B = SparseMatrix_transpose(A);
  if (!B) return (0);

  ia = A->ia;
  ja = A->ja;
  ib = B->ia;
  jb = B->ja;
  m = A->m;

  mask = gmalloc(sizeof(int)*((size_t) m));
  for (i = 0; i < m; i++) mask[i] = -1;

  type = A->type;
  if (test_pattern_symmetry_only) type = MATRIX_TYPE_PATTERN;

  switch (type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    for (i = 0; i <= m; i++) if (ia[i] != ib[i]) goto RETURN;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = j;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ia[i]) goto RETURN;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (((b[j] - a[mask[jb[j]]]) >= 0 ? (b[j] - a[mask[jb[j]]]) : -(b[j] - a[mask[jb[j]]])) > 0.0000001) goto RETURN;
      }
    }
    res = (!(0));
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    for (i = 0; i <= m; i++) if (ia[i] != ib[i]) goto RETURN;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = j;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ia[i]) goto RETURN;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (((b[2*j] - a[2*mask[jb[j]]]) >= 0 ? (b[2*j] - a[2*mask[jb[j]]]) : -(b[2*j] - a[2*mask[jb[j]]])) > 0.0000001) goto RETURN;
	if (((b[2*j+1] - a[2*mask[jb[j]]+1]) >= 0 ? (b[2*j+1] - a[2*mask[jb[j]]+1]) : -(b[2*j+1] - a[2*mask[jb[j]]+1])) > 0.0000001) goto RETURN;
      }
    }
    res = (!(0));
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *ai = (int*) A->a;
    int *bi = (int*) B->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = j;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ia[i]) goto RETURN;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (bi[j] != ai[mask[jb[j]]]) goto RETURN;
      }
    }
    res = (!(0));
    break;
  }
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = j;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ia[i]) goto RETURN;
      }
    }
    res = (!(0));
    break;
  case MATRIX_TYPE_UNKNOWN:
    goto RETURN;
    break;
  default:
    goto RETURN;
    break;
  }

  if (test_pattern_symmetry_only){
    (((A)->property)=(((A)->property)|(MATRIX_PATTERN_SYMMETRIC)));
  } else {
    (((A)->property)=(((A)->property)|(MATRIX_SYMMETRIC)));
    (((A)->property)=(((A)->property)|(MATRIX_PATTERN_SYMMETRIC)));
  }
 RETURN:
  free(mask);

  SparseMatrix_delete(B);
  return res;
}

static SparseMatrix SparseMatrix_init(int m, int n, int type, size_t sz, int format){
  SparseMatrix A;


  A = gmalloc(sizeof(struct SparseMatrix_struct));
  A->m = m;
  A->n = n;
  A->nz = 0;
  A->nzmax = 0;
  A->type = type;
  A->size = sz;
  switch (format){
  case FORMAT_COORD:
    A->ia = (void *)0;
    break;
  case FORMAT_CSC:
  case FORMAT_CSR:
  default:
    A->ia = gmalloc(sizeof(int)*((size_t)(m+1)));
  }
  A->ja = (void *)0;
  A->a = (void *)0;
  A->format = format;
  A->property = 0;
  ((A->property) &=(~(MATRIX_PATTERN_SYMMETRIC)));
  ((A->property) &=(~(MATRIX_SYMMETRIC)));
  ((A->property) &=(~(MATRIX_SKEW)));
  ((A->property) &=(~(MATRIX_HERMITIAN)));
  return A;
}

static SparseMatrix SparseMatrix_alloc(SparseMatrix A, int nz){
  int format = A->format;
  size_t nz_t = (size_t) nz; /* size_t is 64 bit on 64 bit machine. Using nz*A->size can overflow. */

  A->a = (void *)0;
  switch (format){
  case FORMAT_COORD:
    A->ia = gmalloc(sizeof(int)*nz_t);
    A->ja = gmalloc(sizeof(int)*nz_t);
    A->a = gmalloc(A->size*nz_t);
    break;
  case FORMAT_CSR:
  case FORMAT_CSC:
  default:
    A->ja = gmalloc(sizeof(int)*nz_t);
    if (A->size > 0 && nz_t > 0) {
      A->a = gmalloc(A->size*nz_t);
    }
    break;
  }
  A->nzmax = nz;
  return A;
}

static SparseMatrix SparseMatrix_realloc(SparseMatrix A, int nz){
  int format = A->format;
  size_t nz_t = (size_t) nz; /* size_t is 64 bit on 64 bit machine. Using nz*A->size can overflow. */

  switch (format){
  case FORMAT_COORD:
    A->ia = grealloc(A->ia, sizeof(int)*nz_t);
    A->ja = grealloc(A->ja, sizeof(int)*nz_t);
    if (A->size > 0) {
      if (A->a){
	A->a = grealloc(A->a, A->size*nz_t);
      } else {
	A->a = gmalloc(A->size*nz_t);
      }
    } 
    break;
  case FORMAT_CSR:
  case FORMAT_CSC:
  default:
    A->ja = grealloc(A->ja, sizeof(int)*nz_t);
    if (A->size > 0) {
      if (A->a){
	A->a = grealloc(A->a, A->size*nz_t);
      } else {
	A->a = gmalloc(A->size*nz_t);
      }
    }
    break;
  }
  A->nzmax = nz;
  return A;
}

SparseMatrix SparseMatrix_new(int m, int n, int nz, int type, int format){
  /* return a sparse matrix skeleton with row dimension m and storage nz. If nz == 0, 
     only row pointers are allocated */
  SparseMatrix A;
  size_t sz;

  sz = size_of_matrix_type(type);
  A = SparseMatrix_init(m, n, type, sz, format);

  if (nz > 0) A = SparseMatrix_alloc(A, nz);
  return A;

}
SparseMatrix SparseMatrix_general_new(int m, int n, int nz, int type, size_t sz, int format){
  /* return a sparse matrix skeleton with row dimension m and storage nz. If nz == 0, 
     only row pointers are allocated. this is more general and allow elements to be 
     any data structure, not just real/int/complex etc
  */
  SparseMatrix A;

  A = SparseMatrix_init(m, n, type, sz, format);

  if (nz > 0) A = SparseMatrix_alloc(A, nz);
  return A;

}

void SparseMatrix_delete(SparseMatrix A){
  /* return a sparse matrix skeleton with row dimension m and storage nz. If nz == 0, 
     only row pointers are allocated */
  if (!A) return;
  if (A->ia) free(A->ia);
  if (A->ja) free(A->ja);
  if (A->a) free(A->a);
  free(A);
}
void SparseMatrix_print_csr(char *c, SparseMatrix A){
  int *ia, *ja;
  double *a;
  int *ai;
  int i, j, m = A->m;
  
  assert (A->format == FORMAT_CSR);
  printf("%s\n SparseArray[{",c);
  ia = A->ia;
  ja = A->ja;
  a = A->a;
  switch (A->type){
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	printf("{%d, %d}->%f",i+1, ja[j]+1, a[j]);
	if (j != ia[m]-1) printf(",");
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    a = (double*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	printf("{%d, %d}->%f + %f I",i+1, ja[j]+1, a[2*j], a[2*j+1]);
 	if (j != ia[m]-1) printf(",");
     }
    }
    printf("\n");
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	printf("{%d, %d}->%d",i+1, ja[j]+1, ai[j]);
 	if (j != ia[m]-1) printf(",");
     }
    }
    printf("\n");
    break;
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	printf("{%d, %d}->_",i+1, ja[j]+1);
 	if (j != ia[m]-1) printf(",");
      }
    }
    printf("\n");
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }
  printf("},{%d, %d}]\n", m, A->n);

}



void SparseMatrix_print_coord(char *c, SparseMatrix A){
  int *ia, *ja;
  double *a;
  int *ai;
  int i, m = A->m;
  
  assert (A->format == FORMAT_COORD);
  printf("%s\n SparseArray[{",c);
  ia = A->ia;
  ja = A->ja;
  a = A->a;
  switch (A->type){
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    for (i = 0; i < A->nz; i++){
      printf("{%d, %d}->%f",ia[i]+1, ja[i]+1, a[i]);
      if (i != A->nz - 1) printf(",");
    }
    printf("\n");
    break;
  case MATRIX_TYPE_COMPLEX:
    a = (double*) A->a;
    for (i = 0; i < A->nz; i++){
      printf("{%d, %d}->%f + %f I",ia[i]+1, ja[i]+1, a[2*i], a[2*i+1]);
      if (i != A->nz - 1) printf(",");
    }
    printf("\n");
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    for (i = 0; i < A->nz; i++){
      printf("{%d, %d}->%d",ia[i]+1, ja[i]+1, ai[i]);
      if (i != A->nz) printf(",");
    }
    printf("\n");
    break;
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < A->nz; i++){
      printf("{%d, %d}->_",ia[i]+1, ja[i]+1);
      if (i != A->nz - 1) printf(",");
    }
    printf("\n");
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }
  printf("},{%d, %d}]\n", m, A->n);

}




void SparseMatrix_print(char *c, SparseMatrix A){
  switch (A->format){
  case FORMAT_CSR:
    SparseMatrix_print_csr(c, A);
    break;
  case FORMAT_CSC:
    assert(0);/* not implemented yet...
		 SparseMatrix_print_csc(c, A);*/
    break;
  case FORMAT_COORD:
    SparseMatrix_print_coord(c, A);
    break;
  default:
    assert(0);
  }
}





static void SparseMatrix_export_csr(FILE *f, SparseMatrix A){
  int *ia, *ja;
  double *a;
  int *ai;
  int i, j, m = A->m;
  
  switch (A->type){
  case MATRIX_TYPE_REAL:
    fprintf(f,"%%%%MatrixMarket matrix coordinate real general\n");
    break;
  case MATRIX_TYPE_COMPLEX:
    fprintf(f,"%%%%MatrixMarket matrix coordinate complex general\n");
    break;
  case MATRIX_TYPE_INTEGER:
    fprintf(f,"%%%%MatrixMarket matrix coordinate integer general\n");
    break;
  case MATRIX_TYPE_PATTERN:
    fprintf(f,"%%%%MatrixMarket matrix coordinate pattern general\n");
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }

  fprintf(f,"%d %d %d\n",A->m,A->n,A->nz);
  ia = A->ia;
  ja = A->ja;
  a = A->a;
  switch (A->type){
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	fprintf(f, "%d %d %16.8g\n",i+1, ja[j]+1, a[j]);
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    a = (double*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	fprintf(f, "%d %d %16.8g %16.8g\n",i+1, ja[j]+1, a[2*j], a[2*j+1]);
     }
    }
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	fprintf(f, "%d %d %d\n",i+1, ja[j]+1, ai[j]);
     }
    }
    break;
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	fprintf(f, "%d %d\n",i+1, ja[j]+1);
      }
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }

}

void SparseMatrix_export_binary_fp(FILE *f, SparseMatrix A){

  fwrite(&(A->m), sizeof(int), 1, f);
  fwrite(&(A->n), sizeof(int), 1, f);
  fwrite(&(A->nz), sizeof(int), 1, f);
  fwrite(&(A->nzmax), sizeof(int), 1, f);
  fwrite(&(A->type), sizeof(int), 1, f);
  fwrite(&(A->format), sizeof(int), 1, f);
  fwrite(&(A->property), sizeof(int), 1, f);
  fwrite(&(A->size), sizeof(size_t), 1, f);
  if (A->format == FORMAT_COORD){
    fwrite(A->ia, sizeof(int), A->nz, f);
  } else {
    fwrite(A->ia, sizeof(int), A->m + 1, f);
  }
  fwrite(A->ja, sizeof(int), A->nz, f);
  if (A->size > 0) fwrite(A->a, A->size, A->nz, f);

}

void SparseMatrix_export_binary(char *name, SparseMatrix A, int *flag){
  FILE *f;

  *flag = 0;
  f = fopen(name, "wb");
  if (!f) {
    *flag = 1;
    return;
  }
  SparseMatrix_export_binary_fp(f, A);
  fclose(f);

}



SparseMatrix SparseMatrix_import_binary_fp(FILE *f){
  SparseMatrix A = (void *)0;
  int m, n, nz, nzmax, type, format, property, iread;
  size_t sz;

  iread = fread(&m, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&n, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&nz, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&nzmax, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&type, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&format, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&property, sizeof(int), 1, f);
  if (iread != 1) return (void *)0;
  iread = fread(&sz, sizeof(size_t), 1, f);
  if (iread != 1) return (void *)0;
  
  A = SparseMatrix_general_new(m, n, nz, type, sz, format);
  A->nz = nz;
  A->property = property;
  
  if (format == FORMAT_COORD){
    iread = fread(A->ia, sizeof(int), A->nz, f);
    if (iread != A->nz) return (void *)0;
  } else {
    iread = fread(A->ia, sizeof(int), A->m + 1, f);
    if (iread != A->m + 1) return (void *)0;
  }
  iread = fread(A->ja, sizeof(int), A->nz, f);
  if (iread != A->nz) return (void *)0;

  if (A->size > 0) {
    iread = fread(A->a, A->size, A->nz, f);
    if (iread != A->nz) return (void *)0;
  }
  fclose(f);
  return A;
}


SparseMatrix SparseMatrix_import_binary(char *name){
  SparseMatrix A = (void *)0;
  FILE *f;
  f = fopen(name, "rb");

  A = SparseMatrix_import_binary_fp(f);
  return A;
}

static void SparseMatrix_export_coord(FILE *f, SparseMatrix A){
  int *ia, *ja;
  double *a;
  int *ai;
  int i;
  
  switch (A->type){
  case MATRIX_TYPE_REAL:
    fprintf(f,"%%%%MatrixMarket matrix coordinate real general\n");
    break;
  case MATRIX_TYPE_COMPLEX:
    fprintf(f,"%%%%MatrixMarket matrix coordinate complex general\n");
    break;
  case MATRIX_TYPE_INTEGER:
    fprintf(f,"%%%%MatrixMarket matrix coordinate integer general\n");
    break;
  case MATRIX_TYPE_PATTERN:
    fprintf(f,"%%%%MatrixMarket matrix coordinate pattern general\n");
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }

  fprintf(f,"%d %d %d\n",A->m,A->n,A->nz);
  ia = A->ia;
  ja = A->ja;
  a = A->a;
  switch (A->type){
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    for (i = 0; i < A->nz; i++){
      fprintf(f, "%d %d %16.8g\n",ia[i]+1, ja[i]+1, a[i]);
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    a = (double*) A->a;
    for (i = 0; i < A->nz; i++){
      fprintf(f, "%d %d %16.8g %16.8g\n",ia[i]+1, ja[i]+1, a[2*i], a[2*i+1]);
    }
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    for (i = 0; i < A->nz; i++){
      fprintf(f, "%d %d %d\n",ia[i]+1, ja[i]+1, ai[i]);
    }
    break;
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < A->nz; i++){
      fprintf(f, "%d %d\n",ia[i]+1, ja[i]+1);
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
    return;
  default:
    return;
  }
}



void SparseMatrix_export(FILE *f, SparseMatrix A){

  switch (A->format){
  case FORMAT_CSR:
    SparseMatrix_export_csr(f, A);
    break;
  case FORMAT_CSC:
    assert(0);/* not implemented yet...
		 SparseMatrix_print_csc(c, A);*/
    break;
  case FORMAT_COORD:
    SparseMatrix_export_coord(f, A);
    break;
  default:
    assert(0);
  }
}


SparseMatrix SparseMatrix_from_coordinate_format(SparseMatrix A){
  /* convert a sparse matrix in coordinate form to one in compressed row form.*/
  int *irn, *jcn;

  void *a = A->a;

  assert(A->format == FORMAT_COORD);
  if (A->format != FORMAT_COORD) {
    return (void *)0;
  }
  irn = A->ia;
  jcn = A->ja;
  return SparseMatrix_from_coordinate_arrays(A->nz, A->m, A->n, irn, jcn, a, A->type, A->size);

}
SparseMatrix SparseMatrix_from_coordinate_format_not_compacted(SparseMatrix A, int what_to_sum){
  /* convert a sparse matrix in coordinate form to one in compressed row form.*/
  int *irn, *jcn;

  void *a = A->a;

  assert(A->format == FORMAT_COORD);
  if (A->format != FORMAT_COORD) {
    return (void *)0;
  }
  irn = A->ia;
  jcn = A->ja;
  return SparseMatrix_from_coordinate_arrays_not_compacted(A->nz, A->m, A->n, irn, jcn, a, A->type, A->size, what_to_sum);

}

static SparseMatrix SparseMatrix_from_coordinate_arrays_internal(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz, int sum_repeated){
  /* convert a sparse matrix in coordinate form to one in compressed row form.
     nz: number of entries
     irn: row indices 0-based
     jcn: column indices 0-based
     val values if not NULL
     type: matrix type
  */

  SparseMatrix A = (void *)0;
  int *ia, *ja;
  double *a, *val;
  int *ai, *vali;
  int i;

  assert(m > 0 && n > 0 && nz >= 0);

  if (m <=0 || n <= 0 || nz < 0) return (void *)0;
  A = SparseMatrix_general_new(m, n, nz, type, sz, FORMAT_CSR);
  assert(A);
  if (!A) return (void *)0;
  ia = A->ia;
  ja = A->ja;

  for (i = 0; i <= m; i++){
    ia[i] = 0;
  }

  switch (type){
  case MATRIX_TYPE_REAL:
    val = (double*) val0;
    a = (double*) A->a;
    for (i = 0; i < nz; i++){
      if (irn[i] < 0 || irn[i] >= m || jcn[i] < 0 || jcn[i] >= n) {
	assert(0);
	return (void *)0;
      }
      ia[irn[i]+1]++;
    }
    for (i = 0; i < m; i++) ia[i+1] += ia[i];
    for (i = 0; i < nz; i++){
      a[ia[irn[i]]] = val[i];
      ja[ia[irn[i]]++] = jcn[i];
    }
    for (i = m; i > 0; i--) ia[i] = ia[i - 1];
    ia[0] = 0;
    break;
  case MATRIX_TYPE_COMPLEX:
    val = (double*) val0;
    a = (double*) A->a;
    for (i = 0; i < nz; i++){
      if (irn[i] < 0 || irn[i] >= m || jcn[i] < 0 || jcn[i] >= n) {
	assert(0);
	return (void *)0;
      }
      ia[irn[i]+1]++;
    }
    for (i = 0; i < m; i++) ia[i+1] += ia[i];
    for (i = 0; i < nz; i++){
      a[2*ia[irn[i]]] = *(val++);
      a[2*ia[irn[i]]+1] = *(val++);
      ja[ia[irn[i]]++] = jcn[i];
    }
    for (i = m; i > 0; i--) ia[i] = ia[i - 1];
    ia[0] = 0;
    break;
  case MATRIX_TYPE_INTEGER:
    vali = (int*) val0;
    ai = (int*) A->a;
    for (i = 0; i < nz; i++){
      if (irn[i] < 0 || irn[i] >= m || jcn[i] < 0 || jcn[i] >= n) {
	assert(0);
	return (void *)0;
      }
      ia[irn[i]+1]++;
    }
    for (i = 0; i < m; i++) ia[i+1] += ia[i];
    for (i = 0; i < nz; i++){
      ai[ia[irn[i]]] = vali[i];
      ja[ia[irn[i]]++] = jcn[i];
    }
    for (i = m; i > 0; i--) ia[i] = ia[i - 1];
    ia[0] = 0;
    break;
  case MATRIX_TYPE_PATTERN:
    for (i = 0; i < nz; i++){
      if (irn[i] < 0 || irn[i] >= m || jcn[i] < 0 || jcn[i] >= n) {
	assert(0);
	return (void *)0;
      }
      ia[irn[i]+1]++;
    }
    for (i = 0; i < m; i++) ia[i+1] += ia[i];
    for (i = 0; i < nz; i++){
      ja[ia[irn[i]]++] = jcn[i];
    }
    for (i = m; i > 0; i--) ia[i] = ia[i - 1];
    ia[0] = 0;
    break;
  case MATRIX_TYPE_UNKNOWN:
    for (i = 0; i < nz; i++){
      if (irn[i] < 0 || irn[i] >= m || jcn[i] < 0 || jcn[i] >= n) {
	assert(0);
	return (void *)0;
      }
      ia[irn[i]+1]++;
    }
    for (i = 0; i < m; i++) ia[i+1] += ia[i];
    memcpy(A->a, val0, A->size*((size_t)nz));
    for (i = 0; i < nz; i++){
      ja[ia[irn[i]]++] = jcn[i];
    }
    for (i = m; i > 0; i--) ia[i] = ia[i - 1];
    ia[0] = 0;
    break;
  default:
    assert(0);
    return (void *)0;
  }
  A->nz = nz;



  if(sum_repeated) A = SparseMatrix_sum_repeat_entries(A, sum_repeated);
 
  return A;
}


SparseMatrix SparseMatrix_from_coordinate_arrays(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz){
  return SparseMatrix_from_coordinate_arrays_internal(nz, m, n, irn, jcn, val0, type, sz, SUM_REPEATED_ALL);
}


SparseMatrix SparseMatrix_from_coordinate_arrays_not_compacted(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz, int what_to_sum){
  return SparseMatrix_from_coordinate_arrays_internal(nz, m, n, irn, jcn, val0, type, sz, what_to_sum);
}

SparseMatrix SparseMatrix_add(SparseMatrix A, SparseMatrix B){
  int m, n;
  SparseMatrix C = (void *)0;
  int *mask = (void *)0;
  int *ia = A->ia, *ja = A->ja, *ib = B->ia, *jb = B->ja, *ic, *jc;
  int i, j, nz, nzmax;

  assert(A && B);
  assert(A->format == B->format && A->format == FORMAT_CSR);/* other format not yet supported */
  assert(A->type == B->type);
  m = A->m;
  n = A->n;
  if (m != B->m || n != B->n) return (void *)0;

  nzmax = A->nz + B->nz;/* just assume that no entries overlaps for speed */

  C = SparseMatrix_new(m, n, nzmax, A->type, FORMAT_CSR);
  if (!C) goto RETURN;
  ic = C->ia;
  jc = C->ja;

  mask = gmalloc(sizeof(int)*((size_t) n));

  for (i = 0; i < n; i++) mask[i] = -1;

  nz = 0;
  ic[0] = 0;
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    double *c = (double*) C->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = nz;
	jc[nz] = ja[j];
	c[nz] = a[j];
	nz++;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ic[i]){
	  jc[nz] = jb[j];
	  c[nz++] = b[j];
	} else {
	  c[mask[jb[j]]] += b[j];
	}
      }
      ic[i+1] = nz;
    }
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    double *b = (double*) B->a;
    double *c = (double*) C->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = nz;
	jc[nz] = ja[j];
	c[2*nz] = a[2*j];
	c[2*nz+1] = a[2*j+1];
	nz++;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ic[i]){
	  jc[nz] = jb[j];
	  c[2*nz] = b[2*j];
	  c[2*nz+1] = b[2*j+1];
	  nz++;
	} else {
	  c[2*mask[jb[j]]] += b[2*j];
	  c[2*mask[jb[j]]+1] += b[2*j+1];
	}
      }
      ic[i+1] = nz;
    }
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    int *b = (int*) B->a;
    int *c = (int*) C->a;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = nz;
	jc[nz] = ja[j];
	c[nz] = a[j];
	nz++;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ic[i]){
	  jc[nz] = jb[j];
	  c[nz] = b[j];
	  nz++;
	} else {
	  c[mask[jb[j]]] += b[j];
	}
      }
      ic[i+1] = nz;
    }
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	mask[ja[j]] = nz;
	jc[nz] = ja[j];
	nz++;
      }
      for (j = ib[i]; j < ib[i+1]; j++){
	if (mask[jb[j]] < ic[i]){
	  jc[nz] = jb[j];
	  nz++;
	} 
      }
      ic[i+1] = nz;
    }
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    break;
  default:
    break;
  }
  C->nz = nz;

 RETURN:
  if (mask) free(mask);

  return C;
}



static void dense_transpose(double *v, int m, int n){
  /* transpose an m X n matrix in place. Well, we do no really do it without xtra memory. This is possibe, but too complicated for ow */
  int i, j;
  double *u;
  u = gmalloc(sizeof(double)*((size_t) m)*((size_t) n));
  memcpy(u,v, sizeof(double)*((size_t) m)*((size_t) n));

  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      v[j*m+i] = u[i*n+j];
    }
  }
  free(u);
}


static void SparseMatrix_multiply_dense1(SparseMatrix A, double *v, double **res, int dim, int transposed, int res_transposed){
  /* A v or A^T v where v a dense matrix of second dimension dim. Real only for now. */
  int i, j, k, *ia, *ja, n, m;
  double *a, *u;

  assert(A->format == FORMAT_CSR);
  assert(A->type == MATRIX_TYPE_REAL);

  a = (double*) A->a;
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  u = *res;

  if (!transposed){
    if (!u) u = gmalloc(sizeof(double)*((size_t) m)*((size_t) dim));
    for (i = 0; i < m; i++){
      for (k = 0; k < dim; k++) u[i*dim+k] = 0.;
      for (j = ia[i]; j < ia[i+1]; j++){
	for (k = 0; k < dim; k++) u[i*dim+k] += a[j]*v[ja[j]*dim+k];
      }
    }
    if (res_transposed) dense_transpose(u, m, dim);
  } else {
    if (!u) u = gmalloc(sizeof(double)*((size_t) n)*((size_t) dim));
    for (i = 0; i < n*dim; i++) u[i] = 0.;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	for (k = 0; k < dim; k++) u[ja[j]*dim + k] += a[j]*v[i*dim + k];
      }
    }
    if (res_transposed) dense_transpose(u, n, dim);
  }

  *res = u;


}

static void SparseMatrix_multiply_dense2(SparseMatrix A, double *v, double **res, int dim, int transposed, int res_transposed){
  /* A v^T or A^T v^T where v a dense matrix of second dimension n or m. Real only for now.
     transposed = FALSE: A*V^T, with A dimension m x n, V dimension dim x n, v[i*n+j] gives V[i,j]. Result of dimension m x dim
     transposed = TRUE: A^T*V^T, with A dimension m x n, V dimension dim x m. v[i*m+j] gives V[i,j]. Result of dimension n x dim
  */
  double *u, *rr;
  int i, m, n;
  assert(A->format == FORMAT_CSR);
  assert(A->type == MATRIX_TYPE_REAL);
  u = *res;
  m = A->m;
  n = A->n;

  if (!transposed){
    if (!u) u = gmalloc(sizeof(double)*((size_t)m)*((size_t) dim));
    for (i = 0; i < dim; i++){
      rr = &(u[m*i]);
      SparseMatrix_multiply_vector(A, &(v[n*i]), &rr, transposed);
    }
    if (!res_transposed) dense_transpose(u, dim, m);
  } else {
    if (!u) u = gmalloc(sizeof(double)*((size_t)n)*((size_t)dim));
    for (i = 0; i < dim; i++){
      rr = &(u[n*i]);
      SparseMatrix_multiply_vector(A, &(v[m*i]), &rr, transposed);
    }
    if (!res_transposed) dense_transpose(u, dim, n);
  }

  *res = u;


}



void SparseMatrix_multiply_dense(SparseMatrix A, int ATransposed, double *v, int vTransposed, double **res, int res_transposed, int dim){
  /* depend on value of {ATranspose, vTransposed}, assume res_transposed == FALSE
     {FALSE, FALSE}: A * V, with A dimension m x n, with V of dimension n x dim. v[i*dim+j] gives V[i,j]. Result of dimension m x dim
     {TRUE, FALSE}: A^T * V, with A dimension m x n, with V of dimension m x dim. v[i*dim+j] gives V[i,j]. Result of dimension n x dim
     {FALSE, TRUE}: A*V^T, with A dimension m x n, V dimension dim x n, v[i*n+j] gives V[i,j]. Result of dimension m x dim
     {TRUE, TRUE}: A^T*V^T, with A dimension m x n, V dimension dim x m. v[i*m+j] gives V[i,j]. Result of dimension n x dim
 
     furthermore, if res_transpose d== TRUE, then the result is transposed. Hence if res_transposed == TRUE

     {FALSE, FALSE}: V^T A^T, with A dimension m x n, with V of dimension n x dim. v[i*dim+j] gives V[i,j]. Result of dimension dim x dim
     {TRUE, FALSE}: V^T A, with A dimension m x n, with V of dimension m x dim. v[i*dim+j] gives V[i,j]. Result of dimension dim x n
     {FALSE, TRUE}: V*A^T, with A dimension m x n, V dimension dim x n, v[i*n+j] gives V[i,j]. Result of dimension dim x m
     {TRUE, TRUE}: V A, with A dimension m x n, V dimension dim x m. v[i*m+j] gives V[i,j]. Result of dimension dim x n
 */

  if (!vTransposed) {
    SparseMatrix_multiply_dense1(A, v, res, dim, ATransposed, res_transposed);
  } else {
    SparseMatrix_multiply_dense2(A, v, res, dim, ATransposed, res_transposed);
  }

}



void SparseMatrix_multiply_vector(SparseMatrix A, double *v, double **res, int transposed){
  /* A v or A^T v. Real only for now. */
  int i, j, *ia, *ja, n, m;
  double *a, *u = (void *)0;
  int *ai;
  assert(A->format == FORMAT_CSR);
  assert(A->type == MATRIX_TYPE_REAL || A->type == MATRIX_TYPE_INTEGER);

  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  u = *res;

  switch (A->type){
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    if (v){
      if (!transposed){
	if (!u) u = gmalloc(sizeof(double)*((size_t)m));
	for (i = 0; i < m; i++){
	  u[i] = 0.;
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[i] += a[j]*v[ja[j]];
	  }
	}
      } else {
	if (!u) u = gmalloc(sizeof(double)*((size_t)n));
	for (i = 0; i < n; i++) u[i] = 0.;
	for (i = 0; i < m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[ja[j]] += a[j]*v[i];
	  }
	}
      }
    } else {
      /* v is assumed to be all 1's */
      if (!transposed){
	if (!u) u = gmalloc(sizeof(double)*((size_t)m));
	for (i = 0; i < m; i++){
	  u[i] = 0.;
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[i] += a[j];
	  }
	}
      } else {
	if (!u) u = gmalloc(sizeof(double)*((size_t)n));
	for (i = 0; i < n; i++) u[i] = 0.;
	for (i = 0; i < m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[ja[j]] += a[j];
	  }
	}
      }
    }
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    if (v){
      if (!transposed){
	if (!u) u = gmalloc(sizeof(double)*((size_t)m));
	for (i = 0; i < m; i++){
	  u[i] = 0.;
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[i] += ai[j]*v[ja[j]];
	  }
	}
      } else {
	if (!u) u = gmalloc(sizeof(double)*((size_t)n));
	for (i = 0; i < n; i++) u[i] = 0.;
	for (i = 0; i < m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[ja[j]] += ai[j]*v[i];
	  }
	}
      }
    } else {
      /* v is assumed to be all 1's */
      if (!transposed){
	if (!u) u = gmalloc(sizeof(double)*((size_t)m));
	for (i = 0; i < m; i++){
	  u[i] = 0.;
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[i] += ai[j];
	  }
	}
      } else {
	if (!u) u = gmalloc(sizeof(double)*((size_t)n));
	for (i = 0; i < n; i++) u[i] = 0.;
	for (i = 0; i < m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    u[ja[j]] += ai[j];
	  }
	}
      }
    }
    break;
  default:
    assert(0);
    u = (void *)0;
  }
  *res = u;

}



SparseMatrix SparseMatrix_scaled_by_vector(SparseMatrix A, double *v, int apply_to_row){
  /* A SCALED BY VECOTR V IN ROW/COLUMN. Real only for now. */
  int i, j, *ia, *ja, m;
  double *a;
  assert(A->format == FORMAT_CSR);
  assert(A->type == MATRIX_TYPE_REAL);

  a = (double*) A->a;
  ia = A->ia;
  ja = A->ja;
  m = A->m;


  if (!apply_to_row){
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	a[j] *= v[ja[j]];
      }
    }
  } else {
    for (i = 0; i < m; i++){
      if (v[i] != 0){
	for (j = ia[i]; j < ia[i+1]; j++){
	  a[j] *= v[i];
	}
      }
    }
  }
  return A;

}
SparseMatrix SparseMatrix_multiply_by_scaler(SparseMatrix A, double s){
  /* A scaled by a number */
  int i, j, *ia, m;
  double *a, *b = (void *)0;
  int *ai;
  assert(A->format == FORMAT_CSR);

  switch (A->type){
  case MATRIX_TYPE_INTEGER:
    b = gmalloc(sizeof(double)*A->nz);
    ai = (int*) A->a;
    for (i = 0; i < A->nz; i++) b[i] = ai[i];
    free(A->a);
    A->a = b;
    A->type = MATRIX_TYPE_REAL;
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    ia = A->ia;
    m = A->m;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	a[j] *= s;
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    a = (double*) A->a;
    ia = A->ia;
    m = A->m;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	a[2*j] *= s;
	a[2*j+1] *= s;
      }
    }

    break;
  default:
    fprintf(stderr,"warning: scaling of matrix this type is not supported\n");
  }

  return A;

}


SparseMatrix SparseMatrix_multiply(SparseMatrix A, SparseMatrix B){
  int m;
  SparseMatrix C = (void *)0;
  int *mask = (void *)0;
  int *ia = A->ia, *ja = A->ja, *ib = B->ia, *jb = B->ja, *ic, *jc;
  int i, j, k, jj, type, nz;

  assert(A->format == B->format && A->format == FORMAT_CSR);/* other format not yet supported */

  m = A->m;
  if (A->n != B->m) return (void *)0;
  if (A->type != B->type){

    

    return (void *)0;
  }
  type = A->type;
  
  mask = gmalloc(sizeof(int)*((size_t)(B->n)));
  if (!mask) return (void *)0;

  for (i = 0; i < B->n; i++) mask[i] = -1;

  nz = 0;
  for (i = 0; i < m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      for (k = ib[jj]; k < ib[jj+1]; k++){
	if (mask[jb[k]] != -i - 2){
	  if ((nz+1) <= nz) {

	    

	    return (void *)0;
	  }
	  nz++;
	  mask[jb[k]] = -i - 2;
	}
      }
    }
  }

  C = SparseMatrix_new(m, B->n, nz, type, FORMAT_CSR);
  if (!C) goto RETURN;
  ic = C->ia;
  jc = C->ja;
  
  nz = 0;

  switch (type){
  case MATRIX_TYPE_REAL:
    {
      double *a = (double*) A->a;
      double *b = (double*) B->a;
      double *c = (double*) C->a;
      ic[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (k = ib[jj]; k < ib[jj+1]; k++){
	    if (mask[jb[k]] < ic[i]){
	      mask[jb[k]] = nz;
	      jc[nz] = jb[k];
	      c[nz] = a[j]*b[k];
	      nz++;
	    } else {
	      assert(jc[mask[jb[k]]] == jb[k]);
	      c[mask[jb[k]]] += a[j]*b[k];
	    }
	  }
	}
	ic[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    {
      double *a = (double*) A->a;
      double *b = (double*) B->a;
      double *c = (double*) C->a;
      a = (double*) A->a;
      b = (double*) B->a;
      c = (double*) C->a;
      ic[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (k = ib[jj]; k < ib[jj+1]; k++){
	    if (mask[jb[k]] < ic[i]){
	      mask[jb[k]] = nz;
	      jc[nz] = jb[k];
	      c[2*nz] = a[2*j]*b[2*k] - a[2*j+1]*b[2*k+1];/*real part */
	      c[2*nz+1] = a[2*j]*b[2*k+1] + a[2*j+1]*b[2*k];/*img part */
	      nz++;
	    } else {
	      assert(jc[mask[jb[k]]] == jb[k]);
	      c[2*mask[jb[k]]] += a[2*j]*b[2*k] - a[2*j+1]*b[2*k+1];/*real part */
	      c[2*mask[jb[k]]+1] += a[2*j]*b[2*k+1] + a[2*j+1]*b[2*k];/*img part */
	    }
	  }
	}
	ic[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_INTEGER:
    {
      int *a = (int*) A->a;
      int *b = (int*) B->a;
      int *c = (int*) C->a;
      ic[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (k = ib[jj]; k < ib[jj+1]; k++){
	    if (mask[jb[k]] < ic[i]){
	      mask[jb[k]] = nz;
	      jc[nz] = jb[k];
	      c[nz] = a[j]*b[k];
	      nz++;
	    } else {
	      assert(jc[mask[jb[k]]] == jb[k]);
	      c[mask[jb[k]]] += a[j]*b[k];
	    }
	  }
	}
	ic[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_PATTERN:
    ic[0] = 0;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jj = ja[j];
	for (k = ib[jj]; k < ib[jj+1]; k++){
	  if (mask[jb[k]] < ic[i]){
	    mask[jb[k]] = nz;
	    jc[nz] = jb[k];
	    nz++;
	  } else {
	    assert(jc[mask[jb[k]]] == jb[k]);
	  }
	}
      }
      ic[i+1] = nz;
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
  default:
    SparseMatrix_delete(C);
    C = (void *)0; goto RETURN;
    break;
  }
  
  C->nz = nz;

 RETURN:
  free(mask);
  return C;

}



SparseMatrix SparseMatrix_multiply3(SparseMatrix A, SparseMatrix B, SparseMatrix C){
  int m;
  SparseMatrix D = (void *)0;
  int *mask = (void *)0;
  int *ia = A->ia, *ja = A->ja, *ib = B->ia, *jb = B->ja, *ic = C->ia, *jc = C->ja, *id, *jd;
  int i, j, k, l, ll, jj, type, nz;

  assert(A->format == B->format && A->format == FORMAT_CSR);/* other format not yet supported */

  m = A->m;
  if (A->n != B->m) return (void *)0;
  if (B->n != C->m) return (void *)0;

  if (A->type != B->type || B->type != C->type){

    

    return (void *)0;
  }
  type = A->type;
  
  mask = gmalloc(sizeof(int)*((size_t)(C->n)));
  if (!mask) return (void *)0;

  for (i = 0; i < C->n; i++) mask[i] = -1;

  nz = 0;
  for (i = 0; i < m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      for (l = ib[jj]; l < ib[jj+1]; l++){
	ll = jb[l];
	for (k = ic[ll]; k < ic[ll+1]; k++){
	  if (mask[jc[k]] != -i - 2){
	    if ((nz+1) <= nz) {

	      

	      return (void *)0;
	    }
	    nz++;
	    mask[jc[k]] = -i - 2;
	  }
	}
      }
    }
  }

  D = SparseMatrix_new(m, C->n, nz, type, FORMAT_CSR);
  if (!D) goto RETURN;
  id = D->ia;
  jd = D->ja;
  
  nz = 0;

  switch (type){
  case MATRIX_TYPE_REAL:
    {
      double *a = (double*) A->a;
      double *b = (double*) B->a;
      double *c = (double*) C->a;
      double *d = (double*) D->a;
      id[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (l = ib[jj]; l < ib[jj+1]; l++){
	    ll = jb[l];
	    for (k = ic[ll]; k < ic[ll+1]; k++){
	      if (mask[jc[k]] < id[i]){
		mask[jc[k]] = nz;
		jd[nz] = jc[k];
		d[nz] = a[j]*b[l]*c[k];
		nz++;
	      } else {
		assert(jd[mask[jc[k]]] == jc[k]);
		d[mask[jc[k]]] += a[j]*b[l]*c[k];
	      }
	    }
	  }
	}
	id[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    {
      double *a = (double*) A->a;
      double *b = (double*) B->a;
      double *c = (double*) C->a;
      double *d = (double*) D->a;
      id[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (l = ib[jj]; l < ib[jj+1]; l++){
	    ll = jb[l];
	    for (k = ic[ll]; k < ic[ll+1]; k++){
	      if (mask[jc[k]] < id[i]){
		mask[jc[k]] = nz;
		jd[nz] = jc[k];
		d[2*nz] = (a[2*j]*b[2*l] - a[2*j+1]*b[2*l+1])*c[2*k] 
		  - (a[2*j]*b[2*l+1] + a[2*j+1]*b[2*l])*c[2*k+1];/*real part */
		d[2*nz+1] = (a[2*j]*b[2*l+1] + a[2*j+1]*b[2*l])*c[2*k]
		  + (a[2*j]*b[2*l] - a[2*j+1]*b[2*l+1])*c[2*k+1];/*img part */
		nz++;
	      } else {
		assert(jd[mask[jc[k]]] == jc[k]);
		d[2*mask[jc[k]]] += (a[2*j]*b[2*l] - a[2*j+1]*b[2*l+1])*c[2*k] 
		  - (a[2*j]*b[2*l+1] + a[2*j+1]*b[2*l])*c[2*k+1];/*real part */
		d[2*mask[jc[k]]+1] += (a[2*j]*b[2*l+1] + a[2*j+1]*b[2*l])*c[2*k]
		  + (a[2*j]*b[2*l] - a[2*j+1]*b[2*l+1])*c[2*k+1];/*img part */
	      }
	    }
	  }
	}
	id[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_INTEGER:
    {
      int *a = (int*) A->a;
      int *b = (int*) B->a;
      int *c = (int*) C->a;
      int *d = (int*) D->a;
      id[0] = 0;
      for (i = 0; i < m; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  jj = ja[j];
	  for (l = ib[jj]; l < ib[jj+1]; l++){
	    ll = jb[l];
	    for (k = ic[ll]; k < ic[ll+1]; k++){
	      if (mask[jc[k]] < id[i]){
		mask[jc[k]] = nz;
		jd[nz] = jc[k];
		d[nz] += a[j]*b[l]*c[k];
		nz++;
	      } else {
		assert(jd[mask[jc[k]]] == jc[k]);
		d[mask[jc[k]]] += a[j]*b[l]*c[k];
	      }
	    }
	  }
	}
	id[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_PATTERN:
    id[0] = 0;
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	jj = ja[j];
	for (l = ib[jj]; l < ib[jj+1]; l++){
	  ll = jb[l];
	  for (k = ic[ll]; k < ic[ll+1]; k++){
	    if (mask[jc[k]] < id[i]){
	      mask[jc[k]] = nz;
	      jd[nz] = jc[k];
	      nz++;
	    } else {
	      assert(jd[mask[jc[k]]] == jc[k]);
	    }
	  }
	}
      }
      id[i+1] = nz;
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
  default:
    SparseMatrix_delete(D);
    D = (void *)0; goto RETURN;
    break;
  }
  
  D->nz = nz;

 RETURN:
  free(mask);
  return D;

}

/* For complex matrix:
   if what_to_sum = SUM_REPEATED_REAL_PART, we find entries {i,j,x + i y} and sum the x's if {i,j,Round(y)} are the same
   if what_to_sum = SUM_REPEATED_REAL_PART, we find entries {i,j,x + i y} and sum the y's if {i,j,Round(x)} are the same
   so a matrix like {{1,1,2+3i},{1,2,3+4i},{1,1,5+3i},{1,2,4+5i},{1,2,4+4i}} becomes
   {{1,1,2+5+3i},{1,2,3+4+4i},{1,2,4+5i}}. 

   Really this kind of thing is best handled using a 3D sparse matrix like
   {{{1,1,3},2},{{1,2,4},3},{{1,1,3},5},{{1,2,4},4}}, 
   which is then aggreted into
   {{{1,1,3},2+5},{{1,2,4},3+4},{{1,1,3},5}}
   but unfortunately I do not have such object implemented yet.
   

   For other matrix, what_to_sum = SUM_REPEATED_REAL_PART is the same as what_to_sum = SUM_REPEATED_IMAGINARY_PART
   or what_to_sum = SUM_REPEATED_ALL. In this implementation we assume that
   the {j,y} pairs are dense, so we usea 2D array for hashing 
*/
SparseMatrix SparseMatrix_sum_repeat_entries(SparseMatrix A, int what_to_sum){
  /* sum repeated entries in the same row, i.e., {1,1}->1, {1,1}->2 becomes {1,1}->3 */
  int *ia = A->ia, *ja = A->ja, type = A->type, n = A->n;
  int *mask = (void *)0, nz = 0, i, j, sta;

  if (what_to_sum == SUM_REPEATED_NONE) return A;

  mask = gmalloc(sizeof(int)*((size_t)n));
  for (i = 0; i < n; i++) mask[i] = -1;

  switch (type){
  case MATRIX_TYPE_REAL:
    {
      double *a = (double*) A->a;
      nz = 0;
      sta = ia[0];
      for (i = 0; i < A->m; i++){
	for (j = sta; j < ia[i+1]; j++){
	  if (mask[ja[j]] < ia[i]){
	    ja[nz] = ja[j];
	    a[nz] = a[j];
	    mask[ja[j]] = nz++;
	  } else {
	    assert(ja[mask[ja[j]]] == ja[j]);
	    a[mask[ja[j]]] += a[j];
	  }
	}
	sta = ia[i+1];
	ia[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_COMPLEX:
    {
      double *a = (double*) A->a;
      if (what_to_sum == SUM_REPEATED_ALL){
	nz = 0;
	sta = ia[0];
	for (i = 0; i < A->m; i++){
	  for (j = sta; j < ia[i+1]; j++){
	    if (mask[ja[j]] < ia[i]){
	      ja[nz] = ja[j];
	      a[2*nz] = a[2*j];
	      a[2*nz+1] = a[2*j+1];
	      mask[ja[j]] = nz++;
	    } else {
	      assert(ja[mask[ja[j]]] == ja[j]);
	      a[2*mask[ja[j]]] += a[2*j];
	      a[2*mask[ja[j]]+1] += a[2*j+1];
	    }
	  }
	  sta = ia[i+1];
	  ia[i+1] = nz;
	}
      } else if (what_to_sum == SUM_IMGINARY_KEEP_LAST_REAL){
	/* merge {i,j,R1,I1} and {i,j,R2,I2} into {i,j,R1+R2,I2}*/
	nz = 0;
	sta = ia[0];
	for (i = 0; i < A->m; i++){
	  for (j = sta; j < ia[i+1]; j++){
	    if (mask[ja[j]] < ia[i]){
	      ja[nz] = ja[j];
	      a[2*nz] = a[2*j];
	      a[2*nz+1] = a[2*j+1];
	      mask[ja[j]] = nz++;
	    } else {
	      assert(ja[mask[ja[j]]] == ja[j]);
	      a[2*mask[ja[j]]] += a[2*j];
	      a[2*mask[ja[j]]+1] = a[2*j+1];
	    }
	  }
	  sta = ia[i+1];
	  ia[i+1] = nz;
        }
      } else if (what_to_sum == SUM_REPEATED_REAL_PART){
	int ymin, ymax, id;
	ymax = ymin = a[1];
	nz = 0;
	for (i = 0; i < A->m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    ymax = ((ymax)>((int) a[2*nz+1])?(ymax):((int) a[2*nz+1]));
	    ymin = ((ymin)<((int) a[2*nz+1])?(ymin):((int) a[2*nz+1]));
	    nz++;
	  }	  
	}
	free(mask);
	mask = gmalloc(sizeof(int)*((size_t)n)*((size_t)(ymax-ymin+1)));
	for (i = 0; i < n*(ymax-ymin+1); i++) mask[i] = -1;

	nz = 0;
	sta = ia[0];
	for (i = 0; i < A->m; i++){
	  for (j = sta; j < ia[i+1]; j++){
	    id = ja[j] + ((int)a[2*j+1] - ymin)*n;
	    if (mask[id] < ia[i]){
	      ja[nz] = ja[j];
	      a[2*nz] = a[2*j];
	      a[2*nz+1] = a[2*j+1];
	      mask[id] = nz++;
	    } else {
	      assert(id < n*(ymax-ymin+1));
	      assert(ja[mask[id]] == ja[j]);
	      a[2*mask[id]] += a[2*j];
	      a[2*mask[id]+1] = a[2*j+1];
	    }
	  }
	  sta = ia[i+1];
	  ia[i+1] = nz;
	}
	
      } else if (what_to_sum == SUM_REPEATED_IMAGINARY_PART){
	int xmin, xmax, id;
	xmax = xmin = a[1];
	nz = 0;
	for (i = 0; i < A->m; i++){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    xmax = ((xmax)>((int) a[2*nz])?(xmax):((int) a[2*nz]));
	    xmin = ((xmin)>((int) a[2*nz])?(xmin):((int) a[2*nz]));
	    nz++;
	  }	  
	}
	free(mask);
	mask = gmalloc(sizeof(int)*((size_t)n)*((size_t)(xmax-xmin+1)));
	for (i = 0; i < n*(xmax-xmin+1); i++) mask[i] = -1;

	nz = 0;
	sta = ia[0];
	for (i = 0; i < A->m; i++){
	  for (j = sta; j < ia[i+1]; j++){
	    id = ja[j] + ((int)a[2*j] - xmin)*n;
	    if (mask[id] < ia[i]){
	      ja[nz] = ja[j];
	      a[2*nz] = a[2*j];
	      a[2*nz+1] = a[2*j+1];
	      mask[id] = nz++;
	    } else {
	      assert(ja[mask[id]] == ja[j]);
	      a[2*mask[id]] = a[2*j];
	      a[2*mask[id]+1] += a[2*j+1];
	    }
	  }
	  sta = ia[i+1];
	  ia[i+1] = nz;
	}

      }
    }
    break;
  case MATRIX_TYPE_INTEGER:
    {
      int *a = (int*) A->a;
      nz = 0;
      sta = ia[0];
      for (i = 0; i < A->m; i++){
	for (j = sta; j < ia[i+1]; j++){
	  if (mask[ja[j]] < ia[i]){
	    ja[nz] = ja[j];
	    a[nz] = a[j];
	    mask[ja[j]] = nz++;
	  } else {
	    assert(ja[mask[ja[j]]] == ja[j]);
	    a[mask[ja[j]]] += a[j];
	  }
	}
	sta = ia[i+1];
	ia[i+1] = nz;	
      }
    }
    break;
  case MATRIX_TYPE_PATTERN:
    {
      nz = 0;
      sta = ia[0];
      for (i = 0; i < A->m; i++){
	for (j = sta; j < ia[i+1]; j++){
	  if (mask[ja[j]] < ia[i]){
	    ja[nz] = ja[j];
	    mask[ja[j]] = nz++;
	  } else {
	    assert(ja[mask[ja[j]]] == ja[j]);
	  }
	}
	sta = ia[i+1];
	ia[i+1] = nz;
      }
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
    break;
  default:
    return (void *)0;
    break;
  }
  A->nz = nz;
  free(mask);
  return A;
}

SparseMatrix SparseMatrix_coordinate_form_add_entries(SparseMatrix A, int nentries, int *irn, int *jcn, void *val){
  int nz, nzmax, i;
  
  assert(A->format == FORMAT_COORD);
  if (nentries <= 0) return A;
  nz = A->nz;
  nzmax = A->nzmax;

  if (nz + nentries >= A->nzmax){
    nzmax = nz + nentries;
     nzmax = ((10)>((int) 0.2*nzmax)?(10):((int) 0.2*nzmax)) + nzmax;
    A = SparseMatrix_realloc(A, nzmax);
  }
  memcpy((char*) A->ia + ((size_t)nz)*sizeof(int)/sizeof(char), irn, sizeof(int)*((size_t)nentries));
  memcpy((char*) A->ja + ((size_t)nz)*sizeof(int)/sizeof(char), jcn, sizeof(int)*((size_t)nentries));
  if (A->size) memcpy((char*) A->a + ((size_t)nz)*A->size/sizeof(char), val, A->size*((size_t)nentries));
  for (i = 0; i < nentries; i++) {
    if (irn[i] >= A->m) A->m = irn[i]+1;
    if (jcn[i] >= A->n) A->n = jcn[i]+1;
  }
  A->nz += nentries;
  return A;
}


SparseMatrix SparseMatrix_remove_diagonal(SparseMatrix A){
  int i, j, *ia, *ja, nz, sta;

  if (!A) return A;

  nz = 0;
  ia = A->ia;
  ja = A->ja;
  sta = ia[0];
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] != i){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] != i){
	  ja[nz] = ja[j];
	  a[2*nz] = a[2*j];
	  a[2*nz+1] = a[2*j+1];
	  nz++;
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] != i){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] != i){
	  ja[nz++] = ja[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
  default:
    return (void *)0;
  }

  return A;
}


SparseMatrix SparseMatrix_remove_upper(SparseMatrix A){/* remove diag and upper diag */
  int i, j, *ia, *ja, nz, sta;

  if (!A) return A;

  nz = 0;
  ia = A->ia;
  ja = A->ja;
  sta = ia[0];
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] < i){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] < i){
	  ja[nz] = ja[j];
	  a[2*nz] = a[2*j];
	  a[2*nz+1] = a[2*j+1];
	  nz++;
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] < i){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (ja[j] < i){
	  ja[nz++] = ja[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
  default:
    return (void *)0;
  }

  ((A->property) &=(~(MATRIX_PATTERN_SYMMETRIC)));
  ((A->property) &=(~(MATRIX_SYMMETRIC)));
  ((A->property) &=(~(MATRIX_SKEW)));
  ((A->property) &=(~(MATRIX_HERMITIAN)));
  return A;
}




SparseMatrix SparseMatrix_divide_row_by_degree(SparseMatrix A){
  int i, j, *ia, *ja;
  double deg;

  if (!A) return A;

  ia = A->ia;
  ja = A->ja;
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      deg = ia[i+1] - ia[i];
      for (j = ia[i]; j < ia[i+1]; j++){
	a[j] = a[j]/deg;
      }
    }
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      deg = ia[i+1] - ia[i];
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] != i){
	  a[2*j] = a[2*j]/deg;
	  a[2*j+1] = a[2*j+1]/deg;
	}
      }
    }
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    assert(0);/* this operation would not make sense for int matrix */
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
  default:
    return (void *)0;
  }

  return A;
}


SparseMatrix SparseMatrix_get_real_adjacency_matrix_symmetrized(SparseMatrix A){
  /* symmetric, all entries to 1, diaginal removed */
  int i, *ia, *ja, nz, m, n;
  double *a;
  SparseMatrix B;

  if (!A) return A;
  
  nz = A->nz;
  ia = A->ia;
  ja = A->ja;
  n = A->n;
  m = A->m;

  if (n != m) return (void *)0;

  B = SparseMatrix_new(m, n, nz, MATRIX_TYPE_PATTERN, FORMAT_CSR);

  memcpy(B->ia, ia, sizeof(int)*((size_t)(m+1)));
  memcpy(B->ja, ja, sizeof(int)*((size_t)nz));
  B->nz = A->nz;

  A = SparseMatrix_symmetrize(B, (!(0)));
  SparseMatrix_delete(B);
  A = SparseMatrix_remove_diagonal(A);
  A->a = gmalloc(sizeof(double)*((size_t)(A->nz)));
  a = (double*) A->a;
  for (i = 0; i < A->nz; i++) a[i] = 1.;
  A->type = MATRIX_TYPE_REAL;
  A->size = sizeof(double);
  return A;
}



SparseMatrix SparseMatrix_normalize_to_rowsum1(SparseMatrix A){
  int i, j;
  double sum, *a;

  if (!A) return A;
  if (A->format != FORMAT_CSR && A->type != MATRIX_TYPE_REAL) {

    

    return A;
  }

  a = (double*) A->a;
  for (i = 0; i < A->m; i++){
    sum = 0;
    for (j = A->ia[i]; j < A->ia[i+1]; j++){
      sum += a[j];
    }
    if (sum != 0){
      for (j = A->ia[i]; j < A->ia[i+1]; j++){
	a[j] /= sum;
      }
    }
  }
  return A;
}



SparseMatrix SparseMatrix_normalize_by_row(SparseMatrix A){
  int i, j;
  double max, *a;

  if (!A) return A;
  if (A->format != FORMAT_CSR && A->type != MATRIX_TYPE_REAL) {

    

    return A;
  }

  a = (double*) A->a;
  for (i = 0; i < A->m; i++){
    max = 0;
    for (j = A->ia[i]; j < A->ia[i+1]; j++){
      max = ((((a[j]) >= 0 ? (a[j]) : -(a[j])))>(max)?(((a[j]) >= 0 ? (a[j]) : -(a[j]))):(max));
    }
    if (max != 0){
      for (j = A->ia[i]; j < A->ia[i+1]; j++){
	a[j] /= max;
      }
    }
  }
  return A;
}


SparseMatrix SparseMatrix_to_complex(SparseMatrix A){
  int i, *ia, *ja;
  
  if (!A) return A;
  if (A->format != FORMAT_CSR) {

    

    return A;
  }

  ia = A->ia;
  ja = A->ja;
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    int nz = A->nz;
    A->a = a = grealloc(a, 2*sizeof(double)*nz);
    for (i = nz - 1; i >= 0; i--){
      a[2*i] = a[i];
      a[2*i - 1] = 0;
    }
    A->type = MATRIX_TYPE_COMPLEX;
    A->size = 2*sizeof(double);
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    int nz = A->nz;
    double *aa = A->a = gmalloc(2*sizeof(double)*nz);
    for (i = nz - 1; i >= 0; i--){
      aa[2*i] = (double) a[i];
      aa[2*i - 1] = 0;
    }
    A->type = MATRIX_TYPE_COMPLEX;
    A->size = 2*sizeof(double);
    free(a);
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
  default:
    return (void *)0;
  }

  return A;
}


SparseMatrix SparseMatrix_apply_fun(SparseMatrix A, double (*fun)(double x)){
  int i, j;
  double *a;


  if (!A) return A;
  if (A->format != FORMAT_CSR && A->type != MATRIX_TYPE_REAL) {

    

    return A;
  }


  a = (double*) A->a;
  for (i = 0; i < A->m; i++){
    for (j = A->ia[i]; j < A->ia[i+1]; j++){
      a[j] = fun(a[j]);
    }
  }
  return A;
}

SparseMatrix SparseMatrix_apply_fun_general(SparseMatrix A, void (*fun)(int i, int j, int n, double *x)){
  int i, j;
  double *a;
  int len = 1;

  if (!A) return A;
  if (A->format != FORMAT_CSR || (A->type != MATRIX_TYPE_REAL&&A->type != MATRIX_TYPE_COMPLEX)) {

    

    return A;
  }
  if (A->type == MATRIX_TYPE_COMPLEX) len = 2;

  a = (double*) A->a;
  for (i = 0; i < A->m; i++){
    for (j = A->ia[i]; j < A->ia[i+1]; j++){
      fun(i, A->ja[j], len, &a[len*j]);
    }
  }
  return A;
}


SparseMatrix SparseMatrix_crop(SparseMatrix A, double epsilon){
  int i, j, *ia, *ja, nz, sta;

  if (!A) return A;

  nz = 0;
  ia = A->ia;
  ja = A->ja;
  sta = ia[0];
  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (((a[j]) >= 0 ? (a[j]) : -(a[j])) > epsilon){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (sqrt(a[2*j]*a[2*j]+a[2*j+1]*a[2*j+1]) > epsilon){
	  ja[nz] = ja[j];
	  a[2*nz] = a[2*j];
	  a[2*nz+1] = a[2*j+1];
	  nz++;
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    for (i = 0; i < A->m; i++){
      for (j = sta; j < ia[i+1]; j++){
	if (((a[j]) >= 0 ? (a[j]) : -(a[j])) > epsilon){
	  ja[nz] = ja[j];
	  a[nz++] = a[j];
	}
      }
      sta = ia[i+1];
      ia[i+1] = nz;
    }
    A->nz = nz;
    break;
  }
  case MATRIX_TYPE_PATTERN:{
    break;
  }
  case MATRIX_TYPE_UNKNOWN:
    return (void *)0;
  default:
    return (void *)0;
  }

  return A;
}

SparseMatrix SparseMatrix_copy(SparseMatrix A){
  SparseMatrix B;
  if (!A) return A;
  B = SparseMatrix_new(A->m, A->n, A->nz, A->type, A->format);
  memcpy(B->ia, A->ia, sizeof(int)*((size_t)(A->m+1)));
  memcpy(B->ja, A->ja, sizeof(int)*((size_t)(A->ia[A->m])));
  if (A->a) memcpy(B->a, A->a, A->size*((size_t)A->nz));
  B->property = A->property;
  B->nz = A->nz;
  return B;
}

int SparseMatrix_has_diagonal(SparseMatrix A){

  int i, j, m = A->m, *ia = A->ia, *ja = A->ja;

  for (i = 0; i < m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      if (i == ja[j]) return (!(0));
    }
  }
  return (0);
}

void SparseMatrix_level_sets_internal(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask){
  /* mask is assumed to be initialized to negative if provided.
     . On exit, mask = levels for visited nodes (1 for root, 2 for its neighbors, etc), 
     . unless reinitialize_mask = TRUE, in which case mask = -1.
     khops: max number of hops allowed. If khops < 0, no limit is applied.
     A: the graph, undirected
     root: starting node
     nlevel: max distance to root from any node (in the connected comp)
     levelset_ptr, levelset: the level sets
   */
  int i, j, sta = 0, sto = 1, nz, ii;
  int m = A->m, *ia = A->ia, *ja = A->ja;

  if (!(*levelset_ptr)) *levelset_ptr = gmalloc(sizeof(int)*((size_t)(m+2)));
  if (!(*levelset)) *levelset = gmalloc(sizeof(int)*((size_t)m));
  if (!(*mask)) {
    *mask = malloc(sizeof(int)*((size_t)m));
    for (i = 0; i < m; i++) (*mask)[i] = UNMASKED;
  }

  *nlevel = 0;
  assert(root >= 0 && root < m);
  (*levelset_ptr)[0] = 0;
  (*levelset_ptr)[1] = 1;
  (*levelset)[0] = root;
  (*mask)[root] = 1;
  *nlevel = 1;
  nz = 1;
  sta = 0; sto = 1;
  while (sto > sta && (khops < 0 || *nlevel <= khops)){
    for (i = sta; i < sto; i++){
      ii = (*levelset)[i];
      for (j = ia[ii]; j < ia[ii+1]; j++){
	if (ii == ja[j]) continue;
	if ((*mask)[ja[j]] < 0){
	  (*levelset)[nz++] = ja[j];
	  (*mask)[ja[j]] = *nlevel + 1;
	}
      }
    }
    (*levelset_ptr)[++(*nlevel)] = nz;
    sta = sto;
    sto = nz;
  }
  if (khops < 0 || *nlevel <= khops){
    (*nlevel)--;
  }
  if (reinitialize_mask) for (i = 0; i < (*levelset_ptr)[*nlevel]; i++) (*mask)[(*levelset)[i]] = UNMASKED;
}

void SparseMatrix_level_sets(SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask){

  int khops = -1;

  return SparseMatrix_level_sets_internal(khops, A, root, nlevel, levelset_ptr, levelset, mask, reinitialize_mask);

}
void SparseMatrix_level_sets_khops(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask){

  return SparseMatrix_level_sets_internal(khops, A, root, nlevel, levelset_ptr, levelset, mask, reinitialize_mask);

}

void SparseMatrix_weakly_connected_components(SparseMatrix A0, int *ncomp, int **comps, int **comps_ptr){
  SparseMatrix A = A0;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0, nlevel;
  int m = A->m, i, nn;

  if (!SparseMatrix_is_symmetric(A, (!(0)))){
    A = SparseMatrix_symmetrize(A, (!(0)));
  }
  if (!(*comps_ptr)) *comps_ptr = gmalloc(sizeof(int)*((size_t)(m+1)));

  *ncomp = 0;
  (*comps_ptr)[0] = 0;
  for (i = 0; i < m; i++){
    if (i == 0 || mask[i] < 0) {
      SparseMatrix_level_sets(A, i, &nlevel, &levelset_ptr, &levelset, &mask, (0));
      if (i == 0) *comps = levelset;
      nn = levelset_ptr[nlevel];
      levelset += nn;
      (*comps_ptr)[(*ncomp)+1] = (*comps_ptr)[(*ncomp)] + nn;
      (*ncomp)++;
    }
    
  }
  if (A != A0) SparseMatrix_delete(A);
  if (levelset_ptr) free(levelset_ptr);

  free(mask);
}



struct nodedata_struct {
  double dist;/* distance to root */
  int id;/*node id */
};
typedef struct nodedata_struct* nodedata;

static int cmp(void*i, void*j){
  nodedata d1, d2;

  d1 = (nodedata) i;
  d2 = (nodedata) j;
  if (d1->dist > d2->dist){
    return 1;
  } else if (d1->dist == d2->dist){
    return 0;
  } else {
    return -1;
  }
}

static int Dijkstra_internal(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max, int *mask){
  /* Find the shortest path distance of all nodes to root. If khops >= 0, the shortest ath is of distance <= khops,

     A: the nxn connectivity matrix. Entries are assumed to be nonnegative. Absolute value will be taken if 
     .  entry value is negative.
     dist: length n. On on exit contain the distance from root to every other node. dist[root] = 0. dist[i] = distance from root to node i.
     .     if the graph is disconnetced, unreachable node have a distance -1.
     .     note: ||root - list[i]|| =!= dist[i] !!!, instead, ||root - list[i]|| == dist[list[i]]
     nlist: number of nodes visited
     list: length n. the list of node in order of their extraction from the heap. 
     .     The distance from root to last in the list should be the maximum
     dist_max: the maximum distance, should be realized at node list[nlist-1].
     mask: if NULL, not used. Othewise, only nodes i with mask[i] > 0 will be considered
     return: 0 if every node is reachable. -1 if not */

  int m = A->m, i, j, jj, *ia = A->ia, *ja = A->ja, heap_id;
  BinaryHeap h;
  double *a = (void *)0, *aa;
  int *ai;
  nodedata ndata, ndata_min;
  enum {UNVISITED = -2, FINISHED = -1};
  int *heap_ids; /* node ID to heap ID array. Initialised to UNVISITED. 
		   Set to FINISHED after extracted as min from heap */
  int found = 0;

  assert(SparseMatrix_is_symmetric(A, (!(0))));

  assert(m == A->n);

  switch (A->type){
  case MATRIX_TYPE_COMPLEX:
    aa = (double*) A->a;
    a = gmalloc(sizeof(double)*((size_t)(A->nz)));
    for (i = 0; i < A->nz; i++) a[i] = aa[i*2];
    break;
  case MATRIX_TYPE_REAL:
    a = (double*) A->a;
    break;
  case MATRIX_TYPE_INTEGER:
    ai = (int*) A->a;
    a = gmalloc(sizeof(double)*((size_t)(A->nz)));
    for (i = 0; i < A->nz; i++) a[i] = (double) ai[i];
    break;
  case MATRIX_TYPE_PATTERN:
    a = gmalloc(sizeof(double)*((size_t)A->nz));
    for (i = 0; i < A->nz; i++) a[i] = 1.;
    break;
  default:
    assert(0);/* no such matrix type */
  }

  heap_ids = gmalloc(sizeof(int)*((size_t)m));
  for (i = 0; i < m; i++) {
    dist[i] = -1;
    heap_ids[i] = UNVISITED;
  }

  h = BinaryHeap_new(cmp);
  assert(h);

  /* add root as the first item in the heap */
  ndata = gmalloc(sizeof(struct nodedata_struct));
  ndata->dist = 0;
  ndata->id = root;
  heap_ids[root] = BinaryHeap_insert(h, ndata);
  
  assert(heap_ids[root] >= 0);/* by design heap ID from BinaryHeap_insert >=0*/

  while ((ndata_min = BinaryHeap_extract_min(h))){
    i = ndata_min->id;
    dist[i] = ndata_min->dist;
    list[found++] = i;
    heap_ids[i] = FINISHED;
    //fprintf(stderr," =================\n min extracted is id=%d, dist=%f\n",i, ndata_min->dist);
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      heap_id = heap_ids[jj];

      if (jj == i || heap_id == FINISHED || (mask && mask[jj] < 0)) continue;

      if (heap_id == UNVISITED){
	ndata = gmalloc(sizeof(struct nodedata_struct));
	ndata->dist = ((a[j]) >= 0 ? (a[j]) : -(a[j])) + ndata_min->dist;
	ndata->id = jj;
	heap_ids[jj] = BinaryHeap_insert(h, ndata);
	//fprintf(stderr," set neighbor id=%d, dist=%f, hid = %d, a[%d]=%f, dist=%f\n",jj, ndata->dist, heap_ids[jj], jj, a[j], ndata->dist);

      } else {
	ndata = BinaryHeap_get_item(h, heap_id);
	ndata->dist = ((ndata->dist)<(((a[j]) >= 0 ? (a[j]) : -(a[j])) + ndata_min->dist)?(ndata->dist):(((a[j]) >= 0 ? (a[j]) : -(a[j])) + ndata_min->dist));
	assert(ndata->id == jj);
	BinaryHeap_reset(h, heap_id, ndata); 
	//fprintf(stderr," reset neighbor id=%d, dist=%f, hid = %d, a[%d]=%f, dist=%f\n",jj, ndata->dist,heap_id, jj, a[j], ndata->dist);
     }
    }
    free(ndata_min);
  }
  *nlist = found;
  *dist_max = dist[i];


  BinaryHeap_delete(h, free);
  free(heap_ids);
  if (a && a != A->a) free(a);
  if (found == m || mask){
    return 0;
  } else {
    return -1;
  }
}

static int Dijkstra(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max){
  return Dijkstra_internal(A, root, dist, nlist, list, dist_max, (void *)0);
}

static int Dijkstra_masked(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max, int *mask){
  /* this makes the algorithm only consider nodes that are masked.
     nodes are masked as 1, 2, ..., mask_max, which is (the number of hops from root)+1.
     Only paths consists of nodes that are masked are allowed. */
     
  return Dijkstra_internal(A, root, dist, nlist, list, dist_max, mask);
}

double SparseMatrix_pseudo_diameter_weighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ){
  /* weighted graph. But still assume to be undirected. unsymmetric matrix ill be symmetrized */
  SparseMatrix A = A0;
  int m = A->m, i, *list = (void *)0, nlist;
  int flag;
  double *dist = (void *)0, dist_max = -1, dist0 = -1;
  int roots[5], iroots, end11, end22;
 
  if (!SparseMatrix_is_symmetric(A, (!(0)))){
    A = SparseMatrix_symmetrize(A, (!(0)));
  }
  assert(m == A->n);

  dist = gmalloc(sizeof(double)*((size_t)m));
  list = gmalloc(sizeof(int)*((size_t)m));
  nlist = 1;
  list[nlist-1] = root;

  assert(SparseMatrix_is_symmetric(A, (!(0))));

  do {
    dist0 = dist_max;
    root = list[nlist - 1];
    flag = Dijkstra(A, root, dist, &nlist, list, &dist_max);
    //fprintf(stderr,"after Dijkstra, {%d,%d}-%f\n",root, list[nlist-1], dist_max);
    assert(dist[list[nlist-1]] == dist_max);
    assert(root == list[0]);
    assert(nlist > 0);
  } while (dist_max > dist0);

  *connectedQ = (!flag);
  assert((dist_max - dist0)/((1)>(((((dist0) >= 0 ? (dist0) : -(dist0)))>(((dist_max) >= 0 ? (dist_max) : -(dist_max)))?(((dist0) >= 0 ? (dist0) : -(dist0))):(((dist_max) >= 0 ? (dist_max) : -(dist_max)))))?(1):(((((dist0) >= 0 ? (dist0) : -(dist0)))>(((dist_max) >= 0 ? (dist_max) : -(dist_max)))?(((dist0) >= 0 ? (dist0) : -(dist0))):(((dist_max) >= 0 ? (dist_max) : -(dist_max)))))) < 1.e-10);

  *end1 = root;
  *end2 = list[nlist-1];
  //fprintf(stderr,"after search for diameter, diam = %f, ends = {%d,%d}\n", dist_max, *end1, *end2);

  if (aggressive){
    iroots = 0;
    for (i = ((0)>(nlist - 6)?(0):(nlist - 6)); i < nlist - 1; i++){
      roots[iroots++] = list[i];
    }
    for (i = 0; i < iroots; i++){
      root = roots[i];
      dist0 = dist_max;
      fprintf(stderr,"search for diameter again from root=%d\n", root);
      dist_max = SparseMatrix_pseudo_diameter_weighted(A, root, (0), &end11, &end22, connectedQ);
      if (dist_max > dist0){
	*end1 = end11; *end2 = end22;
      } else {
	dist_max = dist0;
      }
    }
    fprintf(stderr,"after aggressive search for diameter, diam = %f, ends = {%d,%d}\n", dist_max, *end1, *end2);
  }

  free(dist);
  free(list);

  if (A != A0) SparseMatrix_delete(A);
  return dist_max;

}

double SparseMatrix_pseudo_diameter_unweighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ){
  /* assume unit edge length! unsymmetric matrix ill be symmetrized */
  SparseMatrix A = A0;
  int m = A->m, i;
  int nlevel;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0;
  int nlevel0 = 0;
  int roots[5], iroots, enda, endb;

  if (!SparseMatrix_is_symmetric(A, (!(0)))){
    A = SparseMatrix_symmetrize(A, (!(0)));
  }

  assert(SparseMatrix_is_symmetric(A, (!(0))));

  SparseMatrix_level_sets(A, root, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
  //  fprintf(stderr,"after level set, {%d,%d}=%d\n",levelset[0], levelset[levelset_ptr[nlevel]-1], nlevel);

  *connectedQ = (levelset_ptr[nlevel] == m);
  while (nlevel0 < nlevel){
    nlevel0 = nlevel;
    root = levelset[levelset_ptr[nlevel] - 1];
    SparseMatrix_level_sets(A, root, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
    //fprintf(stderr,"after level set, {%d,%d}=%d\n",levelset[0], levelset[levelset_ptr[nlevel]-1], nlevel);
  }
  *end1 = levelset[0];
  *end2 = levelset[levelset_ptr[nlevel]-1];

  if (aggressive){
    nlevel0 = nlevel;
    iroots = 0;
    for (i = levelset_ptr[nlevel-1]; i < ((levelset_ptr[nlevel])<(levelset_ptr[nlevel-1]+5)?(levelset_ptr[nlevel]):(levelset_ptr[nlevel-1]+5)); i++){
      iroots++;
      roots[i - levelset_ptr[nlevel-1]] = levelset[i];
    }
    for (i = 0; i < iroots; i++){
      root = roots[i];
      nlevel = (int) SparseMatrix_pseudo_diameter_unweighted(A, root, (0), &enda, &endb, connectedQ);
      if (nlevel > nlevel0) {
	nlevel0 = nlevel;
	*end1 = enda;
	*end2 = endb;
      }
    }
  }

  free(levelset_ptr);
  free(levelset);
  free(mask);
  if (A != A0) SparseMatrix_delete(A);
  return (double) nlevel0 - 1;
}

double SparseMatrix_pseudo_diameter_only(SparseMatrix A){
  int end1, end2, connectedQ;
  return SparseMatrix_pseudo_diameter_unweighted(A, 0, (0), &end1, &end2, &connectedQ);
}

int SparseMatrix_connectedQ(SparseMatrix A0){
  int root = 0, nlevel, *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0, connected;
  SparseMatrix A = A0;

  if (!SparseMatrix_is_symmetric(A, (!(0)))){
    if (A->m != A->n) return (0);
    A = SparseMatrix_symmetrize(A, (!(0)));
  }

  SparseMatrix_level_sets(A, root, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
  connected = (levelset_ptr[nlevel] == A->m);

  free(levelset_ptr);
  free(levelset);
  free(mask);
  if (A != A0) SparseMatrix_delete(A);

  return connected;
}


void SparseMatrix_decompose_to_supervariables(SparseMatrix A, int *ncluster, int **cluster, int **clusterp){
  /* nodes for a super variable if they share exactly the same neighbors. This is know as modules in graph theory.
     We work on columns only and columns with the same pattern are grouped as a super variable
   */
  int *ia = A->ia, *ja = A->ja, n = A->n, m = A->m;
  int *super = (void *)0, *nsuper = (void *)0, i, j, *mask = (void *)0, isup, *newmap, isuper;

  super = gmalloc(sizeof(int)*((size_t)(n)));
  nsuper = gmalloc(sizeof(int)*((size_t)(n+1)));
  mask = gmalloc(sizeof(int)*((size_t)n));
  newmap = gmalloc(sizeof(int)*((size_t)n));
  nsuper++;

  isup = 0;
  for (i = 0; i < n; i++) super[i] = isup;/* every node belongs to super variable 0 by default */
  nsuper[0] = n;
  for (i = 0; i < n; i++) mask[i] = -1;
  isup++;

  for (i = 0; i < m; i++){

    
    

    for (j = ia[i]; j < ia[i+1]; j++){
      isuper = super[ja[j]];
      nsuper[isuper]--;/* those entries will move to a different super vars*/
    }
    for (j = ia[i]; j < ia[i+1]; j++){
      isuper = super[ja[j]];
      if (mask[isuper] < i){
	mask[isuper] = i;
	if (nsuper[isuper] == 0){/* all nodes in the isuper group exist in this row */

	  

	  nsuper[isuper] = 1;
	  newmap[isuper] = isuper;
	} else {
	  newmap[isuper] = isup;
	  nsuper[isup] = 1;

	  

	  super[ja[j]] = isup++;
	}
      } else {

	

	super[ja[j]] = newmap[isuper];
	nsuper[newmap[isuper]]++;
      }
    }

    
    
      

  }

  
    
  


  

  /* now accumulate super nodes */
  nsuper--;
  nsuper[0] = 0;
  for (i = 0; i < isup; i++) nsuper[i+1] += nsuper[i];

  *cluster = newmap;
  for (i = 0; i < n; i++){
    isuper = super[i];
    (*cluster)[nsuper[isuper]++] = i;
  }
  for (i = isup; i > 0; i--) nsuper[i] = nsuper[i-1];
  nsuper[0] = 0;
  *clusterp = nsuper;
  *ncluster = isup;


  
    
    
      
    
    
  
  


  free(mask);
  free(super);

}

SparseMatrix SparseMatrix_get_augmented(SparseMatrix A){
  /* convert matrix A to an augmente dmatrix {{0,A},{A^T,0}} */
  int *irn = (void *)0, *jcn = (void *)0;
  void *val = (void *)0;
  int nz = A->nz, type = A->type;
  int m = A->m, n = A->n, i, j;
  SparseMatrix B = (void *)0;
  if (!A) return (void *)0;
  if (nz > 0){
    irn = gmalloc(sizeof(int)*((size_t)nz)*2);
    jcn = gmalloc(sizeof(int)*((size_t)nz)*2);
  }

  if (A->a){
    assert(A->size != 0 && nz > 0);
    val = gmalloc(A->size*2*((size_t)nz));
    memcpy(val, A->a, A->size*((size_t)nz));
    memcpy((void*)(((char*) val) + ((size_t)nz)*A->size), A->a, A->size*((size_t)nz));
  }

  nz = 0;
  for (i = 0; i < m; i++){
    for (j = (A->ia)[i]; j <  (A->ia)[i+1]; j++){
      irn[nz] = i;
      jcn[nz++] = (A->ja)[j] + m;
    }
  }
  for (i = 0; i < m; i++){
    for (j = (A->ia)[i]; j <  (A->ia)[i+1]; j++){
      jcn[nz] = i;
      irn[nz++] = (A->ja)[j] + m;
    }
  }

  B = SparseMatrix_from_coordinate_arrays(nz, m + n, m + n, irn, jcn, val, type, A->size);
  (((B)->property)=(((B)->property)|(MATRIX_SYMMETRIC)));
  (((B)->property)=(((B)->property)|(MATRIX_PATTERN_SYMMETRIC)));
  if (irn) free(irn);
  if (jcn) free(jcn);
  if (val) free(val);
  return B;

}

SparseMatrix SparseMatrix_to_square_matrix(SparseMatrix A, int bipartite_options){
  SparseMatrix B;
  switch (bipartite_options){
  case BIPARTITE_RECT:
    if (A->m == A->n) return A;
    break;
  case BIPARTITE_PATTERN_UNSYM:
    if (A->m == A->n && SparseMatrix_is_symmetric(A, (!(0)))) return A;
    break;
  case BIPARTITE_UNSYM:
    if (A->m == A->n && SparseMatrix_is_symmetric(A, (0))) return A;
    break;
  case BIPARTITE_ALWAYS:
    break;
  default:
    assert(0);
  }
  B = SparseMatrix_get_augmented(A);
  SparseMatrix_delete(A);
  return B;
}

SparseMatrix SparseMatrix_get_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices){
  /* get the submatrix from row/columns indices[0,...,l-1]. 
     row rindices[i] will be the new row i
     column cindices[i] will be the new column i.
     if rindices = NULL, it is assume that 1 -- nrow is needed. Same for cindices/ncol.
   */
  int nz = 0, i, j, *irn, *jcn, *ia = A->ia, *ja = A->ja, m = A->m, n = A->n;
  int *cmask, *rmask;
  void *v = (void *)0;
  SparseMatrix B = (void *)0;
  int irow = 0, icol = 0;

  if (nrow <= 0 || ncol <= 0) return (void *)0;

  

  rmask = gmalloc(sizeof(int)*((size_t)m));
  cmask = gmalloc(sizeof(int)*((size_t)n));
  for (i = 0; i < m; i++) rmask[i] = -1;
  for (i = 0; i < n; i++) cmask[i] = -1;

  if (rindices){
    for (i = 0; i < nrow; i++) {
      if (rindices[i] >= 0 && rindices[i] < m){
	rmask[rindices[i]] = irow++;
      }
    }
  } else {
    for (i = 0; i < nrow; i++) {
      rmask[i] = irow++;
    }
  }

  if (cindices){
    for (i = 0; i < ncol; i++) {
      if (cindices[i] >= 0 && cindices[i] < n){
	cmask[cindices[i]] = icol++;
      }
    }
  } else {
    for (i = 0; i < ncol; i++) {
      cmask[i] = icol++;
    }
  }

  for (i = 0; i < m; i++){
    if (rmask[i] < 0) continue;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (cmask[ja[j]] < 0) continue;
      nz++;
    }
  }


  switch (A->type){
  case MATRIX_TYPE_REAL:{
    double *a = (double*) A->a;
    double *val;
    irn = gmalloc(sizeof(int)*((size_t)nz));
    jcn = gmalloc(sizeof(int)*((size_t)nz));
    val = gmalloc(sizeof(double)*((size_t)nz));

    nz = 0;
    for (i = 0; i < m; i++){
      if (rmask[i] < 0) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (cmask[ja[j]] < 0) continue;
	irn[nz] = rmask[i];
	jcn[nz] = cmask[ja[j]];
	val[nz++] = a[j];
      }
    }
    v = (void*) val;
    break;
  }
  case MATRIX_TYPE_COMPLEX:{
    double *a = (double*) A->a;
    double *val;

    irn = gmalloc(sizeof(int)*((size_t)nz));
    jcn = gmalloc(sizeof(int)*((size_t)nz));
    val = gmalloc(sizeof(double)*2*((size_t)nz));

    nz = 0;
    for (i = 0; i < m; i++){
      if (rmask[i] < 0) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (cmask[ja[j]] < 0) continue;
	irn[nz] = rmask[i];
	jcn[nz] = cmask[ja[j]];
	val[2*nz] = a[2*j];
	val[2*nz+1] = a[2*j+1];
	nz++;
      }
    }
    v = (void*) val;
    break;
  }
  case MATRIX_TYPE_INTEGER:{
    int *a = (int*) A->a;
    int *val;

    irn = gmalloc(sizeof(int)*((size_t)nz));
    jcn = gmalloc(sizeof(int)*((size_t)nz));
    val = gmalloc(sizeof(int)*((size_t)nz));

    nz = 0;
    for (i = 0; i < m; i++){
      if (rmask[i] < 0) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (cmask[ja[j]] < 0) continue;
	irn[nz] = rmask[i];
	jcn[nz] = cmask[ja[j]];
	val[nz] = a[j];
	nz++;
      }
    }
    v = (void*) val;
    break;
  }
  case MATRIX_TYPE_PATTERN:
    irn = gmalloc(sizeof(int)*((size_t)nz));
    jcn = gmalloc(sizeof(int)*((size_t)nz));
    nz = 0;
     for (i = 0; i < m; i++){
      if (rmask[i] < 0) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (cmask[ja[j]] < 0) continue;
	irn[nz] = rmask[i];
	jcn[nz++] = cmask[ja[j]];
      }
    }
    break;
  case MATRIX_TYPE_UNKNOWN:
    free(rmask);
    free(cmask);
    return (void *)0;
  default:
    free(rmask);
    free(cmask);
    return (void *)0;
  }

  B = SparseMatrix_from_coordinate_arrays(nz, nrow, ncol, irn, jcn, v, A->type, A->size);
  free(cmask);
  free(rmask);
  free(irn);
  free(jcn);
  if (v) free(v);


  return B;

}

SparseMatrix SparseMatrix_exclude_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices){
  /* get a submatrix by excluding rows and columns */
  int *r, *c, nr, nc, i;
  SparseMatrix B;

  if (nrow <= 0 && ncol <= 0) return A;

  r = gmalloc(sizeof(int)*((size_t)A->m));
  c = gmalloc(sizeof(int)*((size_t)A->n));

  for (i = 0; i < A->m; i++) r[i] = i;
  for (i = 0; i < A->n; i++) c[i] = i;
  for (i = 0; i < nrow; i++) {
    if (rindices[i] >= 0 && rindices[i] < A->m){
      r[rindices[i]] = -1;
    }
  }
  for (i = 0; i < ncol; i++) {
    if (cindices[i] >= 0 && cindices[i] < A->n){
      c[cindices[i]] = -1;
    }
  }

  nr = nc = 0;
  for (i = 0; i < A->m; i++) {
    if (r[i] > 0) r[nr++] = r[i];
  }
  for (i = 0; i < A->n; i++) {
    if (c[i] > 0) c[nc++] = c[i];
  }

  B = SparseMatrix_get_submatrix(A, nr, nc, r, c);

  free(r);
  free(c);
  return B;

}

SparseMatrix SparseMatrix_largest_component(SparseMatrix A){
  SparseMatrix B;
  int ncomp;
  int *comps = (void *)0;
  int *comps_ptr = (void *)0;
  int i;
  int nmax, imax = 0;

  if (!A) return (void *)0;
  A = SparseMatrix_to_square_matrix(A, BIPARTITE_RECT);
  SparseMatrix_weakly_connected_components(A, &ncomp, &comps, &comps_ptr);
  if (ncomp == 1) {
    B = A;
  } else {
    nmax = 0;
    for (i = 0; i < ncomp; i++){
      if (nmax < comps_ptr[i+1] - comps_ptr[i]){
	nmax = comps_ptr[i+1] - comps_ptr[i];
	imax = i;
      }
    }
    B = SparseMatrix_get_submatrix(A, nmax, nmax, &comps[comps_ptr[imax]], &comps[comps_ptr[imax]]);
  }
  free(comps);
  free(comps_ptr);
  return B;


}

SparseMatrix SparseMatrix_delete_sparse_columns(SparseMatrix A, int threshold, int **new2old, int *nnew, int inplace){
  /* delete sparse columns of threshold or less entries in A. After than number of columns will be nnew, and 
     the mapping from new matrix column to old matrix column is new2old.
     On entry, if new2old is NULL, it is allocated.
  */
  SparseMatrix B;
  int *ia, *ja;
  int *old2new;
  int i;
  old2new = gmalloc(sizeof(int)*((size_t)A->n));
  for (i = 0; i < A->n; i++) old2new[i] = -1;

  *nnew = 0;
  B = SparseMatrix_transpose(A);
  ia = B->ia; ja = B->ja;
  for (i = 0; i < B->m; i++){
    if (ia[i+1] > ia[i] + threshold){
      (*nnew)++;
    }
  }
  if (!(*new2old)) *new2old = gmalloc(sizeof(int)*((size_t)(*nnew)));

  *nnew = 0;
  for (i = 0; i < B->m; i++){
    if (ia[i+1] > ia[i] + threshold){
      (*new2old)[*nnew] = i;
      old2new[i] = *nnew;
      (*nnew)++;
    }
  }
  SparseMatrix_delete(B);

  if (inplace){
    B = A;
  } else {
    B = SparseMatrix_copy(A);
  }
  ia = B->ia; ja = B->ja;
  for (i = 0; i < ia[B->m]; i++){
    assert(old2new[ja[i]] >= 0);
    ja[i] = old2new[ja[i]];
  }
  B->n = *nnew;

  free(old2new);
  return B;
  

}

SparseMatrix SparseMatrix_delete_empty_columns(SparseMatrix A, int **new2old, int *nnew, int inplace){
  return SparseMatrix_delete_sparse_columns(A, 0, new2old, nnew, inplace);
}

SparseMatrix SparseMatrix_set_entries_to_real_one(SparseMatrix A){
  double *a;
  int i;

  if (A->a) free(A->a);
  A->a = gmalloc(sizeof(double)*((size_t)A->nz));
  a = (double*) (A->a);
  for (i = 0; i < A->nz; i++) a[i] = 1.;
  A->type = MATRIX_TYPE_REAL;
  A->size = sizeof(double);
  return A;

}

SparseMatrix SparseMatrix_complement(SparseMatrix A, int undirected){
  /* find the complement graph A^c, such that {i,h}\in E(A_c) iff {i,j} \notin E(A). Only structural matrix is returned. */
  SparseMatrix B = A;
  int *ia, *ja;
  int m = A->m, n = A->n;
  int *mask, nz = 0;
  int *irn, *jcn;
  int i, j;

  if (undirected) B = SparseMatrix_symmetrize(A, (!(0)));
  assert(m == n);

  ia = B->ia; ja = B->ja;
  mask = gmalloc(sizeof(int)*((size_t)n));
  irn = gmalloc(sizeof(int)*(((size_t)n)*((size_t)n) - ((size_t)A->nz)));
  jcn = gmalloc(sizeof(int)*(((size_t)n)*((size_t)n) - ((size_t)A->nz)));

  for (i = 0; i < n; i++){
    mask[i] = -1;
  }

  for (i = 0; i < n; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      mask[ja[j]] = i;
    }
    for (j = 0; j < n; j++){
      if (mask[j] != i){
	irn[nz] = i;
	jcn[nz++] = j;
      }
    }
  }

  if (B != A) SparseMatrix_delete(B);
  B = SparseMatrix_from_coordinate_arrays(nz, m, n, irn, jcn, (void *)0, MATRIX_TYPE_PATTERN, 0);
  free(irn);
  free(jcn);
  return B;
}

int SparseMatrix_k_centers(SparseMatrix D0, int weighted, int K, int root, int **centers, int centering, double **dist0){
  /*
    Input:
    D: the graph. If weighted, the entry values is used.
    weighted: whether to treat the graph as weighted
    K: the number of centers
    root: the start node to find the k center.
    centering: whether the distance should be centered so that sum_k dist[n*k+i] = 0
    Output:
    centers: the list of nodes that form the k-centers. If centers = NULL on input, it will be allocated.
    dist: of dimension k*n, dist[k*n: (k+1)*n) gives the distance of every node to the k-th center.
    return: flag. if not zero, the graph is not connected, or out of memory.
  */
  SparseMatrix D = D0;
  int m = D->m, n = D->n;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0;
  int aggressive = (0);
  int connectedQ, end1, end2;
  enum {K_CENTER_DISCONNECTED = 1, K_CENTER_MEM};
  double *dist_min = (void *)0, *dist_sum = (void *)0, dmax, dsum;
  double *dist = (void *)0;
  int nlist, *list = (void *)0;
  int flag = 0, i, j, k, nlevel;
  int check_connected = (0);

  if (!SparseMatrix_is_symmetric(D, (0))){
    D = SparseMatrix_symmetrize(D, (0));
  }

  assert(m == n);

  dist_min = gmalloc(sizeof(double)*n);
  dist_sum = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) dist_min[i] = -1;
  for (i = 0; i < n; i++) dist_sum[i] = 0;
  if (!(*centers)) *centers = gmalloc(sizeof(int)*K);
  if (!(*dist0)) *dist0 = gmalloc(sizeof(double)*K*n);
  if (!weighted){
    dist = gmalloc(sizeof(double)*n);
    SparseMatrix_pseudo_diameter_unweighted(D, root, aggressive, &end1, &end2, &connectedQ);
    if (check_connected && !connectedQ) {
      flag =  K_CENTER_DISCONNECTED;
      goto RETURN;
    }
    root = end1;
    for (k = 0; k < K; k++){
      (*centers)[k] = root;
      //      fprintf(stderr,"k = %d, root = %d\n",k, root+1);
      SparseMatrix_level_sets(D, root, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
      if (check_connected) assert(levelset_ptr[nlevel] == n);
      for (i = 0; i < nlevel; i++) {
	for (j = levelset_ptr[i]; j < levelset_ptr[i+1]; j++){
	  (*dist0)[k*n+levelset[j]] = i;
	  if (k == 0){
	    dist_min[levelset[j]] = i;
	  } else {
	    dist_min[levelset[j]] = ((dist_min[levelset[j]])<(i)?(dist_min[levelset[j]]):(i));
	  }
	  dist_sum[levelset[j]] += i;
	}
      }

      /* root = argmax_i min_roots dist(i, roots) */
      dmax = dist_min[0];
      dsum = dist_sum[0];
      root = 0;
      for (i = 0; i < n; i++) {
	if (!check_connected && dist_min[i] < 0) continue;/* if the graph is disconnected, then we can not count on every node to be in level set. 
							     Usee dist_min<0 to identify those not in level set */
	if (dmax < dist_min[i] || (dmax == dist_min[i] && dsum < dist_sum[i])){/* tie break with avg dist */
	  dmax = dist_min[i];
	  dsum = dist_sum[i];
	  root = i;
	}
      }
    }
 } else {
    SparseMatrix_pseudo_diameter_weighted(D, root, aggressive, &end1, &end2, &connectedQ);
    if (check_connected && !connectedQ) return K_CENTER_DISCONNECTED;
    root = end1;
    list = gmalloc(sizeof(int)*n);

    for (k = 0; k < K; k++){
      //fprintf(stderr,"k = %d, root = %d\n",k, root+1);
      (*centers)[k] = root;
      dist = &((*dist0)[k*n]);
      flag = Dijkstra(D, root, dist, &nlist, list, &dmax);
      if (flag){
	flag = K_CENTER_MEM;
	goto RETURN;
      }
      if (check_connected) assert(nlist == n);
      for (i = 0; i < n; i++){
	if (k == 0){
	  dist_min[i] = dist[i];
	} else {
	  dist_min[i] = ((dist_min[i])<(dist[i])?(dist_min[i]):(dist[i]));
	}
	dist_sum[i] += dist[i];
      }

      /* root = argmax_i min_roots dist(i, roots) */
      dmax = dist_min[0];
      dsum = dist_sum[0];
      root = 0;
      for (i = 0; i < n; i++) {
	if (!check_connected && dist_min[i] < 0) continue;/* if the graph is disconnected, then we can not count on every node to be in level set. 
							     Usee dist_min<0 to identify those not in level set */
	if (dmax < dist_min[i] || (dmax == dist_min[i] && dsum < dist_sum[i])){/* tie break with avg dist */
	  dmax = dist_min[i];
	  dsum = dist_sum[i];
	  root = i;
	}
      }
    }
    dist = (void *)0;
  }

  if (centering){
    for (i = 0; i < n; i++) dist_sum[i] /= k;
    for (k = 0; k < K; k++){
      for (i = 0; i < n; i++){
	(*dist0)[k*n+i] -= dist_sum[i];
      }
    }
  }

 RETURN:
  if (levelset_ptr) free(levelset_ptr);
  if (levelset) free(levelset);
  if (mask) free(mask);
  
  if (D != D0) SparseMatrix_delete(D);
  if (dist) free(dist);
  if (dist_min) free(dist_min);
  if (dist_sum) free(dist_sum);
  if (list) free(list);
  return flag;

}



int SparseMatrix_k_centers_user(SparseMatrix D0, int weighted, int K, int *centers_user, int centering, double **dist0){
  /*
    Input:
    D: the graph. If weighted, the entry values is used.
    weighted: whether to treat the graph as weighted
    K: the number of centers
    root: the start node to find the k center.
    centering: whether the distance should be centered so that sum_k dist[n*k+i] = 0
    centers_user: the list of nodes that form the k-centers, GIVEN BY THE USER
    Output:
    dist: of dimension k*n, dist[k*n: (k+1)*n) gives the distance of every node to the k-th center.
    return: flag. if not zero, the graph is not connected, or out of memory.
  */
  SparseMatrix D = D0;
  int m = D->m, n = D->n;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0;
  int aggressive = (0);
  int connectedQ, end1, end2;
  enum {K_CENTER_DISCONNECTED = 1, K_CENTER_MEM};
  double *dist_min = (void *)0, *dist_sum = (void *)0, dmax;
  double *dist = (void *)0;
  int nlist, *list = (void *)0;
  int flag = 0, i, j, k, nlevel;
  int root;

  if (!SparseMatrix_is_symmetric(D, (0))){
    D = SparseMatrix_symmetrize(D, (0));
  }

  assert(m == n);

  dist_min = gmalloc(sizeof(double)*n);
  dist_sum = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) dist_sum[i] = 0;
  if (!(*dist0)) *dist0 = gmalloc(sizeof(double)*K*n);
  if (!weighted){
    dist = gmalloc(sizeof(double)*n);
    root = centers_user[0];
    SparseMatrix_pseudo_diameter_unweighted(D, root, aggressive, &end1, &end2, &connectedQ);
    if (!connectedQ) {
      flag =  K_CENTER_DISCONNECTED;
      goto RETURN;
    }
    for (k = 0; k < K; k++){
      root = centers_user[k];
      SparseMatrix_level_sets(D, root, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
      assert(levelset_ptr[nlevel] == n);
      for (i = 0; i < nlevel; i++) {
	for (j = levelset_ptr[i]; j < levelset_ptr[i+1]; j++){
	  (*dist0)[k*n+levelset[j]] = i;
	  if (k == 0){
	    dist_min[levelset[j]] = i;
	  } else {
	    dist_min[levelset[j]] = ((dist_min[levelset[j]])<(i)?(dist_min[levelset[j]]):(i));
	  }
	  dist_sum[levelset[j]] += i;
	}
      }

    }
 } else {
    root = centers_user[0];
    SparseMatrix_pseudo_diameter_weighted(D, root, aggressive, &end1, &end2, &connectedQ);
    if (!connectedQ) return K_CENTER_DISCONNECTED;
    list = gmalloc(sizeof(int)*n);

    for (k = 0; k < K; k++){
      root = centers_user[k];
      //      fprintf(stderr,"k = %d, root = %d\n",k, root+1);
      dist = &((*dist0)[k*n]);
      flag = Dijkstra(D, root, dist, &nlist, list, &dmax);
      if (flag){
	flag = K_CENTER_MEM;
	dist = (void *)0;
	goto RETURN;
      }
      assert(nlist == n);
      for (i = 0; i < n; i++){
	if (k == 0){
	  dist_min[i] = dist[i];
	} else {
	  dist_min[i] = ((dist_min[i])<(dist[i])?(dist_min[i]):(dist[i]));
	}
	dist_sum[i] += dist[i];
      }

    }
    dist = (void *)0;
  }

  if (centering){
    for (i = 0; i < n; i++) dist_sum[i] /= k;
    for (k = 0; k < K; k++){
      for (i = 0; i < n; i++){
	(*dist0)[k*n+i] -= dist_sum[i];
      }
    }
  }

 RETURN:
  if (levelset_ptr) free(levelset_ptr);
  if (levelset) free(levelset);
  if (mask) free(mask);
  
  if (D != D0) SparseMatrix_delete(D);
  if (dist) free(dist);
  if (dist_min) free(dist_min);
  if (dist_sum) free(dist_sum);
  if (list) free(list);
  return flag;

}




SparseMatrix SparseMatrix_from_dense(int m, int n, double *x){
  /* wrap a mxn matrix into a sparse matrix. the {i,j} entry of the matrix is in x[i*n+j], 0<=i<m; 0<=j<n */
  int i, j, *ja;
  double *a;
  SparseMatrix A = SparseMatrix_new(m, n, m*n, MATRIX_TYPE_REAL, FORMAT_CSR);

  A->ia[0] = 0;
  for (i = 1; i <= m; i++) (A->ia)[i] = (A->ia)[i-1] + n;
  
  ja = A->ja;
  a = (double*) A->a;
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++) {
      ja[j] = j;
      a[j] = x[i*n+j];
    }
    ja += n; a += j;
  }
  A->nz = m*n;
  return A;

}


int SparseMatrix_distance_matrix(SparseMatrix D0, int weighted, double **dist0){
  /*
    Input:
    D: the graph. If weighted, the entry values is used.
    weighted: whether to treat the graph as weighted
    Output:
    dist: of dimension nxn, dist[i*n+j] gives the distance of node i to j.
    return: flag. if not zero, the graph is not connected, or out of memory.
  */
  SparseMatrix D = D0;
  int m = D->m, n = D->n;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0;
  double *dist = (void *)0;
  int nlist, *list = (void *)0;
  int flag = 0, i, j, k, nlevel;
  double dmax;

  if (!SparseMatrix_is_symmetric(D, (0))){
    D = SparseMatrix_symmetrize(D, (0));
  }

  assert(m == n);

  if (!(*dist0)) *dist0 = gmalloc(sizeof(double)*n*n);
  for (i = 0; i < n*n; i++) (*dist0)[i] = -1;

  if (!weighted){
    for (k = 0; k < n; k++){
      SparseMatrix_level_sets(D, k, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
      assert(levelset_ptr[nlevel] == n);
      for (i = 0; i < nlevel; i++) {
	for (j = levelset_ptr[i]; j < levelset_ptr[i+1]; j++){
	  (*dist0)[k*n+levelset[j]] = i;
	}
      }
     }
 } else {
    list = gmalloc(sizeof(int)*n);
    for (k = 0; k < n; k++){
      dist = &((*dist0)[k*n]);
      flag = Dijkstra(D, k, dist, &nlist, list, &dmax);
    }
  }

  if (levelset_ptr) free(levelset_ptr);
  if (levelset) free(levelset);
  if (mask) free(mask);
  
  if (D != D0) SparseMatrix_delete(D);
  if (list) free(list);
  return flag;

}

SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted){
  /* return a sparse matrix whichj represent teh k-center and distance from every node to them.
     The matrix will have k*n entries
   */
  int flag;
  double *dist = (void *)0;
  int m = D->m, n = D->n;
  int root = 0;
  int *centers = (void *)0;
  double d;
  int i, j, center;
  SparseMatrix B, C;
  int centering = (0);

  assert(m == n);

  B = SparseMatrix_new(n, n, 1, MATRIX_TYPE_REAL, FORMAT_COORD);

  flag = SparseMatrix_k_centers(D, weighted, K, root, &centers, centering, &dist);
  assert(!flag);

  for (i = 0; i < K; i++){
    center = centers[i];
    for (j = 0; j < n; j++){
      d = dist[i*n + j];
      B = SparseMatrix_coordinate_form_add_entries(B, 1, &center, &j, &d);
      B = SparseMatrix_coordinate_form_add_entries(B, 1, &j, &center, &d);
    }
  }

  C = SparseMatrix_from_coordinate_format(B);
  SparseMatrix_delete(B);

  free(centers);
  free(dist);
  return C;
}

SparseMatrix SparseMatrix_distance_matrix_khops(int khops, SparseMatrix D0, int weighted){
  /*
    Input:
    khops: number of hops allow. If khops < 0, this will give a dense distances. Otherwise it gives a sparse matrix that represent the k-neighborhood graph
    D: the graph. If weighted, the entry values is used.
    weighted: whether to treat the graph as weighted
    Output:
    DD: of dimension nxn. DD[i,j] gives the shortest path distance, subject to the fact that the short oath must be of <= khops.
    return: flag. if not zero, the graph is not connected, or out of memory.
  */
  SparseMatrix D = D0, B, C;
  int m = D->m, n = D->n;
  int *levelset_ptr = (void *)0, *levelset = (void *)0, *mask = (void *)0;
  double *dist = (void *)0;
  int nlist, *list = (void *)0;
  int flag = 0, i, j, k, itmp, nlevel;
  double dmax, dtmp;

  if (!SparseMatrix_is_symmetric(D, (0))){
    D = SparseMatrix_symmetrize(D, (0));
  }

  assert(m == n);
 
  B = SparseMatrix_new(n, n, 1, MATRIX_TYPE_REAL, FORMAT_COORD);

  if (!weighted){
    for (k = 0; k < n; k++){
      SparseMatrix_level_sets_khops(khops, D, k, &nlevel, &levelset_ptr, &levelset, &mask, (!(0)));
      for (i = 0; i < nlevel; i++) {
	for (j = levelset_ptr[i]; j < levelset_ptr[i+1]; j++){
	  itmp = levelset[j]; dtmp = i;
	  if (k != itmp) B = SparseMatrix_coordinate_form_add_entries(B, 1, &k, &itmp, &dtmp);
	}
      }
     }
  } else {
    list = gmalloc(sizeof(int)*n);
    dist = gmalloc(sizeof(double)*n);
    /*
    Dijkstra_khops(khops, D, 60, dist, &nlist, list, &dmax);
    for (j = 0; j < nlist; j++){
      fprintf(stderr,"{%d,%d}=%f,",60,list[j],dist[list[j]]);
    }
    fprintf(stderr,"\n");
    Dijkstra_khops(khops, D, 94, dist, &nlist, list, &dmax);
    for (j = 0; j < nlist; j++){
      fprintf(stderr,"{%d,%d}=%f,",94,list[j],dist[list[j]]);
    }
    fprintf(stderr,"\n");
    exit(1);

    */

    for (k = 0; k < n; k++){
      SparseMatrix_level_sets_khops(khops, D, k, &nlevel, &levelset_ptr, &levelset, &mask, (0));
      assert(nlevel-1 <= khops);/* the first level is the root */
      flag = Dijkstra_masked(D, k, dist, &nlist, list, &dmax, mask);
      assert(!flag);
      for (i = 0; i < nlevel; i++) {
	for (j = levelset_ptr[i]; j < levelset_ptr[i+1]; j++){
	  assert(mask[levelset[j]] == i+1);
	  mask[levelset[j]] = -1;
	}
      }
      for (j = 0; j < nlist; j++){
	itmp = list[j]; dtmp = dist[itmp];
	if (k != itmp) B = SparseMatrix_coordinate_form_add_entries(B, 1, &k, &itmp, &dtmp);
      }
   }
  }

  C = SparseMatrix_from_coordinate_format(B);
  SparseMatrix_delete(B);

  if (levelset_ptr) free(levelset_ptr);
  if (levelset) free(levelset);
  if (mask) free(mask);
  if (dist) free(dist);

  if (D != D0) SparseMatrix_delete(D);
  if (list) free(list);
  /* I can not find a reliable way to make the matrix symmetric. Right now I use a mask array to
     limit consider of only nodes with in k hops, but even this is not symmetric. e.g.,
     . 10  10    10  10
     .A---B---C----D----E
     .           2 |    | 2
     .             G----F
     .               2
     If we set hops = 4, and from A, it can not see F (which is 5 hops), hence distance(A,E) =40
     but from E, it can see all nodes (all within 4 hops), so distance(E, A)=36.
     .
     may be there is a better way to ensure symmetric, but for now we just symmetrize it
  */
  D = SparseMatrix_symmetrize(C, (0));
  SparseMatrix_delete(C);
  return D;

}



  






  
  
  
  
  
  

  
  
  
  
  

  
  

  
  
    
    
    
    
    
  


  
  
  
  
  

  
  
    
    
      
      
      
      
    
    
    
    
    
      
      
	
	
	
	
	
      
    
  
  

  
  
  

  
    
      
	

	
	  
	

	
      
    
  
  


  
  




  
  
  

  

  
    
      
    
  

  







  







  
  
  
  
  
  

  
  
  
  
  

  
  

  
  
    
    
    
    
  


  
  
  
  

  
  
    
    

    
      
      

      
	
	
	
	  
	  
	  
	    
	    
	    
	    
	    
	  
	
      
      
      
      
      
      
      
    
    
    
    
    
  
  
  
  
  
  
  
  

  
    
      
	

	
	  
	

	
      
    
  
  


  
  





  
  
  

  

  
    
      
    
  

  




void SparseMatrix_page_rank(SparseMatrix A, double teleport_probablity, int weighted, double epsilon, double **page_rank){
  /* A(i,j)/Sum_k A(i,k) gives the probablity of the random surfer walking from i to j
     A: n x n  square matrix
     weighted: whether to use the wedge weights (matrix entries)
     page_rank: array of length n. If *page_rank was null on entry, will be assigned.

 */
  int n = A->n;
  int i, j;
  int *ia = A->ia, *ja = A->ja;
  double *x, *y, *diag, res;
  double *a = (void *)0;
  int iter = 0;

  assert(A->m == n);
  assert(teleport_probablity >= 0);

  if (weighted){
    switch (A->type){
    case MATRIX_TYPE_REAL:
      a = (double*) A->a;
      break;
    case MATRIX_TYPE_COMPLEX:/* take real part */
      a = gmalloc(sizeof(double)*n);
      for (i = 0; i < n; i++) a[i] = ((double*) A->a)[2*i];
      break;
    case MATRIX_TYPE_INTEGER:
      a = gmalloc(sizeof(double)*n);
      for (i = 0; i < n; i++) a[i] = ((int*) A->a)[i];
      break;
    case MATRIX_TYPE_PATTERN:
    case MATRIX_TYPE_UNKNOWN:
    default:
      weighted = (0);
      break;
    }
  }


  if (!(*page_rank)) *page_rank = gmalloc(sizeof(double)*n);
  x = *page_rank;

  diag = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) diag[i] = 0;
  y = gmalloc(sizeof(double)*n);

  for (i = 0; i < n; i++) x[i] = 1./n;

  /* find the column sum */
  if (weighted){
    for (i = 0; i < n; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	diag[i] += ((a[j]) >= 0 ? (a[j]) : -(a[j]));
      }
    }
  } else {
    for (i = 0; i < n; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	diag[i]++;
      }
    }
  }
  for (i = 0; i < n; i++) diag[i] = 1./((diag[i])>(1.0e-16)?(diag[i]):(1.0e-16));

  /* iterate */
  do {
    iter++;
    for (i = 0; i < n; i++) y[i] = 0;
    if (weighted){
      for (i = 0; i < n; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (ja[j] == i) continue;
	  y[ja[j]] += a[j]*x[i]*diag[i];
	}
      }
    } else {
      for (i = 0; i < n; i++){
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (ja[j] == i) continue;
	  y[ja[j]] += x[i]*diag[i];
	}
      }
    }
    for (i = 0; i < n; i++){
      y[i] = (1-teleport_probablity)*y[i] + teleport_probablity/n;
    }

    /*
    fprintf(stderr,"\n============\nx=");
    for (i = 0; i < n; i++) fprintf(stderr,"%f,",x[i]);
    fprintf(stderr,"\nx=");
    for (i = 0; i < n; i++) fprintf(stderr,"%f,",y[i]);
    fprintf(stderr,"\n");
    */

    res = 0;
    for (i = 0; i < n; i++) res += ((x[i] - y[i]) >= 0 ? (x[i] - y[i]) : -(x[i] - y[i]));
    if (Verbose) fprintf(stderr,"page rank iter -- %d, res = %f\n",iter, res);
    memcpy(x, y, sizeof(double)*n);
  } while (res > epsilon);

  free(y);
  free(diag);
  if (a && a != A->a) free(a);
}
