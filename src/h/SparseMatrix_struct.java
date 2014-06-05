package h;
import core.*;
import core.annotation.*;

// awi1o5xa7rw0pq78ymqngqkys

public class SparseMatrix_struct {
}

// struct SparseMatrix_struct {
//   int m; /* row dimension */
//   int n; /* column dimension */
//   int nz;/* The actual length used is nz, for CSR/CSC matrix this is the same as ia[n] */
//   int nzmax; /* the current length of ja and a (if exists) allocated.*/
//   int type; /* whether it is real/complex matrix, or pattern only */
//   int *ia; /* row pointer for CSR format, or row indices for coordinate format. 0-based */
//   int *ja; /* column indices. 0-based */
//   void *a; /* entry values. If NULL, pattern matrix */
//   int format;/* whether it is CSR, CSC, COORD. By default it is in CSR format */
//   int property; /* pattern_symmetric/symmetric/skew/hermitian*/
//   int size;/* size of each entry. This allows for general matrix where each entry is, say, a matrix itself */
// };