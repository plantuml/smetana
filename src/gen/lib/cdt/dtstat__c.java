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
package gen.lib.cdt;
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

public class dtstat__c {
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




//3 91c7rdavgvzhuigvve5ibdpn0
// static void dttstat(Dtstat_t* ds, Dtlink_t* root, int depth, int* level)        
public static Object dttstat(Object... arg) {
UNSUPPORTED("96759a5l0ygg0om48m2a6t0ng"); // static void dttstat(Dtstat_t* ds, Dtlink_t* root, int depth, int* level)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("56ka5rmkoppf3hruu8g6m0xja"); // 	if(root->hl._left)
UNSUPPORTED("cid9xp3s0qj3aabaka0l9zv7t"); // 		dttstat(ds,root->hl._left,depth+1,level);
UNSUPPORTED("9s9ahe7p2w6fq5emj7g8wbjfr"); // 	if(root->right)
UNSUPPORTED("87cqywe08opun9vcdypm5sngz"); // 		dttstat(ds,root->right,depth+1,level);
UNSUPPORTED("1cpnp52f4qqoepwe6x0k1xfba"); // 	if(depth > ds->dt_n)
UNSUPPORTED("7ufge640ert57jo7j225ab7pe"); // 		ds->dt_n = depth;
UNSUPPORTED("3pj5kfo9kjuutf0og8g2j8geg"); // 	if(level)
UNSUPPORTED("9gine8rpyhyyk5yrtmvl56o2p"); // 		level[depth] += 1;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a8o5okh4tw99gnboco3s2dmxd
// static void dthstat(register Dtdata_t* data, Dtstat_t* ds, register int* count)       
public static Object dthstat(Object... arg) {
UNSUPPORTED("48ylybwp2yevlr561pyv3jui"); // static void dthstat(register Dtdata_t* data, Dtstat_t* ds, register int* count)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bqowb8dyq0iy0kow4ic3v69rm"); // 	register Dtlink_t*	t;
UNSUPPORTED("1kv2h7mwh5yurbekfwfiewdhy"); // 	register int		n, h;
UNSUPPORTED("286ioif0j041zmjzncvg5xoll"); // 	for(h = data->ntab-1; h >= 0; --h)
UNSUPPORTED("3q5ha8vx2tajjl4ufu2w0no4p"); // 	{	n = 0;
UNSUPPORTED("csnxwylxkitnmc1zga3njlqgd"); // 		for(t = data->hh._htab[h]; t; t = t->right)
UNSUPPORTED("90p2oslbn5buyc5k0tkflj50d"); // 			n += 1;
UNSUPPORTED("1pfuj1amofbpxyeubend5yxr5"); // 		if(count)
UNSUPPORTED("5nwitx1rnfie4jd6ny8ssadzg"); // 			count[n] += 1;
UNSUPPORTED("3w8in45yqqsl7kb6o0suodbq0"); // 		else if(n > 0)
UNSUPPORTED("ck4u5h04gsnndyuthxg9kuixs"); // 		{	ds->dt_n += 1;
UNSUPPORTED("487tl3ivbjnaxewh91pw7xeuh"); // 			if(n > ds->dt_max)
UNSUPPORTED("arga2k65qq28lxquyhcmmii6p"); // 				ds->dt_max = n;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 1kbkj84h5jc45cmi7lzd45dp
// int dtstat(register Dt_t* dt, Dtstat_t* ds, int all)       
public static Object dtstat(Object... arg) {
UNSUPPORTED("ao2i3bpekp72m9gi7y5ckz4rk"); // int dtstat(register Dt_t* dt, Dtstat_t* ds, int all)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("44m1eek6bje0mjqjlsecsorod"); // 	register int		i;
UNSUPPORTED("26pvlo4hyfclsuk4h43qetsjw"); // 	static int	*Count, Size;
UNSUPPORTED("ckjxpmega2z5oju8xk72wsy0q"); // 	((dt->data->type&010000) ? dtrestore(dt,((Dtlink_t*)0)) : 0);
UNSUPPORTED("ec11eijzw85083qye8hp5eex0"); // 	ds->dt_n = ds->dt_max = 0;
UNSUPPORTED("3tdmcypiwfwu1pn4i6zzf500z"); // 	ds->dt_count = ((int*)0);
UNSUPPORTED("azymim1m9qe68uhp1mftu7fe1"); // 	ds->dt_size = dtsize(dt);
UNSUPPORTED("av3q24lmuasi6ojxa3wldv6ta"); // 	ds->dt_meth = dt->data->type&0000377;
UNSUPPORTED("7wb0sc472yga8vixhnog657ny"); // 	if(!all)
UNSUPPORTED("5izxoao5ryte71964f8yjfd5y"); // 		return 0;
UNSUPPORTED("32ow9kmsxf47y1h17vyj3ef11"); // 	if(dt->data->type&(0000001|0000002))
UNSUPPORTED("3h1ytwsfcbphbuuhvj29vqlpn"); // 	{	dthstat(dt->data,ds,((int*)0));
UNSUPPORTED("cg0ykqnfk3ou03i5e9ykd3m5n"); // 		if(ds->dt_max+1 > Size)
UNSUPPORTED("4ebwk82nv6oujn3zi64gvqqr7"); // 		{	if(Size > 0)
UNSUPPORTED("4dxxr85kxn2tyyzxi82w0iqak"); // 				free(Count);
UNSUPPORTED("3a6ksysaw3s4hfdjvet2q2qxc"); // 			if(!(Count = (int*)malloc((ds->dt_max+1)*sizeof(int))) )
UNSUPPORTED("6pxdbvdu6loxn1ex6nm9i93gb"); // 				return -1;
UNSUPPORTED("13xjtjclxu8ornn37l48jz2rv"); // 			Size = ds->dt_max+1;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("36u41cy59sloyiha209o4m5qy"); // 		for(i = ds->dt_max; i >= 0; --i)
UNSUPPORTED("8aibp56k7f0yagfchektytbwy"); // 			Count[i] = 0;
UNSUPPORTED("b5vi0pdbdr81ex0fk7lepptgm"); // 		dthstat(dt->data,ds,Count);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("av63gjdiqp6xi9w4vjwqpn5oo"); // 	else if(dt->data->type&(0000004|0000010))
UNSUPPORTED("bld1jk0owgrtf4hcqqhwoccpy"); // 	{	if(dt->data->here)
UNSUPPORTED("31bytekoo4eleuggsetk4m6de"); // 		{	dttstat(ds,dt->data->here,0,((int*)0));
UNSUPPORTED("7hz6680zzj4qr9s3dm6v435sk"); // 			if(ds->dt_n+1 > Size)
UNSUPPORTED("aq4shezrsmlv37xas7p8ho5sg"); // 			{	if(Size > 0)
UNSUPPORTED("3y929awdu2jrmw3aer6dqygxb"); // 					free(Count);
UNSUPPORTED("ex3430euevoine0wgb82be0rc"); // 				if(!(Count = (int*)malloc((ds->dt_n+1)*sizeof(int))) )
UNSUPPORTED("9qiuahtnvh744qet6fj8wk596"); // 					return -1;
UNSUPPORTED("e80mtvhrb447fuzvxw7tmlk79"); // 				Size = ds->dt_n+1;
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("ce7lqmqeaeqmtpznl57wppd5n"); // 			for(i = ds->dt_n; i >= 0; --i)
UNSUPPORTED("6j9e4nc2e8eecvywkpfm2ut9m"); // 				Count[i] = 0;
UNSUPPORTED("7vm7v7g848394ourjpirftcq7"); // 			dttstat(ds,dt->data->here,0,Count);
UNSUPPORTED("ce7lqmqeaeqmtpznl57wppd5n"); // 			for(i = ds->dt_n; i >= 0; --i)
UNSUPPORTED("2t8ajn7ynd4ll8m6rug9gxbsx"); // 				if(Count[i] > ds->dt_max)
UNSUPPORTED("8d36wfd4xwyzw0stap7i7dv8y"); // 					ds->dt_max = Count[i];
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("cdj1cmsf0q45eayjhj4n0zpsn"); // 	ds->dt_count = Count;
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
