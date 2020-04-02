#include <iostream>
using namespace std;

const int SIZE = 10;

int main ()
{
    int ICQ[SIZE];
    int mobile[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1 << " ICQ number: ";
        cin >> ICQ[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1 << " mobile number: ";
        cin >> mobile[i];
    }

    cout << "Choose one option: \n";
    cout << "1)sort by ICQ number\n";
    cout << "2)sort by phone numbers\n";
}
