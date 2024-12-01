//Dados 3 valores que se ingresan por teclado, mostrar por pantalla el valor mayor.

#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese 3 valores numericos"<<endl;
    int val1, val2, val3 = 0;
    cin>>val1>>val2>>val3;

    if(val1>val2)
    {
        if(val1>val3)
        {
            cout<<"el numero mas grande es "<<val1<< endl;
        }
        else
        {
            cout<<"el numero mas grande es "<<val3<< endl;
        }
    }
    else
    {
        if (val2>val3)
        {
            cout<<"el numero mas grande es "<<val2<< endl;
        }
        else
        {
        cout<<"el numero mas grande es "<<val1<< endl;
        }
    }

    return 0;
}