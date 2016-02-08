#line 1 "graphviz-2.38.0\\lib\\cgraph\\attr.c" 1
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


#line 16 "graphviz-2.38.0\\lib\\cgraph\\attr.c" 2

/*
 * dynamic attributes
 */

/* to create a graph's data dictionary */



static void freesym(Dict_t * d, void * obj, Dtdisc_t * disc);

Dtdisc_t AgDataDictDisc = {
    (int) ((int)(&(((Agsym_t*)0)->name))),	/* use symbol name as key */
    -1,
    (int) ((int)(&(((Agsym_t*)0)->link))),
    ((Dtmake_f)0),
    freesym,
    ((Dtcompar_f)0),
    ((Dthash_f)0)
};

static char DataDictName[] = "_AG_datadict";
static void init_all_attrs(Agraph_t * g);
static Agdesc_t ProtoDesc = { 1, 0, 1, 0, 1, 1 };
static Agraph_t *ProtoGraph;

Agdatadict_t *agdatadict(Agraph_t * g, int cflag)
{
    Agdatadict_t *rv;
    rv = (Agdatadict_t *) aggetrec(g, DataDictName, (0));
    if (rv || !cflag)
	return rv;
    init_all_attrs(g);
    rv = (Agdatadict_t *) aggetrec(g, DataDictName, (0));
    return rv;
}

Dict_t *agdictof(Agraph_t * g, int kind)
{
    Agdatadict_t *dd;
    Dict_t *dict;

    dd = agdatadict(g, (0));
    if (dd)
	switch (kind) {
	case AGRAPH:
	    dict = dd->dict.g;
	    break;
	case AGNODE:
	    dict = dd->dict.n;
	    break;
	case AGINEDGE:
	case AGOUTEDGE:
	    dict = dd->dict.e;
	    break;
	default:
	    agerr(AGERR,"agdictof: unknown kind %d\n", kind);
	    dict = ((Dict_t *)0);
	    break;
    } else
	dict = ((Dict_t *)0);
    return dict;
}

Agsym_t *agnewsym(Agraph_t * g, char *name, char *value, int id, int kind)
{
    Agsym_t *sym;
    sym = agalloc(g, sizeof(Agsym_t));
    sym->kind = kind;
    sym->name = agstrdup(g, name);
    sym->defval = agstrdup(g, value);
    sym->id = id;
    return sym;
}

static void agcopydict(Dict_t * src, Dict_t * dest, Agraph_t * g, int kind)
{
    Agsym_t *sym, *newsym;

    ;
    for (sym = (Agsym_t *) (*(((Dt_t*)(src))->searchf))((src),(void*)(0),0000200); sym;
	 sym = (Agsym_t *) (*(((Dt_t*)(src))->searchf))((src),(void*)(sym),0000010)) {
	newsym = agnewsym(g, sym->name, sym->defval, sym->id, kind);
	newsym->print = sym->print;
	newsym->fixed = sym->fixed;
	(*(((Dt_t*)(dest))->searchf))((dest),(void*)(newsym),0000001);
    }
}

static Agdatadict_t *agmakedatadict(Agraph_t * g)
{
    Agraph_t *par;
    Agdatadict_t *parent_dd, *dd;

    dd = (Agdatadict_t *) agbindrec(g, DataDictName, sizeof(Agdatadict_t),
				    (0));
    dd->dict.n = agdtopen(g, &AgDataDictDisc, Dttree);
    dd->dict.e = agdtopen(g, &AgDataDictDisc, Dttree);
    dd->dict.g = agdtopen(g, &AgDataDictDisc, Dttree);
    if ((par = agparent(g))) {
	parent_dd = agdatadict(par, (0));
	;
	dtview(dd->dict.n, parent_dd->dict.n);
	dtview(dd->dict.e, parent_dd->dict.e);
	dtview(dd->dict.g, parent_dd->dict.g);
    } else {
	if (ProtoGraph && (g != ProtoGraph)) {
	    /* it's not ok to dtview here for several reasons. the proto
	       graph could change, and the sym indices don't match */
	    parent_dd = agdatadict(ProtoGraph, (0));
	    agcopydict(parent_dd->dict.n, dd->dict.n, g, AGNODE);
	    agcopydict(parent_dd->dict.e, dd->dict.e, g, AGEDGE);
	    agcopydict(parent_dd->dict.g, dd->dict.g, g, AGRAPH);
	}
    }
    return dd;
}

/* look up an attribute with possible viewpathing */
Agsym_t *agdictsym(Dict_t * dict, char *name)
{
    Agsym_t key;
    key.name = (char *) name;
    return (Agsym_t *) (*(((Dt_t*)(dict))->searchf))((dict),(void*)(&key),0000004);
}

/* look up attribute in local dictionary with no view pathing */
Agsym_t *aglocaldictsym(Dict_t * dict, char *name)
{
    Agsym_t *rv;
    Dict_t *view;

    view = dtview(dict, ((Dict_t *)0));
    rv = agdictsym(dict, name);
    dtview(dict, view);
    return rv;
}

Agsym_t *agattrsym(void *obj, char *name)
{
    Agattr_t *data;
    Agsym_t *rv;
    char *arg = name;

    data = agattrrec((Agobj_t *) obj);
    if (data)
	rv = agdictsym(data->dict, arg);
    else
	rv = ((Agsym_t*)0);
    return rv;
}

/* to create a graph's, node's edge's string attributes */

char *AgDataRecName = "_AG_strdata";

static int topdictsize(Agobj_t * obj)
{
    Dict_t *d;

    d = agdictof(agroot(agraphof(obj)), AGTYPE(obj));
    return d ? dtsize(d) : 0;
}

/* g can be either the enclosing graph, or ProtoGraph */
static Agrec_t *agmakeattrs(Agraph_t * context, void *obj)
{
    int sz;
    Agattr_t *rec;
    Agsym_t *sym;
    Dict_t *datadict;

    rec = agbindrec(obj, AgDataRecName, sizeof(Agattr_t), (0));
    datadict = agdictof(context, AGTYPE(obj));
    ;
    if (rec->dict == ((Dict_t *)0)) {
	rec->dict = agdictof(agroot(context), AGTYPE(obj));
	/* don't malloc(0) */
	sz = topdictsize(obj);
	if (sz < 4)
	    sz = 4;
	rec->str = agalloc(agraphof(obj), sz * sizeof(char *));
	/* doesn't call agxset() so no obj-modified callbacks occur */
	for (sym = (Agsym_t *) (*(((Dt_t*)(datadict))->searchf))((datadict),(void*)(0),0000200); sym;
	     sym = (Agsym_t *) (*(((Dt_t*)(datadict))->searchf))((datadict),(void*)(sym),0000010))
	    rec->str[sym->id] = agstrdup(agraphof(obj), sym->defval);
    } else {
	;
    }
    return (Agrec_t *) rec;
}

static void freeattr(Agobj_t * obj, Agattr_t * attr)
{
    int i, sz;
    Agraph_t *g;

    g = agraphof(obj);
    sz = topdictsize(obj);
    for (i = 0; i < sz; i++)
	agstrfree(g, attr->str[i]);
    agfree(g, attr->str);
}

static void freesym(Dict_t * d, void * obj, Dtdisc_t * disc)
{
    Agsym_t *sym;

    (void) d;
    sym = (Agsym_t *) obj;
    (void) disc;
    agstrfree(Ag_G_global, sym->name);
    agstrfree(Ag_G_global, sym->defval);
    agfree(Ag_G_global, sym);
}

Agattr_t *agattrrec(void *obj)
{
    return (Agattr_t *) aggetrec(obj, AgDataRecName, (0));
}


static void addattr(Agraph_t * g, Agobj_t * obj, Agsym_t * sym)
{
    Agattr_t *attr;

    attr = (Agattr_t *) agattrrec(obj);
    ;
    if (sym->id >= 4)
	attr->str = (char **) ((g)->clos->disc.mem)->resize(((g)->clos->state.mem),
						     attr->str,
						     sym->id *
						     sizeof(char *),
						     (sym->id +
						      1) * sizeof(char *));
    attr->str[sym->id] = agstrdup(g, sym->defval);
    /* agmethod_upd(g,obj,sym);  JCE and GN didn't like this. */
}


static Agsym_t *setattr(Agraph_t * g, int kind, char *name, char *value)
{
    Agdatadict_t *dd;
    Dict_t *ldict, *rdict;
    Agsym_t *lsym, *psym, *rsym, *rv;
    Agraph_t *root;
    Agnode_t *n;
    Agedge_t *e;

    ;
    root = agroot(g);
    dd = agdatadict(g, (!(0)));	/* force initialization of string attributes */
    ldict = agdictof(g, kind);
    lsym = aglocaldictsym(ldict, name);
    if (lsym) {			/* update old local definiton */
	agstrfree(g, lsym->defval);
	lsym->defval = agstrdup(g, value);
	rv = lsym;
    } else {
	psym = agdictsym(ldict, name);	/* search with viewpath up to root */
	if (psym) {		/* new local definition */
	    lsym = agnewsym(g, name, value, psym->id, kind);
	    (*(((Dt_t*)(ldict))->searchf))((ldict),(void*)(lsym),0000001);
	    rv = lsym;
	} else {		/* new global definition */
	    rdict = agdictof(root, kind);
	    rsym = agnewsym(g, name, value, dtsize(rdict), kind);
	    (*(((Dt_t*)(rdict))->searchf))((rdict),(void*)(rsym),0000001);
	    switch (kind) {
	    case AGRAPH:
		agapply(root, (Agobj_t *) root, (agobjfn_t) addattr,
			rsym, (!(0)));
		break;
	    case AGNODE:
		for (n = agfstnode(root); n; n = agnxtnode(root, n))
		    addattr(g, (Agobj_t *) n, rsym);
		break;
	    case AGINEDGE:
	    case AGOUTEDGE:
		for (n = agfstnode(root); n; n = agnxtnode(root, n))
		    for (e = agfstout(root, n); e; e = agnxtout(root, e))
			addattr(g, (Agobj_t *) e, rsym);
		break;
	    }
	    rv = rsym;
	}
    }
    if (rv && (kind == AGRAPH))
	agxset(g, rv, value);
    agmethod_upd(g, g, rv);	/* JCE and GN wanted this */
    return rv;
}

static Agsym_t *getattr(Agraph_t * g, int kind, char *name)
{
    Agsym_t *rv = 0;
    Dict_t *dict;
    dict = agdictof(g, kind);
    if (dict)
	rv = agdictsym(dict, name);	/* viewpath up to root */
    return rv;
}

/*
 * create or update an existing attribute and return its descriptor.
 * if the new value is NIL(char*), this is only a search, no update.
 * when a new attribute is created, existing graphs/nodes/edges
 * receive its default value.
 */
Agsym_t *agattr(Agraph_t * g, int kind, char *name, char *value)
{
    Agsym_t *rv;

    if (g == 0) {
	if (ProtoGraph == 0)
	    ProtoGraph = agopen(0, ProtoDesc, 0);
	g = ProtoGraph;
    }
    if (value)
	rv = setattr(g, kind, name, value);
    else
	rv = getattr(g, kind, name);
    return rv;
}

Agsym_t *agnxtattr(Agraph_t * g, int kind, Agsym_t * attr)
{
    Dict_t *d;
    Agsym_t *rv;

    if ((d = agdictof(g, kind))) {
	if (attr)
	    rv = (Agsym_t *) (*(((Dt_t*)(d))->searchf))((d),(void*)(attr),0000010);
	else
	    rv = (Agsym_t *) (*(((Dt_t*)(d))->searchf))((d),(void*)(0),0000200);
    } else
	rv = 0;
    return rv;
}

/* Create or delete attributes associated with an object */

void agraphattr_init(Agraph_t * g)
{
    /* Agdatadict_t *dd; */
    /* Agrec_t                      *attr; */
    Agraph_t *context;

    g->desc.has_attrs = 1;
    /* dd = */ agmakedatadict(g);
    if (!(context = agparent(g)))
	context = g;
    /* attr = */ agmakeattrs(context, g);
}

int agraphattr_delete(Agraph_t * g)
{
    Agdatadict_t *dd;
    Agattr_t *attr;

    Ag_G_global = g;
    if ((attr = agattrrec(g))) {
	freeattr((Agobj_t *) g, attr);
	agdelrec(g, attr->h.name);
    }

    if ((dd = agdatadict(g, (0)))) {
	if (agdtclose(g, dd->dict.n)) return 1;
	if (agdtclose(g, dd->dict.e)) return 1;
	if (agdtclose(g, dd->dict.g)) return 1;
	agdelrec(g, dd->h.name);
    }
    return 0;
}

void agnodeattr_init(Agraph_t * g, Agnode_t * n)
{
    Agattr_t *data;

    data = agattrrec(n);
    if ((!data) || (!data->dict))
	(void) agmakeattrs(g, n);
}

void agnodeattr_delete(Agnode_t * n)
{
    Agattr_t *rec;

    if ((rec = agattrrec(n))) {
	freeattr((Agobj_t *) n, rec);
	agdelrec(n, AgDataRecName);
    }
}

void agedgeattr_init(Agraph_t * g, Agedge_t * e)
{
    Agattr_t *data;

    data = agattrrec(e);
    if ((!data) || (!data->dict))
	(void) agmakeattrs(g, e);
}

void agedgeattr_delete(Agedge_t * e)
{
    Agattr_t *rec;

    if ((rec = agattrrec(e))) {
	freeattr((Agobj_t *) e, rec);
	agdelrec(e, AgDataRecName);
    }
}

char *agget(void *obj, char *name)
{
    Agsym_t *sym;
    Agattr_t *data;
    char *rv;

    sym = agattrsym(obj, name);
    if (sym == ((Agsym_t*)0))
	rv = 0;			/* note was "", but this provides more info */
    else {
	data = agattrrec((Agobj_t *) obj);
	rv = (char *) (data->str[sym->id]);
    }
    return rv;
}

char *agxget(void *obj, Agsym_t * sym)
{
    Agattr_t *data;
    char *rv;

    data = agattrrec((Agobj_t *) obj);
    ;
    rv = (char *) (data->str[sym->id]);
    return rv;
}

int agset(void *obj, char *name, char *value)
{
    Agsym_t *sym;
    int rv;

    sym = agattrsym(obj, name);
    if (sym == ((Agsym_t*)0))
	rv = -1;
    else
	rv = agxset(obj, sym, value);
    return rv;
}

int agxset(void *obj, Agsym_t * sym, char *value)
{
    Agraph_t *g;
    Agobj_t *hdr;
    Agattr_t *data;
    Agsym_t *lsym;

    g = agraphof(obj);
    hdr = (Agobj_t *) obj;
    data = agattrrec(hdr);
    ;
    agstrfree(g, data->str[sym->id]);
    data->str[sym->id] = agstrdup(g, value);
    if (hdr->tag.objtype == AGRAPH) {
	/* also update dict default */
	Dict_t *dict;
	dict = agdatadict(g, (0))->dict.g;
	if ((lsym = aglocaldictsym(dict, sym->name))) {
	    agstrfree(g, lsym->defval);
	    lsym->defval = agstrdup(g, value);
	} else {
	    lsym = agnewsym(g, sym->name, value, sym->id, AGTYPE(hdr));
	    (*(((Dt_t*)(dict))->searchf))((dict),(void*)(lsym),0000001);
	}
    }
    agmethod_upd(g, obj, sym);
    return 0;
}

int agsafeset(void *obj, char *name, char *value, char *def)
{
    Agsym_t *a;

    a = agattr(agraphof(obj), AGTYPE(obj), name, 0);
    if (!a)
	a = agattr(agraphof(obj), AGTYPE(obj), name, def);
    return agxset(obj, a, value);
}


/*
 * attach attributes to the already created graph objs.
 * presumably they were already initialized, so we don't invoke
 * any of the old methods.
 */
static void init_all_attrs(Agraph_t * g)
{
    Agraph_t *root;
    Agnode_t *n;
    Agedge_t *e;

    root = agroot(g);
    agapply(root, (Agobj_t *) root, (agobjfn_t) agraphattr_init,
	    ((Agdisc_t *)0), (!(0)));
    for (n = agfstnode(root); n; n = agnxtnode(root, n)) {
	agnodeattr_init(g, n);
	for (e = agfstout(root, n); e; e = agnxtout(root, e)) {
	    agedgeattr_init(g, e);
	}
    }
}

/* agcopyattr:
 * Assumes attributes have already been declared.
 * Do not copy key attribute for edges, as this must be distinct.
 * Returns non-zero on failure or if objects have different type.
 */
int agcopyattr(void *oldobj, void *newobj)
{
    Agraph_t *g;
    Agsym_t *sym;
    Agsym_t *newsym;
    char* val;
    char* nval;
    int r = 1;

    g = agraphof(oldobj);
    if (AGTYPE(oldobj) != AGTYPE(newobj))
	return 1;
    sym = 0;
    while ((sym = agnxtattr(g, AGTYPE(oldobj), sym))) {
	newsym = agattrsym(newobj, sym->name);
	if (!newsym)
	    return 1;
	val = agxget(oldobj, sym);
	r = agxset(newobj, newsym, val);
	/* FIX(?): Each graph has its own string cache, so a whole new refstr is possibly
	 * allocated. If the original was an html string, make sure the new one is as well.
	 * If cgraph goes to single string table, this can be removed.
	 */
	if (aghtmlstr (val)) {
	    nval = agxget (newobj, newsym);
	    agmarkhtmlstr (nval);
	}
    }
    return r;
}
