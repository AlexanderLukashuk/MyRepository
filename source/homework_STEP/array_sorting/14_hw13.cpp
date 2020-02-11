#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 5;
const int SIZE2 = 10;

int main ()
{
    srand(time(0));
    int array1[SIZE1];
    int array2[SIZE1];
    int array[SIZE2];

    for (int i = 0; i < SIZE1; i++)
    {
        array1[i] = rand() % 10 - 1;
        array2[i] = rand() % 10 - 1;
    }

    for (int i = 0; i < SIZE1; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE1; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

    for (int i = 0, j = SIZE1; i < SIZE1 && j < SIZE2; i++, j++)
    {
        array[i] = array1[i];
        array[j] = array2[i];
    }

    for (int i = 0; i < SIZE2; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
