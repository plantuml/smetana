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

package smetana.core;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;

import smetana.core.debug.Debug;

public class JUtilsDebug {

	private final static CallStack callStack = new CallStack();
	private final static Debug debug = new Debug();

	static public void ENTERING(String signature, String methodName) {
		callStack.entering(signature, methodName);
		debug.entering(signature, methodName);
	}

	static public void LEAVING(String signature, String methodName) {
		callStack.leaving(signature, methodName);
		debug.leaving(signature, methodName);
	}

	static public void printCallStack(File f) throws FileNotFoundException {
		final PrintWriter pw = new PrintWriter(f);
		pw.println("@startuml");
		pw.println("digraph call {");
		pw.println("rankdir=LR;");
		callStack.printCallStack(pw);
		pw.println("}");
		pw.println("@enduml");
		pw.close();
	}

	public static void printMethods() throws IOException {
		callStack.printMethods();
	}

}
