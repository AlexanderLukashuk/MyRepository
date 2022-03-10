#include <iostream>
#include <list>
using namespace std;

class TEST
{
public:
    TEST()
    {
        cout << "CTOR" << endl;
    }

    TEST(int num)
    {
        cout << num << endl;
    }

    ~TEST()
    {
        cout << "DESTR" << endl;
    }

    void show()
    {
        cout << "You in object" << endl;
    }
};

template<class T>
T&& Move(T& t)
{
    return static_cast<T&&>(t);
}

//void func(unique_ptr<TEST> p)
void func(TEST* p)
{

}

int main()
{
    auto ptr = make_unique<TEST>();
    //func(move(ptr));
    func(ptr.get());
}