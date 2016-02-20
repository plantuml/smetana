/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
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

package smetana.core;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

import smetana.job.java2html.ConverterToHtml;

public class CallStack {

	final private Deque<String> stack = new ArrayDeque<String>();
	final private Set<String> already = new LinkedHashSet<String>();
	final private List<String> edges = new ArrayList<String>();
	final private List<String> nodes = new ArrayList<String>();

	public void entering(String signature, String methodName) {
		final String n = getDotNodeName(signature, methodName);
		final String from = stack.peekLast();
		stack.addLast(n);
		if (already.contains(n) == false) {
			if (from != null) {
				final String chain = from + " -> " + n;
				edges.add(chain);
			}
			already.add(n);
			nodes.add(n + "[label=\"" + methodName + "\\n" + signature + "\"];");
		}
	}

	private String getDotNodeName(String signature, String methodName) {
		return "X_" + signature + "_" + methodName;
	}

	private String extractSignature(String s) {
		final int x1 = s.indexOf("_");
		final int x2 = s.indexOf("_", x1 + 1);
		return s.substring(x1 + 1, x2);
	}

	private String extracFunctionName(String s) {
		final int x1 = s.indexOf("_");
		final int x2 = s.indexOf("_", x1 + 1);
		return s.substring(x2 + 1);
	}

	public void leaving(String signature, String methodName) {
		final String n = getDotNodeName(signature, methodName);
		final String out = stack.pollLast();
		if (out.equals(n) == false) {
			throw new IllegalStateException();
		}

	}

	public void printCallStack(PrintWriter pw) {
		for (String s : nodes) {
			pw.println(s);
		}
		for (String s : edges) {
			pw.println(s);
		}
	}

	public void printMethods() throws IOException {
		new File("htmltrace").mkdirs();
		final File dest2 = new File("htmltrace/index.html");
		final PrintWriter index = new PrintWriter(dest2);
		dest2.getParentFile().mkdirs();
		index.println("<html>");
		final List<String> already2 = new ArrayList<String>(already);
		index.println("<table border=1 cellspacing=0 cellpadding=2>");
		index.println("<tr>");
		index.println("<td>");
		index.println("ID");
		index.println("</td>");
		index.println("<td>");
		index.println("FUNCTION NAME");
		index.println("</td>");
		index.println("<td>");
		index.println("NB LINES");
		index.println("</td>");
		index.println("</tr>");
		for (int i = 0; i < already2.size(); i++) {
			index.println("<tr>");
			final String s = already2.get(i);
			final File ctoj = new File("ctoj3", extractSignature(s) + ".ctoj");
			final ConverterToHtml conv = new ConverterToHtml(ctoj);
			index.println("<td>");
			index.println("" + (i + 1) + "/" + already.size());
			index.println("</td>");
			index.println("<td>");
			index.println("<a href=" + getHtmlFileName(s) + ">");
			index.println(extracFunctionName(s));
			index.println("</a>");
			index.println("</td>");
			index.println("<td>");
			index.println(conv.nbJavaSourceLines());
			index.println("</td>");
			index.println("</tr>");

			outHtmlBoth(i, already2, conv);
			outHtmlJava(i, already2, conv);
		}
		index.println("</table>");
		index.println("<html>");
		index.close();

	}

	private void outHtmlJava(int i, final List<String> already, final ConverterToHtml conv) throws IOException {
		final String s = already.get(i);
		final BufferedWriter htmlJava = new BufferedWriter(new FileWriter(new File("htmltrace/"
				+ getHtmlJavaFileName(s))));
		htmlJava.append("<html>\n");
		final int total = already.size();
		htmlJava.append("<title>" + extracFunctionName(s) + "  " + (i + 1) + "/" + total + "</title>\n");
		if (i > 0) {
			writeLinkJava("PREV:", htmlJava, already.get(i - 1));
			htmlJava.append("" + (i + 1 - 1) + "/" + total);
			htmlJava.append("<br>\n");
		}
		if (i < already.size() - 1) {
			writeLinkJava("NEXT:", htmlJava, already.get(i + 1));
			htmlJava.append("" + (i + 1 + 1) + "/" + total);
			htmlJava.append("<br>\n");
		}
		htmlJava.append("<a href=index.html>index</a>\n");
		htmlJava.append("&nbsp;&nbsp;<code>" + extractSignature(s) + "</code>\n");
		htmlJava.append("<a href=" + getHtmlFileName(s) + ">C and Java</a>\n");
		conv.exportJavaToHtml(htmlJava);
		htmlJava.append("</html>\n");
		htmlJava.close();
	}

	private void outHtmlBoth(int i, final List<String> already, final ConverterToHtml conv) throws IOException {
		final String s = already.get(i);
		final int total = already.size();
		final BufferedWriter htmlBoth = new BufferedWriter(new FileWriter(new File("htmltrace/" + getHtmlFileName(s))));
		htmlBoth.append("<html>\n");
		htmlBoth.append("<title>" + extracFunctionName(s) + "  " + (i + 1) + "/" + total + "</title>\n");
		if (i > 0) {
			writeLink("PREV:", htmlBoth, already.get(i - 1));
			htmlBoth.append("" + (i + 1 - 1) + "/" + total);
			htmlBoth.append("<br>\n");
		}
		if (i < already.size() - 1) {
			writeLink("NEXT:", htmlBoth, already.get(i + 1));
			htmlBoth.append("" + (i + 1 + 1) + "/" + total);
			htmlBoth.append("<br>\n");
		}
		htmlBoth.append("<a href=index.html>index</a>\n");
		htmlBoth.append("&nbsp;&nbsp;<code>" + extractSignature(s) + "</code>\n");
		htmlBoth.append("<a href=" + getHtmlJavaFileName(s) + ">Java</a>\n");

		final boolean twoCols = conv.nbJavaSourceLines() > 25;
		if (twoCols) {
			htmlBoth.append("<table width=100% valign=top>\n");
			htmlBoth.append("<tr width=100% valign=top>\n");
			htmlBoth.append("<td width=50%>\n");
			conv.exportCToHtml(htmlBoth);

			htmlBoth.append("</td>\n");
			htmlBoth.append("<td width=50%>\n");
			conv.exportJavaToHtml(htmlBoth);

			htmlBoth.append("</td>\n");
			htmlBoth.append("</tr>\n");
			htmlBoth.append("</table>\n");
		} else {
			conv.exportCToHtml(htmlBoth);
			htmlBoth.append("<hr>\n");
			conv.exportJavaToHtml(htmlBoth);

		}

		htmlBoth.append("</html>\n");
		htmlBoth.close();
	}

	private void writeLink(String title, BufferedWriter writer, String fullSignature) throws IOException {
		writer.append("<a href=" + getHtmlFileName(fullSignature) + ">" + title + "&nbsp;"
				+ extracFunctionName(fullSignature) + "</a>\n");
	}

	private void writeLinkJava(String title, BufferedWriter writer, String fullSignature) throws IOException {
		writer.append("<a href=" + getHtmlJavaFileName(fullSignature) + ">" + title + "&nbsp;"
				+ extracFunctionName(fullSignature) + "</a>\n");
	}

	private String getHtmlFileName(final String s) {
		return s + ".html";
	}

	private String getHtmlJavaFileName(final String s) {
		return "J_" + s.substring(2) + ".html";
	}

}
