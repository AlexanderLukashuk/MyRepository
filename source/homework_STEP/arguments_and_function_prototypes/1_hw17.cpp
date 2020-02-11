#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

void ArraySort(int array[], int size, int argument = 0)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        if (array[i] == 2)
        {
            argument = 1;
        }
        cout << array[i] << " ";
    }
    cout << endl;

    if (argument == 0)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (array[j] < array[j + 1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int array[SIZE];
    ArraySort(array, SIZE);

    return 0;
}
