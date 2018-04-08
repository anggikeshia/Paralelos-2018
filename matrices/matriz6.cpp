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

int min(int a, int b)
{
    if(a < b) return a;
    return b;
}

int ** multiplicacion (int ** a, int ** b, int f, int c){
 int ** nuevo = crear_matriz(f,c);
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            nuevo[i][j]=0;
        }
    }
   //cout<<"Multiplicacion"<<endl;
    unsigned t0,t1;
    t0 = clock();
    int jump=200;
    for(int ii = 0; ii < f; ii+=jump)
        {
            for(int jj = 0; jj < c; jj += jump)
            {
                for(int kk = 0; kk < f; kk += jump)
                {
                    for(int i = ii; i < min(ii+jump,f); i++)
                    {
                        for(int j = jj; j < min(jj+jump,f); j++)
                        {
                            for(int k = kk; k < min(kk+jump,f); k++)
                            {
                                nuevo[i][j] += a[i][k] * b[k][j];
                            }

                        }
                    }
                }
            }
        }
//imprimir(nuevo,f,c);

    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << endl <<  "tiempo  " << time << endl;

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
    int ** mt = multiplicacion(a,b,f,c);



    return 0;

}
