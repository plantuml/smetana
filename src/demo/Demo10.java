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
import java.util.ArrayList;
import java.util.List;

import smetana.core.CString;
import smetana.core.JUtilsDebug;
import smetana.core.Z;
import dot.Graphic;

public class Demo10 {

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

	private static List<Agnode_s> nodes = new ArrayList<Agnode_s>();
	private static List<Agedge_s> edges = new ArrayList<Agedge_s>();

	private static Agnode_s createNode(Agraph_s g, String name) {
		Agnode_s result = agnode(g, new CString(name), true);
		String width = "0.63";
		String height = "0.66";
		agsafeset(result, new CString("shape"), new CString("box"), new CString(""));
		agsafeset(result, new CString("width"), new CString(width), new CString(""));
		agsafeset(result, new CString("height"), new CString(height), new CString(""));
		nodes.add(result);
		return result;
	}

	private static Agedge_s createEdge(Agraph_s g, Agnode_s n1, Agnode_s n2) {
		Agedge_s result = agedge(g, n1, n2, null, true);
		agsafeset(result, new CString("arrowtail"), new CString("none"), new CString(""));
		agsafeset(result, new CString("arrowhead"), new CString("none"), new CString(""));
		edges.add(result);
		return result;
	}

	private static void work(Agraph_s g) {

		Agnode_s a0 = createNode(g, "a0");
		Agnode_s a1 = createNode(g, "a1");
		Agnode_s a2 = createNode(g, "a2");
		Agnode_s a4 = createNode(g, "a4");
		Agnode_s a5 = createNode(g, "a5");
		Agnode_s a3 = createNode(g, "a3");

		// Agnode_s m2 = agnode(g, new CString("m2"), true);
		// Agedge_s e = agedge(g, n, m, null, true);
		// agsafeset(e, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(e, new CString("arrowhead"), new CString("none"), new CString(""));
		// Agedge_s e2 = agedge(g, n, m2, null, true);

		// EDGE cl0001->cl0002
		// EDGE cl0001->cl0004
		// EDGE cl0002->cl0004
		Agedge_s e0_1 = createEdge(g, a0, a1);
		Agedge_s e0_2 = createEdge(g, a0, a2);
		Agedge_s e0_3 = createEdge(g, a0, a3);
		Agedge_s e2_4 = createEdge(g, a2, a4);
		Agedge_s e3_5 = createEdge(g, a3, a5);
		Agedge_s e4_5 = createEdge(g, a4, a5);

		// System.err.println("m=" + m2);
		// System.err.println("e=" + e);

		// /* Set an attribute - in this case one that affects the visible rendering */
		// agsafeset(n, new CString("color"), new CString("red"), new CString(""));

		GVC_s gvc = gvContext();

		/* Compute a layout using layout engine from command line args */
		gvLayoutJobs(gvc, g);

		// DemoUtils.printDebugNode(cl0001);
		// DemoUtils.printDebugNode(cl0002);
		// DemoUtils.printDebugNode(cl0004);
		// DemoUtils.printDebugEdge(e1);
		// DemoUtils.printDebugEdge(e2);
		// DemoUtils.printDebugEdge(e3);

		final Graphic graphic = new Graphic();

		for (Agnode_s n : nodes) {
			graphic.addNode(n);
		}
		for (Agedge_s e : edges) {
			graphic.addEdge(e);
		}

		// graphic.addNode(cl0001);
		// graphic.addNode(cl0002);
		// graphic.addNode(cl0004);
		// graphic.addSplines(e1);
		// graphic.addSplines(e2);
		// graphic.addSplines(e3);
		graphic.drawTo(new File("out.png"));

	}

}
