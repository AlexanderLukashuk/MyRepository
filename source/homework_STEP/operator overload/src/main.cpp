#include <iostream>
#include "../include/decimal.hpp"
#include "decimal.cpp"
using namespace std;

int main()
{
    Decimal dr1(0, 3, 4);

    Decimal dr2(-1, 2, 4);
    Decimal dr3;
    dr3 = dr1 - dr2;
    cout << dr3.toString();
    dr1 != 3;
    cout << dr1.toString();
    Decimal dr(0, 3, 4);
    Decimal dr6;
    dr6 = dr + 2;
    cout << dr6.toString();

    Decimal dr7;
    dr7 = dr + dr1;
    cout << dr7.toString();

    Decimal dr8(0, 2, 4);
    dr8 += dr;
    cout << dr8.toString();
    dr8 += 2;
    cout << dr8.toString();

    Decimal dr4(0, 2, 7);
    cout << !dr4 << endl;
}