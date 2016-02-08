#line 1 "graphviz-2.38.0\\lib\\cdt\\dthash.c" 1
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

























































#line 11 "graphviz-2.38.0\\lib\\cdt\\dthdr.h" 2

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




#line 3 "graphviz-2.38.0\\lib\\cdt\\dthash.c" 2

/*	Hash table.
**	dt:	dictionary
**	obj:	what to look for
**	type:	type of search
**
**      Written by Kiem-Phong Vo (05/25/96)
*/

/* resize the hash table */

static void dthtab(Dt_t* dt)




{
	register Dtlink_t	*t, *r, *p, **s, **hs, **is, **olds;
	int		n, k;

	if(dt->data->minp > 0 && dt->data->ntab > 0) /* fixed table size */
		return;
	dt->data->minp = 0;

	n = dt->data->ntab;
	if(dt->disc && dt->disc->eventf &&
	   (*dt->disc->eventf)(dt, 7, &n, dt->disc) > 0 )
	{	if(n < 0) /* fix table size */
		{	dt->data->minp = 1;
			if(dt->data->ntab > 0 )
				return;
		}
		else /* set a particular size */
		{	for(k = 2; k < n; k *= 2)
				;
			n = k;
		}
	}
	else	n = 0;

	/* compute new table size */
	if(n <= 0)
	{	if((n = dt->data->ntab) == 0)
			n = (256);
		while(dt->data->size > ((n) << 1))
			n = ((n) << 1);
	}
	if(n == dt->data->ntab)
		return;

	/* allocate new table */
	olds = dt->data->ntab == 0 ? ((Dtlink_t**)0) : dt->data->hh._htab;
	if(!(s = (Dtlink_t**)(*dt->memoryf)(dt,olds,n*sizeof(Dtlink_t*),dt->disc)) )
		return;
	olds = s + dt->data->ntab;
	dt->data->hh._htab = s;
	dt->data->ntab = n;

	/* rehash elements */
	for(hs = s+n-1; hs >= olds; --hs)
		*hs = ((Dtlink_t*)0);
	for(hs = s; hs < olds; ++hs)
	{	for(p = ((Dtlink_t*)0), t = *hs; t; t = r)
		{	r = t->right;
			if((is = s + ((t->hl._hash)&((n)-1))) == hs)
				p = t;
			else	/* move to a new chain */
			{	if(p)
					p->right = r;
				else	*hs = r;
				t->right = *is; *is = t;
			}
		}
	}
}


static void* dthash(Dt_t* dt, register void* obj, int type)






{
	register Dtlink_t	*t, *r, *p;
	register void	*k, *key;
	register unsigned int	hsh;
	register int		lk, sz, ky;
	register Dtcompar_f	cmpf;
	register Dtdisc_t*	disc;
	register Dtlink_t	**s, **ends;

	((dt->data->type&010000) ? dtrestore(dt,((Dtlink_t*)0)) : 0);

	/* initialize discipline data */
	disc = dt->disc; (ky = disc->key, sz = disc->size, lk = disc->link, cmpf = disc->comparf);
	dt->type &= ~0100000;

	if(!obj)
	{	if(type&(0000010|0000020))
			goto end_walk;

		if(dt->data->size <= 0 || !(type&(0000100|0000200|0000400)) )
			return ((void*)0);

		ends = (s = dt->data->hh._htab) + dt->data->ntab;
		if(type&0000100)
		{	/* clean out all objects */
			for(; s < ends; ++s)
			{	t = *s;
				*s = ((Dtlink_t*)0);
				if(!disc->freef && disc->link >= 0)
					continue;
				while(t)
				{	r = t->right;
					if(disc->freef)
						(*disc->freef)(dt,(lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ),disc);
					if(disc->link < 0)
						(*dt->memoryf)(dt,(void*)t,0,disc);
					t = r;
				}
			}
			dt->data->here = ((Dtlink_t*)0);
			dt->data->size = 0;
			dt->data->loop = 0;
			return ((void*)0);
		}
		else	/* computing the first/last object */
		{	t = ((Dtlink_t*)0);
			while(s < ends && !t )
				t = (type&0000400) ? *--ends : *s++;
			if(t && (type&0000400))
				for(; t->right; t = t->right)
					;

			dt->data->loop += 1;
			dt->data->here = t;
			return t ? (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ) : ((void*)0);
		}
	}

	/* allow apps to delete an object "actually" in the dictionary */
	if(dt->meth->type == 0000002 && (type&(0000002|0010000)) )
	{	if(!(*(((Dt_t*)(dt))->searchf))((dt),(void*)(obj),0000004) )
			return ((void*)0);

		s = dt->data->hh._htab + ((dt->data->here->hl._hash)&((dt->data->ntab)-1));
		r = ((Dtlink_t*)0);
		for(p = ((Dtlink_t*)0), t = *s; t; p = t, t = t->right)
		{	if((lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ) == obj) /* delete this specific object */
				goto do_delete;
			if(t == dt->data->here)
				r = p;
		}

		/* delete some matching object */
		p = r; t = dt->data->here;
		goto do_delete;
	}

	if(type&(0001000|0000004|0000001|0004000) )
	{	key = (type&0001000) ? obj : (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		hsh = (disc->hashf ? (*disc->hashf)(dt,key,disc) : dtstrhash(0,key,sz) );
		goto do_search;
	}
	else if(type&(0000040|0002000) )
	{	r = (Dtlink_t*)obj;
		obj = (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) );
		key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		hsh = r->hl._hash;
		goto do_search;
	}
	else /*if(type&(DT_DELETE|DT_DETACH|DT_NEXT|DT_PREV))*/
	{	if((t = dt->data->here) && (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ) == obj)
		{	hsh = t->hl._hash;
			s = dt->data->hh._htab + ((hsh)&((dt->data->ntab)-1));
			p = ((Dtlink_t*)0);
		}
		else
		{	key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
			hsh = (disc->hashf ? (*disc->hashf)(dt,key,disc) : dtstrhash(0,key,sz) );
		do_search:
			t = dt->data->ntab <= 0 ? ((Dtlink_t*)0) :
			 	*(s = dt->data->hh._htab + ((hsh)&((dt->data->ntab)-1)));
			for(p = ((Dtlink_t*)0); t; p = t, t = t->right)
			{	if(hsh == t->hl._hash)
				{	k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
					if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) == 0)
						break;
				}
			}
		}
	}

	if(t) /* found matching object */
		dt->type |= 0100000;

	if(type&(0001000|0000004|0002000))
	{	if(!t)
			return ((void*)0);
		if(p && (dt->data->type&0000001) && dt->data->loop <= 0)
		{	/* move-to-front heuristic */
			p->right = t->right;
			t->right = *s;
			*s = t;
		}
		dt->data->here = t;
		return (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) );
	}
	else if(type&(0000001|0004000))
	{	if(t && (dt->data->type&0000001) )
		{	dt->data->here = t;
			return (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) );
		}

		if(disc->makef && (type&0000001) &&
		   !(obj = (*disc->makef)(dt,obj,disc)) )
			return ((void*)0);
		if(lk >= 0)
			r = ((Dtlink_t*)((char*)(obj) + lk) );
		else
		{	r = (Dtlink_t*)(*dt->memoryf)
				(dt,((void*)0),sizeof(Dthold_t),disc);
			if(r)
				((Dthold_t*)r)->obj = obj;
			else
			{	if(disc->makef && disc->freef && (type&0000001))
					(*disc->freef)(dt,obj,disc);
				return ((void*)0);
			}
		}
		r->hl._hash = hsh;

		/* insert object */
	do_insert:
		if((dt->data->size += 1) > ((dt->data->ntab) << 1) && dt->data->loop <= 0 )
			dthtab(dt);
		if(dt->data->ntab == 0)
		{	dt->data->size -= 1;
			if(disc->freef && (type&0000001))
				(*disc->freef)(dt,obj,disc);
			if(disc->link < 0)
				(*disc->memoryf)(dt,(void*)r,0,disc);
			return ((void*)0);
		}
		s = dt->data->hh._htab + ((hsh)&((dt->data->ntab)-1));
		if(t)
		{	r->right = t->right;
			t->right = r;
		}
		else
		{	r->right = *s;
			*s = r;
		}
		dt->data->here = r;
		return obj;
	}
	else if(type&0000010)
	{	if(t && !(p = t->right) )
		{	for(ends = dt->data->hh._htab+dt->data->ntab, s += 1; s < ends; ++s)
				if((p = *s) )
					break;
		}
		goto done_adj;
	}
	else if(type&0000020)
	{	if(t && !p)
		{	if((p = *s) != t)
			{	while(p->right != t)
					p = p->right;
			}
			else
			{	p = ((Dtlink_t*)0);
				for(s -= 1, ends = dt->data->hh._htab; s >= ends; --s)
				{	if((p = *s) )
					{	while(p->right)
							p = p->right;
						break;
					}
				}
			}
		}
	done_adj:
		if(!(dt->data->here = p) )
		{ end_walk:
			if((dt->data->loop -= 1) < 0)
				dt->data->loop = 0;
			if(dt->data->size > ((dt->data->ntab) << 1) && dt->data->loop <= 0)
				dthtab(dt);
			return ((void*)0);
		}
		else
		{	dt->data->type |= 020000;
			return (lk < 0 ? ((Dthold_t*)(p))->obj : (void*)((char*)(p) - lk) );
		}
	}
	else if(type&0000040)
	{	if(!t || (dt->data->type&0000002) )
			goto do_insert;
		else
		{	if(disc->freef)
				(*disc->freef)(dt,obj,disc);
			if(disc->link < 0)
				(*dt->memoryf)(dt,(void*)r,0,disc);
			return t ? (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ) : ((void*)0);
		}
	}
	else /*if(type&(DT_DELETE|DT_DETACH))*/
	{	/* take an element out of the dictionary */
	do_delete:
		if(!t)
			return ((void*)0);
		else if(p)
			p->right = t->right;
		else if((p = *s) == t)
			p = *s = t->right;
		else
		{	while(p->right != t)
				p = p->right;
			p->right = t->right;
		}
		obj = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) );
		dt->data->size -= 1;
		dt->data->here = p;
		if(disc->freef && (type&0000002))
			(*disc->freef)(dt,obj,disc);
		if(disc->link < 0)
			(*dt->memoryf)(dt,(void*)t,0,disc);
		return obj;
	}
}

static Dtmethod_t	_Dtset = { dthash, 0000001 };
static Dtmethod_t	_Dtbag = { dthash, 0000002 };
Dtmethod_t* Dtset = &_Dtset;
Dtmethod_t* Dtbag = &_Dtbag;


Dtmethod_t		_Dthash = { dthash, 0000001 };
Dtmethod_t* Dthash = &_Dthash;





