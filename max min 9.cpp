/*
9) Un buque de carga traslada contenedores a tres diferentes puertos del país. Los puertos se
identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
- Identificación del contenedor
- Peso del contenedor en kg
- Puerto de arribo (un valor de 1 a 3).
El ingreso de datos finaliza con la identificación de un contenedor igual a cero.
Se pide calcular e informar:

a) El peso total que el buque debe trasladar.
b) La identificación del contenedor de mayor peso.
c) La cantidad de contenedores que debe trasladar a cada puerto
*/

#include <iostream>
using namespace std;

int main()
{
    int puerto=0; //3 puertos 1,2,3
    int identificacion=1;  //=0 se dejan de ingresar
    int peso=0;

    int pesototal=0;
    int mayorpeso=0;
    int idenmayorpeso=0;
    int puerto1=0;
    int puerto2=0;
    int puerto3=0;

    cout<<"ingrese el numero identificador"<<endl;
    cin>>identificacion;

    while(identificacion!=0)
    {

        cout<<"ingrese el peso"<<endl;
        cin>>peso;

        if(peso>mayorpeso)
        {
            idenmayorpeso=identificacion;
            mayorpeso=peso;
        }

        pesototal+=peso;

        cout<<"ingrese el codigo del puerto de llegada"<<endl;
        cin>>puerto;

        switch(puerto)
        {
            case 1:
            puerto1++;
            break;

            case 2:
            puerto2++;
            break;

            case 3:
            puerto3++;
            break;
        }
        cout<<"ingrese el numero identificador"<<endl;
        cin>>identificacion;
    }

    cout<<"el peso total que el buque debe trasladar es "<< pesototal << endl;
    cout<<"La identificacion del contenedor de mayor peso es "<< idenmayorpeso <<endl;
    cout<<"la cantidad de contenedores que debe trasladar a" <<endl<< "puerto 1: "<< puerto1<< endl << "puerto 2: "<<puerto2<< endl<<"puerto 3: "<<puerto3 <<endl;

    return 0;
}