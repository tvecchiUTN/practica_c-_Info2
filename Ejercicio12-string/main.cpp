#include <iostream>
#include "mistring.h"

using namespace std;

int main()
{
    miString str1("AB");

    miString str2("ABC");

    miString str3("AB");

    miString str4("ABA");

    miString str5("ABZ");

    miString str6("ABJ");

    cout << (str1 == str2);

    return 0;
}
