#line 1 "graphviz-2.38.0\\lib\\ast\\pathgetlink.c" 1
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

/*
* Glenn Fowler
* AT&T Bell Laboratories
*/


#line 1 "graphviz-2.38.0\\lib\\ast\\pathgetlink.c" 1

#line 1 "graphviz-2.38.0\\lib\\ast\\pathgetlink.c" 1










#line 1 "graphviz-2.38.0\\lib\\ast\\compat_unistd.h" 1
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




























extern int access (const char*, int);
extern char* getcwd (char*, int);






#line 27 "graphviz-2.38.0\\lib\\ast\\pathgetlink.c" 2


/*
 * return external representation for symbolic link text of name in buf
 * the link text string length is returned
 */

int pathgetlink(const char *name, char *buf, int siz)
{

	

    int n;

    if ((n = readlink(name, buf, siz)) < 0)
	return (-1);
    if (n >= siz) {
	errno = EINVAL;
	return (-1);
    }
    buf[n] = 0;

    
	
	
	
	
	
	

	
	
	
	
	    
		
		    
			
			
			
		    
		    
		
		
		    
		
		
		    
			
			    
				
			    
				
				
				
				
				
			    
			
		    
	    
	
    

    return (n);

}
