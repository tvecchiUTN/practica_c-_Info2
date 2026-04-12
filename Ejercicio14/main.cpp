#include <iostream>
#include "alumno.h"
#include <QFile>
#include <QTextStream>

int main()
{
    Alumno yo("Tomas Gabriel", 233);

    Alumno el("Juan Perez", 789);

    //std::cout << yo.getNombre() << " " << yo.getLegajo() << std::endl;
    std::cout << el;
}
