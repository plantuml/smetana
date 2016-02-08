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

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import smetana.job.Signer;

public class Method extends PieceOfCodeC {

	@Override
	protected void createCtojFileSuppData(PrintWriter pw) throws IOException {
		final String methodName = getMethodName();
		pw.println("public static Object " + methodName + "(Object... arg) {");
		exportCode(pw);
		pw.println("throw new UnsupportedOperationException();");
		pw.println("}");
	}

	private void exportCode(PrintWriter pw) {
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
			pw.println("UNSUPPORTED(\"" + getLineSignature(s) + "\"); // " + s);
		}
		pw.println();
	}

	private String getLineSignature(String line) {
		final Signer signer = new Signer();
		signer.addLine(line);
		return signer.getSignature();
	}

	public Method(String s, Iterator<String> it) {
		if (CFile.TRACE) {
			System.err.println("STARTINGMETHOD");
		}
		addRaw(s);
		int level = 0;
		boolean exitAllowed = true;
		while (it.hasNext()) {
			if (level == 0 && s.matches("[\\s\\S]*\\)[\\s\\S]*\\w")) {
				exitAllowed = false;
			}
			if (CFile.TRACE) {
				System.err.println("s11=" + s);
			}
			s = it.next();
			if (level == 0 && s.matches("[\\s\\S]*\\)[\\s\\S]*\\w")) {
				exitAllowed = false;
			}
			addRaw(s);
			if (s.equals("{")) {
				level++;
				exitAllowed = true;
			} else if (s.equals("}")) {
				level--;
			}
			if (exitAllowed && level == 0 && (s.equals(";") || s.equals("}"))) {
				if (CFile.TRACE) {
					System.err.println("ENDING");
				}
				return;
			}
		}
	}

	private MethodWrapping getMethodWrapping() {
		return MethodWrapping.create(getMethodName(), getRaw());
	}

	public String getMethodName() {
		final Pattern p = Pattern.compile("\\b(\\w+)\\s*\\(");
		final Matcher m = p.matcher(getRaw().get(0));
		if (m.find() == false) {
			System.err.println("error " + getRaw());
			// return "NOTFOUND";
			throw new IllegalStateException(getRaw().get(0));
		}
		final String result = m.group(1);
		if (result.equals("clone")) {
			return result + "_";
		}
		return result;

	}

	public String toString() {
		return getRaw().get(0);
	}

	public boolean containsBody() {
		for (String s : getRaw()) {
			if (s.contains("{")) {
				return true;
			}
		}
		return false;
	}

	public StaticVarInit convertToStaticVarInit() {
		return new StaticVarInit(getRaw());
	}

	private String extractName(String line) {
		final int x = line.indexOf('(');
		if (x == -1) {
			throw new IllegalArgumentException(line);
		}
		line = line.substring(0, x);
		final String[] split = line.split(" ");
		line = split[split.length - 1];
		if (line.startsWith("*")) {
			line = line.substring(1);
		}
		return line;
	}

	private int firstTabLine(List<String> m) {
		for (int i = 0; i < m.size(); i++) {
			final String s = m.get(i);
			if (isSpaceChar(s.charAt(0))) {
				return i;
			}
		}
		throw new IllegalArgumentException();
	}

	private boolean isSpaceChar(char c) {
		return c == ' ' || c == '\t';
	}

	@Override
	protected List<String> addTrace(List<String> m) {

		for (String s : m) {
			checkThatStructCreationAreFinal(s);
		}

		while (m.get(m.size() - 1).length() == 0) {
			m = m.subList(0, m.size() - 1);
		}
		final String methodName = extractName(getRaw().get(0).replace('\n', ' '));
		// System.err.println("PieceOfCodeC::addTrace " + getSignature() + " " + methodName);
		// if (methodName.equals("aginit")) {
		// System.err.println("FOR SOME REASON, WE QUIT " + methodName);
		// return m;
		// }
		final List<String> result = new ArrayList<String>();
		final int firstTabLine = firstTabLine(m);
		if (firstTabLine == 0) {
			throw new IllegalStateException();
		}
		for (int i = 0; i < firstTabLine; i++) {
			result.add(m.get(i));
		}

		final MethodWrapping methodWrapping = getMethodWrapping();
		if (methodWrapping != null) {
			checkThatArgsWithStructAreFinal(m.get(firstTabLine - 1));
			result.add("// WARNING!! STRUCT");
			final StringBuilder sb = new StringBuilder();
			if (methodWrapping.isReturnVoid()) {
				sb.append(getMethodName() + "_w_(");
			} else {
				sb.append("return " + getMethodName() + "_w_(");
			}
			for (Iterator<MethodArgument> it = methodWrapping.argumentsIterator(); it.hasNext();) {
				final MethodArgument arg = it.next();
				sb.append(arg.getName());
				if (arg.hasStruct()) {
					sb.append(".copy()");
				}
				if (it.hasNext()) {
					sb.append(", ");
				}
			}
			sb.append(")");
			if (methodWrapping.doesReturnStruct()) {
				sb.append(".copy()");
			}
			sb.append(";");
			result.add("" + sb);
			result.add("}");
			String declaration = m.get(firstTabLine - 1);
			declaration = declaration.replaceAll("\\b" + getMethodName() + "\\b", getMethodName() + "_w_");
			declaration = declaration.replaceAll("\\bpublic\\b", "private");
			result.add(declaration);
		}

		result.add("ENTERING(\"" + getSignature() + "\",\"" + methodName + "\");");
		result.add("try {");
		for (int i = firstTabLine; i < m.size() - 1; i++) {
			result.add(m.get(i));
		}
		final String last = m.get(m.size() - 1);
		if (last.equals("}") == false) {
			throw new IllegalArgumentException();
		}
		result.add("} finally {");
		result.add("LEAVING(\"" + getSignature() + "\",\"" + methodName + "\");");
		result.add("}");
		result.add(last);
		return result;
	}

	private void checkThatStructCreationAreFinal(String s) {
		s = s.trim();
		if (s.startsWith("__struct__")) {
			System.err.println("s=" + getCtojFile());
			throw new IllegalArgumentException("__struct__ must be final");
		}
	}

	private void checkThatArgsWithStructAreFinal(final String declaration) {
		final int idx = declaration.indexOf('(');
		if (idx == -1) {
			throw new IllegalArgumentException(getMethodName() + " " + declaration);
		}
		final String declarationArgs = declaration.substring(idx);
		final int cptFinal = countWord(declarationArgs, "final");
		final int cptStruct = countWord(declarationArgs, "__struct__");
		if (cptFinal != cptStruct) {
			System.err.println("toto2=" + declaration + " " + cptFinal + " " + cptStruct);
			throw new IllegalStateException("final and __struct__ not consistent for " + getMethodName());
		}

	}

	private int countWord(String full, String s) {
		final Pattern p = Pattern.compile("\\b" + s + "\\b");
		final Matcher m = p.matcher(full);
		int nb = 0;
		while (m.find()) {
			nb++;
		}
		return nb;
	}

	public void exportMe(PrintWriter pw) throws IOException {
		pw.println();
		pw.println();
		pw.println("//3 " + getSignature());
		pw.println("// " + getRaw().get(0).replace('\n', ' '));

		if (getCtojFile().exists()) {
			getFileTmp().delete();
			exportJavaFromCtoj(pw);
		} else {
			createCtojFile();
			createCtojFileSuppData(pw);
		}

		pw.println();
		pw.println();

	}

	public boolean isStaticVarInit() {
		final String compact = getCompactString();
		return compact.contains("(") == false;
	}

	public Set<String> getTokens() {
		final Set<String> result = new TreeSet<String>();
		for (String s : getRaw()) {
			final String clean = s.replace('\n', ' ').replace('\r', ' ');
			if (clean.matches("^\\s*$")) {
				continue;
			}
			addTokens(result, clean);
		}
		return result;

	}

	private static void addTokens(Set<String> result, String s) {
		final Pattern p = Pattern.compile("\\w+");
		final Matcher m = p.matcher(s);
		while (m.find()) {
			final String token = m.group(0);
			if (token.matches("\\d+") == false) {
				result.add(token);
			}
		}
	}

}
