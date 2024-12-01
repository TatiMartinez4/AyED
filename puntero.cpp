#include <iostream>
using namespace std;

int main ()
{
    int a;
    int*p;
    a=6;
    p=&a;

    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;

    a=8;

    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;

    return 0;
}