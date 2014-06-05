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

public class id {
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


// a0a2zxsu8n019hzm1rwf1jc7f
// static void *idopen(Agraph_t * g, Agdisc_t* disc) 
@TranslatedBy("plantuml")
public static StarVoid idopen(Agraph_t g, Agdisc_t disc) {
	return g;
}

// lsl0c1gejls1wv04ga6xy2cf
// static long idmap(void *state, int objtype, char *str, unsigned long *id, 		  int createflag) 
@TranslatedBy("plantuml")
public static boolean idmap(StarVoid state, int objtype, StarChar str, @Unsigned Int id, boolean createflag) {
    StarChar s;
    if (str!=null) {
	Agraph_t g;
	g = (Agraph_t) state;
	if (createflag)
	    s = agstrdup(g, str);
	else
	    s = agstrbind(g, str);
	id.set(s);
    } else {
	id.set(ctr);
	ctr += 2;
    }
    return (N(0));
}
static int ctr = 1;
// 8ynmf2fueegi7vjejal3ri1ax
// static long idalloc(void *state, int objtype, unsigned long request) 
@TranslatedBy("plantuml")
public int idalloc(StarVoid state, int objtype, @Unsigned int request) {
return 0;
}

// 5fsdlq8w38bfd7gtwz1z8arad
// static void idfree(void *state, int objtype, unsigned long id) 
@TranslatedBy("plantuml")
public static void idfree(StarVoid state, int objtype, @Unsigned int id) {
throw new UnsupportedOperationException();
}

// 8143j507ej7uqqjzw5i32xej5
// static char *idprint(void *state, int objtype, unsigned long id) 
public static Object idprint() {
throw new UnsupportedOperationException();
}


// 44seyu1scoubb1wsuhwlghwyz
// static void idclose(void *state) 
@TranslatedBy("plantuml")
public static void idclose(StarVoid state) {
}
// 5bjqo0ihl0x25vaspoiehmwzk
// static void idregister(void *state, int objtype, void *obj) 
@TranslatedBy("plantuml")
public static void idregister(StarVoid state, int objtype, StarVoid obj) {
}

// cxrk51474ugltvklkcvp3v2ly
// Agiddisc_t AgIdDisc = 
@TranslatedBy("plantuml")
public static Agiddisc_t AgIdDisc = new Agiddisc_t(
new Agiddisc_s.open() {
	public StarVoid function (Agraph_t g, Agdisc_t t) {
		return idopen(g, t);
	}
}
,
new Agiddisc_s.map() {
	public boolean function (StarVoid state, int objtype, StarChar str, @Unsigned Int id, boolean createflag) {
		return idmap(state, objtype, str, id, createflag);
	}
}
,
new Agiddisc_s.alloc() {
	public int function (StarVoid state, int objtype, @Unsigned int id) {
		throw new UnsupportedOperationException();
	}
}
,
new Agiddisc_s.free() {
	public void function (StarVoid state, int objtype, @Unsigned int id) {
		throw new UnsupportedOperationException();
	}
}
,
new Agiddisc_s.print() {
	public StarChar function (StarVoid state, int objtype, @Unsigned int id) {
		throw new UnsupportedOperationException();
	}
}
,
new Agiddisc_s.close() {
	public void function (StarVoid state) {
		throw new UnsupportedOperationException();
	}
}
,
new Agiddisc_s.idregister() {
	public void function (StarVoid state, int objtype, StarVoid obj) {
		idregister(state, objtype, obj);
	}
}
);
// aq30wwcj4ugatsgx0zdtdmeed
// int agmapnametoid(Agraph_t * g, int objtype, char *str, 		  unsigned long *result, int createflag) 
@TranslatedBy("plantuml")
public static boolean agmapnametoid(Agraph_t g, int objtype, StarChar str, @Unsigned StarLong result, boolean createflag) {
    boolean rv;
    if (str!=null && (str.get() != '%')) {
	rv = g.clos.disc.id.map.function(g.clos.state.id, objtype, str, result,
				createflag);
	if (rv)
	    return rv;
    }
    /* either an internal ID, or disc. can't map strings */
    if (str!=null) {
	rv = aginternalmaplookup(g, objtype, str, result);
	if (rv)
	    return rv;
    } else
	rv = false;
    if (createflag) {
	/* get a new anonymous ID, and store in the internal map */
	rv = g.clos.disc.id.map.function(g.clos.state.id, objtype, null, result,
				createflag);
	if (rv && str!=null)
	    aginternalmapinsert(g, objtype, str, result.get());
    }
    return rv;

}

// dwufsd296z6lfmtm7fp4e3tk7
// int agallocid(Agraph_t * g, int objtype, unsigned long request) 
public static Object agallocid() {
throw new UnsupportedOperationException();
}


// cfub4osftc8djs88cq592feu3
// void agfreeid(Agraph_t * g, int objtype, unsigned long id) 
public static Object agfreeid() {
throw new UnsupportedOperationException();
}


// 6zs9b72qqvdtlho9fur2n6rnn
// char *agnameof(void *obj) 
public static Object agnameof() {
throw new UnsupportedOperationException();
}


// emt63ldde99jnwe2vvjal9kt9
// void agregister(Agraph_t * g, int objtype, void *obj) 
@TranslatedBy("plantuml")
public static void agregister(Agraph_t g, int objtype, StarVoid obj) {
	(g.clos.disc.id).idregister.function((g.clos.state.id), objtype, obj);
}

}
