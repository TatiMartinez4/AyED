/*
Se tiene el archivo “Medicamentos.dat” con un registro por cada medicamento existente en una farmacia. Cada registro tiene código, nombre, stock y precio unitario. 
Hacer un programa que informe los medicamentos con stock menor a 5 y el stock valorizado.
*/

#include <iostream>
using namespace std;
#include <cstdio>
#include<cstring>

struct Medicamento
{
    int codigo;
    char nombre[20];
    int stock;
    double precio;
};

int main()
{
    FILE* medicamento=fopen("Medicamentos.dat","rb");
    double stockValorizado=0.0;

    if(medicamento!=NULL)
    {
        Medicamento m;

        cout<<"medicmaentos con stock menor a 5:"<<endl;

        fread(&m,sizeof(Medicamento),1,medicamento);

        while(!feof(medicamento))
        {
            
            if(m.stock<5)
            {
                cout<<m.nombre<<endl;
            }

            stockValorizado+=double(m.stock)*m.precio;

            fread(&m,sizeof(Medicamento),1,medicamento);
        }
    }

    cout<<"el stock valorizado total es: "<< stockValorizado<<endl;
    
    else
    {
        cout<<"hubo un error al abrir el archivo Medicamentos.dat"<<endl;
    }
    
    fclose(medicamento);

    return 0;
}