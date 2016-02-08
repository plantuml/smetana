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
package smetana.core.amiga;

import smetana.core.Bucket;
import smetana.core.CType;
import smetana.core.JUtils;
import smetana.core.__array_of_double__;
import smetana.core.__array_of_integer__;
import smetana.core.__array_of_ptr__;
import smetana.core.__array_of_struct__;

public class BucketToAreaFactory {

	public static Area createArea(Bucket bucket, StarStruct parent) {
		if (bucket.ctype.getArrayLength() != 0) {
			return createAreaArray(bucket, bucket.ctype.getArrayLength());
		}
		if (bucket.ctype.functionPointer()) {
			// return PointerToNull.nullPointerTo();
			// return new AreaFunctionPointer();
			return null;
		}
		if (bucket.ctype.isIntStar()) {
			return null;
		}
		if (bucket.ctype.isVoidStar()) {
			return null;
			// return PointerToNull.nullPointerTo();
			// return new AreaVoidStar();
		}
		if (bucket.ctype.containsStar()) {
			final String type = bucket.ctype.getType();
			if (type.matches("\\w+\\*")) {
				final Class theClass = CType.getClassFrom(type.substring(0, type.length() - 1));
				JUtils.LOG("theClass=" + theClass);
				// return PointerToNull.nullPointerTo();
				return null;
			}
			throw new UnsupportedOperationException(bucket.toString());
		}
		if (bucket.ctype.isEnum()) {
			return new AreaInt();
		}
		if (bucket.ctype.isPrimitive()) {
			if (bucket.ctype.isInteger()) {
				return new AreaInt();
			}
			if (bucket.ctype.isChar()) {
				return new AreaInt();
			}
			if (bucket.ctype.isShort()) {
				return new AreaInt();
			}
			if (bucket.ctype.isLong()) {
				return new AreaInt();
			}
			if (bucket.ctype.isBoolean()) {
				return new AreaInt();
			}
			if (bucket.ctype.isDoubleOrFloat()) {
				return new AreaDouble();
			}
			throw new UnsupportedOperationException();
		}
		if (bucket.inlineStruct()) {
			final Class theClass = bucket.ctype.getTypeClass();
			return new StarStruct(theClass, parent);
		}
		if (bucket.ctype.isArrayOfCString()) {
			return null;
		}
		if (bucket.ctype.isCString()) {
			// return new AreaCString();
			// return PointerToNull.nullPointerTo();
			return null;
		}
		final Class theClass = bucket.ctype.getTypeClass();
		if (theClass != null) {
			return null;
			// return PointerToNull.nullPointerTo();
		}
		JUtils.LOG("BucketToAreaFactory:: theClass = " + theClass);
		JUtils.LOG("BucketToAreaFactory:: bucket=" + bucket);
		JUtils.LOG("BucketToAreaFactory:: bucket.ctype=" + bucket.ctype);
		throw new UnsupportedOperationException();
	}

	private static Area createAreaArray(Bucket bucket, int arrayLength) {
		JUtils.LOG("BucketToAreaFactory:createAreaArray: bucket=" + bucket);
		JUtils.LOG("BucketToAreaFactory:createAreaArray: arrayLength=" + arrayLength);
		JUtils.LOG("BucketToAreaFactory:createAreaArray: type=" + bucket.ctype);
		if (bucket.ctype.getType().matches("char \\w+\\[\\d+\\]")) {
			// Array of char
			return __array_of_integer__.mallocInteger(arrayLength);
		}
		if (bucket.ctype.getType().matches("int \\w+\\[\\d+\\]")) {
			// Array of int
			return __array_of_integer__.mallocInteger(arrayLength);
		}
		if (bucket.ctype.getType().matches("double \\w+\\[\\d+\\]")) {
			// Array of double
			return __array_of_double__.mallocDouble(arrayLength);
		}
		if (bucket.ctype.getType().matches("\\w+ \\*\\w+\\[\\d+\\]")) {
			// Array of pointer
			final String element = bucket.ctype.getType().split(" ")[0];
			JUtils.LOG("element=" + element);
			final Class theClass = CType.getClassFrom(element);
			JUtils.LOG("theClass=" + theClass);
			return __array_of_ptr__.malloc_empty(arrayLength);
		}
		if (bucket.ctype.getType().matches("\\w+ \\w+\\[\\d+\\]")) {
			// Array of Struct
			final String element = bucket.ctype.getType().split(" ")[0];
			JUtils.LOG("element=" + element);
			final Class theClass = CType.getClassFrom(element);
			JUtils.LOG("theClass=" + theClass);
			return __array_of_struct__.malloc(theClass, arrayLength);
		}
		throw new UnsupportedOperationException();
	}
}
