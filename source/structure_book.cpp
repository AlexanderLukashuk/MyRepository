#include <iostream>
#include <string>
using namespace std;
struct SBook
{
    SBook *inside;
    int pages;
    string name;
    string author;
};
int main ()
{
     
    SBook favorite[2];
    favorite[0].name = "War and peace";
    favorite[0].pages = 1200;
    favorite[0].author = "L. N. Tolstoi";

    favorite[1].name = "Hero of out time";
    favorite[1].pages = 268;
    favorite[1].author = "N. V. Lermontov";

    for (int i = 0; i < 2; i++)
    {
        cout << "Name: " << favorite[i].name << endl;
        cout << favorite[i].pages << endl;
        cout << favorite[i].author << endl;
    }


    return 0;
}
