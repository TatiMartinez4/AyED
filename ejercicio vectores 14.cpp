/*14) Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector con
los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código
de producto. Se pide actualizar el stock del vector de productos.
*/

#include <iostream>
using namespace std;
#define t1 6
#define t2 3

struct Producto
{
    int codigo;
    string descripcion;
    int stock;
};

struct Proveedores
{
    int codigo;
    int cantidad;
};

void actualizar(Producto p[],Proveedores pr[]);
int buscar(Producto p[], int bus);

int main()
{
    Producto p[t1]=
    {
        {1,"banana",4},{2,"manzana",2},{3,"frutilla",2},{4,"melon",1},{5,"sandia",5},{6,"pelon",0}
    };

    Proveedores pr[t2]=
    {
        {2,1},{3,3},{5,1}
    };

    actualizar(p,pr);


}

int buscar(Producto p[], int bus)
{
    int pos=-1;
    int desde=0;
    int hasta=t1-1;
    int medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(p[medio].codigo == bus)
        {
            pos=medio;
        }
        else
        {
            if(bus < p[medio].codigo)
            {
                hasta=medio-1;
            }
            else
            {
                desde=medio+1;
            }
        }
    }
    return pos;
}

void actualizar(Producto p[],Proveedores pr[])
{
    for(int i=0; i<t2; i++)
    {
        int pos= buscar(p,pr[i].codigo);
        if(pos!=-1)
        {
            p[pos].stock+=pr[i].cantidad;
        }
        else
            cout<<"ERROR"<<endl;
    }
}


