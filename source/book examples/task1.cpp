#include <iostream>
int main ()
{
	using namespace std;
	double pp = 2.0;
	double ** p = new double*;
    * p = new double;
    **p = pp;
	
	cout << "Number of pp = " << pp << endl;
	cout << "Number of pp with help notation = " << **p << endl;
	cout << "Number of pp with help **p = " << **p << endl;
    cout << endl;
    cout << endl;
	cout << "Address of pp = " << &pp << endl;
	cout << "Address of pp with help notation = " << *p << endl;
	cout << "Address of **p = " << &p << endl;
	
	delete *p;
    delete p;
	return 0;
}
