#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char buffer[100];
    fstream fs;
    fstream fs2;
    fs.open("2.1.txt");
    if (fs.is_open())
    {
        while (!fs.eof())
            {
                fs.getline(buffer, 100);
                //cout << buffer << endl;
                fs2.open("2.2.txt", ios::app);
                if (fs2.is_open())
                {
                    fs2 << buffer << endl;
                }
                fs2.close();
            }
    }
    fs.close();
}
