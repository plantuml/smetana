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
import smetana.core.Z;
import dot.Graphic;

public class Demo24 {

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
		agsafeset(result, new CString("shape"), new CString("box"), new CString(""));
		agsafeset(result, new CString("width"), new CString(width), new CString(""));
		agsafeset(result, new CString("height"), new CString(height), new CString(""));
		return result;
	}

	private static void work(Agraph_s g) {
		Agnode_s a0 = createNode(g, "a0", "0.6388888", "0.666666666");
		Agnode_s a1 = createNode(g, "a1", "0.6388888", "0.666666666");
		Agnode_s a3 = createNode(g, "a3", "0.6388888", "0.666666666");
		Agnode_s a4 = createNode(g, "a4", "0.6388888", "0.666666666");
		Agnode_s a5 = createNode(g, "a5", "0.6388888", "0.666666666");
		Agnode_s note = createNode(g, "n", "0.527777777777", "0.3659939236");
		Agedge_s e1 = createEdge(g, a0, a1, 1);
		Agedge_s e4 = createEdge(g, note, a4,  0);
		Agedge_s e2 = createEdge(g, a0, a3, 1);
		Agedge_s e3 = createEdge(g, a1, a5, 1);

		GVC_s gvc = gvContext();
		// Debug.setOneNode(a);

		gvLayoutJobs(gvc, g);

		// DebugUtils.printDebugNode(a);
		// DebugUtils.printDebugNode(b);

		final Graphic graphic = new Graphic();
		graphic.addNode(a0);
		graphic.addNode(a1);
		graphic.addNode(a3);
		graphic.addNode(a4);
		graphic.addNode(a5);
		graphic.addNode(note);
		graphic.addEdge(e1);
		graphic.addEdge(e2);
		graphic.addEdge(e3);
		graphic.addEdge(e4);
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
