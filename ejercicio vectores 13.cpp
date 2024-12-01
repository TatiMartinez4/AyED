/*13) Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.

Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
materia, según lo siguiente:
- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
- Primer o segundo parcial con nota menor a 6: RECURSA */

#include <iostream>
using namespace std;
#define t 6

struct Alumnos
{
    string nombre;
    double nota;
};

void condicion(Alumnos v1[],Alumnos v2[], string p[], string a[], string d[], int &cp, int &ca, int &cd);
void leer(string v[], int tam);

int main()
{
    Alumnos notasPrimerParcial[t]=
    {
        {"Ariana",10},{"Bionda",3},{"Charly",8},{"Damian",7},{"Eliana",5},{"Facundo",6}
    };

    Alumnos notasSegundoParical[t]=
    {
        {"Ariana",8},{"Bionda",7},{"Charly",6},{"Damian",5},{"Eliana",5},{"Facundo",6}
    };

    string promocionados[t];
    string aprobados[t];
    string desaprobados[t];

    int cantPromocionados=0;
    int cantAprobados=0;
    int cantDesaprobados=0;

    condicion(notasPrimerParcial, notasSegundoParical, promocionados, aprobados, desaprobados, cantPromocionados, cantAprobados, cantDesaprobados);

    cout<<"los alumnos que promocionaron son: "<<endl;
    leer(promocionados,cantPromocionados);

    cout<<"los alumnos que aprobaron son: "<<endl;
    leer(aprobados,cantAprobados);

    cout<<"los alumnos que desaprobaron son: "<<endl;
    leer(desaprobados,cantDesaprobados);


    return 0;
}

void condicion(Alumnos v1[],Alumnos v2[], string p[], string a[], string d[], int &cp, int &ca, int &cd)
{
    for(int i=0; i<t; i++)
    {
        if(v1[i].nota>=8 && v2[i].nota>=8)
        {
            p[cp]=v1[i].nombre;
            cp++;
        }
        else
        {
            if(v1[i].nota>=6 && v2[i].nota>=6)
            {
               a[ca]=v1[i].nombre;
               ca++;
            }
            else
            {
                d[cd]=v1[i].nombre;
                cd++;
            }
        }
    }
}

void leer(string v[], int tam)
{
    for(int i=0; i<tam; i++)
        cout<<v[i]<<endl;
}