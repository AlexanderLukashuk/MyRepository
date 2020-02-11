#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

template <typename T, typename I>
T func(T array[], I size)
{
    T sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }

    sum /= size;

    return sum;
}

int main()
{
    srand(time(0));
    int array_Int[SIZE];
    double array_DB[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array_Int[i] = rand() % 10;
        cout << array_Int[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        array_DB[i] = rand() % 10 - (i * 0.3);
        cout << array_DB[i] << " ";
    }
    cout << endl;

    cout << func(array_Int, SIZE) << endl;
    cout << func(array_DB, SIZE) << endl;

    return 0;
}
