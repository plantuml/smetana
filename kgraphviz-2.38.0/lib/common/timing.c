#line 1 "graphviz-2.38.0\\lib\\common\\timing.c" 1
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



#line 1 "graphviz-2.38.0\\lib\\common\\timing.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\timing.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\timing.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\timing.c" 1






typedef struct tms mytime_t;
















static mytime_t T;

void start_timer(void)
{
    times(&(T));
}

double elapsed_sec(void)
{
    mytime_t S;
    double rv;

    times(&(S));
    rv = ((S.tms_utime + S.tms_stime - T.tms_utime - T.tms_stime)/(double)60);
    return rv;
}
