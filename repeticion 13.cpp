//13) Hacer un algoritmo que calcule el promedio de números enteros positivos ingresados por teclado
//hasta que se ingrese un cero. Este cero sólo indica el fin de ingreso de datos, no se incluirá en el
//promedio.

#include <iostream>
using namespace std;

int main()
{
    int numero=0;
    int cantidad=0;
    int total=0;
    double promedio=0;

    cout<<"ingrese un numero"<<endl;
    cin>>numero;

    while(numero!=0)
    {
        if(numero>0)
        {
            total+=numero;
            cantidad++;
        }

        cout<<"ingrese un numero"<<endl;
        cin>>numero; 
    }

    if(cantidad>0)
    {
        promedio=double(total/cantidad);

        cout<<"el promedio de numeros enteros positivos ingresados es "<< promedio <<endl;
    }
    
    else
    {
    cout<<"no se ingresaron numeros enteros positivos" <<endl;
    }
    

    return 0;
}