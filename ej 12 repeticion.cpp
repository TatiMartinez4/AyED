#include <iostream>
using namespace std;

int main()
{
    cout<<"ingrese un numero"<<endl;
    int num=0;
    cin>>num;
    int fact=1;

        while(num!=0)
        {
            fact= fact * num;
            num--;
        }
        cout<<"el factorial del numero es " << fact<<endl;
   
    return 0;
}