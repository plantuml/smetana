/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc.
 * in the United States and other countries.]
 *
 * Original Author:  Arnaud Roques
 * 
 */
package smetana.core.debug;

import h.Agedge_s;
import h.Agedgeinfo_t;
import h.bezier;
import h.boxf;
import h.splines;
import smetana.core.Macro;
import smetana.core.__ptr__;
import smetana.core.__struct__;
import demo.DemoUtils;

public class Debug {

	static private Agedge_s e;

	public static void setOneEdge(Agedge_s some) {
		e = some;
	}

	public void entering(String signature, String methodName) {
		check(e);
	}

	public void leaving(String signature, String methodName) {
		check(e);
	}

	private void check(Agedge_s e) {
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

		if (bezier.getInt("size") != 4)
			return;

		final __ptr__ pt = bezier.getPtr("list").plus(0).getPtr();
		final String tmp = DemoUtils.pointftoString(pt);
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
