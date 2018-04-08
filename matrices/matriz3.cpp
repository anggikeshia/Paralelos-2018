#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>
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
          //  cin >> b;
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
int ** nueva = crear_matriz(f,c);
unsigned t0,t1;
    t0 = clock();
    for(int i=0;i<f;i++){
      for(int j=0;j<c;j++){
          nueva[i][j]=0;
          for(int k=0;k<f;k++){
              nueva[i][j]=nueva[i][j]+(a[i][k]*b[k][j]);
          }
      }
  }
  //cout << endl << "MATRIZ C " << endl;
 // cout << endl;
 //imprimir(nueva,f,c);

    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << endl << "tiempo es   " << time << endl;
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
//imprimir(a,f,c);
cout << endl;
llenar(b,f,c);
//imprimir(b,f,c);

int ** mat= multiplicacion(a,b,f,c);
    return 0;
}
