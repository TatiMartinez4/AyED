#include <iostream>
using namespace std;

int main()
{
    cout<< "ingrese la cantidad de numeros que desea ingresar"<< endl;
    int cant=0;
    int sum=0;
    cin>>cant;
    for(int i= 0; i<cant ; i++)
    {
        cout<<"ingrese un numero"<<endl;
        int num=0;
        cin>>num;
        sum+= num;
    }
    cout<< "el promedio es "<< (float) sum/cant<< endl;
    return 0;
}