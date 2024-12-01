//Dados 50 valores distintos que se ingresan por teclado, mostrar el menor.

#include <iostream>
using namespace std;

int main()
{
    int numero1=0;
    int numeromin=0;
    int aux=1;

    cout<<"ingrese un numero"<<endl;
    cin>>numeromin;

    while(aux<50)
    {
        cout<<"ingrese otro numero"<<endl;
        cin>>numero1;

        if(numero1<numeromin)
        {
            numeromin=numero1;
        }
  
        aux++;
    }

    cout<<"el numero mas chico es "<<numeromin<<endl;

    return 0;
}