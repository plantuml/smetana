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

//2 5mip14tura2l8b750vykgeun3

public interface shape_functions extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct shape_functions",
"{",
"void (*initfn) (node_t *)",
"void (*freefn) (node_t *)",
"port(*portfn) (node_t *, char *, char *)",
"boolean(*insidefn) (inside_t * inside_context, pointf)",
"int (*pboxfn)(node_t* n, port* p, int side, boxf rv[], int *kptr)",
"void (*codefn) (GVJ_t * job, node_t * n)",
"}",
"shape_functions");
}

// typedef struct shape_functions {	/* read-only shape functions */
// 	void (*initfn) (node_t *);	/* initializes shape from node u.shape_info structure */
// 	void (*freefn) (node_t *);	/* frees  shape from node u.shape_info structure */
// 	 port(*portfn) (node_t *, char *, char *);	/* finds aiming point and slope of port */
// 	 boolean(*insidefn) (inside_t * inside_context, pointf);	/* clips incident gvc->e spline on shape of gvc->n */
// 	int (*pboxfn)(node_t* n, port* p, int side, boxf rv[], int *kptr); /* finds box path to reach port */
// 	void (*codefn) (GVJ_t * job, node_t * n);	/* emits graphics code for node */
//     } shape_functions;