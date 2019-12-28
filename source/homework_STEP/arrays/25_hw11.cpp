#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int shift, x;
    char side;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "enter the number of shifts: ";
    cin >> shift;
    cout << "selec side of shifts: ";
    cout << "\"r\" - right\n";
    cout << "\"l\" - left\n";
    cin >> side;

    if (side == 'l')
    {
        for (int i = 0; i < shift; i++)
        {
            x = array[i];
            array[i] = array[SIZE - 1 - i];
            array[SIZE - 1 - i] = x;
        }
    }
    else if (side == 'r')
    {

    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
