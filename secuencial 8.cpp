//Determinar el porcentaje de alumnos aprobados, desaprobados y ausentes que hubo en un examen concociendo las cantidades de c/u

#include <iostream>
using namespace std;

int main ()
{
    int aprobados, desaprobados, ausentes = 0;
    cout<<"ingrese la cantidad de aprobados"<<endl;
    cin>>aprobados;
    cout<<"ingrese la cantidad de desaprobados"<<endl;
    cin>>desaprobados;
    cout<<"ingrese la cantidad de ausentes"<<endl;
    cin>>ausentes;

    int cantidad= aprobados+desaprobados+ausentes;

    float paprobados= float(aprobados* 100) / cantidad;
    cout<<"el procentaje de aprobados es "<< paprobados << endl;

    float pdesaprobados= float(desaprobados* 100) / cantidad;
    cout<<"el procentaje de desaprobados es "<< pdesaprobados << endl;

    float pausentes= float(ausentes*100)/cantidad;
    cout<<"el procentaje de ausentes es "<< pausentes << endl;

return 0;

}