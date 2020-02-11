#include <iostream>
#include <time.h>
using namespace std;


void showArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int* func(int* arr, int& size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                int temp1 = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp1;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                int temp1 = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp1;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == 0)
        {
            count++;
        }
    }
    size -= count;
    
    return arr;
}

int main()
{
    srand(time(0));
    int size = 20;
    int array[size];
    int* parray = array;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 8;
    }
    showArray(array, size);
    func(parray, size);
    showArray(array, size);

    return 0;
}
