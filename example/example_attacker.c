#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "example_victim.h"
#include "example_helper.h"

int n;
int * m=0; // dense matrix
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

    allocVecs(n, &m, &v, &y);
    allocRes(n, &res);

    // generate matrix
    // if in TRAIN mode, then attacker can control the matrix contents
#ifdef TRAIN
    genYourOwn(n, m);
#else
    // if in TEST mode, then attacker can not control the matrix contents
    genSecret(n, m);
#endif

    // setup your attack conditions/initialize your performance monitoring code here
    setupAttack();

    // run the victim
    runDenseMV(n, m, v, y);

    // estimate matrix structure
    performAttack();

    // output
    outputResults(n, res);

    // cleanup
    done(m, v, y);

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

