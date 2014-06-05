#line 1 "graphviz-2.38.0\\lib\\dotgen\\rank.c" 1
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
 * Rank the nodes of a directed graph, subject to user-defined
 * sets of nodes to be kept on the same, min, or max rank.
 * The temporary acyclic fast graph is constructed and ranked
 * by a network-simplex technique.  Then ranks are propagated
 * to non-leader nodes and temporary edges are deleted.
 * Leaf nodes and top-level clusters are left collapsed, though.
 * Assigns global minrank and maxrank of graph and all clusters.
 *
 * TODO: safety code.  must not be in two clusters at same level.
 *  must not be in same/min/max/rank and a cluster at the same time.
 *  watch out for interactions between leaves and clusters.
 */

#line 1 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 1
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





#line 1 "graphviz-2.38.0\\lib\\common\\render.h" 1


/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/









#line 1 "graphviz-2.38.0\\lib\\common\\render.h" 1


















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




/* for sincos */




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1



#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
































































    









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





#line 21 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\macros.h" 1
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





































#line 22 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\const.h" 1
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










/*	node,edge types */











/* collapsed node classifications */









/* type of cluster rank assignment */




/* default attributes */









































/* default margin for paged formats such as PostScript - in points  = 0.5in */

/* default margin for embedded formats such as PNG - in points */

/* default padding around graph - in points */








/* default polygon sample size for overlap removal and maps */


/* arrow types */


/* sides (e.g. of cluster margins) */





/* sides of boxes for SHAPE_path */








/* Obj types  for renderers */





/* output languages */



















/* for clusters */








/* edge types */







/* for graph server */



/* for neato */




/* drawing phases */



/* existence of labels */







/* type of graph label: GD_label_pos */





/* values specifying rankdir */





/* allowed charsets */




/* style flags (0-23)*/















/* shape (1-127) */


























/* fill types */





/* label types */




/* Flags stored in GD_flags 
 * Bit(s):  0     HAS_CLUST_EDGE
 *          1-3   ET_ 
 *          4     NEW_RANK
 */

/* edge types */








/* New ranking is used */

/******/

/* user-specified node position: ND_pinned */






/* fontsize at which text is omitted entirely */

/* fontsize at which text is rendered by a simple line */



#line 23 "graphviz-2.38.0\\lib\\common\\render.h" 2
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











#line 24 "graphviz-2.38.0\\lib\\common\\render.h" 2
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







#line 25 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\colorprocs.h" 1
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









#line 17 "graphviz-2.38.0\\lib\\common\\colorprocs.h" 2





extern void setColorScheme (char* s);
extern int colorxlate(char *str, gvcolor_t * color, color_type_t target_type);
extern char *canontoken(char *str);
extern int colorCvt(gvcolor_t *ocolor, gvcolor_t *ncolor);





#line 26 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\geomprocs.h" 1
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











    


































































#line 23 "graphviz-2.38.0\\lib\\common\\geomprocs.h" 2









extern box mkbox(point p, point q);
extern boxf mkboxf(pointf p, pointf q);

extern box flip_rec_box(box b, point p);
extern boxf flip_rec_boxf(boxf b, pointf p);

extern double ptToLine2 (pointf l1, pointf l2, pointf p);

extern int lineToBox(pointf p1, pointf p2, boxf b);

extern point ccwrotatep(point p, int ccwrot);
extern pointf ccwrotatepf(pointf p, int ccwrot);

extern point cwrotatep(point p, int cwrot);
extern pointf cwrotatepf(pointf p, int cwrot);

extern void rect2poly(pointf *p);

extern int line_intersect (pointf a, pointf b, pointf c, pointf d, pointf* p);






static inline point pointof(int x, int y)
{
    point r;

    r.x = x;
    r.y = y;
    return r;
}

static inline pointf pointfof(double x, double y)
{
    pointf r;

    r.x = x;
    r.y = y;
    return r;
}

static inline box boxof(int llx, int lly, int urx, int ury)
{
    box b;

    b.LL.x = llx, b.LL.y = lly;
    b.UR.x = urx, b.UR.y = ury;
    return b;
}

static inline boxf boxfof(double llx, double lly, double urx, double ury)
{
    boxf b;

    b.LL.x = llx, b.LL.y = lly;
    b.UR.x = urx, b.UR.y = ury;
    return b;
}

static inline point add_point(point p, point q)
{
    point r;

    r.x = p.x + q.x;
    r.y = p.y + q.y;
    return r;
}

static inline pointf add_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = p.x + q.x;
    r.y = p.y + q.y;
    return r;
}

static inline point sub_point(point p, point q)
{
    point r;

    r.x = p.x - q.x;
    r.y = p.y - q.y;
    return r;
}

static inline pointf sub_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = p.x - q.x;
    r.y = p.y - q.y;
    return r;
}

/* for +ve coord values, this rounds towards p */
static inline point mid_point(point p, point q)
{
    point r;

    r.x = (p.x + q.x) / 2;
    r.y = (p.y + q.y) / 2;
    return r;
}

static inline pointf mid_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = (p.x + q.x) / 2.;
    r.y = (p.y + q.y) / 2.;
    return r;
}

static inline pointf interpolate_pointf(double t, pointf p, pointf q)
{
    pointf r; 

    r.x = p.x + t * (q.x - p.x);
    r.y = p.y + t * (q.y - p.y);
    return r;
}

static inline point exch_xy(point p)
{
    point r;

    r.x = p.y;
    r.y = p.x;
    return r;
}

static inline pointf exch_xyf(pointf p)
{
    pointf r;

    r.x = p.y;
    r.y = p.x;
    return r;
}

static inline box box_bb(box b0, box b1)
{
    box b;

    b.LL.x = ((b0.LL.x)<(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)<(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)>(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)>(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline boxf boxf_bb(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = ((b0.LL.x)<(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)<(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)>(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)>(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline box box_intersect(box b0, box b1)
{
    box b;

    b.LL.x = ((b0.LL.x)>(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)>(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)<(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)<(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline boxf boxf_intersect(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = ((b0.LL.x)>(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)>(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)<(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)<(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline int box_overlap(box b0, box b1)
{
    return (((b0).UR.x >= (b1).LL.x) && ((b1).UR.x >= (b0).LL.x) && ((b0).UR.y >= (b1).LL.y) && ((b1).UR.y >= (b0).LL.y));
}

static inline int boxf_overlap(boxf b0, boxf b1)
{
    return (((b0).UR.x >= (b1).LL.x) && ((b1).UR.x >= (b0).LL.x) && ((b0).UR.y >= (b1).LL.y) && ((b1).UR.y >= (b0).LL.y));
}

static inline int box_contains(box b0, box b1)
{
    return (((b0).UR.x >= (b1).UR.x) && ((b0).UR.y >= (b1).UR.y) && ((b0).LL.x <= (b1).LL.x) && ((b0).LL.y <= (b1).LL.y));
}

static inline int boxf_contains(boxf b0, boxf b1)
{
    return (((b0).UR.x >= (b1).UR.x) && ((b0).UR.y >= (b1).UR.y) && ((b0).LL.x <= (b1).LL.x) && ((b0).LL.y <= (b1).LL.y));
}

static inline pointf perp (pointf p)
{
    pointf r;

    r.x = -p.y;
    r.y = p.x;
    return r;
}

static inline pointf scale (double c, pointf p)
{
    pointf r;

    r.x = c * p.x;
    r.y = c * p.y;
    return r;
}










#line 27 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.h" 1
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








/* Extensible buffer:
 *  Malloc'ed memory is never released until agxbfree is called.
 */
    typedef struct {
	unsigned char *buf;	/* start of buffer */
	unsigned char *ptr;	/* next place to write */
	unsigned char *eptr;	/* end of buffer */
	int dyna;		/* true if buffer is malloc'ed */
    } agxbuf;

/* agxbinit:
 * Initializes new agxbuf; caller provides memory.
 * Assume if init is non-null, hint = sizeof(init[])
 */
    extern void agxbinit(agxbuf * xb, unsigned int hint,
			 unsigned char *init);

/* agxbput_n:
 * Append string s of length n into xb
 */
    extern int agxbput_n(agxbuf * xb, const char *s, unsigned int n);

/* agxbput:
 * Append string s into xb
 */
    extern int agxbput(agxbuf * xb, const char *s);

/* agxbfree:
 * Free any malloced resources.
 */
    extern void agxbfree(agxbuf * xb);

/* agxbpop:
 * Removes last character added, if any.
 */
    extern int agxbpop(agxbuf * xb);

/* agxbmore:
 * Expand buffer to hold at least ssz more bytes.
 */
    extern int agxbmore(agxbuf * xb, int unsigned ssz);

/* agxbputc:
 * Add character to buffer.
 *  int agxbputc(agxbuf*, char)
 */



/* agxbuse:
 * Null-terminates buffer; resets and returns pointer to data;
 *  char* agxbuse(agxbuf* xb)
 */


/* agxbstart:
 * Return pointer to beginning of buffer.
 *  char* agxbstart(agxbuf* xb)
 */


/* agxblen:
 * Return number of characters currently stored.
 *  int agxblen(agxbuf* xb)
 */


/* agxbclear:
 * Resets pointer to data;
 *  void agxbclear(agxbuf* xb)
 */


/* agxbnext:
 * Next position for writing.
 *  char* agxbnext(agxbuf* xb)
 */







#line 28 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\utils.h" 1
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









/*visual studio*/





/*end visual studio*/


    extern int strcasecmp(const char *s1, const char *s2);


    extern int strncasecmp(const char *s1, const char *s2, size_t n);


    extern nodequeue *new_queue(int);
    extern void free_queue(nodequeue *);
    extern void enqueue(nodequeue *, Agnode_t *);
    extern Agnode_t *dequeue(nodequeue *);
    extern pointf Bezier(pointf *, int, double, pointf *, pointf *);
    extern void attach_attrs(graph_t * g);
    extern void attach_attrs_and_arrows(graph_t*, int*, int*);
    extern char *xml_string(char *str);
    extern char *xml_string0(char *str, boolean raw);
    extern void write_plain(GVJ_t * job, graph_t * g, FILE * f, boolean extend);
    extern double yDir (double y);
    extern char *ps_string(char *s, int);
    extern char *strdup_and_subst_obj(char *str, void *obj);
    extern char *xml_url_string(char *s);
    extern void epsf_emit_body(GVJ_t *job, usershape_t *us);
    extern void epsf_define(GVJ_t * job);
    extern void undoClusterEdges(graph_t * g);
    extern Dt_t* mkClustMap (Agraph_t* g);
    extern Agraph_t* findCluster (Dt_t* map, char* name);
    extern attrsym_t* safe_dcl(graph_t * g, int obj_kind, char *name, char *def);

    extern int late_int(void *, Agsym_t *, int, int);
    extern double late_double(void *, Agsym_t *, double, double);
    extern char *late_nnstring(void *, Agsym_t *, char *);
    extern char *late_string(void *, Agsym_t *, char *);
    extern boolean late_bool(void *, Agsym_t *, int);
    extern double get_inputscale (graph_t* g);

    extern Agnode_t *UF_find(Agnode_t *);
    extern Agnode_t *UF_union(Agnode_t *, Agnode_t *);
    extern void UF_remove(Agnode_t *, Agnode_t *);
    extern void UF_singleton(Agnode_t *);
    extern void UF_setname(Agnode_t *, Agnode_t *);

    extern char *Fgets(FILE * fp);
    extern const char *safefile(const char *filename);

    extern boolean mapBool(char *, boolean);
    extern boolean mapbool(char *);
    extern int maptoken(char *, char **, int *);

    extern boolean findStopColor (char* colorlist, char* clrs[2], float* frac);
    extern int test_toggle(void);

    extern void common_init_node(node_t * n);
    extern int common_init_edge(edge_t * e);

    extern void updateBB(graph_t * g, textlabel_t * lp);
    extern void compute_bb(Agraph_t *);
    extern boxf polyBB (polygon_t* poly);
    extern boolean overlap_node(node_t *n, boxf b);
    extern boolean overlap_label(textlabel_t *lp, boxf b);
    extern boolean overlap_edge(edge_t *e, boxf b);

    extern void get_gradient_points(pointf * A, pointf * G, int n, float angle, int flags);

    extern int processClusterEdges(graph_t * g);

    extern char *latin1ToUTF8(char *);
    extern char *htmlEntityUTF8(char *, graph_t* g);
    extern char* utf8ToLatin1 (char* ins);
    extern char* scanEntity (char* t, agxbuf* xb);

    extern pointf dotneato_closest(splines * spl, pointf p);
    extern pointf neato_closest(splines * spl, pointf p);
    extern pointf spline_at_y(splines * spl, double y);

    extern Agsym_t *setAttr(graph_t*, void*, char*name, char *value, Agsym_t*);
    extern void setEdgeType (graph_t* g, int dflt);
    extern int edgeType (char* s, int dflt);
    extern int is_a_cluster (Agraph_t* g);

    /* from postproc.c */ 
    extern void gv_nodesize(Agnode_t * n, boolean flip);

    /* from timing.c */
    extern void start_timer(void);
    extern double elapsed_sec(void);

    /* from psusershape.c */
    extern void cat_libfile(GVJ_t * job, const char **arglib, const char **stdlib);

Agnodeinfo_t* ninf(Agnode_t* n);
Agraphinfo_t* ginf(Agraph_t* g);
Agedgeinfo_t* einf(Agedge_t* e);
    /**/

	









#line 29 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 1
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

/* Header used by plugins */








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



















    
    			











    			







    
    
    

    
	
	
    

    















	


	












#line 21 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 2

/* 
 * Terminology:
 *
 *    package         - e.g. libgvplugin_cairo.so
 *       api	      - e.g. render
 *          type      - e.g. "png", "ps"
 */

    typedef struct {
	int id;         /* an id that is only unique within a package 
			of plugins of the same api.
			A renderer-type such as "png" in the cairo package
			has an id that is different from the "ps" type
			in the same package */
	const char *type;	/* a string name, such as "png" or "ps" that
			distinguishes different types withing the same
			 (renderer in this case) */
	int quality;    /* an arbitrary integer used for ordering plugins of
			the same type from different packages */
	void *engine;   /* pointer to the jump table for the plugin */
	void *features; /* pointer to the feature description 
				void* because type varies by api */
    } gvplugin_installed_t;

    typedef struct {
	api_t api;
	gvplugin_installed_t *types;
    } gvplugin_api_t;

    typedef struct {
	char *packagename;    /* used when this plugin is builtin and has
					no pathname */
	gvplugin_api_t *apis;
    } gvplugin_library_t;





#line 30 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 1
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

/* Common header used by both clients and plugins */








#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcommon.h" 1
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








    typedef struct GVCOMMON_s {
	char **info;
	char *cmdname;
	int verbose;
	boolean config, auto_outfile_names;
        void (*errorfn) (const char *fmt, ...);
	const char **show_boxes; /* emit code for correct box coordinates */
	const char **lib; 

	/* rendering state */
	int viewNum;     /* current view - 1 based count of views,
			    all pages in all layers */
	const lt_symlist_t *builtins;
	int demand_loading;
    } GVCOMMON_t;





#line 21 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 2
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











    
    
    




		



    
	
	
	
	
	
	
	
    
    










#line 22 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 2



    typedef struct gvdevice_engine_s gvdevice_engine_t;
    typedef struct gvformatter_engine_s gvformatter_engine_t;
    typedef struct gvrender_engine_s gvrender_engine_t;
    typedef struct gvlayout_engine_s gvlayout_engine_t;
    typedef struct gvtextlayout_engine_s gvtextlayout_engine_t;
    typedef struct gvloadimage_engine_s gvloadimage_engine_t;

    typedef enum { PEN_NONE, PEN_DASHED, PEN_DOTTED, PEN_SOLID } pen_type;
    typedef enum { FILL_NONE, FILL_SOLID, FILL_LINEAR, FILL_RADIAL } fill_type;
    typedef enum { FONT_REGULAR, FONT_BOLD, FONT_ITALIC } font_type;
    typedef enum { LABEL_PLAIN, LABEL_HTML } label_type;



    typedef enum { GVATTR_STRING, GVATTR_BOOL, GVATTR_COLOR } gvattr_t;

/* The -T output formats listed below are examples only, they are not definitive or inclusive,
 other outputs may use the flags now, or in the future 

                   Default emit order is breadth first graph walk order 
 EMIT_SORTED			emits nodes before edges		
 EMIT_COLORS			emits colors before nodes or edge -Tfig 
 EMIT_CLUSTERS_LAST		emits cluster after nodes and edges 	
 EMIT_PREORDER			emit in preorder traversal ???		
 EMIT_EDGE_SORTED		emits edges before nodes		

 GVDEVICE_DOES_PAGES		provides pagination support -Tps	
 GVDEVICE_DOES_LAYERS		provides support for layers -Tps	
 GVDEVICE_EVENTS		supports mouse events -Tgtk, -Txlib	
 GVDEVICE_DOES_TRUECOLOR	supports alpha channel -Tpng, -Tgtk, -Txlib 
 GVDEVICE_BINARY_FORMAT		Suppresses \r\n substitution for linends 
 GVDEVICE_COMPRESSED_FORMAT	controls libz compression		
 GVDEVICE_NO_WRITER		used when gvdevice is not used because device uses its own writer, -Tming, devil outputs   (FIXME seems to overlap OUTPUT_NOT_REQUIRED)

 GVRENDER_Y_GOES_DOWN		device origin top left, y goes down, otherwise
  				device origin lower left, y goes up	
 GVRENDER_DOES_TRANSFORM	device uses scale, translate, rotate to do its own
 				coordinate transformations, otherwise coordinates 
  				are pre-transformed			
 GVRENDER_DOES_ARROWS		renderer has its own idea of arrow shapes (deprecated) 
 GVRENDER_DOES_LABELS		basically, maps don't need labels	
 GVRENDER_DOES_MAPS		renderer encodes mapping information for mouse events -Tcmapx -Tsvg 
 GVRENDER_DOES_MAP_RECTANGLE	supports a 2 coord rectngle optimization 
 GVRENDER_DOES_MAP_CIRCLE	supports a 1 coord + radius circle optimization	
 GVRENDER_DOES_MAP_POLYGON	supports polygons (basically, -Tsvg uses anchors, so doesn't need to support any map shapes) 
 GVRENDER_DOES_MAP_ELLIPSE	supports a 2 coord ellipse optimization	
 GVRENDER_DOES_MAP_BSPLINE	supports mapping of splines		
 GVRENDER_DOES_TOOLTIPS		can represent tooltip info -Tcmapx, -Tsvg		
 GVRENDER_DOES_TARGETS		can represent target info (open link in a new tab or window) 
 GVRENDER_DOES_Z		render support 2.5D representation -Tvrml 
 GVRENDER_NO_WHITE_BG		don't paint white background, assumes white paper -Tps 
 LAYOUT_NOT_REQUIRED 		don't perform layout -Tcanon 		
 OUTPUT_NOT_REQUIRED		don't use gvdevice for output (basically when agwrite() used instead) -Tcanon, -Txdot 
 */































    typedef struct {
	int flags;
	double default_pad;	/* graph units */
	char **knowncolors;
	int sz_knowncolors;
	color_type_t color_type;
    } gvrender_features_t;

    typedef struct {
	int flags;
	pointf default_margin;  /* left/right, top/bottom - points */
	pointf default_pagesize;/* default page width, height - points */
	pointf default_dpi;
    } gvdevice_features_t;



    typedef struct gvplugin_active_device_s {
        gvdevice_engine_t *engine;
        int id;
        gvdevice_features_t *features;
        const char *type;
    } gvplugin_active_device_t;

    typedef struct gvplugin_active_render_s {
        gvrender_engine_t *engine;
        int id;
        gvrender_features_t *features;
        const char *type;
    } gvplugin_active_render_t;

    typedef struct gvplugin_active_loadimage_t {
	gvloadimage_engine_t *engine;
	int id;
	const char *type;
    } gvplugin_active_loadimage_t;

    typedef struct gv_argvlist_s {
	char **argv;
	int argc;
	int alloc;
    } gv_argvlist_t;
    
    typedef struct gvdevice_callbacks_s {
	void (*refresh) (GVJ_t * job);
        void (*button_press) (GVJ_t * job, int button, pointf pointer);
        void (*button_release) (GVJ_t * job, int button, pointf pointer);
        void (*motion) (GVJ_t * job, pointf pointer);
        void (*modify) (GVJ_t * job, const char *name, const char *value);
        void (*del) (GVJ_t * job);  /* can't use "delete" 'cos C++ stole it */
        void (*read) (GVJ_t * job, const char *filename, const char *layout);
        void (*layout) (GVJ_t * job, const char *layout);
        void (*render) (GVJ_t * job, const char *format, const char *filename);
    } gvdevice_callbacks_t;

    typedef int (*gvevent_key_callback_t) (GVJ_t * job);

    typedef struct gvevent_key_binding_s {
	char *keystring;
	gvevent_key_callback_t callback;
    } gvevent_key_binding_t;

    typedef enum {MAP_RECTANGLE, MAP_CIRCLE, MAP_POLYGON, } map_shape_t;

    typedef enum {ROOTGRAPH_OBJTYPE, CLUSTER_OBJTYPE, NODE_OBJTYPE, EDGE_OBJTYPE} obj_type;

    /* If this enum is changed, the implementation of xbuf and xbufs in
     * gvrender_core_dot.c will probably need to be changed.
     */
    typedef enum {
	EMIT_GDRAW, EMIT_CDRAW, EMIT_TDRAW, EMIT_HDRAW, 
	EMIT_GLABEL, EMIT_CLABEL, EMIT_TLABEL, EMIT_HLABEL, 
	EMIT_NDRAW, EMIT_EDRAW, EMIT_NLABEL, EMIT_ELABEL,
    } emit_state_t;

    typedef struct obj_state_s obj_state_t;

    struct obj_state_s {
	obj_state_t *parent;

	obj_type type;
	union {
	    graph_t *g;
	    graph_t *sg;  
	    node_t *n;
	    edge_t *e;
	} u;

	emit_state_t emit_state; 

	gvcolor_t pencolor, fillcolor, stopcolor;
	int gradient_angle;
	float gradient_frac;
	pen_type pen;
	fill_type fill;
	double penwidth;
	char **rawstyle;

	double z, tail_z, head_z;   /* z depths for 2.5D renderers such as vrml */

	/* fully substituted text strings */
	char *label;
	char *xlabel;
	char *taillabel;
	char *headlabel; 

	char *url;              /* if GVRENDER_DOES_MAPS */
	char *id;
	char *labelurl;
	char *tailurl;
	char *headurl; 

	char *tooltip;          /* if GVRENDER_DOES_TOOLTIPS */
	char *labeltooltip;
	char *tailtooltip;
	char *headtooltip; 

	char *target;           /* if GVRENDER_DOES_TARGETS */
	char *labeltarget;
	char *tailtarget;
	char *headtarget; 

	int explicit_tooltip:1;
	int explicit_tailtooltip:1;
	int explicit_headtooltip:1;
	int explicit_labeltooltip:1;
	int explicit_tailtarget:1;
	int explicit_headtarget:1;
	int explicit_edgetarget:1;
	int explicit_tailurl:1;
	int explicit_headurl:1;

	/* primary mapped region - node shape, edge labels */
	map_shape_t url_map_shape; 
	int url_map_n;                  /* number of points for url map if GVRENDER_DOES_MAPS */
	pointf *url_map_p;

	/* additonal mapped regions for edges */
	int url_bsplinemap_poly_n;      /* number of polygons in url bspline map
					 if GVRENDER_DOES_MAPS && GVRENDER_DOES_MAP_BSPLINES */
	int *url_bsplinemap_n;          /* array of url_bsplinemap_poly_n ints 
					 of number of points in each polygon */
	pointf *url_bsplinemap_p;       /* all the polygon points */

	int tailendurl_map_n;           /* tail end intersection with node */
	pointf *tailendurl_map_p;

	int headendurl_map_n;           /* head end intersection with node */
	pointf *headendurl_map_p;
    };

/* Note on units:
 *     points  - a physical distance (1/72 inch) unaffected by zoom or dpi.
 *     graph units - related to physical distance by zoom.  Equals points at zoom=1
 *     device units - related to physical distance in points by dpi/72
 */

    struct GVJ_s {
	GVC_t *gvc;		/* parent gvc */
	GVJ_t *next;		/* linked list of jobs */
	GVJ_t *next_active;	/* linked list of active jobs (e.g. multiple windows) */

	GVCOMMON_t *common;

	obj_state_t *obj;	/* objects can be nested (at least clusters can)
					so keep object state on a stack */
	char *input_filename;
	int graph_index;

	const char *layout_type;

	const char *output_filename;
	FILE *output_file;
	char *output_data;
	unsigned int output_data_allocated;
	unsigned int output_data_position;

	const char *output_langname;
	int output_lang;

	gvplugin_active_render_t render;
	gvplugin_active_device_t device;
	gvplugin_active_loadimage_t loadimage;
	gvdevice_callbacks_t *callbacks;
	pointf device_dpi;
	boolean device_sets_dpi;

	void *display;
	int screen;

	void *context;		/* gd or cairo surface */
	boolean external_context;	/* context belongs to caller */
	char *imagedata;	/* location of imagedata */

        int flags;		/* emit_graph flags */

	int numLayers;		/* number of layers */
	int layerNum;		/* current layer - 1 based*/

	point 	pagesArraySize; /* 2D size of page array */
	point	pagesArrayFirst;/* 2D starting corner in */
	point	pagesArrayMajor;/* 2D major increment */
	point	pagesArrayMinor;/* 2D minor increment */
	point	pagesArrayElem; /* 2D coord of current page - 0,0 based */
        int	numPages;	/* number of pages */

	boxf    bb;		/* graph bb with padding - graph units */
	pointf  pad;		/* padding around bb - graph units */
	boxf    clip;		/* clip region in graph units */
	boxf	pageBox;	/* current page in graph units */
	pointf	pageSize;	/* page size in graph units */
	pointf  focus;		/* viewport focus - graph units */

	double  zoom;		/* viewport zoom factor (points per graph unit) */
	int	rotation;	/* viewport rotation (degrees)  0=portrait, 90=landscape */

	pointf  view;		/* viewport size - points */
	boxf	canvasBox;	/* viewport area - points */
        pointf  margin;		/* job-specific margin - points */

	pointf	dpi;		/* device resolution device-units-per-inch */

        unsigned int width;     /* device width - device units */
        unsigned int height;    /* device height - device units */
	box     pageBoundingBox;/* rotated boundingBox - device units */
	box     boundingBox;    /* cumulative boundingBox over all pages - device units */

	pointf  scale;		/* composite device to graph units (zoom and dpi) */
	pointf  translation;    /* composite translation */
	pointf  devscale;	/* composite device to points: dpi, y_goes_down */

	boolean	fit_mode,
		needs_refresh,
		click,
		has_grown,
		has_been_rendered;

	unsigned char button;   /* active button */
	pointf pointer;		/* pointer position in device units */
	pointf oldpointer;	/* old pointer position in device units */

	void *current_obj;      /* graph object that pointer is in currently */

	void *selected_obj;      /* graph object that has been selected */
					/* (e.g. button 1 clicked on current obj) */
	char *active_tooltip;		/* tooltip of active object - or NULL */
	char *selected_href;		/* href of selected object - or NULL */
	gv_argvlist_t selected_obj_type_name; /* (e.g. "edge" "node3" "e" "->" "node5" "") */
	gv_argvlist_t selected_obj_attributes; /* attribute triplets: name, value, type */
				/* e.g. "color", "red", GVATTR_COLOR,
					"style", "filled", GVATTR_BOOL, */

	void *window;		/* display-specific data for gvrender plugin */

        /* keybindings for keyboard events */
	gvevent_key_binding_t *keybindings;
	int numkeys;
	void *keycodes;
    };





#line 31 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 1
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

/* Common header used by both clients and plugins */








#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 21 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcommon.h" 1
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








    
	
	
	
	
        
	
	

	
	
	
	
    





#line 22 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2
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











    
    
    




		



    
	
	
	
	
	
	
	
    
    










#line 23 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2

    /* active plugin headers */
    typedef struct gvplugin_active_layout_s {
        gvlayout_engine_t *engine;
        int id;
        gvlayout_features_t *features;
        const char *type;
    } gvplugin_active_layout_t;

    typedef struct gvplugin_active_textlayout_s {
        gvtextlayout_engine_t *engine;
        int id;
        char *type;
    } gvplugin_active_textlayout_t;

    typedef struct gvplugin_package_s gvplugin_package_t;

    struct gvplugin_package_s {
        gvplugin_package_t *next;
        char *path;
        char *name;
    };

    struct gvplugin_available_s {
	gvplugin_available_t *next;     /* next plugin in linked list, or NULL */
	const char *typestr;		/* type string, e.g. "png" or "ps" */
	int quality;			/* Programmer assigned quality ranking within type (+ve or -ve int).
					First implementation of type should be given "0" quality */
	gvplugin_package_t *package;	/* details of library containing plugin */
	gvplugin_installed_t *typeptr;  /* pointer to jumptable for plugin,
					or NULL if not yet loaded */
    };

    struct GVG_s {
	GVC_t *gvc;	/* parent gvc */
	GVG_t *next;	/* next gvg in list */

	char *input_filename; /* or NULL if stdin */
	int graph_index;  /* index of graph within input_file */
	graph_t *g;
    };



    struct GVC_s {
	GVCOMMON_t common;

	char *config_path;
	boolean config_found;

	/* gvParseArgs */
	char **input_filenames; /* null terminated array of input filenames */

	/* gvNextInputGraph() */
	GVG_t *gvgs;	/* linked list of graphs */
	GVG_t *gvg;	/* current graph */

	/* plugins */

	/* APIS expands to "+1 +1 ... +1" to give the number of APIs */
	gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]; /* array of linked-list of plugins per api */
	gvplugin_available_t *api[ +1 +1 +1 +1 +1 ];  /* array of current plugins per api */

	gvplugin_package_t *packages;   /* list of available packages */

        /* externally provided write() displine */
	size_t (*write_fn) (GVJ_t *job, const char *s, size_t len);

	/* fonts and textlayout */
	Dtdisc_t textfont_disc;
	Dt_t *textfont_dt;
	gvplugin_active_textlayout_t textlayout; /* always use best avail for all jobs */
//	void (*free_layout) (void *layout);   /* function for freeing layouts (mostly used by pango) */
	
/* FIXME - everything below should probably move to GVG_t */

	/* gvrender_config() */
	GVJ_t *jobs;	/* linked list of jobs */
	GVJ_t *job;	/* current job */

	graph_t *g;      /* current graph */

	/* gvrender_begin_job() */
	gvplugin_active_layout_t layout;

	char *graphname;	/* name from graph */
	GVJ_t *active_jobs;   /* linked list of active jobs */

	/* pagination */
	char *pagedir;		/* pagination order */
	pointf margin;		/* margins in graph units */
	pointf pad;		/* pad in graph units */
	pointf pageSize;	/* pageSize in graph units, not including margins */
	point pb;		/* page size - including margins (inches) */
	boxf bb;		/* graph bb in graph units, not including margins */
	int rotation;		/* rotation - 0 = portrait, 90 = landscape */
	boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation;

	/* layers */
	char *layerDelims;	/* delimiters in layer names */
	char *layerListDelims;	/* delimiters between layer ranges */ 
	char *layers;		/* null delimited list of layer names */
	char **layerIDs;	/* array of layer names */
	int numLayers;		/* number of layers */
	int *layerlist;

	/* default font */
	char *defaultfontname;
	double defaultfontsize;

	/* default line style */
	char **defaultlinestyle;

	/* render defaults set from graph */
	gvcolor_t bgcolor;	/* background color */

	/* whether to mangle font names (at least in SVG), usually false */
	int fontrenaming;
    };











#line 32 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcproc.h" 1
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

/* This is the public header for the callers of libgvc */






/* these are intended to be private entry points - see gvc.h for the public ones */

/* configuration */

     char *gvconfig_libdir(GVC_t * gvc);
     void gvconfig(GVC_t * gvc, boolean rescan);
     char *gvhostname(void);

/* plugins */

     boolean gvplugin_install(GVC_t * gvc, api_t api,
		    const char *typestr, int quality, gvplugin_package_t *package,
		    gvplugin_installed_t * typeptr);
     gvplugin_available_t *gvplugin_load(GVC_t * gvc, api_t api, const char *type);
     gvplugin_library_t *gvplugin_library_load(GVC_t *gvc, char *path);
     api_t gvplugin_api(char *str);
     char * gvplugin_api_name(api_t api);
     void gvplugin_write_status(GVC_t * gvc);
     char *gvplugin_list(GVC_t * gvc, api_t api, const char *str);

     Agraph_t * gvplugin_graph(GVC_t * gvc);

/* job */

     void gvjobs_output_filename(GVC_t * gvc, const char *name);
     boolean gvjobs_output_langname(GVC_t * gvc, const char *name);
     GVJ_t *gvjobs_first(GVC_t * gvc);
     GVJ_t *gvjobs_next(GVC_t * gvc);
     void gvjobs_delete(GVC_t * gvc);

/* emit */
     void gvemit_graph(GVC_t * gvc, graph_t * g);

/* textlayout */

     int gvtextlayout_select(GVC_t * gvc);
     boolean gvtextlayout(GVC_t *gvc, textspan_t *span, char **fontpath);

/* loadimage */
     void gvloadimage(GVJ_t *job, usershape_t *us, boxf b, boolean filled, const char *target);
    
/* usershapes */
     point gvusershape_size_dpi(usershape_t *us, pointf dpi);
     point gvusershape_size(graph_t *g, char *name);
     usershape_t *gvusershape_find(char *name);

/* device */
     int gvdevice_initialize(GVJ_t * job);
     void gvdevice_format(GVJ_t * job);
     void gvdevice_finalize(GVJ_t * job);

/* render */

     pointf gvrender_ptf(GVJ_t *job, pointf p);
     pointf* gvrender_ptf_A(GVJ_t *job, pointf *af, pointf *AF, int n);

     int gvrender_begin_job(GVJ_t * job);
     void gvrender_end_job(GVJ_t * job);
     int gvrender_select(GVJ_t * job, const char *lang);
     int gvrender_features(GVJ_t * job);
     void gvrender_begin_graph(GVJ_t * job, graph_t * g);
     void gvrender_end_graph(GVJ_t * job);
     void gvrender_begin_page(GVJ_t * job);
     void gvrender_end_page(GVJ_t * job);
     void gvrender_begin_layer(GVJ_t * job);
     void gvrender_end_layer(GVJ_t * job);
     void gvrender_begin_cluster(GVJ_t * job, graph_t * sg);
     void gvrender_end_cluster(GVJ_t * job, graph_t *g);
     void gvrender_begin_nodes(GVJ_t * job);
     void gvrender_end_nodes(GVJ_t * job);
     void gvrender_begin_edges(GVJ_t * job);
     void gvrender_end_edges(GVJ_t * job);
     void gvrender_begin_node(GVJ_t * job, node_t * n);
     void gvrender_end_node(GVJ_t * job);
     void gvrender_begin_edge(GVJ_t * job, edge_t * e);
     void gvrender_end_edge(GVJ_t * job);
     void gvrender_begin_anchor(GVJ_t * job,
		char *href, char *tooltip, char *target, char *id);
     void gvrender_end_anchor(GVJ_t * job);
     void gvrender_begin_label(GVJ_t * job, label_type type);
     void gvrender_end_label(GVJ_t * job);
     void gvrender_textspan(GVJ_t * job, pointf p, textspan_t * span);
     void gvrender_set_pencolor(GVJ_t * job, char *name);
     void gvrender_set_penwidth(GVJ_t * job, double penwidth);
     void gvrender_set_fillcolor(GVJ_t * job, char *name);
     void gvrender_set_gradient_vals (GVJ_t * job, char *stopcolor, int angle, float frac);

     void gvrender_set_style(GVJ_t * job, char **s);
     void gvrender_ellipse(GVJ_t * job, pointf * AF, int n, int filled);
     void gvrender_polygon(GVJ_t* job, pointf* af, int n, int filled);
     void gvrender_box(GVJ_t * job, boxf BF, int filled);
     void gvrender_beziercurve(GVJ_t * job, pointf * AF, int n,
			int arrow_at_start, int arrow_at_end, boolean filled);
     void gvrender_polyline(GVJ_t * job, pointf * AF, int n);
     void gvrender_comment(GVJ_t * job, char *str);
     void gvrender_usershape(GVJ_t * job, char *name, pointf * AF, int n, boolean filled, char *imagescale);

/* layout */

     int gvlayout_select(GVC_t * gvc, const char *str);
     int gvFreeLayout(GVC_t * gvc, Agraph_t * g);
     int gvLayoutJobs(GVC_t * gvc, Agraph_t * g);

/* argvlist */
     gv_argvlist_t *gvNEWargvlist(void);
     void gv_argvlist_set_item(gv_argvlist_t *list, int index, char *item);
     void gv_argvlist_reset(gv_argvlist_t *list);
     void gv_argvlist_free(gv_argvlist_t *list);




#line 33 "graphviz-2.38.0\\lib\\common\\render.h" 2

    typedef struct epsf_s {
	int macro_id;
	point offset;
    } epsf_t;

    typedef void (*nodesizefn_t) (Agnode_t *, boolean);

/*visual studio*/





/*end visual studio*/

	extern void add_box(path *, boxf);
    extern void arrow_flags(Agedge_t * e, int *sflag, int *eflag);
    extern boxf arrow_bb(pointf p, pointf u, double arrowsize, int flag);
    extern void arrow_gen(GVJ_t * job, emit_state_t emit_state, pointf p, pointf u,
			  double arrowsize, double penwidth, int flag);
    extern double arrow_length(edge_t * e, int flag);
    extern int arrowEndClip(edge_t*, pointf*, int, int , bezier*, int eflag);
    extern int arrowStartClip(edge_t*, pointf* ps, int, int, bezier*, int sflag);
    extern void arrowOrthoClip(edge_t*, pointf* ps, int, int, bezier*, int sflag, int eflag);
    extern void beginpath(path *, Agedge_t *, int, pathend_t *, boolean);
    extern void bezier_clip(inside_t * inside_context,
			    boolean(*insidefn) (inside_t * inside_context,
						pointf p), pointf * sp,
			    boolean left_inside);
    extern shape_desc *bind_shape(char *name, node_t *);
    extern void makeStraightEdge(graph_t * g, edge_t * e, int edgetype, splineInfo * info);
    extern void makeStraightEdges(graph_t* g, edge_t** edges, int e_cnt, int et, splineInfo* sinfo);
    extern void clip_and_install(edge_t * fe, node_t * hn,
	pointf * ps, int pn, splineInfo * info);
    extern char* charsetToStr (int c);
    extern pointf coord(node_t * n);
    extern void do_graph_label(graph_t * sg);
    extern void graph_init(graph_t * g, boolean use_rankdir);
    extern void graph_cleanup(graph_t * g);
    extern int dotneato_args_initialize(GVC_t * gvc, int, char **);
    extern int dotneato_usage(int);
    extern void dotneato_postprocess(Agraph_t *);
    extern void gv_postprocess(Agraph_t *, int);
    extern void dotneato_set_margins(GVC_t * gvc, Agraph_t *);
    extern void dotneato_write(GVC_t * gvc, graph_t *g);
    extern void dotneato_write_one(GVC_t * gvc, graph_t *g);
    extern Ppolyline_t* ellipticWedge (pointf ctr, double major, double minor, double angle0, double angle1);
    extern void emit_clusters(GVJ_t * job, Agraph_t * g, int flags);
    extern char* getObjId (GVJ_t* job, void* obj, agxbuf* xb);
    /* extern void emit_begin_edge(GVJ_t * job, edge_t * e, char**); */
    /* extern void emit_end_edge(GVJ_t * job); */
    extern void emit_graph(GVJ_t * job, graph_t * g);
    extern void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t *);
    extern int emit_once(char *message);
    extern void emit_jobs_eof(GVC_t * gvc);
    extern void emit_map_rect(GVJ_t *job, boxf b);
    extern void enqueue_neighbors(nodequeue *, Agnode_t *, int);
    extern void endpath(path *, Agedge_t *, int, pathend_t *, boolean);
    extern void epsf_init(node_t * n);
    extern void epsf_free(node_t * n);
    extern shape_desc *find_user_shape(const char *);
    extern void free_line(textspan_t *);
    extern void free_label(textlabel_t *);
    extern void free_textspan(textspan_t * tl, int);
    extern void getdouble(graph_t * g, char *name, double *result);
    extern splines *getsplinepoints(edge_t * e);
    extern void gv_fixLocale (int set);
    extern void gv_free_splines(edge_t * e);
    extern void gv_cleanup_edge(Agedge_t * e);
    extern void gv_cleanup_node(Agnode_t * n);
    extern void* init_xdot (Agraph_t* g);
    extern int initMapData (GVJ_t*, char*, char*, char*, char*, char*, void*);
    extern boolean isPolygon(node_t *);
    extern void makeSelfEdge(path * P, edge_t * edges[], int ind, int cnt,
	double sizex, double sizey, splineInfo * sinfo);
    extern textlabel_t *make_label(void *obj, char *str, int kind, double fontsize, char *fontname, char *fontcolor);
    extern bezier *new_spline(edge_t * e, int sz);
    extern char **parse_style(char *s);
    extern void place_graph_label(Agraph_t *);
    extern int place_portlabel(edge_t * e, boolean head_p);
    extern void makePortLabels(edge_t * e);
    extern pointf edgeMidpoint(graph_t* g, edge_t * e);
    extern void addEdgeLabels(graph_t* g, edge_t * e, pointf rp, pointf rq);
    extern void pop_obj_state(GVJ_t *job);
    extern obj_state_t* push_obj_state(GVJ_t *job);
    extern int rank(graph_t * g, int balance, int maxiter);
    extern port resolvePort(node_t*  n, node_t* other, port* oldport);
    extern void resolvePorts (edge_t* e);
    extern void round_corners(GVJ_t * job, pointf * AF, int sides, int style, int filled);
    extern int routesplinesinit(void);
    extern pointf *routesplines(path *, int *);
    extern void routesplinesterm(void);
    extern pointf* simpleSplineRoute (pointf, pointf, Ppoly_t, int*, int);
    extern pointf *routepolylines(path* pp, int* npoints);
    extern int selfRightSpace (edge_t* e);
    extern void setup_graph(GVC_t * gvc, graph_t * g);
    extern shape_kind shapeOf(node_t *);
    extern void shape_clip(node_t * n, pointf curve[4]);
    extern void make_simple_label (GVC_t * gvc, textlabel_t* rv);
    extern int stripedBox (GVJ_t * job, pointf* AF, char* clrs, int rotate);
    extern stroke_t* taper (bezier*, double (*radfunc_t)(double,double,double), double initwid, int linejoin, int linecap);
    extern stroke_t* taper0 (bezier* bez, double initwid);
    extern pointf textspan_size(GVC_t * gvc, textspan_t * span);
    extern Dt_t * textfont_dict_open(GVC_t *gvc);
    extern void textfont_dict_close(GVC_t *gvc);
    extern void translate_bb(Agraph_t *, int);
    extern int wedgedEllipse (GVJ_t* job, pointf * pf, char* clrs);
    extern void update_bb_bz(boxf *bb, pointf *cp);
    extern void write_attributed_dot(graph_t *g, FILE *f);
    extern void write_canonical_dot(graph_t *g, FILE *f);
    extern boxf xdotBB (graph_t* g);
    extern char *findAttrColor(void *obj, attrsym_t *colorattr, char *dflt);








#line 18 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 2
#line 1 "graphviz-2.38.0\\lib\\dotgen\\dotprocs.h" 1
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





1			/* public data */

/* tabs at 8, or you're a sorry loser */




#line 1 "graphviz-2.38.0\\lib\\dotgen\\aspect.h" 1
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




typedef struct aspect_t {
    double targetAR;      /* target aspect ratio */
    double combiAR;
    int prevIterations;   /* no. of iterations in previous pass */
    int curIterations;    /* no. of iterations in current pass */
    int nextIter;         /* dynamically adjusted no. of iterations */
    int nPasses;          /* bound on no. of top-level passes */
    int badGraph;         /* hack: set if graph is disconnected or has
                           * clusters. If so, turn off aspect */
} aspect_t;

extern aspect_t* setAspect (Agraph_t * g, aspect_t* adata);
extern void rank3(graph_t * g, aspect_t * asp);
extern void initEdgeTypes(graph_t * g);
extern void init_UF_size(graph_t * g);
extern int countDummyNodes(graph_t * g);



#line 21 "graphviz-2.38.0\\lib\\dotgen\\dotprocs.h" 2

    extern void acyclic(Agraph_t *);
    extern void allocate_ranks(Agraph_t *);
    extern void build_ranks(Agraph_t *, int);
    extern void build_skeleton(Agraph_t *, Agraph_t *);
    extern void class1(Agraph_t *);
    extern void class2(Agraph_t *);
    extern void decompose(Agraph_t *, int);
    extern void delete_fast_edge(Agedge_t *);
    extern void delete_fast_node(Agraph_t *, Agnode_t *);
    extern void delete_flat_edge(Agedge_t *);
    extern void dot_cleanup(graph_t * g);
    extern void dot_layout(Agraph_t * g);
    extern void dot_init_node_edge(graph_t * g);
    extern void dot_scan_ranks(graph_t * g);
    extern void enqueue_neighbors(nodequeue * q, node_t * n0, int pass);
    extern void expand_cluster(Agraph_t *);
    extern Agedge_t *fast_edge(Agedge_t *);
    extern void fast_node(Agraph_t *, Agnode_t *);
    extern void fast_nodeapp(Agnode_t *, Agnode_t *);
    extern Agedge_t *find_fast_edge(Agnode_t *, Agnode_t *);
    extern Agedge_t *find_flat_edge(Agnode_t *, Agnode_t *);
    extern void flat_edge(Agraph_t *, Agedge_t *);
    extern int flat_edges(Agraph_t *);
    extern void install_cluster(Agraph_t *, Agnode_t *, int, nodequeue *);
    extern void install_in_rank(Agraph_t *, Agnode_t *);
    extern int is_cluster(Agraph_t *);
    extern void dot_compoundEdges(Agraph_t *);
    extern Agedge_t *make_aux_edge(Agnode_t *, Agnode_t *, double, int);
    extern void mark_clusters(Agraph_t *);
    extern void mark_lowclusters(Agraph_t *);
    extern int mergeable(edge_t * e, edge_t * f);
    extern void merge_chain(Agraph_t *, Agedge_t *, Agedge_t *, int);
    extern void merge_oneway(Agedge_t *, Agedge_t *);
    extern int ncross(Agraph_t *);
    extern Agedge_t *new_virtual_edge(Agnode_t *, Agnode_t *, Agedge_t *);
    extern int nonconstraint_edge(Agedge_t *);
    extern void other_edge(Agedge_t *);
    extern void rank1(graph_t * g);
    extern int portcmp(port p0, port p1);
    extern int ports_eq(edge_t *, edge_t *);
    extern void rec_reset_vlists(Agraph_t *);
    extern void rec_save_vlists(Agraph_t *);
    extern void reverse_edge(Agedge_t *);
    extern void safe_other_edge(Agedge_t *);
    extern void save_vlist(Agraph_t *);
    extern void unmerge_oneway(Agedge_t *);
    extern Agedge_t *virtual_edge(Agnode_t *, Agnode_t *, Agedge_t *);
    extern Agnode_t *virtual_node(Agraph_t *);
    extern void virtual_weight(Agedge_t *);
    extern void zapinlist(elist *, Agedge_t *);




    extern Agraph_t* dot_root(void *);
    extern void dot_concentrate(Agraph_t *);
    extern void dot_mincross(Agraph_t *, int);
    extern void dot_position(Agraph_t *, aspect_t*);
    extern void dot_rank(Agraph_t *, aspect_t*);
    extern void dot_sameports(Agraph_t *);
    extern void dot_splines(Agraph_t *);



     





#line 19 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 2


#line 31 "graphviz-2.38.0\\lib\\dotgen\\rank.c" 2

static void dot1_rank(graph_t * g, aspect_t* asp);
static void dot2_rank(graph_t * g, aspect_t* asp);

static void 
renewlist(elist * L)
{
    int i;
    for (i = L->size; i >= 0; i--)
	L->list[i] = NULL;
    L->size = 0;
}

static void 
cleanup1(graph_t * g)
{
    node_t *n;
    edge_t *e, *f;
    int c;

    for (c = 0; c < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size; c++) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list[c];
	for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	    renewlist(&(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in));
	    renewlist(&(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out));
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mark) = 0;
	}
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    f = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt);
	    /* Null out any other references to f to make sure we don't 
	     * handle it a second time. For example, parallel multiedges 
	     * share a virtual edge.
	     */
	    if (f && (e == (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_orig))) {
		edge_t *e1, *f1;
		node_t *n1;
		for (n1 = agfstnode(g); n1; n1 = agnxtnode(g, n1)) {
		    for (e1 = agfstout(g, n1); e1; e1 = agnxtout(g, e1)) {
			if (e != e1) {
			    f1 = (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->to_virt);
			    if (f1 && (f == f1)) {
				(((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->to_virt) = NULL;
			    }
			}
		    }
		}
		free(f->base.data);
		free(f);
	    }
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt) = NULL;
	}
    }
    free((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list = NULL;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size = 0;
}

/* When there are edge labels, extra ranks are reserved here for the virtual
 * nodes of the labels.  This is done by doubling the input edge lengths.
 * The input rank separation is adjusted to compensate.
 */
static void 
edgelabel_ranks(graph_t * g)
{
    node_t *n;
    edge_t *e;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_labels) & (1 << 0)) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    for (e = agfstout(g, n); e; e = agnxtout(g, e))
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) *= 2;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->ranksep) = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->ranksep) + 1) / 2;
    }
}

/* Merge the nodes of a min, max, or same rank set. */
static void 
collapse_rankset(graph_t * g, graph_t * subg, int kind)
{
    node_t *u, *v;

    u = v = agfstnode(subg);
    if (u) {
	(((Agnodeinfo_t*)(((Agobj_t*)(u))->data))->ranktype) = kind;
	while ((v = agnxtnode(subg, v))) {
	    UF_union(u, v);
	    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->ranktype) = (((Agnodeinfo_t*)(((Agobj_t*)(u))->data))->ranktype);
	}
	switch (kind) {
	case 2:
	case 3:
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) == NULL)
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) = u;
	    else
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) = UF_union((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset), u);
	    break;
	case 4:
	case 5:
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) == NULL)
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) = u;
	    else
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) = UF_union((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset), u);
	    break;
	}
	switch (kind) {
	case 3:
	    (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset)))->data))->ranktype) = kind;
	    break;
	case 5:
	    (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset)))->data))->ranktype) = kind;
	    break;
	}
    }
}

static int 
rank_set_class(graph_t * g)
{
    static char *name[] = { "same", "min", "source", "max", "sink", NULL };
    static int class[] =
	{ 1, 2, 3, 4, 5, 0 };
    int val;

    if (is_cluster(g))
	return 7;
    val = maptoken(agget(g, "rank"), name, class);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->set_type) = val;
    return val;
}

static int 
make_new_cluster(graph_t * g, graph_t * subg)
{
    int cno;
    cno = ++((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster));
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust) = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)? (graph_t **)zrealloc((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust),cno + 1,sizeof(graph_t *),(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster)):(graph_t **)zmalloc((cno + 1)*sizeof(graph_t *)));
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[cno] = subg;
    do_graph_label(subg);
    return cno;
}

static void 
node_induce(graph_t * par, graph_t * g)
{
    node_t *n, *nn;
    edge_t *e;
    int i;

    /* enforce that a node is in at most one cluster at this level */
    for (n = agfstnode(g); n; n = nn) {
	nn = agnxtnode(g, n);
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype)) {
	    agdelete(g, n);
	    continue;
	}
	for (i = 1; i < (((Agraphinfo_t*)(((Agobj_t*)(par))->data))->n_cluster); i++)
	    if (agcontains((((Agraphinfo_t*)(((Agobj_t*)(par))->data))->clust)[i], n))
		break;
	if (i < (((Agraphinfo_t*)(((Agobj_t*)(par))->data))->n_cluster))
	    agdelete(g, n);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust) = NULL;
    }

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(dot_root(g), n); e; e = agnxtout(dot_root(g), e)) {
	    if (agcontains(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)))
		agsubedge(g,e,1);
	}
    }
}

void 
dot_scan_ranks(graph_t * g)
{
    node_t *n, *leader = NULL;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (0x7fff);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = -1;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	if (leader == NULL)
	    leader = n;
	else {
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) < (((Agnodeinfo_t*)(((Agobj_t*)(leader))->data))->rank))
		leader = n;
	}
    }
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->leader) = leader;
}

static void
cluster_leader(graph_t * clust)
{
    node_t *leader, *n;
    int maxrank = 0;

    /* find number of ranks and select a leader */
    leader = NULL;
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) == 0) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0))
	    leader = n;
	if (maxrank < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
	    maxrank = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
    }
    assert(leader != NULL);
    (((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->leader) = leader;

    for (n = agfstnode(clust); n; n = agnxtnode(clust, n)) {
	assert(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->UF_size) <= 1) || (n == leader));
	UF_union(n, leader);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype) = 7;
    }
}

/*
 * A cluster is collapsed in three steps.
 * 1) The nodes of the cluster are ranked locally.
 * 2) The cluster is collapsed into one node on the least rank.
 * 3) In class1(), any inter-cluster edges are converted using
 *    the "virtual node + 2 edges" trick.
 */
static void 
collapse_cluster(graph_t * g, graph_t * subg)
{
    if ((((Agraphinfo_t*)(((Agobj_t*)(subg))->data))->parent)) {
	return;
    }
    (((Agraphinfo_t*)(((Agobj_t*)(subg))->data))->parent) = g;
    node_induce(g, subg);
    if (agfstnode(subg) == NULL)
	return;
    make_new_cluster(g, subg);
    if (CL_type == 100) {
	dot1_rank(subg, 0);
	cluster_leader(subg);
    } else
	dot_scan_ranks(subg);
}

/* Execute union commands for "same rank" subgraphs and clusters. */
static void 
collapse_sets(graph_t *rg, graph_t *g)
{
    int c;
    graph_t  *subg;

    


    for (subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
	c = rank_set_class(subg);
	if (c) {
	    if ((c == 7) && CL_type == 100)
		collapse_cluster(rg, subg);
	    else
		collapse_rankset(rg, subg, c);
	}
	else collapse_sets(rg, subg);


 

	
	
	    
		

    }
}

static void 
find_clusters(graph_t * g)
{
    graph_t *subg;
    for (subg = agfstsubg(dot_root(g)); subg; subg = agnxtsubg(subg)) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(subg))->data))->set_type) == 7)
	    collapse_cluster(g, subg);
    }
}

static void 
set_minmax(graph_t * g)
{
    int c;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) += (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->leader)))->data))->rank);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) += (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->leader)))->data))->rank);
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	set_minmax((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c]);
}

/* To ensure that min and max rank nodes always have the intended rank
 * assignment, reverse any incompatible edges.
 */
static point 
minmax_edges(graph_t * g)
{
    node_t *n;
    edge_t *e;
    point  slen;

    slen.x = slen.y = 0;
    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) == NULL) && ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) == NULL))
	return slen;
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) != NULL)
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) = UF_find((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset));
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) != NULL)
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) = UF_find((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset));

    if ((n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset))) {
	slen.y = ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset)))->data))->ranktype) == 5);
	while ((e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0])) {
	    assert(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node) == UF_find(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	    reverse_edge(e);
	}
    }
    if ((n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset))) {
	slen.x = ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset)))->data))->ranktype) == 3);
	while ((e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[0])) {
	    assert(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) == UF_find(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)));
	    reverse_edge(e);
	}
    }
    return slen;
}
    
static int 
minmax_edges2(graph_t * g, point slen)
{
    node_t *n;
    edge_t *e = 0;

    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset)) || ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset))) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    if (n != UF_find(n))
		continue;
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size == 0) && (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset) && (n != (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset))) {
		e = virtual_edge(n, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxset), NULL);
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = slen.y;
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) = 0;
	    }
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size == 0) && (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset) && (n != (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset))) {
		e = virtual_edge((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minset), n, NULL);
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = slen.x;
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) = 0;
	    }
	}
    }
    return (e != 0);
}

/* Run the network simplex algorithm on each component. */
void rank1(graph_t * g)
{
    int maxiter = ((int)(~(unsigned)0 >> 1));
    int c;
    char *s;

    if ((s = agget(g, "nslimit1")))
	maxiter = atof(s) * agnnodes(g);
    for (c = 0; c < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size; c++) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list[c];
	rank(g, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster) == 0 ? 1 : 0), maxiter);	/* TB balance */
    }
}

/* 
 * Assigns ranks of non-leader nodes.
 * Expands same, min, max rank sets.
 * Leaf sets and clusters remain merged.
 * Sets minrank and maxrank appropriately.
 */
static void expand_ranksets(graph_t * g, aspect_t* asp)
{
    int c;
    node_t *n, *leader;

    if ((n = agfstnode(g))) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (0x7fff);
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = -1;
	while (n) {
	    leader = UF_find(n);
	    /* The following works because ND_rank(n) == 0 if n is not in a
	     * cluster, and ND_rank(n) = the local rank offset if n is in
	     * a cluster. */
	    if ((leader != n) && (!asp || ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) == 0)))
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) += (((Agnodeinfo_t*)(((Agobj_t*)(leader))->data))->rank);

	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);

	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype) != 6))
		UF_singleton(n);
	    n = agnxtnode(g, n);
	}
	if (g == dot_root(g)) {
	    if (CL_type == 100) {
		for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
		    set_minmax((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c]);
	    } else {
		find_clusters(g);
	    }
	}
    } else {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = 0;
    }
}





    
    
    
    

    
	
	
	
	    
	
    











    
    
    
    
    
    
	
    
    
	
    

  
    
	
	    
	    
	
    

    
    
    

    
	
	    
	    
		
		
		
		    
			
			
		
	    
	
    





    
    

    
	
	    
		
		    
	    
	
    
    
	



/* dot1_rank:
 * asp != NULL => g is root
 */
static void dot1_rank(graph_t * g, aspect_t* asp)
{
    point p;

    

    edgelabel_ranks(g);

    if (asp) {
	init_UF_size(g);
	initEdgeTypes(g);
    }

    collapse_sets(g,g);
    /*collapse_leaves(g); */
    class1(g);
    p = minmax_edges(g);
    decompose(g, 0);
    if (asp && (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size > 1)||((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster) > 0))) {
	asp->badGraph = 1;
	asp = NULL;
    }
    acyclic(g);
    if (minmax_edges2(g, p))
	decompose(g, 0);

    
	
    


    if (asp)
	rank3(g, asp);
    else
	rank1(g);

    expand_ranksets(g, asp);
    cleanup1(g);
}

void dot_rank(graph_t * g, aspect_t* asp)
{
    if (agget (g, "newrank")) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->flags) |= (1 << 4);
	dot2_rank (g, asp);
    }
    else
	dot1_rank (g, asp);
    if (Verbose)
	fprintf (stderr, "Maxrank = %d, minrank = %d\n", (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank), (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank));
}

int is_cluster(graph_t * g)
{
    return (strncmp(agnameof(g), "cluster", 7) == 0);
}





    

    
	
    
	
	
	
	
    
    





    

    
	
    
	
    
    
    
	
    
	





    
    

    

	
	
	    
	
	    
		
		
	    
	
	
	    
		
		
	    
	
    



/* new ranking code:
 * Allows more constraints
 * Copy of level.c in dotgen2
 * Many of the utility functions are simpler or gone with
 * cgraph library.
 */







/* hops is not used in dot, so we overload it to 
 * contain the index of the connected component
 */


extern int rank2(Agraph_t *, int, int, int);

static void set_parent(graph_t* g, graph_t* p) 
{
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->parent) = p;
    make_new_cluster(p, g);
    node_induce(p, g);
}

static int is_empty(graph_t * g)
{
    return (!agfstnode(g));
}

static int is_a_strong_cluster(graph_t * g)
{
    int rv;
    char *str = agget(g, "compact");
    /* rv = mapBool((str), TRUE); */
    rv = mapBool((str), 0);
    return rv;
}

static int rankset_kind(graph_t * g)
{
    char *str = agget(g, "rank");

    if (str && str[0]) {
	if (!strcmp(str, "min"))
	    return 2;
	if (!strcmp(str, "source"))
	    return 3;
	if (!strcmp(str, "max"))
	    return 4;
	if (!strcmp(str, "sink"))
	    return 5;
	if (!strcmp(str, "same"))
	    return 1;
    }
    return 6;
}

static int is_nonconstraint(edge_t * e)
{
    char *constr;

    if (E_constr && (constr = agxget(e, E_constr))) {
	if (constr[0] && mapbool(constr) == 0)
	    return (!(0));
    }
    return 0;
}

static node_t *find(node_t * n)
{
    node_t *set;
    if ((set = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->set))) {
	if (set != n)
	    set = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->set) = find(set);
    } else
	set = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->set) = n;
    return set;
}

static node_t *union_one(node_t * leader, node_t * n)
{
    if (n)
	return ((((Agnodeinfo_t*)(((Agobj_t*)(find(n)))->data))->set) = find(leader));
    else
	return leader;
}

static node_t *union_all(graph_t * g)
{
    node_t *n, *leader;

    n = agfstnode(g);
    if (!n)
	return n;
    leader = find(n);
    while ((n = agnxtnode(g, n)))
	union_one(leader, n);
    return leader;
}

static void compile_samerank(graph_t * ug, graph_t * parent_clust)
{
    graph_t *s;			/* subgraph being scanned */
    graph_t *clust;		/* cluster that contains the rankset */
    node_t *n, *leader;

    if (is_empty(ug))
	return;
    if (is_a_cluster(ug)) {
	clust = ug;
	if (parent_clust) {
	    (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->level) = (((Agraphinfo_t*)(((Agobj_t*)(parent_clust))->data))->level) + 1;
	    set_parent(ug, parent_clust);
	}
	else
	    (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->level) = 0;
    } else
	clust = parent_clust;

    /* process subgraphs of this subgraph */
    for (s = agfstsubg(ug); s; s = agnxtsubg(s))
	compile_samerank(s, clust);

    /* process this subgraph as a cluster */
    if (is_a_cluster(ug)) {
	for (n = agfstnode(ug); n; n = agnxtnode(ug, n)) {
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust) == 0)
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust) = ug;

	    
		    

	}
    }

    /* process this subgraph as a rankset */
    switch (rankset_kind(ug)) {
    case 3:
	(((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->has_sourcerank) = (!(0));	/* fall through */
    case 2:
	leader = union_all(ug);
	(((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->minrep) = union_one(leader, (((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->minrep));
	break;
    case 5:
	(((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->has_sinkrank) = (!(0));	/* fall through */
    case 4:
	leader = union_all(ug);
	(((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->maxrep) = union_one(leader, (((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->maxrep));
	break;
    case 1:
	leader = union_all(ug);
	/* do we need to record these ranksets? */
	break;
    case 6:
	break;
    default:			/* unrecognized - warn and do nothing */
	agerr(AGWARN, "%s has unrecognized rank=%s", agnameof(ug),
	      agget(ug, "rank"));
    }

    /* a cluster may become degenerate */
    if (is_a_cluster(ug) && (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->minrep)) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->minrep) == (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->maxrep)) {
	    node_t *up = union_all(ug);
	    (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->minrep) = up;
	    (((Agraphinfo_t*)(((Agobj_t*)(ug))->data))->maxrep) = up;
	}
    }
}

static graph_t *dot_lca(graph_t * c0, graph_t * c1)
{
    while (c0 != c1) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(c0))->data))->level) >= (((Agraphinfo_t*)(((Agobj_t*)(c1))->data))->level))
	    c0 = (((Agraphinfo_t*)(((Agobj_t*)(c0))->data))->parent);
	else
	    c1 = (((Agraphinfo_t*)(((Agobj_t*)(c1))->data))->parent);
    }
    return c0;
}

static int is_internal_to_cluster(edge_t * e)
{
    graph_t *par, *ct, *ch;
    ct = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->clust);
    ch = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->clust);
    if (ct == ch)
	return (!(0));
    par = dot_lca(ct, ch);
    /* if (par == agroot(par)) */
	/* return FALSE; */
    if ((par == ct) || (par == ch))
	return (!(0));
    return 0;
}

static node_t* Last_node;
static node_t* makeXnode (graph_t* G, char* name)
{
    node_t *n = agnode(G, name, 1);
    do {(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list = (edge_t**)zmalloc((4 + 1)*sizeof(edge_t*)); } while (0);
    do {(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list = (edge_t**)zmalloc((4 + 1)*sizeof(edge_t*)); } while (0);
    if (Last_node) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->prev) = Last_node;
	(((Agnodeinfo_t*)(((Agobj_t*)(Last_node))->data))->next) = n;
    } else {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->prev) = NULL;
	(((Agraphinfo_t*)(((Agobj_t*)(G))->data))->nlist) = n;
    }
    Last_node = n;
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next) = NULL;
    
    return n;
}

static void compile_nodes(graph_t * g, graph_t * Xg)
{
    /* build variables */
    node_t *n;

    Last_node = NULL;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if (find(n) == n)
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rep) = makeXnode (Xg, agnameof(n));
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rep) == 0)
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rep) = (((Agnodeinfo_t*)(((Agobj_t*)(find(n)))->data))->rep);
    }
}

static void merge(edge_t * e, int minlen, int weight)
{
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen))>(minlen)?((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen)):(minlen));
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) += weight;
}

static void strong(graph_t * g, node_t * t, node_t * h, edge_t * orig)
{
    edge_t *e;
    if ((e = (agedge(g,t,h,NULL,0))) ||
	(e = (agedge(g,h,t,NULL,0))) || (e = agedge(g, t, h, 0, 1)))
	merge(e, (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->minlen), (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->weight));
    else
	agerr(AGERR, "ranking: failure to create strong constraint edge between nodes %s and %s\n", 
	    agnameof(t), agnameof(h));
}

static void weak(graph_t * g, node_t * t, node_t * h, edge_t * orig)
{
    node_t *v;
    edge_t *e, *f;
    static int id;
    char buf[100];

    for (e = agfstin(g, t); e; e = agnxtin(g, e)) {
	/* merge with existing weak edge (e,f) */
	v = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	if ((f = agfstout(g, v)) && (((((((Agobj_t*)(f))->tag).objtype) == 2? (f): ((f)-1))->node) == h)) {
	    return;
	}
    }
    if (!e) {
	sprintf (buf, "_weak_%d", id++);
	v = makeXnode(g, buf);
	e = agedge(g, v, t, 0, 1);
	f = agedge(g, v, h, 0, 1);
    }
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen))>(0)?((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen)):(0));	/* effectively a nop */
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) += (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->weight) * 1000;
    (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->minlen) = (((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->minlen))>((((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->minlen))?((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->minlen)):((((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->minlen)));
    (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->weight) += (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->weight);
}

static void compile_edges(graph_t * ug, graph_t * Xg)
{
    node_t *n;
    edge_t *e;
    node_t *Xt, *Xh;
    graph_t *tc, *hc;

    /* build edge constraints */
    for (n = agfstnode(ug); n; n = agnxtnode(ug, n)) {
	Xt = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rep);
	for (e = agfstout(ug, n); e; e = agnxtout(ug, e)) {
	    if (is_nonconstraint(e))
		continue;
	    Xh = (((Agnodeinfo_t*)(((Agobj_t*)(find(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node))))->data))->rep);
	    if (Xt == Xh)
		continue;

	    tc = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->clust);
	    hc = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->clust);

	    if (is_internal_to_cluster(e)) {
		/* determine if graph requires reversed edge */
		if ((find(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)) == (((Agraphinfo_t*)(((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->clust)))->data))->maxrep))
		    || (find(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)) == (((Agraphinfo_t*)(((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->clust)))->data))->minrep))) {
		    node_t *temp = Xt;
		    Xt = Xh;
		    Xh = temp;
		}
		strong(Xg, Xt, Xh, e);
	    } else {
		if (is_a_strong_cluster(tc) || is_a_strong_cluster(hc))
		    weak(Xg, Xt, Xh, e);
		else
		    strong(Xg, Xt, Xh, e);
	    }
	}
    }
}

static void compile_clusters(graph_t* g, graph_t* Xg, node_t* top, node_t* bot)
{
    node_t *n;
    node_t *rep;
    edge_t *e;
    graph_t *sub;

    if (is_a_cluster(g) && is_a_strong_cluster(g)) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    if (agfstin(g, n) == 0) {
		rep = (((Agnodeinfo_t*)(((Agobj_t*)(find(n)))->data))->rep);
		if (!top) top = makeXnode(Xg,"\177top");
		agedge(Xg, top, rep, 0, 1);
	    }
	    if (agfstout(g, n) == 0) {
		rep = (((Agnodeinfo_t*)(((Agobj_t*)(find(n)))->data))->rep);
		if (!bot)  bot = makeXnode(Xg,"\177bot");
		agedge(Xg, rep, bot, 0, 1);
	    }
	}
	if (top && bot) {
	    e = agedge(Xg, top, bot, 0, 1);
	    merge(e, 0, 1000);
	}
    }
    for (sub = agfstsubg(g); sub; sub = agnxtsubg(sub))
	compile_clusters(sub, Xg, top, bot);
}

static void reverse_edge2(graph_t * g, edge_t * e)
{
    edge_t *rev;

    rev = (agedge(g,((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node),((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node),NULL,0));
    if (!rev)
	rev = agedge(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), 0, 1);
    merge(rev, (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight));
    agdelete(g, e);
}

static void dfs(graph_t * g, node_t * v)
{
    edge_t *e, *f;
    node_t *w;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark))
	return;
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark) = (!(0));
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->onstack) = (!(0));
    for (e = agfstout(g, v); e; e = f) {
	f = agnxtout(g, e);
	w = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	if ((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->onstack))
	    reverse_edge2(g, e);
	else {
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->mark) == 0)
		dfs(g, w);
	}
    }
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->onstack) = 0;
}

static void break_cycles(graph_t * g)
{
    node_t *n;

    for (n = agfstnode(g); n; n = agnxtnode(g, n))
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mark) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->onstack) = 0;
    for (n = agfstnode(g); n; n = agnxtnode(g, n))
	dfs(g, n);
}

static void setMinMax (graph_t* g, int doRoot)
{
    int c, v;
    node_t *n;
    node_t* leader;

      /* Do child clusters */
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	    setMinMax((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c], 0);

    if (!(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->parent) && !doRoot) // root graph
	return;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (0x7fff);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = -1;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	v = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) < v)
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = v;
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > v) {
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = v;
	    leader = n;
	}
    }
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->leader) = leader;
}

/* readout_levels:
 * Store node rank information in original graph.
 * Set rank bounds in graph and clusters
 * Free added data structures.
 *
 * rank2 is called with balance=1, which ensures that minrank=0
 */
static void readout_levels(graph_t * g, graph_t * Xg, int ncc)
{
    node_t *n;
    node_t *xn;
    int* minrk = NULL;
    int doRoot = 0;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (0x7fff);
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = -1;
    if (ncc > 1) {
	int i;
	minrk = (int*)zmalloc((ncc+1)*sizeof(int));
	for (i = 1; i <= ncc; i++)
	    minrk[i] = (0x7fff);
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	xn = (((Agnodeinfo_t*)(((Agobj_t*)(find(n)))->data))->rep);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) = (((Agnodeinfo_t*)(((Agobj_t*)(xn))->data))->rank);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	if (minrk) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) = (((Agnodeinfo_t*)(((Agobj_t*)(xn))->data))->hops);
	    minrk[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops)] = ((minrk[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops)])<((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank))?(minrk[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops)]):((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)));
	}
    }
    if (minrk) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) -= minrk[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops)];
	/* Non-uniform shifting, so recompute maxrank/minrank of root graph */
	doRoot = 1;
    }
    else if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > 0) {  /* should never happen */
	int delta = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank);
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) -= delta;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) -= delta;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) -= delta;
    }

    setMinMax(g, doRoot);

    /* release fastgraph memory from Xg */
    for (n = agfstnode(Xg); n; n = agnxtnode(Xg, n)) {
	do {if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list) free((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list);} while (0);
	do {if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list) free((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list);} while (0);
    }

    free((((Agnodeinfo_t*)(((Agobj_t*)(agfstnode(g)))->data))->alg));
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->alg) = NULL;
    }
    if (minrk)
	free (minrk);
}

static void dfscc(graph_t * g, node_t * n, int cc)
{
    edge_t *e;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) == 0) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) = cc;
	for (e = agfstout(g, n); e; e = agnxtout(g, e))
	    dfscc(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), cc);
	for (e = agfstin(g, n); e; e = agnxtin(g, e))
	    dfscc(g, ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), cc);
    }
}

static int connect_components(graph_t * g)
{
    int cc = 0;
    node_t *n;

    for (n = agfstnode(g); n; n = agnxtnode(g, n))
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) = 0;
    for (n = agfstnode(g); n; n = agnxtnode(g, n))
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) == 0)
	    dfscc(g, n, ++cc);
    if (cc > 1) {
	node_t *root = makeXnode(g, "\177root");
	int ncc = 1;
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->hops) == ncc) {
		(void) agedge(g, root, n, 0, 1);
		ncc++;
	    }
	}
    }
    return (cc);
}

static void add_fast_edges (graph_t * g)
{
    node_t *n;
    edge_t *e;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list = ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list,((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size] = NULL;} while(0);
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list,((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).size] = NULL;} while(0);
	}
    }
}

static void my_init_graph(Agraph_t *g, Agobj_t *graph, void *arg)
{ int *sz = arg; agbindrec(graph,"level graph rec",sz[0],(!(0))); }
static void my_init_node(Agraph_t *g, Agobj_t *node, void *arg)
{ int *sz = arg; agbindrec(node,"level node rec",sz[1],(!(0))); }
static void my_init_edge(Agraph_t *g, Agobj_t *edge, void *arg)
{ int *sz = arg; agbindrec(edge,"level edge rec",sz[2],(!(0))); }
static Agcbdisc_t mydisc = { {my_init_graph,0,0}, {my_init_node,0,0}, {my_init_edge,0,0} };

int infosizes[] = {
    sizeof(Agraphinfo_t), 
    sizeof(Agnodeinfo_t),
    sizeof(Agedgeinfo_t)
};

void dot2_rank(graph_t * g, aspect_t* asp)
{
    int ssize;
    int ncc, maxiter = ((int)(~(unsigned)0 >> 1));
    char *s;
    graph_t *Xg;

    

    Last_node = NULL;
    Xg = agopen("level assignment constraints", Agstrictdirected, 0);
    agbindrec(Xg,"level graph rec",sizeof(Agraphinfo_t),(!(0)));
    agpushdisc(Xg,&mydisc,infosizes);

    edgelabel_ranks(g);

    if ((s = agget(g, "nslimit1")))
	maxiter = atof(s) * agnnodes(g);
    else
	maxiter = ((int)(~(unsigned)0 >> 1));

    compile_samerank(g, 0);
    compile_nodes(g, Xg);
    compile_edges(g, Xg);
    compile_clusters(g, Xg, 0, 0);
    break_cycles(Xg);
    ncc = connect_components(Xg);
    add_fast_edges (Xg);

    if (asp) {
	init_UF_size(Xg);
	initEdgeTypes(Xg);
    }

    if ((s = agget(g, "searchsize")))
	ssize = atoi(s);
    else
	ssize = -1;
    rank2(Xg, 1, maxiter, ssize);
/* fastgr(Xg); */
    readout_levels(g, Xg, ncc);

    

    agclose(Xg);
}
