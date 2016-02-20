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

public class Demo12 {

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

	private static Agnode_s createNode(Agraph_s g, String name) {
		Agnode_s result = agnode(g, new CString(name), true);
		String width = "1";
		String height = "1";
		// agsafeset(result, new CString("shape"), new CString("box"), new CString(""));
		// agsafeset(result, new CString("width"), new CString(width), new CString(""));
		// agsafeset(result, new CString("height"), new CString(height), new CString(""));
		return result;
	}

	private static void work(Agraph_s g) {
		Agnode_s n = createNode(g, "n");
		Agnode_s m = createNode(g, "m");
		Agnode_s p = createNode(g, "p");

		Agedge_s e1 = agedge(g, n, m, null, true);
		Agedge_s e2 = agedge(g, n, p, null, true);

		agsafeset(e1, new CString("label"), Macro.createHackInitDimensionFromLabel(236, 117), new CString(""));
		agsafeset(e2, new CString("label"), Macro.createHackInitDimensionFromLabel(236, 117), new CString(""));

		GVC_s gvc = gvContext();

		gvLayoutJobs(gvc, g);

		// DebugUtils.printDebugNode(n);
		// DebugUtils.printDebugNode(m);
		DebugUtils.printDebugEdge(e1);
		DebugUtils.printDebugEdge(e2);

		final Graphic graphic = new Graphic();
		graphic.addNode(n);
		graphic.addNode(m);
		graphic.addNode(p);
		graphic.addEdge(e1);
		graphic.addEdge(e2);
		graphic.drawTo(new File("out.png"));

	}

}
