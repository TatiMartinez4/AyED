#include <iostream>
using namespace std;
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring> //Para todo lo de cadenas, strc

/*
El dueño de un local de venta de juegos para distintas consolas necesita desarrollar un algoritmo que grabe un archivo, JuegosPorConsola.dat, ordenado por consola, con un solo registro 
por consola según el siguiente diseño:
a) Consola (10 caracteres) 
b) Cantidad de juegos

Para obtener la información solicitada se cuenta con el archivo Juegos.dat, ordenado por consola, con un registro por cada juego que se encuentra en el local, con el siguiente diseño:
1) Código del juego
2) Titulo del Juego (30 caracteres)
3) Stock en el local
4) Consola (10 caracteres) //ORDENADO POR CONSOLA
*/
struct JuegosC
{
    char consola[10];
    int cant;
};

struct Juego
{
    int cod;
    char nombre[30];
    int stock;
    char consola[10];
};

//ojo con el tratamiento de cadenas!!!

int main()
{
    FILE*juegos=fopen("Juegos.dat","rb");
    FILE*juegosPorConsola=fopen("JuegosPorConsola.dat","wb");

    if(juegos!=NULL && juegosPorConsola!=NULL)
    {
        Juego j;
        fread(&j,sizeof(Juego),1,juegos);
        JuegosC aux;
        aux.cant=1;
        strcpy(aux.consola,j.consola);
        fread(&j,sizeof(Juego),1,juegos);

        while(!feof(juegos))
        {
            if(strcmpi(j.consola,aux.consola)==0)//son iguales
            {
                aux.cant++;
            }
            else
            {
                fwrite(&aux,sizeof(JuegosC),1,juegosPorConsola);
                aux.cant=1;
                strcpy(aux.consola,j.consola);
            }
            fread(&j,sizeof(Juego),1,juegos);
        }
        fwrite(&aux,sizeof(JuegosC),1,juegosPorConsola);
    }
    else
    {
        cout<<"hubo un problema con alguno de los archivos"<<endl;
    }

   fclose(juegos);
   fclose(juegosPorConsola);

   return 0;
}