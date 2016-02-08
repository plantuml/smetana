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
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

import org.anarres.cpp.Main;

public class PreprocFileC {
	private final String path;

	public PreprocFileC(String f) {
		if (new File(f).exists() == false) {
			throw new IllegalArgumentException();
		}
		this.path = f;
	}

	public void process() throws Exception {
		final List<String> arg = new ArrayList<String>();
		arg.add("-DHAVE_CONFIG_H");
		addPath(arg);
		arg.add("-DDOT_ONLY");
		addPath(arg);
		arg.add("-D__STD_C");
		addPath(arg);
		arg.add("-D_BEGIN_EXTERNS_");
		addPath(arg);
		arg.add("-D_I_AM_JAVA_");
		addPath(arg);
		arg.add(path);
		System.err.println(arg);
		PrintStream old = System.out;
		final String newFile = "k" + path;
		new File(newFile).getParentFile().mkdirs();
		PrintStream ps = new PrintStream(newFile);
		System.setOut(ps);
		Main.main(arg.toArray(new String[0]));
		ps.close();
		System.setOut(old);
	}

	// Add all .h directory for preprocessor
	private void addPath(List<String> arg) {
		for (File f : new File(PreprocDirC.GRAPHVIZ_2_38_0 + "/lib").listFiles()) {
			if (f.isDirectory()) {
				arg.add("-I");
				arg.add(PreprocDirC.GRAPHVIZ_2_38_0 + "/lib/" + f.getName());
			}
		}
	}

	// public static void main(String[] args) throws Exception {
	// FileC fc = new FileC("graphviz-2.28.0/lib/dotgen2/dotinit.c");
	// fc.process();
	// }

}
