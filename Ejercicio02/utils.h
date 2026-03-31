#ifndef __UTILS_H
#define __UTILS_H

struct datos_alumno
{
    char nombre[20];
    long legajo;
};

void pedirValores(int& i_val1, int& i_val2);

void pedirValores(float& f_val1, float& f_val2);

void pedirValores(datos_alumno& da_val1, datos_alumno& da_val2);

void mostrarValores(int i_val1, int i_val2);

void mostrarValores(float f_val1, float f_val2);

void mostrarValores(datos_alumno da_val1, datos_alumno da_val2);

#endif //
