#include <iostream>
using namespace std;

class StudentException : public exception
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

    virtual char const* what() const
    {
        return message.c_str();
    }
};

class Student
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
        catch (StudentException& ex)
        {
            cout << ex.what() << endl;
        }
    }
};

int main()
{
    //exception ex;
    int size = 2000000000;
    try
    {
        //int * array = new int[size];
        //length_error;
        throw runtime_error("Bad things");
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }
}