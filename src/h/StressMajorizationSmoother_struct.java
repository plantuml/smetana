package h;
import core.*;
import core.annotation.*;

// 1dkkxromsobzdfs76xnyl2clu

public class StressMajorizationSmoother_struct {
}

// struct StressMajorizationSmoother_struct {
//   SparseMatrix D;/* distance matrix. The diagonal is removed hence the ia, ja structure is different from Lw and Lwd!! */
//   SparseMatrix Lw;/* the weighted laplacian. with offdiag = -1/w_ij */
//   SparseMatrix Lwd;/* the laplacian like matrix with offdiag = -scaling*d_ij/w_ij. RHS in stress majorization = Lwd.x */
//   double* lambda;
//   void (*data_deallocator)(void*);
//   void *data;
//   int scheme;
//   double scaling;/* scaling. It is multiplied to Lwd. need to divide coordinate x at the end of the stress majorization process */
//   double tol_cg;/* tolerance and maxit for conjugate gradient that solves the Laplacian system.
// 		 typically the Laplacian only needs to be solved very crudely as it is part of an
// 		 outer iteration.*/
//   int maxit_cg;
// };