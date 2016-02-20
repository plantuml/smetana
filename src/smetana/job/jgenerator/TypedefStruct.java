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

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TypedefStruct extends PieceOfCodeC {

	public static final String TYPEDEF_STRUCT = "typedef struct";
	public static final String TYPEDEF_UNION = "typedef union";

	// protected String getFolderName() {
	// return "ctoj1";
	// }

	public TypedefStruct(String s, Iterator<String> it) {
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

	private static Set<String> already = new HashSet<String>();

	public void exportMe() throws IOException {
		final String n = getClassName();
		if (already.contains(n)) {
			return;
		}
		already.add(n);
		createJavaFile();
		// createCtojFile();
	}

	private void createJavaFile() throws IOException {
		String path = "src/h";
		final File javaFile = new File(path, getClassName() + ".java");
		javaFile.getParentFile().mkdirs();
		final PrintWriter pw = new PrintWriter(javaFile);
		for (String s : License.getJavaHeader()) {
			pw.println(s);
		}
		pw.println("package h;");
		pw.println("import smetana.core.*;");
		pw.println("import java.util.Arrays;");
		pw.println("import java.util.List;");

		// pw.println("import core.*;");
		// pw.println("import core.annotation.*;");
		pw.println();
		pw.println("//2 " + getSignature());
		pw.println();
		// if (getCtojFile().exists()) {
		// exportJavaFromCtoj(pw);
		// } else {

		final List<String> def = getDefinitionWithoutPointVigule();
		boolean done = false;
		if (def.size() == 1) {
			final String uniq = def.get(0);
			final Matcher m1 = Pattern.compile("typedef\\s+struct\\s+(\\w+)\\s+(\\w+)").matcher(uniq);
			if (m1.find() && getClassName().equals(m1.group(1)) == false) {
				pw.println("public interface " + getClassName() + " extends " + m1.group(1) + " {");
				done = true;
			}
		}
		if (done == false) {
			pw.println("public interface " + getClassName() + " extends __ptr__ {");
		}
		pw.println("	public static List<String> DEFINITION = Arrays.asList(");
		for (int i = 0; i < def.size(); i++) {
			pw.print("\"" + def.get(i) + "\"");
			if (i < def.size() - 1) {
				pw.println(",");
			}
		}
		pw.println(");");

		// for (String s : def) {
		// pw.println("//" + s);
		// }
		//
		pw.println("}");
		// }
		pw.println();
		pw.print("// ");
		for (String s : getRaw()) {
			s = s.replaceAll("\n", "\n// ");
			pw.print(s);
		}
		pw.close();
	}

	private List<String> getDefinition() {
		final List<String> result = new ArrayList<String>();
		for (Iterator<String> it = new FileStringParser(getRaw()).iterator(); it.hasNext();) {
			String s = it.next();
			if (s.startsWith("/*")) {
				continue;
			}
			if (s.startsWith("//")) {
				continue;
			}
			if (s.matches("\\s*")) {
				continue;
			}
			s = s.replaceAll("[\n\r\t]", " ").trim();
			result.add(s);
		}
		return result;
	}

	private List<String> getDefinitionWithoutPointVigule() {
		final List<String> result = new ArrayList<String>();
		for (String s : getDefinition()) {
			if (s.equals(";") == false) {
				result.add(s);
			}
		}
		return result;
	}

	public String getClassName() {
		final Pattern p0 = Pattern.compile("typedef\\s+struct\\s+\\w+\\s+(\\w+)");
		final Matcher m0 = p0.matcher(getRaw().get(0));
		if (m0.find()) {
			return manageUppercase(m0.group(1));
		}
		final Pattern p1 = Pattern.compile("typedef\\s+struct\\s*\\w*\\s*\\{.+\\}\\s*(\\w+)\\s*;\\s*$");
		final Matcher m1 = p1.matcher(getCompactString());
		if (m1.find()) {
			return manageUppercase(m1.group(1));
		}
		final Pattern p3 = Pattern.compile("struct\\s+(\\w+)");
		final Matcher m3 = p3.matcher(getRaw().get(0));
		if (m3.find()) {
			return manageUppercase(m3.group(1));
		}
		final String last = getRaw().get(getRaw().size() - 2).trim();
		if (last.matches("^\\w+$")) {
			return manageUppercase(last);
		}
		final Pattern p4 = Pattern.compile("typedef\\s+.*\\(\\*(\\w+)\\)");
		final Matcher m4 = p4.matcher(getRaw().get(0));
		if (m4.find()) {
			return manageUppercase(m4.group(1));
		}
		System.err.println("err1");
		System.err.println(getRaw());
		throw new IllegalStateException();
	}

	private String manageUppercase(String s) {
		// multispline.c contains ipair and Ipair...
		// So we have to do something to upercase letter...
		if (s.equals("Ipair")) {
			return "_Ipair";
		}
		if (s.equals("Queue")) {
			return "_Queue";
		}
		if (s.equals("Block_t")) {
			return "_Block_t";
		}
		if (s.equals("Freeblock")) {
			return "_Freeblock";
		}
		if (s.equals("Freelist")) {
			return "_Freelist";
		}
		if (s.equals("Freenode")) {
			return "_Freenode";
		}
		if (s.equals("PtItem")) {
			return "_PtItem";
		}
		if (s.equals("Node_t")) {
			return "_Note_t___";
		}
		if (s.equals("Pair")) {
			return "_Pair";
		}
		if (s.equals("Point")) {
			return "_Point";
		}
		return s;
	}

}
