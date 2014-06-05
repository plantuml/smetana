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

import java.util.ArrayList;
import java.util.List;

class StarStarImpl<O> extends InStructured implements StarStar<O> {

	private final Class type;
	private final List<O> data;
	private final int posZero;

	private final StarStarImpl<O> root;
	private final StarStarImpl<O> added[];

	private StarStarImpl(Class type, List<O> data, int posZero, StarStarImpl<O> root) {
		this.data = data;
		this.type = type;
		this.posZero = posZero;

		if (posZero == 0) {
			this.root = this;
			this.added = new StarStarImpl[data.size() + 1];
		} else {
			this.root = root;
			this.added = null;
		}

	}

	public static <O> StarStarImpl<O> malloc(Class type, int nb, boolean withAlloc) {
		final List<O> data = new ArrayList<O>(nb);
		for (int i = 0; i < nb; i++) {
			if (withAlloc) {
				try {
					data.add((O) type.newInstance());
				} catch (InstantiationException e) {
					e.printStackTrace();
					throw new IllegalStateException();
				} catch (IllegalAccessException e) {
					e.printStackTrace();
					throw new IllegalStateException();
				}
			} else {
				data.add(null);
			}
		}
		return new StarStarImpl<O>(type, data, 0, null);
	}

	public StarStar<O> realloc(Class type, int nb, boolean withAlloc) {
		if (type.equals(this.type) == false) {
			throw new UnsupportedOperationException();
		}

		if (posZero != 0) {
			throw new IllegalStateException();
		}
		StarStarImpl<O> result = malloc(type, nb, withAlloc);
		for (int i = 0; i < this.data.size(); i++) {
			result.setBracket(i, this.bracket(i));
		}
		return result;

	}

	public void set(O value) {
		data.set(posZero, value);
	}

	public O get() {
		return data.get(posZero);
	}

	public StarStarImpl<O> plus(int pointerArithmetic) {
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarStarImpl<O> result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarStarImpl<O>(type, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}

	public O bracket(int position) {
		return data.get(posZero + position);
	}

	public O setBracket(int position, O value) {
		data.set(posZero + position, value);
		return value;
	}

	public int compareTo(StarStar<O> arg) {
		final StarStarImpl<O> other = (StarStarImpl<O>) arg;
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

	public int size() {
		return data.size() - posZero;
	}

	public int minus(StarStar<O> other) {
		throw new UnsupportedOperationException();
	}
	
	public StarLong asStarLong() {
		throw new UnsupportedOperationException();
	}

}
