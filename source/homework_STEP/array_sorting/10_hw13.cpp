#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int x;

    for (int i = 0; i < SIZE; i ++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
        {
            x = array[j - 1];
            array[j - 1] = array[j];
            array[j] = x;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
