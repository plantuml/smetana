#line 1 "graphviz-2.38.0\\lib\\ortho\\rawgraph.c" 1
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

 /* Implements graph.h  */


#line 1 "graphviz-2.38.0\\lib\\ortho\\rawgraph.c" 1


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


#line 20 "graphviz-2.38.0\\lib\\ortho\\rawgraph.c" 2
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







#line 21 "graphviz-2.38.0\\lib\\ortho\\rawgraph.c" 2
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

#line 22 "graphviz-2.38.0\\lib\\ortho\\rawgraph.c" 2





rawgraph*
make_graph(int n)
{
    int i;
    rawgraph* g = (rawgraph*)zmalloc(sizeof(rawgraph));
    g->nvs = n;
    g->vertices = (vertex*)zmalloc((n)*sizeof(vertex));
    for(i=0;i<n;i++) {
        g->vertices[i].adj_list = openIntSet ();
        g->vertices[i].color = 0;
    }
    return g;
}

void
free_graph(rawgraph* g)
{
    int i;
    for(i=0;i<g->nvs;i++)
        dtclose(g->vertices[i].adj_list);
    free (g->vertices);
    free (g);
}
 
void 
insert_edge(rawgraph* g, int v1, int v2)
{
    intitem obj;

    obj.id = v2;
    (*(((Dt_t*)(g->vertices[v1].adj_list))->searchf))((g->vertices[v1].adj_list),(void*)(&obj),0000001);
}

void
remove_redge(rawgraph* g, int v1, int v2)
{
    intitem obj;
    obj.id = v2;
    (*(((Dt_t*)(g->vertices[v1].adj_list))->searchf))((g->vertices[v1].adj_list),(void*)(&obj),0000002);
    obj.id = v1;
    (*(((Dt_t*)(g->vertices[v2].adj_list))->searchf))((g->vertices[v2].adj_list),(void*)(&obj),0000002);
}

int
edge_exists(rawgraph* g, int v1, int v2)
{
    return ((*(((Dt_t*)(g->vertices[v1].adj_list))->searchf))((g->vertices[v1].adj_list),(void*)(&v2),0001000) != 0);
}

typedef struct {
  int top;
  int* vals;
} stack;

static stack*
mkStack (int i)
{
    stack* sp = (stack*)zmalloc(sizeof(stack));
    sp->vals = (int*)zmalloc((i)*sizeof(int));
    sp->top = -1;
    return sp;
}

static void
freeStack (stack* s)
{
    free (s->vals);
    free (s);
}

static void
pushStack (stack* s, int i)
{
    s->top++;
    s->vals[s->top] = i;
}

static int
popStack (stack* s)
{
    int v;

    if (s->top == -1) return -1;
    v = s->vals[s->top];
    s->top--;
    return v;
}

static int
DFS_visit(rawgraph* g, int v, int time, stack* sp)
{
    Dt_t* adj;
    Dtlink_t* link;
    int id;
    vertex* vp;

    vp = g->vertices + v;
    vp->color = 1;
    /* g->vertices[v].d = time; */
    adj = vp->adj_list;
    time = time + 1;

    for(link = dtflatten (adj); link; link = (((Dtlink_t*)(link))->right)) {
        id = ((intitem*)(((Dt_t*)(adj))->disc->link < 0 ? ((Dthold_t*)((link)))->obj : (void*)((char*)((link)) - ((Dt_t*)(adj))->disc->link) ))->id;
        if(g->vertices[id].color == 0)
            time = DFS_visit(g, id, time, sp);
    }
    vp->color = 2;
    /* g->vertices[v].f = time; */
    pushStack (sp, v);
    return (time + 1);
}

void
top_sort(rawgraph* g)
{
    int i, v;
    int time = 0;
    int count = 0;
    stack* sp;

    if (g->nvs == 0) return;
    if (g->nvs == 1) {
        g->vertices[0].topsort_order = count;
		return;
	}

    sp = mkStack (g->nvs);
    for(i=0;i<g->nvs;i++) {
        if(g->vertices[i].color == 0)
            time = DFS_visit(g, i, time, sp);
    }
    while((v = popStack(sp)) >= 0) {
        g->vertices[v].topsort_order = count;
        count++;
    }
    freeStack (sp);
}
