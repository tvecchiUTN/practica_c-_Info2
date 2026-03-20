#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    double mx;
    double my;

    bool in_range(double val);
    double set_range(double val);
public:

    //Constructores
    Punto();

    Punto(double ejeX);

    Punto(double ejeX, double ejeY);

    Punto(const Punto& r_punto);


    //Metodos
    void setPunto(double ejeX, double ejeY);

    void setPunto(const Punto& r_punto);

    Punto &getPunto() {return *this;}

    void setX(double ejeX);

    double getX() const {return mx;}

    void setY(double ejeY);

    double getY() const {return my;}

    //Operadores

    Punto& operator= (const Punto& r_pun);

    Punto operator+ (const Punto& r_pun);

    Punto operator- (const Punto& r_pun);
};

#endif // PUNTO_H
