#include <iostream>
using namespace std;

class Wheel
{
private:
    string model;
    string season;

public:
    Wheel(string model, string season) : model(model), season(season) {}

    void Print() const
    {
        cout << "Wheel: " << model << ", " << season << endl;
    }
};

class Engine
{
private:
    string model;

public:
    Engine(string model) : model(model) {}

    void Print() const
    {
        cout << "Engine: " << model << endl;
    }
};

class Door
{
private:
    string color;

public:
    Door(string color) : color(color) {}

    void Print() const
    {
        cout << "Door color: " << color << endl;
    }
};

class Body
{
private:
    string type;

public:
    Body(string type) : type(type) {}

    void Print() const
    {
        cout << "Body: " << type << endl;
    }
};

class Headlight
{
private:
    string model;

public:
    Headlight(string model) : model(model) {}

    void Print() const
    {
        cout << "Headlight: " << model << endl;
    }
};

class Driver
{
private:
    string fio;
    int age;

public:
    Driver(string fio, int age) : fio(fio), age(age) {}

    void Print() const
    {
        cout << "FIO: " << fio << endl;
        cout << "Age: " << age << endl;
    }
};

class Car
{
private:
    Headlight lights[2];
    Door doors[4];
    Engine engine;
    Wheel wheels[4];
    Body body;
    Driver* driver;

public:
    Car() :
        lights{ Headlight("LED Matrix"), Headlight("Xenon") },
        doors{ Door("Red"), Door("Blue"), Door("Black"), Door("White") },
        engine("V8 Petrol"),
        wheels{
            Wheel("Michelin Pilot Sport", "Summer"),
            Wheel("Bridgestone Blizzak", "Winter"),
            Wheel("Continental PremiumContact", "Summer"),
            Wheel("Goodyear UltraGrip", "Winter")
        },
        body("Sport Coupe"),
        driver(nullptr)
    {
    }

    void Print() const
    {
        cout << "\n========== CAR ==========" << endl;

        cout << "\nEngine:" << endl;
        engine.Print();

        cout << "\nWheels:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << ". ";
            wheels[i].Print();
        }

        cout << "\nDoors:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << ". ";
            doors[i].Print();
        }

        cout << "\nHeadlights:" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << i + 1 << ". ";
            lights[i].Print();
        }

        cout << "\nBody:" << endl;
        body.Print();

        cout << "\nDriver:" << endl;

        if (driver != nullptr)
        {
            driver->Print();
        }
        else
        {
            cout << "No driver" << endl;
        }

        cout << "=========================" << endl;
    }

    void AggregateDriver(Driver* driver)
    {
        this->driver = driver;
    }

    bool RemoveDriver()
    {
        if (driver == nullptr)
        {
            return false;
        }

        driver = nullptr;
        return true;
    }
};

int main()
{
    Driver driver("Ivanov Ivan Ivanovych", 25);

    Car car;

    car.AggregateDriver(&driver);

    car.Print();

    cout << "\nRemoving driver..." << endl;

    if (car.RemoveDriver())
    {
        cout << "Driver successfully removed!" << endl;
    }
    else
    {
        cout << "Driver not found!" << endl;
    }

}
