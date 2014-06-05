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

/**
 * "Pseudo size" of a C structure. In C, this is the actual size of the structure. In Java, this is an indication to
 * know which structure we are going to allocate.
 * 
 * @author Arnaud Roques
 * 
 */
public class size_t {

	public final Class tobeAllocated;
	public final int arraySize;
	public final int bytes;

	public size_t(Class tobeAllocated) {
		this(tobeAllocated, 1);
	}

	public size_t(Class tobeAllocated, int arraySize) {
		this.tobeAllocated = tobeAllocated;
		this.bytes = 1;
		this.arraySize = arraySize;
		System.err.println("building " + this);
		// Thread.dumpStack();
	}

	private size_t(int bytes) {
		this.tobeAllocated = null;
		this.arraySize = 0;
		this.bytes = bytes;
		System.err.println("building " + this);
		// Thread.dumpStack();
	}

	public static final size_t MINUS_ONE = new size_t(-1);

	@Override
	public String toString() {
		return super.toString() + " size_t(" + tobeAllocated + "*" + arraySize + ", bytes=" + bytes + ")";
	}

	public boolean isStrictPositive() {
		return bytes > 0;
	}

	// public boolean isStrictNegative() {
	// return false;
	// }

	public static boolean isStrictNegative(size_t v) {
		if (v == null) {
			return false;
		}
		return v.bytes < 0;
	}

	public static boolean isNegativeOrNull(size_t v) {
		if (v == null) {
			return true;
		}
		return v.bytes <= 0;
	}

	public final Class getTobeAllocated() {
		return tobeAllocated;
	}

	public size_t plus(int strlen) {
		// throw new UnsupportedOperationException();
		System.err.println("adding " + strlen + " to " + this);
		return this;
	}

	public boolean isStrictLessThan(int v) {
		return false;
	}

	public void setTo(int v) {
		throw new UnsupportedOperationException();
	}

	public size_t multiplyBySizeofStarChar() {
		throw new UnsupportedOperationException();
	}

	public static size_t fromInt(int bytes) {
		return new size_t(bytes);
	}

	public int getSizeInBytes() {
		return bytes;
	}

	/**
	 * @return the arraySize
	 */
	public int getArraySize() {
		return arraySize;
	}

}
