#include <iostream>

//Este es opcional
using namespace std;
/*
    Ejercicio 1: Herramientas de nuestro nuevo entorno de desarrollo
*/

int *pedir_valores(int &var1, int &var2)
{
    int *vec = new int[10];
    if(!vec)
    {
        cout << "Error: memoria insuficiente" << endl;
        return vec;
    }

    int j = 23;
    for(int i = 0; i < 10; i++)
    {
        vec[i] = j;
        j++;
    }

    cout << "Ingrese un numero positivo: ";
    cin >> var1;
    cout << "\n";

    cout << "Ingrese otro numero: ";
    cin >> var2;
    cout << "\n";

    return vec;
}

void mostrar_valores(int *vec, int var1, int var2)
{
    cout << "El primer valor es: " << vec[var1] << " y el segundo es: " << vec[var2] << endl;
    cout << "Si tenias dudas, su direccion es: " << vec << endl;

    delete[] vec;
}


int main()
{
    int val1 = 0;
    int val2 = 0;

    int *vec = nullptr;

    vec = pedir_valores(val1, val2);
    mostrar_valores(vec, val1, val2);
}
