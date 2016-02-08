/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net
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
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc.
 * in the United States and other countries.]
 *
 * Original Author:  Arnaud Roques
 * 
 */
package preprocessor;

import java.io.File;

public class PreprocDirC {

	public static final String GRAPHVIZ_2_38_0 = "graphviz-2.38.0";
	final private File dir;

	public PreprocDirC(File dir) {
		this.dir = dir;
	}

	public void process() throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new PreprocDirC(f).process();
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				new PreprocFileC(f.getPath()).process();
			}
		}

	}

	public static void main(String[] args) throws Exception {
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/lib")).process();
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/plugin")).process();
	}

}
