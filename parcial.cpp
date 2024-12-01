#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>

//1
struct Cursos
{
    int codCurso;
    int cantVacantes;
    int cantInscriptos;
};

struct InscripcionJulio
{
    int dia;
    int codCurso;
    int dni;
    char alumno [30];
};

struct InscriptosJulio
{
    int dni;
    int codCurso;
    char alumno [30];
};

//2 void cargarCursos(Cursos c[], int cantCursos)

//3

void procesarInscripciones(Cursos c[], int cantCursos, int inscriptosPorDia[31], int inscriptosPorCurso[31][14])
{
     FILE*Inscripciones=fopen("inscripcionesJulio.dat","rb");

    if(Inscripciones==NULL)
    {
        cout<<"hubo un error al abrir el archivo de las inscripciones de Julio"<<endl;
    }
    else
    {
        FILE*Inscriptos=fopen("InscriptosJulio.dat","wb");
        if(Inscriptos==NULL)
        {
            cout<<"hubo un error al crear el archivo de inscriptos de Julio"<<endl;
        }
        else
        {
            InscripcionJulio I1; 
            InscriptosJulio I2;  

            while(fread(&I1,sizeof(InscripcionJulio),1,Inscripciones))
            {
                for(int i=0; i<cantCursos ;i++)
                {
                    if(c[i].codCurso== I1.codCurso && c[i].cantInscriptos<c[i].cantVacantes)
                    {
                        strcpy(I2.alumno, I1.alumno);
                        I2.codCurso=I1.codCurso;
                        I2.dni=I1.dni;

                        fwrite(&I2,sizeof(InscriptosJulio),1,Inscriptos);

                        inscriptosPorDia[I1.dia-1]++;
                        inscriptosPorCurso[I1.dia-1][i]++;
                        c[i].cantInscriptos++;
                    }
                }
            }

            fclose(Inscripciones);
            fclose(Inscriptos);
        }
    }
}

//4

void inscXCusoXDia(Cursos c[], int inscriptosPorCurso[][14])
{
    for(int i=0; i<14; i++)
    {
        cout << "codigo de curso: " << c[i].codCurso<< endl;

        for(int j=0; j<31; j++)
        {
            cout<<"dia "<<j+1<<": "<<inscriptosPorCurso[j][i]<<"inscripciones"<<endl;
        }
    }
}

int diaConMasInsc(Cursos c[],int inscriptosPorDia[])
{
    int mayor=inscriptosPorDia[0];
    int diaMayor=1;
    for(int i=1;i<31;i++)
    {
        if(inscriptosPorDia[i]>mayor)
        {
            mayor=inscriptosPorDia[i];
            diaMayor=i+1;
        }
    }

    return diaMayor;
}

int cursosVacios(int inscriptosPorCurso[][14])
{
    int contador=0;

    for(int j=0; j<14;j++)
    {
        int aux=0;

        for(int i=0;i<31;i++)
        {
            aux=aux + inscriptosPorCurso[i][j];
        }
        if(aux==0)
        {
            contador++;
        }
    }

    return contador;
}

void mostrarEstadistica(Cursos c[], int inscriptosPorDia[], int inscriptosPorCurso[][14])
{
    inscXCusoXDia(c,inscriptosPorCurso);

    int diaMayor=diaConMasInsc(c,inscriptosPorDia);

    cout<<"el dia con mayor cantidad de inscriptos es "<< diaMayor << endl;

    int contador=cursosVacios(inscriptosPorCurso);

    cout<<"hay "<<contador<< " cursos sin inscriptos"<<endl;
}

