#line 1 "graphviz-2.38.0\\lib\\label\\node.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\label\\node.c" 1

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










#line 17 "graphviz-2.38.0\\lib\\label\\node.c" 2
#line 1 "graphviz-2.38.0\\lib\\label\\node.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\node.c" 1
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











    
    



    
    
    





















#line 20 "graphviz-2.38.0\\lib\\label\\node.c" 2

/* Make a new node and initialize to have all branch cells empty.
*/
Node_t *RTreeNewNode(RTree_t * rtp)
{
    register Node_t *n;

    rtp->NodeCount++;
    n = (Node_t *) malloc(sizeof(Node_t));
    InitNode(n);
    return n;
}

void RTreeFreeNode(RTree_t * rtp, Node_t * p)
{
    rtp->NodeCount--;
    if (p->level == 0)
	rtp->LeafCount--;
    else
	rtp->NonLeafCount--;
    free(p);
}

/* Initialize a Node structure.
*/
void InitNode(Node_t * n)
{
    register int i;
    n->count = 0;
    n->level = -1;
    for (i = 0; i < 64; i++)
	InitBranch(&(n->branch[i]));
}

/* Initialize one branch cell in a node.
*/
void InitBranch(Branch_t * b)
{
    InitRect(&(b->rect));
    b->child = NULL;
}






    
    

    
    
	
    
	
    
	
    
	    

    
	
	    
    




    
    



/* Find the smallest rectangle that includes all rectangles in
** branches of a node.
*/
Rect_t NodeCover(Node_t * n)
{
    register int i, flag;
    Rect_t r;
    assert(n);

    InitRect(&r);
    flag = 1;
    for (i = 0; i < 64; i++)
	if (n->branch[i].child) {
	    if (flag) {
		r = n->branch[i].rect;
		flag = 0;
	    } else
		r = CombineRect(&r, &(n->branch[i].rect));
	}
    return r;
}

/* Pick a branch.  Pick the one that will need the smallest increase
** in area to accomodate the new rectangle.  This will result in the
** least total area for the covering rectangles in the current node.
** In case of a tie, pick the one which was smaller before, to get
** the best resolution when searching.
*/
int PickBranch(Rect_t * r, Node_t * n)
{
    register Rect_t *rr=0;
    register int i=0, flag=1, increase=0, bestIncr=0, area=0, bestArea=0;
    int best=0;
    assert(r && n);

    for (i = 0; i < 64; i++) {
	if (n->branch[i].child) {
	    Rect_t rect;
	    rr = &n->branch[i].rect;
	    area = RectArea(rr);
	    /* increase = RectArea(&CombineRect(r, rr)) - area; */
	    rect = CombineRect(r, rr);
	    increase = RectArea(&rect) - area;
	    if (increase < bestIncr || flag) {
		best = i;
		bestArea = area;
		bestIncr = increase;
		flag = 0;
	    } else if (increase == bestIncr && area < bestArea) {
		best = i;
		bestArea = area;
		bestIncr = increase;
	    }

	    
		    
		    

	}
    }

    

    return best;
}

/* Add a branch to a node.  Split the node if necessary.
** Returns 0 if node not split.  Old node updated.
** Returns 1 if node split, sets *new to address of new node.
** Old node updated, becomes one of two.
*/
int AddBranch(RTree_t * rtp, Branch_t * b, Node_t * n, Node_t ** new)
{
    register int i;

    assert(b);
    assert(n);

    if (n->count < 64) {	/* split won't be necessary */
	for (i = 0; i < 64; i++) {	/* find empty branch */
	    if (n->branch[i].child == NULL) {
		n->branch[i] = *b;
		n->count++;
		break;
	    }
	}
	assert(i < 64);
	return 0;
    } else {
	if (rtp->StatFlag) {
	    if (rtp->Deleting)
		rtp->DeTouchCount++;
	    else
		rtp->InTouchCount++;
	}
	assert(new);
	SplitNode(rtp, n, b, new);
	if (n->level == 0)
	    rtp->LeafCount++;
	else
	    rtp->NonLeafCount++;
	return 1;
    }
}

/* Disconnect a dependent node.
*/
void DisconBranch(Node_t * n, int i)
{
    assert(n && i >= 0 && i < 64);
    assert(n->branch[i].child);

    InitBranch(&(n->branch[i]));
    n->count--;
}
