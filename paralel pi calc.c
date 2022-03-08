/*
Program ini akan menghitung nilai fungsi
                  4/(1+x*x)

dari 0 ke 1 secara numerik. Nilai integral ini = pi.
Program diparalelisasi dengan menambahkan 4 baris,
(1) Baris yg mengandung omp.h -- file include yg
 mengandung OpenMP's function prototypes dan constants.
(2) Pragma utk membuat sekelompok threads
(3) Pragma yang menyebabkan salah satu thread mencetak
jumlah thread yang digunakan oleh program.
(4) Pragma untuk membagi iterasi loop di antara kelompok
threads. Pragma ini mencakup 2 klausa untuk (1) membuat
variabel pribadi dan (2) menyebabkan thread menghitung
jumlahnya secara lokal dan kemudian menggabungkan jumlah
lokalnya menjadi satu nilai global.
*/
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main ()
{
	  int i;
	  double x, pi, sum = 0.0;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;
	 for (i=1;i<=4;i++){
          sum = 0.0;
          omp_set_num_threads(i);
	  start_time = omp_get_wtime();
#pragma omp parallel
{
#pragma omp single
	  printf(" num_threads = %d",omp_get_num_threads());

#pragma omp for reduction(+:sum)
	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
}
	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi is %f in %f seconds and %d threads\n",pi,run_time,i);
}
}
