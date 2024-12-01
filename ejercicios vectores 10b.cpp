/*Dados los legajos y sueldos de los empleados de una empresa (maximo 100 empleados), we pide determinar el/los empleados de maximo sueldo
a)los numeros de legajo son numeros correlativos de 1 a 100
b)los nueros de legajo son numeros no correlativos de 4 cifras*/

#include <iostream>
using namespace std;

//b
void cargar(int v[], int t);
void ordenarMayorAMenor(int v[], int l [], int t);
void mostrarMaximos(int s[], int v[], int t);

int main()
{
    int tam=10;
    int legajos[tam];

    cout<<"ingrese los numeros de legajo"<<endl;
    cargar(legajos,tam);

    cout<<"ingrese los sueldos en el mismo orden"<<endl;    
    int sueldos[tam];
    cargar(sueldos,tam);

    ordenarMayorAMenor(sueldos, legajos,tam);

    cout<<"los legajos de los empleados con sueldo maximo "<< sueldos[0]<< " son: "<<endl;
    mostrarMaximos(sueldos,legajos,tam);
    
    return 0;
}

void cargar(int v[], int t)
{
    for(int i=0; i<t; i++)
    {
        cin>>v[i];
    }
}

void ordenarMayorAMenor(int v[], int l[], int t)
{
    int i,aux1,aux2,j;
    for(i=1; i<t; i++)
    {
        aux1=v[i];
        aux2=l[i];
        j=i-1;
        while(j>=0 && v[j]<aux1)
        {
            v[j+1]=v[j];
            l[j+1]=l[j];
            j--;
        }
        v[j+1]=aux1;
        l[j+1]=aux2;
    }
}


void mostrarMaximos(int s[], int v[], int t)
{
    int i=0;
    while(s[0]==s[i])
    {
        cout<<v[i]<<endl;
        i++;
    }
}

