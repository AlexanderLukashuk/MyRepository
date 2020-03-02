#include <iostream>
using namespace std;

struct WashingMachine
{
    char name[50];
    char firm[50];
    char color[50];
    int length;
    int height;
    int power;
    int spinSpeed;
    int temperature;

    void initMachine(WashingMachine*& wMachine, int& size)
    {
        if (wMachine == nullptr)
        {
            size++;
            wMachine = new WashingMachine[size];

            cout << "Enter name o machine: ";
            cin.getline(wMachine->name, 50);
            //cin.get();
            cout << "Enter firm: ";
            cin.getline(wMachine->firm, 50);
            //cin.get();
            cout << "Enter color: ";
            cin.getline(wMachine->color, 50);
            //cin.get();
            cout << "Enter lenght: ";
            cin >> wMachine->length;
            cin.get();
            cout << "Enter height: ";
            cin >> wMachine->height;
            cout << "Enter power: ";
            cin >> wMachine->power;
            cin.get();
            cout << "Enter spin speed: ";
            cin >> wMachine->spinSpeed;
            cin.get();
            cout << "Enter heating temperature: ";
            cin >> wMachine->temperature;
            cin.get();
        }
        else
        {
            size++;
            WashingMachine* newMachines = new WashingMachine[size];

            for (int i = 0; i < size - 1; i++)
            {
                newMachines[i] = wMachine[i];
            }

            cout << "Enter name of washing machine: ";
            cin.getline(newMachines[size - 1].name, 50);
            //cin.get();
            cout << "Enter firm: ";
            cin.getline(newMachines[size - 1].firm, 50);
            //cin.get();
            cout << "Enter color: ";
            cin.getline(newMachines[size - 1].color, 50);
            //cin.get();
            cout << "Enter lenght: ";
            cin >> newMachines[size - 1].length;
            cin.get();
            cout << "Enter height: ";
            cin >> newMachines[size - 1].height;
            cout << "Enter power: ";
            cin >> newMachines[size - 1].power;
            cin.get();
            cout << "Enter spin speed: ";
            cin >> newMachines[size - 1].spinSpeed;
            cin.get();
            cout << "Enter heating temperature: ";
            cin >> newMachines[size - 1].temperature;
            cin.get();

            delete[]wMachine;
            wMachine = newMachines;
        }
    }

    void showMachines(WashingMachine* machines, int size)
    {
        if (machines == nullptr)
        {
            cout << "There are no any wahing machine" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << i + 1 << ") " << machines[i].name << " ";
            }
        }
        cout << endl;
    }

    void showParameters(WashingMachine *machines, int size, int index)
    {
        if (machines == nullptr)
        {
            cout << "There are no any machines" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (i == index)
                {
                    cout << "Name of washing machine: " << machines[i].name << endl;
                    cout << "Firm of washing machine: " << machines[i].firm << endl;
                    cout << "Color of washing machine: " << machines[i].color << endl;
                    cout << "Length of washing machines: " << machines[i].length << endl;
                    cout << "Height of washing machine: " << machines[i].height << endl;
                    cout << "Power of washing machine: " << machines[i].power << endl;
                    cout << "Spin speed of washing machine: " << machines[i].spinSpeed;
                    cout << endl;
                    cout << "Heating temperature of washing machine: " <<
                        machines[i].temperature << endl;
                }
            }
        }
    }
};

int main()
{
    WashingMachine* machine = nullptr;
    int size = 0;
    int option = 0;
    int index;

    /*cout << "Choose option: " << endl;
    cout << "1)Add washing machine" << endl;
    cout << "2)Delete washing machine" << endl;
    cout << "3)Show list of wasching machine" << endl;
    cout << "4)Show parametrs of wahing machine" << endl;
    cout << "5)Exit" << endl;
    cin >> option;*/

    while (option != 4)
    {
        cout << "Choose option: " << endl;
        cout << "1)Add washing machine" << endl;
        cout << "2)Show list of wasching machine" << endl;
        cout << "3)Show parametrs of wahing machine" << endl;
        cout << "4)Exit" << endl;
        cin >> option;
        cin.get();

        switch (option)
        {
            case 1:
                machine->initMachine(machine, size);
                break;
            case 2:
                machine->showMachines(machine, size);
                break;
            case 3:
                cout << "Choose number of wahing machine: ";
                cin >> index;
                index--;
                cin.get();
                machine->showParameters(machine, size, index);
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Choose option again" << endl;
                break;
        }
    }
}
