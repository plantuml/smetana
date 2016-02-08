#line 1 "graphviz-2.38.0\\lib\\cdt\\dttree.c" 1
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




#line 3 "graphviz-2.38.0\\lib\\cdt\\dttree.c" 2

/*	Ordered set/multiset
**	dt:	dictionary being searched
**	obj:	the object to look for.
**	type:	search type.
**
**      Written by Kiem-Phong Vo (5/25/96)
*/


static void* dttree(Dt_t* dt, void* obj, int type)






{
	Dtlink_t	*root, *t;
	int		cmp, lk, sz, ky;
	void		*o, *k, *key;
	Dtlink_t	*l, *r, *me, link;
	int		n, minp, turn[(sizeof(size_t)*8 - 2)];
	Dtcompar_f	cmpf;
	Dtdisc_t*	disc;

	((dt->data->type&010000) ? dtrestore(dt,((Dtlink_t*)0)) : 0);
	disc = dt->disc; (ky = disc->key, sz = disc->size, lk = disc->link, cmpf = disc->comparf);
	dt->type &= ~0100000;

	root = dt->data->here;
	if(!obj)
	{	if(!root || !(type&(0000100|0000200|0000400)) )
			return ((void*)0);

		if(type&0000100) /* delete all objects */
		{	if(disc->freef || disc->link < 0)
			{	do
				{	while((t = root->hl._left) )
						(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
					t = root->right;
					if(disc->freef)
						(*disc->freef)(dt,(lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ),disc);
					if(disc->link < 0)
						(*dt->memoryf)(dt,(void*)root,0,disc);
				} while((root = t) );
			}

			dt->data->size = 0;
			dt->data->here = ((Dtlink_t*)0);
			return ((void*)0);
		}
		else /* computing largest/smallest element */
		{	if(type&0000400)
			{	while((t = root->right) )
					(((root)->right = (t)->hl._left, (t)->hl._left = (root)), (root) = (t));
			}
			else /* type&DT_FIRST */
			{	while((t = root->hl._left) )
					(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
			}

			dt->data->here = root;
			return (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) );
		}
	}

	/* note that link.right is LEFT tree and link.left is RIGHT tree */
	l = r = &link;

	/* allow apps to delete an object "actually" in the dictionary */
	if(dt->meth->type == 0000010 && (type&(0000002|0010000)) )
	{	key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		for(o = (*(((Dt_t*)(dt))->searchf))((dt),(void*)(obj),0000004); o; o = (*(((Dt_t*)(dt))->searchf))((dt),(void*)(o),0000010) )
		{	k = (void*)(sz < 0 ? *((char**)((char*)(o)+ky)) : ((char*)(o)+ky));
			if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
				break;
			if(o == obj)
			{	root = dt->data->here;
				l->right = root->hl._left;
				r->hl._left  = root->right;
				goto dt_delete;
			}
		}
	}

	if(type&(0001000|0000004|0000001|0004000))
	{	key = (type&0001000) ? obj : (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		if(root)
			goto do_search;
	}
	else if(type&0000040)
	{	me = (Dtlink_t*)obj;
		obj = (lk < 0 ? ((Dthold_t*)(me))->obj : (void*)((char*)(me) - lk) );
		key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
		if(root)
			goto do_search;
	}
	else if(root && (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ) != obj)
	{	key = (void*)(sz < 0 ? *((char**)((char*)(obj)+ky)) : ((char*)(obj)+ky));
	do_search:
		if(dt->meth->type == 0000004 &&
		   (minp = dt->data->minp) != 0 && (type&(0001000|0000004)) )
		{	/* simple search, note that minp should be even */
			for(t = root, n = 0; n < minp; ++n)
			{	k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
				if((cmp = (cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) )) == 0)
					return (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) );
				else
				{	turn[n] = cmp;	
					if(!(t = cmp < 0 ? t->hl._left : t->right) )
						return ((void*)0);
				}
			}

			/* exceed search length, top-down splay now */
			for(n = 0; n < minp; n += 2)
			{	if(turn[n] < 0)
				{	t = root->hl._left;
					if(turn[n+1] < 0)
					{	((root)->hl._left = (t)->right, (t)->right = (root));
						((r) = (r)->hl._left = (t) );
						root = t->hl._left;
					}
					else
					{	((l) = (l)->right = (t) );
						((r) = (r)->hl._left = (root) );
						root = t->right;
					}
				}
				else
				{	t = root->right;
					if(turn[n+1] > 0)
					{	((root)->right = (t)->hl._left, (t)->hl._left = (root));
						((l) = (l)->right = (t) );
						root = t->right;
					}
					else
					{	((r) = (r)->hl._left = (t) );
						((l) = (l)->right = (root) );
						root = t->hl._left;
					}
				}
			}
		}

		while(1)
		{	k = (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
			if((cmp = (cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) )) == 0)
				break;
			else if(cmp < 0)
			{	if((t = root->hl._left) )
				{	k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
					if((cmp = (cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) )) < 0)
					{	((root)->hl._left = (t)->right, (t)->right = (root));
						((r) = (r)->hl._left = (t) );
						if(!(root = t->hl._left) )
							break;
					}
					else if(cmp == 0)
					{	((r) = (r)->hl._left = (root) );
						root = t;
						break;
					}
					else /* if(cmp > 0) */
					{	((l) = (l)->right = (t) );
						((r) = (r)->hl._left = (root) );
						if(!(root = t->right) )
							break;
					}
				}
				else
				{	((r) = (r)->hl._left = (root) );
					root = ((Dtlink_t*)0);
					break;
				}
			}
			else /* if(cmp > 0) */
			{	if((t = root->right) )
				{	k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
					if((cmp = (cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) )) > 0)
					{	((root)->right = (t)->hl._left, (t)->hl._left = (root));
						((l) = (l)->right = (t) );
						if(!(root = t->right) )
							break;
					}
					else if(cmp == 0)
					{	((l) = (l)->right = (root) );
						root = t;
						break;
					}
					else /* if(cmp < 0) */
					{	((r) = (r)->hl._left = (t) );
						((l) = (l)->right = (root) );
						if(!(root = t->hl._left) )
							break;
					}
				}
				else
				{	((l) = (l)->right = (root) );
					root = ((Dtlink_t*)0);
					break;
				}
			}
		}
	}

	if(root)
	{	/* found it, now isolate it */
		dt->type |= 0100000;
		l->right = root->hl._left;
		r->hl._left = root->right;

		if(type&(0000004|0001000))
		{ has_root:
			root->hl._left = link.right;
			root->right = link.hl._left;
			if((dt->meth->type&0000010) && (type&(0000004|0001000)) )
			{	key = (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) ); key = (void*)(sz < 0 ? *((char**)((char*)(key)+ky)) : ((char*)(key)+ky));
				while((t = root->hl._left) )
				{	/* find max of left subtree */
					while((r = t->right) )
						(((t)->right = (r)->hl._left, (r)->hl._left = (t)), (t) = (r));
					root->hl._left = t;

					/* now see if it's in the same group */
					k = (lk < 0 ? ((Dthold_t*)(t))->obj : (void*)((char*)(t) - lk) ); k = (void*)(sz < 0 ? *((char**)((char*)(k)+ky)) : ((char*)(k)+ky));
					if((cmpf ? (*cmpf)(dt,key,k,disc) : (sz <= 0 ? strcmp(key,k) : memcmp(key,k,sz)) ) != 0)
						break;
					(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
				}
			}
			dt->data->here = root;
			return (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) );
		}
		else if(type&0000010)
		{	root->hl._left = link.right;
			root->right = ((Dtlink_t*)0);
			link.right = root;
		dt_next:
			if((root = link.hl._left) )	
			{	while((t = root->hl._left) )
					(((root)->hl._left = (t)->right, (t)->right = (root)), (root) = (t));
				link.hl._left = root->right;
				goto has_root;
			}
			else	goto no_root;
		}
		else if(type&0000020)
		{	root->right = link.hl._left;
			root->hl._left = ((Dtlink_t*)0);
			link.hl._left = root;
		dt_prev:
			if((root = link.right) )
			{	while((t = root->right) )
					(((root)->right = (t)->hl._left, (t)->hl._left = (root)), (root) = (t));
				link.right = root->hl._left;
				goto has_root;
			}
			else	goto no_root;
		}
		else if(type&(0000002|0010000))
		{	/* taking an object out of the dictionary */
		dt_delete:
			obj = (lk < 0 ? ((Dthold_t*)(root))->obj : (void*)((char*)(root) - lk) );
			if(disc->freef && (type&0000002))
				(*disc->freef)(dt,obj,disc);
			if(disc->link < 0)
				(*dt->memoryf)(dt,(void*)root,0,disc);
			if((dt->data->size -= 1) < 0)
				dt->data->size = -1;
			goto no_root;
		}
		else if(type&(0000001|0004000))
		{	if(dt->meth->type&0000004)
				goto has_root;
			else
			{	root->hl._left = ((Dtlink_t*)0);
				root->right = link.hl._left;
				link.hl._left = root;
				goto dt_insert;
			}
		}
		else if(type&0000040) /* a duplicate */
		{	if(dt->meth->type&0000004)
			{	if(disc->freef)
					(*disc->freef)(dt,obj,disc);
				if(disc->link < 0)
					(*dt->memoryf)(dt,(void*)me,0,disc);
			}
			else
			{	me->hl._left = ((Dtlink_t*)0);
				me->right = link.hl._left;
				link.hl._left = me;
				dt->data->size += 1;
			}
			goto has_root;
		}
	}
	else
	{	/* not found, finish up LEFT and RIGHT trees */
		r->hl._left = ((Dtlink_t*)0);
		l->right = ((Dtlink_t*)0);

		if(type&0000010)
			goto dt_next;
		else if(type&0000020)
			goto dt_prev;
		else if(type&(0000004|0001000))
		{ no_root:
			while((t = r->hl._left) )
				r = t;
			r->hl._left = link.right;
			dt->data->here = link.hl._left;
			return (type&0000002) ? obj : ((void*)0);
		}
		else if(type&(0000001|0004000))
		{ dt_insert:
			if(disc->makef && (type&0000001))
				obj = (*disc->makef)(dt,obj,disc);
			if(obj)
			{	if(lk >= 0)
					root = ((Dtlink_t*)((char*)(obj) + lk) );
				else
				{	root = (Dtlink_t*)(*dt->memoryf)
						(dt,((void*)0),sizeof(Dthold_t),disc);
					if(root)
						((Dthold_t*)root)->obj = obj;
					else if(disc->makef && disc->freef &&
						(type&0000001))
						(*disc->freef)(dt,obj,disc);
				}
			}
			if(root)
			{	if(dt->data->size >= 0)
					dt->data->size += 1;
				goto has_root;
			}
			else	goto no_root;
		}
		else if(type&0000040)
		{	root = me;
			dt->data->size += 1;
			goto has_root;
		}
		else /*if(type&DT_DELETE)*/
		{	obj = ((void*)0);
			goto no_root;
		}
	}

	return ((void*)0);
}

/* make this method available */
static Dtmethod_t	_Dtoset =  { dttree, 0000004 };
static Dtmethod_t	_Dtobag =  { dttree, 0000010 };
Dtmethod_t* Dtoset = &_Dtoset;
Dtmethod_t* Dtobag = &_Dtobag;


Dtmethod_t		_Dttree = { dttree, 0000004 };
Dtmethod_t* Dtorder = &_Dttree;
Dtmethod_t* Dttree = &_Dttree;





