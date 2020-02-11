#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main()
{
    srand(time(0));
    int array1[SIZE];
    int array2[SIZE];
    int array[SIZE];

    cout << "array1: \n";
    for (int i = 0; i < SIZE; i++)
    {
        array1[i] = rand() % 10;
        array2[i] = rand() % 10;
        cout << array1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++)
        cout << array2[i] << " ";
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = array1[i] + array2[i];
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
