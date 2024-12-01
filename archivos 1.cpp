/*
1) Se dispone de un conjunto de inscripciones de alumnos a examen en el mes de mayo.
Cada inscripción tiene los siguientes datos: nombre y apellido, número de legajo, código de materia, día, mes y año del examen. Los datos finalizan con un número de legajo igual a cero.
Desarrollar un programa que a partir del ingreso de las inscripciones por teclado, genere un archivo binario de inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente 
diseño:
a.1 Nro. de legajo
a.2 Código de materia
a.3 Día del examen
a.4 Mes del examen
a.5 Año del examen
a.6 Nombre-Apellido
*/

#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

struct Alumno
{
    int legajo;
    int cod;
    int dia;
    int mes;
    int anio;
    char nombre[50];
};

int main()
{
    Alumno a;
    cout<<"ingrese el numero de legajo (0 si desea terminar)"<<endl;
    cin>>a.legajo;

    FILE*f;
    f=fopen("DIAFINALES.DAT","wb");
    
    if(f!=NULL)
    {
        while(a.legajo!=0)
        {
            cout<<"ingrese el codigo de la materia"<<endl;
            cin>>a.cod;

            cout<<"ingrese el dia"<<endl;
            cin>>a.dia;

            cout<<"ingrese el mes"<<endl;
            cin>>a.mes;

            cout<<"ingrese el anio"<<endl;
            cin>>a.anio;

            cout<<"ingrese nombre-apellido respetando formato"<<endl;
            cin>>a.nombre;

            fwrite(&a,sizeof(Alumno),1,f);

            cout<<"ingrese el numero de legajo (0 si desea terminar)"<<endl;
            cin>>a.legajo;
        }
    }
    
    else
    {
        cout<<"hubo un error al crear el archivo DIAFINALES.DAT"<<endl;
    }

    fclose(f);

    return 0;
}