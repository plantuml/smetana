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

public class rec__c {
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




//3 62z9z5vraa2as0c9t108j9xaf
// static void set_data(Agobj_t * obj, Agrec_t * data, int mtflock) 
public static void set_data(Agobj_s obj, Agrec_s data, int mtflock) {
ENTERING("62z9z5vraa2as0c9t108j9xaf","set_data");
try {
    Agedge_s e;
    obj.setPtr("data", data);
    obj.getStruct("tag").setInt("mtflock", mtflock);
    if ((AGTYPE(obj) == AGINEDGE) || (AGTYPE(obj) == AGOUTEDGE)) {
	e = (Agedge_s) agopp(obj.castTo(Agedge_s.class));
	AGDATA(e, data);
	e.getStruct("base").getStruct("tag").setInt("mtflock", mtflock);
    }
} finally {
LEAVING("62z9z5vraa2as0c9t108j9xaf","set_data");
}
}




//3 7p2ne3oknmyclvsw4lh3axtd8
// Agrec_t *aggetrec(void *obj, char *name, int mtf) 
public static Agrec_s aggetrec(__ptr__ obj, CString name, boolean mtf) {
ENTERING("7p2ne3oknmyclvsw4lh3axtd8","aggetrec");
try {
    Agobj_s hdr;
    Agrec_s d, first;
    hdr = (Agobj_s) obj.castTo(Agobj_s.class);
    first = d = (Agrec_s) hdr.getPtr("data");
    while (d!=null) {
	if (N(strcmp(name,d.getCString("name"))))
	    break;
	d = (Agrec_s) d.getPtr("next");
	if (EQ(d, first)) {
	    d = null;
	    break;
	}
    }
    if (d!=null) {
	if (hdr.getStruct("tag").getBoolean("mtflock")) {
	    if (mtf && NEQ(hdr.getPtr("data"), d))
		System.err.println("move to front lock inconsistency");
	} else {
	    if (NEQ(d, first) || (mtf != hdr.getStruct("tag").getBoolean("mtflock")))
		set_data(hdr, d, ASINT(mtf));	/* Always optimize */
	}
    }
    return d;
} finally {
LEAVING("7p2ne3oknmyclvsw4lh3axtd8","aggetrec");
}
}




//3 7sk4k5ipm2jnd244556g1kr6
// static void objputrec(Agraph_t * g, Agobj_t * obj, void *arg) 
public static void objputrec(Agraph_s g, Agobj_s obj, Object arg) {
ENTERING("7sk4k5ipm2jnd244556g1kr6","objputrec");
try {
    Agrec_s firstrec, newrec;
    newrec = (Agrec_s) arg;
    firstrec = (Agrec_s) obj.getPtr("data");
    if (firstrec == null)
	newrec.setPtr("next", newrec);	/* 0 elts */
    else {
	if (EQ(firstrec.getPtr("next"), firstrec)) {
	    firstrec.setPtr("next", newrec);	/* 1 elt */
	    newrec.setPtr("next", firstrec);
	} else {
	    newrec.setPtr("next", firstrec.getPtr("next"));
	    firstrec.setPtr("next", newrec);
	}
    }
    if (NOT(obj.getStruct("tag").getInt("mtflock")))
	set_data(obj, newrec, (0));
} finally {
LEAVING("7sk4k5ipm2jnd244556g1kr6","objputrec");
}
}




//3 dmh5i83l15mnn1pnu6f5dfv8l
// void *agbindrec(void *arg_obj, char *recname, unsigned int recsize, 		int mtf) 
public static __ptr__ agbindrec(__ptr__ arg_obj, CString recname, size_t recsize, boolean mtf) {
ENTERING("dmh5i83l15mnn1pnu6f5dfv8l","agbindrec");
try {
    Agraph_s g;
    Agobj_s obj;
    Agrec_s rec;
    obj = (Agobj_s) arg_obj.castTo(Agobj_s.class);
    g = agraphof(obj);
    rec = aggetrec(obj, recname, false);
    if ((rec == null && recsize.isStrictPositive())) {
	rec = (Agrec_s) ((__ptr__)agalloc(g, recsize)).castTo(Agrec_s.class);
    // rec = (Agrec_s) Memory.malloc(Agrec_s.class);
	rec.setPtr("name", agstrdup(g, recname));
	switch (obj.getStruct("tag").getInt("objtype")) {
	case AGRAPH:
	    objputrec(g, obj, rec);
	    break;
	case AGNODE:
	    objputrec(g, obj, rec);
	    break;
	case AGINEDGE:
	case AGOUTEDGE:
	    objputrec(g, obj, rec);
	    break;
	}
    }
    if (mtf)
	aggetrec(arg_obj, recname, (N(0)));
    return rec;
} finally {
LEAVING("dmh5i83l15mnn1pnu6f5dfv8l","agbindrec");
}
}




//3 7wkmd0z867cfhifu5sx3f9qk0
// static void objdelrec(Agraph_t * g, Agobj_t * obj, void *arg_rec) 
public static Object objdelrec(Object... arg) {
UNSUPPORTED("50zcyap75kyq5dged87b27eux"); // static void objdelrec(Agraph_t * g, Agobj_t * obj, void *arg_rec)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("emb5aoborhmx7xgff2s0f32r7"); //     Agrec_t *rec = (Agrec_t *) arg_rec, *newrec;
UNSUPPORTED("a3ypwtn30jl38mmwqqe7cncxj"); //     if (obj->data == rec) {
UNSUPPORTED("69qy6kkaiflhbig0kizfx2tti"); // 	if (rec->next == rec)
UNSUPPORTED("xd727mslmxprqxq2rm02c5d8"); // 	    newrec = ((Agrec_t *)0);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("6w6e40pynrhr4cg19g4qnwmeg"); // 	    newrec = rec->next;
UNSUPPORTED("boyfn5td5ma9qwuqx4rb00zxn"); // 	set_data(obj, newrec, (0));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9lrcdtq3amx34ixpjad1kj9w1
// static void listdelrec(Agobj_t * obj, Agrec_t * rec) 
public static Object listdelrec(Object... arg) {
UNSUPPORTED("5vg9c18o4hibwg5a9p47ad9i"); // static void listdelrec(Agobj_t * obj, Agrec_t * rec)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8e7x54av78ukk2gkru2uv7n5t"); //     Agrec_t *prev;
UNSUPPORTED("acnbs96yxc5n81gdoim603six"); //     prev = obj->data;
UNSUPPORTED("j2ssgapam83gwl5s62grl1fg"); //     while (prev->next != rec) {
UNSUPPORTED("4l4pl9wqsuoczyfdlvmzj1gli"); // 	prev = prev->next;
UNSUPPORTED("bt8qt5d94yexozgdbv5sspmm4"); // 	;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("1uagqrrdyb18p3s9qlqg8jwjj"); //     /* following is a harmless no-op if the list is trivial */
UNSUPPORTED("erdqdxkn41xuppe0chxcrx73"); //     prev->next = rec->next;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dr7dc2ebvb106hcsaxz6elhu9
// int agdelrec(void *arg_obj, char *name) 
public static Object agdelrec(Object... arg) {
UNSUPPORTED("8scieaa3q398qeq2uv44asga1"); // int agdelrec(void *arg_obj, char *name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("14h5et4t79wqu2qo8divf5tkt"); //     Agobj_t *obj;
UNSUPPORTED("146agbqco6st2hn1ajcek08r6"); //     Agrec_t *rec;
UNSUPPORTED("1dbyk58q3r4fyfxxo7ovemkpu"); //     Agraph_t *g;
UNSUPPORTED("ami3me63drun9ofwwmxainjy5"); //     obj = (Agobj_t *) arg_obj;
UNSUPPORTED("8pfuk9ua4x9bh68zk1kzwc5t9"); //     g = agraphof(obj);
UNSUPPORTED("dhmaidfkewgpedp1d73ef9yx5"); //     rec = aggetrec(obj, name, (0));
UNSUPPORTED("epwrmjxhdofey6itrewqzilu0"); //     if (rec) {
UNSUPPORTED("q964zfpibwk1nuufmhbvhvz1"); // 	listdelrec(obj, rec);	/* zap it from the circular list */
UNSUPPORTED("bxainz8fp03zcbgxzia4t1ta2"); // 	switch (obj->tag.objtype) {	/* refresh any stale pointers */
UNSUPPORTED("9t6es77h0301xk4n035emz6o"); // 	case AGRAPH:
UNSUPPORTED("39koq493kdonzfnv7y451gzku"); // 	    objdelrec(g, obj, rec);
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("4ih7nalu307xv8wvdpmgy537r"); // 	case AGNODE:
UNSUPPORTED("f0mphr0n2ielt8cpkw0djd9s9"); // 	case AGINEDGE:
UNSUPPORTED("3zbev1w97o9vgmm1ifhakk5g6"); // 	case AGOUTEDGE:
UNSUPPORTED("9ixqdoo4u64vgpl11kitdhiwj"); // 	    agapply(agroot(g), obj, objdelrec, rec, (0));
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("b0419fuh4e7iigkr04vrhwoqw"); // 	agstrfree(g, rec->name);
UNSUPPORTED("9w293r9fg650cqzb27hlm4gm6"); // 	agfree(g, rec);
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("8d9xfgejx5vgd6shva5wk5k06"); // 	return -1;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 61hbvi8qf9sf7fp8zpov061px
// static void simple_delrec(Agraph_t * g, Agobj_t * obj, void *rec_name) 
public static Object simple_delrec(Object... arg) {
UNSUPPORTED("7jivm8vgxrik7o19yqyy4iuoj"); // static void simple_delrec(Agraph_t * g, Agobj_t * obj, void *rec_name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3lu3vc6o8prg1gr2vk05e0eko"); //     agdelrec(obj, rec_name);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e1pnypxtha6b6f6gdnys37746
// void aginit(Agraph_t * g, int kind, char *rec_name, int arg_rec_size, int mtf) 
public static Object aginit(Object... arg) {
UNSUPPORTED("2pn3c5mfp7ik08786jysv3lbs"); // void aginit(Agraph_t * g, int kind, char *rec_name, int arg_rec_size, int mtf)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2jcii9cclu1dijzqekzc175pe"); //     Agnode_t *n;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("8a4qjwfuqqw6rztukk1hbffvl"); //     Agraph_t *s;
UNSUPPORTED("abzwllf3yvcaghy0hkur9oxfd"); // 	int		 rec_size;
UNSUPPORTED("5vb74w15wh9g0ykij86iwtxeb"); // 	int		 recur;	/* if recursive on subgraphs */
UNSUPPORTED("4nlgepehelmt97qydjqp7ecah"); // 	if (arg_rec_size < 0) {recur = 1; rec_size = -arg_rec_size;}
UNSUPPORTED("bevbs1i4v9cvng7nnrs2yqiku"); // 	else {recur = 0; rec_size= arg_rec_size;}
UNSUPPORTED("elb9jvgldg2htymh7c74smj7o"); //     switch (kind) {
UNSUPPORTED("eyna33dobiebmtd0nihpgura4"); //     case AGRAPH:
UNSUPPORTED("9k3pxutrp61xdp73x92pxsv8j"); // 	agbindrec(g, rec_name, rec_size, mtf);
UNSUPPORTED("ufmow0oztf5sdbx36wf4v0e5"); // 	if (recur)
UNSUPPORTED("4oknzxynn26rak0dbvijyz5t"); // 		for (s = agfstsubg(g); s; s = agnxtsubg(s))
UNSUPPORTED("3hu696w8d3t3l7tygoq4twr4x"); // 			aginit(s,kind,rec_name,arg_rec_size,mtf);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("6x7ztvlgv763oeop84udp1egg"); //     case AGNODE:
UNSUPPORTED("a6ls4lkgjoheqwo2e7yqt9zz8"); //     case AGOUTEDGE:
UNSUPPORTED("c9o8hr6x8n5dty1y3eej1fept"); //     case AGINEDGE:
UNSUPPORTED("eg21iwn9eqyjsoisl58nl8i36"); // 	for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("2kxod9hw7p0o5crbt6xh2gcwy"); // 	    if (kind == AGNODE)
UNSUPPORTED("7lbtjiuf91mfv1rfh26gr9rnf"); // 		agbindrec(n, rec_name, rec_size, mtf);
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("5qry6mw56jhkh965gr6si5sjz"); // 		for (e = agfstout(g, n); e; e = agnxtout(g, e))
UNSUPPORTED("3isk98kl2hyz50xh5nk9e79ur"); // 		    agbindrec(e, rec_name, rec_size, mtf);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 d8dlatsnpytjohjptji50kek2
// void agclean(Agraph_t * g, int kind, char *rec_name) 
public static Object agclean(Object... arg) {
UNSUPPORTED("2u4lls7xvbemdliclfn1jjlv3"); // void agclean(Agraph_t * g, int kind, char *rec_name)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2jcii9cclu1dijzqekzc175pe"); //     Agnode_t *n;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("elb9jvgldg2htymh7c74smj7o"); //     switch (kind) {
UNSUPPORTED("eyna33dobiebmtd0nihpgura4"); //     case AGRAPH:
UNSUPPORTED("p5rnonv5qza6uss4lurbzcru"); // 	agapply(g, (Agobj_t *) g, simple_delrec, rec_name, (!(0)));
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("6x7ztvlgv763oeop84udp1egg"); //     case AGNODE:
UNSUPPORTED("a6ls4lkgjoheqwo2e7yqt9zz8"); //     case AGOUTEDGE:
UNSUPPORTED("c9o8hr6x8n5dty1y3eej1fept"); //     case AGINEDGE:
UNSUPPORTED("eg21iwn9eqyjsoisl58nl8i36"); // 	for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("2kxod9hw7p0o5crbt6xh2gcwy"); // 	    if (kind == AGNODE)
UNSUPPORTED("an2xd4k44p94rcg7ynge2g1nq"); // 		agdelrec(n, rec_name);
UNSUPPORTED("6q044im7742qhglc4553noina"); // 	    else {
UNSUPPORTED("5qry6mw56jhkh965gr6si5sjz"); // 		for (e = agfstout(g, n); e; e = agnxtout(g, e))
UNSUPPORTED("7k5tz238egfs4u82cpy7lk8dn"); // 		    agdelrec(e, rec_name);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1s9p443oxpnfk2w28k6bgn1y0
// void agrecclose(Agobj_t * obj) 
public static Object agrecclose(Object... arg) {
UNSUPPORTED("f28etp6uks02tqgelaos87f96"); // void agrecclose(Agobj_t * obj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1dbyk58q3r4fyfxxo7ovemkpu"); //     Agraph_t *g;
UNSUPPORTED("4d3axgxxzgvvs9r07npfgyqqs"); //     Agrec_t *rec, *nrec;
UNSUPPORTED("8pfuk9ua4x9bh68zk1kzwc5t9"); //     g = agraphof(obj);
UNSUPPORTED("7mfrjfyuzo92p41ycl0k8l0ux"); //     if ((rec = obj->data)) {
UNSUPPORTED("8vxyvy38lzpbd83cu26nejaan"); // 	do {
UNSUPPORTED("ezzhxi7n4n97pmh7g0zo4wprj"); // 	    nrec = rec->next;
UNSUPPORTED("e1l0oyl4p7njuyrgfuf1nph9b"); // 	    agstrfree(g, rec->name);
UNSUPPORTED("3yrrykwn17vvbliut3f5a174w"); // 	    agfree(g, rec);
UNSUPPORTED("66id2vgqklsr5nz9a84lor5eb"); // 	    rec = nrec;
UNSUPPORTED("aqvgta0a2vlgkvf7yvufyzvt5"); // 	} while (rec != obj->data);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2ila9b4kx11rvt5yy16n3myks"); //     obj->data = ((Agrec_t *)0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
