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
import smetana.core.amiga.AreaInt;
import smetana.core.amiga.BuilderArea;
import smetana.core.amiga.StarArrayOfPtr;
import smetana.core.amiga.StarStruct;

public class __array_of_ptr__ implements Area {

	private final List<Area> data;
	private final int currentPos;
	private final BuilderArea builder;

	private final int UID = StarStruct.CPT++;

	public String getUID36() {
		return Integer.toString(UID, 36);
	}

	public void swap(int i, int j) {
		Area e1 = data.get(i);
		Area e2 = data.get(j);
		data.set(i, e2);
		data.set(j, e1);
	}

	@Override
	public String toString() {
		if (data.get(0) != null) {
			return "__array__ " + getUID36() + " " + currentPos + "/" + data.size() + " " + data.get(0).toString();
		}
		return "__array__ " + getUID36() + " " + currentPos + "/" + data.size();
	}

	public void realloc(int nb) {
		while (data.size() < nb + currentPos) {
			data.add(builder.createArea());
		}
	}

	public __ptr__ asPtr() {
		return new StarArrayOfPtr(this);
	}

	public int comparePointerInternal(__array_of_ptr__ other) {
		if (this.data != other.data) {
			throw new IllegalArgumentException();
		}
		return this.currentPos - other.currentPos;
	}

	public static __array_of_ptr__ malloc_allocated(final Class cl, int nb) {
		return new __array_of_ptr__(nb, new BuilderArea() {
			public Area createArea() {
				return new StarStruct(cl, null);
			}
		});
	}

	public static __array_of_ptr__ malloc_empty(int nb) {
		return new __array_of_ptr__(nb, new BuilderArea() {
			public Area createArea() {
				return null;
			}
		});
	}

	private __array_of_ptr__(List<Area> data, int currentPos, BuilderArea builderArea) {
		this.data = data;
		this.currentPos = currentPos;
		this.builder = builderArea;
		check();
	}

	private __array_of_ptr__(int size, BuilderArea builder) {
		this.data = new ArrayList<Area>();
		this.builder = builder;
		this.currentPos = 0;
		for (int i = 0; i < size; i++) {
			data.add(builder.createArea());
		}
		check();
	}

	private void check() {
		if (getUID36().equals("194")) {
			JUtils.LOG("It's me");
		}
	}

	public __array_of_ptr__ move(int delta) {
		return new __array_of_ptr__(data, currentPos + delta, builder);
	}

	public __array_of_ptr__ plus(int delta) {
		return move(delta);
	}

	public Area getInternal(int idx) {
		return data.get(idx + currentPos);
	}

	public void setInternalByIndex(int idx, Area value) {
		if (value == this) {
			throw new IllegalArgumentException();
		}
		if (value instanceof __array_of_ptr__) {
			throw new IllegalArgumentException();
		}
		data.set(idx + currentPos, value);
	}

	public void memcopyFrom(Area source) {
		throw new UnsupportedOperationException();
	}

	//

	public int getInt() {
		return ((AreaInt) getInternal(0)).getInternal();
	}

	public CString getCString() {
		return (CString) getInternal(0);
	}

	public __ptr__ getPtr() {
		if (getInternal(0) instanceof __struct__) {
			return ((__struct__) getInternal(0)).amp();
		}
		return (__ptr__) getInternal(0);
	}

	public __struct__ getStruct() {
		if (getInternal(0) instanceof __ptr__) {
			return getPtr().getStruct();
		}
		return (__struct__) getInternal(0);
	}

	public void setInt(int value) {
		((AreaInt) getInternal(0)).setInternal(value);
	}

	public void setCString(CString value) {
		setInternalByIndex(0, value);
	}

	public void setPtr(__ptr__ value) {
		setInternalByIndex(0, (Area) value);
	}

	public void setStruct(__struct__ value) {
		final Area area = getInternal(0);
		if (area instanceof StarStruct) {
			((StarStruct) area).copyDataFrom(value);
		} else if (area instanceof StarArrayOfPtr) {
			((StarArrayOfPtr) area).copyDataFrom(value);
		} else {
			((__struct__) area).____(value);
		}
	}

	public double getDouble(String fieldName) {
		final Area tmp1 = getInternal(0);
		return ((StarStruct) tmp1).getDouble(fieldName);
	}

	public void setDouble(String fieldName, double value) {
		final Area tmp1 = getInternal(0);
		if (tmp1 instanceof __struct__) {
			((__struct__) tmp1).setDouble(fieldName, value);
			return;
		}
		((StarStruct) tmp1).setDouble(fieldName, value);
	}

	public __struct__ getStruct(String fieldName) {
		return ((StarStruct) getInternal(0)).getStruct(fieldName);
	}

}
