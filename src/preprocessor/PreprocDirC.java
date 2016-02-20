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

public class PreprocDirC {

	public static final String GRAPHVIZ_2_38_0 = "graphviz-2.38.0";
	final private File dir;

	public PreprocDirC(File dir) {
		this.dir = dir;
	}

	public void process() throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new PreprocDirC(f).process();
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				new PreprocFileC(f.getPath()).process();
			}
		}

	}

	public static void main(String[] args) throws Exception {
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/lib")).process();
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/plugin")).process();
	}

}
