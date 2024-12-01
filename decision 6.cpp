//Escribir un algortimo que lea dos fechas (diamesaño) e informe cual es la mas reciente

#include <iostream>
using namespace std;

int main ()
{
    cout<<"ingrese dos fechas en el formato dia, mes, anio"<<endl;
    int dia1, mes1, anio1, dia2, mes2, anio2 = 0;
    cin>>dia1>>mes1>>anio1;
    cin>>dia2>>mes2>>anio2;

    if(anio1==anio2)
    {
        if(mes1==mes2)
        {
            if(dia1>dia2)
            {
                cout<<"la fecha mas cercana es "<< dia1 << mes1 << anio1 <<endl;
            }
            else
            {
                cout<<"la fecha mas cercana es "<< dia2 << mes2 << anio2 <<endl;
            }
            
        }
        else
        {
            if(mes1>mes2)
            {
                cout<<"la fecha mas cercana es "<< dia1 << mes1 << anio1 <<endl;
            }
            else
            {
                cout<<"la fecha mas cercana es "<< dia2 << mes2 << anio2 <<endl;
            }
        }
    }
   
    else
    {
        if(anio1>anio2)
        {
            cout<<"la fecha mas cercana es "<< dia1 << mes1 << anio1 <<endl;
        }
        else
        {
            cout<<"la fecha mas cercana es "<< dia2 << mes2 << anio2 <<endl;
        }
    }

    return 0;
}