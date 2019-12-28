#include <iostream>
#include "conio.h"
const int KEY_ARROW_UP = 65;
const int KEY_ARROW_DOWN = 66;
const int KEY_ARROW_LEFT = 68;
const int KEY_ARROW_RIGHT = 67;

int main ()
{
    using namespace std;
    int x_size, y_size;

    cout << "Enter x: ";
    cin >> x_size;
    cout << "Enter y: :";
    cin >> y_size;
   

   int array[x_size][y_size];
   array[x_size/2][y_size/2] = 1;

    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            array[i][j] = 0;
            cout << array[i][j] << endl;
        }
    }

    while (true)
    {
        int key = getche();
        cout << key << endl;
        switch (key)
		{
		case KEY_ARROW_DOWN:
			//do stuff here
			cout << "down arrow" << endl;
			break;
		case KEY_ARROW_UP:
			//do stuff here
			cout << "up arrow" << endl;
			break;
		case KEY_ARROW_LEFT:
			//do stuff here
			cout << "left arrow" << endl;
			break;
		case KEY_ARROW_RIGHT:
			//do stuff here
			cout << "right arrow" << endl;
			break;
		}

    }

    return 0;

}
