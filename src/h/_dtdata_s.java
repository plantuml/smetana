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

//2 2ncfjhm10yijctdn20pwnelos

public interface _dtdata_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct _dtdata_s",
"{",
"int  type",
"Dtlink_t* here",
"union",
"{",
"Dtlink_t** _htab",
"Dtlink_t* _head",
"}",
"hh",
"int  ntab",
"int  size",
"int  loop",
"int  minp",
"}");
}

// struct _dtdata_s
// {	int		type;	/* type of dictionary			*/
// 	Dtlink_t*	here;	/* finger to last search element	*/
// 	union
// 	{ Dtlink_t**	_htab;	/* hash table				*/
// 	  Dtlink_t*	_head;	/* linked list				*/
// 	} hh;
// 	int		ntab;	/* number of hash slots			*/
// 	int		size;	/* number of objects			*/
// 	int		loop;	/* number of nested loops		*/
// 	int		minp;	/* min path before splay, always even	*/
// 				/* for hash dt, > 0: fixed table size 	*/
// };