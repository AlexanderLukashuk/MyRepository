#include <iostream>
#include <time.h>
using namespace std;

enum precipitation
{
    RAIN = 1,
    SNOW = 2,
    HAIL = 3,
    RAIN_AND_SNOW = 4
};

int main()
{
    srand(time(0));
    int temp;
    double col_precipitation[1];
    char type_precipitation[100];
    char str[100] = "rain snow hail rain and snow";
    temp = rand() % 4 + 1;

    switch (temp)
    {
        case RAIN:
            for (int i = 0, j = 0; str[i] != ' '; i++, j++)
            {
                type_precipitation[i] = str[i];
                if (str[i + 1] == ' ')
                {
                    type_precipitation[j + 1] = '\0';
                }
            }
            break;
        case SNOW:
            for (int i = 5, j = 0; str[i] != ' '; i++, j++)
            {
                type_precipitation[j] = str[i];
                if (str[i + 1] == ' ')
                {
                    type_precipitation[j + 1] = '\0';
                }
            }
            break;
        case HAIL:
            for (int i = 10, j = 0; str[i] != ' '; i++, j++)
            {
                type_precipitation[j] = str[i];
                if (str[i + 1] == ' ')
                {
                    type_precipitation[j + 1] = '\0';
                }
            }
            break;
        case RAIN_AND_SNOW:
            for (int i = 15, j = 0; str[i] != '\0'; i++, j++)
            {
                type_precipitation[j] = str[i];
                if (str[i + 1] == '\0')
                {
                    type_precipitation[j + 1] = '\0';
                }
            }
            break;
    }

    col_precipitation[0] = (double)(rand() % 100) + ((double)(rand() % 10) / 10);

    cout << "Type of precipitation is " << type_precipitation << endl;
    cout << "The amount of precipitation = " << col_precipitation[0] << endl;

    return 0;
}
