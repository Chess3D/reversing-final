#ifndef CAR_H
#define CAR_H

// Required external import(s)
#include <iostream>
#include <map>
class Car
{
private:
    // car info
    std::string name;
    std::pair<double, double> coords;
    int numPass;
    int fuel;
    int integrity;

public:
    Car(std::string name, double x, double y, int numPass, double fuel, double integrity);
    std::pair<double, double> getCoords();
    int getNumPass();
    double getFuel();
    double getIntegrity();
    void printCarInfo();
};

#endif