#include <iostream>
using namespace std;

enum Direction
{
    UP = 65,
    DOWN = 66,
    LEFT = 68,
    RIGHT = 67
};

const int SIZE_X = 10;
const int SIZE_Y = 10;
int main ()
{
    int headX, headY
    int array[SIZE_X][SIZE_Y];
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            array[i][j] = 0;
        }
    }
    array[headX][headY] = 2;
    while (true)
    {
        int key = getch();
        switch(key)
        {
            case Direction::UP:
                while(!kbhit())
                {
                    headY--;
                }
                break;
            case Direction::DOWN:
                while(!kbhit())
                {
                    headY++;
                }
                break;
            case Direction::LEFT:
                while(!kbhit())
                {
                    headX--;
                }
                break;
            case Direction::RIGHT:
                while(!kbhit())
                {
                    headX++;
                }
                break;
        }
    }

    return 0;
}
