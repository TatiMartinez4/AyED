//falta terminar el punto 12 de funciones

#include <iostream>
using namespace std;

int mcdEntreDos (int e1, int e2);
unsigned long long factorial(int num);
bool multiplo (int num1, int num2);
unsigned long long combinatorio (int num1, int num2);
double porcentaje(int num1, int num2);
unsigned edadGrupoEtario(unsigned edad);
int juntarfecha (int dia, int mes, int anio);
void separarfecha (int fecha, int& dia, int& mes, int& anio);
int sumadehoras(int hora1, int hora2);
void menudeopciones( int &num1, int &num2);
void repeticion (string texto, int  cantdeveces);
int producto ( int num1, int num2);
int elevado (int num1,int num2);
unsigned int fibonacci (int n);
unsigned long long combinatoriorecursivo (int num1, int num2);
int mcd (int num1, int num2);
void especular(int num);

/* ejercicio de funciones numero 4: Dada una serie de números enteros positivos que finalizan con cero, informar:
a) su factorial
b) cuantos múltiplos de 3
c) cuantos múltiplos de 5
d) cuantos múltiplos de 3 y de 5
Utilice las funciones de ejercicios anteriores. 

int main()
{
    unsigned nro=0;
    unsigned mult3=0;
    unsigned mult5=0;
    unsigned mult3y5=0;

    cout<<"ingrese un numero"<<endl;
    cin>>nro;

    while(nro!=0)
    {
        cout<<"el factorial de "<< nro <<" es "<< factorial (nro) <<endl;

        if(multiplo(nro,3))
        {
            mult3++;
        }

        if(multiplo(nro,5))
        {
            mult5++;
        }

        if(multiplo(nro,15))
        {
            mult3y5++;
        }

        cout<<"ingrese otro numero"<<endl;
        cin>>nro;
    }

    cout<<"la cantidad de multiplos de 3 es "<<mult3<<endl;
    cout<<"la cantidad de multiplos de 5 es "<<mult5<<endl;
    cout<<"la cantidad de multiplos de 3 y 5 es "<<mult3y5<<endl;

    return 0;
    
}
*/


/* funciones 1) Desarrollar una función que calcule el máximo común divisor de dos números enteros A, B
con el siguiente algoritmo:
1. Dividir A por B, y calcular el resto (0 < R < B)
2. Si R = 0, el MCD es B, si no seguir en 3.
3. Reemplazar A por B, B por R, y volver al paso 1.*/

int mcdEntreDos (int e1, int e2)
{
    int resto=0;
    int mcd=0;

    while(mcd==0)
    {
        if(e1%e2==0)
        {
            mcd=e2;
        }
        else
        {
            while(e1%e2!=0)
            {   
                resto=e1%e2;
                e1=e2;
                e2=resto; //esto esta mal pq perdi antes el valor de e2!!!

                if(e1%e2==0)
                {
                    mcd=e2;
                }
            }
        }
    }

    return mcd;
}

/* 2)  funciones Desarrollar una función tal que dado un número entero positivo calcule y retorne su factorial. */

unsigned long long factorial(int num)
{
    unsigned long long fact=1;

        while(num!=0)
        {
            fact*=num;
            num--;
        }
   
    return fact;
}

/* 3)  funciones Desarrollar una función que dados dos números, retorne verdadero si el primero es múltiplo del segundo, falso en caso contrario.*/

bool multiplo (int num1, int num2)
{
    if(num1%num2==0)
    {
        return true;
    }
    else
    {
        return false;
    }

    //return n1%n2==0;
}


//5) funciones  Desarrollar una función que dados n y m devuelva el combinatorio de m tomados de a n. Usar función punto 2 m!/n!(m-n)!

unsigned long long combinatorio (int num1, int num2)
{
    int combina=0;
    combina=factorial(num1)/ (factorial(num2) * factorial(num1-num2));
    return combina;
}

//6) funciones  Desarrollar la función porcentaje que dados los parámetros a y b devuelva el porcentaje que representa a sobre b. 

double porcentaje(int num1, int num2)
{
    return (num1*100)/num2;
}

// 7) funciones  Desarrollar la función unsigned edadAGrupoEtario (unsigned edad) que retorne un valor de 1 a 8, de acuerdo al siguiente cuadro: 

unsigned edadGrupoEtario(unsigned edad)
{
    if(edad<=14)
    {
        return 1;
    }
    else
    {
        if(15<=edad && edad<=21)
        {
            return 2;
        }
        else
        {
            if(22<=edad && edad<=28)
            {
                return 3;
            }
            else
            {
                if(29<=edad && edad<=35)
                {
                    return 4;
                }
                else
                {
                    if(36<=edad && edad<=42)
                    {
                        return 5;
                    }
                    else
                    {
                        if(43<=edad && edad<=49)
                        {
                            return 6;
                        }
                        else
                        {
                            if(50<=edad && edad<=63)
                            {
                                return 7;
                            }
                            else
                            {
                                return 8;
                            }
                        }
                    }
                }
            }
        }
    }

}

//8)  funciones Desarrollar una función que dados el día, el mes y el año de una fecha correcta, devuelva la misma en formato de entero de 8 dígitos con el formato AAAAMMDD.
int juntarfecha (int dia, int mes, int anio)
{
    return anio*10000 + mes*100 + dia;
}

//9)  funciones Desarrollar una función tal que dada una fecha en formato número de 8 dígitos (AAAAMMDD), devuelva el día, el mes y el año correspondientes.
void separarfecha (int fecha, int& dia, int& mes, int& anio)
{
    dia= fecha%100;
    mes= fecha/100%100;
    anio= fecha/10000;
}

//10) funciones Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo también en formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora inicial,
//considere también si cambió el día.

int sumadehoras(int hora1, int hora2)
{
    int segh1=hora1%100;
    int segh2=hora2%100;

    int segundos=segh1+segh2;

    int minh1=hora1/100%100;
    int minh2=hora2/100%100;

    int minutos=minh1+minh2;
    
    int h1=hora1/10000;
    int h2=hora2/10000;

    int hora=h1+h2;

    if(segundos>=60)
    {
        minutos++;
        segundos=segundos%60;
    }
   
    if(minutos>=60)
    {
        hora++;
        minutos=minutos%60;
    }
    
    while(hora>=24)
    {
        hora=hora - 24;
    }

    cout<<hora<<endl;
    cout<<minutos<<endl;
    cout<<segundos<<endl;
    int nuevahora= hora*10000+minutos*100+segundos;

    return nuevahora;   

}

/*11) funciones Hacer un programa dados dos número enteros muestre el siguiente menú de opciones:
1. Muestre la suma de los números.
2. Muestre la resta del menor de los números al mayor.
3. Muestre que porcentaje representa el menor de los números sobre el mayor.
4. Muestre el máximo común divisor de ambos números.
5. Muestre el número combinatorio del mayor de los números sobre el menor.
6. Cambiar los números.
Usar las funciones realizadas en los ejercicios anteriores
*/

void menudeopciones(int& num1, int& num2 )
{
    int eleccion=0;
    cout<<"Elija, escribiendo el numero de la operacion que desea realizar:"<<endl<<"1. Muestre la suma de los números."<<endl<<"2. Muestre la resta del menor de los números al mayor."<<endl;
    cout<<"3. Muestre que porcentaje representa el menor de los números sobre el mayor."<<endl<<"4. Muestre el máximo común divisor de ambos números."<<endl;
    cout<<"5. Muestre el número combinatorio del mayor de los números sobre el menor."<<endl<<"6. Cambiar los números."<<endl;
    cin>>eleccion;

    switch(eleccion)
    {
        case 1:
            cout<<"la suema de los numeros es "<< num1+num2<<endl;;
            break;

        case 2:
            if(num1>num2)
            {
                cout<<"la resta es "<< num1-num2<<endl;
            }
            else
            {
                cout<<"la resta es "<< num2-num1<<endl;
            }
            break;

        case 3:
            if(num1>num2)
            {
                cout<<"el porcentaje es "<< porcentaje(num2,num1)<<endl;
            }
            else
            {
                cout<<"el porcentaje es "<< porcentaje(num1,num2)<<endl;
            }
            break;

        case 4:
            cout<<"el mcd es "<< mcdEntreDos(num1,num2)<<endl;
            break;

        case 5:
            if(num1>num2)
            {
                cout<<"el combinatorio es "<< combinatorio(num1,num2)<<endl;
            }
            else
            {
                cout<<"el combinatorio es "<< combinatorio(num2,num1)<<endl;
            }
            break;

        case 6:
            int aux=num1;
            num1=num2;
            num2=aux;
            break;
    }

}


/*
12)  funciones De un censo realizado en una población se conocen los siguientes datos:
- Día de nacimiento (2 dig.)
- Mes (2 dig.)
- Año (4 dig.)
- Sexo ('M': masculino. 'F: femenino.)
Con estos datos de cada habitante se forma un lote finalizado con un día cero.
Desarrollar el programa que determine e imprima:
a) Cuántas personas corresponden a cada grupo etario.
Utilizar función del ejercicio 7
b) Cuántos nacimientos hubo en el mes de octubre de todos los años.
c) Cuántos nacimientos hubo antes del 9 de julio de 1990.
d) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
e) Sexo de la persona más vieja (solo existe una).
Desarrollar y utilizar las funciones que considere necesarias.
*/

/*
int main()
{
    int dia,mes,anio=0;
    char sexo;

    cout<<"ingrese dia de nacimiento"<<dia;
    cin>>dia;

    while(dia!=0)
    {




    }


}
int censo (int dia, int mes, int anio, int sexo)
{

    a)
    int diaactual=22;
    int mesactual=05;
    int anioactual=2024;

    int edad=anioactual-anio;

    
    if(mes>mesactual)
    {
        edad--;
    }
    else
    {
        if(dia>diaactual)
        {
            edad--;
        }
    }

    int cont1,cont2,cont3,cont4,cont5,cont6,cont7,cont8=0;

    switch(edadGrupoEtario(edad))
    {
        case 1:
            cont1++;
            break;
        case 2:
            cont2++;
            break;
        case 3:
            cont3++;
            break;
        case 4:
            cont4++;
            break;
        case 5:
            cont5++;
            break;
        case 6:
            cont6++;
            break;
        case 7:
            cont7++;
            break;
        case 8:
            cont8++;
            break;

    }
}
*/

// recursividad 1) Mostrar n veces una línea de texto
void repeticion (string texto, int cantdeveces)
{
        cout<<texto<<endl; 
        if(cantdeveces>1)
        {
            repeticion(texto,cantdeveces-1);
        }     
}


//recursividad 2) Obtener el producto de dos números a y b, enteros y positivos, calculado como la sumatoria de a, b veces.

int producto (int num1,int num2)
{
    if(num2==0)
    {
        return 0;
    }
    else
    {
        return num1 + producto(num1,num2-1);
    }
}

// recursividad 3) Obtener a n como el producto de a, n veces.

int elevado (int num1,int num2)
{
    if(num2==0)
    {
        return 1;
    }
    else
    {
        return num1 * elevado(num1,num2-1);
    }
}

// recursividad 4) Dado un valor n devolver el término n de la serie de Fibonacci (1, 1, 2, 3, 5, 8, 13,….)

unsigned int fibonacci (int n)
{
    if(n==0)
    {
        return 0;
    }

    else
    {
        if(n==1)
        {
            return 1;
        }
        else
        {
            return fibonacci(n-1)+fibonacci(n-2);
        }
        
    }
}


int main()
{
    int num1,num2;
    cout<<"Ingrese dos numeros: "<<endl;
    cin>>num1>>num2;
    cout<<"El combinatorio de "<<num1<< " numeros tomados de a "<<num2<< " es " <<combinatoriorecursivo(num1,num2);
    return 0;

}

// recursividad 5) Calcular el combinatorio de m números tomados de a n, donde la definición recursiva es: 

unsigned long long combinatoriorecursivo (int num1, int num2)
{
    if(num2==0 || num1==num2 )
    {
        return 1;
    }
    else
    {
        return combinatoriorecursivo (num1-1,num2-1)*num1/num2 ;
        //(num1, num2-1)*( (num1-num2 +1) /num2 )
    }
}
//me da mal


/* recursividad
6) El máximo común divisor entre dos números A y B se define como:
MCD (A y B) = MCD (B y resto de A dividido B)                            si resto A dividido B es distinto a 0
MCD (A y B) = B                                                          si resto A dividido B es igual a 0 

*/
int mcd (int num1, int num2)
{
    if(num1%num2==0)
    {
        return num2;
    }
    else
    {
        return mcd(num2, num1%num2);

    }

}

// recursividad 7) Dado un número entero positivo imprimir su imagen especular (ej: de 123 su imagen es 321).
void especular(int num)
{
    if(num<10)
    {
        cout<<num;
    }
    else
    {
        cout<< num%10;
        especular(num/10);
        
    }
}