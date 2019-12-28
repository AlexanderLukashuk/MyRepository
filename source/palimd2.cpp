#include <iostream>
int main ()
{
    using namespace std;
    int arr_sz;
    bool isPalindrom = true;
    int * array;

    cout << "Enter array size: ";
    cin >> arr_sz;

    array = new int[arr_sz];

    for (int i = 0; i < arr_sz; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> array[i];
    }

    if (array[arr_sz] == isPalindrom && )
        cout << "This number is palindrom" << endl;
    else
        cout << "This number is not palindrom" << endl;

    delete [] array;
    return 0;
}
