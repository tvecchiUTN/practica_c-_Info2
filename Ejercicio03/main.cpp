#include <iostream>

using namespace std;

void pedirValores(int* vector, int n = 1)
{
    if(!vector)
    {
        return;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Ingrese el valor: ";
        cin >> vector[i];
    }
    cout << endl;
}

int main()
{
    //int variable;
    int vector[5];


    //pedirValores ( &variable );
    pedirValores(vector, 5 );

    for(int i = 0; i < 5; i++)
    {
        cout << "El valor es: " <<vector[i] << endl;
    }
}