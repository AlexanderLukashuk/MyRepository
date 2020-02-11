#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 20;

void sort(int array[], int size)
{
    int start, end;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            start = i;
            break;
        }
    }

    for (int i = size - 1; i > 0; i--)
    {
        if(array[i] < 0)
        {
            end = i;
            break;
        }
    }

    for (int i = start + 1; i < end; i++)
    {
        for (int j = start + 1; j < end - 1; j++)
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

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (-20) + rand() % 40;
        cout << array[i] << " ";
    }
    cout << endl;

    sort(array, SIZE);

    return 0;
}
