#include <iostream>
using namespace std;

class MyString
{
private:
    char *data;
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
    MyString(const MyString &obj) : data(nullptr)
    {
        if (obj.data != nullptr)
        {
            this->data = new char[strlen(obj.data) + 1];
            strcpy(this->data, obj.data);
        }
    }

    MyString(MyString &&obj)
    {
        if (obj.data != nullptr)
        {
            this->data = obj.data;
            obj.data = nullptr;
        }
    }

    ~MyString()
    {
        if (this->data != nullptr)
        {
            delete[]data;
        }
    }

    int size()
    {
        if (data != nullptr)
        {
            int size = strlen(data);
            return size;
        }

        return 0;
    }

    void operator=(const char *str)
    {
        if (str != nullptr)
        {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
    }

    MyString operator=(const MyString &obj)
    {
        if (obj.data != nullptr)
        {
            this->data = new char[strlen(obj.data) + 1];
            strcpy(this->data, obj.data);
            return *this;
        }
    }

    MyString operator=(MyString &&obj)
    {
        if (obj.data != nullptr)
        {
            //delete data;
            data = nullptr;
            this->data = new char[strlen(obj.data) + 1];
            strcpy(this->data, obj.data);
            delete obj.data;
            obj.data = nullptr;
            cout << "str3 op =" << endl;

            return *this;
        }
    }

    char &operator[](int index)
    {
        return data[index];
    }

    MyString operator+(const char *str)
    {
        MyString result;

        int size = strlen(this->data) + strlen(str) + 1;
        char *tmp = new char[size];
        strcpy(tmp, this->data);
        strcat(tmp, str);
        //strcat(tmp, '\0');

        result = tmp;
        return result;
    }

    MyString operator+(const MyString &obj)
    {
        if (obj.data != nullptr)
        {
            *this = *this + obj.data;
            return *this;
        }
    }

    void operator+=(const char *str)
    {
        if (str != nullptr)
        {
            //char* tmp = new char;
            //this->data = new char[strlen(str) + 1];
            strcat(this->data, str);
        }
    }
    void operator+=(const MyString &obj)
    {
        if (obj.data != nullptr)
        {
            strcat(this->data, obj.data);
        }
    }
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
    MyString str3(" World");
    cout << str2 << endl;
    cin >> str1;
    cout << str1 << endl;

    str1 = "Goodbye";
    cout << str1 << endl;

    str1 = str2;
    cout << str1 << endl;
    cout << str2 << endl;

    str1[0] = '!';
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    str3 = str1 + str2; // r-value "!elloyHelloy"
    cout << str3 << endl;

    str1 += str2;// str1 = "!elloyHelloy"
    cout << str1 << endl;

    MyString str4("World");
    str4 += "!!!";
    cout << str4 << endl;

    MyString str5;
    cin >> str5;
    cout << str5 << endl;
}