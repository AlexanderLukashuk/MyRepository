#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 5;
const int SIZE2 = 10;

int main()
{
    srand(time(0));
    int array1[SIZE1][SIZE2];
    int array2[SIZE1][SIZE1];

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            array1[i][j] = rand() % 50;
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 2, n = 0; j <= SIZE1 * 2; j += 2, n++)
        {
            array2[i][n] = array1[i][j - 2] + array1[i][j - 1];
        }
    }

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
