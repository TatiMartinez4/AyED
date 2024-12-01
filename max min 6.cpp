/*
6) Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un
Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven
*/

#include <iostream>
using namespace std;

int main ()
{
    string nombre1;
    int fecha1=0;

    int fechamenor= 00000000;
    int fechamayor= 99999999;
    string nombremenor, nombremayor;

    cout<<"ingrese un nombre" <<endl;
    cin>>nombre1;

    while(nombre1!="FIN")
    {
        cout<<"ingrese una fecha"<<endl;
        cin>>fecha1;

        if(fecha1<fechamayor)
        {
            nombremayor= nombre1;
            fechamayor= fecha1;
            if(fecha1>fechamenor)
            {
                nombremenor= nombre1;
                fechamenor=fecha1;
            }
        }

        else
        {
            if(fecha1>fechamenor)
            {
                nombremenor= nombre1;
                fechamenor=fecha1;
            }
        }

        cout<<"ingrese un nombre"<<endl;
        cin>>nombre1;
    }

    cout<<"la persona de mayor edad es "<< nombremayor<< " la persona de menor edad es "<< nombremenor <<endl;

    return 0;
}