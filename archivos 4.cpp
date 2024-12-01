#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

/*4) Dado un archivo binario de productos que contiene 100 registros, y cada registro corresponde a un producto que está codificado del 1 a 100, 
ordenado por código de producto con el siguiente diseño:

código de producto (1..100) 
stock

y otro archivo binario de pedidos, con el siguiente diseño:
número de pedido 
número de cliente
código de producto (1..100) 
cantidad pedida

Se pide desarrollar un algoritmo que:
a) Realice un listado con los pedidos que fueron satisfechos en su totalidad según el siguiente listado:
Pedidos Satisfechos:
Numero de pedido    Numero de cliente   Codigo de producto    Cantidad pedida
     9999                 9999                9999                 9999
     9999                 9999                9999                 9999
b) actualizar el campo stock del archivo de producto, cada vez que acepte un pedido. LISTO
c) grabar un archivo binario con el mismo diseño que el archivo de pedidos, con aquellos pedidos que no pueden ser satisfechos en su totalidad*/ //LISTO

struct Producto
{
    int codProd;
    int stock;
};

struct Pedido
{
    int numPedido;
    int numCliente;
    int cP;//codigo producto
    int cantidad;
};

int main()
{
    FILE*Productos=fopen("productos.dat","r+b");
    FILE*Pedidos=fopen("pedidos.dat","rb");
    FILE*Insatisfechos=fopen("pedidosinsatisfechos","wb");

    if(Productos!=NULL && Pedidos!=NULL && Insatisfechos!=NULL)
    {
        Pedido aux;
        fread(&aux,sizeof(Pedido),1,Pedidos);
        cout<<"Pedidos Satisfechos: "<<endl;
        cout<<"Numero de pedido    Numero de cliente   Codigo de producto    Cantidad pedida"<<endl;

        while(!feof(Pedidos))
        {
            Producto p;
            fseek(Productos,(aux.cP-1)*sizeof(Producto),SEEK_SET);
            fread(&p,sizeof(Producto),1,Productos);

            if(p.stock>=aux.cantidad)
            {
                p.stock=p.stock-aux.cantidad; //este stock tengo que guardarlo en el archivo en la posicion
                fseek(Productos,(aux.cP-1)*sizeof(Producto),SEEK_SET);
                fwrite(&p,sizeof(Producto),1,Productos);//aca guarde en el archivo el nuevo stock (osea actualice stock)

                //tengo que hacer el listado de pedidos aceptados
                cout<<"    "<<aux.numPedido<<"                "<<aux.numCliente<<"             "<<aux.cP<<"                "<<aux.cantidad<<endl;
            }
            else
            {
                fwrite(&aux,sizeof(Pedido),1,Insatisfechos);
            }
            Pedido aux;
            fread(&aux,sizeof(Pedido),1,Pedidos);
        }
    }
    else
    {
        cout<<"hubo un error al abrir alguno de los archivos necesarios"<<endl;
    }

    fclose(Productos);
    fclose(Pedidos);
    fclose(Insatisfechos);

    return 0;
}