package h;
import core.*;
import core.annotation.*;

// 1xkckec5twdmtzk9s8ebfloqt

public class mcnodeinfo_t {
}

// typedef struct {
//     Agrec_t hdr;
//     node_t  *set;                           /* for union-find */
//     graph_t *cluster;                       /* lowest containing cluster */
//     union {
// 	node_t  *v;
// 	edge_t  *e;
// 	graph_t *g;
//     } rep;
//     Agnode_t* orig;
//     int     type;
//     int     rank;
//     int     order;
//     float orderr;
//     mcNode* mcn;
//     graph_t *highCluster;                   /* highest containing cluster */
//     int inBucket;
// } mcnodeinfo_t;