#include <iostream>
using namespace std;

void upLetters(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((int)str[i] >= 97 && (int)str[i] <= 122)
        {
            int temp = (int)str[i];
            temp -= 32;
            str[i] = (char)temp;
        }
    }
}

int main()
{
    char str[100];

    cout << "Enter string: ";
    cin.getline(str, 100);

    upLetters(str);
    cout << str << endl;

    return 0;
}
