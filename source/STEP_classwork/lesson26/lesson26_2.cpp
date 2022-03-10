#include <iostream>
#include <vector>
using namespace std;

class Parent
{
public:
    int* mas;
    virtual void method1()
    {
        cout << "Parent" << endl;
    }


    virtual ~Parent() {}
};

class Son : public Parent
{
public:
    virtual void method1() override
    {
        cout << "Son" << endl;
    }

    Son()
    {
        mas = new int[10];
        mas[1] = 5;
        mas[2] = 4;
        mas[3] = 3;
        mas[4] = 2;
        mas[5] = 1;

    }

    ~Son()
    {
        cout << "DESTR Son" << endl;
        delete[]mas;
    }
};

class Daughter : public Parent
{
public:
    virtual void method1() override
    {
        cout << "Daughter" << endl;
    }

    ~Daughter()
    {
        cout << "DESTR Daughter" << endl;
    }
};

int main()
{
    vector<reference_wrapper<Parent> > vec;
    {
        Son s;
        Daughter d;
        vec.push_back(s);
        vec.push_back(d);

        cout << dynamic_cast<Son&>(vec[0].get()).mas[3] << endl;

    }
    vec[0].get().method1();
    vec[1].get().method1();

    //vector<Parent*> p;
    /*Son s1;
    Son s2;
    Son s3;
    Daughter d1;
    Daughter d2;
    Daughter d3;
    Daughter d4;
    Parent* ptr1 = &s1;*/

    /*p.push_back(new Son);
    p.push_back(new Son);
    p.push_back(new Daughter);
    p.push_back(new Daughter);
    p.push_back(new Daughter);

    for (auto el : p)
    {
        el->method1();
    }

    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }*/
}