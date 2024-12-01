#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>
/*
Dado el archivo ‘ALUMNOS.dat’ con los datos personales de alumnos ordenado por legajo, con el siguiente diseño:
a.1 Legajo
a.2 Apellido y nombre ( 30 caracteres)
a.3 Domicilio (20 caracteres)
a.4 Código postal
a.5 Teléfono (10 caracteres)
a.6 Año de ingreso
Y otro archivo con el mismo orden que el mencionado llamado “NOVEDADES.dat”, con las actualizaciones (altas, bajas, y modificaciones) a ser aplicadas, donde cada registro contiene además 
de todos los campos de Alumnos.dat un código de operación (‘A’: Alta, ‘B’: Baja, ‘M’: Modificación).
Se pide desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado. //ordenado por legajo
“ALUMACTU.dat” con el mismo diseño.
*/
struct Alumno
{
    int legajo;
    char nombre[30];
    char domicilio[20];
    int cp;
    int telefono;
    int anioIngreso;
};

struct Actualizacion
{
    int legajo;
    char nombre[30];
    char domicilio[20];
    int cp;
    int telefono;
    int anioIngreso;
    char codOp; //A=alta, B=baja, M=modificación
};

int main()
{
    FILE *alumno = fopen("ALUMNOS.dat", "rb");
    FILE *actualizacion = fopen("NOVEDADES.dat", "rb");
    FILE *alumActu = fopen("ALUMACTU.dat", "wb");

    if (alumno != NULL && actualizacion != NULL && alumActu != NULL)
    {
        Alumno alu;
        Actualizacion act;

        // Leer el primer registro de cada archivo
        fread(&alu, sizeof(Alumno), 1, alumno);
        fread(&act, sizeof(Actualizacion), 1, actualizacion);

        // Procesar hasta que ambos archivos hayan sido completamente leídos
        while (!feof(alumno) || !feof(actualizacion))
        {
            if (!feof(alumno) && (feof(actualizacion) || alu.legajo < act.legajo))
            {
                // Escribir alumno del archivo ALUMNOS si no hay novedades o si el legajo es menor
                fwrite(&alu, sizeof(Alumno), 1, alumActu);
                fread(&alu, sizeof(Alumno), 1, alumno); // Leer el siguiente alumno
            }
            else if (!feof(actualizacion) && (feof(alumno) || alu.legajo >= act.legajo))
            {
                // Aplicar la actualización si el legajo es igual o menor
                switch (act.codOp)
                {
                case 'A':
                case 'M':
                {
                    // Crear un nuevo registro con los datos actualizados o agregados
                    Alumno aux;
                    aux.legajo = act.legajo;
                    strcpy(aux.nombre, act.nombre);
                    strcpy(aux.domicilio, act.domicilio);
                    aux.cp = act.cp;
                    aux.telefono = act.telefono;
                    aux.anioIngreso = act.anioIngreso;
                    fwrite(&aux, sizeof(Alumno), 1, alumActu);
                    break;
                }
                case 'B':
                    // No hacer nada, simplemente no se escribe en el nuevo archivo (se da de baja)
                    break;
                default:
                    break;
                }

                // Leer la siguiente actualización
                fread(&act, sizeof(Actualizacion), 1, actualizacion);

                // Si los legajos coinciden, avanzar también en el archivo de alumnos
                if (alu.legajo == act.legajo)
                {
                    fread(&alu, sizeof(Alumno), 1, alumno);
                }
            }
        }
    }
    else
    {
        cout << "Hubo un error al abrir un archivo" << endl;
    }

    // Cerrar los archivos
    fclose(alumno);
    fclose(actualizacion);
    fclose(alumActu);

    return 0;
}
