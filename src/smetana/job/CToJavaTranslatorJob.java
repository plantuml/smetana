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

package smetana.job;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

import smetana.job.jgenerator.CFile;

public class CToJavaTranslatorJob {

	public static final String KGRAPHVIZ_2_38_0 = "kgraphviz-2.38.0";
	final private File dir;

	private final Collection<String> skipping = Arrays.asList("grammar.c", "y.tab.c");

	public CToJavaTranslatorJob(File dir) {
		this.dir = dir;
	}

	public void process(List<String> classes) throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				if (f.getName().equals("dotgen2") == false) {
					new CToJavaTranslatorJob(f).process(classes);
				}
			} else if (f.isFile() && f.getName().endsWith(".c") && skipping.contains(f.getName()) == false) {
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
