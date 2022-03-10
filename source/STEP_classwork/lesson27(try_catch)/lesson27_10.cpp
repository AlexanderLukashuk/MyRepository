#include <iostream>
using namespace std;

int main()
{
    int* array = nullptr;
    try
    {
        array = new int[100];

        throw 1;
        delete[] array;
    }
    catch(...)
    {
        delete[] array;
        cout << "Exception" << endl;
    }
}