// Determinar la suma de las cifras de un numero entero positivo de 4 cifras.

#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese un numero de 4 cifras"<<endl;
    int num=0;
    cin>>num;

    int unidad, decena, centena, mil =0;

    unidad= num%10;
    decena= (num/10) %10;
    centena= (num/100)%10;
    mil= num/1000;

    int suma=unidad+decena+centena+mil;

    cout<<suma<<endl;

    return 0;

}