/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * If you like this project or if you find it useful, you can support us at:
 * 
 * http://plantuml.com/patreon (only 1$ per month!)
 * http://plantuml.com/paypal
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2022, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program:
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
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package gen.lib.cgraph;
import gen.annotation.Original;
import gen.annotation.Reviewed;
import gen.annotation.Unused;
import static smetana.core.JUtilsDebug.ENTERING;
import static smetana.core.JUtilsDebug.LEAVING;
import static smetana.core.Macro.AGEDGE;
import static smetana.core.Macro.AGINEDGE;
import static smetana.core.Macro.UNSUPPORTED;
import h.ST_Agraph_s;
import h.ST_IMapEntry_t;
import h.ST_dt_s;
import smetana.core.CString;

public class imap__c {


//3 mx2krtbgfhcihopw9rw8kcv3
// int aginternalmaplookup(Agraph_t * g, int objtype, char *str, 			unsigned long *result) 
@Unused
@Original(version="2.38.0", path="lib/cgraph/imap.c", name="aginternalmaplookup", key="mx2krtbgfhcihopw9rw8kcv3", definition="int aginternalmaplookup(Agraph_t * g, int objtype, char *str, 			unsigned long *result)")
public static int aginternalmaplookup(ST_Agraph_s g, int objtype, CString str, int result[]) {
ENTERING("mx2krtbgfhcihopw9rw8kcv3","aginternalmaplookup");
try {
 UNSUPPORTED("9xuzgjxqveawe6v2n4x48r93l"); // int aginternalmaplookup(Agraph_t * g, int objtype, char *str,
UNSUPPORTED("a9jw0mphzrt0q739cxcgk2hxw"); // 			unsigned long *result)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("l4y6zpshfefue2m18wlswfkp"); //     Dict_t *d;
UNSUPPORTED("6ich6qfkkifpsux1v4vgzhiyb"); //     IMapEntry_t *sym, template;
UNSUPPORTED("4uffdlbjda8w15jyto7gd77bw"); //     char *search_str;
UNSUPPORTED("84sccu12ven74lipf2dljgik4"); //     if (objtype == AGINEDGE)
UNSUPPORTED("5q9qhv35w1rsuiuzqkwgshm3p"); // 	objtype = AGEDGE;
UNSUPPORTED("drm2n6i20x3uimml5ooxm9u25"); //     if ((d = g->clos->lookup_by_name[objtype])) {
UNSUPPORTED("9ysphludc93c139uov8ximaj2"); // 	if ((search_str = agstrbind(g, str))) {
UNSUPPORTED("73apfmwxngxpf2twqiokd75ph"); // 	    template.str = search_str;
UNSUPPORTED("1r11yngj3z66q9h8k7rx0ifra"); // 	    sym = (IMapEntry_t *) (*(((Dt_t*)(d))->searchf))((d),(void*)(&template),0000004);
UNSUPPORTED("8watgmdse1o9uhfuhoexemnl2"); // 	    if (sym) {
UNSUPPORTED("68xn6zrkilfqqsosou3z2ym7o"); // 		*result = sym->id;
UNSUPPORTED("a1a1uhff21noh1htwzn6yp831"); // 		return (!(0));
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("297p5iu8oro94tdg9v29bbgiw"); //     return (0);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("mx2krtbgfhcihopw9rw8kcv3","aginternalmaplookup");
}
}




//3 ce8fo5gya95enhgssezqs3vav
// void aginternalmapinsert(Agraph_t * g, int objtype, char *str, 			 unsigned long id) 
@Unused
@Original(version="2.38.0", path="lib/cgraph/imap.c", name="aginternalmapinsert", key="ce8fo5gya95enhgssezqs3vav", definition="void aginternalmapinsert(Agraph_t * g, int objtype, char *str, 			 unsigned long id)")
public static Object aginternalmapinsert(Object... arg) {
UNSUPPORTED("bk4ucrzua03gr9lak6zfm3orp"); // void aginternalmapinsert(Agraph_t * g, int objtype, char *str,
UNSUPPORTED("18mfx819yhg1vg5xkrfjr96x2"); // 			 unsigned long id)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bh4b0zdn246m225u6zmdk75zs"); //     IMapEntry_t *ent;
UNSUPPORTED("84hwqfygghmcbo2exzo01t93o"); //     Dict_t *d_name_to_id, *d_id_to_name;
UNSUPPORTED("7wtz0h3ahdkrul4dbb0b7y0l4"); //     ent = ((IMapEntry_t*)(agalloc(g,sizeof(IMapEntry_t))));
UNSUPPORTED("6nwwse4s1ba0m9jfptthwwjbj"); //     ent->id = id;
UNSUPPORTED("d8vvc9mhtu43xfmzodcja9bu9"); //     ent->str = agstrdup(g, str);
UNSUPPORTED("84sccu12ven74lipf2dljgik4"); //     if (objtype == AGINEDGE)
UNSUPPORTED("5q9qhv35w1rsuiuzqkwgshm3p"); // 	objtype = AGEDGE;
UNSUPPORTED("cdo42je1dwhjo7hka7tk4bu20"); //     if ((d_name_to_id = g->clos->lookup_by_name[objtype]) == ((Dict_t *)0))
UNSUPPORTED("7tkuaa0dee3i2mkwj7ba9bmyj"); // 	d_name_to_id = g->clos->lookup_by_name[objtype] =
UNSUPPORTED("5em5y2jcl61223aawnzfqj4a0"); // 	    agdtopen(g, &LookupByName, Dttree);
UNSUPPORTED("4x4ql6no5kg3qbek3o45fn7nx"); //     if ((d_id_to_name = g->clos->lookup_by_id[objtype]) == ((Dict_t *)0))
UNSUPPORTED("7tmtjlukhbvxyxkd08ijr2m47"); // 	d_id_to_name = g->clos->lookup_by_id[objtype] =
UNSUPPORTED("bnhc1g7rce6un1du4m54v8m5r"); // 	    agdtopen(g, &LookupById, Dttree);
UNSUPPORTED("1y4a6gz63nnj0k1ip32krystr"); //     (*(((Dt_t*)(d_name_to_id))->searchf))((d_name_to_id),(void*)(ent),0000001);
UNSUPPORTED("6d4vd73oyoit1sj5kt1otroy9"); //     (*(((Dt_t*)(d_id_to_name))->searchf))((d_id_to_name),(void*)(ent),0000001);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




@Reviewed(when = "12/11/2020")
@Original(version="2.38.0", path="lib/cgraph/imap.c", name="", key="3r16pkjiksv8i7o961ltxyge6", definition="static IMapEntry_t *find_isym(Agraph_t * g, int objtype, unsigned long id)")
public static ST_IMapEntry_t find_isym(ST_Agraph_s g, int objtype, int id) {
ENTERING("3r16pkjiksv8i7o961ltxyge6","find_isym");
try {
    ST_dt_s d;
    ST_IMapEntry_t isym, itemplate = new ST_IMapEntry_t();
    if (objtype == AGINEDGE)
	objtype = AGEDGE;
    if ((d = g.clos.lookup_by_id[objtype])!=null) {
    UNSUPPORTED("itemplate.id = id;");
	isym = (ST_IMapEntry_t) UNSUPPORTED("(IMapEntry_t *) (*(((Dt_t*)(d))->searchf))((d),(void*)(&itemplate),0000004)");
    } else
	isym = null;
    return isym;
} finally {
LEAVING("3r16pkjiksv8i7o961ltxyge6","find_isym");
}
}




@Reviewed(when = "12/11/2020")
@Original(version="2.38.0", path="lib/cgraph/imap.c", name="", key="foe6bvtujfevsc0f3m8aqln8", definition="char *aginternalmapprint(Agraph_t * g, int objtype, unsigned long id)")
public static CString aginternalmapprint(ST_Agraph_s g, int objtype, int id) {
ENTERING("foe6bvtujfevsc0f3m8aqln8","aginternalmapprint");
try {
	ST_IMapEntry_t isym;
    if ((isym = find_isym(g, objtype, id))!=null)
	return isym.str;
    return null;
} finally {
LEAVING("foe6bvtujfevsc0f3m8aqln8","aginternalmapprint");
}
}


}
