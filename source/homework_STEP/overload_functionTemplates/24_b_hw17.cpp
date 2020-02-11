#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

template <typename T>
T func(T array[])
{
    for (int i = 0; i < SIZE / 2; i++)
    {
        T temp = array[i];
        array[i] = array[SIZE - i - 1];
        array[SIZE - i - 1] = temp;
    }

    return array[SIZE];
}

int main()
{
    srand(time(0));
    int array1[SIZE];
    double array2[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array1[i] = rand() % 10;
        cout << array1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        array2[i] = rand() % 10 + (i * 0.3);
        cout << array2[i] << " ";
    }
    cout << endl;

    func(array1);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;

    func(array2);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

    return 0;
}
