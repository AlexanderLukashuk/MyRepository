#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count;
    string str1String = "String ";
    count = str1String.size();
    cout << str1String << endl;
    char* strC_style = new char[100];
    cout << "Enter string: ";
    cin.getline(strC_style, 100);

    str1String.append(strC_style);
    str1String += ' ';
    cout << str1String << endl;

    string str2String;
    cout << "Enter string: ";
    getline(cin, str2String);
    str1String += str2String;
    //str1String.append(str2String);
    cout << str1String << endl;

    str1String.erase(count, strlen(strC_style));
    str1String.erase(count, 1);
    cout << str1String << endl;

    for (int i = 0; i < str1String.size(); i++)
    {
        if (str1String[i] == 'a')
        {
            str1String[i] = '!';
        }
    }

    cout << str1String << endl;


}