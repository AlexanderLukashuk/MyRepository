#include <iostream>
using namespace std;

void delSpace(char*& str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            count++;
        }
    }

    char* newStr = new char[count];

    for (int i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            newStr[j] = str[i];
            j++;
        }
    }
    count += 1;
    newStr[count - 1] = '\0';

    delete[]str;
    str = newStr;
}

int main()
{
    int k = 0;
    char* str1 = new char[100];
    char* str2 = new char[100];
    char* str3 = new char[k];
    bool check = true;

    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    delSpace(str1);
    delSpace(str2);
    cout << str1 << endl;
    cout << str2 << endl;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                check = false;
            }
        }

        if (check)
        {
            str3[k] = str1[i];
            k++;
        }
        check = true;
    }
    k += 1;
    str3[k - 1] = '\0';

    cout << str3 << endl;
    
    delete[]str1;
    delete[]str2;
    delete[]str3;

    return 0;
}
