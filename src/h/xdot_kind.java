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

//2 4a4izg5kkwsn1z1946vyklb3b

public interface xdot_kind extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef enum",
"{",
"xd_filled_ellipse, xd_unfilled_ellipse,     xd_filled_polygon, xd_unfilled_polygon,     xd_filled_bezier,  xd_unfilled_bezier,     xd_polyline,       xd_text,     xd_fill_color,     xd_pen_color, xd_font, xd_style, xd_image,     xd_grad_fill_color,     xd_grad_pen_color,     xd_fontchar",
"}",
"xdot_kind");
}

// typedef enum {
//     xd_filled_ellipse, xd_unfilled_ellipse,
//     xd_filled_polygon, xd_unfilled_polygon,
//     xd_filled_bezier,  xd_unfilled_bezier,
//     xd_polyline,       xd_text,
//     xd_fill_color,     xd_pen_color, xd_font, xd_style, xd_image,
//     xd_grad_fill_color,     xd_grad_pen_color,
//     xd_fontchar
// } xdot_kind;