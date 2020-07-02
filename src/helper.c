#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void usage(void)
{
    printf("attack <square matrix size in terms of number of rows>\n");
    printf("Argument must be a positive integer.\n");
}

void initCSR(int n, int *m, int *rows, int *cols, int *vals)
{
    int k=0;
    int nnz=0;
    rows[0]=0;
    for (int i=0;i<n;i++)
    {
       nnz=0;
       for (int j=0;j<n;j++)
       {
           if (m[i*n+j] != 0) {
              cols[k] = j;
              vals[k] = m[i*n+j];
              k++;
           }  
       }
       rows[i+1]=rows[i]+nnz;
    }
}

void allocVecs(int n, int **m, int **m_rows, int **m_cols, int ** m_vals, int **v, int **y)
{
    *m = (int*) malloc(sizeof(int)*n*sizeof(int)*n);
    *m_rows = (int*) malloc(sizeof(int)*(n+1)); // n+1 pointers are needed to store start and end of each row's non-zero columns
    *m_cols = (int*) malloc(sizeof(int)*n*sizeof(int)*n);
    *m_vals = (int*) malloc(sizeof(int)*n*sizeof(int)*n);
    *v = (int*) malloc (sizeof(int)*n);
    *y = (int*) malloc (sizeof(int)*n);
    if (*m == 0) { printf("Fatal error! matrix m could not be allocated!\n"); exit(0); }
    if (*m_rows == 0) { printf("Fatal error! csr rows of matrix m could not be allocated!\n"); exit(0); }
    if (*m_cols == 0) { printf("Fatal error! csr cols of matrix m could not be allocated!\n"); exit(0); }
    if (*m_vals == 0) { printf("Fatal error! csr vals of matrix m could not be allocated!\n"); exit(0); }
    if (*y == 0) { printf("Fatal error! vector y could not be allocated!\n"); exit(0); }
    if (*v == 0) { printf("Fatal error! vector v could not be allocated!\n"); exit(0); }
    if (*y == 0) { printf("Fatal error! vector y could not be allocated!\n"); exit(0); }

    int *t = *v;
    for (int i=0;i<n;i++) 
    {
        t[i] = 1;
    }
}

void allocRes(int n, results_t ** res)
{
    *res = (results_t*)malloc(sizeof(results_t));
    if (*res == 0) { printf("Fatal error! results could not be allocated\n"); exit(0); }
    (*res)->nnz = (int*)malloc(sizeof(int)*n);
    if ((*res)->nnz == 0) { printf("Fatal error! results.nnz could not be allocated\n"); exit(0); }
    (*res)->cols = (int*)malloc(sizeof(int)*n*sizeof(int)*n);
    if ((*res)->cols == 0) { printf("Fatal error! results.cols could not be allocated\n"); exit(0); }
    
    (*res)->sparsity = -1.0;
    for (int i=0; i<n; i++) (*res)->nnz[i] = -1;
    for (int i=0; i<n*n; i++) (*res)->cols[i] = -1;
}

void done(int *m, int * m_rows, int *m_cols, int *m_vals, int *v, int *y)
{
    if (m) free(m);
    if (m_rows) free(m_rows);
    if (m_cols) free(m_cols);
    if (m_vals) free(m_vals);
    if (v) free(v);
    if (y) free(y);
}

void initResults(int n, results_t * res)
{
    res = (results_t*) malloc(sizeof(results_t));
    res->sparsity = 0.0;
    res->nnz = (int*) malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) res->nnz[i] = -1;
    res->cols = (int*) malloc(sizeof(int)*n*sizeof(int)*n);
    for (int i=0; i<n*n; i++) res->cols[i] = -1;
}

void outputResults(int n, results_t * res)
{
    printf("%g\n", res->sparsity);
    for (int i=0; i<n; i++) printf("%d\n", res->nnz[i]);            
    for (int i=0; i<n*n; i++) printf("%d\n", res->cols[i]);            
}
