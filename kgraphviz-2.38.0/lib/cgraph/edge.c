#line 1 "graphviz-2.38.0\\lib\\cgraph\\edge.c" 1
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


#line 16 "graphviz-2.38.0\\lib\\cgraph\\edge.c" 2






static Agtag_t Tag;		/* to silence warnings about initialization */


/* return first outedge of <n> */
Agedge_t *agfstout(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn;
    Agedge_t *e = ((Agedge_t*)0);

    sn = agsubrep(g, n);
    if (sn) {
		dtrestore(g->e_seq, sn->out_seq);
		e = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(0),0000200);
		sn->out_seq = dtextract(g->e_seq);
	}
    return e;
}

/* return outedge that follows <e> of <n> */
Agedge_t *agnxtout(Agraph_t * g, Agedge_t * e)
{
    Agnode_t *n;
    Agsubnode_t *sn;
    Agedge_t *f = ((Agedge_t*)0);

    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    sn = agsubrep(g, n);
    if (sn) {
		dtrestore(g->e_seq, sn->out_seq);
		f = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(e),0000010);
		sn->out_seq = dtextract(g->e_seq);
	}
    return f;
}

Agedge_t *agfstin(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn;
    Agedge_t *e = ((Agedge_t*)0);

    sn = agsubrep(g, n);
	if (sn) {
		dtrestore(g->e_seq, sn->in_seq);
		e = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(0),0000200);
		sn->in_seq = dtextract(g->e_seq);
	}
    return e;
}

Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e)
{
    Agnode_t *n;
    Agsubnode_t *sn;
    Agedge_t *f = ((Agedge_t*)0);

    n = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    sn = agsubrep(g, n);
	if (sn) {
		dtrestore(g->e_seq, sn->in_seq);
		f = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(e),0000010);
		sn->in_seq = dtextract(g->e_seq);
	}
	return f;
}

Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n)
{
    Agedge_t *rv;
    rv = agfstout(g, n);
    if (rv == ((Agedge_t*)0))
	rv = agfstin(g, n);
    return rv;
}

Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n)
{
    Agedge_t *rv;

    if (((((Agobj_t*)(e))->tag).objtype) == 2) {
	rv = agnxtout(g, e);
	if (rv == ((Agedge_t*)0)) {
	    do {
		rv = !rv ? agfstin(g, n) : agnxtin(g,rv);
	    } while (rv && (rv->node == n));
	}
    } else {
	do {
	    rv = agnxtin(g, e);		/* so that we only see each edge once, */
		e = rv;
	} while (rv && (rv->node == n));	/* ignore loops as in-edges */
    }
    return rv;
}

/* internal edge set lookup */
static Agedge_t *agfindedge_by_key(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			    Agtag_t key)
{
    Agedge_t *e, template;
    Agsubnode_t *sn;

    if ((t == ((Agnode_t*)0)) || (h == ((Agnode_t*)0)))
	return ((Agedge_t*)0);
    template.base.tag = key;
    template.node = t;		/* guess that fan-in < fan-out */
    sn = agsubrep(g, h);
    if (!sn) e = 0;
    else {

	

	    dtrestore(g->e_id, sn->in_id);
	    e = (Agedge_t *) (*(((Dt_t*)(g->e_id))->searchf))((g->e_id),(void*)(&template),0000004);
	    sn->in_id = dtextract(g->e_id);

	
	    
	    
	    
	

    }
    return e;
}

static Agedge_t *agfindedge_by_id(Agraph_t * g, Agnode_t * t, Agnode_t * h,
				  unsigned long id)
{
    Agtag_t tag;

    tag = Tag;
    tag.objtype = 2;
    tag.id = id;
    return agfindedge_by_key(g, t, h, tag);
}

Agsubnode_t *agsubrep(Agraph_t * g, Agnode_t * n)
{
    Agsubnode_t *sn, template;

	if (g == n->root) sn = &(n->mainsub);
	else {
			template.node = n;
			sn = (*(((Dt_t*)(g->n_id))->searchf))((g->n_id),(void*)(&template),0000004);
	}
    return sn;
}

static void ins(Dict_t * d, Dtlink_t ** set, Agedge_t * e)
{
    dtrestore(d, *set);
    (*(((Dt_t*)(d))->searchf))((d),(void*)(e),0000001);
    *set = dtextract(d);
}

static void del(Dict_t * d, Dtlink_t ** set, Agedge_t * e)
{
    void *x;
    dtrestore(d, *set);
    x = (*(((Dt_t*)(d))->searchf))((d),(void*)(e),0000002);
    ;
    *set = dtextract(d);
}

static void installedge(Agraph_t * g, Agedge_t * e)
{
    Agnode_t *t, *h;
    Agedge_t *out, *in;
    Agsubnode_t *sn;

    out = (((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1));
    in = (((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1));
    t = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    h = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    while (g) {
	if (agfindedge_by_key(g, t, h, (((Agobj_t*)(e))->tag))) break;
	sn = agsubrep(g, t);
	ins(g->e_seq, &sn->out_seq, out);
	ins(g->e_id, &sn->out_id, out);
	sn = agsubrep(g, h);
	ins(g->e_seq, &sn->in_seq, in);
	ins(g->e_id, &sn->in_id, in);
	g = agparent(g);
    }
}

static void subedge(Agraph_t * g, Agedge_t * e)
{
    installedge(g, e);
    /* might an init method call be needed here? */
}

static Agedge_t *newedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			 unsigned long id)
{
    Agedgepair_t *e2;
    Agedge_t *in, *out;
    int seq;

    (void)agsubnode(g,t,(!(0)));
    (void)agsubnode(g,h,(!(0)));
    e2 = (Agedgepair_t *) agalloc(g, sizeof(Agedgepair_t));
    in = &(e2->in);
    out = &(e2->out);
    seq = agnextseq(g, 2);
    ((((Agobj_t*)(in))->tag).objtype) = 3;
    ((((Agobj_t*)(out))->tag).objtype) = 2;
    ((((Agobj_t*)(in))->tag).id) = ((((Agobj_t*)(out))->tag).id) = id;
    ((((Agobj_t*)(in))->tag).seq) = ((((Agobj_t*)(out))->tag).seq) = seq;
    in->node = t;
    out->node = h;

    installedge(g, out);
    if (g->desc.has_attrs) {
	(void) agbindrec(out, AgDataRecName, sizeof(Agattr_t), (0));
	agedgeattr_init(g, out);
    }
    agmethod_init(g, out);
    return out;
}

/* edge creation predicate */
static int ok_to_make_edge(Agraph_t * g, Agnode_t * t, Agnode_t * h)
{
    Agtag_t key;

    /* protect against self, multi-edges in strict graphs */
    if (agisstrict(g)) {
	if (g->desc.no_loop && (t == h)) /* simple graphs */
	    return (0);
	key = Tag;
	key.objtype = 0;	/* wild card */
	if (agfindedge_by_key(g, t, h, key))
	    return (0);
    }
    return (!(0));
}

Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
		   unsigned long id, int cflag)
{
    Agraph_t *root;
    Agedge_t *e;

    e = agfindedge_by_id(g, t, h, id);
    if ((e == ((Agedge_t*)0)) && agisundirected(g))
	e = agfindedge_by_id(g, h, t, id);
    if ((e == ((Agedge_t*)0)) && cflag && ok_to_make_edge(g, t, h)) {
	root = agroot(g);
	if ((g != root) && ((e = agfindedge_by_id(root, t, h, id)))) {
	    subedge(g, e);	/* old */
	} else {
	    if (agallocid(g, 2, id)) {
		e = newedge(g, t, h, id);	/* new */
	    }
	}
    }
    return e;
}

Agedge_t *agedge(Agraph_t * g, Agnode_t * t, Agnode_t * h, char *name,
		 int cflag)
{
    Agedge_t *e;
    unsigned long id;
    int have_id;

    have_id = agmapnametoid(g, 2, name, &id, (0));
    if (have_id || ((name == ((char*)0)) && ((!(cflag)) || agisstrict(g)))) {
	/* probe for pre-existing edge */
	Agtag_t key;
	key = Tag;
	if (have_id) {
	    key.id = id;
	    key.objtype = 2;
	} else {
	    key.id = key.objtype = 0;
	}

	/* might already exist locally */
	e = agfindedge_by_key(g, t, h, key);
	if ((e == ((Agedge_t*)0)) && agisundirected(g))
	    e = agfindedge_by_key(g, h, t, key);
	if (e)
	    return e;
	if (cflag) {
	    e = agfindedge_by_key(agroot(g), t, h, key);
	    if ((e == ((Agedge_t*)0)) && agisundirected(g))
		e = agfindedge_by_key(agroot(g), h, t, key);
	    if (e) {
		subedge(g,e);
		return e;
	    }
	}
    }

    if (cflag && ok_to_make_edge(g, t, h)
	&& agmapnametoid(g, 2, name, &id, (!(0)))) { /* reserve id */
	e = newedge(g, t, h, id);
	agregister(g, 2, e); /* register new object in external namespace */
    }
    else
	e = ((Agedge_t*)0);
    return e;
}

void agdeledgeimage(Agraph_t * g, Agedge_t * e, void *ignored)
{
    Agedge_t *in, *out;
    Agnode_t *t, *h;
    Agsubnode_t *sn;

    (void) ignored;
    if (((((Agobj_t*)(e))->tag).objtype) == 3) {
	in = e;
	out = ((e)-1);
    } else {
	out = e;
	in = ((e)+1);
    }
    t = in->node;
    h = out->node;
    sn = agsubrep(g, t);
    del(g->e_seq, &sn->out_seq, out);
    del(g->e_id, &sn->out_id, out);
    sn = agsubrep(g, h);
    del(g->e_seq, &sn->in_seq, in);
    del(g->e_id, &sn->in_id, in);

    
	
    
	

}

int agdeledge(Agraph_t * g, Agedge_t * e)
{
    e = (((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1));
    if (agfindedge_by_key(g, ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), (((Agobj_t*)(e))->tag)) == ((Agedge_t*)0))
	return -1;

    if (g == agroot(g)) {
	if (g->desc.has_attrs)
	    agedgeattr_delete(e);
	agmethod_delete(g, e);
	agrecclose((Agobj_t *) e);
	agfreeid(g, 2, ((((Agobj_t*)(e))->tag).id));
    }
    if (agapply (g, (Agobj_t *) e, (agobjfn_t) agdeledgeimage, ((Agedge_t*)0), (0)) == 0) {
	if (g == agroot(g))
		agfree(g, e);
	return 0;
    } else
	return -1;
}

Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int cflag)
{
    Agnode_t *t, *h;
    Agedge_t *rv;

    rv = ((Agedge_t*)0);
    t = agsubnode(g, ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), cflag);
    h = agsubnode(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), cflag);
    if (t && h) {
	rv = agfindedge_by_key(g, t, h, (((Agobj_t*)(e))->tag));
	if (cflag && (rv == ((Agedge_t*)0))) {

	    
	    
		

	installedge(g, e);
	rv = e;

	}
	if (rv && (((((Agobj_t*)(rv))->tag).objtype) != ((((Agobj_t*)(e))->tag).objtype)))
	    rv = ((((((Agobj_t*)(rv))->tag).objtype)==3)?((rv)-1):((rv)+1));
    }
    return rv;
}

/* edge comparison.  OBJTYPE(e) == 0 means ID is a wildcard. */
int agedgeidcmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc)
{
    long v;
    Agedge_t *e0, *e1;

    (void) d;
    e0 = arg_e0;
    e1 = arg_e1;
    (void) disc;
    v = ((((Agobj_t*)(e0->node))->tag).id) - ((((Agobj_t*)(e1->node))->tag).id);
    if (v == 0) {		/* same node */
	if ((((((Agobj_t*)(e0))->tag).objtype) == 0) || (((((Agobj_t*)(e1))->tag).objtype) == 0))
	    v = 0;
	else
	    v = ((((Agobj_t*)(e0))->tag).id) - ((((Agobj_t*)(e1))->tag).id);
    }
    return ((v==0)?0:(v<0?-1:1));
}

/* edge comparison.  for ordered traversal. */
int agedgeseqcmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc)
{
    long v;
    Agedge_t *e0, *e1;

    (void) d;
    e0 = arg_e0;
    e1 = arg_e1;
    (void) disc;
	;
	if (e0->node != e1->node) v = ((((Agobj_t*)(e0->node))->tag).seq) - ((((Agobj_t*)(e1->node))->tag).seq);
	else v = (((((Agobj_t*)(e0))->tag).seq) - ((((Agobj_t*)(e1))->tag).seq));
    return ((v==0)?0:(v<0?-1:1));
}

/* indexing for ordered traversal */
Dtdisc_t Ag_mainedge_seq_disc = {
    0,				/* pass object ptr      */
    0,				/* size (ignored)       */
    ((int)(&(((Agedge_t*)0)->seq_link))),/* use internal links	*/
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    agedgeseqcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};

Dtdisc_t Ag_subedge_seq_disc = {
    0,				/* pass object ptr      */
    0,				/* size (ignored)       */
    -1,				/* use external holder objects */
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    agedgeseqcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};

/* indexing for random search */
Dtdisc_t Ag_mainedge_id_disc = {
    0,				/* pass object ptr      */
    0,				/* size (ignored)       */
    ((int)(&(((Agedge_t*)0)->id_link))),	/* use internal links	*/
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    agedgeidcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};

Dtdisc_t Ag_subedge_id_disc = {
    0,				/* pass object ptr      */
    0,				/* size (ignored)       */
    -1,				/* use external holder objects */
    ((Dtmake_f)0),
    ((Dtfree_f)0),
    agedgeidcmpf,
    ((Dthash_f)0),
    agdictobjmem,
    ((Dtevent_f)0)
};

/* debug functions */



Agnode_t *agtail(Agedge_t * e)
{
    return ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
}




Agnode_t *aghead(Agedge_t * e)
{
    return ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
}




Agedge_t *agopp(Agedge_t * e)
{
    return ((((((Agobj_t*)(e))->tag).objtype)==3)?((e)-1):((e)+1));
}


	

				    

    

    
	
    
	


