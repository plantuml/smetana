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

public class JavaSourceDir {

	private final File dir;

	public JavaSourceDir(File dir) {
		this.dir = dir;
	}

	public static void main(String[] args) throws IOException {
		new JavaSourceDir(new File("src/demo")).process();
		new JavaSourceDir(new File("src/dot")).process();
		new JavaSourceDir(new File("src/preprocessor")).process();
		new JavaSourceDir(new File("src/smetana/core")).process();
		new JavaSourceDir(new File("src/smetana/core/amiga")).process();
		new JavaSourceDir(new File("src/smetana/core/debug")).process();
		new JavaSourceDir(new File("src/smetana/job")).process();
		new JavaSourceDir(new File("src/smetana/job/formal")).process();
		new JavaSourceDir(new File("src/smetana/job/java2html")).process();
		new JavaSourceDir(new File("src/smetana/job/jgenerator")).process();
	}

	private void process() throws IOException {
		for (File f : dir.listFiles()) {
			if (f.getName().endsWith(".java") == false) {
				continue;
			}
			new JavaSourceFile(f).process();
		}
	}
}
