#include <iostream>
#include <string>
using namespace std;

class Tiles
{
    public:
    string brand;
    double size_h;
    double size_w;

    void getData(Tiles obj)
    {
        cout << "Brand: " << obj.brand << " ";
        cout << "Size_h: " << obj.size_h << " ";
        cout << "Size_w: " << obj.size_w << " ";
        cout << endl;
    }
};

int main()
{
    Tiles tile1;
    Tiles tile2;
    Tiles tile3;

    tile1.brand = "Top brand";
    tile1.size_h = 3.4;
    tile1.size_w = 5.1;

    tile2.brand = "Tiles";
    tile2.size_h = 7.9;
    tile2.size_w = 2.7;

    tile3.brand = "Good";
    tile3.size_h = 6.3;
    tile3.size_w = 15;

    tile1.getData(tile1);
    tile2.getData(tile2);
    tile3.getData(tile3);

    return 0;
}
