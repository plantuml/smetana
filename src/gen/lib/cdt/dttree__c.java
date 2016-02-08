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

public class dttree__c {
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




//3 abqfzg1d1vkzk51225tcdlik5
// static void* dttree(Dt_t* dt, void* obj, int type)       
static class no_root extends RuntimeException {}
static class has_root extends RuntimeException {}
static class do_search extends RuntimeException {}
static class dt_delete extends RuntimeException {}
static class dt_insert extends RuntimeException {}
static class dt_next extends RuntimeException {}
public static Object dttree(_dt_s dt, __ptr__ obj, int type) {
ENTERING("abqfzg1d1vkzk51225tcdlik5","dttree");
try {
	_dtlink_s	root, t;
	int		cmp, lk, sz, ky;
	_dtlink_s	l, r, me=null, link = (_dtlink_s) Memory.malloc(_dtlink_s.class);
	Object		o, k, key = null;
	int		n, minp; //, turn[(sizeof(size_t)*8 - 2)];
	Dtcompar_f	cmpf;
	_dtdisc_s	disc;
	if (((dt.getPtr("data").getInt("type")) & 010000) !=0) { dtrestore(dt,null); }
	disc = (_dtdisc_s) dt.getPtr("disc"); ky = disc.getInt("key");
	sz = disc.getInt("size");
	lk = disc.getInt("link");
	cmpf = (Dtcompar_f) disc.getPtr("comparf");
	dt.setInt("type", dt.getInt("type")&~0100000);
	root = (_dtlink_s) dt.getPtr("data").getPtr("here");
	if(N(obj))
	{	if(N(root) || N(type&(0000100|0000200|0000400)) )
			return null;
		if((type&0000100)!=0) /* delete all objects */
		{
		throw new UnsupportedOperationException();
//			if(disc->freef || disc->link < 0)
//			{	do
//				{	while((t = root->hl._left) )
//						(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
//					t = root->right;
//					if(disc->freef)
//						(*disc->freef)(dt,(lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ),disc);
//					if(disc->link < 0)
//						(*dt->memoryf)(dt,(void*)root,0,disc);
//				} while((root = t) );
//			}
//			dt->data->size = 0;
//			dt->data->here = ((Dtlink_t*)0);
//			return ((void*)0);
		}
		else /* computing largest/smallest element */
		{	if((type&0000400)!=0)
			{	while((t = (_dtlink_s) root.getPtr("right"))!=null ) {
				root.setPtr("right", t.getPtr("hl._left"));
				t.setPtr("hl._left", root);
				root = t;
				}
			}
			else /* type&DT_FIRST */
			{	while((t = (_dtlink_s) root.getPtr("hl._left"))!=null ) {
					root.setPtr("hl._left", t.getPtr("right"));
					t.setPtr("right", root);
					root = t;
				}
			}
			dt.getPtr("data").setPtr("here", root);
			return (lk < 0 ? root.castTo(_dthold_s.class).getPtr("obj") : root.addVirtualBytes(-lk) );
		}
	}
	/* note that link.right is LEFT tree and link.left is RIGHT tree */
	l = r = link;
	/* allow apps to delete an object "actually" in the dictionary */
	try {
	if(dt.getPtr("meth").getInt("type") == 0000010 && ((type&(0000002|0010000))!=0) ) {
		throw new UnsupportedOperationException();
//	{	key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
//		for(o = (*(((Dt_t*)(dt))->searchf))((dt),(void*)(obj),0000004); o; o = (*(((Dt_t*)(dt))->searchf))((dt),(void*)(o),0000010) )
//		{	k = (void*)(sz < 0 ? *((char**)((char*)(o)+ky)) : ((char*)(o)+ky));
//			if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
//				break;
//			if(o == obj)
//			{	root = dt->data->here;
//				l->right = root->hl._left;
//				r->hl._left  = root->right;
//				goto dt_delete;
//			}
//		}
	}
	try {
	if(((type&(0001000|0000004|0000001|0004000))!=0))
		{	key = ((type&0001000)!=0) ? obj : (sz < 0 ? ((__ptr__)obj).addVirtualBytes(ky) : ((__ptr__)obj).addVirtualBytes(ky));
		if(root!=null)
			throw new do_search();
	}
	else if((type&0000040)!=0) {
		throw new UnsupportedOperationException();
//	{	me = (Dtlink_t*)obj;
//		obj = (lk < 0 ? ((Dthold_t*)(me))->obj : (void*)((char*)(me) - lk) );
//		key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
//		if(root)
//			goto do_search;
	}
	else if(root!=null && (lk < 0 ? (root.castTo(_dthold_s.class).getPtr("obj")!=null): NEQ(root.addVirtualBytes(-lk), obj)))
	{	key = (sz < 0 ? UNSUPPORTED("*((char**)((char*)(obj)+ky))") : ((__ptr__)obj).addVirtualBytes(ky));
		throw new do_search();
	}
	} catch (do_search do_search) {
//		do_search:
		if(dt.getPtr("meth").getInt("type") == 0000004 &&
		   (minp = dt.getPtr("data").getInt("minp")) != 0 && (type&(0001000|0000004))!=0)
		{	/* simple search, note that minp should be even */
//			for(t = root, n = 0; n < minp; ++n)
//			{	k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
//				if((cmp = (cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) )) == 0)
//					return (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) );
//				else
//				{	turn[n] = cmp;	
//					if(!(t = cmp < 0 ? t->hl._left : t->right) )
//						return ((void*)0);
//				}
//			}
//			/* exceed search length, top-down splay now */
//			for(n = 0; n < minp; n += 2)
//			{	if(turn[n] < 0)
//				{	t = root->hl._left;
//					if(turn[n+1] < 0)
//					{	((root)->hl._left = (t)->right, (t)->right = (root));
//						((r) = (r)->hl._left = (t) );
//						root = t->hl._left;
//					}
//					else
//					{	((l) = (l)->right = (t) );
//						((r) = (r)->hl._left = (root) );
//						root = t->right;
//					}
//				}
//				else
//				{	t = root->right;
//					if(turn[n+1] > 0)
//					{	((root)->right = (t)->hl._left, (t)->hl._left = (root));
//						((l) = (l)->right = (t) );
//						root = t->right;
//					}
//					else
//					{	((r) = (r)->hl._left = (t) );
//						((l) = (l)->right = (root) );
//						root = t->hl._left;
//					}
//				}
//			}
			throw new UnsupportedOperationException("do_search1");
		}
		while(true) {
			k = lk < 0 ? root.castTo(_dthold_s.class).getPtr("obj") : root.addVirtualBytes(-lk); 
			k = sz < 0 ? ((__ptr__)k).addVirtualBytes(ky) : ((__ptr__)k).addVirtualBytes(ky);
			if((cmp = (cmpf!=null ? (Integer)((CFunction)cmpf).exe(dt,key,k,disc) : 
				(sz <= 0 ? strcmp((CString)key,(CString)k) : UNSUPPORTED_INT("memcmp(key,k,sz))") ))) == 0)
				break;
			else if(cmp < 0)
			{	if((t = (_dtlink_s) root.getPtr("hl._left"))!=null )
				{
				k = lk < 0 ? t.castTo(_dthold_s.class).getPtr("obj") : t.addVirtualBytes(-lk);
				k = sz < 0 ? ((__ptr__)k).addVirtualBytes(ky) : ((__ptr__)k).addVirtualBytes(ky);
				if((cmp = (cmpf!=null ? (Integer)((CFunction)cmpf).exe(dt,key,k,disc)
	 					 : (sz <= 0 ? strcmp((CString)key,(CString)k) : UNSUPPORTED_INT("memcmp(key,k,sz))") ))) < 0)
					{	root.setPtr("hl._left", t.getPtr("right"));
						t.setPtr("right", root);
						r.setPtr("hl._left", t);
						r = t;
						if(N(root = (_dtlink_s) t.getPtr("hl._left")) )
							break;
					}
					else if(cmp == 0)
					{	r.setPtr("hl._left", root);
						r = root;
						root = t;
						break;
					}
					else /* if(cmp > 0) */
					{	l.setPtr("right", t);
						l = t;
						r.setPtr("hl._left", root);
						r  = root;
						if(N(root = (_dtlink_s) t.getPtr("right")) )
							break;
					}
				}
				else
				{
					r.setPtr("hl._left", root);
					r = root;
					root = null;
					break;
				}
			}
			else /* if(cmp > 0) */
			{	if ((t = (_dtlink_s) root.getPtr("right"))!=null )
				{
					k = (lk < 0 ? UNSUPPORTED("((Dthold_t*)(t))->obj") : t.addVirtualBytes(-lk) ); 
 					k = sz < 0 ? ((__ptr__)k).addVirtualBytes(ky) : ((__ptr__)k).addVirtualBytes(ky);
					if((cmp = (cmpf!=null ? (Integer)((CFunction)cmpf).exe(dt,key,k,disc) 
 					 : (sz <= 0 ? strcmp((CString)key,(CString)k) : UNSUPPORTED_INT("memcmp(key,k,sz))") ))) > 0)
					{
						root.setPtr("right", t.getPtr("hl._left"));
						t.setPtr("hl._left", root);
						l.setPtr("right", t);
						l = t;
						if(N(root = (_dtlink_s) t.getPtr("right") ))
							break;
					}
					else if(cmp == 0)
					{	l.setPtr("right", root);
						l = root;
						root = t;
						break;
					}
					else /* if(cmp < 0) */
					{	r.setPtr("hl._left", t);
						r = t;
						l.setPtr("right", root);
						l = root;
						if(N(root = (_dtlink_s) t.getPtr("hl._left") ))
							break;
					}
				}
				else
				{	l.setPtr("right", root);
					l = root;
					root = null;
					break;
				}
			}
		}
	}
	if(root!=null)
	{	/* found it, now isolate it */
		dt.setInt("type", dt.getInt("type") | 0100000);
		l.setPtr("right", root.getPtr("hl._left"));
		r.setPtr("hl._left", root.getPtr("right"));
		if((type&(0000004|0001000))!=0)
		{ /*has_root:*/
		throw new has_root();
		}
		else if((type&0000010)!=0)
		{	root.setPtr("hl._left", link.getPtr("right"));
			root.setPtr("right", null);
			link.setPtr("right", root);
		//dt_next:
			if((root = (_dtlink_s) link.getPtr("hl._left"))!=null )	
			{	while((t = (_dtlink_s) root.getPtr("hl._left"))!=null ) {
					root.setPtr("hl._left", t.getPtr("right"));
					t.setPtr("right", root);
					root = t;
				}
				link.setPtr("hl._left", root.getPtr("right"));
				throw new has_root();
			}
			else	throw new no_root();
		}
		else if((type&0000020)!=0) {
		throw new UnsupportedOperationException();
//		{	root->right = link.hl._left;
//			root->hl._left = ((Dtlink_t*)0);
//			link.hl._left = root;
//		dt_prev:
//			if((root = link.right) )
//			{	while((t = root->right) )
//					(((root)->right = (t)->hl._left, (t)->hl._left = (root)), (root) = (t));
//				link.right = root->hl._left;
//				goto has_root;
//			}
//			else	goto no_root;
		}
		else if((type&(0000002|0010000))!=0) {
		throw new UnsupportedOperationException();
//		{	/* taking an object out of the dictionary */
//		dt_delete:
//			obj = (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) );
//			if(disc->freef && (type&0000002))
//				(*disc->freef)(dt,obj,disc);
//			if(disc->link < 0)
//				(*dt->memoryf)(dt,(void*)root,0,disc);
//			if((dt->data->size -= 1) < 0)
//				dt->data->size = -1;
//			goto no_root;
		}
		else if((type&(0000001|0004000))!=0) {
		throw new UnsupportedOperationException();
//		{	if(dt->meth->type&0000004)
//				goto has_root;
//			else
//			{	root->hl._left = ((Dtlink_t*)0);
//				root->right = link.hl._left;
//				link.hl._left = root;
//				goto dt_insert;
//			}
		}
		else if((type&0000040)!=0) /* a duplicate */ {
		throw new UnsupportedOperationException();
//		{	if(dt->meth->type&0000004)
//			{	if(disc->freef)
//					(*disc->freef)(dt,obj,disc);
//				if(disc->link < 0)
//					(*dt->memoryf)(dt,(void*)me,0,disc);
//			}
//			else
//			{	me->hl._left = ((Dtlink_t*)0);
//				me->right = link.hl._left;
//				link.hl._left = me;
//				dt->data->size += 1;
//			}
//			goto has_root;
		}
	}
	else
	{	/* not found, finish up LEFT and RIGHT trees */
		r.setPtr("hl._left", null);
		l.setPtr("right", null);
		if((type&0000010)!=0)
			throw new UnsupportedOperationException("goto dt_next");
		else if((type&0000020)!=0)
			throw new UnsupportedOperationException("goto dt_prev");
		else if((type&(0000004|0001000))!=0)
		{
			throw new no_root();
		}
		else if((type&(0000001|0004000))!=0)
		{ /*dt_insert:*/
			if(disc.getPtr("makef")!=null && (type&0000001)!=0)
				obj = (__ptr__) disc.call("makef", dt,obj,disc);
			if(obj!=null)
			{
				if(lk >= 0)
					root = (_dtlink_s) ((__ptr__)obj.addVirtualBytes(lk)).castTo(_dtlink_s.class);
				else
				{
					root = (_dtlink_s)(dt.call("memoryf",
						dt,null,sizeof(_dthold_s.class),disc));
					if(root!=null)
						root.castTo(_dthold_s.class).setPtr("obj", obj);
					else if(disc.getPtr("makef")!=null && disc.getPtr("freef")!=null &&
						((type&0000001))!=0)
						UNSUPPORTED("(*disc->freef)(dt,obj,disc);");
				}
			}
			if(root!=null)
			{	if(dt.getPtr("data").getInt("size") >= 0)
					dt.getPtr("data").setInt("size", dt.getPtr("data").getInt("size")+1 );
			throw new has_root();
			}
			else	throw new UnsupportedOperationException("goto no_root");
		}
		else if((type&0000040)!=0)
		{	root = me;
			dt.getPtr("data").setInt("size", dt.getPtr("data").getInt("size")+1 );
			throw new UnsupportedOperationException("goto has_root");
		}
		else /*if(type&DT_DELETE)*/
		{	obj = null;
		throw new UnsupportedOperationException("goto no_root");
		}
		// throw new UnsupportedOperationException();
	}
//	return ((void*)0);
	} catch (has_root has_root) {
	    root = (_dtlink_s) root.castTo(_dtlink_s.class);
		root.setPtr("hl._left", link.getPtr("right"));
		root.setPtr("right", link.getPtr("hl._left"));
		if((dt.getPtr("meth").getInt("type")&0000010)!=0 && (type&(0000004|0001000))!=0 )
		{	//key = (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ); key = (void*)(sz < 0 ? *((char**)((char*)(key)+ky)) : ((char*)(key)+ky));
			throw new UnsupportedOperationException();
//			while((t = root->hl._left) )
//			{	/* find max of left subtree */
//				while((r = t->right) )
//					(((t)->right = (r)->hl._left, (r)->hl._left = (t)), (t) = (r));
//				root->hl._left = t;
//				/* now see if it's in the same group */
//				k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
//				if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
//					break;
//				(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
//			}
		}
		dt.getPtr("data").setPtr("here", root);
		return (lk < 0 ? root.castTo(_dthold_s.class).getPtr("obj") : root.addVirtualBytes(-lk));
	} catch (no_root no_root) {
			while((t = (_dtlink_s) r.getPtr("hl._left"))!=null)
				r = t;
			r.setPtr("hl._left", link.getPtr("right"));
			dt.getPtr("data").setPtr("here", link.getPtr("hl._left"));
			return (type&0000002)!=0 ? obj : null;
	}
throw new UnsupportedOperationException();
} finally {
LEAVING("abqfzg1d1vkzk51225tcdlik5","dttree");
}
}


//1 9g22bw0wprm2n836sva9a545j
// static Dtmethod_t	_Dtoset =  


//1 6lntjtw57dbb52lukeu9qbjm0
// static Dtmethod_t	_Dtobag =  


//1 23jnfpje5fw0aejl101d0mofi
// Dtmethod_t* Dtoset = &_Dtoset


//1 b8q5rjkvf93u0f27esfu3h9ay
// Dtmethod_t* Dtobag = &_Dtobag


//1 5kf1n1yhdy9ojgc0mc3pyowaz
// Dtmethod_t		_Dttree = 
public static final __struct__<_dtmethod_s> _Dttree = __struct__.from(_dtmethod_s.class);
static {
	_Dttree.setPtr("searchf", function(dttree__c.class, "dttree"));
	_Dttree.setInt("type", 0000004);
}

//1 bvfgwxg0ik8j0au3xhv5ear7h
// Dtmethod_t* Dtorder = &_Dttree


//1 avyrqfvu00yyj95dihtoiwmao
// Dtmethod_t* Dttree = &_Dttree
public static _dtmethod_s Dttree = _Dttree.amp();
}
