#include <iostream>
using namespace std;

//4) Hacer una función que dado un vector de números enteros devuelva el mayor número almacenado en el vector y la posición en la que se encuentra.

int numMayor(int v[], int& pos, int puntero);

int main()
{
    int vector[5]={1,2,3,4,5};
    int puntero=5;
    int pos=0;

    cout<<"el numero mayor es "<< numMayor(vector,pos,puntero)<< " y su posicion es "<< pos<<endl;
}

int numMayor(int v[], int& pos, int puntero)
{
    int max=v[0];
    for(int aux=1; aux<puntero; aux++)
    {
        if(v[aux]>max)
        {
            max=v[aux];
            pos=aux;
        }
    }

    return max;
}