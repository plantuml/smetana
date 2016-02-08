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

//2 71w78cxaan0929s365t8kncr6

public interface port extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct port",
"{",
"pointf p",
"double theta",
"boxf *bp",
"boolean defined",
"boolean constrained",
"boolean clip",
"boolean dyna",
"unsigned char order",
"unsigned char side",
"char *name",
"}",
"port");
}

// typedef struct port {	/* internal edge endpoint specification */
// 	pointf p;		/* aiming point relative to node center */
// 	double theta;		/* slope in radians */
// 	boxf *bp;		/* if not null, points to bbox of 
// 				 * rectangular area that is port target
// 				 */
// 	boolean	defined;        /* if true, edge has port info at this end */
// 	boolean	constrained;    /* if true, constraints such as theta are set */
// 	boolean clip;           /* if true, clip end to node/port shape */
// 	boolean dyna;           /* if true, assign compass point dynamically */
// 	unsigned char order;	/* for mincross */
// 	unsigned char side;	/* if port is on perimeter of node, this
//                                  * contains the bitwise OR of the sides (TOP,
//                                  * BOTTOM, etc.) it is on. 
//                                  */
// 	char *name;		/* port name, if it was explicitly given, otherwise NULL */
//     } port;