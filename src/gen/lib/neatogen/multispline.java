package gen.lib.neatogen;
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

public class multispline {
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


// 7pb9zum2n4wlgil34lvh8i0ts
// typedef double COORD


// cxblzphpetx6zzwomzstlq1n4
// typedef int DistType


// v4bpabyggw2gk3qw5qiapig9
// static boolean spline_merge(node_t * n) 
public static Object spline_merge() {
throw new UnsupportedOperationException();
}


// 90yjqn8lf9ig968uma0q5sh34
// static boolean swap_ends_p(edge_t * e) 
public static Object swap_ends_p() {
throw new UnsupportedOperationException();
}


// 300wnvw9sndobgke752j9u139
// static splineInfo sinfo = 


// 8vc4ugk3k9sijqf7rhpbdm5el
// static int cmpItem(Dt_t * d, int p1[], int p2[], Dtdisc_t * disc) 
public static Object cmpItem() {
throw new UnsupportedOperationException();
}


// 8vdhq1656ficexcr5y0milalt
// static void *newItem(Dt_t * d, item * objp, Dtdisc_t * disc) 
public static Object newItem() {
throw new UnsupportedOperationException();
}


// 9k3952c7spf98nnxwfwnp246t
// static void freeItem(Dt_t * d, item * obj, Dtdisc_t * disc) 
public static Object freeItem() {
throw new UnsupportedOperationException();
}


// c796fqhyzf7pfol298rakisbx
// static Dtdisc_t itemdisc = 


// 1y2tim1synm523oxi7qngl2k5
// static void addMap(Dt_t * map, int a, int b, int t) 
public static Object addMap() {
throw new UnsupportedOperationException();
}


// bg5u1dxahpd0vf64y3ti1tdae
// static Dt_t *mapSegToTri(surface_t * sf) 
public static Object mapSegToTri() {
throw new UnsupportedOperationException();
}


// bnrabp5s0af5jxv4xns81hnpk
// static int findMap(Dt_t * map, int a, int b) 
public static Object findMap() {
throw new UnsupportedOperationException();
}


// 1bi4rd9qwg7ja00p21oezwj29
// static int cmpIpair(Dt_t * d, int *p1, int *p2, Dtdisc_t * disc) 
public static Object cmpIpair() {
throw new UnsupportedOperationException();
}


// 9cjzvbe54yfgyj6jckv88a5dd
// static void *newIpair(Dt_t * d, Ipair * objp, Dtdisc_t * disc) 
public static Object newIpair() {
throw new UnsupportedOperationException();
}


// 9wiyfoea7uye8nxhpyh39y3jw
// static void freeIpair(Dt_t * d, Ipair * obj, Dtdisc_t * disc) 
public static Object freeIpair() {
throw new UnsupportedOperationException();
}


// 1jjsmd9wu49ffpxzb32l9uwwh
// static Dtdisc_t ipairdisc = 


// 9mm13pgy4999ocg5yq7iafndo
// static void vmapAdd(Dt_t * map, int i, int j) 
public static Object vmapAdd() {
throw new UnsupportedOperationException();
}


// 7w86kzjcu06i5ga86uob9zmc4
// static int vMap(Dt_t * map, int i) 
public static Object vMap() {
throw new UnsupportedOperationException();
}


// 9oict9jd8asy9l8ow2qkxxxlo
// static void mapTri(Dt_t * map, tri * tp) 
public static Object mapTri() {
throw new UnsupportedOperationException();
}


// 9l8t6g1p301lsto1t0ngyhbp6
// static tri * addTri(int i, int j, tri * oldp) 
public static Object addTri() {
throw new UnsupportedOperationException();
}


// dssy8dg06bmyctebz78t40ni3
// static double bisect(pointf pp, pointf cp, pointf np) 
public static Object bisect() {
throw new UnsupportedOperationException();
}


// cpc5zerbuuqphdniz037ke7gt
// static int raySeg(pointf v, pointf w, pointf a, pointf b) 
public static Object raySeg() {
throw new UnsupportedOperationException();
}


// jzhb0t8t5vha953lrja4lqf5
// static int raySegIntersect(pointf v, pointf w, pointf a, pointf b, pointf * p) 
public static Object raySegIntersect() {
throw new UnsupportedOperationException();
}


// ehb3ox2nwbfeco68ppimgtnzl
// static int triPoint(tripoly_t * trip, int vx, pointf v, pointf w, pointf * ip) 
public static Object triPoint() {
throw new UnsupportedOperationException();
}


// 1ihdzbn7xz9ca0js7z3ezjsjh
// static int ctrlPtIdx(pointf v, Ppoly_t * polys) 
public static Object ctrlPtIdx() {
throw new UnsupportedOperationException();
}


// ax9hf5z886vk3xgmx9u4i1bjd
// static pointf *mkCtrlPts(int s, int mult, pointf prev, pointf v, 			   pointf nxt, tripoly_t * trip) 
public static Object mkCtrlPts() {
throw new UnsupportedOperationException();
}


// 6n1342edzj71w304zjoti6jfd
// static pointf triCenter(pointf * pts, int *idxs) 
public static Object triCenter() {
throw new UnsupportedOperationException();
}


// 47g56l1g53zrkf6h6nq1fg0pd
// static boxf bbox(Ppoly_t** obsp, int npoly, int *np) 
public static Object bbox() {
throw new UnsupportedOperationException();
}


// 1x0uufu7w6y6zr21b4i8j5m93
// static int *mkTriIndices(surface_t * sf) 
public static Object mkTriIndices() {
throw new UnsupportedOperationException();
}


// aoa10qzctgrayzf0jm3c3cef8
// static int degT(int *ip) 
public static Object degT() {
throw new UnsupportedOperationException();
}


// e6ba0j62efqz3hdmcu12u7v83
// static ipair sharedEdge(int *p, int *q) 
public static Object sharedEdge() {
throw new UnsupportedOperationException();
}


// 3z1p14gctmby7bmtp7me9uf9f
// static void addTriEdge(tgraph * g, int t, int h, double d, ipair seg) 
public static Object addTriEdge() {
throw new UnsupportedOperationException();
}


// d89tctbdtolgi6tus95diid7h
// static void freeTriGraph(tgraph * tg) 
public static Object freeTriGraph() {
throw new UnsupportedOperationException();
}


// c9f1pw23rdnlr5kkchuqpvzxl
// static tgraph *mkTriGraph(surface_t * sf, int maxv, pointf * pts) 
public static Object mkTriGraph() {
throw new UnsupportedOperationException();
}


// 291fdzjy9n5nql8yua1atcqo5
// void freeRouter(router_t * rtr) 
public static Object freeRouter() {
throw new UnsupportedOperationException();
}


// 3z8ti92qblhuh6uxtj8x06i62
// router_t *mkRouter(Ppoly_t** obsp, int npoly) 
public static Object mkRouter() {
throw new UnsupportedOperationException();
}


// 1e691v1hgu8czlo4wusvm6f92
// static void finishEdge (graph_t* g, edge_t* e, Ppoly_t spl, int flip, pointf p, pointf q) 
public static Object finishEdge() {
throw new UnsupportedOperationException();
}


// cy8uvo8tlq62rcapcnfc92cyt
// static Ppoint_t tweakEnd (Ppoly_t poly, int s, Ppolyline_t pl, Ppoint_t q) 
public static Object tweakEnd() {
throw new UnsupportedOperationException();
}


// dw2w4qgm8zb36nlxzzjkp3tws
// static void tweakPath (Ppoly_t poly, int s, int t, Ppolyline_t pl) 
public static Object tweakPath() {
throw new UnsupportedOperationException();
}


// encr96670q4dep98c96a13rsn
// static int  genroute(graph_t* g, tripoly_t * trip, int s, int t, edge_t * e, int doPolyline) 
public static Object genroute() {
throw new UnsupportedOperationException();
}


// c9h0ir0lqi88ag17xcdo4b6jx
// static int inCone (pointf a, pointf b, pointf c, pointf q) 
public static Object inCone() {
throw new UnsupportedOperationException();
}


// 6fimbmdbn7firtfjcb7obnfqa
// static pointf north = 


// erpg0qczolxbetkrjtyp3dyjh
// static pointf northeast = 


// 9k1m7aqusr3gt4l0ka2eczj7
// static pointf east = 


// 55w9gzjskc66k55w3y13il5hq
// static pointf southeast = 


// a1h0sqxlo4p028u45s6b4ntmn
// static pointf south = 


// 1gmutmzstbx26ui7z7lhsoxdz
// static pointf southwest = 


// 4lej6spyktnbq1wwsxr238uhl
// static pointf west = 


// 593h93olz471ny963ui3hor0u
// static pointf northwest = 


// 6ucxt4su34a6lhgmzbroeaoah
// static void addEndpoint(router_t * rtr, pointf p, node_t* v, int v_id, int sides) 
public static Object addEndpoint() {
throw new UnsupportedOperationException();
}


// 32pve5n9dhm1o9wc19nnsrnl0
// static ipair edgeToSeg(tgraph * tg, int i, int j) 
public static Object edgeToSeg() {
throw new UnsupportedOperationException();
}


// lhpvb9osrpc6b85d9129zxdz
// static void freeTripoly (tripoly_t* trip) 
public static Object freeTripoly() {
throw new UnsupportedOperationException();
}


// 6u8byl1w95pg232loarxjv8ay
// static tripoly_t *mkPoly(router_t * rtr, int *dad, int s, int t, 			 pointf p_s, pointf p_t, int *sx) 
public static Object mkPoly() {
throw new UnsupportedOperationException();
}


// 87iq0mx2131qliz3g8y07hg2x
// static void resetGraph(tgraph * g, int ncnt, int ecnt) 
public static Object resetGraph() {
throw new UnsupportedOperationException();
}


// ebp3jcv3rmjmssiel8gubvbiv
// static void PQgen(PQ* pq, int sz, int guard) 
public static Object PQgen() {
throw new UnsupportedOperationException();
}


// 3u25r04kzv2l7ru0agcw2ifpw
// static void PQfree(PQ* pq, int freeAll) 
public static Object PQfree() {
throw new UnsupportedOperationException();
}


// 63h4ihx5i74r0m9xgu505x2v5
// static void PQinit(PQ* pq) 
public static Object PQinit() {
throw new UnsupportedOperationException();
}


// 484csjbkd5rfvnxw1o21payhg
// static void PQupheap(PQ* ppq, int k) 
public static Object PQupheap() {
throw new UnsupportedOperationException();
}


// beia8h7nrkkaycei66jdlc9q8
// static int PQinsert(PQ* pq, int np) 
public static Object PQinsert() {
throw new UnsupportedOperationException();
}


// 4g8aqrn9rj0sosddyoxqwtfht
// static void PQdownheap (PQ* ppq, int k) 
public static Object PQdownheap() {
throw new UnsupportedOperationException();
}


// 1ant14sbi1zx4ygei34q5l7ok
// static int PQremove (PQ* pq) 
public static Object PQremove() {
throw new UnsupportedOperationException();
}


// echptk5hfmtdcr28hw8u38xg
// static void PQupdate (PQ* pq, int n, float d) 
public static Object PQupdate() {
throw new UnsupportedOperationException();
}


// ekk27g6b722j6yjme89kacsxr
// static int * triPath(tgraph * g, int n, int v0, int v1, PQ * pq) 
public static Object triPath() {
throw new UnsupportedOperationException();
}


// 5wbb1ldatl50vfhg97u42sigh
// int makeMultiSpline(graph_t* g,  edge_t* e, router_t * rtr, int doPolyline) 
public static Object makeMultiSpline() {
throw new UnsupportedOperationException();
}


}
