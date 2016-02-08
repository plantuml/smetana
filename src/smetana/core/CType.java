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

import h.htmllabel_t;
import h.pointf;

import java.lang.reflect.Field;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CType {

	final private String type;

	CType(String type) {
		this.type = type;
		if (type.equals("void")) {
			throw new IllegalArgumentException();
		}
	}

	public boolean isInteger() {
		return type.equals("int") || type.equals("packval_t");
	}

	public boolean isChar() {
		return type.equals("char");
	}

	public boolean isBoolean() {
		return type.equals("boolean");
	}

	public boolean isDoubleOrFloat() {
		return type.equals("double") || type.equals("float");
	}

	public boolean isShort() {
		return type.equals("short");
	}

	public boolean isLong() {
		return type.equals("long");
	}

	public boolean isEnum() {
		JUtils.LOG("IS ENUM " + this);
		if (functionPointer() || isVoidStar() || isInteger() || isChar() || isCString() || isBoolean()
				|| isDoubleOrFloat() || isShort() || isLong()) {
			return false;
		}
		if (getType().contains("*")) {
			return false;
		}
		if (getType().contains("[")) {
			return false;
		}
		final Class cl = getTypeClass();
		if (cl == null) {
			return false;
		}
		List<String> def = CType.getDefinition(cl);
		JUtils.LOG("def3=" + def);
		if (def.get(0).equals("typedef enum")) {
			return true;
		}
		return false;
	}

	@Override
	public String toString() {
		return "CTYPE:" + type;
	}

	public Class getTypeClass() {
		if (isPrimitive()) {
			return null;
		}
		return getClassFrom(type);
	}

	public static Class getClassFrom(String type) {
		if (type == null) {
			throw new IllegalArgumentException();
		}
		if (type.equals("h.pointf_s")) {
			return pointf.class;
		}
		if (type.equals("pointf_s")) {
			return pointf.class;
		}
		if (type.endsWith("htmllabel_t")) {
			return htmllabel_t.class;
		}
		try {
			final Class result = Class.forName("h." + type);
			final List<String> definition = getDefinition(result);
			if (definition.size() != 1) {
				return result;
			}
			final String single = definition.get(0);
			final Pattern p1 = Pattern.compile("^typedef\\s+struct\\s+(\\w+)\\s+(\\w+)$");
			final Matcher m1 = p1.matcher(single);
			if (m1.find() == false) {
				// return null;
				throw new IllegalStateException(single);
			}
			if (m1.group(2).equals(type) == false) {
				throw new IllegalStateException(single);
			}
			return getClassFrom(m1.group(1));
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	private List<String> getDefinition() {
		return getDefinition(getTypeClass());
	}

	static List<String> getDefinition(Class inter) {
		try {
			// JUtils.LOG("TR1=" + inter);
			if (inter == null) {
				return null;
			}
			final Field field = inter.getField("DEFINITION");
			return (List<String>) field.get(null);
		} catch (NoSuchFieldException e) {
			System.err.println("inter="+inter);
			e.printStackTrace();
			throw new UnsupportedOperationException();
		} catch (SecurityException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
			throw new UnsupportedOperationException();
		}
	}

	public boolean functionPointer() {
		// int (*foo)()
		if (isPrimitive()) {
			return false;
		}
		boolean result = type.matches("^.*(\\(\\*(\\w+)\\)).*$");
		if (result == true) {
			return true;
		}
		try {
			final List<String> definition = getDefinition(Class.forName("h." + type));
			JUtils.LOG("def=" + definition);
			if (definition.size() != 1) {
				return false;
			}
			assert definition.size() == 1;
			result = definition.get(0).matches("^.*(\\(\\*(\\w+)\\)).*$");
			JUtils.LOG("checking " + type + " " + result);
			return result;
		} catch (ClassNotFoundException e) {
			JUtils.LOG("typeXXX=" + type);
			return false;
		}

	}

	public static boolean isPrimitive(String type) {
		if (type.equals("char") || type.equals("long") || type.equals("int") || type.equals("packval_t")
				|| type.equals("boolean") || type.equals("double") || type.equals("float") || type.equals("short")) {
			return true;
		}
		return false;
	}

	public boolean isPrimitive() {
		return isPrimitive(type);
	}

	public Class getClassFrom() {
		return getClassFrom(type);
	}

	public int getArrayLength() {
		final Pattern p = Pattern.compile(".*\\[(\\d+)\\]$");
		final Matcher m = p.matcher(type);
		if (m.find() == false) {
			return 0;
		}
		return Integer.parseInt(m.group(1));
	}

	public boolean isIntStar() {
		return "int*".equals(type);
	}

	public boolean isVoidStar() {
		return "void*".equals(type);
	}

	public String getType() {
		return type;
	}

	public boolean isCString() {
		return type.equals("CString");
	}

	public boolean isArrayOfCString() {
		return type.equals("CString[]");
	}

	public boolean containsStar() {
		return type.contains("*");
	}

}
