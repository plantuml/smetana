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

public class level__c {
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




//3 1vibj3ycvfkl07m1a2dzr3qf3
// static void my_init_node(Agraph_t *g, Agobj_t *node, void *arg) 
public static Object my_init_node(Object... arg) {
UNSUPPORTED("448m4h3oktm1kylrq3iss782r"); // static void my_init_node(Agraph_t *g, Agobj_t *node, void *arg)
UNSUPPORTED("3mooa3mwczxhc97acdygow0sx"); // { int *sz = arg; agbindrec(node,"level node rec",sz[1],NOT(0)); }

throw new UnsupportedOperationException();
}




//3 avor9syqevkn2jo4yf8whbg5f
// static void my_init_edge(Agraph_t *g, Agobj_t *edge, void *arg) 
public static Object my_init_edge(Object... arg) {
UNSUPPORTED("bo6poh3fcfvu02sod3dyzjhsi"); // static void my_init_edge(Agraph_t *g, Agobj_t *edge, void *arg)
UNSUPPORTED("4f0jw3wys20zimucjor8qrhzg"); // { int *sz = arg; agbindrec(edge,"level edge rec",sz[2],NOT(0)); }

throw new UnsupportedOperationException();
}




//3 2xyhunzw903dytfpyy63oznhz
// static void my_init_graph(Agraph_t *g, Agobj_t *graph, void *arg) 
public static Object my_init_graph(Object... arg) {
UNSUPPORTED("3s5gmr0i7qaf8sa79h9ek2t42"); // static void my_init_graph(Agraph_t *g, Agobj_t *graph, void *arg)
UNSUPPORTED("12ubgsqsc8d2oeobshclx2e9m"); // { int *sz = arg; agbindrec(graph,"level graph rec",sz[0],NOT(0)); }

throw new UnsupportedOperationException();
}


//1 46nx7przjp7fn42o28hqdaj9k
// static Agcbdisc_t mydisc = 




//3 6vs6iurtzffi3xa9qm7odrb44
// static void agautoinit(Agraph_t *g, int graphinfo_size, int nodeinfo_size, int edgeinfo_size)  
public static Object agautoinit(Object... arg) {
UNSUPPORTED("51wn1rb3whzl0edwixcgx1cf0"); // static void agautoinit(Agraph_t *g, int graphinfo_size, int nodeinfo_size, int edgeinfo_size) 
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("d8kadupotcrkzo92ueisp1bpx"); //     int *s;
UNSUPPORTED("ct57ikvjkevjeq7df8ioamwuz"); //     s = (int*)zmalloc((3)*sizeof(int));	/* until we fix something, this is a storage leak */
UNSUPPORTED("c2drnkuuycmfsnwa4si2om9qx"); //     s[0] = graphinfo_size; s[1] = nodeinfo_size; s[2] = edgeinfo_size;
UNSUPPORTED("3ltvv5whmzzt7gkbwvqbjg8fd"); //     agpushdisc(g,&mydisc,s);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e0ury24cjiz44ln6g2wfdtbao
// void dot2_levels(graph_t * g) 
public static Object dot2_levels(Object... arg) {
UNSUPPORTED("1yucr5m5zc8y08ygpti0gaipl"); // void dot2_levels(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("23k65agnd27tv4ix9teds9e2t"); //     int ssize;
UNSUPPORTED("yiuh599p05f2mpu2e3pesu2o"); //     char* s;
UNSUPPORTED("4ryqkbnf6h0rvvm8f1lif88bl"); //     graph_t *Xg =
UNSUPPORTED("3xr9wej8gc14pi7iezb06kdv7"); // 	agopen("level assignment constraints", Agstrictdirected, 0);
UNSUPPORTED("2zwbknhq0b3j38z14p42btbd"); //     agautoinit(Xg, sizeof(Agraphinfo_t), sizeof(Agnodeinfo_t),
UNSUPPORTED("3movq06ocerlfv5o3seg9pyl8"); // 	       sizeof(Agedgeinfo_t));
UNSUPPORTED("62k95fm4s1z2wzcyg28ir0x7u"); //     compile_samerank(g, 0);
UNSUPPORTED("bh9imh5owlj1c9ad7mime392x"); //     compile_nodes(g, Xg);
UNSUPPORTED("3kxtahvovojtzi6qqnrricpoo"); //     compile_edges(g, Xg);
UNSUPPORTED("1elfg7artrzlezm28bf1it25s"); //     compile_clusters(g, Xg);
UNSUPPORTED("cwrov5g30logh4g9omvkblonh"); //     break_cycles(Xg);
UNSUPPORTED("7jewclkbfv8h5j1j2foh1gnhh"); //     connect_components(Xg);
UNSUPPORTED("c05s2r77mlprbdvekzb7ckg7g"); //     if ((s = agget(g,"searchsize")))
UNSUPPORTED("9kvht9axpyx5u6vr579mpx73j"); // 	ssize = atoi (s);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("2n4z8w1w3il45lik0kraspkud"); // 	ssize = -1;
UNSUPPORTED("d2q7xjv2eypjtvmld15jyopg9"); //     rank2(Xg, 1, INT_MAX, ssize);
UNSUPPORTED("3dfe8grq1efhcgva7l5lfs82p"); //     readout_levels(g, Xg);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 b5014ym99w77sdmhm79bpbpdf
// static int is_empty(graph_t * g) 
public static Object is_empty(Object... arg) {
UNSUPPORTED("1bkrdpgwmb75nr2g9ooqfc79r"); // static int is_empty(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c6tcifmdzedj8t6pzqhdxb304"); //     return (agfstnode(g) == ((Agnode_t*)0));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8y67tkpj02vatspds9shpmdfs
// static int is_a_strong_cluster(graph_t * g) 
public static Object is_a_strong_cluster(Object... arg) {
UNSUPPORTED("251zndmdq92kg3zmfr3akrrmn"); // static int is_a_strong_cluster(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9l9qe4o3ak62d2r6cbq90e5g"); //     char *str = agget(g, "compact");
UNSUPPORTED("3zw55dph964orp9odai44knm5"); //     return mapBool((str), NOT(0));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 954bo7mrh993f96ujb8u3e8vt
// static int rankset_kind(graph_t * g) 
public static Object rankset_kind(Object... arg) {
UNSUPPORTED("5vyg261oak77cq7e9dmvw2omc"); // static int rankset_kind(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("70l71erfhd26e1u7dnnxpa6i"); //     char *str = agget(g, "rank");
UNSUPPORTED("4ml2m315k80oi1eww739kxwgi"); //     if (str && str[0]) {
UNSUPPORTED("7j0qc9ibr6niawo611kvm2swb"); // 	if (!strcmp(str, "min"))
UNSUPPORTED("avnuwo0ld6vqw4bdve4ku0kwr"); // 	    return 2;
UNSUPPORTED("8q0yyecb20k2nm2qnluagpkcv"); // 	if (!strcmp(str, "source"))
UNSUPPORTED("1xt8eg4imiwilo2bv2i5shg7g"); // 	    return 3;
UNSUPPORTED("7dkmgopul9nxw7arr5odhh641"); // 	if (!strcmp(str, "max"))
UNSUPPORTED("ajqfmduyeyu16131ii3itnjx7"); // 	    return 4;
UNSUPPORTED("4f7keu82iifj10rf0thee5c4s"); // 	if (!strcmp(str, "sink"))
UNSUPPORTED("f45x5jzpirzixrsp3utlgrddo"); // 	    return 5;
UNSUPPORTED("kjtw0fdz1jophwulunsrgzdb"); // 	if (!strcmp(str, "same"))
UNSUPPORTED("btmwubugs9vkexo4yb7a5nqel"); // 	    return 1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ds4c38px5ikyzcv8pbtfcfg8h"); //     return 6;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ev9lrmt9zktnrc1s4bev051r
// int is_nonconstraint(edge_t * e) 
public static Object is_nonconstraint(Object... arg) {
UNSUPPORTED("13uo38uj8jm003m6gpkj7kq6q"); // int is_nonconstraint(edge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5bdi9u1cut03m2rbxpkmjg38w"); //     char *constr;
UNSUPPORTED("ipmkcv3n8rnco04rgte3qrlh"); //     if (E_constr && (constr = agxget(e, E_constr))) {
UNSUPPORTED("cnlkffmn4nysfcmoyktn3wvrx"); // 	if (constr[0] && mapbool(constr) == 0)
UNSUPPORTED("9qhn9m3123s8n6wwxjfo8awlm"); // 	    return NOT(0);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8pb7znv8q3ikfulus8sprsrb8
// static node_t *find(node_t * n) 
public static Object find(Object... arg) {
UNSUPPORTED("420nqb6oiuhh8qfg7ick8eb5j"); // static node_t *find(node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dxloerh79kcplsvqy37g3kwx1"); //     node_t *set;
UNSUPPORTED("ch7ucg4bhoyhb0yswbbtjy53"); //     if ((set = ND_set(n))) {
UNSUPPORTED("e20g6f3inc2t1acfqffb0ksqe"); // 	if (set != n)
UNSUPPORTED("3lalmwvgf54uou021ltj0hfqg"); // 	    set = ND_set(n) = find(set);
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("45wb5d7uba8g13ojkskeug5v2"); // 	set = ND_set(n) = n;
UNSUPPORTED("d5jffopzvq1b1jnhb3jadtkkb"); //     return set;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 tgndl91vjf2dvnepj15uye32
// static node_t *union_one(node_t * leader, node_t * n) 
public static Object union_one(Object... arg) {
UNSUPPORTED("bk1ys5rvc0fqcssw437mw03pk"); // static node_t *union_one(node_t * leader, node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("vkwoakpy0gnbvzgy8gprpluu"); //     if (n)
UNSUPPORTED("879p5fay2s7f829lo6qaxs62y"); // 	return (ND_set(find(n)) = find(leader));
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("o1psslvh23yuu288xx1nzbv6"); // 	return leader;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1ku7zqljp4yk6j8pqxa19ko4u
// static node_t *union_all(graph_t * g) 
public static Object union_all(Object... arg) {
UNSUPPORTED("1bddf3dbho07f9di3ae5tdn2z"); // static node_t *union_all(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("d5wzfazsul6ns71kurzu097zq"); //     node_t *n, *leader;
UNSUPPORTED("42x5vqk9aw9a2ld3duvpmp7u9"); //     n = agfstnode(g);
UNSUPPORTED("b23lxt0h34yyivnau77kavofl"); //     if (!n)
UNSUPPORTED("bp96fem54xcxrw16cmnlpell9"); // 	return n;
UNSUPPORTED("c7r16vtue9uiodzk7n9ybdegz"); //     leader = find(n);
UNSUPPORTED("1azt0yldbuvzvyhftheine5bv"); //     while ((n = agnxtnode(g, n)))
UNSUPPORTED("aygpegbyw6isjunzjiq2efa8e"); // 	union_one(leader, n);
UNSUPPORTED("d2vvjehoyl5rcjodzjl8q0xne"); //     return leader;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cxr0datctpvy9mz2096nfmsqx
// static void compile_samerank(graph_t * ug, graph_t * parent_clust) 
public static Object compile_samerank(Object... arg) {
UNSUPPORTED("52xc1gml0ynibrpu4r03l9cs"); // static void compile_samerank(graph_t * ug, graph_t * parent_clust)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5prtalowcftfpc3phfgtdwxe1"); //     graph_t *s;			/* subgraph being scanned */
UNSUPPORTED("6rya07j39ddlbnek0cawgbdxq"); //     graph_t *clust;		/* cluster that contains the rankset */
UNSUPPORTED("d5wzfazsul6ns71kurzu097zq"); //     node_t *n, *leader;
UNSUPPORTED("116sd790xqr0sm9prs44dhdi9"); //     if (is_a_cluster(ug)) {
UNSUPPORTED("anfjvlosf3592vmzm64wp9ukv"); // 	clust = ug;
UNSUPPORTED("e3os5dnq00bkmoe2wnci3taeg"); // 	GD_parent(ug) = parent_clust;
UNSUPPORTED("5gpikqxnmfxjq1a98gk8aybmr"); // 	if (parent_clust)
UNSUPPORTED("2cme4svj15jnccy2a5my2k0vk"); // 	    GD_level(ug) = GD_level(parent_clust) + 1;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("1f3tsi2calw640ylv89zufnqg"); // 	    GD_level(ug) = 0;
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("f2eqknbcu7dkt0mk3aa0nseps"); // 	clust = parent_clust;
UNSUPPORTED("3j62rndf411nak99bxbvwogwg"); //     if (is_empty(ug))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("2jowbcd45wf29ysq00oxpb9qh"); //     /* process subgraphs of this subgraph */
UNSUPPORTED("cpub3vrdy1soy50cezvowuqp8"); //     for (s = agfstsubg(ug); s; s = agnxtsubg(s))
UNSUPPORTED("6y2vizzx42iva8zf3ndgfxuoo"); // 	compile_samerank(s, clust);
UNSUPPORTED("4st45szka4kxyf5afpt9r2lr7"); //     /* process this subgraph as a cluster */
UNSUPPORTED("116sd790xqr0sm9prs44dhdi9"); //     if (is_a_cluster(ug)) {
UNSUPPORTED("4pm26v2jo8qeolmy8246h5zal"); // 	for (n = agfstnode(ug); n; n = agnxtnode(ug, n)) {
UNSUPPORTED("6y62tg9q6d80lgpschpamyaqc"); // 	    if (ND_clust(n) == ((Agraph_t*)0))
UNSUPPORTED("9ov8qga72kqj7lnxefrlneehb"); // 		ND_clust(n) = ug;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("b6vj39735t21yl5ayiouei3ea"); //     /* process this subgraph as a rankset */
UNSUPPORTED("bt28cwea3vaqopki07c2rians"); //     switch (rankset_kind(ug)) {
UNSUPPORTED("33l7a58zp8vj6fuliwdkk2nkn"); //     case 3:
UNSUPPORTED("btl4oqew40wl0bqc9bhe1qshq"); // 	GD_has_sourcerank(clust) = NOT(0);	/* fall through */
UNSUPPORTED("4u5xz2u3urj13y0aw30fdyup5"); //     case 2:
UNSUPPORTED("9shvnosp4rfl2zcu1mk8mt6k"); // 	leader = union_all(ug);
UNSUPPORTED("6o42rb3i5w3jv1861oa077ahy"); // 	GD_minrep(clust) = union_one(leader, GD_minrep(clust));
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("94bjfk0blg9ugkinwopclju8t"); //     case 5:
UNSUPPORTED("b9tzw03kknh7ged56o6llxdh0"); // 	GD_has_sinkrank(clust) = NOT(0);	/* fall through */
UNSUPPORTED("7gwyze795m9aa2915n3bou49x"); //     case 4:
UNSUPPORTED("9shvnosp4rfl2zcu1mk8mt6k"); // 	leader = union_all(ug);
UNSUPPORTED("dumvmo0mkc9khfmooiadflzuz"); // 	GD_maxrep(clust) = union_one(leader, GD_maxrep(clust));
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("d0gk15gzj4wz8nv54zbr285hm"); //     case 1:
UNSUPPORTED("9shvnosp4rfl2zcu1mk8mt6k"); // 	leader = union_all(ug);
UNSUPPORTED("aukepn75qomcnwetlwyvziwx1"); // 	/* do we need to record these ranksets? */
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("4ak4rwp0nsvc9n89y3dnvoiy9"); //     case 6:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("b7b3qf9gm8yinsl7rq2tcvamg"); //     default:			/* unrecognized - warn and do nothing */
UNSUPPORTED("6yktbx4ypfvda8l9uy130ppis"); // 	agerr (AGWARN, "%s has unrecognized rank=%s", agnameof(ug), agget(ug, "rank"));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8z2hxrvowojvpioiz41x8djhw"); //     /* a cluster may become degenerate */
UNSUPPORTED("bg6be1cr97nd4blhxwc8577cz"); //     if (is_a_cluster(ug) && GD_minrep(ug)) {
UNSUPPORTED("7z1ki4lb1ja4hai3qi68hlg72"); // 	if (GD_minrep(ug) == GD_maxrep(ug)) {
UNSUPPORTED("79m66lr00dwnjnavfaimdsw3d"); // 	    GD_minrep(ug) = GD_maxrep(ug) = union_all(ug);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6mzsthkzz214du9ljfc7ijlf3
// static graph_t *dot_lca(graph_t * c0, graph_t * c1) 
public static Object dot_lca(Object... arg) {
UNSUPPORTED("egnw42d8jhfdyl5zqlzqffv17"); // static graph_t *dot_lca(graph_t * c0, graph_t * c1)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8qmvk29gersospxrjeukh5zdn"); //     while (c0 != c1) {
UNSUPPORTED("9395225iwl078vpfdl5fz3q1i"); // 	if (GD_level(c0) >= GD_level(c1))
UNSUPPORTED("ud0xxtx626m6p44f5ybl28oz"); // 	    c0 = GD_parent(c0);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("1z7wsarh0nlwq4y04yizw1pbj"); // 	    c1 = GD_parent(c1);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("aqd6v9mqxnbx6er4fkhkmhusr"); //     return c0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3bdlv7l2yeyu6vct0r3puzmxi
// static int is_internal_to_cluster(edge_t * e) 
public static Object is_internal_to_cluster(Object... arg) {
UNSUPPORTED("esoedecj682cdsbz3i9026zfo"); // static int is_internal_to_cluster(edge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bf7f1i4wj7cvj82os2h0somln"); //     graph_t *par, *ct, *ch;
UNSUPPORTED("pzh3wmhacvb8baamh8d0x2j5"); //     ct = ND_clust(agtail(e));
UNSUPPORTED("1yxzewahgac4khyfwgegotstb"); //     ch = ND_clust(aghead(e));
UNSUPPORTED("c0hxl5pgz9bgngw9cw54a6y8z"); //     if (ct == ch)
UNSUPPORTED("bp2y18pqq5n09006utwifdyxo"); // 	return NOT(0);
UNSUPPORTED("b4gos5u06phmhqll71bg7znsl"); //     par = dot_lca(ct, ch);
UNSUPPORTED("cw2sxben1dcxhu05ngvxv5lwh"); //     if (par == agroot(par))
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("1vb9z2lsj8ote2lis1nzqfq98"); //     if ((par == ct) || (par == ch))
UNSUPPORTED("bp2y18pqq5n09006utwifdyxo"); // 	return NOT(0);
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5uos5hux9aiao164ho78sbq85
// static void compile_nodes(graph_t * g, graph_t * Xg) 
public static Object compile_nodes(Object... arg) {
UNSUPPORTED("12jh8m3jnppgzqcx642zkv20x"); // static void compile_nodes(graph_t * g, graph_t * Xg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dm6k18yfspisvs0pl8f3kp9j4"); //     /* build variables */
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("2f2poxq5fr9k7bgerylsq6dkm"); // 	if (find(n) == n)
UNSUPPORTED("56hjo64b7nwhutkvzqmdzmb18"); // 	    ND_rep(n) = agnode(Xg, agnameof(n), NOT(0));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("9ksbzul9m87bznr0is2zgjvk9"); // 	if (ND_rep(n) == ((Agnode_t*)0))
UNSUPPORTED("2u4sgiv3zkgh3t4r1ksk76oyl"); // 	    ND_rep(n) = ND_rep(find(n));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e1guv5kmb9i30k71e66mdxo3y
// static void merge(edge_t * e, int minlen, int weight) 
public static Object merge(Object... arg) {
UNSUPPORTED("1npguevtdh47xfz698yahzrqb"); // static void merge(edge_t * e, int minlen, int weight)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("acr0hvlhebqp3iieup5bti0r6"); //     ED_minlen(e) = MAX(ED_minlen(e), minlen);
UNSUPPORTED("eq9oxzgg08304c8ph77144cpu"); //     ED_weight(e) += weight;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4x9dtbimzlbzgyvgl2dow75cb
// static void strong(graph_t * g, node_t * t, node_t * h, edge_t * orig) 
public static Object strong(Object... arg) {
UNSUPPORTED("6vzggze9zva4h232s9hd64r27"); // static void strong(graph_t * g, node_t * t, node_t * h, edge_t * orig)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("bqayp53mx8tl3a9owcil2sfpy"); //     if ((e = (agedge(g,t,h,NULL,0))) ||
UNSUPPORTED("djj5d4rliqlzeukm97s373tg3"); // 	(e = (agedge(g,h,t,NULL,0))) ||
UNSUPPORTED("612mdjrvkwq2yupn33bp2r3ps"); // 	(e = agedge(g, t, h, (char *) 0, NOT(0))))
UNSUPPORTED("9otcshlag9drzks2p4q4bz1z8"); // 	merge(e, ED_minlen(orig), ED_weight(orig));
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("53h65fwnivhy7ght7m3ql45a1"); // 	abort();
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1itenbrmundgdpm7tmyqa985b
// static void weak(graph_t * g, node_t * t, node_t * h, edge_t * orig) 
public static Object weak(Object... arg) {
UNSUPPORTED("e0f6tf4pkq822l7f10u2xromd"); // static void weak(graph_t * g, node_t * t, node_t * h, edge_t * orig)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("5n9mmbpgpmin1li1s5wxfn0j7"); //     for (e = agfstin(g, t); e; e = agnxtin(g, e)) {
UNSUPPORTED("blrs1fuvxzbs20bdqz7btw4yt"); // 	/* merge with existing weak edge (e,f) */
UNSUPPORTED("cccrsacwb6lshsxm8g9vpqdvo"); // 	v = agtail(e);
UNSUPPORTED("657evjbfij6x36pli6d9g15lg"); // 	if ((f = agfstout(g, v)) && (aghead(f) == h)) {
UNSUPPORTED("6cprbghvenu9ldc0ez1ifc63q"); // 	    return;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("dhdmfarapbytpy4h24lgqslbi"); //     if (!e) {
UNSUPPORTED("3k33awp8ppvryac8kmhdh8tnf"); // 	v = agnode(g, 0, NOT(0));
UNSUPPORTED("f3wi7203o3u6jhkrb72zwht4r"); // 	e = agedge(g, v, t, (char *) 0, NOT(0));
UNSUPPORTED("827rl4ok650v60qbditrz49ad"); // 	f = agedge(g, v, h, (char *) 0, NOT(0));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7nn4pn4dj4nuo71wfp1byijpx"); //     ED_minlen(e) = MAX(ED_minlen(e), 0);	/* effectively a nop */
UNSUPPORTED("drqgauf89xr1mpyydaxqfg694"); //     ED_weight(e) += ED_weight(orig) * 1000;
UNSUPPORTED("halhvp8h6olsu4tb4b5zb8ys"); //     ED_minlen(f) = MAX(ED_minlen(f), ED_minlen(orig));
UNSUPPORTED("dyyu1myirsx00xvfvqq97f6dt"); //     ED_weight(f) += ED_weight(orig);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 68dc7hsp2siu9in566grx5h8l
// static void compile_edges(graph_t * ug, graph_t * Xg) 
public static Object compile_edges(Object... arg) {
UNSUPPORTED("57s72j3dqfa0fdsi9zu6yqbxe"); // static void compile_edges(graph_t * ug, graph_t * Xg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("1dgz401xgus10wp90qpgfmm84"); //     node_t *Xt, *Xh;
UNSUPPORTED("c37x0xox8y9eba9wy6d00j14i"); //     graph_t *tc, *hc;
UNSUPPORTED("lp2eyq9typ14npscbcmds97c"); //     /* build edge constraints */
UNSUPPORTED("1rgbf8esuu21jsnjy0ozcv2nx"); //     for (n = agfstnode(ug); n; n = agnxtnode(ug, n)) {
UNSUPPORTED("36jgu4l53q07scrzxtbzu9ws1"); // 	Xt = ND_rep(n);
UNSUPPORTED("1huyj2j0jo6l60j1121l0cenn"); // 	for (e = agfstout(ug, n); e; e = agnxtout(ug, e)) {
UNSUPPORTED("eihgt2jen0ohii72jzayossof"); // 	    if (is_nonconstraint(e))
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("21s68hvg9tcok9mc1yj0cxyo8"); // 	    Xh = ND_rep(find(aghead(e)));
UNSUPPORTED("5c9s9jmoqhby2u29zb0g9neqn"); // 	    if (Xt == Xh)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("enlmoet02jwyseh462fspj7kr"); // 	    tc = ND_clust(agtail(e));
UNSUPPORTED("47ba8c5wv42664v4uk20dcxui"); // 	    hc = ND_clust(aghead(e));
UNSUPPORTED("7o1ut6pe3ws38101s6x9jv08k"); // 	    if (is_internal_to_cluster(e)) {
UNSUPPORTED("61gy4yt9v1l4586kvpqtacmur"); // 		/* determine if graph requires reversed edge */
UNSUPPORTED("cuivzwkiwyl1njm43k0v3zig3"); // 		if ((find(agtail(e)) == GD_maxrep(ND_clust(agtail(e))))
UNSUPPORTED("5nmidqd7say2tmgt62neidnjj"); // 		    || (find(aghead(e)) ==
UNSUPPORTED("b85lcgo8ipbqdfmbdz841a22l"); // 			GD_minrep(ND_clust(aghead(e))))) {
UNSUPPORTED("4mdqa1pib7sml5socnk5zj1jn"); // 		    node_t *temp = Xt;
UNSUPPORTED("edto6lxzuam8lv9gvigp2bnnh"); // 		    Xt = Xh;
UNSUPPORTED("edahfvolx6t8a93b1jzop0prz"); // 		    Xh = temp;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("eap1t3wskyfghhrwqv5fzgiye"); // 		strong(Xg, Xt, Xh, e);
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("73tu1coi87ooqzro2vtdezlut"); // 		if (is_a_strong_cluster(tc) || is_a_strong_cluster(hc))
UNSUPPORTED("1qlyasf525g29jx5adouyjjaf"); // 		    weak(Xg, Xt, Xh, e);
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("dtnnxvw72r9ajw35rh6sh0twe"); // 		    strong(Xg, Xt, Xh, e);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4u7jl0ewckucaryzty41cqk94
// static char *synthname(Agraph_t * g, char *prefix, char *suffix) 
public static Object synthname(Object... arg) {
UNSUPPORTED("4jbs66hq5nnvxedjyjr5z7nr0"); // static char *synthname(Agraph_t * g, char *prefix, char *suffix)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1v66zs5a6lqzacgqugw65twq1"); //     char *rv = agalloc(g, strlen(prefix) + strlen(suffix) + 1);
UNSUPPORTED("2gbh3lxrh3z569liv0y2yscj7"); //     strcpy(rv, prefix);
UNSUPPORTED("a9s6isyg8mn8qf2zznzrhor33"); //     strcat(rv, suffix);
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cr2e1b30ciw70zkqbnd6t2ikq
// static void compile_clusters(graph_t * g, graph_t * Xg) 
public static Object compile_clusters(Object... arg) {
UNSUPPORTED("c6ord0c0p6c1g603zufnqa0n3"); // static void compile_clusters(graph_t * g, graph_t * Xg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("42nflyhfol0ww79jkvzexv7ol"); //     node_t *rep, *top = 0, *bot = 0;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("evmjaaqcnbnbnogx8aaw70ura"); //     graph_t *sub;
UNSUPPORTED("9bdjczxfn1sj6oauckk3ygx5i"); //     char *sname;
UNSUPPORTED("73bera1w406yjis65313aefau"); //     if (is_a_cluster(g) && is_a_strong_cluster(g)) {
UNSUPPORTED("attp4bsjqe99xnhi7lr7pszar"); // 	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("7vj2i3je2o5mpeagtf2l7lp8g"); // 	    if (agfstin(g, n) == ((Agedge_t*)0)) {
UNSUPPORTED("eqsuud7jsawkoiswwrrru1r3a"); // 		rep = ND_rep(find(n));
UNSUPPORTED("12013ieq5k718eyn0dqaqyewm"); // 		if (!top) {
UNSUPPORTED("73zc4tsneu332wpn5fh60048"); // 		    sname = synthname(g, agnameof(g), "_top\177");
UNSUPPORTED("7tb3f2gzobvqg6el55jw833cx"); // 		    top = agnode(Xg, sname, NOT(0));
UNSUPPORTED("a3uh3d4xjn7lukfavpc7erxin"); // 		    agedge(Xg, top, rep, (char *) 0, NOT(0));
UNSUPPORTED("3wlc05wjji5x8d9nod8k8zjww"); // 		    agfree(g, sname);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("ds4f62v4tx926ngcgrfp3nyym"); // 	    if (agfstout(g, n) == ((Agedge_t*)0)) {
UNSUPPORTED("eqsuud7jsawkoiswwrrru1r3a"); // 		rep = ND_rep(find(n));
UNSUPPORTED("766vjt53p2dwjrqhnzvx1yadj"); // 		if (!bot) {
UNSUPPORTED("b4ra44msvta4evtl20rveh6io"); // 		    sname = synthname(g, agnameof(g), "_bottom\177");
UNSUPPORTED("ak0bztpxcl6citohdokgxfzj1"); // 		    bot = agnode(Xg, sname, NOT(0));
UNSUPPORTED("byhctf4cxk677og15lco570fd"); // 		    agedge(Xg, rep, bot, (char *) 0, NOT(0));
UNSUPPORTED("3wlc05wjji5x8d9nod8k8zjww"); // 		    agfree(g, sname);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("6qtb53kac7myad1p5cy3wf89i"); // 	if (top && bot) {
UNSUPPORTED("cnx0yx30yx571f3phu6zdzfyu"); // 	    e = agedge(Xg, top, bot, (char *) 0, NOT(0));
UNSUPPORTED("5s7xl2rvkq0dxxapwrubcmv9p"); // 	    merge(e, 0, 1000);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bkafc0cyfhu7g619r30g2vtmg"); //     for (sub = agfstsubg(g); sub; sub = agnxtsubg(sub))
UNSUPPORTED("10avanmuzxaftpdt2cfiyt583"); // 	compile_clusters(sub, Xg);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 33e4q0mzt3q0esjqyin7oo9t7
// static void reverse_edge(graph_t * g, edge_t * e) 
public static Object reverse_edge(Object... arg) {
UNSUPPORTED("51o6dgtg3y39tz6git5ff8ljl"); // static void reverse_edge(graph_t * g, edge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("32j70piql6r327tbseq7o0k28"); //     edge_t *rev;
UNSUPPORTED("ankp6nch7e9a18lqb2heot7yf"); //     rev = (agedge(g,aghead(e),agtail(e),NULL,0));
UNSUPPORTED("8c5hijvd5kr4lynpc8zoa0b9l"); //     if (!rev)
UNSUPPORTED("6b0y1u52wpr2gpf4g82ot17dt"); // 	rev = agedge(g, aghead(e), agtail(e), (char *) 0, NOT(0));
UNSUPPORTED("a37ttwpda0n66ej1agvpbx9u"); //     merge(rev, ED_minlen(e), ED_weight(e));
UNSUPPORTED("ae7ymr0zymf63zpp3vzny1kw5"); //     agdelete(g, e);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 228wzcq3wzak4w946yygf3wjo
// static void dfs(graph_t * g, node_t * v) 
public static Object dfs(Object... arg) {
UNSUPPORTED("e728nuv7n4wyffryp1y6ny8no"); // static void dfs(graph_t * g, node_t * v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("9cx417bj13sr8qn5zfj0zllwm"); //     node_t *w;
UNSUPPORTED("701du899u3x4bjilnoar3a2me"); //     if (ND_mark(v))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("3dxrqgsmycugkp3qprexbuawx"); //     ND_mark(v) = NOT(0);
UNSUPPORTED("9z9a3g70rwq874kmknu0re0w0"); //     ND_onstack(v) = NOT(0);
UNSUPPORTED("3twcq4i177ymcmm9hj6l996fr"); //     for (e = agfstout(g, v); e; e = f) {
UNSUPPORTED("9oaziib9dhmc3xyk6ku5rco5a"); // 	f = agnxtout(g, e);
UNSUPPORTED("bqi3fu38n0i7mblfl3ycwdjuo"); // 	w = aghead(e);
UNSUPPORTED("1pq8rawujka41xkc0ujz0c4jl"); // 	if (ND_onstack(w))
UNSUPPORTED("c38iac4eb7qsduew0cggbbgak"); // 	    reverse_edge(g, e);
UNSUPPORTED("8k75h069sv2k9b6tgz77dscwd"); // 	else {
UNSUPPORTED("1w7s47988wvu89n176ee6lnii"); // 	    if (ND_mark(w) == 0)
UNSUPPORTED("d5xmvav6dfdviu7ikabr84w6g"); // 		dfs(g, w);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8o0qmsv6vkvey8j3nrtn0z3nd"); //     ND_onstack(v) = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dt90swbhv55qox6i9anmtxctb
// static void break_cycles(graph_t * g) 
public static Object break_cycles(Object... arg) {
UNSUPPORTED("d7jjxsr59cimfe921b021ndni"); // static void break_cycles(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("16hw9gw0dz2w7mrtba0eoqrdi"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("3hbdxz1mh0xcb0h1e1gea41u4"); // 	ND_mark(n) = ND_onstack(n) = 0;
UNSUPPORTED("16hw9gw0dz2w7mrtba0eoqrdi"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("15bqemmbeo0l42s4hi394weuz"); // 	dfs(g, n);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c5p20vj6m7fjb0ugmey9iztbl
// static void readout_levels(graph_t * g, graph_t * Xg) 
public static Object readout_levels(Object... arg) {
UNSUPPORTED("22xmha9gejmgpvlj5ubknth6k"); // static void readout_levels(graph_t * g, graph_t * Xg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("3aslnrkwm6nrdyktawvcwd2er"); // 	ND_rank(n) = ND_rank(ND_rep(find(n)));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3a0t04wvp72r6fye31wyxappc
// static void dfscc(graph_t * g, node_t * n, int cc) 
public static Object dfscc(Object... arg) {
UNSUPPORTED("9rlus4sokq2q7mrelfhcyeq9t"); // static void dfscc(graph_t * g, node_t * n, int cc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("6o22q2n3p1os6swaor77akw8d"); //     if (ND_mark(n) == 0) {
UNSUPPORTED("772szh1cqc5omrb1knzkrkxex"); // 	ND_mark(n) = cc;
UNSUPPORTED("8gbd6b2ssf51om8neirzzr6rw"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e))
UNSUPPORTED("1petrc5reriuz99j26l6kvk9g"); // 	    dfscc(g, aghead(e), cc);
UNSUPPORTED("c9yz11pm5cux1tvh62xx2kwle"); // 	for (e = agfstin(g, n); e; e = agnxtin(g, e))
UNSUPPORTED("4gm4tqnmznd5xu1jmel9vdwu0"); // 	    dfscc(g, agtail(e), cc);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8udnninnq7lhgohjckc16b9r5
// static void connect_components(graph_t * g) 
public static Object connect_components(Object... arg) {
UNSUPPORTED("yvw35808308j5l11ghcua6gi"); // static void connect_components(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("392i41vqwsktdnsnlgldak18l"); //     int cc = 1;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("16hw9gw0dz2w7mrtba0eoqrdi"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("1btcv7arbo4kdjfc0iu4lseed"); // 	ND_mark(n) = 0;
UNSUPPORTED("16hw9gw0dz2w7mrtba0eoqrdi"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("6t6x4ox2i0udlfsfs7k1bo8ym"); // 	if (ND_mark(n) == 0)
UNSUPPORTED("8f3bhx4btilxdre5gd8ujw4l6"); // 	    dfscc(g, n, cc++);
UNSUPPORTED("16hhes6efkztzuw8ooeyr7duq"); //     if (cc > 1) {
UNSUPPORTED("3vgg779uxexcfdbjzk4jj8uax"); // 	node_t *root = agnode(g, "\177root", NOT(0));
UNSUPPORTED("bzbr2vqual2twjcg2p2sffsd4"); // 	int ncc = 1;
UNSUPPORTED("attp4bsjqe99xnhi7lr7pszar"); // 	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("bpn6b1b62u8nwx72ooh93fesp"); // 	    if (ND_mark(n) == ncc) {
UNSUPPORTED("1dnlkun6miejefgd7xabbern3"); // 		(void) agedge(g, root, n, (char *) 0, NOT(0));
UNSUPPORTED("cgm8ehtyoyn2ybwnrxvfx1cv8"); // 		ncc++;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4p0e0mlwnwv9zwtv9f435o76z
// static void aaa(graph_t * g) 
public static Object aaa(Object... arg) {
UNSUPPORTED("dmjm1jnv7l1xjgvgl3sbjtihu"); // static void aaa(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("casxgmme2w92ee08tg35xhuwc"); //     Agsym_t *weight, *minlen, *label;
UNSUPPORTED("dfo0aurn636wn2jjjx0knldqp"); //     char buf[64];
UNSUPPORTED("4o2basf8xoveb4htdnemu6mde"); //     weight = agattr(g, AGEDGE, "weight", "");
UNSUPPORTED("eb1v4vre44hj9bmu1wmps5fsg"); //     minlen = agattr(g, AGEDGE, "minlen", "");
UNSUPPORTED("cmj5vd88z41xucdkeq0bqki5"); //     label = agattr(g, AGEDGE, "label", "");
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("e20lm4qtccvgsfq5fzjv6sjyl"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("7tgxr2d6h3vm8s4rvqb8hdcg9"); // 	    sprintf(buf, "%f", ED_weight(e));
UNSUPPORTED("8uebwk2ve4o0uqrta7qpmzmf1"); // 	    agxset(e, weight, buf);
UNSUPPORTED("4e6yn2m9glwpifnrkxzvu3pf0"); // 	    sprintf(buf, "%d", ED_minlen(e));
UNSUPPORTED("8fsv22tt8q5te7m5g8c634wje"); // 	    agxset(e, minlen, buf);
UNSUPPORTED("df2r00bfk18nnn4005zy9eo41"); // 	    sprintf(buf, "%.02f,%d", ED_weight(e), ED_minlen(e));
UNSUPPORTED("e47sla9zumpkm12t4u1uz2ort"); // 	    agxset(e, label, buf);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6l46jzkgkiqxnhgxdqgd5t0hl
// static void printgraph(Agraph_t * g) 
public static Object printgraph(Object... arg) {
UNSUPPORTED("eoh8eg66u1h9443idt0tjoido"); // static void printgraph(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2rb10x0w8xlfguz2p3vko5dqx"); //     aaa(g);
UNSUPPORTED("82tw3t7ptsjqxu4u0zpzwg6yd"); //     agwrite(g, stderr);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 7xzsxz5qfau8ozwxuwlxb8oob
// static int nd_rank(Agnode_t * n) 
public static Object nd_rank(Object... arg) {
UNSUPPORTED("1xne0nxc0dt37z4wfnnp78jow"); // static int nd_rank(Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3huzv4l0jkg7a7pyqapyl00hl"); //     return ND_rank(n);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
