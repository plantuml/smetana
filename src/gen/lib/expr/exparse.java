package gen.lib.expr;
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

public class exparse {
// 6247rjm5arbcnf5n19lxltxou
// 1 extern ssize_t _Sfi


// 6511pirva7easf3janoodcfwl
// extern Sfio_t *sfstdin


// 4cz9ak8ijas38szhumiyn3ykw
// extern Sfio_t *sfstdout


// 6hew0sj0og4plpyw3jv5yhyfs
// extern Sfio_t *sfstderr


// 5e2qwjlsxr0wq7lkkd6403199
// extern Sfio_t _Sfstdin


// 42bmgpi1ju4cr6klvsb7nbc4x
// extern Sfio_t _Sfstdout


// dztq0m39npdtavex0zuyvv65i
// extern Sfio_t _Sfstderr


// 83a1zu2el049lzgamfy0wo7ye
// typedef unsigned long ALIGN_INTEGRAL


// 51kvqjcldcl26v6sg1onapbir
// extern int exdebug


// 3tpuf2oqoz7i3etzl3dolchwb
// extern EXSTYPE exlval


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


// b72fu9evklskcqilwrdq12o5r
// extern Vmethod_t *Vmbest


// 871rdt059w054qrprts4wvgq1
// extern Vmethod_t *Vmlast


// 8z54qqt9gbzggws03cxsoobsg
// extern Vmethod_t *Vmpool


// 266p34tln76068xbbouutkmbv
// extern Vmethod_t *Vmdebug


// 4kllxxym6x9urhncqv5hhvro
// extern Vmethod_t *Vmprofile


// aas870dijub96f1yjk9wgby2j
// extern Vmdisc_t *Vmdcheap


// 1psbprx5glmkml7dkf5aj5zi6
// extern Vmdisc_t *Vmdcsbrk


// bndxxcipli6lautlm61gvyf55
// extern Vmalloc_t *Vmheap


// nnfafgaguj139vfpong892sw
// extern Vmalloc_t *Vmregion


// 9dai0bai06emckm350qgu2s89
// typedef short Exshort_t


// 3691phrqqrb4ygjieer6hxbjb
// typedef EXSTYPE Extype_t


// eami7o5wilrcavvnh6jun3a9z
// extern Error_info_t _err_info


// 5v5exc52zca1xxlyo7tltwmq8
// extern Exid_t		exbuiltin[]


// 1za9p6746etlrghp0at63l157
// extern const char*	exversion


// 76cfuu7shwxqrb8epon584v4z
// extern Exstate_t	expr


// 35shbriyw6nbtgq2n8kz61cfd
// static int		a2t[] = 


// 8ilouxu9xtr2f1cy6do0uogj7
// static Switch_t		swstate


// ev3agj0kjg0luq631l10r1d50
// Exstate_t		expr


// cgrmowzpwmmecwd9g1c64z2kq
// static int T(int t)  
public static Object T() {
throw new UnsupportedOperationException();
}


// 9v529yqrkrwxr3gm9rbhvyidq
// Exnode_t* exnewnode(Expr_t* p, int op, int binary, int type, Exnode_t* left, Exnode_t* right) 
public static Object exnewnode() {
throw new UnsupportedOperationException();
}


// j4d9ue50oks8a1qmjoox8ndk
// void exfreenode(Expr_t* p, register Exnode_t* x) 
public static Object exfreenode() {
throw new UnsupportedOperationException();
}


// dm1l324yb3mnac1haw4bbzepa
// static Exnode_t *extract(Expr_t * p, Exnode_t ** argp, int type) 
public static Object extract() {
throw new UnsupportedOperationException();
}


// 9szo634qk8vr68xvi9y3mqxvk
// static Exnode_t *exnewsplit(Expr_t * p, int op, Exid_t* dyn, Exnode_t * s, Exnode_t* seps) 
public static Object exnewsplit() {
throw new UnsupportedOperationException();
}


// 5xra5t20dzj9au3b798wrw282
// static Exnode_t *exnewsub(Expr_t * p, Exnode_t * args, int op) 
public static Object exnewsub() {
throw new UnsupportedOperationException();
}


// 5t79sidwoed54klubkndaqeg7
// static Exnode_t *exnewsubstr(Expr_t * p, Exnode_t * args) 
public static Object exnewsubstr() {
throw new UnsupportedOperationException();
}


// 9bhc07smvgh0r5ncdcyohv7n6
// static Exnode_t *exstringOf(Expr_t * p, register Exnode_t * x) 
public static Object exstringOf() {
throw new UnsupportedOperationException();
}


// 8azxm1xsspkweoftnrcls84ey
// static Exnode_t *exprint(Expr_t * p, Exid_t * ex, Exnode_t * args) 
public static Object exprint() {
throw new UnsupportedOperationException();
}


// 60kzbtabo0kk5q0j7ejdci40i
// static Exnode_t *makeVar(Expr_t * prog, Exid_t * s, Exnode_t * idx, 			     Exnode_t * dyna, Exref_t * refs) 
public static Object makeVar() {
throw new UnsupportedOperationException();
}


// 6fqusp3w63cyxmstus24buxuo
// static char*	typename[] = 


// dbgi1z9h4yo4tx5hx9ez3fiu1
// static int	typecast[6][6] = 


// df2u83qy4qtu529yk9al4lh0o
// char *extypename(Expr_t * p, int type) 
public static Object extypename() {
throw new UnsupportedOperationException();
}


// ag5vfelsjpxnlqfxdxnz5mufd
// Exnode_t *exnoncast(register Exnode_t * x) 
public static Object exnoncast() {
throw new UnsupportedOperationException();
}


// 9hi1or1m0nxx394vz1q3n580q
// Exnode_t* excast(Expr_t* p, register Exnode_t* x, register int type, register Exnode_t* xref, int arg) 
public static Object excast() {
throw new UnsupportedOperationException();
}


// bjopz3z2j605a5g6e4npju0fw
// static Exid_t* qualify(register Exref_t* ref, register Exid_t* sym) 
public static Object qualify() {
throw new UnsupportedOperationException();
}


// dav3z840op59ureoqb99njndn
// static Exnode_t* call(Exref_t* ref, register Exid_t* fun, register Exnode_t* args) 
public static Object call() {
throw new UnsupportedOperationException();
}


// 3jsbxjslpf4xw6512sic7xgmx
// static Print_t* preprint(register Exnode_t* args) 
public static Object preprint() {
throw new UnsupportedOperationException();
}


// 4xvemw21z2g483ztimbzodi1w
// int expush(Expr_t* p, const char* name, int line, const char* sp, Sfio_t* fp) 
public static Object expush() {
throw new UnsupportedOperationException();
}


// 1kyf52q3601l0wjddobj9ka4w
// int expop(register Expr_t* p) 
public static Object expop() {
throw new UnsupportedOperationException();
}


// d1kyzivanbi53olxsfxguq7ju
// void exinit(void) 
public static Object exinit() {
throw new UnsupportedOperationException();
}


// 1v9lpvitwel249hapkjmqvchr
// int excomp(register Expr_t* p, const char* name, int line, const char* sp, Sfio_t* fp) 
public static Object excomp() {
throw new UnsupportedOperationException();
}


// 2a5g8dwojq5mfp2a8z8j6mv8n
// void exclose(register Expr_t* p, int all) 
public static Object exclose() {
throw new UnsupportedOperationException();
}


// 3oxnvakltegnbcbdhgvq5d48k
// static void checkBinary(Expr_t * p, Exnode_t * l, Exnode_t * ex, Exnode_t * r)  
public static Object checkBinary() {
throw new UnsupportedOperationException();
}


// b37oihq7ormg0kr3og77y265j
// static void checkName(Exid_t * id)  
public static Object checkName() {
throw new UnsupportedOperationException();
}


// 8406xer5yeu6b92hs6olhmv7r
// static int cmpKey(Dt_t * d, Extype_t * key1, Extype_t * key2, Dtdisc_t * disc)  
public static Object cmpKey() {
throw new UnsupportedOperationException();
}


// 1a5jaqv019yrnbmzzia7yk553
// int exisAssign(Exnode_t * n)  
public static Object exisAssign() {
throw new UnsupportedOperationException();
}


// 1h16qpjli49mhz4h67piigslj
// typedef unsigned char extype_uint8


// 44xtwcycgbs955hov1ydci3w9
// typedef short int extype_int8


// cwjb9ib52mjgy9k699c32waxz
// typedef unsigned short int extype_uint16


// 2j6ue4x980wwzb4zg0of77zde
// typedef short int extype_int16


// b6s1mv518fz6q14ude1io7dsq
// static const extype_uint8 extranslate[] = 


// 17i6vlys9gf71dobu6vxcbx9e
// static const extype_uint16 exprhs[] = 


// 407metymn7hif5wpc18tmh7pg
// static const extype_int16 exrhs[] = 


// 25mdz4632uxn1001ak7zi5aib
// static const extype_uint16 exrline[] = 


// 163k8esorubje9zi5hshgu8kd
// static const char *const extname[] = 


// 69nbb7x7c8p7zjlehrjskfcq0
// static const extype_uint8 exr1[] = 


// 2agipoftzjfikeejarby453ar
// static const extype_uint8 exr2[] = 


// d98zfw8i6pqvex60kmx6bsvg9
// static const extype_uint8 exdefact[] = 


// 43qgldus07f1e9h5jr1ou9bzu
// static const extype_int16 exdefgoto[] = 


// 47bdgyl4gz1az6i2mlb6146x5
// static const extype_int16 expact[] = 


// 31z125w4i80956lse85kerxe5
// static const extype_int16 expgoto[] = 


// d7n9mhzl8psrblzjb8n5icrip
// static const extype_int16 extable[] = 


// 9k78lsaw4ojz5usoxs1w04duh
// static const extype_int16 excheck[] = 


// 7k833t2obvw141gadgo3it4ek
// static const extype_uint8 exstos[] = 


// 9sypx5y764mz8c08o0pxqagi
// static void ex_symbol_value_print (exoutput, extype, exvaluep)     Sfio_t *exoutput
public static Object ex_symbol_value_print() {
throw new UnsupportedOperationException();
}


// iclpc1jgqor4tg1wx6bnavq7
// static void ex_symbol_print (exoutput, extype, exvaluep)     Sfio_t *exoutput
public static Object ex_symbol_print() {
throw new UnsupportedOperationException();
}


// d0i8kch7i0ag6alblt52o0wbg
// static void ex_stack_print (exbottom, extop)     extype_int16 *exbottom
public static Object ex_stack_print() {
throw new UnsupportedOperationException();
}


// 3279j5173i7vfjdigx23jklne
// static void ex_reduce_print (exvsp, exrule)     EXSTYPE *exvsp
public static Object ex_reduce_print() {
throw new UnsupportedOperationException();
}


// 46wwjw32qb51dbr7h8rzbz76h
// int exdebug


// 34o1fzya2t8kmiekzr7ujdnc8
// static void exdestruct (exmsg, extype, exvaluep)     const char *exmsg
public static Object exdestruct() {
throw new UnsupportedOperationException();
}


// 3f5uzqvl9ptruxml5k0ebu4j7
// int exchar


// 7bbshb87k06j13tdh2wlrynlg
// EXSTYPE exlval


// 3l1ezif5vjjoaz3qxy4k4umpz
// int exnerrs


// 335sitpsqay3snids2w1qm3n9
// int exparse ()    
public static Object exparse() {
throw new UnsupportedOperationException();
}


}
