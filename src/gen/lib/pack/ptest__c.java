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
package gen.lib.pack;
import static smetana.core.Macro.UNSUPPORTED;

import gen.annotation.Original;
import gen.annotation.Unused;

public class ptest__c {

//3 73e82wwqdxeij8zonccymd6kz
// static void usage(int v) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="usage", key="73e82wwqdxeij8zonccymd6kz", definition="static void usage(int v)")
public static Object usage(Object... arg) {
UNSUPPORTED("94mouoc9v3rqowaduimbdrlsg"); // static void usage(int v)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dezf59tqaazw376bwzeh0lnk"); //     printf(useString);
UNSUPPORTED("awsu87poqc0o7ac0x3zri08x2"); //     exit(v);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 efl73lc0qt3y2dwkp2bq3qs7q
// static void init(int argc, char *argv[]) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="init", key="efl73lc0qt3y2dwkp2bq3qs7q", definition="static void init(int argc, char *argv[])")
public static Object init(Object... arg) {
UNSUPPORTED("bgxu2kkx7u9qfq81tb3oefdcs"); // static void init(int argc, char *argv[])
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("53xzwretgdbd0atozc0w6hagb"); //     int c;
UNSUPPORTED("4qgmh8k7p00n85stclc5uyuv1"); //     aginit();
UNSUPPORTED("1niqqfd7us06n0wzaiiz3u5xg"); //     while ((c = getopt(argc, argv, ":escvm:?")) != -1) {
UNSUPPORTED("7rk995hpmaqbbasmi40mqg0yw"); // 	switch (c) {
UNSUPPORTED("2fzjr952o6hmcz3ad5arl2n8d"); // 	case 'e':
UNSUPPORTED("612z1fkxvsn3pr6uz8smtwwg6"); // 	    doEdges = 0;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("f3lyz2cejs6yn5fyckhn7ba1"); // 	case 'c':
UNSUPPORTED("coi2qrxdv2l71tb75401s90cn"); // 	    doComps = 1;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("953l7gyh3b52lc5n9fbhtxhbg"); // 	case 'm':
UNSUPPORTED("agwyr30ptmkberfxzlr2qb4sm"); // 	    margin = atoi(optarg);
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("b4quboi30n0afnbpgm9chdttx"); // 	case 's':
UNSUPPORTED("a2kcyv0orvfio4god7x1ra1gc"); // 	    single = 1;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("318vlfmcdz9no6i45k86aygon"); // 	case 'v':
UNSUPPORTED("52jus61ki82kyvoho03bg8yu8"); // 	    verbose = 1;
UNSUPPORTED("z08wni1aiuv5b8ommxtq10kj"); // 	    Verbose = 1;
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("d0u2ka51n27um0avxdj14adrh"); // 	case '?':
UNSUPPORTED("6ongvn9s4rb5sz2f3jrzfcj0m"); // 	    if (optopt == '?')
UNSUPPORTED("46bu3s4vi4qapnhhl79s89q2f"); // 		usage(0);
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("18zn34qcs4vsdhhh831gn9vc9"); // 		fprintf(stderr,
UNSUPPORTED("cqx5xtn6ibatrlhvobfqyy4sj"); // 			"ptest: option -%c unrecognized - ignored\n", c);
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("bza5bo54n74fk73l7h2zw3sn2"); //     argv += optind;
UNSUPPORTED("2z9v9pfcshjw42gkhviv8qmf8"); //     argc -= optind;
UNSUPPORTED("euz202o13jvson684m35br400"); //     if (argc) {
UNSUPPORTED("a6hax0v25w382s8uhktk1z3ac"); // 	Files = argv;
UNSUPPORTED("9j2gbktfok4tc5txw0oj203eb"); // 	nFiles = argc;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6ow5r7ch1so5cayfbyf9crc5p
// static int numFields(char *pos) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="numFields", key="6ow5r7ch1so5cayfbyf9crc5p", definition="static int numFields(char *pos)")
public static Object numFields(Object... arg) {
UNSUPPORTED("29ky16cycv6cs96zmpduu1bsp"); // static int numFields(char *pos)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("behjm5bjsenezpg3f7cncvteu"); //     int cnt = 0;
UNSUPPORTED("wrvu9u7a8j6i6y6552zncxfk"); //     char c;
UNSUPPORTED("1b9np136i2dme8ejhydy0dhlv"); //     while (isspace(*pos))
UNSUPPORTED("e30zd4or99122hlq3vt45sef"); // 	pos++;
UNSUPPORTED("7dpyo20wi5esbmcan08qtztz7"); //     while (*pos) {
UNSUPPORTED("1szm63athnlkprt3pv29pjc6z"); // 	cnt++;
UNSUPPORTED("5piqmvc132ob5y49h6v7bkeof"); // 	while ((c = *pos) && !isspace(c))
UNSUPPORTED("n5o9yha6va5mqug8xmgxtum9"); // 	    pos++;		/* skip token */
UNSUPPORTED("4n3nq7ssq6ovrj330hssbhwz9"); // 	while (isspace(*pos))
UNSUPPORTED("27349aw1zezm0lpez1jn3pcw4"); // 	    pos++;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3zkt5kbq3sockq663o3s3ync7"); //     return cnt;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6b85bwuqwmq3ucqcauigm0orn
// static point *user_spline(attrsym_t * symptr, edge_t * e, int *np) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="", key="6b85bwuqwmq3ucqcauigm0orn", definition="static point *user_spline(attrsym_t * symptr, edge_t * e, int *np)")
public static Object user_spline(Object... arg) {
UNSUPPORTED("ewvc2qr116wrkxhg4q77v0uqv"); // static point *user_spline(attrsym_t * symptr, edge_t * e, int *np)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("bvo2it3yepiz2er9rw3uuk47s"); //     char *pos;
UNSUPPORTED("7k2ifbl8vz1is0pf2z1t0o2xf"); //     int i, n, nc;
UNSUPPORTED("a13x213r98q5dm6phmdpj3r2l"); //     point *ps = 0;
UNSUPPORTED("ca6brvq3h4u316zi41fa1e7nl"); //     point *pp;
UNSUPPORTED("4g01jt8p980itgxzog49s8ur3"); //     double x, y;
UNSUPPORTED("5elka0ltgqf61uccerqfkjvvp"); //     if (symptr == NULL)
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("c21yig5e4hykm28ao7kpzwodl"); //     pos = agxget(e, symptr->index);
UNSUPPORTED("7i9zryjmvv454i1r57dlez6kk"); //     if (*pos == '\0')
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("az1jdxaqsdxumqec6q7ctjrh3"); //     n = numFields(pos);
UNSUPPORTED("82fimuwp8ur9yxpbd8c89a1wb"); //     *np = n;
UNSUPPORTED("bvx0cyk5fhwwsm29cbghfhcpj"); //     if (n > 1) {
UNSUPPORTED("9lfsqwngk625slfuwyukwtdpy"); // 	ps = ALLOC(n, 0, point);
UNSUPPORTED("49hki9cvrilnaez8dm0dbbgoq"); // 	pp = ps;
UNSUPPORTED("4x9kp7oo5ln5zpe2bhy2s9oyc"); // 	while (n) {
UNSUPPORTED("ejpj2kxorfrlsluqdege3h70h"); // 	    i = sscanf(pos, "%lf,%lf%n", &x, &y, &nc);
UNSUPPORTED("4mo26m3d7t9gf29k5zgh6d3dp"); // 	    if (i < 2) {
UNSUPPORTED("botxh6letfus33f79p4s19719"); // 		free(ps);
UNSUPPORTED("d31bxxiinmdzudo8yt1laapa1"); // 		ps = 0;
UNSUPPORTED("9ekmvj13iaml5ndszqyxa8eq"); // 		break;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("8cjb49m5i1gwlcbb72l8kieuk"); // 	    pos = pos + nc;
UNSUPPORTED("dn8a13edl8j88azhrkizcbwsx"); // 	    pp->x = (int) x;
UNSUPPORTED("6qrmrrz624ilc14dax4fzkzy"); // 	    pp->y = (int) y;
UNSUPPORTED("4t42c85s64mps71a1sjc7yoey"); // 	    pp++;
UNSUPPORTED("704o6677xgknjexhj6bdlst8x"); // 	    n--;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("b0dfwpxhogdrp9mwkzc8oa9vt"); //     return ps;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5vxza0l0hf6kgjh7hgffhqk1d
// static void initPos(Agraph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="initPos", key="5vxza0l0hf6kgjh7hgffhqk1d", definition="static void initPos(Agraph_t * g)")
public static Object initPos(Object... arg) {
UNSUPPORTED("6wuroti5ljub8qdkqwz84bll8"); // static void initPos(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2jcii9cclu1dijzqekzc175pe"); //     Agnode_t *n;
UNSUPPORTED("36vshotvjkc5iodgg7nq6qa2r"); //     Agedge_t *e;
UNSUPPORTED("evvfote9pox5gpnsuk75gu9zi"); //     double *pvec;
UNSUPPORTED("aexhdud6z2wbwwi73yppp0ynl"); //     char *p;
UNSUPPORTED("3w79hfiet3147pb1ehbe0tltw"); //     point *sp;
UNSUPPORTED("7hps2kejtrotcphg5gymma43b"); //     int pn;
UNSUPPORTED("6717r3gljnzz5j6x8yd64vxmy"); //     attrsym_t *N_pos = (agattr(g,AGNODE,"pos",NULL));
UNSUPPORTED("8s1tvuk5eoddac3tdw3vwm3g6"); //     attrsym_t *E_pos = (agattr(g,AGEDGE,"pos",NULL));
UNSUPPORTED("607cie06087nzjkhdxwkh8t5x"); //     assert(N_pos);
UNSUPPORTED("9pqnws9ww5w3wm6etqvhhmaag"); //     if (!E_pos) {
UNSUPPORTED("b7m2ei650qyfpw37qbnbselef"); // 	if (doEdges)
UNSUPPORTED("1jx8qc7jakb79udi264irb795"); // 	    fprintf(stderr, "Warning: turning off doEdges, graph %s\n",
UNSUPPORTED("52cuafai1d5jpnyygo0jtwp19"); // 		    g->name);
UNSUPPORTED("25yxh6xy9gvks3xlk4ay8ana2"); // 	doEdges = 0;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("2hbtrrffbxr8fodextlckjcte"); // 	pvec = ND_pos(n);
UNSUPPORTED("4mrzu4a737x10k9m629qjvpmx"); // 	p = agxget(n, N_pos->index);
UNSUPPORTED("9fce8t386yx1ohlzh5z3v64uy"); // 	if (p[0] && (sscanf(p, "%lf,%lf", pvec, pvec + 1) == 2)) {
UNSUPPORTED("a8amhiqvlp5s6vz8p4u2amapy"); // 	    int i;
UNSUPPORTED("e2k2y77qbvhl4ttkl82r7skpc"); // 	    for (i = 0; i < NDIM; i++)
UNSUPPORTED("54fe965wvv1n2dqk9v5lqtfe"); // 		pvec[i] = pvec[i] / PSinputscale;
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("apu2a6fysp0sm0oh3eg9sdx3g"); // 	    fprintf(stderr, "could not find pos for node %s in graph %s\n",
UNSUPPORTED("5ii3q9tejxvznaewo80u58jc6"); // 		    n->name, g->name);
UNSUPPORTED("6f1y0d5qfp1r9zpw0r7m6xfb4"); // 	    exit(1);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("a7cnx8vpthir8tg7wq0gmkyfp"); // 	ND_coord_i(n).x = (ROUND((ND_pos(n)[0])*72));
UNSUPPORTED("56q0neer7h6q9r2hlewrmtpac"); // 	ND_coord_i(n).y = (ROUND((ND_pos(n)[1])*72));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3x2r45g8h3r71u5v8lu9etnq6"); //     if (doEdges) {
UNSUPPORTED("attp4bsjqe99xnhi7lr7pszar"); // 	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("7yvyv13me3s32qvq3gfbyt283"); // 	    for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("cas0s66j5xm7zv7rfmut5t5ua"); // 		if ((sp = user_spline(E_pos, e, &pn)) != 0) {
UNSUPPORTED("b1l3m7l581iaaysgzy59rlnqp"); // 		    clip_and_install(e, sp, pn);
UNSUPPORTED("bgz7miqt6x7s9we62suaznam2"); // 		    free(sp);
UNSUPPORTED("a47jqpic91ky93e1ohxv590l5"); // 		} else {
UNSUPPORTED("4gzgwztxcj3c7qtlt3xuwnsq1"); // 		    fprintf(stderr,
UNSUPPORTED("2mti2jcwd7nic33dut8daaxli"); // 			    "Missing edge pos for edge %s - %s in graph %s\n",
UNSUPPORTED("7tw8ugnhfmrhmd69kh0nfu7p2"); // 			    n->name, e->head->name, g->name);
UNSUPPORTED("btkmdyvgs2b3io3tacfuo3ht6"); // 		    exit(1);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 e5z9zrazoioj4tcqyaohcup5l
// static void ptest_nodesize(node_t * n, boolean flip) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="ptest_nodesize", key="e5z9zrazoioj4tcqyaohcup5l", definition="static void ptest_nodesize(node_t * n, boolean flip)")
public static Object ptest_nodesize(Object... arg) {
UNSUPPORTED("a6fr7g8doj4m1has0v8m3gn0v"); // static void ptest_nodesize(node_t * n, boolean flip)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dgezc9nq6515gryb5aoradhlj"); //     int w;
UNSUPPORTED("hcl98itasit8bk43t1a7dksx"); //     w = ND_xsize(n) = (ROUND((ND_width(n))*72));
UNSUPPORTED("clr7qgpaln5v1e8sa81vefxgx"); //     ND_lw(n) = ND_rw(n) = w / 2;
UNSUPPORTED("dxe3mk5x98xnzhulw934sin35"); //     ND_ht(n) = ND_ysize(n) = (ROUND((ND_height(n))*72));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5z906z4eqvn94qwep17t9ecfv
// static void ptest_initNode(node_t * n) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="ptest_initNode", key="5z906z4eqvn94qwep17t9ecfv", definition="static void ptest_initNode(node_t * n)")
public static Object ptest_initNode(Object... arg) {
UNSUPPORTED("74hpo7rawbv1l53gcs8gse89n"); // static void ptest_initNode(node_t * n)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("76nok3eiyr33qf4ecv69ujxn6"); //     char *str;
UNSUPPORTED("4ii64hrv86n2irvf71lpjlait"); //     ND_width(n) =
UNSUPPORTED("be5qy7slnjp1ltoih3332j4qk"); // 	late_double(n, N_width, 0.75, 0.01);
UNSUPPORTED("9zjn5j4471it4d3vb5wdfuzlh"); //     ND_height(n) =
UNSUPPORTED("n9gbpj6q00o3ggm4xxil4afm"); // 	late_double(n, N_height, 0.5, 0.01);
UNSUPPORTED("4ia5lmwela2aa00dkga0q3by5"); //     if (N_label == NULL)
UNSUPPORTED("8jmb1jjt8cpml3yo3nh59pkkq"); // 	str = "\\N";
UNSUPPORTED("div10atae09n36x269sl208r1"); //     else
UNSUPPORTED("ania83ea7map6i1xu69ykshav"); // 	str = agxget(n, N_label->index);
UNSUPPORTED("182xxyk6623a24gu3lts9h7i3"); //     str = strdup_and_subst(str, "\\N", n->name);
UNSUPPORTED("2rx8312iagen4kz1a1be428i2"); //     ND_label(n) = make_label(str,
UNSUPPORTED("3umbo59bv54mpje1ar1p3emyg"); // 			     late_double(n, N_fontsize, 14.0,
UNSUPPORTED("6joc02il1cncp1pwbeqwqd6bv"); // 					 1.0), late_nnstring(n,
UNSUPPORTED("eg23z30i9f0bgdsfxqzjr8cm3"); // 								      N_fontname,
UNSUPPORTED("7p3qoqg9tlh094wkumjk0gu1r"); // 								      "Times-Roman"),
UNSUPPORTED("27lxhu1i8goyngm5z5ztzc9se"); // 			     late_nnstring(n, N_fontcolor, "black"),
UNSUPPORTED("a66nrz185x5w9czfz4hxvddaj"); // 			     n->graph);
UNSUPPORTED("cfoyczwylecqlhhb5vmnerwbg"); //     ND_shape(n) = bind_shape(late_nnstring(n, N_shape, "ellipse"));
UNSUPPORTED("2z4f61h2jydnf1wz262734vda"); //     ND_shape(n)->initfn(n);	/* ### need to quantize ? */
UNSUPPORTED("56aecvcbqxgl0e67wrub498ix"); //     ptest_nodesize(n, n->GD_flip(graph));
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 5f35etfq3qbirfsag89nr6382
// static void ptest_initGraph(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="ptest_initGraph", key="5f35etfq3qbirfsag89nr6382", definition="static void ptest_initGraph(graph_t * g)")
public static Object ptest_initGraph(Object... arg) {
UNSUPPORTED("6byfidommpiiaekcfq26jwzzz"); // static void ptest_initGraph(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("94x0mmuhef4re0y05ngcuytf9"); //     /* edge_t *e; */
UNSUPPORTED("16hw9gw0dz2w7mrtba0eoqrdi"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n))
UNSUPPORTED("aakael964bsjn7l22rgdr13zt"); // 	ptest_initNode(n);
UNSUPPORTED("4v614d3uabme2jyn0anuritbb"); // /*
UNSUPPORTED("eh6wqx3d37l7km9kh1gdso2t"); //   for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
UNSUPPORTED("1suh3w1zdcqasuka9dgx4ukgl"); //     for (e = agfstout(g,n); e; e = agnxtout(g,e)) ptest_initEdge(e);
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("bnetqzovnscxile7ao44kc0qd"); // */
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 3y6d5zmybm89vnfzssntfxuga
// static void dumpG(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="dumpG", key="3y6d5zmybm89vnfzssntfxuga", definition="static void dumpG(graph_t * g)")
public static Object dumpG(Object... arg) {
UNSUPPORTED("80as52jwfpla4s14zbrh506cu"); // static void dumpG(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("am98nf596s79mx0jh0eukf2pj"); //     /* point  p; */
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("92hx0hzt0genpiycslyy2fphe"); // 	fprintf(stderr, " node %s \n", n->name);
UNSUPPORTED("e20lm4qtccvgsfq5fzjv6sjyl"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("ddikw3m3fhov54kkj3710v3kh"); // 	    fprintf(stderr, " %s - %s \n", e->tail->name, e->head->name);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 c6p4imduurlyugmp9lakjsrkx
// static void copyPos(Agraph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="copyPos", key="c6p4imduurlyugmp9lakjsrkx", definition="static void copyPos(Agraph_t * g)")
public static Object copyPos(Object... arg) {
UNSUPPORTED("2bnytjwn7g67uh683868e3xl7"); // static void copyPos(Agraph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("2jcii9cclu1dijzqekzc175pe"); //     Agnode_t *n;
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("a7cnx8vpthir8tg7wq0gmkyfp"); // 	ND_coord_i(n).x = (ROUND((ND_pos(n)[0])*72));
UNSUPPORTED("56q0neer7h6q9r2hlewrmtpac"); // 	ND_coord_i(n).y = (ROUND((ND_pos(n)[1])*72));
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 56nlfv4elbzzbch9wiks1pqti
// main(int argc, char *argv[]) 
@Unused
@Original(version="2.38.0", path="lib/pack/ptest.c", name="", key="56nlfv4elbzzbch9wiks1pqti", definition="main(int argc, char *argv[])")
public static Object main(Object... arg) {
UNSUPPORTED("8wkt709xta3burfudbrvdhsdm"); // main(int argc, char *argv[])
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("75makfli697jao0r0h73ksibj"); //     Agraph_t **gs;
UNSUPPORTED("8i0oxshyd0x2idt42lftg3zjx"); //     Agraph_t **ccs;
UNSUPPORTED("1dbyk58q3r4fyfxxo7ovemkpu"); //     Agraph_t *g;
UNSUPPORTED("3l5bdi04ekui6vvrgr3s666fx"); //     Agraph_t *gp;
UNSUPPORTED("66jjdcm9x1i8fc2eq9b1z81d4"); //     char *fname;
UNSUPPORTED("dn2hi0km4q5ldibguffbger1c"); //     FILE *fp;
UNSUPPORTED("6iv4xusq3ncisurzdtlt8lhe9"); //     int cnt;
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("44luxtsxnt651zyc4b8x3r6po"); //     init(argc, argv);
UNSUPPORTED("dmdjgm6j4zsty2ies7uit5831"); //     if (!Files) {
UNSUPPORTED("4issxf2kepoao7ljc3j3jkos8"); // 	fprintf(stderr, "No input files given\n");
UNSUPPORTED("dtw3cma0ziyha0w534bszl0tx"); // 	exit(1);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9zj7hq1iiirxb7wx6osfdutah"); //     PSinputscale = 72;
UNSUPPORTED("2szscn7gy6eg6ghb7zdqj0qwm"); //     if (doComps) {
UNSUPPORTED("46pn2m7yn4pem434vcfqq1gei"); // 	if (verbose)
UNSUPPORTED("dawpetqdqceyrxbb0n5oi20vg"); // 	    fprintf(stderr, "do Comps\n");
UNSUPPORTED("2zdroao5t5zjp7reldctg2hic"); // 	while (fname = *Files++) {
UNSUPPORTED("c2vs68cvzv11vpc3d0vhgn0o6"); // 	    fp = fopen(fname, "r");
UNSUPPORTED("2de0glisr7me97htqp4v4qe2m"); // 	    if (!fp) {
UNSUPPORTED("bruposf45ak9wnammmxs05uq2"); // 		fprintf(stderr, "Could not open %s\n", fname);
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("4vtewfrcwhx9cqnhzzelmnc07"); // 	    g = agread(fp);
UNSUPPORTED("81dgkqb2pfz2cmbpgkwbv8yca"); // 	    fclose(fp);
UNSUPPORTED("9e4rervmy1jguubifdob867qa"); // 	    if (!g) {
UNSUPPORTED("c3k9mm0laol4uhxfovks7vvx4"); // 		fprintf(stderr, "Could not read graph\n");
UNSUPPORTED("6hyelvzskqfqa07xtgjtvg2is"); // 		continue;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("5ok0v4mf41z8mas48m0payhcd"); // 	    printf("%s %d nodes %d edges %sconnected\n",
UNSUPPORTED("e4t4a5rs8mj1rhyqxa3t0bc7r"); // 		   g->name, agnnodes(g), agnedges(g),
UNSUPPORTED("84a4uyu2upwydiyuzql8rnciu"); // 		   (isConnected(g) ? "" : "not "));
UNSUPPORTED("d3glokalvrf1m3vjonhaejamf"); // 	    gs = ccomps(g, &cnt, "abc");
UNSUPPORTED("ivgffft2q5w6sjw0k1jg6o4j"); // 	    for (i = 0; i < cnt; i++) {
UNSUPPORTED("55ej4zekzmpz6h9dwcotkqzvn"); // 		gp = gs[i];
UNSUPPORTED("dyst0rumkq269hhpmrynhel67"); // 		printf(" %s %d nodes %d edges\n", gp->name, agnnodes(gp),
UNSUPPORTED("af8li2e2oidx7nfn42l2lzqc0"); // 		       agnedges(gp));
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("c07up7zvrnu2vhzy6d7zcu94g"); //     } else {
UNSUPPORTED("eob8bvfezsx0hr1brt37a4lyv"); // 	gs = (Agraph_t **)gmalloc((nFiles)*sizeof(Agraph_t *));
UNSUPPORTED("5j7jmlebvv4x0vqasag7ecunu"); // 	cnt = 0;
UNSUPPORTED("ievvgb8tg6613rw4cwuvqtqm"); // 	while (fname = Files[cnt]) {
UNSUPPORTED("c2vs68cvzv11vpc3d0vhgn0o6"); // 	    fp = fopen(fname, "r");
UNSUPPORTED("2de0glisr7me97htqp4v4qe2m"); // 	    if (!fp) {
UNSUPPORTED("bruposf45ak9wnammmxs05uq2"); // 		fprintf(stderr, "Could not open %s\n", fname);
UNSUPPORTED("7ujm7da8xuut83e2rygja0n9d"); // 		exit(1);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("4vtewfrcwhx9cqnhzzelmnc07"); // 	    g = agread(fp);
UNSUPPORTED("81dgkqb2pfz2cmbpgkwbv8yca"); // 	    fclose(fp);
UNSUPPORTED("9e4rervmy1jguubifdob867qa"); // 	    if (!g) {
UNSUPPORTED("c3k9mm0laol4uhxfovks7vvx4"); // 		fprintf(stderr, "Could not read graph\n");
UNSUPPORTED("7ujm7da8xuut83e2rygja0n9d"); // 		exit(1);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("4ttwxmfi4jwb95u2zpmg90qlj"); // 	    if (!single) {
UNSUPPORTED("344ixhk5pj5cgkfitztxg39wq"); // 		graph_init(g);
UNSUPPORTED("dgurzsu7a9v8li0uoqshe04ub"); // 		ptest_initGraph(g);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("4ju9fxktkzm6g6k8jyu66ps6s"); // 	    initPos(g);
UNSUPPORTED("4l3u0654thteocjvzjwfmdfc1"); // 	    /* if (Verbose) dumpG (g); */
UNSUPPORTED("2u2wotplp8k3k2hisg44444mr"); // 	    gs[cnt++] = g;
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("9pza2sgruhfiag9f4hehchd0u"); // 	if (single) {
UNSUPPORTED("7xk90wmd7j06hqt7b7i3eeyfy"); // 	    Agraph_t *root;
UNSUPPORTED("81iug4po5ggethdqgapdw9mez"); // 	    Agnode_t *n;
UNSUPPORTED("8zwiekoyqkvb7nqu0jvrmjubj"); // 	    Agnode_t *np;
UNSUPPORTED("7sxvwdnz5adoqfobhuxe9kpo7"); // 	    Agnode_t *tp;
UNSUPPORTED("6dcxsvi3exhmbtwrpyagifa28"); // 	    Agnode_t *hp;
UNSUPPORTED("7vvr9l0r0k3c179gu9edbannt"); // 	    Agedge_t *e;
UNSUPPORTED("45l8sazink6wfvjc5iv9mbqfv"); // 	    Agedge_t *ep;
UNSUPPORTED("2dsdl1tbecto2tl7rzbajp2ki"); // 	    root = agopen("root", 0);
UNSUPPORTED("2qcacl7cdr2zcme1wtbp5nudb"); // 	    agedgeattr(root, "pos", "");
UNSUPPORTED("ivgffft2q5w6sjw0k1jg6o4j"); // 	    for (i = 0; i < cnt; i++) {
UNSUPPORTED("150kyv7qt24hep1ix7ekbxzhv"); // 		g = gs[i];
UNSUPPORTED("3mq66y5bl1rf1c70443ospyk"); // 		for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("5e6yfzrf4s24izgf8jayt1s43"); // 		    if ((agnode(root,n->name,0))) {
UNSUPPORTED("3iwc3dzplzj2jkbze5cd6zfh9"); // 			fprintf(stderr,
UNSUPPORTED("7hqzc3wtbhvlu2qsdc4y25qk6"); // 				"Error: node %s in graph %d (%s) previously added\n",
UNSUPPORTED("cj5j27wggqfiejzj83ygjjtfd"); // 				n->name, i, Files[i]);
UNSUPPORTED("8197k2c9bktvbqw28fy46jqt"); // 			exit(1);
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("9tm8oxmtnz3g24k9p328sf9if"); // 		    np = agnode(root, n->name);
UNSUPPORTED("k7qf5ks6w37bfi3z9eef3qlu"); // 		    ND_pos(np)[0] = ND_pos(n)[0];
UNSUPPORTED("bfzh6521nzll5lsnpw1k5n4m4"); // 		    ND_pos(np)[1] = ND_pos(n)[1];
UNSUPPORTED("khqpoz54xjfjkti1t9djhewn"); // 		    ND_coord_i(np).x = ND_coord_i(n).x;
UNSUPPORTED("4x9c7uwd0kx0jhvnx5dxmudl"); // 		    ND_coord_i(np).y = ND_coord_i(n).y;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("3mq66y5bl1rf1c70443ospyk"); // 		for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("35xtxnvjglep45528xu3bdsj"); // 		    tp = (agnode(root,n->name,0));
UNSUPPORTED("a3z26j7g5efb4epbmqjb786zu"); // 		    for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("62fs4ym4p052thn1lyb29j2q5"); // 			hp = (agnode(root,e->head->name,0));
UNSUPPORTED("dvwpkbrij9w40pbsbchqp4err"); // 			ep = agedge(root, tp, hp);
UNSUPPORTED("dn7joqnj1y0k5ua3p8eyyts4t"); // 			ED_spl(ep) = ED_spl(e);
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("ewdephguezv9n4j0pr1pilfay"); // 	    graph_init(root);
UNSUPPORTED("8c3un2iqe187mmdrtw54jbkyc"); // 	    ptest_initGraph(root);
UNSUPPORTED("7f8mdyxgvend9tx5cby8fsriu"); // 	    ccs = ccomps(root, &cnt, 0);
UNSUPPORTED("bgk9mnbqancywhx9z6leue7ri"); // 	    packGraphs(cnt, ccs, root, margin, doEdges);
UNSUPPORTED("2wu6h8z9h6pvzsdd62mmcfxg0"); // 	    if (!doEdges)
UNSUPPORTED("2ghubirp3mlgcl6gjf50g3gbu"); // 		copyPos(root);
UNSUPPORTED("5c97f6vfxny0zz35l2bu4maox"); // 	    else
UNSUPPORTED("byjd9fn68fzvo0yhanif3ydum"); // 		State = 1;
UNSUPPORTED("664tfkoggn4h8g2k56p888fsg"); // 	    attach_attrs(root);
UNSUPPORTED("ivgffft2q5w6sjw0k1jg6o4j"); // 	    for (i = 0; i < cnt; i++) {
UNSUPPORTED("cpd2gdsuj81r184ywe3ya1863"); // 		agdelete(root, ccs[i]);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("byt1dlccqrnf77otl8aey0q7"); // 	    agwrite(root, stdout);
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("6okr9lyl25rynlpeb541qyy7h"); // 	    packGraphs(cnt, gs, 0, margin, doEdges);
UNSUPPORTED("durj7dcilnt6i4j5m304vugx7"); // 	    if (doEdges)
UNSUPPORTED("byjd9fn68fzvo0yhanif3ydum"); // 		State = 1;
UNSUPPORTED("ivgffft2q5w6sjw0k1jg6o4j"); // 	    for (i = 0; i < cnt; i++) {
UNSUPPORTED("2ebr0nay4ws6wvabvtsc7i6g6"); // 		if (!doEdges)
UNSUPPORTED("6msz5q1lfw4hvu5d3eqbs110s"); // 		    copyPos(gs[i]);
UNSUPPORTED("1ue5ykok6uxlgcq1ob0qdyro8"); // 		attach_attrs(gs[i]);
UNSUPPORTED("4azg08ol0hnirn0s158w62j2j"); // 		agwrite(gs[i], stdout);
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
