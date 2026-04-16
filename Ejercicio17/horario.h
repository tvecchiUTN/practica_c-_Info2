#ifndef HORARIO_H
#define HORARIO_H

#include <cstdint>
#include <string>

class Horario
{
private:

    uint8_t m_hora;
    uint8_t m_minutos;
    uint8_t m_segundos;

    void setHorarios(const char* str, bool format24, bool AM);

public:
    ////Constructores////

    //Setea todos los valores a 0
    Horario();

    //Setea la hora mediante un string, tambien si es AM o PM o si el formato es 24hrs
    Horario(const char* str_time, bool is_format24, bool is_AM);

    //Constructor de copia
    Horario(const Horario& r_horario);

    ////Metodos////

    //Seteador de tiempo
    Horario& setTiempo(const std::string&, bool is_format24, bool is_AM);

    //Geteador de tiempo
    std::string getTiempo() const;

    //Verificador si es AM o no, verdadero si son antes de las 13hrs
    bool isAM() const;

    ////Operadores////

    //Flujo de salida
    friend std::ostream& operator<< (std::ostream& consoleOut, const Horario& r_horario);

    //Si es mayor que otro horario
    bool operator> (const Horario& r_horario) const;

    //Si es menor que otro horario
    bool operator< (const Horario& r_horario) const;

    //Si dos horarios son iguales
    bool operator== (const Horario& r_horario) const;

    //Suma de horarios
    Horario operator+ (const Horario& r_horario) const;

    //Precremento para sumarse el horario
    Horario& operator++();

    //Postcremento para sumarse el horario
    Horario operator++ (int dummy);
};

#endif // HORARIO_H
