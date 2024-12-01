//mejorar para que se muestre una sola vez todos los numeros de una

#include <iostream>
using namespace std;

int main()
{
    int i=0;
    while (i<10)
    {

        cout<<"ingrese un mes de forma numerica"<< endl;
        
        int a=0;

        cin>>a;

        if( a%2==0 )
        {
            cout << "el numero " << a << " es par" <<endl;
            i++;
        }

        else
        {
            i++;
        }

       
    }

    return 0;
}