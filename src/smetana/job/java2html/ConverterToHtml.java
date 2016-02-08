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
package smetana.job.java2html;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

import de.java2html.converter.JavaSource2HTMLConverter;
import de.java2html.javasource.JavaSource;
import de.java2html.javasource.JavaSourceParser;
import de.java2html.options.JavaSourceConversionOptions;
import de.java2html.options.JavaSourceStyleTable;

public class ConverterToHtml {

	private final File src;
	private final List<String> lines = new ArrayList<String>();

	public ConverterToHtml(File f) throws IOException {
		if (f.exists() == false) {
			throw new IllegalArgumentException(f.getAbsolutePath());
		}
		this.src = f;
		final BufferedReader br = new BufferedReader(new FileReader(f));
		String s;
		while ((s = br.readLine()) != null) {
			lines.add(s);
		}
		br.close();
	}

	// public static void mainOld(String[] args) {
	// JavaSource src = new JavaSource("toto=3;\n");
	// System.err.println("src=" + src);
	// System.err.println("src=" + src.getStatisticsString());
	// }
	//
	// public static void main(String[] args) throws IOException {
	// JavaSourceParser parser = new JavaSourceParser();
	// JavaSource src = parser.parse("toto=3;\n");
	// System.err.println("src=" + src.getStatisticsString());
	//
	// JavaSource2HTMLConverter cvt = new JavaSource2HTMLConverter();
	// JavaSourceConversionOptions option = JavaSourceConversionOptions.getDefault();
	// JavaSourceStyleTable style = JavaSourceStyleTable.getDefaultEclipseStyleTable();
	// option.setShowLineNumbers(true);
	// option.setStyleTable(style);
	// File f = new File("out.html");
	// BufferedWriter writer = new BufferedWriter(new FileWriter(f));
	// cvt.convert(src, option, writer);
	// writer.close();
	// }

	private Reader getJavaSource() {
		final StringBuilder sb = new StringBuilder();
		for (String s : lines) {
			if (s.contains("!!!!!!!!!!!!!!!!")) {
				return new StringReader(sb.toString());
			}
			sb.append(s);
			sb.append("\n");
		}
		throw new IllegalStateException();
	}

	public int nbJavaSourceLines() {
		int nb = 0;
		for (String s : lines) {
			if (s.contains("!!!!!!!!!!!!!!!!")) {
				return nb;
			}
			nb++;
		}
		throw new IllegalStateException();
	}

	private Reader getCSource() {
		final StringBuilder sb = new StringBuilder();
		boolean skip = true;
		for (String s : lines) {
			if (s.contains("!!!!!!!!!!!!!!!!")) {
				skip = false;
			} else if (skip == false) {
				sb.append(s);
				sb.append("\n");
			}
		}
		return new StringReader(sb.toString());
	}

	public void exportCToHtml(final BufferedWriter writer) throws IOException {
		JavaSourceParser parser = new JavaSourceParser();
		JavaSource javasrc = parser.parse(getCSource());
		exportToHtml(writer, javasrc);
	}

	public void exportJavaToHtml(final BufferedWriter writer) throws IOException {
		JavaSourceParser parser = new JavaSourceParser();
		JavaSource javasrc = parser.parse(getJavaSource());
		exportToHtml(writer, javasrc);
	}

	private void exportToHtml(final BufferedWriter writer, JavaSource javasrc) throws IOException {
		JavaSource2HTMLConverter cvt = new JavaSource2HTMLConverter();
		JavaSourceConversionOptions option = JavaSourceConversionOptions.getDefault();
		JavaSourceStyleTable style = JavaSourceStyleTable.getDefaultEclipseStyleTable();
		option.setShowLineNumbers(true);
		option.setStyleTable(style);
		cvt.convert(javasrc, option, writer);
	}
}
