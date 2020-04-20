#include <iostream>
//#include <conio.h>
#include <vector>
//#include <Windows.h>
using namespace std;

enum keys{ Up = 72, Down = 80, Right = 77, Left = 75, Space = 32, Esc = 27};

class Coord
{
private:
    int x;
    int y;
public:
    Coord() {}
    Coord(int x, int y) : x(x), y(y) {}

    void setX(const int x)
    {
        this->x = x;
    }

    void setY(const int y)
    {
        this->y = y;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    void operator+=(const Coord& crd)
    {
        x += crd.x;
        y += crd.y;
        /*if (obj.x <= 0)
        {
            x += obj.x;
        }
        else if(obj.x >= 0)
        {
            x += obj.x;
        }

        if (obj.y <= 0)
        {
            y += obj.y;
        }
        else if (obj.y >= 0)
        {
            y += obj.y;
        }*/
    }
};

class Pixel
{
private:
    Coord coord;
    int color;
public:
    Pixel() : color(1) {}
    Pixel(const Coord& coord) : color(1), coord(coord) {}
    Pixel(const Coord& coord, int color) : color(color), coord(coord) {}

    void newxColor()
    {
        color += 16;
        if (color == 0x11)
        {
            color = 0x10;
        }

        if (color == 0x20)
        {
            color = 0x21;
        }

        if (color > 0xF1)
        {
            color = 0x01;
        }
    }

    void setColor(int color)
    {
        this->color = color;
    }

    void setCoord(const Coord& coord)
    {
        this->coord = coord;
    }

    int getColor() const
    {
        return color;
    }

    const Coord& getCoord() const
    {
        return coord;
    }
};

class PixelBox
{
private:
    vector<vector<Pixel> > pixels;
    int height;
    int width;
public:
    PixelBox(int width, int height) : width(width), height(height)
    {
        pixels.resize(height);
        for (int i = 0; i < height; i++)
        {
            pixels[i].resize(width);
            for (int j = 0; j < width; j++)
            {
                pixels[i][j].setCoord(Coord(j, i));
            }
        }

        /*for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Coord coord(i, j);
                pixels[i][j] = Pixel(coord);
            }
        }*/
    }

    void changeColor(const Coord& coord)
    {
        pixels[coord.getX()][coord.getY()].newxColor();
    }

    const vector<vector<Pixel> >& getPixelsBox()
    {
        return pixels;
    }

    const Pixel& getPixel(const Coord& coord)
    {

    }

    int getHeight() const
    {
        return height;
    }

    int getWidth() const
    {
        return width;
    }
};

class PixelService
{
private:
    PixelBox pxb;
    Coord current;

    bool handler(int key)
    {
        switch (key)
        {
            case keys::Up:
            {
                if (current.getY() > 0)
                {
                    current += Coord(0, - 1);
                    //current.setY(current.getY() - 1);
                }
                break;
            }
            case keys::Down:
            {
                if (current.getY() < pxb.getHeight())
                {
                    current += Coord(0, 1);
                    //current.setY(current.getY() - 1);
                }
                break;
            }
            case keys::Right:
            {
                if (current.getX() > pxb.getWidth())
                {
                    current += Coord(1, 0);
                    //current.setY(current.getY() - 1);
                }
                break;
            }
            case keys::Left:
            {
                if (current.getX() > 0)
                {
                    current += Coord(-1, 0);
                    //current.setY(current.getY() - 1);
                }
                break;
            }
            case keys::Space:
            {
                pxb.changeColor(current);
                break;
            }
            case keys::Esc:
            {
                exit(0);
                break;
            }
        }
    }

    void setPos(Coord coord)
    {
        COORD cd;
        cd.X = coord.getX();
        cd.Y = coord.getY();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD( coord.getX(), coord.getY() ));
    }

    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStHandle(STD_OUTPUT_HANDLE), color);
    }

    void updateConsole()
    {
        SetPos(current);
        SetcColor(pxb.getPixels(current).getColor());
        cout << ' ';
        SetPos(current);
    }
public:
    PixelService() : pxb(40, 20) {}
    PixelService(int width, int height) : pxb(width, height) {}

    void start()
    {
        while (true)
        {
            if (KeyboardService::listenKeyboard())
            {
                if (handler(KeyboardService::getKey()))
                {
                    updateConsole();
                }
                setPos(current);
            }
        }
    }
};

class KeyboardService
{
private:
    static int key;
    KeyboardService() {}
public:
    static bool listenKeyboard()
    {
        if(_kbhit())
        {
            key = _getch();
            return true;
        }
        else
        {
            return false;
        }
    }

    static int getKey()
    {
        return key;
    }
};
int KeyboardService::key = 0;

int main()
{
    while (true)
    {
        if (KeyboardService::listenKeyboard())
        {
            cout << KeyboardService::getKey() << " ";
        }
    }
}