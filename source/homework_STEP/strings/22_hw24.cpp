#include <iostream>
using namespace std;

int main()
{
    char str[100];

    cout << "Enter stirng: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    return 0;
}
