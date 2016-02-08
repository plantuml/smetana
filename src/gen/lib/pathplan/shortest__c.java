/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 *
 *
 *
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************
 *
 */
package gen.lib.pathplan;
import h.*;
import smetana.core.*;
import static smetana.core.Macro.*;
import static smetana.core.JUtils.*;
import static gen.lib.cdt.dtclose__c.*;
import static gen.lib.cdt.dtdisc__c.*;
import static gen.lib.cdt.dtextract__c.*;
import static gen.lib.cdt.dtflatten__c.*;
import static gen.lib.cdt.dthash__c.*;
import static gen.lib.cdt.dtlist__c.*;
import static gen.lib.cdt.dtmethod__c.*;
import static gen.lib.cdt.dtopen__c.*;
import static gen.lib.cdt.dtrenew__c.*;
import static gen.lib.cdt.dtrestore__c.*;
import static gen.lib.cdt.dtsize__c.*;
import static gen.lib.cdt.dtstat__c.*;
import static gen.lib.cdt.dtstrhash__c.*;
import static gen.lib.cdt.dttreeset__c.*;
import static gen.lib.cdt.dttree__c.*;
import static gen.lib.cdt.dtview__c.*;
import static gen.lib.cdt.dtwalk__c.*;
import static gen.lib.cgraph.agerror__c.*;
import static gen.lib.cgraph.agxbuf__c.*;
import static gen.lib.cgraph.apply__c.*;
import static gen.lib.cgraph.attr__c.*;
import static gen.lib.cgraph.cmpnd__c.*;
import static gen.lib.cgraph.edge__c.*;
import static gen.lib.cgraph.flatten__c.*;
import static gen.lib.cgraph.grammar__c.*;
import static gen.lib.cgraph.graph__c.*;
import static gen.lib.cgraph.id__c.*;
import static gen.lib.cgraph.imap__c.*;
import static gen.lib.cgraph.io__c.*;
import static gen.lib.cgraph.main__c.*;
import static gen.lib.cgraph.mem__c.*;
import static gen.lib.cgraph.node__c.*;
import static gen.lib.cgraph.obj__c.*;
import static gen.lib.cgraph.pend__c.*;
import static gen.lib.cgraph.rec__c.*;
import static gen.lib.cgraph.refstr__c.*;
import static gen.lib.cgraph.scan__c.*;
import static gen.lib.cgraph.subg__c.*;
import static gen.lib.cgraph.tester__c.*;
import static gen.lib.cgraph.utils__c.*;
import static gen.lib.cgraph.write__c.*;
import static gen.lib.cgraph.y_tab__c.*;
import static gen.lib.circogen.blockpath__c.*;
import static gen.lib.circogen.blocktree__c.*;
import static gen.lib.circogen.block__c.*;
import static gen.lib.circogen.circpos__c.*;
import static gen.lib.circogen.circularinit__c.*;
import static gen.lib.circogen.circular__c.*;
import static gen.lib.circogen.deglist__c.*;
import static gen.lib.circogen.edgelist__c.*;
import static gen.lib.circogen.nodelist__c.*;
import static gen.lib.circogen.nodeset__c.*;
import static gen.lib.common.args__c.*;
import static gen.lib.common.arrows__c.*;
import static gen.lib.common.colxlate__c.*;
import static gen.lib.common.ellipse__c.*;
import static gen.lib.common.emit__c.*;
import static gen.lib.common.geom__c.*;
import static gen.lib.common.globals__c.*;
import static gen.lib.common.htmllex__c.*;
import static gen.lib.common.htmlparse__c.*;
import static gen.lib.common.htmltable__c.*;
import static gen.lib.common.input__c.*;
import static gen.lib.common.intset__c.*;
import static gen.lib.common.labels__c.*;
import static gen.lib.common.memory__c.*;
import static gen.lib.common.ns__c.*;
import static gen.lib.common.output__c.*;
import static gen.lib.common.pointset__c.*;
import static gen.lib.common.postproc__c.*;
import static gen.lib.common.psusershape__c.*;
import static gen.lib.common.routespl__c.*;
import static gen.lib.common.shapes__c.*;
import static gen.lib.common.splines__c.*;
import static gen.lib.common.strcasecmp__c.*;
import static gen.lib.common.strncasecmp__c.*;
import static gen.lib.common.taper__c.*;
import static gen.lib.common.textspan__c.*;
import static gen.lib.common.timing__c.*;
import static gen.lib.common.utils__c.*;
import static gen.lib.common.y_tab__c.*;
import static gen.lib.dotgen.acyclic__c.*;
import static gen.lib.dotgen.aspect__c.*;
import static gen.lib.dotgen.class1__c.*;
import static gen.lib.dotgen.class2__c.*;
import static gen.lib.dotgen.cluster__c.*;
import static gen.lib.dotgen.compound__c.*;
import static gen.lib.dotgen.conc__c.*;
import static gen.lib.dotgen.decomp__c.*;
import static gen.lib.dotgen.dotinit__c.*;
import static gen.lib.dotgen.dotsplines__c.*;
import static gen.lib.dotgen.fastgr__c.*;
import static gen.lib.dotgen.flat__c.*;
import static gen.lib.dotgen.mincross__c.*;
import static gen.lib.dotgen.position__c.*;
import static gen.lib.dotgen.rank__c.*;
import static gen.lib.dotgen.sameport__c.*;
import static gen.lib.dotgen2.decomp__c.*;
import static gen.lib.dotgen2.dotinit__c.*;
import static gen.lib.dotgen2.groups__c.*;
import static gen.lib.dotgen2.level__c.*;
import static gen.lib.dotgen2.minc2__c.*;
import static gen.lib.dotgen2.minc_utils__c.*;
import static gen.lib.dotgen2.ns__c.*;
import static gen.lib.fdpgen.clusteredges__c.*;
import static gen.lib.fdpgen.comp__c.*;
import static gen.lib.fdpgen.dbg__c.*;
import static gen.lib.fdpgen.fdpinit__c.*;
import static gen.lib.fdpgen.grid__c.*;
import static gen.lib.fdpgen.layout__c.*;
import static gen.lib.fdpgen.tlayout__c.*;
import static gen.lib.fdpgen.xlayout__c.*;
import static gen.lib.gvc.gvbuffstderr__c.*;
import static gen.lib.gvc.gvconfig__c.*;
import static gen.lib.gvc.gvcontext__c.*;
import static gen.lib.gvc.gvc__c.*;
import static gen.lib.gvc.gvdevice__c.*;
import static gen.lib.gvc.gvevent__c.*;
import static gen.lib.gvc.gvjobs__c.*;
import static gen.lib.gvc.gvlayout__c.*;
import static gen.lib.gvc.gvloadimage__c.*;
import static gen.lib.gvc.gvplugin__c.*;
import static gen.lib.gvc.gvrender__c.*;
import static gen.lib.gvc.gvtextlayout__c.*;
import static gen.lib.gvc.gvusershape__c.*;
import static gen.lib.gvc.regex_win32__c.*;
import static gen.lib.label.index__c.*;
import static gen.lib.label.node__c.*;
import static gen.lib.label.nrtmain__c.*;
import static gen.lib.label.rectangle__c.*;
import static gen.lib.label.split_q__c.*;
import static gen.lib.label.xlabels__c.*;
import static gen.lib.ortho.fPQ__c.*;
import static gen.lib.ortho.maze__c.*;
import static gen.lib.ortho.ortho__c.*;
import static gen.lib.ortho.partition__c.*;
import static gen.lib.ortho.rawgraph__c.*;
import static gen.lib.ortho.sgraph__c.*;
import static gen.lib.ortho.trapezoid__c.*;
import static gen.lib.pack.ccomps__c.*;
import static gen.lib.pack.pack__c.*;
import static gen.lib.pack.ptest__c.*;
import static gen.lib.pathplan.cvt__c.*;
import static gen.lib.pathplan.inpoly__c.*;
import static gen.lib.pathplan.route__c.*;
import static gen.lib.pathplan.shortestpth__c.*;
import static gen.lib.pathplan.shortest__c.*;
import static gen.lib.pathplan.solvers__c.*;
import static gen.lib.pathplan.triang__c.*;
import static gen.lib.pathplan.util__c.*;
import static gen.lib.pathplan.visibility__c.*;
import static gen.lib.xdot.xdot__c.*;

public class shortest__c {
//1 baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


//1 7pb9zum2n4wlgil34lvh8i0ts
// typedef double COORD


//1 540u5gu9i0x1wzoxqqx5n2vwp
// static jmp_buf jbuf
private static jmp_buf jbuf = new jmp_buf();

//1 3gj35j1owzho1bj8qrr8j520a
// static pointnlink_t *pnls, **pnlps
private static pointnlink_t pnls;
private static __ptr__ pnlps;

//1 6r0oj01m6zabkua5f5x778wq6
// static int pnln, pnll
private static int pnln, pnll;

//1 aywrlzd2nea9kkv8kzuctk7pt
// static triangle_t *tris
private static __ptr__ tris;

//1 a6aizijrgkmhf8hoyeqj49b60
// static int trin, tril
private static int trin, tril;

//1 cc2hmcygbtg3adbwgkunssdhx
// static deque_t dq
private final static __struct__<deque_t> dq = __struct__.from(deque_t.class);

//1 3k2f2er3efsrl0210su710vf
// static Ppoint_t *ops
static private __ptr__ ops;

//1 68lm8qk1d212p1ngzu26gudjc
// static int opn
private static int opn;



//3 2gub5b19vo2qexn56nw23wage
// int Pshortestpath(Ppoly_t * polyp, Ppoint_t * eps, Ppolyline_t * output) 
public static int Pshortestpath(Ppoly_t polyp, __array__ eps, Ppoly_t output) {
ENTERING("2gub5b19vo2qexn56nw23wage","Pshortestpath");
try {
    int pi, minpi;
    double minx;
    final __struct__<pointf> p1 = __struct__.from(pointf.class), p2 = __struct__.from(pointf.class), p3 = __struct__.from(pointf.class);
    int trii, trij, ftrii, ltrii;
    int ei;
    final __array__  epnls = __array__.malloc(pointnlink_t.class, 2);
    pointnlink_t lpnlp=null, rpnlp=null, pnlp=null;
    triangle_t trip;
    int splitindex;
    if (setjmp(jbuf)!=0)
	return -2;
    /* make space */
    growpnls(polyp.getInt("pn"));
    pnll = 0;
    tril = 0;
    growdq(polyp.getInt("pn") * 2);
    dq.setInt("fpnlpi", dq.getInt("pnlpn") / 2);
    dq.setInt("lpnlpi", dq.getInt("fpnlpi") - 1);
    /* make sure polygon is CCW and load pnls array */
    for (pi = 0, minx = HUGE_VAL, minpi = -1; pi < polyp.getInt("pn"); pi++) {
	if (minx > polyp.getPtr("ps").plus(pi).getDouble("x"))
	    { minx = polyp.getPtr("ps").plus(pi).getDouble("x");
		minpi = pi; }
    }
    p2.____(polyp.getPtr("ps").plus(minpi));
    p1.____(polyp.getPtr("ps").plus(((minpi == 0) ? polyp.getInt("pn") - 1 : minpi - 1)));
    p3.____(polyp.getPtr("ps").plus(((minpi == polyp.getInt("pn") - 1) ? 0 : minpi + 1)));
    if (((p1.getDouble("x") == p2.getDouble("x") && p2.getDouble("x") == p3.getDouble("x")) && (p3.getDouble("y") > p2.getDouble("y"))) ||
	ccw(p1.amp(), p2.amp(), p3.amp()) != 1) {
	for (pi = polyp.getInt("pn") - 1; pi >= 0; pi--) {
	    if (pi < polyp.getInt("pn") - 1
		&& polyp.getPtr("ps").plus(pi).getDouble("x") == polyp.getPtr("ps").plus(pi+1).getDouble("x")
		&& polyp.getPtr("ps").plus(pi).getDouble("y") == polyp.getPtr("ps").plus(pi+1).getDouble("y"))
		continue;
	    pnls.plus(pnll).setPtr("pp", polyp.getPtr("ps").plus(pi));
	    pnls.plus(pnll).setPtr("link", pnls.plus(pnll % polyp.getInt("pn")));
	    pnlps.plus(pnll).setPtr(pnls.plus(pnll).getPtr());
	    pnll++;
	}
    } else {
UNSUPPORTED("6r16p93hkrjz2x5g64y5fvgp"); // 	for (pi = 0; pi < polyp->pn; pi++) {
UNSUPPORTED("ag73m5oix1rqdl22sblc6xe7n"); // 	    if (pi > 0 && polyp->ps[pi].x == polyp->ps[pi - 1].x &&
UNSUPPORTED("ve8lcg4wuejy1iamgezldd1l"); // 		polyp->ps[pi].y == polyp->ps[pi - 1].y)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("f1orneg1h1k54qv8qiymscdmu"); // 	    pnls[pnll].pp = &polyp->ps[pi];
UNSUPPORTED("c7iuzik6cedqibya39odsn8rs"); // 	    pnls[pnll].link = &pnls[pnll % polyp->pn];
UNSUPPORTED("263qphtd3ct9iq5g9ttrt3v8"); // 	    pnlps[pnll] = &pnls[pnll];
UNSUPPORTED("91ms6j3km9gat978l2eswlq29"); // 	    pnll++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
    /* generate list of triangles */
    triangulate(pnlps, pnll);
    /* connect all pairs of triangles that share an edge */
    for (trii = 0; trii < tril; trii++)
	for (trij = trii + 1; trij < tril; trij++)
	    connecttris(trii, trij);
    /* find first and last triangles */
    for (trii = 0; trii < tril; trii++)
	if (pointintri(trii, eps.plus(0).getStruct().amp()))
	    break;
    if (trii == tril) {
UNSUPPORTED("4ma3y8l4lmjcsw49kmsgknig6"); // 	fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("source point not in any triangle"));
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
    }
    ftrii = trii;
    for (trii = 0; trii < tril; trii++)
	if (pointintri(trii, eps.plus(1).getStruct().amp()))
	    break;
    if (trii == tril) {
UNSUPPORTED("qofj6tr7dq65r0b7a12fhakq"); // 	fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("destination point not in any triangle"));
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
    }
    ltrii = trii;
    /* mark the strip of triangles from eps[0] to eps[1] */
    if (N(marktripath(ftrii, ltrii))) {
	System.err.println("libpath/%s:%d: %s" + "graphviz-2.38.0\\lib\\pathplan\\shortest.c" + 26 + ("cannot find triangle path"));
	/* a straight line is better than failing */
	growops(2);
	output.setInt("pn", 2);
	ops.plus(0).setStruct(eps.plus(0).getStruct());
	ops.plus(1).setStruct(eps.plus(1).getStruct());
	output.setPtr("ps", ops);
	return 0;
    }
    /* if endpoints in same triangle, use a single line */
    if (ftrii == ltrii) {
UNSUPPORTED("2nnkwrdxg0ma2m482dqarlbz6"); // 	growops(2);
UNSUPPORTED("5penbn9ky80i7jw02belk2zoj"); // 	output->pn = 2;
UNSUPPORTED("8i925e1tnbqn909027lqcg3fi"); // 	ops[0] = eps[0], ops[1] = eps[1];
UNSUPPORTED("3rcg6c9s9nmostq9c3r5n6x4h"); // 	output->ps = ops;
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
    }
    /* build funnel and shortest path linked list (in add2dq) */
    epnls.plus(0).getStruct().setPtr("pp", eps.plus(0).asPtr());
    epnls.plus(0).getStruct().setPtr("link", null);
    epnls.plus(1).getStruct().setPtr("pp", eps.plus(1).asPtr());
    epnls.plus(1).getStruct().setPtr("link", null);
    add2dq(1, epnls.plus(0).asPtr());
    dq.setInt("apex", dq.getInt("fpnlpi"));
    trii = ftrii;
    while (trii != -1) {
	trip = (triangle_t) tris.plus(trii);
	trip.setInt("mark", 2);
	/* find the left and right points of the exiting edge */
	for (ei = 0; ei < 3; ei++)
	    if (trip.getArray("e").plus(ei).getStruct().getPtr("rtp")!=null &&
	      trip.getArray("e").plus(ei).getStruct().getPtr("rtp").getInt("mark") == 1)
		break;
	if (ei == 3) {		/* in last triangle */
	    if (ccw(eps.plus(1).asPtr(), dq.getPtr("pnlps").plus(dq.getInt("fpnlpi")).getPtr().getPtr("pp"),
		    dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).getPtr().getPtr("pp")) == 1)
		{
		lpnlp = (pointnlink_t) dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).getPtr();
		rpnlp = (pointnlink_t) epnls.plus(1).asPtr();
	    } else {
		lpnlp = (pointnlink_t) epnls.plus(1).asPtr();
		rpnlp = (pointnlink_t) dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).getPtr();
		}
	} else {
	    pnlp = (pointnlink_t) trip.getArray("e").plus((ei + 1) % 3).getStruct().getPtr("pnl1p");
	    if (ccw(trip.getArray("e").plus(ei).getStruct().getPtr("pnl0p").getPtr("pp"), pnlp.getPtr("pp"),
		    trip.getArray("e").plus(ei).getStruct().getPtr("pnl1p").getPtr("pp")) == 1)
UNSUPPORTED("2cii65lhw4wb8nyvjv702v7md"); // 		lpnlp = trip->e[ei].pnl1p, rpnlp = trip->e[ei].pnl0p;
	    else
		{
		  lpnlp = (pointnlink_t) trip.getArray("e").plus(ei).getStruct().getPtr("pnl0p");
		  rpnlp = (pointnlink_t) trip.getArray("e").plus(ei).getStruct().getPtr("pnl1p");
		}
	}
	/* update deque */
	if (trii == ftrii) {
	    add2dq(2, lpnlp);
	    add2dq(1, rpnlp);
	} else {
	    if (NEQ(dq.getPtr("pnlps").plus(dq.getInt("fpnlpi")).getPtr(), rpnlp)
		&& NEQ(dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).getPtr(), rpnlp)) {
		/* add right point to deque */
		splitindex = finddqsplit(rpnlp);
		splitdq(2, splitindex);
		add2dq(1, rpnlp);
		/* if the split is behind the apex, then reset apex */
		if (splitindex > dq.getInt("apex"))
		    dq.setInt("apex", splitindex);
	    } else {
		/* add left point to deque */
		splitindex = finddqsplit(lpnlp);
		splitdq(1, splitindex);
		add2dq(2, lpnlp);
		/* if the split is in front of the apex, then reset apex */
		if (splitindex < dq.getInt("apex"))
		    dq.setInt("apex", splitindex);
	    }
	}
	trii = -1;
	for (ei = 0; ei < 3; ei++)
	    if (trip.getArray("e").plus(ei).getStruct().getPtr("rtp")!=null && 
	      trip.getArray("e").plus(ei).getStruct().getPtr("rtp").getInt("mark") == 1) {
		trii = trip.getArray("e").plus(ei).getStruct().getPtr("rtp").minus(tris);
		break;
	    }
    }
    for (pi = 0, pnlp = (pointnlink_t) epnls.plus(1).asPtr(); pnlp!=null; pnlp = (pointnlink_t) pnlp.getPtr("link"))
	pi++;
    growops(pi);
    output.setInt("pn", pi);
    for (pi = pi - 1, pnlp = (pointnlink_t) epnls.plus(1).asPtr(); pnlp!=null; pi--, pnlp = (pointnlink_t) pnlp.getPtr("link"))
	ops.plus(pi).setPtr(pnlp.getPtr("pp"));
    output.setPtr("ps", ops);
    return 0;
} finally {
LEAVING("2gub5b19vo2qexn56nw23wage","Pshortestpath");
}
}




//3 73cr7m3mqvtuotpzrmaw2y8zm
// static void triangulate(pointnlink_t ** pnlps, int pnln) 
public static void triangulate(__ptr__ pnlps, int pnln) {
ENTERING("73cr7m3mqvtuotpzrmaw2y8zm","triangulate");
try {
    int pnli, pnlip1, pnlip2;
	if (pnln > 3) 
	{
		for (pnli = 0; pnli < pnln; pnli++) 
		{
			pnlip1 = (pnli + 1) % pnln;
			pnlip2 = (pnli + 2) % pnln;
			if (isdiagonal(pnli, pnlip2, pnlps, pnln)) 
			{
				loadtriangle(pnlps.plus(pnli).getPtr(), pnlps.plus(pnlip1).getPtr(), pnlps.plus(pnlip2).getPtr());
				for (pnli = pnlip1; pnli < pnln - 1; pnli++)
					pnlps.plus(pnli).setPtr(pnlps.plus(pnli + 1).getPtr());
				triangulate(pnlps, pnln - 1);
				return;
			}
		}
UNSUPPORTED("b7cubu75mkrcno7zj7e0t4dqk"); // 		fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("triangulation failed"));
    } 
	else
		loadtriangle(pnlps.plus(0).getPtr(), pnlps.plus(1).getPtr(), pnlps.plus(2).getPtr());
} finally {
LEAVING("73cr7m3mqvtuotpzrmaw2y8zm","triangulate");
}
}




//3 72of3cd7shtwokglxapw04oe9
// static int isdiagonal(int pnli, int pnlip2, pointnlink_t ** pnlps, 		      int pnln) 
public static boolean isdiagonal(int pnli, int pnlip2, __ptr__ pnlps, int pnln) {
ENTERING("72of3cd7shtwokglxapw04oe9","isdiagonal");
try {
    int pnlip1, pnlim1, pnlj, pnljp1;
    boolean res;
    /* neighborhood test */
    pnlip1 = (pnli + 1) % pnln;
    pnlim1 = (pnli + pnln - 1) % pnln;
    /* If P[pnli] is a convex vertex [ pnli+1 left of (pnli-1,pnli) ]. */
    if (ccw(pnlps.plus(pnlim1).getPtr("pp"), pnlps.plus(pnli).getPtr("pp"), pnlps.plus(pnlip1).getPtr("pp")) ==
	1)
	res =
	    (ccw(pnlps.plus(pnli).getPtr("pp"), pnlps.plus(pnlip2).getPtr("pp"), pnlps.plus(pnlim1).getPtr("pp")) ==
	     1)
	    && (ccw(pnlps.plus(pnlip2).getPtr("pp"), pnlps.plus(pnli).getPtr("pp"), pnlps.plus(pnlip1).getPtr("pp"))
		== 1);
    /* Assume (pnli - 1, pnli, pnli + 1) not collinear. */
    else
	res = (ccw(pnlps.plus(pnli).getPtr("pp"), pnlps.plus(pnlip2).getPtr("pp"),
		   pnlps.plus(pnlip1).getPtr("pp")) == 2);
    if (N(res))
	return false;
    /* check against all other edges */
    for (pnlj = 0; pnlj < pnln; pnlj++) {
	pnljp1 = (pnlj + 1) % pnln;
	if (N((pnlj == pnli) || (pnljp1 == pnli) ||
	      (pnlj == pnlip2) || (pnljp1 == pnlip2)))
	    if (intersects(pnlps.plus(pnli).getPtr("pp"), pnlps.plus(pnlip2).getPtr("pp"),
			   pnlps.plus(pnlj).getPtr("pp"), pnlps.plus(pnljp1).getPtr("pp")))
		return false;
    }
    return ((N(false)));
} finally {
LEAVING("72of3cd7shtwokglxapw04oe9","isdiagonal");
}
}




//3 7vf9jtj9i8rg0cxrstbqswuck
// static void loadtriangle(pointnlink_t * pnlap, pointnlink_t * pnlbp, 			 pointnlink_t * pnlcp) 
public static void loadtriangle(__ptr__ pnlap, __ptr__ pnlbp, __ptr__ pnlcp) {
ENTERING("7vf9jtj9i8rg0cxrstbqswuck","loadtriangle");
try {
    triangle_t trip;
    int ei;
    /* make space */
    if (tril >= trin)
	growtris(trin + 20);
    trip = (triangle_t) tris.plus(tril++);
    trip.setInt("mark", 0);
    trip.getArray("e").plus(0).getStruct().setPtr("pnl0p", pnlap);
    trip.getArray("e").plus(0).getStruct().setPtr("pnl1p", pnlbp);
    trip.getArray("e").plus(0).getStruct().setPtr("rtp", null);
    trip.getArray("e").plus(1).getStruct().setPtr("pnl0p", pnlbp);
    trip.getArray("e").plus(1).getStruct().setPtr("pnl1p", pnlcp);
    trip.getArray("e").plus(1).getStruct().setPtr("rtp", null);
    trip.getArray("e").plus(2).getStruct().setPtr("pnl0p", pnlcp);
    trip.getArray("e").plus(2).getStruct().setPtr("pnl1p", pnlap);
    trip.getArray("e").plus(2).getStruct().setPtr("rtp", null);
    for (ei = 0; ei < 3; ei++)
	trip.getArray("e").plus(ei).getStruct().setPtr("ltp", trip);
} finally {
LEAVING("7vf9jtj9i8rg0cxrstbqswuck","loadtriangle");
}
}




//3 6coujw0qksrgu5sxj0r39qm1u
// static void connecttris(int tri1, int tri2) 
public static void connecttris(int tri1, int tri2) {
ENTERING("6coujw0qksrgu5sxj0r39qm1u","connecttris");
try {
    triangle_t tri1p, tri2p;
    int ei, ej;
    for (ei = 0; ei < 3; ei++) {
	for (ej = 0; ej < 3; ej++) {
	    tri1p = (triangle_t) tris.plus(tri1);
	    tri2p = (triangle_t) tris.plus(tri2);
	    if ((EQ(tri1p.getArray("e").plus(ei).getStruct().getPtr("pnl0p").getPtr("pp"),
	    		tri2p.getArray("e").plus(ej).getStruct().getPtr("pnl0p").getPtr("pp")) &&
		 EQ(tri1p.getArray("e").plus(ei).getStruct().getPtr("pnl1p").getPtr("pp"),
		 		tri2p.getArray("e").plus(ej).getStruct().getPtr("pnl1p").getPtr("pp"))) ||
		(EQ(tri1p.getArray("e").plus(ei).getStruct().getPtr("pnl0p").getPtr("pp"),
				tri2p.getArray("e").plus(ej).getStruct().getPtr("pnl1p").getPtr("pp")) &&
		 EQ(tri1p.getArray("e").plus(ei).getStruct().getPtr("pnl1p").getPtr("pp"),
		 		tri2p.getArray("e").plus(ej).getStruct().getPtr("pnl0p").getPtr("pp"))))
		 {
		tri1p.getArray("e").plus(ei).getStruct().setPtr("rtp", tri2p);
		tri2p.getArray("e").plus(ej).getStruct().setPtr("rtp", tri1p);
		 }
	}
    }
} finally {
LEAVING("6coujw0qksrgu5sxj0r39qm1u","connecttris");
}
}




//3 3waxf5wy3mwt12wpg5hxg3o9c
// static int marktripath(int trii, int trij) 
public static boolean marktripath(int trii, int trij) {
ENTERING("3waxf5wy3mwt12wpg5hxg3o9c","marktripath");
try {
    int ei;
    if (tris.plus(trii).getBoolean("mark"))
	return false;
    tris.plus(trii).setInt("mark", 1);
    if (trii == trij)
	return ((!(false)));
    for (ei = 0; ei < 3; ei++)
	if (tris.plus(trii).getArray("e").plus(ei).getStruct().getPtr("rtp")!=null &&
	    marktripath(tris.plus(trii).getArray("e").plus(ei).getStruct().getPtr("rtp").minus(tris), trij))
	    return ((!(false)));
    tris.plus(trii).setInt("mark", 0);
    return false;
} finally {
LEAVING("3waxf5wy3mwt12wpg5hxg3o9c","marktripath");
}
}




//3 44szdl31mg8mt5qrfj70kb2sn
// static void add2dq(int side, pointnlink_t * pnlp) 
public static void add2dq(int side, __ptr__ pnlp) {
ENTERING("44szdl31mg8mt5qrfj70kb2sn","add2dq");
try {
    if (side == 1) {
	if (dq.getInt("lpnlpi") - dq.getInt("fpnlpi") >= 0)
	    pnlp.setPtr("link", dq.getPtr("pnlps").plus(dq.getInt("fpnlpi")).getPtr());
	    /* shortest path links */
	dq.setInt("fpnlpi", dq.getInt("fpnlpi")-1);
	dq.getPtr("pnlps").plus(dq.getInt("fpnlpi")).setPtr(pnlp);
    } else {
	if (dq.getInt("lpnlpi") - dq.getInt("fpnlpi") >= 0)
	    pnlp.setPtr("link", dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).getPtr());
	    /* shortest path links */
	dq.setInt("lpnlpi", dq.getInt("lpnlpi")+1);
	dq.getPtr("pnlps").plus(dq.getInt("lpnlpi")).setPtr(pnlp);
    }
} finally {
LEAVING("44szdl31mg8mt5qrfj70kb2sn","add2dq");
}
}




//3 572sssdz1se16w790xceiy5vr
// static void splitdq(int side, int index) 
public static void splitdq(int side, int index) {
ENTERING("572sssdz1se16w790xceiy5vr","splitdq");
try {
    if (side == 1)
	dq.setInt("lpnlpi", index);
    else
	dq.setInt("fpnlpi", index);
} finally {
LEAVING("572sssdz1se16w790xceiy5vr","splitdq");
}
}




//3 9dnrc8vqpffp5t3bmsackgqtl
// static int finddqsplit(pointnlink_t * pnlp) 
public static int finddqsplit(pointnlink_t pnlp) {
ENTERING("9dnrc8vqpffp5t3bmsackgqtl","finddqsplit");
try {
    int index;
    for (index = dq.getInt("fpnlpi"); index < dq.getInt("apex"); index++)
	if (ccw(dq.getPtr("pnlps").plus(index + 1).getPtr().getPtr("pp"), dq.getPtr("pnlps").plus(index).getPtr().getPtr("pp"), pnlp.getPtr("pp")) ==
	    1)
	    return index;
    for (index = dq.getInt("lpnlpi"); index > dq.getInt("apex"); index--)
	if (ccw(dq.getPtr("pnlps").plus(index - 1).getPtr().getPtr("pp"), dq.getPtr("pnlps").plus(index).getPtr().getPtr("pp"), pnlp.getPtr("pp")) ==
	    2)
	    return index;
    return dq.getInt("apex");
} finally {
LEAVING("9dnrc8vqpffp5t3bmsackgqtl","finddqsplit");
}
}




//3 72h03s8inxtto2ekvmuqjtj3d
// static int ccw(Ppoint_t * p1p, Ppoint_t * p2p, Ppoint_t * p3p) 
public static int ccw(__ptr__ p1p, __ptr__ p2p, __ptr__ p3p) {
ENTERING("72h03s8inxtto2ekvmuqjtj3d","ccw");
try {
    double d;
    d = ((p1p.getDouble("y") - p2p.getDouble("y")) * (p3p.getDouble("x") - p2p.getDouble("x"))) -
	((p3p.getDouble("y") - p2p.getDouble("y")) * (p1p.getDouble("x") - p2p.getDouble("x")));
    return (d > 0) ? 1 : ((d < 0) ? 2 : 3);
} finally {
LEAVING("72h03s8inxtto2ekvmuqjtj3d","ccw");
}
}




//3 22a9ajg9t8ovqsigk3tyu3rkd
// static int intersects(Ppoint_t * pap, Ppoint_t * pbp, 		      Ppoint_t * pcp, Ppoint_t * pdp) 
public static boolean intersects(__ptr__ pap, __ptr__ pbp, __ptr__ pcp, __ptr__ pdp) {
ENTERING("22a9ajg9t8ovqsigk3tyu3rkd","intersects");
try {
    int ccw1, ccw2, ccw3, ccw4;
    if (ccw(pap, pbp, pcp) == 3 || ccw(pap, pbp, pdp) == 3 ||
	ccw(pcp, pdp, pap) == 3 || ccw(pcp, pdp, pbp) == 3) {
	if (between(pap, pbp, pcp) || between(pap, pbp, pdp) ||
	    between(pcp, pdp, pap) || between(pcp, pdp, pbp))
	    return ((!(false)));
    } else {
	ccw1 = (ccw(pap, pbp, pcp) == 1) ? 1 : 0;
	ccw2 = (ccw(pap, pbp, pdp) == 1) ? 1 : 0;
	ccw3 = (ccw(pcp, pdp, pap) == 1) ? 1 : 0;
	ccw4 = (ccw(pcp, pdp, pbp) == 1) ? 1 : 0;
	return (ccw1 ^ ccw2)!=0 && (ccw3 ^ ccw4)!=0;
    }
    return false;
} finally {
LEAVING("22a9ajg9t8ovqsigk3tyu3rkd","intersects");
}
}




//3 uh5n18rzyevtb4cwpni70qpc
// static int between(Ppoint_t * pap, Ppoint_t * pbp, Ppoint_t * pcp) 
public static boolean between(__ptr__ pap, __ptr__ pbp, __ptr__ pcp) {
ENTERING("uh5n18rzyevtb4cwpni70qpc","between");
try {
    final __struct__<pointf> p1 = __struct__.from(pointf.class), p2 = __struct__.from(pointf.class);
    p1.setDouble("x", pbp.getDouble("x") - pap.getDouble("x"));
    p1.setDouble("y", pbp.getDouble("y") - pap.getDouble("y"));
    p2.setDouble("x", pcp.getDouble("x") - pap.getDouble("x"));
    p2.setDouble("y", pcp.getDouble("y") - pap.getDouble("y"));
    if (ccw(pap, pbp, pcp) != 3)
	return false;
    return (p2.getDouble("x") * p1.getDouble("x") + p2.getDouble("y") * p1.getDouble("y") >= 0) &&
	(p2.getDouble("x") * p2.getDouble("x") + p2.getDouble("y") * p2.getDouble("y") <= p1.getDouble("x") * p1.getDouble("x") + p1.getDouble("y") * p1.getDouble("y"));
} finally {
LEAVING("uh5n18rzyevtb4cwpni70qpc","between");
}
}




//3 zti1mzm2m7tr2xwnbf7e8u3d
// static int pointintri(int trii, Ppoint_t * pp) 
public static boolean pointintri(int trii, __ptr__ pp) {
ENTERING("zti1mzm2m7tr2xwnbf7e8u3d","pointintri");
try {
    int ei, sum;
    for (ei = 0, sum = 0; ei < 3; ei++)
	if (ccw(tris.plus(trii).getArray("e").plus(ei).getStruct().getPtr("pnl0p").getPtr("pp"),
		tris.plus(trii).getArray("e").plus(ei).getStruct().getPtr("pnl1p").getPtr("pp"), pp) != 2)
	    sum++;
    return (sum == 3 || sum == 0);
} finally {
LEAVING("zti1mzm2m7tr2xwnbf7e8u3d","pointintri");
}
}




//3 85wstb60jkjd0kbh9tyninm4h
// static void growpnls(int newpnln) 
public static void growpnls(int newpnln) {
ENTERING("85wstb60jkjd0kbh9tyninm4h","growpnls");
try {
    if (newpnln <= pnln)
	return;
    if (N(pnls)) {
	if (N(pnls = (pointnlink_t) Memory.malloc(sizeof (pointnlink_t.class,  newpnln)))) {
UNSUPPORTED("9zyfc4bjg3i6rrna9vqf8doys"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc pnls"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
	}
	if (N(pnlps = Memory.malloc(sizeof_starstar_empty(pointnlink_t.class, newpnln)))) {
UNSUPPORTED("1etar0wd2cbbvqo4jnmbvjiz4"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc pnlps"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
	}
    } else {
UNSUPPORTED("bnqinq4dd505idzzp038yicrm"); // 	if (!(pnls = (pointnlink_t *) realloc((void *) pnls,
UNSUPPORTED("3dad6m30m7smoxxthgi67rrca"); // 					      sizeof (pointnlink_t) * newpnln))) {
UNSUPPORTED("105nogpkt0qqut0yu4alvkk1u"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc pnls"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("9ttkrsybunc8ar5of48y4z2ua"); // 	if (!(pnlps = (pointnlink_t **) realloc((void *) pnlps,
UNSUPPORTED("ay3z21yx56wzulyzo285nvjc3"); // 						sizeof (pointnlink_t *) *
UNSUPPORTED("ddqiz9aaluzho6azzkpo9elmk"); // 						newpnln))) {
UNSUPPORTED("be84alh84ub40x4um989aj20d"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc pnlps"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
    pnln = newpnln;
} finally {
LEAVING("85wstb60jkjd0kbh9tyninm4h","growpnls");
}
}




//3 c5q8ult6w26jppe5ifzgcoq82
// static void growtris(int newtrin) 
public static void growtris(int newtrin) {
ENTERING("c5q8ult6w26jppe5ifzgcoq82","growtris");
try {
    if (newtrin <= trin)
	return;
    if (N(tris)) {
	if (N(tris = Memory.malloc(sizeof(triangle_t.class, newtrin)))) {
UNSUPPORTED("5782e28cjpaa3dpf8up4zmtq7"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc tris"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
	}
    } else {
UNSUPPORTED("5s57uida8ul0337fx4es83903"); // 	if (!(tris = (triangle_t *) realloc((void *) tris,
UNSUPPORTED("8n7cq5nylvl5v1n4c2t00oiak"); // 					    sizeof (triangle_t) * newtrin))) {
UNSUPPORTED("d3fgu54pn5tydfhn7z73v73ra"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc tris"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
    trin = newtrin;
} finally {
LEAVING("c5q8ult6w26jppe5ifzgcoq82","growtris");
}
}




//3 bzym9u6dtatii1vp4hcmofc80
// static void growdq(int newdqn) 
public static void growdq(int newdqn) {
ENTERING("bzym9u6dtatii1vp4hcmofc80","growdq");
try {
    if (newdqn <= dq.getInt("pnlpn"))
	return;
    if (N(dq.getPtr("pnlps"))) {
	if (N
	    (dq.setPtr("pnlps",
	     (__ptr__) Memory.malloc(sizeof_starstar_empty(pointnlink_t.class, newdqn))))) {
UNSUPPORTED("88fwpb40wz9jc8jiz7u032s4t"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc dq.pnls"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
	}
    } else {
UNSUPPORTED("1lqt1bq6n68aajebcq04qnxi9"); // 	if (!(dq.pnlps = (pointnlink_t **) realloc((void *) dq.pnlps,
UNSUPPORTED("2rez1kpi8lahpe65p73p75bwj"); // 						   sizeof (pointnlink_t *) *
UNSUPPORTED("3jangvz57cahcu1m72u3ewng4"); // 						   newdqn))) {
UNSUPPORTED("exqx4ck7h15m8whgip6xpnhoo"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc dq.pnls"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
    dq.setInt("pnlpn", newdqn);
} finally {
LEAVING("bzym9u6dtatii1vp4hcmofc80","growdq");
}
}




//3 d7vtt8xqxbdnx9kwtt1zzof75
// static void growops(int newopn) 
public static void growops(int newopn) {
ENTERING("d7vtt8xqxbdnx9kwtt1zzof75","growops");
try {
    if (newopn <= opn)
	return;
    if (N(ops)) {
	if (N(ops = Memory.malloc(sizeof(pointf.class, newopn)))) {
UNSUPPORTED("7wxgcgah7iy6vetj5yszoq4k4"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot malloc ops"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
	}
    } else {
UNSUPPORTED("bswlt9pdv0ehbbpvwe9j38ui"); // 	if (!(ops = (Ppoint_t *) realloc((void *) ops,
UNSUPPORTED("ybqfoclgvol50dj2nu0k6n3o"); // 					 sizeof (Ppoint_t) * newopn))) {
UNSUPPORTED("7azrdo5s3kc44taqmtmeu1s33"); // 	    fprintf (stderr, "libpath/%s:%d: %s\n", "graphviz-2.38.0\\lib\\pathplan\\shortest.c", 26, ("cannot realloc ops"));
UNSUPPORTED("1r6uhbnmxv8c6msnscw07w0qx"); // 	    longjmp(jbuf,1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
    opn = newopn;
} finally {
LEAVING("d7vtt8xqxbdnx9kwtt1zzof75","growops");
}
}


}
