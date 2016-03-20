/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program:
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
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package gen.lib.cgraph;
import h.*;
import smetana.core.*;
import static smetana.core.Macro.*;
import static smetana.core.JUtils.*;
import static smetana.core.JUtilsDebug.*;
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

public class subg__c {
//1 9k44uhd5foylaeoekf3llonjq
// extern Dtmethod_t* 	Dtset


//1 1ahfywsmzcpcig2oxm7pt9ihj
// extern Dtmethod_t* 	Dtbag


//1 anhghfj3k7dmkudy2n7rvt31v
// extern Dtmethod_t* 	Dtoset


//1 5l6oj1ux946zjwvir94ykejbc
// extern Dtmethod_t* 	Dtobag


//1 2wtf222ak6cui8cfjnw6w377z
// extern Dtmethod_t*	Dtlist


//1 d1s1s6ibtcsmst88e3057u9r7
// extern Dtmethod_t*	Dtstack


//1 axa7mflo824p6fspjn1rdk0mt
// extern Dtmethod_t*	Dtqueue


//1 ega812utobm4xx9oa9w9ayij6
// extern Dtmethod_t*	Dtdeque


//1 cyfr996ur43045jv1tjbelzmj
// extern Dtmethod_t*	Dtorder


//1 wlofoiftbjgrrabzb2brkycg
// extern Dtmethod_t*	Dttree


//1 12bds94t7voj7ulwpcvgf6agr
// extern Dtmethod_t*	Dthash


//1 9lqknzty480cy7zsubmabkk8h
// extern Dtmethod_t	_Dttree


//1 bvn6zkbcp8vjdhkccqo1xrkrb
// extern Dtmethod_t	_Dthash


//1 9lidhtd6nsmmv3e7vjv9e10gw
// extern Dtmethod_t	_Dtlist


//1 34ujfamjxo7xn89u90oh2k6f8
// extern Dtmethod_t	_Dtqueue


//1 3jy4aceckzkdv950h89p4wjc8
// extern Dtmethod_t	_Dtstack


//1 8dfqgf3u1v830qzcjqh9o8ha7
// extern Agmemdisc_t AgMemDisc


//1 18k2oh2t6llfsdc5x0wlcnby8
// extern Agiddisc_t AgIdDisc


//1 a4r7hi80gdxtsv4hdoqpyiivn
// extern Agiodisc_t AgIoDisc


//1 bnzt5syjb7mgeru19114vd6xx
// extern Agdisc_t AgDefaultDisc


//1 35y2gbegsdjilegaribes00mg
// extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,     Agstrictundirected


//1 c2rygslq6bcuka3awmvy2b3ow
// typedef Agsubnode_t	Agnoderef_t


//1 xam6yv0dcsx57dtg44igpbzn
// typedef Dtlink_t	Agedgeref_t


//1 6ayavpu39aihwyojkx093pcy3
// extern Agraph_t *Ag_G_global


//1 871mxtg9l6ffpxdl9kniwusf7
// extern char *AgDataRecName


//1 c0o2kmml0tn6hftuwo0u4shwd
// extern Dtdisc_t Ag_subnode_id_disc


//1 8k15pyu256unm2kpd9zf5pf7k
// extern Dtdisc_t Ag_subnode_seq_disc


//1 e3d820y06gpeusn6atgmj8bzd
// extern Dtdisc_t Ag_mainedge_id_disc


//1 cbr0772spix9h1aw7h5v7dv9j
// extern Dtdisc_t Ag_subedge_id_disc


//1 akd0c3v0j7m2npxcb9acit1fa
// extern Dtdisc_t Ag_mainedge_seq_disc


//1 12d8la07351ww7vwfzucjst8m
// extern Dtdisc_t Ag_subedge_seq_disc


//1 29eokk7v88e62g8o6lizmo967
// extern Dtdisc_t Ag_subgraph_id_disc


//1 4xd9cbgy6hk5g6nhjcbpzkx14
// extern Agcbdisc_t AgAttrdisc




//3 11ezyrsjsotjz9b3cyvb4ie8p
// static Agraph_t *agfindsubg_by_id(Agraph_t * g, unsigned long id) 
public static Agraph_s agfindsubg_by_id(Agraph_s g, int id) {
ENTERING("11ezyrsjsotjz9b3cyvb4ie8p","agfindsubg_by_id");
try {
    final __struct__<Agraph_s> template = __struct__.from(Agraph_s.class);
    agdtdisc(g, (_dt_s) g.getPtr("g_dict"), Z._().Ag_subgraph_id_disc.amp());
    AGID(template.amp(), id);
    return (Agraph_s) g.getPtr("g_dict").castTo(_dt_s.class).call("searchf", g.getPtr("g_dict"), template.amp(), 0000004);
} finally {
LEAVING("11ezyrsjsotjz9b3cyvb4ie8p","agfindsubg_by_id");
}
}




//3 44saycxbfbr9lou0itlyewkb4
// static Agraph_t *localsubg(Agraph_t * g, unsigned long id) 
public static Agraph_s localsubg(Agraph_s g, int id) {
ENTERING("44saycxbfbr9lou0itlyewkb4","localsubg");
try {
    Agraph_s subg;
    subg = agfindsubg_by_id(g, id);
    if (subg!=null)
	return subg;
    subg = (Agraph_s) agalloc(g, sizeof(Agraph_s.class));
    subg.setPtr("clos", g.getPtr("clos"));
    subg.setStruct("desc", g.getStruct("desc"));
    subg.getStruct("desc").setBoolean("maingraph", false);
    subg.setPtr("parent", g);
    subg.setPtr("root", g.getPtr("root"));
    AGID(subg, id);
    return agopen1(subg);
} finally {
LEAVING("44saycxbfbr9lou0itlyewkb4","localsubg");
}
}




//3 6wqxmivgp34bobzqacmsj7lcv
// Agraph_t *agidsubg(Agraph_t * g, unsigned long id, int cflag) 
public static Object agidsubg(Object... arg) {
UNSUPPORTED("9vhen1flll6k35g72uuroky0z"); // Agraph_t *agidsubg(Agraph_t * g, unsigned long id, int cflag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c3tourf5k7groqyh71yjd5xec"); //     Agraph_t *subg;
UNSUPPORTED("elpselocwvpfk3o27nejqo6dl"); //     subg = agfindsubg_by_id(g, id);
UNSUPPORTED("cf9t4fxh9z5rmv58441ne0ysa"); //     if ((subg == ((Agraph_t*)0)) && cflag && agallocid(g, AGRAPH, id))
UNSUPPORTED("ecrqdk8b7debftn6d8bbmh0s4"); // 	subg = localsubg(g, id);
UNSUPPORTED("17jmp11l2jzc1v9qpaqkzkauj"); //     return subg;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a24jd4r2sdyb4lb2hyababrda
// Agraph_t *agsubg(Agraph_t * g, char *name, int cflag) 
public static Agraph_s agsubg(Agraph_s g, CString name, boolean cflag) {
ENTERING("a24jd4r2sdyb4lb2hyababrda","agsubg");
try {
    int id[] = new int[]{0};
    Agraph_s subg;
    if (name!=null && agmapnametoid(g, AGRAPH, name, id, false)!=0) {
	/* might already exist */
	if ((subg = agfindsubg_by_id(g, id[0]))!=null)
	    return subg;
    }
    if (cflag && agmapnametoid(g, AGRAPH, name, id, (N(false)))!=0) {	/* reserve id */
	subg = localsubg(g, id[0]);
	agregister(g, AGRAPH, subg);
	return subg;
    }
    return null;
} finally {
LEAVING("a24jd4r2sdyb4lb2hyababrda","agsubg");
}
}




//3 51eksrs0lhkgohunejlpwyc4k
// Agraph_t *agfstsubg(Agraph_t * g) 
public static Agraph_s agfstsubg(Agraph_s g) {
ENTERING("51eksrs0lhkgohunejlpwyc4k","agfstsubg");
try {
	__ptr__ tmp = (__ptr__)g.getPtr("g_dict").castTo(_dt_s.class).call("searchf", g.getPtr("g_dict"),null,0000200);
	if (tmp!=null) tmp = tmp.castTo(Agraph_s.class);
	return (Agraph_s) tmp;
} finally {
LEAVING("51eksrs0lhkgohunejlpwyc4k","agfstsubg");
}
}




//3 85c1qisrein0tzm2regoe61t
// Agraph_t *agnxtsubg(Agraph_t * subg) 
public static Agraph_s agnxtsubg(Agraph_s subg) {
ENTERING("85c1qisrein0tzm2regoe61t","agnxtsubg");
try {
    Agraph_s g;
    g = agparent(subg);
    return g!=null ? (Agraph_s) g.getPtr("g_dict").castTo(_dt_s.class).call("searchf", g.getPtr("g_dict"), subg, 0000010) : null;
} finally {
LEAVING("85c1qisrein0tzm2regoe61t","agnxtsubg");
}
}




//3 7kbp6j03hd7u6nnlivi0vt3ja
// Agraph_t *agparent(Agraph_t * g) 
public static Agraph_s agparent(Agraph_s g) {
ENTERING("7kbp6j03hd7u6nnlivi0vt3ja","agparent");
try {
	return (Agraph_s) g.getPtr("parent");
} finally {
LEAVING("7kbp6j03hd7u6nnlivi0vt3ja","agparent");
}
}




//3 37trxrsv69a3pl08f5awwj3tq
// long agdelsubg(Agraph_t * g, Agraph_t * subg) 
public static Object agdelsubg(Object... arg) {
UNSUPPORTED("bjcimcpi0qag1hc37no67mct5"); // long agdelsubg(Agraph_t * g, Agraph_t * subg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dugmh24ptzgxuj3204p7n39m4"); //     return (long) (*(((Dt_t*)(g->g_dict))->searchf))((g->g_dict),(void*)(subg),0000002);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
