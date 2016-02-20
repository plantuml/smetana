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

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import smetana.core.JUtils;

public class MethodArguments {

	private final List<MethodArgument> args = new ArrayList<MethodArgument>();

	public MethodArguments(String strings, List<String> list) {
		strings = strings.trim();
		if (strings.equals("void")) {
			return;
		}
		if (strings.matches("(\\w+\\s*)(,\\s*\\w+\\s*)*")) {
			JUtils.LOG("Strings1=" + strings);
			strings = rebuild(list);
			JUtils.LOG("Strings2=" + strings);
		}
		strings = strings.replaceAll("\\((\\*\\w+)\\)", "$1");
		strings = strings.replaceAll("\\([^()]*\\)", "").trim();

		if (strings.length() > 0) {
			for (String s : strings.split(",")) {
				args.add(new MethodArgument(s.trim()));
			}
		}

	}

	private String rebuild(List<String> subList) {
		final StringBuilder sb = new StringBuilder();
		for (int i = 0; i < subList.size(); i++) {
			String s;
			if (i == 0) {
				s = subList.get(i).replace('\n', ' ').trim();
				final int x = s.indexOf(')');
				if (x == -1) {
					throw new IllegalStateException();
				}
				s = s.substring(x + 1);
			} else {
				s = subList.get(i).trim();
			}
			if (s.equals(";")) {
				continue;
			}
			if (s.equals("")) {
				continue;
			}
			if (s.equals("{")) {
				return sb.toString();
			}
			JUtils.LOG("s22=" + s);
			if (sb.length() > 0) {
				sb.append(", ");
			}
			sb.append(s);
			sb.append(" ");
		}
		throw new IllegalStateException();
	}

	@Override
	public String toString() {
		return args.toString();
	}

	public Iterator<MethodArgument> argumentsIterator() {
		return args.iterator();
	}

	public boolean hasStruct() {
		for (MethodArgument arg : args) {
			if (arg.hasStruct()) {
				return true;
			}
		}
		return false;
	}

}
