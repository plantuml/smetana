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

class StarStarCharImpl extends InStructured implements StarStarChar {

	private final StarChar data[];
	private final int posZero;

	private final StarStarCharImpl root;
	private final StarStarCharImpl added[];

	private StarStarCharImpl(Object parent, StarChar data[], int posZero, StarStarCharImpl root) {
		super(parent);
		this.data = data;
		this.posZero = posZero;

		if (posZero == 0) {
			this.root = this;
			this.added = new StarStarCharImpl[data.length + 1];
		} else {
			this.root = root;
			this.added = null;
		}
	}

	public static StarStarChar malloc(Object parent, int nb) {
		return new StarStarCharImpl(parent, new StarChar[nb], 0, null);
	}

	public static StarStarChar malloc(String[] strings) {
		StarStarChar result = malloc(null, strings.length);
		for (int i = 0; i < strings.length; i++) {
			result.setBracket(i, JUtils.asStarChar(strings[i]));
		}
		return result;
	}

	public StarStarChar realloc(int nb) {
		if (posZero != 0) {
			throw new IllegalStateException();
		}
		StarStarCharImpl result = (StarStarCharImpl) malloc(null, nb);
		for (int i = 0; i < this.data.length; i++) {
			result.data[i] = this.data[i];
		}
		return result;
	}

	public StarChar bracket(int position) {
		return this.data[position];
	}

	public StarChar get() {
		return bracket(0);
	}

	public StarChar set(StarChar data) {
		return setBracket(0, data);
	}

	public StarChar setBracket(int position, StarChar data) {
		this.data[position] = data;
		return data;
	}

	public int size() {
		return data.length - posZero;
	}

	public StarStarCharImpl plus(int pointerArithmetic) {
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarStarCharImpl result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarStarCharImpl(null, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}

	public void memset(int value, size_t size) {
		if (value != 0) {
			throw new UnsupportedOperationException();
		}
		for (int i = 0; i < size.getArraySize(); i++) {
			setBracket(i, null);
		}
	}

}
