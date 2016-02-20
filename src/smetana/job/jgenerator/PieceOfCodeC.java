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
