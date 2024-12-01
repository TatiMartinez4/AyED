#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Empresa 
{
    int codEmpresa;
    char nomEmpresa[20];
};

struct Venta 
{
    int dia;
    int codEmpresa;
    float importe;
};

int ingresoDatosE(Empresa e[], int t);
void ingresoDatosV(Venta v[], int &cantidadVentas, int maxVentas);
void inicializarMatriz(float m[][3], int nf, int nc);
void inicializarVector(int v[], int t);
int buscar(Empresa e[], int t, int bus);
void generarReportes(Empresa e[], int cantEmpresas, Venta v[], int cantVentas, float importeTotal[][3], int cantidadVentasPorDia[]);
void reporteVentasPorDia(Empresa e[], int cantEmpresas, float importeTotal[][3]);
void reporteEmpresasSinVentasPorDia(Empresa e[], int cantEmpresas, float importeTotal[][3]);
void reporteEmpresaConMenorImporte(Empresa e[], int cantEmpresas, float importeTotal[][3]);
void reporteDiaConMasVentas(int cantidadVentasPorDia[]);
void escribirArchivoEmpresas(Empresa e[], int cantEmpresas, float importeTotal[][3], int cantidadVentasPorEmpresa[]);
void escribirArchivoSinAdhesion(Venta v[], int cantVentas, Empresa e[], int cantEmpresas);

int main() {
    Empresa e[500]; //aca guardo nombre de las empresas y codigos
    int cantEmpresas = ingresoDatosE(e, 500);

    float importeTotal[500][3]; //aca guardo los importes totales de las ventas por dia por empresa.
    inicializarMatriz(importeTotal, 500, 3);

    int cantidadVentasPorEmpresa[500]; //cantidad de ventas por empresa. Tengo que incializar el vector todo en 0.
    inicializarVector(cantidadVentasPorEmpresa,500);
    int cantidadVentasPorDia[3];//cantidad de ventas por dia. Tengp que incializar el vector todo en 0.
    inicializarVector(cantidadVentasPorDia,3);

    Venta ventas[1000];
    int cantVentas = 0;

    ingresoDatosV(ventas, cantVentas, 1000); //deberia dejar de ser void no? Asi es int y tengo cuantos ingrese posta. el numero 1000 es uno por tirar. Sabesmos que podria haber 500 o mas de hecho.

    //puntos del 1 al 4
    generarReportes(e, cantEmpresas, ventas, cantVentas, importeTotal, cantidadVentasPorDia);

    //punto 5
    escribirArchivoEmpresas(e, cantEmpresas, importeTotal, cantidadVentasPorEmpresa);
    //punto 6
    escribirArchivoSinAdhesion(ventas, cantVentas, e, cantEmpresas);

    return 0;
}

void inicializarMatriz(float m[][3], int nf, int nc) 
{
    for (int i = 0; i < nf; i++) 
    {
        for (int j = 0; j < nc; j++) 
        {
            m[i][j] = 0;
        }
    }
}

void inicializarVector(int v[], int t)
{
    for(int i=0; i<t; i++)
    {
        v[i]=0;
    }
}

int buscar(Empresa e[], int t, int bus) 
{
    for (int i = 0; i < t; i++) 
    {
        if (e[i].codEmpresa == bus) 
        {
            return i;
        }
    }
    return -1;
}

int ingresoDatosE(Empresa e[], int t) 
{
    int i = 0, codigoEm;
    cout << "Ingrese el codigo de la empresa (0 para terminar): ";
    cin >> codigoEm;

    while (codigoEm != 0 && i < t) 
    {
        e[i].codEmpresa = codigoEm;
        cout << "Ingrese el nombre de la empresa: ";
        cin >> e[i].nomEmpresa;
        i++;
        cout << "Ingrese el codigo de la empresa (0 para terminar): ";
        cin >> codigoEm;
    }
    return i;
}

void ingresoDatosV(Venta v[], int &cantidadVentas, int maxVentas) 
{
    int dia;
    cout << "Ingrese dia de la venta (1, 2, 3) (0 para terminar): ";
    cin >> dia;

    while (dia != 0 && cantidadVentas < maxVentas) 
    {
        if (dia >= 1 && dia <= 3) 
        {
            cout << "Ingrese el codigo de la empresa que realizo la venta: "<<endl;
            cin >> v[cantidadVentas].codEmpresa;
            cout << "Ingrese el importe de la venta: "<<endl;
            cin >> v[cantidadVentas].importe;
            v[cantidadVentas].dia = dia;
            cantidadVentas++;
        } 
        else 
        {
            cout << "Dia ingresado es incorrecto" << endl;
        }
        cout << "Ingrese dia de la venta (1, 2, 3) (0 para terminar): "<<endl;
        cin >> dia;
    }
}

void generarReportes(Empresa e[], int cantEmpresas, Venta v[], int cantVentas, float importeTotal[][3], int cantidadVentasPorDia[]) 
{
    for (int i = 0; i < cantVentas; i++) 
    {
        int pos = buscar(e, cantEmpresas, v[i].codEmpresa);
        if (pos != -1) 
        {
            importeTotal[pos][v[i].dia - 1] += v[i].importe;
            cantidadVentasPorDia[v[i].dia - 1]++;
        }
    }

    reporteVentasPorDia(e, cantEmpresas, importeTotal);
    reporteEmpresasSinVentasPorDia(e, cantEmpresas, importeTotal);
    reporteEmpresaConMenorImporte(e, cantEmpresas, importeTotal);
    reporteDiaConMasVentas(cantidadVentasPorDia);
}

void reporteVentasPorDia(Empresa e[], int cantEmpresas, float importeTotal[][3]) 
{
    for (int dia = 0; dia < 3; dia++) 
    {
        cout << "Dia " << dia + 1 << ":" << endl;
        for (int i = 0; i < cantEmpresas; i++) 
        {
            cout << "Empresa " << e[i].nomEmpresa << ": Ventas = " << importeTotal[i][dia] << endl;
        }
    }
}

void reporteEmpresasSinVentasPorDia(Empresa e[], int cantEmpresas, float importeTotal[][3]) 
{
    for (int i = 0; i < cantEmpresas; i++) 
    {
        cout << "Empresa " << e[i].nomEmpresa << " no realizo ventas en: ";
        bool noVentas = true;
        for (int dia = 0; dia < 3; dia++) 
        {
            if (importeTotal[i][dia] == 0) 
            {
                cout << "Dia " << dia + 1 << " "<<endl;
                noVentas = false;
            }
        }
        if (noVentas) 
        {
            cout << "ningun dia"<<endl;;
        }
    }
}

void reporteEmpresaConMenorImporte(Empresa e[], int cantEmpresas, float importeTotal[][3]) 
{
    float menorImporte = importeTotal[0][0] + importeTotal[0][1] + importeTotal[0][2];
    for (int i = 1; i < cantEmpresas; i++) 
    {
        float totalEmpresa = importeTotal[i][0] + importeTotal[i][1] + importeTotal[i][2];
        if (totalEmpresa < menorImporte) 
        {
            menorImporte = totalEmpresa;
        }
    }

    cout << "Empresa con menor importe total recaudado:" << endl;

    for (int i = 0; i < cantEmpresas; i++) 
    {
        float totalEmpresa = importeTotal[i][0] + importeTotal[i][1] + importeTotal[i][2];
        if (totalEmpresa == menorImporte) 
        {
            cout << "Empresa " << e[i].nomEmpresa << " con importe " << menorImporte << endl;
        }
    }
}

void reporteDiaConMasVentas(int cantidadVentasPorDia[]) 
{
    int diaMasVentas = 0;
    for (int dia = 1; dia < 3; dia++) 
    {
        if (cantidadVentasPorDia[dia] > cantidadVentasPorDia[diaMasVentas]) 
        {
            diaMasVentas = dia;
        }
    }
    cout << "El dia con mas ventas fue el Dia " << diaMasVentas + 1 << " con " << cantidadVentasPorDia[diaMasVentas] << " ventas" << endl;
}

void escribirArchivoEmpresas(Empresa e[], int cantEmpresas, float importeTotal[][3], int cantidadVentasPorEmpresa[]) 
{
    ofstream archivo("ImporteEmpresas.dat", ios::binary);
    for (int i = 0; i < cantEmpresas; i++) 
    {
        float totalImporte = importeTotal[i][0] + importeTotal[i][1] + importeTotal[i][2];
        archivo.write((char*)&e[i].codEmpresa, sizeof(e[i].codEmpresa));
        archivo.write(e[i].nomEmpresa, sizeof(e[i].nomEmpresa));
        archivo.write((char*)&totalImporte, sizeof(totalImporte));
        archivo.write((char*)&cantidadVentasPorEmpresa[i], sizeof(cantidadVentasPorEmpresa[i]));
    }
    archivo.close();
}

void escribirArchivoSinAdhesion(Venta v[], int cantVentas, Empresa e[], int cantEmpresas) 
{
    ofstream archivo("SinAdhesion.dat", ios::binary);
    for (int i = 0; i < cantVentas; i++) {
        if (buscar(e, cantEmpresas, v[i].codEmpresa) == -1) {
            archivo.write((char*)&v[i], sizeof(v[i]));
        }
    }
    archivo.close();
}
