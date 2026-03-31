//#include <iostream>
#include "utils.h"

//using namespace std;

int main()
{
    int * vars_enteras = new int[2];
    float * vars_flotantes = new float[2];
    datos_alumno *vars_alumno = new datos_alumno[2];

    pedirValores(vars_enteras[0],vars_enteras[1]);
    pedirValores(vars_flotantes[0],vars_flotantes[1]);
    pedirValores(vars_alumno[0],vars_alumno[1]);

    mostrarValores(vars_enteras[0],vars_enteras[1]);
    mostrarValores(vars_flotantes[0],vars_flotantes[1]);
    mostrarValores(vars_alumno[0],vars_alumno[1]);

    delete[] vars_enteras;
    delete[] vars_flotantes;
    delete[] vars_alumno;
}