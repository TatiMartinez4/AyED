/* 15) Ingresar edades comprendidas entre 18 y 22, e imprimir cuántas veces se ingresó cada una de estas
edades. El lote finaliza con una edad igual a cero
*/

#include <iostream>
using namespace std;

int main()
{
    int edad=0;
    int cont18=0;
    int cont19=0;
    int cont20=0;
    int cont21=0;
    int cont22=0;

    cout<<"ingrese un numero entre 18 y 22"<<endl;
    cin>>edad;

    while(edad!=0)
    {
        switch(edad)
        {
            case 18:
            cont18++;
            break;

            case 19:
            cont19++;
            break;

            case 20:
            cont20++;
            break;

            case 21:
            cont21++;
            break;

            case 22:
            cont22++;
            break;
        }

        cout<<"ingrese un numero entre 18 y 22 o 0 si desea terminar"<<endl;
        cin>>edad;
    }

    cout<<"la cantidad de veces que se ingreso 18 es "<<cont18<<endl;
    cout<<"la cantidad de veces que se ingreso 19 es "<<cont19<<endl;
    cout<<"la cantidad de veces que se ingreso 20 es "<<cont20<<endl;
    cout<<"la cantidad de veces que se ingreso 21 es "<<cont21<<endl;
    cout<<"la cantidad de veces que se ingreso 18 es "<<cont22<<endl;


    return 0;
}