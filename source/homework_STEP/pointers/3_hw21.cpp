#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 20;

void initArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 20;
    }
}

void showArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void func(int* parray, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (*(parray + i) % 4 == 0)
        {
            *(parray + i) = 999;
        }
    }
}

int main()
{
    srand(time(0));
    int array[SIZE];
    int* parray = array;

    initArray(array);
    showArray(array);
    func(parray, SIZE);
    showArray(array);

    return 0;
}
