/*
1) Dado el archivo “ALUMNOS.dat” con los datos personales de alumnos ordenado por legajo, con el siguiente diseño:
a.1 Legajo
a.2 Apellido y nombre ( 30 caracteres)
a.3 Domicilio (20 caracteres)
a.4 Código postal
a.5 Teléfono (10 caracteres)
a.6 Año de ingreso
Y otro archivo sin orden llamado “NOVEDADES.dat”, con cantidad máxima de registros es 100. Posee las actualizaciones (altas, bajas, y modificaciones) a ser aplicadas, donde cada registro 
contiene además de todos los campos de Alumnos.dat un código de operación (‘A’= Alta, ‘B’= Baja, ‘M’= Modificación).
Se pide desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado “ALUMACTU.dat” con el mismo diseño.
*/

#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring> //para comparar y copiar cadenas de caracteres

struct Alumno
{
    int legajo;
    char nombre[30];
    char domicilio[20];
    int cp;
    double telefono;
    int anio;
};

struct Novedades
{
    int legajo;
    char nombre[30];
    char domicilio[20];
    int cp;
    double telefono;
    int anio;
    char codigo;
};

int cargarNovedadesAux(FILE*novedades, Novedades v[], int t);
void ordenarVPorLegajo(Novedades v[], int cant);
void cargarNuevoArchivo(FILE*alu, Novedades nov[], int cant, FILE*act);

int cargarNovedadesAux(FILE*novedades, Novedades v[], int t)
{
    int i=0;
    Novedades aux;
    fread(&aux,sizeof(Novedades),1,novedades);
    while(i<t && !feof(novedades))
    {       
        v[i]=aux;
        i++;
        fread(&aux,sizeof(Novedades),1,novedades);
    }
    return i;
}

void ordenarVPorLegajo(Novedades v[], int cant) //por metodo de burbujeo
{
    int i=1;
    int j;
    Novedades aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<cant-i; j++)
        {
            if(v[j].legajo>v[j+1].legajo)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while (i<cant && cambio);    
}

void cargarNuevoArchivo(FILE*alu, Novedades nov[], int cant, FILE*act) //alu y nov estan ordenados por legajo
{
    int i=0;
    Alumno aux;
    fread(&aux,sizeof(Alumno),1,alu);
    while(!feof(alu) && i<cant)
    {
        if(aux.legajo==nov[i].legajo)
        {
            //hay que hacer los casos
            switch(nov[i].codigo)
            {
                case 'B': //simplemento lo salteo pq se da de baja
                i++;
                fread(&aux,sizeof(Alumno),1,alu);
                break;

                case 'M': //tengo que copiar los datos modificados. A act no le puedo meter directamente lo de nov pq tiene el campo codigo
                fwrite(&nov[i], sizeof(Alumno),1,act);
                fread(&aux,sizeof(Alumno),1,alu);
                i++;
            }
        }
        else
        {
            if(aux.legajo<nov[i].legajo)
            {
                //hay que cargar lo de aux a act
                fwrite(&aux,sizeof(Alumno),1,act);
                fread(&aux,sizeof(Alumno),1,alu);
            }
            else
            {
                //hay que cargar lo de nov a act. Tener en cuenta que nov tiene un campo extra que nov no debe contener
                fwrite(&nov[i],sizeof(Alumno),1,act);
                i++;
            }
        }

        while(i<cant)
        {
            fwrite(&nov[i],sizeof(Alumno),1,act);
            i++;
        }
    }
}

int main()
{
    FILE*alumnos;
    alumnos=fopen("ALUMNOS.dat","rb");

    FILE*novedades;
    novedades=fopen("NOVEDADES.dat","rb");

    FILE*actualizado;
    actualizado=fopen("ALUMACTU.dat","wb");

    if(alumnos==NULL || novedades==NULL || actualizado==NULL)
    {
        cout<<"hubo un problema al abrir alguno de los archivos necesarios"<<endl;
    }
    else
    {
        Novedades v[100];
        int cant=cargarNovedadesAux(novedades, v, 100);
        ordenarVPorLegajo(v,cant);
        cargarNuevoArchivo(alumnos,v,cant,actualizado);
    }

    fclose(alumnos);
    fclose(novedades);
    fclose(actualizado);
}