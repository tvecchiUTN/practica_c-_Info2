#ifndef MIVECTOR_H
#define MIVECTOR_H

template<class T>
class miVector
{
private:
    T* m_vec;
    int m_sz;

public:
    ////Constructores y destructores////

    //Constructor por defecto
    miVector();

    //Constructor parametrizado
    miVector(T* p_dato, int sz);

    //Constructor de copia
    miVector(const miVector<T>& r_vec);

    //Destructor
    ~miVector();

    ////Metodos////

    //Longitud del vector
    int length();

    //Primera aparicion de un valor
    int posicion(T val);

    ////Operadores sobrecargados////

    //Agrega un valor al final
    miVector<T>& operator+= (T val);

    /*
    //Concatena vectores
    miVector<T>& operator+= (const miVector<T>& r_vec);

    //Igualacion de vectores
    miVector<T>& operator= (const miVector<T>& r_vec);

    //Suma de vectores
    miVector<T> operator+ (const miVector<T>& r_vec);

    //Comparacion de igualad, si todos sus elementos son iguales
    bool operator== (const miVector& r_vec);

    //Devuelve elemento en posicion pos
    T& operator[] (int pos);
    */
};

#include "mivector.cpp"

#endif // MIVECTOR_H
