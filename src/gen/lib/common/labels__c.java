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
import static gen.lib.cgraph.edge__c.aghead;
import static gen.lib.cgraph.graph__c.agisdirected;
import static gen.lib.cgraph.id__c.agnameof;
import static gen.lib.cgraph.obj__c.agobjkind;
import static gen.lib.cgraph.obj__c.agraphof;
import static gen.lib.cgraph.obj__c.agroot;
import static gen.lib.common.htmltable__c.make_html_label;
import static gen.lib.common.utils__c.htmlEntityUTF8;
import static smetana.core.JUtils.NEQ;
import static smetana.core.JUtils.strlen;
import static smetana.core.JUtilsDebug.ENTERING;
import static smetana.core.JUtilsDebug.LEAVING;
import static smetana.core.Macro.AGEDGE;
import static smetana.core.Macro.AGNODE;
import static smetana.core.Macro.AGRAPH;
import static smetana.core.Macro.ED_head_port;
import static smetana.core.Macro.ED_label;
import static smetana.core.Macro.ED_tail_port;
import static smetana.core.Macro.GD_charset;
import static smetana.core.Macro.GD_gvc;
import static smetana.core.Macro.GD_label;
import static smetana.core.Macro.LT_HTML;
import static smetana.core.Macro.LT_RECD;
import static smetana.core.Macro.MAX;
import static smetana.core.Macro.N;
import static smetana.core.Macro.ND_label;
import static smetana.core.Macro.UNSUPPORTED;
import static smetana.core.Macro.agtail;
import static smetana.core.Macro.hackInitDimensionFromLabel;

import gen.annotation.Difficult;
import gen.annotation.Original;
import gen.annotation.Reviewed;
import gen.annotation.Unused;
import h.ST_Agedge_s;
import h.ST_Agnode_s;
import h.ST_Agraph_s;
import h.ST_GVC_s;
import h.ST_pointf;
import h.ST_port;
import h.ST_textlabel_t;
import h.ST_textspan_t;
import smetana.core.CStar;
import smetana.core.CString;
import smetana.core.Memory;
import smetana.core.Z;
import smetana.core.__ptr__;

public class labels__c {




@Reviewed(when = "13/11/2020")
@Difficult
@Original(version="2.38.0", path="lib/common/labels.c", name="storeline", key="4wkeqik2dt7ecr64ej6ltbnvb", definition="static void storeline(GVC_t *gvc, textlabel_t *lp, char *line, char terminator)")
public static void storeline(ST_GVC_s gvc, ST_textlabel_t lp, CString line, char terminator) {
ENTERING("4wkeqik2dt7ecr64ej6ltbnvb","storeline");
try {
    final ST_pointf size = new ST_pointf();
    ST_textspan_t span = null;
    int oldsz = lp.nspans + 1;
    
    lp.span = CStar.<ST_textspan_t>REALLOC__(oldsz + 1, lp.span, ST_textspan_t.class);
    span = lp.span.get__(lp.nspans);
    span.str = line;
    span.just = terminator;

	// WE CHEAT
	Z.z().tf.name = lp.fontname;
	Z.z().tf.size = lp.fontsize;
	size.x = 0.0;
	size.y = (int)(lp.fontsize * 1.20);
	hackInitDimensionFromLabel(size, line.getContent());
	span.size.y = (int)size.y;

    lp.nspans++;
    /* width = max line width */
    lp.dimen.x = MAX(lp.dimen.x, size.x);
    /* accumulate height */
    lp.dimen.y = lp.dimen.y + size.y;
} finally {
LEAVING("4wkeqik2dt7ecr64ej6ltbnvb","storeline");
}
}




@Reviewed(when = "12/11/2020")
@Original(version="2.38.0", path="lib/common/labels.c", name="make_simple_label", key="22ar72ye93a8ntj8pagnt5b5k", definition="void make_simple_label(GVC_t * gvc, textlabel_t * lp)")
public static void make_simple_label(ST_GVC_s gvc, ST_textlabel_t lp) {
ENTERING("22ar72ye93a8ntj8pagnt5b5k","make_simple_label");
try {
    char c;
    CString p, line, lineptr, str = lp.text;
    char bytee = 0x00;
    
    lp.dimen.x = lp.dimen.y = 0.0;
    if (str.charAt(0) == '\0')
	return;
    
    line = lineptr = null;
    p = str;
    line = lineptr = CString.gmalloc((strlen(p) + 1));
    line.setCharAt(0, '\0');
    while ((c = p.charAt(0))!='\0') {
    p = p.plus(1);
	bytee = c;
	/* wingraphviz allows a combination of ascii and big-5. The latter
         * is a two-byte encoding, with the first byte in 0xA1-0xFE, and
         * the second in 0x40-0x7e or 0xa1-0xfe. We assume that the input
         * is well-formed, but check that we don't go past the ending '\0'.
         */
	if ((lp.charset == 2) && 0xA1 <= bytee && bytee <= 0xFE) {
UNSUPPORTED("6la63t1mnqv30shyyp3yfroxb"); // 	    *lineptr++ = c;
UNSUPPORTED("ebmmarxykvf76hmfmjuk0ssjz"); // 	    c = *p++;
UNSUPPORTED("6la63t1mnqv30shyyp3yfroxb"); // 	    *lineptr++ = c;
UNSUPPORTED("1kri3b36twfj4t7bvjbrt6dhs"); // 	    if (!c) /* NB. Protect against unexpected string end here */
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
	} else {
	    if (c == '\\') {
		switch (p.charAt(0)) {
		case 'n':
		case 'l':
		case 'r':
		    lineptr.setCharAt(0, '\0');
		    lineptr = lineptr.plus(1);
		    storeline(gvc, lp, line, p.charAt(0));
		    line = lineptr;
		    break;
		default:
		    lineptr.setCharAt(0, p.charAt(0));
		    lineptr = lineptr.plus(1);
		}
		if (p.charAt(0)!='\0')
		    p = p.plus(1);
		/* tcldot can enter real linend characters */
	    } else if (c == '\n') {
		    lineptr.setCharAt(0, '\0');
		    lineptr = lineptr.plus(1);
		storeline(gvc, lp, line, 'n');
		line = lineptr;
	    } else {
	    lineptr.setCharAt(0, c);
	    lineptr = lineptr.plus(1);
	    }
	}
    }
    
    
    if (NEQ(line, lineptr)) {
	lineptr.setCharAt(0, '\0');
	lineptr = lineptr.plus(1);
	storeline(gvc, lp, line, 'n');
    }
    
    lp.space.___(lp.dimen);
} finally {
LEAVING("22ar72ye93a8ntj8pagnt5b5k","make_simple_label");
}
}




@Reviewed(when = "12/11/2020")
@Original(version="2.38.0", path="lib/common/labels.c", name="", key="ecq5lydlrjrlaz8o6vm6svc8i", definition="textlabel_t *make_label(void *obj, char *str, int kind, double fontsize, char *fontname, char *fontcolor)")
public static ST_textlabel_t make_label(__ptr__ obj, CString str, int kind, double fontsize, CString fontname, CString fontcolor) {
ENTERING("ecq5lydlrjrlaz8o6vm6svc8i","make_label");
try {
	ST_textlabel_t rv = new ST_textlabel_t();
    ST_Agraph_s g = null, sg = null;
    ST_Agnode_s n = null;
    ST_Agedge_s e = null;
        CString s = null;
        
        
    switch (agobjkind(obj)) {
    case AGRAPH:
        sg = (ST_Agraph_s)obj;
	g = (ST_Agraph_s) sg.root;
	break;
    case AGNODE:
        n = (ST_Agnode_s)obj.castTo(ST_Agnode_s.class);
	g = agroot(agraphof(n));
	break;
    case AGEDGE:
        e = (ST_Agedge_s)obj.castTo(ST_Agedge_s.class);
	g = agroot(agraphof(aghead(e)));
	break;
    }
    rv.fontname =  fontname;
    rv.fontcolor = fontcolor;
    rv.fontsize = fontsize;
    rv.charset = GD_charset(g);
    if ((kind & LT_RECD)!=0) {
	rv.text = str.strdup();
        if ((kind & LT_HTML)!=0) {
	    rv.html = (N(0));
	}
    }
    else if (kind == LT_HTML) {
	rv.text = str.strdup();
	rv.html = true;
	if (make_html_label(obj, rv)!=0) {
	    switch (agobjkind(obj)) {
    case AGRAPH:
	        UNSUPPORTED("agerr(AGPREV, in label of graph %s\n,agnameof(sg));");
		break;
    case AGNODE:
	        UNSUPPORTED("agerr(AGPREV, in label of node %s\n, agnameof(n));");
		break;
    case AGEDGE:
		UNSUPPORTED("agerr(AGPREV, in label of edge %s %s %s\n,");
//		        agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), agisdirected(g)?"->":"--", agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)));
		break;
	    }
	}
    }
    else {
        //assert(kind == (0 << 1));
	/* This call just processes the graph object based escape sequences. The formatting escape
         * sequences (\n, \l, \r) are processed in make_simple_label. That call also replaces \\ with \.
         */
	rv.text = strdup_and_subst_obj0(str, obj, 0);
        switch (rv.charset) {
    case 1:
	    UNSUPPORTED("s = latin1ToUTF8(rv->text);");
	    break;
	default: /* UTF8 */
	    s = htmlEntityUTF8(rv.text, g);
	    break;
	}
        Memory.free(rv.text);
        rv.text = s;
	make_simple_label(GD_gvc(g), rv);
    }
    return rv;
} finally {
LEAVING("ecq5lydlrjrlaz8o6vm6svc8i","make_label");
}
}




//3 1qv9kl0wi0snf1xtrb6vo2yiu
// void free_textspan(textspan_t * tl, int cnt) 
@Unused
@Original(version="2.38.0", path="lib/common/labels.c", name="free_textspan", key="1qv9kl0wi0snf1xtrb6vo2yiu", definition="void free_textspan(textspan_t * tl, int cnt)")
public static Object free_textspan(Object... arg) {
UNSUPPORTED("eh9j8hhtolluyaegv937nnpys"); // void free_textspan(textspan_t * tl, int cnt)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("4iuvdwfqjfqyk7dpy1s8mgw2o"); //     textspan_t* tlp = tl;
UNSUPPORTED("1f70128zxfm2jtz3ebwavc3nc"); //     if (!tl) return;
UNSUPPORTED("3r70mdmcurt4csiwolv9n6mmh"); //     for (i = 0; i < cnt; i++) { 
UNSUPPORTED("anxpl4mk65alvdjja9pn97kro"); // 	if ((i == 0) && tlp->str)
UNSUPPORTED("1fhpzk3z0aliuuzuovdmsmp7d"); // 	    free(tlp->str);
UNSUPPORTED("b0d4wly929yfs331ilovdcqjo"); // 	if (tlp->layout && tlp->free_layout)
UNSUPPORTED("40xyvfopujwdcztwx5vs27p5d"); // 	    tlp->free_layout (tlp->layout);
UNSUPPORTED("72ldhje939sa8dg5ttywkmwa6"); // 	tlp++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4pi9nz7hlvy0eo98r6tzd0oy"); //     free(tl);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2palqnlr5u0ssnag1bp5tq510
// void free_label(textlabel_t * p) 
@Unused
@Original(version="2.38.0", path="lib/common/labels.c", name="free_label", key="2palqnlr5u0ssnag1bp5tq510", definition="void free_label(textlabel_t * p)")
public static Object free_label(Object... arg) {
UNSUPPORTED("7fgqv20ow9mktpealn2ueqf9i"); // void free_label(textlabel_t * p)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3cvmixd2u1g2d9l03kuxyyxxw"); //     if (p) {
UNSUPPORTED("26ktwrszmdk4inac0pxe7mudg"); // 	free(p->text);
UNSUPPORTED("6sxnt2ovvq1ihlz4odqepnnln"); // 	if (p->html) {
UNSUPPORTED("8p452npbufapts0rm8ff82xfu"); // 	    if (p->u.html) free_html_label(p->u.html, 1);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("ghxtimeg851hu16krg2dnb14"); // 	    free_textspan(p->u.txt.span, p->u.txt.nspans);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("cy5x5dma0v4hiepir7lrfuo17"); // 	free(p);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 a0gse5mgpw0xhsmu4lwellfdq
// void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t * lp) 
@Unused
@Original(version="2.38.0", path="lib/common/labels.c", name="emit_label", key="a0gse5mgpw0xhsmu4lwellfdq", definition="void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t * lp)")
public static Object emit_label(Object... arg) {
UNSUPPORTED("2bspalmq4q86q66b0sehcnui"); // void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t * lp)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("84llcpxtvxaggx841n2t03850"); //     obj_state_t *obj = job->obj;
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("2bghyit203pd6xw2ihhenzyn8"); //     pointf p;
UNSUPPORTED("ecr1y7qy0ikxkidkdfvwv88ir"); //     emit_state_t old_emit_state;
UNSUPPORTED("c3lqudp40feg72zp97ngqkww9"); //     old_emit_state = obj->emit_state;
UNSUPPORTED("3ook7gsw0rr7b6uwm9f5a5dtx"); //     obj->emit_state = emit_state;
UNSUPPORTED("17ejiipjo2ljqtqe4rkpx6b15"); //     if (lp->html) {
UNSUPPORTED("8jyhluz8a51w5y5qalhlrpgnp"); // 	emit_html_label(job, lp->u.html, lp);
UNSUPPORTED("2rghcn1n5g9f29wxd8nqhub0p"); // 	obj->emit_state = old_emit_state;
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("71u0rnrd0pn6urf5ttv39ec5d"); //     /* make sure that there is something to do */
UNSUPPORTED("c4lzcn6qndbrx4u9kybwfk11l"); //     if (lp->u.txt.nspans < 1)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("2qj4sjf5amdyhvqsi47mei07v"); //     gvrender_begin_label(job, LABEL_PLAIN);
UNSUPPORTED("bl5mm7hn2il0n2e623rbq8q5w"); //     gvrender_set_pencolor(job, lp->fontcolor);
UNSUPPORTED("8a1fbspdbpecd6k8uj7bse1cx"); //     /* position for first span */
UNSUPPORTED("f433l06cgmbaiibsv9a9tjun8"); //     switch (lp->valign) {
UNSUPPORTED("c66d69vmpko3goomc3npvjhy3"); // 	case 't':
UNSUPPORTED("63ukdafw48pf9seqbe8vedft9"); //     	    p.y = lp->pos.y + lp->space.y / 2.0 - lp->fontsize;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("5coaag9ev3fzc0jtpkjkfvhd2"); // 	case 'b':
UNSUPPORTED("eodoiejpigubj8in93lnnc05d"); //     	    p.y = lp->pos.y - lp->space.y / 2.0 + lp->dimen.y - lp->fontsize;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("f3lyz2cejs6yn5fyckhn7ba1"); // 	case 'c':
UNSUPPORTED("8jmef3sfg06sme4q6t23ms8i7"); // 	default:	
UNSUPPORTED("bicy4u16zheftiukscavoqq3c"); //     	    p.y = lp->pos.y + lp->dimen.y / 2.0 - lp->fontsize;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8mg9hiit60q1ve98yormydem5"); //     for (i = 0; i < lp->u.txt.nspans; i++) {
UNSUPPORTED("aq0sxux77sg7whxt7hslkske3"); // 	switch (lp->u.txt.span[i].just) {
UNSUPPORTED("bwy7mh2nb7lz950r20rfilwa4"); // 	case 'l':
UNSUPPORTED("ds60aoxxlta1y3r5wuo09mzzp"); // 	    p.x = lp->pos.x - lp->space.x / 2.0;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("43ds1cyu29ex66kcjszrcu3mp"); // 	case 'r':
UNSUPPORTED("1103h1zfvqia1xelrw919hw2p"); // 	    p.x = lp->pos.x + lp->space.x / 2.0;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("1drv0xz8hp34qnf72b4jpprg2"); // 	default:
UNSUPPORTED("f187wptsr73liavtlyoyfovp3"); // 	case 'n':
UNSUPPORTED("7tkhws043t1k3ra1n1191ld2m"); // 	    p.x = lp->pos.x;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("a00q6gh3dlg3gdt95e6rt129n"); // 	gvrender_textspan(job, p, &(lp->u.txt.span[i]));
UNSUPPORTED("dczp8jeltzgwb21pyxgxyrasy"); // 	/* UL position for next span */
UNSUPPORTED("33byiwlc3a1j2oeyyqf04jpoo"); // 	p.y -= lp->u.txt.span[i].size.y;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8bm7lzosnhuf0od7i4hkgzovo"); //     gvrender_end_label(job);
UNSUPPORTED("b1bkq4eyrmepbxyb3qiuhi8b8"); //     obj->emit_state = old_emit_state;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




/* strdup_and_subst_obj0:
 * Replace various escape sequences with the name of the associated
 * graph object. A double backslash \\ can be used to avoid a replacement.
 * If escBackslash is true, convert \\ to \; else leave alone. All other dyads 
 * of the form \. are passed through unchanged.
 */
@Difficult
@Reviewed(when = "12/11/2020")
@Original(version="2.38.0", path="lib/common/labels.c", name="", key="ajohywvjbrvkc7zca2uew6ghm", definition="static char *strdup_and_subst_obj0 (char *str, void *obj, int escBackslash)")
public static CString strdup_and_subst_obj0(CString str, __ptr__ obj, int escBackslash) {
ENTERING("ajohywvjbrvkc7zca2uew6ghm","strdup_and_subst_obj0");
try {
    char c; CString s, p, t, newstr;
    CString tp_str = new CString(""), hp_str = new CString("");
    CString g_str = new CString("\\G"), n_str = new CString("\\N"), e_str = new CString("\\E"),
	h_str = new CString("\\H"), t_str = new CString("\\T"), l_str = new CString("\\L");
    int g_len = 2, n_len = 2, e_len = 2,
	h_len = 2, t_len = 2, l_len = 2,
	tp_len = 0, hp_len = 0;
    int newlen = 0;
    int isEdge = 0;
    ST_textlabel_t tl;
    final ST_port pt = new ST_port();
    
    
    /* prepare substitution strings */
    switch (agobjkind(obj)) {
	case AGRAPH:
	    g_str = agnameof((ST_Agraph_s)obj);
	    g_len = strlen(g_str);
	    tl = GD_label((ST_Agraph_s)obj);
	    if (tl!=null) {
		l_str = tl.text;
	    	if (str!=null) l_len = strlen(l_str);
	    }
	    break;
	case AGNODE:
	    g_str = agnameof(agraphof(obj.castTo(ST_Agnode_s.class)));
	    g_len = strlen(g_str);
	    n_str = agnameof(obj.castTo(ST_Agnode_s.class));
	    n_len = strlen(n_str);
	    tl = ND_label((ST_Agnode_s)obj.castTo(ST_Agnode_s.class));
	    if (tl!=null) {
		l_str = tl.text;
	    	if (str!=null) l_len = strlen(l_str);
	    }
	    break;
	case AGEDGE:
	    isEdge = 1;
	    g_str = agnameof(agroot(agraphof(agtail((obj.castTo(ST_Agedge_s.class))))));
	    g_len = strlen(g_str);
	    t_str = agnameof(agtail((obj.castTo(ST_Agedge_s.class))));
	    t_len = strlen(t_str);
	    pt.___(ED_tail_port(obj.castTo(ST_Agedge_s.class)));
	    if ((tp_str = pt.name)!=null)
	        tp_len = strlen(tp_str);
	    h_str = agnameof(aghead((obj.castTo(ST_Agedge_s.class))));
	    h_len = strlen(h_str);
	    pt.___(ED_head_port(obj.castTo(ST_Agedge_s.class)));
	    if ((hp_str = pt.name)!=null)
		hp_len = strlen(hp_str);
	    h_len = strlen(h_str);
	    tl = ED_label(obj.castTo(ST_Agedge_s.class));
	    if (tl!=null) {
	    	l_str = tl.text;
	    	if (str!=null) l_len = strlen(l_str);
	    }
	    if (agisdirected(agroot(agraphof(agtail((obj.castTo(ST_Agedge_s.class)))))))
		e_str = new CString("->");
	    else
		e_str = new CString("--");
	    e_len = t_len + (tp_len!=0?tp_len+1:0) + 2 + h_len + (hp_len!=0?hp_len+1:0);
	    break;
    }
    /* two passes over str.
     *
     * first pass prepares substitution strings and computes 
     * total length for newstring required from malloc.
     */
    for (s = str; ;) {
    c = s.charAt(0);
    s = s.plus(1);
    if (c=='\0') break;
	if (c == '\\') {
	  c = s.charAt(0);
	  s = s.plus(1);
	    switch (c) {
	    case 'G':
		newlen += g_len;
		break;
	    case 'N':
		newlen += n_len;
		break;
	    case 'E':
		newlen += e_len;
		break;
	    case 'H':
		newlen += h_len;
		break;
	    case 'T':
		newlen += t_len;
		break; 
	    case 'L':
		newlen += l_len;
		break; 
	    case '\\':
		if (escBackslash!=0) {
		    newlen += 1;
		    break; 
		}
		/* Fall through */
	    default:  /* leave other escape sequences unmodified, e.g. \n \l \r */
		newlen += 2;
	    }
	} else {
	    newlen++;
	}
    }
    /* allocate new string */
    newstr = CString.gmalloc(newlen + 1);
    
    
    /* second pass over str assembles new string */
    p = newstr;
    for (s = str; ;) {
    c = s.charAt(0);
    s = s.plus(1);
    if (c=='\0') break;
	if (c == '\\') {
	  c = s.charAt(0);
	  s = s.plus(1);
	    switch (c) {
	    case 'G':
		UNSUPPORTED("for (t = g_str; (*p = *t++); p++);");
		break;
	    case 'N':
		for (t = n_str; ; ) {
		p.setCharAt(0, t.charAt(0));
		t = t.plus(1);
		if (p.charAt(0)=='\0') break;
		p = p.plus(1);
		}
		break;
	    case 'E':
		UNSUPPORTED("if (isEdge) {");
/*		    for (t = t_str; (*p = *t++); p++);
		    if (tp_len) {
			*p++ = ':';
			for (t = tp_str; (*p = *t++); p++);
		    }
		    for (t = e_str; (*p = *t++); p++);
		    for (t = h_str; (*p = *t++); p++);
		    if (hp_len) {
			*p++ = ':';
			for (t = hp_str; (*p = *t++); p++);
		    }
		}*/
		break;
	    case 'T':
		UNSUPPORTED("for (t = t_str; (*p = *t++); p++);");
		break;
	    case 'H':
		UNSUPPORTED("for (t = h_str; (*p = *t++); p++);");
		break;
	    case 'L':
		UNSUPPORTED("for (t = l_str; (*p = *t++); p++);");
		break;
	    case '\\':
		UNSUPPORTED("if (escBackslash) {");
/*		    *p++ = '\\';
		    break; 
		}*/
		/* Fall through */
	    default:  /* leave other escape sequences unmodified, e.g. \n \l \r */
	    p.setCharAt(0, '\\');
	    p = p.plus(1);
	    p.setCharAt(0, c);
	    p = p.plus(1);
		break;
	    }
	} else {
	    p.setCharAt(0, c);
	    p = p.plus(1);
	}
    }
    p.setCharAt(0, '\0');
    p = p.plus(1);
    return newstr;
} finally {
LEAVING("ajohywvjbrvkc7zca2uew6ghm","strdup_and_subst_obj0");
}
}




//3 af2a0cdl8ld7bbq0qu0rt1d8z
// char *strdup_and_subst_obj(char *str, void *obj) 
@Unused
@Original(version="2.38.0", path="lib/common/labels.c", name="", key="af2a0cdl8ld7bbq0qu0rt1d8z", definition="char *strdup_and_subst_obj(char *str, void *obj)")
public static CString strdup_and_subst_obj(CString str, __ptr__ obj) {
ENTERING("af2a0cdl8ld7bbq0qu0rt1d8z","strdup_and_subst_obj");
try {
 UNSUPPORTED("7eeocxzl6qhtvcv7gnh73o7d1"); // char *strdup_and_subst_obj(char *str, void *obj)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("67419rdrhawe7vudn882sohkd"); //     return strdup_and_subst_obj0 (str, obj, 1);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("af2a0cdl8ld7bbq0qu0rt1d8z","strdup_and_subst_obj");
}
}



}
