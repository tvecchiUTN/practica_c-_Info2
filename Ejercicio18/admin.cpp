#include "admin.h"

Admin::Admin()
{
    m_nombre = "Nombre default";
    m_identific = 0;
    m_user = "User default";
    m_passw = "Password default";
}

Admin::Admin(std::string name, int ident, std::string user, std::string passw)
{
    m_nombre = name;
    m_identific = ident;
    m_user = user;
    m_passw = passw;
}

Admin::Admin(const Admin& r_admin)
{
    m_nombre = r_admin.m_nombre;
    m_identific = r_admin.m_identific;
    m_user = r_admin.m_user;
    m_passw = r_admin.m_passw;
}