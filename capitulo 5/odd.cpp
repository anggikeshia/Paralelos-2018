#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void f_Odd_even(int modo){
srand(time(NULL));
int n, j, thread_count;
vector<int> v_array;
cout<<"Numero de threads :";
cin>>thread_count;
cout<<"Numero de elementos :";
cin>>n;
for(int i=0;i<n;i++){
    v_array.push_back(rand()%n);
}
double start = omp_get_wtime();
if(modo == 1){
    for(int phase=0;phase<n;phase++){
        if(phase%2==0){
            #pragma omp parallel for num_threads(thread_count) default(none) shared(v_array,n) private(j)
            for(j=1;j<n;j+=2){
                if(v_array[j-1] > v_array[j])
                    swap(v_array[j-1], v_array[j]);
            }
        }
        else{
            #pragma omp parallel for num_threads(thread_count) default(none) shared(v_array,n) private(j)
            for(j=1;j<n-1;j+=2){
                if(v_array[j] > v_array[j+1])
                    swap(v_array[j], v_array[j+1]);
            }
            }
    }
}  
if(modo == 2){
    int phase;
    #pragma omp parallel num_threads(thread_count) default(none) shared(v_array,n) private(j, phase)
    for(phase=0;phase<n;phase++){
        if(phase%2==0){
            #pragma omp for
            for(j=1;j<n;j+=2){
                if(v_array[j-1] > v_array[j])
                    swap(v_array[j-1], v_array[j]);
            }
        }
        else {
            #pragma omp for
            for(j=1;j<n-1;j+=2){
                if(v_array[j] > v_array[j+1])
                    swap(v_array[j], v_array[j+1]);
                }
            }
    }
}
    
cout<<"tiempo: "<<omp_get_wtime()-start << endl;

}

int main ()
{
  
    f_Odd_even(2);
 
return 0;

}

