#ifndef ELECTRICAL_SYSTEM_H
#define ELECTRICAL_SYSTEM_H

#include <string>

class ElectricalSystem {
private:
    bool systemOn;
    std::string password;

public:
    ElectricalSystem();
    bool passwordCorrect(std::string input);
    void turnOff(std::string password);
    bool isOn();
};

#endif