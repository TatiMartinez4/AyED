/*
7) Un jugador arroja 5 dados y se registra como puntaje la suma de los dos valores más altos. Dada
una serie de tiros, que finaliza al ingresar ‘N’ ante la consulta “Continúa? S/N”, determinar e
imprimir la cantidad de tiros, el máximo puntaje obtenido, y el puntaje promedio.
*/

#include <iostream>
using namespace std;

int main()
{
    //g
    char sn='S';
    int aux=0;
    int aux2=0;
    int valor=0;
    int suma=0;
    int maximo=0;

    while( sn != 'N' )
    {
        int valormax=0;
        int valormax2=0;
        
        while(aux2<5)
        {
            cout<<"ingrese el valor"<<endl;
            cin>>valor;

            if(valor>valormax)
            {
                valormax2=valormax;
                valormax=valor;
            }
            else
            {
                if(valor>valormax2)
                {
                    valormax2=valor;
                }
                else
                {

                }
            }
            
            if((valormax + valormax2)>maximo)
            {
                maximo=valormax+valormax2;
            }

            aux2++; 
        }
     
        suma+=valormax+valormax2; //suma los dos valores mas altos de los 5 dados en la x cantidad de tiros
        
        aux2=0;
        aux++; //cuenta los tiros

        cout<<"ingresar S si desea continuar o N si desea detenere"<<endl;
        cin>>sn;  

       
    }

    cout<<"suma "<<suma<<endl;
    cout<<"aux"<<aux<<endl;
    cout<<"la cantidad de tiros es "<<aux<<endl;
    cout<<"el puntaje promedio es "<< double(suma)/aux <<endl;
    cout<<"el puntaje mas alto obtenido es "<<maximo<<endl;

    return 0;
}