package h;
import core.*;
import core.annotation.*;

// 7o9hf8flgcfueijigsvihjjf7

public class pedge_struct {
}

// struct pedge_struct {
//   double wgt; /* weight, telling how many original edges this edge represent. If this edge consists of multiple sections of different weights then this is a lower bound. This only applied for agglomerative bundling */
//   int npoints;/* number of poly points */
//   int len;/* length of arra x. len >= npoints */
//   int dim;/* dim >= 2. Point i is stored from x[i*dim]*/
//   double edge_length;
//   double *x;/* coordinates of the npoints poly points. Dimension dim*npoints */
//   double *wgts;/* number of original edges each section represnet. Dimension npoint - 1. This only applied for agglomerative bundling Null for other methods */
// };