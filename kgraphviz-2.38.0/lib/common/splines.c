#line 1 "graphviz-2.38.0\\lib\\common\\splines.c" 1
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


/* Functions related to creating a spline and attaching it to
 * an edge, starting from a list of control points.
 */

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








#line 21 "graphviz-2.38.0\\lib\\common\\splines.c" 2




    
	    
	    
	    
	    




    
    
    

    
    
    
    
    
	
	
    
    

    
    



/* arrow_clip:
 * Clip arrow to node boundary.
 * The real work is done elsewhere. Here we get the real edge,
 * check that the edge has arrowheads, and that an endpoint
 * isn't a merge point where several parts of an edge meet.
 * (e.g., with edge concentrators).
 */
static void
arrow_clip(edge_t * fe, node_t * hn,
	   pointf * ps, int *startp, int *endp,
	   bezier * spl, splineInfo * info)
{
    edge_t *e;
    int i, j, sflag, eflag;

    for (e = fe; (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig); e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig));

    if (info->ignoreSwap)
	j = 0;
    else
	j = info->swapEnds(e);
    arrow_flags(e, &sflag, &eflag);
    if (info->splineMerge(hn))
	eflag = 0;
    if (info->splineMerge(((((((Agobj_t*)(fe))->tag).objtype) == 3? (fe): ((fe)+1))->node)))
	sflag = 0;
    /* swap the two ends */
    if (j) {
	i = sflag;
	sflag = eflag;
	eflag = i;
    }
    if (info->isOrtho) {
	if (eflag || sflag)
	    arrowOrthoClip(e, ps, *startp, *endp, spl, sflag, eflag);
    }
    else {
	if (sflag)
	    *startp =
		arrowStartClip(e, ps, *startp, *endp, spl, sflag);
	if (eflag)
	    *endp =
		arrowEndClip(e, ps, *startp, *endp, spl, eflag);
    }
}

/* bezier_clip
 * Clip bezier to shape using binary search.
 * The details of the shape are passed in the inside_context;
 * The function providing the inside test is passed as a parameter.
 * left_inside specifies that sp[0] is inside the node, 
 * else sp[3] is taken as inside.
 * The points p are in node coordinates.
 */
void bezier_clip(inside_t * inside_context,
		 boolean(*inside) (inside_t * inside_context, pointf p),
		 pointf * sp, boolean left_inside)
{
    pointf seg[4], best[4], pt, opt, *left, *right;
    double low, high, t, *idir, *odir;
    boolean found;
    int i;

    if (left_inside) {
	left = NULL;
	right = seg;
	pt = sp[0];
	idir = &low;
	odir = &high;
    } else {
	left = seg;
	right = NULL;
	pt = sp[3];
	idir = &high;
	odir = &low;
    }
    found = 0;
    low = 0.0;
    high = 1.0;
    do {
	opt = pt;
	t = (high + low) / 2.0;
	pt = Bezier(sp, 3, t, left, right);
	if (inside(inside_context, pt)) {
	    *idir = t;
	} else {
	    for (i = 0; i < 4; i++)
		best[i] = seg[i];
	    found = (!(0));
	    *odir = t;
	}
    } while (((opt.x - pt.x) >= 0 ? (opt.x - pt.x) : -(opt.x - pt.x)) > .5 || ((opt.y - pt.y) >= 0 ? (opt.y - pt.y) : -(opt.y - pt.y)) > .5);
    if (found)
	for (i = 0; i < 4; i++)
	    sp[i] = best[i];
    else
	for (i = 0; i < 4; i++)
	    sp[i] = seg[i];
}

/* shape_clip0:
 * Clip Bezier to node shape using binary search.
 * left_inside specifies that curve[0] is inside the node, else
 * curve[3] is taken as inside.
 * Assumes ND_shape(n) and ND_shape(n)->fns->insidefn are non-NULL.
 * See note on shape_clip.
 */
static void
shape_clip0(inside_t * inside_context, node_t * n, pointf curve[4],
	    boolean left_inside)
{
    int i;
    double save_real_size;
    pointf c[4];

    save_real_size = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
    for (i = 0; i < 4; i++) {
	c[i].x = curve[i].x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	c[i].y = curve[i].y - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    }

    bezier_clip(inside_context, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->insidefn, c,
		left_inside);

    for (i = 0; i < 4; i++) {
	curve[i].x = c[i].x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	curve[i].y = c[i].y + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    }
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) = save_real_size;
}

/* shape_clip:
 * Clip Bezier to node shape
 * Uses curve[0] to determine which which side is inside the node. 
 * NOTE: This test is bad. It is possible for previous call to
 * shape_clip to produce a Bezier with curve[0] moved to the boundary
 * for which insidefn(curve[0]) is true. Thus, if the new Bezier is
 * fed back to shape_clip, it will again assume left_inside is true.
 * To be safe, shape_clip0 should guarantee that the computed boundary
 * point fails insidefn.
 * The edge e is used to provide a port box. If NULL, the spline is
 * clipped to the node shape.
 */
void shape_clip(node_t * n, pointf curve[4])
{
    double save_real_size;
    boolean left_inside;
    pointf c;
    inside_t inside_context;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape) == NULL || (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->insidefn == NULL)
	return;

    inside_context.s.n = n;
    inside_context.s.bp = NULL;
    save_real_size = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
    c.x = curve[0].x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
    c.y = curve[0].y - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    left_inside = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->insidefn(&inside_context, c);
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) = save_real_size;
    shape_clip0(&inside_context, n, curve, left_inside);
}

/* new_spline:
 * Create and attach a new bezier of size sz to the edge d
 */
bezier *new_spline(edge_t * e, int sz)
{
    bezier *rv;
    while ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0)
	e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig);
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl) == NULL)
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl) = (splines*)zmalloc(sizeof(splines));
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list = ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list? (bezier*)grealloc((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list,((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size + 1)*sizeof(bezier)):(bezier*)gmalloc(((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size + 1)*sizeof(bezier)));
    rv = &((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list[(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size++]);
    rv->list = (pointf*)zmalloc((sz)*sizeof(pointf));
    rv->size = sz;
    rv->sflag = rv->eflag = 0;
    rv->sp.x = rv->sp.y = rv->ep.x = rv->ep.y = 0;
    return rv;
}

/* clip_and_install:
 * Given a raw spline (pn control points in ps), representing
 * a path from edge agtail(fe) ending in node hn, clip the ends to
 * the node boundaries and attach the resulting spline to the
 * edge.
 */
void
clip_and_install(edge_t * fe, node_t * hn, pointf * ps, int pn,
		 splineInfo * info)
{
    pointf p2;
    bezier *newspl;
    node_t *tn;
    int start, end, i, clipTail, clipHead;
    graph_t *g;
    edge_t *orig;
    boxf *tbox, *hbox;
    inside_t inside_context;

    tn = ((((((Agobj_t*)(fe))->tag).objtype) == 3? (fe): ((fe)+1))->node);
    g = agraphof(tn);
    newspl = new_spline(fe, pn);

    for (orig = fe; (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->edge_type) != 0; orig = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_orig));

    /* may be a reversed flat edge */
    if (!info->ignoreSwap && ((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank) == (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)) && ((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->order))) {
	node_t *tmp;
	tmp = hn;
	hn = tn;
	tn = tmp;
    }
    if (tn == ((((((Agobj_t*)(orig))->tag).objtype) == 3? (orig): ((orig)+1))->node)) {
	clipTail = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip;
	clipHead = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip;
	tbox = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).bp;
	hbox = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).bp;
    }
    else { /* fe and orig are reversed */
	clipTail = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip;
	clipHead = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip;
	hbox = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).bp;
	tbox = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).bp;
    }

    /* spline may be interior to node */
    if(clipTail && (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->shape) && (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->shape)->fns->insidefn) {
	inside_context.s.n = tn;
	inside_context.s.bp = tbox;
	for (start = 0; start < pn - 4; start += 3) {
	    p2.x = ps[start + 3].x - (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).x;
	    p2.y = ps[start + 3].y - (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y;
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->shape)->fns->insidefn(&inside_context, p2) == 0)
		break;
	}
	shape_clip0(&inside_context, tn, &ps[start], (!(0)));
    } else
	start = 0;
    if(clipHead && (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->shape) && (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->shape)->fns->insidefn) {
	inside_context.s.n = hn;
	inside_context.s.bp = hbox;
	for (end = pn - 4; end > 0; end -= 3) {
	    p2.x = ps[end].x - (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).x;
	    p2.y = ps[end].y - (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).y;
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->shape)->fns->insidefn(&inside_context, p2) == 0)
		break;
	}
	shape_clip0(&inside_context, hn, &ps[end], 0);
    } else
	end = pn - 4;
    for (; start < pn - 4; start += 3) 
	if (! ((((((((ps[start])).x -((ps[start + 3])).x)) * ((((ps[start])).x -((ps[start + 3])).x))) + (((((ps[start])).y -((ps[start + 3])).y)) * ((((ps[start])).y -((ps[start + 3])).y))))) < ((.001) * (.001))))
	    break;
    for (; end > 0; end -= 3)
	if (! ((((((((ps[end])).x -((ps[end + 3])).x)) * ((((ps[end])).x -((ps[end + 3])).x))) + (((((ps[end])).y -((ps[end + 3])).y)) * ((((ps[end])).y -((ps[end + 3])).y))))) < ((.001) * (.001))))
	    break;
   arrow_clip(fe, hn, ps, &start, &end, newspl, info);
    for (i = start; i < end + 4; ) {
	pointf cp[4];
	newspl->list[i - start] = ps[i];
	cp[0] = ps[i];
	i++;
	if ( i >= end + 4)
	    break;
	newspl->list[i - start] = ps[i];
	cp[1] = ps[i];
	i++;
	newspl->list[i - start] = ps[i];
	cp[2] = ps[i];
	i++;
	cp[3] = ps[i];
	update_bb_bz(&(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb), cp);
    }
    newspl->size = end - start + 4;
}

static double 
conc_slope(node_t* n)
{
    double s_in, s_out, m_in, m_out;
    int cnt_in, cnt_out;
    pointf p;
    edge_t *e;

    s_in = s_out = 0.0;
    for (cnt_in = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[cnt_in]); cnt_in++)
	s_in += (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->coord).x;
    for (cnt_out = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[cnt_out]); cnt_out++)
	s_out += (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->coord).x;
    p.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (s_in / cnt_in);
    p.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[0]))->tag).objtype) == 3?((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[0]):(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[0])+1))->node)))->data))->coord).y;
    m_in = atan2(p.y, p.x);
    p.x = (s_out / cnt_out) - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
    p.y = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0]))->tag).objtype) == 2?((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0]):(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0])-1))->node)))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    m_out = atan2(p.y, p.x);
    return ((m_in + m_out) / 2.0);
}

void add_box(path * P, boxf b)
{
    if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	P->boxes[P->nbox++] = b;
}

/* beginpath:
 * Set up boxes near the tail node.
 * For regular nodes, the result should be a list of contiguous rectangles 
 * such that the last one has the smallest LL.y and its LL.y is above
 * the bottom of the rank (rank.ht1).
 * 
 * For flat edges, we assume endp->sidemask has been set. For regular
 * edges, we set this, but it doesn't appear to be needed any more.
 * 
 * In many cases, we tweak the x or y coordinate of P->start.p by 1.
 * This is because of a problem in the path routing code. If the starting
 * point actually lies on the polygon, in some cases, the router gets
 * confused and routes the path outside the polygon. So, the offset ensures
 * the starting point is in the polygon.
 *
 * FIX: Creating the initial boxes only really works for rankdir=TB and
 * rankdir=LR. For the others, we rely on compassPort flipping the side
 * and then assume that the node shape has top-bottom symmetry. Since we
 * at present only put compass points on the bounding box, this works.
 * If we attempt to implement compass points on actual node perimeters,
 * something major will probably be necessary. Doing the coordinate
 * flip (postprocess) before spline routing will be too disruptive. The
 * correct solution is probably to have beginpath/endpath create the
 * boxes assuming an inverted node. Note that compassPort already does
 * some flipping. Even better would be to allow the *_path function
 * to provide a polygon.
 *
 * The extra space provided by FUDGE-2 prevents the edge from getting
 * too close the side of the node.
 *
 */



void
beginpath(path * P, edge_t * e, int et, pathend_t * endp, boolean merge)
{
    int side, mask;
    node_t *n;
    int (*pboxfn) (node_t*, port*, int, boxf*, int*);

    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).dyna)
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port) = resolvePort(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port));
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape))
	pboxfn = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->pboxfn;
    else
	pboxfn = NULL;
    P->start.p = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
    if (merge) {
	/*P->start.theta = - M_PI / 2; */
	P->start.theta = conc_slope(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node));
	P->start.constrained = (!(0));
    } else {
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).constrained) {
	    P->start.theta = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).theta;
	    P->start.constrained = (!(0));
	} else
	    P->start.constrained = 0;
    }
    P->nbox = 0;
    P->data = (void *) e;
    endp->np = P->start.p;
    if ((et == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0) && ((side = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side))) {
	edge_t* orig;
	boxf b0, b = endp->nb;
	if (side & (1<<2)) {
	    endp->sidemask = (1<<2);
	    if (P->start.p.x < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x) { /* go left */
		b0.LL.x = b.LL.x - 1;
		/* b0.LL.y = ND_coord(n).y + HT2(n); */
		b0.LL.y = P->start.p.y;
		b0.UR.x = b.UR.x;
		b0.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2) + (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) - (2-2);
		b.UR.y = b0.LL.y;
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.x -= 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
	    }
	    else {
		b0.LL.x = b.LL.x;
		b0.LL.y = P->start.p.y;
		/* b0.LL.y = ND_coord(n).y + HT2(n); */
		b0.UR.x = b.UR.x+1;
		b0.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2) + (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.LL.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) + (2-2);
		b.UR.y = b0.LL.y;
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.x += 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
	    } 
	    P->start.p.y += 1;
	    endp->boxn = 2;
	}
	else if (side & (1<<0)) {
	    endp->sidemask = (1<<0);
	    b.UR.y = ((b.UR.y)>(P->start.p.y)?(b.UR.y):(P->start.p.y));
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.y -= 1;
	}
	else if (side & (1<<3)) {
	    endp->sidemask = (1<<3);
	    b.UR.x = P->start.p.x;
	    b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
	    b.UR.y = P->start.p.y;
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.x -= 1;
	}
	else {
	    endp->sidemask = (1<<1);
	    b.LL.x = P->start.p.x;
	    b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
	    b.UR.y = P->start.p.y;
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.x += 1;
	}
	for (orig = e; (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->edge_type) != 0; orig = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_orig));
	if (n == ((((((Agobj_t*)(orig))->tag).objtype) == 3? (orig): ((orig)+1))->node))
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip = 0;
	else
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip = 0;
	return;
    }
    if ((et == 2) && ((side = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side))) {
	boxf b0, b = endp->nb;
	edge_t* orig;
	if (side & (1<<2)) {
	    b.LL.y = ((b.LL.y)<(P->start.p.y)?(b.LL.y):(P->start.p.y));
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.y += 1;
	}
	else if (side & (1<<0)) {
	    if (endp->sidemask == (1<<2)) {
		b0.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b0.UR.x = b.UR.x+1;
		b0.LL.x = P->start.p.x;
		b0.LL.y = b0.UR.y - (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.LL.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) + (2-2);
		b.LL.y = b0.UR.y;
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.x += 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
		endp->boxn = 2;
	    }
	    else {
		b.UR.y = ((b.UR.y)>(P->start.p.y)?(b.UR.y):(P->start.p.y));
		endp->boxes[0] = b;
		endp->boxn = 1;
	    }
	    P->start.p.y -= 1;
	}
	else if (side & (1<<3)) {
	    b.UR.x = P->start.p.x+1;
	    if (endp->sidemask == (1<<2)) {
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.y = P->start.p.y-1;
	    }
	    else {
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.y = P->start.p.y+1;
	    }
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.x -= 1;
	}
	else {
	    b.LL.x = P->start.p.x;
	    if (endp->sidemask == (1<<2)) {
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.y = P->start.p.y;
	    }
	    else {
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.y = P->start.p.y+1;
	    }
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->start.p.x += 1;
	}
	for (orig = e; (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->edge_type) != 0; orig = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_orig));
	if (n == ((((((Agobj_t*)(orig))->tag).objtype) == 3? (orig): ((orig)+1))->node))
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip = 0;
	else
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip = 0;
	endp->sidemask = side;
	return;
    }

    if (et == 1) side = (1<<0);
    else side = endp->sidemask;  /* for flat edges */
    if (pboxfn
	&& (mask = (*pboxfn) (n, &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port), side, &endp->boxes[0], &endp->boxn)))
	endp->sidemask = mask;
    else {
	endp->boxes[0] = endp->nb;
	endp->boxn = 1;

	switch (et) {
	case 8:
	/* moving the box UR.y by + 1 avoids colinearity between
	   port point and box that confuses Proutespline().  it's
	   a bug in Proutespline() but this is the easiest fix. */
	    assert(0);  /* at present, we don't use beginpath for selfedges */
	    endp->boxes[0].UR.y = P->start.p.y - 1;
	    endp->sidemask = (1<<0);
	    break;
	case 2:
	    if (endp->sidemask == (1<<2))
		endp->boxes[0].LL.y = P->start.p.y;
	    else
		endp->boxes[0].UR.y = P->start.p.y;
	    break;
	case 1:
	    endp->boxes[0].UR.y = P->start.p.y;
	    endp->sidemask = (1<<0);
	    P->start.p.y -= 1;
	    break;
	}    
    }    
}

void endpath(path * P, edge_t * e, int et, pathend_t * endp, boolean merge)
{
    int side, mask;
    node_t *n;
    int (*pboxfn) (node_t* n, port*, int, boxf*, int*);

    n = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).dyna) 
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port) = resolvePort(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port));
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape))
	pboxfn = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->pboxfn;
    else
	pboxfn = NULL;
    P->end.p = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);
    if (merge) {
	/*P->end.theta = M_PI / 2; */
	P->end.theta = conc_slope(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)) + 3.14159265358979323846;
	assert(P->end.theta < 2 * 3.14159265358979323846);
	P->end.constrained = (!(0));
    } else {
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).constrained) {
	    P->end.theta = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).theta;
	    P->end.constrained = (!(0));
	} else
	    P->end.constrained = 0;
    }
    endp->np = P->end.p;
    if ((et == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0) && ((side = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side))) {
	edge_t* orig;
	boxf b0, b = endp->nb;
	if (side & (1<<2)) {
	    endp->sidemask = (1<<2);
	    b.LL.y = ((b.LL.y)<(P->end.p.y)?(b.LL.y):(P->end.p.y));
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.y += 1;
	}
	else if (side & (1<<0)) {
	    endp->sidemask = (1<<0);
	    if (P->end.p.x < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x) { /* go left */
		b0.LL.x = b.LL.x-1;
		/* b0.UR.y = ND_coord(n).y - HT2(n); */
		b0.UR.y = P->end.p.y;
		b0.UR.x = b.UR.x;
		b0.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2) - (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) - (2-2);
		b.LL.y = b0.UR.y;
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.x -= 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
	    }
	    else {
		b0.LL.x = b.LL.x;
		b0.UR.y = P->end.p.y;
		/* b0.UR.y = ND_coord(n).y - HT2(n); */
		b0.UR.x = b.UR.x+1;
		b0.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2) - (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.LL.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) + (2-2);
		b.LL.y = b0.UR.y;
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.x += 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
	    } 
	    endp->boxn = 2;
	    P->end.p.y -= 1;
	}
	else if (side & (1<<3)) {
	    endp->sidemask = (1<<3);
	    b.UR.x = P->end.p.x;
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
	    b.LL.y = P->end.p.y;
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.x -= 1;
	}
	else {
	    endp->sidemask = (1<<1);
	    b.LL.x = P->end.p.x;
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
	    b.LL.y = P->end.p.y;
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.x += 1;
	}
	for (orig = e; (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->edge_type) != 0; orig = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_orig));
	if (n == ((((((Agobj_t*)(orig))->tag).objtype) == 2? (orig): ((orig)-1))->node))
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip = 0;
	else
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip = 0;
	endp->sidemask = side;
	return;
    }

    if ((et == 2) && ((side = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side))) {
	boxf b0, b = endp->nb;
	edge_t* orig;
	if (side & (1<<2)) {
	    b.LL.y = ((b.LL.y)<(P->end.p.y)?(b.LL.y):(P->end.p.y));
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.y += 1;
	}
	else if (side & (1<<0)) {
	    if (endp->sidemask == (1<<2)) {
		b0.LL.x = b.LL.x-1;
		b0.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b0.UR.x = P->end.p.x;
		b0.LL.y = b0.UR.y - (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->ranksep)/2;
		b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) - 2;
		b.LL.y = b0.UR.y;
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.x -= 1;
		endp->boxes[0] = b0;
		endp->boxes[1] = b;
		endp->boxn = 2;
	    }
	    else {
		b.UR.y = ((b.UR.y)>(P->start.p.y)?(b.UR.y):(P->start.p.y));
		endp->boxes[0] = b;
		endp->boxn = 1;
	    }
	    P->end.p.y -= 1;
	}
	else if (side & (1<<3)) {
	    b.UR.x = P->end.p.x+1;
	    if (endp->sidemask == (1<<2)) {
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.y = P->end.p.y-1;
	    }
	    else {
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.y = P->end.p.y+1;
	    }
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.x -= 1;
	}
	else {
	    b.LL.x = P->end.p.x-1;
	    if (endp->sidemask == (1<<2)) {
		b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.LL.y = P->end.p.y-1;
	    }
	    else {
		b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2);
		b.UR.y = P->end.p.y;
	    }
	    endp->boxes[0] = b;
	    endp->boxn = 1;
	    P->end.p.x += 1;
	}
	for (orig = e; (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->edge_type) != 0; orig = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_orig));
	if (n == ((((((Agobj_t*)(orig))->tag).objtype) == 2? (orig): ((orig)-1))->node))
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->head_port).clip = 0;
	else
	    (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->tail_port).clip = 0;
	endp->sidemask = side;
	return;
    }

    if (et == 1) side = (1<<2);
    else side = endp->sidemask;  /* for flat edges */
    if (pboxfn
	&& (mask = (*pboxfn) (n, &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port), side, &endp->boxes[0], &endp->boxn)))
	endp->sidemask = mask;
    else {
	endp->boxes[0] = endp->nb;
	endp->boxn = 1;

	switch (et) {
	case 8:
	    /* offset of -1 is symmetric w.r.t. beginpath() 
	     * FIXME: is any of this right?  what if self-edge 
	     * doesn't connect from BOTTOM to TOP??? */
	    assert(0);  /* at present, we don't use endpath for selfedges */
	    endp->boxes[0].LL.y = P->end.p.y + 1;
	    endp->sidemask = (1<<2);
	    break;
	case 2:
	    if (endp->sidemask == (1<<2))
		endp->boxes[0].LL.y = P->end.p.y;
	    else
		endp->boxes[0].UR.y = P->end.p.y;
	    break;
	case 1:
	    endp->boxes[0].LL.y = P->end.p.y;
	    endp->sidemask = (1<<2);
	    P->end.p.y += 1;
	    break;
	}
    }
}


static int convert_sides_to_points(int tail_side, int head_side)
{
int vertices[] = {12,4,6,2,3,1,9,8};  //the cumulative side value of each node point
int i, tail_i, head_i;
int pair_a[8][8] = {	    //array of possible node point pairs
{11,12,13,14,15,16,17,18},
{21,22,23,24,25,26,27,28},
{31,32,33,34,35,36,37,38},
{41,42,43,44,45,46,47,48},
{51,52,53,54,55,56,57,58},
{61,62,63,64,65,66,67,68},
{71,72,73,74,75,76,77,78},
{81,82,83,84,85,86,87,88}
};

 tail_i = head_i = -1;
	for(i=0;i< 8; i++){
		if(head_side == vertices[i]){
			head_i = i;
			break;
		}
	}
	for(i=0;i< 8; i++){
		if(tail_side == vertices[i]){
			tail_i = i;
			break;
		}
	}
	
if( tail_i < 0 || head_i < 0)
  return 0;
else
  return pair_a[tail_i][head_i];
}


static void selfBottom (edge_t* edges[], int ind, int cnt,
	double sizex, double stepy, splineInfo* sinfo) 
{
    pointf tp, hp, np;
    node_t *n;
    edge_t *e;
    int i, sgn, point_pair;
    double hy, ty, stepx, dx, dy, width, height; 
    pointf points[1000];
    int pointn;

    e = edges[ind];
    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);

    stepx = (sizex / 2.) / cnt;
    stepx = ((stepx)>(2.)?(stepx):(2.));
    pointn = 0;
    np = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
    tp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
    tp.x += np.x;
    tp.y += np.y;
    hp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    hp.x += np.x;
    hp.y += np.y;
    if (tp.x >= hp.x) sgn = 1;
    else sgn = -1;
    dy = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2., dx = 0.;
    // certain adjustments are required for some point_pairs in order to improve the 
    // display of the edge path between them
    point_pair = convert_sides_to_points((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side,(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side);
    switch(point_pair){
      case 67:  sgn = -sgn;
		break;
      default:
		break;
    }
    ty = ((dy)<(3*(tp.y + dy - np.y))?(dy):(3*(tp.y + dy - np.y)));
    hy = ((dy)<(3*(hp.y + dy - np.y))?(dy):(3*(hp.y + dy - np.y)));
    for (i = 0; i < cnt; i++) {
        e = edges[ind++];
        dy += stepy, ty += stepy, hy += stepy, dx += sgn*stepx;
        pointn = 0;
        points[pointn++] = tp;
        points[pointn++] = pointfof(tp.x + dx, tp.y - ty / 3);
        points[pointn++] = pointfof(tp.x + dx, np.y - dy);
        points[pointn++] = pointfof((tp.x+hp.x)/2, np.y - dy);
        points[pointn++] = pointfof(hp.x - dx, np.y - dy);
        points[pointn++] = pointfof(hp.x - dx, hp.y - hy / 3);
        points[pointn++] = hp;
        if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
	if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node))))->data))->rankdir & 0x3) & 1)) {
    	    width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
    	    height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
    	} else {
    	    width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
    	    height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
    	}
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - dy - height / 2.0;
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
    	if (height > stepy)
    	    dy += height - stepy;
        }
        clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, sinfo);

        
	    

    }
}


static void
selfTop (edge_t* edges[], int ind, int cnt, double sizex, double stepy,
           splineInfo* sinfo) 
{
    int i, sgn, point_pair;
    double hy, ty,  stepx, dx, dy, width, height; 
    pointf tp, hp, np;
    node_t *n;
    edge_t *e;
    pointf points[1000];
    int pointn;

    e = edges[ind];
    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);

    stepx = (sizex / 2.) / cnt;
    stepx = ((stepx)>(2.)?(stepx):(2.));
    pointn = 0;
    np = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
    tp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
    tp.x += np.x;
    tp.y += np.y;
    hp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    hp.x += np.x;
    hp.y += np.y;
    if (tp.x >= hp.x) sgn = 1;
    else sgn = -1;
    dy = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2., dx = 0.;
    // certain adjustments are required for some point_pairs in order to improve the 
    // display of the edge path between them
    point_pair = convert_sides_to_points((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side,(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side);
    switch(point_pair){
	case 15:	
		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) - (hp.x-np.x) + stepx);
		break;

	case 38:
		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-hp.x) + stepx);
		break;
	case 41:
		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)-(tp.x-np.x) + stepx);
		break;
	case 48:
		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)-(tp.x-np.x) + stepx);
		break;
	
	case 14:
	case 37:
	case 47:
	case 51:
	case 57:
	case 58:
		dx = sgn*(((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-tp.x)) + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)-(hp.x-np.x)))/3.));
		break;
	case 73:
 		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-tp.x) + stepx);
		break;
	case 83:
		dx = sgn*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-tp.x));
		break;
	case 84:
		dx = sgn*(((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-tp.x)) + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)-(hp.x-np.x)))/2.) + stepx);
		break;
	case 74:
	case 75:
	case 85:
		dx = sgn*(((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-(np.x-tp.x)) + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)-(hp.x-np.x)))/2.) + 2*stepx);
		break;
	default:
		break;
    }
    ty = ((dy)<(3*(np.y + dy - tp.y))?(dy):(3*(np.y + dy - tp.y)));
    hy = ((dy)<(3*(np.y + dy - hp.y))?(dy):(3*(np.y + dy - hp.y)));
    for (i = 0; i < cnt; i++) {
        e = edges[ind++];
        dy += stepy, ty += stepy, hy += stepy, dx += sgn*stepx;
        pointn = 0;
        points[pointn++] = tp;
        points[pointn++] = pointfof(tp.x + dx, tp.y + ty / 3);
        points[pointn++] = pointfof(tp.x + dx, np.y + dy);
        points[pointn++] = pointfof((tp.x+hp.x)/2, np.y + dy);
        points[pointn++] = pointfof(hp.x - dx, np.y + dy);
        points[pointn++] = pointfof(hp.x - dx, hp.y + hy / 3);
        points[pointn++] = hp;
        if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
	    if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node))))->data))->rankdir & 0x3) & 1)) {
		width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
		height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
	    } else {
		width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
		height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
	    }
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + dy + height / 2.0;
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
	    if (height > stepy)
		dy += height - stepy;
        }
       clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, sinfo);

        
	    

    }
    return;
}

static void
selfRight (edge_t* edges[], int ind, int cnt, double stepx, double sizey,
           splineInfo* sinfo) 
{
    int i, sgn, point_pair;
    double hx, tx, stepy, dx, dy, width, height; 
    pointf tp, hp, np;
    node_t *n;
    edge_t *e;
    pointf points[1000];
    int pointn;

    e = edges[ind];
    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);

    stepy = (sizey / 2.) / cnt;
    stepy = ((stepy)>(2.)?(stepy):(2.));
    pointn = 0;
    np = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
    tp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
    tp.x += np.x;
    tp.y += np.y;
    hp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    hp.x += np.x;
    hp.y += np.y;
    if (tp.y >= hp.y) sgn = 1;
    else sgn = -1;
    dx = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw), dy = 0;
    // certain adjustments are required for some point_pairs in order to improve the 
    // display of the edge path between them
    point_pair = convert_sides_to_points((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side,(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side);
    switch(point_pair){
      case 32: 
      case 65:	if(tp.y == hp.y)
		  sgn = -sgn;
		break;
      default:
		break;
    }
    tx = ((dx)<(3*(np.x + dx - tp.x))?(dx):(3*(np.x + dx - tp.x)));
    hx = ((dx)<(3*(np.x + dx - hp.x))?(dx):(3*(np.x + dx - hp.x)));
    for (i = 0; i < cnt; i++) {
        e = edges[ind++];
        dx += stepx, tx += stepx, hx += stepx, dy += sgn*stepy;
        pointn = 0;
        points[pointn++] = tp;
        points[pointn++] = pointfof(tp.x + tx / 3, tp.y + dy);
        points[pointn++] = pointfof(np.x + dx, tp.y + dy);
        points[pointn++] = pointfof(np.x + dx, (tp.y+hp.y)/2);
        points[pointn++] = pointfof(np.x + dx, hp.y - dy);
        points[pointn++] = pointfof(hp.x + hx / 3, hp.y - dy);
        points[pointn++] = hp;
        if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
	    if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node))))->data))->rankdir & 0x3) & 1)) {
		width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
		height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
	    } else {
		width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
		height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
	    }
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + dx + width / 2.0;
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
	    if (width > stepx)
		dx += width - stepx;
        }
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, sinfo);

        
	    

    }
    return;
}

static void
selfLeft (edge_t* edges[], int ind, int cnt, double stepx, double sizey,
          splineInfo* sinfo) 
{
    int i, sgn,point_pair;
    double hx, tx, stepy, dx, dy, width, height; 
    pointf tp, hp, np;
    node_t *n;
    edge_t *e;
    pointf points[1000];
    int pointn;

    e = edges[ind];
    n = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);

    stepy = (sizey / 2.) / cnt;
    stepy = ((stepy)>(2.)?(stepy):(2.));
    pointn = 0;
    np = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
    tp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
    tp.x += np.x;
    tp.y += np.y;
    hp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    hp.x += np.x;
    hp.y += np.y;
    
    
    if (tp.y >= hp.y) sgn = 1;
    else sgn = -1;
    dx = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw), dy = 0.;
    // certain adjustments are required for some point_pairs in order to improve the 
    // display of the edge path between them
    point_pair = convert_sides_to_points((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side,(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side);
    switch(point_pair){
      case 12:
      case 67:
		if(tp.y == hp.y)
		  sgn = -sgn;
		break;
      default:
		break;
    }
    tx = ((dx)<(3*(tp.x + dx - np.x))?(dx):(3*(tp.x + dx - np.x)));
    hx = ((dx)<(3*(hp.x + dx - np.x))?(dx):(3*(hp.x + dx - np.x)));
    for (i = 0; i < cnt; i++) {
        e = edges[ind++];
        dx += stepx, tx += stepx, hx += stepx, dy += sgn*stepy;
        pointn = 0;
        points[pointn++] = tp;
        points[pointn++] = pointfof(tp.x - tx / 3, tp.y + dy);
        points[pointn++] = pointfof(np.x - dx, tp.y + dy);
        points[pointn++] = pointfof(np.x - dx, (tp.y+hp.y)/2);
        points[pointn++] = pointfof(np.x - dx, hp.y - dy);
        points[pointn++] = pointfof(hp.x - hx / 3, hp.y - dy);
      
        points[pointn++] = hp;
        if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
    	if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node))))->data))->rankdir & 0x3) & 1)) {
    	    width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
    	    height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
    	} else {
    	    width = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x;
    	    height = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
    	}
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - dx - width / 2.0;
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
    	if (width > stepx)
    	    dx += width - stepx;
        }

        clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, sinfo);

        
	    

    }
}

/* selfRightSpace:
 * Assume e is self-edge.
 * Return extra space necessary on the right for this edge.
 * If the edge does not go on the right, return 0.
 * NOTE: the actual space is determined dynamically by GD_nodesep,
 * so using the constant SELF_EDGE_SIZE is going to be wrong.
 * Fortunately, the default nodesep is the same as SELF_EDGE_SIZE.
 */
int
selfRightSpace (edge_t* e)
{
    int sw;
    double label_width;
    textlabel_t* l = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label);

    if (((!(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).defined) && (!(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).defined)) ||
        (!((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<3)) && 
         !((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side & (1<<3)) &&
          (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side != (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side) || 
          (!((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & ((1<<2)|(1<<0))))))) {
	sw = 18;
	if (l) {
	    label_width = ((((Agraphinfo_t*)(((Agobj_t*)(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node))))->data))->rankdir & 0x3) & 1) ? l->dimen.y : l->dimen.x;
	    sw += label_width;
	}
    }
    else sw = 0;
    return sw;
}

/* makeSelfEdge:
 * The routing is biased towards the right side because this is what
 * dot supports, and leaves room for.
 * FIX: With this bias, labels tend to be placed on top of each other.
 * Perhaps for self-edges, the label should be centered.
 */
void
makeSelfEdge(path * P, edge_t * edges[], int ind, int cnt, double sizex,
	     double sizey, splineInfo * sinfo)
{
    edge_t *e;

    e = edges[ind];

    /* self edge without ports or
     * self edge with all ports inside, on the right, or at most 1 on top 
     * and at most 1 on bottom 
     */
    
    if (((!(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).defined) && (!(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).defined)) ||
        (!((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<3)) && 
         !((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side & (1<<3)) &&
          (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side != (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side) || 
          (!((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & ((1<<2)|(1<<0))))))) {
	selfRight(edges, ind, cnt, sizex, sizey, sinfo);
    }

    /* self edge with port on left side */
    else if (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<3)) || ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side & (1<<3))) {

	/* handle L-R specially */
	if (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<1)) || ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side & (1<<1))) {
	    selfTop(edges, ind, cnt, sizex, sizey, sinfo);
	}
	else {
	    selfLeft(edges, ind, cnt, sizex, sizey, sinfo);
	}
    }

    /* self edge with both ports on top side */
    else if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<2)) {
	selfTop(edges, ind, cnt, sizex, sizey, sinfo);
    }
    else if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side & (1<<0)) {
	selfBottom(edges, ind, cnt, sizex, sizey, sinfo);
    }

    else assert(0);
}

/* makePortLabels:
 * Add head and tail labels if necessary and update bounding box.
 */
void makePortLabels(edge_t * e)
{
    /* Only use this if labelangle or labeldistance is set for the edge;
     * otherwise, handle with external labels.
     */
    if (!E_labelangle && !E_labeldistance) return;

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label) && !(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->set) {
	if (place_portlabel(e, (!(0))))
	    updateBB(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label));
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label) && !(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->set) {
	if (place_portlabel(e, 0))
	    updateBB(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label));
    }
}

/* endPoints:
 * Extract the actual end points of the spline, where
 * they touch the node.
 */
static void endPoints(splines * spl, pointf * p, pointf * q)
{
    bezier bz;

    bz = spl->list[0];
    if (bz.sflag) {
	*p = bz.sp;
    }
    else {
	*p = bz.list[0];
    }
    bz = spl->list[spl->size - 1];
    if (bz.eflag) {
	*q = bz.ep;
    }
    else {
	*q = bz.list[bz.size - 1];
    }
}

/* polylineMidpoint;
 * Find midpoint of polyline.
 * pp and pq are set to the endpoints of the line segment containing it.
 */
static pointf
polylineMidpoint (splines* spl, pointf* pp, pointf* pq)
{
    bezier bz;
    int i, j, k;
    double d, dist = 0;
    pointf pf, qf, mf;

    for (i = 0; i < spl->size; i++) {
	bz = spl->list[i];
	for (j = 0, k=3; k < bz.size; j+=3,k+=3) {
	    pf = bz.list[j];
	    qf = bz.list[k];
	    dist += (sqrt((((((((pf)).x -((qf)).x)) * ((((pf)).x -((qf)).x))) + (((((pf)).y -((qf)).y)) * ((((pf)).y -((qf)).y)))))));
	}
    }
    dist /= 2;
    for (i = 0; i < spl->size; i++) {
	bz = spl->list[i];
	for (j = 0, k=3; k < bz.size; j+=3,k+=3) {
	    pf = bz.list[j];
	    qf = bz.list[k];
	    d = (sqrt((((((((pf)).x -((qf)).x)) * ((((pf)).x -((qf)).x))) + (((((pf)).y -((qf)).y)) * ((((pf)).y -((qf)).y)))))));
	    if (d >= dist) {
		*pp = pf;
		*pq = qf;
		mf.x = ((qf.x*dist) + (pf.x*(d-dist)))/d; 
		mf.y = ((qf.y*dist) + (pf.y*(d-dist)))/d; 
		return mf;
	    }
	    else
		dist -= d;
	}
    }
    assert (0);   /* should never get here */
    return mf;
}

pointf
edgeMidpoint (graph_t* g, edge_t * e)
{
    int et = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->flags) & (7 << 1));
    pointf d, spf, p, q;

    endPoints((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl), &p, &q);
    if (((((((((p)).x -((q)).x)) * ((((p)).x -((q)).x))) + (((((p)).y -((q)).y)) * ((((p)).y -((q)).y))))) < ((.001) * (.001)))) { /* degenerate spline */
	spf = p;
    }
    else if ((et == (5 << 1)) || (et == (2 << 1))) {
	d.x = (q.x + p.x) / 2.;
	d.y = (p.y + q.y) / 2.;
	spf = dotneato_closest((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl), d);
    }
    else {   /* ET_PLINE, ET_ORTHO or ET_LINE */
	spf = polylineMidpoint ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl), &p, &q);
    }

    return spf;
}




/* addEdgeLabels:
 * rp and rq are the port points of the tail and head node.
 * Adds label, headlabel and taillabel.
 * The use of 2 and 4 in computing ld.x and ld.y are fudge factors, to
 * introduce a bit of spacing.
 * Updates bounding box.
 * We try to use the actual endpoints of the spline, as they may differ
 * significantly from rp and rq, but if the spline is degenerate (e.g.,
 * the nodes overlap), we use rp and rq.
 */
void addEdgeLabels(graph_t* g, edge_t * e, pointf rp, pointf rq)
{

    
    
    
    
    
    
    
    

    
	
        
	    
	    
	    
	
	
	    
	    
	    
	
	
	    
	
	
	
	
	
	
	    
	    
	    
		
		    
	    
	    
		
		
		    
	    
	    
	    
	    
	
	
	    
	    
	

	
	
	
	
    

    makePortLabels(e);
}



/* vladimir */
/* place_portlabel:
 * place the {head,tail}label (depending on HEAD_P) of edge E
 * N.B. Assume edges are normalized, so tail is at spl->list[0].list[0]
 * and head is at spl->list[spl->size-l].list[bez->size-1]
 * Return 1 on success
 */
int place_portlabel(edge_t * e, boolean head_p)
{
    textlabel_t *l;
    splines *spl;
    bezier *bez;
    double dist, angle;
    pointf c[4], pe, pf;
    int i;
    char* la;
    char* ld;

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 6)
	return 0;
    /* add label here only if labelangle or labeldistance is defined; else, use external label */
    if ((!E_labelangle || (*(la = agxget(e,E_labelangle)) == '\0')) &&
	(!E_labeldistance || (*(ld = agxget(e,E_labeldistance)) == '\0'))) {
	return 0;
    }

    l = head_p ? (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label) : (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label);
    if ((spl = getsplinepoints(e)) == NULL) return 0;
    if (!head_p) {
	bez = &spl->list[0];
	if (bez->sflag) {
	    pe = bez->sp;
	    pf = bez->list[0];
	} else {
	    pe = bez->list[0];
	    for (i = 0; i < 4; i++)
		c[i] = bez->list[i];
	    pf = Bezier(c, 3, 0.1, NULL, NULL);
	}
    } else {
	bez = &spl->list[spl->size - 1];
	if (bez->eflag) {
	    pe = bez->ep;
	    pf = bez->list[bez->size - 1];
	} else {
	    pe = bez->list[bez->size - 1];
	    for (i = 0; i < 4; i++)
		c[i] = bez->list[bez->size - 4 + i];
	    pf = Bezier(c, 3, 0.9, NULL, NULL);
	}
    }
    angle = atan2(pf.y - pe.y, pf.x - pe.x) +
	((late_double(e, E_labelangle, -25, -180.0))/180.0 * 3.14159265358979323846);
    dist = 10 * late_double(e, E_labeldistance, 1.0, 0.0);
    l->pos.x = pe.x + dist * cos(angle);
    l->pos.y = pe.y + dist * sin(angle);
    l->set = (!(0));
    return 1;
}

splines *getsplinepoints(edge_t * e)
{
    edge_t *le;
    splines *sp;

    for (le = e; !(sp = (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->spl)) && (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->edge_type) != 0;
	 le = (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_orig));
    if (sp == NULL) 
	agerr (AGERR, "getsplinepoints: no spline points available for edge (%s,%s)\n",
	    agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
    return sp;
}

