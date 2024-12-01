//Dados 50 valores que se ingresan por teclado, mostrar el mayor y la cantidad de veces que fue ingresado

#include <iostream>
using namespace std;

int main()
{
    int nummax=0;
    int num=0;
    int aux=1;
    int repeticion=1;

    cout<<"ingrese un numero"<<endl;
    cin>>nummax;

    while(aux<5)
    {
        cout<<"ingrese un numero"<<endl;
        cin>>num;

        if(num>nummax)
        {
            nummax=num;
            repeticion=1;
        }
        else
        {
            if(num==nummax)
            {
                repeticion++;
            }
        }


        aux++;
    }

    cout<<"el numero mas grande es "<< nummax<< " y se ingreso "<<repeticion<<" veces."<<endl;

    return 0;
}