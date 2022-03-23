/* Menghitung perkalian matriks secara sekuensial dalam C*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    /* Call function di sini*/
    return 0;
}

int alg_matmul2D(int m, int n, int p, float **a, float **b,
 float **c)
{
    int i, j, k ;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            a[i][j]=0;
            for (k=0; k<p; k++)
                a[i][j] += b[i][k]*c[k][j] ;
        }
    }
    return 0;
}


