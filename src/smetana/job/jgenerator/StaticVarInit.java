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

	private static final boolean DO_HTML_INIT = true;

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
