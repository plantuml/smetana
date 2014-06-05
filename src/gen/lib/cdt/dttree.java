package gen.lib.cdt;
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

public class dttree {
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


// abqfzg1d1vkzk51225tcdlik5
// static void* dttree(Dt_t* dt, void* obj, int type)       
@TranslatedBy("plantuml")
@NeedReview public static StarVoid dttree(Dict_t dt, StarVoid obj, int type) {
	Dtlink_t	root, t=null;
	int		cmp;
	size_t sz;
	OFFSET lk;
	OFFSET ky;
	StarVoid		o, k=null, key=null;
	Dtlink_t	l, r, me=null;
	final Dtlink_t link = new Dtlink_t();
	int		n, minp;
	int turn[] = new int[4*8 - 2];
	Dtcompar_f	cmpf;
	Dtdisc_t	disc;
	if ((dt.data.type&010000)!=0) dtrestore(dt,null);
	disc = dt.disc; ky = disc.key; sz = disc.size; lk = disc.link; cmpf = disc.comparf;
	dt.type &= ~0100000;
	root = dt.data.here;
	if(N(obj))
	{	if(N(root) || N(type&(0000100|0000200|0000400)) )
			return null;
		if((type&0000100)!=0) /* delete all objects */
		{	if(disc.freef!=null || isStrictNegative(disc.link))
			{	do
				{	while((t = root.hl._left())!=null )
						{ root.hl._left(t.right); t.right = root; root = t;}
					t = root.right;
					if(disc.freef!=null)
						disc.freef.function(dt,(isStrictNegative(lk) ? ((Dthold_t)(root.castTo(Dthold_t.class))).obj : root.substractByte(lk) ),disc);
					if(isStrictNegative(disc.link))
						dt.memoryf.function(dt,root,null,disc);
				} while((root = t)!=null );
			}
			dt.data.size = 0;
			dt.data.here = null;
			return null;
		}
		else /* computing largest/smallest element */
		{	if((type&0000400)!=0)
			{	while((t = root.right)!=null )
					{root.right = t.hl._left(); t.hl._left(root); root = t;}
			}
			else /* type&DT_FIRST */
			{	while((t = root.hl._left())!=null )
					{root.hl._left(t.right); t.right = root; root = t;}
			}
			dt.data.here = root;
			return (isStrictNegative(lk) ? ((Dthold_t)(root.castTo(Dthold_t.class))).obj : root.substractByte(lk) );
		}
	}
	/* note that link.right is LEFT tree and link.left is RIGHT tree */
	l = r = link;
	/* allow apps to delete an object "actually" in the dictionary */
	if(dt.meth.type == 0000010 && (type&(0000002|0010000))!=0 )
	{	key = isStrictNegative(sz)  ? ((StarStarChar)obj.addByte(ky)).get() : obj.addByte(ky);
		for(o = dt.searchf.function(dt,obj,0000004); o!=null; o = dt.searchf.function(dt,o,0000010) )
		{	k = isStrictNegative(sz)  ? ((StarStarChar)o.addByte(ky)).get() : o.addByte(ky);
			if((cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
				break;
			if(o == obj)
			{	root = dt.data.here;
				l.right = root.hl._left();
				r.hl._left(root.right);
				return dttree_goto_dt_delete();
			}
		}
	}
	boolean dttree_goto_do_search = false;
	if((type&(0001000|0000004|0000001|0004000))!=0)
	{	key = ((type&0001000)!=0) ? obj : isStrictNegative(sz)  ? ((StarStarChar)obj.addByte(ky)).get() : obj.addByte(ky);
		if(root!=null)
			dttree_goto_do_search = true;
	}
	else if((type&0000040)!=0)
	{	me = (Dtlink_t)obj;
		obj = isStrictNegative(lk) ? ((Dthold_t)me.castTo(Dthold_t.class)).obj : me.substractByte(lk);
		key = isStrictNegative(sz)  ? ((StarStarChar)obj.addByte(ky)).get() : obj.addByte(ky);
		if(root!=null)
			dttree_goto_do_search = true;
	}
	else if(root!=null && (isStrictNegative(lk) ? ((Dthold_t)root.castTo(Dthold_t.class)).obj : root.substractByte(lk) ) != obj)
	{	key = isStrictNegative(sz)  ? ((StarStarChar)obj.addByte(ky)).get() : obj.addByte(ky);
		dttree_goto_do_search = true;
	}
	if (dttree_goto_do_search) {
		if(dt.meth.type == 0000004 &&
		   (minp = dt.data.minp) != 0 && (type&(0001000|0000004))!=0 )
		{	/* simple search, note that minp should be even */
			for(t = root, n = 0; n < minp; ++n)
			{	k = (isStrictNegative(lk) ? ((Dthold_t)t.castTo(Dthold_t.class)).obj : t.substractByte(lk) ); k = isStrictNegative(sz)  ? ((StarStarChar)k.addByte(ky)).get() : k.addByte(ky);
				if((cmp = (cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) )) == 0)
					return (isStrictNegative(lk) ? ((Dthold_t)t.castTo(Dthold_t.class)).obj : t.substractByte(lk) );
				else
				{	turn[n] = cmp;	
					if(N(t = cmp < 0 ? t.hl._left() : t.right) )
						return null;
				}
			}
			/* exceed search length, top-down splay now */
			for(n = 0; n < minp; n += 2)
			{	if(turn[n] < 0)
				{	t = root.hl._left();
					if(turn[n+1] < 0)
					{	root.hl._left(t.right); t.right = root;
						r = r.hl._left(t);
						root = t.hl._left();
					}
					else
					{	l = l.right = t;
						r = r.hl._left(root);
						root = t.right;
					}
				}
				else
				{	t = root.right;
					if(turn[n+1] > 0)
					{	root.right = t.hl._left(); t.hl._left(root);
						l = l.right = t;
						root = t.right;
					}
					else
					{	r = r.hl._left(t);
						l = l.right = root;
						root = t.hl._left();
					}
				}
			}
		}
		while(true)
		{	k = (isStrictNegative(lk) ? ((Dthold_t)root.castTo(Dthold_t.class)).obj : root.substractByte(lk) ); k = isStrictNegative(sz)  ? ((StarStarChar)k.addByte(ky)).get() : k.addByte(ky);
			if((cmp = (cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) )) == 0)
				break;
			else if(cmp < 0)
			{	if((t = root.hl._left())!=null )
				{	k = isStrictNegative(lk) ? ((Dthold_t)t.castTo(Dthold_t.class)).obj : t.substractByte(lk); k = isStrictNegative(sz)  ? ((StarStarChar)k.addByte(ky)).get() : k.addByte(ky);
					if((cmp = (cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) )) < 0)
					{	root.hl._left(t.right); t.right = root;
						r = r.hl._left(t);
						if(N(root = t.hl._left()) )
							break;
					}
					else if(cmp == 0)
					{	r = r.hl._left(root);
						root = t;
						break;
					}
					else /* if(cmp > 0) */
					{	l = l.right = t ;
						r = r.hl._left(root);
						if(N(root = t.right) )
							break;
					}
				}
				else
				{	r = r.hl._left(root);
					root = null;
					break;
				}
			}
			else /* if(cmp > 0) */
			{	if((t = root.right)!=null )
				{	k = isStrictNegative(lk) ? ((Dthold_t)t.castTo(Dthold_t.class)).obj : t.substractByte(lk); k = isStrictNegative(sz)  ? ((StarStarChar)k.addByte(ky)).get() : k.addByte(ky);
					if((cmp = (cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) )) > 0)
					{	root.right = t.hl._left(); t.hl._left(root);
						l = l.right = t;
						if(N(root = t.right) )
							break;
					}
					else if(cmp == 0)
					{	l = l.right = root;
						root = t;
						break;
					}
					else /* if(cmp < 0) */
					{	r = r.hl._left(t);
						l = l.right = root;
						if(N(root = t.hl._left()) )
							break;
					}
				}
				else
				{	l = l.right = root;
					root = null;
					break;
				}
			}
		}		
	}
	if(root!=null)
	{	/* found it, now isolate it */
		dt.type |= 0100000;
		l.right = root.hl._left();
		r.hl._left(root.right);
		if((type&(0000004|0001000))!=0)
		{
			return goto_has_root(root, link, type, key, dt, lk, r, t, k, sz, ky, cmpf, disc);
		}
		else if((type&0000010)!=0)
		{	root.hl._left(link.right);
		root.right = null;
		link.right = root;
		return goto_dt_next(root, link, t, r, dt, obj, type, key, lk, k, sz, ky, cmpf, disc);
		}
		else if((type&0000020)!=0)
		{
throw new UnsupportedOperationException();
		}
		else if((type&(0000002|0010000))!=0)
		{	/* taking an object out of the dictionary */
throw new UnsupportedOperationException();
		}
		else if((type&(0000001|0004000))!=0)
		{
throw new UnsupportedOperationException();
		}
		else if((type&0000040)!=0) /* a duplicate */
		{
throw new UnsupportedOperationException();
		}
throw new UnsupportedOperationException();
	}
	else
	{	/* not found, finish up LEFT and RIGHT trees */
		r.hl._left(null);
		l.right = null;
		if((type&0000010)!=0)
			return goto_dt_next(root, link, t, r, dt, obj, type, key, lk, k, sz, ky, cmpf, disc);
		else if((type&0000020)!=0)
			return goto_dt_prev();
		else if((type&(0000004|0001000))!=0)
		{ return goto_no_root(t, r, dt, link, obj, type);
		}
		else if((type&(0000001|0004000))!=0)
		{ return goto_dt_insert(disc, type, obj, lk, root, dt, t, r, link, key, k, sz, ky, cmpf);
		}
		else if((type&0000040)!=0)
		{	root = me;
			dt.data.size += 1;
			return goto_has_root(root, link, type, key, dt, lk, r, t, k, sz, ky, cmpf, disc);
		}
		else /*if(type&DT_DELETE)*/
		{	obj = null;
			return goto_no_root(t, r, dt, link, obj, type);
		}
	}
}
private static StarVoid goto_no_root(Dtlink_t t, Dtlink_t r, Dict_t dt, Dtlink_t link, StarVoid obj, int type) {
	while((t = r.hl._left())!=null )
		r = t;
	r.hl._left(link.right);
	dt.data.here = link.hl._left();
	return (type&0000002)!=0 ? obj : null;
	}
private static StarVoid goto_dt_insert(Dtdisc_t disc, int type, StarVoid obj, OFFSET lk, Dtlink_t root, Dict_t dt, Dtlink_t t, Dtlink_t r, Dtlink_t link, StarVoid key, StarVoid k, size_t sz, OFFSET ky, Dtcompar_f cmpf) {
			if(disc.makef!=null && (type&0000001)!=0)
				obj = disc.makef.function(dt,obj,disc);
			if(obj!=null)
			{	if(isPositiveOrZero(lk))
					root = (Dtlink_t) obj.addByte(lk).castTo(Dtlink_t.class);
				else
				{	root = (Dtlink_t) dt.memoryf.function
						(dt,null,sizeof(Dthold_t.class),disc);
					if(root!=null)
						((Dthold_t)root.castTo(Dthold_t.class)).obj = obj;
					else if(disc.makef!=null && disc.freef!=null &&
						(type&0000001)!=0)
						disc.freef.function(dt,obj,disc);
				}
			}
			if(root!=null)
			{	if(dt.data.size >= 0)
					dt.data.size += 1;
				return goto_has_root(root, link, type, key, dt, lk, r, t, k, sz, ky, cmpf, disc);
			}
			else	return goto_no_root(t, r, dt, link, obj, type);
	}
private static StarVoid goto_has_root(Dtlink_t root, Dtlink_t link, int type, StarVoid key, Dict_t dt, OFFSET lk, Dtlink_t r, Dtlink_t t, StarVoid k, size_t sz, OFFSET ky, Dtcompar_f cmpf, Dtdisc_t disc) {
			root.hl._left(link.right);
			root.right = link.hl._left();
			if((dt.meth.type&0000010)!=0 && (type&(0000004|0001000))!=0 )
			{	key = (isStrictNegative(lk) ? ((Dthold_t)root.castTo(Dthold_t.class)).obj : root.substractByte(lk) ); key = (isStrictNegative(sz)  ? ((StarStarChar)key.addByte(ky)).get() : key.addByte(ky));
				while((t = root.hl._left())!=null )
				{	/* find max of left subtree */
					while((r = t.right)!=null )
						t.right = r.hl._left(); r.hl._left(t); t = r;
					root.hl._left(t);
					/* now see if it's in the same group */
					k = (isStrictNegative(lk) ? ((Dthold_t)t.castTo(Dthold_t.class)).obj : t.substractByte(lk) ); k = isStrictNegative(sz) ? ((StarStarChar)k.addByte(ky)).get() : k.addByte(ky);
					if((cmpf!=null ? cmpf.function(dt,key,k,disc) : (isNegativeOrNull(sz) ?strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
						break;
					root.hl._left(t.right); t.right = root; root = t;
				}
			}
			dt.data.here = root;
			return (isStrictNegative(lk) ? ((Dthold_t)(root.castTo(Dthold_t.class))).obj : root.substractByte(lk) );
	}
private static StarVoid dttree_goto_dt_delete() {
	throw new UnsupportedOperationException();
	}
private static StarVoid goto_dt_next(Dtlink_t root, Dtlink_t link, Dtlink_t t, Dtlink_t r, Dict_t dt, StarVoid obj, int type,
		StarVoid key, OFFSET lk, StarVoid k, size_t sz, OFFSET ky, Dtcompar_f cmpf, Dtdisc_t disc) {
	if((root = link.hl._left())!=null )	
	{	while((t = root.hl._left())!=null )
			root.hl._left(t.right); t.right = root; root = t;
		link.hl._left(root.right);
		return goto_has_root(root, link, type, key, dt, lk, r, t, k, sz, ky, cmpf, disc);
	}
	else	return goto_no_root(t, r, dt, link, obj, type);
}
private static StarVoid goto_dt_prev() {
throw new UnsupportedOperationException();
}
// 9g22bw0wprm2n836sva9a545j
// static Dtmethod_t	_Dtoset =  
@TranslatedBy("plantuml") 
public static Dtmethod_t _Dtoset = new Dtmethod_t(new Dtsearch_f() {
	public StarVoid function(Dict_t arg1, StarVoid arg2, int arg3) {
	    return dttree(arg1, arg2, arg3);
	}
}, 0000004);
// 6lntjtw57dbb52lukeu9qbjm0
// static Dtmethod_t	_Dtobag =  


// 23jnfpje5fw0aejl101d0mofi
// Dtmethod_t* Dtoset = &_Dtoset
@TranslatedBy("plantuml") 
public static Dtmethod_t Dtoset = _Dtoset;
// b8q5rjkvf93u0f27esfu3h9ay
// Dtmethod_t* Dtobag = &_Dtobag


// 5kf1n1yhdy9ojgc0mc3pyowaz
// Dtmethod_t		_Dttree = 
@TranslatedBy("plantuml")
public static Dtmethod_t _Dttree = new Dtmethod_t(new Dtsearch_f() {
	public StarVoid function(Dict_t arg1, StarVoid arg2, int arg3) {
	    return dttree(arg1, arg2, arg3);
	}
}, 0000004);
// bvfgwxg0ik8j0au3xhv5ear7h
// Dtmethod_t* Dtorder = &_Dttree


// avyrqfvu00yyj95dihtoiwmao
// Dtmethod_t* Dttree = &_Dttree
@TranslatedBy("plantuml")
public static Dtmethod_t Dttree = _Dttree;
}
