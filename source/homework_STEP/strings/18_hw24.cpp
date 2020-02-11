#include <iostream>
using namespace std;

int main()
{
    char* str = new char[100];
    int count = 0, size = strlen(str);

    cout << "Enter string: ";
    cin.getline(str, 100);

    for (int i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'o')
        {
            str[j] = str[i];
            j++;
        }

        if (str[i] == 'o')
        {
            count++;
        }
    }

    size = strlen(str) - count;
    str[size] = '\0';
    cout << str << endl;

    delete[]str;

    return 0;
}
