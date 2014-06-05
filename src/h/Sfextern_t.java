package h;
import core.*;
import core.annotation.*;

// bumm5e1jowgouor1ceaaw86ho

public class Sfextern_t {
}

// typedef struct _sfextern_s {
// 	ssize_t sf_page;
// 	struct _sfpool_s sf_pool;
// 	int (*sf_pmove) _ARG_((Sfio_t *, int));
// 	Sfio_t *(*sf_stack) _ARG_((Sfio_t *, Sfio_t *));
// 	void (*sf_notify) _ARG_((Sfio_t *, int, int));
// 	int (*sf_stdsync) _ARG_((Sfio_t *));
// 	struct _sfdisc_s sf_udisc;
// 	void (*sf_cleanup) _ARG_((void));
// 	int sf_exiting;
// 	int sf_done;
// 	Vtonce_t *sf_once;
// 	void (*sf_oncef) _ARG_((void));
// 	Vtmutex_t *sf_mutex;
//     } Sfextern_t;