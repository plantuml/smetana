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
import static smetana.core.Macro.UNSUPPORTED;

import gen.annotation.Original;
import gen.annotation.Unused;
import smetana.core.jmp_buf;

public class conc__c {


//1 540u5gu9i0x1wzoxqqx5n2vwp
// static jmp_buf jbuf
private static jmp_buf jbuf = new jmp_buf();



//3 9ugj5cxjwh6izs7qwoeplieyq
// static void mergevirtual(graph_t * g, int r, int lpos, int rpos, int dir) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/conc.c", name="mergevirtual", key="9ugj5cxjwh6izs7qwoeplieyq", definition="static void mergevirtual(graph_t * g, int r, int lpos, int rpos, int dir)")
public static Object mergevirtual(Object... arg) {
UNSUPPORTED("7fykjo0tsdbiv0zeb6x3fb8fs"); // static void mergevirtual(graph_t * g, int r, int lpos, int rpos, int dir)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("3omv4g8dibh1pqrvt46eo9gvq"); //     int i, k;
UNSUPPORTED("amyi14irz6dbz0367id35hvp"); //     node_t *left, *right;
UNSUPPORTED("8f8h355l1495yy9dbaz0it2in"); //     edge_t *e, *f, *e0;
UNSUPPORTED("231cg7wmyzy38x2wt2fo5w4mj"); //     left = GD_rank(g)[r].v[lpos];
UNSUPPORTED("ell7qlxmonsekwusp8xopfdfu"); //     /* merge all right nodes into the leftmost one */
UNSUPPORTED("1eeld04u92ygccgaquiq6xaex"); //     for (i = lpos + 1; i <= rpos; i++) {
UNSUPPORTED("5elwzk0mnuzvd2hm4hjqerr0f"); // 	right = GD_rank(g)[r].v[i];
UNSUPPORTED("c1uckn7ho04t7ub7xklkxju8h"); // 	if (dir == 1) {
UNSUPPORTED("b0aboa5nfb7ujemy7qx50riyo"); // 	    while ((e = ND_out(right).list[0])) {
UNSUPPORTED("61h4dtrrxp3gqi4qq4fa84dj6"); // 		for (k = 0; (f = ND_out(left).list[k]); k++)
UNSUPPORTED("e0g1j10s0bixkrbon6u0yv9c6"); // 		    if (aghead(f) == aghead(e))
UNSUPPORTED("a5064jph9xpw67dcun2my4mcm"); // 			break;
UNSUPPORTED("34init75thgijzfyzza21moxe"); // 		if (f == NULL)
UNSUPPORTED("bevz1zn0blsflvx6jkk50rba9"); // 		    f = virtual_edge(left, aghead(e), e);
UNSUPPORTED("asb45d5rqv8it74v7tne8f2fg"); // 		while ((e0 = ND_in(right).list[0])) {
UNSUPPORTED("cuttljjerosdc8dabm2bnnyb8"); // 		    merge_oneway(e0, f);
UNSUPPORTED("7v5ie1ooevp21zluuewlboyb5"); // 		    /*ED_weight(f) += ED_weight(e0); */
UNSUPPORTED("5s7a1scru7071fh3chrychja8"); // 		    delete_fast_edge(e0);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("4xzroqevvsjt307vvx10f8atw"); // 		delete_fast_edge(e);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("a9byy1rucxlzdlxewp2rv7gqq"); // 	    while ((e = ND_in(right).list[0])) {
UNSUPPORTED("c7omxpe29tnl9ydgup95clcci"); // 		for (k = 0; (f = ND_in(left).list[k]); k++)
UNSUPPORTED("a8u5bsqed458j870nosh64yic"); // 		    if (agtail(f) == agtail(e))
UNSUPPORTED("a5064jph9xpw67dcun2my4mcm"); // 			break;
UNSUPPORTED("34init75thgijzfyzza21moxe"); // 		if (f == NULL)
UNSUPPORTED("dbqismmahqza8fnkjhntz4ll0"); // 		    f = virtual_edge(agtail(e), left, e);
UNSUPPORTED("eukpmnw48odadjb55ie78fit9"); // 		while ((e0 = ND_out(right).list[0])) {
UNSUPPORTED("cuttljjerosdc8dabm2bnnyb8"); // 		    merge_oneway(e0, f);
UNSUPPORTED("5s7a1scru7071fh3chrychja8"); // 		    delete_fast_edge(e0);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("4xzroqevvsjt307vvx10f8atw"); // 		delete_fast_edge(e);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("20831ggpnh7lvyeu87hwsm0t3"); // 	assert(ND_in(right).size + ND_out(right).size == 0);
UNSUPPORTED("ahkylw437651e5mf9138vl35w"); // 	delete_fast_node(g, right);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("4yunnb5j9hoe6bcsy79b69fh0"); //     k = lpos + 1;
UNSUPPORTED("1ta71a6pw0aspmpknbt3wjj4k"); //     i = rpos + 1;
UNSUPPORTED("6vm80zqnn9yxelf6y0p8pdhlh"); //     while (i < GD_rank(g)[r].n) {
UNSUPPORTED("aour3qu5mlw9cykjikxt0fxcy"); // 	node_t *n;
UNSUPPORTED("2z4aexzipvp6690gajlfsw9ub"); // 	n = GD_rank(g)[r].v[k] = GD_rank(g)[r].v[i];
UNSUPPORTED("98h1qvrthbfxdz7717i3e1ylh"); // 	ND_order(n) = k;
UNSUPPORTED("9zq7xtwq5cysffia17vtbbt9u"); // 	k++;
UNSUPPORTED("chd2f5z6rt19lbaye25ej7q6j"); // 	i++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("85og729c3c58hh8wdsc8uec8l"); //     GD_rank(g)[r].n = k;
UNSUPPORTED("d8ajai913hx6i4otnoso8kawv"); //     GD_rank(g)[r].v[k] = NULL;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c20jfo46p56bjbachxehha9pu
// static void infuse(graph_t * g, node_t * n) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/conc.c", name="infuse", key="c20jfo46p56bjbachxehha9pu", definition="static void infuse(graph_t * g, node_t * n)")
public static Object infuse(Object... arg) {
UNSUPPORTED("etmqgz9znjdg1p7di2fe6kis4"); // static void infuse(graph_t * g, node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("9roij9rixfrdr3vio8wvn6cym"); //     node_t *lead;
UNSUPPORTED("1dhtnolphtqb1vhzddsjs4997"); //     lead = GD_rankleader(g)[ND_rank(n)];
UNSUPPORTED("7sbrmrdrc6qm86jwzs2p1q0bv"); //     if ((lead == NULL) || (ND_order(lead) > ND_order(n)))
UNSUPPORTED("4kboqcebkf36wvklvhc0smxyf"); // 	GD_rankleader(g)[ND_rank(n)] = n;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e8chm1nms49vyf1mp9zdq7e3n
// static void rebuild_vlists(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/conc.c", name="rebuild_vlists", key="e8chm1nms49vyf1mp9zdq7e3n", definition="static void rebuild_vlists(graph_t * g)")
public static Object rebuild_vlists(Object... arg) {
UNSUPPORTED("8lxgqgoebpr6pqqvqimb2nold"); // static void rebuild_vlists(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("c566lguiyozynv7spc9xx8agv"); //     int c, i, r, maxi;
UNSUPPORTED("augenu6r3rx501311lht9q7qr"); //     node_t *n, *lead;
UNSUPPORTED("3bqpdb6f6p2qw9s76g6txvvro"); //     edge_t *e, *rep;
UNSUPPORTED("br5jnq2zjxxbz2mw0z8ns5uug"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++)
UNSUPPORTED("2rpy1wfe6lhmak6ce4v24v4ao"); // 	GD_rankleader(g)[r] = NULL;
UNSUPPORTED("4frgznaid5m5mdte931ti7cw"); //     dot_scan_ranks(g);
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("7zlur6lceb4yawe9tb9amgq9s"); // 	infuse(g, n);
UNSUPPORTED("e20lm4qtccvgsfq5fzjv6sjyl"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("7uff9xbfc6s0idd1vxtjm2qth"); // 	    for (rep = e; ED_to_virt(rep); rep = ED_to_virt(rep));
UNSUPPORTED("4oqbk654pzi7973xynf59fntp"); // 	    while (ND_rank(aghead(rep)) < ND_rank(aghead(e))) {
UNSUPPORTED("87e8ucrmzsn4x3vikrp4zqx96"); // 		infuse(g, aghead(rep));
UNSUPPORTED("9l3almai3ugohjo61vxf13yb7"); // 		rep = ND_out(aghead(rep)).list[0];
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("60nab7gyukq3bs8e6dizhbacy"); //     for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
UNSUPPORTED("arvyjg1l9juza75tj23zsykps"); // 	lead = GD_rankleader(g)[r];
UNSUPPORTED("4atymss3ar3wje54szsaa3omf"); // 	if (GD_rank(dot_root(g))[r].v[ND_order(lead)] != lead) {
UNSUPPORTED("b3cixj6rtwwwmjmebo4r2h15k"); // 	    agerr(AGERR, "rebuiltd_vlists: rank lead %s not in order %d of rank %d\n", 
UNSUPPORTED("6udrpqggfjxt0na5cdb0725bn"); // 		agnameof(lead), ND_order(lead), r);
UNSUPPORTED("edg6zn44g1egn9rxfpiizzrjo"); // 	    longjmp(jbuf, 1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("3907i7loyifjuq3p41y45kyhm"); // 	GD_rank(g)[r].v =
UNSUPPORTED("7j4ogkw53pg0iv0mmko48fw0x"); // 	    GD_rank(dot_root(g))[r].v + ND_order((GD_rankleader(g)[r]));
UNSUPPORTED("2c6wxmjs9ytmjutd79l3vt4gl"); // 	maxi = -1;
UNSUPPORTED("6eix918gmfs16624x6omusuhm"); // 	for (i = 0; i < GD_rank(g)[r].n; i++) {
UNSUPPORTED("34a7o67ylktm1es8bkuaeejk2"); // 	    if ((n = GD_rank(g)[r].v[i]) == NULL)
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("e0gk7m0zrsus94mtf86d91p04"); // 	    if (ND_node_type(n) == 0) {
UNSUPPORTED("d13494tcz4gbtml8c1ev3ktzb"); // 		if (agcontains(g, n))
UNSUPPORTED("80spg5b3li0mhxyw957sp2n7q"); // 		    maxi = i;
UNSUPPORTED("7e1uy5mzei37p66t8jp01r3mk"); // 		else
UNSUPPORTED("czyohktf9bkx4udfqhx42f4lu"); // 		    break;
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("3gm29k6z4aks8v0k1r7qvxvlt"); // 		edge_t *e;
UNSUPPORTED("42bmttyjay3sng4c3d0tsvkn9"); // 		for (e = ND_in(n).list[0]; e && ED_to_orig(e);
UNSUPPORTED("148t8jlrp8lwlu4pyvlslf49l"); // 		     e = ED_to_orig(e));
UNSUPPORTED("5n3hyea9ita57alojbawbcurz"); // 		if (e && (agcontains(g, agtail(e)))
UNSUPPORTED("2u3pptvaudhj3kaydu0xn0c9x"); // 		    && agcontains(g, aghead(e)))
UNSUPPORTED("80spg5b3li0mhxyw957sp2n7q"); // 		    maxi = i;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("csorvv6yhyohqnsvhazkk6eje"); // 	if (maxi == -1)
UNSUPPORTED("eq3mmft8bst07qw88wjzgvoet"); // 	    agerr(AGWARN, "degenerate concentrated rank %s,%d\n", agnameof(g),
UNSUPPORTED("b6bf10m2f2pvxgkfcax559640"); // 		  r);
UNSUPPORTED("10l3x6nke8pra4fu5ysnu6j08"); // 	GD_rank(g)[r].n = maxi + 1;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7z5fb6iyowsosn1hiz7opeoc6"); //     for (c = 1; c <= GD_n_cluster(g); c++)
UNSUPPORTED("1d7lqtmagp5mwcbbkf4xawdog"); // 	rebuild_vlists(GD_clust(g)[c]);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3mzzkxpsezmtvlbzshvr46b8m
// void dot_concentrate(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/conc.c", name="dot_concentrate", key="3mzzkxpsezmtvlbzshvr46b8m", definition="void dot_concentrate(graph_t * g)")
public static Object dot_concentrate(Object... arg) {
UNSUPPORTED("4h7xkpw4zpae6ztth270w22gd"); // void dot_concentrate(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("62hcnpegd6vvkgtfo3a833aq9"); //     int c, r, leftpos, rightpos;
UNSUPPORTED("amyi14irz6dbz0367id35hvp"); //     node_t *left, *right;
UNSUPPORTED("1exryvusfp7fkh0rn8bxcz96g"); //     if (GD_maxrank(g) - GD_minrank(g) <= 1)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("1o57fdj7j63samf9jysgvpqnq"); //     /* this is the downward looking pass. r is a candidate rank. */
UNSUPPORTED("ca08a4ijjaxoo89carapxu5ur"); //     for (r = 1; GD_rank(g)[r + 1].n; r++) {
UNSUPPORTED("8elk0ekrvmk0yt6bmbwub0epc"); // 	for (leftpos = 0; leftpos < GD_rank(g)[r].n; leftpos++) {
UNSUPPORTED("ela65u1ff5sc7nw7eq6hioji0"); // 	    left = GD_rank(g)[r].v[leftpos];
UNSUPPORTED("7yq5j8b980yc5rz1e4lkwgmth"); // 	    if (downcandidate(left) == 0)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("exizgsc0bwm37dxc6j6op74lz"); // 	    for (rightpos = leftpos + 1; rightpos < GD_rank(g)[r].n;
UNSUPPORTED("5a4wx0786piefhj7q3m241wof"); // 		 rightpos++) {
UNSUPPORTED("3jh1iupmf6freiri4v7zbt87k"); // 		right = GD_rank(g)[r].v[rightpos];
UNSUPPORTED("7ap3iy5ysmyd0x869id0jyedv"); // 		if (bothdowncandidates(left, right) == 0)
UNSUPPORTED("czyohktf9bkx4udfqhx42f4lu"); // 		    break;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("3q4uw7garqdhjalzpk1bivu8s"); // 	    if (rightpos - leftpos > 1)
UNSUPPORTED("4o5cptipygbr3qu2m6rkk4qwg"); // 		mergevirtual(g, r, leftpos, rightpos - 1, 1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cakeuerd3mfjfwy396sci21tn"); //     /* this is the corresponding upward pass */
UNSUPPORTED("9cqq87ffcq47f55xlupeeuo6u"); //     while (r > 0) {
UNSUPPORTED("8elk0ekrvmk0yt6bmbwub0epc"); // 	for (leftpos = 0; leftpos < GD_rank(g)[r].n; leftpos++) {
UNSUPPORTED("ela65u1ff5sc7nw7eq6hioji0"); // 	    left = GD_rank(g)[r].v[leftpos];
UNSUPPORTED("dgbio6b5e3ja3yul0q4rl5qqn"); // 	    if (upcandidate(left) == 0)
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("exizgsc0bwm37dxc6j6op74lz"); // 	    for (rightpos = leftpos + 1; rightpos < GD_rank(g)[r].n;
UNSUPPORTED("5a4wx0786piefhj7q3m241wof"); // 		 rightpos++) {
UNSUPPORTED("3jh1iupmf6freiri4v7zbt87k"); // 		right = GD_rank(g)[r].v[rightpos];
UNSUPPORTED("6j41xobwrcrep12b6hhs39r8z"); // 		if (bothupcandidates(left, right) == 0)
UNSUPPORTED("czyohktf9bkx4udfqhx42f4lu"); // 		    break;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("3q4uw7garqdhjalzpk1bivu8s"); // 	    if (rightpos - leftpos > 1)
UNSUPPORTED("c3v2wops656i36vmsec5ezxk0"); // 		mergevirtual(g, r, leftpos, rightpos - 1, 0);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("8a1wsnjguqfvz8vfx6erejakp"); // 	r--;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ci9r8sj8tbc6yer5c8cebb0cm"); //     if (setjmp(jbuf)) {
UNSUPPORTED("ej9htgkxfq6bintcw04c6svwu"); // 	agerr(AGPREV, "concentrate=true may not work correctly.\n");
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7z5fb6iyowsosn1hiz7opeoc6"); //     for (c = 1; c <= GD_n_cluster(g); c++)
UNSUPPORTED("1d7lqtmagp5mwcbbkf4xawdog"); // 	rebuild_vlists(GD_clust(g)[c]);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
