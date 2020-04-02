#include <iostream>
using namespace std;

class Student
{
private:
    char name[100];
    int age;
    friend ostream& operator<<(ostream& out, const Student& st);
    friend istream& operator>>(istream& in, Student& st);
public:
    Student(const char* name, int age) : age(age)
    {
        strcpy(this->name, name);
    }

    void setName(const char*)
    {
        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        this->age = age;
    }

    char* getName()
    {
        return name;
    }

};

ostream& operator<<(ostream& out, const Student& st)
{
    out << "Name: " << st.name << endl;
    out << "Age: " << st.age << endl;
    return out;
}

istream& operator>>(istream& in, Student& st)
{
    //char name[100];
    //int age;
    cout << "Enter name: ";
    //cin.getline(name, 100);
    in.getline(st.name, 100);
    //st.setName(name);
    cout << "Enter age: ";
    in >> st.age;
    //cin >> age;
    //cin.get();
    //st.setAge(age);
    return in;
}

int main()
{
    Student st("Alex", 21);

    cin >> st;

    cout << st << endl << endl << st << endl;
}