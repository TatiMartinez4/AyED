/*
10) Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al
exterior.

Para ello cuenta con la siguiente información:

De cada vuelo realizado el número de vuelo, destino, y cantidad de asientos.

De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.

La información de los pasajeros de cada vuelo finaliza con un número de pasaporte igual a cero.

Se pide emitir el siguiente listado:
Nro. de Vuelo ………. Destino: ………..
Nro. de Pasaporte Importe en u$s
…………. ………….
 …………. ………….
 Total recaudado del vuelo: ………
Cantidad de asientos libres: ………
Número de vuelo que más recaudó: ……..
*/

#include <iostream>
using namespace std;

int main ()
{

    int aux=0;
    int cantvuelos=0;

    cout<<"ingrese la cantidad de vuelos al exterior del mes"<<endl;
    cin>>cantvuelos;

    unsigned long numvuelo=0;
    string destino;
    int cantasientostotales=0;

    unsigned long long pasaporte=0;
    int importe=0;

    unsigned long importetotal=0;
    int ocupados=0;

    int masrecaudo=0;
    unsigned long nummasrecaudo=0;

    while(aux < cantvuelos)
    {
        cout<<"ingrese el numero de vuelo "<<endl;
        cin>>numvuelo;

        cout<<"ingrese el destino "<<endl;
        cin>>destino;

        cout<<"ingrese la cantidad de asientos "<<endl;
        cin>>cantasientostotales;

        cout<<"ingrese el numero de pasaporte"<<endl;
        cin>>pasaporte;


        if(importetotal>masrecaudo)
        {
            masrecaudo=importetotal;
            nummasrecaudo=numvuelo;
        }

        cout<<"Total recaudado del vuelo "<< importetotal  <<"Cantidad de asientos libres "<<cantasientostotales-ocupados<<endl;

        importetotal=0;;
        aux++;
        ocupados=0;
    }

    cout<<"Numero de vuelo que mas recaudo: "<<nummasrecaudo<<endl;

    return 0;
}