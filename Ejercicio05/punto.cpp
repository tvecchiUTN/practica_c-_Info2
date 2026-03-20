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

double Punto::set_range(double val)
{
    if(val > 1000)
    {
        return 1000;
    }
    else if(val < -1000)
    {
        return -1000;
    }

    return val;
}

Punto::Punto(double ejeX) : mx(set_range(ejeX)), my(0) {}

Punto::Punto(double ejeX, double ejeY) : mx(set_range(ejeX)), my(set_range(ejeY)) {}

Punto::Punto(const Punto& r_punto) : mx(r_punto.mx), my((r_punto.my)) {}

void Punto::setPunto(double ejeX, double ejeY)
{
    mx = set_range(ejeX);
    my = set_range(ejeY);
}

void Punto::setPunto(const Punto& r_punto)
{
    mx = r_punto.mx;
    my = r_punto.my;
}

void Punto::setX(double ejeX)
{
    mx = set_range(ejeX);
}

void Punto::setY(double ejeY)
{
    my = set_range(ejeY);
}

Punto& Punto::operator =(const Punto& r_pun)
{
    mx = r_pun.mx;
    my = r_pun.my;

    return *this;
}

Punto Punto::operator +(const Punto& r_pun)
{
    Punto ret;

    ret.setX(set_range(mx + r_pun.mx));
    ret.setY(set_range(my + r_pun.my));

    return ret;
}

Punto Punto::operator -(const Punto& r_pun)
{
    Punto ret;

    ret.setX(set_range(mx - r_pun.mx));
    ret.setY(set_range(my - r_pun.my));

    return ret;
}