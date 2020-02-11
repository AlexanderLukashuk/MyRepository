#include <iostream>
int main ()
{
using namespace std;
int carrots;
int steinway;
int baldwin;
int yamaha;
yamaha = baldwin = steinway = 88;
carrots = 25;
cout << "I have ";
cout << carrots;
cout << " carrots. ";
cout << endl;
carrots = carrots - 1;
cout << "Crunch, crunch. Now I have " << carrots << " carrots. " << endl;
cout << "steinway = " << steinway << endl;
cout << "baldwin = " << baldwin << endl;
cout << "yamaha = " << yamaha << endl;
return 0;
}
