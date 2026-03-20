#include "punto.h"

Punto::Punto() : mx(0), my(0) {}

bool Punto::in_range(double val)
{
    if((val >= -1000) && (val <= 1000))
    {
        return true;
    }

    return false;
}

Punto::Punto(double ejeX)
{
    if(!in_range(ejeX))
    {
        mx = 0;
        my = 0;
        return;
    }

    mx = ejeX;
    my = 0;
}

Punto::Punto(double ejeX, double ejeY)
{
    if(!in_range(ejeX) || !in_range(ejeY))
    {
        mx = 0;
        my = 0;
        return;
    }

    mx = ejeX;
    my = ejeY;
}

Punto::Punto(const Punto& r_punto) : mx(r_punto.mx), my((r_punto.my)) {}

void Punto::setPunto(double ejeX, double ejeY)
{
    if(!in_range(ejeX) || !in_range(ejeY))
    {
        return;
    }

    mx = ejeX;
    my = ejeY;
}

void Punto::setPunto(const Punto& r_punto)
{
    mx = r_punto.mx;
    my = r_punto.my;
}

Punto& Punto::getPunto() {return *this;}

void Punto::setX(double ejeX)
{
    if(!in_range(ejeX))
    {
        return;
    }
    mx = ejeX;
}

double Punto::getX() const {return mx;}

void Punto::setY(double ejeY)
{
    if(!in_range(ejeY))
    {
        return;
    }
    my = ejeY;
}

double Punto::getY() const {return my;}

Punto& Punto::operator =(const Punto& r_pun)
{
    mx = r_pun.mx;
    my = r_pun.my;

    return *this;
}