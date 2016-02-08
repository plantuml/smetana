#line 1 "graphviz-2.38.0\\lib\\common\\strncasecmp.c" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/


#line 1 "graphviz-2.38.0\\lib\\common\\strncasecmp.c" 1



#line 1 "graphviz-2.38.0\\lib\\common\\strncasecmp.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\strncasecmp.c" 1

int strncasecmp(const char *s1, const char *s2, unsigned int n)
{
    if (n == 0)
	return 0;

    while ((n-- != 0)
	   && (tolower(*(unsigned char *) s1) ==
	       tolower(*(unsigned char *) s2))) {
	if (n == 0 || *s1 == '\0' || *s2 == '\0')
	    return 0;
	s1++;
	s2++;
    }

    return tolower(*(unsigned char *) s1) - tolower(*(unsigned char *) s2);
}

