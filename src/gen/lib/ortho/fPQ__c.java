/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
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
package gen.lib.ortho;
import h.*;
import smetana.core.*;
import static smetana.core.Macro.*;
import static smetana.core.JUtils.*;
import static smetana.core.JUtilsDebug.*;
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

public class fPQ__c {
//1 2digov3edok6d5srhgtlmrycs
// extern lt_symlist_t lt_preloaded_symbols[]


//1 baedz5i9est5csw3epz3cv7z
// typedef Ppoly_t Ppolyline_t


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


//1 8dfqgf3u1v830qzcjqh9o8ha7
// extern Agmemdisc_t AgMemDisc


//1 18k2oh2t6llfsdc5x0wlcnby8
// extern Agiddisc_t AgIdDisc


//1 a4r7hi80gdxtsv4hdoqpyiivn
// extern Agiodisc_t AgIoDisc


//1 bnzt5syjb7mgeru19114vd6xx
// extern Agdisc_t AgDefaultDisc


//1 35y2gbegsdjilegaribes00mg
// extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,     Agstrictundirected


//1 c2rygslq6bcuka3awmvy2b3ow
// typedef Agsubnode_t	Agnoderef_t


//1 xam6yv0dcsx57dtg44igpbzn
// typedef Dtlink_t	Agedgeref_t


//1 75wd380yhtm1uol93mb8l3kmn
// static snode**  pq


//1 8m7y12v9uhpfwb9agee4dvvd7
// static int     PQcnt


//1 37df10if13d1k3ddj140oe9ge
// static snode    guard


//1 3oj5aj3gc05focs9czbzub5sm
// static int     PQsize




//3 6d62kgw3p14u24ayu546j4r82
// void PQgen(int sz) 
public static Object PQgen(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("mv0qxfr5hxyhgu3l3m6o47cy"); // PQgen(int sz)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("do3zjq97xzdk5dhii167i60qh"); //   if (!pq) {
UNSUPPORTED("74u3ayhkzemd24zmbuv7wpym8"); //     pq = (snode**)zmalloc((sz+1)*sizeof(snode*));
UNSUPPORTED("dezukzubu9nms24lhvphuawxq"); //     pq[0] = &guard;
UNSUPPORTED("593hemyh9nreh89upeivll5qx"); //     PQsize = sz;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("akljrpu8bej9lq4rmsktz8u2e"); //   PQcnt = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 af70676bgfacdrx355e3fm16w
// void PQfree(void) 
public static Object PQfree(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("a722afmxpzwjdmlojj7lqbxaj"); // PQfree(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("efn0baufwv42rir223e1awlhs"); //   free (pq);
UNSUPPORTED("4af6njplv9g18xpb4kh6834b2"); //   pq = NULL;
UNSUPPORTED("akljrpu8bej9lq4rmsktz8u2e"); //   PQcnt = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9gva9zqwj67hmfsbnnvelzt5i
// void PQinit(void) 
public static Object PQinit(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("3p0cdanvp4f13d8omi42lvjl1"); // PQinit(void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("akljrpu8bej9lq4rmsktz8u2e"); //   PQcnt = 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 52wib9gann39qwvmctcw6wxdi
// void PQcheck (void) 
public static Object PQcheck(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("ais4fu8ea90z9l9gc75rtolae"); // PQcheck (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("327a0i7b6rqjqj8wdl0h29mnc"); //   int i;
UNSUPPORTED("ajjv0cjc9s0osbkjlg35z41k"); //   for (i = 1; i <= PQcnt; i++) {
UNSUPPORTED("6mg3o7pwh14yf5rgrii3b7la2"); //     if ((pq[i])->n_idx != i) {
UNSUPPORTED("2kc7vwb5ge1ym5i0vk3t2ku3u"); //       assert (0);
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 2lbfs6ynzlunyatr57r41uvz7
// void PQupheap(int k) 
public static Object PQupheap(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("5hhoge8azwixhuw1r6f1ae6d"); // PQupheap(int k)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7e1sq1127wt16hr7o0andcwob"); //   snode* x = pq[k];
UNSUPPORTED("7bfu0p9xmzkty10xv4n4l5cqs"); //   int     v = x->n_val;
UNSUPPORTED("1j1bbq23z0qzohezignztjo66"); //   int     next = k/2;
UNSUPPORTED("ae5pat4mp4l6k25pvk8saz8c7"); //   snode*  n;
UNSUPPORTED("70492o1szwz9au93c3is2goa"); //   while ((n = pq[next])->n_val < v) {
UNSUPPORTED("4i53ezzk69bsmpugd2h8bo35"); //     pq[k] = n;
UNSUPPORTED("iolnc8pg22pbme3zbdim1eqy"); //     (n)->n_idx = k;
UNSUPPORTED("8fpdpgwovt0k58t5u167v63is"); //     k = next;
UNSUPPORTED("eqtnhenyor3dwsa6on9crthdd"); //     next /= 2;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("1lxwoekai0i8v3rg0vrg6ahmx"); //   pq[k] = x;
UNSUPPORTED("7ss0wudteh17yswf0ihopig7z"); //   (x)->n_idx = k;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 dpsy3q4qmuyf70antkm0irwus
// int PQ_insert(snode* np) 
public static Object PQ_insert(Object... arg) {
UNSUPPORTED("etrjsq5w49uo9jq5pzifohkqw"); // int
UNSUPPORTED("5eeaexrm7pigm7t9d73aqaaht"); // PQ_insert(snode* np)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("7d2tojz8u1bqjo7uhe2jqz8ks"); //   if (PQcnt == PQsize) {
UNSUPPORTED("1fnwaiyzr5fvurskinr46kklp"); //     agerr (AGERR, "Heap overflow\n");
UNSUPPORTED("bur99ge8gwr5q0vyjwjyk8z3b"); //     return (1);
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("d8u0aq1g7mc9qslpfsw3o3ezz"); //   PQcnt++;
UNSUPPORTED("8f54fbv0205j58hpu3uq3i2ow"); //   pq[PQcnt] = np;
UNSUPPORTED("f4e1yfpgiak6lx72g6gk4nyi0"); //   PQupheap (PQcnt);
UNSUPPORTED("a7h72yd6f22ezx8o0izfoyyzl"); //   PQcheck();
UNSUPPORTED("bid671dovx1rdiquw5vm3fttj"); //   return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 ah2uksf5mfgu7r25rg6poansh
// void PQdownheap (int k) 
public static Object PQdownheap(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("5jo6sukhc9upf5qv4eukh8kop"); // PQdownheap (int k)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("dd3235mkocimg2v70ln8ixz3k"); //   snode*    x = pq[k];
UNSUPPORTED("e0wd4mp2k58ml2bf01e6mtxfc"); //   int      v = (x)->n_val;
UNSUPPORTED("b9pl90rstqz0jhnw3ttda3kx5"); //   int      lim = PQcnt/2;
UNSUPPORTED("917ffzmzxsh6kw3txaqow8dv0"); //   snode*    n;
UNSUPPORTED("zrgst5t0lhf2kxrym9g7gvsn"); //   int      j;
UNSUPPORTED("7bbx1rekibyh3hyxh24lprwwk"); //   while (k <= lim) {
UNSUPPORTED("disb3eax2r4wgge9im541y9hv"); //     j = k+k;
UNSUPPORTED("e4w7jx4o3i4gav8ujef2bapbn"); //     n = pq[j];
UNSUPPORTED("4yles8zr6ozg2g0df2jefc1l2"); //     if (j < PQcnt) {
UNSUPPORTED("77cupwd0hd3zp8he6wd4tm6nx"); //       if ((n)->n_val < (pq[j+1])->n_val) {
UNSUPPORTED("1jeqo15tfc6vbefwf85bniwfn"); //         j++;
UNSUPPORTED("1sglut5nbxcoto9tvzxs3eixh"); //         n = pq[j];
UNSUPPORTED("dquo3qofk56ds5xl95lhvcthf"); //       }
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3hshbuqs95898wh95e2fdh5uz"); //     if (v >= (n)->n_val) break;
UNSUPPORTED("4i53ezzk69bsmpugd2h8bo35"); //     pq[k] = n;
UNSUPPORTED("iolnc8pg22pbme3zbdim1eqy"); //     (n)->n_idx = k;
UNSUPPORTED("8lpwfkimmel90007dlp5eqpbh"); //     k = j;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("1lxwoekai0i8v3rg0vrg6ahmx"); //   pq[k] = x;
UNSUPPORTED("7ss0wudteh17yswf0ihopig7z"); //   (x)->n_idx = k;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 asdsi15xhxgfyxlqv3bbx7vzv
// snode* PQremove (void) 
public static Object PQremove(Object... arg) {
UNSUPPORTED("7qyamsdkopruu23xaccl0bcd2"); // snode*
UNSUPPORTED("7j2q3l5jxp3w7ags9kr29frzn"); // PQremove (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("5cu5gkv7lbctrvkomvhsw0j1o"); //   snode* n;
UNSUPPORTED("6078p2rnfog3yn8o3qzs373e2"); //   if (PQcnt) {
UNSUPPORTED("6a46qhtz2fbsmmd370t7fv44f"); //     n = pq[1];
UNSUPPORTED("8s70ivnxixrmkvd1lnojuxkfn"); //     pq[1] = pq[PQcnt];
UNSUPPORTED("7o53ly4ejd7hkmf5tx564eb0x"); //     PQcnt--;
UNSUPPORTED("4e6w4ct22nty5htys3c0346u1"); //     if (PQcnt) PQdownheap (1);
UNSUPPORTED("26oeamvax1w8xlf1fp3w3uwbz"); //     PQcheck();
UNSUPPORTED("69hc24ic55i66g8tf2ne42327"); //     return n;
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("7lrkjjj5lce2uf86c1y9o9yoa"); //   else return 0;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 6dvks137inq1ybpgc3p9il60e
// void PQupdate (snode* n, int d) 
public static Object PQupdate(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("b1fi3xtkc0mzuq3pimbrumdj3"); // PQupdate (snode* n, int d)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("byrcaa9kitj1mfe0we79iao5b"); //   (n)->n_val = d;
UNSUPPORTED("az1v3dey64e8mmt571cqcmw5b"); //   PQupheap (n->n_idx);
UNSUPPORTED("a7h72yd6f22ezx8o0izfoyyzl"); //   PQcheck();
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}




//3 9u2i85oe7eva5iz0ousp6k9ze
// void PQprint (void) 
public static Object PQprint(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("837kozmovwrdb83nqf648v9hy"); // PQprint (void)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("29u9nk1nrupcw2j8c7qe5glz7"); //   int    i;
UNSUPPORTED("ae5pat4mp4l6k25pvk8saz8c7"); //   snode*  n;
UNSUPPORTED("f3w7y9hew7fq41kdfxhc1bni7"); //   fprintf (stderr, "Q: ");
UNSUPPORTED("ajjv0cjc9s0osbkjlg35z41k"); //   for (i = 1; i <= PQcnt; i++) {
UNSUPPORTED("8ma2z0vb3r4euoklbfwtvqixt"); //     n = pq[i];
UNSUPPORTED("5vx4bf24j9k0k7d5db0nzqqho"); //     fprintf (stderr, "%d(%d:%d) ",  
UNSUPPORTED("3cv4xg03w7tifmwxdgb02cs87"); //       n->index, (n)->n_idx, (n)->n_val);
UNSUPPORTED("7ijd6pszsxnoopppf6xwo8wdl"); //   }
UNSUPPORTED("axonnz64pfb53bfq61adrgxoo"); //   fprintf (stderr, "\n");
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
