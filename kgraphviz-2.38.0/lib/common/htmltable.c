#line 1 "graphviz-2.38.0\\lib\\common\\htmltable.c" 1
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


/* Implementation of HTML-like tables.
 * 
 * The (now purged) CodeGen graphics model, especially with integral coodinates, is
 * not adequate to handle this as we would like. In particular, it is
 * difficult to handle notions of adjacency and correct rounding to pixels.
 * For example, if 2 adjacent boxes bb1.UR.x == bb2.LL.x, the rectangles
 * may be drawn overlapping. However, if we use bb1.UR.x+1 == bb2.LL.x
 * there may or may not be a gap between them, even in the same device
 * depending on their positions. When CELLSPACING > 1, this isn't as much
 * of a problem.
 *
 * We allow negative spacing as a hack to allow overlapping cell boundaries.
 * For the reasons discussed above, this is difficult to get correct.
 * This is an important enough case we should extend the table model to
 * support it correctly. This could be done by allowing a table attribute,
 * e.g., CELLGRID=n, which sets CELLBORDER=0 and has the border drawing
 * handled correctly by the table.
 */

#line 1 "graphviz-2.38.0\\lib\\common\\htmltable.c" 1
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








#line 37 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2
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






#line 38 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2
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











    
	
	
	
	
    





    
			 




    




    




    




    




    











































#line 39 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\pointset.h" 1
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




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 17 "graphviz-2.38.0\\lib\\common\\pointset.h" 2
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











    


































































#line 18 "graphviz-2.38.0\\lib\\common\\pointset.h" 2





    typedef Dict_t PointSet;
    typedef Dict_t PointMap;






/*visual studio*/





/*end visual studio*/

	 PointSet *newPS(void);
     void freePS(PointSet *);
     void insertPS(PointSet *, point);
     void addPS(PointSet *, int, int);
     int inPS(PointSet *, point);
     int isInPS(PointSet *, int, int);
     int sizeOf(PointSet *);
     point *pointsOf(PointSet *);

     PointMap *newPM(void);
     void clearPM(PointMap *);
     void freePM(PointMap *);
     int insertPM(PointMap *, int, int, int);
     int updatePM(PointMap * pm, int x, int y, int v);







#line 40 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\intset.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 17 "graphviz-2.38.0\\lib\\common\\intset.h" 2

typedef struct {
    int       id;
    Dtlink_t  link;
} intitem;

extern Dt_t* openIntSet (void);
extern void addIntSet (Dt_t*, int);
extern int inIntSet (Dt_t*, int);

#line 41 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 42 "graphviz-2.38.0\\lib\\common\\htmltable.c" 2





typedef struct {
    char *url;
    char *tooltip;
    char *target;
    char *id;
    boolean explicit_tooltip;
    point LL;
    point UR;
} htmlmap_data_t;





/* pushFontInfo:
 * Replace current font attributes in env with ones from fp,
 * storing old attributes in savp. We only deal with attributes
 * set in env. The attributes are restored via popFontInfo.
 */
static void
pushFontInfo(htmlenv_t * env, textfont_t * fp, textfont_t * savp)
{
    if (env->finfo.name) {
	if (fp->name) {
	    savp->name = env->finfo.name;
	    env->finfo.name = fp->name;
	} else
	    savp->name = NULL;
    }
    if (env->finfo.color) {
	if (fp->color) {
	    savp->color = env->finfo.color;
	    env->finfo.color = fp->color;
	} else
	    savp->color = NULL;
    }
    if (env->finfo.size >= 0) {
	if (fp->size >= 0) {
	    savp->size = env->finfo.size;
	    env->finfo.size = fp->size;
	} else
	    savp->size = -1.0;
    }
}

/* popFontInfo:
 * Restore saved font attributes.
 * Copy only set values.
 */
static void popFontInfo(htmlenv_t * env, textfont_t * savp)
{
    if (savp->name)
	env->finfo.name = savp->name;
    if (savp->color)
	env->finfo.color = savp->color;
    if (savp->size >= 0.0)
	env->finfo.size = savp->size;
}

static void
emit_htextspans(GVJ_t * job, int nspans, htextspan_t * spans, pointf p,
		double halfwidth_x, textfont_t finfo, boxf b, int simple)
{
    int i, j;
    double center_x, left_x, right_x;
    textspan_t tl;
    textfont_t tf;
    pointf p_ = { 0.0, 0.0 };
    textspan_t *ti;

    center_x = p.x;
    left_x = center_x - halfwidth_x;
    right_x = center_x + halfwidth_x;

    /* Initial p is in center of text block; set initial baseline
     * to top of text block.
     */
    p_.y = p.y + (b.UR.y - b.LL.y) / 2.0;

    gvrender_begin_label(job, LABEL_HTML);
    for (i = 0; i < nspans; i++) {
	/* set p.x to leftmost point where the line of text begins */
	switch (spans[i].just) {
	case 'l':
	    p.x = left_x;
	    break;
	case 'r':
	    p.x = right_x - spans[i].size;
	    break;
	default:
	case 'n':
	    p.x = center_x - spans[i].size / 2.0;
	    break;
	}
	p_.y -= spans[i].lfsize;	/* move to current base line */

	ti = spans[i].items;
	for (j = 0; j < spans[i].nitems; j++) {
	    if (ti->font && (ti->font->size > 0))
		tf.size = ti->font->size;
	    else
		tf.size = finfo.size;
	    if (ti->font && ti->font->name)
		tf.name = ti->font->name;
	    else
		tf.name = finfo.name;
	    if (ti->font && ti->font->color)
		tf.color = ti->font->color;
	    else
		tf.color = finfo.color;
	    if (ti->font && ti->font->flags)
		tf.flags = ti->font->flags;
	    else
		tf.flags = 0;

	    gvrender_set_pencolor(job, tf.color);

	    tl.str = ti->str;
	    tl.font = &tf;
	    tl.yoffset_layout = ti->yoffset_layout;
	    if (simple)
		tl.yoffset_centerline = ti->yoffset_centerline;
	    else
		tl.yoffset_centerline = 1;
	    tl.font->postscript_alias = ti->font->postscript_alias;
	    tl.layout = ti->layout;
	    tl.size.x = ti->size.x;
	    tl.size.y = spans[i].lfsize;
	    tl.just = 'l';

	    p_.x = p.x;
	    gvrender_textspan(job, p_, &tl);
	    p.x += ti->size.x;
	    ti++;
	}
    }

    gvrender_end_label(job);
}

static void emit_html_txt(GVJ_t * job, htmltxt_t * tp, htmlenv_t * env)
{
    double halfwidth_x;
    pointf p;

    /* make sure that there is something to do */
    if (tp->nspans < 1)
	return;

    halfwidth_x = ((double) (tp->box.UR.x - tp->box.LL.x)) / 2.0;
    p.x = env->pos.x + ((double) (tp->box.UR.x + tp->box.LL.x)) / 2.0;
    p.y = env->pos.y + ((double) (tp->box.UR.y + tp->box.LL.y)) / 2.0;

    emit_htextspans(job, tp->nspans, tp->spans, p, halfwidth_x, env->finfo,
		    tp->box, tp->simple);
}

static void doSide(GVJ_t * job, pointf p, double wd, double ht)
{
    boxf BF;

    BF.LL = p;
    BF.UR.x = p.x + wd;
    BF.UR.y = p.y + ht;
    gvrender_box(job, BF, 1);
}

/* mkPts:
 * Convert boxf into four corner points
 * If border is > 1, inset the points by half the border.
 * It is assume AF is pointf[4], so the data is store there
 * and AF is returned.
 */
static pointf *mkPts(pointf * AF, boxf b, int border)
{
    AF[0] = b.LL;
    AF[2] = b.UR;
    if (border > 1) {
	double delta = ((double) border) / 2.0;
	AF[0].x += delta;
	AF[0].y += delta;
	AF[2].x -= delta;
	AF[2].y -= delta;
    }
    AF[1].x = AF[2].x;
    AF[1].y = AF[0].y;
    AF[3].x = AF[0].x;
    AF[3].y = AF[2].y;

    return AF;
}

/* doBorder:
 * Draw a rectangular border for the box b.
 * Handles dashed and dotted styles, rounded corners.
 * Also handles thick lines.
 * Assume dp->border > 0
 */
static void doBorder(GVJ_t * job, htmldata_t * dp, boxf b)
{
    pointf AF[6];
    char *sptr[2];
    char *color = (dp->pencolor ? dp->pencolor : "black");
    unsigned short sides;

    gvrender_set_pencolor(job, color);
    if ((dp->style & ((1 << 8) | (1 << 7)))) {
	sptr[0] = sptr[1] = NULL;
	if (dp->style & (1 << 8))
	    sptr[0] = "dashed";
	else if (dp->style & (1 << 7))
	    sptr[0] = "dotted";
	gvrender_set_style(job, sptr);
    } else
	gvrender_set_style(job, job->gvc->defaultlinestyle);
    gvrender_set_penwidth(job, dp->border);

    if (dp->style & (1 << 2))
	round_corners(job, mkPts(AF, b, dp->border), 4, (1 << 2), 0);
    else if ((sides = (dp->flags & ((1 << 10)|(1 << 11)|(1 << 12)|(1 << 13))))) {
	mkPts (AF+1, b, dp->border);  /* AF[1-4] has LL=SW,SW,UR=NE,NW */
	switch (sides) {
	case (1 << 13) :
	    gvrender_polyline(job, AF+1, 2);
	    break;
	case (1 << 12) :
	    gvrender_polyline(job, AF+2, 2);
	    break;
	case (1 << 11) :
	    gvrender_polyline(job, AF+3, 2);
	    break;
	case (1 << 10) :
	    AF[0] = AF[4];
	    gvrender_polyline(job, AF, 2);
	    break;
	case (1 << 13)|(1 << 12) :
	    gvrender_polyline(job, AF+1, 3);
	    break;
	case (1 << 12)|(1 << 11) :
	    gvrender_polyline(job, AF+2, 3);
	    break;
	case (1 << 11)|(1 << 10) :
	    AF[5] = AF[1];
	    gvrender_polyline(job, AF+3, 3);
	    break;
	case (1 << 10)|(1 << 13) :
	    AF[0] = AF[4];
	    gvrender_polyline(job, AF, 3);
	    break;
	case (1 << 13)|(1 << 12)|(1 << 11) :
	    gvrender_polyline(job, AF+1, 4);
	    break;
	case (1 << 12)|(1 << 11)|(1 << 10) :
	    AF[5] = AF[1];
	    gvrender_polyline(job, AF+2, 4);
	    break;
	case (1 << 11)|(1 << 10)|(1 << 13) :
	    AF[5] = AF[1];
	    AF[6] = AF[2];
	    gvrender_polyline(job, AF+3, 4);
	    break;
	case (1 << 10)|(1 << 13)|(1 << 12) :
	    AF[0] = AF[4];
	    gvrender_polyline(job, AF, 4);
	    break;
	case (1 << 11)|(1 << 13) :
	    gvrender_polyline(job, AF+1, 2);
	    gvrender_polyline(job, AF+3, 2);
	    break;
	case (1 << 10)|(1 << 12) :
	    AF[0] = AF[4];
	    break;
	}
    } else {
	if (dp->border > 1) {
	    double delta = ((double) dp->border) / 2.0;
	    b.LL.x += delta;
	    b.LL.y += delta;
	    b.UR.x -= delta;
	    b.UR.y -= delta;
	}
	gvrender_box(job, b, 0);
    }
}

/* setFill:
 * Set up fill values from given color; make pen transparent.
 * Return type of fill required.
 */
static int
setFill(GVJ_t * job, char *color, int angle, int style, char *clrs[2])
{
    int filled;
    float frac;
    if (findStopColor(color, clrs, &frac)) {
	gvrender_set_fillcolor(job, clrs[0]);
	if (clrs[1])
	    gvrender_set_gradient_vals(job, clrs[1], angle, frac);
	else
	    gvrender_set_gradient_vals(job, "black", angle, frac);
	if (style & (1 << 1))
	    filled = 3;
	else
	    filled = 2;
    } else {
	gvrender_set_fillcolor(job, color);
	filled = 1;
    }
    gvrender_set_pencolor(job, "transparent");
    return filled;
}

/* initAnchor:
 * Save current map values
 * Initialize fields in job->obj pertaining to anchors.
 * In particular, this also sets the output rectangle.
 * If there is something to do, close current anchor if
 * necessary, start the anchor and returns 1.
 * Otherwise, it returns 0.
 *
 * FIX: Should we provide a tooltip if none is set, as is done
 * for nodes, edges, etc. ?
 */
static int
initAnchor(GVJ_t * job, htmlenv_t * env, htmldata_t * data, boxf b,
	   htmlmap_data_t * save, int closePrev)
{
    obj_state_t *obj = job->obj;
    int changed;
    char *id;
    static int anchorId;
    int internalId = 0;
    agxbuf xb;
    char intbuf[30];		/* hold 64-bit decimal integer */
    unsigned char buf[128];

    save->url = obj->url;
    save->tooltip = obj->tooltip;
    save->target = obj->target;
    save->id = obj->id;
    save->explicit_tooltip = obj->explicit_tooltip;
    id = data->id;
    if (!id || !*id) {		/* no external id, so use the internal one */
	agxbinit(&xb, 128, buf);
	if (!env->objid) {
	    env->objid = strdup(getObjId(job, obj->u.n, &xb));
	    env->objid_set = 1;
	}
	agxbput(&xb, env->objid);
	sprintf(intbuf, "_%d", anchorId++);
	agxbput(&xb, intbuf);
	id = (((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf));
	internalId = 1;
    }
    changed =
	initMapData(job, NULL, data->href, data->title, data->target, id,
		    obj->u.g);
    if (internalId)
	agxbfree(&xb);

    if (changed) {
	if (closePrev && (save->url || save->explicit_tooltip))
	    gvrender_end_anchor(job);
	if (obj->url || obj->explicit_tooltip) {
	    emit_map_rect(job, b);
	    gvrender_begin_anchor(job,
				  obj->url, obj->tooltip, obj->target,
				  obj->id);
	}
    }
    return changed;
}




/* endAnchor:
 * Pop context pushed by initAnchor.
 * This is done by ending current anchor, restoring old values and
 * freeing new, and reopening previous anchor if necessary.
 *
 * NB: We don't save or restore geometric map info. This is because
 * this preservation of map context is only necessary for SVG-like
 * systems where graphical items are wrapped in an anchor, and we map
 * top-down. For ordinary map anchors, this is all done bottom-up, so
 * the geometric map info at the higher level hasn't been emitted yet.
 */
static void endAnchor(GVJ_t * job, htmlmap_data_t * save, int openPrev)
{
    obj_state_t *obj = job->obj;

    if (obj->url || obj->explicit_tooltip)
	gvrender_end_anchor(job);
    if(obj->url != save->url) {free(obj->url); obj->url = save->url;};
    if(obj->tooltip != save->tooltip) {free(obj->tooltip); obj->tooltip = save->tooltip;};
    if(obj->target != save->target) {free(obj->target); obj->target = save->target;};
    if(obj->id != save->id) {free(obj->id); obj->id = save->id;};
    obj->explicit_tooltip = save->explicit_tooltip;
    if (openPrev && (obj->url || obj->explicit_tooltip))
	gvrender_begin_anchor(job,
			      obj->url, obj->tooltip, obj->target,
			      obj->id);
}

/* forward declaration */
static void emit_html_cell(GVJ_t * job, htmlcell_t * cp, htmlenv_t * env);

/* emit_html_rules:
 * place vertical and horizontal lines between adjacent cells and
 * extend the lines to intersect the rounded table boundary 
 */
static void
emit_html_rules(GVJ_t * job, htmlcell_t * cp, htmlenv_t * env, char *color, htmlcell_t* nextc)
{
    pointf rule_pt;
    double rule_length;
    unsigned char base;
    boxf pts = cp->data.box;
    pointf pos = env->pos;

    if (!color)
	color = "black";
    gvrender_set_fillcolor(job, color);
    gvrender_set_pencolor(job, color);

    pts = cp->data.box;
    pts.LL.x += pos.x;
    pts.UR.x += pos.x;
    pts.LL.y += pos.y;
    pts.UR.y += pos.y;

    //Determine vertical line coordinate and length
    if ((cp->ruled & 1) && (cp->col + cp->cspan < cp->parent->cc)) {
	if (cp->row == 0) {	// first row
	    // extend to center of table border and add half cell spacing
	    base = cp->parent->data.border + cp->parent->data.space / 2;
	    rule_pt.y = pts.LL.y - cp->parent->data.space / 2;
	} else if (cp->row + cp->rspan == cp->parent->rc) {	// bottom row
	    // extend to center of table border and add half cell spacing
	    base = cp->parent->data.border + cp->parent->data.space / 2;
	    rule_pt.y = pts.LL.y - cp->parent->data.space / 2 - base;
	} else {
	    base = 0;
	    rule_pt.y = pts.LL.y - cp->parent->data.space / 2;
	}
	rule_pt.x = pts.UR.x + cp->parent->data.space / 2;
	rule_length = base + pts.UR.y - pts.LL.y + cp->parent->data.space;
	doSide(job, rule_pt, 0, rule_length);
    }
    //Determine the horizontal coordinate and length
    if ((cp->ruled & 2) && (cp->row + cp->rspan < cp->parent->rc)) {
	if (cp->col == 0) {	// first column 
	    // extend to center of table border and add half cell spacing
	    base = cp->parent->data.border + cp->parent->data.space / 2;
	    rule_pt.x = pts.LL.x - base - cp->parent->data.space / 2;
	    if (cp->col + cp->cspan == cp->parent->cc)	// also last column
		base *= 2;
	    /* incomplete row of cells; extend line to end */
	    else if (nextc && (nextc->row != cp->row)) {
		base += (cp->parent->data.box.UR.x + pos.x) - (pts.UR.x + cp->parent->data.space / 2);
	    }
	} else if (cp->col + cp->cspan == cp->parent->cc) {	// last column
	    // extend to center of table border and add half cell spacing
	    base = cp->parent->data.border + cp->parent->data.space / 2;
	    rule_pt.x = pts.LL.x - cp->parent->data.space / 2;
	} else {
	    base = 0;
	    rule_pt.x = pts.LL.x - cp->parent->data.space / 2;
	    /* incomplete row of cells; extend line to end */
	    if (nextc && (nextc->row != cp->row)) {
		base += (cp->parent->data.box.UR.x + pos.x) - (pts.UR.x + cp->parent->data.space / 2);
	    }
	}
	rule_pt.y = pts.LL.y - cp->parent->data.space / 2;
	rule_length = base + pts.UR.x - pts.LL.x + cp->parent->data.space;
	doSide(job, rule_pt, rule_length, 0);
    }
}

static void emit_html_tbl(GVJ_t * job, htmltbl_t * tbl, htmlenv_t * env)
{
    boxf pts = tbl->data.box;
    pointf pos = env->pos;
    htmlcell_t **cells = tbl->u.n.cells;
    htmlcell_t *cp;
    static textfont_t savef;
    htmlmap_data_t saved;
    int anchor;			/* if true, we need to undo anchor settings. */
    int doAnchor = (tbl->data.href || tbl->data.target);
    pointf AF[4];

    if (tbl->font)
	pushFontInfo(env, tbl->font, &savef);

    pts.LL.x += pos.x;
    pts.UR.x += pos.x;
    pts.LL.y += pos.y;
    pts.UR.y += pos.y;

    if (doAnchor && !(job->flags & (1<<2)))
	anchor = initAnchor(job, env, &tbl->data, pts, &saved, 1);
    else
	anchor = 0;

    if (!(tbl->data.style & (1 << 5))) {

	/* Fill first */
	if (tbl->data.bgcolor) {
	    char *clrs[2];
	    int filled =
		setFill(job, tbl->data.bgcolor, tbl->data.gradientangle,
			tbl->data.style, clrs);
	    if (tbl->data.style & (1 << 2)) {
		round_corners(job, mkPts(AF, pts, tbl->data.border), 4,
			      (1 << 2), filled);
	    } else
		gvrender_box(job, pts, filled);
	    free(clrs[0]);
	}

	while (*cells) {
	    emit_html_cell(job, *cells, env);
	    cells++;
	}

	/* Draw table rules and border.
	 * Draw after cells so we can draw over any fill.
	 * At present, we set the penwidth to 1 for rules until we provide the calculations to take
	 * into account wider rules.
	 */
	cells = tbl->u.n.cells;
	gvrender_set_penwidth(job, 1.0);
	while ((cp = *cells++)) {
	    if (cp->ruled)
		emit_html_rules(job, cp, env, tbl->data.pencolor, *cells);
	}

	if (tbl->data.border)
	    doBorder(job, &tbl->data, pts);

    }

    if (anchor)
	endAnchor(job, &saved, 1);

    if (doAnchor && (job->flags & (1<<2))) {
	if (initAnchor(job, env, &tbl->data, pts, &saved, 0))
	    endAnchor(job, &saved, 0);
    }

    if (tbl->font)
	popFontInfo(env, &savef);
}

/* emit_html_img:
 * The image will be centered in the given box.
 * Scaling is determined by either the image's scale attribute,
 * or the imagescale attribute of the graph object being drawn.
 */
static void emit_html_img(GVJ_t * job, htmlimg_t * cp, htmlenv_t * env)
{
    pointf A[4];
    boxf bb = cp->box;
    char *scale;

    bb.LL.x += env->pos.x;
    bb.LL.y += env->pos.y;
    bb.UR.x += env->pos.x;
    bb.UR.y += env->pos.y;

    A[0] = bb.UR;
    A[2] = bb.LL;
    A[1].x = A[2].x;
    A[1].y = A[0].y;
    A[3].x = A[0].x;
    A[3].y = A[2].y;

    if (cp->scale)
	scale = cp->scale;
    else
	scale = env->imgscale;
    assert(cp->src);
    assert(cp->src[0]);
    gvrender_usershape(job, cp->src, A, 4, (!(0)), scale);
}

static void emit_html_cell(GVJ_t * job, htmlcell_t * cp, htmlenv_t * env)
{
    htmlmap_data_t saved;
    boxf pts = cp->data.box;
    pointf pos = env->pos;
    int inAnchor, doAnchor = (cp->data.href || cp->data.target);
    pointf AF[4];

    pts.LL.x += pos.x;
    pts.UR.x += pos.x;
    pts.LL.y += pos.y;
    pts.UR.y += pos.y;

    if (doAnchor && !(job->flags & (1<<2)))
	inAnchor = initAnchor(job, env, &cp->data, pts, &saved, 1);
    else
	inAnchor = 0;

    if (!(cp->data.style & (1 << 5))) {
	if (cp->data.bgcolor) {
	    char *clrs[2];
	    int filled =
		setFill(job, cp->data.bgcolor, cp->data.gradientangle,
			cp->data.style, clrs);
	    if (cp->data.style & (1 << 2)) {
		round_corners(job, mkPts(AF, pts, cp->data.border), 4,
			      (1 << 2), filled);
	    } else
		gvrender_box(job, pts, filled);
	    free(clrs[0]);
	}

	if (cp->data.border)
	    doBorder(job, &cp->data, pts);

	if (cp->child.kind == 1)
	    emit_html_tbl(job, cp->child.u.tbl, env);
	else if (cp->child.kind == 3)
	    emit_html_img(job, cp->child.u.img, env);
	else
	    emit_html_txt(job, cp->child.u.txt, env);
    }

    if (inAnchor)
	endAnchor(job, &saved, 1);

    if (doAnchor && (job->flags & (1<<2))) {
	if (initAnchor(job, env, &cp->data, pts, &saved, 0))
	    endAnchor(job, &saved, 0);
    }
}

/* allocObj:
 * Push new obj on stack to be used in common by all 
 * html elements with anchors.
 * This inherits the type, emit_state, and object of the
 * parent, as well as the url, explicit, target and tooltip.
 */
static void allocObj(GVJ_t * job)
{
    obj_state_t *obj;
    obj_state_t *parent;

    obj = push_obj_state(job);
    parent = obj->parent;
    obj->type = parent->type;
    obj->emit_state = parent->emit_state;
    switch (obj->type) {
    case NODE_OBJTYPE:
	obj->u.n = parent->u.n;
	break;
    case ROOTGRAPH_OBJTYPE:
	obj->u.g = parent->u.g;
	break;
    case CLUSTER_OBJTYPE:
	obj->u.sg = parent->u.sg;
	break;
    case EDGE_OBJTYPE:
	obj->u.e = parent->u.e;
	break;
    }
    obj->url = parent->url;
    obj->tooltip = parent->tooltip;
    obj->target = parent->target;
    obj->explicit_tooltip = parent->explicit_tooltip;
}

static void freeObj(GVJ_t * job)
{
    obj_state_t *obj = job->obj;

    obj->url = NULL;
    obj->tooltip = NULL;
    obj->target = NULL;
    obj->id = NULL;
    pop_obj_state(job);
}

static double
heightOfLbl (htmllabel_t * lp)
{
    double sz = 0.0;

    switch (lp->kind) {
    case 1:
	sz  = lp->u.tbl->data.box.UR.y - lp->u.tbl->data.box.LL.y;
	break;
    case 3:
	sz  = lp->u.img->box.UR.y - lp->u.img->box.LL.y;
	break;
    case 2:
	sz  = lp->u.txt->box.UR.y - lp->u.txt->box.LL.y;
	break;
    }
    return sz;
}

/* emit_html_label:
 */
void emit_html_label(GVJ_t * job, htmllabel_t * lp, textlabel_t * tp)
{
    htmlenv_t env;
    pointf p;

    allocObj(job);

    p = tp->pos;
    switch (tp->valign) {
	case 't':
    	    p.y = tp->pos.y + (tp->space.y - heightOfLbl(lp))/ 2.0 - 1;
	    break;
	case 'b':
    	    p.y = tp->pos.y - (tp->space.y - heightOfLbl(lp))/ 2.0 - 1;
	    break;
	default:	
    	    /* no-op */
	    break;
    }
    env.pos = p;
    env.finfo.color = tp->fontcolor;
    env.finfo.name = tp->fontname;
    env.finfo.size = tp->fontsize;
    env.imgscale = agget(job->obj->u.n, "imagescale");
    env.objid = job->obj->id;
    env.objid_set = 0;
    if ((env.imgscale == NULL) || (env.imgscale[0] == '\0'))
	env.imgscale = "false";
    if (lp->kind == 1) {
	htmltbl_t *tbl = lp->u.tbl;

	/* set basic graphics context */
	/* Need to override line style set by node. */
	gvrender_set_style(job, job->gvc->defaultlinestyle);
	if (tbl->data.pencolor)
	    gvrender_set_pencolor(job, tbl->data.pencolor);
	else
	    gvrender_set_pencolor(job, "black");
	emit_html_tbl(job, tbl, &env);
    } else {
	emit_html_txt(job, lp->u.txt, &env);
    }
    if (env.objid_set)
	free(env.objid);
    freeObj(job);
}

void free_html_data(htmldata_t * dp)
{
    free(dp->href);
    free(dp->port);
    free(dp->target);
    free(dp->id);
    free(dp->title);
    free(dp->bgcolor);
    free(dp->pencolor);
}

void free_html_text(htmltxt_t * t)
{
    htextspan_t *tl;
    textspan_t *ti;
    int i, j;

    if (!t)
	return;

    tl = t->spans;
    for (i = 0; i < t->nspans; i++) {
	ti = tl->items;
	for (j = 0; j < tl->nitems; j++) {
	    if (ti->str)
		free(ti->str);
	    if (ti->layout && ti->free_layout)
		ti->free_layout(ti->layout);
	    ti++;
	}
	tl++;
    }
    if (t->spans)
	free(t->spans);
    free(t);
}

void free_html_img(htmlimg_t * ip)
{
    free(ip->src);
    free(ip);
}

static void free_html_cell(htmlcell_t * cp)
{
    free_html_label(&cp->child, 0);
    free_html_data(&cp->data);
    free(cp);
}

/* free_html_tbl:
 * If tbl->n_rows is negative, table is in initial state from
 * HTML parse, with data stored in u.p. Once run through processTbl,
 * data is stored in u.n and tbl->n_rows is > 0.
 */
static void free_html_tbl(htmltbl_t * tbl)
{
    htmlcell_t **cells;

    if (tbl->rc == -1) {
	dtclose(tbl->u.p.rows);
    } else {
	cells = tbl->u.n.cells;

	free(tbl->heights);
	free(tbl->widths);
	while (*cells) {
	    free_html_cell(*cells);
	    cells++;
	}
	free(tbl->u.n.cells);
    }
    free_html_data(&tbl->data);
    free(tbl);
}

void free_html_label(htmllabel_t * lp, int root)
{
    if (lp->kind == 1)
	free_html_tbl(lp->u.tbl);
    else if (lp->kind == 3)
	free_html_img(lp->u.img);
    else
	free_html_text(lp->u.txt);
    if (root)
	free(lp);
}

static htmldata_t *portToTbl(htmltbl_t *, char *);	/* forward declaration */

static htmldata_t *portToCell(htmlcell_t * cp, char *id)
{
    htmldata_t *rv;

    if (cp->data.port && (strcasecmp(cp->data.port, id) == 0))
	rv = &cp->data;
    else if (cp->child.kind == 1)
	rv = portToTbl(cp->child.u.tbl, id);
    else
	rv = NULL;

    return rv;
}

/* portToTbl:
 * See if tp or any of its child cells has the given port id.
 * If true, return corresponding box.
 */
static htmldata_t *portToTbl(htmltbl_t * tp, char *id)
{
    htmldata_t *rv;
    htmlcell_t **cells;
    htmlcell_t *cp;

    if (tp->data.port && (strcasecmp(tp->data.port, id) == 0))
	rv = &tp->data;
    else {
	rv = NULL;
	cells = tp->u.n.cells;
	while ((cp = *cells++)) {
	    if ((rv = portToCell(cp, id)))
		break;
	}
    }

    return rv;
}

/* html_port:
 * See if edge port corresponds to part of the html node.
 * Assume pname != "".
 * If successful, return pointer to port's box.
 * Else return NULL.
 */
boxf *html_port(node_t * n, char *pname, int *sides)
{
    htmldata_t *tp;
    htmllabel_t *lbl = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label)->u.html;
    boxf *rv = NULL;

    if (lbl->kind == 2)
	return NULL;

    tp = portToTbl(lbl->u.tbl, pname);
    if (tp) {
	rv = &tp->box;
	*sides = tp->sides;
    }
    return rv;

}

/* html_path:
 * Return a box in a table containing the given endpoint.
 * If the top flow is text (no internal structure), return 
 * the box of the flow
 * Else return the box of the subtable containing the point.
 * Because of spacing, the point might not be in any subtable.
 * In that case, return the top flow's box.
 * Note that box[0] must contain the edge point. Additional boxes
 * move out to the boundary.
 *
 * At present, unimplemented, since the label may be inside a
 * non-box node and we need to figure out what this means.
 */
int html_path(node_t * n, port * p, int side, boxf * rv, int *k)
{

    
    
    
    
    

    
    
    
    

    
    
	
	
	    
	
	    
	
	
	    
		
		
	    
    

    
    
	
    
	

    
    
    
	
    
	

    return 0;
}

static int size_html_txt(GVC_t *gvc, htmltxt_t * ftxt, htmlenv_t * env)
{
    double xsize = 0.0;		/* width of text block */
    double ysize = 0.0;		/* height of text block */
    double lsize;		/* height of current line */
    double mxfsize = 0.0;	/* max. font size for the current line */
    double curbline = 0.0;	/* dist. of current base line from top */
    pointf sz;
    int i, j;
    double width;
    textspan_t lp;
    textfont_t tf = {NULL,NULL,NULL,0.0,0,0};
    double maxoffset, mxysize;
    int simple = 1;              /* one item per span, same font size/face, no flags */
    double prev_fsize = -1;
    char* prev_fname = NULL;

    for (i = 0; i < ftxt->nspans; i++) {
	if (ftxt->spans[i].nitems > 1) {
	    simple = 0;
	    break;
	}
	if (ftxt->spans[i].items[0].font) {
	    if (ftxt->spans[i].items[0].font->flags) {
		simple = 0;
		break;
	    }
	    if (ftxt->spans[i].items[0].font->size > 0)
		tf.size = ftxt->spans[i].items[0].font->size;
	    else
		tf.size = env->finfo.size;
	    if (ftxt->spans[i].items[0].font->name)
		tf.name = ftxt->spans[i].items[0].font->name;
	    else
		tf.name = env->finfo.name;
	}
	else {
	    tf.size = env->finfo.size;
	    tf.name = env->finfo.name;
	}
	if (prev_fsize == -1)
	    prev_fsize = tf.size;
	else if (tf.size != prev_fsize) {
	    simple = 0;
	    break;
	}
	if (prev_fname == NULL)
	    prev_fname = tf.name;
	else if (strcmp(tf.name,prev_fname)) {
	    simple = 0;
	    break;
	}
    }
    ftxt->simple = simple;

    for (i = 0; i < ftxt->nspans; i++) {
	width = 0;
	mxysize = maxoffset = mxfsize = 0;
	for (j = 0; j < ftxt->spans[i].nitems; j++) {
	    lp.str =
		strdup_and_subst_obj(ftxt->spans[i].items[j].str,
				     env->obj);
	    if (ftxt->spans[i].items[j].font) {
		if (ftxt->spans[i].items[j].font->flags)
		    tf.flags = ftxt->spans[i].items[j].font->flags;
		else if (env->finfo.flags > 0)
		    tf.flags = env->finfo.flags;
		else
		    tf.flags = 0;
		if (ftxt->spans[i].items[j].font->size > 0)
		    tf.size = ftxt->spans[i].items[j].font->size;
		else
		    tf.size = env->finfo.size;
		if (ftxt->spans[i].items[j].font->name)
		    tf.name = ftxt->spans[i].items[j].font->name;
		else
		    tf.name = env->finfo.name;
		if (ftxt->spans[i].items[j].font->color)
		    tf.color = ftxt->spans[i].items[j].font->color;
		else
		    tf.color = env->finfo.color;
	    } else {
		tf.size = env->finfo.size;
		tf.name = env->finfo.name;
		tf.color = env->finfo.color;
		tf.flags = env->finfo.flags;
	    }
	    lp.font = (*(((Dt_t*)(gvc->textfont_dt))->searchf))((gvc->textfont_dt),(void*)(&tf),0000001);
	    sz = textspan_size(gvc, &lp);
	    free(ftxt->spans[i].items[j].str);
	    ftxt->spans[i].items[j].str = lp.str;
	    ftxt->spans[i].items[j].size.x = sz.x;
	    ftxt->spans[i].items[j].yoffset_layout = lp.yoffset_layout;
	    ftxt->spans[i].items[j].yoffset_centerline = lp.yoffset_centerline;
            ftxt->spans[i].items[j].font = lp.font;
	    ftxt->spans[i].items[j].layout = lp.layout;
	    ftxt->spans[i].items[j].free_layout = lp.free_layout;
	    width += sz.x;
	    mxfsize = ((tf.size)>(mxfsize)?(tf.size):(mxfsize));
	    mxysize = ((sz.y)>(mxysize)?(sz.y):(mxysize));
	    maxoffset = ((lp.yoffset_centerline)>(maxoffset)?(lp.yoffset_centerline):(maxoffset));
	}
	/* lsize = mxfsize * LINESPACING; */
	ftxt->spans[i].size = width;
	/* ysize - curbline is the distance from the previous
	 * baseline to the bottom of the previous line.
	 * Then, in the current line, we set the baseline to
	 * be 5/6 of the max. font size. Thus, lfsize gives the
	 * distance from the previous baseline to the new one.
	 */
	/* ftxt->spans[i].lfsize = 5*mxfsize/6 + ysize - curbline; */
	if (simple) {
	    lsize = mxysize;
	    if (i == 0)
		ftxt->spans[i].lfsize = mxfsize;
	    else
		ftxt->spans[i].lfsize = mxysize;
	}
	else {
	    lsize = mxfsize;
	    if (i == 0)
		ftxt->spans[i].lfsize = mxfsize - maxoffset;
	    else
		ftxt->spans[i].lfsize = mxfsize + ysize - curbline - maxoffset;
	}
	curbline += ftxt->spans[i].lfsize;
	xsize = ((width)>(xsize)?(width):(xsize));
	ysize += lsize;
    }
    ftxt->box.UR.x = xsize;
    if (ftxt->nspans == 1)
	ftxt->box.UR.y = mxysize;
    else
	ftxt->box.UR.y = ysize;
    return 0;
}

/* forward declarion for recursive usage */
static int size_html_tbl(graph_t * g, htmltbl_t * tbl, htmlcell_t * parent,
			 htmlenv_t * env);

/* size_html_img:
 */
static int size_html_img(htmlimg_t * img, htmlenv_t * env)
{
    box b;
    int rv;

    b.LL.x = b.LL.y = 0;
    b.UR = gvusershape_size(env->g, img->src);
    if ((b.UR.x == -1) && (b.UR.y == -1)) {
	rv = 1;
	b.UR.x = b.UR.y = 0;
	agerr(AGERR, "No or improper image file=\"%s\"\n", img->src);
    } else {
	rv = 0;
	(((Agraphinfo_t*)(((Agobj_t*)(env->g))->data))->has_images) = (!(0));
    }

    ((((img->box).LL).x = ((b).LL).x,((img->box).LL).y = ((b).LL).y),(((img->box).UR).x = ((b).UR).x,((img->box).UR).y = ((b).UR).y));
    return rv;
}

/* size_html_cell:
 */
static int
size_html_cell(graph_t * g, htmlcell_t * cp, htmltbl_t * parent,
	       htmlenv_t * env)
{
    int rv;
    pointf sz, child_sz;
    int margin;

    cp->parent = parent;
    if (!(cp->data.flags & (1 << 6))) {
	if (parent->data.flags & (1 << 6))
	    cp->data.pad = parent->data.pad;
	else
	    cp->data.pad = 2;
    }
    if (!(cp->data.flags & (1 << 5))) {
	if (parent->cb >= 0)
	    cp->data.border = parent->cb;
	else if (parent->data.flags & (1 << 5))
	    cp->data.border = parent->data.border;
	else
	    cp->data.border = 1;
    }

    if (cp->child.kind == 1) {
	rv = size_html_tbl(g, cp->child.u.tbl, cp, env);
	child_sz = cp->child.u.tbl->data.box.UR;
    } else if (cp->child.kind == 3) {
	rv = size_html_img(cp->child.u.img, env);
	child_sz = cp->child.u.img->box.UR;
    } else {
	rv = size_html_txt((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->gvc), cp->child.u.txt, env);
	child_sz = cp->child.u.txt->box.UR;
    }

    margin = 2 * (cp->data.pad + cp->data.border);
    sz.x = child_sz.x + margin;
    sz.y = child_sz.y + margin;

    if (cp->data.flags & 1) {
	if (cp->data.width && cp->data.height) {
	    if (((cp->data.width < sz.x) || (cp->data.height < sz.y)) && (cp->child.kind != 3)) {
		agerr(AGWARN, "cell size too small for content\n");
		rv = 1;
	    }
	    sz.x = sz.y = 0;

	} else {
	    agerr(AGWARN,
		  "fixed cell size with unspecified width or height\n");
	    rv = 1;
	}
    }
    cp->data.box.UR.x = ((sz.x)>(cp->data.width)?(sz.x):(cp->data.width));
    cp->data.box.UR.y = ((sz.y)>(cp->data.height)?(sz.y):(cp->data.height));
    return rv;
}

static int findCol(PointSet * ps, int row, int col, htmlcell_t * cellp)
{
    int notFound = 1;
    int lastc;
    int i, j, c;
    int end = cellp->cspan - 1;

    while (notFound) {
	lastc = col + end;
	for (c = lastc; c >= col; c--) {
	    if (isInPS(ps, c, row))
		break;
	}
	if (c >= col)		/* conflict : try column after */
	    col = c + 1;
	else
	    notFound = 0;
    }
    for (j = col; j < col + cellp->cspan; j++) {
	for (i = row; i < row + cellp->rspan; i++) {
	    addPS(ps, j, i);
	}
    }
    return col;
}

/* processTbl:
 * Convert parser representation of cells into final form.
 * Find column and row positions of cells.
 * Recursively size cells.
 * Return 1 if problem sizing a cell.
 */
static int processTbl(graph_t * g, htmltbl_t * tbl, htmlenv_t * env)
{
    pitem *rp;
    pitem *cp;
    Dt_t *cdict;
    int r, c, cnt;
    htmlcell_t *cellp;
    htmlcell_t **cells;
    Dt_t *rows = tbl->u.p.rows;
    int rv = 0;
    int n_rows = 0;
    int n_cols = 0;
    PointSet *ps = newPS();
    Dt_t *is = openIntSet();

    rp = (pitem *) dtflatten(rows);
    cnt = 0;
    r = 0;
    while (rp) {
	cdict = rp->u.rp;
	cp = (pitem *) dtflatten(cdict);
	while (cp) {
	    cellp = cp->u.cp;
	    cnt++;
	    cp = (pitem *) (((Dtlink_t*)((Dtlink_t *) cp))->right);
	}
	if (rp->ruled) {
	    addIntSet(is, r + 1);
	}
	rp = (pitem *) (((Dtlink_t*)((Dtlink_t *) rp))->right);
	r++;
    }

    cells = tbl->u.n.cells = (htmlcell_t **)zmalloc((cnt + 1)*sizeof(htmlcell_t *));
    rp = (pitem *) dtflatten(rows);
    r = 0;
    while (rp) {
	cdict = rp->u.rp;
	cp = (pitem *) dtflatten(cdict);
	c = 0;
	while (cp) {
	    cellp = cp->u.cp;
	    *cells++ = cellp;
	    rv |= size_html_cell(g, cellp, tbl, env);
	    c = findCol(ps, r, c, cellp);
	    cellp->row = r;
	    cellp->col = c;
	    c += cellp->cspan;
	    n_cols = ((c)>(n_cols)?(c):(n_cols));
	    n_rows = ((r + cellp->rspan)>(n_rows)?(r + cellp->rspan):(n_rows));
	    if (inIntSet(is, r + cellp->rspan))
		cellp->ruled |= 2;
	    cp = (pitem *) (((Dtlink_t*)((Dtlink_t *) cp))->right);
	}
	rp = (pitem *) (((Dtlink_t*)((Dtlink_t *) rp))->right);
	r++;
    }
    tbl->rc = n_rows;
    tbl->cc = n_cols;
    dtclose(rows);
    dtclose(is);
    freePS(ps);
    return rv;
}

/* Split size x over n pieces with spacing s.
 * We substract s*(n-1) from x, divide by n and 
 * take the ceiling.
 */


/* sizeLinearArray:
 * Determine sizes of rows and columns. The size of a column is the
 * maximum width of any cell in it. Similarly for rows.
 * A cell spanning columns contributes proportionately to each column
 * it is in.
 */
void sizeLinearArray(htmltbl_t * tbl)
{
    htmlcell_t *cp;
    htmlcell_t **cells;
    int wd, ht, i, x, y;

    tbl->heights = (int*)zmalloc((tbl->rc + 1)*sizeof(int));
    tbl->widths = (int*)zmalloc((tbl->cc + 1)*sizeof(int));

    for (cells = tbl->u.n.cells; *cells; cells++) {
	cp = *cells;
	if (cp->rspan == 1)
	    ht = cp->data.box.UR.y;
	else {
	    ht = (((cp->data.box.UR.y) - ((tbl->data.space)-1)*((cp->rspan)-1)) / (cp->rspan));
	    ht = ((ht)>(1)?(ht):(1));
	}
	if (cp->cspan == 1)
	    wd = cp->data.box.UR.x;
	else {
	    wd = (((cp->data.box.UR.x) - ((tbl->data.space)-1)*((cp->cspan)-1)) / (cp->cspan));
	    wd = ((wd)>(1)?(wd):(1));
	}
	for (i = cp->row; i < cp->row + cp->rspan; i++) {
	    y = tbl->heights[i];
	    tbl->heights[i] = ((y)>(ht)?(y):(ht));
	}
	for (i = cp->col; i < cp->col + cp->cspan; i++) {
	    x = tbl->widths[i];
	    tbl->widths[i] = ((x)>(wd)?(x):(wd));
	}
    }
}

static char *nnames[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
};

/* nToName:
 * Convert int to its decimal string representation.
 */
char *nToName(int c)
{
    static char name[100];

    if (c < sizeof(nnames) / sizeof(char *))
	return nnames[c];

    sprintf(name, "%d", c);
    return name;
}

/* closeGraphs:
 * Clean up graphs made for setting column and row widths.
 */
static void closeGraphs(graph_t * rowg, graph_t * colg)
{
    node_t *n;
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(colg))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	do {if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list) free((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list);} while (0);
	do {if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list) free((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list);} while (0);
    }

    agclose(rowg);
    agclose(colg);
}

/* checkChain:
 * For each pair of nodes in the node list, add an edge if none exists.
 * Assumes node list has nodes ordered correctly.
 */
static void checkChain(graph_t * g)
{
    node_t *t;
    node_t *h;
    edge_t *e;
    t = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist);
    for (h = (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->next); h; h = (((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->next)) {
	if (!(agedge(g,t,h,NULL,0))) {
	    e = agedge(g, t, h, NULL, 1);
	    agbindrec(e, "Agedgeinfo_t", sizeof(Agedgeinfo_t), (!(0)));
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = 0;
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list = ((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list,((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size] = NULL;} while(0);
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list = ((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list,((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size] = NULL;} while(0);
	}
	t = h;
    }
}

/* checkEdge:
 * Check for edge in g. If it exists, set its minlen to max of sz and
 * current minlen. Else, create it and set minlen to sz.
 */
static void
checkEdge (graph_t* g, node_t* t, node_t* h, int sz)
{
    edge_t* e;

    e = (agedge(g,t,h,NULL,0));
    if (e)
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen))>(sz)?((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen)):(sz));
    else {
	e = agedge(g, t, h, NULL, 1);
	agbindrec(e, "Agedgeinfo_t", sizeof(Agedgeinfo_t), (!(0)));
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->minlen) = sz;
	do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list = ((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list,((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list[(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size] = NULL;} while(0);
	do {(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list = ((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list,((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).list[(((Agnodeinfo_t*)(((Agobj_t*)(h))->data))->in).size] = NULL;} while(0);
    }
}

/* makeGraphs:
 * Generate dags modeling the row and column constraints.
 * If the table has cc columns, we create the graph
 *  0 -> 1 -> 2 -> ... -> cc
 * and if a cell starts in column c with span cspan, with
 * width w, we add the edge c -> c+cspan [minlen = w].
 * Ditto for rows.
 *
 */
void makeGraphs(htmltbl_t * tbl, graph_t * rowg, graph_t * colg)
{
    htmlcell_t *cp;
    htmlcell_t **cells;
    node_t *t;
    node_t *lastn;
    node_t *h;
    int i;

    lastn = NULL;
    for (i = 0; i <= tbl->cc; i++) {
	t = agnode(colg, nToName(i), 1);
	agbindrec(t, "Agnodeinfo_t", sizeof(Agnodeinfo_t), (!(0)));
	do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->in).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->in).list = (edge_t**)zmalloc((tbl->rc + 1)*sizeof(edge_t*)); } while (0);
	do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list = (edge_t**)zmalloc((tbl->rc + 1)*sizeof(edge_t*)); } while (0);
	if (lastn) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(lastn))->data))->next) = t;
	    lastn = t;
	} else {
	    lastn = (((Agraphinfo_t*)(((Agobj_t*)(colg))->data))->nlist) = t;
	}
    }
    lastn = NULL;
    for (i = 0; i <= tbl->rc; i++) {
	t = agnode(rowg, nToName(i), 1);
	agbindrec(t, "Agnodeinfo_t", sizeof(Agnodeinfo_t), (!(0)));
	do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->in).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->in).list = (edge_t**)zmalloc((tbl->cc + 1)*sizeof(edge_t*)); } while (0);
	do {(((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(t))->data))->out).list = (edge_t**)zmalloc((tbl->cc + 1)*sizeof(edge_t*)); } while (0);
	if (lastn) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(lastn))->data))->next) = t;
	    lastn = t;
	} else {
	    lastn = (((Agraphinfo_t*)(((Agobj_t*)(rowg))->data))->nlist) = t;
	}
    }

    for (cells = tbl->u.n.cells; *cells; cells++) {
	cp = *cells;
	t = (agnode(colg,nToName(cp->col),0));
	h = (agnode(colg,nToName(cp->col + cp->cspan),0));
	checkEdge (colg, t, h, cp->data.box.UR.x);

	t = (agnode(rowg,nToName(cp->row),0));
	h = (agnode(rowg,nToName(cp->row + cp->rspan),0));
	checkEdge (rowg, t, h, cp->data.box.UR.y);
    }

    /* Make sure that 0 <= 1 <= 2 ...k. This implies graph connected. */
    checkChain(colg);
    checkChain(rowg);
}

/* setSizes:
 * Use rankings to determine cell dimensions. The rank values
 * give the coordinate, so to get the width/height, we have
 * to subtract the previous value.
 */
void setSizes(htmltbl_t * tbl, graph_t * rowg, graph_t * colg)
{
    int i;
    node_t *n;
    int prev;

    prev = 0;
    n = (((Agraphinfo_t*)(((Agobj_t*)(rowg))->data))->nlist);
    for (i = 0, n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next); n; i++, n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	tbl->heights[i] = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) - prev;
	prev = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
    }
    prev = 0;
    n = (((Agraphinfo_t*)(((Agobj_t*)(colg))->data))->nlist);
    for (i = 0, n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next); n; i++, n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	tbl->widths[i] = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) - prev;
	prev = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
    }

}

/* sizeArray:
 * Set column and row sizes. Optimize for minimum width and
 * height. Where there is slack, try to distribute evenly.
 * We do this by encoding cells as edges with min length is
 * a dag on a chain. We then run network simplex, using
 * LR_balance.
 */
void sizeArray(htmltbl_t * tbl)
{
    graph_t *rowg;
    graph_t *colg;

    

    Agdesc_t dir = Agstrictdirected;


    /* Do the 1D cases by hand */
    if ((tbl->rc == 1) || (tbl->cc == 1)) {
	sizeLinearArray(tbl);
	return;
    }

    tbl->heights = (int*)zmalloc((tbl->rc + 1)*sizeof(int));
    tbl->widths = (int*)zmalloc((tbl->cc + 1)*sizeof(int));

    rowg = agopen("rowg", dir, ((Agdisc_t *)0));
    colg = agopen("colg", dir, ((Agdisc_t *)0));
    /* Only need GD_nlist */
    agbindrec(rowg, "Agraphinfo_t", sizeof(Agraphinfo_t), (!(0)));	// graph custom data
    agbindrec(colg, "Agraphinfo_t", sizeof(Agraphinfo_t), (!(0)));	// graph custom data
    makeGraphs(tbl, rowg, colg);
    rank(rowg, 2, ((int)(~(unsigned)0 >> 1)));
    rank(colg, 2, ((int)(~(unsigned)0 >> 1)));
    setSizes(tbl, rowg, colg);
    closeGraphs(rowg, colg);
}

static void pos_html_tbl(htmltbl_t *, boxf, int);	/* forward declaration */

/* pos_html_img:
 * Place image in cell
 * storing allowed space handed by parent cell.
 * How this space is used is handled in emit_html_img.
 */
static void pos_html_img(htmlimg_t * cp, boxf pos)
{
    cp->box = pos;
}

/* pos_html_txt:
 * Set default alignment.
 */
static void pos_html_txt(htmltxt_t * ftxt, char c)
{
    int i;

    for (i = 0; i < ftxt->nspans; i++) {
	if (ftxt->spans[i].just == 0)	/* unset */
	    ftxt->spans[i].just = c;
    }
}

/* pos_html_cell:
 */
static void pos_html_cell(htmlcell_t * cp, boxf pos, int sides)
{
    double delx, dely;
    pointf oldsz;
    boxf cbox;

    if (!cp->data.pencolor && cp->parent->data.pencolor)
	cp->data.pencolor = strdup(cp->parent->data.pencolor);

    /* If fixed, align cell */
    if (cp->data.flags & 1) {
	oldsz = cp->data.box.UR;
	delx = (pos.UR.x - pos.LL.x) - oldsz.x;
	if (delx > 0) {
	    switch (cp->data.flags & ((1 << 1) | (1 << 2))) {
	    case (1 << 2):
		pos.UR.x = pos.LL.x + oldsz.x;
		break;
	    case (1 << 1):
		pos.UR.x += delx;
		pos.LL.x += delx;
		break;
	    default:
		pos.LL.x += delx / 2;
		pos.UR.x -= delx / 2;
		break;
	    }
	}
	dely = (pos.UR.y - pos.LL.y) - oldsz.y;
	if (dely > 0) {
	    switch (cp->data.flags & ((1 << 3) | (1 << 4))) {
	    case (1 << 4):
		pos.UR.y = pos.LL.y + oldsz.y;
		break;
	    case (1 << 3):
		pos.UR.y += dely;
		pos.LL.y += dely;
		break;
	    default:
		pos.LL.y += dely / 2;
		pos.UR.y -= dely / 2;
		break;
	    }
	}
    }
    cp->data.box = pos;
    cp->data.sides = sides;

    /* set up child's position */
    cbox.LL.x = pos.LL.x + cp->data.border + cp->data.pad;
    cbox.LL.y = pos.LL.y + cp->data.border + cp->data.pad;
    cbox.UR.x = pos.UR.x - cp->data.border - cp->data.pad;
    cbox.UR.y = pos.UR.y - cp->data.border - cp->data.pad;

    if (cp->child.kind == 1) {
	pos_html_tbl(cp->child.u.tbl, cbox, sides);
    } else if (cp->child.kind == 3) {
	/* Note that alignment trumps scaling */
	oldsz = cp->child.u.img->box.UR;
	delx = (cbox.UR.x - cbox.LL.x) - oldsz.x;
	if (delx > 0) {
	    switch (cp->data.flags & ((1 << 1) | (1 << 2))) {
	    case (1 << 2):
		cbox.UR.x -= delx;
		break;
	    case (1 << 1):
		cbox.LL.x += delx;
		break;
	    }
	}

	dely = (cbox.UR.y - cbox.LL.y) - oldsz.y;
	if (dely > 0) {
	    switch (cp->data.flags & ((1 << 3) | (1 << 4))) {
	    case (1 << 4):
		cbox.UR.y -= dely;
		break;
	    case (1 << 3):
		cbox.LL.y += dely;
		break;
	    }
	}
	pos_html_img(cp->child.u.img, cbox);
    } else {
	char dfltalign;
	int af;

	oldsz = cp->child.u.txt->box.UR;
	delx = (cbox.UR.x - cbox.LL.x) - oldsz.x;
	/* If the cell is larger than the text block and alignment is 
	 * done at textblock level, the text box is shrunk accordingly. 
	 */
	if ((delx > 0)
	    && ((af = (cp->data.flags & ((1 << 1) | (1 << 2)))) != ((1 << 1) | (1 << 2)))) {
	    switch (af) {
	    case (1 << 2):
		cbox.UR.x -= delx;
		break;
	    case (1 << 1):
		cbox.LL.x += delx;
		break;
	    default:
		cbox.LL.x += delx / 2;
		cbox.UR.x -= delx / 2;
		break;
	    }
	}

	dely = (cbox.UR.y - cbox.LL.y) - oldsz.y;
	if (dely > 0) {
	    switch (cp->data.flags & ((1 << 3) | (1 << 4))) {
	    case (1 << 4):
		cbox.UR.y -= dely;
		break;
	    case (1 << 3):
		cbox.LL.y += dely;
		break;
	    default:
		cbox.LL.y += dely / 2;
		cbox.UR.y -= dely / 2;
		break;
	    }
	}
	cp->child.u.txt->box = cbox;

	/* Set default text alignment
	 */
	switch (cp->data.flags & ((1 << 8) | (1 << 9))) {
	case (1 << 9):
	    dfltalign = 'l';
	    break;
	case (1 << 8):
	    dfltalign = 'r';
	    break;
	default:
	    dfltalign = 'n';
	    break;
	}
	pos_html_txt(cp->child.u.txt, dfltalign);
    }
}

/* pos_html_tbl:
 * Position table given its box, then calculate
 * the position of each cell. In addition, set the sides
 * attribute indicating which external sides of the node
 * are accessible to the table.
 */
static void pos_html_tbl(htmltbl_t * tbl, boxf pos, int sides)
{
    int x, y, delx, dely, oldsz;
    int i, extra, plus;
    htmlcell_t **cells = tbl->u.n.cells;
    htmlcell_t *cp;
    boxf cbox;

    if (tbl->u.n.parent && tbl->u.n.parent->data.pencolor
	&& !tbl->data.pencolor)
	tbl->data.pencolor = strdup(tbl->u.n.parent->data.pencolor);

    oldsz = tbl->data.box.UR.x;
    delx = (pos.UR.x - pos.LL.x) - oldsz;
    assert(delx >= 0);
    oldsz = tbl->data.box.UR.y;
    dely = (pos.UR.y - pos.LL.y) - oldsz;
    assert(dely >= 0);

    /* If fixed, align box */
    if (tbl->data.flags & 1) {
	if (delx > 0) {
	    switch (tbl->data.flags & ((1 << 1) | (1 << 2))) {
	    case (1 << 2):
		pos.UR.x = pos.LL.x + oldsz;
		break;
	    case (1 << 1):
		pos.UR.x += delx;
		pos.LL.x += delx;
		break;
	    default:
		pos.LL.x += delx / 2;
		pos.UR.x -= delx / 2;
		break;
	    }
	    delx = 0;
	}
	if (dely > 0) {
	    switch (tbl->data.flags & ((1 << 3) | (1 << 4))) {
	    case (1 << 4):
		pos.UR.y = pos.LL.y + oldsz;
		break;
	    case (1 << 3):
		pos.UR.y += dely;
		pos.LL.y += dely;
		break;
	    default:
		pos.LL.y += dely / 2;
		pos.UR.y -= dely / 2;
		break;
	    }
	    dely = 0;
	}
    }

    /* change sizes to start positions and distribute extra space */
    x = pos.LL.x + tbl->data.border + tbl->data.space;
    extra = delx / (tbl->cc);
    plus = ((delx - extra *(tbl->cc)>=0)?(int)(delx - extra *(tbl->cc) + .5):(int)(delx - extra *(tbl->cc) - .5));
    for (i = 0; i <= tbl->cc; i++) {
	delx = tbl->widths[i] + extra + (i < plus ? 1 : 0);
	tbl->widths[i] = x;
	x += delx + tbl->data.space;
    }
    y = pos.UR.y - tbl->data.border - tbl->data.space;
    extra = dely / (tbl->rc);
    plus = ((dely - extra *(tbl->rc)>=0)?(int)(dely - extra *(tbl->rc) + .5):(int)(dely - extra *(tbl->rc) - .5));
    for (i = 0; i <= tbl->rc; i++) {
	dely = tbl->heights[i] + extra + (i < plus ? 1 : 0);
	tbl->heights[i] = y;
	y -= dely + tbl->data.space;
    }

    while ((cp = *cells++)) {
	int mask = 0;
	if (sides) {
	    if (cp->col == 0)
		mask |= (1<<3);
	    if (cp->row == 0)
		mask |= (1<<2);
	    if (cp->col + cp->cspan == tbl->cc)
		mask |= (1<<1);
	    if (cp->row + cp->rspan == tbl->rc)
		mask |= (1<<0);
	}
	cbox.LL.x = tbl->widths[cp->col];
	cbox.UR.x = tbl->widths[cp->col + cp->cspan] - tbl->data.space;
	cbox.UR.y = tbl->heights[cp->row];
	cbox.LL.y = tbl->heights[cp->row + cp->rspan] + tbl->data.space;
	pos_html_cell(cp, cbox, sides & mask);
    }

    tbl->data.sides = sides;
    tbl->data.box = pos;
}

/* size_html_tbl:
 * Determine the size of a table by first determining the
 * size of each cell.
 */
static int
size_html_tbl(graph_t * g, htmltbl_t * tbl, htmlcell_t * parent,
	      htmlenv_t * env)
{
    int i, wd, ht;
    int rv = 0;
    static textfont_t savef;

    if (tbl->font)
	pushFontInfo(env, tbl->font, &savef);
    tbl->u.n.parent = parent;
    rv = processTbl(g, tbl, env);

    /* Set up border and spacing */
    if (!(tbl->data.flags & (1 << 7))) {
	tbl->data.space = 2;
    }
    if (!(tbl->data.flags & (1 << 5))) {
	tbl->data.border = 1;
    }

    sizeArray(tbl);

    wd = (tbl->cc + 1) * tbl->data.space + 2 * tbl->data.border;
    ht = (tbl->rc + 1) * tbl->data.space + 2 * tbl->data.border;
    for (i = 0; i < tbl->cc; i++)
	wd += tbl->widths[i];
    for (i = 0; i < tbl->rc; i++)
	ht += tbl->heights[i];

    if (tbl->data.flags & 1) {
	if (tbl->data.width && tbl->data.height) {
	    if ((tbl->data.width < wd) || (tbl->data.height < ht)) {
		agerr(AGWARN, "table size too small for content\n");
		rv = 1;
	    }
	    wd = ht = 0;
	} else {
	    agerr(AGWARN,
		  "fixed table size with unspecified width or height\n");
	    rv = 1;
	}
    }
    tbl->data.box.UR.x = ((wd)>(tbl->data.width)?(wd):(tbl->data.width));
    tbl->data.box.UR.y = ((ht)>(tbl->data.height)?(ht):(tbl->data.height));

    if (tbl->font)
	popFontInfo(env, &savef);
    return rv;
}

static char *nameOf(void *obj, agxbuf * xb)
{
    Agedge_t *ep;
    switch (agobjkind(obj)) {
    case 0:
	agxbput(xb, agnameof(((Agraph_t *) obj)));
	break;
    case 1:
	agxbput(xb, agnameof(((Agnode_t *) obj)));
	break;
    case 2:
	ep = (Agedge_t *) obj;
	agxbput(xb, agnameof(((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node)));
	agxbput(xb, agnameof(((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node)));
	if (agisdirected(agraphof(((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node))))
	    agxbput(xb, "->");
	else
	    agxbput(xb, "--");
	break;
    }
    return (((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'\0'))),(char*)((xb)->ptr = (xb)->buf));
}




    
	




    




    
    




    

    
    
    
	
	
	
	    
	    
		    
		    
	    
		
			
			
			
	    
		
	
    




    
    

    
    
    
    
    
	
	
    
	
	
    
	
	
    
    
    
    
	
	
    
	
	
    
	
	
    
    
    




    
    
    
    
    
    
	




    
    
	    
    
    
    
    
	
	
    
	
	
    
	
	
    
	
    




    
	
    
	



static char *getPenColor(void *obj)
{
    char *str;

    if (((str = agget(obj, "pencolor")) != 0) && str[0])
	return str;
    else if (((str = agget(obj, "color")) != 0) && str[0])
	return str;
    else
	return NULL;
}

/* make_html_label:
 * Return non-zero if problem parsing HTML. In this case, use object name.
 */
int make_html_label(void *obj, textlabel_t * lp)
{
    int rv;
    double wd2, ht2;
    boxf box;
    graph_t *g;
    htmllabel_t *lbl;
    htmlenv_t env;
    char *s;

    env.obj = obj;
    switch (agobjkind(obj)) {
    case 0:
	env.g = ((Agraph_t *) obj)->root;
	break;
    case 1:
	env.g = agraphof(((Agnode_t *) obj));
	break;
    case 2:
	env.g = agraphof(((((((Agobj_t*)(((Agedge_t *) obj)))->tag).objtype) == 2? (((Agedge_t *) obj)): ((((Agedge_t *) obj))-1))->node));
	break;
    }
    g = env.g->root;

    env.finfo.size = lp->fontsize;
    env.finfo.name = lp->fontname;
    env.finfo.color = lp->fontcolor;
    env.finfo.flags = 0;
    lbl = parseHTML(lp->text, &rv, &env);
    if (!lbl) {
	/* Parse of label failed; revert to simple text label */
	agxbuf xb;
	unsigned char buf[128];
	agxbinit(&xb, 128, buf);
	lp->html = 0;
	lp->text = strdup(nameOf(obj, &xb));
	switch (lp->charset) {
	case 1:
	    s = latin1ToUTF8(lp->text);
	    break;
	default:		/* UTF8 */
	    s = htmlEntityUTF8(lp->text, env.g);
	    break;
	}
	free(lp->text);
	lp->text = s;
	make_simple_label((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->gvc), lp);
	agxbfree(&xb);
	return rv;
    }

    if (lbl->kind == 1) {
	if (!lbl->u.tbl->data.pencolor && getPenColor(obj))
	    lbl->u.tbl->data.pencolor = strdup(getPenColor(obj));
	rv |= size_html_tbl(g, lbl->u.tbl, NULL, &env);
	wd2 = (lbl->u.tbl->data.box.UR.x) / 2;
	ht2 = (lbl->u.tbl->data.box.UR.y) / 2;
	box = boxfof(-wd2, -ht2, wd2, ht2);
	pos_html_tbl(lbl->u.tbl, box, (1<<0) | (1<<1) | (1<<2) | (1<<3));
	lp->dimen.x = box.UR.x - box.LL.x;
	lp->dimen.y = box.UR.y - box.LL.y;
    } else {
	rv |= size_html_txt((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->gvc), lbl->u.txt, &env);
	wd2 = lbl->u.txt->box.UR.x  / 2;
	ht2 = lbl->u.txt->box.UR.y  / 2;
	box = boxfof(-wd2, -ht2, wd2, ht2);
	lbl->u.txt->box = box;
	lp->dimen.x = box.UR.x - box.LL.x;
	lp->dimen.y = box.UR.y - box.LL.y;
    }

    lp->u.html = lbl;

    /* If the label is a table, replace label text because this may
     * be used for the title and alt fields in image maps.
     */
    if (lbl->kind == 1) {
	free(lp->text);
	lp->text = strdup("<TABLE>");
    }

    return rv;
}
