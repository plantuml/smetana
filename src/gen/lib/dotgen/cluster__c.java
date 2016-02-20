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
package gen.lib.dotgen;
import static gen.lib.cgraph.edge__c.agfstout;
import static gen.lib.cgraph.edge__c.aghead;
import static gen.lib.cgraph.edge__c.agnxtout;
import static gen.lib.cgraph.node__c.agfstnode;
import static gen.lib.cgraph.node__c.agnxtnode;
import static smetana.core.JUtilsDebug.ENTERING;
import static smetana.core.JUtilsDebug.LEAVING;
import static smetana.core.Macro.ED_to_virt;
import static smetana.core.Macro.GD_clust;
import static smetana.core.Macro.GD_n_cluster;
import static smetana.core.Macro.ND_clust;
import static smetana.core.Macro.ND_node_type;
import static smetana.core.Macro.ND_out;
import static smetana.core.Macro.ND_ranktype;
import static smetana.core.Macro.UNSUPPORTED;
import h.Agedge_s;
import h.Agnode_s;
import h.Agobj_s;
import h.Agraph_s;
import h.Agraphinfo_t;
import h.boxf;
import h.pointf;
import smetana.core.__struct__;

public class cluster__c {
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




//3 8bd317q0mykfu6wpr3e4cxmh2
// static node_t* map_interclust_node(node_t * n) 
public static Object map_interclust_node(Object... arg) {
UNSUPPORTED("b9dd3satxbh59hljdxzcxecc"); // static node_t*
UNSUPPORTED("c9elz74ksl4vz5qjvtsb1s5e"); // map_interclust_node(node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4302bhte4qzbdabx61n5e2rim"); //     node_t *rv;
UNSUPPORTED("6oahlbbnqi8owe6dxxhrtjz0r"); //     if ((ND_clust(n) == NULL) || (  GD_expanded(ND_clust(n))) )
UNSUPPORTED("b9ebidcvs6sci0jn0jt6g952w"); // 	rv = n;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("725asxjnihmx9ak4biqsn5au9"); // 	rv = GD_rankleader(ND_clust(n))[ND_rank(n)];
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5ib4nnt2ah5fdd22zs0xds29r
// static void  make_slots(graph_t * root, int r, int pos, int d) 
public static Object make_slots(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("dse5mknojwwieag50nb54af2"); // make_slots(graph_t * root, int r, int pos, int d)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("ebrvvj6vkj6zj5oarcz1o14bc"); //     node_t *v, **vlist;
UNSUPPORTED("6za61n9cpedeb3rcs57d8lv29"); //     vlist = GD_rank(root)[r].v;
UNSUPPORTED("6rffs9egg2lli9120emdwdh85"); //     if (d <= 0) {
UNSUPPORTED("4j1uy4i8jmj8ky4pnhqdp3hu"); // 	for (i = pos - d + 1; i < GD_rank(root)[r].n; i++) {
UNSUPPORTED("c2bblbvuyzu278hg73e0v9ias"); // 	    v = vlist[i];
UNSUPPORTED("8z4668r4wjhdszu5exo9uv4bx"); // 	    ND_order(v) = i + d - 1;
UNSUPPORTED("68gyj82gqshz5j6cagzfm6qow"); // 	    vlist[ND_order(v)] = v;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("1w3sxuwhqr49qyynhkxqh9m68"); // 	for (i = GD_rank(root)[r].n + d - 1; i < GD_rank(root)[r].n; i++)
UNSUPPORTED("9vbx5od7t2kzw09v2mfyihu61"); // 	    vlist[i] = NULL;
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("3x0o6lb6lygb5kged7d95z3zf"); // /*assert(ND_rank(root)[r].n + d - 1 <= ND_rank(root)[r].an);*/
UNSUPPORTED("5a7v9mm4ilyci9e3p2a2xk1kp"); // 	for (i = GD_rank(root)[r].n - 1; i > pos; i--) {
UNSUPPORTED("c2bblbvuyzu278hg73e0v9ias"); // 	    v = vlist[i];
UNSUPPORTED("8z4668r4wjhdszu5exo9uv4bx"); // 	    ND_order(v) = i + d - 1;
UNSUPPORTED("68gyj82gqshz5j6cagzfm6qow"); // 	    vlist[ND_order(v)] = v;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("espci28tl0ev3b5z093f4xp5i"); // 	for (i = pos + 1; i < pos + d; i++)
UNSUPPORTED("9vbx5od7t2kzw09v2mfyihu61"); // 	    vlist[i] = NULL;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1b53yvi9ni0s6rneuasppbjgl"); //     GD_rank(root)[r].n += d - 1;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 d4mwxesl56uh9dyttg9cjlq70
// static node_t*  clone_vn(graph_t * g, node_t * vn) 
public static Object clone_vn(Object... arg) {
UNSUPPORTED("5h97lag1uc713a403n4ytn4l8"); // static node_t* 
UNSUPPORTED("6cdhbndwzvzzk6jejejcbboyd"); // clone_vn(graph_t * g, node_t * vn)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4302bhte4qzbdabx61n5e2rim"); //     node_t *rv;
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("195ae59wpeaox749qavq94ywq"); //     r = ND_rank(vn);
UNSUPPORTED("dp36udfcdslnyedn4oalhjjkj"); //     make_slots(g, r, ND_order(vn), 2);
UNSUPPORTED("cvrll8cgny6kz7junxwy435ke"); //     rv = virtual_node(g);
UNSUPPORTED("eznvurrhiy08b2bgzahws7gkq"); //     ND_lw(rv) = ND_lw(vn);
UNSUPPORTED("3e7v6qne6z4l9raqrcxsbnc58"); //     ND_rw(rv) = ND_rw(vn);
UNSUPPORTED("6r1snmbt81xbtbcu38aevfayd"); //     ND_rank(rv) = ND_rank(vn);
UNSUPPORTED("1xjquwevhtwmdpcxjjr2e7719"); //     ND_order(rv) = ND_order(vn) + 1;
UNSUPPORTED("adc0qfdhup29vh8qu1cwl5jgj"); //     GD_rank(g)[r].v[ND_order(rv)] = rv;
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6o86r59v2ujlxqcw7761y6o5b
// static void  map_path(node_t * from, node_t * to, edge_t * orig, edge_t * ve, int type) 
public static Object map_path(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("6rfj1n9bqywbyr91hjf701jc4"); // map_path(node_t * from, node_t * to, edge_t * orig, edge_t * ve, int type)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("5yrhx4blosxo5xnc1nh1kzhfs"); //     node_t *u, *v;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("aqnqskxwazx5uf38wjkwl25xe"); //     assert(ND_rank(from) < ND_rank(to));
UNSUPPORTED("etl7gohr4vcqj10zhnggsc9p3"); //     if ((agtail(ve) == from) && (aghead(ve) == to))
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dxggiu6cw3ahqtgyogx9cbeui"); //     if (ED_count(ve) > 1) {
UNSUPPORTED("amzisjlzyd7kcnykhwm3emzsw"); // 	ED_to_virt(orig) = NULL;
UNSUPPORTED("3usjzgkkiqzrkacya4l5x1wwv"); // 	if (ND_rank(to) - ND_rank(from) == 1) {
UNSUPPORTED("7rikcljs70u4mv2pl0nxrkozq"); // 	    if ((e = find_fast_edge(from, to)) && (ports_eq(orig, e))) {
UNSUPPORTED("15imfa3fwa9eecqbv04gdlz9g"); // 		merge_oneway(orig, e);
UNSUPPORTED("3wix4edrrj20l71i08ckve4ao"); // 		if ((ND_node_type(from) == 0)
UNSUPPORTED("blnvalvptm73qbqedzi8o5qx2"); // 		    && (ND_node_type(to) == 0))
UNSUPPORTED("1qiw6v20ddsxgj17i5pnlvjyn"); // 		    other_edge(orig);
UNSUPPORTED("6bj8inpmr5ulm16jmfxsstjtn"); // 		return;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("1x35hzfwt92fmliibo5v89m7c"); // 	u = from;
UNSUPPORTED("e0x5b4qz9ijzzy3o87otbxuq9"); // 	for (r = ND_rank(from); r < ND_rank(to); r++) {
UNSUPPORTED("4u4cndjol9mjoizaxexkijz6b"); // 	    if (r < ND_rank(to) - 1)
UNSUPPORTED("7nfktz3r8rlmo2rcg7y075ufe"); // 		v = clone_vn(dot_root(from), aghead(ve));
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("cirictno38xls9e6dhksdpmp2"); // 		v = to;
UNSUPPORTED("6ghi2o0a6dgb9jlk96ydus4c"); // 	    e = virtual_edge(u, v, orig);
UNSUPPORTED("6q6y62qde57z3lsb2801pkn7b"); // 	    ED_edge_type(e) = type;
UNSUPPORTED("7lybui6nu0sgimvycjyy3685h"); // 	    u = v;
UNSUPPORTED("6jjh353s9hrfwqh6yru1b875w"); // 	    ED_count(ve)--;
UNSUPPORTED("5evemf4tm2qpxh7ii2pzs3ba8"); // 	    ve = ND_out(aghead(ve)).list[0];
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("3usjzgkkiqzrkacya4l5x1wwv"); // 	if (ND_rank(to) - ND_rank(from) == 1) {
UNSUPPORTED("89xtdt8atqaubsc33ijpumhxl"); // 	    if ((ve = find_fast_edge(from, to)) && (ports_eq(orig, ve))) {
UNSUPPORTED("apnwi8n66mi1x31jb54puo76j"); // 		/*ED_to_orig(ve) = orig; */
UNSUPPORTED("5p2khszrc6g7ru07ssw0mqrdj"); // 		ED_to_virt(orig) = ve;
UNSUPPORTED("2s25e03vchcien0roipesjdmf"); // 		ED_edge_type(ve) = type;
UNSUPPORTED("23p8k5rg6ca82g2enw2wyuxkq"); // 		ED_count(ve)++;
UNSUPPORTED("3wix4edrrj20l71i08ckve4ao"); // 		if ((ND_node_type(from) == 0)
UNSUPPORTED("blnvalvptm73qbqedzi8o5qx2"); // 		    && (ND_node_type(to) == 0))
UNSUPPORTED("1qiw6v20ddsxgj17i5pnlvjyn"); // 		    other_edge(orig);
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("b87s1z4ymup7pt4ttlit23147"); // 		ED_to_virt(orig) = NULL;
UNSUPPORTED("9h2527fpci2klhg27op1s0nyc"); // 		ve = virtual_edge(from, to, orig);
UNSUPPORTED("2s25e03vchcien0roipesjdmf"); // 		ED_edge_type(ve) = type;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("2jqkm0ejpsdek6yviw2qxpob5"); // 	if (ND_rank(to) - ND_rank(from) > 1) {
UNSUPPORTED("atpqi8htn5pfsp83jsjnpya6u"); // 	    e = ve;
UNSUPPORTED("48q2i88h3eiwyvatk52go1qk3"); // 	    if (agtail(ve) != from) {
UNSUPPORTED("b87s1z4ymup7pt4ttlit23147"); // 		ED_to_virt(orig) = NULL;
UNSUPPORTED("artn59emuxdx7iczkltmrkps0"); // 		e = ED_to_virt(orig) = virtual_edge(from, aghead(ve), orig);
UNSUPPORTED("a57axdi6yo27zbr1wjhy83ulz"); // 		delete_fast_edge(ve);
UNSUPPORTED("afk9bpom7x393euamnvwwkx6b"); // 	    } else
UNSUPPORTED("8q8ufoa5cnfya3803on8l3iqi"); // 		e = ve;
UNSUPPORTED("841onu13nrkagywfwcs5ym6wy"); // 	    while (ND_rank(aghead(e)) != ND_rank(to))
UNSUPPORTED("7zjq6cetd2j3icvu5rdxk4f0d"); // 		e = ND_out(aghead(e)).list[0];
UNSUPPORTED("4b6isfwr3ag7crntdsdg7uewy"); // 	    if (aghead(e) != to) {
UNSUPPORTED("22buahogyeh9ri5tkqe69qsur"); // 		ve = e;
UNSUPPORTED("cdtd6iwjostde5uuwlole4e9m"); // 		e = virtual_edge(agtail(e), to, orig);
UNSUPPORTED("25nmda3y8wn495w90p98e8f3k"); // 		ED_edge_type(e) = type;
UNSUPPORTED("a57axdi6yo27zbr1wjhy83ulz"); // 		delete_fast_edge(ve);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 69xbflgja0gvrsl5xcv7o7dia
// static void  make_interclust_chain(graph_t * g, node_t * from, node_t * to, edge_t * orig) 
public static Object make_interclust_chain(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("1pxoz295ynl8uxtunzhn9zcw8"); // make_interclust_chain(graph_t * g, node_t * from, node_t * to, edge_t * orig)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8bqdnnjl4p07socckb619ym2j"); //     int newtype;
UNSUPPORTED("5yrhx4blosxo5xnc1nh1kzhfs"); //     node_t *u, *v;
UNSUPPORTED("1yvk68e79nwflqeh30vwxcly1"); //     u = map_interclust_node(from);
UNSUPPORTED("3y6r8q80thsmgr8dhaq0cv618"); //     v = map_interclust_node(to);
UNSUPPORTED("7ktl4809y1fjd4k87vzs54rvl"); //     if ((u == from) && (v == to))
UNSUPPORTED("77sur6hpxgjihky9t3wc268xm"); // 	newtype = 1;
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("2soi2ep4ey6fcum9km26q8c66"); // 	newtype = 5;
UNSUPPORTED("eoasdiwdbadedh52fxjv9e63f"); //     map_path(u, v, orig, ED_to_virt(orig), newtype);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6g2m2y44x66lajznvnon2gubv
// void interclexp(graph_t * subg) 
public static Object interclexp(Object... arg) {
UNSUPPORTED("ek3ccf3xw36pv6uezqcoiu8si"); // void interclexp(graph_t * subg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("djl3ek9tn11htu3vj4zglczzz"); //     graph_t *g;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("7zrvjlifb8nyt9ju38q8be944"); //     edge_t *e, *prev, *next;
UNSUPPORTED("8zhb1u0rnu694g9xz1yjbrklh"); //     g = dot_root(subg);
UNSUPPORTED("6ewipai3bqonhmh4h826lvwyi"); //     for (n = agfstnode(subg); n; n = agnxtnode(subg, n)) {
UNSUPPORTED("9848g2kernqnb0vegrrbdjnkk"); // 	/* N.B. n may be in a sub-cluster of subg */
UNSUPPORTED("6sx2tx6c4b42f42jdzwezkjhu"); // 	prev = NULL;
UNSUPPORTED("uvhzvbyt6tz7fks2bc1erbjh"); // 	for (e = agfstedge(g, n); e; e = next) {
UNSUPPORTED("6vbil9er6xviwxl0k2j3mofa9"); // 	    next = agnxtedge(g, e, n);
UNSUPPORTED("6huxivhyl5frz7rckfyi3c333"); // 	    if (agcontains(subg, e))
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("2iq6hn134gv9re3c4vk73effz"); // 	    /* canonicalize edge */
UNSUPPORTED("9z44vigbeogxr42xga2jtuftb"); // 	    e = AGMKOUT(e);
UNSUPPORTED("698a1f4cinuc4jzv1c1anatwp"); // 	    /* short/flat multi edges */
UNSUPPORTED("7c8hcxkl4k6tzjbvuv6zm7i8m"); // 	    if (mergeable(prev, e)) {
UNSUPPORTED("1pv8kbb78w6fs8m3i4x1mrsfv"); // 		if (ND_rank(agtail(e)) == ND_rank(aghead(e)))
UNSUPPORTED("dzrp230epur5myrngxf86icdl"); // 		    ED_to_virt(e) = prev;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("80avg8pw0q6u1yek5npatayak"); // 		    ED_to_virt(e) = NULL;
UNSUPPORTED("2oxl2hzhfzzfn7q7i6phwgkqd"); // 		if (ED_to_virt(prev) == NULL)
UNSUPPORTED("10wljk1lfxrvhkb8y6bzvxz35"); // 		    continue;	/* internal edge */
UNSUPPORTED("8d5mw7m9lzlseqbyx8a8mncgs"); // 		merge_chain(subg, e, ED_to_virt(prev), 0);
UNSUPPORTED("87mmnlsj8quzlzg0vxax15kt2"); // 		safe_other_edge(e);
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("1nads3zouz9kt3i1cowzty7qg"); // 	    /* flat edges */
UNSUPPORTED("f41nqpgmu0v4g3in9iye5hqmk"); // 	    if (ND_rank(agtail(e)) == ND_rank(aghead(e))) {
UNSUPPORTED("7btwg6u7g9qqpsrjkx8kgqaxb"); // 		edge_t* fe;
UNSUPPORTED("19u95m77ae7zrrhs7zgxr1hg2"); // 		if ((fe = find_flat_edge(agtail(e), aghead(e))) == NULL) {
UNSUPPORTED("bpkb1088t7rphe02enn72qn3r"); // 		    flat_edge(g, e);
UNSUPPORTED("2u7me39ekhszjmm5usw9gbdqu"); // 		    prev = e;
UNSUPPORTED("b3t4l2xftweujklnzi93btx10"); // 		} else if (e != fe) {
UNSUPPORTED("ckfinb4h4twp1ry02y9peyhz"); // 		    safe_other_edge(e);
UNSUPPORTED("dg3e0udctqa7xtfynplc7wdpj"); // 		    if (!ED_to_virt(e)) merge_oneway(e, fe);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("77de1lt12166bjdzemq1qzzge"); // 	    /* forward edges */
UNSUPPORTED("d6wijn1x6tz3ui2hmdcoqeutm"); // 	    if (ND_rank(aghead(e)) > ND_rank(agtail(e))) {
UNSUPPORTED("cya82rykkk8ltdjur9d0t4y06"); // 		make_interclust_chain(g, agtail(e), aghead(e), e);
UNSUPPORTED("dpsnmca44s1cfw35axk4m0slg"); // 		prev = e;
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("en84wkh5tegcnfn2uxkoeq3ii"); // 	    /* backward edges */
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("4v614d3uabme2jyn0anuritbb"); // /*
UNSUPPORTED("f4205odrpzllkukgs8jw11wil"); // I think that make_interclust_chain should create call other_edge(e) anyway 
UNSUPPORTED("971rp6el9lv2c5ky83kzchybk"); // 				if (agcontains(subg,agtail(e))
UNSUPPORTED("246ron78q2ynw6t81l76r1hlu"); // 					&& agfindedge(g,aghead(e),agtail(e))) other_edge(e);
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("f3vsjiyhij046afu7hd6mozsu"); // 		make_interclust_chain(g, aghead(e), agtail(e), e);
UNSUPPORTED("dpsnmca44s1cfw35axk4m0slg"); // 		prev = e;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 85nhs7tnmwunw0fsjj1kxao7l
// static void  merge_ranks(graph_t * subg) 
public static Object merge_ranks(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("cyb9t6avlre01zdfj130sqw0b"); // merge_ranks(graph_t * subg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e8t9d1nntl7tg3zgic525u2c7"); //     int i, d, r, pos, ipos;
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("7vns7h9lh77tzfv2yang9mlhc"); //     graph_t *root;
UNSUPPORTED("2rnxnc122mftowo5oputs53mt"); //     root = dot_root(subg);
UNSUPPORTED("61uj2zobhnw5nq0wzggnllp5n"); //     if (GD_minrank(subg) > 0)
UNSUPPORTED("6joeb28tqhza9srpo118g386i"); // 	GD_rank(root)[GD_minrank(subg) - 1].valid = 0;
UNSUPPORTED("7hd1fq1q29nkhy8m7fmb59kvh"); //     for (r = GD_minrank(subg); r <= GD_maxrank(subg); r++) {
UNSUPPORTED("9arx2wwkcirjnha87g9v9dkke"); // 	d = GD_rank(subg)[r].n;
UNSUPPORTED("87ho7258ejyscg51fhceuiv4n"); // 	ipos = pos = ND_order(GD_rankleader(subg)[r]);
UNSUPPORTED("9z797uh5gsro2tm5cfaun9pjf"); // 	make_slots(root, r, pos, d);
UNSUPPORTED("e02587sxo73pzptiwtkcu2iy2"); // 	for (i = 0; i < GD_rank(subg)[r].n; i++) {
UNSUPPORTED("86c3q8t12dy95j43z5ubvpmt2"); // 	    v = GD_rank(root)[r].v[pos] = GD_rank(subg)[r].v[i];
UNSUPPORTED("6zmrwbor9adlqj38xj53hrhay"); // 	    ND_order(v) = pos++;
UNSUPPORTED("bb75iqztzwwlnpnbn3ixplijk"); // 	/* real nodes automatically have v->root = root graph */
UNSUPPORTED("2uc4w73phbo5ke63c0npuxut1"); // 	    if (ND_node_type(v) == 1)
UNSUPPORTED("cmd75ufuy2zn4g67mf16vkfvc"); // 		v->root = agroot(root);
UNSUPPORTED("9iu2aqgzpk1yqsk2idltcqovf"); // 	    delete_fast_node(subg, v);
UNSUPPORTED("4ix79uz0bjwb7vmb36i7993k0"); // 	    fast_node(root, v);
UNSUPPORTED("6y4gzecxwbjvyz0fuozxnwjdy"); // 	    GD_n_nodes(root)++;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("cpfyslvmh6ahlcss0um5lonuu"); // 	GD_rank(subg)[r].v = GD_rank(root)[r].v + ipos;
UNSUPPORTED("7xfzmsitn6y5kd96oh5ggoc9s"); // 	GD_rank(root)[r].valid = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4fw9j2o28aal06zu5chof5hsr"); //     if (r < GD_maxrank(root))
UNSUPPORTED("7xfzmsitn6y5kd96oh5ggoc9s"); // 	GD_rank(root)[r].valid = 0;
UNSUPPORTED("5zubpemwj3covioxuzfu3x6mj"); //     GD_expanded(subg) = NOT(0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c9p7dm16i13qktnh95os0sv58
// static void  remove_rankleaders(graph_t * g) 
public static Object remove_rankleaders(Object... arg) {
UNSUPPORTED("59dl3yc4jbcy2pb7j1njhlybi"); // static void 
UNSUPPORTED("8s6jkfzpo1hvg6z54ebnxbz55"); // remove_rankleaders(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("60nab7gyukq3bs8e6dizhbacy"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("bvep2g583wy7vlgwrwguznvf8"); // 	v = GD_rankleader(g)[r];
UNSUPPORTED("7nnrokg22q8adjqnbexka6d7u"); // 	/* remove the entire chain */
UNSUPPORTED("7t0cmtp6p0n6ps5bs8bwqqtri"); // 	while ((e = ND_out(v).list[0]))
UNSUPPORTED("7hjrudu87t0hj5xv24vhlf3k6"); // 	    delete_fast_edge(e);
UNSUPPORTED("6k2ppe945lkljbp2c5g49788c"); // 	while ((e = ND_in(v).list[0]))
UNSUPPORTED("7hjrudu87t0hj5xv24vhlf3k6"); // 	    delete_fast_edge(e);
UNSUPPORTED("3r9r1pgpihp0gzk930h5hmqbp"); // 	delete_fast_node(dot_root(g), v);
UNSUPPORTED("2rpy1wfe6lhmak6ce4v24v4ao"); // 	GD_rankleader(g)[r] = NULL;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ecrplg8hsyl484f9kxc5xp0go
// void expand_cluster(graph_t * subg) 
public static Object expand_cluster(Object... arg) {
UNSUPPORTED("8r09nj1ydndz2sbuv5a3cs0yw"); // void expand_cluster(graph_t * subg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("20v0p57hvmh0ijvbozfex75b2"); //     /* build internal structure of the cluster */
UNSUPPORTED("124308nt4wlqvenj2kgo1kpfd"); //     class2(subg);
UNSUPPORTED("65g8taekjkoquq087637lvha6"); //     GD_comp(subg).size = 1;
UNSUPPORTED("25xzzho8d0p44on9aeoy3ees7"); //     GD_comp(subg).list[0] = GD_nlist(subg);
UNSUPPORTED("8ogubd5qfa352hiig4rypuk62"); //     allocate_ranks(subg);
UNSUPPORTED("b7bzidwsi0pi848v6w318ggg4"); //     build_ranks(subg, 0);
UNSUPPORTED("27ob5amzldrayj64omx544g9q"); //     merge_ranks(subg);
UNSUPPORTED("alp5n2wnkn3xqz3yk6ild0qo7"); //     /* build external structure of the cluster */
UNSUPPORTED("d1p59qtuqhsq6ij3ewqukocaa"); //     interclexp(subg);
UNSUPPORTED("ag2d9unvlsdc0spx00c99ha27"); //     remove_rankleaders(subg);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cxuirggihlap2iv2khmb1w5l5
// void mark_clusters(graph_t * g) 
public static void mark_clusters(Agraph_s g) {
ENTERING("cxuirggihlap2iv2khmb1w5l5","mark_clusters");
try {
    int c;
    Agnode_s n, nn, vn;
    Agedge_s orig, e;
    Agraph_s clust;
    /* remove sub-clusters below this level */
    for (n = agfstnode(g); n!=null; n = agnxtnode(g, n)) {
	if (ND_ranktype(n) == 7)
UNSUPPORTED("9e3nevyzc6v99gtbi3gafblda"); // 	    UF_singleton(n);
	ND_clust(n, null);
    }
    for (c = 1; c <= g.castTo(Agobj_s.class).getPtr("data").castTo(Agraphinfo_t.class).getInt("n_cluster"); c++) {
UNSUPPORTED("8r7swlrdrtz33331zz7i881hl"); // 	clust = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c];
UNSUPPORTED("4q2t0lecjlhl7t9890360w9lw"); // 	for (n = agfstnode(clust); n; n = nn) {
UNSUPPORTED("3xxccr7xo6ty5mjkmnwtxh8gu"); // 		nn = agnxtnode(clust,n);
UNSUPPORTED("1szgjebapdug0xvr4acnn2p3"); // 	    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype) != 0) {
UNSUPPORTED("5l8jenkv77ax02t47zzxyv1k0"); // 		agerr(AGWARN,
UNSUPPORTED("2ipl4umxgijawr7756ysp9hhd"); // 		      "%s was already in a rankset, deleted from cluster %s\n",
UNSUPPORTED("7r0ulsiau9cygesawzzjnpt5j"); // 		      agnameof(n), agnameof(g));
UNSUPPORTED("4zqc8357rwnd9xe7zaoqooqv3"); // 		agdelete(clust,n);
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("6niuq4wd0y8ruh63q1xccpw28"); // 	    UF_setname(n, (((Agraphinfo_t*)(((Agobj_t*)(clust))->data))->leader));
UNSUPPORTED("61itmk4dnhbj1n37d634m5krc"); // 	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust) = clust;
UNSUPPORTED("8g66yuls81gjk48hgjx6ii6x7"); // 	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ranktype) = 7;
UNSUPPORTED("13shsx4neo5028pgb2bgspyww"); // 	    /* here we mark the vnodes of edges in the cluster */
UNSUPPORTED("ah1lxylwa1lwt2qkkrhhecpa0"); // 	    for (orig = agfstout(clust, n); orig;
UNSUPPORTED("8jhi70ejxq9dhch07hza05ggv"); // 		 orig = agnxtout(clust, orig)) {
UNSUPPORTED("mhkeqqxmg4mfscr6dwhh0pej"); // 		if ((e = (((Agedgeinfo_t*)(((Agobj_t*)(orig))->data))->to_virt))) {
UNSUPPORTED("dnt9308cavxi23curv62ugigz"); // 		    while (e && (((Agnodeinfo_t*)(((Agobj_t*)(vn =((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->node_type) == 1) {
UNSUPPORTED("2i0k1w9na0rckvtw8ce7duahe"); // 			(((Agnodeinfo_t*)(((Agobj_t*)(vn))->data))->clust) = clust;
UNSUPPORTED("861k8sepchf319k6dm3lp7y5i"); // 			e = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->out).list[0];
UNSUPPORTED("426z9apdzwnaqujjg6zur4msi"); // 			/* trouble if concentrators and clusters are mixed */
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
    }
} finally {
LEAVING("cxuirggihlap2iv2khmb1w5l5","mark_clusters");
}
}




//3 bwrw5u0gi2rgah1cn9h0glpse
// void build_skeleton(graph_t * g, graph_t * subg) 
public static Object build_skeleton(Object... arg) {
UNSUPPORTED("ao1aco399y25n5ksddo2c54dw"); // void build_skeleton(graph_t * g, graph_t * subg)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("ei2qpnzm9f28n8ro1fvjsu9t9"); //     node_t *v, *prev, *rl;
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("9pg1u5lrva4tjoa207r87y7uu"); //     prev = NULL;
UNSUPPORTED("9rf17a5hbod5714tv6f6vc3u3"); //     GD_rankleader(subg) = (node_t **)zmalloc((GD_maxrank(subg) + 2)*sizeof(node_t *));
UNSUPPORTED("7hd1fq1q29nkhy8m7fmb59kvh"); //     for (r = GD_minrank(subg); r <= GD_maxrank(subg); r++) {
UNSUPPORTED("f1wbki3uvoo71smx5ut3v5d5f"); // 	v = GD_rankleader(subg)[r] = virtual_node(g);
UNSUPPORTED("4eax8ygh6aiknrsbkt9lzvim0"); // 	ND_rank(v) = r;
UNSUPPORTED("3j3as00imhqeuh0j3u77c336s"); // 	ND_ranktype(v) = 7;
UNSUPPORTED("8llv8wb95398cf9of3e9a7tms"); // 	ND_clust(v) = subg;
UNSUPPORTED("a6y33oymxwxiry6hk21xjsdio"); // 	if (prev) {
UNSUPPORTED("1jdfsu1u8czmk8zfl5eejy8mw"); // 	    e = virtual_edge(prev, v, NULL);
UNSUPPORTED("7tjnxnp2clg1s80azh3tkv0gx"); // 	    ED_xpenalty(e) *= 1000;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("2cgerzj9mx9ggx0i7qmtxsgka"); // 	prev = v;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2es6ll1uukehmlb34ak9gbyzx"); //     /* set the counts on virtual edges of the cluster skeleton */
UNSUPPORTED("8j5hk6r5r7ook6wlepspab3ck"); //     for (v = agfstnode(subg); v; v = agnxtnode(subg, v)) {
UNSUPPORTED("5lk6z8eqhs2zsztqh9s4c3vqv"); // 	rl = GD_rankleader(subg)[ND_rank(v)];
UNSUPPORTED("6xmclrgtmdhcrt0ay2q7oid3c"); // 	ND_UF_size(rl)++;
UNSUPPORTED("echtfywp192aih0pqkybw9oxs"); // 	for (e = agfstout(subg, v); e; e = agnxtout(subg, e)) {
UNSUPPORTED("dkn2kqjyljhbrkiu7cy5jdciq"); // 	    for (r = ND_rank(agtail(e)); r < ND_rank(aghead(e)); r++) {
UNSUPPORTED("8ddnt8snwkgl54jtxgat96g5i"); // 		ED_count(ND_out(rl).list[0])++;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7hd1fq1q29nkhy8m7fmb59kvh"); //     for (r = GD_minrank(subg); r <= GD_maxrank(subg); r++) {
UNSUPPORTED("bi5fzkix4p8p0y6etydfxg843"); // 	rl = GD_rankleader(subg)[r];
UNSUPPORTED("25pg4la4o3wucrsiqa7s1z4cr"); // 	if (ND_UF_size(rl) > 1)
UNSUPPORTED("b3u2psknvy2i1zv4e9jau73zm"); // 	    ND_UF_size(rl)--;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 75yt3xwcwnxipi827t1r8zcmn
// void install_cluster(graph_t * g, node_t * n, int pass, nodequeue * q) 
public static Object install_cluster(Object... arg) {
UNSUPPORTED("bj15esm8qgk83ki9s3rplwwr5"); // void install_cluster(graph_t * g, node_t * n, int pass, nodequeue * q)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("p6jnh7nvcpnl3zbz636pskbs"); //     int r;
UNSUPPORTED("ebd98tetp980s8p4muyc7dg1"); //     graph_t *clust;
UNSUPPORTED("dctaf4e5gafgf0uxc1y5nqg6o"); //     clust = ND_clust(n);
UNSUPPORTED("ewgx34dkqxrkg8zyiasav756w"); //     if (GD_installed(clust) != pass + 1) {
UNSUPPORTED("a3qxlur50f73ztxv673pgrai9"); // 	for (r = GD_minrank(clust); r <= GD_maxrank(clust); r++)
UNSUPPORTED("ds90u2fboesjeokfn98mvo5ac"); // 	    install_in_rank(g, GD_rankleader(clust)[r]);
UNSUPPORTED("a3qxlur50f73ztxv673pgrai9"); // 	for (r = GD_minrank(clust); r <= GD_maxrank(clust); r++)
UNSUPPORTED("bacyglrcfdqgsopu9amth490p"); // 	    enqueue_neighbors(q, GD_rankleader(clust)[r], pass);
UNSUPPORTED("3j0j4hihdiv48ov24vynj45av"); // 	GD_installed(clust) = pass + 1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4muksvb3ec03mt6cvaqpb5c7a
// void mark_lowclusters(Agraph_t * root) 
public static void mark_lowclusters(Agraph_s root) {
ENTERING("4muksvb3ec03mt6cvaqpb5c7a","mark_lowclusters");
try {
    Agnode_s n, vn;
    Agedge_s orig, e;
    /* first, zap any previous cluster labelings */
    for (n = agfstnode(root); n!=null; n = agnxtnode(root, n)) {
	ND_clust(n, null);
	for (orig = agfstout(root, n); orig!=null; orig = agnxtout(root, orig)) {
	    if ((e = ED_to_virt(orig))!=null) {
		while (e!=null && (ND_node_type(vn = aghead(e))) == 1) {
		    ND_clust(vn, null);
		    e = (Agedge_s) ND_out(aghead(e)).getArrayOfPtr("list").plus(0).getPtr();
		}
	    }
	}
    }
    /* do the recursion */
    mark_lowcluster_basic(root);
} finally {
LEAVING("4muksvb3ec03mt6cvaqpb5c7a","mark_lowclusters");
}
}




//3 48j6fdymvkcgeh4wde060ctac
// static void mark_lowcluster_basic(Agraph_t * g) 
public static void mark_lowcluster_basic(Agraph_s g) {
ENTERING("48j6fdymvkcgeh4wde060ctac","mark_lowcluster_basic");
try {
    Agraph_s clust;
    Agnode_s n, vn;
    Agedge_s orig, e;
    int c;
    for (c = 1; c <= GD_n_cluster(g); c++) {
	clust = (Agraph_s) GD_clust(g).plus(c).getPtr();
	mark_lowcluster_basic(clust);
    }
    /* see what belongs to this graph that wasn't already marked */
    for (n = agfstnode(g); n!=null; n = agnxtnode(g, n)) {
	if (ND_clust(n) == null)
	    ND_clust(n, g);
	for (orig = agfstout(g, n); orig!=null; orig = agnxtout(g, orig)) {
	    if ((e = ED_to_virt(orig))!=null) {
		while (e!=null && (ND_node_type(vn = aghead(e))) == 1) {
		    if (ND_clust(vn) == null)
			ND_clust(vn, g);
		    e = (Agedge_s) ND_out(aghead(e)).getArrayOfPtr("list").plus(0).getPtr();
		}
	    }
	}
    }
} finally {
LEAVING("48j6fdymvkcgeh4wde060ctac","mark_lowcluster_basic");
}
}


}
