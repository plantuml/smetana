/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * If you like this project or if you find it useful, you can support us at:
 * 
 * http://plantuml.com/patreon (only 1$ per month!)
 * http://plantuml.com/paypal
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2022, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program:
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
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package h;

import smetana.core.CStar;
import smetana.core.UnsupportedStructAndPtr;
import smetana.core.__struct__;
import smetana.core.amiga.StarStruct;

public class ST_Ppoly_t extends UnsupportedStructAndPtr {

	public CStar<ST_pointf> ps;
	public int pn;

	public ST_Ppoly_t() {
		this(null);
	}

	public ST_Ppoly_t(StarStruct parent) {
	}

	@Override
	public __struct__ copy() {
		ST_Ppoly_t result = new ST_Ppoly_t();
		result.ps = this.ps;
		result.pn = this.pn;
		return result;
	}

	@Override
	public void setInt(String fieldName, int data) {
		if (fieldName.equals("pn")) {
			this.pn = data;
			return;
		}
		super.setInt(fieldName, data);
	}

	// public static List<String> DEFINITION = Arrays.asList(
	// "typedef struct Ppoly_t",
	// "{",
	// "Ppoint_t *ps",
	// "int pn",
	// "}",
	// "Ppoly_t");
}

// typedef struct Ppoly_t {
// Ppoint_t *ps;
// int pn;
// } Ppoly_t;