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

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import smetana.core.amiga.Area;

public class CFunctionImpl extends UnsupportedC implements CFunction, Area {

	private final Class codingClass;
	private final String name;
	private final Method method;

	public static CFunctionImpl create(Class codingClass, String name) {
		return new CFunctionImpl(codingClass, name);
	}

	private CFunctionImpl(Class codingClass, String name) {
		this.codingClass = codingClass;
		this.name = name;
		for (Method m : codingClass.getMethods()) {
			if (m.getName().equals(name)) {
				this.method = m;
				return;
			}
		}
		JUtils.LOG("CANNOT FIND METHOD " + name + " IN " + codingClass);
		throw new IllegalStateException("codingClass=" + codingClass + " name=" + name);
	}

	@Override
	public String toString() {
		return codingClass.getName() + "::" + name;
	}

	public Object exe(Object... args) {
		for (Object arg : args) {
			JUtils.LOG("arg=" + arg);
		}
		try {
			return this.method.invoke(null, args);
		} catch (InvocationTargetException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException(toString());
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException(toString());
		} catch (IllegalAccessException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException(toString());
		}
	}

	public String getName() {
		return name;
	}

	public void memcopyFrom(Area source) {
		throw new UnsupportedOperationException();
	}
	
}
