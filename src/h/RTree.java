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

//2 6erg9dnjb8l3vavlty90aui6v

public interface RTree extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct RTree",
"{",
"Node_t *root",
"SplitQ_t split",
"int MinFill",
"long ElapsedTime",
"float UserTime, SystemTime",
"int Deleting",
"int StatFlag",
"int InsertCount",
"int DeleteCount",
"int ReInsertCount",
"int InSplitCount",
"int DeSplitCount",
"int ElimCount",
"int EvalCount",
"int InTouchCount",
"int DeTouchCount",
"int SeTouchCount",
"int CallCount",
"float SplitMeritSum",
"int RectCount",
"int NodeCount",
"int LeafCount, NonLeafCount",
"int EntryCount",
"int SearchCount",
"int HitCount",
"}");
}

// struct RTree {
//     Node_t *root;
// 
//     SplitQ_t split;
// 
//     /* balance criterion for node splitting */
//     int MinFill;
// 
//     /* times */
//     long ElapsedTime;
//     float UserTime, SystemTime;
// 
//     int Deleting;
// 
//     /* variables for statistics */
//     int StatFlag;		/* tells if we are counting or not */
//     /* counters affected only when StatFlag set */
//     int InsertCount;
//     int DeleteCount;
//     int ReInsertCount;
//     int InSplitCount;
//     int DeSplitCount;
//     int ElimCount;
//     int EvalCount;
//     int InTouchCount;
//     int DeTouchCount;
//     int SeTouchCount;
//     int CallCount;
//     float SplitMeritSum;
// 
//     /* counters used even when StatFlag not set */
//     int RectCount;
//     int NodeCount;
//     int LeafCount, NonLeafCount;
//     int EntryCount;
//     int SearchCount;
//     int HitCount;
// 
// };