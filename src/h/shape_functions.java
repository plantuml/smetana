package h;
import core.*;
import core.annotation.*;

// 5mip14tura2l8b750vykgeun3

public class shape_functions {
}

// typedef struct shape_functions {	/* read-only shape functions */
// 	void (*initfn) (node_t *);	/* initializes shape from node u.shape_info structure */
// 	void (*freefn) (node_t *);	/* frees  shape from node u.shape_info structure */
// 	 port(*portfn) (node_t *, char *, char *);	/* finds aiming point and slope of port */
// 	 boolean(*insidefn) (inside_t * inside_context, pointf);	/* clips incident gvc->e spline on shape of gvc->n */
// 	int (*pboxfn)(node_t* n, port* p, int side, boxf rv[], int *kptr); /* finds box path to reach port */
// 	void (*codefn) (GVJ_t * job, node_t * n);	/* emits graphics code for node */
//     } shape_functions;