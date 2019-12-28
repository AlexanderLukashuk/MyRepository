#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int x;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE / 2; i++)
    {
        x = array[i];
        array[i] = array[SIZE - 1 - i];
        array[SIZE - 1 -i] = x;
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
