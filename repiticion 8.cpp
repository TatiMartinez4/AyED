#include <iostream>
using namespace std;

//Dado un número entero positivo entre 1 y 3999 informar su correspondiente número Romano. NO ESTA TERMINADO PQ PAJA. Es hacer un case para toods y cada uno de los casos.

int main()
{
    //
    int num=0;
    cout<<"ingrese un numero del 1 al 3999"<<endl;
    cin>>num;
    string romano;
    int c= num/100%10

    switch(c)
    {
        case 0:
        case 1:
        case 2: 
        case 3:
        while(c!=0)
        {
            romano=romano + 'C';
            c--;
        }
        break;
        case 4:
        romano= romano+'CD';


    }

    while(num/1000 !=0)
    {
        romano=romano +'M';
        num= num-1000;
    }

    cout<<romano<<endl;

    return 0;
}
