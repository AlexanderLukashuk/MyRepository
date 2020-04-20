#include <iostream>
#include <time.h>
#include <ncurses.h>
#include "game.h"

Game::Game()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = 0;
        }
    }

    spawn();

    //array[3][3] = 2;
    //array[2][3] = 2;

    //array[1][1] = 4;


    //array[3][1] = 4;


    //array[1][0] = 2;
    //array[1][2] = 2;
    //array[1][3] = 2;
    //array[0][3] = 2;
    //array[3][2] = 2;

    //array[0][0] = 4;
    //array[2][1] = 2;
    //array[3][0] = 4;

    //array[0][1] = 4;
    //array[1][1] = 2;
    //array[2][1] = 4;
    //array[0][2] = 2;
    //array[2][2] = 2;
    //array[0][3] = 2;
    //array[1][3] = 2;
}

void Game::move(Direction dir)
{
    spawn();
    switch (dir)
    {
    case Direction::UP:
    {
        moveUp();
        break;
    }
    case Direction::DOWN:
    {
        moveDown();
        break;
    }
    case Direction::LEFT:
    {
        moveLeft();
        break;
    }
    case Direction::RIGHT:
    {
        moveRight();
        break;
    }
    }
}

void Game::moveUp()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 4 - 1; i >= 0; i--)
        {
            if (array[i - 1][j] >= 0 && array[i][j] > 0)
            {
                if (i == 0 && array[i][j] > 0)
                {
                    continue;
                }
                else if (array[i][j] == array[i - 1][j])
                {
                    array[i - 1][j] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }
    
    for (int j = 0; j < 4; j++)
    {
        for (int i = 4 - 1; i >= 0; i--)
        {
            /*if (array[i - 1][j] == 0)
            {
                array[i - 1][j] = array[i][j];
                array[i][j] = 0;
            }*/

            if (i == 0 && array[i][j] > 0)
            {
                continue;
            }
            else if (array[i - 1][j] == 0)
            {
                int temp = i;

                while (temp < 4)
                {
                    array[temp - 1][j] = array[temp][j];
                    array[temp][j] = 0;
                    temp++;
                }
            }
        }
    }

}

void Game::moveDown()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (array[i + 1][j] >= 0 && array[i][j] > 0)
            {
                if (i == 3 && array[i][j] > 0)
                {
                    continue;
                }
                else if (array[i][j] == array[i + 1][j])
                {
                    array[i + 1][j] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            /*if (array[i + 1][j] == 0)
            {
                array[i + 1][j] = array[i][j];
                array[i][j] = 0;
            }*/

            if (i == 3 && array[i][j] > 0)
            {
                continue;
            }
            else if (array[i + 1][j] == 0)
            {
                int temp = i;

                while (temp >= 0)
                {
                    array[temp + 1][j] = array[temp][j];
                    array[temp][j] = 0;
                    temp--;
                }
            }
        }
    }

}

void Game::moveLeft()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j + 1] >= 0)
            {
                if (j == 0 && array[i][j] > 0)
                {
                    continue;
                }
                else if (array[i][j] == array[i][j - 1])
                {
                    array[i][j - 1] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (j == 0 && array[i][j] > 0)
            {
                continue;
            }
            //if (array[i][j + 1] > 0 && array[i][j - 1] == 0 && j + 1 < 4)
            //else if (array[i][j - 1] == 0 && j - 1 >= 0)
            else if (array[i][j - 1] == 0 && j >= 0)
            {
                /*temp = j;
                while (array[i][j - 1] == 0 && temp >= 0)
                {
                    array[i][j - 1] = array[i][j];
                    array[i][j] = 0;
                    temp--;
                }*/

                int temp = j;

                //std::cout << "temp = " << temp << std::endl;

                /*for (int k = j; k < 4; k++)
                {
                    array[i][k - 1] = array[i][k];
                    array[i][k] = 0;
                }*/

                while (temp < 4)
                {
                    array[i][temp - 1] = array[i][temp];
                    array[i][temp] = 0;
                    temp++;
                    //std::cout << "temp = " << temp << std::endl;
                }

                //array[i][j - 1] = array[i][j];
                //array[i][j] = 0;
            }

            /*std::cout << "array[" << i << "][" << j << "] = " << array[i][j] << std::endl;

            std::cout << array[2][0 - 1] << std::endl;

            showField();
            std::cin.get();*/
        }
    }

    /*for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j - 1] >= 0)
            {
                if (array[i][j] == array[i][j - 1])
                {
                    array[i][j - 1] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }*/

    /*for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (array[i][j - 1] >= 0 && array[i][j] > 0)
            {
                if (array[i][j] == array[i][j - 1])
                {
                    array[i][j - 1] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }*/
}

void Game::moveRight()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            /*if (array[i][j + 1] >= 0 && array[i][j] > 0)
            {
                if (array[i][j] == array[i][j + 1])
                {
                    array[i][j + 1] += array[i][j];
                    array[i][j] = 0;
                }
            }*/

            if (array[i][j - 1] >= 0)
            {
                if (j == 3 && array[i][j] > 0)
                {
                    continue;
                }
                else if (array[i][j] == array[i][j + 1])
                {
                    array[i][j + 1] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                continue;
            }
            else if (array[i][j + 1] == 0 && j + 1 <= 4)
            {
                //array[i][j] = array[i][j - 1];
                //array[i][j - 1] = 0;

                int temp = j;
                //std::cout << "temp = " << temp << std::endl;
                //std::cin.get();

                while (temp >= 0)
                {
                    array[i][temp + 1] = array[i][temp];
                    array[i][temp] = 0;
                    temp--;
                //std::cout << "temp = " << temp << std::endl;
                //std::cin.get();
                }

            }
        }
    }

    /*for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j + 1] >= 0 && array[i][j] > 0)
            {
                if (array[i][j] == array[i][j + 1])
                {
                    array[i][j + 1] += array[i][j];
                    array[i][j] = 0;
                }
            }
        }
    }*/
}

void Game::showField()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printw("%d\t", array[i][j]);
        }
        printw("%s", "\n");
        //wmove(stdscr, i, 0);
        //wrefresh(stdscr);
    }
}

void Game::spawn()
{

    int num = rand() % 101;
    int value = (num > 90 ? 4 : 2);

    while (true)
    {
        int y = rand() % 4;
        int x = rand() % 4;

        if (array[y][x] == 0)
        {
            array[y][x] = value;
            break;
        }
    }
}
