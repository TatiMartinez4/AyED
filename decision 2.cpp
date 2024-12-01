//Dado un numero que se ingresa por teclado, informar si es par o impar

#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese un numero"<<endl;
    int num=0;
    cin>>num;

    if(num%2==0)
    {
        cout<<"el numero "<< num<< " es par"<<endl;
    }

    else
    cout<<"el numero "<<num<<" es impar"<<endl;

    return 0;
}