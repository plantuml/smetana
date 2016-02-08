/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc.
 * in the United States and other countries.]
 *
 * Original Author:  Arnaud Roques
 * 
 */
package smetana.core;

/**
 * "Pseudo size" of a C structure. In C, this is the actual size of the structure. In Java, this is an indication to
 * know which structure we are going to allocate.
 * 
 * @author Arnaud Roques
 * 
 */
public class size_t_struct implements size_t {

	public final Class tobeAllocated;
//	public final int bytes;
	private boolean positive = true;

	public size_t_struct(Class tobeAllocated) {
		this.tobeAllocated = tobeAllocated;
	}

//	public size_t_struct(Class tobeAllocated, int arraySize) {
//		this.tobeAllocated = tobeAllocated;
//		this.bytes = 1;
//		this.arraySize = arraySize;
//		JUtils.LOG("building " + this);
//		// Thread.dumpStack();
//	}
//
	public size_t_struct negate() {
		final size_t_struct result = new size_t_struct(tobeAllocated);
		result.positive = !result.positive;
		return result;
	}

//	private size_t_struct(int bytes) {
//		this.tobeAllocated = null;
//		this.arraySize = 0;
//		this.bytes = bytes;
//		JUtils.LOG("building " + this);
//		// Thread.dumpStack();
//	}

	public size_t_struct multiply(int sz) {
//		if (tobeAllocated == null && arraySize == 0) {
//			return new size_t_struct(bytes * sz);
//		}
		throw new UnsupportedOperationException();
	}

	// public static final size_t_struct MINUS_ONE = new size_t_struct(-1);

//	@Override
//	public String toString() {
//		return super.toString() + " size_t(" + tobeAllocated + "*" + arraySize + ", bytes=" + bytes + ")";
//	}

	public boolean isStrictPositive() {
		return positive;
	}

	public boolean isStrictNegative() {
		return !positive;
	}


	// public boolean isStrictNegative() {
	// return false;
	// }

	// public static boolean isStrictNegative(size_t_struct v) {
	// if (v == null) {
	// return false;
	// }
	// return v.bytes < 0;
	// }
	//
	// public static boolean isNegativeOrNull(size_t_struct v) {
	// if (v == null) {
	// return true;
	// }
	// return v.bytes <= 0;
	// }

	public final Class getTobeAllocated() {
		return tobeAllocated;
	}

	public __ptr__ malloc() {
		if (tobeAllocated != null) {
			return Memory.malloc(tobeAllocated);
		}
		return (__ptr__) new CObject(-1, tobeAllocated);
	}

	public size_t_struct plus(int strlen) {
//		throw new UnsupportedOperationException();
		JUtils.LOG("adding " + strlen + " to " + this);
		return this;
	}

	public boolean isZero() {
		return false;
	}

//	public boolean isStrictLessThan(int v) {
//		return false;
//	}

//	public void setTo(int v) {
//		throw new UnsupportedOperationException();
//	}

//	public size_t_struct multiplyBySizeofStarChar() {
//		throw new UnsupportedOperationException();
//	}

//	public static size_t_struct fromInt(int bytes) {
//		return new size_t_struct(bytes);
//	}

//	public int getSizeInBytes() {
//		return bytes;
//	}
//
//	/**
//	 * @return the arraySize
//	 */
//	public int getArraySize() {
//		return arraySize;
//	}
	
	public __ptr__ realloc(Object old) {
		throw new UnsupportedOperationException();
	}


}
