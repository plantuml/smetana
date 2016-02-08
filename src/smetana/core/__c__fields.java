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



public interface __c__fields {

	public __ptr__ getPtr(String fieldName);
	public __struct__ getStruct(String fieldName);
	public boolean getBoolean(String fieldName);
	public double getDouble(String fieldName);
	public CString getCString(String fieldName);
	public int getInt(String fieldName);
	
	public __ptr__ setPtr(String fieldName, __ptr__ value);
	public void setCString(String fieldName, CString value);
	public void setStruct(String fieldName, __struct__ value);
	public void setInt(String fieldName, int value);
	public void setBoolean(String fieldName, boolean value);
	public void setDouble(String fieldName, double value);
	
	// public __array__ getArray(String fieldName);
	public __array_of_integer__ getArrayOfInteger(String fieldName);
	public __array_of_struct__ getArrayOfStruct(String fieldName);
	public __array_of_ptr__ getArrayOfPtr(String fieldName);
	public __array_of_cstring__ getArrayOfCString(String fieldName);
	

}
