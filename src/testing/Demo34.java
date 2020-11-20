/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2020, Arnaud Roques
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
package testing;

import static gen.lib.cgraph.attr__c.agsafeset;
import static gen.lib.cgraph.edge__c.agedge;
import static gen.lib.cgraph.graph__c.agopen;
import static gen.lib.cgraph.node__c.agnode;
import static gen.lib.cgraph.subg__c.agsubg;
import static gen.lib.gvc.gvc__c.gvContext;
import static gen.lib.gvc.gvlayout__c.gvLayoutJobs;

import java.io.File;
import java.io.IOException;

import h.ST_Agedge_s;
import h.ST_Agnode_s;
import h.ST_Agraph_s;
import h.ST_GVC_s;
import smetana.core.CString;
import smetana.core.Macro;
import smetana.core.Z;
import testing.dot.Graphic;

public class Demo34 {

	public static void main(String[] args) throws IOException {

		Z.open();
		ST_Agraph_s g = agopen(new CString("g"), Z.z().Agdirected, null);
		try {
			work(g);
		} catch (Exception e) {
			e.printStackTrace();
		}
//		JUtilsDebug.printCallStack(new File("CALLTRACE.txt"));
//		JUtilsDebug.printMethods();

	}

	private static ST_Agnode_s createNode(ST_Agraph_s g, String name, String width, String height) {
		ST_Agnode_s result = agnode(g, new CString(name), true);
		// agsafeset(result, new CString("shape"), new CString("box"), new CString(""));
		agsafeset(result, new CString("width"), new CString(width), new CString(""));
		agsafeset(result, new CString("height"), new CString(height), new CString(""));
		return result;
	}

	private static ST_Agnode_s createNode(ST_Agraph_s g, String name) {
		ST_Agnode_s result = agnode(g, new CString(name), true);
		return result;
	}

	private static void work(ST_Agraph_s g) {

		final ST_Agraph_s cluster01 = agsubg(g, new CString("cluster01"), true);
		agsafeset(cluster01, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 10), new CString(""));
		ST_Agnode_s cl1 = createNode(cluster01, "cl1");
		ST_Agnode_s cl4 = createNode(cluster01, "cl4");
		ST_Agnode_s cl2 = createNode(cluster01, "cl2");
		ST_Agnode_s cl3 = createNode(cluster01, "cl3");
		ST_Agnode_s cl8 = createNode(cluster01, "cl8");
		ST_Agnode_s cl6 = createNode(cluster01, "cl6");
		ST_Agnode_s cl5 = createNode(cluster01, "cl5");
		ST_Agnode_s cl7 = createNode(cluster01, "cl7");

		ST_Agedge_s e1_4 = createEdge(g, cl1, cl4, 0);
		
		ST_Agedge_s e2_3 = createEdge(g, cl2, cl3, 0);
		
		ST_Agedge_s e2_4 = createEdge(g, cl2, cl4, 0);
		agsafeset(e2_4, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 11), new CString(""));
		
		ST_Agedge_s e8_6 = createEdge(g, cl8, cl6, 0);
		
		ST_Agedge_s e5_6 = createEdge(g, cl5, cl6, 0);
		
		ST_Agedge_s e5_4 = createEdge(g, cl5, cl4, 0);
		agsafeset(e5_4, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 12), new CString(""));
		
		ST_Agedge_s e6_8 = createEdge(g, cl6, cl8, 0);
		agsafeset(e6_8, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 13), new CString(""));
		
		ST_Agedge_s e7_6a = createEdge(g, cl7, cl6, 0);
		agsafeset(e7_6a, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 14), new CString(""));
		
		ST_Agedge_s e7_6b = createEdge(g, cl7, cl6, 0);
		
		ST_Agedge_s e8_3 = createEdge(g, cl8, cl3, 0);
		agsafeset(e8_3, new CString("label"), Macro.createHackInitDimensionFromLabel(10, 15), new CString(""));

		ST_GVC_s gvc = gvContext();
		// Debug.setOneNode(a);

		gvLayoutJobs(gvc, g);

		final Graphic graphic = new Graphic();
		graphic.addCluster(cluster01);
		graphic.addNode(cl1);
		graphic.addNode(cl4);
		graphic.addNode(cl2);
		graphic.addNode(cl3);
		graphic.addNode(cl8);
		graphic.addNode(cl6);
		graphic.addNode(cl5);
		graphic.addNode(cl7);
		graphic.addEdge(e1_4);
		graphic.addEdge(e2_3);
		graphic.addEdge(e2_4);
		graphic.addEdge(e8_6);
		graphic.addEdge(e5_6);
		graphic.addEdge(e5_4);
		graphic.addEdge(e6_8);
		graphic.addEdge(e7_6a);
		graphic.addEdge(e7_6b);
		graphic.addEdge(e8_3);
		graphic.drawTo(new File("out34.png"));

	}

	private static ST_Agedge_s createEdge(ST_Agraph_s g, ST_Agnode_s a0, ST_Agnode_s a1, int minlen) {
		ST_Agedge_s e1 = agedge(g, a0, a1, null, true);
		agsafeset(e1, new CString("minlen"), new CString("" + minlen), new CString(""));
		// agsafeset(e1, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(e1, new CString("arrowhead"), new CString("none"), new CString(""));
		return e1;
	}

}
