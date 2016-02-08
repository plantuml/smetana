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

public class minc2__c {
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


//1 bu1ec70lysvxweoxil4rkfe08
// static int MAGIC_NUMBER = 4




//3 88p3295d69fkuxzdkqjagavj6
// static int higher_cross(mcNode * v, mcNode * w) 
public static Object higher_cross(Object... arg) {
UNSUPPORTED("a8trbl3jlqewf82wtpct46sh0"); // static int higher_cross(mcNode * v, mcNode * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bycbmusvln8r8emwvkekqbf52"); //     mcEdge *e;
UNSUPPORTED("3c5dlnjaeol9lz4ohneukdicp"); //     mcEdge *e2;
UNSUPPORTED("db3p38x320hzshth5d2an34eh"); //     double x1, xx1;
UNSUPPORTED("c06ekh066ohz5h0lfmf37ufwo"); //     double x2, xx2;
UNSUPPORTED("b0lgckyvn8qredk3vnw4uu9jg"); //     int idx, idx2;
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("b8mlixoh2y6fvd13lkufe5q17"); //     for (idx = 0; idx < v->high_edgs_cnt; idx++) {
UNSUPPORTED("bcgmyd8lrbmrral745qzxgw3g"); // 	e = v->high_edgs[idx];
UNSUPPORTED("6d9hs6q2iu13pnd03gqhpwi6g"); // 	x1 = e->lowerPort.p.x + e->lowerN->order;
UNSUPPORTED("4e1dqdguz8d0y8gue4u9p6pps"); // 	xx1 = e->higherPort.p.x + e->higherN->order;
UNSUPPORTED("2i7c9h6icqyj2jfrflp37gm7t"); // 	for (idx2 = 0; idx2 < w->high_edgs_cnt; idx2++) {
UNSUPPORTED("6z6av4nlkf8s9dykw6557ggfu"); // 	    e2 = w->high_edgs[idx2];
UNSUPPORTED("d55vv7zjgzgxva2r45lr2nxto"); // 	    x2 = e2->lowerPort.p.x + e2->lowerN->order;
UNSUPPORTED("11tzuvsy8ojk7fjody13x53o7"); // 	    xx2 = e2->higherPort.p.x + e2->higherN->order;
UNSUPPORTED("bu5x2gpx6pvkfb7b0cbofk8cz"); // 	    if (((x1 < x2) && (xx1 > xx2)) || ((x2 < x1) && (xx2 > xx1))) {
UNSUPPORTED("btxpxxhwdr8ml9qkfxetirqwt"); // 		if (e->penalty > e2->penalty)
UNSUPPORTED("b4u7atrg6yvbe02z4cfitpsp9"); // 		    cnt = cnt + (int)e->penalty;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("cdpfwn6qbncrfq28mzccanh43"); // 		    cnt = cnt + (int)e2->penalty;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5nrdw0hk3vvbs3aqtrqyacd4k
// static int lower_cross(mcNode * v, mcNode * w) 
public static Object lower_cross(Object... arg) {
UNSUPPORTED("1a30dnqzlkbt3jvbpdbfef0ku"); // static int lower_cross(mcNode * v, mcNode * w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bycbmusvln8r8emwvkekqbf52"); //     mcEdge *e;
UNSUPPORTED("3c5dlnjaeol9lz4ohneukdicp"); //     mcEdge *e2;
UNSUPPORTED("db3p38x320hzshth5d2an34eh"); //     double x1, xx1;
UNSUPPORTED("c06ekh066ohz5h0lfmf37ufwo"); //     double x2, xx2;
UNSUPPORTED("b0lgckyvn8qredk3vnw4uu9jg"); //     int idx, idx2;
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("de09pebts6jdxf6kthy2z8lbr"); //     for (idx = 0; idx < v->low_edgs_cnt; idx++) {
UNSUPPORTED("4jrhthdhrgng9lfnblum789qr"); // 	e = v->low_edgs[idx];
UNSUPPORTED("6d9hs6q2iu13pnd03gqhpwi6g"); // 	x1 = e->lowerPort.p.x + e->lowerN->order;
UNSUPPORTED("4e1dqdguz8d0y8gue4u9p6pps"); // 	xx1 = e->higherPort.p.x + e->higherN->order;
UNSUPPORTED("74yw64muqjh4qyt9k0sq5xfwe"); // 	for (idx2 = 0; idx2 < w->low_edgs_cnt; idx2++) {
UNSUPPORTED("6py2d23hh1a9uqyztg2skcs47"); // 	    e2 = w->low_edgs[idx2];
UNSUPPORTED("d55vv7zjgzgxva2r45lr2nxto"); // 	    x2 = e2->lowerPort.p.x + e2->lowerN->order;
UNSUPPORTED("11tzuvsy8ojk7fjody13x53o7"); // 	    xx2 = e2->higherPort.p.x + e2->higherN->order;
UNSUPPORTED("bu5x2gpx6pvkfb7b0cbofk8cz"); // 	    if (((x1 < x2) && (xx1 > xx2)) || ((x2 < x1) && (xx2 > xx1))) {
UNSUPPORTED("btxpxxhwdr8ml9qkfxetirqwt"); // 		if (e->penalty > e2->penalty)
UNSUPPORTED("bx9uac2o5hwz440476bqr31st"); // 		    cnt = cnt +(int) e->penalty;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("cdpfwn6qbncrfq28mzccanh43"); // 		    cnt = cnt + (int)e2->penalty;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7j4fyewo010ifuk77quit1amg
// static int pair_cross(mcNode * v, mcNode * w, int lowToHigh) 
public static Object pair_cross(Object... arg) {
UNSUPPORTED("5oi0j732rk9e9xki9fem291an"); // static int pair_cross(mcNode * v, mcNode * w, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e7i7szdh2ppsyzc6z3hz6a7sw"); //     if (lowToHigh)
UNSUPPORTED("2uj21yulqw7vz5fv7yg8r4zrk"); // 	return lower_cross(v, w);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("8kwf1o6jwmckzzmm3qdruy7gk"); // 	return higher_cross(v, w);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 818jzddawgnb40p6859ity4o3
// static int countAllX(mcGraph * mcG) 
public static Object countAllX(Object... arg) {
UNSUPPORTED("dkut55fluxm3fgf8diezduknv"); // static int countAllX(mcGraph * mcG)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("eqep55xzm6if0fn9qct2b37lx"); //     mcNode *n2;
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("14u6vsnkosb6epnp5d9cid1cj"); //     int id0, id1;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("axydi4oc4jwi46sw3mukybii2"); // 	for (id0 = 0; id0 < l->nodecnt; id0++) {
UNSUPPORTED("9rrc3kwaqfa9s83svsxwd3gdc"); // 	    n = l->nodes[id0];
UNSUPPORTED("9oqm63l52mr3l7wy2s4vldymj"); // 	    for (id1 = 0; id1 < l->nodecnt; id1++) {
UNSUPPORTED("d41p0dv0aq3hxao0kjb9hkc2n"); // 		n2 = l->nodes[id1];
UNSUPPORTED("ae1dhcfhrrk9x2gfmjth9p7b0"); // 		if (id0 != id1) {
UNSUPPORTED("ekcg438tpcqhqpwp1bohziccd"); // 		    int aa;
UNSUPPORTED("1iqq318m72cf73rs4n7swr25"); // 		    aa = pair_cross(n, n2, 1);
UNSUPPORTED("f5c3z0yajzkmfrd291qnu5wvv"); // 		    if (aa > 0) {
UNSUPPORTED("3o80j7irstxupyclreokc3y4s"); // 			aa = pair_cross(n, n2, 1);
UNSUPPORTED("dvqs8huuj88zu5024em73q145"); // 			cnt = cnt + aa;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5wzyejl80b63f67yk1uchhyfs"); //     return cnt / 2;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 412nwb12fyprvqf761v9zap59
// int node_cmp(const mcNode ** a, const mcNode ** b) 
public static Object node_cmp(Object... arg) {
UNSUPPORTED("cp2x93bc2imptfm8cv3553sc7"); // int node_cmp(const mcNode ** a, const mcNode ** b)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("fu7oetq6jfz266fhn2dmd2uw"); //     float ia;
UNSUPPORTED("da63qx2luz3so7umge30zyo8f"); //     float ib;
UNSUPPORTED("34eomskgbrarru1ke2tjc2aao"); //     ia = (*a)->order;
UNSUPPORTED("2fqj6mlnqh7exm17tqaag21c1"); //     ib = (*b)->order;
UNSUPPORTED("amfnqgw3v9whmzoyhiks2015y"); //     if (ia < ib)
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("2i15o97b0uxtf91vzyfslneja"); //     else if (ia > ib)
UNSUPPORTED("eleqpc2p2r3hvma6tipoy7tr"); // 	return 1;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dfnpd1lmgjk9hkn5fpnum5lml
// void reOrderLevel(mcLevel * l) 
public static Object reOrderLevel(Object... arg) {
UNSUPPORTED("91y8btsmn44c9101swdbcx3xn"); // void reOrderLevel(mcLevel * l)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5xrf37mgo34611ve0wwldf3ot"); //     qsort(l->nodes, l->nodecnt, sizeof(mcNode *), (qsort_cmpf) node_cmp);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7km6uc2nnohgbqcmejc2wwoh3
// static int transpose(mcLevel * l, int lowToHigh) 
public static Object transpose(Object... arg) {
UNSUPPORTED("362xk5rvj7mtxt1f7o3cp9su"); // static int transpose(mcLevel * l, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("eqep55xzm6if0fn9qct2b37lx"); //     mcNode *n2;
UNSUPPORTED("a2br58l4f6io3d90tgjrx20gq"); //     float temp;
UNSUPPORTED("9uf2icnp9lntl8gmbrqtn59cu"); //     int id;
UNSUPPORTED("8jle8seqe426evryojqvkhdvm"); //     int improvement = 0;
UNSUPPORTED("3ew1o7b03va5miqcqzc80nxs0"); //      /*DEBUG*/
UNSUPPORTED("5qutzbp34bbz4b1oix49ptswl"); // /*    
UNSUPPORTED("bi8xjz3jddfthixyeo82osiq8"); //     for (n=dtfirst(l->nodes);n;n=dtnext(l->nodes,n))
UNSUPPORTED("9na2anqgr8btfz22mh42qxm2c"); // 	printf("%s %f\n",agnameof(n->node),n->order);
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("3c3vg3j6lqihzecbji9d15cyw"); // 	 /*DEBUG*/ for (id = 0; id < l->nodecnt - 1; id++) {
UNSUPPORTED("3k3ik9akd2gsxu8i4io37ootx"); // 	int c, cc, d, dd;
UNSUPPORTED("8bvrtz9xcvmaf9dt0xkqfzvr8"); // 	n = l->nodes[id];
UNSUPPORTED("48x67hr236kq6fr7qqfrc9fe7"); // 	n2 = l->nodes[id + 1];
UNSUPPORTED("36ci4clpijrnp21h6h0z3uht5"); // //        printf ("comparing %s %s \n",agnameof(n->node),agnameof(n2->node));
UNSUPPORTED("1kbugsv8flq7158hoplyyy9vf"); // 	c = pair_cross(n, n2, lowToHigh);
UNSUPPORTED("25iotrmp61f7thrn5y1fhhw1p"); // 	d = pair_cross(n, n2, !lowToHigh);
UNSUPPORTED("1a94cmb1o4zif11v7w7n4x34d"); // 	/*test swap */
UNSUPPORTED("ai85wcyyur0xrmas8d4ro9dz0"); // 	temp = n2->order;
UNSUPPORTED("7lvd5ti902z8yyg99w908hac9"); // 	n2->order = n->order;
UNSUPPORTED("zp556qtg7mabik5asj8mjsx6"); // 	n->order = temp;
UNSUPPORTED("2ostg5gql4u03wy2mrwvlw336"); // 	cc = pair_cross(n, n2, lowToHigh);
UNSUPPORTED("5hk4wwmsbt4a8vyzzzye63ik4"); // 	dd = pair_cross(n, n2, !lowToHigh);
UNSUPPORTED("ba4hi74oz7e9s96npymwe44h2"); // //      if(((  cc-c) + (dd-d)) >= 0)
UNSUPPORTED("ab3zf5x2e1h1vyowmd1n6r35x"); // 	if ((c - cc) <= 0) {
UNSUPPORTED("f5ib5qolzqy9ymlhuyl5ry9cl"); // 	    temp = n2->order;
UNSUPPORTED("5m6qkvhafgbuba6rowkle5ms5"); // 	    n2->order = n->order;
UNSUPPORTED("4fjscwyodfq5wua87a38oih9a"); // 	    n->order = temp;
UNSUPPORTED("3u0rlxtfw4yrpl2sx3w7o13vy"); // 	    improvement = 0;
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("26clujuwizs5lmbvwce5us6b2"); // 	    improvement = (cc - c);
UNSUPPORTED("8pf87405tniixg7kkb58omg7f"); // 	    l->nodes[id] = n2;
UNSUPPORTED("30tczbvdiizuc6h9q54k4ll0k"); // 	    l->nodes[id + 1] = n;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("f1prj6z2p85u7tq8ad5i91cbc"); //     reOrderLevel(l);
UNSUPPORTED("8egxddjhkxn187fr7q8vb8pb7"); // //    printf ("improvement value :%d\n",improvement);
UNSUPPORTED("85aev1sh1c0jstte6ek1z0kcx"); //     return improvement;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 aote1z7keowwgelqccw1inb3y
// static void add_node(Agraph_t * g, Agedge_t * e, int labels) 
public static Object add_node(Object... arg) {
UNSUPPORTED("3rokrtbamgcp1a9adl93q6db"); // static void add_node(Agraph_t * g, Agedge_t * e, int labels)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1wpyx20qfcutvda3strtdpzjc"); //     /*find out how the ranks increase ,it may not always be from tail to head! */
UNSUPPORTED("7cox3f4p0djuwzfzxvbcl6uxi"); //     int rankDiff;
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("c4gut74s0qdqoqbew454rcpfp"); //     Agnode_t *tmpN;
UNSUPPORTED("ep9udbjvp1wuf369jlbvay83l"); //     Agedge_t *tmpE;
UNSUPPORTED("7bb3aog68u51eyrj931u10row"); //     Agnode_t *tail;
UNSUPPORTED("1x9wmuj8vzj7dzpgg3vpm9pup"); //     Agnode_t *head;
UNSUPPORTED("7zykby8lh5zxwnhr9r5qpvfx6"); //     Agraph_t *cluster = NULL;
UNSUPPORTED("ceo7yb6ylly17bpmz5yzyr551"); //     Agraph_t *tempC1 = NULL;
UNSUPPORTED("1vodq8m2aon4omjibzulzhdoc"); //     Agraph_t *tempC2 = NULL;
UNSUPPORTED("2fj07dwya9n385w7xtvvwrx10"); //     int type = 6;
UNSUPPORTED("9vcgvjkna4elv9mw682bcl1ry"); //     head = aghead(e);
UNSUPPORTED("6pl9v5iuk7ek5nv87env6rn8y"); //     tail = agtail(e);
UNSUPPORTED("66h8ppjfjemirkitpgq8m1xka"); //     /*check whether edge is a cluster */
UNSUPPORTED("dl2q36gyz9rao1r0ytbky94q2"); //     tempC1 = (((mcnodeinfo_t*)((head)->base.data))->highCluster);
UNSUPPORTED("jtjwmwd248g94umbv6s7br80"); //     tempC2 = (((mcnodeinfo_t*)((tail)->base.data))->highCluster);
UNSUPPORTED("39lpvi9j5gk7imdgcs70av291"); //     if (tempC1 == tempC2)
UNSUPPORTED("7b4frmc3zwcuss8xrxf193b66"); // 	cluster = tempC1;
UNSUPPORTED("cze7y2ghb1agmhzz6p9fvhp8o"); //     rankDiff = (((mcnodeinfo_t*)((head)->base.data))->rank) - (((mcnodeinfo_t*)((tail)->base.data))->rank);
UNSUPPORTED("d1tatwrs2fld7vwvbuyn1xol2"); //     if ((rankDiff == 1) || (rankDiff == -1))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dwwi61goe3z6kju4ekxvc6ys8"); //     if (rankDiff == 0)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("d4dhqdzwgkwywwlh977k3k08f"); //     if (rankDiff > 0)		/*expected */
UNSUPPORTED("4u0tkteo3tqgavv4uz8f2uyj5"); // 	for (i = (((mcnodeinfo_t*)((tail)->base.data))->rank) + 1; i < (((mcnodeinfo_t*)((head)->base.data))->rank); i++) {
UNSUPPORTED("1xdh0e5jrmxa85w3kqt8exjqp"); // 	    if (labels) {
UNSUPPORTED("9rhwgpdgqgmrhzp3rbjqiregq"); // 		if (type == 7)
UNSUPPORTED("cj1mtzexflxobbmh6zja56pv1"); // 		    type = 6;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("9dswn2otq2ogdu3ucpa426voq"); // 		    type = 7;
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("im2sodn54tfgjxzy0gehp4lr"); // 		type = 6;
UNSUPPORTED("bsrqvfarcpq7zir2v6jz0po3u"); // 	    tmpN = mkMCNode (g, type, (char *) 0);
UNSUPPORTED("2ss7mip3n7fafq90yehyhxzm9"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->rank) = i;
UNSUPPORTED("9lpugppxw7vjm2461nx335sgl"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->type) = type;
UNSUPPORTED("35brbzk360y9lzyp14zjih54t"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->highCluster) = cluster;
UNSUPPORTED("a88opavkqsfidw949t2s1zk8q"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->orderr) = (((mcnodeinfo_t*)((tail)->base.data))->orderr);
UNSUPPORTED("4rp2w0kgvupdeyu8blt8o9i72"); // 	    /*create internal edge */
UNSUPPORTED("4ighh97wdvq9cr8bbvrzvxbi3"); // 	    tmpE = mkMCEdge (g, tail, tmpN, 0, 1, (((mcedgeinfo_t*)((e)->base.data))->orig));
UNSUPPORTED("c9o3y1iluuzsfn61g82myffeu"); // 	    tail = tmpN;
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("9lmq4r6umoxkwvx8hsgrge5wz"); // 	for (i = (((mcnodeinfo_t*)((tail)->base.data))->rank) - 1; i > (((mcnodeinfo_t*)((head)->base.data))->rank); i--) {
UNSUPPORTED("1xdh0e5jrmxa85w3kqt8exjqp"); // 	    if (labels) {
UNSUPPORTED("9rhwgpdgqgmrhzp3rbjqiregq"); // 		if (type == 7)
UNSUPPORTED("cj1mtzexflxobbmh6zja56pv1"); // 		    type = 6;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("9dswn2otq2ogdu3ucpa426voq"); // 		    type = 7;
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("im2sodn54tfgjxzy0gehp4lr"); // 		type = 6;
UNSUPPORTED("bsrqvfarcpq7zir2v6jz0po3u"); // 	    tmpN = mkMCNode (g, type, (char *) 0);
UNSUPPORTED("2ss7mip3n7fafq90yehyhxzm9"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->rank) = i;
UNSUPPORTED("9lpugppxw7vjm2461nx335sgl"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->type) = type;
UNSUPPORTED("35brbzk360y9lzyp14zjih54t"); // 	    (((mcnodeinfo_t*)((tmpN)->base.data))->highCluster) = cluster;
UNSUPPORTED("4rp2w0kgvupdeyu8blt8o9i72"); // 	    /*create internal edge */
UNSUPPORTED("4ighh97wdvq9cr8bbvrzvxbi3"); // 	    tmpE = mkMCEdge (g, tail, tmpN, 0, 1, (((mcedgeinfo_t*)((e)->base.data))->orig));
UNSUPPORTED("c9o3y1iluuzsfn61g82myffeu"); // 	    tail = tmpN;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("5xfaolutfy5tj778d5xnks1jr"); //     tmpE = mkMCEdge (g, tail, head, 0, 1, (((mcedgeinfo_t*)((e)->base.data))->orig));
UNSUPPORTED("6vsy5xh99oi2msv8o4j5zj3u7"); //     /*mark the long edge for deletion */
UNSUPPORTED("b67e3t335qgs9slcjjqmbhp0m"); //     (((mcedgeinfo_t*)((e)->base.data))->deleteFlag) = 1;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2e3fdvj7ydtlraiys3l234yp2
// static void addNodes(Agraph_t * g, int hasLabels) 
public static Object addNodes(Object... arg) {
UNSUPPORTED("eef5s527kcpfiirah30bgvcl0"); // static void addNodes(Agraph_t * g, int hasLabels)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("7btsnmy4xoqlxy7wkxx2wne25"); //     Agedge_t *ee = NULL;
UNSUPPORTED("4urvb00fxzbv01ouibwef2wrn"); //     Agedge_t **eList = NULL;		/*for technical reasons i add dummy edges after the loop */
UNSUPPORTED("90hdv5ih6q2skj2hab72s7f5u"); //     int tempEdgeCnt = 0;
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("arb0s09dpvnnq668arru5utn"); // 	int type = (((mcnodeinfo_t*)((v)->base.data))->type);
UNSUPPORTED("75aqp7pinidfnxenbct96hxzn"); // 	if (type != 1)
UNSUPPORTED("6hqli9m8yickz1ox1qfgtdbnd"); // 	    continue;
UNSUPPORTED("erx1nf1775jonr4w5wft0hvdu"); // 	for (e = agfstout(g, v); e; e = agnxtout(g, e)) {
UNSUPPORTED("84wrivihd3uim5cakl0oa4664"); // 	    if ((((mcedgeinfo_t*)((e)->base.data))->type) == 1)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("84nddjabo0gaef08tjjxcz3a"); // 	    eList = RALLOC(tempEdgeCnt + 1, eList, Agedge_t *);
UNSUPPORTED("2z3v555kqg87ticmlqay3mief"); // 	    eList[tempEdgeCnt] = e;
UNSUPPORTED("95eqvosfy4l84ldc2zhpwl2fq"); // 	    tempEdgeCnt++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("vyskjbxfihyo2g0l4ut7imlz"); //     for (id = 0; id < tempEdgeCnt; id++)
UNSUPPORTED("8jyvx81y9f89uvmqmmnvcnieb"); // 	add_node(g, eList[id], hasLabels);
UNSUPPORTED("f39dwlas31w13oelbctyual60"); //     /*delete long edges */
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("erx1nf1775jonr4w5wft0hvdu"); // 	for (e = agfstout(g, v); e; e = agnxtout(g, e)) {
UNSUPPORTED("4884w5s4m5yn7ccivuc726sia"); // 	    if (ee)
UNSUPPORTED("dyx71j2ju5x5uws3gm2khctia"); // 		agdelete(g, ee);
UNSUPPORTED("arz7m9q5jkc66ra7ogl3mahft"); // 	    if ((((mcedgeinfo_t*)((e)->base.data))->deleteFlag) == 1)
UNSUPPORTED("5rqt7v7k4zr9sbpti6icneun8"); // 		ee = e;
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("4oojox7pm627cof9r14hjpt7d"); // 		ee = NULL;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8fqom3iztgb2kmyhfx5u55nt8
// static void double_ranks(Agraph_t * g) 
public static Object double_ranks(Object... arg) {
UNSUPPORTED("4ier8k8pwyw0z4lfn06trgpxh"); // static void double_ranks(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("1yckd9ofrc291g3tywpvzi0a0"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v))
UNSUPPORTED("2hursjyxrwvxbpyutdh3phgei"); // 	(((mcnodeinfo_t*)((v)->base.data))->rank) = (((mcnodeinfo_t*)((v)->base.data))->rank) * 2;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 155wcwxccgcwmq14vxvo67dvs
// static void free_mcGroup (mcGroup* g) 
public static Object free_mcGroup(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("anvuhpupua3775a4eoz8p9a0f"); // free_mcGroup (mcGroup* g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5eb5hyqgawtjtmfa3tpqvovzk"); //     dtclose (g->nodes);
UNSUPPORTED("dwuc0y4whcauryjdz2g3rdyey"); //     free (g);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 evfxag55x92tc0pycduzy2weo
// static void free_mcEdge (mcEdge* e) 
public static Object free_mcEdge(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("5ybduolxhyohpf5xlb53thuji"); // free_mcEdge (mcEdge* e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("d8yxvoy3ad7zzsndg9qd410l7"); //     free (e);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dpw9jcaanksnpgigriem1ak1s
// static void free_mcNode (mcNode* n) 
public static Object free_mcNode(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("9b21jeq8b3pqx5ntcm3vx6qkv"); // free_mcNode (mcNode* n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("8qnvvzebi75ryypearm4fa32p"); //     if (n->isLeader)
UNSUPPORTED("1yk0dgryiv8ekmz7ey5qk2f3d"); // 	free_mcGroup (n->group);
UNSUPPORTED("1aslgnyo28vdkzp17bk5x6k1k"); //     for (i = 0; i < n->low_edgs_cnt; i++)
UNSUPPORTED("3aakvwldizr4zjaya9vi3qkhf"); // 	free_mcEdge (n->low_edgs[i]);
UNSUPPORTED("2t89yhgqv9a8klr5ip524kjos"); //     for (i = 0; i < n->high_edgs_cnt; i++)
UNSUPPORTED("diboe8u2oncjvj2xcwjxpdln2"); // 	free_mcEdge (n->high_edgs[i]);
UNSUPPORTED("eft62pgu2x348u7ee9utkz7uv"); //     free (n->low_edgs);
UNSUPPORTED("81fb10ask6zyx5jrjdbzrn7a5"); //     free (n->high_edgs);
UNSUPPORTED("cehs8m5oc4niy7hbyidknirjx"); //     free (n->name);
UNSUPPORTED("5u5488pbkjjk4uw3v9ffzyamg"); //     free (n);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5c8j3p9an8a05m08cqdkptkqu
// static void free_mcLevel (mcLevel* l) 
public static Object free_mcLevel(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("984irihvnl78j6ie36yd6o8f1"); // free_mcLevel (mcLevel* l)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("1m3765apdyq8qczffmb640zog"); //     for (i = 0; i < l->nodecnt; i++)
UNSUPPORTED("9syb29gvg3sxqezuo0fn35axu"); // 	free_mcNode (l->nodes[i]);
UNSUPPORTED("c61pc28potcrivnfrsa9lwxu2"); //     l->nodecnt++;
UNSUPPORTED("1ody4r971f8svbzp75hd0b5bz"); //     free (l->nodes);
UNSUPPORTED("e3gz6aq27ewey2gqoje1teell"); //     free (l);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 15iwtxv0p5aya3iqpkycy8gdo
// static void free_mcGraph (mcGraph* mcg) 
public static Object free_mcGraph(Object... arg) {
UNSUPPORTED("e2z2o5ybnr5tgpkt8ty7hwan1"); // static void
UNSUPPORTED("8fsef8dh5i2uy57nori3445m"); // free_mcGraph (mcGraph* mcg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("7eukjh7g33so76k3pzfsxlxi6"); //     for (idx = 0; idx < mcg->lvl_cnt; idx++)
UNSUPPORTED("6bifptb9eer2v04plm0osx7q5"); // 	free_mcLevel (mcg->lvls[idx]);
UNSUPPORTED("ahvq36cv9023u92nx6hwsq3ng"); //     free (mcg->lvls);
UNSUPPORTED("d9foankilnkvxc0avwv2hphgh"); //     free (mcg);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dip9vumnaqfwhqfzcq9vlvlog
// static mcNode *initMcNode(Agnode_t * n) 
public static Object initMcNode(Object... arg) {
UNSUPPORTED("agtj3gf26pobtz01ixh04gkre"); // static mcNode *initMcNode(Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cfv42nokwh4om9syxyzkvmii4"); //     mcNode *rv;
UNSUPPORTED("cg4681av0wk8eiu9s07xh9ol1"); //     rv = (mcNode*)zmalloc(sizeof(mcNode));
UNSUPPORTED("9wmis0ddmkquhsgav88ypw0lj"); //     rv->group = NULL;
UNSUPPORTED("7td7iw9t7uve3zee9b33k168d"); //     if ((((mcnodeinfo_t*)((n)->base.data))->orderr) < 0)
UNSUPPORTED("byn49vvlec89orw8sb2516lyo"); // 	(((mcnodeinfo_t*)((n)->base.data))->orderr) = 0;
UNSUPPORTED("6igbxnh9nu7o2mobzfw8lywtl"); //     rv->order = (((mcnodeinfo_t*)((n)->base.data))->orderr);
UNSUPPORTED("49zwqjbweh4khh0alcetedgke"); //     rv->w = 0;
UNSUPPORTED("3f2stcqrvxpnocbledcxns3tc"); //     rv->node = n;
UNSUPPORTED("cazpaxv5k3fwdkw503tsvxaop"); //     (((mcnodeinfo_t*)((n)->base.data))->mcn) = rv;
UNSUPPORTED("ean6q27l1wd9aeag7gj55ruuz"); //     (((mcnodeinfo_t*)((n)->base.data))->type) = 1;
UNSUPPORTED("auabirb5pmp1vbog2etl7mhdi"); //     rv->groupOrder = 0;
UNSUPPORTED("cqzjbuh941cly8ccdm8xg12nt"); //     rv->groupOrder = -1;
UNSUPPORTED("95h4cn62tboalcm3xkgzeb3t8"); //     rv->isLeader = 0;
UNSUPPORTED("3cow8jaln1x9acl8x1x4u7mas"); //     rv->leader = NULL;
UNSUPPORTED("es3zj7neykrfut7qxejiw22m9"); //     rv->name = strdup(agnameof(n));
UNSUPPORTED("bv58bnkvsboqvilkg2p7qvql"); //     rv->high_edgs_cnt = 0;
UNSUPPORTED("9ocmuhzvkq4pypvyjofb72ih6"); //     rv->low_edgs = NULL;
UNSUPPORTED("4r3vdri41a79xlpzdaoyrpyb6"); //     rv->low_edgs_cnt = 0;
UNSUPPORTED("48p11eht7za4g3nthjjvdqbro"); //     rv->high_edgs = NULL;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 eldlaegnl4texfwpbqmjwrm4q
// static mcEdge *initMcEdge(Agedge_t * e) 
public static Object initMcEdge(Object... arg) {
UNSUPPORTED("anytb7zc41m6iu3bb4q4zaqq8"); // static mcEdge *initMcEdge(Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("12390pkfo02qdx4i81t0y9rjl"); //     mcEdge *rv;
UNSUPPORTED("c60enamez0dis6gjy84sp3zdn"); //     rv = (mcEdge*)zmalloc(sizeof(mcEdge));
UNSUPPORTED("6v7dqjtr1bklph0e30whfs4hj"); //     rv->e = e;
UNSUPPORTED("elghbr0foqn7tq01mi4i00uil"); //     rv->lowerN = NULL;
UNSUPPORTED("9aaorgn2axw7mloso7zql5jlv"); //     rv->higherN = NULL;
UNSUPPORTED("a5si7tbxm7g30yt2a6ta0m3q0"); //     rv->penalty = 1;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2t70atv31r250lw5wamvwxdq3
// static mcLevel *initMcLevel(int rank) 
public static Object initMcLevel(Object... arg) {
UNSUPPORTED("1waxh6gfnin621stxl9ba0ikk"); // static mcLevel *initMcLevel(int rank)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bnjjvw8y1kxgrccp6ystm0o88"); //     mcLevel *rv;
UNSUPPORTED("1xgpaw5l557ugob74vgie9am8"); //     rv = (mcLevel*)zmalloc(sizeof(mcLevel));
UNSUPPORTED("36ypx9f9r8nglie2i1gbf61ns"); //     rv->nodes = NULL;
UNSUPPORTED("cy4sccakbyegv7fxg4mzto94r"); //     rv->nodecnt = 0;
UNSUPPORTED("5nqbuo223wq20rry50jsl78za"); //     rv->rank = rank;
UNSUPPORTED("79bzfkyntpi1etj7t7id1vgjp"); //     rv->higherEdgeCount = 0;
UNSUPPORTED("8b19o3lpmnax9rppqw9x7372h"); //     rv->lowerEdgeCount = 0;
UNSUPPORTED("b7x4pxjb92tq922dh3gza5pfm"); //     rv->highCnt = 1000000000;
UNSUPPORTED("9mt09tsz0k78t1yf933xnfh2p"); //     rv->lowCnt = 1000000000;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6p451oshawi5fito7icui6bqc
// static void addEdgeToNode(mcNode * n, mcEdge * e, int lowEdge) 
public static Object addEdgeToNode(Object... arg) {
UNSUPPORTED("8cwc8niv38otfaz12n8z4kbkw"); // static void addEdgeToNode(mcNode * n, mcEdge * e, int lowEdge)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1rc2emctj3efbdtmcre0m9tix"); //     if (lowEdge) {
UNSUPPORTED("8rx12hnnwjtq7ur9n6olm8mr"); // 	n->low_edgs_cnt++;
UNSUPPORTED("dltftir3e73052xshuyyw9tqo"); // 	n->low_edgs = RALLOC(n->low_edgs_cnt, n->low_edgs, mcEdge *);
UNSUPPORTED("7j9dwjq6wp0baoo8bji4tnl1q"); // 	n->low_edgs[n->low_edgs_cnt - 1] = e;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("7w1sabdbwocvknbmeup6ow1w"); // 	n->high_edgs_cnt++;
UNSUPPORTED("bg2jcb1qrxo3ku51rycdwnin"); // 	n->high_edgs = RALLOC(n->high_edgs_cnt, n->high_edgs, mcEdge *);
UNSUPPORTED("df067piw1ljtcnpsh0f9qnjqd"); // 	n->high_edgs[n->high_edgs_cnt - 1] = e;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ajpigmqzn2dsbq4k3vljwh32e
// static void addAdjEdges(Agnode_t * n) 
public static Object addAdjEdges(Object... arg) {
UNSUPPORTED("a522qmv37jnbjz31sqphaq158"); // static void addAdjEdges(Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("11egoj2o0qfwjrpgqeapj0317"); //     Agnode_t *av;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("1dbyk58q3r4fyfxxo7ovemkpu"); //     Agraph_t *g;
UNSUPPORTED("4bfvuin2ue2dppaqqzlmxzjvk"); //     int rank;
UNSUPPORTED("658h59cub39c1tjuz1z1ysdcm"); //     mcNode *mcN;
UNSUPPORTED("9ycm3dt9jtmhp8jcad494ucfi"); //     mcEdge *mcE;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("38tgkes5dhr4oloxpg73baq10"); //     g = agraphof(n);
UNSUPPORTED("4eprk3wtzl1mlhr265aabypkx"); //     rank = (((mcnodeinfo_t*)((n)->base.data))->rank);
UNSUPPORTED("c3hxty6ggw6jaijj5eqd8p7px"); //     mcN = (((mcnodeinfo_t*)((n)->base.data))->mcn);
UNSUPPORTED("3xnm36upshhzxh93f0dfxvaqi"); //     l = mcN->level;
UNSUPPORTED("2661ch6g78x3kmtmtuvwn9iaz"); //     for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("2xh7z2oeqey3buj08ie8ec45u"); // 	av = aghead(e);
UNSUPPORTED("blab3ufvmhzomo297nq2ppby8"); // 	mcE = initMcEdge(e);
UNSUPPORTED("5kytqv7z173xldfya1gn5rbet"); // 	if ((((mcnodeinfo_t*)((av)->base.data))->rank) <= rank) {
UNSUPPORTED("c32llgirped5h2sm6migtwuc0"); // 	    addEdgeToNode(mcN, mcE, 1);
UNSUPPORTED("7zjjg6nibluljwhufzg9lqf4n"); // 	    mcE->lowerN = (((mcnodeinfo_t*)((av)->base.data))->mcn);
UNSUPPORTED("75bkn2od6iux9w5p8jryl7ehm"); // 	    mcE->higherN = mcN;
UNSUPPORTED("m2xb3na5zjwuw4l4gw1xa038"); // 	    mcE->lowerPort = (((mcedgeinfo_t*)((e)->base.data))->head_port);
UNSUPPORTED("af7295sx67if8ni9e80fegztx"); // 	    mcE->higherPort = (((mcedgeinfo_t*)((e)->base.data))->tail_port);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("bemjo1u8z0rgtu6om8sdug3fn"); // 	    addEdgeToNode(mcN, mcE, 0);
UNSUPPORTED("7incx3r8rokqd563wkkb2jihr"); // 	    mcE->higherN = (((mcnodeinfo_t*)((av)->base.data))->mcn);
UNSUPPORTED("1dgqi6x09oqalof9iqzj97r9u"); // 	    mcE->lowerN = mcN;
UNSUPPORTED("9tb0pt1n8nml35ffyfwfjx53h"); // 	    mcE->lowerPort = (((mcedgeinfo_t*)((e)->base.data))->tail_port);
UNSUPPORTED("eykdsk8x6y2tcjikgtoebg95x"); // 	    mcE->higherPort = (((mcedgeinfo_t*)((e)->base.data))->head_port);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2wj6c20getix97noebmsx1104"); //     for (e = agfstin(g, n); e; e = agnxtin(g, e)) {
UNSUPPORTED("7e6b3tvt3wcjaybodwwt5ud8a"); // 	av = agtail(e);
UNSUPPORTED("blab3ufvmhzomo297nq2ppby8"); // 	mcE = initMcEdge(e);
UNSUPPORTED("5do38gizhid3216xl8793w7mw"); // 	if ((((mcnodeinfo_t*)((av)->base.data))->rank) < rank) {
UNSUPPORTED("c32llgirped5h2sm6migtwuc0"); // 	    addEdgeToNode(mcN, mcE, 1);
UNSUPPORTED("7zjjg6nibluljwhufzg9lqf4n"); // 	    mcE->lowerN = (((mcnodeinfo_t*)((av)->base.data))->mcn);
UNSUPPORTED("75bkn2od6iux9w5p8jryl7ehm"); // 	    mcE->higherN = mcN;
UNSUPPORTED("9tb0pt1n8nml35ffyfwfjx53h"); // 	    mcE->lowerPort = (((mcedgeinfo_t*)((e)->base.data))->tail_port);
UNSUPPORTED("eykdsk8x6y2tcjikgtoebg95x"); // 	    mcE->higherPort = (((mcedgeinfo_t*)((e)->base.data))->head_port);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("bemjo1u8z0rgtu6om8sdug3fn"); // 	    addEdgeToNode(mcN, mcE, 0);
UNSUPPORTED("7incx3r8rokqd563wkkb2jihr"); // 	    mcE->higherN = (((mcnodeinfo_t*)((av)->base.data))->mcn);
UNSUPPORTED("1dgqi6x09oqalof9iqzj97r9u"); // 	    mcE->lowerN = mcN;
UNSUPPORTED("m2xb3na5zjwuw4l4gw1xa038"); // 	    mcE->lowerPort = (((mcedgeinfo_t*)((e)->base.data))->head_port);
UNSUPPORTED("af7295sx67if8ni9e80fegztx"); // 	    mcE->higherPort = (((mcedgeinfo_t*)((e)->base.data))->tail_port);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1a4t41vg89h4s6jxpbd0r2jhw"); //     l->higherEdgeCount = mcN->high_edgs_cnt;
UNSUPPORTED("6ddhexi42mkcr6zamzwojlxct"); //     l->lowerEdgeCount = mcN->high_edgs_cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dqry798so0htsx0y1tfntgu2t
// static mcGraph *newMcGraph(Agraph_t * g) 
public static Object newMcGraph(Object... arg) {
UNSUPPORTED("30knaomh3f12jpu1rabsn9fy3"); // static mcGraph *newMcGraph(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("92n0ar3ts7ezz3iroapz4a60n"); //     int maxRank = 0;
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("1wt6e6jj8osjfbu4hvxd1eo72"); //     mcGraph *rv;
UNSUPPORTED("enbynbc887pvch3fojuvw2k1v"); //     int ind = 0;
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("drxohc57tbxod5dw2mz6xifzx"); // 	if ((((mcnodeinfo_t*)((v)->base.data))->rank) > maxRank)
UNSUPPORTED("bi8jkja9gridv0zy5612uh5me"); // 	    maxRank = (((mcnodeinfo_t*)((v)->base.data))->rank);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9vd55jnjvodj3cyccleer8wau"); //     rv = (mcGraph*)zmalloc(sizeof(mcGraph));
UNSUPPORTED("8w8r4i0t7ehzjp29sv5uxx7k3"); //     rv->lvls = NULL;
UNSUPPORTED("2zrkziz3nadh26rjhhbnf08et"); //     rv->lvl_cnt = 0;
UNSUPPORTED("dxl5eq7q89b8zusypuzvwdhe4"); //     rv->crossCnt = 0;
UNSUPPORTED("5rz4u9nlasphwu0lyjjufkjzg"); //     rv->g = g;
UNSUPPORTED("dotqoknsfwqywrbdnihk3w64c"); //     for (ind = 0; ind <= maxRank; ind++) {
UNSUPPORTED("7rg0v3pejegruo5nz5l22zxdh"); // 	mcLevel *l = initMcLevel(ind);
UNSUPPORTED("cma99ukgjkn538kzd13ypwsxs"); // 	rv->lvl_cnt++;
UNSUPPORTED("f2ii6yin642l51enexrydxsjw"); // 	rv->lvls = RALLOC(rv->lvl_cnt, rv->lvls, mcLevel*);
UNSUPPORTED("5n6tod2cd5yja2h4kcv7ub7ue"); // 	rv->lvls[rv->lvl_cnt - 1] = l;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9kv8qe0wl8rrw25pzpbk3dyc
// static void addToLevel(mcNode * n, mcGraph * mcG) 
public static Object addToLevel(Object... arg) {
UNSUPPORTED("3xmvkg05gddmcf1zi9gfrgxez"); // static void addToLevel(mcNode * n, mcGraph * mcG)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("xgyfapg1auoxyfyli3ef4gt5"); //     int rank = (((mcnodeinfo_t*)((n->node)->base.data))->rank);
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("eohrdp7go1rzhmfz9l3uzfgs2"); //     l = mcG->lvls[rank];
UNSUPPORTED("c6bnyh0j9bkk0he1r8dozjh14"); //     n->order = l->nodecnt;
UNSUPPORTED("c61pc28potcrivnfrsa9lwxu2"); //     l->nodecnt++;
UNSUPPORTED("4rftx3awifjwr5gxy613hzvxh"); //     l->nodes = RALLOC (l->nodecnt, l->nodes, mcNode*);
UNSUPPORTED("3z8bpzgyaamu8av4oayzckdh1"); //     l->nodes[l->nodecnt - 1] = n;
UNSUPPORTED("7zdxyd077cormew5sfngm71ho"); //     (((mcnodeinfo_t*)((n->node)->base.data))->orderr) = n->order;
UNSUPPORTED("arzzqlnan9nh64bcisygwyq8n"); //     n->level = l;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ad2w9ugv51rei3v4k6jvtcfpu
// static int inEdgeCnt(Agnode_t * n, Agraph_t * g) 
public static Object inEdgeCnt(Object... arg) {
UNSUPPORTED("ebtbmdnfe102u2u87ejk8ff19"); // static int inEdgeCnt(Agnode_t * n, Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("ac765q9popbptusjymwzret5y"); //     for (e = agfstin(g, n); e; e = agnxtin(g, e))
UNSUPPORTED("1szm63athnlkprt3pv29pjc6z"); // 	cnt++;
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 29sgyhmb8sag1z1wdf6eb2mwg
// static int outEdgeCnt(Agnode_t * n, Agraph_t * g) 
public static Object outEdgeCnt(Object... arg) {
UNSUPPORTED("6zbf05wcc89ud2wiqpuv2jwz4"); // static int outEdgeCnt(Agnode_t * n, Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("azojsmj2w5kkwset562797bbz"); //     for (e = agfstout(g, n); e; e = agnxtout(g, e))
UNSUPPORTED("1szm63athnlkprt3pv29pjc6z"); // 	cnt++;
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ass1vp0opzln58e8f9b8zh69v
// static void install_node(Agnode_t * n, mcGraph * mcg) 
public static Object install_node(Object... arg) {
UNSUPPORTED("d6p7eoq4005zyxjffdukzrwqx"); // static void install_node(Agnode_t * n, mcGraph * mcg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8h89r8rhn7udjmeo8y259899y"); //     static int cnt = 0;
UNSUPPORTED("307msh7je95s4n7pauxxjmif6"); //     mcNode *mcn;
UNSUPPORTED("9drig3qcva5gwmln3wfjipq8s"); //     mcn = initMcNode(n);
UNSUPPORTED("3uio3twubefa1ecq86dx48btl"); //     addToLevel(mcn, mcg);
UNSUPPORTED("ckadlska26zrpufeuzvj344bs"); //     cnt++;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 14lmunh58ooagx5d811gb5leq
// Agnode_t *nodeByName(Agraph_t * g, char *name) 
public static Object nodeByName(Object... arg) {
UNSUPPORTED("cb0fh7sudbtknyipi2e0oy93f"); // Agnode_t *nodeByName(Agraph_t * g, char *name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("10iuz1b3jm42kwbijvsdp1cgl"); // 	if (strcmp(agnameof(v), name) == 0)
UNSUPPORTED("b9t6ne0njxrwqqcdw8t4lt7kt"); // 	    return v;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("o68dp934ebg4cplebgc5hv4v"); //     return NULL;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6xzpo1op5nibkdwkcudu6icb8
// static int transposeAllL2H(mcGraph * mcG) 
public static Object transposeAllL2H(Object... arg) {
UNSUPPORTED("lmk8etbdmd4vpwtcftg9mj5h"); // static int transposeAllL2H(mcGraph * mcG)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("4bfvuin2ue2dppaqqzlmxzjvk"); //     int rank;
UNSUPPORTED("fydd7jon6wlisgax7j9z5gk4"); //     int improved = 0;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("f15gvqrcb0glwspuapxcxgbe5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++)
UNSUPPORTED("a3k9216caivcgg6ihqo8nf3y6"); // 	mcG->lvls[idx]->candidate = 1;
UNSUPPORTED("abpec383ug0t8huurv14kl2k7"); //     rank = 0;
UNSUPPORTED("7fgsalkrpk820jqrt7wroa6wj"); //     l = mcG->lvls[0];
UNSUPPORTED("f397h3eoiiox1z0ej5e393gs4"); //     idx = 0;
UNSUPPORTED("53kc41p479auwcycfsbhw8xix"); //     do {
UNSUPPORTED("64aoa3ssxscihz6zggqbkht3g"); // 	if (l->candidate) {
UNSUPPORTED("8gf4xd2gomx0zle368rr84ejx"); // 	    int a;
UNSUPPORTED("5mgrrnxotm5lhdszyv69xi0a"); // 	    a = transpose(l, 1);
UNSUPPORTED("dmmjkje886lwxdsfhtzmtgoaz"); // 	    cnt = cnt + a;
UNSUPPORTED("9oxna5huovcis4rpoyqeo94t8"); // 	    if (a < 0) {
UNSUPPORTED("5zr4cojrf4w7rugmvmcugnqm4"); // 		l->candidate = 1;
UNSUPPORTED("2otded8cfw6lc05qqjmehyk96"); // 		if (idx > 0)
UNSUPPORTED("8ixlr0mk9h0g6hodwj9vsz9c8"); // 		    mcG->lvls[idx - 1]->candidate = 1;
UNSUPPORTED("4yg80o8levfocyjgkkbbylgne"); // 		if (idx < (mcG->lvl_cnt - 1))
UNSUPPORTED("3g5o1y95lmep5h3gdhhbutd7b"); // 		    mcG->lvls[idx + 1]->candidate = 1;
UNSUPPORTED("a54hth4s2vir6xizmkopllcvd"); // 		improved = 1;
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("9gygsqwudigue057k0g4qqfpv"); // 		l->candidate = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c95m7dz4g2elekzukzso6038w"); // 	idx++;
UNSUPPORTED("90yhuas9kne2zbn28hb8lsc6b"); // 	if (idx == mcG->lvl_cnt) {
UNSUPPORTED("60o7jt0n8848ryl8rhs1pnjoc"); // 	    if (!improved)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("9on2998bzxbcen0ju2168t5ap"); // 	    idx = 0;
UNSUPPORTED("b108xjpdhykoaywlpq2l0yt4j"); // 	    improved = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("bisaeb1i484iutawysrspjmfw"); //     } while (1);
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6hi1rv6hm7814zpu2ltlcl8w5
// static int transposeAllH2L(mcGraph * mcG) 
public static Object transposeAllH2L(Object... arg) {
UNSUPPORTED("7i5gc84t75u07i9uhcav24sgd"); // static int transposeAllH2L(mcGraph * mcG)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("4bfvuin2ue2dppaqqzlmxzjvk"); //     int rank;
UNSUPPORTED("fydd7jon6wlisgax7j9z5gk4"); //     int improved = 0;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("f15gvqrcb0glwspuapxcxgbe5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++)
UNSUPPORTED("a3k9216caivcgg6ihqo8nf3y6"); // 	mcG->lvls[idx]->candidate = 1;
UNSUPPORTED("abpec383ug0t8huurv14kl2k7"); //     rank = 0;
UNSUPPORTED("b6726ylr1wdds1mboyywjdbod"); //     l = mcG->lvls[mcG->lvl_cnt - 1];
UNSUPPORTED("1e42m4u7lf29e250guuyeax9u"); //     idx = mcG->lvl_cnt - 1;
UNSUPPORTED("53kc41p479auwcycfsbhw8xix"); //     do {
UNSUPPORTED("64aoa3ssxscihz6zggqbkht3g"); // 	if (l->candidate) {
UNSUPPORTED("8gf4xd2gomx0zle368rr84ejx"); // 	    int a;
UNSUPPORTED("4rtjtj59dzs9bgnz97aj8wn7v"); // 	    a = transpose(l, 0);
UNSUPPORTED("dmmjkje886lwxdsfhtzmtgoaz"); // 	    cnt = cnt + a;
UNSUPPORTED("9oxna5huovcis4rpoyqeo94t8"); // 	    if (a < 0) {
UNSUPPORTED("5zr4cojrf4w7rugmvmcugnqm4"); // 		l->candidate = 1;
UNSUPPORTED("2otded8cfw6lc05qqjmehyk96"); // 		if (idx > 0)
UNSUPPORTED("8ixlr0mk9h0g6hodwj9vsz9c8"); // 		    mcG->lvls[idx - 1]->candidate = 1;
UNSUPPORTED("4yg80o8levfocyjgkkbbylgne"); // 		if (idx < (mcG->lvl_cnt - 1))
UNSUPPORTED("3g5o1y95lmep5h3gdhhbutd7b"); // 		    mcG->lvls[idx + 1]->candidate = 1;
UNSUPPORTED("a54hth4s2vir6xizmkopllcvd"); // 		improved = 1;
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("9gygsqwudigue057k0g4qqfpv"); // 		l->candidate = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bmzjf6n7yvxx9tnpbf8wmgwi1"); // 	idx--;
UNSUPPORTED("7sj37qpphwlvv52oavny944yz"); // 	if (idx == -1) {
UNSUPPORTED("60o7jt0n8848ryl8rhs1pnjoc"); // 	    if (!improved)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("5nonz4mgvqj4z9kznlm1hfd90"); // 	    idx = mcG->lvl_cnt - 1;
UNSUPPORTED("b108xjpdhykoaywlpq2l0yt4j"); // 	    improved = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("bisaeb1i484iutawysrspjmfw"); //     } while (1);
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3kpo21rjwppkk9h8qhswv6vr0
// static mcGraph *createMatrixIn(Agraph_t * g) 
public static Object createMatrixIn(Object... arg) {
UNSUPPORTED("b7pu0025q9r5kmw6nflba5e7a"); // static mcGraph *createMatrixIn(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("91nhhdfghbo87sudtxei17obf"); //     Agnode_t *v0;
UNSUPPORTED("9u49x9gbcy2pql7t7wp0ue886"); //     nodequeue *b;
UNSUPPORTED("1x9wmuj8vzj7dzpgg3vpm9pup"); //     Agnode_t *head;
UNSUPPORTED("5yl865ac13owbmjpge77v9d5w"); //     mcGraph *mcG;
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("agqts4k2ohqoe0edgpg4zodr2"); //     char* nodes[]= 
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dg0bdrjswo5z2hmoaefwrbs62"); //     "d0",
UNSUPPORTED("3m9idshuv4wun416ppb0fz9rj"); // "e1",
UNSUPPORTED("f2x13ysg7kmmty1y2qt8galx9"); // "e2",
UNSUPPORTED("70pe12tawze5ieeiv6fkcx7cz"); // "f0",
UNSUPPORTED("dfrvzc9kutj24x6rbd5aazyc0"); // "f1",
UNSUPPORTED("1qctzehlxxd9v4z5phptne2j6"); // "g0",
UNSUPPORTED("a7gvn5hbj8flsyymdhnk76gr0"); // "a1",
UNSUPPORTED("vnrvxhyv19fwkyn641yiejbc"); // "b1",
UNSUPPORTED("b1jice0atdp1upczqeg0m13uu"); // "b2",
UNSUPPORTED("chktlzlcza7j6fi39yz5mci60"); // "c2",
UNSUPPORTED("evbak4af726sff2fqw10nesf8"); // "c5",
UNSUPPORTED("asviru0k9hblm1gvc1r6s7bkk"); // "c8",
UNSUPPORTED("f405x479r3u7s9o3wei3pkkxu"); // "c3",
UNSUPPORTED("38av8dx27i8anypj7m4qkq161"); // "c4",
UNSUPPORTED("7419tbhjy9vwmvyt5fh5songp"); // "c6",
UNSUPPORTED("2tt3j4mqg4y3hv1ngpmnpg5hk"); // "c7",
UNSUPPORTED("f43u2lpy2uiw304zjvjmecg8v"); // "d2",
UNSUPPORTED("cyqv4nanwk88f998qx0wbb3sq"); // "d4",
UNSUPPORTED("13mdubel2vnkerk64jsjr1gkv"); // "d6",
UNSUPPORTED("899bpfxombzs3aegwpwuwffan"); // "d5",
UNSUPPORTED("42gxxnqynw25rha848h92gw1u"); // "e3",
UNSUPPORTED("b1u7cswy7p6yxqlr4c2lrnshv"); // "e4",
UNSUPPORTED("9vtcjauu3m3cadagm3c0tg0oj"); // "e5",
UNSUPPORTED("8ymgljs5fvfnfn3m5t3uxv3bv"); // "e6",
UNSUPPORTED("ajt6slbsxkkq2dykooxjryw6y"); // "e8",
UNSUPPORTED("32omv0icqv9v3gxara07jhxx9"); // "e7",
UNSUPPORTED("30lpzrq3ps6i4x2is6t2wfyox"); // "f4",
UNSUPPORTED("25s37435cho8z7g4caswsfm14"); // "f2",
UNSUPPORTED("9dnzhgzrrbxpmvl83pcfnznht"); // "f3",
UNSUPPORTED("eymss62f85mife0jyssxg7lyi"); // "f5",
UNSUPPORTED("a2ibwqkn8q402yiujp6dw3vur"); // "a0",
UNSUPPORTED("5lj67wqs057loa001k7yp3kqg"); // "b0",
UNSUPPORTED("28fvdvs1uk9u9xv78t4rgiids"); // "c0",
UNSUPPORTED("1jmq2q6vxu0mjzsw2f39o9unk"); // "c1",
UNSUPPORTED("e41sq6gwyjrelj62cqeix8lc"); // "d1",
UNSUPPORTED("9lnh9w5eay2cuihftdu8v4i3t"); // "d3",
UNSUPPORTED("2nngrhjm4wjq1mpp8kmb69xks"); // "e0" };
UNSUPPORTED("blg2eaax807a99lwybz22md03"); //     GD_nlist(g)=(node_t*)malloc(sizeof(node_t)*agnnodes(g));
UNSUPPORTED("adn8t7q2m7jovmq5g6jrptetd"); //     GD_nlist(g)=NULL;
UNSUPPORTED("825rhxntpnhutvfvxzq26uf2d"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) 
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("du876fgu2qrzuhhvh2o7lo95v"); // 	printf ("%s\n",agnameof(v));
UNSUPPORTED("2hoe6p86e4l01501dbmsjfn52"); // 	fast_node(g,v);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ekcby8mnklvbi9km94cjqneh8"); //     decompose(g,1);
UNSUPPORTED("etdwn1dlnn643p443l34l2900"); //     for (v = GD_nlist(g); v; v = ND_next(v)) 
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("188hdc3gnk1w34dbhg7bxger9"); // 	printf ("_%s\n",agnameof(v));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8y2fzgieaj0xwjh7a3eqjg8c2"); //     b = new_queue(agnnodes(g));
UNSUPPORTED("eef4banbuu7y8nx4pa9i2y4bi"); //     mcG = newMcGraph(g);
UNSUPPORTED("etdwn1dlnn643p443l34l2900"); //     for (v = GD_nlist(g); v; v = ND_next(v)) 
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("ep9kdi3guq6jub006ddeaaz92"); // 	if ((inEdgeCnt(v, g) == 0) && ((((mcnodeinfo_t*)((v)->base.data))->inBucket) != 1)) {
UNSUPPORTED("b2wskwf1k31b4wldlfwhcen9t"); // 	    enqueue(b, v);
UNSUPPORTED("379lwlh39tw1fl2c7d4s1qfp7"); // 	    (((mcnodeinfo_t*)((v)->base.data))->inBucket) = 1;
UNSUPPORTED("cqtjl1766gcqiop1s44cxowi2"); // 	    while ((v0 = dequeue(b))) {
UNSUPPORTED("7ck7quvad7mus9bv5z2nnlfzi"); // 		if (Verbose)
UNSUPPORTED("bbqu1i73qqan6j0lj1tbxxxpq"); // 		    fprintf(stderr, "installing %s\n", agnameof(v0));
UNSUPPORTED("d3sy9ngitag7ter8lslq9zdrl"); // 		install_node(v0, mcG);
UNSUPPORTED("cxh9np464rthoishps8ijoe57"); // 		for (e = agfstout(g, v0); e; e = agnxtout(g, e)) {
UNSUPPORTED("3yopzu08uuxtz3g9bhjfljs3w"); // 		    head = aghead(e);
UNSUPPORTED("8bp69spcye3kjub4aj3l9di3n"); // 		    if (((((mcnodeinfo_t*)((head)->base.data))->inBucket) != 1)) {
UNSUPPORTED("cp679glzyllcro055fwwgi5pd"); // 			enqueue(b, head);
UNSUPPORTED("c240ggf57k4928ktrmyye3bfw"); // 			(((mcnodeinfo_t*)((head)->base.data))->inBucket) = 1;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("a2nuvnio5o4ukrkg2tu2x0cer"); // /*    for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("6h6xxloslzeo6v63tz1zq3s8p"); // 	if ((inEdgeCnt(v, g) == 0) && (MND_inBucket(v) != 1)) {
UNSUPPORTED("b2wskwf1k31b4wldlfwhcen9t"); // 	    enqueue(b, v);
UNSUPPORTED("1kdbzm0mp2wev1bbozcfhrc5h"); // 	    MND_inBucket(v) = 1;
UNSUPPORTED("cqtjl1766gcqiop1s44cxowi2"); // 	    while ((v0 = dequeue(b))) {
UNSUPPORTED("7ck7quvad7mus9bv5z2nnlfzi"); // 		if (Verbose)
UNSUPPORTED("bbqu1i73qqan6j0lj1tbxxxpq"); // 		    fprintf(stderr, "installing %s\n", agnameof(v0));
UNSUPPORTED("d3sy9ngitag7ter8lslq9zdrl"); // 		install_node(v0, mcG);
UNSUPPORTED("cxh9np464rthoishps8ijoe57"); // 		for (e = agfstout(g, v0); e; e = agnxtout(g, e)) {
UNSUPPORTED("3yopzu08uuxtz3g9bhjfljs3w"); // 		    head = aghead(e);
UNSUPPORTED("9ggophf4filupmjpx5ma8f79m"); // 		    if ((MND_inBucket(head) != 1)) {
UNSUPPORTED("cp679glzyllcro055fwwgi5pd"); // 			enqueue(b, head);
UNSUPPORTED("c0ceswvebvxp4m0v2ibii8tq3"); // 			MND_inBucket(head) = 1;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("e4k69vss4p4tez9he2d1kumrd"); // /*    for (id=0;id < ARRAY_SZ; id++)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("4s22ub1wqj9nv6ya1ls3rowko"); // 	install_node(nodeByName(g,nodes[id]),mcG);
UNSUPPORTED("2i005m4jnkmdscirpbp30t1h8"); //     }*/
UNSUPPORTED("btur5sbypv5lza312x1f3lqi7"); //     free_queue (b); 
UNSUPPORTED("1yckd9ofrc291g3tywpvzi0a0"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v))
UNSUPPORTED("dpoj6ki90ev39gsczugb17mi7"); // 	addAdjEdges(v);
UNSUPPORTED("rota27563i9z7vynamukhnal"); //     id = countAllX(mcG);
UNSUPPORTED("1dptskjqm4vae8jcz9wsnfitn"); //     dumpGraph (mcG, "before.gv");
UNSUPPORTED("df483ckqczyfgu9mw0kw88o17"); //     _transpose(mcG, 0);
UNSUPPORTED("cj70m4ey2l2022v0p35lalci9"); // //    transposeAllL2H(mcG);
UNSUPPORTED("8sboq4xa44gj72lvdj3z9ds1x"); //     dumpGraph (mcG, "after_trans.gv");
UNSUPPORTED("rota27563i9z7vynamukhnal"); //     id = countAllX(mcG);
UNSUPPORTED("7zgcsn20l4jc2noqbnypkd6f8"); //     return mcG;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 25tj0fx8dake434qyqcpi9746
// static mcGraph *createMatrixOut(Agraph_t * g) 
public static Object createMatrixOut(Object... arg) {
UNSUPPORTED("brq9jb2dpx3xs5oql3mm38x6w"); // static mcGraph *createMatrixOut(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("91nhhdfghbo87sudtxei17obf"); //     Agnode_t *v0;
UNSUPPORTED("9u49x9gbcy2pql7t7wp0ue886"); //     nodequeue *b;
UNSUPPORTED("7bb3aog68u51eyrj931u10row"); //     Agnode_t *tail;
UNSUPPORTED("5yl865ac13owbmjpge77v9d5w"); //     mcGraph *mcG;
UNSUPPORTED("8y2fzgieaj0xwjh7a3eqjg8c2"); //     b = new_queue(agnnodes(g));
UNSUPPORTED("eef4banbuu7y8nx4pa9i2y4bi"); //     mcG = newMcGraph(g);
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("6ctr5erywfawpb8qakobr3tke"); // 	if ((outEdgeCnt(v, g) == 0) && ((((mcnodeinfo_t*)((v)->base.data))->inBucket) != 1)) {
UNSUPPORTED("b2wskwf1k31b4wldlfwhcen9t"); // 	    enqueue(b, v);
UNSUPPORTED("379lwlh39tw1fl2c7d4s1qfp7"); // 	    (((mcnodeinfo_t*)((v)->base.data))->inBucket) = 1;
UNSUPPORTED("cqtjl1766gcqiop1s44cxowi2"); // 	    while ((v0 = dequeue(b))) {
UNSUPPORTED("d3sy9ngitag7ter8lslq9zdrl"); // 		install_node(v0, mcG);
UNSUPPORTED("7ck7quvad7mus9bv5z2nnlfzi"); // 		if (Verbose)
UNSUPPORTED("bbqu1i73qqan6j0lj1tbxxxpq"); // 		    fprintf(stderr, "installing %s\n", agnameof(v0));
UNSUPPORTED("2cc8ty8sxv3yhmbugjutpbht6"); // 		for (e = agfstin(g, v0); e; e = agnxtin(g, e)) {
UNSUPPORTED("d3wyni9537ucw0jqdgj39m0bi"); // 		    tail = agtail(e);
UNSUPPORTED("5vvy3goxv012v3be16g4rel6u"); // 		    if (((((mcnodeinfo_t*)((tail)->base.data))->inBucket) != 1)) {
UNSUPPORTED("cy5sm6hvpj5ze14hnw71a5l67"); // 			enqueue(b, tail);
UNSUPPORTED("5hlw00pehdqgqqjfmmtdhjvh1"); // 			(((mcnodeinfo_t*)((tail)->base.data))->inBucket) = 1;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("btur5sbypv5lza312x1f3lqi7"); //     free_queue (b); 
UNSUPPORTED("1yckd9ofrc291g3tywpvzi0a0"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v))
UNSUPPORTED("dpoj6ki90ev39gsczugb17mi7"); // 	addAdjEdges(v);
UNSUPPORTED("dp83zl5n4zrlhyb7yg9qpnevp"); //     transposeAllH2L(mcG);
UNSUPPORTED("7zgcsn20l4jc2noqbnypkd6f8"); //     return mcG;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 76v2cdqzdoo5spq2fohubpt63
// static int int_cmp(const void *a, const void *b) 
public static Object int_cmp(Object... arg) {
UNSUPPORTED("s2msrtiydlu44td7210tdhby"); // static int int_cmp(const void *a, const void *b)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1dv0h28h6r78gmyr46gp8doql"); //     const int *ia = (const int *) a;	// casting pointer types
UNSUPPORTED("1b4kxudpcuglk3axc37bo257g"); //     const int *ib = (const int *) b;
UNSUPPORTED("10j9e8726qt20m8e8xiofwnn1"); //     return *ia - *ib;
UNSUPPORTED("7jcxz5b1t9agmzlll6xnfh767"); //     /* integer comparison: returns negative if b > a 
UNSUPPORTED("b71eyyd2bvt8fw4a5usp2492b"); //        and positive if a > b */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 50x5ytxsa9qfhn0ielud4ous0
// static int nodeMedian(mcNode * n, int lowToHigh) 
public static Object nodeMedian(Object... arg) {
UNSUPPORTED("693gzgww0vcirhsb8mjvvqlnh"); // static int nodeMedian(mcNode * n, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("52e8dk3bm86cwaismxoixnu1g"); //     int P[1024];
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("b68xxlw3pk1m03724qkbohzpv"); //     int m;
UNSUPPORTED("8cpfroy45gtyww6l6nj7hlsbq"); //     int ps;
UNSUPPORTED("bhj2j22z20qmd8qbitxa1aqxs"); //     mcEdge **edges;
UNSUPPORTED("8tmelgq03r5uibpv1p05rj68o"); //     int left;
UNSUPPORTED("e7t8o5pl6v6ydtstsrhp05p5u"); //     int right;
UNSUPPORTED("bycbmusvln8r8emwvkekqbf52"); //     mcEdge *e;
UNSUPPORTED("2pvpk1lkdwtfuilwq0zpypr9v"); //     if (lowToHigh) {
UNSUPPORTED("bvpvy7fpptlfu4syyh9oaxane"); // 	edges = n->low_edgs;
UNSUPPORTED("aeg2eeo3979ewlki7kehcw0t0"); // 	m = n->low_edgs_cnt;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("cvan2h0ej921vwket8oudwzv5"); // 	edges = n->high_edgs;
UNSUPPORTED("5hxbmig828cjatsbs4tldka4z"); // 	m = n->high_edgs_cnt;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bz5huu5fpy8a7me3i8qup4q5s"); //     ps = m;
UNSUPPORTED("3jd8agmo33jlaeeycvkd9r5cu"); //     m = m / 2;
UNSUPPORTED("6240ik3he969nywx4b83voplj"); //     for (id = 0; id < ps; id++) {
UNSUPPORTED("62xmmizeww3ohpydxttl5w32j"); // 	e = edges[id];
UNSUPPORTED("1r2bcvc8vv7c7pl1nrr44crqh"); // 	if (lowToHigh)
UNSUPPORTED("r7qwu6x3f7eoqn41y421xhsk"); // 	    P[id] = (int)e->lowerN->order;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("6l42ht0zlkw2rvgkgic0dlpss"); // 	    P[id] = (int)e->higherN->order;
UNSUPPORTED("9u8qqu9tw95qjbv3cxv3hj4bd"); //     };
UNSUPPORTED("4vhsh415oactpq9bfx94nmtz6"); //     qsort(P, ps, sizeof(int), int_cmp);
UNSUPPORTED("61nez2iczkgamg7bl595laqh4"); //     if (ps == 0)
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("8129ttt9qpud4qcdnqjyj1vo3"); //     if ((ps % 2) == 1)
UNSUPPORTED("14lpf79hw4hdjp8zu23oleu71"); // 	return P[m];
UNSUPPORTED("cbdpppcedolw36lxz5p1lklj9"); //     if (ps == 2) {
UNSUPPORTED("ebnhyw9qt4pfp5smheyv8bgx0"); // 	return (P[0] + P[1]) / 2;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5s3d87es1126oyu4nnsbbq7i1"); //     left = P[m - 1] - P[0];
UNSUPPORTED("70657zaag49abp4wjo7ex0h5a"); //     right = P[ps - 1] - P[m];
UNSUPPORTED("zcov6eztbqtdhd611dbvatdh"); //     return (P[m - 1] * right + P[m] * left) / (left + right);
UNSUPPORTED("4v614d3uabme2jyn0anuritbb"); // /*
UNSUPPORTED("f385gc08ylsw7foqtzget64dl"); // 12. procedure median_value(v,adj_rank)
UNSUPPORTED("ds82n930orwzdazdk0s9po3f0"); // 13. P = adj_position(v,adj_rank);
UNSUPPORTED("50lqj1537lvryhx95fwomfqwx"); // 14. m = ú Pú /2;
UNSUPPORTED("47x40g1ms61600fglp0uqb1u2"); // 15. if ú Pú = 0 then
UNSUPPORTED("cjpvubpvxkhd84aqu5w2m5dqu"); // 16. return -1.0;
UNSUPPORTED("lgyh8h8gwh9zjl93pot9rmnq"); // 17. elseif ú Pú mod 2 == 1 then
UNSUPPORTED("53afet417bu5silwa8lhndcos"); // 18. return P[m];
UNSUPPORTED("f3o5h6avw83hdztbobtcmnlwp"); // 19. elseif ú Pú = 2 then
UNSUPPORTED("36h94uxduks0hd3fqz3ekmwbx"); // 20. return (P[0] + P[1])/2;
UNSUPPORTED("2fqfrzzysx3aqvk99ldvo6drr"); // 21. else
UNSUPPORTED("8vygzeyisfxxu5279hj6kb52h"); // 22. left = P[m-1] - P[0];
UNSUPPORTED("c6sk42s3qorw516uft3q7w4pi"); // 23. right = P[ú Pú -1] - P[m];
UNSUPPORTED("969b7ujk781ulaqphhkzs3u7y"); // 24. return (P[m-1]*right + P[m]*left)/(left+right);
UNSUPPORTED("d444peq35medwqhkxd9j9xzst"); // 25. endif
UNSUPPORTED("agg983zc5usrsd976zuoujvel"); // 26. end
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 59kyg5hxjkduzm6wvxlhcvx76
// static int nodeMedian2(mcNode * n, int lowToHigh) 
public static Object nodeMedian2(Object... arg) {
UNSUPPORTED("53eg8ktblc1tnnp2hbodl2x5n"); // static int nodeMedian2(mcNode * n, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ak8wl1r7v4jdbold5j3c6aksw"); // /*    int edgeCnt;
UNSUPPORTED("cvw1hvzrz4ny5154ka9zk15v6"); //     int median;
UNSUPPORTED("cfnpeddo3beh4mr34wk0dzjvd"); //     int even=0;
UNSUPPORTED("erz9hvyzciui1pplelftk2zk2"); //     float newOrder;
UNSUPPORTED("3ajiat7gguezsdwjigby4zj5"); //     Dt_t* edges;
UNSUPPORTED("aad168sfd8njj0x0fzbib11m0"); //     mcEdge* e;
UNSUPPORTED("e7i7szdh2ppsyzc6z3hz6a7sw"); //     if (lowToHigh)
UNSUPPORTED("2edoufydq2gasa9uuexb3zgtv"); //         edges=n->low_edgs;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("e09a256g6cqibfjkcsoy7ahv2"); //         edges=n->high_edgs;
UNSUPPORTED("db4090s226hotidb7550c0u5h"); //     edgeCnt=dtsize(edges);
UNSUPPORTED("620c6mm997d9pw7it953tlsi7"); //     if(edgeCnt==0)
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("5og8ls7dm45s4wlvywd9b0s07"); //     if(edgeCnt % 2 == 0)
UNSUPPORTED("zpkoux5hv7jpt3sjlsffqey2"); // 	    even=1;
UNSUPPORTED("dt741f1p3pcu5jk915e16dxrn"); //     edgeCnt=edgeCnt /2;
UNSUPPORTED("5yodd0rynjnk69oe307xpv7n2"); //     for(e=dtfirst(edges);edgeCnt > 0;edgeCnt--)
UNSUPPORTED("aaf794g11wmg0p8sx6kyjxxwz"); //         e=dtnext(edges,e);
UNSUPPORTED("ckgq8u2e224xarxrswxf8mjl4"); //     if(lowToHigh)
UNSUPPORTED("3bi6zj4aiqt2hxyr701vyvyzo"); //         newOrder=e->lowerN->order;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("qsj0nmjksr0cisyp0dv9um2b"); //         newOrder=e->higherN->order;
UNSUPPORTED("44r8im24e7yzaxxekc4p7nmn9"); //     if(even)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("er9z73p2bsmjso6lecnygw9fv"); //         e=dtprev(edges,e);
UNSUPPORTED("dn1d3m9ohqnca4uovaptvwves"); //         if(lowToHigh)
UNSUPPORTED("a7n0t33noqj33eqlapeg06uv0"); // 	    newOrder=(newOrder+e->lowerN->order)/2;
UNSUPPORTED("35nw1pbiz2p3s6qwlam5eoo3m"); //         else
UNSUPPORTED("7v05iap4iahd7m8ku1kkj9268"); // 	    newOrder=(newOrder+e->higherN->order)/2;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("58ht4ehk1flsxhptgv7x7li44"); // //    return newOrder;
UNSUPPORTED("3sc8u37fb5v68hz065oxx8u3h"); //     return nodeMedian2( n,lowToHigh);*/
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5bb2cfv62p8pvglx1mrj19dxj
// static void normalizeLevel(mcLevel * l) 
public static Object normalizeLevel(Object... arg) {
UNSUPPORTED("dm2k15vsycjex8lwruak96uka"); // static void normalizeLevel(mcLevel * l)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("6v8z5myoooxsalxmzndnm2iyu"); //     for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("8bvrtz9xcvmaf9dt0xkqfzvr8"); // 	n = l->nodes[id];
UNSUPPORTED("1wafzh5zfi2xgwatqz2ybrqz"); // 	n->order = (float)id;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cfmgf3suwg53usbh8027aqpf8
// static void reSetNodePos(mcGraph * mcG, mcLevel * l, int lowToHigh) 
public static Object reSetNodePos(Object... arg) {
UNSUPPORTED("a9z7q4fylc2c3i7kqxy2qybi1"); // static void reSetNodePos(mcGraph * mcG, mcLevel * l, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("y101gsr95t2jrz71t4sl8h1u"); //     float order;
UNSUPPORTED("54vdi7jodi853otvasfzfb9t9"); //     float order2;
UNSUPPORTED("6v8z5myoooxsalxmzndnm2iyu"); //     for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("8bvrtz9xcvmaf9dt0xkqfzvr8"); // 	n = l->nodes[id];
UNSUPPORTED("1v83y5p860jo35305dc7nxlj2"); // 	order = (float)nodeMedian(n, lowToHigh);
UNSUPPORTED("c484i8es464ij2xj5ndf78lte"); // 	order2 = (float)nodeMedian(n, (lowToHigh + 1) % 2);
UNSUPPORTED("14ht5ctrnfdcy64kij8b42a0g"); // 	if (order == -1)
UNSUPPORTED("7a1sfonlmide38nek7qhhm84"); // 	    order = n->order;
UNSUPPORTED("e82ja9mukho97z0on90lc4yy"); // 	if (order2 == -1)
UNSUPPORTED("4ad4j7fo7kn4foc7psoaffllu"); // 	    order2 = order;
UNSUPPORTED("1w5td6lb2byrhf69ptzgzk43j"); // 	if (MAGIC_NUMBER != 0)
UNSUPPORTED("3d6fdkvfcyopdwt5npxqsritp"); // 	    n->order = (order + order2 / MAGIC_NUMBER);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("dcn6misxzw8e28et4eyrtd808"); // 	    n->order = order;
UNSUPPORTED("dkyqt8o4ceytsqyine520pvcu"); // 	(((mcnodeinfo_t*)((n->node)->base.data))->orderr) = n->order;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("92dl0ux3oodot5bnzdb13ta5k"); //     //normalize
UNSUPPORTED("f1prj6z2p85u7tq8ad5i91cbc"); //     reOrderLevel(l);
UNSUPPORTED("bilgtf5vl20wn1w5vz165kby9"); //     normalizeLevel(l);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 756eew0isdvfbymqp9bku2a1h
// static void cacheOrders(mcGraph * mcg, int cacheId) 
public static Object cacheOrders(Object... arg) {
UNSUPPORTED("2e88myi8sh0td4f7525ehzchd"); // static void cacheOrders(mcGraph * mcg, int cacheId)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("8jhkqwgvpetr9rqbex3ncktw7"); //     for (idx = 0; idx < mcg->lvl_cnt; idx++) {
UNSUPPORTED("ckrb7ce4i5piqaniyw8lpx9dd"); // 	l = mcg->lvls[idx];
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("ek2afbsbbvi9xqry7i05mw3x8"); // 	    n->prevOrder[cacheId] = n->order;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7r0ttvdgapl34igsnrfn14i8n
// static void loadOrders(mcGraph * mcg, int cacheId) 
public static Object loadOrders(Object... arg) {
UNSUPPORTED("8zl2o2el62mzhnfa4noqnd9ye"); // static void loadOrders(mcGraph * mcg, int cacheId)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("bxadl4icfi4zkvimu1q0fd3gw"); //     int id = 0;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("8jhkqwgvpetr9rqbex3ncktw7"); //     for (idx = 0; idx < mcg->lvl_cnt; idx++) {
UNSUPPORTED("ckrb7ce4i5piqaniyw8lpx9dd"); // 	l = mcg->lvls[idx];
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("3fnpwd2km2hot3zoai6emzwje"); // 	    n->order = n->prevOrder[cacheId];
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8jhkqwgvpetr9rqbex3ncktw7"); //     for (idx = 0; idx < mcg->lvl_cnt; idx++) {
UNSUPPORTED("ckrb7ce4i5piqaniyw8lpx9dd"); // 	l = mcg->lvls[idx];
UNSUPPORTED("cpuje9gcy0peesawx5p5fh1ol"); // 	reOrderLevel(l);
UNSUPPORTED("22hprzsku0hk6jtvfxwbsrk0e"); // 	normalizeLevel(l);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 m6dru48ja3qq9izu9cddg3qs
// static void wMedianLevel(mcLevel * l, mcGraph * mg, int lowToHigh) 
public static Object wMedianLevel(Object... arg) {
UNSUPPORTED("8k3l31myrg71giyvvajjfivgz"); // static void wMedianLevel(mcLevel * l, mcGraph * mg, int lowToHigh)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e7i7szdh2ppsyzc6z3hz6a7sw"); //     if (lowToHigh)
UNSUPPORTED("dpqjr007mcfmd6lhb9nuc85lj"); // 	reSetNodePos(mg, l, 1);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("lec8cqfagcx1uab64o0ptaw8"); // 	reSetNodePos(mg, l, 0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ekb1k6i79alz0w8zwkd48xh1y
// static void dumbcross(mcGraph * mcG, int pass) 
public static Object dumbcross(Object... arg) {
UNSUPPORTED("55svtbl20oq2czk5j9611bmbv"); // static void dumbcross(mcGraph * mcG, int pass)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("c7psajs27xhu7v6w3peiit9m3"); //     int idx;
UNSUPPORTED("a125zxrzy5w5f73ysqdvx9nne"); //     int it = 0;
UNSUPPORTED("8y33a3mmerqrev5ygkb7tzrlc"); //     int lowToHigh = 0;
UNSUPPORTED("3s8tqbieq22t991vjw2rhxv0a"); //     int best;
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("cpuje9gcy0peesawx5p5fh1ol"); // 	reOrderLevel(l);
UNSUPPORTED("22hprzsku0hk6jtvfxwbsrk0e"); // 	normalizeLevel(l);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7zr70ar1okzy40swqfp13z3iw"); //     cacheOrders(mcG, 0);	/*save init pos */
UNSUPPORTED("4e5pltqeys1bnz0y879i09vv8"); //     best = mcG->crossCnt = countAllX(mcG);
UNSUPPORTED("7iu5qwn0onu8i4068mtcg20hr"); //     fprintf(stderr, "original crossing count : %d\n", mcG->crossCnt);
UNSUPPORTED("8w9gyhqoohj2odfrwd98cktrn"); //     for (it = 0; it < pass; it++) {
UNSUPPORTED("b5ixl0a8iprqa5musjinyxmsx"); // 	if (lowToHigh == 0)
UNSUPPORTED("aye4kw9zvcttd0nnln324q1cc"); // 	    lowToHigh = 1;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("9gwaf3w4mz8uayb4q53d7u5ac"); // 	    lowToHigh = 0;
UNSUPPORTED("9t2n6gla54b0to14yz7qkcnqi"); // 	/*low to high */
UNSUPPORTED("7cquxhdo034zoyyoryhsqrocy"); // 	if (lowToHigh) {
UNSUPPORTED("4vqvzw99yvjojlhiiz53dfvqx"); // 	    int cnt = 0;
UNSUPPORTED("2if5kuoamgocyme74bid7p40u"); // 	    cacheOrders(mcG, 0);
UNSUPPORTED("21daeiifw8qcu510wu2wvlqj7"); // 	    for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("5uoiibkos1urd6flxral7bybe"); // 		l = mcG->lvls[idx];
UNSUPPORTED("1dvudvh7bsztpuottv1p4fyyt"); // 		wMedianLevel(l, mcG, lowToHigh);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("2dzi0fxyw6o5oorm6qmosd1ay"); // 	    cnt = countAllX(mcG);
UNSUPPORTED("3nmp3kzqdzqu08hxohrh86x0u"); // 	    if (cnt < best) {
UNSUPPORTED("5185a0hxcxacmso31zv0q6bhe"); // 		best = cnt;
UNSUPPORTED("41bbw7itrig49edrw0kuh2tlu"); // 		cacheOrders(mcG, 0);
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("anvf45tcjhfrkx60kyyxiaj9n"); // 		loadOrders(mcG, 0);
UNSUPPORTED("hxhwjcgrcicmpqrfv7v9jae3"); // 	    fprintf(stderr, "%d -> %d\n\n", best, cnt);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("4vqvzw99yvjojlhiiz53dfvqx"); // 	    int cnt = 0;
UNSUPPORTED("2if5kuoamgocyme74bid7p40u"); // 	    cacheOrders(mcG, 0);
UNSUPPORTED("arc8ptz6fjwg0gpsq2mjkl8aw"); // 	    for (idx = mcG->lvl_cnt - 1; idx >= 0; idx--) {
UNSUPPORTED("5uoiibkos1urd6flxral7bybe"); // 		l = mcG->lvls[idx];
UNSUPPORTED("1dvudvh7bsztpuottv1p4fyyt"); // 		wMedianLevel(l, mcG, lowToHigh);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("2dzi0fxyw6o5oorm6qmosd1ay"); // 	    cnt = countAllX(mcG);
UNSUPPORTED("3nmp3kzqdzqu08hxohrh86x0u"); // 	    if (cnt < best) {
UNSUPPORTED("5185a0hxcxacmso31zv0q6bhe"); // 		best = cnt;
UNSUPPORTED("41bbw7itrig49edrw0kuh2tlu"); // 		cacheOrders(mcG, 0);
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("anvf45tcjhfrkx60kyyxiaj9n"); // 		loadOrders(mcG, 0);
UNSUPPORTED("hxhwjcgrcicmpqrfv7v9jae3"); // 	    fprintf(stderr, "%d -> %d\n\n", best, cnt);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e3iud95q9thnb1rtj83qae0lw
// void clusterEdges(mcGraph * mcG) 
public static Object clusterEdges(Object... arg) {
UNSUPPORTED("nyg8k9xom0xl49diu49ha26o"); // void clusterEdges(mcGraph * mcG)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("23fjgak8twiudlqolzus99we2"); //     mcNode *n = NULL;
UNSUPPORTED("15c3sef0lcqf271n4w2dkwvqv"); //     mcEdge *e = NULL;
UNSUPPORTED("dfn6dav5qfmxknkb3p5bo59xn"); //     int id, id2;
UNSUPPORTED("4rip97cgvbcrlgycxl0wajpuh"); //     Agnode_t *n1;
UNSUPPORTED("5ozeh48rt3sdc5ufi9nv6yx88"); //     Agnode_t *n2;
UNSUPPORTED("716hjbifedt25yhusduvy5hlt"); //     int idx = 0;
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("52c0ydviqohv0d77ugapr5v6e"); // 	    for (id2 = 0; id2 < n->low_edgs_cnt; id2++) {
UNSUPPORTED("1cm39xuhq56zfz7xw6jfw7wbq"); // 		e = n->low_edgs[id2];
UNSUPPORTED("4u9fekoy5t2z05fdrloy15k5h"); // 		n1 = e->higherN->node;
UNSUPPORTED("5gkssj2rofud9d9ovnwdfmn5h"); // 		n2 = e->lowerN->node;
UNSUPPORTED("8djcrupis6ecv8lmmctw6yip5"); // 		if ((((mcnodeinfo_t*)((n1)->base.data))->highCluster) == (((mcnodeinfo_t*)((n2)->base.data))->highCluster))
UNSUPPORTED("541gafwz3ogkco0nvu11ydzf5"); // 		    if ((((mcnodeinfo_t*)((n1)->base.data))->highCluster)) {
UNSUPPORTED("dbluw2isra91y1v0bmnbfq9xr"); // 			e->penalty = 10000;
UNSUPPORTED("2l029fmuhkmmjb6ysad0hhtrn"); // 			e->higherN->order = -1;
UNSUPPORTED("yvsukemxnz484f31exr5ffav"); // 			e->lowerN->order = -1;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7wl99e8ddr2fa0q6xekbnmnxp"); //     for (idx = mcG->lvl_cnt - 1; idx >= 0; idx--) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("djofnr9fkrtozb4nufln20bfq"); // 	    for (id2 = 0; id2 < n->high_edgs_cnt; id2++) {
UNSUPPORTED("co7qa1vjkm48tglx27hauul0b"); // 		e = n->high_edgs[id2];
UNSUPPORTED("4u9fekoy5t2z05fdrloy15k5h"); // 		n1 = e->higherN->node;
UNSUPPORTED("5gkssj2rofud9d9ovnwdfmn5h"); // 		n2 = e->lowerN->node;
UNSUPPORTED("8djcrupis6ecv8lmmctw6yip5"); // 		if ((((mcnodeinfo_t*)((n1)->base.data))->highCluster) == (((mcnodeinfo_t*)((n2)->base.data))->highCluster))
UNSUPPORTED("541gafwz3ogkco0nvu11ydzf5"); // 		    if ((((mcnodeinfo_t*)((n1)->base.data))->highCluster)) {
UNSUPPORTED("dbluw2isra91y1v0bmnbfq9xr"); // 			e->penalty = 10000;
UNSUPPORTED("2l029fmuhkmmjb6ysad0hhtrn"); // 			e->higherN->order = -1;
UNSUPPORTED("yvsukemxnz484f31exr5ffav"); // 			e->lowerN->order = -1;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("cpuje9gcy0peesawx5p5fh1ol"); // 	reOrderLevel(l);
UNSUPPORTED("22hprzsku0hk6jtvfxwbsrk0e"); // 	normalizeLevel(l);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6yg5u0v9rziht12byqbf5f0xw
// static void readOrders(Agraph_t * g) 
public static Object readOrders(Object... arg) {
UNSUPPORTED("52n457qql8h4vdeligdruaske"); // static void readOrders(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c21enf3w0nz9vfmu0omf2pasm"); //     Agnode_t *v;
UNSUPPORTED("3vgqbf6prdxb3o8hfju87omh5"); //     char *bf;
UNSUPPORTED("7lrfd3npcqkgakq00km2isrez"); //     for (v = agfstnode(g); v; v = agnxtnode(g, v)) {
UNSUPPORTED("blcpdirav7kkb4zan0yrdylm1"); // 	bf = agget(v, "order");
UNSUPPORTED("a35fho493f7x0g8m01qin55nc"); // 	if (bf) {
UNSUPPORTED("9l8jgzrxrs46iroe1sd8bjlu2"); // 	    (((mcnodeinfo_t*)((v)->base.data))->order) = atoi(bf);
UNSUPPORTED("8b9nznnlw49b44kbw75ucapou"); // //              MND_rank(v)=atoi(bf);
UNSUPPORTED("98s1rtucg5tdcfj3kwdsc0cds"); // 	    fprintf(stderr, "retrieved order :%d\n", (((mcnodeinfo_t*)((v)->base.data))->order));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 yfsalqiv299xm2r3a6nkfa5f
// static void mincross(mcGraph * mcG) 
public static void mincross(mcGraph mcG) {
ENTERING("yfsalqiv299xm2r3a6nkfa5f","mincross");
try {
    int id;
    //   drawMatrix(mcG,"I0-original.png","a_original");
    /* dumpGraph (mcG, "before.gv"); */
UNSUPPORTED("st1pbs39l6dptgv7cn4327rw"); //     for (id = 20; id >= 0; id--) {
UNSUPPORTED("533c2pbkhm3z64ygz6eeocmkl"); // 	MAGIC_NUMBER = id;
UNSUPPORTED("37jds5tady6owp1ahvlp7dgdy"); // 	dumbcross(mcG, 25);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("77jkhll6oxhvkdaoz13dvsmvi"); //     for (id = 0; id <= 15; id++) {
UNSUPPORTED("533c2pbkhm3z64ygz6eeocmkl"); // 	MAGIC_NUMBER = id;
UNSUPPORTED("90a66urjmayrgn90q2ffkds2v"); // 	dumbcross(mcG, 10);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c3loynf34pzknaq0e7xl9h7jw"); //     dumpGraph (mcG, "c:/temp/before_final_trans.gv");
UNSUPPORTED("9t588f6loh7qky23dz9gzpaey"); //     _transpose(mcG,0);
UNSUPPORTED("8hkwpzw05hyc2wpnr1wn1ypc"); //     fprintf(stderr,"after transpose final count %d...\n", countAllX(mcG));
UNSUPPORTED("1n6ugrgzq115k4ks3tybt1hk2"); //     dumpGraph (mcG, "c:/temp/after.gv");
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("yfsalqiv299xm2r3a6nkfa5f","mincross");
}
}




//3 40av3zju94wqoolcikmz2ouuv
// Agraph_t *dot2_mincross (Agraph_t * srcGraph) 
public static Object dot2_mincross(Object... arg) {
UNSUPPORTED("9erp3zpsv7tadx2iy5bvt2iyg"); // Agraph_t *dot2_mincross (Agraph_t * srcGraph)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5yl865ac13owbmjpge77v9d5w"); //     mcGraph *mcG;
UNSUPPORTED("e1mituw4qdk17uvvsojpemjw5"); //     Agraph_t *g = mkMCGraph (srcGraph);
UNSUPPORTED("n41fla1yjbclzawqoh3is2ag"); //     graphGroups(g);
UNSUPPORTED("3qunay2o8m0xv11dkj1ujvoyq"); //     if (agattr(srcGraph, AGEDGE, "label", (char *) 0)) {
UNSUPPORTED("56tz7nfs0m8pymin7k5yog5v4"); // 	double_ranks(g);
UNSUPPORTED("2vxwdayh5kh9w9cylv6ob49d6"); // 	addNodes(g, 1);
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("7ry07cneuzxih621dxrh8lkrr"); // 	addNodes(g, 0);
UNSUPPORTED("9m234z4to7cdayq8cmyyjiu5c"); //     nodesToClusters(g);
UNSUPPORTED("dor9tbnup56g17eowbm9csx0"); //     mcG = createMatrixIn(g);
UNSUPPORTED("8ccqflqb45v1a1r7p0p2rlr8h"); //     fprintf(stderr, "in :%d\n", countAllX(mcG));
UNSUPPORTED("6pg5i5dsa03h9yju6piuqn20o"); // /*    mcG=createMatrixOut(g);
UNSUPPORTED("n8a061560vup33j21x5eygs0"); //     fprintf(stderr, ("out :%d\n",countAllX(mcG));*/
UNSUPPORTED("8x6o05pt215ybf12kjaszf10r"); //     createGroups(mcG->g);
UNSUPPORTED("562bj6tb68mo5okeuhor7ve2e"); //     clusterEdges(mcG);
UNSUPPORTED("7zvwhfbi4b8iau6pp1c6hhqx9"); //     mincross(mcG);
UNSUPPORTED("5zvgkiqd188m4khixyl5orh98"); //     /* store order info in g */
UNSUPPORTED("a8wjovt96o9yj7ue2p2pxgykc"); //     free_mcGraph (mcG);
UNSUPPORTED("2syri7q5tc0jyvwq8ecyfo3vr"); //     return g;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e2k95bhif78zfwwf2d9kthgz9
// static void dumpGraph (mcGraph* mcG, char* fname) 
public static Object dumpGraph(Object... arg) {
UNSUPPORTED("d9j5wd6yq8ryl5lkwy679s0fe"); // static void dumpGraph (mcGraph* mcG, char* fname)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cy87dnventm059kt0bzilxdy8"); //     FILE* fp = fopen (fname, "w");
UNSUPPORTED("1q097cfnc08ewrpugqjjamrgh"); //     int id, id2, idx;
UNSUPPORTED("4ktkq3h6yszijd3dpt79oj7g7"); //     mcLevel *l;
UNSUPPORTED("7gpav9whdibcebd715ar61pu4"); //     mcLevel *nextl;
UNSUPPORTED("cfb4hnjgcfi1n3ju5ygwmyptt"); //     mcNode *n;
UNSUPPORTED("7bc3ft53in0b4rfw1o4mtsepi"); //     mcNode *nn;
UNSUPPORTED("bycbmusvln8r8emwvkekqbf52"); //     mcEdge *e;
UNSUPPORTED("b9xopm8bhtnydmfnt9tw8gz53"); //     int dely = 72;
UNSUPPORTED("4t4teh9hris5ydzb1sc4gbqwa"); //     int delx = 100;
UNSUPPORTED("3tsetuywdzi8crkdp7yfkzgs0"); //     char* color;
UNSUPPORTED("bx1dr4weajm160sejmy560gvb"); //     char buf[512];
UNSUPPORTED("2dwpn921ssenbubatikqpgviv"); //     char buf2[512];
UNSUPPORTED("ce3d8dr16nsd20x4vvyl6i4w5"); //     int width, maxl;
UNSUPPORTED("304p80cpezoo5tih4fcsob9cq"); //     if (!fp) {
UNSUPPORTED("9qahb3gzryhthp7rs0psjlbti"); // 	fprintf (stderr, "Could not open %s for writing\n", fname);
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("wwtjo9ingaz2fixld0n20uj9"); //     fputs ("digraph {\n", fp);
UNSUPPORTED("e7tgqnl54ec25s7uswwaicjlo"); //     fputs ("  node[shape=box fontsize=8]\n", fp);
UNSUPPORTED("69yo3g8bq6ru27ndmv9e17rok"); //     maxl = 0;
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("4c2etaxmedg7lohgfbedrqilz"); // 	if (l->nodecnt > maxl) maxl = l->nodecnt;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("23uqyib05am30qz2xbdjwhcmt"); //     width = delx*(maxl+2);
UNSUPPORTED("2mrpbit82k9ego0moiucg6tu5"); //     for (idx = 0; idx < mcG->lvl_cnt; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("xw0vd5fqml6m4g28vuf1t07i"); //         delx = width/(l->nodecnt + 1); 
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("7x6xcszg8n137u61sz9zial8h"); // 	    sprintf(buf, "%s(%0.1f)", agnameof(n->node), n->order);
UNSUPPORTED("a55w82f9pa3m1o5zs7r8tgjwk"); // 	    if (n->group)
UNSUPPORTED("2bex896xos3ak4gq3jof5aoin"); // 		color = "red";
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("2hm4ng34o2djs8z7qg2ac3c1x"); // 		color = "black";
UNSUPPORTED("2qklawoy4qcv4ptyhkeuqojon"); // 	    fprintf (fp, "  \"%s\" [pos=\"%d,%d\" color=%s]\n", buf, (id+1)*delx, -dely*idx, color);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c8q5cvx9hmmsdibqmx9mp75z5"); //     for (idx = 0; idx < mcG->lvl_cnt-1; idx++) {
UNSUPPORTED("b8fr39hhye2rfyi2522zknuxi"); // 	l = mcG->lvls[idx];
UNSUPPORTED("f1enia431tqgkcvwc1vmdcus0"); // 	nextl = mcG->lvls[idx + 1];
UNSUPPORTED("c7rwfru23njedk19myuhilfva"); // 	for (id = 0; id < l->nodecnt; id++) {
UNSUPPORTED("anz3ggz6jht4ekgy5wx9mft53"); // 	    n = l->nodes[id];
UNSUPPORTED("7x6xcszg8n137u61sz9zial8h"); // 	    sprintf(buf, "%s(%0.1f)", agnameof(n->node), n->order);
UNSUPPORTED("djofnr9fkrtozb4nufln20bfq"); // 	    for (id2 = 0; id2 < n->high_edgs_cnt; id2++) {
UNSUPPORTED("co7qa1vjkm48tglx27hauul0b"); // 		e = n->high_edgs[id2];
UNSUPPORTED("7nzstkwyxnawjg21wfzwhbn9t"); // 		nn = e->higherN;
UNSUPPORTED("ecgvv7hav8e0cpr8v3mhsqlw8"); // 		sprintf(buf2, "%s(%0.1f)", agnameof(nn->node), nn->order);
UNSUPPORTED("3emyydh8131ml40vcgxkbrmvk"); // 		if (e->penalty > 1)
UNSUPPORTED("7d248l62bnn9ri08toj9vastd"); // 		    color = "red";
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("axx7q4yy90hd2qya7l3hppd5c"); // 		    color = "black";
UNSUPPORTED("8bmmtd5ryqi57k4n3cuxpvq9i"); // 		fprintf (fp, "  \"%s\" -> \"%s\" [color=%s]\n", buf, buf2, color);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("69smfbpzurcjvgjvm90vhl35k"); //     fputs ("}\n", fp);
UNSUPPORTED("1pp59921axx4040zs2fdet7px"); //     fclose (fp);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5o1uevkm8c7nsineh4cnrwosm
// static void exchange(mcNode* v, mcNode* w) 
public static Object exchange(Object... arg) {
UNSUPPORTED("8q36tum4w343y2ap7dx3ehu5s"); // static void exchange(mcNode* v, mcNode* w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2l047owusolzbnhmogv9ywrup"); //     int vi, wi;
UNSUPPORTED("a7hnfx9d99vtxglc8zwhubf29"); //     vi=(int)v->order;
UNSUPPORTED("dg0ewl176sixvv7v1oisqtsa4"); //     wi=(int)w->order;
UNSUPPORTED("52gaxlhek9xo28holcxrago12"); //     v->order=(float)wi;
UNSUPPORTED("7orzwye57lst4vw74mj2dggst"); //     w->order=(float)vi;
UNSUPPORTED("56g9wavpokjulo5n179k4erm9"); // //	reOrderLevel((mcLevel*)v->level);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cmxewypo1lk6mmwgctc84ntf9
// static int in_cross(mcNode* v, mcNode* w) 
public static Object in_cross(Object... arg) {
UNSUPPORTED("1lmsql6xcaf1d622hpw7mqics"); // static int in_cross(mcNode* v, mcNode* w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2nigkvlsj3wacws75fl1mhppt"); //     register mcEdge* e1, *e2;
UNSUPPORTED("ge64g62liro8mpc6l1z0fefc"); //     register int inv, cross = 0, t;
UNSUPPORTED("dt3rdbg6dnu27soufh2fuxw7y"); //     int id,id2;
UNSUPPORTED("5hfh7jkth5ta05byscw9r1kg"); //     for (id=0;id < w->low_edgs_cnt; id++)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("4hv4jecjd9mno7tvdiuqqk2nb"); // 	register int cnt;		
UNSUPPORTED("9cna9xu1l9dcg6x9zz47odd81"); // 	e2=w->low_edgs[id];
UNSUPPORTED("1rklrml51mg60g5k0xoc8echq"); // 	cnt=(int)e2->penalty;
UNSUPPORTED("8zq4h4uhibr8kq3u26j40a4oq"); // 	inv =(int) e2->lowerN->order;
UNSUPPORTED("bdhc2rfugl4a8dc0rw86y6gdh"); // 	for (id2=0;id2 < v->low_edgs_cnt; id2++)
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("e8ogx9szmc2g65akk86uuukjt"); // 	    e1=v->low_edgs[id2];
UNSUPPORTED("asgqnnudojbd0pq2htosi4hse"); // 	    t =(int)e1->lowerN->order-inv;
UNSUPPORTED("bau6pz5v9hlbbnoqjebe388qc"); // 	    if ((t > 0)
UNSUPPORTED("5oiiiiqkh4fsgrvy0nfm0x4fa"); // 		|| ((t == 0)
UNSUPPORTED("45lbhfwh8bjn1y0dk3vaj7x18"); // 		&& ( ED_tail_port(e1->lowerN->node).p.x > ED_tail_port(e2->lowerN->node).p.x)))
UNSUPPORTED("3iu7w6t0y2f724o4pq2dt09w0"); // 		    cross += (int)e1->penalty * cnt;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8dm5o3tsfvxtjilyob6q5ndi1"); //     return cross;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a76uuv2jnllk5qedbh03497rx
// static int out_cross(mcNode* v, mcNode* w) 
public static Object out_cross(Object... arg) {
UNSUPPORTED("9i77orncsveleaj91o5z3c8o3"); // static int out_cross(mcNode* v, mcNode* w)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2nigkvlsj3wacws75fl1mhppt"); //     register mcEdge* e1, *e2;
UNSUPPORTED("ge64g62liro8mpc6l1z0fefc"); //     register int inv, cross = 0, t;
UNSUPPORTED("dt3rdbg6dnu27soufh2fuxw7y"); //     int id,id2;
UNSUPPORTED("7wudyybw555jwedi1acv7q7ye"); //     for (id=0;id < w->high_edgs_cnt; id++)
UNSUPPORTED("6ld19omy1z68vprfzbhrjqr2z"); //     {
UNSUPPORTED("4hv4jecjd9mno7tvdiuqqk2nb"); // 	register int cnt;		
UNSUPPORTED("4z9ejycciljwusgpy73809vl5"); // 	e2=w->high_edgs[id];
UNSUPPORTED("1rklrml51mg60g5k0xoc8echq"); // 	cnt=(int)e2->penalty;
UNSUPPORTED("9pxaqpaupv9ifjq8j0yh0cnka"); // 	inv = (int)e2->higherN->order;
UNSUPPORTED("1m8f8exln5tl5o5m1igvem81p"); // 	for (id2=0;id2 < v->high_edgs_cnt; id2++)
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("17smq924wu902wk5q3f9q6vqm"); // 	    e1=v->high_edgs[id2];
UNSUPPORTED("6zwuhl2t58m1hokvvl5oi6u3a"); // 	    t =(int)e1->higherN->order-inv;
UNSUPPORTED("bau6pz5v9hlbbnoqjebe388qc"); // 	    if ((t > 0)
UNSUPPORTED("5oiiiiqkh4fsgrvy0nfm0x4fa"); // 		|| ((t == 0)
UNSUPPORTED("du2ash4w1x3mvj94aaxn5mdso"); // 		&& ( ED_head_port(e1->higherN->node).p.x > ED_head_port(e2->higherN->node).p.x)))
UNSUPPORTED("77r4a3aokn3vtna3gdz3fg7z3"); // 		    cross +=(int) e1->penalty * cnt;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8dm5o3tsfvxtjilyob6q5ndi1"); //     return cross;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e1c9fqmv9k5msg081g8ovvan3
// static int transpose_step(mcGraph* mcG, int r, int reverse) 
public static Object transpose_step(Object... arg) {
UNSUPPORTED("1jne35ziu54tdj3aokvr6rhsz"); // static int transpose_step(mcGraph* mcG, int r, int reverse)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("970giwpms1ljmt0px5djlqs0z"); //     int i, c0, c1, rv;
UNSUPPORTED("ed8e25kpizopz8e59x4jfikno"); //     mcNode *v,*w;
UNSUPPORTED("9g47rwc79u4w5arxklzcc2nbi"); //     mcLevel* l= mcG->lvls[r];
UNSUPPORTED("yy0fwjrmxw3jbi85mvwrka7f"); //     rv = 0;
UNSUPPORTED("3u7z430fw8zqk45xufuww45wr"); //     l->candidate=0;
UNSUPPORTED("6p5o1ia40o8r7r8vwcwzyd6iu"); //     for (i = 0; i <l->nodecnt-1;i++) {
UNSUPPORTED("c5pm3hl7flev9q71ipnl3662f"); // 	v=l->nodes[i];
UNSUPPORTED("avqazoc5cnhfu3mdx7x63g2g0"); // 	w=l->nodes[i+1];
UNSUPPORTED("6qxfbeuwo5g5o85q322pdbicn"); // 	assert(v->order < w->order);
UNSUPPORTED("dghourkf44y5u5q4gxo1y2n4u"); // 	/*if (left2right(mcG, v, w))
UNSUPPORTED("33ajuajeyycxlen1xo1c5rnt8"); // 	    continue;*/
UNSUPPORTED("s29ss3mt0cdkkmvdy0cjo6q8"); // 	c0 = c1 = 0;
UNSUPPORTED("83q0jkf1uxirn1vqpf9uv4fmk"); // 	if (r > 0) {
UNSUPPORTED("14j6bnfhech8funkwo1cqst8x"); // 	    c0 += in_cross(v, w);
UNSUPPORTED("dudd7ptz2hdlnb18aetdetr3o"); // 	    c1 += in_cross(w, v);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8yommza5jcbohkpslr8ny9azt"); // 	if (mcG->lvl_cnt > (r+1)) 
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("7viyvlr11k6yoztmgyh2bajsh"); // 	    c0 += out_cross(v, w);
UNSUPPORTED("4z0o1rshenpr595htbxnx2oyx"); // 	    c1 += out_cross(w, v);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("115l8canrsqrfr8wiim5k9mor"); // 	if ((c1 < c0) || ((c0 > 0) && reverse && (c1 == c0))) 
UNSUPPORTED("98gvqspn5y1bfyr14rwoaqk67"); // 	{
UNSUPPORTED("49eey742kulff9x2tveqpt8gx"); // 	    exchange(v, w);
UNSUPPORTED("554s3oe2po6nzun5f4kgfyr0a"); // 	    rv += (c0 - c1);
UNSUPPORTED("7u9o029xjj1bsiuvcqhgxe1e9"); // 	    l->candidate=NOT(0);
UNSUPPORTED("atl6ylcavut8afwq4v0hww8zr"); // 	    if (r > 0) 
UNSUPPORTED("ciytpn715qg5x8a3nr5gycbdf"); // 		mcG->lvls[r-1]->candidate=NOT(0);
UNSUPPORTED("afroxepkmdlweh1fjvapytgoq"); // 	    if (r < mcG->lvl_cnt-1) 
UNSUPPORTED("f4grs5v7wcngut5t2qcl8xpwz"); // 		mcG->lvls[r+1]->candidate = NOT(0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("b6vja2uknkegi7lsu8fjnmm29"); //     reOrderLevel( mcG->lvls[r]);
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9zpt398212dphz0bw3rnfq0fp
// static void _transpose(mcGraph * mcG, int reverse) 
public static Object _transpose(Object... arg) {
UNSUPPORTED("c85hruprwblk84lao61lcztre"); // static void _transpose(mcGraph * mcG, int reverse)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ccja1vlzrgybom5tchpgfftsq"); //     int r, delta;
UNSUPPORTED("cwjy6ohmrkk3khwv5ngccbbja"); //     for (r = 0; r <= mcG->lvl_cnt-1;r++)
UNSUPPORTED("8yyvkpqelj62xg3fzj61mx6o8"); // 	mcG->lvls[r]->candidate= NOT(0);
UNSUPPORTED("53kc41p479auwcycfsbhw8xix"); //     do {
UNSUPPORTED("1nq14goek8390ttms5gapf445"); // 	delta = 0;
UNSUPPORTED("483wu7q3ml1c5qwxvcwvxfhpu"); // 	for (r = 0; r <= mcG->lvl_cnt-1;r++)
UNSUPPORTED("6pjalxixg8dnhbhc46pm6e6ay"); //         {
UNSUPPORTED("em3srf2cc37caxhfr5swy5xl9"); // 	    if (mcG->lvls[r]->candidate) 
UNSUPPORTED("6dbei3uox5ql5a1vaaguh0xzp"); // 	    {
UNSUPPORTED("8jjo6a2e9uskkbnrjcemo45sk"); // 		delta += transpose_step(mcG, r, reverse);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("53ox9pov5iq5rjyczxrljjvzi"); // 	/*} while (delta > ncross(g)*(1.0 - Convergence)); */
UNSUPPORTED("52ud7we98x3ja1dsotq78rt74"); //     } while (delta >= 1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bdubzk3xjlj8q0sj1smpnru21
// static void fast_node(graph_t * g, Agnode_t * n) 
public static Object fast_node(Object... arg) {
UNSUPPORTED("1jl6ppssdg4h2wbc1kd00ob6x"); // static void fast_node(graph_t * g, Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4bwmrormpekjvmxby13l88y3h"); //    ND_next(n) = GD_nlist(g);
UNSUPPORTED("53d41ipaqxwcxk95xcn6ah9tr"); //     if (ND_next(n))
UNSUPPORTED("5arweocgs4q3d9qczu1gc0wsm"); // 	ND_prev(ND_next(n)) = n;
UNSUPPORTED("eipmxdmcne7157w07q4x18xul"); //     GD_nlist(g) = n;
UNSUPPORTED("a3ltpil82kuzhw2mom6r0x541"); //     ND_prev(n) = NULL;
UNSUPPORTED("28zc8mru4b14wj87ydwk5dgdt"); //     assert(n != ND_next(n));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
