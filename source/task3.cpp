#include <iostream>
int main ()
{
   using namespace std;
   int *** p = new int**;
   ** p = *new int*;
   * p = new int;
   *p = 5;

   cout << "number: " << ***p << endl;
   cout << "Address **p = " << **p << endl;
   cout << "Address ***p = " << *p << endl;
   cout << "Address p = " << &p << endl;

   delete *p;
   delete **p;
   delete p;
   return 0;
}
