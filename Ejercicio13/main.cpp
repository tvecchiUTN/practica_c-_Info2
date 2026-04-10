#include <iostream>
#include "mivector.h"

using namespace std;

int main()
{
    int testing[] = {3, 4, 2, 1, 9};

    miVector<int> vecTest(testing, 5);

    vecTest += 2;

    cout << "El numero 1 esta en la posicion: " << vecTest.posicion(1) << endl;

    return 0;
}
