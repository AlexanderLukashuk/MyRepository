#include <iostream>
#include "../include/copy.hpp"
using namespace std;

int main()
{
    Book book1;
    Book book2("1984", "George Orwell", 320);

    cout << book2.toString();
}