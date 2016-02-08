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

//2 9cd2h3321diwjh8ip8pl0j7no

public interface parms_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef struct",
"{",
"int useGrid",
"int useNew",
"long seed",
"int numIters",
"int maxIters",
"int unscaled",
"double C",
"double Tfact",
"double K",
"double T0",
"int smode",
"double Cell",
"double Cell2",
"double K2",
"double Wd",
"double Ht",
"double Wd2",
"double Ht2",
"int pass1",
"int loopcnt",
"}",
"parms_t");
}

// typedef struct {
//     int useGrid;	/* use grid for speed up */
//     int useNew;		/* encode x-K into attractive force */
//     long seed;		/* seed for position RNG */
//     int numIters;	/* actual iterations in layout */
//     int maxIters;	/* max iterations in layout */
//     int unscaled;	/* % of iterations used in pass 1 */
//     double C;		/* Repulsion factor in xLayout */
//     double Tfact;	/* scale temp from default expression */
//     double K;		/* spring constant; ideal distance */
//     double T0;          /* initial temperature */
//     int smode;          /* seed mode */
//     double Cell;	/* grid cell size */
//     double Cell2;	/* Cell*Cell */
//     double K2;		/* K*K */
//     double Wd;		/* half-width of boundary */
//     double Ht;		/* half-height of boundary */
//     double Wd2;		/* Wd*Wd */
//     double Ht2;		/* Ht*Ht */
//     int pass1;		/* iterations used in pass 1 */
//     int loopcnt;        /* actual iterations in this pass */
// } parms_t;