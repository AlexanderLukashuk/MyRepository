#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	
	if (argc >= 1)
	{
		cout << "опции есть" << endl << endl;
		if (strcmp(argv[1], "-v") == 0)
		{
			cout << "введена опция -v" << endl;

			cout << "Программа запрограммирована, выводить версию под эту опцию" << endl;
			cout << endl << "version 1.0.0 (к примеру)" << endl;
		}
		if (strcmp(argv[1], "-i") == 0)
		{
			cout << "введена опция -i" << endl << endl;

			if (argc < 3)
			{
				cout << "программа не понимает" << endl;
				cout << "для этой опции требуется указать еще одну" << endl;
			}
			else 
				cout << "делается какая-то вещь с опцией -i для " << argv[2] << endl;
		}
	}
	else {
		cout << "No options" << endl;
	}

	return 0;
}
