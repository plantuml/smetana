#line 1 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 1
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



#line 1 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 1


#line 1 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 1
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






#line 1 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 1

















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








#line 20 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathplan.h" 1
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










    
    

    
	
    

    
    


    
	
	
    

    

    
	
    


    

    




#line 19 "graphviz-2.38.0\\lib\\pathplan\\pathplan.h" 2










/* find shortest euclidean path within a simple polygon */
    extern int Pshortestpath(Ppoly_t * boundary, Ppoint_t endpoints[2],
			     Ppolyline_t * output_route);

/* fit a spline to an input polyline, without touching barrier segments */
    extern int Proutespline(Pedge_t * barriers, int n_barriers,
			    Ppolyline_t input_route,
			    Pvector_t endpoint_slopes[2],
			    Ppolyline_t * output_route);

/* utility function to convert from a set of polygonal obstacles to barriers */
    extern int Ppolybarriers(Ppoly_t ** polys, int npolys,
			     Pedge_t ** barriers, int *n_barriers);

/* function to convert a polyline into a spline representation */
    extern void make_polyline(Ppolyline_t line, Ppolyline_t* sline);







#line 21 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\neatoprocs.h" 1
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







#line 1 "graphviz-2.38.0\\lib\\neatogen\\adjust.h" 1
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











    


































































#line 21 "graphviz-2.38.0\\lib\\neatogen\\adjust.h" 2
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


























#line 22 "graphviz-2.38.0\\lib\\neatogen\\adjust.h" 2



typedef enum {
    AM_NONE, AM_VOR,
    AM_SCALE, AM_NSCALE, AM_SCALEXY, AM_PUSH, AM_PUSHPULL,
    AM_ORTHO, AM_ORTHO_YX, AM_ORTHOXY, AM_ORTHOYX,
    AM_PORTHO, AM_PORTHO_YX, AM_PORTHOXY, AM_PORTHOYX, AM_COMPRESS,
    AM_VPSC, AM_IPSEP, AM_PRISM
} adjust_mode;

typedef struct {
    adjust_mode mode;
    char *print;
    int value;
    double scaling;
} adjust_data;

typedef struct {
    float x, y;
    boolean doAdd;  /* if true, x and y are in points */
} expand_t;

    extern expand_t sepFactor(graph_t * G);
    extern expand_t esepFactor(graph_t * G);
    extern int adjustNodes(graph_t * G);
    extern int normalize(graph_t * g);
    extern int removeOverlapAs(graph_t*, char*);
    extern int removeOverlapWith(graph_t*, adjust_data*);
    extern int cAdjust(graph_t *, int);
    extern int scAdjust(graph_t *, int);
    extern adjust_data *graphAdjustMode(graph_t *G, adjust_data*, char* dflt);
    extern double *getSizes(Agraph_t * g, pointf pad, int *n_elabels, int **elabels);
    extern SparseMatrix makeMatrix(Agraph_t* g, int dim, SparseMatrix *D);





#line 18 "graphviz-2.38.0\\lib\\neatogen\\neatoprocs.h" 2

    extern int allow_edits(int);
    extern void avoid_cycling(graph_t *, Agnode_t *, double *);
    extern int checkStart(graph_t * G, int nG, int);
    extern Agnode_t *choose_node(graph_t *, int);
    extern int circuit_model(graph_t *, int);
    extern void D2E(Agraph_t *, int, int, double *);
    extern void diffeq_model(graph_t *, int);
    extern double distvec(double *, double *, double *);
    extern void final_energy(graph_t *, int);
    extern double fpow32(double);
    extern Ppolyline_t getPath(edge_t *, vconfig_t *, int, Ppoly_t **,
			       int);
    extern void heapdown(Agnode_t *);
    extern void heapup(Agnode_t *);
    extern void initial_positions(graph_t *, int);
    extern int init_port(Agnode_t *, Agedge_t *, char *, boolean);
    extern void jitter3d(Agnode_t *, int);
    extern void jitter_d(Agnode_t *, int, int);
    extern Ppoly_t *makeObstacle(node_t * n, expand_t*, boolean );
    extern void makeSelfArcs(path * P, edge_t * e, int stepx);
    extern void makeSpline(graph_t*, edge_t *, Ppoly_t **, int, boolean);
    extern void make_spring(graph_t *, Agnode_t *, Agnode_t *, double);
    extern void move_node(graph_t *, int, Agnode_t *);
    extern int init_nop(graph_t * g, int);
    extern void neato_cleanup(graph_t * g);
    extern node_t *neato_dequeue(void);
    extern void neato_enqueue(node_t *);
    extern void neato_init_node(node_t * n);
    extern void neato_layout(Agraph_t * g);
    extern int Plegal_arrangement(Ppoly_t ** polys, int n_polys);
    extern void randompos(Agnode_t *, int);
    extern void s1(graph_t *, node_t *);
    extern int scan_graph(graph_t *);
    extern int scan_graph_mode(graph_t * G, int mode);
    extern void free_scan_graph(graph_t *);
    extern int setSeed (graph_t*, int dflt, long* seedp);
    extern void shortest_path(graph_t *, int);
    extern void solve(double *, double *, double *, int);
    extern void solve_model(graph_t *, int);
    extern int solveCircuit(int nG, double **Gm, double **Gm_inv);
    extern void spline_edges(Agraph_t *);
    extern void spline_edges0(Agraph_t *, boolean);
    extern int spline_edges1(graph_t * g, int);
    extern int splineEdges(graph_t *,
			   int (*edgefn) (graph_t *, expand_t*, int), int);
    extern boolean neato_set_aspect(graph_t * g);
    extern void toggle(int);
    extern int user_pos(Agsym_t *, Agsym_t *, Agnode_t *, int);
    extern double **new_array(int i, int j, double val);
    extern void free_array(double **rv);
    extern int matinv(double **A, double **Ainv, int n);






#line 22 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\adjust.h" 1
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
















    
    
    
    
    



    
    
    
    



    
    


    
    
    
    
    
    
    
    
    
    
    





#line 23 "graphviz-2.38.0\\lib\\neatogen\\neato.h" 2


#line 19 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\adjust.h" 1
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
















    
    
    
    
    



    
    
    
    



    
    


    
    
    
    
    
    
    
    
    
    
    





#line 20 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathplan.h" 1
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


















    
			     


    
			    
			    
			    


    
			     


    







#line 21 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\vispath.h" 1
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










    
    

    
	
    

    
    


    
	
	
    

    

    
	
    


    

    




#line 19 "graphviz-2.38.0\\lib\\pathplan\\vispath.h" 2









/* open a visibility graph 
 * Points in polygonal obstacles must be in clockwise order.
 */
    extern vconfig_t *Pobsopen(Ppoly_t ** obstacles, int n_obstacles);

/* close a visibility graph, freeing its storage */
    extern void Pobsclose(vconfig_t * config);

/* route a polyline from p0 to p1, avoiding obstacles.
 * if an endpoint is inside an obstacle, pass the polygon's index >=0
 * if the endpoint is not inside an obstacle, pass POLYID_NONE
 * if the endpoint location is not known, pass POLYID_UNKNOWN
 */

    extern int Pobspath(vconfig_t * config, Ppoint_t p0, int poly0,
			Ppoint_t p1, int poly1,
			Ppolyline_t * output_route);










#line 22 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\multispline.h" 1
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










































    
	
	
    

    









	
    
    
    
			  
    
    
    
    
    
    
			    
						
			    
    
    
    
    
	
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    








#line 17 "graphviz-2.38.0\\lib\\neatogen\\multispline.h" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathutil.h" 1
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







#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathplan.h" 1
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


















    
			     


    
			    
			    
			    


    
			     


    







#line 19 "graphviz-2.38.0\\lib\\pathplan\\pathutil.h" 2













/*visual studio*/





/*end visual studio*/
	typedef double COORD;
    extern COORD area2(Ppoint_t, Ppoint_t, Ppoint_t);
    extern int wind(Ppoint_t a, Ppoint_t b, Ppoint_t c);
    extern COORD dist2(Ppoint_t, Ppoint_t);
    extern int intersect(Ppoint_t a, Ppoint_t b, Ppoint_t c, Ppoint_t d);

    int in_poly(Ppoly_t argpoly, Ppoint_t q);
    Ppoly_t copypoly(Ppoly_t);
    void freepoly(Ppoly_t);






#line 18 "graphviz-2.38.0\\lib\\neatogen\\multispline.h" 2

typedef struct router_s router_t;

extern void freeRouter (router_t* rtr);
extern router_t* mkRouter (Ppoly_t** obs, int npoly);
extern int makeMultiSpline(graph_t* g, edge_t* e, router_t * rtr, int);


#line 23 "graphviz-2.38.0\\lib\\neatogen\\neatosplines.c" 2

extern double drand48(void);






extern void printvis(vconfig_t * cp);
extern int in_poly(Ppoly_t argpoly, Ppoint_t q);


static boolean spline_merge(node_t * n)
{
    return 0;
}

static boolean swap_ends_p(edge_t * e)
{
    return 0;
}

static splineInfo sinfo = { swap_ends_p, spline_merge };

static void
make_barriers(Ppoly_t ** poly, int npoly, int pp, int qp,
	      Pedge_t ** barriers, int *n_barriers)
{
    int i, j, k, n, b;
    Pedge_t *bar;

    n = 0;
    for (i = 0; i < npoly; i++) {
	if (i == pp)
	    continue;
	if (i == qp)
	    continue;
	n = n + poly[i]->pn;
    }
    bar = (Pedge_t*)gmalloc((n)*sizeof(Pedge_t));
    b = 0;
    for (i = 0; i < npoly; i++) {
	if (i == pp)
	    continue;
	if (i == qp)
	    continue;
	for (j = 0; j < poly[i]->pn; j++) {
	    k = j + 1;
	    if (k >= poly[i]->pn)
		k = 0;
	    bar[b].a = poly[i]->ps[j];
	    bar[b].b = poly[i]->ps[k];
	    b++;
	}
    }
    assert(b == n);
    *barriers = bar;
    *n_barriers = n;
}

/* genPt:
 */
static Ppoint_t genPt(double x, double y, pointf c)
{
    Ppoint_t p;

    p.x = x + c.x;
    p.y = y + c.y;
    return p;
}


/* recPt:
 */
static Ppoint_t recPt(double x, double y, pointf c, expand_t* m)
{
    Ppoint_t p;

    p.x = (x * m->x) + c.x;
    p.y = (y * m->y) + c.y;
    return p;
}

typedef struct {
    node_t *n1;
    pointf p1;
    node_t *n2;
    pointf p2;
} edgeinfo;
typedef struct {
    Dtlink_t link;
    edgeinfo id;
    edge_t *e;
} edgeitem;

static void *newitem(Dt_t * d, edgeitem * obj, Dtdisc_t * disc)
{
    edgeitem *newp;

    (void) disc;
    newp = (edgeitem*)zmalloc(sizeof(edgeitem));
    newp->id = obj->id;
    newp->e = obj->e;
    (((Agedgeinfo_t*)(((Agobj_t*)(newp->e))->data))->count) = 1;

    return newp;
}

static void freeitem(Dt_t * d, edgeitem * obj, Dtdisc_t * disc)
{
    free(obj);
}

static int
cmpitems(Dt_t * d, edgeinfo * key1, edgeinfo * key2, Dtdisc_t * disc)
{
    int x;

    if (key1->n1 > key2->n1)
	return 1;
    if (key1->n1 < key2->n1)
	return -1;
    if (key1->n2 > key2->n2)
	return 1;
    if (key1->n2 < key2->n2)
	return -1;

    if ((x = key1->p1.x - key2->p1.x))
	return x;
    if ((x = key1->p1.y - key2->p1.y))
	return x;
    if ((x = key1->p2.x - key2->p2.x))
	return x;
    return (key1->p2.y - key2->p2.y);
}

Dtdisc_t edgeItemDisc = {
    offsetof(edgeitem, id),
    sizeof(edgeinfo),
    offsetof(edgeitem, link),
    (Dtmake_f) newitem,
    (Dtfree_f) freeitem,
    (Dtcompar_f) cmpitems,
    0,
    0,
    0
};

/* equivEdge:
 * See if we have already encountered an edge between the same
 * node:port pairs. If so, return the earlier edge. If not, 
 * this edge is added to map and returned.
 * We first have to canonicalize the key fields using a lexicographic
 * ordering.
 */
static edge_t *equivEdge(Dt_t * map, edge_t * e)
{
    edgeinfo test;
    edgeitem dummy;
    edgeitem *ip;

    if (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) < ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)) {
	test.n1 = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	test.p1 = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
	test.n2 = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	test.p2 = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    } else if (((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node) > ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)) {
	test.n2 = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	test.p2 = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
	test.n1 = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	test.p1 = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
    } else {
	pointf hp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p;
	pointf tp = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p;
	if (tp.x < hp.x) {
	    test.p1 = tp;
	    test.p2 = hp;
	} else if (tp.x > hp.x) {
	    test.p1 = hp;
	    test.p2 = tp;
	} else if (tp.y < hp.y) {
	    test.p1 = tp;
	    test.p2 = hp;
	} else if (tp.y > hp.y) {
	    test.p1 = hp;
	    test.p2 = tp;
	} else {
	    test.p1 = test.p2 = tp;
	}
	test.n2 = test.n1 = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
    }
    dummy.id = test;
    dummy.e = e;
    ip = (*(((Dt_t*)(map))->searchf))((map),(void*)(&dummy),0000001);
    return ip->e;
}


/* makeSelfArcs:
 * Generate loops. We use the library routine makeSelfEdge
 * which also places the labels.
 * We have to handle port labels here.
 * as well as update the bbox from edge labels.
 */
void makeSelfArcs(path * P, edge_t * e, int stepx)
{
    int cnt = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->count);

    if ((cnt == 1) || Concentrate) {
	edge_t *edges1[1];
	edges1[0] = e;
	makeSelfEdge(P, edges1, 0, 1, stepx, stepx, &sinfo);
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label))
	    updateBB(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label));
	makePortLabels(e);
    } else {
	int i;
	edge_t **edges = (edge_t **)gmalloc((cnt)*sizeof(edge_t *));
	for (i = 0; i < cnt; i++) {
	    edges[i] = e;
	    e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt);
	}
	makeSelfEdge(P, edges, 0, cnt, stepx, stepx, &sinfo);
	for (i = 0; i < cnt; i++) {
	    e = edges[i];
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label))
		updateBB(agraphof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label));
	    makePortLabels(e);
	}
	free(edges);
    }
}

/* makeObstacle:
 * Given a node, return an obstacle reflecting the
 * node's geometry. pmargin specifies how much space to allow
 * around the polygon. 
 * Returns the constructed polygon on success, NULL on failure.
 * Failure means the node shape is not supported. 
 *
 * If isOrtho is true, we have to use the bounding box of each node.
 *
 * The polygon has its vertices in CW order.
 * 
 */
Ppoly_t *makeObstacle(node_t * n, expand_t* pmargin, boolean isOrtho)
{
    Ppoly_t *obs;
    polygon_t *poly;
    double adj = 0.0;
    int j, sides;
    pointf polyp;
    boxf b;
    pointf pt;
    field_t *fld;
    epsf_t *desc;
    int isPoly;
    pointf* verts;
    pointf vs[4];
    pointf p;
    pointf margin;

    switch (shapeOf(n)) {
    case SH_POLY:
    case SH_POINT:
	obs = (Ppoly_t*)zmalloc(sizeof(Ppoly_t));
	poly = (polygon_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
	if (isOrtho) {
	    isPoly = 1;
	    sides = 4;
	    verts = vs;
	    margin.x = margin.y = 0;
		/* For fixedshape, we can't use the width and height, as this includes
		 * the label. We only want to use the actual node shape.
		 */
	    if (poly->option & (1 << 11)) {
		b = polyBB (poly);
		vs[0] = b.LL;
		vs[1].x = b.UR.x;
		vs[1].y = b.LL.y;
		vs[2] = b.UR;
		vs[3].x = b.LL.x;
		vs[3].y = b.UR.y;
	    } else {
		p.x = -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
		p.y = -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2.0;
		vs[0] = p;
		p.x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
		vs[1] = p;
		p.y = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)/2.0;
		vs[2] = p;
		p.x = -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw);
		vs[3] = p;
	    }
	}
	else if (poly->sides >= 3) {
	    isPoly = 1;
	    sides = poly->sides;
	    verts = poly->vertices;
	    margin.x = pmargin->x;
	    margin.y = pmargin->y;
	} else {		/* ellipse */
	    isPoly = 0;
	    sides = 8;
	    adj = drand48() * .01;
	}
	obs->pn = sides;
	obs->ps = (Ppoint_t*)zmalloc((sides)*sizeof(Ppoint_t));
	/* assuming polys are in CCW order, and pathplan needs CW */
	for (j = 0; j < sides; j++) {
	    double xmargin = 0.0, ymargin = 0.0;
	    if (isPoly) {
		if (pmargin->doAdd) {
		    if (sides == 4) {
			switch (j) {
			case 0 :
			    xmargin = margin.x;
			    ymargin = margin.y;
			    break;
			case 1 :
			    xmargin = -margin.x;
			    ymargin = margin.y;
			    break;
			case 2 :
			    xmargin = -margin.x;
			    ymargin = -margin.y;
			    break;
			case 3 :
			    xmargin = margin.x;
			    ymargin = -margin.y;
			    break;
			}
			polyp.x = verts[j].x + xmargin;
			polyp.y = verts[j].y + ymargin;
		    }
		    else {
			double h = (sqrt(((((verts[j].x)) * ((verts[j].x))) + (((verts[j].y)) * ((verts[j].y))))));
			polyp.x = verts[j].x * (1.0 + margin.x/h);
			polyp.y = verts[j].y * (1.0 + margin.y/h);
		    }
		}
		else {
		    polyp.x = verts[j].x * margin.x;
		    polyp.y = verts[j].y * margin.y;
		}
	    } else {
		double c, s;
		c = cos(2.0 * 3.14159265358979323846 * j / sides + adj);
		s = sin(2.0 * 3.14159265358979323846 * j / sides + adj);
		if (pmargin->doAdd) {
		    polyp.x =  c*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)+(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)+pmargin->x) / 2.0;
		    polyp.y =  s*((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)+pmargin->y) / 2.0;
		}
		else {
		    polyp.x = pmargin->x * c * ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)) / 2.0;
		    polyp.y = pmargin->y * s * (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) / 2.0;
		}
	    }
	    obs->ps[sides - j - 1].x = polyp.x + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x;
	    obs->ps[sides - j - 1].y = polyp.y + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y;
	}
	break;
    case SH_RECORD:
	fld = (field_t *) (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info);
	b = fld->b;
	obs = (Ppoly_t*)zmalloc(sizeof(Ppoly_t));
	obs->pn = 4;
	obs->ps = (Ppoint_t*)zmalloc((4)*sizeof(Ppoint_t));
	/* CW order */
	pt = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
	if (pmargin->doAdd) {
	    obs->ps[0] = genPt(b.LL.x-pmargin->x, b.LL.y-pmargin->y, pt);
	    obs->ps[1] = genPt(b.LL.x-pmargin->x, b.UR.y+pmargin->y, pt);
	    obs->ps[2] = genPt(b.UR.x+pmargin->x, b.UR.y+pmargin->y, pt);
	    obs->ps[3] = genPt(b.UR.x+pmargin->x, b.LL.y-pmargin->y, pt);
	}
	else {
	    obs->ps[0] = recPt(b.LL.x, b.LL.y, pt, pmargin);
	    obs->ps[1] = recPt(b.LL.x, b.UR.y, pt, pmargin);
	    obs->ps[2] = recPt(b.UR.x, b.UR.y, pt, pmargin);
	    obs->ps[3] = recPt(b.UR.x, b.LL.y, pt, pmargin);
	}
	break;
    case SH_EPSF:
	desc = (epsf_t *) ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->shape_info));
	obs = (Ppoly_t*)zmalloc(sizeof(Ppoly_t));
	obs->pn = 4;
	obs->ps = (Ppoint_t*)zmalloc((4)*sizeof(Ppoint_t));
	/* CW order */
	pt = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord);
	if (pmargin->doAdd) {
	    obs->ps[0] = genPt(-(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-pmargin->x, -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)-pmargin->y,pt);
	    obs->ps[1] = genPt(-(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw)-pmargin->x, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)+pmargin->y,pt);
	    obs->ps[2] = genPt((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)+pmargin->x, (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)+pmargin->y,pt);
	    obs->ps[3] = genPt((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw)+pmargin->x, -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht)-pmargin->y,pt);
	}
	else {
	    obs->ps[0] = recPt(-(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw), -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht), pt, pmargin);
	    obs->ps[1] = recPt(-(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht), pt, pmargin);
	    obs->ps[2] = recPt((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht), pt, pmargin);
	    obs->ps[3] = recPt((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw), -(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht), pt, pmargin);
	}
	break;
    default:
	obs = (void *)0;
	break;
    }
    return obs;
}

/* getPath
 * Construct the shortest path from one endpoint of e to the other.
 * The obstacles and their number are given by obs and npoly.
 * vconfig is a precomputed data structure to help in the computation.
 * If chkPts is true, the function finds the polygons, if any, containing
 * the endpoints and tells the shortest path computation to ignore them. 
 * Assumes this info is set in ND_lim, usually from _spline_edges.
 * Returns the shortest path.
 */
Ppolyline_t
getPath(edge_t * e, vconfig_t * vconfig, int chkPts, Ppoly_t ** obs,
	int npoly)
{
    Ppolyline_t line;
    int pp, qp;
    Ppoint_t p, q;

    p = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p);
    q = add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p);

    /* determine the polygons (if any) that contain the endpoints */
    pp = qp = -1111;
    if (chkPts) {
	pp = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->lim);
	qp = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->lim);
/*
	for (i = 0; i < npoly; i++) {
	    if ((pp == POLYID_NONE) && in_poly(*obs[i], p))
		pp = i;
	    if ((qp == POLYID_NONE) && in_poly(*obs[i], q))
		qp = i;
	}
*/
    }
    Pobspath(vconfig, p, pp, q, qp, &line);
    return line;
}

/* makePolyline:
 */
static void
makePolyline(graph_t* g, edge_t * e)
{
    Ppolyline_t spl, line = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->path);
    Ppoint_t p0, q0;

    p0 = line.ps[0];
    q0 = line.ps[line.pn - 1];
    make_polyline (line, &spl);
    if (Verbose > 1)
	fprintf(stderr, "polyline %s %s\n", agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
    clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), spl.ps, spl.pn, &sinfo);
    addEdgeLabels(g, e, p0, q0);
}

/* makeSpline:
 * Construct a spline connecting the endpoints of e, avoiding the npoly
 * obstacles obs.
 * The resultant spline is attached to the edge, the positions of any 
 * edge labels are computed, and the graph's bounding box is recomputed.
 * 
 * If chkPts is true, the function checks if one or both of the endpoints 
 * is on or inside one of the obstacles and, if so, tells the shortest path
 * computation to ignore them. 
 */
void makeSpline(graph_t* g, edge_t * e, Ppoly_t ** obs, int npoly, boolean chkPts)
{
    Ppolyline_t line, spline;
    Pvector_t slopes[2];
    int i, n_barriers;
    int pp, qp;
    Ppoint_t p, q;
    Pedge_t *barriers;

    line = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->path);
    p = line.ps[0];
    q = line.ps[line.pn - 1];
    /* determine the polygons (if any) that contain the endpoints */
    pp = qp = -1111;
    if (chkPts)
	for (i = 0; i < npoly; i++) {
	    if ((pp == -1111) && in_poly(*obs[i], p))
		pp = i;
	    if ((qp == -1111) && in_poly(*obs[i], q))
		qp = i;
	}

    make_barriers(obs, npoly, pp, qp, &barriers, &n_barriers);
    slopes[0].x = slopes[0].y = 0.0;
    slopes[1].x = slopes[1].y = 0.0;
    if (Proutespline(barriers, n_barriers, line, slopes, &spline) < 0) {
	agerr (AGERR, "makeSpline: failed to make spline edge (%s,%s)\n", agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
	return;
    }

    /* north why did you ever use int coords */
    if (Verbose > 1)
	fprintf(stderr, "spline %s %s\n", agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
    clip_and_install(e, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), spline.ps, spline.pn, &sinfo);
    free(barriers);
    addEdgeLabels(g, e, p, q);
}

  /* True if either head or tail has a port on its boundary */


/* _spline_edges:
 * Basic default routine for creating edges.
 * If splines are requested, we construct the obstacles.
 * If not, or nodes overlap, the function reverts to line segments.
 * NOTE: intra-cluster edges are not constrained to
 * remain in the cluster's bounding box and, conversely, a cluster's box
 * is not altered to reflect intra-cluster edges.
 * If Nop > 1 and the spline exists, it is just copied.
 * NOTE: if edgetype = ET_NONE, we shouldn't be here.
 */
static int _spline_edges(graph_t * g, expand_t* pmargin, int edgetype)
{
    node_t *n;
    edge_t *e;
    edge_t *e0;
    Ppoly_t **obs = 0;
    Ppoly_t *obp;
    int cnt, i = 0, npoly;
    vconfig_t *vconfig = 0;
    path *P = (void *)0;
    int useEdges = (Nop > 1);
    router_t* rtr = 0;
    int legal = 0;

    /* build configuration */
    if (edgetype >= (3 << 1)) {
	obs = (Ppoly_t **)zmalloc((agnnodes(g))*sizeof(Ppoly_t *));
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    obp = makeObstacle(n, pmargin, edgetype == (4 << 1));
	    if (obp) {
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lim) = i; 
		obs[i++] = obp;
	    }
	    else
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lim) = -1111; 
	}
    } else {
	obs = 0;
    }
    npoly = i;
    if (obs) {
	if ((legal = Plegal_arrangement(obs, npoly))) {
	    if (edgetype != (4 << 1)) vconfig = Pobsopen(obs, npoly);
	}
	else {
	    if (edgetype == (4 << 1))
		agerr(AGWARN, "the bounding boxes of some nodes touch - falling back to straight line edges\n");
	    else 
		agerr(AGWARN, "some nodes with margin (%.02f,%.02f) touch - falling back to straight line edges\n", pmargin->x, pmargin->y);
	}
    }

    /* route edges  */
    if (Verbose)
	fprintf(stderr, "Creating edges using %s\n",
	    (legal && (edgetype == (4 << 1))) ? "orthogonal lines" :
	    (vconfig ? (edgetype == (5 << 1) ? "splines" : "polylines") : 
		"line segments"));
    if (vconfig) {
	/* path-finding pass */
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
		(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->path) = getPath(e, vconfig, (!(0)), obs, npoly);
	    }
	}
    }

    
	
	
    


    /* spline-drawing pass */
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
/* fprintf (stderr, "%s -- %s %d\n", agnameof(agtail(e)), agnameof(aghead(e)), ED_count(e)); */
	    node_t *head = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	    if (useEdges && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)) {
		addEdgeLabels(g, e,
			      add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p),
			      add_pointf((((Agnodeinfo_t*)(((Agobj_t*)(head))->data))->coord), (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p));
	    } 
	    else if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->count) == 0) continue;  /* only do representative */
	    else if (n == head) {    /* self arc */
		if (!P) {
		    P = (path*)zmalloc(sizeof(path));
		    P->boxes = (boxf*)zmalloc((agnnodes(g) + 20 * 2 * 9)*sizeof(boxf));
		}
		makeSelfArcs(P, e, (((Agraphinfo_t*)(((Agobj_t*)(g->root))->data))->nodesep));
	    } else if (vconfig) { /* ET_SPLINE or ET_PLINE */

		
		    
		    
			     
			
		    
			
			
		    
		    
		
		




		cnt = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->count);
		if (Concentrate) cnt = 1; /* only do representative */
		e0 = e;
		for (i = 0; i < cnt; i++) {
		    if (edgetype == (5 << 1))
			makeSpline(g, e0, obs, npoly, (!(0)));
		    else
			makePolyline(g, e0);
		    e0 = (((Agedgeinfo_t*)(((Agobj_t*)(e0))->data))->to_virt);
		}
	    } else {
		makeStraightEdge(g, e, edgetype, &sinfo);
	    }
	}
    }


    
	


    if (vconfig)
	Pobsclose (vconfig);
    if (P) {
	free(P->boxes);
	free(P);
    }
    if (obs) {
	for (i=0; i < npoly; i++)
	    free (obs[i]);
	free (obs);
    }
    return 0;
}

/* splineEdges:
 * Main wrapper code for generating edges.
 * Sets desired separation. 
 * Coalesces equivalent edges (edges * with the same endpoints). 
 * It then calls the edge generating function, and marks the
 * spline phase complete.
 * Returns 0 on success.
 *
 * The edge function is given the graph, the separation to be added
 * around obstacles, and the type of edge. It must guarantee 
 * that all bounding boxes are current; in particular, the bounding box of 
 * g must reflect the addition of the edges.
 */
int
splineEdges(graph_t * g, int (*edgefn) (graph_t *, expand_t*, int),
	    int edgetype)
{
    node_t *n;
    edge_t *e;
    expand_t margin;
    Dt_t *map;

    margin = esepFactor (g);

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    resolvePorts (e);
	}
    }

    /* find equivalent edges */
    map = dtopen(&edgeItemDisc, Dtoset);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    if ((Nop > 1 && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl))) {
		/* If Nop > 1 (use given edges) and e has a spline, it
 		 * should have its own equivalence class.
		 */
		    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->count)++;
	    } else {
		edge_t *leader = equivEdge(map, e);
		if (leader != e) {
		    (((Agedgeinfo_t*)(((Agobj_t*)(leader))->data))->count)++;
		    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt) = (((Agedgeinfo_t*)(((Agobj_t*)(leader))->data))->to_virt);
		    (((Agedgeinfo_t*)(((Agobj_t*)(leader))->data))->to_virt) = e;
		}
	    }
	}
    }
    dtclose(map);

    if (edgefn(g, &margin, edgetype))
	return 1;

    State = 1;
    return 0;
}

/* spline_edges1:
 * Construct edges using default algorithm and given splines value.
 * Return 0 on success.
 */
int spline_edges1(graph_t * g, int edgetype)
{
    return splineEdges(g, _spline_edges, edgetype);
}

/* spline_edges0:
 * Sets the graph's aspect ratio.
 * Check splines attribute and construct edges using default algorithm.
 * If the splines attribute is defined but equal to "", skip edge routing.
 * 
 * Assumes u.bb for has been computed for g and all clusters
 * (not just top-level clusters), and  that GD_bb(g).LL is at the origin.
 *
 * This last criterion is, I believe, mainly to simplify the code
 * in neato_set_aspect. It would be good to remove this constraint,
 * as this would allow nodes pinned on input to have the same coordinates
 * when output in dot or plain format.
 *
 */
void spline_edges0(graph_t * g, boolean set_aspect)
{
    int et = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->flags) & (7 << 1));
    if (set_aspect) neato_set_aspect(g);
    if (et == (0 << 1)) return;

    if (et == (4 << 1)) {
	agerr (AGWARN, "Orthogonal edges not yet supported\n");
	et = (3 << 1); 
	(((Agraphinfo_t*)(((Agobj_t*)(g->root))->data))->flags) &= ~(4 << 1);
	(((Agraphinfo_t*)(((Agobj_t*)(g->root))->data))->flags) |= (3 << 1);
    }

    spline_edges1(g, et);
}

/* shiftClusters:
 */
static void
shiftClusters (graph_t * g, pointf offset)
{
    int i;

    for (i = 1; i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); i++) {
	shiftClusters ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[i], offset);
    }

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x -= offset.x;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y -= offset.y;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x -= offset.x;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y -= offset.y;
}

/* spline_edges:
 * Compute bounding box, translate graph to origin,
 * then construct all edges.
 */
void spline_edges(graph_t * g)
{
    node_t *n;
    pointf offset;

    compute_bb(g);
    offset.x = (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x)/(double)72);
    offset.y = (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y)/(double)72);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[0] -= offset.x;
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[1] -= offset.y;
    }
	
    shiftClusters (g, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL);
    spline_edges0(g, (!(0)));
}

/* scaleEdge:
 * Scale edge by given factor.
 * Assume ED_spl != NULL.
 */
static void scaleEdge(edge_t * e, double xf, double yf)
{
    int i, j;
    pointf *pt;
    bezier *bez;
    pointf delh, delt;

    delh.x = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->pos)[0] * (xf - 1.0));
    delh.y = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->pos)[1] * (yf - 1.0));
    delt.x = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->pos)[0] * (xf - 1.0));
    delt.y = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->pos)[1] * (yf - 1.0));

    bez = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list;
    for (i = 0; i < (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size; i++) {
	pt = bez->list;
	for (j = 0; j < bez->size; j++) {
	    if ((i == 0) && (j == 0)) {
		pt->x += delt.x;
		pt->y += delt.y;
	    }
	    else if ((i == (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size-1) && (j == bez->size-1)) {
		pt->x += delh.x;
		pt->y += delh.y;
	    }
	    else {
		pt->x *= xf;
		pt->y *= yf;
	    }
	    pt++;
	}
	if (bez->sflag) {
	    bez->sp.x += delt.x;
	    bez->sp.y += delt.y;
	}
	if (bez->eflag) {
	    bez->ep.x += delh.x;
	    bez->ep.y += delh.y;
	}
	bez++;
    }

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x *= xf;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y *= yf;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->pos.x += delh.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->pos.y += delh.y;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->pos.x += delt.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->pos.y += delt.y;
    }
}

/* scaleBB:
 * Scale bounding box of clusters of g by given factors.
 */
static void scaleBB(graph_t * g, double xf, double yf)
{
    int i;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x *= xf;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y *= yf;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x *= xf;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y *= yf;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label) && (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->set) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->pos.x *= xf;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->pos.y *= yf;
    }

    for (i = 1; i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); i++)
	scaleBB((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[i], xf, yf);
}

/* translateE:
 * Translate edge by offset.
 * Assume ED_spl(e) != NULL
 */
static void translateE(edge_t * e, pointf offset)
{
    int i, j;
    pointf *pt;
    bezier *bez;

    bez = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->list;
    for (i = 0; i < (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl)->size; i++) {
	pt = bez->list;
	for (j = 0; j < bez->size; j++) {
	    pt->x -= offset.x;
	    pt->y -= offset.y;
	    pt++;
	}
	if (bez->sflag) {
	    bez->sp.x -= offset.x;
	    bez->sp.y -= offset.y;
	}
	if (bez->eflag) {
	    bez->ep.x -= offset.x;
	    bez->ep.y -= offset.y;
	}
	bez++;
    }

    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.x -= offset.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label)->pos.y -= offset.y;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xlabel) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xlabel)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xlabel)->pos.x -= offset.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xlabel)->pos.y -= offset.y;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->pos.x -= offset.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_label)->pos.y -= offset.y;
    }
    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label) && (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->set) {
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->pos.x -= offset.x;
	(((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_label)->pos.y -= offset.y;
    }
}

/* translateG:
 */
static void translateG(Agraph_t * g, pointf offset)
{
    int i;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x -= offset.x;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y -= offset.y;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x -= offset.x;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y -= offset.y;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label) && (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->set) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->pos.x -= offset.x;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->label)->pos.y -= offset.y;
    }

    for (i = 1; i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); i++)
	translateG((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[i], offset);
}

/* translate:
 */
static void translate(Agraph_t * g)
{
    node_t *n;
    edge_t *e;
    pointf offset;
    pointf ll;

    ll = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL;

    offset.x = ((ll.x)/(double)72);
    offset.y = ((ll.y)/(double)72);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[0] -= offset.x;
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[1] -= offset.y;
	if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->xlabel) && (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->xlabel)->set) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->xlabel)->pos.x -= ll.x;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->xlabel)->pos.y -= ll.y;
	}
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e))
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl))
		translateE(e, ll);
    }
    translateG(g, ll);
}

/* _neato_set_aspect;
 * Assume all bounding boxes are correct.
 * Return false if no transform is performed. This includes
 * the possiblity that a translation was done.
 */
static boolean _neato_set_aspect(graph_t * g)
{
    double xf, yf, actual, desired;
    node_t *n;

    if (g->root != g)
	return 0;

    /* compute_bb(g); */
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->ratio_kind) {
	if (((abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x)>=0)?(int)(abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x) + .5):(int)(abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.x) - .5)) || ((abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y)>=0)?(int)(abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y) + .5):(int)(abs((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).LL.y) - .5)))
	    translate (g);
	/* normalize */
	if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) {
	    double t = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x;
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y;
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y = t;
	}
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->ratio_kind == R_FILL) {
	    /* fill is weird because both X and Y can stretch */
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.x <= 0)
		return 0;
	    xf = (double) (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.x / (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x;
	    yf = (double) (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.y / (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y;
	    /* handle case where one or more dimensions is too big */
	    if ((xf < 1.0) || (yf < 1.0)) {
		if (xf < yf) {
		    yf = yf / xf;
		    xf = 1.0;
		} else {
		    xf = xf / yf;
		    yf = 1.0;
		}
	    }
	} else if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->ratio_kind == R_EXPAND) {
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.x <= 0)
		return 0;
	    xf = (double) (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.x / (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x;
	    yf = (double) (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->size.y / (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y;
	    if ((xf > 1.0) && (yf > 1.0)) {
		double scale = ((xf)<(yf)?(xf):(yf));
		xf = yf = scale;
	    } else
		return 0;
	} else if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->ratio_kind == R_VALUE) {
	    desired = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->drawing)->ratio;
	    actual = ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.y) / ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->bb).UR.x);
	    if (actual < desired) {
		yf = desired / actual;
		xf = 1.0;
	    } else {
		xf = actual / desired;
		yf = 1.0;
	    }
	} else
	    return 0;
	if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) {
	    double t = xf;
	    xf = yf;
	    yf = t;
	}

	if (Nop > 1) {
	    edge_t *e;
	    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
		for (e = agfstout(g, n); e; e = agnxtout(g, e))
		    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->spl))
			scaleEdge(e, xf, yf);
	    }
	}
	/* Not relying on neato_nlist here allows us not to have to 
	 * allocate it in the root graph and the connected components. 
	 */
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[0] = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[0] * xf;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[1] = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[1] * yf;
	}
	scaleBB(g, xf, yf);
        return (!(0));
    }
    else
	return 0;
}

/* neato_set_aspect:
 * Sets aspect ratio if necessary; real work done in _neato_set_aspect;
 * This also copies the internal layout coordinates (ND_pos) to the 
 * external ones (ND_coord).
 *
 * Return true if some node moved.
 */
boolean neato_set_aspect(graph_t * g)
{
    node_t *n;
    boolean moved = 0;

	/* setting aspect ratio only makes sense on root graph */
    moved = _neato_set_aspect(g);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).x = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[0]);
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord).y = 72 * ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->pos)[1]);
    }
    return moved;
}

