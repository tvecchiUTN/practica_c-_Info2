#include "fechahora.h"
#include "horario.h"
#include <iostream>

#define DIA 0
#define MES 1
#define ANIO 2

void FechaHora::setFechaHora(const char* str)
{
    uint8_t numero_dia[4];
    numero_dia[0] = '\0';
    numero_dia[1] = '\0';
    int pos_horario = DIA; //Posicion que se encuentra viendo, si el dia, minutos o segundos
    int index_aux = 0;
    for(int i = 0; str[i] || (str[i] == ' '); i++)
    {
        if(str[i] == '/')
        {
            switch(pos_horario)
            {
            case DIA:
                if(index_aux == 1)
                {
                    m_dia = (numero_dia[0] - '0');
                }
                else
                {
                    m_dia = ((numero_dia[0] - '0') * 10) + (numero_dia[1] - '0');
                }
                pos_horario = MES;
                break;

            case MES:
                if(index_aux == 1)
                {
                    m_mes = (numero_dia[0] - '0');
                }
                else
                {
                    m_mes = ((numero_dia[0] - '0') * 10) + (numero_dia[1] - '0');
                }

                pos_horario = ANIO;

                break;
            }

            index_aux = 0;
            numero_dia[0] = '\0';
            numero_dia[1] = '\0';
            continue;
        }

        numero_dia[index_aux] = str[i];
        if(index_aux < 2)
        {
            index_aux++;
        }
        else if(pos_horario == ANIO)
        {
            index_aux++;
        }
    }

    m_anio = ((numero_dia[0] - '0') * 1000) + ((numero_dia[1] - '0') * 100) + ((numero_dia[2] - '0') * 10) + ((numero_dia[3] - '0'));
}


FechaHora::FechaHora()
{
    m_hora = 0;
    m_minutos = 0;
    m_segundos = 0;

    m_dia = 1;
    m_mes = 1;
    m_anio = 1970;
}

FechaHora::FechaHora(const char* str, bool isFormat24, bool isAM)
{
    setFechaHora(str);

    char buffHora[9];
    int index_hora = 0;
    bool timeSection = false;

    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
        {
            timeSection = true;
            continue;
        }

        if(timeSection)
        {
            buffHora[index_hora] = str[i];
            index_hora++;
        }
    }

    buffHora[index_hora] = '\0';

    setHorarios(buffHora, isFormat24, isAM);
}


std::ostream& operator<< (std::ostream& stdSalida, const FechaHora& r_fechaHora)
{
    std::cout << (int)r_fechaHora.m_dia << "/" << (int)r_fechaHora.m_mes << "/" << r_fechaHora.m_anio << " ";
    std::cout << (int)r_fechaHora.m_hora << ":" << (int)r_fechaHora.m_minutos << ":" << (int)r_fechaHora.m_segundos;
    std::cout << std::endl;

    return stdSalida;
}