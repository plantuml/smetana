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

public class shortestpth__c {
//1 baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


//1 7pb9zum2n4wlgil34lvh8i0ts
// typedef double COORD


//1 e75el5ykqd72ikokwkl7j2epc
// typedef COORD **array2


//1 4lqn82dcexmb1ujfx7ciwkq7t
// static COORD unseen = (double) INT_MAX




//3 3vmsnhxv064fhv23juvb3901f
// int *shortestPath(int root, int target, int V, array2 wadj) 
public static Object shortestPath(Object... arg) {
UNSUPPORTED("ck9i1aidj3wocmwgkt8103ov9"); // int *shortestPath(int root, int target, int V, array2 wadj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7q38vtznktnwi60z79t1yl7kn"); //     int *dad;
UNSUPPORTED("3n8lsf3bhkta5dw01y6dosbhw"); //     COORD *vl;
UNSUPPORTED("emjv9wq86wxaz1mkis592qedk"); //     COORD *val;
UNSUPPORTED("985nf8jew0zg19ydmlmarwyl1"); //     int min;
UNSUPPORTED("5tszi7ot461b5xrq7t6i2p9jw"); //     int k, t;
UNSUPPORTED("8lhpkwmemj4ejagiby4wce1tp"); //     /* allocate arrays */
UNSUPPORTED("70ahd60yay9ycxlgxj1zuyqwk"); //     dad = (int *) malloc(V * sizeof(int));
UNSUPPORTED("cwcxxkaw0opazqbubfd67ylkw"); //     vl = (COORD *) malloc((V + 1) * sizeof(COORD));	/* One extra for sentinel */
UNSUPPORTED("30bnpu1p596ets2fp9d9fcuuo"); //     val = vl + 1;
UNSUPPORTED("6usgmh9di07cghsmczuausuqv"); //     /* initialize arrays */
UNSUPPORTED("7s35obmd4mmmswain6cq6kjyz"); //     for (k = 0; k < V; k++) {
UNSUPPORTED("9g1fv9lo3mqgozp0hgspk0jfx"); // 	dad[k] = -1;
UNSUPPORTED("3dfr2o54vzdz7ow35rvkkupwp"); // 	val[k] = -unseen;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6vvn9wwyfshecuati4wkh0hb1"); //     val[-1] = -(unseen + (COORD) 1);	/* Set sentinel */
UNSUPPORTED("ail1ie6r4omx0srfndd7uhkx8"); //     min = root;
UNSUPPORTED("8iguu5odqkwyske4dcuz2zh5c"); //     /* use (min >= 0) to fill entire tree */
UNSUPPORTED("3b9mo25ltl9ubqm9ptv305emr"); //     while (min != target) {
UNSUPPORTED("37uwanwupwkgvkiatkocsnwmi"); // 	k = min;
UNSUPPORTED("2yk23r7ym8txau8t7w94um5l9"); // 	val[k] *= -1;
UNSUPPORTED("d8r99m4cpfcmbygzpwrb87waf"); // 	min = -1;
UNSUPPORTED("99ykmzy96436vip14lubfa2jo"); // 	if (val[k] == unseen)
UNSUPPORTED("9vb74y52jxvq4iptd1w4dewnu"); // 	    val[k] = 0;
UNSUPPORTED("45pfcyfo86ei9srti6g0iz6xo"); // 	for (t = 0; t < V; t++) {
UNSUPPORTED("didw0ewjf6uo68oewapzly1rv"); // 	    if (val[t] < 0) {
UNSUPPORTED("ekeykiipkt1z2a3sn2ilt5gx7"); // 		COORD newpri;
UNSUPPORTED("bczxeah6ns9u23ey094g25kjz"); // 		COORD wkt;
UNSUPPORTED("cctfdc4m6tunpeulyd30cbdma"); // 		/* Use lower triangle */
UNSUPPORTED("akz9x35nrpcyklhz1a227a4xh"); // 		if (k >= t)
UNSUPPORTED("6cx7tblgrev9yzb4ppafglzh7"); // 		    wkt = wadj[k][t];
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("bbx44cas4y4rgf8fnytgoavog"); // 		    wkt = wadj[t][k];
UNSUPPORTED("2p64h5oxifdj0iau4zuiebitc"); // 		newpri = -(val[k] + wkt);
UNSUPPORTED("1skepgmjhmtk882tbnh0ny10o"); // 		if ((wkt != 0) && (val[t] < newpri)) {
UNSUPPORTED("73wirchpqpajql6a751nimkyu"); // 		    val[t] = newpri;
UNSUPPORTED("4hhrf0py8taqfmqeg3uvrx081"); // 		    dad[t] = k;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("98nv5m3wkh33gdi3z4vns4n4k"); // 		if (val[t] > val[min])
UNSUPPORTED("cpb83eu6rulsmbhc2rwsi9i5l"); // 		    min = t;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("yxn5pc6i3jmimfvzmmhfotak"); //     free(vl);
UNSUPPORTED("60tomuwdovbmgh94zzb3yeqib"); //     return dad;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 eb1kiq1ildiyme0qn3xszjyvk
// int *makePath(Ppoint_t p, int pp, COORD * pvis, 	      Ppoint_t q, int qp, COORD * qvis, vconfig_t * conf) 
public static Object makePath(Object... arg) {
UNSUPPORTED("2jth0bos9lrgk2xi5083p5rvp"); // int *makePath(Ppoint_t p, int pp, COORD * pvis,
UNSUPPORTED("a6dn81zxyfp9ydvajebmx15wt"); // 	      Ppoint_t q, int qp, COORD * qvis, vconfig_t * conf)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9e683sch2jealt2ckz48v9f0j"); //     int V = conf->N;
UNSUPPORTED("5ykvw66ec1v4dm5wm0ujsfgt9"); //     if (directVis(p, pp, q, qp, conf)) {
UNSUPPORTED("8y9o9xskc3crv3uecpyrsdakg"); // 	int *dad = (int *) malloc(sizeof(int) * (V + 2));
UNSUPPORTED("7oo70ckt9z1mf09uljyji5zud"); // 	dad[V] = V + 1;
UNSUPPORTED("3akorfrpmzhjtlnjmmos6z20q"); // 	dad[V + 1] = -1;
UNSUPPORTED("7x27015v5wfafitei6hpx0rii"); // 	return dad;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("946fxixcelejjif01eiioqduy"); // 	array2 wadj = conf->vis;
UNSUPPORTED("5ynkls19r2ylvtzz36h6vjy0t"); // 	wadj[V] = qvis;
UNSUPPORTED("a8gy96zl4x1lwid18nfp48pbm"); // 	wadj[V + 1] = pvis;
UNSUPPORTED("1fm1wr69gee2idjkv025ovvwh"); // 	return (shortestPath(V + 1, V, V + 2, wadj));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
