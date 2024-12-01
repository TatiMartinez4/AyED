//12) Dado un número entero positivo informar su factorial.


#include <iostream>
using namespace std;

int main ()
{
    int numero,aux=0;
    int factorial=1;
    cout<<"ingrese un numero"<<endl;
    cin>>numero;

    while(aux<numero)
    {
        factorial=factorial * (numero-aux);
        aux++;
    }
    
    cout<<"el factorial de "<<numero<<" es "<< factorial<<endl;

    return 0;
}