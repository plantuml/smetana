#line 1 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\geom.h" 1
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

/* geometric types and macros (e.g. points and boxes) with application to, but
 * no specific dependance on graphs */





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














































































    









#line 20 "graphviz-2.38.0\\lib\\common\\geom.h" 2





    
typedef struct { int x, y; } point;

typedef struct pointf_s { double x, y; } pointf;

/* tell pathplan/pathgeom.h */


typedef struct { point LL, UR; } box;

typedef struct { pointf LL, UR; } boxf;



/* true if point p is inside box b */


/* true if boxes b0 and b1 overlap */


/* true if box b0 completely contains b1*/


/* expand box b as needed to enclose point p */


/* expand box b0 as needed to enclose box b1 */


/* clip box b0 to fit box b1 */


























/* some common tolerance values */










#line 17 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 2
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














































































    









#line 18 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 1
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

#line 20 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 2
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


#line 21 "graphviz-2.38.0\\lib\\sparse\\QuadTree.c" 2

extern double distance_cropped(double *x, int dim, int i, int j);

struct node_data_struct {
  double node_weight;
  double *coord;
  double id;
  void *data;
};

typedef struct node_data_struct *node_data;


static node_data node_data_new(int dim, double weight, double *coord, int id){
  node_data nd;
  int i;
  nd = gmalloc(sizeof(struct node_data_struct));
  nd->node_weight = weight;
  nd->coord = gmalloc(sizeof(double)*dim);
  nd->id = id;
  for (i = 0; i < dim; i++) nd->coord[i] = coord[i];
  nd->data = (void *)0;
  return nd;
}

void node_data_delete(void *d){
  node_data nd = (node_data) d;
  free(nd->coord);
  /*delete outside   if (nd->data) FREE(nd->data);*/
  free(nd);
}

double node_data_get_weight(void *d){
  node_data nd = (node_data) d;
  return nd->node_weight;
}

double* node_data_get_coord(void *d){
  node_data nd = (node_data) d;
  return nd->coord;
}

int node_data_get_id(void *d){
  node_data nd = (node_data) d;
  return nd->id;
}




void check_or_realloc_arrays(int dim, int *nsuper, int *nsupermax, double **center, double **supernode_wgts, double **distances){
  
  if (*nsuper >= *nsupermax) {
    *nsupermax = *nsuper + ((10)>((int) 0.2*(*nsuper))?(10):((int) 0.2*(*nsuper)));
    *center = grealloc(*center, sizeof(double)*(*nsupermax)*dim);
    *supernode_wgts = grealloc(*supernode_wgts, sizeof(double)*(*nsupermax));
    *distances = grealloc(*distances, sizeof(double)*(*nsupermax));
  }
}

void QuadTree_get_supernodes_internal(QuadTree qt, double bh, double *point, int nodeid, int *nsuper, int *nsupermax, double **center, double **supernode_wgts, double **distances, double *counts, int *flag){
  SingleLinkedList l;
  double *coord, dist;
  int dim, i;

  (*counts)++;

  if (!qt) return;
  dim = qt->dim;
  l = qt->l;
  if (l){
    while (l){
      check_or_realloc_arrays(dim, nsuper, nsupermax, center, supernode_wgts, distances);
      if (node_data_get_id(SingleLinkedList_get_data(l)) != nodeid){
	coord = node_data_get_coord(SingleLinkedList_get_data(l));
	for (i = 0; i < dim; i++){
	  (*center)[dim*(*nsuper)+i] = coord[i];
	}
	(*supernode_wgts)[*nsuper] = node_data_get_weight(SingleLinkedList_get_data(l));
	(*distances)[*nsuper] = point_distance(point, coord, dim);
	(*nsuper)++;
      }
      l = SingleLinkedList_get_next(l);
    }
  }

  if (qt->qts){
    dist = point_distance(qt->center, point, dim); 
    if (qt->width < bh*dist){
      check_or_realloc_arrays(dim, nsuper, nsupermax, center, supernode_wgts, distances);
      for (i = 0; i < dim; i++){
        (*center)[dim*(*nsuper)+i] = qt->average[i];
      }
      (*supernode_wgts)[*nsuper] = qt->total_weight;
      (*distances)[*nsuper] = point_distance(qt->average, point, dim); 
      (*nsuper)++;
    } else {
      for (i = 0; i < 1<<dim; i++){
	QuadTree_get_supernodes_internal(qt->qts[i], bh, point, nodeid, nsuper, nsupermax, center, 
					 supernode_wgts, distances, counts, flag);
      }
    }
  }

}

void QuadTree_get_supernodes(QuadTree qt, double bh, double *point, int nodeid, int *nsuper, 
			     int *nsupermax, double **center, double **supernode_wgts, double **distances, double *counts, int *flag){
  int dim = qt->dim;

  (*counts) = 0;

  *nsuper = 0;

  *flag = 0;
  *nsupermax = 10;
  if (!*center) *center = gmalloc(sizeof(double)*(*nsupermax)*dim);
  if (!*supernode_wgts) *supernode_wgts = gmalloc(sizeof(double)*(*nsupermax));
  if (!*distances) *distances = gmalloc(sizeof(double)*(*nsupermax));
  QuadTree_get_supernodes_internal(qt, bh, point, nodeid, nsuper, nsupermax, center, supernode_wgts, distances, counts, flag);

}


static double *get_or_assign_node_force(double *force, int i, SingleLinkedList l, int dim){

  double *f = (double*) (((node_data) (SingleLinkedList_get_data(l)))->data);

  if (!f){
    (((node_data) (SingleLinkedList_get_data(l)))->data) = &(force[i*dim]);
    f = (double*) (((node_data) (SingleLinkedList_get_data(l)))->data);
  }
  return f;
}
static double *get_or_alloc_force_qt(QuadTree qt, int dim){
  int i;
  double *force = (double*) qt->data;
  if (!force){
    qt->data = gmalloc(sizeof(double)*dim);
    force = (double*) qt->data;
    for (i = 0; i < dim; i++) force[i] = 0.;
  }
  return force;
}

static void QuadTree_repulsive_force_interact(QuadTree qt1, QuadTree qt2, double *x, double *force, double bh, double p, double KP, double *counts){
  /* calculate the all to all reopulsive force and accumulate on each node of the quadtree if an interaction is possible.
     force[i*dim+j], j=1,...,dim is teh force on node i 
   */
  SingleLinkedList l1, l2;
  double *x1, *x2, dist, wgt1, wgt2, f, *f1, *f2, w1, w2;
  int dim, i, j, i1, i2, k;
  QuadTree qt11, qt12; 

  if (!qt1 || !qt2) return;
  assert(qt1->n > 0 && qt2->n > 0);
  dim = qt1->dim;

  l1 = qt1->l;
  l2 = qt2->l;

  /* far enough, calculate repulsive force */
  dist = point_distance(qt1->average, qt2->average, dim); 
  if (qt1->width + qt2->width < bh*dist){
    counts[0]++;
    x1 = qt1->average;
    w1 = qt1->total_weight;
    f1 = get_or_alloc_force_qt(qt1, dim);
    x2 = qt2->average;
    w2 = qt2->total_weight;
    f2 = get_or_alloc_force_qt(qt2, dim);
    assert(dist > 0);
    for (k = 0; k < dim; k++){
      if (p == -1){
	f = w1*w2*KP*(x1[k] - x2[k])/(dist*dist);
      } else {
	f = w1*w2*KP*(x1[k] - x2[k])/pow(dist, 1.- p);
      }
      f1[k] += f;
      f2[k] -= f;
    }
    return;
  }


  /* both at leaves, calculate repulsive force */
  if (l1 && l2){
    while (l1){
      x1 = node_data_get_coord(SingleLinkedList_get_data(l1));
      wgt1 = node_data_get_weight(SingleLinkedList_get_data(l1));
      i1 = node_data_get_id(SingleLinkedList_get_data(l1));
      f1 = get_or_assign_node_force(force, i1, l1, dim);
      l2 = qt2->l;
      while (l2){
	x2 = node_data_get_coord(SingleLinkedList_get_data(l2));
	wgt2 = node_data_get_weight(SingleLinkedList_get_data(l2));
	i2 = node_data_get_id(SingleLinkedList_get_data(l2));
	f2 = get_or_assign_node_force(force, i2, l2, dim);
	if ((qt1 == qt2 && i2 < i1) || i1 == i2) {
	  l2 = SingleLinkedList_get_next(l2);
	  continue;
	}
	counts[1]++;
	dist = distance_cropped(x, dim, i1, i2);
	for (k = 0; k < dim; k++){
	  if (p == -1){
	    f = wgt1*wgt2*KP*(x1[k] - x2[k])/(dist*dist);
	  } else {
	    f = wgt1*wgt2*KP*(x1[k] - x2[k])/pow(dist, 1.- p);
	  }
	  f1[k] += f;
	  f2[k] -= f;
	}
	l2 = SingleLinkedList_get_next(l2);
      }
      l1 = SingleLinkedList_get_next(l1);
    }
    return;
  }


  /* identical, split one */
  if (qt1 == qt2){
      for (i = 0; i < 1<<dim; i++){
	qt11 = qt1->qts[i];
	for (j = i; j < 1<<dim; j++){
	  qt12 = qt1->qts[j];
	  QuadTree_repulsive_force_interact(qt11, qt12, x, force, bh, p, KP, counts);
	}
      }
  } else {
    /* split the one with bigger box, or one not at the last level */
    if (qt1->width > qt2->width && !l1){
      for (i = 0; i < 1<<dim; i++){
	qt11 = qt1->qts[i];
	QuadTree_repulsive_force_interact(qt11, qt2, x, force, bh, p, KP, counts);
      }
    } else if (qt2->width > qt1->width && !l2){
      for (i = 0; i < 1<<dim; i++){
	qt11 = qt2->qts[i];
	QuadTree_repulsive_force_interact(qt11, qt1, x, force, bh, p, KP, counts);
      }
    } else if (!l1){/* pick one that is not at the last level */
      for (i = 0; i < 1<<dim; i++){
	qt11 = qt1->qts[i];
	QuadTree_repulsive_force_interact(qt11, qt2, x, force, bh, p, KP, counts);
      }
    } else if (!l2){
      for (i = 0; i < 1<<dim; i++){
	qt11 = qt2->qts[i];
	QuadTree_repulsive_force_interact(qt11, qt1, x, force, bh, p, KP, counts);
      }
    } else {
      assert(0); /* can be both at the leaf level since that should be catched at the beginning of this func. */
    }
  }
}

static void QuadTree_repulsive_force_accumulate(QuadTree qt, double *force, double *counts){
  /* push down forces on cells into the node level */
  double wgt, wgt2;
  double *f, *f2;
  SingleLinkedList l = qt->l;
  int i, k, dim;
  QuadTree qt2;

  dim = qt->dim;
  wgt = qt->total_weight;
  f = get_or_alloc_force_qt(qt, dim);
  assert(wgt > 0);
  counts[2]++;

  if (l){
    while (l){
      i = node_data_get_id(SingleLinkedList_get_data(l));
      f2 = get_or_assign_node_force(force, i, l, dim);
      wgt2 = node_data_get_weight(SingleLinkedList_get_data(l));
      wgt2 = wgt2/wgt;
      for (k = 0; k < dim; k++) f2[k] += wgt2*f[k];
      l = SingleLinkedList_get_next(l);
    }
    return;
  }

  for (i = 0; i < 1<<dim; i++){
    qt2 = qt->qts[i];
    if (!qt2) continue;
    assert(qt2->n > 0);
    f2 = get_or_alloc_force_qt(qt2, dim);
    wgt2 = qt2->total_weight;
    wgt2 = wgt2/wgt;
    for (k = 0; k < dim; k++) f2[k] += wgt2*f[k];
    QuadTree_repulsive_force_accumulate(qt2, force, counts);
  }

}

void QuadTree_get_repulsive_force(QuadTree qt, double *force, double *x, double bh, double p, double KP, double *counts, int *flag){
  /* get repulsice force by a more efficient algortihm: we consider two cells, if they are well separated, we
     calculate the overall repulsive force on the cell level, if not well separated, we divide one of the cell.
     If both cells are at the leaf level, we calcuaulate repulsicve force among individual nodes. Finally
     we accumulate forces at the cell levels to teh node level
     qt: the quadtree
     x: current coordinates for node i is x[i*dim+j], j = 0, ..., dim-1
     force: the repulsice force, an array of length dim*nnodes, the force for node i is at force[i*dim+j], j = 0, ..., dim - 1
     bh: Barnes-Hut coefficient. If width_cell1+width_cell2 < bh*dist_between_cells, we treat each cell as a supernode.
     p: the repulsive force power
     KP: pow(K, 1 - p)
     counts: array of size 4. 
     .  counts[0]: number of cell-cell interaction
     .  counts[1]: number of cell-node interaction
     .  counts[2]: number of total cells in the quadtree
     . Al normalized by dividing by number of nodes
  */
  int n = qt->n, dim = qt->dim, i;

  for (i = 0; i < 4; i++) counts[i] = 0;

  *flag = 0;

  for (i = 0; i < dim*n; i++) force[i] = 0;

  QuadTree_repulsive_force_interact(qt, qt, x, force, bh, p, KP, counts);
  QuadTree_repulsive_force_accumulate(qt, force, counts);
  for (i = 0; i < 4; i++) counts[i] /= n;

}
QuadTree QuadTree_new_from_point_list(int dim, int n, int max_level, double *coord, double *weight){
  /* form a new QuadTree data structure from a list of coordinates of n points
     coord: of length n*dim, point i sits at [i*dim, i*dim+dim - 1]
     weight: node weight of lentgth n. If NULL, unit weight assumed.
   */
  double *xmin, *xmax, *center, width;
  QuadTree qt = (void *)0;
  int i, k;

  xmin = gmalloc(sizeof(double)*dim);
  xmax = gmalloc(sizeof(double)*dim);
  center = gmalloc(sizeof(double)*dim);
  if (!xmin || !xmax || !center) return (void *)0;

  for (i = 0; i < dim; i++) xmin[i] = coord[i];
  for (i = 0; i < dim; i++) xmax[i] = coord[i];

  for (i = 1; i < n; i++){
    for (k = 0; k < dim; k++){
      xmin[k] = ((xmin[k])<(coord[i*dim+k])?(xmin[k]):(coord[i*dim+k]));
      xmax[k] = ((xmax[k])>(coord[i*dim+k])?(xmax[k]):(coord[i*dim+k]));
    }
  }

  width = xmax[0] - xmin[0];
  for (i = 0; i < dim; i++) {
    center[i] = (xmin[i] + xmax[i])*0.5;
    width = ((width)>(xmax[i] - xmin[i])?(width):(xmax[i] - xmin[i]));
  }
  if (width == 0) width = 0.00001;/* if we only have one point, width = 0! */
  width *= 0.52;
  qt = QuadTree_new(dim, center, width, max_level);

  if (weight){
    for (i = 0; i < n; i++){
      qt = QuadTree_add(qt, &(coord[i*dim]), weight[i], i);
    }
  } else {
    for (i = 0; i < n; i++){
      qt = QuadTree_add(qt, &(coord[i*dim]), 1, i);
    }
  }


  free(xmin);
  free(xmax);
  free(center);
  return qt;
}

QuadTree QuadTree_new(int dim, double *center, double width, int max_level){
  QuadTree q;
  int i;
  q = gmalloc(sizeof(struct QuadTree_struct));
  q->dim = dim;
  q->n = 0;
  q->center = gmalloc(sizeof(double)*dim);
  for (i = 0; i < dim; i++) q->center[i] = center[i];
  assert(width > 0);
  q->width = width;
  q->total_weight = 0;
  q->average = (void *)0;
  q->qts = (void *)0;
  q->l = (void *)0;
  q->max_level = max_level;
  q->data = (void *)0;
  return q;
}

void QuadTree_delete(QuadTree q){
  int i, dim;
  if (!q) return;
  dim = q->dim;
  free(q->center);
  free(q->average);
  if (q->data) free(q->data);
  if (q->qts){
    for (i = 0; i < 1<<dim; i++){
      QuadTree_delete(q->qts[i]);
    }
    free(q->qts);
  }
  SingleLinkedList_delete(q->l, node_data_delete);
  free(q);
}

static int QuadTree_get_quadrant(int dim, double *center, double *coord){
  /* find the quadrant that a point of coordinates coord is going into with reference to the center.
     if coord - center == {+,-,+,+} = {1,0,1,1}, then it will sit in the i-quadrant where
     i's binary representation is 1011 (that is, decimal 11).
   */
  int d = 0, i;

  for (i = dim - 1; i >= 0; i--){
    if (coord[i] - center[i] < 0){
      d = 2*d;
    } else {
      d = 2*d+1;
    }
  }
  return d;
}

QuadTree QuadTree_new_in_quadrant(int dim, double *center, double width, int max_level, int i){
  /* a new quadtree in quadrant i of the original cell. The original cell is centered at 'center".
     The new cell have width "width".
   */
  QuadTree qt;
  int k;

  qt = QuadTree_new(dim, center, width, max_level);
  center = qt->center;/* right now this has the center for the parent */
  for (k = 0; k < dim; k++){/* decompose child id into binary, if {1,0}, say, then
				     add {width/2, -width/2} to the parents' center
				     to get the child's center. */
    if (i%2 == 0){
      center[k]  -= width;
    } else {
      center[k] += width;
    }
    i = (i - i%2)/2;
  }
  return qt;

}
static QuadTree QuadTree_add_internal(QuadTree q, double *coord, double weight, int id, int level){
  int i, dim = q->dim, ii;
  node_data nd = (void *)0;

  int max_level = q->max_level;
  int idd;

  /* Make sure that coord is within bounding box */
  for (i = 0; i < q->dim; i++) {
    if (coord[i] < q->center[i] - q->width - 1.e5*1.0e-16*q->width || coord[i] > q->center[i] + q->width + 1.e5*1.0e-16*q->width) {

      
	      

      //return NULL;
    }
  }

  if (q->n == 0){
    /* if this node is empty right now */
    q->n = 1;
    q->total_weight = weight;
    q->average = gmalloc(sizeof(double)*dim);
    for (i = 0; i < q->dim; i++) q->average[i] = coord[i];
    nd = node_data_new(q->dim, weight, coord, id);
    assert(!(q->l));
    q->l = SingleLinkedList_new(nd);
  } else if (level < max_level){
    /* otherwise open up into 2^dim quadtrees unless the level is too high */
    q->total_weight += weight;
    for (i = 0; i < q->dim; i++) q->average[i] = ((q->average[i])*q->n + coord[i])/(q->n + 1);
    if (!q->qts){
      q->qts = gmalloc(sizeof(QuadTree)*(1<<dim));
      for (i = 0; i < 1<<dim; i++) q->qts[i] = (void *)0;
    }/* done adding new quadtree, now add points to them */
    
    /* insert the old node (if exist) and the current node into the appropriate child quadtree */
    ii = QuadTree_get_quadrant(dim, q->center, coord);
    assert(ii < 1<<dim && ii >= 0);
    if (q->qts[ii] == (void *)0) q->qts[ii] = QuadTree_new_in_quadrant(q->dim, q->center, (q->width)/2, max_level, ii);
    
    q->qts[ii] = QuadTree_add_internal(q->qts[ii], coord, weight, id, level + 1);
    assert(q->qts[ii]);

    if (q->l){
      idd = node_data_get_id(SingleLinkedList_get_data(q->l));
      assert(q->n == 1);
      coord = node_data_get_coord(SingleLinkedList_get_data(q->l));
      weight = node_data_get_weight(SingleLinkedList_get_data(q->l));
      ii = QuadTree_get_quadrant(dim, q->center, coord);
      assert(ii < 1<<dim && ii >= 0);

      if (q->qts[ii] == (void *)0) q->qts[ii] = QuadTree_new_in_quadrant(q->dim, q->center, (q->width)/2, max_level, ii);

      q->qts[ii] = QuadTree_add_internal(q->qts[ii], coord, weight, idd, level + 1);
      assert(q->qts[ii]);
      
      /* delete the old node data on parent */
      SingleLinkedList_delete(q->l, node_data_delete);
      q->l = (void *)0;
    }
    
    (q->n)++;
  } else {
    assert(!(q->qts));
    /* level is too high, append data in the linked list */
    (q->n)++;
    q->total_weight += weight;
    for (i = 0; i < q->dim; i++) q->average[i] = ((q->average[i])*q->n + coord[i])/(q->n + 1);
    nd = node_data_new(q->dim, weight, coord, id);
    assert(q->l);
    q->l = SingleLinkedList_prepend(q->l, nd);
  }
  return q;
}


QuadTree QuadTree_add(QuadTree q, double *coord, double weight, int id){
  if (!q) return q;
  return QuadTree_add_internal(q, coord, weight, id, 0);
  
}

static void draw_polygon(FILE *fp, int dim, double *center, double width){
  /* pliot the enclosing square */
  if (dim < 2 || dim > 3) return;
  fprintf(fp,"(*in c*){Line[{");

  if (dim == 2){
    fprintf(fp, "{%f, %f}", center[0] + width, center[1] + width);
    fprintf(fp, ",{%f, %f}", center[0] - width, center[1] + width);
    fprintf(fp, ",{%f, %f}", center[0] - width, center[1] - width);
    fprintf(fp, ",{%f, %f}", center[0] + width, center[1] - width);
    fprintf(fp, ",{%f, %f}", center[0] + width, center[1] + width);
  } else if (dim == 3){
    /* top */
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] + width, center[1] + width, center[2] + width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] + width, center[2] + width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] - width, center[2] + width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] - width, center[2] + width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] + width, center[2] + width);
    fprintf(fp,"},");
    /* bot */
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] + width, center[1] + width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] + width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] - width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] - width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] + width, center[2] - width);
    fprintf(fp,"},");
    /* for sides */
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] + width, center[1] + width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] + width, center[2] + width);
    fprintf(fp,"},");
    
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] - width, center[1] + width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] + width, center[2] + width);
    fprintf(fp,"},");
    
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] + width, center[1] - width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] + width, center[1] - width, center[2] + width);
    fprintf(fp,"},");
    
    fprintf(fp,"{");
    fprintf(fp, "{%f, %f, %f}", center[0] - width, center[1] - width, center[2] - width);
    fprintf(fp, ",{%f, %f, %f}", center[0] - width, center[1] - width, center[2] + width);
    fprintf(fp,"}");
  }


  fprintf(fp, "}]}(*end C*)");


}
static void QuadTree_print_internal(FILE *fp, QuadTree q, int level){
  /* dump a quad tree in Mathematica format. */
  SingleLinkedList l, l0;
  double *coord;
  int i, dim;

  if (!q) return;

  draw_polygon(fp, q->dim, q->center, q->width);
  dim = q->dim;
  
  l0 = l = q->l;
  if (l){
    printf(",(*a*) {Red,");
    while (l){
      if (l != l0) printf(",");
      coord = node_data_get_coord(SingleLinkedList_get_data(l));
      fprintf(fp, "(*node %d*) Point[{",  node_data_get_id(SingleLinkedList_get_data(l)));
      for (i = 0; i < dim; i++){
	if (i != 0) printf(",");
	fprintf(fp, "%f",coord[i]);
      }
      fprintf(fp, "}]");
      l = SingleLinkedList_get_next(l);
    }
    fprintf(fp, "}");
  }

  if (q->qts){
    for (i = 0; i < 1<<dim; i++){
      fprintf(fp, ",(*b*){");
      QuadTree_print_internal(fp, q->qts[i], level + 1); 
      fprintf(fp, "}");
    }
  }


}

void QuadTree_print(FILE *fp, QuadTree q){
  if (!fp) return;
  if (q->dim == 2){
    fprintf(fp, "Graphics[{");
  } else if (q->dim == 3){
    fprintf(fp, "Graphics3D[{");
  } else {
    return;
  }
  QuadTree_print_internal(fp, q, 0);
  if (q->dim == 2){
    fprintf(fp, "}, PlotRange -> All, Frame -> True, FrameTicks -> True]\n");
  } else {
    fprintf(fp, "}, PlotRange -> All]\n");
  }
}




static void QuadTree_get_nearest_internal(QuadTree qt, double *x, double *y, double *min, int *imin, int tentative, int *flag){
  /* get the narest point years to {x[0], ..., x[dim]} and store in y.*/
  SingleLinkedList l;
  double *coord, dist;
  int dim, i, iq = -1;
  double qmin;
  double *point = x;

  *flag = 0;
  if (!qt) return;
  dim = qt->dim;
  l = qt->l;
  if (l){
    while (l){
      coord = node_data_get_coord(SingleLinkedList_get_data(l));
      dist = point_distance(point, coord, dim);
      if(*min < 0 || dist < *min) {
	*min = dist;
	*imin = node_data_get_id(SingleLinkedList_get_data(l));
	for (i = 0; i < dim; i++) y[i] = coord[i];
      }
      l = SingleLinkedList_get_next(l);
    }
  }
  
  if (qt->qts){
    dist = point_distance(qt->center, point, dim); 
    if (*min >= 0 && (dist - sqrt((double) dim) * qt->width > *min)){
      return;
    } else {
      if (tentative){/* quick first approximation*/
	qmin = -1;
	for (i = 0; i < 1<<dim; i++){
	  if (qt->qts[i]){
	    dist = point_distance(qt->qts[i]->average, point, dim); 
	    if (dist < qmin || qmin < 0){
	      qmin = dist; iq = i;
	    }
	  }
	}
	assert(iq >= 0);
	QuadTree_get_nearest_internal(qt->qts[iq], x, y, min, imin, tentative, flag);
      } else {
	for (i = 0; i < 1<<dim; i++){
	  QuadTree_get_nearest_internal(qt->qts[i], x, y, min, imin, tentative, flag);
	}
      }
    }
  }

}


void QuadTree_get_nearest(QuadTree qt, double *x, double *ymin, int *imin, double *min, int *flag){

  *flag = 0;
  *min = -1;

  QuadTree_get_nearest_internal(qt, x, ymin, min, imin, (!(0)), flag);

  QuadTree_get_nearest_internal(qt, x, ymin, min, imin, (0), flag);


}
