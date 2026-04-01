#include <iostream>
#include "alumno.h"

using namespace std;

ostream& operator<<(ostream& salida, const alumno& al)
{
    salida << "El nombre es: " << al.nombre;
    salida << "El legajo es: " << al.legajo;
}

int main()
{
    alumno alumno1("Tomas", 123);
    cout << alumno1;

    alumno1.setNombre("Vecchi");
    cout << alumno1;

    alumno alumno2("Ezio Auditore", 456);

    alumno1 = "Gabriel";
    cout << alumno1;

    alumno1 = alumno2;
    cout << alumno1;

    return 0;
}
