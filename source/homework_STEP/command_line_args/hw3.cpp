#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
	srand(time(0));

	if (argc == 4)
	{
		int key = atoi(argv[3]);
		ifstream fs;
		ofstream ofs;
		fs.open(argv[1]);
		if (fs.is_open())
		{
			fs.seekg(0, ios::end);
			int size = fs.tellg();
			fs.seekg(0, ios::beg);
			char* str = new char[size];
			for (int i = 0; !fs.eof(); i++) {
				fs.get(str[i]);
				if (fs.eof()) 
                {
					str[i] = '\0';
				}
			}
			fs.close();

			if (!strcmp(argv[2], "shifr"))
			{
				for (int i = 0; str[i] != '\0'; i++)
				{
					str[i] = (int)str[i] + key;
				}
			}
			else if (!strcmp(argv[2], "deshifr")) 
			{
				for (int i = 0; str[i] != '\0'; i++)
				{
					str[i] = (int)str[i] - key;
				}
			}

			ofs.open(argv[1]);
			ofs << str;
			ofs.close();
		}
	}
	else
	{
		cout << "Incorrect count of parametres" << endl;
	}

    return 0;
}
