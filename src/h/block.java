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

//2 aeiesb8xknt6qv58gj7tdny3l

public interface block extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct block",
"{",
"Agnode_t *child",
"block_t *next",
"Agraph_t *sub_graph",
"double radius",
"double rad0",
"nodelist_t *circle_list",
"blocklist_t children",
"double parent_pos",
"int flags",
"}");
}

// struct block {
// 	Agnode_t *child;	/* if non-null, points to node in parent block */
// 	block_t *next;		/* sibling block */
// 	Agraph_t *sub_graph;	/* nodes and edges in this block */
// 	double radius;		/* radius of block and subblocks */
// 	double rad0;		/* radius of block */
// 	nodelist_t *circle_list;	/* ordered list of nodes in block */
// 	blocklist_t children;	/* child blocks */
// 	double parent_pos;	/* if block has 1 node, angle to place parent */
// 	int flags;
//     };