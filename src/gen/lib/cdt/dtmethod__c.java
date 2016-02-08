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

public class dtmethod__c {
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




//3 5y8zard8q0t7wd1fznlyiu0is
// Dtmethod_t* dtmethod(Dt_t* dt, Dtmethod_t* meth)      
public static Object dtmethod(Object... arg) {
UNSUPPORTED("3km1xhxqsi1kc6xhl15kcri1f"); // Dtmethod_t* dtmethod(Dt_t* dt, Dtmethod_t* meth)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bf4mmzf6u2tqotgqbd6k8eqp0"); // 	register Dtlink_t	*list, *r;
UNSUPPORTED("ab9fv18fhjzwp3wngyyqarrns"); // 	register Dtdisc_t*	disc = dt->disc;
UNSUPPORTED("crjx4y1aesvbz4wkqg5642nj4"); // 	register Dtmethod_t*	oldmeth = dt->meth;
UNSUPPORTED("5c6whtsf2a3glrlh1kczzpqe9"); // 	if(!meth || meth->type == oldmeth->type)
UNSUPPORTED("8ttmhoaftdijn5bkmfimd9x7"); // 		return oldmeth;
UNSUPPORTED("8gsk9kzxnlwgo3aceze9c6gl7"); // 	if(disc->eventf &&
UNSUPPORTED("fwq3340fa0pnag7j0f4o7wzm"); // 	   (*disc->eventf)(dt,4,(void*)meth,disc) < 0)
UNSUPPORTED("2igwwp2cx3n29p50m7m8ioyv2"); // 		return ((Dtmethod_t*)0);
UNSUPPORTED("2eqdiqvcsxis68sccmci5sslk"); // 	dt->data->minp = 0;
UNSUPPORTED("3lnvvw51l9ruzql33ygokb3l9"); // 	/* get the list of elements */
UNSUPPORTED("458eivbagnsewjl8xhw519qcg"); // 	list = dtflatten(dt);
UNSUPPORTED("9qekjyedz55m5wna2o1oggk12"); // 	if(dt->data->type&(0000020|0000040|0000100) )
UNSUPPORTED("3v40gkacc2m6me0zor7nhpjmw"); // 		dt->data->hh._head = ((Dtlink_t*)0);
UNSUPPORTED("9l8vi2w86i0txe17utistljqu"); // 	else if(dt->data->type&(0000001|0000002) )
UNSUPPORTED("hysmhouy1ud6hsdj0cubiudt"); // 	{	if(dt->data->ntab > 0)
UNSUPPORTED("4ugmcpi8vkb013vuo4wykn0a3"); // 			(*dt->memoryf)(dt,(void*)dt->data->hh._htab,0,disc);
UNSUPPORTED("daqygvp6d794yl5eu8d06g3gi"); // 		dt->data->ntab = 0;
UNSUPPORTED("1wghucytlosmvwxh9hs06gqnv"); // 		dt->data->hh._htab = ((Dtlink_t**)0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("bl1pmhqf3x1in1wvwhq1v00u2"); // 	dt->data->here = ((Dtlink_t*)0);
UNSUPPORTED("762s6dooy1oj4wiqk2j8mtcs7"); // 	dt->data->type = (dt->data->type&~(0000377|010000)) | meth->type;
UNSUPPORTED("62j00tqtfsxxmirwb05ur7z0t"); // 	dt->meth = meth;
UNSUPPORTED("3hek07go1qr5flyhweyvb88hh"); // 	if(dt->searchf == oldmeth->searchf)
UNSUPPORTED("7d7hyoujq87agx8focnjapazd"); // 		dt->searchf = meth->searchf;
UNSUPPORTED("c0iupu78ptdjv7tkp4fp5eoem"); // 	if(meth->type&(0000020|0000040|0000100) )
UNSUPPORTED("10dxbmrp9w60lb4wyi4c6ze8a"); // 	{	if(!(oldmeth->type&(0000020|0000040|0000100)) )
UNSUPPORTED("c6eshgqlcm9am6oih7mqy27cx"); // 		{	if((r = list) )
UNSUPPORTED("cxw84g4fps5l02s4epfyl6n2r"); // 			{	register Dtlink_t*	t;
UNSUPPORTED("et4fiw7yaciidg54t59if0gz"); // 				for(t = r->right; t; r = t, t = t->right )
UNSUPPORTED("6y5abi7x957jjhe2rscd9ufjx"); // 					t->hl._left = r;
UNSUPPORTED("8nfo3btdkjap25oecr3r2t9zz"); // 				list->hl._left = r;
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("7duc1evkuyrgnx1k6sqnyoc1e"); // 		dt->data->hh._head = list;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("99xc5unqmtom8dp50z8en6k79"); // 	else if(meth->type&(0000004|0000010))
UNSUPPORTED("dejooawjmch41k0n8wz35280p"); // 	{	dt->data->size = 0;
UNSUPPORTED("dzuwpmnfrpq395y1ou6zll3u2"); // 		while(list)
UNSUPPORTED("4b3ko2bznm8f1y9qeju4acfua"); // 		{	r = list->right;
UNSUPPORTED("bdgaa5aljhk83mgc5oupnofue"); // 			(*meth->searchf)(dt,(void*)list,0000040);
UNSUPPORTED("eoujol9u634bcw14kwkb2lm5x"); // 			list = r;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("5i0ckqkt3yzykzquvm6nd08wf"); // 	else if(!((meth->type&0000002) && (oldmeth->type&0000001)) )
UNSUPPORTED("34wwvljvfvcvyh3obzyhgmnpo"); // 	{	int	rehash;
UNSUPPORTED("6akycohy5byonwsy0g7a3l1nk"); // 		if((meth->type&(0000001|0000002)) && !(oldmeth->type&(0000001|0000002)))
UNSUPPORTED("4o1gcrc4m2r1348akifhsvudt"); // 			rehash = 1;
UNSUPPORTED("1byx9oyi0ig37sdx42lv59xv"); // 		else	rehash = 0;
UNSUPPORTED("4zu0hy7teh1cxc74ifeho8ej3"); // 		dt->data->size = dt->data->loop = 0;
UNSUPPORTED("dzuwpmnfrpq395y1ou6zll3u2"); // 		while(list)
UNSUPPORTED("4b3ko2bznm8f1y9qeju4acfua"); // 		{	r = list->right;
UNSUPPORTED("20x8nlwk3x08qy0vwwzj6qtad"); // 			if(rehash)
UNSUPPORTED("30b8etf9nx2grv2w7rsytmgxk"); // 			{	register void* key = (disc->link < 0 ? ((Dthold_t*)(list))->obj : (void*)((char*)(list) - disc->link) );
UNSUPPORTED("8h5rhllokrgydtbfodokfa8tk"); // 				key = (void*)(disc->size < 0 ? *((char**)((char*)(key)+disc->key)) : ((char*)(key)+disc->key));
UNSUPPORTED("t4uwrmevpnx4doh1anexa33y"); // 				list->hl._hash = (disc->hashf ? (*disc->hashf)(dt,key,disc) : dtstrhash(0,key,disc->size) );
UNSUPPORTED("3to5h0rvqxdeqs38mhv47mm3o"); // 			}
UNSUPPORTED("9dj4v9f2xppzoxbumhwauuzk6"); // 			(void)(*meth->searchf)(dt,(void*)list,0000040);
UNSUPPORTED("eoujol9u634bcw14kwkb2lm5x"); // 			list = r;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("37bs415tc2fi47jgdzwr9kyeu"); // 	return oldmeth;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
