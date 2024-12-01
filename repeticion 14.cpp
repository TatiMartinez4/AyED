/* 14) Desarrollar un algoritmo que permita ingresar un conjunto de valores, cada uno de los cuales
representa el sueldo de un empleado (se sabe que un sueldo igual a 0 indica el fin del conjunto), e
informe:
a) Cuántos empleados ganan menos de $900
b) Cuántos ganan $900 o más, pero menos de $1200
c) Cuántos ganan $1200 o más, pero menos de $2000
d) Cuántos ganan $2000 o más
*/

#include <iostream>
using namespace std;

int main()
{
    int sueldo=0; 
    int m900=0;
    int m1200=0;
    int m2000=0;
    int mas2000=0;
    cout<<"ingrese el sueldo"<<endl;
    cin>>sueldo;

    while(sueldo!=0)
    {
        if(sueldo<900)
        {
            m900++;
        }

        else
        {
            if(sueldo<1200)
            {
                m1200++;
            }
            else
            {
                if(sueldo<2000)
                {
                    m2000++;
                }
                else
                {
                    mas2000++;
                }
            }
        }

        cout<<"ingrese el sueldo"<<endl;
        cin>>sueldo;
    }

    cout<<m900<< " empleados ganan menos de 900"<<endl;
    cout<<m1200<< " empleados ganan entre 900 y 1200"<<endl;
    cout<<m2000<<" empleados ganan entre 1200 y 2000"<<endl;
    cout<<mas2000<<" empleados ganan mas de 2000"<<endl;

    return 0;

}