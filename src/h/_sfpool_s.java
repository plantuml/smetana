package h;
import core.*;
import core.annotation.*;

// 7t65anfjbbmvljklyq9in51c4

public class _sfpool_s {
}

// struct _sfpool_s {
// 	Sfpool_t *next;
// 	int mode;		/* type of pool                 */
// 	int s_sf;		/* size of pool array           */
// 	int n_sf;		/* number currently in pool     */
// 	Sfio_t **sf;		/* array of streams             */
// 	Sfio_t *array[3];	/* start with 3                 */
// 	Vtmutex_t mutex;	/* mutex lock object            */
//     };