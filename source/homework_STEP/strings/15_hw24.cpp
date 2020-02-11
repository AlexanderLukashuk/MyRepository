#include <iostream>
using namespace std;

void palindrome(char str[])
{
    int size = strlen(str);
    bool check = true;
    int count = 0;

    for (int i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }

        if (str[i] == ' ')
        {
            count++;
        }
    }

    size -= count;
    str[size] = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((int)str[i] >= 65 && (int)str[i] <= 90)
        {
            int temp = (int)str[i];
            temp += 32;
            str[i] = (char)temp;
        }

        if ((int)str[i] >= 128 && (int)str[i] <= 159)
        {
            int temp = (int)str[i];
            temp += 32;
            str[i] = (char)temp;
        }
    }
    cout << str << endl;

    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - i - 1])
        {
            check = false;
        }
    }

    if (check)
    {
        cout << "This word is palindrome" << endl;
    }
    else
    {
        cout << "This word is not palindrome" << endl;
    }
}

int main()
{
    char str[100];

    cout << "Enter string: ";
    cin.getline(str, 100);

    palindrome(str);
    cout << str << endl;

    return 0;
}
