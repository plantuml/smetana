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

public class compound__c {




//3 f35390txedsmk9p0bb7lc0glh
// static int splineIntersectf(pointf * pts, boxf * bb) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/compound.c", name="splineIntersectf", key="f35390txedsmk9p0bb7lc0glh", definition="static int splineIntersectf(pointf * pts, boxf * bb)")
public static Object splineIntersectf(Object... arg) {
UNSUPPORTED("5skcahu2z7i5of3rceeyk3dja"); // static int splineIntersectf(pointf * pts, boxf * bb)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("4x99qvp4a3bmbyxtp16ajfnsk"); //     double tmin = 2.0;
UNSUPPORTED("6wfj8onzmd4ihhh62dqfmqpbx"); //     double t;
UNSUPPORTED("9g866elzsedx9foz9yjhoiou1"); //     pointf origpts[4];
UNSUPPORTED("b17di9c7wgtqm51bvsyxz6e2f"); //     int i;
UNSUPPORTED("a2n8aqfq0cqpx8elstmfn9oq6"); //     for (i = 0; i < 4; i++) {
UNSUPPORTED("4zou1qx7inlvcv0miqk04wcab"); // 	origpts[i] = pts[i];
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6vm6zifwonvzwuelxtslbue2"); //     t = findVertical(pts, 0.0, 1.0, bb->LL.x, bb->LL.y, bb->UR.y);
UNSUPPORTED("9zvtsolyyf2ytpv8pj4a8n5iu"); //     if ((t >= 0) && (t < tmin)) {
UNSUPPORTED("8w1khrdoc5zw1yk6j1a8drqse"); // 	Bezier(origpts, 3, t, pts, NULL);
UNSUPPORTED("5ml6bcuw1xgfn7f3dyox7iwrv"); // 	tmin = t;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("981p5dxcykkvx91604334lab3"); //     t = findVertical(pts, 0.0, MIN(1.0, tmin), bb->UR.x, bb->LL.y,
UNSUPPORTED("1of63c5vskctycz57r6s1aop5"); // 		     bb->UR.y);
UNSUPPORTED("9zvtsolyyf2ytpv8pj4a8n5iu"); //     if ((t >= 0) && (t < tmin)) {
UNSUPPORTED("8w1khrdoc5zw1yk6j1a8drqse"); // 	Bezier(origpts, 3, t, pts, NULL);
UNSUPPORTED("5ml6bcuw1xgfn7f3dyox7iwrv"); // 	tmin = t;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7a2rh5vrty9usl73kwlat7axz"); //     t = findHorizontal(pts, 0.0, MIN(1.0, tmin), bb->LL.y, bb->LL.x,
UNSUPPORTED("de5psijf8qtaea4iaibltvfli"); // 		       bb->UR.x);
UNSUPPORTED("9zvtsolyyf2ytpv8pj4a8n5iu"); //     if ((t >= 0) && (t < tmin)) {
UNSUPPORTED("8w1khrdoc5zw1yk6j1a8drqse"); // 	Bezier(origpts, 3, t, pts, NULL);
UNSUPPORTED("5ml6bcuw1xgfn7f3dyox7iwrv"); // 	tmin = t;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("8j6y4x6maqneer7is54dvjrg8"); //     t = findHorizontal(pts, 0.0, MIN(1.0, tmin), bb->UR.y, bb->LL.x,
UNSUPPORTED("de5psijf8qtaea4iaibltvfli"); // 		       bb->UR.x);
UNSUPPORTED("9zvtsolyyf2ytpv8pj4a8n5iu"); //     if ((t >= 0) && (t < tmin)) {
UNSUPPORTED("8w1khrdoc5zw1yk6j1a8drqse"); // 	Bezier(origpts, 3, t, pts, NULL);
UNSUPPORTED("5ml6bcuw1xgfn7f3dyox7iwrv"); // 	tmin = t;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("5yrkc1uiqwozz2tsxyo3vpj6n"); //     if (tmin < 2.0) {
UNSUPPORTED("eleqpc2p2r3hvma6tipoy7tr"); // 	return 1;
UNSUPPORTED("2lkbqgh2h6urnppaik3zo7ywi"); //     } else
UNSUPPORTED("c9ckhc8veujmwcw0ar3u3zld4"); // 	return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 cqg91aue3soclnawequqcxspl
// static void makeCompoundEdge(graph_t * g, edge_t * e, Dt_t* clustMap) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/compound.c", name="makeCompoundEdge", key="cqg91aue3soclnawequqcxspl", definition="static void makeCompoundEdge(graph_t * g, edge_t * e, Dt_t* clustMap)")
public static Object makeCompoundEdge(Object... arg) {
UNSUPPORTED("94ok4vzwibg79sh9bgw127ynj"); // static void makeCompoundEdge(graph_t * g, edge_t * e, Dt_t* clustMap)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("d8yeygt41ba5jbyj4rz2bs7jh"); //     graph_t *lh;		/* cluster containing head */
UNSUPPORTED("ckcdimdpkin3lhakg1rjgopmi"); //     graph_t *lt;		/* cluster containing tail */
UNSUPPORTED("em6swtpn9fdaqlt4w0ye5p7db"); //     bezier *bez;		/* original Bezier for e */
UNSUPPORTED("2nh8wbaihnp137k4pc9xuzwhg"); //     bezier *nbez;		/* new Bezier  for e */
UNSUPPORTED("1tw709ct510b9s636x7nkqfkr"); //     int starti = 0, endi = 0;	/* index of first and last control point */
UNSUPPORTED("8i0kwb8r6a2sj6nuvcy3bg9rx"); //     node_t *head;
UNSUPPORTED("abn0n8lzvb24ju9mrqm4oqu8"); //     node_t *tail;
UNSUPPORTED("v5k4w91mrx94yjcdoytcu9oh"); //     boxf *bb;
UNSUPPORTED("dzpsknrwv8qkqq20hjnjpjn68"); //     int i, j;
UNSUPPORTED("cav0e7ncloqss0hsvc4fyfi7s"); //     int size;
UNSUPPORTED("d8sp6cfkpfyndzmid92shiq50"); //     pointf pts[4];
UNSUPPORTED("2bghyit203pd6xw2ihhenzyn8"); //     pointf p;
UNSUPPORTED("a1awknurkwnitpucodqwmcybo"); //     int fixed;
UNSUPPORTED("eg8l6bf528m9rxpz19s67zunk"); //     /* find head and tail target clusters, if defined */
UNSUPPORTED("cv6tt9aup4gcbgqhx1nq22k1c"); //     lh = getCluster(g, agget(e, "lhead"), clustMap);
UNSUPPORTED("1c1flydze3375acsjsk9q3kp"); //     lt = getCluster(g, agget(e, "ltail"), clustMap);
UNSUPPORTED("c0uthnj5r46is8vqpjh6vftc8"); //     if (!lt && !lh)
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("7r9z58ji5z8h9c59lp0npnrgu"); //     if (!ED_spl(e)) return;
UNSUPPORTED("d5zyxsdhnmpgj9r2eeuoe24qd"); //     /* at present, we only handle single spline case */
UNSUPPORTED("9y41ojbiongk0r6fdtq1my3t1"); //     if (ED_spl(e)->size > 1) {
UNSUPPORTED("2bykd7j98lcwoewshvpja61l3"); // 	agerr(AGWARN, "%s -> %s: spline size > 1 not supported\n",
UNSUPPORTED("1wah0q9mwnexbe0myh4pe78ks"); // 	      agnameof(agtail(e)), agnameof(aghead(e)));
UNSUPPORTED("a7fgam0j0jm7bar0mblsv3no4"); // 	return;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("9zp3bsvuco9me48ea4fiy6acl"); //     bez = ED_spl(e)->list;
UNSUPPORTED("1mwkc047hik3rfvg9nirzx1eu"); //     size = bez->size;
UNSUPPORTED("9vcgvjkna4elv9mw682bcl1ry"); //     head = aghead(e);
UNSUPPORTED("6pl9v5iuk7ek5nv87env6rn8y"); //     tail = agtail(e);
UNSUPPORTED("ap2j55l6otqo1gbl6ltds9nwh"); //     /* allocate new Bezier */
UNSUPPORTED("evus0s8ajoz1nr025560y72nt"); //     nbez = (bezier*)gmalloc(sizeof(bezier));
UNSUPPORTED("ep4g00m6u2qqzjjpl5wv8pf68"); //     nbez->eflag = bez->eflag;
UNSUPPORTED("3f2ouh5001dudtknnvyd0d3k"); //     nbez->sflag = bez->sflag;
UNSUPPORTED("9puveeg1x9guxlasq00a4jkoy"); //     /* if Bezier has four points, almost collinear,
UNSUPPORTED("3j2z7u8v0esgm7xffel168hq7"); //      * make line - unimplemented optimization?
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("gquyyp49r5koft7tvjy0s8rg"); //     /* If head cluster defined, find first Bezier
UNSUPPORTED("36p20hcsa21623tw4wu1oz2p6"); //      * crossing head cluster, and truncate spline to
UNSUPPORTED("9s9druwau7a95yt795beirpsq"); //      * box edge.
UNSUPPORTED("cn1atesybawh2axikezvwq87k"); //      * Otherwise, leave end alone.
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("7ub8yceaqsfpwhdiiln16imu8"); //     fixed = 0;
UNSUPPORTED("9pt4rploytevhgdsh2ccwqwa5"); //     if (lh) {
UNSUPPORTED("1epg8to10rb7b0uyumqk5by3d"); // 	bb = &(GD_bb(lh));
UNSUPPORTED("5kfib01to02c8vzno1s2ekcr6"); // 	if (!inBoxf(ND_coord(head), bb)) {
UNSUPPORTED("dw7kdr12sq66xx2svd4s92czw"); // 	    agerr(AGWARN, "%s -> %s: head not inside head cluster %s\n",
UNSUPPORTED("4685lstw48yeb92f1qu3uf6ju"); // 		  agnameof(agtail(e)), agnameof(aghead(e)), agget(e, "lhead"));
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("3uodo3h9hth2y90nphjmbr0oz"); // 	    /* If first control point is in bb, degenerate case. Spline
UNSUPPORTED("48lbfpll26nek7srz6txj1ifd"); // 	     * reduces to four points between the arrow head and the point 
UNSUPPORTED("bnhwhc0oclranqqrc084eqy25"); // 	     * where the segment between the first control point and arrow head 
UNSUPPORTED("cqgsnvduolzsvf228s6bzu09z"); // 	     * crosses box.
UNSUPPORTED("20m1lc1moer8x00tx9ceto0iw"); // 	     */
UNSUPPORTED("9pqsbiv3p2qq7o79wqbbz8l5n"); // 	    if (inBoxf(bez->list[0], bb)) {
UNSUPPORTED("9w1xj4pf7ycfdklkv9mztvayi"); // 		if (inBoxf(ND_coord(tail), bb)) {
UNSUPPORTED("3f0u3cjz549lwgnkj0rlfv6rv"); // 		    agerr(AGWARN,
UNSUPPORTED("27beaae4u5f8m2rui7t930icj"); // 			  "%s -> %s: tail is inside head cluster %s\n",
UNSUPPORTED("5su0sbzvdwjhkfmbg8xivrf3y"); // 			  agnameof(agtail(e)), agnameof(aghead(e)), agget(e, "lhead"));
UNSUPPORTED("a47jqpic91ky93e1ohxv590l5"); // 		} else {
UNSUPPORTED("ewwp403copbj6mdyqowm6q2s4"); // 		    assert(bez->sflag);	/* must be arrowhead on tail */
UNSUPPORTED("lp06fc3tmr8xux3w7kfnjg4r"); // 		    p = boxIntersectf(bez->list[0], bez->sp, bb);
UNSUPPORTED("ejtuxx5nuew10e08cnrbh9avq"); // 		    bez->list[3] = p;
UNSUPPORTED("7duperi3l69fplb736n7smpqf"); // 		    bez->list[1] = mid_pointf(p, bez->sp);
UNSUPPORTED("a4eh5xj2wrncqnmttmavzegdw"); // 		    bez->list[0] = mid_pointf(bez->list[1], bez->sp);
UNSUPPORTED("5dxkrve755ukj7tzac4ft5kee"); // 		    bez->list[2] = mid_pointf(bez->list[1], p);
UNSUPPORTED("59ne8fp4dumv8e2dt8nzlbwm9"); // 		    if (bez->eflag)
UNSUPPORTED("e0iax8us2lskwlp49snfuewo5"); // 			endi = arrowEndClip(e, bez->list,
UNSUPPORTED("cblie3jhaa9y0orqcusd4rz3n"); // 					 starti, 0, nbez, bez->eflag);
UNSUPPORTED("dtvlepuobgzgt31wlwvahcuz6"); // 		    endi += 3;
UNSUPPORTED("b1vrskwl75muujmh6lvltym9p"); // 		    fixed = 1;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("2sf4rxnj84i693qu8p8eeb0th"); // 		for (endi = 0; endi < size - 1; endi += 3) {
UNSUPPORTED("3gsvjp9m9s9xkrldmovrxl86l"); // 		    if (splineIntersectf(&(bez->list[endi]), bb))
UNSUPPORTED("a5064jph9xpw67dcun2my4mcm"); // 			break;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("6v67nn2fkgve6sliwhhcjhlzy"); // 		if (endi == size - 1) {	/* no intersection */
UNSUPPORTED("ne38tb76v74pens6v8pbfrbg"); // 		    assert(bez->eflag);
UNSUPPORTED("6zfsm93mmi2u1kkkh72v0p3ko"); // 		    nbez->ep = boxIntersectf(bez->ep, bez->list[endi], bb);
UNSUPPORTED("a47jqpic91ky93e1ohxv590l5"); // 		} else {
UNSUPPORTED("59ne8fp4dumv8e2dt8nzlbwm9"); // 		    if (bez->eflag)
UNSUPPORTED("2931qkcakw4pmrkqfxkwz6c9w"); // 			endi =
UNSUPPORTED("5m1xf54kia4xa3oh9pi0laqg2"); // 			    arrowEndClip(e, bez->list,
UNSUPPORTED("dif2h2k72i4vle08l8zt6g99d"); // 					 starti, endi, nbez, bez->eflag);
UNSUPPORTED("dtvlepuobgzgt31wlwvahcuz6"); // 		    endi += 3;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("37cextn872jccni47tbuylnde"); // 		fixed = 1;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("b4l5v1tzcfyxswk474eyxoh7g"); //     if (fixed == 0) {		/* if no lh, or something went wrong, use original head */
UNSUPPORTED("5iaa7yro1fezven3pxpfgmxu4"); // 	endi = size - 1;
UNSUPPORTED("a4jsfnfkjyk5zvhtmxz837cwk"); // 	if (bez->eflag)
UNSUPPORTED("ardm696r3cpsbtf6losy2b016"); // 	    nbez->ep = bez->ep;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("ea4t41cqs5cu6h8oyl4vr26m2"); //     /* If tail cluster defined, find last Bezier
UNSUPPORTED("7p2mckkgkchxr6vhh6gezq8wz"); //      * crossing tail cluster, and truncate spline to
UNSUPPORTED("9s9druwau7a95yt795beirpsq"); //      * box edge.
UNSUPPORTED("cn1atesybawh2axikezvwq87k"); //      * Otherwise, leave end alone.
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("7ub8yceaqsfpwhdiiln16imu8"); //     fixed = 0;
UNSUPPORTED("5qu8oy18iv3lo7czvfxeoa9uf"); //     if (lt) {
UNSUPPORTED("pk4bun7t8spswxbvfqizndma"); // 	bb = &(GD_bb(lt));
UNSUPPORTED("5fdmhqx0gpmawrdmhes377bcj"); // 	if (!inBoxf(ND_coord(tail), bb)) {
UNSUPPORTED("1m0jbxdni08pgm584b96t3rjx"); // 	    agerr(AGWARN, "%s -> %s: tail not inside tail cluster %s\n",
UNSUPPORTED("3s8r91i8l8gnx912jssz9qyeo"); // 		agnameof(agtail(e)), agnameof(aghead(e)), agget(e, "ltail"));
UNSUPPORTED("7yhr8hn3r6wohafwxrt85b2j2"); // 	} else {
UNSUPPORTED("1qjsjzvwnzg5em6iaq3reaswh"); // 	    /* If last control point is in bb, degenerate case. Spline
UNSUPPORTED("f2rlo65dpa2r245fl7q3a8uhm"); // 	     * reduces to four points between arrow head, and the point
UNSUPPORTED("c22xvluit87sy443q8y00uc4g"); // 	     * where the segment between the last control point and the 
UNSUPPORTED("drage3192rqa7ifzj1p0rzr7b"); // 	     * arrow head crosses box.
UNSUPPORTED("20m1lc1moer8x00tx9ceto0iw"); // 	     */
UNSUPPORTED("5xu4e03fqpef4n5pmrb5kau0d"); // 	    if (inBoxf(bez->list[endi], bb)) {
UNSUPPORTED("25cb9bqsfesb0faqthoggdumf"); // 		if (inBoxf(ND_coord(head), bb)) {
UNSUPPORTED("3f0u3cjz549lwgnkj0rlfv6rv"); // 		    agerr(AGWARN,
UNSUPPORTED("5xfu8lqrs0caaz29aue2f4s21"); // 			"%s -> %s: head is inside tail cluster %s\n",
UNSUPPORTED("f3g912itxolsegc77eg84cl5l"); // 		  	agnameof(agtail(e)), agnameof(aghead(e)), agget(e, "ltail"));
UNSUPPORTED("a47jqpic91ky93e1ohxv590l5"); // 		} else {
UNSUPPORTED("8f4spvkivd7okr9g59i6nwodq"); // 		    assert(bez->eflag);	/* must be arrowhead on head */
UNSUPPORTED("7f7fhm60xzneykhpsinmusktg"); // 		    p = boxIntersectf(bez->list[endi], nbez->ep, bb);
UNSUPPORTED("5sxlw9wg1evuruihg2pf20m2q"); // 		    starti = endi - 3;
UNSUPPORTED("469jcsvjasontlve9fx1oiprf"); // 		    bez->list[starti] = p;
UNSUPPORTED("cnpwuv23ryh1zxbij0n57992e"); // 		    bez->list[starti + 2] = mid_pointf(p, nbez->ep);
UNSUPPORTED("o7wu7segbiephyk1mn6ruzii"); // 		    bez->list[starti + 3] = mid_pointf(bez->list[starti + 2], nbez->ep);
UNSUPPORTED("1hq51ue6km9jd5khvilyiu8ba"); // 		    bez->list[starti + 1] = mid_pointf(bez->list[starti + 2], p);
UNSUPPORTED("f018p8s1pklqzeu862o8grqz3"); // 		    if (bez->sflag)
UNSUPPORTED("c9hvjpjpxposlztt4ykhchse4"); // 			starti = arrowStartClip(e, bez->list, starti,
UNSUPPORTED("dbcocs457i5fpymvciq1id8sl"); // 				endi - 3, nbez, bez->sflag);
UNSUPPORTED("b1vrskwl75muujmh6lvltym9p"); // 		    fixed = 1;
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("175pyfe8j8mbhdwvrbx3gmew9"); // 	    } else {
UNSUPPORTED("d2jlvy1nqfh80mgss1c39f01j"); // 		for (starti = endi; starti > 0; starti -= 3) {
UNSUPPORTED("28srqjfv5l9fgucte4xcck1wf"); // 		    for (i = 0; i < 4; i++)
UNSUPPORTED("8c8hwyg5j3w5quof1ir68ns70"); // 			pts[i] = bez->list[starti - i];
UNSUPPORTED("4r5afy1ydhha880ua170puwym"); // 		    if (splineIntersectf(pts, bb)) {
UNSUPPORTED("ej309gi9fv5xlnkscibruakjp"); // 			for (i = 0; i < 4; i++)
UNSUPPORTED("7i03k1aqcvrb8znb7097fyn48"); // 			    bez->list[starti - i] = pts[i];
UNSUPPORTED("a5064jph9xpw67dcun2my4mcm"); // 			break;
UNSUPPORTED("dkxvw03k2gg9anv4dbze06axd"); // 		    }
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("btve1tg4yf6dsbobp66rbktt7"); // 		if (starti == 0) {
UNSUPPORTED("8n6t6jnfgooxt9ia0n2d9xj5a"); // 		    assert(bez->sflag);
UNSUPPORTED("9iea16dzn148ggj1yhec6nrv6"); // 		    nbez->sp =
UNSUPPORTED("3c8n4kr8984t1a8f2tvj7wgrr"); // 			boxIntersectf(bez->sp, bez->list[starti], bb);
UNSUPPORTED("a47jqpic91ky93e1ohxv590l5"); // 		} else {
UNSUPPORTED("5yn57nenv2uh775lo64evo8ma"); // 		    starti -= 3;
UNSUPPORTED("f018p8s1pklqzeu862o8grqz3"); // 		    if (bez->sflag)
UNSUPPORTED("c9hvjpjpxposlztt4ykhchse4"); // 			starti = arrowStartClip(e, bez->list, starti,
UNSUPPORTED("dbcocs457i5fpymvciq1id8sl"); // 				endi - 3, nbez, bez->sflag);
UNSUPPORTED("6eq5kf0bj692bokt0bixy1ixh"); // 		}
UNSUPPORTED("37cextn872jccni47tbuylnde"); // 		fixed = 1;
UNSUPPORTED("6t98dcecgbvbvtpycwiq2ynnj"); // 	    }
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7016d9urlsksnhs3cnhecjcda"); //     if (fixed == 0) {		/* if no lt, or something went wrong, use original tail */
UNSUPPORTED("eb2mhex2xw1imv1kk03mvjjou"); // 	/* Note: starti == 0 */
UNSUPPORTED("bid01qt9cg10ravykoxdnzxyk"); // 	if (bez->sflag)
UNSUPPORTED("5r4ncqv0i1d4e42av5wd1enpg"); // 	    nbez->sp = bez->sp;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("6npoy905gpw81hrxzbjbr2cfx"); //     /* complete Bezier, free garbage and attach new Bezier to edge 
UNSUPPORTED("795vpnc8yojryr8b46aidsu69"); //      */
UNSUPPORTED("5xonbkojra95eckls0aqmri36"); //     nbez->size = endi - starti + 1;
UNSUPPORTED("ahcr8abvd2jxjhobcfhctvs1b"); //     nbez->list = (pointf*)gmalloc((nbez->size)*sizeof(pointf));
UNSUPPORTED("c9hwlt12y9khkl85dhudsnoji"); //     for (i = 0, j = starti; i < nbez->size; i++, j++)
UNSUPPORTED("bafoyknloit5d46b4iu8wll9p"); // 	nbez->list[i] = bez->list[j];
UNSUPPORTED("60fikjho2iwcxgrd8xetr09m6"); //     free(bez->list);
UNSUPPORTED("3qr0q84nc1rpnmowlbyiowg2z"); //     free(bez);
UNSUPPORTED("70byyll04ac6uqbdyb54i1gr"); //     ED_spl(e)->list = nbez;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 8dlmdg7jixgrpxke9pgbbnous
// void dot_compoundEdges(graph_t * g) 
@Unused
@Original(version="2.38.0", path="lib/dotgen/compound.c", name="dot_compoundEdges", key="8dlmdg7jixgrpxke9pgbbnous", definition="void dot_compoundEdges(graph_t * g)")
public static Object dot_compoundEdges(Object... arg) {
UNSUPPORTED("7ugy3v610tnicjpszcs8fvlvb"); // void dot_compoundEdges(graph_t * g)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5gypxs09iuryx5a2eho9lgdcp"); //     edge_t *e;
UNSUPPORTED("cjx5v6hayed3q8eeub1cggqca"); //     node_t *n;
UNSUPPORTED("aice9tv6l0gls54iyk8147m5u"); //     Dt_t* clustMap = mkClustMap (g);
UNSUPPORTED("44thr6ep72jsj3fksjiwdx3yr"); //     for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
UNSUPPORTED("e20lm4qtccvgsfq5fzjv6sjyl"); // 	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
UNSUPPORTED("1urljgadk0bknazngl2w39evt"); // 	    makeCompoundEdge(g, e, clustMap);
UNSUPPORTED("flupwh3kosf3fkhkxllllt1"); // 	}
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("11epc7udwyi67f5gszznmfwn8"); //     dtclose(clustMap);
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
