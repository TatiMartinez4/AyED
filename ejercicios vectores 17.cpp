/*17) En un comercio se ingresan los datos de las ventas realizadas en el día. Por cada una se ingresa
número de factura, código de vendedor que realizó la venta (de 1 a 25) e importe de la misma. El
lote de datos finaliza con número de factura cero. Se pide desarrollar un algoritmo que:
- Imprima un listado ordenado por código de vendedor, detallando el importe total de ventas de
cada uno de ellos
- Dado un código de vendedor, imprima la cantidad de ventas realizadas por el mismo.*/

#include <iostream>
using namespace std;

struct Vendedor
{
    int cantDeVentas=0;
    float importe=0.0;
};

void cargarVentas(Vendedor v[], int t);
void mostrarListado(Vendedor v[],int t);
void buscarYMostrar(Vendedor v[], int t);

int main()
{
    int n=25;
    Vendedor v[n];
    cargarVentas(v,n);
    mostrarListado(v,n);
    buscarYMostrar(v, n);

    return 0;
}

void cargarVentas(Vendedor v[], int t)
{
    int vendedor;
    int factura;
    float importe;
    cout<<"ingrese numero de factura "<<endl;
    cin>>factura; // no necesito guardarme el numero de factura para nada
    
    while(factura!=0)
    { 
        cout<<"ingrese el cdigo del vendedor "<<endl;
        cin>>vendedor; 

        cout<<"ingrese importe de la venta "<<endl;
        cin>>importe;

        v[vendedor-1].importe+=importe;
        v[vendedor-1].cantDeVentas++;

        cout<<"ingrese numero de factura "<<endl;
        cin>>factura;
    }
}

void mostrarListado(Vendedor v[],int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"el importe total de ventas del vendedor "<< i+1<< " es: "<< v[i].importe<<endl;
    }
}

void buscarYMostrar(Vendedor v[], int t)
{
    cout<<"ingrese el codigo del vendedor que desea buscar "<<endl;
    int vendedor;
    cin>>vendedor;

    cout<<"la cantidad de ventas realizadas por el vendedor "<<vendedor<<" es: "<< v[vendedor-1].cantDeVentas<<endl;
}