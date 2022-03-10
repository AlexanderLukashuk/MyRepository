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
                else if (array[i][j] == array[i][j - 1] && j - 1 >= 0)
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
            else if (array[i][j - 1] == 0 && j - 1 >= 0)
            {
                int temp = j;

                while (temp < 4)
                {
                    array[i][temp - 1] = array[i][temp];
                    array[i][temp] = 0;
                    temp++;
                }
            }
        }
    }
}

void Game::moveRight()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
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
                int temp = j;

                while (temp >= 0)
                {
                    array[i][temp + 1] = array[i][temp];
                    array[i][temp] = 0;
                    temp--;
                }

            }
        }
    }
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
