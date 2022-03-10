#include <iostream>
//#include <conio.h>
//#include "win10.h"
#include <ncurses.h>
//#include <unistd.h>
using namespace std;

const int SIZE1 = 25;
const int SIZE2 = 80;

struct Screen
{
	char arraySymbols[SIZE1][SIZE2];
	int arrayColor[SIZE1][SIZE2];
	int arrayBackGround[SIZE1][SIZE2];

	Screen()
	{
		for (int i = 0; i < SIZE1; i++)
		{
			for (int j = 0; j < SIZE2; j++)
			{
				arraySymbols[i][j] = '0';
			}
		}

		//SetColor(0xC);
	}

	void show()
	{
		for (int i = 0; i < SIZE1; i++)
		{
			for (int j = 0; j < SIZE2; j++)
			{
				cout << arraySymbols[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
    initscr();
    keypad(stdscr, TRUE);
	char ch;
	Screen file;

	cout << "Enter string: " << endl;
	int k = 0, h = 0;
	while (true)
	{
		//if (kbhit)
		//{
			int key = getch();
			ch = key;
			if (key == 27)
			{
				break;
			}
			file.arraySymbols[h][k] = ch;
			//cout << file.arraySymbols[h][k];
			k++;
			if (k == 79)
			{
				h++;
			}
		//}
		//ch = (char)key;
		//cout << ch;

	}
	system("cls");
	file.show();

	
}
