#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<string> str;
    int count = 0;
    char buffer[100];
    fstream fs;
    fstream fs2;
    fs.open("1.1.txt");
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            count++;
            fs.getline(buffer, 100);
            str.push_back(buffer);
        }
    }
    fs.close();

    fs2.open("1.2.txt", ios::app);
    if (fs2.is_open())
    {
        for (int i = count - 1; i >= 0; i--)
        {
            cout << str[i] << endl;
            fs2 << str[i] << endl;
        }
    }
    fs2.close();

    return 0;
}
