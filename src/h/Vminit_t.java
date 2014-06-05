package h;
import core.*;
import core.annotation.*;

// 43j7vrrlw9ks1b8y5itvl73nh

public class Vminit_t {
}

// typedef struct _vminit_ {
//     Vmdata_t vd;		/* space for the region itself  */
//     Seg_t seg;			/* space for segment            */
//     Block_t block;		/* space for a block            */
//     Head_t head;		/* space for the fake header    */
//     char a[3 * sizeof(struct _align_s)];		/* extra to fuss with alignment */
// } Vminit_t;