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

//2 8reykx9ipp7zhrcjg3ymu8ypm

public interface Agnodeinfo_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct Agnodeinfo_t",
"{",
"Agrec_t hdr",
"shape_desc *shape",
"void *shape_info",
"pointf coord",
"double width, height",
"boxf bb",
"double ht, lw, rw",
"textlabel_t *label",
"textlabel_t *xlabel",
"void *alg",
"char state",
"unsigned char gui_state",
"boolean clustnode",
"unsigned char showboxes",
"boolean  has_port",
"node_t* rep",
"node_t *set",
"char node_type, mark, onstack",
"char ranktype, weight_class",
"node_t *next, *prev",
"elist in, out, flat_out, flat_in, other",
"graph_t *clust",
"int UF_size",
"node_t *UF_parent",
"node_t *inleaf, *outleaf",
"int rank, order",
"double mval",
"elist save_in, save_out",
"elist tree_in, tree_out",
"edge_t *par",
"int low, lim",
"int priority",
"double pad[1]",
"}",
"Agnodeinfo_t");
}

// typedef struct Agnodeinfo_t {
// 	Agrec_t hdr;
// 	shape_desc *shape;
// 	void *shape_info;
// 	pointf coord;
// 	double width, height;  /* inches */
// 	boxf bb;
// 	double ht, lw, rw;
// 	textlabel_t *label;
// 	textlabel_t *xlabel;
// 	void *alg;
// 	char state;
// 	unsigned char gui_state; /* Node state for GUI ops */
// 	boolean clustnode;
// 
// 
// 	
// 	
// 	
// 
// 
// 	unsigned char showboxes;
// 	boolean  has_port;
// 	node_t* rep;
// 	node_t *set;
// 
// 	/* fast graph */
// 	char node_type, mark, onstack;
// 	char ranktype, weight_class;
// 	node_t *next, *prev;
// 	elist in, out, flat_out, flat_in, other;
// 	graph_t *clust;
// 
// 	/* for union-find and collapsing nodes */
// 	int UF_size;
// 	node_t *UF_parent;
// 	node_t *inleaf, *outleaf;
// 
// 	/* for placing nodes */
// 	int rank, order;	/* initially, order = 1 for ordered edges */
// 	double mval;
// 	elist save_in, save_out;
// 
// 	/* for network-simplex */
// 	elist tree_in, tree_out;
// 	edge_t *par;
// 	int low, lim;
// 	int priority;
// 
// 	double pad[1];
// 
// 
//     } Agnodeinfo_t;