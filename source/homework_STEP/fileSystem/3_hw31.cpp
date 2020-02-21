#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char tmp[100];
    fstream fs;
    fstream fs2;
    fs.open("3.1.txt");
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            fs >> tmp;
            if (strlen(tmp) >= 7)
            {
                fs2.open("3.2.txt", ios::app);
                if (fs2.is_open())
                {
                    fs2 << tmp << " ";
                }
                fs2.close();
            }
        }
    }
    fs.close();

    return 0;
}
