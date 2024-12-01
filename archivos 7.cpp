#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

/*
El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el depósito, para realizar las compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el local, con el siguiente diseño:
1. Codigo de libro
2. titulo del libro (30 caracteres)
3. Autor(20 caracteres)
4. Editorial (20 caracteres)
5. Stock en el local 
6. Genero (10 caracteres)

b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el depósito, con el siguiente diseño:
1.Codigo de libro
2.Stock en deposito

Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por código de libro, con un renglón por cada libro que tenga faltante en 
stock sea en depósito, local o en ambos lugares, con el siguiente formato:

   Libros faltantes
Código        Observación
9999        Falta en depósito
9999         Falta en local
9999      Falta en local y en depósito
Total de libros en falta: 999
*/

//mejorable porque podriamos hacer que cuando un archivo se termine deje de revisarlo con un feof

struct Local
{
    int cod;
    char titulo[30];
    char autor[20];
    char editorial[20];
    int stock;
    char genero[10];
};

struct Deposito
{
    int codigo;
    int cantidad;
};

int main()
{
    FILE*local=fopen("StockEnLocal.dat","rb");
    FILE*deposito=fopen("StockEnDeposito.dat","rb");

    Local l;
    fread(&l,sizeof(Local),1,local);

    Deposito d;
    fread(&d,sizeof(Deposito),1,deposito);

    int faltantes=0;

    cout<<"libros faltantes:"<<endl;
    cout<<"codigo          observacion"<<endl;


if(local!=NULL && deposito!=NULL)
{
    while(!feof(local) || !feof(deposito))
    {
        if(l.cod==d.codigo)
        {
            if(d.codigo==0 && l.cod==0)
            {
                cout<<d.codigo<<"          faltante en local y en deposito"<<endl;
                faltantes++;
                fread(&l,sizeof(Local),1,local);
                fread(&d,sizeof(Deposito),1,deposito);
            }
            else
            {
                if(d.codigo==0)
                {
                    cout<<d.codigo<<"      faltante en deposito"<<endl;
                    faltantes++;
                }
                else 
                {
                    if(l.cod==0)
                    {
                        cout<<l.cod<<"       faltante en local"<<endl;
                        faltantes++;
                    }
                }
                fread(&l,sizeof(Local),1,local);
                fread(&d,sizeof(Deposito),1,deposito);
            }
        }
        else
        {
            if(l.cod>d.codigo)
            {
                if(d.codigo==0)
                {
                    cout<<d.codigo<<"      faltante en deposito"<<endl;
                    faltantes++;
                }
                fread(&d,sizeof(Deposito),1,deposito);
            }
            else
            {
                if(l.cod==0)
                {
                    cout<<l.cod<<"       faltante en local"<<endl;
                    faltantes++;
                }
                fread(&d,sizeof(Deposito),1,deposito);
            }
        }
    }
    cout<<"Total de libros faltantes"<<faltantes<<endl;
}

else
{
    cout<<"hubo un error al abrir un archivo"<<endl;
}

    fclose(deposito);
    fclose(local);

return 0;

}