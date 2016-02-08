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

//2 9k0huyjtpb77v42bdkmmy7zo5

public interface attr_state_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"attrsym_t* E_constr",
"attrsym_t* E_samehead",
"attrsym_t* E_sametail",
"attrsym_t* E_weight",
"attrsym_t* E_minlen",
"attrsym_t* E_fontcolor",
"attrsym_t* E_fontname",
"attrsym_t* E_fontsize",
"attrsym_t* E_headclip",
"attrsym_t* E_headlabel",
"attrsym_t* E_label",
"attrsym_t* E_label_float",
"attrsym_t* E_labelfontcolor",
"attrsym_t* E_labelfontname",
"attrsym_t* E_labelfontsize",
"attrsym_t* E_tailclip",
"attrsym_t* E_taillabel",
"attrsym_t* E_xlabel",
"attrsym_t* N_height",
"attrsym_t* N_width",
"attrsym_t* N_shape",
"attrsym_t* N_style",
"attrsym_t* N_fontsize",
"attrsym_t* N_fontname",
"attrsym_t* N_fontcolor",
"attrsym_t* N_label",
"attrsym_t* N_xlabel",
"attrsym_t* N_showboxes",
"attrsym_t* N_ordering",
"attrsym_t* N_sides",
"attrsym_t* N_peripheries",
"attrsym_t* N_skew",
"attrsym_t* N_orientation",
"attrsym_t* N_distortion",
"attrsym_t* N_fixed",
"attrsym_t* N_nojustify",
"attrsym_t* N_group",
"attrsym_t* G_ordering",
"int        State",
"}",
"attr_state_t");
}

// typedef struct {
//     attrsym_t* E_constr;
//     attrsym_t* E_samehead;
//     attrsym_t* E_sametail;
//     attrsym_t* E_weight;
//     attrsym_t* E_minlen;
//     attrsym_t* E_fontcolor;
//     attrsym_t* E_fontname;
//     attrsym_t* E_fontsize;
//     attrsym_t* E_headclip;
//     attrsym_t* E_headlabel;
//     attrsym_t* E_label;
//     attrsym_t* E_label_float;
//     attrsym_t* E_labelfontcolor;
//     attrsym_t* E_labelfontname;
//     attrsym_t* E_labelfontsize;
//     attrsym_t* E_tailclip;
//     attrsym_t* E_taillabel;
//     attrsym_t* E_xlabel;
// 
//     attrsym_t* N_height;
//     attrsym_t* N_width;
//     attrsym_t* N_shape;
//     attrsym_t* N_style;
//     attrsym_t* N_fontsize;
//     attrsym_t* N_fontname;
//     attrsym_t* N_fontcolor;
//     attrsym_t* N_label;
//     attrsym_t* N_xlabel;
//     attrsym_t* N_showboxes;
//     attrsym_t* N_ordering;
//     attrsym_t* N_sides;
//     attrsym_t* N_peripheries;
//     attrsym_t* N_skew;
//     attrsym_t* N_orientation;
//     attrsym_t* N_distortion;
//     attrsym_t* N_fixed;
//     attrsym_t* N_nojustify;
//     attrsym_t* N_group;
// 
//     attrsym_t* G_ordering;
//     int        State;
// } attr_state_t;