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

public class attr {
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


// cwbgwzo8cprw4eobs3iji59dp
// Dtdisc_t AgDataDictDisc = 
@TranslatedBy("plantuml")
public static Dtdisc_t AgDataDictDisc = new Dtdisc_t(
	new OFFSET(Agsym_t.class, "name"),	/* use symbol name as key */
	size_t.MINUS_ONE, 
	new OFFSET(Agsym_t.class, "link"), 
	null, 
	new Dtfree_f() {
		public void function(Dict_t arg1, StarVoid arg2, Dtdisc_t arg3) {
			freesym(arg1, arg2, arg3);
		}
	}, 
	null, 
	null);  
// 67blfrj9x850g8ccpo9qjer2
// static char DataDictName[] = 
@TranslatedBy("plantuml")
public static StarChar DataDictName = JUtils.asStarChar("_AG_datadict");
// 1qn6s7dwoq08ugdjnmsvdgj6u
// static Agdesc_t ProtoDesc = 
@TranslatedBy("plantuml")
static Agdesc_t ProtoDesc = new Agdesc_t(1, 0, 1, 0, 1, 1);
// 30ftenxl879wmnziizunr5vt1
// static Agraph_t *ProtoGraph
@TranslatedBy("plantuml")
static public Agraph_t ProtoGraph = null;
// 4bm10isw1qq1eqcse8afbxee3
// Agdatadict_t *agdatadict(Agraph_t * g, int cflag) 
@TranslatedBy("plantuml")
public static Agdatadict_t agdatadict(Agraph_t g, boolean cflag) {
    Agdatadict_t rv;
    rv = (Agdatadict_t) aggetrec(g, DataDictName, (false)).castTo(Agdatadict_t.class);
    if (rv!=null || N(cflag))
	return rv;
    init_all_attrs(g);
    rv = (Agdatadict_t) aggetrec(g, DataDictName, (false)).castTo(Agdatadict_t.class);
    return rv;
}

// df61jwzr0vd4o0s9dpqfq097v
// Dict_t *agdictof(Agraph_t * g, int kind) 
@TranslatedBy("plantuml")
public static Dict_t agdictof(Agraph_t g, int kind) {
    Agdatadict_t dd;
    Dict_t dict;
    dd = agdatadict(g, (false));
    if (dd!=null)
	switch (kind) {
	case 0:
	    dict = dd.dict.g;
	    break;
	case 1:
	    dict = dd.dict.n;
	    break;
	case 3:
	case 2:
	    dict = dd.dict.e;
	    break;
	default:
	    agerr(agerrlevel_t.AGERR,"agdictof: unknown kind %d\n", kind);
	    dict = null;
	    break;
    } else
	dict = null;
    return dict;
}

// dbhw2q2jfsz9qwawchy0hxj4i
// Agsym_t *agnewsym(Agraph_t * g, char *name, char *value, int id, int kind) 
@TranslatedBy("plantuml")
public static Agsym_t agnewsym(Agraph_t g, StarChar name, StarChar value, int id, int kind) {
    Agsym_t sym;
    sym = (Agsym_t) agalloc(g, sizeof(Agsym_t.class));
    sym.kind = kind;
    sym.name = agstrdup(g, name);
    sym.defval = agstrdup(g, value);
    sym.id = id;
    return sym;
}

// 5s4tpjeh3jwf722izjq6cm6rq
// static void agcopydict(Dict_t * src, Dict_t * dest, Agraph_t * g, int kind) 
@TranslatedBy("plantuml")
public static void agcopydict(Dict_t src, Dict_t dest, Agraph_t g, int kind) {
    Agsym_t sym, newsym;
    ;
    for (sym = (Agsym_t) src.searchf.function(src,null,0000200); sym!=null;
	 sym = (Agsym_t) src.searchf.function(src,sym,0000010)) {
	newsym = agnewsym(g, sym.name, sym.defval, sym.id, kind);
	newsym.print = sym.print;
	newsym.fixed = sym.fixed;
	dest.searchf.function(dest,newsym,0000001);
    }
}

// 7bz8zo1h4wgfvx0xbw8veum36
// static Agdatadict_t *agmakedatadict(Agraph_t * g) 
@TranslatedBy("plantuml")
public static Agdatadict_t agmakedatadict(Agraph_t g) {
    Agraph_t par;
    Agdatadict_t parent_dd, dd;
    dd = (Agdatadict_t ) agbindrec(g, DataDictName, sizeof(Agdatadict_t.class),
				    (false)).castTo(Agdatadict_t.class);
    dd.dict.n = agdtopen(g, AgDataDictDisc, Dttree);
    dd.dict.e = agdtopen(g, AgDataDictDisc, Dttree);
    dd.dict.g = agdtopen(g, AgDataDictDisc, Dttree);
    if ((par = agparent(g))!=null) {
	parent_dd = agdatadict(par, (false));
	;
	dtview(dd.dict.n, parent_dd.dict.n);
	dtview(dd.dict.e, parent_dd.dict.e);
	dtview(dd.dict.g, parent_dd.dict.g);
    } else {
	if (ProtoGraph!=null && (g != ProtoGraph)) {
	    /* it's not ok to dtview here for several reasons. the proto
	       graph could change, and the sym indices don't match */
	    parent_dd = agdatadict(ProtoGraph, (false));
	    agcopydict(parent_dd.dict.n, dd.dict.n, g, 1);
	    agcopydict(parent_dd.dict.e, dd.dict.e, g, 2);
	    agcopydict(parent_dd.dict.g, dd.dict.g, g, 0);
	}
    }
    return dd;
}

// 50wfzq5wy8wc7vuyvs3mrx5ct
// Agsym_t *agdictsym(Dict_t * dict, char *name) 
@TranslatedBy("plantuml")
public static Agsym_t agdictsym(Dict_t dict, StarChar name) {
    Agsym_t key = new Agsym_t();
    key.name = name;
    return (Agsym_t) dict.searchf.function(dict, key,0000004);
}

// 4wy4ggu70d7harhix8xnh5w4l
// Agsym_t *aglocaldictsym(Dict_t * dict, char *name) 
@TranslatedBy("plantuml")
public static Agsym_t aglocaldictsym(Dict_t dict, StarChar name) {
    Agsym_t rv;
    Dict_t view;
    view = dtview(dict, null);
    rv = agdictsym(dict, name);
    dtview(dict, view);
    return rv;
}

// 8hy9sl3zmwobwm960jz466ufe
// Agsym_t *agattrsym(void *obj, char *name) 
@TranslatedBy("plantuml") 
public static Agsym_t agattrsym(StarVoid obj, StarChar name) {
    Agattr_t data;
    Agsym_t rv;
    StarChar arg = name;
    data = agattrrec((Agobj_t) obj.castTo(Agobj_t.class));
    if (data!=null)
	rv = agdictsym(data.dict, arg);
    else
	rv = null;
    return rv;
}

// covyqfvabl7igx9g5rvlhgngz
// char *AgDataRecName = 
@TranslatedBy("plantuml")
public static StarChar AgDataRecName = JUtils.asStarChar("_AG_strdata");
// dcte0ar3jhmedhz12l3v9u0s7
// static int topdictsize(Agobj_t * obj) 
@TranslatedBy("plantuml")
public static int topdictsize(Agobj_t obj) {
    Dict_t d;
    d = agdictof(agroot(agraphof(obj)), ((((Agobj_t)obj).tag).objtype));
    return d!=null ? dtsize(d) : 0;
}

// 77yubh5i0vnut7rldqgyo4t9t
// static Agrec_t *agmakeattrs(Agraph_t * context, void *obj) 
@TranslatedBy("plantuml")
@NeedReview
public static Agrec_t agmakeattrs(Agraph_t context, StarVoid obj) {
    int sz;
    Agattr_t rec;
    Agsym_t sym;
    Dict_t datadict;
    rec = (Agattr_t) agbindrec(obj, AgDataRecName, sizeof(Agattr_t.class), (false)).castTo(Agattr_t.class);
    datadict = agdictof(context, (((Agobj_t)obj.castTo(Agobj_t.class)).tag.objtype));
    ;
    if (rec.dict == null) {
	rec.dict = agdictof(agroot(context), ((Agobj_t)obj.castTo(Agobj_t.class)).tag.objtype);
	/* don't malloc(0) */
	sz = topdictsize((Agobj_t)obj.castTo(Agobj_t.class));
	if (sz < 4)
	    sz = 4;
	rec.str = (StarStarChar) agalloc(agraphof(obj), size_t.fromInt(sz * 4)).castTo(StarStarChar.class);
	/* doesn't call agxset() so no obj-modified callbacks occur */
	for (sym = (Agsym_t) datadict.searchf.function(datadict,null,0000200); sym!=null;
	     sym = (Agsym_t) datadict.searchf.function(datadict,sym,0000010))
	    rec.str.setBracket(sym.id, agstrdup(agraphof(obj), sym.defval));
    } else {
	;
    }
    return (Agrec_t) rec.castTo(Agrec_t.class);
}

// 50md6kgbmmjiwsq00tdvtqrom
// static void freeattr(Agobj_t * obj, Agattr_t * attr) 
public static Object freeattr() {
throw new UnsupportedOperationException();
}


// 6b3c2syvj23lbf7kz0aal8vmc
// static void freesym(Dict_t * d, void * obj, Dtdisc_t * disc) 
@TranslatedBy("plantuml")
public static void freesym(Dict_t d, StarVoid obj, Dtdisc_t disc) {
throw new UnsupportedOperationException();
}

// 13sfx74lme08ur04vkrqta25j
// Agattr_t *agattrrec(void *obj) 
@TranslatedBy("plantuml") 
public static Agattr_t agattrrec(StarVoid obj) {
    return (Agattr_t) aggetrec(obj, AgDataRecName, (false)).castTo(Agattr_t.class);
}

// 2io7b26wq70e7kwdlzsh6bw7f
// static void addattr(Agraph_t * g, Agobj_t * obj, Agsym_t * sym) 
@TranslatedBy("plantuml")
public static void addattr(Agraph_t g, Agobj_t obj, Agsym_t sym) {
throw new UnsupportedOperationException();
}

// 5tdt5quf2o4swebp87dxpvkle
// static Agsym_t *setattr(Agraph_t * g, int kind, char *name, char *value) 
@TranslatedBy("plantuml")
public static Agsym_t setattr(Agraph_t g, int kind, StarChar name, StarChar value) {
    Agdatadict_t dd;
    Dict_t ldict, rdict;
    Agsym_t lsym, psym, rsym, rv;
    Agraph_t root;
    Agnode_t n;
    Agedge_t e;
    ;
    root = agroot(g);
    dd = agdatadict(g, (N(0)));	/* force initialization of string attributes */
    ldict = agdictof(g, kind);
    lsym = aglocaldictsym(ldict, name);
    if (lsym!=null) {			/* update old local definiton */
	agstrfree(g, lsym.defval);
	lsym.defval = agstrdup(g, value);
	rv = lsym;
    } else {
	psym = agdictsym(ldict, name);	/* search with viewpath up to root */
	if (psym!=null) {		/* new local definition */
	    lsym = agnewsym(g, name, value, psym.id, kind);
	    ldict.searchf.function(ldict,lsym,0000001);
	    rv = lsym;
	} else {		/* new global definition */
	    rdict = agdictof(root, kind);
	    rsym = agnewsym(g, name, value, dtsize(rdict), kind);
	    rdict.searchf.function(rdict,rsym,0000001);
	    switch (kind) {
	    case 0:
		agapply(root, (Agobj_t) root.castTo(Agobj_t.class), new agobjfn_t(){
			public void function(Agraph_t g, Agobj_t obj, StarVoid arg) {
				addattr(g, obj, (Agsym_t) arg);
			}},
			rsym, (N(0)));
		break;
	    case 1:
		for (n = agfstnode(root); n!=null; n = agnxtnode(root, n))
		    addattr(g, (Agobj_t) n.castTo(Agobj_t.class), rsym);
		break;
	    case 3:
	    case 2:
		for (n = agfstnode(root); n!=null; n = agnxtnode(root, n))
		    for (e = agfstout(root, n); e!=null; e = agnxtout(root, e))
			addattr(g, (Agobj_t) e.castTo(Agobj_t.class), rsym);
		break;
	    }
	    rv = rsym;
	}
    }
    if (rv!=null && (kind == 0))
	agxset(g, rv, value);
    agmethod_upd(g, g, rv);	/* JCE and GN wanted this */
    return rv;
}

// 8f80aahwb8cqc2t9592v47ttd
// static Agsym_t *getattr(Agraph_t * g, int kind, char *name) 
@TranslatedBy("plantuml")
public static Agsym_t getattr(Agraph_t g, int kind, StarChar name) {
    Agsym_t rv = null;
    Dict_t dict;
    dict = agdictof(g, kind);
    if (dict!=null)
	rv = agdictsym(dict, name);	/* viewpath up to root */
    return rv;
}

// blr3drm2hxuzwd6gpeeb84yyg
// Agsym_t *agattr(Agraph_t * g, int kind, char *name, char *value) 
@TranslatedBy("plantuml")
public static Agsym_t agattr(Agraph_t g, int kind, StarChar name, StarChar value) {
    Agsym_t rv;

    if (g == null) {
	if (ProtoGraph == null)
	    ProtoGraph = agopen(null, ProtoDesc, null);
	g = ProtoGraph;
    }
    if (value!=null)
	rv = setattr(g, kind, name, value);
    else
	rv = getattr(g, kind, name);
    return rv;
}
// 9medmidrd61ljmzlswpxwuxjm
// Agsym_t *agnxtattr(Agraph_t * g, int kind, Agsym_t * attr) 
public static Object agnxtattr() {
throw new UnsupportedOperationException();
}


// ex2qtmuwz0o2e5svkujdbux78
// void agraphattr_init(Agraph_t * g) 
@TranslatedBy("plantuml")
public static void agraphattr_init(Agraph_t g) {
    /* Agdatadict_t *dd; */
    /* Agrec_t                      *attr; */
    Agraph_t context;
    g.desc.has_attrs = true;
    /* dd = */ agmakedatadict(g);
    if (N(context = agparent(g)))
	context = g;
    /* attr = */ agmakeattrs(context, g);
}
// ccqww3yvujvy82bw6i1m0rv96
// int agraphattr_delete(Agraph_t * g) 
public static Object agraphattr_delete() {
throw new UnsupportedOperationException();
}


// 2pp4ot3pqy71jpfvu3g398y4y
// void agnodeattr_init(Agraph_t * g, Agnode_t * n) 
@TranslatedBy("plantuml") 
public static void agnodeattr_init(Agraph_t g, Agnode_t n) {
    Agattr_t data;
    data = agattrrec(n);
    if ((N(data)) || (N(data.dict)))
	agmakeattrs(g, n);
}

// 7fbhjqpb2w17ahde2ie2l22n5
// void agnodeattr_delete(Agnode_t * n) 
public static Object agnodeattr_delete() {
throw new UnsupportedOperationException();
}


// ckfzmnxfi0jiiayxmq38giw0r
// void agedgeattr_init(Agraph_t * g, Agedge_t * e) 
public static Object agedgeattr_init() {
throw new UnsupportedOperationException();
}


// 3cm42f5o83187rwf4l7j7ie1k
// void agedgeattr_delete(Agedge_t * e) 
public static Object agedgeattr_delete() {
throw new UnsupportedOperationException();
}


// eydjyhexv5jr6vi7uhk0cgphv
// char *agget(void *obj, char *name) 
@TranslatedBy("plantuml") 
public static StarChar agget(StarVoid obj, StarChar name) {
    Agsym_t sym;
    Agattr_t data;
    StarChar rv;
    sym = agattrsym(obj, name);
    if (sym == null)
	rv = null;			/* note was "", but this provides more info */
    else {
	data = agattrrec((Agobj_t) obj);
	rv = data.str.bracket(sym.id);
    }
    return rv;
}

// 9h5oymhfkp6k34zl0fonn10k9
// char *agxget(void *obj, Agsym_t * sym) 
public static Object agxget() {
throw new UnsupportedOperationException();
}


// alc2i3vy4lm57qoc7qn69ppgr
// int agset(void *obj, char *name, char *value) 
public static Object agset() {
throw new UnsupportedOperationException();
}


// 5qac6wmqn56f8fys5kmfka26q
// int agxset(void *obj, Agsym_t * sym, char *value) 
@TranslatedBy("plantuml")
public static int agxset(StarVoid obj, Agsym_t sym, StarChar value) {
throw new UnsupportedOperationException();
}

// 5druywwoxlv9y3ovwmzhtwhto
// int agsafeset(void *obj, char *name, char *value, char *def) 
public static Object agsafeset() {
throw new UnsupportedOperationException();
}


// 6gjlgo4s6r0bu7gjazfee6qv8
// static void init_all_attrs(Agraph_t * g) 
@TranslatedBy("plantuml")
public static void init_all_attrs(Agraph_t g) {
throw new UnsupportedOperationException();
}

// drm4b4gsik02ij9ixg1b9yca5
// int agcopyattr(void *oldobj, void *newobj) 
public static Object agcopyattr() {
throw new UnsupportedOperationException();
}


}
