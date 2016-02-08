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

//2 7uiwhqnseej0oaqiv35vi47k1

public interface _dtdisc_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct _dtdisc_s",
"{",
"int  key",
"int  size",
"int  link",
"Dtmake_f makef",
"Dtfree_f freef",
"Dtcompar_f comparf",
"Dthash_f hashf",
"Dtmemory_f memoryf",
"Dtevent_f eventf",
"}");
}

// struct _dtdisc_s
// {	int		key;	/* where the key begins in an object	*/
// 	int		size;	/* key size and type			*/
// 	int		link;	/* offset to Dtlink_t field		*/
// 	Dtmake_f	makef;	/* object constructor			*/
// 	Dtfree_f	freef;	/* object destructor			*/
// 	Dtcompar_f	comparf;/* to compare two objects		*/
// 	Dthash_f	hashf;	/* to compute hash value of an object	*/
// 	Dtmemory_f	memoryf;/* to allocate/free memory		*/
// 	Dtevent_f	eventf;	/* to process events			*/
// };