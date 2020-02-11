#include <iostream>
int main ()
{
    using namespace std;

    int num;
    int source;
    int count = 0;
    int* array;
    bool isLucky = true;

    cout << "Enter lotery number of ticket: ";
    cin >> num;

    source = num;

    while (num != 0)
    {
        num /= 10;
        count++;
    }
    array = new int[count];

    if (count != 20)
        cout << "You entered wrong number of ticket!";

    for (int i = 0; i < count; i++)
    {
        array[i] = source % 10;
        source /= 10;
        cout << "\t" << array[i] << endl;
    }

    for (int i = 0; i < count/2 && isLucky == true; i++)
    {
        if (array[i] != array[count - (4 - i)])
            isLucky = false;
    }

    if (isLucky == true)
        cout << "Congratulations. You won!" << endl;
    else
        cout << "Sorry, You lose" << endl;

    return 0;
}
