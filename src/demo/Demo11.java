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

import static gen.lib.cgraph.graph__c.agopen;
import h.Agraph_s;

import java.io.File;
import java.io.IOException;

import dot.Digraph;
import dot.Graphic;
import smetana.core.CString;
import smetana.core.JUtilsDebug;
import smetana.core.Z;

public class Demo11 {

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

	private static void work(Agraph_s g) {

		Digraph digraph = new Digraph();
		digraph.addString("cl0001 [shape=box, width=7.9, height=4.7]");
		digraph.addString("cl0002 [shape=box, width=0.6, height=0.6]");
		digraph.addString("cl0004 [shape=box, width=0.6, height=0.6]");
		digraph.addString("cl0002->cl0001");
		digraph.addString("cl0001->cl0004");
		digraph.addString("cl0002->cl0004");

		digraph.layout();

		DebugUtils.printDebugEdge(digraph.getEdge(2));

		final Graphic graphic = digraph.getGraphic();
		graphic.drawTo(new File("out.png"));

	}

}
