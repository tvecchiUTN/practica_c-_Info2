#ifndef FECHAHORA_H
#define FECHAHORA_H

#include "horario.h"

class FechaHora : public Horario
{
private:
    uint8_t m_dia;
    uint8_t m_mes;
    uint32_t m_anio;

    void setFechaHora(const char* str);

public:
    FechaHora();

    FechaHora(const char* str, bool isFormat24, bool isAM);

    FechaHora(const FechaHora& r_fechaHora);

    FechaHora(const Horario& r_horario);

    friend std::ostream& operator<< (std::ostream& stdSalida, const FechaHora& r_fechaHora);
};

#endif // FECHAHORA_H
