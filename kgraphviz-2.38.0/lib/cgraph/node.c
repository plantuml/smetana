#line 1 "graphviz-2.38.0\\lib\\cgraph\\node.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
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










#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1


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











#line 20 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 2

#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1













































	/* functional definitions */
typedef Agobj_t *(*agobjsearchfn_t) (Agraph_t * g, Agobj_t * obj);
int agapply(Agraph_t * g, Agobj_t * obj, agobjfn_t fn, void *arg,
	    int preorder);

	/* global variables */
extern Agraph_t *Ag_G_global;
extern char *AgDataRecName;

	/* set ordering disciplines */
extern Dtdisc_t Ag_subnode_id_disc;
extern Dtdisc_t Ag_subnode_seq_disc;
extern Dtdisc_t Ag_mainedge_id_disc;
extern Dtdisc_t Ag_subedge_id_disc;
extern Dtdisc_t Ag_mainedge_seq_disc;
extern Dtdisc_t Ag_subedge_seq_disc;
extern Dtdisc_t Ag_subgraph_id_disc;
extern Agcbdisc_t AgAttrdisc;

	/* internal constructor of graphs and subgraphs */
Agraph_t *agopen1(Agraph_t * g);
int agstrclose(Agraph_t * g);

	/* ref string management */
void agmarkhtmlstr(char *s);

	/* object set management */
Agnode_t *agfindnode_by_id(Agraph_t * g, unsigned long id);
Dtcompar_f agdictorder(Agraph_t *, Dict_t *, Dtcompar_f);
int agedgecmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc);
int agnamecmpf(Dict_t * d, void *, void *, Dtdisc_t * disc);
void agset_node_disc(Agraph_t * g, Dtdisc_t * disc);
unsigned long agnextseq(Agraph_t * g, int objtype);

/* dict helper functions */
Dict_t *agdtopen(Agraph_t * g, Dtdisc_t * disc, Dtmethod_t * method);
void agdtdisc(Agraph_t * g, Dict_t * dict, Dtdisc_t * disc);
long agdtdelete(Agraph_t * g, Dict_t * dict, void *obj);
int agdtclose(Agraph_t * g, Dict_t * dict);
void *agdictobjmem(Dict_t * dict, void * p, size_t size,
		   Dtdisc_t * disc);
void agdictobjfree(Dict_t * dict, void * p, Dtdisc_t * disc);

	/* name-value pair operations */
Agdatadict_t *agdatadict(Agraph_t * g, int cflag);
Agattr_t *agattrrec(void *obj);

void agraphattr_init(Agraph_t * g);
int agraphattr_delete(Agraph_t * g);
void agnodeattr_init(Agraph_t *g, Agnode_t * n);
void agnodeattr_delete(Agnode_t * n);
void agedgeattr_init(Agraph_t *g, Agedge_t * e);
void agedgeattr_delete(Agedge_t * e);

	/* parsing and lexing graph files */
int aagparse(void);
void aglexinit(Agdisc_t * disc, void *ifile);
int aaglex(void);
void aglexeof(void);
void aglexbad(void);

	/* ID management */
int agmapnametoid(Agraph_t * g, int objtype, char *str,
		  unsigned long *result, int allocflag);
int agallocid(Agraph_t * g, int objtype, unsigned long request);
void agfreeid(Agraph_t * g, int objtype, unsigned long id);
char *agprintid(Agobj_t * obj);
int aginternalmaplookup(Agraph_t * g, int objtype, char *str,
			unsigned long *result);
void aginternalmapinsert(Agraph_t * g, int objtype, char *str,
			 unsigned long result);
char *aginternalmapprint(Agraph_t * g, int objtype, unsigned long id);
int aginternalmapdelete(Agraph_t * g, int objtype, unsigned long id);
void aginternalmapclose(Agraph_t * g);
void agregister(Agraph_t * g, int objtype, void *obj);

	/* internal set operations */
void agedgesetop(Agraph_t * g, Agedge_t * e, int insertion);
void agdelnodeimage(Agraph_t * g, Agnode_t * node, void *ignored);
void agdeledgeimage(Agraph_t * g, Agedge_t * edge, void *ignored);
void *agrebind0(Agraph_t * g, void *obj);	/* unsafe */
int agrename(Agobj_t * obj, char *newname);
void agrecclose(Agobj_t * obj);

void agmethod_init(Agraph_t * g, void *obj);
void agmethod_upd(Agraph_t * g, void *obj, Agsym_t * sym);
void agmethod_delete(Agraph_t * g, void *obj);




void agsyspushdisc(Agraph_t * g, Agcbdisc_t * cb, void *state, int stack);
int agsyspopdisc(Agraph_t * g, Agcbdisc_t * cb, int stack);
void agrecord_callback(Agraph_t * g, Agobj_t * obj, int kind,
		       Agsym_t * optsym);
void aginitcb(Agraph_t * g, void *obj, Agcbstack_t * disc);
void agupdcb(Agraph_t * g, void *obj, Agsym_t * sym, Agcbstack_t * disc);
void agdelcb(Agraph_t * g, void *obj, Agcbstack_t * disc);


#line 16 "graphviz-2.38.0\\lib\\cgraph\\node.c" 2

Agnode_t *agfindnode_by_id(Agraph_t * g, unsigned long id)
{
    Agsubnode_t *sn;
    static Agsubnode_t template;
    static Agnode_t dummy;

    dummy.base.tag.id = id;
    template.node = &dummy;
    sn = (Agsubnode_t *) (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(&template),0000004);
    return sn ? sn->node : ((Agnode_t*)0);
}

Agnode_t *agfindnode_by_name(Agraph_t * g, char *name)
{
    unsigned long id;

    if (agmapnametoid(g, 1, name, &id, (0)))
	return agfindnode_by_id(g, id);
    else
	return ((Agnode_t*)0);
}

Agnode_t *agfstnode(Agraph_t * g)
{
    Agsubnode_t *sn;
    sn = (Agsubnode_t *) (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(0),0000200);
    return sn ? sn->node : ((Agnode_t*)0);
}

Agnode_t *agnxtnode(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn;
    sn = agsubrep(g, n);
    if (sn) sn = ((Agsubnode_t *) (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(sn),0000010));
    return sn ? sn->node : ((Agnode_t*)0);
}

Agnode_t *aglstnode(Agraph_t * g)
{
    Agsubnode_t *sn;
    sn = (Agsubnode_t *) (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(0),0000400);
    return sn ? sn->node : ((Agnode_t*)0);
}

Agnode_t *agprvnode(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn;
    sn = agsubrep(g, n);
    if (sn) sn = ((Agsubnode_t *) (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(sn),0000020));
    return sn ? sn->node : ((Agnode_t*)0);
}


/* internal node constructor */
static Agnode_t *newnode(Agraph_t * g, unsigned long id, unsigned long seq)
{
    Agnode_t *n;

    n = agalloc(g, sizeof(Agnode_t));
    ((((Agobj_t*)(n))->tag).objtype) = 1;
    ((((Agobj_t*)(n))->tag).id) = id;
    ((((Agobj_t*)(n))->tag).seq) = seq;
    n->root = agroot(g);
    if (agroot(g)->desc.has_attrs)
	(void) agbindrec(n, AgDataRecName, sizeof(Agattr_t), (0));
    /* nodeattr_init and method_init will be called later, from the
     * subgraph where the node was actually created, but first it has
     * to be installed in all the (sub)graphs up to root. */
    return n;
}

static void installnode(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn;
    int osize;

    ;
    osize = dtsize(g->n_id);
    if (g == agroot(g)) sn = &(n->mainsub);
    else sn = agalloc(g, sizeof(Agsubnode_t));
    sn->node = n;
    (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(sn),0000001);
    (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(sn),0000001);
    ;
    ;
}

static void installnodetoroot(Agraph_t * g, Agnode_t * n)
{
    Agraph_t *par;
    installnode(g, n);
    if ((par = agparent(g)))
	installnodetoroot(par, n);
}

static void initnode(Agraph_t * g, Agnode_t * n)
{
    if (agroot(g)->desc.has_attrs)
	agnodeattr_init(g,n);
    agmethod_init(g, n);
}

/* external node constructor - create by id */
Agnode_t *agidnode(Agraph_t * g, unsigned long id, int cflag)
{
    Agraph_t *root;
    Agnode_t *n;

    n = agfindnode_by_id(g, id);
    if ((n == ((Agnode_t*)0)) && cflag) {
	root = agroot(g);
	if ((g != root) && ((n = agfindnode_by_id(root, id))))	/*old */
	    agsubnode(g, n, (!(0)));	/* insert locally */
	else {
	    if (agallocid(g, 1, id)) {	/* new */
		n = newnode(g, id, agnextseq(g, 1));
		installnodetoroot(g, n);
		initnode(g, n);
	    } else
		n = ((Agnode_t*)0);	/* allocid for new node failed */
	}
    }
    /* else return probe result */
    return n;
}

Agnode_t *agnode(Agraph_t * g, char *name, int cflag)
{
    Agraph_t *root;
    Agnode_t *n;
    unsigned long id;

    root = agroot(g);
    /* probe for existing node */
    if (agmapnametoid(g, 1, name, &id, (0))) {
	if ((n = agfindnode_by_id(g, id)))
	    return n;

	/* might already exist globally, but need to insert locally */
	if (cflag && (g != root) && ((n = agfindnode_by_id(root, id)))) {
	    return agsubnode(g, n, (!(0)));
	}
    }

    if (cflag && agmapnametoid(g, 1, name, &id, (!(0)))) {	/* reserve id */
	n = newnode(g, id, agnextseq(g, 1));
	installnodetoroot(g, n);
	initnode(g, n);
	;
	agregister(g, 1, n); /* register in external namespace */
	return n;
    }

    return ((Agnode_t*)0);
}

/* removes image of node and its edges from graph.
   caller must ensure n belongs to g. */
void agdelnodeimage(Agraph_t * g, Agnode_t * n, void *ignored)
{
    Agedge_t *e, *f;
    static Agsubnode_t template;
    template.node = n;

    (void) ignored;
    for (e = agfstedge(g, n); e; e = f) {
	f = agnxtedge(g, e, n);
	agdeledgeimage(g, e, 0);
    }
    /* If the following lines are switched, switch the discpline using
     * free_subnode below.
     */ 
    (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(&template),0000002);
    (*(((Dt_t*)(g->n_seq))->searchf))((g->n_seq),(void*)(&template),0000002);
}

int agdelnode(Agraph_t * g, Agnode_t * n)
{
    Agedge_t *e, *f;

    if (!agfindnode_by_id(g, ((((Agobj_t*)(n))->tag).id)))
	return -1;		/* bad arg */
    if (g == agroot(g)) {
	for (e = agfstedge(g, n); e; e = f) {
	    f = agnxtedge(g, e, n);
	    agdeledge(g, e);
	}
	if (g->desc.has_attrs)
	    agnodeattr_delete(n);
	agmethod_delete(g, n);
	agrecclose((Agobj_t *) n);
	agfreeid(g, 1, ((((Agobj_t*)(n))->tag).id));
    }
    if (agapply (g, (Agobj_t *) n, (agobjfn_t) agdelnodeimage, ((Agnode_t*)0), (0)) == 0) {
	if (g == agroot(g))
	    agfree(g, n);
	return 0;
    } else
	return -1;
}

static void dict_relabel(Agnode_t * n, void *arg)
{
    Agraph_t *g;
    unsigned long new_id;

    g = agraphof(n);
    new_id = *(unsigned long *) arg;
    (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(n),0000002);	/* wrong, should be subrep */
    ((((Agobj_t*)(n))->tag).id) = new_id;
    (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(n),0000001);	/* also wrong */
    /* because all the subgraphs share the same node now, this
       now requires a separate deletion and insertion phase */
}

int agrelabel_node(Agnode_t * n, char *newname)
{
    Agraph_t *g;
    unsigned long new_id;

    g = agroot(agraphof(n));
    if (agfindnode_by_name(g, newname))
	return -1;
    if (agmapnametoid(g, 1, newname, &new_id, (!(0)))) {
	if (agfindnode_by_id(agroot(g), new_id) == ((Agnode_t*)0)) {
	    agfreeid(g, 1, ((((Agobj_t*)(n))->tag).id));
	    agapply(g, (Agobj_t *) n, (agobjfn_t) dict_relabel,
		    (void *) &new_id, (0));
	    return 0;
	} else {
	    agfreeid(g, 1, new_id);	/* couldn't use it after all */
	}
        /* obj* is unchanged, so no need to re agregister() */
    }
    return -1;
}

/* lookup or insert <n> in <g> */
Agnode_t *agsubnode(Agraph_t * g, Agnode_t * n0, int cflag)
{
    Agraph_t *par;
    Agnode_t *n;

    if (agroot(g) != n0->root)
	return ((Agnode_t*)0);
    n = agfindnode_by_id(g, ((((Agobj_t*)(n0))->tag).id));
    if ((n == ((Agnode_t*)0)) && cflag) {
	if ((par = agparent(g))) {
	    n = agsubnode(par, n0, cflag);
	    installnode(g, n);
	    /* no callback for existing node insertion in subgraph (?) */
	}
	/* else impossible that <n> doesn't belong to <g> */
    }
    /* else lookup succeeded */
    return n;
}

int agsubnodeidcmpf(Dict_t * d, void *arg0, void *arg1, Dtdisc_t * disc)
{
    long	v;
    Agsubnode_t *sn0, *sn1;
    sn0 = (Agsubnode_t *) arg0;
    sn1 = (Agsubnode_t *) arg1;
    v = (((((Agobj_t*)(sn0->node))->tag).id) - ((((Agobj_t*)(sn1->node))->tag).id));
    return ((v==0)?0:(v<0?-1:1));
}

int agsubnodeseqcmpf(Dict_t * d, void *arg0, void *arg1, Dtdisc_t * disc)
{
    Agsubnode_t *sn0, *sn1;
    long	v;
    sn0 = (Agsubnode_t *) arg0;
    sn1 = (Agsubnode_t *) arg1;
    v = (((((Agobj_t*)(sn0->node))->tag).seq) - ((((Agobj_t*)(sn1->node))->tag).seq));
    return ((v==0)?0:(v<0?-1:1));
}

/* free_subnode:
 * Free Agsubnode_t allocated in installnode. This should
 * only be done for subgraphs, as the root graph uses the
 * subnode structure built into the node. This explains the
 * AGSNMAIN test. Also, note that both the id and the seq
 * dictionaries use the same subnode object, so only one
 * should do the deletion.
 */
static void
free_subnode (Dt_t* d, Agsubnode_t* sn, Dtdisc_t * disc)
{

   if (!((sn)==(&((sn)->node->mainsub)))) 
	agfree (sn->node->root, sn);
}

Dtdisc_t Ag_subnode_id_disc = {
    0,				/* pass object ptr  */
    0,				/* size (ignored)   */
    ((int)(&(((Agsubnode_t*)0)->id_link))),	/* link offset */
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    agsubnodeidcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};

Dtdisc_t Ag_subnode_seq_disc = {
    0,				/* pass object ptr  */
    0,				/* size (ignored)   */
    ((int)(&(((Agsubnode_t*)0)->seq_link))),	/* link offset */
    ((Dtmake_f)0),
    (Dtfree_f)free_subnode,
    agsubnodeseqcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};
