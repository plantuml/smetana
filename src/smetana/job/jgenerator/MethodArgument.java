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

public class MethodArgument {

	private final String full;
	private final String name;

	public MethodArgument(String s) {
		this.full = s.trim();
		final String split[] = s.split(" ");
		this.name = split[split.length - 1].replace('*', ' ').trim();
	}

	@Override
	public String toString() {
		return name + "={" + full + "}";
	}

	public String getName() {
		return name;
	}

	public boolean hasStruct() {
		if (full.equals("boxf rv[]")) {
			return false;
		}
		if (full.equals("pointf curve[4]")) {
			return false;
		}
		if (full.equals("boolean*inside")) {
			return false;
		}
		if (full.equals("void")) {
			return false;
		}
		if (full.equals("cx")) {
			return false;
		}
		if (full.equals("rx")) {
			return false;
		}
		if (full.endsWith(name) == false) {
			throw new IllegalStateException(name);
		}
		final String type = full.substring(0, full.length() - name.length()).trim();
		if (MethodWrapping.notStruct(type)) {
			return false;
		}
		// System.err.println("type=" + type);
		if (type.trim().length() == 0) {
			System.err.println("ERROR " + full);
		}
		return true;
	}

}
