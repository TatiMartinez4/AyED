#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

/*5) Se dispone un archivo binario de inscripción de alumnos a exámenes finales MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT, 
ambos ordenados ascendente por número de legajo y código materia y con el siguiente diseño:
a.1Nro de legajo
a.2 Código de materia
a.3 ApellidoNombre
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.*/

//crear nuevo archivo ordenado por Nro de legajo de menor a mayor.

struct Finales
{
    int legajo;
    int codigoMateria;
    char nombre[50];
};

int main()
{
    FILE*finales=fopen("MAESTROFINALES.DAT","rb");
    FILE*inscripciones=fopen("DIAFINALES.DAT","rb");
    FILE*todo=fopen("FINALESACT.DAT","wb");

    if(finales!=NULL && inscripciones!=NULL && todo!=NULL)
    {
        Finales aux;
        fread(&aux,sizeof(Finales),1,finales);
        Finales f;
        fread(&f,sizeof(Finales),1,inscripciones);

        while(!feof(finales) || !feof(inscripciones))
        {
            if(aux.legajo<=f.legajo)
            {
                //guardo aux en el archivo todo
                fwrite(&aux,sizeof(Finales),1,todo);
                fread(&aux,sizeof(Finales),1,finales);
            }
            else
            {
                //guardo f en el archivo todo
                fwrite(&f,sizeof(Finales),1,todo);
                fread(&f,sizeof(Finales),1,inscripciones);
            }
        }

        
    }
    else
    {
        cout<<"hubo un error en alguno de los archivos"<<endl;
    }

    fclose(finales);
    fclose(inscripciones);
    fclose(todo);

    return 0;
}