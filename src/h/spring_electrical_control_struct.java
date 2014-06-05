package h;
import core.*;
import core.annotation.*;

// 515eb66r64fmc2w8mec2klb0r

public class spring_electrical_control_struct {
}

// struct spring_electrical_control_struct {
//   double p;/*a negativve real number default to -1. repulsive force = dist^p */
//   double q;/*a positive real number default to 2. attractive force = dist^q */
//   int random_start;/* whether to apply SE from a random layout, or from exisiting layout */
//   double K;/* the natural distance. If K < 0, K will be set to the average distance of an edge */
//   double C;/* another parameter. f_a(i,j) = C*dist(i,j)^2/K * d_ij, f_r(i,j) = K^(3-p)/dist(i,j)^(-p). By default C = 0.2. */
//   int multilevels;/* if <=1, single level */
//   int multilevel_coarsen_scheme;/* pass on to Multilevel_control->coarsen_scheme */
//   int multilevel_coarsen_mode;/* pass on to Multilevel_control->coarsen_mode */
//   int quadtree_size;/* cut off size above which quadtree approximation is used */
//   int max_qtree_level;/* max level of quadtree */
//   double bh;/* Barnes-Hutt constant, if width(snode)/dist[i,snode] < bh, treat snode as a supernode. default 0.2*/
//   double tol;/* minimum different between two subsequence config before terminating. ||x-xold|| < tol */
//   int maxiter;
//   double cool;/* default 0.9 */
//   double step;/* initial step size */
//   int adaptive_cooling;
//   int random_seed;
//   int beautify_leaves;
//   int use_node_weights;
//   int smoothing;
//   int overlap;
//   int do_shrinking;
//   int tscheme; /* octree scheme. 0 (no octree), 1 (normal), 2 (fast) */
//   int method;/* spring_electical, spring_maxent */
//   double initial_scaling;/* how to scale the layout of the graph before passing to overlap removal algorithm.
// 			  positive values are absolute in points, negative values are relative
// 			  to average label size.
// 			  */
//   double rotation;/* degree of rotation */
//   int edge_labeling_scheme; /* specifying whether to treat node of the form |edgelabel|* as a special node representing an edge label. 
// 			       0 (no action, default), 1 (penalty based method to make that kind of node close to the center of its neighbor), 
// 			       1 (penalty based method to make that kind of node close to the old center of its neighbor),
// 			       3 (two step process of overlap removal and straightening) */
// };