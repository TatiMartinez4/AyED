/*19) Una empresa que se dedica a la fabricación de equipos e instrumentos médicos desea controlar las
ventas que realizan sus visitadores médicos. Cuenta con 10 VISITADORES MEDICOS y cuenta también
con casi 400 PRODUCTOS hasta el momento. Para ello se tienen los siguientes datos de cada PRODUCTO
(estos datos se ingresan por teclado y finalizan cuando se ingresa un CERO en Número de Producto):
− Número de Producto (entre 3.000 y 15.000). !!!!!!!!
− Descripción de Producto (30 caracteres)
− Cantidad de unidades en STOCK (entre 1 y 2000). !!!!!
− Precio de Producto (float, mayor a 0). !!!!!!!
− Porcentaje de comisión por su venta (float, entre 5 y 20 %). !!!!!!!!!!!
Además cuenta con los datos de las VENTAS que realizan sus 10 visitadores médicos que son los siguientes
(estos datos se ingresan por teclado y finalizan cuando se ingresa un Cero en Número de Visitador):
− Número de Visitador Médico (entre 1 y 10). !!!!!
− Número de Producto (entre 3.000 y 15.000). !!!!!!!!
− Cantidad de unidades vendidas. !!!!!
NOTA: Rechazar los pedidos de aquellos productos cuyo stock es inferior al pedido.
Determinar e informar:
a) Informar el Stock de todos los productos luego de procesar las ventas de sus visitadores médicos.
b) Informar las comisiones que van a recibir cada uno de sus visitadores luego de haber procesado todas las
ventas.
c) Informar el total de la facturación que realizó la empresa de cada uno de los productos vendidos luego de
haber procesado todas las ventas.*/

#include <iostream>
using namespace std;

struct Productos
{
    unsigned codProducto=0;
    int stock=0;
    float precio=0.0;
    float comision=0.0;
    int cantVendida=0;
    float ganancia=0.0;
};

int ingresarProducto(Productos p[], int t);
void ingresarVentas(Productos p[],float v[], int t);
int buscarProd(Productos p[], int t, int buscar);
void mostrarStock(Productos p[], int t);
void mostrarComisiones(float v[] , int t);
void mostrarGananciaPorProducto(Productos p[], int t);

int main()
{
    Productos p[400];
    float gananciaVentas[10]={0}; //ganancias de cada vendedor
    int cantProductos=ingresarProducto(p,400);
    ingresarVentas(p,gananciaVentas,400);
    mostrarStock(p,cantProductos);
    mostrarComisiones(gananciaVentas,10);
    mostrarGananciaPorProducto(p, cantProductos);
}


int ingresarProducto(Productos p[], int t)
{
    int i=0;
    string descProd;
    cout<<"ingrese el numero de producto "<<endl;
    cin>>p[i].codProducto;

    while(p[i].codProducto!=0)
    {
        //cout<<"ingrese una descripcion del producto "<<endl;
        //cin>>descProd;

        cout<<"ingrese el stock disponible "<<endl;
        cin>>p[i].stock;

        cout<<"ingrese el precio del producto "<<endl;
        cin>>p[i].precio;

        cout<<"ingrese el porcentaje de comision que se recibe "<<endl;
        cin>>p[i].comision;

        i++;

        cout<<"ingrese el numero de producto "<<endl;
        cin>>p[i].codProducto;

    }

    return i;

}

void ingresarVentas(Productos p[],float v[], int t)
{
    int visitador=0;
    int numProd=0;
    int unidadesVendidas=0;
    cout<<"ingrese el numero del visitador "<<endl;
    cin>>visitador; //num del 1 al 10

    while(visitador!=0)
    {
        cout<<"ingrese numero de producto "<<endl;
        cin>>numProd;

        cout<<"ingrese la cantidad de unidades vendidas "<<endl;
        cin>>unidadesVendidas;

        //procesar
        int pos=buscarProd(p,t,numProd);
        if(unidadesVendidas<= p[pos].stock)
        {
            //actualizar stock
            p[pos].stock-=unidadesVendidas;

            //cual es la ganancia?
            float total= unidadesVendidas*p[pos].precio;
            float g=(total*p[pos].comision)/100;

            v[visitador-1]+=g;

            //actualizar cantidad vendida del producto
            p[pos].cantVendida+=unidadesVendidas;
            p[pos].ganancia+=total;
        }
        else
        {
            cout<<"pedido rechazado"<<endl;
        }
        cout<<"ingrese el numero del visitador "<<endl;
        cin>>visitador;
    }
}

int buscarProd(Productos p[], int t, int buscar)
{
    int i=0;
    while(i<t && p[i].codProducto!=buscar)
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

void mostrarStock(Productos p[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"el stock disponible del producto "<<p[i].codProducto<<" es: "<<p[i].stock<<endl;
    }
}

void mostrarComisiones(float v[] , int t)
{
    for(int i=0;i<t;i++)
    {
        cout<<"la comision recibida por el vendedor "<< i+1<< " es de: "<< v[i]<<endl;
    }
}

void mostrarGananciaPorProducto(Productos p[], int t)
{
    for(int i=0; i<t;i++)
    {
        cout<<"la ganancia total del producto "<< p[i].codProducto<< " es "<<p[i].ganancia<<endl;
    }
}