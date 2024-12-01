/*17) Dado un conjunto de triángulos representados por sus lados lado1, lado2 y lado3 dados como
datos, determinar e imprimir la cantidad de triángulos equiláteros, isósceles y escalenos. El
ingreso de datos finaliza cuando un lado es nulo*/

#include <iostream>
using namespace std;

int main()
{
    int lado1=0;
    int lado2=0;
    int lado3=0;
    int cantEquilatero=0;
    int cantIsoceles=0;
    int cantEscaleno=0;

    cout<<"ingrese los 3 lados de un triangulo"<<endl;
    cin>>lado1>>lado2>>lado3;

    while(lado1>0 && lado2>0 && lado3>0)
    {
        if(lado1==lado2 && lado1==lado3)
        {
            cantEquilatero++;
        }
        else
        {
            if(lado1!=lado2 && lado2!=lado3 && lado3!=lado1)
            {
                cantEscaleno++;
            }
            else
            {
                cantIsoceles++;
            }
        }
   
    cout<<"ingrese los 3 lados de un triangulo"<<endl;
    cin>>lado1>>lado2>>lado3;

    }

    cout<<"la cantidad de triangulos equilateros es "<<cantEquilatero<<endl;
    cout<<"la cantidad de triangulos escalenos es "<<cantEscaleno<<endl;
    cout<<"la cantidad de triangulos isoceles es "<<cantIsoceles<<endl;
    
    return 0;
}