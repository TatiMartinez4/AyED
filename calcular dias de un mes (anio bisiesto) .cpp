#include <iostream>
using namespace std;

int main()
{
   int mes, anio;
	cout<<"ingrese un mes en forma numerica"<<endl;
	cin>>mes;
	cout<<"ingrese un anio"<<endl;
	cin>>anio;
	if((mes<=7 && mes%2!=0) or (mes>7 && mes%2==0))
	{
	   cout<<"el mes tiene 31 dias";
	}
	else
	{
	   if(mes==2 or mes==02)
	   {
	      if((anio%4==0 && anio%100!=0) or anio%400==0)
	         {
	            cout<<"el mes tiene 29 dias";
	         }
	         else
	         {
	            cout<<"el mes tiene 28 dias";
	         }
	   }
	   else
	   {
	      cout<<"el mes tiene 30 dias";
	   }

	}

	return 0;
}
