#include "alumno.h"

#include <string.h>

//Metodos privados
char* alumno::cfgName(const char* src)
{
    char* ret_name = nullptr;

    int szName = strlen(src);

    ret_name = new char[szName];

    int i;
    for(i = 0; src[i] ; i++)
    {
        *(ret_name+i) = src[i];
    }
    *(ret_name+i) = '\0';

    return ret_name;
}

//Constructores
alumno::alumno()
{
    nombre = nullptr;
    legajo = 0;
    is_repeat_name = false;
}

alumno::alumno(const char* n, long l)
{
    nombre = cfgName(n);
    is_repeat_name = true;

    legajo = l;
}

alumno::alumno(const alumno& r_al)
{
    if(is_repeat_name)
    {
        delete[] nombre;
    }

    nombre = cfgName(r_al.nombre);
    is_repeat_name = true;

    legajo = r_al.legajo;
}

//Metodos publicos

//Seteadores
void alumno::setLegajo(long l)
{
    legajo = l;
}

void alumno::setNombre(const char* name)
{
    nombre = cfgName(name);
}

//Geteadores
long alumno::getLegajo() const
{
    return legajo;
}

char* alumno::getNombre() const
{
    return nombre;
}

//Operadores
alumno& alumno::operator=(const char* name)
{
    nombre = cfgName(name);

    return *this;
}

alumno& alumno::operator=(long l)
{
    legajo = l;

    return *this;
}

alumno& alumno::operator=(const alumno& r_al)
{
    nombre = cfgName(r_al.nombre);

    legajo = r_al.legajo;

    return *this;
}

//Destructor
alumno::~alumno()
{
    delete[] nombre;
}