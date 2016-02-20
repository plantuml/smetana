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

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class FormalMethod implements Comparable<FormalMethod> {

	private static final List<FormalMethod> all = new ArrayList<FormalMethod>();

	public static void register(String pack, String file, String name, String[] tokens) {
		final FormalMethod formalMethod = new FormalMethod(pack, file, name, tokens);
		all.add(formalMethod);
	}

	final private String pack;
	final private String file;
	final private String methodName;

	final private Set<String> tokens = new HashSet<String>();

	@Override
	public String toString() {
		return pack + " - " + file + " - " + methodName;
	}

	public int compareTo(FormalMethod other) {
		int ret = pack.compareTo(other.pack);
		if (ret != 0) {
			return ret;
		}
		ret = file.compareTo(other.file);
		if (ret != 0) {
			return ret;
		}
		ret = methodName.compareTo(other.methodName);
		return ret;
	}

	public FormalMethod(String pack, String file, String name, String[] tokensArg) {
		this.pack = pack;
		this.file = file;
		this.methodName = name;
		for (String t : tokensArg) {
			if (t.length() > 0) {
				tokens.add(t);
			}
		}
	}

	public List<FormalMethod> getUsedMethods() {
		final List<FormalMethod> result = new ArrayList<FormalMethod>();
		for (FormalMethod m : all) {
			if (m == this) {
				continue;
			}
			if (tokens.contains(m.methodName)) {
				result.add(m);
			}
		}
		return result;
	}

	public static List<FormalMethod> getMethodsByName(String name) {
		final List<FormalMethod> result = new ArrayList<FormalMethod>();
		for (FormalMethod m : all) {
			if (name.equals(m.methodName)) {
				result.add(m);
			}
		}
		return result;
	}

	public Set<String> getUsedMethodNames() {
		final Set<String> result = new TreeSet<String>();
		for (FormalMethod m : all) {
			if (m == this) {
				continue;
			}
			if (tokens.contains(m.methodName)) {
				result.add(m.methodName);
			}
		}
		return result;
	}

	public static List<FormalMethod> getAll() {
		Collections.sort(all);
		return all;
	}

	public String getMethodName() {
		return methodName;
	}

	public static void addAllCallingThis(Set<String> called, String methodName) {
		for (FormalMethod m : FormalMethod.getMethodsByName(methodName)) {
			called.addAll(m.getUsedMethodNames());
		}
	}

}
