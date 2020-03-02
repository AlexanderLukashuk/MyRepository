#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
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
    KEY_F12 = 34
};

struct Editor
{
	char arraySymbols[SIZE1][SIZE2];
	int arrayColor[SIZE1][SIZE2];
	int arrayBackGround[SIZE1][SIZE2];

	Editor()
	{
		for (int i = 0; i < SIZE1; i++)
		{
			for (int j = 0; j < SIZE2; j++)
			{
				arraySymbols[i][j] = '_';
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
    
    void clearArray()
    {
        for (int i = 0; i < SIZE1; i++)
        {
            for (int j = 0; j < SIZE2; j++)
            {
                arraySymbols[i][j] = '_';
            }
        }
    }
};

char* strcat(char *name, const char *txt)
{
    int size = strlen(name);
    int i;

   for (i = 0; txt[i] != '\0'; i++)
   {
        name[size + i] = txt[i];
   }
    name[size + i] = '\0';

   return name;
}

int main()
{
    fstream fs;
    fstream fList;
    Editor file;
    //Editor* file = nullptr;
    int option = 0;
    char fName[100];
    char txt[] = ".txt";
    char buffer[50];
    char color[8][20] = { "COLOR_BLACK", "COLOR_RED",
        "COLOR_GREEN",
        "COLOR_YELLOW",
        "COLOR_BLUE",
        "COLOR_MAGENTA",
        "COLOR_CYAN",
        "COLOR_WHITE" };

    while (option != 5)
    {
        cout << "TextEdit will open when you chose option" << endl;
        cout << "When you are finished writing, press \"Esc\" to save the file" << endl;
        cout << "Choose option:" << endl;
        cout << "1)Create new file" << endl;
        cout << "2)Open file" << endl;
        cout << "3)Delete file" << endl;
        cout << "4)Show list of file" << endl;
        cout << "5)Exit" << endl;
        cin >> option;
        cin.get();

        switch (option)
        {
            case 1:
                cout << "Enter name of file: ";
                cin.getline(fName, 100);
                strcat(fName, txt);
                //cout << name << endl;
                fs.open(fName);
                //fList.open("List.txt", ios::app);
                /*initscr();
                start_color();
                cbreak();
                keypad(stdscr, TRUE);*/
                if (fs.is_open())
                {
                    cout << "File with this name already exist" << endl;
                    cout << endl;
                }
                else
                {
                    fs.close();
                    fList.open("List.txt", ios::app);
                    if (fList.is_open())
                    {
                        fList << fName << endl;
                    }
                    fList.close();
                    //fs.open(fName, ios::app);
                    /*fList.open("List.txt", ios::app);
                    if (fList.is_open())
                    {
                        fList << fName << " ";
                    }
                    fList.close();*/

                    //fs.open(fName, ios::app);

                    initscr();
                    start_color();
                    cbreak();
                    keypad(stdscr, TRUE);

                    /*fList.open("List.txt", ios::app);
                    if (fList.is_open())
                    {
                        fList << fName << " ";
                    }
                    fList.close();*/
                    //fs.close();
                    //fs.open(fName, ios::app);
                    //noecho();
                    //keypad(stdscr, TRUE);
	                int k = 0, h = 0;
                    WINDOW * win = newwin(SIZE2, SIZE1, h, k);
                    int move(int y, int x);
                    int refresh(void);
	                char ch;
                    int posY = 0, posX = 0;
                    int wmove(WINDOW * win, int y, int x);
                    int wrefresh(WINDOW * win);
                    int countLeft = 0, countRight = 0; 
                    int countUp = 0, countDown = 0;
                    int init_pair(short n, short f, short b);
                    int clr = 0;
                    //wattron(win, COLOR_PAIR(2));

	                while (true)
	                {
		                //if (kbhit)
		                //{
			            int key = getch();
			                //ch = key;
                        //cout << key;
			            if (key == KEY_ESC)
			            {
                            break;
			            }
                        //x = key;

			            if (k == SIZE2)
			            {
				            h++;
                            k = 0;
                            posY++;
                            posX = 0;
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
                            case '\n'://PARASHA(вверх не передвигается курсор)
                                //posY++;
                                cout << '\n';
                                h++;
                                //countDown++;
                                k = 0;
                                //posY++;
                                posX = 0;
                                fs << endl;
                                wmove(win, posY, posX);
                                //move(posY, posX);
                                wrefresh(win);
                                //refresh();
                                break;
                            case 127://POCHTI PARASHA
                                if (k - 1 < 0)
                                {
                                    continue;
                                }
                                else
                                {
			                        file.arraySymbols[h][k - 1] = delch();
			                        file.arraySymbols[h][k - 1] = ' ';
                                    posX--;
                                }
                                //wrefresh(win);
                                break;
                            case 116:
                                clr++;
                                //init_pair(0, clr, COLOR_BLACK);

                                if (clr + 1 > 7)
                                {
                                    clr = 0;
                                }
                                else
                                {
                                    init_pair(0, clr, COLOR_BLACK);
                                }
                                break;
                            default:
                                ch = key;
                                k = k - countLeft + countRight;
                                h = h - countUp + countDown;
                                //posX = k - countLeft + countRight;
                                posY = posY - countUp + countDown;
                                wmove(win, posY, posX + 1);
			                    file.arraySymbols[h][k] = ch;
                                //fs << cin.get();
                                fs.open(fName, ios::app);
                                if (fs.is_open())
                                {
                                    fs << ch;
                                }
                                fs.close();
                                k++;
                                posX++;
                                countLeft = 0;
                                countRight = 0;
                                countUp = 0;
                                countDown = 0;
                                wrefresh(win);
                                //int posX = 0, posY = 0;
                                //int wrefresh(WINDOW * win);
                                //int refresh(void);
                                break;
                        }

                        wmove(win, posY, posX);
                        //wrefresh(win);
		                //ch = (char)key;
		                //cout << ch;

	                }
	                system("clear");
	                //file.show();

                    refresh();
                    endwin();
	                //system("cls");
                    file.show();
                    file.clearArray();
                }
                //file.clearArray();
                //fs.close();
                break;
            case 2:
                cout << "Enter name of file which want open: ";
                cin.getline(fName, 100);
                strcat(fName, txt);
                fs.open(fName);
                /*initscr();
                start_color();
                cbreak();
                keypad(stdscr, TRUE);*/
                if (fs.is_open())
                {
                    initscr();
                    start_color();
                    cbreak();
                    keypad(stdscr, TRUE);

                    fs.close();
                    fs.open(fName, ios::app);
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
                    int countLeft = 0, countRight = 0; 
                    int countUp = 0, countDown = 0, countSymbol = 0;

	                while (true)
	                {
		                //if (kbhit)
		                //{
			            int key = getch();
			                //ch = key;
                        //cout << key;
			            if (key == KEY_ESC)
			            {
                            break;
			            }
                        //x = key;

			            if (k == SIZE2)
			            {
				            h++;
                            k = 0;
                            posY++;
                            posX = 0;
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
                            case '\n'://PARASHA(вверх не передвигается курсор)
                                //posY++;
                                cout << '\n';
                                h++;
                                //countDown++;
                                k = 0;
                                //posY++;
                                posX = 0;
                                fs << endl;
                                wmove(win, posY, posX);
                                //move(posY, posX);
                                wrefresh(win);
                                //refresh();
                                break;
                            case 127://POCHTI PARASHA
                                if (k - 1 < 0)
                                {
                                    continue;
                                }
                                else
                                {
			                        file.arraySymbols[h][k - 1] = delch();
			                        file.arraySymbols[h][k - 1] = ' ';
                                    posX--;
                                }
                                //wrefresh(win);
                                break;
                            default:
                                ch = key;
                                countSymbol++;
                                k = k - countLeft + countRight;
                                h = h - countUp + countDown;
                                //posX = k - countLeft + countRight;
                                posY = posY - countUp + countDown;
                                wmove(win, posY, posX + 1);
			                    file.arraySymbols[h][k] = ch;
                                //fs << cin.get();
                                fs << ch;
                                k++;
                                posX++;
                                countLeft = 0;
                                countRight = 0;
                                countUp = 0;
                                countDown = 0;
                                wrefresh(win);
                                //int posX = 0, posY = 0;
                                //int wrefresh(WINDOW * win);
                                //int refresh(void);
                                break;
                        }

                        wmove(win, posY, posX);
                        //wrefresh(win);
		                //ch = (char)key;
		                //cout << ch;

	                }
	                //system("cls");
	                //file.show();

                    endwin();
	                //system("cls");
                    file.show();
                }
                else
                {
                    cout << "File with this name does not exist" << endl;
                    cout << endl;
                }
                fs.close();
                break;
            case 3:
                cout << "Enter name of file which want delete: ";
                cin.getline(fName, 100);
                strcat(fName, txt);

                if (remove(fName) != 0)
                {
                    cout << endl;
                    cout << "Error deliting file" << endl;
                    cout << "File with this name does not exist" << endl;
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    cout << "File successfuly deleted" << endl;
                    cout << endl;
                }
                break;
            case 4:
                fList.open("List.txt");
                
                if (fList.is_open())
                {
                    while (!fList.eof())
                    {
                        fList >> buffer;
                        cout << buffer;
                    }
                }
                fList.close();
                cout << endl;
                break;
            case 5:
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Try again" << endl;
                break;
        }
    }

    return 0;
}
