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

class StarCharImpl extends InStructured implements StarChar {

	private final char data[];
	private final int posZero;

	private final StarCharImpl root;
	private final StarCharImpl added[];

	private StarCharImpl(Object parent, char data[], int posZero, StarCharImpl root) {
		super(parent);
		this.data = data;
		this.posZero = posZero;

		if (posZero == 0) {
			this.root = this;
			this.added = new StarCharImpl[data.length + 1];
		} else {
			this.root = root;
			this.added = null;
		}
	}

	static StarCharImpl malloc(int nb) {
		return new StarCharImpl(null, new char[nb], 0, null);
	}

	static StarCharImpl malloc(Object parent, int nb) {
		return new StarCharImpl(parent, new char[nb], 0, null);
	}

	static StarCharImpl malloc(String data) {
		return new StarCharImpl(data);
	}

	private StarCharImpl(String args) {
		this(null, new char[args.length() + 1], 0, null);
		for (int i = 0; i < args.length(); i++) {
			data[i] = args.charAt(i);
		}
	}

	public char get() {
		return data[posZero];
	}

	public char set(char c) {
		data[posZero] = c;
		return c;
	}

	public StarCharImpl plus(int pointerArithmetic) {
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarCharImpl result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarCharImpl(null, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}

	public char bracket(int position) {
		return data[posZero + position];
	}

	public int compareTo(StarChar arg) {
		final StarCharImpl other = (StarCharImpl) arg;
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
		final String s = new String(data).substring(posZero);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c > 32 && c < 127) {
				sb.append(c);
			} else {
				sb.append("\\" + ((int) c));
			}
		}
		return sb.toString();
	}

	public void setBracket(int position, char data) {
		this.data[position] = data;
	}

	@Override
	public String toString() {
		return super.toString() + " " + asString();
	}

	public int minus(StarChar other) {
		throw new UnsupportedOperationException();
	}

//	@Override
//	final public void memset(int value, size_t size) {
//		if (size.getTobeAllocated() != null) {
//			throw new UnsupportedOperationException();
//		}
//		for (int i = 0; i < size.getSizeInBytes(); i++) {
//			setBracket(i, (char) value);
//		}
//	}

}
