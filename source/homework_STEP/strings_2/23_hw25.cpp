#include <iostream>
using namespace std;

int main()
{
    char str[100];
    int countSpace = 0, countLetter = 0;
    int sredDlina;

    cout << "Enter string: " << endl;
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            countSpace++;
        }
        else if (((int)str[i] < 65 && (int)str[i] > 90) || ((int)str[i] < 97 && str[i] > 122))
        {
            countSpace++;
        }
        else if (((int)str[i] >= 65 && (int)str[i] <= 90) || ((int)str[i] >= 97 && (int)str[i] <=122))
        {
            countLetter++;
        }
    }
    countSpace += 1;
    sredDlina = countLetter / countSpace;

    cout << "Sred dlina slova = " << sredDlina << endl;

    return 0;
}
