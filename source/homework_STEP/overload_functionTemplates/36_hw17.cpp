#include <iostream>
#include <time.h>
using namespace std;

const int ROW = 10;
const int COL = 10;

void func(int array[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        cout << array[i][0] << " ";
    }
    cout << endl;
}

void func(double array[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        cout << array[i][0] << " ";
    }
    cout << endl;
}

int main ()
{
    srand(time(0));
    int array_Int[ROW][COL];
    double array_DB[ROW][COL];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            array_Int[i][j] = rand() % 10;
            cout << array_Int[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            array_DB[i][j] = rand() % 10 + (i * 0.3);
            cout << array_DB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    func(array_Int);
    func(array_DB);

    return 0;
}
