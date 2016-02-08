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
import smetana.core.__array_of_ptr__;
import smetana.core.__ptr__;

public class StarStar extends UnsupportedC implements Area {

	private Area area;

	StarStar(Area area) {
		this.area = area;
	}

	public static StarStar array_of_array_of_something_empty(final Class cl, int nb) {
		// if (allocated) {
		// return new StarStar(__array__.malloc(cl, nb));
		// }
		return new StarStar(__array_of_ptr__.malloc_empty(nb));
	}

	public String toString() {
		return "->" + area;
	}

	Area getArea() {
		return area;
	}

	public void swap(int i, int j) {
		((__array_of_ptr__) area).swap(i, j);

	}

	public void memcopyFrom(Area source) {
		StarStar other = (StarStar) source;
		this.area = other.area;
	}

	// public __ptr__ getBracket(int idx) {
	// return ((AreaArray) area).getBracket(idx);
	// }
	//
	public void realloc(int nb) {
		((__array_of_ptr__) area).realloc(nb);
	}

	//
	// // __c__
	// public void setBracket(int idx, Object data) {
	// ((AreaArray) area).setBracket(idx, data);
	// }
	//
	// public __ptr__ plus(int pointerMove) {
	// return ((AreaArray) area).plus(pointerMove);
	// }

	public __ptr__ plus(int pointerMove) {
		return new StarStar(((__array_of_ptr__) area).move(pointerMove));
	}

	public __ptr__ getPtr(String fieldName) {
		return ((__array_of_ptr__) area).asPtr().getPtr(fieldName);
	}

	public __ptr__ getPtr() {
		return (__ptr__) ((__array_of_ptr__) area).getInternal(0);
	}

	public void setPtr(__ptr__ value) {
		((__array_of_ptr__) area).setInternalByIndex(0, (Area) value);
	}

	public void setDouble(String fieldName, double data) {
		throw new UnsupportedOperationException(getClass().toString());
	}

	public int comparePointer(__ptr__ other) {
		return ((__array_of_ptr__) area).comparePointerInternal(((__array_of_ptr__) ((StarStar) other).area));
	}

}
