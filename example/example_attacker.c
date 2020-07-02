#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "example_victim.h"
#include "example_helper.h"

int n;
int * m=0; // original dense matrix
int * m_rows=0; // csr row pointers
int * m_cols=0; // csr colunn indices
int * m_vals=0; // csr non-zero values
int * v=0;
int * y=0;
results_t *res;

void setupAttack(void);
void performAttack(void);
void genYourOwn(int n, int *m);

int main(int argc, char ** argv)
{
    if (argc == 1) { usage(); return 0; }
    n = (int) strtoul(argv[1], 0, 10);
    if (n <= 0) { usage(); return 0; }

    allocVecs(n, &m, &m_rows, &m_cols, &m_vals, &v, &y);
    allocRes(n, &res);

    // generate matrix
    // if in TRAIN mode, then attacker can control the matrix contents
#ifdef TRAIN
    genYourOwn(n, m);
#else
    // if in TEST mode, then attacker can not control the matrix contents
    genSecret(n, m);
#endif

    // convert dense matrix to CSR
    initCSR(n, m, m_rows, m_cols, m_vals);

    // setup your attack conditions/initialize your performance monitoring code here
    setupAttack();

    // run the victim
    runSpMV(n, m_rows, m_cols, m_vals, v, y);

    // estimate matrix structure
    performAttack();

    // output
    outputResults(n, res);

    // cleanup
    done(m, m_rows, m_cols, m_vals, v, y);

    return 0;
}

void genYourOwn(int n, int *m)
{

}

void setupAttack(void)
{
    // Your code goes here
}

void performAttack(void)
{
    // Your code goes here
}

