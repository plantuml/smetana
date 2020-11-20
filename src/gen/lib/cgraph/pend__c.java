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
import static smetana.core.Macro.UNSUPPORTED;

public class pend__c {




//3 77vpxparxzmm27mmm1mqs0m0y
// void agrecord_callback(Agraph_t * g, Agobj_t * obj, int kind, 		       Agsym_t * optsym) 
@Unused
@Original(version="2.38.0", path="lib/cgraph/pend.c", name="agrecord_callback", key="77vpxparxzmm27mmm1mqs0m0y", definition="void agrecord_callback(Agraph_t * g, Agobj_t * obj, int kind, 		       Agsym_t * optsym)")
public static Object agrecord_callback(Object... arg) {
UNSUPPORTED("8kh7tdu40e0f5hui0hcx3ojw"); // void agrecord_callback(Agraph_t * g, Agobj_t * obj, int kind,
UNSUPPORTED("amek1l9br0si8a9jvgv8v9jkb"); // 		       Agsym_t * optsym)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("33vdvvs3uqbdtg7b1fuiy1r22"); //     pendingset_t *pending;
UNSUPPORTED("do2ldsjj56m49f95rq76qxpq8"); //     Dict_t *dict;
UNSUPPORTED("3e5oj67wvvqnpkv5irik2w6v7"); //     pending_cb_t *handle;
UNSUPPORTED("ers4ys5zwhwnecpeo7f50pdlk"); //     pending =
UNSUPPORTED("clm1anc67pw03dsc0fl3qb7p0"); // 	(pendingset_t *) agbindrec(g, DRName, sizeof(pendingset_t), (0));
UNSUPPORTED("elb9jvgldg2htymh7c74smj7o"); //     switch (kind) {
UNSUPPORTED("e19luzlumlv4ceyibjghgitjk"); //     case 100:
UNSUPPORTED("bt8qt5d94yexozgdbv5sspmm4"); // 	;
UNSUPPORTED("bt8qt5d94yexozgdbv5sspmm4"); // 	;
UNSUPPORTED("bh8r0ah5bdhy9b8fguergxls8"); // 	dict = dictof(pending, obj, 100);
UNSUPPORTED("8w10gh957jzwdh6u4cu779pov"); // 	handle = lookup(dict, obj);
UNSUPPORTED("3niic65nul5y025zfu6sofbvs"); // 	if (handle == 0)
UNSUPPORTED("3dk7uy243d9xxq8o4v964pmlw"); // 	    handle = insert(dict, g, obj, optsym);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8q5omndta1qpcentw63h413zf"); //     case 101:
UNSUPPORTED("16zt5ri5is42floscnatxr9y0"); // 	if (lookup(dictof(pending, obj, 100), obj))
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("7fgyme1271lzkag7zfllc0tew"); // 	if (lookup(dictof(pending, obj, 102), obj))
UNSUPPORTED("ai3czg6gaaxspsmndknpyvuiu"); // 	    break;
UNSUPPORTED("b8ce64b0yiy7uu0nuusdpn8mm"); // 	dict = dictof(pending, obj, 101);
UNSUPPORTED("8w10gh957jzwdh6u4cu779pov"); // 	handle = lookup(dict, obj);
UNSUPPORTED("3niic65nul5y025zfu6sofbvs"); // 	if (handle == 0)
UNSUPPORTED("3dk7uy243d9xxq8o4v964pmlw"); // 	    handle = insert(dict, g, obj, optsym);
UNSUPPORTED("a0edh2s4u2bcccyz9l2ipltzh"); // 	record_sym(obj, handle, optsym);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("e1sxtr2029u6bg4eodqye5nam"); //     case 102:
UNSUPPORTED("3xn39mhl4qgpevnmfeihn3yfl"); // 	purge(dictof(pending, obj, 100), obj);
UNSUPPORTED("ay7yim5iyu0h1rmxxq1j0yiew"); // 	purge(dictof(pending, obj, 101), obj);
UNSUPPORTED("eva458xjr00pr4dd58xrsr3wo"); // 	dict = dictof(pending, obj, 102);
UNSUPPORTED("8w10gh957jzwdh6u4cu779pov"); // 	handle = lookup(dict, obj);
UNSUPPORTED("3niic65nul5y025zfu6sofbvs"); // 	if (handle == 0)
UNSUPPORTED("3dk7uy243d9xxq8o4v964pmlw"); // 	    handle = insert(dict, g, obj, optsym);
UNSUPPORTED("6aw91xzjmqvmtdvt1di23af8y"); // 	break;
UNSUPPORTED("8l3rwj6ctswoa4gvh2j4poq70"); //     default:
UNSUPPORTED("75q0u8gexnc6ds09pnl8xopt8"); // 	agerr(AGERR,"agrecord_callback of a bad object");
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}



}
