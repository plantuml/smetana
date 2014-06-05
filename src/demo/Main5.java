package demo;

import static gen.lib.cgraph.edge.*;
import static gen.lib.cgraph.graph.*;
import static gen.lib.cgraph.node.*;
import static gen.lib.common.args.*;
import static gen.lib.gvc.gvc.*;
import h.Agedge_t;
import h.Agnode_t;
import h.Agraph_t;
import h.GVC_t;
import core.JUtils;
import core.Memory;
import core.StarStarChar;
public class Main5 {
	/**
	 * Create a empty graph
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		GVC_t gvc = gvContext();
		
		int argc = 0;
		StarStarChar argv = Memory.mallocStarStarChar(1);
		
		gvParseArgs(gvc, argc, argv);

		
		Agraph_t g = agopen(JUtils.asStarChar("g"), Agdirected, null);
		Agnode_t n = agnode(g, JUtils.asStarChar("n"), true);
		Agnode_t m = agnode(g, JUtils.asStarChar("m"), true);
		Agedge_t e = agedge(g, n, m, null, false);
		// /* Set an attribute - in this case one that affects the visible rendering */
		// agsafeset(n, "color", "red", "");
		// /* Compute a layout using layout engine from command line args */
		//gen.gvc.gvlayout.gvLayoutJobs(gvc, g);
		int rc = gvLayout(gvc, g, JUtils.asStarChar("dot"));
		System.err.println("rc="+rc);

	}

	// int main(int argc, char **argv)
	// {
	// Agraph_t *g;
	// Agnode_t *n, *m;
	// Agedge_t *e;
	// Agsym_t *a;
	// GVC_t *gvc;
	// /* set up a graphviz context */
	// gvc = gvContext();
	// /* parse command line args - minimally/* Create a simple digraph */
	// g = agopen("g", Agdirected);
	// n = agnode(g, "n", 1);
	// m = agnode(g, "m", 1);
	// e = agedge(g, n, m, 0, 1);
	// /* Set an attribute - in this case one that affects the visible rendering */
	// agsafeset(n, "color", "red", "");
	// /* Compute a layout using layout engine from command line args */
	// gvLayoutJobs(gvc, g);
	// /* Write the graph according to -T and -o options */
	// gvRenderJobs(gvc, g);
	// /* Free layout data */
	// gvFreeLayout(gvc, g);
	// /* Free graph structures */
	// agclose(g);
	// /* close output file, free context, and return number of errors */
	// return (gvFreeContext(gvc));
	// }

}
