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

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import smetana.core.JUtils;

public class MethodArguments {

	private final List<MethodArgument> args = new ArrayList<MethodArgument>();

	public MethodArguments(String strings, List<String> list) {
		strings = strings.trim();
		if (strings.equals("void")) {
			return;
		}
		if (strings.matches("(\\w+\\s*)(,\\s*\\w+\\s*)*")) {
			JUtils.LOG("Strings1=" + strings);
			strings = rebuild(list);
			JUtils.LOG("Strings2=" + strings);
		}
		strings = strings.replaceAll("\\((\\*\\w+)\\)", "$1");
		strings = strings.replaceAll("\\([^()]*\\)", "").trim();

		if (strings.length() > 0) {
			for (String s : strings.split(",")) {
				args.add(new MethodArgument(s.trim()));
			}
		}

	}

	private String rebuild(List<String> subList) {
		final StringBuilder sb = new StringBuilder();
		for (int i = 0; i < subList.size(); i++) {
			String s;
			if (i == 0) {
				s = subList.get(i).replace('\n', ' ').trim();
				final int x = s.indexOf(')');
				if (x == -1) {
					throw new IllegalStateException();
				}
				s = s.substring(x + 1);
			} else {
				s = subList.get(i).trim();
			}
			if (s.equals(";")) {
				continue;
			}
			if (s.equals("")) {
				continue;
			}
			if (s.equals("{")) {
				return sb.toString();
			}
			JUtils.LOG("s22=" + s);
			if (sb.length() > 0) {
				sb.append(", ");
			}
			sb.append(s);
			sb.append(" ");
		}
		throw new IllegalStateException();
	}

	@Override
	public String toString() {
		return args.toString();
	}

	public Iterator<MethodArgument> argumentsIterator() {
		return args.iterator();
	}

	public boolean hasStruct() {
		for (MethodArgument arg : args) {
			if (arg.hasStruct()) {
				return true;
			}
		}
		return false;
	}

}
