#include <iostream>

#include "punto.h"

int main()
{
    Punto hola1;

    Punto hola2(2.14);

    Punto hola3(4.56, 3.14);


    std::cout << hola2.getY() << "\n";
    return 0;
}
