/*
Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo
valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d) El promedio de todos los valores
*/

//falta arreglar por si no ingresa ningun negativo o ningun positivo
#include <iostream>
using namespace std;

int main ()
{
    int num=0;
    int nummax=-99999999;
    int nummin=999999999;
    int total=0;
    unsigned int aux=1;
    double promedio=0;

    cout<<"ingrese un numero"<<endl;
    cin>>num;
    if(num==0)
    {
        cout<<"no se ingreso ningun valor valido"<<endl;
    }

    else
    {
        while(num!=0)
        {
            if(num>0 && nummin>num)
            {
                nummin=num;
            }
            else
            {
                if(num>nummax)
                {
                    nummax=num;
                }
            }

        total= total + num;
        cout<<"ingrese un numero"<<endl;
        cin>>num;
        aux++;
        }

        promedio=double (total)/(aux-1);

        cout<<"el valor maximo negativo es "<<nummax<<" y el valor minimo positivo es "<<nummin<<endl;;

        cout<<"total "<<total<<" y aux "<< aux-1<<endl;
        
        cout<<"el promedio de todos los valores es "<<promedio<<endl;

    }
    

    return 0;
}