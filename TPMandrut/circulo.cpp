#include "circulo.h"
#include "punto.h"

Circulo::Circulo()
{
    m_x = 0;
    m_y = 0;
    m_radio = 1;
}

Circulo::Circulo(double radio)
{
    m_x = 0;
    m_y = 0;
    m_radio = radio;
}

Circulo::Circulo(double radio, double valx)
{
    m_x = valx;
    m_y = 0;
    m_radio = radio;
}

Circulo::Circulo(double radio, double valx, double valy)
{
    m_x = valx;
    m_y = valy;
    m_radio = radio;
}

Circulo& Circulo::operator= (const Circulo& r_circ)
{
    m_x = r_circ.m_x;
    m_y = r_circ.m_y;
    m_radio = r_circ.m_radio;

    return *this;
}

/*
Circulo& Circulo::operator= (const Punto& r_punto)
{
    m_x = r_punto.m_x;
    m_y = r_punto.m_y;

    return *this;
}
*/