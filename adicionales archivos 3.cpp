/*
En un comercio se tiene el archivo “VentasJunio.dat” con un registro por cada uno de los 30 días del mes de junio con las ventas acumuladas de ese día. 
Cada registro tiene día, importe total y cantidad de ventas. El archivo está ordenado por día. 

Hacer un programa que informe el importe de las ventas del día 15 y además que informe cuándo hubo más ventas, si el primero o el último día del mes
*/

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>

struct Venta
{
    int dia; //ordenado
    double importe;
    int cantidad;
};

int binaria(FILE*f,int t, int bus);

int main()
{
    FILE*ventas=fopen("VentasJunio.dat","rb");
    fseek(ventas,0,SEEK_END);
    int t= ftell(ventas)/sizeof(Venta);
    int pos15= binaria(ventas,t, 15);
    fseek(ventas,pos15*sizeof(Venta),SEEK_SET);

    Venta v;
    fread(&v,sizeof(Venta),1,ventas);

    cout<<"importe de las ventas del dia 15: "<< endl;

    while(v.dia==15)
    {
        cout<<v.importe<<endl;
        fread(&v,sizeof(Venta),1,ventas);
    }

    fseek(ventas,0,SEEK_SET);
    fread(&v,sizeof(Venta),1,ventas);

    int ventas1Dia=v.cantidad;

    fseek(ventas,0,SEEK_END);
    fread(&v,sizeof(Venta),0,ventas);

    int ventas30Dia=v.cantidad;

    if(ventas30Dia<ventas1Dia)
    {
        cout<<"hay mas ventas el primer dia que el ultimo"<<endl;
    }
    else
    {
        cout<<"hay mas ventas el ultimo dia que el primero"<<endl;
    }

    fclose(ventas);

return 0;
}

int binaria(FILE*f,int t, int bus)
{
    int pos=-1, desde=0, hasta=t-1,medio;
    Venta e;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        fseek(f,medio*sizeof(Venta),SEEK_SET);
        fread(&e,sizeof(Venta),1,f);
        if(e.dia==bus)
        {
            pos=medio;
        }
        else
        {
            if(bus<e.dia)
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