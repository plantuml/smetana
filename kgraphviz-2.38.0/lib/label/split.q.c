#line 1 "graphviz-2.38.0\\lib\\label\\split.q.c" 1
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










#line 15 "graphviz-2.38.0\\lib\\label\\split.q.c" 2
#line 1 "graphviz-2.38.0\\lib\\label\\split.q.c" 1
#line 1 "graphviz-2.38.0\\lib\\label\\split.q.c" 1
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


















    
    
    
    
    
    



    
    
    
    









#line 18 "graphviz-2.38.0\\lib\\label\\split.q.c" 2
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


















































#line 19 "graphviz-2.38.0\\lib\\label\\split.q.c" 2

/* Forward declarations */
static void MethodZero(RTree_t * rtp);
static void InitPVars(RTree_t * rtp);
static void LoadNodes(RTree_t * rtp, Node_t * n, Node_t * q,
		      struct PartitionVars *p);
static void Classify(RTree_t * rtp, int i, int group);
static void PickSeeds(RTree_t * rtp);
static void GetBranches(RTree_t * rtp, Node_t * n, Branch_t * b);

/*-----------------------------------------------------------------------------
| Split a node.
| Divides the nodes branches and the extra one between two nodes.
| Old node is one of the new ones, and one really new one is created.
| Tries more than one method for choosing a partition, uses best result.
-----------------------------------------------------------------------------*/
void SplitNode(RTree_t * rtp, Node_t * n, Branch_t * b, Node_t ** nn)
{
    register struct PartitionVars *p;
    register int level;
    int area;

    assert(n);
    assert(b);


    
    
    
    


    if (rtp->StatFlag) {
	if (rtp->Deleting)
	    rtp->DeSplitCount++;
	else
	    rtp->InSplitCount++;
    }

    /* load all the branches into a buffer, initialize old node */
    level = n->level;
    GetBranches(rtp, n, b);


    
	
	
	
	    
	
	
    


    /* find partition */
    p = &rtp->split.Partitions[0];
    MethodZero(rtp);

    area = RectArea(&p->cover[0]) + RectArea(&p->cover[1]);

    /* record how good the split was for statistics */
    if (rtp->StatFlag && !rtp->Deleting && area)
	rtp->SplitMeritSum += (float) rtp->split.CoverSplitArea / area;

    /* put branches from buffer into 2 nodes according to chosen partition */
    *nn = RTreeNewNode(rtp);
    (*nn)->level = n->level = level;
    LoadNodes(rtp, n, *nn, p);
    assert(n->count + (*nn)->count == 64 + 1);


    
    
    
    
    
    


}

/*-----------------------------------------------------------------------------
| Load branch buffer with branches from full node plus the extra branch.
-----------------------------------------------------------------------------*/
static void GetBranches(RTree_t * rtp, Node_t * n, Branch_t * b)
{
    register int i;

    assert(n);
    assert(b);

    /* load the branch buffer */
    for (i = 0; i < 64; i++) {
	assert(n->branch[i].child);	/* node should have every entry full */
	rtp->split.BranchBuf[i] = n->branch[i];
    }
    rtp->split.BranchBuf[64] = *b;

    /* calculate rect containing all in the set */
    rtp->split.CoverSplit = rtp->split.BranchBuf[0].rect;
    for (i = 1; i < 64 + 1; i++) {
	rtp->split.CoverSplit = CombineRect(&rtp->split.CoverSplit,
					    &rtp->split.BranchBuf[i].rect);
    }
    rtp->split.CoverSplitArea = RectArea(&rtp->split.CoverSplit);

    InitNode(n);
}

/*-----------------------------------------------------------------------------
| Method #0 for choosing a partition:
| As the seeds for the two groups, pick the two rects that would waste the
| most area if covered by a single rectangle, i.e. evidently the worst pair
| to have in the same group.
| Of the remaining, one at a time is chosen to be put in one of the two groups.
| The one chosen is the one with the greatest difference in area expansion
| depending on which group - the rect most strongly attracted to one group
| and repelled from the other.
| If one group gets too full (more would force other group to violate min
| fill requirement) then other group gets the rest.
| These last are the ones that can go in either group most easily.
-----------------------------------------------------------------------------*/
static void MethodZero(RTree_t * rtp)
{
    register Rect_t *r;
    register int i, growth0, growth1, diff, biggestDiff;
    register int group, chosen, betterGroup;

    InitPVars(rtp);
    PickSeeds(rtp);

    while (rtp->split.Partitions[0].count[0] +
	   rtp->split.Partitions[0].count[1] < 64 + 1 &&
	   rtp->split.Partitions[0].count[0] < 64 + 1 - rtp->MinFill
	   && rtp->split.Partitions[0].count[1] <
	   64 + 1 - rtp->MinFill) {
	biggestDiff = -1;
	for (i = 0; i < 64 + 1; i++) {
	    if (!rtp->split.Partitions[0].taken[i]) {
		Rect_t rect;
		r = &rtp->split.BranchBuf[i].rect;
		/* growth0 = RectArea(&CombineRect(r,
		   &rtp->split.Partitions[0].cover[0])) -
		   rtp->split.Partitions[0].area[0];
		 */
		/* growth1 = RectArea(&CombineRect(r,
		   &rtp->split.Partitions[0].cover[1])) -
		   rtp->split.Partitions[0].area[1];
		 */
		rect = CombineRect(r, &rtp->split.Partitions[0].cover[0]);
		growth0 =
		    RectArea(&rect) - rtp->split.Partitions[0].area[0];
		rect = CombineRect(r, &rtp->split.Partitions[0].cover[1]);
		growth1 =
		    RectArea(&rect) - rtp->split.Partitions[0].area[1];
		diff = growth1 - growth0;
		if (diff >= 0)
		    group = 0;
		else {
		    group = 1;
		    diff = -diff;
		}

		if (diff > biggestDiff) {
		    biggestDiff = diff;
		    chosen = i;
		    betterGroup = group;
		} else if (diff == biggestDiff &&
			   rtp->split.Partitions[0].count[group] <
			   rtp->split.Partitions[0].count[betterGroup]) {
		    chosen = i;
		    betterGroup = group;
		}
	    }
	}
	Classify(rtp, chosen, betterGroup);
    }

    /* if one group too full, put remaining rects in the other */
    if (rtp->split.Partitions[0].count[0] +
	rtp->split.Partitions[0].count[1] < 64 + 1) {
	group = 0;
	if (rtp->split.Partitions[0].count[0] >=
	    64 + 1 - rtp->MinFill)
	    group = 1;
	for (i = 0; i < 64 + 1; i++) {
	    if (!rtp->split.Partitions[0].taken[i])
		Classify(rtp, i, group);
	}
    }

    assert(rtp->split.Partitions[0].count[0] +
	   rtp->split.Partitions[0].count[1] == 64 + 1);
    assert(rtp->split.Partitions[0].count[0] >= rtp->MinFill
	   && rtp->split.Partitions[0].count[1] >= rtp->MinFill);
}

/*-----------------------------------------------------------------------------
| Pick two rects from set to be the first elements of the two groups.
| Pick the two that waste the most area if covered by a single rectangle.
-----------------------------------------------------------------------------*/
static void PickSeeds(RTree_t * rtp)
{
  register int i, j;
  unsigned int waste, worst;
  int seed0, seed1;
  unsigned int area[64 + 1];

    for (i = 0; i < 64 + 1; i++)
	area[i] = RectArea(&rtp->split.BranchBuf[i].rect);

    //worst = -rtp->split.CoverSplitArea - 1;
    worst=0;
    for (i = 0; i < 64; i++) {
	for (j = i + 1; j < 64 + 1; j++) {
	    Rect_t rect;
	    /* waste = RectArea(&CombineRect(&rtp->split.BranchBuf[i].rect,
	       //                  &rtp->split.BranchBuf[j].rect)) - area[i] - area[j];
	     */
	    rect = CombineRect(&rtp->split.BranchBuf[i].rect,
			       &rtp->split.BranchBuf[j].rect);
	    waste = RectArea(&rect) - area[i] - area[j];
	    if (waste > worst) {
		worst = waste;
		seed0 = i;
		seed1 = j;
	    }
	}
    }
    Classify(rtp, seed0, 0);
    Classify(rtp, seed1, 1);
}

/*-----------------------------------------------------------------------------
| Put a branch in one of the groups.
-----------------------------------------------------------------------------*/
static void Classify(RTree_t * rtp, int i, int group)
{

    assert(!rtp->split.Partitions[0].taken[i]);

    rtp->split.Partitions[0].partition[i] = group;
    rtp->split.Partitions[0].taken[i] = (!(0));

    if (rtp->split.Partitions[0].count[group] == 0)
	rtp->split.Partitions[0].cover[group] =
	    rtp->split.BranchBuf[i].rect;
    else
	rtp->split.Partitions[0].cover[group] =
	    CombineRect(&rtp->split.BranchBuf[i].rect,
			&rtp->split.Partitions[0].cover[group]);
    rtp->split.Partitions[0].area[group] =
	RectArea(&rtp->split.Partitions[0].cover[group]);
    rtp->split.Partitions[0].count[group]++;


    
	
	
	
	
	
	
	    
		
		
	
	
    

}

/*-----------------------------------------------------------------------------
| Copy branches from the buffer into two nodes according to the partition.
-----------------------------------------------------------------------------*/
static void LoadNodes(RTree_t * rtp, Node_t * n, Node_t * q,
		      struct PartitionVars *p)
{
    register int i;
    assert(n);
    assert(q);
    assert(p);

    for (i = 0; i < 64 + 1; i++) {
	assert(rtp->split.Partitions[0].partition[i] == 0 ||
	       rtp->split.Partitions[0].partition[i] == 1);
	if (rtp->split.Partitions[0].partition[i] == 0)
	    AddBranch(rtp, &rtp->split.BranchBuf[i], n, (void *)0);
	else if (rtp->split.Partitions[0].partition[i] == 1)
	    AddBranch(rtp, &rtp->split.BranchBuf[i], q, (void *)0);
    }
}

/*-----------------------------------------------------------------------------
| Initialize a PartitionVars structure.
-----------------------------------------------------------------------------*/
static void InitPVars(RTree_t * rtp)
{
    register int i;

    rtp->split.Partitions[0].count[0] = rtp->split.Partitions[0].count[1] =
	0;
    rtp->split.Partitions[0].cover[0] = rtp->split.Partitions[0].cover[1] =
	NullRect();
    rtp->split.Partitions[0].area[0] = rtp->split.Partitions[0].area[1] =
	0;
    for (i = 0; i < 64 + 1; i++) {
	rtp->split.Partitions[0].taken[i] = (0);
	rtp->split.Partitions[0].partition[i] = -1;
    }
}








    

    
    
	
    
    
    
	
	    
	
	    
    
    
    
	
    
    

    
	    
	    
    
	    
	    
    
	
	
		
		
		
		
		 
    
    
    

    
    


