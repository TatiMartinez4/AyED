/*Dados los legajos y sueldos de los empleados de una empresa (maximo 100 empleados), we pide determinar el/los empleados de maximo sueldo
a)los numeros de legajo son numeros correlativos de 1 a 100
b)los nueros de legajo son numeros no correlativos de 4 cifras*/

#include <iostream>
using namespace std;

//a
void cargarVector(int v[],int tam);
int mayores(int s[], int m[], int t, int&mayor);
void mostrar(int v[], int t);

int main()
{
    int tam=10;
    int sueldos[tam];
    cargarVector(sueldos,tam);
    
    int m[tam]; //es el array que contiene todos los legajos de los que tienen mayor sueldo.
    int mayor=0; //es el sueldo mas alto

    int cantidadDeSueldosMayores = mayores(sueldos,m,tam,mayor);

    cout<<"los legajos de los empleados con el sueldo "<<mayor<<" son:"<<endl;
    mostrar(m,cantidadDeSueldosMayores);

    return 0;
}

void cargarVector(int v[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout<<"ingrese el sueldo del empleado "<< i+1 <<endl;
        cin>>v[i];
    }
}


int mayores(int s[], int m[], int t, int&mayor)
{
    int max=s[0];
    int i=1;
    int cantmax=0;
    m[0]=1;
    while(i<t)
    {
        if(s[i]>max)
        {
            max=s[i];
            cantmax=0;
            m[0]=i+1;
        }
        else
        {
            if(s[i]==max)
            {
                cantmax++;
                m[cantmax]=i+1;
            }
        }

        i++;

    }
    mayor=max;
    //quiero que me devuelva max tambien
    return cantmax;

}

void mostrar(int v[], int t)
{
    for(int i=0; i<=t; i++)
        cout<<v[i]<<endl;
}

