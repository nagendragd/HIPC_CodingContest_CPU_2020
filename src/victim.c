#include "victim.h"

void  runSpMV(int n, int *rows, int *cols, int *vals, int *v, int *y)
{

    int s=0;
    int k=0;
    for (int i=0;i<n;i++)
    {
        int nnz = rows[i+1]-rows[i];
        s=0;
        for (int j=0;j<nnz;j++)
        {
            s+=vals[k+j]*v[cols[k+j]];
        }
        k+=nnz;
        y[i] = s;
    }
}

