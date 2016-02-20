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

import java.util.Iterator;
import java.util.List;

public class MethodWrapping {

	private final String methodName;
	private final MethodArguments args;
	private final boolean returnStruct;
	private final boolean returnVoid;

	private MethodWrapping(String methodName, MethodArguments args, boolean returnStruct, boolean returnVoid) {
		this.methodName = methodName;
		this.args = args;
		this.returnVoid = returnVoid;
		this.returnStruct = returnStruct;
	}

	public static MethodWrapping create(String methodName, List<String> list) {
		String s = list.get(0).replace('\n', ' ').replace('\r', ' ');
		s = s.replaceAll("\\bstatic\\b", "");
		s = s.replaceAll("\\binline\\b", "");
		s = s.replaceAll("\\bconst\\b", "");
		s = s.replaceAll("\\bregister\\b", "");
		s = s.replaceAll("\\bunsigned\\b", "");
		s = s.trim();

		final int x1 = s.indexOf('(');
		final String start = s.substring(0, x1).trim();
		if (start.endsWith(methodName) == false) {
			throw new IllegalStateException(s + "  :  " + methodName);
		}
		final String ret = start.substring(0, start.length() - methodName.length()).trim();
		final int x2 = s.lastIndexOf(')');
		final MethodArguments args = new MethodArguments(s.substring(x1 + 1, x2).trim(), list);

		if (notStruct(ret) == false || args.hasStruct()) {
			if (methodName.equals("poly_path")) {
				System.err.println("FOO=" + list.get(0));
				System.err.println("notStruct(ret)=" + notStruct(ret));
				System.err.println("args.hasStruct()=" + args.hasStruct());
			}
			return new MethodWrapping(methodName, args, notStruct(ret) == false, ret.equals("void"));
		}

		return null;
	}

	public static boolean notStruct(final String ret) {
		return ret.endsWith("*") || ret.equals("int") || ret.equals("void") || ret.equals("boolean")
				|| ret.equals("char") || ret.equals("size_t") || ret.equals("long") || ret.equals("double")
				|| ret.equals("shape_kind") || ret.equals("api_t") || ret.equals("pack_mode");
	}

	public Iterator<MethodArgument> argumentsIterator() {
		return args.argumentsIterator();
	}

	public boolean doesReturnStruct() {
		return returnStruct;
	}

	public boolean isReturnVoid() {
		return returnVoid;
	}

}
