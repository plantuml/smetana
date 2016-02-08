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

import java.util.Iterator;
import java.util.List;

public class MethodWrapping {

	private final String methodName;
	private final MethodArguments args;
	private final boolean returnStruct;
	private final boolean returnVoid;

	private MethodWrapping(String methodName, MethodArguments args, boolean returnStruct, boolean returnVoid) {
		this.methodName = methodName;
		this.args = args;
		this.returnVoid = returnVoid;
		this.returnStruct = returnStruct;
	}

	public static MethodWrapping create(String methodName, List<String> list) {
		String s = list.get(0).replace('\n', ' ').replace('\r', ' ');
		s = s.replaceAll("\\bstatic\\b", "");
		s = s.replaceAll("\\binline\\b", "");
		s = s.replaceAll("\\bconst\\b", "");
		s = s.replaceAll("\\bregister\\b", "");
		s = s.replaceAll("\\bunsigned\\b", "");
		s = s.trim();

		final int x1 = s.indexOf('(');
		final String start = s.substring(0, x1).trim();
		if (start.endsWith(methodName) == false) {
			throw new IllegalStateException(s + "  :  " + methodName);
		}
		final String ret = start.substring(0, start.length() - methodName.length()).trim();
		final int x2 = s.lastIndexOf(')');
		final MethodArguments args = new MethodArguments(s.substring(x1 + 1, x2).trim(), list);

		if (notStruct(ret) == false || args.hasStruct()) {
			if (methodName.equals("poly_path")) {
				System.err.println("FOO=" + list.get(0));
				System.err.println("notStruct(ret)=" + notStruct(ret));
				System.err.println("args.hasStruct()=" + args.hasStruct());
			}
			return new MethodWrapping(methodName, args, notStruct(ret) == false, ret.equals("void"));
		}

		return null;
	}

	public static boolean notStruct(final String ret) {
		return ret.endsWith("*") || ret.equals("int") || ret.equals("void") || ret.equals("boolean")
				|| ret.equals("char") || ret.equals("size_t") || ret.equals("long") || ret.equals("double")
				|| ret.equals("shape_kind") || ret.equals("api_t") || ret.equals("pack_mode");
	}

	public Iterator<MethodArgument> argumentsIterator() {
		return args.argumentsIterator();
	}

	public boolean doesReturnStruct() {
		return returnStruct;
	}

	public boolean isReturnVoid() {
		return returnVoid;
	}

}
