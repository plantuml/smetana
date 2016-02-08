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

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class FileStringParser implements Iterable<String> {

	private final List<String> strings = new ArrayList<String>();

	public FileStringParser(File f) throws IOException {
		if (f.exists() == false) {
			throw new IllegalArgumentException();
		}
		final BufferedInputStream bis = new BufferedInputStream(new FileInputStream(f));
		init(bis);
		bis.close();
	}

	public FileStringParser(List<String> raw) {
		final ByteArrayOutputStream baos = new ByteArrayOutputStream();
		final PrintWriter pw = new PrintWriter(baos);
		for (String s : raw) {
			pw.println(s);
		}
		pw.close();
		final ByteArrayInputStream bis = new ByteArrayInputStream(baos.toByteArray());
		try {
			init(bis);
			bis.close();
		} catch (IOException e) {
			e.printStackTrace();
			throw new IllegalStateException();
		}
	}

	private void init(InputStream is) throws IOException {
		final StringBuilder data = new StringBuilder();
		while (true) {
			final int read = is.read();
			if (read == -1) {
				break;
			}
			data.append((char) read);
		}
		final String full = data.toString().replaceAll("_END_EXTERNS_", "");
		// System.err.println("full=" + full);
		for (int i = 0; i < full.length(); i++) {
			if (strings.size() > 1) {
				// System.err.println(strings.get(strings.size() - 1));
			}
			final char current = full.charAt(i);
			if (isSeparator(current)) {
				strings.add("" + current);
			} else if (current == '/' && full.charAt(i + 1) == '*') {
				int end = i + 2;
				while (full.charAt(end - 1) != '*' || full.charAt(end) != '/') {
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (current == '/' && full.charAt(i + 1) == '/') {
				int end = i + 2;
				while (full.charAt(end) != '\n') {
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (current == '\"') {
				int end = i + 1;
				while (full.charAt(end) != '\"') {
					if (full.charAt(end) == '\\') {
						end++;
					}
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (current == '\'') {
				int end = i + 1;
				while (full.charAt(end) != '\'') {
					if (full.charAt(end) == '\\') {
						end++;
					}
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (current == '#') {
				int end = i + 1;
				while (full.charAt(end) != '\n') {
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (isCarriageReturn(current)) {
				int end = i;
				while (end < full.length() - 1 && isCarriageReturn(full.charAt(end + 1))) {
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else if (isWhitespaceButCarriageReturn(current)) {
				int end = i;
				while (end < full.length() - 1 && isWhitespaceButCarriageReturn(full.charAt(end + 1))) {
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			} else {
				int end = i;
				while (end < full.length() - 1 && isBreakSeparator(full.charAt(end + 1)) == false) {
					if (end < full.length() - 2 && full.substring(end + 1, end + 3).equals("/*")) {
						break;
					}
					if (end < full.length() - 2 && full.substring(end + 1, end + 3).equals("//")) {
						break;
					}
					end++;
				}
				strings.add(full.substring(i, end + 1));
				i = end;
			}
		}
		// System.err.println(strings);
	}

	private boolean isCarriageReturn(final char current) {
		return current == '\n';
	}

	private boolean isWhitespaceButCarriageReturn(final char current) {
		return isCarriageReturn(current) == false && Character.isWhitespace(current);
	}

	private boolean isSeparator(char c) {
		return c == ';' || c == '{' || c == '}';
	}

	private boolean isBreakSeparator(char c) {
		return c == ';' || c == '{' || c == '}' || c == '\"' || c == '\'';
	}

	public Iterator<String> iterator() {
		return strings.iterator();
	}
}
