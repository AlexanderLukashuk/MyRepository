#include <iostream>
#include <sstream>
using namespace std;

class TEST
{
private:
    //int number;
    int* mas;
    int size;
public:
    TEST()
    {
        size = 10;
        mas = new int[size];
        for (int i = 0; i < size; i++)
        {
            mas[i] = rand() % 100;
        }
    }

    ~TEST() 
    {
        if (mas != nullptr)
        {
            delete[]mas;
        }
    }
    // TEST() : number(0) {}

    // TEST& operator++()
    // {
    //     //cout << "prefix" << endl;
    //     number++;
    //     return *this;
    // }

    // TEST operator++(int)
    // {
    //     TEST res = *this;
    //     number++;
    //     return res;
    //     // cout << "postfix" << endl;
    //     // number++;
    //     // return *this;
    // }

    // TEST& operator--()
    // {
    //     number--;
    //     return *this;
    // }

    // TEST operator--(int)
    // {
    //     TEST res = *this;
    //     number--;
    //     return res;
    // }

    // string toString() const
    // {
    //     stringstream ss;
    //     ss << number << endl;
    //     return ss.str();
    // }

    // void operator()()
    // {
    //     cout << "() Without parametrs" << endl;
    // }

    // void operator()(int num)
    // {
    //     cout << "() With one int parametrs: " << num << endl;
    // }

    // void operator()(int num1, int num2, int num3)
    // {
    //     cout << "() With tree int parametrs: " << num1 + num2 + num3 << endl;

    // }

    // void operator()(const char* str, int number, double dnumber)
    // {
    //     cout << "With different parametres" << endl;
    // }

    // int operator[](int index)
    // {
    //     return mas[index];
    // }

    int& operator[](int index)
    {
        return mas[index];
    }

    string toString() const
    {
        stringstream ss;
        for (int i = 0; i < size; i++)
        {
            ss << mas[i] << endl;
        }

        return ss.str();
    }
};

int main()
{
    TEST test;

    cout << test.toString();
    //cout << test[5] << endl;
    test[5] = 99999;
    cout << test.toString();
    // TEST test;
    // test();
    // test(1);
    // test(1, 2, 3);
    // test("123", 1, 4.5);
    // TEST t1, t2, t3;
    // t2 = ++t1;
    //t3 = t1++;
    // cout << t2.toString();
    //cout << t3.toString();
}