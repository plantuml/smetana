#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1
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
 *  Compile-time and run-time interface between gpr and libexpr
 */


#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1

#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1









#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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










/*	Public header file for the sfio library
**
**	Written by Kiem-Phong Vo
*/




#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
































































/* Sfoff_t should be large enough for largest file address */







	typedef struct _sfio_s Sfio_t;

    typedef struct _sfdisc_s Sfdisc_t;
    typedef ssize_t(*Sfread_f)
	_ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    typedef ssize_t(*Sfwrite_f)
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    typedef _ast_intmax_t(*Sfseek_f) _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    typedef int (*Sfexcept_f) _ARG_((Sfio_t *, int, Void_t *, Sfdisc_t *));

/* discipline structure */
    struct _sfdisc_s {
	Sfread_f readf;		/* read function                */
	Sfwrite_f writef;	/* write function               */
	Sfseek_f seekf;		/* seek function                */
	Sfexcept_f exceptf;	/* to handle exceptions         */
	Sfdisc_t *disc;		/* the continuing discipline    */
    };

/* a file structure */
    struct _sfio_s {
	unsigned char *next;	/* next position to read/write from     */
	unsigned char *endw;	/* end of write buffer                  */
	unsigned char *endr;	/* end of read buffer                   */
	unsigned char *endb;	/* end of buffer                        */
	Sfio_t *push;		/* the stream that was pushed on        */
	unsigned short flags;	/* type of stream                       */
	short file;		/* file descriptor                      */
	unsigned char *data;	/* base of data buffer                  */
	ssize_t size;		/* buffer size                          */
	ssize_t val;		/* values or string lengths             */

	 

    };

/* formatting environment */
    typedef struct _sffmt_s Sffmt_t;
    typedef int (*Sffmtext_f) _ARG_((Sfio_t *, Void_t *, Sffmt_t *));
    typedef int (*Sffmtevent_f)
	_ARG_((Sfio_t *, int, Void_t *, Sffmt_t *));
    struct _sffmt_s {
	long version;		/* version of this structure            */
	Sffmtext_f extf;	/* function to process arguments        */
	Sffmtevent_f eventf;	/* process events                       */

	char *form;		/* format string to stack               */
	va_list args;		/* corresponding arg list               */

	int fmt;		/* format character                     */
	ssize_t size;		/* object size                          */
	int flags;		/* formatting flags                     */
	int width;		/* width of field                       */
	int precis;		/* precision required                   */
	int base;		/* conversion base                      */

	char *t_str;		/* type string                          */
	ssize_t n_str;		/* length of t_str                      */

	Void_t *noop;		/* as yet unused                        */
    };
























/* for sfmutex() call */





/* various constants */













/* bits for various types of files */







    /* but BSDI stat.h now uses this symbol. */
    /* So we leave it out in such cases.    */




















/* for sfgetr/sfreserve to hold a record */



/* exception events: SF_NEW(0), SF_READ(1), SF_WRITE(2) and the below 	*/





    /* but AIX now uses this symbol. So we  */
    /* avoid defining it in such cases.     */














/* for stack and disciplines */



/* for the notify function and discipline exception */






     1 extern ssize_t _Sfi;




/* standard in/out/err streams */
    extern Sfio_t *sfstdin;
    extern Sfio_t *sfstdout;
    extern Sfio_t *sfstderr;
    extern Sfio_t _Sfstdin;
    extern Sfio_t _Sfstdout;
    extern Sfio_t _Sfstderr;















    extern Sfio_t *sfnew _ARG_((Sfio_t *, Void_t *, size_t, int, int));
    extern Sfio_t *sfopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfpopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfstack _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sfswap _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sftmp _ARG_((size_t));
    extern int sfpurge _ARG_((Sfio_t *));
    extern int sfpoll _ARG_((Sfio_t **, int, int));
    extern Void_t *sfreserve _ARG_((Sfio_t *, ssize_t, int));
    extern int sfsync _ARG_((Sfio_t *));
    extern int sfclrlock _ARG_((Sfio_t *));
    extern Void_t *sfsetbuf _ARG_((Sfio_t *, Void_t *, size_t));
    extern Sfdisc_t *sfdisc _ARG_((Sfio_t *, Sfdisc_t *));
    extern int sfraise _ARG_((Sfio_t *, int, Void_t *));
    extern int sfnotify _ARG_((void (*)(Sfio_t *, int, int)));
    extern int sfset _ARG_((Sfio_t *, int, int));
    extern int sfsetfd _ARG_((Sfio_t *, int));
    extern Sfio_t *sfpool _ARG_((Sfio_t *, Sfio_t *, int));
    extern ssize_t sfread _ARG_((Sfio_t *, Void_t *, size_t));
    extern ssize_t sfwrite _ARG_((Sfio_t *, const Void_t *, size_t));
    extern _ast_intmax_t sfmove _ARG_((Sfio_t *, Sfio_t *, _ast_intmax_t, int));
    extern int sfclose _ARG_((Sfio_t *));
    extern _ast_intmax_t sftell _ARG_((Sfio_t *));
    extern _ast_intmax_t sfseek _ARG_((Sfio_t *, _ast_intmax_t, int));
    extern ssize_t sfputr _ARG_((Sfio_t *, const char *, int));
    extern char *sfgetr _ARG_((Sfio_t *, int, int));
    extern ssize_t sfnputc _ARG_((Sfio_t *, int, size_t));
    extern int sfungetc _ARG_((Sfio_t *, int));
    extern int sfprintf _ARG_((Sfio_t *, const char *, ...));
    extern char *sfprints _ARG_((const char *, ...));
    extern int sfsprintf _ARG_((char *, int, const char *, ...));
    extern int sfvsprintf _ARG_((char *, int, const char *, va_list));
    extern int sfvprintf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfscanf _ARG_((Sfio_t *, const char *, ...));
    extern int sfsscanf _ARG_((const char *, const char *, ...));
    extern int sfvsscanf _ARG_((const char *, const char *, va_list));
    extern int sfvscanf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfresize _ARG_((Sfio_t *, _ast_intmax_t));

/* mutex locking for thread-safety */
    extern int sfmutex _ARG_((Sfio_t *, int));

/* io functions with discipline continuation */
    extern ssize_t sfrd _ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    extern ssize_t sfwr
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    extern _ast_intmax_t sfsk _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    extern ssize_t sfpkrd _ARG_((int, Void_t *, size_t, int, long, int));

/* portable handling of primitive types */
    extern int sfdlen _ARG_((_ast_fltmax_t));
    extern int sfllen _ARG_((_ast_intmax_t));
    extern int sfulen _ARG_((unsigned _ast_intmax_t));

    extern int sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int sfputc _ARG_((Sfio_t *, int));

    extern _ast_fltmax_t sfgetd _ARG_((Sfio_t *));
    extern _ast_intmax_t sfgetl _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetu _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetm _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfgetc _ARG_((Sfio_t *));

    extern int _sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int _sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int _sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int _sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int _sfflsbuf _ARG_((Sfio_t *, int));

    extern int _sffilbuf _ARG_((Sfio_t *, int));

    extern int _sfdlen _ARG_((_ast_fltmax_t));
    extern int _sfllen _ARG_((_ast_intmax_t));
    extern int _sfulen _ARG_((unsigned _ast_intmax_t));

/* miscellaneous function analogues of fast in-line functions */
    extern _ast_intmax_t sfsize _ARG_((Sfio_t *));
    extern int sfclrerr _ARG_((Sfio_t *));
    extern int sfeof _ARG_((Sfio_t *));
    extern int sferror _ARG_((Sfio_t *));
    extern int sffileno _ARG_((Sfio_t *));
    extern int sfstacked _ARG_((Sfio_t *));
    extern ssize_t sfvalue _ARG_((Sfio_t *));
    extern ssize_t sfslen _ARG_((void));


     _END_EXTERNS_
/* coding long integers in a portable and compact fashion */




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\parse.h" 1
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








    typedef enum { Begin =
	    0, End, BeginG, EndG, Node, Edge, Eof, Error } case_t;

    typedef struct _case_info {
	int gstart;
	char *guard;
	int astart;
	char *action;
	struct _case_info *next;
    } case_info;

    typedef struct _parse_block {
	int l_beging;
	char *begg_stmt;
	int n_nstmts;
	int n_estmts;
	case_info *node_stmts;
	case_info *edge_stmts;
	struct _parse_block *next;
    } parse_block; 

    typedef struct {
	char *source;
	int l_begin, l_end, l_endg;
	char *begin_stmt;
	int n_blocks;
	parse_block *blocks;
	char *endg_stmt;
	char *end_stmt;
    } parse_prog;

    extern parse_prog *parseProg(char *, int);
    extern void freeParseProg (parse_prog *);






#line 20 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1



/*	Public interface for the dictionary library
**
**      Written by Kiem-Phong Vo
*/











#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1






















typedef struct _dtlink_s	Dtlink_t;
typedef struct _dthold_s	Dthold_t;
typedef struct _dtdisc_s	Dtdisc_t;
typedef struct _dtmethod_s	Dtmethod_t;
typedef struct _dtdata_s	Dtdata_t;
typedef struct _dt_s		Dt_t;
typedef struct _dt_s		Dict_t;	/* for libdict compatibility */
typedef struct _dtstat_s	Dtstat_t;
typedef void*			(*Dtmemory_f)(Dt_t*,void*,size_t,Dtdisc_t*);
typedef void*			(*Dtsearch_f)(Dt_t*,void*,int);
typedef void* 		(*Dtmake_f)(Dt_t*,void*,Dtdisc_t*);
typedef void 			(*Dtfree_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtcompar_f)(Dt_t*,void*,void*,Dtdisc_t*);
typedef unsigned int		(*Dthash_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtevent_f)(Dt_t*,int,void*,Dtdisc_t*);

struct _dtlink_s
{	Dtlink_t*	right;	/* right child		*/
	union
	{ unsigned int	_hash;	/* hash value		*/
	  Dtlink_t*	_left;	/* left child		*/
	} hl;
};

/* private structure to hold an object */
struct _dthold_s
{	Dtlink_t	hdr;	/* header		*/
	void*		obj;	/* user object		*/
};

/* method to manipulate dictionary structure */
struct _dtmethod_s 
{	Dtsearch_f	searchf; /* search function	*/
	int		type;	/* type of operation	*/
};

/* stuff that may be in shared memory */
struct _dtdata_s
{	int		type;	/* type of dictionary			*/
	Dtlink_t*	here;	/* finger to last search element	*/
	union
	{ Dtlink_t**	_htab;	/* hash table				*/
	  Dtlink_t*	_head;	/* linked list				*/
	} hh;
	int		ntab;	/* number of hash slots			*/
	int		size;	/* number of objects			*/
	int		loop;	/* number of nested loops		*/
	int		minp;	/* min path before splay, always even	*/
				/* for hash dt, > 0: fixed table size 	*/
};

/* structure to hold methods that manipulate an object */
struct _dtdisc_s
{	int		key;	/* where the key begins in an object	*/
	int		size;	/* key size and type			*/
	int		link;	/* offset to Dtlink_t field		*/
	Dtmake_f	makef;	/* object constructor			*/
	Dtfree_f	freef;	/* object destructor			*/
	Dtcompar_f	comparf;/* to compare two objects		*/
	Dthash_f	hashf;	/* to compute hash value of an object	*/
	Dtmemory_f	memoryf;/* to allocate/free memory		*/
	Dtevent_f	eventf;	/* to process events			*/
};













/* the dictionary structure itself */
struct _dt_s
{	Dtsearch_f	searchf;/* search function			*/
	Dtdisc_t*	disc;	/* method to manipulate objs		*/
	Dtdata_t*	data;	/* sharable data			*/
	Dtmemory_f	memoryf;/* function to alloc/free memory	*/
	Dtmethod_t*	meth;	/* dictionary method			*/
	int		type;	/* type information			*/
	int		nview;	/* number of parent view dictionaries	*/
	Dt_t*		view;	/* next on viewpath			*/
	Dt_t*		walk;	/* dictionary being walked		*/
	void*		user;	/* for user's usage			*/
};

/* structure to get status of a dictionary */
struct _dtstat_s
{	int	dt_meth;	/* method type				*/
	int	dt_size;	/* number of elements			*/
	int	dt_n;		/* number of chains or levels		*/
	int	dt_max;		/* max size of a chain or a level	*/
	int*	dt_count;	/* counts of chains or levels by size	*/
};

/* flag set if the last search operation actually found the object */


/* supported storage methods */










/* asserts to dtdisc() */



/* types of search */















/* events */








1	/* public data */







extern Dtmethod_t* 	Dtset;
extern Dtmethod_t* 	Dtbag;
extern Dtmethod_t* 	Dtoset;
extern Dtmethod_t* 	Dtobag;
extern Dtmethod_t*	Dtlist;
extern Dtmethod_t*	Dtstack;
extern Dtmethod_t*	Dtqueue;
extern Dtmethod_t*	Dtdeque;

/* compatibility stuff; will go away */

extern Dtmethod_t*	Dtorder;
extern Dtmethod_t*	Dttree;
extern Dtmethod_t*	Dthash;
extern Dtmethod_t	_Dttree;
extern Dtmethod_t	_Dthash;
extern Dtmethod_t	_Dtlist;
extern Dtmethod_t	_Dtqueue;
extern Dtmethod_t	_Dtstack;





1	/* public functions */




extern Dt_t*		dtopen (Dtdisc_t*, Dtmethod_t*);
extern int		dtclose (Dt_t*);
extern Dt_t*		dtview (Dt_t*, Dt_t*);
extern Dtdisc_t*	dtdisc (Dt_t* dt, Dtdisc_t*, int);
extern Dtmethod_t*	dtmethod (Dt_t*, Dtmethod_t*);

extern Dtlink_t*	dtflatten (Dt_t*);
extern Dtlink_t*	dtextract (Dt_t*);
extern int		dtrestore (Dt_t*, Dtlink_t*);

extern int		dttreeset (Dt_t*, int, int);

extern int		dtwalk (Dt_t*, int(*)(Dt_t*,void*,void*), void*);

extern void*		dtrenew (Dt_t*, void*);

extern int		dtsize (Dt_t*);
extern int		dtstat (Dt_t*, Dtstat_t*, int);
extern unsigned int	dtstrhash (unsigned int, void*, int);











/* internal functions for translating among holder, object and key */












/* special search function for tree structure only */

























































#line 17 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 2






















/* forward struct type declarations */
typedef struct Agtag_s Agtag_t;
typedef struct Agobj_s Agobj_t;	/* generic object header */
typedef struct Agraph_s Agraph_t;	/* graph, subgraph (or hyperedge) */
typedef struct Agnode_s Agnode_t;	/* node (atom) */
typedef struct Agedge_s Agedge_t;	/* node pair */
typedef struct Agdesc_s Agdesc_t;	/* graph descriptor */
typedef struct Agmemdisc_s Agmemdisc_t;	/* memory allocator */
typedef struct Agiddisc_s Agiddisc_t;	/* object ID allocator */
typedef struct Agiodisc_s Agiodisc_t;	/* IO services */
typedef struct Agdisc_s Agdisc_t;	/* union of client discipline methods */
typedef struct Agdstate_s Agdstate_t;	/* client state (closures) */
typedef struct Agsym_s Agsym_t;	/* string attribute descriptors */
typedef struct Agattr_s Agattr_t;	/* string attribute container */
typedef struct Agcbdisc_s Agcbdisc_t;	/* client event callbacks */
typedef struct Agcbstack_s Agcbstack_t;	/* enclosing state for cbdisc */
typedef struct Agclos_s Agclos_t;	/* common fields for graph/subgs */
typedef struct Agrec_s Agrec_t;	/* generic runtime record */
typedef struct Agdatadict_s Agdatadict_t;	/* set of dictionaries per graph */
typedef struct Agedgepair_s Agedgepair_t;	/* the edge object */
typedef struct Agsubnode_s Agsubnode_t;

/* Header of a user record.  These records are attached by client programs
dynamically at runtime.  A unique string ID must be given to each record
attached to the same object.  Cgraph has functions to create, search for,
and delete these records.   The records are maintained in a circular list,
with obj->data pointing somewhere in the list.  The search function has
an option to lock this pointer on a given record.  The application must
be written so only one such lock is outstanding at a time. */

struct Agrec_s {
    char *name;
    Agrec_t *next;
    /* following this would be any programmer-defined data */
};

/* Object tag for graphs, nodes, and edges.  While there may be several structs
for a given node or edges, there is only one unique ID (per main graph).  */
struct Agtag_s {
    unsigned objtype:2;		/* see literal tags below */
    unsigned mtflock:1;		/* move-to-front lock, see above */
    unsigned attrwf:1;		/* attrs written (parity, write.c) */
    unsigned seq:(sizeof(unsigned) * 8 - 4);	/* sequence no. */
    unsigned long id;		/* client  ID */
};

	/* object tags */






	/* a generic graph/node/edge header */
struct Agobj_s {
    Agtag_t tag;
    Agrec_t *data;
};








/* This is the node struct allocated per graph (or subgraph).  It resides
in the n_dict of the graph.  The node set is maintained by libdict, but
transparently to libgraph callers.  Every node may be given an optional
string name at its time of creation, or it is permissible to pass NIL(char*)
for the name. */

struct Agsubnode_s {		/* the node-per-graph-or-subgraph record */
    Dtlink_t seq_link;		/* must be first */
    Dtlink_t id_link;
    Agnode_t *node;		/* the object */
    Dtlink_t *in_id, *out_id;	/* by node/ID for random access */
    Dtlink_t *in_seq, *out_seq;	/* by node/sequence for serial access */
};

struct Agnode_s {
    Agobj_t base;
    Agraph_t *root;
    Agsubnode_t mainsub;	/* embedded for main graph */
};

struct Agedge_s {
    Agobj_t base;
    Dtlink_t id_link;		/* main graph only */
    Dtlink_t seq_link;
    Agnode_t *node;		/* the endpoint node */
};

struct Agedgepair_s {
    Agedge_t out, in;
};

struct Agdesc_s {		/* graph descriptor */
    unsigned directed:1;	/* if edges are asymmetric */
    unsigned strict:1;		/* if multi-edges forbidden */
    unsigned no_loop:1;		/* if no loops */
    unsigned maingraph:1;	/* if this is the top level graph */
    unsigned flatlock:1;	/* if sets are flattened into lists in cdt */
    unsigned no_write:1;	/* if a temporary subgraph */
    unsigned has_attrs:1;	/* if string attr tables should be initialized */
    unsigned has_cmpnd:1;	/* if may contain collapsed nodes */
};

/* disciplines for external resources needed by libgraph */

struct Agmemdisc_s {		/* memory allocator */
    void *(*open) (Agdisc_t*);	/* independent of other resources */
    void *(*alloc) (void *state, size_t req);
    void *(*resize) (void *state, void *ptr, size_t old, size_t req);
    void (*free) (void *state, void *ptr);
    void (*close) (void *state);
};

struct Agiddisc_s {		/* object ID allocator */
    void *(*open) (Agraph_t * g, Agdisc_t*);	/* associated with a graph */
    long (*map) (void *state, int objtype, char *str, unsigned long *id,
		 int createflag);
    long (*alloc) (void *state, int objtype, unsigned long id);
    void (*free) (void *state, int objtype, unsigned long id);
    char *(*print) (void *state, int objtype, unsigned long id);
    void (*close) (void *state);
    void (*idregister) (void *state, int objtype, void *obj);
};

struct Agiodisc_s {
    int (*afread) (void *chan, char *buf, int bufsize);
    int (*putstr) (void *chan, const char *str);
    int (*flush) (void *chan);	/* sync */
    /* error messages? */
};

struct Agdisc_s {		/* user's discipline */
    Agmemdisc_t *mem;
    Agiddisc_t *id;
    Agiodisc_t *io;
};

	/* default resource disciplines */

/*visual studio*/



/*end visual studio*/

extern Agmemdisc_t AgMemDisc;
extern Agiddisc_t AgIdDisc;
extern Agiodisc_t AgIoDisc;

extern Agdisc_t AgDefaultDisc;


struct Agdstate_s {
    void *mem;
    void *id;
    /* IO must be initialized and finalized outside Cgraph,
     * and channels (FILES) are passed as void* arguments. */
};

typedef void (*agobjfn_t) (Agraph_t * g, Agobj_t * obj, void *arg);
typedef void (*agobjupdfn_t) (Agraph_t * g, Agobj_t * obj, void *arg,
			      Agsym_t * sym);

struct Agcbdisc_s {
    struct {
	agobjfn_t ins;
	agobjupdfn_t mod;
	agobjfn_t del;
    } graph, node, edge;
};

struct Agcbstack_s {		/* object event callbacks */
    Agcbdisc_t *f;		/* methods */
    void *state;		/* closure */
    Agcbstack_t *prev;		/* kept in a stack, unlike other disciplines */
};

struct Agclos_s {
    Agdisc_t disc;		/* resource discipline functions */
    Agdstate_t state;		/* resource closures */
    Dict_t *strdict;		/* shared string dict */
    unsigned long seq[3];	/* local object sequence number counter */
    Agcbstack_t *cb;		/* user and system callback function stacks */
    unsigned char callbacks_enabled;	/* issue user callbacks or hold them? */
    Dict_t *lookup_by_name[3];
    Dict_t *lookup_by_id[3];
};

struct Agraph_s {
    Agobj_t base;
    Agdesc_t desc;
    Dtlink_t link;
    Dict_t *n_seq;		/* the node set in sequence */
    Dict_t *n_id;		/* the node set indexed by ID */
    Dict_t *e_seq, *e_id;	/* holders for edge sets */
    Dict_t *g_dict;		/* subgraphs - descendants */
    Agraph_t *parent, *root;	/* subgraphs - ancestors */
    Agclos_t *clos;		/* shared resources */
};












extern void agpushdisc(Agraph_t * g, Agcbdisc_t * disc, void *state);
extern int agpopdisc(Agraph_t * g, Agcbdisc_t * disc);
extern int agcallbacks(Agraph_t * g, int flag);	/* return prev value */

/* graphs */
extern Agraph_t *agopen(char *name, Agdesc_t desc, Agdisc_t * disc);
extern int agclose(Agraph_t * g);
extern Agraph_t *agread(void *chan, Agdisc_t * disc);
extern Agraph_t *agmemread(const char *cp);
extern void agreadline(int);
extern void agsetfile(char *);
extern Agraph_t *agconcat(Agraph_t * g, void *chan, Agdisc_t * disc);
extern int agwrite(Agraph_t * g, void *chan);
extern int agisdirected(Agraph_t * g);
extern int agisundirected(Agraph_t * g);
extern int agisstrict(Agraph_t * g);
extern int agissimple(Agraph_t * g);

/* nodes */
extern Agnode_t *agnode(Agraph_t * g, char *name, int createflag);
extern Agnode_t *agidnode(Agraph_t * g, unsigned long id, int createflag);
extern Agnode_t *agsubnode(Agraph_t * g, Agnode_t * n, int createflag);
extern Agnode_t *agfstnode(Agraph_t * g);
extern Agnode_t *agnxtnode(Agraph_t * g, Agnode_t * n);
extern Agnode_t *aglstnode(Agraph_t * g);
extern Agnode_t *agprvnode(Agraph_t * g, Agnode_t * n);

extern Agsubnode_t *agsubrep(Agraph_t * g, Agnode_t * n);

/* edges */
extern Agedge_t *agedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			char *name, int createflag);
extern Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			  unsigned long id, int createflag);
extern Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int createflag);
extern Agedge_t *agfstin(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstout(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtout(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n);

/* generic */
extern Agraph_t *agraphof(void* obj);
extern Agraph_t *agroot(void* obj);
extern int agcontains(Agraph_t *, void *);
extern char *agnameof(void *);
extern int agrelabel(void *obj, char *name);	/* scary */
extern int agrelabel_node(Agnode_t * n, char *newname);
extern int agdelete(Agraph_t * g, void *obj);
extern long agdelsubg(Agraph_t * g, Agraph_t * sub);	/* could be agclose */
extern int agdelnode(Agraph_t * g, Agnode_t * arg_n);
extern int agdeledge(Agraph_t * g, Agedge_t * arg_e);
extern int agobjkind(void *);

/* strings */
extern char *agstrdup(Agraph_t *, char *);
extern char *agstrdup_html(Agraph_t *, char *);
extern int aghtmlstr(char *);
extern char *agstrbind(Agraph_t * g, char *);
extern int agstrfree(Agraph_t *, char *);
extern char *agcanon(char *, int);
extern char *agstrcanon(char *, char *);
extern char *agcanonStr(char *str);  /* manages its own buf */

/* definitions for dynamic string attributes */
struct Agattr_s {		/* dynamic string attributes */
    Agrec_t h;			/* common data header */
    Dict_t *dict;		/* shared dict to interpret attr field */
    char **str;			/* the attribute string values */
};

struct Agsym_s {		/* symbol in one of the above dictionaries */
    Dtlink_t link;
    char *name;			/* attribute's name */
    char *defval;		/* its default value for initialization */
    int id;			/* its index in attr[] */
    unsigned char kind;		/* referent object type */
    unsigned char fixed;	/* immutable value */
    unsigned char print;	/* always print */
};

struct Agdatadict_s {		/* set of dictionaries per graph */
    Agrec_t h;			/* installed in list of graph recs */
    struct {
	Dict_t *n, *e, *g;
    } dict;
};

extern Agsym_t *agattr(Agraph_t * g, int kind, char *name, char *value);
extern Agsym_t *agattrsym(void *obj, char *name);
extern Agsym_t *agnxtattr(Agraph_t * g, int kind, Agsym_t * attr);
extern int      agcopyattr(void *oldobj, void *newobj);

extern void *agbindrec(void *obj, char *name, unsigned int size,
		       int move_to_front);
extern Agrec_t *aggetrec(void *obj, char *name, int move_to_front);
extern int agdelrec(void *obj, char *name);
extern void aginit(Agraph_t * g, int kind, char *rec_name, int rec_size,
		   int move_to_front);
extern void agclean(Agraph_t * g, int kind, char *rec_name);

extern char *agget(void *obj, char *name);
extern char *agxget(void *obj, Agsym_t * sym);
extern int agset(void *obj, char *name, char *value);
extern int agxset(void *obj, Agsym_t * sym, char *value);
extern int agsafeset(void* obj, char* name, char* value, char* def);

/* defintions for subgraphs */
extern Agraph_t *agsubg(Agraph_t * g, char *name, int cflag);	/* constructor */
extern Agraph_t *agidsubg(Agraph_t * g, unsigned long id, int cflag);	/* constructor */
extern Agraph_t *agfstsubg(Agraph_t * g), *agnxtsubg(Agraph_t * subg);
extern Agraph_t *agparent(Agraph_t * g);

/* set cardinality */
extern int agnnodes(Agraph_t * g), agnedges(Agraph_t * g), agnsubg(Agraph_t * g);
extern int agdegree(Agraph_t * g, Agnode_t * n, int in, int out);
extern int agcountuniqedges(Agraph_t * g, Agnode_t * n, int in, int out);

/* memory */
extern void *agalloc(Agraph_t * g, size_t size);
extern void *agrealloc(Agraph_t * g, void *ptr, size_t oldsize,
		       size_t size);
extern void agfree(Agraph_t * g, void *ptr);
extern struct _vmalloc_s *agheap(Agraph_t * g);

/* an engineering compromise is a joy forever */
extern void aginternalmapclearlocalnames(Agraph_t * g);




/* error handling */
typedef enum { AGWARN, AGERR, AGMAX, AGPREV } agerrlevel_t;
typedef int (*agusererrf) (char*);
extern agerrlevel_t agseterr(agerrlevel_t);
extern char *aglasterr(void);
extern int agerr(agerrlevel_t level, const char *fmt, ...);
extern void agerrorf(const char *fmt, ...);
extern void agwarningf(const char *fmt, ...);
extern int agerrors(void);
extern int agreseterrors(void);
extern agusererrf agseterrf(agusererrf);

/* data access macros */
/* this assumes that e[0] is out and e[1] is inedge, see edgepair in edge.c  */
























extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,
    Agstrictundirected;



/* fast graphs */
void agflatten(Agraph_t * g, int flag);
typedef Agsubnode_t	Agnoderef_t;
typedef Dtlink_t	Agedgeref_t;



















/* this is expedient but a bit slimey because it "knows" that dict entries of both nodes
and edges are embedded in main graph objects but allocated separately in subgraphs */











#line 20 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 19 "graphviz-2.38.0\\lib\\ast\\ast.h" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\align.h" 1
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





/* : : generated from features/align.c by iffe version 1999-08-11 : : */


    typedef unsigned long ALIGN_INTEGRAL;
































#line 22 "graphviz-2.38.0\\lib\\ast\\ast.h" 2























/*
 * strgrpmatch() flags
 */






/*
 * fmtquote() flags
 */

















    extern char *pathpath(char *, const char *, const char *, int);
    extern char *pathfind(const char *, const char *, const char *, char *,
			  size_t);
    extern char *pathaccess(char *, const char *, const char *,
			    const char *, int);
    extern char *pathbin(void);
    extern char *pathcat(char *, const char *, int, const char *,
			 const char *);
    extern int pathgetlink(const char *, char *, int);
    extern int pathexists(char *, int);

    extern int chresc(const char *, char **);
    extern int chrtoi(const char *);
    extern char *fmtesq(const char *, const char *);
    extern char *fmtesc(const char *as);
    extern char *fmtbuf(size_t n);
    extern char *fmtquote(const char *, const char *, const char *, size_t,
			  int);

    extern int astquery(int, const char *, ...);

    extern int strmatch(const char *, const char *);
    extern int strgrpmatch(const char *, const char *, int *, int, int);
    extern int stresc(char *);
    extern long strton(const char *, char **, char *, int);
    extern char *strcopy(char *s, const char *t);






#line 21 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmalloc.h" 1
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








/*	Public header file for the virtual malloc package.
**
**	Written by Kiem-Phong Vo, kpv@research.att.com, 01/16/94.
*/






#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmalloc.h" 1


    typedef struct _vmalloc_s Vmalloc_t;
    typedef struct _vmstat_s Vmstat_t;
    typedef struct _vmdisc_s Vmdisc_t;
    typedef struct _vmethod_s Vmethod_t;
    typedef void *(*Vmemory_f)
	(Vmalloc_t *, void *, size_t, size_t, Vmdisc_t *);
    typedef int (*Vmexcept_f)
	(Vmalloc_t *, int, void *, Vmdisc_t *);

    struct _vmstat_s {
	int n_busy;		/* number of busy blocks        */
	int n_free;		/* number of free blocks        */
	size_t s_busy;		/* total amount of busy space   */
	size_t s_free;		/* total amount of free space   */
	size_t m_busy;		/* largest busy piece           */
	size_t m_free;		/* largest free piece           */
	int n_seg;		/* number of segments           */
	size_t extent;		/* total size of region         */
    };

    struct _vmdisc_s {
	Vmemory_f memoryf;	/* memory manipulator           */
	Vmexcept_f exceptf;	/* exception handler            */
	size_t round;		/* rounding requirement         */
    };

    struct _vmethod_s {
	void *(*allocf) (Vmalloc_t *, size_t);
	void *(*resizef) (Vmalloc_t *, void *, size_t, int);
	int (*freef) (Vmalloc_t *, void *);
	long (*addrf) (Vmalloc_t *, void *);
	long (*sizef) (Vmalloc_t *, void *);
	int (*compactf) (Vmalloc_t *);
	void *(*alignf) (Vmalloc_t *, size_t, size_t);
	unsigned short meth;
    };

    struct _vmalloc_s {
	Vmethod_t meth;		/* method for allocation        */
	char *file;		/* file name                    */
	int line;		/* line number                  */

	 

    };


















/* exception types */






     1		/* public data */







/*visual studio*/







/*end visual studio*/		 
		 extern Vmethod_t *Vmbest;	/* best allocation              */
    extern Vmethod_t *Vmlast;	/* last-block allocation        */
    extern Vmethod_t *Vmpool;	/* pool allocation              */
    extern Vmethod_t *Vmdebug;	/* allocation with debugging    */
    extern Vmethod_t *Vmprofile;	/* profiling memory usage       */

    extern Vmdisc_t *Vmdcheap;	/* heap discipline              */
    extern Vmdisc_t *Vmdcsbrk;	/* sbrk discipline              */

    extern Vmalloc_t *Vmheap;	/* heap region                  */
    extern Vmalloc_t *Vmregion;	/* malloc region                */

      1	/* public functions */



     extern Vmalloc_t *vmopen (Vmdisc_t *, Vmethod_t *, int);
    extern int vmclose (Vmalloc_t *);
    extern int vmclear (Vmalloc_t *);
    extern int vmcompact (Vmalloc_t *);

    extern Vmdisc_t *vmdisc (Vmalloc_t *, Vmdisc_t *);

    extern void *vmalloc (Vmalloc_t *, size_t);
    extern void *vmalign (Vmalloc_t *, size_t, size_t);
    extern void *vmresize (Vmalloc_t *, void *, size_t, int);
    extern int vmfree (Vmalloc_t *, void *);

    extern long vmaddr (Vmalloc_t *, void *);
    extern long vmsize (Vmalloc_t *, void *);

    extern Vmalloc_t *vmregion (void *);
    extern void *vmsegment (Vmalloc_t *, void *);
    extern int vmset (Vmalloc_t *, int, int);

    extern void *vmdbwatch (void *);
    extern int vmdbcheck (Vmalloc_t *);

    extern int vmprofile (Vmalloc_t *, int);

    extern int vmtrace (int);
    extern int vmtrbusy (Vmalloc_t *);

    extern int vmstat (Vmalloc_t *, Vmstat_t *);

    extern int vmwalk (Vmalloc_t *,
 int(*)(Vmalloc_t *, void *, size_t,
 Vmdisc_t *));
    extern char *vmstrdup (Vmalloc_t *, const char *);




    extern void *malloc (size_t);
    extern void *realloc (void *, size_t);
    extern void free (void *);
    extern void cfree (void *);
    extern void *calloc (size_t, size_t);
    extern void *memalign (size_t, size_t);
    extern void *valloc (size_t);



     
/* to coerce any value to a Vmalloc_t*, make ANSI happy */

/* enable recording of where a call originates from */


































/* non-debugging/profiling allocation calls */
























#line 22 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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
 * AT&T Research
 *
 * expression library definitions
 */




#line 1 "graphviz-2.38.0\\lib\\ast\\ast.h" 1
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
































































    
    
			  
    
			    
    
    
			 
    
    

    
    
    
    
    
    
			  

    

    
    
    
    
    






#line 26 "graphviz-2.38.0\\lib\\expr\\expr.h" 2










/*
 * bison -pPREFIX misses YYSTYPE
 */




#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1


/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */



/* Enabling traces.  */




extern int exdebug;


/* Tokens.  */


   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum extokentype {
     MINTOKEN = 258,
     INTEGER = 259,
     UNSIGNED = 260,
     CHARACTER = 261,
     FLOATING = 262,
     STRING = 263,
     VOIDTYPE = 264,
     STATIC = 265,
     ADDRESS = 266,
     ARRAY = 267,
     BREAK = 268,
     CALL = 269,
     CASE = 270,
     CONSTANT = 271,
     CONTINUE = 272,
     DECLARE = 273,
     DEFAULT = 274,
     DYNAMIC = 275,
     ELSE = 276,
     EXIT = 277,
     FOR = 278,
     FUNCTION = 279,
     GSUB = 280,
     ITERATE = 281,
     ITERATER = 282,
     ID = 283,
     IF = 284,
     LABEL = 285,
     MEMBER = 286,
     NAME = 287,
     POS = 288,
     PRAGMA = 289,
     PRE = 290,
     PRINT = 291,
     PRINTF = 292,
     PROCEDURE = 293,
     QUERY = 294,
     RAND = 295,
     RETURN = 296,
     SCANF = 297,
     SPLIT = 298,
     SPRINTF = 299,
     SRAND = 300,
     SSCANF = 301,
     SUB = 302,
     SUBSTR = 303,
     SWITCH = 304,
     TOKENS = 305,
     UNSET = 306,
     WHILE = 307,
     F2I = 308,
     F2S = 309,
     I2F = 310,
     I2S = 311,
     S2B = 312,
     S2F = 313,
     S2I = 314,
     F2X = 315,
     I2X = 316,
     S2X = 317,
     X2F = 318,
     X2I = 319,
     X2S = 320,
     X2X = 321,
     XPRINT = 322,
     OR = 323,
     AND = 324,
     NE = 325,
     EQ = 326,
     GE = 327,
     LE = 328,
     RS = 329,
     LS = 330,
     IN_OP = 331,
     UNARY = 332,
     DEC = 333,
     INC = 334,
     CAST = 335,
     MAXTOKEN = 336
   };

/* Tokens.  */



















































































typedef union EXSTYPE
{
/* Line 2049 of yacc.c  */


	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	_ast_intmax_t	integer;
	int		op;
	char*		string;
	void*		user;
	struct Exbuf_s*	buffer;


/* Line 2049 of yacc.c  */

} EXSTYPE;





extern EXSTYPE exlval;











int exparse ();





#line 38 "graphviz-2.38.0\\lib\\expr\\expr.h" 2





#line 1 "graphviz-2.38.0\\lib\\expr\\exparse.h" 1















































   

   
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   


























































































	
	
	
	
	
	
	
	
	




























#line 41 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 44 "graphviz-2.38.0\\lib\\expr\\expr.h" 2
#line 1 "graphviz-2.38.0\\lib\\vmalloc\\vmalloc.h" 1
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





















    
    
    
    
    
	
    
	

    
	
	
	
	
	
	
	
	
    

    
	
	
	
    

    
	
	
	
	
	
	
	
	
    

    
	
	
	

	 

    

























     















		 
		 
    
    
    
    

    
    

    
    

     



     
    
    
    

    

    
    
    
    

    
    

    
    
    

    
    

    

    
    

    

    
			     
				     
    




    
    
    
    
    
    
    



     






























































#line 45 "graphviz-2.38.0\\lib\\expr\\expr.h" 2



/*
 * flags
 */




















/* previously known as EXID, but EXID is also defined by bison in y.tab.h */







/* function type mechanism
 * types are encoded in TBITS
 * Thus, maximum # of parameters, including return type,
 * is sizeof(Exid_t.type)/TBITS. Also see T in exgram.h
 */

/*
 * arg 0 is the return value type
 */


















typedef short Exshort_t;


typedef EXSTYPE Extype_t;

union Exdata_u; typedef union Exdata_u Exdata_t;
struct Exdisc_s; typedef struct Exdisc_s Exdisc_t;
struct Exnode_s; typedef struct Exnode_s Exnode_t;
struct Expr_s; typedef struct Expr_s Expr_t;
struct Exref_s; typedef struct Exref_s Exref_t;

typedef int (*Exerror_f) (Expr_t *, Exdisc_t *, int, const char *, ...);
typedef void (*Exexit_f) (Expr_t *, Exdisc_t *, int);

typedef struct Exlocal_s		/* user defined member type	*/
{
	_ast_intmax_t	number;
	char*		pointer;
} Exlocal_t;

typedef struct Exid_s			/* id symbol table info		*/
{
	Dtlink_t	link;		/* symbol table link		*/
	long		lex;		/* lex class			*/
	long		index;		/* user defined index		*/
	long		type;		/* symbol and arg types		*/
	long		index_type;	/* index type for arrays        */
	long		flags;		/* user defined flags		*/
	Exnode_t*	value;		/* value			*/
	Exlocal_t	local;		/* user defined local stuff	*/
	long		isstatic;	/* static			*/
	char		name[32];/* symbol name			*/
} Exid_t;

struct Exref_s				/* . reference list		*/
{
	Exref_t*	next;		/* next in list			*/
	Exid_t*		symbol;		/* reference id symbol		*/
	Exnode_t*	index;		/* optional reference index	*/
};

typedef struct Exbuf_s			/* sized buffer			*/
{
	unsigned long	size;		/* buffer size			*/
	char*		data;		/* buffer data			*/
} Exbuf_t;

union Exdata_u
{

	struct
	{
	Extype_t	value;		/* constant value		*/
	Exid_t*		reference;	/* conversion reference symbol	*/
	}		constant;	/* variable reference		*/

	struct
	{
	Exnode_t*	left;		/* left operand			*/
	Exnode_t*	right;		/* right operand		*/
	Exnode_t*	last;		/* for cons			*/
	}		operand;	/* operands			*/

	struct
	{
	Exnode_t*	statement;	/* case label statement(s)	*/
	Exnode_t*	next;		/* next case item		*/
	Extype_t**	constant;	/* case label constant array	*/
	}		select;		/* case item			*/

	struct
	{
	Exid_t*		symbol;		/* id symbol table entry	*/
	Exref_t*	reference;	/* . reference list		*/
	Exnode_t*	index;		/* array index expression	*/
	Exnode_t*	dyna;		/* dynamic expression		*/
	}		variable;	/* variable reference		*/


	


};

struct Exnode_s				/* expression tree node		*/
{
	Exshort_t	type;		/* value type			*/
	Exshort_t	op;		/* operator			*/
	Exshort_t	binary;		/* data.operand.{left,right} ok	*/
	Exshort_t	pad_1;		/* padding to help cc		*/
	Exlocal_t	local;		/* user defined local stuff	*/
	union
	{
	double	(*floating)(char**);	/* FLOATING return value	*/
	_ast_intmax_t(*integer)(char**);	/* INTEGER|UNSIGNED return value*/
	char*	(*string)(char**);	/* STRING return value		*/
	}		compiled;	/* compiled function pointer	*/
	Exdata_t	data;		/* node data			*/


	


};

struct Exdisc_s				/* discipline			*/
{
	unsigned long	version;	/* EX_VERSION			*/
	unsigned long	flags;		/* EX_* flags			*/
	Exid_t*		symbols;	/* static symbols		*/
	char**		data;		/* compiled function arg data	*/
	char*		lib;		/* pathfind() lib		*/
	char*		type;		/* pathfind() type		*/
	int		(*castf)(Expr_t*, Exnode_t*, const char*, int, Exid_t*, int, Exdisc_t*);
					/* unknown cast function	*/
	int		(*convertf)(Expr_t*, Exnode_t*, int, Exid_t*, int, Exdisc_t*);
					/* type conversion function	*/
	int		(*binaryf) (Expr_t *, Exnode_t *, Exnode_t *, Exnode_t *, int, Exdisc_t *);
					/* binary operator function     */
	char*		(*typename) (Expr_t *, int);
					/* application type names       */
	int		(*stringof) (Expr_t *, Exnode_t *, int, Exdisc_t *);
					/* value to string conversion   */
	Extype_t	(*keyf) (Expr_t *, Extype_t, int, Exdisc_t *);
					/* dictionary key for external type objects     */
	Exerror_f	errorf;		/* error function		*/
	Extype_t	(*getf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Exdisc_t*);
					/* get value function		*/
	Extype_t	(*reff)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, char*, int, Exdisc_t*);
					/* reference value function	*/
	int		(*setf)(Expr_t*, Exnode_t*, Exid_t*, Exref_t*, void*, int, Extype_t, Exdisc_t*);
					/* set value function		*/
	int		(*matchf)(Expr_t*, Exnode_t*, const char*, Exnode_t*, const char*, void*, Exdisc_t*);
	/* exit function           */
	Exexit_f	exitf;
	int*		types;
	void*		user;
};

struct Expr_s				/* ex program state		*/
{
	const char*	id;		/* library id			*/
	Dt_t*		symbols;	/* symbol table			*/
	const char*	more;		/* more after %% (sp or != 0)	*/
	Sfio_t*		file[10];	/* io streams			*/
	Vmalloc_t*	vm;		/* program store		*/


	


};

struct Excc_s; typedef struct Excc_s Excc_t;
struct Exccdisc_s; typedef struct Exccdisc_s Exccdisc_t;

struct Exccdisc_s			/* excc() discipline		*/
{
	Sfio_t*		text;		/* text output stream		*/
	char*		id;		/* symbol prefix		*/
	unsigned long	flags;		/* EXCC_* flags			*/
	int		(*ccf)(Excc_t*, Exnode_t*, Exid_t*, Exref_t*, Exnode_t*, Exccdisc_t*);
					/* program generator function	*/
};

struct Excc_s				/* excc() state			*/
{
	Expr_t*		expr;		/* exopen() state		*/
	Exdisc_t*	disc;		/* exopen() discipline		*/


	


};





extern Exnode_t*	excast(Expr_t*, Exnode_t*, int, Exnode_t*, int);
extern Exnode_t*	exnoncast(Exnode_t *);
extern int		excc(Excc_t*, const char*, Exid_t*, int);
extern int		exccclose(Excc_t*);
extern Excc_t*		exccopen(Expr_t*, Exccdisc_t*);
extern void		exclose(Expr_t*, int);
extern int		excomp(Expr_t*, const char*, int, const char*, Sfio_t*);
extern char*		excontext(Expr_t*, char*, int);
extern int		exdump(Expr_t*, Exnode_t*, Sfio_t*);
extern void		exerror(const char*, ...);
extern void		exwarn(const char *, ...);
extern Extype_t		exeval(Expr_t*, Exnode_t*, void*);
extern Exnode_t*	exexpr(Expr_t*, const char*, Exid_t*, int);
extern void		exfreenode(Expr_t*, Exnode_t*);
extern Exnode_t*	exnewnode(Expr_t*, int, int, int, Exnode_t*, Exnode_t*);
extern char*		exnospace(void);
extern Expr_t*		exopen(Exdisc_t*);
extern int		expop(Expr_t*);
extern int		expush(Expr_t*, const char*, int, const char*, Sfio_t*);
extern int		exrewind(Expr_t*);
extern char*		exstash(Sfio_t*, Vmalloc_t*);
extern void		exstatement(Expr_t*);
extern int		extoken_fn(Expr_t*);
extern char*		exstring(Expr_t *, char *);
extern void*		exstralloc(Expr_t *, void *, size_t);
extern int		exstrfree(Expr_t *, void *);
extern char*		extype(int);
extern Extype_t		exzero(int);
extern char*	exopname(int);
extern void		exinit(void);
extern char*	extypename(Expr_t * p, int);
extern int		exisAssign(Exnode_t *);








#line 23 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\gvpr.h" 1
/* $Id$Revision: */
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








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 19 "graphviz-2.38.0\\lib\\gvpr\\gvpr.h" 2




/* Bits for flags variable in gvprstate_t.
 * Included here so that calling programs can use the first
 * two in gvpropts.flags
 */
  /* If set, gvpr calls exit() on errors */

  /* If set, gvpr stores output graphs in gvpropts */

  /* Use longjmp to return to top-level call in gvpr */

  /* $tvnext has been set but not used */



typedef ssize_t (*gvprwr) (void*, const char *buf, size_t nbyte, void*);
typedef int (*gvpruserfn) (char *);
typedef struct {
    char* name;
    gvpruserfn fn;
} gvprbinding;

typedef struct {
    Agraph_t** ingraphs;      /* NULL-terminated array of input graphs */
    int n_outgraphs;          /* if GV_USE_OUTGRAPH set, output graphs */
    Agraph_t** outgraphs;
    gvprwr out;               /* write function for stdout */
    gvprwr err;               /* write function for stderr */
    int flags;
    gvprbinding* bindings;    /* array of bindings, terminated with {NULL,NULL} */
} gvpropts;

    extern int gvpr (int argc, char *argv[], gvpropts* opts);






#line 24 "graphviz-2.38.0\\lib\\gvpr\\gprstate.h" 2

    typedef enum { TV_flat, TV_ne, TV_en, 
                   TV_bfs, 
                   TV_dfs, TV_fwd, TV_rev,
                   TV_postdfs, TV_postfwd, TV_postrev,
                   TV_prepostdfs, TV_prepostfwd, TV_prepostrev,
    } trav_type;

/* Bits for flags variable. 
 */
  /* If set, gvpr calls exit() on errors */

  /* If set, gvpr stores output graphs in gvpropts */



    typedef struct {
	Agraph_t *curgraph;
	Agraph_t *nextgraph;
	Agraph_t *target;
	Agraph_t *outgraph;
	Agobj_t *curobj;
	Sfio_t *tmp;
	Exdisc_t *dp;
	Exerror_f errf;
	Exexit_f exitf;
	char *tgtname;
	char *infname;
	Sfio_t *outFile;
	Agiodisc_t* dfltIO;
	trav_type tvt;
	Agnode_t *tvroot;
	Agnode_t *tvnext;
	Agedge_t *tvedge;
	int name_used;
	int argc;
	char **argv;
	int flags;
	gvprbinding* bindings;
	int n_bindings;
    } Gpr_t;

    typedef struct {
	Sfio_t *outFile;
	int argc;
	char **argv;
	Exerror_f errf;
	Exexit_f exitf;
	int flags;
    } gpr_info;

    extern Gpr_t *openGPRState(gpr_info*);
    extern void addBindings(Gpr_t* state, gvprbinding*);
    extern gvprbinding* findBinding(Gpr_t* state, char*);
    extern void closeGPRState(Gpr_t* state);
    extern void initGPRState(Gpr_t *, Vmalloc_t *);
    extern int validTVT(int);


    







#line 21 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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
 * AT&T Research
 *
 * expression library definitions
 */















































































































	
	




	
	
	
	
	
	
	
	
	
	




	
	
	




	
	





	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
					
	
					
	
					
	
					
	
					
	
					
	
	
					
	
					
	
					
	
	
	
	
	




	
	
	
	
	


	









	
	
	
	
					




	
	


	
















































#line 22 "graphviz-2.38.0\\lib\\gvpr\\compile.h" 2

    typedef struct {
	Exnode_t *guard;
	Exnode_t *action;
    } case_stmt;



    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
	Extype_t iu;
	Agedge_t* ine;
    } nval_t;

    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
	/* Extype_t iu; */
	char lock;
    } gval_t;

    typedef struct {
	Agrec_t h;
	/* Extype_t xu; */
    } uval_t;



    typedef nval_t ndata;
    typedef uval_t edata;
    typedef gval_t gdata;












    typedef struct {
	Exnode_t *begg_stmt;
	int walks;
	int n_nstmts;
	int n_estmts;
	case_stmt *node_stmts;
	case_stmt *edge_stmts;
    } comp_block; 

    typedef struct {
	int flags;
	Expr_t *prog;
	Exnode_t *begin_stmt;
	int n_blocks;
	comp_block  *blocks;
	Exnode_t *endg_stmt;
	Exnode_t *end_stmt;
    } comp_prog;

    extern comp_prog *compileProg(parse_prog *, Gpr_t *, int);
    extern void freeCompileProg (comp_prog *p);
    extern int usesGraph(comp_prog *);
    extern int walksGraph(comp_block *);
    extern Agraph_t *readG(Sfio_t * fp);
    extern Agraph_t *openG(char *name, Agdesc_t);
    extern Agraph_t *openSubg(Agraph_t * g, char *name);
    extern Agnode_t *openNode(Agraph_t * g, char *name);
    extern Agedge_t *openEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key);






#line 23 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 25 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
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
 * standalone mini error interface
 */




#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1
#line 1 "graphviz-2.38.0\\lib\\ast\\error.h" 1

    typedef struct Error_info_s {
	int errors;
	int indent;
	int line;
	int warnings;
	int trace;
	char *file;
	char *id;
    } Error_info_t;



















    extern Error_info_t _err_info;

    extern void setTraceLevel (int);
    extern void setErrorLine (int);
    extern void setErrorFileLine (char*, int);
    extern void setErrorId (char*);
    extern void setErrorErrors (int);
    extern int  getErrorErrors (void);

    extern void _err_msg(int, ...);
    extern void errorf(void *, void *, int, ...);
    extern void _err_msgv(const char *, int, va_list);






#line 26 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 1
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








#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
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


























































    
    
    





    
    
    
    
    


	






	

    
    
















    
    
    
    
    



    
    
    



    
    
    
    



    



    
    
    
    
    
    
    
    





    
    
    
    
    



    
    
		 
    
    
    
    
    



    
    
    
    



    
    
    


	















    
    
    





			      


    
	
	
	
    



    
    
    



    
    
    
    
    
    
    
    



    
    
    
    
    
    
    
    
    












































			

			  

































    
    
    



    
    
    
    
    
    
    



    
    
	
    








		       



		   






















		       
















































    







































#line 19 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 2
#line 1 "graphviz-2.38.0\\lib\\expr\\expr.h" 1
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
 * AT&T Research
 *
 * expression library definitions
 */















































































































	
	




	
	
	
	
	
	
	
	
	
	




	
	
	




	
	





	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
	
	
	
	
	


	






	
	
	
	
	
	
	
					
	
					
	
					
	
					
	
					
	
					
	
	
					
	
					
	
					
	
	
	
	
	




	
	
	
	
	


	









	
	
	
	
					




	
	


	
















































#line 20 "graphviz-2.38.0\\lib\\gvpr\\actions.h" 2

    extern void nodeInduce(Agraph_t * selected);
    extern Agobj_t *clone(Agraph_t * g, Agobj_t * obj);
    extern Agraph_t *cloneG(Agraph_t * g, char* name);
    extern Agobj_t *copy(Agraph_t * g, Agobj_t * obj);
    extern int copyAttr(Agobj_t * obj, Agobj_t * obj1);
    extern int indexOf(char *s1, char *s2);
    extern int rindexOf(char *s1, char *s2);
    extern int match(char *str, char *pat);
    extern int lockGraph(Agraph_t * g, int);
    extern Agraph_t *compOf(Agraph_t * g, Agnode_t * n);
    extern Agedge_t *isEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key);
    extern Agnode_t *addNode(Agraph_t * g, Agnode_t * n, int doAdd);
    extern Agedge_t *addEdge(Agraph_t * g, Agedge_t * e, int doAdd);
    extern Agraph_t *sameG(void *p1, void *p2, char *fn, char *msg);
    extern int compare(Agobj_t *, Agobj_t *);
    extern int sfioWrite(Agraph_t *, Sfio_t*, Agiodisc_t*);
    extern int writeFile(Agraph_t *, char *, Agiodisc_t*);
    extern int fwriteFile(Expr_t *, Agraph_t *, int, Agiodisc_t*);
    extern Agraph_t *readFile(char *);
    extern Agraph_t *freadFile(Expr_t *, int);
    extern int openFile(Expr_t *, char *, char *);
    extern int closeFile(Expr_t *, int);
    extern char *readLine(Expr_t *, int);
    extern char *canon(Expr_t * pgm, char *);
    extern char *toHtml(Agraph_t*, char *);
    extern char *toLower(Expr_t * pgm, char *, Sfio_t*);
    extern char *toUpper(Expr_t * pgm, char *, Sfio_t*);
    extern int deleteObj(Agraph_t * g, Agobj_t * obj);
    extern char *colorx (Expr_t* ex, char* incolor, char* fmt, Sfio_t* fp);
    extern void gvstart_timer(void);
    extern double gvelapsed_sec(void);






#line 27 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2
#line 1 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 1
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
 * macro interface for sfio write strings
 *
 * NOTE: see <stak.h> for an alternative interface
 *	 read operations require sfseek()
 */




#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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





























































































	

    
    
	
    
	
    
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	

	 

    


    
    
    
	
    
	
	
	

	
	

	
	
	
	
	
	

	
	

	
    




















































    
    






























    
    

























     





    
    
    
    
    
    















    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    


    
    
	
    
    


    
    
    

    
    
    
    
    

    
    
    
    
    

    
    
    
    
    

    

    
    
    


    
    
    
    
    
    
    
    


     





































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 26 "graphviz-2.38.0\\lib\\ast\\sfstr.h" 2

























    extern int sfstrtmp(Sfio_t *, int, void *, size_t);








#line 28 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2
#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1





#line 1 "graphviz-2.38.0\\lib\\gvpr\\gdefs.h" 1



/* generated by mkdefs; do not edit */
























































































































































static Exid_t symbols[] = {
	{{0},(283),(1),(28),0,(0),0,{0},0,"$"},
	{{0},(283),(2),(27),0,(0),0,{0},0,"$G"},
	{{0},(283),(3),(27),0,(0),0,{0},0,"$NG"},
	{{0},(283),(4),(27),0,(0),0,{0},0,"$T"},
	{{0},(283),(5),(27),0,(0),0,{0},0,"$O"},
	{{0},(283),(6),(263),0,(0),0,{0},0,"$tgtname"},
	{{0},(283),(7),(263),0,(0),0,{0},0,"$F"},
	{{0},(283),(8),(25),0,(0),0,{0},0,"$tvroot"},
	{{0},(283),(9),(25),0,(0),0,{0},0,"$tvnext"},
	{{0},(283),(10),(26),0,(0),0,{0},0,"$tvedge"},
	{{0},(283),(11),(29),0,(0),0,{0},0,"$tvtype"},
	{{0},(283),(12),(259),0,(0),0,{0},0,"ARGC"},
	{{0},(283),(13),(259),0,(0),0,{0},0,"degree"},
	{{0},(283),(14),(25),0,(0),0,{0},0,"head"},
	{{0},(283),(15),(25),0,(0),0,{0},0,"tail"},
	{{0},(283),(16),(263),0,(0),0,{0},0,"name"},
	{{0},(283),(17),(259),0,(0),0,{0},0,"indegree"},
	{{0},(283),(18),(259),0,(0),0,{0},0,"outdegree"},
	{{0},(283),(19),(27),0,(0),0,{0},0,"root"},
	{{0},(283),(20),(27),0,(0),0,{0},0,"parent"},
	{{0},(283),(21),(259),0,(0),0,{0},0,"n_edges"},
	{{0},(283),(22),(259),0,(0),0,{0},0,"n_nodes"},
	{{0},(283),(23),(259),0,(0),0,{0},0,"directed"},
	{{0},(283),(24),(259),0,(0),0,{0},0,"strict"},
	{{0},(273),(25),(25),0,(0),0,{0},0,"node_t"},
	{{0},(273),(26),(26),0,(0),0,{0},0,"edge_t"},
	{{0},(273),(27),(27),0,(0),0,{0},0,"graph_t"},
	{{0},(273),(28),(28),0,(0),0,{0},0,"obj_t"},
	{{0},(273),(29),(29),0,(0),0,{0},0,"tvtype_t"},
	{{0},(267),(30),(03|((02)<<((1)*4))),0,(0),0,{0},0,"ARGV"},
	{{0},(279),(31),(0x6|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"graph"},
	{{0},(279),(32),(0x6|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"subg"},
	{{0},(279),(33),(0x6|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"isSubg"},
	{{0},(279),(34),(0x6|((0x6)<<((1)*4))),0,(0),0,{0},0,"fstsubg"},
	{{0},(279),(35),(0x6|((0x6)<<((1)*4))),0,(0),0,{0},0,"nxtsubg"},
	{{0},(279),(36),(0x4|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"node"},
	{{0},(279),(37),(0x4|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"subnode"},
	{{0},(279),(38),(0x4|((0x6)<<((1)*4))),0,(0),0,{0},0,"fstnode"},
	{{0},(279),(39),(0x4|((0x4)<<((1)*4))),0,(0),0,{0},0,"nxtnode"},
	{{0},(279),(40),(0x4|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"nxtnode_sg"},
	{{0},(279),(41),(0x4|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"isNode"},
	{{0},(279),(42),(02|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"isSubnode"},
	{{0},(279),(43),(02|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"indegreeOf"},
	{{0},(279),(44),(02|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"outdegreeOf"},
	{{0},(279),(45),(02|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"degreeOf"},
	{{0},(279),(46),(02|((0x6)<<((1)*4))|((0x7)<<((2)*4))),0,(0),0,{0},0,"isIn"},
	{{0},(279),(47),(0x5|((0x4)<<((1)*4))|((0x4)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"edge"},
	{{0},(279),(48),(0x5|((0x6)<<((1)*4))|((0x4)<<((2)*4))|((0x4)<<((3)*4))|((03)<<((4)*4))),0,(0),0,{0},0,"edge_sg"},
	{{0},(279),(49),(0x5|((0x6)<<((1)*4))|((0x5)<<((2)*4))),0,(0),0,{0},0,"subedge"},
	{{0},(279),(50),(0x4|((0x5)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"opp"},
	{{0},(279),(51),(0x5|((0x4)<<((1)*4))),0,(0),0,{0},0,"fstout"},
	{{0},(279),(52),(0x5|((0x5)<<((1)*4))),0,(0),0,{0},0,"nxtout"},
	{{0},(279),(53),(0x5|((0x4)<<((1)*4))),0,(0),0,{0},0,"fstin"},
	{{0},(279),(54),(0x5|((0x5)<<((1)*4))),0,(0),0,{0},0,"nxtin"},
	{{0},(279),(55),(0x5|((0x4)<<((1)*4))),0,(0),0,{0},0,"fstedge"},
	{{0},(279),(56),(0x5|((0x5)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"nxtedge"},
	{{0},(279),(57),(0x5|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"fstout_sg"},
	{{0},(279),(58),(0x5|((0x6)<<((1)*4))|((0x5)<<((2)*4))),0,(0),0,{0},0,"nxtout_sg"},
	{{0},(279),(59),(0x5|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"fstin_sg"},
	{{0},(279),(60),(0x5|((0x6)<<((1)*4))|((0x5)<<((2)*4))),0,(0),0,{0},0,"nxtin_sg"},
	{{0},(279),(61),(0x5|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"fstedge_sg"},
	{{0},(279),(62),(0x5|((0x6)<<((1)*4))|((0x5)<<((2)*4))|((0x4)<<((3)*4))),0,(0),0,{0},0,"nxtedge_sg"},
	{{0},(279),(63),(0x6|((0x6)<<((1)*4))|((0x4)<<((2)*4))),0,(0),0,{0},0,"compOf"},
	{{0},(279),(64),(03|((0x7)<<((1)*4))),0,(0),0,{0},0,"kindOf"},
	{{0},(279),(65),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"index"},
	{{0},(279),(66),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"rindex"},
	{{0},(279),(67),(0x5|((0x4)<<((1)*4))|((0x4)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"isEdge"},
	{{0},(279),(68),(0x5|((0x6)<<((1)*4))|((0x4)<<((2)*4))|((0x4)<<((3)*4))|((03)<<((4)*4))),0,(0),0,{0},0,"isEdge_sg"},
	{{0},(279),(69),(02|((0x6)<<((1)*4))|((0x5)<<((2)*4))),0,(0),0,{0},0,"isSubedge"},
	{{0},(279),(70),(02|((03)<<((1)*4))),0,(0),0,{0},0,"length"},
	{{0},(279),(71),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"match"},
	{{0},(279),(72),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"write"},
	{{0},(279),(73),(02|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"writeG"},
	{{0},(279),(74),(0x6|((03)<<((1)*4))),0,(0),0,{0},0,"readG"},
	{{0},(279),(75),(02|((0x6)<<((1)*4))|((02)<<((2)*4))),0,(0),0,{0},0,"fwriteG"},
	{{0},(279),(76),(0x6|((02)<<((1)*4))),0,(0),0,{0},0,"freadG"},
	{{0},(279),(77),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"openF"},
	{{0},(279),(78),(02|((02)<<((1)*4))),0,(0),0,{0},0,"closeF"},
	{{0},(279),(79),(03|((02)<<((1)*4))),0,(0),0,{0},0,"readL"},
	{{0},(279),(80),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"induce"},
	{{0},(279),(81),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"isDirect"},
	{{0},(279),(82),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"isStrict"},
	{{0},(279),(83),(02|((0x6)<<((1)*4))|((0x7)<<((2)*4))),0,(0),0,{0},0,"delete"},
	{{0},(279),(84),(0x7|((0x6)<<((1)*4))|((0x7)<<((2)*4))),0,(0),0,{0},0,"clone"},
	{{0},(279),(85),(0x6|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"cloneG"},
	{{0},(279),(86),(0x7|((0x6)<<((1)*4))|((0x7)<<((2)*4))),0,(0),0,{0},0,"copy"},
	{{0},(279),(87),(02|((0x7)<<((1)*4))|((0x7)<<((2)*4))),0,(0),0,{0},0,"copyA"},
	{{0},(279),(88),(02|((0x6)<<((1)*4))|((02)<<((2)*4))),0,(0),0,{0},0,"lock"},
	{{0},(279),(89),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"nNodes"},
	{{0},(279),(90),(02|((0x6)<<((1)*4))),0,(0),0,{0},0,"nEdges"},
	{{0},(279),(91),(01|((01)<<((1)*4))),0,(0),0,{0},0,"sqrt"},
	{{0},(279),(92),(01|((01)<<((1)*4))),0,(0),0,{0},0,"cos"},
	{{0},(279),(93),(01|((01)<<((1)*4))),0,(0),0,{0},0,"sin"},
	{{0},(279),(94),(01|((01)<<((1)*4))|((01)<<((2)*4))),0,(0),0,{0},0,"atan2"},
	{{0},(279),(95),(01|((01)<<((1)*4))),0,(0),0,{0},0,"exp"},
	{{0},(279),(96),(01|((01)<<((1)*4))|((01)<<((2)*4))),0,(0),0,{0},0,"pow"},
	{{0},(279),(97),(01|((01)<<((1)*4))),0,(0),0,{0},0,"log"},
	{{0},(279),(98),(01|((01)<<((1)*4))|((01)<<((2)*4))),0,(0),0,{0},0,"MIN"},
	{{0},(279),(99),(01|((01)<<((1)*4))|((01)<<((2)*4))),0,(0),0,{0},0,"MAX"},
	{{0},(279),(100),(02|((03)<<((1)*4))),0,(0),0,{0},0,"system"},
	{{0},(279),(101),(03|((03)<<((1)*4))),0,(0),0,{0},0,"xOf"},
	{{0},(279),(102),(03|((03)<<((1)*4))),0,(0),0,{0},0,"yOf"},
	{{0},(279),(103),(03|((03)<<((1)*4))),0,(0),0,{0},0,"llOf"},
	{{0},(279),(104),(03|((03)<<((1)*4))),0,(0),0,{0},0,"urOf"},
	{{0},(279),(105),(03|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"html"},
	{{0},(279),(106),(02|((03)<<((1)*4))),0,(0),0,{0},0,"ishtml"},
	{{0},(279),(107),(03|((03)<<((1)*4))),0,(0),0,{0},0,"canon"},
	{{0},(279),(108),(03|((0x7)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"aget"},
	{{0},(279),(109),(02|((0x7)<<((1)*4))|((03)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"aset"},
	{{0},(279),(110),(03|((0x6)<<((1)*4))|((03)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"getDflt"},
	{{0},(279),(111),(02|((0x6)<<((1)*4))|((03)<<((2)*4))|((03)<<((3)*4))|((03)<<((4)*4))),0,(0),0,{0},0,"setDflt"},
	{{0},(279),(112),(02|((0x7)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"hasAttr"},
	{{0},(279),(113),(02|((0x6)<<((1)*4))|((03)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"isAttr"},
	{{0},(279),(114),(03|((0x6)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"fstAttr"},
	{{0},(279),(115),(03|((0x6)<<((1)*4))|((03)<<((2)*4))|((03)<<((3)*4))),0,(0),0,{0},0,"nxtAttr"},
	{{0},(279),(116),(03|((03)<<((1)*4))),0,(0),0,{0},0,"tolower"},
	{{0},(279),(117),(03|((03)<<((1)*4))),0,(0),0,{0},0,"toupper"},
	{{0},(279),(118),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"strcmp"},
	{{0},(279),(119),(02|((03)<<((1)*4))),0,(0),0,{0},0,"atoi"},
	{{0},(279),(120),(01|((03)<<((1)*4))),0,(0),0,{0},0,"atof"},
	{{0},(279),(121),(03|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"colorx"},
	{{0},(279),(122),(02|((03)<<((1)*4))|((03)<<((2)*4))),0,(0),0,{0},0,"call"},
	{{0},(271),(123),(29),0,(0),0,{0},0,"TV_flat"},
	{{0},(271),(124),(29),0,(0),0,{0},0,"TV_ne"},
	{{0},(271),(125),(29),0,(0),0,{0},0,"TV_en"},
	{{0},(271),(126),(29),0,(0),0,{0},0,"TV_bfs"},
	{{0},(271),(127),(29),0,(0),0,{0},0,"TV_dfs"},
	{{0},(271),(128),(29),0,(0),0,{0},0,"TV_fwd"},
	{{0},(271),(129),(29),0,(0),0,{0},0,"TV_rev"},
	{{0},(271),(130),(29),0,(0),0,{0},0,"TV_postdfs"},
	{{0},(271),(131),(29),0,(0),0,{0},0,"TV_postfwd"},
	{{0},(271),(132),(29),0,(0),0,{0},0,"TV_postrev"},
	{{0},(271),(133),(29),0,(0),0,{0},0,"TV_prepostdfs"},
	{{0},(271),(134),(29),0,(0),0,{0},0,"TV_prepostfwd"},
	{{0},(271),(135),(29),0,(0),0,{0},0,"TV_prepostrev"},
	{{0},(271),(136),(28),0,(0),0,{0},0,"NULL"},
	{{0},(0),(0),(0),0,(0),0,{0},0,{0}}
};

static char* typenames[] = {
	"node_t",
	"edge_t",
	"graph_t",
	"obj_t",
	"tvtype_t",
};



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



typedef unsigned short tctype;

static tctype tchk[][2] = {
	{ 0, 0 },
	{ 0, ((1<<(0x4))|(1<<(0x5))|(1<<(0x6))) },
	{ 0, (1<<(0x6)) },
	{ 0, (1<<(0x6)) },
	{ 0, (1<<(0x6)) },
	{ 0, (1<<(0x6)) },
	{ 0, (1<<(03)) },
	{ 0, (1<<(03)) },
	{ 0, (1<<(0x4)) },
	{ 0, (1<<(0x4)) },
	{ 0, (1<<(0x5)) },
	{ 0, (1<<(0x8)) },
	{ 0, (1<<(02)) },
	{ (1<<(0x4)), (1<<(02)) },
	{ (1<<(0x5)), (1<<(0x4)) },
	{ (1<<(0x5)), (1<<(0x4)) },
	{ ((1<<(0x4))|(1<<(0x5))|(1<<(0x6))), (1<<(03)) },
	{ (1<<(0x4)), (1<<(02)) },
	{ (1<<(0x4)), (1<<(02)) },
	{ ((1<<(0x4))|(1<<(0x5))|(1<<(0x6))), (1<<(0x6)) },
	{ (1<<(0x6)), (1<<(0x6)) },
	{ (1<<(0x6)), (1<<(02)) },
	{ (1<<(0x6)), (1<<(02)) },
	{ (1<<(0x6)), (1<<(02)) },
	{ (1<<(0x6)), (1<<(02)) },
};


#line 37 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2

#line 1 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 1
#line 1 "graphviz-2.38.0\\lib\\gvpr\\trie.c" 1


#line 1 "graphviz-2.38.0\\lib\\gvpr\\trieFA.h" 1
/* File - trieFA.h
 *
 *    This file contains code to be included in the scanner file using a
 * generated trie-based FA.
 */

typedef struct {				/* An entry in the FA state table			*/
	short			def;		/* 	If this state is an accepting state then*/
								/*	this is the definition, otherwise -1.	*/
	short			trans_base;	/* The base index into the transition table.*/
	long			mask;		/* The transition mask. 					*/
}TrieState ;

typedef struct {				/* An entry in the FA transition table.		*/
	short			c;				/* The transition character (lowercase).*/
	short			next_state;		/* The next state.						*/
}TrieTrans ;


static long CharMask[28] = {
	0x0000001,	0x0000000,	0x0000004,	0x0000008,	
	0x0000010,	0x0000020,	0x0000040,	0x0000080,
	0x0000100,	0x0000200,	0x0000400,	0x0000800,
	0x0001000,	0x0002000,	0x0004000,	0x0008000,
	0x0010000,	0x0020000,	0x0040000,	0x0080000,
	0x0100000,	0x0200000,	0x0400000,	0x0800000,
	0x1000000,	0x2000000,  0x4000000,  0x8000000,
};






	
	
	
	
	
	
	







static short		TFA_State;

/* TFA_Init:
 *
 *    Initialize the trie FA.
 */


/* TFA_Advance:
 *
 *    Advance to the next state (or -1) on the lowercase letter c. 
 */





















/* TFA_Definition:
 *
 *    Return the definition (if any) associated with the current state.
 */


#line 4 "graphviz-2.38.0\\lib\\gvpr\\trie.c" 2

TrieState           TrieStateTbl[70] = {
    { -1, 0, 0x3b8620 },
    { -1, 9, 0x440 },
    { -1, 11, 0x100 },
    { -1, 12, 0x80000 },
    { -1, 13, 0x40 },
    { -1, 14, 0x40 },
    { (1<<(0x4)), 15, 0x0 },
    { -1, 15, 0x80000 },
    { -1, 16, 0x40 },
    { -1, 17, 0x10 },
    { -1, 18, 0x200000 },
    { -1, 19, 0x40 },
    { -1, 20, 0x20 },
    { (1<<(0x6)), 21, 0x0 },
    { -1, 21, 0x40 },
    { -1, 22, 0x4 },
    { -1, 23, 0x20 },
    { (1<<(0x5)), 24, 0x0 },
    { -1, 24, 0x8000 },
    { -1, 25, 0x20 },
    { -1, 26, 0x40 },
    { -1, 27, 0x100 },
    { -1, 28, 0x80000 },
    { -1, 29, 0x40 },
    { -1, 30, 0x40 },
    { (1<<(0x4)), 31, 0x0 },
    { -1, 31, 0x5 },
    { -1, 33, 0x8040 },
    { -1, 35, 0x20 },
    { -1, 36, 0x100 },
    { -1, 37, 0x40 },
    { -1, 38, 0x100000 },
    { (1<<(0x6)), 39, 0x0 },
    { -1, 39, 0x10000 },
    { -1, 40, 0x20 },
    { -1, 41, 0x40 },
    { -1, 42, 0x100000 },
    { (1<<(0x6)), 43, 0x0 },
    { -1, 43, 0x4000 },
    { -1, 44, 0x40 },
    { ((1<<(0x4))|(1<<(0x5))|(1<<(0x6))), 45, 0x0 },
    { -1, 45, 0x400000 },
    { -1, 46, 0x200000 },
    { -1, 47, 0x20 },
    { -1, 48, 0x40 },
    { -1, 49, 0x100 },
    { -1, 50, 0x80000 },
    { -1, 51, 0x40 },
    { -1, 52, 0x40 },
    { (1<<(0x4)), 53, 0x0 },
    { -1, 53, 0x4 },
    { -1, 54, 0x80000 },
    { -1, 55, 0x40 },
    { -1, 56, 0x8000 },
    { -1, 57, 0x200000 },
    { (1<<(0x6)), 58, 0x0 },
    { -1, 58, 0x10000 },
    { -1, 59, 0x10000 },
    { -1, 60, 0x200000 },
    { ((1<<(0x4))|(1<<(0x5))|(1<<(0x6))), 61, 0x0 },
    { -1, 61, 0x200000 },
    { -1, 62, 0x80000 },
    { -1, 63, 0x400 },
    { -1, 64, 0x10 },
    { -1, 65, 0x200000 },
    { (1<<(0x6)), 66, 0x0 },
    { -1, 66, 0x4 },
    { -1, 67, 0x400 },
    { -1, 68, 0x2000 },
    { (1<<(0x5)), 69, 0x0 },
};
TrieTrans           TrieTransTbl[69] = {
    /* State   0 */  { 'd',   1 }, { 'h',  14 }, { 'i',  18 }, { 'n',  26 }, { 'o',  41 }, { 'p',  50 }, { 'r',  56 }, { 's',  60 }, { 't',  66 },
    /* State   1 */  { 'e',   2 }, { 'i',   7 },
    /* State   2 */  { 'g',   3 },
    /* State   3 */  { 'r',   4 },
    /* State   4 */  { 'e',   5 },
    /* State   5 */  { 'e',   6 },
    /* State   7 */  { 'r',   8 },
    /* State   8 */  { 'e',   9 },
    /* State   9 */  { 'c',  10 },
    /* State  10 */  { 't',  11 },
    /* State  11 */  { 'e',  12 },
    /* State  12 */  { 'd',  13 },
    /* State  14 */  { 'e',  15 },
    /* State  15 */  { 'a',  16 },
    /* State  16 */  { 'd',  17 },
    /* State  18 */  { 'n',  19 },
    /* State  19 */  { 'd',  20 },
    /* State  20 */  { 'e',  21 },
    /* State  21 */  { 'g',  22 },
    /* State  22 */  { 'r',  23 },
    /* State  23 */  { 'e',  24 },
    /* State  24 */  { 'e',  25 },
    /* State  26 */  { '_',  27 }, { 'a',  38 },
    /* State  27 */  { 'e',  28 }, { 'n',  33 },
    /* State  28 */  { 'd',  29 },
    /* State  29 */  { 'g',  30 },
    /* State  30 */  { 'e',  31 },
    /* State  31 */  { 's',  32 },
    /* State  33 */  { 'o',  34 },
    /* State  34 */  { 'd',  35 },
    /* State  35 */  { 'e',  36 },
    /* State  36 */  { 's',  37 },
    /* State  38 */  { 'm',  39 },
    /* State  39 */  { 'e',  40 },
    /* State  41 */  { 'u',  42 },
    /* State  42 */  { 't',  43 },
    /* State  43 */  { 'd',  44 },
    /* State  44 */  { 'e',  45 },
    /* State  45 */  { 'g',  46 },
    /* State  46 */  { 'r',  47 },
    /* State  47 */  { 'e',  48 },
    /* State  48 */  { 'e',  49 },
    /* State  50 */  { 'a',  51 },
    /* State  51 */  { 'r',  52 },
    /* State  52 */  { 'e',  53 },
    /* State  53 */  { 'n',  54 },
    /* State  54 */  { 't',  55 },
    /* State  56 */  { 'o',  57 },
    /* State  57 */  { 'o',  58 },
    /* State  58 */  { 't',  59 },
    /* State  60 */  { 't',  61 },
    /* State  61 */  { 'r',  62 },
    /* State  62 */  { 'i',  63 },
    /* State  63 */  { 'c',  64 },
    /* State  64 */  { 't',  65 },
    /* State  66 */  { 'a',  67 },
    /* State  67 */  { 'i',  68 },
    /* State  68 */  { 'l',  69 },
};
#line 40 "graphviz-2.38.0\\lib\\gvpr\\compile.c" 2










static int iofread(void *chan, char *buf, int bufsize)
{
    return read(( (((Sfio_t *) chan) ? ((Sfio_t*)((Sfio_t *) chan))->file : -1) ), buf, bufsize);
}

static int ioputstr(void *chan, const char *str)
{
    return sfputr((Sfio_t *) chan, str, -1);
}

static int ioflush(void *chan)
{
    return sfsync((Sfio_t *) chan);
}

static Agiodisc_t gprIoDisc = { iofread, ioputstr, ioflush };




static Agdisc_t gprDisc = { &AgMemDisc, &AgIdDisc, &gprIoDisc };


/* nameOf:
 * Return name of object. 
 * Assumes obj !=  NULL
 */
static char *nameOf(Expr_t * ex, Agobj_t * obj, Sfio_t* tmps)
{
    char *s;
    char *key;
    Agedge_t *e;

    switch (((((Agobj_t*)(obj))->tag).objtype)) {
    case 1:
    case 0:
	s = agnameof(obj);
	break;
    default:			/* edge */
	e = (Agedge_t *) obj;
	key = agnameof((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1)));
	sfputr(tmps, agnameof(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)), -1);
	if (agisdirected(agraphof(e)))
	    sfputr(tmps, "->", -1);
	else
	    sfputr(tmps, "--", -1);
	sfputr(tmps, agnameof(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)), -1);
	if (key && *key) {
	    ( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)(('[')))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)(('['))) ) );
	    sfputr(tmps, key, -1);
	    ( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((']')))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((']'))) ) );
	}
	s = exstring(ex, (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ));
	break;
    }
    return s;
}

/* bbOf:
 * If string as form "x,y,u,v" where is all are numeric,
 * return "x,y" or "u,v", depending on getll, else return ""
 */
static char *bbOf(Expr_t * pgm, char *pt, int getll)
{
    double x, y, u, v;
    char *s;
    char *p;
    int len;

    if (sscanf(pt, "%lf,%lf,%lf,%lf", &x, &y, &u, &v) == 4) {
	p = strchr(pt, ',');
	p = strchr(p + 1, ',');
	if (getll) {
	    len = p - pt;
	    s = exstralloc(pgm, 0, len + 1);
	    strncpy(s, pt, len);
	    s[len] = '\0';
	} else
	    s = exstring(pgm, p + 1);
    } else
	s = "";
    return s;
}

/* xyOf:
 * If string as form "x,y" where is x and y are numeric,
 * return "x" or "y", depending on getx, else return ""
 */
static char *xyOf(Expr_t * pgm, char *pt, int getx)
{
    double x, y;
    char *v;
    char *p;
    int len;

    if (sscanf(pt, "%lf,%lf", &x, &y) == 2) {
	p = strchr(pt, ',');
	if (getx) {
	    len = p - pt;
	    v = exstralloc(pgm, 0, len + 1);
	    strncpy(v, pt, len);
	    v[len] = '\0';
	} else
	    v = exstring(pgm, p + 1);
    } else
	v = "";
    return v;
}




    
	
    
	
	

	
	
	
	
    



/* xargs:
 * Convert string argument to graph to type of graph desired.
 *   u => undirected
 *   d => directed
 *   s => strict
 *   n => non-strict
 * Case-insensitive
 * By default, the graph is directed, non-strict.
 */
static Agdesc_t xargs(char *args)
{
    Agdesc_t desc = Agdirected;
    char c;

    while ((c = *args++)) {
	switch (c) {
	case 'u':
	case 'U':
	    desc.directed = 0;
	    break;
	case 'd':
	case 'D':
	    desc.directed = 1;
	    break;
	case 's':
	case 'S':
	    desc.strict = 1;
	    break;
	case 'n':
	case 'N':
	    desc.directed = 0;
	    break;
	default:
	    _err_msg(1, "unknown graph descriptor '%c' : ignored",
		  c);
	    break;
	}
    }
    return desc;
}

/* deparse:
 * Recreate string representation of expression involving
 * a reference and a symbol.
 * The parameter sf must be a string stream.
 */
static char *deparse(Expr_t * ex, Exnode_t * n, Sfio_t * sf)
{
    exdump(ex, n, sf);
    return ((( (((Sfio_t*)((sf)))->next >= ((Sfio_t*)((sf)))->endw ? _sfflsbuf(((Sfio_t*)((sf))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((sf)))->next++ = (unsigned char)((0))) ) ), (char*)((sf)->next = (sf)->data) ));
}

/* deref:
 * Evaluate reference to derive desired graph object.
 * A reference is either DI* or II*
 * The parameter objp is the current object.
 * Assume ref is type-correct.
 */
static Agobj_t *deref(Expr_t * pgm, Exnode_t * x, Exref_t * ref,
		      Agobj_t * objp, Gpr_t * state)
{
    void *ptr;

    if (ref == 0)
	return objp;
    else if (ref->symbol->lex == 275) {
	ptr =
	    ((void *)(
 x->data.variable.dyna->data.variable.dyna->data.
 constant.value.integer));
	if (!ptr) {
	    exerror("null reference %s in expression %s.%s",
		  ref->symbol->name, ref->symbol->name, deparse(pgm, x,
								state->tmp));
	    return ptr;
	} else
	    return deref(pgm, x, ref->next, (Agobj_t *) ptr, state);
    } else
	switch (ref->symbol->index) {	/* sym->lex == ID */
	case 5:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->outgraph,
			 state);
	    break;
	case 1:
	    return deref(pgm, x, ref->next, state->curobj, state);
	    break;
	case 2:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->curgraph,
			 state);
	    break;
	case 3:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->nextgraph,
			 state);
	    break;
	case 4:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->target,
			 state);
	    break;
	case 10:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->tvedge,
			 state);
	    break;
	case 8:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->tvroot,
			 state);
	    break;
	case 9:
	    return deref(pgm, x, ref->next, (Agobj_t *) state->tvnext,
			 state);
	    break;
	case 14:
	    if (!objp && !(objp = state->curobj)) {
		exerror("Current object $ not defined");
		return 0;
	    }
	    if ((((((Agobj_t*)(objp))->tag).objtype)&2))
		return deref(pgm, x, ref->next,
			     (Agobj_t *) ((((((Agobj_t*)((Agedge_t *) objp))->tag).objtype) == 2? ((Agedge_t *) objp): (((Agedge_t *) objp)-1))->node), state);
	    else
		exerror("head of non-edge");
	    break;
	case 15:
	    if (!objp && !(objp = state->curobj)) {
		exerror("Current object $ not defined");
		return 0;
	    }
	    if ((((((Agobj_t*)(objp))->tag).objtype)&2))
		return deref(pgm, x, ref->next,
			     (Agobj_t *) ((((((Agobj_t*)((Agedge_t *) objp))->tag).objtype) == 3? ((Agedge_t *) objp): (((Agedge_t *) objp)+1))->node), state);
	    else
		exerror("tail of non-edge %x", objp);
	    break;
	default:
	    exerror("%s : illegal reference",
		  ref->symbol->name);
	    break;
	}
    return 0;

}

/* assignable:
 * Check that attribute is not a read-only, pseudo-attribute.
 * Return 1 if okay; fatal otherwise.
 */
static int
assignable (Agobj_t *objp, unsigned char* name)
{
    unsigned int ch;
    int rv;
    unsigned char* p = name;

    TFA_State = 0;
    while ((TFA_State >= 0) && (ch = *p)) {
        { char c = ch & ~127 ? 127 : ch; if (TFA_State >= 0) { if (isupper(c)) c = tolower(c); else if (! (islower(c) || ((c) == '_'))) { TFA_State = -1; goto TFA_done; } if (TrieStateTbl[TFA_State].mask & CharMask[((c) - '_')]) { short i = TrieStateTbl[TFA_State].trans_base; while (TrieTransTbl[i].c != c) i++; TFA_State = TrieTransTbl[i].next_state; } else TFA_State = -1; } TFA_done:; };
        p++;
    }
    rv = ((TFA_State < 0) ? -1 : TrieStateTbl[TFA_State].def);
    if (rv < 0) return 1;

    switch (((((Agobj_t*)(objp))->tag).objtype)) {
    case 0 :
	if (rv & (1<<(0x6)))
	    exerror("Cannot assign to pseudo-graph attribute %s", name);
	break;
    case 1 :
	if (rv & (1<<(0x4)))
	    exerror("Cannot assign to pseudo-node attribute %s", name);
	break;
    default :  /* edge */
	if (rv & (1<<(0x5)))
	    exerror("Cannot assign to pseudo-edge attribute %s", name);
	break;
    }
    return 1;
}

/* setattr:
 * Set object's attribute name to val.
 * Initialize attribute if necessary.
 */
static int
setattr (Agobj_t *objp, char* name, char* val)
{
    Agsym_t *gsym = agattrsym(objp, name);
    if (!gsym) {
	gsym = agattr(agroot(agraphof(objp)), ((((Agobj_t*)(objp))->tag).objtype), name, "");
    }
    return agxset(objp, gsym, val);
}

/* kindToStr:
 */
static char*
kindToStr (int kind)
{
    char* s;

    switch (kind) {
    case 0 :
	s = "graph";
	break;
    case 1 :
	s = "node";
	break;
    default :
	s = "edge";
	break;
    }
    return s;
}

/* kindOf:
 * Return string rep of object's kind
 */
static char*
kindOf (Agobj_t* objp)
{
    return (kindToStr (agobjkind (objp)));
}

/* lookup:
 * Apply symbol to get field value of objp
 * Assume objp != NULL
 */
static int lookup(Expr_t * pgm, Agobj_t * objp, Exid_t * sym, Extype_t * v,
  Gpr_t *state)
{
    if (sym->lex == 283) {
	switch (sym->index) {
	case 14:
	    if ((((((Agobj_t*)(objp))->tag).objtype)&2))
		v->integer = ((_ast_intmax_t)(((((((Agobj_t*)((Agedge_t *) objp))->tag).objtype) == 2? ((Agedge_t *) objp): (((Agedge_t *) objp)-1))->node)));
	    else {
		_err_msg(1, "head of non-edge");
		return -1;
	    }
	    break;
	case 15:
	    if ((((((Agobj_t*)(objp))->tag).objtype)&2))
		v->integer = ((_ast_intmax_t)(((((((Agobj_t*)((Agedge_t *) objp))->tag).objtype) == 3? ((Agedge_t *) objp): (((Agedge_t *) objp)+1))->node)));
	    else {
		_err_msg(1, "tail of non-edge");
		return -1;
	    }
	    break;
	case 16:
	    v->string = nameOf(pgm, objp, state->tmp);
	    break;
	case 17:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 1)
		v->integer = agdegree(agroot(objp), (Agnode_t *) objp, 1, 0);
	    else {
		exerror("indegree of non-node");
		return -1;
	    }
	    break;
	case 18:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 1)
		v->integer = agdegree(agroot(objp), (Agnode_t *) objp, 0, 1);
	    else {
		exerror("outdegree of non-node");
		return -1;
	    }
	    break;
	case 13:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 1)
		v->integer = agdegree(agroot(objp), (Agnode_t *) objp, 1, 1);
	    else {
		exerror("degree of non-node");
		return -1;
	    }
	    break;
	case 20:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 0)
		v->integer = ((_ast_intmax_t)(agparent((Agraph_t *) objp)));
	    else {
		exerror("parent of non-graph");
		return -1;
	    }
	    break;
	case 19:
	    v->integer = ((_ast_intmax_t)(agroot(agraphof(objp))));
	    break;
	case 21:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 0)
		v->integer = agnedges((Agraph_t *) objp);
	    else {
		exerror("n_edges of non-graph");
		return -1;
	    }
	    break;
	case 22:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 0)
		v->integer = agnnodes((Agraph_t *) objp);
	    else {
		exerror("n_nodes of non-graph");
		return -1;
	    }
	    break;
	case 23:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 0)
		v->integer = agisdirected((Agraph_t *) objp);
	    else {
		exerror("directed of non-graph");
		return -1;
	    }
	    break;
	case 24:
	    if (((((Agobj_t*)(objp))->tag).objtype) == 0)
		v->integer = agisstrict((Agraph_t *) objp);
	    else {
		exerror("strict of non-graph");
		return -1;
	    }
	    break;
	default:
	    _err_msg(1, "%s : illegal reference", sym->name);
	    return -1;
	    break;
	}
    } else {
	Agsym_t *gsym = agattrsym(objp, sym->name);
	if (!gsym) {
	    gsym = agattr(agroot(agraphof(objp)), ((((Agobj_t*)(objp))->tag).objtype), sym->name, "");
	    _err_msg(1, "Using value of uninitialized %s attribute \"%s\" of \"%s\"", kindOf (objp), sym->name, nameOf(pgm, objp, state->tmp));
	}
	v->string = agxget(objp, gsym);
    }

    return 0;
}

/* getArg:
 * Return value associated with $n.
 */
static char *getArg(int n, Gpr_t * state)
{
    if (n >= state->argc) {
	exerror("program references ARGV[%d] - undefined", n);
	return 0;
    }
    return (state->argv[n]);
}

/* setDfltAttr:
 */
static int
setDfltAttr (Agraph_t *gp, char* k, char* name, char* value)
{
    int kind;

    switch (*k) {
    case 'G' :
	kind = 0;
	break;
    case 'E' :
	kind = 2;
	break;
    case 'N' :
	kind = 1;
	break;
    default :
	_err_msg(1, "Unknown kind \"%s\" passed to setDflt()", k);
	return 1;
	break;
    }
    agattr(gp, kind, name, value);
    return 0;
}

/* toKind:
 * Map string to object kind
 */
static int
toKind (char* k, char* fn)
{
    int      kind;

    switch (*k) {
    case 'G' :
	kind = 0;
	break;
    case 'E' :
	kind = 2;
	break;
    case 'N' :
	kind = 1;
	break;
    default :
	exerror("Unknown kind \"%s\" passed to %s()", k, fn);
	kind = 0;
	break;
    }
    return kind;
}

/* nxtAttr:
 */
static char*
nxtAttr (Agraph_t *gp, char* k, char* name)
{
    char* fn = (name ? "nxtAttr" : "fstAttr");
    int kind = toKind (k, fn);
    Agsym_t* sym;

    if (name) {
	sym = agattr (gp, kind, name, 0);
	if (!sym) {
	    exerror("Third argument \"%s\" in nxtAttr() must be the name of an existing attribute", name); 
	    return "";
	}
	
    }
    else sym = 0;
    
    sym = agnxtattr (gp, kind, sym);
    if (sym) return sym->name; 
    else return "";
}

/* getDfltAttr:
 */
static char*
getDfltAttr (Agraph_t *gp, char* k, char* name)
{
    int kind = toKind (k, "getDflt");
    Agsym_t* sym = agattr (gp, kind, name, 0);
    if (!sym) {
	sym = agattr(gp, kind, name, "");
	_err_msg(1, "Uninitialized %s attribute \"%s\" in %s", 
	    kindToStr (kind), name, "getDflt");
    }
    return sym->defval; 
}

/* getval:
 * Return value associated with gpr identifier.
 */
static Extype_t
getval(Expr_t * pgm, Exnode_t * node, Exid_t * sym, Exref_t * ref,
       void *env, int elt, Exdisc_t * disc)
{
    Extype_t v;
    Gpr_t *state;
    Extype_t *args;
    Agobj_t *objp;
    Agobj_t *objp1;
    char *key;
    Agraph_t *gp;
    Agnode_t *np;
    Agnode_t *hp;
    Agedge_t *ep;
    char* name;
    gvprbinding* bp;

    assert(sym->lex != 271);
    if (elt == (-2)) {
	args = (Extype_t *) env;
	state = (Gpr_t *) (disc->user);
	switch (sym->index) {
	case 31:
	    gp = openG(args[0].string, xargs(args[1].string));
	    v.integer = ((_ast_intmax_t)(gp));
	    break;
	case 32:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		gp = openSubg(gp, args[1].string);
		v.integer = ((_ast_intmax_t)(gp));
	    } else {
		_err_msg(1, "NULL graph passed to subg()");
		v.integer = 0;
	    }
	    break;
	case 33:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		v.integer = ((_ast_intmax_t)(agsubg(gp, args[1].string, 0)));
	    } else {
		_err_msg(1, "NULL graph passed to isSubg()");
		v.integer = 0;
	    }
	    break;
	case 34:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		gp = agfstsubg(gp);
		v.integer = ((_ast_intmax_t)(gp));
	    } else {
		_err_msg(1, "NULL graph passed to fstsubg()");
		v.integer = 0;
	    }
	    break;
	case 35:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		gp = agnxtsubg(gp);
		v.integer = ((_ast_intmax_t)(gp));
	    } else {
		_err_msg(1, "NULL graph passed to nxtsubg()");
		v.integer = 0;
	    }
	    break;
	case 36:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		np = openNode(gp, args[1].string);
		v.integer = ((_ast_intmax_t)(np));
	    } else {
		_err_msg(1, "NULL graph passed to node()");
		v.integer = 0;
	    }
	    break;
	case 37:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to addNode()");
		v.integer = 0;
	    } else if (!np) {
		_err_msg(1, "NULL node passed to addNode()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(addNode(gp, np, 1)));
	    break;
	case 38:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		np = agfstnode(gp);
		v.integer = ((_ast_intmax_t)(np));
	    } else {
		_err_msg(1, "NULL graph passed to fstnode()");
		v.integer = 0;
	    }
	    break;
	case 39:
	    np = ((Agnode_t *)(args[0].integer));
	    if (np) {
		np = agnxtnode(agroot(np), np);
		v.integer = ((_ast_intmax_t)(np));
	    } else {
		_err_msg(1, "NULL node passed to nxtnode()");
		v.integer = 0;
	    }
	    break;
	case 40:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		np = agnxtnode(gp, np);
		v.integer = ((_ast_intmax_t)(np));
	    } else {
		_err_msg(1, "NULL node passed to nxtnode_sg()");
		v.integer = 0;
	    }
	    break;
	case 41:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		v.integer = ((_ast_intmax_t)(agnode(gp, args[1].string, 0)));
	    } else {
		_err_msg(1, "NULL graph passed to isNode()");
		v.integer = 0;
	    }
	    break;
	case 42:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		v.integer = ((_ast_intmax_t)(addNode(gp, np, 0)));
	    } else {
		_err_msg(1, "NULL node passed to isSubnode()");
		v.integer = 0;
	    }
	    break;
	case 43:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		v.integer = agdegree(gp, np, 1, 0);
	    } else {
		_err_msg(1, "NULL node passed to indegreeOf()");
		v.integer = 0;
	    }
	    break;
	case 44:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		v.integer = agdegree(gp, np, 0, 1);
	    } else {
		_err_msg(1, "NULL node passed to outdegreeOf()");
		v.integer = 0;
	    }
	    break;
	case 45:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		v.integer = agdegree(gp, np, 1, 1);
	    } else {
		_err_msg(1, "NULL node passed to degreeOf()");
		v.integer = 0;
	    }
	    break;
	case 46:
	    gp = ((Agraph_t *)(args[0].integer));
	    objp = ((Agobj_t *)(args[1].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to isIn()");
		v.integer = 0;
	    } else if (!objp) {
		_err_msg(1, "NULL object passed to isIn()");
		v.integer = 0;
	    } else
		v.integer = agcontains (gp, objp);
	    break;
	case 63:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to compOf()");
		v.integer = 0;
	    } else if (!np) {
		_err_msg(1, "NULL node passed to compOf()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(compOf(gp, np)));
	    break;
	case 64:
	    objp = ((Agobj_t *)(args[0].integer));
	    if (!objp) {
		exerror("NULL object passed to kindOf()");
		v.string = 0;
	    } else switch (((((Agobj_t*)(objp))->tag).objtype)) {
		case 0 :
		    v.string = "G";
		    break;
		case 1 :
		    v.string = "N";
		    break;
		case 3 :
		case 2 :
		    v.string = "E";
		    break;
	    }
	    break;
	case 47:
	    key = args[2].string;
	    if (*key == '\0')
		key = 0;
	    np = ((Agnode_t *)(args[0].integer));
	    hp = ((Agnode_t *)(args[1].integer));
	    if (!np) {
		_err_msg(1, "NULL tail node passed to edge()");
		v.integer = 0;
	    } else if (!hp) {
		_err_msg(1, "NULL head node passed to edge()");
		v.integer = 0;
	    } else {
		ep = openEdge(0, np, hp, key);
		v.integer = ((_ast_intmax_t)(ep));
	    }
	    break;
	case 48:
	    key = args[3].string;
	    if (*key == '\0')
		key = 0;
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    hp = ((Agnode_t *)(args[2].integer));
	    if (!np) {
		_err_msg(1, "NULL tail node passed to edge_sg()");
		v.integer = 0;
	    } else if (!hp) {
		_err_msg(1, "NULL head node passed to edge_sg()");
		v.integer = 0;
	    } else {
		ep = openEdge(gp, np, hp, key);
		v.integer = ((_ast_intmax_t)(ep));
	    }
	    break;
	case 49:
	    gp = ((Agraph_t *)(args[0].integer));
	    ep = ((Agedge_t *)(args[1].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to addEdge()");
		v.integer = 0;
	    } else if (!ep) {
		_err_msg(1, "NULL edge passed to addEdge()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(addEdge(gp, ep, 1)));
	    break;
	case 50:
	    ep = ((Agedge_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!ep) {
		_err_msg(1, "NULL edge passed to opp()");
		v.integer = 0;
	    } else if (!np) {
		_err_msg(1, "NULL node passed to opp()");
		v.integer = 0;
	    } else {
		if (((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node) == np)
		    np = ((((((Agobj_t*)(ep))->tag).objtype) == 3? (ep): ((ep)+1))->node);
		else
		    np = ((((((Agobj_t*)(ep))->tag).objtype) == 2? (ep): ((ep)-1))->node);
		v.integer = ((_ast_intmax_t)(np));
	    }
	    break;
	case 67:
	    key = args[2].string;
	    if (*key == '\0')
		key = 0;
	    np = ((Agnode_t *)(args[0].integer));
	    hp = ((Agnode_t *)(args[1].integer));
	    if (!np) {
		_err_msg(1, "NULL tail node passed to isEdge()");
		v.integer = 0;
	    } else if (!hp) {
		_err_msg(1, "NULL head node passed to isEdge()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(isEdge(agroot(np), np, hp, key)));
	    break;
	case 68:
	    key = args[3].string;
	    if (*key == '\0')
		key = 0;
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    hp = ((Agnode_t *)(args[2].integer));
	    if (!gp)
		gp = agroot(np);
	    if (!np) {
		_err_msg(1, "NULL tail node passed to isEdge_sg()");
		v.integer = 0;
	    } else if (!hp) {
		_err_msg(1, "NULL head node passed to isEdge_sg()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(isEdge(gp, np, hp, key)));
	    break;
	case 69:
	    gp = ((Agraph_t *)(args[0].integer));
	    ep = ((Agedge_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(ep);
	    if (ep) {
		v.integer = ((_ast_intmax_t)(addEdge(gp, ep, 0)));
	    } else {
		_err_msg(1, "NULL edge passed to isSubedge()");
		v.integer = 0;
	    }
	    break;
	case 51:
	    np = ((Agnode_t *)(args[0].integer));
	    if (np) {
		ep = agfstout(agroot(np), np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstout()");
		v.integer = 0;
	    }
	    break;
	case 57:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		ep = agfstout(gp, np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstout_sg()");
		v.integer = 0;
	    }
	    break;
	case 52:
	    ep = ((Agedge_t *)(args[0].integer));
	    if (ep) {
		ep = agnxtout(agroot(ep), ep);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL edge passed to nxtout()");
		v.integer = 0;
	    }
	    break;
	case 58:
	    gp = ((Agraph_t *)(args[0].integer));
	    ep = ((Agedge_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(ep);
	    if (ep) {
		ep = agnxtout(gp, ep);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL edge passed to nxtout_sg()");
		v.integer = 0;
	    }
	    break;
	case 53:
	    np = ((Agnode_t *)(args[0].integer));
	    if (np) {
		ep = agfstin(agroot(np), np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstin()");
		v.integer = 0;
	    }
	    break;
	case 59:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		ep = agfstin(gp, np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstin_sg()");
		v.integer = 0;
	    }
	    break;
	case 54:
	    ep = ((Agedge_t *)(args[0].integer));
	    if (ep) {
		ep = agnxtin(agroot(ep), ep);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL edge passed to nxtin()");
		v.integer = 0;
	    }
	    break;
	case 60:
	    gp = ((Agraph_t *)(args[0].integer));
	    ep = ((Agedge_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(ep);
	    if (ep) {
		ep = agnxtin(gp, ep);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL edge passed to nxtin_sg()");
		v.integer = 0;
	    }
	    break;
	case 55:
	    np = ((Agnode_t *)(args[0].integer));
	    if (np) {
		ep = agfstedge(agroot(np), np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstedge()");
		v.integer = 0;
	    }
	    break;
	case 61:
	    gp = ((Agraph_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!gp)
		gp = agroot(np);
	    if (np) {
		ep = agfstedge(gp, np);
		v.integer = ((_ast_intmax_t)(ep));
	    } else {
		_err_msg(1, "NULL node passed to fstedge_sg()");
		v.integer = 0;
	    }
	    break;
	case 56:
	    ep = ((Agedge_t *)(args[0].integer));
	    np = ((Agnode_t *)(args[1].integer));
	    if (!ep) {
		_err_msg(1, "NULL edge passed to nxtedge()");
		v.integer = 0;
	    } else if (!np) {
		_err_msg(1, "NULL node passed to nxtedge()");
		v.integer = 0;
	    } else {
		ep = agnxtedge(agroot(np), ep, np);
		v.integer = ((_ast_intmax_t)(ep));
	    }
	    break;
	case 62:
	    gp = ((Agraph_t *)(args[0].integer));
	    ep = ((Agedge_t *)(args[1].integer));
	    np = ((Agnode_t *)(args[2].integer));
	    if (!gp)
		gp = agroot(np);
	    if (!ep) {
		_err_msg(1, "NULL edge passed to nxtedge_sg()");
		v.integer = 0;
	    } else if (!np) {
		_err_msg(1, "NULL node passed to nxtedge_sg()");
		v.integer = 0;
	    } else {
		ep = agnxtedge(gp, ep, np);
		v.integer = ((_ast_intmax_t)(ep));
	    }
	    break;
	case 86:
	    gp = ((Agraph_t *)(args[0].integer));
	    objp = ((Agobj_t *)(args[1].integer));
	    if (!objp) {
		_err_msg(1, "NULL object passed to clone()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(copy(gp, objp)));
	    break;
	case 84:
	    gp = ((Agraph_t *)(args[0].integer));
	    objp = ((Agobj_t *)(args[1].integer));
	    if (!objp) {
		_err_msg(1, "NULL object passed to clone()");
		v.integer = 0;
	    } else
		v.integer = ((_ast_intmax_t)(clone(gp, objp)));
	    break;
	case 85:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		gp = cloneG(gp, args[1].string);
		v.integer = ((_ast_intmax_t)(gp));
	    } else {
		_err_msg(1, "NULL graph passed to cloneG()");
		v.integer = 0;
	    }
	    break;
	case 87:
	    objp = ((Agobj_t *)(args[0].integer));
	    objp1 = ((Agobj_t *)(args[1].integer));
	    if (!(objp && objp1)) {
		_err_msg(1, "NULL object passed to copyA()");
		v.integer = 0;
	    } else
		v.integer = copyAttr(objp, objp1);
	    break;
	case 80:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to induce()");
		v.integer = 1;
	    } else {
		nodeInduce(gp);
		v.integer = 0;
	    }
	    break;
	case 72:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to write()");
		v.integer = 1;
	    } else
		v.integer = sfioWrite (gp, state->outFile, state->dfltIO);
	    break;
	case 73:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to writeG()");
		v.integer = 1;
	    } else
		v.integer = writeFile(gp, args[1].string, state->dfltIO);
	    break;
	case 74:
	    gp = readFile(args[0].string);
	    v.integer = ((_ast_intmax_t)(gp));
	    break;
	case 75:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to fwriteG()");
		v.integer = 1;
	    } else
		v.integer = fwriteFile(pgm, gp, args[1].integer, state->dfltIO);
	    break;
	case 76:
	    gp = freadFile(pgm, args[0].integer);
	    v.integer = ((_ast_intmax_t)(gp));
	    break;
	case 77:
	    v.integer = openFile(pgm, args[0].string, args[1].string);
	    break;
	case 78:
	    v.integer = closeFile(pgm, args[0].integer);
	    break;
	case 79:
	    v.string = readLine(pgm, args[0].integer);
	    break;
	case 81:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to isDirect()");
		v.integer = 0;
	    } else {
		v.integer = agisdirected(gp);
	    }
	    break;
	case 82:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to isStrict()");
		v.integer = 0;
	    } else {
		v.integer = agisstrict(gp);
	    }
	    break;
	case 83:
	    gp = ((Agraph_t *)(args[0].integer));
	    objp = ((Agobj_t *)(args[1].integer));
	    if (!objp) {
		_err_msg(1, "NULL object passed to delete()");
		v.integer = 1;
	    } else if (objp == (Agobj_t *) (state->curgraph)) {
		_err_msg(1, "cannot delete current graph $G");
		v.integer = 1;
	    } else if (objp == (Agobj_t *) (state->target)) {
		_err_msg(1, "cannot delete target graph $T");
		v.integer = 1;
	    } else if (objp == state->curobj) {
		if (!(v.integer = deleteObj(gp, objp)))
		    state->curobj = 0;
	    } else
		v.integer = deleteObj(gp, objp);
	    break;
	case 88:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to lock()");
		v.integer = -1;
	    } else
		v.integer = lockGraph(gp, args[1].integer);
	    break;
	case 89:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to nNodes()");
		v.integer = 0;
	    } else {
		v.integer = agnnodes(gp);
	    }
	    break;
	case 90:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (!gp) {
		_err_msg(1, "NULL graph passed to nEdges()");
		v.integer = 0;
	    } else {
		v.integer = agnedges(gp);
	    }
	    break;
	case 119:
	    v.integer = atoi(args[0].string);
	    break;
	case 120:
	    v.floating = atof(args[0].string);
	    break;
	case 91:
	    v.floating = sqrt(args[0].floating);
	    break;
	case 92:
	    v.floating = cos(args[0].floating);
	    break;
	case 93:
	    v.floating = sin(args[0].floating);
	    break;
	case 94:
	    v.floating = atan2(args[0].floating, args[1].floating);
	    break;
	case 95:
	    v.floating = exp(args[0].floating);
	    break;
	case 96:
	    v.floating = pow(args[0].floating, args[1].floating);
	    break;
	case 97:
	    v.floating = log(args[0].floating);
	    break;
	case 98:
	    v.floating = ((args[0].floating)<(args[1].floating)?(args[0].floating):(args[1].floating));
	    break;
	case 99:
	    v.floating = ((args[0].floating)>(args[1].floating)?(args[0].floating):(args[1].floating));
	    break;
	case 100:
	    v.integer = system(args[0].string);
	    break;
	case 112:
	case 108:
	    objp = ((Agobj_t *)(args[0].integer));
	    name = args[1].string;
	    if (!objp) {
		exerror("NULL object passed to aget()/hasAttr()");
		v.integer = 0;
	    } else if (!name) {
		exerror("NULL name passed to aget()/hasAttr()");
		v.integer = 0;
	    }
	    else {
	        Agsym_t *gsym = agattrsym(objp, name);
		if (sym->index == 112)
		    v.integer = (gsym != 0);
		else {
		    if (!gsym) {
	    		gsym = agattr(agroot(agraphof(objp)), ((((Agobj_t*)(objp))->tag).objtype), name, "");
	    		_err_msg(1, "Using value of %s uninitialized attribute \"%s\" of \"%s\" in aget()", kindOf (objp), name, nameOf(pgm, objp, state->tmp));
		    }
		    v.string = agxget(objp, gsym);
        	}
            }
	    break;
	case 109:
	    objp = ((Agobj_t *)(args[0].integer));
	    if (!objp) {
		_err_msg(1, "NULL object passed to aset()");
		v.integer = 1;
	    } else {
		char* name = args[1].string;
		char* value = args[2].string;
		if (!name) {
		    _err_msg(1, "NULL name passed to aset()");
		    v.integer = 1;
		}
		else if (!value) {
		    _err_msg(1, "NULL value passed to aset()");
		    v.integer = 1;
		}
		else {
		    v.integer = setattr(objp, name, value);
        	}
            }
	    break;
	case 111:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		char* kind = args[1].string;
		char* name = args[2].string;
		char* value = args[3].string;
		if (!name) {
		    _err_msg(1, "NULL name passed to setDflt()");
		    v.integer = 1;
		}
		else if (!value) {
		    _err_msg(1, "NULL value passed to setDflt()");
		    v.integer = 1;
		}
		else if (!kind) {
		    _err_msg(1, "NULL kind passed to setDflt()");
		    v.integer = 1;
		}
		else {
		    v.integer = setDfltAttr(gp, kind, name, value);
        	}
	    } else {
		_err_msg(1, "NULL graph passed to node()");
		v.integer = 0;
	    }
	    break;
	case 114:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		char* kind = args[1].string;
		if (!kind) {
		    _err_msg(2,"NULL kind passed to fstAttr()");
		    v.string = 0;
		}
		else {
		    v.string = nxtAttr (gp, kind, 0);
        	}
	    } else {
		exerror("NULL graph passed to fstAttr()");
		v.string = 0;
	    }
	    break;
	case 115:
	case 113:
	case 110:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		char* kind = args[1].string;
		char* name = args[2].string;
		if (!name) {
		    exerror("NULL name passed to %s", sym->name);
		    v.string = 0;
		}
		else if (!kind) {
		    exerror("NULL kind passed to %s", sym->name);
		    v.string = 0;
		}
		else if (sym->index == 113) {
		    v.integer = (agattr(gp, toKind (kind, sym->name), name, 0) != 0);
        	}
		else if (sym->index == 115) {
		    v.string = nxtAttr (gp, kind, name);
        	}
		else {
		    v.string = getDfltAttr(gp, kind, name);
        	}
	    } else {
		exerror("NULL graph passed to %s", sym->name);
		v.string = 0;
	    }
	    break;
	case 107:
	    v.string = canon(pgm, args[0].string);
	    break;
	case 106:
	    v.integer = aghtmlstr(args[0].string);
	    break;
	case 105:
	    gp = ((Agraph_t *)(args[0].integer));
	    if (gp) {
		v.string = toHtml(gp, args[1].string);
	    } else {
		_err_msg(1, "NULL graph passed to html()");
		v.string = 0;
	    }
	    break;
	case 116:
	    v.string = toLower(pgm, args[0].string, state->tmp);
	    break;
	case 121:
	    v.string = colorx(pgm, args[0].string, args[1].string, state->tmp);
	    break;
	case 118:
	    if (args[0].string) {
		if (args[1].string)
		    v.integer = strcmp(args[0].string,args[1].string);
		else
		    v.integer = -1; 
	    } else if (args[1].string)
		v.integer = 1; 
	    else
		v.integer = 0; 
	    break;
	case 117:
	    v.string = toUpper(pgm, args[0].string, state->tmp);
	    break;
	case 101:
	    v.string = xyOf(pgm, args[0].string, 1);
	    break;
	case 102:
	    v.string = xyOf(pgm, args[0].string, 0);
	    break;
	case 103:
	    v.string = bbOf(pgm, args[0].string, 1);
	    break;
	case 104:
	    v.string = bbOf(pgm, args[0].string, 0);
	    break;
	case 70:
	    v.integer = strlen(args[0].string);
	    break;
	case 65:
	    v.integer = indexOf(args[0].string, args[1].string);
	    break;
	case 66:
	    v.integer = rindexOf(args[0].string, args[1].string);
	    break;
	case 71:
	    v.integer = match(args[0].string, args[1].string);
	    break;
	case 122:
	    if ((bp = findBinding (state, args[0].string)))
		v.integer = (bp->fn)(args[1].string);
	    else
		v.integer = -1;
	    break;
	default:
	    exerror("unknown function call: %s", sym->name);
	}
	return v;
    } else if (elt == (-3)) {
	args = (Extype_t *) env;
	state = (Gpr_t *) (disc->user);
	switch (sym->index) {
	case 30:
	    v.string = getArg(args[0].integer, state);
	    break;
	default:
	    exerror("unknown array name: %s", sym->name);
	    v.string = 0;
	}
	return v;
    }

    state = (Gpr_t *) env;
    if (ref) {
	objp = deref(pgm, node, ref, 0, state);
	if (!objp)
	    exerror("null reference in expression %s",
		  deparse(pgm, node, state->tmp));
    } else if ((sym->lex == 283) && (sym->index <= 12)) {
	switch (sym->index) {
	case 1:
	    v.integer = ((_ast_intmax_t)(state->curobj));
	    break;
	case 2:
	    v.integer = ((_ast_intmax_t)(state->curgraph));
	    break;
	case 3:
	    v.integer = ((_ast_intmax_t)(state->nextgraph));
	    break;
	case 4:
	    v.integer = ((_ast_intmax_t)(state->target));
	    break;
	case 5:
	    v.integer = ((_ast_intmax_t)(state->outgraph));
	    break;
	case 6:
	    v.string = state->tgtname;
	    break;
	case 7:
	    v.string = state->infname;
	    break;
	case 12:
	    v.integer = state->argc;
	    break;
	case 11:
	    v.integer = state->tvt;
	    break;
	case 8:
	    v.integer = ((_ast_intmax_t)(state->tvroot));
	    break;
	case 9:
	    v.integer = ((_ast_intmax_t)(state->tvnext));
	    break;
	case 10:
	    v.integer = ((_ast_intmax_t)(state->tvedge));
	    break;
	}
	return v;
    } else {
	objp = state->curobj;
	if (!objp) {
	    exerror("current object $ not defined as reference for %s",
		  deparse(pgm, node, state->tmp));
	}
    }

    if (objp) {
	if (lookup(pgm, objp, sym, &v, state)) {
	    exerror("in expression %s", deparse(pgm, node, state->tmp));
	    v.integer = 0;
	}
    }
    else
	v.integer = 0;

    return v;
}



static char *typeName(Expr_t * pg, int op)
{
    return typenames[op - (24+1)];
}

/* setval:
 * Set sym to value v.
 * Return -1 if not allowed.
 * Assume already type correct.
 */
static int
setval(Expr_t * pgm, Exnode_t * x, Exid_t * sym, Exref_t * ref,
       void *env, int elt, Extype_t v, Exdisc_t * disc)
{
    Gpr_t *state;
    Agobj_t *objp;
    Agnode_t *np;
    int iv;
    int rv = 0;

    state = (Gpr_t *) env;
    if (ref) {
	objp = deref(pgm, x, ref, 0, state);
	if (!objp) {
	    exerror("in expression %s.%s",
		  ref->symbol->name, deparse(pgm, x, state->tmp));
	    return -1;
	}
    } else if ((1 <= sym->index) && (sym->index <= 136)) {
	switch (sym->index) {
	case 5:
	    state->outgraph = ((Agraph_t *)(v.integer));
	    break;
	case 11:
	    iv = v.integer;
	    if (validTVT(v.integer))
		state->tvt = (trav_type) iv;
	    else
		_err_msg(1, "unexpected value %d assigned to %s : ignored",
		      iv, typeName(pgm, 29));
	    break;
	case 8:
	    np = ((Agnode_t *)(v.integer));
	    if (!np || (agroot(np) == state->curgraph))
		state->tvroot = np;
	    else {
		_err_msg(1, "cannot set $tvroot, node %s not in $G : ignored",
		      agnameof(np));
	    }
	    break;
	case 9:
	    np = ((Agnode_t *)(v.integer));
	    if (!np || (agroot(np) == state->curgraph)) {
		state->tvnext = np;
		state->flags |= 8;
	    } else {
		_err_msg(1, "cannot set $tvnext, node %s not in $G : ignored",
		      agnameof(np));
	    }
	    break;
	case 6:
	    if (!(*(state->tgtname)==*(v.string)&&!strcmp(state->tgtname,v.string))) {
		(*(((Vmalloc_t*)(pgm->vm))->meth.freef))((pgm->vm),(void*)(state->tgtname));
		state->tgtname = vmstrdup(pgm->vm, v.string);
		state->name_used = 0;
	    }
	    break;
	default:
	    rv = -1;
	    break;
	}
	return rv;
    } else {
	objp = state->curobj;
	if (!objp) {
	    exerror("current object $ undefined in expression %s",
		  deparse(pgm, x, state->tmp));
	    return -1;
	}
    }
    
    assignable (objp, (unsigned char*)(sym->name));
    return setattr(objp, sym->name, v.string);
}

static int codePhase;





/* typeChk:
 * Type check input type against implied type of symbol sym.
 * If okay, return result type; else return 0.
 * For functions, input type set must intersect with function domain.
 * This means type errors may occur, but these will be caught at runtime.
 * For non-functions, input type must be 0.
 */
static tctype typeChk(tctype intype, Exid_t * sym)
{
    tctype dom = 0, rng = 0;

    switch (sym->lex) {
    case 275:
	dom = 0;
	switch (sym->type) {
	case 28:
	    rng = ((1<<(0x4))|(1<<(0x5))|(1<<(0x6)));;
	    break;
	case 25:
	    rng = (1<<(0x4));
	    break;
	case 27:
	    rng = (1<<(0x6));
	    break;
	case 26:
	    rng = (1<<(0x5));
	    break;
	case 259:
	    rng = (1<<(02));
	    break;
	case 262:
	    rng = (1<<(01));
	    break;
	case 263:
	    rng = (1<<(03));
	    break;
	default:
	    exerror("unknown dynamic type %d of symbol %s", sym->type,
		    sym->name);
	    break;
	}
	break;
    case 283:
	if (sym->index <= 136) {
	    switch (sym->index) {
	    case 8:
	    case 1:
	    case 2:
	    case 3:
		if (!((1 <= codePhase) && (codePhase <= 4)))
		    exerror
			("keyword %s cannot be used in BEGIN/END statements",
			 sym->name);
		break;
	    case 4:
		if (!((2 <= codePhase) && (codePhase <= 4)))
		    exerror
			("keyword %s cannot be used in BEGIN/BEG_G/END statements",
			 sym->name);
		break;
	    }
	    dom = tchk[sym->index][0];
	    rng = tchk[sym->index][1];
	} else {
	    dom = ((1<<(0x4))|(1<<(0x5))|(1<<(0x6)));
	    rng = (1<<(03));
	}
	break;
    case 287:
	if (!intype && !((1 <= codePhase) && (codePhase <= 4)))
	    exerror
		("undeclared, unmodified names like \"%s\" cannot be\nused in BEGIN and END statements",
		 sym->name);
	dom = ((1<<(0x4))|(1<<(0x5))|(1<<(0x6)));
	rng = (1<<(03));
	break;
    default:
	exerror("unexpected symbol in typeChk: name %s, lex %d",
		sym->name, sym->lex);
	break;
    }

    if (dom) {
	if (!intype)
	    intype = ((1<<(0x4))|(1<<(0x5))|(1<<(0x6)));	/* type of $ */
	if (!(dom & intype))
	    rng = 0;
    } else if (intype)
	rng = 0;
    return rng;
}

/* typeChkExp:
 * Type check variable expression.
 */
static tctype typeChkExp(Exref_t * ref, Exid_t * sym)
{
    tctype ty;

    if (ref) {
	ty = typeChk(0, ref->symbol);
	for (ref = ref->next; ty && ref; ref = ref->next)
	    ty = typeChk(ty, ref->symbol);
	if (!ty)
	    return 0;
    } else
	ty = 0;
    return typeChk(ty, sym);
}

/* refval:
 * Called during compilation for uses of references:   abc.x
 * Also for abc.f(..),  type abc.v, "abc".x and CONSTANTS.
 * The grammar has been  altered to disallow the first 3.
 * Type check expressions; return value unused.
 */
static Extype_t
refval(Expr_t * pgm, Exnode_t * node, Exid_t * sym, Exref_t * ref,
       char *str, int elt, Exdisc_t * disc)
{
    Extype_t v;
    if (sym->lex == 271) {
	switch (sym->index) {
	case 123:
	    v.integer = TV_flat;
	    break;
	case 124:
	    v.integer = TV_ne;
	    break;
	case 125:
	    v.integer = TV_en;
	    break;
	case 126:
	    v.integer = TV_bfs;
	    break;
	case 127:
	    v.integer = TV_dfs;
	    break;
	case 128:
	    v.integer = TV_fwd;
	    break;
	case 129:
	    v.integer = TV_rev;
	    break;
	case 130:
	    v.integer = TV_postdfs;
	    break;
	case 131:
	    v.integer = TV_postfwd;
	    break;
	case 132:
	    v.integer = TV_postrev;
	    break;
	case 133:
	    v.integer = TV_prepostdfs;
	    break;
	case 134:
	    v.integer = TV_prepostfwd;
	    break;
	case 135:
	    v.integer = TV_prepostrev;
	    break;
	case 136:
	    v.integer = 0;
	    break;
	default:
	    v = exzero(node->type);
	    break;
	}
    } else {
	if (!typeChkExp(ref, sym)) {
	    Gpr_t *state = (Gpr_t *) (disc->user);
	    exerror("type error using %s",
		    deparse(pgm, node, state->tmp));
	}
	v = exzero(node->type);
    }
    return v;
}

/* binary:
 * Evaluate (l ex->op r) producing a value of type ex->type,
 * stored in l.
 * May be unary, with r = NULL
 * Return -1 if operation cannot be done, 0 otherwise.
 * If arg is > 0, operation unnecessary; just report possibility.
 */
int
binary(Expr_t * pg, Exnode_t * l, Exnode_t * ex, Exnode_t * r, int arg,
       Exdisc_t * disc)
{
    Agobj_t *lobjp;
    Agobj_t *robjp;
    int ret = -1;

    if (((l->type) > 258))
	return -1;
    if (r && ((r->type) > 258))
	return -1;
    if (!((ex->type)>=259&&(ex->type)<=261))
	return -1;

    if (l->type == 29) {
	int li, ri;

	if (!r)
	    return -1;		/* Assume libexpr handled unary */
	if (r->type != 29)
	    return -1;

	li = l->data.constant.value.integer;
	ri = r->data.constant.value.integer;
	switch (ex->op) {
	case 326:
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li == ri);
	    ret = 0;
	    break;
	case 325:
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li != ri);
	    ret = 0;
	    break;
	case '<':
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li < ri);
	    ret = 0;
	    break;
	case 328:
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li <= ri);
	    ret = 0;
	    break;
	case 327:
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li >= ri);
	    ret = 0;
	    break;
	case '>':
	    if (arg)
		return 0;
	    l->data.constant.value.integer = (li > ri);
	    ret = 0;
	    break;
	}
    }

    /* l is a graph object; make sure r is also */
    if (r && (r->type == 29))
	return -1;

    lobjp = ((Agobj_t *)(l->data.constant.value.integer));
    if (r)
	robjp = ((Agobj_t *)(r->data.constant.value.integer));
    else
	robjp = 0;
    switch (ex->op) {
    case 326:
	if (arg)
	    return 0;
	l->data.constant.value.integer = !compare(lobjp, robjp);
	ret = 0;
	break;
    case 325:
	if (arg)
	    return 0;
	l->data.constant.value.integer = compare(lobjp, robjp);
	ret = 0;
	break;
    case '<':
	if (arg)
	    return 0;
	l->data.constant.value.integer = (compare(lobjp, robjp) < 0);
	ret = 0;
	break;
    case 328:
	if (arg)
	    return 0;
	l->data.constant.value.integer = (compare(lobjp, robjp) <= 0);
	ret = 0;
	break;
    case 327:
	if (arg)
	    return 0;
	l->data.constant.value.integer = (compare(lobjp, robjp) >= 0);
	ret = 0;
	break;
    case '>':
	if (arg)
	    return 0;
	l->data.constant.value.integer = (compare(lobjp, robjp) > 0);
	ret = 0;
	break;
    }

    return ret;
}

/* strToTvtype:
 */
static int
strToTvtype (char* s)
{
    int rt = 0;
    char* sfx;

    if (!strncmp(s, "TV_", 3)) {
	sfx = s + 3;
	if (!strcmp(sfx, "flat")) {
	    rt = TV_flat;
	} else if (!strcmp(sfx, "ne")) {
	    rt = TV_ne;
	} else if (!strcmp(sfx, "en")) {
	    rt = TV_en;
	} else if (!strcmp(sfx, "bfs")) {
	    rt = TV_bfs;
	} else if (!strcmp(sfx, "dfs")) {
	    rt = TV_dfs;
	} else if (!strcmp(sfx, "fwd")) {
	    rt = TV_fwd;
	} else if (!strcmp(sfx, "rev")) {
	    rt = TV_rev;
	} else if (!strcmp(sfx, "postdfs")) {
	    rt = TV_postdfs;
	} else if (!strcmp(sfx, "postfwd")) {
	    rt = TV_postfwd;
	} else if (!strcmp(sfx, "postrev")) {
	    rt = TV_postrev;
	} else if (!strcmp(sfx, "prepostdfs")) {
	    rt = TV_prepostdfs;
	} else if (!strcmp(sfx, "prepostfwd")) {
	    rt = TV_prepostfwd;
	} else if (!strcmp(sfx, "prepostrev")) {
	    rt = TV_prepostrev;
	} else
	    exerror("illegal string \"%s\" for type tvtype_t", s);
    } else
	exerror("illegal string \"%s\" for type tvtype_t", s);
    return rt;
}

/* tvtypeToStr:
 */
static char*
tvtypeToStr (int v)
{
    char* s = 0;

    switch (v) {
    case TV_flat:
	s = "TV_flat";
	break;
    case TV_ne:
	s = "TV_ne";
	break;
    case TV_en:
	s = "TV_en";
	break;
    case TV_bfs:
	s = "TV_bfs";
	break;
    case TV_dfs:
	s = "TV_dfs";
	break;
    case TV_fwd:
	s = "TV_fwd";
	break;
    case TV_rev:
	s = "TV_rev";
	break;
    case TV_postdfs:
	s = "TV_postdfs";
	break;
    case TV_postfwd:
	s = "TV_postfwd";
	break;
    case TV_postrev:
	s = "TV_postrev";
	break;
    case TV_prepostdfs:
	s = "TV_prepostdfs";
	break;
    case TV_prepostfwd:
	s = "TV_prepostfwd";
	break;
    case TV_prepostrev:
	s = "TV_prepostrev";
	break;
    default:
	exerror("Unexpected value %d for type tvtype_t",
	    v);
	break;
    }
    return s;
}

/* stringOf:
 * Convert value x to type string.
 * Assume x does not have a built-in type
 * Return -1 if conversion cannot be done, 0 otherwise.
 * If arg is > 0, conversion unnecessary; just report possibility.
 */
static int stringOf(Expr_t * prog, register Exnode_t * x, int arg, Exdisc_t* disc)
{
    Agobj_t *objp;
    int rv = 0;

    if (arg)
	return 0;

    if (x->type == 29) {
	if (!(x->data.constant.value.string = 
	    tvtypeToStr (x->data.constant.value.integer)))
	    rv = -1;
    } else {
	objp = ((Agobj_t *)(x->data.constant.value.integer));
	if (!objp) {
	    exerror("cannot generate name for NULL %s",
		    typeName(prog, x->type));
	    rv = -1;
	}
	else {
	    Gpr_t* state = (Gpr_t *) (disc->user);
	    x->data.constant.value.string = nameOf(prog, objp, state->tmp);
	}
    }
    x->type = 263;
    return 0;
}

/* convert:
 * Convert value x of type x->type to type type.
 * Return -1 if conversion cannot be done, 0 otherwise.
 * If arg is > 0, conversion unnecessary; just report possibility.
 * In particular, assume x != 0 if arg == 0.
 * Use #ifdef OLD to remove graph object conversion to strings,
 * as this seemed to dangerous.
 */
static int
convert(Expr_t * prog, register Exnode_t * x, int type,
	register Exid_t * xref, int arg, Exdisc_t * disc)
{
    Agobj_t *objp;
    int ret = -1;

    /* If both types are built-in, let libexpr handle */
    if (((type) > 258) && ((x->type) > 258))
	return -1;
    if ((type == 28) && (x->type <= 28))
	ret = 0;		/* trivial cast from specific graph object to T_obj */
    else if ((type <= 28) && (x->type == 259)) {
	if (x->data.constant.value.integer == 0)
	    ret = 0;		/* allow NULL pointer */
    } else if (type == 259) {
	ret = 0;
    } else if (x->type == 28) {
	/* check dynamic type */
	if (arg) {
	    if ((type != 262) && (type <= 28))
		ret = 0;
	} else {
	    objp = ((Agobj_t *)(x->data.constant.value.integer));
	    switch (type) {
	    case 27:
		if (!objp || ((((Agobj_t*)(objp))->tag).objtype) == 0)
		    ret = 0;
		break;
	    case 25:
		if (!objp || ((((Agobj_t*)(objp))->tag).objtype) == 1)
		    ret = 0;
		break;
	    case 26:
		if (!objp || (((((Agobj_t*)(objp))->tag).objtype)&2))
		    ret = 0;
		break;

	    
		
		
		

	    }
	}
    } else if (type == 263) {
	if (x->type == 29) {
	    ret = 0;
	    if (!arg) {
		x->data.constant.value.string =
		    tvtypeToStr (x->data.constant.value.integer);
	    }
	}

	
	    
	    
		
		
	    
		
	

    } else if ((type == 29) && (x->type == 259)) {
	if (arg)
	    ret = 0;
	else if (validTVT(x->data.constant.value.integer))
	    ret = 0;
	else
	    exerror("Integer value %d not legal for type tvtype_t",
		x->data.constant.value.integer);
    }
    /* in case libexpr hands us the trivial case */
    else if (x->type == type) {
	ret = 0;
    } else if (x->type == 263) {
	char *s;
	if (type == 29) {
	    if (arg)
		ret = 0;
	    else {
		ret = 0;
		s = x->data.constant.value.string;
		x->data.constant.value.integer = strToTvtype(s);
	    }
	}
    }
    if (!arg && (ret == 0))
	x->type = type;
    return ret;
}

/* keyval;
 * Calculate unique key for object.
 * We use this to unify local copies of nodes and edges.
 */
static Extype_t keyval(Expr_t * pgm, Extype_t v, int type, Exdisc_t * disc)
{
    if (type <= 28) {
	v.integer = ((((Agobj_t*)(((Agobj_t *)(v.integer))))->tag).id);
    }
    return v;
}

/* matchval:
 * Pattern match strings.
 */
static int
matchval(Expr_t * pgm, Exnode_t * xstr, const char *str, Exnode_t * xpat,
	 const char *pat, void *env, Exdisc_t * disc)
{
    return strgrpmatch(str, pat, 0, 0,
		       01 | 02 | 04);
}

/* a2t:
 * Convert type indices to symbolic name.
 */
static int
 a2t[] = { 0, 262, 259, 263,
    25, 26, 27, 28
};

/* initDisc:
 * Create and initialize expr discipline.
 */
static Exdisc_t *initDisc(Gpr_t * state)
{
    Exdisc_t *dp;

    dp = ((0)?(Exdisc_t*)realloc((char*)(0),sizeof(Exdisc_t)*(1)+(0)):(Exdisc_t*)calloc(1,sizeof(Exdisc_t)*(1)+(0)));
    if (!dp) {
	_err_msg(2,
	      "could not create libexp discipline: out of memory");
	return 0;
    }

    dp->version = 20000101L;
    dp->flags = (1<<0) | (1<<9);
    dp->symbols = symbols;
    dp->convertf = convert;
    dp->stringof = stringOf;
    dp->binaryf = binary;
    dp->typename = typeName;
    if (state->errf)
	dp->errorf = state->errf;
    else
	dp->errorf = (Exerror_f) errorf;
    dp->keyf = keyval;
    dp->getf = getval;
    dp->reff = refval;
    dp->setf = setval;
    dp->matchf = matchval;
    dp->exitf = state->exitf;
    dp->types = a2t;
    dp->user = state;

    state->dp = dp;   /* dp is freed when state is freed */

    return dp;
}

/* compile:
 * Compile given string, then extract and return
 * typed expression.
 */
static Exnode_t *compile(Expr_t * prog, char *src, char *input, int line,
			 char *lbl, char *sfx, int kind)
{
    Exnode_t *e = 0;
    Sfio_t *sf;
    Sfio_t *prefix;
    int rv;

    /* create input stream */
    if (sfx) {
	sf = sfopen(0, sfx, "rs");
	if (input) {
	    prefix = sfopen(0, input, "rs");
	    sfstack(sf, prefix);
	}
    } else
	sf = sfopen(0, input, "rs");

    /*  prefixing label if necessary */
    if (lbl) {
	prefix = sfopen(0, 0, "sr+");
	sfprintf(prefix, "%s:\n", lbl);
	sfseek(prefix, 0, 0);
	sfstack(sf, prefix);
	line--;
    }

    if (!src)
	src = "<command line>";
    rv = excomp(prog, src, line, 0, sf);
    sfclose(sf);

    if (rv >= 0 && (getErrorErrors() == 0))
	e = exexpr(prog, lbl, 0, kind);

    return e;
}

/* checkGuard:
 * Check if guard is an assignment and warn.
 */
static void checkGuard(Exnode_t * gp, char *src, int line)
{
    gp = exnoncast(gp);
    if (gp && exisAssign(gp)) {
	if (src) {
	    setErrorFileLine (src, line);
	}
	_err_msg(1, "assignment used as bool in guard");
    }
}

/* mkStmts:
 */
static case_stmt *mkStmts(Expr_t * prog, char *src, case_info * sp,
			  int cnt, char *lbl, Sfio_t *tmps)
{
    case_stmt *cs;
    int i;

    cs = ((0)?(case_stmt*)realloc((char*)(0),sizeof(case_stmt)*(cnt)+(0)):(case_stmt*)calloc(1,sizeof(case_stmt)*(cnt)+(0)));

    for (i = 0; i < cnt; i++) {
	if (sp->guard) {
	    sfprintf(tmps, "%s_g%d", lbl, i);
	    cs[i].guard = compile(prog, src, sp->guard, sp->gstart,
				  (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ), 0, 259);
	    if (getErrorErrors()) break;
	    checkGuard(cs[i].guard, src, sp->gstart);
	}
	if (sp->action) {
	    sfprintf(tmps, "%s_a%d", lbl, i);
	    cs[i].action = compile(prog, src, sp->action, sp->astart,
				   (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ), 0, 259);
	    if (getErrorErrors()) break;
	    /* If no error but no compiled action, the input action must
	     * have been essentially an empty block, which should be
	     * considered different from a missing block. So, compile a
	     * trivial block.
	     */
	    if (!cs[i].action) {
		sfprintf(tmps, "%s__a%d", lbl, i);
		cs[i].action = compile(prog, src, "1", sp->astart,
				   (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ), 0, 259);
	    }
	}
	sp = sp->next;
    }

    return cs;
}

/* mkBlocks:
 */
static int mkBlock(comp_block* bp, Expr_t * prog, char *src, parse_block *inp, Sfio_t* tmps, int i)
{
    int rv = 0;
    char label[BUFSIZ];

    codePhase = 1;
    if (inp->begg_stmt) {
	sfprintf(tmps, "_begin_g_%d", i);
	symbols[0].type = 27;
	tchk[1][1] = (1<<(0x6));
	bp->begg_stmt = compile(prog, src, inp->begg_stmt,
			       inp->l_beging, (( (((Sfio_t*)((tmps)))->next >= ((Sfio_t*)((tmps)))->endw ? _sfflsbuf(((Sfio_t*)((tmps))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((tmps)))->next++ = (unsigned char)((0))) ) ), (char*)((tmps)->next = (tmps)->data) ), 0, 264);
	if (getErrorErrors())
	    goto finishBlk;
	rv |= 0x2;
    }

    codePhase = 2;
    if (inp->node_stmts) {
	symbols[0].type = 25;
	tchk[1][1] = (1<<(0x4));
	bp->n_nstmts = inp->n_nstmts;
	sprintf (label, "_nd%d", i);
	bp->node_stmts = mkStmts(prog, src, inp->node_stmts,
				inp->n_nstmts, label, tmps);
	if (getErrorErrors())
	    goto finishBlk;
	bp->walks |= 0x1;
    }

    codePhase = 3;
    if (inp->edge_stmts) {
	symbols[0].type = 26;
	tchk[1][1] = (1<<(0x5));
	bp->n_estmts = inp->n_estmts;
	sprintf (label, "_eg%d", i);
	bp->edge_stmts = mkStmts(prog, src, inp->edge_stmts,
				inp->n_estmts, label, tmps);
	if (getErrorErrors())
	    goto finishBlk;
	bp->walks |= 0x1;
    }

    finishBlk:
    if (getErrorErrors()) {
	free (bp->node_stmts);
	free (bp->edge_stmts);
	bp->node_stmts = 0;
	bp->edge_stmts = 0;
    }

    return (rv | bp->walks);
}

/* doFlags:
 * Convert command line flags to actions in END_G.
 */
static char *doFlags(int flags, Sfio_t * s)
{
    sfprintf(s, "\n");
    if (flags & 0x1)
	sfprintf(s, "$O = $G;\n");
    if (flags & 0x2)
	sfprintf(s, "induce($O);\n");
    return (( (((Sfio_t*)((s)))->next >= ((Sfio_t*)((s)))->endw ? _sfflsbuf(((Sfio_t*)((s))),(int)((unsigned char)((0)))) : (int)(*((Sfio_t*)((s)))->next++ = (unsigned char)((0))) ) ), (char*)((s)->next = (s)->data) );
}

/* compileProg:
 * Convert gpr sections in libexpr program.
 */
comp_prog *compileProg(parse_prog * inp, Gpr_t * state, int flags)
{
    comp_prog *p;
    Sfio_t *tmps = state->tmp;
    char *endg_sfx = 0;
    int i, useflags = 0;

    /* Initialize default io */
    state->dfltIO = &gprIoDisc;

    /* Make sure we have enough bits for types */
    assert(8 * sizeof(tctype) >= (1 << 4));

    p = ((0)?(comp_prog*)realloc((char*)(0),sizeof(comp_prog)*(1)+(0)):(comp_prog*)calloc(1,sizeof(comp_prog)*(1)+(0)));
    if (!p) {
	_err_msg(2,
	      "could not create compiled program: out of memory");
	goto finish;
    }

    if (flags) {
	endg_sfx = strdup (doFlags(flags, tmps));
	if (*endg_sfx == '\0')
	    endg_sfx = 0;
    }

    if (!(initDisc(state)))
	goto finish;
    
    exinit();
    if (!(p->prog = exopen(state->dp)))
	goto finish;

    codePhase = 0;
    if (inp->begin_stmt) {
	p->begin_stmt = compile(p->prog, inp->source, inp->begin_stmt,
				inp->l_begin, 0, 0, 264);
	if (getErrorErrors())
	    goto finish;
    }

    if (inp->blocks) {
	comp_block* bp;
	parse_block* ibp = inp->blocks;

	p->blocks = bp = ((0)?(comp_block*)realloc((char*)(0),sizeof(comp_block)*(inp->n_blocks)+(0)):(comp_block*)calloc(1,sizeof(comp_block)*(inp->n_blocks)+(0)));

	for (i = 0; i < inp->n_blocks; bp++, i++) {
	    useflags |= mkBlock (bp, p->prog, inp->source, ibp, tmps, i);
	    if (getErrorErrors())
		goto finish;
	    else {
		ibp = ibp->next;
		p->n_blocks++;
	    }
	}
    }
    p->flags = useflags;

    codePhase = 4;
    if (inp->endg_stmt || endg_sfx) {
	symbols[0].type = 27;
	tchk[1][1] = (1<<(0x6));
	p->endg_stmt = compile(p->prog, inp->source, inp->endg_stmt,
			       inp->l_endg, "_end_g", endg_sfx, 264);
	if (getErrorErrors())
	    goto finish;
    }

    codePhase = 5;
    if (inp->end_stmt) {
	symbols[0].type = 28;
	p->end_stmt = compile(p->prog, inp->source, inp->end_stmt,
			      inp->l_end, "_end_", 0, 264);
	if (getErrorErrors())
	    goto finish;
    }
    setErrorLine (0); /* execution errors have no line numbers */

    if (p->end_stmt)
	p->flags |= 0x4;

    finish:
    if (getErrorErrors()) {
	freeCompileProg (p);
	p = 0;
    }
    free (endg_sfx);

    return p;
}

void
freeCompileProg (comp_prog *p)
{
    comp_block* bp;
    int i;

    if (!p) return;

    exclose (p->prog, 1);
    for (i = 0; i < p->n_blocks; i++) {
	bp = p->blocks + i;
	free (bp->node_stmts);
	free (bp->edge_stmts);
    }
    free (p->blocks);
    free (p);
}

/* walksGraph;
 * Returns true if block actually has node or edge statements.
 */
int walksGraph(comp_block * p)
{
    return (p->walks);
}

/* usesGraph;
 * Returns true if program uses the graph, i.e., has
 * N/E/BEG_G/END_G statments
 */
int usesGraph(comp_prog * p)
{
    return (p->flags);
}

void ptchk(void)
{
    int i;
    for (i = 0; i <= 24; i++)
	printf("%d: %d %d\n", i, tchk[i][0], tchk[i][1]);
}

/* readG:
 * Read graph from file and initialize
 * dynamic data.
 */
Agraph_t *readG(Sfio_t * fp)
{
    Agraph_t *g;


    
    

    g = agread(fp, &gprDisc);
    if (g) {
	aginit(g, 0, "userval", sizeof(gdata), 0);
	aginit(g, 1, "userval", sizeof(ndata), 0);
	aginit(g, 2, "userval", sizeof(edata), 0);
    }
    return g;
}

/* openG:
 * Open graph and initialize dynamic data.
 */
Agraph_t *openG(char *name, Agdesc_t desc)
{
    Agraph_t *g;


    
    

    g = agopen(name, desc, &gprDisc);
    if (g)
	agbindrec(g, "userval", sizeof(gdata), 0);
    return g;
}

/* openSubg:
 * Open subgraph and initialize dynamic data.
 */
Agraph_t *openSubg(Agraph_t * g, char *name)
{
    Agraph_t *sg;

    sg = agsubg(g, name, 1);
    if (sg && !aggetrec(sg, "userval", 0))
	agbindrec(sg, "userval", sizeof(gdata), 0);
    return sg;
}

/* openNode:
 * Create node and initialize dynamic data.
 */
Agnode_t *openNode(Agraph_t * g, char *name)
{
    Agnode_t *np;

    np = agnode(g, name, 1);
    if (np && !aggetrec(np, "userval", 0))
	agbindrec(np, "userval", sizeof(ndata), 0);
    return np;
}

/* openEdge:
 * Create edge and initialize dynamic data.
 */
Agedge_t *openEdge(Agraph_t* g, Agnode_t * t, Agnode_t * h, char *key)
{
    Agedge_t *ep;
    Agraph_t *root;

    root = sameG(t, h, "openEdge", "tail and head nodes");
    if (!root)
	return 0;
    if (g) {
	if (!sameG(g, root, "openEdge", "subgraph and nodes"))
	    return 0;
    } else
	g = root;

    ep = agedge(g, t, h, key, 1);
    if (ep && !aggetrec(ep, "userval", 0))
	agbindrec(ep, "userval", sizeof(edata), 0);
    return ep;
}

