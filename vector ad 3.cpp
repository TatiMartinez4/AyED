#include <iostream>
using namespace std;

//3) Hacer una función que reciba un vector de números enteros y lo copie en otro en orden inverso.

void invertirVector(int v1[], int vf[], int tamanio);
void mostrar(int vf[], int tamanio);

int main()
{
    int vector1[4]={1,2,3,4};
    int vectorInvertido[4];

    invertirVector(vector1, vectorInvertido, 4);
    mostrar(vectorInvertido,4);    
}

void invertirVector(int v1[], int vf[], int tamanio)
{
    int pos=tamanio-1;
    for(int aux=0; aux<tamanio ; aux++)
    {
        vf[aux]=v1[pos];
        pos--;
    }
}

void mostrar(int vf[], int tamanio)
{
    for(int aux=0; aux<tamanio; aux++)
    {
        cout<< vf[aux]<<" ";
    }
}