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

int func(int* arr, int& size)
{
    int count1 = 0, count2 = 0;;
    for (int i = 0; i < size; i ++)
    {
        for (int j = 2; j <= *(arr + i); j++)
        {
            if (*(arr + i) % j == 0)
            {
                count1++;
            }
        }
        
        if (count1 == 1)
        {
            for (int k = i; k < size - 1; k++)
            {
                int temp = *(arr + k);
                *(arr + k) = *(arr + k + 1);
                *(arr + k + 1) = temp;
            }
        }
        count1 = 0;
    }
    for (int i = 0; i < size; i ++)
    {
        for (int j = 2; j <= *(arr + i); j++)
        {
            if (*(arr + i) % j == 0)
            {
                count1++;
            }
        }
        
        if (count1 == 1)
        {
            for (int k = i; k < size - 1; k++)
            {
                int temp = *(arr + k);
                *(arr + k) = *(arr + k + 1);
                *(arr + k + 1) = temp;
            }
        }
        count1 = 0;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 2; j <= *(arr + i); j++)
        {
            if (*(arr + i) % j == 0)
            {
                count1++;
            }
        }

        if (count1 == 1)
        {
            count2++;
        }
        count1 = 0;
    }
    size -= count2;

    return *arr;
}

int main()
{
    srand(time(0));
    int size = 10;
    int* array = new int[size];
    int* parray = array;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 20;
    }

    showArray(array, size);
    func(parray, size);
    showArray(array, size);

    delete[]array;

    return 0;
}
