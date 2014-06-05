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

class StarIntImpl extends InStructured implements StarInt {

	private final int data[];
	private final int posZero;

	private final StarIntImpl root;
	
	// Should probably use WeakReference here
	// http://weblogs.java.net/blog/2006/05/04/understanding-weak-references
	private final StarIntImpl added[];

	private StarIntImpl(Object parent, int data[], int posZero, StarIntImpl root) {
		super(parent);
		this.data = data;
		this.posZero = posZero;

		if (posZero == 0) {
			this.root = this;
			this.added = new StarIntImpl[data.length+1];
		} else {
			this.root = root;
			this.added = null;
		}
	}

	static StarIntImpl malloc(int nb) {
		return new StarIntImpl(null, new int[nb], 0, null);
	}

	static StarIntImpl malloc(Object parent, int nb) {
		return new StarIntImpl(parent, new int[nb], 0, null);
	}
	
	public static StarInt malloc(int[] dataNew) {
		return new StarIntImpl(null, dataNew, 0, null);
	}


	public void set(int value) {
		data[posZero] = value;
	}

	public int get() {
		return data[posZero];
	}

	public StarIntImpl plus(int pointerArithmetic) {
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarIntImpl result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarIntImpl(null, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}

	public int bracket(int position) {
		return data[posZero + position];
	}

	public void setBracket(int position, int value) {
		data[posZero + position] = value;
	}

	public int compareTo(StarInt arg) {
		final StarIntImpl other = (StarIntImpl) arg;
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
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		for (int i = posZero; i < data.length; i++) {
			sb.append(data[i]);
			sb.append(" ");
		}
		sb.append("}");
		return sb.toString();
	}


}
