package gen.lib.common;
import h.*;
import core.*;
import core.annotation.*;
import static core.JUtils.*;
import static core.size_t.*;
import static core.OFFSET.*;
import static core.Macro.*;
import static core.Memory.*;
import static core.Stdlib.*;
import static gen.lib.ast.chresc.*;
import static gen.lib.ast.chrtoi.*;
import static gen.lib.ast.error.*;
import static gen.lib.ast.fmtbuf.*;
import static gen.lib.ast.fmtesc.*;
import static gen.lib.ast.pathaccess.*;
import static gen.lib.ast.pathbin.*;
import static gen.lib.ast.pathcanon.*;
import static gen.lib.ast.pathcat.*;
import static gen.lib.ast.pathexists.*;
import static gen.lib.ast.pathfind.*;
import static gen.lib.ast.pathgetlink.*;
import static gen.lib.ast.pathpath.*;
import static gen.lib.ast.strcopy.*;
import static gen.lib.ast.strerror.*;
import static gen.lib.ast.stresc.*;
import static gen.lib.ast.strmatch.*;
import static gen.lib.ast.strton.*;
import static gen.lib.cdt.dtclose.*;
import static gen.lib.cdt.dtdisc.*;
import static gen.lib.cdt.dtextract.*;
import static gen.lib.cdt.dtflatten.*;
import static gen.lib.cdt.dthash.*;
import static gen.lib.cdt.dtlist.*;
import static gen.lib.cdt.dtmethod.*;
import static gen.lib.cdt.dtopen.*;
import static gen.lib.cdt.dtrenew.*;
import static gen.lib.cdt.dtrestore.*;
import static gen.lib.cdt.dtsize.*;
import static gen.lib.cdt.dtstat.*;
import static gen.lib.cdt.dtstrhash.*;
import static gen.lib.cdt.dttree.*;
import static gen.lib.cdt.dttreeset.*;
import static gen.lib.cdt.dtview.*;
import static gen.lib.cdt.dtwalk.*;
import static gen.lib.cgraph.agerror.*;
import static gen.lib.cgraph.agxbuf.*;
import static gen.lib.cgraph.apply.*;
import static gen.lib.cgraph.attr.*;
import static gen.lib.cgraph.cmpnd.*;
import static gen.lib.cgraph.edge.*;
import static gen.lib.cgraph.flatten.*;
import static gen.lib.cgraph.grammar.*;
import static gen.lib.cgraph.graph.*;
import static gen.lib.cgraph.id.*;
import static gen.lib.cgraph.imap.*;
import static gen.lib.cgraph.io.*;
import static gen.lib.cgraph.main.*;
import static gen.lib.cgraph.mem.*;
import static gen.lib.cgraph.node.*;
import static gen.lib.cgraph.obj.*;
import static gen.lib.cgraph.pend.*;
import static gen.lib.cgraph.rec.*;
import static gen.lib.cgraph.refstr.*;
import static gen.lib.cgraph.scan.*;
import static gen.lib.cgraph.subg.*;
import static gen.lib.cgraph.tester.*;
import static gen.lib.cgraph.utils.*;
import static gen.lib.cgraph.write.*;
import static gen.lib.cgraph.y_tab.*;
import static gen.lib.circogen.block.*;
import static gen.lib.circogen.blockpath.*;
import static gen.lib.circogen.blocktree.*;
import static gen.lib.circogen.circpos.*;
import static gen.lib.circogen.circular.*;
import static gen.lib.circogen.circularinit.*;
import static gen.lib.circogen.deglist.*;
import static gen.lib.circogen.edgelist.*;
import static gen.lib.circogen.nodelist.*;
import static gen.lib.circogen.nodeset.*;
import static gen.lib.common.args.*;
import static gen.lib.common.arrows.*;
import static gen.lib.common.colxlate.*;
import static gen.lib.common.ellipse.*;
import static gen.lib.common.emit.*;
import static gen.lib.common.geom.*;
import static gen.lib.common.globals.*;
import static gen.lib.common.htmllex.*;
import static gen.lib.common.htmlparse.*;
import static gen.lib.common.htmltable.*;
import static gen.lib.common.input.*;
import static gen.lib.common.intset.*;
import static gen.lib.common.labels.*;
import static gen.lib.common.memory.*;
import static gen.lib.common.ns.*;
import static gen.lib.common.output.*;
import static gen.lib.common.pointset.*;
import static gen.lib.common.postproc.*;
import static gen.lib.common.psusershape.*;
import static gen.lib.common.routespl.*;
import static gen.lib.common.shapes.*;
import static gen.lib.common.splines.*;
import static gen.lib.common.strcasecmp.*;
import static gen.lib.common.strncasecmp.*;
import static gen.lib.common.taper.*;
import static gen.lib.common.textspan.*;
import static gen.lib.common.timing.*;
import static gen.lib.common.utils.*;
import static gen.lib.common.y_tab.*;
import static gen.lib.dotgen.acyclic.*;
import static gen.lib.dotgen.aspect.*;
import static gen.lib.dotgen.class1.*;
import static gen.lib.dotgen.class2.*;
import static gen.lib.dotgen.cluster.*;
import static gen.lib.dotgen.compound.*;
import static gen.lib.dotgen.conc.*;
import static gen.lib.dotgen.decomp.*;
import static gen.lib.dotgen.dotinit.*;
import static gen.lib.dotgen.dotsplines.*;
import static gen.lib.dotgen.fastgr.*;
import static gen.lib.dotgen.flat.*;
import static gen.lib.dotgen.mincross.*;
import static gen.lib.dotgen.position.*;
import static gen.lib.dotgen.rank.*;
import static gen.lib.dotgen.sameport.*;
import static gen.lib.dotgen2.decomp.*;
import static gen.lib.dotgen2.dotinit.*;
import static gen.lib.dotgen2.groups.*;
import static gen.lib.dotgen2.level.*;
import static gen.lib.dotgen2.minc2.*;
import static gen.lib.dotgen2.minc_utils.*;
import static gen.lib.dotgen2.ns.*;
import static gen.lib.edgepaint.edge_distinct_coloring.*;
import static gen.lib.edgepaint.furtherest_point.*;
import static gen.lib.edgepaint.intersection.*;
import static gen.lib.edgepaint.lab.*;
import static gen.lib.edgepaint.node_distinct_coloring.*;
import static gen.lib.expr.excc.*;
import static gen.lib.expr.excontext.*;
import static gen.lib.expr.exdata.*;
import static gen.lib.expr.exerror.*;
import static gen.lib.expr.exeval.*;
import static gen.lib.expr.exexpr.*;
import static gen.lib.expr.exlexname.*;
import static gen.lib.expr.exnospace.*;
import static gen.lib.expr.exopen.*;
import static gen.lib.expr.exparse.*;
import static gen.lib.expr.exrewind.*;
import static gen.lib.expr.exstash.*;
import static gen.lib.expr.extoken.*;
import static gen.lib.expr.extype.*;
import static gen.lib.expr.exzero.*;
import static gen.lib.expr.y_tab.*;
import static gen.lib.fdpgen.clusteredges.*;
import static gen.lib.fdpgen.comp.*;
import static gen.lib.fdpgen.dbg.*;
import static gen.lib.fdpgen.fdpinit.*;
import static gen.lib.fdpgen.grid.*;
import static gen.lib.fdpgen.layout.*;
import static gen.lib.fdpgen.tlayout.*;
import static gen.lib.fdpgen.xlayout.*;
import static gen.lib.glcomp.glcompbutton.*;
import static gen.lib.glcomp.glcompfont.*;
import static gen.lib.glcomp.glcompimage.*;
import static gen.lib.glcomp.glcomplabel.*;
import static gen.lib.glcomp.glcompmouse.*;
import static gen.lib.glcomp.glcomppanel.*;
import static gen.lib.glcomp.glcompset.*;
import static gen.lib.glcomp.glcomptextpng.*;
import static gen.lib.glcomp.glcomptexture.*;
import static gen.lib.glcomp.glpangofont.*;
import static gen.lib.glcomp.glutils.*;
import static gen.lib.gvc.gvbuffstderr.*;
import static gen.lib.gvc.gvc.*;
import static gen.lib.gvc.gvconfig.*;
import static gen.lib.gvc.gvcontext.*;
import static gen.lib.gvc.gvdevice.*;
import static gen.lib.gvc.gvevent.*;
import static gen.lib.gvc.gvjobs.*;
import static gen.lib.gvc.gvlayout.*;
import static gen.lib.gvc.gvloadimage.*;
import static gen.lib.gvc.gvplugin.*;
import static gen.lib.gvc.gvrender.*;
import static gen.lib.gvc.gvtextlayout.*;
import static gen.lib.gvc.gvusershape.*;
import static gen.lib.gvc.regex_win32.*;
import static gen.lib.gvpr.actions.*;
import static gen.lib.gvpr.compile.*;
import static gen.lib.gvpr.gprstate.*;
import static gen.lib.gvpr.gvpr.*;
import static gen.lib.gvpr.mkdefs.*;
import static gen.lib.gvpr.parse.*;
import static gen.lib.gvpr.queue.*;
import static gen.lib.gvpr.trie.*;
import static gen.lib.ingraphs.ingraphs.*;
import static gen.lib.label.index.*;
import static gen.lib.label.node.*;
import static gen.lib.label.nrtmain.*;
import static gen.lib.label.rectangle.*;
import static gen.lib.label.split_q.*;
import static gen.lib.label.xlabels.*;
import static gen.lib.mingle.agglomerative_bundling.*;
import static gen.lib.mingle.edge_bundling.*;
import static gen.lib.mingle.ink.*;
import static gen.lib.mingle.nearest_neighbor_graph.*;
import static gen.lib.neatogen.adjust.*;
import static gen.lib.neatogen.bfs.*;
import static gen.lib.neatogen.call_tri.*;
import static gen.lib.neatogen.circuit.*;
import static gen.lib.neatogen.closest.*;
import static gen.lib.neatogen.compute_hierarchy.*;
import static gen.lib.neatogen.conjgrad.*;
import static gen.lib.neatogen.constrained_majorization.*;
import static gen.lib.neatogen.constrained_majorization_ipsep.*;
import static gen.lib.neatogen.constraint.*;
import static gen.lib.neatogen.delaunay.*;
import static gen.lib.neatogen.dijkstra.*;
import static gen.lib.neatogen.edges.*;
import static gen.lib.neatogen.embed_graph.*;
import static gen.lib.neatogen.geometry.*;
import static gen.lib.neatogen.heap.*;
import static gen.lib.neatogen.hedges.*;
import static gen.lib.neatogen.info.*;
import static gen.lib.neatogen.kkutils.*;
import static gen.lib.neatogen.legal.*;
import static gen.lib.neatogen.lu.*;
import static gen.lib.neatogen.matinv.*;
import static gen.lib.neatogen.matrix_ops.*;
import static gen.lib.neatogen.memory.*;
import static gen.lib.neatogen.mosek_quad_solve.*;
import static gen.lib.neatogen.multispline.*;
import static gen.lib.neatogen.neatoinit.*;
import static gen.lib.neatogen.neatosplines.*;
import static gen.lib.neatogen.opt_arrangement.*;
import static gen.lib.neatogen.overlap.*;
import static gen.lib.neatogen.pca.*;
import static gen.lib.neatogen.poly.*;
import static gen.lib.neatogen.printvis.*;
import static gen.lib.neatogen.quad_prog_solve.*;
import static gen.lib.neatogen.quad_prog_vpsc.*;
import static gen.lib.neatogen.site.*;
import static gen.lib.neatogen.smart_ini_x.*;
import static gen.lib.neatogen.solve.*;
import static gen.lib.neatogen.stress.*;
import static gen.lib.neatogen.stuff.*;
import static gen.lib.neatogen.voronoi.*;
import static gen.lib.ortho.fPQ.*;
import static gen.lib.ortho.maze.*;
import static gen.lib.ortho.ortho.*;
import static gen.lib.ortho.partition.*;
import static gen.lib.ortho.rawgraph.*;
import static gen.lib.ortho.sgraph.*;
import static gen.lib.ortho.trapezoid.*;
import static gen.lib.osage.osageinit.*;
import static gen.lib.pack.ccomps.*;
import static gen.lib.pack.pack.*;
import static gen.lib.pack.ptest.*;
import static gen.lib.patchwork.patchwork.*;
import static gen.lib.patchwork.patchworkinit.*;
import static gen.lib.patchwork.tree_map.*;
import static gen.lib.pathplan.cvt.*;
import static gen.lib.pathplan.inpoly.*;
import static gen.lib.pathplan.route.*;
import static gen.lib.pathplan.shortest.*;
import static gen.lib.pathplan.shortestpth.*;
import static gen.lib.pathplan.solvers.*;
import static gen.lib.pathplan.triang.*;
import static gen.lib.pathplan.util.*;
import static gen.lib.pathplan.visibility.*;
import static gen.lib.rbtree.misc.*;
import static gen.lib.rbtree.red_black_tree.*;
import static gen.lib.rbtree.stack.*;
import static gen.lib.rbtree.test_red_black_tree.*;
import static gen.lib.sfdpgen.Multilevel.*;
import static gen.lib.sfdpgen.post_process.*;
import static gen.lib.sfdpgen.PriorityQueue.*;
import static gen.lib.sfdpgen.sfdpinit.*;
import static gen.lib.sfdpgen.sparse_solve.*;
import static gen.lib.sfdpgen.spring_electrical.*;
import static gen.lib.sfdpgen.stress_model.*;
import static gen.lib.sfdpgen.uniform_stress.*;
import static gen.lib.sfio.sfclose.*;
import static gen.lib.sfio.sfclrlock.*;
import static gen.lib.sfio.sfcvt.*;
import static gen.lib.sfio.sfdisc.*;
import static gen.lib.sfio.sfdlen.*;
import static gen.lib.sfio.sfexcept.*;
import static gen.lib.sfio.sfexit.*;
import static gen.lib.sfio.sfextern.*;
import static gen.lib.sfio.sffcvt.*;
import static gen.lib.sfio.sffilbuf.*;
import static gen.lib.sfio.sfflsbuf.*;
import static gen.lib.sfio.sfgetd.*;
import static gen.lib.sfio.sfgetl.*;
import static gen.lib.sfio.sfgetm.*;
import static gen.lib.sfio.sfgetr.*;
import static gen.lib.sfio.sfgetu.*;
import static gen.lib.sfio.sfllen.*;
import static gen.lib.sfio.sfmode.*;
import static gen.lib.sfio.sfmove.*;
import static gen.lib.sfio.sfmutex.*;
import static gen.lib.sfio.sfnew.*;
import static gen.lib.sfio.sfnotify.*;
import static gen.lib.sfio.sfnputc.*;
import static gen.lib.sfio.sfopen.*;
import static gen.lib.sfio.sfpkrd.*;
import static gen.lib.sfio.sfpoll.*;
import static gen.lib.sfio.sfpool.*;
import static gen.lib.sfio.sfpopen.*;
import static gen.lib.sfio.sfprintf.*;
import static gen.lib.sfio.sfprints.*;
import static gen.lib.sfio.sfpurge.*;
import static gen.lib.sfio.sfputd.*;
import static gen.lib.sfio.sfputl.*;
import static gen.lib.sfio.sfputm.*;
import static gen.lib.sfio.sfputr.*;
import static gen.lib.sfio.sfputu.*;
import static gen.lib.sfio.sfraise.*;
import static gen.lib.sfio.sfrd.*;
import static gen.lib.sfio.sfread.*;
import static gen.lib.sfio.sfreserve.*;
import static gen.lib.sfio.sfresize.*;
import static gen.lib.sfio.sfscanf.*;
import static gen.lib.sfio.sfseek.*;
import static gen.lib.sfio.sfset.*;
import static gen.lib.sfio.sfsetbuf.*;
import static gen.lib.sfio.sfsetfd.*;
import static gen.lib.sfio.sfsize.*;
import static gen.lib.sfio.sfsk.*;
import static gen.lib.sfio.sfstack.*;
import static gen.lib.sfio.sfstrtod.*;
import static gen.lib.sfio.sfswap.*;
import static gen.lib.sfio.sfsync.*;
import static gen.lib.sfio.sftable.*;
import static gen.lib.sfio.sftell.*;
import static gen.lib.sfio.sftmp.*;
import static gen.lib.sfio.sfungetc.*;
import static gen.lib.sfio.sfvprintf.*;
import static gen.lib.sfio.sfvscanf.*;
import static gen.lib.sfio.sfwr.*;
import static gen.lib.sfio.sfwrite.*;
import static gen.lib.sparse.BinaryHeap.*;
import static gen.lib.sparse.clustering.*;
import static gen.lib.sparse.colorutil.*;
import static gen.lib.sparse.color_palette.*;
import static gen.lib.sparse.DotIO.*;
import static gen.lib.sparse.general.*;
import static gen.lib.sparse.IntStack.*;
import static gen.lib.sparse.LinkedList.*;
import static gen.lib.sparse.mq.*;
import static gen.lib.sparse.QuadTree.*;
import static gen.lib.sparse.SparseMatrix.*;
import static gen.lib.sparse.vector.*;
import static gen.lib.topfish.hierarchy.*;
import static gen.lib.topfish.rescale_layout.*;
import static gen.lib.twopigen.circle.*;
import static gen.lib.twopigen.twopiinit.*;
import static gen.lib.vmalloc.malloc.*;
import static gen.lib.vmalloc.vmbest.*;
import static gen.lib.vmalloc.vmclear.*;
import static gen.lib.vmalloc.vmclose.*;
import static gen.lib.vmalloc.vmdcheap.*;
import static gen.lib.vmalloc.vmdebug.*;
import static gen.lib.vmalloc.vmdisc.*;
import static gen.lib.vmalloc.vmexit.*;
import static gen.lib.vmalloc.vmlast.*;
import static gen.lib.vmalloc.vmopen.*;
import static gen.lib.vmalloc.vmpool.*;
import static gen.lib.vmalloc.vmprivate.*;
import static gen.lib.vmalloc.vmprofile.*;
import static gen.lib.vmalloc.vmregion.*;
import static gen.lib.vmalloc.vmsegment.*;
import static gen.lib.vmalloc.vmset.*;
import static gen.lib.vmalloc.vmstat.*;
import static gen.lib.vmalloc.vmstrdup.*;
import static gen.lib.vmalloc.vmtrace.*;
import static gen.lib.vmalloc.vmwalk.*;
import static gen.lib.xdot.xdot.*;

public class utils {
// 2digov3edok6d5srhgtlmrycs
// extern lt_symlist_t lt_preloaded_symbols[]


// baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


// 9k44uhd5foylaeoekf3llonjq
// extern Dtmethod_t* 	Dtset


// 1ahfywsmzcpcig2oxm7pt9ihj
// extern Dtmethod_t* 	Dtbag


// anhghfj3k7dmkudy2n7rvt31v
// extern Dtmethod_t* 	Dtoset


// 5l6oj1ux946zjwvir94ykejbc
// extern Dtmethod_t* 	Dtobag


// 2wtf222ak6cui8cfjnw6w377z
// extern Dtmethod_t*	Dtlist


// d1s1s6ibtcsmst88e3057u9r7
// extern Dtmethod_t*	Dtstack


// axa7mflo824p6fspjn1rdk0mt
// extern Dtmethod_t*	Dtqueue


// ega812utobm4xx9oa9w9ayij6
// extern Dtmethod_t*	Dtdeque


// cyfr996ur43045jv1tjbelzmj
// extern Dtmethod_t*	Dtorder


// wlofoiftbjgrrabzb2brkycg
// extern Dtmethod_t*	Dttree


// 12bds94t7voj7ulwpcvgf6agr
// extern Dtmethod_t*	Dthash


// 9lqknzty480cy7zsubmabkk8h
// extern Dtmethod_t	_Dttree


// bvn6zkbcp8vjdhkccqo1xrkrb
// extern Dtmethod_t	_Dthash


// 9lidhtd6nsmmv3e7vjv9e10gw
// extern Dtmethod_t	_Dtlist


// 34ujfamjxo7xn89u90oh2k6f8
// extern Dtmethod_t	_Dtqueue


// 3jy4aceckzkdv950h89p4wjc8
// extern Dtmethod_t	_Dtstack


// 8dfqgf3u1v830qzcjqh9o8ha7
// extern Agmemdisc_t AgMemDisc


// 18k2oh2t6llfsdc5x0wlcnby8
// extern Agiddisc_t AgIdDisc


// a4r7hi80gdxtsv4hdoqpyiivn
// extern Agiodisc_t AgIoDisc


// bnzt5syjb7mgeru19114vd6xx
// extern Agdisc_t AgDefaultDisc


// 35y2gbegsdjilegaribes00mg
// extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,     Agstrictundirected


// c2rygslq6bcuka3awmvy2b3ow
// typedef Agsubnode_t	Agnoderef_t


// xam6yv0dcsx57dtg44igpbzn
// typedef Dtlink_t	Agedgeref_t


// nye6dsi1twkbddwo9iffca1j
// extern char *Version


// 65mu6k7h7lb7bx14jpiw7iyxr
// extern char **Files


// 2rpjdzsdyrvomf00zcs3u3dyn
// extern const char **Lib


// 6d2f111lntd2rsdt4gswh5909
// extern char *CmdName


// a0ltq04fpeg83soa05a2fkwb2
// extern char *specificFlags


// 1uv30qeqq2jh6uznlr4dziv0y
// extern char *specificItems


// 7i4hkvngxe3x7lmg5h6b3t9g3
// extern char *Gvfilepath


// 9jp96pa73kseya3w6sulxzok6
// extern char *Gvimagepath


// 40ylumfu7mrvawwf4v2asvtwk
// extern unsigned char Verbose


// 93st8awjy1z0h07n28qycbaka
// extern unsigned char Reduce


// f2vs67ts992erf8onwfglurzp
// extern int MemTest


// c6f8whijgjwwagjigmxlwz3gb
// extern char *HTTPServerEnVar


// cp4hzj7p87m7arw776d3bt7aj
// extern char *Output_file_name


// a3rqagofsgraie6mx0krzkgsy
// extern int graphviz_errors


// 5up05203r4kxvjn1m4njcgq5x
// extern int Nop


// umig46cco431x14b3kosde2t
// extern double PSinputscale


// 52bj6v8fqz39khasobljfukk9
// extern int Syntax_errors


// 9ekf2ina8fsjj6y6i0an6somj
// extern int Show_cnt


// 38di5qi3nkxkq65onyvconk3r
// extern char** Show_boxes


// 6ri6iu712m8mpc7t2670etpcw
// extern int CL_type


// bomxiw3gy0cgd1ydqtek7fpxr
// extern unsigned char Concentrate


// cqy3gqgcq8empdrbnrhn84058
// extern double Epsilon


// 64slegfoouqeg0rmbyjrm8wgr
// extern int MaxIter


// 88wdinpnmfs4mab4aw62yb0bg
// extern int Ndim


// 8bbad3ogcelqnnvo5br5s05gq
// extern int State


// 17rnd8q45zclfn68qqst2vxxn
// extern int EdgeLabelsDone


// ymx1z4s8cznjifl2d9f9m8jr
// extern double Initial_dist


// a33bgl0c3uqb3trx419qulj1x
// extern double Damping


// d9lvrpjg1r0ojv40pod1xwk8n
// extern int Y_invert


// 71efkfs77q5tq9ex6y0f4kanh
// extern int GvExitOnUsage


// 4xy2dkdkv0acs2ue9eca8hh2e
// extern Agsym_t 	*G_activepencolor, *G_activefillcolor, 	*G_selectedpencolor, *G_selectedfillcolor, 	*G_visitedpencolor, *G_visitedfillcolor, 	*G_deletedpencolor, *G_deletedfillcolor, 	*G_ordering, *G_peripheries, *G_penwidth, 	*G_gradientangle, *G_margin


// 9js5gxgzr74eakgtfhnbws3t9
// extern Agsym_t 	*N_height, *N_width, *N_shape, *N_color, *N_fillcolor, 	*N_activepencolor, *N_activefillcolor, 	*N_selectedpencolor, *N_selectedfillcolor, 	*N_visitedpencolor, *N_visitedfillcolor, 	*N_deletedpencolor, *N_deletedfillcolor, 	*N_fontsize, *N_fontname, *N_fontcolor, *N_margin, 	*N_label, *N_xlabel, *N_nojustify, *N_style, *N_showboxes, 	*N_sides, *N_peripheries, *N_ordering, *N_orientation, 	*N_skew, *N_distortion, *N_fixed, *N_imagescale, *N_layer, 	*N_group, *N_comment, *N_vertices, *N_z, 	*N_penwidth, *N_gradientangle


// anqllp9sj7wo45w6bm11j8trn
// extern Agsym_t 	*E_weight, *E_minlen, *E_color, *E_fillcolor, 	*E_activepencolor, *E_activefillcolor, 	*E_selectedpencolor, *E_selectedfillcolor, 	*E_visitedpencolor, *E_visitedfillcolor, 	*E_deletedpencolor, *E_deletedfillcolor, 	*E_fontsize, *E_fontname, *E_fontcolor, 	*E_label, *E_xlabel, *E_dir, *E_style, *E_decorate, 	*E_showboxes, *E_arrowsz, *E_constr, *E_layer, 	*E_comment, *E_label_float, 	*E_samehead, *E_sametail, 	*E_arrowhead, *E_arrowtail, 	*E_headlabel, *E_taillabel, 	*E_labelfontsize, *E_labelfontname, *E_labelfontcolor, 	*E_labeldistance, *E_labelangle, 	*E_tailclip, *E_headclip, 	*E_penwidth


// bh0z9puipqw7gymjd5h5b8s6i
// extern struct fdpParms_s* fdp_parms


// ciez0pfggxdljedzsbklq49f0
// static inline point pointof(int x, int y) 
public static Object pointof() {
throw new UnsupportedOperationException();
}


// c1s4k85p1cdfn176o3uryeros
// static inline pointf pointfof(double x, double y) 
public static Object pointfof() {
throw new UnsupportedOperationException();
}


// 7cufnfitrh935ew093mw0i4b7
// static inline box boxof(int llx, int lly, int urx, int ury) 
public static Object boxof() {
throw new UnsupportedOperationException();
}


// 1vvsta5i8of59frav6uymguav
// static inline boxf boxfof(double llx, double lly, double urx, double ury) 
public static Object boxfof() {
throw new UnsupportedOperationException();
}


// 1n5xl70wxuabyf97mclvilsm6
// static inline point add_point(point p, point q) 
public static Object add_point() {
throw new UnsupportedOperationException();
}


// arrsbik9b5tnfcbzsm8gr2chx
// static inline pointf add_pointf(pointf p, pointf q) 
public static Object add_pointf() {
throw new UnsupportedOperationException();
}


// ai2dprak5y6obdsflguh5qbd7
// static inline point sub_point(point p, point q) 
public static Object sub_point() {
throw new UnsupportedOperationException();
}


// 16f6pyogcv3j7n2p0n8giqqgh
// static inline pointf sub_pointf(pointf p, pointf q) 
public static Object sub_pointf() {
throw new UnsupportedOperationException();
}


// 9k50jgrhc4f9824vf8ony74rw
// static inline point mid_point(point p, point q) 
public static Object mid_point() {
throw new UnsupportedOperationException();
}


// 59c4f7im0ftyowhnzzq2v9o1x
// static inline pointf mid_pointf(pointf p, pointf q) 
public static Object mid_pointf() {
throw new UnsupportedOperationException();
}


// 5r18p38gisvcx3zsvbb9saixx
// static inline pointf interpolate_pointf(double t, pointf p, pointf q) 
public static Object interpolate_pointf() {
throw new UnsupportedOperationException();
}


// bxzrv2ghq04qk5cbyy68s4mol
// static inline point exch_xy(point p) 
public static Object exch_xy() {
throw new UnsupportedOperationException();
}


// 9lt3e03tac6h6sydljrcws8fd
// static inline pointf exch_xyf(pointf p) 
public static Object exch_xyf() {
throw new UnsupportedOperationException();
}


// bfhoui4uyanme6jwsztspsvg3
// static inline box box_bb(box b0, box b1) 
public static Object box_bb() {
throw new UnsupportedOperationException();
}


// 67266tnzfhg6rknemwbsk7k2u
// static inline boxf boxf_bb(boxf b0, boxf b1) 
public static Object boxf_bb() {
throw new UnsupportedOperationException();
}


// 6g8njmv5p5x0iztq2czxn4wdc
// static inline box box_intersect(box b0, box b1) 
public static Object box_intersect() {
throw new UnsupportedOperationException();
}


// 1omxwxljdk2wxh7g2ukda7ft8
// static inline boxf boxf_intersect(boxf b0, boxf b1) 
public static Object boxf_intersect() {
throw new UnsupportedOperationException();
}


// 6b8mjjsdlq8bi7fvc9279hwqz
// static inline int box_overlap(box b0, box b1) 
public static Object box_overlap() {
throw new UnsupportedOperationException();
}


// 8qlpi3q0pgktsy57e4tekav0n
// static inline int boxf_overlap(boxf b0, boxf b1) 
public static Object boxf_overlap() {
throw new UnsupportedOperationException();
}


// b3nk4vj0bc1ox98sju8z5x4je
// static inline int box_contains(box b0, box b1) 
public static Object box_contains() {
throw new UnsupportedOperationException();
}


// 92rids5igj6vkxr7pidh4y222
// static inline int boxf_contains(boxf b0, boxf b1) 
public static Object boxf_contains() {
throw new UnsupportedOperationException();
}


// 4wf5swkz24xx51ja2dynbycu1
// static inline pointf perp (pointf p) 
public static Object perp() {
throw new UnsupportedOperationException();
}


// 6dtlpzv4mvgzb9o0b252yweuv
// static inline pointf scale (double c, pointf p) 
public static Object scale() {
throw new UnsupportedOperationException();
}


// c7cptalfn8k75wyfirbnptnav
// nodequeue *new_queue(int sz) 
public static Object new_queue() {
throw new UnsupportedOperationException();
}


// 1uj5nmdvwmuklnpd3v5py547f
// void free_queue(nodequeue * q) 
public static Object free_queue() {
throw new UnsupportedOperationException();
}


// 20pwd6i141q3o25lfvrdqytot
// void enqueue(nodequeue * q, node_t * n) 
public static Object enqueue() {
throw new UnsupportedOperationException();
}


// b612nmtf16au96ztbs8pike9r
// node_t *dequeue(nodequeue * q) 
public static Object dequeue() {
throw new UnsupportedOperationException();
}


// 6nydxv4f2m7jcfh8ljs0neu0x
// int late_int(void *obj, attrsym_t * attr, int def, int low) 
public static Object late_int() {
throw new UnsupportedOperationException();
}


// d68314e4f20r79tt0cnmxugme
// double late_double(void *obj, attrsym_t * attr, double def, double low) 
public static Object late_double() {
throw new UnsupportedOperationException();
}


// 1k1t3xnmc07np54es3q8hpeof
// double get_inputscale (graph_t* g) 
public static Object get_inputscale() {
throw new UnsupportedOperationException();
}


// 83xm6yc9q5h1bzufhsnv0v2up
// char *late_string(void *obj, attrsym_t * attr, char *def) 
public static Object late_string() {
throw new UnsupportedOperationException();
}


// 8oon4q1mrublaru177xfntqgd
// char *late_nnstring(void *obj, attrsym_t * attr, char *def) 
public static Object late_nnstring() {
throw new UnsupportedOperationException();
}


// 87ifze04q7qzigjj1fb9y9by2
// boolean late_bool(void *obj, attrsym_t * attr, int def) 
public static Object late_bool() {
throw new UnsupportedOperationException();
}


// dt3wyz80q5t53tmz3j39aqbt4
// node_t *UF_find(node_t * n) 
public static Object UF_find() {
throw new UnsupportedOperationException();
}


// 4l72jsy65ugji4bvyy76wkp5a
// node_t *UF_union(node_t * u, node_t * v) 
public static Object UF_union() {
throw new UnsupportedOperationException();
}


// e5yz36boy200ybq4qa4tdvboh
// void UF_remove(node_t * u, node_t * v) 
public static Object UF_remove() {
throw new UnsupportedOperationException();
}


// ana9n64qky697nsptm254sj5r
// void UF_singleton(node_t * u) 
public static Object UF_singleton() {
throw new UnsupportedOperationException();
}


// byu9ezszyugbv5aktiq16nzdo
// void UF_setname(node_t * u, node_t * v) 
public static Object UF_setname() {
throw new UnsupportedOperationException();
}


// 5eju94jvkx5cgnebfonuz84o7
// pointf coord(node_t * n) 
public static Object coord() {
throw new UnsupportedOperationException();
}


// 6p0ey2c2ujk2o7h221p0b4xon
// pointf Bezier(pointf * V, int degree, double t, pointf * Left, pointf * Right) 
public static Object Bezier() {
throw new UnsupportedOperationException();
}


// 3ly0ylecb4k9xk5b7ffrlolt9
// char *Fgets(FILE * fp) 
public static Object Fgets() {
throw new UnsupportedOperationException();
}


// y5jmaaw5dgz2tqwcqpio6rxe
// static char** mkDirlist (const char* list, int* maxdirlen) 
public static Object mkDirlist() {
throw new UnsupportedOperationException();
}


// 49gli3uq79rprx3u3opdhcx1m
// static char* findPath (char** dirs, int maxdirlen, const char* str) 
public static Object findPath() {
throw new UnsupportedOperationException();
}


// 3xll2b0v9nthwvx9dafq49t8s
// const char *safefile(const char *filename) 
public static Object safefile() {
throw new UnsupportedOperationException();
}


// 2ihv17oajyaaaycirwsbgz1m7
// int maptoken(char *p, char **name, int *val) 
public static Object maptoken() {
throw new UnsupportedOperationException();
}


// 4esyuq2yqdaqoddgfqs24m5m3
// boolean mapBool(char *p, boolean dflt) 
public static Object mapBool() {
throw new UnsupportedOperationException();
}


// ehkvqh6bwf4jw3mj1w5p7a8m8
// boolean mapbool(char *p) 
public static Object mapbool() {
throw new UnsupportedOperationException();
}


// 5hb7n82vommyhrbfyrx5u6yht
// pointf dotneato_closest(splines * spl, pointf pt) 
public static Object dotneato_closest() {
throw new UnsupportedOperationException();
}


// 8g65cbj5nwf7h75wxhad4mwiv
// pointf spline_at_y(splines * spl, double y) 
public static Object spline_at_y() {
throw new UnsupportedOperationException();
}


// 4ws2d4r4z8psnleuxber6j3s6
// pointf neato_closest(splines * spl, pointf p) 
public static Object neato_closest() {
throw new UnsupportedOperationException();
}


// 8s6oop1ayag35eusof2rgdb5b
// static int Tflag


// ak4q69g3z2si69q7q6mmtp9qi
// void gvToggle(int s) 
public static Object gvToggle() {
throw new UnsupportedOperationException();
}


// 6h6t4myqjvz5d7nv9s4fme7ol
// int test_toggle() 
public static Object test_toggle() {
throw new UnsupportedOperationException();
}


// 7nuc7ccko01y938adkuqtaw2m
// void common_init_node(node_t * n) 
public static Object common_init_node() {
throw new UnsupportedOperationException();
}


// d2v8l80y27ue2fag5c0qplah8
// static void initFontEdgeAttr(edge_t * e, struct fontinfo *fi) 
public static Object initFontEdgeAttr() {
throw new UnsupportedOperationException();
}


// ak3pxrdrq900wymudwnjmbito
// static void initFontLabelEdgeAttr(edge_t * e, struct fontinfo *fi, 		      struct fontinfo *lfi) 
public static Object initFontLabelEdgeAttr() {
throw new UnsupportedOperationException();
}


// bgnk1zwht9rwx6thmly98iofb
// static boolean  noClip(edge_t *e, attrsym_t* sym) 
public static Object noClip() {
throw new UnsupportedOperationException();
}


// 9vnr1bc7p533acazoxbhbfmx3
// static port chkPort (port (*pf)(node_t*, char*, char*), node_t* n, char* s) 
public static Object chkPort() {
throw new UnsupportedOperationException();
}


// dr3sfpibgpxsi3ji92kmaxtl8
// int common_init_edge(edge_t * e) 
public static Object common_init_edge() {
throw new UnsupportedOperationException();
}


// 3mkqvtbyq9j8ktzil6t7vakg5
// static boxf addLabelBB(boxf bb, textlabel_t * lp, boolean flipxy) 
public static Object addLabelBB() {
throw new UnsupportedOperationException();
}


// 5vqrf8oj7orz7c2tb9v9ouofl
// boxf polyBB (polygon_t* poly) 
public static Object polyBB() {
throw new UnsupportedOperationException();
}


// 53rl672a6pvygzbrwb6gwr7ga
// void updateBB(graph_t * g, textlabel_t * lp) 
public static Object updateBB() {
throw new UnsupportedOperationException();
}


// 85jgb30jtf87igdp38prjioxd
// void compute_bb(graph_t * g) 
public static Object compute_bb() {
throw new UnsupportedOperationException();
}


// 1ihcngl4nnl0l3a4lazjawjak
// int is_a_cluster (Agraph_t* g) 
public static Object is_a_cluster() {
throw new UnsupportedOperationException();
}


// ewukjkd49rjfv3vtyrhv50y2o
// Agsym_t *setAttr(graph_t * g, void *obj, char *name, char *value, 			Agsym_t * ap) 
public static Object setAttr() {
throw new UnsupportedOperationException();
}


// 7f53enlpdym5phattaq6ya2zo
// static node_t *clustNode(node_t * n, graph_t * cg, agxbuf * xb, 			 graph_t * clg) 
public static Object clustNode() {
throw new UnsupportedOperationException();
}


// c1dr4tu5yewu3tcstfq3jkcfg
// static int cmpItem(Dt_t * d, void *p1[], void *p2[], Dtdisc_t * disc) 
public static Object cmpItem() {
throw new UnsupportedOperationException();
}


// bsharuh63hyx8gytgj0drcbxn
// static void *newItem(Dt_t * d, item * objp, Dtdisc_t * disc) 
public static Object newItem() {
throw new UnsupportedOperationException();
}


// 9k3952c7spf98nnxwfwnp246t
// static void freeItem(Dt_t * d, item * obj, Dtdisc_t * disc) 
public static Object freeItem() {
throw new UnsupportedOperationException();
}


// 3q539ycox1bllayps038bsksa
// static Dtdisc_t mapDisc = 


// cmped1c3ho0jglvwjjj6a228t
// static edge_t *cloneEdge(edge_t * e, node_t * ct, node_t * ch) 
public static Object cloneEdge() {
throw new UnsupportedOperationException();
}


// 86eff0qye8i679o3l43c1pa0n
// static void insertEdge(Dt_t * map, void *t, void *h, edge_t * e) 
public static Object insertEdge() {
throw new UnsupportedOperationException();
}


// dc66l3h4x33j5224698mgabqd
// static item *mapEdge(Dt_t * map, edge_t * e) 
public static Object mapEdge() {
throw new UnsupportedOperationException();
}


// c20xtd8tldxyzxmlrdtuozt64
// static void checkCompound(edge_t * e, graph_t * clg, agxbuf * xb, Dt_t * map, Dt_t* cmap) 
public static Object checkCompound() {
throw new UnsupportedOperationException();
}


// f3w0y6aksjsauz2ufmlaok8vv
// int processClusterEdges(graph_t * g) 
public static Object processClusterEdges() {
throw new UnsupportedOperationException();
}


// do7ny4334k5jkyvhqwl1050o8
// static node_t *mapN(node_t * n, graph_t * clg) 
public static Object mapN() {
throw new UnsupportedOperationException();
}


// 67uvlqkdlk4ln9mhzlio0ak4r
// static void undoCompound(edge_t * e, graph_t * clg) 
public static Object undoCompound() {
throw new UnsupportedOperationException();
}


// 6s7x7ut8o7wrwuw5nfdbknslk
// void undoClusterEdges(graph_t * g) 
public static Object undoClusterEdges() {
throw new UnsupportedOperationException();
}


// 6dwase854hhoz11vcuphugbij
// attrsym_t* safe_dcl(graph_t * g, int obj_kind, char *name, char *def) 
public static Object safe_dcl() {
throw new UnsupportedOperationException();
}


// 8vn95uhvbccfyutd9itvpk8vy
// static int comp_entities(const void *e1, const void *e2) 
public static Object comp_entities() {
throw new UnsupportedOperationException();
}


// 7t94y8iigozdjfx36lfzyak08
// char* scanEntity (char* t, agxbuf* xb) 
public static Object scanEntity() {
throw new UnsupportedOperationException();
}


// 6ol0iqfokq31kpiqngns9cnkm
// static int htmlEntity (char** s) 
public static Object htmlEntity() {
throw new UnsupportedOperationException();
}


// e3fdq03jg6298zgwjnftvhivy
// static unsigned char cvtAndAppend (unsigned char c, agxbuf* xb) 
public static Object cvtAndAppend() {
throw new UnsupportedOperationException();
}


// 9yungx7uxqkmzfh2ub6gs9l48
// char* htmlEntityUTF8 (char* s, graph_t* g) 
public static Object htmlEntityUTF8() {
throw new UnsupportedOperationException();
}


// 6spvz5rdt5uhtcpz0ypysuf8j
// char* latin1ToUTF8 (char* s) 
public static Object latin1ToUTF8() {
throw new UnsupportedOperationException();
}


// 913nrt0i8mr2gg2mz9qxdqh8o
// char* utf8ToLatin1 (char* s) 
public static Object utf8ToLatin1() {
throw new UnsupportedOperationException();
}


// axzv64az22go5e2ecbgw31we5
// boolean overlap_node(node_t *n, boxf b) 
public static Object overlap_node() {
throw new UnsupportedOperationException();
}


// bqyazq549k5b72i4h4xxgt15j
// boolean overlap_label(textlabel_t *lp, boxf b) 
public static Object overlap_label() {
throw new UnsupportedOperationException();
}


// 1lo61pqedf9b9j5bixph5kt9z
// static boolean overlap_arrow(pointf p, pointf u, double scale, int flag, boxf b) 
public static Object overlap_arrow() {
throw new UnsupportedOperationException();
}


// 7ic0hdq8fpa9fby43hy9p96n
// static boolean overlap_bezier(bezier bz, boxf b) 
public static Object overlap_bezier() {
throw new UnsupportedOperationException();
}


// 919yg68v78li9bklblgh0mb3r
// boolean overlap_edge(edge_t *e, boxf b) 
public static Object overlap_edge() {
throw new UnsupportedOperationException();
}


// ckavkcnz5rcrqs17lleds1uxu
// int edgeType (char* s, int dflt) 
public static Object edgeType() {
throw new UnsupportedOperationException();
}


// cev889fnwa30brehdcxoj84j7
// void setEdgeType (graph_t* g, int dflt) 
public static Object setEdgeType() {
throw new UnsupportedOperationException();
}


// 6jwyz00ziwvmc5v8qm6sv07oi
// void get_gradient_points(pointf * A, pointf * G, int n, float angle, int flags) 
public static Object get_gradient_points() {
throw new UnsupportedOperationException();
}


// 22n1uekxezky6gx3cn22ansew
// int strcasecmp(const char *s1, const char *s2) 
public static Object strcasecmp() {
throw new UnsupportedOperationException();
}


// 6fpqvqq5eso7d44vai4lz77jd
// int strncasecmp(const char *s1, const char *s2, unsigned int n) 
public static Object strncasecmp() {
throw new UnsupportedOperationException();
}


// aaits4wz8zia8e1vtgef5s0mp
// void gv_free_splines(edge_t * e) 
public static Object gv_free_splines() {
throw new UnsupportedOperationException();
}


// 8fm5ty90deao241xwwjvz4srx
// void gv_cleanup_edge(edge_t * e) 
public static Object gv_cleanup_edge() {
throw new UnsupportedOperationException();
}


// e5gdos23vmjfapqcrd0oz7zdr
// void gv_cleanup_node(node_t * n) 
public static Object gv_cleanup_node() {
throw new UnsupportedOperationException();
}


// 7ocebex5lj3lw0ljyrs8bj9ra
// void gv_nodesize(node_t * n, boolean flip) 
public static Object gv_nodesize() {
throw new UnsupportedOperationException();
}


// 7uxrf3fkz919opkirpd9xtuv
// double drand48(void) 
public static Object drand48() {
throw new UnsupportedOperationException();
}


// 8lktrcvj65bvhh04y89vecvo2
// static void free_clust (Dt_t* dt, clust_t* clp, Dtdisc_t* disc) 
public static Object free_clust() {
throw new UnsupportedOperationException();
}


// 5kz2qt153vtr25aib7hx2zxma
// static Dtdisc_t strDisc = 


// ymcb1kecrhh35zpyodksd20y
// static void fillMap (Agraph_t* g, Dt_t* map) 
public static Object fillMap() {
throw new UnsupportedOperationException();
}


// 82wzptlrwslbvgp3xyj03p9ba
// Dt_t* mkClustMap (Agraph_t* g) 
public static Object mkClustMap() {
throw new UnsupportedOperationException();
}


// aohw5khae06vhhp2t4cczvcbv
// Agraph_t* findCluster (Dt_t* map, char* name) 
public static Object findCluster() {
throw new UnsupportedOperationException();
}


// cte5wyn5eqivzbrjuttlljnyc
// Agnodeinfo_t* ninf(Agnode_t* n) 
public static Object ninf() {
throw new UnsupportedOperationException();
}


// bpwtpthj4u9yw0v4r1n5e10k6
// Agraphinfo_t* ginf(Agraph_t* g) 
public static Object ginf() {
throw new UnsupportedOperationException();
}


// 7o5sruz1ud2bfugcvk50bji01
// Agedgeinfo_t* einf(Agedge_t* e) 
public static Object einf() {
throw new UnsupportedOperationException();
}


}
