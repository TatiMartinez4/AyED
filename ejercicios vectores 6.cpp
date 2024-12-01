/*6) Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán
ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el
siguiente:
2 salió ... veces
3 salió ... veces
.
.
12 salió ... veces*/


void cargarConCeros( int v[]);
void cargar(int v[]);
void informarCantidades(int v[]);

#include <iostream>
using namespace std;

int main()
{
    int resultados[12];
    cargarConCeros(resultados);
    cargar(resultados);
    informarCantidades(resultados);
}

void cargarConCeros( int v[])
{
    for(int i=0; i<12; i++)
        v[i]=0;
}

void cargar(int v[])
{
    int num1,num2=0;

    for(int i=0; i<5; i++)
    {
        cout<<"ingrese los resultados"<<endl;
        cin>>num1>>num2;

        v[num1+num2-1]+=1;
    }
}

void informarCantidades(int v[])
{
    for(int i=1; i<12; i++)
        cout<<i+1<<" salió "<< v[i]<< " veces"<<endl;
}



