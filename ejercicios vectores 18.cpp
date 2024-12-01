/*17) En un comercio se ingresan los datos de las ventas realizadas en el día. Por cada una se ingresa
número de factura, código de vendedor que realizó la venta (de 4 digitos) e importe de la misma. El
lote de datos finaliza con número de factura cero. Se pide desarrollar un algoritmo que:
- Imprima un listado ordenado por código de vendedor, detallando el importe total de ventas de
cada uno de ellos
- Dado un código de vendedor, imprima la cantidad de ventas realizadas por el mismo.*/ 

#include <iostream>
using namespace std;

struct Vendedor
{
    unsigned codVendedor=0;
    int cantVentas=0;
    float importe=0.0;
};

int cargarVector(Vendedor v[],int t);
void ordenarVector(Vendedor v[],int t);
int buscar(Vendedor v[], int t, int buscar);
void mostrarVector(Vendedor v[], int t);

int main()
{
    int t=5;
    Vendedor v[t];
    int cantidad=cargarVector(v,t);
    ordenarVector(v,cantidad);
    mostrarVector(v,cantidad);

    int deseo=0;

    cout<<"ingrese el codigo del vendedor que desea buscar"<<endl;
    cin>>deseo;

    int busc=buscar(v,cantidad,deseo);

    cout<<"el vendedor que busco ha realizado "<< v[busc].cantVentas<< " ventas "<<endl;
    
}

int buscar(Vendedor v[], int t, int buscar)
{
    unsigned i=0;
    while (i<t && v[i].codVendedor!=buscar)
    {
        i++;
    }
    if(i==t)
    {
        return -1;
    }
    else
    {
        return i;
    }
    
}

int cargarVector(Vendedor v[],int t)
{
    float importe=0.0;
    int factura=0;
    int vendedor=0;
    int i=0;

    cout<<"ingrese el numero de factura "<<endl;
    cin>>factura;
    
    while(factura!=0)
    {
        cout<<"ingrese el codigo de vendedor "<<endl;
        cin>>vendedor;

        cout<<"ingrese el importe de la compra "<<endl;
        cin>>importe;

        int pos=buscar(v,t,vendedor);

        if(pos!=-1)
        {
            v[pos].cantVentas++;
            v[pos].importe+=importe;
        }
        else
        {
            if(i<t)
            {
                v[i].codVendedor=vendedor;
                v[i].cantVentas=1;
                v[i].importe=importe;
                i++;
            }
        }

        cout<<"ingrese el numero de factura "<<endl;
        cin>>factura;
    }  

    return i;
}

void ordenarVector(Vendedor v[],int t)
{
    int i=1,j,aux2;
    unsigned aux1;
    float aux3;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-i;j++)
        {
            if(v[j].codVendedor>v[j+1].codVendedor)
            {
                aux1=v[j].codVendedor;
                aux2=v[j].cantVentas;
                aux3=v[j].importe;

                v[j].codVendedor=v[j+1].codVendedor;
                v[j].cantVentas=v[j+1].cantVentas;
                v[j].importe=v[j+1].importe;

                v[j+1].codVendedor=aux1;
                v[j+1].cantVentas=aux2;
                v[j+1].importe=aux3;

                cambio=true;
            }
        }
        i++;
    } while (i<t && cambio);
}

void mostrarVector(Vendedor v[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"el vendedor "<<v[i].codVendedor<< " vendio en total "<<v[i].importe<<endl;
    }
}