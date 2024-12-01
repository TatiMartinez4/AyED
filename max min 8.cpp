/*
El gobierno de la Ciudad de Buenos Aires realiza una encuesta en casas de familia. De cada
familia encuestada se conoce: 

domicilio, tipo de vivienda (‘C’: casa, ‘D’: departamento) y
cantidad de integrantes.

De cada integrante de la familia se conoce: 
nombre y apellido, edad, sexo (‘F’, ‘M’), nivel de
estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario), y un indicador
(‘I’: Incompleto, ‘C’: Completo) referente al ítem anterior.


Se identifica el fin de ingreso de datos con un cero como cantidad de integrantes.


Informar:
a) La cantidad de encuestados que han completado los estudios primarios,
b) el porcentaje de analfabetismo en la ciudad (se consideran analfabetos a los mayores de
10 años que no poseen estudios)
c) el domicilio de la familia con mayor cantidad de integrantes que viven en un
departamento,
d) la edad promedio de todos los habitantes de la ciudad,
e) la mayor edad promedio de las familias,
f) la cantidad de encuestados con estudios secundarios incompletos,
g) el porcentaje de encuestados de sexo femenino con estudios terciarios completos.
*/

//se puede mejorar si la primer cant de integrantes se declara afuera del while y luego se vuelve a pedir justo antes de que termine el while
//tmb si es S no se le pregunta si es completo o incompleto

#include <iostream>
using namespace std;

int main()
{   
    //de cada familia
    int cant_d_integrantes=1;   
    char vivienda;
    string direc;

    //de cada integramte
    string nom;
    unsigned int edad=0;
    char sex;
    char estudio;
    char completo;

    int primarioscompletos=0;
    int mayores10sinestudios=0;

    int maxintegrantes=0;
    string domiciliomasintegrantes;

    int edadtotal=0;
    int cantidadtotaldepersonas=0;

    int edadtotfamilia=0;
    double edadpromfam=0;
    double edadpromfammayor=0;

    int secundariosincompletos=0;

    int cantmujeres=0;
    int mujeresterciariocompleto=0;

    cout<<"ingrese la cantidad de integrantes "<<endl;
    cin>>cant_d_integrantes;

    while(cant_d_integrantes != 0)
    {
        edadtotfamilia=0;

        cout<<"ingrese el tipo de vivienda C o D "<<endl;
        cin>>vivienda;

        cout<<"ingrese el domicilio "<<endl;
        cin>>direc;

        if(vivienda=='D' && cant_d_integrantes>maxintegrantes)
        {
            maxintegrantes=cant_d_integrantes;
            domiciliomasintegrantes= direc;
        }
        
        int aux=0;

        while(aux < cant_d_integrantes)
        {
            cout<<"Ingrese nombre"<<endl;
            cin>>nom;

            cout<<"ingrese edad"<<endl;
            cin>>edad;

            cout<<"Ingrese sexo F o M"<<endl;
            cin>>sex;

            cout<<"ingrese nivel de estudios"<<endl;
            cin>>estudio;

            if(estudio=='N')
            {

            }

            else
            {
                cout<<"ingrese C si lo completo e I si lo tiene incompleto"<<endl;
                cin>>completo;
            }

            if((estudio=='P' && completo=='C') || estudio=='S' || estudio=='U' || estudio=='T')
            {
                primarioscompletos++;
            }
            
            if(edad>10 && estudio=='N')
            {
                mayores10sinestudios++;
            }

            if(estudio=='S' && completo=='I')
            {
                secundariosincompletos++;
            }

            if(sex=='F')
            {
                cantmujeres++;
            }

            if(sex=='F' && estudio=='T' && completo=='C')
            {
                mujeresterciariocompleto++;
            }

            edadtotfamilia+=edad;

            aux++;
        }

        cantidadtotaldepersonas+=cant_d_integrantes;

        edadpromfam= double(edadtotfamilia)/cant_d_integrantes;

        if(edadpromfam>edadpromfammayor)
        {
            edadpromfammayor=double(edadpromfam);
        }

        edadtotal+=edadtotfamilia;
        cout<<"ingrese la cantidad de integrantes "<<endl;
        cin>>cant_d_integrantes;

    }

    cout<<"la cantidad de primarios completos es "<<primarioscompletos<<endl;
    cout<<"la cantidad de mayores de 10 sin estudios es "<<mayores10sinestudios<<endl;
    cout<<"el departamento con mas integrantes es "<<domiciliomasintegrantes<<endl;
    cout<<"la edad promedio es "<< double(edadtotal)/cantidadtotaldepersonas<<endl;
    cout<<"la mayor edad promedio es "<<edadpromfammayor<<endl;
    cout<<"cantidad de estudios secundarios incompletos "<<secundariosincompletos<<endl;
    cout<<"porcentaje de mujeres con estudios terciarios completos "<< (double(mujeresterciariocompleto)*100)/cantmujeres<<endl;

    return 0;

}