#include "punto.h"

Punto::Punto() : mx(0), my(0) {}

Punto::Punto(double ejeX, double ejeY) : mx(ejeX), my(ejeY) {}

void Punto::setPunto(double ejeX, double ejeY)
{
    mx = ejeX;
    my = ejeY;
}

Punto& Punto::getPunto() {return *this;}

void Punto::setX(double ejeX) {mx = ejeX;}

double Punto::getX() const {return mx;}

void Punto::setY(double ejeY) {my = ejeY;}

double Punto::getY() const {return my;}