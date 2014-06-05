package h;
import core.*;
import core.annotation.*;

// 9530x4kxezum2n33pirh5xejb

public class ex_vtx_data {
}

// typedef struct {
//     int nedges;       // degree, including self-loop
//     int *edges;       // neighbors; edges[0] = self
//     int size;         // no. of original nodes contained
//     int active_level; // Node displayed iff active_level == node's level
//     int globalIndex;  // Each node has a unique ID over all levels
// 
//     // position of node in universal coordinate system
//     float x_coord;
//     float y_coord;
// 
//     // position of node in physical (device) coordinate system
//     float physical_x_coord;
//     float physical_y_coord;	
// 	//previous coords and active level (for animation)
//     float old_physical_x_coord;
//     float old_physical_y_coord;	
// 	int old_active_level;
// 
// 
// } ex_vtx_data;