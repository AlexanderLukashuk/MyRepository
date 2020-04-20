#ifndef _GAME_H_
#define _GAME_H_

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game
{
private:
    int array[4][4];
    int score;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void spawn();
public:
    Game();
    //~Game();

    void move(Direction dir);
    int getScore() const;

    void showField();
};

#endif