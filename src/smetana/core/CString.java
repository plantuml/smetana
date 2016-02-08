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
import smetana.core.amiga.StarStruct;

public class CString extends UnsupportedC implements __ptr__, Area {

	private final Throwable creation = new Throwable();
	private final List<Character> data2;
	private final int currentStart;
	private final List<__ptr__> fathers = new ArrayList<__ptr__>();

	public boolean isSameThan(CString other) {
		if (this.data2 != other.data2) {
			throw new UnsupportedOperationException();
		}
		return this.currentStart == other.currentStart;

	}

	public CString(String string) {
		this(new ArrayList<Character>(), 0);
		for (int i = 0; i < string.length(); i++) {
			data2.add(string.charAt(i));
		}
		data2.add('\0');
	}

	public CString duplicate() {
		// return this;

		return new CString(new ArrayList<Character>(this.data2), currentStart);

		// final CString result = new CString(this.data.size());
		// for (int i = 0; i < result.data.size(); i++) {
		// result.data.set(i, this.data.get(i));
		// }
		// return result;
	}

	public CString strdup() {
		return duplicate();
	}

	public CString(int size) {
		this(new ArrayList<Character>(), 0);
		for (int i = 0; i < size; i++) {
			data2.add('\0');
		}
	}

	private CString(List<Character> data2, int currentStart) {
		this.data2 = data2;
		this.currentStart = currentStart;
		creation.fillInStackTrace();
	}

	public __ptr__ addVirtualBytes(int bytes) {
		JUtils.LOG("CString::addVirtualBytes " + bytes);
		JUtils.LOG("AM " + this);
		if (bytes < 0) {
			OFFSET offset = OFFSET.fromInt(-bytes);
			JUtils.LOG("offset=" + offset);
			for (__ptr__ f : fathers) {
				JUtils.LOG("f=" + f);
				if (f instanceof StarStruct && ((StarStruct) f).getRealClass() == offset.getTheClass()) {
					JUtils.LOG("FOUND1!!");
					if (f.getPtr(offset.getField()).equals(this)) {
						JUtils.LOG("FOUND2!!");
						return f;
					}
				}
			}
		} else {
			JUtils.LOG("father=" + fathers);
			JUtils.LOG("CString created on the following place:");
			creation.printStackTrace();
		}
		throw new UnsupportedOperationException();
	}

	@Override
	public CString plus(int pointerMove) {
		return new CString(data2, currentStart + pointerMove);
	}

	@Override
	public String toString() {
		final StringBuilder sb = new StringBuilder();
		for (Character c : getData()) {
			if (c == '\0') {
				sb.append("(0)");
			} else {
				sb.append(c);
			}
		}
		return "CString:" + sb;
	}

	private List<Character> getData() {
		return data2.subList(currentStart, data2.size());
	}

	public String getContent() {
		final StringBuilder sb = new StringBuilder();
		for (Character c : getData()) {
			if (c == '\0') {
				return sb.toString();
			} else {
				sb.append(c);
			}
		}
		throw new UnsupportedOperationException();
	}

	public char charAt(int i) {
		return getData().get(i);
	}

	public char setCharAt(int i, char c) {
		getData().set(i, c);
		return c;
	}

	public int length() {
		int len = 0;
		for (Character c : getData()) {
			if (c == '\0') {
				return len;
			}
			len++;
		}
		throw new IllegalStateException();
	}

	public int compareTo(CString other) {
		for (int i = 0; i < data2.size() - currentStart; i++) {
			final int diff = this.charAt(i) - other.charAt(i);
			if (this.charAt(i) == '\0' || diff != 0) {
				return diff;
			}
		}
		throw new IllegalStateException();
	}

	public void copyFrom(CString source, int nb) {
		for (int i = 0; i < source.length() + 1 && i < nb; i++) {
			setCharAt(i, source.charAt(i));
		}
	}

	public CString strchr(char c) {
		for (int i = currentStart; i < data2.size(); i++) {
			if (data2.get(i).charValue() == c) {
				return new CString(data2, i);
			}
		}
		return null;
	}

	public boolean isSame(CString other) {
		return getContent().equals(other.getContent());
	}

	public void setMyFather(__ptr__ struct) {
		if (this.toString().equals("black(0)")) {
			JUtils.LOG("CString::setMyFather " + this + "  " + fathers.size());
		}
		this.fathers.add(struct);
	}

	public void memcopyFrom(Area source) {
		throw new UnsupportedOperationException();
	}
	
}
