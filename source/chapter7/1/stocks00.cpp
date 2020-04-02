#include <iostream>
#include "stock00.h"
using namespace std;

void Stock::acquire(const string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        cout << "Number of shares can't be negative; "
            << company << " shares set to 0." << endl;
            shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted." << endl;
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted." << endl;
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
            << "Transaction is aborted. " << endl; 
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    ios_base::fmtflag orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);

    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << "Share price: $" << share_val << endl;
    cout << "Total Worth: $" << total_val << endl;

    cout.precision(2);
    cout << " Total Worth: $" << total_val << endl;

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}