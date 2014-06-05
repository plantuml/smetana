#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.c" 1

#line 1 "graphviz-2.38.0\\lib\\label\\xlabels.h" 1
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










#line 18 "graphviz-2.38.0\\lib\\label\\xlabels.h" 2

typedef struct {
    pointf sz;			/* Size of label (input) */
    pointf pos;			/* Position of lower-left corner of label (output) */
    void *lbl;			/* Pointer to label in the graph */
    unsigned char set;		/* True if the position has been set (input/output) */
} xlabel_t;

typedef struct {
    pointf pos;			/* Position of lower-left corner of object */
    pointf sz;			/* Size of object; may be zero for a point */
    xlabel_t *lbl;		/* Label attached to object, or NULL */
} object_t;

typedef struct {
    boxf bb;			/* Bounding box of all objects */
    unsigned char force;	/* If true, all labels must be placed */
} label_params_t;

int placeLabels(object_t * objs, int n_objs,
		xlabel_t * lbls, int n_lbls, label_params_t * params);


#line 1 "graphviz-2.38.0\\lib\\label\\index.h" 1
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
 * this library is derived from an archived home directory of Antonin Guttman 
 * that implemented the ideas described in
 * "R-trees: a dynamic index structure for spatial searching"
 * Antonin Guttman, University of California, Berkeley
 * SIGMOD '84 Proceedings of the 1984 ACM SIGMOD international conference on Management of data
 * ISBN:0-89791-128-8
 * http://dx.doi.org/10.1145/602259.602266
 * this copy of the code was retrieved from
 * http://web.archive.org/web/20030210112132/http://www.es.ucsc.edu/~tonig/rtrees/
 * we are using the quadratic node splitter only
 * we made a few cosmetic changes to fit our needs
 * per Antonin there is no copyright
 */

/* %W% %G% */
/*-----------------------------------------------------------------------------
| Global definitions.
-----------------------------------------------------------------------------*/




/* #define NDEBUG */

/* branching factor of a node */
/* #define NODECARD (int)((PGSIZE-(2*sizeof(int)))/sizeof(struct Branch))*/

typedef struct RTree RTree_t;

#line 1 "graphviz-2.38.0\\lib\\label\\rectangle.h" 1
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








typedef struct Rect {
    int boundary[2*2];
} Rect_t;

void InitRect(Rect_t * r);



unsigned int RectArea(Rect_t *);
int Overlap(Rect_t *, Rect_t *);
int Contained(Rect_t *, Rect_t *);
Rect_t CombineRect(Rect_t *, Rect_t *);
Rect_t NullRect(void);






#line 44 "graphviz-2.38.0\\lib\\label\\index.h" 2
#line 1 "graphviz-2.38.0\\lib\\label\\node.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\label\\index.h" 1
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
















































    
    



    
    





    
    

    

    
    

    
    
    

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    




    
    






















#line 18 "graphviz-2.38.0\\lib\\label\\node.h" 2

typedef struct Branch {
    Rect_t rect;
    struct Node *child;
} Branch_t;

typedef struct Node {
    int count;
    int level;			/* 0 is leaf, others positive */
    struct Branch branch[64];
} Node_t;

void RTreeFreeNode(RTree_t *, Node_t *);
void InitNode(Node_t *);
void InitBranch(Branch_t *);
Rect_t NodeCover(Node_t *);
int PickBranch(Rect_t *, Node_t *);
int AddBranch(RTree_t *, Branch_t *, Node_t *, Node_t **);
void DisconBranch(Node_t *, int);
void PrintBranch(int, Branch_t *);
Node_t *RTreeNewNode(RTree_t *);










#line 45 "graphviz-2.38.0\\lib\\label\\index.h" 2
#line 1 "graphviz-2.38.0\\lib\\label\\split.q.h" 1
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








/*-----------------------------------------------------------------------------
| Definitions and global variables.
-----------------------------------------------------------------------------*/
#line 1 "graphviz-2.38.0\\lib\\label\\rectangle.h" 1
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









    

















#line 21 "graphviz-2.38.0\\lib\\label\\split.q.h" 2
#line 1 "graphviz-2.38.0\\lib\\label\\index.h" 1
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
















































    
    



    
    





    
    

    

    
    

    
    
    

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
    




    
    






















#line 22 "graphviz-2.38.0\\lib\\label\\split.q.h" 2




/* variables for finding a partition */
    struct PartitionVars {
    int partition[64 + 1];
    int taken[64 + 1];
    int count[2];
    struct Rect cover[2];
    int area[2];
};

typedef struct split_q_s {
    struct Branch BranchBuf[64 + 1];
    struct Rect CoverSplit;
    unsigned int CoverSplitArea;
    struct PartitionVars Partitions[1];
} SplitQ_t;

void SplitNode(RTree_t *, Node_t *, Branch_t *, Node_t **);






#line 46 "graphviz-2.38.0\\lib\\label\\index.h" 2






typedef struct Leaf {
    Rect_t rect;
    void *data;
} Leaf_t;

typedef struct LeafList {
    struct LeafList *next;
    Leaf_t *leaf;
} LeafList_t;




    struct RTree {
    Node_t *root;

    SplitQ_t split;

    /* balance criterion for node splitting */
    int MinFill;

    /* times */
    long ElapsedTime;
    float UserTime, SystemTime;

    int Deleting;

    /* variables for statistics */
    int StatFlag;		/* tells if we are counting or not */
    /* counters affected only when StatFlag set */
    int InsertCount;
    int DeleteCount;
    int ReInsertCount;
    int InSplitCount;
    int DeSplitCount;
    int ElimCount;
    int EvalCount;
    int InTouchCount;
    int DeTouchCount;
    int SeTouchCount;
    int CallCount;
    float SplitMeritSum;

    /* counters used even when StatFlag not set */
    int RectCount;
    int NodeCount;
    int LeafCount, NonLeafCount;
    int EntryCount;
    int SearchCount;
    int HitCount;

};

typedef struct ListNode {
    struct ListNode *next;
    struct Node *node;
} ListNode_t;

RTree_t *RTreeOpen(void);
int RTreeClose(RTree_t * rtp);
Node_t *RTreeNewIndex(RTree_t * rtp);
LeafList_t *RTreeSearch(RTree_t *, Node_t *, Rect_t *);
int RTreeInsert(RTree_t *, Rect_t *, void *, Node_t **, int);
int RTreeDelete(RTree_t *, Rect_t *, void *, Node_t **);

LeafList_t *RTreeNewLeafList(Leaf_t * lp);
LeafList_t *RTreeLeafListAdd(LeafList_t * llp, Leaf_t * lp);
void RTreeLeafListFree(LeafList_t * llp);










#line 41 "graphviz-2.38.0\\lib\\label\\xlabels.h" 2
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


















































#line 42 "graphviz-2.38.0\\lib\\label\\xlabels.h" 2
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

























































#line 43 "graphviz-2.38.0\\lib\\label\\xlabels.h" 2

















// indexes of neighbors in certain arrays
// the node of interest is usually in node 4
// 6 7 8
// 3 4 5
// 0 1 2









    typedef struct best_p_s {
    int n;
    double area;
    pointf pos;
} BestPos_t;

typedef struct obyh {
    Dtlink_t link;
    int key;
    Leaf_t d;
} HDict_t;

typedef struct XLabels_s {
    object_t *objs;
    int n_objs;
    xlabel_t *lbls;
    int n_lbls;
    label_params_t *params;

    Dt_t *hdx;			// splay tree keyed with hilbert spatial codes
    RTree_t *spdx;		// rtree

} XLabels_t;








#line 22 "graphviz-2.38.0\\lib\\label\\xlabels.c" 2
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







#line 23 "graphviz-2.38.0\\lib\\label\\xlabels.c" 2

extern int Verbose;

static int icompare(Dt_t *, void *, void *, Dtdisc_t *);

Dtdisc_t Hdisc = { offsetof(HDict_t, key), sizeof(int), -1, 0, 0,
    icompare, 0, 0, 0
};

static int icompare(Dt_t * dt, void * v1, void * v2, Dtdisc_t * disc)
{
    int k1 = *((int *) v1), k2 = *((int *) v2);
    return k1 - k2;
}

static XLabels_t *xlnew(object_t * objs, int n_objs,
			xlabel_t * lbls, int n_lbls,
			label_params_t * params)
{
    XLabels_t *xlp;

    xlp = (XLabels_t*)zmalloc(sizeof(XLabels_t));

    /* used to load the rtree in hilbert space filling curve order */
    if (!(xlp->hdx = dtopen(&Hdisc, Dtobag))) {
	fprintf(stderr, "out of memory\n");
	goto bad;
    }

    /* for querying intersection candidates */
    if (!(xlp->spdx = RTreeOpen())) {
	fprintf(stderr, "out of memory\n");
	goto bad;
    }
    /* save arg pointers in the handle */
    xlp->objs = objs;
    xlp->n_objs = n_objs;
    xlp->lbls = lbls;
    xlp->n_lbls = n_lbls;
    xlp->params = params;

    return xlp;

  bad:
    if (xlp->hdx)
	dtclose(xlp->hdx);
    if (xlp->spdx)
	RTreeClose(xlp->spdx);
    free(xlp);
    return 0;
}

static void xlfree(XLabels_t * xlp)
{
    RTreeClose(xlp->spdx);
    free(xlp);
    return;
}

/***************************************************************************/

/*
 * floorlog2 - largest base 2 integer logarithm less than n
 * http://en.wikipedia.org/wiki/Binary_logarithm
 * ultimately from http://www.hackersdelight.org/
 */
static int floorLog2(unsigned int n)
{
    int pos = 0;

    if (n == 0)
	return -1;

    if (n >= 1 << 16) {
	n >>= 16;
	pos += 16;
    }
    if (n >= 1 << 8) {
	n >>= 8;
	pos += 8;
    }
    if (n >= 1 << 4) {
	n >>= 4;
	pos += 4;
    }
    if (n >= 1 << 2) {
	n >>= 2;
	pos += 2;
    }
    if (n >= 1 << 1) {
	pos += 1;
    }
    return pos;
}

/*
 * determine the order(depth) of the hilbert sfc so that we satisfy the
 * precondition of hd_hil_s_from_xy()
 */
unsigned int xlhorder(XLabels_t * xlp)
{
    double maxx = xlp->params->bb.UR.x, maxy = xlp->params->bb.UR.y;
    return floorLog2(maxx > maxy ? maxx : maxy) + 1;
}

/* from http://www.hackersdelight.org/ site for the book by Henry S Warren */
/*
 * precondition
 * pow(2, n) >= max(p.x, p.y)
 */
/* adapted from lams1.c
Given the "order" n of a Hilbert curve and coordinates x and y, this
program computes the length s of the curve from the origin to (x, y).
The square that the Hilbert curve traverses is of size 2**n by 2**n.
   The method is that given in [Lam&Shap], described by the following
table.  Here i = n-1 for the most significant bit of x and y, and i = 0
for the least significant bits.

		    x[i]  y[i] | s[2i+1:2i]   x   y
		    -----------|-------------------
		     0     0   |     00       y   x
		     0     1   |     01       x   y
		     1     0   |     11      ~y  ~x
		     1     1   |     10       x   y

To use this table, start at the most significant bits of x and y
(i = n - 1).  If they are both 0 (first row), set the most significant
two bits of s to 00 and interchange x and y.  (Actually, it is only
necessary to interchange the remaining bits of x and y.)  If the most
significant bits of x and y are 10 (third row), output 11, interchange x
and y, and complement x and y.
   Then, consider the next most significant bits of x and y (which may
have been changed by this process), and select the appropriate row of
the table to determine the next two bits of s, and how to change x and
y.  Continue until the least significant bits of x and y have been
processed. */

static unsigned int hd_hil_s_from_xy(point p, int n)
{
    int i, x = p.x, y = p.y, xi, yi;
    unsigned s;

    s = 0;			/* Initialize. */
    for (i = n - 1; i >= 0; i--) {
	xi = (x >> i) & 1;	/* Get bit i of x. */
	yi = (y >> i) & 1;	/* Get bit i of y. */
	s = 4 * s + 2 * xi + (xi ^ yi);	/* Append two bits to s. */

	x = x ^ y;		/* These 3 lines swap */
	y = y ^ (x & (yi - 1));	/* x and y if yi = 0. */
	x = x ^ y;
	x = x ^ (-xi & (yi - 1));	/* Complement x and y if */
	y = y ^ (-xi & (yi - 1));	/* xi = 1 and yi = 0. */
    }
    return s;
}

/* intersection test from
 * from Real-Time Collision Detection 4.2.1 by Christer Ericson
 * intersection area from
 * http://stackoverflow.com/questions/4549544/total-area-of-intersecting-rectangles
*/
static double aabbaabb(Rect_t * r, Rect_t * s)
{
    /* per dimension if( max < omin || min > omax) */
    double iminx, iminy, imaxx, imaxy;
    if (r->boundary[2] < s->boundary[0] || r->boundary[0] > s->boundary[2])
	return 0;
    if (r->boundary[3] < s->boundary[1] || r->boundary[1] > s->boundary[3])
	return 0;

    /* if we get here we have an intersection */

    /* rightmost left edge of the 2 rectangles */
    iminx =
	r->boundary[0] > s->boundary[0] ? r->boundary[0] : s->boundary[0];
    /* upmost bottom edge */
    iminy =
	r->boundary[1] > s->boundary[1] ? r->boundary[1] : s->boundary[1];
    /* leftmost right edge */
    imaxx =
	r->boundary[2] < s->boundary[2] ? r->boundary[2] : s->boundary[2];
    /* downmost top edge */
    imaxy =
	r->boundary[3] < s->boundary[3] ? r->boundary[3] : s->boundary[3];
    return (imaxx - iminx) * (imaxy - iminy);
}

/*
 * test if objp1, a size 0 object is enclosed in the xlabel
 * associated with objp
 */
static int lblenclosing(object_t * objp, object_t * objp1)
{
  xlabel_t * xlp = objp->lbl;;

  assert(objp1->sz.x == 0 && objp1->sz.y == 0);

  if(! xlp) return 0;

  return objp1->pos.x > xlp->pos.x &&
	 objp1->pos.x < (xlp->pos.x + xlp->sz.x) &&
	 objp1->pos.y > xlp->pos.y &&
	 objp1->pos.y < (xlp->pos.y + xlp->sz.y);
}

/*fill in rectangle from the object */
static void objp2rect(object_t * op, Rect_t * r)
{
    r->boundary[0] = op->pos.x;
    r->boundary[1] = op->pos.y;
    r->boundary[2] = op->pos.x + op->sz.x;
    r->boundary[3] = op->pos.y + op->sz.y;
    return;
}

/*fill in rectangle from the objects xlabel */
static void objplp2rect(object_t * objp, Rect_t * r)
{
    xlabel_t *lp = objp->lbl;
    r->boundary[0] = lp->pos.x;
    r->boundary[1] = lp->pos.y;
    r->boundary[2] = lp->pos.x + lp->sz.x;
    r->boundary[3] = lp->pos.y + lp->sz.y;
    return;
}

/* compute boundary that encloses all possible label boundaries */
static Rect_t objplpmks(XLabels_t * xlp, object_t * objp)
{
    Rect_t rect;
    pointf p;

    p.x = p.y = 0.0;
    if (objp->lbl)
	p = objp->lbl->sz;

    rect.boundary[0] = (int) floor(objp->pos.x - p.x);
    rect.boundary[1] = (int) floor(objp->pos.y - p.y);

    rect.boundary[2] = (int) ceil(objp->pos.x + objp->sz.x + p.x);
    assert(rect.boundary[2] < ((int)(~(unsigned)0 >> 1)));
    rect.boundary[3] = (int) ceil(objp->pos.y + objp->sz.y + p.y);
    assert(rect.boundary[3] < ((int)(~(unsigned)0 >> 1)));

    return rect;
}

/* determine the position clp will occupy in intrsx[] */
static int getintrsxi(XLabels_t * xlp, object_t * op, object_t * cp)
{
    int i = -1;
    xlabel_t *lp = op->lbl, *clp = cp->lbl;
    assert(lp != clp);

    if (lp->set == 0 || clp->set == 0)
	return i;
    if ((op->pos.x == 0.0 && op->pos.y == 0.0) ||
	(cp->pos.x == 0.0 && cp->pos.y == 0.0))
	return i;

    if (cp->pos.y < op->pos.y)
	if (cp->pos.x < op->pos.x)
	    i = 0;
	else if (cp->pos.x > op->pos.x)
	    i = 2;
	else
	    i = 1;
    else if (cp->pos.y > op->pos.y)
	if (cp->pos.x < op->pos.x)
	    i = 6;
	else if (cp->pos.x > op->pos.x)
	    i = 8;
	else
	    i = 7;
    else if (cp->pos.x < op->pos.x)
	i = 3;
    else if (cp->pos.x > op->pos.x)
	i = 5;

    return i;

}

/* record the intersecting objects label */
static double
recordointrsx(XLabels_t * xlp, object_t * op, object_t * cp, Rect_t * rp,
	      double a, object_t * intrsx[9])
{
    int i = getintrsxi(xlp, op, cp);
    if (i < 0)
	i = 5;
    if (intrsx[i] != (void *)0) {
	double sa, maxa = 0.0;
	Rect_t srect;
	/* keep maximally overlapping object */
	objp2rect(intrsx[i], &srect);
	sa = aabbaabb(rp, &srect);
	if (sa > a)
	    maxa = sa;
	/*keep maximally overlapping label */
	if (intrsx[i]->lbl) {
	    objplp2rect(intrsx[i], &srect);
	    sa = aabbaabb(rp, &srect);
	    if (sa > a)
		maxa = sa > maxa ? sa : maxa;
	}
	if (maxa > 0.0)
	    return maxa;
	/*replace overlapping label/object pair */
	intrsx[i] = cp;
	return a;
    }
    intrsx[i] = cp;
    return a;
}

/* record the intersecting label */
static double
recordlintrsx(XLabels_t * xlp, object_t * op, object_t * cp, Rect_t * rp,
	      double a, object_t * intrsx[9])
{
    int i = getintrsxi(xlp, op, cp);
    if (i < 0)
	i = 5;
    if (intrsx[i] != (void *)0) {
	double sa, maxa = 0.0;
	Rect_t srect;
	/* keep maximally overlapping object */
	objp2rect(intrsx[i], &srect);
	sa = aabbaabb(rp, &srect);
	if (sa > a)
	    maxa = sa;
	/*keep maximally overlapping label */
	if (intrsx[i]->lbl) {
	    objplp2rect(intrsx[i], &srect);
	    sa = aabbaabb(rp, &srect);
	    if (sa > a)
		maxa = sa > maxa ? sa : maxa;
	}
	if (maxa > 0.0)
	    return maxa;
	/*replace overlapping label/object pair */
	intrsx[i] = cp;
	return a;
    }
    intrsx[i] = cp;
    return a;
}

/* find the objects and labels intersecting lp */
static BestPos_t
xlintersections(XLabels_t * xlp, object_t * objp, object_t * intrsx[9])
{
    int i;
    LeafList_t *ilp, *llp;
    Rect_t rect, srect;
    BestPos_t bp;

    assert(objp->lbl);

    bp.n = 0;
    bp.area = 0.0;
    bp.pos = objp->lbl->pos;

    for(i=0; i<xlp->n_objs; i++) {
      if(objp == &xlp->objs[i]) continue;
      if(xlp->objs[i].sz.x > 0 && xlp->objs[i].sz.y > 0) continue;
      if(lblenclosing(objp, &xlp->objs[i]) ) {
	bp.n++;
      }
    }

    objplp2rect(objp, &rect);

    llp = RTreeSearch(xlp->spdx, xlp->spdx->root, &rect);
    if (!llp)
	return bp;

    for (ilp = llp; ilp; ilp = ilp->next) {
	double a, ra;
	object_t *cp = ilp->leaf->data;

	if (cp == objp)
	    continue;

	/*label-object intersect */
	objp2rect(cp, &srect);
	a = aabbaabb(&rect, &srect);
	if (a > 0.0) {
	  ra = recordointrsx(xlp, objp, cp, &rect, a, intrsx);
	  bp.n++;
	  bp.area += ra;
	}
	/*label-label intersect */
	if (!cp->lbl || !cp->lbl->set)
	    continue;
	objplp2rect(cp, &srect);
	a = aabbaabb(&rect, &srect);
	if (a > 0.0) {
	  ra = recordlintrsx(xlp, objp, cp, &rect, a, intrsx);
	  bp.n++;
	  bp.area += ra;
	}
    }
    RTreeLeafListFree(llp);
    return bp;
}

/*
 * xladjust - find a label position
 * the individual tests at the top are intended to place a preference order
 * on the position
 */
static BestPos_t xladjust(XLabels_t * xlp, object_t * objp)
{
    xlabel_t *lp = objp->lbl;
    double xincr = ((2 * lp->sz.x) + objp->sz.x) / 8;
    double yincr = ((2 * lp->sz.y) + objp->sz.y) / 2;
    object_t *intrsx[9];
    BestPos_t bp, nbp;

    assert(objp->lbl);

    memset(intrsx, 0, sizeof(intrsx));

    /*x left */
    lp->pos.x = objp->pos.x - lp->sz.x;
    /*top */
    lp->pos.y = objp->pos.y + objp->sz.y;
    bp = xlintersections(xlp, objp, intrsx);
    if (bp.n == 0)
	return bp;
    /*mid */
    lp->pos.y = objp->pos.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;
    /*bottom */
    lp->pos.y = objp->pos.y - lp->sz.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;

    /*x mid */
    lp->pos.x = objp->pos.x;
    /*top */
    lp->pos.y = objp->pos.y + objp->sz.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;
    /*bottom */
    lp->pos.y = objp->pos.y - lp->sz.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;

    /*x right */
    lp->pos.x = objp->pos.x + objp->sz.x;
    /*top */
    lp->pos.y = objp->pos.y + objp->sz.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;
    /*mid */
    lp->pos.y = objp->pos.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;
    /*bottom */
    lp->pos.y = objp->pos.y - lp->sz.y;
    nbp = xlintersections(xlp, objp, intrsx);
    if (nbp.n == 0)
	return nbp;
    if (nbp.area < bp.area)
	bp = nbp;

    /*sliding from top left */
    if (intrsx[6] || intrsx[7] || intrsx[8] || intrsx[3] || intrsx[0]) {	/* have to move */
	if (!intrsx[7] && !intrsx[8]) {	/* some room right? */
	    /* slide along upper edge */
	    for (lp->pos.x = objp->pos.x - lp->sz.x,
		 lp->pos.y = objp->pos.y + objp->sz.y;
		 lp->pos.x <= (objp->pos.x + objp->sz.x);
		 lp->pos.x += xincr) {
		nbp = xlintersections(xlp, objp, intrsx);
		if (nbp.n == 0)
		    return nbp;
		if (nbp.area < bp.area)
		    bp = nbp;
	    }
	}
	if (!intrsx[3] && !intrsx[0]) {	/* some room down? */
	    /* slide down left edge */
	    for (lp->pos.x = objp->pos.x - lp->sz.x,
		 lp->pos.y = objp->pos.y + objp->sz.y;
		 lp->pos.y >= (objp->pos.y - lp->sz.y);
		 lp->pos.y -= yincr) {
		nbp = xlintersections(xlp, objp, intrsx);
		if (nbp.n == 0)
		    return nbp;
		if (nbp.area < bp.area)
		    bp = nbp;

	    }
	}
    }

    /*sliding from bottom right */
    lp->pos.x = objp->pos.x + objp->sz.x;
    lp->pos.y = objp->pos.y - lp->sz.y;
    if (intrsx[2] || intrsx[1] || intrsx[0] || intrsx[5] || intrsx[8]) {	/* have to move */
	if (!intrsx[1] && !intrsx[0]) {	/* some room left? */
	    /* slide along lower edge */
	    for (lp->pos.x = objp->pos.x + objp->sz.x,
		 lp->pos.y = objp->pos.y - lp->sz.y;
		 lp->pos.x >= (objp->pos.x - lp->sz.x);
		 lp->pos.x -= xincr) {
		nbp = xlintersections(xlp, objp, intrsx);
		if (nbp.n == 0)
		    return nbp;
		if (nbp.area < bp.area)
		    bp = nbp;
	    }
	}
	if (!intrsx[5] && !intrsx[8]) {	/* some room up? */
	    /* slide up right edge */
	    for (lp->pos.x = objp->pos.x + objp->sz.x,
		 lp->pos.y = objp->pos.y - lp->sz.y;
		 lp->pos.y <= (objp->pos.y + objp->sz.y);
		 lp->pos.y += yincr) {
		nbp = xlintersections(xlp, objp, intrsx);
		if (nbp.n == 0)
		    return nbp;
		if (nbp.area < bp.area)
		    bp = nbp;
	    }
	}
    }
    return bp;
}

/* load the hilbert sfc keyed tree */
static int xlhdxload(XLabels_t * xlp)
{
    int i;
    int order = xlhorder(xlp);

    for (i = 0; i < xlp->n_objs; i++) {
	HDict_t *hp;
	point pi;

	hp = (HDict_t*)zmalloc(sizeof(HDict_t));

	hp->d.data = &xlp->objs[i];
	hp->d.rect = objplpmks(xlp, &xlp->objs[i]);
	/* center of the labeling area */
	pi.x = hp->d.rect.boundary[0] +
	    (hp->d.rect.boundary[2] - hp->d.rect.boundary[0]) / 2;
	pi.y = hp->d.rect.boundary[1] +
	    (hp->d.rect.boundary[3] - hp->d.rect.boundary[1]) / 2;

	hp->key = hd_hil_s_from_xy(pi, order);


	
	    
	    
	

	if (!((*(((Dt_t*)(xlp->hdx))->searchf))((xlp->hdx),(void*)(hp),0000001)))
	    return -1;
    }
    return 0;
}

static void xlhdxunload(XLabels_t * xlp)
{
  int size=dtsize(xlp->hdx), freed=0;
  while(dtsize(xlp->hdx) ) {
    void*vp=(((Dt_t*)(xlp->hdx))->data->here ? (((Dt_t*)((xlp->hdx)))->disc->link < 0 ? ((Dthold_t*)((((Dt_t*)(xlp->hdx))->data->here)))->obj : (void*)((char*)((((Dt_t*)(xlp->hdx))->data->here)) - ((Dt_t*)((xlp->hdx)))->disc->link) ):(void*)(0));
    assert(vp);
    if(vp) {
      (*(((Dt_t*)(xlp->hdx))->searchf))((xlp->hdx),(void*)(vp),0010000);
      free(vp);
      freed++;
    }
  }
  assert(size==freed);
}

static int xlspdxload(XLabels_t * xlp)
{
    HDict_t *op=0;

    for (op = (*(((Dt_t*)(xlp->hdx))->searchf))((xlp->hdx),(void*)(0),0000200); op; op = (*(((Dt_t*)(xlp->hdx))->searchf))((xlp->hdx),(void*)(op),0000010)) {
	/*          tree       rectangle    data        node             lvl */
	RTreeInsert(xlp->spdx, &op->d.rect, op->d.data, &xlp->spdx->root, 0);
    }
    return 0;
}

static int xlinitialize(XLabels_t * xlp)
{
    int r=0;
    if ((r = xlhdxload(xlp)) < 0)
	return r;
    if ((r = xlspdxload(xlp)) < 0)
	return r;
    xlhdxunload(xlp);
    return dtclose(xlp->hdx);
}

int
placeLabels(object_t * objs, int n_objs,
	    xlabel_t * lbls, int n_lbls, label_params_t * params)
{
    int r, i;
    BestPos_t bp;
    XLabels_t *xlp = xlnew(objs, n_objs, lbls, n_lbls, params);
    if ((r = xlinitialize(xlp)) < 0)
	return r;

    /* Place xlabel_t* lp near lp->obj so that the rectangle whose lower-left
     * corner is lp->pos, and size is lp->sz does not intersect any object
     * in objs (by convention, an object consisting of a single point
     * intersects nothing) nor any other label, if possible. On input,
     * lp->set is 0.
     *
     * On output, any label with a position should have this stored in
     * lp->pos and have lp->set non-zero.
     *
     * If params->force is true, all labels must be positioned, even if
     * overlaps are necessary.
     *
     * Return 0 if all labels could be placed without overlap;
     * non-zero otherwise.
     */
    r = 0;
    for (i = 0; i < n_objs; i++) {
	if (objs[i].lbl == 0)
	    continue;
	bp = xladjust(xlp, &objs[i]);
	if (bp.n == 0) {
	    objs[i].lbl->set = 1;
	} else if(bp.area == 0) {
	    objs[i].lbl->pos.x = bp.pos.x;
	    objs[i].lbl->pos.y = bp.pos.y;
	    objs[i].lbl->set = 1;
	} else if (params->force == 1) {
	    objs[i].lbl->pos.x = bp.pos.x;
	    objs[i].lbl->pos.y = bp.pos.y;
	    objs[i].lbl->set = 1;
	} else {
	    r = 1;
	}
    }
    xlfree(xlp);
    return r;
}
