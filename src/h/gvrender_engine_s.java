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

//2 c9lcfmvndhmluehnjakiea1ei

public interface gvrender_engine_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct gvrender_engine_s",
"{",
"void (*begin_job) (GVJ_t * job)",
"void (*end_job) (GVJ_t * job)",
"void (*begin_graph) (GVJ_t * job)",
"void (*end_graph) (GVJ_t * job)",
"void (*begin_layer) (GVJ_t * job, char *layername,         int layerNum, int numLayers)",
"void (*end_layer) (GVJ_t * job)",
"void (*begin_page) (GVJ_t * job)",
"void (*end_page) (GVJ_t * job)",
"void (*begin_cluster) (GVJ_t * job)",
"void (*end_cluster) (GVJ_t * job)",
"void (*begin_nodes) (GVJ_t * job)",
"void (*end_nodes) (GVJ_t * job)",
"void (*begin_edges) (GVJ_t * job)",
"void (*end_edges) (GVJ_t * job)",
"void (*begin_node) (GVJ_t * job)",
"void (*end_node) (GVJ_t * job)",
"void (*begin_edge) (GVJ_t * job)",
"void (*end_edge) (GVJ_t * job)",
"void (*begin_anchor) (GVJ_t * job,   char *href, char *tooltip, char *target, char *id)",
"void (*end_anchor) (GVJ_t * job)",
"void (*begin_label) (GVJ_t * job, label_type type)",
"void (*end_label) (GVJ_t * job)",
"void (*textspan) (GVJ_t * job, pointf p, textspan_t * span)",
"void (*resolve_color) (GVJ_t * job, gvcolor_t * color)",
"void (*ellipse) (GVJ_t * job, pointf * A, int filled)",
"void (*polygon) (GVJ_t * job, pointf * A, int n, int filled)",
"void (*beziercurve) (GVJ_t * job, pointf * A, int n,         int arrow_at_start, int arrow_at_end, int)",
"void (*polyline) (GVJ_t * job, pointf * A, int n)",
"void (*comment) (GVJ_t * job, char *comment)",
"void (*library_shape) (GVJ_t * job, char *name, pointf * A, int n, int filled)",
"}");
}

// struct gvrender_engine_s {
// 	void (*begin_job) (GVJ_t * job);
// 	void (*end_job) (GVJ_t * job);
// 	void (*begin_graph) (GVJ_t * job);
// 	void (*end_graph) (GVJ_t * job);
// 	void (*begin_layer) (GVJ_t * job, char *layername,
// 			     int layerNum, int numLayers);
// 	void (*end_layer) (GVJ_t * job);
// 	void (*begin_page) (GVJ_t * job);
// 	void (*end_page) (GVJ_t * job);
// 	void (*begin_cluster) (GVJ_t * job);
// 	void (*end_cluster) (GVJ_t * job);
// 	void (*begin_nodes) (GVJ_t * job);
// 	void (*end_nodes) (GVJ_t * job);
// 	void (*begin_edges) (GVJ_t * job);
// 	void (*end_edges) (GVJ_t * job);
// 	void (*begin_node) (GVJ_t * job);
// 	void (*end_node) (GVJ_t * job);
// 	void (*begin_edge) (GVJ_t * job);
// 	void (*end_edge) (GVJ_t * job);
// 	void (*begin_anchor) (GVJ_t * job,
// 		char *href, char *tooltip, char *target, char *id);
// 	void (*end_anchor) (GVJ_t * job);
// 	void (*begin_label) (GVJ_t * job, label_type type);
// 	void (*end_label) (GVJ_t * job);
// 	void (*textspan) (GVJ_t * job, pointf p, textspan_t * span);
// 	void (*resolve_color) (GVJ_t * job, gvcolor_t * color);
// 	void (*ellipse) (GVJ_t * job, pointf * A, int filled);
// 	void (*polygon) (GVJ_t * job, pointf * A, int n, int filled);
// 	void (*beziercurve) (GVJ_t * job, pointf * A, int n,
// 			     int arrow_at_start, int arrow_at_end, int);
// 	void (*polyline) (GVJ_t * job, pointf * A, int n);
// 	void (*comment) (GVJ_t * job, char *comment);
// 	void (*library_shape) (GVJ_t * job, char *name, pointf * A, int n, int filled);
//     };