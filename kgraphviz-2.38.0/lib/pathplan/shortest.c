#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1
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


#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1
#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1
#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1



#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1
#line 1 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 1
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










    
    

    typedef struct Pxy_t {
	double x, y;
    } Pxy_t;

    typedef struct Pxy_t Ppoint_t;
    typedef struct Pxy_t Pvector_t;


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






#line 22 "graphviz-2.38.0\\lib\\pathplan\\shortest.c" 2






















typedef struct pointnlink_t {
    Ppoint_t *pp;
    struct pointnlink_t *link;
} pointnlink_t;




typedef struct tedge_t {
    pointnlink_t *pnl0p;
    pointnlink_t *pnl1p;
    struct triangle_t *ltp;
    struct triangle_t *rtp;
} tedge_t;

typedef struct triangle_t {
    int mark;
    struct tedge_t e[3];
} triangle_t;



typedef struct deque_t {
    pointnlink_t **pnlps;
    int pnlpn, fpnlpi, lpnlpi, apex;
} deque_t;

static jmp_buf jbuf;
static pointnlink_t *pnls, **pnlps;
static int pnln, pnll;

static triangle_t *tris;
static int trin, tril;

static deque_t dq;

static Ppoint_t *ops;
static int opn;

static void triangulate(pointnlink_t **, int);
static int isdiagonal(int, int, pointnlink_t **, int);
static void loadtriangle(pointnlink_t *, pointnlink_t *, pointnlink_t *);
static void connecttris(int, int);
static int marktripath(int, int);

static void add2dq(int, pointnlink_t *);
static void splitdq(int, int);
static int finddqsplit(pointnlink_t *);

static int ccw(Ppoint_t *, Ppoint_t *, Ppoint_t *);
static int intersects(Ppoint_t *, Ppoint_t *, Ppoint_t *, Ppoint_t *);
static int between(Ppoint_t *, Ppoint_t *, Ppoint_t *);
static int pointintri(int, Ppoint_t *);

static void growpnls(int);
static void growtris(int);
static void growdq(int);
static void growops(int);

/* Pshortestpath:
 * Find a shortest path contained in the polygon polyp going between the
 * points supplied in eps. The resulting polyline is stored in output.
 * Return 0 on success, -1 on bad input, -2 on memory allocation problem. 
 */
int Pshortestpath(Ppoly_t * polyp, Ppoint_t * eps, Ppolyline_t * output)
{
    int pi, minpi;
    double minx;
    Ppoint_t p1, p2, p3;
    int trii, trij, ftrii, ltrii;
    int ei;
    pointnlink_t epnls[2], *lpnlp, *rpnlp, *pnlp;
    triangle_t *trip;
    int splitindex;

    


    if (setjmp(jbuf))
	return -2;
    /* make space */
    growpnls(polyp->pn);
    pnll = 0;
    tril = 0;
    growdq(polyp->pn * 2);
    dq.fpnlpi = dq.pnlpn / 2, dq.lpnlpi = dq.fpnlpi - 1;

    /* make sure polygon is CCW and load pnls array */
    for (pi = 0, minx = HUGE_VAL, minpi = -1; pi < polyp->pn; pi++) {
	if (minx > polyp->ps[pi].x)
	    minx = polyp->ps[pi].x, minpi = pi;
    }
    p2 = polyp->ps[minpi];
    p1 = polyp->ps[((minpi == 0) ? polyp->pn - 1 : minpi - 1)];
    p3 = polyp->ps[((minpi == polyp->pn - 1) ? 0 : minpi + 1)];
    if (((p1.x == p2.x && p2.x == p3.x) && (p3.y > p2.y)) ||
	ccw(&p1, &p2, &p3) != 1) {
	for (pi = polyp->pn - 1; pi >= 0; pi--) {
	    if (pi < polyp->pn - 1
		&& polyp->ps[pi].x == polyp->ps[pi + 1].x
		&& polyp->ps[pi].y == polyp->ps[pi + 1].y)
		continue;
	    pnls[pnll].pp = &polyp->ps[pi];
	    pnls[pnll].link = &pnls[pnll % polyp->pn];
	    pnlps[pnll] = &pnls[pnll];
	    pnll++;
	}
    } else {
	for (pi = 0; pi < polyp->pn; pi++) {
	    if (pi > 0 && polyp->ps[pi].x == polyp->ps[pi - 1].x &&
		polyp->ps[pi].y == polyp->ps[pi - 1].y)
		continue;
	    pnls[pnll].pp = &polyp->ps[pi];
	    pnls[pnll].link = &pnls[pnll % polyp->pn];
	    pnlps[pnll] = &pnls[pnll];
	    pnll++;
	}
    }


    
    
	


    /* generate list of triangles */
    triangulate(pnlps, pnll);


    
    
	
	    
		    


    /* connect all pairs of triangles that share an edge */
    for (trii = 0; trii < tril; trii++)
	for (trij = trii + 1; trij < tril; trij++)
	    connecttris(trii, trij);

    /* find first and last triangles */
    for (trii = 0; trii < tril; trii++)
	if (pointintri(trii, &eps[0]))
	    break;
    if (trii == tril) {
	fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("source point not in any triangle"));
	return -1;
    }
    ftrii = trii;
    for (trii = 0; trii < tril; trii++)
	if (pointintri(trii, &eps[1]))
	    break;
    if (trii == tril) {
	fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("destination point not in any triangle"));
	return -1;
    }
    ltrii = trii;

    /* mark the strip of triangles from eps[0] to eps[1] */
    if (!marktripath(ftrii, ltrii)) {
	fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot find triangle path"));
	/* a straight line is better than failing */
	growops(2);
	output->pn = 2;
	ops[0] = eps[0], ops[1] = eps[1];
	output->ps = ops;
	return 0;
    }

    /* if endpoints in same triangle, use a single line */
    if (ftrii == ltrii) {
	growops(2);
	output->pn = 2;
	ops[0] = eps[0], ops[1] = eps[1];
	output->ps = ops;
	return 0;
    }

    /* build funnel and shortest path linked list (in add2dq) */
    epnls[0].pp = &eps[0], epnls[0].link = NULL;
    epnls[1].pp = &eps[1], epnls[1].link = NULL;
    add2dq(1, &epnls[0]);
    dq.apex = dq.fpnlpi;
    trii = ftrii;
    while (trii != -1) {
	trip = &tris[trii];
	trip->mark = 2;

	/* find the left and right points of the exiting edge */
	for (ei = 0; ei < 3; ei++)
	    if (trip->e[ei].rtp && trip->e[ei].rtp->mark == 1)
		break;
	if (ei == 3) {		/* in last triangle */
	    if (ccw(&eps[1], dq.pnlps[dq.fpnlpi]->pp,
		    dq.pnlps[dq.lpnlpi]->pp) == 1)
		lpnlp = dq.pnlps[dq.lpnlpi], rpnlp = &epnls[1];
	    else
		lpnlp = &epnls[1], rpnlp = dq.pnlps[dq.lpnlpi];
	} else {
	    pnlp = trip->e[(ei + 1) % 3].pnl1p;
	    if (ccw(trip->e[ei].pnl0p->pp, pnlp->pp,
		    trip->e[ei].pnl1p->pp) == 1)
		lpnlp = trip->e[ei].pnl1p, rpnlp = trip->e[ei].pnl0p;
	    else
		lpnlp = trip->e[ei].pnl0p, rpnlp = trip->e[ei].pnl1p;
	}

	/* update deque */
	if (trii == ftrii) {
	    add2dq(2, lpnlp);
	    add2dq(1, rpnlp);
	} else {
	    if (dq.pnlps[dq.fpnlpi] != rpnlp
		&& dq.pnlps[dq.lpnlpi] != rpnlp) {
		/* add right point to deque */
		splitindex = finddqsplit(rpnlp);
		splitdq(2, splitindex);
		add2dq(1, rpnlp);
		/* if the split is behind the apex, then reset apex */
		if (splitindex > dq.apex)
		    dq.apex = splitindex;
	    } else {
		/* add left point to deque */
		splitindex = finddqsplit(lpnlp);
		splitdq(1, splitindex);
		add2dq(2, lpnlp);
		/* if the split is in front of the apex, then reset apex */
		if (splitindex < dq.apex)
		    dq.apex = splitindex;
	    }
	}
	trii = -1;
	for (ei = 0; ei < 3; ei++)
	    if (trip->e[ei].rtp && trip->e[ei].rtp->mark == 1) {
		trii = trip->e[ei].rtp - tris;
		break;
	    }
    }


    
    
	
    


    for (pi = 0, pnlp = &epnls[1]; pnlp; pnlp = pnlp->link)
	pi++;
    growops(pi);
    output->pn = pi;
    for (pi = pi - 1, pnlp = &epnls[1]; pnlp; pi--, pnlp = pnlp->link)
	ops[pi] = *pnlp->pp;
    output->ps = ops;

    return 0;
}

/* triangulate polygon */
static void triangulate(pointnlink_t ** pnlps, int pnln)
{
    int pnli, pnlip1, pnlip2;

	if (pnln > 3) 
	{
		for (pnli = 0; pnli < pnln; pnli++) 
		{
			pnlip1 = (pnli + 1) % pnln;
			pnlip2 = (pnli + 2) % pnln;
			if (isdiagonal(pnli, pnlip2, pnlps, pnln)) 
			{
				loadtriangle(pnlps[pnli], pnlps[pnlip1], pnlps[pnlip2]);
				for (pnli = pnlip1; pnli < pnln - 1; pnli++)
					pnlps[pnli] = pnlps[pnli + 1];
				triangulate(pnlps, pnln - 1);
				return;
			}
		}
		fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("triangulation failed"));
    } 
	else
		loadtriangle(pnlps[0], pnlps[1], pnlps[2]);
}

/* check if (i, i + 2) is a diagonal */
static int isdiagonal(int pnli, int pnlip2, pointnlink_t ** pnlps,
		      int pnln)
{
    int pnlip1, pnlim1, pnlj, pnljp1, res;

    /* neighborhood test */
    pnlip1 = (pnli + 1) % pnln;
    pnlim1 = (pnli + pnln - 1) % pnln;
    /* If P[pnli] is a convex vertex [ pnli+1 left of (pnli-1,pnli) ]. */
    if (ccw(pnlps[pnlim1]->pp, pnlps[pnli]->pp, pnlps[pnlip1]->pp) ==
	1)
	res =
	    (ccw(pnlps[pnli]->pp, pnlps[pnlip2]->pp, pnlps[pnlim1]->pp) ==
	     1)
	    && (ccw(pnlps[pnlip2]->pp, pnlps[pnli]->pp, pnlps[pnlip1]->pp)
		== 1);
    /* Assume (pnli - 1, pnli, pnli + 1) not collinear. */
    else
	res = (ccw(pnlps[pnli]->pp, pnlps[pnlip2]->pp,
		   pnlps[pnlip1]->pp) == 2);
    if (!res)
	return 0;

    /* check against all other edges */
    for (pnlj = 0; pnlj < pnln; pnlj++) {
	pnljp1 = (pnlj + 1) % pnln;
	if (!((pnlj == pnli) || (pnljp1 == pnli) ||
	      (pnlj == pnlip2) || (pnljp1 == pnlip2)))
	    if (intersects(pnlps[pnli]->pp, pnlps[pnlip2]->pp,
			   pnlps[pnlj]->pp, pnlps[pnljp1]->pp))
		return 0;
    }
    return ((!(0)));
}

static void loadtriangle(pointnlink_t * pnlap, pointnlink_t * pnlbp,
			 pointnlink_t * pnlcp)
{
    triangle_t *trip;
    int ei;

    /* make space */
    if (tril >= trin)
	growtris(trin + 20);
    trip = &tris[tril++];
    trip->mark = 0;
    trip->e[0].pnl0p = pnlap, trip->e[0].pnl1p = pnlbp, trip->e[0].rtp =
	NULL;
    trip->e[1].pnl0p = pnlbp, trip->e[1].pnl1p = pnlcp, trip->e[1].rtp =
	NULL;
    trip->e[2].pnl0p = pnlcp, trip->e[2].pnl1p = pnlap, trip->e[2].rtp =
	NULL;
    for (ei = 0; ei < 3; ei++)
	trip->e[ei].ltp = trip;
}

/* connect a pair of triangles at their common edge (if any) */
static void connecttris(int tri1, int tri2)
{
    triangle_t *tri1p, *tri2p;
    int ei, ej;

    for (ei = 0; ei < 3; ei++) {
	for (ej = 0; ej < 3; ej++) {
	    tri1p = &tris[tri1], tri2p = &tris[tri2];
	    if ((tri1p->e[ei].pnl0p->pp == tri2p->e[ej].pnl0p->pp &&
		 tri1p->e[ei].pnl1p->pp == tri2p->e[ej].pnl1p->pp) ||
		(tri1p->e[ei].pnl0p->pp == tri2p->e[ej].pnl1p->pp &&
		 tri1p->e[ei].pnl1p->pp == tri2p->e[ej].pnl0p->pp))
		tri1p->e[ei].rtp = tri2p, tri2p->e[ej].rtp = tri1p;
	}
    }
}

/* find and mark path from trii, to trij */
static int marktripath(int trii, int trij)
{
    int ei;

    if (tris[trii].mark)
	return 0;
    tris[trii].mark = 1;
    if (trii == trij)
	return ((!(0)));
    for (ei = 0; ei < 3; ei++)
	if (tris[trii].e[ei].rtp &&
	    marktripath(tris[trii].e[ei].rtp - tris, trij))
	    return ((!(0)));
    tris[trii].mark = 0;
    return 0;
}

/* add a new point to the deque, either front or back */
static void add2dq(int side, pointnlink_t * pnlp)
{
    if (side == 1) {
	if (dq.lpnlpi - dq.fpnlpi >= 0)
	    pnlp->link = dq.pnlps[dq.fpnlpi];	/* shortest path links */
	dq.fpnlpi--;
	dq.pnlps[dq.fpnlpi] = pnlp;
    } else {
	if (dq.lpnlpi - dq.fpnlpi >= 0)
	    pnlp->link = dq.pnlps[dq.lpnlpi];	/* shortest path links */
	dq.lpnlpi++;
	dq.pnlps[dq.lpnlpi] = pnlp;
    }
}

static void splitdq(int side, int index)
{
    if (side == 1)
	dq.lpnlpi = index;
    else
	dq.fpnlpi = index;
}

static int finddqsplit(pointnlink_t * pnlp)
{
    int index;

    for (index = dq.fpnlpi; index < dq.apex; index++)
	if (ccw(dq.pnlps[index + 1]->pp, dq.pnlps[index]->pp, pnlp->pp) ==
	    1)
	    return index;
    for (index = dq.lpnlpi; index > dq.apex; index--)
	if (ccw(dq.pnlps[index - 1]->pp, dq.pnlps[index]->pp, pnlp->pp) ==
	    2)
	    return index;
    return dq.apex;
}

/* ccw test: CCW, CW, or co-linear */
static int ccw(Ppoint_t * p1p, Ppoint_t * p2p, Ppoint_t * p3p)
{
    double d;

    d = ((p1p->y - p2p->y) * (p3p->x - p2p->x)) -
	((p3p->y - p2p->y) * (p1p->x - p2p->x));
    return (d > 0) ? 1 : ((d < 0) ? 2 : 3);
}

/* line to line intersection */
static int intersects(Ppoint_t * pap, Ppoint_t * pbp,
		      Ppoint_t * pcp, Ppoint_t * pdp)
{
    int ccw1, ccw2, ccw3, ccw4;

    if (ccw(pap, pbp, pcp) == 3 || ccw(pap, pbp, pdp) == 3 ||
	ccw(pcp, pdp, pap) == 3 || ccw(pcp, pdp, pbp) == 3) {
	if (between(pap, pbp, pcp) || between(pap, pbp, pdp) ||
	    between(pcp, pdp, pap) || between(pcp, pdp, pbp))
	    return ((!(0)));
    } else {
	ccw1 = (ccw(pap, pbp, pcp) == 1) ? 1 : 0;
	ccw2 = (ccw(pap, pbp, pdp) == 1) ? 1 : 0;
	ccw3 = (ccw(pcp, pdp, pap) == 1) ? 1 : 0;
	ccw4 = (ccw(pcp, pdp, pbp) == 1) ? 1 : 0;
	return (ccw1 ^ ccw2) && (ccw3 ^ ccw4);
    }
    return 0;
}

/* is pbp between pap and pcp */
static int between(Ppoint_t * pap, Ppoint_t * pbp, Ppoint_t * pcp)
{
    Ppoint_t p1, p2;

    p1.x = pbp->x - pap->x, p1.y = pbp->y - pap->y;
    p2.x = pcp->x - pap->x, p2.y = pcp->y - pap->y;
    if (ccw(pap, pbp, pcp) != 3)
	return 0;
    return (p2.x * p1.x + p2.y * p1.y >= 0) &&
	(p2.x * p2.x + p2.y * p2.y <= p1.x * p1.x + p1.y * p1.y);
}

static int pointintri(int trii, Ppoint_t * pp)
{
    int ei, sum;

    for (ei = 0, sum = 0; ei < 3; ei++)
	if (ccw(tris[trii].e[ei].pnl0p->pp,
		tris[trii].e[ei].pnl1p->pp, pp) != 2)
	    sum++;
    return (sum == 3 || sum == 0);
}

static void growpnls(int newpnln)
{
    if (newpnln <= pnln)
	return;
    if (!pnls) {
	if (!(pnls = (pointnlink_t *) malloc(sizeof (pointnlink_t) * newpnln))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc pnls"));
	    longjmp(jbuf,1);
	}
	if (!(pnlps = (pointnlink_t **) malloc(sizeof (pointnlink_t *) * newpnln))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc pnlps"));
	    longjmp(jbuf,1);
	}
    } else {
	if (!(pnls = (pointnlink_t *) realloc((void *) pnls,
					      sizeof (pointnlink_t) * newpnln))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc pnls"));
	    longjmp(jbuf,1);
	}
	if (!(pnlps = (pointnlink_t **) realloc((void *) pnlps,
						sizeof (pointnlink_t *) *
						newpnln))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc pnlps"));
	    longjmp(jbuf,1);
	}
    }
    pnln = newpnln;
}

static void growtris(int newtrin)
{
    if (newtrin <= trin)
	return;
    if (!tris) {
	if (!(tris = (triangle_t *) malloc(sizeof (triangle_t) * newtrin))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc tris"));
	    longjmp(jbuf,1);
	}
    } else {
	if (!(tris = (triangle_t *) realloc((void *) tris,
					    sizeof (triangle_t) * newtrin))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc tris"));
	    longjmp(jbuf,1);
	}
    }
    trin = newtrin;
}

static void growdq(int newdqn)
{
    if (newdqn <= dq.pnlpn)
	return;
    if (!dq.pnlps) {
	if (!
	    (dq.pnlps =
	     (pointnlink_t **) malloc(sizeof (pointnlink_t *) * newdqn))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc dq.pnls"));
	    longjmp(jbuf,1);
	}
    } else {
	if (!(dq.pnlps = (pointnlink_t **) realloc((void *) dq.pnlps,
						   sizeof (pointnlink_t *) *
						   newdqn))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc dq.pnls"));
	    longjmp(jbuf,1);
	}
    }
    dq.pnlpn = newdqn;
}

static void growops(int newopn)
{
    if (newopn <= opn)
	return;
    if (!ops) {
	if (!(ops = (Ppoint_t *) malloc(sizeof (Ppoint_t) * newopn))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc ops"));
	    longjmp(jbuf,1);
	}
    } else {
	if (!(ops = (Ppoint_t *) realloc((void *) ops,
					 sizeof (Ppoint_t) * newopn))) {
	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc ops"));
	    longjmp(jbuf,1);
	}
    }
    opn = newopn;
}
