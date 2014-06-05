#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.h" 1
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




/* for sincos */




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1



#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
































































    









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




#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1






































    extern void *zmalloc(size_t);
    extern void *zrealloc(void *, size_t, size_t, size_t);
    extern void *gmalloc(size_t);
	extern void *grealloc(void *, size_t);







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


























#line 17 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.h" 2

typedef struct Multilevel_struct *Multilevel;

struct Multilevel_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A;/* the weighting matrix */
  SparseMatrix D;/* the distance matrix. A and D should have same pattern, 
		    but different entry values. For spring-electrical method, D = NULL. */
  SparseMatrix P; 
  SparseMatrix R; 
  double *node_weights;
  Multilevel next;
  Multilevel prev;
  int delete_top_level_A;
  int coarsen_scheme_used;/* to get from previous level to here */
};

enum {MAX_IND_VTX_SET_U = -100, MAX_IND_VTX_SET_F = -1, MAX_IND_VTX_SET_C = 0};

enum {MAX_CLUSTER_SIZE = 4};

enum {EDGE_BASED_STA, COARSEN_INDEPENDENT_EDGE_SET, COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE, COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_LEAVES_FIRST, COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST, COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_DEGREE_SCALED, COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_CLUSTER_PERNODE_LEAVES_FIRST, EDGE_BASED_STO, VERTEX_BASED_STA, COARSEN_INDEPENDENT_VERTEX_SET, COARSEN_INDEPENDENT_VERTEX_SET_RS, VERTEX_BASED_STO, COARSEN_HYBRID};

enum {COARSEN_MODE_GENTLE, COARSEN_MODE_FORCEFUL};

struct Multilevel_control_struct {
  int minsize;
  double min_coarsen_factor;
  int maxlevel;
  int randomize;
  int coarsen_scheme;
  int coarsen_mode;
};

typedef struct Multilevel_control_struct *Multilevel_control;

Multilevel_control Multilevel_control_new(int scheme, int mode);

void Multilevel_control_delete(Multilevel_control ctrl);

void Multilevel_delete(Multilevel grid);

Multilevel Multilevel_new(SparseMatrix A, SparseMatrix D, double *node_weights, Multilevel_control ctrl);

Multilevel Multilevel_get_coarsest(Multilevel grid);

void print_padding(int n);




void Multilevel_coarsen(SparseMatrix A, SparseMatrix *cA, SparseMatrix D, SparseMatrix *cD, double *node_wgt, double **cnode_wgt,
			SparseMatrix *P, SparseMatrix *R, Multilevel_control ctrl, int *coarsen_scheme_used);

#line 16 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.h" 1


#line 1 "graphviz-2.38.0\\lib\\sparse\\LinkedList.h" 1
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




typedef struct SingleLinkedList_struct* SingleLinkedList;

struct SingleLinkedList_struct {
  void *data;
  SingleLinkedList next;
};

SingleLinkedList SingleLinkedList_new(void *data);
SingleLinkedList SingleLinkedList_new_int(int i);
void SingleLinkedList_delete(SingleLinkedList head, void (*linklist_deallocator)(void*));
SingleLinkedList SingleLinkedList_prepend(SingleLinkedList l, void *data);
SingleLinkedList SingleLinkedList_prepend_int(SingleLinkedList l, int i);

void* SingleLinkedList_get_data(SingleLinkedList l);

SingleLinkedList SingleLinkedList_get_next(SingleLinkedList l);

void SingleLinkedList_print(SingleLinkedList head, void (*linkedlist_print)(void*));


typedef struct DoubleLinkedList_struct* DoubleLinkedList;

struct DoubleLinkedList_struct {
  void *data;
  DoubleLinkedList next;
  DoubleLinkedList prev;
};

DoubleLinkedList DoubleLinkedList_new(void *data);
void DoubleLinkedList_delete(DoubleLinkedList head, void (*linklist_deallocator)(void*));
DoubleLinkedList DoubleLinkedList_prepend(DoubleLinkedList l, void *data);

void* DoubleLinkedList_get_data(DoubleLinkedList l);

DoubleLinkedList DoubleLinkedList_get_next(DoubleLinkedList l);

void DoubleLinkedList_delete_element(DoubleLinkedList l,  void (*linklist_deallocator)(void*), DoubleLinkedList *head);

#line 3 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.h" 2
struct PriorityQueue_struct {
  /* a simple priority queue structure: entries are all integers, gains are all integers in [0, gainmax], total n elements */
  int count;/* how many entries are in?*/

  /* max index value of an entry */
  int n;

  /* only ngain buckets are allowed */
  int ngain;

  /* current highest gain */
  int gain_max;

  /* the ngain buckets. Each bucket i holds all entries with gain = i.*/
  DoubleLinkedList *buckets;

  /* a mapping which maps an entry's index to an element in a DoubleLinkedList */
  DoubleLinkedList *where;

  /* the gain of entry i is gain[i] */
  int *gain;
};

typedef struct PriorityQueue_struct *PriorityQueue;


PriorityQueue PriorityQueue_new(int n, int ngain);

void PriorityQueue_delete(PriorityQueue q);

/* if entry i is already in the list, then an update of gain is carried out*/
PriorityQueue PriorityQueue_push(PriorityQueue q, int i, int gain);

int PriorityQueue_pop(PriorityQueue q, int *i, int *gain);/* return 0 if nmothing left, 1 otherwise */

int PriorityQueue_remove(PriorityQueue q, int i);/* return 0 if error */
int PriorityQueue_get_gain(PriorityQueue q, int i);


#line 17 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 2
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











































    
    
    
	







#line 18 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 2
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


















































#line 19 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 1
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














































































    









#line 21 "graphviz-2.38.0\\lib\\sfdpgen\\Multilevel.c" 2


Multilevel_control Multilevel_control_new(int scheme, int mode){
  Multilevel_control ctrl;

  ctrl = (struct Multilevel_control_struct*)gmalloc(sizeof(struct Multilevel_control_struct));
  ctrl->minsize = 4;
  ctrl->min_coarsen_factor = 0.75;
  ctrl->maxlevel = 1<<30;
  ctrl->randomize = (!(0));
  /* now set in spring_electrical_control_new(), as well as by command line argument -c
    ctrl->coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_CLUSTER_PERNODE_LEAVES_FIRST;
    ctrl->coarsen_scheme = COARSEN_INDEPENDENT_VERTEX_SET_RS;
    ctrl->coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE;
    ctrl->coarsen_scheme = COARSEN_HYBRID;
    ctrl->coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST;
    ctrl->coarsen_mode = COARSEN_MODE_FORCEFUL; or COARSEN_MODE_GENTLE;
  */

  ctrl->coarsen_scheme = scheme;
  ctrl->coarsen_mode = mode;
  return ctrl;
}

void Multilevel_control_delete(Multilevel_control ctrl){
  free(ctrl);
}

static Multilevel Multilevel_init(SparseMatrix A, SparseMatrix D, double *node_weights){
  Multilevel grid;
  if (!A) return (void *)0;
  assert(A->m == A->n);
  grid = (struct Multilevel_struct*)gmalloc(sizeof(struct Multilevel_struct));
  grid->level = 0;
  grid->n = A->n;
  grid->A = A;
  grid->D = D;
  grid->P = (void *)0;
  grid->R = (void *)0;
  grid->node_weights = node_weights;
  grid->next = (void *)0;
  grid->prev = (void *)0;
  grid->delete_top_level_A = (0);
  return grid;
}

void Multilevel_delete(Multilevel grid){
  if (!grid) return;
  if (grid->A){
    if (grid->level == 0) {
      if (grid->delete_top_level_A) {
	SparseMatrix_delete(grid->A);
	if (grid->D) SparseMatrix_delete(grid->D);
      }
    } else {
      SparseMatrix_delete(grid->A);
      if (grid->D) SparseMatrix_delete(grid->D);
    }
  }
  SparseMatrix_delete(grid->P);
  SparseMatrix_delete(grid->R);
  if (grid->node_weights && grid->level > 0) free(grid->node_weights);
  Multilevel_delete(grid->next);
  free(grid);
}

static void maximal_independent_vertex_set(SparseMatrix A, int randomize, int **vset, int *nvset, int *nzc){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0;
  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *vset = (int*)gmalloc((m)*sizeof(int));
  for (i = 0; i < m; i++) (*vset)[i] = MAX_IND_VTX_SET_U;
  *nvset = 0;
  *nzc = 0;

  if (!randomize){
    for (i = 0; i < m; i++){
      if ((*vset)[i] == MAX_IND_VTX_SET_U){
	(*vset)[i] = (*nvset)++;
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (i == ja[j]) continue;
	  (*vset)[ja[j]] = MAX_IND_VTX_SET_F;
	  (*nzc)++;
	}
      }
    }
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      if ((*vset)[i] == MAX_IND_VTX_SET_U){
	(*vset)[i] = (*nvset)++;
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (i == ja[j]) continue;
	  (*vset)[ja[j]] = MAX_IND_VTX_SET_F;
	  (*nzc)++;
	}
      }
    }
    free(p);
  }
  (*nzc) += *nvset;
}


static void maximal_independent_vertex_set_RS(SparseMatrix A, int randomize, int **vset, int *nvset, int *nzc){
  /* The Ruge-Stuben coarsening scheme. Initially all vertices are in the U set (with marker MAX_IND_VTX_SET_U),
     with gain equal to their degree. Select vertex with highest gain into a C set (with
     marker >= MAX_IND_VTX_SET_C), and their neighbors j in F set (with marker MAX_IND_VTX_SET_F). The neighbors of
     j that are in the U set get their gains incremented by 1. So overall 
     gain[k] = |{neighbor of k in U set}|+2*|{neighbors of k in F set}|.
     nzc is the number of entries in the restriction matrix
   */
  int i, jj, ii, *p = (void *)0, j, k, *ia, *ja, m, n, gain, removed, nf = 0;
  PriorityQueue q;
  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));

  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *vset = (int*)gmalloc((m)*sizeof(int));
  for (i = 0; i < m; i++) {
    (*vset)[i] = MAX_IND_VTX_SET_U;
  }
  *nvset = 0;
  *nzc = 0;

  q = PriorityQueue_new(m, 2*(m-1));

  if (!randomize){
    for (i = 0; i < m; i++)
      PriorityQueue_push(q, i, ia[i+1] - ia[i]);
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      PriorityQueue_push(q, i, ia[i+1] - ia[i]);
    }
    free(p);
  }

  while (PriorityQueue_pop(q, &i, &gain)){
    assert((*vset)[i] == MAX_IND_VTX_SET_U);
    (*vset)[i] = (*nvset)++; 
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      assert((*vset)[jj] == MAX_IND_VTX_SET_U || (*vset)[jj] == MAX_IND_VTX_SET_F);
      if (i == jj) continue;
      
      if ((*vset)[jj] == MAX_IND_VTX_SET_U){
	removed = PriorityQueue_remove(q, jj);
	assert(removed);
	(*vset)[jj] = MAX_IND_VTX_SET_F;
	nf++;
	
	for (k = ia[jj]; k < ia[jj+1]; k++){
	  if (jj == ja[k]) continue;
	  if ((*vset)[ja[k]] == MAX_IND_VTX_SET_U){
	    gain = PriorityQueue_get_gain(q, ja[k]);
	    assert(gain >= 0);
	    PriorityQueue_push(q, ja[k], gain + 1);
	  }
	}
      }
      (*nzc)++;
    }
  }
  (*nzc) += *nvset;
  PriorityQueue_delete(q);
  
}



static void maximal_independent_edge_set(SparseMatrix A, int randomize, int **matching, int *nmatch){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0;
  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *matching = (int*)gmalloc((m)*sizeof(int));
  for (i = 0; i < m; i++) (*matching)[i] = i;
  *nmatch = n;

  if (!randomize){
    for (i = 0; i < m; i++){
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  (*matching)[ja[j]] = i;
	  (*matching)[i] = ja[j];
	  (*nmatch)--;
	}
      }
    }
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  (*matching)[ja[j]] = i;
	  (*matching)[i] = ja[j];
	  (*nmatch)--;
	}
      }
    }
    free(p);
  }
}



static void maximal_independent_edge_set_heavest_edge_pernode(SparseMatrix A, int randomize, int **matching, int *nmatch){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0;
  double *a, amax = 0;
  int first = (!(0)), jamax = 0;

  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *matching = (int*)gmalloc((m)*sizeof(int));
  for (i = 0; i < m; i++) (*matching)[i] = i;
  *nmatch = n;

  assert(SparseMatrix_is_symmetric(A, (0)));
  assert(A->type == MATRIX_TYPE_REAL);

  a = (double*) A->a;
  if (!randomize){
    for (i = 0; i < m; i++){
      first = (!(0));
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  (*matching)[jamax] = i;
	  (*matching)[i] = jamax;
	  (*nmatch)--;
      }
    }
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      if ((*matching)[i] != i) continue;
      first = (!(0));
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  (*matching)[jamax] = i;
	  (*matching)[i] = jamax;
	  (*nmatch)--;
      }
    }
    free(p);
  }
}







static void maximal_independent_edge_set_heavest_edge_pernode_leaves_first(SparseMatrix A, int randomize, int **cluster, int **clusterp, int *ncluster){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0, q;
  double *a, amax = 0;
  int first = (!(0)), jamax = 0;
  int *matched, nz, ncmax = 0, nz0, nzz,k ;
  enum {UNMATCHED = -2, MATCHED = -1};

  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *cluster = (int*)gmalloc((m)*sizeof(int));
  *clusterp = (int*)gmalloc(((m+1))*sizeof(int));
  matched = (int*)gmalloc((m)*sizeof(int));

  for (i = 0; i < m; i++) matched[i] = i;

  assert(SparseMatrix_is_symmetric(A, (0)));
  assert(A->type == MATRIX_TYPE_REAL);

  *ncluster = 0;
  (*clusterp)[0] = 0;
  nz = 0;
  a = (double*) A->a;
  if (!randomize){
    for (i = 0; i < m; i++){
      if (matched[i] == MATCHED || (ia[(i)+1] - ia[(i)]) != 1) continue;
      q = ja[ia[i]];
      assert(matched[q] != MATCHED);
      matched[q] = MATCHED;
      (*cluster)[nz++] = q;
      for (j = ia[q]; j < ia[q+1]; j++){
	if (q == ja[j]) continue;
	if ((ia[(ja[j])+1] - ia[(ja[j])]) == 1){
	  matched[ja[j]] = MATCHED;
	  (*cluster)[nz++] = ja[j];
	}
      }
      ncmax = ((ncmax)>(nz -(*clusterp)[*ncluster])?(ncmax):(nz -(*clusterp)[*ncluster]));
      nz0 = (*clusterp)[*ncluster];
      if (nz - nz0 <= MAX_CLUSTER_SIZE){
	(*clusterp)[++(*ncluster)] = nz;
      } else {
	(*clusterp)[++(*ncluster)] = ++nz0;	
	nzz = nz0;
	for (k = nz0; k < nz && nzz < nz; k++){
	  nzz += MAX_CLUSTER_SIZE - 1;
	  nzz = ((nz)<(nzz)?(nz):(nzz));
	  (*clusterp)[++(*ncluster)] = nzz;
	}
      }

    }
 
   
     

    for (i = 0; i < m; i++){
      first = (!(0));
      if (matched[i] == MATCHED) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if (matched[ja[j]] != MATCHED && matched[i] != MATCHED){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  matched[jamax] = MATCHED;
	  matched[i] = MATCHED;
	  (*cluster)[nz++] = i;
	  (*cluster)[nz++] = jamax;
	  (*clusterp)[++(*ncluster)] = nz;
      }
    }

    /* dan yi dian, wu ban */
    for (i = 0; i < m; i++){
      if (matched[i] == i){
	(*cluster)[nz++] = i;
	(*clusterp)[++(*ncluster)] = nz;
      }
    }
    assert(nz == n);
    
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      if (matched[i] == MATCHED || (ia[(i)+1] - ia[(i)]) != 1) continue;
      q = ja[ia[i]];
      assert(matched[q] != MATCHED);
      matched[q] = MATCHED;
      (*cluster)[nz++] = q;
      for (j = ia[q]; j < ia[q+1]; j++){
	if (q == ja[j]) continue;
	if ((ia[(ja[j])+1] - ia[(ja[j])]) == 1){
	  matched[ja[j]] = MATCHED;
	  (*cluster)[nz++] = ja[j];
	}
      }
      ncmax = ((ncmax)>(nz -(*clusterp)[*ncluster])?(ncmax):(nz -(*clusterp)[*ncluster]));
      nz0 = (*clusterp)[*ncluster];
      if (nz - nz0 <= MAX_CLUSTER_SIZE){
	(*clusterp)[++(*ncluster)] = nz;
      } else {
	(*clusterp)[++(*ncluster)] = ++nz0;	
	nzz = nz0;
	for (k = nz0; k < nz && nzz < nz; k++){
	  nzz += MAX_CLUSTER_SIZE - 1;
	  nzz = ((nz)<(nzz)?(nz):(nzz));
	  (*clusterp)[++(*ncluster)] = nzz;
	}
      }
    }

 
    
      

    for (ii = 0; ii < m; ii++){
      i = p[ii];
      first = (!(0));
      if (matched[i] == MATCHED) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if (matched[ja[j]] != MATCHED && matched[i] != MATCHED){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  matched[jamax] = MATCHED;
	  matched[i] = MATCHED;
	  (*cluster)[nz++] = i;
	  (*cluster)[nz++] = jamax;
	  (*clusterp)[++(*ncluster)] = nz;
      }
    }

    /* dan yi dian, wu ban */
    for (i = 0; i < m; i++){
      if (matched[i] == i){
	(*cluster)[nz++] = i;
	(*clusterp)[++(*ncluster)] = nz;
      }
    }

    free(p);
  }

  free(matched);
}



static void maximal_independent_edge_set_heavest_edge_pernode_supernodes_first(SparseMatrix A, int randomize, int **cluster, int **clusterp, int *ncluster){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0;
  double *a, amax = 0;
  int first = (!(0)), jamax = 0;
  int *matched, nz, nz0;
  enum {UNMATCHED = -2, MATCHED = -1};
  int  nsuper, *super = (void *)0, *superp = (void *)0;

  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *cluster = (int*)gmalloc((m)*sizeof(int));
  *clusterp = (int*)gmalloc(((m+1))*sizeof(int));
  matched = (int*)gmalloc((m)*sizeof(int));

  for (i = 0; i < m; i++) matched[i] = i;

  assert(SparseMatrix_is_symmetric(A, (0)));
  assert(A->type == MATRIX_TYPE_REAL);

  SparseMatrix_decompose_to_supervariables(A, &nsuper, &super, &superp);

  *ncluster = 0;
  (*clusterp)[0] = 0;
  nz = 0;
  a = (double*) A->a;

  for (i = 0; i < nsuper; i++){
    if (superp[i+1] - superp[i] <= 1) continue;
    nz0 = (*clusterp)[*ncluster];
    for (j = superp[i]; j < superp[i+1]; j++){
      matched[super[j]] = MATCHED;
      (*cluster)[nz++] = super[j];
      if (nz - nz0 >= MAX_CLUSTER_SIZE){
	(*clusterp)[++(*ncluster)] = nz;
	nz0 = nz;
      }
    }
    if (nz > nz0) (*clusterp)[++(*ncluster)] = nz;
  }

  if (!randomize){
    for (i = 0; i < m; i++){
      first = (!(0));
      if (matched[i] == MATCHED) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if (matched[ja[j]] != MATCHED && matched[i] != MATCHED){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  matched[jamax] = MATCHED;
	  matched[i] = MATCHED;
	  (*cluster)[nz++] = i;
	  (*cluster)[nz++] = jamax;
	  (*clusterp)[++(*ncluster)] = nz;
      }
    }

    /* dan yi dian, wu ban */
    for (i = 0; i < m; i++){
      if (matched[i] == i){
	(*cluster)[nz++] = i;
	(*clusterp)[++(*ncluster)] = nz;
      }
    }
    assert(nz == n);
    
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      first = (!(0));
      if (matched[i] == MATCHED) continue;
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if (matched[ja[j]] != MATCHED && matched[i] != MATCHED){
	  if (first) {
	    amax = a[j];
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j] > amax){
	      amax = a[j];
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  matched[jamax] = MATCHED;
	  matched[i] = MATCHED;
	  (*cluster)[nz++] = i;
	  (*cluster)[nz++] = jamax;
	  (*clusterp)[++(*ncluster)] = nz;
      }
    }

    /* dan yi dian, wu ban */
    for (i = 0; i < m; i++){
      if (matched[i] == i){
	(*cluster)[nz++] = i;
	(*clusterp)[++(*ncluster)] = nz;
      }
    }
    free(p);

  }

  free(super);

  free(superp);

  free(matched);
}

static int scomp(const void *s1, const void *s2){
  double *ss1, *ss2;
  ss1 = (double*) s1;
  ss2 = (double*) s2;

  if ((ss1)[1] > (ss2)[1]){
    return -1;
  } else if ((ss1)[1] < (ss2)[1]){
    return 1;
  }
  return 0;
}

static void maximal_independent_edge_set_heavest_cluster_pernode_leaves_first(SparseMatrix A, int csize, 
									      int randomize, int **cluster, int **clusterp, int *ncluster){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0, q, iv;
  double *a;
  int *matched, nz,  nz0, nzz,k, nv;
  enum {UNMATCHED = -2, MATCHED = -1};
  double *vlist;

  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *cluster = (int*)gmalloc((m)*sizeof(int));
  *clusterp = (int*)gmalloc(((m+1))*sizeof(int));
  matched = (int*)gmalloc((m)*sizeof(int));
  vlist = (double*)gmalloc((2*m)*sizeof(double));

  for (i = 0; i < m; i++) matched[i] = i;

  assert(SparseMatrix_is_symmetric(A, (0)));
  assert(A->type == MATRIX_TYPE_REAL);

  *ncluster = 0;
  (*clusterp)[0] = 0;
  nz = 0;
  a = (double*) A->a;

  p = random_permutation(m);
  for (ii = 0; ii < m; ii++){
    i = p[ii];
    if (matched[i] == MATCHED || (ia[(i)+1] - ia[(i)]) != 1) continue;
    q = ja[ia[i]];
    assert(matched[q] != MATCHED);
    matched[q] = MATCHED;
    (*cluster)[nz++] = q;
    for (j = ia[q]; j < ia[q+1]; j++){
      if (q == ja[j]) continue;
      if ((ia[(ja[j])+1] - ia[(ja[j])]) == 1){
	matched[ja[j]] = MATCHED;
	(*cluster)[nz++] = ja[j];
      }
    }
    nz0 = (*clusterp)[*ncluster];
    if (nz - nz0 <= MAX_CLUSTER_SIZE){
      (*clusterp)[++(*ncluster)] = nz;
    } else {
      (*clusterp)[++(*ncluster)] = ++nz0;	
      nzz = nz0;
      for (k = nz0; k < nz && nzz < nz; k++){
	nzz += MAX_CLUSTER_SIZE - 1;
	nzz = ((nz)<(nzz)?(nz):(nzz));
	(*clusterp)[++(*ncluster)] = nzz;
      }
    }
  }
  
  for (ii = 0; ii < m; ii++){
    i = p[ii];
    if (matched[i] == MATCHED) continue;
    nv = 0;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (i == ja[j]) continue;
      if (matched[ja[j]] != MATCHED && matched[i] != MATCHED){
	vlist[2*nv] = ja[j];
	vlist[2*nv+1] = a[j];
	nv++;
      }
    }
    if (nv > 0){
      qsort(vlist, nv, sizeof(double)*2, scomp);
      for (j = 0; j < ((csize - 1)<(nv)?(csize - 1):(nv)); j++){
	iv = (int) vlist[2*j];
	matched[iv] = MATCHED;
	(*cluster)[nz++] = iv;
      }
      matched[i] = MATCHED;
      (*cluster)[nz++] = i;
      (*clusterp)[++(*ncluster)] = nz;
    }
  }
  
  /* dan yi dian, wu ban */
  for (i = 0; i < m; i++){
    if (matched[i] == i){
      (*cluster)[nz++] = i;
      (*clusterp)[++(*ncluster)] = nz;
    }
  }
  free(p);


  free(matched);
}
static void maximal_independent_edge_set_heavest_edge_pernode_scaled(SparseMatrix A, int randomize, int **matching, int *nmatch){
  int i, ii, j, *ia, *ja, m, n, *p = (void *)0;
  double *a, amax = 0;
  int first = (!(0)), jamax = 0;

  assert(A);
  assert((((A)->property)&(MATRIX_PATTERN_SYMMETRIC)));
  ia = A->ia;
  ja = A->ja;
  m = A->m;
  n = A->n;
  assert(n == m);
  *matching = (int*)gmalloc((m)*sizeof(int));
  for (i = 0; i < m; i++) (*matching)[i] = i;
  *nmatch = n;

  assert(SparseMatrix_is_symmetric(A, (0)));
  assert(A->type == MATRIX_TYPE_REAL);

  a = (double*) A->a;
  if (!randomize){
    for (i = 0; i < m; i++){
      first = (!(0));
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  if (first) {
	    amax = a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]);
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]) > amax){
	      amax = a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]);
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  (*matching)[jamax] = i;
	  (*matching)[i] = jamax;
	  (*nmatch)--;
      }
    }
  } else {
    p = random_permutation(m);
    for (ii = 0; ii < m; ii++){
      i = p[ii];
      if ((*matching)[i] != i) continue;
      first = (!(0));
      for (j = ia[i]; j < ia[i+1]; j++){
	if (i == ja[j]) continue;
	if ((*matching)[ja[j]] == ja[j] && (*matching)[i] == i){
	  if (first) {
	    amax = a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]);
	    jamax = ja[j];
	    first = (0);
	  } else {
	    if (a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]) > amax){
	      amax = a[j]/(ia[i+1]-ia[i])/(ia[ja[j]+1]-ia[ja[j]]);
	      jamax = ja[j];
	    }
	  }
	}
      }
      if (!first){
	  (*matching)[jamax] = i;
	  (*matching)[i] = jamax;
	  (*nmatch)--;
      }
    }
    free(p);
  }
}

SparseMatrix DistanceMatrix_restrict_cluster(int ncluster, int *clusterp, int *cluster, SparseMatrix P, SparseMatrix R, SparseMatrix D){

  
  
  
  
  
  
  
  
  
  
  
  


  
  
  

  
  
  
  
  
  
  


  


  
  
    
      
      
    
  

  
    
    
      
	
      
    
  
  
    
    
    
    
  

  
  
  
  
  
    
    
    
      
      
    
    
      
      
	
	
	  
	  
	
	
	
	
      
    
  

  
    
    
    
    
  


  
    
      
      
      
      
    
  
  
  
  
  
  
  

  
  
  
    
    
    
  
  
  
  

  

  return (void *)0;
}

SparseMatrix DistanceMatrix_restrict_matching(int *matching, SparseMatrix D){
  if (!D) return (void *)0;
  assert(0);/* not yet implemented! */
  return (void *)0;
}

SparseMatrix DistanceMatrix_restrict_filtering(int *mask, int is_C, int is_F, SparseMatrix D){
  /* max independent vtx set based coarsening. Coarsen nodes has mask >= is_C. Fine nodes == is_F. */
  if (!D) return (void *)0;
  assert(0);/* not yet implemented! */
  return (void *)0;
}

static void Multilevel_coarsen_internal(SparseMatrix A, SparseMatrix *cA, SparseMatrix D, SparseMatrix *cD,
					double *node_wgt, double **cnode_wgt,
					SparseMatrix *P, SparseMatrix *R, Multilevel_control ctrl, int *coarsen_scheme_used){
  int *matching = (void *)0, nmatch = 0, nc, nzc, n, i;
  int *irn = (void *)0, *jcn = (void *)0, *ia = (void *)0, *ja = (void *)0;
  double *val = (void *)0;
  SparseMatrix B = (void *)0;
  int *vset = (void *)0, nvset, ncov, j;
  int *cluster=(void *)0, *clusterp=(void *)0, ncluster;

  assert(A->m == A->n);
  *cA = (void *)0;
  *cD = (void *)0;
  *P = (void *)0;
  *R = (void *)0;
  n = A->m;

  *coarsen_scheme_used = ctrl->coarsen_scheme;

  switch (ctrl->coarsen_scheme){
  case COARSEN_HYBRID:

    
      

    *coarsen_scheme_used = ctrl->coarsen_scheme =  COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_LEAVES_FIRST;
    Multilevel_coarsen_internal(A, cA, D, cD, node_wgt, cnode_wgt, P, R, ctrl, coarsen_scheme_used);

    if (!(*cA)) {

      
        

      *coarsen_scheme_used = ctrl->coarsen_scheme =  COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST;
      Multilevel_coarsen_internal(A, cA, D, cD, node_wgt, cnode_wgt, P, R, ctrl, coarsen_scheme_used);
    }

    if (!(*cA)) {

      
        

      *coarsen_scheme_used = ctrl->coarsen_scheme =  COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_CLUSTER_PERNODE_LEAVES_FIRST;
      Multilevel_coarsen_internal(A, cA, D, cD, node_wgt, cnode_wgt, P, R, ctrl, coarsen_scheme_used);
    }

    if (!(*cA)) {

     
        

      *coarsen_scheme_used = ctrl->coarsen_scheme = COARSEN_INDEPENDENT_VERTEX_SET;
      Multilevel_coarsen_internal(A, cA, D, cD, node_wgt, cnode_wgt, P, R, ctrl, coarsen_scheme_used);
    }


    if (!(*cA)) {

      
        

      *coarsen_scheme_used = ctrl->coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE;
      Multilevel_coarsen_internal(A, cA, D, cD, node_wgt, cnode_wgt, P, R, ctrl, coarsen_scheme_used);
    }
    ctrl->coarsen_scheme = COARSEN_HYBRID;
    break;
  case  COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST:
  case  COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_CLUSTER_PERNODE_LEAVES_FIRST:
  case COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_LEAVES_FIRST:
    if (ctrl->coarsen_scheme == COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_LEAVES_FIRST) {
      maximal_independent_edge_set_heavest_edge_pernode_leaves_first(A, ctrl->randomize, &cluster, &clusterp, &ncluster);
    } else if (ctrl->coarsen_scheme == COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST) {
      maximal_independent_edge_set_heavest_edge_pernode_supernodes_first(A, ctrl->randomize, &cluster, &clusterp, &ncluster);
    } else {
      maximal_independent_edge_set_heavest_cluster_pernode_leaves_first(A, 4, ctrl->randomize, &cluster, &clusterp, &ncluster);
    }
    assert(ncluster <= n);
    nc = ncluster;
    if ((ctrl->coarsen_mode == COARSEN_MODE_GENTLE && nc > ctrl->min_coarsen_factor*n) || nc == n || nc < ctrl->minsize) {

      
        

      goto RETURN;
    }
    irn = (int*)gmalloc((n)*sizeof(int));
    jcn = (int*)gmalloc((n)*sizeof(int));
    val = (double*)gmalloc((n)*sizeof(double));
    nzc = 0; 
    for (i = 0; i < ncluster; i++){
      for (j = clusterp[i]; j < clusterp[i+1]; j++){
	assert(clusterp[i+1] > clusterp[i]);
	irn[nzc] = cluster[j];
	jcn[nzc] = i;
	val[nzc++] = 1.;
     }
    }
    assert(nzc == n);
    *P = SparseMatrix_from_coordinate_arrays(nzc, n, nc, irn, jcn, (void *) val, MATRIX_TYPE_REAL, sizeof(double));
    *R = SparseMatrix_transpose(*P);

    *cD = DistanceMatrix_restrict_cluster(ncluster, clusterp, cluster, *P, *R, D);

    *cA = SparseMatrix_multiply3(*R, A, *P); 

    /*
      B = SparseMatrix_multiply(*R, A);
      if (!B) goto RETURN;
      *cA = SparseMatrix_multiply(B, *P); 
      */
    if (!*cA) goto RETURN;

    SparseMatrix_multiply_vector(*R, node_wgt, cnode_wgt, (0));
    *R = SparseMatrix_divide_row_by_degree(*R);
    (((*cA)->property)=(((*cA)->property)|(MATRIX_SYMMETRIC)));
    (((*cA)->property)=(((*cA)->property)|(MATRIX_PATTERN_SYMMETRIC)));
    *cA = SparseMatrix_remove_diagonal(*cA);



    break;
  case COARSEN_INDEPENDENT_EDGE_SET:
    maximal_independent_edge_set(A, ctrl->randomize, &matching, &nmatch);
  case COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE:
    if (ctrl->coarsen_scheme == COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE) 
      maximal_independent_edge_set_heavest_edge_pernode(A, ctrl->randomize, &matching, &nmatch);
  case COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_DEGREE_SCALED:
    if (ctrl->coarsen_scheme == COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_DEGREE_SCALED) 
      maximal_independent_edge_set_heavest_edge_pernode_scaled(A, ctrl->randomize, &matching, &nmatch);
    nc = nmatch;
    if ((ctrl->coarsen_mode == COARSEN_MODE_GENTLE && nc > ctrl->min_coarsen_factor*n) || nc == n || nc < ctrl->minsize) {

      
        

      goto RETURN;
    }
    irn = (int*)gmalloc((n)*sizeof(int));
    jcn = (int*)gmalloc((n)*sizeof(int));
    val = (double*)gmalloc((n)*sizeof(double));
    nzc = 0; nc = 0;
    for (i = 0; i < n; i++){
      if (matching[i] >= 0){
	if (matching[i] == i){
	  irn[nzc] = i;
	  jcn[nzc] = nc;
	  val[nzc++] = 1.;
	} else {
	  irn[nzc] = i;
	  jcn[nzc] = nc;
	  val[nzc++] = 1;
	  irn[nzc] = matching[i];
	  jcn[nzc] = nc;
	  val[nzc++] = 1;
	  matching[matching[i]] = -1;
	}
	nc++;
	matching[i] = -1;
      }
    }
    assert(nc == nmatch);
    assert(nzc == n);
    *P = SparseMatrix_from_coordinate_arrays(nzc, n, nc, irn, jcn, (void *) val, MATRIX_TYPE_REAL, sizeof(double));
    *R = SparseMatrix_transpose(*P);
    *cA = SparseMatrix_multiply3(*R, A, *P); 
    /*
      B = SparseMatrix_multiply(*R, A);
      if (!B) goto RETURN;
      *cA = SparseMatrix_multiply(B, *P); 
      */
    if (!*cA) goto RETURN;
    SparseMatrix_multiply_vector(*R, node_wgt, cnode_wgt, (0));
    *R = SparseMatrix_divide_row_by_degree(*R);
    (((*cA)->property)=(((*cA)->property)|(MATRIX_SYMMETRIC)));
    (((*cA)->property)=(((*cA)->property)|(MATRIX_PATTERN_SYMMETRIC)));
    *cA = SparseMatrix_remove_diagonal(*cA);


    *cD = DistanceMatrix_restrict_matching(matching, D);
    *cD=(void *)0;

    break;
  case COARSEN_INDEPENDENT_VERTEX_SET:
  case COARSEN_INDEPENDENT_VERTEX_SET_RS:
    if (ctrl->coarsen_scheme == COARSEN_INDEPENDENT_VERTEX_SET){
      maximal_independent_vertex_set(A, ctrl->randomize, &vset, &nvset, &nzc);
    } else {
      maximal_independent_vertex_set_RS(A, ctrl->randomize, &vset, &nvset, &nzc);
    }
    ia = A->ia;
    ja = A->ja;
    nc = nvset;
    if ((ctrl->coarsen_mode == COARSEN_MODE_GENTLE && nc > ctrl->min_coarsen_factor*n) || nc == n || nc < ctrl->minsize) {

      
        

      goto RETURN;
    }
    irn = (int*)gmalloc((nzc)*sizeof(int));
    jcn = (int*)gmalloc((nzc)*sizeof(int));
    val = (double*)gmalloc((nzc)*sizeof(double));
    nzc = 0; 
    for (i = 0; i < n; i++){
      if (vset[i] == MAX_IND_VTX_SET_F){
	ncov = 0;
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (vset[ja[j]] >= MAX_IND_VTX_SET_C){
	    ncov++;
	  }
	}
	assert(ncov > 0);
	for (j = ia[i]; j < ia[i+1]; j++){
	  if (vset[ja[j]] >= MAX_IND_VTX_SET_C){
	    irn[nzc] = i;
	    jcn[nzc] = vset[ja[j]];
	    val[nzc++] = 1./(double) ncov;
	  }
	}
      } else {
	assert(vset[i] >= MAX_IND_VTX_SET_C);
	irn[nzc] = i;
	jcn[nzc] = vset[i];
	val[nzc++] = 1.;
      }
    }

    *P = SparseMatrix_from_coordinate_arrays(nzc, n, nc, irn, jcn, (void *) val, MATRIX_TYPE_REAL, sizeof(double));
    *R = SparseMatrix_transpose(*P);
    *cA = SparseMatrix_multiply3(*R, A, *P); 
    if (!*cA) goto RETURN;
    SparseMatrix_multiply_vector(*R, node_wgt, cnode_wgt, (0));
    (((*cA)->property)=(((*cA)->property)|(MATRIX_SYMMETRIC)));
    (((*cA)->property)=(((*cA)->property)|(MATRIX_PATTERN_SYMMETRIC)));
    *cA = SparseMatrix_remove_diagonal(*cA);

    *cD = DistanceMatrix_restrict_filtering(vset, MAX_IND_VTX_SET_C, MAX_IND_VTX_SET_F, D);
    break;
  default:
    goto RETURN;
  }
 RETURN:
  if (matching) free(matching);
  if (vset) free(vset);
  if (irn) free(irn);
  if (jcn) free(jcn);
  if (val) free(val);
  if (B) SparseMatrix_delete(B);

  if(cluster) free(cluster);
  if(clusterp) free(clusterp);
}

void Multilevel_coarsen(SparseMatrix A, SparseMatrix *cA, SparseMatrix D, SparseMatrix *cD, double *node_wgt, double **cnode_wgt,
			       SparseMatrix *P, SparseMatrix *R, Multilevel_control ctrl, int *coarsen_scheme_used){
  SparseMatrix cA0 = A,  cD0 = (void *)0, P0 = (void *)0, R0 = (void *)0, M;
  double *cnode_wgt0 = (void *)0;
  int nc = 0, n;
  
  *P = (void *)0; *R = (void *)0; *cA = (void *)0; *cnode_wgt = (void *)0, *cD = (void *)0;

  n = A->n;

  do {/* this loop force a sufficient reduction */
    node_wgt = cnode_wgt0;
    Multilevel_coarsen_internal(A, &cA0, D, &cD0, node_wgt, &cnode_wgt0, &P0, &R0, ctrl, coarsen_scheme_used);
    if (!cA0) return;
    nc = cA0->n;

    

    if (*P){
      assert(*R);
      M = SparseMatrix_multiply(*P, P0);
      SparseMatrix_delete(*P);
      SparseMatrix_delete(P0);
      *P = M;
      M = SparseMatrix_multiply(R0, *R);
      SparseMatrix_delete(*R);
      SparseMatrix_delete(R0);
      *R = M;
    } else {
      *P = P0;
      *R = R0;
    }

    if (*cA) SparseMatrix_delete(*cA);
    *cA = cA0;
    if (*cD) SparseMatrix_delete(*cD);
    *cD = cD0;

    if (*cnode_wgt) free(*cnode_wgt);
    *cnode_wgt = cnode_wgt0;
    A = cA0;
    D = cD0;
    node_wgt = cnode_wgt0;
    cnode_wgt0 = (void *)0;
  } while (nc > ctrl->min_coarsen_factor*n && ctrl->coarsen_mode ==  COARSEN_MODE_FORCEFUL);

}

void print_padding(int n){
  int i;
  for (i = 0; i < n; i++) fputs (" ", stderr);
}
static Multilevel Multilevel_establish(Multilevel grid, Multilevel_control ctrl){
  Multilevel cgrid;
  int coarsen_scheme_used;
  double *cnode_weights = (void *)0;
  SparseMatrix P, R, A, cA, D, cD;


  
    
    
  

  A = grid->A;
  D = grid->D;
  if (grid->level >= ctrl->maxlevel - 1) {

  
    
    
  

    return grid;
  }
  Multilevel_coarsen(A, &cA, D, &cD, grid->node_weights, &cnode_weights, &P, &R, ctrl, &coarsen_scheme_used);
  if (!cA) return grid;

  cgrid = Multilevel_init(cA, cD, cnode_weights);
  grid->next = cgrid;
  cgrid->coarsen_scheme_used = coarsen_scheme_used;
  cgrid->level = grid->level + 1;
  cgrid->n = cA->m;
  cgrid->A = cA;
  cgrid->D = cD;
  cgrid->P = P;
  grid->R = R;
  cgrid->prev = grid;
  cgrid = Multilevel_establish(cgrid, ctrl);
  return grid;
  
}

Multilevel Multilevel_new(SparseMatrix A0, SparseMatrix D0, double *node_weights, Multilevel_control ctrl){
  /* A: the weighting matrix. D: the distance matrix, could be NULL. If not null, the two matrices must have the same sparsity pattern */
  Multilevel grid;
  SparseMatrix A = A0, D = D0;

  if (!SparseMatrix_is_symmetric(A, (0)) || A->type != MATRIX_TYPE_REAL){
    A = SparseMatrix_get_real_adjacency_matrix_symmetrized(A);
  }
  if (D && (!SparseMatrix_is_symmetric(D, (0)) || D->type != MATRIX_TYPE_REAL)){
    D = SparseMatrix_symmetrize_nodiag(D, (0));
  }
  grid = Multilevel_init(A, D, node_weights);
  grid = Multilevel_establish(grid, ctrl);
  if (A != A0) grid->delete_top_level_A = (!(0));/* be sure to clean up later */
  return grid;
}


Multilevel Multilevel_get_coarsest(Multilevel grid){
  while (grid->next){
    grid = grid->next;
  }
  return grid;
}

