/*16) Se tiene un vector de productos donde cada elemento tiene código de rubro, código de producto y
descripción, ordenado por código de rubro. Se pide generar un vector ordenado por código de rubro
que contenga el código de rubro y la cantidad de productos de ese rubro.*/

#include <iostream>
using namespace std;
#define a 6

struct Producto
{
    int rubro;
    int producto;
    string descripcion;
};

struct Nuevo
{
    int rubro;
    int cantidad;
};

int generarVector(Producto p[],Nuevo n[],int t);
void leer(Nuevo n[],int t);

int main()
{
    Producto p[a]=
    {
        {2,10,"banana"},{2,20,"manzana"},{4,5,"marroc"},{8,9,"hamburguesa"},{8,4,"pancho"},{11,11,"pasta"}
    };

    Nuevo n[a];

    int cant= generarVector(p,n,a);

    cout<<"nueva lista"<<endl;

    leer(n,cant);

    return 0;
}

int generarVector(Producto p[],Nuevo n[],int t)
{
    int i=1;
    int aux=1;
    n[0].rubro=p[0].rubro;
    n[0].cantidad=1;
    while(i<t)
    {
        if(p[i].rubro!=p[i-1].rubro)
        {
            n[aux].rubro=p[i].rubro;
            n[aux].cantidad=1;
            aux++;
        }
        else
        {
            n[aux-1].cantidad++;
        }
        i++;
    }
    return aux;
}

void leer(Nuevo n[],int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"rubro "<< n[i].rubro<<endl;
        cout<< "cantidad "<< n[i].cantidad<<endl;
    }
        
}