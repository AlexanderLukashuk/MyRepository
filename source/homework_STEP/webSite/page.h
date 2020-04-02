#include <iostream>
#include <string>
using namespace std;

class Page
{
    //public:
    Page* pages;
    string name;
    public:
    void setName(string str)
    {
        name = str;
    }
    string getName()
    {
        return name;
    }
    void print()
    {
        cout << "Hello world" << endl;
    }
};
