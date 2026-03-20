#include <iostream>
#include "punto.h"

int main()
{

    Punto val1(11.1, 34.87);

    Punto val2;

    Punto val3(2.554, 3.31);

    val2 = val1 + val3;
    std::cout << val2.getX() << "\n";
    std::cout << val2.getY() << "\n";

    val2 = val1 - val3;
    std::cout << val2.getX() << "\n";
    std::cout << val2.getY() << "\n";

    return 0;
}
