//En una empresa automotriz existen 3 areas: ensambladora, pintura y electrica. El presupuesto se reparte: 37%, 42% y 21% respectivamente. Obtener la cantidad de dinero que recibira cada area.

#include <iostream>
using namespace std;

int main()
{
    int presupuesto, pensambladora, ppintura, pelectrica = 0;
    cout<<"ingrese un presupuesto"<<endl;
    cin>>presupuesto;

    pensambladora= (37*presupuesto)/100;
    ppintura= (42*presupuesto)/100;
    pelectrica= (21*presupuesto)/100;

    cout<<"el presupuesto para ensamblaje es "<<pensambladora << endl;
    cout<<"el presupuesto para pintura es "<<ppintura << endl;
    cout<<"el presupuesto para electrica es "<<pelectrica << endl;
    
    return 0;
}