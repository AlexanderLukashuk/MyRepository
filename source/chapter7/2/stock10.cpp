#include <iostream>
#include "stock10.h"
using namespace std;

Stock::Stock()
{
    cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    shares_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const string & co, long n, double pr)
{
    cout << "Constructor using " << co << " called\n";
    company = co;
    if (n < 0)
    {
        cout << "Number of shares can't be nagative; "
            << company << " shares set tot 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }

    shares_val = pr;
    set_tot();
}

Stock::~Stock()
{
    cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        shares_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
            << "Transction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
            << "Transation is aborted.\n";
    }
    else
    {
        shares -= num;
        shares_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    shares_val = price;
    set_tot();
}

void Stock::show()
{
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);
    cout << "Company: " << company;
    cout << " Shares: " << shares << endl;
    cout << "Shares price: $" << shares_val;

    cout.precision(2);
    cout << " Total Worth: $" << total_val << endl;

    cout.setf(orig, ios_base::floatfield);
    cout.precison(prec);
}