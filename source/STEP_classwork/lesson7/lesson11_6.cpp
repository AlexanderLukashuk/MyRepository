#include <iostream>
using namespace std;

class Singleton
{
    private:
        static Singleton * ptr;
        Singleton() {}
        int number;
    public:
        static const Singleton* getReference()
        {
            return ptr;
        } 

        static void show()
        {
            cout << "SOME TEXT..." << endl;
        }
};

Singleton* Singleton::ptr = new Singleton;

int main()
{
    Singleton::getReference()->show();
}