#include <iostream>
using namespace std;

struct Fraction
{
    int wholePart;
    int numerator;
    int denominator;
};

/*void addFraction(Fraction*& fractions, int& size)
{
    if (fractions == nullptr)
    {
        size++;
        Fraction* fractions = new Fraction;

        cout << "Enter whole part of fraction: ";
        cin >> fractions->wholePart;
        cout << "Enter numerator of fraction: ";
        cin >> fractions->numerator;
        cout << "Enter denominator of fraction: ";
        cin >> fractions->denominator;
    }
    else
    {
        size++;
        Fraction* newFractions = new Fraction[size];

        for (int i = 0; i < size - 1; i++)
        {
            newFractions[i] = fractions[i];
        }

        cout << "Enter whole part of fraction: ";
        cin >> newFractions[size - 1].wholePart;
        cout << "Enter numerator of fraction: ";
        cin >> newFractions[size - 1].numerator;
        cout << "Enter denominator of fraction: ";
        cin >> newFractions[size - 1].denominator;

        delete[]fractions;
        fractions = newFractions;
    }
}*/

void sum(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    //fraction3.numerator = fraction1.numerator + fraction2.numerator;
    if (fraction1.denominator == fraction2.denominator)
    {
        fraction3.denominator = fraction1.denominator;
        fraction3.numerator = fraction1.numerator + fraction2.numerator;
    }
    else
    {
        fraction3.denominator = fraction1.denominator * fraction2.denominator;
    }

    for (int i = 0; i < fraction3.numerator; i++)
    {
        if (fraction3.numerator > fraction3.denominator)
        {
            fraction3.wholePart++;
            //fraction3.numerator -= fraction3.denominator;
        }

        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    for (int i = 0; i < fraction2.numerator; i++)
    {
        if (fraction2.numerator > fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }

        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    for (int i = 0; i < fraction1.numerator; i++)
    {
        if (fraction1.numerator > fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }

        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    fraction3.numerator = fraction1.numerator + fraction2.numerator;
}

void subtraction(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    if (fraction1.denominator == fraction2.denominator)
    {
        fraction3.denominator = fraction1.denominator;
        //fraction3.numerator = fraction1.numerator - fraction2.numerator;
    }
    else
    {
        fraction3.denominator = fraction1.denominator * fraction2.denominator;
    }

    for (int i = 0; i < fraction3.numerator; i++)
    {
        if (fraction3.numerator > fraction3.denominator)
        {
            fraction3.wholePart++;
            fraction3.numerator -= fraction3.denominator;
        }

        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    for (int i = 0; i < fraction2.numerator; i++)
    {
        if (fraction2.numerator > fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }

        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    for (int i = 0; i < fraction1.numerator; i++)
    {
        if (fraction1.numerator > fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }

        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    if (fraction2.numerator > fraction1.numerator && fraction1.wholePart > 0)
    {
        fraction1.wholePart--;
        fraction1.numerator += fraction1.denominator;
    }

    fraction3.numerator = fraction1.numerator - fraction2.numerator;
}

void multiplication(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    //fraction3.numerator = fraction1.numerator + fraction2.numerator;
    fraction1.numerator += fraction1.wholePart * fraction1.denominator;
    fraction3.denominator = fraction1.denominator * fraction2.denominator;

    for (int i = 0; i < fraction3.numerator; i++)
    {
        if (fraction3.numerator > fraction3.denominator)
        {
            fraction3.wholePart++;
            //fraction3.numerator -= fraction3.denominator;
        }

        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    for (int i = 0; i < fraction2.numerator; i++)
    {
        if (fraction2.numerator > fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }

        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    for (int i = 0; i < fraction1.numerator; i++)
    {
        if (fraction1.numerator > fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }

        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    fraction3.numerator = fraction1.numerator + fraction2.numerator;
}

int main()
{
    int size = 0, num = 0;
    Fraction fraction1;
    Fraction fraction2;
    Fraction fraction3;

    /*cout << "Enter first fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction1.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction1.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction1.denominator;

    cout << "Choose operation: " << endl;
    cout << "1)Addition" << endl;
    cout << "2)Subtraction" << endl;
    cout << "3)Multiplication" << endl;
    cout << "4)Division" << endl;
    cin >> num;*/

    while (num != 5)
    {
        cout << "Enter first fraction: " << endl;
        cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
        cin >> fraction1.wholePart;
        cout << "Enter numerator of fraction: ";
        cin >> fraction1.numerator;
        cout << "Enter denominator of fraction: ";
        cin >> fraction1.denominator;

        cout << "Choose operation: " << endl;
        cout << "1)Addition" << endl;
        cout << "2)Subtraction" << endl;
        cout << "3)Multiplication" << endl;
        cout << "4)Division" << endl;
        cout << "5)Exit" << endl;
        cin >> num;

        switch (num)
        {
            case 1:
                sum(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "+"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            case 2:
                subtraction(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "-"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            case 3:
            case 4:
            default:
                break;
        }
    }
}
