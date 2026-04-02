#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
//#include <fstream>
#include "punto.h"

//using namespace std;

int main()
{
    std::vector<Punto> vector_punto;

    int index = 0;
    while(1)
    {
        double valX = 0;
        double valY = 0;

        std::cout << "Ingrese valor para X: ";
        std::cin >> valX;
        std::cout << std::endl;

        std::cout << "Ingrese valor para Y: ";
        std::cin >> valY;
        std::cout << std::endl;

        if((valX == -1) && (valY == -1))
        {
            break;
        }

        Punto toVec(valX, valY);

        vector_punto.push_back(toVec);

        index++;
    }

    Punto cercano_origen;
    Punto lejos_origen;
    if(index > 0)
    {
        cercano_origen = vector_punto[0];
        lejos_origen = vector_punto[0];
    }

    for(int i = 0; i < index; i++)
    {
        std::cout << vector_punto[i] << " ";
        if(vector_punto[i].getModulo() < cercano_origen.getModulo())
        {
            cercano_origen = vector_punto[i];
        }
        else if(vector_punto[i].getModulo() > lejos_origen.getModulo())
        {
            lejos_origen = vector_punto[i];
        }
    }

    std::cout << std::endl;

    std::cout << "El punto mas cercano al origen es: " << cercano_origen << std::endl;

    std::cout << "El punto mas lejano al origen es: " << lejos_origen << std::endl;

    FILE *my_file;

    my_file = std::fopen("testing.txt", "w");

    for(int i = 0; i < index; i++)
    {
        char strPunto[32];
        std::sprintf(strPunto, "(%g;%g)", vector_punto[i].getX(), vector_punto[i].getY());

        std::fwrite(strPunto, 1, strlen(strPunto), my_file);

        if(i != (index-1))
        {
            std::fwrite(" , ", 1, 3, my_file);
        }
    }

    std::fclose(my_file);

    return 0;
}
