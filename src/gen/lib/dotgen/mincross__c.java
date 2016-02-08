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
package gen.lib.dotgen;
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

public class mincross__c {
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




//3 7ye0tsa8kll1jntdcqzsgjp0q
// static int gd_minrank(Agraph_t *g) 
public static Object gd_minrank(Object... arg) {
UNSUPPORTED("7wnr5wvv8mw2d3mfdyvdz5kz9"); // static int gd_minrank(Agraph_t *g) {return GD_minrank(g);}

throw new UnsupportedOperationException();
}




//3 c7dhattawtph3qv1eeoafltk0
// static int gd_maxrank(Agraph_t *g) 
public static Object gd_maxrank(Object... arg) {
UNSUPPORTED("b89n5iyqsgra9z559023bf23e"); // static int gd_maxrank(Agraph_t *g) {return GD_maxrank(g);}

throw new UnsupportedOperationException();
}




//3 8g2can1ih1668s30s6d7wny5b
// static rank_t *gd_rank(Agraph_t *g, int r) 
public static Object gd_rank(Object... arg) {
UNSUPPORTED("bxd4rm18v4y2x6fo30vh9pauo"); // static rank_t *gd_rank(Agraph_t *g, int r) {return &GD_rank(g)[r];}

throw new UnsupportedOperationException();
}




//3 8pjrnrvidhpqcubvkk5lsfp6
// static int nd_order(Agnode_t *v) 
public static Object nd_order(Object... arg) {
UNSUPPORTED("f4zvlmxyp6gei8iiu33hpz4oe"); // static int nd_order(Agnode_t *v) { return ND_order(v); }

throw new UnsupportedOperationException();
}


//1 eusjqny3hma23wvcznk9arpgr
// static int MinQuit
private static int MinQuit;

//1 eykidmlm64erbhaultu3js822
// static double Convergence
private static double Convergence;

//1 f2ssditidb9f1cgp7r1kslp0e
// static graph_t *Root
private static Agraph_s Root;

//1 ager0orj38x5rjuhzv1o2cxuc
// static int GlobalMinRank, GlobalMaxRank
private static int GlobalMinRank, GlobalMaxRank;

//1 dag2n5hcww3ada79u52a8yha6
// static edge_t **TE_list
private static __ptr__ TE_list;

//1 agrg82s0nsmuokh0t3h5q6h90
// static int *TI_list
private static __ptr__ TI_list;

//1 7x0e0qfe96o5elb6lxt8mfmho
// static boolean ReMincross
private static boolean ReMincross;



//3 e876vp4hgkzshluz6qk77cjwk
// void dot_mincross(graph_t * g, int doBalance) 
public static void dot_mincross(Agraph_s g, boolean doBalance) {
ENTERING("e876vp4hgkzshluz6qk77cjwk","dot_mincross");
try {
    int c, nc;
    CString s;
    init_mincross(g);
    for (nc = c = 0; c < GD_comp(g).getInt("size"); c++) {
	init_mccomp(g, c);
	nc += mincross_(g, 0, 2, doBalance);
    }
    merge2(g);
    /* run mincross on contents of each cluster */
    for (c = 1; c <= GD_n_cluster(g); c++) {
	nc += mincross_clust(g, (Agraph_s) GD_clust(g).plus(c).getPtr(), doBalance);
    }
    if ((GD_n_cluster(g) > 0)
	&& (N(s = agget(g, new CString("remincross"))) || (mapbool(s)))) {
	mark_lowclusters(g);
	ReMincross = NOT(0);
	nc = mincross_(g, 2, 2, doBalance);
    }
    cleanup2(g, nc);
} finally {
LEAVING("e876vp4hgkzshluz6qk77cjwk","dot_mincross");
}
}




//3 756bre1tpxb1tq68p7xhkrxkc
// static adjmatrix_t *new_matrix(int i, int j) 
public static adjmatrix_t new_matrix(int i, int j) {
ENTERING("756bre1tpxb1tq68p7xhkrxkc","new_matrix");
try {
 UNSUPPORTED("37r1dlkp6mirsyees58lby3m"); // static adjmatrix_t *new_matrix(int i, int j)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("78iohm462e4fhc71vtbx2hcko"); //     adjmatrix_t *rv = (adjmatrix_t*)zmalloc(sizeof(adjmatrix_t));
UNSUPPORTED("b1jz4smxqpyhxhvybe6ei4h1x"); //     rv->nrows = i;
UNSUPPORTED("1pzlhbyvsknggzt3bjjji7y1c"); //     rv->ncols = j;
UNSUPPORTED("apn1shiflzuyh7giq7f5lul75"); //     rv->data = (char*)zmalloc((i * j)*sizeof(char));
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("756bre1tpxb1tq68p7xhkrxkc","new_matrix");
}
}




//3 1n1e0k0wtlbugwm3cb4na6av6
// static void free_matrix(adjmatrix_t * p) 
public static void free_matrix(adjmatrix_t p) {
ENTERING("1n1e0k0wtlbugwm3cb4na6av6","free_matrix");
try {
    if (p!=null) {
	Memory.free(p.getPtr("data"));
	Memory.free(p);
    }
} finally {
LEAVING("1n1e0k0wtlbugwm3cb4na6av6","free_matrix");
}
}




//3 49vw7fkn99wbojtfksugvuruh
// static void init_mccomp(graph_t * g, int c) 
public static void init_mccomp(Agraph_s g, int c) {
ENTERING("49vw7fkn99wbojtfksugvuruh","init_mccomp");
try {
    int r;
    GD_nlist(g, GD_comp(g).getArray("list").plus(c).getPtr());
    if (c > 0) {
UNSUPPORTED("34zoiglx6i533thnb09wet61g"); // 	for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("d2j00itj7y30o090cs9t0s9ud"); // 	    GD_rank(g)[r].v = GD_rank(g)[r].v + GD_rank(g)[r].n;
UNSUPPORTED("de9su5sye3e0a3pmioywi3fze"); // 	    GD_rank(g)[r].n = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
} finally {
LEAVING("49vw7fkn99wbojtfksugvuruh","init_mccomp");
}
}




//3 72v5zs502m1of3vsofyfo15ap
// static int betweenclust(edge_t * e) 
public static Object betweenclust(Object... arg) {
UNSUPPORTED("6k6r73j7gctt4ntepjubrlfze"); // static int betweenclust(edge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1z9f8ptfggp4qlwv5cdd55i3j"); //     while (ED_to_orig(e))
UNSUPPORTED("bdmai1d040qmubf08ds339v9x"); // 	e = ED_to_orig(e);
UNSUPPORTED("eq2o4v9qo3xx42in97ssadek"); //     return (ND_clust(agtail(e)) != ND_clust(aghead(e)));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 760bwoz4twwy2jr1b32r6zefi
// static void do_ordering_node (graph_t * g, node_t* n, int outflag) 
public static Object do_ordering_node(Object... arg) {
UNSUPPORTED("ajn55zvrzf8njqkshll3kaz88"); // static void do_ordering_node (graph_t * g, node_t* n, int outflag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bp5tdulayknsvyv8a2j2tinh"); //     int i, ne;
UNSUPPORTED("5yrhx4blosxo5xnc1nh1kzhfs"); //     node_t *u, *v;
UNSUPPORTED("9cbk3ly04nbzqoxmmjwptqq9a"); //     edge_t *e, *f, *fe;
UNSUPPORTED("5ol5beitdgh7axwpk35pc9trm"); //     edge_t **sortlist = TE_list;
UNSUPPORTED("aeria2or5qpnnrr9wm15k588l"); //     if (ND_clust(n))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("442hvc4h32o6e3cvzm5y5y3oq"); //     if (outflag) {
UNSUPPORTED("7xi4jdz18dyv740agfh5uwtxv"); // 	for (i = ne = 0; (e = ND_out(n).list[i]); i++)
UNSUPPORTED("24smn55xhvkklh2do2cfcmy98"); // 	    if (!betweenclust(e))
UNSUPPORTED("ouas2w3lk54dwigzgglm3w7r"); // 		sortlist[ne++] = e;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("6dgl0skwzmsi69ugcewc5vwaf"); // 	for (i = ne = 0; (e = ND_in(n).list[i]); i++)
UNSUPPORTED("24smn55xhvkklh2do2cfcmy98"); // 	    if (!betweenclust(e))
UNSUPPORTED("ouas2w3lk54dwigzgglm3w7r"); // 		sortlist[ne++] = e;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("hdnqvw2crdbzt2uenqso4l7k"); //     if (ne <= 1)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("4zkjvsomlyhcl06ummf4gz0d2"); //     /* write null terminator at end of list.
UNSUPPORTED("2zx16rdu8hp86z3z36natgy8t"); //        requires +1 in TE_list alloccation */
UNSUPPORTED("6dp57feioscwstrfmhqhrz1jx"); //     sortlist[ne] = 0;
UNSUPPORTED("4wqnlh6z9lr2xvmjp95nozn84"); //     qsort(sortlist, ne, sizeof(sortlist[0]), (qsort_cmpf) edgeidcmpf);
UNSUPPORTED("d6aia9q03brt8otnyu5m3tlxj"); //     for (ne = 1; (f = sortlist[ne]); ne++) {
UNSUPPORTED("1b9ylnvr8zscovbyrxoe9ypax"); // 	e = sortlist[ne - 1];
UNSUPPORTED("4nbrepm0pmohxxml0csb9j5xc"); // 	if (outflag) {
UNSUPPORTED("2rcn453iomwvou108kjr2rboc"); // 	    u = aghead(e);
UNSUPPORTED("96i3kysq5lfoyukhe65vpiah2"); // 	    v = aghead(f);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("96jttvtco2oqt3y3qr5fbhu1j"); // 	    u = agtail(e);
UNSUPPORTED("8g5mzwux62x43bjzeslylyi0g"); // 	    v = agtail(f);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("a7mygw39shaa9w4l8fdlgqr0i"); // 	if (find_flat_edge(u, v))
UNSUPPORTED("6cprbghvenu9ldc0ez1ifc63q"); // 	    return;
UNSUPPORTED("aoa2embk8eaij29q6nbl4e5tk"); // 	fe = new_virtual_edge(u, v, NULL);
UNSUPPORTED("67t5g8eu9tdqbnwj4s4g6ah6u"); // 	ED_edge_type(fe) = 4;
UNSUPPORTED("b32n066t1nkgj646wvo7vuwlq"); // 	flat_edge(g, fe);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 815nmj2gcomtex4yfclqde12j
// static void do_ordering(graph_t * g, int outflag) 
public static Object do_ordering(Object... arg) {
UNSUPPORTED("9v68euuxlii02rb5mhlyd8alp"); // static void do_ordering(graph_t * g, int outflag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5y5mm5obhrqt745c4fx4o0r56"); //     /* Order all nodes in graph */
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("bicm0b87pp2rusaezmk6qigjq"); // 	do_ordering_node (g, n, outflag);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 svq3i3c6yw3cbfwaeip5dfuy
// static void do_ordering_for_nodes(graph_t * g) 
public static Object do_ordering_for_nodes(Object... arg) {
UNSUPPORTED("7yd9vingwgdcdtrx0p38jti00"); // static void do_ordering_for_nodes(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("887aairlqk73reuayo3hz67v3"); //     /* Order nodes which have the "ordered" attribute */
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("cbbfhy5qk3dailijtedj1czut"); //     const char *ordering;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("ekvbu44bbrdwkw71yd21dbns9"); // 	if ((ordering = late_string(n, N_ordering, NULL))) {
UNSUPPORTED("7jueg5punlemj6mfbpgltb5u8"); // 	    if ((*(ordering)==*("out")&&!strcmp(ordering,"out")))
UNSUPPORTED("302oz5j9wva90otn6jq513bme"); // 		do_ordering_node(g, n, NOT(0));
UNSUPPORTED("1dt1hft3eak5ytycs6dh7yk0"); // 	    else if ((*(ordering)==*("in")&&!strcmp(ordering,"in")))
UNSUPPORTED("dnig45so0x904azp9fhxymqjn"); // 		do_ordering_node(g, n, 0);
UNSUPPORTED("2rxgmu8cktngvqtsex2rlbjed"); // 	    else if (ordering[0])
UNSUPPORTED("axk3fxl1bh09n475kmcx42kdu"); // 		agerr(AGERR, "ordering '%s' not recognized for node '%s'.\n", ordering, agnameof(n));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 hzoz2czb672i0nbjvjhbc3na
// static void ordered_edges(graph_t * g) 
public static void ordered_edges(Agraph_s g) {
ENTERING("hzoz2czb672i0nbjvjhbc3na","ordered_edges");
try {
    CString ordering;
    if (N(G_ordering) && N(N_ordering))
	return;
UNSUPPORTED("98iqppixxkdndoz210i5ejppy"); //     if ((ordering = late_string(g, G_ordering, NULL))) {
UNSUPPORTED("lhhw62wj3on36enoy6ug6u1p"); // 	if ((*(ordering)==*("out")&&!strcmp(ordering,"out")))
UNSUPPORTED("ctbadiyd3jjtlt2f5t9p94au7"); // 	    do_ordering(g, NOT(0));
UNSUPPORTED("259y9uhqwc8w6jhrpm1eaa7hf"); // 	else if ((*(ordering)==*("in")&&!strcmp(ordering,"in")))
UNSUPPORTED("312ij4z5d42rye9s30l9io097"); // 	    do_ordering(g, 0);
UNSUPPORTED("25yw5chxmy54pmo88tre1w2ir"); // 	else if (ordering[0])
UNSUPPORTED("5ugg9zy8378pijqru97mxmen5"); // 	    agerr(AGERR, "ordering '%s' not recognized.\n", ordering);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("50itbchatjp61haxvg3xnhvoo"); // 	graph_t *subg;
UNSUPPORTED("evzjoqkm2xukapjvpccu2f23e"); // 	for (subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
UNSUPPORTED("1016hqxaexp4j33vmkzvdpq80"); // 	    /* clusters are processed by separate calls to ordered_edges */
UNSUPPORTED("7ah0zlu96u6g6cquxebenj4z3"); // 	    if (!is_cluster(subg))
UNSUPPORTED("7sqzaehh40dvpm11hlxhef6cw"); // 		ordered_edges(subg);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("h2b3ao18r091ie7yk9v20pqq"); // 	if (N_ordering) do_ordering_for_nodes (g);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("hzoz2czb672i0nbjvjhbc3na","ordered_edges");
}
}




//3 crwc5qe7fmrpgcqh1a80toyvo
// static int mincross_clust(graph_t * par, graph_t * g, int doBalance) 
public static int mincross_clust(Agraph_s par, Agraph_s g, boolean doBalance) {
ENTERING("crwc5qe7fmrpgcqh1a80toyvo","mincross_clust");
try {
    int c, nc;
    expand_cluster(g);
    ordered_edges(g);
    flat_breakcycles(g);
    flat_reorder(g);
    nc = mincross_(g, 2, 2, doBalance);
UNSUPPORTED("7z5fb6iyowsosn1hiz7opeoc6"); //     for (c = 1; c <= GD_n_cluster(g); c++)
UNSUPPORTED("9rf0oc3d6vv2etoxo9lfaafjv"); // 	nc += mincross_clust(g, GD_clust(g)[c], doBalance);
UNSUPPORTED("epdz9wujhh3y1k5vt6a57dwqv"); //     save_vlist(g);
UNSUPPORTED("bvmnch84b0w6a8b52fsv3my85"); //     return nc;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("crwc5qe7fmrpgcqh1a80toyvo","mincross_clust");
}
}




//3 657v773m21j5w3g3v94o7464t
// static int left2right(graph_t * g, node_t * v, node_t * w) 
public static Object left2right(Object... arg) {
UNSUPPORTED("e9xhu8cggp8fa04znsxctx4fp"); // static int left2right(graph_t * g, node_t * v, node_t * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bbscsjnrij166au4dit0hcnya"); //     adjmatrix_t *M;
UNSUPPORTED("ecz4e03zumggc8tfymqvirexq"); //     int rv;
UNSUPPORTED("a1d8c1kb8iahcs3b4ffgao93l"); //     /* CLUSTER indicates orig nodes of clusters, and vnodes of skeletons */
UNSUPPORTED("dwjoffuliruxg524w8dn9lgm5"); //     if (ReMincross == 0) {
UNSUPPORTED("c6ef5qylzspmlq9kx1x1b4965"); // 	if ((ND_clust(v) != ND_clust(w)) && (ND_clust(v)) && (ND_clust(w))) {
UNSUPPORTED("5jfymqwfx6tzv3q262gqhdkkn"); // 	    /* the following allows cluster skeletons to be swapped */
UNSUPPORTED("91bhygw897qpxvqf8l18732s1"); // 	    if ((ND_ranktype(v) == 7)
UNSUPPORTED("a283wt6pnchihxx1zk7i9oc0f"); // 		&& (ND_node_type(v) == 1))
UNSUPPORTED("5izxoao5ryte71964f8yjfd5y"); // 		return 0;
UNSUPPORTED("6hjnzko0r1bxentznakcjjl7w"); // 	    if ((ND_ranktype(w) == 7)
UNSUPPORTED("5zaowq2gpa6nw67z1nexnl1b9"); // 		&& (ND_node_type(w) == 1))
UNSUPPORTED("5izxoao5ryte71964f8yjfd5y"); // 		return 0;
UNSUPPORTED("9qhn9m3123s8n6wwxjfo8awlm"); // 	    return NOT(0);
UNSUPPORTED("f1wmsam8cmwci21kvsofgc0ex"); // 	    /*return ((ND_ranktype(v) != CLUSTER) && (ND_ranktype(w) != CLUSTER)); */
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("8lltx4lxwrqossx8qw1khzwf9"); // 	if ((ND_clust(v)) != (ND_clust(w)))
UNSUPPORTED("9qhn9m3123s8n6wwxjfo8awlm"); // 	    return NOT(0);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ai1fnguopi0studygsgl6xm9t"); //     M = GD_rank(g)[ND_rank(v)].flat;
UNSUPPORTED("8s0302z93xxwwp9704bratec2"); //     if (M == NULL)
UNSUPPORTED("40zoypg37zonwb7nuewxdti29"); // 	rv = 0;
UNSUPPORTED("1nyzbeonram6636b1w955bypn"); //     else {
UNSUPPORTED("21zvq2qx1j34j1i1879zyhzpj"); // 	if (GD_flip(g)) {
UNSUPPORTED("7hejrtprimtp2cmdj1zhhjiw4"); // 	    node_t *t = v;
UNSUPPORTED("at1y9wq7tpqtpgge0vh0j1b4g"); // 	    v = w;
UNSUPPORTED("e24z7zdnyun249iha0nfhw4s"); // 	    w = t;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("at8hgk5lstgpydu7gbt31yxvk"); // 	rv = (M->data[((ND_low(v))*M->ncols)+(ND_low(w))]);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 daknncpjy7g5peiicolbmh55i
// static int in_cross(node_t * v, node_t * w) 
public static Object in_cross(Object... arg) {
UNSUPPORTED("dwik0ppenkgu33mz3opflrrrf"); // static int in_cross(node_t * v, node_t * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("96fhqtialmibjynkszwl7r4rb"); //     register edge_t **e1, **e2;
UNSUPPORTED("ge64g62liro8mpc6l1z0fefc"); //     register int inv, cross = 0, t;
UNSUPPORTED("1od3s38r2drc9035guu5piras"); //     for (e2 = ND_in(w).list; *e2; e2++) {
UNSUPPORTED("b9d0tsqchw194gwwcaccpeo9y"); // 	register int cnt = ED_xpenalty(*e2);		
UNSUPPORTED("6gy97hhrwmqyi4roqynu0c3i2"); // 	inv = ND_order((agtail(*e2)));
UNSUPPORTED("ev2u3yd7s1srmzfxdpr794y72"); // 	for (e1 = ND_in(v).list; *e1; e1++) {
UNSUPPORTED("70146kw6zdcvg9ij91a5fygo6"); // 	    t = ND_order(agtail(*e1)) - inv;
UNSUPPORTED("bau6pz5v9hlbbnoqjebe388qc"); // 	    if ((t > 0)
UNSUPPORTED("5oiiiiqkh4fsgrvy0nfm0x4fa"); // 		|| ((t == 0)
UNSUPPORTED("6q7wpk7hadmfpog9iz8bf77e6"); // 		    && (  ED_tail_port(*e1).p.x > ED_tail_port(*e2).p.x)))
UNSUPPORTED("ak9hafl2ykj6ez4z6fxdrjyd9"); // 		cross += ED_xpenalty(*e1) * cnt;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8dm5o3tsfvxtjilyob6q5ndi1"); //     return cross;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 b7mf74np8ewrgzwd5u0o8fqod
// static int out_cross(node_t * v, node_t * w) 
public static Object out_cross(Object... arg) {
UNSUPPORTED("10p5htzg76e30d0ffesgx09jr"); // static int out_cross(node_t * v, node_t * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("96fhqtialmibjynkszwl7r4rb"); //     register edge_t **e1, **e2;
UNSUPPORTED("ge64g62liro8mpc6l1z0fefc"); //     register int inv, cross = 0, t;
UNSUPPORTED("8blj530v54lje4qfl9kktzr1l"); //     for (e2 = ND_out(w).list; *e2; e2++) {
UNSUPPORTED("1swt509kml9ho76rldszqzhwe"); // 	register int cnt = ED_xpenalty(*e2);
UNSUPPORTED("79u20gjpbx0hql41jnx8w6c5n"); // 	inv = ND_order(aghead(*e2));
UNSUPPORTED("1i43tjbyfawvljhxotls497ie"); // 	for (e1 = ND_out(v).list; *e1; e1++) {
UNSUPPORTED("641rrguxxepq4a1mag4d8051f"); // 	    t = ND_order(aghead(*e1)) - inv;
UNSUPPORTED("bau6pz5v9hlbbnoqjebe388qc"); // 	    if ((t > 0)
UNSUPPORTED("5oiiiiqkh4fsgrvy0nfm0x4fa"); // 		|| ((t == 0)
UNSUPPORTED("5xdbrre2382jli24u3qow95y1"); // 		    && ((ED_head_port(*e1)).p.x > (ED_head_port(*e2)).p.x)))
UNSUPPORTED("3vzsro14vlaot52hjh6okiww9"); // 		cross += ((ED_xpenalty(*e1)) * cnt);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8dm5o3tsfvxtjilyob6q5ndi1"); //     return cross;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ba4tbr57wips1dzpgxzx3b6ja
// static void exchange(node_t * v, node_t * w) 
public static Object exchange(Object... arg) {
UNSUPPORTED("aht6bc9x5a3ajb7p50qk6uwlr"); // static void exchange(node_t * v, node_t * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8uhj4l1a7aziolfe7cjl5zmk6"); //     int vi, wi, r;
UNSUPPORTED("cw4zcwnnpy44ot1oq93rqzerh"); //     r = ND_rank(v);
UNSUPPORTED("2uel8oob0jgmhpiopqni3x3kd"); //     vi = ND_order(v);
UNSUPPORTED("1yxit65yo5yqn8skj3lb470dt"); //     wi = ND_order(w);
UNSUPPORTED("8pgt68p8dqaez8q7sf0d8br6v"); //     ND_order(v) = wi;
UNSUPPORTED("drs7ioo5mlqypilm4739dc5l9"); //     GD_rank(Root)[r].v[wi] = v;
UNSUPPORTED("9xnexzdcou9cn4w00937nw115"); //     ND_order(w) = vi;
UNSUPPORTED("9zoviq2qqlqu2kzplgnq0uxzl"); //     GD_rank(Root)[r].v[vi] = w;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dzkv88lq5zv0g3yo7bf90qgr7
// static void balanceNodes(graph_t * g, int r, node_t * v, node_t * w) 
public static Object balanceNodes(Object... arg) {
UNSUPPORTED("504qsj6detmzllj50pno6sdx4"); // static void balanceNodes(graph_t * g, int r, node_t * v, node_t * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dor7xumwnqvymg7xdesa6pxqn"); //     node_t *s;			/* separator node */
UNSUPPORTED("c6s55weiu8hc4voeunxf2utru"); //     int sepIndex;
UNSUPPORTED("6gqdkaiir2naiawry8cnlpf4a"); //     int nullType;		/* type of null nodes */
UNSUPPORTED("2dqxr1ujg381s9ugf0367iici"); //     int cntDummy = 0, cntOri = 0;
UNSUPPORTED("7yj94w2zpwdubyzymyljw490a"); //     int k = 0, m = 0, k1 = 0, m1 = 0, i = 0;
UNSUPPORTED("6mq7c2z232o8kvpp371lfmewh"); //     /* we only consider v and w of different types */
UNSUPPORTED("53kjkk6c0h35zpbikj9y2q6b4"); //     if (ND_node_type(v) == ND_node_type(w))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("5ylcsv8rwps97qz7sdftpwrka"); //     /* count the number of dummy and original nodes */
UNSUPPORTED("5025o4uc5dkbxf3smi3kmfoit"); //     for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("d87qjwxc2qjvh6hb9fmi9y9vq"); // 	if (ND_node_type(GD_rank(g)[r].v[i]) == 0)
UNSUPPORTED("dcny4syjny1sh20jyjjl7jj62"); // 	    cntOri++;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("bbpsgrsgquajs3xxqzeqvgv6n"); // 	    cntDummy++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2qx27p3loyln3i09ycwf5p1dh"); //     if (cntOri < cntDummy) {
UNSUPPORTED("ex9drrxqg8zalagzrnvrulrlb"); // 	if (ND_node_type(v) == 0)
UNSUPPORTED("jtm789r1sqidxc39d09n9det"); // 	    s = v;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("c31t0vnbzvj9zml7p91syjzep"); // 	    s = w;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("ex9drrxqg8zalagzrnvrulrlb"); // 	if (ND_node_type(v) == 0)
UNSUPPORTED("c31t0vnbzvj9zml7p91syjzep"); // 	    s = w;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("jtm789r1sqidxc39d09n9det"); // 	    s = v;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ejbeaepbxwawm7mvtusyi2x57"); //     /* get the separator node index */
UNSUPPORTED("5025o4uc5dkbxf3smi3kmfoit"); //     for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("afetrkwabtn6v07evr5japsk5"); // 	if (GD_rank(g)[r].v[i] == s)
UNSUPPORTED("bvwqg08b9hn6rfdx11sjq0hgc"); // 	    sepIndex = i;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ecis6irl9vire6ejfrshttjk4"); //     nullType = (ND_node_type(s) == 0) ? 1 : 0;
UNSUPPORTED("1i78b3w9omzkba0pmafwfunbj"); //     /* count the number of null nodes to the left and 
UNSUPPORTED("1f2jn45p7wv1ud964k43lgdss"); //      * right of the separator node 
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("5l8w7t0ta6p6hnfp72l7lbqey"); //     for (i = sepIndex - 1; i >= 0; i--) {
UNSUPPORTED("49j09cv8f8ien7kqoguzywjmw"); // 	if (ND_node_type(GD_rank(g)[r].v[i]) == nullType)
UNSUPPORTED("borg3y7rgdooetc6ckrsrg9fc"); // 	    k++;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cuj70hyout6yv30drqkjiwllo"); //     for (i = sepIndex + 1; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("49j09cv8f8ien7kqoguzywjmw"); // 	if (ND_node_type(GD_rank(g)[r].v[i]) == nullType)
UNSUPPORTED("d35zlcj7podjjns9eg2ttocr7"); // 	    m++;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9r0b42aqwdlx2cg7aqsxgle1o"); //     /* now exchange v,w and calculate the same counts */
UNSUPPORTED("cvktng9nwm6futhlv28bqbqy"); //     exchange(v, w);
UNSUPPORTED("ejbeaepbxwawm7mvtusyi2x57"); //     /* get the separator node index */
UNSUPPORTED("5025o4uc5dkbxf3smi3kmfoit"); //     for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("afetrkwabtn6v07evr5japsk5"); // 	if (GD_rank(g)[r].v[i] == s)
UNSUPPORTED("bvwqg08b9hn6rfdx11sjq0hgc"); // 	    sepIndex = i;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1i78b3w9omzkba0pmafwfunbj"); //     /* count the number of null nodes to the left and 
UNSUPPORTED("1f2jn45p7wv1ud964k43lgdss"); //      * right of the separator node 
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("5l8w7t0ta6p6hnfp72l7lbqey"); //     for (i = sepIndex - 1; i >= 0; i--) {
UNSUPPORTED("49j09cv8f8ien7kqoguzywjmw"); // 	if (ND_node_type(GD_rank(g)[r].v[i]) == nullType)
UNSUPPORTED("eer25fyjj3njh33v709xj07lk"); // 	    k1++;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cuj70hyout6yv30drqkjiwllo"); //     for (i = sepIndex + 1; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("49j09cv8f8ien7kqoguzywjmw"); // 	if (ND_node_type(GD_rank(g)[r].v[i]) == nullType)
UNSUPPORTED("80ptwhmp1gyks2xfkcjub24o9"); // 	    m1++;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6yjcl5tugkib89c3p3beoi0cs"); //     if (abs(k1 - m1) > abs(k - m)) {
UNSUPPORTED("4hhzcihijbcjb2mo6eop9g855"); // 	exchange(v, w);		//revert to the original ordering
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 72rj5xs4qh00oh2yi1h5qaadu
// static int balance(graph_t * g) 
public static Object balance(Object... arg) {
UNSUPPORTED("4223t6rekw3qd8eksvz9kjcqh"); // static int balance(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("970giwpms1ljmt0px5djlqs0z"); //     int i, c0, c1, rv;
UNSUPPORTED("8xqnhjfdqnlwlyld1ep6hpnmb"); //     node_t *v, *w;
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("yy0fwjrmxw3jbi85mvwrka7f"); //     rv = 0;
UNSUPPORTED("9ey19t6tw2srzaedeng4sq96z"); //     for (r = GD_maxrank(g); r >= GD_minrank(g); r--) {
UNSUPPORTED("2nlemgjbnd1ygry42bcbuwo9y"); // 	GD_rank(g)[r].candidate = 0;
UNSUPPORTED("91gzxbmcoy5xbvf8nlhmlj4eh"); // 	for (i = 0; i < GD_rank(g)[r].n - 1; i++) {
UNSUPPORTED("5ekdr3i8niy7x2ohi7ftgmjke"); // 	    v = GD_rank(g)[r].v[i];
UNSUPPORTED("efwyjm6j3e7byt6z83lrhgd1r"); // 	    w = GD_rank(g)[r].v[i + 1];
UNSUPPORTED("8ey6umhtefcrb61ncgis82hw6"); // 	    assert(ND_order(v) < ND_order(w));
UNSUPPORTED("ddkyq74d5rjfcofczt4hmkxsj"); // 	    if (left2right(g, v, w))
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("cdpfb5fmlhe0831jf96pjp9s0"); // 	    c0 = c1 = 0;
UNSUPPORTED("3l676z6ajeugxvie4r957jap3"); // 	    if (r > 0) {
UNSUPPORTED("ennnd5cl9xhh55j2bni58iuxv"); // 		c0 += in_cross(v, w);
UNSUPPORTED("bk4dl2r7nw7j8xvkpg7g7x0z9"); // 		c1 += in_cross(w, v);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("f0ordylgf44hx2l90eof067yo"); // 	    if (GD_rank(g)[r + 1].n > 0) {
UNSUPPORTED("d945airzpo5xbu0fz68ylmgql"); // 		c0 += out_cross(v, w);
UNSUPPORTED("e6ez0uwca50uwo7i7i4vak4f2"); // 		c1 += out_cross(w, v);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("884yfwkgyw57w5ivpfrggmq15"); // 	    if (c1 <= c0) {
UNSUPPORTED("c2sevxb1gtyc2olq8akmvs40u"); // 		balanceNodes(g, r, v, w);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bxwzx4m9ejausu58u7abr6fm0
// static int transpose_step(graph_t * g, int r, int reverse) 
public static Object transpose_step(Object... arg) {
UNSUPPORTED("22wowirwvw8572horjl8haak1"); // static int transpose_step(graph_t * g, int r, int reverse)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("970giwpms1ljmt0px5djlqs0z"); //     int i, c0, c1, rv;
UNSUPPORTED("8xqnhjfdqnlwlyld1ep6hpnmb"); //     node_t *v, *w;
UNSUPPORTED("yy0fwjrmxw3jbi85mvwrka7f"); //     rv = 0;
UNSUPPORTED("88y1pg6y2gk42w8dn0n6p0m62"); //     GD_rank(g)[r].candidate = 0;
UNSUPPORTED("7dw0638pm1i0cmi1ab1yhfslk"); //     for (i = 0; i < GD_rank(g)[r].n - 1; i++) {
UNSUPPORTED("8q1k6j9oq30od80g0o5yy93bg"); // 	v = GD_rank(g)[r].v[i];
UNSUPPORTED("5nrqnzpfn9d9ce5no0pmc42x3"); // 	w = GD_rank(g)[r].v[i + 1];
UNSUPPORTED("d0v5o0jhskiehioj3fys34k5b"); // 	assert(ND_order(v) < ND_order(w));
UNSUPPORTED("a4tdk2vyxwkhw89p58dnvedta"); // 	if (left2right(g, v, w))
UNSUPPORTED("6hqli9m8yickz1ox1qfgtdbnd"); // 	    continue;
UNSUPPORTED("s29ss3mt0cdkkmvdy0cjo6q8"); // 	c0 = c1 = 0;
UNSUPPORTED("83q0jkf1uxirn1vqpf9uv4fmk"); // 	if (r > 0) {
UNSUPPORTED("14j6bnfhech8funkwo1cqst8x"); // 	    c0 += in_cross(v, w);
UNSUPPORTED("dudd7ptz2hdlnb18aetdetr3o"); // 	    c1 += in_cross(w, v);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("4omfp0pwbobg90d9xeh89wkwe"); // 	if (GD_rank(g)[r + 1].n > 0) {
UNSUPPORTED("7viyvlr11k6yoztmgyh2bajsh"); // 	    c0 += out_cross(v, w);
UNSUPPORTED("4z0o1rshenpr595htbxnx2oyx"); // 	    c1 += out_cross(w, v);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("atyufgwxijousuu65supc4xpr"); // 	if ((c1 < c0) || ((c0 > 0) && reverse && (c1 == c0))) {
UNSUPPORTED("49eey742kulff9x2tveqpt8gx"); // 	    exchange(v, w);
UNSUPPORTED("554s3oe2po6nzun5f4kgfyr0a"); // 	    rv += (c0 - c1);
UNSUPPORTED("bl97dptjca7w5yhvb96nuy471"); // 	    GD_rank(Root)[r].valid = 0;
UNSUPPORTED("2h30ya77zx778oywythgi9pa1"); // 	    GD_rank(g)[r].candidate = NOT(0);
UNSUPPORTED("dgnv4dsi67zn1be6hfj3hjul"); // 	    if (r > GD_minrank(g)) {
UNSUPPORTED("at299o5g5je5irjb60pbk3qh7"); // 		GD_rank(Root)[r - 1].valid = 0;
UNSUPPORTED("5c01qb595cgvih949xqaz0bxs"); // 		GD_rank(g)[r - 1].candidate = NOT(0);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("bgqb2jipy0lkn54kk2dxuz53u"); // 	    if (r < GD_maxrank(g)) {
UNSUPPORTED("8c047jio9e361ny5qyqy1o5rn"); // 		GD_rank(Root)[r + 1].valid = 0;
UNSUPPORTED("81x0kmqqzll0hv69oq6mdbwk5"); // 		GD_rank(g)[r + 1].candidate = NOT(0);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2i22bxgg5y7v5c5d40k5zppky
// static void transpose(graph_t * g, int reverse) 
public static Object transpose(Object... arg) {
UNSUPPORTED("8fny7bks97nkox8yzpszb056g"); // static void transpose(graph_t * g, int reverse)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ccja1vlzrgybom5tchpgfftsq"); //     int r, delta;
UNSUPPORTED("br5jnq2zjxxbz2mw0z8ns5uug"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++)
UNSUPPORTED("b3qynxo3yu3yrtl927m4vbalw"); // 	GD_rank(g)[r].candidate = NOT(0);
UNSUPPORTED("53kc41p479auwcycfsbhw8xix"); //     do {
UNSUPPORTED("1nq14goek8390ttms5gapf445"); // 	delta = 0;
UNSUPPORTED("34zoiglx6i533thnb09wet61g"); // 	for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("15wbv50gexauk4kyrbhprb7az"); // 	    if (GD_rank(g)[r].candidate) {
UNSUPPORTED("34k9plf600i6crkgf940ohaqa"); // 		delta += transpose_step(g, r, reverse);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("53ox9pov5iq5rjyczxrljjvzi"); // 	/*} while (delta > ncross(g)*(1.0 - Convergence)); */
UNSUPPORTED("52ud7we98x3ja1dsotq78rt74"); //     } while (delta >= 1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7lrk2rxqnwwdau8cx85oqkpmv
// static int mincross(graph_t * g, int startpass, int endpass, int doBalance) 
public static int mincross_(Agraph_s g, int startpass, int endpass, boolean doBalance) {
ENTERING("7lrk2rxqnwwdau8cx85oqkpmv","mincross");
try {
    int maxthispass=0, iter, trying, pass;
    int cur_cross, best_cross;
    if (startpass > 1) {
	cur_cross = best_cross = ncross(g);
	save_best(g);
    } else
	cur_cross = best_cross = INT_MAX;
    for (pass = startpass; pass <= endpass; pass++) {
	if (pass <= 1) {
	    maxthispass = MIN(4, MaxIter);
	    if (EQ(g, dot_root(g)))
		build_ranks(g, pass);
	    if (pass == 0)
		flat_breakcycles(g);
	    flat_reorder(g);
	    if ((cur_cross = ncross(g)) <= best_cross) {
		save_best(g);
		best_cross = cur_cross;
	    }
	    trying = 0;
	} else {
	    maxthispass = MaxIter;
	    if (cur_cross > best_cross)
		restore_best(g);
	    cur_cross = best_cross;
	}
	trying = 0;
	for (iter = 0; iter < maxthispass; iter++) {
	    /*if (Verbose)
		fprintf(stderr,
			"mincross: pass %d iter %d trying %d cur_cross %d best_cross %d\n",
			pass, iter, trying, cur_cross, best_cross);*/
	    if (trying++ >= MinQuit)
		break;
	    if (cur_cross == 0)
		break;
	    mincross_step(g, iter);
	    if ((cur_cross = ncross(g)) <= best_cross) {
		save_best(g);
		if (cur_cross < Convergence * best_cross)
		    trying = 0;
		best_cross = cur_cross;
	    }
	}
	if (cur_cross == 0)
	    break;
    }
    if (cur_cross > best_cross)
	restore_best(g);
    if (best_cross > 0) {
	transpose(g, 0);
	best_cross = ncross(g);
    }
    if (doBalance) {
	for (iter = 0; iter < maxthispass; iter++)
	    balance(g);
    }
    return best_cross;
} finally {
LEAVING("7lrk2rxqnwwdau8cx85oqkpmv","mincross");
}
}




//3 520049zkz9mafaeklgvm6s8e5
// static void restore_best(graph_t * g) 
public static Object restore_best(Object... arg) {
UNSUPPORTED("4q8g45k86re5f2yuwix1pcr3c"); // static void restore_best(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("3bvewz6omm7dh7uz9cev5662n"); //     for (n = GD_nlist(g); n; n = ND_next(n))
UNSUPPORTED("5i2kvfhh75s3nkyi1i51dizo2"); // 	ND_order(n) = (ND_coord(n)).x;
UNSUPPORTED("60nab7gyukq3bs8e6dizhbacy"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("aiubcqxqgke7s3v2d7ukdxub4"); // 	GD_rank(Root)[r].valid = 0;
UNSUPPORTED("33wle8ztehrmam8ylr47qxsxn"); // 	qsort(GD_rank(g)[r].v, GD_rank(g)[r].n, sizeof(GD_rank(g)[0].v[0]),
UNSUPPORTED("6jhzusiss42n7vqv3j4raijve"); // 	      (qsort_cmpf) nodeposcmpf);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8uyqc48j0oul206l3np85wj9p
// static void save_best(graph_t * g) 
public static void save_best(Agraph_s g) {
ENTERING("8uyqc48j0oul206l3np85wj9p","save_best");
try {
    Agnode_s n;
    for (n = GD_nlist(g); n!=null; n = ND_next(n))
	(ND_coord(n)).setDouble("x", ND_order(n));
} finally {
LEAVING("8uyqc48j0oul206l3np85wj9p","save_best");
}
}




//3 6d08fwi4dsk6ikk5d0gy6rq2h
// static void merge_components(graph_t * g) 
public static void merge_components(Agraph_s g) {
ENTERING("6d08fwi4dsk6ikk5d0gy6rq2h","merge_components");
try {
    int c;
    Agnode_s u, v;
    if (GD_comp(g).getInt("size") <= 1)
	return;
    u = null;
UNSUPPORTED("636pqelh1tz8cxif83unv4i8h"); //     for (c = 0; c < GD_comp(g).size; c++) {
UNSUPPORTED("5imhf8owstricua9ga0ttxgza"); // 	v = GD_comp(g).list[c];
UNSUPPORTED("b9gfp46tk6krt8gqegwmackqf"); // 	if (u)
UNSUPPORTED("83jz0ssw95jodsh7plgaqrup4"); // 	    ND_next(u) = v;
UNSUPPORTED("1jzywnxul39p2wz0lfjejlcvs"); // 	ND_prev(v) = u;
UNSUPPORTED("7w7lk8hzlv2xblitvnknhu32s"); // 	while (ND_next(v)) {
UNSUPPORTED("en88ux114ejlak2mn2k29phwa"); // 	    v = ND_next(v);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("qkj9h7elujdjas8snduv4pms"); // 	u = v;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9aulongg83abscaxz6bzifded"); //     GD_comp(g).size = 1;
UNSUPPORTED("58d4zw1j389saz5wnd51y2pgu"); //     GD_nlist(g) = GD_comp(g).list[0];
UNSUPPORTED("ces6zn0yqvwyqxklid0d0t44k"); //     GD_minrank(g) = GlobalMinRank;
UNSUPPORTED("242l613u89lhrlpukcz265xm1"); //     GD_maxrank(g) = GlobalMaxRank;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("6d08fwi4dsk6ikk5d0gy6rq2h","merge_components");
}
}




//3 91vebcdl3q3y0uyxef0iw71n9
// static void merge2(graph_t * g) 
public static void merge2(Agraph_s g) {
ENTERING("91vebcdl3q3y0uyxef0iw71n9","merge2");
try {
    int i, r;
    Agnode_s v;
    /* merge the components and rank limits */
    merge_components(g);
    /* install complete ranks */
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	GD_rank(g).plus(r).setInt("n", GD_rank(g).plus(r).getInt("an"));
	GD_rank(g).plus(r).setPtr("v", GD_rank(g).plus(r).getPtr("av"));
	for (i = 0; i < GD_rank(g).plus(r).getInt("n"); i++) {
	    v = (Agnode_s) GD_rank(g).plus(r).getArray("v").plus(i).getPtr();
	    if (v == null) {
		/*if (Verbose)
		    fprintf(stderr,
			    "merge2: graph %s, rank %d has only %d < %d nodes\n",
			    agnameof(g), r, i, GD_rank(g)[r].n);*/
		GD_rank(g).plus(r).setInt("n",  i);
		break;
	    }
	    ND_order(v, i);
	}
    }
} finally {
LEAVING("91vebcdl3q3y0uyxef0iw71n9","merge2");
}
}




//3 3cwiyyk1d1jkoo9iqwb5bge4x
// static void cleanup2(graph_t * g, int nc) 
public static void cleanup2(Agraph_s g, int nc) {
ENTERING("3cwiyyk1d1jkoo9iqwb5bge4x","cleanup2");
try {
    int i, j, r, c;
    Agnode_s v;
    Agedge_s e;
    if (TI_list!=null) {
	Memory.free(TI_list);
	TI_list = null;
    }
    if (TE_list!=null) {
	Memory.free(TE_list);
	TE_list = null;
    }
    /* fix vlists of clusters */
    for (c = 1; c <= GD_n_cluster(g); c++)
	rec_reset_vlists(GD_clust(g).plus(c));
    /* remove node temporary edges for ordering nodes */
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	for (i = 0; i < GD_rank(g).plus(r).getInt("n"); i++) {
	    v = (Agnode_s) GD_rank(g).plus(r).getArray("v").plus(i).getPtr();
	    ND_order(v, i);
	    if (ND_flat_out(v).getPtr("list")!=null) {
		for (j = 0; (e = (Agedge_s) ND_flat_out(v).getArray("list").plus(j).getPtr())!=null; j++)
		    if (ED_edge_type(e) == 4) {
			delete_flat_edge(e);
			Memory.free(e.getPtr("base.data"));
			Memory.free(e);
			j--;
		    }
	    }
	}
	free_matrix((adjmatrix_t) GD_rank(g).plus(r).getPtr("flat"));
    }
    /*if (Verbose)
	fprintf(stderr, "mincross %s: %d crossings, %.2f secs.\n",
		agnameof(g), nc, elapsed_sec());*/
} finally {
LEAVING("3cwiyyk1d1jkoo9iqwb5bge4x","cleanup2");
}
}




//3 arax68kzcf86dr2xu0gp962gq
// static node_t *neighbor(node_t * v, int dir) 
public static Object neighbor(Object... arg) {
UNSUPPORTED("cooo3yper06ar0p024wzw4rec"); // static node_t *neighbor(node_t * v, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4302bhte4qzbdabx61n5e2rim"); //     node_t *rv;
UNSUPPORTED("e5il3lx8mzixp6isrux07m6se"); //     rv = NULL;
UNSUPPORTED("78bfdlcgyjuhlbg1l7zkbmevd"); // assert(v);
UNSUPPORTED("avri04dgsqilu4rrfrwhgiaxq"); //     if (dir < 0) {
UNSUPPORTED("6amd14bdtwjhj0w4ltmpgf65n"); // 	if (ND_order(v) > 0)
UNSUPPORTED("94qfi7a7w4143o7mtc2knxasm"); // 	    rv = GD_rank(Root)[ND_rank(v)].v[ND_order(v) - 1];
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("8ou3jyxqleoiw8so2acxjahzo"); // 	rv = GD_rank(Root)[ND_rank(v)].v[ND_order(v) + 1];
UNSUPPORTED("ahr38d5bwiucncpw94b08hq53"); // assert((rv == 0) || (ND_order(rv)-ND_order(v))*dir > 0);
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1waqm8z71hi389dt1wqh0bmhr
// static int is_a_normal_node_of(graph_t * g, node_t * v) 
public static Object is_a_normal_node_of(Object... arg) {
UNSUPPORTED("4hdjbdsma9mewci4guq1hpte7"); // static int is_a_normal_node_of(graph_t * g, node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8ymqzibljaldgeeby0jom6dxl"); //     return ((ND_node_type(v) == 0) && agcontains(g, v));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9f8atyi1unmleplge3rijdt4s
// static int is_a_vnode_of_an_edge_of(graph_t * g, node_t * v) 
public static Object is_a_vnode_of_an_edge_of(Object... arg) {
UNSUPPORTED("38ex9shu3wd3h9skc3acx2shg"); // static int is_a_vnode_of_an_edge_of(graph_t * g, node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("aeyctz12qt4vsfk55ps3poobh"); //     if ((ND_node_type(v) == 1)
UNSUPPORTED("djp3j0dche599iyes70aeah55"); // 	&& (ND_in(v).size == 1) && (ND_out(v).size == 1)) {
UNSUPPORTED("577ti4mp6m8ah2cgkpjxgrjbj"); // 	edge_t *e = ND_out(v).list[0];
UNSUPPORTED("1aitgidttep2eipfffwj3quk9"); // 	while (ED_edge_type(e) != 0)
UNSUPPORTED("1zvlxrjosiabmje0gsi1lrzrg"); // 	    e = ED_to_orig(e);
UNSUPPORTED("8uahjxmk6qf2accyjtefccvxd"); // 	if (agcontains(g, e))
UNSUPPORTED("9qhn9m3123s8n6wwxjfo8awlm"); // 	    return NOT(0);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 eo7ulc8vwmoaig0j479yapve2
// static int inside_cluster(graph_t * g, node_t * v) 
public static Object inside_cluster(Object... arg) {
UNSUPPORTED("hhgxveigmhjybmvy9o2bhrze"); // static int inside_cluster(graph_t * g, node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("blv976n9gf9884dc8ntd5t8bv"); //     return (is_a_normal_node_of(g, v) | is_a_vnode_of_an_edge_of(g, v));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8xkmkt4r6gfqj8gk0mokszoz0
// static node_t *furthestnode(graph_t * g, node_t * v, int dir) 
public static Object furthestnode(Object... arg) {
UNSUPPORTED("838099xnxpt1xofa9q8ns830q"); // static node_t *furthestnode(graph_t * g, node_t * v, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("38d1vdgo9f29sl2n8hxoa5fly"); //     node_t *u, *rv;
UNSUPPORTED("b0bxockvt1b6rdxv4alpldj86"); //     rv = u = v;
UNSUPPORTED("92byw2dnqctnb5fpe5f5q5frs"); //     while ((u = neighbor(u, dir))) {
UNSUPPORTED("e9u7t9t0wblx71idh0x4etxjg"); // 	if (is_a_normal_node_of(g, u))
UNSUPPORTED("8aikgc5yj8lie66ovgptsts0e"); // 	    rv = u;
UNSUPPORTED("eew0i83hxfefyo0q6nl289l85"); // 	else if (is_a_vnode_of_an_edge_of(g, u))
UNSUPPORTED("8aikgc5yj8lie66ovgptsts0e"); // 	    rv = u;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bwmu2hkwud40601oq5vgo2f1h
// void save_vlist(graph_t * g) 
public static void save_vlist(Agraph_s g) {
ENTERING("bwmu2hkwud40601oq5vgo2f1h","save_vlist");
try {
    int r;
    if (GD_rankleader(g)!=null)
	for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	    GD_rankleader(g).plus(r).setPtr(GD_rank(g).plus(r).getArray("v").plus(0).getPtr());
	}
} finally {
LEAVING("bwmu2hkwud40601oq5vgo2f1h","save_vlist");
}
}




//3 hwdxg97sefkuyd25x2q4pgzg
// void rec_save_vlists(graph_t * g) 
public static void rec_save_vlists(Agraph_s g) {
ENTERING("hwdxg97sefkuyd25x2q4pgzg","rec_save_vlists");
try {
    int c;
    save_vlist(g);
    for (c = 1; c <= GD_n_cluster(g); c++)
	rec_save_vlists((Agraph_s) GD_clust(g).plus(c).getPtr());
} finally {
LEAVING("hwdxg97sefkuyd25x2q4pgzg","rec_save_vlists");
}
}




//3 f3b4wat4uxn5oil720i5mwq4v
// void rec_reset_vlists(graph_t * g) 
public static Object rec_reset_vlists(Object... arg) {
UNSUPPORTED("beg7h6f4142m5q539hfs559qe"); // void rec_reset_vlists(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3uj2h26d8pqkuu2k0mjvkeol9"); //     int r, c;
UNSUPPORTED("25x2fk32ib5gwpvp05iqj8e99"); //     node_t *u, *v, *w;
UNSUPPORTED("6hexl9haonf79yscag1bkd2hp"); //     /* fix vlists of sub-clusters */
UNSUPPORTED("7z5fb6iyowsosn1hiz7opeoc6"); //     for (c = 1; c <= GD_n_cluster(g); c++)
UNSUPPORTED("9g20g9n2zy1e32hvrsrkt4jaq"); // 	rec_reset_vlists(GD_clust(g)[c]);
UNSUPPORTED("bejp0glz6rd31y42pmvg9jd1d"); //     if (GD_rankleader(g))
UNSUPPORTED("34zoiglx6i533thnb09wet61g"); // 	for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("2f5rj012q7k8l1dwrvcria9h9"); // 	    v = GD_rankleader(g)[r];
UNSUPPORTED("dk29ytd6j0s8ahqrloyiih4gs"); // 	    u = furthestnode(g, v, -1);
UNSUPPORTED("ei0k1qdcoaxw4ss8pggyvyjf3"); // 	    w = furthestnode(g, v, 1);
UNSUPPORTED("chlootgcd8tkc8lwtp4uge3ub"); // 	    GD_rankleader(g)[r] = u;
UNSUPPORTED("bwthbwy901g64csqdlq41txgx"); // 	    GD_rank(g)[r].v = GD_rank(dot_root(g))[r].v + ND_order(u);
UNSUPPORTED("dv3k3p7wtwnl7ok7g7ym67weo"); // 	    GD_rank(g)[r].n = ND_order(w) - ND_order(u) + 1;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 pv0rbbdopo4hmkbl5916qys1
// static Agraph_t* realFillRanks (Agraph_t* g, int rnks[], int rnks_sz, Agraph_t* sg) 
public static Agraph_s realFillRanks(Agraph_s g, __ptr__ rnks, int rnks_sz, Agraph_s sg) {
ENTERING("pv0rbbdopo4hmkbl5916qys1","realFillRanks");
try {
 UNSUPPORTED("2o2sf6xi2aumo5k0vglp4ik2y"); // static Agraph_t*
UNSUPPORTED("3pmsfb0uhqmy5u141c932dtn1"); // realFillRanks (Agraph_t* g, int rnks[], int rnks_sz, Agraph_t* sg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("apiu3v3f9zs9yrq8e25nd2rti"); //     int i, c;
UNSUPPORTED("6yramhpyls8c6kexupyqip8oq"); //     Agedge_t* e;
UNSUPPORTED("ci2zh69w6nhi0q816i1ixuy9k"); //     Agnode_t* n;
UNSUPPORTED("7z5fb6iyowsosn1hiz7opeoc6"); //     for (c = 1; c <= GD_n_cluster(g); c++)
UNSUPPORTED("wqxqmv4he79njsw6r7sludv"); // 	sg = realFillRanks (GD_clust(g)[c], rnks, rnks_sz, sg);
UNSUPPORTED("8htor72y55gsejjdeh0e8gdrs"); //     if (dot_root(g) == g)
UNSUPPORTED("bjae04ek2s3o50399zti5a1jh"); // 	return sg;
UNSUPPORTED("bqfhaopbxlwv8h4zfae1lhx6s"); //     memset (rnks, 0, sizeof(int)*rnks_sz);
UNSUPPORTED("7wq24g054kmx3aw25vk5ksj4"); //     for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
UNSUPPORTED("do7v5atqor4gnpwgo18ibgjha"); // 	rnks[ND_rank(n)] = 1;
UNSUPPORTED("9fo44dng5uojukw2kj0z8vvdu"); // 	for (e = agfstout(g,n); e; e = agnxtout(g,e)) {
UNSUPPORTED("emlgvc6yzuboae72y6vxpn8z7"); // 	    for (i = ND_rank(n)+1; i <= ND_rank(aghead(e)); i++) 
UNSUPPORTED("d3fd9x50ix980jjw3old2jrcr"); // 		rnks[i] = 1;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7gfo0rr0un3w2026kt6ipknty"); //     for (i = GD_minrank(g); i <= GD_maxrank(g); i++) {
UNSUPPORTED("6mjvdb94lywg8d7ui6873f18p"); // 	if (rnks[i] == 0) {
UNSUPPORTED("8g0zxrf8w2zly4wln02j3lbnb"); // 	    if (!sg) {
UNSUPPORTED("eqx93butvb7swnxbz9j29winp"); // 		sg = agsubg (dot_root(g), "_new_rank", 1);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("9h7suegjozc071a939rh9apw1"); // 	    n = agnode (sg, NULL, 1);
UNSUPPORTED("8kclviftszfxkowsmlqq31u8"); // 	    agbindrec(n, "Agnodeinfo_t", sizeof(Agnodeinfo_t), NOT(0));
UNSUPPORTED("8wiry1vcdwy6bzdp98nmxss7c"); // 	    ND_rank(n) = i;
UNSUPPORTED("dy16sxtk3jj6127wavfcdx4yw"); // 	    ND_lw(n) = ND_rw(n) = 0.5;
UNSUPPORTED("6jr3li9af4sp0uxnpnoe8dqh8"); // 	    ND_ht(n) = 1;
UNSUPPORTED("c47fetnb62mx46qzuk9ag3qmu"); // 	    ND_UF_size(n) = 1;
UNSUPPORTED("899cyghezv8oxs0iomu58zncj"); // 	    alloc_elist(4, ND_in(n));
UNSUPPORTED("btfqtg58rqwdh7o4cc0gbaaai"); // 	    alloc_elist(4, ND_out(n));
UNSUPPORTED("9zap4z819hsiogrgmekh15f00"); // 	    agsubnode (g, n, 1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1jw141gg4omv8r72xcbl5ln0o"); //     return sg;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("pv0rbbdopo4hmkbl5916qys1","realFillRanks");
}
}




//3 1qy9bupreg1pax62owznr98k
// static void fillRanks (Agraph_t* g) 
public static void fillRanks(Agraph_s g) {
ENTERING("1qy9bupreg1pax62owznr98k","fillRanks");
try {
    Agraph_s sg;
    int rnks_sz = GD_maxrank(g) + 2;
    __ptr__ rnks = zmalloc(size_t_array_of_integer(rnks_sz));
    sg = realFillRanks (g, rnks, rnks_sz, null);
    Memory.free (rnks);
} finally {
LEAVING("1qy9bupreg1pax62owznr98k","fillRanks");
}
}




//3 7fy4chyk12o7bgp1rv3h27yl3
// static void init_mincross(graph_t * g) 
public static void init_mincross(Agraph_s g) {
ENTERING("7fy4chyk12o7bgp1rv3h27yl3","init_mincross");
try {
    int size;
    //if (Verbose)
	//start_timer();
    ReMincross = false;
    Root = g;
    /* alloc +1 for the null terminator usage in do_ordering() */
    /* also, the +1 avoids attempts to alloc 0 sizes, something
       that efence complains about */
    size = agnedges(dot_root(g)) + 1;
    TE_list = zmalloc(sizeof_starstar_empty(Agedge_s.class, size));
    TI_list = zmalloc(size_t_array_of_integer(size));
    mincross_options(g);
    if ((GD_flags(g) & (1 << 4))!=0)
	fillRanks (g);
    class2(g);
    decompose(g, 1);
    allocate_ranks(g);
    ordered_edges(g);
    GlobalMinRank = GD_minrank(g);
    GlobalMaxRank = GD_maxrank(g);
} finally {
LEAVING("7fy4chyk12o7bgp1rv3h27yl3","init_mincross");
}
}




//3 6fprrp93vmz0jn3l4ro0iropp
// void flat_rev(Agraph_t * g, Agedge_t * e) 
public static Object flat_rev(Object... arg) {
UNSUPPORTED("60meymegvcl5kyusa9nowiyey"); // void flat_rev(Agraph_t * g, Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2bs0wcp6367dz1o5x166ec7l8"); //     int j;
UNSUPPORTED("2d7hxar9c7ew4kb78h8e080dg"); //     Agedge_t *rev;
UNSUPPORTED("17klu3t0xbhd7x7s7rg71ains"); //     if (!ND_flat_out(aghead(e)).list)
UNSUPPORTED("cppohlb5j66cx1gu5b993qugy"); // 	rev = NULL;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("7jd6rutmiqbt8ivw52dxbdw3x"); // 	for (j = 0; (rev = ND_flat_out(aghead(e)).list[j]); j++)
UNSUPPORTED("7bf7vjqpade7io8u0hbqeqs8m"); // 	    if (aghead(rev) == agtail(e))
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("8m5izg2w8ldt7aqh5be7ctq0d"); //     if (rev) {
UNSUPPORTED("47of6vwi8sp1rp81106pjrha0"); // 	merge_oneway(e, rev);
UNSUPPORTED("4qby4hntb1heomfmqtkreewwk"); // 	if (ED_to_virt(e) == 0)
UNSUPPORTED("1qkkzbb9lkiz6be8afd7kgsma"); // 	    ED_to_virt(e) = rev;
UNSUPPORTED("69siqm3b5l9eifk19g4lm3ptr"); // 	if ((ED_edge_type(rev) == 4)
UNSUPPORTED("5l5v5l7h3ge53wqz49vbojipy"); // 	    && (ED_to_orig(rev) == 0))
UNSUPPORTED("9k8si77u043a3671bef8no4ko"); // 	    ED_to_orig(rev) = e;
UNSUPPORTED("do5r4saurlfjjbjxaqvyvfdsz"); // 	elist_append(e, ND_other(agtail(e)));
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("epgpomoed7i398231ndqkpv3w"); // 	rev = new_virtual_edge(aghead(e), agtail(e), e);
UNSUPPORTED("9mjzpo9lfftkal4fgr6kbobso"); // 	if (ED_edge_type(e) == 4)
UNSUPPORTED("dgu6abw4apcihw1ncbxycmmyo"); // 	    ED_edge_type(rev) = 4;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("6zjolflkvuyob7hg17citc4xa"); // 	    ED_edge_type(rev) = 3;
UNSUPPORTED("9h3aexk46uq9l3je9dw0aa7zt"); // 	ED_label(rev) = ED_label(e);
UNSUPPORTED("3escrp0dky3o15ajakxnglpcy"); // 	flat_edge(g, rev);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 63ol0ch6cgln1nvl5oiz6n1v0
// static void flat_search(graph_t * g, node_t * v) 
public static Object flat_search(Object... arg) {
UNSUPPORTED("3dplv8liqps606lyji49cwyto"); // static void flat_search(graph_t * g, node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("uz4bkd9jmc1izkfypacwrm7x"); //     boolean hascl;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("1x3lyeyf56cjta47z17ggq7r"); //     adjmatrix_t *M = GD_rank(g)[ND_rank(v)].flat;
UNSUPPORTED("3dxrqgsmycugkp3qprexbuawx"); //     ND_mark(v) = NOT(0);
UNSUPPORTED("9z9a3g70rwq874kmknu0re0w0"); //     ND_onstack(v) = NOT(0);
UNSUPPORTED("f3owhsa283q0fffno3u255bbs"); //     hascl = (GD_n_cluster(dot_root(g)) > 0);
UNSUPPORTED("2k0tyeb9985izamv9zgtdcn2b"); //     if (ND_flat_out(v).list)
UNSUPPORTED("bjd1q4wrt334u4l37r6wyvk9x"); // 	for (i = 0; (e = ND_flat_out(v).list[i]); i++) {
UNSUPPORTED("46ccyp7sfts1arfi6gcmyl47h"); // 	    if (hascl
UNSUPPORTED("9nrg1sdmsv8dvjcnzy3hxl311"); // 		&& NOT(agcontains(g, agtail(e)) && agcontains(g, aghead(e))))
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("8o06h6b27felekpkiczuce1a5"); // 	    if (ED_weight(e) == 0)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("9g5fd0gd8z6kt7wqo87u93e7r"); // 	    if (ND_onstack(aghead(e)) == NOT(0)) {
UNSUPPORTED("cgkgsq3cgt6yvpwsn9st1phym"); // 		assert(ND_low(aghead(e)) < M->nrows);
UNSUPPORTED("38hoycfuki3wuy5cj039e3b00"); // 		assert(ND_low(agtail(e)) < M->ncols);
UNSUPPORTED("ehj17yz9fge33i8h1scw4m7q6"); // 		(M->data[((ND_low(aghead(e)))*M->ncols)+(ND_low(agtail(e)))]) = 1;
UNSUPPORTED("1iwplhbmvtv3d8gseqen1bn52"); // 		delete_flat_edge(e);
UNSUPPORTED("b5737gtfqocrc9dqgtvfuz5e7"); // 		i--;
UNSUPPORTED("8x0ryen4203ncnio11ie1rl6o"); // 		if (ED_edge_type(e) == 4)
UNSUPPORTED("2yi9az7ibt7j9bwztjilyo0v2"); // 		    continue;
UNSUPPORTED("8nnedzb0mcoepaac60ovylf44"); // 		flat_rev(g, e);
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("cgkgsq3cgt6yvpwsn9st1phym"); // 		assert(ND_low(aghead(e)) < M->nrows);
UNSUPPORTED("38hoycfuki3wuy5cj039e3b00"); // 		assert(ND_low(agtail(e)) < M->ncols);
UNSUPPORTED("5tglo5l92e3vo4ojcrpswx0ot"); // 		(M->data[((ND_low(agtail(e)))*M->ncols)+(ND_low(aghead(e)))]) = 1;
UNSUPPORTED("ausndrmwuhuwnm7w5zwx9oy82"); // 		if (ND_mark(aghead(e)) == 0)
UNSUPPORTED("7ocuk5j7l24eda0x312i8tdb1"); // 		    flat_search(g, aghead(e));
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8o0qmsv6vkvey8j3nrtn0z3nd"); //     ND_onstack(v) = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3v5h7z4vqivibvpt913lg8at0
// static void flat_breakcycles(graph_t * g) 
public static void flat_breakcycles(Agraph_s g) {
ENTERING("3v5h7z4vqivibvpt913lg8at0","flat_breakcycles");
try {
    int i, r, flat;
    Agnode_s v;
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	flat = 0;
	for (i = 0; i < GD_rank(g).plus(r).getInt("n"); i++) {
	    v = (Agnode_s) GD_rank(g).plus(r).getArray("v").plus(i).getPtr();
	    ND_mark(v, 0);
	    ND_onstack(v, 0);
	    ND_low(v, i);
	    if ((ND_flat_out(v).getInt("size") > 0) && (flat == 0)) {
		GD_rank(g).plus(r).setPtr("flat",
		    new_matrix(GD_rank(g).plus(r).getInt("n"), GD_rank(g).plus(r).getInt("n")));
		flat = 1;
	    }
	}
	if (flat!=0) {
	    for (i = 0; i < GD_rank(g).plus(r).getInt("n"); i++) {
		v = (Agnode_s) GD_rank(g).plus(r).getArray("v").plus(i).getPtr();
		if (ND_mark(v) == 0)
		    flat_search(g, v);
	    }
	}
    }
} finally {
LEAVING("3v5h7z4vqivibvpt913lg8at0","flat_breakcycles");
}
}




//3 d5vb6jiw8mhkaa8gjwn4eqfyn
// void allocate_ranks(graph_t * g) 
public static void allocate_ranks(Agraph_s g) {
ENTERING("d5vb6jiw8mhkaa8gjwn4eqfyn","allocate_ranks");
try {
	// REVIEW 17/01/2016
    int r, low, high;
    __ptr__ cn;
    Agnode_s n;
    Agedge_s e;
	cn = zmalloc(size_t_array_of_integer(GD_maxrank(g) + 2));
	/* must be 0 based, not GD_minrank */
    for (n = agfstnode(g); n!=null; n = agnxtnode(g, n)) {
	cn.plus(ND_rank(n)).setInt(1+cn.plus(ND_rank(n)).getInt());
	for (e = agfstout(g, n); e!=null; e = agnxtout(g, e)) {
	    low = ND_rank(agtail(e));
	    high = ND_rank(aghead(e));
	    if (low > high) {
		int t = low;
		low = high;
		high = t;
	    }
	    for (r = low + 1; r < high; r++)
		cn.plus(r).setInt(1+cn.plus(r).getInt());
	}
    }
    GD_rank(g, zmalloc(sizeof(rank_t.class, GD_maxrank(g) + 2)));
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	GD_rank(g).plus(r).setInt("n", cn.plus(r).getInt());
	GD_rank(g).plus(r).setInt("an", cn.plus(r).getInt());
	__ptr__ tmp = zmalloc(sizeof_starstar_empty(Agnode_s.class, cn.plus(r).getInt() + 1));
	GD_rank(g).plus(r).setPtr("v", tmp);
	GD_rank(g).plus(r).setPtr("av", tmp);
    }
    Memory.free(cn);
} finally {
LEAVING("d5vb6jiw8mhkaa8gjwn4eqfyn","allocate_ranks");
}
}




//3 3lxoqxhiri9fgt20zc5jz3aa5
// void install_in_rank(graph_t * g, node_t * n) 
public static void install_in_rank(Agraph_s g, Agnode_s n) {
ENTERING("3lxoqxhiri9fgt20zc5jz3aa5","install_in_rank");
try {
    int i, r;
    r = ND_rank(n);
    i = GD_rank(g).plus(r).getInt("n");
    if (GD_rank(g).plus(r).getInt("an") <= 0) {
UNSUPPORTED("8qk1xhvvb994zhv9aq10k4v12"); // 	agerr(AGERR, "install_in_rank, line %d: %s %s rank %d i = %d an = 0\n",
UNSUPPORTED("53h8d82ax23hys2k21hjswp72"); // 	      1034, agnameof(g), agnameof(n), r, i);
	return;
    }
    GD_rank(g).plus(r).getArray("v").plus(i).setPtr(n);
    ND_order(n, i);
    GD_rank(g).plus(r).setInt("n", 1+GD_rank(g).plus(r).getInt("n"));
    // assert(GD_rank(g)[r].n <= GD_rank(g)[r].an);
    if (ND_order(n) > GD_rank(Root).plus(r).getInt("an")) {
UNSUPPORTED("399szcw1txekt1xssyw7s2x07"); // 	agerr(AGERR, "install_in_rank, line %d: ND_order(%s) [%d] > GD_rank(Root)[%d].an [%d]\n",
UNSUPPORTED("9puojrmsk6vb1qc0jtr8ge4g8"); // 	      1052, agnameof(n), ND_order(n), r, GD_rank(Root)[r].an);
	return;
    }
    if ((r < GD_minrank(g)) || (r > GD_maxrank(g))) {
UNSUPPORTED("7o1thnqda767wqpe2lh9mj03t"); // 	agerr(AGERR, "install_in_rank, line %d: rank %d not in rank range [%d,%d]\n",
UNSUPPORTED("d2ugluzf7bmj7osicgitgy3sr"); // 	      1057, r, GD_minrank(g), GD_maxrank(g));
	return;
    }
    if (GD_rank(g).plus(r).getPtr("v").plus(ND_order(n)).comparePointer(
	GD_rank(g).plus(r).getPtr("av").plus(GD_rank(Root).plus(r).getInt("an")))>0) {
UNSUPPORTED("3eb32nc5czs5auwzz5p5mtl04"); // 	agerr(AGERR, "install_in_rank, line %d: GD_rank(g)[%d].v + ND_order(%s) [%d] > GD_rank(g)[%d].av + GD_rank(Root)[%d].an [%d]\n",
UNSUPPORTED("3qe3qpw5h6vse39xs1ca9sjmo"); // 	      1062, r, agnameof(n),GD_rank(g)[r].v + ND_order(n), r, r, GD_rank(g)[r].av+GD_rank(Root)[r].an);
	return;
    }
} finally {
LEAVING("3lxoqxhiri9fgt20zc5jz3aa5","install_in_rank");
}
}




//3 7t49bz6lfcbd9v63ds2x3518z
// void build_ranks(graph_t * g, int pass) 
public static void build_ranks(Agraph_s g, int pass) {
ENTERING("7t49bz6lfcbd9v63ds2x3518z","build_ranks");
try {
    int i, j;
    Agnode_s n, n0 = null;
    __ptr__ otheredges;
    nodequeue q;
    q = new_queue(GD_n_nodes(g));
    for (n = GD_nlist(g); n!=null; n = ND_next(n))
	ND_mark(n, 0);
    for (i = GD_minrank(g); i <= GD_maxrank(g); i++)
	GD_rank(g).plus(i).setInt("n", 0);
    for (n = GD_nlist(g); n!=null; n = ND_next(n)) {
	otheredges = ((pass == 0) ? ND_in(n).getPtr("list") : ND_out(n).getPtr("list"));
	if (otheredges.plus(0).getPtr() != null)
	    continue;
	if ((ND_mark(n)) == 0) {
	    ND_mark(n,  1);
	    enqueue(q, n);
	    while ((n0 = dequeue(q))!=null) {
		if (ND_ranktype(n0) != 7) {
		    install_in_rank(g, n0);
		    enqueue_neighbors(q, n0, pass);
		} else {
		    install_cluster(g, n0, pass, q);
		}
	    }
	}
    }
    if (dequeue(q)!=null)
UNSUPPORTED("1b3hbd5artrq77i58q2o9kgz3"); // 	agerr(AGERR, "surprise\n");
    for (i = GD_minrank(g); i <= GD_maxrank(g); i++) {
	GD_rank(Root).plus(i).setInt("valid", 0);
	if (GD_flip(g)!=0 && (GD_rank(g).plus(i).getInt("n") > 0)) {
	    int nn, ndiv2;
	    __ptr__ vlist = GD_rank(g).plus(i).getPtr("v");
	    nn = GD_rank(g).plus(i).getInt("n") - 1;
	    ndiv2 = nn / 2;
	    for (j = 0; j <= ndiv2; j++)
		exchange(vlist.plus(j), vlist.plus(nn - j));
	}
    }
    if (EQ(g, dot_root(g)) && ncross(g) > 0)
	transpose(g, 0);
    free_queue(q);
} finally {
LEAVING("7t49bz6lfcbd9v63ds2x3518z","build_ranks");
}
}




//3 bmjlneqxex6a9silzkkidkx6s
// void enqueue_neighbors(nodequeue * q, node_t * n0, int pass) 
public static void enqueue_neighbors(nodequeue q, Agnode_s n0, int pass) {
ENTERING("bmjlneqxex6a9silzkkidkx6s","enqueue_neighbors");
try {
    int i;
    Agedge_s e;
    if (pass == 0) {
	for (i = 0; i < ND_out(n0).getInt("size"); i++) {
	    e = (Agedge_s) ND_out(n0).getArray("list").plus(i).getPtr();
	    if (((ND_mark(aghead(e)))) == 0) {
		ND_mark(aghead(e), 1);
		enqueue(q, aghead(e));
	    }
	}
    } else {
UNSUPPORTED("2fk8dihf9myclulmd51g41fn8"); // 	for (i = 0; i < ND_in(n0).size; i++) {
UNSUPPORTED("8vxsji2yyf9q6dgwi3us9x4zb"); // 	    e = ND_in(n0).list[i];
UNSUPPORTED("drvqrqu2uwicmu2ay486xagp0"); // 	    if (((ND_mark(agtail(e)))) == 0) {
UNSUPPORTED("6i9d20jqol7kd3jyoctloi3hc"); // 		(ND_mark(agtail(e))) = NOT(0);
UNSUPPORTED("6v38ky7ayxhwvasmh3408hzai"); // 		enqueue(q, agtail(e));
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
    }
} finally {
LEAVING("bmjlneqxex6a9silzkkidkx6s","enqueue_neighbors");
}
}




//3 c8nqj0v20api63pikohsbx92u
// static int constraining_flat_edge(Agraph_t *g, Agnode_t *v, Agedge_t *e) 
public static Object constraining_flat_edge(Object... arg) {
UNSUPPORTED("zto1c4xs81uku2ye7zbhlwoz"); // static int constraining_flat_edge(Agraph_t *g, Agnode_t *v, Agedge_t *e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3960kx8v8i1zer793t4zlswdw"); // 	if (ED_weight(e) == 0) return 0;
UNSUPPORTED("4w7xujlzgd2uf0aontsqv3lb2"); // 	if (!inside_cluster(g,agtail(e))) return 0;
UNSUPPORTED("2bv0xsji024l93pkethdfl7hr"); // 	if (!inside_cluster(g,aghead(e))) return 0;
UNSUPPORTED("bp2y18pqq5n09006utwifdyxo"); // 	return NOT(0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 46to0pkk188af2dlkik2ab7e3
// static int postorder(graph_t * g, node_t * v, node_t ** list, int r) 
public static Object postorder(Object... arg) {
UNSUPPORTED("7a0o8pgfbtca0tg8dyqfvrskf"); // static int postorder(graph_t * g, node_t * v, node_t ** list, int r)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("b5a93beg34iiqtnufv9wanh2r"); //     int i, cnt = 0;
UNSUPPORTED("7sjtek8z32exmy4kt4swrpl04"); //     (ND_mark(v)) = NOT(0);
UNSUPPORTED("1k9cx50evf472qao05ebg91ng"); //     if (ND_flat_out(v).size > 0) {
UNSUPPORTED("bjd1q4wrt334u4l37r6wyvk9x"); // 	for (i = 0; (e = ND_flat_out(v).list[i]); i++) {
UNSUPPORTED("89s7oi9bkkajr6bf39b13szbo"); // 	    if (!constraining_flat_edge(g,v,e)) continue;
UNSUPPORTED("11adn0zmpyabt4ufn2agotiig"); // 	    if ((ND_mark(aghead(e))) == 0)
UNSUPPORTED("7afj95boikzsh6ue7dnez5wn6"); // 		cnt += postorder(g, aghead(e), list + cnt, r);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2tblnb9814cstqf6qtbzoubtx"); //     assert(ND_rank(v) == r);
UNSUPPORTED("6yxq51zz7jjlven205qqx37d5"); //     list[cnt++] = v;
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 zuxoswju917kyl08a5f0gtp6
// static void flat_reorder(graph_t * g) 
public static void flat_reorder(Agraph_s g) {
ENTERING("zuxoswju917kyl08a5f0gtp6","flat_reorder");
try {
    int i, j, r, pos, n_search, local_in_cnt, local_out_cnt, base_order;
    Agnode_s v, t;
    __ptr__ left, right;
    __ptr__ temprank = null;
    Agedge_s flat_e, e;
    if (GD_has_flat_edges(g) == 0)
	return;
UNSUPPORTED("60nab7gyukq3bs8e6dizhbacy"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("2xm6bhb8x1bdvvm79rdx4ih8k"); // 	if (GD_rank(g)[r].n == 0) continue;
UNSUPPORTED("43wkd0u4gt5f22bo4b81tpj18"); // 	base_order = ND_order(GD_rank(g)[r].v[0]);
UNSUPPORTED("930yyqztt6dbtgwp49heo6aa7"); // 	for (i = 0; i < GD_rank(g)[r].n; i++)
UNSUPPORTED("dz61yb90hbycduz1zl0palr7i"); // 	    (ND_mark(GD_rank(g)[r].v[i])) = 0;
UNSUPPORTED("8bg3a9yayjyik2zurmxun7b2a"); // 	temprank = ALLOC(i + 1, temprank, node_t *);
UNSUPPORTED("ptj0sxywmshehzmr5058z3ld"); // 	pos = 0;
UNSUPPORTED("heovdmfd7dmyls9n93y5ao8w"); // 	/* construct reverse topological sort order in temprank */
UNSUPPORTED("6eix918gmfs16624x6omusuhm"); // 	for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("phr38thvtlbcjq1u87vo3r23"); // 	    if (GD_flip(g)) v = GD_rank(g)[r].v[i];
UNSUPPORTED("6y4xt5s32t191ksegr3it73b2"); // 	    else v = GD_rank(g)[r].v[GD_rank(g)[r].n - i - 1];
UNSUPPORTED("80lfdxbk10vp5rvtxkk5wj5ds"); // 	    local_in_cnt = local_out_cnt = 0;
UNSUPPORTED("bl3do7s57na7xpv6f1vdbmyve"); // 	    for (j = 0; j < ND_flat_in(v).size; j++) {
UNSUPPORTED("e96fdaq6dg03b925jfjo2kpx9"); // 		flat_e = ND_flat_in(v).list[j];
UNSUPPORTED("larig8jnxb7ncytin6qrhq59"); // 		if (constraining_flat_edge(g,v,flat_e)) local_in_cnt++;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("3dy5d7z3uazd4h4yyct78ghnu"); // 	    for (j = 0; j < ND_flat_out(v).size; j++) {
UNSUPPORTED("dva1y1bkf4j66nkebj52la0i6"); // 		flat_e = ND_flat_out(v).list[j];
UNSUPPORTED("2rgbk1kji5v8o4ybrrs4ls262"); // 		if (constraining_flat_edge(g,v,flat_e)) local_out_cnt++;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("8o4pi1ans4czypy73ni9zgsnx"); // 	    if ((local_in_cnt == 0) && (local_out_cnt == 0))
UNSUPPORTED("9nashj3bi59s5cdaa5a7sto8i"); // 		temprank[pos++] = v;
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("1ezp9srjuy982ufzobpcuuisu"); // 		if (((ND_mark(v)) == 0) && (local_in_cnt == 0)) {
UNSUPPORTED("a0cdgbreyl50679zmodu8jcj7"); // 		    left = temprank + pos;
UNSUPPORTED("ewczn7sv1xkn79j21j6y98nna"); // 		    n_search = postorder(g, v, left, r);
UNSUPPORTED("9xx3k65ddahr2zhjqsy9k4d5e"); // 		    pos += n_search;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("exh0x53ewc1trtk2sr9j89dlv"); // 	if (pos) {
UNSUPPORTED("4qkwn54estl5dx8jlgzlyraqo"); // 	    if (GD_flip(g) == 0) {
UNSUPPORTED("aoz8iesotnzpotyuf6ft5oifs"); // 		left = temprank;
UNSUPPORTED("dvxhjx37ryagjnn8012r3lab8"); // 		right = temprank + pos - 1;
UNSUPPORTED("1kao1dlkemj6wsxv5pn1h61uw"); // 		while (left < right) {
UNSUPPORTED("47h36vbyykmhp4m0k8gf0hpmq"); // 		    t = *left;
UNSUPPORTED("235bgn7jwjpkg14gvd07fhz7h"); // 		    *left = *right;
UNSUPPORTED("979a47z6ouhljp1uf4l8y19pw"); // 		    *right = t;
UNSUPPORTED("5abi92edlhj6xlcwxgcsi7nj4"); // 		    left++;
UNSUPPORTED("4xtkerapdpuh4g359203xnbhh"); // 		    right--;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("ekjgpp51cwp03bcjy2ujywyo9"); // 	    for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("5s8v862nltdximeipdvny9y1f"); // 		v = GD_rank(g)[r].v[i] = temprank[i];
UNSUPPORTED("5kb820ryu1ki992hjcxkz57or"); // 		ND_order(v) = i + base_order;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("bi573dmi6584mc3zavlx7d3eq"); // 	    /* nonconstraint flat edges must be made LR */
UNSUPPORTED("ekjgpp51cwp03bcjy2ujywyo9"); // 	    for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("93xv71x0pyo09i8el5dtgsr5z"); // 		v = GD_rank(g)[r].v[i];
UNSUPPORTED("2v2exvmxlze26y0d0kispv9fw"); // 		if (ND_flat_out(v).list) {
UNSUPPORTED("dyi5yufj0afxef8enqddgd7uz"); // 		    for (j = 0; (e = ND_flat_out(v).list[j]); j++) {
UNSUPPORTED("4b127pxbma7th1i5vtdmpsv0a"); // 			if ( ((GD_flip(g) == 0) && (ND_order(aghead(e)) < ND_order(agtail(e)))) ||
UNSUPPORTED("9dc4vox9k8rdfjaqvaf0xnksx"); // 				 ( (GD_flip(g)) && (ND_order(aghead(e)) > ND_order(agtail(e)) ))) {
UNSUPPORTED("3omkik04m6s1wn9lkk45pivko"); // 			    assert(constraining_flat_edge(g,v,e) == 0);
UNSUPPORTED("7ebw4lyjfgu8v0is6gfktqm7x"); // 			    delete_flat_edge(e);
UNSUPPORTED("39xps1d6e8rc55xmsxaunuia8"); // 			    j--;
UNSUPPORTED("1w583swkkvuwckydgv3bcn71d"); // 			    flat_rev(g, e);
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("cvr0qehm47iqjy6mr0gf98ezh"); // 	    /* postprocess to restore intended order */
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("cmw1tuaeuiic11679pz61lx30"); // 	/* else do no harm! */
UNSUPPORTED("aiubcqxqgke7s3v2d7ukdxub4"); // 	GD_rank(Root)[r].valid = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("eedt0djlt1d5wfxm9242oovdy"); //     if (temprank)
UNSUPPORTED("32y50hmbvwlkczwe82ltwu0s5"); // 	free(temprank);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("zuxoswju917kyl08a5f0gtp6","flat_reorder");
}
}




//3 inv6wazjcnh4xkzzphsdcmg4
// static void reorder(graph_t * g, int r, int reverse, int hasfixed) 
public static Object reorder(Object... arg) {
UNSUPPORTED("d2gtoanpfdiw5mkt7u0osaskn"); // static void reorder(graph_t * g, int r, int reverse, int hasfixed)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2pttwwu34vku8bnn74l7o5y43"); //     int changed = 0, nelt;
UNSUPPORTED("2pk8zraqu46gix2yg9gs9ek50"); //     boolean muststay, sawclust;
UNSUPPORTED("bch13lhp7kv18gai0hymoyl3m"); //     node_t **vlist = GD_rank(g)[r].v;
UNSUPPORTED("23obs0sd0xi9le9od6pt7xouh"); //     node_t **lp, **rp, **ep = vlist + GD_rank(g)[r].n;
UNSUPPORTED("9753zpr89tspjcn9laej9os7p"); //     for (nelt = GD_rank(g)[r].n - 1; nelt >= 0; nelt--) {
UNSUPPORTED("275srmtfp4jybgu0bhytv0pjr"); // 	lp = vlist;
UNSUPPORTED("99j4h8rjy893vmdj4hmcsgvw4"); // 	while (lp < ep) {
UNSUPPORTED("69sj6q2suaycj6qaywrivthxh"); // 	    /* find leftmost node that can be compared */
UNSUPPORTED("ctvnnejl6zitj7h32jnfqo280"); // 	    while ((lp < ep) && (ND_mval(*lp) < 0))
UNSUPPORTED("95szyny68d7rd5ego5miqll8e"); // 		lp++;
UNSUPPORTED("cojuos66422zpwb964mfjrhex"); // 	    if (lp >= ep)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("190b0lixapa1aqf77t51lz2tu"); // 	    /* find the node that can be compared */
UNSUPPORTED("da9ewrprx858zhxrme74rx6jc"); // 	    sawclust = muststay = 0;
UNSUPPORTED("73odlkcle5wwpjduxm9tyyzgo"); // 	    for (rp = lp + 1; rp < ep; rp++) {
UNSUPPORTED("a82jg7laskogxw4g7i5e18z2r"); // 		if (sawclust && ND_clust(*rp))
UNSUPPORTED("bd5cs1aheb7llicpwzh84szjx"); // 		    continue;	/* ### */
UNSUPPORTED("4bevuqvfmky9s66sm8wahlzeg"); // 		if (left2right(g, *lp, *rp)) {
UNSUPPORTED("38ugslz70aqlem2tn9zvb7mz7"); // 		    muststay = NOT(0);
UNSUPPORTED("czyohktf9bkx4udfqhx42f4lu"); // 		    break;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("36gjruh8s2hf94ls65s0l6wn9"); // 		if (ND_mval(*rp) >= 0)
UNSUPPORTED("czyohktf9bkx4udfqhx42f4lu"); // 		    break;
UNSUPPORTED("cxzj7p9b32vn7m05kw0x76fwe"); // 		if (ND_clust(*rp))
UNSUPPORTED("eyoojv4xhe7djuinf635js9al"); // 		    sawclust = NOT(0);	/* ### */
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("569py4x39oljvbcut28zhr5r8"); // 	    if (rp >= ep)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("8osogrn4rtcfubd30d9zfm2vd"); // 	    if (muststay == 0) {
UNSUPPORTED("22usozfm50fk3plindg228wbf"); // 		register int p1 = (ND_mval(*lp));
UNSUPPORTED("86n705sctn1ilc92yf1uz2qqd"); // 		register int p2 = (ND_mval(*rp));
UNSUPPORTED("57u1bw85da2bh8onwhvj6vzei"); // 		if ((p1 > p2) || ((p1 == p2) && (reverse))) {
UNSUPPORTED("6bj5d81plk45t5bh7yvuppcvj"); // 		    exchange(*lp, *rp);
UNSUPPORTED("8ibdppb0ordxkgcnhrrutpyxk"); // 		    changed++;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("bz5jma0qhcnrzhpqzcflr7tb7"); // 	    lp = rp;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bpm09l7inao762qwxrihmtbew"); // 	if ((hasfixed == 0) && (reverse == 0))
UNSUPPORTED("4xizdrzqci1qgfdmtjb7wi6wv"); // 	    ep--;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("20w7d59r1l0c34y8izq32fd0e"); //     if (changed) {
UNSUPPORTED("aiubcqxqgke7s3v2d7ukdxub4"); // 	GD_rank(Root)[r].valid = 0;
UNSUPPORTED("cgm6fukyvwfd25scdaookuw8h"); // 	if (r > 0)
UNSUPPORTED("a9i8190znzebye2otdd0qtcyy"); // 	    GD_rank(Root)[r - 1].valid = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 14t80owwvm7io4ou6czb9ba9
// static void mincross_step(graph_t * g, int pass) 
public static Object mincross_step(Object... arg) {
UNSUPPORTED("1mvbma6k9fev9lh1lkb518gmv"); // static void mincross_step(graph_t * g, int pass)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("95fqu2vaepji5voog0r4h4asf"); //     int r, other, first, last, dir;
UNSUPPORTED("dgls5gjrfd2g5nmz4hhtg1g51"); //     int hasfixed, reverse;
UNSUPPORTED("czoqeq91xnlacjso1v7ylqy2z"); //     if ((pass % 4) < 2)
UNSUPPORTED("1ut9g5ncig7xqfdo1vzk4w4d5"); // 	reverse = NOT(0);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("2j399i52nn6k6nbwai778x7fm"); // 	reverse = 0;
UNSUPPORTED("ctbxmice6rvaxzpmvge7m6xf"); //     if (pass % 2) {
UNSUPPORTED("8v6vde090kbqbjd5ddaodesie"); // 	r = GD_maxrank(g) - 1;
UNSUPPORTED("dnf0hfgr2t10wplwdhq2opceu"); // 	dir = -1;
UNSUPPORTED("8f1y0u57y2egqaf5jncjdx0b"); //     } /* up pass */
UNSUPPORTED("1nyzbeonram6636b1w955bypn"); //     else {
UNSUPPORTED("5j2phi2zkje8kvjn46u8addz3"); // 	r = 1;
UNSUPPORTED("4tu6k4gwplcalffq4tkhxmzvx"); // 	dir = 1;
UNSUPPORTED("63lql6fj129k2ddlk3w7woghm"); //     }				/* down pass */
UNSUPPORTED("dzal2mhcuavihfq9iy5cf3f6o"); //     if (pass % 2 == 0) {	/* down pass */
UNSUPPORTED("6t0i7oxmw8snray05dq4yubx5"); // 	first = GD_minrank(g) + 1;
UNSUPPORTED("dnw1i2c7m3lsx99gplzcbpaiw"); // 	if (GD_minrank(g) > GD_minrank(Root))
UNSUPPORTED("4yah8r37e2l8ffdzqv0k8eg21"); // 	    first--;
UNSUPPORTED("bvbz68k307ey5l0gc5hds93tb"); // 	last = GD_maxrank(g);
UNSUPPORTED("4tu6k4gwplcalffq4tkhxmzvx"); // 	dir = 1;
UNSUPPORTED("84knts11hkt1f1vv29b0vr6yr"); //     } else {			/* up pass */
UNSUPPORTED("55cjk8cmgd4u0wxo8fzb385yk"); // 	first = GD_maxrank(g) - 1;
UNSUPPORTED("9kao74nao5exa7oa6om2np33t"); // 	last = GD_minrank(g);
UNSUPPORTED("5t93a90bt9h88n15fjnqlpsls"); // 	if (GD_maxrank(g) < GD_maxrank(Root))
UNSUPPORTED("c261ezi0uyacksq8rgcygup7b"); // 	    first++;
UNSUPPORTED("dnf0hfgr2t10wplwdhq2opceu"); // 	dir = -1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7a9bh4h04ow7trfhqoewvf29q"); //     for (r = first; r != last + dir; r += dir) {
UNSUPPORTED("cy1d32pdxsrayceiergvqhg3e"); // 	other = r - dir;
UNSUPPORTED("7erema4v0ja6rtdehjlll7qc4"); // 	hasfixed = medians(g, r, other);
UNSUPPORTED("2zr6bfo1sm1546ljk4723tnko"); // 	reorder(g, r, reverse, hasfixed);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1lvy7q57hte3hd1cs93grwv44"); //     transpose(g, NOT(reverse));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 aq18oa4k4grixvfjx7r2qnl6r
// static int local_cross(elist l, int dir) 
public static int local_cross(final __struct__<elist> l, int dir) {
// WARNING!! STRUCT
return local_cross_w_(l.copy(), dir);
}
private static int local_cross_w_(final __struct__<elist> l, int dir) {
ENTERING("aq18oa4k4grixvfjx7r2qnl6r","local_cross");
try {
 UNSUPPORTED("3jmndo6p8u1x5wp297qpt0jto"); // static int local_cross(elist l, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2gmuwkiycm22in3d9obd7bzll"); //     int i, j, is_out;
UNSUPPORTED("bcforqedbns82qhgqkocjbvm"); //     int cross = 0;
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("8az9seos08f2sa39127q6yo9"); //     if (dir > 0)
UNSUPPORTED("8xj2loay6suplxyiun7hlye39"); // 	is_out = NOT(0);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("56xhe3qw67sg923dvr87k8hho"); // 	is_out = 0;
UNSUPPORTED("16t717mqlhfn3egmgor8are83"); //     for (i = 0; (e = l.list[i]); i++) {
UNSUPPORTED("3lbek06034x2gsimhxwfmgf0r"); // 	if (is_out)
UNSUPPORTED("2pkmgz4cm8lwpwxgcg3znjm90"); // 	    for (j = i + 1; (f = l.list[j]); j++) {
UNSUPPORTED("8wj6phwqlmunjcua9abo6093d"); // 		if ((ND_order(aghead(f)) - ND_order(aghead(e)))
UNSUPPORTED("pt12knuv94kokmtrwpdp1m0j"); // 			 * (ED_tail_port(f).p.x - ED_tail_port(e).p.x) < 0)
UNSUPPORTED("bw8rwv11yqzss88pad7ljil8a"); // 		    cross += ED_xpenalty(e) * ED_xpenalty(f);
UNSUPPORTED("6to1esmb8qfrhzgtr7jdqleja"); // 	} else
UNSUPPORTED("2pkmgz4cm8lwpwxgcg3znjm90"); // 	    for (j = i + 1; (f = l.list[j]); j++) {
UNSUPPORTED("bza83c6rmihrkzyllwf0jm4tn"); // 		if ((ND_order(agtail(f)) - ND_order(agtail(e)))
UNSUPPORTED("csrxg0y1azmvde7t833lm13sp"); // 			* (ED_head_port(f).p.x - ED_head_port(e).p.x) < 0)
UNSUPPORTED("bw8rwv11yqzss88pad7ljil8a"); // 		    cross += ED_xpenalty(e) * ED_xpenalty(f);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8dm5o3tsfvxtjilyob6q5ndi1"); //     return cross;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("aq18oa4k4grixvfjx7r2qnl6r","local_cross");
}
}




//3 bk5nklhfqgg0uwkv7tv6dn8r2
// static int rcross(graph_t * g, int r) 
static __ptr__ Count;
static int C;
public static int rcross(Agraph_s g, int r) {
ENTERING("bk5nklhfqgg0uwkv7tv6dn8r2","rcross");
try {
    int top, bot, cross, max, i, k;
    Agnode_s v;
    __ptr__ rtop;
    cross = 0;
    max = 0;
    rtop = GD_rank(g).plus(r).getPtr("v");
    if (C <= GD_rank(Root).plus(r + 1).getInt("n")) {
	C = GD_rank(Root).plus(r + 1).getInt("n") + 1;
	Count = ALLOC_INT(C, Count);
    }
    for (i = 0; i < GD_rank(g).plus(r + 1).getInt("n"); i++)
	Count.plus(i).setInt(0);
    for (top = 0; top < GD_rank(g).plus(r).getInt("n"); top++) {
	Agedge_s e;
	if (max > 0) {
	    for (i = 0; (e = (Agedge_s) ND_out(rtop.plus(top).getPtr()).getArray("list").plus(i).getPtr())!=null; i++) {
		for (k = ND_order(aghead(e)) + 1; k <= max; k++)
		    cross += Count.plus(k).getInt() * ED_xpenalty(e);
	    }
	}
	for (i = 0; (e = (Agedge_s) ND_out(rtop.plus(top).getPtr()).getArray("list").plus(i).getPtr())!=null; i++) {
	    int inv = ND_order(aghead(e));
	    if (inv > max)
		max = inv;
	    Count.plus(inv).setInt(Count.plus(inv).getInt() + ED_xpenalty(e));
	}
    }
    for (top = 0; top < GD_rank(g).plus(r).getInt("n"); top++) {
	v = (Agnode_s) GD_rank(g).plus(r).getArray("v").plus(top).getPtr();
	if (ND_has_port(v))
	    cross += local_cross(ND_out(v), 1);
    }
    for (bot = 0; bot < GD_rank(g).plus(r + 1).getInt("n"); bot++) {
	v = (Agnode_s) GD_rank(g).plus(r + 1).getArray("v").plus(bot).getPtr();
	if (ND_has_port(v))
	    cross += local_cross(ND_in(v), -1);
    }
    return cross;
} finally {
LEAVING("bk5nklhfqgg0uwkv7tv6dn8r2","rcross");
}
}




//3 dbjmz2tnii2pn9sxg26ap6w5r
// int ncross(graph_t * g) 
public static int ncross(Agraph_s g) {
ENTERING("dbjmz2tnii2pn9sxg26ap6w5r","ncross");
try {
    int r, count, nc;
    g = Root;
    count = 0;
    for (r = GD_minrank(g); r < GD_maxrank(g); r++) {
	if (GD_rank(g).plus(r).getBoolean("valid"))
	    count += GD_rank(g).plus(r).getInt("cache_nc");
	else {
	    nc = rcross(g, r);
	    GD_rank(g).plus(r).getInt("cache_nc");
	    count += nc;
	    GD_rank(g).plus(r).setInt("valid", 1);
	}
    }
    return count;
} finally {
LEAVING("dbjmz2tnii2pn9sxg26ap6w5r","ncross");
}
}




//3 8wrsq8a2vooekcm3cdtv5x3ke
// static int ordercmpf(int *i0, int *i1) 
public static Object ordercmpf(Object... arg) {
UNSUPPORTED("bf95fyql6mp4ao42taf6gh16n"); // static int ordercmpf(int *i0, int *i1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("agud7qua9v0xbhsvctafmfscj"); //     return (*i0) - (*i1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7397kynkpqf2m1jkpmi8pgf0n
// static int flat_mval(node_t * n) 
public static Object flat_mval(Object... arg) {
UNSUPPORTED("d7wv7aygz17tourswfhc1ybk1"); // static int flat_mval(node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("bz82tc608ha0mxaew277j1h1t"); //     edge_t *e, **fl;
UNSUPPORTED("8cudi8s29q4uqmilbu8c75v3p"); //     node_t *nn;
UNSUPPORTED("45sjfv1n0rivlh2hbx0t78a4z"); //     if (ND_flat_in(n).size > 0) {
UNSUPPORTED("5yzdvn5f31lcaqlwrtyfgigyi"); // 	fl = ND_flat_in(n).list;
UNSUPPORTED("cdgs9itwofluy6pfx1s108e9n"); // 	nn = agtail(fl[0]);
UNSUPPORTED("7oyk0wv990mngda8xb3rrxwvg"); // 	for (i = 1; (e = fl[i]); i++)
UNSUPPORTED("4xlgkm7relaep0wq7joiygx4u"); // 	    if (ND_order(agtail(e)) > ND_order(nn))
UNSUPPORTED("9eqy9zetc3s5ha28tbqf2x0v5"); // 		nn = agtail(e);
UNSUPPORTED("5lofkcdblc6studc2t68hnwkr"); // 	if (ND_mval(nn) >= 0) {
UNSUPPORTED("au3d77a1gzr4g8m345w8wjr3w"); // 	    ND_mval(n) = ND_mval(nn) + 1;
UNSUPPORTED("6f1138i13x0xz1bf1thxgjgka"); // 	    return 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("508llhidjyn7aoa6u49sx8sdp"); //     } else if (ND_flat_out(n).size > 0) {
UNSUPPORTED("5dhk8ij2irqhw0s7b3iinjb7n"); // 	fl = ND_flat_out(n).list;
UNSUPPORTED("d633mc6w6s80ek622u99nkgfb"); // 	nn = aghead(fl[0]);
UNSUPPORTED("7oyk0wv990mngda8xb3rrxwvg"); // 	for (i = 1; (e = fl[i]); i++)
UNSUPPORTED("bttvlsn98f1q60po8dfn10pt7"); // 	    if (ND_order(aghead(e)) < ND_order(nn))
UNSUPPORTED("ebvdk4oxglz1u4mtvz5zlqsjp"); // 		nn = aghead(e);
UNSUPPORTED("9yzbc71vzbg5fnbb9qandc9xn"); // 	if (ND_mval(nn) > 0) {
UNSUPPORTED("q4i6d9bz7r7tcwpu6obu16z1"); // 	    ND_mval(n) = ND_mval(nn) - 1;
UNSUPPORTED("6f1138i13x0xz1bf1thxgjgka"); // 	    return 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8fwlqtemsmckleh6946lyd8mw"); //     return NOT(0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 azvdpixwwxspl31wp7f4k4fmh
// static boolean medians(graph_t * g, int r0, int r1) 
public static Object medians(Object... arg) {
UNSUPPORTED("2ikf6cf8f6a5al0rdgt6usfrp"); // static boolean medians(graph_t * g, int r0, int r1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b6obh0dz63e7lymu8wmlj5x1y"); //     int i, j, j0, lm, rm, lspan, rspan, *list;
UNSUPPORTED("31xfs5mnujy9r6bn3pf3tkth4"); //     node_t *n, **v;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("m4u61nakl3lriv8ejnikozv"); //     boolean hasfixed = 0;
UNSUPPORTED("s1t04g2vgccmkb23bagitauo"); //     list = TI_list;
UNSUPPORTED("enfjcfrcglrm7gnd9zyhzq3pa"); //     v = GD_rank(g)[r0].v;
UNSUPPORTED("arb5acfjsnq6bs3wl1mnokg9n"); //     for (i = 0; i < GD_rank(g)[r0].n; i++) {
UNSUPPORTED("el91kvksppze2ehvfdjchy1gv"); // 	n = v[i];
UNSUPPORTED("5yl8ot1s4iv64jpw5pasb7slf"); // 	j = 0;
UNSUPPORTED("104tt5wp63poomudf31gtj63k"); // 	if (r1 > r0)
UNSUPPORTED("cfq3da97bh0w5vtcwz5a9duqq"); // 	    for (j0 = 0; (e = ND_out(n).list[j0]); j0++) {
UNSUPPORTED("2rc4zobv6gl18x0k4528qvpzd"); // 		if (ED_xpenalty(e) > 0)
UNSUPPORTED("4gvdqifo1brsf40bgim0f7lqw"); // 		    list[j++] = (256 * ND_order(aghead(e)) + (ED_head_port(e)).order);
UNSUPPORTED("6to1esmb8qfrhzgtr7jdqleja"); // 	} else
UNSUPPORTED("5fxijsny5lcaojo140trezzkf"); // 	    for (j0 = 0; (e = ND_in(n).list[j0]); j0++) {
UNSUPPORTED("2rc4zobv6gl18x0k4528qvpzd"); // 		if (ED_xpenalty(e) > 0)
UNSUPPORTED("3vxk16libl8tf9du61ffb63rm"); // 		    list[j++] = (256 * ND_order(agtail(e)) + (ED_tail_port(e)).order);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("3vgr0lc4p64bdfo0yy4nfktp2"); // 	switch (j) {
UNSUPPORTED("46lzlkypfilrge90rkaiveuyb"); // 	case 0:
UNSUPPORTED("11ponhqwd1l1bk186my3q138e"); // 	    ND_mval(n) = -1;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("2o83im06dulx11wjpy469gkoa"); // 	case 1:
UNSUPPORTED("myu2kb4qqw15lsgy02ws35gz"); // 	    ND_mval(n) = list[0];
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("b8vgbvwzllfs4lrqmmqyr1spk"); // 	case 2:
UNSUPPORTED("cx74ve72qnax2cprftk1bghgf"); // 	    ND_mval(n) = (list[0] + list[1]) / 2;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("1drv0xz8hp34qnf72b4jpprg2"); // 	default:
UNSUPPORTED("cti95m853ppunt20s4rbu6tz3"); // 	    qsort(list, j, sizeof(int), (qsort_cmpf) ordercmpf);
UNSUPPORTED("b699h9lfjtbtyn86zoq4va4qr"); // 	    if (j % 2)
UNSUPPORTED("8el5hli3q3zlryjkjcuio2xgb"); // 		ND_mval(n) = list[j / 2];
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("4xnbdpxs85oalv7pefwu8g15y"); // 		/* weighted median */
UNSUPPORTED("bq3anpjb3xrserq9h2kolc9bp"); // 		rm = j / 2;
UNSUPPORTED("d3e3mm7qk6e07psjprn7g0n46"); // 		lm = rm - 1;
UNSUPPORTED("3m7xa7lrd2o9gsx8q09jost3y"); // 		rspan = list[j - 1] - list[rm];
UNSUPPORTED("6k166nalo17jn6mp9y8ezzw4x"); // 		lspan = list[lm] - list[0];
UNSUPPORTED("3ggu6qa3baoie2bu76zq87mxb"); // 		if (lspan == rspan)
UNSUPPORTED("d7bvav9t29xxiwan6ajpi87pk"); // 		    ND_mval(n) = (list[lm] + list[rm]) / 2;
UNSUPPORTED("d28blrbmwwqp80cyksuz7dwx9"); // 		else {
UNSUPPORTED("2ytw7i85l0wuz8p7w1d9gh609"); // 		    int w = list[lm] * rspan + list[rm] * lspan;
UNSUPPORTED("6nnw909f6gkwy8858wrf1aew1"); // 		    ND_mval(n) = w / (lspan + rspan);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("arb5acfjsnq6bs3wl1mnokg9n"); //     for (i = 0; i < GD_rank(g)[r0].n; i++) {
UNSUPPORTED("el91kvksppze2ehvfdjchy1gv"); // 	n = v[i];
UNSUPPORTED("roadxhdvaxn0r8127od1zy1t"); // 	if ((ND_out(n).size == 0) && (ND_in(n).size == 0))
UNSUPPORTED("656sku1ts3u07tqwzgdi65tf0"); // 	    hasfixed |= flat_mval(n);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4hezjlrwkxyuviybynn7thu0d"); //     return hasfixed;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2vdhpcykq508ma83aif8sxcbd
// static int nodeposcmpf(node_t ** n0, node_t ** n1) 
public static Object nodeposcmpf(Object... arg) {
UNSUPPORTED("1xny6jeltp1wrbsg58eeyxsna"); // static int nodeposcmpf(node_t ** n0, node_t ** n1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7c005ftjaf2a12m8lybcajp9n"); //     return (ND_order(*n0) - ND_order(*n1));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 87c98ld9c4hv87ekcxdyojx8l
// static int edgeidcmpf(edge_t ** e0, edge_t ** e1) 
public static Object edgeidcmpf(Object... arg) {
UNSUPPORTED("apvyql25ya1p7w7i7396gucdg"); // static int edgeidcmpf(edge_t ** e0, edge_t ** e1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9gjc2rit3ezq4il0t5aymk1z"); //     return (AGSEQ(*e0) - AGSEQ(*e1));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 40as9opn4mzq4gp4nkmp4dj8w
// static int table[3][3] = 
private static int table[][] = new int[][]{
    /* ordinary */ {1, 1, 1},
    /* singleton */ {1, 2, 2},
    /* virtual */ {1, 2, 4}
};



//3 7j638prioxd97f74v1v4adbsf
// static int endpoint_class(node_t * n) 
public static int endpoint_class(Agnode_s n) {
ENTERING("7j638prioxd97f74v1v4adbsf","endpoint_class");
try {
    if (ND_node_type(n) == 1)
	return 2;
    if (ND_weight_class(n) <= 1)
	return 1;
    return 0;
} finally {
LEAVING("7j638prioxd97f74v1v4adbsf","endpoint_class");
}
}




//3 es57bn7ga4wc9tqtcixpn0451
// void virtual_weight(edge_t * e) 
public static void virtual_weight(Agedge_s e) {
ENTERING("es57bn7ga4wc9tqtcixpn0451","virtual_weight");
try {
    int t;
    t = table[endpoint_class(agtail(e))][endpoint_class(aghead(e))];
    ED_weight(e, ED_weight(e) * t);
} finally {
LEAVING("es57bn7ga4wc9tqtcixpn0451","virtual_weight");
}
}




//3 7ru09oqbudpeofsthzveig2m2
// static void mincross_options(graph_t * g) 
public static void mincross_options(Agraph_s g) {
ENTERING("7ru09oqbudpeofsthzveig2m2","mincross_options");
try {
    CString p;
    double f;
    /* set default values */
    MinQuit = 8;
    MaxIter = 24;
    Convergence = .995;
    p = agget(g, new CString("mclimit"));
    if (p!=null && ((f = atof(p)) > 0.0)) {
UNSUPPORTED("4iu53eiz077u6joqgwawca8ya"); // 	MinQuit = ((1)>(MinQuit * f)?(1):(MinQuit * f));
UNSUPPORTED("38po81l36cibw6jc3qlsscpcu"); // 	MaxIter = ((1)>(MaxIter * f)?(1):(MaxIter * f));
    }   
} finally {
LEAVING("7ru09oqbudpeofsthzveig2m2","mincross_options");
}
}


}
