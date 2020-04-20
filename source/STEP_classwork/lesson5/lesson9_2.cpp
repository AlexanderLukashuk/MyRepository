#include <iostream>
using namespace std;

class TEST
{
    private:
        char* str;
        int number;
    public:
        TEST() : str(nullptr), number(0) {}
        // {
        //     str = nullptr;
        // }
        TEST(const char* str) : number(0)
        {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        }
        //конструктор копирования
        TEST(const TEST & obj)
        {
            //this->str = nullptr;
            cout << "Ctor Copy" << endl;
            if (obj.str != nullptr)
            {
                this->str = new char[strlen(obj.str) + 1];
                strcpy(this->str, obj.str);

            }
            this->number = obj.number;
        }

        ~TEST()
        {
            delete[]str;
        }

        void show() const
        {
            cout << (int*)str <<  " " << str <<endl;
        }

};

void func(TEST& t) 
{
    t.show();
}

int main()
{
    TEST test("Hello");

    test.show();
    func(test);
    test.show();

}