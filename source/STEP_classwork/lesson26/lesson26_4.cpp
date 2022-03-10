#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class A
{
public:
    int *masA;
    int numA;
    A()
    {
        numA = rand() % 100;
        masA = new int[10];
    }

    virtual ~A()
    {
        delete[] masA;
    }

    virtual int getNum() {}

    virtual void show()
    {
        cout << "NumA = " << numA << endl;
    }
};

class B : public A
{
public:
    int *masB;
    int numB;
    B()
    {
        numB = rand() % 100;

        masB = new int[10];
    }

    ~B()
    {
        delete[] masB;
    }

    virtual int getNum() override
    {
        return numB;
    }

    virtual void show() override
    {
        cout << "NumA = " << numA << " | "
             << "NumB = " << numB << endl;
    }
};

class C : public A
{
public:
    int *masC;
    int numC;
    C()
    {
        numC = rand() % 100;

        masC = new int[10];
    }

    ~C()
    {
        delete[] masC;
    }

    virtual int getNum() override
    {
        return numC;
    }

    virtual void show() override
    {
        cout << "NumA = " << numA << " | "
             << "NumC = " << numC << endl;
    }
};

int main()
{
    srand(time(0));

    vector<A *> vec;

    vec.push_back(new A);
    vec.push_back(new C);
    vec.push_back(new C);
    vec.push_back(new A);
    vec.push_back(new C);
    vec.push_back(new B);
    vec.push_back(new C);
    vec.push_back(new A);
    vec.push_back(new B);
    vec.push_back(new A);
    vec.push_back(new A);
    vec.push_back(new B);

    for (auto el : vec)
    {
        el->show();
    }

    int maxA = 0;
    int maxB = 0;
    int maxC = 0;

    A *ptrA = new A();
    A *ptrB = new B();
    A *ptrC = new C();

    for (auto el : vec)
    {
        if (el->numA > maxA)
        {
            maxA = el->numA;
        }
    }

    for (auto el : vec)
    {
        B *tmp = dynamic_cast<B *>(el);
        if (dynamic_cast<B *>(el))
        {
            if (dynamic_cast<B *>(el)->numB > maxB)
            {
                maxB = dynamic_cast<B *>(el)->numB;
            }
        }

        C *tmpC = dynamic_cast<C *>(el);
        if (dynamic_cast<C *>(el))
        {
            if (dynamic_cast<C *>(el)->numC > maxC)
            {
                maxC = dynamic_cast<C *>(el)->numC;
            }
        }
    }

    cout << "\nMax A = " << maxA;
    cout << "\nMax B = " << maxB;
    cout << "\nMax C = " << maxC;
    cout << endl;

    /*for (auto el : vec)
    {
        if (el->numA > maxA)
        {
            maxA = el->numA;
        }

        C *a = dynamic_cast<C *>(ptrA);
        //cout << el->getNum() << endl;
        if (el->getNum() > maxA)
        {
            maxA = el->getNum();
        }
    }

    for (auto el : vec)
    {
        B *b = dynamic_cast<B *>(ptrB);
        //cout << el->getNum() << endl;
        if (el->getNum() > maxB)
        {
            maxB = el->getNum();
        }
    }

    for (auto el : vec)
    {
        C *c = dynamic_cast<C *>(ptrC);
        //cout << el->getNum() << endl;
        if (el->getNum() > maxC)
        {
            maxC = el->getNum();
        }
    }*/

    for (int i = 0; i < vec.size(); i++)
    {
        delete vec[i];
    }
}