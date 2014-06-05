package h;
import core.*;
import core.annotation.*;

// 39c66ffd2kgahvaaf8e61dspv

public class cdata {
}

// typedef struct {
//     union {			/* Pointer to node/cluster in original graph */
// 	Agraph_t *g;
// 	Agnode_t *np;
//     } orig;
//     int flags;
//     node_t *parent;		/* parent in block-cutpoint traversal (1,2,4) */
//     block_t *block;		/* Block containing node (1,2,3,4) */
//     union {
// 	struct {		/* Pass  1 */
// 	    node_t *next;	/* used for stack */
// 	    int val;
// 	    int low_val;
// 	} bc;
// 	node_t *clone;		/* Cloned node (3a) */
// 	struct {		/* Spanning tree and longest path (3b) */
// 	    node_t *tparent;	/* Parent in tree */
// 	    node_t *first;	/* Leaf on longest path from node */
// 	    node_t *second;	/* Leaf on 2nd longest path from node */
// 	    int fdist;		/* Length of longest path from node */
// 	    int sdist;		/* Length of 2nd longest path from node */
// 	} t;
// 	struct {
// 	    int pos;		/* Index of node in block circle (3c,4) */
// 	    double psi;		/* Offset angle of children (4) */
// 	} f;
//     } u;
// } cdata;