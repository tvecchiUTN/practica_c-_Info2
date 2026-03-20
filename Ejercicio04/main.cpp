#include <iostream>

#include "punto.h"

int main()
{
    Punto probando(1.11, 4.44);

    Punto seta(probando);

    Punto operat = probando;

    std::cout << seta.getX() << " " << seta.getY() << "\n";

    std::cout << operat.getX() << " " << operat.getY() << "\n";

    return 0;
}
