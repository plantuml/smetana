package h;
import core.*;
import core.annotation.*;

// c29ex11zecl98njycdm339n7z

public class _head_s {
}

// struct _head_s {
// 	union {
// 	    Seg_t *seg;		/* the containing segment       */
// 	    Block_t *link;	/* possible link list usage     */
// 	    Pfobj_t *pf;	/* profile structure pointer    */
// 	    char *file;		/* for file name in Vmdebug     */
// 	} seg;
// 	union {
// 	    size_t size;	/* size of data area in bytes   */
// 	    Block_t *link;	/* possible link list usage     */
// 	    int line;		/* for line number in Vmdebug   */
// 	} size;
//     };