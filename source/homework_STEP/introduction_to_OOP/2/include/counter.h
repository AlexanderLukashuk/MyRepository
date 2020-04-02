#include <iostream>
using namespace std;

class Counter
{
    private:
        int count;
        int minValue;
        int maxValue;
    public:
        Counter(int min, int max, int c);

        void add();

        void show();
};

void menu(int option, Counter obj);