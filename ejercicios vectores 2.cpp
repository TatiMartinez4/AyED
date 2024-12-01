#include <iostream>
using namespace std;

// 2) Hacer un algoritmo que lea 40 números y los muestre en orden inverso
int cargarVectores(int vector[]);
void mostrarVectores(int vector[],int puntero);

int main()
{
    int numeros [40];
    int puntero= cargarVectores(numeros);
    mostrarVectores(numeros,puntero);
}

int cargarVectores(int vector[])
{
    cout<<"ingrese una nota "<<endl;
    cin>>vector[0];

    int aux=1;
    while(aux<40 && vector[aux-1]!=0)
    {
        cout<<"ingrese un numero"<<endl;
        cin>>vector[aux];
        aux++;
    }

    if(aux==40)
    {
        return aux;
    }
    else
    return aux-1;
}


void mostrarVectores(int vector[], int puntero)
{
   for(int aux=puntero-1; aux>=0; aux-- )
   {
        cout<<vector[aux];
   }
}