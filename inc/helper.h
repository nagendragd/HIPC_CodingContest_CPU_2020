#ifndef __HELPER_H
#define __HELPER_H

typedef struct
{
    double sparsity; // entire matrix wide sparsity
    int    *nnz; // number of non-zeroes in each row
    int    *cols; // column indices of non-zeroes in each row - data arranged row by row
} results_t;

void usage(void);
void initCSR(int n, int *m, int *m_rows, int *m_cols, int *m_vals);
void allocVecs(int n, int **m, int **m_rows, int **m_cols, int ** m_vals, int **v, int **y);
void outputResults(int n, results_t * res);
void done(int *m, int * m_rows, int *m_cols, int *m_vals, int *v, int *y);

#endif

