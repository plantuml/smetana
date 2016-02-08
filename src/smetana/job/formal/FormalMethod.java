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
package smetana.job.formal;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class FormalMethod implements Comparable<FormalMethod> {

	private static final List<FormalMethod> all = new ArrayList<FormalMethod>();

	public static void register(String pack, String file, String name, String[] tokens) {
		final FormalMethod formalMethod = new FormalMethod(pack, file, name, tokens);
		all.add(formalMethod);
	}

	final private String pack;
	final private String file;
	final private String methodName;

	final private Set<String> tokens = new HashSet<String>();

	@Override
	public String toString() {
		return pack + " - " + file + " - " + methodName;
	}

	public int compareTo(FormalMethod other) {
		int ret = pack.compareTo(other.pack);
		if (ret != 0) {
			return ret;
		}
		ret = file.compareTo(other.file);
		if (ret != 0) {
			return ret;
		}
		ret = methodName.compareTo(other.methodName);
		return ret;
	}

	public FormalMethod(String pack, String file, String name, String[] tokensArg) {
		this.pack = pack;
		this.file = file;
		this.methodName = name;
		for (String t : tokensArg) {
			if (t.length() > 0) {
				tokens.add(t);
			}
		}
	}

	public List<FormalMethod> getUsedMethods() {
		final List<FormalMethod> result = new ArrayList<FormalMethod>();
		for (FormalMethod m : all) {
			if (m == this) {
				continue;
			}
			if (tokens.contains(m.methodName)) {
				result.add(m);
			}
		}
		return result;
	}

	public static List<FormalMethod> getMethodsByName(String name) {
		final List<FormalMethod> result = new ArrayList<FormalMethod>();
		for (FormalMethod m : all) {
			if (name.equals(m.methodName)) {
				result.add(m);
			}
		}
		return result;
	}

	public Set<String> getUsedMethodNames() {
		final Set<String> result = new TreeSet<String>();
		for (FormalMethod m : all) {
			if (m == this) {
				continue;
			}
			if (tokens.contains(m.methodName)) {
				result.add(m.methodName);
			}
		}
		return result;
	}

	public static List<FormalMethod> getAll() {
		Collections.sort(all);
		return all;
	}

	public String getMethodName() {
		return methodName;
	}

	public static void addAllCallingThis(Set<String> called, String methodName) {
		for (FormalMethod m : FormalMethod.getMethodsByName(methodName)) {
			called.addAll(m.getUsedMethodNames());
		}
	}

}
