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

public class utils__c {
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


//1 2xwmpggwpggfyyfj0vuw3pmfg
// static Agraph_t *Ag_dictop_G
static public Agraph_s Ag_dictop_G;



//3 7dkudp41c9byhicatk2sxtxqk
// void *agdictobjmem(Dict_t * dict, void * p, size_t size, Dtdisc_t * disc) 
public static Object agdictobjmem(_dt_s dict, Object p, size_t size, _dtdisc_s disc) {
ENTERING("7dkudp41c9byhicatk2sxtxqk","agdictobjmem");
try {
	Agraph_s g;
    g = Ag_dictop_G;
    if (g!=null) {
	if (p!=null)
	    agfree(g, p);
	else
	    return agalloc(g, size);
    } else {
	if (p!=null)
	    Memory.free(p);
	else
	    return size.malloc();
    }
    return null;
} finally {
LEAVING("7dkudp41c9byhicatk2sxtxqk","agdictobjmem");
}
}




//3 5xdfwxth4q1dm3180qzuf51sn
// void agdictobjfree(Dict_t * dict, void * p, Dtdisc_t * disc) 
public static Object agdictobjfree(Object... arg) {
UNSUPPORTED("bsemnw6m2qx5a4hk13xep80nh"); // void agdictobjfree(Dict_t * dict, void * p, Dtdisc_t * disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1dbyk58q3r4fyfxxo7ovemkpu"); //     Agraph_t *g;
UNSUPPORTED("nzl57bfl5onx7q9ge19n2k9i"); //     (void) dict;
UNSUPPORTED("8l8wg6vltx6d7vc9dzqb6n3wi"); //     (void) disc;
UNSUPPORTED("ah8bddgh4pyntvi4o9xx91fkm"); //     g = Ag_dictop_G;
UNSUPPORTED("5skdegxoz3mwfvm59pbtvqtiq"); //     if (g)
UNSUPPORTED("akbizhd9c9w4syt1qpirn7xjy"); // 	agfree(g, p);
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("cy5x5dma0v4hiepir7lrfuo17"); // 	free(p);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 48ox0bg1qmasrer8np51uwsyk
// Dict_t *agdtopen(Agraph_t * g, Dtdisc_t * disc, Dtmethod_t * method) 
public static _dt_s agdtopen(Agraph_s g, _dtdisc_s disc, _dtmethod_s method) {
ENTERING("48ox0bg1qmasrer8np51uwsyk","agdtopen");
try {
    Dtmemory_f memf;
    _dt_s d;
    memf = (Dtmemory_f) disc.getPtr("memoryf");
    disc.setPtr("memoryf", function(utils__c.class, "agdictobjmem"));
    Ag_dictop_G = g;
    d = dtopen(disc, method);
    disc.setPtr("memoryf", memf);
    Ag_dictop_G = null;
    return d;
} finally {
LEAVING("48ox0bg1qmasrer8np51uwsyk","agdtopen");
}
}




//3 6pbz2fsmebq8iy7if4way3ct2
// long agdtdelete(Agraph_t * g, Dict_t * dict, void *obj) 
public static Object agdtdelete(Object... arg) {
UNSUPPORTED("216ju3s3n4ltlcsntcuo0fg5p"); // long agdtdelete(Agraph_t * g, Dict_t * dict, void *obj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("id2cse8d1e37coxkbocjgjt4"); //     Ag_dictop_G = g;
UNSUPPORTED("1ii7n9w3quq15wnwynuuwg395"); //     return (long) (*(((Dt_t*)(dict))->searchf))((dict),(void*)(obj),0000002);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8a6i39x23joa467bqbo4b25ng
// int agobjfinalize(void * obj) 
public static Object agobjfinalize(Object... arg) {
UNSUPPORTED("74745f6w9shsg8hps5dn9cunv"); // int agobjfinalize(void * obj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dnx10u35ynobkoiuo7v5k2u49"); //     agfree(Ag_dictop_G, obj);
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 4x6nykawwls34vi6jc9gk1y29
// int agdtclose(Agraph_t * g, Dict_t * dict) 
public static Object agdtclose(Object... arg) {
UNSUPPORTED("8snkovnbu003p9w5cgbn12c73"); // int agdtclose(Agraph_t * g, Dict_t * dict)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ac1z24z48td8pa6zl9az4bqpd"); //     Dtmemory_f memf;
UNSUPPORTED("cawsyfy3xa5ktlemxuyyhd376"); //     Dtdisc_t *disc;
UNSUPPORTED("95hw7dddoneu0z8zzcnb1uslv"); //     disc = dtdisc(dict, ((Dtdisc_t *)0), 0);
UNSUPPORTED("9grut2uf2ma1mtzeq2sfg7p3f"); //     memf = disc->memoryf;
UNSUPPORTED("1jsr5jo041ushyjrdwyazntu7"); //     disc->memoryf = agdictobjmem;
UNSUPPORTED("id2cse8d1e37coxkbocjgjt4"); //     Ag_dictop_G = g;
UNSUPPORTED("32zal75ij4wrh56hfv01bu7as"); //     if (dtclose(dict))
UNSUPPORTED("eleqpc2p2r3hvma6tipoy7tr"); // 	return 1;
UNSUPPORTED("9qqgn587jlvxto7mbtmfh3o00"); //     disc->memoryf = memf;
UNSUPPORTED("dgvsuq3309uz08ww03zstdg8g"); //     Ag_dictop_G = ((Agraph_t*)0);
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cym72wvu6zffc0vzoa93zha8
// void agdtdisc(Agraph_t * g, Dict_t * dict, Dtdisc_t * disc) 
public static Object agdtdisc(Object... arg) {
UNSUPPORTED("75vpzrdnb0nxp5lbfz5qqcgv6"); // void agdtdisc(Agraph_t * g, Dict_t * dict, Dtdisc_t * disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("8t77ocger6q98unrxiz9zw11p"); //     if (disc && (dtdisc(dict, ((Dtdisc_t *)0), 0) != disc)) {
UNSUPPORTED("bvar6tty3ffc2if8avju3qrhu"); // 	dtdisc(dict, disc, 0);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("2yvkk3cq8ct0yqn676etd3285"); //     /* else unchanged, disc is same as old disc */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
