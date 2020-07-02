#ifndef __HELPER_H
#define __HELPER_H

typedef struct
{
    int matrix_size; // number of rows / columns (of square matrix)
} results_t;

extern "C" 
{
    void usage(void);
    void allocVecs(int n, int **m, int **v, int **y);
    void allocRes(int n, results_t ** res);
    void outputResults(int n, results_t * res);
    void done(int *m, int *v, int *y);
}

#endif

