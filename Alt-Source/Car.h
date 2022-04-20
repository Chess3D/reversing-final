#ifndef CAR_H
#define CAR_H

// Required internal import(s)
#include "ElectricalSystem.h"

// Required external import(s)
#include <iostream>

class Alarm : public ElectricalSystem
{
private:
    // Alarm message
    std::string message;

public:
    Alarm(std::string input);
    Alarm(int input);
    void setMessage(std::string input);
    void printMessage();
};

#endif