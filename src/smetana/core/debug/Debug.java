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

package smetana.core.debug;

import h.Agedge_s;
import h.Agedgeinfo_t;
import h.Agnode_s;
import h.Agnodeinfo_t;
import h.bezier;
import h.boxf;
import h.path;
import h.splines;
import smetana.core.Macro;
import smetana.core.__ptr__;
import smetana.core.__struct__;
import demo.DebugUtils;

public class Debug {

	static private Agedge_s e;
	static private Agnode_s n;
	static public path P;

	public static void setOneEdge(Agedge_s some) {
		e = some;
	}

	public static void setOneNode(Agnode_s some) {
		n = some;
	}

	public void entering(String signature, String methodName) {
		// checkEdge(e);
		checkNode(n);
		checkPath();
	}

	public void leaving(String signature, String methodName) {
		// checkEdge(e);
		checkPath();
	}

	private void checkPath() {
		if (P==null) return;
		__ptr__ boxes =  P.getPtr("boxes");
		if (boxes==null) return;
		double x = boxes.plus(3).getStruct("UR").getDouble("x");
		String tmp = "x=" + x;
		if (tmp.equals(last) == false) {
			System.err.println("change!=" + tmp);
			Throwable creation = new Throwable();
			creation.fillInStackTrace();
			creation.printStackTrace();
		}
		last = tmp;
		
		
	}

	private void checkNode(Agnode_s n) {
		if (n == null)
			return;
		Agedgeinfo_t data = null;
		try {
			data = (Agedgeinfo_t) Macro.AGDATA(n).castTo(Agnodeinfo_t.class);
			if (data == null)
				return;
		} catch (UnsupportedOperationException ex) {
			return;
		}
		double x = data.getStruct("coord").getDouble("x");
		String tmp = "x=" + x;
		if (tmp.equals(last) == false) {
			System.err.println("change!=" + tmp);
			Throwable creation = new Throwable();
			creation.fillInStackTrace();
			//creation.printStackTrace();
		}

		last = tmp;

	}

	private void checkEdge(Agedge_s e) {
		if (e == null)
			return;
		Agedgeinfo_t data = null;
		try {
			data = (Agedgeinfo_t) Macro.AGDATA(e).castTo(Agedgeinfo_t.class);
			if (data == null)
				return;
		} catch (UnsupportedOperationException ex) {
			return;
		}
		final splines splines = (splines) data.getPtr("spl");
		if (splines == null)
			return;
		__struct__<boxf> bb = splines.getStruct("bb");
		if (bb == null)
			return;
		final bezier listBezier = (bezier) splines.getPtr("list");
		if (listBezier == null)
			return;
		final __ptr__ bezier = splines.getPtr("list").getPtr();
		if (bezier == null)
			return;

		if (bezier.getInt("size") == 0)
			return;

		// System.err.println("ssssize=" + bezier.getInt("size"));

		final __ptr__ pt = bezier.getPtr("list").plus(0).getPtr();
		final String tmp = DebugUtils.pointftoString(pt);
		if (tmp.equals(last) == false) {
			System.err.println("change!=" + tmp);
			Throwable creation = new Throwable();
			creation.fillInStackTrace();
			// creation.printStackTrace();
		}
		last = tmp;
	}

	private String last = "";

}
