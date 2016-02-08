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

public class id__c {
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




//3 a0a2zxsu8n019hzm1rwf1jc7f
// static void *idopen(Agraph_t * g, Agdisc_t* disc) 
public static Object idopen(Agraph_s g, Agdisc_s disc) {
ENTERING("a0a2zxsu8n019hzm1rwf1jc7f","idopen");
try {
	return g;
} finally {
LEAVING("a0a2zxsu8n019hzm1rwf1jc7f","idopen");
}
}




//3 lsl0c1gejls1wv04ga6xy2cf
// static long idmap(void *state, int objtype, char *str, unsigned long *id, 		  int createflag) 
static int ctr = 1;
public static int idmap(Object state, int objtype, CString str, int id[], boolean createflag) {
ENTERING("lsl0c1gejls1wv04ga6xy2cf","idmap");
try {
    CString s;
    if (str!=null) {
	Agraph_s g;
	g = (Agraph_s) state;
	if (createflag)
	    s = agstrdup(g, str);
	else
	    s = agstrbind(g, str);
	id[0] = Memory.identityHashCode(s);
    } else {
	id[0] = ctr;
	ctr += 2;
    }
    return ASINT(N(0));
} finally {
LEAVING("lsl0c1gejls1wv04ga6xy2cf","idmap");
}
}




//3 8ynmf2fueegi7vjejal3ri1ax
// static long idalloc(void *state, int objtype, unsigned long request) 
public static Object idalloc(Object... arg) {
UNSUPPORTED("1z2o91qjhxg0zcs8vgzyl9bf1"); // static long idalloc(void *state, int objtype, unsigned long request)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2s0qc9g3dasd7eqa3rhtlxrae"); //     (void) state;
UNSUPPORTED("x0ltcg0hfp8jlgbjde43bdwj"); //     (void) objtype;
UNSUPPORTED("6xs9bwnce34njm5w424uwon6d"); //     (void) request;
UNSUPPORTED("297p5iu8oro94tdg9v29bbgiw"); //     return (0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5fsdlq8w38bfd7gtwz1z8arad
// static void idfree(void *state, int objtype, unsigned long id) 
public static Object idfree(Object... arg) {
UNSUPPORTED("adq5fviqjzpkxrjt37qxo1ywh"); // static void idfree(void *state, int objtype, unsigned long id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("x0ltcg0hfp8jlgbjde43bdwj"); //     (void) objtype;
UNSUPPORTED("e3dd233viwus8xrkad68a1qhr"); //     if (id % 2 == 0)
UNSUPPORTED("69x6bjndheh46syz632mlu192"); // 	agstrfree((Agraph_t *) state, (char *) id);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8143j507ej7uqqjzw5i32xej5
// static char *idprint(void *state, int objtype, unsigned long id) 
public static CString idprint(__ptr__ state, int objtype, int id) {
ENTERING("8143j507ej7uqqjzw5i32xej5","idprint");
try {
    if (id % 2 == 0)
	return (CString) Memory.fromIdentityHashCode(id);
    else
	return null;
} finally {
LEAVING("8143j507ej7uqqjzw5i32xej5","idprint");
}
}




//3 44seyu1scoubb1wsuhwlghwyz
// static void idclose(void *state) 
public static Object idclose(Object... arg) {
UNSUPPORTED("18oh21h7t6fg06ozg64u87nyu"); // static void idclose(void *state)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2s0qc9g3dasd7eqa3rhtlxrae"); //     (void) state;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5bjqo0ihl0x25vaspoiehmwzk
// static void idregister(void *state, int objtype, void *obj) 
public static void idregister(Object state, int objtype, Object obj) {
ENTERING("5bjqo0ihl0x25vaspoiehmwzk","idregister");
try {
 
} finally {
LEAVING("5bjqo0ihl0x25vaspoiehmwzk","idregister");
}
}


//1 cxrk51474ugltvklkcvp3v2ly
// Agiddisc_t AgIdDisc = 
public final static __struct__<Agiddisc_s> AgIdDisc = __struct__.from(Agiddisc_s.class);
static {
	AgIdDisc.setPtr("open", function(id__c.class, "idopen"));
	AgIdDisc.setPtr("map", function(id__c.class, "idmap"));
	AgIdDisc.setPtr("alloc", function(id__c.class, "idalloc"));
	AgIdDisc.setPtr("free", function(id__c.class, "idfree"));
	AgIdDisc.setPtr("print", function(id__c.class, "idprint"));
	AgIdDisc.setPtr("close", function(id__c.class, "idclose"));
	AgIdDisc.setPtr("idregister", function(id__c.class, "idregister"));
}



//3 aq30wwcj4ugatsgx0zdtdmeed
// int agmapnametoid(Agraph_t * g, int objtype, char *str, 		  unsigned long *result, int createflag) 
public static int agmapnametoid(Agraph_s g, int objtype, CString str, int result[], boolean createflag) {
ENTERING("aq30wwcj4ugatsgx0zdtdmeed","agmapnametoid");
try {
    int rv;
    if (str!=null && (str.charAt(0) != '%')) {
    	rv = (Integer) g.getPtr("clos").getStruct("disc").getPtr("id").call("map", g.getPtr("clos").getStruct("state").getPtr("id"), objtype, str, result, createflag);
	if (rv!=0)
	    return rv;
    }
    /* either an internal ID, or disc. can't map strings */
    if (str!=null) {
	rv = aginternalmaplookup(g, objtype, str, result);
	if (rv!=0)
	    return rv;
    } else
	rv = 0;
    if (createflag) {
	/* get a new anonymous ID, and store in the internal map */
	rv = (Integer) g.getPtr("clos").getStruct("disc").getPtr("id").call("map", g.getPtr("clos").getStruct("state").getPtr("id"), objtype, null, result,
				createflag);
	if (rv!=0 && str!=null)
	    aginternalmapinsert(g, objtype, str, result[0]);
    }
    return rv;
} finally {
LEAVING("aq30wwcj4ugatsgx0zdtdmeed","agmapnametoid");
}
}




//3 dwufsd296z6lfmtm7fp4e3tk7
// int agallocid(Agraph_t * g, int objtype, unsigned long request) 
public static Object agallocid(Object... arg) {
UNSUPPORTED("5i7l75ugdm5j5c4xtqqk9atdd"); // int agallocid(Agraph_t * g, int objtype, unsigned long request)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dlf21dkccrftu3zc0t5amuwu4"); //     return ((g)->clos->disc.id)->alloc(((g)->clos->state.id), objtype, request);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cfub4osftc8djs88cq592feu3
// void agfreeid(Agraph_t * g, int objtype, unsigned long id) 
public static Object agfreeid(Object... arg) {
UNSUPPORTED("4hpxv4j7rcvj3lrbvu2e0hus4"); // void agfreeid(Agraph_t * g, int objtype, unsigned long id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3s1vo79t7lt6fm1bimxdpbqj"); //     (void) aginternalmapdelete(g, objtype, id);
UNSUPPORTED("dm45ri059viqxsb08rmvo60y1"); //     (((g)->clos->disc.id)->free) (((g)->clos->state.id), objtype, id);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cctsybrl54fy799aynfej4iiy
// char *agnameof(void *obj) 
// private static char buf[32];
public static CString agnameof(__ptr__ obj) {
ENTERING("cctsybrl54fy799aynfej4iiy","agnameof");
try {
    Agraph_s g;
    CString rv;
    /* perform internal lookup first */
    g = agraphof(obj);
    if ((rv = aginternalmapprint(g, AGTYPE(obj), AGID(obj)))!=null)
	return rv;
    if (g.getPtr("clos").getStruct("disc").getPtr("id").getPtr("print")!=null) {
	if ((rv =
	     (CString) g.getPtr("clos").getStruct("disc").getPtr("id").call("print", g.getPtr("clos").getStruct("state").getPtr("id"),
	     AGTYPE(obj), 
	     AGID(obj)))!=null)
	    return rv;
    }
    if (AGTYPE(obj) != AGEDGE) {
      rv = new CString("%"+obj.castTo(Agobj_s.class).getStruct("tag").getInt("id"));
    }
    else
	rv = null;
    return rv;
} finally {
LEAVING("cctsybrl54fy799aynfej4iiy","agnameof");
}
}




//3 emt63ldde99jnwe2vvjal9kt9
// void agregister(Agraph_t * g, int objtype, void *obj) 
public static void agregister(Agraph_s g, int objtype, Object obj) {
ENTERING("emt63ldde99jnwe2vvjal9kt9","agregister");
try {
	g.getPtr("clos").getStruct("disc").getPtr("id").call("idregister", g.getPtr("clos").getStruct("state").getPtr("id"), objtype, obj);
} finally {
LEAVING("emt63ldde99jnwe2vvjal9kt9","agregister");
}
}


}
