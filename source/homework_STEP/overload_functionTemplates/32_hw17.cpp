#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int func(int array[], int size)
{
    int sum1 = 0;
    for (int i = 0; i < size; i++)
    {
        sum1 += array[i];
    }
    sum1 /= size;

    return sum1;
}

double func(double array[], int size)
{
    double sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        sum2 += array[i];
    }
    sum2 /= size;

    return sum2;
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
        array_DB[i] = rand() % 10 + (i * 0.3);
        cout << array_DB[i] << " ";
    }
    cout << endl;

    cout << "sum1 = " << func(array_Int, SIZE) << endl;
    cout << "sum2 = " << func(array_DB, SIZE) << endl;

    return 0;
}
