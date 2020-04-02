#include <iostream>
using namespace std;

struct TEST
{
    char* str = nullptr;
    TEST() {}
    TEST(const TEST& obj)
    {
        cout << "!!!!" << endl;
    }

    TEST(TEST&& obj)
    {
        cout << "????" << endl;
    }

    ~TEST()
    {
        delete[] str;
    }
};

TEST func()
{
    TEST a;
    return a;
}

int main()
{
    TEST t(func());
    /*t.str = new char[10];
    strcpy(t.str, "123456789");
    cout << t.str << endl;

    func(t);
    cout << t.str << endl;*/
    //int num;
    //num = 10;
    //int& ls1 = num; // l-value ssilka
    //int& ls2 = 100; // nel'zya save v l-value ssilku r-value

    //int && rs1 = 5; // r-value ssilka
    //int && rs2 = num; // r-value ssilke nel'zya save v l-value
    
    //10 = num; //nel'zya
    //int num1 = 10;
    //int num2 = 100;
    //int& s = num1;

    //s = num2;
    //cout << num1;

    return 0;
}
