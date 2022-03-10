#include <iostream>
using namespace std;

class TEST
{
private:
    string name;
    friend ostream &operator<<(ostream &out, const TEST &obj);
public:
    TEST(string name) : name(name) {}
};

ostream &operator<<(ostream &out, const TEST &obj)
{
    out << obj.name << endl;
    return out;
}

void someFunction(TEST *ptr)
{
    if (ptr != nullptr)
    {
        cout << *ptr;
    }
}

int main()
{
    //TEST * ptr = new TEST("Alex");
    auto ptr = make_unique<TEST>("Alex");
    auto ptr2 = make_unique<TEST>("Danil");
    someFunction(ptr.get());
    someFunction(ptr2.get());
    //delete ptr;
}