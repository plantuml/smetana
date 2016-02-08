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

//2 9qqo4pt0x97lv7fp9yneflgkr

public interface textlabel_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct textlabel_t",
"{",
"char *text, *fontname, *fontcolor",
"int charset",
"double fontsize",
"pointf dimen",
"pointf space",
"pointf pos",
"union",
"{",
"struct",
"{",
"textspan_t *span",
"short nspans",
"}",
"txt",
"htmllabel_t *html",
"}",
"u",
"char valign",
"boolean set",
"boolean html",
"}",
"textlabel_t");
}

// typedef struct textlabel_t {
// 	char *text, *fontname, *fontcolor;
// 	int charset;
// 	double fontsize;
// 	pointf dimen; /* the diagonal size of the label (estimated by layout) */
// 	pointf space; /* the diagonal size of the space for the label */
// 		      /*   the rendered label is aligned in this box */
// 		      /*   space does not include pad or margin */
// 	pointf pos;   /* the center of the space for the label */
// 	union {
// 	    struct {
// 		textspan_t *span;
// 		short nspans;
// 	    } txt;
// 	    htmllabel_t *html;
// 	} u;
// 	char valign;  /* 't' 'c' 'b' */
// 	boolean set;  /* true if position is set */
// 	boolean html; /* true if html label */
//     } textlabel_t;