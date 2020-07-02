#ifndef __HELPER_H
#define __HELPER_H

typedef struct
{
    int num_tests; // number of tests done
    int num_correct; // number of times attacker guessed correctly;
} results_t;

const int NUM_TESTS = 100;

extern "C" 
{
    void usage(void);
    void allocVecs(int n, int **m, int **v, int **y);
    void allocRes(results_t ** res);
    void check(results_t *res, int n, int n_guess);
    void outputResults(results_t * res);
    void done(int *m, int *v, int *y);
}

#endif

