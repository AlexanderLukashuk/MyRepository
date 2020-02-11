#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int size1 = rand() % 10;
    int size2 = rand() % 10;
    while (size1 == 0)
    {
        size1 = rand() % 10;
    }
    while (size2 == 0)
    {
        size2 = rand() % 10;
    }
    cout << "size1(y axis) = " << size1 << endl;
    cout << "size2(x axis) = " << size2 << endl;
    int array[size1][size2];
    int x;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < size1 / 2; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            x = array[i][j];
            array[i][j] = array[size1 - 1 - i][j];
            array[size1 - 1 - i][j] = x;
        }
    }

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
