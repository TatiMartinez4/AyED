/*2) Una biblioteca maneja la siguiente información:
a) un archivo de libros “Libros.dat”, ordenado por código de libro y con el siguiente diseño:
a.1 Código del libro
a.2 título del libro (30 caract)
a.3 cantidad de ejemplares
a.4 ubicación (3 caract)
a.5 código de la editorial (1..200)
a.6 autor (25 caract)
b) un archivo de editoriales “Editoriales.dat” ordenado alfabéticamente por nombre de la editorial, con el siguiente diseño.
b.1 nombre de la editorial (25 caracteres)
b.2 código de la editorial (1..200)
c) un archivo, ”Consultas.dat”, de consultas realizadas durante el primer semestre del año. Los diferentes libros consultados no superan los 1000, y el diseño del registro es el siguiente:
c.1 código del libro
c.2 fecha de consulta (aaaammdd)


Se pide realizar la metodología necesaria para obtener un programa que:
1) Emita un listado con los libros que tuvieron como mínimo 20 consultas en cada mes del semestre, con el siguiente diseño, ordenado por código:

Código del Libro           Título              Autor                 Editorial             Consultas en el Semestre
999999                      xxxxxxxxx          xxxxxxxxx              xxxxxxxxx             999 999 999 999 999 999
999999                      xxxxxxxxx          xxxxxxxxx              xxxxxxxxx             999 999 999 999 999 999

2) Grabe un archivo ordenado de mayor a menor por cantidad de libros consultados por editorial, con el siguiente diseño:
2.1 nombre de la editorial (25 caracteres)
2.2 cantidad de libros que fueron consultados en el semestre
*/

#include <iostream>
using namespace std;
#include<cstring>
#include <cstdio>

struct Libros
{
    int codigo; //ordenado por esto
    char titulo[30];
    int stock;
    char ubi[3];
    int editorial; //codigo editorial que va entre 1 y 200
    char autor[25];
};

struct Editoriales
{
    char editorial[25]; //ordenado por esto
    int editorial; //enlazado a libros por esto
};

struct Consultas //son menos de 1000
{
    int codigo; //codigo del libro
    int fecha; //fecha de la consulta
};

struct Archivo
{
    char editorial[25];
    int cantidad;
};

struct Contadores
{ 
    int codigo; //codigo del libro
    int contadores[6];
};

int convertirConsultasEnVector(FILE*consultas, Consultas v[], int t);

int convertirConsultasEnVector(FILE*consultas, Consultas v[], int t)
{
    Consultas aux;
    fread(&aux,sizeof(Consultas),1,consultas);
    int i=0;

    while(!feof(consultas))
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(Consultas),1,consultas);
    }
    return i;
}

int recorrerConsultas(Consultas v[],Contadores c[], int t)
{
    int cantidadLibrosConsultados=1;
    for(int i=0; i<t; i++)
    {
        int mes=(v[i].fecha/100)%100-1;
        bool encontrado=false;
        for(int j=0;j<t; j++ && !encontrado)
        {
            if(c[j].codigo==v[i].codigo)
            {
                c[j].contadores[mes]++;
                encontrado=true;
            }
        }
        if(!encontrado)
        {
            c[cantidadLibrosConsultados].codigo=v[i].codigo;
            c[cantidadLibrosConsultados].contadores[mes]++;
            cantidadLibrosConsultados++;
        }
    }
    return cantidadLibrosConsultados;
}

//hace un listado con los libros que tuvieron como minimo 20 consultas en cada mes


//HACER DESDE ACA
void mostrarPuntoUno(Contadores c[],int cantLibrosConsultados, FILE*libros, FILE*editoriales)
{
    cout<<"Código del Libro           Título              Autor                 Editorial             Consultas en el Semestre"<<endl;
    for(int i=0; i<cantLibrosConsultados; i++)
    {
        if(c[i].contadores[0]>=20 && c[i].contadores[1]>=20 && c[i].contadores[2]>=20 && c[i].contadores[3]>=20 && c[i].contadores[4]>=20 && c[i].contadores[5]>=20)
        {
            //recorro el archivo libros buscando el código. El archivo libros está ordenado asi que la busqueda es mas simple.
            
            char titulo[30]=
            char autor[25]=
            cout<<c[i].codigo<<"           "<<titulo<<"              "<<
        }
    }
}

int main()
{
    FILE*libros;
    libros=fopen("Libros.dat","rb");

    FILE*editoriales;
    editoriales=fopen("Editoriales.dat","rb");

    FILE*consultas;
    consultas=fopen("Consultas.dat","rb");

    //me conviene convertir consultas en un array de tipo CONSULTAS? SI

    Consultas v[1000];

    int cantidadDeConsultas= convertirConsultasEnVector(consultas, v ,1000);

    //necesito recorrer consultas y hacer un contador por libro. IMPORTA EL MES

    Contadores c[cantidadDeConsultas];

    //hasta acá dejé hecho!! 
    
    int cantLibrosConsultados=recorrerConsultas(v,c, cantidadDeConsultas);

    //tengo cantidad de consultas por libro por MES. Osea tengo 6 contadores.

    //punto 1) recorro cada codigo de libro de consultas y si el cont de cada mes es 20 o mas muestro toda la info
    mostrarPuntoUno(c,cantLibrosConsultados,libros,editoriales);

    //punto 2) ???
}