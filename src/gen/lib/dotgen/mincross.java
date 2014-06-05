package gen.lib.dotgen;
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

public class mincross {
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


// 8w9q2y2zwtyyvqvo8i7urfjdm
// static int gd_minrank(Agraph_t *g) 
public static Object gd_minrank() {
throw new UnsupportedOperationException();
}


// 9mj1yh23slnfk3jxy86jckn3
// static int gd_maxrank(Agraph_t *g) 
public static Object gd_maxrank() {
throw new UnsupportedOperationException();
}


// 4b1vor05a9hdcquifg3pkxnxy
// static rank_t *gd_rank(Agraph_t *g, int r) 
public static Object gd_rank() {
throw new UnsupportedOperationException();
}


// efzwlpfvqknlouo2vk05yola1
// static int nd_order(Agnode_t *v) 
public static Object nd_order() {
throw new UnsupportedOperationException();
}


// eusjqny3hma23wvcznk9arpgr
// static int MinQuit


// eykidmlm64erbhaultu3js822
// static double Convergence


// f2ssditidb9f1cgp7r1kslp0e
// static graph_t *Root


// ager0orj38x5rjuhzv1o2cxuc
// static int GlobalMinRank, GlobalMaxRank


// dag2n5hcww3ada79u52a8yha6
// static edge_t **TE_list


// agrg82s0nsmuokh0t3h5q6h90
// static int *TI_list


// 7x0e0qfe96o5elb6lxt8mfmho
// static boolean ReMincross


// d1qnrrwwj1b68etds1cgx2mrl
// void dot_mincross(graph_t * g, int doBalance) 
public static Object dot_mincross() {
throw new UnsupportedOperationException();
}


// 756bre1tpxb1tq68p7xhkrxkc
// static adjmatrix_t *new_matrix(int i, int j) 
public static Object new_matrix() {
throw new UnsupportedOperationException();
}


// 1n1e0k0wtlbugwm3cb4na6av6
// static void free_matrix(adjmatrix_t * p) 
public static Object free_matrix() {
throw new UnsupportedOperationException();
}


// d9i3lea1bl4nssbygblqp8xem
// static void init_mccomp(graph_t * g, int c) 
public static Object init_mccomp() {
throw new UnsupportedOperationException();
}


// 78ssudlgw8nanfgjjh74we1qm
// static int betweenclust(edge_t * e) 
public static Object betweenclust() {
throw new UnsupportedOperationException();
}


// 24zaeljrnbr9dgbotzniyseok
// static void do_ordering_node (graph_t * g, node_t* n, int outflag) 
public static Object do_ordering_node() {
throw new UnsupportedOperationException();
}


// 815nmj2gcomtex4yfclqde12j
// static void do_ordering(graph_t * g, int outflag) 
public static Object do_ordering() {
throw new UnsupportedOperationException();
}


// 4sf5jvwgglvw980gk03hhts4q
// static void do_ordering_for_nodes(graph_t * g) 
public static Object do_ordering_for_nodes() {
throw new UnsupportedOperationException();
}


// ag0o08icw7zjyz8yps3j9tsf3
// static void ordered_edges(graph_t * g) 
public static Object ordered_edges() {
throw new UnsupportedOperationException();
}


// 4bszokhjum6f03da1ag5umm36
// static int mincross_clust(graph_t * par, graph_t * g, int doBalance) 
public static Object mincross_clust() {
throw new UnsupportedOperationException();
}


// 6hl6aujgx3j9l6je4lennbzst
// static int left2right(graph_t * g, node_t * v, node_t * w) 
public static Object left2right() {
throw new UnsupportedOperationException();
}


// aylujn1h3obs8l2cxdk1nsaop
// static int in_cross(node_t * v, node_t * w) 
public static Object in_cross() {
throw new UnsupportedOperationException();
}


// 47ex8x3utnpj09plizp0j28vj
// static int out_cross(node_t * v, node_t * w) 
public static Object out_cross() {
throw new UnsupportedOperationException();
}


// a7n7v2npmieze561cwrq3p33f
// static void exchange(node_t * v, node_t * w) 
public static Object exchange() {
throw new UnsupportedOperationException();
}


// anwn2ys3hfzj0sibw582g5d1m
// static void balanceNodes(graph_t * g, int r, node_t * v, node_t * w) 
public static Object balanceNodes() {
throw new UnsupportedOperationException();
}


// a3vluzz6sh8lgl4wa3tn2y0j2
// static int balance(graph_t * g) 
public static Object balance() {
throw new UnsupportedOperationException();
}


// 7iqjxwq7ndplnxz47p7wvg73z
// static int transpose_step(graph_t * g, int r, int reverse) 
public static Object transpose_step() {
throw new UnsupportedOperationException();
}


// c10uo4m7gv5y7ipp4k315pij9
// static void transpose(graph_t * g, int reverse) 
public static Object transpose() {
throw new UnsupportedOperationException();
}


// 7g46eije0njo9aj4ei9o3wu4b
// static int mincross(graph_t * g, int startpass, int endpass, int doBalance) 
public static Object mincross() {
throw new UnsupportedOperationException();
}


// f0sqhhrucpxlkayzbtu8p10pc
// static void restore_best(graph_t * g) 
public static Object restore_best() {
throw new UnsupportedOperationException();
}


// ciazyving3ms7i1qj1zi8bjyk
// static void save_best(graph_t * g) 
public static Object save_best() {
throw new UnsupportedOperationException();
}


// ebqm2cex8ep60jztgj6tea7bc
// static void merge_components(graph_t * g) 
public static Object merge_components() {
throw new UnsupportedOperationException();
}


// 9f8wkzpj4fhnfhmf3pxyfn49v
// static void merge2(graph_t * g) 
public static Object merge2() {
throw new UnsupportedOperationException();
}


// z8ucnkrbx358ppz21m0qwlii
// static void cleanup2(graph_t * g, int nc) 
public static Object cleanup2() {
throw new UnsupportedOperationException();
}


// 9dvtirsxkigimpbfofzt9cmrv
// static node_t *neighbor(node_t * v, int dir) 
public static Object neighbor() {
throw new UnsupportedOperationException();
}


// bgjk9o0huc8v7pxcp14gouzay
// static int is_a_normal_node_of(graph_t * g, node_t * v) 
public static Object is_a_normal_node_of() {
throw new UnsupportedOperationException();
}


// eqz42tcs7vh5tqpqa6wo74gh4
// static int is_a_vnode_of_an_edge_of(graph_t * g, node_t * v) 
public static Object is_a_vnode_of_an_edge_of() {
throw new UnsupportedOperationException();
}


// eo7ulc8vwmoaig0j479yapve2
// static int inside_cluster(graph_t * g, node_t * v) 
public static Object inside_cluster() {
throw new UnsupportedOperationException();
}


// 8xkmkt4r6gfqj8gk0mokszoz0
// static node_t *furthestnode(graph_t * g, node_t * v, int dir) 
public static Object furthestnode() {
throw new UnsupportedOperationException();
}


// f0uof2cgv6vlki8zk5i5s003z
// void save_vlist(graph_t * g) 
public static Object save_vlist() {
throw new UnsupportedOperationException();
}


// ahodaxg8mve25z0c15jalvnb6
// void rec_save_vlists(graph_t * g) 
public static Object rec_save_vlists() {
throw new UnsupportedOperationException();
}


// 1hdr0m10yrs8lh5oj1yvnofti
// void rec_reset_vlists(graph_t * g) 
public static Object rec_reset_vlists() {
throw new UnsupportedOperationException();
}


// 83ll7i331b5ixpagr5zqglikc
// static Agraph_t* realFillRanks (Agraph_t* g, int rnks[], int rnks_sz, Agraph_t* sg) 
public static Object realFillRanks() {
throw new UnsupportedOperationException();
}


// 9q555odt07zemcm3astjifgi8
// static void fillRanks (Agraph_t* g) 
public static Object fillRanks() {
throw new UnsupportedOperationException();
}


// cgsfj2mvq5e2rvss6r7wa4x7e
// static void init_mincross(graph_t * g) 
public static Object init_mincross() {
throw new UnsupportedOperationException();
}


// ei5aennme6d7v5qkcg3oz1hjc
// void flat_rev(Agraph_t * g, Agedge_t * e) 
public static Object flat_rev() {
throw new UnsupportedOperationException();
}


// duxc8fgr0q2wtn9p40kh4u47u
// static void flat_search(graph_t * g, node_t * v) 
public static Object flat_search() {
throw new UnsupportedOperationException();
}


// 61mb2783tj8tcybvoypy6zrhq
// static void flat_breakcycles(graph_t * g) 
public static Object flat_breakcycles() {
throw new UnsupportedOperationException();
}


// 46egbuckrdttvcvm77jiumi9z
// void allocate_ranks(graph_t * g) 
public static Object allocate_ranks() {
throw new UnsupportedOperationException();
}


// 8qx5mp9l19r4qwl63jb7wge13
// void install_in_rank(graph_t * g, node_t * n) 
public static Object install_in_rank() {
throw new UnsupportedOperationException();
}


// cfnefcjfb6ndkhd5qzt29o0ni
// void build_ranks(graph_t * g, int pass) 
public static Object build_ranks() {
throw new UnsupportedOperationException();
}


// 8zndtjps1vl4kd055mufin1zr
// void enqueue_neighbors(nodequeue * q, node_t * n0, int pass) 
public static Object enqueue_neighbors() {
throw new UnsupportedOperationException();
}


// 48owfca3cu59e8tfrcs5q1agg
// static int constraining_flat_edge(Agraph_t *g, Agnode_t *v, Agedge_t *e) 
public static Object constraining_flat_edge() {
throw new UnsupportedOperationException();
}


// cjqhneu6ugodgykcigg2n7cd7
// static int postorder(graph_t * g, node_t * v, node_t ** list, int r) 
public static Object postorder() {
throw new UnsupportedOperationException();
}


// 73nuogo9gi40yjdkv5gj9e3u0
// static void flat_reorder(graph_t * g) 
public static Object flat_reorder() {
throw new UnsupportedOperationException();
}


// 9west0khu17pqvrj484ppnoyg
// static void reorder(graph_t * g, int r, int reverse, int hasfixed) 
public static Object reorder() {
throw new UnsupportedOperationException();
}


// 2rbvmo1earuu51aney1maa9kr
// static void mincross_step(graph_t * g, int pass) 
public static Object mincross_step() {
throw new UnsupportedOperationException();
}


// avs0z4ssa582mgxtx9h1kbwlu
// static int local_cross(elist l, int dir) 
public static Object local_cross() {
throw new UnsupportedOperationException();
}


// erg9y8dvmuubvd37p1ij4ljyr
// static int rcross(graph_t * g, int r) 
public static Object rcross() {
throw new UnsupportedOperationException();
}


// 1zqav0bs09kxktjd5pkbnndl4
// int ncross(graph_t * g) 
public static Object ncross() {
throw new UnsupportedOperationException();
}


// 8wrsq8a2vooekcm3cdtv5x3ke
// static int ordercmpf(int *i0, int *i1) 
public static Object ordercmpf() {
throw new UnsupportedOperationException();
}


// 8g4d67tt2cdl1pt0hscbo7z9i
// static int flat_mval(node_t * n) 
public static Object flat_mval() {
throw new UnsupportedOperationException();
}


// 2xzpzhjwzj54da612xeodnsdb
// static boolean medians(graph_t * g, int r0, int r1) 
public static Object medians() {
throw new UnsupportedOperationException();
}


// 2eh12wo3jy9x8ske7sudb9w8l
// static int nodeposcmpf(node_t ** n0, node_t ** n1) 
public static Object nodeposcmpf() {
throw new UnsupportedOperationException();
}


// 6ujw7jxz90fgrbt4h1z1nn8ty
// static int edgeidcmpf(edge_t ** e0, edge_t ** e1) 
public static Object edgeidcmpf() {
throw new UnsupportedOperationException();
}


// 40as9opn4mzq4gp4nkmp4dj8w
// static int table[3][3] = 


// 8k011tbnvlhv8qafk7fhd0edv
// static int endpoint_class(node_t * n) 
public static Object endpoint_class() {
throw new UnsupportedOperationException();
}


// afb2bwlvs6lka8xszizcldtkx
// void virtual_weight(edge_t * e) 
public static Object virtual_weight() {
throw new UnsupportedOperationException();
}


// 9hr99c6996x0z8ulvgok2kwda
// static void mincross_options(graph_t * g) 
public static Object mincross_options() {
throw new UnsupportedOperationException();
}


}
