#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;
    friend ostream& operator<<(ostream& out, const Student& st);
    friend istream& operator>>(istream& in, Student& st);

public:
    Student() : age() {}
    Student(const string &name, const int age) : name(name), age()
    {
        //setAge(age);
        if (age < 0)
        {
            throw "Age is negative\n";
        }
        this->age = age;
    }
    //Student(const Student &st) {}
    //Student(Student &&st) {}
    //void show(int num)
    void show()
    {
        //cout << this << endl;
        //cout << &num << endl;
        //reinterpret_cast<int*>(&show);
    }

    void setAge(const int age)
    {
        if (age < 0)
        {
            throw "Age is negative\n";
        }
        else
        {
            this->age = age;
        }
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    int getAge() const
    {
        return age;
    }

    const string &getName() const
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
    int tmp;
    cout << "Enter name: ";
    getline(in, st.name);

    cout << "Enter age: ";
    in >> tmp;
    st.setAge(tmp);
    in.get();

    return in;
}

void func(const Student &stud)
{
}

int main()
{
    Student st1("asd", 21);
    //cout << st1.getAge() << endl;

    cin >> st1;
    cout << st1 << endl;


    //cout << &st1 << endl;
    //st1.show();
    //st2.show();
}