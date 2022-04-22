#include "Car.h"

#include <iostream>
#include <map>

using std::cout;
using std::endl;

Car::Car(std::string name, double x, double y, int numPass, double fuel, double integrity)
{
    this->name = name;
    std::pair<int, int> coords = std::make_pair(x, y);
    this->coords = coords;
    this->numPass = numPass;
    this->fuel = fuel;
    this->integrity = integrity;
}

std::pair<double, double> Car::getCoords()
{
    return coords;
}

double Car::getFuel()
{
    return fuel;
}

int Car::getNumPass()
{
    return numPass;
}

double Car::getIntegrity()
{
    return integrity;
}

void Car::printCarInfo()
{
    cout << "++++++++++++++++++\n      "
         << this->name << "      \n==================\n";
    cout << "Coordinates: " << this->coords.first << "," << this->coords.second << endl;
    cout << "Passengers: " << this->numPass << endl;
    cout << "Fuel: " << this->fuel << endl;
    cout << "Integrity: " << this->integrity;
    if (this->integrity < 50)
    {
        cout << "   ***WARNING: CRITICAL DAMAGE***";
    }
    cout << endl;

    cout << "++++++++++++++++++\n\n";
}