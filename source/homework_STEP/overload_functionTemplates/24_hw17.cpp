#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int func(int array[])
{
    for (int i = 0; i < SIZE / 2; i++)
    {
        int temp = array[i];
        array[i] = array[SIZE - i - 1];
        array[SIZE - i - 1] = temp;
    }

    return array[SIZE];
}

double func(double array[])
{
    for (int i = 0; i < SIZE / 2; i++)
    {
        double temp = array[i];
        array[i] = array[SIZE - i - 1];
        array[SIZE - i - 1] = temp;
    }

    return array[SIZE];
}

int main()
{
    srand(time(0));
    int array_I[SIZE];
    double array_DB[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array_I[i] = rand() % 10;
        cout << array_I[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        array_DB[i] = (rand() % 10) + (i * 0.3);
        cout << array_DB[i] << " ";
    }
    cout << endl;

    func(array_I);

    for (int i = 0; i < SIZE; i++)
    {
        cout << array_I[i] << " ";
    }
    cout << endl;

    func(array_DB);

    for (int i = 0; i < SIZE; i++)
    {
        cout << array_DB[i] << " ";
    }
    cout << endl;

    return 0;
}
