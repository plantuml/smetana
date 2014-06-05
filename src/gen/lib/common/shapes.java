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

public class shapes {
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


// 8h06z4a8bluhfqji3ysnlr3q8
// static port Center = 


// ankops6rt7vi2sp8uptwl13x8
// static char *point_style[3] = 


// bdp4y4mfwmo49z2gqqtn77uhl
// static poly_desc_t star_gen = 


// wr8d5qdzgrixltx1i3jol1p
// static polygon_t p_polygon = 


// 606ee1uued1p0d2o7h96efu9d
// static polygon_t p_ellipse = 


// 3q65p9gs6dv6ie2edejj1vy8l
// static polygon_t p_circle = 


// ugo4ltv5o559q27tqn3r5bkl
// static polygon_t p_egg = 


// 9ftn1ffly0e6ffwzth9q47uz1
// static polygon_t p_triangle = 


// bw9fxu2ppyosdc0fayd10ik29
// static polygon_t p_box = 


// lz1wo6e9iq0idhf5e6ztlb8b
// static polygon_t p_square = 


// cd8ymd9cpth6be42bx9hneg3k
// static polygon_t p_plaintext = 


// 3rr68w4p4ndvjnd8v8t8kyvof
// static polygon_t p_diamond = 


// 2vq6zitonpglah4otrj51bc
// static polygon_t p_trapezium = 


// 1cmprhux7ohd0kvyuccronajx
// static polygon_t p_parallelogram = 


// cviu1ws3i3zudpmfyw9qde1g
// static polygon_t p_house = 


// a2801adj9tjun8kavpqhec32e
// static polygon_t p_pentagon = 


// bqxkc5i7w4qux0yj6fcvk6i3j
// static polygon_t p_hexagon = 


// 9dfxrmf5irbiyglpnjva9shjs
// static polygon_t p_septagon = 


// 8dintdmurw1k99hvel0eylkx
// static polygon_t p_octagon = 


// u1t73h3kmbe3dl3nesrd3lli
// static polygon_t p_note = 


// 7rueooxoen3szgjos715fhyug
// static polygon_t p_tab = 


// 96p5brfwqh960bh90nko57q5y
// static polygon_t p_folder = 


// asszwikv8vsd8r82g9g2dpib0
// static polygon_t p_box3d = 


// 6svqv9h6e8w1upvle3kvqalpz
// static polygon_t p_component = 


// eupkzejle0xh3lxkum31v0cym
// static polygon_t p_underline = 


// 1tvtcrvtnr7rxzgndqgbvn1y0
// static polygon_t p_doublecircle = 


// bnqceu0ie276qgntzbxk8rasy
// static polygon_t p_invtriangle = 


// b4qh6rkxlk3dhq3za50nz70g9
// static polygon_t p_invtrapezium = 


// 6975h7vqnuq4k5wgxu223q48a
// static polygon_t p_invhouse = 


// 1y504l91pfltem8lf4b9yugmh
// static polygon_t p_doubleoctagon = 


// dejwm44vd6au8zngxmnsctb6h
// static polygon_t p_tripleoctagon = 


// cm0diez4xczfsq1e49z5xyx9l
// static polygon_t p_Mdiamond =     


// 5l5tx9j7g4auyutgbnyrxl1bn
// static polygon_t p_Msquare = 


// rau0c72n4b3s1vtavgq2ugtx
// static polygon_t p_Mcircle =     


// 8w3de46truvv9a11sqxbzi3gd
// static polygon_t p_star = 


// 2q69w7roanbt7ldossjvr2zpp
// static polygon_t p_promoter = 


// 8lsvyuy90dk6sxfcfd1g751u5
// static polygon_t p_cds = 


// 73gtceras7h3x5rqur5zh20pm
// static polygon_t p_terminator = 


// 1ggglfhw5mb7uo3xo8fjy78ly
// static polygon_t p_utr = 


// 88ze1f92hnc02v5rtzevj6laf
// static polygon_t p_insulator = 


// 4gnk4h7twwbbkfsm2v2z5kpm3
// static polygon_t p_ribosite = 


// 9p4ragp400660i10e7kw35j6h
// static polygon_t p_rnastab = 


// cj4q7wai5wonk0e937ggwye7a
// static polygon_t p_proteasesite = 


// cyxbjzhf18t5oktxygjnjdzvr
// static polygon_t p_proteinstab = 


// 9ddzvwdbr4wdohmir5y8a0fvd
// static polygon_t p_primersite = 


// 9istclblyhg67yp72g9xs9bwg
// static polygon_t p_restrictionsite = 


// 11kgrzyf2g5uc9sq4sbrd2smb
// static polygon_t p_fivepoverhang = 


// 6wf3da8bdlf8f8mo2u6czpmh0
// static polygon_t p_threepoverhang = 


// 97vug445f04zvds36aoa0xylg
// static polygon_t p_noverhang = 


// 86ma4kod9amw5w024mnxyhfkj
// static polygon_t p_assembly = 


// 23k9m2gdw1fj7q7pdlrcsawl2
// static polygon_t p_signature = 


// ab97s73vl8iehclhx49x8wby5
// static polygon_t p_rpromoter = 


// 1vm63ixobrd8mt967caec1jb
// static polygon_t p_rarrow = 


// 7k1qamsg50xfpik4fmzl26vs1
// static polygon_t p_larrow = 


// 659vs9ww96a1ojqko4w4ezt71
// static polygon_t p_lpromoter = 


// dkgul6r2xulzqk2twms3pswmy
// static shape_functions poly_fns = 


// 10ii4j68l49hzbm38qspv8azn
// static shape_functions point_fns = 


// dkmcmdu75stv4q1ti875sba5e
// static shape_functions record_fns = 


// 4im5kxw9mpwlfxnlet8fn1lbb
// static shape_functions epsf_fns = 


// 6hffa4ola6av0i6ls8q0b11fp
// static shape_functions star_fns = 


// dkylqbkoarh3lf3lwhnbg2k6n
// static shape_desc Shapes[] = 


// a7copj498to9ai2kxtg728mex
// static void unrecognized(node_t * n, char *p) 
public static Object unrecognized() {
throw new UnsupportedOperationException();
}


// 1nifps8w2xj8fe3s0e934h9oo
// static double quant(double val, double q) 
public static Object quant() {
throw new UnsupportedOperationException();
}


// eb4jyrh981apg1fy13fczexdl
// static int same_side(pointf p0, pointf p1, pointf L0, pointf L1) 
public static Object same_side() {
throw new UnsupportedOperationException();
}


// 52h7f4vpu1pj6fqh78wme87uk
// static char* penColor(GVJ_t * job, node_t * n) 
public static Object penColor() {
throw new UnsupportedOperationException();
}


// 7nofo7jo7hj6ehl6tswgfwzif
// static char *findFillDflt(node_t * n, char *dflt) 
public static Object findFillDflt() {
throw new UnsupportedOperationException();
}


// dkh0fr3loytegfs1lz9qi1sd6
// static char *findFill(node_t * n) 
public static Object findFill() {
throw new UnsupportedOperationException();
}


// b6vz4rofh7tr27tzdul6mqinz
// char *findAttrColor(void *obj, attrsym_t *colorattr, char *dflt)
public static Object findAttrColor() {
throw new UnsupportedOperationException();
}


// 1dl8bzyvmof03js7h3zqgfcc3
// static int isBox (node_t* n) 
public static Object isBox() {
throw new UnsupportedOperationException();
}


// 482hlgjq089we8nc051el1h3k
// static int isEllipse(node_t* n) 
public static Object isEllipse() {
throw new UnsupportedOperationException();
}


// cdyy8tr19fdlxisxvdcrecg27
// static char **checkStyle(node_t * n, int *flagp) 
public static Object checkStyle() {
throw new UnsupportedOperationException();
}


// cmfha87baduerx07enpoxpl0i
// static int stylenode(GVJ_t * job, node_t * n) 
public static Object stylenode() {
throw new UnsupportedOperationException();
}


// 3n19zgxsl4wm5gvdm5nj4dghe
// static void Mcircle_hack(GVJ_t * job, node_t * n) 
public static Object Mcircle_hack() {
throw new UnsupportedOperationException();
}


// 1cmpbzoqxcwx57irlmng4h9qw
// void round_corners(GVJ_t * job, pointf * AF, int sides, int style, int filled) 
public static Object round_corners() {
throw new UnsupportedOperationException();
}


// 7m3easr7j3ewwfbughm674yly
// static double userSize(node_t * n) 
public static Object userSize() {
throw new UnsupportedOperationException();
}


// anh1th1ynemqn04azv1v3em2p
// shape_kind shapeOf(node_t * n) 
public static Object shapeOf() {
throw new UnsupportedOperationException();
}


// a12mkza5hvccm3pz6z22cc8
// boolean isPolygon(node_t * n) 
public static Object isPolygon() {
throw new UnsupportedOperationException();
}


// myosi9lovpkz5wj56r1q13v7
// static void poly_init(node_t * n) 
public static Object poly_init() {
throw new UnsupportedOperationException();
}


// ci5m195sqm3z9uwg75qdqhliq
// static void poly_free(node_t * n) 
public static Object poly_free() {
throw new UnsupportedOperationException();
}


// 5nyqql1ectv3f2ltnidzz76kq
// static boolean poly_inside(inside_t * inside_context, pointf p) 
public static Object poly_inside() {
throw new UnsupportedOperationException();
}


// e3vrtp30e32722jqpobclfvpa
// static int poly_path(node_t * n, port * p, int side, boxf rv[], int *kptr) 
public static Object poly_path() {
throw new UnsupportedOperationException();
}


// 857i3hwbu9mbq4nwur2q7e7er
// static int invflip_side(int side, int rankdir) 
public static Object invflip_side() {
throw new UnsupportedOperationException();
}


// 5ptvcwll196bmz7p1orb71fs0
// static double invflip_angle(double angle, int rankdir) 
public static Object invflip_angle() {
throw new UnsupportedOperationException();
}


// 4sz7iz6c0h7i5b45hj3vn78jh
// static pointf compassPoint(inside_t * ictxt, double y, double x) 
public static Object compassPoint() {
throw new UnsupportedOperationException();
}


// ahbvociakwgc4bbfpz8tikzl2
// static int compassPort(node_t * n, boxf * bp, port * pp, char *compass, int sides, 	    inside_t * ictxt) 
public static Object compassPort() {
throw new UnsupportedOperationException();
}


// 5x35nshvfa1sczw13h9ne940s
// static port poly_port(node_t * n, char *portname, char *compass) 
public static Object poly_port() {
throw new UnsupportedOperationException();
}


// 45aafwf8y1q18mmvjbswl28tw
// static void poly_gencode(GVJ_t * job, node_t * n) 
public static Object poly_gencode() {
throw new UnsupportedOperationException();
}


// 3v9fuzxri44ef6ekywvu011x6
// static void point_init(node_t * n) 
public static Object point_init() {
throw new UnsupportedOperationException();
}


// 296yjgpbgtc07o12mj8j05a6w
// static boolean point_inside(inside_t * inside_context, pointf p) 
public static Object point_inside() {
throw new UnsupportedOperationException();
}


// 5fjuwjjmhf7nj8xoqu6yriqyu
// static void point_gencode(GVJ_t * job, node_t * n) 
public static Object point_gencode() {
throw new UnsupportedOperationException();
}


// 7tslf55o9g8v48j97pdsyich9
// static char *reclblp


// 1dflsvfaih0mcg1gg4n23v1rg
// static void free_field(field_t * f) 
public static Object free_field() {
throw new UnsupportedOperationException();
}


// e9v6g9o3uouhdvy68a5uiisw9
// static field_t *parse_error(field_t * rv, char *port) 
public static Object parse_error() {
throw new UnsupportedOperationException();
}


// 3ex08zq5j43b1kw4dksqig30p
// static field_t *parse_reclbl(node_t * n, int LR, int flag, char *text) 
public static Object parse_reclbl() {
throw new UnsupportedOperationException();
}


// 7eyjjpbva3bk5l9n12oqe7kuq
// static pointf size_reclbl(node_t * n, field_t * f) 
public static Object size_reclbl() {
throw new UnsupportedOperationException();
}


// blo8etwhtlcsld8ox0vryznfw
// static void resize_reclbl(field_t * f, pointf sz, int nojustify_p) 
public static Object resize_reclbl() {
throw new UnsupportedOperationException();
}


// ds4v2i9xw0hm4y53ggbt8z2yk
// static void pos_reclbl(field_t * f, pointf ul, int sides) 
public static Object pos_reclbl() {
throw new UnsupportedOperationException();
}


// 3dr506gsi1qy093n0cw3ffm0n
// static void record_init(node_t * n) 
public static Object record_init() {
throw new UnsupportedOperationException();
}


// 6ehylpxgd0q8wdzb0mkxqx2tp
// static void record_free(node_t * n) 
public static Object record_free() {
throw new UnsupportedOperationException();
}


// a005gfg4ujp2d29bpdrtowla0
// static field_t *map_rec_port(field_t * f, char *str) 
public static Object map_rec_port() {
throw new UnsupportedOperationException();
}


// b1aevbfrixuozm90y9pv7tp95
// static port record_port(node_t * n, char *portname, char *compass) 
public static Object record_port() {
throw new UnsupportedOperationException();
}


// 8m4h94tcymloljjps93h75qyd
// static boolean record_inside(inside_t * inside_context, pointf p) 
public static Object record_inside() {
throw new UnsupportedOperationException();
}


// 6fbabungsspcfxq5k98082t4p
// static int record_path(node_t * n, port * prt, int side, boxf rv[], 		       int *kptr) 
public static Object record_path() {
throw new UnsupportedOperationException();
}


// 2t3jwt9h9lesyhrifhvl18ki7
// static void gen_fields(GVJ_t * job, node_t * n, field_t * f) 
public static Object gen_fields() {
throw new UnsupportedOperationException();
}


// duz84u0066h4po3q1ngkz4qj5
// static void record_gencode(GVJ_t * job, node_t * n) 
public static Object record_gencode() {
throw new UnsupportedOperationException();
}


// 7unoy39g6rhro6he8kci7oh4n
// static shape_desc **UserShape


// 94927xsjiykujshql95ma97vb
// static int N_UserShape


// 35sn43hohjmtc7uvkjrx6u7jt
// shape_desc *find_user_shape(const char *name) 
public static Object find_user_shape() {
throw new UnsupportedOperationException();
}


// boykq7gso3qitsu1b1a4pgb2x
// static shape_desc *user_shape(char *name) 
public static Object user_shape() {
throw new UnsupportedOperationException();
}


// bmt148wdf0a7gslm7hmp043jy
// shape_desc *bind_shape(char *name, node_t * np) 
public static Object bind_shape() {
throw new UnsupportedOperationException();
}


// 76cvybnt82wjsdhwhzgl0uy1r
// static boolean epsf_inside(inside_t * inside_context, pointf p) 
public static Object epsf_inside() {
throw new UnsupportedOperationException();
}


// epe70bj28xr7vn2t0d89mfltg
// static void epsf_gencode(GVJ_t * job, node_t * n) 
public static Object epsf_gencode() {
throw new UnsupportedOperationException();
}


// d3qs3yyfczeqg7vew6ttlnjmx
// static pointf star_size (pointf sz0) 
public static Object star_size() {
throw new UnsupportedOperationException();
}


// ctj0rvp5kmhx4b0qoiu46onc5
// static void star_vertices (pointf* vertices, pointf* bb) 
public static Object star_vertices() {
throw new UnsupportedOperationException();
}


// 8wq3wcoq3jrk0da4fc6pom7s4
// static boolean star_inside(inside_t * inside_context, pointf p) 
public static Object star_inside() {
throw new UnsupportedOperationException();
}


// 7nso0aprwwsa0je3az7h9nlue
// static char *side_port[] = 


// 3xwj3dmssm9fg2vm9dl6cocri
// static point cvtPt(pointf p, int rankdir) 
public static Object cvtPt() {
throw new UnsupportedOperationException();
}


// a80nyygm6am7eo5j01fw2orqk
// static char *closestSide(node_t * n, node_t * other, port * oldport) 
public static Object closestSide() {
throw new UnsupportedOperationException();
}


// ckbg1dyu9jzx7g0c9dbriez7r
// port resolvePort(node_t * n, node_t * other, port * oldport) 
public static Object resolvePort() {
throw new UnsupportedOperationException();
}


// ec3wx11crbw95kkpkzvbv0m7f
// void resolvePorts(edge_t * e) 
public static Object resolvePorts() {
throw new UnsupportedOperationException();
}


}
