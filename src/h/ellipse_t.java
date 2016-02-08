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

//2 7sm9vcfcserrygyo079543gdf

public interface ellipse_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"double cx, cy",
"double a, b",
"double theta, cosTheta, sinTheta",
"double eta1, eta2",
"double x1, y1, x2, y2",
"double xF1, yF1,  xF2, yF2",
"double xLeft",
"double yUp",
"double width, height",
"double f, e2, g, g2",
"}",
"ellipse_t");
}

// typedef struct {
//     double cx, cy;		/* center */
//     double a, b;		/* semi-major and -minor axes */
// 
//   /* Orientation of the major axis with respect to the x axis. */
//     double theta, cosTheta, sinTheta;
// 
//   /* Start and end angles of the arc. */
//     double eta1, eta2;
// 
//   /* Position of the start and end points. */
//     double x1, y1, x2, y2;
// 
//   /* Position of the foci. */
//     double xF1, yF1,  xF2, yF2;
// 
//   /* x of the leftmost point of the arc. */
//     double xLeft;
// 
//   /* y of the highest point of the arc. */
//     double yUp;
// 
//   /* Horizontal width and vertical height of the arc. */
//     double width, height;
// 
//     double f, e2, g, g2;
// } ellipse_t;