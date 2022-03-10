#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "pen.h"
using namespace std;

int main()
{
    Pen p("ExtraSkinZMax", "KirovZavod", "Black", 47.5);
    cout << p;

    Pen p2;
    cin >> p2;
    cout << p2;
}