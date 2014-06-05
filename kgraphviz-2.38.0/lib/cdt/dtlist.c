#line 1 "graphviz-2.38.0\\lib\\cdt\\dtlist.c" 1
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




#line 3 "graphviz-2.38.0\\lib\\cdt\\dtlist.c" 2

/*	List, Deque, Stack, Queue.
**
**	Written by Kiem-Phong Vo (05/25/96)
*/


static void* dtlist(register Dt_t* dt, register void* obj, register int type)






{
	register int		lk, sz, ky;
	register Dtcompar_f	cmpf;
	register Dtdisc_t*	disc;
	register Dtlink_t	*r, *t;
	register void	*key, *k;

	((dt->data->type&010000) ? dtrestore(dt,((Dtlink_t*)0)) : 0);
	disc = dt->disc; (ky = disc->key, sz = disc->size, lk = disc->link, cmpf = disc->comparf);
	dt->type &= ~0100000;

	if(!obj)
	{	if(type&(0000400|0000200) )
		{	if((r = dt->data->hh._head) )
			{	if(type&0000400)
					r = r->hl._left;
				dt->data->here = r;
			}
			return r ? (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) ) : ((void*)0);
		}
		else if(type&(0000002|0010000))
		{	if((dt->data->type&(0000020|0000200)) || !(r = dt->data->hh._head))
				return ((void*)0);
			else	goto dt_delete;
		}
		else if(type&0000100)
		{	if(disc->freef || disc->link < 0)
			{	for(r = dt->data->hh._head; r; r = t)
				{	t = r->right;
					if(disc->freef)
						(*disc->freef)(dt,(lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) ),disc);
					if(disc->link < 0)
						(*dt->memoryf)(dt,(void*)r,0,disc);
				}
			}
			dt->data->hh._head = dt->data->here = ((Dtlink_t*)0);
			dt->data->size = 0;
			return ((void*)0);
		}
		else	return ((void*)0);
	}

	if(type&(0000001|0004000))
	{	if(disc->makef && (type&0000001) &&
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

		if(dt->data->type&0000200)
		{	if(type&0020000)
				goto dt_queue;
			else	goto dt_stack;
		}
		else if(dt->data->type&0000020)
		{	if(type&0020000)
			{	if(!(t = dt->data->here) || !t->right)
					goto dt_queue;
				r->right = t->right;
				r->right->hl._left = r;
				r->hl._left = t;
				r->hl._left->right = r;
			}
			else
			{	if(!(t = dt->data->here) || t == dt->data->hh._head)
					goto dt_stack;
				r->hl._left = t->hl._left;
				r->hl._left->right = r;
				r->right = t;
				r->right->hl._left = r;
			}
		}
		else if(dt->data->type&0000040)
		{ dt_stack:
			r->right = t = dt->data->hh._head;
			if(t)
			{	r->hl._left = t->hl._left;
				t->hl._left = r;
			}
			else	r->hl._left = r;
			dt->data->hh._head = r;
		}
		else /* if(dt->data->type&DT_QUEUE) */
		{ dt_queue:
			if((t = dt->data->hh._head) )
			{	t->hl._left->right = r;
				r->hl._left = t->hl._left;
				t->hl._left = r;
			}
			else
			{	dt->data->hh._head = r;
				r->hl._left = r;
			}
			r->right = ((Dtlink_t*)0);
		}

		if(dt->data->size >= 0)
			dt->data->size += 1;

		dt->data->here = r;
		return (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) );
	}

	if((type&0001000) || !(r = dt->data->here) || (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) ) != obj)
	{	key = (type&0001000) ? obj : (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		for(r = dt->data->hh._head; r; r = r->right)
		{	k = (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
			if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) == 0)
				break;
		}
	}

	if(!r)
		return ((void*)0);
	dt->type |= 0100000;

	if(type&(0000002|0010000))
	{ dt_delete:
		if(r->right)
			r->right->hl._left = r->hl._left;
		if(r == (t = dt->data->hh._head) )
		{	dt->data->hh._head = r->right;
			if(dt->data->hh._head)
				dt->data->hh._head->hl._left = t->hl._left;
		}
		else
		{	r->hl._left->right = r->right;
			if(r == t->hl._left)
				t->hl._left = r->hl._left;
		}

		dt->data->here = r == dt->data->here ? r->right : ((Dtlink_t*)0);
		dt->data->size -= 1;

		obj = (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) );
		if(disc->freef && (type&0000002))
			(*disc->freef)(dt,obj,disc);
		if(disc->link < 0)
			(*dt->memoryf)(dt,(void*)r,0,disc);
		return obj;
	}
	else if(type&0000010)
		r = r->right;
	else if(type&0000020)
		r = r == dt->data->hh._head ? ((Dtlink_t*)0) : r->hl._left;

	dt->data->here = r;
	return r ? (lk < 0 ? ((Dthold_t*)(r))->obj : (void*)((char*)(r) - lk) ) : ((void*)0);
}




 Dtmethod_t _Dtlist  = { dtlist, 0000020  };
 Dtmethod_t _Dtdeque  = { dtlist, 0000200  };
 Dtmethod_t _Dtstack = { dtlist, 0000040 };
 Dtmethod_t _Dtqueue = { dtlist, 0000100 };

Dtmethod_t* Dtlist = &_Dtlist;
Dtmethod_t* Dtdeque = &_Dtdeque;
Dtmethod_t* Dtstack = &_Dtstack;
Dtmethod_t* Dtqueue = &_Dtqueue;




