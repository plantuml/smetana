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

import java.util.ArrayList;
import java.util.List;

import smetana.core.amiga.Area;

public class CObject implements Area {

	private static int ID;

	private final int size;
	private int id = ++ID;

	public CObject(int size, Class tobeAllocated) {
		this.size = size;
	}

	@Override
	public String toString() {
		return super.toString() + " id=" + id;
	}

	public List<CString> convertToListOfCString() {
		final ArrayList<CString> result = new ArrayList<CString>();
		for (int i = 0; i < size; i++) {
			result.add(null);
		}
		return result;
	}

//	public AreaArray convertToAreaArray() {
//		return new AreaArray(size, new BuilderArea() {
//			public Area createArea() {
//				return null;
//			}
//		});
//	}

	public void memcopyFrom(Area source) {
		throw new UnsupportedOperationException();
	}
	
}
