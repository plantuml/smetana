#line 1 "graphviz-2.38.0\\lib\\neatogen\\site.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\neatogen\\mem.h" 1
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














    /* Support for freelists */

    typedef struct freelist {
	struct freenode *head;	/* List of free nodes */
	struct freeblock *blocklist;	/* List of malloced blocks */
	int nodesize;		/* Size of node */
    } Freelist;

    extern void *getfree(Freelist *);
    extern void freeinit(Freelist *, int);
    extern void makefree(void *, Freelist *);







#line 16 "graphviz-2.38.0\\lib\\neatogen\\site.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\site.h" 1
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










#line 1 "graphviz-2.38.0\\lib\\neatogen\\geometry.h" 1
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











    

    typedef struct Point {
	double x, y;
    } Point;


    extern Point origin;

    extern double xmin, xmax, ymin, ymax;	/* extreme x,y values of sites */
    extern double deltax, deltay;	/* xmax - xmin, ymax - ymin */

    extern int nsites;		/* Number of sites */
    extern int sqrt_nsites;

    extern void geominit(void);
    extern double dist_2(Point *, Point *);	/* Distance squared between two points */
    extern void subpt(Point * a, Point b, Point c);
    extern void addpt(Point * a, Point b, Point c);
    extern double area_2(Point a, Point b, Point c);
    extern int leftOf(Point a, Point b, Point c);
    extern int intersection(Point a, Point b, Point c, Point d, Point * p);







#line 21 "graphviz-2.38.0\\lib\\neatogen\\site.h" 2

    /* Sites are also used as vertices on line segments */
    typedef struct Site {
	Point coord;
	int sitenbr;
	int refcnt;
    } Site;

    extern int siteidx;
    extern Site *bottomsite;

    extern void siteinit(void);
    extern Site *getsite(void);
    extern double dist(Site *, Site *);	/* Distance between two sites */
    extern void deref(Site *);	/* Increment refcnt of site  */
    extern void ref(Site *);	/* Decrement refcnt of site  */
    extern void makevertex(Site *);	/* Transform a site into a vertex */





#line 17 "graphviz-2.38.0\\lib\\neatogen\\site.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\site.c" 1


int siteidx;
Site *bottomsite;

static Freelist sfl;
static int nvertices;

void siteinit()
{
    /* double sn; */

    freeinit(&sfl, sizeof(Site));
    nvertices = 0;
    /* sn = nsites+4; */
    /* sqrt_nsites = sqrt(sn); */
}


Site *getsite()
{
    return ((Site *) getfree(&sfl));
}

double dist(Site * s, Site * t)
{
    double ans;
    double dx, dy;

    dx = s->coord.x - t->coord.x;
    dy = s->coord.y - t->coord.y;
    ans = sqrt(dx * dx + dy * dy);
    return ans;
}


void makevertex(Site * v)
{
    v->sitenbr = nvertices;
    nvertices += 1;

    

}


void deref(Site * v)
{
    v->refcnt -= 1;
    if (v->refcnt == 0)
	makefree(v, &sfl);
}

void ref(Site * v)
{
    v->refcnt += 1;
}
