#include <iostream>
using namespace std;

int main()
{
    int* array;
    int size;
    cout << "Enter size: ";
    cin >> size;

    try
    {
        if (size <= 0)
        {
            throw size;
        }
        array = new int[size];
        cout << "size = " << size << endl;
        delete[] array;
    }
    catch(exception)
    {
        cout << "wrong size of array = " << size << endl;
    }

    
}