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

public class dtview__c {
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




//3 6spidg45w8teb64726drdswaa
// static void* dtvsearch(Dt_t* dt, register void* obj, register int type)       
public static Object dtvsearch(Object... arg) {
UNSUPPORTED("6lbocx09p5veft2ccvxsn3pec"); // static void* dtvsearch(Dt_t* dt, register void* obj, register int type)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5zzv6381ipve1g512fv7ccdgf"); // 	Dt_t		*d, *p;
UNSUPPORTED("69um62c2am273c1ln0lq60etm"); // 	void		*o, *n, *ok, *nk;
UNSUPPORTED("bq6hgr9t9rzcugtkq1pdk2cpy"); // 	int		cmp, lk, sz, ky;
UNSUPPORTED("7pefxwul88sft8fki9hq7evf6"); // 	Dtcompar_f	cmpf;
UNSUPPORTED("ckdvtn5e5oujt5stmeoaxnluh"); // 	/* these operations only happen at the top level */
UNSUPPORTED("5d2idljwmymdd7xddiu7aysfy"); // 	if(type&(0000001|0000002|0000100|0000040))
UNSUPPORTED("7nihk0fy1qnfmm8lcxvd0wuen"); // 		return (*(dt->meth->searchf))(dt,obj,type);
UNSUPPORTED("61laja0xe6bla1emamd2tfvka"); // 	if((type&(0001000|0000004)) || /* order sets first/last done below */
UNSUPPORTED("4ih60kv3n4ddtwasouzwqlkkz"); // 	   ((type&(0000200|0000400)) && !(dt->meth->type&(0000010|0000004)) ) )
UNSUPPORTED("eh58afn12udc5q8yzr25advls"); // 	{	for(d = dt; d; d = d->view)
UNSUPPORTED("99dyygo1p8ivdwvxg0kyro2wb"); // 			if((o = (*(d->meth->searchf))(d,obj,type)) )
UNSUPPORTED("1dhrv6aj5eq8ntuvb7qbs8aot"); // 				break;
UNSUPPORTED("66mzv36wy2mflr2u2a5pwa2vg"); // 		dt->walk = d;
UNSUPPORTED("c4mj2aqm6yf1jzso7g9z92g39"); // 		return o;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("d84il68c0i90tp5aftrxjyley"); // 	if(dt->meth->type & (0000010|0000004) )
UNSUPPORTED("8slxj5mr48fufo0dlxt1so6ee"); // 	{	if(!(type & (0000200|0000400|0000010|0000020)) )
UNSUPPORTED("aihzmr4oo3tuh6kkxwtn9tlbd"); // 			return ((void*)0);
UNSUPPORTED("eowja0ddbl6y3a9u3w79v7krv"); // 		n = nk = ((void*)0); p = ((Dt_t*)0);
UNSUPPORTED("43jcj7f6oixq18qedtztm6amw"); // 		for(d = dt; d; d = d->view)
UNSUPPORTED("6kcns069wnooq8ody5agu9dts"); // 		{	if(!(o = (*d->meth->searchf)(d, obj, type)) )
UNSUPPORTED("e64uozw3yxyqu9qwwilblfspf"); // 				continue;
UNSUPPORTED("4f62457uttr71ofvfr1j1o5w1"); // 			(ky = d->disc->key, sz = d->disc->size, lk = d->disc->link, cmpf = d->disc->comparf);
UNSUPPORTED("3toy9k4m6evk7wvheiwlwrqac"); // 			ok = (void*)(sz < 0 ? *((char**)((char*)(o)+ky)) : ((char*)(o)+ky));
UNSUPPORTED("4ccvzqq1qhq1n54s3zk1n1g6m"); // 			if(n) /* get the right one among all dictionaries */
UNSUPPORTED("3901wgr15qsodkeaua3t1cowa"); // 			{	cmp = (cmpf ? (*cmpf)(d,ok,nk,d->disc) : (sz <= 0 ? strcmp(ok,nk) : memcmp(ok,nk,sz)) );
UNSUPPORTED("dbakrc2nyretewvmfasl8hcya"); // 				if(((type & (0000010|0000200)) && cmp < 0) ||
UNSUPPORTED("dtwrbl1qp7i61npnve1m7w05f"); // 				   ((type & (0000020|0000400)) && cmp > 0) )
UNSUPPORTED("5o3u9aaanyd9yh74sjfkkofmo"); // 					goto a_dj;
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("8i5fu2uj3vy2l5q8mvuvj9ko8"); // 			else /* looks good for now */
UNSUPPORTED("9xbf1cn825arg4uuemeup3va4"); // 			{ a_dj: p  = d;
UNSUPPORTED("9oscy9gf8ohksry0rta6xvh5a"); // 				n  = o;
UNSUPPORTED("9lzq8mn8zytb3ohf1f25weiml"); // 				nk = ok;
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("67qa4oqf6540erd7ajdprlox1"); // 		dt->walk = p;
UNSUPPORTED("69tnrt5iss03p3i37w8i74v6k"); // 		return n;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("agjavr8uuhtiynnwkg5bnolky"); // 	/* non-ordered methods */
UNSUPPORTED("36qdhpbcwst6tc1gvwcyvg91u"); // 	if(!(type & (0000010|0000020)) )
UNSUPPORTED("5p6q7ip4om6y4nrsjz07ua456"); // 		return ((void*)0);
UNSUPPORTED("bx84jj9durkqzcrq4l9h1b0za"); // 	if(!dt->walk || obj != (dt->walk->disc->link < 0 ? ((Dthold_t*)(dt->walk->data->here))->obj : (void*)((char*)(dt->walk->data->here) - dt->walk->disc->link) ) )
UNSUPPORTED("eh58afn12udc5q8yzr25advls"); // 	{	for(d = dt; d; d = d->view)
UNSUPPORTED("de5yx4s0nsbgshd9seabcy2g9"); // 			if((o = (*(d->meth->searchf))(d, obj, 0000004)) )
UNSUPPORTED("1dhrv6aj5eq8ntuvb7qbs8aot"); // 				break;
UNSUPPORTED("66mzv36wy2mflr2u2a5pwa2vg"); // 		dt->walk = d;
UNSUPPORTED("d4pllgr7b2ohssrhtxxtd1fbb"); // 		if(!(obj = o) )
UNSUPPORTED("aihzmr4oo3tuh6kkxwtn9tlbd"); // 			return ((void*)0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("6he3c07r1xjfepuku37yav920"); // 	for(d = dt->walk, obj = (*d->meth->searchf)(d, obj, type);; )
UNSUPPORTED("d7hiatjof3gfyx3ab27oq4d74"); // 	{	while(obj) /* keep moving until finding an uncovered object */
UNSUPPORTED("44tdztkynd140cqbaafbbxvqn"); // 		{	for(p = dt; ; p = p->view)
UNSUPPORTED("72t51pabtpfsnn4qrcjvd6gkb"); // 			{	if(p == d) /* adjacent object is uncovered */	
UNSUPPORTED("4an2jpd7xs9lm1jlfrbualsrv"); // 					return obj;
UNSUPPORTED("bndt77eukkw8dnhl8sce4ts3d"); // 				if((*(p->meth->searchf))(p, obj, 0000004) )
UNSUPPORTED("6ioth986rfbv208dp59shjy15"); // 					break;
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("5bx9ax8tembk4pweu41m5yw43"); // 			obj = (*d->meth->searchf)(d, obj, type);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("3diupilxwbi5nroolxiy7e8b0"); // 		if(!(d = dt->walk = d->view) ) /* move on to next dictionary */
UNSUPPORTED("aihzmr4oo3tuh6kkxwtn9tlbd"); // 			return ((void*)0);
UNSUPPORTED("esje2igec9cwwteta36lbrdvc"); // 		else if(type&0000010)
UNSUPPORTED("aeh2pn8gp2xj4lehv52n4hp6b"); // 			obj = (*(d->meth->searchf))(d,((void*)0),0000200);
UNSUPPORTED("1lfqka4p8e7w15b16wquy0vjx"); // 		else	obj = (*(d->meth->searchf))(d,((void*)0),0000400);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dfryioch2xz35w8nq6lxbk5kh
// Dt_t* dtview(register Dt_t* dt, register Dt_t* view)      
public static _dt_s dtview(_dt_s dt, _dt_s view) {
ENTERING("dfryioch2xz35w8nq6lxbk5kh","dtview");
try {
	_dt_s	d;
	if ((dt.getPtr("data").getInt("type")&010000)!=0) dtrestore(dt,null);
	if(view!=null)
	{	if ((view.getPtr("data").getInt("type")&010000)!=0) dtrestore(view,null);
		if(NEQ(view.getPtr("meth"), dt.getPtr("meth"))) /* must use the same method */
			UNSUPPORTED("return null;");
	}
	/* make sure there won't be a cycle */
	for(d = view; d!=null; d = (_dt_s)d.getPtr("view"))
		if(EQ(d, dt))
			return null;
	/* no more viewing lower dictionary */
	if((d = (_dt_s)dt.getPtr("view"))!=null )
		d.setInt("nview", d.getInt("nview")-1);
	dt.setPtr("walk", null);
	dt.setPtr("view", null);
	if(N(view))
	{	dt.setPtr("searchf", dt.getPtr("meth").getPtr("searchf"));
		return d;
	}
	/* ok */
	dt.setPtr("view", view);
	dt.setPtr("searchf", function(dtview__c.class, "dtvsearch"));
	view.setInt("nview", view.getInt("nview")+1 );
	return view;
} finally {
LEAVING("dfryioch2xz35w8nq6lxbk5kh","dtview");
}
}


}
