#include <iostream>
using namespace std;

int strToNum(char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[0] < (char)48 || str[0] > (char)57)
        {
            break;
        }
        else if (str[i] >= (char)48 && str[i] <= (char)57)
        {
            size++;
        }
    }

    for (int i = strlen(str)-1; i >= 0; i--)
    {
        if (str[i] < (char)48 || str[i] > (char)57)
        {
            break;
        }
        else if (str[i] >= (char)48 && str[i] <= (char)57)
        {
            size++;
        }
    }

    int* array = new int[size];
    int num = 0;

    if (str[0] >= (char)48 && str[0] <= (char)57)
    {
        for (int i = 0; i < size; i++)
        {
            switch (str[i])
            {
                case '1':
                    array[i] = 1;
                    break;
                case '2':
                    array[i] = 2;
                    break;
                case '3':
                    array[i] = 3;
                    break;
                case '4':
                    array[i] = 4;
                    break;
                case '5':
                    array[i] = 5;
                    break;
                case '6':
                    array[i] = 6;
                    break;
                case '7':
                    array[i] = 7;
                    break;
                case '8':
                    array[i] = 8;
                    break;
                case '9':
                    array[i] = 9;
                    break;
                case '0':
                    array[i] = 0;
                    break;

            }
        }

    }
    else if (str[strlen(str) - 1] >= (char)48 && str[strlen(str) - 1] <= (char)57)
    {
        for (int i = size - 1, j = strlen(str) - 1; i >= 0; i--, j--)
        {
            switch (str[j])
            {
                case '1':
                    array[i] = 1;
                    break;
                case '2':
                    array[i] = 2;
                    break;
                case '3':
                    array[i] = 3;
                    break;
                case '4':
                    array[i] = 4;
                    break;
                case '5':
                    array[i] = 5;
                    break;
                case '6':
                    array[i] = 6;
                    break;
                case '7':
                    array[i] = 7;
                    break;
                case '8':
                    array[i] = 8;
                    break;
                case '9':
                    array[i] = 9;
                    break;
                case '0':
                    array[i] = 0;
                    break;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        num += array[i];
        num *= 10;
    }
    num /= 10;

    delete[]array;

    return num;
}

int main()
{
    char str[100];

    cout << "Enter string: ";
    cin.getline(str, 100);

    cout << strToNum(str) << endl;

    return 0;
}
