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

public class rank {
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


// 3f1re3nfkhxwjjb90kppwuupr
// static void  renewlist(elist * L) 
public static Object renewlist() {
throw new UnsupportedOperationException();
}


// a1wxlfiopbjgk9xfxi81gdqo5
// static void  cleanup1(graph_t * g) 
public static Object cleanup1() {
throw new UnsupportedOperationException();
}


// dylfs8k6dtnycwxiinoni6vyj
// static void  edgelabel_ranks(graph_t * g) 
public static Object edgelabel_ranks() {
throw new UnsupportedOperationException();
}


// djgsdrjq72n0iphwu67e53i0e
// static void  collapse_rankset(graph_t * g, graph_t * subg, int kind) 
public static Object collapse_rankset() {
throw new UnsupportedOperationException();
}


// alnlb3s3zx95k3971ewq85zqc
// static int  rank_set_class(graph_t * g) 
public static Object rank_set_class() {
throw new UnsupportedOperationException();
}


// 791xdrwo32o4ihdfsv5rlssav
// static int  make_new_cluster(graph_t * g, graph_t * subg) 
public static Object make_new_cluster() {
throw new UnsupportedOperationException();
}


// 7q92zkqlgxa4ae8gg08c3cmnl
// static void  node_induce(graph_t * par, graph_t * g) 
public static Object node_induce() {
throw new UnsupportedOperationException();
}


// dikocruauvitd3kdxxk8clm77
// void  dot_scan_ranks(graph_t * g) 
public static Object dot_scan_ranks() {
throw new UnsupportedOperationException();
}


// cnmt44k4mu9bbpzrgdbpktii8
// static void cluster_leader(graph_t * clust) 
public static Object cluster_leader() {
throw new UnsupportedOperationException();
}


// m33tjvtppaap5aembwhdi648
// static void  collapse_cluster(graph_t * g, graph_t * subg) 
public static Object collapse_cluster() {
throw new UnsupportedOperationException();
}


// din4qnipewrwnelaimzvlplft
// static void  collapse_sets(graph_t *rg, graph_t *g) 
public static Object collapse_sets() {
throw new UnsupportedOperationException();
}


// 1fqnomw2rbqls0u4gaf6oay5a
// static void  find_clusters(graph_t * g) 
public static Object find_clusters() {
throw new UnsupportedOperationException();
}


// 59098tuvzkw6a3lnxcbsf6d7k
// static void  set_minmax(graph_t * g) 
public static Object set_minmax() {
throw new UnsupportedOperationException();
}


// 8ww8y9sg9gn638z77q1actyuh
// static point  minmax_edges(graph_t * g) 
public static Object minmax_edges() {
throw new UnsupportedOperationException();
}


// anx6sbl44o53wabchk8ewte0i
// static int  minmax_edges2(graph_t * g, point slen) 
public static Object minmax_edges2() {
throw new UnsupportedOperationException();
}


// djl4v8frt0dkeuw2rg94layl8
// void rank1(graph_t * g) 
public static Object rank1() {
throw new UnsupportedOperationException();
}


// 88wpr4mkjbf2qq0yh994tzvr3
// static void expand_ranksets(graph_t * g, aspect_t* asp) 
public static Object expand_ranksets() {
throw new UnsupportedOperationException();
}


// 29rif7lc0for2nb6cj7azqbzl
// static void dot1_rank(graph_t * g, aspect_t* asp) 
public static Object dot1_rank() {
throw new UnsupportedOperationException();
}


// vobm5sc77zkstqr0ixnxb7bd
// void dot_rank(graph_t * g, aspect_t* asp) 
public static Object dot_rank() {
throw new UnsupportedOperationException();
}


// cdncou6d2ng5i48rd1mk2cpnw
// int is_cluster(graph_t * g) 
public static Object is_cluster() {
throw new UnsupportedOperationException();
}


// 851iyejmufpvln0s8uwq8w0s2
// static void set_parent(graph_t* g, graph_t* p)  
public static Object set_parent() {
throw new UnsupportedOperationException();
}


// 3qlca4afaxtwu0r2v22ccpfy9
// static int is_empty(graph_t * g) 
public static Object is_empty() {
throw new UnsupportedOperationException();
}


// sxmrpf4e3wi4vzeiu486heyw
// static int is_a_strong_cluster(graph_t * g) 
public static Object is_a_strong_cluster() {
throw new UnsupportedOperationException();
}


// 954bo7mrh993f96ujb8u3e8vt
// static int rankset_kind(graph_t * g) 
public static Object rankset_kind() {
throw new UnsupportedOperationException();
}


// cpi6hrz9w51mz9x4li9fvyttb
// static int is_nonconstraint(edge_t * e) 
public static Object is_nonconstraint() {
throw new UnsupportedOperationException();
}


// 569wkr6f7hjyi0jyga0xjlqjt
// static node_t *find(node_t * n) 
public static Object find() {
throw new UnsupportedOperationException();
}


// 6xfkmj0kt3y5l8ka8afdygn8u
// static node_t *union_one(node_t * leader, node_t * n) 
public static Object union_one() {
throw new UnsupportedOperationException();
}


// 1ku7zqljp4yk6j8pqxa19ko4u
// static node_t *union_all(graph_t * g) 
public static Object union_all() {
throw new UnsupportedOperationException();
}


// w3iwej2e16lvft2p49zhvwau
// static void compile_samerank(graph_t * ug, graph_t * parent_clust) 
public static Object compile_samerank() {
throw new UnsupportedOperationException();
}


// 7vi8bdall9uci6ildcjl589gr
// static graph_t *dot_lca(graph_t * c0, graph_t * c1) 
public static Object dot_lca() {
throw new UnsupportedOperationException();
}


// bw8swhp1fmikhnc1f9z551lfm
// static int is_internal_to_cluster(edge_t * e) 
public static Object is_internal_to_cluster() {
throw new UnsupportedOperationException();
}


// ca279jzn1n2k40bv7mz55ccx7
// static node_t* Last_node


// 38ud520bzgntfnt1kus080yya
// static node_t* makeXnode (graph_t* G, char* name) 
public static Object makeXnode() {
throw new UnsupportedOperationException();
}


// 45yy5398m5v9v9iepc6uwk9qh
// static void compile_nodes(graph_t * g, graph_t * Xg) 
public static Object compile_nodes() {
throw new UnsupportedOperationException();
}


// 9n0sxbb8eni6r5hueeoh6pis2
// static void merge(edge_t * e, int minlen, int weight) 
public static Object merge() {
throw new UnsupportedOperationException();
}


// d3ylz94v4q7s6ul3wlqud4ucc
// static void strong(graph_t * g, node_t * t, node_t * h, edge_t * orig) 
public static Object strong() {
throw new UnsupportedOperationException();
}


// 8j4mmib3qk2jwnyfm5ybbcdzc
// static void weak(graph_t * g, node_t * t, node_t * h, edge_t * orig) 
public static Object weak() {
throw new UnsupportedOperationException();
}


// 6t9gmvd4tkkhvs1rhihxq92bf
// static void compile_edges(graph_t * ug, graph_t * Xg) 
public static Object compile_edges() {
throw new UnsupportedOperationException();
}


// ed8wgj99tmnie97hlfx0v723e
// static void compile_clusters(graph_t* g, graph_t* Xg, node_t* top, node_t* bot) 
public static Object compile_clusters() {
throw new UnsupportedOperationException();
}


// e4ctpz0a1yyr4tvga6ma51ftp
// static void reverse_edge2(graph_t * g, edge_t * e) 
public static Object reverse_edge2() {
throw new UnsupportedOperationException();
}


// 1e1xbvgpysqh5hpdaszuare7i
// static void dfs(graph_t * g, node_t * v) 
public static Object dfs() {
throw new UnsupportedOperationException();
}


// blprzafhikmbp7vdckfvc5a3j
// static void break_cycles(graph_t * g) 
public static Object break_cycles() {
throw new UnsupportedOperationException();
}


// 1g1m57tqhopxl7bbdu7gciez9
// static void setMinMax (graph_t* g, int doRoot) 
public static Object setMinMax() {
throw new UnsupportedOperationException();
}


// d1mlvum6fwt15hihqz22qt1zi
// static void readout_levels(graph_t * g, graph_t * Xg, int ncc) 
public static Object readout_levels() {
throw new UnsupportedOperationException();
}


// p008ueai8f0vc4fzr9ipek42
// static void dfscc(graph_t * g, node_t * n, int cc) 
public static Object dfscc() {
throw new UnsupportedOperationException();
}


// rskyvxjog04xtcbc5kdd9bsw
// static int connect_components(graph_t * g) 
public static Object connect_components() {
throw new UnsupportedOperationException();
}


// 3pylrmuxz6idymuvd57pdsznu
// static void add_fast_edges (graph_t * g) 
public static Object add_fast_edges() {
throw new UnsupportedOperationException();
}


// bqe4klbp1rwdt0u7tzl4qhssv
// static void my_init_graph(Agraph_t *g, Agobj_t *graph, void *arg) 
public static Object my_init_graph() {
throw new UnsupportedOperationException();
}


// 5uqmxqvweno9it2s7rb5mu0hr
// static void my_init_node(Agraph_t *g, Agobj_t *node, void *arg) 
public static Object my_init_node() {
throw new UnsupportedOperationException();
}


// bhdzcucectq45m9frrw105n34
// static void my_init_edge(Agraph_t *g, Agobj_t *edge, void *arg) 
public static Object my_init_edge() {
throw new UnsupportedOperationException();
}


// 46nx7przjp7fn42o28hqdaj9k
// static Agcbdisc_t mydisc = 


// 9quqxw3oujl7u6bymimr5be7t
// int infosizes[] = 


// iqc4nqpcqx8k7gjf334x1m64
// void dot2_rank(graph_t * g, aspect_t* asp) 
public static Object dot2_rank() {
throw new UnsupportedOperationException();
}


}
