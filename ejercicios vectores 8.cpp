#include <iostream>
using namespace std;


/*
8) Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio.
*/
void cargarVector(int v[], int t);
void ordenar(int c[], int p[], int t);
void informarCyP(int c[], int p[], int t);
void darPrecio(int c[], int p[], int t);

int main()
{
    int t=5;
    int codigos[t];
    cargarVector(codigos,t);
    int precios[t];
    cargarVector(precios,t);

    ordenar(codigos,precios,t);
    informarCyP(codigos, precios,t);
    darPrecio(codigos,precios,t);

    return 0;
}



void cargarVector(int v[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"ingrese un numero "<<endl;
        int num=0;
        cin>>num;
        v[i]=num;
    }
}
//a

void ordenar(int c[], int p[], int t)
{
    int aux1,j,aux2;
    for(int i=1; i<t; i++)
    {
        aux1=p[i];
        aux2=c[i];
        j=i-1;
        while(j>=0 && p[j]<aux1)
        {
            p[j+1]=p[j];
            c[j+1]=c[j];
            j--;
        }
        p[j+1]=aux1;
        c[j+1]=aux2;
    }

}

void informarCyP(int c[], int p[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"codigo del producto "<< c[i]<<endl;
        cout<<"precio del producto "<< p[i]<<endl;
    }

}



//b mmm no me gusta ese while
void darPrecio(int c[], int p[], int t)
{
    cout<<"ingrese un codigo "<<endl;
    int codigo=0;
    cin>>codigo;

    int i=0;

    while(i<t)
    {
        if(c[i]==codigo)
        {
            cout<<"el precio del producto con el codigo "<< codigo<< " es "<< p[i]<<endl;
        }
        i++;
    }
    
}


