#ifndef MIVECTOR_CPP
#define MIVECTOR_CPP

#include <iostream>
#include "mivector.h"

////Constructores////

template<class T>
//Constructor por defecto
miVector<T>::miVector()
{
    m_vec = nullptr;
    m_sz = 0;
}

template<class T>
//Constructor parametrizado
miVector<T>::miVector(T* p_dato, int sz)
{
    //Por supuesto verifico que no sea negativo o que apunte a nullptr

    m_sz = sz;

    m_vec = new T[m_sz];

    for(int i = 0; i < m_sz; i++)
    {
        m_vec[i] = p_dato[i];
    }

    //O si no hacer esto
    //memcpy(m_vec, p_dato, sizeof(typedata));

    //O tambien se resuelve mediante punteros a funcion
}

template<class T>
//Constructor de copia
miVector<T>::miVector(const miVector<T>& r_vec)
{
    m_sz = r_vec.m_sz;

    m_vec = new T[m_sz];

    for(int i = 0; i < m_sz; i++)
    {
        m_vec[i] = r_vec.m_vec[i];
    }
}

template<class T>
//Destructor
miVector<T>::~miVector()
{
    delete[] m_vec;
}

////Metodos////

template<class T>
//Longitud del vector
int miVector<T>::length()
{
    return m_sz;
}

template<class T>
//Primera aparicion de un valor
int miVector<T>::posicion(T var)
{
    int i;
    for(i = 0; i < m_sz; i++)
    {
        if(m_vec[i] == var)
        {
            return i;
        }
    }

    return -1;
}

////Operadores sobrecargados////

template<class T>
//Agrega un valor al final
miVector<T>& miVector<T>::operator+= (T val)
{
    T* aux_vec = new T[m_sz + 1];
    //Verifico memoria obvio

    for(int i = 0; i < m_sz; i++)
    {
        aux_vec[i] = m_vec[i];
    }

    aux_vec[m_sz] = val;

    delete[] m_vec;

    m_vec = aux_vec;

    m_sz++;

    return *this;
}


template<class T>
//Concatena vectores
miVector<T>& miVector<T>::operator+= (const miVector<T>& r_vec)
{
    T* auxVec = new T[m_sz + r_vec.m_sz];

    int i;
    for(i = 0; i < m_sz; i++)
    {
        auxVec[i] = m_vec[i];
    }

    for(int j = 0; j < r_vec.m_sz; j++, i++)
    {
        auxVec[i] = r_vec.m_vec[j];
    }

    delete[] m_vec;

    m_vec = auxVec;
    m_sz += r_vec.m_sz;

    return *this;
}

template<class U>
//Flujo de salida
std::ostream& operator<< (std::ostream& r_stdout, const miVector<U>& r_vec)
{
    r_stdout << "(";
    for(int i = 0; i < r_vec.m_sz; i++)
    {
        r_stdout << " " << r_vec.m_vec[i] << " ";
    }

    r_stdout << ")" << std::endl;

    return r_stdout;
}


template<class T>
//Igualacion de vectores
miVector<T>& miVector<T>::operator= (const miVector<T>& r_vec)
{
    T* auxVec = new T[r_vec.m_sz];

    for(int i = 0; i < r_vec.m_sz; i++)
    {
        auxVec[i] = r_vec.m_vec[i];
    }

    delete[] m_vec;

    m_vec = auxVec;
    m_sz = r_vec.m_sz;

    return *this;
}


template<class T>
//Suma de vectores
miVector<T> miVector<T>::operator+ (const miVector<T>& r_vec)
{
    T* auxVec = new T[m_sz + r_vec.m_sz];

    int i;
    for(i = 0; i < m_sz; i++)
    {
        auxVec[i] = m_vec[i];
    }

    for(int j = 0; j < r_vec.m_sz; j++, i++)
    {
        auxVec[i] = r_vec.m_vec[j];
    }

    miVector ret_vec(auxVec, m_sz + r_vec.m_sz);

    delete[] auxVec;

    return ret_vec;
}


template<class T>
//Comparacion de igualad, si todos sus elementos son iguales
bool miVector<T>::operator== (const miVector<T>& r_vec)
{
    if(m_sz != r_vec.m_sz)
    {
        return false;
    }

    //Confirmo que ambas son iguales
    for(int i = 0; i < m_sz; i++)
    {
        if(m_vec[i] != r_vec.m_vec[i])
        {
            return false;
        }
    }

    return true;
}

template<class T>
//Devuelve elemento en posicion pos
T& miVector<T>::operator[] (int pos)
{
    if(m_sz > 0)
    {
        if(pos >= m_sz)
        {
            return m_vec[m_sz-1];
        }
        else if(pos < 0)
        {
            return m_vec[0];
        }
    }

    return m_vec[0];
}

#endif