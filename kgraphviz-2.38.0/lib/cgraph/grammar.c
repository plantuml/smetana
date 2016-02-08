#line 1 "graphviz-2.38.0\\lib\\cgraph\\grammar.c" 1
/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with aag or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */


/* Bison version.  */


/* Skeleton name.  */


/* Pure parsers.  */


/* Push parsers.  */


/* Pull parsers.  */





/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */



#line 1 "graphviz-2.38.0\\lib\\cgraph\\grammar.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/










#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1


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


































#line 20 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 2

#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cghdr.h" 1













































	/* functional definitions */
typedef Agobj_t *(*agobjsearchfn_t) (Agraph_t * g, Agobj_t * obj);
int agapply(Agraph_t * g, Agobj_t * obj, agobjfn_t fn, void *arg,
	    int preorder);

	/* global variables */
extern Agraph_t *Ag_G_global;
extern char *AgDataRecName;

	/* set ordering disciplines */
extern Dtdisc_t Ag_subnode_id_disc;
extern Dtdisc_t Ag_subnode_seq_disc;
extern Dtdisc_t Ag_mainedge_id_disc;
extern Dtdisc_t Ag_subedge_id_disc;
extern Dtdisc_t Ag_mainedge_seq_disc;
extern Dtdisc_t Ag_subedge_seq_disc;
extern Dtdisc_t Ag_subgraph_id_disc;
extern Agcbdisc_t AgAttrdisc;

	/* internal constructor of graphs and subgraphs */
Agraph_t *agopen1(Agraph_t * g);
int agstrclose(Agraph_t * g);

	/* ref string management */
void agmarkhtmlstr(char *s);

	/* object set management */
Agnode_t *agfindnode_by_id(Agraph_t * g, unsigned long id);
Dtcompar_f agdictorder(Agraph_t *, Dict_t *, Dtcompar_f);
int agedgecmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc);
int agnamecmpf(Dict_t * d, void *, void *, Dtdisc_t * disc);
void agset_node_disc(Agraph_t * g, Dtdisc_t * disc);
unsigned long agnextseq(Agraph_t * g, int objtype);

/* dict helper functions */
Dict_t *agdtopen(Agraph_t * g, Dtdisc_t * disc, Dtmethod_t * method);
void agdtdisc(Agraph_t * g, Dict_t * dict, Dtdisc_t * disc);
long agdtdelete(Agraph_t * g, Dict_t * dict, void *obj);
int agdtclose(Agraph_t * g, Dict_t * dict);
void *agdictobjmem(Dict_t * dict, void * p, size_t size,
		   Dtdisc_t * disc);
void agdictobjfree(Dict_t * dict, void * p, Dtdisc_t * disc);

	/* name-value pair operations */
Agdatadict_t *agdatadict(Agraph_t * g, int cflag);
Agattr_t *agattrrec(void *obj);

void agraphattr_init(Agraph_t * g);
int agraphattr_delete(Agraph_t * g);
void agnodeattr_init(Agraph_t *g, Agnode_t * n);
void agnodeattr_delete(Agnode_t * n);
void agedgeattr_init(Agraph_t *g, Agedge_t * e);
void agedgeattr_delete(Agedge_t * e);

	/* parsing and lexing graph files */
int aagparse(void);
void aglexinit(Agdisc_t * disc, void *ifile);
int aaglex(void);
void aglexeof(void);
void aglexbad(void);

	/* ID management */
int agmapnametoid(Agraph_t * g, int objtype, char *str,
		  unsigned long *result, int allocflag);
int agallocid(Agraph_t * g, int objtype, unsigned long request);
void agfreeid(Agraph_t * g, int objtype, unsigned long id);
char *agprintid(Agobj_t * obj);
int aginternalmaplookup(Agraph_t * g, int objtype, char *str,
			unsigned long *result);
void aginternalmapinsert(Agraph_t * g, int objtype, char *str,
			 unsigned long result);
char *aginternalmapprint(Agraph_t * g, int objtype, unsigned long id);
int aginternalmapdelete(Agraph_t * g, int objtype, unsigned long id);
void aginternalmapclose(Agraph_t * g);
void agregister(Agraph_t * g, int objtype, void *obj);

	/* internal set operations */
void agedgesetop(Agraph_t * g, Agedge_t * e, int insertion);
void agdelnodeimage(Agraph_t * g, Agnode_t * node, void *ignored);
void agdeledgeimage(Agraph_t * g, Agedge_t * edge, void *ignored);
void *agrebind0(Agraph_t * g, void *obj);	/* unsafe */
int agrename(Agobj_t * obj, char *newname);
void agrecclose(Agobj_t * obj);

void agmethod_init(Agraph_t * g, void *obj);
void agmethod_upd(Agraph_t * g, void *obj, Agsym_t * sym);
void agmethod_delete(Agraph_t * g, void *obj);




void agsyspushdisc(Agraph_t * g, Agcbdisc_t * cb, void *state, int stack);
int agsyspopdisc(Agraph_t * g, Agcbdisc_t * cb, int stack);
void agrecord_callback(Agraph_t * g, Agobj_t * obj, int kind,
		       Agsym_t * optsym);
void aginitcb(Agraph_t * g, void *obj, Agcbstack_t * disc);
void agupdcb(Agraph_t * g, void *obj, Agsym_t * sym, Agcbstack_t * disc);
void agdelcb(Agraph_t * g, void *obj, Agcbstack_t * disc);


#line 66 "graphviz-2.38.0\\lib\\cgraph\\grammar.c" 2
extern void aagerror(char *);	/* gets mapped to aagerror, see below */





static char Key[] = "key";

typedef union s {					/* possible items in generic list */
		Agnode_t		*n;
		Agraph_t		*subg;
		Agedge_t		*e;
		Agsym_t			*asym;	/* bound attribute */
		char			*name;	/* unbound attribute */
		struct item_s	*list;	/* list-of-lists (for edgestmt) */
} val_t;

typedef struct item_s {		/* generic list */
	int				tag;	/* T_node, T_subgraph, T_edge, T_attr */
	val_t			u;		/* primary element */
	char			*str;	/* secondary value - port or attr value */
	struct item_s	*next;
} item;

typedef struct list_s {		/* maintain head and tail ptrs for fast append */
	item			*first;
	item			*last;
} list_t;

typedef struct gstack_s {
	Agraph_t *g;
	Agraph_t *subg;
	list_t	nodelist,edgelist,attrlist;
	struct gstack_s *down;
} gstack_t;

/* functions */
static void appendnode(char *name, char *port, char *sport);
static void attrstmt(int tkind, char *macroname);
static void startgraph(char *name, int directed, int strict);
static void getedgeitems(int x);
static void newedge(Agnode_t *t, char *tport, Agnode_t *h, char *hport, char *key);
static void edgerhs(Agnode_t *n, char *tport, item *hlist, char *key);
static void appendattr(char *name, char *value);
static void bindattrs(int kind);
static void applyattrs(void *obj);
static void endgraph(void);
static void endnode(void);
static void endedge(void);
static char* concat(char*, char*);
static char* concatPort(char*, char*);

static void opensubg(char *name);
static void closesubg(void);

/* global */
static Agraph_t *G;				/* top level graph */
static	Agdisc_t	*Disc;		/* discipline passed to agread or agconcat */
static gstack_t *S;


/* Line 336 of yacc.c  */










/* Enabling verbose error messages.  */







/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */


/* Enabling traces.  */







/* Tokens.  */


   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum aagtokentype {
     T_graph = 258,
     T_node = 259,
     T_edge = 260,
     T_digraph = 261,
     T_subgraph = 262,
     T_strict = 263,
     T_edgeop = 264,
     T_list = 265,
     T_attr = 266,
     T_atom = 267,
     T_qatom = 268
   };

/* Tokens.  */















typedef union YYSTYPE
{
/* Line 350 of yacc.c  */


			int				i;
			char			*str;
			struct Agnode_s	*n;


/* Line 350 of yacc.c  */

} YYSTYPE;





extern YYSTYPE aaglval;











int aagparse ();





/* Copy the second part of user declarations.  */

/* Line 353 of yacc.c  */









typedef unsigned char aagtype_uint8;








typedef short int aagtype_int8;





typedef unsigned short int aagtype_uint16;





typedef short int aagtype_int16;






























/* Suppress unused-variable warnings by "using" E.  */






/* Identity function, used to suppress warnings about constant conditions.  */










    


  





/* The parser invokes alloca or malloc; define the necessary symbols.  */

















      









   


    









































/* A type that is properly aligned for any stack member.  */
union aagalloc
{
  aagtype_int16 aagss_alloc;
  YYSTYPE aagvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */


/* The size of an array large to enough to hold all stacks, each with
   N elements.  */






/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */














/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */

















/* YYFINAL -- State number of the termination state.  */

/* YYLAST -- Last index in YYTABLE.  */


/* YYNTOKENS -- Number of terminals.  */

/* YYNNTS -- Number of nonterminals.  */

/* YYNRULES -- Number of rules.  */

/* YYNRULES -- Number of states.  */


/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */






/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const aagtype_uint8 aagtranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,    17,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,    16,
       2,    19,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    14,     2,    15,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};






       
      
      
      
      
     
     





      
      
       
      
      
      
      
      
      
      
      
      
      
      
      





       
     
     
     
     
     
     








  
  
  
  
  
  
  
  
  
  








       
     
      



/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const aagtype_uint8 aagr1[] =
{
       0,    24,    25,    25,    25,    26,    27,    28,    28,    29,
      29,    30,    30,    31,    31,    32,    32,    33,    33,    34,
      34,    35,    36,    36,    38,    39,    37,    37,    40,    40,
      41,    41,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    49,    49,    50,    51,
      52,    54,    53,    55,    55,    55,    56,    56,    56,    57,
      57,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const aagtype_uint8 aagr2[] =
{
       0,     2,     2,     1,     0,     3,     3,     1,     0,     1,
       0,     1,     1,     1,     0,     2,     1,     1,     0,     2,
       2,     3,     1,     1,     0,     0,     5,     0,     1,     3,
       1,     3,     5,     3,     1,     1,     1,     1,     2,     0,
       1,     0,     4,     2,     0,     2,     1,     1,     3,     2,
       1,     0,     3,     2,     1,     0,     1,     1,     0,     1,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const aagtype_uint8 aagdefact[] =
{
       0,     3,     9,     0,     0,     0,     1,    14,     2,    11,
      12,     8,    35,    36,    37,    54,    59,    61,     0,    13,
      16,    18,    27,    22,    28,    18,    39,    50,    34,    23,
      51,    30,    60,     6,     7,    53,     5,    15,    17,    20,
      24,    41,     0,    19,    41,     0,     0,     0,     0,     0,
      55,    21,    40,    29,    30,     0,    33,    38,    52,    31,
      48,    62,    25,    44,     0,    27,     0,    32,    26,    42,
       0,    43,    58,    46,    47,     0,    49,    56,    57,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const aagtype_int8 aagdefgoto[] =
{
      -1,     3,     8,     4,    33,     5,    11,    18,    19,    39,
      20,    21,    22,    41,    50,    65,    23,    24,    25,    26,
      44,    51,    52,    66,    71,    72,    27,    74,    28,    29,
      46,    30,    79,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */

static const aagtype_int8 aagpact[] =
{
      18,   -18,   -18,    20,     9,     3,   -18,    -2,   -18,   -18,
     -18,     1,   -18,   -18,   -18,     1,   -18,   -18,    10,    -2,
     -18,    19,    25,    21,   -18,    19,     1,   -18,   -18,   -18,
     -18,    11,    17,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,     1,   -18,   -18,    22,     9,     1,     1,    29,
      15,    23,   -18,   -18,    26,    23,    27,   -18,   -18,    28,
     -18,   -18,   -18,   -18,     1,    25,    -5,   -18,   -18,   -18,
       1,   -18,    16,   -18,   -18,    30,   -18,   -18,   -18,   -18
};

/* YYPGOTO[NTERM-NUM].  */
static const aagtype_int8 aagpgoto[] =
{
     -18,   -18,    -1,   -18,   -18,   -18,   -18,   -18,   -18,    31,
      32,   -18,     0,   -17,   -18,   -18,   -18,    12,   -18,   -18,
     -18,     8,    13,   -18,   -18,   -18,    -8,   -18,   -18,   -18,
     -18,   -18,   -18,   -11,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */

static const aagtype_int8 aagtable[] =
{
      34,    12,    13,    14,    35,    15,     9,    16,    17,    10,
      16,    17,   -55,    16,    17,    45,    69,    70,    -4,     1,
       6,   -10,    15,     7,   -10,    36,     2,    16,    17,    47,
      48,    54,    77,    78,    40,    38,    59,    60,    42,    54,
      49,    57,    61,    63,    47,    58,    64,   -40,    68,    48,
      62,    37,    55,    67,    53,    75,    43,    56,    73,    76
};







static const aagtype_uint8 aagcheck[] =
{
      11,     3,     4,     5,    15,     7,     3,    12,    13,     6,
      12,    13,    14,    12,    13,    26,    21,    22,     0,     1,
       0,     3,     7,    14,     6,    15,     8,    12,    13,    18,
      19,    42,    16,    17,     9,    16,    47,    48,    17,    50,
      23,    19,    13,    20,    18,    46,    18,    20,    65,    19,
      50,    19,    44,    64,    42,    66,    25,    44,    66,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const aagtype_uint8 aagstos[] =
{
       0,     1,     8,    25,    27,    29,     0,    14,    26,     3,
       6,    30,     3,     4,     5,     7,    12,    13,    31,    32,
      34,    35,    36,    40,    41,    42,    43,    50,    52,    53,
      55,    57,    58,    28,    57,    57,    15,    34,    16,    33,
       9,    37,    17,    33,    44,    57,    54,    18,    19,    23,
      38,    45,    46,    41,    57,    45,    46,    19,    26,    57,
      57,    13,    36,    20,    18,    39,    47,    57,    37,    21,
      22,    48,    49,    50,    51,    57,    57,    16,    17,    56
};











/* Like YYERROR except do call aagerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */



  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */

























/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

























/* This macro is provided for backward compatibility. */






/* YYLEX -- calling `aaglex' with the right arguments.  */







/* Enable debugging if requested.  */





































    
    
    


  
  
  
    

  
    

  

  
    
      
	
    














    
    
    


  
    
  
    

  
  














    
    


  
  
    
      
      
    
  




















    
    


  
  
  
  
	     
  
  
    
      
      
		       
		       		       
      
    



















/* YYINITDEPTH -- initial size of the parser's stacks.  */




/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */




















    


  
  
    
  

















    
    


  
  

  
    

  















  
    
      
      

      
	
	  
	  
	  
	    

	  
	    
	      
	    
	  
	    
	      
	    
	    

	  
	    
	      
	    
	  
    
    

  
    

  













                

  
  
  
  
  
  
  
  
  

  

  


























  
    
      
      
      
        
          


          
          
          
          
          

          
            
                
              
                
                  
                    
                    
                    
                  
                
                
                
                       
                  
                
              
        
    

  
    




      
      
      
      
      
      

    

  
  
    
  

  
    
      
      
             
        
      
    

  


  
    
    
    
      
        
          
          
        
      
        
          
          
        
  
  



/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/





static void
aagdestruct (aagmsg, aagtype, aagvaluep)
    const char *aagmsg;
    int aagtype;
    YYSTYPE *aagvaluep;

{
  ((void) (aagvaluep));

  if (!aagmsg)
    aagmsg = "Deleting";
  ;

  switch (aagtype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int aagchar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE aaglval;

/* Number of syntax errors so far.  */
int aagnerrs;


/*----------.
| aagparse.  |
`----------*/









    







int
aagparse ()



{
    int aagstate;
    /* Number of tokens to shift before error messages enabled.  */
    int aagerrstatus;

    /* The stacks and their tools:
       `aagss': related to states.
       `aagvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow aagoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    aagtype_int16 aagssa[200];
    aagtype_int16 *aagss;
    aagtype_int16 *aagssp;

    /* The semantic value stack.  */
    YYSTYPE aagvsa[200];
    YYSTYPE *aagvs;
    YYSTYPE *aagvsp;

    unsigned int aagstacksize;

  int aagn;
  int aagresult;
  /* Lookahead token as an internal (translated) token number.  */
  int aagtoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE aagval;


  
  
  
  




  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int aaglen = 0;

  aagtoken = 0;
  aagss = aagssa;
  aagvs = aagvsa;
  aagstacksize = 200;

  ;

  aagstate = 0;
  aagerrstatus = 0;
  aagnerrs = 0;
  aagchar = (-2); /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  aagssp = aagss;
  aagvsp = aagvs;
  goto aagsetstate;

/*------------------------------------------------------------.
| aagnewstate -- Push a new state, which is found in aagstate.  |
`------------------------------------------------------------*/
 aagnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  aagssp++;

 aagsetstate:
  *aagssp = aagstate;

  if (aagss + aagstacksize - 1 <= aagssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      unsigned int aagsize = aagssp - aagss + 1;


      
	


	
	

	



	
		    
		    
		    

	
	
      


      

      /* Extend the stack our own way.  */
      if (10000 <= aagstacksize)
	goto aagexhaustedlab;
      aagstacksize *= 2;
      if (10000 < aagstacksize)
	aagstacksize = 10000;

      {
	aagtype_int16 *aagss1 = aagss;
	union aagalloc *aagptr =
	  (union aagalloc *) malloc (((aagstacksize) * (sizeof (aagtype_int16) + sizeof (YYSTYPE)) + (sizeof (union aagalloc) - 1)));
	if (! aagptr)
	  goto aagexhaustedlab;
	do { unsigned int aagnewbytes; do { unsigned int aagi; for (aagi = 0; aagi < (aagsize); aagi++) (&aagptr->aagss_alloc)[aagi] = (aagss)[aagi]; } while ((0)); aagss = &aagptr->aagss_alloc; aagnewbytes = aagstacksize * sizeof (*aagss) + (sizeof (union aagalloc) - 1); aagptr += aagnewbytes / sizeof (*aagptr); } while ((0));
	do { unsigned int aagnewbytes; do { unsigned int aagi; for (aagi = 0; aagi < (aagsize); aagi++) (&aagptr->aagvs_alloc)[aagi] = (aagvs)[aagi]; } while ((0)); aagvs = &aagptr->aagvs_alloc; aagnewbytes = aagstacksize * sizeof (*aagvs) + (sizeof (union aagalloc) - 1); aagptr += aagnewbytes / sizeof (*aagptr); } while ((0));

	if (aagss1 != aagssa)
	  free (aagss1);
      }



      aagssp = aagss + aagsize - 1;
      aagvsp = aagvs + aagsize - 1;

      ;

      if (aagss + aagstacksize - 1 <= aagssp)
	goto aagabortlab;
    }

  ;

  if (aagstate == 6)
    goto aagacceptlab;

  goto aagbackup;

/*-----------.
| aagbackup.  |
`-----------*/
aagbackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  aagn = aagpact[aagstate];
  if (((aagn) == (-18)))
    goto aagdefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (aagchar == (-2))
    {
      ;
      aagchar = aaglex ();
    }

  if (aagchar <= 0)
    {
      aagchar = aagtoken = 0;
      ;
    }
  else
    {
      aagtoken = ((unsigned int) (aagchar) <= 268 ? aagtranslate[aagchar] : 2);
      ;
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  aagn += aagtoken;
  if (aagn < 0 || 59 < aagn || aagcheck[aagn] != aagtoken)
    goto aagdefault;
  aagn = aagtable[aagn];
  if (aagn <= 0)
    {
      if ((0))
        goto aagerrlab;
      aagn = -aagn;
      goto aagreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (aagerrstatus)
    aagerrstatus--;

  /* Shift the lookahead token.  */
  ;

  /* Discard the shifted token.  */
  aagchar = (-2);

  aagstate = aagn;
  *++aagvsp = aaglval;

  goto aagnewstate;


/*-----------------------------------------------------------.
| aagdefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
aagdefault:
  aagn = aagdefact[aagstate];
  if (aagn == 0)
    goto aagerrlab;
  goto aagreduce;


/*-----------------------------.
| aagreduce -- Do a reduction.  |
`-----------------------------*/
aagreduce:
  /* aagn is the number of a rule to reduce with.  */
  aaglen = aagr2[aagn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  aagval = aagvsp[1-aaglen];


  ;
  switch (aagn)
    {
        case 2:
/* Line 1787 of yacc.c  */

    {endgraph();}
    break;

  case 3:
/* Line 1787 of yacc.c  */

    {if (G) {agclose(G); G = Ag_G_global = ((Agraph_t*)0);}}
    break;

  case 6:
/* Line 1787 of yacc.c  */

    {startgraph((aagvsp[(3) - (3)].str),(aagvsp[(2) - (3)].i),(aagvsp[(1) - (3)].i));}
    break;

  case 7:
/* Line 1787 of yacc.c  */

    {(aagval.str)=(aagvsp[(1) - (1)].str);}
    break;

  case 8:
/* Line 1787 of yacc.c  */

    {(aagval.str)=0;}
    break;

  case 9:
/* Line 1787 of yacc.c  */

    {(aagval.i)=1;}
    break;

  case 10:
/* Line 1787 of yacc.c  */

    {(aagval.i)=0;}
    break;

  case 11:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 0;}
    break;

  case 12:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 1;}
    break;

  case 21:
/* Line 1787 of yacc.c  */

    {if ((aagvsp[(2) - (3)].i)) endedge(); else endnode();}
    break;

  case 24:
/* Line 1787 of yacc.c  */

    {getedgeitems(1);}
    break;

  case 25:
/* Line 1787 of yacc.c  */

    {getedgeitems(2);}
    break;

  case 26:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 1;}
    break;

  case 27:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 0;}
    break;

  case 30:
/* Line 1787 of yacc.c  */

    {appendnode((aagvsp[(1) - (1)].str),((char*)0),((char*)0));}
    break;

  case 31:
/* Line 1787 of yacc.c  */

    {appendnode((aagvsp[(1) - (3)].str),(aagvsp[(3) - (3)].str),((char*)0));}
    break;

  case 32:
/* Line 1787 of yacc.c  */

    {appendnode((aagvsp[(1) - (5)].str),(aagvsp[(3) - (5)].str),(aagvsp[(5) - (5)].str));}
    break;

  case 33:
/* Line 1787 of yacc.c  */

    {attrstmt((aagvsp[(1) - (3)].i),(aagvsp[(2) - (3)].str));}
    break;

  case 34:
/* Line 1787 of yacc.c  */

    {attrstmt(258,((char*)0));}
    break;

  case 35:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 258;}
    break;

  case 36:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 259;}
    break;

  case 37:
/* Line 1787 of yacc.c  */

    {(aagval.i) = 260;}
    break;

  case 38:
/* Line 1787 of yacc.c  */

    {(aagval.str) = (aagvsp[(1) - (2)].str);}
    break;

  case 39:
/* Line 1787 of yacc.c  */

    {(aagval.str) = ((char*)0); }
    break;

  case 48:
/* Line 1787 of yacc.c  */

    {appendattr((aagvsp[(1) - (3)].str),(aagvsp[(3) - (3)].str));}
    break;

  case 49:
/* Line 1787 of yacc.c  */

    {appendattr((aagvsp[(2) - (2)].str),((char*)0));}
    break;

  case 51:
/* Line 1787 of yacc.c  */

    {opensubg((aagvsp[(1) - (1)].str));}
    break;

  case 52:
/* Line 1787 of yacc.c  */

    {closesubg();}
    break;

  case 53:
/* Line 1787 of yacc.c  */

    {(aagval.str)=(aagvsp[(2) - (2)].str);}
    break;

  case 54:
/* Line 1787 of yacc.c  */

    {(aagval.str)=((char*)0);}
    break;

  case 55:
/* Line 1787 of yacc.c  */

    {(aagval.str)=((char*)0);}
    break;

  case 59:
/* Line 1787 of yacc.c  */

    {(aagval.str) = (aagvsp[(1) - (1)].str);}
    break;

  case 60:
/* Line 1787 of yacc.c  */

    {(aagval.str) = (aagvsp[(1) - (1)].str);}
    break;

  case 61:
/* Line 1787 of yacc.c  */

    {(aagval.str) = (aagvsp[(1) - (1)].str);}
    break;

  case 62:
/* Line 1787 of yacc.c  */

    {(aagval.str) = concat((aagvsp[(1) - (3)].str),(aagvsp[(3) - (3)].str));}
    break;


/* Line 1787 of yacc.c  */

      default: break;
    }
  /* User semantic actions sometimes alter aagchar, and that requires
     that aagtoken be updated with the new translation.  We take the
     approach of translating immediately before every use of aagtoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering aagchar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  ;

  (aagvsp -= (aaglen), aagssp -= (aaglen));
  aaglen = 0;
  ;

  *++aagvsp = aagval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  aagn = aagr1[aagn];

  aagstate = aagpgoto[aagn - 24] + *aagssp;
  if (0 <= aagstate && aagstate <= 59 && aagcheck[aagstate] == *aagssp)
    aagstate = aagtable[aagstate];
  else
    aagstate = aagdefgoto[aagn - 24];

  goto aagnewstate;


/*------------------------------------.
| aagerrlab -- here on detecting error |
`------------------------------------*/
aagerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  aagtoken = aagchar == (-2) ? (-2) : ((unsigned int) (aagchar) <= 268 ? aagtranslate[aagchar] : 2);

  /* If not already recovering from an error, report this error.  */
  if (!aagerrstatus)
    {
      ++aagnerrs;

      aagerror ("syntax error");



      
        
        
        
        
          
        
          
            
              
            
            
              
                
                
                
              
            
              
                
                
              
          
        
        
          
      


    }



  if (aagerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (aagchar <= 0)
	{
	  /* Return failure if at end of input.  */
	  if (aagchar == 0)
	    goto aagabortlab;
	}
      else
	{
	  aagdestruct ("Error: discarding",
		      aagtoken, &aaglval);
	  aagchar = (-2);
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto aagerrlab1;


/*---------------------------------------------------.
| aagerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
aagerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label aagerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto aagerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  (aagvsp -= (aaglen), aagssp -= (aaglen));
  aaglen = 0;
  ;
  aagstate = *aagssp;
  goto aagerrlab1;


/*-------------------------------------------------------------.
| aagerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
aagerrlab1:
  aagerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      aagn = aagpact[aagstate];
      if (!((aagn) == (-18)))
	{
	  aagn += 1;
	  if (0 <= aagn && aagn <= 59 && aagcheck[aagn] == 1)
	    {
	      aagn = aagtable[aagn];
	      if (0 < aagn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (aagssp == aagss)
	goto aagabortlab;


      aagdestruct ("Error: popping",
		  aagstos[aagstate], aagvsp);
      (aagvsp -= (1), aagssp -= (1));
      aagstate = *aagssp;
      ;
    }

  *++aagvsp = aaglval;


  /* Shift the error token.  */
  ;

  aagstate = aagn;
  goto aagnewstate;


/*-------------------------------------.
| aagacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
aagacceptlab:
  aagresult = 0;
  goto aagreturn;

/*-----------------------------------.
| aagabortlab -- YYABORT comes here.  |
`-----------------------------------*/
aagabortlab:
  aagresult = 1;
  goto aagreturn;


/*-------------------------------------------------.
| aagexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
aagexhaustedlab:
  aagerror ("memory exhausted");
  aagresult = 2;
  /* Fall through.  */


aagreturn:
  if (aagchar != (-2))
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      aagtoken = ((unsigned int) (aagchar) <= 268 ? aagtranslate[aagchar] : 2);
      aagdestruct ("Cleanup: discarding lookahead",
                  aagtoken, &aaglval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  (aagvsp -= (aaglen), aagssp -= (aaglen));
  ;
  while (aagssp != aagss)
    {
      aagdestruct ("Cleanup: popping",
		  aagstos[*aagssp], aagvsp);
      (aagvsp -= (1), aagssp -= (1));
    }

  if (aagss != aagssa)
    free (aagss);


  
    

  /* Make sure YYID is used.  */
  return (aagresult);
}


/* Line 2048 of yacc.c  */






static item *newitem(int tag, void *p0, char *p1)
{
	item	*rv = agalloc(G,sizeof(item));
	rv->tag = tag; rv->u.name = (char*)p0; rv->str = p1;
	return rv;
}

static item *cons_node(Agnode_t *n, char *port)
	{ return newitem(259,n,port); }

static item *cons_attr(char *name, char *value)
	{ return newitem(267,name,value); }

static item *cons_list(item *list)
	{ return newitem(265,list,((char*)0)); }

static item *cons_subg(Agraph_t *subg)
	{ return newitem(262,subg,((char*)0)); }

static gstack_t *push(gstack_t *s, Agraph_t *subg) {
	gstack_t *rv;
	rv = agalloc(G,sizeof(gstack_t));
	rv->down = s;
	rv->g = subg;
	return rv;
}

static gstack_t *pop(gstack_t *s)
{
	gstack_t *rv;
	rv = S->down;
	agfree(G,s);
	return rv;
}



	


static void delete_items(item *ilist)
{
	item	*p,*pn;

	for (p = ilist; p; p = pn) {
		pn = p->next;
		switch(p->tag) {
			case 265: delete_items(p->u.list); break;
			case 267: case 266: agstrfree(G,p->str); break;
		}
		agfree(G,p);
	}
}




	



static void deletelist(list_t *list)
{
	delete_items(list->first);
	list->first = list->last = ((item*)0);
}




	
	
	



static void listapp(list_t *list, item *v)
{
	if (list->last) list->last->next = v;
	list->last = v;
	if (list->first == ((item*)0)) list->first = v;
}


/* attrs */
static void appendattr(char *name, char *value)
{
	item		*v;

	;
	v = cons_attr(name,value);
	listapp(&(S->attrlist),v);
}

static void bindattrs(int kind)
{
	item		*aptr;
	char		*name;

	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
		;	/* signifies unbound attr */
		name = aptr->u.name;
		if ((kind == AGEDGE) && ((*name == *Key) && !strcmp((name),(Key)))) continue;
		if ((aptr->u.asym = agattr(S->g,kind,name,((char*)0))) == ((Agsym_t*)0))
			aptr->u.asym = agattr(S->g,kind,name,"");
		aptr->tag = 266;				/* signifies bound attr */
		agstrfree(G,name);
	}
}

/* attach node/edge specific attributes */
static void applyattrs(void *obj)
{
	item		*aptr;

	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
		if (aptr->tag == 266) {
			if (aptr->u.asym) {
				agxset(obj,aptr->u.asym,aptr->str);
			}
		}
		else {
			;
			;
			;
		}
	}
}

static void nomacros(void)
{
	agerr(AGWARN,"attribute macros not implemented");
}

/* attrstmt:
 * First argument is always attrtype, so switch covers all cases.
 * This function is used to handle default attribute value assignment.
 */
static void attrstmt(int tkind, char *macroname)
{
	item			*aptr;
	int				kind;
	Agsym_t*  sym;

		/* creating a macro def */
	if (macroname) nomacros();
		/* invoking a macro def */
	for (aptr = S->attrlist.first; aptr; aptr = aptr->next)
		if (aptr->str == ((char*)0)) nomacros();

	switch(tkind) {
		case 258: kind = AGRAPH; break;
		case 259: kind = AGNODE; break;
		case 260: kind = AGEDGE; break;
	}
	bindattrs(kind);	/* set up defaults for new attributes */
	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
		if (!(aptr->u.asym->fixed) || (S->g != G))
			sym = agattr(S->g,kind,aptr->u.asym->name,aptr->str);
		else
			sym = aptr->u.asym;
		if (S->g == G)
			sym->print = (!(0));
	}
	deletelist(&(S->attrlist));
}

/* nodes */

static void appendnode(char *name, char *port, char *sport)
{
	item		*elt;

	if (sport) {
		port = concatPort (port, sport);
	}
	elt = cons_node(agnode(S->g,name,(!(0))),port);
	listapp(&(S->nodelist),elt);
	agstrfree(G,name);
}

/* apply current optional attrs to nodelist and clean up lists */
/* what's bad is that this could also be endsubg.  also, you can't
clean up S->subg in closesubg() because S->subg might be needed
to construct edges.  these are the sort of notes you write to yourself
in the future. */
static void endnode()
{
	item	*ptr;

	bindattrs(AGNODE);
	for (ptr = S->nodelist.first; ptr; ptr = ptr->next)
		applyattrs(ptr->u.n);
	deletelist(&(S->nodelist));
	deletelist(&(S->attrlist));
	deletelist(&(S->edgelist));
	S->subg = 0;  /* notice a pattern here? :-( */
}

/* edges - store up node/subg lists until optional edge key can be seen */

static void getedgeitems(int x)
{
	item	*v = 0;

	if (S->nodelist.first) {
		v = cons_list(S->nodelist.first);
		S->nodelist.first = S->nodelist.last = ((item*)0);
	}
	else {if (S->subg) v = cons_subg(S->subg); S->subg = 0;}
	/* else nil append */
	if (v) listapp(&(S->edgelist),v);
}

static void endedge(void)
{
	char			*key;
	item			*aptr,*tptr,*p;

	Agnode_t		*t;
	Agraph_t		*subg;

	bindattrs(AGEDGE);

	/* look for "key" pseudo-attribute */
	key = ((char*)0);
	for (aptr = S->attrlist.first; aptr; aptr = aptr->next) {
		if ((aptr->tag == 267) && ((*aptr->u.name == *Key) && !strcmp((aptr->u.name),(Key))))
			key = aptr->str;
	}

	/* can make edges with node lists or subgraphs */
	for (p = S->edgelist.first; p->next; p = p->next) {
		if (p->tag == 262) {
			subg = p->u.subg;
			for (t = agfstnode(subg); t; t = agnxtnode(subg,t))
				edgerhs(agsubnode(S->g,t,(0)),((char*)0),p->next,key);
		}
		else {
			for (tptr = p->u.list; tptr; tptr = tptr->next)
				edgerhs(tptr->u.n,tptr->str,p->next,key);
		}
	}
	deletelist(&(S->nodelist));
	deletelist(&(S->edgelist));
	deletelist(&(S->attrlist));
	S->subg = 0;
}

/* concat:
 */
static char*
concat (char* s1, char* s2)
{
  char*  s;
  char   buf[BUFSIZ];
  char*  sym;
  int    len = strlen(s1) + strlen(s2) + 1;

  if (len <= BUFSIZ) sym = buf;
  else sym = (char*)malloc(len);
  strcpy(sym,s1);
  strcat(sym,s2);
  s = agstrdup (G,sym);
  agstrfree (G,s1);
  agstrfree (G,s2);
  if (sym != buf) free (sym);
  return s;
}

/* concatPort:
 */
static char*
concatPort (char* s1, char* s2)
{
  char*  s;
  char   buf[BUFSIZ];
  char*  sym;
  int    len = strlen(s1) + strlen(s2) + 2;  /* one more for ':' */

  if (len <= BUFSIZ) sym = buf;
  else sym = (char*)malloc(len);
  sprintf (sym, "%s:%s", s1, s2);
  s = agstrdup (G,sym);
  agstrfree (G,s1);
  agstrfree (G,s2);
  if (sym != buf) free (sym);
  return s;
}


static void edgerhs(Agnode_t *tail, char *tport, item *hlist, char *key)
{
	Agnode_t		*head;
	Agraph_t		*subg;
	item			*hptr;

	if (hlist->tag == 262) {
		subg = hlist->u.subg;
		for (head = agfstnode(subg); head; head = agnxtnode(subg,head))
			newedge(tail,tport,agsubnode(S->g,head,(0)),((char*)0),key);
	}
	else {
		for (hptr = hlist->u.list; hptr; hptr = hptr->next)
			newedge(tail,tport,agsubnode(S->g,hptr->u.n,(0)),hptr->str,key);
	}
}

static void mkport(Agedge_t *e, char *name, char *val)
{
	Agsym_t *attr;
	if (val) {
		if ((attr = agattr(S->g,AGEDGE,name,((char*)0))) == ((Agsym_t*)0))
			attr = agattr(S->g,AGEDGE,name,"");
		agxset(e,attr,val);
	}
}

static void newedge(Agnode_t *t, char *tport, Agnode_t *h, char *hport, char *key)
{
	Agedge_t 	*e;

	e = agedge(S->g,t,h,key,(!(0)));
	if (e) {		/* can fail if graph is strict and t==h */
		char    *tp = tport;
		char    *hp = hport;
		if ((agtail(e) != aghead(e)) && (aghead(e) == t)) {
			/* could happen with an undirected edge */
			char    *temp;
			temp = tp; tp = hp; hp = temp;
		}
		mkport(e,"tailport",tp);
		mkport(e,"headport",hp);
		applyattrs(e);
	}
}

/* graphs and subgraphs */


static void startgraph(char *name, int directed, int strict)
{
	static Agdesc_t	req;	/* get rid of warnings */

	if (G == ((Agraph_t*)0)) {
		req.directed = directed;
		req.strict = strict;
		req.maingraph = (!(0));
		Ag_G_global = G = agopen(name,req,Disc);
	}
	else {
		Ag_G_global = G;
	}
	S = push(S,G);
	agstrfree(((Agraph_t*)0),name);
}

static void endgraph()
{
	aglexeof();
	aginternalmapclearlocalnames(G);
}

static void opensubg(char *name)
{
	S = push(S,agsubg(S->g,name,(!(0))));
	agstrfree(G,name);
}

static void closesubg()
{
	Agraph_t *subg = S->g;
	S = pop(S);
	S->subg = subg;
	;
}

extern FILE *aagin;
Agraph_t *agconcat(Agraph_t *g, void *chan, Agdisc_t *disc)
{
	aagin = chan;
	G = g;
	Ag_G_global = ((Agraph_t*)0);
	Disc = (disc? disc :  &AgDefaultDisc);
	aglexinit(Disc, chan);
	aagparse();
	if (Ag_G_global == ((Agraph_t*)0)) aglexbad();
	return Ag_G_global;
}

Agraph_t *agread(void *fp, Agdisc_t *disc) {return agconcat(((Agraph_t*)0),fp,disc); }


