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
 * This translation is distributed under the same Licence as the original C program.
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
package demo;

import static gen.lib.cgraph.attr__c.agsafeset;
import static gen.lib.cgraph.edge__c.agedge;
import static gen.lib.cgraph.graph__c.agopen;
import static gen.lib.cgraph.node__c.agnode;
import static gen.lib.gvc.gvc__c.gvContext;
import static gen.lib.gvc.gvlayout__c.gvLayoutJobs;
import h.Agedge_s;
import h.Agnode_s;
import h.Agraph_s;
import h.GVC_s;

import java.io.File;
import java.io.IOException;

import smetana.core.CString;
import smetana.core.JUtilsDebug;
import smetana.core.Macro;
import smetana.core.Z;
import dot.Graphic;

public class Demo25 {

	public static void main(String[] args) throws IOException {

		Z.open();
		Agraph_s g = agopen(new CString("g"), Z._().Agdirected, null);
		try {
			work(g);
		} catch (Exception e) {
			e.printStackTrace();
		}
		JUtilsDebug.printCallStack(new File("CALLTRACE.txt"));
		JUtilsDebug.printMethods();

	}

	private static Agnode_s createNode(Agraph_s g, String name, String width, String height) {
		Agnode_s result = agnode(g, new CString(name), true);
		// agsafeset(result, new CString("shape"), new CString("box"), new CString(""));
		// agsafeset(result, new CString("width"), new CString(width), new CString(""));
		// agsafeset(result, new CString("height"), new CString(height), new CString(""));
		return result;
	}

	private static void work(Agraph_s g) {
		// class A
		//
		// B -> A : owner
		// B <- C

		// NODE cl0001 0.5416666666666666 0.6666666666666666
		// NODE cl0002 0.5555555555555556 0.6666666666666666
		// NODE cl0004 0.5694444444444444 0.6666666666666666
		// EDGE cl0002->cl0001 minlen=0 label=_dim_36_18_
		// EDGE cl0002->cl0004 minlen=0

		Agnode_s a = createNode(g, "a", "0.6388888", "0.666666666");
		Agnode_s b = createNode(g, "b", "0.6388888", "0.666666666");
		Agnode_s c = createNode(g, "c", "0.6388888", "0.666666666");

		Agedge_s e1 = createEdge(g, b, a, 0);
		agsafeset(e1, new CString("label"), Macro.createHackInitDimensionFromLabel(36, 18), new CString(""));
		Agedge_s e2 = createEdge(g, b, c, 0);

		GVC_s gvc = gvContext();
		// Debug.setOneNode(a);

		gvLayoutJobs(gvc, g);

		DebugUtils.printDebugNode(a);
		DebugUtils.printDebugNode(b);
		DebugUtils.printDebugNode(c);
		DebugUtils.printDebugEdge(e1);
		DebugUtils.printDebugEdge(e2);

		final Graphic graphic = new Graphic();
		graphic.addNode(a);
		graphic.addNode(b);
		graphic.addNode(c);
		graphic.addEdge(e1);
		graphic.addEdge(e2);
		graphic.drawTo(new File("out.png"));

	}

	private static Agedge_s createEdge(Agraph_s g, Agnode_s a0, Agnode_s a1, int minlen) {
		Agedge_s e1 = agedge(g, a0, a1, null, true);
		agsafeset(e1, new CString("minlen"), new CString("" + minlen), new CString(""));
		agsafeset(e1, new CString("arrowtail"), new CString("none"), new CString(""));
		agsafeset(e1, new CString("arrowhead"), new CString("none"), new CString(""));
		return e1;
	}

}
