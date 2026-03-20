#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    double mx;
    double my;

    bool in_range(double val);
public:

    //Constructores
    Punto();

    Punto(double ejeX);

    Punto(double ejeX, double ejeY);

    Punto(const Punto& r_punto);


    //Metodos
    void setPunto(double ejeX, double ejeY);

    void setPunto(const Punto& r_punto);

    Punto &getPunto();

    void setX(double ejeX);

    double getX() const;

    void setY(double ejeY);

    double getY() const;

    //Operadores

    Punto& operator= (const Punto& r_pun);
};

#endif // PUNTO_H
