//hacer un algoritmo

#include <iostream>
using namespace std;

int main()
{
    int codigo, cantidad =0;
    float descuento, precio, total =0;
    cout<<"ingrese el codigo y la cantidad a comprar"<<endl;
    cin>>codigo>>cantidad;

    switch(codigo)
    {
        case 1:
        case 10:
        case 100:
            precio=10;
            break;
            
        case 2:
        case 22:
        case 222:
            precio=7;
            break;

        case 3:
        case 33:
            precio=3;
            break;
        case 4:
        case 44:
            precio=2;
            break;
    }

    if(precio==7 && cantidad>10)
    {
        //hay que ver cuantas veces entra 10 en la cantidad
        int i=0;
        int aux=cantidad;
        while(aux/10 !=0)
        {
            aux=aux-10;
            i++;
        }

        total = i*65 + (cantidad%10) * precio;
    }
    
    else
    {
         if(precio==3 && cantidad>10)
        {
            total=precio*cantidad;
            descuento= total/10;
            total= total - descuento;
        }
        else
        {
            total=precio*cantidad;
        }
    }

    cout<<"el precio total a pagar es "<< total <<endl;
   
    return 0;
}