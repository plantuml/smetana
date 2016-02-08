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
package smetana.job.jgenerator;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

import smetana.job.java2html.ConverterToHtml;

public class StaticVarInit extends PieceOfCodeC {

	private static final boolean DO_HTML_INIT = false;

	protected String getFolderName() {
		return "ctoj4";
	}

	public StaticVarInit(List<String> raw) {
		for (String s : raw) {
			addRaw(s);
		}
	}

	public StaticVarInit(String s, Iterator<String> it) {
		addRaw(s);
		int level = 0;
		while (it.hasNext()) {
			s = it.next();
			addRaw(s);
			if (s.equals("{")) {
				level++;
			} else if (s.equals("}")) {
				level--;
			}
			if (level == 0 && s.equals(";")) {
				return;
			}
		}
	}

	public void exportMe(PrintWriter pw) throws IOException {
		pw.println("//1 " + getSignature());
		pw.println("// " + getRaw().get(0).replace('\n', ' '));
		if (getCtojFile().exists()) {
			exportJavaFromCtoj(pw);
			if (DO_HTML_INIT) {
				outInitHtml();
			}
		} else {
			createCtojFile();
			createCtojFileSuppData(pw);
			pw.println();
			pw.println();

		}
	}

	@Override
	protected List<String> addTrace(List<String> m) {
		for (String s : m) {
			checkThatStructCreationAreFinal(s);
		}
		return m;
	}

	private void checkThatStructCreationAreFinal(String s) {
		s = s.trim();
		if (s.contains("__struct__") && s.contains("final ") == false) {
			System.err.println("s33=" + s);
			System.err.println("s44=" + getCtojFile());
			throw new IllegalArgumentException("__struct__ must be final");
		}

	}

	private static final File staticInitFile = new File("staticVarInit.html");

	static {
		if (DO_HTML_INIT)
			try {
				staticInitFile.delete();
				final BufferedWriter bw = getOut();
				bw.append("<html>\n");
				bw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
	}

	private void outInitHtml() throws IOException {
		final ConverterToHtml conv = new ConverterToHtml(getCtojFile());
		final BufferedWriter bw = getOut();
		bw.append("<hr>");
		bw.append("<code>" + getSignature() + "</code><br>");
		conv.exportCToHtml(bw);
		conv.exportJavaToHtml(bw);
		bw.close();
	}

	static private BufferedWriter getOut() throws IOException {
		final BufferedWriter bw = new BufferedWriter(new FileWriter(staticInitFile, true));
		return bw;
	}

}
