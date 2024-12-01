#include <iostream>
using namespace std;

//1) Realizar una función que reciba por parámetro dos vectores de números enteros de 5 elementos cada uno y
//genere un vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro. 

//puse una funcion que tmb muestre lo que tiene este nuevo vector

void generarVector (int v1[], int v2[], int vf[]);
void mostrar(int vf[]);

int main()
{
    int vector1[5]={1,2,3,4,5};
    int vector2[5]={6,7,8,9,10};
    int nuevoVector[10];
    generarVector(vector1,vector2,nuevoVector);
    mostrar(nuevoVector);


}

void generarVector (int v1[], int v2[], int vf[])
{
    for(int aux=0; aux<5;aux++)
    {
        vf[aux]=v1[aux];   
    }

    for(int aux=0; aux<5;aux++)
    {
        vf[aux+5]=v2[aux];   
    }

}

void mostrar(int vf[])
{
    for(int aux=0; aux<10; aux++)
    {
        cout<< vf[aux]<<" ";
    }
}