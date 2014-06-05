#line 1 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 1
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







































typedef unsigned int boolean;
extern unsigned char Verbose;




















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





#line 16 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 1
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











#line 17 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 2
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


























#line 18 "graphviz-2.38.0\\lib\\sparse\\DotIO.h" 2

enum {COLOR_SCHEME_NONE, COLOR_SCHEME_PASTEL = 1, COLOR_SCHEME_BLUE_YELLOW, COLOR_SCHEME_WHITE_RED, COLOR_SCHEME_GREY_RED, COLOR_SCHEME_PRIMARY, COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED, COLOR_SCHEME_ADAM, COLOR_SCHEME_ADAM_BLEND, COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED_LIGHTER, COLOR_SCHEME_GREY};
extern void initDotIO (Agraph_t *g);
extern Agraph_t* SparseMatrix_read_dot(FILE*);

extern void setDotNodeID (Agnode_t* n, int v);
extern int getDotNodeID (Agnode_t* n);

extern void attach_edge_colors(Agraph_t* g, int dim, double *colors);

extern void attach_embedding(Agraph_t *g, int dim, double sc, double *x);

extern SparseMatrix SparseMatrix_import_dot(Agraph_t* g, int dim, double **label_sizes, double **x, int *n_edge_label_nodes,
					    int **edge_label_nodes, int format, SparseMatrix *D);
extern Agraph_t* makeDotGraph (SparseMatrix, char *title, int dim, double *x, int with_color, int with_label, int use_matrix_value);
Agraph_t *convert_edge_labels_to_nodes(Agraph_t* g);
Agraph_t* assign_random_edge_color(Agraph_t* g);
void dump_coordinates(char *name, int n, int dim, double *x);
void edgelist_export(FILE* f, SparseMatrix A, int dim, double *x);
char * hue2rgb(double hue, char *color);

SparseMatrix Import_coord_clusters_from_dot(Agraph_t* g, int maxcluster, int dim, int *nn, double **label_sizes, double **x, int **clusters, float **rgb_r,  float **rgb_g,  float **rgb_b,  float **fsz, char ***labels, int default_color_scheme, int clustering_scheme, int useClusters);

void Dot_SetClusterColor(Agraph_t* g, float *rgb_r,  float *rgb_g,  float *rgb_b, int *clustering);
void attached_clustering(Agraph_t* g, int maxcluster, int clustering_scheme);

int Import_dot_splines(Agraph_t* g, int *ne, char ***xsplines);

#line 17 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\clustering.h" 1
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




typedef struct Multilevel_Modularity_Clustering_struct *Multilevel_Modularity_Clustering;

struct Multilevel_Modularity_Clustering_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A; /* n x n matrix */
  SparseMatrix P; 
  SparseMatrix R; 
  Multilevel_Modularity_Clustering next;
  Multilevel_Modularity_Clustering prev;
  int delete_top_level_A;
  int *matching; /* dimension n. matching[i] is the clustering assignment of node i */
  double modularity;
  double deg_total; /* total edge weights, including self-edges */
  double *deg;/* dimension n. deg[i] equal to the sum of edge weights connected to vertex i. I.e., sum of  row i */
  int agglomerate_regardless;/* whether to agglomerate nodes even if this causes modularity reduction. This is used if we want to force
				agglomeration so as to get less clusters
			      */


};

enum {CLUSTERING_MODULARITY = 0, CLUSTERING_MQ};

/* find a clustering of vertices by maximize modularity
   A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
   inplace: whether A can e modified. If true, A will be modified by removing diagonal.

   maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
   .   is desired. this may not always be realized, and modularity may be low when this is specified. Default: maxcluster = 0 (no limit)

   use_value: whether to use the entry value, or treat edge weights as 1.
   nclusters: on output the number of clusters
   assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters.
   .   If *assignment = NULL on entry, it will be allocated. Otherwise used.
   modularity: achieve modularity
*/
void modularity_clustering(SparseMatrix A, int inplace, int maxcluster, int use_value,
			   int *nclusters, int **assignment, double *modularity, int *flag);


#line 18 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\mq.h" 1
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




typedef struct Multilevel_MQ_Clustering_struct *Multilevel_MQ_Clustering;

struct Multilevel_MQ_Clustering_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A; /* n x n matrix */
  SparseMatrix P; 
  SparseMatrix R; 
  Multilevel_MQ_Clustering next;
  Multilevel_MQ_Clustering prev;
  int delete_top_level_A;
  int *matching; /* dimension n. matching[i] is the clustering assignment of node i */

  /*

   .                                 |E(i,i)|                                     |E(i,j)|
   MQ/2 = (1/k) * \sum_{i=1...k} ------------ - (1/(k*(k-1))) * \sum_{i<j} -------------------  
   .                                |V(i)|^2                                   |V(i)|*|V(j)|
   .   = mq_in/k - mq_out/(k*(k-1))
  */

  double mq;
  double mq_in, mq_out;/* mqs(A) = deg_in(A)/|A|^2 - deg_out(A)/|A|/(|V|-|A|) */
  int ncluster; /* number of clusters */

  double *deg_intra;/* dimension n. deg[i] equal to the sum of edge weights within cluster i */
  double *dout;/* dimension n, dout[i] = \sum_{j -- i} a(i,j)/|j| is the scaled sum of outdegree */
  double *wgt; /* total vertex weight each coarse grid vertex represent */
};

/* find a clustering of vertices by maximize modularity quality
   A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
   inplace: whether A can e modified. If true, A will be modified by removing diagonal.

   maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
   .   is desired. this may not always be realized, and modularity quality may be low when this is specified. Default: maxcluster = 0 (no limit)

   use_value: whether to use the entry value, or treat edge weights as 1.
   nclusters: on output the number of clusters
   assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters.
   .   If *assignment = NULL on entry, it will be allocated. Otherwise used.
   mq: achieve modularity
*/
void mq_clustering(SparseMatrix A, int inplace, int maxcluster, int use_value,
			   int *nclusters, int **assignment, double *mq, int *flag);


#line 19 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2
/* #include "spring_electrical.h" */
#line 1 "graphviz-2.38.0\\lib\\sparse\\color_palette.h" 1
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



#line 1 "graphviz-2.38.0\\lib\\sparse\\color_palette.h" 1
enum {MAX_COLOR = 1001};

enum {npalettes = 265};
extern int knownColorScheme (char*);
extern char *color_palettes[npalettes][2];
  /* return a list of rgb in hex form: "#ff0000,#00ff00,..." */
extern char *color_palettes_get(char *color_palette_name);
extern void color_palettes_name_print(FILE *fp);
extern int color_palettes_Q(char *color_palette_name);

extern float palette_pastel[1001][3];
extern float palette_blue_to_yellow[1001][3];
extern float palette_grey_to_red[1001][3];
extern float palette_grey_to_red[1001][3];
extern float palette_white_to_red[1001][3];
extern float palette_grey[1001][3];
extern float palette_primary[1001][3];
extern float palette_sequential_singlehue_red[1001][3];
extern float palette_sequential_singlehue_red_lighter[1001][3];
extern float palette_adam_blend[1001][3];
extern float palette_adam[11][3];




#line 21 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\colorutil.h" 1
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









#line 17 "graphviz-2.38.0\\lib\\sparse\\colorutil.h" 2

extern int colorxlate(char *str, gvcolor_t * color, color_type_t target_type);

void rgb2hex(float r, float g, float b, char *cstring, char* opacity);/* dimension of cstring must be >=7 */
char* hue2rgb(double hue, char *color);
void hue2rgb_real(double hue, double *color);


#line 22 "graphviz-2.38.0\\lib\\sparse\\DotIO.c" 2

typedef struct {
    Agrec_t h;
    unsigned int id;
} Agnodeinfo_t;







  
  
  

  
  
    
      
    
      
    
    
    
    
  





  
  

  
  

  
    

  
    
    
    
    
  
  



static void color_string(int slen, char *buf, int dim, double *color){
  if (dim > 3 || dim < 1){
    fprintf(stderr,"can only 1, 2 or 3 dimensional color space. with color value between 0 to 1\n");
    assert(0);
  }
  assert(slen >= 3);
  if (dim == 3){
    sprintf(buf,"#%02x%02x%02x", (((unsigned int)(color[0]*255))<(255)?((unsigned int)(color[0]*255)):255), 
	    (((unsigned int)(color[1]*255))<(255)?((unsigned int)(color[1]*255)):255), (((unsigned int)(color[2]*255))<(255)?((unsigned int)(color[2]*255)):255));
  } else if (dim == 1){
    sprintf(buf,"#%02x%02x%02x", (((unsigned int)(color[0]*255))<(255)?((unsigned int)(color[0]*255)):255), 
	    (((unsigned int)(color[0]*255))<(255)?((unsigned int)(color[0]*255)):255), (((unsigned int)(color[0]*255))<(255)?((unsigned int)(color[0]*255)):255));
  } else if (dim == 2){
    sprintf(buf,"#%02x%02x%02x", (((unsigned int)(color[0]*255))<(255)?((unsigned int)(color[0]*255)):255), 
	    0, (((unsigned int)(color[1]*255))<(255)?((unsigned int)(color[1]*255)):255));
  }
}

void attach_edge_colors(Agraph_t* g, int dim, double *colors){
  /* colors is array of dim*nedges, with color for edge i at colors[dim*i, dim(i+1))
   */
  Agsym_t* sym = agattr(g, 2, "color", 0); 
  Agedge_t* e;
  Agnode_t* n;
  enum {slen = 1024};
  char buf[slen];
  int row, col;
  int ie = 0;

  if (!sym)
    sym = agattr (g, 2, "color", "");

  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    row = (((Agnodeinfo_t*)((n)->base.data))->id);
    for (e = agfstout (g, n); e; e = agnxtout (g, e)) {
      col = (((Agnodeinfo_t*)((((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))->base.data))->id);
      if (row == col) continue;
      color_string(slen, buf, dim, colors + ie*dim);
      agxset(e, sym, buf);
      ie++;
    }
  }

}

/* SparseMatrix_read_dot:
 * Wrapper for reading dot graph from file
 */
Agraph_t* 
SparseMatrix_read_dot(FILE* f)
{
    Agraph_t* g;
    g = agread (f, 0);
    aginit(g, 1, "nodeinfo", sizeof(Agnodeinfo_t), 1);
    return g;
}

/* SparseMatrix_import_dot:
 * Assumes g is connected and simple, i.e., we can have a->b and b->a
 * but not a->b and a->b
 */
SparseMatrix 
SparseMatrix_import_dot (Agraph_t* g, int dim, double **label_sizes, double **x, int *n_edge_label_nodes, int **edge_label_nodes, int format, SparseMatrix *D)
{
  SparseMatrix A = 0;
  Agnode_t* n;
  Agedge_t* e;
  Agsym_t *sym, *symD = NULL;
  Agsym_t *psym;
  int nnodes;
  int nedges;
  int i, row;
  int* I;
  int* J;
  double *val, *valD = NULL;
  double v;
  int type = MATRIX_TYPE_REAL;
  size_t sz = sizeof(double);
  double padding = 10;
  int nedge_nodes = 0;



  if (!g) return NULL;
  nnodes = agnnodes (g);
  nedges = agnedges (g);
  if (format != FORMAT_CSR && format != FORMAT_COORD) {
    fprintf (stderr, "Format %d not supported\n", format);
    exit (1);
  }

  /* Assign node ids */
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n))
    (((Agnodeinfo_t*)((n)->base.data))->id) = i++;

  if (format == FORMAT_COORD){
    A = SparseMatrix_new(i, i, nedges, MATRIX_TYPE_REAL, format);
    A->nz = nedges;
    I = A->ia;
    J = A->ja;
    val = (double*) A->a;
  } else {
    I = (int*)malloc((nedges)*sizeof(int));
    J = (int*)malloc((nedges)*sizeof(int));
    val = (double*)malloc((nedges)*sizeof(double));
  }


  if (format == FORMAT_COORD){
    A = SparseMatrix_new(i, i, nedges, MATRIX_TYPE_REAL, format);
    A->nz = nedges;
    I = A->ia;
    J = A->ja;
    val = (double*) A->a;
  } else {
    I = (int*)malloc((nedges)*sizeof(int));
    J = (int*)malloc((nedges)*sizeof(int));
    val = (double*)malloc((nedges)*sizeof(double));
  }

  sym = agattr(g, 2, "weight", NULL);
  if (D) {
    symD = agattr(g, 2, "len", NULL);
    valD = (double*)malloc((nedges)*sizeof(double));
  }
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    if (edge_label_nodes && strncmp(agnameof(n), "|edgelabel|",11)==0) nedge_nodes++;
    row = (((Agnodeinfo_t*)((n)->base.data))->id);
    for (e = agfstout (g, n); e; e = agnxtout (g, e)) {
      I[i] = row;
      J[i] = (((Agnodeinfo_t*)((((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))->base.data))->id);

      /* edge weight */
      if (sym) {
        if (sscanf (agxget(e,sym), "%lf", &v) != 1) v = 1;
      } else {
        v = 1;
      }
      val[i] = v;

      /* edge length */
      if (symD) {
        if (sscanf (agxget (e, symD), "%lf", &v) != 1) {
          v = 72;
        } else {
          v *= 72;/* len is specified in inch. Convert to points */
        }
	valD[i] = v;
      } else if (valD) {
        valD[i] = 72;
      }

      i++;
    }
  }
  
  if (edge_label_nodes) {
    *edge_label_nodes = malloc(sizeof(int)*nedge_nodes);
    nedge_nodes = 0;
  }


  if (label_sizes) *label_sizes = malloc(sizeof(double)*2*nnodes);
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    double sz;
    i = (((Agnodeinfo_t*)((n)->base.data))->id);
    if (edge_label_nodes && strncmp(agnameof(n), "|edgelabel|",11)==0) {
      (*edge_label_nodes)[nedge_nodes++] = i;
    }
    if (label_sizes){
      if (agget(n, "width") && agget(n, "height")){
	sscanf(agget(n, "width"), "%lf", &sz);
	/*      (*label_sizes)[i*2] = POINTS(sz)*.6;*/
	(*label_sizes)[i*2] = 72*(sz)*.5 + padding*0.5;
	sscanf(agget(n, "height"), "%lf", &sz);
	/*(*label_sizes)[i*2+1] = POINTS(sz)*.6;*/
	(*label_sizes)[i*2+1] = 72*(sz)*.5  + padding*0.5;
      } else {
	(*label_sizes)[i*2] = 4*72*(0.75)*.5;
	(*label_sizes)[i*2+1] = 4*72*(0.5)*.5;
      }
    }
  }

  if (x && (psym = agattr(g, 1, "pos", NULL))) {
    int has_positions = 1;
    char* pval;
    if (!(*x)) {
      *x = malloc(sizeof(double)*dim*nnodes);
      assert(*x);
    }
    for (n = agfstnode (g); n && has_positions; n = agnxtnode (g, n)) {
      double xx,yy, zz,ww;
      int nitems;
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      if ((pval = agxget(n, psym)) && *pval) {
	if (dim == 2){
	  nitems = sscanf(pval, "%lf,%lf", &xx, &yy);
	  if (nitems != 2) {
            has_positions = 0;
            agerr(AGERR, "Node \"%s\" pos has %d < 2 values", agnameof(n), nitems);
	  }
	  (*x)[i*dim] = xx;
	  (*x)[i*dim+1] = yy;
	} else if (dim == 3){
	  nitems = sscanf(pval, "%lf,%lf,%lf", &xx, &yy, &zz);
	  if (nitems != 3) {
            has_positions = 0;
            agerr(AGERR, "Node \"%s\" pos has %d < 3 values", agnameof(n), nitems);
	  }
	  (*x)[i*dim] = xx;
	  (*x)[i*dim+1] = yy;
	  (*x)[i*dim+2] = zz;
	} else if (dim == 4){
	  nitems = sscanf(pval, "%lf,%lf,%lf,%lf", &xx, &yy, &zz,&ww);
	  if (nitems != 4) {
            has_positions = 0;
            agerr(AGERR, "Node \"%s\" pos has %d < 4 values", agnameof(n), nitems);
	  }
	  (*x)[i*dim] = xx;
	  (*x)[i*dim+1] = yy;
	  (*x)[i*dim+2] = zz;
	  (*x)[i*dim+3] = ww;
	} else if (dim == 1){
	  nitems = sscanf(pval, "%lf", &xx);
	  if (nitems != 1) return NULL;
	  (*x)[i*dim] = xx;
	} else {
	  assert(0);
	}
      } else {
        has_positions = 0;
	agerr(AGERR, "Node \"%s\" lacks position info", agnameof(n));
      }
    }
    if (!has_positions) {
      free(*x);
      *x = NULL;
    }
  }
  else if (x)
    agerr (AGERR, "Error: graph %s has missing \"pos\" information", agnameof(g));

  if (format == FORMAT_CSR) A = SparseMatrix_from_coordinate_arrays(nedges, nnodes, nnodes, I, J, val, type, sz);
  if (edge_label_nodes) *n_edge_label_nodes = nedge_nodes;

  if (D) *D = SparseMatrix_from_coordinate_arrays(nedges, nnodes, nnodes, I, J, valD, type, sz);

  if (format != FORMAT_COORD){
    free(I);
    free(J);
    free(val);
  }
  if (valD) free(valD);

  return A;
}


static double dist(int dim, double *x, double *y){
  int k;
  double d = 0;
  for (k = 0; k < dim; k++) d += (x[k] - y[k])*(x[k]-y[k]);
  return sqrt(d);
}

/* get spline info */
int Import_dot_splines(Agraph_t* g, int *ne, char ***xsplines){
  /* get the list of splines for the edges in the order they appear, and store as a list of strings in xspline.
     If *xsplines = NULL, it will be allocated. On exit (*xsplines)[i] is the control point string for the i-th edge. This string
     is of the form "x1,y1 x2,y2...", the two end points of the edge is not included per Dot format 
     Return 1 if success. 0 if not.
  */
  Agnode_t* n;
  Agedge_t* e;
  Agsym_t *sym;
  int nedges;
  int i;

  if (!g){
    return 0;
  }

  *ne = nedges = agnedges (g);

  /* Assign node ids */
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n))
    (((Agnodeinfo_t*)((n)->base.data))->id) = i++;

  sym = agattr(g, 2, "pos", 0); 
  if (!sym) return 0;
 
  if (!(*xsplines)) *xsplines = malloc(sizeof(char*)*nedges);

  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    for (e = agfstout (g, n); e; e = agnxtout (g, e)) {
      /* edge weight */
      if (sym) {
	char *pos = agxget (e, sym);
	(*xsplines)[i] = malloc(sizeof(char)*(strlen(pos)+1));
	strcpy((*xsplines)[i], pos);
      } else {
	(*xsplines)[i] = NULL;
      }
      i++;
    }
  }
  return 1;
}

void edgelist_export(FILE* f, SparseMatrix A, int dim, double *x){
  int n = A->m, *ia = A->ia, *ja = A->ja;
  int i, j, len;
  double max_edge_len, min_edge_len;

  for (i = 0; i < n; i++){
    for (j = ia[i]; j < ia[i+1]; j++){
      max_edge_len = ((max_edge_len)>(dist(dim, &x[dim*i], &x[dim*ja[j]]))?(max_edge_len):dist(dim, &x[dim*i], &x[dim*ja[j]]));
      if (min_edge_len < 0){
	min_edge_len = dist(dim, &x[dim*i], &x[dim*ja[j]]);
      } else {
	min_edge_len = ((min_edge_len)<(dist(dim, &x[dim*i], &x[dim*ja[j]]))?(min_edge_len):dist(dim, &x[dim*i], &x[dim*ja[j]]));
      }
    }
  }
  /* format:
     n
     nz
     dim
     x (length n*dim)
     min_edge_length
     max_edge_length
     v1
     neighbors of v1
     v2
     neighbors of v2
     ...
  */
  fprintf(stderr,"writing a total of %d edges\n",A->nz);
  fwrite(&(A->n), sizeof(int), 1, f);
  fwrite(&(A->nz), sizeof(int), 1, f);
  fwrite(&dim, sizeof(int), 1, f);
  fwrite(x, sizeof(double), dim*n, f);
  fwrite(&min_edge_len, sizeof(double), 1, f);
  fwrite(&max_edge_len, sizeof(double), 1, f);
  for (i = 0; i < n; i++){
    if (i%1000 == 0) fprintf(stderr,"%6.2f%% done\r", i/(double) n*100);
    fwrite(&i, sizeof(int), 1, f);
    len = ia[i+1] - ia[i];
    fwrite(&len, sizeof(int), 1, f);
    fwrite(&(ja[ia[i]]), sizeof(int), len, f);
  }
}


void dump_coordinates(char *name, int n, int dim, double *x){
  char fn[1000];
  FILE *fp;
  int i, k;

  if (!name){
    name = "";
  } else {
    name = strip_dir(name);
  }
  
  strcpy(fn, name);
  strcat(fn,".x");
  fp = fopen(fn,"w");
  fprintf(fp, "%d %d\n",n, dim);
  for (i = 0; i < n; i++){
    for (k = 0; k < dim; k++){
      fprintf(fp,"%f ",x[i*dim+k]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);

}

static Agnode_t*
mkNode (Agraph_t* g, char* name)
{
  Agnode_t* n = agnode(g, name, 1);
  agbindrec(n, "info", sizeof(Agnodeinfo_t), 1);
  return n;
}

Agraph_t* 
makeDotGraph (SparseMatrix A, char *name, int dim, double *x, int with_color, int with_label, int  use_matrix_value)
{
  Agraph_t* g;
  Agnode_t* n;
  Agnode_t* h;
  Agedge_t* e;
  int i, j;
  char buf[1024], buf2[1024];
  Agsym_t *sym, *sym2 = NULL, *sym3 = NULL;
  int* ia=A->ia;
  int* ja=A->ja;
  double* val = (double*)(A->a);
  Agnode_t** arr = (Agnode_t**)malloc((A->m)*sizeof(Agnode_t*));
  double *color = NULL;
  char cstring[8];
  char *label_string;

  if (!name){
    name = "stdin";
  } else {
    name = strip_dir(name);
  }
  label_string = malloc(sizeof(char)*1000);

  if ((((A)->property)&(MATRIX_UNDIRECTED))){
    g = agopen ("G", Agundirected, 0);
  } else {
    g = agopen ("G", Agdirected, 0);
  }
  sprintf (buf, "%f", 1.0);

  label_string = strcpy(label_string, name);
  label_string = strcat(label_string, ". ");
  sprintf (buf, "%d", A->m);
  label_string = strcat(label_string, buf);
  label_string = strcat(label_string, " nodes, ");
  sprintf (buf, "%d", A->nz);
  label_string = strcat(label_string, buf);
  /*  label_string = strcat(label_string, " edges. Created by Yifan Hu");*/
  label_string = strcat(label_string, " edges.");


  if (with_label) sym = agattr(g, 0, "label", label_string); 
  sym = agattr(g, 0, "fontcolor", "#808090");
  if (with_color) sym = agattr(g, 0, "bgcolor", "black"); 
  sym = agattr(g, 0, "outputorder", "edgesfirst"); 

  if (A->m > 100) {
    /* -Estyle=setlinewidth(0.0)' -Eheadclip=false -Etailclip=false -Nstyle=invis*/
    agattr(g, 1, "style", "invis"); 
  } else {
    /*    width=0, height = 0, label="", style=filled*/
    agattr(g, 1, "shape", "point"); 
    if (A->m < 50){
      agattr(g, 1, "width", "0.03"); 
    } else {
      agattr(g, 1, "width", "0"); 
    }
    agattr(g, 1, "label", ""); 
    agattr(g, 1, "style", "filled"); 
    if (with_color) {
      agattr(g, 1, "color", "#FF0000"); 
    } else {
      agattr(g, 1, "color", "#000000"); 
    }
  }

  agattr(g, 2, "headclip", "false"); 
  agattr(g, 2, "tailclip", "false"); 
  if (A->m < 50){
    agattr(g, 2, "style", "setlinewidth(2)"); 
  } else if (A->m < 500){
    agattr(g, 2, "style", "setlinewidth(0.5)"); 
  } else if (A->m < 5000){
    agattr(g, 2, "style", "setlinewidth(0.1)"); 
  } else {
    agattr(g, 2, "style", "setlinewidth(0.0)"); 
  }

  if (with_color) {
    sym2 = agattr(g, 2, "color", ""); 
    sym3 = agattr(g, 2, "wt", ""); 
  }
  for (i = 0; i < A->m; i++) {
    sprintf (buf, "%d", i);
    n = mkNode (g, buf);
    (((Agnodeinfo_t*)((n)->base.data))->id) = i;
    arr[i] = n;
  }

  if (with_color){
    double maxdist = 0.;
    double mindist = 0.;
    int first = 1;
    color = malloc(sizeof(double)*A->nz);
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      if (A->type != MATRIX_TYPE_REAL || !use_matrix_value){
	for (j = ia[i]; j < ia[i+1]; j++) {
	  color[j] = distance(x, dim, i, ja[j]);
	  if (i != ja[j]){
	    if (first){
	      mindist = color[j];
	      first = 0;
	    } else {
	      mindist = ((mindist)<(color[j])?(mindist):color[j]);
	    }
	  }
	  maxdist = ((color[j])>(maxdist)?(color[j]):maxdist);
	}
      } else {
	for (j = ia[i]; j < ia[i+1]; j++) {
	  color[j] = (((val[j])>0)?(val[j]):(-(val[j])));
	  if (i != ja[j]){
	    if (first){
	      mindist = color[j];
	      first = 0;
	    } else {
	      mindist = ((mindist)<(color[j])?(mindist):color[j]);
	    }
	  }
	  maxdist = ((color[j])>(maxdist)?(color[j]):maxdist);
	}
      }
    }
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      for (j = ia[i]; j < ia[i+1]; j++) {
        if (i != ja[j]){
	  color[j] = ((color[j] - mindist)/((maxdist-mindist)>(0.000001)?(maxdist-mindist):0.000001));
        } else {
          color[j] = 0;
        }
      }
    }
  }

  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    i = (((Agnodeinfo_t*)((n)->base.data))->id);
    for (j = ia[i]; j < ia[i+1]; j++) {
      h = arr [ja[j]];
      if (val){
	switch (A->type){
	case MATRIX_TYPE_REAL:
	  sprintf (buf, "%f", ((double*)A->a)[j]);
	  break;
	case MATRIX_TYPE_INTEGER:
	  sprintf (buf, "%d", ((int*)A->a)[j]);
	  break;
	case MATRIX_TYPE_COMPLEX:/* take real part as weight */
	  sprintf (buf, "%f", ((double*)A->a)[2*j]);
	  break;
	}
	if (with_color) {
          if (i != ja[j]){
            sprintf (buf2, "%s", hue2rgb(.65*color[j], cstring));
          } else {
            sprintf (buf2, "#000000");
          }
        }
      } else {
	sprintf (buf, "%f", 1.);
        if (with_color) {
          if (i != ja[j]){
            sprintf (buf2, "%s", hue2rgb(.65*color[j], cstring));
          } else {
            sprintf (buf2, "#000000");
          }
        }
     }
      e = agedge (g, n, h, NULL, 1);
      if (with_color) {
	agxset (e, sym2, buf2);
	sprintf (buf2, "%f", color[j]);
	agxset (e, sym3, buf2);
      }
    }
  }
  
  free(color);
  free (arr);
  free(label_string);
  return g;
}


char *cat_string(char *s1, char *s2){
  char *s;
  s = malloc(sizeof(char)*(strlen(s1)+strlen(s2)+1+1));
  strcpy(s,s1);
  strcat(s,"|");
  strcat(s,s2);
  return s;
}

char *cat_string3(char *s1, char *s2, char *s3, int id){
  char *s;
  char sid[1000];
  sprintf(sid,"%d",id);
  s = malloc(sizeof(char)*(strlen(s1)+strlen(s2)+strlen(s3)+strlen(sid)+1+3));
  strcpy(s,s1);
  strcat(s,"|");
  strcat(s,s2);
  strcat(s,"|");
  strcat(s,s3);
  strcat(s,"|");
  strcat(s,sid);
  return s;
}


Agraph_t *convert_edge_labels_to_nodes(Agraph_t* g){
  Agnode_t *n, *newnode;
  Agraph_t *dg;

  int nnodes;
  int nedges;


  Agedge_t *ep, *e;
  int i = 0;
  Agnode_t **ndmap = NULL;
  char *s;
  char *elabel;
  int id = 0;

  Agsym_t* sym = agattr(g, 2, "label", NULL);

  dg = agopen("test", g->desc, 0);

  if (!g) return NULL;
  nnodes = agnnodes (g);
  nedges = agnedges (g);

  ndmap = malloc(sizeof(Agnode_t *)*nnodes);

  agattr(dg, 1, "label", "\\N"); 
  agattr(dg, 1, "shape", "ellipse"); 
  agattr(dg, 1, "width","0.00001");
  agattr(dg, 1, "height", "0.00001");
  agattr(dg, 1, "margin","0.");
  agattr(dg, 2, "arrowsize", "0.5"); 

  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    newnode = mkNode(dg, agnameof(n));
    agset(newnode,"shape","box");
    ndmap[i] = newnode;
    (((Agnodeinfo_t*)((n)->base.data))->id) = i++;
  }


  /*
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    for (ep = agfstedge(g, n); ep; ep = agnxtedge(g, ep, n)) {
      if (agtail(ep) == n) continue;
      agedge(dg, ndmap[ND_id(agtail(ep))], ndmap[ND_id(aghead(ep))]);
    }
  }
  */



  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    for (ep = agfstedge(g, n); ep; ep = agnxtedge(g, ep, n)) {
      if (((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node) == n && (((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node) != n)) continue;
      if (sym && (elabel = agxget(ep,sym)) && strcmp(elabel,"") != 0) {
	s = cat_string3("|edgelabel",agnameof(((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node)), agnameof(((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node)), id++);
	newnode = mkNode(dg,s);
	agset(newnode,"label",elabel);
	agset(newnode,"shape","plaintext");
	e = agedge(dg, ndmap[(((Agnodeinfo_t*)((((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node))->base.data))->id)], newnode, NULL, 1);
	agset(e, "arrowsize","0");
	agedge(dg, newnode, ndmap[(((Agnodeinfo_t*)((((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node))->base.data))->id)], NULL, 1);
	free(s);
      } else {
	agedge(dg, ndmap[(((Agnodeinfo_t*)((((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node))->base.data))->id)], ndmap[(((Agnodeinfo_t*)((((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node))->base.data))->id)], NULL, 1);
      }
    }
  }

  free(ndmap);
  return dg;
 }

Agraph_t* assign_random_edge_color(Agraph_t* g){
  char cstring[8];
  char buf2[1024];
  Agsym_t *sym2;
  Agnode_t* n;
  Agedge_t *ep;

  sym2 = agattr(g, 2, "color", ""); 
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    for (ep = agfstedge(g, n); ep; ep = agnxtedge(g, ep, n)) {
      sprintf (buf2, "%s", hue2rgb(0.65*drand(), cstring));
      agxset (ep, sym2, buf2);
    }
  }

  return g;
 }


static int hex2int(char h){
  if (h >= '0' && h <= '9') return h - '0';
  if (h >= 'a' && h <= 'f') return 10 + h - 'a';
  if (h >= 'A' && h <= 'F') return 10 + h - 'A';
  return 0;
}  
static float hexcol2rgb(char *h){
  return (hex2int(h[0])*16 + hex2int(h[1]))/255.;
}

void Dot_SetClusterColor(Agraph_t* g, float *rgb_r,  float *rgb_g,  float *rgb_b, int *clusters){

  Agnode_t* n;
  char scluster[20];
  int i;
  Agsym_t* clust_clr_sym = agattr(g, 1, "clustercolor", NULL); 

  if (!clust_clr_sym) clust_clr_sym = agattr(g, 1, "clustercolor", "-1"); 
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    i = (((Agnodeinfo_t*)((n)->base.data))->id);
    if (rgb_r && rgb_g && rgb_b) {
      rgb2hex((rgb_r)[(clusters)[i]],(rgb_g)[(clusters)[i]],(rgb_b)[(clusters)[i]], scluster, NULL);
      //sprintf(scluster,"#%2x%2x%2x", (int) (255*((rgb_r)[(clusters)[i]])), (int) (255*((rgb_g)[(clusters)[i]])), (int) (255*((rgb_b)[(clusters)[i]])));
    }
    agxset(n,clust_clr_sym,scluster);
  }
}

SparseMatrix Import_coord_clusters_from_dot(Agraph_t* g, int maxcluster, int dim, int *nn, double **label_sizes, double **x, int **clusters, float **rgb_r,  float **rgb_g,  float **rgb_b,  float **fsz, char ***labels, int default_color_scheme, int clustering_scheme, int useClusters){
  SparseMatrix A = 0;
  Agnode_t* n;
  Agedge_t* e;
  Agsym_t* sym;
  Agsym_t* clust_sym;
  Agsym_t* clust_clr_sym;
  int nnodes;
  int nedges;
  int i, row, ic,nc, j;
  int* I;
  int* J;
  double* val;
  double v;
  int type = MATRIX_TYPE_REAL;
  size_t sz = sizeof(double);
  char scluster[100];
  float ff;

  int MAX_GRPS, MIN_GRPS, noclusterinfo = 0, first = 1;
  float *pal;
  int max_color = MAX_COLOR;

  switch (default_color_scheme){
  case COLOR_SCHEME_BLUE_YELLOW:
    pal = &(palette_blue_to_yellow[0][0]);
    break;
  case COLOR_SCHEME_WHITE_RED:
    pal = &(palette_white_to_red[0][0]);
    break;
  case COLOR_SCHEME_GREY_RED:
    pal = &(palette_grey_to_red[0][0]);
    break;
  case COLOR_SCHEME_GREY:
    pal = &(palette_grey[0][0]);
    break;
  case COLOR_SCHEME_PASTEL:
    pal = &(palette_pastel[0][0]);
    break;
  case COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED:
    fprintf(stderr," HERE!\n");
    pal = &(palette_sequential_singlehue_red[0][0]);
    break;
  case COLOR_SCHEME_SEQUENTIAL_SINGLEHUE_RED_LIGHTER:
    fprintf(stderr," HERE!\n");
    pal = &(palette_sequential_singlehue_red_lighter[0][0]);
    break;
  case COLOR_SCHEME_PRIMARY:
    pal = &(palette_primary[0][0]);
    break;
  case COLOR_SCHEME_ADAM_BLEND:
    pal = &(palette_adam_blend[0][0]);
    break;
  case COLOR_SCHEME_ADAM:
    pal = &(palette_adam[0][0]);
    max_color = 11;
    break;
  case COLOR_SCHEME_NONE:
    pal = NULL;
    break;
  default:
    pal = &(palette_pastel[0][0]);
    break;
  }
    
  if (!g) return NULL;
  nnodes = agnnodes (g);
  nedges = agnedges (g);
  *nn = nnodes;

  /* Assign node ids */
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n))
    (((Agnodeinfo_t*)((n)->base.data))->id) = i++;

  /* form matrix */  
  I = (int*)malloc((nedges)*sizeof(int));
  J = (int*)malloc((nedges)*sizeof(int));
  val = (double*)malloc((nedges)*sizeof(double));

  sym = agattr(g, 2, "weight", NULL); 
  clust_sym = agattr(g, 1, "cluster", NULL); 
  clust_clr_sym = agattr(g, 1, "clustercolor", NULL); 
  //sym = agattr(g, AGEDGE, "wt", NULL); 
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    row = (((Agnodeinfo_t*)((n)->base.data))->id);
    for (e = agfstout (g, n); e; e = agnxtout (g, e)) {
      I[i] = row;
      J[i] = (((Agnodeinfo_t*)((((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))->base.data))->id);
      if (sym) {
        if (sscanf (agxget(e,sym), "%lf", &v) != 1)
          v = 1;
      }
      else
        v = 1;
      val[i] = v;
      i++;
    }
  }
  A = SparseMatrix_from_coordinate_arrays(nedges, nnodes, nnodes, I, J, val, type, sz);

  /* get clustering info */
  *clusters = malloc(sizeof(int)*nnodes);
  nc = 1;
  MIN_GRPS = 0;
  /* if useClusters, the nodes in each top-level cluster subgraph are assigned to
   * clusters 2, 3, .... Any nodes not in a cluster subgraph are tossed into cluster 1.
   */
  if (useClusters) {
    Agraph_t* sg;
    int gid = 1;  
    memset (*clusters, 0, sizeof(int)*nnodes);
    for (sg = agfstsubg(g); sg; sg = agnxtsubg(sg)) {
      if (strncmp(agnameof(sg), "cluster", 7)) continue;
      gid++;
      for (n = agfstnode(sg); n; n = agnxtnode (sg, n)) {
        i = (((Agnodeinfo_t*)((n)->base.data))->id);
        if ((*clusters)[i])
          fprintf (stderr, "Warning: node %s appears in multiple clusters.\n", agnameof(n));
        else
          (*clusters)[i] = gid;
      }
    }
    for (n = agfstnode(g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      if ((*clusters)[i] == 0)
        (*clusters)[i] = 1;
    }
    MIN_GRPS = 1;
    nc = gid;
  }
  else if (clust_sym) {
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      if ((sscanf(agxget(n,clust_sym), "%d", &ic)>0)) {
        (*clusters)[i] = ic;
        nc = ((nc)>(ic)?(nc):ic);
        if (first){
	  MIN_GRPS = ic;
	  first = 0;
        } else {
	  MIN_GRPS = ((MIN_GRPS)<(ic)?(MIN_GRPS):ic);
        }
      } else {
        noclusterinfo = 1;
        break;
      }
    }
  }
  else 
    noclusterinfo = 1;
  MAX_GRPS = nc;

  if (noclusterinfo) {
    int use_value = 1, flag = 0;
    double modularity;
    if (!clust_sym) clust_sym = agattr(g,1,"cluster","-1");

    if (clustering_scheme == CLUSTERING_MQ){
      mq_clustering(A, 0, maxcluster, use_value,
		    &nc, clusters, &modularity, &flag);
    } else if (clustering_scheme == CLUSTERING_MODULARITY){ 
      modularity_clustering(A, 0, maxcluster, use_value,
		    &nc, clusters, &modularity, &flag);
    } else {
      assert(0);
    }
    for (i = 0; i < nnodes; i++) (*clusters)[i]++;/* make into 1 based */
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      sprintf(scluster,"%d",(*clusters)[i]);
      agxset(n,clust_sym,scluster);
    }
    MIN_GRPS = 1;
    MAX_GRPS = nc;
    if (Verbose){
      fprintf(stderr," no complement clustering info in dot file, using modularity clustering. Modularity = %f, ncluster=%d\n",modularity, nc);
    }
  }

  *label_sizes = malloc(sizeof(double)*dim*nnodes);
  if (pal || (!noclusterinfo && clust_clr_sym)){
    *rgb_r = malloc(sizeof(float)*(1+MAX_GRPS));
    *rgb_g = malloc(sizeof(float)*(1+MAX_GRPS));
    *rgb_b = malloc(sizeof(float)*(1+MAX_GRPS));
  } else {
    *rgb_r = NULL;
    *rgb_g = NULL;
    *rgb_b = NULL;
  }
  *fsz = malloc(sizeof(float)*nnodes);
  *labels = malloc(sizeof(char*)*nnodes);

  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    gvcolor_t color;
    double sz;
    i = (((Agnodeinfo_t*)((n)->base.data))->id);
    if (agget(n, "width") && agget(n, "height")){
      sscanf(agget(n, "width"), "%lf", &sz);
      (*label_sizes)[i*2] = 72*(sz*0.5);
      sscanf(agget(n, "height"), "%lf", &sz);
      (*label_sizes)[i*2+1] = 72*(sz*0.5);
    } else {
      (*label_sizes)[i*2] = 72*(0.75/2);
      (*label_sizes)[i*2+1] = 72*(0.5*2);
    }

   if (agget(n, "fontsize")){
      sscanf(agget(n, "fontsize"), "%f", &ff);
      (*fsz)[i] = ff;
    } else {
     (*fsz)[i] = 14;
    }

   if (agget(n, "label") && strcmp(agget(n, "label"), "") != 0 && strcmp(agget(n, "label"), "\\N") != 0){
     char *lbs;
     lbs = agget(n, "label");
      (*labels)[i] = malloc(sizeof(char)*(strlen(lbs)+1));
      strcpy((*labels)[i], lbs);
    } else {
     (*labels)[i] = malloc(sizeof(char)*(strlen(agnameof(n))+1));
      strcpy((*labels)[i], agnameof(n));
    }



   j = (*clusters)[i];
   if (MAX_GRPS-MIN_GRPS < max_color) {
     j = (j-MIN_GRPS)*((int)((max_color-1)/(((MAX_GRPS-MIN_GRPS))>(1)?((MAX_GRPS-MIN_GRPS)):1)));
   } else {
     j = (j-MIN_GRPS)%max_color;
   }

   if (pal){
     //     assert((*clusters)[i] >= 0 && (*clusters)[i] <= MAX_GRPS);
     (*rgb_r)[(*clusters)[i]] = pal[3*j+0];
     (*rgb_g)[(*clusters)[i]] =  pal[3*j+1];
     (*rgb_b)[(*clusters)[i]] = pal[3*j+2];
   }

   if (!noclusterinfo && clust_clr_sym && (colorxlate(agxget(n,clust_clr_sym),&color,RGBA_DOUBLE) == 0)) {
     (*rgb_r)[(*clusters)[i]] = color.u.RGBA[0];
     (*rgb_g)[(*clusters)[i]] = color.u.RGBA[1];
     (*rgb_b)[(*clusters)[i]] = color.u.RGBA[2];
   }

   if (!noclusterinfo && agget(n, "cluster") && agget(n, "clustercolor") && strlen(agget(n, "clustercolor") ) >= 7 && pal){
     char cc[10];
     strcpy(cc, agget(n, "clustercolor"));
     (*rgb_r)[(*clusters)[i]] = hexcol2rgb(cc+1);
     (*rgb_g)[(*clusters)[i]] = hexcol2rgb(cc+3);
     (*rgb_b)[(*clusters)[i]] = hexcol2rgb(cc+5);
   }

  }


  if (x){
    int has_position = 0;
    *x = malloc(sizeof(double)*dim*nnodes);
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      double xx,yy;
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      if (agget(n, "pos")){
        has_position = 1;
	sscanf(agget(n, "pos"), "%lf,%lf", &xx, &yy);
	(*x)[i*dim] = xx;
	(*x)[i*dim+1] = yy;
      } else {
	fprintf(stderr,"WARNING: pos field missing for node %d, set to origin\n",i);
	(*x)[i*dim] = 0;
	(*x)[i*dim+1] = 0;
      }
    }
    if (!has_position){
      free(*x);
      *x = NULL;
    }
  }


  free(I);
  free(J);
  free(val);

  return A;
}

void attached_clustering(Agraph_t* g, int maxcluster, int clustering_scheme){
  SparseMatrix A = 0;
  Agnode_t* n;
  Agedge_t* e;
  Agsym_t *sym, *clust_sym;
  int nnodes;
  int nedges;
  int i, row,nc;
  int* I;
  int* J;
  double* val;
  double v;
  int type = MATRIX_TYPE_REAL;
  size_t sz = sizeof(double);
  char scluster[100];


  int *clusters;


  
  if (!g) return;
  nnodes = agnnodes (g);
  nedges = agnedges (g);
  
  /* Assign node ids */
  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n))
    (((Agnodeinfo_t*)((n)->base.data))->id) = i++;
  
  /* form matrix */  
  I = (int*)malloc((nedges)*sizeof(int));
  J = (int*)malloc((nedges)*sizeof(int));
  val = (double*)malloc((nedges)*sizeof(double));
  
  sym = agattr(g, 2, "weight", NULL);
  clust_sym = agattr(g, 1, "cluster", NULL);

  i = 0;
  for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
    row = (((Agnodeinfo_t*)((n)->base.data))->id);
    for (e = agfstout (g, n); e; e = agnxtout (g, e)) {
      I[i] = row;
      J[i] = (((Agnodeinfo_t*)((((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))->base.data))->id);
      if (sym) {
        if (sscanf (agxget(e,sym), "%lf", &v) != 1)
          v = 1;
      }
      else
        v = 1;
      val[i] = v;
      i++;
    }
  }
  A = SparseMatrix_from_coordinate_arrays(nedges, nnodes, nnodes, I, J, val, type, sz);

  clusters = malloc(sizeof(int)*nnodes);

  {
    int use_value = 1, flag = 0;
    double modularity;
    if (!clust_sym) clust_sym = agattr(g,1,"cluster","-1");
    
    if (clustering_scheme == CLUSTERING_MQ){
      mq_clustering(A, 0, maxcluster, use_value,
		    &nc, &clusters, &modularity, &flag);
    } else if (clustering_scheme == CLUSTERING_MODULARITY){ 
      modularity_clustering(A, 0, maxcluster, use_value,
			    &nc, &clusters, &modularity, &flag);
    } else {
      assert(0);
    }
    for (i = 0; i < nnodes; i++) (clusters)[i]++;/* make into 1 based */
    for (n = agfstnode (g); n; n = agnxtnode (g, n)) {
      i = (((Agnodeinfo_t*)((n)->base.data))->id);
      sprintf(scluster,"%d",(clusters)[i]);
      agxset(n,clust_sym,scluster);
    }
    if (Verbose){
      fprintf(stderr," no complement clustering info in dot file, using modularity clustering. Modularity = %f, ncluster=%d\n",modularity, nc);
    }
  }

  free(I);
  free(J);
  free(val);
  free(clusters);

  SparseMatrix_delete(A);

}



void initDotIO (Agraph_t *g)
{
  aginit(g, 1, "info", sizeof(Agnodeinfo_t), 1);
}

void setDotNodeID (Agnode_t* n, int v)
{
    (((Agnodeinfo_t*)((n)->base.data))->id) = v;
}

int getDotNodeID (Agnode_t* n)
{
    return (((Agnodeinfo_t*)((n)->base.data))->id);
}

