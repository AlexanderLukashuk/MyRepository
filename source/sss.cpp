#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		cout << "options : " << argc << endl;
		for (int i = 0; i < argc; i++)
		{
			cout << i << " : " << argv[i] << endl;
		}
	}
	else {
		cout << "No options" << endl;
	}

	return 0;
}
