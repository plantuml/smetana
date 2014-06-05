#line 1 "graphviz-2.38.0\\lib\\common\\shapes.c" 1
/* $id: shapes.c,v 1.82 2007/12/24 04:50:36 ellson Exp $ $Revision: 1.1 $ */
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








#line 16 "graphviz-2.38.0\\lib\\common\\shapes.c" 2
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






#line 17 "graphviz-2.38.0\\lib\\common\\shapes.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\shapes.c" 1




typedef struct {
    pointf (*size_gen) (pointf);
    void (*vertex_gen) (pointf*, pointf*);
} poly_desc_t;
 
static port Center = { {0, 0}, -1, 0, 0, 0, 1, 0, 0, 0 };


  /* Default point size = 0.05 inches or 3.6 points */

  /* Minimum point size = 0.0003 inches or 0.02 points
   * This will make the radius 0.01 points, which is the smallest
   * non-zero number output by gvprintdouble in gvdevice.c
   */

  /* extra null character needed to avoid style emitter from thinking
   * there are arguments.
   */
static char *point_style[3] = { "invis\0", "filled\0", 0 };

/* forward declarations of functions used in shapes tables */

static void poly_init(node_t * n);
static void poly_free(node_t * n);
static port poly_port(node_t * n, char *portname, char *);
static boolean poly_inside(inside_t * inside_context, pointf p);
static int poly_path(node_t * n, port * p, int side, boxf rv[], int *kptr);
static void poly_gencode(GVJ_t * job, node_t * n);

static void record_init(node_t * n);
static void record_free(node_t * n);
static port record_port(node_t * n, char *portname, char *);
static boolean record_inside(inside_t * inside_context, pointf p);
static int record_path(node_t * n, port * p, int side, boxf rv[],
		       int *kptr);
static void record_gencode(GVJ_t * job, node_t * n);

static void point_init(node_t * n);
static void point_gencode(GVJ_t * job, node_t * n);
static boolean point_inside(inside_t * inside_context, pointf p);

static boolean epsf_inside(inside_t * inside_context, pointf p);
static void epsf_gencode(GVJ_t * job, node_t * n);

static pointf star_size (pointf);
static void star_vertices (pointf*, pointf*);
static boolean star_inside(inside_t * inside_context, pointf p);
static poly_desc_t star_gen = {
    star_size,
    star_vertices,
};

/* polygon descriptions.  "polygon" with 0 sides takes all user control */

/*			       regul perip sides orien disto skew */
static polygon_t p_polygon = { 0, 1, 0, 0., 0., 0. };

/* builtin polygon descriptions */
static polygon_t p_ellipse = { 0, 1, 1, 0., 0., 0. };
static polygon_t p_circle = { (!(0)), 1, 1, 0., 0., 0. };
static polygon_t p_egg = { 0, 1, 1, 0., -.3, 0. };
static polygon_t p_triangle = { 0, 1, 3, 0., 0., 0. };
static polygon_t p_box = { 0, 1, 4, 0., 0., 0. };
static polygon_t p_square = { (!(0)), 1, 4, 0., 0., 0. };
static polygon_t p_plaintext = { 0, 0, 4, 0., 0., 0. };
static polygon_t p_diamond = { 0, 1, 4, 45., 0., 0. };
static polygon_t p_trapezium = { 0, 1, 4, 0., -.4, 0. };
static polygon_t p_parallelogram = { 0, 1, 4, 0., 0., .6 };
static polygon_t p_house = { 0, 1, 5, 0., -.64, 0. };
static polygon_t p_pentagon = { 0, 1, 5, 0., 0., 0. };
static polygon_t p_hexagon = { 0, 1, 6, 0., 0., 0. };
static polygon_t p_septagon = { 0, 1, 7, 0., 0., 0. };
static polygon_t p_octagon = { 0, 1, 8, 0., 0., 0. };
static polygon_t p_note = { 0, 1, 4, 0., 0., 0., (1 << 24) };
static polygon_t p_tab = { 0, 1, 4, 0., 0., 0., (2 << 24) };
static polygon_t p_folder = { 0, 1, 4, 0., 0., 0., (3 << 24) };
static polygon_t p_box3d = { 0, 1, 4, 0., 0., 0., (4 << 24) };
static polygon_t p_component = { 0, 1, 4, 0., 0., 0., (5 << 24) };
static polygon_t p_underline = { 0, 1, 4, 0., 0., 0., (1 << 10) };

/* redundant and undocumented builtin polygons */
static polygon_t p_doublecircle = { (!(0)), 2, 1, 0., 0., 0. };
static polygon_t p_invtriangle = { 0, 1, 3, 180., 0., 0. };
static polygon_t p_invtrapezium = { 0, 1, 4, 180., -.4, 0. };
static polygon_t p_invhouse = { 0, 1, 5, 180., -.64, 0. };
static polygon_t p_doubleoctagon = { 0, 2, 8, 0., 0., 0. };
static polygon_t p_tripleoctagon = { 0, 3, 8, 0., 0., 0. };
static polygon_t p_Mdiamond =
    { 0, 1, 4, 45., 0., 0., (1 << 3) | (1 << 4) };
static polygon_t p_Msquare = { (!(0)), 1, 4, 0., 0., 0., (1 << 3) };
static polygon_t p_Mcircle =
    { (!(0)), 1, 1, 0., 0., 0., (1 << 3) | (1 << 4) };

/* non-convex polygons */
static polygon_t p_star = { 0, 1, 10, 0., 0., 0., 0, (pointf*)&star_gen };

/* biological circuit shapes, as specified by SBOLv*/
/** gene expression symbols **/
static polygon_t p_promoter = { 0, 1, 4, 0., 0., 0., (6 << 24) };
static polygon_t p_cds = { 0, 1, 4, 0., 0., 0., (7 << 24) };
static polygon_t p_terminator = { 0, 1, 4, 0., 0., 0., (8 << 24)};
static polygon_t p_utr = { 0, 1, 4, 0., 0., 0., (9 << 24)};
static polygon_t p_insulator = { 0, 1, 4, 0., 0., 0., (17 << 24)};
static polygon_t p_ribosite = { 0, 1, 4, 0., 0., 0., (18 << 24)};
static polygon_t p_rnastab = { 0, 1, 4, 0., 0., 0., (19 << 24)};
static polygon_t p_proteasesite = { 0, 1, 4, 0., 0., 0., (20 << 24)};
static polygon_t p_proteinstab = { 0, 1, 4, 0., 0., 0., (21 << 24)};
/** dna construction symbols **/
static polygon_t p_primersite = { 0, 1, 4, 0., 0., 0., (10 << 24)};
static polygon_t p_restrictionsite = { 0, 1, 4, 0., 0., 0., (11 << 24)};
static polygon_t p_fivepoverhang = { 0, 1, 4, 0., 0., 0., (12 << 24)};
static polygon_t p_threepoverhang = { 0, 1, 4, 0., 0., 0., (13 << 24)};
static polygon_t p_noverhang = { 0, 1, 4, 0., 0., 0., (14 << 24)};
static polygon_t p_assembly = { 0, 1, 4, 0., 0., 0., (15 << 24)};
static polygon_t p_signature = { 0, 1, 4, 0., 0., 0., (16 << 24)};
static polygon_t p_rpromoter = { 0, 1, 4, 0., 0., 0., (22 << 24)};
static polygon_t p_rarrow = { 0, 1, 4, 0., 0., 0., (23 << 24)};
static polygon_t p_larrow = { 0, 1, 4, 0., 0., 0., (24 << 24)};
static polygon_t p_lpromoter = { 0, 1, 4, 0., 0., 0., (25 << 24)};



/* True if style requires processing through round_corners. */



/*
 * every shape has these functions:
 *
 * void		SHAPE_init(node_t *n)
 *			initialize the shape (usually at least its size).
 * void		SHAPE_free(node_t *n)
 *			free all memory used by the shape
 * port		SHAPE_port(node_t *n, char *portname)
 *			return the aiming point and slope (if constrained)
 *			of a port.
 * int		SHAPE_inside(inside_t *inside_context, pointf p, edge_t *e);
 *			test if point is inside the node shape which is
 *			assumed convex.
 *			the point is relative to the node center.  the edge
 *			is passed in case the port affects spline clipping.
 * int		SHAPE_path(node *n, edge_t *e, int pt, boxf path[], int *nbox)
 *			create a path for the port of e that touches n,
 *			return side
 * void		SHAPE_gencode(GVJ_t *job, node_t *n)
 *			generate graphics code for a node.
 *
 * some shapes, polygons in particular, use additional shape control data *
 *
 */

static shape_functions poly_fns = {
    poly_init,
    poly_free,
    poly_port,
    poly_inside,
    poly_path,
    poly_gencode
};
static shape_functions point_fns = {
    point_init,
    poly_free,
    poly_port,
    point_inside,
    NULL,
    point_gencode
};
static shape_functions record_fns = {
    record_init,
    record_free,
    record_port,
    record_inside,
    record_path,
    record_gencode
};
static shape_functions epsf_fns = {
    epsf_init,
    epsf_free,
    poly_port,
    epsf_inside,
    NULL,
    epsf_gencode
};
static shape_functions star_fns = {
    poly_init,
    poly_free,
    poly_port,
    star_inside,
    poly_path,
    poly_gencode
};

static shape_desc Shapes[] = {	/* first entry is default for no such shape */
    {"box", &poly_fns, &p_box},
    {"polygon", &poly_fns, &p_polygon},
    {"ellipse", &poly_fns, &p_ellipse},
    {"oval", &poly_fns, &p_ellipse},
    {"circle", &poly_fns, &p_circle},
    {"point", &point_fns, &p_circle},
    {"egg", &poly_fns, &p_egg},
    {"triangle", &poly_fns, &p_triangle},
    {"none", &poly_fns, &p_plaintext},
    {"plaintext", &poly_fns, &p_plaintext},
    {"diamond", &poly_fns, &p_diamond},
    {"trapezium", &poly_fns, &p_trapezium},
    {"parallelogram", &poly_fns, &p_parallelogram},
    {"house", &poly_fns, &p_house},
    {"pentagon", &poly_fns, &p_pentagon},
    {"hexagon", &poly_fns, &p_hexagon},
    {"septagon", &poly_fns, &p_septagon},
    {"octagon", &poly_fns, &p_octagon},
    {"note", &poly_fns, &p_note},
    {"tab", &poly_fns, &p_tab},
    {"folder", &poly_fns, &p_folder},
    {"box3d", &poly_fns, &p_box3d},
    {"component", &poly_fns, &p_component},
    {"rect", &poly_fns, &p_box},
    {"rectangle", &poly_fns, &p_box},
    {"square", &poly_fns, &p_square},
    {"doublecircle", &poly_fns, &p_doublecircle},
    {"doubleoctagon", &poly_fns, &p_doubleoctagon},
    {"tripleoctagon", &poly_fns, &p_tripleoctagon},
    {"invtriangle", &poly_fns, &p_invtriangle},
    {"invtrapezium", &poly_fns, &p_invtrapezium},
    {"invhouse", &poly_fns, &p_invhouse},
    {"underline", &poly_fns, &p_underline},
    {"Mdiamond", &poly_fns, &p_Mdiamond},
    {"Msquare", &poly_fns, &p_Msquare},
    {"Mcircle", &poly_fns, &p_Mcircle},
	/* biological circuit shapes, as specified by SBOLv*/
	/** gene expression symbols **/
    {"promoter", &poly_fns, &p_promoter},
    {"cds",  &poly_fns, &p_cds},
    {"terminator",  &poly_fns, &p_terminator},
    {"utr",  &poly_fns, &p_utr},
    {"insulator", &poly_fns, &p_insulator},
    {"ribosite", &poly_fns, &p_ribosite},
    {"rnastab", &poly_fns, &p_rnastab},
    {"proteasesite", &poly_fns, &p_proteasesite},
    {"proteinstab", &poly_fns, &p_proteinstab},
	/** dna construction symbols **/
    {"primersite",  &poly_fns, &p_primersite},
    {"restrictionsite", &poly_fns, &p_restrictionsite},
    {"fivepoverhang", &poly_fns, &p_fivepoverhang},
    {"threepoverhang", &poly_fns, &p_threepoverhang},
    {"noverhang", &poly_fns, &p_noverhang},
    {"assembly", &poly_fns, &p_assembly},
    {"signature", &poly_fns, &p_signature},
    {"rpromoter", &poly_fns, &p_rpromoter},
    {"larrow",  &poly_fns, &p_larrow},
    {"rarrow",  &poly_fns, &p_rarrow},
    {"lpromoter",  &poly_fns, &p_lpromoter},
	/*  *** shapes other than polygons  *** */
    {"record", &record_fns, NULL},
    {"Mrecord", &record_fns, NULL},
    {"epsf", &epsf_fns, NULL},
    {"star", &star_fns, &p_star},
    {NULL, NULL, NULL}
};

static void unrecognized(node_t * n, char *p)
{
    agerr(AGWARN, "node %s, port %s unrecognized\n", agnameof(n), p);
}

static double quant(double val, double q)
{
    int i;
    i = val / q;
    if (i * q + .00001 < val)
	i++;
    return i * q;
}

/* test if both p0 and p1 are on the same side of the line L0,L1 */
static int same_side(pointf p0, pointf p1, pointf L0, pointf L1)
{
    int s0, s1;
    double a, b, c;

    /* a x + b y = c */
    a = -(L1.y - L0.y);
    b = (L1.x - L0.x);
    c = a * L0.x + b * L0.y;

    s0 = (a * p0.x + b * p0.y - c >= 0);
    s1 = (a * p1.x + b * p1.y - c >= 0);
    return (s0 == s1);
}

static
char* penColor(GVJ_t * job, node_t * n)
{
    char *color;

    color = late_nnstring(n, N_color, "");
    if (!color[0])
	color = "black";
    gvrender_set_pencolor(job, color);
    return color;
}

static
char *findFillDflt(node_t * n, char *dflt)
{
    char *color;

    color = late_nnstring(n, N_fillcolor, "");
    if (!color[0]) {
	/* for backward compatibilty, default fill is same as pen */
	color = late_nnstring(n, N_color, "");
	if (!color[0]) {
	    color = dflt;
	}
    }
    return color;
}

static
char *findFill(node_t * n)
{
    return (findFillDflt(n, "lightgrey"));
}

char *findAttrColor(void *obj, attrsym_t *colorattr, char *dflt){
    char *color;

    if(colorattr != NULL)
      color = late_nnstring(obj, colorattr, dflt);
    else if(dflt != NULL && dflt[0])
      color = dflt;
    else
      color = "lightgrey";
    return color;
}


static int
isBox (node_t* n)
{
    polygon_t *p;

    if ((p = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon)) {
	return (p->sides == 4 && (((p->orientation>=0)?(int)(p->orientation + .5):(int)(p->orientation - .5)) % 90) == 0 && p->distortion == 0. && p->skew == 0.);
    }
    else
	return 0;
}

/* isEllipse:
 */
static int
isEllipse(node_t* n)
{
    polygon_t *p;

    if ((p = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon)) {
	return (p->sides <= 2);
    }
    else
	return 0;
}

static char **checkStyle(node_t * n, int *flagp)
{
    char *style;
    char **pstyle = 0;
    int istyle = 0;
    polygon_t *poly;

    style = late_nnstring(n, N_style, "");
    if (style[0]) {
	char **pp;
	char **qp;
	char *p;
	pp = pstyle = parse_style(style);
	while ((p = *pp)) {
	    if ((*(p)==*("filled")&&!strcmp(p,"filled"))) {
		istyle |= (1 << 0);
		pp++;
	    } else if ((*(p)==*("rounded")&&!strcmp(p,"rounded"))) {
		istyle |= (1 << 2);
		qp = pp;	/* remove rounded from list passed to renderer */
		do {
		    qp++;
		    *(qp - 1) = *qp;
		} while (*qp);
	    } else if ((*(p)==*("diagonals")&&!strcmp(p,"diagonals"))) {
		istyle |= (1 << 3);
		qp = pp;	/* remove diagonals from list passed to renderer */
		do {
		    qp++;
		    *(qp - 1) = *qp;
		} while (*qp);
	    } else if ((*(p)==*("invis")&&!strcmp(p,"invis"))) {
		istyle |= (1 << 5);
		pp++;
	    } else if ((*(p)==*("radial")&&!strcmp(p,"radial"))) {
		istyle |= ((1 << 1)|(1 << 0));
		qp = pp;	/* remove radial from list passed to renderer */
		do {
		    qp++;
		    *(qp - 1) = *qp;
		} while (*qp);
	    } else if ((*(p)==*("striped")&&!strcmp(p,"striped")) && isBox(n)) {
		istyle |= (1 << 6);
		qp = pp;	/* remove striped from list passed to renderer */
		do {
		    qp++;
		    *(qp - 1) = *qp;
		} while (*qp);
	    } else if ((*(p)==*("wedged")&&!strcmp(p,"wedged")) && isEllipse(n)) {
		istyle |= (1 << 9);
		qp = pp;	/* remove wedged from list passed to renderer */
		do {
		    qp++;
		    *(qp - 1) = *qp;
		} while (*qp);
	    } else
		pp++;
	}
    }
    if ((poly = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon))
	istyle |= poly->option;

    *flagp = istyle;
    return pstyle;
}

static int stylenode(GVJ_t * job, node_t * n)
{
    char **pstyle, *s;
    int istyle;
    double penwidth;

    if ((pstyle = checkStyle(n, &istyle)))
	gvrender_set_style(job, pstyle);

    if (N_penwidth && ((s = agxget(n, N_penwidth)) && s[0])) {
	penwidth = late_double(n, N_penwidth, 1.0, 0.0);
	gvrender_set_penwidth(job, penwidth);
    }

    return istyle;
}

static void Mcircle_hack(GVJ_t * job, node_t * n)
{
    double x, y;
    pointf AF[2], p;

    y = .7500;
    x = .6614;			/* x^2 + y^2 = 1.0 */
    p.y = y * (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2.0;
    p.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) * x;		/* assume node is symmetric */

    AF[0] = add_pointf(p, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord));
    AF[1].y = AF[0].y;
    AF[1].x = AF[0].x - 2 * p.x;
    gvrender_polyline(job, AF, 2);
    AF[0].y -= 2 * p.y;
    AF[1].y = AF[0].y;
    gvrender_polyline(job, AF, 2);
}

/* round_corners:
 * Handle some special graphical cases, such as rounding the shape,
 * adding diagonals at corners, or drawing certain non-simple figures.
 * Any drawing done here should assume fillcolors, pencolors, etc.
 * have been set by the calling routine. Normally, the drawing should
 * consist of a region, filled or unfilled, followed by additional line
 * segments. A single fill is necessary for gradient colors to work.
 */
void round_corners(GVJ_t * job, pointf * AF, int sides, int style, int filled)
{
    pointf *B, C[5], *D, p0, p1;
    double rbconst, d, dx, dy, t;
    int i, seg, mode, shape;
    pointf* pts;

    shape = style & (127 << 24);
    if (style & (1 << 3))
	mode = (1 << 3);
    else if (style & (127 << 24))
	mode = shape;
    else
	mode = (1 << 2);
    B = (pointf*)zmalloc((4 * sides + 4)*sizeof(pointf));
    i = 0;
    /* rbconst is distance offset from a corner of the polygon.
     * It should be the same for every corner, and also never
     * bigger than one-third the length of a side.
     */
    rbconst = 12;
    for (seg = 0; seg < sides; seg++) {
	p0 = AF[seg];
	if (seg < sides - 1)
	    p1 = AF[seg + 1];
	else
	    p1 = AF[0];
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	d = sqrt(dx * dx + dy * dy);
	rbconst = ((rbconst)<(d / 3.0)?(rbconst):(d / 3.0));
    }
    for (seg = 0; seg < sides; seg++) {
	p0 = AF[seg];
	if (seg < sides - 1)
	    p1 = AF[seg + 1];
	else
	    p1 = AF[0];
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	d = sqrt(dx * dx + dy * dy);
	t = rbconst / d;
	if (shape == (4 << 24) || shape == (5 << 24))
	    t /= 3;
	else if (shape == (1 << 24))
	    t /= 2;
	if (mode != (1 << 2))
	    B[i++] = p0;
	else 
	    B[i++] = interpolate_pointf(.5 * t, p0, p1);
	B[i++] = interpolate_pointf(t, p0, p1);
	B[i++] = interpolate_pointf(1.0 - t, p0, p1);
	if (mode == (1 << 2))
	    B[i++] = interpolate_pointf(1.0 - .5 * t, p0, p1);
    }
    B[i++] = B[0];
    B[i++] = B[1];
    B[i++] = B[2];

    switch (mode) {
    case (1 << 2):
	pts = (pointf*)gmalloc((6 * sides + 2)*sizeof(pointf));
	i = 0;
	for (seg = 0; seg < sides; seg++) {
	    pts[i++] = B[4 * seg];
	    pts[i++] = B[4 * seg+1];
	    pts[i++] = B[4 * seg+1];
	    pts[i++] = B[4 * seg+2];
	    pts[i++] = B[4 * seg+2];
	    pts[i++] = B[4 * seg+3];
	}
	pts[i++] = pts[0];
	pts[i++] = pts[1];
	gvrender_beziercurve(job, pts+1, i-1, 0, 0, filled);
	free (pts);
	

	
	    
		
		
	    
	    
	    
	    
	    
	
	
	    
		
		
	    
	

	break;
    case (1 << 3):
	/* diagonals are weird.  rewrite someday. */
	gvrender_polygon(job, AF, sides, filled);

	for (seg = 0; seg < sides; seg++) {

	    
	    
	    

	    C[0] = B[3 * seg + 2];
	    C[1] = B[3 * seg + 4];
	    gvrender_polyline(job, C, 2);
	}
	break;
    case (1 << 24):
	/* Add the cutoff edge. */
	D = (pointf*)zmalloc((sides + 1)*sizeof(pointf));
	for (seg = 1; seg < sides; seg++)
	    D[seg] = AF[seg];
	D[0] = B[3 * (sides - 1) + 4];
	D[sides] = B[3 * (sides - 1) + 2];
	gvrender_polygon(job, D, sides + 1, filled);
	free(D);

	/* Draw the inner edge. */
	seg = sides - 1;
	C[0] = B[3 * seg + 2];
	C[1] = B[3 * seg + 4];
	C[2].x = C[1].x + (C[0].x - B[3 * seg + 3].x);
	C[2].y = C[1].y + (C[0].y - B[3 * seg + 3].y);
	gvrender_polyline(job, C + 1, 2);
	C[1] = C[2];
	gvrender_polyline(job, C, 2);
	break;
    case (2 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  D[3] +--+ D[2]
	 *       |  |          B[1]
	 *  B[3] +  +----------+--+ AF[0]=B[0]=D[0]
	 *       |  B[2]=D[1]     |
	 *  B[4] +                |
	 *       |                |
	 *  B[5] +                |
	 *       +----------------+
	 *
	 */
	/* Add the tab edges. */
	D = (pointf*)zmalloc((sides + 2)*sizeof(pointf));
	D[0] = AF[0];
	D[1] = B[2];
	D[2].x = B[2].x + (B[3].x - B[4].x) / 3;
	D[2].y = B[2].y + (B[3].y - B[4].y) / 3;
	D[3].x = B[3].x + (B[3].x - B[4].x) / 3;
	D[3].y = B[3].y + (B[3].y - B[4].y) / 3;
	for (seg = 4; seg < sides + 2; seg++)
	    D[seg] = AF[seg - 2];
	gvrender_polygon(job, D, sides + 2, filled);
	free(D);


	/* Draw the inner edge. */
	C[0] = B[3];
	C[1] = B[2];
	gvrender_polyline(job, C, 2);
	break;
    case (3 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *            D[2] +----+ D[1]
	 *  B[3]=         /      	 *  D[4] +--+----+     +  + AF[0]=B[0]=D[0]

	 *       |  B[2] D[3] B[1]|
	 *  B[4] +                |
	 *       |                |
	 *  B[5] +                |
	 *       +----------------+
	 *
	 */
	/* Add the folder edges. */
	D = (pointf*)zmalloc((sides + 3)*sizeof(pointf));
	D[0] = AF[0];
	D[1].x = AF[0].x - (AF[0].x - B[1].x) / 4;
	D[1].y = AF[0].y + (B[3].y - B[4].y) / 3;
	D[2].x = AF[0].x - 2 * (AF[0].x - B[1].x);
	D[2].y = D[1].y;
	D[3].x = AF[0].x - 2.25 * (AF[0].x - B[1].x);
	D[3].y = B[3].y;
	D[4].x = B[3].x;
	D[4].y = B[3].y;
	for (seg = 4; seg < sides + 3; seg++)
	    D[seg] = AF[seg - 3];
	gvrender_polygon(job, D, sides + 3, filled);
	free(D);
	break;
    case (4 << 24):
	assert(sides == 4);
	/* Adjust for the cutoff edges. */
	D = (pointf*)zmalloc((sides + 2)*sizeof(pointf));
	D[0] = AF[0];
	D[1] = B[2];
	D[2] = B[4];
	D[3] = AF[2];
	D[4] = B[8];
	D[5] = B[10];
	gvrender_polygon(job, D, sides + 2, filled);
	free(D);

	/* Draw the inner vertices. */
	C[0].x = B[1].x + (B[11].x - B[0].x);
	C[0].y = B[1].y + (B[11].y - B[0].y);
	C[1] = B[4];
	gvrender_polyline(job, C, 2);
	C[1] = B[8];
	gvrender_polyline(job, C, 2);
	C[1] = B[0];
	gvrender_polyline(job, C, 2);
	break;
    case (5 << 24):
	assert(sides == 4);
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  D[1] +----------------+ D[0]
	 *       |                |
	 *  3+---+2               |
	 *   |                    |
	 *  4+---+5               |
	 *       |                |
	 *  7+---+6               |
	 *   |                    |
	 *  8+---+9               |
	 *       |                |
	 *     10+----------------+ D[11]
	 *
	 */
	D = (pointf*)zmalloc((sides + 8)*sizeof(pointf));
	D[0] = AF[0];
	D[1] = AF[1];
	D[2].x = B[3].x + (B[4].x - B[3].x);
	D[2].y = B[3].y + (B[4].y - B[3].y);
	D[3].x = D[2].x + (B[3].x - B[2].x);
	D[3].y = D[2].y + (B[3].y - B[2].y);
	D[4].x = D[3].x + (B[4].x - B[3].x);
	D[4].y = D[3].y + (B[4].y - B[3].y);
	D[5].x = D[4].x + (D[2].x - D[3].x);
	D[5].y = D[4].y + (D[2].y - D[3].y);

	D[9].x = B[6].x + (B[5].x - B[6].x);
	D[9].y = B[6].y + (B[5].y - B[6].y);
	D[8].x = D[9].x + (B[6].x - B[7].x);
	D[8].y = D[9].y + (B[6].y - B[7].y);
	D[7].x = D[8].x + (B[5].x - B[6].x);
	D[7].y = D[8].y + (B[5].y - B[6].y);
	D[6].x = D[7].x + (D[9].x - D[8].x);
	D[6].y = D[7].y + (D[9].y - D[8].y);

	D[10] = AF[2];
	D[11] = AF[3];
	gvrender_polygon(job, D, sides + 8, filled);

	/* Draw the internal vertices. */
	C[0] = D[2];
	C[1].x = D[2].x - (D[3].x - D[2].x);
	C[1].y = D[2].y - (D[3].y - D[2].y);
	C[2].x = C[1].x + (D[4].x - D[3].x);
	C[2].y = C[1].y + (D[4].y - D[3].y);
	C[3] = D[5];
	gvrender_polyline(job, C, 4);
	C[0] = D[6];
	C[1].x = D[6].x - (D[7].x - D[6].x);
	C[1].y = D[6].y - (D[7].y - D[6].y);
	C[2].x = C[1].x + (D[8].x - D[7].x);
	C[2].y = C[1].y + (D[8].y - D[7].y);
	C[3] = D[9];
	gvrender_polyline(job, C, 4);

	free(D);
	break;

    case (6 << 24):
	/*
	 * L-shaped arrow on a center line, scales in the x direction
	 *
	 *  
	 *      D[1]	          |	 *       +----------------+ 	 *       |	        D[0] 	 *       |                    	 *       |                    /    




	 *       |             D[5]  /
	 *       |        +-------+ /
	 *       |	  |       |/
	 *	 +--------+
	 */
	/* Add the tab edges. */
				
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//the arrow's thickness is (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides + 5)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (AF[0].x - AF[1].x)/8; //x_center + width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)*3/2; //D[4].y + width
	D[1].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (AF[0].x - AF[1].x)/4; //x_center - 2*width
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	D[3].x = D[2].x + (B[2].x - B[3].x)/2; //D[2].x + width
	D[3].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	D[4].x = D[3].x;
	D[4].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y); //highest cds point 
	D[5].x = D[0].x;
	D[5].y = D[4].y; //highest cds point
	D[6].x = D[0].x;
	D[6].y = D[4].y - (B[3].y-B[4].y)/4; //D[4].y - width/2 
	D[7].x = D[6].x + (B[2].x - B[3].x); //D[6].x + 2*width
	D[7].y = D[6].y + (B[3].y - B[4].y)/2; //D[6].y + width
	D[8].x = D[0].x;
	D[8].y = D[0].y + (B[3].y - B[4].y)/4;//D[0].y + width/2
	gvrender_polygon(job, D, sides + 5, filled);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);			
			
	break;
				
    case (7 << 24):
	/*
	 * arrow without the protrusions, scales normally
	 *
	 *  
	 *      D[1] = AF[1]      
	 *       +----------------+	 *       |		D[0]	 *       |                   	 *       |                   /    



	 *       |                  /
	 *       +----------------+/
	 *	  	          D[3]
	 *	 
	 */
	D = (pointf*)zmalloc((sides + 1)*sizeof(pointf));
	D[0].x = B[1].x;
	D[0].y = B[1].y - (B[3].y - B[4].y)/2;
	D[1].x = B[3].x;
	D[1].y = B[3].y - (B[3].y - B[4].y)/2;
	D[2].x = AF[2].x;
	D[2].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[3].x = B[1].x;
	D[3].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[4].y = AF[0].y - (AF[0].y - AF[3].y)/2;
	D[4].x = AF[0].x;
				
	gvrender_polygon(job, D, sides + 1, filled);
	free(D);

	break;

    case (8 << 24):
	/*
	* T-shape, does not scale, always in the center
	*
	*  
	*      D[4]      
	*       +----------------+
	*       |		D[3]
	*       |                |
	*       |                |    
	*       |  D[6]    D[1]  |
	*   D[5]+---+       +----+ D[2]
	*	    |	    |     
	*	    +-------+ D[0]
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	D = (pointf*)zmalloc((sides + 4)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/4; //x_center + width/2
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/2;
	D[2].x = D[1].x + (B[2].x-B[3].x)/2;
	D[2].y = D[1].y;
	D[3].x = D[2].x;
	D[3].y = D[2].y + (B[3].y-B[4].y)/2;
	D[4].x = AF[1].x + (AF[0].x-AF[1].x)/2 - (B[2].x-B[3].x)*3/4; //D[3].y mirrowed across the center
	D[4].y = D[3].y;
	D[5].x = D[4].x;
	D[5].y = D[2].y;
	D[6].x = AF[1].x + (AF[0].x-AF[1].x)/2 - (B[2].x-B[3].x)/4; //D[1].x mirrowed across the center
	D[6].y = D[1].y;
	D[7].x = D[6].x;
	D[7].y = D[0].y;
	gvrender_polygon(job, D, sides + 4, filled);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;

    case (9 << 24):
	/*
	 * half-octagon with line, does not scale, always in center
	 *
	 *  D[3]
	 *     _____  D[2] 
	 *    /     	 *   /       \ D[1]

	 *   |       |
	 *   -----------
	 *              D[0]   
	 *      
	 *	
	 *	          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	D = (pointf*)zmalloc((sides + 2)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)*3/4; //x_center+width	
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/4; //D[0].y+width/2
	D[2].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/4; //x_center+width/2
	D[2].y = D[1].y + (B[3].y-B[4].y)/2; //D[1].y+width
	D[3].x = AF[1].x + (AF[0].x-AF[1].x)/2 - (B[2].x-B[3].x)/4; //D[2].x mirrowed across the center
	D[3].y = D[2].y;
	D[4].x = AF[1].x + (AF[0].x-AF[1].x)/2 - (B[2].x-B[3].x)*3/4;
	D[4].y = D[1].y;
	D[5].x = D[4].x;
	D[5].y = D[0].y;
	gvrender_polygon(job, D, sides + 2, filled);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;
    case (10 << 24):
	/*
	* half arrow shape, scales in the x-direction
	*                 D[1]
	*		    |	*		    | 	*		    |  	*	------------    	*	|		 	*	------------------\ D[0]			 





	*				
	*   --------------------------------
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides + 1)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x);//x_center + width*2
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/4;//y_center + 1/2 width
	D[1].x = D[0].x - (B[2].x-B[3].x); //x_center
	D[1].y = D[0].y + (B[3].y-B[4].y);
	D[2].x = D[1].x;
	D[2].y = D[0].y + (B[3].y-B[4].y)/2;
	D[3].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (AF[0].x - AF[1].x)/4;//x_center - 2*(scalable width)
	D[3].y = D[2].y;
	D[4].x = D[3].x;
	D[4].y = D[0].y;
	gvrender_polygon(job, D, sides + 1, filled);
				
	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;
    case (11 << 24):
	/*
	* zigzag shape, scales in the x-direction (only the middle section)
	*
	*		 
	*   ----D[2]	 
	*   |   |________ D[0]
	*   |            |____
	*   ----------	 |
	*   D[4]      --- D[7]
	*				
	*   
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides + 4)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (AF[0].x - AF[1].x)/8 + (B[2].x-B[3].x)/2;//x_center + scalable_width + width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/4;//y_center + 1/2 width
	D[1].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (AF[0].x - AF[1].x)/8; //x_center - width
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[2].x - (B[2].x-B[3].x)/2; //D[2].x - width
	D[3].y = D[2].y;
	D[4].x = D[3].x;
	D[4].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)/4; //y_center - 1/2(width)
	D[5].x = D[0].x - (B[2].x-B[3].x)/2;
	D[5].y = D[4].y;
	D[6].x = D[5].x;
	D[6].y = D[5].y - (B[3].y-B[4].y)/2;
	D[7].x = D[0].x;
	D[7].y = D[6].y;
	gvrender_polygon(job, D, sides + 4, filled);
				
	/*dsDNA line left half*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = D[4].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);

	/*dsDNA line right half*/
	C[0].x = D[7].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);			    
	free(D);

	break;	
    case (12 << 24):
	/*
	*  does not scale, on the left side
	*
	*  D[3]------D[2]	 
	*  |          |
	*  D[0]------D[1]
	*        -----  ------------
	*        |    |
	*       D[0]--D[1]
	*				
	*   
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x;//the very left edge
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8;//y_center + 1/4 width
	D[1].x = D[0].x + 2*(B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*second, lower shape*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (B[2].x-B[3].x);
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)*5/8; //y_center - 5/4 width
	D[1].x = D[0].x + (B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*dsDNA line right half*/
	C[0].x = D[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);			    
	free(D);

	break;	
    case (13 << 24):
	/*
	*  does not scale, on the right side
	*
	*	   D[2]------D[1]	 
	*	   |          |
	*----------D[3]------D[0]
	*	   -----  D[1]
	*          |    |
	*          D[3]--D[0]
	*				
	*   
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[0].x;//the very right edge
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8;//y_center + 1/4 width
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/2;
	D[2].x = D[1].x - 2*(B[3].y-B[4].y);
	D[2].y = D[1].y;
	D[3].x = D[2].x;
	D[3].y = D[0].y;
	gvrender_polygon(job, D, sides, filled);

	/*second, lower shape*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[0].x - (B[2].x-B[3].x);
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)*5/8; //y_center - 5/4 width
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/2;
	D[2].x = D[1].x - (B[3].y-B[4].y);
	D[2].y = D[1].y;
	D[3].x = D[2].x;
	D[3].y = D[0].y;
	gvrender_polygon(job, D, sides, filled);

	/*dsDNA line left half*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = D[3].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);			    
	free(D);

	break;	
    case (14 << 24):
	/*
	*  does not scale
	*
	*     D[3]------D[2]   D[3]------D[2]    
	*     |          |      |          |
	*  ---D[0]------D[1]   D[0]------D[1]----
	*     D[3]------D[2]   D[3]------D[2]    
	*     |          |	|          |
	*     D[0]------D[1]   D[0]------D[1]
	*        
	*				
	*   
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	/*upper left rectangle*/
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)*9/8; //x_center - 2*width - 1/4*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8;//y_center + 1/4 width
	D[1].x = D[0].x + (B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*lower, left rectangle*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)*9/8; //x_center - 2*width - 1/4*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)*5/8;//y_center - width - 1/4 width
	D[1].x = D[0].x + (B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*lower, right rectangle*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x)/8; //x_center + 1/4*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)*5/8;//y_center - width - 1/4 width
	D[1].x = D[0].x + (B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*upper, right rectangle*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x)/8; //x_center + 1/4*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8;//y_center - width - 1/4 width
	D[1].x = D[0].x + (B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);
	
	/*dsDNA line right half*/
	C[0].x = D[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);

	/*dsDNA line left half*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)*9/8; //D[0].x of of the left rectangles
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[1].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);			    
	free(D);

	break;	
    case (15 << 24):
	/*
	*  does not scale
	*
	*      D[3]----------D[2]	 
	*      |               |
	*     D[0]----------D[1]
	* ----                  ---------
	*      D[3]----------D[2]	 
	*      |               |
	*     D[0]----------D[1]
	*  
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x); //x_center - 2*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8;//y_center + 1/4 width
	D[1].x = D[0].x + 2*(B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*second, lower shape*/
	free(D);
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x); //x_center - 2*width
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)*5/8;//y_center - width - 1/4 width
	D[1].x = D[0].x + 2*(B[2].x-B[3].x);
	D[1].y = D[0].y;
	D[2].x = D[1].x;
	D[2].y = D[1].y + (B[3].y-B[4].y)/2;
	D[3].x = D[0].x;
	D[3].y = D[2].y;
	gvrender_polygon(job, D, sides, filled);

	/*dsDNA line right half*/
	C[0].x = D[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);

	/*dsDNA line left half*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = D[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);
	free(D);

	break;	
    case (16 << 24):
	/*
	*   
	* 
	*   +--------------+
	*   |		   |
	*   |x		   |
	*   |_____________ |
	*   +--------------+
	*/
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2;
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	//the thickness is subituted with (AF[0].x - AF[1].x)/8 to make it scalable in the y with label length
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[0].x;
	D[0].y = B[1].y - (B[3].y - B[4].y)/2;
	D[1].x = B[3].x;
	D[1].y = B[3].y - (B[3].y - B[4].y)/2;
	D[2].x = AF[2].x;
	D[2].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[3].x = AF[0].x;
	D[3].y = AF[2].y + (B[3].y - B[4].y)/2;
	gvrender_polygon(job, D, sides, filled);

	/* "\" of the X*/
	C[0].x = AF[1].x + (B[2].x-B[3].x)/4;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/8; //y_center + 1/4 width
	C[1].x = C[0].x + (B[2].x-B[3].x)/4;//C[0].x + width/2
	C[1].y = C[0].y - (B[3].y-B[4].y)/4;//C[0].y - width/2
	gvrender_polyline(job, C, 2);
	
	/*"/" of the X*/
	C[0].x = AF[1].x + (B[2].x-B[3].x)/4;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[3].y-B[4].y)/8; //y_center - 1/4 width
	C[1].x = C[0].x + (B[2].x-B[3].x)/4;//C[0].x + width/2
	C[1].y = C[0].y + (B[3].y-B[4].y)/4;//C[0].y + width/2
	gvrender_polyline(job, C, 2);	

	/*bottom line*/
	C[0].x = AF[1].x + (B[2].x-B[3].x)/4;
	C[0].y = AF[2].y + (B[3].y-B[4].y)*3/4;
	C[1].x = AF[0].x - (B[2].x-B[3].x)/4;
	C[1].y = C[0].y;
	gvrender_polyline(job, C, 2);
	free(D);

	break;	
    case (17 << 24):
	/*
	 * double square
	 *
	 *  +-----+
	 *--| ___ |---
	 *  | |_| |
	 *  +-----+
	 *	          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	D = (pointf*)zmalloc((sides)*sizeof(pointf));
	D[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x)/2; //x_center+width	
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[2].x-B[3].x)/2; //y_center
	D[1].x = D[0].x;
	D[1].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[2].x-B[3].x)/2; //D[0].y- width
	D[2].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)/2; //x_center-width
	D[2].y = D[1].y;
	D[3].x = D[2].x;
	D[3].y = D[0].y;
	gvrender_polygon(job, D, sides, filled);
	free(D);

	/*outer square line*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x)*3/4; //x_center+1.5*width	
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[2].x-B[3].x)*3/4; //y_center
	C[1].x = C[0].x;
	C[1].y = AF[2].y + (AF[1].y - AF[2].y)/2 - (B[2].x-B[3].x)*3/4; //y_center- 1.5*width
	C[2].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)*3/4; //x_center-1.5*width
	C[2].y = C[1].y;
	C[3].x = C[2].x;
	C[3].y = C[0].y;
	C[4] = C[0];
	gvrender_polyline(job, C, 5);		        
	
	/*dsDNA line right half*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2 + (B[2].x-B[3].x)*3/4;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);

	/*dsDNA line left half*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[1].x + (AF[0].x - AF[1].x)/2 - (B[2].x-B[3].x)*3/4;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);

	break;
    case (18 << 24):
	/*
	 * X with a dashed line on the bottom
	 * 
	 *
	 *           X
	 *	     |
	 *	------------          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;

	D = (pointf*)zmalloc((sides + 12)*sizeof(pointf)); //12-sided x
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/4; //x_center+widtht/2 , lower right corner of the x
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/2; //y_center + width
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/8; //D[0].y +width/4
	D[2].x = D[0].x - (B[2].x-B[3].x)/8; //D[0].x- width/4 //right nook of the x
	D[2].y = D[1].y + (B[3].y-B[4].y)/8; //D[0].y+width/2 or D[1].y+width/4
	D[3].x = D[0].x;
	D[3].y = D[2].y + (B[3].y-B[4].y)/8; //D[2].y + width/4
	D[4].x = D[0].x;
	D[4].y = D[3].y + (B[3].y-B[4].y)/8; //top right corner of the x
	D[5].x = D[2].x;
	D[5].y = D[4].y;
	D[6].x = AF[1].x + (AF[0].x - AF[1].x)/2; //x_center
	D[6].y = D[3].y; //top nook
	D[7].x = D[6].x - (B[2].x-B[3].x)/8; //D[5] mirrowed across y
	D[7].y = D[5].y;
	D[8].x = D[7].x - (B[2].x-B[3].x)/8;//top left corner
	D[8].y = D[7].y;
	D[9].x = D[8].x;
	D[9].y = D[3].y;
	D[10].x = D[8].x + (B[2].x-B[3].x)/8;
	D[10].y = D[2].y;
	D[11].x = D[8].x;
	D[11].y = D[1].y;
	D[12].x = D[8].x;
	D[12].y = D[0].y;
	D[13].x = D[10].x;
	D[13].y = D[12].y;
	D[14].x = D[6].x; //bottom nook
	D[14].y = D[1].y;
	D[15].x = D[2].x;
	D[15].y = D[0].y;
	gvrender_polygon(job, D, sides + 12, filled);

	//2-part dash line

	/*line below the x, bottom dash*/
	C[0].x = D[14].x; //x_center
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	C[1].x = C[0].x;
	C[1].y = C[0].y + (B[3].y-B[4].y)/8; //y_center + 1/4*width
	gvrender_polyline(job, C, 2);

	/*line below the x, top dash*/
	C[0].x = D[14].x; //x_center
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/4;
	C[1].x = C[0].x;
	C[1].y = C[0].y + (B[3].y-B[4].y)/8;
	gvrender_polyline(job, C, 2);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;
    case (19 << 24):
	/*
	 * hexagon with a dashed line on the bottom
	 * 
	 *
	 *           O
	 *	     |
	 *	------------          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;

	D = (pointf*)zmalloc((sides + 4)*sizeof(pointf)); //12-sided x
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/8; //x_center+widtht/8 , lower right corner of the hexagon
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/2; //y_center + width
	D[1].x = D[0].x + (B[2].x-B[3].x)/8;
	D[1].y = D[0].y + (B[3].y-B[4].y)/8; //D[0].y +width/4
	D[2].x = D[1].x; //D[0].x- width/4
	D[2].y = D[1].y + (B[3].y-B[4].y)/4; //D[1].y+width/2
	D[3].x = D[0].x;
	D[3].y = D[2].y + (B[3].y-B[4].y)/8; //D[2].y + width/4
	D[4].x = D[3].x - (B[2].x-B[3].x)/4;
	D[4].y = D[3].y; //top of the hexagon
	D[5].x = D[4].x - (B[2].x-B[3].x)/8;
	D[5].y = D[2].y;
	D[6].x = D[5].x;
	D[6].y = D[1].y; //left side
	D[7].x = D[4].x;
	D[7].y = D[0].y; //bottom
	gvrender_polygon(job, D, sides + 4, filled);

	//2-part dash line

	/*line below the x, bottom dash*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2; //x_center
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	C[1].x = C[0].x;
	C[1].y = C[0].y + (B[3].y-B[4].y)/8; //y_center + 1/4*width
	gvrender_polyline(job, C, 2);

	/*line below the x, top dash*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2; //x_center
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/4;
	C[1].x = C[0].x;
	C[1].y = C[0].y + (B[3].y-B[4].y)/8;
	gvrender_polyline(job, C, 2);



	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;
    case (20 << 24):
	/*
	 * X with a solid line on the bottom
	 * 
	 *
	 *           X
	 *	     |
	 *	------------          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;
	D = (pointf*)zmalloc((sides + 12)*sizeof(pointf)); //12-sided x
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/4; //x_center+widtht/2 , lower right corner of the x
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/2; //y_center + width
	D[1].x = D[0].x;
	D[1].y = D[0].y + (B[3].y-B[4].y)/8; //D[0].y +width/4
	D[2].x = D[0].x - (B[2].x-B[3].x)/8; //D[0].x- width/4 //right nook of the x
	D[2].y = D[1].y + (B[3].y-B[4].y)/8; //D[0].y+width/2 or D[1].y+width/4
	D[3].x = D[0].x;
	D[3].y = D[2].y + (B[3].y-B[4].y)/8; //D[2].y + width/4
	D[4].x = D[0].x;
	D[4].y = D[3].y + (B[3].y-B[4].y)/8; //top right corner of the x
	D[5].x = D[2].x;
	D[5].y = D[4].y;
	D[6].x = AF[1].x + (AF[0].x - AF[1].x)/2; //x_center
	D[6].y = D[3].y; //top nook
	D[7].x = D[6].x - (B[2].x-B[3].x)/8; //D[5] mirrowed across y
	D[7].y = D[5].y;
	D[8].x = D[7].x - (B[2].x-B[3].x)/8;//top left corner
	D[8].y = D[7].y;
	D[9].x = D[8].x;
	D[9].y = D[3].y;
	D[10].x = D[8].x + (B[2].x-B[3].x)/8;
	D[10].y = D[2].y;
	D[11].x = D[8].x;
	D[11].y = D[1].y;
	D[12].x = D[8].x;
	D[12].y = D[0].y;
	D[13].x = D[10].x;
	D[13].y = D[12].y;
	D[14].x = D[6].x; //bottom nook
	D[14].y = D[1].y;
	D[15].x = D[2].x;
	D[15].y = D[0].y;
	gvrender_polygon(job, D, sides + 12, filled);


	/*line below the x*/
	C[0] = D[14];
	C[1].x = C[0].x;
	C[1].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	gvrender_polyline(job, C, 2);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;
    case (21 << 24):
	/*
	 * hexagon with a dashed line on the bottom
	 * 
	 *
	 *           O
	 *	     |
	 *	------------          
	 */
	//x_center is AF[1].x + (AF[0].x - AF[1].x)/2
	//y_center is AF[2].y + (AF[1].y - AF[2].y)/2;
	//width units are (B[2].x-B[3].x)/2 or (B[3].y-B[4].y)/2;

	D = (pointf*)zmalloc((sides + 4)*sizeof(pointf)); //12-sided x
	D[0].x = AF[1].x + (AF[0].x-AF[1].x)/2 + (B[2].x-B[3].x)/8; //x_center+widtht/8 , lower right corner of the hexagon
	D[0].y = AF[2].y + (AF[1].y - AF[2].y)/2 + (B[3].y-B[4].y)/2; //y_center + width
	D[1].x = D[0].x + (B[2].x-B[3].x)/8;
	D[1].y = D[0].y + (B[3].y-B[4].y)/8; //D[0].y +width/4
	D[2].x = D[1].x; //D[0].x- width/4
	D[2].y = D[1].y + (B[3].y-B[4].y)/4; //D[1].y+width/2
	D[3].x = D[0].x;
	D[3].y = D[2].y + (B[3].y-B[4].y)/8; //D[2].y + width/4
	D[4].x = D[3].x - (B[2].x-B[3].x)/4;
	D[4].y = D[3].y; //top of the hexagon
	D[5].x = D[4].x - (B[2].x-B[3].x)/8;
	D[5].y = D[2].y;
	D[6].x = D[5].x;
	D[6].y = D[1].y; //left side
	D[7].x = D[4].x;
	D[7].y = D[0].y; //bottom
	gvrender_polygon(job, D, sides + 4, filled);

	/*line below the x*/
	C[0].x = AF[1].x + (AF[0].x - AF[1].x)/2;
	C[0].y = D[0].y;
	C[1].x = C[0].x;
	C[1].y = AF[2].y + (AF[1].y - AF[2].y)/2; //y_center
	gvrender_polyline(job, C, 2);

	/*dsDNA line*/
	C[0].x = AF[1].x;
	C[0].y = AF[2].y + (AF[1].y - AF[2].y)/2;
	C[1].x = AF[0].x;
	C[1].y = AF[2].y + (AF[0].y - AF[3].y)/2;
	gvrender_polyline(job, C, 2);				
	free(D);

	break;        

    case (22 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  
	 *      D[1] = AF[1]      |	 *       +----------------+ 	 *       |	        D[0] 	 *       |                    	 *       |                    /    




	 *       |                   /
	 *       |        +-------+ /
	 *       |	  |       |/
	 *	 +--------+
	 */
	/* Add the tab edges. */
	D = (pointf*)zmalloc((sides + 5)*sizeof(pointf)); /*5 new points*/
	D[0].x = B[1].x - (B[2].x - B[3].x)/2;
	D[0].y = B[1].y - (B[3].y - B[4].y)/2;
	D[1].x = B[3].x;
	D[1].y = B[3].y - (B[3].y - B[4].y)/2;
	D[2].x = AF[2].x;
	D[2].y = AF[2].y;
	D[3].x = B[2].x + (B[2].x - B[3].x)/2;
	D[3].y = AF[2].y;
	D[4].x = B[2].x + (B[2].x - B[3].x)/2;
	D[4].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[5].x = B[1].x - (B[2].x - B[3].x)/2;
	D[5].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[6].x = B[1].x - (B[2].x - B[3].x)/2;
	D[6].y = AF[3].y;
	D[7].y = AF[0].y - (AF[0].y - AF[3].y)/2; /*triangle point */
	D[7].x = AF[0].x; /*triangle point */
	D[8].y = AF[0].y;
	D[8].x = B[1].x - (B[2].x - B[3].x)/2;

	gvrender_polygon(job, D, sides + 5, filled);
	free(D);
	break;
				
    case (23 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  
	 *      D[1] = AF[1]      |	 *       +----------------+ 	 *       |		D[0] 	 *       |                    	 *       |                    /    




	 *       |                   /
	 *       +----------------+ /
	 *	  	          |/
	 *	 
	 */
	/* Add the tab edges. */
	D = (pointf*)zmalloc((sides + 3)*sizeof(pointf)); /*3 new points*/
	D[0].x = B[1].x - (B[2].x - B[3].x)/2;
	D[0].y = B[1].y - (B[3].y - B[4].y)/2;
	D[1].x = B[3].x;
	D[1].y = B[3].y - (B[3].y - B[4].y)/2;
	D[2].x = AF[2].x;
	D[2].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[3].x = B[1].x - (B[2].x - B[3].x)/2;
	D[3].y = AF[2].y + (B[3].y - B[4].y)/2;
	D[4].x = B[1].x - (B[2].x - B[3].x)/2;
	D[4].y = AF[3].y;
	D[5].y = AF[0].y - (AF[0].y - AF[3].y)/2;/*triangle point*/
	D[5].x = AF[0].x; /*triangle point */
	D[6].y = AF[0].y;
	D[6].x = B[1].x - (B[2].x - B[3].x)/2;

	gvrender_polygon(job, D, sides + 3, filled);
	free(D);
	break;

    case (24 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  
	 *      /|     
	 *     / +----------------+ 
	 *    /                   |        
	 *    \                   |   
	 *     \ +----------------+ 
	 *	\| 	          
	 *	 
	 */
	/* Add the tab edges. */
	D = (pointf*)zmalloc((sides + 3)*sizeof(pointf)); /*3 new points*/
	D[0].x = AF[0].x;
	D[0].y = AF[0].y - (B[3].y-B[4].y)/2;
	D[1].x = B[2].x + (B[2].x - B[3].x)/2;
	D[1].y = AF[0].y - (B[3].y-B[4].y)/2;/*D[0].y*/
	D[2].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[2].y = B[2].y;
	D[3].x = AF[1].x; /*triangle point*/
	D[3].y = AF[1].y - (AF[1].y - AF[2].y)/2; /*triangle point*/
	D[4].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[4].y = AF[2].y;
	D[5].y = AF[2].y + (B[3].y-B[4].y)/2;
	D[5].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[6].y = AF[3].y + (B[3].y - B[4].y)/2;
	D[6].x = AF[0].x;/*D[0]*/

	gvrender_polygon(job, D, sides + 3, filled);
	free(D);
	break;

    case (25 << 24):
	/*
	 * Adjust the perimeter for the protrusions.
	 *
	 *  
	 *      /|     
	 *     / +----------------+ 
	 *    /   		D[0] 
	 *   /                    |    
	 *   \                    |        
	 *    \                   |   
	 *     \ +--------+       + 
	 *	\| 	  |       |
	 *	          +-------+
	 */
	/* Add the tab edges. */
	D = (pointf*)zmalloc((sides + 5)*sizeof(pointf)); /*3 new points*/
	D[0].x = AF[0].x;
	D[0].y = AF[0].y - (B[3].y-B[4].y)/2;
	D[1].x = B[2].x + (B[2].x - B[3].x)/2;
	D[1].y = AF[0].y - (B[3].y-B[4].y)/2;/*D[0].y*/
	D[2].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[2].y = B[2].y;
	D[3].x = AF[1].x; /*triangle point*/
	D[3].y = AF[1].y - (AF[1].y - AF[2].y)/2; /*triangle point*/
	D[4].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[4].y = AF[2].y;
	D[5].y = AF[2].y + (B[3].y-B[4].y)/2;
	D[5].x = B[2].x + (B[2].x - B[3].x)/2;/*D[1].x*/
	D[6].y = AF[3].y + (B[3].y - B[4].y)/2;
	D[6].x = B[1].x - (B[2].x - B[3].x)/2;
	D[7].x = B[1].x - (B[2].x - B[3].x)/2;/*D[6].x*/
	D[7].y = AF[3].y;
	D[8].x = AF[3].x;
	D[8].y = AF[3].y;
				
	gvrender_polygon(job, D, sides + 5, filled);
	free(D);
	break;
    }
    free(B);
}

/*=============================poly start=========================*/

/* userSize;
 * Return maximum size, in points, of width and height supplied
 * by user, if any. Return 0 otherwise.
 */
static double userSize(node_t * n)
{
    double w, h;
    w = late_double(n, N_width, 0.0, 0.01);
    h = late_double(n, N_height, 0.0, 0.02);
    return ((((((w)>(h)?(w):(h)))*72>=0)?(int)((((w)>(h)?(w):(h)))*72 + .5):(int)((((w)>(h)?(w):(h)))*72 - .5)));
}

shape_kind shapeOf(node_t * n)
{
    shape_desc *sh = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape);
    void (*ifn) (node_t *);

    if (!sh)
	return SH_UNSET;
    ifn = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->initfn;
    if (ifn == poly_init)
	return SH_POLY;
    else if (ifn == record_init)
	return SH_RECORD;
    else if (ifn == point_init)
	return SH_POINT;
    else if (ifn == epsf_init)
	return SH_EPSF;
    else
	return SH_UNSET;
}

boolean isPolygon(node_t * n)
{
    return ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->initfn == poly_init));
}

static void poly_init(node_t * n)
{
    pointf dimen, min_bb, bb;
    point imagesize;
    pointf P, Q, R;
    pointf *vertices;
    char *p, *sfile, *fxd;
    double temp, alpha, beta, gamma;
    double orientation, distortion, skew;
    double sectorangle, sidelength, skewdist, gdistortion, gskew;
    double angle, sinx, cosx, xmax, ymax, scalex, scaley;
    double width, height, marginx, marginy, spacex;
    int regular, peripheries, sides;
    int i, j, isBox, outp;
    polygon_t *poly = (polygon_t*)zmalloc(sizeof(polygon_t));

    regular = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->regular;
    peripheries = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->peripheries;
    sides = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->sides;
    orientation = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->orientation;
    skew = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->skew;
    distortion = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->distortion;
    regular |= mapbool(agget(n, "regular"));

    /* all calculations in floating point POINTS */

    /* make x and y dimensions equal if node is regular
     *   If the user has specified either width or height, use the max.
     *   Else use minimum default value.
     * If node is not regular, use the current width and height.
     */
    if (regular) {
	double sz = userSize(n);
	if (sz > 0.0)
	    width = height = sz;
	else {
	    width = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width);
	    height = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height);
	    width = height = ((((((width)<(height)?(width):(height)))*72>=0)?(int)((((width)<(height)?(width):(height)))*72 + .5):(int)((((width)<(height)?(width):(height)))*72 - .5)));
	}
    } else {
	width = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 - .5)));
	height = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 - .5)));
    }

    peripheries = late_int(n, N_peripheries, peripheries, 0);
    orientation += late_double(n, N_orientation, 0.0, -360.0);
    if (sides == 0) {		/* not for builtins */
	skew = late_double(n, N_skew, 0.0, -100.0);
	sides = late_int(n, N_sides, 4, 0);
	distortion = late_double(n, N_distortion, 0.0, -100.0);
    }

    /* get label dimensions */
    dimen = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->dimen;

    /* minimal whitespace around label */
    if (((abs(dimen.x)>=0)?(int)(abs(dimen.x) + .5):(int)(abs(dimen.x) - .5)) || ((abs(dimen.y)>=0)?(int)(abs(dimen.y) + .5):(int)(abs(dimen.y) - .5))) {
	/* padding */
	if ((p = agget(n, "margin"))) {
	    marginx = marginy = 0;
	    i = sscanf(p, "%lf,%lf", &marginx, &marginy);
	    if (marginx < 0)
		marginx = 0;
	    if (marginy < 0)
		marginy = 0;
	    if (i > 0) {
		dimen.x += 2 * ((((marginx)*72>=0)?(int)((marginx)*72 + .5):(int)((marginx)*72 - .5)));
		if (i > 1)
		    dimen.y += 2 * ((((marginy)*72>=0)?(int)((marginy)*72 + .5):(int)((marginy)*72 - .5)));
		else
		    dimen.y += 2 * ((((marginx)*72>=0)?(int)((marginx)*72 + .5):(int)((marginx)*72 - .5)));
	    } else
		{((dimen).x += 4*4); ((dimen).y += 2*4);};
	} else
	    {((dimen).x += 4*4); ((dimen).y += 2*4);};
    }
    spacex = dimen.x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->dimen.x;

    /* quantization */
    if ((temp = (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->drawing)->quantum) > 0.0) {
	temp = ((((temp)*72>=0)?(int)((temp)*72 + .5):(int)((temp)*72 - .5)));
	dimen.x = quant(dimen.x, temp);
	dimen.y = quant(dimen.y, temp);
    }

    imagesize.x = imagesize.y = 0;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->usershape) {
	/* custom requires a shapefile
	 * not custom is an adaptable user shape such as a postscript
	 * function.
	 */
	if ((*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name)==*("custom")&&!strcmp((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name,"custom"))) {
	    sfile = agget(n, "shapefile");
	    imagesize = gvusershape_size(agraphof(n), sfile);
	    if ((imagesize.x == -1) && (imagesize.y == -1)) {
		agerr(AGWARN,
		      "No or improper shapefile=\"%s\" for node \"%s\"\n",
		      (sfile ? sfile : "<nil>"), agnameof(n));
		imagesize.x = imagesize.y = 0;
	    } else {
		(((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->has_images) = (!(0));
		imagesize.x += 2;	/* some fixed padding */
		imagesize.y += 2;
	    }
	}
    } else if ((sfile = agget(n, "image")) && (*sfile != '\0')) {
	imagesize = gvusershape_size(agraphof(n), sfile);
	if ((imagesize.x == -1) && (imagesize.y == -1)) {
	    agerr(AGWARN,
		  "No or improper image=\"%s\" for node \"%s\"\n",
		  (sfile ? sfile : "<nil>"), agnameof(n));
	    imagesize.x = imagesize.y = 0;
	} else {
	    (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->has_images) = (!(0));
	    imagesize.x += 2;	/* some fixed padding */
	    imagesize.y += 2;
	}
    }

    /* initialize node bb to labelsize */
    bb.x = ((dimen.x)>(imagesize.x)?(dimen.x):(imagesize.x));
    bb.y = ((dimen.y)>(imagesize.y)?(dimen.y):(imagesize.y));

    /* I don't know how to distort or skew ellipses in postscript */
    /* Convert request to a polygon with a large number of sides */
    if ((sides <= 2) && ((distortion != 0.) || (skew != 0.))) {
	sides = 120;
    }

    /* extra sizing depends on if label is centered vertically */
    p = agget(n, "labelloc");
    if (p && (p[0] == 't' || p[0] == 'b'))
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->valign = p[0];
    else
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->valign = 'c';

    isBox = (sides == 4 && (((orientation>=0)?(int)(orientation + .5):(int)(orientation - .5)) % 90) == 0
	     && distortion == 0. && skew == 0.);
    if (isBox) {
	/* for regular boxes the fit should be exact */
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->vertices) {
	poly_desc_t* pd = (poly_desc_t*)(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->vertices;
	bb = pd->size_gen(bb);
    } else {
	/* for all other shapes, compute a smallest ellipse
	 * containing bb centered on the origin, and then pad for that.
	 * We assume the ellipse is defined by a scaling up of bb.
	 */
	temp = bb.y * 1.41421356237309504880;
	if (height > temp && (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->valign == 'c') {
	    /* if there is height to spare
	     * and the label is centered vertically
	     * then just pad x in proportion to the spare height */
	    bb.x *= sqrt(1. / (1. - ((bb.y / height) * (bb.y / height))));
	} else {
	    bb.x *= 1.41421356237309504880;
	    bb.y = temp;
	}

	if (sides > 2) {
	    temp = cos(3.14159265358979323846 / sides);
	    bb.x /= temp;
	    bb.y /= temp;
	    /* FIXME - for odd-sided polygons, e.g. triangles, there
	       would be a better fit with some vertical adjustment of the shape */
	}

    }

    /* at this point, bb is the minimum size of node that can hold the label */
    min_bb = bb;

    /* increase node size to width/height if needed */
    fxd = late_string(n, N_fixed, "false");
    if ((*fxd == 's') && (*(fxd)==*("shape")&&!strcmp(fxd,"shape"))) {
	bb.x = width;
	bb.y = height;
	poly->option |= (1 << 11);
    } else if (mapbool(fxd)) {
	/* check only label, as images we can scale to fit */
	if ((width < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->dimen.x) || (height < (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->dimen.y))
	    agerr(AGWARN,
		  "node '%s', graph '%s' size too small for label\n",
		  agnameof(n), agnameof(agraphof(n)));
	bb.x = width;
	bb.y = height;
    } else {
	bb.x = width = ((width)>(bb.x)?(width):(bb.x));
	bb.y = height = ((height)>(bb.y)?(height):(bb.y));
    }

    /* If regular, make dimensions the same.
     * Need this to guarantee final node size is regular.
     */
    if (regular) {
	width = height = bb.x = bb.y = ((bb.x)>(bb.y)?(bb.x):(bb.y));
    }

    /* Compute space available for label.  Provides the justification borders */
    if (!mapbool(late_string(n, N_nojustify, "false"))) {
	if (isBox) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->space.x = ((dimen.x)>(bb.x)?(dimen.x):(bb.x)) - spacex;
	}
	else if (dimen.y < bb.y) {
	    temp = bb.x * sqrt(1.0 - ((dimen.y) * (dimen.y)) / ((bb.y) * (bb.y)));
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->space.x = ((dimen.x)>(temp)?(dimen.x):(temp)) - spacex;
        }
	else
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->space.x = dimen.x - spacex;
    } else {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->space.x = dimen.x - spacex;
    }

    if ((poly->option & (1 << 11)) == 0) {
	temp = bb.y - min_bb.y;
	if (dimen.y < imagesize.y)
	    temp += imagesize.y - dimen.y;
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->space.y = dimen.y + temp;
    }

    outp = peripheries;
    if (peripheries < 1)
	outp = 1;
    if (sides < 3) {		/* ellipses */
	sides = 2;
	vertices = (pointf*)zmalloc((outp * sides)*sizeof(pointf));
	P.x = bb.x / 2.;
	P.y = bb.y / 2.;
	vertices[0].x = -P.x;
	vertices[0].y = -P.y;
	vertices[1] = P;
	if (peripheries > 1) {
	    for (j = 1, i = 2; j < peripheries; j++) {
		P.x += 4;
		P.y += 4;
		vertices[i].x = -P.x;
		vertices[i].y = -P.y;
		i++;
		vertices[i].x = P.x;
		vertices[i].y = P.y;
		i++;
	    }
	    bb.x = 2. * P.x;
	    bb.y = 2. * P.y;
	}
    } else {

/*
 * FIXME - this code is wrong - it doesn't work for concave boundaries.
 *          (e.g. "folder"  or "promoter")
 *   I don't think it even needs sectorangle, or knowledge of skewed shapes.
 *   (Concepts that only work for convex regular (modulo skew/distort) polygons.)
 *
 *   I think it only needs to know inside v. outside (by always drawing
 *   boundaries clockwise, say),  and the two adjacent segments.
 *
 *   It needs to find the point where the two lines, parallel to
 *   the current segments, and outside by GAP distance, intersect.   
 */

	vertices = (pointf*)zmalloc((outp * sides)*sizeof(pointf));
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->vertices) {
	    poly_desc_t* pd = (poly_desc_t*)(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->vertices;
	    pd->vertex_gen (vertices, &bb);
	    xmax = bb.x/2;
	    ymax = bb.y/2;
	} else {
	    sectorangle = 2. * 3.14159265358979323846 / sides;
	    sidelength = sin(sectorangle / 2.);
	    skewdist = hypot(fabs(distortion) + fabs(skew), 1.);
	    gdistortion = distortion * 1.41421356237309504880 / cos(sectorangle / 2.);
	    gskew = skew / 2.;
	    angle = (sectorangle - 3.14159265358979323846) / 2.;
	    *&sinx = sin(angle); *&cosx = cos(angle);
	    R.x = .5 * cosx;
	    R.y = .5 * sinx;
	    xmax = ymax = 0.;
	    angle += (3.14159265358979323846 - sectorangle) / 2.;
	    for (i = 0; i < sides; i++) {

	    /*next regular vertex */
		angle += sectorangle;
		*&sinx = sin(angle); *&cosx = cos(angle);
		R.x += sidelength * cosx;
		R.y += sidelength * sinx;

	    /*distort and skew */
		P.x = R.x * (skewdist + R.y * gdistortion) + R.y * gskew;
		P.y = R.y;

	    /*orient P.x,P.y */
		alpha = ((orientation)/180.0 * 3.14159265358979323846) + atan2(P.y, P.x);
		*&sinx = sin(alpha); *&cosx = cos(alpha);
		P.x = P.y = hypot(P.x, P.y);
		P.x *= cosx;
		P.y *= sinx;

	    /*scale for label */
		P.x *= bb.x;
		P.y *= bb.y;

	    /*find max for bounding box */
		xmax = ((fabs(P.x))>(xmax)?(fabs(P.x)):(xmax));
		ymax = ((fabs(P.y))>(ymax)?(fabs(P.y)):(ymax));

	    /* store result in array of points */
		vertices[i] = P;
		if (isBox) { /* enforce exact symmetry of box */
		    vertices[1].x = -P.x;
		    vertices[1].y = P.y;
		    vertices[2].x = -P.x;
		    vertices[2].y = -P.y;
		    vertices[3].x = P.x;
		    vertices[3].y = -P.y;
		    break;
		}
	    }
	}

	/* apply minimum dimensions */
	xmax *= 2.;
	ymax *= 2.;
	bb.x = ((width)>(xmax)?(width):(xmax));
	bb.y = ((height)>(ymax)?(height):(ymax));
	scalex = bb.x / xmax;
	scaley = bb.y / ymax;

	for (i = 0; i < sides; i++) {
	    P = vertices[i];
	    P.x *= scalex;
	    P.y *= scaley;
	    vertices[i] = P;
	}

	if (peripheries > 1) {
	    Q = vertices[(sides - 1)];
	    R = vertices[0];
	    beta = atan2(R.y - Q.y, R.x - Q.x);
	    for (i = 0; i < sides; i++) {

		/*for each vertex find the bisector */
		P = Q;
		Q = R;
		R = vertices[(i + 1) % sides];
		alpha = beta;
		beta = atan2(R.y - Q.y, R.x - Q.x);
		gamma = (alpha + 3.14159265358979323846 - beta) / 2.;

		/*find distance along bisector to */
		/*intersection of next periphery */
		temp = 4 / sin(gamma);

		/*convert this distance to x and y */
		*&sinx = sin((alpha - gamma)); *&cosx = cos((alpha - gamma));
		sinx *= temp;
		cosx *= temp;

		/*save the vertices of all the */
		/*peripheries at this base vertex */
		for (j = 1; j < peripheries; j++) {
		    Q.x += cosx;
		    Q.y += sinx;
		    vertices[i + j * sides] = Q;
		}
	    }
	    for (i = 0; i < sides; i++) {
		P = vertices[i + (peripheries - 1) * sides];
		bb.x = ((2. * fabs(P.x))>(bb.x)?(2. * fabs(P.x)):(bb.x));
		bb.y = ((2. * fabs(P.y))>(bb.y)?(2. * fabs(P.y)):(bb.y));
	    }
	}
    }
    poly->regular = regular;
    poly->peripheries = peripheries;
    poly->sides = sides;
    poly->orientation = orientation;
    poly->skew = skew;
    poly->distortion = distortion;
    poly->vertices = vertices;

    if (poly->option & (1 << 11)) {
	/* set width and height to reflect label and shape */
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = ((((dimen.x)>(bb.x)?(dimen.x):(bb.x)))/(double)72);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = ((((dimen.y)>(bb.y)?(dimen.y):(bb.y)))/(double)72);
    } else {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = ((bb.x)/(double)72);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = ((bb.y)/(double)72);
    }
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info) = (void *) poly;
}

static void poly_free(node_t * n)
{
    polygon_t *p = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);

    if (p) {
	free(p->vertices);
	free(p);
    }
}



/* poly_inside:
 * Return true if point p is inside polygonal shape of node inside_context->s.n.
 * Calculations are done using unrotated node shape. Thus, if p is in a rotated
 * coordinate system, it is reset as P in the unrotated coordinate system. Similarly,
 * the ND_rw, ND_lw and ND_ht values are rotated if the graph is flipped.
 */
static boolean poly_inside(inside_t * inside_context, pointf p)
{
    static node_t *lastn;	/* last node argument */
    static polygon_t *poly;
    static int last, outp, sides;
    static pointf O;		/* point (0,0) */
    static pointf *vertex;
    static double xsize, ysize, scalex, scaley, box_URx, box_URy;

    int i, i1, j, s;
    pointf P, Q, R;
    boxf *bp = inside_context->s.bp;
    node_t *n = inside_context->s.n;

    P = ccwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));

    /* Quick test if port rectangle is target */
    if (bp) {
	boxf bbox = *bp;
	return (((((bbox).LL.x) <= ((P).x)) && (((P).x) <= ((bbox).UR.x))) && ((((bbox).LL.y) <= ((P).y)) && (((P).y) <= ((bbox).UR.y))));
    }

    if (n != lastn) {
	double n_width, n_height;
	poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
	vertex = poly->vertices;
	sides = poly->sides;

	if (poly->option & (1 << 11)) {
	   boxf bb = polyBB(poly); 
	    n_width = bb.UR.x - bb.LL.x;
	    n_height = bb.UR.y - bb.LL.y;
	    /* get point and node size adjusted for rankdir=LR */
	    if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
		ysize = n_width;
		xsize = n_height;
	    } else {
		xsize = n_width;
		ysize = n_height;
	    }
	} else {
	    /* get point and node size adjusted for rankdir=LR */
	    if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
		ysize = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
		xsize = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht);
	    } else {
		xsize = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
		ysize = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht);
	    }
	    n_width = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 - .5)));
	    n_height = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 - .5)));
	}

	/* scale */
	if (xsize == 0.0)
	    xsize = 1.0;
	if (ysize == 0.0)
	    ysize = 1.0;
	scalex = n_width / xsize;
	scaley = n_height / ysize;
	box_URx = n_width / 2.0;
	box_URy = n_height / 2.0;

	/* index to outer-periphery */
	outp = (poly->peripheries - 1) * sides;
	if (outp < 0)
	    outp = 0;
	lastn = n;
    }

    /* scale */
    P.x *= scalex;
    P.y *= scaley;

    /* inside bounding box? */
    if ((fabs(P.x) > box_URx) || (fabs(P.y) > box_URy))
	return 0;

    /* ellipses */
    if (sides <= 2)
	return (hypot(P.x / box_URx, P.y / box_URy) < 1.);

    /* use fast test in case we are converging on a segment */
    i = last % sides;		/* in case last left over from larger polygon */
    i1 = (i + 1) % sides;
    Q = vertex[i + outp];
    R = vertex[i1 + outp];
    if (!(same_side(P, O, Q, R)))   /* false if outside the segment's face */
	return 0;
    /* else inside the segment face... */
    if ((s = same_side(P, Q, R, O)) && (same_side(P, R, O, Q))) /* true if between the segment's sides */
	return (!(0));
    /* else maybe in another segment */
    for (j = 1; j < sides; j++) { /* iterate over remaining segments */
	if (s) { /* clockwise */
	    i = i1;
	    i1 = (i + 1) % sides;
	} else { /* counter clockwise */
	    i1 = i;
	    i = (i + sides - 1) % sides;
	}
	if (!(same_side(P, O, vertex[i + outp], vertex[i1 + outp]))) { /* false if outside any other segment's face */
	    last = i;
	    return 0;
	}
    }
    /* inside all segments' faces */
    last = i;			/* in case next edge is to same side */
    return (!(0));
}

/* poly_path:
 * Generate box path from port to border.
 * Store boxes in rv and number of boxes in kptr.
 * side gives preferred side of bounding box for last node.
 * Return actual side. Returning 0 indicates nothing done.
 */
static int poly_path(node_t * n, port * p, int side, boxf rv[], int *kptr)
{
    side = 0;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->html && (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->has_port)) {
	side = html_path(n, p, side, rv, kptr);
    }
    return side;
}

/* invflip_side:
 */
static int invflip_side(int side, int rankdir)
{
    switch (rankdir) {
    case 0:
	break;
    case 2:
	switch (side) {
	case (1<<2):
	    side = (1<<0);
	    break;
	case (1<<0):
	    side = (1<<2);
	    break;
	default:
	    break;
	}
	break;
    case 1:
	switch (side) {
	case (1<<2):
	    side = (1<<1);
	    break;
	case (1<<0):
	    side = (1<<3);
	    break;
	case (1<<3):
	    side = (1<<2);
	    break;
	case (1<<1):
	    side = (1<<0);
	    break;
	}
	break;
    case 3:
	switch (side) {
	case (1<<2):
	    side = (1<<1);
	    break;
	case (1<<0):
	    side = (1<<3);
	    break;
	case (1<<3):
	    side = (1<<0);
	    break;
	case (1<<1):
	    side = (1<<2);
	    break;
	}
	break;
    }
    return side;
}

/* invflip_angle:
 */
static double invflip_angle(double angle, int rankdir)
{
    switch (rankdir) {
    case 0:
	break;
    case 2:
	angle *= -1;
	break;
    case 1:
	angle -= 3.14159265358979323846 * 0.5;
	break;
    case 3:
	if (angle == 3.14159265358979323846)
	    angle = -0.5 * 3.14159265358979323846;
	else if (angle == 3.14159265358979323846 * 0.75)
	    angle = -0.25 * 3.14159265358979323846;
	else if (angle == 3.14159265358979323846 * 0.5)
	    angle = 0;
/* clang complains about self assignment of double
	else if (angle == M_PI * 0.25)
	    angle = angle;
 */
	else if (angle == 0)
	    angle = 3.14159265358979323846 * 0.5;
	else if (angle == 3.14159265358979323846 * -0.25)
	    angle = 3.14159265358979323846 * 0.75;
	else if (angle == 3.14159265358979323846 * -0.5)
	    angle = 3.14159265358979323846;
/* clang complains about self assignment of double
	else if (angle == M_PI * -0.75)
	    angle = angle;
 */
	break;
    }
    return angle;
}

/* compassPoint:
 * Compute compass points for non-trivial shapes.
 * It finds where the ray ((0,0),(x,y)) hits the boundary and
 * returns it.
 * Assumes ictxt and ictxt->n are non-NULL.
 *
 * bezier_clip uses the shape's _inside function, which assumes the input
 * point is in the rotated coordinate system (as determined by rankdir), so
 * it rotates the point counterclockwise based on rankdir to get the node's
 * coordinate system.
 * To handle this, if rankdir is set, we rotate (x,y) clockwise, and then
 * rotate the answer counterclockwise.
 */
static pointf compassPoint(inside_t * ictxt, double y, double x)
{
    pointf curve[4];		/* bezier control points for a straight line */
    node_t *n = ictxt->s.n;
    graph_t* g = agraphof(n);
    int rd = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3);
    pointf p;

    p.x = x;
    p.y = y;
    if (rd)
	p = cwrotatepf(p, 90 * rd);

    curve[0].x = curve[0].y = 0;
    curve[1] = curve[0];
    curve[3] = curve[2] = p;

    bezier_clip(ictxt, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->fns->insidefn, curve, 1);

    if (rd)
	curve[0] = ccwrotatepf(curve[0], 90 * rd);
    return curve[0];
}

/* compassPort:
 * Attach a compass point to a port pp, and fill in remaining fields.
 * n is the corresponding node; bp is the bounding box of the port.
 * compass is the compass point
 * Return 1 if unrecognized compass point, in which case we
 * use the center.
 *
 * This function also finishes initializing the port structure,
 * even if no compass point is involved.
 * The sides value gives the set of sides shared by the port. This
 * is used with a compass point to indicate if the port is exposed, to
 * set the port's side value.
 *
 * If ictxt is NULL, we are working with a simple rectangular shape (node or
 * port of record of HTML label), so compass points are trivial. If ictxt is
 * not NULL, it provides shape information so that the compass point can be
 * calculated based on the shape.
 *
 * The code assumes the node has its unrotated shape to find the points,
 * angles, etc. At the end, the parameters are adjusted to take into account
 * the rankdir attribute. In particular, the first if-else statement flips 
 * the already adjusted ND_ht, ND_lw and ND_rw back to non-flipped values. 
 * 
 */
static int
compassPort(node_t * n, boxf * bp, port * pp, char *compass, int sides,
	    inside_t * ictxt)
{
    boxf b;
    pointf p, ctr;
    int rv = 0;
    double theta = 0.0;
    boolean constrain = 0;
    boolean dyna = 0;
    int side = 0;
    boolean clip = (!(0));
    boolean defined;
    double maxv;  /* sufficiently large value outside of range of node */

    if (bp) {
	b = *bp;
	p = pointfof((b.LL.x + b.UR.x) / 2, (b.LL.y + b.UR.y) / 2);
	defined = (!(0));
    } else {
	p.x = p.y = 0.;
	if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
	    b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2.;
	    b.LL.x = -b.UR.x;
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
	    b.LL.y = -b.UR.y;
	} else {
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2.;
	    b.LL.y = -b.UR.y;
	    b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
	    b.LL.x = -b.UR.x;
	}
	defined = 0;
    }
    maxv = ((b.UR.x)>(b.UR.y)?(b.UR.x):(b.UR.y));
    maxv *= 4.0;
    ctr = p;
    if (compass && *compass) {
	switch (*compass++) {
	case 'e':
	    if (*compass)
		rv = 1;
	    else {
                if (ictxt)
                    p = compassPoint(ictxt, ctr.y, maxv);
                else
		    p.x = b.UR.x;
		theta = 0.0;
		constrain = (!(0));
		defined = (!(0));
		clip = 0;
		side = sides & (1<<1);
	    }
	    break;
	case 's':
	    p.y = b.LL.y;
	    constrain = (!(0));
	    clip = 0;
	    switch (*compass) {
	    case '\0':
		theta = -3.14159265358979323846 * 0.5;
		defined = (!(0));
                if (ictxt)
                    p = compassPoint(ictxt, -maxv, ctr.x);
                else
                    p.x = ctr.x;
		side = sides & (1<<0);
		break;
	    case 'e':
		theta = -3.14159265358979323846 * 0.25;
		defined = (!(0));
		if (ictxt)
		    p = compassPoint(ictxt, -maxv, maxv);
		else
		    p.x = b.UR.x;
		side = sides & ((1<<0) | (1<<1));
		break;
	    case 'w':
		theta = -3.14159265358979323846 * 0.75;
		defined = (!(0));
		if (ictxt)
		    p = compassPoint(ictxt, -maxv, -maxv);
		else
		    p.x = b.LL.x;
		side = sides & ((1<<0) | (1<<3));
		break;
	    default:
		p.y = ctr.y;
		constrain = 0;
		clip = (!(0));
		rv = 1;
		break;
	    }
	    break;
	case 'w':
	    if (*compass)
		rv = 1;
	    else {
                if (ictxt)
                    p = compassPoint(ictxt, ctr.y, -maxv);
                else
		    p.x = b.LL.x;
		theta = 3.14159265358979323846;
		constrain = (!(0));
		defined = (!(0));
		clip = 0;
		side = sides & (1<<3);
	    }
	    break;
	case 'n':
	    p.y = b.UR.y;
	    constrain = (!(0));
	    clip = 0;
	    switch (*compass) {
	    case '\0':
		defined = (!(0));
		theta = 3.14159265358979323846 * 0.5;
                if (ictxt)
                    p = compassPoint(ictxt, maxv, ctr.x);
                else
                    p.x = ctr.x;
		side = sides & (1<<2);
		break;
	    case 'e':
		defined = (!(0));
		theta = 3.14159265358979323846 * 0.25;
		if (ictxt)
		    p = compassPoint(ictxt, maxv, maxv);
		else
		    p.x = b.UR.x;
		side = sides & ((1<<2) | (1<<1));
		break;
	    case 'w':
		defined = (!(0));
		theta = 3.14159265358979323846 * 0.75;
		if (ictxt)
		    p = compassPoint(ictxt, maxv, -maxv);
		else
		    p.x = b.LL.x;
		side = sides & ((1<<2) | (1<<3));
		break;
	    default:
		p.y = ctr.y;
		constrain = 0;
		clip = (!(0));
		rv = 1;
		break;
	    }
	    break;
	case '_':
	    dyna = (!(0));
	    side = sides;
	    break;
	case 'c':
	    break;
	default:
	    rv = 1;
	    break;
	}
    }
    p = cwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));
    if (dyna)
	pp->side = side;
    else
	pp->side = invflip_side(side, (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));
    pp->bp = bp;
    ((pp->p).x = (((p).x>=0)?(int)((p).x + .5):(int)((p).x - .5)),(pp->p).y = (((p).y>=0)?(int)((p).y + .5):(int)((p).y - .5)));
    pp->theta = invflip_angle(theta, (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));
    if ((p.x == 0) && (p.y == 0))
	pp->order = 256 / 2;
    else {
	/* compute angle with 0 at north pole, increasing CCW */
	double angle = atan2(p.y, p.x) + 1.5 * 3.14159265358979323846;
	if (angle >= 2 * 3.14159265358979323846)
	    angle -= 2 * 3.14159265358979323846;
	pp->order = (int) ((256 * angle) / (2 * 3.14159265358979323846));
    }
    pp->constrained = constrain;
    pp->defined = defined;
    pp->clip = clip;
    pp->dyna = dyna;
    return rv;
}

static port poly_port(node_t * n, char *portname, char *compass)
{
    port rv;
    boxf *bp;
    int sides;			/* bitmap of which sides the port lies along */

    if (portname[0] == '\0')
	return Center;

    if (compass == NULL)
	compass = "_";
    sides = (1<<0) | (1<<1) | (1<<2) | (1<<3);
    if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->html) && (bp = html_port(n, portname, &sides))) {
	if (compassPort(n, bp, &rv, compass, sides, NULL)) {
	    agerr(AGWARN,
		  "node %s, port %s, unrecognized compass point '%s' - ignored\n",
		  agnameof(n), portname, compass);
	}
    } else {
	inside_t *ictxtp;
	inside_t ictxt;

	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon == &p_box))
	    ictxtp = NULL;
	else {
	    ictxt.s.n = n;
	    ictxt.s.bp = NULL;
	    ictxtp = &ictxt;
	}
	if (compassPort(n, NULL, &rv, portname, sides, ictxtp))
	    unrecognized(n, portname);
    }

    return rv;
}



/* generic polygon gencode routine */
static void poly_gencode(GVJ_t * job, node_t * n)
{
    obj_state_t *obj = job->obj;
    polygon_t *poly;
    double xsize, ysize;
    int i, j, peripheries, sides, style;
    pointf P, *vertices;
    static pointf *AF;
    static int A_size;
    boolean filled;
    boolean usershape_p;
    boolean pfilled;		/* true if fill not handled by user shape */
    char *color, *name;
    int doMap = (obj->url || obj->explicit_tooltip);
    char* fillcolor=NULL;
    char* pencolor=NULL;
    char* clrs[2];

    if (doMap && !(job->flags & (1<<2)))
	gvrender_begin_anchor(job,
			      obj->url, obj->tooltip, obj->target,
			      obj->id);

    poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
    vertices = poly->vertices;
    sides = poly->sides;
    peripheries = poly->peripheries;
    if (A_size < sides) {
	A_size = sides + 5;
	AF = (AF? (pointf*)grealloc(AF,(A_size)*sizeof(pointf)):(pointf*)gmalloc((A_size)*sizeof(pointf)));
    }

    /* nominal label position in the center of the node */
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->pos = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);

    xsize = ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)) / (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 - .5)));
    ysize = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 - .5)));

    style = stylenode(job, n);
    clrs[0] = NULL;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<0)) {
	pencolor = late_nnstring(n, N_activepencolor, "#808080");
	gvrender_set_pencolor(job, pencolor);
	color =
	    late_nnstring(n, N_activefillcolor, "#fcfcfc");
	gvrender_set_fillcolor(job, color);
	filled = 1;
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<1)) {
	pencolor =
	    late_nnstring(n, N_selectedpencolor, "#303030");
	gvrender_set_pencolor(job, pencolor);
	color =
	    late_nnstring(n, N_selectedfillcolor,
			  "#e8e8e8");
	gvrender_set_fillcolor(job, color);
	filled = 1;
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<3)) {
	pencolor =
	    late_nnstring(n, N_deletedpencolor, "#e0e0e0");
	gvrender_set_pencolor(job, pencolor);
	color =
	    late_nnstring(n, N_deletedfillcolor, "#f0f0f0");
	gvrender_set_fillcolor(job, color);
	filled = 1;
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<2)) {
	pencolor =
	    late_nnstring(n, N_visitedpencolor, "#101010");
	gvrender_set_pencolor(job, pencolor);
	color =
	    late_nnstring(n, N_visitedfillcolor, "#f8f8f8");
	gvrender_set_fillcolor(job, color);
	filled = 1;
    } else {
	if (style & (1 << 0)) {
	    float frac;
	    fillcolor = findFill (n);
	    if (findStopColor (fillcolor, clrs, &frac)) {
        	gvrender_set_fillcolor(job, clrs[0]);
		if (clrs[1]) 
		    gvrender_set_gradient_vals(job,clrs[1],late_int(n,N_gradientangle,0,0), frac);
		else 
		    gvrender_set_gradient_vals(job,"black",late_int(n,N_gradientangle,0,0), frac);
		if (style & (1 << 1))
		    filled = 3;
	 	else
		    filled = 2;
	    }
	    else {
        	gvrender_set_fillcolor(job, fillcolor);
		filled = 1;
	    }
	}
	else if (style & ((1 << 6)|(1 << 9)))  {
	    fillcolor = findFill (n);
            /* gvrender_set_fillcolor(job, fillcolor); */
	    filled = (!(0));
	}
	else {
	    filled = 0;
	}
	pencolor = penColor(job, n);	/* emit pen color */
    }

    pfilled = !(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->usershape || (*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name)==*("custom")&&!strcmp((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name,"custom"));

    /* if no boundary but filled, set boundary color to transparent */
    if ((peripheries == 0) && filled && pfilled) {
	peripheries = 1;
	gvrender_set_pencolor(job, "transparent");
    }

    /* draw peripheries first */
    for (j = 0; j < peripheries; j++) {
	for (i = 0; i < sides; i++) {
	    P = vertices[i + j * sides];
	    AF[i].x = P.x * xsize + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	    AF[i].y = P.y * ysize + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
	}
	if (sides <= 2) {
	    if ((style & (1 << 9)) && (j == 0) && (strchr(fillcolor,':'))) {
		int rv = wedgedEllipse (job, AF, fillcolor);
		if (rv > 1)
		    agerr (AGPREV, "in node %s\n", agnameof(n));
		filled = 0;
	    }
	    gvrender_ellipse(job, AF, sides, filled);
	    if (style & (1 << 3)) {
		Mcircle_hack(job, n);
	    }
	} else if (style & (1 << 6)) {
	    if (j == 0) {
		int rv = stripedBox (job, AF, fillcolor, 1);
		if (rv > 1)
		    agerr (AGPREV, "in node %s\n", agnameof(n));
	    }
	    gvrender_polygon(job, AF, sides, 0);
	} else if (style & (1 << 10)) {
	    gvrender_set_pencolor(job, "transparent");
	    gvrender_polygon(job, AF, sides, filled);
	    gvrender_set_pencolor(job, pencolor);
	    gvrender_polyline(job, AF+2, 2);
	} else if (((style) & ((1 << 2) | (1 << 3) | (127 << 24)))) {
	    round_corners(job, AF, sides, style, filled);
	} else {
	    gvrender_polygon(job, AF, sides, filled);
	}
	/* fill innermost periphery only */
	filled = 0;
    }

    usershape_p = 0;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->usershape) {
	name = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name;
	if ((*(name)==*("custom")&&!strcmp(name,"custom"))) {
	    if ((name = agget(n, "shapefile")) && name[0])
		usershape_p = (!(0));
	} else
	    usershape_p = (!(0));
    } else if ((name = agget(n, "image")) && name[0]) {
	usershape_p = (!(0));
    }
    if (usershape_p) {
	/* get coords of innermost periphery */
	for (i = 0; i < sides; i++) {
	    P = vertices[i];
	    AF[i].x = P.x * xsize + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	    AF[i].y = P.y * ysize + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
	}
	/* lay down fill first */
	if (filled && pfilled) {
	    if (sides <= 2) {
		if ((style & (1 << 9)) && (j == 0) && (strchr(fillcolor,':'))) {
		    int rv = wedgedEllipse (job, AF, fillcolor);
		    if (rv > 1)
			agerr (AGPREV, "in node %s\n", agnameof(n));
		    filled = 0;
		}
		gvrender_ellipse(job, AF, sides, filled);
		if (style & (1 << 3)) {
		    Mcircle_hack(job, n);
		}
	    } else if (style & (1 << 6)) {
		int rv = stripedBox (job, AF, fillcolor, 1);
		if (rv > 1)
		    agerr (AGPREV, "in node %s\n", agnameof(n));
		gvrender_polygon(job, AF, sides, 0);
	    } else if (style & ((1 << 2) | (1 << 3))) {
		round_corners(job, AF, sides, style, filled);
	    } else {
		gvrender_polygon(job, AF, sides, filled);
	    }
	}
	gvrender_usershape(job, name, AF, sides, filled,
			   late_string(n, N_imagescale, "false"));
	filled = 0;		/* with user shapes, we have done the fill if needed */
    }

    free (clrs[0]);

    emit_label(job, EMIT_NLABEL, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label));
    if (doMap) {
	if (job->flags & (1<<2))
	    gvrender_begin_anchor(job,
				  obj->url, obj->tooltip, obj->target,
				  obj->id);
	gvrender_end_anchor(job);
    }
}

/*=======================end poly======================================*/

/*===============================point start========================*/

/* point_init:
 * shorthand for shape=circle, style=filled, width=0.05, label=""
 */
static void point_init(node_t * n)
{
    polygon_t *poly = (polygon_t*)zmalloc(sizeof(polygon_t));
    int sides, outp, peripheries = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->polygon->peripheries;
    double sz;
    pointf P, *vertices;
    int i, j;
    double w, h;

    /* set width and height, and make them equal
     * if user has set weight or height, use it.
     * if both are set, use smallest.
     * if neither, use default
     */
    w = late_double(n, N_width, 1.7976931348623157e+308, 0.0);
    h = late_double(n, N_height, 1.7976931348623157e+308, 0.0);
    w = ((w)<(h)?(w):(h));
    if ((w == 1.7976931348623157e+308) && (h == 1.7976931348623157e+308))	/* neither defined */
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = 0.05;
    else {
	w = ((w)<(h)?(w):(h));
	/* If w == 0, use it; otherwise, make w no less than MIN_POINT due
         * to the restrictions mentioned above.
         */
	if (w > 0.0) 
	    w = ((w)>(0.0003)?(w):(0.0003));
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = w;
    }

    sz = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) * 72;
    peripheries = late_int(n, N_peripheries, peripheries, 0);
    if (peripheries < 1)
	outp = 1;
    else
	outp = peripheries;
    sides = 2;
    vertices = (pointf*)zmalloc((outp * sides)*sizeof(pointf));
    P.y = P.x = sz / 2.;
    vertices[0].x = -P.x;
    vertices[0].y = -P.y;
    vertices[1] = P;
    if (peripheries > 1) {
	for (j = 1, i = 2; j < peripheries; j++) {
	    P.x += 4;
	    P.y += 4;
	    vertices[i].x = -P.x;
	    vertices[i].y = -P.y;
	    i++;
	    vertices[i].x = P.x;
	    vertices[i].y = P.y;
	    i++;
	}
	sz = 2. * P.x;
    }
    poly->regular = 1;
    poly->peripheries = peripheries;
    poly->sides = 2;
    poly->orientation = 0;
    poly->skew = 0;
    poly->distortion = 0;
    poly->vertices = vertices;

    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = ((sz)/(double)72);
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info) = (void *) poly;
}

static boolean point_inside(inside_t * inside_context, pointf p)
{
    static node_t *lastn;	/* last node argument */
    static double radius;
    pointf P;
    node_t *n = inside_context->s.n;

    P = ccwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));

    if (n != lastn) {
	int outp;
	polygon_t *poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);

	/* index to outer-periphery */
	outp = 2 * (poly->peripheries - 1);
	if (outp < 0)
	    outp = 0;

	radius = poly->vertices[outp + 1].x;
	lastn = n;
    }

    /* inside bounding box? */
    if ((fabs(P.x) > radius) || (fabs(P.y) > radius))
	return 0;

    return (hypot(P.x, P.y) <= radius);
}

static void point_gencode(GVJ_t * job, node_t * n)
{
    obj_state_t *obj = job->obj;
    polygon_t *poly;
    int i, j, sides, peripheries, style;
    pointf P, *vertices;
    static pointf *AF;
    static int A_size;
    boolean filled;
    char *color;
    int doMap = (obj->url || obj->explicit_tooltip);

    if (doMap && !(job->flags & (1<<2)))
	gvrender_begin_anchor(job,
			      obj->url, obj->tooltip, obj->target,
			      obj->id);

    poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
    vertices = poly->vertices;
    sides = poly->sides;
    peripheries = poly->peripheries;
    if (A_size < sides) {
	A_size = sides + 2;
	AF = (AF? (pointf*)grealloc(AF,(A_size)*sizeof(pointf)):(pointf*)gmalloc((A_size)*sizeof(pointf)));
    }

    checkStyle(n, &style);
    if (style & (1 << 5))
	gvrender_set_style(job, point_style);
    else
	gvrender_set_style(job, &point_style[1]);

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<0)) {
	color = late_nnstring(n, N_activepencolor, "#808080");
	gvrender_set_pencolor(job, color);
	color =
	    late_nnstring(n, N_activefillcolor, "#fcfcfc");
	gvrender_set_fillcolor(job, color);
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<1)) {
	color =
	    late_nnstring(n, N_selectedpencolor, "#303030");
	gvrender_set_pencolor(job, color);
	color =
	    late_nnstring(n, N_selectedfillcolor,
			  "#e8e8e8");
	gvrender_set_fillcolor(job, color);
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<3)) {
	color =
	    late_nnstring(n, N_deletedpencolor, "#e0e0e0");
	gvrender_set_pencolor(job, color);
	color =
	    late_nnstring(n, N_deletedfillcolor, "#f0f0f0");
	gvrender_set_fillcolor(job, color);
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->gui_state) & (1<<2)) {
	color =
	    late_nnstring(n, N_visitedpencolor, "#101010");
	gvrender_set_pencolor(job, color);
	color =
	    late_nnstring(n, N_visitedfillcolor, "#f8f8f8");
	gvrender_set_fillcolor(job, color);
    } else {
	color = findFillDflt(n, "black");
	gvrender_set_fillcolor(job, color);	/* emit fill color */
	penColor(job, n);	/* emit pen color */
    }
    filled = (!(0));

    /* if no boundary but filled, set boundary color to fill color */
    if (peripheries == 0) {
	peripheries = 1;
	if (color[0])
	    gvrender_set_pencolor(job, color);
    }

    for (j = 0; j < peripheries; j++) {
	for (i = 0; i < sides; i++) {
	    P = vertices[i + j * sides];
	    AF[i].x = P.x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	    AF[i].y = P.y + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
	}
	gvrender_ellipse(job, AF, sides, filled);
	/* fill innermost periphery only */
	filled = 0;
    }

    if (doMap) {
	if (job->flags & (1<<2))
	    gvrender_begin_anchor(job,
				  obj->url, obj->tooltip, obj->target,
				  obj->id);
	gvrender_end_anchor(job);
    }
}

/* the "record" shape is a rudimentary table formatter */









static char *reclblp;

static void free_field(field_t * f)
{
    int i;

    for (i = 0; i < f->n_flds; i++) {
	free_field(f->fld[i]);
    }

    free(f->id);
    free_label(f->lp);
    free(f->fld);
    free(f);
}

/* parse_error:
 * Clean up memory allocated in parse_reclbl, then return NULL
 */
static field_t *parse_error(field_t * rv, char *port)
{
    free_field(rv);
    if (port)
	free(port);
    return NULL;
}

static field_t *parse_reclbl(node_t * n, int LR, int flag, char *text)
{
    field_t *fp, *rv = (field_t*)zmalloc(sizeof(field_t));
    char *tsp, *psp=NULL, *hstsp, *hspsp=NULL, *sp;
    char *tmpport = NULL;
    int maxf, cnt, mode, wflag, ishardspace, fi;
    textlabel_t *lbl = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label);

    fp = NULL;
    for (maxf = 1, cnt = 0, sp = reclblp; *sp; sp++) {
	if (*sp == '\\') {
	    sp++;
	    if (*sp
		&& (*sp == '{' || *sp == '}' || *sp == '|' || *sp == '\\'))
		continue;
	}
	if (*sp == '{')
	    cnt++;
	else if (*sp == '}')
	    cnt--;
	else if (*sp == '|' && cnt == 0)
	    maxf++;
	if (cnt < 0)
	    break;
    }
    rv->fld = (field_t **)zmalloc((maxf)*sizeof(field_t *));
    rv->LR = LR;
    mode = 0;
    fi = 0;
    hstsp = tsp = text;
    wflag = (!(0));
    ishardspace = 0;
    while (wflag) {
	if ((*reclblp < ' ') && *reclblp) {    /* Ignore non-0 control characters */
	    reclblp++;
	    continue;
	}
	switch (*reclblp) {
	case '<':
	    if (mode & (4 | 2))
		return parse_error(rv, tmpport);
	    if (lbl->html)
		goto dotext;
	    mode |= (2 | 16);
	    reclblp++;
	    hspsp = psp = text;
	    break;
	case '>':
	    if (lbl->html)
		goto dotext;
	    if (!(mode & 16))
		return parse_error(rv, tmpport);
	    if (psp > text + 1 && psp - 1 != hspsp && *(psp - 1) == ' ')
		psp--;
	    *psp = '\000';
	    tmpport = strdup(text);
	    mode &= ~16;
	    reclblp++;
	    break;
	case '{':
	    reclblp++;
	    if (mode != 0 || !*reclblp)
		return parse_error(rv, tmpport);
	    mode = 4;
	    if (!(rv->fld[fi++] = parse_reclbl(n, (!(LR)), 0, text)))
		return parse_error(rv, tmpport);
	    break;
	case '}':
	case '|':
	case '\000':
	    if ((!*reclblp && !flag) || (mode & 16))
		return parse_error(rv, tmpport);
	    if (!(mode & 4))
		fp = rv->fld[fi++] = (field_t*)zmalloc(sizeof(field_t));
	    if (tmpport) {
		fp->id = tmpport;
		tmpport = NULL;
	    }
	    if (!(mode & (1 | 4)))
		mode |= 1, *tsp++ = ' ';
	    if (mode & 1) {
		if (tsp > text + 1 &&
		    tsp - 1 != hstsp && *(tsp - 1) == ' ')
		    tsp--;
		*tsp = '\000';
		fp->lp =
		    make_label((void *) n, strdup(text),
			       (lbl->html ? (1 << 1) : (0 << 1)),
			       lbl->fontsize, lbl->fontname,
			       lbl->fontcolor);
		fp->LR = (!(0));
		hstsp = tsp = text;
	    }
	    if (*reclblp) {
		if (*reclblp == '}') {
		    reclblp++;
		    rv->n_flds = fi;
		    return rv;
		}
		mode = 0;
		reclblp++;
	    } else
		wflag = 0;
	    break;
	case '\\':
	    if (*(reclblp + 1)) {
		if (((*(reclblp + 1)) == '{' || (*(reclblp + 1)) == '}' || (*(reclblp + 1)) == '|' || (*(reclblp + 1)) == '<' || (*(reclblp + 1)) == '>'))
		    reclblp++;
		else if ((*(reclblp + 1) == ' ') && !lbl->html)
		    ishardspace = (!(0)), reclblp++;
		else {
		    *tsp++ = '\\';
		    mode |= (8 | 1);
		    reclblp++;
		}
	    }
	    /* falling through ... */
	default:
	  dotext:
	    if ((mode & 4) && *reclblp != ' ')
		return parse_error(rv, tmpport);
	    if (!(mode & (8 | 16)) && *reclblp != ' ')
		mode |= (8 | 1);
	    if (mode & 8) {
		if (!
		    (*reclblp == ' ' && !ishardspace && *(tsp - 1) == ' '
		     && !lbl->html))
		    *tsp++ = *reclblp;
		if (ishardspace)
		    hstsp = tsp - 1;
	    } else if (mode & 16) {
		if (!(*reclblp == ' ' && !ishardspace &&
		      (psp == text || *(psp - 1) == ' ')))
		    *psp++ = *reclblp;
		if (ishardspace)
		    hspsp = psp - 1;
	    }
	    reclblp++;
	    while (*reclblp & 128)
		*tsp++ = *reclblp++;
	    break;
	}
    }
    rv->n_flds = fi;
    return rv;
}

static pointf size_reclbl(node_t * n, field_t * f)
{
    int i;
    char *p;
    double marginx, marginy;
    pointf d, d0;
    pointf dimen;

    if (f->lp) {
	dimen = f->lp->dimen;

	/* minimal whitespace around label */
	if ((dimen.x > 0.0) || (dimen.y > 0.0)) {
	    /* padding */
	    if ((p = agget(n, "margin"))) {
		i = sscanf(p, "%lf,%lf", &marginx, &marginy);
		if (i > 0) {
		    dimen.x += 2 * ((((marginx)*72>=0)?(int)((marginx)*72 + .5):(int)((marginx)*72 - .5)));
		    if (i > 1)
			dimen.y += 2 * ((((marginy)*72>=0)?(int)((marginy)*72 + .5):(int)((marginy)*72 - .5)));
		    else
			dimen.y += 2 * ((((marginy)*72>=0)?(int)((marginy)*72 + .5):(int)((marginy)*72 - .5)));
		} else
		    {((dimen).x += 4*4); ((dimen).y += 2*4);};
	    } else
		{((dimen).x += 4*4); ((dimen).y += 2*4);};
	}
	d = dimen;
    } else {
	d.x = d.y = 0;
	for (i = 0; i < f->n_flds; i++) {
	    d0 = size_reclbl(n, f->fld[i]);
	    if (f->LR) {
		d.x += d0.x;
		d.y = ((d.y)>(d0.y)?(d.y):(d0.y));
	    } else {
		d.y += d0.y;
		d.x = ((d.x)>(d0.x)?(d.x):(d0.x));
	    }
	}
    }
    f->size = d;
    return d;
}

static void resize_reclbl(field_t * f, pointf sz, int nojustify_p)
{
    int i, amt;
    double inc;
    pointf d;
    pointf newsz;
    field_t *sf;

    /* adjust field */
    d.x = sz.x - f->size.x;
    d.y = sz.y - f->size.y;
    f->size = sz;

    /* adjust text area */
    if (f->lp && !nojustify_p) {
	f->lp->space.x += d.x;
	f->lp->space.y += d.y;
    }

    /* adjust children */
    if (f->n_flds) {

	if (f->LR)
	    inc = d.x / f->n_flds;
	else
	    inc = d.y / f->n_flds;
	for (i = 0; i < f->n_flds; i++) {
	    sf = f->fld[i];
	    amt = ((int) ((i + 1) * inc)) - ((int) (i * inc));
	    if (f->LR)
		newsz = pointfof(sf->size.x + amt, sz.y);
	    else
		newsz = pointfof(sz.x, sf->size.y + amt);
	    resize_reclbl(sf, newsz, nojustify_p);
	}
    }
}

/* pos_reclbl:
 * Assign position info for each field. Also, set
 * the sides attribute, which indicates which sides of the
 * record are accessible to the field.
 */
static void pos_reclbl(field_t * f, pointf ul, int sides)
{
    int i, last, mask;

    f->sides = sides;
    f->b.LL = pointfof(ul.x, ul.y - f->size.y);
    f->b.UR = pointfof(ul.x + f->size.x, ul.y);
    last = f->n_flds - 1;
    for (i = 0; i <= last; i++) {
	if (sides) {
	    if (f->LR) {
		if (i == 0) {
		    if (i == last)
			mask = (1<<2) | (1<<0) | (1<<1) | (1<<3);
		    else
			mask = (1<<2) | (1<<0) | (1<<3);
		} else if (i == last)
		    mask = (1<<2) | (1<<0) | (1<<1);
		else
		    mask = (1<<2) | (1<<0);
	    } else {
		if (i == 0) {
		    if (i == last)
			mask = (1<<2) | (1<<0) | (1<<1) | (1<<3);
		    else
			mask = (1<<2) | (1<<1) | (1<<3);
		} else if (i == last)
		    mask = (1<<3) | (1<<0) | (1<<1);
		else
		    mask = (1<<3) | (1<<1);
	    }
	} else
	    mask = 0;
	pos_reclbl(f->fld[i], ul, sides & mask);
	if (f->LR)
	    ul.x = ul.x + f->fld[i]->size.x;
	else
	    ul.y = ul.y - f->fld[i]->size.y;
    }
}




    
    
	




    
	    




    

    
    
	
	
    
	
	
	
	    
	
    



/* syntax of labels: foo|bar|baz or foo|(recursive|label)|baz */
static void record_init(node_t * n)
{
    field_t *info;
    pointf ul, sz;
    int flip, len;
    char *textbuf;		/* temp buffer for storing labels */
    int sides = (1<<0) | (1<<1) | (1<<2) | (1<<3);

    /* Always use rankdir to determine how records are laid out */
    flip = (!((((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir) >> 2) & 1)));
    reclblp = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->text;
    len = strlen(reclblp);
    /* For some forgotten reason, an empty label is parsed into a space, so
     * we need at least two bytes in textbuf.
     */
    len = ((len)>(1)?(len):(1));
    textbuf = (char*)zmalloc((len + 1)*sizeof(char));
    if (!(info = parse_reclbl(n, flip, (!(0)), textbuf))) {
	agerr(AGERR, "bad label format %s\n", (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->text);
	reclblp = "\\N";
	info = parse_reclbl(n, flip, (!(0)), textbuf);
    }
    free(textbuf);
    size_reclbl(n, info);
    sz.x = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width))*72 - .5)));
    sz.y = (((((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72>=0)?(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 + .5):(int)(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height))*72 - .5)));
    if (mapbool(late_string(n, N_fixed, "false"))) {
	if ((sz.x < info->size.x) || (sz.y < info->size.y)) {
/* should check that the record really won't fit, e.g., there may be no text.
			agerr(AGWARN, "node '%s' size may be too small\n", agnameof(n));
*/
	}
    } else {
	sz.x = ((info->size.x)>(sz.x)?(info->size.x):(sz.x));
	sz.y = ((info->size.y)>(sz.y)?(info->size.y):(sz.y));
    }
    resize_reclbl(info, sz, mapbool(late_string(n, N_nojustify, "false")));
    ul = pointfof(-sz.x / 2., sz.y / 2.);	/* FIXME - is this still true:    suspected to introduce ronding error - see Kluge below */
    pos_reclbl(info, ul, sides);
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->width) = ((info->size.x)/(double)72);
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->height) = ((info->size.y + 1)/(double)72);	/* Kluge!!  +1 to fix rounding diff between layout and rendering 
						   otherwise we can get -1 coords in output */
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info) = (void *) info;
}

static void record_free(node_t * n)
{
    field_t *p = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);

    free_field(p);
}

static field_t *map_rec_port(field_t * f, char *str)
{
    field_t *rv;
    int sub;

    if (f->id && ((*(f->id)==*(str)&&!strcmp(f->id,str))))
	rv = f;
    else {
	rv = NULL;
	for (sub = 0; sub < f->n_flds; sub++)
	    if ((rv = map_rec_port(f->fld[sub], str)))
		break;
    }
    return rv;
}

static port record_port(node_t * n, char *portname, char *compass)
{
    field_t *f;
    field_t *subf;
    port rv;
    int sides;			/* bitmap of which sides the port lies along */

    if (portname[0] == '\0')
	return Center;
    sides = (1<<0) | (1<<1) | (1<<2) | (1<<3);
    if (compass == NULL)
	compass = "_";
    f = (field_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
    if ((subf = map_rec_port(f, portname))) {
	if (compassPort(n, &subf->b, &rv, compass, subf->sides, NULL)) {
	    agerr(AGWARN,
		  "node %s, port %s, unrecognized compass point '%s' - ignored\n",
		  agnameof(n), portname, compass);
	}
    } else if (compassPort(n, &f->b, &rv, portname, sides, NULL)) {
	unrecognized(n, portname);
    }

    return rv;
}

/* record_inside:
 * Note that this does not handle Mrecords correctly. It assumes 
 * everything is a rectangle.
 */
static boolean record_inside(inside_t * inside_context, pointf p)
{

    field_t *fld0;
    boxf *bp = inside_context->s.bp;
    node_t *n = inside_context->s.n;
    boxf bbox;

    /* convert point to node coordinate system */
    p = ccwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));

    if (bp == NULL) {
	fld0 = (field_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
	bbox = fld0->b;
    } else
	bbox = *bp;

    return (((((bbox).LL.x) <= ((p).x)) && (((p).x) <= ((bbox).UR.x))) && ((((bbox).LL.y) <= ((p).y)) && (((p).y) <= ((bbox).UR.y))));
}

/* record_path:
 * Generate box path from port to border.
 * See poly_path for constraints.
 */
static int record_path(node_t * n, port * prt, int side, boxf rv[],
		       int *kptr)
{
    int i, ls, rs;
    pointf p;
    field_t *info;

    if (!prt->defined)
	return 0;
    p = prt->p;
    info = (field_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);

    for (i = 0; i < info->n_flds; i++) {
	if (!((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
	    ls = info->fld[i]->b.LL.x;
	    rs = info->fld[i]->b.UR.x;
	} else {
	    ls = info->fld[i]->b.LL.y;
	    rs = info->fld[i]->b.UR.y;
	}
	if ((((ls) <= (p.x)) && ((p.x) <= (rs)))) {
	    /* FIXME: I don't understand this code */
	    if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
		rv[0] = flip_rec_boxf(info->fld[i]->b, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord));
	    } else {
		rv[0].LL.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + ls;
		rv[0].LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2);
		rv[0].UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + rs;
	    }
	    rv[0].UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2);
	    *kptr = 1;
	    break;
	}
    }
    return side;
}

static void gen_fields(GVJ_t * job, node_t * n, field_t * f)
{
    int i;
    pointf AF[2], coord;

    if (f->lp) {
	f->lp->pos = add_pointf(mid_pointf(f->b.LL, f->b.UR), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord));
	emit_label(job, EMIT_NLABEL, f->lp);
	penColor(job, n);
    }

    coord = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
    for (i = 0; i < f->n_flds; i++) {
	if (i > 0) {
	    if (f->LR) {
		AF[0] = f->fld[i]->b.LL;
		AF[1].x = AF[0].x;
		AF[1].y = f->fld[i]->b.UR.y;
	    } else {
		AF[1] = f->fld[i]->b.UR;
		AF[0].x = f->fld[i]->b.LL.x;
		AF[0].y = AF[1].y;
	    }
	    AF[0] = add_pointf(AF[0], coord);
	    AF[1] = add_pointf(AF[1], coord);
	    gvrender_polyline(job, AF, 2);
	}
	gen_fields(job, n, f->fld[i]);
    }
}

static void record_gencode(GVJ_t * job, node_t * n)
{
    obj_state_t *obj = job->obj;
    boxf BF;
    pointf AF[4];
    int style;
    field_t *f;
    int doMap = (obj->url || obj->explicit_tooltip);
    int filled;
    char* clrs[2];

    f = (field_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
    BF = f->b;
    BF.LL.x += (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
    BF.LL.y += (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    BF.UR.x += (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
    BF.UR.y += (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;

    if (doMap && !(job->flags & (1<<2)))
	gvrender_begin_anchor(job,
			      obj->url, obj->tooltip, obj->target,
			      obj->id);
    style = stylenode(job, n);
    penColor(job, n);
    clrs[0] = NULL;
    if (style & (1 << 0)) {
	char* fillcolor = findFill (n);
	float frac;
	
	if (findStopColor (fillcolor, clrs, &frac)) {
            gvrender_set_fillcolor(job, clrs[0]);
	    if (clrs[1]) 
		gvrender_set_gradient_vals(job,clrs[1],late_int(n,N_gradientangle,0,0), frac);
	    else 
		gvrender_set_gradient_vals(job,"black",late_int(n,N_gradientangle,0,0), frac);
	    if (style & (1 << 1))
		filled = 3;
	    else
		filled = 2;
	}
	else {
	    filled = 1;
            gvrender_set_fillcolor(job, fillcolor);
	}
    }
    else filled = 0;

    if ((*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name)==*("Mrecord")&&!strcmp((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape)->name,"Mrecord")))
	style |= (1 << 2);
    if (((style) & ((1 << 2) | (1 << 3) | (127 << 24)))) {
	AF[0] = BF.LL;
	AF[2] = BF.UR;
	AF[1].x = AF[2].x;
	AF[1].y = AF[0].y;
	AF[3].x = AF[0].x;
	AF[3].y = AF[2].y;
	round_corners(job, AF, 4, style, filled);
    } else {
	gvrender_box(job, BF, filled);
    }

    gen_fields(job, n, f);

    if (clrs[0]) free (clrs[0]);

    if (doMap) {
	if (job->flags & (1<<2))
	    gvrender_begin_anchor(job,
				  obj->url, obj->tooltip, obj->target,
				  obj->id);
	gvrender_end_anchor(job);
    }
}

static shape_desc **UserShape;
static int N_UserShape;

shape_desc *find_user_shape(const char *name)
{
    int i;
    if (UserShape) {
	for (i = 0; i < N_UserShape; i++) {
	    if ((*(UserShape[i]->name)==*(name)&&!strcmp(UserShape[i]->name,name)))
		return UserShape[i];
	}
    }
    return NULL;
}

static shape_desc *user_shape(char *name)
{
    int i;
    shape_desc *p;

    if ((p = find_user_shape(name)))
	return p;
    i = N_UserShape++;
    UserShape = (UserShape? (shape_desc **)grealloc(UserShape,(N_UserShape)*sizeof(shape_desc *)):(shape_desc **)gmalloc((N_UserShape)*sizeof(shape_desc *)));
    p = UserShape[i] = (shape_desc*)zmalloc(sizeof(shape_desc));
    *p = Shapes[0];
    p->name = strdup(name);
    if (Lib == NULL && !(*(name)==*("custom")&&!strcmp(name,"custom"))) {
	agerr(AGWARN, "using %s for unknown shape %s\n", Shapes[0].name,
	      p->name);
	p->usershape = 0;
    } else {
	p->usershape = (!(0));
    }
    return p;
}

shape_desc *bind_shape(char *name, node_t * np)
{
    shape_desc *ptr, *rv = NULL;
    const char *str;

    str = safefile(agget(np, "shapefile"));
    /* If shapefile is defined and not epsf, set shape = custom */
    if (str && !(*(name)==*("epsf")&&!strcmp(name,"epsf")))
	name = "custom";
    if (!(*(name)==*("custom")&&!strcmp(name,"custom"))) {
	for (ptr = Shapes; ptr->name; ptr++) {
	    if ((*(ptr->name)==*(name)&&!strcmp(ptr->name,name))) {
		rv = ptr;
		break;
	    }
	}
    }
    if (rv == NULL)
	rv = user_shape(name);
    return rv;
}

static boolean epsf_inside(inside_t * inside_context, pointf p)
{
    pointf P;
    double x2;
    node_t *n = inside_context->s.n;

    P = ccwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));
    x2 = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2;
    return ((P.y >= -x2) && (P.y <= x2) && (P.x >= -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw))
	    && (P.x <= (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)));
}

static void epsf_gencode(GVJ_t * job, node_t * n)
{
    obj_state_t *obj = job->obj;
    epsf_t *desc;
    int doMap = (obj->url || obj->explicit_tooltip);

    desc = (epsf_t *) ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info));
    if (!desc)
	return;

    if (doMap && !(job->flags & (1<<2)))
	gvrender_begin_anchor(job,
			      obj->url, obj->tooltip, obj->target,
			      obj->id);
    if (desc)
	fprintf(job->output_file,
		"%.5g %.5g translate newpath user_shape_%d\n",
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + desc->offset.x,
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + desc->offset.y, desc->macro_id);
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->pos = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);

    emit_label(job, EMIT_NLABEL, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label));
    if (doMap) {
	if (job->flags & (1<<2))
	    gvrender_begin_anchor(job,
				  obj->url, obj->tooltip, obj->target,
				  obj->id);
	gvrender_end_anchor(job);
    }
}






static pointf star_size (pointf sz0)
{
    pointf sz;
    double r0, r, rx, ry;

    rx = sz0.x/(2*cos((3.14159265358979323846/10.0)));
    ry = sz0.y/(sin((3.14159265358979323846/10.0)) + sin((3*(3.14159265358979323846/10.0))));
    r0 = ((rx)>(ry)?(rx):(ry));
    r = (r0*sin((2*(2*(3.14159265358979323846/10.0))))*cos((2*(3.14159265358979323846/10.0))))/(cos((3.14159265358979323846/10.0))*cos((2*(2*(3.14159265358979323846/10.0)))));

    sz.x = 2*r*cos((3.14159265358979323846/10.0));
    sz.y = r*(1 + sin((3*(3.14159265358979323846/10.0))));
    return sz;
}

static void star_vertices (pointf* vertices, pointf* bb)
{
    int i;
    pointf sz = *bb;
    double offset, a, aspect = (1 + sin((3*(3.14159265358979323846/10.0))))/(2*cos((3.14159265358979323846/10.0)));
    double r, r0, theta = (3.14159265358979323846/10.0);

    /* Scale up width or height to required aspect ratio */
    a = sz.y/sz.x;
    if (a > aspect) {
	sz.x = sz.y/aspect;
    }
    else if (a < aspect) {
	sz.y = sz.x*aspect;
    }

    /* for given sz, get radius */
    r = sz.x/(2*cos((3.14159265358979323846/10.0)));
    r0 = (r*cos((3.14159265358979323846/10.0))*cos((2*(2*(3.14159265358979323846/10.0)))))/(sin((2*(2*(3.14159265358979323846/10.0))))*cos((2*(3.14159265358979323846/10.0))));
    
    /* offset is the y shift of circle center from bb center */
    offset = (r*(1 - sin((3*(3.14159265358979323846/10.0)))))/2;

    for (i = 0; i < 10; i += 2) {
	vertices[i].x = r*cos(theta);
	vertices[i].y = r*sin(theta) - offset;
	theta += (2*(3.14159265358979323846/10.0));
	vertices[i+1].x = r0*cos(theta);
	vertices[i+1].y = r0*sin(theta) - offset;
	theta += (2*(3.14159265358979323846/10.0));
    }

    *bb = sz;
}

static boolean star_inside(inside_t * inside_context, pointf p)
{
    static node_t *lastn;	/* last node argument */
    static polygon_t *poly;
    static int outp, sides;
    static pointf *vertex;
    static pointf O;		/* point (0,0) */

    boxf *bp = inside_context->s.bp;
    node_t *n = inside_context->s.n;
    pointf P, Q, R;
    int i, outcnt;

    P = ccwrotatepf(p, 90 * (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3));

    /* Quick test if port rectangle is target */
    if (bp) {
	boxf bbox = *bp;
	return (((((bbox).LL.x) <= ((P).x)) && (((P).x) <= ((bbox).UR.x))) && ((((bbox).LL.y) <= ((P).y)) && (((P).y) <= ((bbox).UR.y))));
    }

    if (n != lastn) {
	poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
	vertex = poly->vertices;
	sides = poly->sides;

	/* index to outer-periphery */
	outp = (poly->peripheries - 1) * sides;
	if (outp < 0)
	    outp = 0;
	lastn = n;
    }

    outcnt = 0;
    for (i = 0; i < sides; i += 2) {
	Q = vertex[i + outp];
	R = vertex[((i+4) % sides) + outp];
	if (!(same_side(P, O, Q, R))) {
	    outcnt++;
	}
	if (outcnt == 2) {
	    return 0;
	}
    }
    return (!(0));
}

static char *side_port[] = { "s", "e", "n", "w" };

static point cvtPt(pointf p, int rankdir)
{
    pointf q = { 0, 0 };
    point Q;

    switch (rankdir) {
    case 0:
	q = p;
	break;
    case 2:
	q.x = p.x;
	q.y = -p.y;
	break;
    case 1:
	q.y = p.x;
	q.x = -p.y;
	break;
    case 3:
	q.y = p.x;
	q.x = p.y;
	break;
    }
    ((Q).x = (((q).x>=0)?(int)((q).x + .5):(int)((q).x - .5)),(Q).y = (((q).y>=0)?(int)((q).y + .5):(int)((q).y - .5)));
    return Q;
}

/* closestSide:
 * Resolve unspecified compass-point port to best available port.
 * At present, this finds the available side closest to the center
 * of the other port.
 *
 * This could be improved:
 *  - if other is unspecified, do them together
 *  - if dot, bias towards bottom of one to top of another, if possible
 *  - if line segment from port centers uses available sides, use these
 *     or center. (This latter may require spline routing to cooperate.)
 */
static char *closestSide(node_t * n, node_t * other, port * oldport)
{
    boxf b;
    int rkd = (((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)->root))->data))->rankdir & 0x3);
    point p = { 0, 0 };
    point pt = cvtPt((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord), rkd);
    point opt = cvtPt((((Agnodeinfo_t*)(((Agobj_t*)(other))->data))->coord), rkd);
    int sides = oldport->side;
    char *rv = NULL;
    int i, d, mind = 0;

    if ((sides == 0) || (sides == ((1<<2) | (1<<0) | (1<<3) | (1<<1))))
	return rv;		/* use center */

    if (oldport->bp) {
	b = *oldport->bp;
    } else {
	if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1)) {
	    b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2;
	    b.LL.x = -b.UR.x;
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
	    b.LL.y = -b.UR.y;
	} else {
	    b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2;
	    b.LL.y = -b.UR.y;
	    b.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
	    b.LL.x = -b.UR.x;
	}
    }

    for (i = 0; i < 4; i++) {
	if ((sides & (1 << i)) == 0)
	    continue;
	switch (i) {
	case 0:
	    p.y = b.LL.y;
	    p.x = (b.LL.x + b.UR.x) / 2;
	    break;
	case 1:
	    p.x = b.UR.x;
	    p.y = (b.LL.y + b.UR.y) / 2;
	    break;
	case 2:
	    p.y = b.UR.y;
	    p.x = (b.LL.x + b.UR.x) / 2;
	    break;
	case 3:
	    p.x = b.LL.x;
	    p.y = (b.LL.y + b.UR.y) / 2;
	    break;
	}
	p.x += pt.x;
	p.y += pt.y;
	d = ((((((p).x -(opt).x)) * (((p).x -(opt).x))) + ((((p).y -(opt).y)) * (((p).y -(opt).y)))));
	if (!rv || (d < mind)) {
	    mind = d;
	    rv = side_port[i];
	}
    }
    return rv;
}

port resolvePort(node_t * n, node_t * other, port * oldport)
{
    port rv;
    char *compass = closestSide(n, other, oldport);

    /* transfer name pointer; all other necessary fields will be regenerated */
    rv.name = oldport->name;
    compassPort(n, oldport->bp, &rv, compass, oldport->side, NULL);

    return rv;
}

void resolvePorts(edge_t * e)
{
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).dyna)
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port) =
	    resolvePort(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port));
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).dyna)
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port) =
	    resolvePort(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), &(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port));
}
