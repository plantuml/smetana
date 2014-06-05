package h;
import core.*;
import core.annotation.*;

// 9ddqodn1tfzo8w3prfu6lmb4h

public class Hierarchy {
}

// typedef struct {
//     int nlevels;
//     v_data ** graphs;
//     ex_vtx_data ** geom_graphs;
//     int * nvtxs;
//     int * nedges;
//     /* Node i on level k is mapped to coarse node v2cv[k][i] on level k+1
//      */
//     int ** v2cv;
//     /* Coarse node i on level k contains nodes cv2v[k][2*i] and 
//      * cv2v[k][2*i+1] on level k-1. If it contains only 1 node, then
//      * cv2v[k][2*i+1] will be -1
//      */
//     int ** cv2v;
//     int maxNodeIndex;
// } Hierarchy;