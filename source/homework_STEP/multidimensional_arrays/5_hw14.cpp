#include <iostream>
using namespace std;

const int SIZE1 = 4;
const int SIZE2 = 10;

int main()
{
    int array[SIZE1][SIZE2];

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            if (i > 0)
            {
                array[i][SIZE2 - 1 - j] = array[i - 1][j] + 10;
                
            }
            else
            {
                array[i][j] = j;
            }
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
