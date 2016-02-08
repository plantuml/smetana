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

import smetana.core.UnsupportedC;
import smetana.core.__array_of_struct__;
import smetana.core.__ptr__;
import smetana.core.__struct__;
import smetana.struct.AllH;

public class StarArrayOfStruct extends UnsupportedC implements Area, AllH {

	private final __array_of_struct__ array;

	public StarArrayOfStruct(__array_of_struct__ array) {
		this.array = array;
	}

	public void realloc(int nb) {
		array.realloc(nb);
	}

	public String getUID36() {
		return array.getUID36();
	}

	public void memcopyFrom(Area source) {
		throw new UnsupportedOperationException();
	}

	public final __array_of_struct__ getInternalArray() {
		return array;
	}

	public __ptr__ plus(int pointerMove) {
		return new StarArrayOfStruct(array.move(pointerMove));
	}

	public __struct__ getStruct() {
		return array.getStruct();
	}

	public __ptr__ getPtr() {
		return array.getPtr();
	}

	public int minus(__ptr__ other) {
		StarArrayOfStruct other2 = (StarArrayOfStruct) other;
		int res = array.comparePointerInternal(other2.array);
		return res;
	}

	public void setStruct(__struct__ value) {
		array.setStruct(value);
	}

	public __ptr__ getPtrForEquality() {
		return array.getStruct().amp();
	}

	public int comparePointer(__ptr__ other) {
		return array.comparePointerInternal(((StarArrayOfStruct) other).array);
	}

	public boolean isSameThan(StarArrayOfStruct other) {
		return array.comparePointerInternal(other.array) == 0;
	}

	// Fieldname

	public __ptr__ setPtr(String fieldName, __ptr__ data) {
		final Area tmp1 = array.getInternal(0);
		return ((__struct__) tmp1).setPtr(fieldName, data);
	}

	public __ptr__ getPtr(String fieldName) {
		final Area tmp1 = array.getInternal(0);
		return ((__struct__) tmp1).getPtr(fieldName);
	}

	public int getInt(String fieldName) {
		final Area tmp1 = array.getInternal(0);
		return ((__struct__) tmp1).getInt(fieldName);
	}

	public double getDouble(String fieldName) {
		final Area tmp1 = array.getInternal(0);
		return ((__struct__) tmp1).getDouble(fieldName);
	}

}
