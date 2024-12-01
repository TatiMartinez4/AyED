#include <iostream>
using namespace std;

/*
4) Desarrollar un programa que permita:
- Cargar un vector de 50 valores enteros
- Mostrar por pantalla el contenido del vector
- Obtener el mayor valor entero contenido en el vector y su posición en el mismo
- Obtener el menor valor entero contenido en el vector y su posición en el mismo.
Analizar y describir los cambios necesarios para resolver el mismo problema considerando a lo
sumo 50 valores enteros.
*/

int cargarVector(int vector[]);
void mostrarVector(int vector[], int puntero);
int mayorValor (int vector[], int puntero, int& posmayor);
int menorValor (int vector[], int puntero, int& posmenor);

int main()
{
    int vector[50];
    int puntero=cargarVector(vector);
    mostrarVector(vector, puntero);

    int posmayor=0;
    int mayor= mayorValor(vector,puntero,posmayor);
    cout<<"el mayor valor es "<< mayor << " y su posicion es "<<posmayor<<endl;

    int posmenor=0;
    int menor= menorValor(vector,puntero,posmenor);
    cout<<"el menor valor es "<<menor<< " y su posicion es "<<posmenor<<endl;

}

int cargarVector(int vector[])
{
    cout<<"ingrese una nota "<<endl;
    cin>>vector[0];

    int aux=1;
    while(aux<5 && vector[aux-1]!=0)
    {
        cout<<"ingrese un valor"<<endl;
        cin>>vector[aux];
        aux++;
    }
    if(aux==50)
    {
        return aux;
    }
    else
    return aux-2;
}

void mostrarVector(int vector[], int puntero)
{
    for(int aux=0;aux<=puntero;aux++)
    {
        cout<<vector[aux]<<" ";
    }
}

int mayorValor (int vector[], int puntero, int& posmayor)
{
    int valormax=0;
    for(int aux=0; aux<=puntero; aux++)
    {
        if(valormax<=vector[aux])
        {
            valormax=vector[aux];
            posmayor=aux;
        }
    }

    return valormax;
}


int menorValor (int vector[], int puntero, int& posmenor)
{
    int valormin=vector[0];
    for(int aux=1; aux<puntero; aux++)
    {
        if(valormin>=vector[aux])
        {
            valormin=vector[aux];
            posmenor=aux;
        }
    }

    return valormin;
}