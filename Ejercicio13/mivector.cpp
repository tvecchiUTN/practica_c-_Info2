#ifndef MIVECTOR_CPP
#define MIVECTOR_CPP

//#include <iostream>
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

/*
template<class typedata>
//Concatena vectores
miVector<typedata>& miVector<typedata>::operator+= (const miVector& r_vec)
{

}

template<class typedata>
//Igualacion de vectores
miVector<typedata>& miVector<typedata>::operator= (const miVector& r_vec)
{

}

template<class typedata>
//Suma de vectores
miVector<typedata> miVector<typedata>::operator+ (const miVector& r_vec)
{

}

template<class typedata>
//Comparacion de igualad, si todos sus elementos son iguales
bool miVector<typedata>::operator== (const miVector& r_vec)
{

}

template<class typedata>
//Devuelve elemento en posicion pos
typedata& miVector<typedata>::operator[] (int pos)
{

}
*/

#endif