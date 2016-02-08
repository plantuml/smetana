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

//2 ap7c4ii9ux7nlggs68fm76fy6

public interface reg_errcode_t extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"typedef enum",
"{",
"REG_NOERROR = 0,",
"REG_NOMATCH,",
"REG_BADPAT,",
"REG_ECOLLATE,",
"REG_ECTYPE,",
"REG_EESCAPE,",
"REG_ESUBREG,",
"REG_EBRACK,",
"REG_EPAREN,",
"REG_EBRACE,",
"REG_BADBR,",
"REG_ERANGE,",
"REG_ESPACE,",
"REG_BADRPT,",
"REG_EEND,",
"REG_ESIZE,",
"REG_ERPAREN",
"}",
"reg_errcode_t");
}

// typedef enum
//     {
//         REG_NOERROR = 0,        /* Success.  */
//         REG_NOMATCH,            /* Didn't find a match (for regexec).  */
// 
//         /* POSIX regcomp return error codes.  (In the order listed in the
//            standard.)  */
//         REG_BADPAT,             /* Invalid pattern.  */
//         REG_ECOLLATE,           /* Not implemented.  */
//         REG_ECTYPE,             /* Invalid character class name.  */
//         REG_EESCAPE,            /* Trailing backslash.  */
//         REG_ESUBREG,            /* Invalid back reference.  */
//         REG_EBRACK,             /* Unmatched left bracket.  */
//         REG_EPAREN,             /* Parenthesis imbalance.  */
//         REG_EBRACE,             /* Unmatched \{.  */
//         REG_BADBR,              /* Invalid contents of \{\}.  */
//         REG_ERANGE,             /* Invalid range end.  */
//         REG_ESPACE,             /* Ran out of memory.  */
//         REG_BADRPT,             /* No preceding re for repetition op.  */
// 
//         /* Error codes we've added.  */
//         REG_EEND,               /* Premature end.  */
//         REG_ESIZE,              /* Compiled pattern bigger than 2^16 bytes.  */
//         REG_ERPAREN             /* Unmatched ) or \); not returned from regcomp.  */
//     } reg_errcode_t;