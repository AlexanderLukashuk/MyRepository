#include <iostream>
#include "../include/counter.h"
using namespace std;

// Counter::Counter()
// {
//     count = 0;
//     minValue = 0;
//     maxValue = 100;
// }

Counter::Counter(int min, int max, int c)
{
    minValue = min;
    maxValue = max;
    count = c;
}

void Counter::add()
{
    if (count + 1 <= maxValue)
    {
        count++;
    }
    else
    {
        count = minValue;
    }
}

void Counter::show()
{
    cout << "Min value: " << minValue << endl;
    cout << "Max value: " << maxValue << endl;
    cout << "Counter now = " << count << endl;
}

void menu(int option, Counter obj)
{
    while (option != 3)
    {
        switch (option)
        {
            case 1:
                obj.add();
                break;
            case 2:
                obj.show();
                break;
            case 3:
                cout << "Bye" << endl;
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Try choose again" << endl;
        }

        cout << "Choose option: " << endl;
        cout << "1)Add" << endl;
        cout << "2)Show" << endl;
        cout << "3)Exit" << endl;
        cin >> option;
    }
}