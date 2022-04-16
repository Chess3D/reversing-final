#ifndef ALARM_H
#define ALARM_H

// Required internal imports
#include <ElectricalSystem.h>

class Alarm: public ElectricalSystem {
private:
    // Types of alarms
    string custom;
    
    // Deviates from source code but should be functionally equivalent
    // Originally these were assigned and left unchanged in the constructor
    const string messages[5] = {
        "SEVERE WEATHER IMMINDENT. EVACUATE IMMEDIATELY",
        "THE FIRE ALARM HAS BEEN ACTIVATED. EVACUATE IMMEDIATELY",
        "BREACH DETECTED",
        "SYSTEM FAILURE",
        "ASSETS OUT OF CONTAINTMENT. THIS IS NOT A DRILL."
    };

public:
    Alarm(string input);
    Alarm(int input);
    void setMessage(string input);
    void printMessage();
};

#endif