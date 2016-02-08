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
package smetana.job;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import smetana.job.jgenerator.CFile;

public class CToJavaTranslatorJob {

	public static final String KGRAPHVIZ_2_38_0 = "kgraphviz-2.38.0";
	final private File dir;

	public CToJavaTranslatorJob(File dir) {
		this.dir = dir;
	}

	public void process(List<String> classes) throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new CToJavaTranslatorJob(f).process(classes);
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				final CFile file = new CFile(f);
				file.toJavaFile();
				classes.add(file.getPackageName() + "." + file.getClassName());
			}
		}
	}

	public static void main(String[] args) throws Exception {
		final List<String> classes = new ArrayList<String>();
		new CToJavaTranslatorJob(new File(KGRAPHVIZ_2_38_0 + "/lib")).process(classes);
		new CToJavaTranslatorJob(new File(KGRAPHVIZ_2_38_0 + "/plugin")).process(classes);
		System.err.println("classes=" + classes.size());
	}

}
