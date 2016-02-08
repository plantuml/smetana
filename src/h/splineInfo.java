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

//2 8u1r3c3d0g8hn19fq04x9z0ht

public interface splineInfo extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"boolean(*swapEnds) (edge_t * e)",
"boolean(*splineMerge) (node_t * n)",
"boolean ignoreSwap",
"boolean isOrtho",
"}",
"splineInfo");
}

// typedef struct {
// 	boolean(*swapEnds) (edge_t * e);	/* Should head and tail be swapped? */
// 	boolean(*splineMerge) (node_t * n);	/* Is n a node in the middle of an edge? */
// 	boolean ignoreSwap;                     /* Test for swapped edges if false */
// 	boolean isOrtho;                        /* Orthogonal routing used */
//     } splineInfo;