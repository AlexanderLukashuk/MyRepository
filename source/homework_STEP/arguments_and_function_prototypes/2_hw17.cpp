#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

void sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size / 2 - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = size / 2; i < size; i++)
    {
        for (int j = size / 2; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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
    sort(array, SIZE);

    return 0;
}
