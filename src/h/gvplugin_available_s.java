/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.com
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
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 *
 * Original Author:  Arnaud Roques
 *
 *
 *
 *
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************
 *
 */
package h;
import smetana.core.*;
import java.util.Arrays;
import java.util.List;

//2 4mff7kl30vs5cmzxe47j17hex

public interface gvplugin_available_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct gvplugin_available_s",
"{",
"gvplugin_available_t *next",
"const char *typestr",
"int quality",
"gvplugin_package_t *package",
"gvplugin_installed_t *typeptr",
"}");
}

// struct gvplugin_available_s {
// 	gvplugin_available_t *next;     /* next plugin in linked list, or NULL */
// 	const char *typestr;		/* type string, e.g. "png" or "ps" */
// 	int quality;			/* Programmer assigned quality ranking within type (+ve or -ve int).
// 					First implementation of type should be given "0" quality */
// 	gvplugin_package_t *package;	/* details of library containing plugin */
// 	gvplugin_installed_t *typeptr;  /* pointer to jumptable for plugin,
// 					or NULL if not yet loaded */
//     };