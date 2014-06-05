#line 1 "graphviz-2.38.0\\lib\\rbtree\\stack.c" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      See the LICENSE file for copyright infomation.     *
**********************************************************/


#line 1 "graphviz-2.38.0\\lib\\rbtree\\stack.c" 1


#line 1 "graphviz-2.38.0\\lib\\rbtree\\stack.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */
    
/**********************************************************
*      See the LICENSE file for copyright infomation.     *
**********************************************************/
    







/* needed for intptr_t */

#line 1 "graphviz-2.38.0\\lib\\rbtree\\stack.h" 1








#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      See the LICENSE file for copyright infomation.     *
**********************************************************/








#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.h" 1
#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.h" 1

extern jmp_buf rb_jbuf;

/*  CONVENTIONS:  All data structures for red-black trees have the prefix */
/*                "rb_" to prevent name conflicts. */
/*                                                                      */
/*                Function names: Each word in a function name begins with */
/*                a capital letter.  An example funcntion name is  */
/*                CreateRedTree(a,b,c). Furthermore, each function name */
/*                should begin with a capital letter to easily distinguish */
/*                them from variables. */
/*                                                                     */
/*                Variable names: Each word in a variable name begins with */
/*                a capital letter EXCEPT the first letter of the variable */
/*                name.  For example, int newLongInt.  Global variables have */
/*                names beginning with "g".  An example of a global */
/*                variable name is gNewtonsConstant. */

void Assert(int assertion, char* error);
void * SafeMalloc(size_t size);







#line 14 "graphviz-2.38.0\\lib\\rbtree\\stack.h" 2

/*  CONVENTIONS:  All data structures for stacks have the prefix */
/*                "stk_" to prevent name conflicts. */
/*                                                                      */
/*                Function names: Each word in a function name begins with */
/*                a capital letter.  An example funcntion name is  */
/*                CreateRedTree(a,b,c). Furthermore, each function name */
/*                should begin with a capital letter to easily distinguish */
/*                them from variables. */
/*                                                                     */
/*                Variable names: Each word in a variable name begins with */
/*                a capital letter EXCEPT the first letter of the variable */
/*                name.  For example, int newLongInt.  Global variables have */
/*                names beginning with "g".  An example of a global */
/*                variable name is gNewtonsConstant. */

/*  if DATA_TYPE is undefined then stack.h and stack.c will be code for */
/*  stacks of void *, if they are defined then they will be stacks of the */
/*  appropriate data_type */





typedef struct stk_stack_node {
  void * info;
  struct stk_stack_node * next;
} stk_stack_node;

typedef struct stk_stack { 
  stk_stack_node * top;
  stk_stack_node * tail;
} stk_stack ;

/*  These functions are all very straightforward and self-commenting so */
/*  I didn't think additional comments would be useful */
stk_stack * StackJoin(stk_stack * stack1, stk_stack * stack2);
stk_stack * StackCreate(void);
void StackPush(stk_stack * theStack, void * newInfoPointer);
void * StackPop(stk_stack * theStack);
intptr_t StackNotEmpty(stk_stack *);






#line 12 "graphviz-2.38.0\\lib\\rbtree\\stack.c" 2

intptr_t StackNotEmpty(stk_stack * theStack) {
  return( theStack ? (intptr_t) theStack->top : 0);
}

stk_stack * StackJoin(stk_stack * stack1, stk_stack * stack2) {
  if (!stack1->tail) {
    free(stack1);
    return(stack2);
  } else {
    stack1->tail->next=stack2->top;
    stack1->tail=stack2->tail;
    free(stack2);
    return(stack1);
  }
}

stk_stack * StackCreate() {
  stk_stack * newStack;
  
  newStack=(stk_stack *) SafeMalloc(sizeof(stk_stack));
  newStack->top=newStack->tail=NULL;
  return(newStack);
}


void StackPush(stk_stack * theStack, void * newInfoPointer) {
  stk_stack_node * newNode;

  if(!theStack->top) {
    newNode=(stk_stack_node *) SafeMalloc(sizeof(stk_stack_node));
    newNode->info=newInfoPointer;
    newNode->next=theStack->top;
    theStack->top=newNode;
    theStack->tail=newNode;
  } else {
    newNode=(stk_stack_node *) SafeMalloc(sizeof(stk_stack_node));
    newNode->info=newInfoPointer;
    newNode->next=theStack->top;
    theStack->top=newNode;
  }
  
}

void * StackPop(stk_stack * theStack) {
  void * popInfo;
  stk_stack_node * oldNode;

  if(theStack->top) {
    popInfo=theStack->top->info;
    oldNode=theStack->top;
    theStack->top=theStack->top->next;
    free(oldNode);
    if (!theStack->top) theStack->tail=NULL;
  } else {
    popInfo=NULL;
  }
  return(popInfo);
}

void StackDestroy(stk_stack * theStack,void DestFunc(void * a)) {
  stk_stack_node * x=theStack->top;
  stk_stack_node * y;

  if(theStack) {
    while(x) {
      y=x->next;
      DestFunc(x->info);
      free(x);
      x=y;
    }
    free(theStack);
  }
} 
    
