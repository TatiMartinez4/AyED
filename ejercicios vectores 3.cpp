#include <iostream>
using namespace std;

//3) Hacer un algoritmo que lea 40 edades de alumnos y muestre por pantalla las edades que superen a la edad promedio.

int cargarVectores(int vector []);
int promedio(int vector [], int puntero);
void mayorAPromedio(int vector [], int puntero, int promedio);

int main()
{
    int edades [40];
    int puntero=cargarVectores(edades);
    int prom= promedio(edades,puntero);
    mayorAPromedio(edades,puntero,prom);
}

int cargarVectores(int vector [])
{
    cout<<"ingrese una nota "<<endl;
    cin>>vector[0];

    int aux=1;
    while(aux<40 && vector[aux-1]!=0)
    {
        cout<<"ingrese una edad"<<endl;
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

int promedio(int vector [], int puntero)
{
    int prom=0;
    for(int aux=0; aux<puntero; aux++)
    {
        prom+=vector[aux];
    }
    return prom/(puntero);
}

void mayorAPromedio(int vector [], int puntero, int promedio)
{
    cout<<"los numeros mayores a "<<promedio<<" son:"<<endl;
    for(int aux=0; aux<puntero; aux++)
    {
        if(vector[aux]>promedio)
        {
            cout<<vector[aux]<<endl;
        }
    }
}