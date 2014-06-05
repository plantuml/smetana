#line 1 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 1
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







#line 16 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2
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







#line 17 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\edges.h" 1
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





#line 21 "graphviz-2.38.0\\lib\\neatogen\\edges.h" 2

    typedef struct Edge {
	double a, b, c;		/* edge on line ax + by = c */
	Site *ep[2];		/* endpoints (vertices) of edge; initially NULL */
	Site *reg[2];		/* sites forming edge */
	int edgenbr;
    } Edge;




    extern double pxmin, pxmax, pymin, pymax;	/* clipping window */
    extern void edgeinit(void);
    extern void endpoint(Edge *, int, Site *);
    extern void clip_line(Edge * e);
    extern Edge *bisect(Site *, Site *);






#line 18 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\hedges.h" 1
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












    
    
	
	
	
    

    
    

    
    
    
    
    
    





#line 21 "graphviz-2.38.0\\lib\\neatogen\\hedges.h" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\edges.h" 1
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












    
	
	
	
	
    




    
    
    
    
    






#line 22 "graphviz-2.38.0\\lib\\neatogen\\hedges.h" 2

    typedef struct Halfedge {
	struct Halfedge *ELleft, *ELright;
	Edge *ELedge;
	int ELrefcnt;
	char ELpm;
	Site *vertex;
	double ystar;
	struct Halfedge *PQnext;
    } Halfedge;

    extern Halfedge *ELleftend, *ELrightend;

    extern void ELinitialize(void);
    extern void ELcleanup(void);
    extern int right_of(Halfedge *, Point *);
    extern Site *hintersect(Halfedge *, Halfedge *);
    extern Halfedge *HEcreate(Edge *, char);
    extern void ELinsert(Halfedge *, Halfedge *);
    extern Halfedge *ELleftbnd(Point *);
    extern void ELdelete(Halfedge *);
    extern Halfedge *ELleft(Halfedge *), *ELright(Halfedge *);
    extern Halfedge *ELleftbnd(Point *);
    extern Site *leftreg(Halfedge *), *rightreg(Halfedge *);






#line 19 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\heap.h" 1
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










#line 1 "graphviz-2.38.0\\lib\\neatogen\\hedges.h" 1
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













    
	
	
	
	
	
	
	
    

    

    
    
    
    
    
    
    
    
    
    
    






#line 21 "graphviz-2.38.0\\lib\\neatogen\\heap.h" 2

    extern void PQinitialize(void);
    extern void PQcleanup(void);
    extern Halfedge *PQextractmin(void);
    extern Point PQ_min(void);
    extern int PQempty(void);
    extern void PQdelete(Halfedge *);
    extern void PQinsert(Halfedge *, Site *, double);






#line 20 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2
#line 1 "graphviz-2.38.0\\lib\\neatogen\\voronoi.h" 1
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












    
    
	
	
	
    

    
    

    
    
    
    
    
    





#line 21 "graphviz-2.38.0\\lib\\neatogen\\voronoi.h" 2

    extern void voronoi(int, Site * (*)(void));







#line 21 "graphviz-2.38.0\\lib\\neatogen\\voronoi.c" 2


void voronoi(int triangulate, Site * (*nextsite) (void))
{
    Site *newsite, *bot, *top, *temp, *p;
    Site *v;
    Point newintstar;
    char pm;
    Halfedge *lbnd, *rbnd, *llbnd, *rrbnd, *bisector;
    Edge *e;

    edgeinit();
    siteinit();
    PQinitialize();
    bottomsite = (*nextsite) ();

    

    ELinitialize();

    newsite = (*nextsite) ();
    while (1) {
	if (!PQempty())
	    newintstar = PQ_min();

	if (newsite != (struct Site *) 0 && (PQempty()
						|| newsite->coord.y <
						newintstar.y
						|| (newsite->coord.y ==
						    newintstar.y
						    && newsite->coord.x <
						    newintstar.x))) {
	    /* new site is smallest */

	    

	    lbnd = ELleftbnd(&(newsite->coord));
	    rbnd = ELright(lbnd);
	    bot = rightreg(lbnd);
	    e = bisect(bot, newsite);
	    bisector = HEcreate(e, 0);
	    ELinsert(lbnd, bisector);
	    if ((p = hintersect(lbnd, bisector)) != (struct Site *) 0) {
		PQdelete(lbnd);
		PQinsert(lbnd, p, dist(p, newsite));
	    }
	    lbnd = bisector;
	    bisector = HEcreate(e, 1);
	    ELinsert(lbnd, bisector);
	    if ((p = hintersect(bisector, rbnd)) != (struct Site *) 0)
		PQinsert(bisector, p, dist(p, newsite));
	    newsite = (*nextsite) ();
	} else if (!PQempty()) {
	    /* intersection is smallest */
	    lbnd = PQextractmin();
	    llbnd = ELleft(lbnd);
	    rbnd = ELright(lbnd);
	    rrbnd = ELright(rbnd);
	    bot = leftreg(lbnd);
	    top = rightreg(rbnd);

	    

	    v = lbnd->vertex;
	    makevertex(v);
	    endpoint(lbnd->ELedge, lbnd->ELpm, v);
	    endpoint(rbnd->ELedge, rbnd->ELpm, v);
	    ELdelete(lbnd);
	    PQdelete(rbnd);
	    ELdelete(rbnd);
	    pm = 0;
	    if (bot->coord.y > top->coord.y) {
		temp = bot;
		bot = top;
		top = temp;
		pm = 1;
	    }
	    e = bisect(bot, top);
	    bisector = HEcreate(e, pm);
	    ELinsert(llbnd, bisector);
	    endpoint(e, 1 - pm, v);
	    deref(v);
	    if ((p = hintersect(llbnd, bisector)) != (struct Site *) 0) {
		PQdelete(llbnd);
		PQinsert(llbnd, p, dist(p, bot));
	    }
	    if ((p = hintersect(bisector, rrbnd)) != (struct Site *) 0) {
		PQinsert(bisector, p, dist(p, bot));
	    }
	} else
	    break;
    }

    for (lbnd = ELright(ELleftend); lbnd != ELrightend;
	 lbnd = ELright(lbnd)) {
	e = lbnd->ELedge;
	clip_line(e);

	

    }
}
