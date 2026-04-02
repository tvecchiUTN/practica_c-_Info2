#include <iostream>
#include "punto.h"

#include <math.h>
////Contructores////

//Contructor por defecto
Punto::Punto()
{
    m_x = 0;
    m_y = 0;

    //cantPuntos++;
}

//Contructor parametrizado
Punto::Punto(double valX, double valY)
{
    m_x = valX;
    m_y = valY;
    //cantPuntos++;
}

//Contructor de copia
Punto::Punto(const Punto& r_punto)
{
    this->m_x = r_punto.m_x;
    this->m_y = r_punto.m_y;
    //cantPuntos++;
}

////Seteadores////

//Seteador valor x
void Punto::setX(double valX)
{
    m_x = valX;
}

//Seteador valor y
void Punto::setY(double valY)
{
    m_y = valY;
}

//Seteador punto
void Punto::setPunto(double valX, double valY)
{
    m_x = valX;
    m_y = valY;
}

//Seteador punto
void Punto::setPunto(const Punto& r_punto)
{
    this->m_x = r_punto.m_x;
    this->m_y = r_punto.m_y;
}
////Geteadores////

//Geteador valor x
double Punto::getX() const
{
    return m_x;
}

//Geteador valor y
double Punto::getY() const
{
    return m_y;
}

//Geteador valor x
Punto Punto::getPunto() const
{
    return *this;
}

////Adicionales////

//Obtener modulo del vector
double Punto::getModulo() const
{
    return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2));
}

////Operadores////

//Sobrecarga del flujo de salida
std::ostream& operator<< (std::ostream& out, const Punto& r_punto)
{
    out << "(" << r_punto.m_x << ";" << r_punto.m_y << ")";

    return out;
}

//Sobrecarga del igual =
Punto& Punto::operator= (const Punto& r_punto)
{
    this->m_x = r_punto.m_x;
    this->m_y = r_punto.m_y;

    return *this;
}

//Sobrecarga del producto-igual *=
//Multiplicacion por escalar
Punto& Punto::operator*= (double escalar)
{
    m_x *= escalar;
    m_y *= escalar;

    return *this;
}

//Sobrecarga del multiplicador *
//Producto vectorial
double operator* (const Punto& punto1, const Punto& punto2)
{
    return punto1.m_x * punto2.m_x + punto1.m_y * punto2.m_y;
}

//Sobrecarga de la suma +
//Suma de puntos
Punto operator+ (const Punto& punto1, const Punto& punto2)
{
    return Punto(punto1.m_x + punto2.m_x, punto1.m_y + punto2.m_y);
}

//Sobrecarga del igual para comparacion ==
//Igualdad de puntos
bool operator== (const Punto& punto1, const Punto& punto2)
{
    return ((punto1.m_x == punto2.m_x) && (punto1.m_y == punto2.m_y));
}