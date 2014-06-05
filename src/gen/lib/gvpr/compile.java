package gen.lib.gvpr;
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

public class compile {
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


// 83a1zu2el049lzgamfy0wo7ye
// typedef unsigned long ALIGN_INTEGRAL


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


// 51kvqjcldcl26v6sg1onapbir
// extern int exdebug


// 3tpuf2oqoz7i3etzl3dolchwb
// extern EXSTYPE exlval


// 9dai0bai06emckm350qgu2s89
// typedef short Exshort_t


// 3691phrqqrb4ygjieer6hxbjb
// typedef EXSTYPE Extype_t


// 8ucops7mhzrjfqf3p6pw2c04s
// typedef nval_t ndata


// 72v420rxijd709ansjdd4rdrr
// typedef uval_t edata


// ai7b4z8rb0iuspkampp4qlsam
// typedef gval_t gdata


// eami7o5wilrcavvnh6jun3a9z
// extern Error_info_t _err_info


// 991j015wrltgu3nzuwp6y4n7w
// static Exid_t symbols[] = 


// 7eqt64wir3eelbj14rf7g36ur
// static char* typenames[] = 


// cu94dvzzo1pntb5eb1ogzdgjb
// typedef unsigned short tctype


// d23n7aab9g6jhhtaaut38vlrb
// static tctype tchk[][2] = 


// 8zjvt2wf9llrz18i1f2juyg5c
// static long CharMask[28] = 


// 8ekvz7q44iqm3z13pu9ubxi5s
// static short		TFA_State


// 5jpenxv59z93j4msb2zpsxecp
// TrieState           TrieStateTbl[70] = 


// a27ihyc9mgyikvnfxz56lgovm
// TrieTrans           TrieTransTbl[69] = 


// d2ufvqoepjrlyganayrd56j47
// static int iofread(void *chan, char *buf, int bufsize) 
public static Object iofread() {
throw new UnsupportedOperationException();
}


// 4ne022hbh7aiyupfpj6hebmgj
// static int ioputstr(void *chan, const char *str) 
public static Object ioputstr() {
throw new UnsupportedOperationException();
}


// 70wrt4xtuxuxwwq1ke3hobv82
// static int ioflush(void *chan) 
public static Object ioflush() {
throw new UnsupportedOperationException();
}


// 25h5pdhv9k82mtxlmtaitw3fn
// static Agiodisc_t gprIoDisc = 


// 1hlitvli7rcl8esadtqh565ta
// static Agdisc_t gprDisc = 


// dab807ep3ucsbyjfa79hx7ueb
// static char *nameOf(Expr_t * ex, Agobj_t * obj, Sfio_t* tmps) 
public static Object nameOf() {
throw new UnsupportedOperationException();
}


// 9fldx8debx5p1p2sqc41he9ph
// static char *bbOf(Expr_t * pgm, char *pt, int getll) 
public static Object bbOf() {
throw new UnsupportedOperationException();
}


// bknpehrsncw2flj6muyx0rjk3
// static char *xyOf(Expr_t * pgm, char *pt, int getx) 
public static Object xyOf() {
throw new UnsupportedOperationException();
}


// 2mmj1ylugn2mjj0jj4fhxud9b
// static Agdesc_t xargs(char *args) 
public static Object xargs() {
throw new UnsupportedOperationException();
}


// dz9zke8m04zomi7jvjn0r8l6u
// static char *deparse(Expr_t * ex, Exnode_t * n, Sfio_t * sf) 
public static Object deparse() {
throw new UnsupportedOperationException();
}


// 456av0g25zy6nev84d8r94r16
// static Agobj_t *deref(Expr_t * pgm, Exnode_t * x, Exref_t * ref, 		      Agobj_t * objp, Gpr_t * state) 
public static Object deref() {
throw new UnsupportedOperationException();
}


// b2b2wpcvel1wy7x58wvqdyd3k
// static int assignable (Agobj_t *objp, unsigned char* name) 
public static Object assignable() {
throw new UnsupportedOperationException();
}


// 1751awytleetksuawhadczr4c
// static int setattr (Agobj_t *objp, char* name, char* val) 
public static Object setattr() {
throw new UnsupportedOperationException();
}


// 5xu72rbbriojfh83gkwnr0uh2
// static char* kindToStr (int kind) 
public static Object kindToStr() {
throw new UnsupportedOperationException();
}


// 4huuom6ggnxbi9kaxjvywmub0
// static char* kindOf (Agobj_t* objp) 
public static Object kindOf() {
throw new UnsupportedOperationException();
}


// cul1ms5vsnnbi6zf2bz526ccv
// static int lookup(Expr_t * pgm, Agobj_t * objp, Exid_t * sym, Extype_t * v,   Gpr_t *state) 
public static Object lookup() {
throw new UnsupportedOperationException();
}


// dz4my7b7iiqrwxem82jxonpah
// static char *getArg(int n, Gpr_t * state) 
public static Object getArg() {
throw new UnsupportedOperationException();
}


// 35x213ofigui9hw41nrk4el80
// static int setDfltAttr (Agraph_t *gp, char* k, char* name, char* value) 
public static Object setDfltAttr() {
throw new UnsupportedOperationException();
}


// edk4ndl534zae01snt5o27526
// static int toKind (char* k, char* fn) 
public static Object toKind() {
throw new UnsupportedOperationException();
}


// ciorljgd2ny3qc6lsj287ju95
// static char* nxtAttr (Agraph_t *gp, char* k, char* name) 
public static Object nxtAttr() {
throw new UnsupportedOperationException();
}


// e1fih92v2gix0jovsueyqaabj
// static char* getDfltAttr (Agraph_t *gp, char* k, char* name) 
public static Object getDfltAttr() {
throw new UnsupportedOperationException();
}


// uybb213pk4lk1qragjuxv2lk
// static Extype_t getval(Expr_t * pgm, Exnode_t * node, Exid_t * sym, Exref_t * ref,        void *env, int elt, Exdisc_t * disc) 
public static Object getval() {
throw new UnsupportedOperationException();
}


// 5vutbedduw9lfgmq35daheid5
// static char *typeName(Expr_t * pg, int op) 
public static Object typeName() {
throw new UnsupportedOperationException();
}


// djhyn3lryw235vtgkys8xszs5
// static int setval(Expr_t * pgm, Exnode_t * x, Exid_t * sym, Exref_t * ref,        void *env, int elt, Extype_t v, Exdisc_t * disc) 
public static Object setval() {
throw new UnsupportedOperationException();
}


// 3cs0dn51a0meh6vor877jfiy7
// static int codePhase


// 2m7hewrgw8te4anbm89ep8ock
// static tctype typeChk(tctype intype, Exid_t * sym) 
public static Object typeChk() {
throw new UnsupportedOperationException();
}


// caejmgpg7zpnk33b96f8vkj0f
// static tctype typeChkExp(Exref_t * ref, Exid_t * sym) 
public static Object typeChkExp() {
throw new UnsupportedOperationException();
}


// bz2b7y5uhr8f680y4firtw8z2
// static Extype_t refval(Expr_t * pgm, Exnode_t * node, Exid_t * sym, Exref_t * ref,        char *str, int elt, Exdisc_t * disc) 
public static Object refval() {
throw new UnsupportedOperationException();
}


// 2vit55nkd10tpzqopnqppkibi
// int binary(Expr_t * pg, Exnode_t * l, Exnode_t * ex, Exnode_t * r, int arg,        Exdisc_t * disc) 
public static Object binary() {
throw new UnsupportedOperationException();
}


// 98pajqhrhri8nddarqhkcd86x
// static int strToTvtype (char* s) 
public static Object strToTvtype() {
throw new UnsupportedOperationException();
}


// 39dcm8mm9hpongur28beo9iew
// static char* tvtypeToStr (int v) 
public static Object tvtypeToStr() {
throw new UnsupportedOperationException();
}


// 4v5jsvxx479fepokacwfadcrt
// static int stringOf(Expr_t * prog, register Exnode_t * x, int arg, Exdisc_t* disc) 
public static Object stringOf() {
throw new UnsupportedOperationException();
}


// a5c0sl112x19ct77bln5plbnt
// static int convert(Expr_t * prog, register Exnode_t * x, int type, 	register Exid_t * xref, int arg, Exdisc_t * disc) 
public static Object convert() {
throw new UnsupportedOperationException();
}


// 1bkweogimdsstuo08fzqr37pp
// static Extype_t keyval(Expr_t * pgm, Extype_t v, int type, Exdisc_t * disc) 
public static Object keyval() {
throw new UnsupportedOperationException();
}


// ad384d3zundolp0tzls6c0l2j
// static int matchval(Expr_t * pgm, Exnode_t * xstr, const char *str, Exnode_t * xpat, 	 const char *pat, void *env, Exdisc_t * disc) 
public static Object matchval() {
throw new UnsupportedOperationException();
}


// 6k8xk9z13c9nht4ivm8ufr5px
// static int  a2t[] = 


// 3olmke7if0upyqmyti5nhsas0
// static Exdisc_t *initDisc(Gpr_t * state) 
public static Object initDisc() {
throw new UnsupportedOperationException();
}


// 6ypzc65hfxme0vrp65glw3jmk
// static Exnode_t *compile(Expr_t * prog, char *src, char *input, int line, 			 char *lbl, char *sfx, int kind) 
public static Object compile() {
throw new UnsupportedOperationException();
}


// ao8z3ornkj9dr4phcn2x951b9
// static void checkGuard(Exnode_t * gp, char *src, int line) 
public static Object checkGuard() {
throw new UnsupportedOperationException();
}


// 7n4fdgar4q811u5i5ktvhrdvf
// static case_stmt *mkStmts(Expr_t * prog, char *src, case_info * sp, 			  int cnt, char *lbl, Sfio_t *tmps) 
public static Object mkStmts() {
throw new UnsupportedOperationException();
}


// avvtpiy1x35ugpfv6ccfh3vzf
// static int mkBlock(comp_block* bp, Expr_t * prog, char *src, parse_block *inp, Sfio_t* tmps, int i) 
public static Object mkBlock() {
throw new UnsupportedOperationException();
}


// edfwamxjb4rmapjneqluquxqa
// static char *doFlags(int flags, Sfio_t * s) 
public static Object doFlags() {
throw new UnsupportedOperationException();
}


// ts8b60d28ij5b9naetpcve4l
// comp_prog *compileProg(parse_prog * inp, Gpr_t * state, int flags) 
public static Object compileProg() {
throw new UnsupportedOperationException();
}


// 5uyeme0ktq95l2i3upjqrupgs
// void freeCompileProg (comp_prog *p) 
public static Object freeCompileProg() {
throw new UnsupportedOperationException();
}


// 8r3d03zz1lapudayub84ot9v0
// int walksGraph(comp_block * p) 
public static Object walksGraph() {
throw new UnsupportedOperationException();
}


// 8xx7qqdb1b6b1j55mgxdfy448
// int usesGraph(comp_prog * p) 
public static Object usesGraph() {
throw new UnsupportedOperationException();
}


// 8qgmzkyh6f0ofnovmjk1rnpuz
// void ptchk(void) 
public static Object ptchk() {
throw new UnsupportedOperationException();
}


// db1lni3ftzm5ktl7b9ejgkk8q
// Agraph_t *readG(Sfio_t * fp) 
public static Object readG() {
throw new UnsupportedOperationException();
}


// c8ool4q6u6kg8ewvho6elx86l
// Agraph_t *openG(char *name, Agdesc_t desc) 
public static Object openG() {
throw new UnsupportedOperationException();
}


// bynrr4gcai25xexfsjdhet82i
// Agraph_t *openSubg(Agraph_t * g, char *name) 
public static Object openSubg() {
throw new UnsupportedOperationException();
}


// 7230auohjnud1fpocrctu725a
// Agnode_t *openNode(Agraph_t * g, char *name) 
public static Object openNode() {
throw new UnsupportedOperationException();
}


// cyt1de7m9sabjr0txm4o8p3k
// Agedge_t *openEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key) 
public static Object openEdge() {
throw new UnsupportedOperationException();
}


}
