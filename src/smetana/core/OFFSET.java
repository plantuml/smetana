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

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class OFFSET {

	private static int CPT = 10000;
	private static Map<Integer, OFFSET> byID = new HashMap<Integer, OFFSET>();
	private static Map<Object, OFFSET> primaryKey = new HashMap<Object, OFFSET>();

	private final Class cl;
	private final String field;
	private final int id;

	private OFFSET(Class cl, String field) {
		this.cl = cl;
		this.field = field;
		this.id = CPT++;
		JUtils.LOG("REAL CREATING OF " + this);
	}

	@Override
	public String toString() {
		return cl.getName() + "::" + field;
	}

	public static OFFSET create(Class cl, String field) {
		final Object key = Arrays.asList(cl, field);
		JUtils.LOG("getting OFFSET " + key);
		OFFSET result = primaryKey.get(key);
		if (result != null) {
			JUtils.LOG("FOUND!");
			return result;
		}
		result = new OFFSET(cl, field);
		byID.put(result.id, result);
		primaryKey.put(key, result);
		return result;
	}

	public int toInt() {
		return id;
	}

	public static OFFSET fromInt(int value) {
		final OFFSET result = byID.get(value);
		if (result == null) {
			throw new IllegalArgumentException("value=" + value);
		}
		return result;
	}

	public final Class getTheClass() {
		return cl;
	}

	public final String getField() {
		return field;
	}

}
