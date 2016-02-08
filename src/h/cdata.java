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

//2 39c66ffd2kgahvaaf8e61dspv

public interface cdata extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"union",
"{",
"Agraph_t *g",
"Agnode_t *np",
"}",
"orig",
"int flags",
"node_t *parent",
"block_t *block",
"union",
"{",
"struct",
"{",
"node_t *next",
"int val",
"int low_val",
"}",
"bc",
"node_t *clone",
"struct",
"{",
"node_t *tparent",
"node_t *first",
"node_t *second",
"int fdist",
"int sdist",
"}",
"t",
"struct",
"{",
"int pos",
"double psi",
"}",
"f",
"}",
"u",
"}",
"cdata");
}

// typedef struct {
//     union {			/* Pointer to node/cluster in original graph */
// 	Agraph_t *g;
// 	Agnode_t *np;
//     } orig;
//     int flags;
//     node_t *parent;		/* parent in block-cutpoint traversal (1,2,4) */
//     block_t *block;		/* Block containing node (1,2,3,4) */
//     union {
// 	struct {		/* Pass  1 */
// 	    node_t *next;	/* used for stack */
// 	    int val;
// 	    int low_val;
// 	} bc;
// 	node_t *clone;		/* Cloned node (3a) */
// 	struct {		/* Spanning tree and longest path (3b) */
// 	    node_t *tparent;	/* Parent in tree */
// 	    node_t *first;	/* Leaf on longest path from node */
// 	    node_t *second;	/* Leaf on 2nd longest path from node */
// 	    int fdist;		/* Length of longest path from node */
// 	    int sdist;		/* Length of 2nd longest path from node */
// 	} t;
// 	struct {
// 	    int pos;		/* Index of node in block circle (3c,4) */
// 	    double psi;		/* Offset angle of children (4) */
// 	} f;
//     } u;
// } cdata;