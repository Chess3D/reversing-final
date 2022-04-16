#ifndef ELECTRICAL_SYSTEM_H
#define ELECTRICAL_SYSTEM_H

#include <string>

class ElectricalSystem {
private:
    bool systemOn;
    std::string password;

    bool passwordCorrect(std::string input);
    
public:
    ElectricalSystem();
    void turnOff(std::string password);
    bool isOn();
};

#endif