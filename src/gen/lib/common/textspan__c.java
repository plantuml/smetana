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
package gen.lib.common;
import static smetana.core.JUtilsDebug.ENTERING;
import static smetana.core.JUtilsDebug.LEAVING;
import static smetana.core.Macro.UNSUPPORTED;

import gen.annotation.Original;
import gen.annotation.Unused;
import h.ST_GVC_s;
import h.ST_dt_s;
import h.ST_pointf;
import h.ST_textspan_t;

public class textspan__c {

//3 n8tcl06mifdn779rzenam44z
// pointf textspan_size(GVC_t *gvc, textspan_t * span) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textspan_size", key="n8tcl06mifdn779rzenam44z", definition="pointf textspan_size(GVC_t *gvc, textspan_t * span)")
public static ST_pointf textspan_size(ST_GVC_s gvc, ST_textspan_t span) {
// WARNING!! STRUCT
return textspan_size_w_(gvc, span).copy();
}
private static ST_pointf textspan_size_w_(ST_GVC_s gvc, ST_textspan_t span) {
ENTERING("n8tcl06mifdn779rzenam44z","textspan_size");
try {
	System.err.println("Warning:textspan_size "+span);
	span.size.x = 30;
	span.size.y = 20;
    return span.size.copy();
} finally {
LEAVING("n8tcl06mifdn779rzenam44z","textspan_size");
}
}




//3 3bbrz9gqi8j8b5c1fxsnv6txg
// static void* textfont_makef(Dt_t* dt, void* obj, Dtdisc_t* disc) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textfont_makef", key="3bbrz9gqi8j8b5c1fxsnv6txg", definition="static void* textfont_makef(Dt_t* dt, void* obj, Dtdisc_t* disc)")
public static Object textfont_makef(Object... arg) {
UNSUPPORTED("ezwm25dnds89i6n9bz6jxfpyv"); // static void* textfont_makef(Dt_t* dt, void* obj, Dtdisc_t* disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("51vxeragpkjf0vwb07i7dl9x"); //     textfont_t *f1 = (textfont_t*)obj;
UNSUPPORTED("7j92va3n01tx9nm5lfz6stedq"); //     textfont_t *f2 = calloc(1,sizeof(textfont_t));
UNSUPPORTED("5w5r0tig83q9yoy6zhz5o7agc"); //     /* key */
UNSUPPORTED("23s5fksqi3wn73kpx2mipfx82"); //     if (f1->name) f2->name = strdup(f1->name);
UNSUPPORTED("f2zpyj0gm6kd4y0chvzpe3di4"); //     if (f1->color) f2->color = strdup(f1->color);
UNSUPPORTED("83wzklvzx2pc15wj16qppl4v2"); //     f2->flags = f1->flags;
UNSUPPORTED("8u1zhn0nsxkxbr1tmt2w8hw1f"); //     f2->size = f1->size;
UNSUPPORTED("62pprpgc67m2fs16j6p98kin6"); //     /* non key */
UNSUPPORTED("cf410wlb1gvcoq8d3oiajaph3"); //     f2->postscript_alias = f1->postscript_alias;
UNSUPPORTED("9y0cehsmm6fiuv0ibvh9e4gvz"); //     return f2;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 p4o48ztsya6bv2xz1m59jzrk
// static void textfont_freef(Dt_t* dt, void* obj, Dtdisc_t* disc) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textfont_freef", key="p4o48ztsya6bv2xz1m59jzrk", definition="static void textfont_freef(Dt_t* dt, void* obj, Dtdisc_t* disc)")
public static Object textfont_freef(Object... arg) {
UNSUPPORTED("d6z1bfrko1uq2uadgutf42fpr"); // static void textfont_freef(Dt_t* dt, void* obj, Dtdisc_t* disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bx771pipb8kf13oa7ww02nex3"); //     textfont_t *f = (textfont_t*)obj;
UNSUPPORTED("eymlly2a6yv51q1jufubndg9o"); //     if (f->name) free(f->name);
UNSUPPORTED("1omkvtjx5x2ef8xensxdm6wt7"); //     if (f->color) free(f->color);
UNSUPPORTED("a4v6veu7h0jl3a2wwlxwpdsuw"); //     free(f);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3xya6188lnt9kg5uwchhya2wt
// static int textfont_comparf (Dt_t* dt, void* key1, void* key2, Dtdisc_t* disc) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textfont_comparf", key="3xya6188lnt9kg5uwchhya2wt", definition="static int textfont_comparf (Dt_t* dt, void* key1, void* key2, Dtdisc_t* disc)")
public static Object textfont_comparf(Object... arg) {
UNSUPPORTED("9w5158s061nd0o3p6dbh4tnqz"); // static int textfont_comparf (Dt_t* dt, void* key1, void* key2, Dtdisc_t* disc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("1bh3yj957he6yv2dkeg4pzwdk"); //     int rc;
UNSUPPORTED("222ejoojlkxc5ocmxue2bgxdy"); //     textfont_t *f1 = (textfont_t*)key1, *f2 = (textfont_t*)key2;
UNSUPPORTED("87sttldb6hr2mn0ab405d03li"); //     if (f1->name || f2->name) {
UNSUPPORTED("2bqh121m1japcj8bnsuy6sc8q"); //         if (! f1->name) return -1;
UNSUPPORTED("86ytzx2x5nrcvurajdkbm95gk"); //         if (! f2->name) return 1;
UNSUPPORTED("673e3f928tkakxhcajat2h6p0"); //         rc = strcmp(f1->name, f2->name);
UNSUPPORTED("b9i8cahaxv9md4mvlw484iqeg"); //         if (rc) return rc;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7vzuntdto9vcvitx5s7m6zma7"); //     if (f1->color || f2->color) {
UNSUPPORTED("4tw0lvc7t2cc0000lrb9flurf"); //         if (! f1->color) return -1;
UNSUPPORTED("7xj68kytc2wzv6iq8ddwkwqlk"); //         if (! f2->color) return 1;
UNSUPPORTED("bcepjb2zqe0moqakgmofmbpq2"); //         rc = strcmp(f1->color, f2->color);
UNSUPPORTED("b9i8cahaxv9md4mvlw484iqeg"); //         if (rc) return rc;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9gf3266sjn2sm6m3mxf19197l"); //     rc = f1->flags - f2->flags;
UNSUPPORTED("9ngqgld29f5nt7h1ffl4s0em4"); //     if (rc) return rc;
UNSUPPORTED("d3e2n6libjqhx2xs4516lxyrf"); //     if (f1->size < f2->size) return -1;
UNSUPPORTED("1kww1mevjniiermvdkcyihkqp"); //     if (f1->size > f2->size) return 1;
UNSUPPORTED("5oxhd3fvp0gfmrmz12vndnjt"); //     return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9mfrgcpzz2d9f7nxfgx4nxj2q
// Dt_t * textfont_dict_open(GVC_t *gvc) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textfont_dict_open", key="9mfrgcpzz2d9f7nxfgx4nxj2q", definition="Dt_t * textfont_dict_open(GVC_t *gvc)")
public static ST_dt_s textfont_dict_open(ST_GVC_s gvc) {
ENTERING("9mfrgcpzz2d9f7nxfgx4nxj2q","textfont_dict_open");
try {
	return null;
//UNSUPPORTED("nexd6tbei8przmonjwzag8uf"); // Dt_t * textfont_dict_open(GVC_t *gvc)
//UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
//UNSUPPORTED("cdeb412fjgrtibum4qt0yxhc7"); //     ( (&(gvc->textfont_disc))->key = (0), (&(gvc->textfont_disc))->size = (sizeof(textfont_t)), (&(gvc->textfont_disc))->link = (-1), (&(gvc->textfont_disc))->makef = (textfont_makef), (&(gvc->textfont_disc))->freef = (textfont_freef), (&(gvc->textfont_disc))->comparf = (textfont_comparf), (&(gvc->textfont_disc))->hashf = (NULL), (&(gvc->textfont_disc))->memoryf = (NULL), (&(gvc->textfont_disc))->eventf = (NULL) );
//UNSUPPORTED("d1t3xr23spgfbbggquvg4nodm"); //     gvc->textfont_dt = dtopen(&(gvc->textfont_disc), Dtoset);
//UNSUPPORTED("6ynzkfpi9sy9wbln45o4jajhp"); //     return gvc->textfont_dt;
//UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }
} finally {
LEAVING("9mfrgcpzz2d9f7nxfgx4nxj2q","textfont_dict_open");
}
}




//3 5o4jyd0j7s18vl7inlo4o0w99
// void textfont_dict_close(GVC_t *gvc) 
@Unused
@Original(version="2.38.0", path="lib/common/textspan.c", name="textfont_dict_close", key="5o4jyd0j7s18vl7inlo4o0w99", definition="void textfont_dict_close(GVC_t *gvc)")
public static Object textfont_dict_close(Object... arg) {
UNSUPPORTED("7uxwdoqc8jmcbexpk4lhvdgg"); // void textfont_dict_close(GVC_t *gvc)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dyrkxfb6i5v7i47xoxoe22ykv"); //     dtclose(gvc->textfont_dt);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
