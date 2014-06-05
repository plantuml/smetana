#line 1 "graphviz-2.38.0\\lib\\sparse\\mq.c" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Modularity Quality definitation:

   We assume undirected graph. Directed graph should be converted by summing edge weights.

   Given a partition P of V into k clusters.

   Let E(i,j) be the set of edges between cluster i and j.
   Let |E(i,j)| be the sum of edge weights of edges in E(i,j).

   Let E(i,i) be the set of edges within cluster i, but excluding self-edges.
   Let |E(i,i)| be the sum of edge weights of edges in E(i,i).

   Let V(i) be the sets of vertices in i

   The intra-cluster edges concentration for a cluster i is 
   (the denominator could be |V(i)|*(|V(i)-1)/2 strictly speaking as we exclude self-edges):

     |E(i,i)|
   -----------
   (|V(i)|^2/2)

   The inter-cluster edges concentration between cluster i and j is

     |E(i,j)|
   ------------
   |V(i)|*|V(j)|

   So the cluster index is defined as the average intra cluster edge concentration, minus
   the inter-cluster edge concentration:

   .                               |E(i,i)|                                        |E(i,j)|
   MQ(P) = (1/k) * \sum_{i=1...k} ------------ - (1/(k*(k-1)/2)) * \sum_{i<j} ------------------- = mq_in/k - mq_out/(k*(k-1)/2)
   .                              (|V(i)|^2/2)                                   |V(i)|*|V(j)|

   or

   .                                 |E(i,i)|                                     |E(i,j)|
   MQ(P)/2 = (1/k) * \sum_{i=1...k} ------------ - (1/(k*(k-1))) * \sum_{i<j} ------------------ = mq_in/k - mq_out/(k*(k-1))
   .                                |V(i)|^2                                   |V(i)|*|V(j)|

   Notice that if we assume the graph is unweights (edge weights = 1), then 0<= MQ <= 1.
   For weighted graph, MQ may not be within 0 to 1. We could normalized it, but 
   for comparing clustering quality of the same graph but different partitioning, this 
   unnormalized quantity is not a problem.

*/


#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
/* Applications that do not use the common library can define STANDALONE
 * to get definitions/definitions that are normally provided there.
 * In particular, note that Verbose is declared but undefined.
 */







































typedef unsigned int boolean;
extern unsigned char Verbose;




















extern int irand(int n);
extern double drand(void);
extern int *random_permutation(int n);/* random permutation of 0 to n-1 */


double* vector_subtract_to(int n, double *x, double *y);/* y = x-y */
double* vector_subtract_from(int n, double *x, double *y);/* y = y-x */
double* vector_add_to(int n, double *x, double *y);

double vector_product(int n, double *x, double *y);

double* vector_saxpy(int n, double *x, double *y, double beta); /* y = x+beta*y */


double* vector_saxpy2(int n, double *x, double *y, double beta);/* x = x+beta*y */

/* take m elements v[p[i]]],i=1,...,m and oput in u. u will be assigned if *u = NULL */
void vector_take(int n, double *v, int m, int *p, double **u);
void vector_float_take(int n, float *v, int m, int *p, float **u);

/* give the position of the lagest, second largest etc in vector v if ascending = TRUE
   or
   give the position of the smallest, second smallest etc  in vector v if ascending = TRUE.
   results in p. If *p == NULL, p is asigned.
*/
void vector_ordering(int n, double *v, int **p, int ascending);
void vector_sort_real(int n, double *v, int ascending);
void vector_sort_int(int n, int *v, int ascending);
double vector_median(int n, double *x);
double vector_percentile(int n, double *x, double y);/* find the value such that y% of element of vector x is <= that value.*/

void vector_print(char *s, int n, double *x);





int excute_system_command3(char *s1, char *s2, char *s3);
int excute_system_command(char *s1, char *s2);



enum {UNMATCHED = -1};


double distance(double *x, int dim, int i, int j);
double distance_cropped(double *x, int dim, int i, int j);

double point_distance(double *p1, double *p2, int dim);

char *strip_dir(char *s);

void scale_to_box(double xmin, double ymin, double xmax, double ymax, int n, int dim, double *x);

/* check to see if this is a string is integer (that can be casted into an integer variable hence very long list of digits are not valid, like 123456789012345. Return 1 if true, 0 if false. */
int validQ_int_string(char *to_convert, int *v);

/* check to see if this is a string of digits consists of 0-9 */
int digitsQ(char *to_convert);





#line 63 "graphviz-2.38.0\\lib\\sparse\\mq.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/



#line 1 "graphviz-2.38.0\\lib\\sparse\\general.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/










































































































































#line 16 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\SparseMatrix.h" 1


enum {FORMAT_CSC, FORMAT_CSR, FORMAT_COORD};
enum {UNMASKED = -10, MASKED = 1};
enum {MATRIX_PATTERN_SYMMETRIC = 1<<0, MATRIX_SYMMETRIC = 1<<1, MATRIX_SKEW = 1<<2, MATRIX_HERMITIAN = 1<<3, MATRIX_UNDIRECTED = 1<<4};
enum {BIPARTITE_RECT = 0, BIPARTITE_PATTERN_UNSYM, BIPARTITE_UNSYM, BIPARTITE_ALWAYS};


struct SparseMatrix_struct {
  int m; /* row dimension */
  int n; /* column dimension */
  int nz;/* The actual length used is nz, for CSR/CSC matrix this is the same as ia[n] */
  int nzmax; /* the current length of ja and a (if exists) allocated.*/
  int type; /* whether it is real/complex matrix, or pattern only */
  int *ia; /* row pointer for CSR format, or row indices for coordinate format. 0-based */
  int *ja; /* column indices. 0-based */
  void *a; /* entry values. If NULL, pattern matrix */
  int format;/* whether it is CSR, CSC, COORD. By default it is in CSR format */
  int property; /* pattern_symmetric/symmetric/skew/hermitian*/
  int size;/* size of each entry. This allows for general matrix where each entry is, say, a matrix itself */
};

typedef struct SparseMatrix_struct* SparseMatrix;

enum {MATRIX_TYPE_REAL = 1<<0, MATRIX_TYPE_COMPLEX = 1<<1, MATRIX_TYPE_INTEGER = 1<<2, MATRIX_TYPE_PATTERN = 1<<3, MATRIX_TYPE_UNKNOWN = 1<<4};

/* SparseMatrix_general is more general and allow elements to be 
   any data structure, not just real/int/complex etc */
SparseMatrix SparseMatrix_new(int m, int n, int nz, int type, int format);
SparseMatrix SparseMatrix_general_new(int m, int n, int nz, int type, size_t sz, int format);

/* this version sum repeated entries */
SparseMatrix SparseMatrix_from_coordinate_format(SparseMatrix A);
/* what_to_sum is SUM_REPEATED_NONE, SUM_REPEATED_ALL, SUM_REPEATED_REAL_PART, SUM_REPEATED_IMAGINARY_PART, SUM_IMGINARY_KEEP_LAST_REAL*/
SparseMatrix SparseMatrix_from_coordinate_format_not_compacted(SparseMatrix A, int what_to_sum);

SparseMatrix SparseMatrix_from_coordinate_arrays(int nz, int m, int n, int *irn, int *jcn, void *val, int type, size_t sz);
SparseMatrix SparseMatrix_from_coordinate_arrays_not_compacted(int nz, int m, int n, int *irn, int *jcn, void *val, int type, size_t sz, int what_to_sum);


void SparseMatrix_print(char *, SparseMatrix A);/*print to stdout in Mathematica format*/

void SparseMatrix_export(FILE *f, SparseMatrix A);/* export into MM format except the header */

SparseMatrix SparseMatrix_import_binary(char *name);
SparseMatrix SparseMatrix_import_binary_fp(FILE *f);/* import into a preopenned file */

void SparseMatrix_export_binary(char *name, SparseMatrix A, int *flag);
void SparseMatrix_export_binary_fp(FILE *f, SparseMatrix A);/* export binary into a file preopened */

void SparseMatrix_delete(SparseMatrix A);

SparseMatrix SparseMatrix_add(SparseMatrix A, SparseMatrix B);
SparseMatrix SparseMatrix_multiply(SparseMatrix A, SparseMatrix B);
SparseMatrix SparseMatrix_multiply3(SparseMatrix A, SparseMatrix B, SparseMatrix C);

/* For complex matrix:
   if what_to_sum = SUM_REPEATED_REAL_PART, we find entries {i,j,x + i y} and sum the x's if {i,j,Round(y)} are the same
   if what_to_sum = SUM_REPEATED_IMAGINARY_PART, we find entries {i,j,x + i y} and sum the y's if {i,j,Round(x)} are the same
   For other matrix, what_to_sum = SUM_REPEATED_REAL_PART is the same as what_to_sum = SUM_REPEATED_IMAGINARY_PART
   or what_to_sum = SUM_REPEATED_ALL
   if what_to_sum = SUM_IMGINARY_KEEP_LAST_REAL, we merge {i,j,R1,I1} and {i,j,R2,I2} into {i,j,R1+R2,I2}. Useful if I1 and I2 are time stamps, 
   .   and we use this to indicate that a user watched R1+R2 seconds, last watch is I2.
*/
enum {SUM_REPEATED_NONE = 0, SUM_REPEATED_ALL, SUM_REPEATED_REAL_PART, SUM_REPEATED_IMAGINARY_PART, SUM_IMGINARY_KEEP_LAST_REAL};
SparseMatrix SparseMatrix_sum_repeat_entries(SparseMatrix A, int what_to_sum);
SparseMatrix SparseMatrix_coordinate_form_add_entries(SparseMatrix A, int nentries, int *irn, int *jcn, void *val);
int SparseMatrix_is_symmetric(SparseMatrix A, int test_pattern_symmetry_only);
SparseMatrix SparseMatrix_transpose(SparseMatrix A);
SparseMatrix SparseMatrix_symmetrize(SparseMatrix A, int pattern_symmetric_only);
SparseMatrix SparseMatrix_symmetrize_nodiag(SparseMatrix A, int pattern_symmetric_only);
void SparseMatrix_multiply_vector(SparseMatrix A, double *v, double **res, int transposed);/* if v = NULL, v is assumed to be {1,1,...,1}*/
SparseMatrix SparseMatrix_remove_diagonal(SparseMatrix A);
SparseMatrix SparseMatrix_remove_upper(SparseMatrix A);/* remove diag and upper diag */
SparseMatrix SparseMatrix_divide_row_by_degree(SparseMatrix A);
SparseMatrix SparseMatrix_get_real_adjacency_matrix_symmetrized(SparseMatrix A);  /* symmetric, all entries to 1, diaginal removed */
SparseMatrix SparseMatrix_normalize_to_rowsum1(SparseMatrix A);/* for real only! */
void SparseMatrix_multiply_dense(SparseMatrix A, int ATranspose, double *v, int vTransposed, double **res, int res_transpose, int dim);
SparseMatrix SparseMatrix_apply_fun(SparseMatrix A, double (*fun)(double x));/* for real only! */
SparseMatrix SparseMatrix_apply_fun_general(SparseMatrix A, void (*fun)(int i, int j, int n, double *x));/* for real and complex (n=2) */
SparseMatrix SparseMatrix_copy(SparseMatrix A);
int SparseMatrix_has_diagonal(SparseMatrix A);
SparseMatrix SparseMatrix_normalize_by_row(SparseMatrix A);/* divide by max of each row */
SparseMatrix SparseMatrix_crop(SparseMatrix A, double epsilon);/*remove any entry <= epsilon*/
SparseMatrix SparseMatrix_scaled_by_vector(SparseMatrix A, double *v, int apply_to_row);
SparseMatrix SparseMatrix_multiply_by_scaler(SparseMatrix A, double s);
SparseMatrix SparseMatrix_make_undirected(SparseMatrix A);/* make it strictly low diag only, and set flag to undirected */
int SparseMatrix_connectedQ(SparseMatrix A);
double SparseMatrix_pseudo_diameter_only(SparseMatrix A);
double SparseMatrix_pseudo_diameter_weighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ); /* assume real distances, unsymmetric matrix ill be symmetrized */
double SparseMatrix_pseudo_diameter_unweighted(SparseMatrix A0, int root, int aggressive, int *end1, int *end2, int *connectedQ); /* assume unit edge length, unsymmetric matrix ill be symmetrized */
void SparseMatrix_level_sets(SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reintialize_mask);
void SparseMatrix_level_sets_khops(int khops, SparseMatrix A, int root, int *nlevel, int **levelset_ptr, int **levelset, int **mask, int reintialize_mask);
void SparseMatrix_weakly_connected_components(SparseMatrix A0, int *ncomp, int **comps, int **comps_ptr);
void SparseMatrix_decompose_to_supervariables(SparseMatrix A, int *ncluster, int **cluster, int **clusterp);
SparseMatrix SparseMatrix_get_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices);
SparseMatrix SparseMatrix_exclude_submatrix(SparseMatrix A, int nrow, int ncol, int *rindices, int *cindices);

SparseMatrix SparseMatrix_get_augmented(SparseMatrix A);

/* bipartite_options:
   BIPARTITE_RECT -- turn rectangular matrix into square), 
   BIPARTITE_PATTERN_UNSYM -- pattern unsummetric as bipartite
   BIPARTITE_UNSYM -- unsymmetric as square
   BIPARTITE_ALWAYS -- always as square
*/
SparseMatrix SparseMatrix_to_square_matrix(SparseMatrix A, int bipartite_options);

SparseMatrix SparseMatrix_largest_component(SparseMatrix A);

/* columns with <= threhold entries are deleted */
SparseMatrix SparseMatrix_delete_empty_columns(SparseMatrix A, int **new2old, int *nnew, int inplace);
SparseMatrix SparseMatrix_delete_sparse_columns(SparseMatrix A, int threshold, int **new2old, int *nnew, int inplace);

SparseMatrix SparseMatrix_sort(SparseMatrix A);

SparseMatrix SparseMatrix_set_entries_to_real_one(SparseMatrix A);

SparseMatrix SparseMatrix_complement(SparseMatrix A, int undirected);

int SparseMatrix_k_centers(SparseMatrix D, int weighted, int K, int root, 
			  int **centers, int centering, double **dist);

int SparseMatrix_k_centers_user(SparseMatrix D, int weighted, int K, 
				int *centers_user, int centering, double **dist);

SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted);

int SparseMatrix_distance_matrix(SparseMatrix A, int weighted,  double **dist_matrix);
SparseMatrix SparseMatrix_distance_matrix_khops(int khops, SparseMatrix A, int weighted);
SparseMatrix SparseMatrix_distance_matrix_k_centers(int K, SparseMatrix D, int weighted);

void SparseMatrix_kcoreness(SparseMatrix A, int **coreness);/* assign coreness to each node */
void SparseMatrix_kcore_decomposition(SparseMatrix A, int *coreness_max0, int **coreness_ptr0, int **coreness_list0);/* return the decomposition */

void SparseMatrix_khairness(SparseMatrix A, int **hairness);/* assign hairness to each node */
void SparseMatrix_khair_decomposition(SparseMatrix A, int *hairness_max0, int **hairness_ptr0, int **hairness_list0);/* return the decomposition */

SparseMatrix SparseMatrix_from_dense(int m, int n, double *x);

void SparseMatrix_page_rank(SparseMatrix A, double teleport_probablity, int weighted, double epsilon, double **page_rank);


























#line 64 "graphviz-2.38.0\\lib\\sparse\\mq.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\mq.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




typedef struct Multilevel_MQ_Clustering_struct *Multilevel_MQ_Clustering;

struct Multilevel_MQ_Clustering_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A; /* n x n matrix */
  SparseMatrix P; 
  SparseMatrix R; 
  Multilevel_MQ_Clustering next;
  Multilevel_MQ_Clustering prev;
  int delete_top_level_A;
  int *matching; /* dimension n. matching[i] is the clustering assignment of node i */

  /*

   .                                 |E(i,i)|                                     |E(i,j)|
   MQ/2 = (1/k) * \sum_{i=1...k} ------------ - (1/(k*(k-1))) * \sum_{i<j} -------------------  
   .                                |V(i)|^2                                   |V(i)|*|V(j)|
   .   = mq_in/k - mq_out/(k*(k-1))
  */

  double mq;
  double mq_in, mq_out;/* mqs(A) = deg_in(A)/|A|^2 - deg_out(A)/|A|/(|V|-|A|) */
  int ncluster; /* number of clusters */

  double *deg_intra;/* dimension n. deg[i] equal to the sum of edge weights within cluster i */
  double *dout;/* dimension n, dout[i] = \sum_{j -- i} a(i,j)/|j| is the scaled sum of outdegree */
  double *wgt; /* total vertex weight each coarse grid vertex represent */
};

/* find a clustering of vertices by maximize modularity quality
   A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
   inplace: whether A can e modified. If true, A will be modified by removing diagonal.

   maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
   .   is desired. this may not always be realized, and modularity quality may be low when this is specified. Default: maxcluster = 0 (no limit)

   use_value: whether to use the entry value, or treat edge weights as 1.
   nclusters: on output the number of clusters
   assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters.
   .   If *assignment = NULL on entry, it will be allocated. Otherwise used.
   mq: achieve modularity
*/
void mq_clustering(SparseMatrix A, int inplace, int maxcluster, int use_value,
			   int *nclusters, int **assignment, double *mq, int *flag);


#line 65 "graphviz-2.38.0\\lib\\sparse\\mq.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\LinkedList.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




typedef struct SingleLinkedList_struct* SingleLinkedList;

struct SingleLinkedList_struct {
  void *data;
  SingleLinkedList next;
};

SingleLinkedList SingleLinkedList_new(void *data);
SingleLinkedList SingleLinkedList_new_int(int i);
void SingleLinkedList_delete(SingleLinkedList head, void (*linklist_deallocator)(void*));
SingleLinkedList SingleLinkedList_prepend(SingleLinkedList l, void *data);
SingleLinkedList SingleLinkedList_prepend_int(SingleLinkedList l, int i);

void* SingleLinkedList_get_data(SingleLinkedList l);

SingleLinkedList SingleLinkedList_get_next(SingleLinkedList l);

void SingleLinkedList_print(SingleLinkedList head, void (*linkedlist_print)(void*));


typedef struct DoubleLinkedList_struct* DoubleLinkedList;

struct DoubleLinkedList_struct {
  void *data;
  DoubleLinkedList next;
  DoubleLinkedList prev;
};

DoubleLinkedList DoubleLinkedList_new(void *data);
void DoubleLinkedList_delete(DoubleLinkedList head, void (*linklist_deallocator)(void*));
DoubleLinkedList DoubleLinkedList_prepend(DoubleLinkedList l, void *data);

void* DoubleLinkedList_get_data(DoubleLinkedList l);

DoubleLinkedList DoubleLinkedList_get_next(DoubleLinkedList l);

void DoubleLinkedList_delete_element(DoubleLinkedList l,  void (*linklist_deallocator)(void*), DoubleLinkedList *head);

#line 66 "graphviz-2.38.0\\lib\\sparse\\mq.c" 2

static double get_mq(SparseMatrix A, int *assignment, int *ncluster0, double *mq_in0, double *mq_out0, double **dout0){
  /* given a symmetric matrix representation of a graph and an assignment of nodes into clusters, calculate the modularity quality.
   assignment: assignmenet[i] gives the cluster assignment of node i. 0 <= assignment[i] < ncluster.
   ncluster: number of clusters
   mq_in: the part of MQ to do with intra-cluster edges, before divide by 1/k
   mq_out: the part of MQ to do with inter-cluster edges, before divide by 1/(k*(k-1))
   mq = 2*(mq_in/k - mq_out/(k*(k-1)));
  */
  int ncluster = 0;
  int n = A->m;
  int test_pattern_symmetry_only = 0;
  int *counts, *ia = A->ia, *ja = A->ja, k, i, j, jj;
  double mq_in = 0, mq_out = 0, *a = NULL, Vi, Vj;
  int c;
  double *dout;


  assert(SparseMatrix_is_symmetric(A, test_pattern_symmetry_only));
  assert(A->n == n);
  if (A->type == MATRIX_TYPE_REAL) a = (double*) A->a;

  counts = malloc(sizeof(int)*n);

  for (i = 0; i < n; i++) counts[i] = 0;

  for (i = 0; i < n; i++){
    assert(assignment[i] >= 0 && assignment[i] < n);
    if (counts[assignment[i]] == 0) ncluster++;
    counts[assignment[i]]++;
  }
  k = ncluster;
  assert(ncluster <= n);

  for (i = 0; i < n; i++){
    assert(assignment[i] < ncluster);
    c = assignment[i];
    Vi = counts[c];
    for (j = ia[i] ; j < ia[i+1]; j++){
      /* ASSUME UNDIRECTED */
      jj = ja[j];
      if (jj >= i) continue;
      assert(assignment[jj] < ncluster);
      Vj = counts[assignment[jj]];
      if (assignment[jj] == c){
	if (a) {
	  mq_in += a[j]/(Vi*Vi);
	} else {
	  mq_in += 1./(Vi*Vi);
	}
      } else {
	if (a) {
	  mq_out += a[j]/(Vi*Vj);
	} else {
	  mq_out += 1./(Vi*Vj);
	}
      }
      
    }
  }

  /* calculate scaled out degree */
  dout = malloc(sizeof(double)*n);
  for (i = 0; i < n; i++){
    dout[i] = 0;
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      if (jj == i) continue;
      if (a){
	dout[i] += a[j]/(double) counts[assignment[jj]];
      } else {
	dout[i] += 1./(double) counts[assignment[jj]];
      }
    }
  }

  *ncluster0 = k;
  *mq_in0 = mq_in;
  *mq_out0 = mq_out;
  *dout0 = dout;
  free(counts);

  if (k > 1){
    return 2*(mq_in/k - mq_out/(k*(k-1)));
  } else {
    return 2*mq_in;
  }
}

Multilevel_MQ_Clustering Multilevel_MQ_Clustering_init(SparseMatrix A, int level){
  Multilevel_MQ_Clustering grid;
  int n = A->n, i;
  int *matching;

  assert(A->type == MATRIX_TYPE_REAL);
  assert(SparseMatrix_is_symmetric(A, 0));

  if (!A) return NULL;
  assert(A->m == n);
  grid = malloc(sizeof(struct Multilevel_MQ_Clustering_struct));
  grid->level = level;
  grid->n = n;
  grid->A = A;
  grid->P = NULL;
  grid->R = NULL;
  grid->next = NULL;
  grid->prev = NULL;
  grid->delete_top_level_A = 0;
  matching = grid->matching = malloc(sizeof(double)*(n));
  grid->deg_intra = NULL;
  grid->dout = NULL;
  grid->wgt = NULL;

  if (level == 0){
    double mq = 0, mq_in, mq_out;
    int n = A->n, ncluster;
    double *deg_intra, *wgt, *dout;

    grid->deg_intra = malloc(sizeof(double)*(n));
    deg_intra = grid->deg_intra;

    grid->wgt = malloc(sizeof(double)*n);
    wgt = grid->wgt;

    for (i = 0; i < n; i++){
      deg_intra[i] = 0;
      wgt[i] = 1.;
    }
    for (i = 0; i < n; i++) matching[i] = i;
    mq = get_mq(A, matching, &ncluster, &mq_in, &mq_out, &dout);
    fprintf(stderr,"ncluster = %d, mq = %f\n", ncluster, mq);
    grid->mq = mq;
    grid->mq_in = mq_in;
    grid->mq_out = mq_out;
    grid->dout = dout;
    grid->ncluster = ncluster;

  }


  return grid;
} 

void Multilevel_MQ_Clustering_delete(Multilevel_MQ_Clustering grid){
  if (!grid) return;
  if (grid->A){
    if (grid->level == 0) {
      if (grid->delete_top_level_A) SparseMatrix_delete(grid->A);
    } else {
      SparseMatrix_delete(grid->A);
    }
  }
  SparseMatrix_delete(grid->P);
  SparseMatrix_delete(grid->R);
  free(grid->matching);
  free(grid->deg_intra);
  free(grid->dout);
  free(grid->wgt);
  Multilevel_MQ_Clustering_delete(grid->next);
  free(grid);
}

Multilevel_MQ_Clustering Multilevel_MQ_Clustering_establish(Multilevel_MQ_Clustering grid, int maxcluster){
  int *matching = grid->matching;
  SparseMatrix A = grid->A;
  int n = grid->n, level = grid->level, nc = 0, nclusters = n;
  double mq = 0, mq_in = 0, mq_out = 0, mq_new, mq_in_new, mq_out_new, mq_max = 0, mq_in_max = 0, mq_out_max = 0;
  int *ia = A->ia, *ja = A->ja;
  double *a, amax = 0;
  double *deg_intra = grid->deg_intra, *wgt = grid->wgt;
  double *deg_intra_new, *wgt_new = NULL;
  int i, j, k, jj, jc, jmax;
  double *deg_inter, gain = 0, *dout = grid->dout, *dout_new, deg_in_i, deg_in_j, wgt_i, wgt_j, a_ij, dout_i, dout_j, dout_max = 0, wgt_jmax = 0;
  int *mask;
  double maxgain = 0;
  double total_gain = 0;
  SingleLinkedList *neighbors = NULL, lst;


  neighbors = malloc(sizeof(SingleLinkedList)*n);
  for (i = 0; i < n; i++) neighbors[i] = NULL;

  mq = grid->mq;
  mq_in = grid->mq_in;
  mq_out = grid->mq_out;

  deg_intra_new = malloc(sizeof(double)*n);
  wgt_new = malloc(sizeof(double)*n);
  deg_inter = malloc(sizeof(double)*n);
  mask = malloc(sizeof(int)*n);
  dout_new = malloc(sizeof(double)*n);
  for (i = 0; i < n; i++) mask[i] = -1;

  assert(n == A->n);
  for (i = 0; i < n; i++) matching[i] = UNMATCHED;

  /* gain in merging node A into cluster B is
     mq_in_new = mq_in - |E(A,A)|/(V(A))^2 - |E(B,B)|/(V(B))^2 + (|E(A,A)|+|E(B,B)|+|E(A,B)|)/(|V(A)|+|V(B)|)^2
     .         = mq_in - deg_intra(A)/|A|^2 - deg_intra(B)/|B|^2 + (deg_intra(A)+deg_intra(B)+a(A,B))/(|A|+|B|)^2

     mq_out_new = mq_out - |E(A,B)|/(|V(A)|*V(B)|)-\sum_{C and A connected, C!=B} |E(A,C)|/(|V(A)|*|V(C)|)-\sum_{C and B connected,C!=B} |E(B,C)|/(|V(B)|*|V(C)|)
     .                  + \sum_{C connected to A or B, C!=A, C!=B} (|E(A,C)|+|E(B,C)|)/(|V(C)|*(|V(A)|+|V(B)|)
     .          = mq_out + a(A,B)/(|A|*|B|)-\sum_{C and A connected} a(A,C)/(|A|*|C|)-\sum_{C and B connected} a(B,C)/(|B|*|C|)
     .                  + \sum_{C connected to A or B, C!=A, C!=B} (a(A,C)+a(B,C))/(|C|*(|A|+|B|))
     Denote:
     dout(i) = \sum_{j -- i} a(i,j)/|j|
     then

     mq_out_new = mq_out - |E(A,B)|/(|V(A)|*V(B)|)-\sum_{C and A connected, C!=B} |E(A,C)|/(|V(A)|*|V(C)|)-\sum_{C and B connected,C!=B} |E(B,C)|/(|V(B)|*|V(C)|)
     .                  + \sum_{C connected to A or B, C!=A, C!=B} (|E(A,C)|+|E(B,C)|)/(|V(C)|*(|V(A)|+|V(B)|)
     .          = mq_out + a(A,B)/(|A|*|B|)-dout(A)/|A| - dout(B)/|B|
     .                  + (dout(A)+dout(B))/(|A|+|B|) - (a(A,B)/|A|+a(A,B)/|B|)/(|A|+|B|)
     .          = mq_out -dout(A)/|A| - dout(B)/|B| + (dout(A)+dout(B))/(|A|+|B|)
     after merging A and B into cluster AB,
     dout(AB) = dout(A) + dout(B);
     dout(C) := dout(C) - a(A,C)/|A| - a(B,C)/|B| + a(A,C)/(|A|+|B|) + a(B, C)/(|A|+|B|) 

     mq_new = mq_in_new/(k-1) - mq_out_new/((k-1)*(k-2))
     gain = mq_new - mq
  */
  a = (double*) A->a;
  for (i = 0; i < n; i++){
    if (matching[i] != UNMATCHED) continue;
    /* accumulate connections between i and clusters */
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      if (jj == i) continue;
      if ((jc=matching[jj]) != UNMATCHED){
	if (mask[jc] != i) {
	  mask[jc] = i;
	  deg_inter[jc] = a[j];
	} else {
	  deg_inter[jc] += a[j];
	}
      }
    }
    deg_in_i = deg_intra[i];
    wgt_i = wgt[i];
    dout_i = dout[i];

    maxgain = 0; 
    jmax = -1;
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      if (jj == i) continue;
      jc = matching[jj];
      if (jc == UNMATCHED){
	a_ij = a[j];
	wgt_j = wgt[jj];
	deg_in_j = deg_intra[jj];
	dout_j = dout[jj];
      } else if (deg_inter[jc] < 0){
	continue;
      } else {
	a_ij = deg_inter[jc];
	wgt_j = wgt_new[jc];
	deg_inter[jc] = -1; /* so that we do not redo the calulation when we hit another neighbor in cluster jc */
	deg_in_j = deg_intra_new[jc];
	dout_j = dout_new[jc];
      }

      mq_in_new = mq_in - deg_in_i/pow(wgt_i, 2) - deg_in_j/pow(wgt_j,2) 
	+ (deg_in_i + deg_in_j + a_ij)/pow(wgt_i + wgt_j,2);

      mq_out_new = mq_out - dout_i/wgt_i - dout_j/wgt_j + (dout_i + dout_j)/(wgt_i + wgt_j);

      if (nclusters > 2){
	mq_new =  2*(mq_in_new/(nclusters - 1) - mq_out_new/((nclusters - 1)*(nclusters - 2)));
      } else {
	mq_new =  2*mq_in_new/(nclusters - 1);
      }


      
	
	
	
	
	
	  
	
	  
	  
	  
	
	
	
	

	
	
      


      gain = mq_new - mq;
      if (Verbose) fprintf(stderr,"gain in merging node %d with node %d = %f-%f = %f\n", i, jj, mq, mq_new, gain);
      if (j == ia[i] || gain > maxgain){
	maxgain = gain;
	jmax = jj;
	amax = a_ij;
	dout_max = dout_j;
	wgt_jmax = wgt_j;
	mq_max = mq_new;
	mq_in_max = mq_in_new;
	mq_out_max = mq_out_new;
      }

    }

    /* now merge i and jmax */
    if (maxgain > 0 || (nc >= 1 && nc > maxcluster)){
      total_gain += maxgain;
      jc = matching[jmax];
      if (jc == UNMATCHED){
	fprintf(stderr, "maxgain=%f, merge %d, %d\n",maxgain, i, jmax);
	neighbors[nc] = SingleLinkedList_new_int(jmax);
	neighbors[nc] = SingleLinkedList_prepend_int(neighbors[nc], i);
	dout_new[nc] = dout_i + dout_max;
	matching[i] = matching[jmax] = nc;
	wgt_new[nc] = wgt[i] + wgt[jmax];
	deg_intra_new[nc] = deg_intra[i] + deg_intra[jmax] + amax;
	nc++;
      } else {	
	fprintf(stderr,"maxgain=%f, merge with existing cluster %d, %d\n",maxgain, i, jc);
	neighbors[jc] = SingleLinkedList_prepend_int(neighbors[jc], i);
	dout_new[jc] = dout_i + dout_max;
	wgt_new[jc] += wgt[i];
	matching[i] = jc;
	deg_intra_new[jc] += deg_intra[i] + amax;
      }
      mq = mq_max;
      mq_in = mq_in_max;
      mq_out = mq_out_max;
      nclusters--;
    } else {
      fprintf(stderr,"gain: %f -- no gain, skip merging node %d\n", maxgain, i);
      assert(maxgain <= 0);
      neighbors[nc] = SingleLinkedList_new_int(i);
      matching[i] = nc;
      deg_intra_new[nc] = deg_intra[i];
      wgt_new[nc] = wgt[i];
      nc++;
    }


    /* update scaled outdegree of neighbors of i and its merged node/cluster jmax */
    jc = matching[i];
    lst = neighbors[jc];
    do {
      mask[*((int*) SingleLinkedList_get_data(lst))] = n+i;
      lst = SingleLinkedList_get_next(lst);
    } while (lst);

    lst = neighbors[jc];

    do {
      k = *((int*) SingleLinkedList_get_data(lst));
      for (j = ia[k]; j < ia[k+1]; j++){
	jj = ja[j]; 
	if (mask[jj] == n+i) continue;/* link to within cluster */
	if ((jc = matching[jj]) == UNMATCHED){
	  if (k == i){
	    dout[jj] += -a[j]/wgt_i + a[j]/(wgt_i + wgt_jmax);
	  } else {
	    dout[jj] += -a[j]/wgt_jmax + a[j]/(wgt_i + wgt_jmax);
	  }
	} else {
	  if (k == i){
	    dout_new[jc] += -a[j]/wgt_i + a[j]/(wgt_i + wgt_jmax);
	  } else {
	    dout_new[jc] += -a[j]/wgt_jmax + a[j]/(wgt_i + wgt_jmax);
	  }
	}
      }
      lst = SingleLinkedList_get_next(lst);
    } while (lst);

  }

  fprintf(stderr,"verbose=%d\n",Verbose);
  if (Verbose) fprintf(stderr,"mq = %f new mq = %f level = %d, n = %d, nc = %d, gain = %g, mq_in = %f, mq_out = %f\n", mq, mq + total_gain, 
		       level, n, nc, total_gain, mq_in, mq_out);
  

  

  
  

  


  if (nc >= 1 && (total_gain > 0 || nc < n)){
    /* now set up restriction and prolongation operator */
    SparseMatrix P, R, R0, B, cA;
    double one = 1.;
    Multilevel_MQ_Clustering cgrid;

    R0 = SparseMatrix_new(nc, n, 1, MATRIX_TYPE_REAL, FORMAT_COORD);
    for (i = 0; i < n; i++){
      jj = matching[i];
      SparseMatrix_coordinate_form_add_entries(R0, 1, &jj, &i, &one);
    }
    R = SparseMatrix_from_coordinate_format(R0);
    SparseMatrix_delete(R0);
    P = SparseMatrix_transpose(R);
    B = SparseMatrix_multiply(R, A);
    if (!B) goto RETURN;
    cA = SparseMatrix_multiply(B, P); 
    if (!cA) goto RETURN;
    SparseMatrix_delete(B);
    grid->P = P;
    grid->R = R;
    level++;
    cgrid = Multilevel_MQ_Clustering_init(cA, level); 
    deg_intra_new = realloc(deg_intra_new, nc*sizeof(double));
    wgt_new = realloc(wgt_new, nc*sizeof(double));
    cgrid->deg_intra = deg_intra_new;
    cgrid->mq = grid->mq + total_gain;
    cgrid->wgt = wgt_new;
    dout_new =  realloc(dout_new, nc*sizeof(double));
    cgrid->dout = dout_new;

    cgrid = Multilevel_MQ_Clustering_establish(cgrid, maxcluster);

    grid->next = cgrid;
    cgrid->prev = grid;
  } else {
    /* no more improvement, stop and final clustering found */
    for (i = 0; i < n; i++) matching[i] = i;

    free(deg_intra_new);
    free(wgt_new);
    free(dout_new);
  }

 RETURN:
  for (i = 0; i < n; i++) SingleLinkedList_delete(neighbors[i], free);
  free(neighbors);

  free(deg_inter);
  free(mask);
  return grid;
}

Multilevel_MQ_Clustering Multilevel_MQ_Clustering_new(SparseMatrix A0, int maxcluster){
  /* maxcluster is used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
     is desired. this may not always be realized, and mq may be low when this is specified. Default: maxcluster = 0 */
  Multilevel_MQ_Clustering grid;
  SparseMatrix A = A0;

  if (maxcluster <= 0) maxcluster = A->m;
  if (!SparseMatrix_is_symmetric(A, 0) || A->type != MATRIX_TYPE_REAL){
    A = SparseMatrix_get_real_adjacency_matrix_symmetrized(A);
  }
  grid = Multilevel_MQ_Clustering_init(A, 0);

  grid = Multilevel_MQ_Clustering_establish(grid, maxcluster);

  if (A != A0) grid->delete_top_level_A = 1;/* be sure to clean up later */
  return grid;
}


static void hierachical_mq_clustering(SparseMatrix A, int maxcluster,
					      int *nclusters, int **assignment, double *mq, int *flag){
  /* find a clustering of vertices by maximize mq
     A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
     maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
     .   is desired. this may not always be realized, and mq may be low when this is specified. Default: maxcluster = 0 
     nclusters: on output the number of clusters
     assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters
   */

  Multilevel_MQ_Clustering grid, cgrid;
  int *matching, i;
  SparseMatrix P;
  double *u;
  assert(A->m == A->n);

  *mq = 0.;

  *flag = 0;

  grid = Multilevel_MQ_Clustering_new(A, maxcluster);

  /* find coarsest */
  cgrid = grid;
  while (cgrid->next){
    cgrid = cgrid->next;
  }

  /* project clustering up */
  u =  malloc(sizeof(double)*cgrid->n);
  for (i = 0; i < cgrid->n; i++) u[i] = (double) (cgrid->matching)[i];
  *nclusters = cgrid->n;
  *mq = cgrid->mq;

  while (cgrid->prev){
    double *v = NULL;
    P = cgrid->prev->P;
    SparseMatrix_multiply_vector(P, u, &v, 0);
    free(u);
    u = v;
    cgrid = cgrid->prev;
  }

  if (*assignment){
    matching = *assignment; 
  } else {
    matching = malloc(sizeof(int)*(grid->n));
    *assignment = matching;
  }
  for (i = 0; i < grid->n; i++) (matching)[i] = (int) u[i];
  free(u);

  Multilevel_MQ_Clustering_delete(grid);
  
}



void mq_clustering(SparseMatrix A, int inplace, int maxcluster, int use_value,
			   int *nclusters, int **assignment, double *mq, int *flag){
  /* find a clustering of vertices by maximize mq
     A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
     inplace: whether A can e modified. If true, A will be modified by removing diagonal.
     maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
     .   is desired. this may not always be realized, and mq may be low when this is specified. Default: maxcluster = 0 
     nclusters: on output the number of clusters
     assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters
   */
  SparseMatrix B;

  *flag = 0;
  
  assert(A->m == A->n);

  B = SparseMatrix_symmetrize(A, 0);

  if (!inplace && B == A) {
    B = SparseMatrix_copy(A);
  }

  B = SparseMatrix_remove_diagonal(B);

  if (B->type != MATRIX_TYPE_REAL || !use_value) B = SparseMatrix_set_entries_to_real_one(B);

  hierachical_mq_clustering(B, maxcluster, nclusters, assignment, mq, flag);

  if (B != A) SparseMatrix_delete(B);

}
