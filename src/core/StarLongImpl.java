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
package core;

class StarLongImpl extends InStructured implements StarLong {

	private final int data[];
	private final int posZero;

	private final StarLongImpl root;

	// Should probably use WeakReference here
	// http://weblogs.java.net/blog/2006/05/04/understanding-weak-references
	private final StarLongImpl added[];

	private StarLongImpl(Object parent, int data[], int posZero, StarLongImpl root) {
		super(parent);
		this.data = data;
		this.posZero = posZero;

		if (posZero == 0) {
			this.root = this;
			this.added = new StarLongImpl[data.length + 1];
		} else {
			this.root = root;
			this.added = null;
		}
	}

	private StarLongImpl malloc(int nb) {
		return new StarLongImpl(null, new int[nb], 0, null);
	}

	private StarLongImpl malloc(Object parent, int nb) {
		return new StarLongImpl(parent, new int[nb], 0, null);
	}

	private static StarLong malloc(int[] dataNew) {
		return new StarLongImpl(null, dataNew, 0, null);
	}

	public void set(int value) {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		data[posZero] = value;
	}

	public int get() {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		return data[posZero];
	}

	public StarLongImpl plus(int pointerArithmetic) {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarLongImpl result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarLongImpl(null, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}

	public int bracket(int position) {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		return data[posZero + position];
	}

	public void setBracket(int position, int value) {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		data[posZero + position] = value;
	}

	public int compareTo(StarLong arg) {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		final StarLongImpl other = (StarLongImpl) arg;
		if (this.data != other.data) {
			throw new IllegalArgumentException();
		}
		if (this.posZero == other.posZero) {
			return 0;
		}
		if (this.posZero > other.posZero) {
			return 1;
		}
		return -1;
	}

	public String asString() {
		if (starVoidvalue != null) {
			throw new UnsupportedOperationException();
		}
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		for (int i = posZero; i < data.length; i++) {
			sb.append(data[i]);
			sb.append(" ");
		}
		sb.append("}");
		return sb.toString();
	}

	private StarVoid starVoidvalue;

	public void set(StarVoid value) {
		System.err.println("I am "+this);
		throw new UnsupportedOperationException();
//		System.err.println("value=" + value);
//		this.starVoidvalue = value;
	}

//	public Int getInt() {
//		if (starVoidvalue == null) {
//			// May be we should return null ?
//			// May be we should throw new UnsupportedOperationException();
//			return null;
//		}
//		return (Int) starVoidvalue;
//	}
	public int getIntegerValue() {
		throw new UnsupportedOperationException();
	}

}
