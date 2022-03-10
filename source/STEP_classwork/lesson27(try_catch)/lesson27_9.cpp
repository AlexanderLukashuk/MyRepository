#include <iostream>
using namespace std;

/*class StudentException : public exception
{
private:
    string message;

public:
    StudentException(string message) : message(message) {}
    /*StudentException(string message, int n): message(message)
    {
        char* buff = new char[10];
        itoa(n, buff, 10);

    }*/

/*virtual const char* what() const
    {
        char const* str = new char[message.length() + 1];
        strcpy(const_cast<char*>(str), message.c_str());
        return str;
    }*/

/*virtual char const *what() const
    {
        return message.c_str();
    }*/
//};

/*class Student
{
private:
    char *name;
    int size;
    char **subjects;

public:
    Student() : name(nullptr), subjects(nullptr), size() {}
    Student(const char *name, int size) : name(nullptr), subjects(nullptr), size() {}

    ~Student()
    {
        cout << "DESTR" << endl;
        delete[] name;
        for (int i = 0; i < size; i++)
        {
            delete[] subjects[i];
        }
        delete[] subjects;
    }

    int &operator[](int index)
    {
        try
        {
            throw StudentException("Invalid index");
        }
        catch (StudentException &ex)
        {
            cout << ex.what() << endl;
        }
    }
};*/

class Parent
{
public:
    Parent()
    {
        throw 1;
    }

    virtual ~Parent()
    {
        cout << "DESTR Parent\n";
    }

    virtual void show() const
    {
        cout << "Parent\n";
    }
};

class Child : public Parent
{
public:
    Child()
    try : Parent()
    {
    }
    catch (...)
    {
        cout << "Exeption" << endl;
    }

    ~Child()
    {
        cout << "DESTR Child\n" ;
    }

    virtual void show() const override
    {
        cout << "Child\n";
    }
};

int main()
{
    try
    {
        Child c;
    }
    catch (...)
    {
        cout << "!!!!!!!" << endl;
    }
}