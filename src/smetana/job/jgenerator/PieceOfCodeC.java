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

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

import smetana.job.Signer;

public class PieceOfCodeC {

	private final List<String> raw = new ArrayList<String>();

	final protected void addRaw(String s) {
		raw.add(s);
	}

	final public List<String> getRaw() {
		return Collections.unmodifiableList(raw);
	}

	final protected String getCompactString() {
		final StringBuilder sb = new StringBuilder();
		for (String s : raw) {
			if (s.startsWith("//")) {
				continue;
			}
			if (s.startsWith("/*")) {
				continue;
			}
			s = s.replace('\n', ' ');
			sb.append(s);
		}
		return sb.toString();
	}

	final protected String getSignature() {
		final Signer signer = new Signer();
		signer.addLine(getCompactString().replaceAll("\\s", ""));
		return signer.getSignature();
	}

	private static final Set<File> alreadyCreated = new HashSet<File>();

	protected String getFolderName() {
		return "ctoj3";
	}

	final protected void exportJavaFromCtoj(PrintWriter pw) throws IOException {
		final BufferedReader br = new BufferedReader(new FileReader(getCtojFile()));
		final List<String> m = new ArrayList<String>();
		String s;
		while ((s = br.readLine()) != null) {
			if (s.startsWith("!!!!!")) {
				export(pw, m);
				br.close();
				return;
			}
			m.add(s);
		}
		br.close();
		throw new IllegalStateException();
	}

	private void export(PrintWriter pw, List<String> m) {
		for (String s : addTrace(m)) {
			pw.println(s);
		}
	}

	protected List<String> addTrace(List<String> m) {
		return m;
	}

	final protected File getCtojFile() {
		return new File(getFolderName(), getSignature() + ".ctoj");
	}

	final protected void createCtojFile() throws IOException {
		if (getCtojFile().exists()) {
			return;
		}
		final File tmpFile = getFileTmp();
		if (alreadyCreated.contains(tmpFile)) {
			return;
		}
		alreadyCreated.add(tmpFile);
		tmpFile.getParentFile().mkdirs();
		final PrintWriter pw = new PrintWriter(tmpFile);

		createCtojFileSuppData(pw);
		pw.println();
		pw.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		final StringBuilder code = new StringBuilder();
		for (String s : getRaw()) {
			code.append(s);
		}
		final StringTokenizer st = new StringTokenizer(code.toString(), "\n");
		while (st.hasMoreTokens()) {
			final String s = st.nextToken();
			if (s.matches("^\\s*$")) {
				continue;
			}
			pw.println(s);
		}
		pw.println();
		pw.close();
	}

	protected File getFileTmp() {
		return new File(getFolderName(), getSignature() + ".tmp");
	}

	protected void createCtojFileSuppData(PrintWriter pw) throws IOException {
	}

}
