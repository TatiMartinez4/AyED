#include <iostream>
using namespace std;
#include<cstring>
#include <cstdio>

// structs necesarios
struct Archivo
{
	char palabra[31]; //1 espacio para el /0
};

struct Resultado
{
	char palabra[31];
	int cant;
};

struct NodoLista 
{
    Resultado info;
    NodoLista*siguiente;
};

//funciones declaradas
int esMayuscula(int t);
int esMinuscula(int t);
int minMay(int t);
int mayMin(int t);
NodoLista*cargarSinRepetir(NodoLista* nuevaLista,Archivo aux2);
NodoLista*procesarArchivo (FILE*archivo);

NodoLista*procesarArchivo(FILE*archivo) //devuelve el puntero procesarArchivo que tiene formato de NodoLista
{
//tengo que abrir el archivo en donde tengo guardadas las cosas
FILE*h=fopen("informacion.dat","rb");

//tengo que crear una lista
	NodoLista*nuevaLista=NULL;

//tengo que declarar algo que almacene lo que voy a ir cargando a la lista:

	Resultado aux1; //no lo use para nada xd

//tengo que ir leyendo el archivo mientras haya datos
//Necesito un lugar donde ir guardando lo que lea del archivo

	Archivo aux2;

//leo el archivo por primera vez
	
	fread(&aux2,sizeof(Archivo),1,h);

//sigo leyendo hasta que se termine

    while(!feof(h))
    {
	    // y cargar la lista con las palabras ordenadas, sin repetirlas y con la cantidad de ocurrencias y modificando las minúsculas

        //primero verificamos si es minúscula para cargarlo bien
        if(esMinuscula(aux2[0])==1) //ósea si es minuscula
        {
            aux2[0]=minMay(aux2[0]);
        }

        //opciones: insertar sin repetir e ir contando cuando se repite.

        //cargamos nuestro primer elemento que sabemos que no se repite

        nuevaLista.palabra=aux2;
        nuevaLista.cant=0;

        //tenemos que seguir repitiendo y necesitamos que nos devuelva un puntero auxiliar

        NodoLista*auxiliar=NULL;

        auxiliar=insertarSinRepetir(nuevaLista, aux2);

        auxiliar->info.cant++;

        fread(&aux2,sizeof(Archivo),1,h ); //leo y guardo el dato en aux2

        }

    //cerrar el archivo
	fclose(h);

    return nuevaLista;
}

