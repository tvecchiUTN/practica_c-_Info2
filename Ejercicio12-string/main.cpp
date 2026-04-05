#include <iostream>
#include "mistring.h"

using namespace std;

int main()
{
    miString str1("Tomas");

    miString str2("Vecchi");

    str1 += ' ';

    miString strNombre(str1 + str2);

    cout << strNombre << endl;

    return 0;
}
