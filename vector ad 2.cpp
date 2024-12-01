#include <iostream>
using namespace std;

//2) Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un vector de 10 posiciones con el contenido de ambos vectores intercalados. 

void vectoresIntercalados(int v1[], int v2[], int vf[]);
void mostrar(int vf[]);

int main()
{
    int vector1[]={1,2,3,4,5};
    int vector2[]={6,7,8,9,10};
    int vectorFinal[10];
    vectoresIntercalados(vector1,vector2, vectorFinal);
    mostrar(vectorFinal);
}

void vectoresIntercalados(int v1[], int v2[], int vf[])
{
    int i=0;
    for(int aux=0; aux<5; aux++)
    {
        vf[i]=v1[aux];
        i++;
        vf[i]=v2[aux];
        i++;
    }
}

void mostrar(int vf[])
{
    for(int aux=0; aux<10; aux++)
    {
        cout<< vf[aux]<<" ";
    }
}