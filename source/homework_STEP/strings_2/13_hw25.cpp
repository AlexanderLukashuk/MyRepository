#include <iostream>
using namespace std;

void numToString(char *str, int num)
{
    int size = 0, k = 0;
    int* array = new int[size];
    while (num != 0)
    {
        array[size] = num % 10;
        num /= 10;
        size++;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        switch (array[i])
        {
            case 1:
                str[k] = '1';
                k++;
                break;
            case 2:
                str[k] = '2';
                k++;
                break;
            case 3:
                str[k] = '3';
                k++;
                break;
            case 4:
                str[k] = '4';
                k++;
                break;
            case 5:
                str[k] = '5';
                k++;
                break;
            case 6:
                str[k] = '6';
                k++;
                break;
            case 7:
                str[k] = '7';
                k++;
                break;
            case 8:
                str[k] = '8';
                k++;
                break;
            case 9:
                str[k] = '9';
                k++;
                break;
            case 0:
                str[k] = '0';
                k++;
                break;
        }
    }

    str[k] = '\0';
}

int main()
{
    char str[100];
    int num;

    cout << "Enter number: ";
    cin >> num;

    numToString(str, num);
    cout << str << endl;

    return 0;
}
