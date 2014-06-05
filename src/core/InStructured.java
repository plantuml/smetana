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

public abstract class InStructured implements InStructurable {

	final private Object parentStructure;

	public InStructured() {
		this(null);
	}

	public InStructured(Object parentStructure) {
		this.parentStructure = parentStructure;
	}

	public StarVoid getParentStructure() {
		// if (parentStructure == null) {
		// throw new IllegalStateException("This object is not in another structure");
		// }
		return (StarVoid) parentStructure;
	}

	public void setParentStructure(Object parent) {
		// if (parentStructure != null) {
		// throw new IllegalStateException();
		// }
		// if (parent == null) {
		// throw new IllegalStateException();
		// }
		// this.parentStructure = parent;
		throw new UnsupportedOperationException();
	}

	public StarVoid castTo(Class clazz) {
		if (this.getClass() == clazz) {
			return (StarVoid) this;
		}
		if (clazz == StarChar.class) {
			return (StarVoid) this;
		}
		if (parentStructure != null && parentStructure.getClass() == clazz) {
			return (StarVoid) parentStructure;
		}
		System.err.println("I am " + getClass() + " and I try to cast to " + clazz);
		throw new UnsupportedOperationException();
	}

	public void memset(int value, size_t size) {
		if (value == 0 && size.getTobeAllocated() == this.getClass()) {
			reset();
			return;
		}
		System.err.println("I am " + getClass() + " and I don't know put " + value + " for " + size);
		throw new UnsupportedOperationException();
	}

	public void reset() {
		System.err.println("I am " + getClass() + " and I don't know to reset");
		throw new UnsupportedOperationException();
	}

	public void memcopyFrom(StarVoid from) {
		throw new UnsupportedOperationException();
	}

	public StarVoid addByte(OFFSET offset) {
		if (offset == null) {
			return (StarVoid) this;
		}
		if (offset != null && getClass() == offset.reference) {
			return ((Structure) this).ASREF(offset.name);
		}
		if (offset != null && parentStructure != null && parentStructure.getClass() == offset.reference) {
			return ((Structure) parentStructure).ASREF(offset.name);

		}
		System.err.println("I am " + getClass() + " and I try to addByte " + offset);
		System.err.println("My parent is " + parentStructure);
		throw new UnsupportedOperationException();
	}

	public StarVoid addByte(int offset) {
		if (offset == 0) {
			return (StarVoid) this;
		}
		System.err.println("I am " + getClass() + " and I try to addByte " + offset);
		throw new UnsupportedOperationException();
	}

}
