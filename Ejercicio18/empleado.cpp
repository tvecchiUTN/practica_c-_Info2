#include "empleado.h"

Empleado::Empleado() : m_nombre("Usuario default"), m_identific(0) {}

Empleado::Empleado(std::string name, int indentific) : m_nombre(name), m_identific(indentific) {}

Empleado::Empleado(const Empleado& r_empleado) : m_nombre(r_empleado.m_nombre), m_identific(r_empleado.m_identific) {}