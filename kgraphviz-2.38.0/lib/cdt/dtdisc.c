#line 1 "graphviz-2.38.0\\lib\\cdt\\dtdisc.c" 1
#line 1 "graphviz-2.38.0\\lib\\cdt\\dthdr.h" 1






/*	Internal definitions for libcdt.
**	Written by Kiem-Phong Vo (5/25/96)
*/




#line 1 "graphviz-2.38.0\\lib\\cdt\\dthdr.h" 1


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

























































#line 10 "graphviz-2.38.0\\lib\\cdt\\dthdr.h" 2

/* short-hand notations */








/* this must be disjoint from DT_METHODS */



/* how the Dt_t handle was allocated */



/* max search length before splaying */


/* hash start size and load factor */








/* tree rotation/linking functions */









1
extern void*	malloc (size_t);
extern void*	realloc (void*, size_t);
extern void	free (void*);




#line 3 "graphviz-2.38.0\\lib\\cdt\\dtdisc.c" 2

/*	Change discipline.
**	dt :	dictionary
**	disc :	discipline
**
**	Written by Kiem-Phong Vo (5/26/96)
*/


static void* dtmemory(Dt_t* dt,void* addr,size_t size,Dtdisc_t* disc)







{
	if(addr)
	{	if(size == 0)
		{	free(addr);
			return ((void*)0);
		}
		else	return realloc(addr,size);
	}
	else	return size > 0 ? malloc(size) : ((void*)0);
}


Dtdisc_t* dtdisc(Dt_t* dt, Dtdisc_t* disc, int type)






{
	register Dtsearch_f	searchf;
	register Dtlink_t	*r, *t;
	register char*	k;
	register Dtdisc_t*	old;

	if(!(old = dt->disc) )	/* initialization call from dtopen() */
	{	dt->disc = disc;
		if(!(dt->memoryf = disc->memoryf) )
			dt->memoryf = dtmemory;
		return disc;
	}

	if(!disc)	/* only want to know current discipline */
		return old;

	searchf = dt->meth->searchf;

	((dt->data->type&010000) ? dtrestore(dt,((Dtlink_t*)0)) : 0);

	if(old->eventf && (*old->eventf)(dt,3,(void*)disc,old) < 0)
		return ((Dtdisc_t*)0);

	dt->disc = disc;
	if(!(dt->memoryf = disc->memoryf) )
		dt->memoryf = dtmemory;

	if(dt->data->type&(0000040|0000100|0000020))
		goto done;
	else if(dt->data->type&0000002)
	{	if(type&0000002)
			goto done;
		else	goto dt_renew;
	}
	else if(dt->data->type&(0000001|0000002))
	{	if((type&0000002) && (type&0000001))
			goto done;
		else	goto dt_renew;
	}
	else /*if(dt->data->type&(DT_OSET|DT_OBAG))*/
	{	if(type&0000001)
			goto done;
	dt_renew:
		r = dtflatten(dt);
		dt->data->type &= ~010000;
		dt->data->here = ((Dtlink_t*)0);
		dt->data->size = 0;

		if(dt->data->type&(0000001|0000002))
		{	register Dtlink_t	**s, **ends;
			ends = (s = dt->data->hh._htab) + dt->data->ntab;
			while(s < ends)
				*s++ = ((Dtlink_t*)0);
		}

		/* reinsert them */
		while(r)
		{	t = r->right;
			if(!(type&0000002))	/* new hash value */
			{	k = (char*)(disc->link < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - disc->link) );
				k = (void*)(disc->size < 0 ? *((char**)((char*)((void*)k)+disc->key)) : ((char*)((void*)k)+disc->key));
				r->hl._hash = (disc->hashf ? (*disc->hashf)(dt,k,disc) : dtstrhash(0,k,disc->size) );
			}
			(void)(*searchf)(dt,(void*)r,0000040);
			r = t;
		}
	}

done:
	return old;
}
