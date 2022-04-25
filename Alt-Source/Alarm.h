#ifndef ALARM_H
#define ALARM_H

// Required internal import(s)
#include "ElectricalSystem.h"

// Required external import(s)
#include <iostream>

class Alarm : public ElectricalSystem
{
private:
    // Alarm message
    std::string message;

    // Predefined messages
    const std::string messages[5] = {
        "SEVERE WEATHER IMMINENT. EVACUATE IMMEDIATELY",
        "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY",
        "BREACH DETECTED",
        "SYSTEM FAILURE",
        "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL."
    };

public:
    Alarm(std::string input);
    Alarm(int input);
    void setMessage(std::string input);
    void setMessage(int input);
    void printMessage();
};

#endif