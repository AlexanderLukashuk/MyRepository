#include <iostream>
using namespace std;

class GrandPa
{
public:
    int num;
};

class ParentLeft : virtual public GrandPa
{

};

class ParentRight : virtual public GrandPa
{

};

class Child : public ParentLeft, public ParentRight
{

};

int main()
{
    Child ch;
    ch.ParentLeft::num = 321;
    ch.ParentRight::num = 123;

    cout << ch.ParentLeft::num << " " << ch.ParentRight::num << endl;

}