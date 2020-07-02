#include <stdio.h>
#include <stdlib.h>
#include "example_helper.h"

void usage(void)
{
    printf("attack <square matrix size in terms of number of rows>\n");
    printf("Argument must be a positive integer.\n");
}

void allocVecs(int n, int **m, int **v, int **y)
{
    *m = (int*) malloc(sizeof(int)*n*sizeof(int)*n);
    *v = (int*) malloc (sizeof(int)*n);
    *y = (int*) malloc (sizeof(int)*n);
    if (*m == 0) { printf("Fatal error! matrix m could not be allocated!\n"); exit(0); }
    if (*v == 0) { printf("Fatal error! vector v could not be allocated!\n"); exit(0); }
    if (*y == 0) { printf("Fatal error! vector y could not be allocated!\n"); exit(0); }

    int *t = *v;
    for (int i=0;i<n;i++) 
    {
        t[i] = 1;
    }
}

void allocRes(results_t ** res)
{
    *res = (results_t*)malloc(sizeof(results_t));
    if (*res == 0) { printf("Fatal error! results could not be allocated\n"); exit(0); }
    
    (*res)->num_tests = NUM_TESTS;
    (*res)->num_correct = 0.0;
}

void done(int *m, int *v, int *y)
{
    if (m) free(m);
    if (v) free(v);
    if (y) free(y);
}

void outputResults(results_t * res)
{
    printf("Num Tests: %d\n", res->num_tests);
    printf("Num Correct: %d\n", res->num_correct);
    printf("%% Correct:  %g\n", (double)res->num_correct / (double)res->num_tests);
}

void check(results_t * res, int n, int n_guess)
{
    if (n == n_guess) res->num_correct ++;
}
