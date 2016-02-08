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

//2 3hom62aciieyjg8pgbfmp1qik

public interface re_pattern_buffer extends __ptr__ {
	public static List<String> DEFINITION = Arrays.asList(
"struct re_pattern_buffer",
"{",
"unsigned char *buffer",
"unsigned long int allocated",
"unsigned long int used",
"reg_syntax_t syntax",
"char *fastmap",
"char * translate",
"size_t re_nsub",
"unsigned can_be_null : 1",
"unsigned regs_allocated : 2",
"unsigned fastmap_accurate : 1",
"unsigned no_sub : 1",
"unsigned not_bol : 1",
"unsigned not_eol : 1",
"unsigned newline_anchor : 1",
"}");
}

// struct re_pattern_buffer
//     {
//         /* [[[begin pattern_buffer]]] */
//         /* Space that holds the compiled pattern.  It is declared as
//            `unsigned char *' because its elements are
//            sometimes used as array indexes.  */
//         unsigned char *buffer;
// 
//         /* Number of bytes to which `buffer' points.  */
//         unsigned long int allocated;
// 
//         /* Number of bytes actually used in `buffer'.  */
//         unsigned long int used;
// 
//         /* Syntax setting with which the pattern was compiled.  */
//         reg_syntax_t syntax;
// 
//         /* Pointer to a fastmap, if any, otherwise zero.  re_search uses
//            the fastmap, if there is one, to skip over impossible
//            starting points for matches.  */
//         char *fastmap;
// 
//         /* Either a translate table to apply to all characters before
//            comparing them, or zero for no translation.  The translation
//            is applied to a pattern when it is compiled and to a string
//            when it is matched.  */
//         char * translate;
// 
//         /* Number of subexpressions found by the compiler.  */
//         size_t re_nsub;
// 
//         /* Zero if this pattern cannot match the empty string, one else.
//            Well, in truth it's used only in `re_search_2', to see
//            whether or not we should use the fastmap, so we don't set
//            this absolutely perfectly; see `re_compile_fastmap' (the
//            `duplicate' case).  */
//         unsigned can_be_null : 1;
// 
//         /* If REGS_UNALLOCATED, allocate space in the `regs' structure
//            for `max (RE_NREGS, re_nsub + 1)' groups.
//            If REGS_REALLOCATE, reallocate space if necessary.
//            If REGS_FIXED, use what's there.  */
// 
// 
// 
//         unsigned regs_allocated : 2;
// 
//         /* Set to zero when `regex_compile' compiles a pattern; set to one
//            by `re_compile_fastmap' if it updates the fastmap.  */
//         unsigned fastmap_accurate : 1;
// 
//         /* If set, `re_match_2' does not return information about
//            subexpressions.  */
//         unsigned no_sub : 1;
// 
//         /* If set, a beginning-of-line anchor doesn't match at the
//            beginning of the string.  */
//         unsigned not_bol : 1;
// 
//         /* Similarly for an end-of-line anchor.  */
//         unsigned not_eol : 1;
// 
//         /* If true, an anchor at a newline matches.  */
//         unsigned newline_anchor : 1;
// 
//         /* [[[end pattern_buffer]]] */
//     };