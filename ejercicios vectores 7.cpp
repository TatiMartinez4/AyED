/*7) Dado un número N (<20), y dos vectores A y B de N elementos que contenga valores entre 0..9
que representan números naturales muy largos
a) genere e informe un tercer vector SUMA de N+1 elementos que sea el resultante de la suma de
los dos números.
b) genere e informe un tercer vector RESTA de N elementos que sea el resultante de la resta de
los dos números.
*/

// Todo se ingresa tal como si fuesen numeros, de adelante para atras.

#include <iostream>
using namespace std;

void llenarVector(int v[], int tamanio);
void vectorConCeros(int v[], int tamanio);
void sumarVectores (int v1[], int v2[], int suma[], int tamanio);
void leerVector(int v[], int tamanio);
void restarVectores(int v1[], int v2[], int resta[], int tamanio);


int main()
{
    int n=0;
    cout<<"ingrese un numero menor a 20"<<endl;
    cin>>n;
    int a [n];
    llenarVector(a,n);
    int b [n];
    llenarVector(b,n);

    int suma[n+1];
    vectorConCeros(suma,n+1);
    sumarVectores (a, b, suma, n);

    //cout<<"el vector suma es " <<endl;
    //leerVector(suma, n+1);

    int resta[n];
    vectorConCeros(resta,n);
    restarVectores(a,b,resta,n);

    cout<<"el vector resta es " <<endl;
    leerVector(resta, n);

    return 0;
}

void llenarVector(int v[], int tamanio)
{
    for(int i=tamanio-1 ; i>=0; i--)
    {
        cout<<"ingrese un numero"<<endl;
        cin>> v[i];
    }
}

void vectorConCeros(int v[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
        v[i]=0;  
    }     
}

void sumarVectores (int v1[], int v2[], int suma[], int tamanio)
{
    bool c=false;
    for(int i=0; i<tamanio; i++)
    {
        
        if (c)
        {
            if((v1[i]+v2[i]+1)<10)
            {
                suma[i]+=v1[i]+v2[i]+1;
                c=false;
            }
            else
            {
                suma[i]+=v1[i]+v2[i]+1-10;
                c=true;
            }
                    
        }
        else
        {
            if((v1[i]+v2[i])<10)
            {
                suma[i]+=v1[i]+v2[i];
                c=false;
            }
            else
            {
                suma[i]+=v1[i]+v2[i]-10;
                c=true;
            }
        }
    }

    if(c)
    {
        suma[tamanio]=1;
    }
    else
        suma[tamanio]=0;
}

void restarVectores(int v1[], int v2[], int resta[], int tamanio)
{
    for(int i=0; i<tamanio ; i++)
    {
        if(v1[i]-v2[i]>=0)
        {
            resta[i]=v1[i]-v2[i];
        }
        else
        {
            resta[i]=v1[i]+10-v2[i];
            v1[i+1]-=1;
        }
    }

}


void leerVector(int v[], int tamanio)
{
    for(int i=tamanio-1; i>=0 ; i--)
    {
        cout<<v[i];
    }
}