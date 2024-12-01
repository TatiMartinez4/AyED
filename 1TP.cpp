/*Se requiere una aplicación para realizar registro y estadísticas sobre el último Hot Sale en el que
participan, como máximo, 500 empresas adheridas.

Por cada empresa participante se ingresa:
-Código de empresa
-Nombre

El ingreso de datos finaliza como el equipo decida.

También se ingresan datos correspondientes a las ventas realizadas durante los 3 días del Hot Sale.
Por cada venta se ingresa:

-Día de la venta (1, 2 o 3)  (sabemos que son 3) (un contador por cada dia?)
-Código de empresa  (sabemos que son 500)
-Importe de la venta   ¡¡nos importa el importe total, no el de cada venta!!
¡¡necesitamos un contador para tener la cantidad de ventas!!

El ingreso de datos finaliza como el equipo decida.
Realizar un programa para:
1) Informar por cada día de la promoción cantidad de ventas e importe total recaudado por
cada empresa adherida.
2) Informar por cada empresa adherida, si corresponde, los días en que no realizaron ventas.
3) Informar la o las empresas que recaudaron el menor importe total, informando también
dicho importe.
4) Informar cuál de los tres días hubo más ventas.
5) Generar el archivo “ImporteEmpresas.dat”, con un registro por cada empresa adherida,
ordenado por código de empresa. Cada registro deberá tener código y nombre de la empresa
y el importe total recaudado por sus ventas y la cantidad de ellas. El archivo debe estar
ordenado por código de empresa.
6) Generar el archivo “SinAdhesion.dat”, con las ventas ingresadas de empresas que no
estuvieron adheridos a la promoción.*/

//CANTIDAD DE VENTAS POR DIA (un contador por dia serian 3 contadores)
//IMPORTE TOTAL POR DIA POR EMPRESA (seria un contador por cada empresa que son 500 por cada dia que son 3?) !!
//DIAS EN QUE CADA EMPRESA NO REALIZO VENTA (sale del ejercicio anterior)
//EMPRESAS QUE MENOS RECAUDARON----(INFORMANDO EL IMPORTE) 
//CUAL DE LOS 3 DIAS TUVO MAS VENTAS 
//GENERAR ARCHIVO QUE REGISTRE LAS EMPRESAS CON NOMBRE, CODIGO, IMPORTE TOTAL RECAUDADO, CANT DE VENTAS DE LA EMPRESA
//GENERAR ARCHIVO QUE INDIQUE LAS EMPRESAS QUE TUVIERON VENTAS Y QUE NO ESTABAN ADHERIDAS. (osea no estan en el primer "struct" pero si en el segundo)

#include <iostream>
using namespace std;

struct Empresas 
{
    int codEmpresa;
    char nomEmpresa[20];
};

int ingresoDatosE(Empresas e[], int t);
void ingresoDatosV(int m [][3], int e[], int t);
void inicializarMatriz(int m[][3], int nc, int nf);
int buscar(int e[],int t,int bus);

int main()
{
    Empresas e[500]; //me sirve de algo tenerlo ordenado por codigo de empresa?
    int cantEmpresas= ingresoDatosE(e,500);
    //por cada empresa

    int impPorDiaPorEmpresa [cantEmpresas][3]; //esta matriz tiene los dias y la cantidad de ventas pero no estaria guardando el codigo de las empresas no?, tengo que hacer un array paralelo

    inicializarMatriz(impPorDiaPorEmpresa,cantEmpresas,3);

    int empre[cantEmpresas];

    ingresoDatosV(impPorDiaPorEmpresa, empre, cantEmpresas);

    //aca habria que cargar la matriz y el array empre con los codigos de la empresas y que trabajen en paralelo.



    return 0;
}

void inicializarMatriz(int m[][3], int nc, int nf)
{
    for(int i=0; i<nc;i++)
    {
        for(int j=0;j<nf;j++)
        {
            m[i][j]=0;
        }
    }
}

int buscar(int e[],int t,int bus)
{
    int pos=-1, desde=0, hasta=t, medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(e[medio]==bus)
        {
            pos=medio;
        }
        else
        {
            if(bus<e[medio])
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

int ingresoDatosE(Empresas e[], int t)
{
    //el ingreso de empresas termina cuando el codigo de empresa ingresado es cero.
    int i=0,codigoEm;

    cout<<"ingrese el codigo de la empresa"<<endl;
    cin>>codigoEm;

    e[i].codEmpresa=codigoEm;

    while(codigoEm!=0 && i<t)
    {   
        cout<<"ingrese el nombre de la empresa"<<endl;
        cin>>e[i].nomEmpresa;

        i++;

        cout<<"ingrese el codigo de la empresa"<<endl;
        cin>>codigoEm;
        
        e[i].codEmpresa=codigoEm;
    }
    return i;
}


void ingresoDatosV(int m [][3], int e[], int t)
{
    //finaliza con dia =0
    int i=0,dia;
    cout<<"Ingrese dia de la venta "<<endl;
    cin>>dia;
    if(dia>3 || dia<0)
    {
        cout<<"el dia ingresado es erroneo"<<endl;
    }
    else
    {
        while(dia!=0)
        {
            cout<<"ingrese el codigo de la empresa que realizo la venta"<<endl;
            int bus;
            cin>>bus;
            if(buscar(e,t,bus)!=-1)
            {
                e[i]=bus;
            }

            cout<<"ingrese el importe de la venta "<<endl;
            int importe=0;
            cin>>importe;

            m[i][dia-1]+=importe;

            i++;

            cout<<"Ingrese dia de la venta "<<endl;
            cin>>dia;
            
            if(dia>3 && dia<0)
            {
                cout<<"el dia ingresado es erroneo"<<endl;
            }
        }
    }

}

