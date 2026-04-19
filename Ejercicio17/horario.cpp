#include "horario.h"
#include <cstring>
#include <iostream>

#define HORA 0
#define MINUTOS 1
#define SEGUNDOS 2

////Metodos privados////

//Seteador del horario
void Horario::setHorarios(const char* str, bool is_format24, bool is_AM)
{
    uint8_t numero_tiempo[2];
    numero_tiempo[0] = '0';
    numero_tiempo[1] = '0';
    int pos_horario = HORA; //Posicion que se encuentra viendo, si las horas, minutos o segundos
    int index_aux = 0;
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ':')
        {
            switch(pos_horario)
            {
            case HORA:
                if(index_aux == 1)
                {
                    m_hora = (numero_tiempo[0] - '0');
                }
                else
                {
                    m_hora = ((numero_tiempo[0] - '0') * 10) + (numero_tiempo[1] - '0');
                }

                if(!is_format24 && !is_AM)
                {
                    m_hora += 12;
                }
                pos_horario = MINUTOS;
            break;

            case MINUTOS:
                if(index_aux == 1)
                {
                    m_minutos = (numero_tiempo[0] - '0');
                }
                else
                {
                    m_minutos = ((numero_tiempo[0] - '0') * 10) + (numero_tiempo[1] - '0');
                }
            break;
            }

            index_aux = 0;
            numero_tiempo[0] = '0';
            numero_tiempo[1] = '0';
            continue;
        }
        numero_tiempo[index_aux] = str[i];
        if(index_aux < 2)
        {
            index_aux++;
        }
    }

    if(index_aux == 1)
    {
        m_segundos = (numero_tiempo[0] - '0');
    }
    else
    {
        m_segundos = ((numero_tiempo[0] - '0') * 10) + (numero_tiempo[1] - '0');
    }
}

////Constructores////

//Setea todos los valores a 0
Horario::Horario() : m_hora(0), m_minutos(0), m_segundos(0) {}

//Setea la hora mediante un string, tambien si es AM o PM o si el formato es 24hrs
Horario::Horario(const char* str_time, bool is_format24, bool is_AM)
{
    setHorarios(str_time, is_format24, is_AM);
}

//Constructor de copia
Horario::Horario(const Horario& r_horario) : m_hora(r_horario.m_hora), m_minutos(r_horario.m_minutos), m_segundos(r_horario.m_segundos) {}

////Metodos////

//Seteador de tiempo
Horario& Horario::setTiempo(const std::string& str_hora, bool is_format24, bool is_AM)
{
    setHorarios(str_hora.c_str(), is_format24, is_AM);

    return *this;
}

//Geteador de tiempo
std::string Horario::getTiempo() const
{
    std::string str_ret;

    str_ret += ('0' + ((char)(m_hora / 10)));
    str_ret += ('0' + ((char)(m_hora % 10)));

    str_ret += ':';

    str_ret += ('0' + ((char)(m_minutos / 10)));
    str_ret += ('0' + ((char)(m_minutos % 10)));

    str_ret += ':';

    str_ret += ('0' + ((char)(m_segundos / 10)));
    str_ret += ('0' + ((char)(m_segundos % 10)));

    return str_ret;
}

//Verificador si es AM o no, verdadero si son antes de las 13hrs
bool Horario::isAM() const
{
    if(m_hora >= 13)
    {
        return false;
    }

    return true;
}

////Operadores////

//Igualar la hora, objeto Horario
Horario& Horario::operator= (const Horario& r_horario)
{
    m_hora = r_horario.m_hora;
    m_minutos = r_horario.m_minutos;
    m_segundos = r_horario.m_segundos;

    return *this;
}

//Flujo de salida
std::ostream& operator<< (std::ostream& consoleOut, const Horario& r_horario)
{
    consoleOut << (int)r_horario.m_hora << ":" << (int)r_horario.m_minutos << ":" << (int)r_horario.m_segundos << "\n";

    return consoleOut;
}

//Si es mayor que otro horario
bool Horario::operator> (const Horario& r_horario) const
{
    if(m_hora > r_horario.m_hora)
    {
        return true;
    }
    else if((m_hora == r_horario.m_hora) && (m_minutos > r_horario.m_minutos))
    {
        return true;
    }
    else if((m_hora == r_horario.m_hora) && (m_minutos == r_horario.m_minutos) && (m_segundos > r_horario.m_segundos))
    {
        return true;
    }

    return false;
}

//Si es menor que otro horario
bool Horario::operator< (const Horario& r_horario) const
{
    if(m_hora < r_horario.m_hora)
    {
        return true;
    }
    else if((m_hora == r_horario.m_hora) && (m_minutos < r_horario.m_minutos))
    {
        return true;
    }
    else if((m_hora == r_horario.m_hora) && (m_minutos == r_horario.m_minutos) && (m_segundos < r_horario.m_segundos))
    {
        return true;
    }

    return false;
}

//Si dos horarios son iguales
bool Horario::operator== (const Horario& r_horario) const
{
    if((m_hora == r_horario.m_hora) && (m_minutos == r_horario.m_minutos) && (m_segundos == r_horario.m_segundos))
    {
        return true;
    }

    return false;
}

//Suma de horarios
Horario Horario::operator+ (const Horario& r_horario) const
{
    Horario ret_time;

    ret_time.m_hora = (m_hora + r_horario.m_hora) % 24;

    ret_time.m_minutos = (m_minutos + r_horario.m_minutos) % 60;
    if((m_minutos + r_horario.m_minutos) >= 60)
    {
        ret_time.m_hora = (ret_time.m_hora + 1) % 24;
    }

    ret_time.m_segundos = (m_segundos + r_horario.m_segundos) % 60;
    if((m_segundos + r_horario.m_segundos) >= 60)
    {
        ret_time.m_minutos = (ret_time.m_minutos + 1) % 24;
    }

    return ret_time;
}

//Precremento para sumarse el horario
Horario& Horario::operator++()
{
    m_segundos += 1;
    if(m_segundos >= 60)
    {
        m_segundos = 0;
        m_minutos += 1;

        if(m_minutos >= 60)
        {
            m_minutos = 0;
            m_hora += 1;

            if(m_hora >= 24)
            {
                m_hora = 0;
            }
        }
    }

    return *this;
}

//Postcremento para sumarse el horario
Horario Horario::operator++ (int)
{
    Horario ret_horario(*this);

    m_segundos += 1;
    if(m_segundos >= 60)
    {
        m_segundos = 0;
        m_minutos += 1;

        if(m_minutos >= 60)
        {
            m_minutos = 0;
            m_hora += 1;

            if(m_hora >= 24)
            {
                m_hora = 0;
            }
        }
    }

    return ret_horario;
}