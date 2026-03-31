#include <iostream>
#include <string.h>

using namespace std;

struct datos_alumno
{
    char nombre[20];
    int legajo;
};

datos_alumno& operator+= (datos_alumno& da, const char* name)
{
    strcpy(da.nombre, name);
    return da;
}

datos_alumno& operator+= (datos_alumno& da, int leg)
{
    da.legajo = leg;
    return da;
}

int main()
{

    datos_alumno alumno1;

    //alumno1 += "Tomas";
    //alumno1 += 123;

    (alumno1 += "Tomi") += 345;

    cout << "El alumno es " << alumno1.nombre << " y su legajo es " << alumno1.legajo << endl;

    return 0;
}
