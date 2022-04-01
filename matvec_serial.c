#include <stdio.h>
#include <stdlib.h>

int main()
{
    matvec({{1,2},{3,4}}, {5,6});
    return 0;
}

int matvec(float **matrix, float *vector, float *result,
int size_i, int size_j) {
   int i;
   int j;
   for(i=0;i<size_i;i++) {
      result[i]=0;
      for(j=0;j<size_j;j++) {
          result[i] += matrix[i][j]*vector[j];
      }
   }
   return 0;
}
