#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto
{
private:
    double m_x;
    double m_y;

    //Contador de invocaciones
    static int cantPuntos;

public:
    ////Contructores////

    //Contructor por defecto
    Punto();

    //Contructor parametrizado
    Punto(double valX, double valY);

    //Contructor de copia
    Punto(const Punto& r_punto);

    ////Seteadores////

    //Seteador valor x
    void setX(double valX);

    //Seteador valor y
    void setY(double valY);

    //Seteador punto
    void setPunto(double valX, double valY);

    ////Geteadores////

    //Geteador valor x
    double getX() const;

    //Geteador valor y
    double getY() const;

    //Geteador valor x
    Punto getPunto() const;

    ////Adicionales////

    //Obtener modulo del vector
    double getModulo() const;

    ////Operadores////

    //Sobrecarga del flujo de salida
    friend std::ostream& operator<< (std::ostream& out, const Punto& r_punto);

    //Sobrecarga del igual =
    Punto& operator= (const Punto& r_punto);

    //Sobrecarga del producto-igual *=
    //Multiplicacion por escalar
    Punto& operator*= (double escalar);

    //Sobrecarga del multiplicador *
    //Producto vectorial
    friend double operator* (const Punto& punto1, const Punto& punto2);

    //Sobrecarga de la suma +
    //Suma de puntos
    friend Punto operator+ (const Punto& punto1, const Punto& punto2);

    //Sobrecarga del igual para comparacion ==
    //Igualdad de puntos
    friend bool operator== (const Punto& punto1, const Punto& punto2);
};


#endif // PUNTO_H
