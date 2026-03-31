#include <iostream>

using namespace std;

template <typename comodin>
void pedirValores(comodin* vector, int cdadVal)
{
    for(int i = 0; i < cdadVal; i++)
    {
        cin >> *(vector + i);
    }
    cout << endl;
}

template <typename comodin>
void mostrarValores(const comodin* vector, int cdadVal)
{
    for(int i = 0; i < cdadVal; i++)
    {
        cout << "Valor " << i << " es: " << vector[i] << endl;
    }
}

int main()
{
    int * vars_enteras = new int[2];
    float * vars_flotantes = new float[3];

    pedirValores(vars_enteras,2);
    pedirValores(vars_flotantes,3);

    mostrarValores(vars_enteras,2);
    mostrarValores(vars_flotantes,3);

    delete[] vars_enteras;
    delete[] vars_flotantes;
}