#include <iostream>
using namespace std;

struct Apartment
{
    int num;
    int room;
    int area;

    void addApartment(Apartment*& apartments, int& count)
    {
        if (apartments == nullptr)
        {
            count++;
            apartments = new Apartment[count];

            cout << "Enter number of apartment: ";
            cin >> apartments->num;
            cout << "Enter number of room: ";
            cin >> apartments->room;
            cout << "Enter area of apartment: ";
            cin >> apartments->area;
        }
        else
        {
            count++;
            Apartment* newApartments = new Apartment[count];

            for (int i = 0; i < count - 1; i++)
            {
                newApartments[i] = apartments[i];
            }

            cout << "Enter number of apartment: ";
            cin >> newApartments[count - 1].num;
            cout << "Enter number of room: ";
            cin >> newApartments[count - 1].room;
            cout << "Enter area of apartment: ";
            cin >> newApartments[count - 1].area;

            delete[]apartments;
            apartments = newApartments;
        }
    }

    void showParameters(Apartment* apartments, int count)
    {
        if (apartments == nullptr)
        {
            cout << "There are no any apartment" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                cout << endl;
                cout << "Apartment number: " << apartments[i].num << endl;
                cout << "Number of room in apartment: " << apartments[i].room << endl;
                cout << "Area of apartment: " << apartments[i].area << endl;
                cout << endl;
            }
        }
    }
};

struct House
{
    int houseNum;
    int countApartment;
    Apartment* apartments = nullptr;

    void addNewApart(Apartment*& Apartments, int& countApartments)
    {
        apartments->addApartment(Apartments, countApartments);
    }

    void showApartments(Apartment* apartments, int count)
    {
        if (apartments == nullptr)
        {
            cout << "There are no any apartment" << endl;
            return;
        }
        else
        {
           //for (int i = 0; i < count; i++)
           //{
           //    cout << "Apartment number: " << apartments[i].num << endl;
           //}

            apartments->showParameters(apartments, count);
        }
    }

    void deleteApartment(Apartment*& apartments, int& countApartment, int index)
    {
        if (apartments == nullptr)
        {
            cout << "There are no any apartment" << endl;
            return;
        }
        else
        {
            bool check = false;

            for (int i = 0; i < countApartment + 1; i++)
            {
                if (apartments[i].num == index)
                {
                    check = true;
                }
            }

            if (check)
            {
                countApartment--;
                Apartment* newApartments = new Apartment[countApartment];

                for (int i = 0, j = 0; i < countApartment + 1; i++)
                {
                    if (apartments[i].num != index)
                    {
                        newApartments[j] = apartments[i];
                        j++;
                    }
                }

                delete[]apartments;
                apartments = newApartments;
            }
            else
            {
                cout << "There are no apartment with this number" << endl;
                return;
            }
        }
    }
};

int main()
{
    int index;
    House house;
    house.countApartment = 0;
    cout << "Enter number of house: ";
    cin >> house.houseNum;
    int option = 0;

    while (option != 4)
    {
        cout << "Chose option: " << endl;
        cout << "1)Add apartment" << endl;
        cout << "2)Delete apartment" << endl;
        cout << "3)Show all aprtments" << endl;
        cout << "4)Exit" << endl;
        cin >> option;

        switch (option)
        {
            case 1:
                house.addNewApart(house.apartments, house.countApartment);
                break;
            case 2:
                cout << "Enter number of apartment which want delete: ";
                cin >> index;
                house.deleteApartment(house.apartments, house.countApartment, index);
                break;
            case 3:
                house.showApartments(house.apartments, house.countApartment);
                break;
            case 4:
                cout << "Bye" << endl;
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Try again" << endl;
                break;
        }
    }

    return 0;
}
