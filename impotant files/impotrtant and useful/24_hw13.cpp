#include <iostream>
#include "conio.h"
#include <stdio.h>
#include <unistd.h>
using namespace std;

void Beep(double Hz, int msec)
{
    fprintf(stderr,"\033[10;%f]\033[11;%d]\a", Hz, msec);
    usleep(msec*1000);
}

int main()
{
	Beep(494, 250);
    Beep(523, 250);
    Beep(587, 500);
    Beep(523, 250);
    Beep(494, 250);
    Beep(440, 500);
        while(true)
    {
        char key = getch();
        switch(key)
        {
            case 'a':
                cout << "do";
                break;
            case 's':
                cout << "re";
                break;
            case 'd':
                cout << "mi";
                break;
            case 'f':
                cout << "fa";
                break;
            case 'g':
                cout << "so";
                break;
            case 'h':
                cout << "la";
                break;
            case 'j':
                cout << "si";
                break;
        }
        Beep(124, 50);
    }
    
    
    return 0;
}
