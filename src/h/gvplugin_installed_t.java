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

//2 dcmpl8ruksxab5p8161qcvxcw

public interface gvplugin_installed_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"int id",
"const char *type",
"int quality",
"void *engine",
"void *features",
"}",
"gvplugin_installed_t");
}

// typedef struct {
// 	int id;         /* an id that is only unique within a package 
// 			of plugins of the same api.
// 			A renderer-type such as "png" in the cairo package
// 			has an id that is different from the "ps" type
// 			in the same package */
// 	const char *type;	/* a string name, such as "png" or "ps" that
// 			distinguishes different types withing the same
// 			 (renderer in this case) */
// 	int quality;    /* an arbitrary integer used for ordering plugins of
// 			the same type from different packages */
// 	void *engine;   /* pointer to the jump table for the plugin */
// 	void *features; /* pointer to the feature description 
// 				void* because type varies by api */
//     } gvplugin_installed_t;