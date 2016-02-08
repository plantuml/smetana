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
package smetana.job.jgenerator;

public class MethodArgument {

	private final String full;
	private final String name;

	public MethodArgument(String s) {
		this.full = s.trim();
		final String split[] = s.split(" ");
		this.name = split[split.length - 1].replace('*', ' ').trim();
	}

	@Override
	public String toString() {
		return name + "={" + full + "}";
	}

	public String getName() {
		return name;
	}

	public boolean hasStruct() {
		if (full.equals("boxf rv[]")) {
			return false;
		}
		if (full.equals("pointf curve[4]")) {
			return false;
		}
		if (full.equals("boolean*inside")) {
			return false;
		}
		if (full.equals("void")) {
			return false;
		}
		if (full.endsWith(name) == false) {
			throw new IllegalStateException(name);
		}
		final String type = full.substring(0, full.length() - name.length()).trim();
		if (MethodWrapping.notStruct(type)) {
			return false;
		}
		// System.err.println("type=" + type);
		if (type.trim().length() == 0) {
			System.err.println("ERROR " + full);
		}
		return true;
	}

}
