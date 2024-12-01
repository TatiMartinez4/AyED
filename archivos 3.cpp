#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

/*
3) Dado el archivo binario generado en el ejercicio 1, que contiene todas las inscripciones del día, y otro con el mismo diseño que contiene las inscripciones anteriores (FINALES.DAT),
desarrolle un programa que agregue al archivo de inscripciones anteriores el contenido del archivo del día.
*/

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
    FILE*ej1=fopen("DIAFINALES.DAT","rb");
    FILE*nuevo=fopen("FINALES.DAT","ab");

    if(ej1!=NULL && nuevo!=NULL)
    {
        Alumno aux;
        fread(&aux,sizeof(Alumno),1,ej1);
        while(!feof(ej1))
        {   
            fwrite(&aux,sizeof(Alumno),1,nuevo);
            fread(&aux,sizeof(Alumno),1,ej1);
        } 
    }
    else
    {
        cout<<"error al abrir los archivos"<<endl;
    }

    fclose(ej1);
    fclose(nuevo);

    return 0;
}