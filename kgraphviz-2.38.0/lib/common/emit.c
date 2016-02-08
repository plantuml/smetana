#line 1 "graphviz-2.38.0\\lib\\common\\emit.c" 1
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
 *  graphics code generator
 */


#line 1 "graphviz-2.38.0\\lib\\common\\emit.c" 1


#line 1 "graphviz-2.38.0\\lib\\common\\emit.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\emit.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\emit.c" 1
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




























































#line 28 "graphviz-2.38.0\\lib\\common\\types.h" 2
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












#line 29 "graphviz-2.38.0\\lib\\common\\types.h" 2
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




#line 30 "graphviz-2.38.0\\lib\\common\\types.h" 2
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





#line 31 "graphviz-2.38.0\\lib\\common\\types.h" 2
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


































#line 32 "graphviz-2.38.0\\lib\\common\\types.h" 2





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





#line 182 "graphviz-2.38.0\\lib\\common\\types.h" 2

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

    b.LL.x = MIN(b0.LL.x, b1.LL.x);
    b.LL.y = MIN(b0.LL.y, b1.LL.y);
    b.UR.x = MAX(b0.UR.x, b1.UR.x);
    b.UR.y = MAX(b0.UR.y, b1.UR.y);

    return b;
}

static inline boxf boxf_bb(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = MIN(b0.LL.x, b1.LL.x);
    b.LL.y = MIN(b0.LL.y, b1.LL.y);
    b.UR.x = MAX(b0.UR.x, b1.UR.x);
    b.UR.y = MAX(b0.UR.y, b1.UR.y);

    return b;
}

static inline box box_intersect(box b0, box b1)
{
    box b;

    b.LL.x = MAX(b0.LL.x, b1.LL.x);
    b.LL.y = MAX(b0.LL.y, b1.LL.y);
    b.UR.x = MIN(b0.UR.x, b1.UR.x);
    b.UR.y = MIN(b0.UR.y, b1.UR.y);

    return b;
}

static inline boxf boxf_intersect(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = MAX(b0.LL.x, b1.LL.x);
    b.LL.y = MAX(b0.LL.y, b1.LL.y);
    b.UR.x = MIN(b0.UR.x, b1.UR.x);
    b.UR.y = MIN(b0.UR.y, b1.UR.y);

    return b;
}

static inline int box_overlap(box b0, box b1)
{
    return OVERLAP(b0, b1);
}

static inline int boxf_overlap(boxf b0, boxf b1)
{
    return OVERLAP(b0, b1);
}

static inline int box_contains(box b0, box b1)
{
    return CONTAINS(b0, b1);
}

static inline int boxf_contains(boxf b0, boxf b1)
{
    return CONTAINS(b0, b1);
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




#line 1 "graphviz-2.38.0\\lib\\gvc\\gvc.h" 1
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


































    
    
    
    
    
    



    

    
	
	    
	    
	
	
	    
	    
	
    

    
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
    

    
	
	
	
	
	
    

    
	
	
	
	
    

    
	
	
	
	
    

    
	
	
	
    

    
	
	
	
	
	
		      
		      
	
	
	    
		
		
	    
	    
	
	
	
	
    

    
	
	
	
	
	
	
	
	
    

    
	
	
	
	
    









    
	
	
	

    

    
	
	
	 
	 
	
	
    

    

    
	
	
	
	
    



    
	
    

    
	
	
    

    
	
	
	
	
	
	
	
	
	
	
    

    
	    

    
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
    

    
	
	
    

    
	
	
    















    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	
	
	
	
	
	


	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	

	
	
	
	
	
	

	
	

	
	
	
	
	
	
	


    

































































    
	
	
	
	
	
	
	
	
	
	
	
	
	


	
	
	


	
	
	
	

	
	
	
	
	
	

	
	
	
	

	
	
	
	

	
	
	
	
	

	


    




























































    
	
	
	
	
	
	
	
	
	
	


	
	
	


	
	
	
	
	
	
	
	

    






































    
	
    





#line 17 "graphviz-2.38.0\\lib\\gvc\\gvc.h" 2
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


















    
	
	
	
	
	
    

    
	
	
    

    
	
	
    





#line 18 "graphviz-2.38.0\\lib\\gvc\\gvc.h" 2











/*visual studio*/






/*end visual studio*/
	


/* misc */
/* FIXME - this needs eliminating or renaming */
 void gvToggle(int);

/* set up a graphviz context */
 GVC_t *gvNEWcontext(const lt_symlist_t *builtins, int demand_loading);

/*  set up a graphviz context - and init graph - retaining old API */
 GVC_t *gvContext(void);
/*  set up a graphviz context - and init graph - with builtins */
 GVC_t *gvContextPlugins(const lt_symlist_t *builtins, int demand_loading);

/* get information associated with a graphviz context */
 char **gvcInfo(GVC_t*);
 char *gvcVersion(GVC_t*);
 char *gvcBuildDate(GVC_t*);

/* parse command line args - minimally argv[0] sets layout engine */
 int gvParseArgs(GVC_t *gvc, int argc, char **argv);
 graph_t *gvNextInputGraph(GVC_t *gvc);
 graph_t *gvPluginsGraph(GVC_t *gvc);

/* Compute a layout using a specified engine */
 int gvLayout(GVC_t *gvc, graph_t *g, const char *engine);

/* Compute a layout using layout engine from command line args */
 int gvLayoutJobs(GVC_t *gvc, graph_t *g);

/* Render layout into string attributes of the graph */
 void attach_attrs(graph_t *g);

/* Render layout in a specified format to an open FILE */
 int gvRender(GVC_t *gvc, graph_t *g, const char *format, FILE *out);

/* Render layout in a specified format to an open FILE */
 int gvRenderFilename(GVC_t *gvc, graph_t *g, const char *format, const char *filename);

/* Render layout in a specified format to an external context */
 int gvRenderContext(GVC_t *gvc, graph_t *g, const char *format, void *context);

/* Render layout in a specified format to a malloc'ed string */
 int gvRenderData(GVC_t *gvc, graph_t *g, const char *format, char **result, unsigned int *length);

/* Free memory allocated and pointed to by *result in gvRenderData */
 void gvFreeRenderData (char* data);

/* Render layout according to -T and -o options found by gvParseArgs */
 int gvRenderJobs(GVC_t *gvc, graph_t *g);

/* Clean up layout data structures - layouts are not nestable (yet) */
 int gvFreeLayout(GVC_t *gvc, graph_t *g);

/* Clean up graphviz context */
 void gvFinalize(GVC_t *gvc);
 int gvFreeContext(GVC_t *gvc);

/* Return list of plugins of type kind.
 * kind would normally be "render" "layout" "textlayout" "device" "loadimage"
 * The size of the list is stored in sz.
 * The caller is responsible for freeing the storage. This involves
 * freeing each item, then the list.
 * Returns NULL on error, or if there are no plugins.
 * In the former case, sz is unchanged; in the latter, sz = 0.
 *
 * At present, the str argument is unused, but may be used to modify
 * the search as in gvplugin_list above.
 */
 char** gvPluginList (GVC_t *gvc, char* kind, int* sz, char*);

/** Add a library from your user application
 * @param gvc Graphviz context to add library to
 * @param lib library to add
 */

 void gvAddLibrary(GVC_t *gvc, gvplugin_library_t *lib);








#line 19 "graphviz-2.38.0\\lib\\gvc\\gvcproc.h" 2

/* these are intended to be private entry points - see gvc.h for the public ones */

/* configuration */

    extern char *gvconfig_libdir(GVC_t * gvc);
    extern void gvconfig(GVC_t * gvc, boolean rescan);
    extern char *gvhostname(void);

/* plugins */

    extern boolean gvplugin_install(GVC_t * gvc, api_t api,
		    const char *typestr, int quality, gvplugin_package_t *package,
		    gvplugin_installed_t * typeptr);
    extern gvplugin_available_t *gvplugin_load(GVC_t * gvc, api_t api, const char *type);
    extern gvplugin_library_t *gvplugin_library_load(GVC_t *gvc, char *path);
    extern api_t gvplugin_api(char *str);
    extern char * gvplugin_api_name(api_t api);
    extern void gvplugin_write_status(GVC_t * gvc);
    extern char *gvplugin_list(GVC_t * gvc, api_t api, const char *str);

    extern Agraph_t * gvplugin_graph(GVC_t * gvc);

/* job */

    extern void gvjobs_output_filename(GVC_t * gvc, const char *name);
    extern boolean gvjobs_output_langname(GVC_t * gvc, const char *name);
    extern GVJ_t *gvjobs_first(GVC_t * gvc);
    extern GVJ_t *gvjobs_next(GVC_t * gvc);
    extern void gvjobs_delete(GVC_t * gvc);

/* emit */
    extern void gvemit_graph(GVC_t * gvc, graph_t * g);

/* textlayout */

    extern int gvtextlayout_select(GVC_t * gvc);
    extern boolean gvtextlayout(GVC_t *gvc, textspan_t *span, char **fontpath);

/* loadimage */
    extern void gvloadimage(GVJ_t *job, usershape_t *us, boxf b, boolean filled, const char *target);
    
/* usershapes */
    extern point gvusershape_size_dpi(usershape_t *us, pointf dpi);
    extern point gvusershape_size(graph_t *g, char *name);
    extern usershape_t *gvusershape_find(char *name);

/* device */
    extern int gvdevice_initialize(GVJ_t * job);
    extern void gvdevice_format(GVJ_t * job);
    extern void gvdevice_finalize(GVJ_t * job);

/* render */

    extern pointf gvrender_ptf(GVJ_t *job, pointf p);
    extern pointf* gvrender_ptf_A(GVJ_t *job, pointf *af, pointf *AF, int n);

    extern int gvrender_begin_job(GVJ_t * job);
    extern void gvrender_end_job(GVJ_t * job);
    extern int gvrender_select(GVJ_t * job, const char *lang);
    extern int gvrender_features(GVJ_t * job);
    extern void gvrender_begin_graph(GVJ_t * job, graph_t * g);
    extern void gvrender_end_graph(GVJ_t * job);
    extern void gvrender_begin_page(GVJ_t * job);
    extern void gvrender_end_page(GVJ_t * job);
    extern void gvrender_begin_layer(GVJ_t * job);
    extern void gvrender_end_layer(GVJ_t * job);
    extern void gvrender_begin_cluster(GVJ_t * job, graph_t * sg);
    extern void gvrender_end_cluster(GVJ_t * job, graph_t *g);
    extern void gvrender_begin_nodes(GVJ_t * job);
    extern void gvrender_end_nodes(GVJ_t * job);
    extern void gvrender_begin_edges(GVJ_t * job);
    extern void gvrender_end_edges(GVJ_t * job);
    extern void gvrender_begin_node(GVJ_t * job, node_t * n);
    extern void gvrender_end_node(GVJ_t * job);
    extern void gvrender_begin_edge(GVJ_t * job, edge_t * e);
    extern void gvrender_end_edge(GVJ_t * job);
    extern void gvrender_begin_anchor(GVJ_t * job,
		char *href, char *tooltip, char *target, char *id);
    extern void gvrender_end_anchor(GVJ_t * job);
    extern void gvrender_begin_label(GVJ_t * job, label_type type);
    extern void gvrender_end_label(GVJ_t * job);
    extern void gvrender_textspan(GVJ_t * job, pointf p, textspan_t * span);
    extern void gvrender_set_pencolor(GVJ_t * job, char *name);
    extern void gvrender_set_penwidth(GVJ_t * job, double penwidth);
    extern void gvrender_set_fillcolor(GVJ_t * job, char *name);
    extern void gvrender_set_gradient_vals (GVJ_t * job, char *stopcolor, int angle, float frac);

    extern void gvrender_set_style(GVJ_t * job, char **s);
    extern void gvrender_ellipse(GVJ_t * job, pointf * AF, int n, int filled);
    extern void gvrender_polygon(GVJ_t* job, pointf* af, int n, int filled);
    extern void gvrender_box(GVJ_t * job, boxf BF, int filled);
    extern void gvrender_beziercurve(GVJ_t * job, pointf * AF, int n,
			int arrow_at_start, int arrow_at_end, boolean filled);
    extern void gvrender_polyline(GVJ_t * job, pointf * AF, int n);
    extern void gvrender_comment(GVJ_t * job, char *str);
    extern void gvrender_usershape(GVJ_t * job, char *name, pointf * AF, int n, boolean filled, char *imagescale);

/* layout */

    extern int gvlayout_select(GVC_t * gvc, const char *str);
    extern int gvFreeLayout(GVC_t * gvc, Agraph_t * g);
    extern int gvLayoutJobs(GVC_t * gvc, Agraph_t * g);

/* argvlist */
    extern gv_argvlist_t *gvNEWargvlist(void);
    extern void gv_argvlist_set_item(gv_argvlist_t *list, int index, char *item);
    extern void gv_argvlist_reset(gv_argvlist_t *list);
    extern void gv_argvlist_free(gv_argvlist_t *list);




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








#line 25 "graphviz-2.38.0\\lib\\common\\emit.c" 2
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











    
	
	
	
	
    





    
			 




    




    




    




    




    











































#line 26 "graphviz-2.38.0\\lib\\common\\emit.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\htmltable.h" 1
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






























    /* spans of text within a cell
     * NOTE: As required, the str field in span is utf-8.
     * This translation is done when libexpat scans the input.
     */
	
    /* line of textspan_t's */
    typedef struct {
	textspan_t *items;
	short nitems;
	char just;
	double size;   /* width of span */
	double lfsize; /* offset from previous baseline to current one */
    } htextspan_t;
	
    typedef struct {
	htextspan_t *spans;
	short nspans;
	char simple;
	boxf box;
    } htmltxt_t;

    typedef struct {
	boxf box;
	char *src;
	char *scale;
    } htmlimg_t;

    typedef struct {
	char *href;		/* pointer to an external resource */
	char *port;
	char *target;
	char *title;
	char *id;
	char *bgcolor;
	char *pencolor;
	int gradientangle;
	signed char space;
	unsigned char border;
	unsigned char pad;
	unsigned char sides;    /* set of sides exposed to field */
	unsigned short flags;
	unsigned short width;
	unsigned short height;
	unsigned short style;
	boxf box;		/* its geometric placement in points */
    } htmldata_t;









    typedef struct htmlcell_t htmlcell_t;
    typedef struct htmltbl_t htmltbl_t;
	
    struct htmltbl_t {
	htmldata_t data;
	union {
	    struct {
		htmlcell_t *parent;	/* enclosing cell */
		htmlcell_t **cells;	/* cells */
	    } n;
	    struct {
		htmltbl_t *prev;	/* stack */
		Dt_t *rows;	/* cells */
	    } p;
	} u;
	signed char cb;		/* cell border */
	int *heights;		/* heights of the rows */
	int *widths;		/* widths of the columns */
	int rc;			/* number of rows */
	int cc;			/* number of columns */
	textfont_t *font;	/* font info */
	unsigned char flags;
    };

    struct htmllabel_t {
	union {
	    htmltbl_t *tbl;
	    htmltxt_t *txt;
	    htmlimg_t *img;
	} u;
	char kind;
    };

    struct htmlcell_t {
	htmldata_t data;
	unsigned short cspan;
	unsigned short rspan;
	unsigned short col;
	unsigned short row;
	htmllabel_t child;
	htmltbl_t *parent;
	unsigned char ruled;
    };

/* During parsing, table contents are stored as rows of cells.
 * A row is a list of cells
 * Rows is a list of rows.
 * pitems are used for both lists.
 */
    typedef struct {
	Dtlink_t link;
	union {
	    Dt_t *rp;
	    htmlcell_t *cp;
	} u;
	unsigned char ruled;
    } pitem;
	
    typedef struct {
        pointf pos;
        textfont_t finfo;
        void *obj;
        graph_t *g;
        char *imgscale;
        char *objid;
        boolean objid_set;
    } htmlenv_t;

    extern htmllabel_t *parseHTML(char *, int *, htmlenv_t *);

    extern int make_html_label(void *obj, textlabel_t * lp);
    extern void emit_html_label(GVJ_t * job, htmllabel_t * lp, textlabel_t *);

    extern void free_html_label(htmllabel_t *, int);
    extern void free_html_data(htmldata_t *);
    extern void free_html_text(htmltxt_t *);

    extern boxf *html_port(node_t * n, char *pname, int* sides);
    extern int html_path(node_t * n, port* p, int side, boxf * rv, int *k);
    extern int html_inside(node_t * n, pointf p, edge_t * e);






#line 27 "graphviz-2.38.0\\lib\\common\\emit.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvc.h" 1
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

























	





















































































#line 28 "graphviz-2.38.0\\lib\\common\\emit.c" 2
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 29 "graphviz-2.38.0\\lib\\common\\emit.c" 2
#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.h" 1
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



#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.h" 1










typedef enum {
    xd_none,
    xd_linear,
    xd_radial
} xdot_grad_type;

typedef struct {
    float frac;
    char* color;
} xdot_color_stop;

typedef struct {
    double x0, y0;
    double x1, y1;
    int n_stops;
    xdot_color_stop* stops;
} xdot_linear_grad;

typedef struct {
    double x0, y0, r0;
    double x1, y1, r1;
    int n_stops;
    xdot_color_stop* stops;
} xdot_radial_grad;

typedef struct {
    xdot_grad_type type;
    union {
	char* clr;
	xdot_linear_grad ling;
	xdot_radial_grad ring;
    } u;
} xdot_color;

typedef enum {
    xd_left, xd_center, xd_right
} xdot_align;

typedef struct {
    double x, y, z;
} xdot_point;

typedef struct {
    double x, y, w, h;
} xdot_rect;

typedef struct {
    int cnt;
    xdot_point* pts;
} xdot_polyline;

typedef struct {
  double x, y;
  xdot_align align;
  double width;
  char* text;
} xdot_text;

typedef struct {
    xdot_rect pos;
    char* name;
} xdot_image;

typedef struct {
    double size;
    char* name;
} xdot_font;

typedef enum {
    xd_filled_ellipse, xd_unfilled_ellipse,
    xd_filled_polygon, xd_unfilled_polygon,
    xd_filled_bezier,  xd_unfilled_bezier,
    xd_polyline,       xd_text,
    xd_fill_color,     xd_pen_color, xd_font, xd_style, xd_image,
    xd_grad_fill_color,     xd_grad_pen_color,
    xd_fontchar
} xdot_kind; 
    
typedef enum {
    xop_ellipse,
    xop_polygon,
    xop_bezier,
    xop_polyline,       xop_text,
    xop_fill_color,     xop_pen_color, xop_font, xop_style, xop_image,
    xop_grad_color,
    xop_fontchar
} xop_kind; 
    
typedef struct _xdot_op xdot_op;
typedef void (*drawfunc_t)(xdot_op*, int);
typedef void (*freefunc_t)(xdot_op*);

struct _xdot_op {
    xdot_kind kind;
    union {
      xdot_rect ellipse;       /* xd_filled_ellipse, xd_unfilled_ellipse */
      xdot_polyline polygon;   /* xd_filled_polygon, xd_unfilled_polygon */
      xdot_polyline polyline;  /* xd_polyline */
      xdot_polyline bezier;    /* xd_filled_bezier,  xd_unfilled_bezier */
      xdot_text text;          /* xd_text */
      xdot_image image;        /* xd_image */
      char* color;             /* xd_fill_color, xd_pen_color */
      xdot_color grad_color;   /* xd_grad_fill_color, xd_grad_pen_color */
      xdot_font font;          /* xd_font */
      char* style;             /* xd_style */
      unsigned int fontchar;   /* xd_fontchar */
    } u;
    drawfunc_t drawfunc;
};



typedef struct {
    int cnt;  /* no. of xdot ops */
    int sz;   /* sizeof structure containing xdot_op as first field */
    xdot_op* ops;
    freefunc_t freefunc;
    int flags;
} xdot;

typedef struct {
    int cnt;  /* no. of xdot ops */
    int n_ellipse;
    int n_polygon;
    int n_polygon_pts;
    int n_polyline;
    int n_polyline_pts;
    int n_bezier;
    int n_bezier_pts;
    int n_text;
    int n_font;
    int n_style;
    int n_color;
    int n_image;
    int n_gradcolor;
    int n_fontchar;
} xdot_stats;

/* ops are indexed by xop_kind */
extern xdot* parseXDotF (char*, drawfunc_t opfns[], int sz);
extern xdot* parseXDotFOn (char*, drawfunc_t opfns[], int sz, xdot*);
extern xdot* parseXDot (char*);
extern char* sprintXDot (xdot*);
extern void fprintXDot (FILE*, xdot*);
extern void jsonXDot (FILE*, xdot*);
extern void freeXDot (xdot*);
extern int statXDot (xdot*, xdot_stats*);
extern xdot_grad_type colorTypeXDot (char*);
extern char* parseXDotColor (char* cp, xdot_color* clr);
extern void freeXDotColor (xdot_color*);





#line 30 "graphviz-2.38.0\\lib\\common\\emit.c" 2









typedef struct {
    xdot_op op;
    boxf bb;
    textspan_t* span;
} exdot_op;

void* init_xdot (Agraph_t* g)
{
    char* p;
    xdot* xd = NULL;

    if (!((p = agget(g, "_background")) && p[0])) {
	if (!((p = agget(g, "_draw_")) && p[0])) {
	    return NULL;
	}
    }

    
	
    

    xd = parseXDotF (p, NULL, sizeof (exdot_op));

    if (!xd) {
	agerr(AGWARN, "Could not parse \"_background\" attribute in graph %s\n", agnameof(g));
	agerr(AGPREV, "  \"%s\"\n", p);
    }

    
	
	
	
	
	
	
	
	
	
    

    return xd;
}

static char *defaultlinestyle[3] = { "solid\0", "setlinewidth\0001\0", 0 };

/* push empty graphic state for current object */
obj_state_t* push_obj_state(GVJ_t *job)
{
    obj_state_t *obj, *parent;

    if (! (obj = zmalloc(sizeof(obj_state_t))))
        agerr(AGERR, "no memory from zmalloc()\n");

    parent = obj->parent = job->obj;
    job->obj = obj;
    if (parent) {
        obj->pencolor = parent->pencolor;        /* default styles to parent's style */
        obj->fillcolor = parent->fillcolor;
        obj->pen = parent->pen;
        obj->fill = parent->fill;
        obj->penwidth = parent->penwidth;
	obj->gradient_angle = parent->gradient_angle;
	obj->stopcolor = parent->stopcolor;
    }
    else {
	/* obj->pencolor = NULL */
	/* obj->fillcolor = NULL */
	obj->pen = PEN_SOLID;
	obj->fill = FILL_NONE;
	obj->penwidth = 1.;
    }
    return obj;
}

/* pop graphic state of current object */
void pop_obj_state(GVJ_t *job)
{
    obj_state_t *obj = job->obj;

    assert(obj);

    free(obj->id);
    free(obj->url);
    free(obj->labelurl);
    free(obj->tailurl);
    free(obj->headurl);
    free(obj->tooltip);
    free(obj->labeltooltip);
    free(obj->tailtooltip);
    free(obj->headtooltip);
    free(obj->target);
    free(obj->labeltarget);
    free(obj->tailtarget);
    free(obj->headtarget);
    free(obj->url_map_p);
    free(obj->url_bsplinemap_p);
    free(obj->url_bsplinemap_n);

    job->obj = obj->parent;
    free(obj);
}

/* initMapData:
 * Store image map data into job, substituting for node, edge, etc.
 * names.
 * Return 1 if an assignment was made for url or tooltip or target.
 */
int
initMapData (GVJ_t* job, char* lbl, char* url, char* tooltip, char* target, char *id,
  void* gobj)
{
    obj_state_t *obj = job->obj;
    int flags = job->flags;
    int assigned = 0;

    if ((flags & (1<<15)) && lbl)
        obj->label = lbl;
    if (flags & (1<<16)) {
        obj->id = strdup_and_subst_obj(id, gobj);
	if (url && url[0]) {
            obj->url = strdup_and_subst_obj(url, gobj);
	    assigned = 1;
        }
    }
    if (flags & (1<<22)) {
        if (tooltip && tooltip[0]) {
            obj->tooltip = strdup_and_subst_obj(tooltip, gobj);
            obj->explicit_tooltip = NOT(0);
	    assigned = 1;
        }
        else if (obj->label) {
            obj->tooltip = strdup(obj->label);
	    assigned = 1;
        }
    }
    if ((flags & (1<<23)) && target && target[0]) {
        obj->target = strdup_and_subst_obj(target, gobj);
	assigned = 1;
    }
    return assigned;
}

static void
layerPagePrefix (GVJ_t* job, agxbuf* xb)
{
    char buf[128]; /* large enough for 2 decimal 64-bit ints and "page_," */
    if (job->layerNum > 1 && (job->flags & (1<<6))) {
	agxbput (xb, job->gvc->layerIDs[job->layerNum]);
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'_')));
    }
    if ((job->pagesArrayElem.x > 0) || (job->pagesArrayElem.x > 0)) {
	sprintf (buf, "page%d,%d_", job->pagesArrayElem.x, job->pagesArrayElem.y);
	agxbput (xb, buf);
    }
}

/* genObjId:
 * Use id of root graph if any, plus kind and internal id of object
 */
char*
getObjId (GVJ_t* job, void* obj, agxbuf* xb)
{
    char* id;
    graph_t* root = job->gvc->g;
    char* gid = GD_drawing(root)->id;
    long idnum;
    char* pfx;
    char buf[64]; /* large enough for a decimal 64-bit int */

    layerPagePrefix (job, xb);

    id = agget(obj, "id");
    if (id && (*id != '\0')) {
	agxbput (xb, id);
	return (((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'\0'))),(char*)((xb)->ptr = (xb)->buf));
    }

    if ((obj != root) && gid) {
	agxbput (xb, gid);
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'_')));
    }

    switch (agobjkind(obj)) {
    case AGRAPH:
	idnum = AGSEQ(obj);
	if (root == obj)
	    pfx = "graph";
	else
	    pfx = "clust";
	break;
    case AGNODE:
        idnum = AGSEQ((Agnode_t*)obj);
	pfx = "node";
	break;
    case AGEDGE:
        idnum = AGSEQ((Agedge_t*)obj);
	pfx = "edge";
	break;
    }

    agxbput (xb, pfx);
    sprintf (buf, "%ld", idnum);
    agxbput (xb, buf);

    return (((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'\0'))),(char*)((xb)->ptr = (xb)->buf));
}

static void
initObjMapData (GVJ_t* job, textlabel_t *lab, void* gobj)
{
    char* lbl;
    char* url = agget(gobj, "href");
    char* tooltip = agget(gobj, "tooltip");
    char* target = agget(gobj, "target");
    char* id;
    unsigned char buf[128];
    agxbuf xb;

    agxbinit(&xb, 128, buf);

    if (lab) lbl = lab->text;
    else lbl = NULL;
    if (!url || !*url)  /* try URL as an alias for href */
	url = agget(gobj, "URL");
    id = getObjId (job, gobj, &xb);
    initMapData (job, lbl, url, tooltip, target, id, gobj);

    agxbfree(&xb);
}

static void map_point(GVJ_t *job, pointf pf)
{
    obj_state_t *obj = job->obj;
    int flags = job->flags;
    pointf *p;

    if (flags & ((1<<16) | (1<<22))) {
	if (flags & (1<<17)) {
	    obj->url_map_shape = MAP_RECTANGLE;
	    obj->url_map_n = 2;
	}
	else {
	    obj->url_map_shape = MAP_POLYGON;
	    obj->url_map_n = 4;
	}
	free(obj->url_map_p);
	obj->url_map_p = p = (pointf*)zmalloc((obj->url_map_n)*sizeof(pointf));
	(p[0].x = pf.x - 3, p[0].y = pf.y - 3, p[1].x = pf.x + 3, p[1].y = pf.y + 3);
	if (! (flags & (1<<13)))
	    gvrender_ptf_A(job, p, p, 2);
	if (! (flags & (1<<17)))
	    rect2poly(p);
    }
}

static char **checkClusterStyle(graph_t* sg, int *flagp)
{
    char *style;
    char **pstyle = 0;
    int istyle = 0;

    if (((style = agget(sg, "style")) != 0) && style[0]) {
	char **pp;
	char **qp;
	char *p;
	pp = pstyle = parse_style(style);
	while ((p = *pp)) {
	    if (strcmp(p, "filled") == 0) {
		istyle |= (1 << 0);
		pp++;
 	    }else if (strcmp(p, "radial") == 0) {
 		istyle |= ((1 << 0) | (1 << 1));
		qp = pp; /* remove rounded from list passed to renderer */
		do {
		    qp++;
		    *(qp-1) = *qp;
		} while (*qp);
 	    }else if (strcmp(p, "striped") == 0) {
 		istyle |= (1 << 6);
		qp = pp; /* remove rounded from list passed to renderer */
		do {
		    qp++;
		    *(qp-1) = *qp;
		} while (*qp);
	    }else if (strcmp(p, "rounded") == 0) {
		istyle |= (1 << 2);
		qp = pp; /* remove rounded from list passed to renderer */
		do {
		    qp++;
		    *(qp-1) = *qp;
		} while (*qp);
	    } else pp++;
	}
    }

    *flagp = istyle;
    return pstyle;
}

typedef struct {
    char* color;   /* segment color */
    float t;       /* segment size >= 0 */
    boolean hasFraction;  /* true if color explicitly specifies its fraction */
} colorseg_t;
/* Sum of segment sizes should add to 1 */
typedef struct {
    int numc;     /* number of used segments in segs; may include segs with t == 0 */
    char* base;   /* storage of color names */
    colorseg_t* segs;  /* array of segments; real segments always followed by a sentinel */
} colorsegs_t;
 
static void
freeSegs (colorsegs_t* segs)
{
    free (segs->base);
    free (segs->segs);
    free (segs);
}

/* getSegLen:
 * Find semicolon in s, replace with '\0'.
 * Convert remainder to float v.
 * Return 0 if no float given
 * Return -1 on failure
 */
static double getSegLen (char* s)
{
    char* p = strchr (s, ';');
    char* endp;
    double v;

    if (!p) {
	return 0;
    }
    *p++ = '\0';
    v = strtod (p, &endp);
    if (endp != p) {  /* scanned something */
	if (v >= 0)
	    return v;
    }
    return -1;
}




/* parseSegs:
 * Parse string of form color;float:color;float:...:color;float:color
 * where the floats are optional, nonnegative, sum to <= 1.
 * Store the values in an array of colorseg_t's and return the array in psegs.
 * If nseg == 0, count the number of colors.
 * If the sum of the floats does not equal 1, the remainder is equally distributed
 * to all colors without an explicit float. If no such colors exist, the remainder
 * is added to the last color.
 *  0 => okay
 *  1 => error without message 
 *  2 => error with message 
 *  3 => warning message
 * There is a last sentinel segment with color == NULL; it will always follow
 * the last segment with t > 0.
 */
static int
parseSegs (char* clrs, int nseg, colorsegs_t** psegs)
{
    colorsegs_t* segs = (colorsegs_t*)zmalloc(sizeof(colorsegs_t));
    colorseg_t* s;
    char* colors = strdup (clrs);
    char* color;
    int cnum = 0;
    double v, left = 1;
    static int doWarn = 1;
    int i, rval = 0;
    char* p;

    if (nseg == 0) {
	nseg = 1;
	/* need to know how many colors separated by ':' */
	for (p = colors; *p; p++) {
	    if (*p == ':') nseg++;
	}
    }

    segs->base = colors;
    segs->segs = s = (colorseg_t*)zmalloc((nseg+1)*sizeof(colorseg_t));
    for (color = strtok(colors, ":"); color; color = strtok(0, ":")) {
	if ((v = getSegLen (color)) >= 0) {
	    double del = v - left;
	    if (del > 0) {
		if (doWarn && !(((del) < 1E-5) && ((del) > -1E-5))) {
		    agerr (AGWARN, "Total size > 1 in \"%s\" color spec ", clrs);
		    doWarn = 0;
		    rval = 3;
		}
		v = left;
	    }
	    left -= v;
	    if (v > 0) s[cnum].hasFraction = NOT(0);
	    if (*color) s[cnum].color = color;
	    s[cnum++].t = v;
	}
	else {
	    if (doWarn) {
		agerr (AGERR, "Illegal length value in \"%s\" color attribute ", clrs);
		doWarn = 0;
		rval = 2;
	    }
	    else rval = 1;
	    freeSegs (segs);
	    return rval;
	}
	if ((((left) < 1E-5) && ((left) > -1E-5))) {
	    left = 0;
	    break;
	}
    }

    /* distribute remaining into slot with t == 0; if none, add to last */
    if (left > 0) {
	/* count zero segments */
	nseg = 0;
	for (i = 0; i < cnum; i++) {
	    if (s[i].t == 0) nseg++;
	}
	if (nseg > 0) {
	    double delta = left/nseg;
	    for (i = 0; i < cnum; i++) {
		if (s[i].t == 0) s[i].t = delta;
	    }
	}
	else {
	    s[cnum-1].t += left;
	}
    }
    
    /* Make sure last positive segment is followed by a sentinel. */
    nseg = 0;
    for (i = cnum-1; i >= 0; i--) {
	if (s[i].t > 0) break;
    }
    s[i+1].color = NULL;
    segs->numc = i+1;

    *psegs = segs;
    return rval;
}



/* wedgedEllipse:
 * Fill an ellipse whose bounding box is given by 2 points in pf
 * with multiple wedges determined by the color spec in clrs.
 * clrs is a list of colon separated colors, with possible quantities. 
 * Thin boundaries are drawn.
 *  0 => okay
 *  1 => error without message 
 *  2 => error with message 
 *  3 => warning message
 */
int 
wedgedEllipse (GVJ_t* job, pointf * pf, char* clrs)
{
    colorsegs_t* segs;
    colorseg_t* s;
    int rv;
    double save_penwidth = job->obj->penwidth;
    pointf ctr, semi;
    Ppolyline_t* pp;
    double angle0, angle1;

    rv = parseSegs (clrs, 0, &segs);
    if ((rv == 1) || (rv == 2)) return rv;
    ctr.x = (pf[0].x + pf[1].x) / 2.;
    ctr.y = (pf[0].y + pf[1].y) / 2.;
    semi.x = pf[1].x - ctr.x;
    semi.y = pf[1].y - ctr.y;
    if (save_penwidth > 0.5)
	gvrender_set_penwidth(job, 0.5);
	
    angle0 = 0;
    for (s = segs->segs; s->color; s++) {
	if (s->t == 0) continue;
	gvrender_set_fillcolor (job, (s->color?s->color:"black"));

	if (s[1].color == NULL) 
	    angle1 = 2*M_PI;
	else
	    angle1 = angle0 + 2*M_PI*(s->t);
	pp = ellipticWedge (ctr, semi.x, semi.y, angle0, angle1);
	gvrender_beziercurve(job, pp->ps, pp->pn, 0, 0, 1);
	angle0 = angle1;
	freePath (pp);
    }

    if (save_penwidth > 0.5)
	gvrender_set_penwidth(job, save_penwidth);
    freeSegs (segs);
    return rv;
}

/* stripedBox:
 * Fill a rectangular box with vertical stripes of colors.
 * AF gives 4 corner points, with AF[0] the LL corner and the points ordered CCW.
 * clrs is a list of colon separated colors, with possible quantities. 
 * Thin boundaries are drawn.
 *  0 => okay
 *  1 => error without message 
 *  2 => error with message 
 *  3 => warning message
 */
int
stripedBox (GVJ_t * job, pointf* AF, char* clrs, int rotate)
{
    colorsegs_t* segs;
    colorseg_t* s;
    int rv;
    double xdelta;
    pointf pts[4];
    double lastx;
    double save_penwidth = job->obj->penwidth;

    rv = parseSegs (clrs, 0, &segs);
    if ((rv == 1) || (rv == 2)) return rv;
    if (rotate) {
	pts[0] = AF[2];
	pts[1] = AF[3];
	pts[2] = AF[0];
	pts[3] = AF[1];
    } else {
	pts[0] = AF[0];
	pts[1] = AF[1];
	pts[2] = AF[2];
	pts[3] = AF[3];
    }
    lastx = pts[1].x;
    xdelta = (pts[1].x - pts[0].x);
    pts[1].x = pts[2].x = pts[0].x;
    
    if (save_penwidth > 0.5)
	gvrender_set_penwidth(job, 0.5);
    for (s = segs->segs; s->color; s++) {
	if (s->t == 0) continue;
	gvrender_set_fillcolor (job, (s->color?s->color:"black"));
	/* gvrender_polygon(job, pts, 4, FILL | NO_POLY); */
	if (s[1].color == NULL) 
	    pts[1].x = pts[2].x = lastx;
	else
	    pts[1].x = pts[2].x = pts[0].x + xdelta*(s->t);
	gvrender_polygon(job, pts, 4, 1);
	pts[0].x = pts[3].x = pts[1].x;
    }
    if (save_penwidth > 0.5)
	gvrender_set_penwidth(job, save_penwidth);
    freeSegs (segs);
    return rv;
}

void emit_map_rect(GVJ_t *job, boxf b)
{
    obj_state_t *obj = job->obj;
    int flags = job->flags;
    pointf *p;

    if (flags & ((1<<16) | (1<<22))) {
	if (flags & (1<<17)) {
	    obj->url_map_shape = MAP_RECTANGLE;
	    obj->url_map_n = 2;
	}
	else {
	    obj->url_map_shape = MAP_POLYGON;
	    obj->url_map_n = 4;
	}
	free(obj->url_map_p);
	obj->url_map_p = p = (pointf*)zmalloc((obj->url_map_n)*sizeof(pointf));
	p[0] = b.LL;
	p[1] = b.UR;
	if (! (flags & (1<<13)))
	    gvrender_ptf_A(job, p, p, 2);
	if (! (flags & (1<<17)))
	    rect2poly(p);
    }
}

static void map_label(GVJ_t *job, textlabel_t *lab)
{
    obj_state_t *obj = job->obj;
    int flags = job->flags;
    pointf *p;

    if (flags & ((1<<16) | (1<<22))) {
	if (flags & (1<<17)) {
	    obj->url_map_shape = MAP_RECTANGLE;
	    obj->url_map_n = 2;
	}
	else {
	    obj->url_map_shape = MAP_POLYGON;
	    obj->url_map_n = 4;
	}
	free(obj->url_map_p);
	obj->url_map_p = p = (pointf*)zmalloc((obj->url_map_n)*sizeof(pointf));
	(p[0].x = lab->pos.x - lab->dimen.x / 2., p[0].y = lab->pos.y - lab->dimen.y / 2., p[1].x = lab->pos.x + lab->dimen.x / 2., p[1].y = lab->pos.y + lab->dimen.y / 2.);
	if (! (flags & (1<<13)))
	    gvrender_ptf_A(job, p, p, 2);
	if (! (flags & (1<<17)))
	    rect2poly(p);
    }
}

/* isRect:
 * isRect function returns true when polygon has
 * regular rectangular shape. Rectangle is regular when
 * it is not skewed and distorted and orientation is almost zero
 */
static boolean isRect(polygon_t * p)
{
    return (p->sides == 4 && (ROUND(p->orientation) % 90) == 0
            && p->distortion == 0.0 && p->skew == 0.0);
}

/*
 * isFilled function returns 1 if filled style has been set for node 'n'
 * otherwise returns 0. it accepts pointer to node_t as an argument
 */
static int ifFilled(node_t * n)
{
    char *style, *p, **pp;
    int r = 0;
    style = late_nnstring(n, N_style, "");
    if (style[0]) {
        pp = parse_style(style);
        while ((p = *pp)) {
            if (strcmp(p, "filled") == 0)
                r = 1;
            pp++;
        }
    }
    return r;
}

/* pEllipse:
 * pEllipse function returns 'np' points from the circumference
 * of ellipse described by radii 'a' and 'b'.
 * Assumes 'np' is greater than zero.
 * 'np' should be at least 4 to sample polygon from ellipse
 */
static pointf *pEllipse(double a, double b, int np)
{
    double theta = 0.0;
    double deltheta = 2 * M_PI / np;
    int i;
    pointf *ps;

    ps = (pointf*)zmalloc((np)*sizeof(pointf));
    for (i = 0; i < np; i++) {
        ps[i].x = a * cos(theta);
        ps[i].y = b * sin(theta);
        theta += deltheta;
    }
    return ps;
}



/* check_control_points:
 * check_control_points function checks the size of quadrilateral
 * formed by four control points
 * returns 1 if four points are in line (or close to line)
 * else return 0
 */
static int check_control_points(pointf *cp)
{
    double dis1 = ptToLine2 (cp[0], cp[3], cp[1]);
    double dis2 = ptToLine2 (cp[0], cp[3], cp[2]);
    if (dis1 < 2.0*2.0 && dis2 < 2.0*2.0)
        return 1;
    else
        return 0;
}

/* update bounding box to contain a bezier segment */
void update_bb_bz(boxf *bb, pointf *cp)
{

    /* if any control point of the segment is outside the bounding box */
    if (cp[0].x > bb->UR.x || cp[0].x < bb->LL.x ||
        cp[0].y > bb->UR.y || cp[0].y < bb->LL.y ||
        cp[1].x > bb->UR.x || cp[1].x < bb->LL.x ||
        cp[1].y > bb->UR.y || cp[1].y < bb->LL.y ||
        cp[2].x > bb->UR.x || cp[2].x < bb->LL.x ||
        cp[2].y > bb->UR.y || cp[2].y < bb->LL.y ||
        cp[3].x > bb->UR.x || cp[3].x < bb->LL.x ||
        cp[3].y > bb->UR.y || cp[3].y < bb->LL.y) {

        /* if the segment is sufficiently refined */
        if (check_control_points(cp)) {        
            int i;
            /* expand the bounding box */
            for (i = 0; i < 4; i++) {
                if (cp[i].x > bb->UR.x)
                    bb->UR.x = cp[i].x;
                else if (cp[i].x < bb->LL.x)
                    bb->LL.x = cp[i].x;
                if (cp[i].y > bb->UR.y)
                    bb->UR.y = cp[i].y;
                else if (cp[i].y < bb->LL.y)
                    bb->LL.y = cp[i].y;
            }
        }
        else { /* else refine the segment */
            pointf left[4], right[4];
            Bezier (cp, 3, 0.5, left, right);
            update_bb_bz(bb, left);
            update_bb_bz(bb, right);
        }
    }
}




   
   
   
        
   



typedef struct segitem_s {
    pointf p;
    struct segitem_s* next;
} segitem_t;





static segitem_t* appendSeg (pointf p, segitem_t* lp)
{
    segitem_t* s = (segitem_t*)gmalloc(sizeof(segitem_t));
    {(s)->next = 0; (s)->p = p;};
    lp->next = s;
    return s;
}

/* map_bspline_poly:
 * Output the polygon determined by the n points in p1, followed
 * by the n points in p2 in reverse order. Assumes n <= 50.
 */
static void map_bspline_poly(pointf **pbs_p, int **pbs_n, int *pbs_poly_n, int n, pointf* p1, pointf* p2)
{
    int i = 0, nump = 0, last = 2*n-1;

    for ( ; i < *pbs_poly_n; i++)
        nump += (*pbs_n)[i];

    (*pbs_poly_n)++;
    *pbs_n = grealloc(*pbs_n, (*pbs_poly_n) * sizeof(int));
    (*pbs_n)[i] = 2*n;
    *pbs_p = grealloc(*pbs_p, (nump + 2*n) * sizeof(pointf));

    for (i = 0; i < n; i++) {
        (*pbs_p)[nump+i] = p1[i];
        (*pbs_p)[nump+last-i] = p2[i];
    }

    

}

/* approx_bezier:
 * Approximate Bezier by line segments. If the four points are
 * almost colinear, as determined by check_control_points, we store
 * the segment cp[0]-cp[3]. Otherwise we split the Bezier into 2 and recurse. 
 * Since 2 contiguous segments share an endpoint, we actually store
 * the segments as a list of points.
 * New points are appended to the list given by lp. The tail of the
 * list is returned.
 */
static segitem_t* approx_bezier (pointf *cp, segitem_t* lp)
{
    pointf left[4], right[4];

    if (check_control_points(cp)) {
        if (((lp)->next == (segitem_t*)1)) {(lp)->next = 0; (lp)->p = cp[0];};
        lp = appendSeg (cp[3], lp);
    }
    else {
        Bezier (cp, 3, 0.5, left, right);
        lp = approx_bezier (left, lp);
        lp = approx_bezier (right, lp);
    }
    return lp;
}

/* bisect:
 * Return the angle of the bisector between the two rays
 * pp-cp and cp-np. The bisector returned is always to the
 * left of pp-cp-np.
 */
static double bisect (pointf pp, pointf cp, pointf np)
{
  double ang, theta, phi;
  theta = atan2(np.y - cp.y,np.x - cp.x);
  phi = atan2(pp.y - cp.y,pp.x - cp.x);
  ang = theta - phi;
  if (ang > 0) ang -= 2*M_PI;

  return (phi + ang/2.0);
}

/* mkSegPts:
 * Determine polygon points related to 2 segments prv-cur and cur-nxt.
 * The points lie on the bisector of the 2 segments, passing through cur,
 * and distance w2 from cur. The points are stored in p1 and p2.
 * If p1 is NULL, we use the normal to cur-nxt.
 * If p2 is NULL, we use the normal to prv-cur.
 * Assume at least one of prv or nxt is non-NULL.
 */
static void mkSegPts (segitem_t* prv, segitem_t* cur, segitem_t* nxt,
        pointf* p1, pointf* p2, double w2)
{
    pointf cp, pp, np;
    double theta, delx, dely;
    pointf p;

    cp = cur->p;
    /* if prv or nxt are NULL, use the one given to create a collinear
     * prv or nxt. This could be more efficiently done with special case code, 
     * but this way is more uniform.
     */
    if (prv) {
        pp = prv->p;
        if (nxt)
            np = nxt->p;
        else {
            np.x = 2*cp.x - pp.x;
            np.y = 2*cp.y - pp.y;
        }
    }
    else {
        np = nxt->p;
        pp.x = 2*cp.x - np.x;
        pp.y = 2*cp.y - np.y;
    }
    theta = bisect(pp,cp,np);
    delx = w2*cos(theta);
    dely = w2*sin(theta);
    p.x = cp.x + delx;
    p.y = cp.y + dely;
    *p1 = p;
    p.x = cp.x - delx;
    p.y = cp.y - dely;
    *p2 = p;
}

/* map_output_bspline:
 * Construct and output a closed polygon approximating the input
 * B-spline bp. We do this by first approximating bp by a sequence
 * of line segments. We then use the sequence of segments to determine
 * the polygon.
 * In cmapx, polygons are limited to 100 points, so we output polygons
 * in chunks of 100.
 */
static void map_output_bspline (pointf **pbs, int **pbs_n, int *pbs_poly_n, bezier* bp, double w2)
{
    segitem_t* segl = (segitem_t*)gmalloc(sizeof(segitem_t));
    segitem_t* segp = segl;
    segitem_t* segprev;
    segitem_t* segnext;
    int nc, j, k, cnt;
    pointf pts[4], pt1[50], pt2[50];

    ((segl)->next = (segitem_t*)1);
    nc = (bp->size - 1)/3; /* nc is number of bezier curves */
    for (j = 0; j < nc; j++) {
        for (k = 0; k < 4; k++) {
            pts[k] = bp->list[3*j + k];
        }
        segp = approx_bezier (pts, segp);
    }

    segp = segl;
    segprev = 0;
    cnt = 0;
    while (segp) {
        segnext = segp->next;
        mkSegPts (segprev, segp, segnext, pt1+cnt, pt2+cnt, w2);
        cnt++;
        if ((segnext == NULL) || (cnt == 50)) {
            map_bspline_poly (pbs, pbs_n, pbs_poly_n, cnt, pt1, pt2);
            pt1[0] = pt1[cnt-1];
            pt2[0] = pt2[cnt-1];
            cnt = 1;
        }
        segprev = segp;
        segp = segnext;
    }

    /* free segl */
    while (segl) {
        segp = segl->next;
        free (segl);
        segl = segp;
    }
}

static boolean is_natural_number(char *sstr)
{
    unsigned char *str = (unsigned char *) sstr;

    while (*str)
	if (NOT(isdigit(*str++)))
	    return 0;
    return NOT(0);
}

static int layer_index(GVC_t *gvc, char *str, int all)
{
    /* GVJ_t *job = gvc->job; */
    int i;

    if ((*(str)==*("all")&&!strcmp(str,"all")))
	return all;
    if (is_natural_number(str))
	return atoi(str);
    if (gvc->layerIDs)
	for (i = 1; i <= gvc->numLayers; i++)
	    if ((*(str)==*(gvc->layerIDs[i])&&!strcmp(str,gvc->layerIDs[i])))
		return i;
    return -1;
}

static boolean selectedLayer(GVC_t *gvc, int layerNum, int numLayers, char *spec)
{
    int n0, n1;
    unsigned char buf[128];
    char *w0, *w1;
    char *buf_part_p = NULL, *buf_p = NULL, *cur, *part_in_p;
    agxbuf xb;
    boolean rval = 0;

    agxbinit(&xb, 128, buf);
    agxbput(&xb, spec);
    part_in_p = (((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf));

    /* Thanks to Matteo Nastasi for this extended code. */
    while ((rval == 0) && (cur = strtok_r(part_in_p, gvc->layerListDelims, &buf_part_p))) {
	w1 = w0 = strtok_r (cur, gvc->layerDelims, &buf_p);
	if (w0)
	    w1 = strtok_r (NULL, gvc->layerDelims, &buf_p);
	switch ((w0 != NULL) + (w1 != NULL)) {
	case 0:
	    rval = 0;
	    break;
	case 1:
	    n0 = layer_index(gvc, w0, layerNum);
	    rval = (n0 == layerNum);
	    break;
	case 2:
	    n0 = layer_index(gvc, w0, 0);
	    n1 = layer_index(gvc, w1, numLayers);
	    if ((n0 >= 0) || (n1 >= 0)) {
		if (n0 > n1) {
		    int t = n0;
		    n0 = n1;
		    n1 = t;
		}
		rval = BETWEEN(n0, layerNum, n1);
	    }
	    break;
	}
	part_in_p = NULL;
    }
    agxbfree(&xb);
    return rval;
}

static boolean selectedlayer(GVJ_t *job, char *spec)
{
    return selectedLayer (job->gvc, job->layerNum, job->numLayers, spec);
}

/* parse_layerselect:
 * Parse the graph's layerselect attribute, which determines
 * which layers are emitted. The specification is the same used
 * by the layer attribute.
 *
 * If we find n layers, we return an array arr of n+2 ints. arr[0]=n.
 * arr[n+1]=numLayers+1, acting as a sentinel. The other entries give
 * the desired layer indices.
 *
 * If no layers are detected, NULL is returned.
 *
 * This implementation does a linear walk through each layer index and
 * uses selectedLayer to match it against p. There is probably a more
 * efficient way to do this, but this is simple and until we find people
 * using huge numbers of layers, it should be adequate.
 */
static int* parse_layerselect(GVC_t *gvc, graph_t * g, char *p)
{
    int* laylist = (int*)gmalloc((gvc->numLayers+2)*sizeof(int));
    int i, cnt = 0;
    for (i = 1; i <=gvc->numLayers; i++) {
	if (selectedLayer (gvc, i, gvc->numLayers, p)) {
	    laylist[++cnt] = i;
	} 
    }
    if (cnt) {
	laylist[0] = cnt;
	laylist[cnt+1] = gvc->numLayers+1;
    }
    else {
	agerr(AGWARN, "The layerselect attribute \"%s\" does not match any layer specifed by the layers attribute - ignored.\n", p);
	laylist[0] = cnt;
	free (laylist);
	laylist = NULL;
    }
    return laylist;
}

/* parse_layers:
 * Split input string into tokens, with separators specified by
 * the layersep attribute. Store the values in the gvc->layerIDs array,
 * starting at index 1, and return the count.
 * Free previously stored list. Note that there is no mechanism
 * to free the memory before exit.
 */
static int parse_layers(GVC_t *gvc, graph_t * g, char *p)
{
    int ntok;
    char *tok;
    int sz;

    gvc->layerDelims = agget(g, "layersep");
    if (!gvc->layerDelims)
        gvc->layerDelims = ":\t ";
    gvc->layerListDelims = agget(g, "layerlistsep");
    if (!gvc->layerListDelims)
        gvc->layerListDelims = ",";
    if ((tok = strpbrk (gvc->layerDelims, gvc->layerListDelims))) { /* conflict in delimiter strings */
	agerr(AGWARN, "The character \'%c\' appears in both the layersep and layerlistsep attributes - layerlistsep ignored.\n", *tok);
        gvc->layerListDelims = "";
    }

    ntok = 0;
    sz = 0;
    gvc->layers = strdup(p);

    for (tok = strtok(gvc->layers, gvc->layerDelims); tok;
         tok = strtok(NULL, gvc->layerDelims)) {
        ntok++;
        if (ntok > sz) {
            sz += 128;
            gvc->layerIDs = ALLOC(sz, gvc->layerIDs, char *);
        }
        gvc->layerIDs[ntok] = tok;
    }
    if (ntok) {
        gvc->layerIDs = RALLOC(ntok + 2, gvc->layerIDs, char *);        /* shrink to minimum size */
        gvc->layerIDs[0] = NULL;
        gvc->layerIDs[ntok + 1] = NULL;
    }

    return ntok;
}

/* chkOrder:
 * Determine order of output.
 * Output usually in breadth first graph walk order
 */
static int chkOrder(graph_t * g)
{
    char *p = agget(g, "outputorder");
    if (p) {
        char c = *p;
        if ((c == 'n') && !strcmp(p + 1, "odesfirst"))
            return (1<<0);
        if ((c == 'e') && !strcmp(p + 1, "dgesfirst"))
            return (1<<4);
    }
    return 0;
}

static void init_layering(GVC_t * gvc, graph_t * g)
{
    char *str;

    /* free layer strings and pointers from previous graph */
    if (gvc->layers) {
	free(gvc->layers);
	gvc->layers = NULL;
    }
    if (gvc->layerIDs) {
	free(gvc->layerIDs);
	gvc->layerIDs = NULL;
    }
    if (gvc->layerlist) {
	free(gvc->layerlist);
	gvc->layerlist = NULL;
    }
    if ((str = agget(g, "layers")) != 0) {
	gvc->numLayers = parse_layers(gvc, g, str);
 	if (((str = agget(g, "layerselect")) != 0) && *str) {
	    gvc->layerlist = parse_layerselect(gvc, g, str);
	}
    } else {
	gvc->layerIDs = NULL;
	gvc->numLayers = 1;
    }
}

/* numPhysicalLayers:
 * Return number of physical layers to be emitted.
 */
static int numPhysicalLayers (GVJ_t *job)
{
    if (job->gvc->layerlist) {
	return job->gvc->layerlist[0];
    }
    else
	return job->numLayers;

}

static void firstlayer(GVJ_t *job, int** listp)
{
    job->numLayers = job->gvc->numLayers;
    if (job->gvc->layerlist) {
	int *list = job->gvc->layerlist;
	int cnt = *list++;
	if ((cnt > 1) && (! (job->flags & (1<<6)))) {
	    agerr(AGWARN, "layers not supported in %s output\n",
		job->output_langname);
	    list[1] = job->numLayers + 1; /* only one layer printed */
	}
	job->layerNum = *list++;
	*listp = list;
    }
    else {
	if ((job->numLayers > 1)
		&& (! (job->flags & (1<<6)))) {
	    agerr(AGWARN, "layers not supported in %s output\n",
		job->output_langname);
	    job->numLayers = 1;
	}
	job->layerNum = 1;
	*listp = NULL;
    }
}

static boolean validlayer(GVJ_t *job)
{
    return (job->layerNum <= job->numLayers);
}

static void nextlayer(GVJ_t *job, int** listp)
{
    int *list = *listp;
    if (list) {
	job->layerNum = *list++;
	*listp = list;
    }
    else
	job->layerNum++;
}

static point pagecode(GVJ_t *job, char c)
{
    point rv;
    rv.x = rv.y = 0;
    switch (c) {
    case 'T':
	job->pagesArrayFirst.y = job->pagesArraySize.y - 1;
	rv.y = -1;
	break;
    case 'B':
	rv.y = 1;
	break;
    case 'L':
	rv.x = 1;
	break;
    case 'R':
	job->pagesArrayFirst.x = job->pagesArraySize.x - 1;
	rv.x = -1;
	break;
    }
    return rv;
}

static void init_job_pagination(GVJ_t * job, graph_t *g)
{
    GVC_t *gvc = job->gvc;
    pointf pageSize;	/* page size for the graph - points*/
    pointf imageSize;	/* image size on one page of the graph - points */
    pointf margin;	/* margin for a page of the graph - points */
    pointf centering = {0.0, 0.0}; /* centering offset - points */

    /* unpaginated image size - in points - in graph orientation */
    imageSize = job->view;

    /* rotate imageSize to page orientation */
    if (job->rotation)
	imageSize = exch_xyf(imageSize);

    /* margin - in points - in page orientation */
    margin = job->margin;

    /* determine pagination */
    if (gvc->graph_sets_pageSize && (job->flags & (1<<5))) {
	/* page was set by user */

        /* determine size of page for image */
	pageSize.x = gvc->pageSize.x - 2 * margin.x;
	pageSize.y = gvc->pageSize.y - 2 * margin.y;

	if (pageSize.x < .0001)
	    job->pagesArraySize.x = 1;
	else {
	    job->pagesArraySize.x = (int)(imageSize.x / pageSize.x);
	    if ((imageSize.x - (job->pagesArraySize.x * pageSize.x)) > .0001)
		job->pagesArraySize.x++;
	}
	if (pageSize.y < .0001)
	    job->pagesArraySize.y = 1;
	else {
	    job->pagesArraySize.y = (int)(imageSize.y / pageSize.y);
	    if ((imageSize.y - (job->pagesArraySize.y * pageSize.y)) > .0001)
		job->pagesArraySize.y++;
	}
	job->numPages = job->pagesArraySize.x * job->pagesArraySize.y;

	/* find the drawable size in points */
	imageSize.x = MIN(imageSize.x, pageSize.x);
	imageSize.y = MIN(imageSize.y, pageSize.y);
    } else {
	/* page not set by user, use default from renderer */
	if (job->render.features) {
	    pageSize.x = job->device.features->default_pagesize.x - 2*margin.x;
	    if (pageSize.x < 0.)
		pageSize.x = 0.;
	    pageSize.y = job->device.features->default_pagesize.y - 2*margin.y;
	    if (pageSize.y < 0.)
		pageSize.y = 0.;
	}
	else
	    pageSize.x = pageSize.y = 0.;
	job->pagesArraySize.x = job->pagesArraySize.y = job->numPages = 1;
        
        if (pageSize.x < imageSize.x)
	    pageSize.x = imageSize.x;
        if (pageSize.y < imageSize.y)
	    pageSize.y = imageSize.y;
    }

    /* initial window size */
//fprintf(stderr,"page=%g,%g dpi=%g,%g zoom=%g\n", pageSize.x, pageSize.y, job->dpi.x, job->dpi.y, job->zoom);
    job->width = ROUND((pageSize.x + 2*margin.x) * job->dpi.x / 72);
    job->height = ROUND((pageSize.y + 2*margin.y) * job->dpi.y / 72);

    /* set up pagedir */
    job->pagesArrayMajor.x = job->pagesArrayMajor.y 
		= job->pagesArrayMinor.x = job->pagesArrayMinor.y = 0;
    job->pagesArrayFirst.x = job->pagesArrayFirst.y = 0;
    job->pagesArrayMajor = pagecode(job, gvc->pagedir[0]);
    job->pagesArrayMinor = pagecode(job, gvc->pagedir[1]);
    if ((abs(job->pagesArrayMajor.x + job->pagesArrayMinor.x) != 1)
     || (abs(job->pagesArrayMajor.y + job->pagesArrayMinor.y) != 1)) {
	job->pagesArrayMajor = pagecode(job, 'B');
	job->pagesArrayMinor = pagecode(job, 'L');
	agerr(AGWARN, "pagedir=%s ignored\n", gvc->pagedir);
    }

    /* determine page box including centering */
    if (GD_drawing(g)->centered) {
	if (pageSize.x > imageSize.x)
	    centering.x = (pageSize.x - imageSize.x) / 2;
	if (pageSize.y > imageSize.y)
	    centering.y = (pageSize.y - imageSize.y) / 2;
    }

    /* rotate back into graph orientation */
    if (job->rotation) {
	imageSize = exch_xyf(imageSize);
	pageSize = exch_xyf(pageSize);
	margin = exch_xyf(margin);
	centering = exch_xyf(centering);
    }

    /* canvas area, centered if necessary */
    job->canvasBox.LL.x = margin.x + centering.x;
    job->canvasBox.LL.y = margin.y + centering.y;
    job->canvasBox.UR.x = margin.x + centering.x + imageSize.x;
    job->canvasBox.UR.y = margin.y + centering.y + imageSize.y;

    /* size of one page in graph units */
    job->pageSize.x = imageSize.x / job->zoom;
    job->pageSize.y = imageSize.y / job->zoom;

    /* pageBoundingBox in device units and page orientation */
    job->pageBoundingBox.LL.x = ROUND(job->canvasBox.LL.x * job->dpi.x / 72);
    job->pageBoundingBox.LL.y = ROUND(job->canvasBox.LL.y * job->dpi.y / 72);
    job->pageBoundingBox.UR.x = ROUND(job->canvasBox.UR.x * job->dpi.x / 72);
    job->pageBoundingBox.UR.y = ROUND(job->canvasBox.UR.y * job->dpi.y / 72);
    if (job->rotation) {
	job->pageBoundingBox.LL = exch_xy(job->pageBoundingBox.LL);
	job->pageBoundingBox.UR = exch_xy(job->pageBoundingBox.UR);
    }
}

static void firstpage(GVJ_t *job)
{
    job->pagesArrayElem = job->pagesArrayFirst;
}

static boolean validpage(GVJ_t *job)
{
    return ((job->pagesArrayElem.x >= 0)
	 && (job->pagesArrayElem.x < job->pagesArraySize.x)
	 && (job->pagesArrayElem.y >= 0)
	 && (job->pagesArrayElem.y < job->pagesArraySize.y));
}

static void nextpage(GVJ_t *job)
{
    job->pagesArrayElem = add_point(job->pagesArrayElem, job->pagesArrayMinor);
    if (validpage(job) == 0) {
	if (job->pagesArrayMajor.y)
	    job->pagesArrayElem.x = job->pagesArrayFirst.x;
	else
	    job->pagesArrayElem.y = job->pagesArrayFirst.y;
	job->pagesArrayElem = add_point(job->pagesArrayElem, job->pagesArrayMajor);
    }
}

static boolean write_edge_test(Agraph_t * g, Agedge_t * e)
{
    Agraph_t *sg;
    int c;

    for (c = 1; c <= GD_n_cluster(g); c++) {
	sg = GD_clust(g)[c];
	if (agcontains(sg, e))
	    return 0;
    }
    return NOT(0);
}

static boolean write_node_test(Agraph_t * g, Agnode_t * n)
{
    Agraph_t *sg;
    int c;

    for (c = 1; c <= GD_n_cluster(g); c++) {
	sg = GD_clust(g)[c];
	if (agcontains(sg, n))
	    return 0;
    }
    return NOT(0);
}



static pointf*
copyPts (pointf* pts, int* ptsize, xdot_point* inpts, int numpts)
{
    int i, sz = *ptsize;

    if (numpts > sz) {
	sz = MAX(2*sz, numpts);
	pts = RALLOC(sz, pts, pointf);
	*ptsize = sz;
    }

    for (i = 0; i < numpts; i++) {
	pts[i].x = inpts[i].x;
	pts[i].y = inpts[i].y;
    }

    return pts;
}

static void emit_xdot (GVJ_t * job, xdot* xd)
{
    int image_warn = 1;
    int ptsize = 1000;
    pointf* pts = (pointf*)gmalloc((1000)*sizeof(pointf));
    exdot_op* op;
    int i, angle;
    char** styles = 0;
    int filled = 1;

    op = (exdot_op*)(xd->ops);
    for (i = 0; i < xd->cnt; i++) {
	switch (op->op.kind) {
	case xd_filled_ellipse :
	case xd_unfilled_ellipse :
    	    if (boxf_overlap(op->bb, job->clip)) {
		pts[0].x = op->op.u.ellipse.x - op->op.u.ellipse.w;
		pts[0].y = op->op.u.ellipse.y - op->op.u.ellipse.h;
		pts[1].x = op->op.u.ellipse.w;
		pts[1].y = op->op.u.ellipse.h;
		gvrender_ellipse(job, pts, 2, (op->op.kind == xd_filled_ellipse?filled:0));
	    }
	    break;
	case xd_filled_polygon :
	case xd_unfilled_polygon :
    	    if (boxf_overlap(op->bb, job->clip)) {
		pts = copyPts (pts, &ptsize, op->op.u.polygon.pts, op->op.u.polygon.cnt);
		gvrender_polygon(job, pts, op->op.u.polygon.cnt, (op->op.kind == xd_filled_polygon?filled:0));
	    }
	    break;
	case xd_filled_bezier :
	case xd_unfilled_bezier :
    	    if (boxf_overlap(op->bb, job->clip)) {
		pts = copyPts (pts, &ptsize, op->op.u.bezier.pts, op->op.u.bezier.cnt);
		gvrender_beziercurve(job, pts, op->op.u.bezier.cnt, 0, 0, (op->op.kind == xd_filled_bezier?filled:0));
	    }
	    break;
	case xd_polyline :
    	    if (boxf_overlap(op->bb, job->clip)) {
		pts = copyPts (pts, &ptsize, op->op.u.polyline.pts, op->op.u.polyline.cnt);
		gvrender_polyline(job, pts, op->op.u.polyline.cnt);
	    }
	    break;
	case xd_text :
    	    if (boxf_overlap(op->bb, job->clip)) {
		pts[0].x = op->op.u.text.x;
		pts[0].y = op->op.u.text.y;
		gvrender_textspan(job, pts[0], op->span);
	    }
	    break;
	case xd_fill_color :
            gvrender_set_fillcolor(job, op->op.u.color);
	    filled = 1;
	    break;
	case xd_pen_color :
            gvrender_set_pencolor(job, op->op.u.color);
	    filled = 1;
	    break;
	case xd_grad_fill_color : 
	    {
		char* clr0;
		char* clr1;
		float frac;
		if (op->op.u.grad_color.type == xd_radial) {
		    xdot_radial_grad* p = &op->op.u.grad_color.u.ring;
		    clr0 = p->stops[0].color;
		    clr1 = p->stops[1].color;
		    frac = p->stops[1].frac;
		    if ((p->x1 == p->x0) && (p->y1 == p->y0))
			angle = 0;
		    else
			angle = (int)(180.0*acos((p->x0 - p->x1)/p->r0)/M_PI);
        	    gvrender_set_fillcolor(job, clr0);
		    gvrender_set_gradient_vals(job, clr1, angle, frac);
		    filled = 3;
		}
		else {
		    xdot_linear_grad* p = &op->op.u.grad_color.u.ling;
		    clr0 = p->stops[0].color;
		    clr1 = p->stops[1].color;
		    frac = p->stops[1].frac;
		    angle = (int)(180.0*atan2(p->y1-p->y0,p->x1-p->x0)/M_PI);
        	    gvrender_set_fillcolor(job, clr0);
		    gvrender_set_gradient_vals(job, clr1, angle, frac);
		    filled = 2;
		}
	    }
	    break;
	case xd_grad_pen_color :
	    agerr (AGWARN, "gradient pen colors not yet supported.\n");
	    break;
	case xd_font :
	    /* fontsize and fontname already encoded via xdotBB */
	    break;
	case xd_style :
	    styles = parse_style (op->op.u.style);
            gvrender_set_style (job, styles);
	    break;
	case xd_fontchar :
	    /* font characteristics already encoded via xdotBB */
	    break;
	case xd_image :
	    if (image_warn) {
	        agerr(AGWARN, "Images unsupported in \"background\" attribute\n");
	        image_warn = 0;
	    }
	    break;
	}
	op++;
    }
    if (styles)
	gvrender_set_style(job, job->gvc->defaultlinestyle);
    free (pts);
}

static void emit_background(GVJ_t * job, graph_t *g)
{
    xdot* xd;
    char *str;
    int dfltColor;
    
    /* if no bgcolor specified - first assume default of "white" */
    if (! ((str = agget(g, "bgcolor")) && str[0])) {
	str = "white";
	dfltColor = 1;
    }
    else
	dfltColor = 0;
    

    /* if device has no truecolor support, change "transparent" to "white" */
    if (! (job->flags & (1<<8)) && ((*(str)==*("transparent")&&!strcmp(str,"transparent")))) {
	str = "white";
	dfltColor = 1;
    }

    /* except for "transparent" on truecolor, or default "white" on (assumed) white paper, paint background */
    if (!(   ((job->flags & (1<<8)) && (*(str)==*("transparent")&&!strcmp(str,"transparent")))
          || ((job->flags & (1<<25)) && dfltColor))) {
	char* clrs[2];
	float frac;

	if ((findStopColor (str, clrs, &frac))) {
	    int filled, istyle = 0;
            gvrender_set_fillcolor(job, clrs[0]);
            gvrender_set_pencolor(job, "transparent");
	    checkClusterStyle(g, &istyle);
	    if (clrs[1]) 
		gvrender_set_gradient_vals(job,clrs[1],late_int(g,G_gradientangle,0,0), frac);
	    else 
		gvrender_set_gradient_vals(job,"black",late_int(g,G_gradientangle,0,0), frac);
	    if (istyle & (1 << 1))
		filled = 3;
	    else
		filled = 2;
	    gvrender_box(job, job->clip, filled);
	    free (clrs[0]);
	}
	else {
            gvrender_set_fillcolor(job, str);
    	    gvrender_set_pencolor(job, "transparent");
	    gvrender_box(job, job->clip, 1);	/* filled */
	}
    }

    if ((xd = (xdot*)GD_drawing(g)->xdots))
	emit_xdot (job, xd);
}

static void setup_page(GVJ_t * job, graph_t * g)
{
    point pagesArrayElem = job->pagesArrayElem, pagesArraySize = job->pagesArraySize;
	
    if (job->rotation) {
	pagesArrayElem = exch_xy(pagesArrayElem);
	pagesArraySize = exch_xy(pagesArraySize);
    }

    /* establish current box in graph units */
    job->pageBox.LL.x = pagesArrayElem.x * job->pageSize.x - job->pad.x;
    job->pageBox.LL.y = pagesArrayElem.y * job->pageSize.y - job->pad.y;
    job->pageBox.UR.x = job->pageBox.LL.x + job->pageSize.x;
    job->pageBox.UR.y = job->pageBox.LL.y + job->pageSize.y;

    /* maximum boundingBox in device units and page orientation */
    if (job->common->viewNum == 0)
        job->boundingBox = job->pageBoundingBox;
    else
        EXPANDBB(job->boundingBox, job->pageBoundingBox);

    if (job->flags & (1<<7)) {
        job->clip.LL.x = job->focus.x - job->view.x / 2.;
        job->clip.LL.y = job->focus.y - job->view.y / 2.;
        job->clip.UR.x = job->focus.x + job->view.x / 2.;
        job->clip.UR.y = job->focus.y + job->view.y / 2.;
    }
    else {
        job->clip.LL.x = job->focus.x + job->pageSize.x * (pagesArrayElem.x - pagesArraySize.x / 2.);
        job->clip.LL.y = job->focus.y + job->pageSize.y * (pagesArrayElem.y - pagesArraySize.y / 2.);
        job->clip.UR.x = job->clip.LL.x + job->pageSize.x;
        job->clip.UR.y = job->clip.LL.y + job->pageSize.y;
    }

    /* CAUTION - job->translation was difficult to get right. */
    /* Test with and without assymetric margins, e.g: -Gmargin="1,0" */
    if (job->rotation) {
	job->translation.y = - job->clip.UR.y - job->canvasBox.LL.y / job->zoom;
        if ((job->flags & (1<<12)) || (Y_invert))
            job->translation.x = - job->clip.UR.x - job->canvasBox.LL.x / job->zoom;
        else
            job->translation.x = - job->clip.LL.x + job->canvasBox.LL.x / job->zoom;
    }
    else {
	/* pre unscale margins to keep them constant under scaling */
        job->translation.x = - job->clip.LL.x + job->canvasBox.LL.x / job->zoom;
        if ((job->flags & (1<<12)) || (Y_invert))
            job->translation.y = - job->clip.UR.y - job->canvasBox.LL.y / job->zoom;
        else
            job->translation.y = - job->clip.LL.y + job->canvasBox.LL.y / job->zoom;
    }



	
	
	
	
	
	
	
	
	
	
	
	
	
	

}

static boolean node_in_layer(GVJ_t *job, graph_t * g, node_t * n)
{
    char *pn, *pe;
    edge_t *e;

    if (job->numLayers <= 1)
	return NOT(0);
    pn = late_string(n, N_layer, "");
    if (selectedlayer(job, pn))
	return NOT(0);
    if (pn[0])
	return 0;		/* Only check edges if pn = "" */
    if ((e = agfstedge(g, n)) == NULL)
	return NOT(0);
    for (e = agfstedge(g, n); e; e = agnxtedge(g, e, n)) {
	pe = late_string(e, E_layer, "");
	if ((pe[0] == '\0') || selectedlayer(job, pe))
	    return NOT(0);
    }
    return 0;
}

static boolean edge_in_layer(GVJ_t *job, graph_t * g, edge_t * e)
{
    char *pe, *pn;
    int cnt;

    if (job->numLayers <= 1)
	return NOT(0);
    pe = late_string(e, E_layer, "");
    if (selectedlayer(job, pe))
	return NOT(0);
    if (pe[0])
	return 0;
    for (cnt = 0; cnt < 2; cnt++) {
	pn = late_string(cnt < 1 ? agtail(e) : aghead(e), N_layer, "");
	if ((pn[0] == '\0') || selectedlayer(job, pn))
	    return NOT(0);
    }
    return 0;
}

static boolean clust_in_layer(GVJ_t *job, graph_t * sg)
{
    char *pg;
    node_t *n;

    if (job->numLayers <= 1)
	return NOT(0);
    pg = late_string(sg, agattr(sg, AGRAPH, "layer", 0), "");
    if (selectedlayer(job, pg))
	return NOT(0);
    if (pg[0])
	return 0;
    for (n = agfstnode(sg); n; n = agnxtnode(sg, n))
	if (node_in_layer(job, sg, n))
	    return NOT(0);
    return 0;
}

static boolean node_in_box(node_t *n, boxf b)
{
    return boxf_overlap(ND_bb(n), b);
}

static void emit_begin_node(GVJ_t * job, node_t * n)
{
    obj_state_t *obj;
    int flags = job->flags;
    int sides, peripheries, i, j, filled = 0, rect = 0, shape, nump = 0;
    polygon_t *poly = NULL;
    pointf *vertices, *p = NULL;
    pointf coord;
    char *s;

    obj = push_obj_state(job);
    obj->type = NODE_OBJTYPE;
    obj->u.n = n;
    obj->emit_state = EMIT_NDRAW;

    if (flags & (1<<24)) {
        /* obj->z = late_double(n, N_z, 0.0, -MAXFLOAT); */
	if (GD_odim(agraphof(n)) >=3)
            obj->z = (ROUND((ND_pos(n)[2])*72));
	else
            obj->z = 0.0;
    }
    initObjMapData (job, ND_label(n), n);
    if ((flags & ((1<<16) | (1<<22)))
           && (obj->url || obj->explicit_tooltip)) {

        /* checking shape of node */
        shape = shapeOf(n);
        /* node coordinate */
        coord = ND_coord(n);
        /* checking if filled style has been set for node */
        filled = ifFilled(n);

        if (shape == SH_POLY || shape == SH_POINT) {
            poly = (polygon_t *) ND_shape_info(n);

            /* checking if polygon is regular rectangle */
            if (isRect(poly) && (poly->peripheries || filled))
                rect = 1;
        }

        /* When node has polygon shape and requested output supports polygons
         * we use a polygon to map the clickable region that is a:
         * circle, ellipse, polygon with n side, or point.
         * For regular rectangular shape we have use node's bounding box to map clickable region
         */
        if (poly && !rect && (flags & (1<<19))) {

            if (poly->sides < 3)
                sides = 1;
            else
                sides = poly->sides;

            if (poly->peripheries < 2)
                peripheries = 1;
            else
                peripheries = poly->peripheries;

            vertices = poly->vertices;

            if ((s = agget(n, "samplepoints")))
                nump = atoi(s);
            /* We want at least 4 points. For server-side maps, at most 100
             * points are allowed. To simplify things to fit with the 120 points
             * used for skewed ellipses, we set the bound at 60.
             */
            if ((nump < 4) || (nump > 60))
                nump = 20;
            /* use bounding box of text label or node image for mapping
             * when polygon has no peripheries and node is not filled
             */
            if (poly->peripheries == 0 && !filled) {
                obj->url_map_shape = MAP_RECTANGLE;
                nump = 2;
                p = (pointf*)zmalloc((nump)*sizeof(pointf));
                (p[0].x = coord.x - ND_lw(n), p[0].y = coord.y - ND_ht(n) / 2.0, p[1].x = coord.x + ND_lw(n), p[1].y = coord.y + ND_ht(n) / 2.0);
            }
            /* circle or ellipse */
            else if (poly->sides < 3 && poly->skew == 0.0 && poly->distortion == 0.0) {
                if (poly->regular) {
                    obj->url_map_shape = MAP_CIRCLE;
                    nump = 2;              /* center of circle and top right corner of bb */
                    p = (pointf*)zmalloc((nump)*sizeof(pointf));
                    p[0].x = coord.x;
                    p[0].y = coord.y;
		    /* even vertices contain LL corner of bb */
		    /* odd vertices contain UR corner of bb */
                    p[1].x = coord.x + vertices[2*peripheries - 1].x;
                    p[1].y = coord.y + vertices[2*peripheries - 1].y;
                }
                else { /* ellipse is treated as polygon */
                    obj->url_map_shape= MAP_POLYGON;
                    p = pEllipse((double)(vertices[2*peripheries - 1].x),
                                 (double)(vertices[2*peripheries - 1].y), nump);
                    for (i = 0; i < nump; i++) {
                        p[i].x += coord.x;
                        p[i].y += coord.y;
                    }
		}
            }
            /* all other polygonal shape */
            else {
                int offset = (peripheries - 1)*(poly->sides);
                obj->url_map_shape = MAP_POLYGON;
                /* distorted or skewed ellipses and circles are polygons with 120
                 * sides. For mapping we convert them into polygon with sample sides
                 */
                if (poly->sides >= nump) {
                    int delta = poly->sides / nump;
                    p = (pointf*)zmalloc((nump)*sizeof(pointf));
                    for (i = 0, j = 0; j < nump; i += delta, j++) {
                        p[j].x = coord.x + vertices[i + offset].x;
                        p[j].y = coord.y + vertices[i + offset].y;
                    }
                } else {
                    nump = sides;
                    p = (pointf*)zmalloc((nump)*sizeof(pointf));
                    for (i = 0; i < nump; i++) {
                        p[i].x = coord.x + vertices[i + offset].x;
                        p[i].y = coord.y + vertices[i + offset].y;
                    }
                }
            }
        }
        else {
            /* we have to use the node's bounding box to map clickable region
             * when requested output format is not capable of polygons.
             */
            obj->url_map_shape = MAP_RECTANGLE;
            nump = 2;
            p = (pointf*)zmalloc((nump)*sizeof(pointf));
            p[0].x = coord.x - ND_lw(n);
            p[0].y = coord.y - (ND_ht(n) / 2);
            p[1].x = coord.x + ND_rw(n);
            p[1].y = coord.y + (ND_ht(n) / 2);
        }
        if (! (flags & (1<<13)))
            gvrender_ptf_A(job, p, p, nump);
        obj->url_map_p = p;
        obj->url_map_n = nump;
    }

    setColorScheme (agget (n, "colorscheme"));
    gvrender_begin_node(job, n);
}

static void emit_end_node(GVJ_t * job)
{
    gvrender_end_node(job);
    pop_obj_state(job);
}

/* emit_node:
 */
static void emit_node(GVJ_t * job, node_t * n)
{
    GVC_t *gvc = job->gvc;
    char *s;
    char *style;
    char **styles = 0;
    char **sp;
    char *p;

    if (ND_shape(n) 				     /* node has a shape */
	    && node_in_layer(job, agraphof(n), n)    /* and is in layer */
	    && node_in_box(n, job->clip)             /* and is in page/view */
	    && (ND_state(n) != gvc->common.viewNum)) /* and not already drawn */
    {
	ND_state(n) = gvc->common.viewNum; 	     /* mark node as drawn */

        gvrender_comment(job, agnameof(n));
	s = late_string(n, N_comment, "");
	if (s[0])
	    gvrender_comment(job, s);
        
	style = late_string(n, N_style, "");
	if (style[0]) {
	    styles = parse_style(style);
	    sp = styles;
	    while ((p = *sp++)) {
		if ((*(p)==*("invis")&&!strcmp(p,"invis"))) return;
	    }
	}

	emit_begin_node(job, n);
	ND_shape(n)->fns->codefn(job, n);
	if (ND_xlabel(n) && ND_xlabel(n)->set)
	    emit_label(job, EMIT_NLABEL, ND_xlabel(n));
	emit_end_node(job);
    }
}

/* calculate an offset vector, length d, perpendicular to line p,q */
static pointf computeoffset_p(pointf p, pointf q, double d)
{
    pointf res;
    double x = p.x - q.x, y = p.y - q.y;

    /* keep d finite as line length approaches 0 */
    d /= sqrt(x * x + y * y + .0001);
    res.x = y * d;
    res.y = -x * d;
    return res;
}

/* calculate offset vector, length d, perpendicular to spline p,q,r,s at q&r */
static pointf computeoffset_qr(pointf p, pointf q, pointf r, pointf s,
			       double d)
{
    pointf res;
    double len;
    double x = q.x - r.x, y = q.y - r.y;

    len = sqrt(x * x + y * y);
    if (len < .0001) {
	/* control points are on top of each other
	   use slope between endpoints instead */
	x = p.x - s.x, y = p.y - s.y;
	/* keep d finite as line length approaches 0 */
	len = sqrt(x * x + y * y + .0001);
    }
    d /= len;
    res.x = y * d;
    res.y = -x * d;
    return res;
}

static void emit_attachment(GVJ_t * job, textlabel_t * lp, splines * spl)
{
    pointf sz, AF[3];
    unsigned char *s;

    for (s = (unsigned char *) (lp->text); *s; s++) {
	if (isspace(*s) == 0)
	    break;
    }
    if (*s == 0)
	return;

    sz = lp->dimen;
    AF[0] = pointfof(lp->pos.x + sz.x / 2., lp->pos.y - sz.y / 2.);
    AF[1] = pointfof(AF[0].x - sz.x, AF[0].y);
    AF[2] = dotneato_closest(spl, lp->pos);
    /* Don't use edge style to draw attachment */
    gvrender_set_style(job, job->gvc->defaultlinestyle);
    /* Use font color to draw attachment
       - need something unambiguous in case of multicolored parallel edges
       - defaults to black for html-like labels
     */
    gvrender_set_pencolor(job, lp->fontcolor);
    gvrender_polyline(job, AF, 3);
}

/* edges colors can be mutiple colors separated by ":"
 * so we commpute a default pencolor with the same number of colors. */
static char* default_pencolor(char *pencolor, char *deflt)
{
    static char *buf;
    static int bufsz;
    char *p;
    int len, ncol;

    ncol = 1;
    for (p = pencolor; *p; p++) {
	if (*p == ':')
	    ncol++;
    }
    len = ncol * (strlen(deflt) + 1);
    if (bufsz < len) {
	bufsz = len + 10;
	buf = realloc(buf, bufsz);
    }
    strcpy(buf, deflt);
    while(--ncol) {
	strcat(buf, ":");
	strcat(buf, deflt);
    }
    return buf;
}

/* approxLen:
 */
static double approxLen (pointf* pts)
{
    double d = DIST(pts[0],pts[1]);
    d += DIST(pts[1],pts[2]);
    d += DIST(pts[2],pts[3]);
    return d;
}
 
/* splitBSpline:
 * Given B-spline bz and 0 < t < 1, split bz so that left corresponds to
 * the fraction t of the arc length. The new parts are store in left and right.
 * The caller needs to free the allocated points.
 *
 * In the current implementation, we find the Bezier that should contain t by
 * treating the control points as a polyline.
 * We then split that Bezier.
 */
static void splitBSpline (bezier* bz, float t, bezier* left, bezier* right)
{
    int i, j, k, cnt = (bz->size - 1)/3;
    double* lens;
    double last, len, sum;
    pointf* pts;
    float r;

    if (cnt == 1) {
	left->size = 4;
	left->list = (pointf*)zmalloc((4)*sizeof(pointf));
	right->size = 4;
	right->list = (pointf*)zmalloc((4)*sizeof(pointf));
	Bezier (bz->list, 3, t, left->list, right->list);
	return;
    }
    
    lens = (double*)zmalloc((cnt)*sizeof(double));
    sum = 0;
    pts = bz->list;
    for (i = 0; i < cnt; i++) {
	lens[i] = approxLen (pts);
	sum += lens[i];
	pts += 3;
    }
    len = t*sum;
    sum = 0;
    for (i = 0; i < cnt; i++) {
	sum += lens[i];
	if (sum >= len)
	    break;
    }

    left->size = 3*(i+1) + 1;
    left->list = (pointf*)zmalloc((left->size)*sizeof(pointf));
    right->size = 3*(cnt-i) + 1;
    right->list = (pointf*)zmalloc((right->size)*sizeof(pointf));
    for (j = 0; j < left->size; j++)
	left->list[j] = bz->list[j];
    k = j - 4;
    for (j = 0; j < right->size; j++)
	right->list[j] = bz->list[k++];

    last = lens[i];
    r = (len - (sum - last))/last;
    Bezier (bz->list + 3*i, 3, r, left->list + 3*i, right->list);

    free (lens);
}

/* multicolor:
 * Draw an edge as a sequence of colors.
 * Not sure how to handle multiple B-splines, so do a naive
 * implementation.
 * Return non-zero if color spec is incorrect
 */
static int multicolor (GVJ_t * job, edge_t * e, char** styles, char* colors, int num, double arrowsize, double penwidth)
{ 
    bezier bz;
    bezier bz0, bz_l, bz_r;
    int i, rv;
    colorsegs_t* segs;
    colorseg_t* s;
    char* endcolor;
    double left;
    int first;  /* first segment with t > 0 */

    rv = parseSegs (colors, num, &segs);
    if (rv > 1) {
	Agraph_t* g = agraphof(agtail(e));
	agerr (AGPREV, "in edge %s%s%s\n", agnameof(agtail(e)), (agisdirected(g)?" -> ":" -- "), agnameof(aghead(e)));

	if (rv == 2)
	    return 1;
    }
    else if (rv == 1)
	return 1;
    

    for (i = 0; i < ED_spl(e)->size; i++) {
	left = 1;
	bz = ED_spl(e)->list[i];
	first = 1;
	for (s = segs->segs; s->color; s++) {
	    if ((((s->t) < 1E-5) && ((s->t) > -1E-5))) continue;
    	    gvrender_set_pencolor(job, s->color);
	    left -= s->t;
	    endcolor = s->color;
	    if (first) {
		first = 0;
		splitBSpline (&bz, s->t, &bz_l, &bz_r);
		gvrender_beziercurve(job, bz_l.list, bz_l.size, 0, 0, 0);
		free (bz_l.list);
		if ((((left) < 1E-5) && ((left) > -1E-5))) {
		    free (bz_r.list);
		    break;
		}
	    }
	    else if ((((left) < 1E-5) && ((left) > -1E-5))) {
		gvrender_beziercurve(job, bz_r.list, bz_r.size, 0, 0, 0);
		free (bz_r.list);
		break;
	    }
	    else {
		bz0 = bz_r;
		splitBSpline (&bz0, (s->t)/(left+s->t), &bz_l, &bz_r);
		free (bz0.list);
		gvrender_beziercurve(job, bz_l.list, bz_l.size, 0, 0, 0);
		free (bz_l.list);
	    }
		
	}
                /* arrow_gen resets the job style  (How?  FIXME)
                 * If we have more splines to do, restore the old one.
                 * Use local copy of penwidth to work around reset.
                 */
	if (bz.sflag) {
    	    gvrender_set_pencolor(job, segs->segs->color);
    	    gvrender_set_fillcolor(job, segs->segs->color);
	    arrow_gen(job, EMIT_TDRAW, bz.sp, bz.list[0], arrowsize, penwidth, bz.sflag);
	}
	if (bz.eflag) {
    	    gvrender_set_pencolor(job, endcolor);
    	    gvrender_set_fillcolor(job, endcolor);
	    arrow_gen(job, EMIT_HDRAW, bz.ep, bz.list[bz.size - 1], arrowsize, penwidth, bz.eflag);
	}
	if ((ED_spl(e)->size>1) && (bz.sflag||bz.eflag) && styles) 
	    gvrender_set_style(job, styles);
    }
    free (segs);
    return 0;
}

static void free_stroke (stroke_t* sp)
{
    if (sp) {
	free (sp->vertices);
	free (sp);
    }
}

typedef double (*radfunc_t)(double,double,double);

static double forfunc (double curlen, double totallen, double initwid)
{
    return ((1 - (curlen/totallen))*initwid/2.0);
}

static double revfunc (double curlen, double totallen, double initwid)
{
    return (((curlen/totallen))*initwid/2.0);
}

static double nonefunc (double curlen, double totallen, double initwid)
{
    return (initwid/2.0);
}

static double bothfunc (double curlen, double totallen, double initwid)
{
    double fr = curlen/totallen;
    if (fr <= 0.5) return (fr*initwid);
    else return ((1-fr)*initwid);
}

static radfunc_t 
taperfun (edge_t* e)
{
    char* attr;
    if (E_dir && ((attr = agxget(e, E_dir)))[0]) {
	if ((*(attr)==*("forward")&&!strcmp(attr,"forward"))) return forfunc;
	if ((*(attr)==*("back")&&!strcmp(attr,"back"))) return revfunc;
	if ((*(attr)==*("both")&&!strcmp(attr,"both"))) return bothfunc;
	if ((*(attr)==*("none")&&!strcmp(attr,"none"))) return nonefunc;
    }
    return (agisdirected(agraphof(aghead(e))) ? forfunc : nonefunc);
}

static void emit_edge_graphics(GVJ_t * job, edge_t * e, char** styles)
{
    int i, j, cnum, numc = 0, numsemi = 0;
    char *color, *pencolor, *fillcolor;
    char *headcolor, *tailcolor, *lastcolor;
    char *colors = NULL;
    bezier bz;
    splines offspl, tmpspl;
    pointf pf0, pf1, pf2 = { 0, 0 }, pf3, *offlist, *tmplist;
    double arrowsize, numc2, penwidth=job->obj->penwidth;
    char* p;
    boolean tapered = 0;



    setColorScheme (agget (e, "colorscheme"));
    if (ED_spl(e)) {
	arrowsize = late_double(e, E_arrowsz, 1.0, 0.0);
	color = late_string(e, E_color, "");

	if (styles) {
	    char** sp = styles;
	    while ((p = *sp++)) {
		if ((*(p)==*("tapered")&&!strcmp(p,"tapered"))) {
		    tapered = 1;
		    break;
		}
	    }
	}

	/* need to know how many colors separated by ':' */
	for (p = color; *p; p++) {
	    if (*p == ':')
		numc++;
	    else if (*p == ';')
		numsemi++;
	}

	if (numsemi && numc) {
	    if (multicolor (job, e, styles, color, numc+1, arrowsize, penwidth)) {
		color = "black";
	    }
	    else
		return;
	}

	fillcolor = pencolor = color;
	if (ED_gui_state(e) & (1<<0)) {
	    pencolor = late_nnstring(e, E_activepencolor,
			default_pencolor(pencolor, "#808080"));
	    fillcolor = late_nnstring(e, E_activefillcolor, "#fcfcfc");
	}
	else if (ED_gui_state(e) & (1<<1)) {
	    pencolor = late_nnstring(e, E_selectedpencolor,
			default_pencolor(pencolor, "#303030"));
	    fillcolor = late_nnstring(e, E_selectedfillcolor, "#e8e8e8");
	}
	else if (ED_gui_state(e) & (1<<3)) {
	    pencolor = late_nnstring(e, E_deletedpencolor,
			default_pencolor(pencolor, "#e0e0e0"));
	    fillcolor = late_nnstring(e, E_deletedfillcolor, "#f0f0f0");
	}
	else if (ED_gui_state(e) & (1<<2)) {
	    pencolor = late_nnstring(e, E_visitedpencolor,
			default_pencolor(pencolor, "#101010"));
	    fillcolor = late_nnstring(e, E_visitedfillcolor, "#f8f8f8");
	}
	else
	    fillcolor = late_nnstring(e, E_fillcolor, color);
	if (pencolor != color)
    	    gvrender_set_pencolor(job, pencolor);
	if (fillcolor != color)
	    gvrender_set_fillcolor(job, fillcolor);
	color = pencolor;

	if (tapered) {
	    stroke_t* stp;
	    if (*color == '\0') color = "black";
	    if (*fillcolor == '\0') fillcolor = "black";
    	    gvrender_set_pencolor(job, "transparent");
	    gvrender_set_fillcolor(job, color);
	    bz = ED_spl(e)->list[0];
	    stp = taper (&bz, taperfun (e), penwidth, 0, 0);
	    gvrender_polygon(job, stp->vertices, stp->nvertices, NOT(0));
	    free_stroke (stp);
    	    gvrender_set_pencolor(job, color);
	    if (fillcolor != color)
		gvrender_set_fillcolor(job, fillcolor);
	    if (bz.sflag) {
		arrow_gen(job, EMIT_TDRAW, bz.sp, bz.list[0], arrowsize, penwidth, bz.sflag);
	    }
	    if (bz.eflag) {
		arrow_gen(job, EMIT_HDRAW, bz.ep, bz.list[bz.size - 1], arrowsize, penwidth, bz.eflag);
	    }
	}
	/* if more than one color - then generate parallel beziers, one per color */
	else if (numc) {
	    /* calculate and save offset vector spline and initialize first offset spline */
	    tmpspl.size = offspl.size = ED_spl(e)->size;
	    offspl.list = malloc(sizeof(bezier) * offspl.size);
	    tmpspl.list = malloc(sizeof(bezier) * tmpspl.size);
	    numc2 = (2 + numc) / 2.0;
	    for (i = 0; i < offspl.size; i++) {
		bz = ED_spl(e)->list[i];
		tmpspl.list[i].size = offspl.list[i].size = bz.size;
		offlist = offspl.list[i].list = malloc(sizeof(pointf) * bz.size);
		tmplist = tmpspl.list[i].list = malloc(sizeof(pointf) * bz.size);
		pf3 = bz.list[0];
		for (j = 0; j < bz.size - 1; j += 3) {
		    pf0 = pf3;
		    pf1 = bz.list[j + 1];
		    /* calculate perpendicular vectors for each bezier point */
		    if (j == 0)	/* first segment, no previous pf2 */
			offlist[j] = computeoffset_p(pf0, pf1, 2.0);
		    else	/* i.e. pf2 is available from previous segment */
			offlist[j] = computeoffset_p(pf2, pf1, 2.0);
		    pf2 = bz.list[j + 2];
		    pf3 = bz.list[j + 3];
		    offlist[j + 1] = offlist[j + 2] =
			computeoffset_qr(pf0, pf1, pf2, pf3, 2.0);
		    /* initialize tmpspl to outermost position */
		    tmplist[j].x = pf0.x - numc2 * offlist[j].x;
		    tmplist[j].y = pf0.y - numc2 * offlist[j].y;
		    tmplist[j + 1].x = pf1.x - numc2 * offlist[j + 1].x;
		    tmplist[j + 1].y = pf1.y - numc2 * offlist[j + 1].y;
		    tmplist[j + 2].x = pf2.x - numc2 * offlist[j + 2].x;
		    tmplist[j + 2].y = pf2.y - numc2 * offlist[j + 2].y;
		}
		/* last segment, no next pf1 */
		offlist[j] = computeoffset_p(pf2, pf3, 2.0);
		tmplist[j].x = pf3.x - numc2 * offlist[j].x;
		tmplist[j].y = pf3.y - numc2 * offlist[j].y;
	    }
	    lastcolor = headcolor = tailcolor = color;
	    colors = strdup(color);
	    for (cnum = 0, color = strtok(colors, ":"); color;
		cnum++, color = strtok(0, ":")) {
		if (!color[0])
		    color = "black";
		if (color != lastcolor) {
	            if (! (ED_gui_state(e) & ((1<<0) | (1<<1)))) {
		        gvrender_set_pencolor(job, color);
		        gvrender_set_fillcolor(job, color);
		    }
		    lastcolor = color;
		}
		if (cnum == 0)
		    headcolor = tailcolor = color;
		if (cnum == 1)
		    tailcolor = color;
		for (i = 0; i < tmpspl.size; i++) {
		    tmplist = tmpspl.list[i].list;
		    offlist = offspl.list[i].list;
		    for (j = 0; j < tmpspl.list[i].size; j++) {
			tmplist[j].x += offlist[j].x;
			tmplist[j].y += offlist[j].y;
		    }
		    gvrender_beziercurve(job, tmplist, tmpspl.list[i].size,
					 0, 0, 0);
		}
	    }
	    if (bz.sflag) {
		if (color != tailcolor) {
		    color = tailcolor;
	            if (! (ED_gui_state(e) & ((1<<0) | (1<<1)))) {
		        gvrender_set_pencolor(job, color);
		        gvrender_set_fillcolor(job, color);
		    }
		}
		arrow_gen(job, EMIT_TDRAW, bz.sp, bz.list[0],
			arrowsize, penwidth, bz.sflag);
	    }
	    if (bz.eflag) {
		if (color != headcolor) {
		    color = headcolor;
	            if (! (ED_gui_state(e) & ((1<<0) | (1<<1)))) {
		        gvrender_set_pencolor(job, color);
		        gvrender_set_fillcolor(job, color);
		    }
		}
		arrow_gen(job, EMIT_HDRAW, bz.ep, bz.list[bz.size - 1],
			arrowsize, penwidth, bz.eflag);
	    }
	    free(colors);
	    for (i = 0; i < offspl.size; i++) {
		free(offspl.list[i].list);
		free(tmpspl.list[i].list);
	    }
	    free(offspl.list);
	    free(tmpspl.list);
	} else {
	    if (! (ED_gui_state(e) & ((1<<0) | (1<<1)))) {
	        if (color[0]) {
		    gvrender_set_pencolor(job, color);
		    gvrender_set_fillcolor(job, fillcolor);
	        } else {
		    gvrender_set_pencolor(job, "black");
		    if (fillcolor[0])
			gvrender_set_fillcolor(job, fillcolor);
		    else
			gvrender_set_fillcolor(job, "black");
	        }
	    }
	    for (i = 0; i < ED_spl(e)->size; i++) {
		bz = ED_spl(e)->list[i];
		if (job->flags & (1<<14)) {
		    gvrender_beziercurve(job, bz.list, bz.size, bz.sflag, bz.eflag, 0);
		} else {
		    gvrender_beziercurve(job, bz.list, bz.size, 0, 0, 0);
		    if (bz.sflag) {
			arrow_gen(job, EMIT_TDRAW, bz.sp, bz.list[0],
				arrowsize, penwidth, bz.sflag);
		    }
		    if (bz.eflag) {
			arrow_gen(job, EMIT_HDRAW, bz.ep, bz.list[bz.size - 1],
				arrowsize, penwidth, bz.eflag);
		    }
		    if ((ED_spl(e)->size>1) && (bz.sflag||bz.eflag) && styles) 
			gvrender_set_style(job, styles);
		}
	    }
	}
    }
}

static boolean edge_in_box(edge_t *e, boxf b)
{
    splines *spl;
    textlabel_t *lp;

    spl = ED_spl(e);
    if (spl && boxf_overlap(spl->bb, b))
        return NOT(0);

    lp = ED_label(e);
    if (lp && overlap_label(lp, b))
        return NOT(0);

    lp = ED_xlabel(e);
    if (lp && lp->set && overlap_label(lp, b))
        return NOT(0);

    return 0;
}

static void emit_begin_edge(GVJ_t * job, edge_t * e, char** styles)
{
    obj_state_t *obj;
    int flags = job->flags;
    char *s;
    textlabel_t *lab = NULL, *tlab = NULL, *hlab = NULL;
    pointf *pbs = NULL;
    int	i, nump, *pbs_n = NULL, pbs_poly_n = 0;
    char* dflt_url = NULL;
    char* dflt_target = NULL;
    double penwidth;

    obj = push_obj_state(job);
    obj->type = EDGE_OBJTYPE;
    obj->u.e = e;
    obj->emit_state = EMIT_EDRAW;

    /* We handle the edge style and penwidth here because the width
     * is needed below for calculating polygonal image maps
     */
    if (styles && ED_spl(e)) gvrender_set_style(job, styles);

    if (E_penwidth && ((s=agxget(e,E_penwidth)) && s[0])) {
	penwidth = late_double(e, E_penwidth, 1.0, 0.0);
	gvrender_set_penwidth(job, penwidth);
    }

    if (flags & (1<<24)) {
        /* obj->tail_z = late_double(agtail(e), N_z, 0.0, -1000.0); */
        /* obj->head_z = late_double(aghead(e), N_z, 0.0, -MAXFLOAT); */
	if (GD_odim(agraphof(agtail(e))) >=3) {
            obj->tail_z = (ROUND((ND_pos(agtail(e))[2])*72));
            obj->head_z = (ROUND((ND_pos(aghead(e))[2])*72));
	} else {
            obj->tail_z = obj->head_z = 0.0;
	}
    }

    if (flags & (1<<15)) {
	if ((lab = ED_label(e)))
	    obj->label = lab->text;
	obj->taillabel = obj->headlabel = obj->xlabel = obj->label;
	if ((tlab = ED_xlabel(e)))
	    obj->xlabel = tlab->text;
	if ((tlab = ED_tail_label(e)))
	    obj->taillabel = tlab->text;
	if ((hlab = ED_head_label(e)))
	    obj->headlabel = hlab->text;
    }

    if (flags & (1<<16)) {
	agxbuf xb;
	unsigned char xbuf[128];

	agxbinit(&xb, 128, xbuf);
	s = getObjId (job, e, &xb);
	obj->id = strdup_and_subst_obj(s, (void*)e);
	agxbfree(&xb);

        if (((s = agget(e, "href")) && s[0]) || ((s = agget(e, "URL")) && s[0]))
            dflt_url = strdup_and_subst_obj(s, (void*)e);
	if (((s = agget(e, "edgehref")) && s[0]) || ((s = agget(e, "edgeURL")) && s[0]))
            obj->url = strdup_and_subst_obj(s, (void*)e);
	else if (dflt_url)
	    obj->url = strdup(dflt_url);
	if (((s = agget(e, "labelhref")) && s[0]) || ((s = agget(e, "labelURL")) && s[0]))
            obj->labelurl = strdup_and_subst_obj(s, (void*)e);
	else if (dflt_url)
	    obj->labelurl = strdup(dflt_url);
	if (((s = agget(e, "tailhref")) && s[0]) || ((s = agget(e, "tailURL")) && s[0])) {
            obj->tailurl = strdup_and_subst_obj(s, (void*)e);
            obj->explicit_tailurl = NOT(0);
	}
	else if (dflt_url)
	    obj->tailurl = strdup(dflt_url);
	if (((s = agget(e, "headhref")) && s[0]) || ((s = agget(e, "headURL")) && s[0])) {
            obj->headurl = strdup_and_subst_obj(s, (void*)e);
            obj->explicit_headurl = NOT(0);
	}
	else if (dflt_url)
	    obj->headurl = strdup(dflt_url);
    } 

    if (flags & (1<<23)) {
        if ((s = agget(e, "target")) && s[0])
            dflt_target = strdup_and_subst_obj(s, (void*)e);
        if ((s = agget(e, "edgetarget")) && s[0]) {
	    obj->explicit_edgetarget = NOT(0);
            obj->target = strdup_and_subst_obj(s, (void*)e);
	}
	else if (dflt_target)
	    obj->target = strdup(dflt_target);
        if ((s = agget(e, "labeltarget")) && s[0])
            obj->labeltarget = strdup_and_subst_obj(s, (void*)e);
	else if (dflt_target)
	    obj->labeltarget = strdup(dflt_target);
        if ((s = agget(e, "tailtarget")) && s[0]) {
            obj->tailtarget = strdup_and_subst_obj(s, (void*)e);
	    obj->explicit_tailtarget = NOT(0);
	}
	else if (dflt_target)
	    obj->tailtarget = strdup(dflt_target);
        if ((s = agget(e, "headtarget")) && s[0]) {
	    obj->explicit_headtarget = NOT(0);
            obj->headtarget = strdup_and_subst_obj(s, (void*)e);
	}
	else if (dflt_target)
	    obj->headtarget = strdup(dflt_target);
    } 

    if (flags & (1<<22)) {
        if (((s = agget(e, "tooltip")) && s[0]) ||
            ((s = agget(e, "edgetooltip")) && s[0])) {
            obj->tooltip = strdup_and_subst_obj(s, (void*)e);
	    obj->explicit_tooltip = NOT(0);
	}
	else if (obj->label)
	    obj->tooltip = strdup(obj->label);

        if ((s = agget(e, "labeltooltip")) && s[0]) {
            obj->labeltooltip = strdup_and_subst_obj(s, (void*)e);
	    obj->explicit_labeltooltip = NOT(0);
	}
	else if (obj->label)
	    obj->labeltooltip = strdup(obj->label);

        if ((s = agget(e, "tailtooltip")) && s[0]) {
            obj->tailtooltip = strdup_and_subst_obj(s, (void*)e);
	    obj->explicit_tailtooltip = NOT(0);
	}
	else if (obj->taillabel)
	    obj->tailtooltip = strdup(obj->taillabel);

        if ((s = agget(e, "headtooltip")) && s[0]) {
            obj->headtooltip = strdup_and_subst_obj(s, (void*)e);
	    obj->explicit_headtooltip = NOT(0);
	}
	else if (obj->headlabel)
	    obj->headtooltip = strdup(obj->headlabel);
    } 
    
    free (dflt_url);
    free (dflt_target);

    if (flags & ((1<<16) | (1<<22))) {
	if (ED_spl(e) && (obj->url || obj->tooltip) && (flags & (1<<19))) {
	    int ns;
	    splines *spl;
	    double w2 = MAX(job->obj->penwidth/2.0,2.0);

	    spl = ED_spl(e);
	    ns = spl->size; /* number of splines */
	    for (i = 0; i < ns; i++)
		map_output_bspline (&pbs, &pbs_n, &pbs_poly_n, spl->list+i, w2);
	    obj->url_bsplinemap_poly_n = pbs_poly_n;
	    obj->url_bsplinemap_n = pbs_n;
	    if (! (flags & (1<<13))) {
    		for ( nump = 0, i = 0; i < pbs_poly_n; i++)
        	    nump += pbs_n[i];
		gvrender_ptf_A(job, pbs, pbs, nump);		
	    }
	    obj->url_bsplinemap_p = pbs;
	    obj->url_map_shape = MAP_POLYGON;
	    obj->url_map_p = pbs;
	    obj->url_map_n = pbs_n[0];
	}
    }

    gvrender_begin_edge(job, e);
    if (obj->url || obj->explicit_tooltip)
	gvrender_begin_anchor(job,
		obj->url, obj->tooltip, obj->target, obj->id);
}

static void
emit_edge_label(GVJ_t* job, textlabel_t* lbl, emit_state_t lkind, int explicit,
    char* url, char* tooltip, char* target, char *id, splines* spl)
{
    int flags = job->flags;
    emit_state_t old_emit_state;
    char* newid;
    char* type;

    if ((lbl == NULL) || !(lbl->set)) return;
    if (id) { /* non-NULL if needed */
	newid = (char*)zmalloc((strlen(id) + sizeof("-headlabel"))*sizeof(char));
	switch (lkind) {
	case EMIT_ELABEL :
	    type = "label";
	    break;
	case EMIT_HLABEL :
	    type = "headlabel";
	    break;
	case EMIT_TLABEL :
	    type = "taillabel";
	    break;
	default :
	    assert (0);
	    break;
	}
	sprintf (newid, "%s-%s", id, type);
    }
    else
	newid = NULL;
    old_emit_state = job->obj->emit_state;
    job->obj->emit_state = lkind;
    if ((url || explicit) && !(flags & (1<<2))) {
	map_label(job, lbl);
	gvrender_begin_anchor(job, url, tooltip, target, newid);
    }
    emit_label(job, lkind, lbl);
    if (spl) emit_attachment(job, lbl, spl);
    if (url || explicit) {
	if (flags & (1<<2)) {
	    map_label(job, lbl);
	    gvrender_begin_anchor(job, url, tooltip, target, newid);
	}
	gvrender_end_anchor(job);
    }
    if (newid) free (newid);
    job->obj->emit_state = old_emit_state;
}

/* nodeIntersect:
 * Common logic for setting hot spots at the beginning and end of 
 * an edge.
 * If we are given a value (url, tooltip, target) explicitly set for
 * the head/tail, we use that. 
 * Otherwise, if we are given a value explicitly set for the edge,
 * we use that.
 * Otherwise, we use whatever the argument value is.
 * We also note whether or not the tooltip was explicitly set.
 * If the url is non-NULL or the tooltip was explicit, we set
 * a hot spot around point p.
 */
static void nodeIntersect (GVJ_t * job, pointf p, 
    boolean explicit_iurl, char* iurl,
    boolean explicit_itooltip, char* itooltip,
    boolean explicit_itarget, char* itarget)
{
    obj_state_t *obj = job->obj;
    char* url;
    char* tooltip;
    char* target;
    boolean explicit;

    if (explicit_iurl) url = iurl;
    else url = obj->url;
    if (explicit_itooltip) {
	tooltip = itooltip;
	explicit = NOT(0);
    }
    else if (obj->explicit_tooltip) {
	tooltip = obj->tooltip;
	explicit = NOT(0);
    }
    else {
	explicit = 0;
	tooltip = itooltip;
    }
    if (explicit_itarget)
	target = itarget;
    else if (obj->explicit_edgetarget)
	target = obj->target;
    else
	target = itarget;

    if (url || explicit) {
	map_point(job, p);


	
	

    }
}

static void emit_end_edge(GVJ_t * job)
{
    obj_state_t *obj = job->obj;
    edge_t *e = obj->u.e;
    int i, nump;

    if (obj->url || obj->explicit_tooltip) {
	gvrender_end_anchor(job);
	if (obj->url_bsplinemap_poly_n) {
	    for ( nump = obj->url_bsplinemap_n[0], i = 1; i < obj->url_bsplinemap_poly_n; i++) {
		/* additional polygon maps around remaining bezier pieces */
		obj->url_map_n = obj->url_bsplinemap_n[i];
		obj->url_map_p = &(obj->url_bsplinemap_p[nump]);
		gvrender_begin_anchor(job,
			obj->url, obj->tooltip, obj->target, obj->id);
		gvrender_end_anchor(job);
		nump += obj->url_bsplinemap_n[i];
	    }
	}
    }
    obj->url_map_n = 0;       /* null out copy so that it doesn't get freed twice */
    obj->url_map_p = NULL;

    if (ED_spl(e)) {
	pointf p;
	bezier bz;

	/* process intersection with tail node */
	bz = ED_spl(e)->list[0];
	if (bz.sflag) /* Arrow at start of splines */
	    p = bz.sp;
	else /* No arrow at start of splines */
	    p = bz.list[0];
	nodeIntersect (job, p, obj->explicit_tailurl, obj->tailurl,
	    obj->explicit_tailtooltip, obj->tailtooltip, 
	    obj->explicit_tailtarget, obj->tailtarget); 
        
	/* process intersection with head node */
	bz = ED_spl(e)->list[ED_spl(e)->size - 1];
	if (bz.eflag) /* Arrow at end of splines */
	    p = bz.ep;
	else /* No arrow at end of splines */
	    p = bz.list[bz.size - 1];
	nodeIntersect (job, p, obj->explicit_headurl, obj->headurl,
	    obj->explicit_headtooltip, obj->headtooltip, 
	    obj->explicit_headtarget, obj->headtarget); 
    }

    emit_edge_label(job, ED_label(e), EMIT_ELABEL,
	obj->explicit_labeltooltip, 
	obj->labelurl, obj->labeltooltip, obj->labeltarget, obj->id, 
	((mapbool(late_string(e, E_decorate, "false")) && ED_spl(e)) ? ED_spl(e) : 0));
    emit_edge_label(job, ED_xlabel(e), EMIT_ELABEL,
	obj->explicit_labeltooltip, 
	obj->labelurl, obj->labeltooltip, obj->labeltarget, obj->id, 
	((mapbool(late_string(e, E_decorate, "false")) && ED_spl(e)) ? ED_spl(e) : 0));
    emit_edge_label(job, ED_head_label(e), EMIT_HLABEL, 
	obj->explicit_headtooltip,
	obj->headurl, obj->headtooltip, obj->headtarget, obj->id,
	0);
    emit_edge_label(job, ED_tail_label(e), EMIT_TLABEL, 
	obj->explicit_tailtooltip,
	obj->tailurl, obj->tailtooltip, obj->tailtarget, obj->id,
	0);

    gvrender_end_edge(job);
    pop_obj_state(job);
}

static void emit_edge(GVJ_t * job, edge_t * e)
{
    char *s;
    char *style;
    char **styles = 0;
    char **sp;
    char *p;

    if (edge_in_box(e, job->clip) && edge_in_layer(job, agraphof(aghead(e)), e) ) {

	s = malloc(strlen(agnameof(agtail(e))) + 2 + strlen(agnameof(aghead(e))) + 1);
	strcpy(s,agnameof(agtail(e)));
	if (agisdirected(agraphof(aghead(e))))

	    strcat(s,"->");
	else
	    strcat(s,"--");
	strcat(s,agnameof(aghead(e)));
	gvrender_comment(job, s);
	free(s);

	s = late_string(e, E_comment, "");
	if (s[0])
	    gvrender_comment(job, s);

	style = late_string(e, E_style, "");
	/* We shortcircuit drawing an invisible edge because the arrowhead
	 * code resets the style to solid, and most of the code generators
	 * (except PostScript) won't honor a previous style of invis.
	 */
	if (style[0]) {
	    styles = parse_style(style);
	    sp = styles;
	    while ((p = *sp++)) {
		if ((*(p)==*("invis")&&!strcmp(p,"invis"))) return;
	    }
	}

	emit_begin_edge(job, e, styles);
	emit_edge_graphics (job, e, styles);
	emit_end_edge(job);
    }
}

static char adjust[] = {'l', 'n', 'r'};

static void
expandBB (boxf* bb, pointf p)
{
    if (p.x > bb->UR.x)
	bb->UR.x = p.x;
    if (p.x < bb->LL.x)
	bb->LL.x = p.x;
    if (p.y > bb->UR.y)
	bb->UR.y = p.y;
    if (p.y < bb->LL.y)
	bb->LL.y = p.y;
}

static boxf
ptsBB (xdot_point* inpts, int numpts, boxf* bb)
{
    boxf opbb;
    int i;

    opbb.LL.x = opbb.UR.x = inpts->x;
    opbb.LL.y = opbb.UR.y = inpts->y;
    for (i = 1; i < numpts; i++) {
	inpts++;
	if (inpts->x < opbb.LL.x)
	    opbb.LL.x = inpts->x;
	else if (inpts->x > opbb.UR.x)
	    opbb.UR.x = inpts->x;
	if (inpts->y < opbb.LL.y)
	    opbb.LL.y = inpts->y;
	else if (inpts->y > opbb.UR.y)
	    opbb.UR.y = inpts->y;

    }
    expandBB (bb, opbb.LL);
    expandBB (bb, opbb.UR);
    return opbb;
}

static boxf
textBB (double x, double y, textspan_t* span)
{
    boxf bb;
    pointf sz = span->size;

    switch (span->just) {
    case 'l':
	bb.LL.x = x;
	bb.UR.x = bb.LL.x + sz.x;
	break; 
    case 'n':
	bb.LL.x = x - sz.x / 2.0; 
	bb.UR.x = x + sz.x / 2.0; 
	break; 
    case 'r':
	bb.UR.x = x; 
	bb.LL.x = bb.UR.x - sz.x;
	break; 
    }
    bb.UR.y = y + span->yoffset_layout;
    bb.LL.y = bb.UR.y - sz.y;
    return bb;
}

static void
freePara (exdot_op* op)
{
    if (op->op.kind == xd_text)
	free_textspan (op->span, 1);
}

boxf xdotBB (Agraph_t* g)
{
    GVC_t *gvc = GD_gvc(g);
    exdot_op* op;
    int i;
    double fontsize = 0.0;
    char* fontname = NULL;
    pointf pts[2];
    pointf sz;
    boxf bb0;
    boxf bb = GD_bb(g);
    xdot* xd = (xdot*)GD_drawing(g)->xdots;
    textfont_t tf, null_tf = {NULL,NULL,NULL,0.0,0,0};
    int fontflags;

    if (!xd) return bb;

    if ((bb.LL.x == bb.UR.x) && (bb.LL.y == bb.UR.y)) {
	bb.LL.x = bb.LL.y = MAXDOUBLE;
	bb.UR.x = bb.UR.y = -MAXDOUBLE;
    }

    op = (exdot_op*)(xd->ops);
    for (i = 0; i < xd->cnt; i++) {
	tf = null_tf;
	switch (op->op.kind) {
	case xd_filled_ellipse :
	case xd_unfilled_ellipse :
	    pts[0].x = op->op.u.ellipse.x - op->op.u.ellipse.w;
	    pts[0].y = op->op.u.ellipse.y - op->op.u.ellipse.h;
	    pts[1].x = op->op.u.ellipse.x + op->op.u.ellipse.w;
	    pts[1].y = op->op.u.ellipse.y + op->op.u.ellipse.h;
	    op->bb.LL = pts[0];
	    op->bb.UR = pts[1];
	    expandBB (&bb, pts[0]);
	    expandBB (&bb, pts[1]);
	    break;
	case xd_filled_polygon :
	case xd_unfilled_polygon :
	    op->bb = ptsBB (op->op.u.polygon.pts, op->op.u.polygon.cnt, &bb);
	    break;
	case xd_filled_bezier :
	case xd_unfilled_bezier :
	    op->bb = ptsBB (op->op.u.polygon.pts, op->op.u.polygon.cnt, &bb);
	    break;
	case xd_polyline :
	    op->bb = ptsBB (op->op.u.polygon.pts, op->op.u.polygon.cnt, &bb);
	    break;
	case xd_text :
	    op->span = (textspan_t*)zmalloc(sizeof(textspan_t));
	    op->span->str = strdup (op->op.u.text.text);
	    op->span->just = adjust [op->op.u.text.align];
	    tf.name = fontname;
	    tf.size = fontsize;
	    tf.flags = fontflags;
            op->span->font = (*(((Dt_t*)(gvc->textfont_dt))->searchf))((gvc->textfont_dt),(void*)(&tf),0000001);
	    sz = textspan_size (gvc, op->span);
	    bb0 = textBB (op->op.u.text.x, op->op.u.text.y, op->span);
	    op->bb = bb0;
	    expandBB (&bb, bb0.LL);
	    expandBB (&bb, bb0.UR);
	    if (!xd->freefunc)
		xd->freefunc = (freefunc_t)freePara;
	    break;
	case xd_font :
	    fontsize = op->op.u.font.size;
	    fontname = op->op.u.font.name;
	    break;
	case xd_fontchar :
	    fontflags = op->op.u.fontchar;
	    break;
	default :
	    break;
	}
	op++;
    }
    return bb;
}

static void init_gvc(GVC_t * gvc, graph_t * g)
{
    double xf, yf;
    char *p;
    int i;

    gvc->g = g;

    /* margins */
    gvc->graph_sets_margin = 0;
    if ((p = agget(g, "margin"))) {
        i = sscanf(p, "%lf,%lf", &xf, &yf);
        if (i > 0) {
            gvc->margin.x = gvc->margin.y = xf * 72;
            if (i > 1)
                gvc->margin.y = yf * 72;
            gvc->graph_sets_margin = NOT(0);
        }
    }

    /* pad */
    gvc->graph_sets_pad = 0;
    if ((p = agget(g, "pad"))) {
        i = sscanf(p, "%lf,%lf", &xf, &yf);
        if (i > 0) {
            gvc->pad.x = gvc->pad.y = xf * 72;
            if (i > 1)
                gvc->pad.y = yf * 72;
            gvc->graph_sets_pad = NOT(0);
        }
    }

    /* pagesize */
    gvc->graph_sets_pageSize = 0;
    gvc->pageSize = GD_drawing(g)->page;
    if ((GD_drawing(g)->page.x > 0.001) && (GD_drawing(g)->page.y > 0.001))
        gvc->graph_sets_pageSize = NOT(0);

    /* rotation */
    if (GD_drawing(g)->landscape)
	gvc->rotation = 90;
    else 
	gvc->rotation = 0;

    /* pagedir */
    gvc->pagedir = "BL";
    if ((p = agget(g, "pagedir")) && p[0])
            gvc->pagedir = p;


    /* bounding box */
    gvc->bb = GD_bb(g);

    /* clusters have peripheries */
    G_peripheries = (agattr(g,AGRAPH,"peripheries",NULL));
    G_penwidth = (agattr(g,AGRAPH,"penwidth",NULL));

    /* default font */
    gvc->defaultfontname = late_nnstring(NULL,
                N_fontname, "Times-Roman");
    gvc->defaultfontsize = late_double(NULL,
                N_fontsize, 14.0, 1.0);

    /* default line style */
    gvc->defaultlinestyle = defaultlinestyle;

    gvc->graphname = agnameof(g);
}

static void init_job_pad(GVJ_t *job)
{
    GVC_t *gvc = job->gvc;
    
    if (gvc->graph_sets_pad) {
	job->pad = gvc->pad;
    }
    else {
	switch (job->output_lang) {
	case 300:
	    job->pad.x = job->pad.y = job->render.features->default_pad;
	    break;
	default:
	    job->pad.x = job->pad.y = 4;
	    break;
	}
    }
}

static void init_job_margin(GVJ_t *job)
{
    GVC_t *gvc = job->gvc;
    
    if (gvc->graph_sets_margin) {
	job->margin = gvc->margin;
    }
    else {
        /* set default margins depending on format */
        switch (job->output_lang) {
        case 300:
            job->margin = job->device.features->default_margin;
            break;
        case 2: case 3: case 4: case 22: case 21: case 30:
            job->margin.x = job->margin.y = 36;
            break;
        default:
            job->margin.x = job->margin.y = 0;
            break;
        }
    }

}

static void init_job_dpi(GVJ_t *job, graph_t *g)
{
    GVJ_t *firstjob = job->gvc->active_jobs;

    if (GD_drawing(g)->dpi != 0) {
        job->dpi.x = job->dpi.y = (double)(GD_drawing(g)->dpi);
    }
    else if (firstjob && firstjob->device_sets_dpi) {
        job->dpi = firstjob->device_dpi;   /* some devices set dpi in initialize() */
    }
    else {
        /* set default margins depending on format */
        switch (job->output_lang) {
        case 300:
            job->dpi = job->device.features->default_dpi;
            break;
        default:
            job->dpi.x = job->dpi.y = (double)(DEFAULT_DPI);
            break;
        }
    }
}

static void init_job_viewport(GVJ_t * job, graph_t * g)
{
    GVC_t *gvc = job->gvc;
    pointf LL, UR, size, sz;
    double X, Y, Z, x, y;
    int rv;
    Agnode_t *n;
    char *str, *nodename = NULL, *junk = NULL;

    UR = gvc->bb.UR;
    LL = gvc->bb.LL;
    job->bb.LL.x = LL.x - job->pad.x;           /* job->bb is bb of graph and padding - graph units */
    job->bb.LL.y = LL.y - job->pad.y;
    job->bb.UR.x = UR.x + job->pad.x;
    job->bb.UR.y = UR.y + job->pad.y;
    sz.x = job->bb.UR.x - job->bb.LL.x;   /* size, including padding - graph units */
    sz.y = job->bb.UR.y - job->bb.LL.y;

    /* determine final drawing size and scale to apply. */
    /* N.B. size given by user is not rotated by landscape mode */
    /* start with "natural" size of layout */

    Z = 1.0;
    if (GD_drawing(g)->size.x > 0.001 && GD_drawing(g)->size.y > 0.001) { /* graph size was given by user... */
	size = GD_drawing(g)->size;
	if (sz.x == 0) sz.x = size.x;
	if (sz.y == 0) sz.y = size.y;
	if ((size.x < sz.x) || (size.y < sz.y) /* drawing is too big (in either axis) ... */
	    || ((GD_drawing(g)->filled) /* or ratio=filled requested and ... */
		&& (size.x > sz.x) && (size.y > sz.y))) /* drawing is too small (in both axes) ... */
	    Z = MIN(size.x/sz.x, size.y/sz.y);
    }
    
    /* default focus, in graph units = center of bb */
    x = (LL.x + UR.x) / 2.;
    y = (LL.y + UR.y) / 2.;

    /* rotate and scale bb to give default absolute size in points*/
    job->rotation = job->gvc->rotation;
    X = sz.x * Z;
    Y = sz.y * Z;

    /* user can override */
    if ((str = agget(g, "viewport"))) {
        nodename = malloc(strlen(str)+1);
        junk = malloc(strlen(str)+1);
	rv = sscanf(str, "%lf,%lf,%lf,\'%[^\']\'", &X, &Y, &Z, nodename);
	if (rv == 4) {
	    n = (agnode(g->root,nodename,0));
	    if (n) {
		x = ND_coord(n).x;
		y = ND_coord(n).y;
	    }
	}
	else {
	    rv = sscanf(str, "%lf,%lf,%lf,%[^,]%s", &X, &Y, &Z, nodename, junk);
	    if (rv == 4) {
                n = (agnode(g->root,nodename,0));
                if (n) {
                    x = ND_coord(n).x;
                    y = ND_coord(n).y;
		}
	    }
	    else {
	        rv = sscanf(str, "%lf,%lf,%lf,%lf,%lf", &X, &Y, &Z, &x, &y);
	    }
        }
	free (nodename);
	free (junk);
    }
    /* rv is ignored since args retain previous values if not scanned */

    /* job->view gives port size in graph units, unscaled or rotated
     * job->zoom gives scaling factor.
     * job->focus gives the position in the graph of the center of the port
     */
    job->view.x = X;
    job->view.y = Y;
    job->zoom = Z;              /* scaling factor */
    job->focus.x = x;
    job->focus.y = y;


	
	
	

}

static void emit_cluster_colors(GVJ_t * job, graph_t * g)
{
    graph_t *sg;
    int c;
    char *str;

    for (c = 1; c <= GD_n_cluster(g); c++) {
	sg = GD_clust(g)[c];
	emit_cluster_colors(job, sg);
	if (((str = agget(sg, "color")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
	if (((str = agget(sg, "pencolor")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
	if (((str = agget(sg, "bgcolor")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
	if (((str = agget(sg, "fillcolor")) != 0) && str[0])
	    gvrender_set_fillcolor(job, str);
	if (((str = agget(sg, "fontcolor")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
    }
}

static void emit_colors(GVJ_t * job, graph_t * g)
{
    node_t *n;
    edge_t *e;
    char *str, *colors;

    gvrender_set_fillcolor(job, "lightgrey");
    if (((str = agget(g, "bgcolor")) != 0) && str[0])
	gvrender_set_fillcolor(job, str);
    if (((str = agget(g, "fontcolor")) != 0) && str[0])
	gvrender_set_pencolor(job, str);
  
    emit_cluster_colors(job, g);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if (((str = agget(n, "color")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
	if (((str = agget(n, "pencolor")) != 0) && str[0])
	    gvrender_set_fillcolor(job, str);
	if (((str = agget(n, "fillcolor")) != 0) && str[0]) {
	    if (strchr(str, ':')) {
		colors = strdup(str);
		for (str = strtok(colors, ":"); str;
		    str = strtok(0, ":")) {
		    if (str[0])
			gvrender_set_pencolor(job, str);
		}
		free(colors);
	    }
	    else {
		gvrender_set_pencolor(job, str);
	    }
	}
	if (((str = agget(n, "fontcolor")) != 0) && str[0])
	    gvrender_set_pencolor(job, str);
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    if (((str = agget(e, "color")) != 0) && str[0]) {
		if (strchr(str, ':')) {
		    colors = strdup(str);
		    for (str = strtok(colors, ":"); str;
			str = strtok(0, ":")) {
			if (str[0])
			    gvrender_set_pencolor(job, str);
		    }
		    free(colors);
		}
		else {
		    gvrender_set_pencolor(job, str);
		}
	    }
	    if (((str = agget(e, "fontcolor")) != 0) && str[0])
		gvrender_set_pencolor(job, str);
	}
    }
}

static void emit_view(GVJ_t * job, graph_t * g, int flags)
{
    GVC_t * gvc = job->gvc;
    node_t *n;
    edge_t *e;

    gvc->common.viewNum++;
    /* when drawing, lay clusters down before nodes and edges */
    if (!(flags & (1<<2)))
	emit_clusters(job, g, flags);
    if (flags & (1<<0)) {
	/* output all nodes, then all edges */
	gvrender_begin_nodes(job);
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    emit_node(job, n);
	gvrender_end_nodes(job);
	gvrender_begin_edges(job);
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    for (e = agfstout(g, n); e; e = agnxtout(g, e))
		emit_edge(job, e);
	}
	gvrender_end_edges(job);
    } else if (flags & (1<<4)) {
	/* output all edges, then all nodes */
	gvrender_begin_edges(job);
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    for (e = agfstout(g, n); e; e = agnxtout(g, e))
		emit_edge(job, e);
	gvrender_end_edges(job);
	gvrender_begin_nodes(job);
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    emit_node(job, n);
	gvrender_end_nodes(job);
    } else if (flags & (1<<3)) {
	gvrender_begin_nodes(job);
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    if (write_node_test(g, n))
		emit_node(job, n);
	gvrender_end_nodes(job);
	gvrender_begin_edges(job);

	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
		if (write_edge_test(g, e))
		    emit_edge(job, e);
	    }
	}
	gvrender_end_edges(job);
    } else {
	/* output in breadth first graph walk order */
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    emit_node(job, n);
	    for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
		emit_node(job, aghead(e));
		emit_edge(job, e);
	    }
	}
    }
    /* when mapping, detect events on clusters after nodes and edges */
    if (flags & (1<<2))
	emit_clusters(job, g, flags);
}

static void emit_begin_graph(GVJ_t * job, graph_t * g)
{
    obj_state_t *obj;

    obj = push_obj_state(job);
    obj->type = ROOTGRAPH_OBJTYPE;
    obj->u.g = g;
    obj->emit_state = EMIT_GDRAW;

    initObjMapData (job, GD_label(g), g);

    gvrender_begin_graph(job, g);
}

static void emit_end_graph(GVJ_t * job, graph_t * g)
{
    gvrender_end_graph(job);
    pop_obj_state(job);
}



static void emit_page(GVJ_t * job, graph_t * g)
{
    obj_state_t *obj = job->obj;
    int nump = 0, flags = job->flags;
    textlabel_t *lab;
    pointf *p = NULL;
    char* saveid;
    unsigned char buf[128];
    agxbuf xb;

    /* For the first page, we can use the values generated in emit_begin_graph. 
     * For multiple pages, we need to generate a new id.
     */
    if ((((job)->layerNum>1)||((job)->pagesArrayElem.x > 0)||((job)->pagesArrayElem.x > 0))) {
	agxbinit(&xb, 128, buf);
	saveid = obj->id;
	layerPagePrefix (job, &xb);
	agxbput (&xb, saveid);
	obj->id = (((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf));
    }
    else
	saveid = NULL;

    setColorScheme (agget (g, "colorscheme"));
    setup_page(job, g);
    gvrender_begin_page(job);
    gvrender_set_pencolor(job, "black");
    gvrender_set_fillcolor(job, "lightgrey");
    if ((flags & ((1<<16) | (1<<22)))
	    && (obj->url || obj->explicit_tooltip)) {
	if (flags & ((1<<17) | (1<<19))) {
	    if (flags & (1<<17)) {
		obj->url_map_shape = MAP_RECTANGLE;
		nump = 2;
	    }
	    else {
		obj->url_map_shape = MAP_POLYGON;
		nump = 4;
	    }
	    p = (pointf*)zmalloc((nump)*sizeof(pointf));
	    p[0] = job->pageBox.LL;
	    p[1] = job->pageBox.UR;
	    if (! (flags & ((1<<17))))
		rect2poly(p);
	}
	if (! (flags & (1<<13)))
	    gvrender_ptf_A(job, p, p, nump);
	obj->url_map_p = p;
	obj->url_map_n = nump;
    }
    if ((flags & (1<<15)) && ((lab = GD_label(g))))
	/* do graph label on every page and rely on clipping to show it on the right one(s) */
	obj->label = lab->text;
	/* If EMIT_CLUSTERS_LAST is set, we assume any URL or tooltip
	 * attached to the root graph is emitted either in begin_page
	 * or end_page of renderer.
	 */
    if (!(flags & (1<<2)) && (obj->url || obj->explicit_tooltip)) {
	emit_map_rect(job, job->clip);
	gvrender_begin_anchor(job, obj->url, obj->tooltip, obj->target, obj->id);
    }
    /* if (numPhysicalLayers(job) == 1) */
	emit_background(job, g);
    if (GD_label(g))
	emit_label(job, EMIT_GLABEL, GD_label(g));
    if (!(flags & (1<<2)) && (obj->url || obj->explicit_tooltip))
	gvrender_end_anchor(job);
    emit_view(job,g,flags);
    gvrender_end_page(job);
    if (saveid) {
	agxbfree(&xb);
	obj->id = saveid;
    }
}

void emit_graph(GVJ_t * job, graph_t * g)
{
    node_t *n;
    char *s;
    int flags = job->flags;
    int* lp;

    /* device dpi is now known */
    job->scale.x = job->zoom * job->dpi.x / 72;
    job->scale.y = job->zoom * job->dpi.y / 72;

    job->devscale.x = job->dpi.x / 72;
    job->devscale.y = job->dpi.y / 72;
    if ((job->flags & (1<<12)) || (Y_invert))
	job->devscale.y *= -1;

    /* compute current view in graph units */
    if (job->rotation) {
	job->view.y = job->width / job->scale.y;
	job->view.x = job->height / job->scale.x;
    }
    else {
	job->view.x = job->width / job->scale.x;
	job->view.y = job->height / job->scale.y;
    }


	


    s = late_string(g, agattr(g, AGRAPH, "comment", 0), "");
    gvrender_comment(job, s);

    job->layerNum = 0;
    emit_begin_graph(job, g);

    if (flags & (1<<1))
	emit_colors(job,g);

    /* reset node state */
    for (n = agfstnode(g); n; n = agnxtnode(g, n))
	ND_state(n) = 0;
    /* iterate layers */
    for (firstlayer(job,&lp); validlayer(job); nextlayer(job,&lp)) {
	if (numPhysicalLayers (job) > 1)
	    gvrender_begin_layer(job);

	/* iterate pages */
	for (firstpage(job); validpage(job); nextpage(job))
	    emit_page(job, g);

	if (numPhysicalLayers (job) > 1)
	    gvrender_end_layer(job);
    } 
    emit_end_graph(job, g);
}

/* support for stderr_once */
static void free_string_entry(Dict_t * dict, char *key, Dtdisc_t * disc)
{
    free(key);
}

static Dict_t *strings;
static Dtdisc_t stringdict = {
    0,				/* key  - the object itself */
    0,				/* size - null-terminated string */
    -1,				/* link - allocate separate holder objects  */
    ((Dtmake_f)0),
    (Dtfree_f) free_string_entry,
    ((Dtcompar_f)0),
    ((Dthash_f)0),
    ((Dtmemory_f)0),
    ((Dtevent_f)0)
};

int emit_once(char *str)
{
    if (strings == 0)
	strings = dtopen(&stringdict, Dtoset);
    if (!(*(((Dt_t*)(strings))->searchf))((strings),(void*)(str),0000004)) {
	(*(((Dt_t*)(strings))->searchf))((strings),(void*)(strdup(str)),0000001);
	return NOT(0);
    }
    return 0;
}

void emit_once_reset(void)
{
    if (strings) {
	dtclose(strings);
	strings = 0;
    }
}

static void emit_begin_cluster(GVJ_t * job, Agraph_t * sg)
{
    obj_state_t *obj;

    obj = push_obj_state(job);
    obj->type = CLUSTER_OBJTYPE;
    obj->u.sg = sg;
    obj->emit_state = EMIT_CDRAW;

    initObjMapData (job, GD_label(sg), sg);
    
    gvrender_begin_cluster(job, sg);
}

static void emit_end_cluster(GVJ_t * job, Agraph_t * g)
{
    gvrender_end_cluster(job, g);
    pop_obj_state(job);
}

void emit_clusters(GVJ_t * job, Agraph_t * g, int flags)
{
    int doPerim, c, istyle, filled;
    pointf AF[4];
    char *color, *fillcolor, *pencolor, **style, *s;
    graph_t *sg;
    node_t *n;
    edge_t *e;
    obj_state_t *obj;
    textlabel_t *lab;
    int doAnchor;
    double penwidth;
    char* clrs[2];
    
    for (c = 1; c <= GD_n_cluster(g); c++) {
	sg = GD_clust(g)[c];
	if (clust_in_layer(job, sg) == 0)
	    continue;
	/* when mapping, detect events on clusters after sub_clusters */
	if (flags & (1<<2))
	    emit_clusters(job, sg, flags);
	emit_begin_cluster(job, sg);
	obj = job->obj;
	doAnchor = (obj->url || obj->explicit_tooltip);
	setColorScheme (agget (sg, "colorscheme"));
	if (doAnchor && !(flags & (1<<2))) {
	    emit_map_rect(job, GD_bb(sg));
	    gvrender_begin_anchor(job, obj->url, obj->tooltip, obj->target, obj->id);
	}
	filled = 0;
	istyle = 0;
	if ((style = checkClusterStyle(sg, &istyle))) {
	    gvrender_set_style(job, style);
	    if (istyle & (1 << 0))
		filled = 1;
	}
	fillcolor = pencolor = 0;

	if (GD_gui_state(sg) & (1<<0)) {
	    pencolor = late_nnstring(sg, G_activepencolor, "#808080");
	    fillcolor = late_nnstring(sg, G_activefillcolor, "#fcfcfc");
	    filled = NOT(0);
	}
	else if (GD_gui_state(sg) & (1<<1)) {
	    pencolor = late_nnstring(sg, G_activepencolor, "#303030");
	    fillcolor = late_nnstring(sg, G_activefillcolor, "#e8e8e8");
	    filled = NOT(0);
	}
	else if (GD_gui_state(sg) & (1<<3)) {
	    pencolor = late_nnstring(sg, G_deletedpencolor, "#e0e0e0");
	    fillcolor = late_nnstring(sg, G_deletedfillcolor, "#f0f0f0");
	    filled = NOT(0);
	}
	else if (GD_gui_state(sg) & (1<<2)) {
	    pencolor = late_nnstring(sg, G_visitedpencolor, "#101010");
	    fillcolor = late_nnstring(sg, G_visitedfillcolor, "#f8f8f8");
	    filled = NOT(0);
	}
	else {
	    if (((color = agget(sg, "color")) != 0) && color[0])
		fillcolor = pencolor = color;
	    if (((color = agget(sg, "pencolor")) != 0) && color[0])
		pencolor = color;
	    if (((color = agget(sg, "fillcolor")) != 0) && color[0])
		fillcolor = color;
	    /* bgcolor is supported for backward compatability 
	       if fill is set, fillcolor trumps bgcolor, so
               don't bother checking.
               if gradient is set fillcolor trumps bgcolor
             */
	    if ((!filled || !fillcolor) && ((color = agget(sg, "bgcolor")) != 0) && color[0]) {
		fillcolor = color;
	        filled = 1;
            }

	}
	if (!pencolor) pencolor = "black";
	if (!fillcolor) fillcolor = "lightgrey";
	clrs[0] = NULL;
	if (filled) {
	    float frac;
	    if (findStopColor (fillcolor, clrs, &frac)) {
        	gvrender_set_fillcolor(job, clrs[0]);
		if (clrs[1]) 
		    gvrender_set_gradient_vals(job,clrs[1],late_int(sg,G_gradientangle,0,0), frac);
		else 
		    gvrender_set_gradient_vals(job,"black",late_int(sg,G_gradientangle,0,0), frac);
		if (istyle & (1 << 1))
		    filled = 3;
	 	else
		    filled = 2;
	    }
	    else
        	gvrender_set_fillcolor(job, fillcolor);
	}

	if (G_penwidth && ((s=agxget(sg,G_penwidth)) && s[0])) {
	    penwidth = late_double(sg, G_penwidth, 1.0, 0.0);
            gvrender_set_penwidth(job, penwidth);
	}

	if (istyle & (1 << 2)) {
	    if ((doPerim = late_int(sg, G_peripheries, 1, 0)) || filled) {
		AF[0] = GD_bb(sg).LL;
		AF[2] = GD_bb(sg).UR;
		AF[1].x = AF[2].x;
		AF[1].y = AF[0].y;
		AF[3].x = AF[0].x;
		AF[3].y = AF[2].y;
		if (doPerim)
    		    gvrender_set_pencolor(job, pencolor);
		else
        	    gvrender_set_pencolor(job, "transparent");
		round_corners(job, AF, 4, istyle, filled);
	    }
	}
	else if (istyle & (1 << 6)) {
	    int rv;
	    AF[0] = GD_bb(sg).LL;
	    AF[2] = GD_bb(sg).UR;
	    AF[1].x = AF[2].x;
	    AF[1].y = AF[0].y;
	    AF[3].x = AF[0].x;
	    AF[3].y = AF[2].y;
	    if (late_int(sg, G_peripheries, 1, 0) == 0)
        	gvrender_set_pencolor(job, "transparent");
	    else
    		gvrender_set_pencolor(job, pencolor);
	    rv = stripedBox (job, AF, fillcolor, 0);
	    if (rv > 1)
		agerr (AGPREV, "in cluster %s\n", agnameof(sg));
	    gvrender_box(job, GD_bb(sg), 0);
	}
	else {
	    if (late_int(sg, G_peripheries, 1, 0)) {
    		gvrender_set_pencolor(job, pencolor);
		gvrender_box(job, GD_bb(sg), filled);
	    }
	    else if (filled) {
        	gvrender_set_pencolor(job, "transparent");
		gvrender_box(job, GD_bb(sg), filled);
	    }
	}

	free (clrs[0]);
	if ((lab = GD_label(sg)))
	    emit_label(job, EMIT_CLABEL, lab);

	if (doAnchor) {
	    if (flags & (1<<2)) {
		emit_map_rect(job, GD_bb(sg));
		gvrender_begin_anchor(job, obj->url, obj->tooltip, obj->target, obj->id);
	    }
	    gvrender_end_anchor(job);
	}

	if (flags & (1<<3)) {
	    for (n = agfstnode(sg); n; n = agnxtnode(sg, n)) {
		emit_node(job, n);
		for (e = agfstout(sg, n); e; e = agnxtout(sg, e))
		    emit_edge(job, e);
	    }
	}
	emit_end_cluster(job, g);
	/* when drawing, lay down clusters before sub_clusters */
	if (!(flags & (1<<2)))
	    emit_clusters(job, sg, flags);
    }
}

static boolean is_style_delim(int c)
{
    switch (c) {
    case '(':
    case ')':
    case ',':
    case '\0':
	return NOT(0);
    default:
	return 0;
    }
}



static int style_token(char **s, agxbuf * xb)
{
    char *p = *s;
    int token, rc;
    char c;

    while (*p && (isspace(*p) || (*p == ',')))
	p++;
    switch (*p) {
    case '\0':
	token = 0;
	break;
    case '(':
    case ')':
	token = *p++;
	break;
    default:
	token = 1;
	while (!is_style_delim(c = *p)) {
	    rc = ((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)c)));
	    p++;
	}
    }
    *s = p;
    return token;
}


static unsigned char outbuf[128];
static agxbuf ps_xb;




    



/* parse_style:
 * This is one of the worst internal designs in graphviz.
 * The use of '\0' characters within strings seems cute but it
 * makes all of the standard functions useless if not dangerous.
 * Plus the function uses static memory for both the array and
 * the character buffer. One hopes all of the values are used
 * before the function is called again.
 */
char **parse_style(char *s)
{
    static char *parse[64];
    static boolean is_first = NOT(0);
    int fun = 0;
    boolean in_parens = 0;
    unsigned char buf[128];
    char *p;
    int c;
    agxbuf xb;

    if (is_first) {
	agxbinit(&ps_xb, 128, outbuf);

	

	is_first = 0;
    }

    agxbinit(&xb, 128, buf);
    p = s;
    while ((c = style_token(&p, &xb)) != 0) {
	switch (c) {
	case '(':
	    if (in_parens) {
		agerr(AGERR, "nesting not allowed in style: %s\n", s);
		parse[0] = (char *) 0;
		agxbfree(&xb);
		return parse;
	    }
	    in_parens = NOT(0);
	    break;

	case ')':
	    if (in_parens == 0) {
		agerr(AGERR, "unmatched ')' in style: %s\n", s);
		parse[0] = (char *) 0;
		agxbfree(&xb);
		return parse;
	    }
	    in_parens = 0;
	    break;

	default:
	    if (in_parens == 0) {
		if (fun == 64 - 1) {
		    agerr(AGWARN, "truncating style '%s'\n", s);
		    parse[fun] = (char *) 0;
		    agxbfree(&xb);
		    return parse;
		}
		((((&ps_xb)->ptr >= (&ps_xb)->eptr) ? agxbmore(&ps_xb,1) : 0), (int)(*(&ps_xb)->ptr++ = ((unsigned char)'\0')));	/* terminate previous */
		parse[fun++] = ((char*)((&ps_xb)->ptr));
	    }
	    agxbput(&ps_xb, (((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)));
	    ((((&ps_xb)->ptr >= (&ps_xb)->eptr) ? agxbmore(&ps_xb,1) : 0), (int)(*(&ps_xb)->ptr++ = ((unsigned char)'\0')));
	}
    }

    if (in_parens) {
	agerr(AGERR, "unmatched '(' in style: %s\n", s);
	parse[0] = (char *) 0;
	agxbfree(&xb);
	return parse;
    }
    parse[fun] = (char *) 0;
    agxbfree(&xb);
    (void)(((((&ps_xb)->ptr >= (&ps_xb)->eptr) ? agxbmore(&ps_xb,1) : 0), (int)(*(&ps_xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&ps_xb)->ptr = (&ps_xb)->buf));		/* adds final '\0' to buffer */
    return parse;
}

static boxf bezier_bb(bezier bz)
{
    int i;
    pointf p, p1, p2;
    boxf bb;

    assert(bz.size > 0);
    assert(bz.size % 3 == 1);
    bb.LL = bb.UR = bz.list[0];
    for (i = 1; i < bz.size;) {
	/* take mid-point between two control points for bb calculation */
	p1=bz.list[i];
	i++;
	p2=bz.list[i];
	i++;
	p.x = ( p1.x + p2.x ) / 2;
	p.y = ( p1.y + p2.y ) / 2;
        EXPANDBP(bb,p);

	p=bz.list[i];
        EXPANDBP(bb,p);
	i++;
    }
    return bb;
}

static void init_splines_bb(splines *spl)
{
    int i;
    bezier bz;
    boxf bb, b;

    assert(spl->size > 0);
    bz = spl->list[0];
    bb = bezier_bb(bz);
    for (i = 0; i < spl->size; i++) {
        if (i > 0) {
            bz = spl->list[i];
            b = bezier_bb(bz);
            EXPANDBB(bb, b);
        }
        if (bz.sflag) {
            b = arrow_bb(bz.sp, bz.list[0], 1, bz.sflag);
            EXPANDBB(bb, b);
        }
        if (bz.eflag) {
            b = arrow_bb(bz.ep, bz.list[bz.size - 1], 1, bz.eflag);
            EXPANDBB(bb, b);
        }
    }
    spl->bb = bb;
}

static void init_bb_edge(edge_t *e)
{
    splines *spl;

    spl = ED_spl(e);
    if (spl)
        init_splines_bb(spl);

//    lp = ED_label(e);
//    if (lp)
//        {}
}

static void init_bb_node(graph_t *g, node_t *n)
{
    edge_t *e;

    ND_bb(n).LL.x = ND_coord(n).x - ND_lw(n);
    ND_bb(n).LL.y = ND_coord(n).y - ND_ht(n) / 2.;
    ND_bb(n).UR.x = ND_coord(n).x + ND_rw(n);
    ND_bb(n).UR.y = ND_coord(n).y + ND_ht(n) / 2.;

    for (e = agfstout(g, n); e; e = agnxtout(g, e))
        init_bb_edge(e);

    /* IDEA - could also save in the node the bb of the node and
    all of its outedges, then the scan time would be proportional
    to just the number of nodes for many graphs.
    Wouldn't work so well if the edges are sprawling all over the place
    because then the boxes would overlap a lot and require more tests,
    but perhaps that wouldn't add much to the cost before trying individual
    nodes and edges. */
}

static void init_bb(graph_t *g)
{
    node_t *n;

    for (n = agfstnode(g); n; n = agnxtnode(g, n))
        init_bb_node(g, n);
}

extern gvevent_key_binding_t gvevent_key_binding[];
extern int gvevent_key_binding_size;
extern gvdevice_callbacks_t gvdevice_callbacks;

/* gv_fixLocale:
 * Set LC_NUMERIC to "C" to get expected interpretation of %f
 * in printf functions. Languages like postscript and dot expect
 * floating point numbers to use a decimal point.
 * 
 * If set is non-zero, the "C" locale set;
 * if set is zero, the original locale is reset.
 * Calls to the function can nest.
 */
void gv_fixLocale (int set)
{
    static char* save_locale;
    static int cnt;

    if (set) {
	cnt++;
	if (cnt == 1) {
	    save_locale = strdup (setlocale (LC_NUMERIC, NULL));
	    setlocale (LC_NUMERIC, "C");
	}
    }
    else if (cnt > 0) {
	cnt--;
	if (cnt == 0) {
	    setlocale (LC_NUMERIC, save_locale);
	    free (save_locale);
	}
    }
}




int gvRenderJobs (GVC_t * gvc, graph_t * g)
{
    static GVJ_t *prevjob;
    GVJ_t *job, *firstjob;

    if (Verbose)
	start_timer();
    
    if (!(agbindrec(g, "Agraphinfo_t", 0, NOT(0)) && GD_drawing(g))) {
        agerr (AGERR, "Layout was not done.  Missing layout plugins? \n");
	if (Verbose) fprintf(stderr,"gvRenderJobs %s: %.2f secs.\n", agnameof(g), elapsed_sec());
        return -1;
    }

    init_bb(g);
    init_gvc(gvc, g);
    init_layering(gvc, g);

    gv_fixLocale (1);
    for (job = gvjobs_first(gvc); job; job = gvjobs_next(gvc)) {
	if (gvc->gvg) {
	    job->input_filename = gvc->gvg->input_filename;
	    job->graph_index = gvc->gvg->graph_index;
	}
	else {
	    job->input_filename = NULL;
	    job->graph_index = 0;
	}
	job->common = &(gvc->common);
	job->layout_type = gvc->layout.type;
	job->keybindings = gvevent_key_binding;
	job->numkeys = gvevent_key_binding_size;
	if (!GD_drawing(g)) {
	    agerr (AGERR, "layout was not done\n");
	    gv_fixLocale (0);
	    if (Verbose) fprintf(stderr,"gvRenderJobs %s: %.2f secs.\n", agnameof(g), elapsed_sec());
	    return -1;
	}

        job->output_lang = gvrender_select(job, job->output_langname);
        if (job->output_lang == 999) {
            agerr (AGERR, "renderer for %s is unavailable\n", job->output_langname);
	    gv_fixLocale (0);
	    if (Verbose) fprintf(stderr,"gvRenderJobs %s: %.2f secs.\n", agnameof(g), elapsed_sec());
            return -1;
        }

        switch (job->output_lang) {
        case 21:
            /* output sorted, i.e. all nodes then all edges */
            job->flags |= (1<<0);
            break;
        case 24:
            /* output in preorder traversal of the graph */
            job->flags |= (1<<3)
		       | (1<<9);
            break;
        default:
            job->flags |= chkOrder(g);
            break;
        }

	/* if we already have an active job list and the device doesn't support mutiple output files, or we are about to write to a different output device */
        firstjob = gvc->active_jobs;
        if (firstjob) {
	    if (! (firstjob->flags & (1<<5))
	      || (strcmp(job->output_langname,firstjob->output_langname))) {

	        gvrender_end_job(firstjob);
	    
            	gvc->active_jobs = NULL; /* clear active list */
	    	gvc->common.viewNum = 0;
	    	prevjob = NULL;
            }
        }
        else {
	    prevjob = NULL;
        }

	if (prevjob) {
            prevjob->next_active = job;  /* insert job in active list */
	    job->output_file = prevjob->output_file;  /* FIXME - this is dumb ! */
	}
	else {
	    if (gvrender_begin_job(job))
		continue;
	    gvc->active_jobs = job;   /* first job of new list */
	}
	job->next_active = NULL;      /* terminate active list */
	job->callbacks = &gvdevice_callbacks;

	init_job_pad(job);
	init_job_margin(job);
	init_job_dpi(job, g);
	init_job_viewport(job, g);
	init_job_pagination(job, g);

	if (! (job->flags & (1<<7))) {

    		


	    

	    emit_graph(job, g);
	}

        /* the last job, after all input graphs are processed,
         *      is finalized from gvFinalize()
         */
	prevjob = job;
    }
    gv_fixLocale (0);
    if (Verbose) fprintf(stderr,"gvRenderJobs %s: %.2f secs.\n", agnameof(g), elapsed_sec());
    return 0;
}

/* findStopColor:
 * Check for colon in colorlist. If one exists, and not the first
 * character, store the characters before the colon in clrs[0] and
 * the characters after the colon (and before the next or end-of-string)
 * in clrs[1]. If there are no characters after the first colon, clrs[1]
 * is NULL. Return TRUE.
 * If there is no non-trivial string before a first colon, set clrs[0] to
 * NULL and return FALSE.
 *
 * Note that memory is allocated as a single block stored in clrs[0] and
 * must be freed by calling function.
 */
boolean findStopColor (char* colorlist, char* clrs[2], float* frac)
{
    colorsegs_t* segs;
    int rv;

    rv = parseSegs (colorlist, 0, &segs);
    if (rv || (segs->numc < 2) || (segs->segs[0].color == NULL)) {
	clrs[0] = NULL;
	return 0;
    }

    if (segs->numc > 2)
	agerr (AGWARN, "More than 2 colors specified for a gradient - ignoring remaining\n");

    clrs[0] = (char*)gmalloc((strlen(colorlist)+1)*sizeof(char)); 
    strcpy (clrs[0], segs->segs[0].color);
    if (segs->segs[1].color) {
	clrs[1] = clrs[0] + (strlen(clrs[0])+1);
	strcpy (clrs[1], segs->segs[1].color);
    }
    else
	clrs[1] = NULL;

    if (segs->segs[0].hasFraction)
	*frac = segs->segs[0].t;
    else if (segs->segs[1].hasFraction)
	*frac = 1 - segs->segs[1].t;
    else 
	*frac = 0;

    freeSegs (segs);
    return NOT(0);
}

