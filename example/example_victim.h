#ifndef __VICTIM_H
#define __VICTIM_H

// Function declaration for the sparse matrix vector multiply routine
// This routine performs:
// y = m*v, where m is a sparse matrix represented in CSR format
// v is a dense vector
// y is the output vector
// the matrix m is assumed square and of dimensions n by n
extern "C" void  runDenseMV(int n, int *m, int *v, int* y);

#endif
