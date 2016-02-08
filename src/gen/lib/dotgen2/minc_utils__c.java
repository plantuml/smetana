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
package gen.lib.dotgen2;
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

public class minc_utils__c {
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




//3 9t1glmpcara0suj4k06js5e7o
// static Agedge_t* mapEdge (Dt_t* emap, Agedge_t* e) 
public static Object mapEdge(Object... arg) {
UNSUPPORTED("6brdr8wx9pidlrz4g71hamlqp"); // static Agedge_t*
UNSUPPORTED("jpn5ncdkcwoldbkeust283qc"); // mapEdge (Dt_t* emap, Agedge_t* e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("d1c5hr23pln3amc9hsddtwo5l"); //      edgepair_t* ep = (*(((Dt_t*)(emap))->searchf))((emap),(void*)(&e),0001000);
UNSUPPORTED("20yx7jzbnoln06dqzmde1sl1u"); //      if (ep) return ep->val;
UNSUPPORTED("dkboa8aqx9tmlrnepq5retl9k"); //      else return NULL;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 95ol4qn9744ugej6kkiv8zfq3
// static int cmppair(Dt_t * d, Agedge_t** key1, Agedge_t** key2, Dtdisc_t * disc) 
public static Object cmppair(Object... arg) {
UNSUPPORTED("5yyi8m15w2kjqwudc9duv92gt"); // static int cmppair(Dt_t * d, Agedge_t** key1, Agedge_t** key2, Dtdisc_t * disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7bzwfv0pzp2sxf8zky27739ay"); //     if (*key1 > *key2) return 1;
UNSUPPORTED("kxikrbjbmafnai9p6gjs3nyx"); //     else if (*key1 < *key2) return -1;
UNSUPPORTED("895k5gbyc2kla939upm8m5u76"); //     else return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 exdrndxi7kutrtm0utmotyyy
// static Dtdisc_t edgepair = 




//3 bu02als6475swjagcglc1g55o
// static void cloneSubg (Agraph_t* parent, Agraph_t* sg, Dt_t* emap) 
public static Object cloneSubg(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("45e7kn8ba6x6pks9qhg2d7tsk"); // cloneSubg (Agraph_t* parent, Agraph_t* sg, Dt_t* emap)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("6fav2eq8otcpsz36rup4o6aqu"); //     Agraph_t* subg;
UNSUPPORTED("4xszs8qyovowwc9h1ezmojmwi"); //     Agnode_t* t;
UNSUPPORTED("6yramhpyls8c6kexupyqip8oq"); //     Agedge_t* e;
UNSUPPORTED("5q44qzfigjxvxalmgwkw40zey"); //     Agnode_t* newt;
UNSUPPORTED("6r402vmybtwrin17oo4i3ohg6"); //     Agedge_t* newe;
UNSUPPORTED("1ofwqtpxz3yqn1nwfwdd34hhj"); //     Agraph_t* newg;
UNSUPPORTED("86yzckjehbaja1gzmxvzvqero"); //     if (is_a_cluster(sg)) {
UNSUPPORTED("4i6anctqrjtd5k8c6slsldnc1"); // 	newg = agsubg (parent, agnameof(sg), 1);
UNSUPPORTED("cruq23strawdc7rq21e9dkjvx"); // 	parent = newg; 
UNSUPPORTED("cptzf4uy7bdihz6lreh33a31d"); // 	for (t = agfstnode(sg); t; t = agnxtnode(sg, t)) {
UNSUPPORTED("3x0klr7nqbbn8j17phlr0wx4m"); // 	    newt = agnode(newg, agnameof(t), 0);
UNSUPPORTED("2alfw3a1nkv5jxihshiinqffc"); //             agsubnode(newg, newt, 1);
UNSUPPORTED("blh3ce4dfoaauuj5zj3uen0xa"); // 	    /* if e is in sg, both end points are, so we can use out edges */
UNSUPPORTED("dhhjfiv0fem9f1d4s6ivquvpl"); // 	    for (e = agfstout(sg, t); e; e = agnxtout(sg, e)) {
UNSUPPORTED("3rfclhh58bunpjlud81racfye"); // 		newe = mapEdge (emap, e);
UNSUPPORTED("5b1ind9v42e5ayivaq2d2eqb8"); // 		agsubedge(newg, newe, 1);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5tbjdg70q26bo3m3a4i61ydps"); //     for (subg = agfstsubg(sg); subg; subg = agnxtsubg(subg)) {
UNSUPPORTED("647q6uzccemqoi16g2mzmhqt5"); // 	cloneSubg(parent, subg, emap);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bvbg3j4upzfnuc0ml80xgobap
// Agraph_t*  mkMCGraph (Agraph_t* g) 
public static Object mkMCGraph(Object... arg) {
UNSUPPORTED("9i460shslbpmfnl7dzwodh0hr"); // Agraph_t* 
UNSUPPORTED("1d5k1jjvpvsnmuobvx5tirvbe"); // mkMCGraph (Agraph_t* g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4xszs8qyovowwc9h1ezmojmwi"); //     Agnode_t* t;
UNSUPPORTED("5q44qzfigjxvxalmgwkw40zey"); //     Agnode_t* newt;
UNSUPPORTED("7tvuy92g0gt0ck4lcyfjo0pom"); //     Agnode_t* newh;
UNSUPPORTED("6yramhpyls8c6kexupyqip8oq"); //     Agedge_t* e;
UNSUPPORTED("6r402vmybtwrin17oo4i3ohg6"); //     Agedge_t* newe;
UNSUPPORTED("a9vu6hocyi7htsqyh6phlzeil"); //     Agraph_t* sg;
UNSUPPORTED("besxngkdo8t031gjxm5vfd5xx"); //     edgepair_t* data;
UNSUPPORTED("5a1jqw8gx8cm5msiy8io1aixr"); //     edgepair_t* ep;
UNSUPPORTED("23v5kvd9xwlilyqviokjdfjj1"); //     Agraph_t* newg = agopen (agnameof(g), g->desc, 0);
UNSUPPORTED("63h4gp8sbf5b8crmoisvvigj1"); //     Dt_t* emap = dtopen (&edgepair, Dtoset);;
UNSUPPORTED("4os8vmn6y3vehc4nurk1hr2lh"); //     data = (edgepair_t*)zmalloc((agnedges(g))*sizeof(edgepair_t));
UNSUPPORTED("87nwqojoe4s0kwt8hfabfyuyb"); //     ep = data;
UNSUPPORTED("1dog8ciiciwave274w4n209r0"); //     for (t = agfstnode(g); t; t = agnxtnode(g, t)) {
UNSUPPORTED("657t600al73g2ffkbip22zipw"); // 	newt = mkMCNode (newg, 1, agnameof(t));
UNSUPPORTED("80dph5o7ffe0i67vlt24c48ad"); // 	assert(newt);
UNSUPPORTED("399kg6plk0fuf04gikgm2sswq"); //         (((mcnodeinfo_t*)((newt)->base.data))->orig) = t;
UNSUPPORTED("dkrzqtv66zna11bi2zlo1kak0"); //         (((mcnodeinfo_t*)((newt)->base.data))->rank) = ND_rank(t);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1dog8ciiciwave274w4n209r0"); //     for (t = agfstnode(g); t; t = agnxtnode(g, t)) {
UNSUPPORTED("4toe9a38bicrfge0e7unsaw43"); //         newt = agnode (newg, agnameof(t), 0);
UNSUPPORTED("17zamhmsma48mde8lfx6xn68g"); // 	for (e = agfstout(g, t); e; e = agnxtout(g, e)) {
UNSUPPORTED("77w66u7ibk28qyibrj1230n99"); // 	    newh = agnode (newg, agnameof(aghead(e)), 0);
UNSUPPORTED("47lub0tkr9f056x8dqi0dxc4i"); // 	    assert(newh);
UNSUPPORTED("4ztnjynimf23pgkvhsaiqsotq"); //             newe = mkMCEdge (newg, newt, newh, agnameof (e), 0, e); 
UNSUPPORTED("feh8s3ds1a7nimqbpcwi95jh"); // 	    assert(newe);
UNSUPPORTED("2x02iudgmr7vbal4vrniz9cbi"); // 	    ep->key = e;
UNSUPPORTED("6ag50704j14dd5ig78vq63gll"); // 	    ep->val = newe;
UNSUPPORTED("ewgknyj03wwacfabftibqjd2c"); // 	    (*(((Dt_t*)(emap))->searchf))((emap),(void*)(ep++),0000001);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ahix9jmplgwyd9js3fil1xy4j"); //     for (sg = agfstsubg(g); sg; sg = agnxtsubg(sg)) {
UNSUPPORTED("df0zcx5tocs2igh2mgku26txv"); // 	cloneSubg(newg, sg, emap);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1iot84m69fxb5uqwbenqmn4m6"); //     dtclose (emap);
UNSUPPORTED("23jg3jufd8h5n6iqw6jh5trop"); //     free (data);
UNSUPPORTED("dbggtnwlxegx2o32hm0oqdnoy"); //     return newg;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6jcxaryhg3ui5ohc7sw01imtg
// Agnode_t *mkMCNode (Agraph_t * g, int type, char *name) 
public static Object mkMCNode(Object... arg) {
UNSUPPORTED("6dqk7zjjco89q9icrrx9cejjo"); // Agnode_t *mkMCNode (Agraph_t * g, int type, char *name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ury6rq7he525xrufqq5xyj"); //     static int k = 0;
UNSUPPORTED("1bmfhejxfxvyh8xkqhnq0dvxc"); //     Agnode_t *rv;
UNSUPPORTED("bx1dr4weajm160sejmy560gvb"); //     char buf[512];
UNSUPPORTED("5r6402qoihdsj9ne0abemq7nj"); //     switch (type) {
UNSUPPORTED("4ak4rwp0nsvc9n89y3dnvoiy9"); //     case 6:
UNSUPPORTED("1bjs4nng2iog6zrdbday80z3z"); // 	sprintf(buf, "____tempN%d", k++);	/*unique node name for internal nodes */
UNSUPPORTED("7yjrfasz4vkx3hhiah3nk55bk"); // 	rv = agnode(g, buf, 1);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("b7p43bjfs7jl70jrygxd24o88"); //     case 7:
UNSUPPORTED("apx698dpd6a8gq7yfytw422eu"); // 	sprintf(buf, "____lblN%d", k++);	/*unique node name for labels */
UNSUPPORTED("7yjrfasz4vkx3hhiah3nk55bk"); // 	rv = agnode(g, buf, 1);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("6eeqczd3yry2vik3tg2qlwrkf"); // 	rv = agnode(g, name, 1);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c3itawp62buk3zrsd5j7t9wgr"); //     agbindrec(rv, "mcnodeinfo_t", sizeof(mcnodeinfo_t), NOT(0));
UNSUPPORTED("dgvtyb9t5o3m1t3bzbw11op4x"); //     (((mcnodeinfo_t*)((rv)->base.data))->type) = type;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 fzx4a8qgsof6c95j8afag4al
// Agedge_t* mkMCEdge (Agraph_t* g, Agnode_t* tail, Agnode_t* head, char* name, int type, Agedge_t* orige) 
public static Object mkMCEdge(Object... arg) {
UNSUPPORTED("dh7u18qfujkfe9qsg1m4by7tl"); // Agedge_t* mkMCEdge (Agraph_t* g, Agnode_t* tail, Agnode_t* head, char* name, int type, Agedge_t* orige)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cmyi8pjdm0681g1h40968b4p9"); //     Agedge_t* tmpE = agedge(g, tail, head, name, 1);
UNSUPPORTED("29ra6hgw0i22aoyb5qe5crdg3"); //     agbindrec(tmpE, "mcedgeinfo_t", sizeof(mcedgeinfo_t), NOT(0));
UNSUPPORTED("44edihmyhk09owzgh2zvsz8hj"); //     (((mcedgeinfo_t*)((tmpE)->base.data))->type) = type;
UNSUPPORTED("2zxpf2mbujkjnof9md1f7dx99"); //     (((mcedgeinfo_t*)((tmpE)->base.data))->orig) = orige;
UNSUPPORTED("bzk63xdowordy4fnt8du8jvki"); //     return tmpE;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
