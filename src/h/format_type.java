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

//2 48gvd3f5a7qs6f6eid493tvyl

public interface format_type extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef enum",
"{",
"FORMAT_PNG_XDOT, FORMAT_GIF_XDOT, FORMAT_JPEG_XDOT, FORMAT_SVG_XDOT, FORMAT_PS_XDOT,     FORMAT_PNG_DOT,  FORMAT_GIF_DOT,  FORMAT_JPEG_DOT,  FORMAT_SVG_DOT,  FORMAT_PS_DOT,     FORMAT_PNG_MAP,  FORMAT_GIF_MAP,  FORMAT_JPEG_MAP,  FORMAT_SVG_MAP,  FORMAT_PS_MAP,     FORMAT_PNG_SVG,  FORMAT_GIF_SVG,  FORMAT_JPEG_SVG,  FORMAT_SVG_SVG,     FORMAT_PNG_FIG,  FORMAT_GIF_FIG,  FORMAT_JPEG_FIG,     FORMAT_PNG_VRML, FORMAT_GIF_VRML, FORMAT_JPEG_VRML,     FORMAT_PS_PS, FORMAT_PSLIB_PS,      FORMAT_PNG_VML, FORMAT_GIF_VML, FORMAT_JPEG_VML,      FORMAT_GIF_TK,",
"}",
"format_type");
}

// typedef enum {
//     FORMAT_PNG_XDOT, FORMAT_GIF_XDOT, FORMAT_JPEG_XDOT, FORMAT_SVG_XDOT, FORMAT_PS_XDOT,
//     FORMAT_PNG_DOT,  FORMAT_GIF_DOT,  FORMAT_JPEG_DOT,  FORMAT_SVG_DOT,  FORMAT_PS_DOT,
//     FORMAT_PNG_MAP,  FORMAT_GIF_MAP,  FORMAT_JPEG_MAP,  FORMAT_SVG_MAP,  FORMAT_PS_MAP,
//     FORMAT_PNG_SVG,  FORMAT_GIF_SVG,  FORMAT_JPEG_SVG,  FORMAT_SVG_SVG,
//     FORMAT_PNG_FIG,  FORMAT_GIF_FIG,  FORMAT_JPEG_FIG,
//     FORMAT_PNG_VRML, FORMAT_GIF_VRML, FORMAT_JPEG_VRML,
//     FORMAT_PS_PS, FORMAT_PSLIB_PS, 
//     FORMAT_PNG_VML, FORMAT_GIF_VML, FORMAT_JPEG_VML, 
//     FORMAT_GIF_TK,
// } format_type;