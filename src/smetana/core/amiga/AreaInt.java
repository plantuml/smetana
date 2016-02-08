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

public class AreaInt implements Area {

	private int data = 0;

	private final int UID = StarStruct.CPT++;

	private String getUID36() {
		return Integer.toString(UID, 36);
	}

	@Override
	public String toString() {
		return "AreaArray " + getUID36() + " " + data;
	}

	public void memcopyFrom(Area source) {
		AreaInt other = (AreaInt) source;
		this.data = other.data;
	}

	public void setInternal(int data) {
		this.data = data;
		if (trace()) {
			System.err.println("set I AM " + this);
		}
	}

	private boolean trace() {
		return getUID36().equals("2z7");
	}

	public int getInternal() {
		if (trace()) {
			// System.err.println("get I AM " + this);
		}
		return data;
	}

	// public void incInternal(int increment) {
	// data += increment;
	//
	// }
}
