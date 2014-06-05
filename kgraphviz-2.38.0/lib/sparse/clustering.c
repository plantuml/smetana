#line 1 "graphviz-2.38.0\\lib\\sparse\\clustering.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\sparse\\clustering.c" 2
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


























#line 17 "graphviz-2.38.0\\lib\\sparse\\clustering.c" 2
#line 1 "graphviz-2.38.0\\lib\\sparse\\clustering.h" 1
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




typedef struct Multilevel_Modularity_Clustering_struct *Multilevel_Modularity_Clustering;

struct Multilevel_Modularity_Clustering_struct {
  int level;/* 0, 1, ... */
  int n;
  SparseMatrix A; /* n x n matrix */
  SparseMatrix P; 
  SparseMatrix R; 
  Multilevel_Modularity_Clustering next;
  Multilevel_Modularity_Clustering prev;
  int delete_top_level_A;
  int *matching; /* dimension n. matching[i] is the clustering assignment of node i */
  double modularity;
  double deg_total; /* total edge weights, including self-edges */
  double *deg;/* dimension n. deg[i] equal to the sum of edge weights connected to vertex i. I.e., sum of  row i */
  int agglomerate_regardless;/* whether to agglomerate nodes even if this causes modularity reduction. This is used if we want to force
				agglomeration so as to get less clusters
			      */


};

enum {CLUSTERING_MODULARITY = 0, CLUSTERING_MQ};

/* find a clustering of vertices by maximize modularity
   A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
   inplace: whether A can e modified. If true, A will be modified by removing diagonal.

   maxcluster: used to specify the maximum number of cluster desired, e.g., maxcluster=10 means that a maximum of 10 clusters
   .   is desired. this may not always be realized, and modularity may be low when this is specified. Default: maxcluster = 0 (no limit)

   use_value: whether to use the entry value, or treat edge weights as 1.
   nclusters: on output the number of clusters
   assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters.
   .   If *assignment = NULL on entry, it will be allocated. Otherwise used.
   modularity: achieve modularity
*/
void modularity_clustering(SparseMatrix A, int inplace, int maxcluster, int use_value,
			   int *nclusters, int **assignment, double *modularity, int *flag);


#line 18 "graphviz-2.38.0\\lib\\sparse\\clustering.c" 2



static Multilevel_Modularity_Clustering Multilevel_Modularity_Clustering_init(SparseMatrix A, int level){
  Multilevel_Modularity_Clustering grid;
  int n = A->n, i, j;

  assert(A->type == MATRIX_TYPE_REAL);
  assert(SparseMatrix_is_symmetric(A, 0));

  if (!A) return NULL;
  assert(A->m == n);
  grid = malloc(sizeof(struct Multilevel_Modularity_Clustering_struct));
  grid->level = level;
  grid->n = n;
  grid->A = A;
  grid->P = NULL;
  grid->R = NULL;
  grid->next = NULL;
  grid->prev = NULL;
  grid->delete_top_level_A = 0;
  grid->matching = malloc(sizeof(double)*(n));
  grid->deg = NULL;
  grid->agglomerate_regardless = 0;

  if (level == 0){
    double modularity = 0;
    int *ia = A->ia, *ja = A->ja, n = A->n;
    double deg_total = 0;
    double *deg, *a = (double*) (A->a);
    double *indeg;

    grid->deg_total = 0.;
    grid->deg = malloc(sizeof(double)*(n));
    deg = grid->deg;

    indeg = malloc(sizeof(double)*n);
    for (i = 0; i < n; i++){
      deg[i] = 0;
      indeg[i] = 0.;
      for (j = ia[i]; j < ia[i+1]; j++){
	deg[i] += a[j];
	if (ja[j] == i) indeg[i] = a[j];
      }
      deg_total += deg[i];
    }
    if (deg_total == 0) deg_total = 1;
    for (i = 0; i < n; i++){
      modularity += (indeg[i] - deg[i]*deg[i]/deg_total)/deg_total;
    }
    grid->deg_total = deg_total;
    grid->deg = deg;
    grid->modularity = modularity;
    free(indeg);
  }


  return grid;
} 

static void Multilevel_Modularity_Clustering_delete(Multilevel_Modularity_Clustering grid){
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
  free(grid->deg);

  Multilevel_Modularity_Clustering_delete(grid->next);
  free(grid);
}

static Multilevel_Modularity_Clustering Multilevel_Modularity_Clustering_establish(Multilevel_Modularity_Clustering grid, int ncluster_target){
  int *matching = grid->matching;
  SparseMatrix A = grid->A;
  int n = grid->n, level = grid->level, nc = 0;
  double modularity = 0;
  int *ia = A->ia, *ja = A->ja;
  double *a;
  double *deg = grid->deg;
  double *deg_new;
  int i, j, jj, jc, jmax;
  double inv_deg_total = 1./(grid->deg_total);
  double *deg_inter, gain;
  int *mask;
  double maxgain;
  double total_gain = 0;
  modularity = grid->modularity;

  deg_new = malloc(sizeof(double)*n);
  deg_inter = malloc(sizeof(double)*n);
  mask = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) mask[i] = -1;

  assert(n == A->n);
  for (i = 0; i < n; i++) matching[i] = UNMATCHED;

  /* gain in merging node i into cluster j is
     deg(i,j)/deg_total - 2*deg(i)*deg(j)/deg_total^2
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

    maxgain = 0;
    jmax = -1;
    for (j = ia[i]; j < ia[i+1]; j++){
      jj = ja[j];
      if (jj == i) continue;
      if ((jc=matching[jj]) == UNMATCHED){
	/* the first 2 is due to the fact that deg_iter gives edge weight from i to jj, but there are also edges from jj to i */
	gain = (2*a[j] - 2*deg[i]*deg[jj]*inv_deg_total)*inv_deg_total;
      } else {
	if (deg_inter[jc] > 0){
	  /* the first 2 is due to the fact that deg_iter gives edge weight from i to jc, but there are also edges from jc to i */
	  gain = (2*deg_inter[jc] - 2*deg[i]*deg_new[jc]*inv_deg_total)*inv_deg_total;
	  //	  printf("mod = %f deg_inter[jc] =%f, deg[i] = %f, deg_new[jc]=%f, gain = %f\n",modularity, deg_inter[jc],deg[i],deg_new[jc],gain);
	  deg_inter[jc] = -1; /* so that we do not redo the calulation when we hit another neighbor in cluster jc */
	} else {
	  gain = -1;
	}
      }
      if (jmax < 0 || gain > maxgain){
	maxgain = gain;
        jmax = jj;
      } 

    }

    /* now merge i and jmax */
    if (maxgain > 0 || grid->agglomerate_regardless){
      total_gain += maxgain;
      jc = matching[jmax];
      if (jc == UNMATCHED){
	//fprintf(stderr, "maxgain=%f, merge %d, %d\n",maxgain, i, jmax);
	matching[i] = matching[jmax] = nc;
	deg_new[nc] = deg[i] + deg[jmax];
	nc++;
      } else {
	//fprintf(stderr, "maxgain=%f, merge with existing cluster %d, %d\n",maxgain, i, jc);
	deg_new[jc] += deg[i];
	matching[i] = jc;
      }
    } else {
      assert(maxgain <= 0);
      matching[i] = nc;
      deg_new[nc] = deg[i];
      nc++;
    }

  }

  if (Verbose) fprintf(stderr,"modularity = %f new modularity = %f level = %d, n = %d, nc = %d, gain = %g\n", modularity, modularity + total_gain, 
		       level, n, nc, total_gain);

  /* !!!!!!!!!!!!!!!!!!!!!! */
  if (ncluster_target > 0){
    if (nc <= ncluster_target && n >= ncluster_target){
      if (n - ncluster_target > ncluster_target - nc){/* ncluster = nc */

      } else if (n - ncluster_target <= ncluster_target - nc){/* ncluster_target close to n */
	fprintf(stderr,"ncluster_target = %d, close to n=%d\n", ncluster_target, n);
	for (i = 0; i < n; i++) matching[i] = i;
	free(deg_new);
	goto RETURN;
      }
    } else if (n < ncluster_target){
      fprintf(stderr,"n < target\n");
      for (i = 0; i < n; i++) matching[i] = i;
      free(deg_new);
      goto RETURN;
    }
  }

  if (nc >= 1 && (total_gain > 0 || nc < n)){
    /* now set up restriction and prolongation operator */
    SparseMatrix P, R, R0, B, cA;
    double one = 1.;
    Multilevel_Modularity_Clustering cgrid;

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
    cgrid = Multilevel_Modularity_Clustering_init(cA, level); 
    deg_new = realloc(deg_new, nc*sizeof(double));
    cgrid->deg = deg_new;
    cgrid->modularity = grid->modularity + total_gain;
    cgrid->deg_total = grid->deg_total;
    cgrid = Multilevel_Modularity_Clustering_establish(cgrid, ncluster_target);
    grid->next = cgrid;
    cgrid->prev = grid;
  } else {
    /* if we want a small number of cluster but right now we have too many, we will force agglomeration */
    if (ncluster_target > 0 && nc > ncluster_target && !(grid->agglomerate_regardless)){
      grid->agglomerate_regardless = 1;
      free(deg_inter);
      free(mask);
      free(deg_new);
      return Multilevel_Modularity_Clustering_establish(grid, ncluster_target);
    }
    /* no more improvement, stop and final clustering found */
    for (i = 0; i < n; i++) matching[i] = i;
    free(deg_new);
  }

 RETURN:
  free(deg_inter);
  free(mask);
  return grid;
}

static Multilevel_Modularity_Clustering Multilevel_Modularity_Clustering_new(SparseMatrix A0, int ncluster_target){
  /* ncluster_target is used to specify the target number of cluster desired, e.g., ncluster_target=10 means that around 10 clusters
     is desired. The resulting clustering will give as close to this number as possible.
     If this number != the optimal number of clusters, the resulting modularity may be lower, or equal to, the optimal modularity.
     .  Agglomeration will be forced even if that reduces the modularity when there are too many clusters. It will stop when nc <= ncluster_target <= nc2,
     .  where nc and nc2 are the number of clusters in the current and next level of clustering. The final cluster number will be
     .  selected among nc or nc2, which ever is closer to ncluster_target.
     Default: ncluster_target <= 0 */

  Multilevel_Modularity_Clustering grid;
  SparseMatrix A = A0;

  if (!SparseMatrix_is_symmetric(A, 0) || A->type != MATRIX_TYPE_REAL){
    A = SparseMatrix_get_real_adjacency_matrix_symmetrized(A);
  }
  grid = Multilevel_Modularity_Clustering_init(A, 0);

  grid = Multilevel_Modularity_Clustering_establish(grid, ncluster_target);

  if (A != A0) grid->delete_top_level_A = 1;/* be sure to clean up later */
  return grid;
}


static void hierachical_modularity_clustering(SparseMatrix A, int ncluster_target,
					      int *nclusters, int **assignment, double *modularity, int *flag){
  /* find a clustering of vertices by maximize modularity
     A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.

     ncluster_target: is used to specify the target number of cluster desired, e.g., ncluster_target=10 means that around 10 clusters 
     is desired. The resulting clustering will give as close to this number as possible.                                                                                                 
     If this number != the optimal number of clusters, the resulting modularity may be lower, or equal to, the optimal modularity.                                                      
     .  Agglomeration will be forced even if that reduces the modularity when there are too many clusters. It will stop when nc <= ncluster_target <= nc2,                                   
     .  where nc and nc2 are the number of clusters in the current and next level of clustering. The final cluster number will be                                                     
     .  selected among nc or nc2, which ever is closer to ncluster_target.                                                                                                                  
     Default: ncluster_target <= 0 

     nclusters: on output the number of clusters
     assignment: dimension n. Node i is assigned to cluster "assignment[i]". 0 <= assignment < nclusters
   */

  Multilevel_Modularity_Clustering grid, cgrid;
  int *matching, i;
  SparseMatrix P;
  double *u;
  assert(A->m == A->n);

  *modularity = 0.;

  *flag = 0;

  grid = Multilevel_Modularity_Clustering_new(A, ncluster_target);

  /* find coarsest */
  cgrid = grid;
  while (cgrid->next){
    cgrid = cgrid->next;
  }

  /* project clustering up */
  u =  malloc(sizeof(double)*cgrid->n);
  for (i = 0; i < cgrid->n; i++) u[i] = (double) (cgrid->matching)[i];
  *nclusters = cgrid->n;
  *modularity = cgrid->modularity;

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

  Multilevel_Modularity_Clustering_delete(grid);
  
}



void modularity_clustering(SparseMatrix A, int inplace, int ncluster_target, int use_value,
			   int *nclusters, int **assignment, double *modularity, int *flag){
  /* find a clustering of vertices by maximize modularity
     A: symmetric square matrix n x n. If real value, value will be used as edges weights, otherwise edge weights are considered as 1.
     inplace: whether A can e modified. If true, A will be modified by removing diagonal.
     ncluster_target: is used to specify the target number of cluster desired, e.g., ncluster_target=10 means that around 10 clusters
     is desired. The resulting clustering will give as close to this number as possible.
     If this number != the optimal number of clusters, the resulting modularity may be lower, or equal to, the optimal modularity.
     .  Agglomeration will be forced even if that reduces the modularity when there are too many clusters. It will stop when nc <= ncluster_target <= nc2,
     .  where nc and nc2 are the number of clusters in the current and next level of clustering. The final cluster number will be
     .  selected among nc or nc2, which ever is closer to ncluster_target.
     Default: ncluster_target <= 0 
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

  hierachical_modularity_clustering(B, ncluster_target, nclusters, assignment, modularity, flag);

  if (B != A) SparseMatrix_delete(B);

}
