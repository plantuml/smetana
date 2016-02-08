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

//2 926gualwyh744kklf86qw5qsj

public interface _dt_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct _dt_s",
"{",
"Dtsearch_f searchf",
"Dtdisc_t* disc",
"Dtdata_t* data",
"Dtmemory_f memoryf",
"Dtmethod_t* meth",
"int  type",
"int  nview",
"Dt_t*  view",
"Dt_t*  walk",
"void*  user",
"}");
}

// struct _dt_s
// {	Dtsearch_f	searchf;/* search function			*/
// 	Dtdisc_t*	disc;	/* method to manipulate objs		*/
// 	Dtdata_t*	data;	/* sharable data			*/
// 	Dtmemory_f	memoryf;/* function to alloc/free memory	*/
// 	Dtmethod_t*	meth;	/* dictionary method			*/
// 	int		type;	/* type information			*/
// 	int		nview;	/* number of parent view dictionaries	*/
// 	Dt_t*		view;	/* next on viewpath			*/
// 	Dt_t*		walk;	/* dictionary being walked		*/
// 	void*		user;	/* for user's usage			*/
// };