#ifndef PUNTO_H
#define PUNTO_H

#include <cstdint>
#include <iostream>

class Punto
{
private:
    static uint32_t cantCreadas;

    static uint32_t cantExistentes;

protected:
    double m_x;
    double m_y;

    void set_with_limits(double valx, double valy);

public:
    //Constructor por defecto
    Punto();

    Punto(double valx, double valy);

    Punto(const Punto& r_punto);

    ~Punto();

    Punto& setPunto(double valx, double valy);

    Punto& setPunto(const Punto& r_punto);

    Punto getPunto() const {return Punto(m_x, m_y);}

    Punto& setX(double valx); //{m_x = valx; return *this;} Para ejercicio 1

    Punto& setY(double valy); //{m_y = valy; return *this;} Para ejercicio 1

    double getX() const {return m_x;}

    double getY() const {return m_y;}

    uint32_t getCantCreada() const {return cantCreadas;}

    uint32_t getCantExistentes() const {return cantExistentes;}

    Punto& operator= (const Punto& r_punto);

    Punto operator+ (const Punto& r_punto);

    Punto operator- (const Punto& r_punto);

    friend Punto operator+ (double val, const Punto& r_punto);

    friend Punto operator- (double val, const Punto& r_punto);

    bool operator== (const Punto& r_punto);

    bool operator!= (const Punto& r_punto);

    bool operator> (const Punto& r_punto);

    bool operator< (const Punto& r_punto);

    friend std::ostream& operator<< (std::ostream& outConsole, const Punto& r_punto);

    friend std::istream& operator<< (std::istream& inConsole, Punto& r_punto);
};

#endif // PUNTO_H
