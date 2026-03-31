#include <iostream>
#include "utils.h"

using namespace std;

void pedirValores(int& i_val1, int& i_val2)
{
    cout << "Ingrese primer valor: ";
    cin >> i_val1;

    cout << endl;

    cout << "Ingrese segundo valor: ";
    cin >> i_val2;

    cout << endl;
}

void pedirValores(float& f_val1, float& f_val2)
{
    cout << "Ingrese primer valor: ";
    cin >> f_val1;

    cout << endl;

    cout << "Ingrese segundo valor: ";
    cin >> f_val2;

    cout << endl;
}

void pedirValores(datos_alumno& da_val1, datos_alumno& da_val2)
{
    cout << "Ingrese el nombre del primer miembro: ";

    cin >> da_val1.nombre;

    cout << endl;

    cout << "Ingrese su legajo: ";

    cin >> da_val1.legajo;

    cout << "Ahora ingrese el nombre del segundo miembro: ";

    cin >> da_val2.nombre;

    cout << endl;

    cout << "Ingrese su legajo: ";

    cin >> da_val2.legajo;

    cout << endl;
}

void mostrarValores(int i_val1, int i_val2)
{
    cout << "El primer valor es: " << i_val1 << endl;

    cout << "El segundo valor es: " << i_val2 << endl;
}

void mostrarValores(float f_val1, float f_val2)
{
    cout << "El primer valor es: " << f_val1 << endl;

    cout << "El segundo valor es: " << f_val2 << endl;
}

void mostrarValores(datos_alumno da_val1, datos_alumno da_val2)
{
    cout << "Los datos del primer miembro son: " << endl;

    cout << "Nombre: " << da_val1.nombre;

    cout << "Legajo: " << da_val1.legajo;

    coud << endl;

    cout << "Los datos del segundo miembro son: " << endl;

    cout << "Nombre: " << da_val2.nombre;

    cout << "Legajo: " << da_val2.legajo;

    coud << endl;
}