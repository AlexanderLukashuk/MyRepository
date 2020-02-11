#include <iostream>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    int count = 0, size, k = 0;

    cin.getline(str1, 100);
    cin.getline(str2, 100);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str2[j] == str1[i])
            {
                count += 2;
            }
        }
    }

    //for (int i = 0; str2[i] != '\0'; i++)
    //{
    //    for (int j = 0; str1[j] != '\0'; j++)
    //    {
    //        if (str1[j] == str2[i])
    //        {
    //            count++;
    //        }
    //    }
    //}

    size = count;
    char* str3 = new char[size];

    for (int i = 0; str1[i] != '\0'; i++)
    {
        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str2[j] == str1[i])
            {
                str3[k] = str1[i];
                k++;
            }
        }
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        for (int j = 0; str1[j] != '\0'; j++)
        {
            if (str1[j] == str2[i])
            {
                str3[k] = str2[i];
                k++;
            }
        }
    }

    cout << size << endl;
    cout << str3 << endl;

    return 0;
}
