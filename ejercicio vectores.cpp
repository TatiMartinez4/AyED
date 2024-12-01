/*Se ingresan por teclado los datos de los estudiantes inscriptos en la materia AYED.
De cada ALUMNO se ingresa:
-DNI se guarda en un vector de alumnos
-Nombre y apellido innecesario
-Curse (1 a 8) en un vector de 8 se guarda la cant de alumnos por curso

El ingreso finaliza von DNI=0

Se sabe que como max hay 500 alumnos

Se pide:
a. Mostrar un listado de todos los inscriptos ordenados alfabeticamente,
b. Mostrar la cantidad de inscriptos por cada curso*/

#include <iostream>
using namespace std;

int ingresarAlumnos(string a[], int c[], int t);
void ordenar(string a[], int t);
void mostrar(string a[], int t);
void mostrar(int c[], int t);

int main()
{
    string alumnos[500];
    int cantPorCurso[8]={0};

    int cantAlumnos= ingresarAlumnos(alumnos,cantPorCurso,500);
    ordenar(alumnos,cantAlumnos);


    cout<<"los alumnos inscriptos son: "<<endl;
    mostrar(alumnos,cantAlumnos);

    mostrar(cantPorCurso,8);
}

int ingresarAlumnos(string a[], int c[], int t)
{
    cout<<"ingrese el numero de dni del alumno"<<endl;
    int dni=0;
    cin>>dni;
    int i=0;
    int aux;

    while (dni!=0)
    {
        cout<<"ingrese el nombre del alumno"<<endl;
        cin>> a[i];

        cout<<"ingrese el curso del alumno "<<endl;
        cin>>aux;

        c[aux-1]++;

        /* code */
        cout<<"ingrese el dni del alumno"<<endl;
        cin>>dni;

        i++;
    }
    
    return i;
}

void ordenar(string a[], int t)
{
    int i=1,j;
    string aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(a[j]>a[j+1])
            {
                aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    }
    while (i<t && cambio);
}

void mostrar(string a[], int t)
{
    for(int i=0; i<t;i++)
    {
        cout<<a[i]<<endl;
    }
}

void mostrar(int c[], int t)
{
    for(int i=0; i<t;i++)
    {
        cout<<"la cantidad de alumnos del curso "<< i+1<<" es: "<< c[i]<<endl;
    }
}