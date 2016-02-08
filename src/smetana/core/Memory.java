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

import java.util.HashMap;
import java.util.Map;

import smetana.core.amiga.StarArrayOfPtr;
import smetana.core.amiga.StarStruct;


public class Memory {

	public static __ptr__ malloc(Class cl) {
		JUtils.LOG("MEMORY::malloc " + cl);
		return StarStruct.malloc(cl);
	}

	public static __ptr__ malloc(size_t size) {
		return (__ptr__) size.malloc();
	}

	public static __ptr__ realloc(__ptr__ old, size_t size) {
		if (old instanceof StarArrayOfPtr) {
			((StarArrayOfPtr) old).realloc(((size_t_array_of_something) size).getNb());
			return old;

		}
		throw new UnsupportedOperationException();
	}

	public static void free(Object arg) {
	}

	private static Map<Integer, Object> all = new HashMap<Integer, Object>();

	public static int identityHashCode(Object data) {
		int result = System.identityHashCode(data);
		all.put(result, data);
		System.err.println("Memory::identityHashCode data=" + data);
		System.err.println("Memory::identityHashCode " + result + " " + all.size());
		return result;
	}

	public static Object fromIdentityHashCode(int hash) {
		System.err.println("Memory::fromIdentityHashCode hash=" + hash);
		Object result = all.get(hash);
		System.err.println("Memory::fromIdentityHashCode result=" + result);
		if (result == null) {
			throw new UnsupportedOperationException();
		}
		return result;
	}

}
