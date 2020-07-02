#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include "example_victim.h"
#include "example_helper.h"

int n;
int * m=0; // dense matrix
int * v=0;
int * y=0;
results_t *res;

void initAttack(int);
void setupAttack(void);
int  performAttack(void);
void updateAttack(int, int);
void finishAttack(void);
void genYourOwn(int n, int *m);

const int SMALLEST_SIZE=32;
const int LARGEST_SIZE=1024;
const int NUM_RUNS=5;
double *timings = 0;

static __inline__ unsigned long long rdtsc(void)
{
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}
unsigned long long start, end;

int main(int argc, char ** argv)
{
    printf("Calibrating execution time for different matrix sizes..\n");
    initAttack(LARGEST_SIZE);
    for (int n=SMALLEST_SIZE; n <= LARGEST_SIZE; n++)
    {
        for (int j=0;j<NUM_RUNS; j++)
        {
            allocVecs(n, &m, &v, &y);
    
            genYourOwn(n, m);

            // setup your attack conditions/initialize your performance monitoring code here
            setupAttack();

            // run the victim
            runDenseMV(n, m, v, y);

            // estimate matrix dimension
            updateAttack(n, j);

            // cleanup
            done(m, v, y);
        }
    }
    finishAttack();
    printf("Done calibrating ...\n");
    printf("Ready for mounting timing-based attack ...\n");

    srand(time(0));

    printf("Running %d tests ...\n", NUM_TESTS);
    allocRes(&res);
    for (int i=0;i<NUM_TESTS; i++)
    {
        n = SMALLEST_SIZE + rand()%(LARGEST_SIZE-SMALLEST_SIZE);

        allocVecs(n, &m, &v, &y);

        genYourOwn(n, m);

        // setup your attack conditions/initialize your performance monitoring code here
        setupAttack();

        // run the victim
        runDenseMV(n, m, v, y);

        // estimate matrix dimension
        check(res, n, performAttack());

        // cleanup
        done(m, v, y);
    }
    printf("Done running tests ...\n");
    outputResults(res);

    free(timings);

    return 0;
}

void genYourOwn(int n, int *m)
{
    /* what values go in the matrix don't really matter */
    /* we just set every element to 1 */
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        m[i*n+j] = 1;
}

void initAttack(int max_size)
{
    timings = (double*)malloc(sizeof(double)*(max_size+1));
    for (int i=0;i<=max_size; i++)
    {
        timings[i]=0;
    } 
}

void setupAttack(void)
{
    // Your code goes here
    start = rdtsc();
}

void updateAttack(int n, int count)
{
    // Your code goes here
    end = rdtsc();

    double t = end - start;

    timings[n] += t;

    if (count == (NUM_RUNS-1))
    {
        timings[n] = timings[n]/NUM_RUNS;
    }
}

int performAttack(void)
{
    // Your code goes here
    end = rdtsc();

    double delta = end - start;

    // now match the entry in timings[.] closest to this value.
    int n_guess = -1;
    double min_gap = 1<<20; // some large constant
    for (int i=0;i<LARGEST_SIZE;i++)
    {
        if (fabs(timings[i]-delta) < min_gap) { 
            min_gap = fabs(timings[i] - delta); 
            n_guess = i;
        }
    }

    return n_guess;
}

void finishAttack(void)
{
    // any finalization of the attack goes here   
}
