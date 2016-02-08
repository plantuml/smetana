/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 *
 *
 *
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************
 *
 */
package gen.lib.cgraph;
import h.*;
import smetana.core.*;
import static smetana.core.Macro.*;
import static smetana.core.JUtils.*;
import static gen.lib.cdt.dtclose__c.*;
import static gen.lib.cdt.dtdisc__c.*;
import static gen.lib.cdt.dtextract__c.*;
import static gen.lib.cdt.dtflatten__c.*;
import static gen.lib.cdt.dthash__c.*;
import static gen.lib.cdt.dtlist__c.*;
import static gen.lib.cdt.dtmethod__c.*;
import static gen.lib.cdt.dtopen__c.*;
import static gen.lib.cdt.dtrenew__c.*;
import static gen.lib.cdt.dtrestore__c.*;
import static gen.lib.cdt.dtsize__c.*;
import static gen.lib.cdt.dtstat__c.*;
import static gen.lib.cdt.dtstrhash__c.*;
import static gen.lib.cdt.dttreeset__c.*;
import static gen.lib.cdt.dttree__c.*;
import static gen.lib.cdt.dtview__c.*;
import static gen.lib.cdt.dtwalk__c.*;
import static gen.lib.cgraph.agerror__c.*;
import static gen.lib.cgraph.agxbuf__c.*;
import static gen.lib.cgraph.apply__c.*;
import static gen.lib.cgraph.attr__c.*;
import static gen.lib.cgraph.cmpnd__c.*;
import static gen.lib.cgraph.edge__c.*;
import static gen.lib.cgraph.flatten__c.*;
import static gen.lib.cgraph.grammar__c.*;
import static gen.lib.cgraph.graph__c.*;
import static gen.lib.cgraph.id__c.*;
import static gen.lib.cgraph.imap__c.*;
import static gen.lib.cgraph.io__c.*;
import static gen.lib.cgraph.main__c.*;
import static gen.lib.cgraph.mem__c.*;
import static gen.lib.cgraph.node__c.*;
import static gen.lib.cgraph.obj__c.*;
import static gen.lib.cgraph.pend__c.*;
import static gen.lib.cgraph.rec__c.*;
import static gen.lib.cgraph.refstr__c.*;
import static gen.lib.cgraph.scan__c.*;
import static gen.lib.cgraph.subg__c.*;
import static gen.lib.cgraph.tester__c.*;
import static gen.lib.cgraph.utils__c.*;
import static gen.lib.cgraph.write__c.*;
import static gen.lib.cgraph.y_tab__c.*;
import static gen.lib.circogen.blockpath__c.*;
import static gen.lib.circogen.blocktree__c.*;
import static gen.lib.circogen.block__c.*;
import static gen.lib.circogen.circpos__c.*;
import static gen.lib.circogen.circularinit__c.*;
import static gen.lib.circogen.circular__c.*;
import static gen.lib.circogen.deglist__c.*;
import static gen.lib.circogen.edgelist__c.*;
import static gen.lib.circogen.nodelist__c.*;
import static gen.lib.circogen.nodeset__c.*;
import static gen.lib.common.args__c.*;
import static gen.lib.common.arrows__c.*;
import static gen.lib.common.colxlate__c.*;
import static gen.lib.common.ellipse__c.*;
import static gen.lib.common.emit__c.*;
import static gen.lib.common.geom__c.*;
import static gen.lib.common.globals__c.*;
import static gen.lib.common.htmllex__c.*;
import static gen.lib.common.htmlparse__c.*;
import static gen.lib.common.htmltable__c.*;
import static gen.lib.common.input__c.*;
import static gen.lib.common.intset__c.*;
import static gen.lib.common.labels__c.*;
import static gen.lib.common.memory__c.*;
import static gen.lib.common.ns__c.*;
import static gen.lib.common.output__c.*;
import static gen.lib.common.pointset__c.*;
import static gen.lib.common.postproc__c.*;
import static gen.lib.common.psusershape__c.*;
import static gen.lib.common.routespl__c.*;
import static gen.lib.common.shapes__c.*;
import static gen.lib.common.splines__c.*;
import static gen.lib.common.strcasecmp__c.*;
import static gen.lib.common.strncasecmp__c.*;
import static gen.lib.common.taper__c.*;
import static gen.lib.common.textspan__c.*;
import static gen.lib.common.timing__c.*;
import static gen.lib.common.utils__c.*;
import static gen.lib.common.y_tab__c.*;
import static gen.lib.dotgen.acyclic__c.*;
import static gen.lib.dotgen.aspect__c.*;
import static gen.lib.dotgen.class1__c.*;
import static gen.lib.dotgen.class2__c.*;
import static gen.lib.dotgen.cluster__c.*;
import static gen.lib.dotgen.compound__c.*;
import static gen.lib.dotgen.conc__c.*;
import static gen.lib.dotgen.decomp__c.*;
import static gen.lib.dotgen.dotinit__c.*;
import static gen.lib.dotgen.dotsplines__c.*;
import static gen.lib.dotgen.fastgr__c.*;
import static gen.lib.dotgen.flat__c.*;
import static gen.lib.dotgen.mincross__c.*;
import static gen.lib.dotgen.position__c.*;
import static gen.lib.dotgen.rank__c.*;
import static gen.lib.dotgen.sameport__c.*;
import static gen.lib.dotgen2.decomp__c.*;
import static gen.lib.dotgen2.dotinit__c.*;
import static gen.lib.dotgen2.groups__c.*;
import static gen.lib.dotgen2.level__c.*;
import static gen.lib.dotgen2.minc2__c.*;
import static gen.lib.dotgen2.minc_utils__c.*;
import static gen.lib.dotgen2.ns__c.*;
import static gen.lib.fdpgen.clusteredges__c.*;
import static gen.lib.fdpgen.comp__c.*;
import static gen.lib.fdpgen.dbg__c.*;
import static gen.lib.fdpgen.fdpinit__c.*;
import static gen.lib.fdpgen.grid__c.*;
import static gen.lib.fdpgen.layout__c.*;
import static gen.lib.fdpgen.tlayout__c.*;
import static gen.lib.fdpgen.xlayout__c.*;
import static gen.lib.gvc.gvbuffstderr__c.*;
import static gen.lib.gvc.gvconfig__c.*;
import static gen.lib.gvc.gvcontext__c.*;
import static gen.lib.gvc.gvc__c.*;
import static gen.lib.gvc.gvdevice__c.*;
import static gen.lib.gvc.gvevent__c.*;
import static gen.lib.gvc.gvjobs__c.*;
import static gen.lib.gvc.gvlayout__c.*;
import static gen.lib.gvc.gvloadimage__c.*;
import static gen.lib.gvc.gvplugin__c.*;
import static gen.lib.gvc.gvrender__c.*;
import static gen.lib.gvc.gvtextlayout__c.*;
import static gen.lib.gvc.gvusershape__c.*;
import static gen.lib.gvc.regex_win32__c.*;
import static gen.lib.label.index__c.*;
import static gen.lib.label.node__c.*;
import static gen.lib.label.nrtmain__c.*;
import static gen.lib.label.rectangle__c.*;
import static gen.lib.label.split_q__c.*;
import static gen.lib.label.xlabels__c.*;
import static gen.lib.ortho.fPQ__c.*;
import static gen.lib.ortho.maze__c.*;
import static gen.lib.ortho.ortho__c.*;
import static gen.lib.ortho.partition__c.*;
import static gen.lib.ortho.rawgraph__c.*;
import static gen.lib.ortho.sgraph__c.*;
import static gen.lib.ortho.trapezoid__c.*;
import static gen.lib.pack.ccomps__c.*;
import static gen.lib.pack.pack__c.*;
import static gen.lib.pack.ptest__c.*;
import static gen.lib.pathplan.cvt__c.*;
import static gen.lib.pathplan.inpoly__c.*;
import static gen.lib.pathplan.route__c.*;
import static gen.lib.pathplan.shortestpth__c.*;
import static gen.lib.pathplan.shortest__c.*;
import static gen.lib.pathplan.solvers__c.*;
import static gen.lib.pathplan.triang__c.*;
import static gen.lib.pathplan.util__c.*;
import static gen.lib.pathplan.visibility__c.*;
import static gen.lib.xdot.xdot__c.*;

public class edge__c {
//1 9k44uhd5foylaeoekf3llonjq
// extern Dtmethod_t* 	Dtset


//1 1ahfywsmzcpcig2oxm7pt9ihj
// extern Dtmethod_t* 	Dtbag


//1 anhghfj3k7dmkudy2n7rvt31v
// extern Dtmethod_t* 	Dtoset


//1 5l6oj1ux946zjwvir94ykejbc
// extern Dtmethod_t* 	Dtobag


//1 2wtf222ak6cui8cfjnw6w377z
// extern Dtmethod_t*	Dtlist


//1 d1s1s6ibtcsmst88e3057u9r7
// extern Dtmethod_t*	Dtstack


//1 axa7mflo824p6fspjn1rdk0mt
// extern Dtmethod_t*	Dtqueue


//1 ega812utobm4xx9oa9w9ayij6
// extern Dtmethod_t*	Dtdeque


//1 cyfr996ur43045jv1tjbelzmj
// extern Dtmethod_t*	Dtorder


//1 wlofoiftbjgrrabzb2brkycg
// extern Dtmethod_t*	Dttree


//1 12bds94t7voj7ulwpcvgf6agr
// extern Dtmethod_t*	Dthash


//1 9lqknzty480cy7zsubmabkk8h
// extern Dtmethod_t	_Dttree


//1 bvn6zkbcp8vjdhkccqo1xrkrb
// extern Dtmethod_t	_Dthash


//1 9lidhtd6nsmmv3e7vjv9e10gw
// extern Dtmethod_t	_Dtlist


//1 34ujfamjxo7xn89u90oh2k6f8
// extern Dtmethod_t	_Dtqueue


//1 3jy4aceckzkdv950h89p4wjc8
// extern Dtmethod_t	_Dtstack


//1 8dfqgf3u1v830qzcjqh9o8ha7
// extern Agmemdisc_t AgMemDisc


//1 18k2oh2t6llfsdc5x0wlcnby8
// extern Agiddisc_t AgIdDisc


//1 a4r7hi80gdxtsv4hdoqpyiivn
// extern Agiodisc_t AgIoDisc


//1 bnzt5syjb7mgeru19114vd6xx
// extern Agdisc_t AgDefaultDisc


//1 35y2gbegsdjilegaribes00mg
// extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,     Agstrictundirected


//1 c2rygslq6bcuka3awmvy2b3ow
// typedef Agsubnode_t	Agnoderef_t


//1 xam6yv0dcsx57dtg44igpbzn
// typedef Dtlink_t	Agedgeref_t


//1 6ayavpu39aihwyojkx093pcy3
// extern Agraph_t *Ag_G_global


//1 871mxtg9l6ffpxdl9kniwusf7
// extern char *AgDataRecName


//1 c0o2kmml0tn6hftuwo0u4shwd
// extern Dtdisc_t Ag_subnode_id_disc


//1 8k15pyu256unm2kpd9zf5pf7k
// extern Dtdisc_t Ag_subnode_seq_disc


//1 e3d820y06gpeusn6atgmj8bzd
// extern Dtdisc_t Ag_mainedge_id_disc


//1 cbr0772spix9h1aw7h5v7dv9j
// extern Dtdisc_t Ag_subedge_id_disc


//1 akd0c3v0j7m2npxcb9acit1fa
// extern Dtdisc_t Ag_mainedge_seq_disc


//1 12d8la07351ww7vwfzucjst8m
// extern Dtdisc_t Ag_subedge_seq_disc


//1 29eokk7v88e62g8o6lizmo967
// extern Dtdisc_t Ag_subgraph_id_disc


//1 4xd9cbgy6hk5g6nhjcbpzkx14
// extern Agcbdisc_t AgAttrdisc


//1 cee3kc2m61ml4f8le5ueoyrjb
// static Agtag_t Tag
private final static __struct__<Agtag_s> Tag = __struct__.from(Agtag_s.class);



//3 9vamtktowqtk4955i546z9obw
// Agedge_t *agfstout(Agraph_t * g, Agnode_t * n) 
public static Agedge_s agfstout(Agraph_s g, Agnode_s n) {
ENTERING("9vamtktowqtk4955i546z9obw","agfstout");
try {
    Agsubnode_s sn;
    Agedge_s e = null;
    sn = agsubrep(g, n);
    if (sn!=null) {
		dtrestore((_dt_s)g.getPtr("e_seq"), (_dtlink_s)sn.getPtr("out_seq"));
		e = (Agedge_s)  g.getPtr("e_seq").castTo(_dt_s.class).call("searchf", g.getPtr("e_seq"),null,0000200);
		sn.setPtr("out_seq", dtextract((_dt_s)g.getPtr("e_seq")));
	}
    return e;
} finally {
LEAVING("9vamtktowqtk4955i546z9obw","agfstout");
}
}




//3 1qh7mgqwomkdqvczauv4ex1lu
// Agedge_t *agnxtout(Agraph_t * g, Agedge_t * e) 
public static Agedge_s agnxtout(Agraph_s g, Agedge_s e) {
ENTERING("1qh7mgqwomkdqvczauv4ex1lu","agnxtout");
try {
    Agnode_s n;
    Agsubnode_s sn;
    Agedge_s f = null;
    n = AGTAIL(e);
    sn = agsubrep(g, n);
    if (sn!=null) {
		dtrestore((_dt_s)g.getPtr("e_seq"), (_dtlink_s)sn.getPtr("out_seq"));
		f = (Agedge_s) g.getPtr("e_seq").castTo(_dt_s.class).call("searchf", g.getPtr("e_seq"),e,0000010);
		sn.setPtr("out_seq", dtextract((_dt_s)g.getPtr("e_seq")));
	}
    return f;
} finally {
LEAVING("1qh7mgqwomkdqvczauv4ex1lu","agnxtout");
}
}




//3 c60qt3ycq0xweabgtqt16xe93
// Agedge_t *agfstin(Agraph_t * g, Agnode_t * n) 
public static Object agfstin(Object... arg) {
UNSUPPORTED("4takk0440p4yrpvuqkacjil0n"); // Agedge_t *agfstin(Agraph_t * g, Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2llbfi4jrmre7cyhu90pgcm72"); //     Agsubnode_t *sn;
UNSUPPORTED("9r7zueep91p3cfc0mbh78ebg6"); //     Agedge_t *e = ((Agedge_t*)0);
UNSUPPORTED("b0wzl2qtz6anq1dhlxtmvwvgn"); //     sn = agsubrep(g, n);
UNSUPPORTED("64ql1cd8hmmmnqnhfvf1st6qr"); // 	if (sn) {
UNSUPPORTED("bwae286ybix28ku0fyaju52wr"); // 		dtrestore(g->e_seq, sn->in_seq);
UNSUPPORTED("5jn8cy5c6ff47r521cc976a82"); // 		e = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(0),0000200);
UNSUPPORTED("bnsdycmdzrxwuzp2l4l5ypqrz"); // 		sn->in_seq = dtextract(g->e_seq);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("2bswif6w6ot01ynlvkimntfly"); //     return e;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 f2af4x97mqn16npd6alsw7avs
// Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e) 
public static Object agnxtin(Object... arg) {
UNSUPPORTED("eq6lndp7wou5f1wdf59vob1g6"); // Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2jcii9cclu1dijzqekzc175pe"); //     Agnode_t *n;
UNSUPPORTED("2llbfi4jrmre7cyhu90pgcm72"); //     Agsubnode_t *sn;
UNSUPPORTED("e9fpg2a29j5gprdt0ykeit9ci"); //     Agedge_t *f = ((Agedge_t*)0);
UNSUPPORTED("30x87nopz7bz801xgx6uot5ag"); //     n = AGHEAD(e);
UNSUPPORTED("b0wzl2qtz6anq1dhlxtmvwvgn"); //     sn = agsubrep(g, n);
UNSUPPORTED("64ql1cd8hmmmnqnhfvf1st6qr"); // 	if (sn) {
UNSUPPORTED("bwae286ybix28ku0fyaju52wr"); // 		dtrestore(g->e_seq, sn->in_seq);
UNSUPPORTED("95pmhj4qgcb45cy0p2qvmq625"); // 		f = (Agedge_t *) (*(((Dt_t*)(g->e_seq))->searchf))((g->e_seq),(void*)(e),0000010);
UNSUPPORTED("bnsdycmdzrxwuzp2l4l5ypqrz"); // 		sn->in_seq = dtextract(g->e_seq);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("6una2eqzhvv9d6c21xay2vdyo"); // 	return f;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6nwyo5bklramr0d093aa1h25o
// Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n) 
public static Object agfstedge(Object... arg) {
UNSUPPORTED("peomnniyk2wddlbnttj52z2y"); // Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2k85xnpgz2z3cqtrecvkjcy3h"); //     Agedge_t *rv;
UNSUPPORTED("6lrg6z89kfk6zfp15kgjh4vcb"); //     rv = agfstout(g, n);
UNSUPPORTED("3p57ktz7acp0mq0zkclnqlxhk"); //     if (rv == ((Agedge_t*)0))
UNSUPPORTED("2xb2q0untgtls729sxast2t8n"); // 	rv = agfstin(g, n);
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8zy2u6gsi2xzv2ffv8o4v4uvf
// Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n) 
public static Object agnxtedge(Object... arg) {
UNSUPPORTED("81ss5mfnxewi5b2rbpe12qelo"); // Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2k85xnpgz2z3cqtrecvkjcy3h"); //     Agedge_t *rv;
UNSUPPORTED("1yqoah4iedlwafbspixhgpiy8"); //     if (AGTYPE(e) == AGOUTEDGE) {
UNSUPPORTED("6ahaw1pqeg3n6x3kcqqfexojt"); // 	rv = agnxtout(g, e);
UNSUPPORTED("cxg3q14hn3xpezhgam8fna6m"); // 	if (rv == ((Agedge_t*)0)) {
UNSUPPORTED("4fxvu5anbh1w3aofrs0xesi4f"); // 	    do {
UNSUPPORTED("f4y8kovvtyqm9m2wj65temntr"); // 		rv = !rv ? agfstin(g, n) : agnxtin(g,rv);
UNSUPPORTED("afdp7kn52vss5qmlrhc58hpch"); // 	    } while (rv && (rv->node == n));
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("8vxyvy38lzpbd83cu26nejaan"); // 	do {
UNSUPPORTED("3gag18j9w2k92asp2ee8phmtj"); // 	    rv = agnxtin(g, e);		/* so that we only see each edge once, */
UNSUPPORTED("6ycty4n35xkayb6krwwfpkyqd"); // 		e = rv;
UNSUPPORTED("b9imavm9kktk7knqkcvmwiako"); // 	} while (rv && (rv->node == n));	/* ignore loops as in-edges */
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c175o6j61jqmfnl4o1g1h1mie
// static Agedge_t *agfindedge_by_key(Agraph_t * g, Agnode_t * t, Agnode_t * h, 			    Agtag_t key) 
public static Agedge_s agfindedge_by_key(Agraph_s g, Agnode_s t, Agnode_s h,  final __struct__<Agtag_s> key) {
// WARNING!! STRUCT
return agfindedge_by_key_w_(g, t, h, key.copy());
}
private static Agedge_s agfindedge_by_key_w_(Agraph_s g, Agnode_s t, Agnode_s h,  final __struct__<Agtag_s> key) {
ENTERING("c175o6j61jqmfnl4o1g1h1mie","agfindedge_by_key");
try {
    Agedge_s e, template = (Agedge_s) Memory.malloc(Agedge_s.class);
    Agsubnode_s sn;
    if ((t == null) || (h == null))
	return null;
    template.getStruct("base").setStruct("tag", key);
    template.setPtr("node", t);		/* guess that fan-in < fan-out */
    sn = agsubrep(g, h);
    if (N(sn)) e = null;
    else {
	    dtrestore((_dt_s)g.getPtr("e_id"), (_dtlink_s)sn.getPtr("in_id"));
	    e = (Agedge_s) ((__ptr__)g.getPtr("e_id").castTo(_dt_s.class).call("searchf", g.getPtr("e_id"),template,0000004));
	    if (e!=null) e = (Agedge_s) e.castTo(Agedge_s.class);
	    sn.setPtr("in_id", dtextract((_dt_s)g.getPtr("e_id")));
    }
    return e;
} finally {
LEAVING("c175o6j61jqmfnl4o1g1h1mie","agfindedge_by_key");
}
}




//3 7ph1egysh0yp1kxmrerg5v40e
// static Agedge_t *agfindedge_by_id(Agraph_t * g, Agnode_t * t, Agnode_t * h, 				  unsigned long id) 
public static Object agfindedge_by_id(Object... arg) {
UNSUPPORTED("ec9zslg8lac601i0b25y7zwto"); // static Agedge_t *agfindedge_by_id(Agraph_t * g, Agnode_t * t, Agnode_t * h,
UNSUPPORTED("3aq1nzyk7buuizn5in1tizrxw"); // 				  unsigned long id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("e1mtghvcaueacf53mmdm4tfy0"); //     Agtag_t tag;
UNSUPPORTED("9sao87j2usq1a87o75iju8s5b"); //     tag = Tag;
UNSUPPORTED("8ftb0g8ykm4jkjpro0pcai75y"); //     tag.objtype = AGEDGE;
UNSUPPORTED("4dwsgoqnwiy82putqjt97dagp"); //     tag.id = id;
UNSUPPORTED("57t26f9vd4vltjvoz5m7lo5lf"); //     return agfindedge_by_key(g, t, h, tag);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 b32ssm6ex1pdz1b3nt4fwlhul
// Agsubnode_t *agsubrep(Agraph_t * g, Agnode_t * n) 
public static Agsubnode_s agsubrep(Agraph_s g, Agnode_s n) {
ENTERING("b32ssm6ex1pdz1b3nt4fwlhul","agsubrep");
try {
    Agsubnode_s sn;
    final __struct__<Agsubnode_s> template = __struct__.from(Agsubnode_s.class);
	if (EQ(g, n.getPtr("root"))) sn = (Agsubnode_s) n.getStruct("mainsub").amp();
	else {
			template.setPtr("node", n);
			sn = (Agsubnode_s) g.getPtr("n_id").castTo(_dt_s.class).call("searchf", g.getPtr("n_id"),template,0000004);
	}
    return sn;
} finally {
LEAVING("b32ssm6ex1pdz1b3nt4fwlhul","agsubrep");
}
}




//3 6u0niow33w9gva780waluva4n
// static void ins(Dict_t * d, Dtlink_t ** set, Agedge_t * e) 
public static void ins(_dt_s d, STARSTAR<_dtlink_s> set, Agedge_s e) {
ENTERING("6u0niow33w9gva780waluva4n","ins");
try {
    dtrestore(d, set.getMe());
    d.call("searchf", d,e,0000001);
    set.setMe(dtextract(d));
} finally {
LEAVING("6u0niow33w9gva780waluva4n","ins");
}
}




//3 2h2dtr49b6fcn440sc4xrseg3
// static void del(Dict_t * d, Dtlink_t ** set, Agedge_t * e) 
public static Object del(Object... arg) {
UNSUPPORTED("5lvsvkq5t8c8pj03debt0mwal"); // static void del(Dict_t * d, Dtlink_t ** set, Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("atawgqln44t2lhf2j4q1dsw80"); //     void *x;
UNSUPPORTED("c1wraxzkcgmquqsiuypvr56tj"); //     dtrestore(d, *set);
UNSUPPORTED("9e6qtst4eze5ps8ukq79d6zf8"); //     x = (*(((Dt_t*)(d))->searchf))((d),(void*)(e),0000002);
UNSUPPORTED("5i0sddp616zsw63jk38od62l4"); //     ;
UNSUPPORTED("dgfo5c0o8ftxxwmcq8kxe7ht8"); //     *set = dtextract(d);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8kizmg7gziussfgx8zs3qvkfw
// static void installedge(Agraph_t * g, Agedge_t * e) 
public static void installedge(Agraph_s g, Agedge_s e) {
ENTERING("8kizmg7gziussfgx8zs3qvkfw","installedge");
try {
    Agnode_s t, h;
    Agedge_s out, in;
    Agsubnode_s sn;
    out = AGMKOUT(e);
    in = AGMKIN(e);
    t = agtail(e);
    h = aghead(e);
    while (g!=null) {
	if (agfindedge_by_key(g, t, h, AGTAG(e))!=null) break;
	sn = agsubrep(g, t); final Agsubnode_s sn1 = sn;
	ins((_dt_s)g.getPtr("e_seq"), 
			STARSTAR.amp(new ACCESS<_dtlink_s>() {
				public _dtlink_s get() {
					return (_dtlink_s) sn1.getPtr("out_seq");
				}
				public void set(_dtlink_s obj) {
					sn1.setPtr("out_seq", obj);
				}})
	, (Agedge_s)out);
	ins((_dt_s)g.getPtr("e_id"), 
			STARSTAR.amp(new ACCESS<_dtlink_s>() {
				public _dtlink_s get() {
					return (_dtlink_s) sn1.getPtr("out_id");
				}
				public void set(_dtlink_s obj) {
					sn1.setPtr("out_id", obj);
				}})
	, (Agedge_s)out);
	sn = agsubrep(g, h);  final Agsubnode_s sn2 = sn;
	ins((_dt_s)g.getPtr("e_seq"), 
			STARSTAR.amp(new ACCESS<_dtlink_s>() {
				public _dtlink_s get() {
					return (_dtlink_s) sn2.getPtr("in_seq");
				}
				public void set(_dtlink_s obj) {
					sn2.setPtr("in_seq", obj);
				}})
	, (Agedge_s)in);
	ins((_dt_s)g.getPtr("e_id"), 
			STARSTAR.amp(new ACCESS<_dtlink_s>() {
				public _dtlink_s get() {
					return (_dtlink_s) sn2.getPtr("in_id");
				}
				public void set(_dtlink_s obj) {
					sn2.setPtr("in_id", obj);
				}})
	, (Agedge_s)in);
	g = agparent(g);
    }
} finally {
LEAVING("8kizmg7gziussfgx8zs3qvkfw","installedge");
}
}




//3 2vtt6zb0n3oru23okvw4pxasg
// static void subedge(Agraph_t * g, Agedge_t * e) 
public static Object subedge(Object... arg) {
UNSUPPORTED("1qslen16fp6w3yse2y311vtsf"); // static void subedge(Agraph_t * g, Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3rvuc9rdxdwmvq3dtwv2hqwjo"); //     installedge(g, e);
UNSUPPORTED("4d70e4y79ekvafnx88hgwdrna"); //     /* might an init method call be needed here? */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4rzjui6oo0k009o64bxwgjmvq
// static Agedge_t *newedge(Agraph_t * g, Agnode_t * t, Agnode_t * h, 			 unsigned long id) 
public static Agedge_s newedge(Agraph_s g, Agnode_s t, Agnode_s h, int id) {
ENTERING("4rzjui6oo0k009o64bxwgjmvq","newedge");
try {
    Agedgepair_s e2;
    Agedge_s in, out;
    int seq;
    agsubnode(g,t,(N(0)));
    agsubnode(g,h,(N(0)));
    e2 = (Agedgepair_s) agalloc(g, sizeof(Agedgepair_s.class));
    in = (Agedge_s) e2.getStruct("in").amp();
    out = (Agedge_s) e2.getStruct("out").amp();
    seq = agnextseq(g, AGEDGE);
    AGTYPE(in, AGINEDGE);
    AGTYPE(out, AGOUTEDGE);
    AGID(out, id);
    AGID(in, id);
    AGSEQ(in, seq);
    AGSEQ(out, seq);
    in.setPtr("node", t);
    out.setPtr("node", h);
    installedge(g, out);
    if (g.getStruct("desc").getBoolean("has_attrs")) {
	  agbindrec(out, AgDataRecName, sizeof(Agattr_s.class), false);
	  agedgeattr_init(g, out);
    }
    agmethod_init(g, out);
    return out;
} finally {
LEAVING("4rzjui6oo0k009o64bxwgjmvq","newedge");
}
}




//3 1ufxhg5xnmll1pe5339477823
// static int ok_to_make_edge(Agraph_t * g, Agnode_t * t, Agnode_t * h) 
public static boolean ok_to_make_edge(Agraph_s g, Agnode_s t, Agnode_s h) {
ENTERING("1ufxhg5xnmll1pe5339477823","ok_to_make_edge");
try {
    final __struct__<Agtag_s> key = __struct__.from(Agtag_s.class);
    /* protect against self, multi-edges in strict graphs */
    if (agisstrict(g)) {
	if (g.getPtr("desc").getBoolean("no_loop") && (EQ(t, h))) /* simple graphs */
	    return false;
	key.____(Tag);
	key.setInt("objtype", 0);	/* wild card */
	if (agfindedge_by_key(g, t, h, key)!=null)
	    return false;
    }
    return (N(0));
} finally {
LEAVING("1ufxhg5xnmll1pe5339477823","ok_to_make_edge");
}
}




//3 75ua3fc3lvhnwftacueslv8e5
// Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h, 		   unsigned long id, int cflag) 
public static Object agidedge(Object... arg) {
UNSUPPORTED("5pslnv27wv1h507npa2zxh90y"); // Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
UNSUPPORTED("e28xnrj58aci1fn3kunzmqxbv"); // 		   unsigned long id, int cflag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2hs0004nnparj6tt7elslt4zj"); //     Agraph_t *root;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("1v1wyp9m83obk7jvlhzzmbwqb"); //     e = agfindedge_by_id(g, t, h, id);
UNSUPPORTED("1gxwr1hr3zd8rrmnl1zq34xju"); //     if ((e == ((Agedge_t*)0)) && agisundirected(g))
UNSUPPORTED("7jnnbxt6l29uby71ap2ioa94q"); // 	e = agfindedge_by_id(g, h, t, id);
UNSUPPORTED("2m5yl6487z3nh60gz8x9otg16"); //     if ((e == ((Agedge_t*)0)) && cflag && ok_to_make_edge(g, t, h)) {
UNSUPPORTED("7zol2448bccu90sqoxkvnbuif"); // 	root = agroot(g);
UNSUPPORTED("e9viv3tnfxask57of0bhahbev"); // 	if ((g != root) && ((e = agfindedge_by_id(root, t, h, id)))) {
UNSUPPORTED("7u9o1s6uopqwva82fgnfbgr03"); // 	    subedge(g, e);	/* old */
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("3nwzv8q6jwjadczk10hhrt14f"); // 	    if (agallocid(g, AGEDGE, id)) {
UNSUPPORTED("2zklsds1y3vegvq9xgmx9ayyn"); // 		e = newedge(g, t, h, id);	/* new */
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2bswif6w6ot01ynlvkimntfly"); //     return e;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4361pvzr3ozft2ov0fgx6t8bo
// Agedge_t *agedge(Agraph_t * g, Agnode_t * t, Agnode_t * h, char *name, 		 int cflag) 
public static Agedge_s agedge(Agraph_s g, Agnode_s t, Agnode_s h, CString name, boolean cflag) {
ENTERING("4361pvzr3ozft2ov0fgx6t8bo","agedge");
try {
    Agedge_s e;
    int id[] = new int[1];
    int have_id;
    have_id = agmapnametoid(g, AGEDGE, name, id, false);
    if (have_id!=0 || ((name == null) && ((NOT(cflag)) || agisstrict(g)))) {
	/* probe for pre-existing edge */
	final __struct__<Agtag_s> key = __struct__.from(Agtag_s.class);
	key.____(Tag);
	if (have_id!=0) {
	    key.setInt("id", id[0]);
	    key.setInt("objtype", AGEDGE);
	} else {
	    key.setInt("id", 0);
	    key.setInt("objtype", 0);
	}
	/* might already exist locally */
	e = agfindedge_by_key(g, t, h, key);
	if ((e == null && agisundirected(g)))
	    e = agfindedge_by_key(g, h, t, key);
	if (e!=null)
	    return e;
	if (cflag) {
	    e = agfindedge_by_key(agroot(g), t, h, key);
	    if ((e == null) && agisundirected(g))
		e = agfindedge_by_key(agroot(g), h, t, key);
	    if (e!=null) {
		subedge(g,e);
		return e;
	    }
 	}
    }
    if (cflag && ok_to_make_edge(g, t, h)
	&& (agmapnametoid(g, AGEDGE, name, id, (N(0))))!=0) { /* reserve id */
	e = newedge(g, t, h, id[0]);
	agregister(g, AGEDGE, e); /* register new object in external namespace */
    }
    else
	e = null;
    return e;
} finally {
LEAVING("4361pvzr3ozft2ov0fgx6t8bo","agedge");
}
}




//3 bbzly9og4lr1fza64fjk04djp
// void agdeledgeimage(Agraph_t * g, Agedge_t * e, void *ignored) 
public static Object agdeledgeimage(Object... arg) {
UNSUPPORTED("7gzvhvwj0z152fzg3h94s4wa3"); // void agdeledgeimage(Agraph_t * g, Agedge_t * e, void *ignored)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("50fokbemxzgivcd3b6k3miqqn"); //     Agedge_t *in, *out;
UNSUPPORTED("4ybt6tm56tubmbuve8lp6rxhh"); //     Agnode_t *t, *h;
UNSUPPORTED("2llbfi4jrmre7cyhu90pgcm72"); //     Agsubnode_t *sn;
UNSUPPORTED("4pgl4pn1cad2whf242bntmjre"); //     (void) ignored;
UNSUPPORTED("65tqa3if9hwq2yshaaiw31i7p"); //     if (AGTYPE(e) == AGINEDGE) {
UNSUPPORTED("7awcpvsw7kw84dndmnqoe7jml"); // 	in = e;
UNSUPPORTED("d4vc8t57wygctu4vl9tau8a6a"); // 	out = AGIN2OUT(e);
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("54k8hnomk4mrwatjixro9a1yr"); // 	out = e;
UNSUPPORTED("7qnm0e5czl4a8gcj7f5vo98h"); // 	in = AGOUT2IN(e);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("uc5fexr8h438pt7usvlh0ul3"); //     t = in->node;
UNSUPPORTED("9a1uo5zmwfnuphv9st2w2b7hh"); //     h = out->node;
UNSUPPORTED("dpshsqc8cs6ucoq4t0hnuxws6"); //     sn = agsubrep(g, t);
UNSUPPORTED("a1kpx292l61dmu7eqdcm7fd51"); //     del(g->e_seq, &sn->out_seq, out);
UNSUPPORTED("3xx2m5a0qzz8zcz61qn8mw44q"); //     del(g->e_id, &sn->out_id, out);
UNSUPPORTED("e1vy7p3xj8dfi23jli55il082"); //     sn = agsubrep(g, h);
UNSUPPORTED("dtt5k4axitnc0rvaop78flltt"); //     del(g->e_seq, &sn->in_seq, in);
UNSUPPORTED("3w1dtrerdp5ojxgix55ysgcd3"); //     del(g->e_id, &sn->in_id, in);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5l2v1bqchqfkinhpae4ip3yvz
// int agdeledge(Agraph_t * g, Agedge_t * e) 
public static Object agdeledge(Object... arg) {
UNSUPPORTED("a87xum130tyatez3ic2nbxnna"); // int agdeledge(Agraph_t * g, Agedge_t * e)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9tj8yk1m099w6420vq9obwqv6"); //     e = AGMKOUT(e);
UNSUPPORTED("58hfnwh2g7pubdk6wexuvksuo"); //     if (agfindedge_by_key(g, agtail(e), aghead(e), AGTAG(e)) == ((Agedge_t*)0))
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("ackx3cor82a94trjk4owh3083"); //     if (g == agroot(g)) {
UNSUPPORTED("5247bml3o0pwzg9fc9q1xhhnc"); // 	if (g->desc.has_attrs)
UNSUPPORTED("4lf7sorcdbqef4eadxah45x08"); // 	    agedgeattr_delete(e);
UNSUPPORTED("dpp3uqwrwe9geok1zmxonosd3"); // 	agmethod_delete(g, e);
UNSUPPORTED("6kvbonl2aylsja52uh6deu14c"); // 	agrecclose((Agobj_t *) e);
UNSUPPORTED("dnmywe26u2d1rmgozlfonjw94"); // 	agfreeid(g, AGEDGE, AGID(e));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6ox33bv05arfuz70cp795jqlg"); //     if (agapply (g, (Agobj_t *) e, (agobjfn_t) agdeledgeimage, ((Agedge_t*)0), (0)) == 0) {
UNSUPPORTED("6tlwlx478gb1clm2fykihi2zk"); // 	if (g == agroot(g))
UNSUPPORTED("ebin71xd0muor7ysk74hizhw3"); // 		agfree(g, e);
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 30v8z3tlda81fbqbkzx6m9fkn
// Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int cflag) 
public static Object agsubedge(Object... arg) {
UNSUPPORTED("38yi9hovj0unro23lccybbl9e"); // Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int cflag)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4ybt6tm56tubmbuve8lp6rxhh"); //     Agnode_t *t, *h;
UNSUPPORTED("2k85xnpgz2z3cqtrecvkjcy3h"); //     Agedge_t *rv;
UNSUPPORTED("80g0nls7wtv69vlicppzx9cc"); //     rv = ((Agedge_t*)0);
UNSUPPORTED("7gr0tv0tz875c0ditt25upwqy"); //     t = agsubnode(g, AGTAIL(e), cflag);
UNSUPPORTED("ezg9ns8qgnkupvptfw3oc5x30"); //     h = agsubnode(g, AGHEAD(e), cflag);
UNSUPPORTED("ecawwulkcrk1905r35hbfgyyq"); //     if (t && h) {
UNSUPPORTED("35chuim9jkob8d4egvridkhu8"); // 	rv = agfindedge_by_key(g, t, h, AGTAG(e));
UNSUPPORTED("7z11zomu0rrq9tfs2j52kp8ln"); // 	if (cflag && (rv == ((Agedge_t*)0))) {
UNSUPPORTED("cb7g8iizc3vjq95l3smqi09br"); // 	installedge(g, e);
UNSUPPORTED("8zm1645nr0k9r95lur0lyy7a"); // 	rv = e;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("2rort18jfixd122iia8fkaj8w"); // 	if (rv && (AGTYPE(rv) != AGTYPE(e)))
UNSUPPORTED("2zd4qt65g3442d4ijz2h0plrx"); // 	    rv = AGOPP(rv);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("v7vqc9l7ge2bfdwnw11z7rzi"); //     return rv;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 avk47eh26r45qk2dtoipwiqvz
// int agedgeidcmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc) 
public static int agedgeidcmpf(_dt_s d, __ptr__ arg_e0, __ptr__ arg_e1, _dtdisc_s disc) {
ENTERING("avk47eh26r45qk2dtoipwiqvz","agedgeidcmpf");
try {
    int v;
    Agedge_s e0, e1;
    e0 = (Agedge_s) arg_e0;
    e1 = (Agedge_s) arg_e1;
    v = AGID(e0.getPtr("node")) - AGID(e1.getPtr("node"));
    if (v == 0) {		/* same node */
UNSUPPORTED("ehtddg5qmuiufgoj2gbag28en"); // 	if ((((((Agobj_t*)(e0))->tag).objtype) == 0) || (((((Agobj_t*)(e1))->tag).objtype) == 0))
UNSUPPORTED("1k3e39kpc8hkrh2jtdmzy1tur"); // 	    v = 0;
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("9rfiauukf1b9q77d98glvwsyx"); // 	    v = ((((Agobj_t*)(e0))->tag).id) - ((((Agobj_t*)(e1))->tag).id);
    }
    return ((v==0)?0:(v<0?-1:1));
} finally {
LEAVING("avk47eh26r45qk2dtoipwiqvz","agedgeidcmpf");
}
}




//3 b6jhzc16xvrknu4e7jp6zx0ue
// int agedgeseqcmpf(Dict_t * d, void *arg_e0, void *arg_e1, Dtdisc_t * disc) 
public static int agedgeseqcmpf(_dt_s d, __ptr__ arg_e0, __ptr__ arg_e1, _dtdisc_s disc) {
ENTERING("b6jhzc16xvrknu4e7jp6zx0ue","agedgeseqcmpf");
try {
    int v;
    Agedge_s e0, e1;
    e0 = (Agedge_s) arg_e0;
    e1 = (Agedge_s) arg_e1;
	if (NEQ(e0.getPtr("node"), e1.getPtr("node"))) v = AGSEQ(e0.getPtr("node")) - AGSEQ(e1.getPtr("node"));
	else v = (AGSEQ(e0) - AGSEQ(e1));
    return ((v==0)?0:(v<0?-1:1));
} finally {
LEAVING("b6jhzc16xvrknu4e7jp6zx0ue","agedgeseqcmpf");
}
}


//1 d058zqckpiqls71p4vkuxe87o
// Dtdisc_t Ag_mainedge_seq_disc = 
static final public __struct__<_dtdisc_s> Ag_mainedge_seq_disc = __struct__.from(_dtdisc_s.class);
static {
	Ag_mainedge_seq_disc.setInt("key", 0);
	Ag_mainedge_seq_disc.setInt("size", 0);
	Ag_mainedge_seq_disc.setInt("link", OFFSET.create(Agedge_s.class, "seq_link").toInt());  // seq_link is the third field in Agedge_t
	Ag_mainedge_seq_disc.setPtr("makef", null);
	Ag_mainedge_seq_disc.setPtr("freef", null);
	Ag_mainedge_seq_disc.setPtr("comparf", function(edge__c.class, "agedgeseqcmpf"));
	Ag_mainedge_seq_disc.setPtr("hashf", null);
	Ag_mainedge_seq_disc.setPtr("memoryf", function(utils__c.class, "agdictobjmem"));
	Ag_mainedge_seq_disc.setPtr("eventf", null);
}

//1 7n5e8w5zjp9b4oeecyvyl96il
// Dtdisc_t Ag_subedge_seq_disc = 
static public final __struct__<_dtdisc_s> Ag_subedge_seq_disc = __struct__.from(_dtdisc_s.class);
static {
	Ag_mainedge_seq_disc.setInt("key", 0);
	Ag_mainedge_seq_disc.setInt("size", 0);
	Ag_mainedge_seq_disc.setInt("link", -1);
	Ag_mainedge_seq_disc.setPtr("makef", null);
	Ag_mainedge_seq_disc.setPtr("freef", null);
	Ag_mainedge_seq_disc.setPtr("comparf", function(edge__c.class, "agedgeseqcmpf"));
	Ag_mainedge_seq_disc.setPtr("hashf", null);
	Ag_mainedge_seq_disc.setPtr("memoryf", function(utils__c.class, "agdictobjmem"));
	Ag_mainedge_seq_disc.setPtr("eventf", null);
}


//1 7grv8f2wvpg0db2pn1g7r5abv
// Dtdisc_t Ag_mainedge_id_disc = 
static final public __struct__<_dtdisc_s> Ag_mainedge_id_disc = __struct__.from(_dtdisc_s.class);
static {
	Ag_mainedge_id_disc.setInt("key", 0);
	Ag_mainedge_id_disc.setInt("size", 0);
	Ag_mainedge_id_disc.setInt("link", OFFSET.create(Agedge_s.class, "id_link").toInt()); // id_link is the second field in Agedge_t
	Ag_mainedge_id_disc.setPtr("makef", null);
	Ag_mainedge_id_disc.setPtr("freef", null);
	Ag_mainedge_id_disc.setPtr("comparf", function(edge__c.class, "agedgeidcmpf"));
	Ag_mainedge_id_disc.setPtr("hashf", null);
	Ag_mainedge_id_disc.setPtr("memoryf", function(utils__c.class, "agdictobjmem"));
	Ag_mainedge_id_disc.setPtr("eventf", null);
}

//1 9u0ic8u2hrwlmlqalv37s053f
// Dtdisc_t Ag_subedge_id_disc = 
static public final __struct__<_dtdisc_s> Ag_subedge_id_disc = __struct__.from(_dtdisc_s.class);
static {
	Ag_subedge_id_disc.setInt("key", 0);
	Ag_subedge_id_disc.setInt("size", 0);
	Ag_subedge_id_disc.setInt("link", -1);
	Ag_subedge_id_disc.setPtr("makef", null);
	Ag_subedge_id_disc.setPtr("freef", null);
	Ag_subedge_id_disc.setPtr("comparf", function(edge__c.class, "agedgeidcmpf"));
	Ag_subedge_id_disc.setPtr("hashf", null);
	Ag_subedge_id_disc.setPtr("memoryf", function(utils__c.class, "agdictobjmem"));
	Ag_subedge_id_disc.setPtr("eventf", null);
}



//3 ceexs6t1q4jxwz6h0g8fszxp4
// Agnode_t *agtail(Agedge_t * e) 
public static Agnode_s agtail(Agedge_s e) {
ENTERING("ceexs6t1q4jxwz6h0g8fszxp4","agtail");
try {
    return AGTAIL(e);
} finally {
LEAVING("ceexs6t1q4jxwz6h0g8fszxp4","agtail");
}
}




//3 3tj9gj3dvrpox6grrdd3rftd8
// Agnode_t *aghead(Agedge_t * e) 
public static Agnode_s aghead(__ptr__ e) {
ENTERING("3tj9gj3dvrpox6grrdd3rftd8","aghead");
try {
    return AGHEAD((Agedge_s) e);
} finally {
LEAVING("3tj9gj3dvrpox6grrdd3rftd8","aghead");
}
}




//3 15e6s5bh5hey2u79yoebir59w
// Agedge_t *agopp(Agedge_t * e) 
public static Agedge_s agopp(__ptr__ e) {
ENTERING("15e6s5bh5hey2u79yoebir59w","agopp");
try {
    return AGOPP((Agedge_s) e);
} finally {
LEAVING("15e6s5bh5hey2u79yoebir59w","agopp");
}
}


}
