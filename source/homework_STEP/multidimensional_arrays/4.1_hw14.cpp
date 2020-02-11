#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 10;
const int SIZE2 = 5;

int main()
{
    int array[SIZE1][SIZE2];
    int x;

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < SIZE1 / 2; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            x = array[i][j];
            array[i][j] = array[SIZE1 - 1 - i][j];
            array[SIZE1 - 1 - i][j] = x;
        }
    }

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
