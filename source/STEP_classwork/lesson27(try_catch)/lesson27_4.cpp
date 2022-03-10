#include <iostream>
using namespace std;

class Student
{
private:
    char *name;
    int size;
    char **subjects;

public:
    Student() : name(nullptr), subjects(nullptr), size() {}
    Student(const char *name, int size) : name(nullptr), subjects(nullptr), size()
    {
        try
        {
            if (name == nullptr)
            {
                throw 1;
            }

            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->size = size;
            subjects = new char *[size];
        }
        catch (...)
        {
            delete[] this->name;
            delete[] subjects;
            cout << "Exception" << endl;
        }
    }

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
};

int main()
{
    {
        Student* ptr = new Student("Igor", -100);

        ptr;
        cout << "Program is continue" << endl;
    }

    cout << "Program is continue" << endl;
}