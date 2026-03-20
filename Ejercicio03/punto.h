#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    double mx;
    double my;

    bool in_range(double val);
public:
    Punto();

    Punto(double ejeX);

    Punto(double ejeX, double ejeY);

    void setPunto(double ejeX, double ejeY);

    void setPunto(const Punto& r_punto);

    Punto &getPunto();

    void setX(double ejeX);

    double getX() const;

    void setY(double ejeY);

    double getY() const;
};

#endif // PUNTO_H
