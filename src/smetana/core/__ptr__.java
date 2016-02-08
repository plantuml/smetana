/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net
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
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc.
 * in the United States and other countries.]
 *
 * Original Author:  Arnaud Roques
 * 
 */
package smetana.core;



public interface __ptr__ extends __c__fields {

	public __ptr__ castTo(Class dest);
	public Object addVirtualBytes(int bytes);
	public __ptr__ unsupported();
	public __ptr__ plus(int pointerMove);
	public int comparePointer(__ptr__ other);
	public int minus(__ptr__ other);

	public String getDebug(String fieldName);

	public void copyDataFrom(__ptr__ other);
	public void copyDataFrom(__struct__ other);
	
	public int getInt();
	public void setInt(int value);
	public double getDouble();
	public void setDouble(double value);
	public __ptr__ getPtr();
	public void setPtr(__ptr__ value);
	public __struct__ getStruct();
	public void setStruct(__struct__ value);
	
	public Object call(String name, Object... args);
	

}
