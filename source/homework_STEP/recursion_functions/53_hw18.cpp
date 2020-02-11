#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 3;
const int SIZE2 = 4;

void func(int array[][SIZE2], int s)
{
    if (s == 1)
    {
        for (int i = 0; i < SIZE1; i++)
        {
            for (int j = SIZE2 - 1; j > 0; j--)
            {
                int temp = array[i][j];
                array[i][j] = array[i][j - 1];
                array[i][j - 1] = temp;
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
    }
    else if (s > 1)
    {
        for (int i = 0; i < SIZE1; i++)
        {
            for (int j = SIZE2 - 1; j > 0; j--)
            {
                int temp = array[i][j];
                array[i][j] = array[i][j - 1];
                array[i][j - 1] = temp;
            }
        }


        /*for (int i = 0; i < SIZE1; i++)
        {
            for (int j = 0; j < SIZE2; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }*/
        func(array, s - 1);
    }
    /*while (s != 0)
    {
        for (int i = 0; i < SIZE1; i++)
        {
            for (int j = SIZE2 - 1; j > 0; j--)
            {
                int temp = array[i][j];
                array[i][j] = array[i][j - 1];
                array[i][j - 1] = temp;
            }
        }
        s--;
    }
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }*/
}

int main()
{
    srand(time(0));
    int array[SIZE1][SIZE2];
    int shift;

    cout << "Enter the number of shifts: ";
    cin >> shift;

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

    func(array, shift);

    return 0;
}
