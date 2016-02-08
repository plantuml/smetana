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

//2 dhiu7hb5hm946g0tfbnpowdu5

public interface xdot_state_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"attrsym_t *g_draw",
"attrsym_t *g_l_draw",
"attrsym_t *n_draw",
"attrsym_t *n_l_draw",
"attrsym_t *e_draw",
"attrsym_t *h_draw",
"attrsym_t *t_draw",
"attrsym_t *e_l_draw",
"attrsym_t *hl_draw",
"attrsym_t *tl_draw",
"unsigned char buf[(EMIT_HLABEL+1)][BUFSIZ]",
"unsigned short version",
"char* version_s",
"}",
"xdot_state_t");
}

// typedef struct {
//     attrsym_t *g_draw;
//     attrsym_t *g_l_draw;
//     attrsym_t *n_draw;
//     attrsym_t *n_l_draw;
//     attrsym_t *e_draw;
//     attrsym_t *h_draw;
//     attrsym_t *t_draw;
//     attrsym_t *e_l_draw;
//     attrsym_t *hl_draw;
//     attrsym_t *tl_draw;
//     unsigned char buf[(EMIT_HLABEL+1)][BUFSIZ];
//     unsigned short version;
//     char* version_s;
// } xdot_state_t;