//dados 3 valores informar si el traingulo es isoceles, escalento o equilatero

#include <iostream>
using namespace std;

int main()
{
    int lado1,lado2,lado3=0;
    cout<<"ingrese las medidas de los tres lados de un triangulo"<<endl;
    cin>>lado1>>lado2>>lado3;

    if(lado1==lado2 && lado2==lado3)
    {
        cout<<"el triangulo es equilatero"<<endl;
    }

    else
    {
        if(lado1!=lado2 && lado2!=lado3 && lado1!=lado3)
        {
            cout<<"el triangulo es escaleno"<<endl;
        }
        else
        {
            cout<<"el triangulo es isoceles"<<endl;
        }
    }

    return 0;
}