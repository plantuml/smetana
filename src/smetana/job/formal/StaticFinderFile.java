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

package smetana.job.formal;

import java.io.File;
import java.lang.reflect.Field;

public class StaticFinderFile {

	private final File file;

	public StaticFinderFile(File file) {
		this.file = file;
	}

	public void analyze() throws ClassNotFoundException {
		String path = file.getAbsolutePath().replaceAll("[/\\\\]", ".");
		int idx = path.indexOf(".src.gen.");
		if (idx == -1) {
			throw new IllegalStateException();
		}
		path = path.substring(idx + 5);
		path = path.replaceAll("\\.java$", "");
		final Class cl = Class.forName(path);
		analyze(cl);
	}

	private void analyze(Class cl) {
//		boolean printed = false;
		for (Field f : cl.getDeclaredFields()) {
			if (f.getName().equals("jbuf")) {
				continue;
			}
			// if (printed == false) {
			// System.err.println("cl=" + cl);
			// printed = true;
			// }
			System.err.println("f=" + f);
		}

	}
}
