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

public class node {
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


// 4w89du6uel405pm3vxsr3ayxt
// Agnode_t *agfindnode_by_id(Agraph_t * g, unsigned long id) 
@TranslatedBy("plantuml") 
public static Agnode_t agfindnode_by_id(Agraph_t g, @Unsigned Int id) {
    Agsubnode_t sn;
    dummy.base.tag.id = id;
    template.node = dummy;
    sn = (Agsubnode_t) g.n_id.searchf.function((g.n_id),template,0000004);
    return sn!=null ? sn.node : null;
}
static final Agsubnode_t template = new Agsubnode_t();
static final Agnode_t dummy = new Agnode_t();

// 5vx7fn1v22rrpr75adkoknajz
// Agnode_t *agfindnode_by_name(Agraph_t * g, char *name) 
public static Object agfindnode_by_name() {
throw new UnsupportedOperationException();
}


// 55wopi2gd93zpmycxoywlxm0y
// Agnode_t *agfstnode(Agraph_t * g) 
@TranslatedBy("plantuml")
public static Agnode_t agfstnode(Agraph_t g) {
    Agsubnode_t sn;
    sn = (Agsubnode_t) g.n_seq.searchf.function(g.n_seq,null,0000200);
    return sn!=null ? sn.node : null;
}

// bek79ccvjys1j9q404i3y6oh8
// Agnode_t *agnxtnode(Agraph_t * g, Agnode_t * n) 
@TranslatedBy("plantuml")
public static Agnode_t agnxtnode(Agraph_t g, Agnode_t n) {
throw new UnsupportedOperationException();
}

// 17tu6ipvtgbjfrggkvyz3nasf
// Agnode_t *aglstnode(Agraph_t * g) 
public static Object aglstnode() {
throw new UnsupportedOperationException();
}


// 3qloij26jbl7m0ftyb0ouesq4
// Agnode_t *agprvnode(Agraph_t * g, Agnode_t * n) 
public static Object agprvnode() {
throw new UnsupportedOperationException();
}


// v8mofmgbbew0rwtlkge7ecfb
// static Agnode_t *newnode(Agraph_t * g, unsigned long id, unsigned long seq) 
@TranslatedBy("plantuml") 
public static Agnode_t newnode(Agraph_t g, @Unsigned Int id, @Unsigned int seq) {
    Agnode_t n;
    n = (Agnode_t) agalloc(g, sizeof(Agnode_t.class));
    ((((Agobj_t)(n.castTo(Agobj_t.class))).tag).objtype) = 1;
    ((((Agobj_t)(n.castTo(Agobj_t.class))).tag).id) = id;
    ((((Agobj_t)(n.castTo(Agobj_t.class))).tag).seq) = seq;
    n.root = agroot(g);
    if (agroot(g).desc.has_attrs)
	agbindrec(n, AgDataRecName, sizeof(Agattr_t.class), (false));
    /* nodeattr_init and method_init will be called later, from the
     * subgraph where the node was actually created, but first it has
     * to be installed in all the (sub)graphs up to root. */
    return n;
}

// 4m26dpgaiw44hcleugjy71eus
// static void installnode(Agraph_t * g, Agnode_t * n) 
@TranslatedBy("plantuml") 
public static void installnode(Agraph_t g, Agnode_t n) {
    Agsubnode_t sn;
    int osize;
    ;
    osize = dtsize(g.n_id);
    if (g == agroot(g)) sn = n.mainsub;
    else sn = (Agsubnode_t) agalloc(g, sizeof(Agsubnode_t.class));
    sn.node = n;
    g.n_id.searchf.function(g.n_id,sn,0000001);
    g.n_seq.searchf.function(g.n_seq,sn,0000001);
    ;
    ;
}
// 3mfxjcaeepn8nitirs3yoqaed
// static void installnodetoroot(Agraph_t * g, Agnode_t * n) 
@TranslatedBy("plantuml") 
public static void installnodetoroot(Agraph_t g, Agnode_t n) {
    Agraph_t par;
    installnode(g, n);
    if ((par = agparent(g))!=null)
	installnodetoroot(par, n);
}

// 85bb9mezhsgtzar3kqz95mq1
// static void initnode(Agraph_t * g, Agnode_t * n) 
@TranslatedBy("plantuml") 
public static void initnode(Agraph_t g, Agnode_t n) {
    if (agroot(g).desc.has_attrs)
	agnodeattr_init(g,n);
    agmethod_init(g, n);
}

// 8pheyc1zc7lnvhdgwtmnk0bhu
// Agnode_t *agidnode(Agraph_t * g, unsigned long id, int cflag) 
public static Object agidnode() {
throw new UnsupportedOperationException();
}


// 8rc5p3g28dnfnhmv0tzur17m9
// Agnode_t *agnode(Agraph_t * g, char *name, int cflag) 
@TranslatedBy("plantuml") 
public static Agnode_t agnode(Agraph_t g, StarChar name, boolean cflag) {
    Agraph_t root;
    Agnode_t n;
    @Unsigned Int id[] = new Int[] {new StarLongGeneric()};
    root = agroot(g);
    /* probe for existing node */
    if (agmapnametoid(g, 1, name, ASREF(id), (false))) {
	if ((n = agfindnode_by_id(g, id[0]))!=null)
	    return n;
	/* might already exist globally, but need to insert locally */
	if (cflag && (g != root) && ((n = agfindnode_by_id(root, id[0]))!=null)) {
	    return agsubnode(g, n, (N(false)));
	}
    }
    if (cflag && agmapnametoid(g, 1, name, ASREF(id), (N(false)))) {	/* reserve id */
	n = newnode(g, id[0], agnextseq(g, 1));
	installnodetoroot(g, n);
	initnode(g, n);
	;
	agregister(g, 1, n); /* register in external namespace */
	return n;
    }
    return null;
}
// acahmq5kvzn3o31mluqgw7q9p
// void agdelnodeimage(Agraph_t * g, Agnode_t * n, void *ignored) 
public static Object agdelnodeimage() {
throw new UnsupportedOperationException();
}


// apmrfwq8eaqjv92p71ib12s3w
// int agdelnode(Agraph_t * g, Agnode_t * n) 
public static Object agdelnode() {
throw new UnsupportedOperationException();
}


// 283fwlza5s3tgkzm71b82jtw4
// static void dict_relabel(Agnode_t * n, void *arg) 
public static Object dict_relabel() {
throw new UnsupportedOperationException();
}


// 8ox59qtf4u1dwq5djr39zs46h
// int agrelabel_node(Agnode_t * n, char *newname) 
public static Object agrelabel_node() {
throw new UnsupportedOperationException();
}


// 64quo0f2hena8dg0q31tju5b
// Agnode_t *agsubnode(Agraph_t * g, Agnode_t * n0, int cflag) 
@TranslatedBy("plantuml") 
public static Agnode_t agsubnode(Agraph_t g, Agnode_t n0, boolean cflag) {
throw new UnsupportedOperationException();
}

// 71l75gmg5089hoxap0c79zdix
// int agsubnodeidcmpf(Dict_t * d, void *arg0, void *arg1, Dtdisc_t * disc) 
@TranslatedBy("plantuml")
@NeedReview
public static int agsubnodeidcmpf(Dict_t d, StarVoid arg0, StarVoid arg1, Dtdisc_t disc) {
    int	v;
    Agsubnode_t sn0, sn1;
    sn0 = (Agsubnode_t) arg0.castTo(Agsubnode_t.class);
    sn1 = (Agsubnode_t) arg1.castTo(Agsubnode_t.class);
    Int id0 =  ((((Agobj_t)(sn0.node.castTo(Agobj_t.class))).tag).id);
    Int id1 =  ((((Agobj_t)(sn1.node.castTo(Agobj_t.class))).tag).id);
    v = id0.getIntegerValue() - id1.getIntegerValue();
    return ((v==0)?0:(v<0?-1:1));
}

// dw64tsmvfgwtwz235at51nwz3
// int agsubnodeseqcmpf(Dict_t * d, void *arg0, void *arg1, Dtdisc_t * disc) 
@TranslatedBy("plantuml")
public static int agsubnodeseqcmpf(Dict_t d, StarVoid arg0, StarVoid arg1, Dtdisc_t disc) {
    Agsubnode_t sn0, sn1;
    long	v;
    sn0 = (Agsubnode_t) arg0.castTo(Agsubnode_t.class);
    sn1 = (Agsubnode_t) arg1.castTo(Agsubnode_t.class);
    v = (((((Agobj_t)(sn0.node.castTo(Agobj_t.class))).tag).seq) - ((((Agobj_t)(sn1.node.castTo(Agobj_t.class))).tag).seq));
    return ((v==0)?0:(v<0?-1:1));
}

// 7cswhizoa1o3xpo72j83fj19o
// static void free_subnode (Dt_t* d, Agsubnode_t* sn, Dtdisc_t * disc) 
@TranslatedBy("plantuml")
public static void free_subnode (Dict_t d, Agsubnode_t sn, Dtdisc_t disc) {
throw new UnsupportedOperationException();
}

// us7d1n3fefkf0qyr6thv1sai
// Dtdisc_t Ag_subnode_id_disc = 
@TranslatedBy("plantuml")
@NeedReview
@HasQuestion("link offset ignored ?")
	public static Dtdisc_t Ag_subnode_id_disc = new Dtdisc_t(
	null,
	null, 
	null, 
	null, 
	null, 
	new Dtcompar_f() {
		public int function(Dict_t arg1, StarVoid arg2, StarVoid arg3, Dtdisc_t arg4) {
			return agsubnodeidcmpf(arg1, arg2, arg3, arg4);
		}
	}, 
	null, 
	new Dtmemory_f() {
		public StarVoid function(Dict_t arg1, StarVoid arg2, size_t arg3, Dtdisc_t arg4) {
			return agdictobjmem(arg1, arg2, arg3, arg4);
		}
	},
	null);
// 3gqjvodjfsv6wz1tk75zy19p9
// Dtdisc_t Ag_subnode_seq_disc = 
@TranslatedBy("plantuml")
@HasQuestion("link offset ignored ?")
	public static Dtdisc_t Ag_subnode_seq_disc = new Dtdisc_t(
	null,
	null, 
	null, 
	null, 
	new Dtfree_f() {
		public void function(Dict_t arg1, StarVoid arg2, Dtdisc_t arg3) {
			free_subnode(arg1, (Agsubnode_t) arg2, arg3);
		}
	}, 
	new Dtcompar_f() {
		public int function(Dict_t arg1, StarVoid arg2, StarVoid arg3, Dtdisc_t arg4) {
			return agsubnodeseqcmpf(arg1, arg2, arg3, arg4);
		}
	}, 
	null, 
	new Dtmemory_f() {
		public StarVoid function(Dict_t arg1, StarVoid arg2, size_t arg3, Dtdisc_t arg4) {
			return agdictobjmem(arg1, arg2, arg3, arg4);
		}
	},
	null);
}
