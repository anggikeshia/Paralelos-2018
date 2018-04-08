#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;


int ** crear_matriz (int f, int c){
    int ** mat;
    mat = new int * [f];
        for (int i = 0; i < f; i++)
            mat [i] = new int [c];
        return mat;
    }

void llenar (int ** mat, int f, int c){
    for (int i = 0; i < f; i++){
        for (int j = 0; j < c; j++){
            mat[i][j] = 10;//rand()%10;
            }
        }
    }


void imprimir (int ** mat, int f, int c){
    for (int i = 0; i < f; i++){
        for (int j = 0; j < c; j++){
            cout << mat [i][j]<< '\t';
        }
        cout << endl;
    }
}


int ** multiplicacion (int ** a, int ** b, int f, int c){
 int ** nuevo = crear_matriz(f,c);
   //cout<<"Multiplicacion"<<endl;
    int bloque=4;
    for(int ii = 0; ii < f; ii+=bloque){
            for(int jj = 0; jj < c; jj += bloque){
                for(int kk = 0; kk < f; kk += bloque){
                    for(int i = ii; i < min(ii+bloque,f); i++){
                        for(int j = jj; j < min(jj+bloque,f); j++){
                            for(int k = kk; k < min(kk+bloque,f); k++){
                                nuevo[i][j] += a[i][k] * b[k][j];
                            }
                        }
                    }
                }
            }
        } 
return nuevo;

//imprimir(nuevo,f,c);

}



int main()
{
    int f,c;
    cout <<"ingresar filas " << endl;
    cin >> f;
    cout <<"ingresar columnas " << endl;
    cin >> c;
    int ** a = crear_matriz(f,c);
    int ** b = crear_matriz(f,c);
    llenar(a,f,c);
    llenar(b,f,c);
    clock_t t0;
    clock_t t1;
    double tiempo;    
    srand(time(0));    
    //imprimir(a,f,c);
    //imprimir(b,f,c);
    int ** mt;
    t0 = clock();
    mt = multiplicacion(a,b,f,c);
    t1 = clock();
    tiempo = ((double)(t1 - t0 )) / CLOCKS_PER_SEC;
    cout<<endl;
    
    cout<<" El tiempo que demora es: "<< tiempo << endl;
 
    return 0;

}
