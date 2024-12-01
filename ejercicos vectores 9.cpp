//9. Dado un vector notas y un vector de numeros de documentos paralelo al vector de notas,
//informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor nota.

#include <iostream>
using namespace std;
int cargarVector(int v[]);
void ordenar(int v[], int d[], int t);
void informarMenores(int v[], int d[],int t);
void informarMayores(int v[], int d[],int t);


int main()
{
    int notas[100];
    int documentos[100];
    int t=cargarVector(notas);
    cargarVector(documentos);
    ordenar(notas,documentos,t);

    cout<<"los alumnos que tiene la menor nota "<<notas[0]<< " son:"<<endl;
    informarMenores(notas,documentos,t);
    cout<<"los alumnos que tiene la mayor nota "<<notas[t-1]<< " son:"<<endl;
    informarMayores(notas,documentos,t);

    return 0;
}

int cargarVector(int v[])
{
    int i=0;
    int num=0;
    cout<<"ingrese un numero"<<endl;
    cin>>num;

    while(num!=0)
    {
        v[i]=num;
        cout<<"ingrese un numero"<<endl;
        cin>>num;
    }

    return i;
}


void ordenar(int n[], int d[], int t)
{
    int i,aux1,aux2,j;
    for(i=1; i<t; i++)
    {
        aux1=n[i];
        aux2=d[i];

        j=i-1;

        while(j>=0 && n[j]>aux1)
        {
            n[j+1]=n[j];
            d[j+1]=d[j];
            j--;
        }
        n[j+1]=aux1;
        d[j+1]=aux2;
    }
}

void informarMenores(int n[], int d[],int t)
{
    int i=0;

    while(i<t && n[i]==n[0])
    {
        cout<<d[i]<<endl;
        i++;
    }

}

void informarMayores(int n[], int d[],int t)
{
    int i=t-1;

    while(i>0 && n[i]==n[t-1])
    {
        cout<<d[i]<<endl;
        i--;
    }

}