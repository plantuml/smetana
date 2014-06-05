/* ========================================================================
 * JDot  : Port from C to Java of GraphViz
 * ========================================================================
 *
 * (C) Copyright 2012, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net/jdot/jdot.html
 * 
 * This file is part of JDot.
 *
 * JDot is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JDot distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 * 
 * GraphViz itself is distributed under Eclipse Public License v1.0:
 * 
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/
package core.debug;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;

import core.StarChar;
import core.StarInt;
import core.StarStar;
import core.StarStarChar;
import core.Structure;

public class StructurePrinter {

	private final Structure data1;
	private final PrintStream ps;

	public StructurePrinter(PrintStream ps, Structure data) {
		this.data1 = data;
		this.ps = ps;
	}

	public StructurePrinter(String filename, Structure data) throws FileNotFoundException {
		this.data1 = data;
		this.ps = new PrintStream(filename);
	}

	public void print() {
		try {
			printInternal();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		}
		ps.flush();
	}

	public void printInternal() throws IllegalArgumentException, IllegalAccessException {
		ps.println(data1);
		List all = new ArrayList();
		all.add(data1);
		int n = 0;
		do {
			printOne(all, n);
			n++;
		} while (n < all.size());

	}

	private void printOne(List all, int num) throws IllegalAccessException {
		Object tmp = all.get(num);
		Class cl = tmp.getClass();
		ps.println(tmp.getClass().getSimpleName() + "[" + all.indexOf(tmp) + "]");
		if (cl.isArray()) {
			printArray(all, tmp);
		} else if (tmp instanceof StarStarChar) {
			printStarStarChar(all, (StarStarChar) tmp);
		} else if (tmp instanceof StarStar) {
			printStarStar(all, (StarStar) tmp);
		} else {
			printObject(all, tmp);
		}
		ps.println();
	}

	private void printStarStar(List all, StarStar tmp) {
		ps.println("printStarStar lenght = " + tmp.size());
		for (int i = 0; i < tmp.size(); i++) {
			final Object data = tmp.bracket(i);
			if (data != null) {
				all.add(data);
			}
		}
	}

	private void printStarStarChar(List all, StarStarChar tmp) {
		ps.println("printStarStarChar lenght = " + tmp.size());
		for (int i = 0; i < tmp.size(); i++) {
			final StarChar data = tmp.bracket(i);
			if (data != null) {
				all.add(data);
			}
		}
	}

	private void printArray(List all, Object tmp) {
		ps.println("arrays");
		throw new UnsupportedOperationException();

	}

	private void printObject(List all, Object tmp) throws IllegalAccessException {
		Field fields[] = tmp.getClass().getFields();
		for (Field f : fields) {
			ps.print(f.getName());
			Object v = f.get(tmp);
			Class t = f.getType();
			if (v == null) {
				ps.println("  null");
			} else if (t.isPrimitive()) {
				ps.println("  " + v);
			} else if (v instanceof StarChar) {
				ps.println("  \"" + ((StarChar) v).asString() + "\"");
			} else if (v instanceof StarInt) {
				ps.println("  " + ((StarInt) v).asString());
			} else if (v instanceof StarStarChar) {
				int idx = all.indexOf(v);
				if (idx == -1) {
					all.add(v);
					idx = all.indexOf(v);
				}
				ps.println("  StarStarChar" + "[" + idx + "]");
//			} else if (v instanceof StarStar) {
//				int idx = all.indexOf(v);
//				if (idx == -1) {
//					all.add(v);
//					idx = all.indexOf(v);
//				}
//				ps.println("  StarStar" + "[" + idx + "]");
			} else if (v instanceof Structure) {
				int idx = all.indexOf(v);
				if (idx == -1) {
					all.add(v);
					idx = all.indexOf(v);
				}
				ps.println("  " + t.getSimpleName() + "[" + idx + "]");
			} else {
				ps.println("  other:" + t);
			}
		}
	}
}
