#line 1 "graphviz-2.38.0\\lib\\cgraph\\main.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\cgraph\\main.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\main.c" 1

static void prstats(Agraph_t * g, int verbose);
static void do_it(Agraph_t * g, int dostat);


static void my_ins(Agraph_t * g, Agobj_t * obj, void *context)
{
    Agnode_t *n;

    if (AGTYPE(obj) == AGNODE) {
	n = (Agnode_t *) obj;
	fprintf(stderr, "%s initialized with label %s\n", agnameof(n),
		agget(n, "label"));
    }
}

static Agcbdisc_t mydisc = { {0, 0, 0}, {my_ins, 0, 0}, {0, 0, 0} };

main(int argc, char **argv)
{
    Agraph_t *g, *prev;
    int dostat;

    if (argc > 1)
	dostat = atoi(argv[1]);
    else
	dostat = 0;

    prev = agopen("some_name", Agdirected, NIL(Agdisc_t *));
    agcallbacks(prev, FALSE);
    agpushdisc(prev, &mydisc, NIL(void *));
    while (g = agconcat(prev, stdin, NIL(Agdisc_t *))) {
	/*do_it(g, dostat); */
    }
    /*agwrite(prev,stdout); */
    fprintf(stderr, "ready to go, computer fans\n");
    agcallbacks(prev, TRUE);
    agclose(prev);
    return 1;
}

static void prstats(Agraph_t * g, int verbose)
{

    
    
    
    
	
		
		
		
    
	

}

static void do_it(Agraph_t * g, int dostat)
{
    agwrite(g, stdout);
    if (dostat)
	prstats(g, dostat > 1);
}
