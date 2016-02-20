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
