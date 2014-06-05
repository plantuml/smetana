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

//import lib.common.Types_h.Bezier;

public class Memory {

	public static StarDouble mallocDouble(int nb) {
		return StarDoubleImpl.malloc(nb);
	}

	public static StarInt mallocInt(int nb) {
		return StarIntImpl.malloc(nb);
	}

	public static StarLong mallocLong(int nb) {
		if (nb == 1) {
			return new StarLongGeneric();
		}
		throw new UnsupportedOperationException();
		// return StarLongImpl.malloc(nb);
	}

	public static StarInt mallocInt(int[] data) {
		return StarIntImpl.malloc(data);
	}

	public static StarInt mallocInt(Object parent, int nb) {
		return StarIntImpl.malloc(parent, nb);
	}

	public static StarChar mallocStarChar(int nb) {
		return StarCharImpl.malloc(nb);
	}

	public static StarChar mallocStarChar(Object parent, int nb) {
		return StarCharImpl.malloc(parent, nb);
	}

	public static StarStarChar mallocStarStarChar(int nb) {
		return StarStarCharImpl.malloc(null, nb);
	}

	public static StarStarChar mallocStarStarChar(String[] strings) {
		return StarStarCharImpl.malloc(strings);
	}

	public static <O> StarStar<? extends O> mallocStarStar(Class type, int nb, boolean withAlloc) {
		return StarStarImpl.<O> malloc(type, nb, withAlloc);
	}

	public static StarStarChar reallocStarStarChar(StarStarChar data, int nb) {
		StarStarCharImpl s = (StarStarCharImpl) data;
		return s.realloc(nb);
	}

	public static <O> StarStar<O> reallocStarStar(Class type, StarStar<O> data, int nb, boolean withAlloc) {
		final StarStarImpl<O> s = (StarStarImpl<O>) data;
		return s.realloc(type, nb, withAlloc);
	}

	public static StarVoid realloc(StarVoid addr, size_t size) {
		throw new UnsupportedOperationException();
	}

	public static StarVoid malloc(int size) {
		return new StarVoidFresh(size);
	}

	public static StarVoid malloc(size_t size) {
		if (size.getTobeAllocated() != null && size.getArraySize() == 1) {
			return malloc(size.getTobeAllocated());
		}
		if (size.bytes != 0) {
			return new StarVoidFresh(size.bytes);
		}
		throw new UnsupportedOperationException();
	}

	public static StarVoid malloc(Class cl) {
		try {
			if (cl == StarChar.class) {
				return mallocStarStarChar(1);
			}
			return (StarVoid) cl.newInstance();
		} catch (InstantiationException e) {
			e.printStackTrace();
			throw new IllegalStateException();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
			throw new IllegalStateException();
		}
	}

	public static StarChar reallocStarChar(StarChar data, int nb) {
		throw new UnsupportedOperationException();
	}

	public static Object realloc(Object array, int size) {
		throw new UnsupportedOperationException();
	}

	public static void memset(StarVoid rv, int value, size_t size) {
		rv.memset(value, size);
	}

	public static void free(StarVoid ptr) {
	}

}
