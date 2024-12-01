#include <iostream>
using namespace std;

// codigo A--200 D--400 F--600 M--1500 T--1500
// ticket con el numdeh codigo e importe a pagar

int main ()
{
    int numdeh, importe =0;
    char codigo;
    cout<<"ingrese el numero de historial del paciente"<<endl;
    cin>>numdeh;
    cout<<"ingrese el codigo de la prestacion"<<endl;
    cin>>codigo;

    switch(codigo)
    {
        case 'A':
        importe=200;
        break;

        case 'D':
        importe=400;
        break;

        case 'F':
        importe=600;
        break;

        case 'M':
        case 'T':
        importe=1500;
        break;
    }

    cout<<"ticket"<<endl<<"numero de historial: "<< numdeh <<endl<< "codigo de la prestacion: "<< codigo << endl << "importe: " << importe << endl;

    return 0;

}