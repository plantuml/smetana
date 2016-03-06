#line 1 "graphviz-2.38.0\\lib\\ortho\\partition.c" 1
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


#line 1 "graphviz-2.38.0\\lib\\ortho\\partition.c" 1


#line 1 "graphviz-2.38.0\\lib\\ortho\\partition.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\ortho\\maze.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\ortho\\sgraph.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\ortho\\structures.h" 1
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


	/* to place nodes */
	node_t **neato_nlist;
	int move;
	double **dist, **spring, **sum_t, ***t;
	unsigned short ndim;
	unsigned short odim;


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


	unsigned char pinned;
	int id, heapindex, hops;
	double *pos, dist;


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


	double factor;
	double dist;
	Ppolyline_t path;


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





#line 17 "graphviz-2.38.0\\lib\\ortho\\structures.h" 2
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




























































    
    
    





    
    
    
    
    


	








	

    
    


















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	



















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       


















































    









































#line 18 "graphviz-2.38.0\\lib\\ortho\\structures.h" 2
#line 1 "graphviz-2.38.0\\lib\\ortho\\rawgraph.h" 1
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




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 17 "graphviz-2.38.0\\lib\\ortho\\rawgraph.h" 2

typedef struct {
  int color;
  int topsort_order;
  Dt_t* adj_list;  /* adj_list */
} vertex;

typedef struct {
  int nvs;
  vertex* vertices;
} rawgraph;

extern rawgraph* make_graph(int n);  /* makes a graph wih n vertices, 0 edges */
extern void free_graph(rawgraph*); 
  /* inserts edge FROM v1 to v2 */
extern void insert_edge(rawgraph*, int v1, int v2); 
  /* removes any edge between v1 to v2 -- irrespective of direction */
extern void remove_redge(rawgraph*, int v1, int v2);  
  /* tests if there is an edge FROM v1 TO v2 */
extern int edge_exists(rawgraph*, int v1, int v2);
  /* topologically sorts the directed graph */
extern void top_sort(rawgraph*); 


#line 19 "graphviz-2.38.0\\lib\\ortho\\structures.h" 2

typedef struct {
    double p1, p2;
} paird;

typedef struct {
    int a,b;
} pair;

typedef struct {
	pair t1, t2;
} pair2;

typedef enum {B_NODE, B_UP, B_LEFT, B_DOWN, B_RIGHT} bend;

/* Example : segment connecting maze point (3,2) 
 * and (3,8) has isVert = 1, common coordinate = 3, p1 = 2, p2 = 8
 */
typedef struct segment {
  boolean isVert;
  boolean flipped;
  double comm_coord;  /* the common coordinate */
  paird p;      /* end points */
  bend l1, l2; 
  int ind_no;      /* index number of this segment in its channel */
  int track_no;    /* track number assigned in the channel */
  struct segment* prev;
  struct segment* next;
} segment;

typedef struct {
  int n;
  segment* segs;
} route;

typedef struct {
  Dtlink_t link;
  paird p;   /* extrema of channel */
  int cnt;   /* number of segments */
  segment** seg_list; /* array of segment pointers */
  rawgraph* G;
  struct cell* cp;
} channel;



  
  
  

  



	
	



  
  
  

  



	
	






#line 17 "graphviz-2.38.0\\lib\\ortho\\sgraph.h" 2

typedef struct snode snode;
typedef struct sedge sedge;

struct snode {
  int n_val, n_idx;
  snode* n_dad;
  sedge* n_edge;
  short   n_adj;
  short   save_n_adj;
  struct cell* cells[2];

    /* edges incident on this node 
     * -- stored as indices of the edges array in the graph
     */
  int* adj_edge_list;  
  int index;
  boolean isVert;  /* true if node corresponds to vertical segment */
};

struct sedge {
  double weight;    /* weight of edge */
  int cnt;          /* paths using edge */
      /* end-points of the edge 
       * -- stored as indices of the nodes vector in the graph
       */
  int v1, v2;      
};

typedef struct {
  int nnodes, nedges;
  int save_nnodes, save_nedges;
  snode* nodes;
  sedge* edges;
} sgraph;

extern void reset(sgraph*);
extern void gsave(sgraph*);
extern sgraph* createSGraph(int);
extern void freeSGraph (sgraph*);
extern void initSEdges (sgraph* g, int maxdeg);
extern int shortPath (sgraph* g, snode* from, snode* to);
extern snode* createSNode (sgraph*);
extern sedge* createSEdge (sgraph* g, snode* v0, snode* v1, double wt);


#line 17 "graphviz-2.38.0\\lib\\ortho\\maze.h" 2

enum {M_RIGHT=0, M_TOP, M_LEFT, M_BOTTOM};







  /* cell corresponds to node */

  /* cell already inserted in vertical channel */

  /* cell already inserted in horizontal channel */

  /* cell has small height corresponding to a small height node */

  /* cell has small width corresponding to a small width node */


typedef struct cell {
  int flags;
  int nedges;
  sedge* edges[6];
  int nsides;
  snode** sides;
  boxf  bb;
} cell;

typedef struct {
  int ncells, ngcells;
  cell* cells;     /* cells not corresponding to graph nodes */
  cell* gcells;    /* cells corresponding to graph nodes */
  sgraph* sg;
  Dt_t* hchans;
  Dt_t* vchans;
} maze;

extern maze* mkMaze (graph_t*, int);
extern void freeMaze (maze*);
void updateWts (sgraph* g, cell* cp, sedge* ep);









#line 17 "graphviz-2.38.0\\lib\\ortho\\partition.h" 2

extern boxf* partition (cell*, int, int*, boxf);


#line 18 "graphviz-2.38.0\\lib\\ortho\\partition.c" 2
#line 1 "graphviz-2.38.0\\lib\\ortho\\trap.h" 1
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




/* Segment attributes */

typedef struct {
  pointf v0, v1;       /* two endpoints */ 
  int is_inserted;      /* inserted in trapezoidation yet ? */
  int root0, root1;     /* root nodes in Q */
  int next;         /* Next logical segment */
  int prev;         /* Previous segment */
} segment_t;


/* Trapezoid attributes */

typedef struct {
  int lseg, rseg;       /* two adjoining segments */
  pointf hi, lo;       /* max/min y-values */ 
  int u0, u1;
  int d0, d1;
  int sink;         /* pointer to corresponding in Q */
  int usave, uside;     /* I forgot what this means */
  int state;
} trap_t; 





                /* all decisions about collinearity or */
                /* left/right of segment. Decrease */
                /* this value if the input points are */
                /* spaced very close together */








extern int construct_trapezoids(int, segment_t*, int*, int, trap_t*);


#line 19 "graphviz-2.38.0\\lib\\ortho\\partition.c" 2
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







#line 20 "graphviz-2.38.0\\lib\\ortho\\partition.c" 2
#line 1 "graphviz-2.38.0\\lib\\ortho\\partition.c" 1
#line 1 "graphviz-2.38.0\\lib\\ortho\\partition.c" 1



























typedef struct {
  int vnum;
  int next;         /* Circularly linked list  */
  int prev;         /* describing the monotone */
  int marked;           /* polygon */
} monchain_t;

typedef struct {
  pointf pt;
  int vnext[4];         /* next vertices for the 4 chains */
  int vpos[4];          /* position of v in the 4 chains */
  int nextfree;
} vertexchain_t;

static int chain_idx, mon_idx;
	/* Table to hold all the monotone */
	/* polygons . Each monotone polygon */
	/* is a circularly linked list */
static monchain_t* mchain;
	/* chain init. information. This */
	/* is used to decide which */
	/* monotone polygon to split if */
	/* there are several other */
	/* polygons touching at the same */
	/* vertex  */
static vertexchain_t* vert;
	/* contains position of any vertex in */
	/* the monotone chain for the polygon */
static int* mon;

/* return a new mon structure from the table */

/* return a new chain element from the table */


static void
convert (boxf bb, int flip, int ccw, pointf* pts)
{
    pts[0] = bb.LL;
    pts[2] = bb.UR;
    if (ccw) {
	pts[1].x = bb.UR.x;
	pts[1].y = bb.LL.y;
	pts[3].x = bb.LL.x;
	pts[3].y = bb.UR.y;
    }
    else {
	pts[1].x = bb.LL.x;
	pts[1].y = bb.UR.y;
	pts[3].x = bb.UR.x;
	pts[3].y = bb.LL.y;
    }
    if (flip) {
	int i;
	for (i = 0; i < 4; i++) {
	    double tmp = pts[i].y;
	    pts[i].y = pts[i].x;
	    pts[i].x = -tmp;
	}
    }
}

static int
store (segment_t* seg, int first, pointf* pts)
{
    int i, last = first + 4 - 1;
    int j = 0;

    for (i = first; i <= last; i++, j++) {
	if (i == first) {
	    seg[i].next = first+1;
	    seg[i].prev = last;
	}
	else if (i == last) {
	    seg[i].next = first;
	    seg[i].prev = last-1;
	}
	else {
	    seg[i].next = i+1;
	    seg[i].prev = i-1;
	}
	seg[i].is_inserted = 0;
	seg[seg[i].prev].v1 = seg[i].v0 = pts[j];
    }
    return (last+1);
}

static void
genSegments (cell* cells, int ncells, boxf bb, segment_t* seg, int flip)
{
    int j = 0, i = 1;
    pointf pts[4];

    convert (bb, flip, 1, pts);
    i = store (seg, i, pts);
    for (j = 0; j < ncells; j++) {
	convert (cells[j].bb, flip, 0, pts);
	i = store (seg, i, pts);
    }
}

/* Generate a random permutation of the segments 1..n */
static void 
generateRandomOrdering(int n, int* permute)
{
    int i, j, tmp;
    for (i = 0; i <= n; i++) permute[i] = i;

    for (i = 1; i <= n; i++) {
	j = i + drand48() * (n + 1 - i);
	if (j != i) {
	    tmp = permute[i];
	    permute [i] = permute[j];
            permute [j] = tmp;
	}
    }
}

/* Function returns TRUE if the trapezoid lies inside the polygon */
static int 
inside_polygon (trap_t *t, segment_t* seg)
{
  int rseg = t->rseg;

  if (t->state == 2)
    return 0;

  if ((t->lseg <= 0) || (t->rseg <= 0))
    return 0;
  
  if (((t->u0 <= 0) && (t->u1 <= 0)) || 
      ((t->d0 <= 0) && (t->d1 <= 0))) /* triangle */
    return ((((&seg[rseg].v1)->y > (&seg[rseg].v0)->y + 1.0e-7) ? NOT(0) : (((&seg[rseg].v1)->y < (&seg[rseg].v0)->y - 1.0e-7) ? 0 : ((&seg[rseg].v1)->x > (&seg[rseg].v0)->x))));
  
  return 0;
}

static double
get_angle (pointf *vp0, pointf *vpnext, pointf *vp1)
{
  pointf v0, v1;
  
  v0.x = vpnext->x - vp0->x;
  v0.y = vpnext->y - vp0->y;

  v1.x = vp1->x - vp0->x;
  v1.y = vp1->y - vp0->y;

  if (((v0).x * (v1).y - (v1).x * (v0).y) >= 0)	/* sine is positive */
    return ((v0).x * (v1).x + (v0).y * (v1).y)/(sqrt((v0).x * (v0).x + (v0).y * (v0).y))/(sqrt((v1).x * (v1).x + (v1).y * (v1).y));
  else
    return (-1.0 * ((v0).x * (v1).x + (v0).y * (v1).y)/(sqrt((v0).x * (v0).x + (v0).y * (v0).y))/(sqrt((v1).x * (v1).x + (v1).y * (v1).y)) - 2);
}

/* (v0, v1) is the new diagonal to be added to the polygon. Find which */
/* chain to use and return the positions of v0 and v1 in p and q */ 
static int
get_vertex_positions (int v0, int v1, int *ip, int *iq)
{
  vertexchain_t *vp0, *vp1;
  register int i;
  double angle, temp;
  int tp, tq;

  vp0 = &vert[v0];
  vp1 = &vert[v1];
  
  /* p is identified as follows. Scan from (v0, v1) rightwards till */
  /* you hit the first segment starting from v0. That chain is the */
  /* chain of our interest */
  
  angle = -4.0;
  for (i = 0; i < 4; i++)
    {
      if (vp0->vnext[i] <= 0)
	continue;
      if ((temp = get_angle(&vp0->pt, &(vert[vp0->vnext[i]].pt), 
			    &vp1->pt)) > angle)
	{
	  angle = temp;
	  tp = i;
	}
    }

  *ip = tp;

  /* Do similar actions for q */

  angle = -4.0;
  for (i = 0; i < 4; i++)
    {
      if (vp1->vnext[i] <= 0)
	continue;      
      if ((temp = get_angle(&vp1->pt, &(vert[vp1->vnext[i]].pt), 
			    &vp0->pt)) > angle)
	{
	  angle = temp;
	  tq = i;
	}
    }

  *iq = tq;

  return 0;
}

/* v0 and v1 are specified in anti-clockwise order with respect to 
 * the current monotone polygon mcur. Split the current polygon into 
 * two polygons using the diagonal (v0, v1) 
 */
static int 
make_new_monotone_poly (int mcur, int v0, int v1)
{
  int p, q, ip, iq;
  int mnew = (++mon_idx);
  int i, j, nf0, nf1;
  vertexchain_t *vp0, *vp1;
  
  vp0 = &vert[v0];
  vp1 = &vert[v1];

  get_vertex_positions(v0, v1, &ip, &iq);

  p = vp0->vpos[ip];
  q = vp1->vpos[iq];

  /* At this stage, we have got the positions of v0 and v1 in the */
  /* desired chain. Now modify the linked lists */

  i = (++chain_idx);	/* for the new list */
  j = (++chain_idx);

  mchain[i].vnum = v0;
  mchain[j].vnum = v1;

  mchain[i].next = mchain[p].next;
  mchain[mchain[p].next].prev = i;
  mchain[i].prev = j;
  mchain[j].next = i;
  mchain[j].prev = mchain[q].prev;
  mchain[mchain[q].prev].next = j;

  mchain[p].next = q;
  mchain[q].prev = p;

  nf0 = vp0->nextfree;
  nf1 = vp1->nextfree;

  vp0->vnext[ip] = v1;

  vp0->vpos[nf0] = i;
  vp0->vnext[nf0] = mchain[mchain[i].next].vnum;
  vp1->vpos[nf1] = j;
  vp1->vnext[nf1] = v0;

  vp0->nextfree++;
  vp1->nextfree++;


  
	  
  


  mon[mcur] = p;
  mon[mnew] = i;
  return mnew;
}

/* recursively visit all the trapezoids */
static int
traverse_polygon (int* visited, boxf* decomp, int size, segment_t* seg, trap_t* tr,
    int mcur, int trnum, int from, int flip, int dir)
{
  trap_t *t = &tr[trnum];
  int mnew;
  int v0, v1;
  int retval;
  int do_switch = 0;

  if ((trnum <= 0) || visited[trnum])
    return size;

  visited[trnum] = NOT(0);
  
  if ((t->hi.y > t->lo.y) &&
      (seg[t->lseg].v0.x == seg[t->lseg].v1.x) &&
      (seg[t->rseg].v0.x == seg[t->rseg].v1.x)) {
      if (flip) {
          decomp[size].LL.x = t->lo.y;
          decomp[size].LL.y = -seg[t->rseg].v0.x;
          decomp[size].UR.x = t->hi.y;
          decomp[size].UR.y = -seg[t->lseg].v0.x;
      } else {
          decomp[size].LL.x = seg[t->lseg].v0.x;
          decomp[size].LL.y = t->lo.y;
          decomp[size].UR.x = seg[t->rseg].v0.x;
          decomp[size].UR.y = t->hi.y;
      }
      size++;
  }
  
  /* We have much more information available here. */
  /* rseg: goes upwards   */
  /* lseg: goes downwards */

  /* Initially assume that dir = TR_FROM_DN (from the left) */
  /* Switch v0 and v1 if necessary afterwards */


  /* special cases for triangles with cusps at the opposite ends. */
  /* take care of this first */
  if ((t->u0 <= 0) && (t->u1 <= 0))
    {
      if ((t->d0 > 0) && (t->d1 > 0)) /* downward opening triangle */
	{
	  v0 = tr[t->d1].lseg;
	  v1 = t->lseg;
	  if (from == t->d1)
	    {
	      do_switch = NOT(0);
	      mnew = make_new_monotone_poly(mcur, v1, v0);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);	    
	    }
	  else
	    {
	      mnew = make_new_monotone_poly(mcur, v0, v1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
	    }
	}
      else
	{
	  retval = -1;	/* Just traverse all neighbours */
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
	}
    }
  
  else if ((t->d0 <= 0) && (t->d1 <= 0))
    {
      if ((t->u0 > 0) && (t->u1 > 0)) /* upward opening triangle */
	{
	  v0 = t->rseg;
	  v1 = tr[t->u0].rseg;
	  if (from == t->u1)
	    {
	      do_switch = NOT(0);
	      mnew = make_new_monotone_poly(mcur, v1, v0);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);	    
	    }
	  else
	    {
	      mnew = make_new_monotone_poly(mcur, v0, v1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
	    }
	}
      else
	{
	  retval = -1;	/* Just traverse all neighbours */
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
	  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
	}
    }
  
  else if ((t->u0 > 0) && (t->u1 > 0)) 
    {
      if ((t->d0 > 0) && (t->d1 > 0)) /* downward + upward cusps */
	{
	  v0 = tr[t->d1].lseg;
	  v1 = tr[t->u0].rseg;
	  retval = 3;
	  if (((dir == 2) && (t->d1 == from)) ||
	      ((dir == 1) && (t->u1 == from)))
	    {
	      do_switch = NOT(0);
	      mnew = make_new_monotone_poly(mcur, v1, v0);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
	    }
	  else
	    {
	      mnew = make_new_monotone_poly(mcur, v0, v1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);	      
	    }
	}
      else			/* only downward cusp */
	{
	  if (((fabs((&t->lo)->y - (&seg[t->lseg].v1)->y) <= 1.0e-7) && (fabs((&t->lo)->x - (&seg[t->lseg].v1)->x) <= 1.0e-7)))
	    {
	      v0 = tr[t->u0].rseg;
	      v1 = seg[t->lseg].next;

	      retval = 4;
	      if ((dir == 1) && (t->u0 == from))
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		}
	    }
	  else
	    {
	      v0 = t->rseg;
	      v1 = tr[t->u0].rseg;	
	      retval = 5;
	      if ((dir == 1) && (t->u1 == from))
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		}
	    }
	}
    }
  else if ((t->u0 > 0) || (t->u1 > 0)) /* no downward cusp */
    {
      if ((t->d0 > 0) && (t->d1 > 0)) /* only upward cusp */
	{
	  if (((fabs((&t->hi)->y - (&seg[t->lseg].v0)->y) <= 1.0e-7) && (fabs((&t->hi)->x - (&seg[t->lseg].v0)->x) <= 1.0e-7)))
	    {
	      v0 = tr[t->d1].lseg;
	      v1 = t->lseg;
	      retval = 6;
	      if (!((dir == 2) && (t->d0 == from)))
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);	      
		}
	    }
	  else
	    {
	      v0 = tr[t->d1].lseg;
	      v1 = seg[t->rseg].next;

	      retval = 7;	    
	      if ((dir == 2) && (t->d1 == from))
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
		}
	    }
	}
      else			/* no cusp */
	{
	  if (((fabs((&t->hi)->y - (&seg[t->lseg].v0)->y) <= 1.0e-7) && (fabs((&t->hi)->x - (&seg[t->lseg].v0)->x) <= 1.0e-7)) &&
	      ((fabs((&t->lo)->y - (&seg[t->rseg].v0)->y) <= 1.0e-7) && (fabs((&t->lo)->x - (&seg[t->rseg].v0)->x) <= 1.0e-7)))
	    {
	      v0 = t->rseg;
	      v1 = t->lseg;
	      retval = 2;
	      if (dir == 1)
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		}
	    }
	  else if (((fabs((&t->hi)->y - (&seg[t->rseg].v1)->y) <= 1.0e-7) && (fabs((&t->hi)->x - (&seg[t->rseg].v1)->x) <= 1.0e-7)) &&
		   ((fabs((&t->lo)->y - (&seg[t->lseg].v1)->y) <= 1.0e-7) && (fabs((&t->lo)->x - (&seg[t->lseg].v1)->x) <= 1.0e-7)))
	    {
	      v0 = seg[t->rseg].next;
	      v1 = seg[t->lseg].next;

	      retval = 1;
	      if (dir == 1)
		{
		  do_switch = NOT(0);
		  mnew = make_new_monotone_poly(mcur, v1, v0);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->d0, trnum, flip, 1);
		}
	      else
		{
		  mnew = make_new_monotone_poly(mcur, v0, v1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u0, trnum, flip, 2);
		  size = traverse_polygon (visited, decomp, size, seg, tr, mnew, t->u1, trnum, flip, 2);
		}
	    }
	  else			/* no split possible */
	    {
	      retval = -1;
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u0, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d0, trnum, flip, 1);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->u1, trnum, flip, 2);
	      size = traverse_polygon (visited, decomp, size, seg, tr, mcur, t->d1, trnum, flip, 1);	      	      
	    }
	}
    }

  return size;
}

static int
monotonate_trapezoids(int nsegs, segment_t*seg, trap_t* tr, 
    int flip, boxf* decomp)
{
    int i, size;
    int tr_start;
    int tr_size = (5*(nsegs)+1);
    int* visited = (int*)zmalloc((tr_size)*sizeof(int));

    mchain = (monchain_t*)zmalloc((tr_size)*sizeof(monchain_t));
    vert = (vertexchain_t*)zmalloc((nsegs+1)*sizeof(vertexchain_t)); 
    mon = (int*)zmalloc((nsegs)*sizeof(int));    

  /* First locate a trapezoid which lies inside the polygon */
  /* and which is triangular */
    for (i = 0; i < (5*(nsegs)+1); i++)
	if (inside_polygon(&tr[i], seg)) break;
    tr_start = i;
  
  /* Initialise the mon data-structure and start spanning all the */
  /* trapezoids within the polygon */

    for (i = 1; i <= nsegs; i++) {
	mchain[i].prev = seg[i].prev;
	mchain[i].next = seg[i].next;
	mchain[i].vnum = i;
	vert[i].pt = seg[i].v0;
	vert[i].vnext[0] = seg[i].next; /* next vertex */
	vert[i].vpos[0] = i;	/* locn. of next vertex */
	vert[i].nextfree = 1;
    }

    chain_idx = nsegs;
    mon_idx = 0;
    mon[0] = 1;			/* position of any vertex in the first */
				/* chain  */
  
  /* traverse the polygon */
    if (tr[tr_start].u0 > 0)
	size = traverse_polygon (visited, decomp, 0, seg, tr, 0, tr_start, tr[tr_start].u0, flip, 1);
    else if (tr[tr_start].d0 > 0)
	size = traverse_polygon (visited, decomp, 0, seg, tr, 0, tr_start, tr[tr_start].d0, flip, 2);
  
    free (visited);
    free (mchain);
    free (vert);
    free (mon);

  /* return the number of rects created */
  return size;
}

static int 
rectIntersect (boxf *d, const boxf *r0, const boxf *r1)
{
    double t;

    t = (r0->LL.x > r1->LL.x) ? r0->LL.x : r1->LL.x;
    d->UR.x = (r0->UR.x < r1->UR.x) ? r0->UR.x : r1->UR.x;
    d->LL.x = t;
    
    t = (r0->LL.y > r1->LL.y) ? r0->LL.y : r1->LL.y;
    d->UR.y = (r0->UR.y < r1->UR.y) ? r0->UR.y : r1->UR.y;
    d->LL.y = t;

    if ((d->LL.x >= d->UR.x) ||
        (d->LL.y >= d->UR.y))
    return 0;

    return 1;
}





    
    
      
      
         
         
      
         
    
    





    
    
      
      
         
         
    
    



boxf*
partition (cell* cells, int ncells, int* nrects, boxf bb)
{
    int nsegs = 4*(ncells+1);
    segment_t* segs = (segment_t*)gmalloc((nsegs+1)*sizeof(segment_t));
    int* permute = (int*)zmalloc((nsegs+1)*sizeof(int));
    int hd_size, vd_size;
    int i, j, cnt = 0;
    boxf* rs;
    int ntraps = (5*(nsegs)+1);
    trap_t* trs = (trap_t*)gmalloc((ntraps)*sizeof(trap_t));
    boxf* hor_decomp = (boxf*)zmalloc((ntraps)*sizeof(boxf));
    boxf* vert_decomp = (boxf*)zmalloc((ntraps)*sizeof(boxf));
    int nt;

    /* fprintf (stderr, "cells = %d segs = %d traps = %d\n", ncells, nsegs, ntraps);  */
    genSegments (cells, ncells, bb, segs, 0);



  
  
  


    srand(173);
    generateRandomOrdering (nsegs, permute);
    nt = construct_trapezoids(nsegs, segs, permute, ntraps, trs);
    /* fprintf (stderr, "hor traps = %d\n", nt); */
    hd_size = monotonate_trapezoids (nsegs, segs, trs, 0, hor_decomp);

    genSegments (cells, ncells, bb, segs, 1);
    generateRandomOrdering (nsegs, permute);
    nt = construct_trapezoids(nsegs, segs, permute, ntraps, trs);
    /* fprintf (stderr, "ver traps = %d\n", nt); */
    vd_size = monotonate_trapezoids (nsegs, segs, trs, 1, vert_decomp);

    rs = (boxf*)zmalloc((hd_size*vd_size)*sizeof(boxf));
    for (i=0; i<vd_size; i++) 
	for (j=0; j<hd_size; j++)
	    if (rectIntersect(&rs[cnt], &vert_decomp[i], &hor_decomp[j]))
		cnt++;

    rs = RALLOC (cnt, rs, boxf);
    free (segs);
    free (permute);
    free (trs);
    free (hor_decomp);
    free (vert_decomp);
    *nrects = cnt;
    return rs;
}
