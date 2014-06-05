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

public class Structure extends InStructured implements StarVoid, StarChar {

	public Structure() {
		super();
	}

	public Structure(Object parentStructure) {
		super(parentStructure);
		if (parentStructure == null) {
			throw new IllegalArgumentException();
		}
	}

	// public Field getFieldIdx(StarVoid data) {
	// try {
	// for (Field f : getClass().getFields()) {
	// if (f.get(this) == data) {
	// return f;
	// }
	// }
	// } catch (IllegalAccessException e) {
	// e.printStackTrace();
	// throw new UnsupportedOperationException();
	// }
	// throw new IllegalArgumentException();
	// }

	// public StarVoid plusfield(Field f) {
	// if (f == null) {
	// // (char*)(obj)+ky) when ky==0 is obj
	// return this;
	// }
	// try {
	// return (StarVoid) f.get(this);
	// } catch (IllegalAccessException e) {
	// e.printStackTrace();
	// throw new UnsupportedOperationException();
	// }
	// }

	public StarVoid substractByte(int link) {
		if (link == 0) {
			return this;
		}
		System.err.println("I am " + getClass() + " and I don't know how to substractByte " + link);
		System.err.println("My parent is " + getParentStructure());
		throw new UnsupportedOperationException();
	}

	public StarVoid substractByte(OFFSET link) {
		if (link == null) {
			return this;
		}
		System.err.println("I am " + getClass());
		if (getParentStructure() != null) {
			return ((Structure) getParentStructure()).substractByte(link);
		}
		System.err.println("I am " + getClass() + " and I don't know how to substractByte " + link);
		System.err.println("My parent is " + getParentStructure());
		throw new UnsupportedOperationException();
	}

	// public StarVoid plusByte(int pointerArithmetic) {
	// throw new UnsupportedOperationException();
	// }

	@Override
	public boolean equals(Object o) {
		return super.equals(o);
	}

	public StarVoid ASREF(String name) {
		System.err.println("I am " + getClass() + " and I don't know how to ref " + name);
		throw new UnsupportedOperationException();
	}

	// Used for structure affectations
	public void copyFrom(Structure other) {
		System.err.println("I am " + getClass() + " and I don't know how to copyFrom " + other);
		throw new UnsupportedOperationException();
	}
	
	// StarChar
	final public char get() {
		throw new UnsupportedOperationException();
	}
	final public char set(char c) {
		throw new UnsupportedOperationException();
	}
	final public StarChar plus(int pointerArithmetic) {
		throw new UnsupportedOperationException();
	}
	final public char bracket(int position) {
		throw new UnsupportedOperationException();
	}
	final public void setBracket(int position, char data) {
		throw new UnsupportedOperationException();
	}
	final public int minus(StarChar other) {
		throw new UnsupportedOperationException();
	}
	final public int compareTo(StarChar arg0) {
		throw new UnsupportedOperationException();
	}
	final public String asString() {
		throw new UnsupportedOperationException();
	}

}
