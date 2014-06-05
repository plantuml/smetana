package h;
import core.*;
import core.annotation.*;

// c7a9je6j2c3t51hnsiowf1vua

public class relative_position_constraints_struct {
}

// struct relative_position_constraints_struct{
//   double constr_penalty; /* penalty parameter used in making edge labels as much on the line as possible */
//   int edge_labeling_scheme;/* specifying whether to treat node of the form |edgelabel|* as a special node representing an edge label. 
// 			       0 (no action, default), 1 (penalty based method to make that kind of node close to the center of its neighbor), 
// 			       2 (penalty based method to make that kind of node close to the "old" center of its neighbor), 
// 			       3 (two step process of overlap removal and straightening) */
//   int n_constr_nodes;/*n_constr_nodes: number of nodes that has constraints, these are nodes that is
// 		       constrained to be close to the average of its neighbors.*/
//   int *constr_nodes;/*constr_nodes: a list of nodes that need to be constrained. If NULL, unused.*/
//   int *irn;/* working arrays to hold the Laplacian of the constrain graph */
//   int *jcn;
//   double *val;
//   SparseMatrix A_constr; /*A_constr: neighbors of node i are in the row i of this matrix. i needs to sit
// 			   in between these neighbors as much as possible. this must not be NULL
// 			   if constr_nodes != NULL.*/
//   
// };