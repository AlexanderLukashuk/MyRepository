#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Реализовать классы(Констр Дестр и Вирт метод show)
// Выполнить задание в main()
class Drink
{
protected:
    string name;
    double volume;
    double ccal;
    double price;

public:
    Drink() : volume(), ccal(), price() {}
    Drink(string name, double volume, double ccal, double price)
        : volume(volume), ccal(ccal), price(price)
    {
        if (name.empty() != true)
        {
            if (name.size() < 14)
            {
                this->name = name;
            }
            else
            {
                //this->name = "no name";
                this->name = name;
                this->name.resize(14);
            }
        }
        else
        {
            this->name = "no name";
        }
    }

    virtual void show() const
    {
        //cout << "Name\t\tVolume\t\tCcal\t\tPrice" << endl;
        if (name.size() > 8 && name.size() < 15)
        {
            cout << name << "\t" << volume << "\t\t" << ccal << "\t\t" << price;
        }
        else if (name.size() > 15)
        {
            cout << name << " " << volume << "\t\t" << ccal << "\t\t" << price;
        }
        else
        {
            cout << name << "\t\t" << volume << "\t\t" << ccal << "\t\t" << price;
        }
        cout << endl;
        /*cout << "Name: " << name << endl;
        cout << "Volume: " << volume << endl;
        cout << "Ccal: " << ccal << endl;
        cout << "Price: " << price << endl;*/
    }
};

class EnergyDrink : public Drink
{
protected:
    double caffeine;
    double taurine;

public:
    EnergyDrink() : Drink(), caffeine(), taurine() {}
    EnergyDrink(string name, double volume, double ccal, double price, double caffeine, double taurine)
        : Drink(name, volume, ccal, price), caffeine(caffeine), taurine(taurine) {}
    virtual void show() const override
    {
        Drink::show();
        cout << "Caffeine: " << caffeine << endl;
        cout << "Taurine: " << taurine << endl;
    }
};

class Alcohol : public Drink
{
protected:
    double degree;

public:
    Alcohol() : Drink(), degree() {}
    Alcohol(string name, double volume, double ccal, double price, double degree)
        : Drink(name, volume, ccal, price), degree(degree) {}
    virtual void show() const override
    {
        Drink::show();
        cout << "Degree: " << degree << endl;
    }
};

int menu(const vector<string> menuTitles)
{
    int result = -1;

    //for (auto s = menuTitles.begin(); s != menuTitles.end(); ++i);
    for (auto s : menuTitles)
    {
        cout << s << endl;
    }
    cin >> result;
    cin.get();

    return result;
}

vector<string> initMenu()
{
    vector<string> m;
    m.push_back("1) Add");
    m.push_back("2) Show All drinks");
    m.push_back("3) Exit");

    return m;
}

vector<string> initDrinks()
{
    vector<string> d;
    d.push_back("1) Drink");
    d.push_back("2) Energy Drink");
    d.push_back("3) Alcohol");

    return d;
}

Drink createDrink()
{
    string str;
    double drinkVolume;
    double drinkCcal;
    double drinkPrice;
    cout << "Enter name: ";
    getline(cin, str);
    cout << "Enter volume: ";
    cin >> drinkVolume;
    cout << "Enter ccal: ";
    cin >> drinkCcal;
    cout << "Enter price: ";
    cin >> drinkPrice;
    cin.get();
    Drink drink(str, drinkVolume, drinkCcal, drinkPrice);
    return drink;
}

EnergyDrink createEnergyDrink()
{
    string str;
    double drinkVolume;
    double drinkCcal;
    double drinkPrice;
    double drinkCoffeine;
    double drinkTaurine;
    cout << "Enter name: ";
    getline(cin, str);
    cout << "Enter volume: ";
    cin >> drinkVolume;
    cout << "Enter ccal: ";
    cin >> drinkCcal;
    cout << "Enter price: ";
    cin >> drinkPrice;
    cout << "Enter coffeine: ";
    cin >> drinkCoffeine;
    cout << "Enter Taurine: ";
    cin >> drinkTaurine;
    cin.get();
    EnergyDrink drink(str, drinkVolume, drinkCcal, drinkPrice, drinkCoffeine, drinkTaurine);
    return drink;
}

Alcohol createAlcohol()
{
    string str;
    double drinkVolume;
    double drinkCcal;
    double drinkPrice;
    double drinkDegree;
    cout << "Enter name: ";
    getline(cin, str);
    cout << "Enter volume: ";
    cin >> drinkVolume;
    cout << "Enter ccal: ";
    cin >> drinkCcal;
    cout << "Enter price: ";
    cin >> drinkPrice;
    cout << "Enter degree of alcohol: ";
    cin >> drinkDegree;
    cin.get();
    Alcohol drink(str, drinkVolume, drinkCcal, drinkPrice, drinkDegree);
    return drink;
}

void createDrinks(vector<unique_ptr<Drink>> &ptr)
{
    vector<string> d = initDrinks();

    switch (menu(d))
    {
    case 1:
    {
        ptr.push_back(make_unique<Drink>(createDrink()));
        break;
    }
    case 2:
    {
        ptr.push_back(make_unique<EnergyDrink>(createEnergyDrink()));
        break;
    }
    case 3:
    {
        ptr.push_back(make_unique<Alcohol>(createAlcohol()));
        break;
    }
    }
}

/*vector<unique_ptr<Drink>> ptr createDrink()
{
    vector<string> d = initDrinks();

    switch(menu(d))
    {
        case 1:
        {
            string str;
            double drinkVolume;
            double drinkCcal;
            double drinkPrice;
            cout << "Enter name: ";
            getline(cin, str);
            cin.get();
            cout << "Enter volume: ";
            cin >> drinkVolume;
            cout << "Enter ccal: ";
            cin >> drinkCcal;
            cout << "Enter price: ";
            cin >> drinkPrice;
            ptr.push_back(make_unique<Drink>(str, drinkVolume, drinkCcal, drinkPrice));
            //Drink drink(str, drinkVolume, drinkCcal, drinkPrice);
            //return drink;
            return ptr;
            //break;
        }
        case 2:
        {
            string str;
            double drinkVolume;
            double drinkCcal;
            double drinkPrice;
            double drinkCoffeine;
            double drinkTaurine;
            cout << "Enter name: ";
            getline(cin, str);
            cin.get();
            cout << "Enter volume: ";
            cin >> drinkVolume;
            cout << "Enter ccal: ";
            cin >> drinkCcal;
            cout << "Enter price: ";
            cin >> drinkPrice;
            cout << "Enter coffeine: ";
            cin >> drinkCoffeine;
            cout << "Enter Taurine: ";
            cin >> drinkTaurine;
            //EnergyDrink drink(str, drinkVolume, drinkCcal, drinkPrice, drinkCoffeine, drinkTaurine);
            ptr.push_back(make_unique<Drink>(str, drinkVolume, drinkCcal, drinkPrice, drinkCoffeine, drinkTaurine));
            //return drink;
            break;
        }
        case 3:
        {
            string str;
            double drinkVolume;
            double drinkCcal;
            double drinkPrice;
            double drinkDegree;
            cout << "Enter name: ";
            getline(cin, str);
            cin.get();
            cout << "Enter volume: ";
            cin >> drinkVolume;
            cout << "Enter ccal: ";
            cin >> drinkCcal;
            cout << "Enter price: ";
            cin >> drinkPrice;
            cout << "Enter degree of alcohol: ";
            cin >> drinkDegree;
            ptr.push_back(make_unique<Drink>(str, drinkVolume, drinkCcal, drinkPrice, drinkDegree));
            //return drink;
            break;
        }
    }
}*/

//void app(vector<unique_ptr<Drink>> &drinks)
void app()
{
    vector<unique_ptr<Drink>> drinks;
    vector<string> m = initMenu();

    while (true)
    {
        switch (menu(m))
        {
        case 1:
        {
            createDrinks(drinks);
            break;
        }
        case 2:
        {
            cout << "Name\t\tVolume\t\tCcal\t\tPrice" << endl;
            for (auto &el : drinks)
            {
                el->show();
            }
            break;
        }
        case 3:
        {
            cout << "Bye\n";
            return;
            break;
        }
        }
    }
}

int main()
{
    // вектор уникальных указателей типа родителя Drink
    // заполнить вектор напитками(разними и обычными и энергетиками и алкоголем)
    // вывести на экран вектор в цикле

    /*vector<unique_ptr<Drink>> drinks;

    drinks.push_back(make_unique<Drink>("Tea", 0.33, 320, 210));
    drinks.push_back(make_unique<Alcohol>("Old Forester", 0.75, 1440, 10920, 50));
    drinks.push_back(make_unique<Alcohol>("Vine", 0.75, 880, 4800, 12));
    drinks.push_back(make_unique<EnergyDrink>("Flash", 0.5, 560, 480, 40, 30));
    drinks.push_back(make_unique<Drink>("Water", 1.5, 0, 180));
    drinks.push_back(make_unique<EnergyDrink>("Monster", 0.5, 660, 630, 58.7, 43.17));
    drinks.push_back(make_unique<Alcohol>("Gin Tonic", 0.7, 540, 720, 8.7));
    drinks.push_back(make_unique<EnergyDrink>("Coffee", 0.45, 243, 250, 11.5, 4.9));
    drinks.push_back(make_unique<Drink>("Orange juce", 2.5, 529, 680));
    drinks.push_back(make_unique<Drink>("Sprite", 2.25, 280, 450));
    drinks.push_back(make_unique<Alcohol>("Baltika 9", 1.0, 230, 420, 9));

    app(drinks);*/

    app();

    /*for (auto &el : drinks)
    {
        el->show();
        cin.get();
    }*/
}