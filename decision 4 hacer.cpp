//confeccionar un programa que solicite dos valores reales positivos, espresados en cm.
//El primero corresponde a la base y el segundo a la altura de un triangulo, se desea calcular el valor de la superficie. 
//Si la superficie calculada es menor a 100cm2, expresarla en milimetros cuadrados, caso contrario en metros cuadrados. (informar con unidades)

#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese dos medidas con valores reales positivos expresados en cm"<<endl;

    int base, altura=0;
    cin>>base>>altura;

    int superficie= (base*altura)/2;

    if(superficie<100)
    {
        superficie=superficie*100;
        cout<< "la superficie del triangulo es "<< superficie <<"mm2";
    }

    else
    cout<< "la superficie del triangulo es "<< superficie <<"cm2";

    return 0;
}