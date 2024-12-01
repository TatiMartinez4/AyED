//Dados 50 valores distintos que se ingresan por teclado, mostrar en qué posición se ingresó el mayor.

#include <iostream>
using namespace std;

int main()
{
    int num1, nummax=0;
    int pos=1;
    int aux=1;

    cout<<"ingresa un numero"<<endl;
    cin>>nummax;

    while(aux<50)
    {
        cout<<"ingresa un numero"<<endl;
        cin>>num1;

        if(num1>nummax)
        {
            nummax=num1;
            pos=aux+1;
        }

        aux++;

    }

    cout<<"el numero mas grande es "<<nummax<<" y se encuentra en la posicion "<<pos<<endl;

    return 0;
}