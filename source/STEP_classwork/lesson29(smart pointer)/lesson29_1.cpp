#include <iostream>
#include <string>
using namespace std;
//using std::cout;
//using std::endl;
//using std::move;
//using std::string;

// семантика перемещения

class TEST
{
private:
    int size;
public:
    int* array;
    TEST() 
    {
        size = 10;
        array = new int[10];
    }

    TEST(const TEST& obj)
    {
        size = obj.size;

        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = obj.array[i];
        }
    }

    TEST(TEST&& obj)
    {
        size = obj.size;

        array = obj.array;
        obj.array = nullptr;
    }
};

int main()
{

    TEST t;
    cout << t.array << endl;

    TEST t2 = std::move(t);
    cout << t2.array << endl;

    if (t.array == nullptr)
    {
        cout << "t.array = nullptr" << endl;
    }

    TEST t3 = t2;
    cout << "t3.array = " << t3.array << endl;
    cout << "t2.array = " << t2.array << endl;

    /*string str1("First");
    string str2("Second");
    int num1 = 1;
    int num2 = 2;

    string tmp(std::move(str1));
    //cout << tmp << endl;
    cout << str1 << endl;*/
    //str1 = std::move(str2);
    //str2 = std::move(tmp);

    //int tmpInt = std::move(num1);
    //num1 = std::move(num2);
    //num2 = std::move(tmpInt);

    //cout << num1 << " " << num2 << endl;
}