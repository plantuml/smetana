package demo;

import static gen.lib.cgraph.edge__c.agedge;
import static gen.lib.cgraph.graph__c.Agdirected;
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
import smetana.core.JUtils;
import smetana.core.debug.Debug;
import demo.graphic.Graphic;

public class Demo02 {

	public static void main(String[] args) throws IOException {

		Agraph_s g = agopen(new CString("g"), Agdirected, null);
		try {
			work(g);
		} catch (Exception e) {
			e.printStackTrace();
		}
		JUtils.printCallStack(new File("CALLTRACE.txt"));
		JUtils.printMethods();

	}

	private static void work(Agraph_s g) {
		Agnode_s n = agnode(g, new CString("n"), true);
		Agnode_s m = agnode(g, new CString("m"), true);
		Agnode_s m2 = agnode(g, new CString("m2"), true);
		Agedge_s e = agedge(g, n, m, null, true);
		Agedge_s e2 = agedge(g, n, m2, null, true);
		System.err.println("n=" + n);
		System.err.println("m=" + m);
		// System.err.println("m=" + m2);
		System.err.println("e=" + e);

		// /* Set an attribute - in this case one that affects the visible rendering */
		// agsafeset(e, new CString("arrowtail"), new CString("none"), new CString(""));
		// agsafeset(e, new CString("arrowhead"), new CString("none"), new CString(""));
		// agsafeset(n, new CString("color"), new CString("red"), new CString(""));

		GVC_s gvc = gvContext();
		Debug.setOneEdge(e);

		/* Compute a layout using layout engine from command line args */
		gvLayoutJobs(gvc, g);

		DemoUtils.printDebugNode(n);
		DemoUtils.printDebugNode(m);
		DemoUtils.printDebugNode(m2);
		DemoUtils.printDebugEdge(e);
		DemoUtils.printDebugEdge(e2);

		final Graphic graphic = new Graphic(640, 320);
		graphic.addSplines(e);
		graphic.addSplines(e2);
		graphic.drawTo(new File("out.png"));
	}

}
