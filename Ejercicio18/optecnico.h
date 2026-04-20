#ifndef OPTECNICO_H
#define OPTECNICO_H

#include "empleado.h"
#include <vector>

class OpTecnico : public Empleado
{
protected:
    std::vector<std::string> m_tareas_del_dia;

public:
    OpTecnico();
};

#endif // OPTECNICO_H
