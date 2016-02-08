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

//2 z6er5w4b36ot9sh8q7zz99ye

public interface Agraphinfo_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct Agraphinfo_t",
"{",
"Agrec_t hdr",
"layout_t *drawing",
"textlabel_t *label",
"boxf bb",
"pointf border[4]",
"unsigned char gui_state",
"unsigned char has_labels",
"boolean has_images",
"unsigned char charset",
"int rankdir",
"double ht1, ht2",
"unsigned short flags",
"void *alg",
"GVC_t *gvc",
"void (*cleanup) (graph_t * g)",
"int n_cluster",
"graph_t **clust",
"graph_t *dotroot",
"node_t *nlist",
"rank_t *rank",
"graph_t *parent",
"int level",
"node_t *minrep, *maxrep",
"nlist_t comp",
"node_t *minset, *maxset",
"long n_nodes",
"short minrank, maxrank",
"boolean has_flat_edges",
"boolean has_sourcerank",
"boolean has_sinkrank",
"unsigned char showboxes",
"fontname_kind fontnames",
"int nodesep, ranksep",
"node_t *ln, *rn",
"node_t *leader, **rankleader",
"boolean expanded",
"char installed",
"char set_type",
"char label_pos",
"boolean exact_ranksep",
"}",
"Agraphinfo_t");
}

// typedef struct Agraphinfo_t {
// 	Agrec_t hdr;
// 	/* to generate code */
// 	layout_t *drawing;
// 	textlabel_t *label;	/* if the cluster has a title */
// 	boxf bb;			/* bounding box */
// 	pointf border[4];	/* sizes of margins for graph labels */
// 	unsigned char gui_state; /* Graph state for GUI ops */
// 	unsigned char has_labels;
// 	boolean has_images;
// 	unsigned char charset; /* input character set */
// 	int rankdir;
// 	double ht1, ht2;	/* below and above extremal ranks */
// 	unsigned short flags;
// 	void *alg;
// 	GVC_t *gvc;	/* context for "globals" over multiple graphs */
// 	void (*cleanup) (graph_t * g);   /* function to deallocate layout-specific data */
// 
// 
// 	
// 	
// 	
// 	
// 	
// 	
// 
// 
// 	/* to have subgraphs */
// 	int n_cluster;
// 	graph_t **clust;	/* clusters are in clust[1..n_cluster] !!! */
// 	graph_t *dotroot;
// 	node_t *nlist;
// 	rank_t *rank;
// 	graph_t *parent;        /* containing cluster (not parent subgraph) */
// 	int level;		/* cluster nesting level (not node level!) */
// 	node_t	*minrep, *maxrep;	/* set leaders for min and max rank */
// 
// 	/* fast graph node list */
// 	nlist_t comp;
// 	/* connected components */
// 	node_t *minset, *maxset;	/* set leaders */
// 	long n_nodes;
// 	/* includes virtual */
// 	short minrank, maxrank;
// 
// 	/* various flags */
// 	boolean has_flat_edges;
// 	boolean has_sourcerank;
// 	boolean has_sinkrank;
// 	unsigned char	showboxes;
// 	fontname_kind fontnames;		/* to override mangling in SVG */
// 
// 	int nodesep, ranksep;
// 	node_t *ln, *rn;	/* left, right nodes of bounding box */
// 
// 	/* for clusters */
// 	node_t *leader, **rankleader;
// 	boolean expanded;
// 	char installed;
// 	char set_type;
// 	char label_pos;
// 	boolean exact_ranksep;
// 
// 
//     } Agraphinfo_t;