package h;
import core.*;
import core.annotation.*;

// 66ut8l8mzo1tel6q4r1626z3b

public class Vmdata_t {
}

// typedef struct _vmdata_s {
// 	int mode;		/* current mode for region              */
// 	size_t incr;		/* allocate in multiple of this         */
// 	size_t pool;		/* size of an elt in a Vmpool region    */
// 	Seg_t *seg;		/* list of segments                     */
// 	Block_t *free;		/* most recent free block               */
// 	Block_t *wild;		/* wilderness block                     */
// 	Block_t *root;		/* root of free tree                    */
// 	Block_t *tiny[7];	/* small blocks                         */
// 	Block_t *cache[7 + 1];	/* delayed free blocks                */
//     } Vmdata_t;