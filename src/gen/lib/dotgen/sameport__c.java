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
package gen.lib.dotgen;
import gen.annotation.Original;
import gen.annotation.Reviewed;
import gen.annotation.Unused;
import static gen.lib.cgraph.attr__c.agattr;
import static smetana.core.JUtilsDebug.ENTERING;
import static smetana.core.JUtilsDebug.LEAVING;
import static smetana.core.Macro.AGEDGE;
import static smetana.core.Macro.N;
import static smetana.core.Macro.UNSUPPORTED;
import h.ST_Agedge_s;
import h.ST_Agnode_s;
import h.ST_Agraph_s;
import h.ST_pointf;
import smetana.core.CString;
import smetana.core.Z;

public class sameport__c {




//3 eu2yvovb9xx4rzic3gllij2bv
// void dot_sameports(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/sameport.c", name="dot_sameports", key="eu2yvovb9xx4rzic3gllij2bv", definition="void dot_sameports(graph_t * g)")
public static void dot_sameports(ST_Agraph_s g) {
ENTERING("eu2yvovb9xx4rzic3gllij2bv","dot_sameports");
try {
    ST_Agnode_s n;
    ST_Agedge_s e;
    CString id;
    //same_t samehead[5];
    //same_t sametail[5];
    int n_samehead;		/* number of same_t groups on current node */
    int n_sametail;		/* number of same_t groups on current node */
    int i;
    Z.z().E_samehead = agattr(g, AGEDGE, new CString("samehead"),null);
    Z.z().E_sametail = agattr(g, AGEDGE, new CString("sametail"),null);
    if (N(Z.z().E_samehead!=null || Z.z().E_sametail!=null))
	return;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("4roxmr5lxkjz6gn1j9mndurq2"); // 	n_samehead = n_sametail = 0;
UNSUPPORTED("8oxob1qbbkbjh0jjcogk42jfl"); // 	for (e = agfstedge(g, n); e; e = agnxtedge(g, e, n)) {
UNSUPPORTED("4gy7rakqurxvound05crezka2"); // 	    if (aghead(e) == agtail(e)) continue;  /* Don't support same* for loops */
UNSUPPORTED("2r5fkddp1ey0fvpok2scgkk99"); // 	    if (aghead(e) == n && E_samehead &&
UNSUPPORTED("d38ofiemhq37ykyauh9wync84"); // 	        (id = agxget(e, E_samehead))[0])
UNSUPPORTED("18y7dy98psh7ultlx0jugsfu2"); // 		n_samehead = sameedge(samehead, n_samehead, n, e, id);
UNSUPPORTED("5snv0fee5roi91irdwv8x51xi"); // 	    else if (agtail(e) == n && E_sametail &&
UNSUPPORTED("8xvjbvzldkn1yksprzfexgsjs"); // 	        (id = agxget(e, E_sametail))[0])
UNSUPPORTED("cdn1fgq1pke9ekyar2b4r6e91"); // 		n_sametail = sameedge(sametail, n_sametail, n, e, id);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c96gtgvp5uw8ktp389l2s9l4u"); // 	for (i = 0; i < n_samehead; i++) {
UNSUPPORTED("b2s9feywib1q9pxw4h31yz6dk"); // 	    if (samehead[i].l.size > 1)
UNSUPPORTED("1xvsmwfz2hihjki8tsqiaa1g8"); // 		sameport(n, &samehead[i].l, samehead[i].arr_len);
UNSUPPORTED("cpzvkkchr60qet357b9gg1e5q"); // 	    free_list(samehead[i].l);
UNSUPPORTED("6cnsuklvjftdyhzat6za4qggi"); // 	    /* I sure hope I don't need to free the char* id */
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("9ktz8j6cseb5w7jkfhrj5r19t"); // 	for (i = 0; i < n_sametail; i++) {
UNSUPPORTED("5vcqm1irqrqcg4f6ldrqkikq8"); // 	    if (sametail[i].l.size > 1)
UNSUPPORTED("dcjzqns8bm1o766uqi8dy72qf"); // 		sameport(n, &sametail[i].l, sametail[i].arr_len);
UNSUPPORTED("13a7frulpyheo0h4ajbfja7ph"); // 	    free_list(sametail[i].l);
UNSUPPORTED("6cnsuklvjftdyhzat6za4qggi"); // 	    /* I sure hope I don't need to free the char* id */
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
} finally {
LEAVING("eu2yvovb9xx4rzic3gllij2bv","dot_sameports");
}
}




//3 e6phoefj4ujntgmpiclbnmliw
// static int sameedge(same_t * same, int n_same, node_t * n, edge_t * e, char *id) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/sameport.c", name="sameedge", key="e6phoefj4ujntgmpiclbnmliw", definition="static int sameedge(same_t * same, int n_same, node_t * n, edge_t * e, char *id)")
public static Object sameedge(Object... arg) {
UNSUPPORTED("4pviw1spiyvhdz8yvl4ho6qkx"); // static int sameedge(same_t * same, int n_same, node_t * n, edge_t * e, char *id)
UNSUPPORTED("bz7wamuuo5855unp564487v13"); // /* register E in the SAME structure of N under ID. Uses static int N_SAME */
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("ddmbnep3k060w2rgslisky5vw"); //     int i, sflag, eflag, flag;
UNSUPPORTED("4yhtj0buzrukmv0lwrz77s5oa"); //     for (i = 0; i < n_same; i++)
UNSUPPORTED("6htdinsa3h8aamp1e6pvd6ig5"); // 	if ((*(same[i].id)==*(id)&&!strcmp(same[i].id,id))) {
UNSUPPORTED("bqrcn2qjykhnd6fuwneng85h"); // 	    elist_append(e, same[i].l);
UNSUPPORTED("g5anfkdhikcxt42clvstq6hm"); // 	    goto set_arrow;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8ac5s7v71vxuj2d2r4t989b1c"); //     if (++n_same > 5) {
UNSUPPORTED("c29filv0jivh50blpbuqjk5ib"); // 	n_same--;
UNSUPPORTED("3uf43hfdusyzm1vp3dq12qu29"); // 	agerr(AGERR, "too many (> %d) same{head,tail} groups for node %s\n",
UNSUPPORTED("ciwytw61x3j4anugbarxaa7m"); // 	      5, agnameof(n));
UNSUPPORTED("3lrnrroeosc48ilq0azgtzyna"); // 	return n_same;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("36d7os443e3k5gf7g7zvi3vfs"); //     alloc_elist(1, same[i].l);
UNSUPPORTED("3s0n702bprlxue4xtghqv3nad"); //     elist_fastapp(e, same[i].l);
UNSUPPORTED("cwxcw0cnsxpwkd7l94pmw1dfg"); //     same[i].id = id;
UNSUPPORTED("4y2b9aw2a57zud1ncpiw2fihn"); //     same[i].n_arr = 0;
UNSUPPORTED("2lemlhm6qdqemg83e6xwyzd01"); //     same[i].arr_len = 0;
UNSUPPORTED("3k68ve2sycumnr4ncfzymgyli"); //   set_arrow:
UNSUPPORTED("4028w60fcyzgcb6qh4kf8090j"); //     arrow_flags(e, &sflag, &eflag);
UNSUPPORTED("1rkfoax4tin2ccbtpc8w1tnpv"); //     if ((flag = aghead(e) == n ? eflag : sflag))
UNSUPPORTED("bhh3lvo0knve8fiod7js8o8oy"); // 	same[i].arr_len =
UNSUPPORTED("b7yh5042d5o8u6iso9bm39glf"); // 	    /* only consider arrows if there's exactly one arrow */
UNSUPPORTED("5r1jxkep2wvpcpjz1e6n0dxo7"); // 	    (++same[i].n_arr == 1) ? arrow_length(e, flag) : 0;
UNSUPPORTED("59a2z18u4tje6r407a6psdqy8"); //     return n_same;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2mnqx0mihpyo94rckzyvqd3ha
// static void sameport(node_t * u, elist * l, double arr_len) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/sameport.c", name="sameport", key="2mnqx0mihpyo94rckzyvqd3ha", definition="static void sameport(node_t * u, elist * l, double arr_len)")
public static Object sameport(Object... arg) {
UNSUPPORTED("5h4o73bwixguohs97owrtr8ef"); // static void sameport(node_t * u, elist * l, double arr_len)
UNSUPPORTED("d5nznmmgnjszlfjdd61kps3jx"); // /* make all edges in L share the same port on U. The port is placed on the
UNSUPPORTED("bo9mbi1sf1ycc8zr8zucow3sz"); //    node boundary and the average angle between the edges. FIXME: this assumes
UNSUPPORTED("4jpc10q4iiglyfgqc4t0rvtce"); //    naively that the edges are straight lines, which is wrong if they are long.
UNSUPPORTED("wh2ex8xlk21eu1y33pacj3v2"); //    In that case something like concentration could be done.
UNSUPPORTED("4c9tqu2byiozzo2mzc1fbvda9"); //    An arr_port is also computed that's ARR_LEN away from the node boundary.
UNSUPPORTED("atdcc5pbds8mqzssaq6v0r6rw"); //    It's used for edges that don't themselves have an arrow.
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("aigogf44ojtcesuy4xs7inqbn"); //     node_t *v;
UNSUPPORTED("9b48a157azcrz2ihzqehhpsvs"); //     edge_t *e, *f;
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("e39yybz8f8dk5960upp4t7e85"); //     double x = 0, y = 0, x1, y1, x2, y2, r;
UNSUPPORTED("cmzlbdlia0ky3ulmkmhw731vo"); //     port prt;
UNSUPPORTED("lnwbe9uftcv8uw5w72tyaim6"); //     int sflag, eflag;
UNSUPPORTED("3s75qjxnr416bs4xwntk5wjey"); //     /* Compute the direction vector (x,y) of the average direction. We compute
UNSUPPORTED("168uvy6red5coj19cfwdg74w4"); //        with direction vectors instead of angles because else we have to first
UNSUPPORTED("byd7rdw7ogomu0h8xa3cngptx"); //        bring the angles within PI of each other. av(a,b)!=av(a,b+2*PI) */
UNSUPPORTED("7qdtxp882tja3q4pjpimsdpz2"); //     for (i = 0; i < l->size; i++) {
UNSUPPORTED("9a2w9ypg4zbrmt9mwxerl9ku9"); // 	e = l->list[i];
UNSUPPORTED("dmcddmsjj52vhbo0p72d20r7x"); // 	if (aghead(e) == u)
UNSUPPORTED("4gg5n60ynsciy3te5bmvsjdu0"); // 	    v = agtail(e);
UNSUPPORTED("9352ql3e58qs4fzapgjfrms2s"); // 	else
UNSUPPORTED("39bh91n8ucstjr8vmtx3ynvcd"); // 	    v = aghead(e);
UNSUPPORTED("3bzvithkkr721ghsi2ljswz41"); // 	x1 = ND_coord(v).x - ND_coord(u).x;
UNSUPPORTED("2b884aalfpupcphtkwlw7fh1p"); // 	y1 = ND_coord(v).y - ND_coord(u).y;
UNSUPPORTED("2bo8vt6om92qnyd8ajsur7839"); // 	r = hypot(x1, y1);
UNSUPPORTED("8ldeax6x9cgrmbfybuxbl5n3o"); // 	x += x1 / r;
UNSUPPORTED("lvaxvfnj6g12uz2apxvc32bt"); // 	y += y1 / r;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("a1mnn3lz9vym0mycdnjtnqt50"); //     r = hypot(x, y);
UNSUPPORTED("en33l6y6hjb8cbouawh4qgny1"); //     x /= r;
UNSUPPORTED("7ogy0bdt0ghq60m7dyzb48vku"); //     y /= r;
UNSUPPORTED("1zwmby4z9dnptpyvedi7zqx1y"); //     /* (x1,y1),(x2,y2) is a segment that must cross the node boundary */
UNSUPPORTED("aezmu3kg51jsv6vuj8yl2vgx0"); //     x1 = ND_coord(u).x;
UNSUPPORTED("b9lds1fhngov0656kxk71v6o"); //     y1 = ND_coord(u).y;	/* center of node */
UNSUPPORTED("a47id67bq23txqyol6w89ohg8"); //     r = MAX(ND_lw(u) + ND_rw(u), ND_ht(u) + GD_ranksep(agraphof(u)));	/* far away */
UNSUPPORTED("632ifec281b8hg0vql6w66fd0"); //     x2 = x * r + ND_coord(u).x;
UNSUPPORTED("tpm4a8o4c87dctdvop70l3gg"); //     y2 = y * r + ND_coord(u).y;
UNSUPPORTED("9axcwk1yl7elzq5ch7zzsg2b"); //     {				/* now move (x1,y1) to the node boundary */
UNSUPPORTED("6qp76u7xiuyi81ocft3zna7rw"); // 	pointf curve[4];		/* bezier control points for a straight line */
UNSUPPORTED("d2banip9m2nhni4tcg0ub95sb"); // 	curve[0].x = x1;
UNSUPPORTED("jy2q28s2gzpbigtocfoo6cy6"); // 	curve[0].y = y1;
UNSUPPORTED("90jm80vushtpjetfmrlks5tr6"); // 	curve[1].x = (2 * x1 + x2) / 3;
UNSUPPORTED("ah6xwuv1rqq311cmwhnrs4p7g"); // 	curve[1].y = (2 * y1 + y2) / 3;
UNSUPPORTED("5nzdtvblt406q4j887woceaso"); // 	curve[2].x = (2 * x2 + x1) / 3;
UNSUPPORTED("8ccq8nqc6cwcgqyrls16i5n1x"); // 	curve[2].y = (2 * y2 + y1) / 3;
UNSUPPORTED("9e73i3zoi98jcem56ovsw95mw"); // 	curve[3].x = x2;
UNSUPPORTED("bt1idr0p5w37ehw0ca5qvh2d0"); // 	curve[3].y = y2;
UNSUPPORTED("4hvdnsqv9gvg89n449ivew89w"); // 	shape_clip(u, curve);
UNSUPPORTED("e8zqbvvz0hnmxynqrsi4tq6z9"); // 	x1 = curve[0].x - ND_coord(u).x;
UNSUPPORTED("10uhdsyhabakyucrrlkpxmy39"); // 	y1 = curve[0].y - ND_coord(u).y;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ftxzqcd66xy9t3i1shc08phg"); //     /* compute PORT on the boundary */
UNSUPPORTED("egqrua11zla4ilqnv8fe2rqa9"); //     prt.p.x = ROUND(x1);
UNSUPPORTED("3j43h2ta90714rhr89dxd9bly"); //     prt.p.y = ROUND(y1);
UNSUPPORTED("72f3ncaut57fflmrrrd7g625i"); //     prt.bp = 0;
UNSUPPORTED("86dw0xu09q0vf963rwyhthsga"); //     prt.order =
UNSUPPORTED("bi7e99txixk5vn16uz1ewze60"); // 	(256 * (ND_lw(u) + prt.p.x)) / (ND_lw(u) + ND_rw(u));
UNSUPPORTED("2ssajop92yd2a8y22o22ea36z"); //     prt.constrained = 0;
UNSUPPORTED("6oy9nbi9ensh5cuoda16glfkk"); //     prt.defined = NOT(0);
UNSUPPORTED("9vfrhc8s3bav5vsioug70ec8a"); //     prt.clip = 0;
UNSUPPORTED("58u5npq8vw06285kpx39zg9us"); //     prt.dyna = 0;
UNSUPPORTED("26hzjlrn2f97g04rs41bxd6cp"); //     prt.theta = 0;
UNSUPPORTED("6r9ivoxmq49o3gv1yto4zyvi3"); //     prt.side = 0;
UNSUPPORTED("aujriwmmb49o2fxrmsjoedap6"); //     prt.name = NULL;
UNSUPPORTED("3ff91qop4adzc4f4h1lnljqyp"); //     /* assign one of the ports to every edge */
UNSUPPORTED("7qdtxp882tja3q4pjpimsdpz2"); //     for (i = 0; i < l->size; i++) {
UNSUPPORTED("9a2w9ypg4zbrmt9mwxerl9ku9"); // 	e = l->list[i];
UNSUPPORTED("84n057olv326z2v8k45silocb"); // 	arrow_flags(e, &sflag, &eflag);
UNSUPPORTED("2csv6mfvww0031xz126km61c5"); // 	for (; e; e = ED_to_virt(e)) {	/* assign to all virt edges of e */
UNSUPPORTED("9rrwjg2l48y4n9w7ymrr9udrs"); // 	    for (f = e; f;
UNSUPPORTED("cd9trmrmocvmp9gcd5yhpi8j2"); // 		 f = ED_edge_type(f) == 1 &&
UNSUPPORTED("c609sm2glgudtov2qxajroomq"); // 		 ND_node_type(aghead(f)) == 1 &&
UNSUPPORTED("ez0iln0wthfexsk2addlvf968"); // 		 ND_out(aghead(f)).size == 1 ?
UNSUPPORTED("3c7kng7zq5tuk7q0g4368f83a"); // 		 ND_out(aghead(f)).list[0] : NULL) {
UNSUPPORTED("au8chupq2urgaefasiz9q9p4"); // 		if (aghead(f) == u)
UNSUPPORTED("9n4w8egcjmjwmkgptavq9x8on"); // 		    ED_head_port(f) = prt;
UNSUPPORTED("ckzw343313p1917g5yol8mget"); // 		if (agtail(f) == u)
UNSUPPORTED("es5btobfx5kd4ziscx7ym4kf7"); // 		    ED_tail_port(f) = prt;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("9rrwjg2l48y4n9w7ymrr9udrs"); // 	    for (f = e; f;
UNSUPPORTED("cd9trmrmocvmp9gcd5yhpi8j2"); // 		 f = ED_edge_type(f) == 1 &&
UNSUPPORTED("9po6nu7kgaeigs2afm08whv2o"); // 		 ND_node_type(agtail(f)) == 1 &&
UNSUPPORTED("49xjryc5nmnom413y2dy0v7gh"); // 		 ND_in(agtail(f)).size == 1 ?
UNSUPPORTED("91kaqt4bbz94s6de4uf9wept7"); // 		 ND_in(agtail(f)).list[0] : NULL) {
UNSUPPORTED("au8chupq2urgaefasiz9q9p4"); // 		if (aghead(f) == u)
UNSUPPORTED("9n4w8egcjmjwmkgptavq9x8on"); // 		    ED_head_port(f) = prt;
UNSUPPORTED("ckzw343313p1917g5yol8mget"); // 		if (agtail(f) == u)
UNSUPPORTED("es5btobfx5kd4ziscx7ym4kf7"); // 		    ED_tail_port(f) = prt;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("d7reofoel6ngjj7zza32cdi0w"); //     ND_has_port(u) = NOT(0);	/* kinda pointless, because mincross is already done */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
