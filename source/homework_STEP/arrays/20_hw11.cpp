#include <iostream>
using namespace std;

const int SIZE = 4;

int main ()
{
    int array[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1 << " number of your IP: ";
        cin >> array[i];
        for (int j = i;;)
        {
            if (array[i] < 0 || array[i] > 255)
            {
                cout << "You entered wrong number of IP" << endl;
                cout << "Please enter number of IP again: ";
                cin >> array[i];
            }
            else
                break;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << ".";
    }
    cout << endl;
    
    return 0;
}
