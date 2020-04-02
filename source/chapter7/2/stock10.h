#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>
using namespace std;

class Stock
{
    private:
        string company;
        long shares;
        double shares_val;
        double total_val;
        void set_tot()
        {
            total_val = shares * shares_val;
        }

        public:
            Stock();
            Stock(const string & co, long n = 0, double pr = 0.0);
            ~Stock();
            void buy(long num, double price);
            void sell(long num, double price);
            void update(double price);
            void show();
};
#endif