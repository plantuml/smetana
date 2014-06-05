package h;
import core.*;
import core.annotation.*;

// 3cl38y4ai8c9r6d23izdf6jgn

public class rank_t {
}

// typedef struct rank_t {
// 	int n;			/* number of nodes in this rank  */
// 	node_t **v;		/* ordered list of nodes in rank    */
// 	int an;			/* globally allocated number of nodes   */
// 	node_t **av;		/* allocated list of nodes in rank  */
// 	double ht1, ht2;	/* height below/above centerline    */
// 	double pht1, pht2;	/* as above, but only primitive nodes   */
// 	boolean candidate;	/* for transpose () */
// 	boolean valid;
// 	int cache_nc;		/* caches number of crossings */
// 	adjmatrix_t *flat;
//     } rank_t;