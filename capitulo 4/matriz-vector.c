#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int thread_count;
int n,m;
double **A, *x, *y;  //todas son variables globales y compartidas

void* Pth_math_vect(void* rank){
  long my_rank = (long) rank;
  int i,j;
  int local_m = m/thread_count;  // como divide el subproceso 
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank+1) * local_m - 1;

  for(i = my_first_row; i <= my_last_row; i++){
    y[i] = 0.0;
    for(j = 0; j < n; j++){
      y[i] += A[i][j] * x[j];
    }
  }

  return NULL;
}


int main(int argc, char* argv[]){
    int i,j;
    long thread;
    pthread_t* thread_handles;
    double elapsed;
    struct timespec begin,end; 
    scanf("%d %d", &n, &m);
    A = (double**) malloc(m*sizeof(double));
    x = (double*) malloc(n*sizeof(double));
    y = (double*) malloc(m*sizeof(double));
    for(i = 0; i < m; i++){
        A[i] = (double*) malloc(n*sizeof(double));
    for(j = 0; j < n; j++){
        A[i][j] = rand() % 100000;
    }
    }
    for(i = 0; i < m; i++) y[i] = 0;
    for(i = 0; i < n; i++) x[i] = 1;
    thread_count = strtol(argv[1],NULL,10);
    thread_handles = malloc(thread_count*sizeof(pthread_t));
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for(thread = 0; thread < thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, Pth_math_vect, (void*) thread);}
    for(thread = 0; thread < thread_count; thread++){
        pthread_join(thread_handles[thread],NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_sec - begin.tv_sec;
    elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    printf("time is %lf\n", elapsed);
  /*for(i = 0; i < m;i++)
      printf("%f ",y[i]);
      printf("\n");*/
  free(thread_handles);


    for (int i = 0; i <= m; i++)
    {
        z[i] = 0.0;
        for (int j = 0; j < n; j++)
            z[i] += A[i*n+j]*x[j];
    }




  return 0;
}
