#include <iostream>
using namespace std;

class Film
{
    private:
        char* name;
        char* producer;
        int ticket_price;
    public:
        Film() : name(nullptr), producer(nullptr), ticket_price(0) {}
        Film(const char* name, const char* producer, int ticket_price)
        {
            if (name != nullptr)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            }

            if (producer != nullptr)
            {
                this->producer = new char[strlen(producer) + 1];
                strcpy(this->producer, producer);
            }

            if (ticket_price >= 0)
            {
                this->ticket_price = ticket_price;
            }
        }

        Film(const Film& obj) : name(nullptr), producer(nullptr), ticket_price(obj.ticket_price)
        {
            if (obj.name != nullptr)
            {
                this->name = new char[strlen(obj.name) + 1];
                strcpy(this->name, obj.name);
            }

            if (obj.producer != nullptr)
            {
                this->producer = new char[strlen(obj.producer) + 1];
                strcpy(this->producer, obj.producer);
            }
        }

        /*Film(Film&& obj)
        {
            name = obj.name;
            obj.name = nullptr;
            producer = obj.producer;
            obj.producer = nullptr;
            ticket_price = obj.ticket_price;
        }

        ~Film()
        {
            delete[]name;
            delete[]producer;
        }*/

        void operator=(const Film& obj)
        {
            if (this->name != nullptr)
            {
                delete[]this->name;
                this->name = nullptr;
            }

            if (this->producer != nullptr)
            {
                delete[]this->producer;
                this->producer = nullptr;
            }

            if (obj.name != nullptr)
            {
                this->name = new char[strlen(obj.name) + 1];
                strcpy(this->name, obj.name);
            }

            if (obj.producer != nullptr)
            {
                this->producer = new char[strlen(obj.producer) + 1];
                strcpy(this->producer, obj.producer);
            }

            ticket_price = obj.ticket_price;
        }

        /*void operator=(Film&& obj)
        {
            if (name != nullptr)
            {
                delete[]name;
                name = nullptr;
            }

            if (producer != nullptr)
            {
                delete[]producer;
                producer = nullptr;
            }

            name = obj.name;
            obj.name = nullptr;
            producer = obj.producer;
            obj.producer = nullptr;
            ticket_price = obj.ticket_price;
        }*/

        void show() const
        {
            cout << "Name of film: " << name << endl;
            cout << "Producer: " << producer << endl;
            cout << "Ticket price: " << ticket_price << endl;
        }

        void setName(const char* name)
        {
            if (this->name != nullptr)
            {
                delete[]name;
                name = nullptr;
            }

            if (name != nullptr)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            }
        }

        void setProducer(const char* producer)
        {
            if (this->producer != nullptr)
            {
                delete[]producer;
                producer = nullptr;
            }

            if (producer != nullptr)
            {
                this->producer = new char[strlen(producer) + 1];
                strcpy(this->producer, producer);
            }
        }

        void setTicketPrice(int ticket_price)
        {
            if (ticket_price >= 0)
            {
                this->ticket_price = ticket_price;
            }
        }

        char* getName()
        {
            return name;
        }

        char* getProducer()
        {
            return producer;
        }

        int getTicketPrice()
        {
            return ticket_price;
        }
};

int main()
{
    Film film1;
    Film film2("Joker", "Todd Phillips", 1800);
    Film film3;

    film1.setName("Godfather");
    film1.setProducer("Albert Ruddy");
    film1.setTicketPrice(2500);

    film1.show();
    film2.show();

    cout << "Pause" << endl;

    film3 = film2;
    cout << "Film3: " << endl;
    film3.show();
}