package h;
import core.*;
import core.annotation.*;

// 8reykx9ipp7zhrcjg3ymu8ypm

public class Agnodeinfo_t {
}

// typedef struct Agnodeinfo_t {
// 	Agrec_t hdr;
// 	shape_desc *shape;
// 	void *shape_info;
// 	pointf coord;
// 	double width, height;  /* inches */
// 	boxf bb;
// 	double ht, lw, rw;
// 	textlabel_t *label;
// 	textlabel_t *xlabel;
// 	void *alg;
// 	char state;
// 	unsigned char gui_state; /* Node state for GUI ops */
// 	boolean clustnode;
// 
// 
// 	
// 	
// 	
// 
// 
// 	unsigned char showboxes;
// 	boolean  has_port;
// 	node_t* rep;
// 	node_t *set;
// 
// 	/* fast graph */
// 	char node_type, mark, onstack;
// 	char ranktype, weight_class;
// 	node_t *next, *prev;
// 	elist in, out, flat_out, flat_in, other;
// 	graph_t *clust;
// 
// 	/* for union-find and collapsing nodes */
// 	int UF_size;
// 	node_t *UF_parent;
// 	node_t *inleaf, *outleaf;
// 
// 	/* for placing nodes */
// 	int rank, order;	/* initially, order = 1 for ordered edges */
// 	double mval;
// 	elist save_in, save_out;
// 
// 	/* for network-simplex */
// 	elist tree_in, tree_out;
// 	edge_t *par;
// 	int low, lim;
// 	int priority;
// 
// 	double pad[1];
// 
// 
//     } Agnodeinfo_t;