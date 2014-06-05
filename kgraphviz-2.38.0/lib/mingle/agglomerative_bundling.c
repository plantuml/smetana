#line 1 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 1
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





#line 13 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
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











#line 14 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
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





#line 15 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 1
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


























#line 17 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\vector.h" 1
/* $Id$Revision: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/



#line 1 "graphviz-2.38.0\\lib\\sparse\\vector.h" 1
struct vector_struct {
  int maxlen;
  int len;
  void *v;
  size_t size_of_elem;
  void (*deallocator)(void *v);
};

typedef struct vector_struct *Vector;

/* deallocator works on each element of the vector */
Vector Vector_new(int maxlen, size_t size_of_elem, void (*deallocator)(void *v));

Vector Vector_add(Vector v, void *stuff);

Vector Vector_reset(Vector v, void *stuff, int i);

void Vector_delete(Vector v);

void* Vector_get(Vector v, int i);

int Vector_get_length(Vector v);

Vector Vector_reset(Vector v, void *stuff, int i);

/*------------- vector of strings ----------- */

typedef Vector StringVector;

Vector StringVector_new(int len, int delete_element_strings);
Vector StringVector_add(Vector v, char *i);
void StringVector_delete(Vector v);
char** StringVector_get(Vector v, int i);
int StringVector_get_length(Vector v);
Vector StringVector_reset(Vector v, char *content, int pos);
void StringVector_fprint(FILE *fp, StringVector v);
void StringVector_fprint1(FILE *fp, StringVector v);
StringVector StringVector_part(StringVector v, int n, int *selected_list);
/*------------- integer vector ----------- */

typedef Vector IntegerVector;

Vector IntegerVector_new(int len);
Vector IntegerVector_add(Vector v, int i);
void IntegerVector_delete(Vector v);
int* IntegerVector_get(Vector v, int i);
int IntegerVector_get_length(Vector v);
Vector IntegerVector_reset(Vector v, int content, int pos);




#line 18 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\mingle\\edge_bundling.h" 1
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














  
  
  
  
  
  
  
  
  
  
  





































































































			  


				










































#line 13 "graphviz-2.38.0\\lib\\mingle\\edge_bundling.h" 2

struct pedge_struct {
  double wgt; /* weight, telling how many original edges this edge represent. If this edge consists of multiple sections of different weights then this is a lower bound. This only applied for agglomerative bundling */
  int npoints;/* number of poly points */
  int len;/* length of arra x. len >= npoints */
  int dim;/* dim >= 2. Point i is stored from x[i*dim]*/
  double edge_length;
  double *x;/* coordinates of the npoints poly points. Dimension dim*npoints */
  double *wgts;/* number of original edges each section represnet. Dimension npoint - 1. This only applied for agglomerative bundling Null for other methods */
};

typedef struct pedge_struct* pedge;

pedge* edge_bundling(SparseMatrix A, int dim, double *x, int maxit_outer, double K, int method, int nneighbor, int compatibility_method, int max_recursion, double angle_param, double angle, int open_gl);
void pedge_delete(pedge e);
pedge pedge_realloc(pedge e, int np);
pedge pedge_wgts_realloc(pedge e, int n);
void pedge_export_mma(FILE *fp, int ne, pedge *edges);
void pedge_export_gv(FILE *fp, int ne, pedge *edges);
enum {METHOD_NONE = -1, METHOD_FD, METHOD_INK_AGGLOMERATE, METHOD_INK};
enum {COMPATIBILITY_DIST = 0, COMPATIBILITY_FULL};
pedge pedge_new(int np, int dim, double *x);
pedge pedge_wgt_new(int np, int dim, double *x, double wgt);
pedge pedge_double(pedge e);

/* flip the polyline so that last point becomes the first, second last the second, etc*/
pedge pedge_flip(pedge e);





#line 19 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\mingle\\ink.h" 1
/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\mingle\\edge_bundling.h" 1
/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/






  
  
  
  
  
  
  























#line 14 "graphviz-2.38.0\\lib\\mingle\\ink.h" 2

typedef struct {
  double x, y;
} point_t;

/* given a list of edges, find the best ink bundling by making them meet at 2 points
   \                       /
   -meet1 ---------- meet2 - 
   /                          edges: list of edges

   numEdges: number of edges
   pick: if not NULL, consider edges pick[0], pick[1], ..., pick[numedges-1],
   .     othetwise consider edges 0, 1, ..., numEdge-1
   ink0: ink needed if no bundling
   meet1, meet2: meeting point
   return: best ink needed if bundled.
*/
double ink(pedge* edges, int numEdges, int *pick, double *ink0, point_t *meet1, point_t *meet2, double angle_param, double angle);
double ink1(pedge e);

extern double ink_count;


#line 20 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.h" 1
/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




typedef struct Agglomerative_Ink_Bundling_struct *Agglomerative_Ink_Bundling;

struct Agglomerative_Ink_Bundling_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A; /* n x n matrix, where n is the number of edges/bundles in this level */
  SparseMatrix P; /* prolongation matrix from level + 1 to level */
  SparseMatrix R0;/* this is basically R[level - 1].R[level - 2]...R[0], which gives the map of bundling i to the original edges: first row of R0 gives
		     the nodes on the finest grid corresponding to the coarsest node 1, etc */
  SparseMatrix R;/* striction mtrix from level to level + 1*/
  Agglomerative_Ink_Bundling next;
  Agglomerative_Ink_Bundling prev;
  double *inks; /* amount of ink needed to draw this edge/bundle. Dimension n. */
  double total_ink; /* amount of ink needed to draw this edge/bundle. Dimension n. */
  pedge* edges; /* the original edge info. This does not vary level to level and is of dimenion n0, where n0 is the number of original edges */
  int delete_top_level_A;/*whether the top level matrix should be deleted on garbage collecting the grid */
};

pedge* agglomerative_ink_bundling(int dim, SparseMatrix A, pedge* edges, int nneighbor, int max_recursion, double angle_param, double angle, int open_gl, int *flag);


#line 21 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2
#line 1 "graphviz-2.38.0\\lib\\mingle\\nearest_neighbor_graph.h" 1
/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




SparseMatrix nearest_neighbor_graph(int nPts, int num_neigbors, int dim, double *x, double eps);


#line 22 "graphviz-2.38.0\\lib\\mingle\\agglomerative_bundling.c" 2







enum {DEBUG=0};

static Agglomerative_Ink_Bundling Agglomerative_Ink_Bundling_init(SparseMatrix A, pedge *edges, int level){
  Agglomerative_Ink_Bundling grid;
  int n = A->n, i;

  assert(SparseMatrix_is_symmetric(A, (!(0))));

  if (!A) return (void *)0;
  assert(A->m == n);
  grid = gmalloc(sizeof(struct Agglomerative_Ink_Bundling_struct));
  grid->level = level;
  grid->n = n;
  grid->A = A;
  grid->P = (void *)0;
  grid->R0 = (void *)0;
  grid->R = (void *)0;
  grid->next = (void *)0;
  grid->prev = (void *)0;
  grid->inks = gmalloc(sizeof(double)*(A->m));
  grid->edges = edges;
  grid->delete_top_level_A = 0;
  grid->total_ink = -1;
  if (level == 0){
    double total_ink = 0;
    for (i = 0; i < n; i++) {
      (grid->inks)[i] = ink1(edges[i]);
      total_ink += (grid->inks)[i];
    }
    grid->total_ink = total_ink;
  }
  return grid;
} 

static void Agglomerative_Ink_Bundling_delete(Agglomerative_Ink_Bundling grid){
  if (!grid) return;
  if (grid->A){
    if (grid->level == 0) {
      if (grid->delete_top_level_A) SparseMatrix_delete(grid->A);
    } else {
      SparseMatrix_delete(grid->A);
    }
  }
  SparseMatrix_delete(grid->P);
  /* on level 0, R0 = NULL, on level 1, R0 = R */
  if (grid->level > 1) SparseMatrix_delete(grid->R0);
  SparseMatrix_delete(grid->R);
  free(grid->inks);

  Agglomerative_Ink_Bundling_delete(grid->next);
  free(grid);
}

static Agglomerative_Ink_Bundling Agglomerative_Ink_Bundling_establish(Agglomerative_Ink_Bundling grid, int *pick, double angle_param, double angle){
  /* pick is a work array of dimension n, with n the total number of original edges */
  int *matching;
  SparseMatrix A = grid->A;
  int n = grid->n, level = grid->level, nc = 0;
  int *ia = A->ia, *ja = A->ja;
  // real *a;
  int i, j, k, jj, jc, jmax, ni, nj, npicks;
  int *mask;
  pedge *edges = grid->edges;
  double *inks = grid->inks, *cinks, inki, inkj;
  double gain, maxgain, minink, total_gain = 0;
  int *ip = (void *)0, *jp = (void *)0, ie;
  Vector *cedges;/* a table listing the content of bundled edges in the coarsen grid.
		    cedges[i] contain the list of origonal edges that make up the bundle i in the next level */
  double ink0, ink1, grand_total_ink = 0, grand_total_gain = 0;
  point_t meet1, meet2;

  if (Verbose > 1) fprintf(stderr,"level ===================== %d, n = %d\n",grid->level, n);
  cedges = gmalloc(sizeof(Vector)*n);
  cinks = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) cedges[i] = Vector_new(1, sizeof(int), (void *)0);

  if (grid->level > 0){
    ip = grid->R0->ia;
    jp = grid->R0->ja;
  }

  matching = gmalloc(sizeof(int)*n);
  mask = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) mask[i] = -1;

  assert(n == A->n);
  for (i = 0; i < n; i++) matching[i] = UNMATCHED;

  //  a = (real*) A->a;
  for (i = 0; i < n; i++){
    if (matching[i] != UNMATCHED) continue;

    /* find the best matching in ink saving */
    maxgain = 0;
    minink = -1;
    jmax = -1;
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      if (jj == i) continue;

      /* ink saving of merging i and j */
      if ((jc=matching[jj]) == UNMATCHED){
	/* neither i nor jj are matched */
	inki = inks[i]; inkj = inks[jj];
	if (ip && jp){/* not the first level */
	  ni = (ip[i+1] - ip[i]);/* number of edges represented by i */
	  nj = (ip[jj+1] - ip[jj]);/* number of edges represented by jj */
	  memcpy(pick, &(jp[ip[i]]), sizeof(int)*ni);
	  memcpy(pick+ni, &(jp[ip[jj]]), sizeof(int)*nj);
	} else {/* first level */
	  pick[0] = i; pick[1] = jj;
	  ni = nj = 1;
	}
	if (Verbose && DEBUG) fprintf(stderr, "ink(%d)=%f, ink(%d)=%f", i, inki, jj, inkj);
      } else {
	/* j is already matched. Its content is on cedges[jc] */
	inki = inks[i]; inkj = cinks[jc];
	if (Verbose && DEBUG) fprintf(stderr, "ink(%d)=%f, ink(%d->%d)=%f", i, inki, jj, jc, inkj);
	if (ip) {
	  ni = (ip[i+1] - ip[i]);/* number of edges represented by i */
	  memcpy(pick, &(jp[ip[i]]), sizeof(int)*ni);
	} else {
	  ni = 1; pick[0] = i; 
	}
	nj = Vector_get_length(cedges[jc]);
	npicks = ni;
	for (k = 0; k < nj; k++) {
	  pick[npicks++] = *((int*) Vector_get(cedges[jc], k));
	}
      }

      npicks = ni + nj;
      ink1 = ink(edges, npicks, pick, &ink0, &meet1, &meet2, angle_param, angle);
      if (Verbose && DEBUG) {
	fprintf(stderr,", if merging {");
	for (k = 0; k < npicks; k++) fprintf(stderr,"%d,", pick[k]);
	fprintf(stderr,"}, ");
	fprintf(stderr, " ink0=%f, ink1=%f", inki+inkj, ink1);
      }

      gain = inki + inkj - ink1;
      if (Verbose && DEBUG) fprintf(stderr, " gain=%f", gain);
      if (gain > maxgain){
	maxgain = gain;
	minink = ink1;
	jmax = jj;
	if (Verbose && DEBUG) fprintf(stderr, "maxgain=%f", maxgain);
      } 
      if (Verbose && DEBUG) fprintf(stderr, "\n");

      

    }


    /* now merge i and jmax */
    if (maxgain > 0){
      /* a good bundling of i and another edge jmax is found */
      total_gain += maxgain;
      jc = matching[jmax];
      if (jc == UNMATCHED){/* i and j both unmatched. Add j in the table first */
	if (Verbose && DEBUG) printf("maxgain=%f, merge %d with best edge: %d to form coarsen edge %d. Ink=%f\n",maxgain, i, jmax, nc, minink);
	matching[i] = matching[jmax] = nc;
	if (ip){
	  for (k = ip[jmax]; k < ip[jmax+1]; k++) {
	    ie = jp[k];
	    Vector_add(cedges[nc], (void*) (&ie));
	  }
	} else {
	  Vector_add(cedges[nc], (void*) (&jmax));
	}
	jc = nc;
	nc++;
      } else {/*j is already matched */
	if (Verbose && DEBUG) printf("maxgain=%f, merge %d with existing cluster %d\n",maxgain, i, jc);
	matching[i] = jc;
	grand_total_ink -= cinks[jc];/* ink of cluster jc was already added, and will be added again as part of a larger cluster with i, so dicount */
      }
    } else {/*i can not match/bundle successfully */
      if (Verbose && DEBUG) fprintf(stderr, "no gain in bundling node %d\n",i);
      assert(maxgain <= 0);
      matching[i] = nc;
      jc = nc;
      minink = inks[i];
      nc++;
    }


    /* add i to the appropriate table */
    if (ip){
      for (k = ip[i]; k < ip[i+1]; k++) {
	ie = jp[k];
	Vector_add(cedges[jc], (void*) (&ie));
      }
    } else {
	Vector_add(cedges[jc], (void*) (&i));
    }
    cinks[jc] = minink;
    grand_total_ink += minink;
    grand_total_gain += maxgain;

    if (Verbose && DEBUG){
      fprintf(stderr," coarse edge[%d]={",jc);
      for (k = 0; k < Vector_get_length(cedges[jc]); k++) {
	fprintf(stderr,"%d,", *((int*) Vector_get(cedges[jc], k)));
      }
      fprintf(stderr,"}, grand_total_gain=%f\n",grand_total_gain);
    }

  }

  if (nc >= 1 && total_gain > 0){
    /* now set up restriction and prolongation operator */
    SparseMatrix P, R, R1, R0, B, cA;
    double one = 1.;
    Agglomerative_Ink_Bundling cgrid;

    R1 = SparseMatrix_new(nc, n, 1, MATRIX_TYPE_REAL, FORMAT_COORD);
    for (i = 0; i < n; i++){
      jj = matching[i];
      SparseMatrix_coordinate_form_add_entries(R1, 1, &jj, &i, &one);
    }
    R = SparseMatrix_from_coordinate_format(R1);
    SparseMatrix_delete(R1);
    P = SparseMatrix_transpose(R);
    B = SparseMatrix_multiply(R, A);
    if (!B) goto RETURN;
    cA = SparseMatrix_multiply(B, P); 
    if (!cA) goto RETURN;
    SparseMatrix_delete(B);
    grid->P = P;
    grid->R = R;

    level++;
    cgrid = Agglomerative_Ink_Bundling_init(cA, edges, level); 


    /* set up R0!!! */
    if (grid->R0){
      R0 = SparseMatrix_multiply(R, grid->R0);
    } else {
      assert(grid->level == 0);
      R0 = R;
    }
    cgrid->R0 = R0;
    cgrid->inks = cinks;
    cgrid->total_ink = grand_total_ink;

    if (Verbose > 1) fprintf(stderr,"level %d->%d, edges %d -> %d, ink %f->%f , gain = %f, or %f\n", grid->level, cgrid->level, grid->n, 
			 cgrid->n, grid->total_ink, grand_total_ink, grid->total_ink - grand_total_ink, grand_total_gain);	 
    assert(((grid->total_ink - cgrid->total_ink - grand_total_gain) >= 0 ? (grid->total_ink - cgrid->total_ink - grand_total_gain) : -(grid->total_ink - cgrid->total_ink - grand_total_gain)) <= 0.0001*grid->total_ink);

    cgrid = Agglomerative_Ink_Bundling_establish(cgrid, pick, angle_param, angle);
    grid->next = cgrid;
    cgrid->prev = grid;

  } else {
    if (Verbose > 1) fprintf(stderr,"no more improvement, orig ink = %f, gain = %f, stop and final bundling found\n", grand_total_ink, grand_total_gain);
    /* no more improvement, stop and final bundling found */
    for (i = 0; i < n; i++) matching[i] = i;
  }

 RETURN:
  free(matching);
  for (i = 0; i < n; i++) Vector_delete(cedges[i]);
  free(cedges);
  free(mask);
  return grid;
}



static Agglomerative_Ink_Bundling Agglomerative_Ink_Bundling_aggressive_establish(Agglomerative_Ink_Bundling grid, int *pick, double angle_param, double angle){
  /* this does a true single-linkage clustering: find the edge that gives the best saving, merge, find again. 
     As oppose to: find the edge of node i that gives the best ink saving, merge, then do the same for node i+1, etc etc.
     Right now it is implemented as a quick hack to check whether it is worth while: it saves about 3% extra ink on airlines: from
     59% to 62%
  */
  /* pick is a work array of dimension n, with n the total number of original edges */
  int *matching;
  SparseMatrix A = grid->A;
  int n = grid->n, level = grid->level, nc = 0;
  int *ia = A->ia, *ja = A->ja;
  //  real *a;
  int i, j, k, jj, jc = -1, jmax, imax, ni, nj, npicks;
  int *mask;
  pedge *edges = grid->edges;
  double *inks = grid->inks, *cinks, inki, inkj;
  double gain, maxgain, minink, total_gain = 0;
  int *ip = (void *)0, *jp = (void *)0, ie;
  Vector *cedges;/* a table listing the content of bundled edges in the coarsen grid.
		    cedges[i] contain the list of origonal edges that make up the bundle i in the next level */
  double ink0, ink1, grand_total_ink = 0, grand_total_gain = 0;
  point_t meet1, meet2;

  if (Verbose > 1) fprintf(stderr,"level ===================== %d, n = %d\n",grid->level, n);
  cedges = gmalloc(sizeof(Vector)*n);
  cinks = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) cedges[i] = Vector_new(1, sizeof(int), (void *)0);

  if (grid->level > 0){
    ip = grid->R0->ia;
    jp = grid->R0->ja;
  }

  matching = gmalloc(sizeof(int)*n);
  mask = gmalloc(sizeof(double)*n);
  for (i = 0; i < n; i++) mask[i] = -1;

  assert(n == A->n);
  for (i = 0; i < n; i++) matching[i] = UNMATCHED;

  //a = (real*) A->a;

  do {
    maxgain = 0;
    imax = -1;
    jmax = -1;
    minink = -1;
    for (i = 0; i < n; i++){
      if (matching[i] != UNMATCHED) continue;
      
      /* find the best matching in ink saving */
      for (j = ia[i]; j < ia[i+1]; j++){
	jj = ja[j];
	if (jj == i) continue;
	
	/* ink saving of merging i and j */
	if ((jc=matching[jj]) == UNMATCHED){
	  /* neither i nor jj are matched */
	  inki = inks[i]; inkj = inks[jj];
	  if (ip && jp){/* not the first level */
	    ni = (ip[i+1] - ip[i]);/* number of edges represented by i */
	    nj = (ip[jj+1] - ip[jj]);/* number of edges represented by jj */
	    memcpy(pick, &(jp[ip[i]]), sizeof(int)*ni);
	    memcpy(pick+ni, &(jp[ip[jj]]), sizeof(int)*nj);
	  } else {/* first level */
	    pick[0] = i; pick[1] = jj;
	    ni = nj = 1;
	  }
	  if (Verbose && DEBUG) fprintf(stderr, "ink(%d)=%f, ink(%d)=%f", i, inki, jj, inkj);
	} else {
	  /* j is already matched. Its content is on cedges[jc] */
	  inki = inks[i]; inkj = cinks[jc];
	  if (Verbose && DEBUG) fprintf(stderr, "ink(%d)=%f, ink(%d->%d)=%f", i, inki, jj, jc, inkj);
	  if (ip) {
	    ni = (ip[i+1] - ip[i]);/* number of edges represented by i */
	    memcpy(pick, &(jp[ip[i]]), sizeof(int)*ni);
	  } else {
	    ni = 1; pick[0] = i; 
	  }
	  nj = Vector_get_length(cedges[jc]);
	  npicks = ni;
	  for (k = 0; k < nj; k++) {
	    pick[npicks++] = *((int*) Vector_get(cedges[jc], k));
	  }
	}

	npicks = ni + nj;
	ink1 = ink(edges, npicks, pick, &ink0, &meet1, &meet2, angle_param, angle);
	if (Verbose && DEBUG) {
	  fprintf(stderr,", if merging {");
	  for (k = 0; k < npicks; k++) fprintf(stderr,"%d,", pick[k]);
	  fprintf(stderr,"}, ");
	  fprintf(stderr, " ink0=%f, ink1=%f", inki+inkj, ink1);
	}

	gain = inki + inkj - ink1;
	if (Verbose && DEBUG) fprintf(stderr, " gain=%f", gain);
	if (gain > maxgain){
	  maxgain = gain;
	  minink = ink1;
	  jmax = jj;
	  imax = i;
	  if (Verbose && DEBUG) fprintf(stderr, "maxgain=%f", maxgain);
	} 
	if (Verbose && DEBUG) fprintf(stderr, "\n");

      

      }
    }

    /* now merge i and jmax */
    if (maxgain > 0){
      /* a good bundling of i and another edge jmax is found */
      total_gain += maxgain;
      jc = matching[jmax];
      if (jc == UNMATCHED){/* i and j both unmatched. Add j in the table first */
	if (Verbose && DEBUG) printf("maxgain=%f, merge %d with best edge: %d to form coarsen edge %d. Ink=%f\n",maxgain, imax, jmax, nc, minink);
	matching[imax] = matching[jmax] = nc;
	if (ip){
	  for (k = ip[jmax]; k < ip[jmax+1]; k++) {
	    ie = jp[k];
	    Vector_add(cedges[nc], (void*) (&ie));
	  }
	} else {
	  Vector_add(cedges[nc], (void*) (&jmax));
	}
	jc = nc;
	nc++;
      } else {/*j is already matched */
	if (Verbose && DEBUG) printf("maxgain=%f, merge %d with existing cluster %d\n",maxgain, i, jc);
	matching[imax] = jc;
	grand_total_ink -= cinks[jc];/* ink of cluster jc was already added, and will be added again as part of a larger cluster with i, so dicount */
      }
      /* add i to the appropriate table */
      if (ip){
	for (k = ip[imax]; k < ip[imax+1]; k++) {
	  ie = jp[k];
	  Vector_add(cedges[jc], (void*) (&ie));
	}
      } else {
	Vector_add(cedges[jc], (void*) (&imax));
      }
      cinks[jc] = minink;
      grand_total_ink += minink;
      grand_total_gain += maxgain;
    } else {/*i can not match/bundle successfully */
      if (Verbose && DEBUG) fprintf(stderr, "no gain in bundling node %d\n",i);
      for (i = 0; i < n; i++){
	assert(maxgain <= 0);
	if (matching[i] == UNMATCHED){
	  imax = i;
	  matching[imax] = nc;
	  jc = nc;
	  minink = inks[imax];
	  nc++;

	  if (ip){
	    for (k = ip[imax]; k < ip[imax+1]; k++) {
	      ie = jp[k];
	      Vector_add(cedges[jc], (void*) (&ie));
	    }
	  } else {
	    Vector_add(cedges[jc], (void*) (&imax));
	  }
	  cinks[jc] = minink;
	  grand_total_ink += minink;
	  grand_total_gain += maxgain;




	}
      }
    }

  } while (maxgain > 0);

  
  if (Verbose && DEBUG){
    fprintf(stderr," coarse edge[%d]={",jc);
    for (k = 0; k < Vector_get_length(cedges[jc]); k++) {
      fprintf(stderr,"%d,", *((int*) Vector_get(cedges[jc], k)));
    }
    fprintf(stderr,"}\n");
  }
  
  if (nc >= 1 && total_gain > 0){
    /* now set up restriction and prolongation operator */
    SparseMatrix P, R, R1, R0, B, cA;
    double one = 1.;
    Agglomerative_Ink_Bundling cgrid;

    R1 = SparseMatrix_new(nc, n, 1, MATRIX_TYPE_REAL, FORMAT_COORD);
    for (i = 0; i < n; i++){
      jj = matching[i];
      SparseMatrix_coordinate_form_add_entries(R1, 1, &jj, &i, &one);
    }
    R = SparseMatrix_from_coordinate_format(R1);
    SparseMatrix_delete(R1);
    P = SparseMatrix_transpose(R);
    B = SparseMatrix_multiply(R, A);
    if (!B) goto RETURN;
    cA = SparseMatrix_multiply(B, P); 
    if (!cA) goto RETURN;
    SparseMatrix_delete(B);
    grid->P = P;
    grid->R = R;

    level++;
    cgrid = Agglomerative_Ink_Bundling_init(cA, edges, level); 


    /* set up R0!!! */
    if (grid->R0){
      R0 = SparseMatrix_multiply(R, grid->R0);
    } else {
      assert(grid->level == 0);
      R0 = R;
    }
    cgrid->R0 = R0;
    cgrid->inks = cinks;
    cgrid->total_ink = grand_total_ink;

    if (Verbose > 1) fprintf(stderr,"level %d->%d, edges %d -> %d, ink %f->%f , gain = %f, or %f\n", grid->level, cgrid->level, grid->n, 
			 cgrid->n, grid->total_ink, grand_total_ink, grid->total_ink - grand_total_ink, grand_total_gain);	 
    assert(((grid->total_ink - cgrid->total_ink - grand_total_gain) >= 0 ? (grid->total_ink - cgrid->total_ink - grand_total_gain) : -(grid->total_ink - cgrid->total_ink - grand_total_gain)) <= 0.0001*grid->total_ink);

    cgrid = Agglomerative_Ink_Bundling_aggressive_establish(cgrid, pick, angle_param, angle);
    grid->next = cgrid;
    cgrid->prev = grid;

  } else {
    if (Verbose > 1) fprintf(stderr,"no more improvement, orig ink = %f, gain = %f, stop and final bundling found\n", grand_total_ink, grand_total_gain);
    /* no more improvement, stop and final bundling found */
    for (i = 0; i < n; i++) matching[i] = i;
  }
 
 RETURN:
  free(matching);
  for (i = 0; i < n; i++) Vector_delete(cedges[i]);
  free(mask);
  return grid;
}

static Agglomerative_Ink_Bundling Agglomerative_Ink_Bundling_new(SparseMatrix A0, pedge *edges, double angle_param, double angle){
  /* give a link of edges and their nearest neighbor graph, return a multilevel of edge bundling based on ink saving */
  Agglomerative_Ink_Bundling grid;
  int *pick;
  SparseMatrix A = A0;

  if (!SparseMatrix_is_symmetric(A, 0) || A->type != MATRIX_TYPE_REAL){
    A = SparseMatrix_get_real_adjacency_matrix_symmetrized(A);
  }
  grid = Agglomerative_Ink_Bundling_init(A, edges, 0);

  pick = gmalloc(sizeof(int)*A0->m);
  
  //grid = Agglomerative_Ink_Bundling_aggressive_establish(grid, pick, angle_param, angle);
  grid = Agglomerative_Ink_Bundling_establish(grid, pick, angle_param, angle);
  free(pick);

  if (A != A0) grid->delete_top_level_A = (!(0));/* be sure to clean up later */

  return grid;
}

static pedge* agglomerative_ink_bundling_internal(int dim, SparseMatrix A, pedge* edges, int nneighbors, int *recurse_level, int MAX_RECURSE_LEVEL, double angle_param, double angle, int open_gl, double *current_ink, double *ink00, int *flag){

  int i, j, jj, k;
  int *ia, *ja;
  int *pick;
  Agglomerative_Ink_Bundling grid, cgrid;
  SparseMatrix R;
  double ink0, ink1;
  point_t meet1, meet2;
  pedge e;
  double TOL = 0.0001, wgt_all;
  clock_t start;
  
  (*recurse_level)++;
  if (Verbose > 1) fprintf(stderr, "agglomerative_ink_bundling_internal, recurse level ------- %d\n",*recurse_level);

  assert(A->m == A->n);

  *flag = 0;

  start = clock();
  grid = Agglomerative_Ink_Bundling_new(A, edges, angle_param, angle);
  if (Verbose > 1)
    fprintf(stderr, "CPU for agglomerative bundling %f\n", ((double) (clock() - start))/CLOCKS_PER_SEC);
  ink0 = grid->total_ink;

  /* find coarsest */
  cgrid = grid;
  while (cgrid->next){
    cgrid = cgrid->next;
  }
  ink1 = cgrid->total_ink;

  if (*current_ink < 0){
    *current_ink = *ink00 = ink0;
    if (Verbose > 1)
      fprintf(stderr,"initial total ink = %f\n",*current_ink);
  } 
  if (ink1 < ink0){
    *current_ink -= ink0 - ink1;
  }

  if (Verbose > 1) fprintf(stderr,"ink: %f->%f, edges: %d->%d, current ink = %f, percentage gain over original = %f\n", ink0, ink1, grid->n, cgrid->n, *current_ink, (ink0-ink1)/(*ink00));

  /* if no meaningful improvement (0.0001%), out, else rebundle the middle section */
  if ((ink0-ink1)/(*ink00) < 0.000001 || *recurse_level > MAX_RECURSE_LEVEL) {
    /* project bundles up */
    R = cgrid->R0;
    if (R){
      ia = R->ia;
      ja = R->ja;
      for (i = 0; i < R->m; i++){
	pick = &(ja[ia[i]]);
	
	if (Verbose && DEBUG) fprintf(stderr,"calling ink2...\n");
	ink1 = ink(edges, ia[i+1]-ia[i], pick, &ink0, &meet1, &meet2, angle_param, angle);
	if (Verbose && DEBUG) fprintf(stderr,"finish calling ink2...\n");
	assert(((ink1 - cgrid->inks[i]) >= 0 ? (ink1 - cgrid->inks[i]) : -(ink1 - cgrid->inks[i]))<=((TOL)>(TOL*ink1)?(TOL):(TOL*ink1)) && ink1 - ink0 <= TOL);
	wgt_all = 0.;
	if (ia[i+1]-ia[i] > 1){
	  for (j = ia[i]; j < ia[i+1]; j++){
	    /* make this edge 4 points, insert two meeting points at 1 and 2, make 3 the last point */
	    jj = ja[j];
	    edges[jj] = pedge_double(edges[jj]);/* has to call pedge_double twice: from 2 points to 3 points to 5 points. The last point not used, may be
						 improved later */
	    e = edges[jj] = pedge_double(edges[jj]);

	    e->wgts = grealloc(e->wgts, sizeof(double)*4);	
	    e->x[1*dim] = meet1.x;
	    e->x[1*dim+1] = meet1.y;
	    e->x[2*dim] = meet2.x;
	    e->x[2*dim+1] = meet2.y;
	    e->x[3*dim] = e->x[4*dim];
	    e->x[3*dim+1] = e->x[4*dim+1];
	    e->npoints = 4;
	    for (k = 0; k < 3; k++) e->wgts[k] = e->wgt;
	    wgt_all += e->wgt;
	    
	  }
	  for (j = ia[i]; j < ia[i+1]; j++){
	    e = edges[ja[j]];
	    e->wgts[1] = wgt_all;
	  }
	}
	
      } 
    }
  } else {
    pedge *mid_edges, midedge;/* middle section of edges that will be bundled again */
    double *xx;
    int ne, npp, l;
    SparseMatrix A_mid;
    double eps = 0., wgt, total_wgt = 0;

   /* make new edges using meet1 and meet2.
       
       call Agglomerative_Ink_Bundling_new
       
       inherit new edges to old edges
    */

    R = cgrid->R0;
    assert(R && cgrid != grid);/* if ink improved, we should have gone at leat 1 level down! */
    ia = R->ia;
    ja = R->ja;
    ne = R->m;
    mid_edges = gmalloc(sizeof(pedge)*ne);
    xx = gmalloc(sizeof(double)*4*ne);
    for (i = 0; i < R->m; i++){
      pick = &(ja[ia[i]]);
      wgt = 0.;
      for (j = ia[i]; j < ia[i+1]; j++) wgt += edges[j]->wgt;
      total_wgt += wgt;
      if (Verbose && DEBUG) fprintf(stderr,"calling ink3...\n");
      ink1 = ink(edges, ia[i+1]-ia[i], pick, &ink0, &meet1, &meet2, angle_param, angle);
      if (Verbose && DEBUG) fprintf(stderr,"done calling ink3...\n");
      assert(((ink1 - cgrid->inks[i]) >= 0 ? (ink1 - cgrid->inks[i]) : -(ink1 - cgrid->inks[i]))<=((TOL)>(TOL*ink1)?(TOL):(TOL*ink1)) && ink1 - ink0 <= TOL);
      xx[i*4 + 0] = meet1.x;
      xx[i*4 + 1] = meet1.y;
      xx[i*4 + 2] = meet2.x;
      xx[i*4 + 3] = meet2.y;
      mid_edges[i] = pedge_wgt_new(2, dim, &(xx[i*4]), wgt);
      //mid_edges[i] = pedge_wgt_new(2, dim, &(xx[i*4]), 1.);

    }

    A_mid = nearest_neighbor_graph(ne, ((nneighbors)<(ne)?(nneighbors):(ne)), 4, xx, eps);

    agglomerative_ink_bundling_internal(dim, A_mid, mid_edges, nneighbors, recurse_level, MAX_RECURSE_LEVEL, angle_param, angle, open_gl, current_ink, ink00, flag);
    SparseMatrix_delete(A_mid);
    free(xx);
    
    /* patching edges with the new mid-section */
    for (i = 0; i < R->m; i++){
      pick = &(ja[ia[i]]);
      midedge = mid_edges[i];
      npp = midedge->npoints + 2;
      for (j = ia[i]; j < ia[i+1]; j++){
	jj = ja[j];
	e = edges[jj] = pedge_wgts_realloc(edges[jj], npp);

	assert(e->npoints = 2);
	for (l = 0; l < dim; l++){/* move the second point to the last */
	  e->x[(npp - 1)*dim+l] = e->x[1*dim+l];
	}

	for (k = 0; k < midedge->npoints; k++){
	  for (l = 0; l < dim; l++){
	    e->x[(k+1)*dim+l] = midedge->x[k*dim+l];
	  }
	  if (k < midedge->npoints - 1){
	    if (midedge->wgts){
	      e->wgts[(k+1)] = midedge->wgts[k];
	    } else {
	      e->wgts[(k+1)] = midedge->wgt;
	    }
	  }
	}
	e->wgts[npp - 2] = e->wgts[0];/* the last interval take from the 1st interval */


	e->npoints = npp;
      }

      
	
	
	
	
      

    }

    for (i = 0; i < ne; i++) pedge_delete(mid_edges[i]);

  }



  
    
    
    
    
  


  Agglomerative_Ink_Bundling_delete(grid);

  return edges;
}


pedge* agglomerative_ink_bundling(int dim, SparseMatrix A, pedge* edges, int nneighbor, int MAX_RECURSE_LEVEL, double angle_param, double angle, int open_gl, int *flag){
  int recurse_level = 0;
  double current_ink = -1, ink0;
  pedge *edges2;

  ink_count = 0;
  edges2 = agglomerative_ink_bundling_internal(dim, A, edges, nneighbor, &recurse_level, MAX_RECURSE_LEVEL, angle_param, angle, open_gl, &current_ink, &ink0, flag);

  
  if (Verbose > 1)
    fprintf(stderr,"initial total ink = %f, final total ink = %f, inksaving = %f percent, total ink_calc = %f, avg ink_calc per edge = %f\n", ink0, current_ink, (ink0-current_ink)/ink0, ink_count,  ink_count/(double) A->m);
  return edges2;
}

