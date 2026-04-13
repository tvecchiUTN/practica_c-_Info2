#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

class Alumno
{
private:
    //Nombre del alumno
    char* m_nombre;
    //Legajo del alumno
    long m_legajo;

    //Copiar nombre, pero con memoria dinamica
    char* cpy_name(const char* str);

public:
    ////Constructores////
    //Constructor por defecto
    Alumno();

    //Constrctor parametrizado
    Alumno(const char* nombre, long leg);

    //Constructor de copia
    Alumno(const Alumno& r_al);

    //Destructor
    ~Alumno();

    ////Metodos////

    //Seteador de nombre
    Alumno& setNombre(const char* nombre);

    //Seteador de legajo
    Alumno& setLegajo(long legajo);

    //Geteador de nombre
    char* getNombre() const;

    //Geteador de legajo
    long getLegajo() const;

    ////Operadores////

    //Asignacion con puntero a char
    Alumno& operator= (const char* nombre);

    //Asignacion con string
    Alumno& operator= (std::string str);

    //Asignacion de legajo
    Alumno& operator= (long legajo);

    //Asignacion con alumno
    Alumno& operator= (const Alumno& r_al);

    //Flujo de salida
    friend std::ostream& operator<< (std::ostream& salida, const Alumno& r_al);

    //Flujo de entrada, probando
    friend std::istream& operator>> (std::istream& entrada, Alumno& r_al);

    //Igualacion de nombres
    bool operator== (const Alumno& r_al) const;
};


#endif // ALUMNO_H
