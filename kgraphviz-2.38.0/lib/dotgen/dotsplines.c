#line 1 "graphviz-2.38.0\\lib\\dotgen\\dotsplines.c" 1
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
 * set edge splines.
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


#line 21 "graphviz-2.38.0\\lib\\dotgen\\dotsplines.c" 2


































static boxf boxes[1000];
typedef struct {
    int LeftBound, RightBound, Splinesep, Multisep;
    boxf* Rank_box;
} spline_info_t;

static void adjustregularpath(path *, int, int);
static Agedge_t *bot_bound(Agedge_t *, int);
static boolean pathscross(Agnode_t *, Agnode_t *, Agedge_t *, Agedge_t *);
static Agraph_t *cl_bound(graph_t*, Agnode_t *, Agnode_t *);
static int cl_vninside(Agraph_t *, Agnode_t *);
static void completeregularpath(path *, Agedge_t *, Agedge_t *,
				pathend_t *, pathend_t *, boxf *, int, int);
static int edgecmp(Agedge_t **, Agedge_t **);
static void make_flat_edge(graph_t*, spline_info_t*, path *, Agedge_t **, int, int, int);
static void make_regular_edge(graph_t* g, spline_info_t*, path *, Agedge_t **, int, int, int);
static boxf makeregularend(boxf, int, double);
static boxf maximal_bbox(graph_t* g, spline_info_t*, Agnode_t *, Agedge_t *, Agedge_t *);
static Agnode_t *neighbor(graph_t*, Agnode_t *, Agedge_t *, Agedge_t *, int);
static void place_vnlabel(Agnode_t *);
static boxf rank_box(spline_info_t* sp, Agraph_t *, int);
static void recover_slack(Agedge_t *, path *);
static void resize_vn(Agnode_t *, int, int, int);
static void setflags(Agedge_t *, int, int, int);
static int straight_len(Agnode_t *);
static Agedge_t *straight_path(Agedge_t *, int, pointf *, int *);
static Agedge_t *top_bound(Agedge_t *, int);



static edge_t*
getmainedge(edge_t * e)
{
    edge_t *le = e;
    while ((((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_virt))
	le = (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_virt);
    while ((((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_orig))
	le = (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_orig);
    return le;
}

static boolean spline_merge(node_t * n)
{
    return (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1)
	    && (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size > 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size > 1)));
}

static boolean swap_ends_p(edge_t * e)
{
    while ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig))
	e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig);
    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank) > (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank))
	return 0;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank) < (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank))
	return (!(0));
    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) >= (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order))
	return 0;
    return (!(0));
}

static splineInfo sinfo = { swap_ends_p, spline_merge };

int portcmp(port p0, port p1)
{
    int rv;
    if (p1.defined == 0)
	return (p0.defined ? 1 : 0);
    if (p0.defined == 0)
	return -1;
    rv = p0.p.x - p1.p.x;
    if (rv == 0)
	rv = p0.p.y - p1.p.y;
    return rv;
}

/* swap_bezier:
 */
static void swap_bezier(bezier * old, bezier * new)
{
    pointf *list;
    pointf *lp;
    pointf *olp;
    int i, sz;

    sz = old->size;
    list = (pointf*)gmalloc((sz)*sizeof(pointf));
    lp = list;
    olp = old->list + (sz - 1);
    for (i = 0; i < sz; i++) {	/* reverse list of points */
	*lp++ = *olp--;
    }

    new->list = list;
    new->size = sz;
    new->sflag = old->eflag;
    new->eflag = old->sflag;
    new->sp = old->ep;
    new->ep = old->sp;
}

/* swap_spline:
 */
static void swap_spline(splines * s)
{
    bezier *list;
    bezier *lp;
    bezier *olp;
    int i, sz;

    sz = s->size;
    list = (bezier*)gmalloc((sz)*sizeof(bezier));
    lp = list;
    olp = s->list + (sz - 1);
    for (i = 0; i < sz; i++) {	/* reverse and swap list of beziers */
	swap_bezier(olp--, lp++);
    }

    /* free old structures */
    for (i = 0; i < sz; i++)
	free(s->list[i].list);
    free(s->list);

    s->list = list;
}

/* edge_normalize:
 * Some back edges are reversed during layout and the reversed edge
 * is used to compute the spline. We would like to guarantee that
 * the order of control points always goes from tail to head, so
 * we reverse them if necessary.
 */
static void edge_normalize(graph_t * g)
{
    edge_t *e;
    node_t *n;

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    if (sinfo.swapEnds(e) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl))
		swap_spline((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl));
	}
    }
}

/* resetRW:
 * In position, each node has its rw stored in mval and,
 * if a node is part of a loop, rw may be increased to
 * reflect the loops and associated labels. We restore
 * the original value here. 
 */
static void
resetRW (graph_t * g)
{
    node_t* n;

    for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->other).list) {
	    double tmp = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval);
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = tmp;
	}
    }
}

/* setEdgeLabelPos:
 * Set edge label position information for regular and non-adjacent flat edges.
 * Dot has allocated space and position for these labels. This info will be
 * used when routing orthogonal edges.
 */
static void
setEdgeLabelPos (graph_t * g)
{
    node_t* n;
    textlabel_t* l;

    /* place regular edge labels */
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1) {
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->alg)) {   // label of non-adjacent flat edge
		edge_t* fe = (edge_t*)(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->alg);
		assert ((l = (((Agedgeinfo_t*)(((Agobj_t*)(fe))->data))->label)));
		l->pos = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
		l->set = (!(0));
	    }
	    else if ((l = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label))) {// label of regular edge
		place_vnlabel(n);
	    }
	    if (l) updateBB(g, l);
	}
    }
}

/* _dot_splines:
 * Main spline routing code.
 * The normalize parameter allows this function to be called by the
 * recursive call in make_flat_edge without normalization occurring,
 * so that the edge will only be normalized once in the top level call
 * of dot_splines.
 */
static void _dot_splines(graph_t * g, int normalize)
{
    int i, j, k, n_nodes, n_edges, ind, cnt;
    node_t *n;
    Agedgeinfo_t fwdedgeai, fwdedgebi;
    Agedgepair_t fwdedgea, fwdedgeb;
    edge_t *e, *e0, *e1, *ea, *eb, *le0, *le1, **edges;
    path *P;
    spline_info_t sd;
    int et = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->flags) & (7 << 1));
    fwdedgea.out.base.data = (Agrec_t*)&fwdedgeai;
    fwdedgeb.out.base.data = (Agrec_t*)&fwdedgebi;

    if (et == (0 << 1)) return; 
    if (et == (2 << 1)) {
	resetRW (g);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_labels) & (1 << 0)) {
	    agerr (AGWARN, "edge labels with splines=curved not supported in dot - use xlabels\n");
	}
	for (n = agfstnode (g); n; n = agnxtnode(g, n)) {
	    for (e = agfstout(g, n); e; e = agnxtout(g,e)) {
		makeStraightEdge(g, e, et, &sinfo);
	    }
	}
	goto finish;
    } 

    
	
	
	    
	    
	
	
	    
	
    


    mark_lowclusters(g);
    if (routesplinesinit()) return;
    P = (path*)zmalloc(sizeof(path));
    /* FlatHeight = 2 * GD_nodesep(g); */
    sd.Splinesep = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nodesep) / 4;
    sd.Multisep = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nodesep);
    edges = (edge_t **)zmalloc((128)*sizeof(edge_t *));

    /* compute boundaries and list of splines */
    sd.LeftBound = sd.RightBound = 0;
    n_edges = n_nodes = 0;
    for (i = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); i++) {
	n_nodes += (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n;
	if ((n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].v[0]))
	    sd.LeftBound = ((sd.LeftBound)<(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)))?(sd.LeftBound):(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw))));
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n && (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].v[(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n - 1]))
	    sd.RightBound = ((sd.RightBound)>(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)))?(sd.RightBound):(((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw))));
	sd.LeftBound -= 16;
	sd.RightBound += 16;

	for (j = 0; j < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n; j++) {
	    n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].v[j];
		/* if n is the label of a flat edge, copy its position to
		 * the label.
		 */
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->alg)) {
		edge_t* fe = (edge_t*)(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->alg);
		assert ((((Agedgeinfo_t*)(((Agobj_t*)(fe))->data))->label));
		(((Agedgeinfo_t*)(((Agobj_t*)(fe))->data))->label)->pos = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
		(((Agedgeinfo_t*)(((Agobj_t*)(fe))->data))->label)->set = (!(0));
	    }
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) != 0) &&
		(sinfo.splineMerge(n) == 0))
		continue;
	    for (k = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[k]); k++) {
		if (((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 4)
		    || ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 6))
		    continue;
		setflags(e, 1, 16, 64);
		edges[n_edges++] = e;
		if (n_edges % 128 == 0)
		    (edges = (edges? (edge_t**)grealloc(edges,(n_edges + 128)*sizeof(edge_t*)):(edge_t**)gmalloc((n_edges + 128)*sizeof(edge_t*))));
	    }
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_out).list)
		for (k = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_out).list[k]); k++) {
		    setflags(e, 2, 0, 128);
		    edges[n_edges++] = e;
		    if (n_edges % 128 == 0)
			(edges = (edges? (edge_t**)grealloc(edges,(n_edges + 128)*sizeof(edge_t*)):(edge_t**)gmalloc((n_edges + 128)*sizeof(edge_t*))));
		}
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->other).list) {
		/* In position, each node has its rw stored in mval and,
                 * if a node is part of a loop, rw may be increased to
                 * reflect the loops and associated labels. We restore
                 * the original value here. 
                 */
		if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0) {
		    double tmp = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw);
		    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval);
		    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = tmp;
		}
		for (k = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->other).list[k]); k++) {
		    setflags(e, 0, 0, 128);
		    edges[n_edges++] = e;
		    if (n_edges % 128 == 0)
			(edges = (edges? (edge_t**)grealloc(edges,(n_edges + 128)*sizeof(edge_t*)):(edge_t**)gmalloc((n_edges + 128)*sizeof(edge_t*))));
		}
	    }
	}
    }

    /* Sort so that equivalent edges are contiguous. 
     * Equivalence should basically mean that 2 edges have the
     * same set {(tailnode,tailport),(headnode,headport)}, or
     * alternatively, the edges would be routed identically if
     * routed separately.
     */
    qsort((char *) &edges[0], n_edges, sizeof(edges[0]),
	  (qsort_cmpf) edgecmp);

    /* FIXME: just how many boxes can there be? */
    P->boxes = (boxf*)zmalloc((n_nodes + 20 * 2 * 9)*sizeof(boxf));
    sd.Rank_box = (boxf*)zmalloc((i)*sizeof(boxf));

    if (et == (1 << 1)) {
    /* place regular edge labels */
	for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label))) {
		place_vnlabel(n);
	    }
	}
    }

    for (i = 0; i < n_edges;) {
 	boolean havePorts;
	ind = i;
	le0 = getmainedge((e0 = edges[i++]));
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->head_port).defined) {
	    havePorts = (!(0));
	    ea = e0;
	} else {
	    havePorts = 0;
	    ea =  le0;
	}
	if ((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tree_index) & 32) {
	    { edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgea.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)ea->base.data; *newp = *ea; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(ea))->tag).objtype) == 2? (ea): ((ea)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(ea))->tag).objtype) == 3? (ea): ((ea)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = ea; };
	    ea = &fwdedgea.out;
	}
	for (cnt = 1; i < n_edges; cnt++, i++) {
	    if (le0 != (le1 = getmainedge((e1 = edges[i]))))
		break;
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->adjacent)) continue; /* all flat adjacent edges at once */
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->head_port).defined) {
		if (!havePorts) break;
		else
		    eb = e1;
	    } else {
		if (havePorts) break;
		else
		    eb = le1;
	    }
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tree_index) & 32) {
		{ edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgeb.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)eb->base.data; *newp = *eb; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(eb))->tag).objtype) == 2? (eb): ((eb)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(eb))->tag).objtype) == 3? (eb): ((eb)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = eb; };
		eb = &fwdedgeb.out;
	    }
	    if (portcmp((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tail_port), (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tail_port)))
		break;
	    if (portcmp((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->head_port), (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->head_port)))
		break;
	    if (((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->tree_index) & 15) == 2
		&& (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->label) != (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label))
		break;
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(edges[i]))->data))->tree_index) & 64)	/* Aha! -C is on */
		break;
	}

	if (((((((Agobj_t*)(e0))->tag).objtype) == 3? (e0): ((e0)+1))->node) == ((((((Agobj_t*)(e0))->tag).objtype) == 2? (e0): ((e0)-1))->node)) {
	    int b, sizey, r;
	    n = ((((((Agobj_t*)(e0))->tag).objtype) == 3? (e0): ((e0)+1))->node);
	    r = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
	    if (r == (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank)) {
		if (r > 0)
		    sizey = (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r-1].v[0]))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
		else
		    sizey = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht);
	    }
	    else if (r == (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank)) {
		sizey = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r+1].v[0]))->data))->coord).y;
	    }
	    else {
		int upy = (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r-1].v[0]))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
		int dwny = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r+1].v[0]))->data))->coord).y;
		sizey = ((upy)<(dwny)?(upy):(dwny));
	    }
	    makeSelfEdge(P, edges, ind, cnt, sd.Multisep, sizey/2, &sinfo);
	    for (b = 0; b < cnt; b++) {
		e = edges[ind+b];
		if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label))
		    updateBB(g, (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label));
	    }
	}
	else if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e0))->tag).objtype) == 3?(e0):((e0)+1))->node)))->data))->rank) == (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e0))->tag).objtype) == 2?(e0):((e0)-1))->node)))->data))->rank)) {
	    make_flat_edge(g, &sd, P, edges, ind, cnt, et);
	}
	else
	    make_regular_edge(g, &sd, P, edges, ind, cnt, et);
    }

    /* place regular edge labels */
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label))) {
	    place_vnlabel(n);
	    updateBB(g, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label));
	}
    }

    /* normalize splines so they always go from tail to head */
    /* place_portlabel relies on this being done first */
    if (normalize)
	edge_normalize(g);

finish :
    /* vladimir: place port labels */
    /* FIX: head and tail labels are not part of cluster bbox */
    if ((E_headlabel || E_taillabel) && (E_labelangle || E_labeldistance)) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    if (E_headlabel) {
		for (e = agfstin(g, n); e; e = agnxtin(g, e))
		    if ((((Agedgeinfo_t*)(((Agobj_t*)((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))))->data))->head_label)) {
			place_portlabel((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)), (!(0)));
			updateBB(g, (((Agedgeinfo_t*)(((Agobj_t*)((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))))->data))->head_label));
		    }

	    }
	    if (E_taillabel) {
		for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
		    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)) {
			if (place_portlabel(e, 0))
			    updateBB(g, (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label));
		    }
		}
	    }
	}
    }
    /* end vladimir */


    

    if (et != (2 << 1)) {

	free(edges);
	free(P->boxes);
	free(P);
	free(sd.Rank_box);
	routesplinesterm();
    } 
    State = 1;
    EdgeLabelsDone = 1;
}

/* dot_splines:
 * If the splines attribute is defined but equal to "", skip edge routing.
 */
void dot_splines(graph_t * g)
{
    _dot_splines (g, 1);
}

/* place_vnlabel:
 * assign position of an edge label from its virtual node
 * This is for regular edges only.
 */
static void 
place_vnlabel(node_t * n)
{
    pointf dimen;
    double width;
    edge_t *e;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size == 0)
	return;			/* skip flat edge labels here */
    for (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0]; (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0;
	 e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig));
    dimen = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen;
    width = ((((Agraphinfo_t*)(((Agobj_t*)(agraphof(n)))->data))->rankdir & 0x3) & 1) ? dimen.y : dimen.x;
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x + width / 2.0;
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
}

static void 
setflags(edge_t *e, int hint1, int hint2, int f3)
{
    int f1, f2;
    if (hint1 != 0)
	f1 = hint1;
    else {
	if (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) == ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).defined)
		f1 = 4;
	    else
		f1 = 8;
	else if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank) == (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank))
	    f1 = 2;
	else
	    f1 = 1;
    }
    if (hint2 != 0)
	f2 = hint2;
    else {
	if (f1 == 1)
	    f2 = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank) < (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank)) ? 16 : 32;
	else if (f1 == 2)
	    f2 = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order) < (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order)) ?  16 : 32;
	else			/* f1 == SELF*EDGE */
	    f2 = 16;
    }
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tree_index) = (f1 | f2 | f3);
}

/* edgecmp:
 * lexicographically order edges by
 *  - edge type
 *  - |rank difference of nodes|
 *  - |x difference of nodes|
 *  - id of witness edge for equivalence class
 *  - port comparison
 *  - graph type
 *  - labels if flat edges
 *  - edge id
 */
static int edgecmp(edge_t** ptr0, edge_t** ptr1)
{
    Agedgeinfo_t fwdedgeai, fwdedgebi;
    Agedgepair_t fwdedgea, fwdedgeb;
    edge_t *e0, *e1, *ea, *eb, *le0, *le1;
    int et0, et1, v0, v1, rv;
    double t0, t1;

    fwdedgea.out.base.data = (Agrec_t*)&fwdedgeai;
    fwdedgeb.out.base.data = (Agrec_t*)&fwdedgebi;
    e0 = (edge_t *) * ptr0;
    e1 = (edge_t *) * ptr1;
    et0 = (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->tree_index) & 15;
    et1 = (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->tree_index) & 15;
    if (et0 != et1)
	return (et1 - et0);

    le0 = getmainedge(e0);
    le1 = getmainedge(e1);

    t0 = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le0))->tag).objtype) == 3?(le0):((le0)+1))->node)))->data))->rank) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le0))->tag).objtype) == 2?(le0):((le0)-1))->node)))->data))->rank);
    t1 = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le1))->tag).objtype) == 3?(le1):((le1)+1))->node)))->data))->rank) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le1))->tag).objtype) == 2?(le1):((le1)-1))->node)))->data))->rank);
    v0 = (((int)t0) >= 0 ? ((int)t0) : -((int)t0));   /* ugly, but explicit as to how we avoid equality tests on fp numbers */
    v1 = (((int)t1) >= 0 ? ((int)t1) : -((int)t1));
    if (v0 != v1)
	return (v0 - v1);

    t0 = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le0))->tag).objtype) == 3?(le0):((le0)+1))->node)))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le0))->tag).objtype) == 2?(le0):((le0)-1))->node)))->data))->coord).x;
    t1 = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le1))->tag).objtype) == 3?(le1):((le1)+1))->node)))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(le1))->tag).objtype) == 2?(le1):((le1)-1))->node)))->data))->coord).x;
    v0 = (((int)t0) >= 0 ? ((int)t0) : -((int)t0));
    v1 = (((int)t1) >= 0 ? ((int)t1) : -((int)t1));
    if (v0 != v1)
	return (v0 - v1);

    /* This provides a cheap test for edges having the same set of endpoints.  */
    if (((((Agobj_t*)(le0))->tag).seq) != ((((Agobj_t*)(le1))->tag).seq))
	return (((((Agobj_t*)(le0))->tag).seq) - ((((Agobj_t*)(le1))->tag).seq));

    ea = ((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->head_port).defined) ? e0 : le0;
    if ((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tree_index) & 32) {
	{ edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgea.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)ea->base.data; *newp = *ea; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(ea))->tag).objtype) == 2? (ea): ((ea)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(ea))->tag).objtype) == 3? (ea): ((ea)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = ea; };
	ea = &fwdedgea.out;
    }
    eb = ((((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->head_port).defined) ? e1 : le1;
    if ((((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tree_index) & 32) {
	{ edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgeb.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)eb->base.data; *newp = *eb; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(eb))->tag).objtype) == 2? (eb): ((eb)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(eb))->tag).objtype) == 3? (eb): ((eb)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = eb; };
	eb = &fwdedgeb.out;
    }
    if ((rv = portcmp((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->tail_port), (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->tail_port))))
	return rv;
    if ((rv = portcmp((((Agedgeinfo_t*)(((Agobj_t*)(ea))->data))->head_port), (((Agedgeinfo_t*)(((Agobj_t*)(eb))->data))->head_port))))
	return rv;

    et0 = (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->tree_index) & 192;
    et1 = (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->tree_index) & 192;
    if (et0 != et1)
	return (et0 - et1);

    if (et0 == 2 && (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->label) != (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label))
	return (int) ((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->label) - (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label));

    return (((((Agobj_t*)(e0))->tag).seq) - ((((Agobj_t*)(e1))->tag).seq));
}

/* cloneGraph:
 */
typedef struct {
    attrsym_t* E_constr;
    attrsym_t* E_samehead;
    attrsym_t* E_sametail;
    attrsym_t* E_weight;
    attrsym_t* E_minlen;
    attrsym_t* E_fontcolor;
    attrsym_t* E_fontname;
    attrsym_t* E_fontsize;
    attrsym_t* E_headclip;
    attrsym_t* E_headlabel;
    attrsym_t* E_label;
    attrsym_t* E_label_float;
    attrsym_t* E_labelfontcolor;
    attrsym_t* E_labelfontname;
    attrsym_t* E_labelfontsize;
    attrsym_t* E_tailclip;
    attrsym_t* E_taillabel;
    attrsym_t* E_xlabel;

    attrsym_t* N_height;
    attrsym_t* N_width;
    attrsym_t* N_shape;
    attrsym_t* N_style;
    attrsym_t* N_fontsize;
    attrsym_t* N_fontname;
    attrsym_t* N_fontcolor;
    attrsym_t* N_label;
    attrsym_t* N_xlabel;
    attrsym_t* N_showboxes;
    attrsym_t* N_ordering;
    attrsym_t* N_sides;
    attrsym_t* N_peripheries;
    attrsym_t* N_skew;
    attrsym_t* N_orientation;
    attrsym_t* N_distortion;
    attrsym_t* N_fixed;
    attrsym_t* N_nojustify;
    attrsym_t* N_group;

    attrsym_t* G_ordering;
    int        State;
} attr_state_t;

static void
setState (graph_t* auxg, attr_state_t* attr_state)
{
    /* save state */
    attr_state->E_constr = E_constr;
    attr_state->E_samehead = E_samehead;
    attr_state->E_sametail = E_sametail;
    attr_state->E_weight = E_weight;
    attr_state->E_minlen = E_minlen;
    attr_state->E_fontcolor = E_fontcolor;
    attr_state->E_fontname = E_fontname;
    attr_state->E_fontsize = E_fontsize;
    attr_state->E_headclip = E_headclip;
    attr_state->E_headlabel = E_headlabel;
    attr_state->E_label = E_label;
    attr_state->E_label_float = E_label_float;
    attr_state->E_labelfontcolor = E_labelfontcolor;
    attr_state->E_labelfontname = E_labelfontname;
    attr_state->E_labelfontsize = E_labelfontsize;
    attr_state->E_tailclip = E_tailclip;
    attr_state->E_taillabel = E_taillabel;
    attr_state->E_xlabel = E_xlabel;
    attr_state->N_height = N_height;
    attr_state->N_width = N_width;
    attr_state->N_shape = N_shape;
    attr_state->N_style = N_style;
    attr_state->N_fontsize = N_fontsize;
    attr_state->N_fontname = N_fontname;
    attr_state->N_fontcolor = N_fontcolor;
    attr_state->N_label = N_label;
    attr_state->N_xlabel = N_xlabel;
    attr_state->N_showboxes = N_showboxes;
    attr_state->N_ordering = N_ordering;
    attr_state->N_sides = N_sides;
    attr_state->N_peripheries = N_peripheries;
    attr_state->N_skew = N_skew;
    attr_state->N_orientation = N_orientation;
    attr_state->N_distortion = N_distortion;
    attr_state->N_fixed = N_fixed;
    attr_state->N_nojustify = N_nojustify;
    attr_state->N_group = N_group;
    attr_state->State = State;
    attr_state->G_ordering = G_ordering;

    E_constr = NULL;
    E_samehead = agattr(auxg,2, "samehead", NULL);
    E_sametail = agattr(auxg,2, "sametail", NULL);
    E_weight = agattr(auxg,2, "weight", NULL);
    if (!E_weight)
	E_weight = agattr (auxg,2,"weight", "");
    E_minlen = NULL;
    E_fontcolor = NULL;
    E_fontname = (agattr(auxg,2,"fontname",NULL));
    E_fontsize = (agattr(auxg,2,"fontsize",NULL));
    E_headclip = (agattr(auxg,2,"headclip",NULL));
    E_headlabel = NULL;
    E_label = (agattr(auxg,2,"label",NULL));
    E_label_float = (agattr(auxg,2,"label_float",NULL));
    E_labelfontcolor = NULL;
    E_labelfontname = (agattr(auxg,2,"labelfontname",NULL));
    E_labelfontsize = (agattr(auxg,2,"labelfontsize",NULL));
    E_tailclip = (agattr(auxg,2,"tailclip",NULL));
    E_taillabel = NULL;
    E_xlabel = NULL;
    N_height = (agattr(auxg,1,"height",NULL));
    N_width = (agattr(auxg,1,"width",NULL));
    N_shape = (agattr(auxg,1,"shape",NULL));
    N_style = NULL;
    N_fontsize = (agattr(auxg,1,"fontsize",NULL));
    N_fontname = (agattr(auxg,1,"fontname",NULL));
    N_fontcolor = NULL;
    N_label = (agattr(auxg,1,"label",NULL));
    N_xlabel = NULL;
    N_showboxes = NULL;
    N_ordering = (agattr(auxg,1,"ordering",NULL));
    N_sides = (agattr(auxg,1,"sides",NULL));
    N_peripheries = (agattr(auxg,1,"peripheries",NULL));
    N_skew = (agattr(auxg,1,"skew",NULL));
    N_orientation = (agattr(auxg,1,"orientation",NULL));
    N_distortion = (agattr(auxg,1,"distortion",NULL));
    N_fixed = (agattr(auxg,1,"fixed",NULL));
    N_nojustify = NULL;
    N_group = NULL;
    G_ordering = (agattr(auxg,0,"ordering",NULL));
}

/* cloneGraph:
 * Create clone graph. It stores the global Agsyms, to be
 * restored in cleanupCloneGraph. The graph uses the main
 * graph's settings for certain geometry parameters, and
 * declares all node and edge attributes used in the original
 * graph.
 */
static graph_t*
cloneGraph (graph_t* g, attr_state_t* attr_state)
{
    Agsym_t* sym;
    graph_t* auxg;
    if (agisdirected(g))
	auxg = agopen ("auxg",Agdirected, ((Agdisc_t *)0));
    else
	auxg = agopen ("auxg",Agundirected, ((Agdisc_t *)0));
    agbindrec(auxg, "Agraphinfo_t", sizeof(Agraphinfo_t), (!(0)));
    agattr(auxg, 0, "rank", "");
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->drawing) = (layout_t*)zmalloc(sizeof(layout_t));
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->drawing)->quantum = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->quantum; 
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->drawing)->dpi = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->dpi;

    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->charset) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->charset);
    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1))
	((((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->rankdir) = 0);
    else
	((((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->rankdir) = 1);
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->nodesep) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nodesep);
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->ranksep) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->ranksep);

	//copy node attrs to auxg
    sym=agnxtattr(agroot(g),1,NULL); //get the first attr.
    for (; sym; sym = agnxtattr(agroot(g),1,sym))
	agattr (auxg, 1,sym->name, sym->defval);

	//copy edge attributes
    sym=agnxtattr(agroot(g),2,NULL); //get the first attr.
    for (; sym; sym = agnxtattr(agroot(g),2,sym))
	agattr (auxg, 2,sym->name, sym->defval);

    if (!agattr(auxg,2, "headport", NULL))
	agattr(auxg,2, "headport", "");
    if (!agattr(auxg,2, "tailport", NULL))
	agattr(auxg,2, "tailport", "");

    setState (auxg, attr_state);

    return auxg;
}

/* cleanupCloneGraph:
 */
static void
cleanupCloneGraph (graph_t* g, attr_state_t* attr_state)
{
    /* restore main graph syms */
    E_constr = attr_state->E_constr;
    E_samehead = attr_state->E_samehead;
    E_sametail = attr_state->E_sametail;
    E_weight = attr_state->E_weight;
    E_minlen = attr_state->E_minlen;
    E_fontcolor = attr_state->E_fontcolor;
    E_fontname = attr_state->E_fontname;
    E_fontsize = attr_state->E_fontsize;
    E_headclip = attr_state->E_headclip;
    E_headlabel = attr_state->E_headlabel;
    E_label = attr_state->E_label;
    E_label_float = attr_state->E_label_float;
    E_labelfontcolor = attr_state->E_labelfontcolor;
    E_labelfontname = attr_state->E_labelfontname;
    E_labelfontsize = attr_state->E_labelfontsize;
    E_tailclip = attr_state->E_tailclip;
    E_taillabel = attr_state->E_taillabel;
    E_xlabel = attr_state->E_xlabel;
    N_height = attr_state->N_height;
    N_width = attr_state->N_width;
    N_shape = attr_state->N_shape;
    N_style = attr_state->N_style;
    N_fontsize = attr_state->N_fontsize;
    N_fontname = attr_state->N_fontname;
    N_fontcolor = attr_state->N_fontcolor;
    N_label = attr_state->N_label;
    N_xlabel = attr_state->N_xlabel;
    N_showboxes = attr_state->N_showboxes;
    N_ordering = attr_state->N_ordering;
    N_sides = attr_state->N_sides;
    N_peripheries = attr_state->N_peripheries;
    N_skew = attr_state->N_skew;
    N_orientation = attr_state->N_orientation;
    N_distortion = attr_state->N_distortion;
    N_fixed = attr_state->N_fixed;
    N_nojustify = attr_state->N_nojustify;
    N_group = attr_state->N_group;
    G_ordering = attr_state->G_ordering;
    State = attr_state->State;

    free (attr_state);
    dot_cleanup(g);
    agclose(g);
}

/* cloneNode:
 * If flipped is true, original graph has rankdir=LR or RL.
 * In this case, records change shape, so we wrap a record node's
 * label in "{...}" to prevent this.
 */
static node_t*
cloneNode (graph_t* g, node_t* orign, int flipped)
{
    node_t* n = agnode(g, agnameof(orign),1);
    agbindrec(n, "Agnodeinfo_t", sizeof(Agnodeinfo_t), (!(0)));
    agcopyattr (orign, n);
    if (shapeOf(orign) == SH_RECORD) {
	int lbllen = strlen((((Agnodeinfo_t*)(((Agobj_t*)(orign))->data))->label)->text);
        char* buf = (char*)gmalloc((lbllen+3)*sizeof(char));
        sprintf (buf, "{%s}", (((Agnodeinfo_t*)(((Agobj_t*)(orign))->data))->label)->text);
	agset (n, "label", buf);
    }

    return n;
}

/* cloneEdge:
 */
static edge_t*
cloneEdge (graph_t* g, node_t* tn, node_t* hn, edge_t* orig)
{
    edge_t* e = agedge(g, tn, hn,NULL,1);
    /* for (; ED_edge_type(orig) != NORMAL; orig = ED_to_orig(orig)); */
    agbindrec(e, "Agedgeinfo_t", sizeof(Agedgeinfo_t), (!(0)));
    agcopyattr (orig, e);
/*
    if (orig->tail != ND_alg(tn)) {
	char* hdport = agget (orig, HEAD_ID);
	char* tlport = agget (orig, TAIL_ID);
	agset (e, TAIL_ID, (hdport ? hdport : ""));
	agset (e, HEAD_ID, (tlport ? tlport : ""));
    }
*/

    return e;
}

/* transformf:
 * Rotate, if necessary, then translate points.
 */
static pointf
transformf (pointf p, pointf del, int flip)
{
    if (flip) {
	double i = p.x;
	p.x = p.y;
	p.y = -i;
    }
    return add_pointf(p, del);
}

/* edgelblcmpfn:
 * lexicographically order edges by
 *  - has label
 *  - label is wider
 *  - label is higher
 */
static int edgelblcmpfn(edge_t** ptr0, edge_t** ptr1)
{
    edge_t *e0, *e1;
    pointf sz0, sz1;

    e0 = (edge_t *) * ptr0;
    e1 = (edge_t *) * ptr1;

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->label)) {
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label)) {
	    sz0 = (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->label)->dimen;
	    sz1 = (((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label)->dimen;
	    if (sz0.x > sz1.x) return -1;
	    else if (sz0.x < sz1.x) return 1;
	    else if (sz0.y > sz1.y) return -1;
	    else if (sz0.y < sz1.y) return 1;
	    else return 0;
	}
	else
	    return -1;
    }
    else if ((((Agedgeinfo_t*)(((Agobj_t*)(e1))->data))->label)) {
 	return 1;
    }
    else
 	return 0;
}



/* makeSimpleFlatLabels:
 * This handles the second simplest case for flat edges between
 * two adjacent nodes. We still invoke a dot on a rotated problem
 * to handle edges with ports. This usually works, but fails for
 * records because of their weird nature.
 */
static void
makeSimpleFlatLabels (node_t* tn, node_t* hn, edge_t** edges, int ind, int cnt, int et, int n_lbls)
{
    pointf *ps;
    Ppoly_t poly;
    int pn;
    edge_t* e = edges[ind];
    pointf points[10], tp, hp;
    int i, pointn;
    double leftend, rightend, ctrx, ctry, miny, maxy;
    double uminx, umaxx;
    double lminx, lmaxx;

    edge_t** earray = (edge_t**)zmalloc((cnt)*sizeof(edge_t*));

    for (i = 0; i < cnt; i++) {
	earray[i] = edges[ind + i];
    }

    qsort (earray, cnt, sizeof(edge_t*), (qsort_cmpf) edgelblcmpfn);

    tp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
    hp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);

    leftend = tp.x+(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rw);
    rightend = hp.x-(((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->lw);
    ctrx = (leftend + rightend)/2.0;
    
    /* do first edge */
    e = earray[0];
    pointn = 0;
    points[pointn++] = tp;
    points[pointn++] = tp;
    points[pointn++] = hp;
    points[pointn++] = hp;
    clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, &sinfo);
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = ctrx;
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = tp.y + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y+6)/2.0;
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));

    miny = tp.y + 6/2.0;
    maxy = miny + (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
    uminx = ctrx - ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x)/2.0;
    umaxx = ctrx + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x)/2.0;

    for (i = 1; i < n_lbls; i++) {
	e = earray[i];
	if (i%2) {  /* down */
	    if (i == 1) {
		lminx = ctrx - ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x)/2.0;
		lmaxx = ctrx + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.x)/2.0;
	    }
	    miny -= 6 + (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y;
	    points[0] = tp;
	    points[1].x = tp.x;
	    points[1].y = miny - 6;
	    points[2].x = hp.x;
	    points[2].y = points[1].y;
	    points[3] = hp;
	    points[4].x = lmaxx;
	    points[4].y = hp.y;
	    points[5].x = lmaxx;
	    points[5].y = miny;
	    points[6].x = lminx;
	    points[6].y = miny;
	    points[7].x = lminx;
	    points[7].y = tp.y;
	    ctry = miny + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y)/2.0;
	}
	else {   /* up */
	    points[0] = tp;
	    points[1].x = uminx;
	    points[1].y = tp.y;
	    points[2].x = uminx;
	    points[2].y = maxy;
	    points[3].x = umaxx;
	    points[3].y = maxy;
	    points[4].x = umaxx;
	    points[4].y = hp.y;
	    points[5].x = hp.x;
	    points[5].y = hp.y;
	    points[6].x = hp.x;
	    points[6].y = maxy + 6;
	    points[7].x = tp.x;
	    points[7].y = maxy + 6;
	    ctry =  maxy + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y)/2.0 + 6;
	    maxy += (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y + 6;
	}
	poly.pn = 8;
	poly.ps = (Ppoint_t*)points;
	ps = simpleSplineRoute (tp, hp, poly, &pn, et == (3 << 1));
	if (pn == 0) return;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x = ctrx;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y = ctry;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ps, pn, &sinfo);
    }

    /* edges with no labels */
    for (; i < cnt; i++) {
	e = earray[i];
	if (i%2) {  /* down */
	    if (i == 1) {
		lminx = (2*leftend + rightend)/3.0;
		lmaxx = (leftend + 2*rightend)/3.0;
	    }
	    miny -= 6;
	    points[0] = tp;
	    points[1].x = tp.x;
	    points[1].y = miny - 6;
	    points[2].x = hp.x;
	    points[2].y = points[1].y;
	    points[3] = hp;
	    points[4].x = lmaxx;
	    points[4].y = hp.y;
	    points[5].x = lmaxx;
	    points[5].y = miny;
	    points[6].x = lminx;
	    points[6].y = miny;
	    points[7].x = lminx;
	    points[7].y = tp.y;
	}
	else {   /* up */
	    points[0] = tp;
	    points[1].x = uminx;
	    points[1].y = tp.y;
	    points[2].x = uminx;
	    points[2].y = maxy;
	    points[3].x = umaxx;
	    points[3].y = maxy;
	    points[4].x = umaxx;
	    points[4].y = hp.y;
	    points[5].x = hp.x;
	    points[5].y = hp.y;
	    points[6].x = hp.x;
	    points[6].y = maxy + 6;
	    points[7].x = tp.x;
	    points[7].y = maxy + 6;
	    maxy += + 6;
	}
	poly.pn = 8;
	poly.ps = (Ppoint_t*)points;
	ps = simpleSplineRoute (tp, hp, poly, &pn, et == (3 << 1));
	if (pn == 0) return;
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ps, pn, &sinfo);
    }
   
    free (earray);
}

/* makeSimpleFlat:
 */
static void
makeSimpleFlat (node_t* tn, node_t* hn, edge_t** edges, int ind, int cnt, int et)
{
    edge_t* e = edges[ind];
    pointf points[10], tp, hp;
    int i, pointn;
    double stepy, dy;

    tp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
    hp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);

    stepy = (cnt > 1) ? (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->ht) / (double)(cnt - 1) : 0.;
    dy = tp.y - ((cnt > 1) ? (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->ht) / 2. : 0.);

    for (i = 0; i < cnt; i++) {
	e = edges[ind + i];
	pointn = 0;
	if ((et == (5 << 1)) || (et == (1 << 1))) {
	    points[pointn++] = tp;
	    points[pointn++] = pointfof((2 * tp.x + hp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * hp.x + tp.x) / 3, dy);
	    points[pointn++] = hp;
	}
	else {   /* ET_PLINE */
	    points[pointn++] = tp;
	    points[pointn++] = tp;
	    points[pointn++] = pointfof((2 * tp.x + hp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * tp.x + hp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * tp.x + hp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * hp.x + tp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * hp.x + tp.x) / 3, dy);
	    points[pointn++] = pointfof((2 * hp.x + tp.x) / 3, dy);
	    points[pointn++] = hp;
	    points[pointn++] = hp;
	}
	dy += stepy;
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), points, pointn, &sinfo);
    }
}

/* make_flat_adj_edges:
 * In the simple case, with no labels or ports, this creates a simple
 * spindle of splines.
 * If there are only labels, cobble something together.
 * Otherwise, we run dot recursively on the 2 nodes and the edges, 
 * essentially using rankdir=LR, to get the needed spline info.
 * This is probably to cute and fragile, and should be rewritten in a 
 * more straightforward and laborious fashion. 
 */
static void
make_flat_adj_edges(graph_t* g, path* P, edge_t** edges, int ind, int cnt, edge_t* e0,
                    int et)
{
    node_t* n;
    node_t *tn, *hn;
    edge_t* e;
    int labels = 0, ports = 0;
    graph_t* auxg;
    graph_t* subg;
    node_t *auxt, *auxh;
    edge_t* auxe;
    int     i, j, midx, midy, leftx, rightx;
    pointf   del;
    edge_t* hvye = NULL;
    attr_state_t* attrs;

    tn = ((((((Agobj_t*)(e0))->tag).objtype) == 3? (e0): ((e0)+1))->node), hn = ((((((Agobj_t*)(e0))->tag).objtype) == 2? (e0): ((e0)-1))->node);
    for (i = 0; i < cnt; i++) {
	e = edges[ind + i];
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) labels++;
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).defined || (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).defined) ports = 1;
    }

    if (ports == 0) {
	/* flat edges without ports and labels can go straight left to right */
	if (labels == 0) {
	    makeSimpleFlat (tn, hn, edges, ind, cnt, et);
	}
	/* flat edges without ports but with labels take more work */
	else {
	    makeSimpleFlatLabels (tn, hn, edges, ind, cnt, et, labels);
	}
	return;
    }

    attrs = (attr_state_t*)zmalloc(sizeof(attr_state_t));
    auxg = cloneGraph (g, attrs);
    subg = agsubg (auxg, "xxx",1);
    agbindrec(subg, "Agraphinfo_t", sizeof(Agraphinfo_t), (!(0)));
    agset (subg, "rank", "source");
    rightx = (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).x;
    leftx = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).x;
    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) {
        node_t* n;
        n = tn;
        tn = hn;
        hn = n;
    }
    auxt = cloneNode(subg, tn, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)); 
    auxh = cloneNode(auxg, hn, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)); 
    for (i = 0; i < cnt; i++) {
	e = edges[ind + i];
	for (; (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0; e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig));
	if (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) == tn)
	    auxe = cloneEdge (auxg, auxt, auxh, e);
	else
	    auxe = cloneEdge (auxg, auxh, auxt, e);
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->alg) = auxe;
	if (!hvye && !(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).defined && !(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).defined) {
	    hvye = auxe;
	    (((Agedgeinfo_t*)(((Agobj_t*)(hvye))->data))->alg) = e;
	}
    }
    if (!hvye) {
	hvye = agedge (auxg, auxt, auxh,NULL,1);
    }
    agxset (hvye, E_weight, "10000");
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->gvc) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->gvc);
    (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->dotroot) = auxg;
    setEdgeType (auxg, et);
    dot_init_node_edge(auxg);

    dot_rank(auxg, 0);
    dot_mincross(auxg, 0);
    dot_position(auxg, 0);
    
    /* reposition */
    midx = ((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rw) + (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->lw))/2;
    midy = ((((Agnodeinfo_t*)(((Agobj_t*)(auxt))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(auxh))->data))->coord).x)/2;
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(auxg))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	if (n == auxt) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y = rightx;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x = midy;
	}
	else if (n == auxh) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y = leftx;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x = midy;
	}
	else (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y = midx;
    }
    dot_sameports(auxg);
    _dot_splines(auxg, 0);
    dotneato_postprocess(auxg);

       /* copy splines */
    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) {
	del.x = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(auxt))->data))->coord).y;
	del.y = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y + (((Agnodeinfo_t*)(((Agobj_t*)(auxt))->data))->coord).x;
    }
    else {
	del.x = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(auxt))->data))->coord).x;
	del.y = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y - (((Agnodeinfo_t*)(((Agobj_t*)(auxt))->data))->coord).y;
    }
    for (i = 0; i < cnt; i++) {
	bezier* auxbz;
	bezier* bz;

	e = edges[ind + i];
	for (; (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0; e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig));
	auxe = (edge_t*)(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->alg);
	if ((auxe == hvye) & !(((Agedgeinfo_t*)(((Agobj_t*)(auxe))->data))->alg)) continue; /* pseudo-edge */
	auxbz = (((Agedgeinfo_t*)(((Agobj_t*)(auxe))->data))->spl)->list;
	bz = new_spline(e, auxbz->size);
	bz->sflag = auxbz->sflag;
	bz->sp = transformf(auxbz->sp, del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	bz->eflag = auxbz->eflag;
	bz->ep = transformf(auxbz->ep, del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	for (j = 0; j <  auxbz->size; ) {
	    pointf cp[4];
	    cp[0] = bz->list[j] = transformf(auxbz->list[j], del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	    j++;
	    if ( j >= auxbz->size ) 
		break;
	    cp[1] = bz->list[j] = transformf(auxbz->list[j], del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	    j++;
	    cp[2] = bz->list[j] = transformf(auxbz->list[j], del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	    j++;
	    cp[3] = transformf(auxbz->list[j], del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	    update_bb_bz(&(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb), cp);
        }
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos = transformf((((Agedgeinfo_t*)(((Agobj_t*)(auxe))->data))->label)->pos, del, ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1));
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));
	    updateBB(g, (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label));
	}
    }

    cleanupCloneGraph (auxg, attrs);
}

/* makeFlatEnd;
 */
static void
makeFlatEnd (graph_t* g, spline_info_t* sp, path* P, node_t* n, edge_t* e, pathend_t* endp,
             boolean isBegin)
{
    boxf b;

    b = endp->nb = maximal_bbox(g, sp, n, NULL, e);
    endp->sidemask = (1<<2);
    if (isBegin) beginpath(P, e, 2, endp, 0);
    else endpath(P, e, 2, endp, 0);
    b.UR.y = endp->boxes[endp->boxn - 1].UR.y;
    b.LL.y = endp->boxes[endp->boxn - 1].LL.y;
    b = makeregularend(b, (1<<2), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)].ht2);
    if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	endp->boxes[endp->boxn++] = b;
}
/* makeBottomFlatEnd;
 */
static void
makeBottomFlatEnd (graph_t* g, spline_info_t* sp, path* P, node_t* n, edge_t* e, 
	pathend_t* endp, boolean isBegin)
{
    boxf b;

    b = endp->nb = maximal_bbox(g, sp, n, NULL, e);
    endp->sidemask = (1<<0);
    if (isBegin) beginpath(P, e, 2, endp, 0);
    else endpath(P, e, 2, endp, 0);
    b.UR.y = endp->boxes[endp->boxn - 1].UR.y;
    b.LL.y = endp->boxes[endp->boxn - 1].LL.y;
    b = makeregularend(b, (1<<0), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)].ht2);
    if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	endp->boxes[endp->boxn++] = b;
}


/* make_flat_labeled_edge:
 */
static void
make_flat_labeled_edge(graph_t* g, spline_info_t* sp, path* P, edge_t* e, int et)
{
    node_t *tn, *hn, *ln;
    pointf *ps;
    pathend_t tend, hend;
    boxf lb;
    int boxn, i, pn, ydelta;
    edge_t *f;
    pointf points[7];

    tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);

    for (f = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt); (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_virt); f = (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_virt));
    ln = ((((((Agobj_t*)(f))->tag).objtype) == 3? (f): ((f)+1))->node);
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos = (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->coord);
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set = (!(0));

    if (et == (1 << 1)) {
	pointf startp, endp, lp;

	startp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
	endp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);

        lp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos;
	lp.y -= ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen.y)/2.0;
	points[1] = points[0] = startp;
	points[2] = points[3] = points[4] = lp;
	points[5] = points[6] = endp;
	ps = points;
	pn = 7;
    }
    else {
	lb.LL.x = (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->lw);
	lb.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->rw);
	lb.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->coord).y + (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->ht)/2;
	ydelta = (((Agnodeinfo_t*)(((Agobj_t*)(ln))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)].ht1 -
		(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)].ht2;
	ydelta /= 6.;
	lb.LL.y = lb.UR.y - ((5.)>(ydelta)?(5.):(ydelta)); 

	boxn = 0;
	makeFlatEnd (g, sp, P, tn, e, &tend, (!(0)));
	makeFlatEnd (g, sp, P, hn, e, &hend, 0);

	boxes[boxn].LL.x = tend.boxes[tend.boxn - 1].LL.x; 
	boxes[boxn].LL.y = tend.boxes[tend.boxn - 1].UR.y; 
	boxes[boxn].UR.x = lb.LL.x;
	boxes[boxn].UR.y = lb.LL.y;
	boxn++;
	boxes[boxn].LL.x = tend.boxes[tend.boxn - 1].LL.x; 
	boxes[boxn].LL.y = lb.LL.y;
	boxes[boxn].UR.x = hend.boxes[hend.boxn - 1].UR.x;
	boxes[boxn].UR.y = lb.UR.y;
	boxn++;
	boxes[boxn].LL.x = lb.UR.x;
	boxes[boxn].UR.y = lb.LL.y;
	boxes[boxn].LL.y = hend.boxes[hend.boxn - 1].UR.y; 
	boxes[boxn].UR.x = hend.boxes[hend.boxn - 1].UR.x;
	boxn++;

	for (i = 0; i < tend.boxn; i++) add_box(P, tend.boxes[i]);
	for (i = 0; i < boxn; i++) add_box(P, boxes[i]);
	for (i = hend.boxn - 1; i >= 0; i--) add_box(P, hend.boxes[i]);

	if (et == (5 << 1)) ps = routesplines(P, &pn);
	else ps = routepolylines(P, &pn);
	if (pn == 0) return;
    }
    clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ps, pn, &sinfo);
}

/* make_flat_bottom_edges:
 */
static void
make_flat_bottom_edges(graph_t* g, spline_info_t* sp, path * P, edge_t ** edges, int 
	ind, int cnt, edge_t* e, int splines)
{
    node_t *tn, *hn;
    int j, i, r;
    double stepx, stepy, vspace;
    rank_t* nextr;
    int pn;
    pointf *ps;
    pathend_t tend, hend;

    tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    r = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank);
    if (r < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank)) {
	nextr = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank) + (r+1);
	vspace = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].pht1 -
		((((Agnodeinfo_t*)(((Agobj_t*)(nextr->v[0]))->data))->coord).y + nextr->pht2);
    }
    else {
	vspace = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->ranksep);
    }
    stepx = ((double)(sp->Multisep)) / (cnt+1); 
    stepy = vspace / (cnt+1);

    makeBottomFlatEnd (g, sp, P, tn, e, &tend, (!(0)));
    makeBottomFlatEnd (g, sp, P, hn, e, &hend, 0);

    for (i = 0; i < cnt; i++) {
	int boxn;
	boxf b;
	e = edges[ind + i];
	boxn = 0;

	b = tend.boxes[tend.boxn - 1];
 	boxes[boxn].LL.x = b.LL.x; 
	boxes[boxn].UR.y = b.LL.y; 
	boxes[boxn].UR.x = b.UR.x + (i + 1) * stepx;
	boxes[boxn].LL.y = b.LL.y - (i + 1) * stepy;
	boxn++;
	boxes[boxn].LL.x = tend.boxes[tend.boxn - 1].LL.x; 
	boxes[boxn].UR.y = boxes[boxn-1].LL.y;
	boxes[boxn].UR.x = hend.boxes[hend.boxn - 1].UR.x;
	boxes[boxn].LL.y = boxes[boxn].UR.y - stepy;
	boxn++;
	b = hend.boxes[hend.boxn - 1];
	boxes[boxn].UR.x = b.UR.x;
	boxes[boxn].UR.y = b.LL.y;
	boxes[boxn].LL.x = b.LL.x - (i + 1) * stepx;
	boxes[boxn].LL.y = boxes[boxn-1].UR.y;
	boxn++;

	for (j = 0; j < tend.boxn; j++) add_box(P, tend.boxes[j]);
	for (j = 0; j < boxn; j++) add_box(P, boxes[j]);
	for (j = hend.boxn - 1; j >= 0; j--) add_box(P, hend.boxes[j]);

	if (splines) ps = routesplines(P, &pn);
	else ps = routepolylines(P, &pn);
	if (pn == 0)
	    return;
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ps, pn, &sinfo);
	P->nbox = 0;
    }
}

/* make_flat_edge:
 * Construct flat edges edges[ind...ind+cnt-1]
 * There are 4 main cases:
 *  - all edges between a and b where a and b are adjacent 
 *  - one labeled edge
 *  - all non-labeled edges with identical ports between non-adjacent a and b 
 *     = connecting bottom to bottom/left/right - route along bottom
 *     = the rest - route along top
 */
static void
make_flat_edge(graph_t* g, spline_info_t* sp, path * P, edge_t ** edges, int ind, int cnt, int et)
{
    node_t *tn, *hn;
    Agedgeinfo_t fwdedgei;
    Agedgepair_t fwdedge;
    edge_t *e;
    int j, i, r, isAdjacent;
    double stepx, stepy, vspace;
    int tside, hside, pn;
    pointf *ps;
    pathend_t tend, hend;

    fwdedge.out.base.data = (Agrec_t*)&fwdedgei;

    /* Get sample edge; normalize to go from left to right */
    e = edges[ind];
    isAdjacent = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->adjacent);
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tree_index) & 32) {
	{ edge_t *newp; Agedgeinfo_t *info; newp = &fwdedge.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)e->base.data; *newp = *e; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = e; };
	e = &fwdedge.out;
    }
    for (i = 1; i < cnt; i++) {
	if ((((Agedgeinfo_t*)(((Agobj_t*)(edges[ind+i]))->data))->adjacent)) {
	    isAdjacent = 1;
	    break;
	}
    }
    /* The lead edge edges[ind] might not have been marked earlier as adjacent,
     * so check them all.
     */
    if (isAdjacent) {
	make_flat_adj_edges (g, P, edges, ind, cnt, e, et);
	return;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {  /* edges with labels aren't multi-edges */
	make_flat_labeled_edge (g, sp, P, e, et);
	return;
    }

    if (et == (1 << 1)) {
	makeSimpleFlat (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), edges, ind, cnt, et);
	return;
    }

    tside = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).side;
    hside = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).side;
    if (((tside == (1<<0)) && (hside != (1<<2))) ||
        ((hside == (1<<0)) && (tside != (1<<2)))) {
	make_flat_bottom_edges (g, sp, P, edges, ind, cnt, e, et == (5 << 1));
	return;
    }

    tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    r = (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank);
    if (r > 0) {
	rank_t* prevr;
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_labels) & (1 << 0))
	    prevr = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank) + (r-2);
	else
	    prevr = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank) + (r-1);
	vspace = (((Agnodeinfo_t*)(((Agobj_t*)(prevr->v[0]))->data))->coord).y - prevr->ht1 - (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].ht2;
    }
    else {
	vspace = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->ranksep);
    }
    stepx = ((double)sp->Multisep) / (cnt+1); 
    stepy = vspace / (cnt+1);

    makeFlatEnd (g, sp, P, tn, e, &tend, (!(0)));
    makeFlatEnd (g, sp, P, hn, e, &hend, 0);

    for (i = 0; i < cnt; i++) {
	int boxn;
	boxf b;
	e = edges[ind + i];
	boxn = 0;

	b = tend.boxes[tend.boxn - 1];
 	boxes[boxn].LL.x = b.LL.x; 
	boxes[boxn].LL.y = b.UR.y; 
	boxes[boxn].UR.x = b.UR.x + (i + 1) * stepx;
	boxes[boxn].UR.y = b.UR.y + (i + 1) * stepy;
	boxn++;
	boxes[boxn].LL.x = tend.boxes[tend.boxn - 1].LL.x; 
	boxes[boxn].LL.y = boxes[boxn-1].UR.y;
	boxes[boxn].UR.x = hend.boxes[hend.boxn - 1].UR.x;
	boxes[boxn].UR.y = boxes[boxn].LL.y + stepy;
	boxn++;
	b = hend.boxes[hend.boxn - 1];
	boxes[boxn].UR.x = b.UR.x;
	boxes[boxn].LL.y = b.UR.y;
	boxes[boxn].LL.x = b.LL.x - (i + 1) * stepx;
	boxes[boxn].UR.y = boxes[boxn-1].LL.y;
	boxn++;

	for (j = 0; j < tend.boxn; j++) add_box(P, tend.boxes[j]);
	for (j = 0; j < boxn; j++) add_box(P, boxes[j]);
	for (j = hend.boxn - 1; j >= 0; j--) add_box(P, hend.boxes[j]);

	if (et == (5 << 1)) ps = routesplines(P, &pn);
	else ps = routepolylines(P, &pn);
	if (pn == 0)
	    return;
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ps, pn, &sinfo);
	P->nbox = 0;
    }
}

/* ccw:
 * Return true if p3 is to left of ray p1->p2
 */
static int
leftOf (pointf p1, pointf p2, pointf p3)
{
    int d;

    d = ((p1.y - p2.y) * (p3.x - p2.x)) -
        ((p3.y - p2.y) * (p1.x - p2.x));
    return (d > 0);
}

/* makeLineEdge:
 * Create an edge as line segment. We guarantee that the points
 * are always drawn downwards. This means that for flipped edges,
 * we draw from the head to the tail. The routine returns the
 * end node of the edge in *hp. The points are stored in the
 * given array of points, and the number of points is returned.
 *
 * If the edge has a label, the edge is draw as two segments, with
 * the bend near the label.
 *
 * If the endpoints are on adjacent ranks, revert to usual code by
 * returning 0.
 * This is done because the usual code handles the interaction of
 * multiple edges better.
 */
static int 
makeLineEdge(graph_t* g, edge_t* fe, pointf* points, node_t** hp)
{
    int delr, pn;
    node_t* hn;
    node_t* tn;
    edge_t* e = fe;
    pointf startp, endp, lp;
    pointf dimen;
    double width, height;

    while ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0)
	e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig);
    hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    delr = (((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)-(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)) >= 0 ? ((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)-(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)) : -((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)-(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)));
    if ((delr == 1) || ((delr == 2) && ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_labels) & (1 << 0))))
	return 0;
    if (((((((Agobj_t*)(fe))->tag).objtype) == 3? (fe): ((fe)+1))->node) == ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)) {
	*hp = hn;
	startp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
	endp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);
    }
    else {
 	*hp = tn; 
	startp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);
	endp = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
    }

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)) {
	dimen = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->dimen;
	if (((((Agraphinfo_t*)(((Agobj_t*)(agraphof(hn)))->data))->rankdir & 0x3) & 1)) {
	    width = dimen.y;
	    height = dimen.x;
	}
	else {
	    width = dimen.x;
	    height = dimen.y;
	}

	lp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos, lp;
	if (leftOf (endp,startp,lp)) {
	    lp.x += width/2.0;
	    lp.y -= height/2.0;
	}    
	else {
	    lp.x -= width/2.0;
	    lp.y += height/2.0;
	}

	points[1] = points[0] = startp;
	points[2] = points[3] = points[4] = lp;
	points[5] = points[6] = endp;
	pn = 7;
    }
    else {
	points[1] = points[0] = startp;
	points[3] = points[2] = endp;
	pn = 4;
    }

    return pn;
}



/* make_regular_edge:
 */
static void
make_regular_edge(graph_t* g, spline_info_t* sp, path * P, edge_t ** edges, int ind, int cnt, int et)
{
    node_t *tn, *hn;
    Agedgeinfo_t fwdedgeai, fwdedgebi, fwdedgei;
    Agedgepair_t fwdedgea, fwdedgeb, fwdedge;
    edge_t *e, *fe, *le, *segfirst;
    pointf *ps;
    pathend_t tend, hend;
    boxf b;
    int boxn, sl, si, smode, i, j, dx, pn, hackflag, longedge;
    static pointf* pointfs;
    static pointf* pointfs2;
    static int numpts;
    static int numpts2;
    int pointn;

    fwdedgea.out.base.data = (Agrec_t*)&fwdedgeai;
    fwdedgeb.out.base.data = (Agrec_t*)&fwdedgebi;
    fwdedge.out.base.data = (Agrec_t*)&fwdedgei;

    if (!pointfs) {
	pointfs = (pointf*)gmalloc((2000)*sizeof(pointf));
   	pointfs2 = (pointf*)gmalloc((2000)*sizeof(pointf));
	numpts = 2000;
	numpts2 = 2000;
    }
    sl = 0;
    e = edges[ind];
    hackflag = 0;
    if ((((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank)) >= 0 ? ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank)) : -((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank))) > 1) {
	fwdedgeai = *(Agedgeinfo_t*)e->base.data;
	fwdedgea.out = *e;
	fwdedgea.out.base.data = (Agrec_t*)&fwdedgeai;
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tree_index) & 32) {
	    { edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgeb.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)e->base.data; *newp = *e; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = e; };
	    ((((((Agobj_t*)(&fwdedgea.out))->tag).objtype) == 3? (&fwdedgea.out): ((&fwdedgea.out)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	    (((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port);
	} else {
	    fwdedgebi = *(Agedgeinfo_t*)e->base.data;
	    fwdedgeb.out = *e;
	    fwdedgeb.out.base.data = (Agrec_t*)&fwdedgebi;
	    ((((((Agobj_t*)(&fwdedgea.out))->tag).objtype) == 3? (&fwdedgea.out): ((&fwdedgea.out)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	}
	le = getmainedge(e);
	while ((((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_virt))
	    le = (((Agedgeinfo_t*)(((Agobj_t*)(le))->data))->to_virt);
	((((((Agobj_t*)(&fwdedgea.out))->tag).objtype) == 2? (&fwdedgea.out): ((&fwdedgea.out)-1))->node) = ((((((Agobj_t*)(le))->tag).objtype) == 2? (le): ((le)-1))->node);
	(((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->head_port).defined = 0;
	(((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->edge_type) = 1;
	(((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->head_port).p.x = (((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->head_port).p.y = 0;
	(((Agedgeinfo_t*)(((Agobj_t*)(&fwdedgea.out))->data))->to_orig) = e;
	e = &fwdedgea.out;
	hackflag = (!(0));
    } else {
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tree_index) & 32) {
	    { edge_t *newp; Agedgeinfo_t *info; newp = &fwdedgea.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)e->base.data; *newp = *e; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = e; };
	    e = &fwdedgea.out;
	}
    }
    fe = e;

    /* compute the spline points for the edge */

    if ((et == (1 << 1)) && (pointn = makeLineEdge (g, fe, pointfs, &hn))) {
    }
    else {
	int splines = et == (5 << 1);
	boxn = 0;
	pointn = 0;
	segfirst = e;
	tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	b = tend.nb = maximal_bbox(g, sp, tn, NULL, e);
	beginpath(P, e, 1, &tend, spline_merge(tn));
	b.UR.y = tend.boxes[tend.boxn - 1].UR.y;
	b.LL.y = tend.boxes[tend.boxn - 1].LL.y;
	b = makeregularend(b, (1<<0),
	    	   (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)].ht1);
	if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	    tend.boxes[tend.boxn++] = b;
	longedge = 0;
	smode = 0, si = -1;
	while ((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->node_type) == 1 && !sinfo.splineMerge(hn)) {
	    longedge = 1;
	    boxes[boxn++] = rank_box(sp, g, (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank));
	    if (!smode
	        && ((sl = straight_len(hn)) >=
	    	(((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_labels) & (1 << 0)) ? 4 + 1 : 2 + 1))) {
	        smode = (!(0));
	        si = 1, sl -= 2;
	    }
	    if (!smode || si > 0) {
	        si--;
	        boxes[boxn++] = maximal_bbox(g, sp, hn, e, (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->out).list[0]);
	        e = (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->out).list[0];
	        tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	        hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	        continue;
	    }
	    hend.nb = maximal_bbox(g, sp, hn, e, (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->out).list[0]);
	    endpath(P, e, 1, &hend, spline_merge(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	    b = makeregularend(hend.boxes[hend.boxn - 1], (1<<2),
	    	       (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)].ht2);
	    if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	        hend.boxes[hend.boxn++] = b;
	    P->end.theta = 3.14159265358979323846 / 2, P->end.constrained = (!(0));
	    completeregularpath(P, segfirst, e, &tend, &hend, boxes, boxn, 1);
	    if (splines) ps = routesplines(P, &pn);
	    else {
		ps = routepolylines (P, &pn);
		if ((et == (1 << 1)) && (pn > 4)) {
		    ps[1] = ps[0];
		    ps[3] = ps[2] = ps[pn-1];
		    pn = 4;
		}
	    }
	    if (pn == 0)
	        return;
	
	    if (pointn + pn > numpts) {
                /* This should be enough to include 3 extra points added by
                 * straight_path below.
                 */
		numpts = 2*(pointn+pn); 
		pointfs = ((pointf*)grealloc(pointfs,(numpts)*sizeof(pointf)));
	    }
	    for (i = 0; i < pn; i++) {
		pointfs[pointn++] = ps[i];
	    }
	    e = straight_path((((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->out).list[0], sl, pointfs, &pointn);
	    recover_slack(segfirst, P);
	    segfirst = e;
	    tn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	    hn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	    boxn = 0;
	    tend.nb = maximal_bbox(g, sp, tn, (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->in).list[0], e);
	    beginpath(P, e, 1, &tend, spline_merge(tn));
	    b = makeregularend(tend.boxes[tend.boxn - 1], (1<<0),
	    	       (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank)].ht1);
	    if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	        tend.boxes[tend.boxn++] = b;
	    P->start.theta = -3.14159265358979323846 / 2, P->start.constrained = (!(0));
	    smode = 0;
	}
	boxes[boxn++] = rank_box(sp, g, (((Agnodeinfo_t*)(((Agobj_t*)(tn))->data))->rank));
	b = hend.nb = maximal_bbox(g, sp, hn, e, NULL);
	endpath(P, hackflag ? &fwdedgeb.out : e, 1, &hend, spline_merge(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	b.UR.y = hend.boxes[hend.boxn - 1].UR.y;
	b.LL.y = hend.boxes[hend.boxn - 1].LL.y;
	b = makeregularend(b, (1<<2),
	    	   (((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(hn))->data))->rank)].ht2);
	if (b.LL.x < b.UR.x && b.LL.y < b.UR.y)
	    hend.boxes[hend.boxn++] = b;
	completeregularpath(P, segfirst, e, &tend, &hend, boxes, boxn,
	    		longedge);
	if (splines) ps = routesplines(P, &pn);
	else ps = routepolylines (P, &pn);
	if ((et == (1 << 1)) && (pn > 4)) {
	    /* Here we have used the polyline case to handle
	     * an edge between two nodes on adjacent ranks. If the
	     * results really is a polyline, straighten it.
	     */
	    ps[1] = ps[0];
	    ps[3] = ps[2] = ps[pn-1];
	    pn = 4;
        }
	if (pn == 0)
	    return;
	if (pointn + pn > numpts) {
	    numpts = 2*(pointn+pn); 
	    pointfs = ((pointf*)grealloc(pointfs,(numpts)*sizeof(pointf)));
	}
	for (i = 0; i < pn; i++) {
	    pointfs[pointn++] = ps[i];
	}
	recover_slack(segfirst, P);
	hn = hackflag ? ((((((Agobj_t*)(&fwdedgeb.out))->tag).objtype) == 2? (&fwdedgeb.out): ((&fwdedgeb.out)-1))->node) : ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
    }

    /* make copies of the spline points, one per multi-edge */

    if (cnt == 1) {
	clip_and_install(fe, hn, pointfs, pointn, &sinfo);
	return;
    }
    dx = sp->Multisep * (cnt - 1) / 2;
    for (i = 1; i < pointn - 1; i++)
	pointfs[i].x -= dx;

    if (numpts > numpts2) {
	numpts2 = numpts; 
	pointfs2 = ((pointf*)grealloc(pointfs2,(numpts2)*sizeof(pointf)));
    }
    for (i = 0; i < pointn; i++)
	pointfs2[i] = pointfs[i];
    clip_and_install(fe, hn, pointfs2, pointn, &sinfo);
    for (j = 1; j < cnt; j++) {
	e = edges[ind + j];
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tree_index) & 32) {
	    { edge_t *newp; Agedgeinfo_t *info; newp = &fwdedge.out; info = (Agedgeinfo_t*)newp->base.data; *info = *(Agedgeinfo_t*)e->base.data; *newp = *e; newp->base.data = (Agrec_t*)info; ((((((Agobj_t*)(newp))->tag).objtype) == 3? (newp): ((newp)+1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node); ((((((Agobj_t*)(newp))->tag).objtype) == 2? (newp): ((newp)-1))->node) = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->tail_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->head_port) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port); (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->edge_type) = 1; (((Agedgeinfo_t*)(((Agobj_t*)(newp))->data))->to_orig) = e; };
	    e = &fwdedge.out;
	}
	for (i = 1; i < pointn - 1; i++)
	    pointfs[i].x += sp->Multisep;
	for (i = 0; i < pointn; i++)
	    pointfs2[i] = pointfs[i];
	clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), pointfs2, pointn, &sinfo);
    }
}

/* regular edges */



static void
completeregularpath(path * P, edge_t * first, edge_t * last,
		    pathend_t * tendp, pathend_t * hendp, boxf * boxes,
		    int boxn, int flag)
{
    edge_t *uleft, *uright, *lleft, *lright;
    int i, fb, lb;
    splines *spl;
    pointf *pp;
    int pn;

    fb = lb = -1;
    uleft = uright = NULL;
    uleft = top_bound(first, -1), uright = top_bound(first, 1);
    if (uleft) {
	if (!(spl = getsplinepoints(uleft))) return;
	pp = spl->list[0].list;
       	pn = spl->list[0].size;
    }
    if (uright) {
	if (!(spl = getsplinepoints(uright))) return;
	pp = spl->list[0].list;
       	pn = spl->list[0].size;
    }
    lleft = lright = NULL;
    lleft = bot_bound(last, -1), lright = bot_bound(last, 1);
    if (lleft) {
	if (!(spl = getsplinepoints(lleft))) return;
	pp = spl->list[spl->size - 1].list;
       	pn = spl->list[spl->size - 1].size;
    }
    if (lright) {
	if (!(spl = getsplinepoints(lright))) return;
	pp = spl->list[spl->size - 1].list;
       	pn = spl->list[spl->size - 1].size;
    }
    for (i = 0; i < tendp->boxn; i++)
	add_box(P, tendp->boxes[i]);
    fb = P->nbox + 1;
    lb = fb + boxn - 3;
    for (i = 0; i < boxn; i++)
	add_box(P, boxes[i]);
    for (i = hendp->boxn - 1; i >= 0; i--)
	add_box(P, hendp->boxes[i]);
    adjustregularpath(P, fb, lb);
}


		       




		    
		    

    
    
    
    

    
    
    
	
    
    
    
	
    
		      
    
	
    
	
	    
	    
	    
		
		
		
	    
	    
	
	    
	    
	    
		
		
		
	    
	    
	
	
	    
	    
	
	
	    
    
	
	    
	
	
	
	    
	
	    
    
    
	
    



/* makeregularend:
 * Add box to fill between node and interrank space. Needed because
 * nodes in a given rank can differ in height.
 * for now, regular edges always go from top to bottom 
 */
static boxf makeregularend(boxf b, int side, double y)
{
    boxf newb;
    switch (side) {
    case (1<<0):
	newb = boxfof(b.LL.x, y, b.UR.x, b.LL.y);
	break;
    case (1<<2):
	newb = boxfof(b.LL.x, b.UR.y, b.UR.x, y);
	break;
    }
    return newb;
}










    
    
    
    
    
    

    
    
	
	
	
    
    
    
	
	
	
	
	    
    
    
    
    
	
	

	
	    

	
	    

	
	    
	
	    
	    
	    
	    
	    
		
	
	
	
    
    
	
	
	
	    
	    
	    
	    
	
	
			 
	
	    
			     
	    
	    
	
	
	
	    
    
    
	
	
	
	    
	    
	    
	    
	
	
			 
	
	    
			     
	    
	    
	
	
	
	    
    



/* adjustregularpath:
 * make sure the path is wide enough.
 * the % 2 was so that in rank boxes would only be grown if
 * they were == 0 while inter-rank boxes could be stretched to a min
 * width.
 * The list of boxes has three parts: tail boxes, path boxes, and head
 * boxes. (Note that because of back edges, the tail boxes might actually
 * belong to the head node, and vice versa.) fb is the index of the
 * first interrank path box and lb is the last interrank path box.
 * If fb > lb, there are none.
 *
 * The second for loop was added by ek long ago, and apparently is intended
 * to guarantee an overlap between adjacent boxes of at least MINW.
 * It doesn't do this, and the ifdef'ed part has the potential of moving 
 * a box within a node for more complex paths.
 */
static void adjustregularpath(path * P, int fb, int lb)
{
    boxf *bp1, *bp2;
    int i, x;

    for (i = fb-1; i < lb+1; i++) {
	bp1 = &P->boxes[i];
	if ((i - fb) % 2 == 0) {
	    if (bp1->LL.x >= bp1->UR.x) {
		x = (bp1->LL.x + bp1->UR.x) / 2;
		bp1->LL.x = x - 8, bp1->UR.x = x + 8;
	    }
	} else {
	    if (bp1->LL.x + 16 > bp1->UR.x) {
		x = (bp1->LL.x + bp1->UR.x) / 2;
		bp1->LL.x = x - 8, bp1->UR.x = x + 8;
	    }
	}
    }
    for (i = 0; i < P->nbox - 1; i++) {
	bp1 = &P->boxes[i], bp2 = &P->boxes[i + 1];
	if (i >= fb && i <= lb && (i - fb) % 2 == 0) {
	    if (bp1->LL.x + 16 > bp2->UR.x)
		bp2->UR.x = bp1->LL.x + 16;
	    if (bp1->UR.x - 16 < bp2->LL.x)
		bp2->LL.x = bp1->UR.x - 16;
	} else if (i + 1 >= fb && i < lb && (i + 1 - fb) % 2 == 0) {
	    if (bp1->LL.x + 16 > bp2->UR.x)
		bp1->LL.x = bp2->UR.x - 16;
	    if (bp1->UR.x - 16 < bp2->LL.x)
		bp1->UR.x = bp2->LL.x + 16;
	} 
    }
}

static boxf rank_box(spline_info_t* sp, graph_t * g, int r)
{
    boxf b;
    node_t /* *right0, *right1, */  * left0, *left1;

    b = sp->Rank_box[r];
    if (b.LL.x == b.UR.x) {
	left0 = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[0];
	/* right0 = GD_rank(g)[r].v[GD_rank(g)[r].n - 1]; */
	left1 = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].v[0];
	/* right1 = GD_rank(g)[r + 1].v[GD_rank(g)[r + 1].n - 1]; */
	b.LL.x = sp->LeftBound;
	b.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(left1))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].ht2;
	b.UR.x = sp->RightBound;
	b.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(left0))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].ht1;
	sp->Rank_box[r] = b;
    }
    return b;
}

/* returns count of vertically aligned edges starting at n */
static int straight_len(node_t * n)
{
    int cnt = 0;
    node_t *v;

    v = n;
    while (1) {
	v = ((((((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).list[0]))->tag).objtype) == 2? ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).list[0]): (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).list[0])-1))->node);
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) != 1)
	    break;
	if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).size != 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->in).size != 1))
	    break;
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->coord).x != (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x)
	    break;
	cnt++;
    }
    return cnt;
}

static edge_t *straight_path(edge_t * e, int cnt, pointf * plist, int *np)
{
    int n = *np;
    edge_t *f = e;

    while (cnt--)
	f = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 2?(f):((f)-1))->node)))->data))->out).list[0];
    plist[(*np)++] = plist[n - 1];
    plist[(*np)++] = plist[n - 1];
    plist[(*np)] = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 3?(f):((f)+1))->node)))->data))->coord);  /* will be overwritten by next spline */

    return f;
}

static void recover_slack(edge_t * e, path * p)
{
    int b;
    node_t *vn;

    b = 0;			/* skip first rank box */
    for (vn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	 (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->node_type) == 1 && !sinfo.splineMerge(vn);
	 vn = ((((((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->out).list[0]))->tag).objtype) == 2? ((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->out).list[0]): (((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->out).list[0])-1))->node)) {
	while ((b < p->nbox) && (p->boxes[b].LL.y > (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).y))
	    b++;
	if (b >= p->nbox)
	    break;
	if (p->boxes[b].UR.y < (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).y)
	    continue;
	if ((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->label))
	    resize_vn(vn, p->boxes[b].LL.x, p->boxes[b].UR.x,
		      p->boxes[b].UR.x + (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rw));
	else
	    resize_vn(vn, p->boxes[b].LL.x, (p->boxes[b].LL.x +
					     p->boxes[b].UR.x) / 2,
		      p->boxes[b].UR.x);
    }
}

static void resize_vn(vn, lx, cx, rx)
node_t *vn;
int lx, cx, rx;
{
    (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).x = cx;
    (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->lw) = cx - lx, (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rw) = rx - cx;
}

/* side > 0 means right. side < 0 means left */
static edge_t *top_bound(edge_t * e, int side)
{
    edge_t *f, *ans = NULL;
    int i;

    for (i = 0; (f = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->out).list[i]); i++) {

	
	    

	if (side * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 2?(f):((f)-1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order)) <= 0)
	    continue;
	if (((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->spl) == NULL)
	    && (((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_orig) == NULL) || ((((Agedgeinfo_t*)(((Agobj_t*)((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_orig)))->data))->spl) == NULL)))
	    continue;
	if ((ans == NULL)
	    || (side * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(ans))->tag).objtype) == 2?(ans):((ans)-1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 2?(f):((f)-1))->node)))->data))->order)) > 0))
	    ans = f;
    }
    return ans;
}

static edge_t *bot_bound(edge_t * e, int side)
{
    edge_t *f, *ans = NULL;
    int i;

    for (i = 0; (f = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->in).list[i]); i++) {

	
	    

	if (side * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 3?(f):((f)+1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order)) <= 0)
	    continue;
	if (((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->spl) == NULL)
	    && (((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_orig) == NULL) || ((((Agedgeinfo_t*)(((Agobj_t*)((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->to_orig)))->data))->spl) == NULL)))
	    continue;
	if ((ans == NULL)
	    || (side * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(ans))->tag).objtype) == 3?(ans):((ans)+1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 3?(f):((f)+1))->node)))->data))->order)) > 0))
	    ans = f;
    }
    return ans;
}

/* common routines */

static int cl_vninside(graph_t * cl, node_t * n)
{
    return (((((((Agraphinfo_t*)(((Agobj_t*)(cl))->data))->bb).LL.x) <= ((double)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x))) && (((double)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x)) <= ((((Agraphinfo_t*)(((Agobj_t*)(cl))->data))->bb).UR.x))) &&
	    ((((((Agraphinfo_t*)(((Agobj_t*)(cl))->data))->bb).LL.y) <= ((double)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y))) && (((double)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y)) <= ((((Agraphinfo_t*)(((Agobj_t*)(cl))->data))->bb).UR.y))));
}

/* All nodes belong to some cluster, which may be the root graph.
 * For the following, we only want a cluster if it is a real cluster
 * It is not clear this will handle all potential problems. It seems one
 * could have hcl and tcl contained in cl, which would also cause problems.
 */


/* returns the cluster of (adj) that interferes with n,
 */
static Agraph_t *cl_bound(graph_t* g,  node_t *n, node_t *adj)
{
    graph_t *rv, *cl, *tcl, *hcl;
    edge_t *orig;

    rv = NULL;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0)
	tcl = hcl = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust);
    else {
	orig = (((Agedgeinfo_t*)(((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[0]))->data))->to_orig);
	tcl = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 3?(orig):((orig)+1))->node)))->data))->clust);
	hcl = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 2?(orig):((orig)-1))->node)))->data))->clust);
    }
    if ((((Agnodeinfo_t*)(((Agobj_t*)(adj))->data))->node_type) == 0) {
	cl = ((((Agnodeinfo_t*)(((Agobj_t*)(adj))->data))->clust)==g?NULL:(((Agnodeinfo_t*)(((Agobj_t*)(adj))->data))->clust));
	if (cl && (cl != tcl) && (cl != hcl))
	    rv = cl;
    } else {
	orig = (((Agedgeinfo_t*)(((Agobj_t*)((((Agnodeinfo_t*)(((Agobj_t*)(adj))->data))->out).list[0]))->data))->to_orig);
	cl = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 3?(orig):((orig)+1))->node)))->data))->clust)==g?NULL:(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 3?(orig):((orig)+1))->node)))->data))->clust));
	if (cl && (cl != tcl) && (cl != hcl) && cl_vninside(cl, adj))
	    rv = cl;
	else {
	    cl = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 2?(orig):((orig)-1))->node)))->data))->clust)==g?NULL:(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(orig))->tag).objtype) == 2?(orig):((orig)-1))->node)))->data))->clust));
	    if (cl && (cl != tcl) && (cl != hcl) && cl_vninside(cl, adj))
		rv = cl;
	}
    }
    return rv;
}

/* maximal_bbox:
 * Return an initial bounding box to be used for building the
 * beginning or ending of the path of boxes.
 * Height reflects height of tallest node on rank.
 * The extra space provided by FUDGE allows begin/endpath to create a box
 * FUDGE-2 away from the node, so the routing can avoid the node and the
 * box is at least 2 wide.
 */


static boxf maximal_bbox(graph_t* g, spline_info_t* sp, node_t* vn, edge_t* ie, edge_t* oe)
{
    double b, nb;
    graph_t *left_cl, *right_cl;
    node_t *left, *right;
    boxf rv;

    left_cl = right_cl = NULL;

    /* give this node all the available space up to its neighbors */
    b = (double)((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->lw) - 4);
    if ((left = neighbor(g, vn, ie, oe, -1))) {
	if ((left_cl = cl_bound(g, vn, left)))
	    nb = (((Agraphinfo_t*)(((Agobj_t*)(left_cl))->data))->bb).UR.x + (double)(sp->Splinesep);
	else {
	    nb = (double)((((Agnodeinfo_t*)(((Agobj_t*)(left))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(left))->data))->mval));
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(left))->data))->node_type) == 0)
		nb += (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nodesep) / 2.;
	    else
		nb += (double)(sp->Splinesep);
	}
	if (nb < b)
	    b = nb;
	rv.LL.x = ((b>=0)?(int)(b + .5):(int)(b - .5));
    } else
	rv.LL.x = ((((b>=0)?(int)(b + .5):(int)(b - .5)))<(sp->LeftBound)?(((b>=0)?(int)(b + .5):(int)(b - .5))):(sp->LeftBound));

    /* we have to leave room for our own label! */
    if (((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->node_type) == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->label)))
	b = (double)((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).x + 10);
    else
	b = (double)((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).x + (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rw) + 4);
    if ((right = neighbor(g, vn, ie, oe, 1))) {
	if ((right_cl = cl_bound(g, vn, right)))
	    nb = (((Agraphinfo_t*)(((Agobj_t*)(right_cl))->data))->bb).LL.x - (double)(sp->Splinesep);
	else {
	    nb = (((Agnodeinfo_t*)(((Agobj_t*)(right))->data))->coord).x - (((Agnodeinfo_t*)(((Agobj_t*)(right))->data))->lw);
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(right))->data))->node_type) == 0)
		nb -= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nodesep) / 2.;
	    else
		nb -= (double)(sp->Splinesep);
	}
	if (nb > b)
	    b = nb;
	rv.UR.x = ((b>=0)?(int)(b + .5):(int)(b - .5));
    } else
	rv.UR.x = ((((b>=0)?(int)(b + .5):(int)(b - .5)))>(sp->RightBound)?(((b>=0)?(int)(b + .5):(int)(b - .5))):(sp->RightBound));

    if (((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->node_type) == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->label))) {
	rv.UR.x -= (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rw);
	if (rv.UR.x < rv.LL.x) rv.UR.x = (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).x;
    }

    rv.LL.y = (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).y - (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rank)].ht1;
    rv.UR.y = (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->coord).y + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rank)].ht2;
    return rv;
}

static node_t *
neighbor(graph_t* g, node_t *vn, edge_t *ie, edge_t *oe, int dir)
{
    int i;
    node_t *n, *rv = NULL;
    rank_t *rank = &((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->rank)]);

    for (i = (((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->order) + dir; ((i >= 0) && (i < rank->n)); i += dir) {
	n = rank->v[i];
	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->label))) {
	    rv = n;
	    break;
	}
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 0) {
	    rv = n;
	    break;
	}
	if (pathscross(n, vn, ie, oe) == 0) {
	    rv = n;
	    break;
	}
    }
    return rv;
}

static boolean pathscross(n0, n1, ie1, oe1)
node_t *n0, *n1;
edge_t *ie1, *oe1;
{
    edge_t *e0, *e1;
    node_t *na, *nb;
    int order, cnt;

    order = ((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(n1))->data))->order));
    if (((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).size != 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).size != 1))
	return 0;
    e1 = oe1;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).size == 1 && e1) {
	e0 = (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).list[0];
	for (cnt = 0; cnt < 2; cnt++) {
	    if ((na = ((((((Agobj_t*)(e0))->tag).objtype) == 2? (e0): ((e0)-1))->node)) == (nb = ((((((Agobj_t*)(e1))->tag).objtype) == 2? (e1): ((e1)-1))->node)))
		break;
	    if (order != ((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->order)))
		return (!(0));
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->out).size != 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->node_type) == 0))
		break;
	    e0 = (((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->out).list[0];
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->out).size != 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->node_type) == 0))
		break;
	    e1 = (((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->out).list[0];
	}
    }
    e1 = ie1;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->in).size == 1 && e1) {
	e0 = (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->in).list[0];
	for (cnt = 0; cnt < 2; cnt++) {
	    if ((na = ((((((Agobj_t*)(e0))->tag).objtype) == 3? (e0): ((e0)+1))->node)) == (nb = ((((((Agobj_t*)(e1))->tag).objtype) == 3? (e1): ((e1)+1))->node)))
		break;
	    if (order != ((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->order)))
		return (!(0));
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->in).size != 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->node_type) == 0))
		break;
	    e0 = (((Agnodeinfo_t*)(((Agobj_t*)(na))->data))->in).list[0];
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->in).size != 1) || ((((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->node_type) == 0))
		break;
	    e1 = (((Agnodeinfo_t*)(((Agobj_t*)(nb))->data))->in).list[0];
	}
    }
    return 0;
}




    
    

    
    
	
	
	
		
		
    
    


