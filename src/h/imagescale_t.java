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

//2 89sw2fm15jrbgce4w1skvyxcw

public interface imagescale_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef enum",
"{",
"IMAGESCALE_FALSE,",
"IMAGESCALE_TRUE,",
"IMAGESCALE_WIDTH,",
"IMAGESCALE_HEIGHT,",
"IMAGESCALE_BOTH",
"}",
"imagescale_t");
}

// typedef enum {
// 	IMAGESCALE_FALSE,  /* no image scaling */
// 	IMAGESCALE_TRUE,   /* scale image to fit but keep aspect ratio */
// 	IMAGESCALE_WIDTH,  /* scale image width to fit, keep height fixed */
// 	IMAGESCALE_HEIGHT, /* scale image height to fit, keep width fixed */
// 	IMAGESCALE_BOTH    /* scale image to fit without regard for aspect ratio */
//     } imagescale_t;