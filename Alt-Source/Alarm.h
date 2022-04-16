#ifndef ALARM_H
#define ALARM_H

// Required internal import(s)
#include <ElectricalSystem.h>

// Required external import(s)
#include <iostream>

class Alarm: public ElectricalSystem {
private:
    // Types of alarms
    std::string custom;
    
    // Deviates from source code but should be functionally equivalent
    // Originally these were assigned and left unchanged in the constructor
    const std::string messages[5] = {
        "SEVERE WEATHER IMMINDENT. EVACUATE IMMEDIATELY",
        "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY",
        "BREACH DETECTED",
        "SYSTEM FAILURE",
        "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL."
    };

public:
    Alarm(std::string input);
    Alarm(int input);
    void setMessage(std::string input);
    void printMessage();
};

#endif