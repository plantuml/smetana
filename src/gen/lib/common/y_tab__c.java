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
package gen.lib.common;
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

public class y_tab__c {
//1 2digov3edok6d5srhgtlmrycs
// extern lt_symlist_t lt_preloaded_symbols[]


//1 baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


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


//1 nye6dsi1twkbddwo9iffca1j
// extern char *Version


//1 65mu6k7h7lb7bx14jpiw7iyxr
// extern char **Files


//1 2rpjdzsdyrvomf00zcs3u3dyn
// extern const char **Lib


//1 6d2f111lntd2rsdt4gswh5909
// extern char *CmdName


//1 a0ltq04fpeg83soa05a2fkwb2
// extern char *specificFlags


//1 1uv30qeqq2jh6uznlr4dziv0y
// extern char *specificItems


//1 7i4hkvngxe3x7lmg5h6b3t9g3
// extern char *Gvfilepath


//1 9jp96pa73kseya3w6sulxzok6
// extern char *Gvimagepath


//1 40ylumfu7mrvawwf4v2asvtwk
// extern unsigned char Verbose


//1 93st8awjy1z0h07n28qycbaka
// extern unsigned char Reduce


//1 f2vs67ts992erf8onwfglurzp
// extern int MemTest


//1 c6f8whijgjwwagjigmxlwz3gb
// extern char *HTTPServerEnVar


//1 cp4hzj7p87m7arw776d3bt7aj
// extern char *Output_file_name


//1 a3rqagofsgraie6mx0krzkgsy
// extern int graphviz_errors


//1 5up05203r4kxvjn1m4njcgq5x
// extern int Nop


//1 umig46cco431x14b3kosde2t
// extern double PSinputscale


//1 52bj6v8fqz39khasobljfukk9
// extern int Syntax_errors


//1 9ekf2ina8fsjj6y6i0an6somj
// extern int Show_cnt


//1 38di5qi3nkxkq65onyvconk3r
// extern char** Show_boxes


//1 6ri6iu712m8mpc7t2670etpcw
// extern int CL_type


//1 bomxiw3gy0cgd1ydqtek7fpxr
// extern unsigned char Concentrate


//1 cqy3gqgcq8empdrbnrhn84058
// extern double Epsilon


//1 64slegfoouqeg0rmbyjrm8wgr
// extern int MaxIter


//1 88wdinpnmfs4mab4aw62yb0bg
// extern int Ndim


//1 8bbad3ogcelqnnvo5br5s05gq
// extern int State


//1 17rnd8q45zclfn68qqst2vxxn
// extern int EdgeLabelsDone


//1 ymx1z4s8cznjifl2d9f9m8jr
// extern double Initial_dist


//1 a33bgl0c3uqb3trx419qulj1x
// extern double Damping


//1 d9lvrpjg1r0ojv40pod1xwk8n
// extern int Y_invert


//1 71efkfs77q5tq9ex6y0f4kanh
// extern int GvExitOnUsage


//1 4xy2dkdkv0acs2ue9eca8hh2e
// extern Agsym_t 	*G_activepencolor, *G_activefillcolor, 	*G_selectedpencolor, *G_selectedfillcolor, 	*G_visitedpencolor, *G_visitedfillcolor, 	*G_deletedpencolor, *G_deletedfillcolor, 	*G_ordering, *G_peripheries, *G_penwidth, 	*G_gradientangle, *G_margin


//1 9js5gxgzr74eakgtfhnbws3t9
// extern Agsym_t 	*N_height, *N_width, *N_shape, *N_color, *N_fillcolor, 	*N_activepencolor, *N_activefillcolor, 	*N_selectedpencolor, *N_selectedfillcolor, 	*N_visitedpencolor, *N_visitedfillcolor, 	*N_deletedpencolor, *N_deletedfillcolor, 	*N_fontsize, *N_fontname, *N_fontcolor, *N_margin, 	*N_label, *N_xlabel, *N_nojustify, *N_style, *N_showboxes, 	*N_sides, *N_peripheries, *N_ordering, *N_orientation, 	*N_skew, *N_distortion, *N_fixed, *N_imagescale, *N_layer, 	*N_group, *N_comment, *N_vertices, *N_z, 	*N_penwidth, *N_gradientangle


//1 anqllp9sj7wo45w6bm11j8trn
// extern Agsym_t 	*E_weight, *E_minlen, *E_color, *E_fillcolor, 	*E_activepencolor, *E_activefillcolor, 	*E_selectedpencolor, *E_selectedfillcolor, 	*E_visitedpencolor, *E_visitedfillcolor, 	*E_deletedpencolor, *E_deletedfillcolor, 	*E_fontsize, *E_fontname, *E_fontcolor, 	*E_label, *E_xlabel, *E_dir, *E_style, *E_decorate, 	*E_showboxes, *E_arrowsz, *E_constr, *E_layer, 	*E_comment, *E_label_float, 	*E_samehead, *E_sametail, 	*E_arrowhead, *E_arrowtail, 	*E_headlabel, *E_taillabel, 	*E_labelfontsize, *E_labelfontname, *E_labelfontcolor, 	*E_labeldistance, *E_labelangle, 	*E_tailclip, *E_headclip, 	*E_penwidth


//1 bh0z9puipqw7gymjd5h5b8s6i
// extern struct fdpParms_s* fdp_parms




//3 ciez0pfggxdljedzsbklq49f0
// static inline point pointof(int x, int y) 
public static Object pointof(Object... arg) {
UNSUPPORTED("8e4tj258yvfq5uhsdpk37n5eq"); // static inline point pointof(int x, int y)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c0j3k9xv06332q98k2pgpacto"); //     point r;
UNSUPPORTED("12jimkrzqxavaie0cpapbx18c"); //     r.x = x;
UNSUPPORTED("7ivmviysahgsc5nn9gtp7q2if"); //     r.y = y;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c1s4k85p1cdfn176o3uryeros
// static inline pointf pointfof(double x, double y) 
public static __struct__<pointf> pointfof(double x, double y) {
// WARNING!! STRUCT
return pointfof_w_(x, y).copy();
}
private static __struct__<pointf> pointfof_w_(double x, double y) {
ENTERING("c1s4k85p1cdfn176o3uryeros","pointfof");
try {
    final __struct__<pointf> r = __struct__.from(pointf.class);
    r.setDouble("x", x);
    r.setDouble("y", y);
    return r;
} finally {
LEAVING("c1s4k85p1cdfn176o3uryeros","pointfof");
}
}




//3 7cufnfitrh935ew093mw0i4b7
// static inline box boxof(int llx, int lly, int urx, int ury) 
public static Object boxof(Object... arg) {
UNSUPPORTED("3lzesfdd337h31jrlib1czocm"); // static inline box boxof(int llx, int lly, int urx, int ury)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("52u27kayecy1i1e8bbo8f7s9r"); //     box b;
UNSUPPORTED("cylhjlutoc0sc0uy7g98m9fb8"); //     b.LL.x = llx, b.LL.y = lly;
UNSUPPORTED("242of6revxzx8hpe7yerrchz6"); //     b.UR.x = urx, b.UR.y = ury;
UNSUPPORTED("2vmm1j57brhn455f8f3iyw6mo"); //     return b;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1vvsta5i8of59frav6uymguav
// static inline boxf boxfof(double llx, double lly, double urx, double ury) 
public static __struct__<boxf> boxfof(double llx, double lly, double urx, double ury) {
// WARNING!! STRUCT
return boxfof_w_(llx, lly, urx, ury).copy();
}
private static __struct__<boxf> boxfof_w_(double llx, double lly, double urx, double ury) {
ENTERING("1vvsta5i8of59frav6uymguav","boxfof");
try {
    final __struct__<boxf> b = __struct__.from(boxf.class);
    b.getStruct("LL").setDouble("x", llx);
    b.getStruct("LL").setDouble("y", lly);
    b.getStruct("UR").setDouble("x", urx);
    b.getStruct("UR").setDouble("y", ury);
    return b;
} finally {
LEAVING("1vvsta5i8of59frav6uymguav","boxfof");
}
}




//3 1n5xl70wxuabyf97mclvilsm6
// static inline point add_point(point p, point q) 
public static Object add_point(Object... arg) {
UNSUPPORTED("6iamka1fx8fk1rohzzse8phte"); // static inline point add_point(point p, point q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c0j3k9xv06332q98k2pgpacto"); //     point r;
UNSUPPORTED("3n2sizjd0civbzm6iq7su1s2p"); //     r.x = p.x + q.x;
UNSUPPORTED("65ygdo31w09i5i6bd2f7azcd3"); //     r.y = p.y + q.y;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 arrsbik9b5tnfcbzsm8gr2chx
// static inline pointf add_pointf(pointf p, pointf q) 
public static __struct__<pointf> add_pointf(final __struct__<pointf> p, final __struct__<pointf> q) {
// WARNING!! STRUCT
return add_pointf_w_(p.copy(), q.copy()).copy();
}
private static __struct__<pointf> add_pointf_w_(final __struct__<pointf> p, final __struct__<pointf> q) {
ENTERING("arrsbik9b5tnfcbzsm8gr2chx","add_pointf");
try {
    final __struct__<pointf> r = __struct__.from(pointf.class);
    r.setDouble("x", p.getDouble("x") + q.getDouble("x"));
    r.setDouble("y", p.getDouble("y") + q.getDouble("y"));
    return r;
} finally {
LEAVING("arrsbik9b5tnfcbzsm8gr2chx","add_pointf");
}
}




//3 ai2dprak5y6obdsflguh5qbd7
// static inline point sub_point(point p, point q) 
public static Object sub_point(Object... arg) {
UNSUPPORTED("cd602849h0bce8lu9xegka0ia"); // static inline point sub_point(point p, point q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c0j3k9xv06332q98k2pgpacto"); //     point r;
UNSUPPORTED("4q4q9dveah93si8ajfv59gz27"); //     r.x = p.x - q.x;
UNSUPPORTED("9f90ik0o2yqhanzntpy3d2ydy"); //     r.y = p.y - q.y;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 16f6pyogcv3j7n2p0n8giqqgh
// static inline pointf sub_pointf(pointf p, pointf q) 
public static Object sub_pointf(Object... arg) {
UNSUPPORTED("dmufj44lddsnj0wjyxsg2fcso"); // static inline pointf sub_pointf(pointf p, pointf q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cvexv13y9fq49v0j4d5t4cm9f"); //     pointf r;
UNSUPPORTED("4q4q9dveah93si8ajfv59gz27"); //     r.x = p.x - q.x;
UNSUPPORTED("9f90ik0o2yqhanzntpy3d2ydy"); //     r.y = p.y - q.y;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9k50jgrhc4f9824vf8ony74rw
// static inline point mid_point(point p, point q) 
public static Object mid_point(Object... arg) {
UNSUPPORTED("evy44tdsmu3erff9dp2x835u2"); // static inline point mid_point(point p, point q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c0j3k9xv06332q98k2pgpacto"); //     point r;
UNSUPPORTED("1a6p6fm57o0wt5ze2btsx06c7"); //     r.x = (p.x + q.x) / 2;
UNSUPPORTED("1kbj5tgdmfi6kf4jgg6skhr6e"); //     r.y = (p.y + q.y) / 2;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 59c4f7im0ftyowhnzzq2v9o1x
// static inline pointf mid_pointf(pointf p, pointf q) 
public static Object mid_pointf(Object... arg) {
UNSUPPORTED("381o63o9kb04d7gzg65v0r3q"); // static inline pointf mid_pointf(pointf p, pointf q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cvexv13y9fq49v0j4d5t4cm9f"); //     pointf r;
UNSUPPORTED("c5vboetlr3mf43wns7iik6m1w"); //     r.x = (p.x + q.x) / 2.;
UNSUPPORTED("bcdf562ldr3bjn78hcay5xd63"); //     r.y = (p.y + q.y) / 2.;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5r18p38gisvcx3zsvbb9saixx
// static inline pointf interpolate_pointf(double t, pointf p, pointf q) 
public static Object interpolate_pointf(Object... arg) {
UNSUPPORTED("894yimn33kmtm454llwdaotu8"); // static inline pointf interpolate_pointf(double t, pointf p, pointf q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ef2acl8wa2ooqcb5vz3098maz"); //     pointf r; 
UNSUPPORTED("5tpwuyf5iidesy80v8o4nwkmk"); //     r.x = p.x + t * (q.x - p.x);
UNSUPPORTED("ewnrc5uloj3w5jbmsjcn3wja0"); //     r.y = p.y + t * (q.y - p.y);
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bxzrv2ghq04qk5cbyy68s4mol
// static inline point exch_xy(point p) 
public static Object exch_xy(Object... arg) {
UNSUPPORTED("2vxya0v2fzlv5e0vjaa8d414"); // static inline point exch_xy(point p)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c0j3k9xv06332q98k2pgpacto"); //     point r;
UNSUPPORTED("60cojdwc2h7f0m51s9jdwvup7"); //     r.x = p.y;
UNSUPPORTED("evp2x66oa4s1tlnc0ytxq2qbq"); //     r.y = p.x;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9lt3e03tac6h6sydljrcws8fd
// static inline pointf exch_xyf(pointf p) 
public static Object exch_xyf(Object... arg) {
UNSUPPORTED("8qamrobrqi8jsvvfrxkimrsnw"); // static inline pointf exch_xyf(pointf p)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cvexv13y9fq49v0j4d5t4cm9f"); //     pointf r;
UNSUPPORTED("60cojdwc2h7f0m51s9jdwvup7"); //     r.x = p.y;
UNSUPPORTED("evp2x66oa4s1tlnc0ytxq2qbq"); //     r.y = p.x;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8l9qhieokthntzdorlu5zn29b
// static inline box box_bb(box b0, box b1) 
public static Object box_bb(Object... arg) {
UNSUPPORTED("36et5gmnjrby6o7bq9sgh1hx6"); // static inline box box_bb(box b0, box b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("52u27kayecy1i1e8bbo8f7s9r"); //     box b;
UNSUPPORTED("8mr2c9xitsqi8z1plbp7ox1hu"); //     b.LL.x = MIN(b0.LL.x, b1.LL.x);
UNSUPPORTED("2egu55ef4u1i03nwz01k7kcrl"); //     b.LL.y = MIN(b0.LL.y, b1.LL.y);
UNSUPPORTED("9n6ei3odbgefwfxvql9whcpe"); //     b.UR.x = MAX(b0.UR.x, b1.UR.x);
UNSUPPORTED("19ocysbuh4pxyft2bqhyhigr1"); //     b.UR.y = MAX(b0.UR.y, b1.UR.y);
UNSUPPORTED("2vmm1j57brhn455f8f3iyw6mo"); //     return b;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 clws9h3bbjm0lw3hexf8nl4c4
// static inline boxf boxf_bb(boxf b0, boxf b1) 
public static Object boxf_bb(Object... arg) {
UNSUPPORTED("dyrqu4ww9osr9c86gqgmifcp6"); // static inline boxf boxf_bb(boxf b0, boxf b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c57pq0f87j6dnbcvygu7v6k84"); //     boxf b;
UNSUPPORTED("8mr2c9xitsqi8z1plbp7ox1hu"); //     b.LL.x = MIN(b0.LL.x, b1.LL.x);
UNSUPPORTED("2egu55ef4u1i03nwz01k7kcrl"); //     b.LL.y = MIN(b0.LL.y, b1.LL.y);
UNSUPPORTED("9n6ei3odbgefwfxvql9whcpe"); //     b.UR.x = MAX(b0.UR.x, b1.UR.x);
UNSUPPORTED("19ocysbuh4pxyft2bqhyhigr1"); //     b.UR.y = MAX(b0.UR.y, b1.UR.y);
UNSUPPORTED("2vmm1j57brhn455f8f3iyw6mo"); //     return b;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bit6ycxo1iqd2al92y8gkzlvb
// static inline box box_intersect(box b0, box b1) 
public static Object box_intersect(Object... arg) {
UNSUPPORTED("34gv28cldst09bl71itjgviue"); // static inline box box_intersect(box b0, box b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("52u27kayecy1i1e8bbo8f7s9r"); //     box b;
UNSUPPORTED("9slu7bixuymxttjic76ha2nl2"); //     b.LL.x = MAX(b0.LL.x, b1.LL.x);
UNSUPPORTED("3uv943c2f82yuif249pf5azob"); //     b.LL.y = MAX(b0.LL.y, b1.LL.y);
UNSUPPORTED("74tf5h16bc9zabq3s3dyny543"); //     b.UR.x = MIN(b0.UR.x, b1.UR.x);
UNSUPPORTED("d99gcv3i7xes7y7rqf8ii20ux"); //     b.UR.y = MIN(b0.UR.y, b1.UR.y);
UNSUPPORTED("2vmm1j57brhn455f8f3iyw6mo"); //     return b;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8gfybie7k6pgb3o1a6llgpwng
// static inline boxf boxf_intersect(boxf b0, boxf b1) 
public static Object boxf_intersect(Object... arg) {
UNSUPPORTED("ape22b8z6jfg17gvo42hok9eb"); // static inline boxf boxf_intersect(boxf b0, boxf b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c57pq0f87j6dnbcvygu7v6k84"); //     boxf b;
UNSUPPORTED("9slu7bixuymxttjic76ha2nl2"); //     b.LL.x = MAX(b0.LL.x, b1.LL.x);
UNSUPPORTED("3uv943c2f82yuif249pf5azob"); //     b.LL.y = MAX(b0.LL.y, b1.LL.y);
UNSUPPORTED("74tf5h16bc9zabq3s3dyny543"); //     b.UR.x = MIN(b0.UR.x, b1.UR.x);
UNSUPPORTED("d99gcv3i7xes7y7rqf8ii20ux"); //     b.UR.y = MIN(b0.UR.y, b1.UR.y);
UNSUPPORTED("2vmm1j57brhn455f8f3iyw6mo"); //     return b;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7z8j2quq65govaaejrz7b4cvb
// static inline int box_overlap(box b0, box b1) 
public static Object box_overlap(Object... arg) {
UNSUPPORTED("1e9k599x7ygct7r4cfdxlk9u9"); // static inline int box_overlap(box b0, box b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7a9wwpu7dhdphd08y1ecw54w5"); //     return OVERLAP(b0, b1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4z0suuut2acsay5m8mg9dqjdu
// static inline int boxf_overlap(boxf b0, boxf b1) 
public static Object boxf_overlap(Object... arg) {
UNSUPPORTED("905nejsewihwhhc3bhnrz9nwo"); // static inline int boxf_overlap(boxf b0, boxf b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7a9wwpu7dhdphd08y1ecw54w5"); //     return OVERLAP(b0, b1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dd34swz5rmdgu3a2np2a4h1dy
// static inline int box_contains(box b0, box b1) 
public static Object box_contains(Object... arg) {
UNSUPPORTED("aputfc30fjkvy6jx4otljaczq"); // static inline int box_contains(box b0, box b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("87ap80vrh2a4gpprbxr33lrg3"); //     return CONTAINS(b0, b1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8laj1bspbu2i1cjd9upr7xt32
// static inline int boxf_contains(boxf b0, boxf b1) 
public static Object boxf_contains(Object... arg) {
UNSUPPORTED("7ccnttkiwt834yfyw0evcm18v"); // static inline int boxf_contains(boxf b0, boxf b1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("87ap80vrh2a4gpprbxr33lrg3"); //     return CONTAINS(b0, b1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4wf5swkz24xx51ja2dynbycu1
// static inline pointf perp (pointf p) 
public static Object perp(Object... arg) {
UNSUPPORTED("567wpqlg9rv63ynyvxd9sgkww"); // static inline pointf perp (pointf p)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cvexv13y9fq49v0j4d5t4cm9f"); //     pointf r;
UNSUPPORTED("2fyydy6t6yifjsczccsb9szeg"); //     r.x = -p.y;
UNSUPPORTED("evp2x66oa4s1tlnc0ytxq2qbq"); //     r.y = p.x;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6dtlpzv4mvgzb9o0b252yweuv
// static inline pointf scale (double c, pointf p) 
public static Object scale(Object... arg) {
UNSUPPORTED("c1ngytew34bmkdb7vps5h3dh8"); // static inline pointf scale (double c, pointf p)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cvexv13y9fq49v0j4d5t4cm9f"); //     pointf r;
UNSUPPORTED("dznf7nac14snww4usquyd6r3r"); //     r.x = c * p.x;
UNSUPPORTED("33kk73m8vjcux5tnjl8co2pe6"); //     r.y = c * p.y;
UNSUPPORTED("a2hk6w52njqjx48nq3nnn2e5i"); //     return r;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 z596gpwi24gl7hh3seyp0gck
// static void free_ritem(Dt_t* d, pitem* p,Dtdisc_t* ds) 
public static Object free_ritem(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("d1sfyoxiqpnl52w8y4ogbcpx4"); // free_ritem(Dt_t* d, pitem* p,Dtdisc_t* ds)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("79kn2ug4yy0rtx86eqx7hzfas"); //   dtclose (p->u.rp);
UNSUPPORTED("9e923y5yzq38a869awae5o4pq"); //   free (p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 agf3jzkrkzu95vturq4ruirl1
// static void free_item(Dt_t* d, void* p,Dtdisc_t* ds) 
public static Object free_item(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("aeylv2tqn9jclpx81wzo8jna8"); // free_item(Dt_t* d, void* p,Dtdisc_t* ds)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9e923y5yzq38a869awae5o4pq"); //   free (p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 53er8pztmugi7aaoo8w6xwmtt
// static void cleanTbl (htmltbl_t* tp) 
public static Object cleanTbl(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("ejt6odqhq24f0w764y6ycw02q"); // cleanTbl (htmltbl_t* tp)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7krxj3oaa24is3so7hqc97yq4"); //   dtclose (tp->u.p.rows);
UNSUPPORTED("dkrc2ghxhhre60fr65tyau4h"); //   free_html_data (&tp->data);
UNSUPPORTED("b5ddb7yg0q1g3is7zdyamegtz"); //   free (tp);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5fdbv5ru77dtss1pgwxt2dviz
// static void cleanCell (htmlcell_t* cp) 
public static Object cleanCell(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("a2mzu2huku49nng3e0xjq7gly"); // cleanCell (htmlcell_t* cp)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("77li1v44m9m2t09yybvetr1j7"); //   if (cp->child.kind == 1) cleanTbl (cp->child.u.tbl);
UNSUPPORTED("e9frm74dt3zpfwmvcjt6d7rsp"); //   else if (cp->child.kind == 2) free_html_text (cp->child.u.txt);
UNSUPPORTED("8o091oqx5kx7i4vunqj2rbe3w"); //   free_html_data (&cp->data);
UNSUPPORTED("4pvswhooboe78ehkkgcubcohg"); //   free (cp);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8ipdkk14qkzxks3qfhcg430xd
// static void free_citem(Dt_t* d, pitem* p,Dtdisc_t* ds) 
public static Object free_citem(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("bixe5avd0uejldfgeyicnxgak"); // free_citem(Dt_t* d, pitem* p,Dtdisc_t* ds)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8mlg640v3o1fdr5uj9sn6po9s"); //   cleanCell (p->u.cp);
UNSUPPORTED("9e923y5yzq38a869awae5o4pq"); //   free (p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 8syn2cu0jbf04go8pm5edutfo
// static Dtdisc_t rowDisc = 


//1 94uru1gihainl2dp1ajf4c2nb
// static Dtdisc_t cellDisc = 




//3 4vewb2db7impvcvf47z3wia3j
// static void  free_fitem(Dt_t* d, fitem* p, Dtdisc_t* ds) 
public static Object free_fitem(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("26gmt3uykv7jwzz4zsuhzmh6c"); // free_fitem(Dt_t* d, fitem* p, Dtdisc_t* ds)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("arsp2i9gms37oc65b9ios89et"); //     if (p->ti.str)
UNSUPPORTED("3k6lgmit4vxwd69i0exjcet4e"); // 	free (p->ti.str);
UNSUPPORTED("ap7e4kfupx34ac9hq9kl5x48o"); //     free (p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 49a1cavr0uwsfiywr4vlx1j9a
// static void  free_fspan(Dt_t* d, fspan* p, Dtdisc_t* ds) 
public static Object free_fspan(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("8jhubbnlsdmf8fbpmzgat0ym2"); // free_fspan(Dt_t* d, fspan* p, Dtdisc_t* ds)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("329j7icm39s2sase5gxu6gc03"); //     textspan_t* ti;
UNSUPPORTED("42eg0b6eo5j9iu80p1uw4zid7"); //     if (p->lp.nitems) {
UNSUPPORTED("bbuxsg26kpzb2fl660hjri9l8"); // 	int i;
UNSUPPORTED("f4tcwn4c6523y5ixkmiplt4hy"); // 	ti = p->lp.items;
UNSUPPORTED("a82cuuzhevdwszh5on4eme3j6"); // 	for (i = 0; i < p->lp.nitems; i++) {
UNSUPPORTED("1o53httu5a3mbs45forifv3v"); // 	    if (ti->str) free (ti->str);
UNSUPPORTED("6f0wl1s431kpd69mmcufrgwpw"); // 	    ti++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("ck90yu0z5f11dxw03hkkrq95f"); // 	free (p->lp.items);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ap7e4kfupx34ac9hq9kl5x48o"); //     free (p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 1np2sacxaatzjpdyuxmr0k1f1
// static Dtdisc_t fstrDisc = 


//1 1isgrjiedau6lket9pvwj1cxy
// static Dtdisc_t fspanDisc = 




//3 5mdfgv2hdexhdfc83v70ruckg
// static void appendFItemList (agxbuf *ag) 
public static Object appendFItemList(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("3bn87tz9mrrkcgn2ilvrticxw"); // appendFItemList (agxbuf *ag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("doxwot367nm4unbmqvlyra7iq"); //     fitem *fi = (fitem*)zmalloc(sizeof(fitem));
UNSUPPORTED("4lvo94ar3s2v4g4pkc1ms9lwy"); //     fi->ti.str = strdup((((((ag)->ptr >= (ag)->eptr) ? agxbmore(ag,1) : 0), (int)(*(ag)->ptr++ = ((unsigned char)'\0'))),(char*)((ag)->ptr = (ag)->buf)));
UNSUPPORTED("91z0oz4x1kngfnfwxn4cltgws"); //     fi->ti.font = HTMLstate.fontstack->cfont;
UNSUPPORTED("3ywp027tx29yvpgfvcnwxudxh"); //     (*(((Dt_t*)(HTMLstate.fitemList))->searchf))((HTMLstate.fitemList),(void*)(fi),0000001);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4famoxxlv0pr1b2fcrf0jgu7s
// static void  appendFLineList (int v) 
public static Object appendFLineList(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("1azzbwypafe22124r30oc4gda"); // appendFLineList (int v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6iv4xusq3ncisurzdtlt8lhe9"); //     int cnt;
UNSUPPORTED("9zu5mdi1r78uwa3vbpf61c95d"); //     fspan *ln = (fspan*)zmalloc(sizeof(fspan));
UNSUPPORTED("6k4lwsneas5kj0gght5yl0cwz"); //     fitem *fi;
UNSUPPORTED("6g93m1mz5i3cvqsrtk0010zx7"); //     Dt_t *ilist = HTMLstate.fitemList;
UNSUPPORTED("755rwhfp43ntyoieyof0bydox"); //     cnt = dtsize(ilist);
UNSUPPORTED("egxqlj0drkytzofn16fw10t2k"); //     ln->lp.just = v;
UNSUPPORTED("77njmf3w9m7xk714hk5o8hjv5"); //     if (cnt) {
UNSUPPORTED("6pui6q7pmbuh77j3mwflu6dh5"); //         int i = 0;
UNSUPPORTED("364dv1yyznq3ttfgmlficsnjl"); // 	ln->lp.nitems = cnt;
UNSUPPORTED("8svd1o5xg6z1ni5xqndfxjfoa"); // 	ln->lp.items = (textspan_t*)zmalloc((cnt)*sizeof(textspan_t));
UNSUPPORTED("7jn3x6w0gczpwy9ly59swpxo0"); // 	fi = (fitem*)dtflatten(ilist);
UNSUPPORTED("6mm1jtagzhgt1uvafv3xsnrps"); // 	for (; fi; fi = (fitem*)(((Dtlink_t*)((Dtlink_t*)fi))->right)) {
UNSUPPORTED("4ubyu68yegzu2jnk1iubu6ior"); // 		/* NOTE: When fitemList is closed, it uses free_item, which only frees the container,
UNSUPPORTED("dhebr74wsajvoittzd8u8d2f9"); // 		 * not the contents, so this copy is safe.
UNSUPPORTED("edw1ss2r31mqgsvca2gowi52v"); // 		 */
UNSUPPORTED("e9w5vyh1n133n13q9qyjy9ozt"); // 	    ln->lp.items[i] = fi->ti;  
UNSUPPORTED("1lo0ackow66iudrq1gb15y3ry"); // 	    i++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1nyzbeonram6636b1w955bypn"); //     else {
UNSUPPORTED("988zd9b8qbjkr2ruagx1lba6j"); // 	ln->lp.items = (textspan_t*)zmalloc(sizeof(textspan_t));
UNSUPPORTED("7olg12o4clx3ucbt1ovdkecgj"); // 	ln->lp.nitems = 1;
UNSUPPORTED("9s20ql63zxmctegw4085j3fmx"); // 	ln->lp.items[0].str = strdup("");
UNSUPPORTED("2p1lktdlp9q8kh7c1ujxogs61"); // 	ln->lp.items[0].font = HTMLstate.fontstack->cfont;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("53hyx9r3svmvy8o9fi8qr4mzm"); //     (*(((Dt_t*)(ilist))->searchf))((ilist),(void*)(0),0000100);
UNSUPPORTED("8n0i45x1qnicbsjl3t906vaa8"); //     (*(((Dt_t*)(HTMLstate.fspanList))->searchf))((HTMLstate.fspanList),(void*)(ln),0000001);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 az5nhw9enic3fddz8gnedxcju
// static htmltxt_t* mkText(void) 
public static Object mkText(Object... arg) {
UNSUPPORTED("ey6kc3f9ltt691wqrfmypaozl"); // static htmltxt_t*
UNSUPPORTED("cjs0uzhgqb2fc7756tzv0vojf"); // mkText(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6iv4xusq3ncisurzdtlt8lhe9"); //     int cnt;
UNSUPPORTED("3moicc1bb7tuz64d74jgr044"); //     Dt_t * ispan = HTMLstate.fspanList;
UNSUPPORTED("243kqn4v9kdemlqwu2dhg6pdy"); //     fspan *fl ;
UNSUPPORTED("e188sj25s1ko32xdk40qd877e"); //     htmltxt_t *hft = (htmltxt_t*)zmalloc(sizeof(htmltxt_t));
UNSUPPORTED("ag6dt4kjzoulw1j0mhwbokdid"); //     if (dtsize (HTMLstate.fitemList)) 
UNSUPPORTED("5madleux7wg2vumi9pl1bdv8s"); // 	appendFLineList (0);
UNSUPPORTED("ykhei8t74adzsrnktxe4u6wc"); //     cnt = dtsize(ispan);
UNSUPPORTED("57eezqowalifcx3ocgmtz5gmp"); //     hft->nspans = cnt;
UNSUPPORTED("77njmf3w9m7xk714hk5o8hjv5"); //     if (cnt) {
UNSUPPORTED("87wlv7rom7negdjfub75atom0"); // 	int i = 0;
UNSUPPORTED("btg64tgzrm3tsx7w2cjgtkt5g"); // 	hft->spans = (htextspan_t*)zmalloc((cnt)*sizeof(htextspan_t));	
UNSUPPORTED("2yjlc0huszsbrp4p6mljwnqez"); //     	for(fl=(fspan *)(*(((Dt_t*)(ispan))->searchf))((ispan),(void*)(0),0000200); fl; fl=(fspan *)(*(((Dt_t*)(ispan))->searchf))((ispan),(void*)(fl),0000010)) {
UNSUPPORTED("o7nqqo5invz9fssk2z7yxvdk"); //     	    hft->spans[i] = fl->lp;
UNSUPPORTED("5at77pazhse3utac5y67rfrpg"); //     	    i++;
UNSUPPORTED("klxoy56t7b20wxnwqm0qoofz"); //     	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ewiox4giau2t8uc31b4m8cbos"); //     (*(((Dt_t*)(ispan))->searchf))((ispan),(void*)(0),0000100);
UNSUPPORTED("dnp8w4len77c0t9hp9b2j5nye"); //     return hft;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 23wdl6n60rq8jhsrdhgamjwls
// static pitem* lastRow (void) 
public static Object lastRow(Object... arg) {
UNSUPPORTED("d6gug3eud9z5l6tlnca1w8use"); // static pitem* lastRow (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7yjzj8jcniwi23ahtmhu8f7cp"); //   htmltbl_t* tbl = HTMLstate.tblstack;
UNSUPPORTED("f25khljxvq2epkwsa4mgzdc5v"); //   pitem*     sp = (*(((Dt_t*)(tbl->u.p.rows))->searchf))((tbl->u.p.rows),(void*)(0),0000400);
UNSUPPORTED("1nblb3mrq7wrxkm06v7yvyin"); //   return sp;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8t79v9x9xl9lbtpdi34ff3phe
// static pitem* addRow (void) 
public static Object addRow(Object... arg) {
UNSUPPORTED("743f44ql6wbf8utttlgok2tms"); // static pitem* addRow (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("76ds0mb9gofz9vcw348tw74pq"); //   Dt_t*      dp = dtopen(&cellDisc, Dtqueue);
UNSUPPORTED("7yjzj8jcniwi23ahtmhu8f7cp"); //   htmltbl_t* tbl = HTMLstate.tblstack;
UNSUPPORTED("6zaqqicaaq9xlvykkckhmxbyy"); //   pitem*     sp = (pitem*)zmalloc(sizeof(pitem));
UNSUPPORTED("aqkc4euu97i25dyyrncpttmit"); //   sp->u.rp = dp;
UNSUPPORTED("3fun70bheg258bgk09490w0sh"); //   if (tbl->flags & 2)
UNSUPPORTED("dmgfwq598sxflnnqkc7ad1b32"); //     sp->ruled = 1;
UNSUPPORTED("2g348nq1krudex6ifjgv27wyg"); //   (*(((Dt_t*)(tbl->u.p.rows))->searchf))((tbl->u.p.rows),(void*)(sp),0000001);
UNSUPPORTED("1nblb3mrq7wrxkm06v7yvyin"); //   return sp;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bdjjvqfdlg0yrp580jpv43hw4
// static void setCell (htmlcell_t* cp, void* obj, int kind) 
public static Object setCell(Object... arg) {
UNSUPPORTED("a6ymak98eyh09432vmvpogipt"); // static void setCell (htmlcell_t* cp, void* obj, int kind)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6zaqqicaaq9xlvykkckhmxbyy"); //   pitem*     sp = (pitem*)zmalloc(sizeof(pitem));
UNSUPPORTED("7yjzj8jcniwi23ahtmhu8f7cp"); //   htmltbl_t* tbl = HTMLstate.tblstack;
UNSUPPORTED("qw6vdwg3yid1pdaz0qrjppaj"); //   pitem*     rp = (pitem*)(*(((Dt_t*)(tbl->u.p.rows))->searchf))((tbl->u.p.rows),(void*)(0),0000400);
UNSUPPORTED("d6k77mp03y46jligheanx94dg"); //   Dt_t*      row = rp->u.rp;
UNSUPPORTED("e9s2ni07poro3gct8f1ya0l7a"); //   sp->u.cp = cp;
UNSUPPORTED("2ajp3r1vfd0xl0s07q51tgkhd"); //   (*(((Dt_t*)(row))->searchf))((row),(void*)(sp),0000001);
UNSUPPORTED("73ausrcgminfktwghjhuctrdc"); //   cp->child.kind = kind;
UNSUPPORTED("8ianzmahfvf64a86twwxp86jp"); //   if (tbl->flags & 1)
UNSUPPORTED("dpw9bdo34u2djuw3g3a6rsn0z"); //     cp->ruled = 1;
UNSUPPORTED("a2drbo5m3cl97fd4khnnp0x1x"); //   if(kind == 2)
UNSUPPORTED("g98aqixq093hbgc60377v9xj"); //   	cp->child.u.txt = (htmltxt_t*)obj;
UNSUPPORTED("7m1dgczjy0huec6a30h9cbkf"); //   else if (kind == 3)
UNSUPPORTED("6v92mg93bq298eauy1s1dn2kv"); //     cp->child.u.img = (htmlimg_t*)obj;
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("5mgc55pb51xtqrskdy6lupjj9"); //     cp->child.u.tbl = (htmltbl_t*)obj;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 86xg3md174m9d0hdj7lm1r8h8
// static htmllabel_t* mkLabel (void* obj, int kind) 
public static Object mkLabel(Object... arg) {
UNSUPPORTED("68olevx5qr27d1plva3kh6e5d"); // static htmllabel_t* mkLabel (void* obj, int kind)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8ke9r2q8imfs4uovjyrc0m582"); //   htmllabel_t* lp = (htmllabel_t*)zmalloc(sizeof(htmllabel_t));
UNSUPPORTED("43clk7pdhozybye425c5vxbqs"); //   lp->kind = kind;
UNSUPPORTED("59s9lao6qui2fmj9eef4wmr0l"); //   if (kind == 2)
UNSUPPORTED("11pai3t9lnogky3p7m0vpbty"); //     lp->u.txt = (htmltxt_t*)obj;
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("8ag7q576emt2v7de68p7zi1vg"); //     lp->u.tbl = (htmltbl_t*)obj;
UNSUPPORTED("75meu722lubo2wmb1bahwmv1u"); //   return lp;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cidlq4a037zcw1viv3yj5dm3o
// static void freeFontstack(void) 
public static Object freeFontstack(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("5n6hadg2nnxbykkls8yuljrux"); // freeFontstack(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7j1n1whz7ns8m658dgt3rf7m6"); //     sfont_t* s;
UNSUPPORTED("45fzuya14aqi3ydx2mx7qy7li"); //     sfont_t* next;
UNSUPPORTED("820gi48ql7mjvm02zqrlrk2j0"); //     for (s = HTMLstate.fontstack; (next = s->pfont); s = next) {
UNSUPPORTED("d285xdylp7oj81aar06ulc7kh"); // 	free(s);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ewyzfsvy1gms3jg0repa41hey
// static void cleanup (void) 
public static Object cleanup(Object... arg) {
UNSUPPORTED("4udlidhjhh186l60tnwrndods"); // static void cleanup (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("61xcnqsgba2hv68f84p8whcvy"); //   htmltbl_t* tp = HTMLstate.tblstack;
UNSUPPORTED("ej2qxu72gf97u4o99kg06l2bl"); //   htmltbl_t* next;
UNSUPPORTED("bzbpzh7k9m3nsya6a8e0qzuns"); //   if (HTMLstate.lbl) {
UNSUPPORTED("3we2rhjt0mgfjgbczne6cjhxh"); //     free_html_label (HTMLstate.lbl,1);
UNSUPPORTED("7kxmztohe6skbt7owagd4nyjj"); //     HTMLstate.lbl = NULL;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("d33vybg2nal9pqyqnsooy2a3e"); //   cellDisc.freef = (Dtfree_f)free_citem;
UNSUPPORTED("bep9lbei2j0r4rjc1dkx7zkzd"); //   while (tp) {
UNSUPPORTED("9t026l68ed6imumb8ij7yhzh5"); //     next = tp->u.p.prev;
UNSUPPORTED("8f6vdwgdm8fjshmxo6ei6l4x9"); //     cleanTbl (tp);
UNSUPPORTED("314eojl0ohy55hom5nx2fwyfi"); //     tp = next;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("caxitvipeydnmdgworfislzhs"); //   cellDisc.freef = (Dtfree_f)free_item;
UNSUPPORTED("dlpulny8fqkx25ms5nmppj3vz"); //   fstrDisc.freef = (Dtfree_f)free_fitem;
UNSUPPORTED("33zrdedw85v7v1x9nbd1ckxoa"); //   (*(((Dt_t*)(HTMLstate.fitemList))->searchf))((HTMLstate.fitemList),(void*)(0),0000100);
UNSUPPORTED("3869gecvlcnxgmpwhtwhrjm0d"); //   fstrDisc.freef = (Dtfree_f)free_item;
UNSUPPORTED("7odzhifod2x35wc5tbi6ix4be"); //   fspanDisc.freef = (Dtfree_f)free_fspan;
UNSUPPORTED("ba01mdd5f4vk5utis9ha5e30"); //   (*(((Dt_t*)(HTMLstate.fspanList))->searchf))((HTMLstate.fspanList),(void*)(0),0000100);
UNSUPPORTED("eav0sd07lj1ql28b4mb7w2uaf"); //   fspanDisc.freef = (Dtfree_f)free_item;
UNSUPPORTED("98nbz0do2np8v147v1gegnrbi"); //   freeFontstack();
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8bl8i4l3vq6849ak8bwey6mzk
// static int nonSpace (char* s) 
public static Object nonSpace(Object... arg) {
UNSUPPORTED("48jbmcx7d591k3p9ro9ty0m3g"); // static int nonSpace (char* s)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8jg9j6uvh89uy3p6606fh8a2w"); //   char   c;
UNSUPPORTED("efa7ei8mz8h7lvxh5wqq5wc33"); //   while ((c = *s++)) {
UNSUPPORTED("9sludt6qrbcf6zk9hm3gysufj"); //     if (c != ' ') return 1;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("bid671dovx1rdiquw5vm3fttj"); //   return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 87ios5hi5757k5miu6wlrum5w
// static void pushFont (textfont_t *fp) 
public static Object pushFont(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("a9n2aesdy1bywbrbze7gmkn17"); // pushFont (textfont_t *fp)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("691ytrxzc6cij5vazhtnuoy0n"); //     sfont_t *ft = (sfont_t*)zmalloc(sizeof(sfont_t));
UNSUPPORTED("31e675d7cp5uavv6vydzkii0t"); //     textfont_t* curfont = HTMLstate.fontstack->cfont;
UNSUPPORTED("18b0yq7hsh4rq27jpn4mqwq34"); //     textfont_t  f = *fp;
UNSUPPORTED("e31ng2kblbzn273ypcnmjro76"); //     if (curfont) {
UNSUPPORTED("2tpx9chys0c52v4xe4hacak69"); // 	if (!f.color && curfont->color)
UNSUPPORTED("1n368po1sgerkqtzfsd32203n"); // 	    f.color = curfont->color;
UNSUPPORTED("ak5bw2q3nrfw2txz5a14sq6ha"); // 	if ((f.size < 0.0) && (curfont->size >= 0.0))
UNSUPPORTED("aimplrk4u9egypl4ejx0x9b8d"); // 	    f.size = curfont->size;
UNSUPPORTED("4660knpp4fazggl9yqsfxdr1e"); // 	if (!f.name && curfont->name)
UNSUPPORTED("e43b7fxbbvqjlwtsywbv167k"); // 	    f.name = curfont->name;
UNSUPPORTED("d41lsjow2yoew5l40lj5se1wt"); // 	if (curfont->flags)
UNSUPPORTED("2c7fsvh63forfjfugu4grsiiq"); // 	    f.flags |= curfont->flags;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5jm1g08zslbh1e16seen6jgis"); //     ft->cfont = (*(((Dt_t*)(HTMLstate.gvc->textfont_dt))->searchf))((HTMLstate.gvc->textfont_dt),(void*)(&f),0000001);
UNSUPPORTED("3ptdxuzgcqapdr5xju6zt62cj"); //     ft->pfont = HTMLstate.fontstack;
UNSUPPORTED("3mdpaak1y5sxe2o2upjzfpy1e"); //     HTMLstate.fontstack = ft;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9p42c6b9fpbzacsbf6pelg18i
// static void  popFont (void) 
public static Object popFont(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("hvm5yavuo5ntqsxkc2wna9oi"); // popFont (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5ab6yk7kzqxbhn54ye5aovrb0"); //     sfont_t* curfont = HTMLstate.fontstack;
UNSUPPORTED("3enh12gz0ie5d7arcrnm4g0ck"); //     sfont_t* prevfont = curfont->pfont;
UNSUPPORTED("7lf7opedggfvxwj1hqhdb9wfr"); //     free (curfont);
UNSUPPORTED("5ono575lrg0e9hs3qnjqspxg1"); //     HTMLstate.fontstack = prevfont;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 3m6d1cijfc6a7zhs4el1r1r80
// extern YYSTYPE yylval


//1 7lxd9viqkr2d4upq5ly0ss23m
// typedef unsigned char yytype_uint8


//1 4a59l0x62df4kmcnnzny7qrta
// typedef short int yytype_int8


//1 2nrjyi2x4xpr9jjzho0bpu8cm
// typedef unsigned short int yytype_uint16


//1 2y29tbvfe4gv3ykm9x1h2cg2q
// typedef short int yytype_int16


//1 9zl7iljfsyw4w98wp0lkavzcz
// static const yytype_uint8 yytranslate[] = 


//1 7eofqjzmv1jjtxybcfgwirdo6
// static const yytype_uint8 yyr1[] = 


//1 ergyxr172748qexkiietu1kah
// static const yytype_uint8 yyr2[] = 


//1 d0mz6sxb8tibmsrak6yjz7xje
// static const yytype_uint8 yydefact[] = 


//1 1vmcg5wa0m0y29gvwoq6pceml
// static const yytype_int8 yydefgoto[] = 


//1 8ua882sh3fbz5wsd1y2jpxxvi
// static const yytype_int16 yypact[] = 


//1 bi5i029gbkpciucxw9cdyw2qt
// static const yytype_int16 yypgoto[] = 


//1 eah2re70qtly76fbhamfa5l76
// static const yytype_int8 yytable[] = 


//1 5lthlg8oeacaxjju7ihtxa72p
// static const yytype_int8 yycheck[] = 


//1 4y3mxezip1q69kevvggluzy83
// static const yytype_uint8 yystos[] = 




//3 d4f3pmjir7ks7uczm389ee342
// static void yydestruct (yymsg, yytype, yyvaluep)     const char *yymsg
public static Object yydestruct(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("6z3valttodfef9p0v0b90b7xy"); // yydestruct (yymsg, yytype, yyvaluep)
UNSUPPORTED("cbmgfstdv3sdevyp8bmuc9pix"); //     const char *yymsg;
UNSUPPORTED("6s7nq7d7qgx01kysn7094jwfe"); //     int yytype;
UNSUPPORTED("56gviyihbbn59yr16tfma815d"); //     YYSTYPE *yyvaluep;
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2785h7uyj7xmjojjiuapbyvfg"); //   ((void) (yyvaluep));
UNSUPPORTED("6zruki2d3oxvwe5rkhm4rrec3"); //   if (!yymsg)
UNSUPPORTED("ex05njmls0f5y8vumog0i9v30"); //     yymsg = "Deleting";
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("9aisjuert8kedobv3bvynam1l"); //   switch (yytype)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("5vhsnixpf0pg2oz10ps2valyn"); //       default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 4t3eaa1wxy67rmdq020suek5g
// int yychar


//1 65txx0ps68nds1ofl4me400po
// YYSTYPE yylval


//1 66amrdqtj9gqnibr2wzhjhyzh
// int yynerrs




//3 dsohi6w0mxb8bepdy2u8r7ft6
// int yyparse ()    
public static Object yyparse(Object... arg) {
UNSUPPORTED("etrjsq5w49uo9jq5pzifohkqw"); // int
UNSUPPORTED("b6v65fna6ryyq0tpig4iyu9vg"); // yyparse ()
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1dk3m00u84t1a2kyszepn80j6"); //     int yystate;
UNSUPPORTED("9s1gvm4tg9jub4ua9d2z36uh"); //     /* Number of tokens to shift before error messages enabled.  */
UNSUPPORTED("42c9eysu6d2pg1bypeyxm3qtj"); //     int yyerrstatus;
UNSUPPORTED("9ok1ifmve6y93u5i4275oxt1d"); //     /* The stacks and their tools:
UNSUPPORTED("4fukmr5oau0fjzcj04ar3kqkn"); //        `yyss': related to states.
UNSUPPORTED("8dhqnx1y3sapyexks84pvseir"); //        `yyvs': related to semantic values.
UNSUPPORTED("dfvqwf4g1d3d2zdxg9zrr8mjq"); //        Refer to the stacks through separate pointers, to allow yyoverflow
UNSUPPORTED("e8cfmvs5ozsrhl6v1u6mp3dw0"); //        to reallocate them elsewhere.  */
UNSUPPORTED("e0svr3ez9dsitn8x3e0ix2b6q"); //     /* The state stack.  */
UNSUPPORTED("2sqc8pekv6u4g5y7c671l43pw"); //     yytype_int16 yyssa[200];
UNSUPPORTED("f2qhrruh315q5l58ry41iaim2"); //     yytype_int16 *yyss;
UNSUPPORTED("c8itx6pxbsl031qaw5zpkmsy5"); //     yytype_int16 *yyssp;
UNSUPPORTED("3a5u4tdfyqrq2c72j4bf9ukca"); //     /* The semantic value stack.  */
UNSUPPORTED("1ng7z6w87duh2o6pk6c01x7g9"); //     YYSTYPE yyvsa[200];
UNSUPPORTED("3ude8ur34xko5iu75o2ebjtng"); //     YYSTYPE *yyvs;
UNSUPPORTED("1lyjomk5bc8y38szkrc1zv6z"); //     YYSTYPE *yyvsp;
UNSUPPORTED("9qxqwb5bwozch7m33wn87kzh9"); //     unsigned int yystacksize;
UNSUPPORTED("673206wu93ogvv72r0qab0vb7"); //   int yyn;
UNSUPPORTED("2yqvcni7p2qhfskomav9gkalo"); //   int yyresult;
UNSUPPORTED("15mkyt2y35y6b3kw61tcv89hz"); //   /* Lookahead token as an internal (translated) token number.  */
UNSUPPORTED("8f8xkti3pqf2hlqkoccpjmkfp"); //   int yytoken;
UNSUPPORTED("8e8sr2gy45snswwlopuywd4"); //   /* The variables used to return semantic value and location from the
UNSUPPORTED("d4q0w76h1grh0723v2ors4nxs"); //      action routines.  */
UNSUPPORTED("byt2amdyt07x4v308utxp7wxg"); //   YYSTYPE yyval;
UNSUPPORTED("8s5ggdw8hglgk87czklidx1pl"); //   /* The number of symbols on the RHS of the reduced rule.
UNSUPPORTED("d7da55fsvudhvjfgejvxp4301"); //      Keep to zero when no symbol should be popped.  */
UNSUPPORTED("548izgfrh6bp1djl5o8ct1dgu"); //   int yylen = 0;
UNSUPPORTED("827mn3d1rkymtmbgdamswh8cd"); //   yytoken = 0;
UNSUPPORTED("bh0phzvw63qgpbgd16c8y9pwx"); //   yyss = yyssa;
UNSUPPORTED("bv2p6df0685hzt5m8cbuo173n"); //   yyvs = yyvsa;
UNSUPPORTED("ed2zq9u3o6ujzfwp9w2m9vr1s"); //   yystacksize = 200;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("da1w9jcv3yts73g3wnb545sy9"); //   yystate = 0;
UNSUPPORTED("c70k37zof8xfzzd0dkp9evil8"); //   yyerrstatus = 0;
UNSUPPORTED("6bq75neqmnb7w2ltzm59t0db"); //   yynerrs = 0;
UNSUPPORTED("5xul3512dbcz7ghodgtlsriid"); //   yychar = (-2); /* Cause a token to be read.  */
UNSUPPORTED("f0kbtpk40bbe7m53uwx0eezp4"); //   /* Initialize stack pointers.
UNSUPPORTED("d8dtor5u60ag1mqqgil372nvk"); //      Waste one element of value and location stack
UNSUPPORTED("7ev6rqep9cwoby6w6f1tx2osc"); //      so that they stay on the same level as the state stack.
UNSUPPORTED("yd2jbvtitsi6j7lrxgzvchcv"); //      The wasted elements are never initialized.  */
UNSUPPORTED("9snje1pqr60ts9nh3hlkoybon"); //   yyssp = yyss;
UNSUPPORTED("6yijppbac4k1kbgx8vhht99fc"); //   yyvsp = yyvs;
UNSUPPORTED("bbhte1t33cpgfhqlwi01134bj"); //   goto yysetstate;
UNSUPPORTED("4flvn46w2728mhozqf9kuosm2"); // /*------------------------------------------------------------.
UNSUPPORTED("b2z6zko7vznmus9njmk7hc5wq"); // | yynewstate -- Push a new state, which is found in yystate.  |
UNSUPPORTED("a6znfp1d4ixngc79hwpyrw4wp"); // `------------------------------------------------------------*/
UNSUPPORTED("9mj285eb90wl3pdaog8uvexts"); //  yynewstate:
UNSUPPORTED("ej0agaz4g5pjpstralb0dkmdd"); //   /* In all cases, when you get here, the value and location stacks
UNSUPPORTED("7wmq2lqpn4jmj4m6nxe2ndmc5"); //      have just been pushed.  So pushing a state here evens the stacks.  */
UNSUPPORTED("2wy3sro4u4uf9kb8vl7d7xwlj"); //   yyssp++;
UNSUPPORTED("afv9alv5cytatzfp7ve1iimwh"); //  yysetstate:
UNSUPPORTED("944cbn8sbyvyrtpfe3hx2j2uh"); //   *yyssp = yystate;
UNSUPPORTED("bi6mggybevzfmmidanfaspr11"); //   if (yyss + yystacksize - 1 <= yyssp)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("548pbbpfwcnj355codzyz202a"); //       /* Get the current used size of the three stacks, in elements.  */
UNSUPPORTED("ec8ld8t5quqy3vtn60ki30o6z"); //       unsigned int yysize = yyssp - yyss + 1;
UNSUPPORTED("74tyblyhdau9tp40uzltqv3x7"); //       /* Extend the stack our own way.  */
UNSUPPORTED("b5eatrtbq7sduonqte8f21so4"); //       if (10000 <= yystacksize)
UNSUPPORTED("eon6lih6282gufu0qvrgl5g2j"); // 	goto yyexhaustedlab;
UNSUPPORTED("1ulf4xdxoqrvyivaown8lyg3a"); //       yystacksize *= 2;
UNSUPPORTED("5cyf16zzve41ehkzbbvk41ock"); //       if (10000 < yystacksize)
UNSUPPORTED("8wopg9oj560fnhrwhbn2j3hfi"); // 	yystacksize = 10000;
UNSUPPORTED("cdsm9962a8k19vkufzg36hzc8"); //       {
UNSUPPORTED("bdtlcizwtve6v93tfpmbq06cu"); // 	yytype_int16 *yyss1 = yyss;
UNSUPPORTED("6kjwclkp9xma7gvqfp0g5v0o1"); // 	union yyalloc *yyptr =
UNSUPPORTED("3qskr4yclsahj4ier4leil4dm"); // 	  (union yyalloc *) malloc (((yystacksize) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) + (sizeof (union yyalloc) - 1)));
UNSUPPORTED("34qleckicraurrnbukjcrgonl"); // 	if (! yyptr)
UNSUPPORTED("8rt03qxk4s7zcewhu9gjlvwfn"); // 	  goto yyexhaustedlab;
UNSUPPORTED("5lfskp4hg9damhy7dk6v1ypr8"); // 	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyss_alloc)[yyi] = (yyss)[yyi]; } while ((0)); yyss = &yyptr->yyss_alloc; yynewbytes = yystacksize * sizeof (*yyss) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));
UNSUPPORTED("df5ph3w93ni5ifz7znmwh2w3a"); // 	do { unsigned int yynewbytes; do { unsigned int yyi; for (yyi = 0; yyi < (yysize); yyi++) (&yyptr->yyvs_alloc)[yyi] = (yyvs)[yyi]; } while ((0)); yyvs = &yyptr->yyvs_alloc; yynewbytes = yystacksize * sizeof (*yyvs) + (sizeof (union yyalloc) - 1); yyptr += yynewbytes / sizeof (*yyptr); } while ((0));
UNSUPPORTED("3y5wxnh21auk2usfoajv43y1k"); // 	if (yyss1 != yyssa)
UNSUPPORTED("ewhwt0puq4prsa4csu3agdltp"); // 	  free (yyss1);
UNSUPPORTED("dquo3qofk56ds5xl95lhvcthf"); //       }
UNSUPPORTED("f2pnjh52uf3jivu6xtmu1ubb0"); //       yyssp = yyss + yysize - 1;
UNSUPPORTED("dtcliy1g46kqfujpfosyu4wz4"); //       yyvsp = yyvs + yysize - 1;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("5fttfrirw536vu8kehb2voeql"); //       if (yyss + yystacksize - 1 <= yyssp)
UNSUPPORTED("am10j8773h9xy42gz4l87tvut"); // 	goto yyabortlab;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("aqbe225x29rzykimfa9madxhl"); //   if (yystate == 31)
UNSUPPORTED("2s4c4zxmqpg8f41cf52q11hn2"); //     goto yyacceptlab;
UNSUPPORTED("16s1l456bx80zdf87xqnqq1m7"); //   goto yybackup;
UNSUPPORTED("1js0t0ytcx8ywvz9tsx2kc95p"); // /*-----------.
UNSUPPORTED("8ydoveifd0u2zarzinfbv2mcs"); // | yybackup.  |
UNSUPPORTED("dbmfwil8k8aqwvx0qac9r5n48"); // `-----------*/
UNSUPPORTED("blf4pkg8pdjsi0tr7900g42pu"); // yybackup:
UNSUPPORTED("6yzm6oy5bmq3akecjcji6mxyb"); //   /* Do appropriate processing given the current state.  Read a
UNSUPPORTED("3plrzglhiw3koxy90giytgoee"); //      lookahead token if we need one and don't already have one.  */
UNSUPPORTED("cbfd87dteogvv9rjyncz9jnkm"); //   /* First try to decide what to do without reference to lookahead token.  */
UNSUPPORTED("d4kp3a274os58vujea556wr7c"); //   yyn = yypact[yystate];
UNSUPPORTED("a47gs6dvu5wmwnxc6mtepl7b2"); //   if (((yyn) == (-82)))
UNSUPPORTED("3fmgyft4gr6wfphigrb3jvrzq"); //     goto yydefault;
UNSUPPORTED("46jyau3ggxbt5nfv3rhpd6lxc"); //   /* Not known => get a lookahead token if don't already have one.  */
UNSUPPORTED("bax3bsy3o04vppl5jub837tlx"); //   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
UNSUPPORTED("3fzj8g0a8bf26gibx654z00mi"); //   if (yychar == (-2))
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("ca2sfn8c9d99bizyfbelhuyd5"); //       yychar = yylex ();
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bwxh0nxiyjroh5agrbyz3kxt1"); //   if (yychar <= 0)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("9yhwy8a16schyp3gns3dfjxlx"); //       yychar = yytoken = 0;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("2e9rne2ydt5whdza1irirvsv6"); //       yytoken = ((unsigned int) (yychar) <= 295 ? yytranslate[yychar] : 2);
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7lmyp30l6y4v0glydzcrxhs2d"); //   /* If the proper action on seeing token YYTOKEN is to reduce or to
UNSUPPORTED("b7crt9is4hw3fqusq1xx9sf6a"); //      detect an error, take that action.  */
UNSUPPORTED("4in4os01kde6b0djzao9gs7oy"); //   yyn += yytoken;
UNSUPPORTED("d2h6buenzt07v61hv7cxv9c6u"); //   if (yyn < 0 || 271 < yyn || yycheck[yyn] != yytoken)
UNSUPPORTED("3fmgyft4gr6wfphigrb3jvrzq"); //     goto yydefault;
UNSUPPORTED("81lmf51yxrv6xlwbpzxiy6lnd"); //   yyn = yytable[yyn];
UNSUPPORTED("8hdfgl90wbtvfaw1fgn0quf2t"); //   if (yyn <= 0)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("6mbeksrzh2gawgu5dkavj2est"); //       if ((0))
UNSUPPORTED("8zxmh2oycvsns4p6zsq690jz5"); //         goto yyerrlab;
UNSUPPORTED("5k4kf1gjxdqx3fcyrvgr7oueb"); //       yyn = -yyn;
UNSUPPORTED("b2ubjdjd6gwlcu0nmv2mk2zrx"); //       goto yyreduce;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6m1h8vs57mr1pqnti7d1p21zm"); //   /* Count tokens shifted since error; after three, turn off error
UNSUPPORTED("71k349r438nfbibdaenrctckz"); //      status.  */
UNSUPPORTED("1nwqsayw0ogig9j8u9pl83uf9"); //   if (yyerrstatus)
UNSUPPORTED("281kcss36kmwi4ogfxfs8lni7"); //     yyerrstatus--;
UNSUPPORTED("bg4fkvjteodqrz0juw1viqqjp"); //   /* Shift the lookahead token.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("vmreafe95a9c5qif2txdddol"); //   /* Discard the shifted token.  */
UNSUPPORTED("7kjg2gi4l12wc5k9x58zpfono"); //   yychar = (-2);
UNSUPPORTED("4sw9jayz05xpsc2hc4128mpt9"); //   yystate = yyn;
UNSUPPORTED("dqkpgoae3twion4t14photdkh"); //   *++yyvsp = yylval;
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("52wvjbtwrbu5hxceg6pcdel69"); // /*-----------------------------------------------------------.
UNSUPPORTED("ah2pnhtd1w6vcf81w55ms3jlq"); // | yydefault -- do the default action for the current state.  |
UNSUPPORTED("9hhkvyvbwlemtn3h1klxkqvhu"); // `-----------------------------------------------------------*/
UNSUPPORTED("6tnzvb6g2e5qv3l2lmumev8xt"); // yydefault:
UNSUPPORTED("e4sfm76r6iqywirgkml8i54v4"); //   yyn = yydefact[yystate];
UNSUPPORTED("94c6edlw2m6fjrujc8g6q812t"); //   if (yyn == 0)
UNSUPPORTED("drlqcn07i3xq2agzwe6hu7oxd"); //     goto yyerrlab;
UNSUPPORTED("cn1kd5p4cr0ll8sj11kitg3rt"); //   goto yyreduce;
UNSUPPORTED("e719ikbjilezocbt4m9kwl59z"); // /*-----------------------------.
UNSUPPORTED("bzo9wknoprssg2zk1whgwcmml"); // | yyreduce -- Do a reduction.  |
UNSUPPORTED("22xw21uiel1yqgh9ekbbt357t"); // `-----------------------------*/
UNSUPPORTED("60ilp1j1ms5ef31o9q556t1ob"); // yyreduce:
UNSUPPORTED("6b8rp07vnvxb5qdulsmksjblt"); //   /* yyn is the number of a rule to reduce with.  */
UNSUPPORTED("329u717rvw0xuxfcgvptopun5"); //   yylen = yyr2[yyn];
UNSUPPORTED("1xow6gk24a2ai9mxr7uo7ja67"); //   /* If YYLEN is nonzero, implement the default value of the action:
UNSUPPORTED("2hk39ofhzlvc0dwqdyy9u0vqb"); //      `$$ = $1'.
UNSUPPORTED("z0dyb7fx7wbongcqyjgkdi93"); //      Otherwise, the following line sets YYVAL to garbage.
UNSUPPORTED("9bj8xv378tepxxvoutf7s2jey"); //      This behavior is undocumented and Bison
UNSUPPORTED("cxdh1gg9j5jy0oknt01shgx43"); //      users should not rely upon it.  Assigning to YYVAL
UNSUPPORTED("d2ax79vvmf62r51efz5v31h1f"); //      unconditionally makes the parser a bit smaller, and it avoids a
UNSUPPORTED("jctvjfbzk1f2q35vsx7olb4"); //      GCC warning that YYVAL may be used uninitialized.  */
UNSUPPORTED("e9b07am7pqcwiww0i1rq4nc70"); //   yyval = yyvsp[1-yylen];
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("nputzf5og4rmodhrmks0mqk6"); //   switch (yyn)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("7ywtj1dc9qm2wgh1sjqw8bog0"); //         case 2:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6hc00xdywmr0j4vvvwj9t8ojg"); //     { HTMLstate.lbl = mkLabel((yyvsp[(2) - (3)].txt),2); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("4b2fuxeeiy5560zrwr84bw997"); //   case 3:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("af1zwcnp1uvtqr9rkx4vc7oix"); //     { HTMLstate.lbl = mkLabel((yyvsp[(2) - (3)].tbl),1); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9o9wpnyoqhlymcmbfbx4eoii3"); //   case 4:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6r55goh04f90zvnb6ibuvmih9"); //     { cleanup(); goto yyabortlab; }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2l9i1e6ufz8i61ksw5x2douj"); //   case 5:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("csx6zga5bvckqvhof9ccp4zlb"); //     { (yyval.txt) = mkText(); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("aq0mcxx5aqy1tk410oeaicrz"); //   case 8:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8z66z0w2o50jn2ov9ttch7d4n"); //     { appendFItemList(HTMLstate.str);}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3fjp05wa4on3vfha31n5uf9c3"); //   case 9:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("cjkrt6jc0aeqw8uogtv21svtv"); //     {appendFLineList((yyvsp[(1) - (1)].i));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("4wkftacr8qkkw7lq6winsirev"); //   case 18:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("e8rlv1js84jhlc5ycq1ljqqni"); //     { pushFont ((yyvsp[(1) - (1)].font)); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("btnbf68hd81l8x43edgngqkn4"); //   case 19:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("90nfzt90tr98p02wpfyghsiu"); //     { popFont (); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("6b3z3u3dqncd4foiz9f4il304"); //   case 20:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("epqpoh4lzr1gr3b0h7lv6suoj"); //   case 21:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9f8ykijwy76c3vifbbpux0n4y"); //   case 22:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("csxcbt7njg0z17ocb9bzv53w9"); //   case 23:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("90jn0veof2gkokrhklmj2yng4"); //   case 24:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("a1zicssxikyxg7770ja6oi1qo"); //   case 25:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("91777erp91zdakf2rq4nhm80d"); //   case 26:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("10s9wf75pcu4xgky3vzfov0rr"); //   case 27:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("1pcg7jpxjlrxymtxnqe2n0omu"); //   case 28:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2y6jol0ugwkre8ty8azrihcw8"); //   case 29:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3n69l4nxtlpullf9g4klblcml"); //   case 30:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2z2j2xsio9grsk7azwojofq1a"); //   case 31:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("dgjfss93xjj8va3zpzsmwsc7s"); //   case 32:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3v81n77b1jezcbk3enzrnqn3f"); //     {pushFont((yyvsp[(1) - (1)].font));}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9y3ycu2dl1ja9jadl9mg7jk67"); //   case 33:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1f2vasoxz080ueipaaxp22ppm"); //     {popFont();}
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("esz4cbak5l686zq9r9zbi7yx5"); //   case 34:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("24ijtkmh6zrwmek4abzzw7l86"); //     { (yyval.i) = (yyvsp[(1) - (2)].i); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("eestp885g0ixxylrl2yz4l4jk"); //   case 35:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7jyhs12v4ygigqo1yj2y0orbo"); //     { (yyval.i) = (yyvsp[(1) - (1)].i); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("av4z5qte05unsmsl8oy2jw5wh"); //   case 38:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("37vabglvl5ih3c2yuds3fywqz"); //     { 
UNSUPPORTED("ewpf9i8j025kajqhi528c19ql"); //           if (nonSpace((((((HTMLstate.str)->ptr >= (HTMLstate.str)->eptr) ? agxbmore(HTMLstate.str,1) : 0), (int)(*(HTMLstate.str)->ptr++ = ((unsigned char)'\0'))),(char*)((HTMLstate.str)->ptr = (HTMLstate.str)->buf)))) {
UNSUPPORTED("e94hzxtl91n44btslbv6te1ry"); //             yyerror ("Syntax error: non-space string used before <TABLE>");
UNSUPPORTED("dh11jthr8n4cz6lk1mbgcl27j"); //             cleanup(); goto yyabortlab;
UNSUPPORTED("4v3ujrl58y59e7pqk0ke5t564"); //           }
UNSUPPORTED("95zuxlwp9zcuou0y11mqdib2a"); //           (yyvsp[(2) - (2)].tbl)->u.p.prev = HTMLstate.tblstack;
UNSUPPORTED("4wk4w04j4wb9ql94m1bd3kivb"); //           (yyvsp[(2) - (2)].tbl)->u.p.rows = dtopen(&rowDisc, Dtqueue);
UNSUPPORTED("1tj6xrj3lyw2jtox9t6dbssp8"); //           HTMLstate.tblstack = (yyvsp[(2) - (2)].tbl);
UNSUPPORTED("11cbtl4a2eoux3fp7q47qeom7"); //           (yyvsp[(2) - (2)].tbl)->font = HTMLstate.fontstack->cfont;
UNSUPPORTED("3dpok2xgf4aunmlv45k3hg3ms"); //           (yyval.tbl) = (yyvsp[(2) - (2)].tbl);
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("clipffhxj206f2zoz5tskxfso"); //   case 39:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("ewpf9i8j025kajqhi528c19ql"); //           if (nonSpace((((((HTMLstate.str)->ptr >= (HTMLstate.str)->eptr) ? agxbmore(HTMLstate.str,1) : 0), (int)(*(HTMLstate.str)->ptr++ = ((unsigned char)'\0'))),(char*)((HTMLstate.str)->ptr = (HTMLstate.str)->buf)))) {
UNSUPPORTED("54scxlgpkdnq3enyns1pamgrc"); //             yyerror ("Syntax error: non-space string used after </TABLE>");
UNSUPPORTED("dh11jthr8n4cz6lk1mbgcl27j"); //             cleanup(); goto yyabortlab;
UNSUPPORTED("4v3ujrl58y59e7pqk0ke5t564"); //           }
UNSUPPORTED("a40yrjq3rp7lwposkv2tr5b2v"); //           (yyval.tbl) = HTMLstate.tblstack;
UNSUPPORTED("186brzy420t3w4it4fgx6ijl8"); //           HTMLstate.tblstack = HTMLstate.tblstack->u.p.prev;
UNSUPPORTED("4mhlpjofolwivhm0tl8cxznly"); //         }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("508xojiq76e68ysea7ccx0988"); //   case 40:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7k9f3nhc81ein6inl8nyn1ovz"); //     { (yyval.tbl) = (yyvsp[(1) - (1)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("707q21176uh540icjdkmho8lp"); //   case 41:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8izta614ccg329bjmnn6lgk25"); //     { (yyval.tbl)=(yyvsp[(2) - (3)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("afkusc5gt7341vg6q20kyt3r0"); //   case 42:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8izta614ccg329bjmnn6lgk25"); //     { (yyval.tbl)=(yyvsp[(2) - (3)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("aw1w7mfmqa9ga8wr6x4u6nbju"); //   case 43:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8izta614ccg329bjmnn6lgk25"); //     { (yyval.tbl)=(yyvsp[(2) - (3)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("alyqwgnskt6d6wilhbz1voo06"); //   case 44:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8izta614ccg329bjmnn6lgk25"); //     { (yyval.tbl)=(yyvsp[(2) - (3)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("23po4ixywlwb8futv80yuc377"); //   case 45:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("8izta614ccg329bjmnn6lgk25"); //     { (yyval.tbl)=(yyvsp[(2) - (3)].tbl); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("co51vw9d73gymlc8231s1jobg"); //   case 48:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("cyj4zpm50sbuzb94nigcz9s4b"); //     { (yyval.p) = (yyvsp[(1) - (1)].p); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("3gd6s52j3cevgz1ud9ys8mmpu"); //   case 49:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("alvnoh83tddfqap6yw3489hsl"); //     { (yyval.p) = (yyvsp[(2) - (2)].p); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("4hiji17koy9b0nvi4qcb7f0yn"); //   case 50:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("eta2enlygrb8t6bmtsn4xnw7"); //     { (yyvsp[(1) - (3)].p)->ruled = 1; (yyval.p) = (yyvsp[(3) - (3)].p); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("605ei0ilu3nz1gtra52oi7mz3"); //   case 51:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("2yogfcs5uhf5ebch8wotuiuoc"); //     { addRow (); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("9qbtgt2eyxxuukc88ljehppv1"); //   case 52:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("f1v8u3yozj5akwkxqcr2kj7ug"); //     { (yyval.p) = lastRow(); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("a5l2sixwhiv4x59rzexutoo1"); //   case 53:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("dy7dmbb9yo9sm1xj3rethzq2y"); //     { (yyval.cell) = (yyvsp[(1) - (1)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("d9qqg2poxec5i2gk2tlzjceze"); //   case 54:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("39exi4ppmhsf7kzimai5sui89"); //     { (yyval.cell) = (yyvsp[(2) - (2)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("19bjcrzc7duy98u3gs54bkn75"); //   case 55:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3p8ycl98b5je4z5wfll4mkn69"); //     { (yyvsp[(1) - (3)].cell)->ruled |= 1; (yyval.cell) = (yyvsp[(3) - (3)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("67uutyij1gj1990fya85n5ky9"); //   case 56:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("1mdy0edf3z2e4lzjhpocw2eb2"); //     { setCell((yyvsp[(1) - (2)].cell),(yyvsp[(2) - (2)].tbl),1); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("959w7yr2dhhobu7nk3tnemg3n"); //   case 57:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7eciu07btwmircvweu5lvydl1"); //     { (yyval.cell) = (yyvsp[(1) - (4)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("p7d04q56jydruu4g4mkcl0sv"); //   case 58:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("6uakmfqawie6xmt69vvphz7s2"); //     { setCell((yyvsp[(1) - (2)].cell),(yyvsp[(2) - (2)].txt),2); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("2e8vk62ndof1wckppsf3h1s08"); //   case 59:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7eciu07btwmircvweu5lvydl1"); //     { (yyval.cell) = (yyvsp[(1) - (4)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("datyn4rldj3j181mig7lm4p15"); //   case 60:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("3raerxybjs31c79rluhwor4pm"); //     { setCell((yyvsp[(1) - (2)].cell),(yyvsp[(2) - (2)].img),3); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("arwsoeo1a8oc675m9cdqjutkj"); //   case 61:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7eciu07btwmircvweu5lvydl1"); //     { (yyval.cell) = (yyvsp[(1) - (4)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("dvs3metp9y50zqp24wirfa2mt"); //   case 62:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("2sqdk1ca8bhu3z3dud8h0wykv"); //     { setCell((yyvsp[(1) - (1)].cell),mkText(),2); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("bumsxvl14bzsf1d8ynzopdhvp"); //   case 63:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("2lkcphnuqrfrofjhup7r9j5mq"); //     { (yyval.cell) = (yyvsp[(1) - (3)].cell); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("cif7nn92zrlfslvnv5c4lpoku"); //   case 64:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("7x60h4389wcyhcudy6nqbx1tw"); //     { (yyval.img) = (yyvsp[(1) - (2)].img); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("dxemu7derx72r4fpo6fzfantn"); //   case 65:
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("dtc9j8wtmuvx8e4q2g0slnbt2"); //     { (yyval.img) = (yyvsp[(1) - (1)].img); }
UNSUPPORTED("8ofzhd1f1qc2gz9hfk7vzz6ox"); //     break;
UNSUPPORTED("8sch3zvqi27y4ab9h9s76ge3l"); // /* Line 1787 of yacc.c  */
UNSUPPORTED("dlej2d1ppih1bnw53vhocc61k"); //       default: break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5cqll1f6ifjhnf5kjarx18ld7"); //   /* User semantic actions sometimes alter yychar, and that requires
UNSUPPORTED("awngk7ukt8o0iti5qo4bas9qu"); //      that yytoken be updated with the new translation.  We take the
UNSUPPORTED("3ylmmve1iqs603x0j5nwz4f7t"); //      approach of translating immediately before every use of yytoken.
UNSUPPORTED("5egmt4bmrda5rwmq0fxaut100"); //      One alternative is translating here after every semantic action,
UNSUPPORTED("cbfgp6r4p0aww4ln7e4wjq5rg"); //      but that translation would be missed if the semantic action invokes
UNSUPPORTED("5e50914xh0fwl1xezevm21gnp"); //      YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
UNSUPPORTED("c4u72wy240sife8xvhjcdf3y"); //      if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
UNSUPPORTED("9oqy8bmho7vno5ewpwljpvk7k"); //      incorrect destructor might then be invoked immediately.  In the
UNSUPPORTED("2dm4du9w60sge1uyx4vrwgtuv"); //      case of YYERROR or YYBACKUP, subsequent parser actions might lead
UNSUPPORTED("55ajnkklldzargdu2v7xxw8jh"); //      to an incorrect destructor call or verbose syntax error message
UNSUPPORTED("2w6gaiusmvs9119tusfj7wmgn"); //      before the lookahead is translated.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("8vm93a8434d8sy5ft2p0ffy2f"); //   yylen = 0;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("cmccd42l0im45m3od0igu34al"); //   *++yyvsp = yyval;
UNSUPPORTED("8zf4hex7pjvkzs6628u0usoop"); //   /* Now `shift' the result of the reduction.  Determine what state
UNSUPPORTED("9p956m8qfuj78tnsyhxtvs3t4"); //      that goes to, based on the state we popped back to and the rule
UNSUPPORTED("2sr0m6m0qte5wg0zclc83vtln"); //      number reduced by.  */
UNSUPPORTED("3j26tpego5wkr3i7sxhi0vlfi"); //   yyn = yyr1[yyn];
UNSUPPORTED("95dmft79gf55xzk4kyehyfpjx"); //   yystate = yypgoto[yyn - 41] + *yyssp;
UNSUPPORTED("2uoufancdr7a5bqxxh3jkawgd"); //   if (0 <= yystate && yystate <= 271 && yycheck[yystate] == *yyssp)
UNSUPPORTED("qmyvkodfobpxzeqpbyt6bqds"); //     yystate = yytable[yystate];
UNSUPPORTED("8983svt6g1kt3l45bd6ju9mw6"); //   else
UNSUPPORTED("evvp4dfdjqirf5de0pquv5pkm"); //     yystate = yydefgoto[yyn - 41];
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("brpyacmu3j2c5b5b57c44c6xg"); // /*------------------------------------.
UNSUPPORTED("dm7tq63p22rwn6r638bg01ste"); // | yyerrlab -- here on detecting error |
UNSUPPORTED("46kmo9tkqrq2trhedjhrmq5iu"); // `------------------------------------*/
UNSUPPORTED("2i48je78o7b125ljlmo3rrrn9"); // yyerrlab:
UNSUPPORTED("6pctfudiscetk242w9vfsytui"); //   /* Make sure we have latest lookahead translation.  See comments at
UNSUPPORTED("9z8lh3976ui2i6adwx4bu8xtu"); //      user semantic actions for why this is necessary.  */
UNSUPPORTED("bwa3vofs66y2wx51oirvg6d64"); //   yytoken = yychar == (-2) ? (-2) : ((unsigned int) (yychar) <= 295 ? yytranslate[yychar] : 2);
UNSUPPORTED("4yyok9q9sqmbmxchbquk9rz3a"); //   /* If not already recovering from an error, report this error.  */
UNSUPPORTED("5tzevilbik2gtdm8eme1d0rr0"); //   if (!yyerrstatus)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("nbgtjj315e9erfjw1966r1nj"); //       ++yynerrs;
UNSUPPORTED("6dvzyrcoug25gdlx878gfncgd"); //       yyerror ("syntax error");
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("55ts2vdfkuwiduyrxm4dthuge"); //   if (yyerrstatus == 3)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("3jyg22xuaw01ib5n6y8iv3xxr"); //       /* If just tried and failed to reuse lookahead token after an
UNSUPPORTED("4zj2myg3clgam20xdvt28usk8"); // 	 error, discard it.  */
UNSUPPORTED("7syst9kqcdmgefgn9sa5pf7o5"); //       if (yychar <= 0)
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("ps0ydhmk8cvulxq94uiebnl3"); // 	  /* Return failure if at end of input.  */
UNSUPPORTED("cx3jo1wzpr0xulijxy2hr6sc6"); // 	  if (yychar == 0)
UNSUPPORTED("6yhjuhoaoslhl1mcaltg7q7pg"); // 	    goto yyabortlab;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("e2koj2xocq76awegpydpyu62m"); //       else
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("1jxztkqlg99as0f75qw9zu7hc"); // 	  yydestruct ("Error: discarding",
UNSUPPORTED("d77dp0agmh0vtezh1or0i4739"); // 		      yytoken, &yylval);
UNSUPPORTED("83od8u43ovfv5njq9h6djl0ot"); // 	  yychar = (-2);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cngu0btwjacz5b793e8yvi9m1"); //   /* Else will try to reuse lookahead token after shifting the error
UNSUPPORTED("38vbb7wijegv8on4kj8r2jh3w"); //      token.  */
UNSUPPORTED("erwd0x8o17qppvw1i027q4w8g"); //   goto yyerrlab1;
UNSUPPORTED("6iskxmjpvgrnnac6655f5jk67"); // /*---------------------------------------------------.
UNSUPPORTED("e8wekw8xk8h4ehfscg9thr469"); // | yyerrorlab -- error raised explicitly by YYERROR.  |
UNSUPPORTED("6a0f8547ydra66tf81ssie9pn"); // `---------------------------------------------------*/
UNSUPPORTED("6sqgsf1ikylmv5xu2vnzb6zfh"); // yyerrorlab:
UNSUPPORTED("skx5cc7fpyqelhc1lbzwq6gy"); //   /* Pacify compilers like GCC when the user code never invokes
UNSUPPORTED("61aw8i7lhhk5dco9iriz40sew"); //      YYERROR and the label yyerrorlab therefore never appears in user
UNSUPPORTED("2cx96j1h5f1sf0pyotl6w1g31"); //      code.  */
UNSUPPORTED("9850ib9fy0bgpnxd1mv3rhcl0"); //   if (/*CONSTCOND*/ 0)
UNSUPPORTED("a51kt3zd29fq3lcg3v1ks7u3t"); //      goto yyerrorlab;
UNSUPPORTED("2lhgt1uq3z8cnzed8w920d1og"); //   /* Do not reclaim the symbols of the rule which action triggered
UNSUPPORTED("2qdujvpg7me3yjqefsbmb4nbl"); //      this YYERROR.  */
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("8vm93a8434d8sy5ft2p0ffy2f"); //   yylen = 0;
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("zhrklmvb28eknyhrgi1sl42m"); //   yystate = *yyssp;
UNSUPPORTED("erwd0x8o17qppvw1i027q4w8g"); //   goto yyerrlab1;
UNSUPPORTED("a9uzsnursnm07o2p12lh2sbdg"); // /*-------------------------------------------------------------.
UNSUPPORTED("d5bdojxx2qhdavmglrnnu20wq"); // | yyerrlab1 -- common code for both syntax error and YYERROR.  |
UNSUPPORTED("cinw8ra05yfs6jshwnk7uer8g"); // `-------------------------------------------------------------*/
UNSUPPORTED("4a99tboc4ge220j5k0q7kkcv8"); // yyerrlab1:
UNSUPPORTED("4q9jx23t3a7q78efzc3hplezr"); //   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
UNSUPPORTED("9qdgu2bhbvj6h80iki9hjhpcx"); //   for (;;)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("7h162nbw1l50eoity8vl8vlfx"); //       yyn = yypact[yystate];
UNSUPPORTED("chnx967ebmovspkelngnq4ekr"); //       if (!((yyn) == (-82)))
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("2cb0b601jdhr7ao1k7uedmqp4"); // 	  yyn += 1;
UNSUPPORTED("cnqog3y050erwngnmuavj6riq"); // 	  if (0 <= yyn && yyn <= 271 && yycheck[yyn] == 1)
UNSUPPORTED("6dbei3uox5ql5a1vaaguh0xzp"); // 	    {
UNSUPPORTED("3h7enjuboh25u2w9uv7n20zdp"); // 	      yyn = yytable[yyn];
UNSUPPORTED("929wghuvx3qqaljlqay2r0qox"); // 	      if (0 < yyn)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("1nekbbuf2scf8o8o56p3e2btr"); //       /* Pop the current state because it cannot handle the error token.  */
UNSUPPORTED("4ku603ttm915jqijkt8jfdtur"); //       if (yyssp == yyss)
UNSUPPORTED("am10j8773h9xy42gz4l87tvut"); // 	goto yyabortlab;
UNSUPPORTED("b8z1x6wup2pyz9pk8yo2f7mly"); //       yydestruct ("Error: popping",
UNSUPPORTED("3xxknhj7rdvwd70kls6v0sjlv"); // 		  yystos[yystate], yyvsp);
UNSUPPORTED("do23hvgct6rw0i2id4p6c8w3w"); //       (yyvsp -= (1), yyssp -= (1));
UNSUPPORTED("aa9r4mny7kfvlswoajt6ewiua"); //       yystate = *yyssp;
UNSUPPORTED("3ejmh10g3kyn79v59obt4uwve"); //       ;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dqkpgoae3twion4t14photdkh"); //   *++yyvsp = yylval;
UNSUPPORTED("1bunp144fpibi7v7rbgn16l6l"); //   /* Shift the error token.  */
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("4sw9jayz05xpsc2hc4128mpt9"); //   yystate = yyn;
UNSUPPORTED("6nvi85ih8317wifajbvg2pqs2"); //   goto yynewstate;
UNSUPPORTED("179qxptpyl5068065s1ai8g3c"); // /*-------------------------------------.
UNSUPPORTED("anl6cgk1tm199ldzxzf8s1bh3"); // | yyacceptlab -- YYACCEPT comes here.  |
UNSUPPORTED("2bvn7c0u1oq31d3b0uk6m3tdy"); // `-------------------------------------*/
UNSUPPORTED("cbzrzcwa3d2vc6ordo6oj3xko"); // yyacceptlab:
UNSUPPORTED("5vzqjwd5x1qujng4k6z6tpi2o"); //   yyresult = 0;
UNSUPPORTED("9rhxz7vhxa5rm8e3p37nc24b0"); //   goto yyreturn;
UNSUPPORTED("8p4f508auqnz4koon32xrgqkm"); // /*-----------------------------------.
UNSUPPORTED("28nb5q4v0xxkeavz1lxebk5k6"); // | yyabortlab -- YYABORT comes here.  |
UNSUPPORTED("6p3zuxhtllqujwb6275y1iuol"); // `-----------------------------------*/
UNSUPPORTED("cs5upc0kvptz7pahmh8s1dhr7"); // yyabortlab:
UNSUPPORTED("dxco1j9c6ug5tilavyzolvj1v"); //   yyresult = 1;
UNSUPPORTED("9rhxz7vhxa5rm8e3p37nc24b0"); //   goto yyreturn;
UNSUPPORTED("1visspreqlkrsxbrmmtajzyi0"); // /*-------------------------------------------------.
UNSUPPORTED("29by7a2oedt1hazfly96vjurq"); // | yyexhaustedlab -- memory exhaustion comes here.  |
UNSUPPORTED("3zfwm8se9uqcr4uczanjlo4wx"); // `-------------------------------------------------*/
UNSUPPORTED("b2ygf3uu6p4g9r7tgaohy1240"); // yyexhaustedlab:
UNSUPPORTED("4ytx7di4prwazpscx8x0vbo8v"); //   yyerror ("memory exhausted");
UNSUPPORTED("e012l6rqiz3pyhp7p2yfh67zu"); //   yyresult = 2;
UNSUPPORTED("50117q88lfg743xhieoyg9dtb"); //   /* Fall through.  */
UNSUPPORTED("3ddyjbtqzdtjsfqcfj6zddwmj"); // yyreturn:
UNSUPPORTED("9nwvriowi4mgw93nqdwsg3h3y"); //   if (yychar != (-2))
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("1yvk3imqcd71tq0dg520dalwv"); //       /* Make sure we have latest lookahead translation.  See comments at
UNSUPPORTED("8f533hh53bahoyrmc8vumq0er"); //          user semantic actions for why this is necessary.  */
UNSUPPORTED("2e9rne2ydt5whdza1irirvsv6"); //       yytoken = ((unsigned int) (yychar) <= 295 ? yytranslate[yychar] : 2);
UNSUPPORTED("bw1xk28c88hsn48guw3wtxcny"); //       yydestruct ("Cleanup: discarding lookahead",
UNSUPPORTED("8q59rkbmrhyjxo0in0tysc9d3"); //                   yytoken, &yylval);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2lhgt1uq3z8cnzed8w920d1og"); //   /* Do not reclaim the symbols of the rule which action triggered
UNSUPPORTED("brvt6wka5tijolvbute9f9vjy"); //      this YYABORT or YYACCEPT.  */
UNSUPPORTED("8x7gb1igulyb30k4h1wip0jbw"); //   (yyvsp -= (yylen), yyssp -= (yylen));
UNSUPPORTED("3nswekisilyfverb25pazm044"); //   ;
UNSUPPORTED("4ek9gfkq4rqe58yqa7yp7n4wf"); //   while (yyssp != yyss)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("d0tynwjettp1otc13e09xap0g"); //       yydestruct ("Cleanup: popping",
UNSUPPORTED("7buci8ktyvgwlnzitin2vcnzb"); // 		  yystos[*yyssp], yyvsp);
UNSUPPORTED("do23hvgct6rw0i2id4p6c8w3w"); //       (yyvsp -= (1), yyssp -= (1));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dt668kats752ezjns7gbcqbm"); //   if (yyss != yyssa)
UNSUPPORTED("3zst4dfy8kmamfritmsl2bgld"); //     free (yyss);
UNSUPPORTED("96m641qde7y8nrj81kip0kdli"); //   /* Make sure YYID is used.  */
UNSUPPORTED("czgny8i6sq1w5i986hse6937y"); //   return (yyresult);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2azjwpo04yf3bsb9gidbw3i4x
// htmllabel_t* parseHTML (char* txt, int* warn, htmlenv_t *env) 
public static Object parseHTML(Object... arg) {
UNSUPPORTED("226x3zxbn3f7kzhqucskm0uoq"); // htmllabel_t*
UNSUPPORTED("8cvtnulc9n3wdvcnyz42lwhzy"); // parseHTML (char* txt, int* warn, htmlenv_t *env)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("63meyud67rookn7jurut0266j"); //   unsigned char buf[128];
UNSUPPORTED("5kki2fqr7sc6h70wuy48nmwoz"); //   agxbuf        str;
UNSUPPORTED("151zh677cirxjroyz07ylg4qu"); //   htmllabel_t*  l;
UNSUPPORTED("ip3d7wcpkp2cvqvcytoydu0c"); //   sfont_t       dfltf;
UNSUPPORTED("bnowsob1rpic47r9qahesp5z9"); //   dfltf.cfont = NULL;
UNSUPPORTED("1qchcbo1e5aphcn9agydjwpur"); //   dfltf.pfont = NULL;
UNSUPPORTED("bf7yeekp5lae3g14li808nkom"); //   HTMLstate.fontstack = &dfltf;
UNSUPPORTED("97wdd3n2my59w2bi1alxtx7gl"); //   HTMLstate.tblstack = 0;
UNSUPPORTED("5942cc6lkx6yzhwmdaojw2kg4"); //   HTMLstate.lbl = 0;
UNSUPPORTED("3fpf8hxu4jf37tofuik9m4l1i"); //   HTMLstate.gvc = GD_gvc(env->g);
UNSUPPORTED("avdl29glu77okugd20p4ev32l"); //   HTMLstate.fitemList = dtopen(&fstrDisc, Dtqueue);
UNSUPPORTED("e2bulyqtlb1ygl39ntnk15fgp"); //   HTMLstate.fspanList = dtopen(&fspanDisc, Dtqueue);
UNSUPPORTED("67g016u4kj6rhoy4ltearmu5f"); //   agxbinit (&str, 128, buf);
UNSUPPORTED("6qe9sv6fwllra61m6ze3qcdml"); //   HTMLstate.str = &str;
UNSUPPORTED("79h006ssg3lcsf0nzr3jmeear"); //   if (initHTMLlexer (txt, &str, env)) {/* failed: no libexpat - give up */
UNSUPPORTED("cf2n9mlnm2nlhfvofhkylf8lu"); //     *warn = 2;
UNSUPPORTED("8vl68pdd939xriomclc4lhjbd"); //     l = NULL;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("e3wc96h4r8zbmwy1sdt30ax31"); //   else {
UNSUPPORTED("4jcbfj1drq48ao0s6es5r6moo"); //     yyparse();
UNSUPPORTED("1ts3x58vf766fgbehwhtqjre6"); //     *warn = clearHTMLlexer ();
UNSUPPORTED("41cqw8kpgh69hd6d7ljh2vi8x"); //     l = HTMLstate.lbl;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("4slkyw4zzk5uohd8pvfbzzogm"); //   dtclose (HTMLstate.fitemList);
UNSUPPORTED("79tfoea2y63wx0wpq88o2sgx1"); //   dtclose (HTMLstate.fspanList);
UNSUPPORTED("9w2nanryjis49dz84vnpnvcdb"); //   HTMLstate.fitemList = NULL;
UNSUPPORTED("83u1p988zjx0anlxa62ac2704"); //   HTMLstate.fspanList = NULL;
UNSUPPORTED("2z66fvlnqunk5hsw63l7pvdb0"); //   HTMLstate.fontstack = NULL;
UNSUPPORTED("3pycv6y7tnm4uu44fp7ut5yma"); //   agxbfree (&str);
UNSUPPORTED("29x14oexykxrkgq9s3x6kssi1"); //   return l;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
