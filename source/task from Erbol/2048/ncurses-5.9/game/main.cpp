#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#include <iostream>
#include <time.h>
#include <ncurses.h>
#include "game.h"

int main()
{
    initscr();
    keypad(stdscr, true);
    srand(time(0));
    int ch;
    Game game;

    while(true)
    {
        game.showField();
        cls();
        ch = getch();

        switch(ch)
        {
            case KEY_UP:
            {
                game.move(UP);
                break;
            }
            case KEY_DOWN:
            {
                game.move(DOWN);
                break;
            }
            case KEY_LEFT:
            {
                game.move(LEFT);
                break;
            }
            case KEY_RIGHT:
            {
                game.move(RIGHT);
                break;
            }
        }
    }

    /*Game game1;
    game1.showField();
    std::cout << std::endl;
    std::cout << std::endl;
    //game1.move(UP);
    //game1.move(DOWN);
    //game1.move(RIGHT);
    //game1.move(LEFT);
    //game1.move(UP);
    game1.showField();
    game1.move(DOWN);

    std::cout << std::endl;
    std::cout << std::endl;

    //game1.move(RIGHT);
    //game1.move(LEFT);
    //game1.move(UP);
    game1.showField();
    game1.move(DOWN);

    std::cout << std::endl;
    std::cout << std::endl;

    game1.showField();
    game1.move(RIGHT);

    std::cout << std::endl;
    std::cout << std::endl;

    //game1.move(RIGHT);
    //game1.move(LEFT);
    //game1.move(UP);
    game1.showField();
    game1.move(LEFT);

    
    game1.showField();*/

    endwin();
}