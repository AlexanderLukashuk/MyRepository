#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;
const int SIZE1 = 5;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int array1[SIZE1];

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;
    
    for (int i = 0, j = 0; i < SIZE1; i++, j++)
    {
        array1[j] = array[i] + array[SIZE - 1 - i];
        cout << array1[j] << " ";
    }
    cout << endl;

    return 0;
}
