/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program.
 * 
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
