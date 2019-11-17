#include <iostream>
int main ()
{
    using namespace std;
    int mas_sz;

    cout << "Enter massive size: ";
    cin >> mas_sz;

    int * array = new int[mas_sz];

    for (int i = 0; i < mas_sz; i++)
    {
        array[i] = rand();
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    for (int k = 0; k < mas_sz/2; k++)
    {
        swap(array[0 + k], array[mas_sz - 1 - k]);
    }

    for (int j = 0; j < mas_sz; j++)
    {
        cout << "array[" << j << "] = " << array[j] << endl;
    }

    delete [] array;
    return 0;
}
