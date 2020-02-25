#include <iostream>
#include <string.h>
//#include <conio.h>
#include <ncurses.h>
using namespace std;

const int SIZE1 = 25;
const int SIZE2 = 80;

enum {
    KEY_ARROW_UP = 72,
    KEY_ARROW_DOWN = 80,
    KEY_ARROW_LEFT = 75,
    KEY_ARROW_RIGHT = 77,
    KEY_ESC = 27,
    KEY_SPACE = 32,
    ENTER_KEY = 13,
    KEY_TAB = 9,
    KEY_DELETE = 83,
    BACKSPACE_KEY = 8,
    //KEY_F1 = 59,
    //KEY_F2,
    //KEY_F3,
    //KEY_F4,
    //KEY_F5,
    //KEY_F6,
    //KEY_F7,
    //KEY_F8,
    //KEY_F9,
    //KEY_F10,
    KEY_F12 = 34
};

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
    cbreak();
    //noecho();
    keypad(stdscr, TRUE);
	int k = 0, h = 0;
    WINDOW * win = newwin(SIZE2, SIZE1, h, k);
    int move(int y, int x);
    int refresh(void);
	char ch;
    int posY = 0, posX = 0;
    int wmove(WINDOW * win, int y, int x);
    int wrefresh(WINDOW * win);
	Screen file;
    int option;

    int countLeft = 0, countRight = 0, countUp = 0, countDown = 0, countSymbol = 0;
    char txt[] = ".txt";
    int count = 1;
    char name[100];
    int *pcount = &count;

    /*cout << "Choose option:" << endl;
    cout << "1)Create new file" << endl;
    cout << "2)Open file" << endl;
    cout << "3)Delete file" << endl;
    cout << "4)Show list of file" << endl;
    cout << "5)Exit" << endl;
    cout << "When you are finished writing, press \"Esc\" to save the file" << endl;
    cin >> option;*/

    /*while (option != 5)
    {
    
        switch (option)
        {
            case 1:
                name = strcat(count, txt);
            case 2:
            case 3:
            case 4:
            default:
        }*/
	while (true)
	{
		//if (kbhit)
		//{
			int key = getch();
			ch = key;
            //cout << key;
			if (key == KEY_ESC)
			{
                break;
			}

			if (k == 79)
			{
				h++;
                k = 0;
			}

            switch (key)
            {
                case KEY_LEFT:
                    if (k - 1 >= 0)
                    {
                        countLeft++;
                        posX--;
                        wmove(win, posY, posX);
                        wrefresh(win);
                    }
                    break;
                case KEY_RIGHT:
                    if (k + 1 <= SIZE2 - 1 && posX + 1 <= k)
                    {
                        countRight++;
                        posX++;
                        wmove(win, posY, posX);
                        wrefresh(win);
                    }
                    break;
                case KEY_UP:
                    if (h - 1 >= 0)
                    {
                        countUp++;
                        posY--;
                        wmove(win, posY, posX);
                        wrefresh(win);
                    }
                    //int wmove(WINDOW * win, int posY, int posX);
                    break;
                case KEY_DOWN:
                    if (h + 1 >= 0 && posY + 1 <= SIZE1 - 1)
                    {
                        countDown++;
                        posY++;
                        wmove(win, posY, posX);
                        wrefresh(win);
                    }
                    break;
                case '\n':
                    cout << '\n';
                    h++;
                    //countDown++;
                    k = 0;
                    //posY++;
                    posX = 0;
                    wmove(win, posY, posX);
                    //move(posY, posX);
                    //wrefresh(win);
                    //refresh();
                    break;
                default:
                    countSymbol++;
                    k = k - countLeft + countRight;
                    h = h - countUp + countDown;
                    //posX = k - countLeft + countRight;
                    //posY = h - countUp + countDown;
                    wmove(win, posY, posX + 1);
			        file.arraySymbols[h][k] = ch;
                    k++;
                    posX++;
                    countLeft = 0;
                    countRight = 0;
                    countUp = 0;
                    countDown = 0;
                    //int posX = 0, posY = 0;
                    //int wrefresh(WINDOW * win);
                    //int refresh(void);
                    break;
            }

            wrefresh(win);
		//ch = (char)key;
		//cout << ch;

	}
	system("cls");
	file.show();

    endwin();
	system("cls");
    file.show();
}
