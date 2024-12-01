#include <iostream>
using namespace std;

int main()
{
    int med1,med2,med3 = 0;
    cout<<"ingrese tres medidas"<<endl;
    cin>>med1,med2,med3;

    if(med1+med2>med3 && med2+med3>med1 && med1+med3>med2)
    {
        cout<<"Forman un triangulo"<<endl;
    }
    else
        cout<<"no forman un triangulo"<<endl;

    return 0;
}