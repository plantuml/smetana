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
 * Modelize a <code>char*</code> in C.
 * 
 * @author Arnaud Roques
 *
 */
public interface StarChar extends StarVoid, Comparable<StarChar> {

	/**
	 * Equivalent of <code>*this</code>.
	 * 
	 * @return the character pointed by this pointer.
	 */
	public char get();
	
	public char set(char c);
	

	/**
	 * Equivalent of <code>this+42</code>.
	 * 
	 * @param pointerArithmetic an int to add to the current pointer
	 * 
	 * @return the new pointer
	 */
	public StarChar plus(int pointerArithmetic);
	
	/**
	 * Equivalent of <code>this[42]</code>.
	 * 
	 * @param position an int to be in bracket
	 * @return the nth character pointed by this StarChar.
	 */
	public char bracket(int position);
	
	/**
	 * Equivalent of <code>this[42]=v</code>.
	 * 
	 * @param position an int to be in bracket
	 * @param data character to put in the nth character pointed by this StarChar
	 */
	public void setBracket(int position, char data);

	/**
	 * Equivalent of <code>this-otherPointer</code>.
	 * 
	 * @param other an other StarChar to be compared with this one.
	 * 
	 * @return the distance (in char) between the two pointers.
	 */
	public int minus(StarChar other);

	/**
	 * Equivalent of <code>this>otherPointer</code>.
	 * 
	 * @param arg0 another StarChar
	 * 
	 * @return the comparaison between the two pointers.
	 */
	public int compareTo(StarChar arg0);
	
	/**
	 * Convert this <code>char*</code> to Java String.
	 * @return a plain Java String.
	 */
	public String asString();
	
}
