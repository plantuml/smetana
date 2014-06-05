/* ========================================================================
 * JDot  : Port from C to Java of GraphViz
 * ========================================================================
 *
 * (C) Copyright 2012, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net/jdot/jdot.html
 * 
 * This file is part of JDot.
 *
 * JDot is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JDot distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 * 
 * GraphViz itself is distributed under Eclipse Public License v1.0:
 * 
 *************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/
package core;

/**
 * Modelize a <code>**foo</code> in C where <code>foo</code> is a structure.
 * 
 * @author Arnaud Roques
 *
 * @param <O> the structure pointed by the pointer of pointer.
 */
public interface StarStar<O> extends StarVoid, Comparable<StarStar<O>>{

	/**
	 * Emulate <code>*foo</code>.
	 * Don't forget that in Java, <code>Foo</code> is already a pointer.
	 * 
	 * @return the pointer pointed by <code>*this</code>
	 */
	public O get();

	/**
	 * Emulate <code>*this = somePointer</code>, where somePointer is <code>*foo</code>.
	 * 
	 * @param value
	 */
	public void set(O value);

	public StarStar<O> plus(int pointerArithmetic);

	public O bracket(int position);

	public O setBracket(int position, O value);
	
	public int minus(StarStar<O> other);

	
	public int size();
	
	public StarLong asStarLong();
}
