
/*En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos contra
todos. Por cada partido disputado por un equipo se dispone de la siguiente información :
a) Nombre del equipo,
b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
Se arma un lote de datos con todos los resultados del torneo, agrupados por nombre del
equipo.
Desarrollar el programa que imprima:
Por cada equipo, su nombre y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata).*/

#include <iostream>
using namespace std;

int main()
{
    int cantEquipos=0;
    cout <<"ingrese la cantidad de equipos"<<endl;
    cin>>cantEquipos;


    string nomEquipo;
    char resultado;
    int punto, puntosTotales=0;


    int aux1, aux2= 0;

    while(cantEquipos>aux1)
    {   
        //se debe ingresar el nombre del equipo y todos su resultados. Si son 3 equipos cada equipo tiene 2 resultados. Osea la cantidad de partidos por equipo es igual a la cantidad de equipos - 1
        cout<<"ingrese nombre del equipo"<<endl;
        cin>>nomEquipo;

        aux2=1;
        puntosTotales=0;

        while(cantEquipos>aux2)
        {
            cout<<"ingrese el codigo del resultado del partido (P, E o G)"<<endl;
            cin>>resultado;

            switch(resultado)
            {
                case 'G':
                punto=3;
                break;

                case 'E':
                punto=1;
                break;

                case 'P':
                punto=0;
                break;
            }

            puntosTotales= puntosTotales + punto;

            aux2++;
        }

        cout<<"el equipo "<< nomEquipo <<" tiene en total " << puntosTotales << " puntos"<< endl;

        aux1++;
    }

    return 0;
}