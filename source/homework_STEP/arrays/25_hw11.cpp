#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int shear, x;
    char direction;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "enter the number of shear: ";
    cin >> shear;
    cout << "select shear direction: ";
    cout << "\"r\" - right\n";
    cout << "\"l\" - left\n";
    cin >> direction;


    for (int j = 0; j < shear; j++)
    {
        switch (direction)
        {
            case 'r':
                for (int i = SIZE - 1; i > 0; i--)
                {
                    x = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = x;
                }
                break;
            case 'l':
                for (int i = 0; i < SIZE - 1; i++)
                {
                    x = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = x;
                }
                break;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
