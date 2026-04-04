#include <iostream>
#include "mistring.h"

using namespace std;

int main()
{
    miString str1("Tomas");

    miString str2("Vecchi");

    miString str3("Gabriel");

    cout << str1 << endl;

    cout << str2 << endl;

    cout << str3 << endl;
    miString strCpy(str1);

    miString final;

    cout << str1 << endl;

    cout << strCpy << endl;

    strCpy += ' ';

    str1 += ' ';

    cout << strCpy << endl;

    final = str1 + str2; //Fuga de memoria

    cout << final << endl;

    final += ' ';

    cout << final << endl;

    final += str3;

    cout << final << endl;;
    return 0;
}
