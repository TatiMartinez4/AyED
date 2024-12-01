//5) Hacer una función que dado un vector de números enteros repetidos muestre todas las posiciones donde se encuentra el menor elemento.

#include <iostream>
using namespace std;

void posicionMenores(int v[]);

int main()
{
    int vector[7]={3,5,3,9,2,2,3};
    posicionMenores(vector);
}

void posicionMenores(int v[])
{
    int menor= v[0];
    for(int aux=1; aux<7; aux++)
    {
        if(v[aux]<=menor)
        {
            menor=v[aux];
        }
    }

    cout<<"las posiciones en las que se encuentra el numero "<< menor << " son: ";

    for(int aux=0;aux<7;aux++)
    {
        if(menor==v[aux])
        {
            cout<<aux<<" ";
        }
    }
}
