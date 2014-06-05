package h;
import core.*;
import core.annotation.*;

// 5azjs54pjx1yjvjt4rvmoix77

public class Vmextern_t {
}

// typedef struct _vmextern_ {
// 	Block_t *(*vm_extend) _ARG_((Vmalloc_t *, size_t, Vmsearch_f));
// 	int (*vm_truncate) _ARG_((Vmalloc_t *, Seg_t *, size_t, int));
// 	size_t vm_pagesize;
// 	char *(*vm_strcpy) _ARG_((char *, char *, int));
// 	char *(*vm_itoa) _ARG_((Vmulong_t, int));
// 	void (*vm_trace) _ARG_((Vmalloc_t *,
// 				Vmuchar_t *, Vmuchar_t *, size_t, size_t));
// 	void (*vm_pfclose) _ARG_((Vmalloc_t *));
//     } Vmextern_t;