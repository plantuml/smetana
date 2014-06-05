package gen.lib.sparse;
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

public class SparseMatrix {
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


// a0ryl617d6urcim7c96fxe64e
// static size_t size_of_matrix_type(int type)
public static Object size_of_matrix_type() {
throw new UnsupportedOperationException();
}


// 5ka8b46u5wtbrpqnam83vz929
// SparseMatrix SparseMatrix_sort(SparseMatrix A)
public static Object SparseMatrix_sort() {
throw new UnsupportedOperationException();
}


// eylbpeth4ggdvzjzjkbua6swc
// SparseMatrix SparseMatrix_make_undirected(SparseMatrix A)
public static Object SparseMatrix_make_undirected() {
throw new UnsupportedOperationException();
}


// b31i1x3au1eenuwvgsozh47iz
// SparseMatrix SparseMatrix_transpose(SparseMatrix A)
public static Object SparseMatrix_transpose() {
throw new UnsupportedOperationException();
}


// 66iefhdeent4tcnu654z7e6cw
// SparseMatrix SparseMatrix_symmetrize(SparseMatrix A, int pattern_symmetric_only)
public static Object SparseMatrix_symmetrize() {
throw new UnsupportedOperationException();
}


// 2lr80qi9wgsj49z815ajy7d0s
// SparseMatrix SparseMatrix_symmetrize_nodiag(SparseMatrix A, int pattern_symmetric_only)
public static Object SparseMatrix_symmetrize_nodiag() {
throw new UnsupportedOperationException();
}


// acox722un3kphn6kdm85qe1k9
// int SparseMatrix_is_symmetric(SparseMatrix A, int test_pattern_symmetry_only)
public static Object SparseMatrix_is_symmetric() {
throw new UnsupportedOperationException();
}


// 1jyepwqo5cnk6dfnt3hngos1f
// static SparseMatrix SparseMatrix_init(int m, int n, int type, size_t sz, int format)
public static Object SparseMatrix_init() {
throw new UnsupportedOperationException();
}


// aip9x1lu1x1dq6tg9m2hk893h
// static SparseMatrix SparseMatrix_alloc(SparseMatrix A, int nz)
public static Object SparseMatrix_alloc() {
throw new UnsupportedOperationException();
}


// 2wnc51r49o0kh4nea4bzwnvfy
// static SparseMatrix SparseMatrix_realloc(SparseMatrix A, int nz)
public static Object SparseMatrix_realloc() {
throw new UnsupportedOperationException();
}


// 6d60pzx1870ttqlugibpq3hph
// SparseMatrix SparseMatrix_new(int m, int n, int nz, int type, int format)
public static Object SparseMatrix_new() {
throw new UnsupportedOperationException();
}


// 5lc60jrxn0s4kufi8uahqkiqm
// SparseMatrix SparseMatrix_general_new(int m, int n, int nz, int type, size_t sz, int format)
public static Object SparseMatrix_general_new() {
throw new UnsupportedOperationException();
}


// e163z6r69vpdg7z66ze48ea5w
// void SparseMatrix_delete(SparseMatrix A)
public static Object SparseMatrix_delete() {
throw new UnsupportedOperationException();
}


// ciob9qqaihtdgmyngt1dxwlhi
// void SparseMatrix_print_csr(char *c, SparseMatrix A)
public static Object SparseMatrix_print_csr() {
throw new UnsupportedOperationException();
}


// 1lw7w98qs8bcwkdvh55py7yvk
// void SparseMatrix_print_coord(char *c, SparseMatrix A)
public static Object SparseMatrix_print_coord() {
throw new UnsupportedOperationException();
}


// 73mukjvzyt9dc009cmy3fjtu8
// void SparseMatrix_print(char *c, SparseMatrix A)
public static Object SparseMatrix_print() {
throw new UnsupportedOperationException();
}


// 8oh6q1wjzqgm3zu4qmsz0hncp
// static void SparseMatrix_export_csr(FILE *f, SparseMatrix A)
public static Object SparseMatrix_export_csr() {
throw new UnsupportedOperationException();
}


// 7rsy09simi239j1xs8h87lr7b
// void SparseMatrix_export_binary_fp(FILE *f, SparseMatrix A)
public static Object SparseMatrix_export_binary_fp() {
throw new UnsupportedOperationException();
}


// 9yyu3l0qjp8mw680ehmgpwy4i
// void SparseMatrix_export_binary(char *name, SparseMatrix A, int *flag)
public static Object SparseMatrix_export_binary() {
throw new UnsupportedOperationException();
}


// 1bfj2sxif6ec5fqkpp8x7kvlb
// SparseMatrix SparseMatrix_import_binary_fp(FILE *f)
public static Object SparseMatrix_import_binary_fp() {
throw new UnsupportedOperationException();
}


// 5wev25zpxul07wcsha6muf2z
// SparseMatrix SparseMatrix_import_binary(char *name)
public static Object SparseMatrix_import_binary() {
throw new UnsupportedOperationException();
}


// 78wclwglheloye4cz6iv217tf
// static void SparseMatrix_export_coord(FILE *f, SparseMatrix A)
public static Object SparseMatrix_export_coord() {
throw new UnsupportedOperationException();
}


// 9ct1jnqtbxu8t7aek0bst7dt
// void SparseMatrix_export(FILE *f, SparseMatrix A)
public static Object SparseMatrix_export() {
throw new UnsupportedOperationException();
}


// ah8n99fv8b350xm4kavt0fxch
// SparseMatrix SparseMatrix_from_coordinate_format(SparseMatrix A)
public static Object SparseMatrix_from_coordinate_format() {
throw new UnsupportedOperationException();
}


// 3l352r526hgdwaiwvw19q36o6
// SparseMatrix SparseMatrix_from_coordinate_format_not_compacted(SparseMatrix A, int what_to_sum)
public static Object SparseMatrix_from_coordinate_format_not_compacted() {
throw new UnsupportedOperationException();
}


// 97thixddz999jxajc7eh6hgt2
// static SparseMatrix SparseMatrix_from_coordinate_arrays_internal(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz, int sum_repeated)
public static Object SparseMatrix_from_coordinate_arrays_internal() {
throw new UnsupportedOperationException();
}


// 2b42f9hg99zdasfivk4kj36ps
// SparseMatrix SparseMatrix_from_coordinate_arrays(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz)
public static Object SparseMatrix_from_coordinate_arrays() {
throw new UnsupportedOperationException();
}


// 2gmyl6k61mnhdna9qj5klp58
// SparseMatrix SparseMatrix_from_coordinate_arrays_not_compacted(int nz, int m, int n, int *irn, int *jcn, void *val0, int type, size_t sz, int what_to_sum)
public static Object SparseMatrix_from_coordinate_arrays_not_compacted() {
throw new UnsupportedOperationException();
}


// buwra6vpdrup9mq0jxnaoa9ts
// SparseMatrix SparseMatrix_add(SparseMatrix A, SparseMatrix B)
public static Object SparseMatrix_add() {
throw new UnsupportedOperationException();
}


// ad68amr2c8loydeuuxj6ahku6
// static void dense_transpose(double *v, int m, int n)
public static Object dense_transpose() {
throw new UnsupportedOperationException();
}


// 7goatbyeef0fdzc3msczi9a5d
// static void SparseMatrix_multiply_dense1(SparseMatrix A, double *v, double **res, int dim, int transposed, int res_transposed)
public static Object SparseMatrix_multiply_dense1() {
throw new UnsupportedOperationException();
}


// 1iwz608wtovpbpo8audu776ed
// static void SparseMatrix_multiply_dense2(SparseMatrix A, double *v, double **res, int dim, int transposed, int res_transposed)
public static Object SparseMatrix_multiply_dense2() {
throw new UnsupportedOperationException();
}


// 67knwqnagdj78sc1eu6rd6g14
// void SparseMatrix_multiply_dense(SparseMatrix A, int ATransposed, double *v, int vTransposed, double **res, int res_transposed, int dim)
public static Object SparseMatrix_multiply_dense() {
throw new UnsupportedOperationException();
}


// 18msncxcrufuljmww7vuhvxf1
// void SparseMatrix_multiply_vector(SparseMatrix A, double *v, double **res, int transposed)
public static Object SparseMatrix_multiply_vector() {
throw new UnsupportedOperationException();
}


// 4ccd6m8gshyov40z3l0nk8msc
// SparseMatrix SparseMatrix_scaled_by_vector(SparseMatrix A, double *v, int apply_to_row)
public static Object SparseMatrix_scaled_by_vector() {
throw new UnsupportedOperationException();
}


// 6j5uwgibisekkoc6ko7oamwhh
// SparseMatrix SparseMatrix_multiply_by_scaler(SparseMatrix A, double s)
public static Object SparseMatrix_multiply_by_scaler() {
throw new UnsupportedOperationException();
}


// br7r69cyqm4ap8lbnfnxwhk34
// SparseMatrix SparseMatrix_multiply(SparseMatrix A, SparseMatrix B)
public static Object SparseMatrix_multiply() {
throw new UnsupportedOperationException();
}


// vfxiazy7afcsf5vx62dxn9zw
// SparseMatrix SparseMatrix_multiply3(SparseMatrix A, SparseMatrix B, SparseMatrix C)
public static Object SparseMatrix_multiply3() {
throw new UnsupportedOperationException();
}


// 71nl968sq4vz7bast6tkuvj04
// SparseMatrix SparseMatrix_sum_repeat_entries(SparseMatrix A, int what_to_sum)
public static Object SparseMatrix_sum_repeat_entries() {
throw new UnsupportedOperationException();
}


// 9dnhkn8pfjolj8mw47s59zdig
// SparseMatrix SparseMatrix_coordinate_form_add_entries(SparseMatrix A, int nentries, int *irn, int *jcn, void *val)
public static Object SparseMatrix_coordinate_form_add_entries() {
throw new UnsupportedOperationException();
}


// 92ool08cuf6rtyocei4z935tf
// SparseMatrix SparseMatrix_remove_diagonal(SparseMatrix A)
public static Object SparseMatrix_remove_diagonal() {
throw new UnsupportedOperationException();
}


// 5eyr7jllwr02pvoqy4w1tvl3h
// SparseMatrix SparseMatrix_remove_upper(SparseMatrix A)
public static Object SparseMatrix_remove_upper() {
throw new UnsupportedOperationException();
}


// ceyxeyaf5wdurmreczae2481u
// SparseMatrix SparseMatrix_divide_row_by_degree(SparseMatrix A)
public static Object SparseMatrix_divide_row_by_degree() {
throw new UnsupportedOperationException();
}


// 1bfzen11d2a6qsok444bi3s00
// SparseMatrix SparseMatrix_get_real_adjacency_matrix_symmetrized(SparseMatrix A)
public static Object SparseMatrix_get_real_adjacency_matrix_symmetrized() {
throw new UnsupportedOperationException();
}


// 8hty2a3w2cqkc140x1cbidezz
// SparseMatrix SparseMatrix_normalize_to_rowsum1(SparseMatrix A)
public static Object SparseMatrix_normalize_to_rowsum1() {
throw new UnsupportedOperationException();
}


// b0s5ws25fpadqxh10574p6qtu
// SparseMatrix SparseMatrix_normalize_by_row(SparseMatrix A)
public static Object SparseMatrix_normalize_by_row() {
throw new UnsupportedOperationException();
}


// bpw0y255uveltxq1frykl8n5x
// SparseMatrix SparseMatrix_to_complex(SparseMatrix A)
public static Object SparseMatrix_to_complex() {
throw new UnsupportedOperationException();
}


// 5cfyaf92j9fkhmn7twy4hulv8
// SparseMatrix SparseMatrix_apply_fun(SparseMatrix A, double (*fun)(double x))
public static Object SparseMatrix_apply_fun() {
throw new UnsupportedOperationException();
}


// 5u8b13u5dy0s8qq50kkjak1d3
// SparseMatrix SparseMatrix_apply_fun_general(SparseMatrix A, void (*fun)(int i, int j, int n, double *x))
public static Object SparseMatrix_apply_fun_general() {
throw new UnsupportedOperationException();
}


// b51pzbr8i6zlqq9w5gki6hep1
// SparseMatrix SparseMatrix_crop(SparseMatrix A, double epsilon)
public static Object SparseMatrix_crop() {
throw new UnsupportedOperationException();
}


// 5c5ujjg3273st768r9u8ufw2t
// SparseMatrix SparseMatrix_copy(SparseMatrix A)
public static Object SparseMatrix_copy() {
throw new UnsupportedOperationException();
}


// 32fkhn433ku84sq4cu0d6fu41
// int SparseMatrix_has_diagonal(SparseMatrix A)
public static Object SparseMatrix_has_diagonal() {
throw new UnsupportedOperationException();
}


// 8nu0jtgggf5kmehfk9u9nx9cc
// void SparseMatrix_level_sets_internal(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask)
public static Object SparseMatrix_level_sets_internal() {
throw new UnsupportedOperationException();
}


// 9n9ybpcuc30wsld38mfdvqlqg
// void SparseMatrix_level_sets(SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask)
public static Object SparseMatrix_level_sets() {
throw new UnsupportedOperationException();
}


// 3bztn1hsx145gok5w7upyc6jf
// void SparseMatrix_level_sets_khops(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reinitialize_mask)
public static Object SparseMatrix_level_sets_khops() {
throw new UnsupportedOperationException();
}


// p2fdauwq23wtw310sbzdwtvf
// void SparseMatrix_weakly_connected_components(SparseMatrix A0, int *ncomp, int **comps, int **comps_ptr)
public static Object SparseMatrix_weakly_connected_components() {
throw new UnsupportedOperationException();
}


// b4f9wpzq76b1xafxf23rz82c5
// static int cmp(void*i, void*j)
public static Object cmp() {
throw new UnsupportedOperationException();
}


// aamj2n52wjichwlb1ra7ulhjb
// static int Dijkstra_internal(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max, int *mask)
public static Object Dijkstra_internal() {
throw new UnsupportedOperationException();
}


// dosnarpf7w856dl9134j4ugtj
// static int Dijkstra(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max)
public static Object Dijkstra() {
throw new UnsupportedOperationException();
}


// 5i8cxo3zjj2bfkipdaler2kr2
// static int Dijkstra_masked(SparseMatrix A, int root, double *dist, int *nlist, int *list, double *dist_max, int *mask)
public static Object Dijkstra_masked() {
throw new UnsupportedOperationException();
}


// f4d8cspdp3x1n9okxv7fre445
// double SparseMatrix_pseudo_diameter_weighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ)
public static Object SparseMatrix_pseudo_diameter_weighted() {
throw new UnsupportedOperationException();
}


// dbc9domfmqi8lximzpuc7jazm
// double SparseMatrix_pseudo_diameter_unweighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ)
public static Object SparseMatrix_pseudo_diameter_unweighted() {
throw new UnsupportedOperationException();
}


// 9c9ddm8r6gbast87qnv4q3087
// double SparseMatrix_pseudo_diameter_only(SparseMatrix A)
public static Object SparseMatrix_pseudo_diameter_only() {
throw new UnsupportedOperationException();
}


// 7cwog8a24ae270oi3q9tjjso0
// int SparseMatrix_connectedQ(SparseMatrix A0)
public static Object SparseMatrix_connectedQ() {
throw new UnsupportedOperationException();
}


// 5kkhh089wxktseyblgujkc7t6
// void SparseMatrix_decompose_to_supervariables(SparseMatrix A, int *ncluster, int **cluster, int **clusterp)
public static Object SparseMatrix_decompose_to_supervariables() {
throw new UnsupportedOperationException();
}


// 2u6myvi52vbu5jmslzurj5ofo
// SparseMatrix SparseMatrix_get_augmented(SparseMatrix A)
public static Object SparseMatrix_get_augmented() {
throw new UnsupportedOperationException();
}


// 97qcg20pzhlbj55pgkyahfvox
// SparseMatrix SparseMatrix_to_square_matrix(SparseMatrix A, int bipartite_options)
public static Object SparseMatrix_to_square_matrix() {
throw new UnsupportedOperationException();
}


// 7gfz1j0xzv3j0tk8bbgx2uvu3
// SparseMatrix SparseMatrix_get_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices)
public static Object SparseMatrix_get_submatrix() {
throw new UnsupportedOperationException();
}


// 8fujqatits67cpptpk0b4g3f1
// SparseMatrix SparseMatrix_exclude_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices)
public static Object SparseMatrix_exclude_submatrix() {
throw new UnsupportedOperationException();
}


// 3djso24sn5423zte10g6itz6z
// SparseMatrix SparseMatrix_largest_component(SparseMatrix A)
public static Object SparseMatrix_largest_component() {
throw new UnsupportedOperationException();
}


// azq1fe13ve3xc90hf4tmqo6mk
// SparseMatrix SparseMatrix_delete_sparse_columns(SparseMatrix A, int threshold, int **new2old, int *nnew, int inplace)
public static Object SparseMatrix_delete_sparse_columns() {
throw new UnsupportedOperationException();
}


// 3rj4yzq7xgkaxxe8epiz2srrb
// SparseMatrix SparseMatrix_delete_empty_columns(SparseMatrix A, int **new2old, int *nnew, int inplace)
public static Object SparseMatrix_delete_empty_columns() {
throw new UnsupportedOperationException();
}


// e0hhmx63qow45vdi8lxqzh1ye
// SparseMatrix SparseMatrix_set_entries_to_real_one(SparseMatrix A)
public static Object SparseMatrix_set_entries_to_real_one() {
throw new UnsupportedOperationException();
}


// mrxb1s4tujxot5bx52rdrav3
// SparseMatrix SparseMatrix_complement(SparseMatrix A, int undirected)
public static Object SparseMatrix_complement() {
throw new UnsupportedOperationException();
}


// b1aopjqfbg1syzk7awr4437cu
// int SparseMatrix_k_centers(SparseMatrix D0, int weighted, int K, int root, int **centers, int centering, double **dist0)
public static Object SparseMatrix_k_centers() {
throw new UnsupportedOperationException();
}


// 3ovm7y4p8nih7yy730m2wpelb
// int SparseMatrix_k_centers_user(SparseMatrix D0, int weighted, int K, int *centers_user, int centering, double **dist0)
public static Object SparseMatrix_k_centers_user() {
throw new UnsupportedOperationException();
}


// ca9yz7fnhu0wsc69dchcvyptm
// SparseMatrix SparseMatrix_from_dense(int m, int n, double *x)
public static Object SparseMatrix_from_dense() {
throw new UnsupportedOperationException();
}


// 2v8ws7lr3rk6v6qm6yxtzk4wg
// int SparseMatrix_distance_matrix(SparseMatrix D0, int weighted, double **dist0)
public static Object SparseMatrix_distance_matrix() {
throw new UnsupportedOperationException();
}


// 9dgcv5kqjzneup8rn75sefql3
// SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted)
public static Object SparseMatrix_distance_matrix_k_centers() {
throw new UnsupportedOperationException();
}


// b2xzfcw4ejdtcjz2eyn7z0kwk
// SparseMatrix SparseMatrix_distance_matrix_khops(int khops, SparseMatrix D0, int weighted)
public static Object SparseMatrix_distance_matrix_khops() {
throw new UnsupportedOperationException();
}


// 2ty13i2gqg1aekneyolyehe2e
// void SparseMatrix_page_rank(SparseMatrix A, double teleport_probablity, int weighted, double epsilon, double **page_rank)
public static Object SparseMatrix_page_rank() {
throw new UnsupportedOperationException();
}


}
