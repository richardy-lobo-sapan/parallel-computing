#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Call Function Here*/
    return 0;
}

int matvec(float** matrix, float* vector, float* result,
int size_i, int size_j)
{
   int i,j;
#pragma omp parallel shared(matrix,result,vector) private(i,j)
   {
#pragma omp for  schedule(static)
   for (i=0; i<size_i; i=i+1){
      result[i]=0.;
      for (j=0; j<size_j; j=j+1){
         result[i]=(result[i])+((matrix[i][j])*(vector[j]));
      }
   }
   }
   return 0;
}
