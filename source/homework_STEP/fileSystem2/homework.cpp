#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char buffer;
    char str[100];
    int countSymbol = 0, countNumber = 0, countVowels = 0, countLine = 0;
    int countConsonants = 0;
    fstream fs;
    fs.open("hw.txt");
    
    if(fs.is_open())
    {
        while (!fs.eof())
        {
            buffer = fs.get();

            if ((int)buffer >= 1 && (int)buffer <= 255)
            {
                countSymbol++;
            }

            if ((int)buffer >= 48 && (int)buffer <= 57)
            {
                countNumber++;
            }

            if (buffer == 'A' || buffer == 'E' || buffer == 'I' || buffer == 'O' 
                    || buffer == 'U' || buffer == 'Y' || buffer == 'a' 
                    || buffer == 'e' || buffer == 'i' || buffer == 'o'
                    || buffer == 'u' || buffer == 'y')
            {
                countVowels++;
            }
            else if (buffer == 'B' || buffer == 'C' || buffer == 'D'
                    || buffer == 'F' || buffer == 'G' || buffer == 'H'
                    || buffer == 'J' || buffer == 'K' || buffer == 'L'
                    || buffer == 'M' || buffer == 'N' || buffer == 'P'
                    || buffer == 'Q' || buffer == 'R' || buffer == 'S'
                    || buffer == 'T' || buffer == 'V' || buffer == 'W'
                    || buffer == 'X' || buffer == 'Z' || buffer == 'b'
                    || buffer == 'c' || buffer == 'd' || buffer == 'f'
                    || buffer == 'g' || buffer == 'h' || buffer == 'j'
                    || buffer == 'k' || buffer == 'l' || buffer == 'm'
                    || buffer == 'n' || buffer == 'p' || buffer == 'q'
                    || buffer == 'r' || buffer == 's' || buffer == 't'
                    || buffer == 'v' || buffer == 'w' || buffer == 'x'
                    || buffer == 'z')
            {
                countConsonants++;
            }
        }

        /*while (!fs.eof())
        {
            countLine++;
            fs.getline(str, 100);
        }*/
    }
    fs.close();

    fs.open("hw.txt");
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            countLine++;
            fs.getline(str, 100);
        }
    }
    fs.close();

    cout << "Number of symbols = " << countSymbol << endl;
    cout << "Number of lines = " << countLine << endl;
    cout << "Number of vowels letters = " << countVowels << endl;
    cout << "Number of consonants letters = " << countConsonants << endl;
    cout << "Number of numbers = " << countNumber << endl;

    return 0;
}
