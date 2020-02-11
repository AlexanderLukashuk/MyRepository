#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

template <typename T>
void func(T array[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i][0] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int array_Int[SIZE][SIZE];
    double array_DB[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array_Int[i][j] = rand() % 10;
            cout << array_Int[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array_DB[i][j] = rand() % 10 - ((j + 1) * 0.3);
            cout << array_DB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    func(array_Int);
    func(array_DB);

    return 0;
}
