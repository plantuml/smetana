#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 1
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


#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 1


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


























#line 18 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.h" 1
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














  
  
  
  
  
  
  
  
  
  
  





































































































			  


				










































#line 17 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.h" 2

enum {ERROR_NOT_SQUARE_MATRIX = -100};

/* a flag to indicate that p should be set auto */


enum {SMOOTHING_NONE, SMOOTHING_STRESS_MAJORIZATION_GRAPH_DIST, SMOOTHING_STRESS_MAJORIZATION_AVG_DIST, SMOOTHING_STRESS_MAJORIZATION_POWER_DIST, SMOOTHING_SPRING, SMOOTHING_TRIANGLE, SMOOTHING_RNG};

enum {QUAD_TREE_HYBRID_SIZE = 10000};

enum {QUAD_TREE_NONE = 0, QUAD_TREE_NORMAL, QUAD_TREE_FAST, QUAD_TREE_HYBRID};

enum {METHOD_STA = -1, METHOD_SPRING_ELECTRICAL, METHOD_SPRING_MAXENT, METHOD_STRESS_MAXENT, METHOD_STRESS_APPROX, METHOD_STRESS, METHOD_UNIFORM_STRESS, METHOD_FULL_STRESS, METHOD_NONE, METHOD_STO};

struct spring_electrical_control_struct {
  double p;/*a negativve real number default to -1. repulsive force = dist^p */
  double q;/*a positive real number default to 2. attractive force = dist^q */
  int random_start;/* whether to apply SE from a random layout, or from exisiting layout */
  double K;/* the natural distance. If K < 0, K will be set to the average distance of an edge */
  double C;/* another parameter. f_a(i,j) = C*dist(i,j)^2/K * d_ij, f_r(i,j) = K^(3-p)/dist(i,j)^(-p). By default C = 0.2. */
  int multilevels;/* if <=1, single level */
  int multilevel_coarsen_scheme;/* pass on to Multilevel_control->coarsen_scheme */
  int multilevel_coarsen_mode;/* pass on to Multilevel_control->coarsen_mode */
  int quadtree_size;/* cut off size above which quadtree approximation is used */
  int max_qtree_level;/* max level of quadtree */
  double bh;/* Barnes-Hutt constant, if width(snode)/dist[i,snode] < bh, treat snode as a supernode. default 0.2*/
  double tol;/* minimum different between two subsequence config before terminating. ||x-xold|| < tol */
  int maxiter;
  double cool;/* default 0.9 */
  double step;/* initial step size */
  int adaptive_cooling;
  int random_seed;
  int beautify_leaves;
  int use_node_weights;
  int smoothing;
  int overlap;
  int do_shrinking;
  int tscheme; /* octree scheme. 0 (no octree), 1 (normal), 2 (fast) */
  int method;/* spring_electical, spring_maxent */
  double initial_scaling;/* how to scale the layout of the graph before passing to overlap removal algorithm.
			  positive values are absolute in points, negative values are relative
			  to average label size.
			  */
  double rotation;/* degree of rotation */
  int edge_labeling_scheme; /* specifying whether to treat node of the form |edgelabel|* as a special node representing an edge label. 
			       0 (no action, default), 1 (penalty based method to make that kind of node close to the center of its neighbor), 
			       1 (penalty based method to make that kind of node close to the old center of its neighbor),
			       3 (two step process of overlap removal and straightening) */
};

typedef struct  spring_electrical_control_struct  *spring_electrical_control; 

spring_electrical_control spring_electrical_control_new(void);

void spring_electrical_embedding(int dim, SparseMatrix A0, spring_electrical_control ctrl, double *node_weights, double *x, int *flag);
void spring_electrical_embedding_fast(int dim, SparseMatrix A0, spring_electrical_control ctrl, double *node_weights, double *x, int *flag);

void multilevel_spring_electrical_embedding(int dim, SparseMatrix A0, SparseMatrix D, spring_electrical_control ctrl, double *node_weights, double *label_sizes, 
					    double *x, int n_edge_label_nodes, int *edge_label_nodes, int *flag);

void export_embedding(FILE *fp, int dim, SparseMatrix A, double *x, double *width);
void spring_electrical_control_delete(spring_electrical_control ctrl);
void print_matrix(double *x, int n, int dim);

double average_edge_length(SparseMatrix A, int dim, double *coord);

void spring_electrical_spring_embedding(int dim, SparseMatrix A, SparseMatrix D, spring_electrical_control ctrl, double *node_weights, double *x, int *flag);
void force_print(FILE *fp, int n, int dim, double *x, double *force);

enum {MAX_I = 20, OPT_UP = 1, OPT_DOWN = -1, OPT_INIT = 0};
struct oned_optimizer_struct{
  int i;
  double work[MAX_I+1];
  int direction;
};
typedef struct oned_optimizer_struct *oned_optimizer;
void oned_optimizer_delete(oned_optimizer opt);
oned_optimizer oned_optimizer_new(int i);
void oned_optimizer_train(oned_optimizer opt, double work);
int oned_optimizer_get(oned_optimizer opt);
void interpolate_coord(int dim, SparseMatrix A, double *x);
int power_law_graph(SparseMatrix A);
void pcp_rotate(int n, int dim, double *x);

#line 19 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
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


#line 20 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
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

#line 21 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\post_process.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.h" 1
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




















  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  










					    












  
  
  










#line 17 "graphviz-2.38.0\\lib\\sfdpgen\\post_process.h" 2

enum {SM_SCHEME_NORMAL, SM_SCHEME_NORMAL_ELABEL, SM_SCHEME_UNIFORM_STRESS, SM_SCHEME_MAXENT, SM_SCHEME_STRESS_APPROX, SM_SCHEME_STRESS};

struct StressMajorizationSmoother_struct {
  SparseMatrix D;/* distance matrix. The diagonal is removed hence the ia, ja structure is different from Lw and Lwd!! */
  SparseMatrix Lw;/* the weighted laplacian. with offdiag = -1/w_ij */
  SparseMatrix Lwd;/* the laplacian like matrix with offdiag = -scaling*d_ij/w_ij. RHS in stress majorization = Lwd.x */
  double* lambda;
  void (*data_deallocator)(void*);
  void *data;
  int scheme;
  double scaling;/* scaling. It is multiplied to Lwd. need to divide coordinate x at the end of the stress majorization process */
  double tol_cg;/* tolerance and maxit for conjugate gradient that solves the Laplacian system.
		 typically the Laplacian only needs to be solved very crudely as it is part of an
		 outer iteration.*/
  int maxit_cg;
};

typedef struct StressMajorizationSmoother_struct *StressMajorizationSmoother;

void StressMajorizationSmoother_delete(StressMajorizationSmoother sm);

enum {IDEAL_GRAPH_DIST, IDEAL_AVG_DIST, IDEAL_POWER_DIST};
StressMajorizationSmoother StressMajorizationSmoother2_new(SparseMatrix A, int dim, double lambda, double *x, int ideal_dist_scheme);

double StressMajorizationSmoother_smooth(StressMajorizationSmoother sm, int dim, double *x, int maxit, double tol);
/*-------------------- triangle/neirhborhood graph based smoother ------------------- */
typedef  StressMajorizationSmoother TriangleSmoother;



void TriangleSmoother_delete(TriangleSmoother sm);

TriangleSmoother TriangleSmoother_new(SparseMatrix A, int dim, double lambda, double *x, int use_triangularization);

void TriangleSmoother_smooth(TriangleSmoother sm, int dim, double *x);



/*------------------ spring and spring-electrical based smoother */

struct SpringSmoother_struct {
  SparseMatrix D;
  spring_electrical_control ctrl;
};

typedef struct SpringSmoother_struct *SpringSmoother;

SpringSmoother SpringSmoother_new(SparseMatrix A, int dim, spring_electrical_control ctrl, double *x);

void SpringSmoother_delete(SpringSmoother sm);

void SpringSmoother_smooth(SpringSmoother sm, SparseMatrix A, double *node_weights, int dim, double *x);
/*------------------------------------------------------------------*/

void post_process_smoothing(int dim, SparseMatrix A, spring_electrical_control ctrl, double *node_weights, double *x, int *flag);

/*-------------------- sparse stress majorizationp ------------------- */
typedef  StressMajorizationSmoother SparseStressMajorizationSmoother;



void SparseStressMajorizationSmoother_delete(SparseStressMajorizationSmoother sm);

enum {WEIGHTING_SCHEME_NONE, WEIGHTING_SCHEME_INV_DIST, WEIGHTING_SCHEME_SQR_DIST};
SparseStressMajorizationSmoother SparseStressMajorizationSmoother_new(SparseMatrix A, int dim, double lambda, double *x, 
								      int weighting_scheme, int scale_initial_coord);

double SparseStressMajorizationSmoother_smooth(SparseStressMajorizationSmoother sm, int dim, double *x, int maxit_sm, double tol);

double get_stress(int m, int dim, int *iw, int *jw, double *w, double *d, double *x, double scaling, void *data, int weighted);

double get_full_stress(SparseMatrix A, int dim, double *x, int weighting_scheme);
void dump_distance_edge_length(char *outfile, SparseMatrix A, int dim, double *x);

/*--------------------------------------------------------------*/



#line 22 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\overlap.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\post_process.h" 1
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









  
  
  
  
  
  
  
  
  
  


























  
  






















								      












#line 17 "graphviz-2.38.0\\lib\\neatogen\\overlap.h" 2

typedef  StressMajorizationSmoother OverlapSmoother;



void OverlapSmoother_delete(OverlapSmoother sm);

OverlapSmoother OverlapSmoother_new(SparseMatrix A, int m, 
				    int dim, double lambda0, double *x, double *width, int include_original_graph, int neighborhood_only, 
				    double *max_overlap, double *min_overlap,
				    int edge_labeling_scheme, int n_constr_nodes, int *constr_nodes, SparseMatrix A_constr, int shrink
				    );

enum {ELSCHEME_NONE = 0, ELSCHEME_PENALTY, ELSCHEME_PENALTY2, ELSCHEME_STRAIGHTLINE_PENALTY, ELSCHEME_STRAIGHTLINE_PENALTY2};

struct relative_position_constraints_struct{
  double constr_penalty; /* penalty parameter used in making edge labels as much on the line as possible */
  int edge_labeling_scheme;/* specifying whether to treat node of the form |edgelabel|* as a special node representing an edge label. 
			       0 (no action, default), 1 (penalty based method to make that kind of node close to the center of its neighbor), 
			       2 (penalty based method to make that kind of node close to the "old" center of its neighbor), 
			       3 (two step process of overlap removal and straightening) */
  int n_constr_nodes;/*n_constr_nodes: number of nodes that has constraints, these are nodes that is
		       constrained to be close to the average of its neighbors.*/
  int *constr_nodes;/*constr_nodes: a list of nodes that need to be constrained. If NULL, unused.*/
  int *irn;/* working arrays to hold the Laplacian of the constrain graph */
  int *jcn;
  double *val;
  SparseMatrix A_constr; /*A_constr: neighbors of node i are in the row i of this matrix. i needs to sit
			   in between these neighbors as much as possible. this must not be NULL
			   if constr_nodes != NULL.*/
  
};

typedef struct relative_position_constraints_struct*  relative_position_constraints;

double OverlapSmoother_smooth(OverlapSmoother sm, int dim, double *x);

void remove_overlap(int dim, SparseMatrix A, double *x, double *label_sizes, int ntry, double initial_scaling, 
		    int edge_labeling_scheme, int n_constr_nodes, int *constr_nodes, SparseMatrix A_constr, int doShrink, int *flag);
double overlap_scaling(int dim, int m, double *x, double *width, double scale_sta, double scale_sto, double epsilon, int maxiter);

#line 23 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
/* lib/common/types.h.  Generated from types.h.in by configure.  */
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




/* Define if you want CGRAPH */


#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1

typedef unsigned char boolean;










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










#line 27 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcext.h" 1

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

/* Common header used by both clients and plugins */








/*
 * Define an apis array of name strings using an enumerated api_t as index.
 * The enumerated type is defined here.  The apis array is
 * inititialized in gvplugin.c by redefining ELEM and reinvoking APIS.
 */


/*
 * Define api_t using names based on the plugin names with API_ prefixed.
 */

    typedef enum { API_render, API_layout, API_textlayout, API_device, API_loadimage, _DUMMY_ELEM_=0 } api_t; /* API_render, API_layout, ... */
    			/* Stupid but true: The sole purpose of "_DUMMY_ELEM_=0"
			 * is to avoid a "," after the last element of the enum
			 * because some compilers when using "-pedantic"
			 * generate an error for about the dangling ","
			 * but only if this header is used from a .cpp file!
			 * Setting it to 0 makes sure that the enumeration
			 * does not define an extra value.  (It does however
			 * define _DUMMY_ELEM_ as an enumeration symbol,
			 * but its value duplicates that of the first
			 * symbol in the enumeration - in this case "render".)
			 */

    			/* One could wonder why trailing "," in:
			 * 	int nums[]={1,2,3,};
			 * is OK, but in:
			 * 	typedef enum {a,b,c,} abc_t; 
			 * is not!!!
			 */


    typedef struct GVJ_s GVJ_t;
    typedef struct GVG_s GVG_t;
    typedef struct GVC_s GVC_t;

    typedef struct {
	const char *name;
	void* address;
    } lt_symlist_t;

    typedef struct gvplugin_available_s gvplugin_available_t;

/*visual studio*/








/*end visual studio*/




	


	extern lt_symlist_t lt_preloaded_symbols[];












#line 28 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathgeom.h" 1
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










    typedef struct pointf_s Ppoint_t;
    typedef struct pointf_s Pvector_t;

    
	
    

    
    


    typedef struct Ppoly_t {
	Ppoint_t *ps;
	int pn;
    } Ppoly_t;

    typedef Ppoly_t Ppolyline_t;

    typedef struct Pedge_t {
	Ppoint_t a, b;
    } Pedge_t;

/* opaque state handle for visibility graph operations */
    typedef struct vconfig_s vconfig_t;

    void freePath(Ppolyline_t* p);




#line 29 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\textspan.h" 1
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








/* Bold, Italic, Underline, Sup, Sub, Strike */
/* Stored in textfont_t.flags, which is 7 bits, so full */
/* Probably should be moved to textspan_t */








    typedef struct _PostscriptAlias {
        char* name;
        char* family;
        char* weight;
        char* stretch;
        char* style;
        int xfig_code;
	char* svg_font_family;
	char* svg_font_weight;
	char* svg_font_style;
    } PostscriptAlias;

    /* font information
     * If name or color is NULL, or size < 0, that attribute
     * is unspecified. 
     */
    typedef struct {
	char*  name;
	char*  color;
	PostscriptAlias *postscript_alias;
	double size;
	unsigned int flags:7;  /* HTML_UL, HTML_IF, HTML_BF, etc. */
	unsigned int cnt:(sizeof(unsigned int) * 8 - 7);   /* reference count */
    } textfont_t;

    /* atomic unit of text emitted using a single htmlfont_t */
    typedef struct {
	char *str;      /* stored in utf-8 */
	textfont_t *font;
	void *layout;
	void (*free_layout) (void *layout);   /* FIXME - this is ugly */
	double yoffset_layout, yoffset_centerline;
 	pointf size;
	char just;	/* 'l' 'n' 'r' */ /* FIXME */
    } textspan_t;





#line 30 "graphviz-2.38.0\\lib\\common\\types.h" 2
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 31 "graphviz-2.38.0\\lib\\common\\types.h" 2





    typedef int (*qsort_cmpf) (const void *, const void *);
    typedef int (*bsearch_cmpf) (const void *, const void *);
    typedef struct Agraph_s graph_t;
    typedef struct Agnode_s node_t;
    typedef struct Agedge_s edge_t;
    typedef struct Agsym_s attrsym_t;



    typedef struct htmllabel_t htmllabel_t;

    typedef union inside_t {
	struct {
	    pointf* p;
	    double* r;
	} a;
	struct {
	    node_t* n;
	    boxf*    bp;
	} s;
    } inside_t;

    typedef struct port {	/* internal edge endpoint specification */
	pointf p;		/* aiming point relative to node center */
	double theta;		/* slope in radians */
	boxf *bp;		/* if not null, points to bbox of 
				 * rectangular area that is port target
				 */
	boolean	defined;        /* if true, edge has port info at this end */
	boolean	constrained;    /* if true, constraints such as theta are set */
	boolean clip;           /* if true, clip end to node/port shape */
	boolean dyna;           /* if true, assign compass point dynamically */
	unsigned char order;	/* for mincross */
	unsigned char side;	/* if port is on perimeter of node, this
                                 * contains the bitwise OR of the sides (TOP,
                                 * BOTTOM, etc.) it is on. 
                                 */
	char *name;		/* port name, if it was explicitly given, otherwise NULL */
    } port;

    typedef struct {
	boolean(*swapEnds) (edge_t * e);	/* Should head and tail be swapped? */
	boolean(*splineMerge) (node_t * n);	/* Is n a node in the middle of an edge? */
	boolean ignoreSwap;                     /* Test for swapped edges if false */
	boolean isOrtho;                        /* Orthogonal routing used */
    } splineInfo;

    typedef struct pathend_t {
	boxf nb;			/* the node box */
	pointf np;		/* node port */
	int sidemask;
	int boxn;
	boxf boxes[20];
    } pathend_t;

    typedef struct path {	/* internal specification for an edge spline */
	port start, end;
	int nbox;		/* number of subdivisions */
	boxf *boxes;		/* rectangular regions of subdivision */
	void *data;
    } path;

    typedef struct bezier {
	pointf *list;
	int size;
	int sflag, eflag;
	pointf sp, ep;
    } bezier;

    typedef struct splines {
	bezier *list;
	int size;
	boxf bb;
    } splines;

    typedef struct textlabel_t {
	char *text, *fontname, *fontcolor;
	int charset;
	double fontsize;
	pointf dimen; /* the diagonal size of the label (estimated by layout) */
	pointf space; /* the diagonal size of the space for the label */
		      /*   the rendered label is aligned in this box */
		      /*   space does not include pad or margin */
	pointf pos;   /* the center of the space for the label */
	union {
	    struct {
		textspan_t *span;
		short nspans;
	    } txt;
	    htmllabel_t *html;
	} u;
	char valign;  /* 't' 'c' 'b' */
	boolean set;  /* true if position is set */
	boolean html; /* true if html label */
    } textlabel_t;

    typedef struct polygon_t {	/* mutable shape information for a node */
	int regular;		/* true for symmetric shapes */
	int peripheries;	/* number of periphery lines */
	int sides;		/* number of sides */
	double orientation;	/* orientation of shape (+ve degrees) */
	double distortion;	/* distortion factor - as in trapezium */
	double skew;		/* skew factor - as in parallelogram */
	int option;		/* ROUNDED, DIAGONAL corners, etc. */
	pointf *vertices;	/* array of vertex points */
    } polygon_t;

    typedef struct stroke_t {	/* information about a single stroke */
	/* we would have called it a path if that term wasn't already used */
	int nvertices;		/* number of points in the stroke */
	int flags;		/* stroke style flags */
	pointf *vertices;	/* array of vertex points */
    } stroke_t;

/* flag definitions for stroke_t */





    typedef struct shape_t {	/* mutable shape information for a node */
	int nstrokes;		/* number of strokes in array */
	stroke_t *strokes;	/* array of strokes */
	/* The last stroke must always be closed, but can be pen_up.
	 * It is used as the clipping path */
    } shape_t;

    typedef struct shape_functions {	/* read-only shape functions */
	void (*initfn) (node_t *);	/* initializes shape from node u.shape_info structure */
	void (*freefn) (node_t *);	/* frees  shape from node u.shape_info structure */
	 port(*portfn) (node_t *, char *, char *);	/* finds aiming point and slope of port */
	 boolean(*insidefn) (inside_t * inside_context, pointf);	/* clips incident gvc->e spline on shape of gvc->n */
	int (*pboxfn)(node_t* n, port* p, int side, boxf rv[], int *kptr); /* finds box path to reach port */
	void (*codefn) (GVJ_t * job, node_t * n);	/* emits graphics code for node */
    } shape_functions;

    typedef enum { SH_UNSET, SH_POLY, SH_RECORD, SH_POINT, SH_EPSF} shape_kind;

    typedef struct shape_desc {	/* read-only shape descriptor */
	char *name;		/* as read from graph file */
	shape_functions *fns;
	polygon_t *polygon;	/* base polygon info */
	boolean usershape;
    } shape_desc;

#line 1 "graphviz-2.38.0\\lib\\common\\usershape.h" 1
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




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 17 "graphviz-2.38.0\\lib\\common\\usershape.h" 2





    typedef enum { FT_NULL,
	FT_BMP, FT_GIF, FT_PNG, FT_JPEG,
	FT_PDF, FT_PS, FT_EPS, FT_SVG, FT_XML,
	FT_RIFF, FT_WEBP, FT_ICO, FT_TIFF
    } imagetype_t;

    typedef enum {
	IMAGESCALE_FALSE,  /* no image scaling */
	IMAGESCALE_TRUE,   /* scale image to fit but keep aspect ratio */
	IMAGESCALE_WIDTH,  /* scale image width to fit, keep height fixed */
	IMAGESCALE_HEIGHT, /* scale image height to fit, keep width fixed */
	IMAGESCALE_BOTH    /* scale image to fit without regard for aspect ratio */
    } imagescale_t;

    typedef struct usershape_s usershape_t;

    struct usershape_s {
	Dtlink_t link;
	const char *name;
	int macro_id;
	boolean must_inline;
	boolean nocache;
	FILE *f;
	imagetype_t type;
	char *stringtype;
	int x, y, w, h, dpi;
	void *data;                   /* data loaded by a renderer */
	size_t datasize;              /* size of data (if mmap'ed) */
	void (*datafree)(usershape_t *us); /* renderer's function for freeing data */
    };





#line 180 "graphviz-2.38.0\\lib\\common\\types.h" 2

    typedef struct nodequeue {
	node_t **store, **limit, **head, **tail;
    } nodequeue;

    typedef struct adjmatrix_t {
	int nrows, ncols;
	char *data;
    } adjmatrix_t;

    typedef struct rank_t {
	int n;			/* number of nodes in this rank  */
	node_t **v;		/* ordered list of nodes in rank    */
	int an;			/* globally allocated number of nodes   */
	node_t **av;		/* allocated list of nodes in rank  */
	double ht1, ht2;	/* height below/above centerline    */
	double pht1, pht2;	/* as above, but only primitive nodes   */
	boolean candidate;	/* for transpose () */
	boolean valid;
	int cache_nc;		/* caches number of crossings */
	adjmatrix_t *flat;
    } rank_t;

    typedef enum { R_NONE =
	    0, R_VALUE, R_FILL, R_COMPRESS, R_AUTO, R_EXPAND } ratio_t;

    typedef struct layout_t {
	double quantum;
	double scale;
	double ratio;		/* set only if ratio_kind == R_VALUE */
	double dpi;
	pointf margin;
	pointf page;
	pointf size;
	boolean filled;
	boolean landscape;
	boolean centered;
	ratio_t ratio_kind;
	void* xdots;
	char* id;
    } layout_t;

/* for "record" shapes */
    typedef struct field_t {
	pointf size;		/* its dimension */
	boxf b;			/* its placement in node's coordinates */
	int n_flds;
	textlabel_t *lp;	/* n_flds == 0 */
	struct field_t **fld;	/* n_flds > 0 */
	char *id;		/* user's identifier */
	unsigned char LR;	/* if box list is horizontal (left to right) */
	unsigned char sides;    /* sides of node exposed to field */
    } field_t;

    typedef struct nlist_t {
	node_t **list;
	int size;
    } nlist_t;

    typedef struct elist {
	edge_t **list;
	int size;
    } elist;











typedef enum {NATIVEFONTS,PSFONTS,SVGFONTS} fontname_kind;

    typedef struct Agraphinfo_t {
	Agrec_t hdr;
	/* to generate code */
	layout_t *drawing;
	textlabel_t *label;	/* if the cluster has a title */
	boxf bb;			/* bounding box */
	pointf border[4];	/* sizes of margins for graph labels */
	unsigned char gui_state; /* Graph state for GUI ops */
	unsigned char has_labels;
	boolean has_images;
	unsigned char charset; /* input character set */
	int rankdir;
	double ht1, ht2;	/* below and above extremal ranks */
	unsigned short flags;
	void *alg;
	GVC_t *gvc;	/* context for "globals" over multiple graphs */
	void (*cleanup) (graph_t * g);   /* function to deallocate layout-specific data */


	
	
	
	
	
	


	/* to have subgraphs */
	int n_cluster;
	graph_t **clust;	/* clusters are in clust[1..n_cluster] !!! */
	graph_t *dotroot;
	node_t *nlist;
	rank_t *rank;
	graph_t *parent;        /* containing cluster (not parent subgraph) */
	int level;		/* cluster nesting level (not node level!) */
	node_t	*minrep, *maxrep;	/* set leaders for min and max rank */

	/* fast graph node list */
	nlist_t comp;
	/* connected components */
	node_t *minset, *maxset;	/* set leaders */
	long n_nodes;
	/* includes virtual */
	short minrank, maxrank;

	/* various flags */
	boolean has_flat_edges;
	boolean has_sourcerank;
	boolean has_sinkrank;
	unsigned char	showboxes;
	fontname_kind fontnames;		/* to override mangling in SVG */

	int nodesep, ranksep;
	node_t *ln, *rn;	/* left, right nodes of bounding box */

	/* for clusters */
	node_t *leader, **rankleader;
	boolean expanded;
	char installed;
	char set_type;
	char label_pos;
	boolean exact_ranksep;


    } Agraphinfo_t;































































    typedef struct Agnodeinfo_t {
	Agrec_t hdr;
	shape_desc *shape;
	void *shape_info;
	pointf coord;
	double width, height;  /* inches */
	boxf bb;
	double ht, lw, rw;
	textlabel_t *label;
	textlabel_t *xlabel;
	void *alg;
	char state;
	unsigned char gui_state; /* Node state for GUI ops */
	boolean clustnode;


	
	
	


	unsigned char showboxes;
	boolean  has_port;
	node_t* rep;
	node_t *set;

	/* fast graph */
	char node_type, mark, onstack;
	char ranktype, weight_class;
	node_t *next, *prev;
	elist in, out, flat_out, flat_in, other;
	graph_t *clust;

	/* for union-find and collapsing nodes */
	int UF_size;
	node_t *UF_parent;
	node_t *inleaf, *outleaf;

	/* for placing nodes */
	int rank, order;	/* initially, order = 1 for ordered edges */
	double mval;
	elist save_in, save_out;

	/* for network-simplex */
	elist tree_in, tree_out;
	edge_t *par;
	int low, lim;
	int priority;

	double pad[1];


    } Agnodeinfo_t;


























































    typedef struct Agedgeinfo_t {
	Agrec_t hdr;
	splines *spl;
	port tail_port, head_port;
	textlabel_t *label, *head_label, *tail_label, *xlabel;
	char edge_type;
	char adjacent;          /* true for flat edge with adjacent nodes */
	char label_ontop;
	unsigned char gui_state; /* Edge state for GUI ops */
	edge_t *to_orig;	/* for dot's shapes.c    */
	void *alg;


	
	
	


	unsigned char showboxes;
	boolean conc_opp_flag;
	short xpenalty;
	int weight;
	int cutvalue, tree_index;
	short count;
	unsigned short minlen;
	edge_t *to_virt;

    } Agedgeinfo_t;



































    typedef struct {
	int flags;
    } gvlayout_features_t;





#line 24 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
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











































    
    
    
	







#line 25 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
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














































































    









#line 26 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
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


















































#line 27 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 1
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














































    
    
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
	
	
	
	
	
	
    
	
	
	
	
	
	
	
	
	
	
	
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

    











#line 29 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 1
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\spring_electrical.c" 1



spring_electrical_control spring_electrical_control_new(){
  spring_electrical_control ctrl;
  ctrl = gmalloc(sizeof(struct spring_electrical_control_struct));
  ctrl->p = -1.0001234;/*a negativve number default to -1. repulsive force = dist^p */
  ctrl->q = 1;/*a positive number default to 1. Only apply to maxent. 
		attractive force = dist^q. Stress energy = (||x_i-x_j||-d_ij)^{q+1} */
  ctrl->random_start = (!(0));/* whether to apply SE from a random layout, or from exisiting layout */
  ctrl->K = -1;/* the natural distance. If K < 0, K will be set to the average distance of an edge */
  ctrl->C = 0.2;/* another parameter. f_a(i,j) = C*dist(i,j)^2/K * d_ij, f_r(i,j) = K^(3-p)/dist(i,j)^(-p). By default C = 0.2. */
  ctrl->multilevels = (0);/* if <=1, single level */

  //ctrl->multilevel_coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET;
  //ctrl->multilevel_coarsen_mode = COARSEN_MODE_GENTLE;

  ctrl->multilevel_coarsen_scheme = COARSEN_INDEPENDENT_EDGE_SET_HEAVEST_EDGE_PERNODE_SUPERNODES_FIRST;  /* pass on to Multilevel_control->coarsen_scheme */
  ctrl->multilevel_coarsen_mode = COARSEN_MODE_FORCEFUL;/*alternative: COARSEN_MODE_GENTLE. pass on to Multilevel_control->coarsen_mode */


  ctrl->quadtree_size = 45;/* cut off size above which quadtree approximation is used */
  ctrl->max_qtree_level = 10;/* max level of quadtree */
  ctrl->bh = 0.6;/* Barnes-Hutt constant, if width(snode)/dist[i,snode] < bh, treat snode as a supernode.*/
  ctrl->tol = 0.001;/* minimum different between two subsequence config before terminating. ||x-xold||_infinity < tol/K */
  ctrl->maxiter = 500;
  ctrl->cool = 0.90;/* default 0.9 */
  ctrl->step = 0.1;
  ctrl->adaptive_cooling = (!(0));
  ctrl->random_seed = 123;
  ctrl->beautify_leaves = (0);
  ctrl->use_node_weights = (0);
  ctrl->smoothing = SMOOTHING_NONE;
  ctrl->overlap = 0;
  ctrl->do_shrinking = 1;
  ctrl->tscheme = QUAD_TREE_HYBRID;
  ctrl->method = METHOD_SPRING_ELECTRICAL;
  ctrl->initial_scaling = -4;
  ctrl->rotation = 0.;
  ctrl->edge_labeling_scheme = 0;
  return ctrl;
}

void spring_electrical_control_delete(spring_electrical_control ctrl){
  free(ctrl);
}


void oned_optimizer_delete(oned_optimizer opt){
  free(opt);
}

oned_optimizer oned_optimizer_new(int i){
  oned_optimizer opt;
  opt = gmalloc(sizeof(struct oned_optimizer_struct));
  opt->i = i;
  opt->direction = OPT_INIT;
  return opt;
}

void oned_optimizer_train(oned_optimizer opt, double work){
  int i = opt->i;
 
  assert(i >= 0);
  opt->work[i] = work;
  if (opt->direction == OPT_INIT){
    if (opt->i == MAX_I){
      opt->direction = OPT_DOWN;
      opt->i = opt->i - 1;
    } else {
      opt->direction = OPT_UP;
      opt->i = ((MAX_I)<(opt->i + 1)?(MAX_I):(opt->i + 1));
    }
  } else if (opt->direction == OPT_UP){
    /*    fprintf(stderr, "{current_level, prev_level} = {%d,%d}, {work, work_prev} = {%f,%f}",i,i-1,opt->work[i], opt->work[i-1]);*/
    assert(i >= 1);
    if (opt->work[i] < opt->work[i-1] && opt->i < MAX_I){
      /*      fprintf(stderr, "keep going up to level %d\n",opt->i+1);*/
      opt->i = ((MAX_I)<(opt->i + 1)?(MAX_I):(opt->i + 1));
    } else {
      /*      fprintf(stderr, "going down to level %d\n",opt->i-1);*/
      (opt->i)--;
      opt->direction = OPT_DOWN;
    }
  } else {
    assert(i < MAX_I);
    /*    fprintf(stderr, "{current_level, prev_level} = {%d,%d}, {work, work_prev} = {%f,%f}",i,i+1,opt->work[i], opt->work[i+1]);*/
    if (opt->work[i] < opt->work[i+1] && opt->i > 0){
      /*      fprintf(stderr, "keep going down to level %d\n",opt->i-1);*/
      opt->i = ((0)>(opt->i-1)?(0):(opt->i-1));
    } else {
      /*      fprintf(stderr, "keep up to level %d\n",opt->i+1);*/
      (opt->i)++;
      opt->direction = OPT_UP;
    }
  }
}

int oned_optimizer_get(oned_optimizer opt){
  return opt->i;
}


double average_edge_length(SparseMatrix A, int dim, double *coord){
  double dist = 0, d;
  int *ia = A->ia, *ja = A->ja, i, j, k;
  assert(SparseMatrix_is_symmetric(A, (!(0))));

  if (ia[A->m] == 0) return 1;
  for (i = 0; i < A->m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      d = 0;
      for (k = 0; k < dim; k++){
	d += (coord[dim*i+k] - coord[dim*ja[j]])*(coord[dim*i+k] - coord[dim*ja[j]]);
      }
      dist += sqrt(d);
    }
  }
  return dist/ia[A->m];
}



      






  
  

  
    
    
      
      
      
    
    
    
    
      
      
      
	
	  
	
	  
	
      
    
  
  




void export_embedding(FILE *fp, int dim, SparseMatrix A, double *x, double *width){
  int i, j, k, *ia=A->ia, *ja = A->ja;
  int ne = 0;
  double xsize, ysize, xmin, xmax, ymin, ymax;

  xmax = xmin = x[0];
  ymax = ymin = x[1];
  for (i = 0; i < A->m; i++){
    xmax = ((xmax)>(x[i*dim])?(xmax):(x[i*dim]));
    xmin = ((xmin)<(x[i*dim])?(xmin):(x[i*dim]));
    ymax = ((ymax)>(x[i*dim+1])?(ymax):(x[i*dim+1]));
    ymin = ((ymin)<(x[i*dim+1])?(ymin):(x[i*dim+1]));
  }
  xsize = xmax-xmin;
  ysize = ymax-ymin;
  xsize = ((xsize)>(ysize)?(xsize):(ysize));

  if (dim == 2){
    fprintf(fp,"Graphics[{GrayLevel[0.5],Line[{");
  } else {
    fprintf(fp,"Graphics3D[{GrayLevel[0.5],Line[{");
  }
  for (i = 0; i < A->m; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      if (ja[j] == i) continue;
      ne++;
      if (ne > 1) fprintf(fp, ",");
      fprintf(fp, "{{");
      for (k = 0; k < dim; k++) {
	if (k > 0) fprintf(fp,",");
	fprintf(fp, "%f",x[i*dim+k]);
      }
      fprintf(fp, "},{");
      for (k = 0; k < dim; k++) {
	if (k > 0) fprintf(fp,",");
	fprintf(fp, "%f",x[ja[j]*dim+k]);
      }
      fprintf(fp, "}}");
    }
  }

  fprintf(fp,"}],Hue[%f]",/*drand()*/1.);
 
  if (width && dim == 2){
    for (i = 0; i < A->m; i++){
      if (i >= 0) fprintf(fp,",");
      fprintf(fp,"(*width={%f,%f}, x = {%f,%f}*){GrayLevel[.5,.5],Rectangle[{%f,%f},{%f,%f}]}", width[i*dim], width[i*dim+1], x[i*dim], x[i*dim + 1],
          x[i*dim] - width[i*dim], x[i*dim+1] - width[i*dim+1],
          x[i*dim] + width[i*dim], x[i*dim+1] + width[i*dim+1]);
    }
  }

  if (A->m < 100){
    for (i = 0; i < A->m; i++){
      if (i >= 0) fprintf(fp,",");
      fprintf(fp,"Text[%d,{",i+1);
      for (k = 0; k < dim; k++) {
	if (k > 0) fprintf(fp,",");
	fprintf(fp, "%f",x[i*dim+k]);
      }
      fprintf(fp,"}]");
    }
  } else if (A->m < 500000){
    fprintf(fp, ", Point[{");
    for (i = 0; i < A->m; i++){
      if (i > 0) fprintf(fp,",");
      fprintf(fp,"{");
      for (k = 0; k < dim; k++) {
	if (k > 0) fprintf(fp,",");
	fprintf(fp, "%f",x[i*dim+k]);
      }
      fprintf(fp,"}");
    }
    fprintf(fp, "}]");
  } else {
      fprintf(fp,"{}");
  }


 fprintf(fp,"},ImageSize->%f]\n", 2*xsize/2);

}

static double update_step(int adaptive_cooling, double step, double Fnorm, double Fnorm0, double cool){

  if (!adaptive_cooling) {
    return cool*step;
  }
  if (Fnorm >= Fnorm0){
    step = cool*step;
  } else if (Fnorm > 0.95*Fnorm0){
    //    step = step;
  } else {
    step = 0.99*step/cool;
  }
  return step;
}
 



void check_real_array_size(double **a, int len, int *lenmax){
  if (len >= *lenmax){
    *lenmax = len + (((int) 0.2*len)>(10)?((int) 0.2*len):(10));
    *a = grealloc(*a, sizeof(double)*(*lenmax));
  }
  
}
void check_int_array_size(int **a, int len, int *lenmax){
  if (len >= *lenmax){
    *lenmax = len + (((int) 0.2*len)>(10)?((int) 0.2*len):(10));
    *a = grealloc(*a, sizeof(int)*(*lenmax));
  }
  
}

double get_angle(double *x, int dim, int i, int j){
  /* between [0, 2Pi)*/
  int k;
  double y[2], res;
  double eps = 0.00001;
  for (k = 0; k < 2; k++){
    y[k] = x[j*dim+k] - x[i*dim+k];
  }
  if (((y[0]) >= 0 ? (y[0]) : -(y[0])) <= ((y[1]) >= 0 ? (y[1]) : -(y[1]))*eps){
    if (y[1] > 0) return 0.5*3.14159265358979323846;
    return 1.5*3.14159265358979323846;
  }
  res = atan(y[1]/y[0]);
  if (y[0] > 0){
    if (y[1] < 0) res = 2*3.14159265358979323846+res;
  } else if (y[0] < 0){
    res = res + 3.14159265358979323846;
  }
  return res;
}

int comp_real(const void *x, const void *y){
  double *xx = (double*) x;
  double *yy = (double*) y;

  if (*xx > *yy){
    return 1;
  } else if (*xx < *yy){
    return -1;
  }
  return 0;
}
static void sort_real(int n, double *a){
  qsort(a, n, sizeof(double), comp_real);
}


static void set_leaves(double *x, int dim, double dist, double ang, int i, int j){
  x[dim*j] = cos(ang)*dist + x[dim*i];
  x[dim*j+1] = sin(ang)*dist + x[dim*i+1];
}

static void beautify_leaves(int dim, SparseMatrix A, double *x){
  int m = A->m, i, j, *ia = A->ia, *ja = A->ja, k;
  int *checked, p;
  double dist;
  int nleaves, nleaves_max = 10;
  double *angles, maxang, ang1 = 0, ang2 = 0, pad, step;
  int *leaves, nangles_max = 10, nangles;

  assert(!SparseMatrix_has_diagonal(A));

  checked = gmalloc(sizeof(int)*m);
  angles = gmalloc(sizeof(double)*nangles_max);
  leaves = gmalloc(sizeof(int)*nleaves_max);


  for (i = 0; i < m; i++) checked[i] = (0);

  for (i = 0; i < m; i++){
    if (ia[i+1] - ia[i] != 1) continue;
    if (checked[i]) continue;
    p = ja[ia[i]];
    if (!checked[p]){
      checked[p] = (!(0));
      dist = 0; nleaves = 0; nangles = 0;
      for (j = ia[p]; j < ia[p+1]; j++){
	if ((ia[(ja[j])+1] - ia[(ja[j])]) == 1){
	  checked[ja[j]] = (!(0));
	  check_int_array_size(&leaves, nleaves, &nleaves_max);
	  dist += distance(x, dim, p, ja[j]);
	  leaves[nleaves] = ja[j];
	  nleaves++;
	} else {
	  check_real_array_size(&angles, nangles, &nangles_max);
	  angles[nangles++] = get_angle(x, dim, p, ja[j]);
	}
      }
      assert(nleaves > 0);
      dist /= nleaves;
      if (nangles > 0){
	sort_real(nangles, angles);
	maxang = 0;
	for (k = 0; k < nangles - 1; k++){
	  if (angles[k+1] - angles[k] > maxang){
	    maxang = angles[k+1] - angles[k]; 
	    ang1 = angles[k]; ang2 = angles[k+1];
	  }
	}
	if (2*3.14159265358979323846 + angles[0] - angles[nangles - 1] > maxang){
	  maxang = 2*3.14159265358979323846 + angles[0] - angles[nangles - 1];
	  ang1 = angles[nangles - 1];
	  ang2 = 2*3.14159265358979323846 + angles[0];
	}
      } else {
	ang1 = 0; ang2 = 2*3.14159265358979323846; maxang = 2*3.14159265358979323846;
      }
      pad = ((maxang - 3.14159265358979323846*0.166667*(nleaves-1))>(0)?(maxang - 3.14159265358979323846*0.166667*(nleaves-1)):(0))*0.5;
      ang1 += pad*0.95;
      ang2 -= pad*0.95;
ang1 = 0; ang2 = 2*3.14159265358979323846; maxang = 2*3.14159265358979323846;
      assert(ang2 >= ang1);
      step = 0.;
      if (nleaves > 1) step = (ang2 - ang1)/(nleaves - 1);
      for (i = 0; i < nleaves; i++) {
	set_leaves(x, dim, dist, ang1, p, leaves[i]);
	ang1 += step;
      }
    }
  }


  free(checked);
  free(angles);
  free(leaves);
}

void force_print(FILE *fp, int n, int dim, double *x, double *force){
  int i, k;
  
  fprintf(fp,"Graphics[{");
  for (i = 0; i < n; i++){
    if (i > 0) fprintf(fp, ",");
    fprintf(fp, "Arrow[{{");
    for (k = 0; k < dim; k++){
      if (k > 0) fprintf(fp, ",");
      fprintf(fp, "%f",x[i*dim+k]);
    }
    fprintf(fp, "},{");
    for (k = 0; k < dim; k++){
      if (k > 0) fprintf(fp, ",");
      fprintf(fp, "%f",x[i*dim+k]+0.5*force[i*dim+k]);
    }
    fprintf(fp, "}}]");
  }
  fprintf(fp,",");
  for (i = 0; i < n; i++){
    if (i > 0) fprintf(fp, ",");
    fprintf(fp, "Tooltip[Point[{");
    for (k = 0; k < dim; k++){
      if (k > 0) fprintf(fp, ",");
      fprintf(fp, "%f",x[i*dim+k]);
    }
    fprintf(fp, "}],%d]",i);
  }




  fprintf(fp,"}]\n");

}


void spring_electrical_embedding_fast(int dim, SparseMatrix A0, spring_electrical_control ctrl, double *node_weights, double *x, int *flag){
  /* x is a point to a 1D array, x[i*dim+j] gives the coordinate of the i-th node at dimension j.  */
  SparseMatrix A = A0;
  int m, n;
  int i, j, k;
  double p = ctrl->p, K = ctrl->K, C = ctrl->C, CRK, tol = ctrl->tol, maxiter = ctrl->maxiter, cool = ctrl->cool, step = ctrl->step, KP;
  int *ia = (void *)0, *ja = (void *)0;
  double *xold = (void *)0;
  double *f = (void *)0, dist, F, Fnorm = 0, Fnorm0;
  int iter = 0;
  int adaptive_cooling = ctrl->adaptive_cooling;
  QuadTree qt = (void *)0;
  double counts[4], *force = (void *)0;

  
  
  
  

  int max_qtree_level = ctrl->max_qtree_level;
  oned_optimizer qtree_level_optimizer = (void *)0;

  if (!A || maxiter <= 0) return;

  m = A->m, n = A->n;
  if (n <= 0 || dim <= 0) return;

  qtree_level_optimizer = oned_optimizer_new(max_qtree_level);

  *flag = 0;
  if (m != n) {
    *flag = ERROR_NOT_SQUARE_MATRIX;
    goto RETURN;
  }
  assert(A->format == FORMAT_CSR);
  A = SparseMatrix_symmetrize(A, (!(0)));
  ia = A->ia;
  ja = A->ja;

  if (ctrl->random_start){
    srand(ctrl->random_seed);
    for (i = 0; i < dim*n; i++) x[i] = drand();
  }
  if (K < 0){
    ctrl->K = K = average_edge_length(A, dim, x);
  }
  if (C < 0) ctrl->C = C = 0.2;
  if (p >= 0) ctrl->p = p = -1;
  KP = pow(K, 1 - p);
  CRK = pow(C, (2.-p)/3.)/K;

  xold = gmalloc(sizeof(double)*dim*n); 
  force = gmalloc(sizeof(double)*dim*n);

  do {

    



    
      
      
      
      
      
      
      
      
      
    


    iter++;
    xold = memcpy(xold, x, sizeof(double)*dim*n);
    Fnorm0 = Fnorm;
    Fnorm = 0.;

    max_qtree_level = oned_optimizer_get(qtree_level_optimizer);
    

    

    if (ctrl->use_node_weights){
      qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, node_weights);
    } else {
      qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, (void *)0);
    }
  

    


    /* repulsive force */

    


    QuadTree_get_repulsive_force(qt, force, x, ctrl->bh, p, KP, counts, flag);

    assert(!(*flag));


    
    


    /* attractive force   C^((2-p)/3) ||x_i-x_j||/K * (x_j - x_i) */
    for (i = 0; i < n; i++){
      f = &(force[i*dim]);
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	dist = distance(x, dim, i, ja[j]);
	for (k = 0; k < dim; k++){
	  f[k] -= CRK*(x[i*dim+k] - x[ja[j]*dim+k])*dist;
	}
      }
    }
  

    /* move */
    for (i = 0; i < n; i++){
      f = &(force[i*dim]);
      F = 0.;
      for (k = 0; k < dim; k++) F += f[k]*f[k];
      F = sqrt(F);
      Fnorm += F;
      if (F > 0) for (k = 0; k < dim; k++) f[k] /= F;
      for (k = 0; k < dim; k++) x[i*dim+k] += step*f[k];
    }/* done vertex i */



    if (qt) {

      

      QuadTree_delete(qt);

      
      



      
      
      





      
      

      oned_optimizer_train(qtree_level_optimizer, counts[0]+0.85*counts[1]+3.3*counts[2]);
    } else {   
      if (Verbose) {
        fprintf(stderr, "\r                iter = %d, step = %f Fnorm = %f nz = %d  K = %f                                  ",iter, step, Fnorm, A->nz,K);

        

      }
    }

    step = update_step(adaptive_cooling, step, Fnorm, Fnorm0, cool);
  } while (step > tol && iter < maxiter);


  




    
      
    


  if (ctrl->beautify_leaves) beautify_leaves(dim, A, x);


  
  



 RETURN:
  oned_optimizer_delete(qtree_level_optimizer);
  ctrl->max_qtree_level = max_qtree_level;

  if (xold) free(xold);
  if (A != A0) SparseMatrix_delete(A);
  if (force) free(force);

}


void spring_electrical_embedding_slow(int dim, SparseMatrix A0, spring_electrical_control ctrl, double *node_weights, double *x, int *flag){
  /* a version that does vertex moves in one go, instead of one at a time, use for debugging the fast version. Quadtree is not used. */
  /* x is a point to a 1D array, x[i*dim+j] gives the coordinate of the i-th node at dimension j.  */
  SparseMatrix A = A0;
  int m, n;
  int i, j, k;
  double p = ctrl->p, K = ctrl->K, C = ctrl->C, CRK, tol = ctrl->tol, maxiter = ctrl->maxiter, cool = ctrl->cool, step = ctrl->step, KP;
  int *ia = (void *)0, *ja = (void *)0;
  double *xold = (void *)0;
  double *f = (void *)0, dist, F, Fnorm = 0, Fnorm0;
  int iter = 0;
  int adaptive_cooling = ctrl->adaptive_cooling;
  QuadTree qt = (void *)0;
  int USE_QT = (0);
  int nsuper = 0, nsupermax = 10;
  double *center = (void *)0, *supernode_wgts = (void *)0, *distances = (void *)0, nsuper_avg, counts = 0, counts_avg = 0;
  double *force;

  
  
  
  

  int max_qtree_level = ctrl->max_qtree_level;
  oned_optimizer qtree_level_optimizer = (void *)0;

  fprintf(stderr,"spring_electrical_embedding_slow");
  if (!A || maxiter <= 0) return;

  m = A->m, n = A->n;
  if (n <= 0 || dim <= 0) return;
  force = gmalloc(sizeof(double)*n*dim);

  if (n >= ctrl->quadtree_size) {
    USE_QT = (!(0));
    qtree_level_optimizer = oned_optimizer_new(max_qtree_level);
    center = gmalloc(sizeof(double)*nsupermax*dim);
    supernode_wgts = gmalloc(sizeof(double)*nsupermax);
    distances = gmalloc(sizeof(double)*nsupermax);
  }
  USE_QT = (0);
  *flag = 0;
  if (m != n) {
    *flag = ERROR_NOT_SQUARE_MATRIX;
    goto RETURN;
  }
  assert(A->format == FORMAT_CSR);
  A = SparseMatrix_symmetrize(A, (!(0)));
  ia = A->ia;
  ja = A->ja;

  if (ctrl->random_start){
    srand(ctrl->random_seed);
    for (i = 0; i < dim*n; i++) x[i] = drand();
  }
  if (K < 0){
    ctrl->K = K = average_edge_length(A, dim, x);
  }
  if (C < 0) ctrl->C = C = 0.2;
  if (p >= 0) ctrl->p = p = -1;
  KP = pow(K, 1 - p);
  CRK = pow(C, (2.-p)/3.)/K;


  
    
    
    
    
    
    
    
  


  f = gmalloc(sizeof(double)*dim);
  xold = gmalloc(sizeof(double)*dim*n); 
  do {
    for (i = 0; i < dim*n; i++) force[i] = 0;

    iter++;
    xold = memcpy(xold, x, sizeof(double)*dim*n);
    Fnorm0 = Fnorm;
    Fnorm = 0.;
    nsuper_avg = 0;

    if (USE_QT) {
      max_qtree_level = oned_optimizer_get(qtree_level_optimizer);
      if (ctrl->use_node_weights){
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, node_weights);
      } else {
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, (void *)0);
      }
    }

    



    for (i = 0; i < n; i++){
      for (k = 0; k < dim; k++) f[k] = 0.;
     /* repulsive force K^(1 - p)/||x_i-x_j||^(1 - p) (x_i - x_j) */
      if (USE_QT){

	

	QuadTree_get_supernodes(qt, ctrl->bh, &(x[dim*i]), i, &nsuper, &nsupermax, 
				&center, &supernode_wgts, &distances, &counts, flag);

	
	

	counts_avg += counts;
	nsuper_avg += nsuper;
	if (*flag) goto RETURN;
	for (j = 0; j < nsuper; j++){
	  dist = ((distances[j])>(1.e-15)?(distances[j]):(1.e-15));
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/(dist*dist);
	    } else {
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/pow(dist, 1.- p);
	    }
	  }
	}
      } else {
	if (ctrl->use_node_weights && node_weights){
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	} else {
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	}
      }
      for (k = 0; k < dim; k++) force[i*dim+k] += f[k];
    }

 

    for (i = 0; i < n; i++){
      for (k = 0; k < dim; k++) f[k] = 0.;
      /* attractive force   C^((2-p)/3) ||x_i-x_j||/K * (x_j - x_i) */
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	dist = distance(x, dim, i, ja[j]);
	for (k = 0; k < dim; k++){
	  f[k] -= CRK*(x[i*dim+k] - x[ja[j]*dim+k])*dist;
	}
      }
      for (k = 0; k < dim; k++) force[i*dim+k] += f[k];
    }



    for (i = 0; i < n; i++){
     /* normalize force */
      for (k = 0; k < dim; k++) f[k] = force[i*dim+k];
     
      F = 0.;
      for (k = 0; k < dim; k++) F += f[k]*f[k];
      F = sqrt(F);
      Fnorm += F;

      if (F > 0) for (k = 0; k < dim; k++) f[k] /= F;

      for (k = 0; k < dim; k++) x[i*dim+k] += step*f[k];

    }/* done vertex i */

    if (qt) {
      QuadTree_delete(qt);
      nsuper_avg /= n;
      counts_avg /= n;

      
      
      

      if (Verbose && 0) fprintf(stderr, "nsuper_avg=%f, counts_avg = %f 2*nsuper+counts=%f\n",nsuper_avg,counts_avg, 2*nsuper_avg+counts_avg);
      oned_optimizer_train(qtree_level_optimizer, 5*nsuper_avg + counts_avg);
    }    


    
        
        
    



    step = update_step(adaptive_cooling, step, Fnorm, Fnorm0, cool);
  } while (step > tol && iter < maxiter);


  



  
    
    
    
    
    
    
    
  




    
      
	
      
	
      
    


  if (ctrl->beautify_leaves) beautify_leaves(dim, A, x);


  
  


 RETURN:
  if (USE_QT) {
    oned_optimizer_delete(qtree_level_optimizer);
    ctrl->max_qtree_level = max_qtree_level;
  }
  if (xold) free(xold);
  if (A != A0) SparseMatrix_delete(A);
  if (f) free(f);
  if (center) free(center);
  if (supernode_wgts) free(supernode_wgts);
  if (distances) free(distances);
  free(force);

}



void spring_electrical_embedding(int dim, SparseMatrix A0, spring_electrical_control ctrl, double *node_weights, double *x, int *flag){
  /* x is a point to a 1D array, x[i*dim+j] gives the coordinate of the i-th node at dimension j.  */
  SparseMatrix A = A0;
  int m, n;
  int i, j, k;
  double p = ctrl->p, K = ctrl->K, C = ctrl->C, CRK, tol = ctrl->tol, maxiter = ctrl->maxiter, cool = ctrl->cool, step = ctrl->step, KP;
  int *ia = (void *)0, *ja = (void *)0;
  double *xold = (void *)0;
  double *f = (void *)0, dist, F, Fnorm = 0, Fnorm0;
  int iter = 0;
  int adaptive_cooling = ctrl->adaptive_cooling;
  QuadTree qt = (void *)0;
  int USE_QT = (0);
  int nsuper = 0, nsupermax = 10;
  double *center = (void *)0, *supernode_wgts = (void *)0, *distances = (void *)0, nsuper_avg, counts = 0, counts_avg = 0;

  
  
  
  

  int max_qtree_level = ctrl->max_qtree_level;
  oned_optimizer qtree_level_optimizer = (void *)0;

  if (!A || maxiter <= 0) return;

  m = A->m, n = A->n;
  if (n <= 0 || dim <= 0) return;

  if (n >= ctrl->quadtree_size) {
    USE_QT = (!(0));
    qtree_level_optimizer = oned_optimizer_new(max_qtree_level);
    center = gmalloc(sizeof(double)*nsupermax*dim);
    supernode_wgts = gmalloc(sizeof(double)*nsupermax);
    distances = gmalloc(sizeof(double)*nsupermax);
  }
  *flag = 0;
  if (m != n) {
    *flag = ERROR_NOT_SQUARE_MATRIX;
    goto RETURN;
  }
  assert(A->format == FORMAT_CSR);
  A = SparseMatrix_symmetrize(A, (!(0)));
  ia = A->ia;
  ja = A->ja;

  if (ctrl->random_start){
    srand(ctrl->random_seed);
    for (i = 0; i < dim*n; i++) x[i] = drand();
  }
  if (K < 0){
    ctrl->K = K = average_edge_length(A, dim, x);
  }
  if (C < 0) ctrl->C = C = 0.2;
  if (p >= 0) ctrl->p = p = -1;
  KP = pow(K, 1 - p);
  CRK = pow(C, (2.-p)/3.)/K;


  
    
    
    
    
    
    
    
  


  f = gmalloc(sizeof(double)*dim);
  xold = gmalloc(sizeof(double)*dim*n); 
  do {

    //#define VIS_MULTILEVEL

  
    
    
    
    
    
    
    
  


    
      
      
      
      
      
      
      
      
      
    


    iter++;
    xold = memcpy(xold, x, sizeof(double)*dim*n);
    Fnorm0 = Fnorm;
    Fnorm = 0.;
    nsuper_avg = 0;
    counts_avg = 0;

    if (USE_QT) {

      max_qtree_level = oned_optimizer_get(qtree_level_optimizer);
      if (ctrl->use_node_weights){
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, node_weights);
      } else {
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, (void *)0);
      }

	  
    }

    


    for (i = 0; i < n; i++){
      for (k = 0; k < dim; k++) f[k] = 0.;
      /* attractive force   C^((2-p)/3) ||x_i-x_j||/K * (x_j - x_i) */
      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	dist = distance(x, dim, i, ja[j]);
	for (k = 0; k < dim; k++){
	  f[k] -= CRK*(x[i*dim+k] - x[ja[j]*dim+k])*dist;
	}
      }

      /* repulsive force K^(1 - p)/||x_i-x_j||^(1 - p) (x_i - x_j) */
      if (USE_QT){

	

	QuadTree_get_supernodes(qt, ctrl->bh, &(x[dim*i]), i, &nsuper, &nsupermax, 
				&center, &supernode_wgts, &distances, &counts, flag);


	
	

	counts_avg += counts;
	nsuper_avg += nsuper;
	if (*flag) goto RETURN;
	for (j = 0; j < nsuper; j++){
	  dist = ((distances[j])>(1.e-15)?(distances[j]):(1.e-15));
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/(dist*dist);
	    } else {
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/pow(dist, 1.- p);
	    }
	  }
	}
      } else {
	if (ctrl->use_node_weights && node_weights){
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	} else {
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	}
      }
	
      /* normalize force */
      F = 0.;
      for (k = 0; k < dim; k++) F += f[k]*f[k];
      F = sqrt(F);
      Fnorm += F;

      if (F > 0) for (k = 0; k < dim; k++) f[k] /= F;

      for (k = 0; k < dim; k++) x[i*dim+k] += step*f[k];

    }/* done vertex i */

    if (qt) {
      QuadTree_delete(qt);
      nsuper_avg /= n;
      counts_avg /= n;

      
      
      

      if (Verbose & 0) fprintf(stderr, "nsuper_avg=%f, counts_avg = %f 2*nsuper+counts=%f\n",nsuper_avg,counts_avg, 2*nsuper_avg+counts_avg);
      oned_optimizer_train(qtree_level_optimizer, 5*nsuper_avg + counts_avg);
    }    


    
        
        
    



    step = update_step(adaptive_cooling, step, Fnorm, Fnorm0, cool);
  } while (step > tol && iter < maxiter);


  



  
    
    
    
    
    
    
    
  




    
      
	
      
	
      
    


  if (ctrl->beautify_leaves) beautify_leaves(dim, A, x);


  
  


 RETURN:
  if (USE_QT) {
    oned_optimizer_delete(qtree_level_optimizer);
    ctrl->max_qtree_level = max_qtree_level;
  }
  if (xold) free(xold);
  if (A != A0) SparseMatrix_delete(A);
  if (f) free(f);
  if (center) free(center);
  if (supernode_wgts) free(supernode_wgts);
  if (distances) free(distances);

}

static void scale_coord(int n, int dim, double *x, int *id, int *jd, double *d, double dj){
  int i, j, k;
  double w_ij, dist, s = 0, stop = 0, sbot = 0., nz = 0;

  if (dj == 0.) return;
  for (i = 0; i < n; i++){
    for (j = id[i]; j < id[i+1]; j++){
      if (jd[j] == i) continue;
      dist = distance_cropped(x, dim, i, jd[j]);
      if (d){
	dj = d[j];
      } 
      assert(dj > 0);
      w_ij = 1./(dj*dj);
      /* spring force */
      for (k = 0; k < dim; k++){
	stop += w_ij*dj*dist;
	sbot += w_ij*dist*dist;
      }
      s += dist; nz++;
    }
  }
  s = stop/sbot;
  for (i = 0; i < n*dim; i++) x[i] *= s;
  fprintf(stderr,"scaling factor = %f\n",s);
}

static double dmean_get(int n, int *id, int *jd, double* d){
  double dmean = 0;
  int i, j;

  if (!d) return 1.;
  for (i = 0; i < n; i++){
    for (j = id[i]; j < id[i+1]; j++){
      dmean += d[j];
    }
  }
  return dmean/((double) id[n]);
}

void spring_maxent_embedding(int dim, SparseMatrix A0, SparseMatrix D, spring_electrical_control ctrl, double *node_weights, double *x, double rho, int *flag){
  /* x is a point to a 1D array, x[i*dim+j] gives the coordinate of the i-th node at dimension j. 

     Minimize \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij)^2 - \rho \Sum_{(i,j)\NotIn E} Log ||x_i-x_j||

     or

     Minimize \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij)^2 - \rho \Sum_{(i,j)\NotIn E} ||x_i-x_j||^p

     The derivatives are

     d E/d x_i = \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij) (x_i-x_j)/||x_i-x_j|| - \rho \Sum_{(i,j)\NotIn E} (x_i-x_j)/||x_i-x_j||^2

     or

      d E/d x_i = \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij) (x_i-x_j)/||x_i-x_j|| - \rho \Sum_{(i,j)\NotIn E} ||x_i-x_j||^(p-2) (x_i-x_j)
    
      if D == NULL, unit weight assumed

  */
  SparseMatrix A = A0;
  int m, n;
  int i, j, k;
  double p = ctrl->p, C = ctrl->C, tol = ctrl->tol, maxiter = ctrl->maxiter, cool = ctrl->cool, step = ctrl->step, w_ij, dj = 1.;
  int *ia = (void *)0, *ja = (void *)0;
  int *id = (void *)0, *jd = (void *)0;
  double *d, dmean;
  double *xold = (void *)0;
  double *f = (void *)0, dist, F, Fnorm = 0, Fnorm0;
  int iter = 0;
  int adaptive_cooling = ctrl->adaptive_cooling;
  QuadTree qt = (void *)0;
  int USE_QT = (0);
  int nsuper = 0, nsupermax = 10;
  double *center = (void *)0, *supernode_wgts = (void *)0, *distances = (void *)0, nsuper_avg, counts = 0;
  int max_qtree_level = 10;

  


  if (!A || maxiter <= 0) return;
  m = A->m, n = A->n;
  if (n <= 0 || dim <= 0) return;

  if (ctrl->tscheme != QUAD_TREE_NONE && n >= ctrl->quadtree_size) {
    USE_QT = (!(0));
    center = gmalloc(sizeof(double)*nsupermax*dim);
    supernode_wgts = gmalloc(sizeof(double)*nsupermax);
    distances = gmalloc(sizeof(double)*nsupermax);
  }

  *flag = 0;
  if (m != n) {
    *flag = ERROR_NOT_SQUARE_MATRIX;
    goto RETURN;
  }


  assert(A->format == FORMAT_CSR);
  A = SparseMatrix_symmetrize(A, (!(0)));
  ia = A->ia;
  ja = A->ja;
  if (D){
    id = D->ia;
    jd = D->ja;
    d = (double*) D->a;
  } else {
    id = ia; jd = ja; d = (void *)0;
  }
  if (rho < 0) {
    dmean = dmean_get(n, id, jd, d);
    rho = rho*(id[n]/((((double) n)*((double) n)) - id[n]))/pow(dmean, p+1);
    fprintf(stderr,"dmean = %f, rho = %f\n",dmean, rho);
  }

  if (ctrl->random_start){
    fprintf(stderr, "send random coordinates\n");
    srand(ctrl->random_seed);
    for (i = 0; i < dim*n; i++) x[i] = drand();
  /* rescale x to give minimum stress:
     Min \Sum_{(i,j)\in E} w_ij (s ||x_i-x_j||-d_ij)^2
     thus
     s = (\Sum_{(ij)\in E} w_ij d_ij ||x_i-x_j||)/(\Sum_{(i,j)\in E} w_ij ||x_i-x_j||^2)
  */

  } 
  scale_coord(n, dim, x, id, jd, d, dj);



  if (C < 0) ctrl->C = C = 0.2;
  if (p >= 0) ctrl->p = p = -1;


  
    
    
    
    
    
    
    
  


  f = gmalloc(sizeof(double)*dim);
  xold = gmalloc(sizeof(double)*dim*n); 
  do {
    iter++;
    xold = memcpy(xold, x, sizeof(double)*dim*n);
    Fnorm0 = Fnorm;
    Fnorm = 0.;
    nsuper_avg = 0;

    


    if (USE_QT) {
      if (ctrl->use_node_weights){
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, node_weights);
      } else {
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, (void *)0);
      }
    }

    /*
      .    d E/d x_i = \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij) (x_i-x_j)/||x_i-x_j|| - \rho \Sum_{(i,j)\NotIn E} (x_i-x_j)/||x_i-x_j||^2
      or
      .    d E/d x_i = \Sum_{(i,j)\in E} w_ij (||x_i-x_j||-d_ij) (x_i-x_j)/||x_i-x_j|| - \rho \Sum_{(i,j)\NotIn E} ||x_i-x_j||^(p-2) (x_i-x_j)
    */
    for (i = 0; i < n; i++){
      for (k = 0; k < dim; k++) f[k] = 0.;

      /* spring (attractive or repulsive) force   w_ij (||x_i-x_j||-d_ij) (x_i-x_j)/||x_i-x_j|| */
      for (j = id[i]; j < id[i+1]; j++){
	if (jd[j] == i) continue;
	dist = distance_cropped(x, dim, i, jd[j]);
	if (d){
	  dj = d[j];
	} 
	assert(dj > 0);
	/* spring force */
	if (ctrl->q == 2){
	  w_ij = 1./(dj*dj*dj);
	  for (k = 0; k < dim; k++){
	    f[k] += -w_ij*(x[i*dim+k] - x[jd[j]*dim+k])*(dist - dj)*(dist - dj)/dist;
	  }
	} else if (ctrl->q == 1){/* square stress force */
	  w_ij = 1./(dj*dj);
	  for (k = 0; k < dim; k++){
	    f[k] += -w_ij*(x[i*dim+k] - x[jd[j]*dim+k])*(dist - dj)/dist;
	  }
	} else {
	  w_ij = 1./pow(dj, ctrl->q + 1);
	  for (k = 0; k < dim; k++){
	    f[k] += -w_ij*(x[i*dim+k] - x[jd[j]*dim+k])*pow(dist - dj, ctrl->q)/dist;
	  }
	}


	
	
	  
	



	/* discount repulsive force between neighboring vertices which will be applied next, that way there is no
	   repulsive forces between neighboring vertices */
	if (ctrl->use_node_weights && node_weights){
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] -= rho*node_weights[j]*(x[i*dim+k] - x[jd[j]*dim+k])/(dist*dist);
	    } else {
	      f[k] -= rho*node_weights[j]*(x[i*dim+k] - x[jd[j]*dim+k])/pow(dist, 1.- p);
	    }
	  }
	} else {
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] -= rho*(x[i*dim+k] - x[jd[j]*dim+k])/(dist*dist);
	    } else {
	      f[k] -= rho*(x[i*dim+k] - x[jd[j]*dim+k])/pow(dist, 1.- p);
	    }
	  }

	}

      }

      /* repulsive force ||x_i-x_j||^(1 - p) (x_i - x_j) */
      if (USE_QT){
	QuadTree_get_supernodes(qt, ctrl->bh, &(x[dim*i]), i, &nsuper, &nsupermax, 
				&center, &supernode_wgts, &distances, &counts, flag);
	nsuper_avg += nsuper;
	if (*flag) goto RETURN;
	for (j = 0; j < nsuper; j++){
	  dist = ((distances[j])>(1.e-15)?(distances[j]):(1.e-15));
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] += rho*supernode_wgts[j]*(x[i*dim+k] - center[j*dim+k])/(dist*dist);
	    } else {
	      f[k] += rho*supernode_wgts[j]*(x[i*dim+k] - center[j*dim+k])/pow(dist, 1.- p);
	    }
	  }
	}
      } else {
	if (ctrl->use_node_weights && node_weights){
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += rho*node_weights[j]*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += rho*node_weights[j]*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	} else {
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += rho*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += rho*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	}
      }
	
      /* normalize force */
      F = 0.;
      for (k = 0; k < dim; k++) F += f[k]*f[k];
      F = sqrt(F);
      Fnorm += F;

      if (F > 0) for (k = 0; k < dim; k++) f[k] /= F;

      for (k = 0; k < dim; k++) x[i*dim+k] += step*f[k];

    }/* done vertex i */

    if (qt) QuadTree_delete(qt);
    nsuper_avg /= n;

    
    
      
    

    
    step = update_step(adaptive_cooling, step, Fnorm, Fnorm0, cool);
  } while (step > tol && iter < maxiter);


  



  if (ctrl->beautify_leaves) beautify_leaves(dim, A, x);

 RETURN:
  if (xold) free(xold);
  if (A != A0) SparseMatrix_delete(A);
  if (f) free(f);
  if (center) free(center);
  if (supernode_wgts) free(supernode_wgts);
  if (distances) free(distances);

}



void spring_electrical_spring_embedding(int dim, SparseMatrix A0, SparseMatrix D, spring_electrical_control ctrl, double *node_weights, double *x, int *flag){
  /* x is a point to a 1D array, x[i*dim+j] gives the coordinate of the i-th node at dimension j. Same as the spring-electrical except we also 
     introduce force due to spring length
   */
  SparseMatrix A = A0;
  int m, n;
  int i, j, k;
  double p = ctrl->p, K = ctrl->K, C = ctrl->C, CRK, tol = ctrl->tol, maxiter = ctrl->maxiter, cool = ctrl->cool, step = ctrl->step, KP;
  int *ia = (void *)0, *ja = (void *)0;
  int *id = (void *)0, *jd = (void *)0;
  double *d;
  double *xold = (void *)0;
  double *f = (void *)0, dist, F, Fnorm = 0, Fnorm0;
  int iter = 0;
  int adaptive_cooling = ctrl->adaptive_cooling;
  QuadTree qt = (void *)0;
  int USE_QT = (0);
  int nsuper = 0, nsupermax = 10;
  double *center = (void *)0, *supernode_wgts = (void *)0, *distances = (void *)0, nsuper_avg, counts = 0;
  int max_qtree_level = 10;

  if (!A  || maxiter <= 0) return;
  m = A->m, n = A->n;
  if (n <= 0 || dim <= 0) return;

  if (n >= ctrl->quadtree_size) {
    USE_QT = (!(0));
    center = gmalloc(sizeof(double)*nsupermax*dim);
    supernode_wgts = gmalloc(sizeof(double)*nsupermax);
    distances = gmalloc(sizeof(double)*nsupermax);
  }
  *flag = 0;
  if (m != n) {
    *flag = ERROR_NOT_SQUARE_MATRIX;
    goto RETURN;
  }
  assert(A->format == FORMAT_CSR);
  A = SparseMatrix_symmetrize(A, (!(0)));
  ia = A->ia;
  ja = A->ja;
  id = D->ia;
  jd = D->ja;
  d = (double*) D->a;

  if (ctrl->random_start){
    srand(ctrl->random_seed);
    for (i = 0; i < dim*n; i++) x[i] = drand();
  }
  if (K < 0){
    ctrl->K = K = average_edge_length(A, dim, x);
  }
  if (C < 0) ctrl->C = C = 0.2;
  if (p >= 0) ctrl->p = p = -1;
  KP = pow(K, 1 - p);
  CRK = pow(C, (2.-p)/3.)/K;


  
    
    
    
    
    
    
    
  


  f = gmalloc(sizeof(double)*dim);
  xold = gmalloc(sizeof(double)*dim*n); 
  do {
    iter++;
    xold = memcpy(xold, x, sizeof(double)*dim*n);
    Fnorm0 = Fnorm;
    Fnorm = 0.;
    nsuper_avg = 0;

    if (USE_QT) {
      if (ctrl->use_node_weights){
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, node_weights);
      } else {
	qt = QuadTree_new_from_point_list(dim, n, max_qtree_level, x, (void *)0);
      }
    }

    for (i = 0; i < n; i++){
      for (k = 0; k < dim; k++) f[k] = 0.;
      /* attractive force   C^((2-p)/3) ||x_i-x_j||/K * (x_j - x_i) */

      for (j = ia[i]; j < ia[i+1]; j++){
	if (ja[j] == i) continue;
	dist = distance(x, dim, i, ja[j]);
	for (k = 0; k < dim; k++){
	  f[k] -= CRK*(x[i*dim+k] - x[ja[j]*dim+k])*dist;
	}
      }

      for (j = id[i]; j < id[i+1]; j++){
	if (jd[j] == i) continue;
	dist = distance_cropped(x, dim, i, jd[j]);
	for (k = 0; k < dim; k++){
	  if (dist < d[j]){
	    f[k] += 0.2*CRK*(x[i*dim+k] - x[jd[j]*dim+k])*(dist - d[j])*(dist - d[j])/dist;
	  } else {
	    f[k] -= 0.2*CRK*(x[i*dim+k] - x[jd[j]*dim+k])*(dist - d[j])*(dist - d[j])/dist;
	  }
	  /* f[k] -= 0.2*CRK*(x[i*dim+k] - x[jd[j]*dim+k])*(dist - d[j]);*/
	}
      }

      /* repulsive force K^(1 - p)/||x_i-x_j||^(1 - p) (x_i - x_j) */
      if (USE_QT){
	QuadTree_get_supernodes(qt, ctrl->bh, &(x[dim*i]), i, &nsuper, &nsupermax, 
				&center, &supernode_wgts, &distances, &counts, flag);
	nsuper_avg += nsuper;
	if (*flag) goto RETURN;
	for (j = 0; j < nsuper; j++){
	  dist = ((distances[j])>(1.e-15)?(distances[j]):(1.e-15));
	  for (k = 0; k < dim; k++){
	    if (p == -1){
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/(dist*dist);
	    } else {
	      f[k] += supernode_wgts[j]*KP*(x[i*dim+k] - center[j*dim+k])/pow(dist, 1.- p);
	    }
	  }
	}
      } else {
	if (ctrl->use_node_weights && node_weights){
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += node_weights[j]*KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	} else {
	  for (j = 0; j < n; j++){
	    if (j == i) continue;
	    dist = distance_cropped(x, dim, i, j);
	    for (k = 0; k < dim; k++){
	      if (p == -1){
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/(dist*dist);
	      } else {
		f[k] += KP*(x[i*dim+k] - x[j*dim+k])/pow(dist, 1.- p);
	      }
	    }
	  }
	}
      }
	
      /* normalize force */
      F = 0.;
      for (k = 0; k < dim; k++) F += f[k]*f[k];
      F = sqrt(F);
      Fnorm += F;

      if (F > 0) for (k = 0; k < dim; k++) f[k] /= F;

      for (k = 0; k < dim; k++) x[i*dim+k] += step*f[k];

    }/* done vertex i */

    if (qt) QuadTree_delete(qt);
    nsuper_avg /= n;

    
        

        

    

    
    step = update_step(adaptive_cooling, step, Fnorm, Fnorm0, cool);
  } while (step > tol && iter < maxiter);


  



  
    
    
    
    
    
    
    
  


  if (ctrl->beautify_leaves) beautify_leaves(dim, A, x);

 RETURN:
  if (xold) free(xold);
  if (A != A0) SparseMatrix_delete(A);
  if (f) free(f);
  if (center) free(center);
  if (supernode_wgts) free(supernode_wgts);
  if (distances) free(distances);

}




void print_matrix(double *x, int n, int dim){
  int i, k;
  printf("{");
  for (i = 0; i < n; i++){
    if (i != 0) printf(",");
    printf("{");
    for (k = 0; k < dim; k++) {
      if (k != 0) printf(",");
      printf("%f",x[i*dim+k]);
    }
    printf("}");
  }
  printf("}\n");
}

/*
static void interpolate2(int dim, SparseMatrix A, real *x){
  int i, j, k, *ia = A->ia, *ja = A->ja, nz, m = A->m;
  real alpha = 0.5, beta, *y;

  y = MALLOC(sizeof(real)*dim*m);
  for (k = 0; k < dim*m; k++) y[k] = 0;
  for (i = 0; i < m; i++){
    nz = 0;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (ja[j] == i) continue;
      nz++;
      for (k = 0; k < dim; k++){
	y[i*dim+k] += x[ja[j]*dim + k];
      }
    }
    if (nz > 0){
      beta = (1-alpha)/nz;
      for (k = 0; k < dim; k++) y[i*dim+k] = alpha*x[i*dim+k] +  beta*y[i*dim+k];
    }
  }
  for (k = 0; k < dim*m; k++) x[k] = y[k];

  FREE(y);
}

*/

void interpolate_coord(int dim, SparseMatrix A, double *x){
  int i, j, k, *ia = A->ia, *ja = A->ja, nz;
  double alpha = 0.5, beta, *y;

  y = gmalloc(sizeof(double)*dim);
  for (i = 0; i < A->m; i++){
    for (k = 0; k < dim; k++) y[k] = 0;
    nz = 0;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (ja[j] == i) continue;
      nz++;
      for (k = 0; k < dim; k++){
	y[k] += x[ja[j]*dim + k];
      }
    }
    if (nz > 0){
      beta = (1-alpha)/nz;
      for (k = 0; k < dim; k++) x[i*dim+k] = alpha*x[i*dim+k] +  beta*y[k];
    }
  }

  free(y);
}
static void prolongate(int dim, SparseMatrix A, SparseMatrix P, SparseMatrix R, double *x, double *y, int coarsen_scheme_used, double delta){
  int nc, *ia, *ja, i, j, k;
  SparseMatrix_multiply_dense(P, (0), x, (0), &y, (0), dim);

  /* xu yao rao dong */
  if (coarsen_scheme_used > EDGE_BASED_STA && coarsen_scheme_used < EDGE_BASED_STO){
    interpolate_coord(dim, A, y);
    nc = R->m;
    ia = R->ia;
    ja = R->ja;
    for (i = 0; i < nc; i++){
      for (j = ia[i]+1; j < ia[i+1]; j++){
	for (k = 0; k < dim; k++){
	  y[ja[j]*dim + k] += delta*(drand() - 0.5);
	}
      }
    }
  }
}



int power_law_graph(SparseMatrix A){
  int *mask, m, max = 0, i, *ia = A->ia, *ja = A->ja, j, deg;
  int res = (0);
  m = A->m;
  mask = gmalloc(sizeof(int)*(m+1));

  for (i = 0; i < m + 1; i++){
    mask[i] = 0;
  }

  for (i = 0; i < m; i++){
    deg = 0;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (i == ja[j]) continue;
      deg++;
    }
    mask[deg]++;
    max = ((max)>(mask[deg])?(max):(mask[deg]));
  }
  if (mask[1] > 0.8*max && mask[1] > 0.3*m) res = (!(0));
  free(mask);
  return res;
}

void pcp_rotate(int n, int dim, double *x){
  int i, k,l;
  double y[4], axis[2], center[2], dist, x0, x1;

  assert(dim == 2);
  for (i = 0; i < dim*dim; i++) y[i] = 0;
  for (i = 0; i < dim; i++) center[i] = 0;
  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      center[k] += x[i*dim+k];
    }
  }
  for (i = 0; i < dim; i++) center[i] /= n;
  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      x[dim*i+k] =  x[dim*i+k] - center[k];
    }
  }

  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      for (l = 0; l < dim; l++){
	y[dim*k+l] += x[i*dim+k]*x[i*dim+l];
      }
    }
  }
  if (y[1] == 0) {
    axis[0] = 0; axis[1] = 1;
  } else {
    /*         Eigensystem[{{x0, x1}, {x1, x3}}] = 
	       {{(x0 + x3 - Sqrt[x0^2 + 4*x1^2 - 2*x0*x3 + x3^2])/2, 
	       (x0 + x3 + Sqrt[x0^2 + 4*x1^2 - 2*x0*x3 + x3^2])/2}, 
	       {{-(-x0 + x3 + Sqrt[x0^2 + 4*x1^2 - 2*x0*x3 + x3^2])/(2*x1), 1}, 
	       {-(-x0 + x3 - Sqrt[x0^2 + 4*x1^2 - 2*x0*x3 + x3^2])/(2*x1), 1}}}
    */
    axis[0] = -(-y[0] + y[3] - sqrt(y[0]*y[0]+4*y[1]*y[1]-2*y[0]*y[3]+y[3]*y[3]))/(2*y[1]);
    axis[1] = 1;
  }
  dist = sqrt(1+axis[0]*axis[0]);
  axis[0] = axis[0]/dist;
  axis[1] = axis[1]/dist;
  for (i = 0; i < n; i++){
    x0 = x[dim*i]*axis[0]+x[dim*i+1]*axis[1];
    x1 = -x[dim*i]*axis[1]+x[dim*i+1]*axis[0];
    x[dim*i] = x0;
    x[dim*i + 1] = x1;

  }


}
 
static void rotate(int n, int dim, double *x, double angle){
  int i, k;
  double axis[2], center[2], x0, x1;
  double radian = 3.14159/180;

  assert(dim == 2);
  for (i = 0; i < dim; i++) center[i] = 0;
  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      center[k] += x[i*dim+k];
    }
  }
  for (i = 0; i < dim; i++) center[i] /= n;
  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      x[dim*i+k] =  x[dim*i+k] - center[k];
    }
  }
  axis[0] = cos(-angle*radian);
  axis[1] = sin(-angle*radian);
  for (i = 0; i < n; i++){
    x0 = x[dim*i]*axis[0]+x[dim*i+1]*axis[1];
    x1 = -x[dim*i]*axis[1]+x[dim*i+1]*axis[0];
    x[dim*i] = x0;
    x[dim*i + 1] = x1;
  }

  
}

static void attach_edge_label_coordinates(int dim, SparseMatrix A, int n_edge_label_nodes, int *edge_label_nodes, double *x, double *x2){
  int *mask;
  int i, ii, j, k;
  int nnodes = 0;
  double len;

  mask = gmalloc(sizeof(int)*A->m);

  for (i = 0; i < A->m; i++) mask[i] = 1;
  for (i = 0; i < n_edge_label_nodes; i++) {
    if (edge_label_nodes[i] >= 0 && edge_label_nodes[i] < A->m) mask[edge_label_nodes[i]] = -1;
  }

  for (i = 0; i < A->m; i++) {
    if (mask[i] >= 0) mask[i] = nnodes++;
  }


  for (i = 0; i < A->m; i++){
    if (mask[i] >= 0){
      for (k = 0; k < dim; k++) x[i*dim+k] = x2[mask[i]*dim+k];
    }
  }

  for (i = 0; i < n_edge_label_nodes; i++){
    ii = edge_label_nodes[i];
    len = A->ia[ii+1] - A->ia[ii];
    assert(len >= 2); /* should just be 2 */
    assert(mask[ii] < 0);
    for (k = 0; k < dim; k++) {
      x[ii*dim+k] = 0;
    }
    for (j = A->ia[ii]; j < A->ia[ii+1]; j++){
      for (k = 0; k < dim; k++){
	x[ii*dim+k] += x[(A->ja[j])*dim+k];
      }
    }
    for (k = 0; k < dim; k++) {
      x[ii*dim+k] /= len;
    }
  }

  free(mask);
}

static SparseMatrix shorting_edge_label_nodes(SparseMatrix A, int n_edge_label_nodes, int *edge_label_nodes){
  int *mask;
  int i, id = 0, nz, j, jj, ii;
  int *ia = A->ia, *ja = A->ja, *irn = (void *)0, *jcn = (void *)0;
  SparseMatrix B;

  mask = gmalloc(sizeof(int)*A->m);

  for (i = 0; i < A->m; i++) mask[i] = 1;

  for (i = 0; i < n_edge_label_nodes; i++){
    mask[edge_label_nodes[i]] = -1;
  }

  for (i = 0; i < A->m; i++) {
    if (mask[i] > 0) mask[i] = id++;
  }

  nz  = 0;
  for (i = 0; i < A->m; i++){
    if (mask[i] < 0) continue;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (mask[ja[j]] >= 0) {
	nz++;
	continue;
      }
      ii = ja[j];
      for (jj = ia[ii]; jj < ia[ii+1]; jj++){
	if (ja[jj] != i && mask[ja[jj]] >= 0) nz++;
      }
    }
  }

  if (nz > 0) {
    irn = gmalloc(sizeof(int)*nz);
    jcn = gmalloc(sizeof(int)*nz);
  }

  nz = 0;
  for (i = 0; i < A->m; i++){
    if (mask[i] < 0) continue;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (mask[ja[j]] >= 0) {
	irn[nz] = mask[i];
	jcn[nz++] = mask[ja[j]];
	if (mask[i] == 68 || mask[ja[j]] == 68){
	  fprintf(stderr, "xxx %d %d\n",mask[i], mask[ja[j]]);
	  mask[i] = mask[i];
	}
	continue;
      }
      ii = ja[j];
      for (jj = ia[ii]; jj < ia[ii+1]; jj++){
	if (ja[jj] != i && mask[ja[jj]] >= 0) {
	    irn[nz] = mask[i];
	    jcn[nz++] = mask[ja[jj]];
	    if (mask[i] == 68 || mask[ja[jj]] == 68){
	      fprintf(stderr, "%d %d\n",mask[i], mask[ja[jj]]);
	      mask[i] = mask[i];
	    }
	}
      }
    }
  }

  B = SparseMatrix_from_coordinate_arrays(nz, id, id, irn, jcn, (void *)0, MATRIX_TYPE_PATTERN, sizeof(double));

  free(irn);
  free(jcn);
  free(mask);
  return B;

}

static void multilevel_spring_electrical_embedding_core(int dim, SparseMatrix A0, SparseMatrix D0, spring_electrical_control ctrl, double *node_weights, double *label_sizes, 
					    double *x, int n_edge_label_nodes, int *edge_label_nodes, int *flag){
  

  Multilevel_control mctrl = (void *)0;
  int n, plg, coarsen_scheme_used;
  SparseMatrix A = A0, D = D0, P = (void *)0;
  Multilevel grid, grid0;
  double *xc = (void *)0, *xf = (void *)0;
  struct spring_electrical_control_struct ctrl0;

  


  ctrl0 = *ctrl;


  


  *flag = 0;
  if (!A) return;
  n = A->n;
  if (n <= 0 || dim <= 0) return;

  if (!SparseMatrix_is_symmetric(A, (0)) || A->type != MATRIX_TYPE_REAL){
    if (ctrl->method == METHOD_SPRING_MAXENT){
      A = SparseMatrix_symmetrize_nodiag(A, (0));
      assert(D0);
      D = SparseMatrix_symmetrize_nodiag(D, (0));
    } else {
      A = SparseMatrix_get_real_adjacency_matrix_symmetrized(A);
    }
  } else {
    if (ctrl->method == METHOD_SPRING_MAXENT){
      assert(D0);
      D = SparseMatrix_remove_diagonal(D);
    }
    A = SparseMatrix_remove_diagonal(A);
  }

  /* we first generate a layout discarding (shorting) the edge labels nodes, then assign the edge label nodes at the average of their neighbors */
  if ((ctrl->edge_labeling_scheme == ELSCHEME_STRAIGHTLINE_PENALTY || ctrl->edge_labeling_scheme == ELSCHEME_STRAIGHTLINE_PENALTY2)
      && n_edge_label_nodes > 0){
    SparseMatrix A2;

    double *x2 = gmalloc(sizeof(double)*(A->m)*dim);
    A2 = shorting_edge_label_nodes(A, n_edge_label_nodes, edge_label_nodes);
    multilevel_spring_electrical_embedding(dim, A2, (void *)0, ctrl, (void *)0, (void *)0, x2, 0, (void *)0, flag);

    assert(!(*flag));
    attach_edge_label_coordinates(dim, A, n_edge_label_nodes, edge_label_nodes, x, x2);
    remove_overlap(dim, A, x, label_sizes, ctrl->overlap, ctrl->initial_scaling,
		   ctrl->edge_labeling_scheme, n_edge_label_nodes, edge_label_nodes, A, ctrl->do_shrinking, flag);
    SparseMatrix_delete(A2);
    free(x2);
    if (A != A0) SparseMatrix_delete(A);

    return;
  }

  mctrl = Multilevel_control_new(ctrl->multilevel_coarsen_scheme, ctrl->multilevel_coarsen_mode);
  mctrl->maxlevel = ctrl->multilevels;
  grid0 = Multilevel_new(A, D, node_weights, mctrl);

  grid = Multilevel_get_coarsest(grid0);
  if ((!((grid)->prev))){
    xc = x;
  } else {
    xc = gmalloc(sizeof(double)*grid->n*dim);
  }

  plg = power_law_graph(A);
  if (ctrl->p == -1.0001234){
    ctrl->p = -1;
    if (plg) ctrl->p = -1.8;
  }
  
  do {

    
      
      
	
      
	
      
    

    if (ctrl->method == METHOD_SPRING_ELECTRICAL){
      if (ctrl->tscheme == QUAD_TREE_NONE){
	spring_electrical_embedding_slow(dim, grid->A, ctrl, grid->node_weights, xc, flag);
      } else if (ctrl->tscheme == QUAD_TREE_FAST || (ctrl->tscheme == QUAD_TREE_HYBRID && grid->A->m > QUAD_TREE_HYBRID_SIZE)){
	if (ctrl->tscheme == QUAD_TREE_HYBRID && grid->A->m > 10 && Verbose){
	  fprintf(stderr, "QUAD_TREE_HYBRID, size larger than %d, switch to fast quadtree", QUAD_TREE_HYBRID_SIZE);
	}
	spring_electrical_embedding_fast(dim, grid->A, ctrl, grid->node_weights, xc, flag);
      } else if (ctrl->tscheme == QUAD_TREE_NORMAL){
	spring_electrical_embedding(dim, grid->A, ctrl, grid->node_weights, xc, flag);
      } else {
	spring_electrical_embedding(dim, grid->A, ctrl, grid->node_weights, xc, flag);
      }
    } else if (ctrl->method == METHOD_SPRING_MAXENT){
      double rho = 0.05;

      ctrl->step = 1;
      ctrl->adaptive_cooling = (!(0));
      if ((!((grid)->next))){
	ctrl->maxiter=500;
	rho = 0.5;
      } else {
	ctrl->maxiter=100;
      }

      if ((!((grid)->prev))) {/* gradually reduce influence of entropy */
	spring_maxent_embedding(dim, grid->A, grid->D, ctrl, grid->node_weights, xc, rho, flag);
	ctrl->random_start = (0);
	ctrl->step = .05;
	ctrl->adaptive_cooling = (0);
	spring_maxent_embedding(dim, grid->A, grid->D, ctrl, grid->node_weights, xc, rho/2, flag);
	spring_maxent_embedding(dim, grid->A, grid->D, ctrl, grid->node_weights, xc, rho/8, flag);
	spring_maxent_embedding(dim, grid->A, grid->D, ctrl, grid->node_weights, xc, rho/32, flag);
      } else {
	spring_maxent_embedding(dim, grid->A, grid->D, ctrl, grid->node_weights, xc, rho, flag);
      }
    } else {
      assert(0);
    }
    if ((!((grid)->prev))) break;
    if (*flag) {
      free(xc);
      goto RETURN;
    }
    P = grid->P;
    coarsen_scheme_used = grid->coarsen_scheme_used;
    grid = grid->prev;
    if ((!((grid)->prev))){
      xf = x;
    } else {
      xf = gmalloc(sizeof(double)*grid->n*dim);
    }
    prolongate(dim, grid->A, P, grid->R, xc, xf, coarsen_scheme_used, (ctrl->K)*0.001);
    free(xc);
    xc = xf;
    ctrl->random_start = (0);
    ctrl->K = ctrl->K * 0.75;
    ctrl->adaptive_cooling = (0);
    if (grid->next->coarsen_scheme_used > VERTEX_BASED_STA &&
	grid->next->coarsen_scheme_used < VERTEX_BASED_STO){
      ctrl->step = 1;
    } else {
      ctrl->step = .1;
    }
  } while (grid);


  
    
  


  post_process_smoothing(dim, A, ctrl, node_weights, x, flag);

  if (Verbose) fprintf(stderr, "ctrl->overlap=%d\n",ctrl->overlap);

  /* rotation has to be done before overlap removal, since rotation could induce overlaps */
  if (dim == 2){
    pcp_rotate(n, dim, x);
  }
  if (ctrl->rotation != 0) rotate(n, dim, x, ctrl->rotation);


  remove_overlap(dim, A, x, label_sizes, ctrl->overlap, ctrl->initial_scaling,
		 ctrl->edge_labeling_scheme, n_edge_label_nodes, edge_label_nodes, A, ctrl->do_shrinking, flag);

 RETURN:
  *ctrl = ctrl0;
  if (A != A0) SparseMatrix_delete(A);
  if (D && D != D0) SparseMatrix_delete(D);
  Multilevel_control_delete(mctrl);
  Multilevel_delete(grid0);
}



  
  
  
  
  
  
  
  
  
  



  

  
  
  


				 
  

  
  

  

  
  
  
  

  
  
  
  
  
  
  



void multilevel_spring_electrical_embedding(int dim, SparseMatrix A, SparseMatrix D, spring_electrical_control ctrl, double *node_weights, double *label_sizes, 
				 double *x, int n_edge_label_nodes, int *edge_label_nodes, int *flag){
  multilevel_spring_electrical_embedding_core(dim, A, D, ctrl, node_weights, label_sizes, x, n_edge_label_nodes, edge_label_nodes, flag);
}

