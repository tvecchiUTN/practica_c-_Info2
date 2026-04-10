#include <iostream>
#include "mivector.h"

int main() {
    // 1. Probamos constructores
    int arr1[] = {10, 20, 30};
    miVector<int> v1(arr1, 3); // Parametrizado
    miVector<int> v2;          // Por defecto

    // 2. Probamos el operador +=
    v2 += 40;
    v2 += 50;

    std::cout << "Longitud de v1: " << v1.length() << "\n"; // Debe ser 3
    std::cout << "Posicion del valor 20 en v1: " << v1.posicion(20) << "\n"; // Debe ser 1

    // 3. Probamos la concatenacion (+) y asignacion (=)
    miVector<int> v3 = v1 + v2;

    std::cout << "Contenido de v3 (concatenado):\n";
    std::cout << v3;

    // 4. Probamos igualdad (==)
    miVector<int> v4(v1); // Constructor de copia
    if (v1 == v4) {
        std::cout << "v1 y v4 son iguales!\n";
    }

    // 5. Probamos operador [] (Lectura y Escritura)
    v3[2] = 99; // Guarda 99 en la posicion 2
    std::cout << "v3[2] modificado es: " << v3[2] << "\n";

    // 6. Probamos operador [] fuera de rango (pidiendo el indice 10)
    int valorErroneo = v3[10];
    std::cout << "Valor fuera de rango: " << valorErroneo << " (Devuelve 0 como se pidio)\n";

    return 0;
}