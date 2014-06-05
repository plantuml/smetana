package gen.lib.cgraph;
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

public class scan {
// 9u1ttuisot4jd2hvnp85ay56g
// typedef signed char flex_int8_t


// wvexxj8vbty6kaj0saqbx6ts
// typedef short int flex_int16_t


// hwqrvan7avqujsfxav228c11
// typedef int flex_int32_t


// 7lla3uunolf6lxmj92jrtn42g
// typedef unsigned char flex_uint8_t


// f9lv61viy2nrstz0unqh9sqh
// typedef unsigned short int flex_uint16_t


// amgh831s9403je2b1fbipav6b
// typedef unsigned int flex_uint32_t


// o1gyrcpeise6ulid46rm843i
// typedef size_t aag_size_t


// 1f24j2fvxxvkjnlu5zfmsrb3y
// extern aag_size_t aagleng


// bn8sus4ks1cb72itw8xzz1flz
// extern FILE *aagin, *aagout


// 3hxi4rnlmjyc30okmpb31jq2x
// static size_t aag_buffer_stack_top = 0


// cvdgf98m8wxs77dykhlbh8cee
// static size_t aag_buffer_stack_max = 0


// f2vs4coshydmjcysvmam9xyqe
// static YY_BUFFER_STATE * aag_buffer_stack = 0


// e1hf3tomaeg9eyupoxlsqppd8
// static char aag_hold_char


// 3yvf3qfwm5w59tkhanhadp0sc
// static aag_size_t aag_n_chars


// bjftnvag2m5zx3ut0gxhbm1yp
// aag_size_t aagleng


// 3qr2iyg8mnjvp20zhsfc7zhll
// static char *aag_c_buf_p = (char *) 0


// 7p8qmci0084z5p538lompqcgl
// static int aag_init = 0


// aqkdngbj0xlr01bnkezay6hpw
// static int aag_start = 0


// by6x4qfu7ct1epyt34gtk0c68
// static int aag_did_buffer_switch_on_eof


// 9dv61b9prrpqjbdic1p73cmii
// typedef unsigned char YY_CHAR


// u29aw8w233elgi1t0d69a2tp
// FILE *aagin = (FILE *) 0, *aagout = (FILE *) 0


// 6yqm263qjbxbombyqn8htwe9h
// typedef int aag_state_type


// 4jmbvml2ky2nnj8z2fttiwlpj
// extern int aaglineno


// 8hrt3xlca3e6jbiammiyc4vny
// int aaglineno = 1


// 4cxmiga6ltifuposa502y9yyt
// extern char *aagtext


// 7xtkfznh5z71t9bxwa8l65woe
// static  flex_int16_t aag_accept[93] =     


// 681ycgqijl2pdx86pv93mlmpl
// static  flex_int32_t aag_ec[256] =     


// bc0sgnek7ow53q48q3951dxf7
// static  flex_int32_t aag_meta[49] =     


// 2kiqxti33weulohzuygr5c60p
// static  flex_int16_t aag_base[105] =     


// 2dk0cchyur4w0ynnbcpumq3df
// static  flex_int16_t aag_def[105] =     


// 5cx77li3gho8yavxa8ny5ydy8
// static  flex_int16_t aag_nxt[279] =     


// 84mqlrbyvesev1wun43vo6rt5
// static  flex_int16_t aag_chk[279] =     


// baro9b24r2upjoluxg072zqan
// static aag_state_type aag_last_accepting_state


// 51sd6p9r881rurh2cn0gr95sb
// static char *aag_last_accepting_cpos


// 4j2pfnbqhihe02dxjobjg2x8s
// extern int aag_flex_debug


// 693kz0rs1kqe9rnq983sul9xf
// int aag_flex_debug = 0


// d9rx7y8pk05fhn4zb20edan8k
// char *aagtext


// bv6npyi314kx5c073l8ghs1md
// extern YYSTYPE aaglval


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


// 6ayavpu39aihwyojkx093pcy3
// extern Agraph_t *Ag_G_global


// 871mxtg9l6ffpxdl9kniwusf7
// extern char *AgDataRecName


// c0o2kmml0tn6hftuwo0u4shwd
// extern Dtdisc_t Ag_subnode_id_disc


// 8k15pyu256unm2kpd9zf5pf7k
// extern Dtdisc_t Ag_subnode_seq_disc


// e3d820y06gpeusn6atgmj8bzd
// extern Dtdisc_t Ag_mainedge_id_disc


// cbr0772spix9h1aw7h5v7dv9j
// extern Dtdisc_t Ag_subedge_id_disc


// akd0c3v0j7m2npxcb9acit1fa
// extern Dtdisc_t Ag_mainedge_seq_disc


// 12d8la07351ww7vwfzucjst8m
// extern Dtdisc_t Ag_subedge_seq_disc


// 29eokk7v88e62g8o6lizmo967
// extern Dtdisc_t Ag_subgraph_id_disc


// 4xd9cbgy6hk5g6nhjcbpzkx14
// extern Agcbdisc_t AgAttrdisc


// ulfzla7f173z9e7hy51d7yxc
// static int line_num = 1


// 7k271geg3zfbftdupjdh78yl0
// static int html_nest = 0


// 91mp0doens27fx1oso66rsrpm
// static char* InputFile


// a00t38gjjcwqriw9cdxo4tdnd
// static Agdisc_t	*Disc


// 1by6tdr1jakvfvcghn57hto4l
// static void 	*Ifile


// 8kv7ct8l9pvdr999inffhfd8u
// static int graphType


// 1oj4owfzrg4azkuildy8ykqr9
// void agreadline(int n) 
public static Object agreadline() {
throw new UnsupportedOperationException();
}


// bf0ltyw37l11aswamj8q178wi
// void agsetfile(char* f) 
public static Object agsetfile() {
throw new UnsupportedOperationException();
}


// 3r1v6x85pa9sbewoebj1wpjuu
// void aglexinit(Agdisc_t *disc, void *ifile) 
public static Object aglexinit() {
throw new UnsupportedOperationException();
}


// cry2o4y2edn77xmsht3kg427n
// static char	*Sbuf,*Sptr,*Send


// ci1omlit75xbk0j3loutg4m5g
// static void beginstr(void) 
public static Object beginstr() {
throw new UnsupportedOperationException();
}


// 81ls7ujxrb181svnc5awggx7n
// static void addstr(char *src) 
public static Object addstr() {
throw new UnsupportedOperationException();
}


// 2rmqzhh7aovtupqfrlts8pa2m
// static void endstr(void) 
public static Object endstr() {
throw new UnsupportedOperationException();
}


// 4t56dhvw52uu822nlaokivf85
// static void endstr_html(void) 
public static Object endstr_html() {
throw new UnsupportedOperationException();
}


// 9nr6wfm5bmxh70x9saeavz26m
// static void storeFileName (char* fname, int len) 
public static Object storeFileName() {
throw new UnsupportedOperationException();
}


// bj9zjg1k93tugikci6pdacgv8
// static void ppDirective (void) 
public static Object ppDirective() {
throw new UnsupportedOperationException();
}


// 7fcnmcd19oiyoyaqr7swnx68s
// static int chkNum(void) 
public static Object chkNum() {
throw new UnsupportedOperationException();
}


// e5pbkh72mgktxf6bfh0n4gt4
// int aaglex (void) 
public static Object aaglex() {
throw new UnsupportedOperationException();
}


// 1bk2c3ez7bpnqxz6emq8dv629
// static int aag_get_next_buffer (void) 
public static Object aag_get_next_buffer() {
throw new UnsupportedOperationException();
}


// dge0pk480ox74sfkkc1y9j2az
// static aag_state_type aag_get_previous_state (void) 
public static Object aag_get_previous_state() {
throw new UnsupportedOperationException();
}


// 1bqrp6l15lwke1ldr6rocxdac
// static aag_state_type aag_try_NUL_trans  (aag_state_type aag_current_state ) 
public static Object aag_try_NUL_trans() {
throw new UnsupportedOperationException();
}


// kz1k3qeyyshqirx2726nc2lb
// static void aagunput (int c, register char * aag_bp ) 
public static Object aagunput() {
throw new UnsupportedOperationException();
}


// 23mhytvy8ivrz8bn5qfjy7jm5
// static int input  (void)   
public static Object input() {
throw new UnsupportedOperationException();
}


// b91gjad0l9xznwagmx7tqnomu
// void aagrestart  (FILE * input_file ) 
public static Object aagrestart() {
throw new UnsupportedOperationException();
}


// 418kp3955qaorltr2gp3n7hr3
// void aag_switch_to_buffer  (YY_BUFFER_STATE  new_buffer ) 
public static Object aag_switch_to_buffer() {
throw new UnsupportedOperationException();
}


// 2n1quqa5b6mm0p65k3ewgjdll
// static void aag_load_buffer_state  (void) 
public static Object aag_load_buffer_state() {
throw new UnsupportedOperationException();
}


// bz2sdl6duvmrjgptg3i8pek7d
// YY_BUFFER_STATE aag_create_buffer  (FILE * file, int  size ) 
public static Object aag_create_buffer() {
throw new UnsupportedOperationException();
}


// cvxw0l0ojnracqk5o3c07vf4m
// void aag_delete_buffer (YY_BUFFER_STATE  b ) 
public static Object aag_delete_buffer() {
throw new UnsupportedOperationException();
}


// 8z0ws8ykdt2m53k269y0s3uau
// static void aag_init_buffer  (YY_BUFFER_STATE  b, FILE * file )  
public static Object aag_init_buffer() {
throw new UnsupportedOperationException();
}


// euu43g3i43888wantq0lgdqe8
// void aag_flush_buffer (YY_BUFFER_STATE  b ) 
public static Object aag_flush_buffer() {
throw new UnsupportedOperationException();
}


// 19g3ujgwn6wfrv2pvydtxr75
// void aagpush_buffer_state (YY_BUFFER_STATE new_buffer ) 
public static Object aagpush_buffer_state() {
throw new UnsupportedOperationException();
}


// 27b1vcsegbixqbqjzrwamdpcn
// void aagpop_buffer_state (void) 
public static Object aagpop_buffer_state() {
throw new UnsupportedOperationException();
}


// 1iyph8hj357vj714inph32tcl
// static void aagensure_buffer_stack (void) 
public static Object aagensure_buffer_stack() {
throw new UnsupportedOperationException();
}


// 7yvjra4z1kimbp0xfvzml1ge1
// YY_BUFFER_STATE aag_scan_buffer  (char * base, aag_size_t  size ) 
public static Object aag_scan_buffer() {
throw new UnsupportedOperationException();
}


// 43izorque2e7plck393cc6hsz
// YY_BUFFER_STATE aag_scan_string ( char * aagstr ) 
public static Object aag_scan_string() {
throw new UnsupportedOperationException();
}


// 74bdwb6md7bl3lpynnjoca8pm
// YY_BUFFER_STATE aag_scan_bytes  ( char * aagbytes, aag_size_t  _aagbytes_len ) 
public static Object aag_scan_bytes() {
throw new UnsupportedOperationException();
}


// ar1fz1d00siup070hcy6exvpz
// static void aag_fatal_error ( char* msg ) 
public static Object aag_fatal_error() {
throw new UnsupportedOperationException();
}


// ak2o99rit6h1dzbfugt87rz4l
// int aagget_lineno  (void) 
public static Object aagget_lineno() {
throw new UnsupportedOperationException();
}


// c4xsc4x2etna327n4r43l0src
// FILE *aagget_in  (void) 
public static Object aagget_in() {
throw new UnsupportedOperationException();
}


// 4werkxqgsv51e1huizt8jy900
// FILE *aagget_out  (void) 
public static Object aagget_out() {
throw new UnsupportedOperationException();
}


// c930io2oqys6cwcw6hokf74af
// aag_size_t aagget_leng  (void) 
public static Object aagget_leng() {
throw new UnsupportedOperationException();
}


// elqro7uvtzkdgrd0axaati5dn
// char *aagget_text  (void) 
public static Object aagget_text() {
throw new UnsupportedOperationException();
}


// ddyawmdmhp4bhddv0ycwtja18
// void aagset_lineno (int  line_number ) 
public static Object aagset_lineno() {
throw new UnsupportedOperationException();
}


// rnmvgky3jm4cqnymq9s4bzig
// void aagset_in (FILE *  in_str ) 
public static Object aagset_in() {
throw new UnsupportedOperationException();
}


// bho3hef6ijshlmjirs3pp56ov
// void aagset_out (FILE *  out_str ) 
public static Object aagset_out() {
throw new UnsupportedOperationException();
}


// 43ss154kldgxk2nhdusc1m4rz
// int aagget_debug  (void) 
public static Object aagget_debug() {
throw new UnsupportedOperationException();
}


// ccfhizqhlcd8o5g92d987s2m2
// void aagset_debug (int  bdebug ) 
public static Object aagset_debug() {
throw new UnsupportedOperationException();
}


// 5fcbavnjmbu31asyzd62fwq2d
// static int aag_init_globals (void) 
public static Object aag_init_globals() {
throw new UnsupportedOperationException();
}


// b88yq5tilv62doe0lqk0odlu8
// int aaglex_destroy  (void) 
public static Object aaglex_destroy() {
throw new UnsupportedOperationException();
}


// c8en52xb7jekcv34dmaqouq5x
// void *aagalloc (aag_size_t  size ) 
public static Object aagalloc() {
throw new UnsupportedOperationException();
}


// 5hlwjmuqfpjsqydhktwpbidq2
// void *aagrealloc  (void * ptr, aag_size_t  size ) 
public static Object aagrealloc() {
throw new UnsupportedOperationException();
}


// dt3z1styelhok5vdef4znud0x
// void aagfree (void * ptr ) 
public static Object aagfree() {
throw new UnsupportedOperationException();
}


// b7djg5vf8k7q1bmscjoxbdi7m
// void aagerror(char *str) 
public static Object aagerror() {
throw new UnsupportedOperationException();
}


// d7y223uahk83hp7is4nahwefj
// void aglexeof() 
public static Object aglexeof() {
throw new UnsupportedOperationException();
}


// 3ufv8can0vbou4fqbz8jayves
// void aglexbad() 
public static Object aglexbad() {
throw new UnsupportedOperationException();
}


// 8mvwigk3z82cg7dw50v9tpfaw
// int aagwrap(void) 
public static Object aagwrap() {
throw new UnsupportedOperationException();
}


}
