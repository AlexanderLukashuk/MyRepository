#include <iostream>
using namespace std;

class StudentException
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

    string& get()
    {
        return message;
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
            cout << ex.get() << endl;
        }
    }
};

int main()
{
    Student st;
    st[1];

    cout << "Program is continue" << endl;
}