#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

class Circulo : public Punto
{
    double m_radio;

public:
    Circulo();

    Circulo(double radio);

    Circulo(double radio, double valx);

    Circulo(double radio, double valx, double valy);

    Circulo& operator= (const Circulo& r_circ);

    Circulo& operator= (const Punto& r_circ);
};

#endif // CIRCULO_H
