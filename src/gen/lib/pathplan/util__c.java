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
package gen.lib.pathplan;
import static smetana.core.Macro.UNSUPPORTED;

import gen.annotation.Original;
import gen.annotation.Unused;

public class util__c {


//3 ct6tszngugakbl42zkaqrt7p1
// void make_polyline(Ppolyline_t line, Ppolyline_t* sline) 
@Unused
@Original(version="2.38.0", path="lib/pathplan/util.c", name="make_polyline", key="ct6tszngugakbl42zkaqrt7p1", definition="void make_polyline(Ppolyline_t line, Ppolyline_t* sline)")
public static Object make_polyline(Object... arg) {
UNSUPPORTED("c01vxogao855zs8fe94tpim9g"); // void
UNSUPPORTED("caslgp07xc1rz7m4io9o6y06u"); // make_polyline(Ppolyline_t line, Ppolyline_t* sline)
UNSUPPORTED("erg9i1970wdri39osu8hx2a6e"); // {
UNSUPPORTED("69kg050pehcqgm1vozba79nx6"); //     static int isz = 0;
UNSUPPORTED("4fjyhrgkxtd8bira8nmu5i8b3"); //     static Ppoint_t* ispline = 0;
UNSUPPORTED("dzpsknrwv8qkqq20hjnjpjn68"); //     int i, j;
UNSUPPORTED("93m2yes5av2bhu9cbgdvgao05"); //     int npts = 4 + 3*(line.pn-2);
UNSUPPORTED("c0tj1d84o2ebjy9ke6sgke9m8"); //     if (npts > isz) {
UNSUPPORTED("av96wgpkd1n2udjlb9h7j3y3y"); // 	ispline = (ispline? (Ppoint_t*)realloc(ispline,(npts)*sizeof(Ppoint_t)):(Ppoint_t*)malloc((npts)*sizeof(Ppoint_t))); 
UNSUPPORTED("ehmbnzpsz0najunz7f2xuutcf"); // 	isz = npts;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("cjbplkbp2r33l9lxd9f4plw8q"); //     j = i = 0;
UNSUPPORTED("3sl38lopto9lxrp6b54bo2mp9"); //     ispline[j+1] = ispline[j] = line.ps[i];
UNSUPPORTED("1jxyp8hw11938jx60dm71z97j"); //     j += 2;
UNSUPPORTED("6xu6l640dwkn7142pwdqqinwh"); //     i++;
UNSUPPORTED("73ap4ch7ov640gtez9np1qdy"); //     for (; i < line.pn-1; i++) {
UNSUPPORTED("9mzuffh5epf8o14tph3qhs6bb"); // 	ispline[j+2] = ispline[j+1] = ispline[j] = line.ps[i];
UNSUPPORTED("b6bx299910tris4yhn65it5di"); // 	j += 3;
UNSUPPORTED("dvgyxsnyeqqnyzq696k3vskib"); //     }
UNSUPPORTED("3sl38lopto9lxrp6b54bo2mp9"); //     ispline[j+1] = ispline[j] = line.ps[i];
UNSUPPORTED("1m0hhl8du9lwz0vqvit6zf4cv"); //     sline->pn = npts;
UNSUPPORTED("bsi255abbfm738aeiyf2i04u8"); //     sline->ps = ispline;
UNSUPPORTED("c24nfmv9i7o5eoqaymbibp7m7"); // }

throw new UnsupportedOperationException();
}


}
