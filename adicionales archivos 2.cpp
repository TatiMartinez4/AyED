/*
Se tiene el archivo “Escuelas.dat” con un registro con las escuelas de gestión estatal de un municipio de la provincia. Cada registro tiene número de escuela, 
dirección y cantidad total de alumnos. El archivo está ordenado por número de escuela. Hacer un programa que informe los datos de las escuelas que están entre 
dos números de escuela ingresados por teclado. Informar también la cantidad de total de alumnos de las escuelas informadas.
*/
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>

struct Escuela
{
    int numEsc; //ordenado
    char direccion [30];
    int cantidadAlumnos;
};

int binaria(FILE*escuelas,int t, int bus);

int main()
{
    FILE*escuelas=fopen("Escuelas.dat","rb");
    fseek(escuelas,0,SEEK_END);
    int t= ftell(escuelas)/sizeof(Escuela);
    
    int bus=0;
    cout<<"ingrese el numero de escuela"<<endl;
    cin>>bus;

    int pos= binaria(escuelas,t,bus);

    
    cout<<"ingrese el numero de escuela"<<endl;
    cin>>bus;
    int final= binaria(escuelas,t,bus);

    Escuela e;
    int totalAlumnos;

    while(pos<=final)
    {
        fseek(escuelas,pos*sizeof(Escuela),SEEK_SET);
        fread(&e,sizeof(Escuela),1,escuelas);
        cout<<"Numero de escuela; "<<e.numEsc<<"---cantidad de alumnos: "<<e.cantidadAlumnos<<"----Direccion: "<<e.direccion<<endl;
        pos++;
    }

    fclose(escuelas);

    return 0;

}

int binaria(FILE*escuelas,int t, int bus)
{
    int pos=-1, desde=0, hasta=t-1,medio;
    Escuela e;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        fseek(escuelas,medio*sizeof(Escuela),SEEK_SET);
        fread(&e,sizeof(Escuela),1,escuelas);
        if(e.numEsc==bus)
        {
            pos=medio;
        }
        else
        {
            if(bus<e.numEsc)
            {
                hasta=medio-1;
            }
            else
            {
                desde=medio+1;
            }
        }

    }
    return pos;
}