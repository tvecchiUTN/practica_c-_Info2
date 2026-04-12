#include "alumno.h"
#include <string.h>
#include <cstring>
#include <iostream>

////Metodos privados////

//Copiar nombre, pero con memoria dinamica
char* Alumno::cpy_name(const char* str)
{
    char* ret_str = new char[strlen(str) + 1];

    int i;
    for(i = 0; str[i]; i++)
    {
        ret_str[i] = str[i];
    }

    ret_str[i] = '\0';

    return ret_str;
}

////Constructores////
//Constructor por defecto
Alumno::Alumno()
{
    m_nombre = nullptr;
    m_legajo = 0;
}

//Constrctor parametrizado
Alumno::Alumno(const char* nombre, long leg)
{
    m_legajo = leg;

    m_nombre = cpy_name(nombre);
}

//Constructor de copia
Alumno::Alumno(const Alumno& r_al)
{
    m_legajo = r_al.m_legajo;

    m_nombre = cpy_name(r_al.m_nombre);
}

//Destructor
Alumno::~Alumno()
{
    delete[] m_nombre;
}

////Metodos////

//Seteador de nombre
Alumno& Alumno::setNombre(const char* nombre)
{
    delete[] m_nombre;

    m_nombre = cpy_name(nombre);

    return *this;
}

//Seteador de legajo
Alumno& Alumno::setLegajo(long legajo)
{
    m_legajo = legajo;

    return *this;
}

//Geteador de nombre
char* Alumno::getNombre() const
{
    return m_nombre;
}

//Geteador de legajo
long Alumno::getLegajo() const
{
    return m_legajo;
}

////Operadores////

//Asignacion con string
Alumno& Alumno::operator= (const char* nombre)
{
    delete[] m_nombre;

    m_nombre = cpy_name(nombre);

    return *this;
}

//Asignacion de legajo
Alumno& Alumno::operator= (long legajo)
{
    m_legajo = legajo;

    return *this;
}

//Asignacion con alumno
Alumno& Alumno::operator= (const Alumno& r_al)
{
    m_legajo = r_al.m_legajo;

    delete[] m_nombre;

    m_nombre = cpy_name(r_al.m_nombre);

    return *this;
}

//Flujo de salida
std::ostream& operator<< (std::ostream& salida, const Alumno& r_al)
{
    salida << "Nombre: " << r_al.m_nombre << ", ";
    salida << "Leg: " << r_al.m_legajo << std::endl;

    return salida;
}

/**
//Flujo de entrada, probando
std::istream& operator>> (std::istream& entrada, Alumno& r_al)
{

}
**/

//Igualacion de nombres
bool Alumno::operator== (const Alumno& r_al) const
{
    if(!strcmp(m_nombre, r_al.m_nombre))
    {
        return true;
    }

    return false;
}