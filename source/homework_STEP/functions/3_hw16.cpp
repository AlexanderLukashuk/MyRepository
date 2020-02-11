#include <iostream>
using namespace std;

const int SIZE = 14;

int alphanum(char str[], int size)
{
    int num = 0, letter = 0;
    for (int i = 0; i < size; i++)
    {
        if(str[i] >= 48 && str[i] <= 57)
        {
            num = 1;
        }

        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            letter = 1;
        }

    }

        if (num == 1 && letter == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main()
{
    char str_arr[SIZE] = { "frgdfr2rfdtg5" };
    char str_arr1[SIZE] = { "grdfbtdvfsopn" };
    char str_arr2[SIZE] = { "4542348841489" };

    cout << alphanum(str_arr, SIZE) << endl;
    cout << alphanum(str_arr1, SIZE) << endl;
    cout << alphanum(str_arr2, SIZE) << endl;

    return 0;
}
