#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

void min(int* array, int size)
{
    int min = 20, index;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) < min)
        {
            min = *(array + i);
            index = i;
        }
    }
    cout << "min = " << min << endl;
    cout << "index of element = " << index << endl;
    cout << "number of element = " << index + 1 << endl;
}

int main()
{
    srand(time(0));
    int array[SIZE];
    int* parray = array;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 20;
        cout << array[i] << " ";
    }
    cout << endl;

    min(parray, SIZE);

    return 0;
}
