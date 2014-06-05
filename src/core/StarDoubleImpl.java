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

public class StarDoubleImpl extends InStructured implements StarDouble {
	
	private final double data[];
	private final int posZero;
	
	private final StarDoubleImpl root;
	private final StarDoubleImpl added[];



	private StarDoubleImpl(Object parent, double data[], int posZero, StarDoubleImpl root) {
		super(parent);
		this.data = data;
		this.posZero = posZero;
		
		if (posZero == 0) {
			this.root = this;
			this.added = new StarDoubleImpl[data.length+1];
		} else {
			this.root = root;
			this.added = null;
		}
	}

	static StarDoubleImpl malloc(int nb) {
		return new StarDoubleImpl(null, new double[nb], 0, null);
	}

	static StarDoubleImpl malloc(Object parent, int nb) {
		return new StarDoubleImpl(parent, new double[nb], 0, null);
	}

	public void set(double value) {
		data[posZero] = value;
	}

	public double get() {
		return data[posZero];
	}

	public StarDoubleImpl plus(int pointerArithmetic) {
		if (posZero != 0) {
			return root.plus(pointerArithmetic + this.posZero);
		}
		assert posZero == 0;
		if (pointerArithmetic == 0) {
			return this;
		}
		StarDoubleImpl result = this.added[pointerArithmetic];
		if (result == null) {
			result = new StarDoubleImpl(null, data, pointerArithmetic, this.root);
			this.added[pointerArithmetic] = result;
		}
		return result;
	}


	public double bracket(int position) {
		return data[posZero + position];
	}

	public void setBracket(int position, double value) {
		data[posZero + position] = value;
	}

	public int compareTo(StarDouble arg) {
		final StarDoubleImpl other = (StarDoubleImpl) arg;
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
		for (int i=posZero; i<data.length; i++) {
			sb.append(data[i]);
			sb.append(" ");
		}
		sb.append("}");
		return sb.toString();
	}


}
