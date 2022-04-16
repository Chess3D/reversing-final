#ifndef ELECTRICAL_SYSTEM_H
#define ELECTRICAL_SYSTEM_H

#include <string>
using std::string

class ElectricalSystem {
private:
    bool systemOn;
    string password;

    bool passwordCorrect(string input);
    
public:
    ElectricalSystem();
    void turnOff(string password);
    bool isOn();
};

#endif