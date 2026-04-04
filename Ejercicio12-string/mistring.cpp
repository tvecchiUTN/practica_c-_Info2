#include <iostream>
#include <cstring>
#include "mistring.h"

#define NOT_FOUND -1

////Contructores////

//Contructor por defecto, inicia todo en 0
miString::miString()
{
    m_string = nullptr;
    m_size = 0;
}

//Contructor parametrizado
miString::miString(const char* str)
{
    m_size = std::strlen(str) +1;
    m_string = new char[m_size];

    for(int i = 0; i < m_size; i++)
    {
        m_string[i] = str[i];
    }

}

//Contructor de copia
miString::miString(const miString& r_str)
{
    m_size = r_str.m_size;
    m_string = new char[m_size];

    for(int i = 0; i < m_size; i++)
    {
        m_string[i] = r_str.m_string[i];
    }
}

miString::~miString()
{
    delete[] m_string;
    m_string = nullptr;
}

////Metodos consultores de datos del string////

//Longitud del string
int miString::strlen()
{
    return m_size;
}

//String dentro de otro string
bool miString::strstr(const char* str)
{
    if(std::strstr(m_string, str))
    {
        return true;
    }

    return false;
}

//Caracter dentro del string
int miString::strchr(char letter)
{
    int index;
    for(index = 0; index < m_size; index++)
    {
        if(m_string[index] == letter)
        {
            return index;
        }
    }

    return NOT_FOUND;
}

//Separador de strings
miString miString::strsplit(int pos)
{
    char temp_c = *(m_string + pos);

    *(m_string + pos) = '\0';

    miString ret_str(m_string);

    *(m_string + pos) = temp_c;

    return ret_str;
}

std::ostream& operator<<(std::ostream& out_console, const miString& r_str)
{
    out_console << r_str.m_string;

    return out_console;
}

//Suma igual += para letras
miString& miString::operator+=(char c)
{
    char* aux_str = new char[m_size + 1];

    for(int i = 0; i < m_size; i++)
    {
        aux_str[i] = m_string[i];
    }

    aux_str[m_size-1] = c;
    aux_str[m_size] = '\0';

    m_size++;

    delete[] m_string;

    m_string = aux_str;

    return *this;
}


//Suma igual += para string
miString& miString::operator+=(const miString& r_str)
{
    int szTotal = this->m_size + r_str.m_size - 1;

    char* aux_str = new char[szTotal];

    int i;
    for(i = 0; i < (m_size-1); i++)
    {
        aux_str[i] = m_string[i];
    }
    for(int j = 0; j < r_str.m_size; j++)
    {
        aux_str[i] = r_str.m_string[j];
        i++;
    }

    delete[] m_string;

    m_string = aux_str;

    m_size = szTotal;

    return *this;
}


//Suma de strings
miString operator+(const miString& r_str1, const miString& r_str2)
{
    int szTotal = r_str1.m_size + r_str2.m_size -1;

    char* aux_str = new char[szTotal];

    int i;
    for(i = 0; i < (r_str1.m_size-1); i++)
    {
        aux_str[i] = r_str1.m_string[i];
    }
    for(int j = 0; j < r_str2.m_size; j++)
    {
        aux_str[i] = r_str2.m_string[j];
        i++;
    }

    miString ret(aux_str);

    return ret;
}

miString& miString::operator=(const miString& r_str)
{
    delete[] m_string;

    m_string = new char[r_str.m_size];
    m_size = r_str.m_size;

    for(int i = 0; i <= m_size; i++)
    {
        this->m_string[i] = r_str.m_string[i];
    }

    return *this;
}

//Igualdad de strings
bool miString::operator==(const miString& r_str)
{
    char* p_str1 = m_string;
    char* p_str2 = r_str.m_string;

    for(; !(*p_str1 - *p_str2) && *p_str1 && *p_str2; p_str1++, p_str2++);

    if(!(*p_str1 - *p_str2))
    {
        return true;
    }

    return false;
}


//String menor a otro
bool miString::operator<(const miString& r_str)
{
    char* p_str1 = m_string;
    char* p_str2 = r_str.m_string;

    for(; !(*p_str1 - *p_str2) && *p_str1 && *p_str2; p_str1++, p_str2++);

    if((*p_str1 - *p_str2) < 0)
    {
        return true;
    }

    return false;
}

//String mayor a otro
bool miString::operator>(const miString& r_str)
{
    char* p_str1 = m_string;
    char* p_str2 = r_str.m_string;

    for(; !(*p_str1 - *p_str2) && *p_str1 && *p_str2; p_str1++, p_str2++);

    if((*p_str1 - *p_str2) > 0)
    {
        return true;
    }

    return false;
}

//Posicionador de char
char& miString::operator[] (int index)
{
    return ((index < m_size) ? m_string[index] : m_string[m_size-2]);
}

/*
//Signo igual
miString& miString::operator= (char c)
{


    return *this;
}
*/