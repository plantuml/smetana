#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.c" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      See the LICENSE file for copyright infomation.     *
**********************************************************/


#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.c" 1


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







#line 12 "graphviz-2.38.0\\lib\\rbtree\\misc.c" 2
#line 1 "graphviz-2.38.0\\lib\\rbtree\\misc.c" 1

jmp_buf rb_jbuf;

/***********************************************************************/
/*  FUNCTION:  void Assert(int assertion, char* error)  */
/**/
/*  INPUTS: assertion should be a predicated that the programmer */
/*  assumes to be true.  If this assumption is not true the message */
/*  error is printed and the program exits. */
/**/
/*  OUTPUT: None. */
/**/
/*  Modifies input:  none */
/**/
/*  Note:  If DEBUG_ASSERT is not defined then assertions should not */
/*         be in use as they will slow down the code.  Therefore the */
/*         compiler will complain if an assertion is used when */
/*         DEBUG_ASSERT is undefined. */
/***********************************************************************/


void Assert(int assertion, char* error) {
  if(!assertion) {
    fprintf(stderr, "Assertion Failed: %s\n",error);
    longjmp(rb_jbuf, 1);
  }
}



/***********************************************************************/
/*  FUNCTION:  SafeMalloc */
/**/
/*    INPUTS:  size is the size to malloc */
/**/
/*    OUTPUT:  returns pointer to allocated memory if succesful */
/**/
/*    EFFECT:  mallocs new memory.  If malloc fails, prints error message */
/*             and terminates program. */
/**/
/*    Modifies Input: none */
/**/
/***********************************************************************/

void * SafeMalloc(size_t size) {
  void * result;

  if ( (result = malloc(size)) ) { /* assignment intentional */
    return(result);
  } else {
    fprintf(stderr, "memory overflow: malloc failed in SafeMalloc.");
    /* printf("  Exiting Program.\n"); */
    longjmp(rb_jbuf, 2);
    return(0);
  }
}
/*  NullFunction does nothing it is included so that it can be passed */
/*  as a function to RBTreeCreate when no other suitable function has */
/*  been defined */

void NullFunction(void * junk) { ; }
