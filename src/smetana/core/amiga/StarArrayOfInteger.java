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
import smetana.core.__array_of_integer__;
import smetana.core.__ptr__;
import smetana.struct.AllH;

public class StarArrayOfInteger extends UnsupportedC implements Area, AllH {

	private final __array_of_integer__ array;

	public StarArrayOfInteger(__array_of_integer__ array) {
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

	public final __array_of_integer__ getInternalArray() {
		return array;
	}

	public __ptr__ plus(int pointerMove) {
		return new StarArrayOfInteger(array.move(pointerMove));
	}

	public void setInt(int value) {
		array.setInt(value);
	}

	public int getInt() {
		return array.getInt();
	}


}
