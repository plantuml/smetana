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
package dot;

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

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import smetana.core.CString;
import smetana.core.Z;

public class Digraph {

	private static Map<String, Agnode_s> nodes = new LinkedHashMap<String, Agnode_s>();
	private static List<Agedge_s> edges = new ArrayList<Agedge_s>();
	private final Agraph_s g;

	public Digraph() {
		Z.open();
		g = agopen(new CString("g"), Z._().Agdirected, null);
	}

	public void addString(String s) {
		s = s.trim();
		if (s.startsWith("digraph {")) {
			// Do nothing
		} else if (s.equals("}")) {
			// Do nothing
		} else if (s.contains("->")) {
			addEdge(s);
		} else if (s.contains("[") && s.contains("]")) {
			addNode(s);
		}

	}

	public Agedge_s getEdge(int nb) {
		return edges.get(nb);
	}

	private void addNode(String s) {
		int x = s.indexOf("[");
		if (x == -1) {
			throw new IllegalArgumentException(s);
		}
		String name = s.substring(0, x - 1).trim();
		String shape = getValue(s, "shape");
		String width = getValue(s, "width");
		String height = getValue(s, "height");

		Agnode_s result = agnode(g, new CString(name), true);
		agsafeset(result, new CString("shape"), new CString(shape), new CString(""));
		agsafeset(result, new CString("width"), new CString(width), new CString(""));
		agsafeset(result, new CString("height"), new CString(height), new CString(""));

		nodes.put(name, result);
	}

	private String getValue(String s, String key) {
		int x = s.indexOf(key);
		if (x == -1) {
			throw new IllegalArgumentException(s);
		}
		s = s.substring(x + key.length());
		return s.split("[,\\[\\]=]")[1];
	}

	private void addEdge(String s) {
		String val[] = s.split("->");
		Agnode_s n = nodes.get(val[0]);
		Agnode_s m = nodes.get(val[1]);
		if (n == null || m == null) {
			throw new IllegalArgumentException(s);
		}
		Agedge_s result = agedge(g, n, m, null, true);
		// agsafeset(result, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(result, new CString("arrowhead"), new CString("none"), new CString(""));
		edges.add(result);

	}

	public void layout() {
		GVC_s gvc = gvContext();
		gvLayoutJobs(gvc, g);
	}

	public Graphic getGraphic() {
		final Graphic graphic = new Graphic();

		for (Agnode_s n : nodes.values()) {
			graphic.addNode(n);
		}
		for (Agedge_s e : edges) {
			graphic.addEdge(e);
		}
		return graphic;
	}

}
