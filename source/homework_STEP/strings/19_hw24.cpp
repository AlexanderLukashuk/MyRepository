#include <iostream>
using namespace std;

void swap(char str[])
{
    int size = strlen(str);
    cout << size << endl;
    for (int i = 0; i < size / 2; i++)
    {
        char temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

int main()
{
    char str[100];

    cout << "Enter stirng: ";
    cin.getline(str, 100);

    swap(str);
    cout << str << endl;

    return 0;
}
