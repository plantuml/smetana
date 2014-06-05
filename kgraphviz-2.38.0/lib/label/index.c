#line 1 "graphviz-2.38.0\\lib\\label\\index.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\label\\index.c" 1

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










#line 17 "graphviz-2.38.0\\lib\\label\\index.c" 2
#line 1 "graphviz-2.38.0\\lib\\label\\index.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\index.c" 1
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


















































#line 20 "graphviz-2.38.0\\lib\\label\\index.c" 2
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







#line 21 "graphviz-2.38.0\\lib\\label\\index.c" 2

LeafList_t *RTreeNewLeafList(Leaf_t * lp)
{
    LeafList_t *llp;

    if ((llp = (LeafList_t*)zmalloc(sizeof(LeafList_t)))) {
	llp->leaf = lp;
	llp->next = 0;
    }
    return llp;
}

LeafList_t *RTreeLeafListAdd(LeafList_t * llp, Leaf_t * lp)
{
    LeafList_t *nlp;
    if (!lp)
	return llp;

    nlp = RTreeNewLeafList(lp);
    nlp->next = llp;
    return nlp;
}

void RTreeLeafListFree(LeafList_t * llp)
{
    LeafList_t *tlp;
    while (llp->next) {
	tlp = llp->next;
	free(llp);
	llp = tlp;
    }
    free(llp);
    return;
}

/* Allocate space for a node in the list used in DeletRect to
 * store Nodes that are too empty.
 */
static struct ListNode *RTreeNewListNode(void)
{
    return (struct ListNode*)zmalloc(sizeof(struct ListNode));
}




    



/* Add a node to the reinsertion list.  All its branches will later
 * be reinserted into the index structure.
 */
static int RTreeReInsert(RTree_t * rtp, Node_t * n, struct ListNode **ee)
{
    register struct ListNode *l;

    if (!(l = RTreeNewListNode()))
	return -1;
    l->node = n;
    l->next = *ee;
    *ee = l;
    return 0;
}

RTree_t *RTreeOpen()
{
    RTree_t *rtp;

    if ((rtp = (RTree_t*)zmalloc(sizeof(RTree_t))))
	rtp->root = RTreeNewIndex(rtp);
    return rtp;
}

/* Make a new index, empty.  Consists of a single node. */
Node_t *RTreeNewIndex(RTree_t * rtp)
{
    Node_t *x;
    x = RTreeNewNode(rtp);
    x->level = 0;		/* leaf */
    rtp->LeafCount++;
    return x;
}

static int RTreeClose2(RTree_t * rtp, Node_t * n)
{
    int i;

    if (n->level > 0) {
	for (i = 0; i < 64; i++) {
	    if (!n->branch[i].child)
		continue;
	    if (!RTreeClose2(rtp, n->branch[i].child)) {
		free(n->branch[i].child);
		DisconBranch(n, i);
		rtp->EntryCount--;
		if (rtp->StatFlag)
		    rtp->ElimCount++;
	    }
	}
    } else {
	for (i = 0; i < 64; i++) {
	    if (!n->branch[i].child)
		continue;
	    // free(n->branch[i].child);
	    DisconBranch(n, i);
	    rtp->EntryCount--;
	    if (rtp->StatFlag)
	        rtp->ElimCount++;
	}
	//free(n);
    }
    return 0;
}


int RTreeClose(RTree_t * rtp)
{
    RTreeClose2(rtp, rtp->root);
    free(rtp->root);
    free(rtp);
    return 0;
}







    
    
    
    

    
	
	    
		
	
    

    






    
    
    
    

    
	
    
	
	    
		
	
    



/* RTreeSearch in an index tree or subtree for all data retangles that
** overlap the argument rectangle.
** Returns the number of qualifying data rects.
*/
LeafList_t *RTreeSearch(RTree_t * rtp, Node_t * n, Rect_t * r)
{
    register int i;
    LeafList_t *llp = 0;

    assert(n);
    assert(n->level >= 0);
    assert(r);

    rtp->SeTouchCount++;

    if (n->level > 0) {		/* this is an internal node in the tree */
	for (i = 0; i < 64; i++)
	    if (n->branch[i].child && Overlap(r, &n->branch[i].rect)) {
		LeafList_t *tlp = RTreeSearch(rtp, n->branch[i].child, r);
		if (llp) {
		    LeafList_t *xlp = llp;
		    while (xlp->next)
			xlp = xlp->next;
		    xlp->next = tlp;
		} else
		    llp = tlp;
	    }
    } else {			/* this is a leaf node */
	for (i = 0; i < 64; i++) {
	    if (n->branch[i].child && Overlap(r, &n->branch[i].rect)) {
		llp = RTreeLeafListAdd(llp, (Leaf_t *) & n->branch[i]);

		

	    }
	}
    }
    return llp;
}

/* Insert a data rectangle into an index structure.
** RTreeInsert provides for splitting the root;
** returns 1 if root was split, 0 if it was not.
** The level argument specifies the number of steps up from the leaf
** level to insert; e.g. a data rectangle goes in at level = 0.
** RTreeInsert2 does the recursion.
*/
static int RTreeInsert2(RTree_t *, Rect_t *, void *, Node_t *, Node_t **,
			int);
/*static int RTreeInsert2(RTree_t*, Rect_t*, int, Node_t*, Node_t**, int); */

int
RTreeInsert(RTree_t * rtp, Rect_t * r, void *data, Node_t ** n, int level)
{
    /* RTreeInsert(RTree_t*rtp, Rect_t*r, int data, Node_t**n, int level) { */
    register int i;
    register Node_t *newroot;
    Node_t *newnode=0;
    Branch_t b;
    int result = 0;


    assert(r && n);
    assert(level >= 0 && level <= (*n)->level);
    for (i = 0; i < 2; i++)
	assert(r->boundary[i] <= r->boundary[2 + i]);


    


    if (rtp->StatFlag) {
	if (rtp->Deleting)
	    rtp->ReInsertCount++;
	else
	    rtp->InsertCount++;
    }
    if (!rtp->Deleting)
	rtp->RectCount++;

    if (RTreeInsert2(rtp, r, data, *n, &newnode, level)) {	/* root was split */
	if (rtp->StatFlag) {
	    if (rtp->Deleting)
		rtp->DeTouchCount++;
	    else
		rtp->InTouchCount++;
	}

	newroot = RTreeNewNode(rtp);	/* grow a new root, make tree taller */
	rtp->NonLeafCount++;
	newroot->level = (*n)->level + 1;
	b.rect = NodeCover(*n);
	b.child = *n;
	AddBranch(rtp, &b, newroot, (void *)0);
	b.rect = NodeCover(newnode);
	b.child = newnode;
	AddBranch(rtp, &b, newroot, (void *)0);
	*n = newroot;
	// rtp->root = newroot;
	rtp->EntryCount += 2;
	result = 1;
    }

    return result;
}

/* Inserts a new data rectangle into the index structure.
** Recursively descends tree, propagates splits back up.
** Returns 0 if node was not split.  Old node updated.
** If node was split, returns 1 and sets the pointer pointed to by
** new to point to the new node.  Old node updated to become one of two.
** The level argument specifies the number of steps up from the leaf
** level to insert; e.g. a data rectangle goes in at level = 0.
*/
static int
RTreeInsert2(RTree_t * rtp, Rect_t * r, void *data,
	     Node_t * n, Node_t ** new, int level)
{
    /*static int */
    /* RTreeInsert2(RTree_t*rtp, Rect_t*r,
       int data, Node_t*n, Node_t**new, int level) {
     */
    register int i=0;
    Branch_t b;
    Node_t *n2=0;

    assert(r && n && new);
    assert(level >= 0 && level <= n->level);

    if (rtp->StatFlag) {
	if (rtp->Deleting)
	    rtp->DeTouchCount++;
	else
	    rtp->InTouchCount++;
    }

    /* Still above level for insertion, go down tree recursively */
    if (n->level > level) {
	i = PickBranch(r, n);
	if (!RTreeInsert2(rtp, r, data, n->branch[i].child, &n2, level)) {	/* recurse: child was not split */
	    n->branch[i].rect = CombineRect(r, &(n->branch[i].rect));
	    return 0;
	} else {		/* child was split */
	    n->branch[i].rect = NodeCover(n->branch[i].child);
	    b.child = n2;
	    b.rect = NodeCover(n2);
	    rtp->EntryCount++;
	    return AddBranch(rtp, &b, n, new);
	}
    } else if (n->level == level) {	/* at level for insertion. */
	/*Add rect, split if necessary */
	b.rect = *r;
	b.child = (Node_t *) data;
	rtp->EntryCount++;
	return AddBranch(rtp, &b, n, new);
    } else {			/* Not supposed to happen */
	assert((0));
	return 0;
    }
}

static void FreeListNode(register struct ListNode *p)
{
    free(p);
}

/* Delete a data rectangle from an index structure.
** Pass in a pointer to a Rect, the data of the record, ptr to ptr to root node.
** Returns 1 if record not found, 0 if success.
** RTreeDelete provides for eliminating the root.
*/
static int RTreeDelete2(RTree_t *, Rect_t *, void *, Node_t *,
			ListNode_t **);
/* static int RTreeDelete2(RTree_t*, Rect_t*, int, Node_t*, ListNode_t**); */

int RTreeDelete(RTree_t * rtp, Rect_t * r, void *data, Node_t ** nn)
{
    /* int */
    /* RTreeDelete(RTree_t*rtp, Rect_t*r, int data, Node_t**nn) { */
    register int i;
    register Node_t *t;
    struct ListNode *reInsertList = (void *)0;
    register struct ListNode *e;

    assert(r && nn);
    assert(*nn);
    assert(data >= 0);

    rtp->Deleting = (!(0));


    


    if (!RTreeDelete2(rtp, r, data, *nn, &reInsertList)) {
	/* found and deleted a data item */
	if (rtp->StatFlag)
	    rtp->DeleteCount++;
	rtp->RectCount--;

	/* reinsert any branches from eliminated nodes */
	while (reInsertList) {
	    t = reInsertList->node;
	    for (i = 0; i < 64; i++) {
		if (t->branch[i].child) {
		    RTreeInsert(rtp, &(t->branch[i].rect),
				/* (int)t->branch[i].child, nn, t->level); */
				t->branch[i].child, nn, t->level);
		    rtp->EntryCount--;
		}
	    }
	    e = reInsertList;
	    reInsertList = reInsertList->next;
	    RTreeFreeNode(rtp, e->node);
	    FreeListNode(e);
	}

	/* check for redundant root (not leaf, 1 child) and eliminate */
	if ((*nn)->count == 1 && (*nn)->level > 0) {
	    if (rtp->StatFlag)
		rtp->ElimCount++;
	    rtp->EntryCount--;
	    for (i = 0; i < 64; i++) {
		if ((t = (*nn)->branch[i].child))
		    break;
	    }
	    RTreeFreeNode(rtp, *nn);
	    *nn = t;
	}
	rtp->Deleting = (0);
	return 0;
    } else {
	rtp->Deleting = (0);
	return 1;
    }
}

/* Delete a rectangle from non-root part of an index structure.
** Called by RTreeDelete.  Descends tree recursively,
** merges branches on the way back up.
*/
static int
RTreeDelete2(RTree_t * rtp, Rect_t * r, void *data, Node_t * n,
	     ListNode_t ** ee)
/* static int */
/* RTreeDelete2(RTree_t*rtp, Rect_t*r, int data, Node_t*n, ListNode_t**ee) */
{
    register int i;

    assert(r && n && ee);
    assert(data >= 0);
    assert(n->level >= 0);

    if (rtp->StatFlag)
	rtp->DeTouchCount++;

    if (n->level > 0) {		/* not a leaf node */
	for (i = 0; i < 64; i++) {
	    if (n->branch[i].child && Overlap(r, &(n->branch[i].rect))) {
		if (!RTreeDelete2(rtp, r, data, n->branch[i].child, ee)) {	/*recurse */
		    if (n->branch[i].child->count >= rtp->MinFill)
			n->branch[i].rect = NodeCover(n->branch[i].child);
		    else {	/* not enough entries in child, eliminate child node */
			RTreeReInsert(rtp, n->branch[i].child, ee);
			DisconBranch(n, i);
			rtp->EntryCount--;
			if (rtp->StatFlag)
			    rtp->ElimCount++;
		    }
		    return 0;
		}
	    }
	}
	return 1;
    } else {			/* a leaf node */
	for (i = 0; i < 64; i++) {
	    if (n->branch[i].child
		&& n->branch[i].child == (Node_t *) data) {
		DisconBranch(n, i);
		rtp->EntryCount--;
		return 0;
	    }
	}
	return 1;
    }
}







    



