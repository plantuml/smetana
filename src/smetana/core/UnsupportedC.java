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

public class UnsupportedC implements __ptr__ {

	public int getInt() {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setInt(int value) {
		throw new UnsupportedOperationException(getClass().toString());
	}
	
	public void setCString(String fieldName, CString value) {
		throw new UnsupportedOperationException(getClass().toString());
	}


	public int minus(__ptr__ other) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public double getDouble() {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setDouble(double value) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __ptr__ getPtr() {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setPtr(__ptr__ value) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __ptr__ getPtr(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __struct__ getStruct() {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setStruct(__struct__ value) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	// public __array__ getArray(String fieldName) {
	// throw new UnsupportedOperationException(getClass().toString());
	// }

	public __array_of_integer__ getArrayOfInteger(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __array_of_struct__ getArrayOfStruct(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __array_of_ptr__ getArrayOfPtr(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __array_of_cstring__ getArrayOfCString(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __struct__ getStruct(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public boolean getBoolean(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public double getDouble(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public CString getCString(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public int getInt(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __ptr__ setPtr(String fieldName, __ptr__ data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setStruct(String fieldName, __struct__ data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setInt(String fieldName, int data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setBoolean(String fieldName, boolean data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void setDouble(String fieldName, double data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __ptr__ castTo(Class dest) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public Object call(String name, Object... args) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public Object addVirtualBytes(int bytes) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	final public __ptr__ unsupported() {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public __ptr__ plus(int pointerMove) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public int comparePointer(__ptr__ other) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public String getDebug(String fieldName) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void copyDataFrom(__ptr__ other) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public void copyDataFrom(__struct__ other) {
		throw new UnsupportedOperationException(getClass().toString());
	}

}
