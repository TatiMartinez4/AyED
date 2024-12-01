/*15) Se tiene un vector con las notas de los exámenes rendidos por los alumnos (nombre y nota)
ordenado por nombre con un elemento por cada examen rendido (un alumno puede haber rendido 1,
2, ó más exámenes). Se pide generar un vector con un elemento por alumno con el promedio de las
notas de sus exámenes, ordenado por nombre.*/

//es mejorable por mucho este programa. Podria tener una cadena de strings que este asociada para informar con el nombre.

#include <iostream>
using namespace std;

void cargar(int a[][5], double p[],int t,int e);
void mostrar(double p[], int t);

int main()
{  
    int alumnos[3][5]=
    {
        {1,10,2,0,0},{3,4,5,9,0},{2,3,5,6,8}
    };

    double promedio[3];

    cargar(alumnos,promedio,3,5);    

    cout<<"los promedios de los alumnos"<<endl;

    mostrar(promedio,3);

    return 0;
}

void cargar(int a[][5], double p[],int t, int e)
{
    
    for(int i=0;i<t;i++)
    {   
        int aux=0;
        int b=0;
        while(b<e && a[i][b]!=0)
        {
            aux+=a[i][b];
            b++;
        }
        p[i]=double(aux)/b;
    }
}

void mostrar(double p[], int t)
{
    for(int i=0; i<3; i++)
        cout<<p[i]<<endl;
}