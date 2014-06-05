#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\sparse\\LinkedList.h" 1
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




typedef struct SingleLinkedList_struct* SingleLinkedList;

struct SingleLinkedList_struct {
  void *data;
  SingleLinkedList next;
};

SingleLinkedList SingleLinkedList_new(void *data);
SingleLinkedList SingleLinkedList_new_int(int i);
void SingleLinkedList_delete(SingleLinkedList head, void (*linklist_deallocator)(void*));
SingleLinkedList SingleLinkedList_prepend(SingleLinkedList l, void *data);
SingleLinkedList SingleLinkedList_prepend_int(SingleLinkedList l, int i);

void* SingleLinkedList_get_data(SingleLinkedList l);

SingleLinkedList SingleLinkedList_get_next(SingleLinkedList l);

void SingleLinkedList_print(SingleLinkedList head, void (*linkedlist_print)(void*));


typedef struct DoubleLinkedList_struct* DoubleLinkedList;

struct DoubleLinkedList_struct {
  void *data;
  DoubleLinkedList next;
  DoubleLinkedList prev;
};

DoubleLinkedList DoubleLinkedList_new(void *data);
void DoubleLinkedList_delete(DoubleLinkedList head, void (*linklist_deallocator)(void*));
DoubleLinkedList DoubleLinkedList_prepend(DoubleLinkedList l, void *data);

void* DoubleLinkedList_get_data(DoubleLinkedList l);

DoubleLinkedList DoubleLinkedList_get_next(DoubleLinkedList l);

void DoubleLinkedList_delete_element(DoubleLinkedList l,  void (*linklist_deallocator)(void*), DoubleLinkedList *head);

#line 16 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.h" 1


#line 1 "graphviz-2.38.0\\lib\\sparse\\LinkedList.h" 1
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







  
  


















  
  
  












#line 3 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.h" 2
struct PriorityQueue_struct {
  /* a simple priority queue structure: entries are all integers, gains are all integers in [0, gainmax], total n elements */
  int count;/* how many entries are in?*/

  /* max index value of an entry */
  int n;

  /* only ngain buckets are allowed */
  int ngain;

  /* current highest gain */
  int gain_max;

  /* the ngain buckets. Each bucket i holds all entries with gain = i.*/
  DoubleLinkedList *buckets;

  /* a mapping which maps an entry's index to an element in a DoubleLinkedList */
  DoubleLinkedList *where;

  /* the gain of entry i is gain[i] */
  int *gain;
};

typedef struct PriorityQueue_struct *PriorityQueue;


PriorityQueue PriorityQueue_new(int n, int ngain);

void PriorityQueue_delete(PriorityQueue q);

/* if entry i is already in the list, then an update of gain is carried out*/
PriorityQueue PriorityQueue_push(PriorityQueue q, int i, int gain);

int PriorityQueue_pop(PriorityQueue q, int *i, int *gain);/* return 0 if nmothing left, 1 otherwise */

int PriorityQueue_remove(PriorityQueue q, int i);/* return 0 if error */
int PriorityQueue_get_gain(PriorityQueue q, int i);


#line 17 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1






































    extern void *zmalloc(size_t);
    extern void *zrealloc(void *, size_t, size_t, size_t);
    extern void *gmalloc(size_t);
	extern void *grealloc(void *, size_t);







#line 18 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\logic.h" 1
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


















































#line 19 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 2
#line 1 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 1
#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
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

/* geometric functions (e.g. on points and boxes) with application to, but
 * no specific dependance on graphs */




/* for sincos */




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1



#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
































































    









#line 21 "graphviz-2.38.0\\lib\\sfdpgen\\PriorityQueue.c" 2







PriorityQueue PriorityQueue_new(int n, int ngain){
  PriorityQueue q;
  int i;
  q = (struct PriorityQueue_struct*)gmalloc((1)*sizeof(struct PriorityQueue_struct));
  q->count = 0;
  q->n = n;
  q->ngain = ngain;
  q->gain_max = -1;/* no entries yet */
  q->buckets = (DoubleLinkedList*)gmalloc(((ngain+1))*sizeof(DoubleLinkedList));
  for (i = 0; i < ngain+1; i++) (q->buckets)[i] = (void *)0;

  q->where = (DoubleLinkedList*)gmalloc(((n+1))*sizeof(DoubleLinkedList));
  for (i = 0; i < n+1; i++) (q->where)[i] = (void *)0;

  q->gain = (int*)gmalloc(((n+1))*sizeof(int));
  for (i = 0; i < n+1; i++) (q->gain)[i] = -999;
  return q;

}

void PriorityQueue_delete(PriorityQueue q){
  int i;

  if (q){
    if (q->buckets){
      for (i = 0; i < q->ngain+1; i++) DoubleLinkedList_delete((q->buckets)[i], free);
      free(q->buckets);
    }

    if (q->where){
      free(q->where);
    }

    free(q->gain);
    free(q);
  }
}

PriorityQueue PriorityQueue_push(PriorityQueue q, int i, int gain){
  DoubleLinkedList l;
  int *data, gainold;

  assert(q);
  assert(gain <= q->ngain);


  if (!(q->where)[i]){
    /* this entry is no in the queue yet, so this is a new addition */

    (q->count)++;
    if (gain > q->gain_max) q->gain_max = gain;
    q->gain[i] = gain;

    data = (int*)gmalloc((1)*sizeof(int));
    data[0] = i;
    if ((l = (q->buckets)[gain])){
      (q->buckets)[gain] = (q->where)[i] = DoubleLinkedList_prepend(l, data);
    } else {
      (q->buckets)[gain] = (q->where)[i] = DoubleLinkedList_new(data);
    }

  } else {
    /* update gain for an exisiting entry */
    l = q->where[i];
    gainold = q->gain[i];
    q->where[i] = (void *)0; 
    (q->count)--;
    DoubleLinkedList_delete_element(l, free, &((q->buckets)[gainold]));
    return PriorityQueue_push(q, i, gain);
  }
  return q;
}

int PriorityQueue_pop(PriorityQueue q, int *i, int *gain){
  int gain_max;
  DoubleLinkedList l;
  int *data;

  if (!q || q->count <= 0) return 0;
  *gain = gain_max = q->gain_max;
  (q->count)--;
  l = (q->buckets)[gain_max];
  data = (int*) DoubleLinkedList_get_data(l);
  *i = data[0];

  DoubleLinkedList_delete_element(l, free, &((q->buckets)[gain_max]));
  if (!(q->buckets)[gain_max]){/* the bin that contain the best gain is empty now after poping */
    while (gain_max >= 0 && !(q->buckets)[gain_max]) gain_max--;
    q->gain_max = gain_max;
  }
  q->where[*i] = (void *)0;
  q->gain[*i] = -999;
  return 1;
}




int PriorityQueue_get_gain(PriorityQueue q, int i){
  return q->gain[i];
}

int PriorityQueue_remove(PriorityQueue q, int i){
  /* remove an entry from the queue. If error, return 0. */
  int gain, gain_max;
  DoubleLinkedList l;

  if (!q || q->count <= 0) return 0;
  gain = q->gain[i];
  (q->count)--;
  l = (q->where)[i];

  DoubleLinkedList_delete_element(l, free, &((q->buckets)[gain]));

  if (gain == (gain_max = q->gain_max) && !(q->buckets)[gain_max]){/* the bin that contain the best gain is empty now after poping */
    while (gain_max >= 0 && !(q->buckets)[gain_max]) gain_max--;
    q->gain_max = gain_max;
  }
  q->where[i] = (void *)0;
  q->gain[i] = -999;
  return 1;
}

/*

main(){
  int i, gain;

    
    PriorityQueue q;
    q = PriorityQueue_new(10,100);
    PriorityQueue_push(q, 3, 1);
    PriorityQueue_push(q, 2, 2);
    PriorityQueue_push(q, 4, 2);
    PriorityQueue_push(q, 5, 2);
    PriorityQueue_push(q, 1, 100);
    PriorityQueue_push(q, 2,  1);
    while (PriorityQueue_pop(q, &i, &gain)){
      printf("i = %d gain = %d\n", i, gain);
    }
    
    printf("=========\n");
    PriorityQueue_push(q, 3, 1);
    PriorityQueue_push(q, 2, 2);
    PriorityQueue_push(q, 4, 2);
    PriorityQueue_push(q, 5, 2);
    PriorityQueue_push(q, 1, 100);
    PriorityQueue_push(q, 2,  1);
    PriorityQueue_push(q, 2,  100);
    while (PriorityQueue_pop(q, &i, &gain)){
      printf("i = %d gain = %d\n", i, gain);
    }


    printf("====after removing 3 and 2 =====\n");
    PriorityQueue_push(q, 3, 1);
    PriorityQueue_push(q, 2, 2);
    PriorityQueue_push(q, 4, 2);
    PriorityQueue_push(q, 5, 2);
    PriorityQueue_push(q, 1, 100);
    PriorityQueue_push(q, 2,  1);
    PriorityQueue_push(q, 2,  100);
    PriorityQueue_remove(q, 3);
    PriorityQueue_remove(q, 2);
    while (PriorityQueue_pop(q, &i, &gain)){
      printf("i = %d gain = %d\n", i, gain);
    }
    PriorityQueue_delete(q);

}

*/
