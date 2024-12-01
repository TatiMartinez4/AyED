/*5) Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 500, sin repetición, que
finaliza con cero, desarrollar un algoritmo que:
. Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
. Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto. */


#include <iostream>
using namespace std;

void llenarConCeros(int v[]);
void cargarValores(int v[]);
void imprimirValExist (int v[]);
void imprimirValFalt (int v[]);

int main()
{
    int valores[500];
    llenarConCeros(valores);
    cargarValores(valores);  
    imprimirValExist (valores);
    imprimirValFalt(valores);

}

void llenarConCeros(int v[])
{
    for(int i=0; i<500; i++ )
        v[i]=0;
}

void cargarValores(int v[])
{
    int num=0;
    cout<<"ingrese un valor entero comprendido entre 1 y 500"<<endl;
    cin>>num;

    while(1<=num && num<=500)
    {
        v[num-1]=num;
        cout<<"ingrese un valor entero comprendido entre 1 y 500"<<endl;
        cin>>num;
    }

}

void imprimirValExist (int v[])
{
    cout<<"los valores ingresados son:"<<endl;
    for(int i=0; i<500; i++)
    {
        if(v[i]!=0)
        {
            cout<<v[i]<<endl;
        }
    }
}

void imprimirValFalt (int v[])
{
    cout<<"los valores que faltaron ingresar son:"<<endl;
    for(int i=0; i<500; i++)
    {
        if(v[i]==0)
        {
            cout<<i+1<<endl;
        }
    }
}





