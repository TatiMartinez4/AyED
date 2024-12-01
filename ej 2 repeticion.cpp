#include <iostream>
using namespace std;

int main()
{
    cout<< "ingrese la cantidad de alumnos de un curso"<< endl;

    int cantidad=0;

    cin>>cantidad;

    int i=0;

    while(i<cantidad)
    {
        if(i==0)
        {
            cout<<"ingrese el nombre del primer alumno alumno"<<endl;
        }

        else
        {
            cout<<"ingrese el nombre de otro alumno"<<endl;
        }
        
        string nombre;
        cin>>nombre;
        cout<<"ingrese sus dos notas"<<endl;
        int nota1=0;
        int nota2=0;
        cin>>nota1>>nota2;

        double prom= (double) (nota1+nota2)/2;

        cout<<"el alumno "<< nombre<< " tiene un promedio de "<< prom << endl;

        i++;
    }

    return 0;
}