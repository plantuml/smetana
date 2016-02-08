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

//2 clpjw996k49ieh47hl09lwwq1

public interface GVC_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct GVC_s",
"{",
"GVCOMMON_t common",
"char *config_path",
"boolean config_found",
"char **input_filenames",
"GVG_t *gvgs",
"GVG_t *gvg",
"gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]",
"gvplugin_available_t *api[ +1 +1 +1 +1 +1 ]",
"gvplugin_package_t *packages",
"size_t (*write_fn) (GVJ_t *job, const char *s, size_t len)",
"Dtdisc_t textfont_disc",
"Dt_t *textfont_dt",
"gvplugin_active_textlayout_t textlayout",
"GVJ_t *jobs",
"GVJ_t *job",
"graph_t *g",
"gvplugin_active_layout_t layout",
"char *graphname",
"GVJ_t *active_jobs",
"char *pagedir",
"pointf margin",
"pointf pad",
"pointf pageSize",
"point pb",
"boxf bb",
"int rotation",
"boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation",
"char *layerDelims",
"char *layerListDelims",
"char *layers",
"char **layerIDs",
"int numLayers",
"int *layerlist",
"char *defaultfontname",
"double defaultfontsize",
"char **defaultlinestyle",
"gvcolor_t bgcolor",
"int fontrenaming",
"}");
}

// struct GVC_s {
// 	GVCOMMON_t common;
// 
// 	char *config_path;
// 	boolean config_found;
// 
// 	/* gvParseArgs */
// 	char **input_filenames; /* null terminated array of input filenames */
// 
// 	/* gvNextInputGraph() */
// 	GVG_t *gvgs;	/* linked list of graphs */
// 	GVG_t *gvg;	/* current graph */
// 
// 	/* plugins */
// 
// 	/* APIS expands to "+1 +1 ... +1" to give the number of APIs */
// 	gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]; /* array of linked-list of plugins per api */
// 	gvplugin_available_t *api[ +1 +1 +1 +1 +1 ];  /* array of current plugins per api */
// 
// 	gvplugin_package_t *packages;   /* list of available packages */
// 
//         /* externally provided write() displine */
// 	size_t (*write_fn) (GVJ_t *job, const char *s, size_t len);
// 
// 	/* fonts and textlayout */
// 	Dtdisc_t textfont_disc;
// 	Dt_t *textfont_dt;
// 	gvplugin_active_textlayout_t textlayout; /* always use best avail for all jobs */
// //	void (*free_layout) (void *layout);   /* function for freeing layouts (mostly used by pango) */
// 	
// /* FIXME - everything below should probably move to GVG_t */
// 
// 	/* gvrender_config() */
// 	GVJ_t *jobs;	/* linked list of jobs */
// 	GVJ_t *job;	/* current job */
// 
// 	graph_t *g;      /* current graph */
// 
// 	/* gvrender_begin_job() */
// 	gvplugin_active_layout_t layout;
// 
// 	char *graphname;	/* name from graph */
// 	GVJ_t *active_jobs;   /* linked list of active jobs */
// 
// 	/* pagination */
// 	char *pagedir;		/* pagination order */
// 	pointf margin;		/* margins in graph units */
// 	pointf pad;		/* pad in graph units */
// 	pointf pageSize;	/* pageSize in graph units, not including margins */
// 	point pb;		/* page size - including margins (inches) */
// 	boxf bb;		/* graph bb in graph units, not including margins */
// 	int rotation;		/* rotation - 0 = portrait, 90 = landscape */
// 	boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation;
// 
// 	/* layers */
// 	char *layerDelims;	/* delimiters in layer names */
// 	char *layerListDelims;	/* delimiters between layer ranges */ 
// 	char *layers;		/* null delimited list of layer names */
// 	char **layerIDs;	/* array of layer names */
// 	int numLayers;		/* number of layers */
// 	int *layerlist;
// 
// 	/* default font */
// 	char *defaultfontname;
// 	double defaultfontsize;
// 
// 	/* default line style */
// 	char **defaultlinestyle;
// 
// 	/* render defaults set from graph */
// 	gvcolor_t bgcolor;	/* background color */
// 
// 	/* whether to mangle font names (at least in SVG), usually false */
// 	int fontrenaming;
//     };