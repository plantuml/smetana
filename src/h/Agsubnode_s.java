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

//2 eykrclzau59zmxissqegaiilg

public interface Agsubnode_s extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct Agsubnode_s",
"{",
"Dtlink_t seq_link",
"Dtlink_t id_link",
"Agnode_t *node",
"Dtlink_t *in_id, *out_id",
"Dtlink_t *in_seq, *out_seq",
"}");
}

// struct Agsubnode_s {		/* the node-per-graph-or-subgraph record */
//     Dtlink_t seq_link;		/* must be first */
//     Dtlink_t id_link;
//     Agnode_t *node;		/* the object */
//     Dtlink_t *in_id, *out_id;	/* by node/ID for random access */
//     Dtlink_t *in_seq, *out_seq;	/* by node/sequence for serial access */
// };