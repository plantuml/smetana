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
 * Memory just allocated.
 * 
 * @author Arnaud Roques
 * 
 */
class StarVoidFresh implements StarVoid {

	private final int size;
	private boolean valid = true;

	public StarVoidFresh(int size) {
		this.size = size;
	}

	public Object getParentStructure() {
		throw new UnsupportedOperationException();
	}

	public void setParentStructure(Object parent) {
		throw new UnsupportedOperationException();
	}

	public final boolean isValid() {
		return valid;
	}

	// public Object cast(Class cl) {
	// valid = false;
	// if (size == 1) {
	// try {
	// return cl.newInstance();
	// } catch (InstantiationException e) {
	// e.printStackTrace();
	// throw new IllegalStateException();
	// } catch (IllegalAccessException e) {
	// e.printStackTrace();
	// throw new IllegalStateException();
	// }
	// }
	// throw new UnsupportedOperationException("size=" + size);
	// }

	public void memset(int value, size_t size) {
		if (value == 0) {
			// The memory is already clean
			return;
		}
		throw new UnsupportedOperationException();
	}

	@Override
	public StarVoid castTo(Class cl) {
		valid = false;
		if (cl == StarStarChar.class) {
			if (size % 4 != 0) {
				throw new UnsupportedOperationException();
			}
			return Memory.mallocStarStarChar(size / 4);
		}
		if (cl == StarChar.class) {
			if (size % 4 != 0) {
				throw new UnsupportedOperationException();
			}
			return Memory.mallocStarChar(size / 4);
		}
		// if (size == 1) {
		if (size > 0) {
			try {
				return (StarVoid) cl.newInstance();
			} catch (InstantiationException e) {
				e.printStackTrace();
				throw new IllegalStateException();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
				throw new IllegalStateException();
			}
		}
		throw new UnsupportedOperationException("size=" + size);
	}

	public void memcopyFrom(StarVoid from) {
		throw new UnsupportedOperationException();
	}

	public StarVoid addByte(OFFSET offset) {
		throw new UnsupportedOperationException();
	}

	public StarVoid addByte(int offset) {
		throw new UnsupportedOperationException();
	}

}
