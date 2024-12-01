// 11) Dados n y m enteros positivos, informar su producto obtenido por sumas sucesivas.

#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese dos numeros"<<endl;
    int num1, num2, resultado=0;
    cin>>num1>>num2;

    int aux=0;

    while(aux<num2)
    {
        resultado+=num1;
        aux++;
    }

    cout<<"el resultado es "<< resultado <<endl;

    return 0;
}