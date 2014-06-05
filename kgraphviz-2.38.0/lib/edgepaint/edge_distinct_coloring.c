#line 1 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 1
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





#line 12 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2
#line 1 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 1
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


























#line 14 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2
#line 1 "graphviz-2.38.0\\lib\\edgepaint\\node_distinct_coloring.h" 1
/*************************************************************************
 * Copyright (c) 2014 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




enum {COLOR_RGB, COLOR_GRAY, COLOR_LAB};
enum {ERROR_BAD_LAB_GAMUT_FILE = -10, ERROR_BAD_COLOR_SCHEME = -9};
void node_distinct_coloring(char *color_scheme, char *lightness, int weightedQ, SparseMatrix A, double accuracy, int iter_max, int seed, int *cdim, double **colors, double *color_diff, double *color_diff_sum, int *flag);


#line 15 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 17 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 2
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














  
  
  
  
  
  
  
  
  
  
  





































































































			  


				










































#line 18 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 2

enum {COLOR_SCHEME_NONE, COLOR_SCHEME_PASTEL = 1, COLOR_SCHEME_BLUE_YELLOW, COLOR_SCHEME_WHITE_RED, COLOR_SCHEME_GREY_RED, COLOR_SCHEME_PRIMARY, COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED, COLOR_SCHEME_ADAM, COLOR_SCHEME_ADAM_BLEND, COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED_LIGHTER, COLOR_SCHEME_GREY};
extern void initDotIO (Agraph_t *g);
extern Agraph_t* SparseMatrix_read_dot(FILE*);

extern void setDotNodeID (Agnode_t* n, int v);
extern int getDotNodeID (Agnode_t* n);

extern void attach_edge_colors(Agraph_t* g, int dim, double *colors);

extern void attach_embedding(Agraph_t *g, int dim, double sc, double *x);

extern SparseMatrix SparseMatrix_import_dot(Agraph_t* g, int dim, double **label_sizes, double **x, int *n_edge_label_nodes,
					    int **edge_label_nodes, int format, SparseMatrix *D);
extern Agraph_t* makeDotGraph (SparseMatrix, char *title, int dim, double *x, int with_color, int with_label, int use_matrix_value);
Agraph_t *convert_edge_labels_to_nodes(Agraph_t* g);
Agraph_t* assign_random_edge_color(Agraph_t* g);
void dump_coordinates(char *name, int n, int dim, double *x);
void edgelist_export(FILE* f, SparseMatrix A, int dim, double *x);
char * hue2rgb(double hue, char *color);

SparseMatrix Import_coord_clusters_from_dot(Agraph_t* g, int maxcluster, int dim, int *nn, double **label_sizes, double **x, int **clusters, float **rgb_r,  float **rgb_g,  float **rgb_b,  float **fsz, char ***labels, int default_color_scheme, int clustering_scheme, int useClusters);

void Dot_SetClusterColor(Agraph_t* g, float *rgb_r,  float *rgb_g,  float *rgb_b, int *clustering);
void attached_clustering(Agraph_t* g, int maxcluster, int clustering_scheme);

int Import_dot_splines(Agraph_t* g, int *ne, char ***xsplines);

#line 16 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2
#line 1 "graphviz-2.38.0\\lib\\edgepaint\\intersection.h" 1
/*************************************************************************
 * Copyright (c) 2014 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




double intersection_angle(double *p1, double *p2, double *q1, double *q2);


#line 17 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\QuadTree.h" 1
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

#line 17 "graphviz-2.38.0\\lib\\sparse\\QuadTree.h" 2
/* #include "sfdpinternal.h" */
#line 1 "graphviz-2.38.0\\lib\\sparse\\QuadTree.h" 1

typedef struct QuadTree_struct *QuadTree;

struct QuadTree_struct {
  /* a data structure containing coordinates of n items, their average is in "average".
     The current level is a square or cube of width "width", which is subdivided into 
     2^dim QuadTrees qts. At the last level, all coordinates are stored in a single linked list l. 
     total_weight is the combined weights of the nodes */
  int n;/* number of items */
  double total_weight;
  int dim;
  double *center;/* center of the bounding box, array of dimension dim. Allocated inside */
  double width;/* center +/- width gives the lower/upper bound, so really width is the 
		"radius" */
  double *average;/* the average coordinates. Array of length dim. Allocated inside  */
  QuadTree *qts;/* subtree . If dim = 2, there are 4, dim = 3 gives 8 */
  SingleLinkedList l;
  int max_level;
  void *data;
};


QuadTree QuadTree_new(int dim, double *center, double width, int max_level);

void QuadTree_delete(QuadTree q);

QuadTree QuadTree_add(QuadTree q, double *coord, double weight, int id);/* coord is copied in */

void QuadTree_print(FILE *fp, QuadTree q);

QuadTree QuadTree_new_from_point_list(int dim, int n, int max_level, double *coord, double *weight);

double point_distance(double *p1, double *p2, int dim);

void QuadTree_get_supernodes(QuadTree qt, double bh, double *point, int nodeid, int *nsuper, 
			     int *nsupermax, double **center, double **supernode_wgts, double **distances, double *counts, int *flag);

void QuadTree_get_repulsive_force(QuadTree qt, double *force, double *x, double bh, double p, double KP, double *counts, int *flag);

/* find the nearest point and put in ymin, index in imin and distance in min */
void QuadTree_get_nearest(QuadTree qt, double *x, double *ymin, int *imin, double *min, int *flag);

QuadTree QuadTree_new_in_quadrant(int dim, double *center, double width, int max_level, int i);


#line 18 "graphviz-2.38.0\\lib\\edgepaint\\edge_distinct_coloring.c" 2

static int splines_intersect(int dim, int u1, int v1, int u2, int v2, 
			     double cos_critical, int check_edges_with_same_endpoint, 
			     double *x, char *xsplines1, char *xsplines2){
  /* u1, v2 an u2, v2: the node index of the two edn points of two edges.
     cos_critical: cos of critical angle
     check_edges_with_same_endpoint: whether need to treat two splines from
     .     the same end point specially in ignoring splines that exit/enter the same end pont at around 180
     x: the coordinates of nodes
     xsplines1,xsplines2: the first and second splines corresponding to two edges

  */
  int itmp;
  int len1 = 100, len2 = 100;
  double *x1, *x2;
  int ns1 = 0, ns2 = 0;
  int i, j, iter1 = 0, iter2 = 0;
  double cos_a, tmp[2];
  int endp1 = 0, endp2 = 0;

  tmp[0] = tmp[1] = 0;
  x1 = gmalloc(sizeof(double)*len1);
  x2 = gmalloc(sizeof(double)*len2);

  assert(dim <= 3);
  /* if two end points are the same, make sure they are the first in each edge */
  if (u1 == v2){/* switch u2 and v2 */
    itmp = u2; u2 = v2; v2 = itmp;
  } else if (v1 == u2){/* switch u1 and v1 */
    itmp = u1; u1 = v1; v1 = itmp;
  } else if (v1 == v2){/* switch both */
    itmp = u2; u2 = v2; v2 = itmp;
    itmp = u1; u1 = v1; v1 = itmp;
  }

  /* origonally I though the two end points has to be included. But now I think it does not need to since
     the splie might start from the border of the label box
  MEMCPY(x1, &(x[dim*u1]), sizeof(real)*dim);
  MEMCPY(x2, &(x[dim*u2]), sizeof(real)*dim);
  ns1++; ns2++;
  */

  /* splines could be a list of 
     1. 3n points
     2. of the form "e,x,y" followed by 3n points, where x,y is really padded to the end of the 3n points
     3. of the form "s,x,y" followed by 3n points, where x,y is padded to the start of the 3n points
  */
  if (xsplines1){
    if(strstr(xsplines1, "e,")){
      endp1 = 1;
      xsplines1 = strstr(xsplines1, "e,") + 2;
    } else if (strstr(xsplines2, "s,")){
      xsplines1 = strstr(xsplines1, "s,") + 2;
    }
  }
  while (xsplines1 && sscanf(xsplines1,"%lf,%lf", &(x1[ns1*dim]), &x1[ns1*dim + 1]) == 2){
    if (endp1 && iter1 == 0){
      tmp[0] = x1[ns1*dim]; tmp[1] = x1[ns1*dim + 1];
    } else {
      ns1++;
    }
    iter1++;
    xsplines1 = strstr(xsplines1, " ");
    if (!xsplines1) break;
    xsplines1++;
    if (ns1*dim >= len1){
      len1 = ns1*dim + (int)((10)>(0.2*ns1*dim)?(10):(0.2*ns1*dim));
      x1 = grealloc(x1, sizeof(double)*len1);
    }
  }
  if (endp1){/* pad the end point at the last position */
    ns1++;
    if (ns1*dim >= len1){
      len1 = ns1*dim + (int)((10)>(0.2*ns1*dim)?(10):(0.2*ns1*dim));
      x1 = grealloc(x1, sizeof(double)*len1);
    }
    x1[(ns1-1)*dim] = tmp[0];  x1[(ns1-1)*dim + 1] = tmp[1]; 
  }


  /* splines could be a list of 
     1. 3n points
     2. of the form "e,x,y" followed by 3n points, where x,y is really padded to the end of the 3n points
     3. of the form "s,x,y" followed by 3n points, where x,y is padded to the start of the 3n points
  */
  if (xsplines2){
    if(strstr(xsplines2, "e,")){
      endp2 = 1;
      xsplines2 = strstr(xsplines2, "e,") + 2;
    } else if (strstr(xsplines2, "s,")){
      xsplines2 = strstr(xsplines2, "s,") + 2;
    }
  }
  while (xsplines2 && sscanf(xsplines2,"%lf,%lf", &(x2[ns2*dim]), &x2[ns2*dim + 1]) == 2){
    if (endp2 && iter2 == 0){
      tmp[0] = x2[ns2*dim]; tmp[1] = x2[ns2*dim + 1];
    } else {
      ns2++;
    }
    iter2++;
    xsplines2 = strstr(xsplines2, " ");
    if (!xsplines2) break;
    xsplines2++;
    if (ns2*dim >= len2){
      len2 = ns2*dim + (int)((10)>(0.2*ns2*dim)?(10):(0.2*ns2*dim));
      x2 = grealloc(x2, sizeof(double)*len2);
    }
  }
  if (endp2){/* pad the end point at the last position */
    ns2++;
    if (ns2*dim >= len2){
      len2 = ns2*dim + (int)((10)>(0.2*ns2*dim)?(10):(0.2*ns2*dim));
      x2 = grealloc(x2, sizeof(double)*len2);
    }
    x2[(ns2-1)*dim] = tmp[0];  x2[(ns2-1)*dim + 1] = tmp[1]; 
  }

  /* origonally I though the two end points has to be included. But now I think it does not need to since
     the splie might start from the border of the label box
  MEMCPY(&(x2[dim*ns2]), &(x[dim*v2]), sizeof(real)*dim);
  ns2++;
  MEMCPY(&(x1[dim*ns1]), &(x[dim*v1]), sizeof(real)*dim);
  ns1++;
  */

for (i = 0; i < ns1 - 1; i++){
    for (j = 0; j < ns2 - 1; j++){
      cos_a = intersection_angle(&(x1[dim*i]), &(x1[dim*(i + 1)]), &(x2[dim*j]), &(x2[dim*(j+1)]));
      if (!check_edges_with_same_endpoint && cos_a >= -1) cos_a = ((cos_a) >= 0 ? (cos_a) : -(cos_a));
      if (cos_a > cos_critical) {
	return 1;
      }

    }
  }

  free(x1);
  free(x2);
  return 0;
}


Agraph_t* edge_distinct_coloring(char *color_scheme, char *lightness, Agraph_t* g, double angle, double accuracy, int check_edges_with_same_endpoint, int seed){
  /* color the edges of a graph so that conflicting edges are as dinstrinct in color as possibl.
     color_scheme: rgb, lab, gray, or a list of comma separaterd RGB colors in hex, like #ff0000,#00ff00
     lightness: of the form 0,70, specifying the range of lightness of LAB color. Ignored if scheme is not COLOR_LAB.
     .          if NULL, 0,70 is assumed
     g: the graph
     angle: if two edges cross at an angle < "angle", consider they as conflict
     accuracy: how accurate when finding  color of an edge to be as different from others
     check_edges_with_same_endpoint: if TRUE, we will check edges with same end point and only consider them as conflict if
     .                   their angle is very small. Edges that share an end point and is close to 180 degree
     .                   are not consider conflict.
     seed: random_seed. If negative, consider -seed as the number of random start iterations
  */
  double *x = (void *)0;
  int dim = 2;
  SparseMatrix A, B, C;
  int *irn, *jcn, nz, nz2 = 0;
  double cos_critical = cos(angle/180*3.14159), cos_a;
  int u1, v1, u2, v2, i, j;
  double *colors = (void *)0, color_diff, color_diff_sum;
  int flag, ne;
  char **xsplines = (void *)0;
  int cdim;

  A = SparseMatrix_import_dot(g, dim, (void *)0, &x, (void *)0, (void *)0, FORMAT_COORD, (void *)0);
  if (!x){
    fprintf(stderr,"The gv file contains no or improper 2D coordinates\n");
    return (void *)0;
  }


  irn = A->ia; jcn = A->ja;
  nz = A->nz;

  /* get rid of self edges */
  for (i = 0; i < nz; i++){
    if (irn[i] != jcn[i]){
      irn[nz2] = irn[i];
      jcn[nz2++] = jcn[i];
    }
  }

  if (Verbose)
    fprintf(stderr,"cos = %f, nz2 = %d\n", cos_critical, nz2);
  /* now find edge collision */
  nz = 0;
  B = SparseMatrix_new(nz2, nz2, 1, MATRIX_TYPE_REAL, FORMAT_COORD);

  if (Import_dot_splines(g, &ne, &xsplines)){

    

    assert(ne == nz2);
    cos_a = 1.;/* for splines we exit conflict check as soon as we find an conflict, so the anle may not be representitive, hence set to constant */
    for (i = 0; i < nz2; i++){
      u1 = irn[i]; v1 = jcn[i];
      for (j = i+1; j < nz2; j++){
	u2 = irn[j]; v2 = jcn[j];
	if (splines_intersect(dim, u1, v1, u2, v2, cos_critical, check_edges_with_same_endpoint, x, xsplines[i], xsplines[j])){
	  B = SparseMatrix_coordinate_form_add_entries(B, 1, &i, &j, &cos_a);
	}
      }
    }

    

    
  } else {
    /* no splines, justsimple edges */

    

    
    
    for (i = 0; i < nz2; i++){
      u1 = irn[i]; v1 = jcn[i];
      for (j = i+1; j < nz2; j++){
	u2 = irn[j]; v2 = jcn[j];
	cos_a = intersection_angle(&(x[dim*u1]), &(x[dim*v1]), &(x[dim*u2]), &(x[dim*v2]));
	if (!check_edges_with_same_endpoint && cos_a >= -1) cos_a = ((cos_a) >= 0 ? (cos_a) : -(cos_a));
	if (cos_a > cos_critical) {
	  B = SparseMatrix_coordinate_form_add_entries(B, 1, &i, &j, &cos_a);
	}
      }
    }

    

  } 
  C = SparseMatrix_from_coordinate_format(B);
  if (B != C) SparseMatrix_delete(B);
  
  {

    

    int weightedQ = (0);
    int iter_max = 100;
    node_distinct_coloring(color_scheme, lightness, weightedQ, C, accuracy, iter_max, seed, &cdim, &colors, &color_diff, &color_diff_sum, &flag);
    if (flag) goto RETURN;

    

  }

  /* for printing dual*/

  
    
    
    
    
      
      
	
	
	
	
	  
	
      
    
    
      
      
	
		
      
	
		
      
	
		
      
    
    
  


  if (Verbose)
    fprintf(stderr,"The edge conflict graph has %d nodes and %d edges, final color_diff=%f color_diff_sum = %f\n",
	  C->m, C->nz, color_diff, color_diff_sum);

  attach_edge_colors(g, cdim, colors);

 RETURN:
  SparseMatrix_delete(A);
  SparseMatrix_delete(C);
  free(colors);
  free(x);
  if (xsplines){
    for (i = 0; i < ne; i++){
      if (xsplines[i]) free(xsplines[i]);
    }
    free(xsplines);
  }
  return g;

}

