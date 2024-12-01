//rehacer el ejercicio 8 con un vector de struct.
//Dado un struct que contenga el codigo y el precio de cada producto se pide:
//a)informar codigo y precio de todos los productos ordenados de mayor a menor por precio.
//b) Dado un codigo de producto informar su precio.

#include <iostream>
using namespace std;

struct Producto
{
    int codigo;
    double precio;
};

void cargar(Producto p[], int t);
void ordenar(Producto p[], int t);
void mostrar(Producto p[], int t);
int buscar(Producto p[], int t, int bus);

int main()
{
    int t=10;
    Producto prod[t];
    cout<<"ingresar el codigo y precio de los productos "<<endl;

    cargar(prod, t);
    ordenar(prod, t);

    cout<<"los codigos y precios de los productos ordenados de mayor a menor son: "<<endl;

    mostrar(prod,t);

    cout<<"el codigo del producto que se desea buscar es: "<<endl;
    int bus;
    cin>>bus;
    
    int codP= buscar(prod,t,bus);

    cout<<"el precio del producto buscado es: "<<prod[codP].precio<<endl;
    
        

    return 0;
}

void cargar(Producto p[],int t)
{
    for(int i=0; i<t; i++)
    {
        cin>>p[i].codigo;
        cin>>p[i].precio;
    }
}

void ordenar(Producto p[], int t)
{
    int i,j;
    double aux1,aux2;

    for(i=1;i<t;i++)
    {
        aux1=p[i].precio;
        aux2=p[i].codigo;
        j=i-1;

        while(j>0 && p[j].precio>aux1)
        {
            p[j+1].precio=p[j].precio;
            p[j+1].codigo=p[j].codigo;
            j--;
        }
        p[j+1].precio=aux1;
        p[j+1].codigo=aux2;
    }
}

void mostrar(Producto p[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"precio: "<< p[i].precio<<endl;
        cout<<"codigo: "<< p[i].codigo<<endl;
    }
}

int buscar(Producto p[], int t, int bus)
{
    int i=0;
    while(i<t && p[i].codigo!=bus)
    {
        i++;
    }

    return i;
}