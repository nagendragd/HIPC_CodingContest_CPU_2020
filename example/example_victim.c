#include "example_victim.h"

void  runDenseMV(int n, int *m, int *v, int *y)
{

    int s=0;
    for (int i=0;i<n;i++)
    {
        s=0;
        for (int j=0;j<n;j++)
        {
            s+=m[i*n+j]*v[j];
        }
        y[i] = s;
    }
}

