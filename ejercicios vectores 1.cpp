#include <iostream>
using namespace std;

//1) Hacer un algoritmo que lea 30 notas las cargue un vector y luego muestre la nota máxima.
int cargarVector(int vector[], int tamanio);
int numMAx(int vector[],int puntero);

int main()
{
    int notas [30];
    int posicion= cargarVector(notas,30);
    cout<<"la nota maxima es "<< numMAx(notas,posicion)<<endl;

    return 0;
}


int cargarVector(int vector[],int tamanio)
{
    cout<<"ingrese una nota "<<endl;
    cin>>vector[0];

    int aux=1;
    while (aux<tamanio && vector[aux-1]!=0)
    {
        cout<<"ingrese una nota "<<endl;
        cin>>vector[aux];
        aux++;
    }
       
    return aux;
}

int numMAx(int vector[],int puntero)
{
    int numaux=0;
    for(int aux=0; aux<puntero; aux++)
    {
        if(vector[aux]>=numaux)
        {
            numaux=vector[aux];
        }

    } 
    return numaux;
}