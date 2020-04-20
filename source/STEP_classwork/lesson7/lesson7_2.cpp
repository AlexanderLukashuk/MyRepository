#include <iostream>
using namespace std;

class TEST
{
    public:
        TEST() {}
        TEST(const TEST& obj)
        {
            cout << "CTOR COPY\n";
        }
};

class TEST2
{
    private:
        int* mas;
    public:
        TEST2() 
        {
            mas = new int[5]{1, 2, 3, 4, 5 };
        }

        TEST2(const TEST2& obj)
        {
            if (obj.mas != nullptr)
            {
                mas = new int[5];
                for (int i = 0; i < 5; i++)
                {
                    mas[i] = obj.mas[i];
                }
            }
        }
};

void func1(const TEST& obj)
{
    cout << &obj << endl;
}

void func2(TEST obj) 
{
    cout << &obj << endl;
}

TEST2& func(TEST2& A)
{
    return A;
}

int main()
{
    TEST obj;
    cout << &obj << endl;
    func2(obj);
    //-----------

    // TEST obj2;
    // obj2 = func();
    TEST2 a;
    TEST2 obj2(func(a));
}