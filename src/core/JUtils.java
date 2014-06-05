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

// http://docs.oracle.com/javase/specs/jls/se5.0/html/expressions.html#15.7.4
// http://www.jbox.dk/sanos/source/lib/string.c.html

public class JUtils {
	
	public static StarLong ASREF(final Int[] data) {
		return new StarLong() {
			
			public int compareTo(StarLong arg0) {
				throw new UnsupportedOperationException();
			}
			
			public void setParentStructure(Object parent) {
				throw new UnsupportedOperationException();
			}
			
			public Object getParentStructure() {
				throw new UnsupportedOperationException();
			}
			
			public void memset(int value, size_t size) {
				throw new UnsupportedOperationException();
			}
			
			public void memcopyFrom(StarVoid from) {
				throw new UnsupportedOperationException();
			}
			
			public StarVoid castTo(Class clazz) {
				throw new UnsupportedOperationException();
			}
			
			public StarVoid addByte(int offset) {
				throw new UnsupportedOperationException();
			}
			
			public StarVoid addByte(OFFSET offset) {
				throw new UnsupportedOperationException();
			}
			
			public void setBracket(int position, int value) {
				throw new UnsupportedOperationException();
			}
			
			public void set(StarVoid value) {
				data[0].set(value);
			}

			public int getIntegerValue() {
				throw new UnsupportedOperationException();
			}

			public void set(int value) {
				throw new UnsupportedOperationException();
			}
			
			public StarLong plus(int pointerArithmetic) {
				throw new UnsupportedOperationException();
			}
			
			public int get() {
				throw new UnsupportedOperationException();
			}
			
			public int bracket(int position) {
				throw new UnsupportedOperationException();
			}
			
			public String asString() {
				throw new UnsupportedOperationException();
			}

		};
	}

	public static <O> StarStar<O> ASREF(final O[] data) {
		return new StarStarAdapter<O>() {
			public O get() {
				return data[0];
			}

			public void set(O value) {
				data[0] = value;
			}

			public StarLong asStarLong() {
				// return new StarLongFromStarStar(data);
				throw new UnsupportedOperationException();
			}
		};
	}

	// public static StarStarChar REF(StarChar data) {
	// throw new UnsupportedOperationException();
	// }
	//
	// private static <O> StarStar<O> REF(O data) {
	// final StarStar<O> result = (StarStar<O>) Memory.<O> mallocStarStar(data.getClass(), 1, false);
	// result.set(data);
	// return result;
	// }
	//
	// public static <O> StarStar<O> REF(final O data, final SETTER<O> setter) {
	// return new StarStar<O>() {
	// public O get() {
	// return data;
	// }
	//
	// public void set(O value) {
	// setter.set(value);
	// }
	//
	// public int compareTo(StarStar<O> other) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public StarStar<O> plus(int pointerArithmetic) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public O bracket(int position) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public O setBracket(int position, O value) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public int minus(StarStar<O> other) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public int size() {
	// throw new UnsupportedOperationException();
	// }
	//
	// public void memset(int value, int size) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public StarVoid castTo(Class clazz) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public void memcopyFrom(StarVoid from) {
	// throw new UnsupportedOperationException();
	// }
	//
	// public Object getParentStructure() {
	// throw new UnsupportedOperationException();
	// }
	//
	// public void setParentStructure(Object parent) {
	// throw new UnsupportedOperationException();
	// }
	//
	// };
	// }
	//
	// public static StarDouble REF(double value) {
	// StarDouble result = Memory.mallocDouble(1);
	// result.set(value);
	// return result;
	// }
	//
	// public static StarInt REF(int data) {
	// final StarInt result = Memory.mallocInt(1);
	// result.set(data);
	// return result;
	// }
	//
	// public static StarChar REF(char data) {
	// final StarChar result = Memory.mallocStarChar(1);
	// result.set(data);
	// return result;
	// }

	public static StarVoid asStarVoid(Object obj) {
		if (obj instanceof StarVoid) {
			return (StarVoid) obj;
		}
		throw new UnsupportedOperationException("" + obj.getClass());
	}

	public static StarChar asStarChar(Object obj) {
		return new StarCharGeneric(obj);
	}

	// public static StarVoid fromStarVoid(Class cl, StarVoid starVoid) {
	// if (starVoid instanceof StarVoidFresh == false) {
	// throw new UnsupportedOperationException();
	// }
	// final StarVoidFresh fresh = (StarVoidFresh) starVoid;
	// if (fresh.isValid() == false) {
	// throw new UnsupportedOperationException();
	// }
	// return fresh.castTo(cl);
	// }

	public static Object fromStarChar(Class cl, StarChar starChar) {
		if (starChar instanceof StarCharGeneric == false) {
			throw new UnsupportedOperationException();
		}
		final StarCharGeneric generic = (StarCharGeneric) starChar;
		return generic.cast(cl);
	}

	public static size_t sizeof(Class cl) {
		return new size_t(cl);
		// throw new UnsupportedOperationException();
	}

	public static StarChar asStarChar(String s) {
		return StarCharImpl.malloc(s);
	}
	
	public static StarVoid castTo(StarVoid tobeCasted, Class clazz) {
		if (tobeCasted==null) {
			return null;
		}
		return tobeCasted.castTo(clazz);
	}

}
