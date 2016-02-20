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
import smetana.core.Z;
import smetana.core.debug.Debug;
import dot.Graphic;

public class Demo09 {

	public static void main(String[] args) throws IOException {

		Agraph_s g = agopen(new CString("g"), Z._().Agdirected, null);
		try {
			work(g);
		} catch (Exception e) {
			e.printStackTrace();
		}
		JUtilsDebug.printCallStack(new File("CALLTRACE.txt"));
		JUtilsDebug.printMethods();

	}

	private static void work(Agraph_s g) {
		Agnode_s cl0001 = agnode(g, new CString("a"), true);
		Agnode_s cl0002 = agnode(g, new CString("b"), true);
		Agnode_s cl0004 = agnode(g, new CString("c"), true);
		// Agnode_s m2 = agnode(g, new CString("m2"), true);
		// Agedge_s e = agedge(g, n, m, null, true);
		// agsafeset(e, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(e, new CString("arrowhead"), new CString("none"), new CString(""));
		// Agedge_s e2 = agedge(g, n, m2, null, true);

		// EDGE cl0001->cl0002
		// EDGE cl0001->cl0004
		// EDGE cl0002->cl0004
		Agedge_s e1 = agedge(g, cl0001, cl0002, null, true);
		Agedge_s e2 = agedge(g, cl0001, cl0004, null, true);
		Debug.setOneEdge(e2);
		Agedge_s e3 = agedge(g, cl0002, cl0004, null, true);

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
		DebugUtils.printDebugEdge(e1);
		DebugUtils.printDebugEdge(e2);
		DebugUtils.printDebugEdge(e3);

		final Graphic graphic = new Graphic();
		graphic.addNode(cl0001);
		graphic.addNode(cl0002);
		graphic.addNode(cl0004);
		graphic.addEdge(e1);
		graphic.addEdge(e2);
		graphic.addEdge(e3);
		graphic.drawTo(new File("out.png"));

	}

}
