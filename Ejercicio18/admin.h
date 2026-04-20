#ifndef ADMIN_H
#define ADMIN_H

#include "empleado.h"

class Admin : public Empleado
{
protected:
    std::string m_user;
    std::string m_passw;

public:
    Admin();

    Admin(std::string name, int ident, std::string user, std::string passw);

    Admin(const Admin& r_admin);
};

#endif // ADMIN_H
