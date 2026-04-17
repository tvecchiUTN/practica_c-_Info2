#ifndef FECHAHORA_H
#define FECHAHORA_H

#include "horario.h"

class FechaHora : public Horario
{
private:
    uint8_t m_dia;
    uint8_t m_mes;
    uint32_t m_anio;

public:
    FechaHora();
};

#endif // FECHAHORA_H
