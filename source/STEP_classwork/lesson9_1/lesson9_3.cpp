#include <iostream>
using namespace std;

class Car
{
    private:
        char* marka;
        char* model;
        double price;
    public:
        Car() : marka(nullptr), model(nullptr), price(0) {}

        Car(const char* marka, const char* model, double price)
        {
            if (this->marka != nullptr)
            {
                this->marka = new char[strlen(marka) + 1];
                strcpy(this->marka, marka);
            }

            if (this->model != nullptr)
            {
                this->model = new char[strlen(model) + 1];
                strcpy(this->model, model);
            }

            if (price >= 0)
            {
                this->price = price;
            }
        }

        Car(const Car& obj)
        {
            if (obj.marka != nullptr && obj.model != nullptr)
            {
                this->marka = new char[strlen(obj.marka) + 1];
                strcpy(this->marka, obj.marka);

                this->model = new char[strlen(obj.model) + 1];
                strcpy(this->model, model);
            }
            else if (obj.model != nullptr && obj.model == nullptr)
            {
                this->marka = new char[strlen(obj.marka) + 1];
                strcpy(this->marka, obj.marka);
            }
            else if (obj.marka == nullptr && obj.model != nullptr)
            {
                this->model = new char[strlen(obj.model) + 1];
                strcpy(this->model, model);
            }
            this->price = obj.price;
        }

        ~Car()
        {
            delete[]marka;
            delete[]model;
        }

        void input()
        {
            char str[100];
            double pr;
            cout << "Enter mark of car: ";
            cin.getline(str, 100);
            if (str == nullptr)
            {
                while (str == nullptr)
                {
                    cin.getline(str, 100);
                }
            }

            if (str != nullptr)
            {
                this->marka = new char[strlen(str) + 1];
                strcpy(this->marka, str);
            }

            cout << "Enter model of car: ";
            cin.getline(str, 100);
            this->model = new char[strlen(str) + 1];
            strcpy(this->model, str);
            if (str == nullptr)
            {
                while (str == nullptr)
                {
                    cin.getline(str, 100);
                }
            }

            if (str != nullptr)
            {
                this->model = new char[strlen(str) + 1];
                strcpy(this->model, str);
            }

            cout << "Enter price: ";
            cin >> this->price;
            if (this->price < 0)
            {
                while (this->price < 0)
                {
                    cout << "Enter price again: ";
                    cin >> this->price;
                }
            }
        }

        void show() const
        {
            cout << "Marka: " << marka << endl;
            cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
        }

        const char* getMarka()
        {
            return marka;
        }
};

void func(Car car)
{
    car.show();
}

int main()
{
    Car car1;
    car1.input();
    car1.show();
    cout << endl;

    Car car2("Nissan", "Maxima", 12000);
    car2.show();
    cout << endl;
    
    func(car2);
    cout << endl;
    car1.show();
    cout << endl;
}