/*rehacer el ejercicio 9 con un vector struct
Dado un struct alumno que contenga las notas y los documenos, informar el dni
de los alumnos que tienen la mayor nota y el dni de los que tienen menor nota
*/

#include <iostream>
using namespace std;

struct Alumno
{
    double nota;
    int dni;
};

void ingresar(Alumno a[], int t);
int mayores(Alumno a[], int v[], int t, double& mayor);
int menores(Alumno a[], int v[], int t, double& menor);
void leerVector(int vector[], int tam);

int main()
{
    int t=10;
    Alumno alumnos[t];

    ingresar(alumnos,t);

    int dniMayoresNotas[t];
    double mayor=0;
    int cantMayores= mayores(alumnos,dniMayoresNotas,t,mayor);
    cout<<"los alumnos con la mayor nota ("<<mayor<<") son: "<<endl;
    leerVector(dniMayoresNotas, cantMayores);


    int dniMenoresNotas[t];
    double menor=0;
    int cantMenores= menores(alumnos, dniMenoresNotas,t,menor);
    cout<<"los alumnos con la menor nota ("<<menor<<") son:"<<endl;
    leerVector(dniMenoresNotas, cantMenores);
    
    return 0;
}

void ingresar(Alumno a[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"ingrese el dni del alumno"<<endl;
        cin>> a[i].dni;

        cout<<"ingrese la nota del alumno"<<endl;
        cin>>a[i].nota;
    }
}

int mayores(Alumno a[], int v[], int t, double& mayor)
{
    int i=1;
    int cantDeMax=0;
    mayor=a[0].nota;
    v[0]=a[0].dni;

    while (i<t)
    {
        if(a[i].nota > mayor)
        {
            mayor=a[i].nota;
            cantDeMax=0;
            v[0]=a[i].dni;
            cantDeMax++;
            
        }
        else
            if(a[i].nota == mayor)
            {
                v[cantDeMax]=a[i].dni;
                cantDeMax++;
            }
        i++;
    }
    return cantDeMax;
}

int menores(Alumno a[], int v[], int t, double& menor)
{
    int i=1;
    int cantDeMin=0;
    menor=a[0].nota;
    v[0]=a[0].dni;

    while (i<t)
    {
        if(a[i].nota < menor)
        {
            v[0]=a[i].dni;
            cantDeMin=0;
            menor=a[i].nota;
            cantDeMin++;

        }
        else
            if(a[i].nota == menor)
            {
                v[cantDeMin]=a[i].nota;
                cantDeMin++;
            }
        i++;
    }
    return cantDeMin;
}

void leerVector(int vector[], int tam)
{
    for(int i=0; i<tam; i++)
        cout<<vector[i]<<endl;
}