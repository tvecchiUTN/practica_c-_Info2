#ifndef MISTRING_H
#define MISTRING_H

#include <iostream>

//Clase miString
class miString
{
private:
    //Puntero a char con la direccion en el heap del string
    char* m_string;
    //Longitud del string
    int m_size;

public:
    ////Contructores////

    //Contructor por defecto, inicia todo en 0
    miString();

    //Contructor parametrizado
    miString(const char* str);

    //Contructor de copia
    miString(const miString& r_str);

    //Destructor
    ~miString();

    ////Metodos consultores de datos del string////

    //Longitud del string
    int strlen();

    //String dentro de otro string
    bool strstr(const char* str);

    //Caracter dentro del string
    int strchr(char letter);

    //Separador de strings
    miString strsplit(int pos);

    ////Operadores sobrecargados////

    //Flujo de salida
    friend std::ostream& operator<<(std::ostream& out_console, const miString& r_str);

    //Suma igual += para letras
    miString& operator+=(char c);

    //Suma igual += para string
    miString& operator+=(const miString& r_str);

    //Suma de strings
    friend miString operator+(const miString& r_str1, const miString& r_str2);

    //Signo igual a string
    miString& operator=(const miString& r_str);

    //Igualdad de strings
    bool operator==(const miString& r_str);

    //String menor a otro
    bool operator<(const miString& r_str);

    //String mayor a otro
    bool operator>(const miString& r_str);

    //Posicionador de char
    char& operator[] (int index);

    //Signo igual a char
    miString& operator= (char c);
};

#endif // MISTRING_H
