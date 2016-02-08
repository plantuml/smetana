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

public class CEnumInterpretor {

	private final List<String> keys = new ArrayList<String>();
	private String keyRef;
	private int valueRef;

	public CEnumInterpretor(Class enumClass) {
		List<String> def = CType.getDefinition(enumClass);
		JUtils.LOG("def1=" + def);
		if (def.get(0).equals("typedef enum") == false) {
			throw new IllegalArgumentException();
		}
		if (def.get(1).equals("{") == false) {
			throw new IllegalArgumentException();
		}
		if (def.get(def.size() - 2).equals("}") == false) {
			throw new IllegalArgumentException();
		}
		def = def.subList(2, def.size() - 2);
		JUtils.LOG("def2=" + def);

		for (String s1 : def) {
			for (String s2 : s1.split(",")) {
				s2 = s2.trim();
				final int idx = s2.indexOf('=');
				final String k = idx == -1 ? s2 : s2.substring(0, idx);
				keys.add(k.trim());
				if (idx == -1) {
					continue;
				}
				if (keyRef != null) {
					throw new IllegalStateException();
				}
				keyRef = k.trim();
				valueRef = Integer.parseInt(s2.substring(idx + 1).trim());
			}
		}
		JUtils.LOG("keys=" + keys);
	}

	public int valueOf(String name) {
		JUtils.LOG("keys=" + keys);
		final int idx = keys.indexOf(name);
		if (idx == -1) {
			throw new IllegalArgumentException(name + " is no enum value");
		}
		if (keyRef == null) {
			return idx;
		}
		final int keyRefIndex = keys.indexOf(keyRef);
		if (keyRefIndex == -1) {
			throw new IllegalStateException();
		}
		return idx - keyRefIndex + valueRef;
	}
}
