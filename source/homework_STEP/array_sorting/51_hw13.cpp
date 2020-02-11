#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 5;
const int SIZE2 = 5;

int main()
{
    srand(time(0));
    int array[SIZE1][SIZE2];
    int sum = 0;

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1, j = 1; i <= SIZE1 && j <= SIZE2; i++, j++)
    {
            sum += array[i - 1][j - 1];
    }
    for (int i = 1, j = SIZE2; i <= SIZE1 && j > 0; i++, j--)
    {
            sum += array[i - 1][j - 1];
    }
    sum -= array[2][2];
    cout << "the amount = " << sum << endl;

    return 0;
}
