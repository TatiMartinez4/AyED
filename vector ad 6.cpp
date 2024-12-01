//6) Hacer una función que dado un vector de números enteros y un número, devuelva la posición en la que está.

#include <iostream>
using namespace std;

int posNumero (int vector[], int num, int pos);

int main()
{
    int vector[6]={2,1,8,5,4,6};
    cout<< posNumero(vector, 8, 6)<<endl;

    return 0;
}

int posNumero (int vector[], int num, int pos)
{
    int posNumero=0;
    for(int aux=0; aux<pos; aux++)
    {
        if(vector[aux]==num)
        {
            posNumero=aux;
        }
    }
    return posNumero;
}