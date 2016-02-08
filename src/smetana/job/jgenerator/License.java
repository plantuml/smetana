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
import java.util.Collections;
import java.util.List;

public class License {

	public static List<String> getJavaHeader() {
		final List<String> h = new ArrayList<String>();
		h.add("/* ========================================================================");
		h.add(" * PlantUML : a free UML diagram generator");
		h.add(" * ========================================================================");
		h.add(" *");
		h.add(" * (C) Copyright 2009-2017, Arnaud Roques");
		h.add(" *");
		h.add(" * Project Info:  http://plantuml.com");
		h.add(" * ");
		h.add(" * This file is part of PlantUML.");
		h.add(" *");
		h.add(" * PlantUML is free software; you can redistribute it and/or modify it");
		h.add(" * under the terms of the GNU General Public License as published by");
		h.add(" * the Free Software Foundation, either version 3 of the License, or");
		h.add(" * (at your option) any later version.");
		h.add(" *");
		h.add(" * PlantUML distributed in the hope that it will be useful, but");
		h.add(" * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY");
		h.add(" * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public");
		h.add(" * License for more details.");
		h.add(" *");
		h.add(" * You should have received a copy of the GNU Lesser General Public");
		h.add(" * License along with this library; if not, write to the Free Software");
		h.add(" * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,");
		h.add(" * USA.");
		h.add(" *");
		h.add(" *");
		h.add(" * Original Author:  Arnaud Roques");
		h.add(" *");
		h.add(" *");
		h.add(" *");
		h.add(" *");
		h.add(" *************************************************************************");
		h.add(" * Copyright (c) 2011 AT&T Intellectual Property ");
		h.add(" * All rights reserved. This program and the accompanying materials");
		h.add(" * are made available under the terms of the Eclipse Public License v1.0");
		h.add(" * which accompanies this distribution, and is available at");
		h.add(" * http://www.eclipse.org/legal/epl-v10.html");
		h.add(" *");
		h.add(" * Contributors: See CVS logs. Details at http://www.graphviz.org/");
		h.add(" *************************************************************************");
		h.add(" *");
		h.add(" */");
		return Collections.unmodifiableList(h);
	}

}
