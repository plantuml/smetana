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

public class ns__c {
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


//1 5kbimjtsi4ulxiyk2w1brj6py
// static graph_t *G
private static Agraph_s G;
//1 608xz3ruk6qq4bs1sagl9fuav
// static int N_nodes, N_edges
private static int N_nodes, N_edges;

//1 cfz1upsuq7ct75nfqmyg925bo
// static int Minrank, Maxrank
static private int Minrank, Maxrank;

//1 1xxb2cip20ls1938be1sgpc8s
// static int S_i
private static int S_i;

//1 2ahnzxrqoz8eoicu88g9jzic7
// static int Search_size
private static int Search_size;

//1 11b7xeg0x1f09v305mxwvgbhs
// static elist Tree_edge
private static final __struct__<elist> Tree_edge = __struct__.from(elist.class);

//1 3t9aql1n1eclyvy7p2nwyacor
// static nlist_t Tree_node
private static final __struct__<nlist_t> Tree_node = __struct__.from(nlist_t.class);



//3 f5a6u77k9y8t78t57i8kndbc3
// static void add_tree_edge(edge_t * e) 
public static Object add_tree_edge(Object... arg) {
UNSUPPORTED("9hwux7cj9l2oabkdk96on7ayw"); // static void add_tree_edge(edge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("cuxe2km9yjmfwmu1fxgdwr45j"); //     if ((ED_tree_index(e) >= 0))
UNSUPPORTED("53h65fwnivhy7ght7m3ql45a1"); // 	abort();
UNSUPPORTED("8934ue3mwml2nan600ofoyr0d"); //     ED_tree_index(e) = Tree_edge.size;
UNSUPPORTED("8b0zifd4kwjb7y83nqtvcr9gt"); //     Tree_edge.list[Tree_edge.size++] = e;
UNSUPPORTED("bfztb1gw6vkhliqjhate5xnp"); //     if (ND_mark(agtail(e)) == 0)
UNSUPPORTED("bv72etge563olrpt0m6f77mxm"); // 	Tree_node.list[Tree_node.size++] = agtail(e);
UNSUPPORTED("emwdciyowp4p2hvdolq5eiiei"); //     if (ND_mark(aghead(e)) == 0)
UNSUPPORTED("dw5dycgchrhg1tqi4ubryygk0"); // 	Tree_node.list[Tree_node.size++] = aghead(e);
UNSUPPORTED("dul1axf6kjslblufm4omk5k32"); //     n = agtail(e);
UNSUPPORTED("48nn8i73qtqmak66tas8adfbm"); //     ND_mark(n) = NOT(0);
UNSUPPORTED("3xvzl1ega95h9owc6oog2bh2q"); //     ND_tree_out(n).list[ND_tree_out(n).size++] = e;
UNSUPPORTED("epz5g5nkje8kyzfswti7gevtb"); //     ND_tree_out(n).list[ND_tree_out(n).size] = NULL;
UNSUPPORTED("90guunk0aet85xffou8lcs651"); //     n = aghead(e);
UNSUPPORTED("48nn8i73qtqmak66tas8adfbm"); //     ND_mark(n) = NOT(0);
UNSUPPORTED("b1hgdvytcrufm3mmzouhu6baf"); //     ND_tree_in(n).list[ND_tree_in(n).size++] = e;
UNSUPPORTED("emtdq0qedxotm9k9lzxv9u2kh"); //     ND_tree_in(n).list[ND_tree_in(n).size] = NULL;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9b7b78pmafynmvffztrqnlxtn
// static void exchange_tree_edges(edge_t * e, edge_t * f) 
public static void exchange_tree_edges(Agedge_s e, Agedge_s f) {
ENTERING("9b7b78pmafynmvffztrqnlxtn","exchange_tree_edges");
try {
    int i, j;
    Agnode_s n;
    ED_tree_index(f, ED_tree_index(e));
    Tree_edge.getArray("list").plus(ED_tree_index(e)).setPtr(f);
    ED_tree_index(e, -1);
    n = agtail(e);
    ND_tree_out(n).setInt("size", ND_tree_out(n).getInt("size") -1);
    i = ND_tree_out(n).getInt("size");
    for (j = 0; j <= i; j++)
	if (EQ(ND_tree_out(n).getArray("list").plus(j).getPtr(), e))
	    break;
    ND_tree_out(n).getArray("list").plus(j).setPtr(ND_tree_out(n).getArray("list").plus(i).getPtr());
    ND_tree_out(n).getArray("list").plus(i).setPtr(null);
    n = aghead(e);
    ND_tree_in(n).setInt("size", ND_tree_in(n).getInt("size") -1);
    i = ND_tree_in(n).getInt("size");
    for (j = 0; j <= i; j++)
	if (EQ(ND_tree_in(n).getArray("list").plus(j).getPtr(), e))
	    break;
    ND_tree_in(n).getArray("list").plus(j).setPtr(ND_tree_in(n).getArray("list").plus(i).getPtr());
    ND_tree_in(n).getArray("list").plus(i).setPtr(null);
    n = agtail(f);
    ND_tree_out(n).getArray("list").plus(ND_tree_out(n).getInt("size")).setPtr(f);
    ND_tree_out(n).setInt("size", ND_tree_out(n).getInt("size") +1);
    ND_tree_out(n).getArray("list").plus(ND_tree_out(n).getInt("size")).setPtr(null);
    n = aghead(f);
    ND_tree_in(n).getArray("list").plus(ND_tree_in(n).getInt("size")).setPtr(f);
    ND_tree_in(n).setInt("size", ND_tree_in(n).getInt("size") +1);
    ND_tree_in(n).getArray("list").plus(ND_tree_in(n).getInt("size")).setPtr(null);
} finally {
LEAVING("9b7b78pmafynmvffztrqnlxtn","exchange_tree_edges");
}
}




//3 847ekj74ftx95ibumvjygzxdc
// static void init_rank(void) 
public static Object init_rank(Object... arg) {
UNSUPPORTED("9y7ivrr4l5s7wx7hbbkjpd2fr"); // static
UNSUPPORTED("brejoruow5799elaq1yi9ijh5"); // void init_rank(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4q9bde7a58uhaducmfilgk6m5"); //     int ctr;
UNSUPPORTED("8l357uyv69cyft4f0wmp7ii7c"); //     nodequeue *Q;
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("2r3r48zblewquughq8s4zl609"); //     Q = new_queue(N_nodes);
UNSUPPORTED("ed34tf52s8gum31l4j47ozwuo"); //     ctr = 0;
UNSUPPORTED("dvbrp4loxvpuo0ka6h0nkhaac"); //     for (v = agfstnode(G); v; v = agnxtnode(G, v)) {
UNSUPPORTED("e0lreo4zquvv7fq5q5ni4n98h"); // 	if (ND_priority(v) == 0)
UNSUPPORTED("5tepw20w2hxa93j2id3ge7d04"); // 	    enqueue(Q, v);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1rmb5uh14gcp80zqyempfst6x"); //     while ((v = dequeue(Q))) {
UNSUPPORTED("267mynxobr4dg9e9fmuk3l1vu"); // 	ND_rank(v) = 0;
UNSUPPORTED("7f3y9f2k317dpdkyncc8evvc4"); // 	ctr++;
UNSUPPORTED("aqipa8wmagtcn8jv6vdu0z03f"); // 	for (e = agfstin(G, v); e; e = agnxtin(G, e))
UNSUPPORTED("9v01gaa0zp3kq4rg1zv6tm4w5"); // 	    ND_rank(v) =
UNSUPPORTED("jmyy14feaeibke9jxmastbz3"); // 		MAX(ND_rank(v), ND_rank(agtail(e)) + ED_minlen(e));
UNSUPPORTED("9vxousxluf6prrwe75aoncj8w"); // 	for (e = agfstout(G, v); e; e = agnxtout(G, e))
UNSUPPORTED("2le0yl9qhucvtdx7is7lm7c4p"); // 	    if (--(ND_priority(aghead(e))) <= 0)
UNSUPPORTED("676mko62s1tzk2ay6vqcm8lyl"); // 		enqueue(Q, aghead(e));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dahefyb4gfuw7z5o2536930dy"); //     if (ctr != N_nodes) {
UNSUPPORTED("7sgp99x1l3hzfks5wykxa87gf"); // 	agerr(AGERR, "trouble in init_rank\n");
UNSUPPORTED("a4razb86hvug6zkcbnj76zl68"); // 	for (v = agfstnode(G); v; v = agnxtnode(G, v)) {
UNSUPPORTED("5z2nap2bo384o8py63gj3sxbi"); // 	    if (ND_priority(v))
UNSUPPORTED("9odlmuvxc7en4dgme0nscf4vf"); // 		agerr(AGPREV, "\t%s %d\n", agnameof(v), ND_priority(v));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1y2x4tcqce2uwpsykzl99q053"); //     free_queue(Q);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bj7ux5kz8ls2lnfh0ix6i00b9
// static node_t *incident(edge_t * e) 
public static Agnode_s incident(Agedge_s e) {
ENTERING("bj7ux5kz8ls2lnfh0ix6i00b9","incident");
try {
    if (ND_mark(agtail(e))!=0) {
	if (ND_mark(aghead(e)) == 0)
	    return agtail(e);
    } else {
	if (ND_mark(aghead(e))!=0)
	    return aghead(e);
    }
    return null;
} finally {
LEAVING("bj7ux5kz8ls2lnfh0ix6i00b9","incident");
}
}




//3 ds9lhib1kje74rm61giiv06og
// static edge_t *leave_edge(void) 
public static Object leave_edge(Object... arg) {
UNSUPPORTED("4hkoxrh4axw5h92mzoftrdgsm"); // static edge_t *leave_edge(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("54g3irtdif92xm104k73ysixr"); //     edge_t *f, *rv = NULL;
UNSUPPORTED("28wwq82z0qz3hpi9ny8nhn8r6"); //     int j, cnt = 0;
UNSUPPORTED("6cxhc1kztw2q5l82nr7imf5q5"); //     j = S_i;
UNSUPPORTED("5v7mh8ab9raootjrfli21vd84"); //     while (S_i < Tree_edge.size) {
UNSUPPORTED("7e8ig5rviw5rpg5nci9pkp26x"); // 	if (ED_cutvalue((f = Tree_edge.list[S_i])) < 0) {
UNSUPPORTED("6ct09lmz8b842ztujw9lsga90"); // 	    if (rv) {
UNSUPPORTED("enob0jev0i3qfgwbtmbfsmt3o"); // 		if (ED_cutvalue(rv) > ED_cutvalue(f))
UNSUPPORTED("azx50xtma9jw5xhlg0n18w7ef"); // 		    rv = f;
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("d3r8wsirg3w0sucfw02kqgwjs"); // 		rv = Tree_edge.list[S_i];
UNSUPPORTED("d2vt6kxletqkql14vyghczprr"); // 	    if (++cnt >= Search_size)
UNSUPPORTED("7ypdy5hzykanxlhx32ii8nwbg"); // 		return rv;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("7xjr9gzeco2strremr1tha33k"); // 	S_i++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6dvucm8vl2c0kbs45wo70dv8d"); //     if (j > 0) {
UNSUPPORTED("e4gsrp62f0wncsopbn9370to4"); // 	S_i = 0;
UNSUPPORTED("a51kd83s1ykzlcj7h0i3vfwut"); // 	while (S_i < j) {
UNSUPPORTED("2w8yyimebzmgg5gk0sobuhu3a"); // 	    if (ED_cutvalue((f = Tree_edge.list[S_i])) < 0) {
UNSUPPORTED("11vvx0bxl5bipgfofee5q0iac"); // 		if (rv) {
UNSUPPORTED("1g2gsbdvxrza46li6eru6cbjk"); // 		    if (ED_cutvalue(rv) > ED_cutvalue(f))
UNSUPPORTED("eg3qac3jdgmldml7frtlgup9k"); // 			rv = f;
UNSUPPORTED("738mi6h8ef0itznt34ngxe25o"); // 		} else
UNSUPPORTED("3834ngh8uw7vg3gvdcz1fu94i"); // 		    rv = Tree_edge.list[S_i];
UNSUPPORTED("4qi46mxuwthkw7mf5d1d0kfa8"); // 		if (++cnt >= Search_size)
UNSUPPORTED("7nukzdmlh4mklsedpm903o4cj"); // 		    return rv;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("9u8bsdoueffypl5f7cm1vltb8"); // 	    S_i++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


//1 3wm7ej298st1xk7rbhbtnbk64
// static edge_t *Enter
private static Agedge_s Enter;

//1 dx9f0e947f5kjhc2eftn43t90
// static int Low, Lim, Slack
private static int Low, Lim, Slack;



//3 coxab0ilk11thzqlq5rbzgib2
// static void dfs_enter_outedge(node_t * v) 
public static Object dfs_enter_outedge(Object... arg) {
UNSUPPORTED("5aeisjkzrf2n2kypeh7zb86ik"); // static void dfs_enter_outedge(node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("f5kktpag8d9zee5idgik7srfl"); //     int i, slack;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("bzrns1aafcy20z1wn82twd7ca"); //     for (e = agfstout(G, v); e; e = agnxtout(G, e)) {
UNSUPPORTED("9w7yrx12q8hey28btl8pxnp0x"); // 	if ((ED_tree_index(e) >= 0) == 0) {
UNSUPPORTED("c8cclzht36biw2cwrrk81dmxz"); // 	    if (!(((Low) <= (ND_lim(aghead(e)))) && ((ND_lim(aghead(e))) <= (Lim)))) {
UNSUPPORTED("dk10m0yccqakb1yot8exu2c0y"); // 		slack = ((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e));
UNSUPPORTED("3bx25ml174yh77z4gvt8f9kbw"); // 		if ((slack < Slack) || (Enter == NULL)) {
UNSUPPORTED("bu6yvi44cx564ex4bqjqwkg6l"); // 		    Enter = e;
UNSUPPORTED("8xs72plo1jwfx1py5vfl6e30x"); // 		    Slack = slack;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("511osbx5joqk0e7vic2qmul6t"); // 	} else if (ND_lim(aghead(e)) < ND_lim(v))
UNSUPPORTED("b5nky1f2p4lwciitop8n892oy"); // 	    dfs_enter_outedge(aghead(e));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3hbniohqzyw4q06k6khi0lhr3"); //     for (i = 0; (e = ND_tree_in(v).list[i]) && (Slack > 0); i++)
UNSUPPORTED("cq4gpojg2kbk8nekia9oelvfe"); // 	if (ND_lim(agtail(e)) < ND_lim(v))
UNSUPPORTED("1e6s3gszer8v4tv4hlrdhoimv"); // 	    dfs_enter_outedge(agtail(e));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ate0igf4ffmsjkgx649pesu8k
// static void dfs_enter_inedge(node_t * v) 
public static Object dfs_enter_inedge(Object... arg) {
UNSUPPORTED("2x7x087gw29b7je24pxio787d"); // static void dfs_enter_inedge(node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("f5kktpag8d9zee5idgik7srfl"); //     int i, slack;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("74z4oi1uzavuqrtxdygzkb4ro"); //     for (e = agfstin(G, v); e; e = agnxtin(G, e)) {
UNSUPPORTED("9w7yrx12q8hey28btl8pxnp0x"); // 	if ((ED_tree_index(e) >= 0) == 0) {
UNSUPPORTED("a3a59zvao310x5onr661ogre1"); // 	    if (!(((Low) <= (ND_lim(agtail(e)))) && ((ND_lim(agtail(e))) <= (Lim)))) {
UNSUPPORTED("dk10m0yccqakb1yot8exu2c0y"); // 		slack = ((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e));
UNSUPPORTED("3bx25ml174yh77z4gvt8f9kbw"); // 		if ((slack < Slack) || (Enter == NULL)) {
UNSUPPORTED("bu6yvi44cx564ex4bqjqwkg6l"); // 		    Enter = e;
UNSUPPORTED("8xs72plo1jwfx1py5vfl6e30x"); // 		    Slack = slack;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("egu4oe770po99e1y3l7wrr6ta"); // 	} else if (ND_lim(agtail(e)) < ND_lim(v))
UNSUPPORTED("8w8dcgrmmbj0l6zqzp1xyr53h"); // 	    dfs_enter_inedge(agtail(e));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("eyo4c4vhyxp4r5v2spdfw6cel"); //     for (i = 0; (e = ND_tree_out(v).list[i]) && (Slack > 0); i++)
UNSUPPORTED("a8pgusbpflyi3iumaz2rfpjnj"); // 	if (ND_lim(aghead(e)) < ND_lim(v))
UNSUPPORTED("mn523p3ufj3pzvy2kpdzc37d"); // 	    dfs_enter_inedge(aghead(e));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 aeu2po1o1rvibmafk0k8dw0fh
// static edge_t *enter_edge(edge_t * e) 
public static Agedge_s enter_edge(Agedge_s e) {
ENTERING("aeu2po1o1rvibmafk0k8dw0fh","enter_edge");
try {
    Agnode_s v;
    int outsearch;
    /* v is the down node */
    if (ND_lim(agtail(e)) < ND_lim(aghead(e))) {
	v = agtail(e);
	outsearch = 0;
    } else {
	v = aghead(e);
	outsearch = 1;
    }
    Enter = null;
    Slack = INT_MAX;
    Low = ND_low(v);
    Lim = ND_lim(v);
    if (outsearch!=0)
	dfs_enter_outedge(v);
    else
	dfs_enter_inedge(v);
    return Enter;
} finally {
LEAVING("aeu2po1o1rvibmafk0k8dw0fh","enter_edge");
}
}




//3 bvnn2oi1xrybfmazcx0i8uzsh
// static int treesearch(node_t * v) 
public static Object treesearch(Object... arg) {
UNSUPPORTED("8gnt23nlo0f47yo5csz6vtjfy"); // static int treesearch(node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("bzrns1aafcy20z1wn82twd7ca"); //     for (e = agfstout(G, v); e; e = agnxtout(G, e)) {
UNSUPPORTED("65dz7h8x9ewx1fb51c741v6hu"); // 	if ((ND_mark(aghead(e)) == 0) && (((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e)) == 0)) {
UNSUPPORTED("7gwsx8inwxlpl498qeiow1bog"); // 	    add_tree_edge(e);
UNSUPPORTED("75s0r95dsn03r9xtiwyeje75u"); // 	    if ((Tree_edge.size == N_nodes - 1) || treesearch(aghead(e)))
UNSUPPORTED("2x33o4mmwvtxskc8zij2mgkxm"); // 		return NOT(0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("74z4oi1uzavuqrtxdygzkb4ro"); //     for (e = agfstin(G, v); e; e = agnxtin(G, e)) {
UNSUPPORTED("desbox45bk9hg5eqzocaxiafz"); // 	if ((ND_mark(agtail(e)) == 0) && (((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e)) == 0)) {
UNSUPPORTED("7gwsx8inwxlpl498qeiow1bog"); // 	    add_tree_edge(e);
UNSUPPORTED("f3ctm1g4y9x7pxqz4cirijlsn"); // 	    if ((Tree_edge.size == N_nodes - 1) || treesearch(agtail(e)))
UNSUPPORTED("2x33o4mmwvtxskc8zij2mgkxm"); // 		return NOT(0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 185k64hub2o0tqep6pw7a2844
// static int tight_tree(void) 
public static Object tight_tree(Object... arg) {
UNSUPPORTED("ekxjptmb8690vqr7g6fz5wixq"); // static int tight_tree(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("4i16cidbem2pp7lmgjf1lviav"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("1btcv7arbo4kdjfc0iu4lseed"); // 	ND_mark(n) = 0;
UNSUPPORTED("3ru7vdk2837q8r3b0bivxh13w"); // 	ND_tree_in(n).list[0] = ND_tree_out(n).list[0] = NULL;
UNSUPPORTED("8xvgu92hvqx90ewsorn0r886d"); // 	ND_tree_in(n).size = ND_tree_out(n).size = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("apdzktkdsfac4cxtlid9vh2wa"); //     for (i = 0; i < Tree_edge.size; i++)
UNSUPPORTED("5n2d8qqydtfvu8thx33qwfgcz"); // 	ED_tree_index(Tree_edge.list[i]) = -1;
UNSUPPORTED("5thgdeyb1sej760u8zem7asil"); //     Tree_node.size = Tree_edge.size = 0;
UNSUPPORTED("6k2txiyy5e6a17hrie8m2f29q"); //     for (n = agfstnode(G); n && (Tree_edge.size == 0); n = agnxtnode(G, n))
UNSUPPORTED("11sa6d1okpmi0c848pqndhwt0"); // 	treesearch(n);
UNSUPPORTED("6vpqkc1ki2ub7hdfl98pjbejn"); //     return Tree_node.size;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 30d99735rglxooiwclbg1q7iu
// static void init_cutvalues(void) 
public static Object init_cutvalues(Object... arg) {
UNSUPPORTED("687q167f1w8nkra6ebpgimxmo"); // static void init_cutvalues(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3b5uup3v49oc74lovfcfw8eq0"); //     dfs_range(agfstnode(G), NULL, 1);
UNSUPPORTED("actekdlw0xo6l1xkuxw66gnsc"); //     dfs_cutval(agfstnode(G), NULL);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 evcy6jgbaihhws8kpm2jth9a
// static void feasible_tree(void) 
public static Object feasible_tree(Object... arg) {
UNSUPPORTED("4h6p3oi6aw7psa5k558423wwo"); // static void feasible_tree(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4cj25hcu9r2olzb9dr45uj06v"); //     int i, delta;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("7aw8atjvssvezykvtwxx8uz0e"); //     if (N_nodes <= 1)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("c8t768lea8z7vf2s6ixc091u"); //     while (tight_tree() < N_nodes) {
UNSUPPORTED("7d4itmpr24svte9evqfic2yv"); // 	e = NULL;
UNSUPPORTED("100zj1fj3d3m273cb50mhb7ys"); // 	for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("3vzmm2x83chp3c1jnoea7dyjn"); // 	    for (f = agfstout(G, n); f; f = agnxtout(G, f)) {
UNSUPPORTED("9nxnz6ola53pcx70ehwbcff5q"); // 		if (((ED_tree_index(f) >= 0) == 0) && incident(f) && ((e == NULL)
UNSUPPORTED("cvqy9ag0f0e45zw5elp20ewn9"); // 							       || (((ND_rank(aghead(f)) - ND_rank(agtail(f))) - ED_minlen(f))
UNSUPPORTED("5op5aw49m8ma6cruf2w2hm3gs"); // 								   <
UNSUPPORTED("we6orer2e8ut7fb55m9o5lem"); // 								   ((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e)))))
UNSUPPORTED("a7fw9nl7m5cdkq0j9gbq32w03"); // 		    e = f;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("tfi0qfhtzy9u14io5bqldv7r"); // 	if (e) {
UNSUPPORTED("9enai3i3w1ri2ribzuk7xp3yw"); // 	    delta = ((ND_rank(aghead(e)) - ND_rank(agtail(e))) - ED_minlen(e));
UNSUPPORTED("8bm0vffy4n9ia0xhk4r6rjrv7"); // 	    if (delta) {
UNSUPPORTED("602ttigu9ipa4he0s7ynrjhl4"); // 		if (incident(e) == aghead(e))
UNSUPPORTED("d1kbuyzn7bvcbwa6pgby0fy5c"); // 		    delta = -delta;
UNSUPPORTED("dbanfur2r5sqa5sjby4y6g47c"); // 		for (i = 0; i < Tree_node.size; i++)
UNSUPPORTED("5uiug0xjwrn72qmfppwupcv20"); // 		    ND_rank(Tree_node.list[i]) += delta;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("dzj4ki4z7wnglym8xp1lbyt6s"); // 	    abort();
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ewd41f8oha0b2m95knlmt516t"); //     init_cutvalues();
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 avepjxx9hu41znazr96xipjmk
// static node_t *treeupdate(node_t * v, node_t * w, int cutvalue, int dir) 
public static Object treeupdate(Object... arg) {
UNSUPPORTED("aduqutqny5g0ztqti3wtxuwsw"); // static node_t *treeupdate(node_t * v, node_t * w, int cutvalue, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("5azgw3jpyk2yccpp3p4s3q817"); //     int d;
UNSUPPORTED("c4heiltta24fhdbnlzzv46kml"); //     while (!(((ND_low(v)) <= (ND_lim(w))) && ((ND_lim(w)) <= (ND_lim(v))))) {
UNSUPPORTED("1nriensm3nzml31jkej49i1kz"); // 	e = ND_par(v);
UNSUPPORTED("4k38nsor1i3s0v3p4a512ap1d"); // 	if (v == agtail(e))
UNSUPPORTED("7inm625at01hyictalirafzw6"); // 	    d = dir;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("84t86dtymznr9yaola28prcgj"); // 	    d = NOT(dir);
UNSUPPORTED("1ulfzf1l4wqt2h65gf88tofvj"); // 	if (d)
UNSUPPORTED("dzxfhntboux7ck49ox0z6j8rz"); // 	    ED_cutvalue(e) += cutvalue;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("75v5i5yxd3e5t5htlnoo38jij"); // 	    ED_cutvalue(e) -= cutvalue;
UNSUPPORTED("cxib4a5zem92xd790p9yr4x7d"); // 	if (ND_lim(agtail(e)) > ND_lim(aghead(e)))
UNSUPPORTED("4gg5n60ynsciy3te5bmvsjdu0"); // 	    v = agtail(e);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("39bh91n8ucstjr8vmtx3ynvcd"); // 	    v = aghead(e);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dpci52ct1zm8k1aasm170ru2j"); //     return v;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e66n8gern1fejjsn8nefypo0g
// static void rerank(node_t * v, int delta) 
public static void rerank(Agnode_s v, int delta) {
ENTERING("e66n8gern1fejjsn8nefypo0g","rerank");
try {
    int i;
    Agedge_s e;
    ND_rank(v, ND_rank(v) - delta);
    for (i = 0; (e = (Agedge_s) ND_tree_out(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, ND_par(v)))
	    rerank(aghead(e), delta);
    for (i = 0; (e = (Agedge_s) ND_tree_in(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, ND_par(v)))
	    rerank(agtail(e), delta);
} finally {
LEAVING("e66n8gern1fejjsn8nefypo0g","rerank");
}
}




//3 6s6e4m5lurixh00dwg4r75g94
// static void update(edge_t * e, edge_t * f) 
public static Object update(Object... arg) {
UNSUPPORTED("es3sfqf3mwh2bmltkwmmowg2k"); // static void update(edge_t * e, edge_t * f)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7avrf7q4cj537dtgthgxunsz2"); //     int cutvalue, delta;
UNSUPPORTED("2aupz88qsve8pghbysyxgnp42"); //     node_t *lca;
UNSUPPORTED("6395030j083m8e9thbts6bv2z"); //     delta = ((ND_rank(aghead(f)) - ND_rank(agtail(f))) - ED_minlen(f));
UNSUPPORTED("clqo5a436vkdtaz7hd207h444"); //     /* "for (v = in nodes in tail side of e) do ND_rank(v) -= delta;" */
UNSUPPORTED("4cjxm7t1y2fgelzpwqyddowxn"); //     if (delta > 0) {
UNSUPPORTED("aikubsfckv0tsg0abylliygo8"); // 	int s;
UNSUPPORTED("6z143ta067h5sg0omh19p0j1b"); // 	s = ND_tree_in(agtail(e)).size + ND_tree_out(agtail(e)).size;
UNSUPPORTED("a9nwbakco9oow3uojzndpm2g3"); // 	if (s == 1)
UNSUPPORTED("2rad5dh8xgc0717q0gl382n8r"); // 	    rerank(agtail(e), delta);
UNSUPPORTED("8k75h069sv2k9b6tgz77dscwd"); // 	else {
UNSUPPORTED("3ktb4ojo7cat0p5rtc5el2vr7"); // 	    s = ND_tree_in(aghead(e)).size + ND_tree_out(aghead(e)).size;
UNSUPPORTED("57qx3gp792smjbfc12l2tbr6y"); // 	    if (s == 1)
UNSUPPORTED("bv5knsucyzhi8ysue6orm2h4m"); // 		rerank(aghead(e), -delta);
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("8dtuhafq5ldyymsmatj7jlglx"); // 		if (ND_lim(agtail(e)) < ND_lim(aghead(e)))
UNSUPPORTED("9xup8kc2hyvfx24e0flkkmymp"); // 		    rerank(agtail(e), delta);
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("7rt04q3b1fjvfooquozcf6vvz"); // 		    rerank(aghead(e), -delta);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("36x017asldhchl2sjdvgkdt4w"); //     cutvalue = ED_cutvalue(e);
UNSUPPORTED("5dxuutx4y3ethhlq6pxsf4ojc"); //     lca = treeupdate(agtail(f), aghead(f), cutvalue, 1);
UNSUPPORTED("4gjy5ir3q2f6q4m0lg6cgsjkk"); //     if (treeupdate(aghead(f), agtail(f), cutvalue, 0) != lca)
UNSUPPORTED("53h65fwnivhy7ght7m3ql45a1"); // 	abort();
UNSUPPORTED("9ilg0tnjajn1i9j9ji3g37e12"); //     ED_cutvalue(f) = -cutvalue;
UNSUPPORTED("e4t0pcphvhc1wreqrd47tjz3m"); //     ED_cutvalue(e) = 0;
UNSUPPORTED("626rwoe83bx1hhakm58j0oxqw"); //     exchange_tree_edges(e, f);
UNSUPPORTED("8478ou035u86x8q6qg8xswwaj"); //     dfs_range(lca, ND_par(lca), ND_low(lca));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 83kbam9kqtnnmo0ndnvt9tokx
// static void scan_and_normalize(void) 
public static Object scan_and_normalize(Object... arg) {
UNSUPPORTED("a2jamvs5yafodko2iol9jytz2"); // static void scan_and_normalize(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("397xa7azo04p9pd739tikpgtd"); //     Minrank = INT_MAX;
UNSUPPORTED("6f0srjz365idac5cl53l0rumx"); //     Maxrank = -INT_MAX;
UNSUPPORTED("4i16cidbem2pp7lmgjf1lviav"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("1ddu934h7zd8r4luptanno5uz"); // 	Minrank = MIN(Minrank, ND_rank(n));
UNSUPPORTED("1dgyzkr5eoclg5fmayfnhtl7u"); // 	Maxrank = MAX(Maxrank, ND_rank(n));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1qs9gopjf1cytbyjivkw2947v"); //     if (Minrank != 0) {
UNSUPPORTED("2ex34000lxu5swdcs7gym515j"); // 	for (n = agfstnode(G); n; n = agnxtnode(G, n))
UNSUPPORTED("70gpjvl3v03vjvc0d1arj911l"); // 	    ND_rank(n) -= Minrank;
UNSUPPORTED("9q5zgng6wp9m01e0yxvrrslf3"); // 	Maxrank -= Minrank;
UNSUPPORTED("9fle32bmbxyzdg29qcyebetpz"); // 	Minrank = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8y7fuoulofbi98ratqybylahk
// static void LR_balance(void) 
public static Object LR_balance(Object... arg) {
UNSUPPORTED("dok4s1oc2p6g4n33v3mxjp0cc"); // static void LR_balance(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4cj25hcu9r2olzb9dr45uj06v"); //     int i, delta;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("ageh60gqut4bxtz6p8vnwnltx"); //     for (i = 0; i < Tree_edge.size; i++) {
UNSUPPORTED("9hlcrcsmj5r57r5c0by27qxu5"); // 	e = Tree_edge.list[i];
UNSUPPORTED("6bt4iha93rvzrhyxu4gysikyp"); // 	if (ED_cutvalue(e) == 0) {
UNSUPPORTED("3ywzcgo0u4dwz8kvjl6e31ons"); // 	    f = enter_edge(e);
UNSUPPORTED("crb5g5sdo0r56dz22c5lrudwt"); // 	    if (f == NULL)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("3ryo8kufonzwc2fzagsh3rpwd"); // 	    delta = ((ND_rank(aghead(f)) - ND_rank(agtail(f))) - ED_minlen(f));
UNSUPPORTED("azmap1zryyf1ushrz9p7qq41i"); // 	    if (delta <= 1)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("d8bnigokkm3e3ebe5iza34cmk"); // 	    if (ND_lim(agtail(e)) < ND_lim(aghead(e)))
UNSUPPORTED("99cmmjz2h12zj8os5im8rbuly"); // 		rerank(agtail(e), delta / 2);
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("8iu2u00zamjr9f6311aukwvc3"); // 		rerank(aghead(e), -delta / 2);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4i16cidbem2pp7lmgjf1lviav"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("4t1hex2v6e2u4uzc9yya14uio"); // 	free_list(ND_tree_in(n));
UNSUPPORTED("2tvmt7fbq5fmn2ehvvpzz4gw8"); // 	free_list(ND_tree_out(n));
UNSUPPORTED("1btcv7arbo4kdjfc0iu4lseed"); // 	ND_mark(n) = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8dyyxyx5c9hgtbt68s1oj38ef
// static int countable_node(node_t * n) 
public static Object countable_node(Object... arg) {
UNSUPPORTED("2fnmftyayn0agxhl2eo3wg3nq"); // static int countable_node(node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1yr5pxcdwisa6xrwe3emv4dg"); //     return NOT(0);		/* could be false for slacknodes */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 88tushyfbkjir3bap4u4aj2wh
// static void TB_balance(void) 
public static Object TB_balance(Object... arg) {
UNSUPPORTED("9ylrkrux4ja8czg37cehxrviq"); // static void TB_balance(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("ae3f48k53b7wq0r9a5jxhi9a6"); //     int i, low, high, choice, *nrank;
UNSUPPORTED("a41z0oq92n27hxzv5z4ruznqh"); //     int inweight, outweight;
UNSUPPORTED("15b32g2agcylwc4rf4c2fppax"); //     scan_and_normalize();
UNSUPPORTED("aqkiyvwq1tc3planofcjixzr9"); //     /* find nodes that are not tight and move to less populated ranks */
UNSUPPORTED("3xqtrfmwbhnhx8xp3lq2lzah6"); //     nrank = (int*)zmalloc((Maxrank + 1)*sizeof(int));
UNSUPPORTED("b05lp7vg2di3wwc91ruxlu4nh"); //     for (i = 0; i <= Maxrank; i++)
UNSUPPORTED("s5mvjkk2p1acw6v7dpp29k0s"); // 	nrank[i] = 0;
UNSUPPORTED("f3v4zebw5ue67iswvu5770pxs"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n))
UNSUPPORTED("3n248sqrk2x3o44lutlqchga8"); // 	if (countable_node(n))
UNSUPPORTED("c6rb2hannxmtq1zqsz5o9jpo2"); // 	    nrank[ND_rank(n)]++;
UNSUPPORTED("4i16cidbem2pp7lmgjf1lviav"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("7uycfgkafzpsv1n7pli0iqq25"); // 	if (!countable_node(n))
UNSUPPORTED("6hqli9m8yickz1ox1qfgtdbnd"); // 	    continue;
UNSUPPORTED("8y4c0nd0qs2s3y8b943zrmdwz"); // 	inweight = outweight = 0;
UNSUPPORTED("a6d47f09uwm7x4gox6zh6uz6j"); // 	low = 0;
UNSUPPORTED("75jgh3xpahggvrq1n34g6srb6"); // 	high = Maxrank;
UNSUPPORTED("8buy8twhjqq6n8gzqlik80uua"); // 	for (e = agfstin(G, n); e; e = agnxtin(G, e)) {
UNSUPPORTED("cf7x5asja014t2wo5eiizofw5"); // 	    inweight += ED_weight(e);
UNSUPPORTED("2gq9j8eeeoovv0h84w5ofklde"); // 	    low = MAX(low, ND_rank(agtail(e)) + ED_minlen(e));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("5lpz1wu7pqg48vv7zew67brmh"); // 	for (e = agfstout(G, n); e; e = agnxtout(G, e)) {
UNSUPPORTED("37g8y40nu12pezrslhymq4uj"); // 	    outweight += ED_weight(e);
UNSUPPORTED("9h79lyp0d4tbgdc3eh3nc59wx"); // 	    high = MIN(high, ND_rank(aghead(e)) - ED_minlen(e));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("durfyeg9kdevw0fvgr9176e1m"); // 	if (low < 0)
UNSUPPORTED("7tsgifalnpld7hr1zx4qhvqko"); // 	    low = 0;		/* vnodes can have ranks < 0 */
UNSUPPORTED("anxmw58uzg8ux1q1wqivudu4j"); // 	if (inweight == outweight) {
UNSUPPORTED("4hirw9ql1hxnp6jtk3408tlf4"); // 	    choice = low;
UNSUPPORTED("4fmk1766aj4p34irbtmnaqhwz"); // 	    for (i = low + 1; i <= high; i++)
UNSUPPORTED("4rwlbkm8u19aqvof2crj6t71e"); // 		if (nrank[i] < nrank[choice])
UNSUPPORTED("cy21ybi6srr5dfmc2cx29ik3a"); // 		    choice = i;
UNSUPPORTED("3x905c8yf2xsud9cksguze9nm"); // 	    nrank[ND_rank(n)]--;
UNSUPPORTED("9a9fwpw43xm4p8u5fq7nje4kr"); // 	    nrank[choice]++;
UNSUPPORTED("69zcxg2gohvpdeoyfa90c659q"); // 	    ND_rank(n) = choice;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("4t1hex2v6e2u4uzc9yya14uio"); // 	free_list(ND_tree_in(n));
UNSUPPORTED("2tvmt7fbq5fmn2ehvvpzz4gw8"); // 	free_list(ND_tree_out(n));
UNSUPPORTED("1btcv7arbo4kdjfc0iu4lseed"); // 	ND_mark(n) = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5o23saogg3rf1k9yqpa6ztr3"); //     free(nrank);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 bxbe6svn116d5i1con4goa4jg
// static int init_graph(graph_t * g) 
public static Object init_graph(Object... arg) {
UNSUPPORTED("duhp7qzxkgxtbkkykb58nspxz"); // static int init_graph(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8tqafzjpm5tu0o69dr64rbn59"); //     int i, feasible;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("qi47axa9j2qnoeymsifkb37n"); //     G = g;
UNSUPPORTED("766e4aw8j4np9eonp5d7rmghh"); //     N_nodes = N_edges = S_i = 0;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("1btcv7arbo4kdjfc0iu4lseed"); // 	ND_mark(n) = 0;
UNSUPPORTED("9479wjxc0efysywuogf655att"); // 	N_nodes++;
UNSUPPORTED("8gbd6b2ssf51om8neirzzr6rw"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e))
UNSUPPORTED("a4s7jvj0hu2gb0ved19q70boo"); // 	    N_edges++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("11tu6nen0s929pckrv4bn5fec"); //     Tree_node.list = ALLOC(N_nodes, Tree_node.list, node_t *);
UNSUPPORTED("6jinb0tw9mvm2ls73enhsp2v2"); //     Tree_node.size = 0;
UNSUPPORTED("86b5dtng9fi3si9vc2h0247xq"); //     Tree_edge.list = ALLOC(N_nodes, Tree_edge.list, edge_t *);
UNSUPPORTED("2rjdtdz0nw8duvaagwhvl3h3l"); //     Tree_edge.size = 0;
UNSUPPORTED("buj741pfjhhjgky7m4ba13bkj"); //     feasible = NOT(0);
UNSUPPORTED("4i16cidbem2pp7lmgjf1lviav"); //     for (n = agfstnode(G); n; n = agnxtnode(G, n)) {
UNSUPPORTED("122o94oduvs1upcvt0gaccwdm"); // 	ND_priority(n) = 0;
UNSUPPORTED("5or0zebpgtvozlmal8j2q1ymh"); // 	i = 0;
UNSUPPORTED("8buy8twhjqq6n8gzqlik80uua"); // 	for (e = agfstin(G, n); e; e = agnxtin(G, e)) {
UNSUPPORTED("1lo0ackow66iudrq1gb15y3ry"); // 	    i++;
UNSUPPORTED("70kfych1i9cct0n9y7g0v6rj3"); // 	    ND_priority(n)++;
UNSUPPORTED("6tbl74mp4pf6y2crmgoeqfgws"); // 	    ED_cutvalue(e) = 0;
UNSUPPORTED("69v0ucrpgona6ohp8ompx303w"); // 	    ED_tree_index(e) = -1;
UNSUPPORTED("9crxgqt9ovx4j123ssboqukny"); // 	    if (feasible
UNSUPPORTED("9yxulu36s0h7wu6ze39yabcbw"); // 		&& (ND_rank(aghead(e)) - ND_rank(agtail(e)) <
UNSUPPORTED("5ygj9st7c2txq8t7x0evw0gwy"); // 		    ED_minlen(e)))
UNSUPPORTED("9vt1v9ciblsgsxkuijk7jiwbj"); // 		feasible = 0;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("do971l8eujqhnbgpygq8k17dk"); // 	ND_tree_in(n).list = (edge_t **)zmalloc((i + 1)*sizeof(edge_t *));
UNSUPPORTED("m5kztgeog8fpr1s5cq430y10"); // 	ND_tree_in(n).size = 0;
UNSUPPORTED("8awrer1rklz706o03kv85w03a"); // 	for (e = agfstout(G, n); e; e = agnxtout(G, e))
UNSUPPORTED("1lo0ackow66iudrq1gb15y3ry"); // 	    i++;
UNSUPPORTED("8r3szti94sq1gxxv2o4pit142"); // 	ND_tree_out(n).list = (edge_t **)zmalloc((i + 1)*sizeof(edge_t *));
UNSUPPORTED("4ref9f9nzjcix7ws4rjlujxak"); // 	ND_tree_out(n).size = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4y8bejp6joj8888jh9k6dgbi0"); //     return feasible;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dbmq7fksxvtnowntzvgf6bvpe
// void rank2(graph_t * g, int balance, int maxiter, int searchsize) 
public static Object rank2(Object... arg) {
UNSUPPORTED("agkgtw44dwr961357ucs4aqo2"); // void rank2(graph_t * g, int balance, int maxiter, int searchsize)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5ysxfjdtauzndyqqjjxjzml0"); //     int iter = 0, feasible;
UNSUPPORTED("9c8v7b6ovi5r1avsy21hgi9bc"); //     char *s, *ns = "network simplex: ";
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("2di5wqm6caczzl6bvqe35ry8y"); //     if (Verbose)
UNSUPPORTED("aaarjibm8djv3koq2y6u4m044"); // 	start_timer();
UNSUPPORTED("c5neu9chdqik7ojltg83x5ak3"); //     feasible = init_graph(g);
UNSUPPORTED("5kghcf22tgjtofe5xd42jgp8e"); //     if (!feasible)
UNSUPPORTED("zgr0nx4idsul38omong9uzac"); // 	init_rank();
UNSUPPORTED("8yi0gb3fhwihk1nfzajqprbk4"); //     if (maxiter <= 0)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("5gcx8khh25lm0f2v6jh6zrkt5"); //     if (searchsize >= 0)
UNSUPPORTED("9j7d81drejaf0lxw7e522k7k3"); // 	Search_size = searchsize;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("71793olrbe523agb1c61pbe6q"); // 	Search_size = 30;
UNSUPPORTED("3fsnrp54nsja7h66x4my2bbx7"); //     feasible_tree();
UNSUPPORTED("a4g8hvwqtgyhd0lisw0oraois"); //     while ((e = leave_edge())) {
UNSUPPORTED("ahk62ququvrin9j4la6tdmfar"); // 	f = enter_edge(e);
UNSUPPORTED("f5hklv9l1hu0kz1b887fs83ej"); // 	update(e, f);
UNSUPPORTED("28sg7952j6768q3zme1oe11cq"); // 	iter++;
UNSUPPORTED("emzrzx0dpy47ttts0tau6bxsq"); // 	if (Verbose && (iter % 100 == 0)) {
UNSUPPORTED("283nrg8uu1ipbndmxdmhbe5z6"); // 	    if (iter % 1000 == 100)
UNSUPPORTED("a2x7006clsl33nolmm6d2yyi3"); // 		fputs(ns, stderr);
UNSUPPORTED("yfy6o9puxuiowmxilqdizkoi"); // 	    fprintf(stderr, "%d ", iter);
UNSUPPORTED("cejj4ad1neougiuhihieum6nu"); // 	    if (iter % 1000 == 0)
UNSUPPORTED("7f10li52odmw1lmncjqfoo89z"); // 		fputc('\n', stderr);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("a674em0xdxo3nbvgoc1xsq1ow"); // 	if (iter >= maxiter)
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9pn3evsvb278v3x6odr90l4i"); //     switch (balance) {
UNSUPPORTED("d0gk15gzj4wz8nv54zbr285hm"); //     case 1:
UNSUPPORTED("8m5a2j526esepi7c618ahlla5"); // 	TB_balance();
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("4u5xz2u3urj13y0aw30fdyup5"); //     case 2:
UNSUPPORTED("3sqx8ibdm8mpwk31urri2lxy3"); // 	LR_balance();
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("d0y9yjj89v8udst6qyriyje4q"); // 	scan_and_normalize();
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cve2on8gll5i0vomy8lnwhai2"); //     if (Verbose) {
UNSUPPORTED("1bwk7sc4bxms0ud3etmt8gk41"); // 	if (iter >= 100)
UNSUPPORTED("7gzifjk9agkv1gc55rpq8fl01"); // 	    fputc('\n', stderr);
UNSUPPORTED("5kt4mzysu043lhi33edw16nyn"); // 	fprintf(stderr, "%s%d nodes %d edges %d iter %.2f sec\n",
UNSUPPORTED("evgt6cvqs00qob0f4njvy7gqa"); // 		ns, N_nodes, N_edges, iter, elapsed_sec());
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 eg9t3nj2diurenf6ovgzhcctp
// static void x_cutval(edge_t * f) 
public static Object x_cutval(Object... arg) {
UNSUPPORTED("a5skc5witbi3spxa6nmnlv2he"); // static void x_cutval(edge_t * f)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("6pcmlnj2o86tpsavwmj69hiic"); //     int sum, dir;
UNSUPPORTED("33345q0n8gimxrk291b579l03"); //     /* set v to the node on the side of the edge already searched */
UNSUPPORTED("74yk99le891v0u8z88qe1k6w6"); //     if (ND_par(agtail(f)) == f) {
UNSUPPORTED("6ymygf0ohu6hnisri0q4v6slk"); // 	v = agtail(f);
UNSUPPORTED("4tu6k4gwplcalffq4tkhxmzvx"); // 	dir = 1;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("5ua5qirdr1t4wte9ku938d8ve"); // 	v = aghead(f);
UNSUPPORTED("dnf0hfgr2t10wplwdhq2opceu"); // 	dir = -1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("a6vxbyim8v2mmrdcey3t2n4r0"); //     sum = 0;
UNSUPPORTED("8z6cqsglbe5ouzg4gr8gora1"); //     for (e = agfstout(G, v); e; e = agnxtout(G, e))
UNSUPPORTED("ebn6epb81glkfyb40pu6ulxbl"); // 	sum += x_val(e, v, dir);
UNSUPPORTED("7qvsu65gitr71kzfdkr6o84ra"); //     for (e = agfstin(G, v); e; e = agnxtin(G, e))
UNSUPPORTED("ebn6epb81glkfyb40pu6ulxbl"); // 	sum += x_val(e, v, dir);
UNSUPPORTED("cw3lnghu6dwvoaepg0g647uk4"); //     ED_cutvalue(f) = sum;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 98h49fkyqccijff4nlv737pow
// static int x_val(edge_t * e, node_t * v, int dir) 
public static Object x_val(Object... arg) {
UNSUPPORTED("618nablbgn0h8jsrf2iy5k5et"); // static int x_val(edge_t * e, node_t * v, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dxz8gujppjqsa63merjuwp9ak"); //     node_t *other;
UNSUPPORTED("8pwpn30jkwvocryxep8q3l4ts"); //     int d, rv, f;
UNSUPPORTED("17s4g7ixjir1ji83726d4rkml"); //     if (agtail(e) == v)
UNSUPPORTED("ddn2u7jjuy674veth7q72p0sb"); // 	other = aghead(e);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("5a60qbv8r5b666nfetu7fbotj"); // 	other = agtail(e);
UNSUPPORTED("ap7n3sh3sfv0j8g8kh9186zob"); //     if (!((((ND_low(v)) <= (ND_lim(other))) && ((ND_lim(other)) <= (ND_lim(v)))))) {
UNSUPPORTED("660rqpxbqub2k8xmzsnggomj0"); // 	f = 1;
UNSUPPORTED("bdqlkbl66y9frp4vjbot4svtv"); // 	rv = ED_weight(e);
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("5fakoy78fn8supsw3hklar8s7"); // 	f = 0;
UNSUPPORTED("b1rds4s7gglxwgvzm67jdo5t5"); // 	if ((ED_tree_index(e) >= 0))
UNSUPPORTED("1ppn6f8tftbm1ws5hska8wfz7"); // 	    rv = ED_cutvalue(e);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("6x7u8qhr1l1yhthdztmb8zbvw"); // 	    rv = 0;
UNSUPPORTED("2of8np40ar3581prcgn8u822t"); // 	rv -= ED_weight(e);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1uau3evf4rn2r0ex2fvo6cdig"); //     if (dir > 0) {
UNSUPPORTED("209v0cum9kirek998k3eijo0h"); // 	if (aghead(e) == v)
UNSUPPORTED("c5krqo60t4kv0c6vj2yxklrir"); // 	    d = 1;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("a9n09zi0owv42txv9bsgtgnez"); // 	    d = -1;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("7ucv76dk6a6r6b54wepszch7t"); // 	if (agtail(e) == v)
UNSUPPORTED("c5krqo60t4kv0c6vj2yxklrir"); // 	    d = 1;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("a9n09zi0owv42txv9bsgtgnez"); // 	    d = -1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ipbyl3gjhd2nj0pbftgjiu3m"); //     if (f)
UNSUPPORTED("6yctz3j9yi75z889gu05s470f"); // 	d = -d;
UNSUPPORTED("8x41xs0nmhal8wgow4s7rmaeo"); //     if (d < 0)
UNSUPPORTED("t87b2ssaz8lh5oa1zawnru85"); // 	rv = -rv;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ah65iqmwa5j0qwotm6amhijlg
// static void dfs_cutval(node_t * v, edge_t * par) 
public static void dfs_cutval(Agnode_s v, Agedge_s par) {
ENTERING("ah65iqmwa5j0qwotm6amhijlg","dfs_cutval");
try {
    int i;
    Agedge_s e;
    for (i = 0; (e = (Agedge_s) ND_tree_out(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, par))
	    dfs_cutval(aghead(e), e);
    for (i = 0; (e = (Agedge_s) ND_tree_in(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, par))
	    dfs_cutval(agtail(e), e);
    if (par!=null)
	x_cutval(par);
} finally {
LEAVING("ah65iqmwa5j0qwotm6amhijlg","dfs_cutval");
}
}




//3 cgqr48qol9p8bsqjnryo5z5x9
// static int dfs_range(node_t * v, edge_t * par, int low) 
public static int dfs_range(Agnode_s v, Agedge_s par, int low) {
ENTERING("cgqr48qol9p8bsqjnryo5z5x9","dfs_range");
try {
    Agedge_s e;
    int i, lim;
    lim = low;
    ND_par(v, par);
    ND_low(v, low);
    for (i = 0; (e = (Agedge_s) ND_tree_out(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, par))
	    lim = dfs_range(aghead(e), e, lim);
    for (i = 0; (e = (Agedge_s) ND_tree_in(v).getArray("list").plus(i).getPtr())!=null; i++)
	if (NEQ(e, par))
	    lim = dfs_range(agtail(e), e, lim);
    ND_lim(v, lim);
    return lim + 1;
} finally {
LEAVING("cgqr48qol9p8bsqjnryo5z5x9","dfs_range");
}
}


}
