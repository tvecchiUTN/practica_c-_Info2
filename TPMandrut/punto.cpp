#include "punto.h"
#include <iostream>
#include <cmath>

uint32_t Punto::cantCreadas = 0;
uint32_t Punto::cantExistentes = 0;

void Punto::set_with_limits(double valx, double valy)
{
    m_x = valx;

    if(valx > 1000)
    {
        m_x = 1000;
    }
    else if(valx < -1000)
    {
        m_x = -1000;
    }

    m_y = valy;

    if(valy > 1000)
    {
        m_y = 1000;
    }
    else if(valy < -1000)
    {
        m_y = -1000;
    }
}

Punto::Punto() : m_x(0), m_y(0) {cantExistentes++; cantCreadas++;}

Punto::Punto(double valx, double valy)
{
    set_with_limits(valx, valy);

    cantCreadas++;
    cantExistentes++;
}

Punto::Punto(const Punto& r_punto)
{
    m_x = r_punto.m_x;
    m_y = r_punto.m_y;

    cantCreadas++;
    cantExistentes++;
}

Punto::~Punto()
{
    cantExistentes--;
}

Punto& Punto::setPunto(double valx, double valy)
{
    set_with_limits(valx, valy);

    return *this;
}

Punto& Punto::setPunto(const Punto& r_punto)
{
    m_x = r_punto.m_x;
    m_y = r_punto.m_y;

    return *this;
}

Punto& Punto::setX(double valx)
{
    m_x = valx;

    if(valx > 1000)
    {
        m_x = 1000;
    }
    else if(valx < -1000)
    {
        m_x = -1000;
    }

    return *this;
}

Punto& Punto::setY(double valy)
{
    m_y = valy;

    if(valy > 1000)
    {
        m_y = 1000;
    }
    else if(valy < -1000)
    {
        m_y = -1000;
    }

    return *this;
}

Punto& Punto::operator= (const Punto& r_punto)
{
    m_x = r_punto.m_x;
    m_y = r_punto.m_y;

    return *this;
}

Punto Punto::operator+ (const Punto& r_punto)
{
    return Punto(m_x + r_punto.m_x, m_y + r_punto.m_y);
}

Punto Punto::operator- (const Punto& r_punto)
{
    return Punto(m_x - r_punto.m_x, m_y - r_punto.m_y);
}

Punto operator+ (double val, const Punto& r_punto)
{
    return Punto(val + r_punto.m_x, val + r_punto.m_y);
}

Punto operator- (double val, const Punto& r_punto)
{
    return Punto(val - r_punto.m_x, val - r_punto.m_y);
}

bool Punto::operator== (const Punto& r_punto)
{
    if((m_x == r_punto.m_x) && (m_y == r_punto.m_y))
    {
        return true;
    }

    return false;
}

bool Punto::operator!= (const Punto& r_punto)
{
    if((m_x != r_punto.m_x) || (m_y != r_punto.m_y))
    {
        return true;
    }

    return false;
}


bool Punto::operator> (const Punto& r_punto)
{
    if(std::sqrt(m_x * m_x + m_y * m_y) > std::sqrt(r_punto.m_x * r_punto.m_x + r_punto.m_y * r_punto.m_y))
    {
        return true;
    }

    return false;
}

bool Punto::operator< (const Punto& r_punto)
{
    if(std::sqrt(m_x * m_x + m_y * m_y) < std::sqrt(r_punto.m_x * r_punto.m_x + r_punto.m_y * r_punto.m_y))
    {
        return true;
    }

    return false;
}

std::ostream& operator<< (std::ostream& outConsole, const Punto& r_punto)
{
    outConsole << "(" << r_punto.m_x << "," << r_punto.m_y << ")" << std::endl;

    return outConsole;
}

std::istream& operator<< (std::istream& inConsole, Punto& r_punto)
{
    std::cout << "Ingrese valor para eje X: ";
    inConsole >> r_punto.m_x;

    std::cout << "Ingrese valor para eje Y: ";
    inConsole >> r_punto.m_y;

    return inConsole;
}
