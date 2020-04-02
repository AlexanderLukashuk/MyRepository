#include <iostream>
using namespace std;

class MyString
{
private:
    char* data;
    friend ostream &operator<<(ostream &out, const MyString &obj);
    friend istream &operator>>(istream &in, MyString &obj);

public:
    MyString() : data(nullptr) {}
    MyString(const char *data)
    {
        if (data != nullptr)
        {
            this->data = new char[strlen(data) + 1];
            strcpy(this->data, data);
        }
    }
    MyString(const MyString &obj) {}
    MyString(MyString &&obj) {}
    ~MyString() {}

    int size() {}

    void operator=(const char *str) {}
    void operator=(const MyString &obj) {}
    void operator=(MyString &&obj) {}

    char& operator[](int index) 
    {
        return data[index];
    }

    MyString operator+(const char *str) {}
    MyString operator+(const MyString &obj) {}
    void operator+=(const char *str) {}
    void operator+=(const MyString &obj) {}
};

ostream &operator<<(ostream &out, const MyString &obj)
{
    out << obj.data;
    return out;
}

istream &operator>>(istream &in, MyString &obj)
{
    char *buff = new char[1000];
    cout << "Enter string: ";
    if (obj.data != nullptr)
    {
        delete[] obj.data;
        obj.data = nullptr;
    }
    in.getline(buff, 1000);
    obj.data = new char[strlen(buff) + 1];
    strcpy(obj.data, buff);
    delete[] buff;
    return in;
}

int main()
{
    MyString str1;
    MyString str2("Hello");
    MyString str3;
    cout << str2 << endl;
    cin >> str1;
    cout << str1 << endl;

    /*str1 = "Goodbye";
    cout << str1 << endl;

    str1 = str2;
    cout << str1 << endl;*/

    //str1[0] = "!";

    /*str3 = str1 + str2; // r-value "!elloyHelloy"
    cout << str3 << endl;

    str1 += str2;// str1 = "!elloyHelloy"
    cout << str1 << endl;

    MyString str4("World");
    str4 += "!!!";
    cout << str4 << endl;

    MyString str5;
    cin >> str5;
    cout << str5 << endl;*/

    //== !=
}