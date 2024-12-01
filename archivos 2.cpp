#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

/*2) Dado el archivo binario generado en el ejercicio 1, desarrolle un programa que solicitando por teclado un código de materia permita seleccionar todos los registros 
de alumnos que se anotaron para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo diseño.*/

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
    cout<<"ingrese el codigo de la materia"<<endl;
    int codigo=0;
    cin>>codigo;

    FILE*f=fopen("DIAFINALES.DAT","rb");
    if(f!=NULL)
    {
        FILE*finales=fopen("MATFINALES.DAT","wb");
        if(finales!=NULL)
        {
            Alumno aux;
            fread(&aux,sizeof(Alumno),1,f);
            while(!feof(f));
            {
                if(codigo==aux.cod)
                {
                    fwrite(&aux,sizeof(Alumno),1,finales);
                }
                fread(&aux,sizeof(Alumno),1,f);
            } 

            fclose(finales);
        }
        fclose(f);
    }
}