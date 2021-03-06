#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#include <time.h>


//ejecutar: gcc -g -Wall -fopenmp -o matriz matriz.c

int main(int argc, char* argv[]){
int thread_count = strtol(argv[1], NULL, 10);
int m,n,i,j;
double **A, *x, *y;
double elapsed;
struct timeval begin, end;
scanf("%d %d", &n, &m);;
A = (double**) malloc(m*sizeof(double));
x = (double*) malloc(n*sizeof(double));
y = (double*) malloc(m*sizeof(double));
for(i = 0; i < m; i++) {
    A[i] = (double*) malloc(n*sizeof(double));
    for(j = 0; j < n;j++){
        A[i][j] = 1;
    }
  }
gettimeofday(&begin, NULL);

#pragma omp parallel for num_threads(thread_count) default(none) private(i,j) shared(A,x,y,m,n)

    for(i = 0; i < m; i++){
        y[i] = 0.0;
    for(j = 0; j < n; j++)
        y[i] += A[i][j] * x[j];
    }
gettimeofday(&end, NULL);
elapsed = ((end.tv_sec - begin.tv_sec) * 1000000u + end.tv_usec - begin.tv_usec) / 1.e6;
printf("%lf\n", elapsed);
  return 0;
}
