//Dados 50 valores distintos que se ingresan por teclado, mostrar los dos mayores.

#include <iostream>
using namespace std;

int main()
{
    int nummax=0;
    int nummax2=0;
    int num=0;
    int aux1=2;
    int aux=0;

    cout<<"ingrese un numero"<<endl;
    cin>>nummax;

    cout<<"ingrese un numero"<<endl;
    cin>>nummax2;

    if(nummax<nummax2)
    {   
        aux=nummax;
        nummax=nummax2;
        nummax2=aux;
    }

    while(aux1<50)
    {
            cout<<"ingrese un numero"<<endl;
            cin>>num;

            if(num>nummax)
            {
                nummax2=nummax;
                nummax=num;
            }
            else
            {
                if(num>nummax2)
                {
                    nummax2=num;
                }
            }

        aux1++;
    }

    cout<<"el numero mas grande es "<<nummax<<" y el segundo numero mas grande es "<<nummax2<<endl;


    return 0;
}