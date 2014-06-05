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

// http://docs.oracle.com/javase/specs/jls/se5.0/html/expressions.html#15.7.4
// http://www.jbox.dk/sanos/source/lib/string.c.html

import static core.JUtils.*;

public class Stdlib {
	
	static public final int BUFSIZ = 512;
	static public final int USHRT_MAX = 256*256; 

	public static int strncmp(StarChar s1, StarChar s2, int nb) {
		throw new UnsupportedOperationException();
	}

	public static int strcmp(StarChar s1, StarChar s2) {
		int ret = 0;
		while ((ret = s1.get() - s2.get()) == 0 && s2.get() != 0) {
			s1 = s1.plus(1);
			s2 = s2.plus(1);
		}

		if (ret < 0)
			ret = -1;
		else if (ret > 0)
			ret = 1;

		return ret;
	}

	public static void strcpy(StarChar dest, StarChar src) {
		while (true) {
			dest.set(src.get());
			if (src.get() == 0) {
				return;
			}
			dest = dest.plus(1);
			src = src.plus(1);
		}
	}

	public static StarChar strncpy(StarChar dest, StarChar source, int n) {
		StarChar start = dest;

		// while (n && (*dest++ = *source++)) n--;
		while (n != 0) {
			final char tmp = source.get();
			dest.set(tmp);
			dest = dest.plus(1);
			source = source.plus(1);
			if (tmp == '\0') {
				break;
			}
			n--;
		}
		if (n != 0)
			while (--n != 0) {
				dest.set('\0');
				dest = dest.plus(1);
			}
		;
		return start;
	}

	public static StarChar strchr(StarChar s, char ch) {
		while (s.get() != '\0' && s.get() != ch)
			s = s.plus(1);
		if (s.get() == ch)
			return s;
		return null;
	}

	public static int strcmp(StarVoid string1, StarVoid string2) {
		StarChar s1 = (StarChar) string1;
		StarChar s2 = (StarChar) string2;
		return strcmp(s1, s2);
	}

	public static int memcmp(StarVoid s1, StarVoid s2, int size) {
		throw new UnsupportedOperationException();
	}
	
	public static int memcmp(StarVoid s1, StarVoid s2, size_t size) {
		System.err.println("s1="+s1);
		System.err.println("s2="+s2);
		System.err.println("size_t="+size);
		throw new UnsupportedOperationException();
	}
	
	public static StarVoid memset(StarVoid ptr, int value, int size_t_num) {
		throw new UnsupportedOperationException();
	}

	public static StarChar memcpy(StarChar dest, StarChar src, int size) {
		for (int i=0; i<size; i++) {
			dest.setBracket(i, src.bracket(i));
		}
		return dest;
	}

	public static int strlen(StarChar s) {
		int size = 0;
		while (true) {
			if (s.get() == '\0') {
				return size;
			}
			size++;
			s = s.plus(1);
		}
	}

	public static StarChar strstr(StarChar str1, StarChar str2) {
		throw new UnsupportedOperationException();
	}

	public static void sprintf(StarChar dest, String format, Object... args) {
		String s = String.format(format, args);
		strcpy(dest, asStarChar(s));
	}

	public static StarChar getenv(StarChar varname) {
		return null;
	}

	public static double atof(StarChar str) {
		return Double.parseDouble(toJavaString(str));
	}

	public static int atoi(StarChar str) {
		return Integer.parseInt(toJavaString(str));
	}

	private static String toJavaString(StarChar str) {
		StringBuilder sb = new StringBuilder();
		while (str.get() != '\0') {
			sb.append(str.get());
			str = str.plus(1);
		}
		return sb.toString();
	}

	public static int sscanf(StarChar str, String format, Object... varg) {
		String s = toJavaString(str);
		if (format.equals("%f") || format.equals("%lf")) {
			final double f = Double.parseDouble(s);
			StarDouble v = (StarDouble) varg[0];
			v.set(f);
			return 1;
		}
//		if (format.equals("%lf,%lf%c")) {
//			Matcher m = Pattern.compile("([-+.0-9]+),([-+.0-9]+)(.)").matcher(s);
//		}
		throw new UnsupportedOperationException();
	}
	
	public static char tolower(char c) {
		return Character.toLowerCase(c);
	}

	public static boolean isdigit(char c) {
		return Character.isDigit(c);
	}
	
	public static boolean isspace(char c) {
		return Character.isWhitespace(c);
	}
	
	public static double fabs3(double val) {
		return Math.abs(val);
	}
	
	public static int abs3(int val) {
		return Math.abs(val);
	}
	
	public static double cos(double val) {
		return Math.cos(val);
	}
	
	public static double sin(double val) {
		return Math.sin(val);
	}
	
	public static double sqrt(double val) {
		return Math.sqrt(val);
	}
	
	public static double atan2(double y, double x) {
		return Math.atan2(y,x);
	}
	
	public static double hypot(double a, double b) {
		return sqrt(a*a+b*b);
	}

	
	public static StarChar strdup(StarChar s) {
		StarChar r = Memory.mallocStarChar(strlen(s)+1);
		strcpy(r, s);
		return r;
	}
	
	public static void free(Object o) {
	}
	
	public static double strtod(StarChar str, StarStarChar endprt) {
		/*
double strtod ( const char * str, char ** endptr );

Convert string to double
Parses the C string str interpreting its content as a floating point number and returns its value as a double. If endptr is not a null pointer, the function also sets the value of endptr to point to the first character after the number.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes as many characters as possible that are valid following a syntax resembling that of floating point literals, and interprets them as a numerical value. A pointer to the rest of the string after the last valid character is stored in the object pointed by endptr.

A valid floating point number for strtod is formed by a succession of:

    * An optional plus or minus sign
    * A sequence of digits, optionally containing a decimal-point character
    * An optional exponent part, which itself consists on an 'e' or 'E' character followed by an optional sign and a sequence of digits.

If the first sequence of non-whitespace characters in str does not form a valid floating-point number as just defined, or if no such sequence exists because either str is empty or contains only whitespace characters, no conversion is performed.

Parameters

str
    C string beginning with the representation of a floating-point number.
endptr
    Reference to an already allocated object of type char*, whose value is set by the function to the next character in str after the numerical value.
    This parameter can also be a null pointer, in which case it is not used.


Return Value
On success, the function returns the converted floating point number as a double value.
If no valid conversion could be performed, a zero value (0.0) is returned.
If the correct value is out of the range of representable values, a positive or negative HUGE_VAL is returned, and the global variable errno is set to ERANGE.
If the correct value would cause underflow, zero is returned and errno is set to ERANGE.
		 * 
		 */
		throw new UnsupportedOperationException();
	}
	
	static public int strtol (StarChar str, StarStarChar endptr, int base ) {
		/*
		 * 
		 * strtol
long int strtol ( const char * str, char ** endptr, int base );

Convert string to long integer
Parses the C string str interpreting its content as an integral number of the specified base, which is returned as a long int value.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes as many characters as possible that are valid following a syntax that depends on the base parameter, and interprets them as a numerical value. Finally, a pointer to the first character following the integer representation in str is stored in the object pointed by endptr.

If the value of base is zero, the syntax expected is similar to that of integer constants, which is formed by a succession of:

    * An optional plus or minus sign
    * An optional prefix indicating octal or hexadecimal base ("0" or "0x" respectively)
    * A sequence of decimal digits (if no base prefix was specified) or either octal or hexadecimal digits if a specific prefix is present


If the base value is between 2 and 36, the format expected for the integral number is a succession of the valid digits and/or letters needed to represent integers of the specified radix (starting from '0' and up to 'z'/'Z' for radix 36). The sequence may optionally be preceded by a plus or minus sign and, if base is 16, an optional "0x" or "0X" prefix.

If the first sequence of non-whitespace characters in str is not a valid integral number as defined above, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

Parameters

str
    C string containing the representation of an integral number.
endptr
    Reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
    This parameter can also be a null pointer, in which case it is not used.


Return Value
On success, the function returns the converted integral number as a long int value.
If no valid conversion could be performed, a zero value is returned.
If the correct value is out of the range of representable values, LONG_MAX or LONG_MIN is returned, and the global variable errno is set to ERANGE.

		 */
		throw new UnsupportedOperationException();
	}
	
	static public int qsort(Object data, int i1, int i2, Object function) {
		throw new UnsupportedOperationException();
	}
	
	static public void abort() {
		throw new UnsupportedOperationException("abort");
	}
	
	static public double ceil(double x) {
		return Math.ceil(x);
	}
	
	static public void COPY(Object dest, Object src) {
		throw new UnsupportedOperationException();
	}

}
