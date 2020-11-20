/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2020, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
 * 
 * If you like this project or if you find it useful, you can support us at:
 * 
 * http://plantuml.com/patreon (only 1$ per month!)
 * http://plantuml.com/paypal
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 */
package testing.dot;

import static gen.lib.cgraph.attr__c.agsafeset;
import static gen.lib.cgraph.edge__c.agedge;
import static gen.lib.cgraph.graph__c.agopen;
import static gen.lib.cgraph.node__c.agnode;
import static gen.lib.gvc.gvc__c.gvContext;
import static gen.lib.gvc.gvlayout__c.gvLayoutJobs;

import java.io.File;

import h.ST_Agedge_s;
import h.ST_Agnode_s;
import h.ST_Agnodeinfo_t;
import h.ST_Agraph_s;
import h.ST_GVC_s;
import h.ST_field_t;
import smetana.core.CString;
import smetana.core.JUtilsDebug;
import smetana.core.Macro;
import smetana.core.Z;
import smetana.core.__ptr__;

public class MainDot7 {

	public static void main(String[] args) {


/**
		@startuml
		digraph structs {
		    struct1 [shape=record, label="<f0> left|<f1> middle|<f2> right"];
		    struct2 [shape=record, label="<f0> one|<f1> two"];
		    struct3 [shape=record, label="helloworld |{ b |{c|<here> d|e}| f}| g | h"];
		    struct1:f1 -> struct2:f0;
		    struct1:f2 -> struct3:here;
		}
		@enduml
		*/
		// See CucaDiagramFileMakerJDot
		Z.open();
		try {
			final ST_Agraph_s g = agopen(new CString("g"), Z.z().Agdirected, null);

			final ST_Agnode_s agnode1 = agnode(g, new CString("node1"), true);
			agsafeset(agnode1, new CString("shape"), new CString("box"), new CString(""));

			final ST_Agnode_s agnode3 = agnode(g, new CString("node3"), true);
			agsafeset(agnode3, new CString("shape"), new CString("record"), new CString(""));
			agsafeset(agnode3, new CString("label"), new CString("{ b | <here> d }"),
					new CString(""));

			// source -> target [tailport=sourceport, headport=targetport]

			// struct1:f2 -> struct3:here
			final ST_Agedge_s edge3 = agedge(g, agnode1, agnode3, null, true);
			// System.err.println("createEdge " + link);
			agsafeset(edge3, new CString("arrowtail"), new CString("none"), new CString(""));
			agsafeset(edge3, new CString("arrowhead"), new CString("none"), new CString(""));
//			agsafeset(edge3, new CString("tailport"), new CString("f2"), new CString(""));
			agsafeset(edge3, new CString("headport"), new CString("here"), new CString(""));
			// agsafeset(edge3, new CString("minlen"), new CString("1"), new CString(""));

			final ST_GVC_s gvc = gvContext();
			JUtilsDebug.reset();
			gvLayoutJobs(gvc, g);
			JUtilsDebug.printMe();




			Graphic graphic = new Graphic();
			graphic.addNode(agnode1);
			graphic.addNode(agnode3);
			graphic.addEdge(edge3);
			final File out = new File("maindot3.png");
			System.err.println("out=" + out.getAbsolutePath());
			graphic.drawTo(out);

		} finally {
			Z.close();
		}

	}

}
