#include <iostream>
#include "alumno.h"
#include <QFile>
#include <QTextStream>

int main()
{
    int var = 56;
    QFile archivo("C:/Users/tomas/GitHub/practica_c-_Info2/Ejercicio14/test.txt");
    if(archivo.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        QTextStream stream(&archivo);
        stream << "Escribo el valor de la variable: " << var << "\n";

        archivo.close();
    }

    return 0;
}
