#include <iostream>
#include "../include/counter.h"
using namespace std;

int main()
{
    int min, max, _count;

    cout << "Enter max value: ";
    cin >> max;
    cout << "Enter min value: ";
    cin >> min;
    cout << "Enter counter: ";
    cin >> _count;
    
    Counter counter(min, max, _count);
    int num;

    cout << "Choose option: " << endl;
    cout << "1)Add" << endl;
    cout << "2)Show" << endl;
    cout << "3)Exit" << endl;
    cin >> num;

    menu(num, counter);

    return 0;
}