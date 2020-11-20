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
package testing.dot;

import static gen.lib.cgraph.attr__c.agsafeset;
import static gen.lib.cgraph.edge__c.agedge;
import static gen.lib.cgraph.graph__c.agopen;
import static gen.lib.cgraph.node__c.agnode;
import static gen.lib.cgraph.subg__c.agsubg;
import static gen.lib.gvc.gvc__c.gvContext;
import static gen.lib.gvc.gvlayout__c.gvLayoutJobs;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Deque;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import h.ST_Agedge_s;
import h.ST_Agnode_s;
import h.ST_Agraph_s;
import h.ST_GVC_s;
import smetana.core.CString;
import smetana.core.Z;

public class Digraph {

	private Map<String, ST_Agnode_s> nodes = new LinkedHashMap<String, ST_Agnode_s>();
	private List<ST_Agedge_s> edges = new ArrayList<ST_Agedge_s>();
	private Collection<ST_Agraph_s> clusters = new ArrayList<ST_Agraph_s>();
	private final ST_Agraph_s graph;
	private final Deque<ST_Agraph_s> currents = new LinkedList<ST_Agraph_s>();

	public Digraph() {
		Z.open();
		graph = agopen(new CString("g"), Z.z().Agdirected, null);
		currents.addLast(graph);
	}

	public void addString(String s) {
		s = s.trim();
		if (s.startsWith("digraph")) {
			// Do nothing
		} else if (s.startsWith("subgraph")) {
			openSubgraph(s);
		} else if (s.equals("}")) {
			closeBracket();
		} else if (s.contains("->")) {
			addEdge(s);
		} else if (s.matches("\\w+\\s*;?")) {
			addNodeSimple(s);
		} else if (s.contains("[") && s.contains("]")) {
			addNode(s);
		}

	}

	private void closeBracket() {
		currents.removeLast();
	}

	private void openSubgraph(String s) {
		String name = s.split("\\W")[1];
		final ST_Agraph_s subcluster = agsubg(currents.getLast(), new CString(name), true);
		clusters.add(subcluster);
		currents.addLast(subcluster);
	}

	public ST_Agedge_s getEdge(int nb) {
		return edges.get(nb);
	}

	private void addNodeSimple(String s) {
		String name = s.replaceAll("\\W", "");
		ST_Agnode_s result = agnode(currents.getLast(), new CString(name), true);
		nodes.put(name, result);
	}

	private void addNode(String s) {
		int x = s.indexOf("[");
		if (x == -1) {
			throw new IllegalArgumentException(s);
		}
		int y = s.indexOf("]", x + 1);
		String name = s.substring(0, x - 1).trim();
		ST_Agnode_s result = agnode(currents.getLast(), new CString(name), true);
		String options[] = s.substring(x + 1, y).split(",");
		for (String op : options) {
			String option[] = op.trim().split("=");
			addNodeOption(result, option[0].trim(), option[1].trim());
		}
		// String shape = getValue(s, "shape");
		// String width = getValue(s, "width");
		// String height = getValue(s, "height");
		//
		// agsafeset(result, new CString("shape"), new CString(shape), new CString(""));
		// agsafeset(result, new CString("width"), new CString(width), new CString(""));
		// agsafeset(result, new CString("height"), new CString(height), new CString(""));

		nodes.put(name, result);
	}

	// private String getValue(String s, String key) {
	// int x = s.indexOf(key);
	// if (x == -1) {
	// throw new IllegalArgumentException(s);
	// }
	// s = s.substring(x + key.length());
	// return s.split("[,\\[\\]=]")[1];
	// }

	private void addNodeOption(ST_Agnode_s node, String key, String value) {
		agsafeset(node, new CString(key), new CString(value), new CString(""));
	}

	private void addEdge(String s) {
		String val[] = s.split("->|;|\\[|\\]|,");
		ST_Agnode_s n = nodes.get(val[0].trim());
		ST_Agnode_s m = nodes.get(val[1].trim());
		if (n == null || m == null) {
			throw new IllegalArgumentException(s);
		}
		//Agedge_s result = agedge(currents.getLast(), n, m, null, true);
		ST_Agedge_s result = agedge(graph, n, m, null, true);
		for (int i = 2; i < val.length; i++) {
			String option[] = val[i].trim().split("=");
			addEdgeOption(result, option[0].trim(), option[1].trim());
		}
		// agsafeset(result, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(result, new CString("arrowhead"), new CString("none"), new CString(""));
		edges.add(result);

	}

	private void addEdgeOption(ST_Agedge_s edge, String key, String value) {
		agsafeset(edge, new CString(key), new CString(value), new CString(""));
	}

	public void layout() {
		ST_GVC_s gvc = gvContext();
		gvLayoutJobs(gvc, graph);
	}

	public Graphic getGraphic() {
		final Graphic graphic = new Graphic();

		for (ST_Agnode_s n : nodes.values()) {
			graphic.addNode(n);
		}
		for (ST_Agedge_s e : edges) {
			graphic.addEdge(e);
		}
		for (ST_Agraph_s c : clusters) {
			graphic.addCluster(c);
		}
		return graphic;
	}

}
