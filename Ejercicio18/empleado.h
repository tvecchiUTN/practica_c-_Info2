#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string.h>
#include <string>

class Empleado
{
protected:
    std::string m_nombre;
    int m_identific;

public:
    Empleado();

    Empleado(std::string name, int indentific);

    Empleado(const Empleado& r_empleado);
};

#endif // EMPLEADO_H
